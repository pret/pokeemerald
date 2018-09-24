	.include "MPlayDef.s"

	.equ	se_doku_grp, voicegroup127
	.equ	se_doku_pri, 5
	.equ	se_doku_rev, reverb_set+50
	.equ	se_doku_mvl, 127
	.equ	se_doku_key, 0
	.equ	se_doku_tbs, 1
	.equ	se_doku_exg, 0
	.equ	se_doku_cmp, 1

	.section .rodata
	.global	se_doku
	.align	2

@********************** Track  1 **********************@

se_doku_1:
	.byte	KEYSH , se_doku_key+0
	.byte	TEMPO , 150*se_doku_tbs/2
	.byte		VOICE , 16
	.byte		BENDR , 12
	.byte		VOL   , 110*se_doku_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Ds3 , v100
	.byte	W04
	.byte		N02   
	.byte	W05
	.byte		N02   
	.byte	W05
	.byte		N02   
	.byte	W05
	.byte		N02   
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_doku:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_doku_pri	@ Priority
	.byte	se_doku_rev	@ Reverb.

	.word	se_doku_grp

	.word	se_doku_1

	.end
