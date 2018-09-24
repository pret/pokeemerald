	.include "MPlayDef.s"

	.equ	mus_rg_tamamusi_grp, voicegroup168
	.equ	mus_rg_tamamusi_pri, 0
	.equ	mus_rg_tamamusi_rev, reverb_set+50
	.equ	mus_rg_tamamusi_mvl, 127
	.equ	mus_rg_tamamusi_key, 0
	.equ	mus_rg_tamamusi_tbs, 1
	.equ	mus_rg_tamamusi_exg, 0
	.equ	mus_rg_tamamusi_cmp, 1

	.section .rodata
	.global	mus_rg_tamamusi
	.align	2

@********************** Track  1 **********************@

mus_rg_tamamusi_1:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte	TEMPO , 110*mus_rg_tamamusi_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 26*mus_rg_tamamusi_mvl/mxv
	.byte		N36   , Fs3 , v120
	.byte	W36
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Dn3 , v127
	.byte	W24
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
mus_rg_tamamusi_1_B1:
	.byte		VOL   , 26*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        15*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 26*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Bn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Cn4 , v108
	.byte	W12
	.byte		N48   , An3 , v127
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , An3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N36   , An3 
	.byte	W12
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        24*mus_rg_tamamusi_mvl/mxv
	.byte		N06   
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        Cn4 , v104
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		        An3 , v127
	.byte	W12
	.byte		N12   , Bn3 
	.byte	W12
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W06
	.byte		VOL   , 16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 25*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn4 , v088
	.byte	W06
	.byte		VOL   , 15*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 26*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn3 , v127
	.byte	W06
	.byte		VOL   , 16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 24*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Bn3 
	.byte	W24
	.byte		N12   , Gn3 
	.byte	W12
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Bn3 
	.byte	W06
	.byte		VOL   , 16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		MOD   , 7
	.byte	W03
	.byte		VOL   , 7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 24*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cn4 , v108
	.byte	W12
	.byte		N48   , An3 , v127
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Cn4 , v108
	.byte	W12
	.byte		N06   , Bn3 , v127
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 , v120
	.byte	W06
	.byte		MOD   , 7
	.byte		N12   , Fs3 
	.byte	W12
	.byte		MOD   , 0
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N48   , An3 
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        24*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Bn3 
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Cn4 , v096
	.byte	W12
	.byte		N48   , Bn3 , v127
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        24*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , An3 
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
mus_rg_tamamusi_1_000:
	.byte		MOD   , 0
	.byte		N24   , An3 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W06
	.byte		VOL   , 15*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 7
	.byte		VOL   , 26*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , An3 
	.byte	W06
	.byte		VOL   , 15*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        26*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		N48   , Bn3 
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Cn4 , v104
	.byte	W12
	.byte		N48   , Bn3 , v127
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        24*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , An3 
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        26*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PATT
	 .word	mus_rg_tamamusi_1_000
	.byte		N48   , An2 , v120
	.byte	W24
	.byte		VOL   , 21*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		        12*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        7*mus_rg_tamamusi_mvl/mxv
	.byte	W09
	.byte		        26*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W12
	.byte		VOL   , 19*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        16*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        25*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_tamamusi_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_tamamusi_2:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Dn4 , v127
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N48   , An4 
	.byte	W30
	.byte		VOL   , 54*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        61*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        70*mus_rg_tamamusi_mvl/mxv
	.byte	W06
mus_rg_tamamusi_2_B1:
	.byte		VOICE , 73
	.byte		VOL   , 65*mus_rg_tamamusi_mvl/mxv
	.byte		N24   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Gn4 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N48   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		VOL   , 56*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_tamamusi_mvl/mxv
	.byte		N24   
	.byte	W24
	.byte		N06   , Fs4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 56*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   
	.byte	W12
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Gn4 
	.byte	W24
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N24   , Gn4 
	.byte	W12
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N48   , An4 
	.byte	W12
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W36
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte		N12   
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , En4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W12
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W36
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Dn5 
	.byte	W12
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W36
	.byte		VOICE , 60
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Dn4 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N03   , An3 
	.byte	W03
	.byte		        Bn3 , v096
	.byte	W03
	.byte		N06   , An3 , v108
	.byte	W06
	.byte		        Gn3 , v120
	.byte	W06
	.byte		        Bn3 , v127
	.byte	W06
	.byte		N24   , En4 , v096
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 , v127
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		VOL   , 45*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 39*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        28*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        22*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		VOICE , 73
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Dn4 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 61*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , Cn4 , v127
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 61*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 65*mus_rg_tamamusi_mvl/mxv
	.byte		N48   , Cn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 61*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 69*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOL   , 61*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        55*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        50*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 68*mus_rg_tamamusi_mvl/mxv
	.byte		N03   , Dn4 , v120
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 , v068
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 , v076
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cn5 
	.byte	W03
	.byte		        Cs5 , v088
	.byte	W03
	.byte		N30   , Dn5 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W06
	.byte		VOL   , 56*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 69*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Cn5 
	.byte	W06
	.byte		N03   , An4 , v100
	.byte	W03
	.byte		        Fs4 , v092
	.byte	W03
	.byte		        En4 , v084
	.byte	W03
	.byte		        Dn4 , v072
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_tamamusi_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_tamamusi_3:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W48
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
mus_rg_tamamusi_3_B1:
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N06   , Dn2 , v127
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 , v127
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		        Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N06   , An2 , v127
	.byte	W06
	.byte		        Cn3 , v120
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 , v127
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cn3 , v120
	.byte	W06
	.byte		        Dn2 , v127
	.byte	W06
	.byte		        Fs2 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , An2 , v127
	.byte	W06
	.byte		        Cn3 , v120
	.byte	W06
	.byte		        Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N09   , An2 
	.byte	W09
	.byte		N03   , Cs3 , v120
	.byte	W03
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Cn3 , v120
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N06   , Bn2 , v127
	.byte	W06
	.byte		        An2 , v120
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W06
	.byte		N03   , Fs2 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N06   , Dn3 , v127
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , Bn2 , v127
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N06   , Bn2 , v127
	.byte	W06
	.byte		        En2 , v120
	.byte	W06
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Bn2 , v127
	.byte	W06
	.byte		        Gn2 , v120
	.byte	W06
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , An2 
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		PAN   , c_v+62
	.byte		N06   , Fs2 , v127
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		N12   , Dn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N06   , En2 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W06
	.byte		        Gs1 , v120
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N36   , Dn2 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W03
	.byte		PAN   , c_v+62
	.byte		VOL   , 22*mus_rg_tamamusi_mvl/mxv
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte		N12   , Fs2 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
mus_rg_tamamusi_3_000:
	.byte		N12   , Gn2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte	PEND
mus_rg_tamamusi_3_001:
	.byte		PAN   , c_v+63
	.byte		N12   , Gn2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn3 
	.byte	W12
	.byte	PEND
mus_rg_tamamusi_3_002:
	.byte		N12   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+62
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+63
	.byte		N12   , Fs2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Cn3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_tamamusi_3_000
	.byte	PATT
	 .word	mus_rg_tamamusi_3_001
	.byte	PATT
	 .word	mus_rg_tamamusi_3_002
	.byte		PAN   , c_v+63
	.byte		N12   , Fs2 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N12   , En2 
	.byte	W12
	.byte		N36   , Dn2 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 22*mus_rg_tamamusi_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 34*mus_rg_tamamusi_mvl/mxv
	.byte	W03
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		N24   , Fs2 
	.byte	W12
	.byte		MOD   , 8
	.byte	W12
	.byte		        0
	.byte		N24   , An2 
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte	GOTO
	 .word	mus_rg_tamamusi_3_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_tamamusi_4:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 53*mus_rg_tamamusi_mvl/mxv
	.byte		MOD   , 2
	.byte	W96
mus_rg_tamamusi_4_B1:
mus_rg_tamamusi_4_000:
	.byte		N12   , Gn1 , v120
	.byte	W12
	.byte		N06   , Gn2 , v096
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Gn2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte	PEND
mus_rg_tamamusi_4_001:
	.byte	W12
	.byte		N06   , Gn2 , v096
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte	PEND
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   , Cn3 , v096
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		N12   , Dn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn2 , v120
	.byte	W12
	.byte		N12   , Cn2 , v100
	.byte	W12
	.byte		N06   , Bn1 , v120
	.byte	W12
	.byte		N12   , An1 , v104
	.byte	W12
	.byte	PATT
	 .word	mus_rg_tamamusi_4_000
	.byte	PATT
	 .word	mus_rg_tamamusi_4_001
	.byte		N12   , Dn2 , v120
	.byte	W12
	.byte		        Dn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Cs1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N48   , An1 
	.byte	W24
	.byte		VOL   , 44*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        38*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        34*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        29*mus_rg_tamamusi_mvl/mxv
	.byte	W06
	.byte		        53*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , Fs1 
	.byte	W12
mus_rg_tamamusi_4_002:
	.byte		N12   , Gn1 , v120
	.byte	W42
	.byte		N06   , Fs1 , v096
	.byte	W06
	.byte		N12   , Gn1 , v120
	.byte	W48
	.byte	PEND
mus_rg_tamamusi_4_003:
	.byte		N12   , Gn1 , v120
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte		N18   , Dn2 
	.byte	W18
	.byte		N06   , Cs2 
	.byte	W06
	.byte	PEND
mus_rg_tamamusi_4_004:
	.byte		N12   , Dn1 , v120
	.byte	W42
	.byte		N06   , Cs1 , v096
	.byte	W06
	.byte		N12   , Dn1 , v120
	.byte	W48
	.byte	PEND
mus_rg_tamamusi_4_005:
	.byte		N12   , Dn1 , v120
	.byte	W42
	.byte		N06   , Cs1 , v096
	.byte	W06
	.byte		        Dn1 , v120
	.byte	W12
	.byte		N18   
	.byte	W18
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_tamamusi_4_002
	.byte	PATT
	 .word	mus_rg_tamamusi_4_003
	.byte	PATT
	 .word	mus_rg_tamamusi_4_004
	.byte	PATT
	 .word	mus_rg_tamamusi_4_005
	.byte		N48   , Dn1 , v120
	.byte	W48
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W18
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_tamamusi_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_tamamusi_5:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 25*mus_rg_tamamusi_mvl/mxv
	.byte	W48
	.byte		N06   , Dn4 , v127
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
mus_rg_tamamusi_5_B1:
	.byte		VOICE , 45
	.byte		VOL   , 50*mus_rg_tamamusi_mvl/mxv
	.byte	W12
	.byte		N12   , Dn4 , v112
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W36
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   , Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W36
	.byte	W96
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , Dn5 
	.byte	W24
	.byte		N06   , Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 , v080
	.byte	W06
	.byte		N12   , Dn5 , v112
	.byte	W48
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
	 .word	mus_rg_tamamusi_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_tamamusi_6:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 43*mus_rg_tamamusi_mvl/mxv
	.byte	W96
mus_rg_tamamusi_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 48
	.byte		PAN   , c_v-32
	.byte		VOL   , 37*mus_rg_tamamusi_mvl/mxv
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
mus_rg_tamamusi_6_000:
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte	PEND
mus_rg_tamamusi_6_001:
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte	PEND
	.byte		        Dn2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_tamamusi_6_000
	.byte	PATT
	 .word	mus_rg_tamamusi_6_000
	.byte	PATT
	 .word	mus_rg_tamamusi_6_001
	.byte		N06   , Dn2 , v120
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N03   , Fs3 , v116
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs3 , v080
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N30   , An3 , v120
	.byte	W30
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_tamamusi_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_tamamusi_7:
	.byte	KEYSH , mus_rg_tamamusi_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 64*mus_rg_tamamusi_mvl/mxv
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N12   , En3 , v108
	.byte	W12
mus_rg_tamamusi_7_B1:
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W36
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N06   , Gs2 , v064
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		N12   , En3 , v108
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gs2 , v068
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		        En3 , v108
	.byte	W06
	.byte		        Gs2 , v068
	.byte	W06
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs2 , v084
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Fs2 , v108
	.byte	W12
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N06   , Gs2 , v068
	.byte	W06
	.byte		        Dn3 , v080
	.byte	W06
	.byte		        En3 , v108
	.byte	W06
	.byte		        Gs2 , v068
	.byte	W06
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N06   , Gs2 , v080
	.byte	W06
	.byte		        Dn3 , v088
	.byte	W06
	.byte		        En3 , v108
	.byte	W06
	.byte		        Gs2 , v068
	.byte	W06
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		        Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Gs2 , v084
	.byte	W06
	.byte		        Dn3 , v096
	.byte	W06
	.byte		        En3 , v104
	.byte	W06
	.byte		        Gs2 , v064
	.byte	W06
	.byte		N12   , Fs2 
	.byte	W12
	.byte		        Fs2 , v024
	.byte	W12
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Fs2 , v084
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Fs2 , v108
	.byte	W12
mus_rg_tamamusi_7_000:
	.byte		N12   , Bn4 , v056
	.byte	W12
	.byte		N09   , Bn4 , v024
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   , Bn4 , v044
	.byte	W12
	.byte		N09   , Bn4 , v024
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte	PATT
	 .word	mus_rg_tamamusi_7_000
	.byte		N03   , Fs2 , v076
	.byte	W03
	.byte		        Fs2 , v036
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Fs2 , v064
	.byte	W12
	.byte		        Fs2 , v088
	.byte	W12
	.byte		N24   , Bn4 , v048
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_tamamusi_7_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_tamamusi:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_tamamusi_pri	@ Priority
	.byte	mus_rg_tamamusi_rev	@ Reverb.

	.word	mus_rg_tamamusi_grp

	.word	mus_rg_tamamusi_1
	.word	mus_rg_tamamusi_2
	.word	mus_rg_tamamusi_3
	.word	mus_rg_tamamusi_4
	.word	mus_rg_tamamusi_5
	.word	mus_rg_tamamusi_6
	.word	mus_rg_tamamusi_7

	.end
