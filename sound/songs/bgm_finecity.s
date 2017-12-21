	.include "MPlayDef.s"

	.equ	bgm_finecity_grp, voicegroup_868D074
	.equ	bgm_finecity_pri, 0
	.equ	bgm_finecity_rev, reverb_set+50
	.equ	bgm_finecity_mvl, 127
	.equ	bgm_finecity_key, 0
	.equ	bgm_finecity_tbs, 1
	.equ	bgm_finecity_exg, 0
	.equ	bgm_finecity_cmp, 1

	.section .rodata
	.global	bgm_finecity
	.align	2

@********************** Track  1 **********************@

bgm_finecity_1:
	.byte	KEYSH , bgm_finecity_key+0
	.byte	TEMPO , 124*bgm_finecity_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 41*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_1_B1:
bgm_finecity_1_000:
	.byte	W12
	.byte		N03   , Gn5 , v064
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
bgm_finecity_1_001:
	.byte		N03   , Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v072
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_1_001
bgm_finecity_1_002:
	.byte		N03   , Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v072
	.byte	W12
	.byte		        Gn5 , v080
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
bgm_finecity_1_003:
	.byte		N03   , Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v072
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_001
bgm_finecity_1_004:
	.byte		N03   , Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W24
	.byte		        Gn5 , v072
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte		N03   , Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v092
	.byte	W18
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v072
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v076
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v088
	.byte	W18
	.byte		        Gn5 , v072
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte	PATT
	 .word	bgm_finecity_1_004
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_002
	.byte	PATT
	 .word	bgm_finecity_1_003
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_001
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	PATT
	 .word	bgm_finecity_1_000
	.byte	GOTO
	 .word	bgm_finecity_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_finecity_2:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 68*bgm_finecity_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W48
bgm_finecity_2_B1:
	.byte		VOICE , 14
	.byte		VOL   , 68*bgm_finecity_mvl/mxv
	.byte		N36   , Fs4 , v112
	.byte	W24
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An3 
	.byte	W24
bgm_finecity_2_000:
	.byte		N24   , Fs4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte	PEND
bgm_finecity_2_001:
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte	PEND
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 52*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 51*bgm_finecity_mvl/mxv
	.byte	W36
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W12
	.byte	W12
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W24
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N30   , An4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N96   , An4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W72
	.byte		VOICE , 73
	.byte		MOD   , 0
	.byte	W48
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Cs5 
	.byte	W24
	.byte		N06   , En5 
	.byte	W12
	.byte		N42   , Fs5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        44*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        41*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        39*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        39*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        36*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        34*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        31*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N24   , Fs5 
	.byte	W24
	.byte		        En5 
	.byte	W24
	.byte		        Fs5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Gn5 
	.byte	W18
	.byte		N06   , Fs5 
	.byte	W18
	.byte		N48   , En5 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        43*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        41*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        39*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        37*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        36*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        34*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        31*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 30*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        28*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        28*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        46*bgm_finecity_mvl/mxv
	.byte		N12   , Gn5 
	.byte	W18
	.byte		N06   , Fs5 
	.byte	W18
	.byte		N48   , En5 
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        44*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        41*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        39*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        37*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        35*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        31*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        30*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        28*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N78   , En5 
	.byte	W06
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        45*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        44*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        43*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        41*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        41*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        39*bgm_finecity_mvl/mxv
	.byte	W06
	.byte		        36*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        36*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        34*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        34*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        33*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        31*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        28*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        28*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W06
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        20*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		VOICE , 14
	.byte		MOD   , 0
	.byte		VOL   , 63*bgm_finecity_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N24   , An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		VOICE , 14
	.byte		VOL   , 70*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	PATT
	 .word	bgm_finecity_2_000
	.byte	PATT
	 .word	bgm_finecity_2_001
	.byte		VOICE , 48
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 24
	.byte		VOL   , 55*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	PATT
	 .word	bgm_finecity_2_000
	.byte	PATT
	 .word	bgm_finecity_2_001
	.byte		VOICE , 48
	.byte		VOL   , 48*bgm_finecity_mvl/mxv
	.byte		N24   , Gn4 , v112
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		VOICE , 24
	.byte		VOL   , 57*bgm_finecity_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v+16
	.byte		VOL   , 48*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*bgm_finecity_mvl/mxv
	.byte	W48
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W36
	.byte		N36   , As4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N72   , Bn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte	W24
	.byte	W48
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W36
	.byte		N12   , Cn5 
	.byte	W12
	.byte		MOD   , 4
	.byte		N06   , Bn4 
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , An4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOL   , 52*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		VOICE , 48
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte	GOTO
	 .word	bgm_finecity_2_B1
	.byte		VOL   , 42*bgm_finecity_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	FINE

@********************** Track  3 **********************@

bgm_finecity_3:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 24
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W48
bgm_finecity_3_B1:
	.byte		VOICE , 24
	.byte		PAN   , c_v-16
	.byte		VOL   , 45*bgm_finecity_mvl/mxv
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v060
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v064
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+23
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v060
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		PAN   , c_v+21
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		PAN   , c_v-21
	.byte		N06   , Gs2 , v076
	.byte	W06
	.byte		        An2 , v080
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		PAN   , c_v+21
	.byte		N06   , Cs3 , v076
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        An3 , v088
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		PAN   , c_v-16
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
	.byte		VOL   , 49*bgm_finecity_mvl/mxv
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v060
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v064
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+21
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v060
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        An2 , v076
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , Cs3 , v072
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		VOL   , 49*bgm_finecity_mvl/mxv
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v060
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v064
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v060
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W06
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , An3 , v064
	.byte	W06
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 45
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 24
	.byte		VOL   , 52*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		PAN   , c_v-26
	.byte		N06   , Bn2 , v072
	.byte	W06
	.byte		        Dn3 , v076
	.byte	W06
	.byte		        Gn3 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , Gn3 , v068
	.byte	W06
	.byte		        An3 , v076
	.byte	W06
	.byte		        Dn4 , v080
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 73
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , Ds4 , v060
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , Ds4 , v064
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		N03   , En4 , v060
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Bn3 , v064
	.byte	W06
	.byte		VOICE , 24
	.byte		VOL   , 52*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        An2 , v076
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		PAN   , c_v+20
	.byte		N06   , Cs3 , v072
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_finecity_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_finecity_4:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+16
	.byte		VOL   , 37*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 17
	.byte	W36
	.byte		N03   , Bn4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , As4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W12
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Cn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W24
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N30   , Gn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N30   , Dn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		PAN   , c_v+24
	.byte		MOD   , 0
	.byte		VOL   , 31*bgm_finecity_mvl/mxv
	.byte	W48
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N24   , Cs5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , An4 
	.byte	W12
	.byte		N42   , Cn5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 28*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        27*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        25*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		        21*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        13*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        12*bgm_finecity_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 31*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N03   , Ds5 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N24   , Ds5 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        An4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		MOD   , 0
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+24
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		N78   , An5 , v060
	.byte	W06
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 31*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        27*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        25*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        21*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        16*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        15*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        13*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        12*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_finecity_mvl/mxv
	.byte		N06   , An5 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W12
	.byte		N12   , En5 
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_finecity_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_finecity_5:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 44*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_5_B1:
bgm_finecity_5_000:
	.byte		N06   , En5 , v112
	.byte	W24
	.byte		        En5 , v080
	.byte	W24
	.byte		        En5 , v112
	.byte	W24
	.byte		        En5 , v088
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , En5 , v112
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		        En5 , v092
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte	W96
	.byte	W12
	.byte		        En5 , v092
	.byte	W84
	.byte	W60
	.byte		        En5 , v096
	.byte	W36
	.byte	W60
	.byte		N12   
	.byte	W24
	.byte		        En5 , v112
	.byte	W12
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , En5 , v112
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	PATT
	 .word	bgm_finecity_5_000
	.byte	GOTO
	 .word	bgm_finecity_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_finecity_6:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W48
bgm_finecity_6_B1:
	.byte		VOICE , 83
	.byte	W06
	.byte		N24   , Fs5 , v084
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N30   , Fs5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte	W06
	.byte		VOICE , 80
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		VOICE , 80
	.byte		BEND  , c_v+0
	.byte		N30   , Gn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , En3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N36   
	.byte	W09
	.byte		MOD   , 3
	.byte	W24
	.byte	W03
	.byte		N03   , Fs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , An3 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W12
	.byte		MOD   , 3
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Gn3 
	.byte		N03   , Bn3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		MOD   , 3
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		MOD   , 3
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		MOD   , 3
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   
	.byte	W24
	.byte		MOD   , 3
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Cs4 
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		N03   , An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , En3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N84   , Gn3 
	.byte	W24
	.byte		MOD   , 3
	.byte	W60
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N48   , An3 
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		MOD   , 0
	.byte		N84   
	.byte	W24
	.byte		MOD   , 3
	.byte	W60
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N48   , Fs3 
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		N24   , En3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
bgm_finecity_6_000:
	.byte		MOD   , 0
	.byte		N96   , En4 , v112
	.byte	W24
	.byte		MOD   , 3
	.byte	W72
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_6_000
	.byte		MOD   , 0
	.byte		N96   , Gn4 , v112
	.byte	W24
	.byte		MOD   , 3
	.byte	W48
	.byte		        5
	.byte	W24
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		N06   , En3 
	.byte	W12
	.byte		        En3 , v036
	.byte	W12
	.byte		        En3 , v112
	.byte	W12
	.byte		        En3 , v036
	.byte	W12
	.byte		        En3 , v112
	.byte	W12
	.byte		        En3 , v036
	.byte	W12
	.byte		        En3 , v112
	.byte	W12
	.byte		        En3 , v036
	.byte	W12
	.byte		N24   , Fs4 , v112
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		VOICE , 80
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		VOICE , 83
	.byte		N24   , Fs5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		VOICE , 80
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		        29*bgm_finecity_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W03
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        26*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        22*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		VOICE , 80
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte		N84   , Dn4 
	.byte	W84
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N96   , Cn4 
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		VOICE , 83
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 80
	.byte		N84   , Dn4 
	.byte	W84
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N96   , En4 
	.byte	W96
	.byte		        Cn4 
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		VOICE , 83
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Cs5 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , Dn4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte		        35*bgm_finecity_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 32*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        24*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        29*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        19*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        23*bgm_finecity_mvl/mxv
	.byte	W02
	.byte		        14*bgm_finecity_mvl/mxv
	.byte	W01
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W03
	.byte	GOTO
	 .word	bgm_finecity_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_finecity_7:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 39
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_7_B1:
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		N12   , Dn2 , v036
	.byte	W18
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Fs1 
	.byte	W06
bgm_finecity_7_000:
	.byte		N30   , Gn1 , v112
	.byte	W30
	.byte		N06   , Gn1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		N30   , Fs1 , v112
	.byte	W30
	.byte		N06   , Fs1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte	PEND
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N24   , En1 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
bgm_finecity_7_001:
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W30
	.byte		N03   , En1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte	PEND
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Gs1 , v096
	.byte	W12
	.byte		N06   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W30
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N24   , Fs1 , v112
	.byte	W24
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W30
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Fn1 , v096
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W30
	.byte		N03   , En1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N18   , Dn1 , v112
	.byte	W18
	.byte		N06   , Dn1 , v036
	.byte	W06
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W30
	.byte		N03   , En1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An1 
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		N18   , An1 , v112
	.byte	W18
	.byte		N06   , An1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v036
	.byte	W30
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N06   , Dn2 , v036
	.byte	W12
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_finecity_7_001
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		N18   , An1 , v112
	.byte	W18
	.byte		N06   , An1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W30
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N18   , Fs1 , v112
	.byte	W18
	.byte		N06   , Fs1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W30
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N24   , Fs1 , v112
	.byte	W24
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		        Cn2 , v120
	.byte	W12
	.byte		N09   , Cn2 , v096
	.byte	W12
	.byte		N06   , Cn2 , v120
	.byte	W12
	.byte		N09   , Cn2 , v096
	.byte	W12
	.byte		N06   , Cn2 , v120
	.byte	W12
	.byte		N09   , Cn2 , v096
	.byte	W12
	.byte		N06   , Bn2 , v112
	.byte	W06
	.byte		        Cn3 , v120
	.byte	W06
	.byte		N09   , Cn2 , v096
	.byte	W12
	.byte		N06   , Cs2 , v120
	.byte	W12
	.byte		N09   , Cs2 , v096
	.byte	W12
	.byte		N06   , Cs2 , v120
	.byte	W12
	.byte		N09   , Cs2 , v096
	.byte	W12
	.byte		N06   , Cs2 , v120
	.byte	W12
	.byte		N09   , Cs2 , v096
	.byte	W12
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Cs3 , v120
	.byte	W06
	.byte		N12   , Bn2 , v096
	.byte	W12
	.byte		N06   , An2 , v120
	.byte	W12
	.byte		N09   , An2 , v096
	.byte	W12
	.byte		N06   , An2 , v120
	.byte	W12
	.byte		N09   , An2 , v096
	.byte	W12
	.byte		N06   , An2 , v120
	.byte	W12
	.byte		N09   , An2 , v096
	.byte	W12
	.byte		N06   , An2 , v120
	.byte	W12
	.byte		N09   , An2 , v096
	.byte	W12
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		        An2 , v036
	.byte	W18
	.byte		        An2 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte	PATT
	 .word	bgm_finecity_7_000
	.byte		N06   , Gs1 , v112
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		N24   , Cs2 , v112
	.byte	W24
	.byte		N06   , An1 
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		N24   , An1 , v112
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W18
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		N24   , Fs1 , v112
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N24   , En1 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N24   , En1 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N18   , An1 
	.byte	W18
	.byte		N06   , An1 , v036
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		N24   , Gn1 , v112
	.byte	W24
	.byte		        Gs1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W30
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		N12   , Fn1 , v112
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W06
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v036
	.byte	W06
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W30
	.byte		N03   , Gs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		        Ds1 , v112
	.byte	W06
	.byte		        Ds1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W30
	.byte		N03   , Gn1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v036
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v036
	.byte	W30
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn1 , v036
	.byte	W06
	.byte		N12   , Fn1 , v112
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W18
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v036
	.byte	W30
	.byte		N03   , Cn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , An1 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , An1 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , An1 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , An2 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , An1 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , An1 , v120
	.byte	W12
	.byte		N09   , An1 , v096
	.byte	W12
	.byte		N06   , Dn2 , v120
	.byte	W12
	.byte		N12   , Dn2 , v096
	.byte	W12
	.byte		N06   , Dn3 , v120
	.byte	W12
	.byte		N12   , Cn3 , v096
	.byte	W12
	.byte		N30   , En2 , v112
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		        En2 , v036
	.byte	W06
	.byte		N30   , Ds2 , v112
	.byte	W30
	.byte		N06   , Ds2 , v036
	.byte	W06
	.byte		        Ds2 , v112
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		N30   , Cs2 , v112
	.byte	W30
	.byte		N06   , Cs2 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		N30   , Bn1 , v112
	.byte	W30
	.byte		N06   , Bn1 , v036
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		N30   , An1 , v112
	.byte	W30
	.byte		N06   , An1 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		N30   , Gs1 , v112
	.byte	W30
	.byte		N06   , Gs1 , v036
	.byte	W06
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Fs2 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		N24   , Fs1 , v112
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte	GOTO
	 .word	bgm_finecity_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_finecity_8:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*bgm_finecity_mvl/mxv
	.byte		N06   , Cn1 , v127
	.byte		N42   , An2 , v060
	.byte	W12
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 , v124
	.byte	W06
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
bgm_finecity_8_B1:
	.byte		VOL   , 63*bgm_finecity_mvl/mxv
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v096
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
bgm_finecity_8_000:
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v092
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte	PEND
bgm_finecity_8_001:
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v096
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte	PEND
	.byte		N06   
	.byte		N48   , An2 , v096
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte		N36   , An2 , v096
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
bgm_finecity_8_002:
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_8_002
	.byte	PATT
	 .word	bgm_finecity_8_002
	.byte	PATT
	 .word	bgm_finecity_8_002
	.byte	PATT
	 .word	bgm_finecity_8_002
	.byte	PATT
	 .word	bgm_finecity_8_002
	.byte		N06   , Cn1 , v120
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N48   , An2 , v080
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 , v124
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        Cn1 , v120
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N06   
	.byte	W12
bgm_finecity_8_003:
	.byte		N06   , En1 , v120
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_8_003
	.byte		N06   , En1 , v124
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
bgm_finecity_8_004:
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v088
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_8_000
	.byte	PATT
	 .word	bgm_finecity_8_001
bgm_finecity_8_005:
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v092
	.byte	W24
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_8_004
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v088
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_finecity_8_004
	.byte	PATT
	 .word	bgm_finecity_8_005
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v088
	.byte	W24
	.byte		N06   , Cn1 , v127
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N48   , An2 , v088
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N24   , An2 , v060
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
bgm_finecity_8_006:
	.byte		N06   , Cn1 , v120
	.byte	W18
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte	PEND
	.byte		        Cn1 , v120
	.byte	W18
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 , v092
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W18
	.byte		        Cn1 , v120
	.byte	W18
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		        En1 , v120
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	bgm_finecity_8_006
	.byte		N06   , Cn1 , v120
	.byte	W18
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W24
	.byte		N06   
	.byte	W18
	.byte		N03   , Dn1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte	PATT
	 .word	bgm_finecity_8_004
	.byte		N06   , En1 , v112
	.byte		N48   , An2 , v088
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N48   , An2 , v092
	.byte	W24
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En1 , v112
	.byte		N24   , Gn2 , v080
	.byte	W12
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N48   , An2 , v092
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte		N24   , An2 , v056
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte	GOTO
	 .word	bgm_finecity_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_finecity_9:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_9_B1:
bgm_finecity_9_000:
	.byte		VOICE , 6
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Cs5 , v060
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte	PEND
bgm_finecity_9_001:
	.byte		N06   , Fs5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Cs5 , v064
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v060
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte	PEND
bgm_finecity_9_002:
	.byte		N06   , Fs5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		N06   , Fs5 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		N03   , An4 , v064
	.byte	W06
	.byte	PEND
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N12   , Bn2 , v112
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		VOICE , 5
	.byte		PAN   , c_v+63
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N30   , Bn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   , As3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W09
	.byte		MOD   , 5
	.byte	W24
	.byte	W03
	.byte		N03   , Bn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N03   , Cn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 3
	.byte	W24
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N06   , Fs4 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		MOD   , 4
	.byte		N03   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W12
	.byte		MOD   , 4
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , An3 
	.byte	W12
	.byte		MOD   , 4
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N03   , En4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N24   , Fn4 
	.byte	W24
	.byte		MOD   , 5
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , En4 
	.byte	W24
	.byte		MOD   , 4
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N84   , Bn3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W60
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		N24   , En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		MOD   , 0
	.byte		N84   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W60
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N48   , Bn3 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
bgm_finecity_9_003:
	.byte		MOD   , 0
	.byte		N96   , Gn4 , v112
	.byte	W24
	.byte		MOD   , 3
	.byte	W72
	.byte	PEND
	.byte	PATT
	 .word	bgm_finecity_9_003
	.byte		MOD   , 0
	.byte		N96   , An4 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W72
	.byte		        0
	.byte		N06   
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		VOICE , 6
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Cs5 , v060
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		N03   , Dn5 , v064
	.byte	W06
	.byte		N06   , An5 , v112
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte	PATT
	 .word	bgm_finecity_9_001
	.byte	PATT
	 .word	bgm_finecity_9_002
	.byte		VOICE , 81
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N24   , Bn2 , v112
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte	PATT
	 .word	bgm_finecity_9_000
	.byte	PATT
	 .word	bgm_finecity_9_001
	.byte	PATT
	 .word	bgm_finecity_9_002
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte		N24   , Bn2 , v112
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		VOICE , 5
	.byte		PAN   , c_v+63
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte		N84   , Fn4 
	.byte	W84
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N96   , En4 
	.byte	W96
	.byte		        Ds4 
	.byte	W96
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N84   , Fn4 
	.byte	W84
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N96   , Gn4 
	.byte	W96
	.byte		        En4 
	.byte	W96
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		VOICE , 6
	.byte		VOL   , 35*bgm_finecity_mvl/mxv
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , Ds5 , v060
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , Ds5 , v064
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N06   , Cs6 , v112
	.byte	W06
	.byte		N03   , En5 , v060
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N06   , Bn5 , v112
	.byte	W06
	.byte		N03   , En5 
	.byte	W06
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		N06   , Fs5 , v112
	.byte	W06
	.byte		N03   , En5 , v064
	.byte	W06
	.byte		N06   , Gs5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		N06   , Fs5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		N06   , Cs5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Bn4 , v064
	.byte	W06
	.byte		VOICE , 81
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte	W12
	.byte		N12   , Cs4 , v112
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_finecity_9_B1
	.byte	FINE

@********************** Track 10 **********************@

bgm_finecity_10:
	.byte	KEYSH , bgm_finecity_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*bgm_finecity_mvl/mxv
	.byte	W48
bgm_finecity_10_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte		N48   , En3 , v112
	.byte	W48
	.byte		VOICE , 24
	.byte		VOL   , 40*bgm_finecity_mvl/mxv
	.byte		N06   , En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W48
	.byte		VOICE , 24
	.byte		VOL   , 41*bgm_finecity_mvl/mxv
	.byte		N06   , An4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte		N06   , Gn5 
	.byte	W24
	.byte		VOICE , 48
	.byte		N24   , En3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N36   , Ds3 
	.byte	W12
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W48
	.byte		N96   , Dn3 
	.byte	W96
	.byte		N48   , Cs3 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		N44   , An3 
	.byte	W48
	.byte		N48   , Gn3 
	.byte	W48
	.byte		VOL   , 28*bgm_finecity_mvl/mxv
	.byte		N48   , An3 , v104
	.byte	W48
	.byte		VOICE , 24
	.byte		VOL   , 44*bgm_finecity_mvl/mxv
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		VOL   , 31*bgm_finecity_mvl/mxv
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 36*bgm_finecity_mvl/mxv
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		VOICE , 24
	.byte		VOL   , 42*bgm_finecity_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+22
	.byte		N06   , En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
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
	.byte		VOICE , 73
	.byte		VOL   , 29*bgm_finecity_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+1
	.byte	W48
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		N06   , Cn5 
	.byte	W36
	.byte		N36   , As4 
	.byte	W18
	.byte		VOL   , 22*bgm_finecity_mvl/mxv
	.byte	W06
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        13*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        26*bgm_finecity_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N72   , Bn4 
	.byte	W24
	.byte		VOL   , 26*bgm_finecity_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 22*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        21*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        17*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        13*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        11*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        8*bgm_finecity_mvl/mxv
	.byte	W05
	.byte		        4*bgm_finecity_mvl/mxv
	.byte	W07
	.byte		        29*bgm_finecity_mvl/mxv
	.byte		MOD   , 2
	.byte	W24
	.byte	W48
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N24   , En5 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W36
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N06   , Cn5 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOL   , 46*bgm_finecity_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_finecity_10_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_finecity:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_finecity_pri	@ Priority
	.byte	bgm_finecity_rev	@ Reverb.

	.word	bgm_finecity_grp

	.word	bgm_finecity_1
	.word	bgm_finecity_2
	.word	bgm_finecity_3
	.word	bgm_finecity_4
	.word	bgm_finecity_5
	.word	bgm_finecity_6
	.word	bgm_finecity_7
	.word	bgm_finecity_8
	.word	bgm_finecity_9
	.word	bgm_finecity_10

	.end
