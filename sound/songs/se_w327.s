	.include "MPlayDef.s"

	.equ	se_w327_grp, voicegroup128
	.equ	se_w327_pri, 4
	.equ	se_w327_rev, reverb_set+50
	.equ	se_w327_mvl, 127
	.equ	se_w327_key, 0
	.equ	se_w327_tbs, 1
	.equ	se_w327_exg, 0
	.equ	se_w327_cmp, 1

	.section .rodata
	.global	se_w327
	.align	2

@********************** Track  1 **********************@

se_w327_1:
	.byte	KEYSH , se_w327_key+0
	.byte	TEMPO , 220*se_w327_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 110*se_w327_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+0
	.byte		N02   , Cn4 , v127
	.byte	W03
	.byte		VOL   , 104*se_w327_mvl/mxv
	.byte	W03
	.byte		        93*se_w327_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N02   , Cn5 
	.byte	W03
	.byte		VOL   , 110*se_w327_mvl/mxv
	.byte	W01
	.byte		VOICE , 22
	.byte		PAN   , c_v+0
	.byte		N24   , Cn4 , v060
	.byte	W02
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v+1
	.byte	W01
	.byte		VOL   , 105*se_w327_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 103*se_w327_mvl/mxv
	.byte	W02
	.byte		        91*se_w327_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 77*se_w327_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 61*se_w327_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		VOL   , 38*se_w327_mvl/mxv
	.byte	W01
	.byte		        15*se_w327_mvl/mxv
	.byte		BEND  , c_v-3
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_w327_2:
	.byte	KEYSH , se_w327_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_w327_mvl/mxv
	.byte		N02   , Cn3 , v060
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Gs4 
	.byte	W04
	.byte		        Gs4 , v020
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_w327:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w327_pri	@ Priority
	.byte	se_w327_rev	@ Reverb.

	.word	se_w327_grp

	.word	se_w327_1
	.word	se_w327_2

	.end
