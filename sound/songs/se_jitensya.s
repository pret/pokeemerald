	.include "MPlayDef.s"

	.equ	se_jitensya_grp, voicegroup_869D6F4
	.equ	se_jitensya_pri, 4
	.equ	se_jitensya_rev, reverb_set+50
	.equ	se_jitensya_mvl, 127
	.equ	se_jitensya_key, 0
	.equ	se_jitensya_tbs, 1
	.equ	se_jitensya_exg, 0
	.equ	se_jitensya_cmp, 1

	.section .rodata
	.global	se_jitensya
	.align	2

@********************** Track  1 **********************@

se_jitensya_1:
	.byte	KEYSH , se_jitensya_key+0
	.byte	TEMPO , 120*se_jitensya_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 90*se_jitensya_mvl/mxv
	.byte		N96   , Cn3 , v127
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

se_jitensya:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_jitensya_pri	@ Priority
	.byte	se_jitensya_rev	@ Reverb.

	.word	se_jitensya_grp

	.word	se_jitensya_1

	.end
