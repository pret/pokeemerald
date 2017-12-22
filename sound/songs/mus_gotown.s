	.include "MPlayDef.s"

	.equ	mus_gotown_grp, voicegroup_8680AB0
	.equ	mus_gotown_pri, 0
	.equ	mus_gotown_rev, reverb_set+50
	.equ	mus_gotown_mvl, 127
	.equ	mus_gotown_key, 0
	.equ	mus_gotown_tbs, 1
	.equ	mus_gotown_exg, 0
	.equ	mus_gotown_cmp, 1

	.section .rodata
	.global	mus_gotown
	.align	2

@********************** Track  1 **********************@

mus_gotown_1:
	.byte	KEYSH , mus_gotown_key+0
	.byte	TEMPO , 128*mus_gotown_tbs/2
	.byte		VOICE , 6
	.byte		PAN   , c_v-64
	.byte		XCMD  , xIECV , 12
	.byte		        xIECL , 8
	.byte		LFOS  , 44
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W12
	.byte	W72
mus_gotown_1_B1:
	.byte		VOICE , 6
	.byte	W18
	.byte		N03   , As3 , v068
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , An3 , v112
	.byte	W12
mus_gotown_1_000:
	.byte		N01   , An3 , v080
	.byte	W12
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		N01   , An3 , v080
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N01   , An3 , v080
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte	PEND
mus_gotown_1_001:
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cn4 , v068
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte	PEND
mus_gotown_1_002:
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte	PEND
mus_gotown_1_003:
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cn4 , v068
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte	PEND
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N01   , Gs3 , v080
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		VOICE , 3
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N36   , Fs3 , v112
	.byte	W15
	.byte		MOD   , 9
	.byte	W21
	.byte		        2
	.byte		N36   , Cn3 
	.byte	W12
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte	W12
	.byte		N36   , As2 
	.byte	W12
	.byte		MOD   , 9
	.byte	W24
	.byte		        2
	.byte	W48
	.byte		N36   
	.byte	W12
	.byte		MOD   , 9
	.byte	W12
	.byte	W09
	.byte		        2
	.byte	W03
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W03
	.byte		VOICE , 6
	.byte	W03
	.byte		N03   , As3 , v068
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , An3 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_1_000
	.byte	PATT
	 .word	mus_gotown_1_001
	.byte	PATT
	 .word	mus_gotown_1_002
	.byte	PATT
	 .word	mus_gotown_1_003
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		N01   , Bn3 , v080
	.byte	W12
	.byte		N06   , Bn3 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		VOICE , 3
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N36   , Fn3 , v112
	.byte	W12
	.byte		MOD   , 9
	.byte	W21
	.byte		        1
	.byte	W03
	.byte		N36   , Cn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte	W12
	.byte		N36   , As2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte	W12
	.byte		N36   , Ds3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        1
	.byte	W24
	.byte		VOICE , 6
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		N01   , Ds4 , v080
	.byte	W12
mus_gotown_1_004:
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		N01   , Fn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Fn4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	PEND
	.byte		VOICE , 3
	.byte		N24   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Bn3 
	.byte	W09
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte	W03
	.byte		N06   , Cn4 
	.byte	W12
	.byte		MOD   , 8
	.byte		N06   , Bn3 
	.byte	W12
	.byte		MOD   , 1
	.byte		N12   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte		N03   , Cs4 , v064
	.byte	W03
	.byte		        Bn3 , v056
	.byte	W03
	.byte		        As3 , v048
	.byte	W03
	.byte		        Gs3 , v040
	.byte	W03
	.byte		VOICE , 6
	.byte		MOD   , 1
	.byte	W24
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		N01   , Ds4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
mus_gotown_1_005:
	.byte		N01   , Ds4 , v080
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		N01   , Ds4 , v080
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W06
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte	PEND
	.byte		VOICE , 3
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N12   , Gn3 
	.byte	W12
	.byte		MOD   , 8
	.byte		N03   , Bn3 , v056
	.byte	W03
	.byte		        Dn4 , v068
	.byte	W03
	.byte		        Fn4 , v080
	.byte	W03
	.byte		        Gn4 , v084
	.byte	W03
	.byte		VOICE , 6
	.byte		MOD   , 1
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W24
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W12
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N01   , Dn4 , v080
	.byte	W12
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N01   , Cn4 , v080
	.byte	W09
	.byte		N03   , Cs4 , v068
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_1_004
	.byte		VOICE , 3
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N24   , Cn4 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Bn3 
	.byte	W15
	.byte		MOD   , 8
	.byte	W09
	.byte		N06   , Cn4 
	.byte	W03
	.byte		MOD   , 1
	.byte	W09
	.byte		        8
	.byte		N06   , Bn3 
	.byte	W12
	.byte		MOD   , 1
	.byte		N12   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte		N03   , Cs4 , v072
	.byte	W03
	.byte		        Bn3 , v064
	.byte	W03
	.byte		        As3 , v052
	.byte	W03
	.byte		        Gs3 , v044
	.byte	W03
	.byte		VOICE , 6
	.byte		MOD   , 1
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W24
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte		N01   , Ds4 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , Ds4 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_1_005
	.byte		N06   , Cn4 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N01   , As3 , v080
	.byte	W12
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		N01   , An3 , v080
	.byte	W12
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		N01   , Fn3 , v080
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte	GOTO
	 .word	mus_gotown_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_gotown_2:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		VOL   , 82*mus_gotown_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v112
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N02   , An3 , v124
	.byte	W02
	.byte		        As3 
	.byte	W02
	.byte		N08   , An3 , v112
	.byte	W08
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
mus_gotown_2_B1:
	.byte		VOL   , 46*mus_gotown_mvl/mxv
	.byte		N48   , Fn3 , v112
	.byte	W04
	.byte		VOL   , 49*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        52*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        54*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        61*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        81*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        85*mus_gotown_mvl/mxv
	.byte	W16
	.byte		MOD   , 1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gn4 
	.byte	W09
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N12   , Fn4 
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		VOL   , 46*mus_gotown_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W04
	.byte		VOL   , 49*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        52*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        54*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        61*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        81*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        85*mus_gotown_mvl/mxv
	.byte	W16
	.byte		MOD   , 1
	.byte	W12
	.byte		N12   , Ds4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		VOL   , 44*mus_gotown_mvl/mxv
	.byte		N42   , Gn3 
	.byte	W04
	.byte		VOL   , 50*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        54*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        58*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        70*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        80*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 5
	.byte		VOL   , 84*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        85*mus_gotown_mvl/mxv
	.byte	W20
	.byte		MOD   , 1
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N32   , As3 
	.byte	W15
	.byte		MOD   , 5
	.byte	W18
	.byte		N03   , Bn3 
	.byte	W03
	.byte		MOD   , 1
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
	.byte	W09
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N12   , An3 
	.byte	W24
	.byte		N36   , Fn3 
	.byte	W18
	.byte		MOD   , 5
	.byte	W18
	.byte		        1
	.byte		N03   , Gn3 , v068
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		N06   , En4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N21   , Fn4 
	.byte	W09
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte		N06   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W24
	.byte		N02   , Fs4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		VOICE , 48
	.byte		PAN   , c_v+28
	.byte		VOL   , 40*mus_gotown_mvl/mxv
	.byte		N21   , Cn4 
	.byte	W21
	.byte		N03   , Cs4 
	.byte	W03
	.byte		N09   , Dn4 
	.byte	W09
	.byte		N03   , Bn3 
	.byte	W03
	.byte		N48   , As3 
	.byte	W48
	.byte		N06   , An3 
	.byte	W12
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N06   , An3 
	.byte	W24
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		N24   , As3 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N09   , Ds4 
	.byte	W09
	.byte		N03   , Cs4 
	.byte	W03
	.byte		N48   , Cn4 
	.byte	W48
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		N09   , As3 
	.byte	W09
	.byte		N06   , An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N36   , As3 
	.byte	W36
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N48   , An3 
	.byte	W48
	.byte		        Gn3 , v096
	.byte	W48
	.byte		N12   , Fs3 , v088
	.byte	W12
	.byte		        Gs3 , v096
	.byte	W12
	.byte		        As3 , v108
	.byte	W12
	.byte		        Cn4 , v112
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		N24   , Cs4 
	.byte	W24
	.byte		VOL   , 36*mus_gotown_mvl/mxv
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N36   , Cn4 
	.byte	W36
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N06   , As3 , v056
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		VOL   , 47*mus_gotown_mvl/mxv
	.byte		N04   , Cn5 , v068
	.byte	W04
	.byte		        As4 
	.byte	W05
	.byte		        An4 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Cn5 
	.byte	W05
	.byte		VOL   , 54*mus_gotown_mvl/mxv
	.byte		N04   , Dn5 , v076
	.byte	W04
	.byte		        Cn5 
	.byte	W05
	.byte		        As4 
	.byte	W05
	.byte		        Cn5 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte		N04   , Ds5 , v092
	.byte	W04
	.byte		        Dn5 
	.byte	W05
	.byte		        Cn5 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		VOL   , 64*mus_gotown_mvl/mxv
	.byte		N04   , Fn5 , v100
	.byte	W04
	.byte		        Ds5 
	.byte	W05
	.byte		        Dn5 
	.byte	W05
	.byte		        Ds5 
	.byte	W05
	.byte		        Fn5 
	.byte	W05
	.byte		VOL   , 69*mus_gotown_mvl/mxv
	.byte		N12   , Gn5 , v112
	.byte	W12
	.byte		N03   , Fn5 , v064
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N24   , Gn4 , v108
	.byte	W24
	.byte		N06   , Gn4 , v032
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		N03   , An4 , v032
	.byte	W03
	.byte		        Cs5 , v080
	.byte	W03
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		N06   , Cn5 , v032
	.byte	W12
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W18
	.byte		        Dn5 , v112
	.byte	W06
	.byte		        Dn5 , v032
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N48   , Fn5 
	.byte	W15
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        56*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        52*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        51*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        47*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        45*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        41*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        37*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        34*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        30*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        29*mus_gotown_mvl/mxv
	.byte		N06   , Fn5 , v032
	.byte	W02
	.byte		VOL   , 26*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        68*mus_gotown_mvl/mxv
	.byte	W06
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		        Fn5 , v112
	.byte	W06
	.byte		        Fn5 , v032
	.byte	W06
	.byte		N24   , Gn5 , v112
	.byte	W12
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        55*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        50*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        46*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        62*mus_gotown_mvl/mxv
	.byte		N24   , Fn5 
	.byte	W12
	.byte		VOL   , 58*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        52*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        47*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        45*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Bn4 , v112
	.byte	W06
	.byte		        Bn4 , v032
	.byte	W06
	.byte		N12   , Cn5 , v112
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		N03   , Cs5 , v064
	.byte	W03
	.byte		        Dn5 , v072
	.byte	W03
	.byte		N36   , Ds5 , v112
	.byte	W12
	.byte		VOL   , 58*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        55*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        50*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        45*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        37*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        34*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        31*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W18
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		N24   , An4 , v112
	.byte	W24
	.byte		N06   , An4 , v032
	.byte	W12
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W06
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W18
	.byte		N24   , An4 , v112
	.byte	W12
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte	W12
	.byte		        64*mus_gotown_mvl/mxv
	.byte		N06   , Fn4 
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte		N96   , Dn5 , v112
	.byte	W24
	.byte		VOL   , 61*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        57*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        53*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        50*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        46*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        37*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        33*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        26*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        24*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        21*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        22*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        24*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        26*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        28*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        36*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        37*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        40*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        46*mus_gotown_mvl/mxv
	.byte	W01
	.byte		        48*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        55*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        51*mus_gotown_mvl/mxv
	.byte	W01
	.byte		        60*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        55*mus_gotown_mvl/mxv
	.byte	W01
	.byte		        64*mus_gotown_mvl/mxv
	.byte	W02
	.byte		        58*mus_gotown_mvl/mxv
	.byte	W01
	.byte		        71*mus_gotown_mvl/mxv
	.byte	W03
	.byte		VOICE , 17
	.byte		VOL   , 53*mus_gotown_mvl/mxv
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N03   , Fn5 , v064
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N24   , As4 , v108
	.byte	W36
	.byte		N06   , As4 , v112
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn5 
	.byte	W24
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W36
	.byte		N24   
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W24
	.byte		N24   , Ds5 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N06   , As4 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Dn5 
	.byte	W24
	.byte		        Ds5 
	.byte	W24
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        An4 
	.byte	W24
	.byte		        Fn4 
	.byte	W12
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 78*mus_gotown_mvl/mxv
	.byte		N12   , As3 
	.byte	W12
	.byte		N02   , An3 , v092
	.byte	W02
	.byte		        As3 , v088
	.byte	W02
	.byte		N08   , An3 , v112
	.byte	W08
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	GOTO
	 .word	mus_gotown_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_gotown_3:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		PAN   , c_v+63
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		N12   , An4 , v112
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N02   , An4 , v124
	.byte	W02
	.byte		        As4 
	.byte	W02
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
mus_gotown_3_B1:
	.byte		VOICE , 4
	.byte		MOD   , 2
	.byte		VOL   , 22*mus_gotown_mvl/mxv
	.byte		N48   , Fn4 , v112
	.byte	W04
	.byte		VOL   , 25*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        28*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        31*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        34*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        36*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        38*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        40*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W01
	.byte		MOD   , 8
	.byte	W15
	.byte		        2
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N09   , Gn5 
	.byte	W09
	.byte		N03   , Fs5 
	.byte	W03
	.byte		N12   , Fn5 
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		        Ds5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		VOL   , 22*mus_gotown_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W04
	.byte		VOL   , 25*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        28*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        31*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        34*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        36*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        38*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        40*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte	W12
	.byte		        2
	.byte	W12
	.byte		N12   , Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W12
	.byte		VOL   , 22*mus_gotown_mvl/mxv
	.byte		N42   , Gn4 
	.byte	W04
	.byte		VOL   , 25*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        28*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        31*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        34*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        36*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 38*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        40*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        42*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 2
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N32   , As4 
	.byte	W18
	.byte		MOD   , 8
	.byte	W12
	.byte		        2
	.byte	W03
	.byte		N03   , Bn4 
	.byte	W03
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        2
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte	W09
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N12   , An4 
	.byte	W24
	.byte		N36   , Fn4 
	.byte	W21
	.byte		MOD   , 8
	.byte	W15
	.byte		        2
	.byte		N03   , Gn4 , v068
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		N06   , En5 , v112
	.byte	W06
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N36   , Cs3 
	.byte	W15
	.byte		MOD   , 3
	.byte	W21
	.byte		N36   , Gs2 
	.byte	W03
	.byte		MOD   , 1
	.byte	W09
	.byte		        5
	.byte	W24
	.byte		        1
	.byte	W12
	.byte		N36   , Gn2 
	.byte	W12
	.byte	W60
	.byte		N24   , Fs2 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N12   , Cs3 
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N36   
	.byte	W15
	.byte		MOD   , 4
	.byte	W21
	.byte		        1
	.byte		N36   , Gs2 
	.byte	W12
	.byte		MOD   , 4
	.byte	W24
	.byte		VOICE , 4
	.byte		PAN   , c_v+63
	.byte		MOD   , 1
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N06   , Cn4 
	.byte	W12
	.byte		VOL   , 85*mus_gotown_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		N12   , An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		VOICE , 7
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , Fn4 , v064
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N24   , Gn3 , v108
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		        An3 
	.byte	W09
	.byte		N03   , Cs4 , v064
	.byte	W03
	.byte		N12   , Cn4 , v112
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , As3 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        1
	.byte	W12
	.byte		N06   , Ds4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N24   , Fn4 
	.byte	W15
	.byte		MOD   , 4
	.byte	W09
	.byte		        1
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Cs4 , v064
	.byte	W03
	.byte		        Dn4 , v072
	.byte	W03
	.byte		N36   , Ds4 , v112
	.byte	W15
	.byte		MOD   , 4
	.byte	W18
	.byte		        1
	.byte	W03
	.byte		N06   , As3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , An3 
	.byte	W36
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W24
	.byte		N24   , An4 
	.byte	W24
	.byte		N06   , Fn4 
	.byte	W12
	.byte		N96   , Dn5 
	.byte	W48
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 10
	.byte		MOD   , 1
	.byte		PAN   , c_v+32
	.byte		N12   , Gn5 
	.byte	W12
	.byte		N03   , Fn5 , v064
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		N24   , As4 , v108
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N06   , As4 , v032
	.byte	W12
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte	W12
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		        Dn5 , v112
	.byte	W06
	.byte		        Dn5 , v032
	.byte	W18
	.byte		N24   , Ds5 , v112
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W15
	.byte		MOD   , 4
	.byte	W09
	.byte		        1
	.byte		N06   , Dn5 , v032
	.byte	W12
	.byte		N24   , Dn5 , v112
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        1
	.byte		N06   , Cs5 
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		        Cs5 , v112
	.byte	W06
	.byte		        Cs5 , v032
	.byte	W06
	.byte		N12   , Dn5 , v112
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N06   , Fn5 
	.byte	W06
	.byte		        Fn5 , v032
	.byte	W18
	.byte		N24   , Ds5 , v112
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W03
	.byte		MOD   , 1
	.byte	W03
	.byte		N06   , Ds5 
	.byte	W06
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W24
	.byte		N06   , As4 
	.byte	W06
	.byte		        As4 , v032
	.byte	W30
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		        Ds5 , v112
	.byte	W06
	.byte		        Ds5 , v032
	.byte	W06
	.byte		N24   , Dn5 , v112
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N24   , Ds5 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        1
	.byte		N12   , Fn5 
	.byte	W12
	.byte		N06   , En5 
	.byte	W06
	.byte		        Ds5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Dn5 , v032
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        Gn4 , v112
	.byte	W06
	.byte		        Gn4 , v032
	.byte	W18
	.byte		        An4 , v112
	.byte	W06
	.byte		        An4 , v032
	.byte	W18
	.byte		        Fn4 , v112
	.byte	W06
	.byte		        Fn4 , v032
	.byte	W06
	.byte	W12
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		        As4 , v112
	.byte	W06
	.byte		        As4 , v032
	.byte	W06
	.byte		VOICE , 4
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N12   , As4 , v112
	.byte	W12
	.byte		N02   , An4 , v092
	.byte	W02
	.byte		        As4 , v088
	.byte	W02
	.byte		N08   , An4 , v112
	.byte	W08
	.byte		N12   , Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte	GOTO
	 .word	mus_gotown_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_gotown_4:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 38
	.byte		VOL   , 85*mus_gotown_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W12
	.byte	W48
	.byte		VOICE , 38
	.byte	W12
	.byte		N12   , An1 , v112
	.byte	W12
mus_gotown_4_B1:
	.byte		BEND  , c_v+0
	.byte		N24   , As1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W24
mus_gotown_4_000:
	.byte		N24   , Cn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N24   , Cn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W24
	.byte		        Fn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N18   , Ds2 , v112
	.byte	W18
	.byte		N06   , Fn1 , v127
	.byte	W06
mus_gotown_4_001:
	.byte		N36   , Fs2 , v127
	.byte	W36
	.byte		        Cs2 
	.byte	W48
	.byte		        Cn2 
	.byte	W12
	.byte	PEND
	.byte	W36
	.byte		        Bn1 
	.byte	W48
	.byte		N03   , An1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , As1 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn2 
	.byte	W36
	.byte		N06   , Fn1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Cn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Gn2 
	.byte	W36
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N03   , Ds2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Fn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W24
	.byte		        Fn1 , v127
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Gs2 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , Gs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PATT
	 .word	mus_gotown_4_001
	.byte	W36
	.byte		N36   , Fn2 , v127
	.byte	W48
	.byte		N03   , Dn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N24   , Ds2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   , As1 
	.byte	W12
	.byte		        Ds2 , v112
	.byte	W24
	.byte		        As1 , v127
	.byte	W12
mus_gotown_4_002:
	.byte		N24   , Dn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , An1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N24   , Dn2 
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N24   , Gs1 , v112
	.byte	W24
	.byte		N06   , Dn2 , v127
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W36
	.byte		N06   , Ds2 
	.byte	W12
	.byte		N24   , Gn1 
	.byte	W36
	.byte		N06   , Gs1 
	.byte	W12
	.byte		N24   , An1 
	.byte	W36
	.byte		N06   , Fn2 
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W36
	.byte		N06   , An1 
	.byte	W12
	.byte		N24   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , As1 , v112
	.byte	W24
	.byte		N06   , Fn1 , v127
	.byte	W12
	.byte		N24   , Gs2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N03   , Dn2 
	.byte	W06
	.byte		        Dn2 , v112
	.byte	W06
	.byte		N24   , Gn2 , v127
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W12
	.byte		N24   , Ds2 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		N24   , Ds2 , v112
	.byte	W24
	.byte		N06   , As1 , v127
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_4_002
	.byte		N24   , Dn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Cn2 , v112
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	PATT
	 .word	mus_gotown_4_000
	.byte		N24   , Cn2 , v127
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Fs1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , As1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn1 
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Fn1 , v112
	.byte	W03
	.byte		BEND  , c_v-7
	.byte	W03
	.byte		        c_v-15
	.byte	W03
	.byte		        c_v-25
	.byte	W03
	.byte		        c_v-36
	.byte	W03
	.byte		        c_v-42
	.byte	W03
	.byte		        c_v-61
	.byte	W06
	.byte	GOTO
	 .word	mus_gotown_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_gotown_5:
	.byte	KEYSH , mus_gotown_key+0
	.byte		LFOS  , 44
	.byte		PAN   , c_v-32
	.byte		VOL   , 73*mus_gotown_mvl/mxv
	.byte	W03
	.byte		        74*mus_gotown_mvl/mxv
	.byte	W09
	.byte		VOICE , 17
	.byte	W72
mus_gotown_5_B1:
	.byte		PAN   , c_v-32
	.byte	W24
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        69*mus_gotown_mvl/mxv
	.byte	W48
	.byte		N12   , Gs4 , v112
	.byte	W12
	.byte		N02   , Fs4 , v100
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N12   , Fn4 , v104
	.byte	W12
	.byte		        Ds4 , v112
	.byte	W12
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte		N06   , Fn5 
	.byte	W06
	.byte		N30   , Fn4 
	.byte	W18
	.byte		MOD   , 3
	.byte	W12
	.byte		        1
	.byte		N06   , Fn5 , v084
	.byte	W06
	.byte		N18   , Fn4 , v088
	.byte	W15
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W03
	.byte		N06   , Fn5 , v096
	.byte	W06
	.byte		N18   , Fn4 , v108
	.byte	W06
	.byte	W12
	.byte		N06   , Fn5 , v112
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		VOL   , 64*mus_gotown_mvl/mxv
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v-13
	.byte		VOL   , 66*mus_gotown_mvl/mxv
	.byte		N48   , Fn4 
	.byte	W04
	.byte		VOL   , 67*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        69*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        73*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        77*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        80*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte	W24
	.byte		        1
	.byte		VOL   , 78*mus_gotown_mvl/mxv
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn5 
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte	W12
	.byte		N02   , Fn5 , v080
	.byte	W02
	.byte		        Gn5 
	.byte	W02
	.byte		N08   , Fn5 , v112
	.byte	W20
	.byte		N12   , Ds5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N03   , Cn5 , v064
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte		N48   , Dn5 , v112
	.byte	W04
	.byte		VOL   , 45*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        46*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        49*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        52*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        56*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        73*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        77*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        79*mus_gotown_mvl/mxv
	.byte	W08
	.byte		MOD   , 1
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W12
	.byte		N12   , Ds5 
	.byte	W24
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N06   , As4 
	.byte	W24
	.byte		N12   , Gn4 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		VOL   , 44*mus_gotown_mvl/mxv
	.byte		N36   , As4 
	.byte	W04
	.byte		VOL   , 49*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        62*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        67*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        68*mus_gotown_mvl/mxv
	.byte	W04
	.byte		        72*mus_gotown_mvl/mxv
	.byte	W04
	.byte		MOD   , 3
	.byte		VOL   , 74*mus_gotown_mvl/mxv
	.byte	W12
	.byte		MOD   , 1
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W36
	.byte		N06   , Gn4 
	.byte	W12
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		        Gn4 
	.byte	W12
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N02   , Fs4 
	.byte	W02
	.byte		        Gs4 
	.byte	W02
	.byte		N08   , Fs4 
	.byte	W08
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N09   , Ds4 
	.byte	W09
	.byte		N03   , En5 
	.byte	W03
	.byte		VOL   , 72*mus_gotown_mvl/mxv
	.byte		N06   , Fn5 
	.byte	W12
	.byte		        As4 , v104
	.byte	W12
	.byte		        Cn5 
	.byte	W09
	.byte		N03   , Fs5 , v064
	.byte	W03
	.byte		N21   , Fn5 , v100
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        1
	.byte		N06   , As4 , v092
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		N24   , Fn5 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        1
	.byte		N06   , As4 , v104
	.byte	W12
	.byte		        Cn5 , v108
	.byte	W12
	.byte		N36   , Fn5 
	.byte	W24
	.byte		MOD   , 3
	.byte	W12
	.byte		        1
	.byte		N24   , Fs5 , v112
	.byte	W24
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
	 .word	mus_gotown_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_gotown_6:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 1
	.byte		XCMD  , xIECV , 12
	.byte		        xIECV , 8
	.byte		VOL   , 36*mus_gotown_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W12
	.byte	W72
mus_gotown_6_B1:
	.byte		VOICE , 1
	.byte	W18
	.byte		N03   , Cn3 , v068
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
mus_gotown_6_000:
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cs3 , v088
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
mus_gotown_6_001:
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte	PEND
mus_gotown_6_002:
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_gotown_6_001
mus_gotown_6_003:
	.byte		VOICE , 2
	.byte		N36   , As2 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		N36   , Fn2 
	.byte	W03
	.byte		MOD   , 1
	.byte	W09
	.byte		        8
	.byte	W24
	.byte	W03
	.byte		        1
	.byte	W09
	.byte		N36   , Ds2 
	.byte	W12
	.byte	PEND
	.byte		MOD   , 8
	.byte	W24
	.byte	W03
	.byte		        1
	.byte	W21
	.byte		N36   
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W03
	.byte		MOD   , 1
	.byte	W09
	.byte	W15
	.byte		VOICE , 1
	.byte	W03
	.byte		N03   , Cn3 , v080
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W12
	.byte		N06   , Dn3 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_6_000
	.byte	W12
	.byte		N01   , Dn3 , v080
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N03   , Cs3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte		N01   , Ds3 , v080
	.byte	W12
	.byte		N06   , Ds3 , v112
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_6_001
	.byte	PATT
	 .word	mus_gotown_6_002
	.byte	PATT
	 .word	mus_gotown_6_001
	.byte	PATT
	 .word	mus_gotown_6_003
	.byte		MOD   , 8
	.byte	W24
	.byte	W03
	.byte		        1
	.byte	W09
	.byte		N36   , An2 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte	W03
	.byte		        1
	.byte	W21
	.byte		VOICE , 1
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N01   , Gn3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		N01   , Gn3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
mus_gotown_6_004:
	.byte		N01   , Fs3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Fs3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		N01   , Fs3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		N01   , Fs3 , v080
	.byte	W12
	.byte	PEND
mus_gotown_6_005:
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		N01   , An3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		N01   , Fn3 , v080
	.byte	W12
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
	.byte		VOICE , 2
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N03   , Fs3 , v064
	.byte	W03
	.byte		        En3 , v056
	.byte	W03
	.byte		        Ds3 , v048
	.byte	W03
	.byte		        Cs3 , v040
	.byte	W03
mus_gotown_6_006:
	.byte		VOICE , 1
	.byte		MOD   , 1
	.byte	W24
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		N01   , Gn3 , v080
	.byte	W12
	.byte		N01   
	.byte	W12
	.byte		N06   , Gn3 , v112
	.byte	W12
	.byte		N01   , Gn3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_gotown_6_004
	.byte		VOICE , 2
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N24   , Fn2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N06   , As2 
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N12   , Bn2 
	.byte	W12
	.byte		MOD   , 8
	.byte		N03   , Dn3 , v064
	.byte	W03
	.byte		        Fn3 , v076
	.byte	W03
	.byte		        Gn3 , v080
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte	PATT
	 .word	mus_gotown_6_006
	.byte		N01   , Fs3 , v080
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , Fs3 , v080
	.byte	W09
	.byte		N03   , Fn3 , v068
	.byte	W03
	.byte		N06   , Fs3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_6_005
	.byte		VOICE , 2
	.byte		N24   , Gs3 , v112
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N24   , Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        1
	.byte		N06   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 8
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N03   , Fs3 , v072
	.byte	W03
	.byte		        En3 , v064
	.byte	W03
	.byte		        Ds3 , v052
	.byte	W03
	.byte		        Cs3 , v044
	.byte	W03
	.byte	PATT
	 .word	mus_gotown_6_006
	.byte	PATT
	 .word	mus_gotown_6_004
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N01   , As2 , v080
	.byte	W12
	.byte		N06   , Fn2 , v112
	.byte	W12
	.byte		N01   , Fn2 , v080
	.byte	W12
	.byte		N06   , As2 , v112
	.byte	W12
	.byte		N01   , As2 , v080
	.byte	W12
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte	GOTO
	 .word	mus_gotown_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_gotown_7:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 127
	.byte		PAN   , c_v-62
	.byte		VOL   , 42*mus_gotown_mvl/mxv
	.byte	W12
	.byte	W72
mus_gotown_7_B1:
mus_gotown_7_000:
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
mus_gotown_7_001:
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		        An4 , v104
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
	.byte	PATT
	 .word	mus_gotown_7_000
	.byte	PATT
	 .word	mus_gotown_7_001
mus_gotown_7_002:
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte	PEND
mus_gotown_7_003:
	.byte		N06   , An4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte	PEND
	.byte		        An4 , v112
	.byte	W12
	.byte		        An4 , v064
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		        An4 , v112
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , An4 , v064
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		        An4 , v064
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	mus_gotown_7_002
	.byte	PATT
	 .word	mus_gotown_7_003
	.byte	PATT
	 .word	mus_gotown_7_002
	.byte	W12
	.byte		N03   , En4 , v112
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , An4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N15   , En4 
	.byte	W24
	.byte	GOTO
	 .word	mus_gotown_7_B1
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

mus_gotown_8:
	.byte	KEYSH , mus_gotown_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*mus_gotown_mvl/mxv
	.byte	W12
	.byte	W60
	.byte		N06   , Fs1 , v100
	.byte	W06
	.byte		        Fs1 , v080
	.byte	W06
mus_gotown_8_B1:
mus_gotown_8_000:
	.byte		N06   , En3 , v100
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
mus_gotown_8_001:
	.byte		N06   , Fs1 , v100
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs1 
	.byte	W06
	.byte		        Fs1 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte	PATT
	 .word	mus_gotown_8_000
	.byte	PATT
	 .word	mus_gotown_8_001
	.byte		VOL   , 64*mus_gotown_mvl/mxv
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v124
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W06
	.byte		N03   , Dn1 , v072
	.byte	W03
	.byte		        Dn1 , v076
	.byte	W03
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 , v116
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        En1 , v120
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Cn1 , v100
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v116
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En3 , v100
	.byte	W12
mus_gotown_8_002:
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte	PEND
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte	PATT
	 .word	mus_gotown_8_002
	.byte		N06   , Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Dn3 , v100
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        Fs2 , v100
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Cn1 , v127
	.byte	W12
	.byte		        En3 , v100
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        Dn1 , v100
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		N12   , As1 , v088
	.byte	W12
	.byte	GOTO
	 .word	mus_gotown_8_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_gotown:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_gotown_pri	@ Priority
	.byte	mus_gotown_rev	@ Reverb.

	.word	mus_gotown_grp

	.word	mus_gotown_1
	.word	mus_gotown_2
	.word	mus_gotown_3
	.word	mus_gotown_4
	.word	mus_gotown_5
	.word	mus_gotown_6
	.word	mus_gotown_7
	.word	mus_gotown_8

	.end
