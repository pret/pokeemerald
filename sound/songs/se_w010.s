	.include "MPlayDef.s"

	.equ	se_w010_grp, voicegroup128
	.equ	se_w010_pri, 4
	.equ	se_w010_rev, reverb_set+50
	.equ	se_w010_mvl, 127
	.equ	se_w010_key, 0
	.equ	se_w010_tbs, 1
	.equ	se_w010_exg, 0
	.equ	se_w010_cmp, 1

	.section .rodata
	.global	se_w010
	.align	2

@********************** Track  1 **********************@

se_w010_1:
	.byte	KEYSH , se_w010_key+0
	.byte	TEMPO , 220*se_w010_tbs/2
	.byte		VOICE , 18
	.byte		BENDR , 12
	.byte		PAN   , c_v+14
	.byte		VOL   , 42*se_w010_mvl/mxv
	.byte		BEND  , c_v+39
	.byte		N10   , Gn5 , v092
	.byte	W01
	.byte		VOL   , 55*se_w010_mvl/mxv
	.byte	W01
	.byte		        71*se_w010_mvl/mxv
	.byte		BEND  , c_v+23
	.byte	W01
	.byte		PAN   , c_v-15
	.byte		VOL   , 86*se_w010_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		VOL   , 110*se_w010_mvl/mxv
	.byte		BEND  , c_v-23
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-34
	.byte	W01
	.byte		        c_v-55
	.byte	W01
	.byte		        c_v-64
	.byte	W02
	.byte		VOICE , 21
	.byte		BEND  , c_v+63
	.byte		N01   , Cn5 
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		        Gn5 , v064
	.byte	W10
	.byte	FINE

@******************************************************@
	.align	2

se_w010:
	.byte	1	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_w010_pri	@ Priority
	.byte	se_w010_rev	@ Reverb.

	.word	se_w010_grp

	.word	se_w010_1

	.end
