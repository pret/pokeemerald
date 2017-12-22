	.include "MPlayDef.s"

	.equ	mus_rg_santoan_grp, voicegroup_86AB938
	.equ	mus_rg_santoan_pri, 0
	.equ	mus_rg_santoan_rev, reverb_set+50
	.equ	mus_rg_santoan_mvl, 127
	.equ	mus_rg_santoan_key, 0
	.equ	mus_rg_santoan_tbs, 1
	.equ	mus_rg_santoan_exg, 0
	.equ	mus_rg_santoan_cmp, 1

	.section .rodata
	.global	mus_rg_santoan
	.align	2

@********************** Track  1 **********************@

mus_rg_santoan_1:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte	TEMPO , 114*mus_rg_santoan_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 42*mus_rg_santoan_mvl/mxv
	.byte	W72
	.byte		N12   , As2 , v127
	.byte	W12
	.byte		        Cn3 , v108
	.byte	W12
mus_rg_santoan_1_000:
	.byte		N24   , Cs3 , v127
	.byte	W24
	.byte		        Fn2 , v112
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte	PEND
mus_rg_santoan_1_001:
	.byte		N36   , As2 , v120
	.byte	W36
	.byte		N12   , Fn2 , v108
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PEND
mus_rg_santoan_1_002:
	.byte		N36   , Cn3 , v120
	.byte	W36
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte	PEND
mus_rg_santoan_1_B1:
	.byte	W72
	.byte		N12   , As2 , v127
	.byte	W12
	.byte		        Cn3 , v112
	.byte	W12
	.byte		N24   , Cs3 , v127
	.byte	W24
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Cs3 , v120
	.byte	W24
	.byte		N12   , Fs3 , v112
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N36   , Cn3 , v120
	.byte	W36
	.byte		N06   , As2 , v112
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N24   , Gs2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		VOL   , 45*mus_rg_santoan_mvl/mxv
	.byte		N12   , Fn3 , v120
	.byte	W12
	.byte		N24   , Cs3 , v112
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Cs3 , v127
	.byte	W24
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N24   , As2 , v120
	.byte	W24
	.byte		N12   , Cs3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_santoan_1_002
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 24
	.byte		VOL   , 40*mus_rg_santoan_mvl/mxv
	.byte		N01   , As3 , v120
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N01   , Cs3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   , En4 , v092
	.byte	W06
	.byte		N12   , Gs3 , v120
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N01   , Cs3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N01   , Cs3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N01   , Cs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N01   , An3 
	.byte	W06
	.byte		N05   , Cs3 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N01   , Gs3 , v092
	.byte	W06
	.byte		N04   , Cs3 , v120
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N01   , Fn3 , v092
	.byte	W06
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N01   , As2 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W06
	.byte		N03   , Cn3 , v112
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , Cs3 , v124
	.byte	W06
	.byte		N03   , Cs3 , v120
	.byte	W06
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N01   , Cn4 , v088
	.byte	W06
	.byte		N06   , Gs3 , v096
	.byte	W06
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N05   , Cs4 , v096
	.byte	W06
	.byte		N12   , Cn4 , v080
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N05   , Gs3 
	.byte	W06
	.byte		N01   , Cs4 
	.byte	W06
	.byte		N12   , Fn3 , v076
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 45*mus_rg_santoan_mvl/mxv
	.byte		N12   , Gs3 , v120
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Ds4 , v064
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Ds4 , v032
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Ds4 , v016
	.byte	W24
	.byte		PAN   , c_v-32
	.byte	W72
	.byte		N12   , As2 , v127
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_santoan_1_000
	.byte	PATT
	 .word	mus_rg_santoan_1_001
	.byte	PATT
	 .word	mus_rg_santoan_1_002
	.byte	GOTO
	 .word	mus_rg_santoan_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_santoan_2:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 77*mus_rg_santoan_mvl/mxv
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Gs3 , v064
	.byte	W12
	.byte		N24   , Fs4 , v112
	.byte	W24
mus_rg_santoan_2_000:
	.byte		N08   , Fn4 , v127
	.byte	W08
	.byte		        Fs4 , v096
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte	PEND
mus_rg_santoan_2_001:
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 , v064
	.byte	W12
	.byte		N24   , Fs4 , v127
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PEND
mus_rg_santoan_2_002:
	.byte		N24   , Gs4 , v127
	.byte	W24
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Ds4 , v127
	.byte	W24
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Ds4 , v096
	.byte	W12
	.byte	PEND
mus_rg_santoan_2_B1:
	.byte		VOICE , 4
	.byte		VOL   , 65*mus_rg_santoan_mvl/mxv
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fs4 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
mus_rg_santoan_2_003:
	.byte		MOD   , 0
	.byte		N08   , Fn4 , v127
	.byte	W08
	.byte		        Fs4 , v096
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N12   , Ds4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Ds4 , v127
	.byte	W24
	.byte		        Cn4 , v108
	.byte	W24
	.byte	PEND
mus_rg_santoan_2_004:
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 , v048
	.byte	W12
	.byte		N24   , Fs4 , v124
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PEND
mus_rg_santoan_2_005:
	.byte		N12   , Gs4 , v127
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        Fs4 , v127
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W36
	.byte	PEND
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		VOL   , 51*mus_rg_santoan_mvl/mxv
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fs4 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte	PATT
	 .word	mus_rg_santoan_2_003
	.byte	PATT
	 .word	mus_rg_santoan_2_004
	.byte	PATT
	 .word	mus_rg_santoan_2_005
	.byte		VOICE , 73
	.byte		VOL   , 89*mus_rg_santoan_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fn4 , v127
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N09   , Fs4 
	.byte	W09
	.byte		N03   , Gn4 , v080
	.byte	W03
	.byte		N12   , Gs4 , v127
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 , v127
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W09
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs4 , v127
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn4 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gs3 , v127
	.byte	W12
	.byte		        As3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        As3 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 , v127
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 , v127
	.byte	W12
	.byte		        Ds3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W09
	.byte		N03   , Bn3 , v068
	.byte	W03
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        As3 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N09   , Ds4 
	.byte	W09
	.byte		N03   , En4 , v076
	.byte	W03
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gs4 , v127
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		VOICE , 24
	.byte		VOL   , 74*mus_rg_santoan_mvl/mxv
	.byte		MOD   , 0
	.byte		N01   , Fn4 , v092
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N06   , Fn4 , v127
	.byte	W06
	.byte		N01   , Fn4 , v120
	.byte	W06
	.byte		N12   , Ds4 , v112
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N01   , Gs3 
	.byte	W06
	.byte		N12   , Fn4 , v127
	.byte	W12
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , Fn4 , v120
	.byte	W12
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Gs4 , v127
	.byte	W06
	.byte		N01   , Cn5 , v092
	.byte	W06
	.byte		N12   , Ds4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , Gs3 , v127
	.byte	W06
	.byte		N01   , Fn3 , v120
	.byte	W06
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   , Gs3 , v120
	.byte	W06
	.byte		N12   , Ds4 , v112
	.byte	W12
	.byte		N03   , Fn3 , v080
	.byte	W03
	.byte		        Gs3 , v092
	.byte	W03
	.byte		        As3 , v096
	.byte	W03
	.byte		        Cn4 , v104
	.byte	W03
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cs4 , v127
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fn4 , v127
	.byte	W06
	.byte		N03   , Ds4 , v104
	.byte	W03
	.byte		        Cs4 , v120
	.byte	W03
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N01   , Gs3 
	.byte	W06
	.byte		N03   , Gs3 , v120
	.byte	W06
	.byte		N06   , Gs3 , v127
	.byte	W06
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		        Fs3 , v076
	.byte	W03
	.byte		        Gs3 , v084
	.byte	W03
	.byte		        An3 , v096
	.byte	W03
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		N01   , Fs4 
	.byte	W06
	.byte		N05   , As3 , v120
	.byte	W06
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 , v127
	.byte	W12
	.byte		N01   , Fn4 , v092
	.byte	W06
	.byte		N04   , Gs3 , v112
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 , v127
	.byte	W12
	.byte		N01   , Cs4 , v092
	.byte	W06
	.byte		N12   , En3 , v112
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N01   , Fs3 , v120
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 , v127
	.byte	W12
	.byte		N01   , Fs4 , v080
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , As3 , v124
	.byte	W06
	.byte		N03   , As3 , v120
	.byte	W06
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N01   , Gs4 , v088
	.byte	W06
	.byte		N06   , Fn4 , v096
	.byte	W06
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N05   , Gs4 , v100
	.byte	W06
	.byte		N12   , Fs4 , v108
	.byte	W12
	.byte		N06   , Fn4 , v104
	.byte	W06
	.byte		N05   , Ds4 , v127
	.byte	W06
	.byte		N01   , Gs4 , v096
	.byte	W06
	.byte		N12   , Cn4 , v120
	.byte	W12
	.byte		VOICE , 1
	.byte		VOL   , 77*mus_rg_santoan_mvl/mxv
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        Gs4 , v064
	.byte	W24
	.byte		        Gs4 , v032
	.byte	W24
	.byte		        Gs4 , v016
	.byte	W24
	.byte		N12   , Cs4 , v127
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Gs3 , v120
	.byte	W12
	.byte		N24   , Fs4 , v127
	.byte	W24
	.byte	PATT
	 .word	mus_rg_santoan_2_000
	.byte	PATT
	 .word	mus_rg_santoan_2_001
	.byte	PATT
	 .word	mus_rg_santoan_2_002
	.byte	GOTO
	 .word	mus_rg_santoan_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_santoan_3:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 26*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_3_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N12   , Gs3 , v120
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		VOICE , 92
	.byte		N48   , Fs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N84   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W72
	.byte		        0
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N72   , Ds3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W60
	.byte		        0
	.byte		N24   , Gs3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Cs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Ds3 , v120
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Fn3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cs3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Ds3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N24   , Gs2 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , As2 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W21
	.byte		N15   , Cn3 , v120
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		N36   , Cs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Cn3 , v120
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N36   , Cn3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Gs3 , v120
	.byte	W12
	.byte		N24   , Gs2 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , As2 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N48   , Ds3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , En3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N84   , Gs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W72
	.byte		        0
	.byte		N12   , As3 , v120
	.byte	W12
	.byte		N36   , Cn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 , v120
	.byte	W06
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N36   , Gs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		N06   , Fn3 , v120
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N36   , As2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N24   , As2 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn3 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cs3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , As3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , Cn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N48   , Cs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N48   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_santoan_4:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_4_B1:
	.byte		N48   , Cs2 , v120
	.byte	W48
	.byte		N24   , Cn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		N36   , As1 
	.byte	W36
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N12   , As1 
	.byte	W12
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N48   , Gs1 
	.byte	W48
	.byte		        Cn2 
	.byte	W48
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N24   , Gs1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N06   , As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N24   , Ds1 
	.byte	W24
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W24
	.byte		N09   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N30   , Fs1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		N18   , Ds2 
	.byte	W18
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N30   , Fs1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N21   , Ds1 
	.byte	W24
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N18   , Cs2 
	.byte	W18
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N03   , Ds1 
	.byte	W12
	.byte		N03   
	.byte	W18
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   , Cn2 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N18   , Cn1 
	.byte	W24
	.byte		N06   , Ds1 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Cs2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W18
	.byte		        Ds1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W12
	.byte		N03   , Ds1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs2 
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		N24   , Cs1 
	.byte	W30
	.byte		N06   
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Cs2 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Cs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W12
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W42
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	W96
	.byte		VOL   , 31*mus_rg_santoan_mvl/mxv
	.byte	W48
	.byte		VOICE , 82
	.byte	W24
	.byte		MOD   , 5
	.byte	W06
	.byte		N06   , En1 
	.byte	W18
	.byte	W09
	.byte		TIE   
	.byte	W84
	.byte	W03
	.byte	W96
	.byte	W12
	.byte		VOL   , 30*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        25*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        19*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        19*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        13*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_santoan_mvl/mxv
	.byte	W09
	.byte		        8*mus_rg_santoan_mvl/mxv
	.byte	W09
	.byte		        6*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		        3*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		EOT   
	.byte		MOD   , 0
	.byte		VOL   , 0*mus_rg_santoan_mvl/mxv
	.byte	W48
	.byte		VOICE , 81
	.byte	W24
	.byte		VOL   , 56*mus_rg_santoan_mvl/mxv
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_santoan_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_santoan_5:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Fs4 , v120
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Cs5 , v056
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W06
	.byte		N06   , Fn5 , v044
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		PAN   , c_v+31
	.byte	W09
	.byte		N06   , Ds6 , v120
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Ds5 
	.byte	W09
	.byte		PAN   , c_v+31
	.byte	W06
	.byte		N06   , Cn5 , v044
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte	W12
	.byte		N06   , Ds4 , v120
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        As5 
	.byte	W18
	.byte		        Fs5 , v056
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Fs5 , v044
	.byte	W06
	.byte		        As5 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte	W09
	.byte		N06   , Cn6 , v120
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn5 , v056
	.byte	W06
	.byte		        Gs5 
	.byte	W09
	.byte		PAN   , c_v+32
	.byte	W06
	.byte		N06   , Fn5 , v044
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Ds4 , v120
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		        Cs5 , v056
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		PAN   , c_v-33
	.byte	W12
	.byte		N06   , Fs5 , v044
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	W09
	.byte		N06   , Cn6 , v120
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Fn5 , v056
	.byte	W06
	.byte		        Gs5 
	.byte	W09
	.byte		PAN   , c_v+31
	.byte	W06
	.byte		N06   , Fn5 , v044
	.byte	W06
	.byte		        Gs5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Ds4 , v120
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        As5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W06
	.byte		N06   , Fs5 , v044
	.byte	W06
	.byte		        As5 
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
	.byte		PAN   , c_v-62
	.byte		VOL   , 56*mus_rg_santoan_mvl/mxv
	.byte	W22
	.byte		VOICE , 58
	.byte	W56
	.byte		N06   , En2 , v120
	.byte	W18
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		TIE   
	.byte	W15
	.byte		PAN   , c_v-49
	.byte	W12
	.byte		        c_v-41
	.byte	W12
	.byte		        c_v-32
	.byte	W12
	.byte		        c_v-25
	.byte	W12
	.byte		        c_v-16
	.byte	W12
	.byte		        c_v-8
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+8
	.byte	W12
	.byte		        c_v+16
	.byte	W12
	.byte		        c_v+21
	.byte	W12
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+38
	.byte	W12
	.byte		        c_v+47
	.byte	W12
	.byte		        c_v+56
	.byte	W12
	.byte		        c_v+63
	.byte	W12
	.byte		VOL   , 42*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		VOL   , 33*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+41
	.byte		VOL   , 28*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		VOL   , 22*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		VOL   , 17*mus_rg_santoan_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		VOL   , 12*mus_rg_santoan_mvl/mxv
	.byte	W15
	.byte		        6*mus_rg_santoan_mvl/mxv
	.byte	W09
	.byte		EOT   
	.byte		VOL   , 0*mus_rg_santoan_mvl/mxv
	.byte	W48
	.byte		VOICE , 46
	.byte		VOL   , 48*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W48
	.byte	GOTO
	 .word	mus_rg_santoan_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_santoan_6:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 48
	.byte		VOL   , 41*mus_rg_santoan_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_6_B1:
	.byte	W96
	.byte		PAN   , c_v+32
	.byte	W96
	.byte		VOL   , 34*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte		VOICE , 48
	.byte	W96
	.byte		VOL   , 34*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N12   , Cs2 , v120
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Fn3 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gs2 , v120
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Ds3 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   , Gs2 , v120
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , As1 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Cs3 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gs2 , v120
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , As2 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   , Gs2 , v120
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , As3 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Cs3 , v120
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Fs3 , v096
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N06   , As2 , v120
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+16
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 24*mus_rg_santoan_mvl/mxv
	.byte		N84   , Gs4 
	.byte	W84
	.byte		N06   , As4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W36
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N12   , An4 
	.byte	W12
	.byte		N36   , As4 
	.byte	W36
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		N36   , Cn5 
	.byte	W36
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N36   , As4 
	.byte	W36
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N30   , Cn5 
	.byte	W30
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N30   , As4 
	.byte	W30
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N21   , Cn5 
	.byte	W21
	.byte		N15   , Cs5 
	.byte	W15
	.byte		N36   , Dn5 
	.byte	W36
	.byte		N12   , Ds5 
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v+32
	.byte		VOL   , 36*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N03   , As4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		VOL   , 36*mus_rg_santoan_mvl/mxv
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N03   , En5 , v092
	.byte	W03
	.byte		        Ds5 
	.byte	W09
	.byte		        Gs4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W24
	.byte		        Fn5 
	.byte	W12
	.byte	W54
	.byte		N03   , Cn5 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , As4 , v088
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W12
	.byte		        Fn5 , v120
	.byte	W18
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W36
	.byte		        Fn5 
	.byte	W06
	.byte		N03   , Ds5 , v088
	.byte	W03
	.byte		        Cs5 
	.byte	W09
	.byte		        Gs4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   , Fn4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fs4 
	.byte	W30
	.byte		        As4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		N03   , Gs4 , v092
	.byte	W03
	.byte		        Fs4 , v088
	.byte	W03
	.byte		N06   , Cn5 , v120
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Cn5 , v092
	.byte	W03
	.byte		        As4 
	.byte	W09
	.byte		        Gs4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Cn5 , v092
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N06   , Fs4 , v120
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W18
	.byte		N06   , Fn5 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W06
	.byte		N06   , Fn5 
	.byte	W12
	.byte		N03   , Ds5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Bn4 , v088
	.byte	W03
	.byte		        As4 
	.byte	W84
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_santoan_7:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_7_B1:
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
	.byte	W48
	.byte		VOICE , 80
	.byte	W06
	.byte		N06   , Fs4 , v120
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Bn4 , v092
	.byte	W03
	.byte		        As4 
	.byte	W09
	.byte		        Ds4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W12
	.byte	W54
	.byte		N03   , Gs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W06
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N03   , Fs4 , v088
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cn5 , v120
	.byte	W12
	.byte		        As4 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N03   , Fs4 , v088
	.byte	W03
	.byte		        Fn4 
	.byte	W09
	.byte		        Cs4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   , Gs3 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W30
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Cs4 , v092
	.byte	W03
	.byte		        As3 , v088
	.byte	W03
	.byte		N06   , Fs4 , v120
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Fs4 , v092
	.byte	W03
	.byte		        Fn4 
	.byte	W09
	.byte		        Cs4 , v120
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Cs4 , v092
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , As3 , v120
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        As4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W18
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn4 , v088
	.byte	W03
	.byte		        Fs4 
	.byte	W84
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_santoan_8:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v-8
	.byte		VOL   , 52*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-8
	.byte	W96
mus_rg_santoan_8_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , Cn1 , v120
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn4 , v024
	.byte	W12
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn4 , v024
	.byte	W24
	.byte		N12   , Cn1 , v120
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W24
	.byte		N24   , Bn4 , v024
	.byte	W24
	.byte		N12   , Cn1 , v120
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W24
	.byte		        Cs1 
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Cs1 
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W24
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W09
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N18   , Cs1 
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N15   , Cn1 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N15   , Cn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W18
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W18
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 , v124
	.byte	W12
	.byte		N06   , Ds1 , v120
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W18
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Ds1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N72   , An2 
	.byte	W96
	.byte		VOL   , 22*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N96   , Cn3 , v064
	.byte	W06
	.byte		VOL   , 30*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-43
	.byte	W06
	.byte		VOL   , 38*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-40
	.byte	W06
	.byte		VOL   , 45*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-30
	.byte	W06
	.byte		VOL   , 51*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W06
	.byte		        c_v-9
	.byte	W06
	.byte		VOL   , 56*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v-6
	.byte	W09
	.byte		VOL   , 63*mus_rg_santoan_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		VOL   , 74*mus_rg_santoan_mvl/mxv
	.byte	W06
	.byte		        79*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W06
	.byte		VOL   , 87*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v+10
	.byte	W06
	.byte		VOL   , 90*mus_rg_santoan_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W09
	.byte		        c_v+25
	.byte	W09
	.byte		        c_v+32
	.byte	W06
	.byte		        c_v+0
	.byte		VOL   , 49*mus_rg_santoan_mvl/mxv
	.byte		N24   , Cs2 , v060
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cs2 , v024
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N24   , Cs2 , v016
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Cs2 , v008
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_santoan_9:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_9_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_9_000:
	.byte		N02   , Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_santoan_9_000
	.byte		N02   , Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		N01   , Cn5 , v100
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
	.byte		N02   , Cn5 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		N01   , Cn5 , v064
	.byte	W18
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
mus_rg_santoan_9_001:
	.byte		N02   , Cn5 , v120
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W18
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte	PEND
mus_rg_santoan_9_002:
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_santoan_9_001
	.byte	PATT
	 .word	mus_rg_santoan_9_002
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W18
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N01   , Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		N01   , Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N02   
	.byte	W18
	.byte		        Cn5 , v092
	.byte	W12
	.byte		        Cn5 , v080
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		N01   , Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v092
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		N01   , Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W24
	.byte		        Cn5 , v064
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v068
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v068
	.byte	W18
	.byte		        Cn5 , v072
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v116
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W18
	.byte		N01   , Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v100
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		N01   , Cn5 , v060
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N02   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v036
	.byte	W18
	.byte		        Cn5 , v072
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W18
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W18
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_rg_santoan_10:
	.byte	KEYSH , mus_rg_santoan_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_rg_santoan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_santoan_10_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N12   , Gn5 , v080
	.byte	W24
	.byte	W72
	.byte		N12   
	.byte	W24
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte		        Gn5 , v120
	.byte	W96
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W24
	.byte		        Gn5 , v080
	.byte	W24
	.byte		        Gn5 , v096
	.byte	W24
	.byte		        Gn5 , v088
	.byte	W12
	.byte	W24
	.byte		        Gn5 , v080
	.byte	W72
mus_rg_santoan_10_000:
	.byte	W12
	.byte		N12   , Gn5 , v120
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte	PEND
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_rg_santoan_10_000
	.byte	W84
	.byte		N12   , Gn5 , v120
	.byte	W12
	.byte	W36
	.byte		N06   
	.byte	W60
	.byte	W30
	.byte		N12   
	.byte	W66
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	W12
	.byte		N12   
	.byte	W84
	.byte	PATT
	 .word	mus_rg_santoan_10_000
	.byte	W48
	.byte		N12   , Gn5 , v120
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W24
	.byte		        Gn5 , v076
	.byte	W24
	.byte		        Gn5 , v100
	.byte	W24
	.byte		        Gn5 , v112
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_santoan_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_santoan:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_santoan_pri	@ Priority
	.byte	mus_rg_santoan_rev	@ Reverb.

	.word	mus_rg_santoan_grp

	.word	mus_rg_santoan_1
	.word	mus_rg_santoan_2
	.word	mus_rg_santoan_3
	.word	mus_rg_santoan_4
	.word	mus_rg_santoan_5
	.word	mus_rg_santoan_6
	.word	mus_rg_santoan_7
	.word	mus_rg_santoan_8
	.word	mus_rg_santoan_9
	.word	mus_rg_santoan_10

	.end
