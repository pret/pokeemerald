	.include "MPlayDef.s"

	.equ	bgm_cycling_grp, voicegroup_86820D0
	.equ	bgm_cycling_pri, 0
	.equ	bgm_cycling_rev, reverb_set+50
	.equ	bgm_cycling_mvl, 127
	.equ	bgm_cycling_key, 0
	.equ	bgm_cycling_tbs, 1
	.equ	bgm_cycling_exg, 0
	.equ	bgm_cycling_cmp, 1

	.section .rodata
	.global	bgm_cycling
	.align	2

@********************** Track  1 **********************@

bgm_cycling_1:
	.byte	KEYSH , bgm_cycling_key+0
	.byte	TEMPO , 138*bgm_cycling_tbs/2
	.byte		VOICE , 47
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		LFOS  , 44
	.byte	W96
bgm_cycling_1_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 47
	.byte	W84
	.byte		N06   , An2 , v096
	.byte	W12
	.byte		N92   , Dn2 
	.byte	W24
	.byte		VOL   , 65*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        54*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        37*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        8*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        3*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        2*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		VOICE , 9
	.byte		PAN   , c_v-63
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		N48   , En5 , v064
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		N48   , Ds5 
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		VOICE , 47
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		N36   , Gn2 , v096
	.byte	W24
	.byte		VOL   , 65*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        68*bgm_cycling_mvl/mxv
	.byte		N06   , Bn1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W21
	.byte		VOL   , 67*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        68*bgm_cycling_mvl/mxv
	.byte		N48   , An2 
	.byte	W24
	.byte		VOL   , 67*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        62*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        68*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N92   , Cs2 
	.byte	W24
	.byte		VOL   , 67*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        64*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        59*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        40*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		VOICE , 9
	.byte		PAN   , c_v-63
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		N48   , Dn5 , v064
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		N48   , Cs5 
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		N72   , Cn5 
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W24
	.byte		VOICE , 46
	.byte		PAN   , c_v-32
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		VOICE , 35
	.byte		PAN   , c_v+0
	.byte		VOL   , 83*bgm_cycling_mvl/mxv
	.byte		N09   , Gn1 
	.byte	W09
	.byte		N06   , Gn1 , v036
	.byte	W24
	.byte	W03
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		N18   , Gn1 
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_cycling_1_000:
	.byte		N09   , Gn1 , v112
	.byte	W09
	.byte		N06   , Gn1 , v036
	.byte	W24
	.byte	W03
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		N21   , Gn1 
	.byte	W24
	.byte		N06   , En1 
	.byte	W12
	.byte	PEND
	.byte		N09   , Fs1 
	.byte	W09
	.byte		N06   , Fs1 , v036
	.byte	W24
	.byte	W03
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W24
	.byte		N06   , An1 
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W09
	.byte		N06   , Bn1 , v036
	.byte	W24
	.byte	W03
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W12
	.byte		N21   , Bn1 
	.byte	W24
	.byte		N06   , As1 
	.byte	W12
	.byte		N09   , Gn1 
	.byte	W09
	.byte		N06   , Gn1 , v036
	.byte	W24
	.byte	W03
	.byte		        Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		N18   , Gn1 
	.byte	W18
	.byte		N06   , Gn1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W12
	.byte	PATT
	 .word	bgm_cycling_1_000
	.byte		N09   , Fs1 , v112
	.byte	W09
	.byte		N06   , Fs1 , v036
	.byte	W24
	.byte	W03
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		        Cs1 , v112
	.byte	W06
	.byte		        Cs1 , v036
	.byte	W06
	.byte		N18   , Fs1 , v112
	.byte	W18
	.byte		N06   , Fs1 , v036
	.byte	W06
	.byte		        As1 , v112
	.byte	W12
	.byte		N09   , Bn1 
	.byte	W09
	.byte		N06   , Bn1 , v036
	.byte	W24
	.byte	W03
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W06
	.byte		        Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v036
	.byte	W06
	.byte		N21   , Bn1 , v112
	.byte	W24
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W06
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W12
	.byte		        Gs1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W12
	.byte		        Gs1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v096
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte	GOTO
	 .word	bgm_cycling_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_cycling_2:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		VOL   , 80*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		BENDR , 12
	.byte	W48
	.byte		N06   , Gn4 , v028
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 , v032
	.byte	W06
	.byte		        Bn4 , v040
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 , v044
	.byte	W06
	.byte		        En5 
	.byte	W06
bgm_cycling_2_B1:
	.byte		PAN   , c_v-16
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		VOICE , 48
	.byte		N06   , Fs4 , v096
	.byte	W06
	.byte		N03   , En4 , v084
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , Dn4 , v092
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Bn3 , v092
	.byte	W06
	.byte		        Bn3 , v032
	.byte	W06
	.byte		        An3 , v092
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W06
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte		N06   , En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W06
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W06
	.byte		N06   , En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W06
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N06   , En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		N06   , En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		N06   , An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W06
	.byte		N06   , En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W06
	.byte		N09   , En4 , v096
	.byte	W09
	.byte		N03   , Ds4 , v080
	.byte	W03
	.byte		N12   , Dn4 , v096
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        An3 , v032
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 1
	.byte		PAN   , c_v-32
	.byte		VOL   , 50*bgm_cycling_mvl/mxv
	.byte		N09   , Gn3 
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn3 , v112
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn3 , v112
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte		N09   , Cs4 , v112
	.byte	W12
	.byte		N03   , Cs4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Cs4 , v112
	.byte	W12
	.byte		N03   , Cs4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , An3 , v112
	.byte	W12
	.byte		N03   , Cs4 , v064
	.byte	W12
	.byte		N09   , An3 , v112
	.byte	W12
	.byte		N03   , An3 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , An3 , v112
	.byte	W12
	.byte		N03   , An3 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , An3 , v112
	.byte	W12
	.byte		N03   , An3 , v064
	.byte	W12
	.byte		N09   , An3 , v112
	.byte	W12
	.byte		N03   , An3 , v064
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N09   , Gs3 , v112
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N72   , Bn5 
	.byte	W24
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		        0
	.byte		N06   , Cs6 
	.byte	W12
	.byte		N04   , Bn5 
	.byte	W04
	.byte		        Cs6 
	.byte	W04
	.byte		        Bn5 
	.byte	W04
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W12
	.byte		        An5 
	.byte	W06
	.byte		        An5 , v040
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        An5 , v040
	.byte	W06
	.byte		        Fs5 , v112
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W09
	.byte		N03   , Bn5 
	.byte	W03
	.byte		N12   , Cn6 
	.byte	W12
	.byte		N06   , Bn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N04   , Gn5 
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Fs5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        An5 , v040
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        An5 , v040
	.byte	W06
	.byte		        An5 , v112
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Bn5 , v040
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Bn5 , v040
	.byte	W06
	.byte		        Cs6 , v112
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		N72   , An5 
	.byte	W60
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N09   , Gn5 
	.byte	W12
	.byte		N03   , An5 
	.byte	W12
	.byte		VOICE , 48
	.byte	W96
	.byte	GOTO
	 .word	bgm_cycling_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_cycling_3:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte	W84
	.byte		N12   , An1 , v108
	.byte	W12
bgm_cycling_3_B1:
	.byte		VOICE , 45
	.byte		PAN   , c_v+27
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W06
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W54
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		VOICE , 48
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOICE , 45
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W54
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Fs4 , v032
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte	W12
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W18
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		VOICE , 48
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N06   , Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 52*bgm_cycling_mvl/mxv
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 52*bgm_cycling_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N36   , Fs3 
	.byte	W24
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        53*bgm_cycling_mvl/mxv
	.byte		N09   , Dn3 
	.byte	W09
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N36   , An3 
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N72   , Gn3 , v108
	.byte	W24
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        52*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W09
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 42*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        40*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte		N12   , Fs3 , v104
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N48   , Bn3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 48*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        52*bgm_cycling_mvl/mxv
	.byte		MOD   , 0
	.byte		N44   , Bn2 , v108
	.byte	W24
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 45*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        42*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 52*bgm_cycling_mvl/mxv
	.byte		N06   , An2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N36   , Dn3 
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        40*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 39*bgm_cycling_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		N36   , Cs3 
	.byte	W24
	.byte		MOD   , 3
	.byte		VOL   , 49*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N36   , An2 
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		N12   , Fn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		TIE   , Fs3 
	.byte	W24
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		MOD   , 2
	.byte	W02
	.byte		VOL   , 48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        24*bgm_cycling_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        10*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        8*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        4*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		VOICE , 56
	.byte		PAN   , c_v+25
	.byte		VOL   , 63*bgm_cycling_mvl/mxv
	.byte		N09   , Dn4 
	.byte	W12
	.byte		N03   , Dn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Dn4 , v112
	.byte	W12
	.byte		N03   , Dn4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Bn3 , v112
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W12
	.byte		N09   , En4 
	.byte	W12
	.byte		N03   , En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , En4 , v112
	.byte	W12
	.byte		N03   , En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Cs4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N03   , Fs4 , v064
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N09   , Fn4 , v112
	.byte	W12
	.byte		N03   , En4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Cs4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N09   , Fs4 
	.byte	W12
	.byte		N03   , En4 , v064
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N09   , Fs4 , v112
	.byte	W12
	.byte		N03   , Fs4 , v064
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Dn4 , v112
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 66*bgm_cycling_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		MOD   , 1
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N12   , En4 
	.byte	W12
	.byte		N03   , Dn4 , v084
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOL   , 65*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        62*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        40*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_cycling_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W09
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 46
	.byte		PAN   , c_v-48
	.byte		N03   , Ds4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , An4 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		PAN   , c_v+36
	.byte		N03   , Fs5 
	.byte	W03
	.byte		PAN   , c_v+44
	.byte		N03   , An5 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte	W96
	.byte	W96
	.byte		VOICE , 45
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+30
	.byte	W12
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v032
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W18
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v032
	.byte	W06
	.byte	W12
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W18
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		VOICE , 48
	.byte		VOL   , 60*bgm_cycling_mvl/mxv
	.byte		N06   , Gn4 , v040
	.byte	W06
	.byte		        Fs4 , v044
	.byte	W06
	.byte		        Gn4 , v048
	.byte	W06
	.byte		        An4 , v052
	.byte	W06
	.byte		VOL   , 65*bgm_cycling_mvl/mxv
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 , v060
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	GOTO
	 .word	bgm_cycling_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_cycling_4:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 9
	.byte		        xIECL , 8
	.byte		PAN   , c_v+0
	.byte		VOL   , 41*bgm_cycling_mvl/mxv
	.byte		BENDR , 12
	.byte		N06   , Cs2 , v096
	.byte	W06
	.byte		        Bn1 , v080
	.byte	W06
	.byte		        Cs2 , v084
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        En2 , v088
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 , v092
	.byte	W06
	.byte		        An2 , v096
	.byte	W06
	.byte		PAN   , c_v-42
	.byte		VOL   , 29*bgm_cycling_mvl/mxv
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        An2 , v100
	.byte	W06
	.byte		        Bn2 , v104
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 , v108
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
bgm_cycling_4_B1:
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
bgm_cycling_4_000:
	.byte	W36
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		        7
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		        0
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	bgm_cycling_4_000
	.byte	W12
	.byte		MOD   , 0
	.byte	W60
	.byte		VOICE , 73
	.byte		PAN   , c_v-16
	.byte		VOL   , 79*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W09
	.byte		N03   , As4 , v092
	.byte	W03
	.byte		N48   , An4 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 74*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        68*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        65*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_cycling_mvl/mxv
	.byte		N12   , An4 , v032
	.byte	W12
	.byte		N06   , Fs4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W09
	.byte		N03   , Ds5 , v080
	.byte	W03
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W09
	.byte		N03   , Fn4 , v072
	.byte	W03
	.byte		N96   , En4 , v112
	.byte	W48
	.byte		MOD   , 5
	.byte		VOL   , 77*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        73*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        70*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        68*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        66*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        63*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        40*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte	W96
	.byte		VOL   , 79*bgm_cycling_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		        En4 , v032
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		N48   , Gn4 , v112
	.byte	W24
	.byte		MOD   , 5
	.byte		VOL   , 77*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        73*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        69*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        61*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        52*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 79*bgm_cycling_mvl/mxv
	.byte		N12   , Gn4 , v032
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , Ds5 , v064
	.byte	W03
	.byte		        Dn5 , v068
	.byte	W03
	.byte		N09   , Cs5 , v104
	.byte	W09
	.byte		N03   , Cn5 , v080
	.byte	W03
	.byte		N12   , Bn4 , v112
	.byte	W12
	.byte		N06   , Cs5 , v100
	.byte	W12
	.byte		        En5 , v108
	.byte	W12
	.byte		TIE   , Fs5 , v112
	.byte	W48
	.byte		MOD   , 3
	.byte		VOL   , 69*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        66*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        63*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        62*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        10*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 7*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        3*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W24
	.byte		VOL   , 72*bgm_cycling_mvl/mxv
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
	.byte		VOICE , 48
	.byte		N06   , Cs2 , v060
	.byte	W06
	.byte		        Bn1 , v064
	.byte	W06
	.byte		        Cs2 , v068
	.byte	W06
	.byte		        Dn2 , v072
	.byte	W06
	.byte		        En2 , v076
	.byte	W06
	.byte		        Fs2 , v080
	.byte	W06
	.byte		        Gn2 , v084
	.byte	W06
	.byte		        An2 , v088
	.byte	W06
	.byte		        Bn2 , v092
	.byte	W06
	.byte		        An2 , v096
	.byte	W06
	.byte		        Bn2 , v100
	.byte	W06
	.byte		        Cs3 , v104
	.byte	W06
	.byte		        Dn3 , v108
	.byte	W06
	.byte		        En3 , v112
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	GOTO
	 .word	bgm_cycling_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_cycling_5:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*bgm_cycling_mvl/mxv
	.byte		N06   , An2 , v096
	.byte	W06
	.byte		        Gn2 , v080
	.byte	W06
	.byte		        An2 , v084
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cs3 , v088
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 , v092
	.byte	W06
	.byte		        Fs3 , v096
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Fs3 , v100
	.byte	W06
	.byte		        Gn3 , v104
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 , v108
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
bgm_cycling_5_B1:
	.byte		PAN   , c_v+0
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		N06   , Fs4 , v112
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W12
	.byte		N48   , An4 , v112
	.byte	W24
	.byte		VOL   , 60*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        54*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		MOD   , 3
	.byte	W02
	.byte		VOL   , 41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 41*bgm_cycling_mvl/mxv
	.byte		N12   , An4 , v032
	.byte	W02
	.byte		VOL   , 36*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		VOICE , 48
	.byte	W03
	.byte		VOL   , 68*bgm_cycling_mvl/mxv
	.byte		N06   , Fs4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 , v104
	.byte	W06
	.byte		N03   , Bn4 , v096
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N06   , An4 , v100
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		N96   , En4 , v112
	.byte	W48
	.byte		VOL   , 62*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        42*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        37*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte		VOL   , 29*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 17*bgm_cycling_mvl/mxv
	.byte	W48
	.byte		        68*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N06   , Fs4 , v104
	.byte	W06
	.byte		N03   , Gn4 , v096
	.byte	W03
	.byte		        Gs4 , v100
	.byte	W03
	.byte		N12   , An4 , v104
	.byte	W12
	.byte		N06   , Gn4 , v108
	.byte	W06
	.byte		        Fs4 , v100
	.byte	W06
	.byte		        En4 , v112
	.byte	W12
	.byte		        En4 , v032
	.byte	W12
	.byte		        Fs4 , v112
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		N48   , Gn4 , v112
	.byte	W24
	.byte	W03
	.byte		VOL   , 62*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        61*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte		VOL   , 60*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        54*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte		N12   , Gn4 , v032
	.byte	W02
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        68*bgm_cycling_mvl/mxv
	.byte		N06   , En4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N09   , Cs5 , v092
	.byte	W09
	.byte		N03   , Cn5 , v076
	.byte	W03
	.byte		N12   , Bn4 , v096
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N96   , An4 , v112
	.byte	W48
	.byte		VOL   , 62*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        60*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        42*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        37*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte		VOL   , 29*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , An4 , v032
	.byte	W96
	.byte		PAN   , c_v-23
	.byte		VOL   , 45*bgm_cycling_mvl/mxv
	.byte		N03   , Dn4 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N72   , An5 
	.byte	W24
	.byte	W24
	.byte		VOL   , 48*bgm_cycling_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        37*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 51*bgm_cycling_mvl/mxv
	.byte		N04   , Gn5 , v108
	.byte	W04
	.byte		        An5 
	.byte	W04
	.byte		        Gn5 , v104
	.byte	W04
	.byte		        Fs5 , v100
	.byte	W04
	.byte		        Gn5 , v096
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        En5 , v092
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        En5 , v088
	.byte	W04
	.byte		        Dn5 , v084
	.byte	W04
	.byte		        En5 , v080
	.byte	W04
	.byte		        Dn5 , v076
	.byte	W04
	.byte		N06   , Cs5 , v112
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N24   , En5 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		        Fs5 
	.byte	W08
	.byte		        En5 
	.byte	W08
	.byte		N48   , Dn5 
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		        0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N72   , Bn4 
	.byte	W24
	.byte	W36
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Cs5 
	.byte	W12
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W09
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		N06   , Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N72   , An4 
	.byte	W48
	.byte		MOD   , 3
	.byte	W24
	.byte		        0
	.byte		N09   , Gn4 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N06   , An2 , v064
	.byte	W06
	.byte		        Gn2 , v072
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 , v076
	.byte	W06
	.byte		        Cs3 , v080
	.byte	W06
	.byte		        Dn3 , v084
	.byte	W06
	.byte		        En3 , v088
	.byte	W06
	.byte		        Fs3 , v092
	.byte	W06
	.byte		        Gn3 , v096
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 , v100
	.byte	W06
	.byte		        An3 , v104
	.byte	W06
	.byte		        Bn3 , v108
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	GOTO
	 .word	bgm_cycling_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_cycling_6:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 4
	.byte		        xIECL , 4
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W96
bgm_cycling_6_B1:
	.byte		VOICE , 81
	.byte		PAN   , c_v-61
	.byte		VOL   , 17*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , Fs2 , v112
	.byte	W05
	.byte		VOL   , 18*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        21*bgm_cycling_mvl/mxv
	.byte		N24   , Dn3 , v104
	.byte	W05
	.byte		VOL   , 22*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        28*bgm_cycling_mvl/mxv
	.byte		N12   , An2 , v100
	.byte	W05
	.byte		VOL   , 31*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		VOICE , 84
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N03   , Fs3 , v092
	.byte	W12
	.byte		VOL   , 38*bgm_cycling_mvl/mxv
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W12
	.byte		VOICE , 81
	.byte		N24   , Dn3 , v100
	.byte	W12
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N24   , Cs3 , v096
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 39*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W12
	.byte		VOL   , 39*bgm_cycling_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        40*bgm_cycling_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        23*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W02
	.byte		VOL   , 17*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        40*bgm_cycling_mvl/mxv
	.byte		N06   , Dn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N03   , Fs3 , v112
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		VOICE , 81
	.byte		N06   , An2 , v092
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		N12   , Cs3 , v088
	.byte	W12
	.byte		VOL   , 38*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , An2 , v096
	.byte	W09
	.byte		VOICE , 84
	.byte	W03
	.byte		N06   , Bn4 , v080
	.byte	W06
	.byte		        An4 , v084
	.byte	W06
	.byte		N04   , Bn4 , v092
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        En5 , v096
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N06   , An5 
	.byte	W06
	.byte		        An5 , v032
	.byte	W06
	.byte		VOICE , 81
	.byte		N24   , En3 , v112
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		VOICE , 84
	.byte		VOL   , 38*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , Fs3 , v096
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		VOL   , 39*bgm_cycling_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        40*bgm_cycling_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        40*bgm_cycling_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		VOICE , 81
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , An2 , v112
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		N06   , Bn2 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , Cs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 28*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W84
	.byte		N12   , An2 , v064
	.byte	W12
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N92   , Dn2 
	.byte	W48
	.byte		VOL   , 32*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W96
	.byte		N36   , Gn2 
	.byte	W09
	.byte		VOL   , 33*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        18*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        34*bgm_cycling_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte		VOL   , 33*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        18*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        34*bgm_cycling_mvl/mxv
	.byte		N60   , An2 
	.byte	W24
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        18*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W10
	.byte		        34*bgm_cycling_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N92   , Cs2 
	.byte	W48
	.byte		VOL   , 32*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        16*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        6*bgm_cycling_mvl/mxv
	.byte	W96
	.byte		VOICE , 84
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W72
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N24   , Bn5 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        1
	.byte		N24   , Cs6 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Dn6 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N72   , An6 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N04   , Gn6 , v108
	.byte	W04
	.byte		        An6 
	.byte	W04
	.byte		        Gn6 , v104
	.byte	W04
	.byte		        Fs6 , v100
	.byte	W04
	.byte		        Gn6 , v096
	.byte	W04
	.byte		        Fs6 
	.byte	W04
	.byte		        En6 , v092
	.byte	W04
	.byte		        Fs6 
	.byte	W04
	.byte		        En6 , v088
	.byte	W04
	.byte		        Dn6 , v084
	.byte	W04
	.byte		        En6 , v080
	.byte	W04
	.byte		        Dn6 , v076
	.byte	W04
	.byte		N06   , Cs6 , v112
	.byte	W12
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		N24   , En6 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N08   
	.byte	W08
	.byte		        Fs6 
	.byte	W08
	.byte		        En6 
	.byte	W08
	.byte		N48   , Dn6 
	.byte	W24
	.byte		MOD   , 10
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		VOL   , 19*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N72   , Gn3 
	.byte	W02
	.byte		VOL   , 21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N12   , An3 , v080
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		VOL   , 20*bgm_cycling_mvl/mxv
	.byte		N72   , Cs4 
	.byte	W02
	.byte		VOL   , 21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W10
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		VOL   , 20*bgm_cycling_mvl/mxv
	.byte		N72   , An3 
	.byte	W02
	.byte		VOL   , 21*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W01
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W09
	.byte		MOD   , 9
	.byte	W24
	.byte		        1
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		VOL   , 27*bgm_cycling_mvl/mxv
	.byte		N48   , Ds4 
	.byte	W02
	.byte		VOL   , 30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N96   , Dn4 
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_cycling_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_cycling_7:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 4
	.byte		        xIECL , 4
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W96
bgm_cycling_7_B1:
	.byte		VOICE , 87
	.byte		PAN   , c_v+63
	.byte		VOL   , 14*bgm_cycling_mvl/mxv
	.byte		N06   , Fs3 , v092
	.byte	W05
	.byte		VOL   , 17*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        18*bgm_cycling_mvl/mxv
	.byte		N24   , An3 , v096
	.byte	W05
	.byte		VOL   , 21*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W05
	.byte		        27*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        30*bgm_cycling_mvl/mxv
	.byte		N12   , Fs3 , v100
	.byte	W05
	.byte		VOL   , 31*bgm_cycling_mvl/mxv
	.byte	W07
	.byte		        34*bgm_cycling_mvl/mxv
	.byte		N03   , Dn4 , v076
	.byte	W09
	.byte		VOICE , 80
	.byte	W03
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N06   , Fs5 , v080
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 , v088
	.byte	W06
	.byte		        An5 , v032
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 , v088
	.byte	W06
	.byte		        An5 , v032
	.byte	W06
	.byte		VOICE , 87
	.byte		N24   , An3 , v100
	.byte	W12
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		N24   , Gn3 , v096
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        41*bgm_cycling_mvl/mxv
	.byte		N06   , Dn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Bn3 , v096
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 87
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N03   , An3 , v112
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , En3 , v092
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N12   , An3 , v088
	.byte	W12
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N03   , En3 , v096
	.byte	W12
	.byte		VOICE , 80
	.byte		N06   , Bn4 , v080
	.byte	W06
	.byte		        An4 , v084
	.byte	W06
	.byte		N04   , Bn4 , v092
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        En5 , v096
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N06   , An5 
	.byte	W06
	.byte		        An5 , v032
	.byte	W06
	.byte		VOICE , 87
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		VOICE , 80
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N12   , Fs3 , v096
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        23*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        20*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        9*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        5*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        41*bgm_cycling_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        An3 , v096
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		VOICE , 87
	.byte		VOL   , 34*bgm_cycling_mvl/mxv
	.byte		N36   , Fs3 , v112
	.byte	W15
	.byte		MOD   , 6
	.byte	W21
	.byte		N06   , Fn3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		VOL   , 56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W84
	.byte		N12   , An2 , v064
	.byte	W12
	.byte		N92   , Dn1 
	.byte	W48
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        35*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        33*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N24   , En6 
	.byte	W24
	.byte		        En6 , v032
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N24   , Ds6 , v044
	.byte	W24
	.byte		        Ds6 , v024
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N36   , Gn1 , v064
	.byte	W12
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        26*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W12
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        44*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		N60   , An1 
	.byte	W24
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        50*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        42*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        24*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        13*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        11*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		N12   , Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		N92   , Cs1 
	.byte	W48
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        38*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        32*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        31*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        28*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        21*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        19*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        14*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N48   , Dn6 
	.byte	W12
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N48   , Cs6 
	.byte	W12
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N72   , Cn6 , v048
	.byte	W12
	.byte		VOL   , 53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        36*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        29*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        22*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        17*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        15*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        12*bgm_cycling_mvl/mxv
	.byte	W28
	.byte		VOICE , 82
	.byte		PAN   , c_v-61
	.byte		VOL   , 55*bgm_cycling_mvl/mxv
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 10
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N72   , En5 
	.byte	W24
	.byte	W24
	.byte		MOD   , 9
	.byte		VOL   , 54*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        39*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        34*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        30*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        25*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 58*bgm_cycling_mvl/mxv
	.byte		N04   , Dn5 , v108
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 , v104
	.byte	W04
	.byte		        Cs5 , v100
	.byte	W04
	.byte		        Dn5 , v096
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Bn4 , v092
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        Bn4 , v088
	.byte	W04
	.byte		        An4 , v084
	.byte	W04
	.byte		        Bn4 , v080
	.byte	W04
	.byte		        An4 , v076
	.byte	W04
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N24   , Cs5 
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte		        0
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn5 
	.byte	W08
	.byte		        Cs5 
	.byte	W08
	.byte		N48   , Bn4 
	.byte	W24
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte	W24
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte		N72   , Dn4 , v080
	.byte	W05
	.byte		VOL   , 39*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        41*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        42*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W10
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W24
	.byte		VOL   , 37*bgm_cycling_mvl/mxv
	.byte		N72   , En4 
	.byte	W02
	.byte		VOL   , 40*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        47*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        51*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        54*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        58*bgm_cycling_mvl/mxv
	.byte	W19
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		VOL   , 41*bgm_cycling_mvl/mxv
	.byte		N72   , Cs4 
	.byte	W02
	.byte		VOL   , 42*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        43*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        45*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        46*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        49*bgm_cycling_mvl/mxv
	.byte	W06
	.byte		        52*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        53*bgm_cycling_mvl/mxv
	.byte	W02
	.byte		        54*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        56*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        57*bgm_cycling_mvl/mxv
	.byte	W16
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N36   , Ds4 
	.byte	W36
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOL   , 45*bgm_cycling_mvl/mxv
	.byte		N48   , Fs4 
	.byte	W02
	.byte		VOL   , 48*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        52*bgm_cycling_mvl/mxv
	.byte	W03
	.byte		        55*bgm_cycling_mvl/mxv
	.byte	W04
	.byte		        57*bgm_cycling_mvl/mxv
	.byte	W12
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte		N03   , Bn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W18
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N96   
	.byte	W72
	.byte		MOD   , 9
	.byte	W24
	.byte		        0
	.byte	W96
	.byte	GOTO
	 .word	bgm_cycling_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_cycling_8:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		VOL   , 45*bgm_cycling_mvl/mxv
	.byte	W96
bgm_cycling_8_B1:
bgm_cycling_8_000:
	.byte	W12
	.byte		N06   , Fs2 , v112
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_cycling_8_000
	.byte	PATT
	 .word	bgm_cycling_8_000
bgm_cycling_8_001:
	.byte	W12
	.byte		N06   , Fs2 , v112
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_cycling_8_000
	.byte	PATT
	 .word	bgm_cycling_8_000
	.byte	PATT
	 .word	bgm_cycling_8_000
	.byte	PATT
	 .word	bgm_cycling_8_001
	.byte		N84   , An2 , v112
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
	 .word	bgm_cycling_8_000
	.byte	W12
	.byte		N06   , Fs2 , v112
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_cycling_8_B1
	.byte	FINE

@********************** Track  9 **********************@

bgm_cycling_9:
	.byte	KEYSH , bgm_cycling_key+0
	.byte		VOICE , 83
	.byte		VOL   , 45*bgm_cycling_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
bgm_cycling_9_B1:
	.byte		BEND  , c_v+0
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W12
	.byte		        En2 
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W18
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W18
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		        Bn1 , v112
	.byte	W06
	.byte		        Bn1 , v032
	.byte	W18
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        An2 , v032
	.byte	W18
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W18
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		        An2 , v112
	.byte	W06
	.byte		        An2 , v032
	.byte	W18
	.byte		        En2 , v112
	.byte	W06
	.byte		        En2 , v032
	.byte	W18
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   , En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		        Dn2 , v112
	.byte	W06
	.byte		        Dn2 , v032
	.byte	W18
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v032
	.byte	W18
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Cs2 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+1
	.byte		N09   , Gn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N18   , Gn1 
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_cycling_9_000:
	.byte		N09   , Gn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N21   , Gn1 
	.byte	W24
	.byte		N06   , En1 
	.byte	W12
	.byte	PEND
	.byte		N09   , Fs1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W24
	.byte		N06   , An1 
	.byte	W12
bgm_cycling_9_001:
	.byte		N09   , Bn1 , v112
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N21   , Bn1 
	.byte	W24
	.byte		N06   , As1 
	.byte	W12
	.byte	PEND
	.byte		N09   , Gn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N18   , Gn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	bgm_cycling_9_000
	.byte		N09   , Fs1 , v112
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W24
	.byte		N06   , As1 
	.byte	W12
	.byte	PATT
	 .word	bgm_cycling_9_001
	.byte		N06   , Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gn1 , v112
	.byte	W12
	.byte		        Gn1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W12
	.byte		        Gs1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Gs1 , v112
	.byte	W12
	.byte		        Gs1 , v096
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
bgm_cycling_9_002:
	.byte		N06   , An1 , v112
	.byte	W24
	.byte		        An1 , v096
	.byte	W24
	.byte		        An1 , v112
	.byte	W24
	.byte		        An1 , v096
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_cycling_9_002
	.byte	GOTO
	 .word	bgm_cycling_9_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_cycling:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_cycling_pri	@ Priority
	.byte	bgm_cycling_rev	@ Reverb.

	.word	bgm_cycling_grp

	.word	bgm_cycling_1
	.word	bgm_cycling_2
	.word	bgm_cycling_3
	.word	bgm_cycling_4
	.word	bgm_cycling_5
	.word	bgm_cycling_6
	.word	bgm_cycling_7
	.word	bgm_cycling_8
	.word	bgm_cycling_9

	.end
