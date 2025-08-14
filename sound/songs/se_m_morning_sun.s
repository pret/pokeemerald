	.include "MPlayDef.s"

	.equ	se_m_morning_sun_grp, voicegroup_rs_sfx_2
	.equ	se_m_morning_sun_pri, 5
	.equ	se_m_morning_sun_rev, reverb_set+50
	.equ	se_m_morning_sun_mvl, 127
	.equ	se_m_morning_sun_key, 0
	.equ	se_m_morning_sun_tbs, 1
	.equ	se_m_morning_sun_exg, 0
	.equ	se_m_morning_sun_cmp, 1

	.section .rodata
	.global	se_m_morning_sun
	.align	2

@********************** Track  1 **********************@

se_m_morning_sun_1:
	.byte	KEYSH , se_m_morning_sun_key+0
	.byte	TEMPO , 150*se_m_morning_sun_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 95*se_m_morning_sun_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte	W03
	.byte		N06   , Ds6 , v112
	.byte	W03
	.byte	W03
	.byte		        En5 , v104
	.byte	W03
	.byte	W03
	.byte		        Ds6 , v096
	.byte	W03
	.byte	W03
	.byte		        En5 , v088
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Ds6 , v080
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , En5 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Ds6 , v064
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , En5 , v056
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Ds6 , v044
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , En5 , v036
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Ds6 , v028
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , En5 , v020
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_morning_sun_2:
	.byte	KEYSH , se_m_morning_sun_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_m_morning_sun_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , Gs6 , v108
	.byte	W03
	.byte	W03
	.byte		        Bn5
	.byte	W03
	.byte	W03
	.byte		        Gs6 , v100
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v092
	.byte	W03
	.byte	W03
	.byte		        Gs6 , v084
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v076
	.byte	W03
	.byte	W03
	.byte		        Gs6 , v068
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v060
	.byte	W03
	.byte	W03
	.byte		        Gs6 , v052
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v040
	.byte	W03
	.byte	W03
	.byte		        Gs6 , v032
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v024
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_morning_sun:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_morning_sun_pri	@ Priority
	.byte	se_m_morning_sun_rev	@ Reverb.

	.word	se_m_morning_sun_grp

	.word	se_m_morning_sun_1
	.word	se_m_morning_sun_2

	.end
