	.include "MPlayDef.s"

	.equ	song_594_grp, voicegroup_86A0754
	.equ	song_594_pri, 4
	.equ	song_594_rev, 0
	.equ	song_594_mvl, 127
	.equ	song_594_key, 0
	.equ	song_594_tbs, 1
	.equ	song_594_exg, 0
	.equ	song_594_cmp, 1

	.section .rodata
	.global	song_594
	.align	2

@********************** Track  1 **********************@

song_594_1:
	.byte	KEYSH , song_594_key+0
	.byte	TEMPO , 120*song_594_tbs/2
	.byte		VOICE , 35
	.byte		VOL   , 127*song_594_mvl/mxv
	.byte		N54   , Cn3 , v127
	.byte	W54
	.byte	FINE

@******************************************************@
	.align	2

song_594:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_594_pri	@ Priority
	.byte	song_594_rev	@ Reverb.

	.word	song_594_grp

	.word	song_594_1

	.end
