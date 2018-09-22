	.include "MPlayDef.s"

	.equ	ph_trap_blend_grp, voicegroup130
	.equ	ph_trap_blend_pri, 4
	.equ	ph_trap_blend_rev, 0
	.equ	ph_trap_blend_mvl, 127
	.equ	ph_trap_blend_key, 0
	.equ	ph_trap_blend_tbs, 1
	.equ	ph_trap_blend_exg, 0
	.equ	ph_trap_blend_cmp, 1

	.section .rodata
	.global	ph_trap_blend
	.align	2

@********************** Track  1 **********************@

ph_trap_blend_1:
	.byte	KEYSH , ph_trap_blend_key+0
	.byte	TEMPO , 120*ph_trap_blend_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 127*ph_trap_blend_mvl/mxv
	.byte		N44   , Cn3 , v127
	.byte	W44
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

ph_trap_blend:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ph_trap_blend_pri	@ Priority
	.byte	ph_trap_blend_rev	@ Reverb.

	.word	ph_trap_blend_grp

	.word	ph_trap_blend_1

	.end
