	.include "MPlayDef.s"

	.equ	se_toreoff_grp, voicegroup129
	.equ	se_toreoff_pri, 5
	.equ	se_toreoff_rev, reverb_set+50
	.equ	se_toreoff_mvl, 127
	.equ	se_toreoff_key, 0
	.equ	se_toreoff_tbs, 1
	.equ	se_toreoff_exg, 0
	.equ	se_toreoff_cmp, 1

	.section .rodata
	.global	se_toreoff
	.align	2

@********************** Track  1 **********************@

se_toreoff_1:
	.byte	KEYSH , se_toreoff_key+0
	.byte	TEMPO , 120*se_toreoff_tbs/2
	.byte		VOICE , 10
	.byte		VOL   , 110*se_toreoff_mvl/mxv
	.byte		BEND  , c_v-8
	.byte	W01
	.byte		N01   , Ds3 , v112
	.byte	W04
	.byte		        Gs1 
	.byte	W01
	.byte		        Bn1 , v056
	.byte	W04
	.byte		        Bn1 , v024
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@********************** Track  2 **********************@

se_toreoff_2:
	.byte	KEYSH , se_toreoff_key+0
	.byte		VOICE , 82
	.byte		VOL   , 110*se_toreoff_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+0
	.byte		N01   , Cs3 , v064
	.byte	W01
	.byte		        Fs4 , v032
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N01   , Gs5 , v028
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v-63
	.byte		N01   , Cs3 , v036
	.byte	W01
	.byte		BEND  , c_v+63
	.byte	W01
	.byte		        c_v-63
	.byte		N01   , Bn4 , v052
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		N01   , Cs1 
	.byte	W02
	.byte	W06
	.byte	W06
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_toreoff:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_toreoff_pri	@ Priority
	.byte	se_toreoff_rev	@ Reverb.

	.word	se_toreoff_grp

	.word	se_toreoff_1
	.word	se_toreoff_2

	.end
