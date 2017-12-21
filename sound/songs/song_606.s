	.include "MPlayDef.s"

	.equ	song_606_grp, voicegroup_86A0754
	.equ	song_606_pri, 4
	.equ	song_606_rev, 0
	.equ	song_606_mvl, 127
	.equ	song_606_key, 0
	.equ	song_606_tbs, 1
	.equ	song_606_exg, 0
	.equ	song_606_cmp, 1

	.section .rodata
	.global	song_606
	.align	2

@********************** Track  1 **********************@

song_606_1:
	.byte	KEYSH , song_606_key+0
	.byte	TEMPO , 120*song_606_tbs/2
	.byte		VOICE , 47
	.byte		VOL   , 127*song_606_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_606:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_606_pri	@ Priority
	.byte	song_606_rev	@ Reverb.

	.word	song_606_grp

	.word	song_606_1

	.end
