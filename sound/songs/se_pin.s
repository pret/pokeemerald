	.include "MPlayDef.s"

	.equ	se_pin_grp, voicegroup_869D0F4
	.equ	se_pin_pri, 4
	.equ	se_pin_rev, reverb_set+50
	.equ	se_pin_mvl, 127
	.equ	se_pin_key, 0
	.equ	se_pin_tbs, 1
	.equ	se_pin_exg, 0
	.equ	se_pin_cmp, 1

	.section .rodata
	.global	se_pin
	.align	2

@********************** Track  1 **********************@

se_pin_1:
	.byte	KEYSH , se_pin_key+0
	.byte	TEMPO , 100*se_pin_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 60*se_pin_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Gn5 , v127
	.byte	W03
	.byte		        Gn6 , v112
	.byte	W03
	.byte		        Gn6 , v024
	.byte	W03
	.byte		        Gn6 , v068
	.byte	W03
	.byte		        Gn6 , v024
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_pin:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pin_pri	@ Priority
	.byte	se_pin_rev	@ Reverb.

	.word	se_pin_grp

	.word	se_pin_1

	.end
