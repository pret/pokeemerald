	.include "MPlayDef.s"

	.equ	song_576_grp, voicegroup_86A0754
	.equ	song_576_pri, 4
	.equ	song_576_rev, 0
	.equ	song_576_mvl, 127
	.equ	song_576_key, 0
	.equ	song_576_tbs, 1
	.equ	song_576_exg, 0
	.equ	song_576_cmp, 1

	.section .rodata
	.global	song_576
	.align	2

@********************** Track  1 **********************@

song_576_1:
	.byte	KEYSH , song_576_key+0
	.byte	TEMPO , 120*song_576_tbs/2
	.byte		VOICE , 17
	.byte		VOL   , 127*song_576_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_576:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_576_pri	@ Priority
	.byte	song_576_rev	@ Reverb.

	.word	song_576_grp

	.word	song_576_1

	.end
