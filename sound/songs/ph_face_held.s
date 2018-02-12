	.include "MPlayDef.s"

	.equ	ph_face_held_grp, voicegroup_86A0754
	.equ	ph_face_held_pri, 4
	.equ	ph_face_held_rev, 0
	.equ	ph_face_held_mvl, 127
	.equ	ph_face_held_key, 0
	.equ	ph_face_held_tbs, 1
	.equ	ph_face_held_exg, 0
	.equ	ph_face_held_cmp, 1

	.section .rodata
	.global	ph_face_held
	.align	2

@********************** Track  1 **********************@

ph_face_held_1:
	.byte	KEYSH , ph_face_held_key+0
	.byte	TEMPO , 120*ph_face_held_tbs/2
	.byte		VOICE , 4
	.byte		VOL   , 127*ph_face_held_mvl/mxv
	.byte		TIE   , Cn3 , v127
	.byte	W96
ph_face_held_1_B1:
	.byte	W96
	.byte	GOTO
	 .word	ph_face_held_1_B1
	.byte	W48
	.byte		EOT   , Cn3 
	.byte	FINE

@******************************************************@
	.align	2

ph_face_held:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	ph_face_held_pri	@ Priority
	.byte	ph_face_held_rev	@ Reverb.

	.word	ph_face_held_grp

	.word	ph_face_held_1

	.end
