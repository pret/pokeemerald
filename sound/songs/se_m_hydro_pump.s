	.include "MPlayDef.s"

	.equ	se_m_hydro_pump_grp, voicegroup128
	.equ	se_m_hydro_pump_pri, 4
	.equ	se_m_hydro_pump_rev, reverb_set+50
	.equ	se_m_hydro_pump_mvl, 127
	.equ	se_m_hydro_pump_key, 0
	.equ	se_m_hydro_pump_tbs, 1
	.equ	se_m_hydro_pump_exg, 0
	.equ	se_m_hydro_pump_cmp, 1

	.section .rodata
	.global	se_m_hydro_pump
	.align	2

@********************** Track  1 **********************@

se_m_hydro_pump_1:
	.byte	KEYSH , se_m_hydro_pump_key+0
	.byte	TEMPO , 150*se_m_hydro_pump_tbs/2
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 115*se_m_hydro_pump_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn2 , v127
	.byte	W06
	.byte		PAN   , c_v-4
	.byte	W06
	.byte		        c_v-10
	.byte	W06
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+11
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-4
	.byte	W06
	.byte		        c_v-10
	.byte	W06
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+4
	.byte	W06
	.byte		        c_v+11
	.byte	W02
	.byte		VOL   , 103*se_m_hydro_pump_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		VOL   , 85*se_m_hydro_pump_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 71*se_m_hydro_pump_mvl/mxv
	.byte	W05
	.byte		        52*se_m_hydro_pump_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W04
	.byte		VOL   , 32*se_m_hydro_pump_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		VOL   , 11*se_m_hydro_pump_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-5
	.byte	W01
	.byte		VOL   , 6*se_m_hydro_pump_mvl/mxv
	.byte	W05
	.byte		EOT
	.byte	FINE

@********************** Track  2 **********************@

se_m_hydro_pump_2:
	.byte	KEYSH , se_m_hydro_pump_key+0
	.byte		VOL   , 58*se_m_hydro_pump_mvl/mxv
	.byte		N14   , Gn3 , v080
	.byte	W01
	.byte		VOICE , 25
	.byte		VOL   , 76*se_m_hydro_pump_mvl/mxv
	.byte	W01
	.byte		        89*se_m_hydro_pump_mvl/mxv
	.byte	W01
	.byte		        100*se_m_hydro_pump_mvl/mxv
	.byte	W01
	.byte		        115*se_m_hydro_pump_mvl/mxv
	.byte	W06
	.byte		        90*se_m_hydro_pump_mvl/mxv
	.byte	W02
	.byte		        76*se_m_hydro_pump_mvl/mxv
	.byte	W01
	.byte		        58*se_m_hydro_pump_mvl/mxv
	.byte	W11
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_hydro_pump:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_hydro_pump_pri	@ Priority
	.byte	se_m_hydro_pump_rev	@ Reverb.

	.word	se_m_hydro_pump_grp

	.word	se_m_hydro_pump_1
	.word	se_m_hydro_pump_2

	.end
