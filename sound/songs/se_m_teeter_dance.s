	.include "MPlayDef.s"

	.equ	se_m_teeter_dance_grp, voicegroup128
	.equ	se_m_teeter_dance_pri, 4
	.equ	se_m_teeter_dance_rev, reverb_set+50
	.equ	se_m_teeter_dance_mvl, 127
	.equ	se_m_teeter_dance_key, 0
	.equ	se_m_teeter_dance_tbs, 1
	.equ	se_m_teeter_dance_exg, 0
	.equ	se_m_teeter_dance_cmp, 1

	.section .rodata
	.global	se_m_teeter_dance
	.align	2

@********************** Track  1 **********************@

se_m_teeter_dance_1:
	.byte	KEYSH , se_m_teeter_dance_key+0
	.byte	TEMPO , 170*se_m_teeter_dance_tbs/2
	.byte		VOICE , 37
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_teeter_dance_mvl/mxv
	.byte		BEND  , c_v-4
	.byte		N03   , Gn4 , v100
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Gn4 , v056
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , An5 , v100
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-15
	.byte		N03   , An5 , v056
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Cn6 , v100
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , Cn6 , v056
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Gn4 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Gn4 , v028
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , An5 , v072
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03   , An5 , v028
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Cn6 , v072
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Cn6 , v028
	.byte	W03
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_m_teeter_dance_2:
	.byte	KEYSH , se_m_teeter_dance_key+0
	.byte		VOICE , 47
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		MOD   , 20
	.byte		VOL   , 44*se_m_teeter_dance_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte	W03
	.byte		        Gn3 , v068
	.byte	W03
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v068
	.byte	W03
	.byte		        Cn5 , v112
	.byte	W03
	.byte	W03
	.byte		        Cn5 , v068
	.byte	W03
	.byte		        Gn3 , v080
	.byte	W06
	.byte		        Gn3 , v036
	.byte	W03
	.byte		        An4 , v080
	.byte	W03
	.byte	W03
	.byte		        An4 , v036
	.byte	W03
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v036
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_teeter_dance:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_teeter_dance_pri	@ Priority
	.byte	se_m_teeter_dance_rev	@ Reverb.

	.word	se_m_teeter_dance_grp

	.word	se_m_teeter_dance_1
	.word	se_m_teeter_dance_2

	.end
