	.include "MPlayDef.s"

	.equ	song_250_grp, voicegroup_86A0154
	.equ	song_250_pri, 5
	.equ	song_250_rev, reverb_set+50
	.equ	song_250_mvl, 127
	.equ	song_250_key, 0
	.equ	song_250_tbs, 1
	.equ	song_250_exg, 0
	.equ	song_250_cmp, 1

	.section .rodata
	.global	song_250
	.align	2

@********************** Track  1 **********************@

song_250_1:
	.byte	KEYSH , song_250_key+0
	.byte	TEMPO , 182*song_250_tbs/2
	.byte		VOICE , 125
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 16*song_250_mvl/mxv
	.byte		BEND  , c_v+2
	.byte		N24   , Gn5 , v088
	.byte	W03
	.byte		VOL   , 32*song_250_mvl/mxv
	.byte	W03
	.byte		        48*song_250_mvl/mxv
	.byte	W03
	.byte		        64*song_250_mvl/mxv
	.byte	W03
	.byte		        80*song_250_mvl/mxv
	.byte	W03
	.byte		        96*song_250_mvl/mxv
	.byte	W03
	.byte		        112*song_250_mvl/mxv
	.byte	W03
	.byte		        127*song_250_mvl/mxv
	.byte	W03
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

song_250:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_250_pri	@ Priority
	.byte	song_250_rev	@ Reverb.

	.word	song_250_grp

	.word	song_250_1

	.end
