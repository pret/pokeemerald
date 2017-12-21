	.include "MPlayDef.s"

	.equ	song_562_grp, voicegroup_86A0754
	.equ	song_562_pri, 4
	.equ	song_562_rev, 0
	.equ	song_562_mvl, 127
	.equ	song_562_key, 0
	.equ	song_562_tbs, 1
	.equ	song_562_exg, 0
	.equ	song_562_cmp, 1

	.section .rodata
	.global	song_562
	.align	2

@********************** Track  1 **********************@

song_562_1:
	.byte	KEYSH , song_562_key+0
	.byte	TEMPO , 120*song_562_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 127*song_562_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_562:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_562_pri	@ Priority
	.byte	song_562_rev	@ Reverb.

	.word	song_562_grp

	.word	song_562_1

	.end
