	.include "MPlayDef.s"

	.equ	song_262_grp, voicegroup_869D0F4
	.equ	song_262_pri, 5
	.equ	song_262_rev, reverb_set+50
	.equ	song_262_mvl, 127
	.equ	song_262_key, 0
	.equ	song_262_tbs, 1
	.equ	song_262_exg, 0
	.equ	song_262_cmp, 1

	.section .rodata
	.global	song_262
	.align	2

@********************** Track  1 **********************@

song_262_1:
	.byte	KEYSH , song_262_key+0
	.byte	TEMPO , 240*song_262_tbs/2
	.byte		VOICE , 92
	.byte		BENDR , 12
	.byte		VOL   , 127*song_262_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn2 , v127
	.byte	W03
	.byte		        Cn2 , v020
	.byte	W03
	.byte		N18   , Cn2 , v127
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N09   , Cn2 , v020
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

song_262:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_262_pri	@ Priority
	.byte	song_262_rev	@ Reverb.

	.word	song_262_grp

	.word	song_262_1

	.end
