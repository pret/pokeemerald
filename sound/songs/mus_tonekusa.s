	.include "MPlayDef.s"

	.equ	mus_tonekusa_grp, voicegroup_868E28C
	.equ	mus_tonekusa_pri, 0
	.equ	mus_tonekusa_rev, reverb_set+50
	.equ	mus_tonekusa_mvl, 127
	.equ	mus_tonekusa_key, 0
	.equ	mus_tonekusa_tbs, 1
	.equ	mus_tonekusa_exg, 0
	.equ	mus_tonekusa_cmp, 1

	.section .rodata
	.global	mus_tonekusa
	.align	2

@********************** Track  1 **********************@

mus_tonekusa_1:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_1_B1:
	.byte	TEMPO , 148*mus_tonekusa_tbs/2
	.byte		VOICE , 24
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		N72   , Fn4 , v048
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        7
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N72   , Cn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N96   , Fn4 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        7
	.byte		VOL   , 97*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        87*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        72*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        59*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        34*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        18*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        3*mus_tonekusa_mvl/mxv
	.byte	W01
	.byte		        11*mus_tonekusa_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N72   , Gn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
mus_tonekusa_1_000:
	.byte		N24   , Fn4 , v048
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		N72   , Dn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N96   , Cn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		        7
	.byte		VOL   , 97*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        87*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        72*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        59*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        34*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        18*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        3*mus_tonekusa_mvl/mxv
	.byte	W01
	.byte		        11*mus_tonekusa_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N72   , Gn4 
	.byte	W24
	.byte		MOD   , 4
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W48
	.byte		N48   , Ds4 
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N16   
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		N48   , Dn4 
	.byte	W24
	.byte		MOD   , 2
	.byte	W24
	.byte		        0
	.byte		N48   , Fn4 
	.byte	W24
	.byte		MOD   , 2
	.byte	W24
	.byte		        0
	.byte		N48   , Gn4 
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_1_000
	.byte		N48   , Dn4 , v048
	.byte	W48
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W48
	.byte		VOICE , 73
	.byte		N03   , Fs4 , v064
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W24
	.byte		MOD   , 3
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N66   , Cn4 
	.byte	W42
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N21   , Dn4 
	.byte	W21
	.byte		N24   , Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte		N72   , Fn4 
	.byte	W48
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N44   , Gn4 
	.byte	W56
	.byte	W01
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N09   , As4 
	.byte	W09
	.byte		N03   , En4 
	.byte	W03
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N03   , Cs4 
	.byte	W03
	.byte		N44   , Dn4 
	.byte	W21
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N02   , Ds4 
	.byte	W02
	.byte		N14   , Dn4 
	.byte	W14
	.byte		N16   , Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		N72   , Cn4 
	.byte	W48
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		VOICE , 48
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Fn4 , v040
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , Gn4 , v044
	.byte	W60
	.byte		N03   , Gs4 
	.byte	W03
	.byte		N09   , Gn4 
	.byte	W09
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 , v040
	.byte	W12
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Dn4 , v032
	.byte	W24
	.byte		N12   , As3 , v040
	.byte	W48
	.byte		N48   , Ds4 
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte		N04   
	.byte	W04
	.byte		N02   , Fn4 , v044
	.byte	W02
	.byte		N10   , Ds4 
	.byte	W10
	.byte		N16   , Dn4 , v040
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fs4 , v044
	.byte	W24
	.byte		N44   , Gn4 
	.byte	W24
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte	W12
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , Gn4 , v036
	.byte	W12
	.byte		        An4 , v032
	.byte	W12
	.byte		        As4 , v040
	.byte	W12
	.byte		N24   , Dn5 , v044
	.byte	W24
	.byte		        Cn5 , v040
	.byte	W24
	.byte		        As4 , v032
	.byte	W24
	.byte		        Fn4 , v028
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N03   , Cn4 , v024
	.byte	W03
	.byte		        Dn4 , v028
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , An3 , v032
	.byte	W12
	.byte		N72   , As3 , v044
	.byte	W48
	.byte		VOL   , 89*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 59*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        5*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        100*mus_tonekusa_mvl/mxv
	.byte		MOD   , 0
	.byte	W24
	.byte		VOICE , 24
	.byte	W48
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	GOTO
	 .word	mus_tonekusa_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_tonekusa_2:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_2_B1:
	.byte		VOICE , 45
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v-15
	.byte	W24
	.byte		N12   , Fn3 , v080
	.byte	W12
	.byte		        Fn3 , v020
	.byte	W12
	.byte		        An3 , v080
	.byte	W12
	.byte		        An3 , v020
	.byte	W12
	.byte		        Cn4 , v080
	.byte	W12
	.byte		        Cn4 , v020
	.byte	W12
	.byte	W24
	.byte		        Fn3 , v076
	.byte	W12
	.byte		        Fn3 , v020
	.byte	W12
	.byte		        An3 , v076
	.byte	W12
	.byte		        An3 , v020
	.byte	W12
	.byte		        Gn3 , v080
	.byte	W12
	.byte		        Gn3 , v020
	.byte	W12
	.byte	W24
	.byte		        Ds3 , v080
	.byte	W12
	.byte		        Ds3 , v020
	.byte	W12
	.byte		        An2 , v080
	.byte	W12
	.byte		        An2 , v020
	.byte	W12
	.byte		        Cn3 , v080
	.byte	W12
	.byte		        Cn3 , v020
	.byte	W12
	.byte		        Fn2 , v080
	.byte	W12
	.byte		        Fn2 , v020
	.byte	W84
	.byte	W96
	.byte	W96
	.byte		N06   , Dn3 , v076
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		VOICE , 73
	.byte		N06   , Ds5 , v036
	.byte	W06
	.byte		N03   , Fn5 
	.byte	W03
	.byte		N15   , Ds5 
	.byte	W15
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        Cn5 , v020
	.byte	W06
	.byte		        An4 , v036
	.byte	W06
	.byte		        An4 , v020
	.byte	W06
	.byte		        Fn4 , v040
	.byte	W06
	.byte		        Fn4 , v020
	.byte	W06
	.byte		        Ds4 , v040
	.byte	W06
	.byte		        Ds4 , v020
	.byte	W06
	.byte		        Cn4 , v040
	.byte	W06
	.byte		        Cn4 , v020
	.byte	W06
	.byte		        Fn4 , v036
	.byte	W06
	.byte		        Fn4 , v020
	.byte	W06
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
	.byte	GOTO
	 .word	mus_tonekusa_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_tonekusa_3:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_3_B1:
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24   , As3 , v032
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N72   , As3 
	.byte	W72
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		N72   , Ds4 
	.byte	W72
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W48
	.byte		N48   , An3 
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        An3 
	.byte	W16
	.byte		N48   , As3 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Ds4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Cn4 
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
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tonekusa_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_tonekusa_4:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_4_B1:
	.byte		VOICE , 45
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte	W24
	.byte		N12   , Fn2 , v080
	.byte	W12
	.byte		        Fn2 , v020
	.byte	W12
	.byte		        An2 , v080
	.byte	W12
	.byte		        An2 , v020
	.byte	W12
	.byte		        Cn3 , v080
	.byte	W12
	.byte		        Cn3 , v020
	.byte	W12
	.byte	W96
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte	W24
	.byte		N24   , As2 , v064
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Gs2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Ds2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Ds2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N12   , As1 
	.byte	W24
	.byte		N24   , Ds2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N24   , As1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Gn2 , v072
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N48   , As1 
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W05
	.byte		VOL   , 61*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte	W48
	.byte		VOICE , 60
	.byte		N72   , Fn1 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        61*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N72   , As1 
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        61*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As1 
	.byte	W24
	.byte		N24   , As2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		N72   , Ds2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        61*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Ds1 
	.byte	W24
	.byte		        Fn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		        Gn2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N12   , As1 
	.byte	W24
	.byte		N24   , Ds2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
mus_tonekusa_4_000:
	.byte		MOD   , 0
	.byte		N24   , Fn1 , v072
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Fn2 
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		N24   , Fn2 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W24
	.byte		N24   , As1 
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		        Cn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_4_000
	.byte		MOD   , 0
	.byte		N72   , As1 , v072
	.byte	W24
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        62*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        40*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        19*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N48   , As1 
	.byte	W24
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N48   , Fn2 
	.byte	W24
	.byte		VOL   , 81*mus_tonekusa_mvl/mxv
	.byte		MOD   , 6
	.byte	W05
	.byte		VOL   , 62*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte		        40*mus_tonekusa_mvl/mxv
	.byte	W05
	.byte		        19*mus_tonekusa_mvl/mxv
	.byte	W07
	.byte	GOTO
	 .word	mus_tonekusa_4_B1
	.byte		MOD   , 0
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte	FINE

@********************** Track  5 **********************@

mus_tonekusa_5:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_5_B1:
	.byte		VOICE , 46
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		PAN   , c_v+12
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N12   , Ds3 , v064
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		N03   , Fn4 , v060
	.byte	W03
	.byte		        Gn4 , v056
	.byte	W03
	.byte		N06   , Fn4 , v060
	.byte	W06
	.byte		N12   , Ds4 , v056
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 , v052
	.byte	W12
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        Ds4 , v048
	.byte	W03
	.byte		N06   , Dn4 , v056
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		        Fn3 , v060
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	W12
	.byte		        Cn3 , v064
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N03   , Dn4 , v060
	.byte	W03
	.byte		        Ds4 , v056
	.byte	W03
	.byte		N06   , Dn4 , v060
	.byte	W06
	.byte		N12   , As3 
	.byte	W12
	.byte		        Fn3 , v056
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Dn3 , v044
	.byte	W03
	.byte		        Fn3 , v056
	.byte	W03
	.byte		N12   , As3 , v060
	.byte	W12
	.byte		        As3 , v024
	.byte	W36
	.byte	W24
	.byte		N06   , An4 , v060
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v060
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , An4 , v056
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v056
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , An4 , v060
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v060
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v056
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v056
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , Gn4 , v056
	.byte	W12
	.byte		N12   , Gn4 , v020
	.byte	W12
	.byte		N06   , Ds5 , v056
	.byte	W12
	.byte		N12   , Ds5 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , An4 , v056
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , Dn5 , v056
	.byte	W12
	.byte		N12   , Dn5 , v020
	.byte	W12
	.byte		N06   , As4 , v056
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v056
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , Cn5 , v056
	.byte	W12
	.byte		N12   , Cn5 , v020
	.byte	W12
	.byte		N06   , An4 , v056
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v056
	.byte	W12
	.byte		N12   , Fn4 , v016
	.byte	W12
mus_tonekusa_5_000:
	.byte		VOICE , 24
	.byte		BEND  , c_v+0
	.byte		N12   , As3 , v032
	.byte	W12
	.byte		        Ds4 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , As3 , v032
	.byte	W12
	.byte		        Gn3 , v060
	.byte	W12
	.byte		        Ds4 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		N12   , As3 , v040
	.byte	W12
	.byte		        Gn3 , v048
	.byte	W12
	.byte		        Ds4 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte	PEND
	.byte		N12   , Dn3 , v040
	.byte	W12
	.byte		        As3 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , Fn3 , v040
	.byte	W12
	.byte		        Dn3 , v056
	.byte	W12
	.byte		        As3 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , Fn3 , v040
	.byte	W12
	.byte		        Cs3 , v044
	.byte	W12
	.byte		        Dn3 , v048
	.byte	W12
	.byte		        Ds3 , v040
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , An3 , v044
	.byte	W12
	.byte		        Fn3 , v040
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , An3 , v048
	.byte	W12
	.byte		        Fn3 , v044
	.byte	W12
	.byte		        Cn4 , v056
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , Dn4 , v040
	.byte	W12
	.byte		        As3 , v060
	.byte	W12
	.byte		        Fn3 , v040
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
	.byte		        Fn3 , v044
	.byte	W12
	.byte		        Dn3 , v060
	.byte	W12
	.byte		N24   , Cs4 
	.byte	W12
	.byte		BEND  , c_v+6
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_5_000
	.byte		N12   , Dn4 , v040
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte		        As3 , v060
	.byte	W12
	.byte		        Fn3 , v048
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		        Fn3 , v052
	.byte	W12
	.byte		        As3 , v040
	.byte	W12
	.byte		        Cn4 , v056
	.byte	W12
	.byte		        Fn3 , v032
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W03
	.byte		BEND  , c_v+1
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		N12   , An3 , v048
	.byte	W12
	.byte		        Fn3 , v044
	.byte	W12
	.byte		        Cn4 
	.byte	W09
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte		N12   , An3 , v060
	.byte	W12
	.byte		        Fn3 , v044
	.byte	W12
	.byte		        Fn4 , v048
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W03
	.byte		        c_v+0
	.byte	W03
	.byte		VOICE , 45
	.byte		N12   , Fn2 , v060
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 46
	.byte		N03   , As3 , v028
	.byte	W03
	.byte		        Dn4 , v032
	.byte	W03
	.byte		        Fn4 , v040
	.byte	W03
	.byte		        An4 , v048
	.byte	W03
	.byte		N12   , As4 
	.byte	W12
	.byte		        As4 , v028
	.byte	W84
	.byte	GOTO
	 .word	mus_tonekusa_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_tonekusa_6:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_6_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v-60
	.byte		VOL   , 39*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 4*mus_tonekusa_mvl/mxv
	.byte		N72   , Dn3 , v072
	.byte	W02
	.byte		VOL   , 9*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        12*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W04
	.byte		        18*mus_tonekusa_mvl/mxv
	.byte	W02
	.byte		        20*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        23*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        25*mus_tonekusa_mvl/mxv
	.byte	W04
	.byte		        28*mus_tonekusa_mvl/mxv
	.byte		MOD   , 6
	.byte	W02
	.byte		VOL   , 29*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        33*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        34*mus_tonekusa_mvl/mxv
	.byte	W06
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W10
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		N24   , Cs3 
	.byte	W24
	.byte		VOL   , 33*mus_tonekusa_mvl/mxv
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N96   , Fn3 
	.byte	W48
	.byte		MOD   , 6
	.byte	W48
	.byte		        0
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Gn2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Ds2 
	.byte	W24
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , An2 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn2 , v064
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , As2 , v072
	.byte	W24
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N24   , As1 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		VOL   , 39*mus_tonekusa_mvl/mxv
	.byte		N12   , Cn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
mus_tonekusa_6_000:
	.byte		N12   , As3 , v072
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte	PEND
	.byte		        Fn2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_6_000
	.byte		N12   , Gn2 , v072
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_tonekusa_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_tonekusa_7:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_7_B1:
	.byte		VOICE , 81
	.byte		PAN   , c_v+63
	.byte		VOL   , 39*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 4*mus_tonekusa_mvl/mxv
	.byte		N72   , Fn3 , v072
	.byte	W02
	.byte		VOL   , 9*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        12*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        15*mus_tonekusa_mvl/mxv
	.byte	W04
	.byte		        18*mus_tonekusa_mvl/mxv
	.byte	W02
	.byte		        20*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        23*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        25*mus_tonekusa_mvl/mxv
	.byte	W04
	.byte		        28*mus_tonekusa_mvl/mxv
	.byte		MOD   , 7
	.byte	W02
	.byte		VOL   , 29*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        33*mus_tonekusa_mvl/mxv
	.byte	W03
	.byte		        34*mus_tonekusa_mvl/mxv
	.byte	W06
	.byte		        37*mus_tonekusa_mvl/mxv
	.byte	W10
	.byte		        39*mus_tonekusa_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		N24   , Fs3 
	.byte	W24
	.byte		VOL   , 31*mus_tonekusa_mvl/mxv
	.byte		N48   , Gn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
mus_tonekusa_7_000:
	.byte		MOD   , 0
	.byte		N48   , As3 , v072
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PEND
	.byte		        0
	.byte		N96   , An3 
	.byte	W48
	.byte		MOD   , 7
	.byte	W48
	.byte		        0
	.byte		N48   
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn4 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte	PATT
	 .word	mus_tonekusa_7_000
	.byte		MOD   , 0
	.byte		N48   , An3 , v072
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Fn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , As3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Dn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Cn3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N48   , Ds3 
	.byte	W24
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N24   , Fn3 
	.byte	W24
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		VOL   , 37*mus_tonekusa_mvl/mxv
	.byte		N12   , Fn2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
mus_tonekusa_7_001:
	.byte		N12   , Dn4 , v072
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
	.byte		        An2 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_7_001
	.byte		N12   , As2 , v072
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_tonekusa_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_tonekusa_8:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_8_B1:
	.byte		VOICE , 82
	.byte		PAN   , c_v+0
	.byte		VOL   , 37*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BEND  , c_v+1
	.byte		N72   , Fn4 , v064
	.byte	W72
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
mus_tonekusa_8_000:
	.byte		N72   , Cn4 , v064
	.byte	W72
	.byte		N12   , As3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte	PEND
mus_tonekusa_8_001:
	.byte		N24   , Dn4 , v064
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte	PEND
	.byte		N96   , Fn4 
	.byte	W96
	.byte		N72   , Gn4 
	.byte	W72
	.byte		N12   , An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
mus_tonekusa_8_002:
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte	PEND
	.byte		N72   , Dn4 
	.byte	W72
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N96   , Cn4 
	.byte	W96
	.byte		N72   , Gn4 
	.byte	W72
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
mus_tonekusa_8_003:
	.byte		N24   , Fn4 , v064
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , As3 
	.byte	W48
	.byte	PEND
mus_tonekusa_8_004:
	.byte		N48   , Ds4 , v064
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte	PEND
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Fn4 
	.byte	W48
mus_tonekusa_8_005:
	.byte		N48   , Gn4 , v064
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_tonekusa_8_002
	.byte		N48   , Dn4 , v064
	.byte	W48
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N18   , Cn4 
	.byte	W18
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N48   , As3 
	.byte	W48
	.byte		VOICE , 83
	.byte		N03   , Fs4 
	.byte	W03
	.byte		N09   , Fn4 
	.byte	W09
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N72   , Fn4 
	.byte	W72
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_8_000
	.byte	PATT
	 .word	mus_tonekusa_8_001
	.byte		N72   , Fn4 , v064
	.byte	W72
	.byte		N12   , Ds4 
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N09   , As4 
	.byte	W09
	.byte		N03   , En4 
	.byte	W03
	.byte	PATT
	 .word	mus_tonekusa_8_002
	.byte		N48   , Dn4 , v064
	.byte	W48
	.byte		N16   
	.byte	W16
	.byte		        Ds4 
	.byte	W16
	.byte		        Dn4 
	.byte	W16
	.byte		N72   , Cn4 
	.byte	W72
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte	PATT
	 .word	mus_tonekusa_8_003
	.byte	PATT
	 .word	mus_tonekusa_8_004
	.byte		N24   , Dn4 , v064
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte	PATT
	 .word	mus_tonekusa_8_005
	.byte		N24   , Dn5 , v064
	.byte	W24
	.byte		        Cn5 
	.byte	W24
	.byte		        As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N24   , Cn4 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N72   , As3 
	.byte	W96
	.byte	W48
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte	GOTO
	 .word	mus_tonekusa_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_tonekusa_9:
	.byte	KEYSH , mus_tonekusa_key+0
mus_tonekusa_9_B1:
	.byte		VOICE , 46
	.byte		VOL   , 100*mus_tonekusa_mvl/mxv
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+11
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N03   , Fn4 , v032
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		N24   , Fn5 , v048
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W12
	.byte		N12   , Dn5 , v020
	.byte	W12
	.byte		N06   , Ds5 , v048
	.byte	W12
	.byte		N12   , Ds5 , v020
	.byte	W12
	.byte		N06   , Fn5 , v048
	.byte	W12
	.byte		N12   , Fn5 , v020
	.byte	W12
	.byte		N06   , Gn5 , v048
	.byte	W12
	.byte		N12   , Gn5 , v020
	.byte	W36
	.byte		N06   , As5 , v048
	.byte	W12
	.byte		N12   , As5 , v020
	.byte	W36
mus_tonekusa_9_000:
	.byte		N06   , Fn5 , v048
	.byte	W12
	.byte		N12   , Fn5 , v020
	.byte	W36
	.byte		N06   , As5 , v048
	.byte	W12
	.byte		N12   , As5 , v020
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_tonekusa_9_000
	.byte		N06   , Cn5 , v048
	.byte	W12
	.byte		N12   , Cn5 , v020
	.byte	W36
	.byte		N06   , Fn5 , v048
	.byte	W12
	.byte		N12   , Fn5 , v020
	.byte	W36
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 9
	.byte	W24
	.byte		N06   , An4 , v044
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , An4 , v044
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , An4 , v044
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , Gn4 , v044
	.byte	W12
	.byte		N12   , Gn4 , v020
	.byte	W12
	.byte		N06   , Ds5 , v044
	.byte	W12
	.byte		N12   , Ds5 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte		N06   , An4 , v044
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W12
	.byte	W24
	.byte		N06   , Dn5 , v044
	.byte	W12
	.byte		N12   , Dn5 , v020
	.byte	W12
	.byte		N06   , As4 , v044
	.byte	W12
	.byte		N12   , As4 , v020
	.byte	W36
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		N12   , Fn4 , v020
	.byte	W12
	.byte		N06   , Cn5 , v044
	.byte	W12
	.byte		N12   , Cn5 , v020
	.byte	W12
	.byte		N06   , An4 , v044
	.byte	W12
	.byte		N12   , An4 , v020
	.byte	W12
	.byte		N06   , Fn4 , v044
	.byte	W12
	.byte		VOICE , 73
	.byte		N12   , Dn4 , v048
	.byte	W12
	.byte		N48   , Ds4 
	.byte	W60
	.byte		N03   , En4 
	.byte	W03
	.byte		N09   , Ds4 
	.byte	W09
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W48
	.byte		N48   , An3 
	.byte	W48
	.byte		N04   , Cn4 
	.byte	W04
	.byte		N02   , Dn4 
	.byte	W02
	.byte		N10   , Cn4 
	.byte	W10
	.byte		N16   , An3 
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		N24   , As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		N48   
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte		        Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N24   , As4 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		N48   , Fn3 
	.byte	W48
	.byte		N03   , Gn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N18   , Gn3 
	.byte	W18
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N72   
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tonekusa_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_tonekusa:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_tonekusa_pri	@ Priority
	.byte	mus_tonekusa_rev	@ Reverb.

	.word	mus_tonekusa_grp

	.word	mus_tonekusa_1
	.word	mus_tonekusa_2
	.word	mus_tonekusa_3
	.word	mus_tonekusa_4
	.word	mus_tonekusa_5
	.word	mus_tonekusa_6
	.word	mus_tonekusa_7
	.word	mus_tonekusa_8
	.word	mus_tonekusa_9

	.end
