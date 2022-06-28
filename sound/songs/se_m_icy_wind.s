	.include "MPlayDef.s"

	.equ	se_m_icy_wind_grp, voicegroup128
	.equ	se_m_icy_wind_pri, 4
	.equ	se_m_icy_wind_rev, 0
	.equ	se_m_icy_wind_mvl, 127
	.equ	se_m_icy_wind_key, 0
	.equ	se_m_icy_wind_tbs, 1
	.equ	se_m_icy_wind_exg, 0
	.equ	se_m_icy_wind_cmp, 1

	.section .rodata
	.global	se_m_icy_wind
	.align	2

@********************** Track  1 **********************@

se_m_icy_wind_1:
	.byte	KEYSH , se_m_icy_wind_key+0
	.byte	TEMPO , 150*se_m_icy_wind_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 100*se_m_icy_wind_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Ds4 , v112
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		N01   , Bn4 , v040
	.byte	W04
	.byte		PAN   , c_v-5
	.byte		N01   , Ds4 , v112
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Bn4
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_icy_wind_2:
	.byte	KEYSH , se_m_icy_wind_key+0
	.byte		VOICE , 5
	.byte		VOL   , 100*se_m_icy_wind_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Dn4 , v040
	.byte	W04
	.byte		        Bn3
	.byte	W02
	.byte		PAN   , c_v-7
	.byte	W02
	.byte		        c_v+9
	.byte	W01
	.byte		N01   , Dn4
	.byte	W01
	.byte		PAN   , c_v-7
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_m_icy_wind:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_icy_wind_pri	@ Priority
	.byte	se_m_icy_wind_rev	@ Reverb.

	.word	se_m_icy_wind_grp

	.word	se_m_icy_wind_1
	.word	se_m_icy_wind_2

	.end
