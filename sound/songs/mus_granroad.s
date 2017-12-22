	.include "MPlayDef.s"

	.equ	mus_granroad_grp, voicegroup_8681CB0
	.equ	mus_granroad_pri, 0
	.equ	mus_granroad_rev, reverb_set+50
	.equ	mus_granroad_mvl, 127
	.equ	mus_granroad_key, 0
	.equ	mus_granroad_tbs, 1
	.equ	mus_granroad_exg, 0
	.equ	mus_granroad_cmp, 1

	.section .rodata
	.global	mus_granroad
	.align	2

@********************** Track  1 **********************@

mus_granroad_1:
	.byte	KEYSH , mus_granroad_key+0
	.byte	TEMPO , 136*mus_granroad_tbs/2
	.byte		VOICE , 58
	.byte		LFOS  , 44
	.byte		VOL   , 83*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 92*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_granroad_mvl/mxv
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_granroad_mvl/mxv
	.byte	W24
	.byte		N24   , En1 , v127
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		VOICE , 56
	.byte		PAN   , c_v+32
	.byte	W04
	.byte		N04   , Fs4 , v096
	.byte	W08
	.byte		PAN   , c_v+32
	.byte		N72   , An4 
	.byte	W03
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        75*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        65*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        69*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        72*mus_granroad_mvl/mxv
	.byte		MOD   , 10
	.byte	W02
	.byte		VOL   , 80*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        84*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        90*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        96*mus_granroad_mvl/mxv
	.byte	W12
	.byte		        94*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        91*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        86*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        83*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        78*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        74*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 69*mus_granroad_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		VOICE , 56
	.byte	W04
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W08
	.byte		N72   , An4 
	.byte	W03
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        75*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        65*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        69*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        72*mus_granroad_mvl/mxv
	.byte		MOD   , 10
	.byte	W02
	.byte		VOL   , 80*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        84*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        90*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        96*mus_granroad_mvl/mxv
	.byte	W12
	.byte		        94*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        91*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        86*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        83*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        78*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        74*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte	W96
	.byte	W96
mus_granroad_1_B1:
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v-63
	.byte		VOL   , 65*mus_granroad_mvl/mxv
	.byte		N04   , En3 , v092
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v076
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 , v032
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , En4 , v084
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		        Gs4 , v080
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gs4 , v032
	.byte	W04
	.byte		        An4 , v076
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Bn4 , v064
	.byte	W04
	.byte		        Bn4 , v032
	.byte	W04
	.byte		        An4 , v060
	.byte	W04
	.byte		PAN   , c_v+47
	.byte		N04   , An4 , v032
	.byte	W04
	.byte		        Gs4 , v064
	.byte	W04
	.byte		        Gs4 , v032
	.byte	W04
	.byte		PAN   , c_v+28
	.byte		N04   , Fs4 , v080
	.byte	W04
	.byte		        Fs4 , v032
	.byte	W04
	.byte		        En4 , v088
	.byte	W04
	.byte		PAN   , c_v+13
	.byte		N04   , En4 , v032
	.byte	W04
	.byte		        Dn4 , v092
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte		N04   , Cs4 , v084
	.byte	W04
	.byte		N20   , Cs4 , v032
	.byte	W92
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 9
	.byte		PAN   , c_v+0
	.byte		VOL   , 33*mus_granroad_mvl/mxv
	.byte		N48   , En5 , v112
	.byte	W24
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v+0
	.byte		N48   , An4 
	.byte	W24
	.byte		PAN   , c_v-61
	.byte	W24
	.byte		        c_v+0
	.byte		N48   , Dn5 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v+0
	.byte		N24   , An4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N48   , Dn5 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v+0
	.byte		N48   , En4 
	.byte	W24
	.byte		PAN   , c_v-61
	.byte	W24
	.byte		        c_v+0
	.byte		N48   , Cs5 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte	W24
	.byte		        c_v+0
	.byte		N24   , An4 
	.byte	W24
	.byte		VOL   , 33*mus_granroad_mvl/mxv
	.byte		N72   , Bn4 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		VOL   , 30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 20*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        19*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        17*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        16*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        15*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        14*mus_granroad_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte	W08
	.byte		        9*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        8*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        7*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        6*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        42*mus_granroad_mvl/mxv
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 46
	.byte		PAN   , c_v-63
	.byte		N04   , An3 , v060
	.byte	W04
	.byte		        Dn4 , v064
	.byte	W04
	.byte		        En4 , v080
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , En4 , v084
	.byte	W04
	.byte		        Bn4 , v088
	.byte	W04
	.byte		        Dn5 , v084
	.byte	W04
	.byte		PAN   , c_v+17
	.byte		N04   , An4 , v080
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Bn5 , v056
	.byte	W04
	.byte		        En5 , v068
	.byte	W04
	.byte		        Dn5 , v080
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An4 
	.byte	W04
	.byte		        En5 , v088
	.byte	W04
	.byte		        Dn5 , v092
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , An4 , v088
	.byte	W04
	.byte		        Dn5 , v092
	.byte	W04
	.byte		        Gs4 , v076
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , En4 , v080
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Dn4 , v072
	.byte	W04
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 56
	.byte		VOL   , 83*mus_granroad_mvl/mxv
	.byte		N08   , En3 , v112
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		N08   , En4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Gn4 
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W08
	.byte		        En4 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N72   , An4 
	.byte	W03
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        75*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        65*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        69*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        80*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        84*mus_granroad_mvl/mxv
	.byte	W03
	.byte		MOD   , 9
	.byte		VOL   , 90*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        96*mus_granroad_mvl/mxv
	.byte	W36
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_granroad_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_granroad_2:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		MOD   , 2
	.byte		PAN   , c_v+0
	.byte		VOL   , 89*mus_granroad_mvl/mxv
	.byte		N04   , Ds3 , v068
	.byte	W04
	.byte		        En3 , v072
	.byte	W04
	.byte		        Fs3 , v076
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 , v080
	.byte	W04
	.byte		        Gs3 , v084
	.byte	W04
	.byte		        Fs3 , v088
	.byte	W04
	.byte		        Gs3 , v092
	.byte	W04
	.byte		        An3 , v096
	.byte	W04
	.byte		        Gs3 , v100
	.byte	W04
	.byte		        An3 , v104
	.byte	W04
	.byte		        Bn3 , v108
	.byte	W04
	.byte		VOICE , 60
	.byte		N32   , Cs4 , v112
	.byte	W24
	.byte		MOD   , 9
	.byte	W08
	.byte		        2
	.byte		N04   , En3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N08   , En3 , v032
	.byte	W12
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		N08   , Cs4 , v032
	.byte	W08
mus_granroad_2_000:
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte	PEND
	.byte		N32   , Dn4 
	.byte	W24
	.byte		MOD   , 8
	.byte	W08
	.byte		N08   , Dn4 , v032
	.byte	W04
	.byte		MOD   , 2
	.byte	W04
	.byte		N04   , An3 , v112
	.byte	W08
	.byte		N48   
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte		N04   , Fn3 
	.byte	W04
	.byte		N08   , Fn3 , v032
	.byte	W12
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N04   , Gn3 
	.byte	W04
	.byte		N08   , Gn3 , v032
	.byte	W12
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N24   , Bn3 , v112
	.byte	W24
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Cs4 , v032
	.byte	W08
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N04   , Cs4 , v116
	.byte	W16
	.byte		N32   , En4 , v112
	.byte	W32
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Dn4 , v032
	.byte	W16
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N48   , An3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOICE , 60
	.byte		MOD   , 2
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		        Fn3 , v112
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		VOL   , 18*mus_granroad_mvl/mxv
	.byte		N88   , Bn3 , v072
	.byte	W02
	.byte		VOL   , 19*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W09
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        29*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 30*mus_granroad_mvl/mxv
	.byte	W05
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W09
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W20
	.byte		N04   , An3 
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		MOD   , 2
	.byte		N04   , Fs3 , v072
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , An3 , v072
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
mus_granroad_2_B1:
	.byte		VOL   , 22*mus_granroad_mvl/mxv
	.byte		N48   , An3 , v072
	.byte	W02
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        29*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N08   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		VOL   , 16*mus_granroad_mvl/mxv
	.byte		N64   , An3 
	.byte	W02
	.byte		VOL   , 17*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        19*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 30*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W23
	.byte		MOD   , 0
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Dn3 , v072
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W12
	.byte		        An3 , v072
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		VOL   , 19*mus_granroad_mvl/mxv
	.byte		N48   , Gs3 , v072
	.byte	W02
	.byte		VOL   , 22*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 29*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W10
	.byte		MOD   , 0
	.byte		N48   
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		VOL   , 18*mus_granroad_mvl/mxv
	.byte		N64   , An3 
	.byte	W02
	.byte		VOL   , 19*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 29*mus_granroad_mvl/mxv
	.byte	W08
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W24
	.byte	W02
	.byte		MOD   , 0
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        En3 , v072
	.byte	W04
	.byte		N08   , En3 , v032
	.byte	W12
	.byte		N04   , An3 , v072
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		VOL   , 21*mus_granroad_mvl/mxv
	.byte		N48   , Fs3 , v072
	.byte	W02
	.byte		VOL   , 23*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N08   , Bn2 , v032
	.byte	W08
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W36
	.byte		N48   , Gs3 , v088
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Bn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W08
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v080
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Fs3 , v084
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N08   , Dn3 , v084
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N48   , Gs3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N08   , An3 , v032
	.byte	W96
	.byte	W48
	.byte		N04   , Ds3 , v112
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		VOICE , 60
	.byte		VOL   , 46*mus_granroad_mvl/mxv
	.byte		N32   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N08   , Ds3 , v032
	.byte	W12
	.byte		N24   , Cn4 , v112
	.byte	W24
	.byte		N08   , Cn4 , v032
	.byte	W08
	.byte		N24   , Ds4 , v112
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N32   , Fn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N08   , Fn4 , v032
	.byte	W08
	.byte		N04   , Gs3 , v112
	.byte	W08
	.byte		N20   
	.byte	W20
	.byte		N04   , Gs3 , v032
	.byte	W04
	.byte		        Fn3 , v112
	.byte	W04
	.byte		N08   , Fn3 , v032
	.byte	W12
	.byte		N04   , Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		N24   , Fs3 , v112
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W04
	.byte		N08   , Cn3 , v032
	.byte	W12
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Cs3 , v032
	.byte	W04
	.byte		N48   , Ds3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		N08   , Ds3 , v032
	.byte	W12
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		N48   , Fs3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N04   , Gs3 
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		        As3 , v112
	.byte	W04
	.byte		        As3 , v032
	.byte	W04
	.byte		N32   , Cn4 , v112
	.byte	W32
	.byte		PAN   , c_v+29
	.byte		N32   , Cs4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		        0
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        En3 , v112
	.byte	W04
	.byte		N08   , En3 , v032
	.byte	W12
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		N08   , Cs4 , v032
	.byte	W08
	.byte	PATT
	 .word	mus_granroad_2_000
	.byte		N32   , Dn4 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W08
	.byte		N08   , Dn4 , v032
	.byte	W04
	.byte		MOD   , 0
	.byte	W04
	.byte		N04   , An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N48   , An3 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		PAN   , c_v+0
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N36   , Fn4 
	.byte	W36
	.byte		N04   , Fn4 , v032
	.byte	W04
	.byte		N02   , Gs3 , v112
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Fn4 
	.byte	W24
	.byte		N08   , Fn4 , v032
	.byte	W08
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		VOL   , 51*mus_granroad_mvl/mxv
	.byte		N04   , Fs3 
	.byte	W04
	.byte		N08   , Fs3 , v032
	.byte	W12
	.byte		N04   , Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		N48   , An3 , v112
	.byte	W48
	.byte		N08   , An3 , v032
	.byte	W24
	.byte		N04   , Fn3 , v112
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		        Fn3 , v112
	.byte	W04
	.byte		        Fn3 , v032
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        Gn3 , v112
	.byte	W04
	.byte		        Gn3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		VOL   , 16*mus_granroad_mvl/mxv
	.byte		N88   , Bn3 , v112
	.byte	W02
	.byte		VOL   , 17*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        29*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte	W40
	.byte		N04   , An3 , v088
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		        Fs3 , v088
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		        Gs3 , v112
	.byte	W04
	.byte		        Gs3 , v032
	.byte	W04
	.byte		        An3 , v088
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte	GOTO
	 .word	mus_granroad_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_granroad_3:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 58
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*mus_granroad_mvl/mxv
	.byte		LFOS  , 44
	.byte		MOD   , 2
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOL   , 30*mus_granroad_mvl/mxv
	.byte		N16   , Gn4 , v120
	.byte	W16
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		VOL   , 11*mus_granroad_mvl/mxv
	.byte		N64   , En4 , v124
	.byte	W05
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        14*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        16*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        29*mus_granroad_mvl/mxv
	.byte	W16
	.byte		MOD   , 9
	.byte	W16
	.byte		        2
	.byte		N04   , Dn4 , v120
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Cs4 , v120
	.byte	W04
	.byte		N08   , Cs4 , v032
	.byte	W12
	.byte		N04   , En4 , v120
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
mus_granroad_3_B1:
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte		N48   , Dn4 , v124
	.byte	W02
	.byte		VOL   , 14*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W12
	.byte		MOD   , 8
	.byte	W16
	.byte		        2
	.byte		N24   , An3 , v120
	.byte	W24
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte		N64   , Dn4 , v124
	.byte	W02
	.byte		VOL   , 13*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        15*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W11
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte		N04   , Cs4 , v120
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte		N48   , Cs4 , v124
	.byte	W02
	.byte		VOL   , 16*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        19*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		MOD   , 8
	.byte		VOL   , 29*mus_granroad_mvl/mxv
	.byte	W16
	.byte		MOD   , 2
	.byte		N16   , En4 , v120
	.byte	W16
	.byte		N08   , En4 , v032
	.byte	W08
	.byte		        An3 , v120
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		VOL   , 11*mus_granroad_mvl/mxv
	.byte		N64   , Cs4 , v124
	.byte	W02
	.byte		VOL   , 12*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        15*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        16*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        19*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        25*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W10
	.byte		MOD   , 9
	.byte	W16
	.byte		        2
	.byte		N04   , Bn3 , v120
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		        An3 , v120
	.byte	W04
	.byte		N08   , An3 , v032
	.byte	W12
	.byte		N04   , Cs4 , v120
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		VOL   , 11*mus_granroad_mvl/mxv
	.byte		N48   , Bn3 , v120
	.byte	W02
	.byte		VOL   , 15*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        19*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte		VOL   , 25*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W12
	.byte		MOD   , 2
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		VOL   , 34*mus_granroad_mvl/mxv
	.byte		N04   , Gs3 , v124
	.byte	W08
	.byte		        An3 , v127
	.byte	W04
	.byte		N08   , An3 , v032
	.byte	W12
	.byte		N04   , An3 , v120
	.byte	W04
	.byte		N08   , An3 , v032
	.byte	W12
	.byte		N04   , An3 , v120
	.byte	W04
	.byte		N08   , An3 , v032
	.byte	W12
	.byte		N04   , An3 , v127
	.byte	W04
	.byte		N08   , An3 , v032
	.byte	W04
	.byte		        Fs3 , v120
	.byte	W08
	.byte		N16   , Gs3 
	.byte	W16
	.byte		N04   , An3 
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		VOL   , 37*mus_granroad_mvl/mxv
	.byte		N72   , En4 , v120
	.byte	W44
	.byte		VOL   , 37*mus_granroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte		VOL   , 40*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        53*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        58*mus_granroad_mvl/mxv
	.byte	W04
	.byte		VOICE , 56
	.byte		VOL   , 96*mus_granroad_mvl/mxv
	.byte		MOD   , 2
	.byte		N08   
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        En4 , v032
	.byte	W56
	.byte		N04   , Dn4 , v120
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Cs4 , v120
	.byte	W04
	.byte		N08   , Cs4 , v032
	.byte	W12
	.byte		N04   , En4 , v120
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		N48   , Dn4 , v120
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte		N24   , An3 
	.byte	W24
	.byte		N08   , En3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Dn4 , v032
	.byte	W56
	.byte		N04   , Cs4 , v120
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v120
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 , v120
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N48   , Cs4 , v120
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v120
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N16   , Bn3 , v120
	.byte	W16
	.byte		N08   , Bn3 , v032
	.byte	W08
	.byte		N16   , An3 , v120
	.byte	W16
	.byte		        Bn3 
	.byte	W16
	.byte		        Cs4 
	.byte	W16
	.byte		N08   , Dn4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Fs4 
	.byte	W08
	.byte		N04   , Gs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		N32   , Bn4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W08
	.byte		        2
	.byte		N04   , As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		N04   , An4 
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		        An4 , v120
	.byte	W04
	.byte		N08   , An4 , v032
	.byte	W12
	.byte		N04   , An4 , v120
	.byte	W04
	.byte		N08   , An4 , v032
	.byte	W12
	.byte		N04   , An4 , v120
	.byte	W04
	.byte		N08   , An4 , v032
	.byte	W12
	.byte		N04   , An4 , v120
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		N08   , Fs4 , v120
	.byte	W08
	.byte		N16   , Gs4 
	.byte	W16
	.byte		N04   , An4 
	.byte	W04
	.byte		        An4 , v032
	.byte	W04
	.byte		N48   , Bn4 , v120
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        2
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte		N04   , Cs5 
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Cs5 , v120
	.byte	W04
	.byte		N08   , Cs5 , v032
	.byte	W12
	.byte		N04   , Cs5 , v120
	.byte	W04
	.byte		N08   , Cs5 , v032
	.byte	W12
	.byte		N04   , Cs5 , v120
	.byte	W04
	.byte		        Cs5 , v032
	.byte	W04
	.byte		        Dn5 , v120
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		        Dn5 , v120
	.byte	W04
	.byte		N08   , Dn5 , v032
	.byte	W12
	.byte		N04   , Dn5 , v120
	.byte	W04
	.byte		N08   , Dn5 , v032
	.byte	W12
	.byte		N04   , Dn5 , v120
	.byte	W04
	.byte		        Dn5 , v032
	.byte	W04
	.byte		N96   , En3 , v120
	.byte	W48
	.byte		MOD   , 10
	.byte	W48
	.byte		        2
	.byte	W96
	.byte	W96
	.byte		N04   , Cs4 , v112
	.byte	W16
	.byte		        Fn4 
	.byte	W08
	.byte		N72   , Gs4 
	.byte	W03
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        75*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        65*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        69*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        72*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        80*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        84*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        90*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        96*mus_granroad_mvl/mxv
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 58
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte	W48
	.byte		N04   , Bn3 
	.byte	W16
	.byte		        Dn4 
	.byte	W08
	.byte		TIE   , Gn4 
	.byte	W08
	.byte		VOL   , 46*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        26*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W08
	.byte		        17*mus_granroad_mvl/mxv
	.byte	W12
	.byte		        13*mus_granroad_mvl/mxv
	.byte	W16
	.byte		        15*mus_granroad_mvl/mxv
	.byte	W40
	.byte		        13*mus_granroad_mvl/mxv
	.byte	W12
	.byte		        15*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        17*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        18*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        21*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        22*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        44*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        52*mus_granroad_mvl/mxv
	.byte	W16
	.byte		EOT   
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		N08   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W08
	.byte	GOTO
	 .word	mus_granroad_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_granroad_4:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v-8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte		N04   , Fs2 , v068
	.byte	W04
	.byte		        Gs2 , v072
	.byte	W04
	.byte		        An2 , v076
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        An2 , v080
	.byte	W04
	.byte		        Bn2 , v084
	.byte	W04
	.byte		        An2 , v088
	.byte	W04
	.byte		        Bn2 , v092
	.byte	W04
	.byte		        Cs3 , v096
	.byte	W04
	.byte		        Bn2 , v100
	.byte	W04
	.byte		        Cs3 , v104
	.byte	W04
	.byte		        Dn3 , v108
	.byte	W04
	.byte		PAN   , c_v-25
	.byte		N32   , En3 , v100
	.byte	W32
	.byte		N04   , An2 , v096
	.byte	W04
	.byte		        An2 , v032
	.byte	W04
	.byte		        An2 , v096
	.byte	W04
	.byte		        An2 , v032
	.byte	W04
	.byte		        An2 , v096
	.byte	W04
	.byte		N08   , An2 , v032
	.byte	W12
	.byte		N24   , En3 , v096
	.byte	W24
	.byte		N08   , En3 , v032
	.byte	W08
	.byte		N24   , Gn3 , v096
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Cs4 , v100
	.byte	W08
	.byte		        An4 , v127
	.byte	W08
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte		N08   , Dn4 , v100
	.byte	W08
	.byte		N04   , Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N04   , Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cs4 , v080
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		VOL   , 72*mus_granroad_mvl/mxv
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		VOL   , 92*mus_granroad_mvl/mxv
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte		N04   , An2 , v092
	.byte	W04
	.byte		N08   , An2 , v032
	.byte	W12
	.byte		N04   , Dn3 , v104
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		N24   , Fn3 , v104
	.byte	W24
	.byte		N04   , Bn2 , v100
	.byte	W04
	.byte		N08   , Bn2 , v032
	.byte	W12
	.byte		N04   , Dn3 , v096
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		N24   , Gn3 , v096
	.byte	W24
	.byte		N08   , En3 
	.byte	W08
	.byte		N02   , An2 
	.byte	W08
	.byte		        An2 , v100
	.byte	W08
	.byte		        An2 , v096
	.byte	W16
	.byte		        An2 , v104
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , En3 , v112
	.byte	W24
	.byte		N08   , En3 , v032
	.byte	W08
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N04   , Cs3 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		        Cs4 , v127
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte		N08   , Dn5 , v112
	.byte	W08
	.byte		N04   , Cs5 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte		N08   , Dn5 , v112
	.byte	W08
	.byte		N04   , Cs5 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		VOL   , 77*mus_granroad_mvl/mxv
	.byte		N04   , Dn5 , v112
	.byte	W04
	.byte		        Cs5 , v080
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        An4 , v112
	.byte	W04
	.byte		        Gn4 , v104
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		VOL   , 86*mus_granroad_mvl/mxv
	.byte		N04   , En4 , v100
	.byte	W04
	.byte		        Dn4 , v096
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 , v092
	.byte	W04
	.byte		        Gn3 , v088
	.byte	W04
	.byte		VOL   , 48*mus_granroad_mvl/mxv
	.byte		N04   , An2 , v092
	.byte	W04
	.byte		        An2 , v032
	.byte	W04
	.byte		        An2 , v096
	.byte	W04
	.byte		        An2 , v032
	.byte	W04
	.byte		        Dn3 , v096
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		N24   , Fn3 , v100
	.byte	W24
	.byte		N04   , Bn2 , v096
	.byte	W04
	.byte		        Bn2 , v032
	.byte	W04
	.byte		        Bn2 , v096
	.byte	W04
	.byte		        Bn2 , v032
	.byte	W04
	.byte		        Dn3 , v088
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte		N88   , Gn3 , v072
	.byte	W02
	.byte		VOL   , 26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        29*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        42*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        44*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W48
	.byte	W02
	.byte		N08   , Gn3 , v032
	.byte	W32
mus_granroad_4_B1:
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte		N48   , Fs3 , v064
	.byte	W02
	.byte		VOL   , 26*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        32*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        36*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        39*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        41*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        45*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W10
	.byte		        28*mus_granroad_mvl/mxv
	.byte		N48   , Dn3 
	.byte	W02
	.byte		VOL   , 31*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        30*mus_granroad_mvl/mxv
	.byte		N64   , Fs3 
	.byte	W02
	.byte		VOL   , 32*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        36*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        39*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        41*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        42*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        44*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        45*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W32
	.byte		N08   , Fs3 , v032
	.byte	W32
	.byte		VOL   , 33*mus_granroad_mvl/mxv
	.byte		N48   , Cs3 , v064
	.byte	W02
	.byte		VOL   , 35*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        31*mus_granroad_mvl/mxv
	.byte		N48   , En3 , v072
	.byte	W02
	.byte		VOL   , 34*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        35*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W05
	.byte		        38*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        39*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        41*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W01
	.byte		        48*mus_granroad_mvl/mxv
	.byte	W09
	.byte		N68   
	.byte	W96
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N48   , Dn3 
	.byte	W02
	.byte		VOL   , 40*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        42*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        45*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W32
	.byte	W02
	.byte		N24   , An2 , v064
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		N08   , Fs2 , v032
	.byte	W08
	.byte		N04   , An2 , v072
	.byte	W04
	.byte		N08   , An2 , v032
	.byte	W12
	.byte		N04   , An2 , v072
	.byte	W04
	.byte		        An2 , v032
	.byte	W12
	.byte		        An2 , v080
	.byte	W04
	.byte		        An2 , v032
	.byte	W12
	.byte		        An2 , v084
	.byte	W04
	.byte		        An2 , v032
	.byte	W04
	.byte		N08   , Dn3 , v076
	.byte	W08
	.byte		N16   , En3 , v072
	.byte	W16
	.byte		N04   , Fs3 , v080
	.byte	W08
	.byte		VOL   , 39*mus_granroad_mvl/mxv
	.byte		N08   , Gs3 , v112
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		N08   , An3 
	.byte	W08
	.byte		N04   , Bn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N08   , Gs3 
	.byte	W08
	.byte		N04   , An3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , En3 
	.byte	W08
	.byte		N04   , Fs3 
	.byte	W08
	.byte		        Gs3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N08   , An3 , v112
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		        Fs3 , v112
	.byte	W04
	.byte		        Fs3 , v032
	.byte	W04
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Dn3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N08   , Dn4 , v112
	.byte	W08
	.byte		N04   , En4 
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		        Dn4 , v112
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N08   , Cs4 , v112
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		        Cs4 , v112
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W04
	.byte		        Cs4 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N08   , En3 , v112
	.byte	W08
	.byte		N04   , An3 
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		        Bn3 , v112
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		N08   , Cs4 , v112
	.byte	W08
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N08   , En4 , v112
	.byte	W08
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N04   , En3 
	.byte	W04
	.byte		        En3 , v032
	.byte	W04
	.byte		        An3 , v112
	.byte	W04
	.byte		        An3 , v032
	.byte	W04
	.byte		N16   , En3 , v112
	.byte	W16
	.byte		        Fs3 
	.byte	W16
	.byte		        Gs3 
	.byte	W16
	.byte		N08   , An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N32   , Fs4 
	.byte	W32
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		        Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        En4 
	.byte	W04
	.byte		N08   , En4 , v032
	.byte	W12
	.byte		N04   , En4 , v112
	.byte	W04
	.byte		N08   , En4 , v032
	.byte	W12
	.byte		N04   , En4 , v112
	.byte	W04
	.byte		N08   , En4 , v032
	.byte	W12
	.byte		N04   , En4 , v112
	.byte	W04
	.byte		        En4 , v032
	.byte	W04
	.byte		N08   , Bn3 , v112
	.byte	W08
	.byte		N16   , Cs4 
	.byte	W16
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Dn4 , v032
	.byte	W04
	.byte		N08   , Gs4 , v112
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        Gs4 
	.byte	W08
	.byte		        En4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N04   , As4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		VOL   , 47*mus_granroad_mvl/mxv
	.byte	W96
	.byte		N32   , Ds3 
	.byte	W32
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   , Ds3 
	.byte	W32
	.byte		        Fs3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N32   , Gs3 
	.byte	W40
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N20   
	.byte	W48
	.byte	W24
	.byte		N04   , Fn2 
	.byte	W16
	.byte		        Gs2 
	.byte	W08
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N04   , Gs2 
	.byte	W16
	.byte		        As2 
	.byte	W08
	.byte		N48   , Cn3 
	.byte	W48
	.byte		N04   
	.byte	W16
	.byte		        Cs3 
	.byte	W08
	.byte		N48   , Ds3 
	.byte	W48
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		N32   , Fs3 
	.byte	W08
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        An4 
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , An3 
	.byte	W16
	.byte		        An4 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Cs5 
	.byte	W08
	.byte		N04   , En4 
	.byte	W16
	.byte		        Cs5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		N08   , En5 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N04   , Fs4 , v080
	.byte	W08
	.byte		        Dn5 
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W16
	.byte		        Dn5 , v080
	.byte	W08
	.byte		N08   , Dn5 , v112
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W16
	.byte		        Dn5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N04   , Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N08   , En4 
	.byte	W08
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        Gn3 
	.byte	W08
	.byte		N08   , Gn4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N36   , Gs3 
	.byte	W40
	.byte		N02   , Cs3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Gs3 
	.byte	W32
	.byte		        Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N08   , Dn5 
	.byte	W08
	.byte		N04   , Cs5 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn5 , v112
	.byte	W08
	.byte		N04   , Cs5 , v080
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn5 , v112
	.byte	W04
	.byte		        Cs5 , v080
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        An4 , v112
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		VOL   , 25*mus_granroad_mvl/mxv
	.byte		N88   , Gn3 
	.byte	W02
	.byte		VOL   , 27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        36*mus_granroad_mvl/mxv
	.byte	W07
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W02
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W09
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        48*mus_granroad_mvl/mxv
	.byte	W06
	.byte		        51*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        53*mus_granroad_mvl/mxv
	.byte	W03
	.byte		        55*mus_granroad_mvl/mxv
	.byte	W64
	.byte	GOTO
	 .word	mus_granroad_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_granroad_5:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		MOD   , 2
	.byte		XCMD  , xIECV , 8
	.byte		PAN   , c_v-61
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N04   , Fs1 , v068
	.byte	W04
	.byte		        Gs1 , v040
	.byte	W04
	.byte		        An1 , v044
	.byte	W04
	.byte		        Gs1 , v048
	.byte	W04
	.byte		        An1 , v052
	.byte	W04
	.byte		        Bn1 , v056
	.byte	W04
	.byte		        An1 , v060
	.byte	W04
	.byte		        Bn1 , v064
	.byte	W04
	.byte		        Cs2 , v072
	.byte	W04
	.byte		        Bn1 , v076
	.byte	W04
	.byte		        Cs2 , v080
	.byte	W04
	.byte		        Dn2 , v084
	.byte	W04
	.byte		VOICE , 81
	.byte		N32   , Cs3 , v112
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte	W08
	.byte		N02   , An2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N32   , Cs3 
	.byte	W20
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte		N08   , En2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		N08   , An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		N04   , An2 
	.byte	W08
	.byte		N16   , En3 
	.byte	W16
	.byte		N24   , An3 
	.byte	W08
	.byte		MOD   , 12
	.byte	W16
	.byte		        0
	.byte		N08   , En3 
	.byte	W08
	.byte		N24   , An2 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N08   , Dn3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , Fn3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N02   , Gs3 , v104
	.byte	W02
	.byte		        Gn3 
	.byte	W02
	.byte		        Fs3 , v108
	.byte	W02
	.byte		        Fn3 
	.byte	W02
	.byte		        En3 
	.byte	W02
	.byte		        Ds3 
	.byte	W02
	.byte		        Dn3 , v104
	.byte	W02
	.byte		        Cs3 , v088
	.byte	W02
	.byte		MOD   , 2
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Gn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N04   , Gn2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		N02   , An2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Cs3 
	.byte	W08
	.byte		MOD   , 9
	.byte	W16
	.byte		N08   , Dn3 
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , En3 , v096
	.byte	W08
	.byte		N02   , An2 
	.byte	W08
	.byte		        An2 , v100
	.byte	W08
	.byte		        An2 , v096
	.byte	W16
	.byte		        An2 , v104
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   , An3 , v112
	.byte	W08
	.byte		MOD   , 11
	.byte	W16
	.byte		N08   , En3 
	.byte	W08
	.byte		MOD   , 0
	.byte		N24   , Fs3 
	.byte	W40
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N32   , Fs4 
	.byte	W08
	.byte		MOD   , 12
	.byte	W24
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		N32   , An2 
	.byte	W32
	.byte		N04   , Fs2 
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn2 
	.byte	W16
	.byte		        Gn2 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N04   , As2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		VOL   , 40*mus_granroad_mvl/mxv
	.byte		N08   , An2 , v084
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        An2 , v048
	.byte	W08
	.byte		        Cs3 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        Cs3 , v060
	.byte	W08
	.byte		        An2 , v064
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        Gs2 , v080
	.byte	W08
mus_granroad_5_B1:
	.byte		VOICE , 83
	.byte		VOL   , 40*mus_granroad_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N08   , Fs2 , v084
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fs2 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        An2 , v060
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        An2 , v068
	.byte	W08
	.byte		        Fs2 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 , v080
	.byte	W08
	.byte		        Fs2 , v084
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fs2 , v048
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		        Fs2 , v056
	.byte	W08
	.byte		        An2 , v060
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        An2 , v068
	.byte	W08
	.byte		        Fs2 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        An2 , v080
	.byte	W08
	.byte		        Gs2 , v084
	.byte	W08
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_granroad_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N04   , En3 , v048
	.byte	W04
	.byte		        En3 , v028
	.byte	W04
	.byte		        An3 , v048
	.byte	W04
	.byte		        An3 , v028
	.byte	W04
	.byte		        Cs4 , v048
	.byte	W04
	.byte		        Cs4 , v028
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v028
	.byte	W04
	.byte		        Gs4 , v048
	.byte	W04
	.byte		        Gs4 , v028
	.byte	W04
	.byte		        An4 , v048
	.byte	W04
	.byte		        An4 , v028
	.byte	W04
	.byte		        Bn4 , v048
	.byte	W04
	.byte		        Bn4 , v028
	.byte	W04
	.byte		        An4 , v048
	.byte	W04
	.byte		        An4 , v028
	.byte	W04
	.byte		        Gs4 , v048
	.byte	W04
	.byte		        Gs4 , v028
	.byte	W04
	.byte		        Fs4 , v048
	.byte	W04
	.byte		        Fs4 , v028
	.byte	W04
	.byte		        En4 , v048
	.byte	W04
	.byte		        En4 , v028
	.byte	W04
	.byte		        Dn4 , v048
	.byte	W04
	.byte		        Dn4 , v028
	.byte	W04
	.byte		VOICE , 83
	.byte		VOL   , 41*mus_granroad_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		BEND  , c_v+0
	.byte		N08   , Cs2 , v084
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs2 , v048
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		        Cs2 , v056
	.byte	W08
	.byte		        An2 , v060
	.byte	W08
	.byte		        Cs2 , v064
	.byte	W08
	.byte		        An2 , v068
	.byte	W08
	.byte		        Cs2 
	.byte	W08
	.byte		        An2 , v072
	.byte	W08
	.byte		        Gs2 , v076
	.byte	W08
	.byte		        Fs2 , v080
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En2 , v048
	.byte	W08
	.byte		        Bn2 , v052
	.byte	W08
	.byte		        En2 , v056
	.byte	W08
	.byte		        Bn2 , v060
	.byte	W08
	.byte		        En2 , v064
	.byte	W08
	.byte		        Bn2 , v068
	.byte	W08
	.byte		        En2 , v072
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        An2 , v076
	.byte	W08
	.byte		        Gs2 , v084
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Dn2 , v048
	.byte	W08
	.byte		        Bn2 , v052
	.byte	W08
	.byte		        Dn2 , v056
	.byte	W08
	.byte		        Bn2 , v060
	.byte	W08
	.byte		        Dn2 , v064
	.byte	W08
	.byte		        Bn2 , v068
	.byte	W08
	.byte		        Dn2 , v072
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 , v076
	.byte	W08
	.byte		        An2 , v080
	.byte	W08
	.byte		        En2 , v084
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        En2 , v048
	.byte	W08
	.byte		        Bn2 , v052
	.byte	W08
	.byte		        En2 , v056
	.byte	W08
	.byte		        Bn2 , v060
	.byte	W08
	.byte		        Gs2 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		VOL   , 21*mus_granroad_mvl/mxv
	.byte		MOD   , 4
	.byte		BEND  , c_v+1
	.byte		N48   , En6 , v112
	.byte	W48
	.byte		        An5 
	.byte	W48
	.byte		        Dn6 
	.byte	W48
	.byte		N24   , An5 
	.byte	W24
	.byte		        Bn5 
	.byte	W24
	.byte		N48   , Dn6 
	.byte	W48
	.byte		        En5 
	.byte	W48
	.byte		        Cs6 
	.byte	W48
	.byte		N24   , An5 
	.byte	W24
	.byte		        Bn5 
	.byte	W24
	.byte		VOICE , 81
	.byte		MOD   , 0
	.byte		PAN   , c_v-61
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N16   , An2 
	.byte	W16
	.byte		N02   , Gs2 
	.byte	W08
	.byte		N04   , An2 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		MOD   , 0
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N02   , Gn2 
	.byte	W08
	.byte		N04   , Gs2 
	.byte	W16
	.byte		N02   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Fn2 
	.byte	W16
	.byte		N04   , Fs2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N16   , En2 
	.byte	W16
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N02   , En2 
	.byte	W08
	.byte		N04   , Gs2 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , An2 
	.byte	W16
	.byte		N02   , Fn2 
	.byte	W08
	.byte		N04   , An2 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		N02   , Fs2 
	.byte	W08
	.byte		N04   , As2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		N02   , As2 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N02   , Gn2 
	.byte	W08
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		N02   , Ds3 
	.byte	W08
	.byte		VOICE , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 44*mus_granroad_mvl/mxv
	.byte		N04   , An3 , v064
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Gs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N32   , Cn3 , v112
	.byte	W32
	.byte		N02   , Ds2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W32
	.byte		N02   , As2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N04   , As2 
	.byte	W08
	.byte		N32   , Fn3 
	.byte	W40
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N20   
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N04   , Ds5 
	.byte	W08
	.byte		        Fn5 
	.byte	W08
	.byte		N08   , Fs5 
	.byte	W08
	.byte		N04   , An5 
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		        An5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An4 
	.byte	W16
	.byte		        An5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		        Gn5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		        Gn5 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		        Ds5 
	.byte	W08
	.byte		N72   , Dn5 
	.byte	W72
	.byte		VOICE , 81
	.byte		MOD   , 2
	.byte		PAN   , c_v-62
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N48   , Fs3 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		N36   , Fn3 
	.byte	W40
	.byte		N02   , Gs2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N24   , En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte	W96
	.byte		VOICE , 81
	.byte		VOL   , 40*mus_granroad_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N08   , Fs2 , v084
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Fs2 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        An2 , v060
	.byte	W08
	.byte		        Gs2 , v064
	.byte	W08
	.byte		        Bn2 , v068
	.byte	W08
	.byte		        Gs2 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		        En2 , v080
	.byte	W08
	.byte		        An2 , v084
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        An2 , v048
	.byte	W08
	.byte		        Cs3 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        Cs3 , v060
	.byte	W08
	.byte		        An2 , v064
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Cs3 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        Gs2 , v080
	.byte	W08
	.byte	GOTO
	 .word	mus_granroad_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_granroad_6:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N04   , Ds2 , v068
	.byte	W04
	.byte		        En2 , v040
	.byte	W04
	.byte		        Fs2 , v044
	.byte	W04
	.byte		        En2 , v048
	.byte	W04
	.byte		        Fs2 , v056
	.byte	W04
	.byte		        Gs2 
	.byte	W04
	.byte		        Fs2 , v060
	.byte	W04
	.byte		        Gs2 , v064
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Gs2 , v072
	.byte	W04
	.byte		        An2 , v080
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		N32   , An3 , v112
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte	W08
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N32   , An3 
	.byte	W20
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte		N08   , An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W08
	.byte		N04   , An2 
	.byte	W08
	.byte		N08   , Cs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		N16   , Bn3 
	.byte	W16
	.byte		N24   , Cs4 
	.byte	W08
	.byte		MOD   , 12
	.byte	W16
	.byte		        0
	.byte		N08   , An3 
	.byte	W08
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N08   , An3 
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N08   , Dn4 
	.byte	W08
	.byte		N04   , Cs4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N02   , Fs4 , v104
	.byte	W02
	.byte		        Fn4 
	.byte	W02
	.byte		        En4 , v108
	.byte	W02
	.byte		        Ds4 
	.byte	W02
	.byte		        Dn4 
	.byte	W02
	.byte		        Cs4 
	.byte	W02
	.byte		        Cn4 , v104
	.byte	W02
	.byte		        Bn3 , v084
	.byte	W02
	.byte		N24   , Dn4 , v112
	.byte	W24
	.byte		N08   , Fn4 
	.byte	W08
	.byte		N04   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N16   , An3 
	.byte	W16
	.byte		N04   , Bn3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N08   , An3 
	.byte	W08
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , An3 
	.byte	W08
	.byte		MOD   , 9
	.byte	W16
	.byte		N08   , Bn3 
	.byte	W08
	.byte		MOD   , 0
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N02   , En3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   , En4 
	.byte	W08
	.byte		MOD   , 11
	.byte	W16
	.byte		N08   , Cs4 
	.byte	W08
	.byte		MOD   , 0
	.byte		N24   , An3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N32   , Dn4 
	.byte	W08
	.byte		MOD   , 13
	.byte	W24
	.byte		        0
	.byte		N32   , Dn3 
	.byte	W32
	.byte		N04   , Bn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W16
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Gn3 
	.byte	W16
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N08   , Cs3 , v084
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 , v048
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        Cs3 , v056
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Cs3 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
mus_granroad_6_B1:
	.byte		VOICE , 80
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N08   , An2 , v084
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		        Dn3 , v056
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn3 , v060
	.byte	W08
	.byte		        An2 , v064
	.byte	W08
	.byte		        Dn3 , v068
	.byte	W08
	.byte		        An2 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        An2 , v084
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 , v048
	.byte	W08
	.byte		        Dn3 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        Dn3 , v060
	.byte	W08
	.byte		        An2 , v064
	.byte	W08
	.byte		        Dn3 , v068
	.byte	W08
	.byte		        An2 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Cs3 , v080
	.byte	W08
	.byte		        Bn2 , v084
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        An2 , v048
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        An2 , v056
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        An2 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Fs2 , v084
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        Fs2 , v048
	.byte	W08
	.byte		        Cs3 , v052
	.byte	W08
	.byte		        Fs2 , v056
	.byte	W08
	.byte		        Cs3 , v060
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        Cs3 , v068
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Cs3 , v072
	.byte	W08
	.byte		        Bn2 , v076
	.byte	W08
	.byte		        An2 , v080
	.byte	W08
	.byte		        Gs2 , v084
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gs2 , v048
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        Gs2 , v056
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Gs2 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Gs2 , v072
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Bn2 , v084
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Fs2 , v048
	.byte	W08
	.byte		        Dn3 , v052
	.byte	W08
	.byte		        Fs2 , v056
	.byte	W08
	.byte		        Dn3 , v060
	.byte	W08
	.byte		        Fs2 , v064
	.byte	W08
	.byte		        Dn3 , v068
	.byte	W08
	.byte		        Fs2 , v072
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Cs3 , v076
	.byte	W08
	.byte		        Dn3 , v080
	.byte	W08
	.byte		        Gs2 , v084
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Gs2 , v048
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        Gs2 , v056
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Bn2 , v064
	.byte	W08
	.byte		        Gs3 , v068
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		        Gs3 , v072
	.byte	W08
	.byte		        Fs3 , v076
	.byte	W08
	.byte		        En3 , v080
	.byte	W08
	.byte		VOICE , 87
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N72   , Dn4 , v120
	.byte	W08
	.byte		VOL   , 27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        34*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		MOD   , 8
	.byte	W04
	.byte		VOL   , 37*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        43*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        48*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        55*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        56*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        58*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        64*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N08   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		VOL   , 13*mus_granroad_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W04
	.byte		VOL   , 16*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        20*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        23*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        24*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        30*mus_granroad_mvl/mxv
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 34*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        39*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        46*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        49*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        55*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N72   , Dn4 
	.byte	W04
	.byte		VOL   , 25*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        28*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        31*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		MOD   , 8
	.byte	W04
	.byte		VOL   , 37*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        45*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        48*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        49*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        52*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        55*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        58*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        60*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        61*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        64*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte		N08   , En4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		VOL   , 24*mus_granroad_mvl/mxv
	.byte		N48   , Cs4 
	.byte	W04
	.byte		VOL   , 27*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        30*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        33*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        37*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        40*mus_granroad_mvl/mxv
	.byte		MOD   , 6
	.byte	W04
	.byte		VOL   , 45*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        48*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        51*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        57*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        61*mus_granroad_mvl/mxv
	.byte	W04
	.byte		        36*mus_granroad_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 80
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		VOL   , 32*mus_granroad_mvl/mxv
	.byte		N16   , Cs3 , v112
	.byte	W16
	.byte		N02   , Cn3 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N02   , As2 
	.byte	W08
	.byte		N04   , Bn2 
	.byte	W16
	.byte		N02   
	.byte	W16
	.byte		N16   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Gs2 
	.byte	W16
	.byte		N04   , An2 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N16   , Gs2 
	.byte	W16
	.byte		N08   , An2 
	.byte	W08
	.byte		N16   , Bn2 
	.byte	W16
	.byte		N02   , Gs2 
	.byte	W08
	.byte		N04   , Bn2 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , Cn3 
	.byte	W16
	.byte		N02   , An2 
	.byte	W08
	.byte		N04   , Cn3 
	.byte	W16
	.byte		N02   
	.byte	W08
	.byte		N16   , Cs3 
	.byte	W16
	.byte		N02   , As2 
	.byte	W08
	.byte		N04   , Cs3 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		N02   , Cs3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		N02   , Bn2 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		N02   , Fs3 
	.byte	W08
	.byte		VOICE , 85
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*mus_granroad_mvl/mxv
	.byte		N96   , En1 
	.byte	W24
	.byte		MOD   , 8
	.byte	W72
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		N32   , Gs3 
	.byte	W32
	.byte		N02   , Cn3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W32
	.byte		N02   , Ds3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N04   , Ds3 
	.byte	W08
	.byte		N32   , Cs4 
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N20   
	.byte	W48
	.byte		PAN   , c_v+0
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		PAN   , c_v+63
	.byte		N32   , En3 
	.byte	W32
	.byte		N02   , An2 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W16
	.byte		N24   , En3 
	.byte	W24
	.byte		N04   , Fs3 
	.byte	W08
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N32   , Fs3 
	.byte	W40
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N48   
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		N36   , Cs4 
	.byte	W40
	.byte		N02   , Fn3 
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N08   , Bn3 
	.byte	W08
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte	W96
	.byte		VOL   , 36*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N08   , An2 , v084
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        An2 , v052
	.byte	W08
	.byte		        Dn3 , v056
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		        Dn3 , v060
	.byte	W08
	.byte		        Bn2 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Bn2 , v072
	.byte	W08
	.byte		        En3 , v076
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte		        Cs3 , v084
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Cs3 , v048
	.byte	W08
	.byte		        En3 , v052
	.byte	W08
	.byte		        Cs3 , v056
	.byte	W08
	.byte		        En3 , v060
	.byte	W08
	.byte		        Cs3 , v064
	.byte	W08
	.byte		        En3 , v068
	.byte	W08
	.byte		        Cs3 
	.byte	W08
	.byte		        En3 , v072
	.byte	W08
	.byte		        Dn3 , v076
	.byte	W08
	.byte		        Bn2 , v080
	.byte	W08
	.byte	GOTO
	 .word	mus_granroad_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_granroad_7:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 0
	.byte		VOL   , 84*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*mus_granroad_mvl/mxv
	.byte	W48
	.byte		N24   , An2 , v092
	.byte	W24
	.byte		N04   , En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W20
	.byte		N04   , En1 , v127
	.byte	W08
	.byte		        En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
mus_granroad_7_000:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N04   
	.byte	W16
	.byte		        En1 , v127
	.byte	W08
	.byte		        En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W52
	.byte		N32   , An2 , v096
	.byte	W32
	.byte		N16   , An2 , v064
	.byte	W16
	.byte		N48   , An2 , v088
	.byte	W48
	.byte		N24   , An2 , v084
	.byte	W24
	.byte		N04   , En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W20
	.byte		N24   , An2 , v092
	.byte	W28
	.byte		N04   , En1 , v044
	.byte	W04
mus_granroad_7_001:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N16   , An2 , v084
	.byte	W16
	.byte		N40   , An2 , v096
	.byte	W40
	.byte		N04   , En1 , v112
	.byte	W08
	.byte	PEND
	.byte		N40   , An2 , v088
	.byte	W96
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N24   , An2 , v080
	.byte	W48
	.byte	W96
mus_granroad_7_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_granroad_7_002:
	.byte		N04   , En1 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v108
	.byte	W04
	.byte		        En1 , v084
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PATT
	 .word	mus_granroad_7_002
mus_granroad_7_003:
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W24
	.byte		        En1 , v084
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PEND
	.byte	PATT
	 .word	mus_granroad_7_002
	.byte	PATT
	 .word	mus_granroad_7_003
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v108
	.byte	W04
	.byte		        En1 , v084
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v108
	.byte	W04
	.byte		        En1 , v084
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En1 , v108
	.byte	W04
	.byte		        En1 , v084
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PATT
	 .word	mus_granroad_7_002
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N24   , An2 , v092
	.byte	W24
	.byte		N04   , En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W20
	.byte		N04   , En1 , v127
	.byte	W08
	.byte		        En1 , v088
	.byte	W04
	.byte		N08   , En1 , v044
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PATT
	 .word	mus_granroad_7_000
	.byte		N04   , En1 , v112
	.byte	W16
	.byte		        En1 , v127
	.byte	W08
	.byte		        En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W20
	.byte		N04   , En1 , v127
	.byte	W32
	.byte		N32   , An2 , v092
	.byte	W32
	.byte		N16   , An2 , v072
	.byte	W16
	.byte		N48   , An2 , v096
	.byte	W48
	.byte		N24   , An2 , v092
	.byte	W24
	.byte		N04   , En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W20
	.byte		        En1 , v044
	.byte	W04
	.byte		        En1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        En1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N32   , An2 , v064
	.byte	W32
	.byte		N16   , An2 , v096
	.byte	W16
	.byte		N32   , An2 , v064
	.byte	W32
	.byte		N16   , An2 , v096
	.byte	W16
	.byte		N24   , An2 , v112
	.byte	W24
	.byte		N04   , En1 , v088
	.byte	W04
	.byte		        En1 , v044
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N08   
	.byte	W20
	.byte		N28   , An2 , v092
	.byte	W28
	.byte		N04   , En1 , v044
	.byte	W04
	.byte	PATT
	 .word	mus_granroad_7_001
	.byte		N40   , An2 , v088
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_granroad_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_granroad_8:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 84
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 21
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte	W24
	.byte		N16   , En1 , v112
	.byte	W16
	.byte		N08   , Gs1 
	.byte	W08
mus_granroad_8_000:
	.byte		N24   , An1 , v112
	.byte	W64
	.byte		N32   
	.byte	W32
	.byte	PEND
mus_granroad_8_001:
	.byte		N24   , Gn1 , v112
	.byte	W64
	.byte		N32   
	.byte	W32
	.byte	PEND
	.byte		N24   , Fs1 
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		        Fn1 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        Fs1 
	.byte	W08
	.byte		N24   , Gn1 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		        Gs1 
	.byte	W08
	.byte	PATT
	 .word	mus_granroad_8_000
	.byte	PATT
	 .word	mus_granroad_8_001
	.byte		N24   , Fs1 , v112
	.byte	W64
	.byte		N32   
	.byte	W32
mus_granroad_8_002:
	.byte		N04   , Fn1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W32
	.byte		N08   
	.byte	W16
	.byte	PEND
mus_granroad_8_003:
	.byte		N08   , Dn2 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte	PEND
mus_granroad_8_B1:
	.byte		VOICE , 84
	.byte		VOL   , 60*mus_granroad_mvl/mxv
	.byte		N08   , Dn2 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N04   , Dn2 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , Bn1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Bn2 
	.byte	W16
	.byte		N04   , Bn1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N16   , Bn1 
	.byte	W16
	.byte		N08   , An1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , An2 
	.byte	W16
	.byte		N04   , An1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N16   , An1 
	.byte	W16
	.byte		N08   , Fs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs2 
	.byte	W16
	.byte		N04   , Fs1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W16
	.byte		N08   , En1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , En2 
	.byte	W16
	.byte		N04   , En1 
	.byte	W08
	.byte		N08   
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		        En1 
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N16   , En1 
	.byte	W16
	.byte		N08   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N16   , Dn2 
	.byte	W16
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , En2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W16
	.byte		N08   
	.byte	W24
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N12   , Dn2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Bn1 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Bn2 
	.byte	W08
	.byte		N08   , Bn1 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N08   , An1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        An2 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   , An2 
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fs2 
	.byte	W16
	.byte		        Fs1 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		N08   , Fs1 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , En1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En2 
	.byte	W16
	.byte		        En1 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        En2 
	.byte	W08
	.byte		N16   , En1 
	.byte	W16
	.byte	PATT
	 .word	mus_granroad_8_003
	.byte		N08   , En2 , v112
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , En3 
	.byte	W08
	.byte		N08   , En2 
	.byte	W16
	.byte		        Fn2 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Ds3 
	.byte	W08
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		        En3 
	.byte	W08
	.byte		        Fs2 
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Gn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        Gn2 
	.byte	W04
	.byte		        En1 
	.byte	W04
	.byte		N96   , Bn2 
	.byte	W96
	.byte		N24   , Gs1 
	.byte	W64
	.byte		N24   
	.byte	W24
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W64
	.byte		N24   
	.byte	W24
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N24   , Cs2 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N04   , Bn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W32
	.byte		        Cn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , Cn2 
	.byte	W24
	.byte		        Cs2 
	.byte	W64
	.byte		N24   
	.byte	W32
	.byte		        Gn1 
	.byte	W64
	.byte		N24   
	.byte	W24
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N24   
	.byte	W96
	.byte	PATT
	 .word	mus_granroad_8_002
	.byte	PATT
	 .word	mus_granroad_8_003
	.byte	GOTO
	 .word	mus_granroad_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_granroad_9:
	.byte	KEYSH , mus_granroad_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*mus_granroad_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W40
	.byte		N04   , En1 , v127
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		VOICE , 47
	.byte		N12   , An1 
	.byte	W32
	.byte		N04   , En2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N24   , An1 
	.byte	W32
mus_granroad_9_000:
	.byte		N16   , Gn1 , v127
	.byte	W32
	.byte		N08   , En2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N24   , Gn1 
	.byte	W32
	.byte	PEND
	.byte		N12   , Fs1 
	.byte	W40
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		        Fs1 
	.byte	W08
	.byte		N04   , An1 , v064
	.byte	W04
	.byte		        An1 , v072
	.byte	W04
	.byte		        An1 , v084
	.byte	W04
	.byte		        An1 , v092
	.byte	W04
	.byte		        An2 , v100
	.byte	W04
	.byte		        An2 , v127
	.byte	W04
	.byte		N16   , Fn2 
	.byte	W32
	.byte		N08   
	.byte	W08
	.byte		N04   , Cn3 , v112
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N16   , Gn2 , v127
	.byte	W32
	.byte		N16   
	.byte	W16
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N32   , An1 
	.byte	W32
	.byte	PATT
	 .word	mus_granroad_9_000
	.byte		N16   , Fs1 , v127
	.byte	W40
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N08   , Fs1 
	.byte	W08
	.byte		N04   , An1 , v064
	.byte	W04
	.byte		        An1 , v072
	.byte	W04
	.byte		        An1 , v084
	.byte	W04
	.byte		        An1 , v092
	.byte	W04
	.byte		        An2 , v127
	.byte	W04
	.byte		N04   
	.byte	W04
mus_granroad_9_001:
	.byte		N04   , Fn2 , v127
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N12   , An1 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Gn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Bn1 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte	PEND
	.byte		N64   , Dn1 , v064
	.byte	W96
mus_granroad_9_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N04   , En2 , v088
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   , An1 
	.byte	W48
mus_granroad_9_002:
	.byte	W24
	.byte		N16   , An2 , v088
	.byte	W48
	.byte		N16   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W08
	.byte		N24   , Bn1 
	.byte	W48
	.byte	PATT
	 .word	mus_granroad_9_002
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W08
	.byte		N16   , En2 , v127
	.byte	W16
	.byte		N24   , En1 
	.byte	W32
	.byte		N16   , Fn2 
	.byte	W16
	.byte		N24   , Fn1 
	.byte	W24
	.byte		        Fs1 
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte		N24   , Gn1 
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N96   , En2 
	.byte	W96
	.byte		N12   , Gs1 
	.byte	W32
	.byte		N04   , Ds2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , Gs1 
	.byte	W32
	.byte		N16   , Fs1 
	.byte	W32
	.byte		N08   , Ds2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N32   , Fs1 
	.byte	W32
	.byte		N12   , Cs2 
	.byte	W40
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N20   
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N12   , An1 
	.byte	W32
	.byte		N16   , En2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N32   , An1 
	.byte	W32
	.byte		N16   , Gn1 
	.byte	W32
	.byte		N04   , En2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , Gn1 
	.byte	W32
	.byte		N12   , Fs1 
	.byte	W40
	.byte		N08   , Fs2 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		        Fs1 
	.byte	W08
	.byte		N04   , An1 , v072
	.byte	W04
	.byte		        An1 , v080
	.byte	W04
	.byte		        An1 , v092
	.byte	W04
	.byte		        An1 , v104
	.byte	W04
	.byte		        An2 , v116
	.byte	W04
	.byte		        An2 , v127
	.byte	W04
	.byte		        Bn2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N04   , Cn3 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N24   , Cn2 
	.byte	W24
	.byte		N36   , Cs2 
	.byte	W40
	.byte		N04   , Gs2 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N32   , Cs2 
	.byte	W32
	.byte		N16   , Gn1 
	.byte	W32
	.byte		N08   , En2 
	.byte	W16
	.byte		N08   
	.byte	W16
	.byte		N32   , Gn1 
	.byte	W32
	.byte		N16   , Fs1 
	.byte	W40
	.byte		N04   , Fs2 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N32   , Fs1 
	.byte	W24
	.byte		N04   , An2 
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte	PATT
	 .word	mus_granroad_9_001
	.byte		N64   , Dn1 , v064
	.byte	W96
	.byte	GOTO
	 .word	mus_granroad_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_granroad:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_granroad_pri	@ Priority
	.byte	mus_granroad_rev	@ Reverb.

	.word	mus_granroad_grp

	.word	mus_granroad_1
	.word	mus_granroad_2
	.word	mus_granroad_3
	.word	mus_granroad_4
	.word	mus_granroad_5
	.word	mus_granroad_6
	.word	mus_granroad_7
	.word	mus_granroad_8
	.word	mus_granroad_9

	.end
