	.include "MPlayDef.s"

	.equ	se_m_attract_grp, voicegroup_rs_sfx_2
	.equ	se_m_attract_pri, 4
	.equ	se_m_attract_rev, reverb_set+50
	.equ	se_m_attract_mvl, 127
	.equ	se_m_attract_key, 0
	.equ	se_m_attract_tbs, 1
	.equ	se_m_attract_exg, 0
	.equ	se_m_attract_cmp, 1

	.section .rodata
	.global	se_m_attract
	.align	2

@********************** Track  1 **********************@

se_m_attract_1:
	.byte	KEYSH , se_m_attract_key+0
	.byte	TEMPO , 210*se_m_attract_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 95*se_m_attract_mvl/mxv
	.byte		BENDR , 2
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte	W03
	.byte		N06   , Cn6 , v116
	.byte	W03
	.byte	W03
	.byte		        En6 , v108
	.byte	W03
	.byte	W03
	.byte		        Cs5 , v100
	.byte	W03
	.byte	W03
	.byte		        Gs5 , v088
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , Cs6 , v080
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , Dn6 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+4
	.byte		N06   , Fs6 , v060
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N06   , Ds5 , v052
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-4
	.byte		N06   , As5 , v040
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+0
	.byte	W03
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte	W03
	.byte		        c_v+0
	.byte	FINE

@********************** Track  2 **********************@

se_m_attract_2:
	.byte	KEYSH , se_m_attract_key+0
	.byte		VOICE , 53
	.byte		BENDR , 2
	.byte		VOL   , 43*se_m_attract_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+15
	.byte		N06   , Cn5 , v120
	.byte	W03
	.byte	W03
	.byte		        Gn5 , v112
	.byte	W03
	.byte	W03
	.byte		        Cn6 , v104
	.byte	W03
	.byte	W03
	.byte		        Cs6 , v092
	.byte	W03
	.byte	W03
	.byte		        Fn6 , v084
	.byte	W03
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte	W03
	.byte		        An5 , v064
	.byte	W03
	.byte	W03
	.byte		        Dn6 , v056
	.byte	W03
	.byte	W03
	.byte		        Ds6 , v048
	.byte	W03
	.byte	W03
	.byte		        Gn6 , v036
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_attract:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_attract_pri	@ Priority
	.byte	se_m_attract_rev	@ Reverb.

	.word	se_m_attract_grp

	.word	se_m_attract_1
	.word	se_m_attract_2

	.end
