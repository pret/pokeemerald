	.include "MPlayDef.s"

	.equ	se_hi_turun_grp, voicegroup128
	.equ	se_hi_turun_pri, 4
	.equ	se_hi_turun_rev, reverb_set+50
	.equ	se_hi_turun_mvl, 127
	.equ	se_hi_turun_key, 0
	.equ	se_hi_turun_tbs, 1
	.equ	se_hi_turun_exg, 0
	.equ	se_hi_turun_cmp, 1

	.section .rodata
	.global	se_hi_turun
	.align	2

@********************** Track  1 **********************@

se_hi_turun_1:
	.byte	KEYSH , se_hi_turun_key+0
	.byte	TEMPO , 220*se_hi_turun_tbs/2
	.byte		VOICE , 9
	.byte		VOL   , 90*se_hi_turun_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N21   , Gn5 
	.byte	W03
	.byte	W03
	.byte		VOL   , 81*se_hi_turun_mvl/mxv
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		VOL   , 72*se_hi_turun_mvl/mxv
	.byte		BEND  , c_v+20
	.byte	W03
	.byte		VOL   , 46*se_hi_turun_mvl/mxv
	.byte		BEND  , c_v+37
	.byte	W03
	.byte		VOL   , 24*se_hi_turun_mvl/mxv
	.byte		BEND  , c_v+63
	.byte	W03
	.byte		VOL   , 7*se_hi_turun_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_hi_turun:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hi_turun_pri	@ Priority
	.byte	se_hi_turun_rev	@ Reverb.

	.word	se_hi_turun_grp

	.word	se_hi_turun_1

	.end
