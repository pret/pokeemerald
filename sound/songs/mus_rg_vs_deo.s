	.include "MPlayDef.s"

	.equ	mus_rg_vs_deo_grp, voicegroup_86B264C
	.equ	mus_rg_vs_deo_pri, 0
	.equ	mus_rg_vs_deo_rev, reverb_set+50
	.equ	mus_rg_vs_deo_mvl, 127
	.equ	mus_rg_vs_deo_key, 0
	.equ	mus_rg_vs_deo_tbs, 1
	.equ	mus_rg_vs_deo_exg, 0
	.equ	mus_rg_vs_deo_cmp, 1

	.section .rodata
	.global	mus_rg_vs_deo
	.align	2

@********************** Track  1 **********************@

mus_rg_vs_deo_1:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte	TEMPO , 128*mus_rg_vs_deo_tbs/2
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W92
	.byte	TEMPO , 128*mus_rg_vs_deo_tbs/2
	.byte	W04
	.byte		BEND  , c_v+1
	.byte		N12   , Fn1 , v064
	.byte	W06
	.byte	TEMPO , 130*mus_rg_vs_deo_tbs/2
	.byte	W06
	.byte		        Gn1 
	.byte	W05
	.byte	TEMPO , 130*mus_rg_vs_deo_tbs/2
	.byte	W07
	.byte		N36   , As1 
	.byte	W03
	.byte	TEMPO , 132*mus_rg_vs_deo_tbs/2
	.byte	W10
	.byte	TEMPO , 132*mus_rg_vs_deo_tbs/2
	.byte	W11
	.byte	TEMPO , 134*mus_rg_vs_deo_tbs/2
	.byte	W10
	.byte	TEMPO , 134*mus_rg_vs_deo_tbs/2
	.byte	W02
	.byte		N12   , Gs1 
	.byte	W09
	.byte	TEMPO , 136*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		        Gn1 
	.byte	W07
	.byte	TEMPO , 136*mus_rg_vs_deo_tbs/2
	.byte	W05
	.byte		        Fn1 
	.byte	W06
	.byte	TEMPO , 138*mus_rg_vs_deo_tbs/2
	.byte	W06
	.byte		        Ds1 
	.byte	W04
	.byte	TEMPO , 138*mus_rg_vs_deo_tbs/2
	.byte	W08
	.byte		        Fn1 
	.byte	W03
	.byte	TEMPO , 140*mus_rg_vs_deo_tbs/2
	.byte	W09
	.byte		BEND  , c_v-10
	.byte		N24   , As1 
	.byte	W01
	.byte	TEMPO , 140*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W08
	.byte	TEMPO , 142*mus_rg_vs_deo_tbs/2
	.byte		        c_v-11
	.byte	W10
	.byte	TEMPO , 142*mus_rg_vs_deo_tbs/2
	.byte	W02
	.byte		        c_v+1
	.byte		N12   , Gn1 
	.byte	W09
	.byte	TEMPO , 144*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		        Fn1 
	.byte	W07
	.byte	TEMPO , 144*mus_rg_vs_deo_tbs/2
	.byte	W05
	.byte		        Ds1 
	.byte	W06
	.byte	TEMPO , 146*mus_rg_vs_deo_tbs/2
	.byte	W06
	.byte		        Gn1 
	.byte	W04
	.byte	TEMPO , 146*mus_rg_vs_deo_tbs/2
	.byte	W08
	.byte		N48   , Fn1 
	.byte	W03
	.byte	TEMPO , 148*mus_rg_vs_deo_tbs/2
	.byte	W10
	.byte	TEMPO , 148*mus_rg_vs_deo_tbs/2
	.byte	W11
	.byte	TEMPO , 150*mus_rg_vs_deo_tbs/2
	.byte	W10
	.byte	TEMPO , 150*mus_rg_vs_deo_tbs/2
	.byte	W11
	.byte	TEMPO , 152*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		        Gn1 
	.byte	W07
	.byte	TEMPO , 152*mus_rg_vs_deo_tbs/2
	.byte	W11
	.byte	TEMPO , 154*mus_rg_vs_deo_tbs/2
	.byte	W08
	.byte		BEND  , c_v-3
	.byte	W02
	.byte	TEMPO , 154*mus_rg_vs_deo_tbs/2
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-19
	.byte	W02
	.byte		        c_v-23
	.byte	W01
	.byte	TEMPO , 156*mus_rg_vs_deo_tbs/2
	.byte	W01
	.byte		        c_v-29
	.byte	W02
	.byte		        c_v-32
	.byte	W06
	.byte		        c_v+1
	.byte		N24   , Cn1 
	.byte	W01
	.byte	TEMPO , 156*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		BEND  , c_v+3
	.byte	W08
	.byte	TEMPO , 158*mus_rg_vs_deo_tbs/2
	.byte		        c_v+1
	.byte	W10
	.byte	TEMPO , 158*mus_rg_vs_deo_tbs/2
	.byte	W02
	.byte		N08   , Cn2 
	.byte	W08
	.byte		        Cn1 
	.byte	W01
	.byte	TEMPO , 160*mus_rg_vs_deo_tbs/2
	.byte	W07
	.byte		        As1 
	.byte	W03
	.byte	TEMPO , 160*mus_rg_vs_deo_tbs/2
	.byte	W05
	.byte		        Cn1 
	.byte	W06
	.byte	TEMPO , 162*mus_rg_vs_deo_tbs/2
	.byte	W02
	.byte		        Gn1 
	.byte	W08
	.byte	TEMPO , 162*mus_rg_vs_deo_tbs/2
	.byte		        Cn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W03
	.byte	TEMPO , 164*mus_rg_vs_deo_tbs/2
	.byte	W05
	.byte		        Cn1 
	.byte	W05
	.byte	TEMPO , 162*mus_rg_vs_deo_tbs/2
	.byte	W03
	.byte		        Ds1 
	.byte	W08
	.byte	TEMPO , 162*mus_rg_vs_deo_tbs/2
	.byte		VOICE , 78
	.byte		PAN   , c_v+0
	.byte		VOL   , 42*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		TIE   , Cn3 , v020
	.byte	W04
	.byte		VOL   , 45*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        49*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        51*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        56*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        65*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        74*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        77*mus_rg_vs_deo_mvl/mxv
	.byte	W60
	.byte	W48
	.byte		BEND  , c_v+16
	.byte	W02
	.byte		        c_v+28
	.byte	W02
	.byte		        c_v+38
	.byte	W02
	.byte		        c_v+48
	.byte	W02
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+63
	.byte	W14
	.byte		        c_v-16
	.byte	W02
	.byte		        c_v-25
	.byte	W02
	.byte		        c_v-36
	.byte	W02
	.byte		        c_v-49
	.byte	W02
	.byte		        c_v-64
	.byte	W16
	.byte		        c_v+0
	.byte	W96
	.byte	W24
	.byte		        c_v+3
	.byte	W04
	.byte		        c_v+4
	.byte	W04
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+11
	.byte	W02
	.byte		        c_v+12
	.byte	W02
	.byte		        c_v+14
	.byte	W02
	.byte		        c_v+20
	.byte	W02
	.byte		        c_v+22
	.byte	W02
	.byte		        c_v+25
	.byte	W02
	.byte		        c_v+28
	.byte	W02
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+36
	.byte	W02
	.byte		        c_v+41
	.byte	W02
	.byte		        c_v+46
	.byte	W02
	.byte		        c_v+51
	.byte	W02
	.byte		        c_v+56
	.byte	W02
	.byte		        c_v+62
	.byte	W18
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		        61*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		        39*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		        19*mus_rg_vs_deo_mvl/mxv
	.byte	W03
	.byte		EOT   
mus_rg_vs_deo_1_B1:
	.byte		VOL   , 9*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte		        80*mus_rg_vs_deo_mvl/mxv
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
	.byte		VOICE , 30
	.byte		PAN   , c_v+32
	.byte		VOL   , 59*mus_rg_vs_deo_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N04   , Cs4 , v127
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		BEND  , c_v+1
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		VOL   , 62*mus_rg_vs_deo_mvl/mxv
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v+31
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		VOL   , 64*mus_rg_vs_deo_mvl/mxv
	.byte		N04   
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Cs5 , v092
	.byte	W03
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v-4
	.byte	W03
	.byte		        c_v-6
	.byte	W03
	.byte		        c_v-8
	.byte	W03
	.byte		        c_v-10
	.byte	W03
	.byte		        c_v-13
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		VOL   , 54*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		BEND  , c_v-18
	.byte	W03
	.byte		        c_v-19
	.byte	W03
	.byte		        c_v-20
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		BEND  , c_v-22
	.byte	W03
	.byte		VOL   , 50*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-23
	.byte	W03
	.byte		        c_v-24
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v-25
	.byte	W03
	.byte		        c_v-27
	.byte	W03
	.byte		VOL   , 45*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BEND  , c_v-30
	.byte	W03
	.byte		        c_v-34
	.byte	W03
	.byte		        c_v-35
	.byte	W03
	.byte		        c_v-37
	.byte	W03
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-39
	.byte	W03
	.byte		        c_v-41
	.byte	W03
	.byte		VOL   , 35*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-44
	.byte	W03
	.byte		        c_v-47
	.byte	W03
	.byte		VOL   , 30*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-50
	.byte	W03
	.byte		        c_v-53
	.byte	W03
	.byte		VOL   , 25*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-54
	.byte	W03
	.byte		        c_v-57
	.byte	W03
	.byte		VOL   , 20*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-59
	.byte	W03
	.byte		        c_v-61
	.byte	W03
	.byte		VOL   , 15*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-62
	.byte	W03
	.byte		        c_v-64
	.byte	W03
	.byte		        c_v-1
	.byte	W03
	.byte		        c_v+0
	.byte	W92
	.byte	W01
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
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
	.byte		VOICE , 53
	.byte		PAN   , c_v-48
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		TIE   , Dn3 , v112
	.byte	W12
	.byte		PAN   , c_v-34
	.byte		MOD   , 4
	.byte	W12
	.byte		PAN   , c_v-22
	.byte	W12
	.byte		        c_v-8
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+10
	.byte	W12
	.byte		        c_v+30
	.byte	W12
	.byte		        c_v+40
	.byte	W12
	.byte		        c_v+48
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N96   , En3 
	.byte	W12
	.byte		PAN   , c_v+41
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+34
	.byte	W12
	.byte		        c_v+26
	.byte	W12
	.byte		        c_v+22
	.byte	W12
	.byte		        c_v+14
	.byte	W12
	.byte		        c_v+8
	.byte	W12
	.byte		        c_v-1
	.byte	W12
	.byte		        c_v+0
	.byte		MOD   , 0
	.byte		N96   , Dn3 
	.byte	W12
	.byte		PAN   , c_v-8
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v-14
	.byte	W12
	.byte		        c_v-22
	.byte	W12
	.byte		        c_v-26
	.byte	W12
	.byte		        c_v-38
	.byte	W12
	.byte		        c_v-40
	.byte	W24
	.byte		        c_v-48
	.byte		MOD   , 0
	.byte		TIE   , En3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W84
	.byte		PAN   , c_v-48
	.byte	W12
	.byte		        c_v-34
	.byte	W12
	.byte		        c_v-22
	.byte	W12
	.byte		        c_v-8
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v+10
	.byte	W12
	.byte		        c_v+30
	.byte	W12
	.byte		        c_v+40
	.byte	W12
	.byte		EOT   
	.byte		PAN   , c_v+48
	.byte		MOD   , 0
	.byte		N96   , Fs3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W84
	.byte		        0
	.byte		N96   , En3 
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		MOD   , 5
	.byte	W12
	.byte		PAN   , c_v+22
	.byte	W12
	.byte		        c_v+14
	.byte	W12
	.byte		        c_v+0
	.byte	W12
	.byte		        c_v-10
	.byte		VOL   , 32*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		        27*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-26
	.byte	W02
	.byte		VOL   , 23*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-40
	.byte	W02
	.byte		VOL   , 17*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        13*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		MOD   , 0
	.byte		VOL   , 28*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		VOICE , 78
	.byte		PAN   , c_v+48
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , Cs5 , v024
	.byte	W03
	.byte		PAN   , c_v+45
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		        c_v-4
	.byte	W02
	.byte		PAN   , c_v+44
	.byte	W01
	.byte		BEND  , c_v-6
	.byte	W02
	.byte		PAN   , c_v+42
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		PAN   , c_v+40
	.byte	W01
	.byte		BEND  , c_v-10
	.byte	W03
	.byte		        c_v-13
	.byte	W02
	.byte		PAN   , c_v+39
	.byte	W01
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		PAN   , c_v+37
	.byte	W01
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		PAN   , c_v+36
	.byte	W01
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		PAN   , c_v+32
	.byte	W01
	.byte		BEND  , c_v-20
	.byte	W03
	.byte		        c_v-22
	.byte	W02
	.byte		PAN   , c_v+30
	.byte	W01
	.byte		BEND  , c_v-23
	.byte	W02
	.byte		PAN   , c_v+28
	.byte	W01
	.byte		BEND  , c_v-24
	.byte	W02
	.byte		PAN   , c_v+27
	.byte	W01
	.byte		BEND  , c_v-25
	.byte	W02
	.byte		PAN   , c_v+25
	.byte	W01
	.byte		BEND  , c_v-27
	.byte	W02
	.byte		PAN   , c_v+24
	.byte	W01
	.byte		BEND  , c_v-30
	.byte	W02
	.byte		PAN   , c_v+23
	.byte	W01
	.byte		BEND  , c_v-34
	.byte	W02
	.byte		PAN   , c_v+20
	.byte	W01
	.byte		BEND  , c_v-35
	.byte	W02
	.byte		PAN   , c_v+18
	.byte	W01
	.byte		BEND  , c_v-37
	.byte	W02
	.byte		PAN   , c_v+16
	.byte	W01
	.byte		BEND  , c_v-39
	.byte	W03
	.byte		        c_v-41
	.byte	W02
	.byte		PAN   , c_v+13
	.byte	W01
	.byte		BEND  , c_v-44
	.byte	W03
	.byte		        c_v-47
	.byte	W02
	.byte		PAN   , c_v+11
	.byte	W01
	.byte		BEND  , c_v-50
	.byte	W02
	.byte		PAN   , c_v+9
	.byte	W01
	.byte		BEND  , c_v-53
	.byte	W02
	.byte		PAN   , c_v+8
	.byte	W01
	.byte		BEND  , c_v-54
	.byte	W03
	.byte		        c_v-57
	.byte	W02
	.byte		PAN   , c_v+6
	.byte	W01
	.byte		BEND  , c_v-59
	.byte	W03
	.byte		        c_v-61
	.byte	W02
	.byte		PAN   , c_v+4
	.byte	W01
	.byte		BEND  , c_v-62
	.byte	W03
	.byte		        c_v-64
	.byte	W02
	.byte		PAN   , c_v+1
	.byte	W01
	.byte		BEND  , c_v+0
	.byte		N96   , Cs4 
	.byte	W03
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-2
	.byte	W03
	.byte		PAN   , c_v-3
	.byte		BEND  , c_v-4
	.byte	W03
	.byte		        c_v-6
	.byte	W02
	.byte		PAN   , c_v-4
	.byte	W01
	.byte		BEND  , c_v-8
	.byte	W02
	.byte		PAN   , c_v-6
	.byte	W01
	.byte		BEND  , c_v-10
	.byte	W02
	.byte		PAN   , c_v-8
	.byte	W01
	.byte		BEND  , c_v-13
	.byte	W02
	.byte		PAN   , c_v-9
	.byte	W01
	.byte		BEND  , c_v-15
	.byte	W02
	.byte		PAN   , c_v-11
	.byte	W01
	.byte		BEND  , c_v-18
	.byte	W02
	.byte		PAN   , c_v-13
	.byte	W01
	.byte		BEND  , c_v-19
	.byte	W02
	.byte		PAN   , c_v-16
	.byte	W01
	.byte		BEND  , c_v-20
	.byte	W02
	.byte		PAN   , c_v-17
	.byte	W01
	.byte		BEND  , c_v-22
	.byte	W02
	.byte		PAN   , c_v-20
	.byte	W01
	.byte		BEND  , c_v-23
	.byte	W02
	.byte		PAN   , c_v-21
	.byte	W01
	.byte		BEND  , c_v-24
	.byte	W02
	.byte		PAN   , c_v-24
	.byte	W01
	.byte		BEND  , c_v-25
	.byte	W02
	.byte		PAN   , c_v-25
	.byte	W01
	.byte		BEND  , c_v-27
	.byte	W02
	.byte		PAN   , c_v-28
	.byte	W01
	.byte		BEND  , c_v-30
	.byte	W03
	.byte		        c_v-34
	.byte	W02
	.byte		PAN   , c_v-30
	.byte	W01
	.byte		BEND  , c_v-35
	.byte	W02
	.byte		PAN   , c_v-32
	.byte	W01
	.byte		BEND  , c_v-37
	.byte	W02
	.byte		PAN   , c_v-35
	.byte	W01
	.byte		BEND  , c_v-39
	.byte	W02
	.byte		PAN   , c_v-37
	.byte	W01
	.byte		BEND  , c_v-41
	.byte	W02
	.byte		PAN   , c_v-39
	.byte	W01
	.byte		BEND  , c_v-44
	.byte	W02
	.byte		PAN   , c_v-40
	.byte	W01
	.byte		BEND  , c_v-47
	.byte	W02
	.byte		PAN   , c_v-42
	.byte	W01
	.byte		BEND  , c_v-50
	.byte	W03
	.byte		        c_v-53
	.byte	W03
	.byte		        c_v-54
	.byte	W03
	.byte		        c_v-57
	.byte	W03
	.byte		        c_v-59
	.byte	W03
	.byte		        c_v-61
	.byte	W03
	.byte		        c_v-62
	.byte	W03
	.byte		        c_v-64
	.byte	W03
	.byte		VOICE , 62
	.byte		PAN   , c_v-32
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N08   , Cn2 , v127
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		PAN   , c_v-33
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N24   , Cs3 
	.byte	W04
	.byte		MOD   , 6
	.byte	W20
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N08   , Cn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		N24   , Cs3 
	.byte	W04
	.byte		MOD   , 6
	.byte	W20
	.byte	GOTO
	 .word	mus_rg_vs_deo_1_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_vs_deo_2:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 10*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W04
	.byte		N01   , En5 , v064
	.byte	W02
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Fs5 , v020
	.byte	W11
	.byte		PAN   , c_v-62
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W08
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W05
	.byte		PAN   , c_v-62
	.byte	W06
	.byte		N01   , Bn4 , v064
	.byte	W02
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N01   , Dn5 , v020
	.byte	W10
	.byte		        Fs5 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Cs4 , v064
	.byte	W03
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W02
	.byte		        As3 
	.byte	W04
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		N01   , Fs3 , v064
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W03
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W07
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W03
	.byte		PAN   , c_v-62
	.byte		N01   , An4 , v020
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Gs4 , v020
	.byte	W09
	.byte		        En5 , v064
	.byte	W02
	.byte		        En5 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W08
	.byte		VOL   , 20*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W05
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W02
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W09
	.byte		N01   , Bn4 , v064
	.byte	W02
	.byte		        Bn4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Dn5 , v020
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Cs5 , v020
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W03
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W02
	.byte		        As3 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		VOL   , 30*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N01   , Cn5 
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		N01   , Gn3 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W08
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W03
	.byte		        An4 , v020
	.byte	W07
	.byte		        Fs4 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , En5 , v064
	.byte	W02
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Cn5 
	.byte	W09
	.byte		        Fs3 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W08
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W05
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W02
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W09
	.byte		N01   , Bn4 , v064
	.byte	W02
	.byte		        Bn4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Dn5 , v020
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Cs5 , v020
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W03
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W02
	.byte		        As3 
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		VOL   , 50*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N01   , Cn5 
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W01
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		N01   , Gn3 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W08
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W03
	.byte		        An4 , v020
	.byte	W07
	.byte		        Fs4 , v064
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , En5 , v064
	.byte	W02
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Cn5 
	.byte	W09
	.byte		        Fs3 , v064
	.byte	W02
	.byte		PAN   , c_v-63
	.byte		N01   , Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W08
	.byte		VOL   , 56*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cn3 , v040
	.byte	W04
	.byte		        Cn3 , v024
	.byte	W04
	.byte		        Gn3 , v040
	.byte	W04
	.byte		        Gn3 , v024
	.byte	W04
	.byte		        Fn3 , v040
	.byte	W04
	.byte		        Fn3 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        As3 , v040
	.byte	W04
	.byte		        As3 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W12
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds4 , v040
	.byte	W04
	.byte		        Ds4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
mus_rg_vs_deo_2_000:
	.byte		N04   , Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        Gn4 , v040
	.byte	W04
	.byte		        Gn4 , v024
	.byte	W04
	.byte		        Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        As4 , v040
	.byte	W04
	.byte		        As4 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W12
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds5 , v040
	.byte	W04
	.byte		        Ds5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_2_001:
	.byte		N04   , Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        Gn4 , v040
	.byte	W04
	.byte		        Gn4 , v024
	.byte	W04
	.byte		        Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        As4 , v040
	.byte	W04
	.byte		        As4 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W12
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds5 , v040
	.byte	W04
	.byte		        Ds5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_2_002:
	.byte		N04   , Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        Gn5 , v040
	.byte	W04
	.byte		        Gn5 , v024
	.byte	W04
	.byte		        Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W04
	.byte		        As5 , v040
	.byte	W04
	.byte		        As5 , v024
	.byte	W04
	.byte		        Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W12
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte		        Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds6 , v040
	.byte	W04
	.byte		        Ds6 , v024
	.byte	W04
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_2_B1:
mus_rg_vs_deo_2_003:
	.byte		N04   , Fn6 , v040
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        Cn3 , v024
	.byte	W04
	.byte		        Gn3 , v040
	.byte	W04
	.byte		        Gn3 , v024
	.byte	W04
	.byte		        Fn3 , v040
	.byte	W04
	.byte		        Fn3 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        As3 , v040
	.byte	W04
	.byte		        As3 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W12
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds4 , v040
	.byte	W04
	.byte		        Ds4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_2_000
	.byte	PATT
	 .word	mus_rg_vs_deo_2_001
	.byte	PATT
	 .word	mus_rg_vs_deo_2_002
	.byte	PATT
	 .word	mus_rg_vs_deo_2_003
	.byte	PATT
	 .word	mus_rg_vs_deo_2_000
	.byte	PATT
	 .word	mus_rg_vs_deo_2_001
	.byte	PATT
	 .word	mus_rg_vs_deo_2_002
	.byte	PATT
	 .word	mus_rg_vs_deo_2_003
	.byte	PATT
	 .word	mus_rg_vs_deo_2_000
	.byte	PATT
	 .word	mus_rg_vs_deo_2_001
	.byte	PATT
	 .word	mus_rg_vs_deo_2_002
	.byte		N04   , Fn6 , v040
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Cs3 , v024
	.byte	W04
	.byte		        Gs3 , v040
	.byte	W04
	.byte		        Gs3 , v024
	.byte	W04
	.byte		        Fs3 , v040
	.byte	W04
	.byte		        Fs3 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Bn3 , v040
	.byte	W04
	.byte		        Bn3 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W12
	.byte		        Dn4 , v040
	.byte	W04
	.byte		        Dn4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En4 , v040
	.byte	W04
	.byte		        En4 , v024
	.byte	W04
	.byte		        Dn4 , v040
	.byte	W04
	.byte		        Dn4 , v024
	.byte	W04
mus_rg_vs_deo_2_004:
	.byte		N04   , Fs4 , v040
	.byte	W04
	.byte		        Fs4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Gs4 , v040
	.byte	W04
	.byte		        Gs4 , v024
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        Fs4 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Bn4 , v040
	.byte	W04
	.byte		        Bn4 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W12
	.byte		        Dn5 , v040
	.byte	W04
	.byte		        Dn5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En5 , v040
	.byte	W04
	.byte		        En5 , v024
	.byte	W04
	.byte		        Dn5 , v040
	.byte	W04
	.byte		        Dn5 , v024
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_2_005:
	.byte		N04   , Fs5 , v040
	.byte	W04
	.byte		        Fs5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Gs4 , v040
	.byte	W04
	.byte		        Gs4 , v024
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        Fs4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Bn4 , v040
	.byte	W04
	.byte		        Bn4 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W12
	.byte		        Dn5 , v040
	.byte	W04
	.byte		        Dn5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En5 , v040
	.byte	W04
	.byte		        En5 , v024
	.byte	W04
	.byte		        Dn5 , v040
	.byte	W04
	.byte		        Dn5 , v024
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_2_006:
	.byte		N04   , Fs5 , v040
	.byte	W04
	.byte		        Fs5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Gs5 , v040
	.byte	W04
	.byte		        Gs5 , v024
	.byte	W04
	.byte		        Fs5 , v040
	.byte	W04
	.byte		        Fs5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte		        Bn5 , v040
	.byte	W04
	.byte		        Bn5 , v024
	.byte	W04
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W12
	.byte		        Dn6 , v040
	.byte	W04
	.byte		        Dn6 , v024
	.byte	W04
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En6 , v040
	.byte	W08
	.byte		        Dn6 
	.byte	W04
	.byte		        Dn6 , v024
	.byte	W04
	.byte	PEND
	.byte		        Fs6 , v040
	.byte	W08
	.byte		PAN   , c_v+63
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Cs3 , v024
	.byte	W04
	.byte		        Gs3 , v040
	.byte	W04
	.byte		        Gs3 , v024
	.byte	W04
	.byte		        Fs3 , v040
	.byte	W04
	.byte		        Fs3 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Bn3 , v040
	.byte	W04
	.byte		        Bn3 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W12
	.byte		        Dn4 , v040
	.byte	W04
	.byte		        Dn4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En4 , v040
	.byte	W04
	.byte		        En4 , v024
	.byte	W04
	.byte		        Dn4 , v040
	.byte	W04
	.byte		        Dn4 , v024
	.byte	W04
	.byte	PATT
	 .word	mus_rg_vs_deo_2_004
	.byte	PATT
	 .word	mus_rg_vs_deo_2_005
	.byte	PATT
	 .word	mus_rg_vs_deo_2_006
	.byte		N04   , Fs6 , v040
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
	.byte		PAN   , c_v-64
	.byte		VOL   , 30*mus_rg_vs_deo_mvl/mxv
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        En2 , v064
	.byte	W04
	.byte		        En2 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        En2 , v064
	.byte	W04
	.byte		        En2 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En2 , v064
	.byte	W04
	.byte		        En2 , v040
	.byte	W04
	.byte		        Bn2 , v064
	.byte	W04
	.byte		        Bn2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		BEND  , c_v+1
	.byte		N04   , En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 45*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+3
	.byte		N04   , En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		        An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        Dn3 , v064
	.byte	W04
	.byte		        Dn3 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , An2 , v064
	.byte	W04
	.byte		        An2 , v040
	.byte	W04
	.byte		        En3 , v064
	.byte	W04
	.byte		        En3 , v040
	.byte	W04
	.byte		        An3 , v064
	.byte	W04
	.byte		        An3 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		VOL   , 50*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N04   , Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v040
	.byte	W04
	.byte		        Bn3 , v064
	.byte	W04
	.byte		        Bn3 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        En4 , v064
	.byte	W04
	.byte		        En4 , v040
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        En4 , v064
	.byte	W04
	.byte		        En4 , v040
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v040
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v040
	.byte	W04
	.byte		        En4 , v064
	.byte	W04
	.byte		        En4 , v040
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v040
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte		N04   , Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        Bn4 , v080
	.byte	W04
	.byte		        Bn4 , v048
	.byte	W04
	.byte		        Bn3 , v080
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte		N04   , Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        En4 , v080
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N04   , Bn4 , v080
	.byte	W04
	.byte		        Bn4 , v048
	.byte	W04
	.byte		        Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        Bn4 , v080
	.byte	W04
	.byte		        Bn4 , v048
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		N04   , Bn3 , v080
	.byte	W04
	.byte		        Bn3 , v048
	.byte	W04
	.byte		        Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        Bn4 , v080
	.byte	W04
	.byte		        Bn4 , v048
	.byte	W04
	.byte		VOICE , 14
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N48   , Fn3 , v127
	.byte	W48
	.byte		        Gn3 , v112
	.byte	W48
	.byte		N96   , Cn3 , v104
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		VOICE , 80
	.byte		VOL   , 56*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		PAN   , c_v-64
	.byte		N04   , Cn3 , v040
	.byte	W04
	.byte		        Cn3 , v024
	.byte	W04
	.byte		        Gn3 , v040
	.byte	W04
	.byte		        Gn3 , v024
	.byte	W04
	.byte		        Fn3 , v040
	.byte	W04
	.byte		        Fn3 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        As3 , v040
	.byte	W04
	.byte		        As3 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W12
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds4 , v040
	.byte	W04
	.byte		        Ds4 , v024
	.byte	W04
	.byte		        Cs4 , v040
	.byte	W04
	.byte		        Cs4 , v024
	.byte	W04
	.byte		        Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		        Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        Gn4 , v040
	.byte	W04
	.byte		        Gn4 , v024
	.byte	W04
	.byte		        Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        As4 , v040
	.byte	W04
	.byte		        As4 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W12
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds5 , v040
	.byte	W04
	.byte		        Ds5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 , v040
	.byte	W04
	.byte		        Cn4 , v024
	.byte	W04
	.byte		        Gn4 , v040
	.byte	W04
	.byte		        Gn4 , v024
	.byte	W04
	.byte		        Fn4 , v040
	.byte	W04
	.byte		        Fn4 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        As4 , v040
	.byte	W04
	.byte		        As4 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W12
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds5 , v040
	.byte	W04
	.byte		        Ds5 , v024
	.byte	W04
	.byte		        Cs5 , v040
	.byte	W04
	.byte		        Cs5 , v024
	.byte	W04
	.byte		        Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		        Cn5 , v040
	.byte	W04
	.byte		        Cn5 , v024
	.byte	W04
	.byte		        Gn5 , v040
	.byte	W04
	.byte		        Gn5 , v024
	.byte	W04
	.byte		        Fn5 , v040
	.byte	W04
	.byte		        Fn5 , v024
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W04
	.byte		        As5 , v040
	.byte	W04
	.byte		        As5 , v024
	.byte	W04
	.byte		        Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W12
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte		        Cn6 , v040
	.byte	W04
	.byte		        Cn6 , v024
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds6 , v040
	.byte	W04
	.byte		        Ds6 , v024
	.byte	W04
	.byte		        Cs6 , v040
	.byte	W04
	.byte		        Cs6 , v024
	.byte	W04
	.byte	GOTO
	 .word	mus_rg_vs_deo_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_vs_deo_3:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 31
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 59*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W72
	.byte		BEND  , c_v+0
	.byte		TIE   , As3 , v020
	.byte	W24
	.byte	W48
	.byte	W01
	.byte		BEND  , c_v-5
	.byte	W01
	.byte		        c_v-6
	.byte	W01
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-18
	.byte	W01
	.byte		        c_v-22
	.byte	W01
	.byte		        c_v-24
	.byte	W01
	.byte		        c_v-26
	.byte	W02
	.byte		        c_v-32
	.byte	W02
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-40
	.byte	W02
	.byte		        c_v-44
	.byte	W02
	.byte		        c_v-47
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-54
	.byte	W02
	.byte		        c_v-56
	.byte	W02
	.byte		        c_v-58
	.byte	W01
	.byte		        c_v-59
	.byte	W02
	.byte		        c_v-60
	.byte	W02
	.byte		        c_v-62
	.byte	W03
	.byte		        c_v-63
	.byte	W14
	.byte	W01
	.byte		        c_v-63
	.byte	W02
	.byte		        c_v-62
	.byte	W02
	.byte		        c_v-58
	.byte	W03
	.byte		        c_v-54
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-38
	.byte	W03
	.byte		        c_v-34
	.byte	W01
	.byte		        c_v-31
	.byte	W01
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-11
	.byte	W01
	.byte		        c_v-5
	.byte	W01
	.byte		        c_v+7
	.byte	W02
	.byte		        c_v+26
	.byte	W02
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+49
	.byte	W02
	.byte		        c_v+53
	.byte	W02
	.byte		        c_v+59
	.byte	W01
	.byte		        c_v+63
	.byte	W44
	.byte	W03
	.byte		        c_v+63
	.byte	W01
	.byte		        c_v+62
	.byte	W01
	.byte		        c_v+61
	.byte	W01
	.byte		        c_v+59
	.byte	W02
	.byte		        c_v+58
	.byte	W03
	.byte		        c_v+56
	.byte	W01
	.byte		        c_v+53
	.byte	W03
	.byte		        c_v+52
	.byte	W01
	.byte		        c_v+50
	.byte	W02
	.byte		        c_v+42
	.byte	W02
	.byte	W02
	.byte		        c_v+40
	.byte	W01
	.byte		        c_v+39
	.byte	W02
	.byte		        c_v+37
	.byte	W03
	.byte		        c_v+34
	.byte	W02
	.byte		        c_v+32
	.byte	W02
	.byte		        c_v+29
	.byte	W02
	.byte		        c_v+28
	.byte	W01
	.byte		        c_v+25
	.byte	W02
	.byte		        c_v+22
	.byte	W02
	.byte		        c_v+20
	.byte	W01
	.byte		        c_v+18
	.byte	W01
	.byte		        c_v+17
	.byte	W01
	.byte		        c_v+14
	.byte	W02
	.byte		        c_v+10
	.byte	W02
	.byte		        c_v+8
	.byte	W01
	.byte		        c_v+5
	.byte	W01
	.byte		        c_v+4
	.byte	W01
	.byte		        c_v+1
	.byte	W03
	.byte		        c_v-2
	.byte	W01
	.byte		        c_v-3
	.byte	W01
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-14
	.byte	W03
	.byte		        c_v-19
	.byte	W01
	.byte		        c_v-20
	.byte	W01
	.byte		        c_v-24
	.byte	W02
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-30
	.byte	W01
	.byte		        c_v-32
	.byte	W01
	.byte		        c_v-35
	.byte	W02
	.byte		        c_v-43
	.byte	W02
	.byte		        c_v-44
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-58
	.byte	W02
	.byte		        c_v-60
	.byte	W18
	.byte		        c_v-63
	.byte	W01
	.byte		        c_v-62
	.byte	W01
	.byte		        c_v-58
	.byte	W02
	.byte		        c_v-55
	.byte	W02
	.byte		        c_v-52
	.byte	W01
	.byte		        c_v-51
	.byte	W01
	.byte		        c_v-48
	.byte	W01
	.byte		        c_v-46
	.byte	W02
	.byte		        c_v-37
	.byte	W02
	.byte		        c_v-35
	.byte	W01
	.byte		        c_v-26
	.byte	W01
	.byte		        c_v-16
	.byte	W01
	.byte		        c_v+0
	.byte	W07
	.byte		VOL   , 51*mus_rg_vs_deo_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v+1
	.byte	W01
	.byte		        c_v+2
	.byte	W01
	.byte		        c_v+4
	.byte	W02
	.byte		        c_v+8
	.byte	W02
	.byte		        c_v+9
	.byte	W01
	.byte		VOL   , 45*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W01
	.byte		        c_v+13
	.byte	W01
	.byte		        c_v+16
	.byte	W02
	.byte		        c_v+24
	.byte	W02
	.byte		        c_v+26
	.byte	W01
	.byte		        c_v+30
	.byte	W01
	.byte		VOL   , 37*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+31
	.byte	W01
	.byte		        c_v+34
	.byte	W02
	.byte		        c_v+35
	.byte	W01
	.byte		        c_v+37
	.byte	W01
	.byte		        c_v+38
	.byte	W01
	.byte		        c_v+41
	.byte	W02
	.byte		VOL   , 30*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+44
	.byte	W02
	.byte		        c_v+45
	.byte	W01
	.byte		        c_v+49
	.byte	W01
	.byte		        c_v+50
	.byte	W01
	.byte		        c_v+53
	.byte	W02
	.byte		        c_v+55
	.byte	W01
	.byte		VOL   , 21*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+56
	.byte	W01
	.byte		        c_v+59
	.byte	W01
	.byte		        c_v+63
	.byte	W02
	.byte		        c_v+63
	.byte	W04
	.byte		VOL   , 13*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		EOT   
	.byte	W48
	.byte	W02
	.byte		VOICE , 87
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W01
	.byte		        c_v+0
	.byte	W92
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_vs_deo_3_B1:
	.byte		VOICE , 87
	.byte		N08   , Gn2 , v104
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
mus_rg_vs_deo_3_000:
	.byte		N08   , Gn2 , v104
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_3_001:
	.byte		N08   , Gn2 , v104
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte		VOICE , 84
	.byte		N08   , Gs2 , v104
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
mus_rg_vs_deo_3_002:
	.byte		N08   , Gs2 , v104
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_3_003:
	.byte		N08   , Gs2 , v104
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_3_002
	.byte	PATT
	 .word	mus_rg_vs_deo_3_003
	.byte	PATT
	 .word	mus_rg_vs_deo_3_002
	.byte	PATT
	 .word	mus_rg_vs_deo_3_003
	.byte	PATT
	 .word	mus_rg_vs_deo_3_002
	.byte		VOICE , 87
	.byte		N08   , Gs2 , v104
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_3_002
	.byte	PATT
	 .word	mus_rg_vs_deo_3_003
	.byte	PATT
	 .word	mus_rg_vs_deo_3_002
mus_rg_vs_deo_3_004:
	.byte		N08   , As2 , v104
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_3_005:
	.byte		N08   , As2 , v104
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_3_004
	.byte	PATT
	 .word	mus_rg_vs_deo_3_005
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		N08   , Bn2 , v104
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
mus_rg_vs_deo_3_006:
	.byte		N08   , Bn2 , v104
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte	PEND
	.byte		VOICE , 84
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		N08   , Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_3_006
	.byte		VOICE , 85
	.byte		N08   , En3 , v104
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
mus_rg_vs_deo_3_007:
	.byte		N08   , En3 , v104
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte	PEND
	.byte		VOICE , 84
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte		N08   , En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_3_007
	.byte		VOICE , 87
	.byte		N08   , Cn3 , v104
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
mus_rg_vs_deo_3_008:
	.byte		N08   , Cn3 , v104
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte	PEND
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Fn2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        As2 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_3_008
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	PATT
	 .word	mus_rg_vs_deo_3_001
	.byte	PATT
	 .word	mus_rg_vs_deo_3_000
	.byte	GOTO
	 .word	mus_rg_vs_deo_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_vs_deo_4:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 33
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte		N12   , Fn1 , v127
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N36   , As1 
	.byte	W36
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		BEND  , c_v-10
	.byte		N24   , As1 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		        c_v-11
	.byte	W12
	.byte		        c_v+0
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N48   , Fn1 
	.byte	W48
	.byte		        Gn1 
	.byte	W24
	.byte	W02
	.byte		BEND  , c_v-3
	.byte	W02
	.byte		        c_v-6
	.byte	W02
	.byte		        c_v-10
	.byte	W02
	.byte		        c_v-11
	.byte	W02
	.byte		        c_v-14
	.byte	W02
	.byte		        c_v-19
	.byte	W02
	.byte		        c_v-23
	.byte	W02
	.byte		        c_v-29
	.byte	W02
	.byte		        c_v-32
	.byte	W06
	.byte		        c_v-1
	.byte		N24   , Cn1 
	.byte	W02
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		        c_v+3
	.byte	W08
	.byte		        c_v+0
	.byte	W12
	.byte		N08   , Cn2 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Gn1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Fn1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
mus_rg_vs_deo_4_000:
	.byte		N08   , Cn1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Cn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_4_001:
	.byte		N08   , Cn1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N24   , Cs2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
mus_rg_vs_deo_4_B1:
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
mus_rg_vs_deo_4_002:
	.byte		N08   , Cs1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_4_003:
	.byte		N08   , Cs1 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		N24   , Dn2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_4_002
	.byte	PATT
	 .word	mus_rg_vs_deo_4_003
	.byte	PATT
	 .word	mus_rg_vs_deo_4_002
	.byte	PATT
	 .word	mus_rg_vs_deo_4_003
	.byte	PATT
	 .word	mus_rg_vs_deo_4_002
	.byte		N08   , Cs1 , v127
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        Bn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
mus_rg_vs_deo_4_004:
	.byte		N08   , Bn0 , v127
	.byte	W16
	.byte		        Cs1 
	.byte	W08
	.byte		        Bn0 
	.byte	W16
	.byte		        Cs1 
	.byte	W08
	.byte		        Bn0 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte	PEND
	.byte		        Bn0 
	.byte	W16
	.byte		        Cs1 
	.byte	W08
	.byte		        Bn0 
	.byte	W16
	.byte		        En1 
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		        Cs1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_4_004
	.byte		N08   , Bn0 , v127
	.byte	W16
	.byte		        Cs1 
	.byte	W08
	.byte		        Bn0 
	.byte	W16
	.byte		        En1 
	.byte	W08
	.byte		        Bn0 
	.byte	W16
	.byte		        Ds1 
	.byte	W08
	.byte		        Bn0 
	.byte	W16
	.byte		        Cs1 
	.byte	W08
mus_rg_vs_deo_4_005:
	.byte		N08   , Cs1 , v127
	.byte	W16
	.byte		        Ds1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		        Ds1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte	PEND
	.byte		        Cs1 
	.byte	W16
	.byte		        Ds1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		        Fs1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Ds1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_4_005
	.byte		N08   , Cs1 , v127
	.byte	W16
	.byte		        Ds1 
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		        As0 
	.byte	W24
	.byte		        Bn0 
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Ds1 
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_vs_deo_4_006:
	.byte		N08   , En0 , v127
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        En0 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_4_006
	.byte	PATT
	 .word	mus_rg_vs_deo_4_006
	.byte	PATT
	 .word	mus_rg_vs_deo_4_006
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	PATT
	 .word	mus_rg_vs_deo_4_000
	.byte	PATT
	 .word	mus_rg_vs_deo_4_001
	.byte	GOTO
	 .word	mus_rg_vs_deo_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_vs_deo_5:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W04
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v-61
	.byte		N01   , Fs5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W08
	.byte		N01   , Dn5 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W09
	.byte		PAN   , c_v-62
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W04
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W02
	.byte		        Dn5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W09
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W04
	.byte		PAN   , c_v-62
	.byte		VOL   , 50*mus_rg_vs_deo_mvl/mxv
	.byte	W02
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W05
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		        Gn3 , v020
	.byte	W03
	.byte		PAN   , c_v-62
	.byte	W06
	.byte		N01   , Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W02
	.byte		        An4 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W09
	.byte		PAN   , c_v-62
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W05
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Dn5 , v020
	.byte	W11
	.byte		PAN   , c_v-62
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W05
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W01
mus_rg_vs_deo_5_000:
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		        Cn4 , v064
	.byte	W03
	.byte		        Cn4 , v020
	.byte	W01
	.byte		        Gn3 , v064
	.byte	W02
	.byte		PAN   , c_v+63
	.byte		N01   , Gn3 , v020
	.byte	W09
	.byte		        Gn4 , v064
	.byte	W02
	.byte		        Gn4 , v020
	.byte		N01   , An4 , v064
	.byte	W01
	.byte		PAN   , c_v-61
	.byte	W01
	.byte		N01   , An4 , v020
	.byte	W01
	.byte		PAN   , c_v-62
	.byte	W07
	.byte		N01   , Fs4 , v064
	.byte	W02
	.byte		        Fs4 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Gs4 , v064
	.byte	W02
	.byte		        Gs4 , v020
	.byte	W07
	.byte		PAN   , c_v-62
	.byte	W01
	.byte		N01   , En5 , v064
	.byte	W03
	.byte		        En5 , v020
	.byte	W02
	.byte		        Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W07
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		PAN   , c_v-62
	.byte		N01   , Cn5 
	.byte	W09
	.byte		        Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte		N01   , Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W09
	.byte	PEND
	.byte		PAN   , c_v-62
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W01
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v-61
	.byte	W02
	.byte		        c_v-62
	.byte	W05
	.byte		N01   , Bn4 , v064
	.byte	W03
	.byte		        Bn4 , v020
	.byte	W01
	.byte		        Dn5 , v064
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W01
	.byte		N01   , Dn5 , v020
	.byte	W11
	.byte		PAN   , c_v-62
	.byte		N01   , Fs5 , v064
	.byte	W03
	.byte		        Fs5 , v020
	.byte	W06
	.byte		        Cs5 , v064
	.byte	W02
	.byte		        Cs5 , v020
	.byte	W01
	.byte		PAN   , c_v+63
	.byte	W05
	.byte		N01   , Cs4 , v064
	.byte	W02
	.byte		        As3 
	.byte		N01   , Cs4 , v020
	.byte	W03
	.byte		        As3 
	.byte	W02
	.byte		PAN   , c_v-62
	.byte	W03
	.byte		N01   , Fs3 , v064
	.byte	W02
	.byte		        Fs3 , v020
	.byte	W01
	.byte		        Gs3 , v064
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N01   , Dn5 , v064
	.byte	W03
	.byte		        Cn5 
	.byte		N01   , Dn5 , v020
	.byte	W02
	.byte		        Cn5 
	.byte	W01
	.byte	PATT
	 .word	mus_rg_vs_deo_5_000
	.byte		PAN   , c_v-64
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N04   , Cn3 , v064
	.byte	W04
	.byte		        Cn3 , v032
	.byte	W04
	.byte		        Gn3 , v064
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        Fn3 , v064
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        As3 , v064
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W12
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds4 , v064
	.byte	W04
	.byte		        Ds4 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
mus_rg_vs_deo_5_001:
	.byte		N04   , Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        As4 , v064
	.byte	W04
	.byte		        As4 , v032
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds5 , v064
	.byte	W04
	.byte		        Ds5 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Fn5 , v064
	.byte	W04
	.byte		        Fn5 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_002:
	.byte		PAN   , c_v+63
	.byte		N04   , Cn3 , v064
	.byte	W04
	.byte		        Cn3 , v032
	.byte	W04
	.byte		        Gn3 , v064
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        Fn3 , v064
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        As3 , v064
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W12
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds4 , v064
	.byte	W04
	.byte		        Ds4 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_003:
	.byte		N04   , Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		        Gn4 , v032
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		        As4 , v064
	.byte	W04
	.byte		        As4 , v032
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W12
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Cn5 , v064
	.byte	W04
	.byte		        Cn5 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Ds5 , v064
	.byte	W04
	.byte		        Ds5 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Fn5 , v064
	.byte	W04
	.byte		        Fn5 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_B1:
mus_rg_vs_deo_5_004:
	.byte		PAN   , c_v-64
	.byte		N04   , Cn3 , v064
	.byte	W04
	.byte		        Cn3 , v032
	.byte	W04
	.byte		        Gn3 , v064
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        Fn3 , v064
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		        As3 , v064
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W12
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cn4 , v064
	.byte	W04
	.byte		        Cn4 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Ds4 , v064
	.byte	W04
	.byte		        Ds4 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Fn4 , v064
	.byte	W04
	.byte		        Fn4 , v032
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_5_001
	.byte	PATT
	 .word	mus_rg_vs_deo_5_002
	.byte	PATT
	 .word	mus_rg_vs_deo_5_003
	.byte	PATT
	 .word	mus_rg_vs_deo_5_004
	.byte	PATT
	 .word	mus_rg_vs_deo_5_001
	.byte	PATT
	 .word	mus_rg_vs_deo_5_002
	.byte	PATT
	 .word	mus_rg_vs_deo_5_003
	.byte	PATT
	 .word	mus_rg_vs_deo_5_004
	.byte	PATT
	 .word	mus_rg_vs_deo_5_001
	.byte	PATT
	 .word	mus_rg_vs_deo_5_002
	.byte	PATT
	 .word	mus_rg_vs_deo_5_003
mus_rg_vs_deo_5_005:
	.byte		PAN   , c_v-64
	.byte		N04   , Cs3 , v064
	.byte	W04
	.byte		        Cs3 , v032
	.byte	W04
	.byte		        Gs3 , v064
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		        Fs3 , v064
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v064
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En4 , v064
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_006:
	.byte		N04   , Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W12
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , En5 , v064
	.byte	W04
	.byte		        En5 , v032
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        Fs5 , v064
	.byte	W04
	.byte		        Fs5 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_007:
	.byte		PAN   , c_v+63
	.byte		N04   , Cs3 , v064
	.byte	W04
	.byte		        Cs3 , v032
	.byte	W04
	.byte		        Gs3 , v064
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		        Fs3 , v064
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v064
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En4 , v064
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte	PEND
mus_rg_vs_deo_5_008:
	.byte		N04   , Cs4 , v064
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		        Fs4 , v064
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		PAN   , c_v-64
	.byte		N04   , Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W12
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        Cs5 , v064
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , En5 , v064
	.byte	W04
	.byte		        En5 , v032
	.byte	W04
	.byte		        Dn5 , v064
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        Fs5 , v064
	.byte	W04
	.byte		        Fs5 , v032
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_5_005
	.byte	PATT
	 .word	mus_rg_vs_deo_5_006
	.byte	PATT
	 .word	mus_rg_vs_deo_5_007
	.byte	PATT
	 .word	mus_rg_vs_deo_5_008
	.byte		VOICE , 62
	.byte		PAN   , c_v+32
	.byte		N16   , Bn3 , v080
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N32   , Cs2 , v100
	.byte	W32
mus_rg_vs_deo_5_009:
	.byte		PAN   , c_v+32
	.byte		N16   , Bn3 , v080
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N08   , En4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Cs4 
	.byte	W08
	.byte	PEND
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W32
	.byte		PAN   , c_v-48
	.byte		N24   , Cs2 , v100
	.byte	W24
	.byte	PATT
	 .word	mus_rg_vs_deo_5_009
	.byte		N16   , Cs4 , v080
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N32   , Ds2 , v100
	.byte	W32
mus_rg_vs_deo_5_010:
	.byte		PAN   , c_v+32
	.byte		N16   , Cs4 , v080
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Fs4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W08
	.byte	PEND
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N08   , Ds4 
	.byte	W32
	.byte		PAN   , c_v-48
	.byte		N24   , Ds2 , v100
	.byte	W24
	.byte	PATT
	 .word	mus_rg_vs_deo_5_010
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 40*mus_rg_vs_deo_mvl/mxv
	.byte		TIE   , An2 , v084
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   , Bn2 , v080
	.byte	W96
	.byte		        En2 
	.byte	W96
	.byte		        Cs3 , v076
	.byte	W96
	.byte		        Bn2 , v080
	.byte	W96
	.byte		VOL   , 50*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N48   , Fn3 , v064
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		N96   , Cn3 
	.byte	W96
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W84
	.byte		VOICE , 81
	.byte	W12
	.byte	PATT
	 .word	mus_rg_vs_deo_5_004
	.byte	PATT
	 .word	mus_rg_vs_deo_5_001
	.byte	PATT
	 .word	mus_rg_vs_deo_5_002
	.byte	PATT
	 .word	mus_rg_vs_deo_5_003
	.byte	GOTO
	 .word	mus_rg_vs_deo_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_vs_deo_6:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-22
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W24
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N48   , Fn3 , v060
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N96   , Cn3 
	.byte	W36
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        35*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        25*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        14*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        9*mus_rg_vs_deo_mvl/mxv
	.byte	W72
	.byte	W96
	.byte	W24
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N48   , Fn3 
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N96   , Cn3 
	.byte	W36
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W06
	.byte		VOL   , 55*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 44*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 35*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		VOL   , 25*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        14*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_vs_deo_6_B1:
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
	.byte		VOL   , 62*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v-28
	.byte		TIE   , Gs3 , v096
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N80   , Cs4 
	.byte	W80
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N80   , An3 
	.byte	W80
	.byte		TIE   , Gs3 
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte		N24   , Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N56   , Cs4 
	.byte	W56
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N56   , An4 
	.byte	W08
	.byte	W48
	.byte		N48   , Cn5 
	.byte	W20
	.byte		VOL   , 56*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        45*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        41*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        36*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        31*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        26*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		VOICE , 29
	.byte		PAN   , c_v+32
	.byte		VOL   , 62*mus_rg_vs_deo_mvl/mxv
	.byte	W48
	.byte		PAN   , c_v-48
	.byte		N02   , Cs5 
	.byte	W16
	.byte		PAN   , c_v+32
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v+47
	.byte		N24   , Cs2 
	.byte	W24
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N02   , Cs5 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N24   , Cs2 
	.byte	W24
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v-48
	.byte		N02   , Ds5 
	.byte	W16
	.byte		PAN   , c_v+34
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v+47
	.byte		N24   , Ds2 
	.byte	W24
	.byte	W96
	.byte	W48
	.byte		PAN   , c_v+32
	.byte		N02   , Ds5 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N02   
	.byte	W08
	.byte		PAN   , c_v+48
	.byte		N24   , Ds2 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N16   , Cs5 , v064
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N08   , Fs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W08
	.byte		VOICE , 48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        14
	.byte	W24
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N48   , Fn3 , v048
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N96   , Cn3 
	.byte	W36
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        35*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        25*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        14*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        9*mus_rg_vs_deo_mvl/mxv
	.byte	W24
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W48
	.byte		VOICE , 48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_vs_deo_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_vs_deo_7:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 57
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+0
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
mus_rg_vs_deo_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOICE , 60
	.byte	W36
	.byte		TIE   , Cn4 , v108
	.byte	W72
	.byte		VOL   , 74*mus_rg_vs_deo_mvl/mxv
	.byte	W24
	.byte	W24
	.byte		EOT   
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N80   , Gn4 
	.byte	W32
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W12
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W12
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W12
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W12
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		N16   , Cn4 
	.byte	W16
	.byte		N80   , Cs4 
	.byte	W80
	.byte		TIE   , Cn4 
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte		N24   , Cn5 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N16   , Fn4 
	.byte	W16
	.byte		N56   , Gn4 
	.byte	W20
	.byte		MOD   , 5
	.byte	W12
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   , Cn5 
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		TIE   , Cs4 
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N80   , Gs4 
	.byte	W80
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N80   , Dn4 
	.byte	W80
	.byte		TIE   , Cs4 
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		N16   , Fs4 
	.byte	W16
	.byte		N56   , Gs4 
	.byte	W56
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N56   , Dn5 
	.byte	W08
	.byte	W48
	.byte		N48   , Fs5 
	.byte	W24
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        55*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        44*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W24
	.byte		N32   , Cs3 
	.byte	W32
mus_rg_vs_deo_7_000:
	.byte		N16   , Bn4 , v108
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , En5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		        Cs5 
	.byte	W08
	.byte	PEND
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N16   , Bn4 
	.byte	W16
	.byte		N08   , Cs5 
	.byte	W32
	.byte		N24   , Cs3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_vs_deo_7_000
	.byte		N16   , Cs5 , v108
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W24
	.byte		N32   , Ds3 
	.byte	W32
mus_rg_vs_deo_7_001:
	.byte		N16   , Cs5 , v108
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N08   , Fs5 
	.byte	W24
	.byte		        Fn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W08
	.byte	PEND
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W08
	.byte		N16   , Cs5 
	.byte	W16
	.byte		N08   , Ds5 
	.byte	W32
	.byte		N24   , Ds3 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_vs_deo_7_001
	.byte		TIE   , Dn3 , v112
	.byte	W96
mus_rg_vs_deo_7_002:
	.byte	W48
	.byte		VOL   , 65*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        62*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        57*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        54*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte	PEND
	.byte		EOT   , Dn3 
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N96   , En3 , v112
	.byte	W48
	.byte		VOL   , 65*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 62*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        57*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 54*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		N96   , Dn3 
	.byte	W48
	.byte		VOL   , 65*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        62*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        57*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        54*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        51*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        47*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		TIE   , En3 
	.byte	W96
	.byte	PATT
	 .word	mus_rg_vs_deo_7_002
	.byte		EOT   , En3 
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte		N96   , Fs3 , v112
	.byte	W96
	.byte		        En3 
	.byte	W60
	.byte		VOL   , 65*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        61*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        59*mus_rg_vs_deo_mvl/mxv
	.byte	W08
	.byte		        54*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_vs_deo_mvl/mxv
	.byte	W04
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_vs_deo_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_vs_deo_8:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 14
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N48   , Fn3 , v127
	.byte	W24
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        57*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        46*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 72*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W36
	.byte		VOL   , 72*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        63*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        49*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        42*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        37*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        31*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        27*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        9*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		N48   , Fn3 , v096
	.byte	W24
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        57*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        46*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		VOL   , 72*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        60*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        36*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		N96   , Cn3 
	.byte	W36
	.byte		VOL   , 72*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-1
	.byte	W06
	.byte		VOL   , 63*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        56*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 49*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        42*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-2
	.byte	W06
	.byte		VOL   , 37*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        31*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W06
	.byte		VOL   , 27*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        17*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_vs_deo_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_vs_deo_8_B1:
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+15
	.byte		N48   , Fn3 , v116
	.byte	W24
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N48   , Gn3 , v112
	.byte	W24
	.byte		VOL   , 69*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        80*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N96   , Cn3 , v104
	.byte	W36
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        44*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        40*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        35*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        30*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        25*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        20*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        14*mus_rg_vs_deo_mvl/mxv
	.byte	W06
	.byte		        9*mus_rg_vs_deo_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		VOL   , 70*mus_rg_vs_deo_mvl/mxv
	.byte	W72
	.byte	W68
	.byte		N06   , Gs0 , v120
	.byte	W28
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_vs_deo_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_vs_deo_9:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 0
	.byte		VOL   , 78*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N08   , En1 , v104
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
mus_rg_vs_deo_9_000:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_9_001:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
mus_rg_vs_deo_9_002:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_9_B1:
	.byte		N16   , Cn1 , v100
	.byte		N48   , En2 , v124
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_002
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte		N16   , Cs1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_002
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte		N08   , Cs1 , v127
	.byte	W08
	.byte		N16   , Cs1 , v112
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W16
	.byte		        Cs1 
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
mus_rg_vs_deo_9_003:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_9_004:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Cs1 , v127
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PEND
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Cn1 , v127
	.byte	W16
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W16
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 , v127
	.byte	W08
	.byte		        Cs1 , v112
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_003
	.byte	PATT
	 .word	mus_rg_vs_deo_9_004
	.byte	PATT
	 .word	mus_rg_vs_deo_9_003
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 , v127
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N08   
	.byte	W08
mus_rg_vs_deo_9_005:
	.byte	W24
	.byte		N24   , Cs1 , v112
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N24   
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_005
	.byte	W24
	.byte		N32   , Cs1 , v112
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N08   
	.byte	W08
mus_rg_vs_deo_9_006:
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PEND
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_006
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte		N16   , Cn1 , v127
	.byte		TIE   , Cn3 , v048
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_002
	.byte		EOT   , Cn3 
	.byte		N16   , Cn1 , v127
	.byte		N48   , Gn2 , v096
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte	PATT
	 .word	mus_rg_vs_deo_9_001
	.byte	PATT
	 .word	mus_rg_vs_deo_9_000
	.byte		N16   , Cn1 , v127
	.byte	W16
	.byte		N08   , Cn1 , v112
	.byte	W08
	.byte		N16   , Cs1 
	.byte	W16
	.byte		N08   , Cn1 
	.byte	W08
	.byte		        Cn1 , v127
	.byte		N48   , Cn3 , v072
	.byte	W08
	.byte		N08   , Cs1 , v112
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte	GOTO
	 .word	mus_rg_vs_deo_9_B1
	.byte	FINE

@********************** Track 10 **********************@

mus_rg_vs_deo_10:
	.byte	KEYSH , mus_rg_vs_deo_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*mus_rg_vs_deo_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_vs_deo_10_000:
	.byte		N04   , Cn5 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
mus_rg_vs_deo_10_001:
	.byte		N04   , Cn5 , v064
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W32
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
mus_rg_vs_deo_10_B1:
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_000
	.byte	PATT
	 .word	mus_rg_vs_deo_10_001
	.byte	GOTO
	 .word	mus_rg_vs_deo_10_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_vs_deo:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_vs_deo_pri	@ Priority
	.byte	mus_rg_vs_deo_rev	@ Reverb.

	.word	mus_rg_vs_deo_grp

	.word	mus_rg_vs_deo_1
	.word	mus_rg_vs_deo_2
	.word	mus_rg_vs_deo_3
	.word	mus_rg_vs_deo_4
	.word	mus_rg_vs_deo_5
	.word	mus_rg_vs_deo_6
	.word	mus_rg_vs_deo_7
	.word	mus_rg_vs_deo_8
	.word	mus_rg_vs_deo_9
	.word	mus_rg_vs_deo_10

	.end
