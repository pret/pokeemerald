	.include "MPlayDef.s"

	.equ	se_u_grp, voicegroup128
	.equ	se_u_pri, 4
	.equ	se_u_rev, reverb_set+50
	.equ	se_u_mvl, 127
	.equ	se_u_key, 0
	.equ	se_u_tbs, 1
	.equ	se_u_exg, 0
	.equ	se_u_cmp, 1

	.section .rodata
	.global	se_u
	.align	2

@********************** Track  1 **********************@

se_u_1:
	.byte	KEYSH , se_u_key+0
	.byte	TEMPO , 240*se_u_tbs/2
	.byte		VOICE , 124
	.byte		BENDR , 12
	.byte		VOL   , 127*se_u_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N72   , Cn3 , v127
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_u:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_u_pri	@ Priority
	.byte	se_u_rev	@ Reverb.

	.word	se_u_grp

	.word	se_u_1

	.end
