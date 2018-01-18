	.include "MPlayDef.s"

	.equ	se_mizu_grp, voicegroup_869D6F4
	.equ	se_mizu_pri, 4
	.equ	se_mizu_rev, reverb_set+50
	.equ	se_mizu_mvl, 127
	.equ	se_mizu_key, 0
	.equ	se_mizu_tbs, 1
	.equ	se_mizu_exg, 0
	.equ	se_mizu_cmp, 1

	.section .rodata
	.global	se_mizu
	.align	2

@********************** Track  1 **********************@

se_mizu_1:
	.byte	KEYSH , se_mizu_key+0
	.byte	TEMPO , 150*se_mizu_tbs/2
	.byte		VOICE , 23
	.byte		VOL   , 20*se_mizu_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-25
	.byte		N03   , Gs4 , v112
	.byte	W01
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		        c_v+9
	.byte	W04
	.byte	W02
	.byte		VOL   , 17*se_mizu_mvl/mxv
	.byte		BEND  , c_v+18
	.byte		N02   , Gs4 , v127
	.byte	W01
	.byte		BEND  , c_v+34
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_mizu:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_mizu_pri	@ Priority
	.byte	se_mizu_rev	@ Reverb.

	.word	se_mizu_grp

	.word	se_mizu_1

	.end
