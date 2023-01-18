	.include "MPlayDef.s"

	.equ	se_m_supersonic_grp, voicegroup128
	.equ	se_m_supersonic_pri, 4
	.equ	se_m_supersonic_rev, reverb_set+50
	.equ	se_m_supersonic_mvl, 127
	.equ	se_m_supersonic_key, 0
	.equ	se_m_supersonic_tbs, 1
	.equ	se_m_supersonic_exg, 0
	.equ	se_m_supersonic_cmp, 1

	.section .rodata
	.global	se_m_supersonic
	.align	2

@********************** Track  1 **********************@

se_m_supersonic_1:
	.byte	KEYSH , se_m_supersonic_key+0
	.byte	TEMPO , 150*se_m_supersonic_tbs/2
	.byte		VOICE , 43
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N07   , Gs4 , v127
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		VOL   , 75*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		VOL   , 93*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		PAN   , c_v+9
	.byte		VOL   , 110*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v+7
	.byte	W02
	.byte	W02
	.byte		VOL   , 0*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-4
	.byte		N32
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		VOL   , 36*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		PAN   , c_v+9
	.byte		VOL   , 67*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		VOL   , 84*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		VOL   , 92*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		VOL   , 99*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 105*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 110*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-4
	.byte	W02
	.byte		VOL   , 46*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 67*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 84*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		VOL   , 100*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 110*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 101*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+2
	.byte	W02
	.byte		VOL   , 85*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 75*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-13
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 48*se_m_supersonic_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 24*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 6*se_m_supersonic_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_supersonic:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_supersonic_pri	@ Priority
	.byte	se_m_supersonic_rev	@ Reverb.

	.word	se_m_supersonic_grp

	.word	se_m_supersonic_1

	.end
