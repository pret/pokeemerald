	.include "MPlayDef.s"

	.equ	mus_dummy_grp, voicegroup000
	.equ	mus_dummy_pri, 0
	.equ	mus_dummy_rev, reverb_set+40
	.equ	mus_dummy_mvl, 127
	.equ	mus_dummy_key, 0
	.equ	mus_dummy_tbs, 1
	.equ	mus_dummy_exg, 0
	.equ	mus_dummy_cmp, 1

	.section .rodata
	.global	mus_dummy
	.align	2

@******************************************************@
	.align	2

mus_dummy:
	.byte	0	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_dummy_pri	@ Priority
	.byte	mus_dummy_rev	@ Reverb.

	.word	mus_dummy_grp


	.end
