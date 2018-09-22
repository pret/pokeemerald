	.include "MPlayDef.s"

	.equ	mus_rg_sousa_grp, voicegroup182
	.equ	mus_rg_sousa_pri, 0
	.equ	mus_rg_sousa_rev, reverb_set+50
	.equ	mus_rg_sousa_mvl, 127
	.equ	mus_rg_sousa_key, 0
	.equ	mus_rg_sousa_tbs, 1
	.equ	mus_rg_sousa_exg, 0
	.equ	mus_rg_sousa_cmp, 1

	.section .rodata
	.global	mus_rg_sousa
	.align	2

@********************** Track  1 **********************@

mus_rg_sousa_1:
	.byte	KEYSH , mus_rg_sousa_key+0
	.byte	TEMPO , 120*mus_rg_sousa_tbs/2
	.byte		VOICE , 0
	.byte		VOL   , 85*mus_rg_sousa_mvl/mxv
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_rg_sousa_1_B1:
mus_rg_sousa_1_000:
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
mus_rg_sousa_1_001:
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v120
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_sousa_1_000
	.byte	PATT
	 .word	mus_rg_sousa_1_001
	.byte	GOTO
	 .word	mus_rg_sousa_1_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_sousa:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_sousa_pri	@ Priority
	.byte	mus_rg_sousa_rev	@ Reverb.

	.word	mus_rg_sousa_grp

	.word	mus_rg_sousa_1

	.end
