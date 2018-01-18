	.include "MPlayDef.s"

	.equ	se_poke_dead_grp, voicegroup_869D0F4
	.equ	se_poke_dead_pri, 5
	.equ	se_poke_dead_rev, reverb_set+50
	.equ	se_poke_dead_mvl, 127
	.equ	se_poke_dead_key, 0
	.equ	se_poke_dead_tbs, 1
	.equ	se_poke_dead_exg, 0
	.equ	se_poke_dead_cmp, 1

	.section .rodata
	.global	se_poke_dead
	.align	2

@********************** Track  1 **********************@

se_poke_dead_1:
	.byte	KEYSH , se_poke_dead_key+0
	.byte	TEMPO , 90*se_poke_dead_tbs/2
	.byte		VOICE , 90
	.byte		VOL   , 110*se_poke_dead_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , Cn4 , v100
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_poke_dead_2:
	.byte	KEYSH , se_poke_dead_key+0
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 82*se_poke_dead_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N05   , Gs4 , v060
	.byte	W03
	.byte		VOL   , 94*se_poke_dead_mvl/mxv
	.byte	W03
	.byte		        103*se_poke_dead_mvl/mxv
	.byte		N22   
	.byte	W03
	.byte		VOL   , 110*se_poke_dead_mvl/mxv
	.byte	W03
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  3 **********************@

se_poke_dead_3:
	.byte	KEYSH , se_poke_dead_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_poke_dead_mvl/mxv
	.byte		N06   , Cn3 , v080
	.byte	W06
	.byte		N18   , Cn3 , v092
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_poke_dead:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_poke_dead_pri	@ Priority
	.byte	se_poke_dead_rev	@ Reverb.

	.word	se_poke_dead_grp

	.word	se_poke_dead_1
	.word	se_poke_dead_2
	.word	se_poke_dead_3

	.end
