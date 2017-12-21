	.include "MPlayDef.s"

	.equ	song_604_grp, voicegroup_86A0754
	.equ	song_604_pri, 4
	.equ	song_604_rev, 0
	.equ	song_604_mvl, 127
	.equ	song_604_key, 0
	.equ	song_604_tbs, 1
	.equ	song_604_exg, 0
	.equ	song_604_cmp, 1

	.section .rodata
	.global	song_604
	.align	2

@********************** Track  1 **********************@

song_604_1:
	.byte	KEYSH , song_604_key+0
	.byte	TEMPO , 120*song_604_tbs/2
	.byte		VOICE , 45
	.byte		VOL   , 127*song_604_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_604:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_604_pri	@ Priority
	.byte	song_604_rev	@ Reverb.

	.word	song_604_grp

	.word	song_604_1

	.end
