	.include "MPlayDef.s"

	.equ	song_598_grp, voicegroup_86A0754
	.equ	song_598_pri, 4
	.equ	song_598_rev, 0
	.equ	song_598_mvl, 127
	.equ	song_598_key, 0
	.equ	song_598_tbs, 1
	.equ	song_598_exg, 0
	.equ	song_598_cmp, 1

	.section .rodata
	.global	song_598
	.align	2

@********************** Track  1 **********************@

song_598_1:
	.byte	KEYSH , song_598_key+0
	.byte	TEMPO , 120*song_598_tbs/2
	.byte		VOICE , 39
	.byte		VOL   , 127*song_598_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_598:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_598_pri	@ Priority
	.byte	song_598_rev	@ Reverb.

	.word	song_598_grp

	.word	song_598_1

	.end
