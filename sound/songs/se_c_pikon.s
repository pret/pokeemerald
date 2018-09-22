	.include "MPlayDef.s"

	.equ	se_c_pikon_grp, voicegroup128
	.equ	se_c_pikon_pri, 5
	.equ	se_c_pikon_rev, reverb_set+50
	.equ	se_c_pikon_mvl, 127
	.equ	se_c_pikon_key, 0
	.equ	se_c_pikon_tbs, 1
	.equ	se_c_pikon_exg, 0
	.equ	se_c_pikon_cmp, 1

	.section .rodata
	.global	se_c_pikon
	.align	2

@********************** Track  1 **********************@

se_c_pikon_1:
	.byte	KEYSH , se_c_pikon_key+0
	.byte	TEMPO , 150*se_c_pikon_tbs/2
	.byte		VOICE , 14
	.byte		VOL   , 90*se_c_pikon_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N02   , Cn5 , v112
	.byte	W02
	.byte		        Cn6 
	.byte	W04
	.byte	W01
	.byte		        Cn6 , v060
	.byte	W05
	.byte	W02
	.byte		        Cn5 , v112
	.byte	W02
	.byte		        Cn6 
	.byte	W02
	.byte	W03
	.byte		        Cn6 , v060
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_c_pikon:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_c_pikon_pri	@ Priority
	.byte	se_c_pikon_rev	@ Reverb.

	.word	se_c_pikon_grp

	.word	se_c_pikon_1

	.end
