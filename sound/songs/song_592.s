	.include "MPlayDef.s"

	.equ	song_592_grp, voicegroup_86A0754
	.equ	song_592_pri, 4
	.equ	song_592_rev, 0
	.equ	song_592_mvl, 127
	.equ	song_592_key, 0
	.equ	song_592_tbs, 1
	.equ	song_592_exg, 0
	.equ	song_592_cmp, 1

	.section .rodata
	.global	song_592
	.align	2

@********************** Track  1 **********************@

song_592_1:
	.byte	KEYSH , song_592_key+0
	.byte	TEMPO , 120*song_592_tbs/2
	.byte		VOICE , 33
	.byte		VOL   , 127*song_592_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_592:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_592_pri	@ Priority
	.byte	song_592_rev	@ Reverb.

	.word	song_592_grp

	.word	song_592_1

	.end
