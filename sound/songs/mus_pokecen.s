	.include "MPlayDef.s"

	.equ	mus_pokecen_grp, voicegroup_86810B0
	.equ	mus_pokecen_pri, 0
	.equ	mus_pokecen_rev, reverb_set+50
	.equ	mus_pokecen_mvl, 127
	.equ	mus_pokecen_key, 0
	.equ	mus_pokecen_tbs, 1
	.equ	mus_pokecen_exg, 0
	.equ	mus_pokecen_cmp, 1

	.section .rodata
	.global	mus_pokecen
	.align	2

@********************** Track  1 **********************@

mus_pokecen_1:
	.byte	KEYSH , mus_pokecen_key+0
	.byte	TEMPO , 104*mus_pokecen_tbs/2
	.byte		VOICE , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 29*mus_pokecen_mvl/mxv
	.byte	W96
mus_pokecen_1_B1:
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
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Cs3 , v100
	.byte	W12
	.byte		        En3 , v096
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	GOTO
	 .word	mus_pokecen_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_pokecen_2:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 73
	.byte		VOL   , 3*mus_pokecen_mvl/mxv
	.byte		LFOS  , 44
	.byte		MOD   , 1
	.byte		PAN   , c_v-7
	.byte		N72   , En3 , v120
	.byte	W03
	.byte		VOL   , 8*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        9*mus_pokecen_mvl/mxv
	.byte	W07
	.byte		        10*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        10*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        11*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        14*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        15*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        16*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        17*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        19*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        21*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        22*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        23*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        26*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        28*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        34*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        41*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        44*mus_pokecen_mvl/mxv
	.byte	W01
	.byte		        52*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        60*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        62*mus_pokecen_mvl/mxv
	.byte	W01
	.byte		        73*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        70*mus_pokecen_mvl/mxv
	.byte	W01
	.byte		        80*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        76*mus_pokecen_mvl/mxv
	.byte	W01
	.byte		        86*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        78*mus_pokecen_mvl/mxv
	.byte		N02   , Gs3 , v112
	.byte	W02
	.byte		        An3 
	.byte	W02
	.byte		N08   , Gs3 
	.byte	W09
	.byte		N06   , Fs3 
	.byte	W05
	.byte		        Gs3 
	.byte	W06
mus_pokecen_2_B1:
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		N03   , Ds4 , v072
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        En4 , v016
	.byte	W12
	.byte		        En4 , v108
	.byte	W12
	.byte		N02   , Dn4 , v112
	.byte	W02
	.byte		        En4 
	.byte	W02
	.byte		N08   , Dn4 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W05
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Gs3 , v092
	.byte	W06
	.byte		MOD   , 5
	.byte	W06
	.byte		        1
	.byte		N12   , Gs3 , v016
	.byte	W48
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte	W32
	.byte	W01
	.byte		N03   , Cn4 , v068
	.byte	W03
	.byte		N06   , Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v016
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Bn3 , v016
	.byte	W12
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W18
	.byte		        1
	.byte		N06   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W09
	.byte		N03   , As3 , v076
	.byte	W03
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W32
	.byte	W01
	.byte		N03   , Ds5 , v072
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W12
	.byte		        En5 , v016
	.byte	W12
	.byte		        Dn5 , v092
	.byte	W12
	.byte		        Dn5 , v016
	.byte	W12
	.byte		        Cs5 , v092
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W12
	.byte		N12   , Gs4 , v092
	.byte	W12
	.byte		MOD   , 1
	.byte		N12   , Gs4 , v016
	.byte	W48
	.byte		N02   , Bn4 , v112
	.byte	W02
	.byte		        Cs5 
	.byte	W02
	.byte		N08   , Bn4 
	.byte	W09
	.byte		N06   , As4 
	.byte	W05
	.byte		        Bn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W24
	.byte		N06   
	.byte	W09
	.byte		N03   , Cn5 , v068
	.byte	W03
	.byte		N06   , Cs5 , v112
	.byte	W12
	.byte		        Cs5 , v016
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W12
	.byte		        Bn4 , v016
	.byte	W12
	.byte		        Gs4 , v112
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		N03   , Gs3 , v064
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		MOD   , 1
	.byte		N24   , En4 , v088
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		N03   , Fn4 , v064
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 , v068
	.byte	W03
	.byte		        As4 , v076
	.byte	W03
	.byte		        Bn4 , v080
	.byte	W03
	.byte		        Cn5 , v092
	.byte	W03
	.byte		MOD   , 1
	.byte		VOL   , 69*mus_pokecen_mvl/mxv
	.byte		PAN   , c_v-2
	.byte		N48   , Cs5 , v112
	.byte	W36
	.byte		MOD   , 7
	.byte	W12
	.byte		        2
	.byte		N36   , En5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W18
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N02   , Cs5 
	.byte	W02
	.byte		        Dn5 
	.byte	W02
	.byte		N08   , Cs5 
	.byte	W09
	.byte		N06   , Bn4 
	.byte	W05
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N09   , Gs4 
	.byte	W09
	.byte		N03   , Cn5 
	.byte	W03
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N02   , En5 
	.byte	W02
	.byte		        Fs5 
	.byte	W02
	.byte		N08   , En5 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W05
	.byte		        Bn4 
	.byte	W06
	.byte		VOL   , 69*mus_pokecen_mvl/mxv
	.byte	W06
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		VOL   , 60*mus_pokecen_mvl/mxv
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		VOL   , 81*mus_pokecen_mvl/mxv
	.byte		N03   , Ds5 , v096
	.byte	W03
	.byte		N21   , En5 
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		        1
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		VOL   , 23*mus_pokecen_mvl/mxv
	.byte		N24   , An4 
	.byte	W03
	.byte		VOL   , 28*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        32*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        40*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        47*mus_pokecen_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        69*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        77*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte		N02   , Gs4 
	.byte	W02
	.byte		        An4 
	.byte	W02
	.byte		N08   , Gs4 
	.byte	W09
	.byte		N06   , Fs4 
	.byte	W05
	.byte		        Gs4 
	.byte	W06
	.byte	GOTO
	 .word	mus_pokecen_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_pokecen_3:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 45
	.byte		PAN   , c_v-32
	.byte		VOL   , 79*mus_pokecen_mvl/mxv
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		LFOS  , 44
	.byte	W96
mus_pokecen_3_B1:
	.byte		N06   , An3 , v092
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        Cs4 , v020
	.byte	W60
	.byte	W12
	.byte		        Dn4 , v112
	.byte	W12
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W30
	.byte		        Gs3 , v092
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W12
	.byte		        Gs3 , v016
	.byte	W60
	.byte		VOL   , 75*mus_pokecen_mvl/mxv
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		VOL   , 67*mus_pokecen_mvl/mxv
	.byte		N06   , An3 , v092
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        Gs3 , v092
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        An4 , v016
	.byte	W12
	.byte		        En5 , v100
	.byte	W12
	.byte		        En5 , v016
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Gs4 , v016
	.byte	W12
	.byte		        En4 , v112
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gs3 , v092
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        Gs4 , v016
	.byte	W12
	.byte		        Dn5 , v112
	.byte	W12
	.byte		        Dn5 , v016
	.byte	W12
	.byte		        Bn4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        An4 , v016
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_pokecen_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_pokecen_4:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		VOL   , 82*mus_pokecen_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W96
mus_pokecen_4_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N06   , Cs3 , v056
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Dn3 , v048
	.byte	W03
	.byte		N32   , Cs3 , v056
	.byte	W21
	.byte		VOL   , 78*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        70*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        62*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        60*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        82*mus_pokecen_mvl/mxv
	.byte		N12   , En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N36   , Dn3 
	.byte	W24
	.byte		VOL   , 78*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        70*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        62*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        60*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        82*mus_pokecen_mvl/mxv
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N02   , Gs2 
	.byte	W02
	.byte		        An2 
	.byte	W02
	.byte		N08   , Gs2 
	.byte	W09
	.byte		N06   , Gn2 
	.byte	W05
	.byte		        Gs2 
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N03   , Cn3 , v048
	.byte	W03
	.byte		N32   , Bn2 , v056
	.byte	W21
	.byte		VOL   , 78*mus_pokecen_mvl/mxv
	.byte	W02
	.byte		        70*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        62*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        60*mus_pokecen_mvl/mxv
	.byte	W04
	.byte		        82*mus_pokecen_mvl/mxv
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 , v060
	.byte	W12
	.byte		        Fs3 , v064
	.byte	W12
	.byte		        Gs3 , v068
	.byte	W12
	.byte		PAN   , c_v-44
	.byte		VOL   , 57*mus_pokecen_mvl/mxv
	.byte		N06   , Dn4 , v064
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOL   , 49*mus_pokecen_mvl/mxv
	.byte		N06   , Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Gs3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Fs3 , v064
	.byte	W06
	.byte		        Fs4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs4 , v096
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        En4 , v096
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        Dn3 , v064
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        Fn3 , v064
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Cs4 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		VOL   , 81*mus_pokecen_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	GOTO
	 .word	mus_pokecen_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_pokecen_5:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte		MOD   , 2
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		N03   , Cs5 , v068
	.byte	W06
	.byte		        Cs5 , v016
	.byte	W06
	.byte		        En5 , v068
	.byte	W06
	.byte		        En5 , v016
	.byte	W06
	.byte		        An4 , v068
	.byte	W06
	.byte		        An4 , v020
	.byte	W06
	.byte		        Gs4 , v068
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		        Fs4 , v068
	.byte	W06
	.byte		        Fs4 , v016
	.byte	W06
	.byte		        Gs4 , v068
	.byte	W06
	.byte		        Gs4 , v016
	.byte	W06
	.byte		        An4 , v068
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		        Bn4 , v068
	.byte	W06
	.byte		        Bn4 , v016
	.byte	W06
mus_pokecen_5_B1:
	.byte	W96
	.byte		VOICE , 4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 46*mus_pokecen_mvl/mxv
	.byte		N48   , En3 , v076
	.byte	W48
	.byte		N24   , An3 , v088
	.byte	W24
	.byte		N04   , Dn3 , v112
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        2
	.byte		N36   , En4 
	.byte	W24
	.byte		MOD   , 10
	.byte	W12
	.byte		        2
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N02   , Cs4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		N08   , Cs4 
	.byte	W09
	.byte		N06   , Bn3 
	.byte	W05
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N02   , En4 
	.byte	W02
	.byte		        Fs4 
	.byte	W02
	.byte		N08   , En4 
	.byte	W09
	.byte		N06   , Cs4 
	.byte	W05
	.byte		        Bn3 
	.byte	W06
	.byte		N48   , Cs4 
	.byte	W24
	.byte		MOD   , 11
	.byte	W24
	.byte		        2
	.byte		N48   , En4 
	.byte	W24
	.byte		MOD   , 11
	.byte	W24
	.byte		        2
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		N21   , Gs4 
	.byte	W09
	.byte		MOD   , 8
	.byte	W12
	.byte		        2
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		VOL   , 34*mus_pokecen_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        2
	.byte		N24   , Gs4 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        2
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        2
	.byte	W24
	.byte	GOTO
	 .word	mus_pokecen_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_pokecen_6:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 3
	.byte		PAN   , c_v-63
	.byte		VOL   , 69*mus_pokecen_mvl/mxv
	.byte		N03   , En4 , v096
	.byte	W06
	.byte		        En4 , v016
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		        An4 , v016
	.byte	W06
	.byte		        Cs4 , v064
	.byte	W06
	.byte		        Cs4 , v020
	.byte	W06
	.byte		        Bn3 , v064
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
	.byte		        An3 , v064
	.byte	W06
	.byte		        An3 , v016
	.byte	W06
	.byte		        Bn3 , v064
	.byte	W06
	.byte		        Bn3 , v016
	.byte	W06
	.byte		        Cs4 , v072
	.byte	W06
	.byte		        Cs4 , v016
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		        En4 , v016
	.byte	W06
mus_pokecen_6_B1:
	.byte		VOL   , 69*mus_pokecen_mvl/mxv
	.byte		N06   , An4 , v068
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		VOICE , 6
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N03   , Ds5 
	.byte	W03
	.byte		N06   , En5 
	.byte	W12
	.byte		        En5 , v016
	.byte	W12
	.byte		        En5 , v064
	.byte	W12
	.byte		N02   , Dn5 , v068
	.byte	W02
	.byte		        En5 
	.byte	W02
	.byte		N08   , Dn5 
	.byte	W09
	.byte		N06   , Cs5 
	.byte	W05
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v-63
	.byte	W03
	.byte		VOICE , 3
	.byte	W03
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Dn5 , v016
	.byte	W12
	.byte		        Bn4 , v068
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 6
	.byte		PAN   , c_v+63
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		VOICE , 3
	.byte		PAN   , c_v-63
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		VOICE , 6
	.byte		PAN   , c_v+63
	.byte	W03
	.byte		N03   , Cn5 
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Cs5 , v016
	.byte	W12
	.byte		        Bn4 , v068
	.byte	W12
	.byte		        Bn4 , v016
	.byte	W12
	.byte		        Gs4 , v068
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		VOICE , 3
	.byte		PAN   , c_v+0
	.byte		N24   , Cs5 
	.byte	W36
	.byte		VOL   , 57*mus_pokecen_mvl/mxv
	.byte	W21
	.byte		N03   , As4 , v096
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		VOL   , 44*mus_pokecen_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W09
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W12
	.byte		        En4 , v016
	.byte	W12
	.byte		        Dn4 , v096
	.byte	W12
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Cs4 , v096
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn4 , v016
	.byte	W12
	.byte		        Bn3 , v096
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W09
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W12
	.byte		        Cs4 , v016
	.byte	W12
	.byte		        Bn3 , v096
	.byte	W12
	.byte		        Bn3 , v016
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 , v096
	.byte	W12
	.byte		        Bn3 , v112
	.byte	W12
	.byte		N04   , Cs4 , v080
	.byte	W04
	.byte		        Dn4 , v084
	.byte	W04
	.byte		        En4 , v092
	.byte	W04
	.byte		        Fs4 , v096
	.byte	W04
	.byte		        Gs4 , v100
	.byte	W04
	.byte		        An4 , v108
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_pokecen_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_pokecen_7:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 5
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte	W96
mus_pokecen_7_B1:
mus_pokecen_7_000:
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		        En1 
	.byte	W18
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v036
	.byte	W18
	.byte		        An1 , v127
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte	PEND
mus_pokecen_7_001:
	.byte		N06   , Bn1 , v127
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W30
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		        En1 
	.byte	W18
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W18
	.byte		        En1 , v127
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PEND
	.byte		        Bn1 
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W30
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		        Gs1 
	.byte	W18
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W18
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		        An1 , v127
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W18
	.byte		        Cs2 , v127
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte	PATT
	 .word	mus_pokecen_7_000
	.byte	PATT
	 .word	mus_pokecen_7_001
	.byte		N06   , Bn1 , v127
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W30
	.byte		N03   , Bn1 , v127
	.byte	W06
	.byte		        Gs1 
	.byte	W18
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W18
	.byte		        Dn2 , v127
	.byte	W06
	.byte		        Dn2 , v036
	.byte	W06
	.byte		        An1 , v127
	.byte	W06
	.byte		        An1 , v036
	.byte	W30
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v036
	.byte	W18
	.byte		        En2 , v127
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		N24   , An1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , En1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cs2 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		N24   , Dn2 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Dn2 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , En2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Gn1 , v127
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		N24   , Gs1 , v127
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , En1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Bn1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        92*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gs1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        92*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , An1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N24   , An1 , v127
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , En1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cs2 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs2 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Bn1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Bn1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N24   , Gs1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gs1 , v036
	.byte	W09
	.byte		VOL   , 92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        92*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gs1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        92*mus_pokecen_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , An1 
	.byte	W06
	.byte		VOL   , 87*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        81*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        75*mus_pokecen_mvl/mxv
	.byte		N06   , An1 , v036
	.byte	W03
	.byte		VOL   , 68*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        63*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        57*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		        52*mus_pokecen_mvl/mxv
	.byte	W09
	.byte		        92*mus_pokecen_mvl/mxv
	.byte	W03
	.byte		N03   , An1 , v127
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Gs1 , v127
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte	GOTO
	 .word	mus_pokecen_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_pokecen_8:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 45
	.byte		VOL   , 75*mus_pokecen_mvl/mxv
	.byte	W96
mus_pokecen_8_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N06   , Gs3 , v112
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
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
	 .word	mus_pokecen_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_pokecen_9:
	.byte	KEYSH , mus_pokecen_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_pokecen_mvl/mxv
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v080
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v080
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v088
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		        Fn3 , v096
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
mus_pokecen_9_B1:
mus_pokecen_9_000:
	.byte		N01   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v084
	.byte	W12
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v080
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_pokecen_9_000
	.byte	PATT
	 .word	mus_pokecen_9_000
	.byte		N01   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_pokecen_9_000
	.byte		N01   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte	PATT
	 .word	mus_pokecen_9_000
	.byte		N01   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v084
	.byte	W12
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v088
	.byte	W04
	.byte		        Gn4 , v064
	.byte	W04
	.byte		N01   
	.byte	W04
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
mus_pokecen_9_001:
	.byte		N01   , Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_pokecen_9_001
	.byte	PATT
	 .word	mus_pokecen_9_001
	.byte	PATT
	 .word	mus_pokecen_9_001
	.byte	PATT
	 .word	mus_pokecen_9_001
	.byte	PATT
	 .word	mus_pokecen_9_001
	.byte		N12   , Gs4 , v112
	.byte	W36
	.byte		N01   , Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v088
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N01   , Gn4 , v084
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N01   , Gn4 , v080
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte	GOTO
	 .word	mus_pokecen_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_pokecen:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_pokecen_pri	@ Priority
	.byte	mus_pokecen_rev	@ Reverb.

	.word	mus_pokecen_grp

	.word	mus_pokecen_1
	.word	mus_pokecen_2
	.word	mus_pokecen_3
	.word	mus_pokecen_4
	.word	mus_pokecen_5
	.word	mus_pokecen_6
	.word	mus_pokecen_7
	.word	mus_pokecen_8
	.word	mus_pokecen_9

	.end
