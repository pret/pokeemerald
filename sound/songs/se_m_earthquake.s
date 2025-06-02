	.include "MPlayDef.s"

	.equ	se_m_earthquake_grp, voicegroup_rs_sfx_2
	.equ	se_m_earthquake_pri, 4
	.equ	se_m_earthquake_rev, reverb_set+50
	.equ	se_m_earthquake_mvl, 127
	.equ	se_m_earthquake_key, 0
	.equ	se_m_earthquake_tbs, 1
	.equ	se_m_earthquake_exg, 0
	.equ	se_m_earthquake_cmp, 1

	.section .rodata
	.global	se_m_earthquake
	.align	2

@********************** Track  1 **********************@

se_m_earthquake_1:
	.byte	KEYSH , se_m_earthquake_key+0
	.byte	TEMPO , 150*se_m_earthquake_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_earthquake_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Cs2 , v127
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v120
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Bn1 , v116
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
se_m_earthquake_1_000:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v108
	.byte	W04
	.byte	PEND
se_m_earthquake_1_001:
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte	PEND
se_m_earthquake_1_002:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v108
	.byte	W02
	.byte	PEND
se_m_earthquake_1_003:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v100
	.byte	W04
	.byte	PEND
se_m_earthquake_1_004:
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte	PEND
se_m_earthquake_1_005:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v100
	.byte	W02
	.byte	PEND
se_m_earthquake_1_006:
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v116
	.byte	W04
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v116
	.byte	W02
	.byte	W02
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v112
	.byte	W04
se_m_earthquake_1_007:
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte	PEND
se_m_earthquake_1_008:
	.byte	W01
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
	.byte	PEND
	.byte	PATT
	 .word	se_m_earthquake_1_000
	.byte	PATT
	 .word	se_m_earthquake_1_001
	.byte	PATT
	 .word	se_m_earthquake_1_002
	.byte	PATT
	 .word	se_m_earthquake_1_003
	.byte	PATT
	 .word	se_m_earthquake_1_007
	.byte	PATT
	 .word	se_m_earthquake_1_008
	.byte	PATT
	 .word	se_m_earthquake_1_000
	.byte	PATT
	 .word	se_m_earthquake_1_001
	.byte	PATT
	 .word	se_m_earthquake_1_002
	.byte	PATT
	 .word	se_m_earthquake_1_003
	.byte	PATT
	 .word	se_m_earthquake_1_004
	.byte	PATT
	 .word	se_m_earthquake_1_005
	.byte	PATT
	 .word	se_m_earthquake_1_006
	.byte		VOL   , 106*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v112
	.byte	W03
	.byte		VOL   , 103*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte	W01
	.byte		VOL   , 97*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		VOL   , 89*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N03   , Cs2 , v116
	.byte	W02
	.byte	W02
	.byte		VOL   , 85*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N03   , Cn2 , v112
	.byte	W04
	.byte		VOL   , 78*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cs2 , v108
	.byte	W03
	.byte		VOL   , 72*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte	W01
	.byte		VOL   , 66*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N03   , Cs2 , v116
	.byte	W03
	.byte		VOL   , 58*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+11
	.byte		N03   , Cn2 , v112
	.byte	W02
	.byte	W02
	.byte		VOL   , 46*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v-11
	.byte		N03   , Cs2 , v108
	.byte	W04
	.byte		VOL   , 30*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N03   , Cn2 , v100
	.byte	W03
	.byte		VOL   , 12*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+6
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_earthquake_2:
	.byte	KEYSH , se_m_earthquake_key+0
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_earthquake_mvl/mxv
	.byte		N02   , Fn2 , v072
	.byte	W02
	.byte		N01
	.byte	W01
	.byte		N02   , Gn2
	.byte	W03
	.byte		N01   , Gs2 , v060
	.byte	W06
	.byte		VOICE , 27
	.byte		N06   , Bn1 , v080
	.byte	W06
se_m_earthquake_2_000:
	.byte		PAN   , c_v+0
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte	PEND
	.byte		N06
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte	PATT
	 .word	se_m_earthquake_2_000
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		N06
	.byte	W06
	.byte		VOL   , 106*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 103*se_m_earthquake_mvl/mxv
	.byte	W03
	.byte		N06
	.byte	W01
	.byte		VOL   , 97*se_m_earthquake_mvl/mxv
	.byte	W03
	.byte		        89*se_m_earthquake_mvl/mxv
	.byte	W02
	.byte		N06
	.byte	W02
	.byte		VOL   , 85*se_m_earthquake_mvl/mxv
	.byte	W04
	.byte		        78*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 72*se_m_earthquake_mvl/mxv
	.byte	W03
	.byte		N06
	.byte	W01
	.byte		VOL   , 66*se_m_earthquake_mvl/mxv
	.byte	W03
	.byte		        58*se_m_earthquake_mvl/mxv
	.byte	W02
	.byte		N06
	.byte	W02
	.byte		VOL   , 46*se_m_earthquake_mvl/mxv
	.byte	W04
	.byte		        30*se_m_earthquake_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06
	.byte	W03
	.byte		VOL   , 12*se_m_earthquake_mvl/mxv
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_earthquake:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_earthquake_pri	@ Priority
	.byte	se_m_earthquake_rev	@ Reverb.

	.word	se_m_earthquake_grp

	.word	se_m_earthquake_1
	.word	se_m_earthquake_2

	.end
