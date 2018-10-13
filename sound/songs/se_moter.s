	.include "MPlayDef.s"

	.equ	se_moter_grp, voicegroup128
	.equ	se_moter_pri, 4
	.equ	se_moter_rev, reverb_set+50
	.equ	se_moter_mvl, 127
	.equ	se_moter_key, 0
	.equ	se_moter_tbs, 1
	.equ	se_moter_exg, 0
	.equ	se_moter_cmp, 1

	.section .rodata
	.global	se_moter
	.align	2

@********************** Track  1 **********************@

se_moter_1:
	.byte	KEYSH , se_moter_key+0
se_moter_1_B1:
	.byte	TEMPO , 150*se_moter_tbs/2
	.byte		VOICE , 15
	.byte		VOL   , 90*se_moter_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte		TIE   , Gn2 , v100
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		EOT   
	.byte	GOTO
	 .word	se_moter_1_B1
	.byte	W48
	.byte	FINE

@******************************************************@
	.align	2

se_moter:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_moter_pri	@ Priority
	.byte	se_moter_rev	@ Reverb.

	.word	se_moter_grp

	.word	se_moter_1

	.end
