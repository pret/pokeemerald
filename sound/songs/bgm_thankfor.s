	.include "MPlayDef.s"

	.equ	bgm_thankfor_grp, voicegroup_8694C7C
	.equ	bgm_thankfor_pri, 0
	.equ	bgm_thankfor_rev, reverb_set+50
	.equ	bgm_thankfor_mvl, 127
	.equ	bgm_thankfor_key, 0
	.equ	bgm_thankfor_tbs, 1
	.equ	bgm_thankfor_exg, 0
	.equ	bgm_thankfor_cmp, 1

	.section .rodata
	.global	bgm_thankfor
	.align	2

@********************** Track  1 **********************@

bgm_thankfor_1:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 88*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+6
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		N24   , Bn2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 
	.byte	W18
	.byte		VOL   , 77*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		N24   , Cn3 , v076
	.byte	W24
	.byte		        Bn2 , v084
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		        An2 , v092
	.byte	W24
	.byte	TEMPO , 84*bgm_thankfor_tbs/2
	.byte		        Bn2 , v104
	.byte	W24
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte	W24
	.byte		        Bn2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		N30   , Gn3 , v064
	.byte	W36
	.byte		N12   , Gn3 , v088
	.byte	W12
	.byte	TEMPO , 84*bgm_thankfor_tbs/2
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte	TEMPO , 76*bgm_thankfor_tbs/2
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 , v064
	.byte	W12
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N96   , Bn3 , v096
	.byte	W96
	.byte		N24   , An3 , v076
	.byte	W24
	.byte		        Bn3 , v080
	.byte	W24
	.byte		        Cn4 , v084
	.byte	W24
	.byte		N12   , Dn4 , v092
	.byte	W18
	.byte		N03   , Gn3 , v072
	.byte	W03
	.byte		        An3 , v076
	.byte	W03
	.byte		N90   , Bn3 , v108
	.byte	W90
	.byte		N03   , Gn3 , v064
	.byte	W06
	.byte		N96   , Gn3 , v096
	.byte	W96
	.byte		        Cn4 , v108
	.byte	W96
	.byte		N24   , Bn3 , v076
	.byte	W24
	.byte		        Cn4 , v084
	.byte	W24
	.byte		        Dn4 , v088
	.byte	W24
	.byte		N18   , En4 , v080
	.byte	W18
	.byte		N03   , Fs3 , v072
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N96   , Cn4 , v112
	.byte	W96
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		VOL   , 31*bgm_thankfor_mvl/mxv
	.byte	W48
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N18   , Cn5 , v096
	.byte	W18
	.byte		N06   , Bn4 , v092
	.byte	W06
	.byte		        An4 , v084
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N36   , Bn4 , v112
	.byte	W36
	.byte		N06   , As4 , v080
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		N30   , Dn4 , v096
	.byte	W36
	.byte		N03   , Dn4 , v076
	.byte	W06
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		        Bn4 , v104
	.byte	W24
	.byte		        Cn5 , v092
	.byte	W24
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N06   , Cs5 , v068
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		N03   , Gn4 , v080
	.byte	W06
	.byte		N24   , Gn4 , v108
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Fs4 , v040
	.byte	W06
	.byte		        En4 , v052
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		        Bn3 , v072
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+27
	.byte		N04   , Gn5 , v044
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		PAN   , c_v+2
	.byte		N04   , En5 , v036
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-13
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-25
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn3 , v032
	.byte	W04
	.byte		PAN   , c_v+5
	.byte		N42   , Cn5 , v108
	.byte	W42
	.byte		N03   , En4 , v080
	.byte	W06
	.byte		N36   , En4 , v100
	.byte	W36
	.byte		N06   , En4 , v076
	.byte	W06
	.byte		        An4 , v092
	.byte	W06
	.byte		N12   , Bn4 , v112
	.byte	W12
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		        Bn4 , v072
	.byte	W06
	.byte		N12   , Cn5 , v100
	.byte	W12
	.byte		N06   , En4 , v068
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte		N12   , Dn5 , v100
	.byte	W12
	.byte		N06   , En4 , v068
	.byte	W06
	.byte		        Dn5 , v072
	.byte	W06
	.byte		N12   , En5 , v100
	.byte	W12
	.byte		N06   , An4 , v088
	.byte	W06
	.byte		N03   , En5 , v076
	.byte	W03
	.byte		        Fs5 , v084
	.byte	W03
	.byte		N06   , Gn5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        En5 , v076
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		N24   , Dn5 , v096
	.byte	W24
	.byte	TEMPO , 80*bgm_thankfor_tbs/2
	.byte		N12   , Bn4 , v088
	.byte	W12
	.byte		N06   , Cn5 , v080
	.byte	W06
	.byte		        Dn5 , v088
	.byte	W06
	.byte	TEMPO , 92*bgm_thankfor_tbs/2
	.byte		PAN   , c_v+32
	.byte		N06   , Gn5 , v044
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte	TEMPO , 86*bgm_thankfor_tbs/2
	.byte		PAN   , c_v+8
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fs5 , v040
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 , v032
	.byte	W06
	.byte	TEMPO , 80*bgm_thankfor_tbs/2
	.byte		PAN   , c_v-8
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte	TEMPO , 68*bgm_thankfor_tbs/2
	.byte		PAN   , c_v-25
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 , v036
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		PAN   , c_v+5
	.byte		N30   , Bn3 , v112
	.byte	W30
	.byte		N12   , Cn4 , v084
	.byte	W12
	.byte		N06   , Dn4 , v092
	.byte	W06
	.byte		N36   , Bn3 , v104
	.byte	W24
	.byte	TEMPO , 92*bgm_thankfor_tbs/2
	.byte	W12
	.byte		N06   , Cn4 , v088
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N12   , Fn4 , v104
	.byte	W12
	.byte		        En4 , v092
	.byte	W12
	.byte		        Ds4 , v084
	.byte	W12
	.byte		        En4 , v092
	.byte	W12
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		N30   , Bn3 , v096
	.byte	W24
	.byte	TEMPO , 84*bgm_thankfor_tbs/2
	.byte	W06
	.byte		N12   , Cn4 , v092
	.byte	W12
	.byte		N06   , Dn4 , v100
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N30   , Cn4 , v112
	.byte	W30
	.byte		N12   , Dn4 , v104
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N36   , Cn4 , v104
	.byte	W36
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		        En4 , v100
	.byte	W06
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		        Dn4 , v096
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte	TEMPO , 78*bgm_thankfor_tbs/2
	.byte	W06
	.byte		N06   , Bn3 , v100
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N30   , Bn4 
	.byte	W30
	.byte		N12   , Cn5 , v104
	.byte	W12
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		N36   , Bn4 , v104
	.byte	W36
	.byte		N06   , Cn5 , v088
	.byte	W06
	.byte		        Dn5 , v100
	.byte	W06
	.byte		N12   , Fn5 , v104
	.byte	W12
	.byte		        En5 , v092
	.byte	W12
	.byte		        Ds5 , v084
	.byte	W12
	.byte		        En5 , v092
	.byte	W12
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte		N30   , Bn4 , v096
	.byte	W24
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W06
	.byte		N12   , Cn5 , v092
	.byte	W12
	.byte		N06   , Dn5 , v100
	.byte	W06
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        An4 , v088
	.byte	W12
	.byte		        En4 , v076
	.byte	W12
	.byte		N24   , Gn4 , v104
	.byte	W24
	.byte		N03   , Gn4 , v080
	.byte	W03
	.byte		        An4 , v092
	.byte	W03
	.byte		N06   , Gn4 , v080
	.byte	W06
	.byte		        Fs4 , v088
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte		N72   , Gn4 , v096
	.byte	W36
	.byte	TEMPO , 92*bgm_thankfor_tbs/2
	.byte	W12
	.byte	TEMPO , 86*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 76*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W48
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W48
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	TEMPO , 88*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 64*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 88*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 70*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 64*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W72
	.byte	TEMPO , 86*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W48
	.byte	TEMPO , 86*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W96
	.byte	W48
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 78*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W96
	.byte	W48
	.byte	TEMPO , 90*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 92*bgm_thankfor_tbs/2
	.byte	W48
	.byte	TEMPO , 88*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 74*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 92*bgm_thankfor_tbs/2
	.byte	W72
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W24
	.byte	TEMPO , 94*bgm_thankfor_tbs/2
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
	.byte	TEMPO , 82*bgm_thankfor_tbs/2
	.byte	W96
	.byte	TEMPO , 182*bgm_thankfor_tbs/2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

bgm_thankfor_2:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 100*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W24
	.byte		N24   , Bn2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Cn3 , v076
	.byte	W24
	.byte		        Bn2 , v084
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 , v104
	.byte	W24
	.byte	W24
	.byte		        Bn2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		N30   , Gn3 , v064
	.byte	W36
	.byte		N12   , Gn3 , v088
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 , v064
	.byte	W12
	.byte		N96   , Bn3 , v096
	.byte	W96
	.byte		N24   , An3 , v076
	.byte	W24
	.byte		        Bn3 , v080
	.byte	W24
	.byte		        Cn4 , v084
	.byte	W24
	.byte		N12   , Dn4 , v092
	.byte	W18
	.byte		N03   , Gn3 , v072
	.byte	W03
	.byte		        An3 , v076
	.byte	W03
	.byte		N90   , Bn3 , v108
	.byte	W90
	.byte		N03   , Gn3 , v064
	.byte	W06
	.byte		N96   , Gn3 , v096
	.byte	W96
	.byte		        Cn4 , v108
	.byte	W96
	.byte		N24   , Bn3 , v076
	.byte	W24
	.byte		        Cn4 , v084
	.byte	W24
	.byte		        Dn4 , v088
	.byte	W24
	.byte		N18   , En4 , v080
	.byte	W18
	.byte		N03   , Fs3 , v072
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N96   , Cn4 , v092
	.byte	W96
	.byte		VOL   , 78*bgm_thankfor_mvl/mxv
	.byte	W48
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		N18   , Cn5 , v096
	.byte	W18
	.byte		N06   , Bn4 , v092
	.byte	W06
	.byte		        An4 , v084
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Bn4 , v112
	.byte	W36
	.byte		N06   , As4 , v080
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		N30   , Dn4 , v096
	.byte	W36
	.byte		N03   , Dn4 , v076
	.byte	W06
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		N24   , An4 , v084
	.byte	W24
	.byte		        Bn4 , v088
	.byte	W24
	.byte		        Cn5 , v092
	.byte	W24
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N06   , Cs5 , v068
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		N03   , Gn4 , v080
	.byte	W06
	.byte		N24   , Gn4 , v108
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Fs4 , v040
	.byte	W06
	.byte		        En4 , v052
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		        Gn4 , v096
	.byte	W06
	.byte		        Bn3 , v072
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+27
	.byte		N04   , Gn5 , v044
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		PAN   , c_v+1
	.byte		N04   , En5 , v040
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-11
	.byte		N04   , Bn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-24
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N42   , Cn5 , v108
	.byte	W42
	.byte		N03   , En4 , v080
	.byte	W06
	.byte		N36   , En4 , v100
	.byte	W36
	.byte		N06   , En4 , v076
	.byte	W06
	.byte		        An4 , v092
	.byte	W06
	.byte		N12   , Bn4 , v112
	.byte	W12
	.byte		N06   , En4 , v064
	.byte	W06
	.byte		        Bn4 , v072
	.byte	W06
	.byte		N12   , Cn5 , v100
	.byte	W12
	.byte		N06   , En4 , v068
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte		N12   , Dn5 , v100
	.byte	W12
	.byte		N06   , En4 , v068
	.byte	W06
	.byte		        Dn5 , v072
	.byte	W06
	.byte		N12   , En5 , v100
	.byte	W12
	.byte		N06   , An4 , v088
	.byte	W06
	.byte		N03   , En5 , v076
	.byte	W03
	.byte		        Fs5 , v084
	.byte	W03
	.byte		N06   , Gn5 , v112
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        En5 , v076
	.byte	W06
	.byte		        Fs5 , v080
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N12   , Bn4 , v088
	.byte	W12
	.byte		N06   , Cn5 , v076
	.byte	W06
	.byte		        Dn5 , v080
	.byte	W06
	.byte		PAN   , c_v+25
	.byte		N06   , Gn5 , v044
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		PAN   , c_v+16
	.byte		N06   , Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		PAN   , c_v+5
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fs5 , v040
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        En5 , v032
	.byte	W06
	.byte		PAN   , c_v-8
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		PAN   , c_v-26
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 , v036
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		VOL   , 98*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N30   , Bn3 , v088
	.byte	W30
	.byte		N12   , Cn4 , v084
	.byte	W12
	.byte		N06   , Dn4 , v092
	.byte	W06
	.byte		N36   , Bn3 , v104
	.byte	W36
	.byte		N06   , Cn4 , v088
	.byte	W06
	.byte		        Dn4 , v100
	.byte	W06
	.byte		N12   , Fn4 , v104
	.byte	W12
	.byte		        En4 , v092
	.byte	W12
	.byte		        Ds4 , v084
	.byte	W12
	.byte		        En4 , v092
	.byte	W12
	.byte		N30   , Bn3 , v080
	.byte	W30
	.byte		N12   , Cn4 , v092
	.byte	W12
	.byte		N06   , Dn4 , v100
	.byte	W06
	.byte		N30   , Cn4 , v096
	.byte	W30
	.byte		N12   , Dn4 , v104
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		N36   , Cn4 , v104
	.byte	W36
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		        En4 , v100
	.byte	W06
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		        Dn4 , v096
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W18
	.byte		N06   , Bn3 , v100
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		VOL   , 78*bgm_thankfor_mvl/mxv
	.byte		N30   , Bn4 
	.byte	W30
	.byte		N12   , Cn5 , v104
	.byte	W12
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		N36   , Bn4 , v104
	.byte	W36
	.byte		N06   , Cn5 , v088
	.byte	W06
	.byte		        Dn5 , v100
	.byte	W06
	.byte		N12   , Fn5 , v104
	.byte	W12
	.byte		        En5 , v092
	.byte	W12
	.byte		        Ds5 , v084
	.byte	W12
	.byte		        En5 , v092
	.byte	W12
	.byte		N30   , Bn4 , v096
	.byte	W30
	.byte		N12   , Cn5 , v092
	.byte	W12
	.byte		N06   , Dn5 , v100
	.byte	W06
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        An4 , v088
	.byte	W12
	.byte		        En4 , v076
	.byte	W12
	.byte		N24   , Gn4 , v104
	.byte	W24
	.byte		N03   , Gn4 , v080
	.byte	W03
	.byte		        An4 , v092
	.byte	W03
	.byte		N06   , Gn4 , v080
	.byte	W06
	.byte		        Fs4 , v088
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N72   , Gn4 , v096
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 73
	.byte	W96
	.byte		PAN   , c_v-29
	.byte		VOL   , 29*bgm_thankfor_mvl/mxv
	.byte		N06   , Gn5 , v112
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		N03   , An5 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N03   , Gn5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N03   , En5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N06   , En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cn6 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N03   , An5 
	.byte	W03
	.byte		        Bn5 
	.byte	W03
	.byte		N06   , An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N18   , Gn5 
	.byte	W18
	.byte		N03   , En5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N03   , Bn5 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N03   , En5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		N03   , Cn6 
	.byte	W03
	.byte		        Dn6 
	.byte	W03
	.byte		N06   , Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		N03   , Bn5 
	.byte	W03
	.byte		        Cn6 
	.byte	W03
	.byte		N06   , Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		N12   , An5 
	.byte	W12
	.byte		N06   , Gn5 
	.byte	W06
	.byte		N03   , An5 , v084
	.byte	W03
	.byte		        Bn5 , v088
	.byte	W03
	.byte		        Cs6 , v112
	.byte	W03
	.byte		        Dn6 
	.byte	W03
	.byte		N06   , Cn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        An5 
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
	.byte	W18
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N18   , An4 
	.byte	W24
	.byte		N04   , Dn6 , v092
	.byte	W04
	.byte		        En6 , v072
	.byte	W04
	.byte		        Dn6 , v068
	.byte	W04
	.byte		        Cn6 , v092
	.byte	W04
	.byte		        Dn6 , v072
	.byte	W04
	.byte		        Cn6 , v068
	.byte	W04
	.byte		        Bn5 , v092
	.byte	W04
	.byte		        Cn6 , v072
	.byte	W04
	.byte		        Bn5 , v068
	.byte	W04
	.byte		        An5 , v092
	.byte	W04
	.byte		        Bn5 , v072
	.byte	W04
	.byte		        An5 , v068
	.byte	W04
	.byte		        Gn5 , v092
	.byte	W04
	.byte		        An5 , v072
	.byte	W04
	.byte		        Gn5 , v068
	.byte	W04
	.byte		        Fs5 , v092
	.byte	W04
	.byte		        Gn5 , v072
	.byte	W04
	.byte		        Fs5 , v068
	.byte	W04
	.byte		VOICE , 56
	.byte		PAN   , c_v-38
	.byte		VOL   , 48*bgm_thankfor_mvl/mxv
	.byte		N32   , Dn4 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		        Dn4 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N32   , Dn4 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		        Dn4 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N24   , Bn3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N03   , An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		VOICE , 60
	.byte		VOL   , 59*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-41
	.byte		N30   , An3 
	.byte	W30
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		VOICE , 60
	.byte		N12   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N03   , An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N30   , Dn4 
	.byte	W30
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N30   , En4 
	.byte	W48
	.byte		PAN   , c_v+42
	.byte		VOL   , 44*bgm_thankfor_mvl/mxv
	.byte		N12   , An4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		PAN   , c_v-41
	.byte		VOL   , 59*bgm_thankfor_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N60   , En5 
	.byte	W24
	.byte		VOL   , 58*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        43*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        39*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        38*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N60   , En5 
	.byte	W24
	.byte		VOL   , 59*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        57*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        46*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        39*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N03   , En5 , v100
	.byte	W03
	.byte		        Fn5 , v092
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        En5 , v100
	.byte	W06
	.byte		N48   , Dn5 , v112
	.byte	W24
	.byte		VOL   , 59*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        46*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        43*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		N60   , Fn5 
	.byte	W24
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        45*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , En5 
	.byte	W12
	.byte		N48   , Fn5 
	.byte	W12
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N36   , Dn5 
	.byte	W36
	.byte		N06   , En5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N36   , Dn5 
	.byte	W36
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		VOL   , 59*bgm_thankfor_mvl/mxv
	.byte		N92   , Cs5 
	.byte	W24
	.byte		VOL   , 55*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        46*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        43*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        34*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        58*bgm_thankfor_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        8*bgm_thankfor_mvl/mxv
	.byte		TIE   , En5 
	.byte	W12
	.byte		VOL   , 7*bgm_thankfor_mvl/mxv
	.byte	W24
	.byte	W02
	.byte		        8*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        30*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        39*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        43*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        45*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        67*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        70*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        72*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        75*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        78*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        81*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        82*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        86*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		EOT   
	.byte		VOICE , 47
	.byte		PAN   , c_v+50
	.byte		N12   , An2 , v096
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

bgm_thankfor_3:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 1
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v-24
	.byte		VOL   , 93*bgm_thankfor_mvl/mxv
	.byte		TIE   , Gn1 , v120
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   
	.byte	W96
	.byte		N48   , Cn1 , v064
	.byte	W48
	.byte		N12   , Cn2 , v092
	.byte	W12
	.byte		        Dn2 , v076
	.byte	W12
	.byte		        An1 , v084
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		TIE   , Gn1 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En1 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		TIE   , An1 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   , Dn2 
	.byte	W96
	.byte		N36   , Dn1 , v088
	.byte	W36
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N12   , Dn1 
	.byte	W12
	.byte		TIE   , Gn1 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En1 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		TIE   , An1 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   , Dn2 
	.byte	W96
	.byte		N84   , Dn2 , v088
	.byte	W84
	.byte		N12   , Dn1 , v112
	.byte	W12
bgm_thankfor_3_000:
	.byte		N48   , Gn1 , v112
	.byte	W48
	.byte		        Fs1 
	.byte	W48
	.byte	PEND
	.byte		        Fn1 
	.byte	W48
	.byte		        En1 
	.byte	W48
	.byte		        An1 
	.byte	W48
	.byte		        Gs1 
	.byte	W48
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Cn2 , v084
	.byte	W24
	.byte		        Bn1 , v088
	.byte	W24
	.byte		N12   , An1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_3_000
	.byte		N48   , Fn1 , v112
	.byte	W48
	.byte		N36   , En1 
	.byte	W36
	.byte		N12   , Gs1 
	.byte	W12
	.byte		N48   , An1 
	.byte	W48
	.byte		        Dn2 
	.byte	W48
	.byte		N72   , Gn1 
	.byte	W72
	.byte		VOICE , 58
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*bgm_thankfor_mvl/mxv
	.byte		N12   , Dn0 
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		TIE   , Gn0 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En0 
	.byte	W96
	.byte	W72
	.byte		EOT   
	.byte		N12   
	.byte	W12
	.byte		        Dn0 
	.byte	W12
	.byte		TIE   , An0 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   , Dn1 
	.byte	W96
	.byte		N72   , Dn0 , v088
	.byte	W72
	.byte		N12   , Dn0 , v112
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		VOICE , 58
	.byte		VOL   , 78*bgm_thankfor_mvl/mxv
	.byte		N36   , Gn0 
	.byte	W36
	.byte		VOL   , 78*bgm_thankfor_mvl/mxv
	.byte		N06   , Fs0 
	.byte	W06
	.byte		        Gn0 
	.byte	W06
	.byte		N48   
	.byte	W48
	.byte		N36   
	.byte	W36
	.byte		N12   , Fs0 
	.byte	W12
	.byte		N36   , Gn0 
	.byte	W36
	.byte		N12   , Fs0 
	.byte	W12
	.byte		N36   , En0 
	.byte	W36
	.byte		N06   , Ds0 
	.byte	W06
	.byte		        En0 
	.byte	W06
	.byte		N48   
	.byte	W48
	.byte		N42   
	.byte	W42
	.byte		N06   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Fs0 
	.byte	W12
	.byte		N36   , An0 
	.byte	W36
	.byte		N06   , Gs0 
	.byte	W06
	.byte		        An0 
	.byte	W06
	.byte		N36   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   
	.byte	W36
	.byte		N06   , Bn0 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N96   , Dn1 
	.byte	W96
	.byte		N84   , Dn1 , v088
	.byte	W84
	.byte		N12   , Dn0 , v112
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N02   , Gn1 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Fn1 , v112
	.byte	W12
	.byte		N02   , Fn1 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N02   , Dn1 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 85*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn0 , v112
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		N36   , Cn1 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , Bn0 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , As0 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , An0 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , Dn1 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , Cs1 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		VOL   , 82*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N36   , Bn0 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N36   , Gn1 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
bgm_thankfor_3_001:
	.byte		N36   , An1 , v112
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
	.byte		N36   , Gn1 
	.byte	W12
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_3_001
	.byte	PATT
	 .word	bgm_thankfor_3_001
	.byte	PATT
	 .word	bgm_thankfor_3_001
	.byte		VOL   , 10*bgm_thankfor_mvl/mxv
	.byte		TIE   , An1 , v112
	.byte	W05
	.byte		VOL   , 11*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W16
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W08
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		        19*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W08
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        32*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte	W02
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        52*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        58*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        68*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        70*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        72*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        77*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        80*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        84*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        88*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        91*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        93*bgm_thankfor_mvl/mxv
	.byte	W10
	.byte		EOT   
	.byte		N06   , An0 
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

bgm_thankfor_4:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+21
	.byte		VOL   , 69*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		N24   , Dn2 , v080
	.byte	W24
	.byte		        Dn2 , v076
	.byte	W24
	.byte		        Dn2 , v080
	.byte	W21
	.byte		PAN   , c_v+30
	.byte	W03
	.byte		N24   , Dn2 , v076
	.byte	W12
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W24
	.byte		        Dn2 , v076
	.byte	W24
	.byte		        Dn2 , v080
	.byte	W24
	.byte		        Gn2 , v116
	.byte	W12
	.byte	W12
	.byte		        Dn2 , v080
	.byte	W24
	.byte		        Dn2 , v076
	.byte	W24
	.byte		        Dn2 , v080
	.byte	W24
	.byte		N12   , Dn2 , v076
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		N36   , Cn3 , v084
	.byte	W36
	.byte		N18   , Dn3 , v092
	.byte	W18
	.byte		N30   , Dn3 , v080
	.byte	W30
	.byte	W12
	.byte		N24   , Dn2 , v068
	.byte	W24
	.byte		        Dn2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Dn2 , v068
	.byte	W12
bgm_thankfor_4_000:
	.byte	W12
	.byte		N24   , Dn2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Dn2 , v088
	.byte	W12
	.byte	PEND
bgm_thankfor_4_001:
	.byte	W12
	.byte		N24   , Bn1 , v068
	.byte	W24
	.byte		        Bn1 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn1 , v068
	.byte	W12
	.byte	PEND
bgm_thankfor_4_002:
	.byte	W12
	.byte		N24   , Bn1 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
bgm_thankfor_4_003:
	.byte	W12
	.byte		N24   , En2 , v068
	.byte	W24
	.byte		        En2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        En2 , v068
	.byte	W12
	.byte	PEND
bgm_thankfor_4_004:
	.byte	W12
	.byte		N24   , En2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        En2 , v088
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		        An2 , v068
	.byte	W24
	.byte		        An2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , An2 , v068
	.byte	W12
	.byte	W12
	.byte		N32   , An1 , v092
	.byte	W32
	.byte	W01
	.byte		N03   , An4 , v076
	.byte	W03
	.byte		N48   , Cn3 , v112
	.byte	W48
	.byte		VOL   , 73*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		N24   , Dn2 , v068
	.byte	W24
	.byte		        Dn2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Dn2 , v068
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_4_000
	.byte	PATT
	 .word	bgm_thankfor_4_001
	.byte	PATT
	 .word	bgm_thankfor_4_002
	.byte	PATT
	 .word	bgm_thankfor_4_003
	.byte	PATT
	 .word	bgm_thankfor_4_004
	.byte	W12
	.byte		N24   , An2 , v068
	.byte	W24
	.byte		        An2 , v064
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An2 , v068
	.byte	W12
	.byte	W72
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v+31
	.byte	W12
	.byte		N24   , Dn2 , v088
	.byte	W24
	.byte		        Dn2 , v092
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn2 , v108
	.byte	W12
	.byte	W12
	.byte		N24   , Bn1 , v088
	.byte	W24
	.byte		        Bn1 , v092
	.byte	W24
	.byte		        Bn1 , v088
	.byte	W24
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte	W12
	.byte		N24   , En2 , v088
	.byte	W24
	.byte		        En2 , v092
	.byte	W24
	.byte		        En2 , v088
	.byte	W24
	.byte		N09   , En2 , v112
	.byte	W12
	.byte	W12
	.byte		N24   , An2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        An2 , v088
	.byte	W24
	.byte		N12   , An2 , v104
	.byte	W12
	.byte	W12
	.byte		N24   , Dn2 , v088
	.byte	W24
	.byte		        Dn2 , v092
	.byte	W24
	.byte		        Dn2 , v088
	.byte	W24
	.byte		N12   , Dn2 , v104
	.byte	W12
	.byte	W12
	.byte		N24   , Bn1 , v088
	.byte	W24
	.byte		        Bn1 , v092
	.byte	W24
	.byte		        Bn1 , v088
	.byte	W36
	.byte	W12
	.byte		        En2 
	.byte	W24
	.byte		N12   , En2 , v092
	.byte	W24
	.byte		N24   , An2 , v088
	.byte	W24
	.byte		N12   , An2 , v104
	.byte	W12
	.byte	W12
	.byte		N24   , Dn2 , v088
	.byte	W24
	.byte		        Dn2 , v092
	.byte	W24
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		VOICE , 73
	.byte		PAN   , c_v+0
	.byte		VOL   , 43*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N03   , Cn5 , v080
	.byte	W03
	.byte		N68   , Bn4 , v112
	.byte	W21
	.byte		MOD   , 7
	.byte		VOL   , 40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        23*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 43*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		        Bn4 , v104
	.byte	W24
	.byte		        Cn5 , v100
	.byte	W24
	.byte		N12   , Dn5 , v092
	.byte	W12
	.byte		N06   , Cs5 , v080
	.byte	W06
	.byte		        Cn5 , v072
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W24
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W01
	.byte		MOD   , 0
	.byte		VOL   , 12*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Gs4 , v096
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N60   , Gn4 
	.byte	W60
	.byte		MOD   , 0
	.byte	W21
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N36   , Cn5 
	.byte	W24
	.byte		VOL   , 40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_thankfor_mvl/mxv
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   , Cs5 , v080
	.byte	W03
	.byte		N44   , Cn5 , v112
	.byte	W21
	.byte		MOD   , 7
	.byte		VOL   , 40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        32*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        23*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 44*bgm_thankfor_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		N03   , Ds5 , v084
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Cs5 , v072
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N06   , Cn5 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N68   , Cn5 
	.byte	W21
	.byte		MOD   , 7
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        34*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte	W03
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 , v064
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 , v068
	.byte	W03
	.byte		        Cn5 , v072
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N06   , As4 , v080
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		N30   , Dn4 , v096
	.byte	W36
	.byte		N03   , Dn4 , v076
	.byte	W06
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		        Bn4 , v104
	.byte	W24
	.byte		        Cn5 , v100
	.byte	W24
	.byte		N12   , Dn5 , v092
	.byte	W12
	.byte		N06   , Cs5 , v072
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N24   , Gn4 , v092
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Fs4 , v076
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		        Fs4 , v084
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W96
	.byte		N36   , Cn5 , v108
	.byte	W36
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N36   , En4 , v080
	.byte	W36
	.byte		N03   , En4 , v076
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , An4 , v080
	.byte	W06
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N18   , En5 
	.byte	W18
	.byte		N03   , Dn5 , v092
	.byte	W06
	.byte		N24   , Dn5 , v108
	.byte	W36
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N18   , Dn5 
	.byte	W24
	.byte		N04   , Gn5 , v092
	.byte	W04
	.byte		        An5 , v072
	.byte	W04
	.byte		        Gn5 , v068
	.byte	W04
	.byte		        Fs5 , v092
	.byte	W04
	.byte		        Gn5 , v072
	.byte	W04
	.byte		        Fs5 , v068
	.byte	W04
	.byte		        En5 , v092
	.byte	W04
	.byte		        Fs5 , v072
	.byte	W04
	.byte		        En5 , v068
	.byte	W04
	.byte		        Dn5 , v092
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        Dn5 , v068
	.byte	W04
	.byte		        Cn5 , v092
	.byte	W04
	.byte		        Dn5 , v072
	.byte	W04
	.byte		        Cn5 , v068
	.byte	W04
	.byte		        Bn4 , v092
	.byte	W04
	.byte		        Cn5 , v072
	.byte	W04
	.byte		        Bn4 , v068
	.byte	W04
	.byte		VOICE , 60
	.byte		VOL   , 90*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N30   , Bn3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 , v108
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        En4 , v116
	.byte	W12
	.byte		N03   , Ds4 , v108
	.byte	W03
	.byte		        En4 , v112
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Dn4 , v104
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		N30   , Bn3 , v096
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 74*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Cn4 , v092
	.byte	W12
	.byte		N06   , Dn4 , v100
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N30   , Cn4 , v112
	.byte	W12
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte		N12   , Dn4 , v104
	.byte	W12
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Cn4 , v104
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn4 , v088
	.byte	W06
	.byte		        En4 , v100
	.byte	W06
	.byte		N12   , Gn4 , v104
	.byte	W12
	.byte		        Fs4 , v092
	.byte	W12
	.byte		N03   , En4 , v084
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 , v092
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		N12   , Dn4 , v096
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		VOL   , 67*bgm_thankfor_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		VOL   , 80*bgm_thankfor_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		VOL   , 75*bgm_thankfor_mvl/mxv
	.byte		N30   , Bn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Cn5 , v104
	.byte	W12
	.byte		N06   , Dn5 , v112
	.byte	W06
	.byte		N36   , Bn4 , v104
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cn5 , v088
	.byte	W06
	.byte		        Dn5 , v100
	.byte	W06
	.byte		N12   , Fn5 , v104
	.byte	W12
	.byte		        En5 , v092
	.byte	W12
	.byte		        Ds5 , v112
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N30   , Bn4 , v096
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		VOICE , 48
	.byte		VOL   , 74*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Cn5 , v092
	.byte	W12
	.byte		N06   , Dn5 , v100
	.byte	W06
	.byte		VOL   , 81*bgm_thankfor_mvl/mxv
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		        En4 , v084
	.byte	W12
	.byte		        An4 , v088
	.byte	W12
	.byte		        En4 , v076
	.byte	W12
	.byte		        Gn4 , v104
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*bgm_thankfor_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 60
	.byte		VOL   , 69*bgm_thankfor_mvl/mxv
	.byte		N36   , An3 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N48   , En4 
	.byte	W24
	.byte		VOL   , 69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Bn3 
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N72   , En4 
	.byte	W24
	.byte		VOL   , 69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W24
	.byte		VOL   , 69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        34*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N21   , Dn4 
	.byte	W24
	.byte		N72   , En4 
	.byte	W24
	.byte		VOL   , 66*bgm_thankfor_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N21   , Dn4 
	.byte	W24
	.byte		VOL   , 6*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		TIE   , Cs4 
	.byte	W02
	.byte		VOL   , 7*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        9*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        19*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        32*bgm_thankfor_mvl/mxv
	.byte	W08
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        55*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        70*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        75*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        78*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        79*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        81*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        87*bgm_thankfor_mvl/mxv
	.byte	W28
	.byte		EOT   
	.byte		N03   , An1 
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

bgm_thankfor_5:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 90*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+28
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
	.byte	W48
	.byte		        c_v+30
	.byte	W48
	.byte		VOL   , 56*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-29
	.byte	W12
	.byte		N06   , Bn4 , v112
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N03   , Bn3 , v100
	.byte	W03
	.byte		        Dn4 , v104
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		PAN   , c_v-24
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 , v092
	.byte	W03
	.byte		        Dn5 , v096
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		PAN   , c_v+26
	.byte		N03   , Bn5 , v100
	.byte	W03
	.byte		        An5 , v096
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , Gn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 , v092
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		N06   , Bn4 , v088
	.byte	W06
	.byte		        As4 , v084
	.byte	W06
	.byte		PAN   , c_v-13
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W06
	.byte		PAN   , c_v-32
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		N03   , Dn4 , v096
	.byte	W03
	.byte		        Gn4 , v088
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		PAN   , c_v-25
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		PAN   , c_v-10
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        An5 , v092
	.byte	W03
	.byte		PAN   , c_v+24
	.byte		N03   , Bn5 , v096
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Gn5 , v088
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		PAN   , c_v+2
	.byte		N03   , An5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W36
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+26
	.byte		N03   , Cn6 , v092
	.byte	W03
	.byte		        An5 , v084
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		PAN   , c_v+8
	.byte		N03   , Fs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		PAN   , c_v-33
	.byte		N03   , En5 
	.byte	W03
	.byte		        Cn5 , v096
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		VOICE , 46
	.byte		VOL   , 57*bgm_thankfor_mvl/mxv
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N12   , Dn5 
	.byte	W36
	.byte		PAN   , c_v-39
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		PAN   , c_v-21
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		PAN   , c_v+42
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		PAN   , c_v+25
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		PAN   , c_v+7
	.byte		N03   , An3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 62*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Gn4 , v096
	.byte	W06
	.byte		        Bn3 , v072
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		PAN   , c_v-16
	.byte		N06   , Bn4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		PAN   , c_v-7
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N04   , Gn5 , v092
	.byte	W04
	.byte		        En5 , v088
	.byte	W04
	.byte		        Bn4 , v080
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Bn4 , v076
	.byte	W04
	.byte		        Gn4 , v072
	.byte	W04
	.byte		PAN   , c_v+15
	.byte		N04   , Bn4 , v088
	.byte	W04
	.byte		        Gn4 , v084
	.byte	W04
	.byte		        En4 , v080
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , Gn4 , v072
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Bn3 , v064
	.byte	W04
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte	W96
	.byte		        47
	.byte		VOL   , 62*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W48
	.byte		VOL   , 88*bgm_thankfor_mvl/mxv
	.byte		N04   , Dn2 , v056
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Dn2 , v060
	.byte	W04
	.byte		        Dn2 , v072
	.byte	W04
	.byte		        Dn2 , v088
	.byte	W04
	.byte		        Dn2 , v108
	.byte	W04
	.byte		        Dn2 , v112
	.byte	W04
	.byte		        Dn2 , v116
	.byte	W04
	.byte		VOL   , 88*bgm_thankfor_mvl/mxv
	.byte		N15   , Gn1 , v112
	.byte	W36
	.byte		N02   , Gn1 , v056
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N14   , Fs1 , v072
	.byte	W36
	.byte		N02   , Fs1 , v052
	.byte	W04
	.byte		        Fs1 , v048
	.byte	W04
	.byte		        Fs1 , v052
	.byte	W04
	.byte		N04   , Fn1 , v064
	.byte	W24
	.byte		        En1 , v040
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		VOL   , 88*bgm_thankfor_mvl/mxv
	.byte		N04   , En1 
	.byte	W12
	.byte		N06   , En2 , v112
	.byte	W12
	.byte		N24   , An1 
	.byte	W36
	.byte		N04   , Cn2 , v040
	.byte	W04
	.byte		        Bn1 
	.byte	W08
	.byte		N24   , Gs1 
	.byte	W36
	.byte		N04   , Bn1 
	.byte	W04
	.byte		        Cn2 
	.byte	W08
	.byte		        Dn2 , v060
	.byte	W24
	.byte		        Cn2 , v040
	.byte	W24
	.byte		VOICE , 47
	.byte		N04   , Dn2 , v056
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		        Dn2 , v060
	.byte	W04
	.byte		        Dn2 , v072
	.byte	W04
	.byte		        Dn2 , v088
	.byte	W04
	.byte		        Dn2 , v108
	.byte	W04
	.byte		        Dn2 , v112
	.byte	W04
	.byte		        Dn2 , v116
	.byte	W04
	.byte		VOL   , 100*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Gn1 , v112
	.byte	W36
	.byte		N02   , Gn1 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Fs1 , v112
	.byte	W36
	.byte		N02   , Fs1 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Fn1 , v112
	.byte	W48
	.byte		N08   , Bn1 , v096
	.byte	W12
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N06   , Bn1 , v080
	.byte	W06
	.byte		        Bn1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		N48   , An1 , v124
	.byte	W48
	.byte		N04   , Dn2 , v104
	.byte	W12
	.byte		        An1 , v084
	.byte	W12
	.byte		        Dn2 , v112
	.byte	W12
	.byte		N12   , An1 , v092
	.byte	W12
	.byte		VOICE , 47
	.byte		VOL   , 100*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Gn2 , v112
	.byte	W12
	.byte		N02   , Dn2 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		PAN   , c_v+26
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		N02   , Dn2 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		N06   , Dn2 , v112
	.byte	W12
	.byte		N02   , Dn2 , v080
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N02   , Gn1 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		        Gn1 , v084
	.byte	W04
	.byte		        Gn1 , v096
	.byte	W04
	.byte		        Gn1 , v108
	.byte	W04
	.byte		        Gn1 , v124
	.byte	W04
	.byte		VOICE , 1
	.byte		VOL   , 49*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Cn3 , v112
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		VOICE , 14
	.byte		N48   , An3 
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte		        Gn3 
	.byte	W48
	.byte		        Dn3 
	.byte	W48
bgm_thankfor_5_000:
	.byte		N72   , En3 , v112
	.byte	W72
	.byte		N24   , Dn3 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_5_000
	.byte		N72   , En3 , v112
	.byte	W96
	.byte		VOICE , 48
	.byte		VOL   , 6*bgm_thankfor_mvl/mxv
	.byte		TIE   , An3 
	.byte	W08
	.byte		VOL   , 7*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        9*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        19*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        26*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        32*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte	W02
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        51*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        64*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        69*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        70*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        73*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        75*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        78*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        79*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        81*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        83*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        85*bgm_thankfor_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte		VOICE , 47
	.byte		VOL   , 100*bgm_thankfor_mvl/mxv
	.byte		N24   , An1 
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

bgm_thankfor_6:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-61
	.byte		VOL   , 44*bgm_thankfor_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_thankfor_6_000:
	.byte		VOL   , 30*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	PEND
bgm_thankfor_6_001:
	.byte	W12
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_6_001
	.byte	W12
	.byte		N24   , Bn2 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
bgm_thankfor_6_002:
	.byte	W12
	.byte		N24   , En3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_6_002
	.byte	W12
	.byte		N24   , Fs3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		VOL   , 10*bgm_thankfor_mvl/mxv
	.byte		N48   , Dn3 
	.byte	W06
	.byte		VOL   , 10*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        52*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        57*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        61*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte		N48   , An3 
	.byte	W03
	.byte		VOL   , 11*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        23*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        61*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_6_000
	.byte	PATT
	 .word	bgm_thankfor_6_001
	.byte	W12
	.byte		N24   , Dn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
bgm_thankfor_6_003:
	.byte	W12
	.byte		N24   , En4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_6_003
	.byte	W12
	.byte		N24   , Fs4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte		        Dn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , An4 
	.byte	W03
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		VOICE , 4
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N44   , Gn4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W24
	.byte		N24   , Fs4 
	.byte	W24
	.byte		MOD   , 0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , An4 
	.byte	W24
	.byte		N15   , Gn4 
	.byte	W12
	.byte		MOD   , 0
	.byte	W06
	.byte		N03   , En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Ds4 
	.byte	W24
	.byte		MOD   , 0
	.byte		N24   , En4 
	.byte	W24
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N44   , Gn4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Bn4 , v096
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N03   , As4 
	.byte	W03
	.byte		N68   , An4 
	.byte	W21
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W15
	.byte		VOL   , 45*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        35*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        32*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		VOICE , 68
	.byte		VOL   , 40*bgm_thankfor_mvl/mxv
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   , En2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N09   , An2 
	.byte	W06
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N18   , Fs3 
	.byte	W96
	.byte		VOICE , 84
	.byte		N32   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		        Gn3 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N32   , Fs3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		        Fs3 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N24   , Gs3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte		N30   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N36   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte		VOICE , 68
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N12   , Gn3 , v116
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v088
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn4 , v084
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v088
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Fn4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W15
	.byte		N12   
	.byte	W09
	.byte		PAN   , c_v+63
	.byte		N12   , Fn4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v096
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Fn4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W15
	.byte		N12   
	.byte	W09
	.byte		PAN   , c_v+63
	.byte		N12   , Fn4 , v088
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Fn4 , v092
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		PAN   , c_v-62
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Gn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		        c_v-62
	.byte		N12   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn3 
	.byte	W12
	.byte		PAN   , c_v-62
	.byte		N12   , Dn3 
	.byte	W12
	.byte		VOICE , 4
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
bgm_thankfor_6_004:
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_6_004
	.byte	PATT
	 .word	bgm_thankfor_6_004
	.byte		VOICE , 81
	.byte		VOL   , 5*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		TIE   , En2 , v112
	.byte	W02
	.byte		VOL   , 6*bgm_thankfor_mvl/mxv
	.byte	W56
	.byte	W02
	.byte		        7*bgm_thankfor_mvl/mxv
	.byte	W20
	.byte		        7*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		        8*bgm_thankfor_mvl/mxv
	.byte	W07
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        28*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        34*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        46*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        47*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        50*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        59*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        75*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        81*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        84*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        88*bgm_thankfor_mvl/mxv
	.byte	W28
	.byte		EOT   
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

bgm_thankfor_7:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 5
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 43*bgm_thankfor_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_thankfor_7_000:
	.byte		VOL   , 30*bgm_thankfor_mvl/mxv
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PEND
bgm_thankfor_7_001:
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte	PEND
bgm_thankfor_7_002:
	.byte		N24   , Gn3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte	PEND
	.byte		        En3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
bgm_thankfor_7_003:
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_7_003
	.byte		N24   , An3 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		VOL   , 10*bgm_thankfor_mvl/mxv
	.byte		N48   , Fs3 
	.byte	W06
	.byte		VOL   , 10*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        12*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        15*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        20*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        52*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        53*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        57*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        61*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte		N48   , Cn4 
	.byte	W03
	.byte		VOL   , 11*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        16*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        23*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        27*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        48*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        56*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        61*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        62*bgm_thankfor_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_7_000
	.byte	PATT
	 .word	bgm_thankfor_7_001
	.byte	PATT
	 .word	bgm_thankfor_7_002
	.byte		N06   , En4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        En4 
	.byte	W24
bgm_thankfor_7_004:
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_thankfor_7_004
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	W96
	.byte		VOL   , 31*bgm_thankfor_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		VOICE , 80
	.byte		VOL   , 41*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N24   , Bn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		N12   , En2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Bn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , En2 
	.byte	W24
	.byte		        Fs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Bn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , Cn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Cn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N36   , Dn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 45*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        25*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        23*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		VOICE , 105
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
	.byte		N36   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N30   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        En4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fs4 , v084
	.byte	W06
	.byte		        En4 , v072
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N32   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N21   , Cn4 
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N03   , An4 
	.byte	W06
	.byte		N24   
	.byte	W36
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N18   , Fs4 
	.byte	W96
	.byte		VOICE , 86
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*bgm_thankfor_mvl/mxv
	.byte		N32   , Gn1 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N32   , Fs1 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N24   , Fn1 
	.byte	W24
	.byte		N12   , En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N36   , An1 
	.byte	W36
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N36   , Gs1 
	.byte	W36
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Cn2 , v096
	.byte	W24
	.byte		        An1 , v108
	.byte	W24
	.byte		N12   , Fs1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N32   , Gn1 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N32   , Fs1 
	.byte	W36
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N36   , Fn1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N36   , En1 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N36   , An1 
	.byte	W36
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_thankfor_mvl/mxv
	.byte		N36   , Cn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , Bn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , An1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , Dn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , Cs2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N48   
	.byte	W48
	.byte		N36   , Bn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W36
	.byte		N06   
	.byte	W12
bgm_thankfor_7_005:
	.byte		N36   , An2 , v112
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte		N36   , Gn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_thankfor_7_005
	.byte	PATT
	 .word	bgm_thankfor_7_005
	.byte	PATT
	 .word	bgm_thankfor_7_005
	.byte		VOICE , 109
	.byte		VOL   , 7*bgm_thankfor_mvl/mxv
	.byte		TIE   , An4 , v112
	.byte	W02
	.byte		VOL   , 7*bgm_thankfor_mvl/mxv
	.byte	W36
	.byte		        7*bgm_thankfor_mvl/mxv
	.byte	W30
	.byte		        7*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        8*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        9*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W09
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        11*bgm_thankfor_mvl/mxv
	.byte	W01
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        10*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        14*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        29*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        34*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        41*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        44*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        49*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        54*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        57*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        60*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        66*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        67*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        72*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        74*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        78*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        82*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        87*bgm_thankfor_mvl/mxv
	.byte	W24
	.byte		EOT   
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

bgm_thankfor_8:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 70*bgm_thankfor_mvl/mxv
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N48   , Gn2 , v096
	.byte	W48
	.byte		        An2 , v112
	.byte	W96
	.byte	W84
	.byte		N12   , Gn2 , v076
	.byte	W12
	.byte		N48   , An2 , v104
	.byte	W96
	.byte	W84
	.byte		N12   , Gn2 , v080
	.byte	W12
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W84
	.byte		N12   , Gn2 , v076
	.byte	W12
	.byte		N48   , An2 , v112
	.byte	W96
	.byte	W96
	.byte		N48   
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
	.byte		N06   , Cn1 
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

bgm_thankfor_9:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*bgm_thankfor_mvl/mxv
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
	.byte		VOICE , 6
	.byte	W48
	.byte		PAN   , c_v+0
	.byte		VOL   , 21*bgm_thankfor_mvl/mxv
	.byte		BEND  , c_v+1
	.byte	W24
	.byte		N12   , Gn4 , v112
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N03   , Cn5 , v080
	.byte	W03
	.byte		N68   , Bn4 , v112
	.byte	W21
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		        Bn4 , v104
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N06   , Cs5 , v108
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		N72   , Bn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W48
	.byte		        0
	.byte	W12
	.byte		N03   , Gs4 , v096
	.byte	W03
	.byte		        Gn4 , v112
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N60   , Gn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W36
	.byte		        0
	.byte	W21
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N36   , Cn5 
	.byte	W24
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N03   , Cs5 , v080
	.byte	W03
	.byte		N44   , Cn5 , v112
	.byte	W21
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		N03   , Ds5 , v084
	.byte	W03
	.byte		        Dn5 , v076
	.byte	W03
	.byte		        Cs5 , v072
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N06   , Cn5 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		N68   , Cn5 
	.byte	W21
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 74
	.byte		VOL   , 25*bgm_thankfor_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte	W03
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 , v064
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 , v068
	.byte	W03
	.byte		        Cn5 , v072
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N36   , Bn4 
	.byte	W36
	.byte		N06   , As4 , v080
	.byte	W06
	.byte		        Bn4 , v088
	.byte	W06
	.byte		N30   , Dn4 , v096
	.byte	W36
	.byte		N03   , Dn4 , v076
	.byte	W06
	.byte		N06   , Dn4 , v088
	.byte	W06
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		        Bn4 , v104
	.byte	W24
	.byte		        Cn5 , v100
	.byte	W24
	.byte		N12   , Dn5 , v092
	.byte	W12
	.byte		N06   , Cs5 , v072
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Bn4 , v108
	.byte	W06
	.byte		        An4 , v076
	.byte	W06
	.byte		        Gn4 , v072
	.byte	W06
	.byte		        An4 , v080
	.byte	W06
	.byte		N18   , Bn4 , v112
	.byte	W18
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N24   , Gn4 , v092
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Fs4 , v076
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		        Fs4 , v084
	.byte	W06
	.byte		N48   , Gn4 
	.byte	W96
	.byte		N36   , Cn5 , v108
	.byte	W36
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N36   , En4 , v080
	.byte	W36
	.byte		N03   , En4 , v076
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
	.byte		N24   , Bn4 , v112
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        Dn5 
	.byte	W24
	.byte		N12   , En5 
	.byte	W12
	.byte		N06   , An4 , v080
	.byte	W06
	.byte		N03   , En5 , v112
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N18   , En5 
	.byte	W18
	.byte		N03   , Dn5 
	.byte	W06
	.byte		N24   , Dn5 , v096
	.byte	W36
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N18   , Dn5 
	.byte	W24
	.byte		N04   , Gn5 , v092
	.byte	W04
	.byte		        An5 , v072
	.byte	W04
	.byte		        Gn5 , v068
	.byte	W04
	.byte		        Fs5 , v092
	.byte	W04
	.byte		        Gn5 , v072
	.byte	W04
	.byte		        Fs5 , v068
	.byte	W04
	.byte		        En5 , v092
	.byte	W04
	.byte		        Fs5 , v072
	.byte	W04
	.byte		        En5 , v068
	.byte	W04
	.byte		        Dn5 , v092
	.byte	W04
	.byte		        En5 , v072
	.byte	W04
	.byte		        Dn5 , v068
	.byte	W04
	.byte		        Cn5 , v092
	.byte	W04
	.byte		        Dn5 , v072
	.byte	W04
	.byte		        Cn5 , v068
	.byte	W04
	.byte		        Bn4 , v092
	.byte	W04
	.byte		        Cn5 , v072
	.byte	W04
	.byte		        Bn4 , v068
	.byte	W04
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		PAN   , c_v+63
	.byte		VOL   , 28*bgm_thankfor_mvl/mxv
	.byte	W24
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W12
	.byte		N12   , Cs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte	W96
	.byte		VOL   , 25*bgm_thankfor_mvl/mxv
	.byte		N96   , En3 
	.byte	W48
	.byte		VOL   , 50*bgm_thankfor_mvl/mxv
	.byte	W48
	.byte		N03   , An2 
	.byte	W96
	.byte	FINE

@********************** Track 10 **********************@

bgm_thankfor_10:
	.byte	KEYSH , bgm_thankfor_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-17
	.byte		VOL   , 70*bgm_thankfor_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N21   , En3 , v064
	.byte	W24
	.byte		N24   , En3 , v096
	.byte	W24
	.byte		N21   , Fs3 , v092
	.byte	W21
	.byte		N24   , Fs3 , v080
	.byte	W24
	.byte	W03
bgm_thankfor_10_000:
	.byte	W24
	.byte		N24   , Bn2 , v088
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PEND
	.byte		        Cn3 , v076
	.byte	W24
	.byte		        Bn2 , v084
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 , v104
	.byte	W24
	.byte	W24
	.byte		        Gn2 , v088
	.byte	W24
	.byte		        Fs2 , v068
	.byte	W24
	.byte		        Gn2 , v080
	.byte	W24
	.byte		        An2 , v076
	.byte	W24
	.byte		        Gn2 , v072
	.byte	W24
	.byte		        Fs2 , v068
	.byte	W24
	.byte		        Gn2 , v084
	.byte	W24
bgm_thankfor_10_001:
	.byte	W24
	.byte		N24   , Cn3 , v088
	.byte	W24
	.byte		        Bn2 , v092
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte	PEND
bgm_thankfor_10_002:
	.byte		N24   , Dn3 , v076
	.byte	W24
	.byte		        Cn3 , v084
	.byte	W24
	.byte		        Bn2 , v092
	.byte	W24
	.byte		        Cn3 , v104
	.byte	W24
	.byte	PEND
bgm_thankfor_10_003:
	.byte	W24
	.byte		N24   , Fs3 , v088
	.byte	W24
	.byte		        En3 , v092
	.byte	W24
	.byte		        Fs3 , v104
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		N18   , Fs2 , v092
	.byte	W18
	.byte		N42   , Fs4 , v112
	.byte	W54
	.byte	PATT
	 .word	bgm_thankfor_10_000
	.byte		N24   , Cn3 , v076
	.byte	W24
	.byte		        Bn2 , v084
	.byte	W24
	.byte		        An2 , v092
	.byte	W24
	.byte		        Bn2 , v088
	.byte	W24
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Fs2 , v068
	.byte	W24
	.byte		        Gn2 , v092
	.byte	W24
	.byte		        An2 , v076
	.byte	W24
	.byte		        Gn2 , v084
	.byte	W24
	.byte		        Fs2 , v068
	.byte	W24
	.byte		        Gn2 , v104
	.byte	W24
	.byte	PATT
	 .word	bgm_thankfor_10_001
	.byte	PATT
	 .word	bgm_thankfor_10_002
	.byte	PATT
	 .word	bgm_thankfor_10_003
	.byte	W96
bgm_thankfor_10_004:
	.byte	W24
	.byte		N24   , Bn2 , v092
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte		        Gs2 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	W24
	.byte		        Cn3 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	W24
	.byte		        Fs3 
	.byte	W48
	.byte		N24   
	.byte	W24
	.byte	PATT
	 .word	bgm_thankfor_10_004
	.byte	W24
	.byte		N24   , Gs2 , v092
	.byte	W48
	.byte		        Gs2 , v120
	.byte	W24
	.byte	W24
	.byte		        Cn3 , v092
	.byte	W48
	.byte		        Dn3 
	.byte	W24
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Bn2 , v112
	.byte	W48
	.byte		VOICE , 48
	.byte		VOL   , 41*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+25
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N03   , Gn3 , v100
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N18   , Gn3 , v112
	.byte	W18
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N24   , As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N18   , En3 
	.byte	W18
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W18
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Cn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		VOL   , 14*bgm_thankfor_mvl/mxv
	.byte		N96   , Dn3 
	.byte	W09
	.byte		VOL   , 15*bgm_thankfor_mvl/mxv
	.byte	W05
	.byte		        17*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        18*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        21*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        22*bgm_thankfor_mvl/mxv
	.byte	W01
	.byte		VOICE , 48
	.byte		PAN   , c_v+41
	.byte	W02
	.byte		VOL   , 24*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        26*bgm_thankfor_mvl/mxv
	.byte	W06
	.byte		        31*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        33*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        36*bgm_thankfor_mvl/mxv
	.byte	W04
	.byte		        37*bgm_thankfor_mvl/mxv
	.byte	W02
	.byte		        40*bgm_thankfor_mvl/mxv
	.byte	W03
	.byte		        42*bgm_thankfor_mvl/mxv
	.byte	W44
	.byte	W02
	.byte		PAN   , c_v+25
	.byte		VOL   , 34*bgm_thankfor_mvl/mxv
	.byte		N36   
	.byte	W36
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N36   , Bn2 
	.byte	W36
	.byte		N06   , Gn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N36   , En3 
	.byte	W36
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N36   , Bn2 
	.byte	W36
	.byte		N06   , An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N48   , Gn2 
	.byte	W48
	.byte		N06   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W36
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N30   , Cn3 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N03   , En3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N06   , En3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N24   
	.byte	W36
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N18   , Dn4 
	.byte	W72
	.byte		VOICE , 60
	.byte		VOL   , 64*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		VOICE , 56
	.byte		PAN   , c_v+45
	.byte		VOL   , 34*bgm_thankfor_mvl/mxv
	.byte		N32   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte	W18
	.byte		        0
	.byte	W06
	.byte		N04   
	.byte	W04
	.byte		        Dn5 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N32   , Dn5 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N04   
	.byte	W04
	.byte		        Dn5 , v096
	.byte	W04
	.byte		N04   
	.byte	W04
	.byte		N24   , Bn4 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Ds4 
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
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		VOICE , 1
	.byte		PAN   , c_v+23
	.byte		VOL   , 41*bgm_thankfor_mvl/mxv
	.byte		N03   , An4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N04   , Gn5 , v096
	.byte	W04
	.byte		        An5 , v104
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        Gn5 
	.byte	W04
	.byte		        Fs5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Fs5 , v108
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        En5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Cn5 , v104
	.byte	W04
	.byte		        Dn5 , v108
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        Bn4 
	.byte	W04
	.byte		N03   , An4 , v112
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		VOICE , 46
	.byte		VOL   , 53*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-40
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		PAN   , c_v+29
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W24
	.byte	W03
	.byte		PAN   , c_v-40
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		PAN   , c_v+29
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W24
	.byte	W03
	.byte		PAN   , c_v-33
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v-16
	.byte		N03   , En4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		PAN   , c_v+33
	.byte		N03   , Bn5 
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		VOICE , 60
	.byte		PAN   , c_v-41
	.byte		VOL   , 44*bgm_thankfor_mvl/mxv
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N09   , Bn4 
	.byte	W12
	.byte		N02   , Dn5 
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N12   
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N09   
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		VOICE , 46
	.byte		PAN   , c_v-41
	.byte		VOL   , 62*bgm_thankfor_mvl/mxv
	.byte		N03   , Gn5 
	.byte	W03
	.byte		        Fn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		PAN   , c_v+39
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		PAN   , c_v-41
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		PAN   , c_v+8
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		VOICE , 14
	.byte		PAN   , c_v+32
	.byte		VOL   , 62*bgm_thankfor_mvl/mxv
	.byte		N36   , Gn4 
	.byte	W36
	.byte		N48   , Cn5 
	.byte	W48
	.byte		N06   , Dn4 
	.byte	W12
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W24
	.byte		        Bn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W36
	.byte		N36   
	.byte	W36
	.byte		N48   , As4 
	.byte	W60
	.byte	W12
	.byte		N24   , Cs5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W12
	.byte	W12
	.byte		N24   , An4 
	.byte	W24
	.byte		N36   , Dn5 
	.byte	W36
	.byte		N24   , An4 
	.byte	W24
	.byte		N24   
	.byte	W36
	.byte		        Cs5 
	.byte	W24
	.byte		N36   , An4 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 49*bgm_thankfor_mvl/mxv
	.byte		PAN   , c_v-29
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

bgm_thankfor:
	.byte	10	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_thankfor_pri	@ Priority
	.byte	bgm_thankfor_rev	@ Reverb.

	.word	bgm_thankfor_grp

	.word	bgm_thankfor_1
	.word	bgm_thankfor_2
	.word	bgm_thankfor_3
	.word	bgm_thankfor_4
	.word	bgm_thankfor_5
	.word	bgm_thankfor_6
	.word	bgm_thankfor_7
	.word	bgm_thankfor_8
	.word	bgm_thankfor_9
	.word	bgm_thankfor_10

	.end
