	.include "MPlayDef.s"

	.equ	song_253_grp, voicegroup_86A0154
	.equ	song_253_pri, 5
	.equ	song_253_rev, reverb_set+50
	.equ	song_253_mvl, 127
	.equ	song_253_key, 0
	.equ	song_253_tbs, 1
	.equ	song_253_exg, 0
	.equ	song_253_cmp, 1

	.section .rodata
	.global	song_253
	.align	2

@********************** Track  1 **********************@

song_253_1:
	.byte	KEYSH , song_253_key+0
	.byte	TEMPO , 422*song_253_tbs/2
	.byte		VOICE , 80
	.byte		VOL   , 64*song_253_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Dn4 , v084
	.byte	W02
	.byte		BEND  , c_v+17
	.byte		N03   , Fs4 , v080
	.byte	W01
	.byte		BEND  , c_v-40
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

song_253_2:
	.byte	KEYSH , song_253_key+0
	.byte		VOICE , 2
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 127*song_253_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N04   , En3 , v127
	.byte	W03
	.byte	W01
	.byte		VOICE , 2
	.byte		N02   , Bn3 
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

song_253:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_253_pri	@ Priority
	.byte	song_253_rev	@ Reverb.

	.word	song_253_grp

	.word	song_253_1
	.word	song_253_2

	.end
