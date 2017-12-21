	.include "MPlayDef.s"

	.equ	song_603_grp, voicegroup_86A0754
	.equ	song_603_pri, 4
	.equ	song_603_rev, 0
	.equ	song_603_mvl, 127
	.equ	song_603_key, 0
	.equ	song_603_tbs, 1
	.equ	song_603_exg, 0
	.equ	song_603_cmp, 1

	.section .rodata
	.global	song_603
	.align	2

@********************** Track  1 **********************@

song_603_1:
	.byte	KEYSH , song_603_key+0
	.byte	TEMPO , 120*song_603_tbs/2
	.byte		VOICE , 44
	.byte		VOL   , 127*song_603_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_603:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_603_pri	@ Priority
	.byte	song_603_rev	@ Reverb.

	.word	song_603_grp

	.word	song_603_1

	.end
