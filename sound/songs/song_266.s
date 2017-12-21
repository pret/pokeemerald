	.include "MPlayDef.s"

	.equ	song_266_grp, voicegroup_86A0154
	.equ	song_266_pri, 5
	.equ	song_266_rev, reverb_set+50
	.equ	song_266_mvl, 127
	.equ	song_266_key, 0
	.equ	song_266_tbs, 1
	.equ	song_266_exg, 0
	.equ	song_266_cmp, 1

	.section .rodata
	.global	song_266
	.align	2

@********************** Track  1 **********************@

song_266_1:
	.byte	KEYSH , song_266_key+0
	.byte	TEMPO , 92*song_266_tbs/2
	.byte		VOICE , 116
	.byte		VOL   , 127*song_266_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		N04   , Fn3 , v127
	.byte	W04
	.byte		VOICE , 10
	.byte		N04   , Cn3 
	.byte	W05
	.byte		VOICE , 116
	.byte		N32   , Fn3 
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@********************** Track  2 **********************@

song_266_2:
	.byte	KEYSH , song_266_key+0
	.byte		VOICE , 117
	.byte		VOL   , 127*song_266_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+1
	.byte		N04   , Gn3 , v100
	.byte	W04
	.byte		        Dn3 
	.byte	W05
	.byte		N32   , Gn3 
	.byte	W03
	.byte	W12
	.byte	W12
	.byte	W12
	.byte	FINE

@******************************************************@
	.align	2

song_266:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_266_pri	@ Priority
	.byte	song_266_rev	@ Reverb.

	.word	song_266_grp

	.word	song_266_1
	.word	song_266_2

	.end
