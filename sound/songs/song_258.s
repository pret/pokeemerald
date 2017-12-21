	.include "MPlayDef.s"

	.equ	song_258_grp, voicegroup_86A0154
	.equ	song_258_pri, 5
	.equ	song_258_rev, reverb_set+50
	.equ	song_258_mvl, 127
	.equ	song_258_key, 0
	.equ	song_258_tbs, 1
	.equ	song_258_exg, 0
	.equ	song_258_cmp, 1

	.section .rodata
	.global	song_258
	.align	2

@********************** Track  1 **********************@

song_258_1:
	.byte	KEYSH , song_258_key+0
	.byte	TEMPO , 420*song_258_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 95*song_258_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N04   , Dn5 , v092
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn5 , v032
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , An4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , An4 , v032
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 , v092
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Fs4 , v032
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N04   , En4 , v092
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , En4 , v032
	.byte	W06
	.byte		PAN   , c_v-39
	.byte		N04   , Dn4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v032
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v016
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn4 , v012
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn4 , v004
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

song_258:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_258_pri	@ Priority
	.byte	song_258_rev	@ Reverb.

	.word	song_258_grp

	.word	song_258_1

	.end
