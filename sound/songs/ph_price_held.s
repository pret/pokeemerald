	.include "MPlayDef.s"

	.equ	ph_price_held_grp, voicegroup130
	.equ	ph_price_held_pri, 4
	.equ	ph_price_held_rev, 0
	.equ	ph_price_held_mvl, 127
	.equ	ph_price_held_key, 0
	.equ	ph_price_held_tbs, 1
	.equ	ph_price_held_exg, 0
	.equ	ph_price_held_cmp, 1

	.section .rodata
	.global	ph_price_held
	.align	2

@********************** Track  1 **********************@

ph_price_held_1:
	.byte	KEYSH , ph_price_held_key+0
	.byte	TEMPO , 120*ph_price_held_tbs/2
	.byte		VOICE , 19
	.byte		VOL   , 117*ph_price_held_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
ph_price_held_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	ph_price_held_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

ph_price_held:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ph_price_held_pri	@ Priority
	.byte	ph_price_held_rev	@ Reverb.

	.word	ph_price_held_grp

	.word	ph_price_held_1

	.end
