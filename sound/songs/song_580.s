	.include "MPlayDef.s"

	.equ	song_580_grp, voicegroup_86A0754
	.equ	song_580_pri, 4
	.equ	song_580_rev, 0
	.equ	song_580_mvl, 127
	.equ	song_580_key, 0
	.equ	song_580_tbs, 1
	.equ	song_580_exg, 0
	.equ	song_580_cmp, 1

	.section .rodata
	.global	song_580
	.align	2

@********************** Track  1 **********************@

song_580_1:
	.byte	KEYSH , song_580_key+0
	.byte	TEMPO , 120*song_580_tbs/2
	.byte		VOICE , 21
	.byte		VOL   , 127*song_580_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_580:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_580_pri	@ Priority
	.byte	song_580_rev	@ Reverb.

	.word	song_580_grp

	.word	song_580_1

	.end
