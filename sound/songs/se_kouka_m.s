	.include "MPlayDef.s"

	.equ	se_kouka_m_grp, voicegroup127
	.equ	se_kouka_m_pri, 5
	.equ	se_kouka_m_rev, reverb_set+50
	.equ	se_kouka_m_mvl, 127
	.equ	se_kouka_m_key, 0
	.equ	se_kouka_m_tbs, 1
	.equ	se_kouka_m_exg, 0
	.equ	se_kouka_m_cmp, 1

	.section .rodata
	.global	se_kouka_m
	.align	2

@********************** Track  1 **********************@

se_kouka_m_1:
	.byte	KEYSH , se_kouka_m_key+0
	.byte	TEMPO , 90*se_kouka_m_tbs/2
	.byte		VOICE , 125
	.byte		VOL   , 110*se_kouka_m_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , As2 , v100
	.byte	W03
	.byte		BEND  , c_v-33
	.byte		N36   , Ds3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_kouka_m_2:
	.byte	KEYSH , se_kouka_m_key+0
	.byte		VOICE , 0
	.byte		VOL   , 110*se_kouka_m_mvl/mxv
	.byte		N03   , Cn3 , v127
	.byte	W03
	.byte		N18   
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_kouka_m:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kouka_m_pri	@ Priority
	.byte	se_kouka_m_rev	@ Reverb.

	.word	se_kouka_m_grp

	.word	se_kouka_m_1
	.word	se_kouka_m_2

	.end
