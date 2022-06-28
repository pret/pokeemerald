	.include "MPlayDef.s"

	.equ	mus_weather_kyogre_grp, voicegroup089
	.equ	mus_weather_kyogre_pri, 0
	.equ	mus_weather_kyogre_rev, reverb_set+50
	.equ	mus_weather_kyogre_mvl, 127
	.equ	mus_weather_kyogre_key, 0
	.equ	mus_weather_kyogre_tbs, 1
	.equ	mus_weather_kyogre_exg, 0
	.equ	mus_weather_kyogre_cmp, 1

	.section .rodata
	.global	mus_weather_kyogre
	.align	2

@********************** Track  1 **********************@

mus_weather_kyogre_1:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte	TEMPO , 128*mus_weather_kyogre_tbs/2
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W24
mus_weather_kyogre_1_B1:
mus_weather_kyogre_1_000:
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte		TIE   , As3 , v112
	.byte	W48
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte	W32
	.byte		        11*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        12*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        13*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        14*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte		        15*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte		        17*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        18*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        21*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        25*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        26*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        29*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        32*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        35*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        39*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        41*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 5
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		TIE   , Bn3 
	.byte	W96
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        38*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        36*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        34*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte		        28*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        26*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        24*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        22*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        20*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        18*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        16*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        14*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        12*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , As3 
	.byte	W48
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte	W32
	.byte		        11*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        12*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        13*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        14*mus_weather_kyogre_mvl/mxv
	.byte	W04
mus_weather_kyogre_1_001:
	.byte		VOL   , 15*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte		        17*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        18*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        21*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        25*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        26*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        29*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        32*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        35*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        39*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        41*mus_weather_kyogre_mvl/mxv
	.byte	W48
	.byte	PEND
	.byte		EOT   , As3 
	.byte		TIE   , Bn3 , v112
	.byte	W96
mus_weather_kyogre_1_002:
	.byte	W12
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        38*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        36*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        34*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte		        28*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        26*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        24*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        22*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        20*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        18*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        16*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        14*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        12*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W24
	.byte	PEND
	.byte		EOT   , Bn3 
	.byte	PATT
	 .word	mus_weather_kyogre_1_000
	.byte	PATT
	 .word	mus_weather_kyogre_1_001
	.byte		EOT   , As3 
	.byte		TIE   , Bn3 , v112
	.byte	W96
	.byte	PATT
	 .word	mus_weather_kyogre_1_002
	.byte		EOT   , Bn3 
	.byte	PATT
	 .word	mus_weather_kyogre_1_000
	.byte	PATT
	 .word	mus_weather_kyogre_1_001
	.byte		EOT   , As3 
	.byte		TIE   , Bn3 , v112
	.byte	W96
	.byte	PATT
	 .word	mus_weather_kyogre_1_002
	.byte		EOT   , Bn3 
	.byte	GOTO
	 .word	mus_weather_kyogre_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_weather_kyogre_2:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_weather_kyogre_mvl/mxv
	.byte	W24
mus_weather_kyogre_2_B1:
mus_weather_kyogre_2_000:
	.byte		N02   , Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v072
	.byte	W08
	.byte		        Gn5 , v076
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	PATT
	 .word	mus_weather_kyogre_2_000
	.byte	GOTO
	 .word	mus_weather_kyogre_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_weather_kyogre_3:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-63
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte		N24   , An1 , v112
	.byte	W04
	.byte		VOL   , 47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W08
mus_weather_kyogre_3_B1:
	.byte		VOL   , 60*mus_weather_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
mus_weather_kyogre_3_000:
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		        Ds1 , v064
	.byte	W08
	.byte		        Ds1 , v100
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		N02   , Ds1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Ds1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_weather_kyogre_3_001:
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , En1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , En1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte	PEND
	.byte		N08   
	.byte	W08
	.byte		N04   , En1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v100
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		N02   , En1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-62
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte		N24   
	.byte	W04
	.byte		VOL   , 47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		MOD   , 13
	.byte		VOL   , 61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte		        60*mus_weather_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		MOD   , 2
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte	PATT
	 .word	mus_weather_kyogre_3_000
	.byte	PATT
	 .word	mus_weather_kyogre_3_001
mus_weather_kyogre_3_002:
	.byte		N08   , En1 , v112
	.byte	W08
	.byte		N04   , En1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v100
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		N02   , En1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-62
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte		N24   
	.byte	W04
	.byte		VOL   , 47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W08
	.byte	PEND
mus_weather_kyogre_3_003:
	.byte		VOL   , 60*mus_weather_kyogre_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_weather_kyogre_3_000
	.byte	PATT
	 .word	mus_weather_kyogre_3_001
	.byte	PATT
	 .word	mus_weather_kyogre_3_002
	.byte	PATT
	 .word	mus_weather_kyogre_3_003
	.byte	PATT
	 .word	mus_weather_kyogre_3_000
	.byte	PATT
	 .word	mus_weather_kyogre_3_001
	.byte	PATT
	 .word	mus_weather_kyogre_3_002
	.byte	GOTO
	 .word	mus_weather_kyogre_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_weather_kyogre_4:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N24   , En1 , v112
	.byte	W04
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W04
mus_weather_kyogre_4_B1:
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , Ds3 , v112
	.byte	W48
	.byte		VOL   , 13*mus_weather_kyogre_mvl/mxv
	.byte	W48
mus_weather_kyogre_4_000:
	.byte		VOL   , 20*mus_weather_kyogre_mvl/mxv
	.byte	W24
	.byte		        30*mus_weather_kyogre_mvl/mxv
	.byte	W24
	.byte		        40*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        51*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        60*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        73*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		EOT   , Ds3 
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte		TIE   , Ds3 , v112
	.byte	W48
	.byte		MOD   , 3
	.byte	W12
	.byte		VOL   , 36*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        27*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        23*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 19*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        15*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 9
	.byte	W12
	.byte		VOL   , 11*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		EOT   
	.byte		PAN   , c_v+63
	.byte		VOL   , 27*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 2
	.byte		N24   , Bn1 
	.byte	W04
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		MOD   , 13
	.byte		VOL   , 53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte		MOD   , 2
	.byte		TIE   , Ds3 
	.byte	W48
	.byte		VOL   , 13*mus_weather_kyogre_mvl/mxv
	.byte	W48
	.byte	PATT
	 .word	mus_weather_kyogre_4_000
	.byte		EOT   , Ds3 
mus_weather_kyogre_4_001:
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte		TIE   , Ds3 , v112
	.byte	W60
	.byte		VOL   , 36*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        31*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        27*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte	PEND
mus_weather_kyogre_4_002:
	.byte		VOL   , 23*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        19*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        15*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        11*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte		        10*mus_weather_kyogre_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		EOT   , Ds3 
	.byte		PAN   , c_v+63
	.byte		VOL   , 27*mus_weather_kyogre_mvl/mxv
	.byte		N24   , Bn1 , v112
	.byte	W04
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W04
mus_weather_kyogre_4_003:
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_weather_kyogre_mvl/mxv
	.byte		TIE   , Ds3 , v112
	.byte	W48
	.byte		VOL   , 13*mus_weather_kyogre_mvl/mxv
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_weather_kyogre_4_000
	.byte		EOT   , Ds3 
	.byte	PATT
	 .word	mus_weather_kyogre_4_001
	.byte	PATT
	 .word	mus_weather_kyogre_4_002
	.byte		EOT   , Ds3 
	.byte		PAN   , c_v+63
	.byte		VOL   , 27*mus_weather_kyogre_mvl/mxv
	.byte		N24   , Bn1 , v112
	.byte	W04
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte	PATT
	 .word	mus_weather_kyogre_4_003
	.byte	PATT
	 .word	mus_weather_kyogre_4_000
	.byte		EOT   , Ds3 
	.byte	PATT
	 .word	mus_weather_kyogre_4_001
	.byte	PATT
	 .word	mus_weather_kyogre_4_002
	.byte		EOT   , Ds3 
	.byte		PAN   , c_v+63
	.byte		VOL   , 27*mus_weather_kyogre_mvl/mxv
	.byte		N24   , Bn1 , v112
	.byte	W04
	.byte		VOL   , 42*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        47*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        53*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        61*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte		        71*mus_weather_kyogre_mvl/mxv
	.byte	W04
	.byte	GOTO
	 .word	mus_weather_kyogre_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_weather_kyogre_5:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		MOD   , 64
	.byte		VOL   , 80*mus_weather_kyogre_mvl/mxv
	.byte	W24
mus_weather_kyogre_5_B1:
mus_weather_kyogre_5_000:
	.byte		N04   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		        Cn1 , v088
	.byte	W08
	.byte	PEND
mus_weather_kyogre_5_001:
	.byte		N04   , Cn1 , v127
	.byte	W24
	.byte		        Cn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		        Dn1 , v127
	.byte	W08
	.byte		        Cn1 , v088
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_000
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_000
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_000
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	PATT
	 .word	mus_weather_kyogre_5_001
	.byte	GOTO
	 .word	mus_weather_kyogre_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_weather_kyogre_6:
	.byte	KEYSH , mus_weather_kyogre_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*mus_weather_kyogre_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N24   , An1 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
mus_weather_kyogre_6_B1:
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
mus_weather_kyogre_6_000:
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		        Ds1 , v064
	.byte	W08
	.byte		        Ds1 , v100
	.byte	W08
	.byte		        Dn1 , v112
	.byte	W08
	.byte		N02   , Ds1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Ds1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_weather_kyogre_6_001:
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , En1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Ds1 , v112
	.byte	W08
	.byte		N04   , En1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte	PEND
	.byte		N08   
	.byte	W08
	.byte		N04   , En1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v100
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		N02   , En1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W12
	.byte		MOD   , 13
	.byte	W12
	.byte		VOICE , 84
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N16   , As4 
	.byte	W16
	.byte		N04   , Cs5 
	.byte	W08
	.byte		        Cn5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs5 
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N40   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W28
	.byte		        0
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N08   , Bn4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N08   , Gs4 
	.byte	W08
	.byte		N04   , Bn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        Gs5 
	.byte	W16
	.byte		        Fs4 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N42   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W30
	.byte		        0
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W02
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs4 
	.byte	W14
	.byte		MOD   , 7
	.byte	W10
	.byte		        0
	.byte		BEND  , c_v+2
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , Ds1 , v076
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , Ds1 , v112
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds2 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte	PATT
	 .word	mus_weather_kyogre_6_000
	.byte	PATT
	 .word	mus_weather_kyogre_6_001
	.byte		N08   , En1 , v112
	.byte	W08
	.byte		N04   , En1 , v056
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		        En1 , v064
	.byte	W08
	.byte		        En1 , v100
	.byte	W08
	.byte		        Ds1 , v112
	.byte	W08
	.byte		N02   , En1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   
	.byte	W24
	.byte		VOICE , 83
	.byte		BEND  , c_v+0
	.byte		N16   , As3 
	.byte	W16
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs4 
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N40   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W28
	.byte		        0
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Gs4 
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N42   , Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W30
	.byte		        0
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W02
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gs3 
	.byte	W14
	.byte		MOD   , 7
	.byte	W10
	.byte	GOTO
	 .word	mus_weather_kyogre_6_B1
	.byte		MOD   , 0
	.byte	FINE

@******************************************************@
	.align	2

mus_weather_kyogre:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_weather_kyogre_pri	@ Priority
	.byte	mus_weather_kyogre_rev	@ Reverb.

	.word	mus_weather_kyogre_grp

	.word	mus_weather_kyogre_1
	.word	mus_weather_kyogre_2
	.word	mus_weather_kyogre_3
	.word	mus_weather_kyogre_4
	.word	mus_weather_kyogre_5
	.word	mus_weather_kyogre_6

	.end
