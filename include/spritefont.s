
@{{BLOCK(spritefont)

@=======================================================================
@
@	spritefont, 88x8@4, 
@	Transparent color : FF,00,DF
@	+ palette 16 entries, not compressed
@	+ 11 tiles not compressed
@	Total size: 32 + 352 = 384
@
@	Time-stamp: 2023-02-05, 16:36:58
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global spritefontTiles		@ 352 bytes
spritefontTiles:
	.hword 0x2220,0x0022,0x1122,0x0221,0x0122,0x1222,0x2122,0x1220
	.hword 0x0222,0x1221,0x1122,0x1220,0x2220,0x1122,0x1100,0x0111
	.hword 0x2000,0x0002,0x2200,0x0012,0x2000,0x0012,0x2000,0x0012
	.hword 0x2000,0x0012,0x2000,0x0012,0x2200,0x0022,0x1000,0x0111
	.hword 0x2200,0x0002,0x1020,0x0022,0x0100,0x0122,0x2000,0x0112
	.hword 0x2200,0x0011,0x1220,0x0001,0x2220,0x0022,0x1100,0x0111
	.hword 0x2200,0x0002,0x1020,0x0022,0x0100,0x0122,0x2000,0x0112
	.hword 0x0000,0x0022,0x0020,0x0122,0x2200,0x0112,0x1000,0x0011

	.hword 0x0000,0x0022,0x2000,0x0122,0x0200,0x0122,0x1020,0x0122
	.hword 0x2220,0x0222,0x1100,0x1122,0x0000,0x0122,0x0000,0x0110
	.hword 0x2220,0x0022,0x1220,0x0111,0x1220,0x0000,0x2220,0x0022
	.hword 0x1100,0x0122,0x0020,0x0122,0x2200,0x0112,0x1000,0x0011
	.hword 0x2200,0x0002,0x1220,0x0021,0x1220,0x0100,0x2220,0x0002
	.hword 0x1220,0x0021,0x1220,0x0120,0x2200,0x0102,0x1000,0x0011
	.hword 0x2220,0x0022,0x1100,0x0122,0x2000,0x0112,0x2200,0x0011
	.hword 0x1220,0x0001,0x1220,0x0000,0x1220,0x0000,0x1100,0x0000

	.hword 0x2220,0x0002,0x1122,0x0021,0x0222,0x0120,0x2220,0x0122
	.hword 0x1102,0x0222,0x0012,0x1220,0x2220,0x1122,0x1100,0x0111
	.hword 0x2200,0x0002,0x1020,0x0022,0x0120,0x0122,0x2200,0x0122
	.hword 0x1000,0x0122,0x0020,0x0122,0x2200,0x0112,0x1000,0x0011
	.hword 0x0020,0x0020,0x0122,0x0202,0x0120,0x1212,0x0120,0x1212
	.hword 0x0120,0x1212,0x0120,0x1212,0x0222,0x1020,0x1110,0x0100
	.size	spritefontTiles, .-spritefontTiles

	.section .rodata
	.align	2
	.global spritefontPal		@ 32 bytes
spritefontPal:
	.hword 0x6C1F,0x0000,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.size	spritefontPal, .-spritefontPal

@}}BLOCK(spritefont)
