	.include "MPlayDef.s"

	.equ	song_591_grp, voicegroup_86A0754
	.equ	song_591_pri, 4
	.equ	song_591_rev, 0
	.equ	song_591_mvl, 127
	.equ	song_591_key, 0
	.equ	song_591_tbs, 1
	.equ	song_591_exg, 0
	.equ	song_591_cmp, 1

	.section .rodata
	.global	song_591
	.align	2

@********************** Track  1 **********************@

song_591_1:
	.byte	KEYSH , song_591_key+0
	.byte	TEMPO , 120*song_591_tbs/2
	.byte		VOICE , 32
	.byte		VOL   , 127*song_591_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_591:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_591_pri	@ Priority
	.byte	song_591_rev	@ Reverb.

	.word	song_591_grp

	.word	song_591_1

	.end
