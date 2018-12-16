	.include "MPlayDef.s"

	.equ	se_tu_saa_grp, voicegroup127
	.equ	se_tu_saa_pri, 4
	.equ	se_tu_saa_rev, reverb_set+50
	.equ	se_tu_saa_mvl, 127
	.equ	se_tu_saa_key, 0
	.equ	se_tu_saa_tbs, 1
	.equ	se_tu_saa_exg, 0
	.equ	se_tu_saa_cmp, 1

	.section .rodata
	.global	se_tu_saa
	.align	2

@********************** Track  1 **********************@

se_tu_saa_1:
	.byte	KEYSH , se_tu_saa_key+0
	.byte	TEMPO , 220*se_tu_saa_tbs/2
	.byte		VOICE , 123
	.byte		VOL   , 90*se_tu_saa_mvl/mxv
	.byte		N03   , Cn4 , v060
	.byte	W03
	.byte		VOL   , 62*se_tu_saa_mvl/mxv
	.byte		N32   , Gs4
	.byte	W03
	.byte		VOL   , 68*se_tu_saa_mvl/mxv
	.byte	W03
	.byte		        72*se_tu_saa_mvl/mxv
	.byte	W03
	.byte		        78*se_tu_saa_mvl/mxv
	.byte	W03
	.byte		        85*se_tu_saa_mvl/mxv
	.byte	W03
	.byte		        90*se_tu_saa_mvl/mxv
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_tu_saa:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_tu_saa_pri	@ Priority
	.byte	se_tu_saa_rev	@ Reverb.

	.word	se_tu_saa_grp

	.word	se_tu_saa_1

	.end
