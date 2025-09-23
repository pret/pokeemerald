	.include "MPlayDef.s"

	.equ	se_dex_scroll_grp, voicegroup_rs_sfx_1
	.equ	se_dex_scroll_pri, 5
	.equ	se_dex_scroll_rev, reverb_set+50
	.equ	se_dex_scroll_mvl, 127
	.equ	se_dex_scroll_key, 0
	.equ	se_dex_scroll_tbs, 1
	.equ	se_dex_scroll_exg, 0
	.equ	se_dex_scroll_cmp, 1

	.section .rodata
	.global	se_dex_scroll
	.align	2

@********************** Track  1 **********************@

se_dex_scroll_1:
	.byte	KEYSH , se_dex_scroll_key+0
	.byte	TEMPO , 100*se_dex_scroll_tbs/2
	.byte		VOICE , 4
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 40*se_dex_scroll_mvl/mxv
	.byte		BEND  , c_v+4
	.byte		N01   , Gn4 , v127
	.byte	W01
	.byte		        Gn4 , v020
	.byte	W02
	.byte	FINE

@******************************************************@
	.align	2

se_dex_scroll:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_dex_scroll_pri	@ Priority
	.byte	se_dex_scroll_rev	@ Reverb.

	.word	se_dex_scroll_grp

	.word	se_dex_scroll_1

	.end
