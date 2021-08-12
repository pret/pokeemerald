	.include "MPlayDef.s"

	.equ	se_m_sweet_scent_grp, voicegroup128
	.equ	se_m_sweet_scent_pri, 4
	.equ	se_m_sweet_scent_rev, reverb_set+50
	.equ	se_m_sweet_scent_mvl, 127
	.equ	se_m_sweet_scent_key, 0
	.equ	se_m_sweet_scent_tbs, 1
	.equ	se_m_sweet_scent_exg, 0
	.equ	se_m_sweet_scent_cmp, 1

	.section .rodata
	.global	se_m_sweet_scent
	.align	2

@********************** Track  1 **********************@

se_m_sweet_scent_1:
	.byte	KEYSH , se_m_sweet_scent_key+0
	.byte	TEMPO , 150*se_m_sweet_scent_tbs/2
	.byte		VOICE , 61
	.byte		BENDR , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_sweet_scent_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N36   , En3 , v096
	.byte	W12
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+2
	.byte	W12
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+4
	.byte	W12
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+5
	.byte		N36   , Fn3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+6
	.byte	W12
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+7
	.byte	W12
	.byte		PAN   , c_v+9
	.byte		BEND  , c_v+8
	.byte		N36   , En3 , v088
	.byte	W12
	.byte		PAN   , c_v+5
	.byte		BEND  , c_v+8
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+9
	.byte	W12
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+10
	.byte		N60   , Fs3 , v056
	.byte	W12
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+11
	.byte	W12
	.byte		PAN   , c_v-4
	.byte		BEND  , c_v+12
	.byte	W04
	.byte		VOL   , 103*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		        97*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		VOL   , 91*se_m_sweet_scent_mvl/mxv
	.byte	W05
	.byte		        81*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        72*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+13
	.byte	W01
	.byte		VOL   , 62*se_m_sweet_scent_mvl/mxv
	.byte	W02
	.byte		        51*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        39*se_m_sweet_scent_mvl/mxv
	.byte	W02
	.byte		        24*se_m_sweet_scent_mvl/mxv
	.byte	W02
	.byte		        12*se_m_sweet_scent_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_sweet_scent_2:
	.byte	KEYSH , se_m_sweet_scent_key+0
	.byte		VOICE , 22
	.byte		BENDR , 44
	.byte		PAN   , c_v+1
	.byte		VOL   , 38*se_m_sweet_scent_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		TIE   , Gn3 , v100
	.byte	W03
	.byte		VOL   , 50*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		        62*se_m_sweet_scent_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-1
	.byte	W01
	.byte		VOL   , 65*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		        74*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		        78*se_m_sweet_scent_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		VOL   , 86*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        95*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        105*se_m_sweet_scent_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		VOL   , 110*se_m_sweet_scent_mvl/mxv
	.byte	W13
	.byte		BEND  , c_v-2
	.byte	W04
	.byte	W10
	.byte		        c_v-1
	.byte	W10
	.byte		        c_v+0
	.byte	W04
	.byte	W03
	.byte		        c_v+1
	.byte	W10
	.byte		        c_v+1
	.byte	W11
	.byte	W02
	.byte		        c_v+2
	.byte	W14
	.byte		        c_v+3
	.byte	W08
	.byte		VOL   , 105*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        101*se_m_sweet_scent_mvl/mxv
	.byte	W05
	.byte		        96*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v+2
	.byte	W01
	.byte		VOL   , 91*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        86*se_m_sweet_scent_mvl/mxv
	.byte	W05
	.byte		        78*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte	W02
	.byte		        68*se_m_sweet_scent_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+1
	.byte	W04
	.byte		VOL   , 58*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		        48*se_m_sweet_scent_mvl/mxv
	.byte	W04
	.byte		        37*se_m_sweet_scent_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		VOL   , 23*se_m_sweet_scent_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-1
	.byte	W02
	.byte		VOL   , 12*se_m_sweet_scent_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	FINE

@******************************************************@
	.align	2

se_m_sweet_scent:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_sweet_scent_pri	@ Priority
	.byte	se_m_sweet_scent_rev	@ Reverb.

	.word	se_m_sweet_scent_grp

	.word	se_m_sweet_scent_1
	.word	se_m_sweet_scent_2

	.end
