	.include "MPlayDef.s"

	.equ	song_260_grp, voicegroup_86A0154
	.equ	song_260_pri, 5
	.equ	song_260_rev, reverb_set+50
	.equ	song_260_mvl, 127
	.equ	song_260_key, 0
	.equ	song_260_tbs, 1
	.equ	song_260_exg, 0
	.equ	song_260_cmp, 1

	.section .rodata
	.global	song_260
	.align	2

@********************** Track  1 **********************@

song_260_1:
	.byte	KEYSH , song_260_key+0
	.byte	TEMPO , 262*song_260_tbs/2
	.byte		VOICE , 123
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*song_260_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N02   , Cn2 , v120
	.byte	W08
	.byte		N04   , Cn5 
	.byte	W16
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@********************** Track  2 **********************@

song_260_2:
	.byte	KEYSH , song_260_key+0
	.byte		VOICE , 31
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 80*song_260_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-64
	.byte		TIE   , En4 , v032
	.byte	W24
	.byte	W04
	.byte		BEND  , c_v-55
	.byte	W02
	.byte		        c_v-50
	.byte	W02
	.byte		        c_v-39
	.byte	W02
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-23
	.byte	W02
	.byte		        c_v-18
	.byte	W02
	.byte		        c_v-9
	.byte	W02
	.byte		        c_v-2
	.byte	W02
	.byte		        c_v+16
	.byte	W02
	.byte		        c_v+23
	.byte	W02
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+39
	.byte	W02
	.byte		        c_v+48
	.byte	W02
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+63
	.byte	W16
	.byte	W24
	.byte	W24
	.byte		VOL   , 70*song_260_mvl/mxv
	.byte	W04
	.byte		        66*song_260_mvl/mxv
	.byte	W06
	.byte		        60*song_260_mvl/mxv
	.byte	W06
	.byte		        55*song_260_mvl/mxv
	.byte	W08
	.byte		        49*song_260_mvl/mxv
	.byte	W06
	.byte		        44*song_260_mvl/mxv
	.byte	W06
	.byte		        40*song_260_mvl/mxv
	.byte	W06
	.byte		        35*song_260_mvl/mxv
	.byte	W06
	.byte		        30*song_260_mvl/mxv
	.byte	W04
	.byte		        24*song_260_mvl/mxv
	.byte	W02
	.byte		        20*song_260_mvl/mxv
	.byte	W02
	.byte		        15*song_260_mvl/mxv
	.byte	W04
	.byte		        10*song_260_mvl/mxv
	.byte	W06
	.byte		        0*song_260_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	FINE

@********************** Track  3 **********************@

song_260_3:
	.byte	KEYSH , song_260_key+0
	.byte		VOICE , 50
	.byte		VOL   , 69*song_260_mvl/mxv
	.byte		PAN   , c_v-64
	.byte	W24
	.byte		        c_v+63
	.byte		N01   , Fs4 , v064
	.byte	W06
	.byte		        Gs4 
	.byte	W03
	.byte		PAN   , c_v-64
	.byte	W07
	.byte		N01   , En5 
	.byte	W05
	.byte		        Fs5 
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W10
	.byte		N01   , Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W07
	.byte		PAN   , c_v-64
	.byte	W04
	.byte		N01   , Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-64
	.byte	W09
	.byte		N01   , Fs5 
	.byte	W09
	.byte		        Cs5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W02
	.byte		N01   , Cs4 , v036
	.byte	W02
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte		PAN   , c_v-64
	.byte	W03
	.byte		N01   , Dn5 , v028
	.byte	W03
	.byte		        Cn5 
	.byte	W06
	.byte		        Fs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Gn4 , v020
	.byte	W02
	.byte		        An4 
	.byte	W16
	.byte	FINE

@******************************************************@
	.align	2

song_260:
	.byte	3	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_260_pri	@ Priority
	.byte	song_260_rev	@ Reverb.

	.word	song_260_grp

	.word	song_260_1
	.word	song_260_2
	.word	song_260_3

	.end
