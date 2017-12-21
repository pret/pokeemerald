	.include "MPlayDef.s"

	.equ	song_567_grp, voicegroup_86A0754
	.equ	song_567_pri, 4
	.equ	song_567_rev, 0
	.equ	song_567_mvl, 127
	.equ	song_567_key, 0
	.equ	song_567_tbs, 1
	.equ	song_567_exg, 0
	.equ	song_567_cmp, 1

	.section .rodata
	.global	song_567
	.align	2

@********************** Track  1 **********************@

song_567_1:
	.byte	KEYSH , song_567_key+0
	.byte	TEMPO , 120*song_567_tbs/2
	.byte		VOICE , 8
	.byte		VOL   , 127*song_567_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_567:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_567_pri	@ Priority
	.byte	song_567_rev	@ Reverb.

	.word	song_567_grp

	.word	song_567_1

	.end
