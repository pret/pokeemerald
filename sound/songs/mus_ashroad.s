	.include "MPlayDef.s"

	.equ	mus_ashroad_grp, voicegroup_8684248
	.equ	mus_ashroad_pri, 0
	.equ	mus_ashroad_rev, reverb_set+50
	.equ	mus_ashroad_mvl, 127
	.equ	mus_ashroad_key, 0
	.equ	mus_ashroad_tbs, 1
	.equ	mus_ashroad_exg, 0
	.equ	mus_ashroad_cmp, 1

	.section .rodata
	.global	mus_ashroad
	.align	2

@********************** Track  1 **********************@

mus_ashroad_1:
	.byte	KEYSH , mus_ashroad_key+0
	.byte	TEMPO , 120*mus_ashroad_tbs/2
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		VOL   , 51*mus_ashroad_mvl/mxv
	.byte		PAN   , c_v-49
	.byte		N06   , Dn2 , v084
	.byte	W06
	.byte		        Fn2 , v080
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 , v084
	.byte	W06
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 8
	.byte		VOL   , 49*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        46*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        43*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        35*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        30*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        21*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 51*mus_ashroad_mvl/mxv
	.byte		N24   , Bn2 , v088
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
mus_ashroad_1_B1:
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W72
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En4 , v036
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N12   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		N18   , En4 
	.byte	W06
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , Bn3 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		MOD   , 7
	.byte		N06   , Cs4 , v036
	.byte	W06
	.byte		N18   , Dn4 , v112
	.byte	W06
	.byte		MOD   , 0
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N90   , En4 
	.byte	W18
	.byte		MOD   , 3
	.byte	W60
	.byte		        8
	.byte	W12
	.byte		        0
	.byte		N12   , En4 , v036
	.byte	W60
	.byte	W03
	.byte		MOD   , 0
	.byte	W12
	.byte		        7
	.byte	W09
	.byte		N12   , Fn4 , v112
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W06
	.byte		        Dn4 , v112
	.byte	W06
	.byte		N18   , En4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fn4 , v036
	.byte	W06
	.byte		MOD   , 0
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		N18   , An4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Dn5 , v036
	.byte	W06
	.byte		MOD   , 0
	.byte		N96   , Cs5 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte	W60
	.byte		        8
	.byte	W12
	.byte		        0
	.byte		N12   , Cs5 , v036
	.byte	W96
mus_ashroad_1_000:
	.byte		MOD   , 0
	.byte		N24   , Fs4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 , v036
	.byte	W36
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte	PEND
mus_ashroad_1_001:
	.byte		MOD   , 0
	.byte		N24   , Gs4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Gs4 , v036
	.byte	W36
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v036
	.byte	W06
	.byte	PEND
	.byte		MOD   , 0
	.byte		N24   , En4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , En4 , v036
	.byte	W36
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v036
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v036
	.byte	W06
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v036
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v036
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v036
	.byte	W06
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v036
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_1_000
	.byte	PATT
	 .word	mus_ashroad_1_001
	.byte		MOD   , 0
	.byte		N24   , An4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An4 , v036
	.byte	W36
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Bn4 , v036
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , Bn4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn4 , v036
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W06
	.byte		TIE   , En5 
	.byte	W24
	.byte		MOD   , 3
	.byte	W72
	.byte	W48
	.byte		        7
	.byte	W24
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N12   , En5 , v036
	.byte	W24
	.byte	GOTO
	 .word	mus_ashroad_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_ashroad_2:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 67*mus_ashroad_mvl/mxv
	.byte		N06   , Fn2 , v096
	.byte	W06
	.byte		        An2 , v104
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		N44   , Fn3 , v120
	.byte	W24
	.byte		MOD   , 4
	.byte		VOL   , 63*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        55*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        52*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        43*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        33*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        31*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 67*mus_ashroad_mvl/mxv
	.byte		N24   , Dn3 , v112
	.byte	W24
mus_ashroad_2_B1:
	.byte		VOL   , 47*mus_ashroad_mvl/mxv
	.byte		PAN   , c_v-52
	.byte		N06   , En3 , v112
	.byte	W21
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
mus_ashroad_2_000:
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		N03   
	.byte	W09
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
	.byte	PEND
mus_ashroad_2_001:
	.byte		N06   , En3 , v112
	.byte	W21
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_2_000
	.byte	PATT
	 .word	mus_ashroad_2_001
	.byte	PATT
	 .word	mus_ashroad_2_000
	.byte	PATT
	 .word	mus_ashroad_2_001
	.byte	PATT
	 .word	mus_ashroad_2_000
	.byte	PATT
	 .word	mus_ashroad_2_001
mus_ashroad_2_002:
	.byte		VOL   , 47*mus_ashroad_mvl/mxv
	.byte		N06   , En3 , v112
	.byte	W12
	.byte		N03   
	.byte	W09
	.byte		        Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Fn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Gn3 
	.byte	W12
	.byte	PEND
	.byte		        Fs3 
	.byte	W21
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , An3 
	.byte	W12
mus_ashroad_2_003:
	.byte		N06   , Gs3 , v112
	.byte	W21
	.byte		N03   , An3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        Gs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gs3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , An3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Bn3 
	.byte	W12
	.byte	PEND
	.byte		        En3 
	.byte	W21
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        En3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W21
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , As2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W12
	.byte		VOL   , 47*mus_ashroad_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W21
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		        Fs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Fs3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Gs3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , An3 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_2_003
	.byte		N06   , An3 , v112
	.byte	W21
	.byte		N03   , As3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        An3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        An3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W21
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Bn3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Cn4 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Dn4 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_2_001
	.byte	PATT
	 .word	mus_ashroad_2_002
	.byte	GOTO
	 .word	mus_ashroad_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_ashroad_3:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 58
	.byte		VOL   , 76*mus_ashroad_mvl/mxv
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		N06   , Dn2 , v112
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N48   , Fn1 , v120
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 76*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        73*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        67*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        62*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        59*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        56*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        52*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        49*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 76*mus_ashroad_mvl/mxv
	.byte		N24   , Gs1 , v112
	.byte	W24
mus_ashroad_3_B1:
	.byte		VOICE , 38
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N12   , Bn1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
mus_ashroad_3_000:
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N12   , Bn1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_3_000
	.byte	PATT
	 .word	mus_ashroad_3_000
	.byte	PATT
	 .word	mus_ashroad_3_000
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N12   , Bn1 , v040
	.byte	W18
	.byte		N03   , Gs1 , v112
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N18   , Gs1 
	.byte	W18
	.byte		N06   , An1 
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N12   , Bn1 , v040
	.byte	W12
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
mus_ashroad_3_001:
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N12   , Bn1 , v040
	.byte	W12
	.byte		N06   , Bn1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_3_001
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W12
	.byte		N06   , An1 , v112
	.byte	W06
	.byte		N12   , En1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 , v127
	.byte	W18
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		N12   , An0 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N12   , Dn1 , v032
	.byte	W30
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N12   , En1 , v127
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W12
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Cs1 , v127
	.byte	W18
	.byte		N06   , Cs1 , v112
	.byte	W06
	.byte		N12   , Gs0 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Fs1 , v127
	.byte	W18
	.byte		N06   , Fs1 , v112
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Fs1 , v127
	.byte	W12
	.byte		N12   , En1 , v112
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Dn1 , v127
	.byte	W18
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		N12   , An0 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N12   , Dn1 , v032
	.byte	W30
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , En1 , v127
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , Bn0 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , En1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Bn1 
	.byte	W12
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Fn1 , v127
	.byte	W18
	.byte		N06   , Fn1 , v112
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N12   , Gn1 , v127
	.byte	W18
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		        Gn1 , v127
	.byte	W06
	.byte		N03   , Dn2 , v112
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , Dn1 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_3_000
	.byte		N06   , An1 , v127
	.byte	W06
	.byte		N12   , An1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N12   , En1 , v040
	.byte	W18
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte	GOTO
	 .word	mus_ashroad_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_ashroad_4:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 81
	.byte		VOL   , 47*mus_ashroad_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		LFOS  , 44
	.byte	W96
mus_ashroad_4_B1:
mus_ashroad_4_000:
	.byte		N06   , Cs3 , v112
	.byte	W21
	.byte		N03   , Dn3 , v056
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En3 
	.byte	W12
	.byte	PEND
mus_ashroad_4_001:
	.byte		N06   , Cs3 , v112
	.byte	W12
	.byte		N03   
	.byte	W09
	.byte		        Dn3 , v056
	.byte	W03
	.byte		        Cs3 , v112
	.byte	W03
	.byte		        Cs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        En3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_4_000
	.byte	PATT
	 .word	mus_ashroad_4_001
	.byte	PATT
	 .word	mus_ashroad_4_000
	.byte	PATT
	 .word	mus_ashroad_4_001
	.byte	PATT
	 .word	mus_ashroad_4_000
	.byte	PATT
	 .word	mus_ashroad_4_001
	.byte	PATT
	 .word	mus_ashroad_4_000
	.byte	PATT
	 .word	mus_ashroad_4_001
mus_ashroad_4_002:
	.byte		N06   , An2 , v112
	.byte	W21
	.byte		N03   , As2 , v064
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		        An2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        An2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Bn2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Cs3 
	.byte	W12
	.byte	PEND
mus_ashroad_4_003:
	.byte		N06   , Bn2 , v112
	.byte	W21
	.byte		N03   , Cn3 , v064
	.byte	W03
	.byte		        Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Cs3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Dn3 
	.byte	W12
	.byte	PEND
	.byte		        Gs2 
	.byte	W21
	.byte		N03   , An2 , v064
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Fs2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Gs2 
	.byte	W12
	.byte		        Fs2 
	.byte	W21
	.byte		N03   , Gn2 , v064
	.byte	W03
	.byte		        Fs2 , v112
	.byte	W03
	.byte		        Fs2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fs2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Cs2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Fs2 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_4_002
	.byte	PATT
	 .word	mus_ashroad_4_003
	.byte		N06   , Cn3 , v112
	.byte	W21
	.byte		N03   , Cs3 , v064
	.byte	W03
	.byte		        Cn3 , v112
	.byte	W03
	.byte		        Cn3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W21
	.byte		N03   , Ds3 , v064
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , En3 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W12
	.byte		        Cs2 
	.byte	W21
	.byte		N03   , Dn2 , v064
	.byte	W03
	.byte		        Cs2 , v112
	.byte	W03
	.byte		        Cs2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        En2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		N03   
	.byte	W09
	.byte		        Dn2 , v064
	.byte	W03
	.byte		        Cs2 , v112
	.byte	W03
	.byte		        Cs2 , v080
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        En2 , v112
	.byte	W12
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte		N24   , Dn2 
	.byte	W02
	.byte		VOL   , 27*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        32*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        38*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        41*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        45*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        54*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        57*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        47*mus_ashroad_mvl/mxv
	.byte		N06   , En2 
	.byte	W12
	.byte	GOTO
	 .word	mus_ashroad_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_ashroad_5:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 38
	.byte		PAN   , c_v+51
	.byte		VOL   , 28*mus_ashroad_mvl/mxv
	.byte		N06   , Fn3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N48   , Fn4 , v120
	.byte	W24
	.byte		VOL   , 28*mus_ashroad_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 25*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        23*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        21*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		        19*mus_ashroad_mvl/mxv
	.byte	W02
	.byte		        16*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        14*mus_ashroad_mvl/mxv
	.byte	W03
	.byte		        13*mus_ashroad_mvl/mxv
	.byte	W04
	.byte		MOD   , 0
	.byte		VOL   , 28*mus_ashroad_mvl/mxv
	.byte		N24   , Dn4 , v088
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
mus_ashroad_5_B1:
	.byte		VOICE , 38
	.byte		MOD   , 0
	.byte		VOL   , 31*mus_ashroad_mvl/mxv
	.byte		PAN   , c_v+51
	.byte		N06   , En3 , v072
	.byte	W96
	.byte	W96
	.byte		MOD   , 0
	.byte		N24   , Cs3 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Cs3 , v040
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        An3 , v040
	.byte	W03
	.byte		N12   , An2 , v112
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Bn2 
	.byte	W18
	.byte		N06   , As2 
	.byte	W06
	.byte		N15   , An2 
	.byte	W15
	.byte		N03   , An2 , v040
	.byte	W03
	.byte		        An2 , v112
	.byte	W03
	.byte		N06   , An2 , v040
	.byte	W09
	.byte		N03   , An2 , v112
	.byte	W03
	.byte		        An2 , v040
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		N06   , Gs2 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , En2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Dn2 , v040
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v040
	.byte	W06
	.byte		N12   , En2 , v112
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        An2 , v040
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N03   , Fn3 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Bn2 , v040
	.byte	W06
	.byte		        Cs3 , v112
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N18   , Dn3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W09
	.byte		N12   , As2 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		        0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Cs3 , v040
	.byte	W12
	.byte		        An2 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N06   , Dn3 , v040
	.byte	W06
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte		N12   , Dn3 , v040
	.byte	W15
	.byte		        An2 , v112
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
	.byte		        Ds3 , v112
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , As2 
	.byte	W06
	.byte		N12   , An2 
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En3 
	.byte	W06
	.byte		        En3 , v040
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , En3 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Dn3 , v040
	.byte	W06
	.byte		N12   , Dn3 , v112
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , En3 
	.byte	W12
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Bn2 , v040
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        An2 , v040
	.byte	W06
	.byte		        Gs2 , v112
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		VOL   , 29*mus_ashroad_mvl/mxv
	.byte		N21   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs4 
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
mus_ashroad_5_000:
	.byte		MOD   , 0
	.byte		N21   , En4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , Cn4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	PEND
	.byte		MOD   , 0
	.byte		N21   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , An3 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N12   , Cs4 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        As3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Cs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N21   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Fs4 
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
	.byte	PATT
	 .word	mus_ashroad_5_000
	.byte		MOD   , 0
	.byte		N21   , Fn4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , As3 
	.byte	W03
	.byte		MOD   , 0
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		MOD   , 0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		TIE   , An4 
	.byte	W24
	.byte		MOD   , 3
	.byte	W72
	.byte	W48
	.byte		        7
	.byte	W24
	.byte		EOT   
	.byte		MOD   , 0
	.byte	W24
	.byte	GOTO
	 .word	mus_ashroad_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_ashroad_6:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 82
	.byte		VOL   , 38*mus_ashroad_mvl/mxv
	.byte		LFOS  , 44
	.byte		BEND  , c_v-3
	.byte	W96
mus_ashroad_6_B1:
	.byte		MOD   , 0
	.byte	W96
	.byte	W72
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , En4 , v040
	.byte	W06
	.byte		N03   , An3 , v112
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , Fn4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N18   , En4 
	.byte	W06
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn3 , v040
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v040
	.byte	W06
	.byte		N18   , Dn4 , v112
	.byte	W06
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N90   , En4 
	.byte	W18
	.byte		MOD   , 3
	.byte	W60
	.byte		        8
	.byte	W12
	.byte		        0
	.byte		N12   , En4 , v040
	.byte	W84
	.byte		        Fn4 , v112
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N03   , An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N06   , Fn4 
	.byte	W06
	.byte		N03   , Gn4 
	.byte	W03
	.byte		        Fn4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		N18   , En4 
	.byte	W18
	.byte		N06   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W06
	.byte		N18   , An4 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Dn5 , v040
	.byte	W06
	.byte		N96   , Cs5 , v112
	.byte	W24
	.byte		MOD   , 3
	.byte	W60
	.byte		        8
	.byte	W12
	.byte		        0
	.byte		N12   , Cs5 , v040
	.byte	W96
mus_ashroad_6_000:
	.byte		N24   , Fs4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 , v040
	.byte	W36
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v040
	.byte	W06
	.byte	PEND
mus_ashroad_6_001:
	.byte		N24   , Gs4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Gs4 , v040
	.byte	W36
	.byte		N06   , Gs4 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An4 , v040
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        Gs4 , v040
	.byte	W06
	.byte	PEND
	.byte		N24   , En4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , En4 , v040
	.byte	W36
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Fs4 , v040
	.byte	W06
	.byte		        Gs4 , v112
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        En4 , v040
	.byte	W06
	.byte		N12   , Fs4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		N06   , En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v040
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Cs4 , v040
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v040
	.byte	W06
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v040
	.byte	W06
	.byte		        Fs4 , v112
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte	PATT
	 .word	mus_ashroad_6_000
	.byte	PATT
	 .word	mus_ashroad_6_001
	.byte		N24   , An4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An4 , v040
	.byte	W36
	.byte		N06   , An4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Bn4 , v040
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An4 , v040
	.byte	W06
	.byte		N24   , Bn4 , v112
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn4 , v040
	.byte	W24
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N96   , En5 
	.byte	W24
	.byte		MOD   , 3
	.byte	W72
	.byte		N12   , En5 , v040
	.byte	W48
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W24
	.byte	GOTO
	 .word	mus_ashroad_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_ashroad_7:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v-63
	.byte		VOL   , 51*mus_ashroad_mvl/mxv
	.byte	W96
mus_ashroad_7_B1:
mus_ashroad_7_000:
	.byte		N01   , Gn4 , v112
	.byte	W24
	.byte		N01   
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v060
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W12
	.byte		N01   
	.byte	W24
	.byte		N01   
	.byte	W03
	.byte		        Gn4 , v052
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
mus_ashroad_7_001:
	.byte		N01   , Gn4 , v112
	.byte	W12
	.byte		        Gn4 , v096
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v060
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W12
	.byte		N01   
	.byte	W24
	.byte		N01   
	.byte	W03
	.byte		        Gn4 , v052
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_001
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_001
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_001
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_001
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_000
	.byte	PATT
	 .word	mus_ashroad_7_001
	.byte	GOTO
	 .word	mus_ashroad_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_ashroad_8:
	.byte	KEYSH , mus_ashroad_key+0
	.byte		VOICE , 0
	.byte		VOL   , 76*mus_ashroad_mvl/mxv
	.byte	W96
mus_ashroad_8_B1:
mus_ashroad_8_000:
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		N03   , Dn3 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	mus_ashroad_8_000
	.byte	PATT
	 .word	mus_ashroad_8_000
	.byte	PATT
	 .word	mus_ashroad_8_000
mus_ashroad_8_001:
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        Dn3 , v096
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_ashroad_8_000
	.byte	PATT
	 .word	mus_ashroad_8_000
	.byte	PATT
	 .word	mus_ashroad_8_000
	.byte	PATT
	 .word	mus_ashroad_8_001
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		N12   , As1 , v088
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		N12   , As1 , v088
	.byte	W12
	.byte		N03   , En1 , v080
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W18
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        Dn3 , v112
	.byte	W06
	.byte		        Cn1 , v124
	.byte	W12
	.byte		        Dn3 , v092
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		        En1 , v088
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N12   , As1 , v088
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		N12   , As1 , v088
	.byte	W12
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W24
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 , v124
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N06   , Cn1 , v124
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		N12   , As1 , v092
	.byte	W12
	.byte		N06   , En1 , v120
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N03   , Fs1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 , v124
	.byte		N48   , An2 , v100
	.byte	W12
	.byte		N06   , En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        En3 , v096
	.byte	W06
	.byte		        En3 , v080
	.byte	W06
	.byte		        Cn1 , v088
	.byte	W12
	.byte		        Dn3 , v096
	.byte	W12
	.byte	GOTO
	 .word	mus_ashroad_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_ashroad:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_ashroad_pri	@ Priority
	.byte	mus_ashroad_rev	@ Reverb.

	.word	mus_ashroad_grp

	.word	mus_ashroad_1
	.word	mus_ashroad_2
	.word	mus_ashroad_3
	.word	mus_ashroad_4
	.word	mus_ashroad_5
	.word	mus_ashroad_6
	.word	mus_ashroad_7
	.word	mus_ashroad_8

	.end
