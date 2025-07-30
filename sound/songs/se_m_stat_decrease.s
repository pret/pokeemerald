	.include "MPlayDef.s"

	.equ	se_m_stat_decrease_grp, voicegroup_rs_sfx_2
	.equ	se_m_stat_decrease_pri, 4
	.equ	se_m_stat_decrease_rev, reverb_set+50
	.equ	se_m_stat_decrease_mvl, 127
	.equ	se_m_stat_decrease_key, 0
	.equ	se_m_stat_decrease_tbs, 1
	.equ	se_m_stat_decrease_exg, 0
	.equ	se_m_stat_decrease_cmp, 1

	.section .rodata
	.global	se_m_stat_decrease
	.align	2

@********************** Track  1 **********************@

se_m_stat_decrease_1:
	.byte	KEYSH , se_m_stat_decrease_key+0
	.byte	TEMPO , 170*se_m_stat_decrease_tbs/2
	.byte		VOICE , 67
	.byte		VOL   , 70*se_m_stat_decrease_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , Cs6 , v076
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte		N02   , Cs5
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , Fs5
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+0
	.byte		N02   , Fs4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , Cn6
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte		N02   , Cn5
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , Fn5
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+0
	.byte		N02   , Fn4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , Bn5
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte		N02   , Bn4
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , En5
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+0
	.byte		N02   , En4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , As5
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte		N02   , As4
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , Ds5
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		BEND  , c_v+0
	.byte		N02   , Ds4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , An5
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+16
	.byte		N02   , An4
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , Cs5 , v056
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v+0
	.byte		N02   , Cs4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , An5
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+12
	.byte		BEND  , c_v+16
	.byte		N02   , An4
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+8
	.byte		N02   , Cs5 , v032
	.byte	W01
	.byte		BEND  , c_v+5
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v+0
	.byte		N02   , Cs4
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+42
	.byte		N02   , An5
	.byte	W01
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+24
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+16
	.byte		N02   , An4
	.byte	W01
	.byte		BEND  , c_v+12
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_stat_decrease_2:
	.byte	KEYSH , se_m_stat_decrease_key+0
	.byte		VOICE , 55
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 70*se_m_stat_decrease_mvl/mxv
	.byte		N02   , As3 , v052
	.byte	W03
	.byte		N02
	.byte	W03
	.byte	W01
	.byte		        An3
	.byte	W03
	.byte		N02
	.byte	W02
	.byte	W02
	.byte		        Gs3
	.byte	W04
	.byte		N02
	.byte	W03
	.byte		        Gn3
	.byte	W03
	.byte	W01
	.byte		N02
	.byte	W03
	.byte		        Fs3
	.byte	W02
	.byte	W02
	.byte		N02
	.byte	W04
	.byte		        Fn3
	.byte	W03
	.byte		N02
	.byte	W03
	.byte	W01
	.byte		        En3
	.byte	W03
	.byte		N02
	.byte	W02
	.byte	W02
	.byte		        Ds3
	.byte	W04
	.byte		        Ds3 , v032
	.byte	W03
	.byte		        Dn3
	.byte	W03
	.byte	W01
	.byte		N02
	.byte	W03
	.byte		        Cs3 , v020
	.byte	W02
	.byte	W02
	.byte		N02
	.byte	W04
	.byte		        Cn3 , v012
	.byte	W03
	.byte		N02
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_stat_decrease:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_stat_decrease_pri	@ Priority
	.byte	se_m_stat_decrease_rev	@ Reverb.

	.word	se_m_stat_decrease_grp

	.word	se_m_stat_decrease_1
	.word	se_m_stat_decrease_2

	.end
