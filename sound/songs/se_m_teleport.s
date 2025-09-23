	.include "MPlayDef.s"

	.equ	se_m_teleport_grp, voicegroup_rs_sfx_2
	.equ	se_m_teleport_pri, 4
	.equ	se_m_teleport_rev, reverb_set+50
	.equ	se_m_teleport_mvl, 127
	.equ	se_m_teleport_key, 0
	.equ	se_m_teleport_tbs, 1
	.equ	se_m_teleport_exg, 0
	.equ	se_m_teleport_cmp, 1

	.section .rodata
	.global	se_m_teleport
	.align	2

@********************** Track  1 **********************@

se_m_teleport_1:
	.byte	KEYSH , se_m_teleport_key+0
	.byte	TEMPO , 150*se_m_teleport_tbs/2
	.byte		VOICE , 45
	.byte		BENDR , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 32*se_m_teleport_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+0
	.byte		N06   , Cn3 , v127
	.byte	W01
	.byte		BEND  , c_v+4
	.byte	W01
	.byte		VOL   , 49*se_m_teleport_mvl/mxv
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		        c_v+16
	.byte	W01
	.byte		VOL   , 61*se_m_teleport_mvl/mxv
	.byte		BEND  , c_v+24
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+2
	.byte		N06   , Dn3 , v116
	.byte	W01
	.byte		VOL   , 71*se_m_teleport_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W01
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		VOL   , 81*se_m_teleport_mvl/mxv
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		        c_v+27
	.byte	W02
	.byte		VOL   , 95*se_m_teleport_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+4
	.byte		N06   , En3 , v112
	.byte	W01
	.byte		BEND  , c_v+9
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+29
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+6
	.byte		N06   , Fn3
	.byte	W01
	.byte		BEND  , c_v+11
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+15
	.byte	W01
	.byte		        c_v+22
	.byte	W01
	.byte		        c_v+31
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte		N06   , Gn3 , v108
	.byte	W01
	.byte		BEND  , c_v+14
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		        c_v+25
	.byte	W01
	.byte		        c_v+34
	.byte	W02
	.byte		VOL   , 82*se_m_teleport_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte		N06   , An3 , v100
	.byte	W01
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		VOL   , 71*se_m_teleport_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		VOL   , 61*se_m_teleport_mvl/mxv
	.byte		BEND  , c_v+38
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte		N06   , Bn3 , v060
	.byte	W01
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+38
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte		N06   , Cn4 , v040
	.byte	W01
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+38
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+14
	.byte		N06   , Dn4 , v020
	.byte	W01
	.byte		BEND  , c_v+18
	.byte	W01
	.byte		PAN   , c_v+8
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		        c_v+38
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_teleport:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_teleport_pri	@ Priority
	.byte	se_m_teleport_rev	@ Reverb.

	.word	se_m_teleport_grp

	.word	se_m_teleport_1

	.end
