	.include "MPlayDef.s"

	.equ	se_m_heat_wave_grp, voicegroup_rs_sfx_2
	.equ	se_m_heat_wave_pri, 4
	.equ	se_m_heat_wave_rev, reverb_set+50
	.equ	se_m_heat_wave_mvl, 127
	.equ	se_m_heat_wave_key, 0
	.equ	se_m_heat_wave_tbs, 1
	.equ	se_m_heat_wave_exg, 0
	.equ	se_m_heat_wave_cmp, 1

	.section .rodata
	.global	se_m_heat_wave
	.align	2

@********************** Track  1 **********************@

se_m_heat_wave_1:
	.byte	KEYSH , se_m_heat_wave_key+0
	.byte	TEMPO , 150*se_m_heat_wave_tbs/2
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 23*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Fn4 , v127
	.byte	W01
	.byte		VOL   , 51*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        75*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        99*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 115*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte	W01
	.byte		VOL   , 99*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		        92*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v+7
	.byte	W01
	.byte		VOL   , 97*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		        105*se_m_heat_wave_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 110*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-9
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-24
	.byte	W03
	.byte		VOL   , 115*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-38
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-41
	.byte	W04
	.byte		        c_v-45
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		BEND  , c_v-39
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-35
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		BEND  , c_v-30
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		BEND  , c_v-26
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W05
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-18
	.byte	W04
	.byte		        c_v-13
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+6
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		PAN   , c_v-8
	.byte		VOL   , 113*se_m_heat_wave_mvl/mxv
	.byte	W04
	.byte		        110*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		BEND  , c_v-7
	.byte	W02
	.byte		VOL   , 105*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		VOL   , 98*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-11
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 91*se_m_heat_wave_mvl/mxv
	.byte	W03
	.byte		        81*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W02
	.byte		VOL   , 74*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-30
	.byte	W01
	.byte		VOL   , 50*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		        40*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 28*se_m_heat_wave_mvl/mxv
	.byte		BEND  , c_v-52
	.byte	W02
	.byte		VOL   , 17*se_m_heat_wave_mvl/mxv
	.byte	W03
	.byte		EOT
	.byte	FINE

@********************** Track  2 **********************@

se_m_heat_wave_2:
	.byte	KEYSH , se_m_heat_wave_key+0
	.byte		VOICE , 27
	.byte		PAN   , c_v+0
	.byte		VOL   , 23*se_m_heat_wave_mvl/mxv
	.byte		N30   , Gn2 , v032
	.byte	W01
	.byte		VOL   , 51*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        75*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        99*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        115*se_m_heat_wave_mvl/mxv
	.byte	W03
	.byte		        99*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		        92*se_m_heat_wave_mvl/mxv
	.byte	W01
	.byte		        97*se_m_heat_wave_mvl/mxv
	.byte	W02
	.byte		        115*se_m_heat_wave_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

se_m_heat_wave:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_heat_wave_pri	@ Priority
	.byte	se_m_heat_wave_rev	@ Reverb.

	.word	se_m_heat_wave_grp

	.word	se_m_heat_wave_1
	.word	se_m_heat_wave_2

	.end
