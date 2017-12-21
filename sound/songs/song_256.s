	.include "MPlayDef.s"

	.equ	song_256_grp, voicegroup_86A0154
	.equ	song_256_pri, 5
	.equ	song_256_rev, reverb_set+50
	.equ	song_256_mvl, 127
	.equ	song_256_key, 0
	.equ	song_256_tbs, 1
	.equ	song_256_exg, 0
	.equ	song_256_cmp, 1

	.section .rodata
	.global	song_256
	.align	2

@********************** Track  1 **********************@

song_256_1:
	.byte	KEYSH , song_256_key+0
	.byte	TEMPO , 164*song_256_tbs/2
	.byte		VOICE , 9
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*song_256_mvl/mxv
	.byte		MOD   , 1
	.byte		N04   , En2 , v127
	.byte	W04
	.byte		N10   , En2 , v104
	.byte	W20
	.byte	W10
	.byte		PAN   , c_v-64
	.byte		TIE   , En2 , v127
	.byte	W08
	.byte		PAN   , c_v-48
	.byte	W06
	.byte	W02
	.byte		        c_v-32
	.byte	W08
	.byte		        c_v-16
	.byte	W08
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+31
	.byte	W06
	.byte		        c_v+48
	.byte	W06
	.byte		        c_v+63
	.byte	W06
	.byte	W18
	.byte		        c_v+47
	.byte	W06
	.byte		        c_v+40
	.byte	W06
	.byte		        c_v+30
	.byte	W06
	.byte		        c_v+10
	.byte	W06
	.byte		        c_v-11
	.byte	W06
	.byte		        c_v-25
	.byte	W06
	.byte		        c_v-34
	.byte	W06
	.byte		        c_v-50
	.byte	W06
	.byte		        c_v-64
	.byte	W06
	.byte	W18
	.byte		VOL   , 80*song_256_mvl/mxv
	.byte		PAN   , c_v-52
	.byte	W06
	.byte		VOL   , 72*song_256_mvl/mxv
	.byte		PAN   , c_v-41
	.byte	W06
	.byte		VOL   , 64*song_256_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W06
	.byte		VOL   , 53*song_256_mvl/mxv
	.byte		PAN   , c_v-18
	.byte	W06
	.byte		VOL   , 48*song_256_mvl/mxv
	.byte		PAN   , c_v+15
	.byte	W06
	.byte		VOL   , 42*song_256_mvl/mxv
	.byte		PAN   , c_v+25
	.byte	W06
	.byte		VOL   , 32*song_256_mvl/mxv
	.byte		PAN   , c_v+40
	.byte	W02
	.byte		VOL   , 24*song_256_mvl/mxv
	.byte	W04
	.byte		        16*song_256_mvl/mxv
	.byte		PAN   , c_v+47
	.byte	W04
	.byte		VOL   , 8*song_256_mvl/mxv
	.byte	W02
	.byte		EOT   
	.byte		VOL   , 0*song_256_mvl/mxv
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

song_256_2:
	.byte	KEYSH , song_256_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		MOD   , 15
	.byte		VOL   , 48*song_256_mvl/mxv
	.byte		N04   , En1 , v127
	.byte	W04
	.byte		N10   , En1 , v104
	.byte	W20
	.byte	W10
	.byte		TIE   , En1 , v127
	.byte	W14
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W18
	.byte		VOL   , 42*song_256_mvl/mxv
	.byte	W06
	.byte		        36*song_256_mvl/mxv
	.byte	W06
	.byte		        32*song_256_mvl/mxv
	.byte	W06
	.byte		        26*song_256_mvl/mxv
	.byte	W06
	.byte		        23*song_256_mvl/mxv
	.byte	W06
	.byte		        15*song_256_mvl/mxv
	.byte	W06
	.byte		        13*song_256_mvl/mxv
	.byte	W06
	.byte		        8*song_256_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		VOL   , 0*song_256_mvl/mxv
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

song_256:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_256_pri	@ Priority
	.byte	song_256_rev	@ Reverb.

	.word	song_256_grp

	.word	song_256_1
	.word	song_256_2

	.end
