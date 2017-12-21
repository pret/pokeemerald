	.include "MPlayDef.s"

	.equ	se_fu_zaku2_grp, voicegroup_869D0F4
	.equ	se_fu_zaku2_pri, 4
	.equ	se_fu_zaku2_rev, reverb_set+50
	.equ	se_fu_zaku2_mvl, 127
	.equ	se_fu_zaku2_key, 0
	.equ	se_fu_zaku2_tbs, 1
	.equ	se_fu_zaku2_exg, 0
	.equ	se_fu_zaku2_cmp, 1

	.section .rodata
	.global	se_fu_zaku2
	.align	2

@********************** Track  1 **********************@

se_fu_zaku2_1:
	.byte	KEYSH , se_fu_zaku2_key+0
	.byte	TEMPO , 150*se_fu_zaku2_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 110*se_fu_zaku2_mvl/mxv
	.byte		N01   , An2 , v112
	.byte	W01
	.byte		        En3 
	.byte	W01
	.byte		        Gn3 
	.byte	W01
	.byte	W02
	.byte		N02   , Cn3 , v092
	.byte	W01
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_fu_zaku2:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_fu_zaku2_pri	@ Priority
	.byte	se_fu_zaku2_rev	@ Reverb.

	.word	se_fu_zaku2_grp

	.word	se_fu_zaku2_1

	.end
