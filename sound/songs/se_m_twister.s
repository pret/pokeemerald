	.include "MPlayDef.s"

	.equ	se_m_twister_grp, voicegroup128
	.equ	se_m_twister_pri, 4
	.equ	se_m_twister_rev, reverb_set+50
	.equ	se_m_twister_mvl, 127
	.equ	se_m_twister_key, 0
	.equ	se_m_twister_tbs, 1
	.equ	se_m_twister_exg, 0
	.equ	se_m_twister_cmp, 1

	.section .rodata
	.global	se_m_twister
	.align	2

@********************** Track  1 **********************@

se_m_twister_1:
	.byte	KEYSH , se_m_twister_key+0
	.byte	TEMPO , 150*se_m_twister_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 67*se_m_twister_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Dn2 , v127
	.byte	W03
	.byte		VOL   , 83*se_m_twister_mvl/mxv
	.byte		BEND  , c_v+22
	.byte	W03
	.byte		VOL   , 88*se_m_twister_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W03
	.byte		VOL   , 95*se_m_twister_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+8
	.byte	W01
	.byte		VOL   , 105*se_m_twister_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		VOL   , 115*se_m_twister_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		PAN   , c_v-12
	.byte	W06
	.byte		        c_v-17
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v-7
	.byte	W03
	.byte		PAN   , c_v-9
	.byte	W06
	.byte		        c_v-3
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W03
	.byte		        c_v+10
	.byte	W06
	.byte		        c_v+16
	.byte	W01
	.byte		BEND  , c_v-20
	.byte	W05
	.byte		PAN   , c_v+13
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte	W01
	.byte		BEND  , c_v-13
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte	W03
	.byte		        c_v-17
	.byte	W01
	.byte		BEND  , c_v-6
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W06
	.byte		        c_v-3
	.byte	W03
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+10
	.byte	W01
	.byte		BEND  , c_v+6
	.byte	W05
	.byte		PAN   , c_v+16
	.byte	W06
	.byte		        c_v+13
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		        c_v-11
	.byte		VOL   , 103*se_m_twister_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-17
	.byte	W01
	.byte		BEND  , c_v+20
	.byte	W05
	.byte		PAN   , c_v-9
	.byte	W01
	.byte		VOL   , 97*se_m_twister_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v-3
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+6
	.byte		VOL   , 88*se_m_twister_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W02
	.byte		BEND  , c_v+7
	.byte	W02
	.byte		VOL   , 79*se_m_twister_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W04
	.byte		VOL   , 62*se_m_twister_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		PAN   , c_v+13
	.byte	W04
	.byte		VOL   , 45*se_m_twister_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		BEND  , c_v-7
	.byte	W01
	.byte		VOL   , 33*se_m_twister_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		        c_v-8
	.byte	W01
	.byte		VOL   , 18*se_m_twister_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-11
	.byte	W03
	.byte		EOT   
	.byte	FINE

@********************** Track  2 **********************@

se_m_twister_2:
	.byte	KEYSH , se_m_twister_key+0
	.byte		VOICE , 25
	.byte		VOL   , 67*se_m_twister_mvl/mxv
	.byte		TIE   , Gs4 , v012
	.byte	W03
	.byte		VOL   , 83*se_m_twister_mvl/mxv
	.byte	W03
	.byte		        88*se_m_twister_mvl/mxv
	.byte	W03
	.byte		        95*se_m_twister_mvl/mxv
	.byte	W03
	.byte		        105*se_m_twister_mvl/mxv
	.byte	W03
	.byte		        115*se_m_twister_mvl/mxv
	.byte	W09
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W21
	.byte		        103*se_m_twister_mvl/mxv
	.byte	W03
	.byte	W07
	.byte		        97*se_m_twister_mvl/mxv
	.byte	W08
	.byte		        88*se_m_twister_mvl/mxv
	.byte	W07
	.byte		        79*se_m_twister_mvl/mxv
	.byte	W02
	.byte	W04
	.byte		        62*se_m_twister_mvl/mxv
	.byte	W06
	.byte		        45*se_m_twister_mvl/mxv
	.byte	W04
	.byte		        33*se_m_twister_mvl/mxv
	.byte	W05
	.byte		        18*se_m_twister_mvl/mxv
	.byte	W05
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_m_twister:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_twister_pri	@ Priority
	.byte	se_m_twister_rev	@ Reverb.

	.word	se_m_twister_grp

	.word	se_m_twister_1
	.word	se_m_twister_2

	.end
