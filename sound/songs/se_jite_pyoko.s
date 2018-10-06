	.include "MPlayDef.s"

	.equ	se_jite_pyoko_grp, voicegroup127
	.equ	se_jite_pyoko_pri, 4
	.equ	se_jite_pyoko_rev, reverb_set+50
	.equ	se_jite_pyoko_mvl, 127
	.equ	se_jite_pyoko_key, 0
	.equ	se_jite_pyoko_tbs, 1
	.equ	se_jite_pyoko_exg, 0
	.equ	se_jite_pyoko_cmp, 1

	.section .rodata
	.global	se_jite_pyoko
	.align	2

@********************** Track  1 **********************@

se_jite_pyoko_1:
	.byte	KEYSH , se_jite_pyoko_key+0
	.byte	TEMPO , 180*se_jite_pyoko_tbs/2
	.byte		VOICE , 85
	.byte		VOL   , 90*se_jite_pyoko_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn3 , v080
	.byte	W02
	.byte		VOICE , 86
	.byte		N03   , Cn4 , v127
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_jite_pyoko:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_jite_pyoko_pri	@ Priority
	.byte	se_jite_pyoko_rev	@ Reverb.

	.word	se_jite_pyoko_grp

	.word	se_jite_pyoko_1

	.end
