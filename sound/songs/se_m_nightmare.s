	.include "MPlayDef.s"

	.equ	se_m_nightmare_grp, voicegroup128
	.equ	se_m_nightmare_pri, 4
	.equ	se_m_nightmare_rev, reverb_set+50
	.equ	se_m_nightmare_mvl, 127
	.equ	se_m_nightmare_key, 0
	.equ	se_m_nightmare_tbs, 1
	.equ	se_m_nightmare_exg, 0
	.equ	se_m_nightmare_cmp, 1

	.section .rodata
	.global	se_m_nightmare
	.align	2

@********************** Track  1 **********************@

se_m_nightmare_1:
	.byte	KEYSH , se_m_nightmare_key+0
	.byte	TEMPO , 220*se_m_nightmare_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 110*se_m_nightmare_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Gn2 , v092
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Gn2 , v088
	.byte	W09
	.byte		PAN   , c_v-1
	.byte		N03   , Fs3 , v104
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , Fs3 , v088
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Ds3
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03
	.byte	W09
	.byte		PAN   , c_v-1
	.byte		N03   , An2 , v096
	.byte	W06
	.byte		PAN   , c_v+17
	.byte		N03   , An2 , v088
	.byte	W09
	.byte		PAN   , c_v-1
	.byte		N03   , Gs3 , v104
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N03   , Gs3 , v088
	.byte	W03
	.byte	W03
	.byte		PAN   , c_v-1
	.byte		N03   , Fn3
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N03
	.byte	W15
	.byte	FINE

@********************** Track  2 **********************@

se_m_nightmare_2:
	.byte	KEYSH , se_m_nightmare_key+0
	.byte		VOICE , 20
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 110*se_m_nightmare_mvl/mxv
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+55
	.byte		N03   , Cn2 , v100
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+36
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+17
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+2
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-8
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+12
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v+6
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+0
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-6
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-19
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-31
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-44
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		BEND  , c_v-55
	.byte		N03
	.byte	W06
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-64
	.byte		N03
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_m_nightmare:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_nightmare_pri	@ Priority
	.byte	se_m_nightmare_rev	@ Reverb.

	.word	se_m_nightmare_grp

	.word	se_m_nightmare_1
	.word	se_m_nightmare_2

	.end
