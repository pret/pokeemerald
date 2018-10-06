	.include "MPlayDef.s"

	.equ	se_bowa_grp, voicegroup127
	.equ	se_bowa_pri, 4
	.equ	se_bowa_rev, reverb_set+50
	.equ	se_bowa_mvl, 127
	.equ	se_bowa_key, 0
	.equ	se_bowa_tbs, 1
	.equ	se_bowa_exg, 0
	.equ	se_bowa_cmp, 1

	.section .rodata
	.global	se_bowa
	.align	2

@********************** Track  1 **********************@

se_bowa_1:
	.byte	KEYSH , se_bowa_key+0
	.byte	TEMPO , 128*se_bowa_tbs/2
	.byte		VOICE , 7
	.byte		BENDR , 12
	.byte		VOL   , 70*se_bowa_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N04   , Fn2 , v127
	.byte	W04
	.byte		N01   , Dn3 
	.byte	W02
	.byte		VOICE , 8
	.byte	FINE

@******************************************************@
	.align	2

se_bowa:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_bowa_pri	@ Priority
	.byte	se_bowa_rev	@ Reverb.

	.word	se_bowa_grp

	.word	se_bowa_1

	.end
