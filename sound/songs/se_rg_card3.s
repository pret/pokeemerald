	.include "MPlayDef.s"

	.equ	se_rg_card3_grp, voicegroup_86A0154
	.equ	se_rg_card3_pri, 5
	.equ	se_rg_card3_rev, reverb_set+50
	.equ	se_rg_card3_mvl, 127
	.equ	se_rg_card3_key, 0
	.equ	se_rg_card3_tbs, 1
	.equ	se_rg_card3_exg, 0
	.equ	se_rg_card3_cmp, 1

	.section .rodata
	.global	se_rg_card3
	.align	2

@********************** Track  1 **********************@

se_rg_card3_1:
	.byte	KEYSH , se_rg_card3_key+0
	.byte	TEMPO , 174*se_rg_card3_tbs/2
	.byte		VOICE , 46
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 112*se_rg_card3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 112*se_rg_card3_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N03   , An5 , v112
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte		N03   , Bn5 
	.byte	W03
	.byte		VOL   , 112*se_rg_card3_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N06   , En6 
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		        112*se_rg_card3_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N06   , En6 , v040
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		VOL   , 97*se_rg_card3_mvl/mxv
	.byte		N06   , En6 , v032
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		VOL   , 96*se_rg_card3_mvl/mxv
	.byte		N06   , En6 , v024
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		VOL   , 80*se_rg_card3_mvl/mxv
	.byte		N06   , En6 , v016
	.byte	W03
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		VOL   , 80*se_rg_card3_mvl/mxv
	.byte		N06   , En6 , v012
	.byte	W03
	.byte		VOL   , 48*se_rg_card3_mvl/mxv
	.byte	W03
	.byte		N06   , En6 , v008
	.byte	W03
	.byte		VOL   , 2*se_rg_card3_mvl/mxv
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

se_rg_card3_2:
	.byte	KEYSH , se_rg_card3_key+0
	.byte		VOICE , 124
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*se_rg_card3_mvl/mxv
	.byte		N03   , Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W18
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_rg_card3:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_card3_pri	@ Priority
	.byte	se_rg_card3_rev	@ Reverb.

	.word	se_rg_card3_grp

	.word	se_rg_card3_1
	.word	se_rg_card3_2

	.end
