	.include "MPlayDef.s"

	.equ	mus_hageshii_grp, voicegroup_8686A74
	.equ	mus_hageshii_pri, 0
	.equ	mus_hageshii_rev, reverb_set+50
	.equ	mus_hageshii_mvl, 127
	.equ	mus_hageshii_key, 0
	.equ	mus_hageshii_tbs, 1
	.equ	mus_hageshii_exg, 0
	.equ	mus_hageshii_cmp, 1

	.section .rodata
	.global	mus_hageshii
	.align	2

@********************** Track  1 **********************@

mus_hageshii_1:
	.byte	KEYSH , mus_hageshii_key+0
	.byte	TEMPO , 140*mus_hageshii_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 50*mus_hageshii_mvl/mxv
	.byte	W24
mus_hageshii_1_B1:
mus_hageshii_1_000:
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v064
	.byte	W12
	.byte	PEND
mus_hageshii_1_001:
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W12
	.byte		N06   , En4 , v060
	.byte	W12
	.byte		N12   , En4 , v112
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_hageshii_1_000
mus_hageshii_1_002:
	.byte	W72
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_hageshii_1_000
	.byte	PATT
	 .word	mus_hageshii_1_001
	.byte	PATT
	 .word	mus_hageshii_1_000
	.byte	PATT
	 .word	mus_hageshii_1_002
	.byte	GOTO
	 .word	mus_hageshii_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_hageshii_2:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 67*mus_hageshii_mvl/mxv
	.byte	W24
mus_hageshii_2_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn4 , v108
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn4 , v112
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn4 , v108
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		        Gn4 , v112
	.byte	W12
	.byte	GOTO
	 .word	mus_hageshii_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_hageshii_3:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 78*mus_hageshii_mvl/mxv
	.byte	W24
mus_hageshii_3_B1:
	.byte		BEND  , c_v-2
	.byte		N08   , Fn1 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v-14
	.byte		N08   , Cn2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v-21
	.byte		N08   , Fn1 
	.byte	W03
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N06   , Fn0 
	.byte	W06
	.byte		BEND  , c_v-2
	.byte		N08   , Fn1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v+18
	.byte		N08   , Cn2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v+24
	.byte		N08   , Fn1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N06   , Fn0 
	.byte	W06
	.byte		BEND  , c_v-2
	.byte		N08   , Fn1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v-14
	.byte		N08   , Cn1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , Ds1 
	.byte	W06
	.byte		N08   , Fn1 
	.byte	W12
	.byte		N02   , Ds1 
	.byte	W06
	.byte		BEND  , c_v-21
	.byte		N08   , Fn1 
	.byte	W03
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N06   , Fn0 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-22
	.byte	W03
	.byte		        c_v-44
	.byte	W04
	.byte		        c_v-2
	.byte		N08   , Fs1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v-14
	.byte		N08   , Cs2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v-21
	.byte		N08   , Fs1 
	.byte	W03
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   , Fs0 
	.byte	W06
	.byte		BEND  , c_v-2
	.byte		N08   , Fs1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v+18
	.byte		N08   , Cs2 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v+24
	.byte		N08   , Fs1 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   , Fs0 
	.byte	W06
	.byte		BEND  , c_v-2
	.byte		N08   , Fs1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v-14
	.byte		N08   , Cs1 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 11
	.byte	W06
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		MOD   , 2
	.byte		N02   , En1 
	.byte	W06
	.byte		N08   , Fs1 
	.byte	W12
	.byte		N02   , En1 
	.byte	W06
	.byte		BEND  , c_v-21
	.byte		N08   , Fs1 
	.byte	W03
	.byte		BEND  , c_v+14
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N03   , Cs1 
	.byte	W06
	.byte		N06   , Fs0 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W02
	.byte		        c_v-22
	.byte	W03
	.byte		        c_v-44
	.byte	W04
	.byte	GOTO
	 .word	mus_hageshii_3_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  4 **********************@

mus_hageshii_4:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 70
	.byte		VOL   , 68*mus_hageshii_mvl/mxv
	.byte		PAN   , c_v-30
	.byte	W18
	.byte		BENDR , 12
	.byte	W06
mus_hageshii_4_B1:
	.byte		VOL   , 68*mus_hageshii_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , Gs2 , v112
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 16
	.byte		BEND  , c_v-64
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N09   , Cn2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , Gs2 
	.byte	W24
	.byte		MOD   , 16
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte	W06
	.byte		N09   , Cn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        En2 , v092
	.byte	W06
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Cn2 
	.byte	W06
	.byte		N03   , Cn2 , v064
	.byte	W06
	.byte		        Cn2 , v080
	.byte	W06
	.byte		        Cn2 , v064
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N18   , Gs2 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 16
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N03   , En2 
	.byte	W06
	.byte		        En2 , v072
	.byte	W06
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W12
	.byte		VOL   , 65*mus_hageshii_mvl/mxv
	.byte		N06   , Gn2 
	.byte	W02
	.byte		VOL   , 58*mus_hageshii_mvl/mxv
	.byte	W03
	.byte		        51*mus_hageshii_mvl/mxv
	.byte	W01
	.byte		N06   , Gs2 
	.byte	W02
	.byte		VOL   , 47*mus_hageshii_mvl/mxv
	.byte	W04
	.byte		        40*mus_hageshii_mvl/mxv
	.byte		N12   , Fn2 
	.byte	W02
	.byte		VOL   , 25*mus_hageshii_mvl/mxv
	.byte	W03
	.byte		        1*mus_hageshii_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v-62
	.byte	W03
	.byte		VOL   , 68*mus_hageshii_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , An2 
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 16
	.byte		BEND  , c_v-64
	.byte	W12
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N09   , Cs2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W12
	.byte		VOL   , 68*mus_hageshii_mvl/mxv
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fn2 , v072
	.byte	W06
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , An2 
	.byte	W24
	.byte		MOD   , 16
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte	W06
	.byte		N09   , Cs2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W12
	.byte		N03   , Fs2 
	.byte	W06
	.byte		        Fn2 , v092
	.byte	W06
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , Cs2 , v064
	.byte	W06
	.byte		        Cs2 , v080
	.byte	W06
	.byte		        Cs2 , v064
	.byte	W06
	.byte		BEND  , c_v-16
	.byte		N18   , An2 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 16
	.byte	W06
	.byte		        0
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N06   , En2 
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W06
	.byte		        Fn2 , v072
	.byte	W06
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		VOL   , 65*mus_hageshii_mvl/mxv
	.byte		N06   , Gs2 
	.byte	W02
	.byte		VOL   , 58*mus_hageshii_mvl/mxv
	.byte	W03
	.byte		        51*mus_hageshii_mvl/mxv
	.byte	W01
	.byte		N06   , An2 
	.byte	W02
	.byte		VOL   , 47*mus_hageshii_mvl/mxv
	.byte	W04
	.byte		        40*mus_hageshii_mvl/mxv
	.byte		N12   , Fs2 
	.byte	W02
	.byte		VOL   , 25*mus_hageshii_mvl/mxv
	.byte	W03
	.byte		        1*mus_hageshii_mvl/mxv
	.byte	W04
	.byte		BEND  , c_v-62
	.byte	W03
	.byte	GOTO
	 .word	mus_hageshii_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_hageshii_5:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v-62
	.byte		VOL   , 53*mus_hageshii_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W18
	.byte		BENDR , 12
	.byte	W06
mus_hageshii_5_B1:
	.byte		BEND  , c_v+0
	.byte		N03   , Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v088
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Fn3 , v076
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		N01   , Fn3 , v084
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        Fn3 , v088
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v056
	.byte	W06
	.byte		        Ds3 , v100
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W12
	.byte		        Fn3 , v088
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Ds3 , v096
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v052
	.byte	W06
	.byte		        Fn3 , v076
	.byte	W06
	.byte		        Fn3 , v044
	.byte	W06
	.byte		N96   , Fn5 , v092
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v-4
	.byte	W09
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v-7
	.byte	W09
	.byte		        c_v-8
	.byte	W15
	.byte		        c_v-12
	.byte	W09
	.byte		        c_v-13
	.byte	W09
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-24
	.byte	W06
	.byte		        c_v-26
	.byte	W06
	.byte		        c_v-31
	.byte	W06
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte		        c_v+0
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		N04   , Fs3 , v112
	.byte	W04
	.byte		N01   , Fs3 , v084
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N03   , En3 , v112
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v056
	.byte	W06
	.byte		        En3 , v100
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W12
	.byte		        Fs3 , v088
	.byte	W06
	.byte		        Fs3 , v040
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        En3 , v096
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W06
	.byte		        Fs3 , v052
	.byte	W06
	.byte		        Fs3 , v076
	.byte	W06
	.byte		        Fs3 , v044
	.byte	W06
	.byte		N96   , Fs5 , v092
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v-4
	.byte	W09
	.byte		        c_v-5
	.byte	W06
	.byte		        c_v-7
	.byte	W09
	.byte		        c_v-8
	.byte	W15
	.byte		        c_v-12
	.byte	W09
	.byte		        c_v-13
	.byte	W09
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-24
	.byte	W06
	.byte		        c_v-26
	.byte	W06
	.byte		        c_v-31
	.byte	W06
	.byte		        c_v-39
	.byte	W03
	.byte		        c_v-50
	.byte	W03
	.byte	GOTO
	 .word	mus_hageshii_5_B1
	.byte		BEND  , c_v+0
	.byte	FINE

@********************** Track  6 **********************@

mus_hageshii_6:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+63
	.byte		VOL   , 37*mus_hageshii_mvl/mxv
	.byte		BENDR , 12
	.byte		BEND  , c_v+2
	.byte	W24
mus_hageshii_6_B1:
	.byte		BEND  , c_v+2
	.byte		N36   , Fn3 , v112
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 11
	.byte		BEND  , c_v-63
	.byte	W12
	.byte		        c_v+1
	.byte	W06
	.byte		N09   , Gs2 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , Fn3 
	.byte	W24
	.byte		BEND  , c_v+2
	.byte	W18
	.byte		N09   , Gs2 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Bn2 , v092
	.byte	W06
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   , Fn2 , v064
	.byte	W06
	.byte		        Fn2 , v092
	.byte	W06
	.byte		        Fn2 , v064
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v-14
	.byte		N18   , Fn3 , v112
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		N03   , Cn3 
	.byte	W06
	.byte		MOD   , 2
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N06   , As2 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W06
	.byte		        Bn2 , v072
	.byte	W06
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte	W06
	.byte		        c_v+2
	.byte		N36   , Fs3 
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 11
	.byte		BEND  , c_v-63
	.byte	W12
	.byte		        c_v+1
	.byte	W06
	.byte		N09   , An2 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+2
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Cn3 , v072
	.byte	W06
	.byte		N06   , Cs3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , Fs3 
	.byte	W24
	.byte		BEND  , c_v+2
	.byte	W18
	.byte		N09   , An2 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Cn3 , v092
	.byte	W06
	.byte		N06   , Cs3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v092
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v-14
	.byte		N18   , Fs3 , v112
	.byte	W03
	.byte		BEND  , c_v+2
	.byte	W15
	.byte		N03   , Cs3 
	.byte	W06
	.byte		MOD   , 2
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N03   , Cn3 
	.byte	W06
	.byte		        Cn3 , v072
	.byte	W06
	.byte		N06   , Cs3 , v112
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		BEND  , c_v+2
	.byte		N06   
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , An2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte	W06
	.byte	GOTO
	 .word	mus_hageshii_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_hageshii_7:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 0
	.byte		VOL   , 76*mus_hageshii_mvl/mxv
	.byte		N04   , En1 , v112
	.byte		N04   , Fs2 
	.byte	W04
	.byte		        En1 , v084
	.byte		N04   , Fs2 , v052
	.byte	W04
	.byte		        En1 , v084
	.byte		N04   , Fs2 , v052
	.byte	W04
	.byte		N06   , Dn1 , v112
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v044
	.byte	W06
mus_hageshii_7_B1:
mus_hageshii_7_000:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v072
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte	PEND
mus_hageshii_7_001:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte	PEND
mus_hageshii_7_002:
	.byte		N06   , Cn1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v112
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Cn1 , v084
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Fs2 , v048
	.byte	W06
	.byte		        Dn1 , v120
	.byte		N06   , Fs2 , v076
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte	PEND
mus_hageshii_7_003:
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte		N18   , An2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N18   , An2 , v080
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte		N18   , An2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Dn1 
	.byte		N12   , An2 , v080
	.byte	W06
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Fs1 , v112
	.byte		N24   , An2 
	.byte	W06
	.byte		N06   , Fs1 , v080
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_hageshii_7_000
	.byte	PATT
	 .word	mus_hageshii_7_001
	.byte	PATT
	 .word	mus_hageshii_7_002
	.byte	PATT
	 .word	mus_hageshii_7_003
	.byte	GOTO
	 .word	mus_hageshii_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_hageshii_8:
	.byte	KEYSH , mus_hageshii_key+0
	.byte		VOICE , 29
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*mus_hageshii_mvl/mxv
	.byte	W24
mus_hageshii_8_B1:
	.byte		BEND  , c_v+0
	.byte		N36   , Fn2 , v112
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 11
	.byte		BEND  , c_v-63
	.byte	W12
	.byte		        c_v+0
	.byte	W06
	.byte		N09   , Gs1 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Bn1 , v072
	.byte	W06
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , Fn2 
	.byte	W24
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W18
	.byte		N09   , Gs1 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Bn1 , v092
	.byte	W06
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Fn1 
	.byte	W06
	.byte		N03   , Fn1 , v064
	.byte	W06
	.byte		        Fn1 , v092
	.byte	W06
	.byte		        Fn1 , v064
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v-14
	.byte		N18   , Fn2 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		N03   , Cn2 
	.byte	W06
	.byte		MOD   , 2
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   , As1 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        Bn1 , v072
	.byte	W06
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte	W06
	.byte		        c_v+0
	.byte		N36   , Fs2 
	.byte	W18
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		        c_v-40
	.byte	W04
	.byte		MOD   , 11
	.byte		BEND  , c_v-63
	.byte	W12
	.byte		        c_v+0
	.byte	W06
	.byte		N09   , An1 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Cn2 , v072
	.byte	W06
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte		N36   , Fs2 
	.byte	W24
	.byte		MOD   , 11
	.byte		BEND  , c_v+0
	.byte	W18
	.byte		N09   , An1 
	.byte	W06
	.byte		MOD   , 2
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W06
	.byte		        Cn2 , v092
	.byte	W06
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N03   , Fs1 , v064
	.byte	W06
	.byte		        Fs1 , v092
	.byte	W06
	.byte		        Fs1 , v064
	.byte	W06
	.byte		MOD   , 11
	.byte		BEND  , c_v-14
	.byte		N18   , Fs2 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		N03   , Cs2 
	.byte	W06
	.byte		MOD   , 2
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N03   , Cn2 
	.byte	W06
	.byte		        Cn2 , v072
	.byte	W06
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N06   
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , An1 
	.byte	W06
	.byte		BEND  , c_v-64
	.byte	W06
	.byte	GOTO
	 .word	mus_hageshii_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_hageshii:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_hageshii_pri	@ Priority
	.byte	mus_hageshii_rev	@ Reverb.

	.word	mus_hageshii_grp

	.word	mus_hageshii_1
	.word	mus_hageshii_2
	.word	mus_hageshii_3
	.word	mus_hageshii_4
	.word	mus_hageshii_5
	.word	mus_hageshii_6
	.word	mus_hageshii_7
	.word	mus_hageshii_8

	.end
