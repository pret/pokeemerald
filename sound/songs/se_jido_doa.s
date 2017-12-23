	.include "MPlayDef.s"

	.equ	se_jido_doa_grp, voicegroup_869D6F4
	.equ	se_jido_doa_pri, 4
	.equ	se_jido_doa_rev, reverb_set+50
	.equ	se_jido_doa_mvl, 127
	.equ	se_jido_doa_key, 0
	.equ	se_jido_doa_tbs, 1
	.equ	se_jido_doa_exg, 0
	.equ	se_jido_doa_cmp, 1

	.section .rodata
	.global	se_jido_doa
	.align	2

@********************** Track  1 **********************@

se_jido_doa_1:
	.byte	KEYSH , se_jido_doa_key+0
	.byte	TEMPO , 120*se_jido_doa_tbs/2
	.byte		VOICE , 1
	.byte		VOL   , 95*se_jido_doa_mvl/mxv
	.byte		N12   , Cn2 , v127
	.byte	W12
	.byte		VOL   , 0*se_jido_doa_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

se_jido_doa:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_jido_doa_pri	@ Priority
	.byte	se_jido_doa_rev	@ Reverb.

	.word	se_jido_doa_grp

	.word	se_jido_doa_1

	.end
