	.include "MPlayDef.s"

	.equ	se_w155_grp, voicegroup128
	.equ	se_w155_pri, 4
	.equ	se_w155_rev, reverb_set+50
	.equ	se_w155_mvl, 127
	.equ	se_w155_key, 0
	.equ	se_w155_tbs, 1
	.equ	se_w155_exg, 0
	.equ	se_w155_cmp, 1

	.section .rodata
	.global	se_w155
	.align	2

@********************** Track  1 **********************@

se_w155_1:
	.byte	KEYSH , se_w155_key+0
	.byte	TEMPO , 150*se_w155_tbs/2
	.byte		VOICE , 24
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_w155_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N01   , Cn5 , v127
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		N01   , Cn6 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Cn5 
	.byte	W04
	.byte		N01   
	.byte	W01
	.byte		PAN   , c_v-11
	.byte		N01   , Cn6 
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Cn5 
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w155:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w155_pri	@ Priority
	.byte	se_w155_rev	@ Reverb.

	.word	se_w155_grp

	.word	se_w155_1

	.end
