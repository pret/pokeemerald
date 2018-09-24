	.include "MPlayDef.s"

	.equ	se_w231_grp, voicegroup128
	.equ	se_w231_pri, 4
	.equ	se_w231_rev, reverb_set+50
	.equ	se_w231_mvl, 127
	.equ	se_w231_key, 0
	.equ	se_w231_tbs, 1
	.equ	se_w231_exg, 0
	.equ	se_w231_cmp, 1

	.section .rodata
	.global	se_w231
	.align	2

@********************** Track  1 **********************@

se_w231_1:
	.byte	KEYSH , se_w231_key+0
	.byte	TEMPO , 150*se_w231_tbs/2
	.byte		VOICE , 28
	.byte		VOL   , 100*se_w231_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+16
	.byte		N03   , Gs3 , v080
	.byte	W01
	.byte		BEND  , c_v+38
	.byte	W01
	.byte		        c_v+62
	.byte	W02
	.byte		N17   , Gs4 , v096
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W02
	.byte		        c_v+0
	.byte	W03
	.byte		        c_v-8
	.byte	W02
	.byte		        c_v+0
	.byte	W02
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W05
	.byte	FINE

@********************** Track  2 **********************@

se_w231_2:
	.byte	KEYSH , se_w231_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*se_w231_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , En4 , v060
	.byte	W04
	.byte		N17   , Gs4 , v096
	.byte	W20
	.byte	FINE

@******************************************************@
	.align	2

se_w231:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w231_pri	@ Priority
	.byte	se_w231_rev	@ Reverb.

	.word	se_w231_grp

	.word	se_w231_1
	.word	se_w231_2

	.end
