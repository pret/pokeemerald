	.include "MPlayDef.s"

	.equ	se_boo_grp, voicegroup_869D0F4
	.equ	se_boo_pri, 4
	.equ	se_boo_rev, reverb_set+50
	.equ	se_boo_mvl, 127
	.equ	se_boo_key, 0
	.equ	se_boo_tbs, 1
	.equ	se_boo_exg, 0
	.equ	se_boo_cmp, 1

	.section .rodata
	.global	se_boo
	.align	2

@********************** Track  1 **********************@

se_boo_1:
	.byte	KEYSH , se_boo_key+0
	.byte	TEMPO , 100*se_boo_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		VOL   , 110*se_boo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cn3 , v127
	.byte	W03
	.byte		        Cn2 , v112
	.byte	W03
	.byte	W03
	.byte		        Cn2 , v024
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_boo:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_boo_pri	@ Priority
	.byte	se_boo_rev	@ Reverb.

	.word	se_boo_grp

	.word	se_boo_1

	.end
