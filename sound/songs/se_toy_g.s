	.include "MPlayDef.s"

	.equ	se_toy_g_grp, voicegroup128
	.equ	se_toy_g_pri, 4
	.equ	se_toy_g_rev, reverb_set+50
	.equ	se_toy_g_mvl, 127
	.equ	se_toy_g_key, 0
	.equ	se_toy_g_tbs, 1
	.equ	se_toy_g_exg, 0
	.equ	se_toy_g_cmp, 1

	.section .rodata
	.global	se_toy_g
	.align	2

@********************** Track  1 **********************@

se_toy_g_1:
	.byte	KEYSH , se_toy_g_key+0
	.byte	TEMPO , 150*se_toy_g_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 110*se_toy_g_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Gn5 , v112
	.byte	W06
	.byte	W06
	.byte		N06   , Gn5 , v040
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_toy_g_2:
	.byte	KEYSH , se_toy_g_key+0
	.byte		VOICE , 17
	.byte		VOL   , 110*se_toy_g_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , Dn6 , v060
	.byte	W06
	.byte	W06
	.byte		N06   , Dn6 , v032
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_toy_g:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_toy_g_pri	@ Priority
	.byte	se_toy_g_rev	@ Reverb.

	.word	se_toy_g_grp

	.word	se_toy_g_1
	.word	se_toy_g_2

	.end
