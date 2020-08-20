	.include "MPlayDef.s"

	.equ	se_m_self_destruct_grp, voicegroup128
	.equ	se_m_self_destruct_pri, 4
	.equ	se_m_self_destruct_rev, reverb_set+50
	.equ	se_m_self_destruct_mvl, 127
	.equ	se_m_self_destruct_key, 0
	.equ	se_m_self_destruct_tbs, 1
	.equ	se_m_self_destruct_exg, 0
	.equ	se_m_self_destruct_cmp, 1

	.section .rodata
	.global	se_m_self_destruct
	.align	2

@********************** Track  1 **********************@

se_m_self_destruct_1:
	.byte	KEYSH , se_m_self_destruct_key+0
	.byte	TEMPO , 150*se_m_self_destruct_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 115*se_m_self_destruct_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Gn3 , v127
	.byte	W01
	.byte		        Cn3 
	.byte	W01
	.byte		N24   , An3 
	.byte	W06
	.byte		PAN   , c_v+6
	.byte	W04
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 102*se_m_self_destruct_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		VOL   , 88*se_m_self_destruct_mvl/mxv
	.byte	W03
	.byte		        78*se_m_self_destruct_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 67*se_m_self_destruct_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		PAN   , c_v+7
	.byte		VOL   , 45*se_m_self_destruct_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 13*se_m_self_destruct_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-15
	.byte	W22
	.byte	FINE

@******************************************************@
	.align	2

se_m_self_destruct:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_self_destruct_pri	@ Priority
	.byte	se_m_self_destruct_rev	@ Reverb.

	.word	se_m_self_destruct_grp

	.word	se_m_self_destruct_1

	.end
