	.include "MPlayDef.s"

	.equ	se_m_uproar_grp, voicegroup128
	.equ	se_m_uproar_pri, 4
	.equ	se_m_uproar_rev, reverb_set+50
	.equ	se_m_uproar_mvl, 127
	.equ	se_m_uproar_key, 0
	.equ	se_m_uproar_tbs, 1
	.equ	se_m_uproar_exg, 0
	.equ	se_m_uproar_cmp, 1

	.section .rodata
	.global	se_m_uproar
	.align	2

@********************** Track  1 **********************@

se_m_uproar_1:
	.byte	KEYSH , se_m_uproar_key+0
	.byte	TEMPO , 150*se_m_uproar_tbs/2
	.byte		VOICE , 60
	.byte		BENDR , 12
	.byte		VOL   , 25*se_m_uproar_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N24   , Gs2 , v127
	.byte	W01
	.byte		PAN   , c_v+2
	.byte		VOL   , 51*se_m_uproar_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+5
	.byte		VOL   , 74*se_m_uproar_mvl/mxv
	.byte	W01
	.byte		        89*se_m_uproar_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		PAN   , c_v+2
	.byte		VOL   , 100*se_m_uproar_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v-2
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		PAN   , c_v-4
	.byte	W02
	.byte		        c_v-2
	.byte		BEND  , c_v+5
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+5
	.byte	W02
	.byte		        c_v+2
	.byte	W02
	.byte		        c_v+0
	.byte	W01
	.byte		VOL   , 85*se_m_uproar_mvl/mxv
	.byte		PAN   , c_v-2
	.byte	W01
	.byte		        c_v-4
	.byte		VOL   , 62*se_m_uproar_mvl/mxv
	.byte	W01
	.byte		        33*se_m_uproar_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-2
	.byte		VOL   , 11*se_m_uproar_mvl/mxv
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_uproar:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_uproar_pri	@ Priority
	.byte	se_m_uproar_rev	@ Reverb.

	.word	se_m_uproar_grp

	.word	se_m_uproar_1

	.end
