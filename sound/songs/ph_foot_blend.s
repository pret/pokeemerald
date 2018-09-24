	.include "MPlayDef.s"

	.equ	ph_foot_blend_grp, voicegroup130
	.equ	ph_foot_blend_pri, 4
	.equ	ph_foot_blend_rev, 0
	.equ	ph_foot_blend_mvl, 127
	.equ	ph_foot_blend_key, 0
	.equ	ph_foot_blend_tbs, 1
	.equ	ph_foot_blend_exg, 0
	.equ	ph_foot_blend_cmp, 1

	.section .rodata
	.global	ph_foot_blend
	.align	2

@********************** Track  1 **********************@

ph_foot_blend_1:
	.byte	KEYSH , ph_foot_blend_key+0
	.byte	TEMPO , 120*ph_foot_blend_tbs/2
	.byte		VOICE , 36
	.byte		VOL   , 127*ph_foot_blend_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

ph_foot_blend:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ph_foot_blend_pri	@ Priority
	.byte	ph_foot_blend_rev	@ Reverb.

	.word	ph_foot_blend_grp

	.word	ph_foot_blend_1

	.end
