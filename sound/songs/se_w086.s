	.include "MPlayDef.s"

	.equ	se_w086_grp, voicegroup128
	.equ	se_w086_pri, 4
	.equ	se_w086_rev, reverb_set+50
	.equ	se_w086_mvl, 127
	.equ	se_w086_key, 0
	.equ	se_w086_tbs, 1
	.equ	se_w086_exg, 0
	.equ	se_w086_cmp, 1

	.section .rodata
	.global	se_w086
	.align	2

@********************** Track  1 **********************@

se_w086_1:
	.byte	KEYSH , se_w086_key+0
	.byte	TEMPO , 150*se_w086_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 110*se_w086_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+32
	.byte		N06   , Gn3 , v127
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+32
	.byte		N04   , Cn3 
	.byte	W02
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Gn3 
	.byte	W02
	.byte		        Bn2 
	.byte	W02
	.byte		N13   , Gn3 
	.byte	W02
	.byte		VOL   , 96*se_w086_mvl/mxv
	.byte	W01
	.byte		        85*se_w086_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-23
	.byte	W01
	.byte		VOL   , 66*se_w086_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		VOL   , 36*se_w086_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-54
	.byte	W02
	.byte		VOL   , 12*se_w086_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-64
	.byte	W21
	.byte	FINE

@********************** Track  2 **********************@

se_w086_2:
	.byte	KEYSH , se_w086_key+0
	.byte		VOICE , 5
	.byte		VOL   , 110*se_w086_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v052
	.byte	W04
	.byte		PAN   , c_v+10
	.byte		N02   , En3 , v044
	.byte	W04
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v036
	.byte	W04
	.byte		PAN   , c_v+10
	.byte		N02   , En3 , v028
	.byte	W04
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v020
	.byte	W08
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_w086:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w086_pri	@ Priority
	.byte	se_w086_rev	@ Reverb.

	.word	se_w086_grp

	.word	se_w086_1
	.word	se_w086_2

	.end
