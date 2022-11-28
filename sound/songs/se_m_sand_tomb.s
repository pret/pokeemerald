	.include "MPlayDef.s"

	.equ	se_m_sand_tomb_grp, voicegroup128
	.equ	se_m_sand_tomb_pri, 4
	.equ	se_m_sand_tomb_rev, reverb_set+50
	.equ	se_m_sand_tomb_mvl, 127
	.equ	se_m_sand_tomb_key, 0
	.equ	se_m_sand_tomb_tbs, 1
	.equ	se_m_sand_tomb_exg, 0
	.equ	se_m_sand_tomb_cmp, 1

	.section .rodata
	.global	se_m_sand_tomb
	.align	2

@********************** Track  1 **********************@

se_m_sand_tomb_1:
	.byte	KEYSH , se_m_sand_tomb_key+0
	.byte	TEMPO , 150*se_m_sand_tomb_tbs/2
	.byte		VOICE , 22
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*se_m_sand_tomb_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , En2 , v127
	.byte	W03
	.byte		VOL   , 79*se_m_sand_tomb_mvl/mxv
	.byte		BEND  , c_v+22
	.byte	W02
	.byte		        c_v+8
	.byte	W01
	.byte		VOL   , 84*se_m_sand_tomb_mvl/mxv
	.byte		PAN   , c_v-4
	.byte	W03
	.byte		VOL   , 91*se_m_sand_tomb_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 100*se_m_sand_tomb_mvl/mxv
	.byte		PAN   , c_v-8
	.byte	W03
	.byte		VOL   , 110*se_m_sand_tomb_mvl/mxv
	.byte	W03
	.byte		PAN   , c_v-12
	.byte	W06
	.byte		        c_v-17
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v-7
	.byte	W03
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-12
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		PAN   , c_v-3
	.byte	W03
	.byte		        c_v+6
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		PAN   , c_v+10
	.byte	W03
	.byte		BEND  , c_v-6
	.byte	W03
	.byte		PAN   , c_v+16
	.byte	W03
	.byte		BEND  , c_v+6
	.byte	W03
	.byte		PAN   , c_v+13
	.byte		BEND  , c_v+11
	.byte	W03
	.byte		        c_v+20
	.byte	W03
	.byte		PAN   , c_v+8
	.byte	W03
	.byte		        c_v+0
	.byte		BEND  , c_v+12
	.byte	W03
	.byte		PAN   , c_v-8
	.byte		BEND  , c_v+7
	.byte	W03
	.byte		PAN   , c_v-11
	.byte	W03
	.byte		        c_v-17
	.byte		VOL   , 98*se_m_sand_tomb_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 90*se_m_sand_tomb_mvl/mxv
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		PAN   , c_v-9
	.byte		BEND  , c_v-12
	.byte	W01
	.byte		VOL   , 80*se_m_sand_tomb_mvl/mxv
	.byte	W02
	.byte		BEND  , c_v-20
	.byte	W01
	.byte		VOL   , 71*se_m_sand_tomb_mvl/mxv
	.byte	W02
	.byte		PAN   , c_v-3
	.byte	W02
	.byte		VOL   , 58*se_m_sand_tomb_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v-13
	.byte	W03
	.byte		PAN   , c_v+10
	.byte		VOL   , 45*se_m_sand_tomb_mvl/mxv
	.byte	W02
	.byte		        27*se_m_sand_tomb_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-6
	.byte	W01
	.byte		VOL   , 11*se_m_sand_tomb_mvl/mxv
	.byte	W02
	.byte	FINE

@********************** Track  2 **********************@

se_m_sand_tomb_2:
	.byte	KEYSH , se_m_sand_tomb_key+0
	.byte		VOICE , 57
	.byte		PAN   , c_v+0
	.byte		VOL   , 110*se_m_sand_tomb_mvl/mxv
	.byte		N03   , Cn3 , v100
	.byte	W03
	.byte		        En3 , v080
	.byte	W04
	.byte		        Dn3
	.byte	W03
	.byte		        Cn3 , v100
	.byte	W04
	.byte		        En3 , v080
	.byte	W04
	.byte		        Dn3
	.byte	W03
	.byte		        Cn3 , v100
	.byte	W03
	.byte	W01
	.byte		        En3 , v080
	.byte	W03
	.byte		        Dn3
	.byte	W04
	.byte		        Cn3 , v100
	.byte	W04
	.byte		        En3 , v080
	.byte	W03
	.byte		        Dn3
	.byte	W04
	.byte		        Cn3 , v100
	.byte	W03
	.byte		        En3 , v080
	.byte	W02
	.byte	W02
	.byte		        Dn3
	.byte	W04
	.byte		        Cn3 , v100
	.byte	W03
	.byte		        En3 , v080
	.byte	W04
	.byte		        Dn3
	.byte	W03
	.byte		        Cn3 , v100
	.byte	W04
	.byte		        En3 , v080
	.byte	W04
	.byte		        Dn3
	.byte	W03
	.byte		        Cn3 , v092
	.byte	W04
	.byte		        En3 , v060
	.byte	W03
	.byte		        Dn3 , v052
	.byte	W04
	.byte		        Cn3 , v060
	.byte	W04
	.byte		        En3 , v032
	.byte	W03
	.byte		N02   , Dn3 , v020
	.byte	W03
	.byte	FINE

@******************************************************@
	.align	2

se_m_sand_tomb:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_sand_tomb_pri	@ Priority
	.byte	se_m_sand_tomb_rev	@ Reverb.

	.word	se_m_sand_tomb_grp

	.word	se_m_sand_tomb_1
	.word	se_m_sand_tomb_2

	.end
