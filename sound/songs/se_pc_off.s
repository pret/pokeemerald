	.include "MPlayDef.s"

	.equ	se_pc_off_grp, voicegroup_869D0F4
	.equ	se_pc_off_pri, 5
	.equ	se_pc_off_rev, reverb_set+50
	.equ	se_pc_off_mvl, 127
	.equ	se_pc_off_key, 0
	.equ	se_pc_off_tbs, 1
	.equ	se_pc_off_exg, 0
	.equ	se_pc_off_cmp, 1

	.section .rodata
	.global	se_pc_off
	.align	2

@********************** Track  1 **********************@

se_pc_off_1:
	.byte	KEYSH , se_pc_off_key+0
	.byte	TEMPO , 120*se_pc_off_tbs/2
	.byte		VOICE , 6
	.byte		VOL   , 100*se_pc_off_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N04   , Cn3 , v112
	.byte	W04
	.byte		        Cn2 
	.byte	W02
	.byte	W02
	.byte		        Cn1 
	.byte	W04
	.byte		        Cn1 , v024
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_pc_off:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pc_off_pri	@ Priority
	.byte	se_pc_off_rev	@ Reverb.

	.word	se_pc_off_grp

	.word	se_pc_off_1

	.end
