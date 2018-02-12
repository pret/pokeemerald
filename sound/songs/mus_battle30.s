	.include "MPlayDef.s"

	.equ	mus_battle30_grp, voicegroup_869CAF4
	.equ	mus_battle30_pri, 1
	.equ	mus_battle30_rev, reverb_set+50
	.equ	mus_battle30_mvl, 127
	.equ	mus_battle30_key, 0
	.equ	mus_battle30_tbs, 1
	.equ	mus_battle30_exg, 0
	.equ	mus_battle30_cmp, 1

	.section .rodata
	.global	mus_battle30
	.align	2

@********************** Track  1 **********************@

mus_battle30_1:
	.byte	KEYSH , mus_battle30_key+0
	.byte	TEMPO , 202*mus_battle30_tbs/2
	.byte		LFOS  , 16
	.byte		VOL   , 80*mus_battle30_mvl/mxv
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
	.byte	W48
	.byte		PAN   , c_v-8
	.byte		N48   , En2 , v108
	.byte	W01
	.byte		VOICE , 48
	.byte	W44
	.byte	W03
	.byte		N12   , Fn2 
	.byte	W36
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N12   , Ds2 
	.byte	W24
mus_battle30_1_000:
	.byte		N12   , Fn2 , v108
	.byte	W36
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N12   , En2 
	.byte	W24
	.byte	PEND
mus_battle30_1_001:
	.byte		N12   , Fn2 , v108
	.byte	W36
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
mus_battle30_1_002:
	.byte		N12   , Fn2 , v108
	.byte	W36
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N12   , Fs2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_1_000
	.byte	PATT
	 .word	mus_battle30_1_000
	.byte	PATT
	 .word	mus_battle30_1_001
mus_battle30_1_003:
	.byte		N12   , Fn2 , v108
	.byte	W36
	.byte		        Cn2 
	.byte	W12
	.byte		N48   , Fn2 
	.byte	W48
	.byte	PEND
mus_battle30_1_B1:
	.byte		PAN   , c_v-8
	.byte		N12   , Gn2 , v108
	.byte	W36
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N12   , Fn2 
	.byte	W24
mus_battle30_1_004:
	.byte		N12   , Gn2 , v108
	.byte	W36
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N12   , Fs2 
	.byte	W24
	.byte	PEND
mus_battle30_1_005:
	.byte		N12   , Gn2 , v108
	.byte	W36
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	PEND
	.byte		        Gn2 
	.byte	W36
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N12   , Gs2 
	.byte	W24
	.byte	PATT
	 .word	mus_battle30_1_004
	.byte	PATT
	 .word	mus_battle30_1_004
	.byte	PATT
	 .word	mus_battle30_1_005
	.byte		N12   , Gn2 , v108
	.byte	W36
	.byte		        Dn2 
	.byte	W12
	.byte		N48   , Ds3 
	.byte	W48
	.byte		PAN   , c_v+10
	.byte		N36   , En3 , v096
	.byte	W36
	.byte		        Ds3 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N36   , Dn3 
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N24   , An2 
	.byte	W24
	.byte		N36   , Bn2 
	.byte	W36
	.byte		        Cn3 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte		TIE   , Gs2 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Gs1 , v100
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_battle30_1_006:
	.byte		N36   , Cn2 , v108
	.byte	W36
	.byte		        Cs2 
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte	PEND
	.byte		N36   , Fn2 
	.byte	W36
	.byte		        Cs2 
	.byte	W36
	.byte		N24   , Bn1 
	.byte	W24
	.byte	PATT
	 .word	mus_battle30_1_006
	.byte		N36   , Fn2 , v108
	.byte	W36
	.byte		        Fs2 
	.byte	W36
	.byte		N24   , Gs2 
	.byte	W24
	.byte		PAN   , c_v-30
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N12   
	.byte	W03
	.byte		VOICE , 56
	.byte	W09
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , As2 
	.byte	W24
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		VOICE , 60
	.byte		N12   , Gn3 , v096
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N96   
	.byte	W96
	.byte		        Fs3 
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		        Cn3 
	.byte	W96
	.byte		N96   
	.byte	W96
	.byte		        Fs2 
	.byte	W96
	.byte		        Fn2 
	.byte	W96
	.byte		        Fs2 
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v-8
	.byte		N12   , Fn2 , v108
	.byte	W36
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N12   , Ds2 
	.byte	W24
	.byte	PATT
	 .word	mus_battle30_1_000
	.byte	PATT
	 .word	mus_battle30_1_001
	.byte	PATT
	 .word	mus_battle30_1_002
	.byte	PATT
	 .word	mus_battle30_1_000
	.byte	PATT
	 .word	mus_battle30_1_000
	.byte	PATT
	 .word	mus_battle30_1_001
	.byte	PATT
	 .word	mus_battle30_1_003
	.byte	GOTO
	 .word	mus_battle30_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_battle30_2:
	.byte	KEYSH , mus_battle30_key+0
	.byte		LFOS  , 16
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W90
	.byte		VOICE , 56
	.byte		N06   , Dn3 , v120
	.byte	W06
mus_battle30_2_000:
	.byte		N96   , Ds3 , v120
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte	PEND
	.byte		        0
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_2_000
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Ds3 , v120
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_2_000
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Ds3 , v120
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		TIE   , Ds3 
	.byte	W48
	.byte		MOD   , 6
	.byte	W32
	.byte	W01
	.byte		VOL   , 76*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        73*mus_battle30_mvl/mxv
	.byte	W06
	.byte	W03
	.byte		        68*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        59*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        50*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        38*mus_battle30_mvl/mxv
	.byte	W06
	.byte		        25*mus_battle30_mvl/mxv
	.byte	W06
	.byte		        13*mus_battle30_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W42
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		N06   , En3 , v124
	.byte	W06
mus_battle30_2_001:
	.byte		N96   , Fn3 , v124
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte	PEND
mus_battle30_2_002:
	.byte		MOD   , 0
	.byte	W06
	.byte		N06   , En3 , v124
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_2_001
mus_battle30_2_003:
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Fn3 , v124
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_2_001
mus_battle30_2_004:
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Fn3 , v124
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PEND
	.byte		TIE   , Fn3 
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte	W48
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N48   , Fs3 
	.byte	W48
mus_battle30_2_B1:
mus_battle30_2_005:
	.byte		N96   , Gn3 , v124
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte	PEND
mus_battle30_2_006:
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Gn3 , v124
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_2_005
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Gn3 , v124
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_2_005
	.byte	PATT
	 .word	mus_battle30_2_006
	.byte		N72   , Gn3 , v124
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N72   , Dn4 , v120
	.byte	W24
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v-10
	.byte		MOD   , 0
	.byte		N36   , Bn3 , v108
	.byte	W36
	.byte		        As3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N36   , An3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
	.byte		TIE   , Ds3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Ds2 , v112
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 60
	.byte		N36   , Cn2 , v116
	.byte	W36
	.byte		        Cs2 
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N36   , Fn2 
	.byte	W36
	.byte		        Cs2 
	.byte	W36
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N36   , Cn2 
	.byte	W36
	.byte		        Cs2 
	.byte	W36
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N36   , Fn2 
	.byte	W36
	.byte		        Fs2 
	.byte	W36
	.byte		N24   , Ds2 
	.byte	W24
mus_battle30_2_007:
	.byte		N36   , Fn2 , v116
	.byte	W36
	.byte		        Fs2 
	.byte	W36
	.byte		N24   , Bn2 
	.byte	W24
	.byte	PEND
	.byte		N36   , As2 
	.byte	W36
	.byte		        Fs2 
	.byte	W36
	.byte		N24   , En2 
	.byte	W24
	.byte	PATT
	 .word	mus_battle30_2_007
	.byte		N36   , As2 , v116
	.byte	W36
	.byte		        Bn2 
	.byte	W36
	.byte		N24   , Cs3 
	.byte	W24
	.byte		VOICE , 56
	.byte		N12   , Cn3 , v120
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		VOICE , 48
	.byte		N12   , Cn4 , v108
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Fn5 , v100
	.byte	W24
	.byte		VOL   , 78*mus_battle30_mvl/mxv
	.byte	W15
	.byte		        74*mus_battle30_mvl/mxv
	.byte	W15
	.byte		        70*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        68*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        65*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        62*mus_battle30_mvl/mxv
	.byte	W06
	.byte	W09
	.byte		        59*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        55*mus_battle30_mvl/mxv
	.byte	W18
	.byte		        58*mus_battle30_mvl/mxv
	.byte	W15
	.byte		        61*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        63*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        66*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        69*mus_battle30_mvl/mxv
	.byte	W06
	.byte	W06
	.byte		        70*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        74*mus_battle30_mvl/mxv
	.byte	W12
	.byte		        77*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        80*mus_battle30_mvl/mxv
	.byte	W56
	.byte	W01
	.byte	W18
	.byte		        76*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        72*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        68*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        62*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        56*mus_battle30_mvl/mxv
	.byte	W09
	.byte		        46*mus_battle30_mvl/mxv
	.byte	W06
	.byte		        34*mus_battle30_mvl/mxv
	.byte	W06
	.byte		        22*mus_battle30_mvl/mxv
	.byte	W03
	.byte		        10*mus_battle30_mvl/mxv
	.byte	W03
	.byte		        5*mus_battle30_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		N06   , En3 , v124
	.byte	W06
	.byte	PATT
	 .word	mus_battle30_2_001
	.byte	PATT
	 .word	mus_battle30_2_002
	.byte	PATT
	 .word	mus_battle30_2_001
	.byte	PATT
	 .word	mus_battle30_2_003
	.byte	PATT
	 .word	mus_battle30_2_001
	.byte	PATT
	 .word	mus_battle30_2_004
	.byte		N72   , Fn3 , v124
	.byte	W36
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N48   , Cn4 , v120
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N48   , Fs3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W21
	.byte		        0
	.byte	W03
	.byte	GOTO
	 .word	mus_battle30_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_battle30_3:
	.byte	KEYSH , mus_battle30_key+0
	.byte		VOICE , 33
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		N24   , Ds0 , v116
	.byte	W24
	.byte		        Fs0 
	.byte	W24
	.byte		        En0 
	.byte	W24
	.byte		        Ds0 
	.byte	W24
	.byte		        Cs0 
	.byte	W24
	.byte		        En0 
	.byte	W24
	.byte		        Ds0 
	.byte	W24
	.byte		        Cs0 
	.byte	W24
	.byte		        Ds0 
	.byte	W24
	.byte		        Fs0 
	.byte	W24
	.byte		        En0 
	.byte	W24
	.byte		        Ds0 
	.byte	W24
	.byte		        Cs0 
	.byte	W24
	.byte		        BnM1
	.byte	W24
	.byte		N12   , Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
mus_battle30_3_000:
	.byte		N12   , Ds0 , v116
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
mus_battle30_3_001:
	.byte		N12   , Ds0 , v116
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PEND
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_000
	.byte	PATT
	 .word	mus_battle30_3_001
	.byte		N12   , Ds0 , v116
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        As0 
	.byte	W12
mus_battle30_3_002:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
mus_battle30_3_003:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
mus_battle30_3_004:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
mus_battle30_3_005:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte	PEND
mus_battle30_3_006:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_3_003
	.byte	PATT
	 .word	mus_battle30_3_004
mus_battle30_3_007:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte	PEND
mus_battle30_3_B1:
mus_battle30_3_008:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
mus_battle30_3_009:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
mus_battle30_3_010:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_009
	.byte	PATT
	 .word	mus_battle30_3_010
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_008
	.byte	PATT
	 .word	mus_battle30_3_008
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
mus_battle30_3_011:
	.byte		N12   , Gs0 , v116
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gs0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_3_011
	.byte	PATT
	 .word	mus_battle30_3_011
	.byte	PATT
	 .word	mus_battle30_3_011
	.byte	PATT
	 .word	mus_battle30_3_002
mus_battle30_3_012:
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_012
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_012
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
mus_battle30_3_013:
	.byte		N12   , Gn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_013
	.byte		N12   , Cn1 , v116
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        As0 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Gn0 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte		N12   , Fn0 , v116
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn0 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_3_002
	.byte	PATT
	 .word	mus_battle30_3_003
	.byte	PATT
	 .word	mus_battle30_3_004
	.byte	PATT
	 .word	mus_battle30_3_005
	.byte	PATT
	 .word	mus_battle30_3_006
	.byte	PATT
	 .word	mus_battle30_3_003
	.byte	PATT
	 .word	mus_battle30_3_004
	.byte	PATT
	 .word	mus_battle30_3_007
	.byte	GOTO
	 .word	mus_battle30_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_battle30_4:
	.byte	KEYSH , mus_battle30_key+0
	.byte		LFOS  , 16
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N06   , Ds4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_4_000:
	.byte		N06   , Ds4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , En4 
	.byte	W24
	.byte	PEND
	.byte		N06   , Ds4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_4_000
	.byte		N06   , Ds4 , v052
	.byte	W96
	.byte	W96
	.byte		        Fn4 
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_4_001:
	.byte		N06   , Fn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte	PEND
	.byte		N06   , Fn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_4_001
	.byte		N06   , Fn4 , v052
	.byte	W96
	.byte	W96
mus_battle30_4_B1:
	.byte		PAN   , c_v-48
	.byte		N06   , Gn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_4_002:
	.byte		N06   , Gn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Gs4 
	.byte	W24
	.byte	PEND
	.byte		N06   , Gn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_4_002
	.byte		N06   , Gn4 , v052
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
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		VOICE , 4
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N96   , Cn3 
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 4
	.byte		PAN   , c_v+48
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        En2 
	.byte	W24
mus_battle30_4_003:
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Ds3 
	.byte	W24
	.byte	PEND
	.byte		N12   , Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_4_003
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Fn3 , v072
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Bn2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , As2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Fs2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Fn2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Bn1 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , As1 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 5
	.byte		N12   , Cn2 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 80
	.byte		PAN   , c_v-48
	.byte		N06   , Fn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_battle30_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_battle30_5:
	.byte	KEYSH , mus_battle30_key+0
	.byte		LFOS  , 16
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		BEND  , c_v+0
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		N06   , As3 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_5_000:
	.byte		N06   , As3 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Bn3 
	.byte	W24
	.byte	PEND
	.byte		N06   , As3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_5_000
	.byte		N06   , As3 , v052
	.byte	W96
	.byte	W96
	.byte		        Cn4 
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_5_001:
	.byte		N06   , Cn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte	PEND
	.byte		N06   , Cn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_5_001
	.byte		N06   , Cn4 , v052
	.byte	W96
	.byte	W96
mus_battle30_5_B1:
	.byte		PAN   , c_v+48
	.byte		N06   , Dn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N06   
	.byte	W24
mus_battle30_5_002:
	.byte		N06   , Dn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
	.byte	PEND
	.byte		N06   , Dn4 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_5_002
	.byte		N06   , Dn4 , v052
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
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-3
	.byte	W18
	.byte		VOICE , 5
	.byte		N12   , Cn3 , v032
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte	W06
	.byte		        Cn3 
	.byte	W12
	.byte		VOICE , 6
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte		BEND  , c_v+0
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
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v-2
	.byte		N12   , Bn1 , v072
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N06   , Cn4 , v052
	.byte	W36
	.byte		N06   
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Cn4 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_battle30_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_battle30_6:
	.byte	KEYSH , mus_battle30_key+0
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_battle30_mvl/mxv
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
	.byte	W48
	.byte		N12   , Cn3 , v048
	.byte	W24
	.byte		N12   
	.byte	W24
mus_battle30_6_000:
	.byte		N12   , Cn3 , v048
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PEND
mus_battle30_6_001:
	.byte		N12   , Cn3 , v048
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N06   , Fn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_6_000
mus_battle30_6_002:
	.byte		N12   , Cn3 , v048
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_6_000
	.byte	PATT
	 .word	mus_battle30_6_001
	.byte	PATT
	 .word	mus_battle30_6_000
mus_battle30_6_003:
	.byte		N12   , Cn3 , v048
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		        Cs3 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PEND
mus_battle30_6_B1:
mus_battle30_6_004:
	.byte		N12   , Dn3 , v048
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte	PEND
mus_battle30_6_005:
	.byte		N12   , Dn3 , v048
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_6_004
	.byte		N12   , Dn3 , v048
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PATT
	 .word	mus_battle30_6_004
	.byte	PATT
	 .word	mus_battle30_6_005
	.byte		N12   , Dn3 , v048
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N48   , Gn3 
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
	.byte	PATT
	 .word	mus_battle30_6_000
	.byte	PATT
	 .word	mus_battle30_6_001
	.byte	PATT
	 .word	mus_battle30_6_000
	.byte	PATT
	 .word	mus_battle30_6_002
	.byte	PATT
	 .word	mus_battle30_6_000
	.byte	PATT
	 .word	mus_battle30_6_001
	.byte	PATT
	 .word	mus_battle30_6_000
	.byte	PATT
	 .word	mus_battle30_6_003
	.byte	GOTO
	 .word	mus_battle30_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_battle30_7:
	.byte	KEYSH , mus_battle30_key+0
	.byte		VOICE , 127
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N96   , Gn2 , v116
	.byte	W48
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		VOICE , 126
	.byte		N96   , Bn2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		VOICE , 0
	.byte		N12   , Dn1 , v112
	.byte	W24
mus_battle30_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
mus_battle30_7_B1:
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
mus_battle30_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
mus_battle30_7_002:
	.byte	W24
	.byte		N12   , Ds1 , v092
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_7_002
	.byte	PATT
	 .word	mus_battle30_7_002
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_001
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	W12
	.byte		N12   , Dn1 , v112
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
mus_battle30_7_003:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_003
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	PATT
	 .word	mus_battle30_7_000
	.byte	GOTO
	 .word	mus_battle30_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_battle30_8:
	.byte	KEYSH , mus_battle30_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*mus_battle30_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N96   , Ds2 , v112
	.byte	W48
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte		N96   
	.byte	W96
	.byte	W24
	.byte		N24   , Gn2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
mus_battle30_8_000:
	.byte		N36   , Gn2 , v112
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N24   , Cn2 
	.byte	W24
	.byte	PEND
mus_battle30_8_001:
	.byte		N36   , Gn2 , v112
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_8_000
	.byte	PATT
	 .word	mus_battle30_8_001
	.byte	PATT
	 .word	mus_battle30_8_000
	.byte	PATT
	 .word	mus_battle30_8_000
	.byte	PATT
	 .word	mus_battle30_8_000
	.byte		N36   , Gn2 , v112
	.byte	W36
	.byte		N36   
	.byte	W48
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
mus_battle30_8_002:
	.byte		N12   , Gn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W60
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
mus_battle30_8_003:
	.byte		N12   , Gn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
mus_battle30_8_B1:
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_003
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_003
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte		N12   , Gn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
mus_battle30_8_004:
	.byte		N12   , Gn2 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Fn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_battle30_8_004
	.byte	PATT
	 .word	mus_battle30_8_004
	.byte		N12   , Gn2 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte	PATT
	 .word	mus_battle30_8_004
	.byte	PATT
	 .word	mus_battle30_8_004
	.byte	PATT
	 .word	mus_battle30_8_004
	.byte		N12   , Gn2 , v112
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_003
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	PATT
	 .word	mus_battle30_8_002
	.byte	GOTO
	 .word	mus_battle30_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_battle30:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_battle30_pri	@ Priority
	.byte	mus_battle30_rev	@ Reverb.

	.word	mus_battle30_grp

	.word	mus_battle30_1
	.word	mus_battle30_2
	.word	mus_battle30_3
	.word	mus_battle30_4
	.word	mus_battle30_5
	.word	mus_battle30_6
	.word	mus_battle30_7
	.word	mus_battle30_8

	.end
