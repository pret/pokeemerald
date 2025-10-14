	.include "MPlayDef.s"

	.equ	se_m_giga_drain_grp, voicegroup_rs_sfx_2
	.equ	se_m_giga_drain_pri, 4
	.equ	se_m_giga_drain_rev, reverb_set+50
	.equ	se_m_giga_drain_mvl, 127
	.equ	se_m_giga_drain_key, 0
	.equ	se_m_giga_drain_tbs, 1
	.equ	se_m_giga_drain_exg, 0
	.equ	se_m_giga_drain_cmp, 1

	.section .rodata
	.global	se_m_giga_drain
	.align	2

@********************** Track  1 **********************@

se_m_giga_drain_1:
	.byte	KEYSH , se_m_giga_drain_key+0
	.byte	TEMPO , 150*se_m_giga_drain_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_giga_drain_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn2 , v127
	.byte	W02
	.byte		PAN   , c_v+3
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOICE , 23
	.byte		N02   , Cn3 , v104
	.byte	W01
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		VOICE , 36
	.byte		N02   , Cn2 , v127
	.byte	W01
	.byte		PAN   , c_v+7
	.byte	W01
	.byte		VOICE , 23
	.byte		BEND  , c_v+4
	.byte		N06   , Cn3 , v104
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v-5
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		        c_v-23
	.byte	W01
	.byte		VOICE , 36
	.byte		BEND  , c_v+0
	.byte		N03   , An2 , v100
	.byte	W04
	.byte		PAN   , c_v+5
	.byte		N03   , Bn2 , v076
	.byte	W03
	.byte		PAN   , c_v-6
	.byte		N02   , Cs3 , v040
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_giga_drain:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_giga_drain_pri	@ Priority
	.byte	se_m_giga_drain_rev	@ Reverb.

	.word	se_m_giga_drain_grp

	.word	se_m_giga_drain_1

	.end
