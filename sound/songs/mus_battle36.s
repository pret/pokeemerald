	.include "MPlayDef.s"

	.equ	mus_battle36_grp, voicegroup_869B900
	.equ	mus_battle36_pri, 1
	.equ	mus_battle36_rev, reverb_set+50
	.equ	mus_battle36_mvl, 127
	.equ	mus_battle36_key, 0
	.equ	mus_battle36_tbs, 1
	.equ	mus_battle36_exg, 0
	.equ	mus_battle36_cmp, 1

	.section .rodata
	.global	mus_battle36
	.align	2

@********************** Track  1 **********************@

mus_battle36_1:
	.byte	KEYSH , mus_battle36_key+0
	.byte	TEMPO , 160*mus_battle36_tbs/2
	.byte		VOICE , 48
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N08   , Cs4 , v112
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte	W96
	.byte	W48
	.byte		VOICE , 56
	.byte		PAN   , c_v-48
	.byte		BEND  , c_v-2
	.byte	W12
	.byte		N36   , Cs4 , v020
	.byte	W36
	.byte		N12   , Dn4 
	.byte	W60
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W60
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Dn3 
	.byte	W96
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W18
	.byte		        Cn4 
	.byte	W06
	.byte	W12
	.byte		        Ds4 
	.byte	W84
	.byte	W60
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W12
	.byte		        En3 
	.byte	W18
	.byte		        As3 
	.byte	W18
	.byte		        En3 
	.byte	W48
	.byte	W42
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W06
	.byte	W12
	.byte		        Cn4 
	.byte	W18
	.byte		        An3 
	.byte	W66
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte		BEND  , c_v+0
	.byte		TIE   , Cs3 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , An3 
	.byte	W16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N96   , Bn3 
	.byte	W96
mus_battle36_1_000:
	.byte		N64   , An3 , v100
	.byte	W64
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N16   , Fs3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte	PEND
	.byte		N96   , Gs3 
	.byte	W96
	.byte		        Cs3 
	.byte	W96
mus_battle36_1_B1:
	.byte		PAN   , c_v-10
	.byte		TIE   , Dn3 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , As3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		N96   , Cn4 
	.byte	W96
	.byte		N64   , As3 
	.byte	W64
	.byte		N08   , An3 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N08   , As3 
	.byte	W08
	.byte		N96   , An3 
	.byte	W96
	.byte		        Dn4 
	.byte	W96
mus_battle36_1_001:
	.byte		VOL   , 54*mus_battle36_mvl/mxv
	.byte		N96   , As2 , v100
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte	PEND
	.byte		        54*mus_battle36_mvl/mxv
	.byte		N96   , Gn2 
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte		N12   , Fs2 , v108
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle36_1_001
	.byte		VOL   , 54*mus_battle36_mvl/mxv
	.byte		N96   , Ds3 , v100
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte		N12   , Dn3 , v108
	.byte	W96
	.byte	W96
	.byte		TIE   , Cs3 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , An3 
	.byte	W16
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N96   , Bn3 
	.byte	W96
	.byte	PATT
	 .word	mus_battle36_1_000
	.byte		N96   , Gs3 , v100
	.byte	W96
	.byte		        Cs3 
	.byte	W96
	.byte	GOTO
	 .word	mus_battle36_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_battle36_2:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		PAN   , c_v-16
	.byte		N24   , Gs4 , v076
	.byte	W48
	.byte		PAN   , c_v+16
	.byte		N24   
	.byte	W48
	.byte	W48
	.byte		PAN   , c_v-16
	.byte		N24   
	.byte	W48
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N24   
	.byte	W48
	.byte		PAN   , c_v+16
	.byte		N24   
	.byte	W96
	.byte		VOICE , 56
	.byte	W24
	.byte		PAN   , c_v-10
	.byte	W12
	.byte		N36   , Cs4 , v108
	.byte	W36
	.byte		N12   , Dn4 
	.byte	W24
	.byte	W36
	.byte		N36   , Gs3 
	.byte	W36
	.byte		N12   , An3 
	.byte	W24
	.byte	W36
	.byte		N36   , Cs3 
	.byte	W36
	.byte		N12   , Dn3 
	.byte	W24
	.byte	W96
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
	.byte	W96
	.byte	W36
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte	W06
	.byte		        As3 
	.byte	W18
	.byte		        En3 
	.byte	W72
	.byte	W18
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W06
	.byte		        An3 
	.byte	W90
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		TIE   , Cs2 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N96   , Bn2 
	.byte	W96
mus_battle36_2_000:
	.byte		N64   , An2 , v100
	.byte	W64
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N16   , Fs2 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte	PEND
	.byte		N96   , Gs2 
	.byte	W96
	.byte		        Cs2 
	.byte	W96
mus_battle36_2_B1:
	.byte		PAN   , c_v+0
	.byte		TIE   , Dn2 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , As2 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte		N96   , Cn3 
	.byte	W96
	.byte		N64   , As2 
	.byte	W64
	.byte		N08   , An2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		N08   , As2 
	.byte	W08
	.byte		N96   , An2 
	.byte	W96
	.byte		        Dn3 
	.byte	W96
mus_battle36_2_001:
	.byte		VOL   , 54*mus_battle36_mvl/mxv
	.byte		N96   , Ds3 , v100
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte	PEND
	.byte		        54*mus_battle36_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte		N12   , Dn3 , v108
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle36_2_001
	.byte		VOL   , 54*mus_battle36_mvl/mxv
	.byte		N96   , Gn3 , v100
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        65*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        75*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        80*mus_battle36_mvl/mxv
	.byte	W32
	.byte		N12   , Fs3 , v108
	.byte	W96
	.byte	W96
	.byte		TIE   , Cs2 , v100
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N16   , An2 
	.byte	W16
	.byte		N08   , Gs2 
	.byte	W08
	.byte		N96   , Bn2 
	.byte	W96
	.byte	PATT
	 .word	mus_battle36_2_000
	.byte		N96   , Gs2 , v100
	.byte	W96
	.byte		        Cs2 
	.byte	W96
	.byte	GOTO
	 .word	mus_battle36_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_battle36_3:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 36
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		N08   , Cs0 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An0 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Cs2 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
mus_battle36_3_000:
	.byte		N08   , Cs1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte	PEND
mus_battle36_3_001:
	.byte		N08   , Cs1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Gs0 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
mus_battle36_3_002:
	.byte		N08   , Dn1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte	PEND
mus_battle36_3_003:
	.byte		N08   , Dn1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        An0 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte		N08   , Dn1 , v116
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
mus_battle36_3_B1:
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_002
	.byte	PATT
	 .word	mus_battle36_3_003
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	PATT
	 .word	mus_battle36_3_000
	.byte	PATT
	 .word	mus_battle36_3_001
	.byte	GOTO
	 .word	mus_battle36_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_battle36_4:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 6
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		N08   , Cs5 , v060
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
mus_battle36_4_000:
	.byte		N08   , Cs4 , v060
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_4_000
mus_battle36_4_001:
	.byte		N08   , Cs4 , v060
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
mus_battle36_4_002:
	.byte		N08   , Dn4 , v060
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
mus_battle36_4_B1:
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte	PATT
	 .word	mus_battle36_4_002
	.byte		VOICE , 5
	.byte		PAN   , c_v+48
	.byte		N08   , Dn3 , v060
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Cs3 , v056
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 , v052
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v048
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        An2 , v044
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gs2 , v040
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 , v036
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        As2 , v032
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        An2 , v028
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Ds2 , v024
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		VOICE , 6
	.byte		PAN   , c_v+0
	.byte		N08   , Cs4 , v060
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	PATT
	 .word	mus_battle36_4_001
	.byte	GOTO
	 .word	mus_battle36_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_battle36_5:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 7
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		BEND  , c_v-2
	.byte	W08
	.byte		N08   , Cs5 , v032
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Cs3 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An5 
	.byte	W08
	.byte		        Gs5 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
mus_battle36_5_000:
	.byte		N08   , Gs4 , v032
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
mus_battle36_5_001:
	.byte		N08   , Gs4 , v032
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte	PEND
mus_battle36_5_002:
	.byte		N08   , An4 , v032
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte		N08   , An4 , v032
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
mus_battle36_5_B1:
	.byte	PATT
	 .word	mus_battle36_5_001
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte		N08   , An4 , v032
	.byte	W08
	.byte		N12   , Dn4 
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N08   , As4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte	PATT
	 .word	mus_battle36_5_002
	.byte		VOICE , 82
	.byte		VOL   , 54*mus_battle36_mvl/mxv
	.byte		N12   , As2 , v072
	.byte	W08
	.byte		VOL   , 57*mus_battle36_mvl/mxv
	.byte	W04
	.byte		VOICE , 83
	.byte		N12   
	.byte	W04
	.byte		VOL   , 59*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        62*mus_battle36_mvl/mxv
	.byte		N12   
	.byte	W08
	.byte		VOL   , 65*mus_battle36_mvl/mxv
	.byte	W04
	.byte		N12   
	.byte	W04
	.byte		VOL   , 68*mus_battle36_mvl/mxv
	.byte	W08
	.byte		        72*mus_battle36_mvl/mxv
	.byte		N12   
	.byte	W08
	.byte		VOL   , 75*mus_battle36_mvl/mxv
	.byte	W04
	.byte		N12   
	.byte	W04
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte	W08
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 4
	.byte		PAN   , c_v-48
	.byte		N08   , An4 , v060
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Gs4 , v056
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Cn5 , v052
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Bn4 , v048
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        En4 , v044
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Ds4 , v040
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Fs4 , v036
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fn4 , v032
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        En4 , v028
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 , v024
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		PAN   , c_v+48
	.byte	W08
	.byte		VOICE , 7
	.byte		N08   , Cs4 , v032
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		        An4 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	PATT
	 .word	mus_battle36_5_000
	.byte	GOTO
	 .word	mus_battle36_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_battle36_6:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-1
	.byte		N06   , Gs4 , v048
	.byte	W48
	.byte		N06   
	.byte	W48
	.byte	W48
	.byte		N06   
	.byte	W48
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W48
	.byte		N06   
	.byte	W96
	.byte	W36
	.byte		        Cs4 
	.byte	W36
	.byte		        Dn4 
	.byte	W24
	.byte	W36
	.byte		        Gs3 
	.byte	W36
	.byte		        An3 
	.byte	W24
	.byte	W36
	.byte		        Cs3 
	.byte	W36
	.byte		        Dn3 
	.byte	W24
	.byte	W96
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W18
	.byte		        Cn4 
	.byte	W18
	.byte		        Ds4 
	.byte	W12
	.byte	W96
	.byte	W36
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte	W06
	.byte		        As3 
	.byte	W18
	.byte		        En3 
	.byte	W72
	.byte	W18
	.byte		        Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W24
	.byte		        An3 
	.byte	W18
	.byte		        Cn4 
	.byte	W12
	.byte	W06
	.byte		        An3 
	.byte	W90
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_battle36_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_battle36_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_battle36_7:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte		N24   , Cn2 , v120
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
mus_battle36_7_000:
	.byte		N24   , Cn2 , v120
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_7_000
	.byte		N24   , Cn2 , v120
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N36   , An2 , v096
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N16   , Dn1 , v112
	.byte	W16
	.byte		N08   
	.byte	W08
mus_battle36_7_B1:
mus_battle36_7_001:
	.byte	W24
	.byte		N24   , Dn1 , v112
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
mus_battle36_7_002:
	.byte	W24
	.byte		N24   , Dn1 , v112
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	W24
	.byte		N24   , Dn1 , v112
	.byte	W40
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	W96
	.byte	W72
	.byte		N24   , Dn1 , v112
	.byte	W24
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_002
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	PATT
	 .word	mus_battle36_7_001
	.byte	GOTO
	 .word	mus_battle36_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_battle36_8:
	.byte	KEYSH , mus_battle36_key+0
	.byte		VOICE , 47
	.byte		PAN   , c_v+10
	.byte		VOL   , 80*mus_battle36_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_battle36_8_000:
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte	PEND
mus_battle36_8_001:
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte	PATT
	 .word	mus_battle36_8_001
mus_battle36_8_002:
	.byte		N48   , Cn2 , v112
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_8_002
	.byte	PATT
	 .word	mus_battle36_8_002
	.byte	PATT
	 .word	mus_battle36_8_002
	.byte	PATT
	 .word	mus_battle36_8_002
	.byte		N48   , Cn2 , v112
	.byte	W48
	.byte		N24   
	.byte	W32
	.byte		N08   , An1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte	PATT
	 .word	mus_battle36_8_000
	.byte		N24   , Cn2 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W48
mus_battle36_8_B1:
mus_battle36_8_003:
	.byte		N24   , Cn2 , v112
	.byte	W48
	.byte		N24   
	.byte	W48
	.byte	PEND
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte		N24   , Cn2 , v112
	.byte	W48
	.byte		N16   
	.byte	W48
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_002
	.byte		N48   , Cn2 , v112
	.byte	W48
	.byte		N24   
	.byte	W48
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	PATT
	 .word	mus_battle36_8_003
	.byte	GOTO
	 .word	mus_battle36_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_battle36:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_battle36_pri	@ Priority
	.byte	mus_battle36_rev	@ Reverb.

	.word	mus_battle36_grp

	.word	mus_battle36_1
	.word	mus_battle36_2
	.word	mus_battle36_3
	.word	mus_battle36_4
	.word	mus_battle36_5
	.word	mus_battle36_6
	.word	mus_battle36_7
	.word	mus_battle36_8

	.end
