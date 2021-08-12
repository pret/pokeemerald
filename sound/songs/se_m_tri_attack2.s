	.include "MPlayDef.s"

	.equ	se_m_tri_attack2_grp, voicegroup128
	.equ	se_m_tri_attack2_pri, 4
	.equ	se_m_tri_attack2_rev, reverb_set+50
	.equ	se_m_tri_attack2_mvl, 127
	.equ	se_m_tri_attack2_key, 0
	.equ	se_m_tri_attack2_tbs, 1
	.equ	se_m_tri_attack2_exg, 0
	.equ	se_m_tri_attack2_cmp, 1

	.section .rodata
	.global	se_m_tri_attack2
	.align	2

@********************** Track  1 **********************@

se_m_tri_attack2_1:
	.byte	KEYSH , se_m_tri_attack2_key+0
	.byte	TEMPO , 220*se_m_tri_attack2_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_tri_attack2_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N09   , An3 , v127
	.byte	W03
	.byte		BEND  , c_v+21
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v+6
	.byte		N15   , An3 , v120
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		PAN   , c_v+10
	.byte	W02
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-29
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N09   , Cn3 , v127
	.byte	W06
	.byte		BEND  , c_v-8
	.byte	W03
	.byte		        c_v-15
	.byte		N60   , Cs3 , v124
	.byte	W03
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W06
	.byte		        c_v+0
	.byte		BEND  , c_v-8
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-9
	.byte	W03
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-22
	.byte	W06
	.byte		VOL   , 103*se_m_tri_attack2_mvl/mxv
	.byte		PAN   , c_v+10
	.byte	W03
	.byte		BEND  , c_v-32
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOL   , 95*se_m_tri_attack2_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W03
	.byte		PAN   , c_v-9
	.byte	W05
	.byte		BEND  , c_v-45
	.byte	W01
	.byte		VOL   , 66*se_m_tri_attack2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W05
	.byte		        c_v+10
	.byte	W01
	.byte		BEND  , c_v-52
	.byte	W03
	.byte		VOL   , 21*se_m_tri_attack2_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_m_tri_attack2_2:
	.byte	KEYSH , se_m_tri_attack2_key+0
	.byte		VOICE , 4
	.byte		VOL   , 110*se_m_tri_attack2_mvl/mxv
	.byte		N06   , Cn3 , v060
	.byte	W09
	.byte		N15   
	.byte	W15
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_tri_attack2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_tri_attack2_pri	@ Priority
	.byte	se_m_tri_attack2_rev	@ Reverb.

	.word	se_m_tri_attack2_grp

	.word	se_m_tri_attack2_1
	.word	se_m_tri_attack2_2

	.end
