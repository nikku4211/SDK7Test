#include <seven/prelude.h>
#include <seven/hw/video/prelude.h>
#include <seven/hw/video/bg_bitmap.h>
#include <seven/hw/video/object.h>
#include <seven/hw/video/oam.h>
#include <seven/util/random.h>

#include <stdlib.h>

#include <string.h>

#include "circle.h"
#include "ponggers.h"
#include "ballgers.h"
#include "spritefont.h"

void vblank_callback(u16 irqs){
  (void)irqs;
}

int main(void)
{
    
    int pong1y = 48;
    int pong1speed = 2; //your speed
    int pong1score = 0; //your score
    
    int pong2y = 48;
    bool enemy_rising = false; //is enemy going up?
    int pong2score = 0; //enemy score
    
    int ballx = 104;
    int bally = 64;
    bool ballfaceleft = false;
    s16 deltx = 0; //delta x and y
    s16 delty = 0;
    
    //LOL SO RANDOM
    randSetSeed(0x54671243);
    u32 pongRand = randNext();
  
    // Set up the necessary interrupt handling
    irqInitDefault();
    irqEnableFull(IRQ_VBLANK);
    irqHandlerSet(IRQ_VBLANK, vblank_callback);

    // Clear the force-blank bit
    REG_DISPCNT = 0;
    
    REG_DISPCNT = VIDEO_MODE(3) | VIDEO_BG2_ENABLE | VIDEO_OBJ_ENABLE | VIDEO_OBJ_LAYOUT_1D;
    
    //fill the bitmap layer
    memcpy(MODE3_FRAME, circleBitmap, 76800);
    
    //construct sprite structs
    struct Object Pongger1;
    
    Pongger1.attr0 = OBJ_Y_POS(48) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_TALL;
    Pongger1.attr1 = OBJ_X_POS(24) | OBJ_SIZE_32X64;
    Pongger1.attr2 = OBJ_TILE_NUMBER(512) | OBJ_PROIRITY_MAX;
    
    struct Object Pongger2;
    
    Pongger2.attr0 = OBJ_Y_POS(48) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_TALL;
    Pongger2.attr1 = OBJ_X_POS(184) | OBJ_SIZE_32X64 | OBJ_FLIP_H;
    Pongger2.attr2 = OBJ_TILE_NUMBER(512) | OBJ_PROIRITY_MAX;
    
    struct Object Ballger;
    
    Ballger.attr0 = OBJ_Y_POS(64) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_SQUARE;
    Ballger.attr1 = OBJ_X_POS(104) | OBJ_SIZE_32X32;
    Ballger.attr2 = OBJ_TILE_NUMBER(544) | OBJ_PROIRITY_MAX;
    
    struct Object ScoreSpr1;
    
    ScoreSpr1.attr0 = OBJ_Y_POS(16) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_SQUARE;
    ScoreSpr1.attr1 = OBJ_X_POS(16) | OBJ_SIZE_8X8;
    ScoreSpr1.attr2 = OBJ_TILE_NUMBER(560) | OBJ_PROIRITY_MAX | OBJ_PALETTE_NUMBER(1);
    
    struct Object ScoreSpr2;
    
    ScoreSpr2.attr0 = OBJ_Y_POS(16) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_SQUARE;
    ScoreSpr2.attr1 = OBJ_X_POS(216) | OBJ_SIZE_8X8;
    ScoreSpr2.attr2 = OBJ_TILE_NUMBER(560) | OBJ_PROIRITY_MAX | OBJ_PALETTE_NUMBER(1);
    
    //upload sprite graphics to VRAM
    memcpy(MEM_VRAM + 0x14000, ponggersTiles, 1024);
    memcpy(OBJ_PALETTE, ponggersPal, 16);
    
    memcpy(MEM_VRAM + 0x14400, ballgersTiles, 512);
    
    memcpy(MEM_VRAM + 0x14600, spritefontTiles, 352);
    memcpy(OBJ_PALETTE+16, spritefontPal, 16);
    
    //setup input
    struct InputState pongInp;
    pongInp = inputNew();
    
    while (true) {
      //poll input
      pongInp = inputPoll(pongInp);

      if (inputKeysDown(KEY_UP, pongInp) && pong1y > 0){
        pong1y -= pong1speed;
      } else if (inputKeysDown(KEY_DOWN, pongInp) && pong1y < 96){
        pong1y += pong1speed;
      }
      
      if(inputKeysDown(KEY_B, pongInp)){
        pong1speed = 1;  //allow player to change speed
      }else if(inputKeysDown(KEY_A, pongInp)){
        pong1speed = 4;
      }else{
        pong1speed = 2;
      }
      
      if(enemy_rising){
          
        if(pong2y > 0 && bally < (pong2y+16)){
          pong2y -= 1;  //move enemy paddle according to ball
        }else{
          enemy_rising = false;
        }
        
      }else{
        if(pong2y < 96 && bally > (pong2y+16)){
          pong2y += 1;  //move enemy paddle accoding to ball
        }else{
          enemy_rising = true;
        }
      }
      
      if(inputKeysPressed(KEY_START, pongInp) && deltx == 0 && delty == 0){
        
        while(deltx == 0 || delty == 0){
          //randomise deltas
          pongRand = randNext();
          deltx = pongRand>>30;
          pongRand = randNext();
          delty = pongRand>>30;
        }
        
        if(pong1score % 10 == 0){
              pong1score = 0;
              pong2score = 0;
            }
      }
      
      ballx += deltx;
      bally += delty;
      
      if(ballx < 20){
          
          if(abs((bally+16) - (pong1y+32)) < 32){
            deltx *= -1;
            delty = (bally - (pong1y))>>3;
            ballfaceleft = false;
            
          }else{
            pong2score++;
            ballx = 104;
            bally = 64;
            pongRand = randNext();
            deltx = (s16)(pongRand)>>25;
            pongRand = randNext();
            delty = (s16)(pongRand)>>25;
            if(deltx == 0){
              deltx = 1;  //zero x speed check
            }
            if(pong2score % 10 == 0){
              deltx = 0;
              delty = 0;
            }
          }
          
      }else if(ballx > 184){
          if(abs((bally+16) - (pong2y+32)) < 32){
            deltx *= -1;
            delty = (bally - pong2y)>>3;
            ballfaceleft = true;
            
          }else{
            pong1score++;
            ballx = 104;
            bally = 64;
            pongRand = randNext();
            deltx = (s16)(pongRand)>>25;
            pongRand = randNext();
            delty = (s16)(pongRand)>>25;
            if(deltx == 0){
              deltx = -1;  //zero x speed check
            }
            if(pong1score % 10 == 0){
              deltx = 0;
              delty = 0;
            }
          }
      }
      
      if(bally < 0){
          delty *= -1;  //ball bounces off of ceiling
        }else if(bally > 128){
          delty *= -1;  //ball bounces off of floor
      }
      
      //change sprite position based on variable
      
      Pongger1.attr0 = OBJ_Y_POS(pong1y) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_TALL;
      Pongger2.attr0 = OBJ_Y_POS(pong2y) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_TALL;
      
      Ballger.attr0 = OBJ_Y_POS(bally) | OBJ_MODE_REGULAR | OBJ_TYPE_REGULAR | OBJ_TILE_4BPP | OBJ_SHAPE_SQUARE;
      
      if(ballfaceleft){
      Ballger.attr1 = OBJ_X_POS(ballx) | OBJ_SIZE_32X32 | OBJ_FLIP_H;
      } else {
      Ballger.attr1 = OBJ_X_POS(ballx) | OBJ_SIZE_32X32;  
      }
      
      ScoreSpr1.attr2 = OBJ_TILE_NUMBER(560+pong1score) | OBJ_PROIRITY_MAX | OBJ_PALETTE_NUMBER(1);
      ScoreSpr2.attr2 = OBJ_TILE_NUMBER(560+pong2score) | OBJ_PROIRITY_MAX | OBJ_PALETTE_NUMBER(1);
      
      //write the sprite structs to OAM
      oamWriteObjects(0, &Pongger1, 1);
      oamWriteObjects(1, &Pongger2, 1);
      oamWriteObjects(2, &Ballger, 1);
      oamWriteObjects(3, &ScoreSpr1, 1);
      oamWriteObjects(4, &ScoreSpr2, 1);
      
      // Wait for V-sync
      biosVBlankIntrWait();
    }
}
