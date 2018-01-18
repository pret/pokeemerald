	.include "MPlayDef.s"

	.equ	se_naminori_grp, voicegroup_869D0F4
	.equ	se_naminori_pri, 4
	.equ	se_naminori_rev, reverb_set+50
	.equ	se_naminori_mvl, 127
	.equ	se_naminori_key, 0
	.equ	se_naminori_tbs, 1
	.equ	se_naminori_exg, 0
	.equ	se_naminori_cmp, 1

	.section .rodata
	.global	se_naminori
	.align	2

@********************** Track  1 **********************@

se_naminori_1:
	.byte	KEYSH , se_naminori_key+0
	.byte	TEMPO , 220*se_naminori_tbs/2
	.byte		VOICE , 123
	.byte		VOL   , 75*se_naminori_mvl/mxv
	.byte		N03   , Ds3 , v127
	.byte	W03
	.byte		TIE   , Cn4 
	.byte	W21
	.byte	W24
	.byte	W18
	.byte		VOL   , 75*se_naminori_mvl/mxv
	.byte	W06
	.byte		        71*se_naminori_mvl/mxv
	.byte	W05
	.byte		        67*se_naminori_mvl/mxv
	.byte	W03
	.byte		        62*se_naminori_mvl/mxv
	.byte	W04
	.byte		        59*se_naminori_mvl/mxv
	.byte	W05
	.byte		        57*se_naminori_mvl/mxv
	.byte	W03
	.byte		        54*se_naminori_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        50*se_naminori_mvl/mxv
	.byte	W03
	.byte		        49*se_naminori_mvl/mxv
	.byte	W03
	.byte		        44*se_naminori_mvl/mxv
	.byte	W04
	.byte		        41*se_naminori_mvl/mxv
	.byte	W02
	.byte		        38*se_naminori_mvl/mxv
	.byte	W03
	.byte		        35*se_naminori_mvl/mxv
	.byte	W03
	.byte		        32*se_naminori_mvl/mxv
	.byte	W04
	.byte		        28*se_naminori_mvl/mxv
	.byte	W02
	.byte		        24*se_naminori_mvl/mxv
	.byte	W03
	.byte		        21*se_naminori_mvl/mxv
	.byte	W03
	.byte		        18*se_naminori_mvl/mxv
	.byte	W04
	.byte		        14*se_naminori_mvl/mxv
	.byte	W02
	.byte		        11*se_naminori_mvl/mxv
	.byte	W03
	.byte		        9*se_naminori_mvl/mxv
	.byte	W03
	.byte		        6*se_naminori_mvl/mxv
	.byte	W04
	.byte		        3*se_naminori_mvl/mxv
	.byte	W02
	.byte		        1*se_naminori_mvl/mxv
	.byte	W22
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_naminori:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_naminori_pri	@ Priority
	.byte	se_naminori_rev	@ Reverb.

	.word	se_naminori_grp

	.word	se_naminori_1

	.end
