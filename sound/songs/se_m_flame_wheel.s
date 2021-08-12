	.include "MPlayDef.s"

	.equ	se_m_flame_wheel_grp, voicegroup128
	.equ	se_m_flame_wheel_pri, 4
	.equ	se_m_flame_wheel_rev, reverb_set+50
	.equ	se_m_flame_wheel_mvl, 127
	.equ	se_m_flame_wheel_key, 0
	.equ	se_m_flame_wheel_tbs, 1
	.equ	se_m_flame_wheel_exg, 0
	.equ	se_m_flame_wheel_cmp, 1

	.section .rodata
	.global	se_m_flame_wheel
	.align	2

@********************** Track  1 **********************@

se_m_flame_wheel_1:
	.byte	KEYSH , se_m_flame_wheel_key+0
	.byte	TEMPO , 150*se_m_flame_wheel_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 22*se_m_flame_wheel_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N30   , Dn4 , v127
	.byte	W01
	.byte		VOL   , 49*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        71*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        95*se_m_flame_wheel_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 110*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOL   , 95*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        88*se_m_flame_wheel_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+7
	.byte	W01
	.byte		VOL   , 93*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        110*se_m_flame_wheel_mvl/mxv
	.byte		PAN   , c_v-5
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 86*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-9
	.byte	W01
	.byte		VOL   , 63*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        37*se_m_flame_wheel_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		VOL   , 13*se_m_flame_wheel_mvl/mxv
	.byte		BEND  , c_v-46
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_flame_wheel_2:
	.byte	KEYSH , se_m_flame_wheel_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 22*se_m_flame_wheel_mvl/mxv
	.byte		N30   , Gn2 , v032
	.byte	W01
	.byte		VOL   , 49*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        71*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        95*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        110*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte	W01
	.byte		        95*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        88*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte		        93*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        110*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        86*se_m_flame_wheel_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        63*se_m_flame_wheel_mvl/mxv
	.byte	W02
	.byte		        37*se_m_flame_wheel_mvl/mxv
	.byte	W03
	.byte		        13*se_m_flame_wheel_mvl/mxv
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_flame_wheel:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_flame_wheel_pri	@ Priority
	.byte	se_m_flame_wheel_rev	@ Reverb.

	.word	se_m_flame_wheel_grp

	.word	se_m_flame_wheel_1
	.word	se_m_flame_wheel_2

	.end
