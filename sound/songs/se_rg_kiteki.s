	.include "MPlayDef.s"

	.equ	se_rg_kiteki_grp, voicegroup129
	.equ	se_rg_kiteki_pri, 5
	.equ	se_rg_kiteki_rev, reverb_set+50
	.equ	se_rg_kiteki_mvl, 127
	.equ	se_rg_kiteki_key, 0
	.equ	se_rg_kiteki_tbs, 1
	.equ	se_rg_kiteki_exg, 0
	.equ	se_rg_kiteki_cmp, 1

	.section .rodata
	.global	se_rg_kiteki
	.align	2

@********************** Track  1 **********************@

se_rg_kiteki_1:
	.byte	KEYSH , se_rg_kiteki_key+0
	.byte	TEMPO , 164*se_rg_kiteki_tbs/2
	.byte		VOICE , 9
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 96*se_rg_kiteki_mvl/mxv
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
	.byte		VOL   , 80*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v-52
	.byte	W06
	.byte		VOL   , 72*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v-41
	.byte	W06
	.byte		VOL   , 64*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W06
	.byte		VOL   , 53*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v-18
	.byte	W06
	.byte		VOL   , 48*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v+15
	.byte	W06
	.byte		VOL   , 42*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v+25
	.byte	W06
	.byte		VOL   , 32*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v+40
	.byte	W02
	.byte		VOL   , 24*se_rg_kiteki_mvl/mxv
	.byte	W04
	.byte		        16*se_rg_kiteki_mvl/mxv
	.byte		PAN   , c_v+47
	.byte	W04
	.byte		VOL   , 8*se_rg_kiteki_mvl/mxv
	.byte	W02
	.byte		EOT   
	.byte		VOL   , 0*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_rg_kiteki_2:
	.byte	KEYSH , se_rg_kiteki_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		MOD   , 15
	.byte		VOL   , 48*se_rg_kiteki_mvl/mxv
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
	.byte		VOL   , 42*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        36*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        32*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        26*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        23*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        15*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        13*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		        8*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		VOL   , 0*se_rg_kiteki_mvl/mxv
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_rg_kiteki:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_rg_kiteki_pri	@ Priority
	.byte	se_rg_kiteki_rev	@ Reverb.

	.word	se_rg_kiteki_grp

	.word	se_rg_kiteki_1
	.word	se_rg_kiteki_2

	.end
