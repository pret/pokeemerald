	.include "MPlayDef.s"

	.equ	mus_boy_sup_grp, voicegroup067
	.equ	mus_boy_sup_pri, 0
	.equ	mus_boy_sup_rev, reverb_set+50
	.equ	mus_boy_sup_mvl, 127
	.equ	mus_boy_sup_key, 0
	.equ	mus_boy_sup_tbs, 1
	.equ	mus_boy_sup_exg, 0
	.equ	mus_boy_sup_cmp, 1

	.section .rodata
	.global	mus_boy_sup
	.align	2

@********************** Track  1 **********************@

mus_boy_sup_1:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte	TEMPO , 128*mus_boy_sup_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_boy_sup_mvl/mxv
	.byte		LFOS  , 44
	.byte	W96
	.byte	W68
	.byte	W01
	.byte		VOL   , 52*mus_boy_sup_mvl/mxv
	.byte	W15
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
mus_boy_sup_1_B1:
	.byte		VOICE , 1
	.byte		VOL   , 52*mus_boy_sup_mvl/mxv
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W09
	.byte		N03   , Fn4 , v088
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N03   , Cn4 , v088
	.byte	W03
	.byte		N42   , Bn3 , v112
	.byte	W42
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Cn4 , v080
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 , v044
	.byte	W03
	.byte		        An3 , v040
	.byte	W03
	.byte		        Fs3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N03   , Gs4 , v088
	.byte	W03
	.byte		N15   , An4 , v112
	.byte	W15
	.byte		N03   , Fs4 , v088
	.byte	W03
	.byte		        En4 , v068
	.byte	W03
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N18   , Cs4 
	.byte	W18
	.byte		N30   , Bn3 
	.byte	W30
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Gn3 , v056
	.byte	W03
	.byte		        An3 , v072
	.byte	W03
	.byte		        Bn3 , v080
	.byte	W03
	.byte		        Dn4 , v084
	.byte	W03
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOICE , 17
	.byte	W12
	.byte		VOL   , 18*mus_boy_sup_mvl/mxv
	.byte		N36   , Cs5 
	.byte	W02
	.byte		VOL   , 19*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        21*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        22*mus_boy_sup_mvl/mxv
	.byte	W04
	.byte		        27*mus_boy_sup_mvl/mxv
	.byte	W02
	.byte		        31*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        38*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        42*mus_boy_sup_mvl/mxv
	.byte	W04
	.byte		        47*mus_boy_sup_mvl/mxv
	.byte	W02
	.byte		        51*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        53*mus_boy_sup_mvl/mxv
	.byte	W07
	.byte		        39*mus_boy_sup_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		VOL   , 18*mus_boy_sup_mvl/mxv
	.byte		N36   , Cs5 
	.byte	W02
	.byte		VOL   , 19*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        21*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        22*mus_boy_sup_mvl/mxv
	.byte	W04
	.byte		        27*mus_boy_sup_mvl/mxv
	.byte	W02
	.byte		        31*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        38*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        42*mus_boy_sup_mvl/mxv
	.byte	W04
	.byte		        47*mus_boy_sup_mvl/mxv
	.byte	W02
	.byte		        51*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		        53*mus_boy_sup_mvl/mxv
	.byte	W13
	.byte		        39*mus_boy_sup_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Ds5 , v064
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cs5 , v060
	.byte	W03
	.byte		        Cn5 , v056
	.byte	W03
	.byte		        Bn4 , v052
	.byte	W30
	.byte		N12   , En5 , v112
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N30   , Gn4 
	.byte	W30
	.byte		N06   , En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W36
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N18   , Bn4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        En5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn5 , v072
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
	.byte		        Bn4 , v056
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		VOL   , 28*mus_boy_sup_mvl/mxv
	.byte	W03
	.byte		VOICE , 17
	.byte		N03   , Ds5 , v076
	.byte	W03
	.byte		N12   , En5 
	.byte	W15
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N15   , En5 
	.byte	W15
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N09   , En5 
	.byte	W09
	.byte		N03   , An5 
	.byte	W03
	.byte		N24   , Gs5 
	.byte	W24
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N30   , En5 
	.byte	W24
	.byte		VOICE , 24
	.byte	W06
	.byte		N03   , Dn5 , v052
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_boy_sup_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_boy_sup_2:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 126
	.byte		PAN   , c_v-63
	.byte		VOL   , 35*mus_boy_sup_mvl/mxv
	.byte	W60
	.byte		N12   , Gn4 , v112
	.byte	W36
mus_boy_sup_2_000:
	.byte	W12
	.byte		N12   , Gn4 , v064
	.byte	W24
	.byte		        Gn4 , v080
	.byte	W24
	.byte		        Gn4 , v112
	.byte	W36
	.byte	PEND
mus_boy_sup_2_B1:
mus_boy_sup_2_001:
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
	.byte	PATT
	 .word	mus_boy_sup_2_001
mus_boy_sup_2_002:
	.byte	W12
	.byte		N06   , Gn4 , v112
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_boy_sup_2_002
	.byte	PATT
	 .word	mus_boy_sup_2_002
	.byte	PATT
	 .word	mus_boy_sup_2_002
	.byte	PATT
	 .word	mus_boy_sup_2_002
	.byte	PATT
	 .word	mus_boy_sup_2_002
	.byte	W60
	.byte		N12   , Gn4 , v112
	.byte	W36
	.byte	PATT
	 .word	mus_boy_sup_2_000
	.byte	GOTO
	 .word	mus_boy_sup_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_boy_sup_3:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 38
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*mus_boy_sup_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte		N03   , Bn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Bn1 
	.byte	W06
	.byte		BEND  , c_v-10
	.byte	W03
	.byte		        c_v-23
	.byte	W03
	.byte		        c_v-40
	.byte	W03
	.byte		        c_v-60
	.byte	W09
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N24   , En2 
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W09
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		BEND  , c_v-4
	.byte		N24   , En2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W18
mus_boy_sup_3_B1:
	.byte		N18   , An0 , v112
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N06   , An0 
	.byte	W12
	.byte		N03   , Gs0 
	.byte	W06
	.byte		N36   , An0 
	.byte	W06
	.byte		BEND  , c_v+14
	.byte	W06
	.byte		        c_v+0
	.byte	W24
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N18   , An0 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N06   , An0 
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N18   , Dn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N18   , An0 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        An0 
	.byte	W12
	.byte		N03   , Gs0 
	.byte	W06
	.byte		N36   , An0 
	.byte	W06
	.byte		BEND  , c_v+16
	.byte	W06
	.byte		        c_v+0
	.byte	W24
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N18   , An0 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		        An0 
	.byte	W18
	.byte		N12   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N18   , Dn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Gn2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N12   , Dn1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An0 , v092
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N03   , Dn2 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N18   , Dn2 
	.byte	W05
	.byte		BEND  , c_v-16
	.byte	W03
	.byte		        c_v-32
	.byte	W04
	.byte		        c_v-52
	.byte	W02
	.byte		        c_v-63
	.byte	W04
	.byte		        c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An0 , v092
	.byte	W06
	.byte		        Bn0 , v112
	.byte	W06
	.byte		N03   , Gs1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , Gn0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , Fs0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		        Fs0 
	.byte	W12
	.byte		N12   , As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , En0 
	.byte	W06
	.byte		        Gs0 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Bn1 
	.byte	W24
	.byte		N06   , Bn0 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		N03   , En2 
	.byte	W12
	.byte		N24   
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W09
	.byte		        c_v+0
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		BEND  , c_v-4
	.byte		N24   , En2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W18
	.byte	GOTO
	 .word	mus_boy_sup_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_boy_sup_4:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 56
	.byte		VOL   , 70*mus_boy_sup_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v060
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 , v120
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W12
mus_boy_sup_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+32
	.byte		VOL   , 52*mus_boy_sup_mvl/mxv
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W18
	.byte		VOL   , 52*mus_boy_sup_mvl/mxv
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W09
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W12
	.byte		VOL   , 52*mus_boy_sup_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W36
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v060
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N03   , Dn4 , v080
	.byte	W03
	.byte		        Cn4 , v072
	.byte	W03
	.byte		        Bn3 , v056
	.byte	W12
	.byte	GOTO
	 .word	mus_boy_sup_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_boy_sup_5:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 56
	.byte		VOL   , 66*mus_boy_sup_mvl/mxv
	.byte		PAN   , c_v-26
	.byte		LFOS  , 44
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En3 , v060
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , An3 , v052
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W12
mus_boy_sup_5_B1:
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
	.byte	GOTO
	 .word	mus_boy_sup_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_boy_sup_6:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v-63
	.byte		VOL   , 36*mus_boy_sup_mvl/mxv
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v080
	.byte	W18
	.byte		        En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
mus_boy_sup_6_000:
	.byte		N03   , En4 , v112
	.byte	W24
	.byte		        En4 , v064
	.byte	W24
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v080
	.byte	W42
	.byte	PEND
mus_boy_sup_6_B1:
mus_boy_sup_6_001:
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
	.byte	PATT
	 .word	mus_boy_sup_6_001
mus_boy_sup_6_002:
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		        En4 , v060
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_boy_sup_6_002
	.byte	PATT
	 .word	mus_boy_sup_6_002
	.byte	PATT
	 .word	mus_boy_sup_6_002
	.byte	PATT
	 .word	mus_boy_sup_6_002
	.byte	PATT
	 .word	mus_boy_sup_6_002
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v080
	.byte	W18
	.byte		        En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte	PATT
	 .word	mus_boy_sup_6_000
	.byte	GOTO
	 .word	mus_boy_sup_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_boy_sup_7:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 80
	.byte		PAN   , c_v-62
	.byte		VOL   , 39*mus_boy_sup_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		N03   , Fs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
mus_boy_sup_7_000:
	.byte	W12
	.byte		N06   , An2 , v112
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte	PEND
mus_boy_sup_7_B1:
	.byte		N24   , Cs3 , v112
	.byte	W30
	.byte		N06   
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W48
mus_boy_sup_7_001:
	.byte		N30   , Cs3 , v112
	.byte	W30
	.byte		N03   , Dn3 , v096
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N21   , En3 , v112
	.byte	W21
	.byte		N03   , Ds3 , v100
	.byte	W03
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N09   , Dn3 
	.byte	W09
	.byte		N03   , En3 , v096
	.byte	W03
	.byte	PEND
mus_boy_sup_7_002:
	.byte		N24   , Fs3 , v112
	.byte	W30
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N03   , As3 
	.byte	W03
	.byte		N09   , An3 
	.byte	W09
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PEND
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N04   , En3 
	.byte	W04
	.byte		N02   , Bn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N06   , En2 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N24   , Cs3 
	.byte	W30
	.byte		N06   
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W36
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte	PATT
	 .word	mus_boy_sup_7_001
	.byte	PATT
	 .word	mus_boy_sup_7_002
	.byte		N03   , Bn2 , v112
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N04   , En3 
	.byte	W04
	.byte		N02   , Bn2 
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		N04   , En2 
	.byte	W04
	.byte		N02   , Gs2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		VOL   , 27*mus_boy_sup_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W18
	.byte		VOL   , 27*mus_boy_sup_mvl/mxv
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Fs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W09
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W36
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOL   , 39*mus_boy_sup_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs2 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PATT
	 .word	mus_boy_sup_7_000
	.byte	GOTO
	 .word	mus_boy_sup_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_boy_sup_8:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		VOL   , 39*mus_boy_sup_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		N03   , Dn3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	W12
	.byte		        En3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Gs3 
	.byte	W24
mus_boy_sup_8_B1:
mus_boy_sup_8_000:
	.byte		N24   , An3 , v112
	.byte	W30
	.byte		N06   
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	PEND
mus_boy_sup_8_001:
	.byte		N30   , Gn3 , v112
	.byte	W30
	.byte		N03   , An3 , v096
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N21   , Bn3 , v112
	.byte	W21
	.byte		N03   , As3 , v100
	.byte	W03
	.byte		N09   , An3 , v112
	.byte	W09
	.byte		N03   , Gs3 , v096
	.byte	W03
	.byte		N09   , Gn3 , v112
	.byte	W09
	.byte		N03   , Gs3 , v100
	.byte	W03
	.byte		N09   , An3 , v112
	.byte	W09
	.byte		N03   , Bn3 , v096
	.byte	W03
	.byte	PEND
mus_boy_sup_8_002:
	.byte		N24   , Dn4 , v112
	.byte	W30
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W03
	.byte		N09   , Cs4 
	.byte	W09
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	PEND
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W04
	.byte		N02   , Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , En3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte	PATT
	 .word	mus_boy_sup_8_000
	.byte	PATT
	 .word	mus_boy_sup_8_001
	.byte	PATT
	 .word	mus_boy_sup_8_002
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N04   , Bn3 
	.byte	W04
	.byte		N02   , Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N04   , Bn2 
	.byte	W04
	.byte		N02   , En3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W09
	.byte		        En3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En3 , v064
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W09
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fs3 , v064
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W09
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N18   , Cs3 
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N06   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En3 , v060
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	W12
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 , v088
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W03
	.byte		        Gs3 , v056
	.byte	W03
	.byte		        Fs3 , v044
	.byte	W12
	.byte	GOTO
	 .word	mus_boy_sup_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_boy_sup_9:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*mus_boy_sup_mvl/mxv
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
mus_boy_sup_9_000:
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte	PEND
mus_boy_sup_9_B1:
mus_boy_sup_9_001:
	.byte		N06   , Cn1 , v112
	.byte	W24
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_boy_sup_9_001
	.byte	PATT
	 .word	mus_boy_sup_9_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_boy_sup_9_001
	.byte	PATT
	 .word	mus_boy_sup_9_001
	.byte	PATT
	 .word	mus_boy_sup_9_001
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N04   , Cn1 
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		N04   
	.byte	W04
mus_boy_sup_9_002:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		        Dn1 
	.byte	W18
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_boy_sup_9_002
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_boy_sup_9_000
	.byte	GOTO
	 .word	mus_boy_sup_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_boy_sup_10:
	.byte	KEYSH , mus_boy_sup_key+0
	.byte		VOICE , 83
	.byte		VOL   , 29*mus_boy_sup_mvl/mxv
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W84
	.byte		BEND  , c_v+4
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
mus_boy_sup_10_B1:
	.byte		N06   , Cs5 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W09
	.byte		N03   , Fn5 , v088
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N03   , Cn5 , v088
	.byte	W03
	.byte		N42   , Bn4 , v112
	.byte	W42
	.byte		N03   , Cn5 
	.byte	W03
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N03   , Cn5 , v080
	.byte	W03
	.byte		        Bn4 , v064
	.byte	W03
	.byte		        As4 , v044
	.byte	W03
	.byte		        An4 , v040
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N12   , Cs5 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N03   , Gs5 , v088
	.byte	W03
	.byte		N15   , An5 , v112
	.byte	W15
	.byte		N03   , Fs5 , v088
	.byte	W03
	.byte		        En5 , v068
	.byte	W03
	.byte		N06   , Cs5 , v112
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N30   , Bn4 
	.byte	W30
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , Gn4 , v056
	.byte	W03
	.byte		        An4 , v072
	.byte	W03
	.byte		        Bn4 , v080
	.byte	W03
	.byte		        Dn5 , v084
	.byte	W03
	.byte		N24   , En5 , v112
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W12
	.byte		VOICE , 84
	.byte	W12
	.byte		N36   , Cs5 
	.byte	W36
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		N18   , Bn4 
	.byte	W18
	.byte		N36   , Cs5 
	.byte	W42
	.byte		N06   , En4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W06
	.byte		N03   , Ds5 , v040
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Bn4 , v048
	.byte	W30
	.byte		N12   , En5 , v112
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N30   , Gn4 
	.byte	W30
	.byte		N06   , En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W36
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N18   , Bn4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        En5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn5 , v072
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
	.byte		        Bn4 , v056
	.byte	W03
	.byte		        An4 
	.byte	W06
	.byte		        Ds5 , v080
	.byte	W03
	.byte		N12   , En5 
	.byte	W15
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N15   , En5 
	.byte	W15
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N09   , En5 
	.byte	W09
	.byte		N03   , An5 
	.byte	W03
	.byte		N24   , Gs5 
	.byte	W24
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N30   , En5 
	.byte	W30
	.byte		N03   , Dn5 , v060
	.byte	W03
	.byte		        Cs5 , v048
	.byte	W03
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_boy_sup_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_boy_sup:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_boy_sup_pri	@ Priority
	.byte	mus_boy_sup_rev	@ Reverb.

	.word	mus_boy_sup_grp

	.word	mus_boy_sup_1
	.word	mus_boy_sup_2
	.word	mus_boy_sup_3
	.word	mus_boy_sup_4
	.word	mus_boy_sup_5
	.word	mus_boy_sup_6
	.word	mus_boy_sup_7
	.word	mus_boy_sup_8
	.word	mus_boy_sup_9
	.word	mus_boy_sup_10

	.end
