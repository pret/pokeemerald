	.include "MPlayDef.s"

	.equ	bgm_fune_kan_grp, voicegroup_867A744
	.equ	bgm_fune_kan_pri, 0
	.equ	bgm_fune_kan_rev, reverb_set+50
	.equ	bgm_fune_kan_mvl, 127
	.equ	bgm_fune_kan_key, 0
	.equ	bgm_fune_kan_tbs, 1
	.equ	bgm_fune_kan_exg, 0
	.equ	bgm_fune_kan_cmp, 1

	.section .rodata
	.global	bgm_fune_kan
	.align	2

@********************** Track  1 **********************@

bgm_fune_kan_1:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte	TEMPO , 120*bgm_fune_kan_tbs/2
	.byte		VOICE , 0
	.byte		LFOS  , 35
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N16   , Dn3 , v100
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte	TEMPO , 70*bgm_fune_kan_tbs/2
	.byte		N48   , An3 
	.byte	W32
	.byte	TEMPO , 120*bgm_fune_kan_tbs/2
	.byte	W16
	.byte		N16   , Dn3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte		        Gn4 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte	TEMPO , 70*bgm_fune_kan_tbs/2
	.byte		N32   , En4 
	.byte	W32
	.byte	TEMPO , 120*bgm_fune_kan_tbs/2
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		TIE   , Cs4 
	.byte	W96
	.byte	W24
	.byte		EOT   
	.byte	TEMPO , 90*bgm_fune_kan_tbs/2
	.byte		N24   , An3 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
bgm_fune_kan_1_B1:
bgm_fune_kan_1_000:
	.byte		N08   , Fs4 , v100
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte	PEND
bgm_fune_kan_1_001:
	.byte		N12   , Dn4 , v100
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte	PEND
	.byte		N24   , An4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte	PATT
	 .word	bgm_fune_kan_1_000
	.byte	PATT
	 .word	bgm_fune_kan_1_001
	.byte		N24   , An4 , v100
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , En4 
	.byte	W48
	.byte		VOICE , 56
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		        c_v-18
	.byte		N12   , Fs4 , v112
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , En4 , v088
	.byte	W12
	.byte		N09   , Fs4 , v100
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N12   , Fs4 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		        c_v-7
	.byte		N12   , Gn4 , v088
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   , Gn4 , v088
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		        c_v-12
	.byte		N12   , An4 , v112
	.byte	W04
	.byte		BEND  , c_v-7
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		N12   , En4 , v100
	.byte	W12
	.byte		        Cs4 , v084
	.byte	W12
	.byte		        Bn3 , v076
	.byte	W12
	.byte		        An3 , v088
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 , v100
	.byte	W12
	.byte		N15   , En4 , v112
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W03
	.byte		VOL   , 36*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N12   , Dn4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , Cs4 , v088
	.byte	W12
	.byte		N09   , Dn4 , v112
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		        c_v-7
	.byte		N12   , En4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , Dn4 
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   , En4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		        c_v-12
	.byte		N12   , Fs4 
	.byte	W04
	.byte		BEND  , c_v-7
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		N12   , Cs4 , v100
	.byte	W12
	.byte		        Bn3 , v084
	.byte	W12
	.byte		        An3 , v072
	.byte	W12
	.byte		        An3 , v088
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 , v100
	.byte	W12
	.byte		N15   , En4 , v112
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W03
	.byte		VOL   , 36*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-18
	.byte		N12   , Bn3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		N09   , Bn3 , v112
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		        c_v-7
	.byte		N12   , Cs4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , Bn3 
	.byte	W12
	.byte		BEND  , c_v-7
	.byte		N12   , Cs4 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		        c_v-12
	.byte		N12   , Dn4 
	.byte	W04
	.byte		BEND  , c_v-7
	.byte	W04
	.byte		        c_v+0
	.byte	W04
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		        Fs3 , v084
	.byte	W12
	.byte		        En3 , v072
	.byte	W12
	.byte		        Dn3 , v088
	.byte	W12
	.byte		        En3 , v092
	.byte	W12
	.byte		        Fs3 , v100
	.byte	W12
	.byte		N15   , An3 , v112
	.byte	W04
	.byte		VOL   , 68*bgm_fune_kan_mvl/mxv
	.byte	W04
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W01
	.byte		BEND  , c_v-12
	.byte	W03
	.byte		VOL   , 36*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v+12
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N12   , Bn3 
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W08
	.byte		N12   , An3 , v100
	.byte	W12
	.byte		N09   , Bn3 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs4 , v100
	.byte	W12
	.byte		        Dn4 , v104
	.byte	W12
	.byte		BEND  , c_v-5
	.byte		N12   , En4 , v108
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N09   , Fs4 , v112
	.byte	W12
	.byte		BEND  , c_v-7
	.byte		N09   , Gn4 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W06
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		BEND  , c_v-12
	.byte		N09   , An4 , v116
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N09   , Gn4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N12   , En4 
	.byte	W12
	.byte		N44   , Fs4 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 75*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        62*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        45*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        33*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        13*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        3*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-8
	.byte		N08   , Gn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W05
	.byte		N08   , En4 , v104
	.byte	W08
	.byte		        Cs4 , v100
	.byte	W08
	.byte		        An3 , v096
	.byte	W08
	.byte		        En3 , v092
	.byte	W08
	.byte		        Cs3 , v096
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W08
	.byte		        En3 , v100
	.byte	W08
	.byte		        Dn3 , v112
	.byte	W08
	.byte		BEND  , c_v-16
	.byte		N24   , Bn3 
	.byte	W03
	.byte		BEND  , c_v-5
	.byte	W03
	.byte		        c_v+0
	.byte	W09
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N44   , An3 
	.byte	W18
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 75*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        62*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        45*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        33*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        13*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        3*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-10
	.byte		N44   , Bn3 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 75*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        62*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        45*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        33*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        13*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        3*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        Cs4 , v096
	.byte	W08
	.byte		        Dn4 , v104
	.byte	W08
	.byte		        En4 , v112
	.byte	W08
	.byte		        Dn4 , v104
	.byte	W08
	.byte		        Cs4 , v092
	.byte	W08
	.byte		N21   , Dn4 , v112
	.byte	W06
	.byte		MOD   , 0
	.byte	W03
	.byte		        5
	.byte	W06
	.byte		VOL   , 65*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        47*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        17*bgm_fune_kan_mvl/mxv
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v-7
	.byte		N12   , En4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N12   , Dn4 , v096
	.byte	W12
	.byte		N21   , Cs4 , v112
	.byte	W09
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 65*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        46*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        17*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		BEND  , c_v-12
	.byte		N09   , Dn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , An3 
	.byte	W12
	.byte		BEND  , c_v-12
	.byte		N09   , Dn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		BEND  , c_v-8
	.byte		N12   , Gn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W15
	.byte		N12   , Fs4 
	.byte	W18
	.byte		        En4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        0
	.byte		BEND  , c_v-10
	.byte		N21   , Fs4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		MOD   , 5
	.byte	W05
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        49*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        29*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        10*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N08   
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		BEND  , c_v-8
	.byte		N24   , Fs4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		BEND  , c_v-12
	.byte		N08   , Bn4 
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W05
	.byte		N08   , Fs4 , v108
	.byte	W08
	.byte		        Dn4 , v104
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Dn4 , v100
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 , v104
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gn4 , v108
	.byte	W08
	.byte		N28   , An4 , v092
	.byte	W16
	.byte		MOD   , 5
	.byte	W05
	.byte		VOL   , 69*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        45*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        21*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        11*bgm_fune_kan_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte		N08   , En4 , v104
	.byte	W01
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte	W07
	.byte		BEND  , c_v-5
	.byte		N08   , Bn4 , v112
	.byte	W04
	.byte		BEND  , c_v+0
	.byte	W04
	.byte		N44   , An4 
	.byte	W16
	.byte		MOD   , 5
	.byte	W08
	.byte		VOL   , 75*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        62*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        45*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        33*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        13*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        3*bgm_fune_kan_mvl/mxv
	.byte	W02
	.byte		MOD   , 0
	.byte	W04
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Dn4 , v100
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_fune_kan_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_fune_kan_2:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v+8
	.byte		N48   , An2 , v092
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte		N16   , Dn4 
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		N48   , En3 
	.byte	W48
	.byte		        An2 
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte		N16   , Dn4 
	.byte	W16
	.byte		        En4 
	.byte	W16
	.byte		        Fs4 
	.byte	W16
	.byte		N32   , An3 
	.byte	W48
	.byte		PAN   , c_v-8
	.byte		N96   , An1 , v096
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte		N06   , An3 , v068
	.byte	W07
	.byte		        Dn4 , v044
	.byte	W07
	.byte		        Gn4 , v040
	.byte	W07
	.byte		        Cs5 , v048
	.byte	W07
	.byte		        En4 
	.byte	W08
	.byte		        An4 , v032
	.byte	W07
	.byte		        Dn5 , v040
	.byte	W07
	.byte		        Fs4 , v064
	.byte	W07
	.byte		        Bn4 , v048
	.byte	W07
	.byte		        En5 , v040
	.byte	W08
	.byte		        An4 , v068
	.byte	W07
	.byte		        Dn5 , v052
	.byte	W07
	.byte		        Gn5 , v032
	.byte	W07
	.byte		        Cs6 , v012
	.byte	W03
	.byte		VOICE , 0
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N48   , An3 , v092
	.byte	W48
	.byte		N24   , En4 
	.byte	W24
bgm_fune_kan_2_B1:
bgm_fune_kan_2_000:
	.byte		N36   , Dn4 , v092
	.byte	W48
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	PEND
bgm_fune_kan_2_001:
	.byte	W24
	.byte		N24   , An3 , v092
	.byte	W24
	.byte		N48   , Bn3 
	.byte	W48
	.byte	PEND
	.byte		        Dn4 
	.byte	W48
	.byte		N24   , Cs4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	W24
	.byte		N48   
	.byte	W48
	.byte		N24   , En4 
	.byte	W24
	.byte	PATT
	 .word	bgm_fune_kan_2_000
	.byte	PATT
	 .word	bgm_fune_kan_2_001
	.byte		N48   , Dn4 , v092
	.byte	W48
	.byte		        Cs4 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v-16
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N24   , En4 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , En3 
	.byte	W18
	.byte		        Fs3 
	.byte	W18
	.byte		        Gn3 
	.byte	W12
	.byte		N08   , Fs3 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Fs3 , v084
	.byte	W08
	.byte		        Dn3 , v080
	.byte	W08
	.byte		        Fs3 , v076
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs2 , v072
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v076
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		        Gn3 , v084
	.byte	W08
	.byte		N28   , An3 , v080
	.byte	W32
	.byte		N08   , Gn3 , v092
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N44   , En3 
	.byte	W48
	.byte	W24
	.byte		PAN   , c_v+8
	.byte		N48   , An3 
	.byte	W48
	.byte		N24   , En4 
	.byte	W24
	.byte	GOTO
	 .word	bgm_fune_kan_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_fune_kan_3:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N44   , Dn2 , v104
	.byte	W80
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W48
	.byte		N32   , Cs3 
	.byte	W32
	.byte		N16   , Cs2 
	.byte	W16
	.byte		N32   , Dn2 
	.byte	W32
	.byte		N08   , An1 
	.byte	W16
	.byte		N32   , Dn2 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N32   , Dn2 
	.byte	W32
	.byte		N08   , An1 
	.byte	W16
	.byte		N48   , Cs2 
	.byte	W48
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v064
	.byte	W09
	.byte		        Cs4 , v052
	.byte	W10
	.byte		        En4 , v036
	.byte	W09
	.byte		        Gn4 , v020
	.byte	W10
	.byte		        Bn4 , v032
	.byte	W10
	.byte		        An3 , v064
	.byte	W09
	.byte		        Cs4 , v048
	.byte	W10
	.byte		        En4 , v036
	.byte	W09
	.byte		        Gn4 , v020
	.byte	W10
	.byte		        Bn4 , v036
	.byte	W10
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		N06   , Bn3 , v064
	.byte	W07
	.byte		        En4 , v036
	.byte	W07
	.byte		        An4 
	.byte	W08
	.byte		        Cs4 , v068
	.byte	W07
	.byte		        Fs4 , v044
	.byte	W07
	.byte		        Bn4 , v032
	.byte	W07
	.byte		        En5 , v044
	.byte	W07
	.byte		        Gn4 , v060
	.byte	W08
	.byte		        Cs5 , v040
	.byte	W07
	.byte		        Fs5 , v048
	.byte	W07
	.byte		        Bn4 , v064
	.byte	W07
	.byte		        En5 , v044
	.byte	W07
	.byte		        An5 , v024
	.byte	W08
	.byte		VOICE , 35
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N44   , Dn1 , v120
	.byte	W48
	.byte		        An1 
	.byte	W48
bgm_fune_kan_3_B1:
	.byte		N44   , Bn1 , v120
	.byte	W48
	.byte		        An1 
	.byte	W48
bgm_fune_kan_3_000:
	.byte		N44   , Dn1 , v120
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte	PEND
bgm_fune_kan_3_001:
	.byte		N44   , An1 , v120
	.byte	W48
	.byte		N21   
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte	PEND
	.byte		N44   , Dn1 
	.byte	W48
	.byte		        An0 
	.byte	W48
	.byte		        Bn0 
	.byte	W48
	.byte		        Cs1 
	.byte	W48
	.byte	PATT
	 .word	bgm_fune_kan_3_000
	.byte	PATT
	 .word	bgm_fune_kan_3_001
	.byte		N10   , Bn1 , v120
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		N10   
	.byte	W24
	.byte		        Fs1 
	.byte	W24
	.byte		        An1 
	.byte	W24
	.byte		        Cs2 
	.byte	W24
	.byte		        Fs1 
	.byte	W24
	.byte		N44   , Gn1 
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte		N12   , Gn0 
	.byte	W12
	.byte		N36   , Dn1 
	.byte	W36
	.byte		N09   , An1 
	.byte	W12
	.byte		N44   , Dn1 
	.byte	W48
	.byte		N03   , En1 
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N36   , An1 
	.byte	W36
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Gn1 
	.byte	W06
	.byte		N36   , An1 
	.byte	W36
	.byte		N06   , An0 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        An1 
	.byte	W18
	.byte		N18   , An0 
	.byte	W18
	.byte		N12   , An1 
	.byte	W12
	.byte		        Bn1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An0 
	.byte	W06
	.byte		N12   , Gn1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 
	.byte	W18
	.byte		N18   , En2 
	.byte	W18
	.byte		N10   , En1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N06   , An0 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An0 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Dn1 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N03   , Dn1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Cs2 
	.byte	W06
	.byte		N06   , Cs1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        As1 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N09   , En1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   , An1 
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An0 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		        Cs1 
	.byte	W06
	.byte		VOICE , 35
	.byte		N44   , Dn1 
	.byte	W48
	.byte		        An1 
	.byte	W48
	.byte	GOTO
	 .word	bgm_fune_kan_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_fune_kan_4:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		LFOS  , 35
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v+0
	.byte	W04
	.byte		N12   , Bn3 , v060
	.byte	W10
	.byte		        Dn4 , v044
	.byte	W10
	.byte		        Fs4 , v028
	.byte	W09
	.byte		        An4 , v024
	.byte	W10
	.byte		        Cs5 , v040
	.byte	W09
	.byte		        Bn3 , v060
	.byte	W10
	.byte		        Dn4 , v040
	.byte	W10
	.byte		        Fs4 , v028
	.byte	W09
	.byte		        An4 
	.byte	W10
	.byte		        Cs5 , v040
	.byte	W05
	.byte		PAN   , c_v-16
	.byte	W04
	.byte		N06   , Cs4 , v052
	.byte	W08
	.byte		        Fs4 , v028
	.byte	W07
	.byte		        Bn4 , v044
	.byte	W07
	.byte		        Dn4 , v064
	.byte	W07
	.byte		        Gn4 , v036
	.byte	W07
	.byte		        Cs5 
	.byte	W08
	.byte		        En4 , v068
	.byte	W07
	.byte		        An4 , v056
	.byte	W07
	.byte		        Dn5 , v032
	.byte	W07
	.byte		        Gn5 , v056
	.byte	W07
	.byte		        Cs5 
	.byte	W08
	.byte		        Fs5 , v036
	.byte	W07
	.byte		        Bn5 , v020
	.byte	W05
	.byte	W96
bgm_fune_kan_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		N12   , Dn2 , v080
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs2 , v080
	.byte	W12
	.byte		        An2 , v064
	.byte	W12
	.byte		        Cs3 , v072
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn1 , v080
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An1 , v080
	.byte	W12
	.byte		        En2 , v072
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An1 , v080
	.byte	W12
	.byte		        Fs2 , v072
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn1 , v080
	.byte	W12
	.byte		        Gn2 , v072
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En2 , v080
	.byte	W12
	.byte		        An2 , v072
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v-22
	.byte		N08   , Bn3 , v044
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        Bn3 , v044
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        An3 , v044
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        An4 , v068
	.byte	W08
	.byte		        Cs5 , v072
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        An3 , v044
	.byte	W08
	.byte		        Cs4 , v056
	.byte	W08
	.byte		        En4 , v068
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        An4 , v056
	.byte	W08
	.byte		        Gn3 , v044
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Gn3 , v044
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Fs3 , v072
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Fs3 , v044
	.byte	W08
	.byte		        An3 , v056
	.byte	W08
	.byte		        Cs4 , v068
	.byte	W08
	.byte		        Cs5 , v072
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Fs4 , v056
	.byte	W08
	.byte		        Bn3 , v044
	.byte	W08
	.byte		        Gn4 , v056
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gn4 , v056
	.byte	W08
	.byte		N11   , Bn3 , v044
	.byte	W08
	.byte		N08   , Gn4 , v056
	.byte	W08
	.byte		        Bn4 , v068
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        Bn4 
	.byte	W08
	.byte		        Gn4 , v056
	.byte	W08
	.byte		        An3 , v044
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        An4 , v068
	.byte	W08
	.byte		        Dn5 , v072
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        An3 , v044
	.byte	W08
	.byte		        Dn4 , v056
	.byte	W08
	.byte		        Fs4 , v068
	.byte	W08
	.byte		        Fs5 , v072
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        An4 , v056
	.byte	W08
	.byte		        Gn3 , v044
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        Gn3 , v044
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        Gn4 , v068
	.byte	W08
	.byte		        Bn4 , v072
	.byte	W08
	.byte		        Gn4 
	.byte	W08
	.byte		        En4 , v056
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        An3 , v044
	.byte	W08
	.byte		        Cs4 , v056
	.byte	W08
	.byte		        En4 , v068
	.byte	W08
	.byte		        En5 , v072
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		        An4 , v056
	.byte	W08
	.byte	W96
	.byte	W96
	.byte		VOICE , 81
	.byte	W96
	.byte		PAN   , c_v-1
	.byte		BEND  , c_v-5
	.byte		N21   , An2 , v048
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W03
	.byte		N09   , Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N24   , En2 
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		MOD   , 0
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_fune_kan_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_fune_kan_5:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		LFOS  , 35
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_fune_kan_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 85
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v-49
	.byte		N24   , Cs3 , v032
	.byte	W24
	.byte		N48   , Dn3 , v040
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , En3 
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , Cs3 , v052
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		N06   , Fs3 , v040
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N42   , Gn3 
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N36   , Fs3 
	.byte	W36
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N03   , En3 
	.byte	W06
	.byte		N09   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W24
	.byte		N12   , Bn3 , v052
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , En4 , v060
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		VOICE , 85
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Fs3 , v052
	.byte	W18
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		N21   , En3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , Cs3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , Bn2 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W09
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , En3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , An3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , Bn3 , v060
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		N08   , Dn5 , v040
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N09   , An2 , v052
	.byte	W09
	.byte		        En3 
	.byte	W10
	.byte		        An3 
	.byte	W09
	.byte		        En4 
	.byte	W10
	.byte		        An4 
	.byte	W10
	.byte		VOICE , 85
	.byte		N24   , An2 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N18   , Dn3 
	.byte	W09
	.byte		VOL   , 52*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        36*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        15*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W18
	.byte		        Dn4 
	.byte	W18
	.byte		        Cs4 
	.byte	W12
	.byte		N17   , Fs3 
	.byte	W09
	.byte		VOL   , 52*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        36*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        15*bgm_fune_kan_mvl/mxv
	.byte	W01
	.byte		N08   , Dn3 
	.byte	W02
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		N08   , An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N24   , As3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , Cs4 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N21   , Fs4 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N21   , Gn4 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W18
	.byte		MOD   , 4
	.byte	W30
	.byte		        0
	.byte		N48   , Cs4 
	.byte	W06
	.byte		VOL   , 69*bgm_fune_kan_mvl/mxv
	.byte	W09
	.byte		        61*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 54*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        44*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        32*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        20*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte	GOTO
	 .word	bgm_fune_kan_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_fune_kan_6:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		LFOS  , 35
	.byte		XCMD  , xIECV , 8
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_fune_kan_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 86
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		N24   , An2 , v032
	.byte	W24
	.byte		N12   , An2 , v040
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		N12   , An2 
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		N12   , An2 , v052
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N06   , Dn3 , v040
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , Dn3 
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N09   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N09   
	.byte	W24
	.byte		N12   , Fs3 , v052
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		VOICE , 82
	.byte		N12   , An3 
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Cs4 , v060
	.byte	W12
	.byte		VOICE , 87
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Dn3 , v048
	.byte	W18
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N21   , Cs3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , An2 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , Fs2 , v052
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W09
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N06   , Dn3 , v048
	.byte	W12
	.byte		        Bn2 
	.byte	W06
	.byte		N24   , Cs3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , En3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		VOICE , 86
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Dn3 , v052
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		N12   , Gn3 , v060
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 84
	.byte		MOD   , 0
	.byte		BEND  , c_v+4
	.byte	W04
	.byte		N08   , Dn5 , v032
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		BEND  , c_v+0
	.byte		N09   , Cs3 , v040
	.byte	W10
	.byte		        Gn3 
	.byte	W10
	.byte		        Cs4 
	.byte	W09
	.byte		        Gn4 
	.byte	W10
	.byte		N04   , Cs5 
	.byte	W05
	.byte		VOICE , 86
	.byte		N24   , Fs2 , v052
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N18   , An2 
	.byte	W09
	.byte		VOL   , 52*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        36*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        15*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		N12   , As3 
	.byte	W18
	.byte		        An3 
	.byte	W18
	.byte		        Gn3 
	.byte	W12
	.byte		N17   , Dn3 
	.byte	W09
	.byte		VOL   , 52*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        36*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        15*bgm_fune_kan_mvl/mxv
	.byte	W01
	.byte		N08   , An2 
	.byte	W02
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		N08   , Fs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N24   , As3 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N21   , Dn4 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N21   , En4 
	.byte	W12
	.byte		VOL   , 71*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        54*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        30*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        8*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		        80*bgm_fune_kan_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 86
	.byte		N12   , An3 
	.byte	W12
	.byte		VOICE , 88
	.byte		N12   
	.byte	W06
	.byte		MOD   , 4
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 86
	.byte		MOD   , 0
	.byte		N12   
	.byte	W06
	.byte		VOL   , 69*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		VOICE , 88
	.byte		N12   
	.byte	W03
	.byte		VOL   , 61*bgm_fune_kan_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte	W06
	.byte		VOL   , 54*bgm_fune_kan_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 44*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		        32*bgm_fune_kan_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 20*bgm_fune_kan_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W96
	.byte	GOTO
	 .word	bgm_fune_kan_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_fune_kan_7:
	.byte	KEYSH , bgm_fune_kan_key+0
	.byte		VOICE , 1
	.byte		VOL   , 80*bgm_fune_kan_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_fune_kan_7_B1:
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
bgm_fune_kan_7_000:
	.byte	W24
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v020
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W30
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v020
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_fune_kan_7_000
	.byte		N06   , Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v020
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W78
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        Fs2 , v020
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v032
	.byte	W06
	.byte		        Fs2 , v016
	.byte	W06
	.byte		        Fs2 , v008
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		N03   , Fs2 , v052
	.byte	W03
	.byte		        Fs2 , v056
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W06
	.byte		        Fs2 , v044
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        Fs2 , v048
	.byte	W06
	.byte		        En1 , v127
	.byte	W06
	.byte		        Fs2 , v056
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v032
	.byte	W06
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        As1 , v060
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v032
	.byte	W06
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W06
	.byte		        Fs2 , v032
	.byte	W06
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        As1 , v060
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        En1 , v100
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        As1 , v060
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W12
	.byte		        As1 , v060
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W12
	.byte		        En1 , v127
	.byte	W12
	.byte		        Fs1 , v060
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En1 , v127
	.byte	W24
	.byte	W96
	.byte	GOTO
	 .word	bgm_fune_kan_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_fune_kan:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_fune_kan_pri	@ Priority
	.byte	bgm_fune_kan_rev	@ Reverb.

	.word	bgm_fune_kan_grp

	.word	bgm_fune_kan_1
	.word	bgm_fune_kan_2
	.word	bgm_fune_kan_3
	.word	bgm_fune_kan_4
	.word	bgm_fune_kan_5
	.word	bgm_fune_kan_6
	.word	bgm_fune_kan_7

	.end
