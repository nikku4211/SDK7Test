
@{{BLOCK(ballgers)

@=======================================================================
@
@	ballgers, 32x32@4, 
@	+ palette 16 entries, not compressed
@	+ 16 tiles Metatiled by 4x4 not compressed
@	Total size: 32 + 512 = 544
@
@	Time-stamp: 2023-02-04, 11:17:56
@	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
@	( http://www.coranac.com/projects/#grit )
@
@=======================================================================

	.section .rodata
	.align	2
	.global ballgersTiles		@ 512 bytes
ballgersTiles:
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x2200,0x0000,0x2222,0x2000,0x2222,0x2200,0x2222
	.hword 0x2220,0x2222,0x2220,0x2222,0x2222,0x2222,0x2222,0x2222
	.hword 0x0022,0x0000,0x2222,0x0000,0x2222,0x0002,0x2222,0x0022
	.hword 0x2222,0x0222,0x2222,0x0222,0x2222,0x2222,0x2222,0x2222
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x2222,0x2222,0x2222,0x2222,0x2220,0x2222,0x2220,0x2222
	.hword 0x2200,0x2222,0x2000,0x2222,0x0000,0x2222,0x0000,0x2200
	.hword 0x2222,0x2222,0x2222,0x1112,0x2222,0x0111,0x2222,0x2112
	.hword 0x2222,0x2122,0x2222,0x0222,0x2222,0x0022,0x2222,0x0002
	.hword 0x0000,0x0000,0x0002,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000

	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.size	ballgersTiles, .-ballgersTiles

	.section .rodata
	.align	2
	.global ballgersPal		@ 32 bytes
ballgersPal:
	.hword 0x0000,0x7773,0x7FFF,0x0000,0x0000,0x0000,0x0000,0x0000
	.hword 0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000
	.size	ballgersPal, .-ballgersPal

@}}BLOCK(ballgers)