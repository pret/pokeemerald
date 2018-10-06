	.include "MPlayDef.s"

	.equ	se_w240_grp, voicegroup128
	.equ	se_w240_pri, 4
	.equ	se_w240_rev, reverb_set+50
	.equ	se_w240_mvl, 127
	.equ	se_w240_key, 0
	.equ	se_w240_tbs, 1
	.equ	se_w240_exg, 0
	.equ	se_w240_cmp, 1

	.section .rodata
	.global	se_w240
	.align	2

@********************** Track  1 **********************@

se_w240_1:
	.byte	KEYSH , se_w240_key+0
	.byte	TEMPO , 220*se_w240_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 20*se_w240_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn3 , v064
	.byte	W03
	.byte		VOL   , 37*se_w240_mvl/mxv
	.byte	W03
	.byte		        53*se_w240_mvl/mxv
	.byte	W03
	.byte		        60*se_w240_mvl/mxv
	.byte	W03
	.byte		        71*se_w240_mvl/mxv
	.byte	W03
	.byte		        81*se_w240_mvl/mxv
	.byte	W03
	.byte		        93*se_w240_mvl/mxv
	.byte	W03
	.byte		        110*se_w240_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+3
	.byte	W06
	.byte		        c_v+11
	.byte	W12
	.byte		        c_v+20
	.byte	W06
	.byte		        c_v+25
	.byte	W12
	.byte		        c_v+14
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte	W06
	.byte		        c_v-3
	.byte	W12
	.byte		        c_v-16
	.byte	W06
	.byte	W06
	.byte		        c_v-26
	.byte	W12
	.byte		        c_v-16
	.byte	W06
	.byte		VOL   , 104*se_w240_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		VOL   , 101*se_w240_mvl/mxv
	.byte	W03
	.byte		        98*se_w240_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		VOL   , 93*se_w240_mvl/mxv
	.byte	W03
	.byte		        90*se_w240_mvl/mxv
	.byte		PAN   , c_v+14
	.byte	W03
	.byte		VOL   , 86*se_w240_mvl/mxv
	.byte	W03
	.byte		        83*se_w240_mvl/mxv
	.byte	W03
	.byte		        77*se_w240_mvl/mxv
	.byte	W03
	.byte		        73*se_w240_mvl/mxv
	.byte		PAN   , c_v+24
	.byte	W03
	.byte		VOL   , 66*se_w240_mvl/mxv
	.byte	W03
	.byte		        58*se_w240_mvl/mxv
	.byte	W03
	.byte		        44*se_w240_mvl/mxv
	.byte	W03
	.byte		        32*se_w240_mvl/mxv
	.byte		PAN   , c_v+15
	.byte	W03
	.byte		VOL   , 16*se_w240_mvl/mxv
	.byte	W03
	.byte		        1*se_w240_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W06
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_w240:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w240_pri	@ Priority
	.byte	se_w240_rev	@ Reverb.

	.word	se_w240_grp

	.word	se_w240_1

	.end
