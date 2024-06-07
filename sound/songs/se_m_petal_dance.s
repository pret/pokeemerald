	.include "MPlayDef.s"

	.equ	se_m_petal_dance_grp, voicegroup128
	.equ	se_m_petal_dance_pri, 4
	.equ	se_m_petal_dance_rev, 0
	.equ	se_m_petal_dance_mvl, 127
	.equ	se_m_petal_dance_key, 0
	.equ	se_m_petal_dance_tbs, 1
	.equ	se_m_petal_dance_exg, 0
	.equ	se_m_petal_dance_cmp, 1

	.section .rodata
	.global	se_m_petal_dance
	.align	2

@********************** Track  1 **********************@

se_m_petal_dance_1:
	.byte	KEYSH , se_m_petal_dance_key+0
	.byte	TEMPO , 150*se_m_petal_dance_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 95*se_m_petal_dance_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte	W03
	.byte		N06   , Dn6 , v112
	.byte	W03
	.byte	W03
	.byte		        An5 , v104
	.byte	W03
	.byte	W03
	.byte		        Dn6 , v100
	.byte	W03
	.byte	W03
	.byte		        An5
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v096
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v092
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6 , v088
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v084
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v080
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v076
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Dn6 , v068
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v064
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Dn6 , v060
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v056
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		N06   , Dn6 , v052
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v048
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+8
	.byte		N06   , Dn6 , v044
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v040
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		N06   , Dn6 , v036
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , An5 , v032
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_petal_dance_2:
	.byte	KEYSH , se_m_petal_dance_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_m_petal_dance_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , En6 , v108
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v104
	.byte	W03
	.byte	W03
	.byte		        En6 , v100
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v096
	.byte	W03
	.byte	W03
	.byte		        En6 , v092
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v088
	.byte	W03
	.byte	W03
	.byte		        En6
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v084
	.byte	W03
	.byte	W03
	.byte		        En6 , v080
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v076
	.byte	W03
	.byte	W03
	.byte		        En6 , v072
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v068
	.byte	W03
	.byte	W03
	.byte		        En6 , v064
	.byte	W03
	.byte	W03
	.byte		        Bn5
	.byte	W03
	.byte	W03
	.byte		        En6 , v060
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v056
	.byte	W03
	.byte	W03
	.byte		        En6 , v052
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v048
	.byte	W03
	.byte	W03
	.byte		        En6 , v044
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v040
	.byte	W03
	.byte	W03
	.byte		        En6 , v036
	.byte	W03
	.byte	W03
	.byte		        Bn5 , v032
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_petal_dance:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_petal_dance_pri	@ Priority
	.byte	se_m_petal_dance_rev	@ Reverb.

	.word	se_m_petal_dance_grp

	.word	se_m_petal_dance_1
	.word	se_m_petal_dance_2

	.end
