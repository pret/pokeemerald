	.include "MPlayDef.s"

	.equ	mus_sitennou_grp, voicegroup_8692E7C
	.equ	mus_sitennou_pri, 0
	.equ	mus_sitennou_rev, reverb_set+50
	.equ	mus_sitennou_mvl, 127
	.equ	mus_sitennou_key, 0
	.equ	mus_sitennou_tbs, 1
	.equ	mus_sitennou_exg, 0
	.equ	mus_sitennou_cmp, 1

	.section .rodata
	.global	mus_sitennou
	.align	2

@********************** Track  1 **********************@

mus_sitennou_1:
	.byte	KEYSH , mus_sitennou_key+0
	.byte	TEMPO , 134*mus_sitennou_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 51*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v+62
	.byte	W24
mus_sitennou_1_B1:
mus_sitennou_1_000:
	.byte	W12
	.byte		N03   , Gn5 , v072
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	PATT
	 .word	mus_sitennou_1_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_sitennou_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_sitennou_2:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*mus_sitennou_mvl/mxv
	.byte	W24
mus_sitennou_2_B1:
	.byte		VOICE , 38
	.byte		BEND  , c_v-5
	.byte		N12   , Bn0 , v112
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W12
	.byte		N12   , As1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		BEND  , c_v-4
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Bn0 
	.byte	W36
	.byte		BEND  , c_v-6
	.byte		N24   , Cn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W18
	.byte		        c_v-5
	.byte		N12   , Bn0 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W12
	.byte		N12   , As1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		BEND  , c_v-4
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Bn0 
	.byte	W36
	.byte		BEND  , c_v-6
	.byte		N06   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
mus_sitennou_2_000:
	.byte		BEND  , c_v-5
	.byte		N12   , Dn1 , v112
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N12   , An1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Ds1 
	.byte	W06
	.byte		BEND  , c_v-4
	.byte		N12   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte	PEND
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W24
	.byte		N03   , An0 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v-6
	.byte		N24   , Ds1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W18
	.byte	PATT
	 .word	mus_sitennou_2_000
	.byte		BEND  , c_v-5
	.byte		N12   , Dn1 , v112
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte	W06
	.byte		        c_v+0
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        An0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        As0 
	.byte	W18
mus_sitennou_2_001:
	.byte		BEND  , c_v-5
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte		N03   , Cs2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Gs1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte		N03   , Cn2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Gn1 
	.byte	W06
	.byte		BEND  , c_v+4
	.byte		N06   , Cn2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		        Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		BEND  , c_v-4
	.byte		N03   , Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte	PEND
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N06   , Cn2 
	.byte	W06
	.byte		BEND  , c_v-6
	.byte		N03   , Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte		N03   , Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		        Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte		        Bn0 
	.byte	W03
	.byte		        Cn1 
	.byte	W03
	.byte	PATT
	 .word	mus_sitennou_2_001
	.byte		N06   , An0 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , As0 
	.byte	W12
	.byte		N03   , An0 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , An0 
	.byte	W12
	.byte		N24   , An1 
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		        c_v-12
	.byte	W03
	.byte		        c_v-20
	.byte	W04
	.byte		        c_v-28
	.byte	W02
	.byte		        c_v-38
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-59
	.byte	W04
	.byte	GOTO
	 .word	mus_sitennou_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_sitennou_3:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 68*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v-1
	.byte	W24
mus_sitennou_3_B1:
	.byte		VOICE , 13
	.byte		PAN   , c_v-32
	.byte		VOL   , 64*mus_sitennou_mvl/mxv
	.byte	W12
	.byte		N03   , Bn5 , v088
	.byte	W03
	.byte		N06   , Bn5 , v036
	.byte	W09
	.byte		PAN   , c_v-23
	.byte		N03   , An5 , v096
	.byte	W03
	.byte		N06   , An5 , v036
	.byte	W09
	.byte		PAN   , c_v-7
	.byte		N03   , Gn5 , v096
	.byte	W03
	.byte		N06   , Gn5 , v036
	.byte	W09
	.byte		PAN   , c_v+20
	.byte		N03   , Fs5 , v096
	.byte	W03
	.byte		        Fs5 , v036
	.byte	W03
	.byte		        En5 , v096
	.byte	W03
	.byte		N06   , En5 , v036
	.byte	W09
	.byte		N03   , Dn5 , v096
	.byte	W03
	.byte		N06   , Dn5 , v036
	.byte	W03
	.byte		PAN   , c_v+28
	.byte	W06
	.byte		N03   , Fs5 , v096
	.byte	W03
	.byte		        Fs5 , v036
	.byte	W03
	.byte		N12   , Bn4 , v096
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v-26
	.byte		VOL   , 73*mus_sitennou_mvl/mxv
	.byte		MOD   , 8
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cn2 
	.byte	W12
	.byte		MOD   , 19
	.byte	W12
	.byte		        8
	.byte		N09   , An1 
	.byte	W09
	.byte		N03   , As1 
	.byte	W03
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		VOL   , 58*mus_sitennou_mvl/mxv
	.byte	W12
	.byte		N03   , Bn5 
	.byte	W03
	.byte		N06   , Bn5 , v036
	.byte	W09
	.byte		PAN   , c_v+29
	.byte		N03   , An5 , v112
	.byte	W03
	.byte		N06   , An5 , v036
	.byte	W06
	.byte		PAN   , c_v+16
	.byte	W03
	.byte		N03   , Gn5 , v112
	.byte	W03
	.byte		N06   , Gn5 , v036
	.byte	W09
	.byte		PAN   , c_v-16
	.byte		N03   , Fs5 , v112
	.byte	W03
	.byte		        Fs5 , v036
	.byte	W03
	.byte		        En5 , v112
	.byte	W03
	.byte		N06   , En5 , v036
	.byte	W09
	.byte		N03   , Dn5 , v112
	.byte	W03
	.byte		N06   , Dn5 , v036
	.byte	W03
	.byte		PAN   , c_v-27
	.byte	W06
	.byte		N03   , As4 , v112
	.byte	W03
	.byte		        As4 , v036
	.byte	W03
	.byte		N12   , Fs5 , v112
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v-27
	.byte		VOL   , 73*mus_sitennou_mvl/mxv
	.byte		MOD   , 8
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		PAN   , c_v-27
	.byte	W03
	.byte		VOICE , 17
	.byte		VOL   , 68*mus_sitennou_mvl/mxv
	.byte		N03   , Cn4 , v064
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		PAN   , c_v-14
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v+18
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		VOICE , 13
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		VOL   , 64*mus_sitennou_mvl/mxv
	.byte	W12
	.byte		N03   , Dn6 , v080
	.byte	W03
	.byte		N06   , Dn6 , v036
	.byte	W09
	.byte		PAN   , c_v-24
	.byte		N03   , Cn6 , v096
	.byte	W03
	.byte		N06   , Cn6 , v036
	.byte	W09
	.byte		PAN   , c_v-8
	.byte		N03   , As5 , v096
	.byte	W03
	.byte		N06   , As5 , v036
	.byte	W09
	.byte		PAN   , c_v+19
	.byte		N03   , An5 , v096
	.byte	W03
	.byte		        An5 , v036
	.byte	W03
	.byte		        Gn5 , v096
	.byte	W03
	.byte		N06   , Gn5 , v036
	.byte	W09
	.byte		N03   , Fn5 , v096
	.byte	W03
	.byte		N06   , Fn5 , v036
	.byte	W03
	.byte		PAN   , c_v+32
	.byte	W06
	.byte		N03   , An5 , v096
	.byte	W03
	.byte		        An5 , v036
	.byte	W03
	.byte		N12   , Dn5 , v096
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v-27
	.byte		VOL   , 74*mus_sitennou_mvl/mxv
	.byte		MOD   , 9
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W03
	.byte		MOD   , 15
	.byte	W09
	.byte		VOICE , 24
	.byte		VOL   , 68*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v+24
	.byte		MOD   , 9
	.byte		N03   , An5 , v088
	.byte	W03
	.byte		        As5 , v068
	.byte	W03
	.byte		        An5 , v064
	.byte	W06
	.byte		        Gn5 , v088
	.byte	W06
	.byte		        Fn5 , v076
	.byte	W06
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		VOL   , 58*mus_sitennou_mvl/mxv
	.byte	W12
	.byte		N03   , Dn6 , v092
	.byte	W03
	.byte		N06   , Dn6 , v036
	.byte	W09
	.byte		PAN   , c_v+21
	.byte		N03   , Cn6 , v096
	.byte	W03
	.byte		N06   , Cn6 , v036
	.byte	W09
	.byte		PAN   , c_v+8
	.byte		N03   , As5 , v112
	.byte	W03
	.byte		N06   , As5 , v036
	.byte	W09
	.byte		PAN   , c_v-16
	.byte		N03   , An5 , v112
	.byte	W03
	.byte		        An5 , v036
	.byte	W03
	.byte		        Gn5 , v112
	.byte	W03
	.byte		N06   , Gn5 , v036
	.byte	W09
	.byte		N03   , Fn5 , v112
	.byte	W03
	.byte		N06   , Fn5 , v036
	.byte	W03
	.byte		PAN   , c_v-27
	.byte	W06
	.byte		N03   , Cs5 , v112
	.byte	W03
	.byte		        Cs5 , v036
	.byte	W03
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v-27
	.byte		VOL   , 74*mus_sitennou_mvl/mxv
	.byte		MOD   , 9
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 17
	.byte		VOL   , 68*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v+51
	.byte		N03   , Ds4 , v064
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v+30
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		PAN   , c_v-17
	.byte		N03   , An4 
	.byte	W03
	.byte		PAN   , c_v-23
	.byte		N03   , As4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		PAN   , c_v-38
	.byte		N03   , As4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-6
	.byte		N03   , An4 , v112
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v-26
	.byte		MOD   , 8
	.byte		VOL   , 78*mus_sitennou_mvl/mxv
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 21
	.byte	W12
	.byte		VOICE , 38
	.byte		MOD   , 10
	.byte		PAN   , c_v+0
	.byte		VOL   , 55*mus_sitennou_mvl/mxv
	.byte		N03   , An4 , v092
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		N12   , Gn4 , v076
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , An4 , v084
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , An4 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W12
	.byte		VOICE , 17
	.byte		PAN   , c_v+44
	.byte		VOL   , 60*mus_sitennou_mvl/mxv
	.byte		N03   , An4 , v072
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		PAN   , c_v+27
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		PAN   , c_v-13
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v-40
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte	GOTO
	 .word	mus_sitennou_3_B1
	.byte		PAN   , c_v+6
	.byte	FINE

@********************** Track  4 **********************@

mus_sitennou_4:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 27*mus_sitennou_mvl/mxv
	.byte	W24
mus_sitennou_4_B1:
mus_sitennou_4_000:
	.byte		N06   , En5 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	PATT
	 .word	mus_sitennou_4_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_sitennou_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_sitennou_5:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v-61
	.byte	W24
mus_sitennou_5_B1:
	.byte		MOD   , 2
	.byte		BEND  , c_v+0
	.byte		N12   , Fs2 , v112
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N09   , En2 
	.byte	W09
	.byte		N03   , Fn2 
	.byte	W03
	.byte		MOD   , 2
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N03   , Fs2 , v064
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
mus_sitennou_5_000:
	.byte		MOD   , 2
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte		N12   
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PATT
	 .word	mus_sitennou_5_000
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        2
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , En4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte	GOTO
	 .word	mus_sitennou_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_sitennou_6:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_sitennou_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W24
mus_sitennou_6_B1:
	.byte	W12
	.byte		N03   , Fs5 , v112
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N09   , En3 
	.byte	W09
	.byte		N03   , Fn3 
	.byte	W03
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		VOL   , 54*mus_sitennou_mvl/mxv
	.byte		N06   , An5 
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte		        An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte		PAN   , c_v-61
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		PAN   , c_v-61
	.byte		N06   , An5 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
mus_sitennou_6_000:
	.byte		PAN   , c_v+63
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte		        An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte		PAN   , c_v-61
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		PAN   , c_v-61
	.byte		N06   , An5 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W06
	.byte		        An5 , v036
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_6_000
	.byte		PAN   , c_v+63
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-61
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		VOL   , 39*mus_sitennou_mvl/mxv
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte	GOTO
	 .word	mus_sitennou_6_B1
	.byte		PAN   , c_v+63
	.byte	FINE

@********************** Track  7 **********************@

mus_sitennou_7:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 66*mus_sitennou_mvl/mxv
	.byte		N06   , Cn1 , v112
	.byte		N24   , An2 , v076
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   
	.byte	W06
mus_sitennou_7_B1:
mus_sitennou_7_000:
	.byte		N48   , An2 , v112
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
mus_sitennou_7_001:
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_7_000
	.byte	PATT
	 .word	mus_sitennou_7_001
mus_sitennou_7_002:
	.byte		N48   , An2 , v112
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte	PEND
	.byte	W18
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v096
	.byte	W06
	.byte		        En1 , v112
	.byte	W24
	.byte	PATT
	 .word	mus_sitennou_7_002
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W24
mus_sitennou_7_003:
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_7_003
	.byte	PATT
	 .word	mus_sitennou_7_003
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , En1 
	.byte		N24   , An2 
	.byte	W03
	.byte		N03   , En1 
	.byte	W21
	.byte	GOTO
	 .word	mus_sitennou_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_sitennou_8:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 84
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*mus_sitennou_mvl/mxv
	.byte	W24
mus_sitennou_8_B1:
	.byte		MOD   , 8
	.byte		BEND  , c_v-4
	.byte		N12   , Bn1 , v112
	.byte	W03
	.byte		MOD   , 2
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N18   , Cn2 
	.byte	W06
	.byte		MOD   , 15
	.byte	W12
	.byte		        0
	.byte		N03   , Bn1 
	.byte	W03
	.byte		        As1 
	.byte	W03
	.byte		N09   , An1 
	.byte	W09
	.byte		N03   , As1 
	.byte	W03
	.byte		MOD   , 2
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cn2 
	.byte	W06
	.byte		MOD   , 14
	.byte	W18
	.byte		N03   , Bn1 , v088
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , As1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		MOD   , 2
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Ds2 
	.byte	W03
	.byte		MOD   , 13
	.byte	W21
	.byte		N06   , Cn2 
	.byte	W03
	.byte		MOD   , 3
	.byte	W03
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N12   
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En2 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		BEND  , c_v-4
	.byte		N03   , An2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        2
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W06
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		N03   , An2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N03   
	.byte	W36
	.byte	GOTO
	 .word	mus_sitennou_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_sitennou_9:
	.byte	KEYSH , mus_sitennou_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_sitennou_mvl/mxv
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W03
	.byte		N03   
	.byte	W03
mus_sitennou_9_B1:
	.byte		PAN   , c_v-30
	.byte		N12   , Bn1 , v112
	.byte	W60
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+26
	.byte		N06   , Bn1 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Fs1 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Bn1 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N06   , Fs1 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Bn1 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+31
	.byte		N03   , Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 
	.byte	W48
	.byte		PAN   , c_v+23
	.byte		N06   , As1 
	.byte	W12
	.byte		PAN   , c_v-31
	.byte		N06   , Fs1 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-29
	.byte		N12   , Fs1 
	.byte	W03
	.byte		PAN   , c_v-31
	.byte	W09
	.byte		        c_v+22
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N06   , Fn1 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte	W09
	.byte		N06   , Fs1 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , Bn1 
	.byte	W06
	.byte		PAN   , c_v-31
	.byte		N06   , Fs1 
	.byte	W12
	.byte		PAN   , c_v+35
	.byte		N06   , Bn1 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N06   , Fs1 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N12   , Dn2 
	.byte	W36
	.byte		PAN   , c_v-36
	.byte	W12
	.byte		        c_v+22
	.byte		N06   , An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		PAN   , c_v-37
	.byte		N06   , An2 
	.byte	W12
	.byte		PAN   , c_v+22
	.byte		N06   , Dn3 
	.byte	W12
	.byte		PAN   , c_v-36
	.byte		N06   , An2 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		PAN   , c_v+26
	.byte		N12   , Dn2 
	.byte	W48
	.byte		N06   , An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-35
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W48
	.byte		PAN   , c_v+25
	.byte		N06   , Dn3 
	.byte	W12
	.byte		PAN   , c_v-35
	.byte		N06   , An2 
	.byte	W12
	.byte		PAN   , c_v+23
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v-35
	.byte		N06   , An2 
	.byte	W12
	.byte		PAN   , c_v-44
	.byte		N06   
	.byte	W12
	.byte		        An2 , v052
	.byte	W12
	.byte		        An2 , v084
	.byte	W12
	.byte		        An2 , v096
	.byte	W12
	.byte		        An2 , v112
	.byte	W12
	.byte		        An2 , v127
	.byte	W12
	.byte		        An2 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
mus_sitennou_9_000:
	.byte		PAN   , c_v-32
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+39
	.byte		N06   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+39
	.byte		N06   , Cs2 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+39
	.byte		N06   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-48
	.byte		N24   , As2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_sitennou_9_000
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+33
	.byte		N06   , An2 
	.byte	W06
	.byte		PAN   , c_v-47
	.byte		N06   , An1 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N03   , An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-47
	.byte		N06   , An1 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , An2 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-43
	.byte		N06   , An1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v+35
	.byte		N06   , An2 
	.byte	W24
	.byte	GOTO
	 .word	mus_sitennou_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_sitennou:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_sitennou_pri	@ Priority
	.byte	mus_sitennou_rev	@ Reverb.

	.word	mus_sitennou_grp

	.word	mus_sitennou_1
	.word	mus_sitennou_2
	.word	mus_sitennou_3
	.word	mus_sitennou_4
	.word	mus_sitennou_5
	.word	mus_sitennou_6
	.word	mus_sitennou_7
	.word	mus_sitennou_8
	.word	mus_sitennou_9

	.end
