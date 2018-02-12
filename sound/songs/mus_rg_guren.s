	.include "MPlayDef.s"

	.equ	mus_rg_guren_grp, voicegroup_86A35D4
	.equ	mus_rg_guren_pri, 0
	.equ	mus_rg_guren_rev, reverb_set+50
	.equ	mus_rg_guren_mvl, 127
	.equ	mus_rg_guren_key, 0
	.equ	mus_rg_guren_tbs, 1
	.equ	mus_rg_guren_exg, 0
	.equ	mus_rg_guren_cmp, 1

	.section .rodata
	.global	mus_rg_guren
	.align	2

@********************** Track  1 **********************@

mus_rg_guren_1:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte	TEMPO , 120*mus_rg_guren_tbs/2
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 28*mus_rg_guren_mvl/mxv
	.byte		N03   , Dn3 , v104
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , An2 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
mus_rg_guren_1_B1:
	.byte	W24
	.byte		N24   , Dn3 , v104
	.byte	W24
	.byte		N36   , En3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		N24   , Bn2 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N36   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W24
	.byte		        Gn3 
	.byte	W24
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		VOICE , 24
	.byte		VOL   , 45*mus_rg_guren_mvl/mxv
	.byte		N06   , Dn5 , v108
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N06   
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v-32
	.byte		VOL   , 28*mus_rg_guren_mvl/mxv
	.byte		N36   , Bn3 , v104
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N48   , Dn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N36   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		N48   , En3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N36   , Fs4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        18*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N48   , Gn3 
	.byte	W48
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N36   , Bn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        18*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N48   , Dn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N36   , Cn4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        18*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , An3 
	.byte	W12
	.byte		N48   , Fs3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N36   , En4 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        18*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N48   , Gn3 
	.byte	W12
	.byte		VOL   , 22*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        19*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        17*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        28*mus_rg_guren_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N03   , Dn3 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Gn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , En3 
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , An2 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_guren_2:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 17
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N03   , Gn4 , v096
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Bn4 , v076
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N06   , Dn4 , v096
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
mus_rg_guren_2_B1:
	.byte		N36   , Gn4 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        73*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
mus_rg_guren_2_000:
	.byte		N24   , En5 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	PEND
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        73*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 89*mus_rg_guren_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        72*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_guren_2_000
	.byte		N24   , Dn5 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N36   , Dn4 , v064
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N48   , Gn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N48   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        71*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		VOICE , 24
	.byte		MOD   , 0
	.byte		N06   , Bn4 , v056
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Dn5 , v064
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        69*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N18   , Gn4 
	.byte	W18
	.byte		N03   , An4 , v048
	.byte	W03
	.byte		        Gn4 , v052
	.byte	W03
	.byte		N12   , Fs4 , v064
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , En5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        70*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 79*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		        70*mus_rg_guren_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_guren_mvl/mxv
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Dn5 
	.byte	W18
	.byte		N06   , Fs5 
	.byte	W06
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		VOICE , 17
	.byte		N03   , Gn4 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		N24   
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An4 
	.byte	W06
	.byte		N03   , Bn4 , v060
	.byte	W03
	.byte		        An4 , v064
	.byte	W03
	.byte		N06   , Dn4 , v092
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_guren_3:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+39
	.byte		VOL   , 40*mus_rg_guren_mvl/mxv
	.byte		N03   , Bn2 , v120
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
mus_rg_guren_3_B1:
mus_rg_guren_3_000:
	.byte		N06   , Gn3 , v127
	.byte	W18
	.byte		N01   
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N01   , Gn4 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte	PEND
	.byte		        Gn3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W18
	.byte		N01   
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N01   , Gn4 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W18
	.byte		N01   
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N01   , Fs4 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		N03   , Gs3 , v120
	.byte	W06
	.byte	PATT
	 .word	mus_rg_guren_3_000
	.byte		N06   , Gn3 , v127
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   , Gn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N01   , Gn4 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W03
	.byte		N01   
	.byte	W03
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W24
	.byte		N03   , An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   , En4 
	.byte	W06
	.byte		N01   , En4 , v100
	.byte	W06
	.byte		N03   , En4 , v127
	.byte	W06
	.byte		N01   , En4 , v100
	.byte	W06
	.byte		N06   , Bn3 , v127
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W24
	.byte		N12   , En4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
mus_rg_guren_3_001:
	.byte		N06   , Bn3 , v127
	.byte	W12
	.byte		        Gn3 , v120
	.byte	W06
	.byte		N03   , An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N12   , Dn4 , v127
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , As3 
	.byte	W12
	.byte	PEND
	.byte		N06   , Bn3 
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   , Gn4 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N01   , An3 
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W18
	.byte		N03   , Cn4 , v120
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N01   , En4 
	.byte	W06
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N12   , An4 
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_guren_3_001
	.byte		N03   , Bn2 , v120
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_guren_4:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 58*mus_rg_guren_mvl/mxv
	.byte		N06   , Gn1 , v120
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W24
	.byte		N24   , An1 
	.byte	W24
mus_rg_guren_4_B1:
	.byte		N24   , Dn2 , v120
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte		N06   , Bn1 
	.byte	W24
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        En2 
	.byte	W06
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N24   , Dn2 
	.byte	W24
	.byte		        Bn1 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        Gn1 
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn2 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        Dn2 
	.byte	W24
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N24   , Dn1 
	.byte	W24
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte		N06   , Fs1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N12   , Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn1 
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   , An1 
	.byte	W12
	.byte		N06   , Gn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		N06   , An1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		        Dn2 
	.byte	W24
	.byte		N24   , An1 
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_guren_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_guren_5:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 92
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 19*mus_rg_guren_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N03   , Gn4 , v120
	.byte	W12
	.byte		N24   
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An4 , v096
	.byte	W06
	.byte		N03   , Bn4 , v084
	.byte	W03
	.byte		        An4 , v120
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
mus_rg_guren_5_B1:
	.byte		N36   , Gn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N36   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
mus_rg_guren_5_000:
	.byte		N24   , Dn5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , Gn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte	PEND
mus_rg_guren_5_001:
	.byte		N24   , En5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	PEND
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N06   , An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N18   , Cn5 
	.byte	W18
	.byte		N06   , Bn4 , v120
	.byte	W06
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Dn5 , v127
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_guren_5_000
	.byte	PATT
	 .word	mus_rg_guren_5_001
	.byte		N24   , Dn5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N48   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N36   , En5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N48   , An4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N24   , An4 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Dn5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N18   , Gn4 
	.byte	W18
	.byte		N03   , An4 , v084
	.byte	W03
	.byte		        Gn4 , v068
	.byte	W03
	.byte		N12   , Fs4 , v120
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		N36   , En5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Cn5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 , v120
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N36   , An5 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , Fs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N18   , Dn5 
	.byte	W18
	.byte		N06   , Fs5 , v120
	.byte	W06
	.byte		N12   , En5 , v127
	.byte	W12
	.byte		        Dn5 , v120
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 , v127
	.byte	W12
	.byte		N03   , Gn4 , v120
	.byte	W12
	.byte		MOD   , 7
	.byte		N24   
	.byte	W12
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , An4 , v096
	.byte	W06
	.byte		N03   , Bn4 , v084
	.byte	W03
	.byte		        An4 , v120
	.byte	W03
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N12   , Fs4 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_guren_6:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 46*mus_rg_guren_mvl/mxv
	.byte		N03   , Gn2 , v120
	.byte	W12
	.byte		N18   , Dn2 
	.byte	W24
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
mus_rg_guren_6_B1:
	.byte		N06   , Bn2 , v127
	.byte	W18
	.byte		N01   
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N01   , Bn3 
	.byte	W24
	.byte		N03   , Dn3 , v092
	.byte	W03
	.byte		N01   , Dn3 , v072
	.byte	W03
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W06
	.byte		N01   , Gn3 , v127
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		N15   , Dn3 , v120
	.byte	W15
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N01   , Fs3 , v127
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W18
	.byte		N01   
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N01   , Bn3 
	.byte	W24
	.byte		N03   , Dn3 , v092
	.byte	W03
	.byte		N01   , Dn3 , v072
	.byte	W03
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N01   , Gn3 , v072
	.byte	W06
	.byte		N06   , Bn2 , v120
	.byte	W18
	.byte		N01   , Bn2 , v127
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Dn3 , v120
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N01   , Dn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W12
	.byte		N01   
	.byte	W06
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Cn3 
	.byte	W06
	.byte		N06   , Bn2 , v127
	.byte	W18
	.byte		N01   , An2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N01   , Bn3 
	.byte	W24
	.byte		N03   , Dn3 , v092
	.byte	W03
	.byte		N01   , Dn3 , v072
	.byte	W03
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W06
	.byte		N01   , Gn3 , v127
	.byte	W12
	.byte		N01   
	.byte	W03
	.byte		N15   , Dn3 , v120
	.byte	W15
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   , An2 , v127
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N01   , Fs3 , v127
	.byte	W06
	.byte		N06   , Bn2 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N01   , Bn3 
	.byte	W24
	.byte		N03   , Dn3 , v092
	.byte	W03
	.byte		N01   , Dn3 , v072
	.byte	W03
	.byte		N12   , En3 , v120
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W06
	.byte		N01   , Gn3 , v072
	.byte	W06
	.byte		N06   , Dn3 , v120
	.byte	W06
	.byte		N01   , Gn3 , v127
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		N24   , Gn3 , v120
	.byte	W24
	.byte		N03   , Fs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N01   , Bn3 , v127
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		        Bn3 , v127
	.byte	W06
	.byte		        Bn3 , v100
	.byte	W06
	.byte		N06   , Dn3 , v120
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , An3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
mus_rg_guren_6_000:
	.byte		N06   , Dn3 , v120
	.byte	W12
	.byte		        Bn2 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn3 
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte	PEND
	.byte		N06   , Dn3 
	.byte	W18
	.byte		N03   , Bn2 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N01   , Dn4 
	.byte	W06
	.byte		N03   , Dn3 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W18
	.byte		N03   
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N12   , Gn3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N01   , Cn4 
	.byte	W06
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W18
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		N01   
	.byte	W06
	.byte		N06   , An3 
	.byte	W12
	.byte		N09   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte	PATT
	 .word	mus_rg_guren_6_000
	.byte		N03   , Gn2 , v120
	.byte	W12
	.byte		N18   , Dn2 
	.byte	W24
	.byte		N06   , Bn2 
	.byte	W12
	.byte		N12   , Gn2 
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_guren_7:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 66*mus_rg_guren_mvl/mxv
	.byte		N12   , Cn1 , v120
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , En1 , v072
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cs1 , v084
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
mus_rg_guren_7_B1:
	.byte		N12   , Cn1 , v120
	.byte		N48   , Cs2 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cs1 , v120
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cs1 , v120
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v092
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cs1 , v120
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v056
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Dn2 , v120
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Bn1 
	.byte	W06
	.byte		N12   , Fn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte		N06   , Cs1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cs1 , v120
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		        En1 , v056
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v096
	.byte	W06
	.byte		N12   , Cn1 , v120
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N18   , Cs1 , v120
	.byte	W18
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Cs1 , v092
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v060
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , Cs1 , v120
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        An1 
	.byte	W06
	.byte		        Cs1 
	.byte	W06
	.byte		N06   
	.byte	W06
mus_rg_guren_7_000:
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte	PEND
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		        Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , Cn1 , v120
	.byte		N12   , As4 , v016
	.byte	W12
	.byte	PATT
	 .word	mus_rg_guren_7_000
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte		N03   , An4 , v036
	.byte	W03
	.byte		        An4 , v012
	.byte	W03
	.byte		        An4 , v020
	.byte	W06
	.byte		N12   , As4 , v032
	.byte	W12
	.byte		        Cs1 , v120
	.byte		N03   , An4 , v036
	.byte	W12
	.byte		N12   , Cn1 , v120
	.byte		N12   , As4 , v016
	.byte	W12
	.byte		N24   , Cn1 , v120
	.byte	W24
	.byte		N12   , Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N24   
	.byte	W24
	.byte		        Cs1 
	.byte	W24
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N12   , Cn1 
	.byte	W12
	.byte		        Cs1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   , Cs1 
	.byte	W18
	.byte		N06   , Cs1 , v084
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , Cs1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Dn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N12   
	.byte		N48   , An2 
	.byte	W12
	.byte		N06   , En1 , v072
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N12   , Cs1 , v120
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W06
	.byte		        Cs1 , v084
	.byte	W06
	.byte		N12   , Fn1 , v120
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_guren_8:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_rg_guren_mvl/mxv
	.byte		N02   , Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
mus_rg_guren_8_B1:
	.byte		N02   , Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v060
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		N01   , Cn5 , v084
	.byte	W03
	.byte		        Cn5 , v048
	.byte	W03
	.byte		N01   
	.byte	W06
	.byte		N02   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
mus_rg_guren_8_000:
	.byte		N02   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W24
	.byte	PEND
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		N01   , Cn5 , v084
	.byte	W03
	.byte		        Cn5 , v052
	.byte	W03
	.byte		        Cn5 , v048
	.byte	W06
	.byte		N02   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W18
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		N01   , Cn5 , v084
	.byte	W03
	.byte		        Cn5 , v052
	.byte	W03
	.byte		N01   
	.byte	W06
	.byte		N02   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte	PATT
	 .word	mus_rg_guren_8_000
	.byte		N02   , Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		N01   , Cn5 , v084
	.byte	W03
	.byte		        Cn5 , v048
	.byte	W03
	.byte		N01   
	.byte	W06
	.byte		N02   , Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v052
	.byte	W06
	.byte		        Cn5 , v112
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        Cn5 , v084
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v056
	.byte	W18
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v048
	.byte	W12
	.byte		        Cn5 , v120
	.byte	W24
	.byte		        Cn5 , v112
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v084
	.byte	W06
	.byte		        Cn5 , v040
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v052
	.byte	W06
	.byte		N02   
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte		        Cn5 , v120
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W24
	.byte		N02   
	.byte	W12
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W06
	.byte		        Cn5 , v120
	.byte	W06
	.byte		        Cn5 , v044
	.byte	W18
	.byte	GOTO
	 .word	mus_rg_guren_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_rg_guren_9:
	.byte	KEYSH , mus_rg_guren_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_rg_guren_mvl/mxv
	.byte	W36
	.byte		N12   , Gn5 , v096
	.byte	W48
	.byte		N12   
	.byte	W12
mus_rg_guren_9_B1:
	.byte	W96
	.byte	W84
	.byte		N12   , Gn5 , v120
	.byte	W12
	.byte	W96
	.byte	W12
	.byte		        Gn5 , v072
	.byte	W24
	.byte		N12   
	.byte	W48
	.byte		        Gn5 , v120
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		        Cs5 , v096
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		        Gn5 
	.byte	W72
	.byte		N12   
	.byte	W12
	.byte	W60
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	W36
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_guren_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_guren:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_guren_pri	@ Priority
	.byte	mus_rg_guren_rev	@ Reverb.

	.word	mus_rg_guren_grp

	.word	mus_rg_guren_1
	.word	mus_rg_guren_2
	.word	mus_rg_guren_3
	.word	mus_rg_guren_4
	.word	mus_rg_guren_5
	.word	mus_rg_guren_6
	.word	mus_rg_guren_7
	.word	mus_rg_guren_8
	.word	mus_rg_guren_9

	.end
