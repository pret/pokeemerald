	.include "MPlayDef.s"

	.equ	se_m_haze_grp, voicegroup_rs_sfx_2
	.equ	se_m_haze_pri, 4
	.equ	se_m_haze_rev, reverb_set+50
	.equ	se_m_haze_mvl, 127
	.equ	se_m_haze_key, 0
	.equ	se_m_haze_tbs, 1
	.equ	se_m_haze_exg, 0
	.equ	se_m_haze_cmp, 1

	.section .rodata
	.global	se_m_haze
	.align	2

@********************** Track  1 **********************@

se_m_haze_1:
	.byte	KEYSH , se_m_haze_key+0
	.byte	TEMPO , 190*se_m_haze_tbs/2
	.byte		VOICE , 45
	.byte		BENDR , 8
	.byte		PAN   , c_v-47
	.byte		VOL   , 10*se_m_haze_mvl/mxv
	.byte		MOD   , 30
	.byte		BEND  , c_v+1
	.byte		TIE   , As2 , v100
	.byte	W03
	.byte		VOL   , 14*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        22*se_m_haze_mvl/mxv
	.byte		PAN   , c_v-45
	.byte	W02
	.byte		VOL   , 31*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        39*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-43
	.byte	W02
	.byte		VOL   , 45*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        50*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-41
	.byte	W01
	.byte		VOL   , 61*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        66*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-39
	.byte		VOL   , 73*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        78*se_m_haze_mvl/mxv
	.byte	W04
	.byte		        84*se_m_haze_mvl/mxv
	.byte		PAN   , c_v-37
	.byte	W03
	.byte		VOL   , 91*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        98*se_m_haze_mvl/mxv
	.byte		PAN   , c_v-35
	.byte	W02
	.byte		VOL   , 104*se_m_haze_mvl/mxv
	.byte	W04
	.byte		        110*se_m_haze_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W06
	.byte		        c_v-28
	.byte	W06
	.byte		        c_v-25
	.byte		VOL   , 106*se_m_haze_mvl/mxv
	.byte	W04
	.byte		        104*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-23
	.byte	W03
	.byte		VOL   , 101*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-20
	.byte	W03
	.byte		VOL   , 97*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-17
	.byte	W02
	.byte		VOL   , 91*se_m_haze_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-13
	.byte	W03
	.byte		VOL   , 88*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		VOL   , 81*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-7
	.byte	W04
	.byte		VOL   , 75*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-3
	.byte	W02
	.byte		VOL   , 74*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        76*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+0
	.byte	W01
	.byte		VOL   , 79*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        83*se_m_haze_mvl/mxv
	.byte	W03
	.byte	W01
	.byte		        86*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+2
	.byte		VOL   , 90*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        95*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        98*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		VOL   , 102*se_m_haze_mvl/mxv
	.byte	W02
	.byte		        104*se_m_haze_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+10
	.byte		VOL   , 110*se_m_haze_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+14
	.byte	W06
	.byte		        c_v+16
	.byte	W02
	.byte		VOL   , 106*se_m_haze_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+19
	.byte	W01
	.byte		VOL   , 100*se_m_haze_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+22
	.byte		VOL   , 94*se_m_haze_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+25
	.byte		VOL   , 88*se_m_haze_mvl/mxv
	.byte	W04
	.byte		        83*se_m_haze_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v+27
	.byte	W06
	.byte		        c_v+29
	.byte		VOL   , 75*se_m_haze_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 64*se_m_haze_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+34
	.byte	W01
	.byte		VOL   , 55*se_m_haze_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+38
	.byte	W01
	.byte		VOL   , 47*se_m_haze_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+41
	.byte	W01
	.byte		VOL   , 41*se_m_haze_mvl/mxv
	.byte	W05
	.byte		PAN   , c_v+44
	.byte		VOL   , 32*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        25*se_m_haze_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+47
	.byte	W01
	.byte		VOL   , 12*se_m_haze_mvl/mxv
	.byte	W03
	.byte		        6*se_m_haze_mvl/mxv
	.byte	W02
	.byte		EOT
	.byte	FINE

@********************** Track  2 **********************@

se_m_haze_2:
	.byte	KEYSH , se_m_haze_key+0
	.byte		VOICE , 70
	.byte		BENDR , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_haze_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Fn4 , v020
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Gs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Gn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Fs4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        Fn4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		        En4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte		N18   , Ds4
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_haze:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_haze_pri	@ Priority
	.byte	se_m_haze_rev	@ Reverb.

	.word	se_m_haze_grp

	.word	se_m_haze_1
	.word	se_m_haze_2

	.end
