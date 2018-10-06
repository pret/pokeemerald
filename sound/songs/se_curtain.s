	.include "MPlayDef.s"

	.equ	se_curtain_grp, voicegroup129
	.equ	se_curtain_pri, 5
	.equ	se_curtain_rev, reverb_set+50
	.equ	se_curtain_mvl, 127
	.equ	se_curtain_key, 0
	.equ	se_curtain_tbs, 1
	.equ	se_curtain_exg, 0
	.equ	se_curtain_cmp, 1

	.section .rodata
	.global	se_curtain
	.align	2

@********************** Track  1 **********************@

se_curtain_1:
	.byte	KEYSH , se_curtain_key+0
	.byte	TEMPO , 98*se_curtain_tbs/2
	.byte		PAN   , c_v+0
	.byte		VOL   , 127*se_curtain_mvl/mxv
	.byte	W19
	.byte	TEMPO , 112*se_curtain_tbs/2
	.byte		VOICE , 38
	.byte		MOD   , 2
	.byte		N04   , Gs1 , v120
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		        1
	.byte		N04   , Cn2 
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , En2 
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , Gs2 
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		        1
	.byte		N04   , Cn3 
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		        1
	.byte		N04   , Ds3 
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		        1
	.byte		N04   , En3 , v096
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v032
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		MOD   , 1
	.byte		N04   , En3 , v048
	.byte	W03
	.byte		MOD   , 7
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v012
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		MOD   , 1
	.byte		N04   , En3 , v032
	.byte	W02
	.byte		MOD   , 7
	.byte	W03
	.byte		PAN   , c_v-62
	.byte		MOD   , 1
	.byte		N04   , En4 , v008
	.byte	W02
	.byte		MOD   , 7
	.byte	W02
	.byte		        2
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_curtain_2:
	.byte	KEYSH , se_curtain_key+0
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*se_curtain_mvl/mxv
	.byte	W19
	.byte		VOICE , 100
	.byte	W12
	.byte	W07
	.byte		N04   , Cn4 , v112
	.byte	W05
	.byte		        As4 
	.byte	W07
	.byte		        Gs5 , v064
	.byte	W05
	.byte		        Ds6 , v048
	.byte	W07
	.byte		        Gn6 , v032
	.byte	W05
	.byte	W12
	.byte	FINE

@********************** Track  3 **********************@

se_curtain_3:
	.byte	KEYSH , se_curtain_key+0
	.byte		VOICE , 125
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		MOD   , 2
	.byte		VOL   , 86*se_curtain_mvl/mxv
	.byte		BEND  , c_v-57
	.byte		N09   , Cn5 , v064
	.byte	W01
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v+0
	.byte	W03
	.byte		N01   , Gn5 , v096
	.byte	W10
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_curtain:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_curtain_pri	@ Priority
	.byte	se_curtain_rev	@ Reverb.

	.word	se_curtain_grp

	.word	se_curtain_1
	.word	se_curtain_2
	.word	se_curtain_3

	.end
