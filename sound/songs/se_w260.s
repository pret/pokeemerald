	.include "MPlayDef.s"

	.equ	se_w260_grp, voicegroup128
	.equ	se_w260_pri, 4
	.equ	se_w260_rev, reverb_set+50
	.equ	se_w260_mvl, 127
	.equ	se_w260_key, 0
	.equ	se_w260_tbs, 1
	.equ	se_w260_exg, 0
	.equ	se_w260_cmp, 1

	.section .rodata
	.global	se_w260
	.align	2

@********************** Track  1 **********************@

se_w260_1:
	.byte	KEYSH , se_w260_key+0
	.byte	TEMPO , 150*se_w260_tbs/2
	.byte		VOICE , 41
	.byte		VOL   , 100*se_w260_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		N01   , Dn5 , v127
	.byte	W01
	.byte		        Gn4 
	.byte	W01
	.byte		N09   , En5 
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		VOL   , 92*se_w260_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		VOL   , 83*se_w260_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		VOL   , 71*se_w260_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v-4
	.byte	W01
	.byte		VOL   , 46*se_w260_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		VOL   , 22*se_w260_mvl/mxv
	.byte		PAN   , c_v-12
	.byte		BEND  , c_v-15
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_w260:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w260_pri	@ Priority
	.byte	se_w260_rev	@ Reverb.

	.word	se_w260_grp

	.word	se_w260_1

	.end
