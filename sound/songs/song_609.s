	.include "MPlayDef.s"

	.equ	song_609_grp, voicegroup_86A0754
	.equ	song_609_pri, 4
	.equ	song_609_rev, 0
	.equ	song_609_mvl, 127
	.equ	song_609_key, 0
	.equ	song_609_tbs, 1
	.equ	song_609_exg, 0
	.equ	song_609_cmp, 1

	.section .rodata
	.global	song_609
	.align	2

@********************** Track  1 **********************@

song_609_1:
	.byte	KEYSH , song_609_key+0
	.byte	TEMPO , 120*song_609_tbs/2
	.byte		VOICE , 50
	.byte		VOL   , 127*song_609_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_609:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_609_pri	@ Priority
	.byte	song_609_rev	@ Reverb.

	.word	song_609_grp

	.word	song_609_1

	.end
