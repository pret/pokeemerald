	.include "MPlayDef.s"

	.equ	mus_rg_ajito_grp, voicegroup_86A1BB8
	.equ	mus_rg_ajito_pri, 0
	.equ	mus_rg_ajito_rev, reverb_set+50
	.equ	mus_rg_ajito_mvl, 127
	.equ	mus_rg_ajito_key, 0
	.equ	mus_rg_ajito_tbs, 1
	.equ	mus_rg_ajito_exg, 0
	.equ	mus_rg_ajito_cmp, 1

	.section .rodata
	.global	mus_rg_ajito
	.align	2

@********************** Track  1 **********************@

mus_rg_ajito_1:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte	TEMPO , 130*mus_rg_ajito_tbs/2
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte	W48
	.byte		        11*mus_rg_ajito_mvl/mxv
	.byte		N48   , Fs4 , v127
	.byte	W03
	.byte		VOL   , 16*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        61*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        73*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        85*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        90*mus_rg_ajito_mvl/mxv
	.byte	W06
mus_rg_ajito_1_B1:
	.byte		MOD   , 0
	.byte		VOL   , 29*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+1
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
mus_rg_ajito_1_000:
	.byte		PAN   , c_v-64
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v-64
	.byte		VOL   , 32*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 35*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 2
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 29*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_ajito_1_000
	.byte		PAN   , c_v-64
	.byte		MOD   , 2
	.byte		VOL   , 31*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 37*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		MOD   , 3
	.byte		VOL   , 41*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , En4 
	.byte	W12
	.byte		        En4 , v048
	.byte	W12
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N12   , En5 , v096
	.byte	W12
	.byte		        En5 , v036
	.byte	W12
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        En4 , v048
	.byte	W12
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W09
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		BEND  , c_v+1
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N18   
	.byte	W09
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		BEND  , c_v+2
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N18   , Cs4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W09
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N24   , Gn3 , v127
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N24   , En3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , En3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn2 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , Bn2 , v056
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N06   , Cn3 , v064
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 , v080
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Dn3 , v092
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W54
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W54
	.byte		PAN   , c_v-64
	.byte	W24
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W54
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W78
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N12   , Gn2 , v096
	.byte	W12
	.byte		N24   , As2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N24   , Cs3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N24   , Cs3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N24   , Cs3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N24   , Bn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Fs2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Bn3 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N18   , Bn3 
	.byte	W18
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N18   , Cs4 
	.byte	W18
	.byte		PAN   , c_v-64
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte		N48   , Fs3 
	.byte	W48
	.byte		PAN   , c_v+63
	.byte		N48   , Ds3 
	.byte	W48
	.byte		PAN   , c_v-64
	.byte		VOL   , 32*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 , v092
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs1 , v120
	.byte	W06
	.byte		        As3 , v104
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+1
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 , v112
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+2
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Bn3 , v116
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Fs3 , v120
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ajito_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_ajito_2:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N48   , Gs4 , v127
	.byte	W03
	.byte		VOL   , 16*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        61*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        73*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        85*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        90*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Dn5 
	.byte	W03
	.byte		VOL   , 16*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        61*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        73*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        85*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        90*mus_rg_ajito_mvl/mxv
	.byte	W06
mus_rg_ajito_2_B1:
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 51*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 55*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 65*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 53*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 65*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Cn3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Cs3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Ds3 
	.byte	W12
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   , Fs3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   , Gn3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   , As3 
	.byte	W12
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		        An3 , v100
	.byte	W03
	.byte		N18   , Gn3 , v120
	.byte	W06
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte		N12   , Fs3 , v127
	.byte	W12
	.byte		BEND  , c_v+1
	.byte		N48   , En3 , v060
	.byte	W32
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		        c_v+1
	.byte		N48   , Fn3 , v056
	.byte	W32
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		        c_v+1
	.byte		N48   , Fs3 , v092
	.byte	W32
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N48   , Gn3 , v127
	.byte	W32
	.byte	W01
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W66
	.byte		        En1 
	.byte	W12
mus_rg_ajito_2_000:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W78
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_2_000
	.byte		BEND  , c_v+0
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W78
	.byte		VOICE , 83
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W12
mus_rg_ajito_2_001:
	.byte	W12
	.byte		N36   , An3 , v127
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N24   , Bn3 
	.byte	W12
	.byte	PEND
mus_rg_ajito_2_002:
	.byte	W12
	.byte		N36   , Gn3 , v127
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		        Fs3 
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W12
	.byte	W12
	.byte		N36   , En3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ajito_2_001
	.byte	PATT
	 .word	mus_rg_ajito_2_002
	.byte	W12
	.byte		N36   , En3 , v127
	.byte	W36
	.byte		        Fs3 
	.byte	W36
	.byte		N12   , Ds3 
	.byte	W12
	.byte		VOICE , 81
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N24   , Fs3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		N24   , Gn3 
	.byte	W12
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte		N48   , Bn3 
	.byte	W48
	.byte		        Ds4 
	.byte	W48
	.byte		BEND  , c_v+0
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v092
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v088
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v088
	.byte	W06
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		VOL   , 39*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v084
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		        En2 , v127
	.byte	W06
	.byte		        En2 , v092
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v088
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v088
	.byte	W06
	.byte		VOL   , 51*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v127
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		        En2 , v127
	.byte	W06
	.byte		        En2 , v084
	.byte	W06
	.byte		        Bn2 , v127
	.byte	W06
	.byte		        Cn3 , v084
	.byte	W18
	.byte		        Cn3 , v116
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ajito_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_ajito_3:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
mus_rg_ajito_3_B1:
	.byte		VOICE , 92
	.byte		VOL   , 51*mus_rg_ajito_mvl/mxv
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
mus_rg_ajito_3_000:
	.byte		MOD   , 0
	.byte		N24   , Cs5 , v127
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PEND
mus_rg_ajito_3_001:
	.byte		MOD   , 0
	.byte		N24   , As4 , v127
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PEND
mus_rg_ajito_3_002:
	.byte		MOD   , 0
	.byte		N24   , Gs4 , v127
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ajito_3_000
	.byte	PATT
	 .word	mus_rg_ajito_3_001
	.byte	PATT
	 .word	mus_rg_ajito_3_002
	.byte		VOICE , 87
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		        En3 , v120
	.byte	W30
	.byte		        En2 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W30
	.byte		        En2 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte	W36
	.byte		N06   , En2 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , An3 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte	W36
	.byte		N06   , En3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
mus_rg_ajito_3_003:
	.byte	W36
	.byte		N06   , En3 , v127
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte	PEND
mus_rg_ajito_3_004:
	.byte	W36
	.byte		N06   , En3 , v127
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte	PEND
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W78
mus_rg_ajito_3_005:
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W78
	.byte	PEND
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W66
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ajito_3_005
	.byte	PATT
	 .word	mus_rg_ajito_3_005
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W54
	.byte		VOICE , 92
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
mus_rg_ajito_3_006:
	.byte		N24   , En2 , v127
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte	PEND
mus_rg_ajito_3_007:
	.byte		N24   , Cs3 , v127
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
mus_rg_ajito_3_008:
	.byte		N24   , As2 , v127
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	PEND
mus_rg_ajito_3_009:
	.byte		N24   , Gs2 , v127
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_3_006
	.byte	PATT
	 .word	mus_rg_ajito_3_007
	.byte	PATT
	 .word	mus_rg_ajito_3_008
	.byte	PATT
	 .word	mus_rg_ajito_3_009
	.byte		VOICE , 87
	.byte		N12   , En2 , v127
	.byte	W36
	.byte		N06   , En3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_ajito_3_003
	.byte	PATT
	 .word	mus_rg_ajito_3_004
	.byte		N48   , Bn3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W36
	.byte		        0
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 , v120
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		VOICE , 92
	.byte	W36
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ajito_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_ajito_4:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 48
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N48   , Gs2 , v096
	.byte	W06
	.byte		PAN   , c_v-40
	.byte		VOL   , 17*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 25*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-22
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		VOL   , 41*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		VOL   , 52*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , Dn2 , v100
	.byte	W06
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        89*mus_rg_ajito_mvl/mxv
	.byte	W12
mus_rg_ajito_4_B1:
	.byte		VOL   , 60*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte		VOICE , 38
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		VOL   , 64*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N06   , Cn2 , v127
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , En2 , v120
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , En1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Cn2 
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , En1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N24   , Cs2 
	.byte	W06
	.byte		BEND  , c_v+8
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N06   , En1 
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte	W96
	.byte		BEND  , c_v+0
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte		N03   , En1 
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N24   , Bn1 
	.byte	W06
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v-13
	.byte	W03
	.byte		        c_v-34
	.byte	W03
	.byte		        c_v-63
	.byte	W03
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte		N06   , En1 , v076
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W66
	.byte		        Gn1 , v120
	.byte	W06
	.byte		        Fs1 
	.byte	W06
mus_rg_ajito_4_000:
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W78
	.byte	PEND
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W66
	.byte		        En1 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ajito_4_000
	.byte	PATT
	 .word	mus_rg_ajito_4_000
	.byte	PATT
	 .word	mus_rg_ajito_4_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 120
	.byte		VOL   , 5*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		TIE   , Cn5 , v120
	.byte	W24
	.byte		VOL   , 8*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W24
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-48
	.byte	W24
	.byte		        c_v+48
	.byte	W12
	.byte		        c_v-48
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-48
	.byte	W12
	.byte		        c_v+48
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		VOL   , 12*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        21*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        39*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        48*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        52*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        61*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte		VOICE , 38
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v088
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v088
	.byte	W06
	.byte		VOL   , 52*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte		VOL   , 60*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v088
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v088
	.byte	W06
	.byte		VOL   , 52*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte		VOL   , 57*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v127
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte		VOL   , 61*mus_rg_ajito_mvl/mxv
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Bn1 , v127
	.byte	W06
	.byte		        Cn2 , v084
	.byte	W18
	.byte		        Cn2 , v120
	.byte	W06
	.byte		        Bn1 , v084
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ajito_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_ajito_5:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 7*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N48   , Gs3 , v080
	.byte	W06
	.byte		VOL   , 7*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        13*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W09
	.byte		VOL   , 18*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 21*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        24*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_ajito_mvl/mxv
	.byte		N48   , Fs4 
	.byte	W06
	.byte		VOL   , 7*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        11*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W06
	.byte		VOL   , 13*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_ajito_mvl/mxv
	.byte	W09
	.byte		        18*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        21*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        24*mus_rg_ajito_mvl/mxv
	.byte	W06
mus_rg_ajito_5_B1:
	.byte	W96
	.byte		VOICE , 14
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_ajito_5_000:
	.byte		PAN   , c_v+0
	.byte		N24   , En4 , v127
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   , En4 , v056
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , En4 , v044
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   , En4 , v024
	.byte	W24
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N24   , En5 , v127
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , En5 , v056
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N24   , En5 , v044
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , En5 , v024
	.byte	W24
	.byte	PATT
	 .word	mus_rg_ajito_5_000
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		N24   , En5 , v127
	.byte	W12
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N24   , Ds5 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Cn5 , v127
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn5 , v127
	.byte	W06
	.byte		N18   
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        As4 , v096
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn5 , v127
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W12
	.byte		VOICE , 17
	.byte		MOD   , 0
	.byte		VOL   , 48*mus_rg_ajito_mvl/mxv
	.byte	W09
	.byte		N03   , Ds5 , v096
	.byte	W03
	.byte		N24   , En5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		        An4 , v100
	.byte	W03
	.byte		N18   , Gn4 , v120
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 , v127
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cn5 , v064
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cs5 , v088
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 1
	.byte	W12
	.byte		N06   , Dn4 , v127
	.byte	W06
	.byte		        Ds4 
	.byte	W06
mus_rg_ajito_5_001:
	.byte		PAN   , c_v+0
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Bn4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn4 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , As4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , As4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Dn5 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn5 , v040
	.byte	W12
	.byte	PEND
mus_rg_ajito_5_002:
	.byte		PAN   , c_v+0
	.byte		N12   , Cs5 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Cs5 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Gs4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gs4 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gn4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Bn4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn4 , v040
	.byte	W12
	.byte	PEND
mus_rg_ajito_5_003:
	.byte		PAN   , c_v+0
	.byte		N12   , As4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , As4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Ds4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , An4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An4 , v040
	.byte	W12
	.byte	PEND
mus_rg_ajito_5_004:
	.byte		PAN   , c_v+0
	.byte		N12   , Gs4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gs4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v040
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Fs4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Fs4 , v040
	.byte	W12
	.byte		PAN   , c_v-1
	.byte		N12   , Ds4 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Ds4 , v040
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_5_001
	.byte	PATT
	 .word	mus_rg_ajito_5_002
	.byte	PATT
	 .word	mus_rg_ajito_5_003
	.byte	PATT
	 .word	mus_rg_ajito_5_004
	.byte		VOICE , 56
	.byte		PAN   , c_v+0
	.byte		VOL   , 79*mus_rg_ajito_mvl/mxv
	.byte		N03   , En4 , v127
	.byte	W06
	.byte		N06   , En4 , v120
	.byte	W18
	.byte		        En4 , v127
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W18
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 63*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		VOICE , 60
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W18
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 79*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		VOICE , 56
	.byte		N06   , En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N18   , Cs4 , v120
	.byte	W18
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Dn4 , v076
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_ajito_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_ajito_6:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 9*mus_rg_ajito_mvl/mxv
	.byte		N48   , Gs4 , v112
	.byte	W06
	.byte		VOL   , 14*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        19*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        24*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        32*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        64*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        70*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        77*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        9*mus_rg_ajito_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W06
	.byte		VOL   , 14*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        19*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        24*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        32*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        64*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        70*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        77*mus_rg_ajito_mvl/mxv
	.byte	W03
mus_rg_ajito_6_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v+32
	.byte		VOL   , 40*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
mus_rg_ajito_6_000:
	.byte		PAN   , c_v+32
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_6_000
	.byte		PAN   , c_v+32
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		VOL   , 49*mus_rg_ajito_mvl/mxv
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		VOL   , 54*mus_rg_ajito_mvl/mxv
	.byte		N06   , An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 41*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_ajito_6_000
	.byte	PATT
	 .word	mus_rg_ajito_6_000
	.byte		PAN   , c_v+32
	.byte		N06   , En2 , v127
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 45*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		VOL   , 51*mus_rg_ajito_mvl/mxv
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		VOL   , 33*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte		N96   , Bn2 , v120
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		N96   , En2 
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		N96   , Cs3 
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 30
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N48   , En3 , v064
	.byte	W06
	.byte		VOL   , 25*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 29*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        60*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        63*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fn3 , v080
	.byte	W06
	.byte		VOL   , 25*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 29*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        60*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        63*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fs3 , v092
	.byte	W06
	.byte		VOL   , 25*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 29*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        55*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        60*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        63*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 35*mus_rg_ajito_mvl/mxv
	.byte		N48   , Gn3 , v127
	.byte	W06
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 42*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        50*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        58*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        63*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        69*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        72*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        77*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 17
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , En3 
	.byte	W12
	.byte	W12
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte	W12
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fs3 
	.byte	W18
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		VOICE , 29
	.byte		N36   , En3 , v032
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , En3 
	.byte	W12
	.byte	W12
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte	W12
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte	W12
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 62*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Ds3 
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v+32
	.byte		VOL   , 49*mus_rg_ajito_mvl/mxv
	.byte		N06   , En3 , v127
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v-33
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N18   , Bn2 
	.byte	W18
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N18   
	.byte	W18
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , As2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N18   , Cs3 
	.byte	W18
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		VOL   , 38*mus_rg_ajito_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-32
	.byte		N06   , En2 , v072
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 , v092
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 43*mus_rg_ajito_mvl/mxv
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 , v127
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 46*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v-1
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v-2
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		VOL   , 51*mus_rg_ajito_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , En2 , v120
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Bn2 , v116
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		N06   , Fs2 , v120
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_ajito_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_ajito_7:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 78
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+18
	.byte		VOL   , 8*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v+15
	.byte	W92
	.byte	W01
mus_rg_ajito_7_B1:
	.byte		VOICE , 78
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte		N15   , En3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , Gn3 , v096
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Bn3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Bn3 , v096
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Dn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Bn3 , v096
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Gs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An3 , v096
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Bn3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N15   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , An3 , v096
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , En3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N15   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , En3 , v096
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , An3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Fs3 , v096
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N21   , En3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , Fn3 , v096
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+15
	.byte		N18   , Fs3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Fn3 , v096
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Ds3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 11*mus_rg_ajito_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+15
	.byte		N15   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , Gn4 , v096
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , As4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Bn4 , v096
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Dn5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Cs5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Bn4 , v096
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Gs4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , An4 , v096
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N15   , As4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , An4 , v096
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , En4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N15   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , En4 , v096
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , An4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte		N18   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Fs4 , v096
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N21   , En4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , Fn4 , v096
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v+15
	.byte		N18   , Fs4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		N03   , Fn4 , v096
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		MOD   , 0
	.byte		PAN   , c_v-17
	.byte		N24   , Ds4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+15
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		VOL   , 22*mus_rg_ajito_mvl/mxv
	.byte		N96   , En2 , v120
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
	.byte		N96   , En2 
	.byte	W60
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_ajito_mvl/mxv
	.byte	W06
	.byte		        68*mus_rg_ajito_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_ajito_mvl/mxv
	.byte	W18
	.byte		        22*mus_rg_ajito_mvl/mxv
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
	.byte		VOICE , 24
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N12   , Gn4 , v127
	.byte	W12
	.byte		N24   , As4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        As4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_ajito_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_ajito_8:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 65*mus_rg_ajito_mvl/mxv
	.byte	W48
	.byte		N48   , Cn3 , v104
	.byte	W36
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_rg_ajito_8_B1:
	.byte		N06   , En1 , v120
	.byte		N48   , Cs2 
	.byte	W24
	.byte		N06   , En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_rg_ajito_8_000:
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v072
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
mus_rg_ajito_8_001:
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PEND
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v072
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        En1 
	.byte		N48   , Bn2 
	.byte	W24
	.byte		N06   , En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v088
	.byte	W12
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	mus_rg_ajito_8_000
	.byte	PATT
	 .word	mus_rg_ajito_8_001
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        En1 , v064
	.byte	W12
	.byte		        En1 , v072
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N48   , Cn3 , v096
	.byte	W48
	.byte		N06   , Cn1 , v120
	.byte		N48   , An2 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N24   , Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte		N48   , En2 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N24   , Cs1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte		N48   , Gn2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte		N48   , Bn2 
	.byte	W12
	.byte		N24   , Cn1 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Dn3 , v088
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        En1 , v127
	.byte		N12   , As4 , v052
	.byte	W12
	.byte		N06   , Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Cn1 , v088
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        Dn3 , v096
	.byte		N12   , As4 , v052
	.byte	W12
	.byte		N06   , Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        En1 , v127
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Dn3 , v088
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        En1 , v127
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Dn3 , v088
	.byte	W06
	.byte		N03   , Dn3 , v120
	.byte		N06   , Gs4 , v044
	.byte	W03
	.byte		N03   , Dn3 , v084
	.byte	W03
	.byte		        Dn3 , v088
	.byte		N06   , An4 , v016
	.byte	W03
	.byte		N03   , Dn3 , v064
	.byte	W03
	.byte		N06   , Cn1 , v104
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Dn3 , v112
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Cn1 , v100
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        En1 , v127
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Dn3 , v076
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        Cn1 , v064
	.byte		N12   , As4 , v052
	.byte	W06
	.byte		N06   , Dn3 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , Gs4 , v044
	.byte	W06
	.byte		        Cn1 , v076
	.byte		N06   , An4 , v016
	.byte	W06
	.byte		        Cs1 , v120
	.byte		N12   , As4 , v052
	.byte	W12
	.byte		        Dn1 , v096
	.byte		N48   , Cs2 , v120
	.byte	W12
	.byte		N12   , Dn1 , v048
	.byte	W12
	.byte		        Dn1 , v028
	.byte	W12
	.byte		        Dn1 , v016
	.byte	W48
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v076
	.byte	W06
	.byte		N48   , Cn1 , v120
	.byte		N48   , An2 
	.byte	W48
	.byte		        Cn3 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        En2 , v064
	.byte	W96
	.byte	W72
	.byte		N60   , Cn3 , v052
	.byte	W24
	.byte	W12
	.byte		VOL   , 55*mus_rg_ajito_mvl/mxv
	.byte	W84
	.byte		        65*mus_rg_ajito_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Cn1 , v100
	.byte		N06   , En2 
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N42   , En2 , v127
	.byte	W18
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte		N24   , En2 , v127
	.byte	W12
	.byte		N06   , Cs1 , v120
	.byte	W06
	.byte		        Cs1 , v088
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N06   , En2 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte		N42   , En2 , v127
	.byte	W06
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cs1 , v076
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte		N24   , En2 , v127
	.byte	W06
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Dn1 
	.byte		N06   , En2 , v068
	.byte	W06
	.byte		        Dn1 , v120
	.byte		N42   , En2 , v127
	.byte	W06
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		        Bn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W03
	.byte		        Gn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte		N24   , En2 , v127
	.byte	W06
	.byte		N06   , Cn1 , v088
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W06
	.byte		N24   , Dn1 , v120
	.byte		N48   , Bn2 , v127
	.byte	W24
	.byte		N03   , Dn2 , v120
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W03
	.byte		        Fn1 
	.byte	W03
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N24   , Dn1 
	.byte		N48   , Cs2 , v127
	.byte	W24
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
mus_rg_ajito_8_002:
	.byte		N06   , Cn1 , v120
	.byte		N48   , An2 
	.byte	W18
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N48   , En2 
	.byte	W18
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_ajito_8_002
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N36   , En2 
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		N06   , Dn1 , v120
	.byte		N36   , Cn3 
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v120
	.byte	W06
	.byte		N12   , Fn1 , v124
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ajito_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_ajito_9:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte	W84
	.byte		N06   , Cn4 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
mus_rg_ajito_9_B1:
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N03   , Cn4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W24
	.byte		N06   
	.byte	W24
mus_rg_ajito_9_000:
	.byte		N03   , Cn4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PATT
	 .word	mus_rg_ajito_9_000
	.byte	PATT
	 .word	mus_rg_ajito_9_000
	.byte	PATT
	 .word	mus_rg_ajito_9_000
	.byte	PATT
	 .word	mus_rg_ajito_9_000
mus_rg_ajito_9_001:
	.byte		N06   , Cn4 , v064
	.byte	W06
	.byte		N06   
	.byte	W66
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_9_001
	.byte	PATT
	 .word	mus_rg_ajito_9_001
	.byte		N06   , Cn4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
mus_rg_ajito_9_002:
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		N03   
	.byte	W66
	.byte		N03   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_9_002
	.byte	PATT
	 .word	mus_rg_ajito_9_002
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		N01   , Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W06
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		        Cn5 , v096
	.byte	W06
	.byte		        Cn5 , v048
	.byte	W18
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte		N06   , Cn4 , v064
	.byte	W96
	.byte	W96
	.byte		VOL   , 34*mus_rg_ajito_mvl/mxv
	.byte		N84   , Cn4 , v092
	.byte	W90
	.byte		N03   , Cn4 , v060
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N21   , Cn4 , v092
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N21   , Cn4 , v080
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Cn4 , v060
	.byte	W12
	.byte		        Cn4 , v092
	.byte	W06
	.byte		N03   , Cn4 , v048
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N84   , Cn4 , v092
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W72
	.byte		N03   , Cn4 , v084
	.byte	W09
	.byte		        Cn4 , v056
	.byte	W09
	.byte		N09   , Cn4 , v044
	.byte	W06
	.byte		VOL   , 68*mus_rg_ajito_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W06
	.byte		N03   , Cn4 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , Cn5 , v024
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W48
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
	.byte		N06   , Cn4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		VOL   , 44*mus_rg_ajito_mvl/mxv
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W18
mus_rg_ajito_9_003:
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_ajito_9_003
	.byte		N03   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v088
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v080
	.byte	W18
	.byte	GOTO
	 .word	mus_rg_ajito_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_rg_ajito_10:
	.byte	KEYSH , mus_rg_ajito_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 56*mus_rg_ajito_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
mus_rg_ajito_10_B1:
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
	.byte	W12
	.byte		N12   , Gn5 , v060
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn5 , v056
	.byte	W24
	.byte		        Gn5 , v060
	.byte	W12
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Gn5 , v056
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		        Gn5 , v120
	.byte	W12
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W84
	.byte		        Gn5 , v080
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_ajito_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_ajito:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_ajito_pri	@ Priority
	.byte	mus_rg_ajito_rev	@ Reverb.

	.word	mus_rg_ajito_grp

	.word	mus_rg_ajito_1
	.word	mus_rg_ajito_2
	.word	mus_rg_ajito_3
	.word	mus_rg_ajito_4
	.word	mus_rg_ajito_5
	.word	mus_rg_ajito_6
	.word	mus_rg_ajito_7
	.word	mus_rg_ajito_8
	.word	mus_rg_ajito_9
	.word	mus_rg_ajito_10

	.end
