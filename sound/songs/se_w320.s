	.include "MPlayDef.s"

	.equ	se_w320_grp, voicegroup128
	.equ	se_w320_pri, 4
	.equ	se_w320_rev, reverb_set+50
	.equ	se_w320_mvl, 127
	.equ	se_w320_key, 0
	.equ	se_w320_tbs, 1
	.equ	se_w320_exg, 0
	.equ	se_w320_cmp, 1

	.section .rodata
	.global	se_w320
	.align	2

@********************** Track  1 **********************@

se_w320_1:
	.byte	KEYSH , se_w320_key+0
	.byte	TEMPO , 100*se_w320_tbs/2
	.byte		VOICE , 64
	.byte		BENDR , 2
	.byte		LFOS  , 40
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*se_w320_mvl/mxv
	.byte		BEND  , c_v-16
	.byte		N21   , Gn5 , v112
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		MOD   , 10
	.byte	W03
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		N09   , An5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		BEND  , c_v-14
	.byte		N66   , Gn5 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 10
	.byte	W12
	.byte	W12
	.byte	W06
	.byte		VOL   , 61*se_w320_mvl/mxv
	.byte	W06
	.byte		        51*se_w320_mvl/mxv
	.byte	W06
	.byte		        36*se_w320_mvl/mxv
	.byte	W06
	.byte		        18*se_w320_mvl/mxv
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

se_w320_2:
	.byte	KEYSH , se_w320_key+0
	.byte		VOICE , 64
	.byte		BENDR , 2
	.byte		LFOS  , 40
	.byte		VOL   , 70*se_w320_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+12
	.byte		BEND  , c_v-16
	.byte		N21   , Gn5 , v072
	.byte	W03
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		MOD   , 10
	.byte	W03
	.byte	W09
	.byte		        0
	.byte	W03
	.byte		PAN   , c_v-12
	.byte		N09   , An5 
	.byte	W12
	.byte		PAN   , c_v+14
	.byte		N09   , En5 
	.byte	W12
	.byte		PAN   , c_v-15
	.byte		BEND  , c_v-14
	.byte		N66   , Gn5 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W06
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 10
	.byte	W12
	.byte	W06
	.byte		VOL   , 61*se_w320_mvl/mxv
	.byte	W06
	.byte		        51*se_w320_mvl/mxv
	.byte	W06
	.byte		        36*se_w320_mvl/mxv
	.byte	W06
	.byte		        18*se_w320_mvl/mxv
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_w320:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w320_pri	@ Priority
	.byte	se_w320_rev	@ Reverb.

	.word	se_w320_grp

	.word	se_w320_1
	.word	se_w320_2

	.end
