	.include "MPlayDef.s"

	.equ	se_fu_zaku_grp, voicegroup_869D0F4
	.equ	se_fu_zaku_pri, 4
	.equ	se_fu_zaku_rev, reverb_set+50
	.equ	se_fu_zaku_mvl, 127
	.equ	se_fu_zaku_key, 0
	.equ	se_fu_zaku_tbs, 1
	.equ	se_fu_zaku_exg, 0
	.equ	se_fu_zaku_cmp, 1

	.section .rodata
	.global	se_fu_zaku
	.align	2

@********************** Track  1 **********************@

se_fu_zaku_1:
	.byte	KEYSH , se_fu_zaku_key+0
	.byte	TEMPO , 150*se_fu_zaku_tbs/2
	.byte		VOICE , 126
	.byte		VOL   , 120*se_fu_zaku_mvl/mxv
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W08
	.byte		N01   , Cn3 , v068
	.byte	W01
	.byte		        En3 , v064
	.byte	W01
	.byte		        Gn3 
	.byte	W03
	.byte		N02   , An2 , v048
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_fu_zaku:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_fu_zaku_pri	@ Priority
	.byte	se_fu_zaku_rev	@ Reverb.

	.word	se_fu_zaku_grp

	.word	se_fu_zaku_1

	.end
