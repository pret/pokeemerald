	.include "MPlayDef.s"

	.equ	se_hazure_grp, voicegroup_869D0F4
	.equ	se_hazure_pri, 4
	.equ	se_hazure_rev, reverb_set+50
	.equ	se_hazure_mvl, 127
	.equ	se_hazure_key, 0
	.equ	se_hazure_tbs, 1
	.equ	se_hazure_exg, 0
	.equ	se_hazure_cmp, 1

	.section .rodata
	.global	se_hazure
	.align	2

@********************** Track  1 **********************@

se_hazure_1:
	.byte	KEYSH , se_hazure_key+0
	.byte	TEMPO , 240*se_hazure_tbs/2
	.byte		VOICE , 92
	.byte		BENDR , 12
	.byte		VOL   , 120*se_hazure_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn2 , v127
	.byte	W03
	.byte		        Cn2 , v020
	.byte	W03
	.byte		N18   , Cn2 , v127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N09   , Cn2 , v020
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_hazure:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hazure_pri	@ Priority
	.byte	se_hazure_rev	@ Reverb.

	.word	se_hazure_grp

	.word	se_hazure_1

	.end
