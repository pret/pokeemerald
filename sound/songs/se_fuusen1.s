	.include "MPlayDef.s"

	.equ	se_fuusen1_grp, voicegroup_869D6F4
	.equ	se_fuusen1_pri, 4
	.equ	se_fuusen1_rev, reverb_set+50
	.equ	se_fuusen1_mvl, 127
	.equ	se_fuusen1_key, 0
	.equ	se_fuusen1_tbs, 1
	.equ	se_fuusen1_exg, 0
	.equ	se_fuusen1_cmp, 1

	.section .rodata
	.global	se_fuusen1
	.align	2

@********************** Track  1 **********************@

se_fuusen1_1:
	.byte	KEYSH , se_fuusen1_key+0
	.byte	TEMPO , 240*se_fuusen1_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_fuusen1_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Cn4 , v127
	.byte	W06
	.byte		VOICE , 23
	.byte		N02   , Cn3 , v112
	.byte	W07
	.byte		N01   , Cn4 
	.byte	W05
	.byte		        Cn3 , v100
	.byte	W02
	.byte		        Gn3 , v092
	.byte	W02
	.byte		        Cn3 , v072
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_fuusen1:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_fuusen1_pri	@ Priority
	.byte	se_fuusen1_rev	@ Reverb.

	.word	se_fuusen1_grp

	.word	se_fuusen1_1

	.end
