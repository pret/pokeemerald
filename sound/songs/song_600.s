	.include "MPlayDef.s"

	.equ	song_600_grp, voicegroup_86A0754
	.equ	song_600_pri, 4
	.equ	song_600_rev, 0
	.equ	song_600_mvl, 127
	.equ	song_600_key, 0
	.equ	song_600_tbs, 1
	.equ	song_600_exg, 0
	.equ	song_600_cmp, 1

	.section .rodata
	.global	song_600
	.align	2

@********************** Track  1 **********************@

song_600_1:
	.byte	KEYSH , song_600_key+0
	.byte	TEMPO , 120*song_600_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 127*song_600_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_600:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_600_pri	@ Priority
	.byte	song_600_rev	@ Reverb.

	.word	song_600_grp

	.word	song_600_1

	.end
