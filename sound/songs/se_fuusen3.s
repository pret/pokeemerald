	.include "MPlayDef.s"

	.equ	se_fuusen3_grp, voicegroup128
	.equ	se_fuusen3_pri, 4
	.equ	se_fuusen3_rev, reverb_set+50
	.equ	se_fuusen3_mvl, 127
	.equ	se_fuusen3_key, 0
	.equ	se_fuusen3_tbs, 1
	.equ	se_fuusen3_exg, 0
	.equ	se_fuusen3_cmp, 1

	.section .rodata
	.global	se_fuusen3
	.align	2

@********************** Track  1 **********************@

se_fuusen3_1:
	.byte	KEYSH , se_fuusen3_key+0
	.byte	TEMPO , 240*se_fuusen3_tbs/2
	.byte		VOICE , 2
	.byte		BENDR , 12
	.byte		VOL   , 105*se_fuusen3_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Fn3 , v127
	.byte	W02
	.byte		N01   , Cn4 , v112
	.byte	W02
	.byte		N03   , Fn3 , v052
	.byte	W02
	.byte	W02
	.byte		VOICE , 23
	.byte		N01   , En4 , v092
	.byte	W01
	.byte		        Cn5 
	.byte	W03
	.byte		        Gn3 
	.byte	W01
	.byte		        En4 
	.byte	W02
	.byte		        En3 , v048
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_fuusen3:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_fuusen3_pri	@ Priority
	.byte	se_fuusen3_rev	@ Reverb.

	.word	se_fuusen3_grp

	.word	se_fuusen3_1

	.end
