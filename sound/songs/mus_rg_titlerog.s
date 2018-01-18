	.include "MPlayDef.s"

	.equ	mus_rg_titlerog_grp, voicegroup_86B15F0
	.equ	mus_rg_titlerog_pri, 0
	.equ	mus_rg_titlerog_rev, reverb_set+50
	.equ	mus_rg_titlerog_mvl, 127
	.equ	mus_rg_titlerog_key, 0
	.equ	mus_rg_titlerog_tbs, 1
	.equ	mus_rg_titlerog_exg, 0
	.equ	mus_rg_titlerog_cmp, 1

	.section .rodata
	.global	mus_rg_titlerog
	.align	2

@********************** Track  1 **********************@

mus_rg_titlerog_1:
	.byte	KEYSH , mus_rg_titlerog_key+0
	.byte	TEMPO , 150*mus_rg_titlerog_tbs/2
	.byte		VOICE , 46
	.byte		BENDR , 2
	.byte		VOL   , 75*mus_rg_titlerog_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v+0
	.byte		N02   , En6 , v112
	.byte	W02
	.byte		        Dn6 
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N02   , Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		PAN   , c_v-48
	.byte		N02   , An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		PAN   , c_v+32
	.byte		N02   , En6 , v048
	.byte	W01
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		PAN   , c_v-32
	.byte		N02   , Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
mus_rg_titlerog_1_000:
	.byte		N02   , Fn5 , v048
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	PEND
	.byte	W01
	.byte		PAN   , c_v+16
	.byte		N02   , Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		PAN   , c_v-48
	.byte		N02   , An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_titlerog_1_000
	.byte	W01
	.byte		N02   , Dn5 , v048
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte	W01
	.byte		        En6 , v016
	.byte	W02
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        Dn6 
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v-48
	.byte		N02   , An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        An4 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte		N02   , Gs3 
	.byte	W02
	.byte		        Cn4 
	.byte	W01
	.byte	W01
	.byte		        Dn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        Gn4 
	.byte	W01
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Ds5 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , Dn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W01
	.byte	W01
	.byte		        Gn4 , v024
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Ds5 
	.byte	W02
	.byte		        Gn5 
	.byte	W01
	.byte	W01
	.byte		        Gs5 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte		N02   , Ds4 
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W01
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Ds5 
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		        Gs5 
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , Gn4 
	.byte	W02
	.byte		        Gs4 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Ds5 
	.byte	W01
	.byte	W01
	.byte		        Gn5 
	.byte	W02
	.byte		        Gs5 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte		        Ds6 , v044
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        Gs5 
	.byte	W02
	.byte		        Ds5 
	.byte	W02
	.byte		PAN   , c_v+32
	.byte		N02   , Dn6 , v080
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        As5 
	.byte	W02
	.byte		        Gn5 
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v-16
	.byte		N02   , Ds5 
	.byte	W02
	.byte		PAN   , c_v-32
	.byte		N02   , Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        As4 
	.byte	W02
	.byte		        Gn4 
	.byte	W02
	.byte		        Ds4 
	.byte	W01
	.byte	W01
	.byte		        Dn4 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , As3 
	.byte	W02
	.byte		        Dn6 , v048
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        As5 
	.byte	W02
	.byte		PAN   , c_v-32
	.byte		N02   , Gn5 
	.byte	W01
	.byte	W01
	.byte		        Ds5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        As4 
	.byte	W02
	.byte		PAN   , c_v+32
	.byte		N02   , Cn6 , v080
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Gn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte		N02   , Dn5 
	.byte	W01
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N02   , Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Gn4 
	.byte	W01
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Cn4 
	.byte	W01
	.byte	W01
	.byte		        An3 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , Cn6 , v048
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Gn5 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte		N02   , Fn5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Gn4 
	.byte	W01
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		PAN   , c_v+16
	.byte		N02   , Cn6 , v020
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		PAN   , c_v-16
	.byte		N02   , Gn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        As4 
	.byte	W01
	.byte	W01
	.byte		        Gs4 
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		VOL   , 62*mus_rg_titlerog_mvl/mxv
	.byte		N04   , Cn4 , v064
	.byte	W03
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Gn5 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Bn5 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        En6 , v056
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 53*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v036
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 44*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v032
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 37*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v020
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 27*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v012
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 22*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v008
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 14*mus_rg_titlerog_mvl/mxv
	.byte		N04   
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 11*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En6 , v004
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 7*mus_rg_titlerog_mvl/mxv
	.byte		N04   
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		VOL   , 6*mus_rg_titlerog_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		N72   
	.byte	W02
	.byte		VOL   , 6*mus_rg_titlerog_mvl/mxv
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        5*mus_rg_titlerog_mvl/mxv
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        4*mus_rg_titlerog_mvl/mxv
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        2*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        1*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W02
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_titlerog_2:
	.byte	KEYSH , mus_rg_titlerog_key+0
	.byte		VOICE , 46
	.byte		BENDR , 2
	.byte		VOL   , 50*mus_rg_titlerog_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N02   , Cn6 , v112
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
mus_rg_titlerog_2_000:
	.byte		N02   , En5 , v112
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	PEND
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        An4 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_titlerog_2_000
	.byte	W01
	.byte		N02   , Cn5 , v112
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Fn4 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		        Cn6 , v064
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
mus_rg_titlerog_2_001:
	.byte		N02   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	PEND
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte	W01
	.byte		        Fn4 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_titlerog_2_001
	.byte	W01
	.byte		N02   , An4 , v064
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 
	.byte	W01
	.byte	W01
	.byte		        Cn6 , v032
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        An4 
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        Fn4 
	.byte	W01
	.byte	W01
	.byte		        En4 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		VOL   , 40*mus_rg_titlerog_mvl/mxv
	.byte		N04   , Cn3 , v064
	.byte	W03
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Cn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        En4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Bn4 , v056
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        Dn5 , v052
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 41*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v040
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 37*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v032
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 29*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v024
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 22*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v016
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 17*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v008
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 9*mus_rg_titlerog_mvl/mxv
	.byte		N04   , En5 , v004
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 4*mus_rg_titlerog_mvl/mxv
	.byte		N04   
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		VOL   , 2*mus_rg_titlerog_mvl/mxv
	.byte		N04   
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+32
	.byte		VOL   , 1*mus_rg_titlerog_mvl/mxv
	.byte		N76   
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		VOL   , 0*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_titlerog_3:
	.byte	KEYSH , mus_rg_titlerog_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 31*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N72   , CnM2, v048
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_titlerog_4:
	.byte	KEYSH , mus_rg_titlerog_key+0
	.byte		VOICE , 46
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+33
	.byte		VOL   , 25*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W01
	.byte		N02   , En6 , v112
	.byte	W02
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        Dn6 
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        An4 
	.byte	W02
	.byte		        En6 , v048
	.byte	W02
	.byte		        Dn6 
	.byte	W01
	.byte	W01
	.byte		        Cn6 
	.byte	W02
mus_rg_titlerog_4_000:
	.byte		N02   , An5 , v048
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	PEND
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_titlerog_4_000
	.byte	W01
	.byte		N02   , En5 , v048
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		        En6 , v016
	.byte	W01
	.byte	W01
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        Dn6 
	.byte	W02
	.byte		        Cn6 
	.byte	W01
	.byte	W01
	.byte		        An5 
	.byte	W02
mus_rg_titlerog_4_001:
	.byte		N02   , Fn5 , v016
	.byte	W02
	.byte		        En5 
	.byte	W01
	.byte	PEND
	.byte	W01
	.byte		        Cn6 
	.byte	W02
	.byte		        An5 
	.byte	W02
	.byte		        Fn5 
	.byte	W01
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte	W01
	.byte		        Cn5 
	.byte	W02
	.byte	PATT
	 .word	mus_rg_titlerog_4_001
	.byte	W01
	.byte		N02   , Dn5 , v016
	.byte	W02
	.byte		VOICE , 1
	.byte		VOL   , 3*mus_rg_titlerog_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+0
	.byte		N80   , Cn4 , v124
	.byte	W01
	.byte		VOL   , 3*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        5*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        6*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        9*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        10*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        12*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        13*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        15*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        16*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        17*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        19*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        20*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        21*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        23*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        26*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        27*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        28*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        30*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        31*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        32*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        34*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        35*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        36*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        38*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        39*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        41*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        42*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        43*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 44*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        45*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        46*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		VOL   , 47*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        49*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W02
	.byte		VOL   , 50*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W02
	.byte	W02
	.byte		        c_v+0
	.byte		N24   , Gn3 
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N14   , An3 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N40   , Fn3 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N20   , Dn3 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		TIE   , En3 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		VOL   , 49*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        47*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        46*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        45*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        43*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        42*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        41*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        39*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        38*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        36*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        35*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        34*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        32*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        31*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        30*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        28*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        27*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        26*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        23*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        21*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        20*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        19*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        17*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        16*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        15*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        13*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        12*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        10*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        9*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        6*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        5*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        2*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        1*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_titlerog_5:
	.byte	KEYSH , mus_rg_titlerog_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v-17
	.byte		VOL   , 36*mus_rg_titlerog_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		VOL   , 3*mus_rg_titlerog_mvl/mxv
	.byte		N80   , Cn2 , v124
	.byte	W01
	.byte		VOL   , 3*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        5*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        6*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        9*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        10*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        12*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        13*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        15*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        16*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        17*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        19*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        20*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        21*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        23*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        26*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        27*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        28*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        30*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        31*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        32*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        34*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        35*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        36*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        38*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        39*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        41*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        42*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        43*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 44*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        45*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        46*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-11
	.byte	W01
	.byte		VOL   , 47*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        49*mus_rg_titlerog_mvl/mxv
	.byte		BEND  , c_v-16
	.byte	W02
	.byte		VOL   , 50*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W02
	.byte	W02
	.byte		        c_v+0
	.byte		N24   , Gn1 
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N14   , An1 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N40   , Fn1 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte		N20   , Dn1 
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		TIE   , En1 
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		VOL   , 49*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        48*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        47*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        46*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        45*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        44*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        43*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        42*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        41*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        40*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        39*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        38*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        37*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        36*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        35*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        34*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        33*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        32*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        31*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        30*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        29*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        28*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        27*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        26*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        25*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        24*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        23*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        22*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        21*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        20*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        19*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        18*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        17*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        16*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        15*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        14*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        13*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        12*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        11*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        10*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        9*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        8*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W01
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        7*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        6*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        5*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        4*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        3*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        2*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte		        1*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W02
	.byte		        0*mus_rg_titlerog_mvl/mxv
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_titlerog:
	.byte	5	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_titlerog_pri	@ Priority
	.byte	mus_rg_titlerog_rev	@ Reverb.

	.word	mus_rg_titlerog_grp

	.word	mus_rg_titlerog_1
	.word	mus_rg_titlerog_2
	.word	mus_rg_titlerog_3
	.word	mus_rg_titlerog_4
	.word	mus_rg_titlerog_5

	.end
