	.include "MPlayDef.s"

	.equ	song_255_grp, voicegroup_86A0154
	.equ	song_255_pri, 5
	.equ	song_255_rev, reverb_set+50
	.equ	song_255_mvl, 127
	.equ	song_255_key, 0
	.equ	song_255_tbs, 1
	.equ	song_255_exg, 0
	.equ	song_255_cmp, 1

	.section .rodata
	.global	song_255
	.align	2

@********************** Track  1 **********************@

song_255_1:
	.byte	KEYSH , song_255_key+0
	.byte	TEMPO , 124*song_255_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 80*song_255_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N30   , Cn3 , v120
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

song_255:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_255_pri	@ Priority
	.byte	song_255_rev	@ Reverb.

	.word	song_255_grp

	.word	song_255_1

	.end
