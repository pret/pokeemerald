	.include "MPlayDef.s"

	.equ	se_hinsi_grp, voicegroup127
	.equ	se_hinsi_pri, 3
	.equ	se_hinsi_rev, reverb_set+50
	.equ	se_hinsi_mvl, 127
	.equ	se_hinsi_key, 0
	.equ	se_hinsi_tbs, 1
	.equ	se_hinsi_exg, 0
	.equ	se_hinsi_cmp, 1

	.section .rodata
	.global	se_hinsi
	.align	2

@********************** Track  1 **********************@

se_hinsi_1:
	.byte	KEYSH , se_hinsi_key+0
se_hinsi_1_B1:
	.byte	TEMPO , 150*se_hinsi_tbs/2
	.byte		VOICE , 15
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_hinsi_mvl/mxv
	.byte		BEND  , c_v+17
	.byte		N12   , Dn4 , v080
	.byte	W12
	.byte		BEND  , c_v+31
	.byte		N12   , An3 
	.byte	W12
	.byte	W12
	.byte	GOTO
	 .word	se_hinsi_1_B1
	.byte	FINE

@******************************************************@
	.align	2

se_hinsi:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_hinsi_pri	@ Priority
	.byte	se_hinsi_rev	@ Reverb.

	.word	se_hinsi_grp

	.word	se_hinsi_1

	.end
