	.include "MPlayDef.s"

	.equ	se_stop_grp, voicegroup_pokemon_cry
	.equ	se_stop_pri, 0
	.equ	se_stop_rev, reverb_set+40
	.equ	se_stop_mvl, 127
	.equ	se_stop_key, 0
	.equ	se_stop_tbs, 1
	.equ	se_stop_exg, 0
	.equ	se_stop_cmp, 1

	.section .rodata
	.global	se_stop
	.align	2

@******************************************************@
	.align	2

se_stop:
	.byte	0	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_stop_pri	@ Priority
	.byte	se_stop_rev	@ Reverb.

	.word	se_stop_grp


	.end
