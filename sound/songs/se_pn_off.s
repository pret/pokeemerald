	.include "MPlayDef.s"

	.equ	se_pn_off_grp, voicegroup_869D0F4
	.equ	se_pn_off_pri, 5
	.equ	se_pn_off_rev, reverb_set+50
	.equ	se_pn_off_mvl, 127
	.equ	se_pn_off_key, 0
	.equ	se_pn_off_tbs, 1
	.equ	se_pn_off_exg, 0
	.equ	se_pn_off_cmp, 1

	.section .rodata
	.global	se_pn_off
	.align	2

@********************** Track  1 **********************@

se_pn_off_1:
	.byte	KEYSH , se_pn_off_key+0
	.byte	TEMPO , 144*se_pn_off_tbs/2
	.byte		VOICE , 4
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 100*se_pn_off_mvl/mxv
	.byte		BEND  , c_v-6
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W03
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W03
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_pn_off_2:
	.byte	KEYSH , se_pn_off_key+0
	.byte		VOICE , 14
	.byte		VOL   , 50*se_pn_off_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		N01   , Gn4 , v032
	.byte	W01
	.byte		N02   , Dn4 , v060
	.byte	W02
	.byte	W01
	.byte		N01   , Dn4 , v032
	.byte	W01
	.byte		N02   , Gn4 , v060
	.byte	W02
	.byte		        Gn4 , v032
	.byte	W02
	.byte	W01
	.byte		        Gn3 , v060
	.byte	W02
	.byte		        Gn3 , v032
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_pn_off:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_pn_off_pri	@ Priority
	.byte	se_pn_off_rev	@ Reverb.

	.word	se_pn_off_grp

	.word	se_pn_off_1
	.word	se_pn_off_2

	.end
