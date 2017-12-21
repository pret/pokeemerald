	.include "MPlayDef.s"

	.equ	song_565_grp, voicegroup_86A0754
	.equ	song_565_pri, 4
	.equ	song_565_rev, 0
	.equ	song_565_mvl, 127
	.equ	song_565_key, 0
	.equ	song_565_tbs, 1
	.equ	song_565_exg, 0
	.equ	song_565_cmp, 1

	.section .rodata
	.global	song_565
	.align	2

@********************** Track  1 **********************@

song_565_1:
	.byte	KEYSH , song_565_key+0
	.byte	TEMPO , 120*song_565_tbs/2
	.byte		VOICE , 6
	.byte		VOL   , 127*song_565_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_565:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_565_pri	@ Priority
	.byte	song_565_rev	@ Reverb.

	.word	song_565_grp

	.word	song_565_1

	.end
