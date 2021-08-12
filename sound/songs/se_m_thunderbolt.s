	.include "MPlayDef.s"

	.equ	se_m_thunderbolt_grp, voicegroup128
	.equ	se_m_thunderbolt_pri, 4
	.equ	se_m_thunderbolt_rev, reverb_set+50
	.equ	se_m_thunderbolt_mvl, 127
	.equ	se_m_thunderbolt_key, 0
	.equ	se_m_thunderbolt_tbs, 1
	.equ	se_m_thunderbolt_exg, 0
	.equ	se_m_thunderbolt_cmp, 1

	.section .rodata
	.global	se_m_thunderbolt
	.align	2

@********************** Track  1 **********************@

se_m_thunderbolt_1:
	.byte	KEYSH , se_m_thunderbolt_key+0
	.byte	TEMPO , 220*se_m_thunderbolt_tbs/2
	.byte		VOICE , 18
	.byte		VOL   , 120*se_m_thunderbolt_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+32
	.byte		N06   , Dn3 , v127
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v-16
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v+32
	.byte		N06   , Dn2 , v104
	.byte	W02
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		        c_v+0
	.byte		BEND  , c_v+0
	.byte		N21   , Dn3 , v127
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-15
	.byte	W01
	.byte		BEND  , c_v-13
	.byte	W02
	.byte		PAN   , c_v-7
	.byte	W01
	.byte		BEND  , c_v-23
	.byte	W02
	.byte		VOL   , 100*se_m_thunderbolt_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-40
	.byte	W01
	.byte		VOL   , 86*se_m_thunderbolt_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-54
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		VOL   , 68*se_m_thunderbolt_mvl/mxv
	.byte	W02
	.byte		        37*se_m_thunderbolt_mvl/mxv
	.byte		BEND  , c_v-64
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		VOL   , 17*se_m_thunderbolt_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+10
	.byte	W15
	.byte	FINE

@********************** Track  2 **********************@

se_m_thunderbolt_2:
	.byte	KEYSH , se_m_thunderbolt_key+0
	.byte		VOICE , 5
	.byte		VOL   , 120*se_m_thunderbolt_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v048
	.byte	W05
	.byte		PAN   , c_v+10
	.byte		N02   , En3 , v040
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v032
	.byte	W07
	.byte		PAN   , c_v+10
	.byte		N02   , En3 , v024
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N02   , En3 , v016
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_thunderbolt:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_thunderbolt_pri	@ Priority
	.byte	se_m_thunderbolt_rev	@ Reverb.

	.word	se_m_thunderbolt_grp

	.word	se_m_thunderbolt_1
	.word	se_m_thunderbolt_2

	.end
