	.include "MPlayDef.s"

	.equ	se_m_minimize_grp, voicegroup128
	.equ	se_m_minimize_pri, 4
	.equ	se_m_minimize_rev, reverb_set+50
	.equ	se_m_minimize_mvl, 127
	.equ	se_m_minimize_key, 0
	.equ	se_m_minimize_tbs, 1
	.equ	se_m_minimize_exg, 0
	.equ	se_m_minimize_cmp, 1

	.section .rodata
	.global	se_m_minimize
	.align	2

@********************** Track  1 **********************@

se_m_minimize_1:
	.byte	KEYSH , se_m_minimize_key+0
	.byte	TEMPO , 150*se_m_minimize_tbs/2
	.byte		VOICE , 45
	.byte		BENDR , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*se_m_minimize_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+39
	.byte		N06   , Dn4 , v127
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		VOL   , 49*se_m_minimize_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+15
	.byte	W01
	.byte		VOL   , 61*se_m_minimize_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+35
	.byte		N06   , Cn4 , v116
	.byte	W01
	.byte		VOL   , 71*se_m_minimize_mvl/mxv
	.byte		BEND  , c_v+27
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+19
	.byte	W01
	.byte		VOL   , 81*se_m_minimize_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		        c_v+5
	.byte	W02
	.byte		VOL   , 95*se_m_minimize_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+32
	.byte		N06   , Bn3 , v112
	.byte	W01
	.byte		BEND  , c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		        c_v+8
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+28
	.byte		N06   , An3 
	.byte	W01
	.byte		BEND  , c_v+20
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v-2
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+24
	.byte		N06   , Gn3 , v108
	.byte	W01
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		        c_v+1
	.byte	W01
	.byte		        c_v-6
	.byte	W02
	.byte		VOL   , 82*se_m_minimize_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+21
	.byte		N06   , Fn3 , v100
	.byte	W01
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 71*se_m_minimize_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v-2
	.byte	W01
	.byte		VOL   , 61*se_m_minimize_mvl/mxv
	.byte		BEND  , c_v-10
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+17
	.byte		N06   , En3 , v060
	.byte	W01
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-13
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte		N06   , Dn3 , v040
	.byte	W01
	.byte		BEND  , c_v+6
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		        c_v-10
	.byte	W01
	.byte		        c_v-17
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+12
	.byte		N06   , Cn3 , v020
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-18
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_minimize:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_minimize_pri	@ Priority
	.byte	se_m_minimize_rev	@ Reverb.

	.word	se_m_minimize_grp

	.word	se_m_minimize_1

	.end
