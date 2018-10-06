	.include "MPlayDef.s"

	.equ	se_kaidan_grp, voicegroup127
	.equ	se_kaidan_pri, 5
	.equ	se_kaidan_rev, reverb_set+50
	.equ	se_kaidan_mvl, 127
	.equ	se_kaidan_key, 0
	.equ	se_kaidan_tbs, 1
	.equ	se_kaidan_exg, 0
	.equ	se_kaidan_cmp, 1

	.section .rodata
	.global	se_kaidan
	.align	2

@********************** Track  1 **********************@

se_kaidan_1:
	.byte	KEYSH , se_kaidan_key+0
	.byte	TEMPO , 120*se_kaidan_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 120*se_kaidan_mvl/mxv
	.byte		N02   , An2 , v068
	.byte	W02
	.byte		        Cn3 , v127
	.byte	W01
	.byte	W01
	.byte		        En4 , v068
	.byte	W02
	.byte	W03
	.byte	W03
	.byte		        An2 
	.byte	W02
	.byte		        Cn3 , v100
	.byte	W01
	.byte	W01
	.byte		        En4 , v068
	.byte	W02
	.byte	W03
	.byte	W03
	.byte		        An2 , v032
	.byte	W02
	.byte		        Cn3 , v052
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_kaidan:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_kaidan_pri	@ Priority
	.byte	se_kaidan_rev	@ Reverb.

	.word	se_kaidan_grp

	.word	se_kaidan_1

	.end
