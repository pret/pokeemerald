	.include "MPlayDef.s"

	.equ	se_seikai_grp, voicegroup_869D0F4
	.equ	se_seikai_pri, 4
	.equ	se_seikai_rev, reverb_set+50
	.equ	se_seikai_mvl, 127
	.equ	se_seikai_key, 0
	.equ	se_seikai_tbs, 1
	.equ	se_seikai_exg, 0
	.equ	se_seikai_cmp, 1

	.section .rodata
	.global	se_seikai
	.align	2

@********************** Track  1 **********************@

se_seikai_1:
	.byte	KEYSH , se_seikai_key+0
	.byte	TEMPO , 240*se_seikai_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 80*se_seikai_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Gn5 , v127
	.byte	W06
	.byte		N18   , Ds5 
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_seikai:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_seikai_pri	@ Priority
	.byte	se_seikai_rev	@ Reverb.

	.word	se_seikai_grp

	.word	se_seikai_1

	.end
