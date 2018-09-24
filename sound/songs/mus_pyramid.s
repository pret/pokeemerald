	.include "MPlayDef.s"

	.equ	mus_pyramid_grp, voicegroup106
	.equ	mus_pyramid_pri, 0
	.equ	mus_pyramid_rev, reverb_set+50
	.equ	mus_pyramid_mvl, 127
	.equ	mus_pyramid_key, 0
	.equ	mus_pyramid_tbs, 1
	.equ	mus_pyramid_exg, 0
	.equ	mus_pyramid_cmp, 1

	.section .rodata
	.global	mus_pyramid
	.align	2

@********************** Track  1 **********************@

mus_pyramid_1:
	.byte	KEYSH , mus_pyramid_key+0
	.byte	TEMPO , 106*mus_pyramid_tbs/2
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W48
	.byte		N03   , Fn4 , v112
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte	W96
	.byte		VOL   , 55*mus_pyramid_mvl/mxv
	.byte		N03   , An3 , v084
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
mus_pyramid_1_000:
	.byte		N03   , Ds3 , v084
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds5 , v112
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte	PEND
mus_pyramid_1_B1:
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
	.byte	W96
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		N03   , An4 , v084
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        Ds6 
	.byte	W03
	.byte		        Fn6 
	.byte	W03
	.byte		        Ds6 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds6 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds6 , v112
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		VOL   , 50*mus_pyramid_mvl/mxv
	.byte		N03   , An3 , v084
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte	PATT
	 .word	mus_pyramid_1_000
	.byte	GOTO
	 .word	mus_pyramid_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_pyramid_2:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , As2 
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W48
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N48   , As2 
	.byte	W48
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		N03   , Fn4 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte		N12   , Fn3 
	.byte	W03
	.byte		VOL   , 29*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        39*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        40*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        46*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W03
	.byte		VOL   , 22*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        24*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        30*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        35*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        42*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        45*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        49*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        53*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        59*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        64*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        69*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        70*mus_pyramid_mvl/mxv
	.byte	W05
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
mus_pyramid_2_B1:
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N24   , Cn3 , v112
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W12
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N36   , Fn3 
	.byte	W12
	.byte		VOL   , 24*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 23*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N32   , Cn4 
	.byte	W12
	.byte		VOL   , 23*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
mus_pyramid_2_000:
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		N24   , Cn3 , v112
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Ds3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	mus_pyramid_2_000
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		N24   , Fn3 , v112
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N22   , Ds3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Cn3 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , An2 
	.byte	W12
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        13*mus_pyramid_mvl/mxv
	.byte		N96   , Gn2 , v108
	.byte	W12
	.byte		VOL   , 14*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        19*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        21*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        24*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-46
	.byte	W02
	.byte		VOL   , 26*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        29*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        31*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-43
	.byte	W03
	.byte		VOL   , 35*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-36
	.byte	W03
	.byte		VOL   , 37*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-33
	.byte	W03
	.byte		VOL   , 39*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W03
	.byte		VOL   , 40*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-20
	.byte	W03
	.byte		VOL   , 46*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-13
	.byte	W03
	.byte		VOL   , 49*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		VOL   , 52*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+3
	.byte	W03
	.byte		VOL   , 55*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+10
	.byte	W03
	.byte		VOL   , 59*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+19
	.byte	W03
	.byte		VOL   , 63*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+34
	.byte	W03
	.byte		VOL   , 67*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+41
	.byte	W03
	.byte		VOL   , 74*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+43
	.byte	W03
	.byte		VOL   , 77*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        79*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W01
	.byte		        21*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+50
	.byte		N48   , Cn3 , v064
	.byte	W02
	.byte		VOL   , 25*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+44
	.byte	W02
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+34
	.byte	W03
	.byte		VOL   , 32*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+28
	.byte	W03
	.byte		VOL   , 36*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+25
	.byte	W03
	.byte		VOL   , 41*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+21
	.byte	W03
	.byte		VOL   , 47*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+12
	.byte	W03
	.byte		VOL   , 54*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+4
	.byte	W03
	.byte		VOL   , 57*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W03
	.byte		VOL   , 64*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		VOL   , 67*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-26
	.byte	W03
	.byte		VOL   , 74*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-36
	.byte	W03
	.byte		VOL   , 79*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-39
	.byte	W13
	.byte		VOL   , 21*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-37
	.byte		N48   , Fn3 
	.byte	W02
	.byte		VOL   , 25*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W03
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-23
	.byte	W03
	.byte		VOL   , 32*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		VOL   , 36*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-7
	.byte	W03
	.byte		VOL   , 41*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+3
	.byte	W03
	.byte		VOL   , 47*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+12
	.byte	W03
	.byte		VOL   , 54*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+21
	.byte	W03
	.byte		VOL   , 57*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+35
	.byte	W03
	.byte		VOL   , 64*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+47
	.byte	W03
	.byte		VOL   , 67*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        74*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        79*mus_pyramid_mvl/mxv
	.byte	W13
	.byte		VOICE , 60
	.byte		VOL   , 41*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W48
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 27*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 40*mus_pyramid_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 27*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		VOICE , 48
	.byte		VOL   , 33*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v-40
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N06   , Gn4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , An4 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , As4 
	.byte	W06
	.byte		PAN   , c_v+28
	.byte		N06   , Cn5 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		N24   , Fn4 
	.byte	W12
	.byte		VOL   , 19*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 19*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , Cs4 
	.byte	W12
	.byte		VOL   , 19*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        33*mus_pyramid_mvl/mxv
	.byte		N24   , As3 
	.byte	W12
	.byte		VOL   , 19*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        38*mus_pyramid_mvl/mxv
	.byte		N03   , Fn5 , v084
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Ds5 , v080
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        Cn5 , v076
	.byte	W03
	.byte		        Cn5 , v016
	.byte	W03
	.byte		        An4 , v072
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Bn4 , v068
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        An4 , v040
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Fn4 , v040
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Ds4 , v040
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        Fn4 , v040
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn4 , v044
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        An4 , v044
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Ds5 , v044
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        Bn4 , v044
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn5 , v064
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Ds5 , v088
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        An5 , v112
	.byte	W03
	.byte		        An5 , v016
	.byte	W03
	.byte		        Gs5 , v088
	.byte	W03
	.byte		        Gs5 , v016
	.byte	W03
	.byte		        Fn5 , v080
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Dn5 , v072
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Dn5 , v056
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Bn4 , v048
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Fn4 , v052
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Dn5 , v056
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Bn4 , v056
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn5 , v056
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Gs5 , v072
	.byte	W03
	.byte		        Gs5 , v016
	.byte	W03
	.byte		        Fn5 , v088
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Bn5 , v104
	.byte	W03
	.byte		        Bn5 , v016
	.byte	W03
	.byte		        An5 , v088
	.byte	W03
	.byte		        An5 , v016
	.byte	W03
	.byte		        Fs5 , v084
	.byte	W03
	.byte		        Fs5 , v016
	.byte	W03
	.byte		        Ds5 , v080
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        Cn5 , v072
	.byte	W03
	.byte		        Cn5 , v016
	.byte	W03
	.byte		        Ds5 , v068
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        Cn5 , v044
	.byte	W03
	.byte		        Cn5 , v016
	.byte	W03
	.byte		        An4 , v044
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Fs4 , v048
	.byte	W03
	.byte		        Fs4 , v016
	.byte	W03
	.byte		        An4 , v048
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Ds5 , v048
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        Cn5 , v048
	.byte	W03
	.byte		        Cn5 , v016
	.byte	W03
	.byte		        Fs5 , v048
	.byte	W03
	.byte		        Fs5 , v016
	.byte	W03
	.byte		        Ds5 , v052
	.byte	W03
	.byte		        Ds5 , v016
	.byte	W03
	.byte		        An5 , v076
	.byte	W03
	.byte		        An5 , v016
	.byte	W03
	.byte		        Fs5 , v088
	.byte	W03
	.byte		        Fs5 , v016
	.byte	W03
	.byte		        Cn6 , v096
	.byte	W03
	.byte		        Cn6 , v016
	.byte	W03
	.byte		        Bn5 , v076
	.byte	W03
	.byte		        Bn5 , v016
	.byte	W03
	.byte		        Gs5 , v068
	.byte	W03
	.byte		        Gs5 , v016
	.byte	W03
	.byte		        Fn5 , v056
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Dn5 , v048
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Fn5 , v044
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Dn5 , v048
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Bn4 , v052
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Gs4 , v052
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Bn4 , v056
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn5 , v060
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Dn5 , v060
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Gs5 , v064
	.byte	W03
	.byte		        Gs5 , v016
	.byte	W03
	.byte		        Fn5 , v076
	.byte	W03
	.byte		        Fn5 , v016
	.byte	W03
	.byte		        Bn5 , v088
	.byte	W03
	.byte		        Bn5 , v016
	.byte	W03
	.byte		        Gs5 , v096
	.byte	W03
	.byte		        Gs5 , v016
	.byte	W03
	.byte		        Dn6 , v108
	.byte	W03
	.byte		        Dn6 , v016
	.byte	W03
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   , Ds4 , v080
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		VOL   , 13*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N24   , An3 
	.byte	W01
	.byte		VOL   , 14*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        19*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        22*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        33*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        35*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        39*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        44*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        49*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        52*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        61*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		PAN   , c_v-32
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_pyramid_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_pyramid_3:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 87
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+2
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N03   , Fn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		MOD   , 0
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   , An1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , An1 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		VOL   , 70*mus_pyramid_mvl/mxv
	.byte		N12   , An1 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
mus_pyramid_3_000:
	.byte		N06   , Fn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte	PEND
mus_pyramid_3_B1:
mus_pyramid_3_001:
	.byte		N06   , Fn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_pyramid_3_000
	.byte		N06   , Fn1 , v112
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N03   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N03   , An2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		N12   , Ds2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Fn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn1 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N03   
	.byte	W02
	.byte		        An2 
	.byte	W02
	.byte		N06   , Fn2 
	.byte	W08
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N21   , An2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W06
mus_pyramid_3_002:
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N84   , Ds1 
	.byte	W48
	.byte		MOD   , 6
	.byte	W36
	.byte	PEND
	.byte		        0
	.byte	W84
	.byte		N12   , Fs1 
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_pyramid_3_002
	.byte		MOD   , 0
	.byte	W48
	.byte		N24   , Cn2 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Fn1 
	.byte	W09
	.byte		MOD   , 10
	.byte	W09
	.byte		        0
	.byte		N06   , An1 
	.byte	W06
mus_pyramid_3_003:
	.byte		N06   , As1 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte	PEND
	.byte		        Fn1 
	.byte	W06
	.byte		N03   , Cn2 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W18
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte	PATT
	 .word	mus_pyramid_3_003
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   , Cn2 
	.byte	W18
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N03   , Gn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte	PATT
	 .word	mus_pyramid_3_003
	.byte		N03   , Fn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds2 
	.byte	W18
	.byte		        En2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        As1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N24   , Fn1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , As1 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 70*mus_pyramid_mvl/mxv
	.byte		N06   , Fn1 , v084
	.byte	W06
	.byte		        An1 , v080
	.byte	W06
	.byte		        Gs1 , v076
	.byte	W06
	.byte		        Gn1 , v072
	.byte	W06
	.byte		        Cn2 , v068
	.byte	W06
	.byte		        Bn1 , v052
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        En2 , v056
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 , v060
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        En2 , v076
	.byte	W06
	.byte		        Ds2 , v084
	.byte	W06
	.byte		        En2 , v092
	.byte	W06
	.byte		        Fn1 , v088
	.byte	W06
	.byte		        An1 , v080
	.byte	W06
	.byte		        Gs1 , v072
	.byte	W06
	.byte		        Gn1 , v064
	.byte	W06
	.byte		        Cn2 , v056
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        En2 , v060
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fn2 , v072
	.byte	W06
	.byte		        En2 , v076
	.byte	W06
	.byte		        Ds2 , v084
	.byte	W06
	.byte		        En2 , v096
	.byte	W06
	.byte		        Fn1 , v088
	.byte	W06
	.byte		        An1 , v084
	.byte	W06
	.byte		        Gs1 , v080
	.byte	W06
	.byte		        Gn1 , v072
	.byte	W06
	.byte		        Cn2 , v068
	.byte	W06
	.byte		        Bn1 , v044
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        En2 , v048
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fn2 , v052
	.byte	W06
	.byte		        Gs2 , v072
	.byte	W06
	.byte		        Gn2 , v084
	.byte	W06
	.byte		        Fs2 , v092
	.byte	W06
	.byte		        Fn1 , v076
	.byte	W06
	.byte		        An1 , v068
	.byte	W06
	.byte		        Gs1 , v056
	.byte	W06
	.byte		        Gn1 , v048
	.byte	W06
	.byte		        Cn2 , v044
	.byte	W06
	.byte		        Bn1 , v048
	.byte	W06
	.byte		        As1 , v052
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 , v056
	.byte	W06
	.byte		        Dn2 , v060
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fn2 , v076
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Cs2 , v096
	.byte	W06
	.byte		        As1 , v108
	.byte	W06
	.byte		VOICE , 87
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , An1 , v112
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N02   , An1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N24   , An2 
	.byte	W18
	.byte		MOD   , 8
	.byte	W06
	.byte		VOICE , 87
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , Fn1 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte	PATT
	 .word	mus_pyramid_3_000
	.byte	PATT
	 .word	mus_pyramid_3_001
	.byte		N06   , Fn1 , v112
	.byte	W24
	.byte		        Ds2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte	GOTO
	 .word	mus_pyramid_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_pyramid_4:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N24   , As2 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N60   , As3 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W48
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , Fs3 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W36
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W06
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		VOL   , 18*mus_pyramid_mvl/mxv
	.byte		N12   , Bn2 
	.byte	W03
	.byte		VOL   , 29*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        37*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        52*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W03
	.byte		VOL   , 14*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        17*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        19*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        22*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        24*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        29*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        32*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        37*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        46*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        53*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        59*mus_pyramid_mvl/mxv
	.byte	W08
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W96
	.byte	W96
mus_pyramid_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 17
	.byte	W24
	.byte		PAN   , c_v+17
	.byte		N36   , Cn6 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N01   , As5 
	.byte	W01
	.byte		        An5 
	.byte	W01
	.byte		        Gn5 
	.byte	W01
	.byte		        Fn5 
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N09   , Cn5 
	.byte	W09
	.byte		N01   , Cs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N08   , As5 
	.byte	W08
	.byte		N01   , Gs5 
	.byte	W01
	.byte		        Gn5 
	.byte	W01
	.byte		        Fs5 
	.byte	W02
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , Fn4 
	.byte		N12   , Cn5 
	.byte	W06
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N06   
	.byte		N01   , Cs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W01
	.byte		N19   , Ds5 
	.byte	W01
	.byte		N06   , Gs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		N01   , En5 
	.byte	W01
	.byte		        Fn5 
	.byte	W02
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , Fs5 
	.byte	W12
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N01   , Fn5 
	.byte		N01   , Fs5 
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N03   , Fs5 
	.byte	W03
	.byte		N01   , Fn5 
	.byte	W01
	.byte		        En5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte		        Cs5 
	.byte	W01
	.byte		N09   , Cn5 
	.byte	W10
	.byte		N12   , As4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W04
	.byte		N08   , Fs5 
	.byte	W02
	.byte		MOD   , 0
	.byte	W07
	.byte		N01   , Fn5 
	.byte	W01
	.byte		        Ds5 
	.byte	W04
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Ds5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Fs5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N02   , Fs4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N07   , Fs4 
	.byte	W08
	.byte		N12   , Ds4 
	.byte	W12
	.byte		VOICE , 24
	.byte		PAN   , c_v+32
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N18   , Ds4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N36   , Ds5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N18   , Gn4 
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , An3 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N06   , Fn3 , v096
	.byte	W18
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N06   , Fn3 , v080
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , An3 
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , An2 
	.byte	W03
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte	W03
	.byte		N06   , As2 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W18
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N36   , As3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W18
	.byte		N03   , Cs3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N24   , En2 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		VOL   , 61*mus_pyramid_mvl/mxv
	.byte		N03   , An4 , v084
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Ds4 , v080
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        Fn4 , v076
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Ds4 , v068
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        An3 , v040
	.byte	W03
	.byte		        An3 , v016
	.byte	W03
	.byte		        Bn3 , v040
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Fn3 , v040
	.byte	W03
	.byte		        Fn3 , v016
	.byte	W03
	.byte		        Ds3 , v040
	.byte	W03
	.byte		        Ds3 , v016
	.byte	W03
	.byte		        Bn3 , v044
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        An3 , v044
	.byte	W03
	.byte		        An3 , v016
	.byte	W03
	.byte		        Fn3 , v044
	.byte	W03
	.byte		        Fn3 , v016
	.byte	W03
	.byte		        Ds4 , v044
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        An3 , v064
	.byte	W03
	.byte		        An3 , v016
	.byte	W03
	.byte		        Fn4 , v088
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        Bn4 , v088
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Gs4 , v072
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Dn4 , v064
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Fn4 , v056
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn3 , v048
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Dn4 , v052
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Gs3 , v052
	.byte	W03
	.byte		        Gs3 , v016
	.byte	W03
	.byte		        Fn3 , v052
	.byte	W03
	.byte		        Fn3 , v016
	.byte	W03
	.byte		        Dn4 , v056
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Gs3 , v056
	.byte	W03
	.byte		        Gs3 , v016
	.byte	W03
	.byte		        Fn3 , v056
	.byte	W03
	.byte		        Fn3 , v016
	.byte	W03
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn3 , v072
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Gs4 , v088
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Dn4 , v104
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Cn5 , v088
	.byte	W03
	.byte		        Cn5 , v016
	.byte	W03
	.byte		        Fs4 , v084
	.byte	W03
	.byte		        Fs4 , v016
	.byte	W03
	.byte		        An4 , v080
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Ds4 , v072
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        Fs4 , v068
	.byte	W03
	.byte		        Fs4 , v016
	.byte	W03
	.byte		        Cn4 , v044
	.byte	W03
	.byte		        Cn4 , v016
	.byte	W03
	.byte		        Ds4 , v044
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        An3 , v048
	.byte	W03
	.byte		        An3 , v016
	.byte	W03
	.byte		        Fs3 , v048
	.byte	W03
	.byte		        Fs3 , v016
	.byte	W03
	.byte		        Ds4 , v048
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        An3 , v048
	.byte	W03
	.byte		        An3 , v016
	.byte	W03
	.byte		        Fs3 , v048
	.byte	W03
	.byte		        Fs3 , v016
	.byte	W03
	.byte		        Fs4 , v052
	.byte	W03
	.byte		        Fs4 , v016
	.byte	W03
	.byte		        Cn4 , v076
	.byte	W03
	.byte		        Cn4 , v016
	.byte	W03
	.byte		        An4 , v088
	.byte	W03
	.byte		        An4 , v016
	.byte	W03
	.byte		        Ds4 , v096
	.byte	W03
	.byte		        Ds4 , v016
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Dn5 , v016
	.byte	W03
	.byte		        Gs4 , v068
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Bn4 , v056
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn4 , v048
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Gs4 , v044
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Dn4 , v048
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Fn4 , v052
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn3 , v052
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Gs3 , v056
	.byte	W03
	.byte		        Gs3 , v016
	.byte	W03
	.byte		        Fn4 , v060
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		        Bn3 , v060
	.byte	W03
	.byte		        Bn3 , v016
	.byte	W03
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v016
	.byte	W03
	.byte		        Gs4 , v076
	.byte	W03
	.byte		        Gs4 , v016
	.byte	W03
	.byte		        Dn4 , v088
	.byte	W03
	.byte		        Dn4 , v016
	.byte	W03
	.byte		        Bn4 , v096
	.byte	W03
	.byte		        Bn4 , v016
	.byte	W03
	.byte		        Fn4 , v108
	.byte	W03
	.byte		        Fn4 , v016
	.byte	W03
	.byte		VOICE , 60
	.byte		PAN   , c_v-16
	.byte		N24   , Bn3 , v064
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , An3 , v080
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   , Fn3 , v112
	.byte	W24
	.byte		VOL   , 13*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+21
	.byte		N24   , Ds3 
	.byte	W01
	.byte		VOL   , 14*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        19*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        22*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        33*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        35*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        39*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        44*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        49*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        52*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		VOICE , 24
	.byte		PAN   , c_v+32
	.byte		N48   , Gs3 , v080
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        61*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte		BEND  , c_v+0
	.byte		N48   
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		MOD   , 7
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        61*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_pyramid_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_pyramid_5:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 14
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-15
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W36
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W48
mus_pyramid_5_B1:
	.byte		VOICE , 14
	.byte	W24
	.byte		N24   , As4 , v112
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N36   , An4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N13   , Fn4 
	.byte	W12
	.byte		N36   , Cn5 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N48   , Cn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N48   , An3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N48   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N12   , An4 
	.byte	W12
	.byte		N36   , Fn5 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 24
	.byte	W96
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-41
	.byte		N12   , Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , As4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        As4 
	.byte	W06
	.byte		PAN   , c_v-23
	.byte		N12   , An4 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+13
	.byte		N12   , Fn4 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W06
	.byte		MOD   , 8
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+33
	.byte		N06   , As3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v-14
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
	.byte		VOICE , 24
	.byte		PAN   , c_v-7
	.byte		N48   , Fn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W48
	.byte		BEND  , c_v+0
	.byte		N48   
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		MOD   , 7
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W36
	.byte		N12   , Cn3 
	.byte	W12
	.byte		VOICE , 14
	.byte		N48   , Fn3 
	.byte	W24
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W36
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N48   , Fn3 
	.byte	W24
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	GOTO
	 .word	mus_pyramid_5_B1
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte	FINE

@********************** Track  6 **********************@

mus_pyramid_6:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Cn2 , v064
	.byte	W03
	.byte		        Cn2 , v092
	.byte	W03
	.byte		        Cn2 , v112
	.byte	W03
	.byte		        Cn2 , v127
	.byte	W03
	.byte		N24   , As1 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N12   , As2 
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		N24   , Cn2 , v127
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   , Bn1 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   , As1 
	.byte	W24
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
mus_pyramid_6_000:
	.byte		N12   , Fn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
mus_pyramid_6_001:
	.byte		N12   , Fn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
mus_pyramid_6_B1:
	.byte	PATT
	 .word	mus_pyramid_6_000
	.byte		N12   , Fn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PATT
	 .word	mus_pyramid_6_000
	.byte		N12   , Fn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PATT
	 .word	mus_pyramid_6_000
	.byte	PATT
	 .word	mus_pyramid_6_001
	.byte	PATT
	 .word	mus_pyramid_6_000
	.byte		N12   , Fn2 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W24
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N84   , Gn1 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        35*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        21*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W84
	.byte		N06   , Ds2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N84   , Gn1 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        33*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        22*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W96
	.byte		VOICE , 30
	.byte		PAN   , c_v-24
	.byte		VOL   , 50*mus_pyramid_mvl/mxv
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N03   , As2 , v064
	.byte	W03
	.byte		        As2 , v024
	.byte	W03
	.byte		        As2 , v064
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Fn3 , v020
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W03
	.byte		N06   , Cn3 , v020
	.byte	W09
	.byte		        Fn2 , v064
	.byte	W06
	.byte		        Fn2 , v024
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		N12   , Fn3 , v020
	.byte	W12
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        Fn2 , v020
	.byte	W03
	.byte		        Fn2 , v064
	.byte	W03
	.byte		        Fn2 , v020
	.byte	W03
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N03   , As2 , v064
	.byte	W03
	.byte		        As2 , v024
	.byte	W03
	.byte		        As2 , v064
	.byte	W03
	.byte		        As2 , v024
	.byte	W03
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N12   , Cn3 , v024
	.byte	W12
	.byte		N06   , Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v024
	.byte	W06
	.byte		        Cn3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N03   , As2 , v064
	.byte	W03
	.byte		        As2 , v020
	.byte	W03
	.byte		        As2 , v064
	.byte	W03
	.byte		        As2 , v020
	.byte	W03
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn2 , v028
	.byte	W06
	.byte		        Fn2 , v064
	.byte	W06
	.byte		        Fn2 , v020
	.byte	W06
	.byte		        Ds3 , v064
	.byte	W06
	.byte		N12   , Ds3 , v020
	.byte	W12
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        Fn2 , v020
	.byte	W03
	.byte		        Fn2 , v064
	.byte	W03
	.byte		        Fn2 , v020
	.byte	W03
	.byte		N06   , Fn3 , v064
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v024
	.byte	W18
	.byte		N06   , As2 , v064
	.byte	W06
	.byte		N12   , As2 , v020
	.byte	W18
	.byte		N03   , As2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N24   , Fn1 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N06   , As1 , v048
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		N24   , En2 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v-23
	.byte		MOD   , 0
	.byte		N12   , Gn2 
	.byte	W12
	.byte		VOICE , 47
	.byte		PAN   , c_v+32
	.byte		VOL   , 55*mus_pyramid_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N18   , Fn2 
	.byte	W18
	.byte	W96
	.byte	W96
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N06   , Fn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte	GOTO
	 .word	mus_pyramid_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_pyramid_7:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 85
	.byte		LFOS  , 51
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		        c_v+1
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 11
	.byte	W36
	.byte		        0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 11
	.byte	W36
	.byte		        0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W12
	.byte		VOL   , 23*mus_pyramid_mvl/mxv
	.byte		N12   , An3 
	.byte	W02
	.byte		VOL   , 34*mus_pyramid_mvl/mxv
	.byte	W04
	.byte		        42*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		N24   , An4 
	.byte	W03
	.byte		VOL   , 16*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        18*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        22*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        23*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        27*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        29*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        32*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        36*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        39*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        42*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N06   , Fn2 
	.byte	W96
	.byte	W72
	.byte		VOICE , 85
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
mus_pyramid_7_B1:
	.byte		N60   , Ds4 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W48
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N10   , Cn4 
	.byte	W10
	.byte		N01   , Bn3 , v080
	.byte	W02
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		N32   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W21
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N01   , As3 , v080
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N08   , An3 
	.byte	W08
	.byte		N01   , Gs3 , v080
	.byte	W01
	.byte		        Gn3 
	.byte	W01
	.byte		        Fs3 
	.byte	W02
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N01   , As3 , v080
	.byte	W01
	.byte		        An3 
	.byte	W01
	.byte		        Fs3 
	.byte	W02
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+1
	.byte	W02
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N54   , Ds5 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W01
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W17
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N01   , Cs5 , v080
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Gs4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N01   , Cs5 , v080
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		N32   , An4 
	.byte	W10
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N01   , As4 , v080
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W13
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N07   , Cn5 
	.byte	W07
	.byte		N01   , As4 , v080
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W01
	.byte		        Fs4 
	.byte	W02
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , Cn5 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W13
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N18   , Cs4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N24   , Cn4 
	.byte	W09
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		VOICE , 85
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N84   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W48
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        9*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N54   , Cn4 
	.byte	W18
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W01
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        42*mus_pyramid_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N54   , Cn4 
	.byte	W18
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , Cs4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W96
	.byte		BEND  , c_v+63
	.byte		N96   , Dn4 , v048
	.byte	W02
	.byte		BEND  , c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W03
	.byte		        c_v+51
	.byte	W03
	.byte		        c_v+47
	.byte	W03
	.byte		        c_v+42
	.byte	W03
	.byte		        c_v+39
	.byte	W03
	.byte		        c_v+35
	.byte	W03
	.byte		        c_v+31
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-45
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-56
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		VOICE , 80
	.byte		BEND  , c_v+63
	.byte		N96   , Cs3 
	.byte	W02
	.byte		BEND  , c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W03
	.byte		        c_v+51
	.byte	W03
	.byte		        c_v+47
	.byte	W03
	.byte		        c_v+42
	.byte	W03
	.byte		        c_v+39
	.byte	W03
	.byte		        c_v+35
	.byte	W03
	.byte		        c_v+31
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-1
	.byte	W01
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-45
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-56
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte	W24
	.byte		        c_v+1
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N03   , Dn4 , v044
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Gs5 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Dn6 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		VOICE , 85
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , An1 , v112
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N02   , An1 
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , Fn2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte	W96
	.byte	W72
	.byte		N06   , Ds3 , v064
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte	W96
	.byte	W72
	.byte		        Ds3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_pyramid_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_pyramid_8:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 86
	.byte		LFOS  , 50
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W24
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N48   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gs4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , An4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn1 , v112
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N02   , An4 , v096
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		N12   , Bn1 , v108
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N06   , An1 , v112
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte		N12   , An3 , v096
	.byte	W02
	.byte		VOL   , 37*mus_pyramid_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 47*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N24   , An4 , v112
	.byte	W04
	.byte		VOL   , 16*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        20*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        23*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        33*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        37*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		        45*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        48*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        52*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        58*mus_pyramid_mvl/mxv
	.byte	W01
	.byte		        63*mus_pyramid_mvl/mxv
	.byte	W02
	.byte		MOD   , 8
	.byte		VOL   , 70*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte	W72
	.byte		VOICE , 86
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
mus_pyramid_8_B1:
	.byte		N60   , Ds4 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W21
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N10   , Cn4 
	.byte	W10
	.byte		N01   , Bn3 , v080
	.byte	W02
	.byte		N12   , As3 , v112
	.byte	W12
	.byte		N32   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N01   , As3 , v080
	.byte	W01
	.byte		        Bn3 
	.byte	W02
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N08   , An3 
	.byte	W08
	.byte		N01   , Gs3 , v080
	.byte	W01
	.byte		        Gn3 
	.byte	W01
	.byte		        Fs3 
	.byte	W02
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		N08   , Cn4 
	.byte	W08
	.byte		N01   , As3 , v080
	.byte	W01
	.byte		        An3 
	.byte	W01
	.byte		        Fs3 
	.byte	W02
	.byte		N12   , Fn3 , v112
	.byte	W12
	.byte		N03   , Fs3 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N01   , Gs3 , v080
	.byte		N01   , An3 
	.byte	W01
	.byte		        Gn3 
	.byte	W02
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N54   , Ds5 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N01   , Cs5 , v080
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        As4 
	.byte	W01
	.byte		        Gs4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N01   , Cs5 , v080
	.byte	W01
	.byte		        Cn5 
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		N32   , An4 
	.byte	W10
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N01   , As4 , v080
	.byte	W01
	.byte		        Bn4 
	.byte	W02
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N07   , Cn5 
	.byte	W07
	.byte		N01   , As4 , v080
	.byte	W01
	.byte		        An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W01
	.byte		        Fs4 
	.byte	W02
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W13
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Cn5 
	.byte	W03
	.byte		N01   , Gs4 , v080
	.byte		N01   , An4 
	.byte	W01
	.byte		        Gn4 
	.byte	W02
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N36   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N18   , Cs4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W06
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N24   , Cn4 
	.byte	W09
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W09
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W09
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N48   , Cn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		VOICE , 86
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		N06   , Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N84   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W48
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        14*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Dn4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N54   , Cn4 
	.byte	W18
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W01
	.byte		        28*mus_pyramid_mvl/mxv
	.byte	W11
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		VOICE , 82
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Cn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fn4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs4 
	.byte	W18
	.byte		N03   , As3 
	.byte	W06
	.byte		N36   , Cs4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N54   , Cn4 
	.byte	W18
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Ds4 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs4 
	.byte	W18
	.byte		N03   , Fn3 
	.byte	W06
	.byte		N36   
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 81
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gs3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W12
	.byte		        56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N48   , Gn3 
	.byte	W12
	.byte		VOL   , 42*mus_pyramid_mvl/mxv
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 28*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		VOICE , 82
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte	W96
	.byte		BEND  , c_v+63
	.byte		N96   , Bn4 , v048
	.byte	W02
	.byte		BEND  , c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W03
	.byte		        c_v+51
	.byte	W03
	.byte		        c_v+47
	.byte	W03
	.byte		        c_v+42
	.byte	W03
	.byte		        c_v+39
	.byte	W03
	.byte		        c_v+35
	.byte	W03
	.byte		        c_v+31
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-45
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-56
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		VOICE , 81
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		BEND  , c_v+63
	.byte		N96   , As3 
	.byte	W02
	.byte		BEND  , c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W03
	.byte		        c_v+51
	.byte	W03
	.byte		        c_v+47
	.byte	W03
	.byte		        c_v+42
	.byte	W03
	.byte		        c_v+39
	.byte	W03
	.byte		        c_v+35
	.byte	W03
	.byte		        c_v+31
	.byte	W03
	.byte		        c_v+23
	.byte	W03
	.byte		        c_v+18
	.byte	W03
	.byte		        c_v+13
	.byte	W03
	.byte		        c_v+9
	.byte	W03
	.byte		        c_v+4
	.byte	W03
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v-2
	.byte	W04
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-16
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		        c_v-29
	.byte	W03
	.byte		        c_v-33
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		        c_v-45
	.byte	W03
	.byte		        c_v-48
	.byte	W03
	.byte		        c_v-52
	.byte	W03
	.byte		        c_v-56
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte	W24
	.byte		        c_v+0
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N03   , Gs4 , v044
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Dn6 
	.byte	W03
	.byte		        Fn6 
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N03   , Gs6 
	.byte	W03
	.byte		        Fn6 
	.byte	W03
	.byte		        Dn6 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		VOICE , 86
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte		MOD   , 0
	.byte		N48   , An4 , v064
	.byte	W18
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte	W18
	.byte		        8
	.byte	W06
	.byte		        0
	.byte		N24   , As4 , v112
	.byte	W18
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W06
	.byte		        0
	.byte		BEND  , c_v+1
	.byte		N06   , Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W06
	.byte		N12   , Fs1 , v060
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		N03   , Fn1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N06   , Ds3 , v064
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte		N06   , Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Fn1 , v060
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W06
	.byte		N12   , Fs1 , v060
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Fn1 , v024
	.byte	W18
	.byte		        Ds2 , v060
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		N03   , Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte	GOTO
	 .word	mus_pyramid_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_pyramid_9:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 65*mus_pyramid_mvl/mxv
	.byte	W24
	.byte		N24   , An2 , v072
	.byte	W96
	.byte	W96
	.byte		        Gn2 , v080
	.byte	W36
	.byte		        En2 
	.byte	W24
	.byte		N12   , Bn2 , v084
	.byte	W12
	.byte		        Cn3 
	.byte	W24
	.byte		N48   , An2 
	.byte	W60
	.byte		N18   , Fn2 , v044
	.byte	W18
	.byte		N06   , Fn2 , v048
	.byte	W09
	.byte		N03   , Gs2 
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
mus_pyramid_9_000:
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte	PEND
mus_pyramid_9_B1:
mus_pyramid_9_001:
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_pyramid_9_000
	.byte	PATT
	 .word	mus_pyramid_9_001
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , Fs2 , v080
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W06
	.byte		N12   , Gn2 , v088
	.byte	W12
	.byte		N06   , Fs2 , v080
	.byte	W06
	.byte		N03   , Gs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte	PATT
	 .word	mus_pyramid_9_001
	.byte	PATT
	 .word	mus_pyramid_9_000
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		N03   , Gs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W12
	.byte		        Gs2 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		N12   , Gn2 , v092
	.byte	W12
	.byte		N06   , Fs2 , v080
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N36   , Gn2 
	.byte	W84
	.byte	W12
	.byte		N18   , Fn2 , v032
	.byte	W18
	.byte		        Fn2 , v040
	.byte	W18
	.byte		        Fn2 , v032
	.byte	W18
	.byte		N06   , Fn2 , v040
	.byte	W06
	.byte		        Dn2 , v076
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N36   , En2 
	.byte	W84
	.byte		N18   , Cn1 , v096
	.byte		N12   , Fn2 , v044
	.byte	W12
	.byte		N18   , Fn2 , v032
	.byte	W06
	.byte		N06   , Cn1 , v056
	.byte	W06
	.byte		N18   , Cn1 , v076
	.byte	W06
	.byte		        Fn2 , v044
	.byte	W12
	.byte		N06   , Cn1 , v056
	.byte	W06
	.byte		N18   , Cn1 , v076
	.byte		N18   , Fn2 , v032
	.byte	W18
	.byte		N06   , Cn1 , v056
	.byte		N06   , Fn2 , v044
	.byte	W06
	.byte		        Cn1 , v076
	.byte		N15   , Gn2 
	.byte	W06
	.byte		N06   , Dn2 , v080
	.byte	W06
	.byte		        Cn1 
	.byte	W03
	.byte		N03   , Gs2 , v048
	.byte	W03
	.byte		N06   , Fn1 , v080
	.byte		N03   , Gs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N12   , En1 
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		N12   , En1 , v104
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v048
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N12   , En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		N12   , En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		N03   , Gs2 , v048
	.byte	W06
	.byte		N12   , En1 , v060
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N03   , En1 , v096
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v048
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En1 , v104
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v040
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		N03   , En1 , v072
	.byte		N06   , Dn3 , v064
	.byte	W03
	.byte		N03   , En1 , v028
	.byte	W03
	.byte		        En1 , v072
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 , v064
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N12   , En1 
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		N12   , En1 , v104
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N12   , En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		N12   , En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N12   , En1 , v060
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		N03   , Gs2 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v096
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v048
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En1 , v104
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v040
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Gs2 , v048
	.byte	W06
	.byte		        En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		N03   , En1 , v072
	.byte		N06   , Dn3 , v064
	.byte	W03
	.byte		N03   , En1 , v028
	.byte	W03
	.byte		        En1 , v072
	.byte		N03   , Fs2 , v064
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N03   
	.byte		N03   , Fs2 , v044
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v088
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Gs2 , v048
	.byte	W06
	.byte		N12   , En1 
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		N12   , En1 , v104
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Gs2 
	.byte	W06
	.byte		N12   , En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , En1 , v060
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		N03   , Gs2 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En1 , v096
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v048
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En1 , v104
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v040
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v096
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		N03   , En1 , v072
	.byte	W03
	.byte		        En1 , v028
	.byte	W03
	.byte		        En1 , v072
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N03   
	.byte		N06   , Gs2 , v048
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		N12   , En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		N03   , Gs2 , v048
	.byte	W06
	.byte		N12   , En1 , v112
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v048
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En1 , v048
	.byte	W06
	.byte		N12   , En1 , v108
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , En1 , v048
	.byte		N03   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		N12   , En1 , v112
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , En1 , v100
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte		N06   , Fs2 , v064
	.byte	W03
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N12   , En1 , v100
	.byte	W12
	.byte		        En1 , v048
	.byte	W12
	.byte		        En1 , v092
	.byte	W12
	.byte		N06   , En1 , v048
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v052
	.byte	W06
	.byte		        En1 , v120
	.byte	W06
	.byte		        En1 , v052
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		        En1 , v088
	.byte	W03
	.byte		        En1 , v092
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N03   , Gs4 , v036
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		        En1 , v112
	.byte		N12   , An4 , v032
	.byte	W03
	.byte		N03   , En1 , v040
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v052
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		N06   , En1 , v120
	.byte		N03   , An4 , v016
	.byte	W06
	.byte		N06   , En1 , v040
	.byte		N12   , Gs4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   
	.byte		N03   , Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		N12   , En1 , v104
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		        En1 , v112
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 
	.byte	W03
	.byte		        En1 , v096
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		        En1 , v080
	.byte		N12   , Gs4 , v032
	.byte	W03
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		        En1 , v068
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v112
	.byte		N03   , Gs4 , v032
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		N12   , En1 , v104
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		N06   , En1 , v048
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte		N03   , An4 , v016
	.byte	W06
	.byte		N06   , En1 , v044
	.byte		N12   , Gs4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N03   , En1 , v104
	.byte		N03   , Gs4 , v032
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		        En1 , v048
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v112
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		        En1 , v104
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		N03   
	.byte		N12   , Gs4 , v032
	.byte	W03
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		        En1 , v076
	.byte	W03
	.byte		        En1 , v096
	.byte	W03
	.byte		N12   , En1 , v112
	.byte		N03   , Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		        En1 , v112
	.byte		N12   , An4 , v032
	.byte	W03
	.byte		N03   , En1 , v040
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v052
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		N06   , En1 , v120
	.byte		N03   , An4 , v016
	.byte	W06
	.byte		N06   , En1 , v040
	.byte		N12   , Gs4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   
	.byte		N03   , Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v020
	.byte	W06
	.byte		N12   , En1 , v104
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		        En1 , v112
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 
	.byte	W03
	.byte		        En1 , v092
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v032
	.byte	W03
	.byte		        En1 , v108
	.byte		N12   , Gs4 , v032
	.byte	W03
	.byte		N03   , En1 , v052
	.byte	W03
	.byte		        En1 , v064
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		        En1 , v096
	.byte		N03   , Gs4 , v032
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		        En1 , v036
	.byte		N03   , Gs4 , v016
	.byte	W03
	.byte		N12   , En1 , v104
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		N06   , En1 , v048
	.byte		N03   , An4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte		N03   , An4 , v016
	.byte	W06
	.byte		N06   , En1 , v044
	.byte		N12   , Gs4 , v032
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v096
	.byte		N03   , Gs4 , v032
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		        En1 , v112
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		N03   
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v048
	.byte	W03
	.byte		        En1 , v112
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        En1 , v036
	.byte	W03
	.byte		        En1 , v088
	.byte		N03   , An4 , v016
	.byte	W03
	.byte		        En1 , v044
	.byte	W03
	.byte		        En1 , v052
	.byte		N12   , Gs4 , v032
	.byte	W03
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		        En1 , v072
	.byte	W03
	.byte		        En1 , v080
	.byte	W03
	.byte		N24   , Gn2 
	.byte	W36
	.byte		        En2 
	.byte	W24
	.byte		N18   , Bn2 , v084
	.byte	W18
	.byte		        Cn3 
	.byte	W18
	.byte	W96
	.byte	W96
	.byte	W84
	.byte	W03
	.byte		N03   , Gs2 , v048
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gs2 , v064
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs2 
	.byte	W12
	.byte	GOTO
	 .word	mus_pyramid_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_pyramid_10:
	.byte	KEYSH , mus_pyramid_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*mus_pyramid_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
mus_pyramid_10_000:
	.byte		N03   , En4 , v064
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N01   , En4 , v064
	.byte	W03
	.byte		        En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N01   , En4 , v064
	.byte	W03
	.byte		        En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En4 , v064
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte	PEND
mus_pyramid_10_001:
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		N02   , En4 , v032
	.byte	W06
	.byte		N03   , En4 , v048
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        En4 , v064
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N06   , En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        En4 , v048
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N03   , En4 , v064
	.byte	W03
	.byte		N01   , En4 , v032
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
mus_pyramid_10_B1:
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	PATT
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
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
	 .word	mus_pyramid_10_000
	.byte	PATT
	 .word	mus_pyramid_10_001
	.byte	GOTO
	 .word	mus_pyramid_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_pyramid:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_pyramid_pri	@ Priority
	.byte	mus_pyramid_rev	@ Reverb.

	.word	mus_pyramid_grp

	.word	mus_pyramid_1
	.word	mus_pyramid_2
	.word	mus_pyramid_3
	.word	mus_pyramid_4
	.word	mus_pyramid_5
	.word	mus_pyramid_6
	.word	mus_pyramid_7
	.word	mus_pyramid_8
	.word	mus_pyramid_9
	.word	mus_pyramid_10

	.end
