	.include "MPlayDef.s"

	.equ	se_w030_grp, voicegroup_869D6F4
	.equ	se_w030_pri, 4
	.equ	se_w030_rev, reverb_set+50
	.equ	se_w030_mvl, 127
	.equ	se_w030_key, 0
	.equ	se_w030_tbs, 1
	.equ	se_w030_exg, 0
	.equ	se_w030_cmp, 1

	.section .rodata
	.global	se_w030
	.align	2

@********************** Track  1 **********************@

se_w030_1:
	.byte	KEYSH , se_w030_key+0
	.byte	TEMPO , 150*se_w030_tbs/2
	.byte		VOICE , 21
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w030_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N01   , Bn5 , v127
	.byte	W02
	.byte		VOICE , 18
	.byte		N01   , Cn4 
	.byte	W02
	.byte		VOICE , 36
	.byte		N06   , Gn5 , v040
	.byte	W02
	.byte		VOL   , 58*se_w030_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		VOL   , 71*se_w030_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 84*se_w030_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+21
	.byte	W01
	.byte		VOL   , 97*se_w030_mvl/mxv
	.byte		PAN   , c_v-14
	.byte		BEND  , c_v+33
	.byte	W01
	.byte		VOL   , 110*se_w030_mvl/mxv
	.byte	W14
	.byte	FINE

@******************************************************@
	.align	2

se_w030:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w030_pri	@ Priority
	.byte	se_w030_rev	@ Reverb.

	.word	se_w030_grp

	.word	se_w030_1

	.end
