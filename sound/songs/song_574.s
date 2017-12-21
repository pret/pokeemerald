	.include "MPlayDef.s"

	.equ	song_574_grp, voicegroup_86A0754
	.equ	song_574_pri, 4
	.equ	song_574_rev, 0
	.equ	song_574_mvl, 127
	.equ	song_574_key, 0
	.equ	song_574_tbs, 1
	.equ	song_574_exg, 0
	.equ	song_574_cmp, 1

	.section .rodata
	.global	song_574
	.align	2

@********************** Track  1 **********************@

song_574_1:
	.byte	KEYSH , song_574_key+0
	.byte	TEMPO , 120*song_574_tbs/2
	.byte		VOICE , 15
	.byte		VOL   , 127*song_574_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_574:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_574_pri	@ Priority
	.byte	song_574_rev	@ Reverb.

	.word	song_574_grp

	.word	song_574_1

	.end
