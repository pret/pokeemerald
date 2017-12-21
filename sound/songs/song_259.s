	.include "MPlayDef.s"

	.equ	song_259_grp, voicegroup_86A0154
	.equ	song_259_pri, 5
	.equ	song_259_rev, reverb_set+50
	.equ	song_259_mvl, 127
	.equ	song_259_key, 0
	.equ	song_259_tbs, 1
	.equ	song_259_exg, 0
	.equ	song_259_cmp, 1

	.section .rodata
	.global	song_259
	.align	2

@********************** Track  1 **********************@

song_259_1:
	.byte	KEYSH , song_259_key+0
	.byte	TEMPO , 420*song_259_tbs/2
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*song_259_mvl/mxv
	.byte		N04   , Dn4 , v120
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N04   , Dn4 , v032
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N04   , Fs4 , v096
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N04   , Fs4 , v032
	.byte	W06
	.byte		VOICE , 92
	.byte		PAN   , c_v+0
	.byte		VOL   , 125*song_259_mvl/mxv
	.byte		N04   , An1 , v112
	.byte	W10
	.byte		MOD   , 8
	.byte	W02
	.byte		N06   , An1 , v088
	.byte	W06
	.byte		        An1 , v024
	.byte	W06
	.byte		MOD   , 0
	.byte	FINE

@******************************************************@
	.align	2

song_259:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_259_pri	@ Priority
	.byte	song_259_rev	@ Reverb.

	.word	song_259_grp

	.word	song_259_1

	.end
