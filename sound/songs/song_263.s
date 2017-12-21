	.include "MPlayDef.s"

	.equ	song_263_grp, voicegroup_86A0154
	.equ	song_263_pri, 5
	.equ	song_263_rev, reverb_set+50
	.equ	song_263_mvl, 127
	.equ	song_263_key, 0
	.equ	song_263_tbs, 1
	.equ	song_263_exg, 0
	.equ	song_263_cmp, 1

	.section .rodata
	.global	song_263
	.align	2

@********************** Track  1 **********************@

song_263_1:
	.byte	KEYSH , song_263_key+0
	.byte	TEMPO , 136*song_263_tbs/2
	.byte		VOICE , 13
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 120*song_263_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N01   , An5 , v064
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        An5 
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        Fs6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        An5 
	.byte	W01
	.byte		        Fs6 
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte		N01   
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        An5 
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        Fs6 
	.byte	W02
	.byte		        An5 
	.byte	W01
	.byte		        Dn6 
	.byte	W01
	.byte		        An5 
	.byte	W01
	.byte		        Fs6 
	.byte	W01
	.byte		        An5 
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

song_263_2:
	.byte	KEYSH , song_263_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 45*song_263_mvl/mxv
	.byte		MOD   , 2
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+2
	.byte		N01   , Dn5 , v064
	.byte	W01
	.byte		        Fs5 
	.byte	W01
	.byte		PAN   , c_v-62
	.byte		N01   , Dn5 
	.byte	W01
	.byte		        Fs5 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , An5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte		PAN   , c_v-61
	.byte		N01   , Fs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , An5 
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte		PAN   , c_v-61
	.byte		N01   
	.byte	W01
	.byte		        Fs5 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , Dn5 
	.byte	W01
	.byte		        Fs5 
	.byte	W01
	.byte		PAN   , c_v-61
	.byte		N01   , An5 
	.byte	W02
	.byte		        Dn5 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 
	.byte	W01
	.byte		        Dn5 
	.byte	W01
	.byte		PAN   , c_v-61
	.byte		N01   , An5 
	.byte	W01
	.byte		        Dn5 
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

song_263:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	song_263_pri	@ Priority
	.byte	song_263_rev	@ Reverb.

	.word	song_263_grp

	.word	song_263_1
	.word	song_263_2

	.end
