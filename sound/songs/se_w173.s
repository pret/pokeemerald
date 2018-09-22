	.include "MPlayDef.s"

	.equ	se_w173_grp, voicegroup128
	.equ	se_w173_pri, 4
	.equ	se_w173_rev, reverb_set+50
	.equ	se_w173_mvl, 127
	.equ	se_w173_key, 0
	.equ	se_w173_tbs, 1
	.equ	se_w173_exg, 0
	.equ	se_w173_cmp, 1

	.section .rodata
	.global	se_w173
	.align	2

@********************** Track  1 **********************@

se_w173_1:
	.byte	KEYSH , se_w173_key+0
	.byte	TEMPO , 220*se_w173_tbs/2
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 27*se_w173_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N10   , An1 , v127
	.byte	W01
	.byte		VOL   , 75*se_w173_mvl/mxv
	.byte	W01
	.byte		        120*se_w173_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        75*se_w173_mvl/mxv
	.byte	W01
	.byte		        28*se_w173_mvl/mxv
	.byte	W03
	.byte		VOICE , 36
	.byte		VOL   , 83*se_w173_mvl/mxv
	.byte		N18   , En2 , v112
	.byte	W02
	.byte		VOL   , 87*se_w173_mvl/mxv
	.byte	W02
	.byte		        91*se_w173_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        97*se_w173_mvl/mxv
	.byte	W02
	.byte		        102*se_w173_mvl/mxv
	.byte	W01
	.byte		        109*se_w173_mvl/mxv
	.byte	W02
	.byte		        113*se_w173_mvl/mxv
	.byte	W01
	.byte		        120*se_w173_mvl/mxv
	.byte	W05
	.byte	FINE

@********************** Track  2 **********************@

se_w173_2:
	.byte		VOL   , 120*se_w173_mvl/mxv
	.byte	KEYSH , se_w173_key+0
	.byte		VOICE , 27
	.byte		N01   , En2 , v052
	.byte	W02
	.byte		        Dn2 
	.byte	W02
	.byte		        En2 
	.byte	W02
	.byte	W01
	.byte		        Dn2 
	.byte	W02
	.byte		        En2 
	.byte	W03
	.byte	W01
	.byte		        En2 , v064
	.byte	W02
	.byte		        Gs2 
	.byte	W03
	.byte		        Dn3 
	.byte	W02
	.byte		        En2 
	.byte	W02
	.byte		        Gs2 
	.byte	W02
	.byte	W01
	.byte		        Dn3 
	.byte	W05
	.byte	FINE

@******************************************************@
	.align	2

se_w173:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w173_pri	@ Priority
	.byte	se_w173_rev	@ Reverb.

	.word	se_w173_grp

	.word	se_w173_1
	.word	se_w173_2

	.end
