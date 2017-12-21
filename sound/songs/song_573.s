	.include "MPlayDef.s"

	.equ	song_573_grp, voicegroup_86A0754
	.equ	song_573_pri, 4
	.equ	song_573_rev, 0
	.equ	song_573_mvl, 127
	.equ	song_573_key, 0
	.equ	song_573_tbs, 1
	.equ	song_573_exg, 0
	.equ	song_573_cmp, 1

	.section .rodata
	.global	song_573
	.align	2

@********************** Track  1 **********************@

song_573_1:
	.byte	KEYSH , song_573_key+0
	.byte	TEMPO , 120*song_573_tbs/2
	.byte		VOICE , 14
	.byte		VOL   , 127*song_573_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_573:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_573_pri	@ Priority
	.byte	song_573_rev	@ Reverb.

	.word	song_573_grp

	.word	song_573_1

	.end
