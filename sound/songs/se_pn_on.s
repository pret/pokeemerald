	.include "MPlayDef.s"

	.equ	se_pn_on_grp, voicegroup_869D0F4
	.equ	se_pn_on_pri, 5
	.equ	se_pn_on_rev, reverb_set+50
	.equ	se_pn_on_mvl, 127
	.equ	se_pn_on_key, 0
	.equ	se_pn_on_tbs, 1
	.equ	se_pn_on_exg, 0
	.equ	se_pn_on_cmp, 1

	.section .rodata
	.global	se_pn_on
	.align	2

@********************** Track  1 **********************@

se_pn_on_1:
	.byte	KEYSH , se_pn_on_key+0
	.byte	TEMPO , 144*se_pn_on_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_pn_on_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W03
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W03
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_pn_on_2:
	.byte	KEYSH , se_pn_on_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_pn_on_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		N01   , Cn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Cn4 , v060
	.byte	W02
	.byte		        Cn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Cn5 , v060
	.byte	W02
	.byte		        Cn5 , v032
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_pn_on:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pn_on_pri	@ Priority
	.byte	se_pn_on_rev	@ Reverb.

	.word	se_pn_on_grp

	.word	se_pn_on_1
	.word	se_pn_on_2

	.end
