	.include "MPlayDef.s"

	.equ	song_257_grp, voicegroup_86A0154
	.equ	song_257_pri, 5
	.equ	song_257_rev, reverb_set+50
	.equ	song_257_mvl, 127
	.equ	song_257_key, 0
	.equ	song_257_tbs, 1
	.equ	song_257_exg, 0
	.equ	song_257_cmp, 1

	.section .rodata
	.global	song_257
	.align	2

@********************** Track  1 **********************@

song_257_1:
	.byte	KEYSH , song_257_key+0
	.byte	TEMPO , 420*song_257_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 96*song_257_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N04   , Dn4 , v096
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn4 , v032
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   , Fs4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Fs4 , v032
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N04   , An4 , v096
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , An4 , v032
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N04   , Cs5 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Cs5 , v032
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , Dn5 , v076
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn5 , v032
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn5 , v024
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn5 , v016
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Dn5 , v008
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn5 , v004
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

song_257:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_257_pri	@ Priority
	.byte	song_257_rev	@ Reverb.

	.word	song_257_grp

	.word	song_257_1

	.end
