	.include "MPlayDef.s"

	.equ	se_m_flame_wheel2_grp, voicegroup128
	.equ	se_m_flame_wheel2_pri, 4
	.equ	se_m_flame_wheel2_rev, 0
	.equ	se_m_flame_wheel2_mvl, 127
	.equ	se_m_flame_wheel2_key, 0
	.equ	se_m_flame_wheel2_tbs, 1
	.equ	se_m_flame_wheel2_exg, 0
	.equ	se_m_flame_wheel2_cmp, 1

	.section .rodata
	.global	se_m_flame_wheel2
	.align	2

@********************** Track  1 **********************@

se_m_flame_wheel2_1:
	.byte	KEYSH , se_m_flame_wheel2_key+0
	.byte	TEMPO , 150*se_m_flame_wheel2_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_flame_wheel2_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Cn4 , v127
	.byte	W06
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W03
	.byte		BEND  , c_v+5
	.byte	W03
	.byte		VOL   , 98*se_m_flame_wheel2_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W03
	.byte		VOL   , 88*se_m_flame_wheel2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		VOL   , 68*se_m_flame_wheel2_mvl/mxv
	.byte		PAN   , c_v-5
	.byte	W03
	.byte		        c_v+7
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		VOL   , 44*se_m_flame_wheel2_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		VOL   , 13*se_m_flame_wheel2_mvl/mxv
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		        c_v-40
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_flame_wheel2_2:
	.byte	KEYSH , se_m_flame_wheel2_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_flame_wheel2_mvl/mxv
	.byte		N48   , Gn2 , v032
	.byte	W18
	.byte		VOL   , 98*se_m_flame_wheel2_mvl/mxv
	.byte	W06
	.byte		        88*se_m_flame_wheel2_mvl/mxv
	.byte	W06
	.byte		        68*se_m_flame_wheel2_mvl/mxv
	.byte	W06
	.byte		        44*se_m_flame_wheel2_mvl/mxv
	.byte	W06
	.byte		        13*se_m_flame_wheel2_mvl/mxv
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_flame_wheel2:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_flame_wheel2_pri	@ Priority
	.byte	se_m_flame_wheel2_rev	@ Reverb.

	.word	se_m_flame_wheel2_grp

	.word	se_m_flame_wheel2_1
	.word	se_m_flame_wheel2_2

	.end
