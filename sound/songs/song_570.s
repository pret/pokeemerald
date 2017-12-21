	.include "MPlayDef.s"

	.equ	song_570_grp, voicegroup_86A0754
	.equ	song_570_pri, 4
	.equ	song_570_rev, 0
	.equ	song_570_mvl, 127
	.equ	song_570_key, 0
	.equ	song_570_tbs, 1
	.equ	song_570_exg, 0
	.equ	song_570_cmp, 1

	.section .rodata
	.global	song_570
	.align	2

@********************** Track  1 **********************@

song_570_1:
	.byte	KEYSH , song_570_key+0
	.byte	TEMPO , 120*song_570_tbs/2
	.byte		VOICE , 11
	.byte		VOL   , 127*song_570_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_570:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_570_pri	@ Priority
	.byte	song_570_rev	@ Reverb.

	.word	song_570_grp

	.word	song_570_1

	.end
