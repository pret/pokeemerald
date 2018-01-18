	.include "MPlayDef.s"

	.equ	ph_foot_solo_grp, voicegroup_86A0754
	.equ	ph_foot_solo_pri, 4
	.equ	ph_foot_solo_rev, 0
	.equ	ph_foot_solo_mvl, 127
	.equ	ph_foot_solo_key, 0
	.equ	ph_foot_solo_tbs, 1
	.equ	ph_foot_solo_exg, 0
	.equ	ph_foot_solo_cmp, 1

	.section .rodata
	.global	ph_foot_solo
	.align	2

@********************** Track  1 **********************@

ph_foot_solo_1:
	.byte	KEYSH , ph_foot_solo_key+0
	.byte	TEMPO , 120*ph_foot_solo_tbs/2
	.byte		VOICE , 38
	.byte		VOL   , 127*ph_foot_solo_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

ph_foot_solo:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ph_foot_solo_pri	@ Priority
	.byte	ph_foot_solo_rev	@ Reverb.

	.word	ph_foot_solo_grp

	.word	ph_foot_solo_1

	.end
