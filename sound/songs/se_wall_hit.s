	.include "MPlayDef.s"

	.equ	se_wall_hit_grp, voicegroup_rs_sfx_1
	.equ	se_wall_hit_pri, 2
	.equ	se_wall_hit_rev, reverb_set+50
	.equ	se_wall_hit_mvl, 127
	.equ	se_wall_hit_key, 0
	.equ	se_wall_hit_tbs, 1
	.equ	se_wall_hit_exg, 0
	.equ	se_wall_hit_cmp, 1

	.section .rodata
	.global	se_wall_hit
	.align	2

@********************** Track  1 **********************@

se_wall_hit_1:
	.byte	KEYSH , se_wall_hit_key+0
	.byte	TEMPO , 220*se_wall_hit_tbs/2
	.byte		VOICE , 89
	.byte		VOL   , 80*se_wall_hit_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N18   , Gn1 , v127
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_wall_hit:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_wall_hit_pri	@ Priority
	.byte	se_wall_hit_rev	@ Reverb.

	.word	se_wall_hit_grp

	.word	se_wall_hit_1

	.end
