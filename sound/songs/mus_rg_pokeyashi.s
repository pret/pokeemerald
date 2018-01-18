	.include "MPlayDef.s"

	.equ	mus_rg_pokeyashi_grp, voicegroup_86A67E4
	.equ	mus_rg_pokeyashi_pri, 0
	.equ	mus_rg_pokeyashi_rev, reverb_set+50
	.equ	mus_rg_pokeyashi_mvl, 127
	.equ	mus_rg_pokeyashi_key, 0
	.equ	mus_rg_pokeyashi_tbs, 1
	.equ	mus_rg_pokeyashi_exg, 0
	.equ	mus_rg_pokeyashi_cmp, 1

	.section .rodata
	.global	mus_rg_pokeyashi
	.align	2

@********************** Track  1 **********************@

mus_rg_pokeyashi_1:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte	TEMPO , 132*mus_rg_pokeyashi_tbs/2
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Fn5 , v064
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Fn5 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn4 
	.byte	W06
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		PAN   , c_v-1
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Fn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W12
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 , v076
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N03   , Fn5 , v064
	.byte	W06
	.byte		VOL   , 42*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Cs4 
	.byte	W06
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
mus_rg_pokeyashi_1_B1:
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W18
	.byte		PAN   , c_v-1
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Cn6 
	.byte	W06
	.byte	W06
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v032
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		VOL   , 42*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cn5 , v032
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W06
	.byte	W12
	.byte		        Fn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cs4 
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn6 
	.byte	W12
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v052
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn6 
	.byte	W78
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte	W06
	.byte		N03   , Cs4 , v072
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N06   , Cn6 , v064
	.byte	W06
	.byte		N18   , Cn6 , v120
	.byte	W18
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N03   , Fn5 , v064
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W06
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N03   , Cs4 
	.byte	W06
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v+0
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Fn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		PAN   , c_v-1
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W06
	.byte		VOL   , 42*mus_rg_pokeyashi_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N06   , Cn6 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cs4 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Cn6 , v064
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fn4 
	.byte	W12
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Cn6 
	.byte	W18
	.byte		PAN   , c_v-1
	.byte		N03   , Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cs4 , v064
	.byte	W18
	.byte		N06   , Cn6 
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N03   , Cn6 
	.byte	W18
	.byte		        Fn5 
	.byte	W06
	.byte		        Fn5 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W18
	.byte		PAN   , c_v-1
	.byte		VOL   , 41*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , Gn3 
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Ds4 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Bn3 
	.byte	W18
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte	W18
	.byte		N24   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		VOL   , 41*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v-1
	.byte	W18
	.byte		N24   , Ds4 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , Dn4 
	.byte	W24
	.byte		PAN   , c_v-1
	.byte		N24   , Bn3 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Dn4 , v120
	.byte	W06
	.byte		PAN   , c_v-1
	.byte	W18
	.byte		        c_v+63
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_pokeyashi_1_B1
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_pokeyashi_2:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_2_B1:
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 , v032
	.byte	W12
mus_rg_pokeyashi_2_000:
	.byte		PAN   , c_v-1
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , As3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 , v032
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_2_001:
	.byte		PAN   , c_v-1
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 , v032
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_2_002:
	.byte		PAN   , c_v-1
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W12
	.byte		        c_v-64
	.byte	W12
	.byte		        c_v-1
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte		PAN   , c_v-1
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_2_002
	.byte	GOTO
	 .word	mus_rg_pokeyashi_2_B1
	.byte		PAN   , c_v-1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_pokeyashi_3:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
mus_rg_pokeyashi_3_000:
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_3_001:
	.byte		N12   , Cs1 , v092
	.byte	W12
	.byte		        Cs1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_3_002:
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_3_003:
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_3_004:
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		N24   , Fn1 , v092
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte	PEND
mus_rg_pokeyashi_3_005:
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Cs1 , v092
	.byte	W12
	.byte		        Cs1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_3_006:
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		N24   , En1 , v092
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte	PEND
mus_rg_pokeyashi_3_B1:
	.byte		MOD   , 0
	.byte		VOL   , 63*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_004
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_005
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_006
mus_rg_pokeyashi_3_007:
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_004
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_005
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_006
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_007
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_004
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_005
	.byte	PATT
	 .word	mus_rg_pokeyashi_3_006
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N96   , Fn1 , v092
	.byte	W48
	.byte		VOL   , 79*mus_rg_pokeyashi_mvl/mxv
	.byte	W48
	.byte		        63*mus_rg_pokeyashi_mvl/mxv
	.byte		N96   , En1 
	.byte	W48
	.byte		VOL   , 79*mus_rg_pokeyashi_mvl/mxv
	.byte	W48
	.byte		        64*mus_rg_pokeyashi_mvl/mxv
	.byte		N96   , Gs1 
	.byte	W48
	.byte		VOL   , 79*mus_rg_pokeyashi_mvl/mxv
	.byte	W48
	.byte		        63*mus_rg_pokeyashi_mvl/mxv
	.byte		N48   , An1 
	.byte	W48
	.byte		VOL   , 79*mus_rg_pokeyashi_mvl/mxv
	.byte		N48   , En1 
	.byte	W12
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-53
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_pokeyashi_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_pokeyashi_4:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 39
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cs1 , v092
	.byte	W12
	.byte		        Cs1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Fn1 , v092
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-51
	.byte	W03
mus_rg_pokeyashi_4_000:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Cs1 , v092
	.byte	W12
	.byte		        Cs1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		VOL   , 67*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_001:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , En1 , v092
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte	PEND
mus_rg_pokeyashi_4_B1:
mus_rg_pokeyashi_4_002:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		VOL   , 67*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_003:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_004:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cs1 , v092
	.byte	W12
	.byte		        Cs1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		VOL   , 67*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_005:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		        En1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v092
	.byte	W12
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_006:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cn1 , v092
	.byte	W12
	.byte		        Cn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		VOL   , 67*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v020
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_4_007:
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		        Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 50*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn1 , v092
	.byte	W12
	.byte		        Fn1 , v020
	.byte	W12
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Fn1 , v092
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v-15
	.byte	W03
	.byte		        c_v-26
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-51
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_004
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_005
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_006
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_007
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_004
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_005
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_006
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_007
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_4_001
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Fn1 , v092
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		        79*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N96   , En1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		        79*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Gs1 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 72*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		        82*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , An1 , v104
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		VOL   , 77*mus_rg_pokeyashi_mvl/mxv
	.byte		N48   , Fn1 , v108
	.byte	W12
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		        c_v-7
	.byte	W03
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		VOL   , 90*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v-23
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-43
	.byte	W03
	.byte		        c_v-46
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-53
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_pokeyashi_4_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_pokeyashi_5:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_5_B1:
	.byte		VOICE , 13
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
mus_rg_pokeyashi_5_000:
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_5_001:
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_5_002:
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		        c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_5_003:
	.byte		PAN   , c_v-32
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_001
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		        c_v+32
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_003
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_003
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		        c_v+32
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		        c_v+32
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_001
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_003
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_001
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		        c_v+32
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_000
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_002
	.byte		VOICE , 14
	.byte		PAN   , c_v-32
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , En3 , v096
	.byte	W12
	.byte		        En3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		VOL   , 48*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 60*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte	PATT
	 .word	mus_rg_pokeyashi_5_003
	.byte		PAN   , c_v-32
	.byte		N12   , Gs3 , v096
	.byte	W12
	.byte		        Gs3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An3 , v096
	.byte	W12
	.byte		        An3 , v032
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Dn4 , v104
	.byte	W12
	.byte		        Dn4 , v044
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_pokeyashi_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_pokeyashi_6:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 58
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		MOD   , 1
	.byte		VOL   , 22*mus_rg_pokeyashi_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+16
	.byte		VOL   , 41*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Fn4 , v096
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 31*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 19*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 25*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 32*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , As4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 33*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 7
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 31*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 7
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 8
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		MOD   , 0
	.byte		VOL   , 37*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 7
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N24   , Bn4 , v120
	.byte	W12
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		        c_v+16
	.byte		MOD   , 0
	.byte		N24   , Dn5 , v064
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 7
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_pokeyashi_6_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_pokeyashi_7:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 19*mus_rg_pokeyashi_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_7_B1:
mus_rg_pokeyashi_7_000:
	.byte		N03   , Fn4 , v120
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 , v064
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_rg_pokeyashi_7_001:
	.byte		N03   , Fn4 , v080
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 , v088
	.byte	W06
	.byte		        Fn4 , v096
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 , v100
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Fn4 , v104
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 , v108
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Fn4 , v116
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 , v120
	.byte	W06
	.byte		        Gs4 , v124
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Gn4 , v127
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Fs4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Fn4 
	.byte	W06
	.byte	PEND
mus_rg_pokeyashi_7_002:
	.byte		N03   , En4 , v120
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_rg_pokeyashi_7_003:
	.byte		N03   , En4 , v080
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 , v088
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 , v100
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , En4 , v104
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 , v108
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , En4 , v116
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 , v120
	.byte	W06
	.byte		        Cs4 , v124
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , Dn4 , v127
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N03   , Ds4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , En4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_003
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_002
	.byte	PATT
	 .word	mus_rg_pokeyashi_7_003
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_pokeyashi_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_pokeyashi_8:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 0
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , En3 , v080
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Dn3 , v064
	.byte	W36
	.byte		        En3 , v080
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte	W96
	.byte		        En3 , v084
	.byte	W12
	.byte		        Dn3 , v052
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W36
	.byte		        En3 , v080
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte		N24   , Cn1 , v032
	.byte	W24
	.byte		        Cn1 , v060
	.byte	W24
	.byte		        Cn1 , v096
	.byte	W24
	.byte		N12   , Dn1 , v076
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_8_000:
	.byte		N24   , Cn1 , v032
	.byte	W24
	.byte		        Cn1 , v064
	.byte	W24
	.byte		        Cn1 , v096
	.byte	W24
	.byte		N12   , Dn1 , v080
	.byte	W24
	.byte	PEND
mus_rg_pokeyashi_8_B1:
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte		N12   , En3 , v080
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W36
	.byte		        En3 , v080
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Dn3 , v068
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_rg_pokeyashi_8_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_rg_pokeyashi_8_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 68*mus_rg_pokeyashi_mvl/mxv
	.byte		N42   , An2 , v120
	.byte	W42
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		N36   , Cn1 , v120
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v044
	.byte	W12
	.byte		        Dn1 , v028
	.byte	W12
	.byte		N36   , Cs2 , v120
	.byte	W36
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn1 , v064
	.byte	W12
	.byte		        Dn1 , v048
	.byte	W12
	.byte		        Dn1 , v032
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 , v092
	.byte	W12
	.byte		        Dn1 , v124
	.byte	W12
	.byte		        Dn1 , v060
	.byte	W12
	.byte		        Dn1 , v040
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_pokeyashi_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_pokeyashi_9:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_rg_pokeyashi_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N06   , Cn4 , v127
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
mus_rg_pokeyashi_9_B1:
	.byte	W96
	.byte	W72
	.byte		N06   , Cn4 , v127
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_pokeyashi_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_rg_pokeyashi_10:
	.byte	KEYSH , mus_rg_pokeyashi_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte	W96
	.byte	W96
mus_rg_pokeyashi_10_000:
	.byte		VOL   , 22*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   , Gn5 , v127
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		VOL   , 28*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte	PEND
mus_rg_pokeyashi_10_001:
	.byte		N01   , Gn5 , v127
	.byte	W06
	.byte		N01   
	.byte	W90
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
mus_rg_pokeyashi_10_B1:
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte		VOL   , 22*mus_rg_pokeyashi_mvl/mxv
	.byte	W48
	.byte		        28*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte		        34*mus_rg_pokeyashi_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_000
	.byte	PATT
	 .word	mus_rg_pokeyashi_10_001
	.byte		N01   , Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		VOL   , 39*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   , Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gn5 , v112
	.byte	W24
	.byte		VOL   , 34*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   , Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v096
	.byte	W06
	.byte		        Gn5 , v092
	.byte	W06
	.byte		        Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		VOL   , 38*mus_rg_pokeyashi_mvl/mxv
	.byte		N01   , Gn5 , v127
	.byte	W12
	.byte		        Gn5 , v096
	.byte	W12
	.byte		VOL   , 45*mus_rg_pokeyashi_mvl/mxv
	.byte		N24   , Gn5 , v112
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_pokeyashi_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_pokeyashi:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_pokeyashi_pri	@ Priority
	.byte	mus_rg_pokeyashi_rev	@ Reverb.

	.word	mus_rg_pokeyashi_grp

	.word	mus_rg_pokeyashi_1
	.word	mus_rg_pokeyashi_2
	.word	mus_rg_pokeyashi_3
	.word	mus_rg_pokeyashi_4
	.word	mus_rg_pokeyashi_5
	.word	mus_rg_pokeyashi_6
	.word	mus_rg_pokeyashi_7
	.word	mus_rg_pokeyashi_8
	.word	mus_rg_pokeyashi_9
	.word	mus_rg_pokeyashi_10

	.end
