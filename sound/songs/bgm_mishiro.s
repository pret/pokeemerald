	.include "MPlayDef.s"

	.equ	bgm_mishiro_grp, voicegroup_8682CD0
	.equ	bgm_mishiro_pri, 0
	.equ	bgm_mishiro_rev, reverb_set+50
	.equ	bgm_mishiro_mvl, 127
	.equ	bgm_mishiro_key, 0
	.equ	bgm_mishiro_tbs, 1
	.equ	bgm_mishiro_exg, 0
	.equ	bgm_mishiro_cmp, 1

	.section .rodata
	.global	bgm_mishiro
	.align	2

@********************** Track  1 **********************@

bgm_mishiro_1:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte	TEMPO , 108*bgm_mishiro_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-16
	.byte		LFOS  , 44
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_1_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N03   , Bn3 , v096
	.byte	W03
	.byte		N32   , Cn4 , v108
	.byte	W21
	.byte		MOD   , 3
	.byte		VOL   , 36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , As3 , v104
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        As3 , v096
	.byte	W12
	.byte		        Cn4 , v108
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	W12
	.byte		N03   , Fn4 , v100
	.byte	W03
	.byte		N21   , En4 , v112
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 , v096
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        An3 , v096
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W12
	.byte		        En4 , v096
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		        Fn4 , v036
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v036
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        An4 , v036
	.byte	W12
	.byte		        Fn4 , v100
	.byte	W12
	.byte		        Cs4 , v092
	.byte	W12
	.byte		        An3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W03
	.byte		N21   , Fn4 
	.byte	W09
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N48   , As3 
	.byte	W24
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte		VOL   , 27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N48   , As3 
	.byte	W24
	.byte		VOL   , 36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 6
	.byte		VOL   , 27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N03   , En4 
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N72   , Gn3 
	.byte	W24
	.byte		VOL   , 36*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        26*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W07
	.byte		MOD   , 4
	.byte		VOL   , 24*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N36   , En3 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_mishiro_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_mishiro_2:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
bgm_mishiro_2_B1:
	.byte		VOICE , 73
	.byte		N03   , Gs4 , v112
	.byte	W03
	.byte		N32   , An4 
	.byte	W21
	.byte		MOD   , 6
	.byte		VOL   , 41*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn4 , v084
	.byte	W12
	.byte		N11   , An4 , v092
	.byte	W12
	.byte		        Gn4 , v088
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 , v092
	.byte	W12
	.byte		N36   , Cn5 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 41*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        30*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        23*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        An4 , v100
	.byte	W24
	.byte		        An4 , v096
	.byte	W12
	.byte		        Cs5 , v100
	.byte	W12
	.byte		        Dn5 , v112
	.byte	W12
	.byte		        Dn5 , v036
	.byte	W12
	.byte		N24   , En5 , v100
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N12   , Dn5 , v092
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   , Dn5 , v036
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , An4 , v100
	.byte	W12
	.byte		        Gn4 , v096
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		        En4 , v096
	.byte	W12
	.byte		        Fn4 , v100
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		N03   , Cs5 , v104
	.byte	W03
	.byte		N21   , Dn5 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N12   , Dn4 , v096
	.byte	W12
	.byte		        En4 , v104
	.byte	W12
	.byte		N48   , Fn4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , As4 , v100
	.byte	W06
	.byte		        As4 , v036
	.byte	W06
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		        An4 , v100
	.byte	W12
	.byte		N48   , Fn4 , v104
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N03   , Cs5 , v092
	.byte	W03
	.byte		N09   , Dn5 , v096
	.byte	W09
	.byte		N06   , An4 
	.byte	W06
	.byte		        An4 , v032
	.byte	W06
	.byte		N12   , An4 , v096
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W24
	.byte		VOL   , 42*bgm_mishiro_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        38*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W05
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        43*bgm_mishiro_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , En4 , v100
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N36   , En4 , v112
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn4 , v100
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 41*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn4 , v096
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   , Gs4 , v104
	.byte	W03
	.byte		N32   , An4 , v112
	.byte	W21
	.byte		MOD   , 3
	.byte		VOL   , 39*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W01
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        30*bgm_mishiro_mvl/mxv
	.byte	W01
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W01
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        Gn4 , v096
	.byte	W12
	.byte		        An4 , v108
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte	W12
	.byte		N03   , Cs5 , v100
	.byte	W03
	.byte		N21   , Cn5 , v112
	.byte	W09
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Dn5 , v096
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        Gn4 , v096
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        Cs5 , v096
	.byte	W12
	.byte		        Dn5 , v112
	.byte	W12
	.byte		        Dn5 , v036
	.byte	W12
	.byte		        En5 , v112
	.byte	W12
	.byte		        En5 , v036
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        Fn5 , v036
	.byte	W12
	.byte		        An4 , v100
	.byte	W12
	.byte		        Gn4 , v092
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N21   , Dn5 
	.byte	W09
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 31*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        26*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 6
	.byte		VOL   , 31*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        26*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N09   , Dn5 
	.byte	W09
	.byte		N06   , An4 
	.byte	W06
	.byte		        An4 , v032
	.byte	W06
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W24
	.byte		VOL   , 39*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        26*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        20*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_mishiro_mvl/mxv
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 46*bgm_mishiro_mvl/mxv
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 41*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        39*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        34*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 45*bgm_mishiro_mvl/mxv
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn4 , v032
	.byte	W12
	.byte		        Fn4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 42*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		N12   , Gn4 , v032
	.byte	W12
	.byte		VOL   , 45*bgm_mishiro_mvl/mxv
	.byte		N03   , En4 , v112
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N24   , En4 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W12
	.byte		VOICE , 48
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N48   , Cn5 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 42*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        40*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        39*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        37*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        30*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 25*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn5 , v032
	.byte	W12
	.byte		VOL   , 45*bgm_mishiro_mvl/mxv
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v032
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N48   , Gn5 
	.byte	W24
	.byte		VOL   , 42*bgm_mishiro_mvl/mxv
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 38*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 22*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn5 , v032
	.byte	W12
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		N09   , Fn5 
	.byte	W09
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        En5 , v032
	.byte	W06
	.byte		N24   , En5 , v112
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		VOICE , 73
	.byte		MOD   , 0
	.byte		VOL   , 47*bgm_mishiro_mvl/mxv
	.byte		N12   , As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	GOTO
	 .word	bgm_mishiro_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_mishiro_3:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 35
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		N24   , En1 , v112
	.byte	W24
bgm_mishiro_3_B1:
	.byte		N24   , Fn1 , v120
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , Fn1 , v108
	.byte	W06
	.byte		        Fn1 , v028
	.byte	W06
	.byte		        Cn2 , v088
	.byte	W06
	.byte		N05   , Cn2 , v028
	.byte	W06
	.byte		N17   , Fn1 , v100
	.byte	W18
	.byte		N05   , Fn1 , v028
	.byte	W06
	.byte		N06   , Gn1 , v100
	.byte	W06
	.byte		N05   , Gn1 , v028
	.byte	W06
	.byte		N24   , An1 , v120
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v120
	.byte	W24
	.byte		N06   , Gn1 , v112
	.byte	W12
	.byte		N24   , Dn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v120
	.byte	W18
	.byte		N06   , An1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Cn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		        An1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , Fn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As0 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N18   , As1 , v120
	.byte	W18
	.byte		N06   , As1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N24   , Gn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn1 , v028
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N18   , Gn1 , v120
	.byte	W18
	.byte		N06   , Gn1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N24   , Cn2 , v120
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v028
	.byte	W06
	.byte		N12   , Cn2 , v116
	.byte	W12
	.byte		        As1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , En1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , En1 , v028
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v028
	.byte	W06
	.byte		        Cn1 , v116
	.byte	W06
	.byte		        Cn1 , v028
	.byte	W06
	.byte		N12   , Cn2 , v104
	.byte	W12
	.byte		N06   , Cn3 , v084
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N24   , Fn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		        Fn1 , v028
	.byte	W06
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		N18   , Fn1 , v120
	.byte	W18
	.byte		N06   , Fn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , An1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v120
	.byte	W18
	.byte		N06   , An1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Dn1 , v124
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v120
	.byte	W24
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Cn1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		N24   , Fn1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , As0 , v112
	.byte	W06
	.byte		        As0 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N18   , As1 , v120
	.byte	W18
	.byte		N06   , As1 , v028
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v028
	.byte	W06
	.byte		N24   , Gn1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N18   , Gn1 , v120
	.byte	W18
	.byte		N06   , Gn1 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N24   , Cn2 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v028
	.byte	W06
	.byte		N12   , Cn2 , v120
	.byte	W12
	.byte		        As1 , v112
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , En1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , En1 , v028
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v028
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v028
	.byte	W06
	.byte		N12   , Cn2 , v120
	.byte	W12
	.byte		N06   , Cn3 , v088
	.byte	W06
	.byte		        Cn3 , v028
	.byte	W06
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N24   , Cn2 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , Cs2 , v120
	.byte	W18
	.byte		N06   , Cs2 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N24   , An1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Fn1 , v120
	.byte	W18
	.byte		N06   , Fn1 , v028
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		N24   , As1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , As1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v028
	.byte	W06
	.byte		N18   , Gn1 , v120
	.byte	W18
	.byte		N06   , Gn1 , v028
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		N24   , Cn2 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        As1 , v112
	.byte	W06
	.byte		        As1 , v028
	.byte	W06
	.byte		N18   , As1 , v120
	.byte	W18
	.byte		N06   , As1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , An1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , An1 , v028
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N18   , An1 , v120
	.byte	W18
	.byte		N06   , An1 , v028
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v028
	.byte	W06
	.byte		N24   , Fn1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn1 , v028
	.byte	W12
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Bn1 , v120
	.byte	W18
	.byte		N06   , Bn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , As1 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , As1 , v028
	.byte	W12
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v028
	.byte	W06
	.byte		N18   , Bn1 , v120
	.byte	W18
	.byte		N06   , Bn1 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte		N24   , Cn2 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		VOL   , 88*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        75*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        62*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        50*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn2 , v028
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v028
	.byte	W06
	.byte		        Cn2 , v112
	.byte	W06
	.byte		        Cn2 , v028
	.byte	W06
	.byte		N18   , Cn2 , v120
	.byte	W18
	.byte		N06   , Cn2 , v028
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v028
	.byte	W06
	.byte	GOTO
	 .word	bgm_mishiro_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_mishiro_4:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 45
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+32
	.byte		VOL   , 62*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_4_B1:
	.byte		VOICE , 45
	.byte	W24
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		N12   , Fn3 , v040
	.byte	W42
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		N11   , Fn3 , v040
	.byte	W18
	.byte	W24
	.byte		N06   , An3 , v112
	.byte	W06
	.byte		N12   , An3 , v040
	.byte	W42
	.byte		N06   , En3 , v112
	.byte	W06
	.byte		N12   , En3 , v040
	.byte	W06
	.byte		N06   , Cs3 , v112
	.byte	W06
	.byte		N12   , Cs3 , v040
	.byte	W06
	.byte	W24
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N12   , Dn4 , v040
	.byte	W42
	.byte		N06   , Cs4 , v112
	.byte	W06
	.byte		N12   , Cs4 , v040
	.byte	W18
	.byte	W24
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N12   , Cn4 , v040
	.byte	W42
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		N12   , Fn3 , v040
	.byte	W06
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N12   , Dn3 , v040
	.byte	W06
bgm_mishiro_4_000:
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N12   , As3 , v040
	.byte	W42
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		N12   , As3 , v040
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	bgm_mishiro_4_000
	.byte	W24
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N12   , Cn4 , v040
	.byte	W42
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		N12   , Cn4 , v040
	.byte	W18
	.byte	PATT
	 .word	bgm_mishiro_4_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOICE , 0
	.byte		VOL   , 50*bgm_mishiro_mvl/mxv
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_mishiro_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_mishiro_5:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 1
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 50*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_5_B1:
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
	.byte		N12   , An5 , v112
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N48   , Cn6 
	.byte	W48
	.byte		N12   , Cs6 
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Fn5 , v036
	.byte	W06
	.byte		N24   , Fn5 , v112
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v036
	.byte	W12
	.byte		        Fn5 , v112
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N48   , Gn5 
	.byte	W48
	.byte		N12   , Gn5 , v036
	.byte	W12
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		N09   , Fn5 
	.byte	W09
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        En5 , v036
	.byte	W06
	.byte		N24   , En5 , v112
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Gn5 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W12
	.byte		        As5 
	.byte	W12
	.byte		N48   , Cn6 
	.byte	W48
	.byte		N12   , Cn6 , v036
	.byte	W12
	.byte		        An5 , v112
	.byte	W12
	.byte		        Cs6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte		        Gn6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        En6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		        Dn6 
	.byte	W12
	.byte		        Dn6 , v032
	.byte	W12
	.byte		        Fn6 , v112
	.byte	W12
	.byte		        An6 
	.byte	W12
	.byte		N48   , Gn6 
	.byte	W48
	.byte		N12   , Gn6 , v036
	.byte	W12
	.byte		N03   , En6 , v112
	.byte	W03
	.byte		N09   , Fn6 
	.byte	W09
	.byte		N12   , Dn6 
	.byte	W12
	.byte		        Fn6 
	.byte	W12
	.byte		N06   , En6 
	.byte	W06
	.byte		        En6 , v032
	.byte	W06
	.byte		N24   , En6 , v112
	.byte	W24
	.byte		N12   , Fn6 
	.byte	W12
	.byte		N24   , Gn6 
	.byte	W24
	.byte		N12   , As5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte	GOTO
	 .word	bgm_mishiro_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_mishiro_6:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 45
	.byte		PAN   , c_v-8
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_6_B1:
	.byte		VOICE , 45
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v040
	.byte	W06
	.byte		N05   , Cn3 , v112
	.byte	W06
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		N05   , An3 , v112
	.byte	W06
	.byte		N06   , An3 , v040
	.byte	W06
	.byte		N05   , Cn3 , v112
	.byte	W06
	.byte		N06   , Cn3 , v040
	.byte	W06
	.byte		N05   , An2 , v112
	.byte	W06
	.byte		N06   , An2 , v040
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v040
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v040
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v040
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v040
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v040
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W60
	.byte		VOICE , 48
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_mishiro_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_mishiro_7:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn4 , v064
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
bgm_mishiro_7_B1:
	.byte		VOICE , 4
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , Gs4 , v064
	.byte	W03
	.byte		N32   , An4 
	.byte	W21
	.byte		MOD   , 6
	.byte		VOL   , 34*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        24*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        12*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N36   , Cn5 
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 32*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        15*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn5 , v024
	.byte	W12
	.byte		N24   , En5 , v064
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   , Dn5 , v024
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N21   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        32*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        16*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        15*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v024
	.byte	W06
	.byte		N12   , As4 , v064
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        30*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        27*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        18*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        16*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N09   , Dn5 
	.byte	W09
	.byte		N06   , An4 
	.byte	W06
	.byte		        An4 , v024
	.byte	W06
	.byte		N12   , An4 , v064
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        36*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        35*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        33*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        31*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        28*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        25*bgm_mishiro_mvl/mxv
	.byte	W06
	.byte		        23*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		        20*bgm_mishiro_mvl/mxv
	.byte	W05
	.byte		        19*bgm_mishiro_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N36   , En4 
	.byte	W24
	.byte		MOD   , 6
	.byte		VOL   , 35*bgm_mishiro_mvl/mxv
	.byte	W02
	.byte		        29*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        23*bgm_mishiro_mvl/mxv
	.byte	W03
	.byte		        22*bgm_mishiro_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_mishiro_mvl/mxv
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W48
	.byte		VOICE , 6
	.byte		PAN   , c_v-61
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
bgm_mishiro_7_000:
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte	PEND
	.byte		        As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Gn2 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte	PATT
	 .word	bgm_mishiro_7_000
	.byte		N06   , As2 , v112
	.byte	W06
	.byte		        As2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W06
	.byte		        Bn2 , v032
	.byte	W06
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W06
	.byte		        Cn3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte	GOTO
	 .word	bgm_mishiro_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_mishiro_8:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 5
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		LFOS  , 44
	.byte		VOL   , 50*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_8_B1:
	.byte		VOICE , 5
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        7
	.byte		VOL   , 44*bgm_mishiro_mvl/mxv
	.byte	W24
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v032
	.byte	W30
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte	W24
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W42
	.byte		        En3 , v112
	.byte	W06
	.byte		        En3 , v032
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W06
	.byte		        Cs3 , v032
	.byte	W06
	.byte	W24
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W42
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W42
	.byte		        Fn3 , v112
	.byte	W06
	.byte		        Fn3 , v032
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v032
	.byte	W06
bgm_mishiro_8_000:
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W42
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_mishiro_8_000
bgm_mishiro_8_001:
	.byte	W24
	.byte		N06   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W42
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	PEND
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W42
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W18
	.byte	W24
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W42
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W18
bgm_mishiro_8_002:
	.byte	W24
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W42
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W18
	.byte	PEND
	.byte	W24
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W42
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Gn3 , v032
	.byte	W18
	.byte	W24
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W42
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W18
	.byte	W24
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W42
	.byte		        An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W18
	.byte	PATT
	 .word	bgm_mishiro_8_002
	.byte	W24
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W42
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W18
	.byte	PATT
	 .word	bgm_mishiro_8_001
	.byte	GOTO
	 .word	bgm_mishiro_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_mishiro_9:
	.byte	KEYSH , bgm_mishiro_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 42*bgm_mishiro_mvl/mxv
	.byte	W12
	.byte	W24
bgm_mishiro_9_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_mishiro_9_000:
	.byte		N06   , Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte		        Fs2 , v084
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W12
	.byte		        Fs2 , v068
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	PATT
	 .word	bgm_mishiro_9_000
	.byte	GOTO
	 .word	bgm_mishiro_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_mishiro:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_mishiro_pri	@ Priority
	.byte	bgm_mishiro_rev	@ Reverb.

	.word	bgm_mishiro_grp

	.word	bgm_mishiro_1
	.word	bgm_mishiro_2
	.word	bgm_mishiro_3
	.word	bgm_mishiro_4
	.word	bgm_mishiro_5
	.word	bgm_mishiro_6
	.word	bgm_mishiro_7
	.word	bgm_mishiro_8
	.word	bgm_mishiro_9

	.end
