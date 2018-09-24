	.include "MPlayDef.s"

	.equ	se_w104_grp, voicegroup128
	.equ	se_w104_pri, 4
	.equ	se_w104_rev, reverb_set+50
	.equ	se_w104_mvl, 127
	.equ	se_w104_key, 0
	.equ	se_w104_tbs, 1
	.equ	se_w104_exg, 0
	.equ	se_w104_cmp, 1

	.section .rodata
	.global	se_w104
	.align	2

@********************** Track  1 **********************@

se_w104_1:
	.byte	KEYSH , se_w104_key+0
	.byte	TEMPO , 150*se_w104_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w104_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N19   , Dn3 , v108
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		VOL   , 101*se_w104_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v+8
	.byte	W02
	.byte		VOL   , 84*se_w104_mvl/mxv
	.byte		BEND  , c_v+4
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 64*se_w104_mvl/mxv
	.byte		BEND  , c_v-13
	.byte	W01
	.byte		PAN   , c_v+8
	.byte	W02
	.byte		VOL   , 45*se_w104_mvl/mxv
	.byte		BEND  , c_v-31
	.byte	W02
	.byte		VOL   , 32*se_w104_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOICE , 2
	.byte	W01
	.byte		VOL   , 13*se_w104_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W08
	.byte	FINE

@******************************************************@
	.align	2

se_w104:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w104_pri	@ Priority
	.byte	se_w104_rev	@ Reverb.

	.word	se_w104_grp

	.word	se_w104_1

	.end
