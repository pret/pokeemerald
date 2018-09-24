	.include "MPlayDef.s"

	.equ	se_w258_grp, voicegroup128
	.equ	se_w258_pri, 4
	.equ	se_w258_rev, reverb_set+50
	.equ	se_w258_mvl, 127
	.equ	se_w258_key, 0
	.equ	se_w258_tbs, 1
	.equ	se_w258_exg, 0
	.equ	se_w258_cmp, 1

	.section .rodata
	.global	se_w258
	.align	2

@********************** Track  1 **********************@

se_w258_1:
	.byte	KEYSH , se_w258_key+0
	.byte	TEMPO , 150*se_w258_tbs/2
	.byte		VOICE , 3
	.byte		VOL   , 100*se_w258_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Fn4 , v112
	.byte	W04
	.byte		PAN   , c_v+6
	.byte		N02   , Ds5 , v040
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v-5
	.byte		N01   , Gn4 , v112
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5 
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		N02   , Ds5 , v020
	.byte	W03
	.byte		PAN   , c_v-5
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5 
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N02   , Ds5 , v020
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-13
	.byte		N01   , Gn4 , v064
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Ds5 
	.byte	W04
	.byte	FINE

@********************** Track  2 **********************@

se_w258_2:
	.byte	KEYSH , se_w258_key+0
	.byte		VOICE , 4
	.byte		VOL   , 100*se_w258_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N01   , Dn4 , v040
	.byte	W04
	.byte		        Bn3 
	.byte	W02
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte	W01
	.byte		        Bn3 , v032
	.byte	W05
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 , v012
	.byte	W03
	.byte	W02
	.byte		        Dn4 
	.byte	W04
	.byte	FINE

@******************************************************@
	.align	2

se_w258:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w258_pri	@ Priority
	.byte	se_w258_rev	@ Reverb.

	.word	se_w258_grp

	.word	se_w258_1
	.word	se_w258_2

	.end
