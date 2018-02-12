	.include "MPlayDef.s"

	.equ	se_pinpon_grp, voicegroup_869D0F4
	.equ	se_pinpon_pri, 5
	.equ	se_pinpon_rev, reverb_set+50
	.equ	se_pinpon_mvl, 127
	.equ	se_pinpon_key, 0
	.equ	se_pinpon_tbs, 1
	.equ	se_pinpon_exg, 0
	.equ	se_pinpon_cmp, 1

	.section .rodata
	.global	se_pinpon
	.align	2

@********************** Track  1 **********************@

se_pinpon_1:
	.byte	KEYSH , se_pinpon_key+0
	.byte	TEMPO , 150*se_pinpon_tbs/2
	.byte		VOICE , 15
	.byte		BENDR , 2
	.byte		VOL   , 90*se_pinpon_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N24   , Ds4 , v092
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		BEND  , c_v+15
	.byte		N36   , Bn3 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_pinpon_2:
	.byte	KEYSH , se_pinpon_key+0
	.byte		VOICE , 14
	.byte		VOL   , 90*se_pinpon_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N24   , Ds4 , v072
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		BEND  , c_v+15
	.byte		N36   , Bn3 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_pinpon:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pinpon_pri	@ Priority
	.byte	se_pinpon_rev	@ Reverb.

	.word	se_pinpon_grp

	.word	se_pinpon_1
	.word	se_pinpon_2

	.end
