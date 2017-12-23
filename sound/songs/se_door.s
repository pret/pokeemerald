	.include "MPlayDef.s"

	.equ	se_door_grp, voicegroup_869D0F4
	.equ	se_door_pri, 5
	.equ	se_door_rev, reverb_set+50
	.equ	se_door_mvl, 127
	.equ	se_door_key, 0
	.equ	se_door_tbs, 1
	.equ	se_door_exg, 0
	.equ	se_door_cmp, 1

	.section .rodata
	.global	se_door
	.align	2

@********************** Track  1 **********************@

se_door_1:
	.byte	KEYSH , se_door_key+0
	.byte	TEMPO , 110*se_door_tbs/2
	.byte		VOICE , 127
	.byte		VOL   , 80*se_door_mvl/mxv
	.byte		N03   , Dn3 , v127
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W18
	.byte	FINE

@******************************************************@
	.align	2

se_door:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_door_pri	@ Priority
	.byte	se_door_rev	@ Reverb.

	.word	se_door_grp

	.word	se_door_1

	.end
