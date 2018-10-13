	.include "MPlayDef.s"

	.equ	se_toy_kabe_grp, voicegroup128
	.equ	se_toy_kabe_pri, 4
	.equ	se_toy_kabe_rev, reverb_set+50
	.equ	se_toy_kabe_mvl, 127
	.equ	se_toy_kabe_key, 0
	.equ	se_toy_kabe_tbs, 1
	.equ	se_toy_kabe_exg, 0
	.equ	se_toy_kabe_cmp, 1

	.section .rodata
	.global	se_toy_kabe
	.align	2

@********************** Track  1 **********************@

se_toy_kabe_1:
	.byte	KEYSH , se_toy_kabe_key+0
	.byte	TEMPO , 240*se_toy_kabe_tbs/2
	.byte		VOICE , 41
	.byte		BENDR , 12
	.byte		VOL   , 110*se_toy_kabe_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Fs4 , v127
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte	W01
	.byte		        c_v+0
	.byte		N10   , Cn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_toy_kabe_mvl/mxv
	.byte	W02
	.byte		        82*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte		        45*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte		        20*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W01
	.byte		        110*se_toy_kabe_mvl/mxv
	.byte		N10   , Cn4 , v040
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 96*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte		        82*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte		        45*se_toy_kabe_mvl/mxv
	.byte	W01
	.byte		        20*se_toy_kabe_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_toy_kabe:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_toy_kabe_pri	@ Priority
	.byte	se_toy_kabe_rev	@ Reverb.

	.word	se_toy_kabe_grp

	.word	se_toy_kabe_1

	.end
