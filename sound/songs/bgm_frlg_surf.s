	.include "MPlayDef.s"

	.equ	bgm_frlg_surf_grp, voicegroup_86ABF38
	.equ	bgm_frlg_surf_pri, 0
	.equ	bgm_frlg_surf_rev, reverb_set+50
	.equ	bgm_frlg_surf_mvl, 127
	.equ	bgm_frlg_surf_key, 0
	.equ	bgm_frlg_surf_tbs, 1
	.equ	bgm_frlg_surf_exg, 0
	.equ	bgm_frlg_surf_cmp, 1

	.section .rodata
	.global	bgm_frlg_surf
	.align	2

@********************** Track  1 **********************@

bgm_frlg_surf_1:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte	TEMPO , 100*bgm_frlg_surf_tbs/2
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+32
	.byte		VOL   , 38*bgm_frlg_surf_mvl/mxv
	.byte	W36
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N18   , Gs2 
	.byte	W18
	.byte		N06   , Fs2 
	.byte	W06
	.byte		N36   , En2 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Gs3 
	.byte	W12
bgm_frlg_surf_1_B1:
	.byte		VOICE , 4
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		N06   , En3 , v127
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   , Fs3 
	.byte	W18
	.byte		        Cn3 
	.byte	W06
	.byte		N12   , An2 , v120
	.byte	W12
	.byte		N06   , En3 , v127
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 24
	.byte		VOL   , 27*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		N12   , An4 , v096
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N24   , An4 , v064
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Gs4 , v096
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , Gs4 , v060
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 , v096
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N24   , Fs4 , v064
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte		N12   , En4 , v096
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N24   , En4 , v064
	.byte	W12
	.byte		MOD   , 5
	.byte	W12
	.byte		VOICE , 4
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En3 , v127
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W12
	.byte		N36   , Cs4 
	.byte	W36
	.byte		VOICE , 48
	.byte		VOL   , 21*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		VOL   , 21*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N18   , Bn4 
	.byte	W18
	.byte		PAN   , c_v-32
	.byte		N06   , Cs5 , v120
	.byte	W06
	.byte		N36   , En5 , v127
	.byte	W12
	.byte		VOL   , 18*bgm_frlg_surf_mvl/mxv
	.byte	W09
	.byte		        13*bgm_frlg_surf_mvl/mxv
	.byte	W09
	.byte		        8*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_surf_1_B1
	.byte	W72
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_surf_2:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 71*bgm_frlg_surf_mvl/mxv
	.byte		N12   , An3 , v127
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , Fs3 
	.byte	W06
	.byte		MOD   , 6
	.byte		N36   , En3 
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        44*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        70*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gs3 
	.byte	W12
	.byte		VOL   , 68*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        56*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        44*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        34*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        68*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En4 , v104
	.byte	W12
	.byte		        Dn4 , v096
	.byte	W12
	.byte		        Bn3 , v092
	.byte	W12
bgm_frlg_surf_2_B1:
	.byte		VOICE , 4
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , En5 , v072
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N30   , Cs5 , v084
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		VOICE , 5
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Dn4 , v088
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Bn3 , v100
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Dn4 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , En4 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Cs4 , v100
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		VOICE , 4
	.byte		VOL   , 65*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , En5 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N30   , Cs5 
	.byte	W12
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W18
	.byte		        67*bgm_frlg_surf_mvl/mxv
	.byte		N06   , En5 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Dn5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W24
	.byte		VOICE , 5
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En4 , v104
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , An4 , v088
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , An4 , v104
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		VOICE , 73
	.byte		VOL   , 60*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N03   , Cn6 , v052
	.byte	W03
	.byte		N09   , Bn5 , v080
	.byte	W09
	.byte		N18   , An5 
	.byte	W18
	.byte		N06   , Dn5 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En5 
	.byte	W12
	.byte		N18   , Fs5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N06   , Bn4 
	.byte	W06
	.byte		VOL   , 67*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Fs5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 66*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En5 
	.byte	W12
	.byte		N18   , Ds5 
	.byte	W18
	.byte		N06   , En5 
	.byte	W06
	.byte		N36   , An5 
	.byte	W12
	.byte		MOD   , 8
	.byte		VOL   , 56*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        45*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		VOICE , 48
	.byte		VOL   , 42*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		N12   , Bn4 , v127
	.byte	W12
	.byte		N18   , An4 
	.byte	W18
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W36
	.byte		N12   , En4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W36
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		N36   , Gs4 
	.byte	W36
	.byte		N12   , An4 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W36
	.byte	GOTO
	 .word	bgm_frlg_surf_2_B1
	.byte	W72
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_surf_3:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte	W72
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*bgm_frlg_surf_mvl/mxv
	.byte		N36   , En4 , v127
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		N12   , En3 , v072
	.byte	W12
	.byte		        Fs3 , v076
	.byte	W12
	.byte		        Gs3 , v072
	.byte	W12
bgm_frlg_surf_3_B1:
	.byte		N12   , An2 , v127
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W18
	.byte		        En3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_frlg_surf_3_000:
	.byte		N12   , Cs3 , v127
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_surf_3_000
bgm_frlg_surf_3_001:
	.byte		N12   , Dn3 , v127
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
bgm_frlg_surf_3_002:
	.byte		N12   , En3 , v127
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
bgm_frlg_surf_3_003:
	.byte		N12   , En3 , v127
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte		N12   , En3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte	PATT
	 .word	bgm_frlg_surf_3_001
	.byte	PATT
	 .word	bgm_frlg_surf_3_002
	.byte	PATT
	 .word	bgm_frlg_surf_3_003
	.byte		N12   , En3 , v127
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N12   , Cs3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_surf_3_B1
	.byte	W72
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_surf_4:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 80
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*bgm_frlg_surf_mvl/mxv
	.byte	W72
	.byte	W36
	.byte		N12   , En1 , v080
	.byte	W12
	.byte		        Fs1 , v092
	.byte	W12
	.byte		        Gs1 , v096
	.byte	W12
bgm_frlg_surf_4_B1:
	.byte		N12   , An1 , v096
	.byte	W36
	.byte		        En1 
	.byte	W12
	.byte		N03   , Fn1 , v068
	.byte	W03
	.byte		        Fs1 
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		        An1 
	.byte	W03
	.byte		N12   , As1 , v100
	.byte	W12
	.byte		        Bn1 
	.byte	W36
	.byte		        En1 
	.byte	W24
	.byte		        As1 
	.byte	W12
bgm_frlg_surf_4_000:
	.byte		N12   , Bn1 , v100
	.byte	W36
	.byte		        En1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte	PEND
	.byte		        Cs2 
	.byte	W36
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        En1 
	.byte	W36
	.byte		        Cs2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W36
	.byte		        En1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte	PATT
	 .word	bgm_frlg_surf_4_000
	.byte		N12   , Cs2 , v100
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N06   , Fn1 
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N18   , An1 
	.byte	W18
	.byte		N03   , Fs1 , v064
	.byte	W03
	.byte		        En1 
	.byte	W03
	.byte		N12   , Dn1 , v096
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		        An1 
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N18   , Gs1 
	.byte	W18
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N12   , En1 
	.byte	W36
	.byte		        Gs1 
	.byte	W12
	.byte		N18   , Bn1 
	.byte	W18
	.byte		N06   , Dn2 
	.byte	W06
	.byte		N15   , Cs2 
	.byte	W36
	.byte		N12   , An1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N18   , Dn2 
	.byte	W18
	.byte		N03   , Cs2 , v064
	.byte	W03
	.byte		        Gs1 
	.byte	W03
	.byte		N12   , Fs1 , v096
	.byte	W12
	.byte		N18   , En1 
	.byte	W18
	.byte		N06   , Fs1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N18   , En1 
	.byte	W18
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W12
	.byte		N18   , En2 
	.byte	W18
	.byte		N06   , An1 
	.byte	W06
	.byte		N12   , Gs1 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		N18   , Cs2 
	.byte	W18
	.byte		N06   , Gs1 
	.byte	W06
	.byte		N12   , An1 
	.byte	W36
	.byte		N30   , En1 
	.byte	W30
	.byte		N06   , Gs1 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_surf_4_B1
	.byte	W72
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_surf_5:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 30*bgm_frlg_surf_mvl/mxv
	.byte		N06   , En3 , v120
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v+32
	.byte		N06   , En4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-32
	.byte		N06   , En3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		PAN   , c_v-43
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , Cs5 
	.byte	W03
	.byte		PAN   , c_v+28
	.byte		N03   , Dn5 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N36   , En5 
	.byte	W36
bgm_frlg_surf_5_B1:
	.byte		PAN   , c_v+32
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		        c_v+48
	.byte		VOL   , 41*bgm_frlg_surf_mvl/mxv
	.byte		N06   , Dn4 , v120
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N24   , Dn5 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   , An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		PAN   , c_v+48
	.byte		N18   , Cs5 
	.byte	W18
	.byte		N03   , Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		PAN   , c_v-32
	.byte		N03   , An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		PAN   , c_v-48
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N12   , Bn4 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N12   , An4 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-48
	.byte		N06   , An4 
	.byte	W06
	.byte		N12   , Cs5 
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W03
	.byte		        Dn4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		PAN   , c_v+16
	.byte		N03   , Fs5 
	.byte	W03
	.byte		PAN   , c_v+32
	.byte		N03   , Gs5 
	.byte	W03
	.byte		PAN   , c_v+48
	.byte		N12   , An5 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_surf_5_B1
	.byte	W72
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_surf_6:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 73
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 45*bgm_frlg_surf_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		N12   , An4 , v076
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 33*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        26*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        21*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        11*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte	W48
	.byte		VOICE , 92
	.byte		PAN   , c_v+0
	.byte	W24
bgm_frlg_surf_6_B1:
	.byte		VOL   , 34*bgm_frlg_surf_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N36   , En4 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N30   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N06   , En4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N36   , Dn3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N36   , Cs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N36   , En4 , v084
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N30   , Cs4 
	.byte	W30
	.byte		N06   , En4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N36   , Fs3 , v127
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N36   
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N03   , Cn4 , v080
	.byte	W03
	.byte		N09   , Bn3 , v127
	.byte	W09
	.byte		N18   , An3 
	.byte	W18
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N36   , Cs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N18   , Cs3 
	.byte	W18
	.byte		N06   , Bn2 
	.byte	W06
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		N18   , Ds3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		VOICE , 92
	.byte		MOD   , 0
	.byte		BEND  , c_v+1
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N18   , An4 
	.byte	W18
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N36   , Fs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N12   , En4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , Gs4 
	.byte	W06
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W12
	.byte		N18   , Fs4 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		N36   , Gs4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W24
	.byte		        0
	.byte		N12   , An4 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W06
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 28*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		        22*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        15*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_surf_6_B1
	.byte		MOD   , 0
	.byte	W72
	.byte	FINE

@********************** Track  7 **********************@

bgm_frlg_surf_7:
	.byte	KEYSH , bgm_frlg_surf_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 11*bgm_frlg_surf_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , An4 , v120
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		VOL   , 11*bgm_frlg_surf_mvl/mxv
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
bgm_frlg_surf_7_B1:
	.byte		VOL   , 11*bgm_frlg_surf_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N36   , An3 , v120
	.byte	W12
	.byte		MOD   , 8
	.byte	W24
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		N30   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		N36   , Gs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		PAN   , c_v-64
	.byte		N36   , Bn3 
	.byte	W36
	.byte		PAN   , c_v+63
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N18   , Dn4 
	.byte	W18
	.byte		N06   , Bn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N36   
	.byte	W36
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		N30   , En3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte		N06   , An3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N24   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		MOD   , 0
	.byte		PAN   , c_v+63
	.byte		N36   , Fs3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		PAN   , c_v-64
	.byte		N36   , Bn3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		PAN   , c_v+63
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N36   , An3 
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		VOICE , 12
	.byte		MOD   , 0
	.byte		PAN   , c_v-64
	.byte		VOL   , 24*bgm_frlg_surf_mvl/mxv
	.byte		N01   , Dn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Fs3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Gs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Bn3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Gs3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , En3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N01   , Cs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N01   , An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		VOICE , 81
	.byte		PAN   , c_v-64
	.byte		VOL   , 25*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N18   , Cs4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N24   , An3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 19*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 25*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , As3 
	.byte	W03
	.byte		N09   , An3 
	.byte	W09
	.byte		N18   , Gs3 
	.byte	W18
	.byte		N06   , An3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N24   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 19*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 25*bgm_frlg_surf_mvl/mxv
	.byte		N12   , En4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N03   , An3 
	.byte	W03
	.byte		N09   , Gs3 
	.byte	W09
	.byte		N18   , Fs3 
	.byte	W18
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N24   , Gs3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 19*bgm_frlg_surf_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 25*bgm_frlg_surf_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N12   , En4 
	.byte	W12
	.byte		N18   , Ds4 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N36   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W06
	.byte		VOL   , 21*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        16*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte		        10*bgm_frlg_surf_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_surf_7_B1
	.byte		MOD   , 0
	.byte	W72
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_surf:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_surf_pri	@ Priority
	.byte	bgm_frlg_surf_rev	@ Reverb.

	.word	bgm_frlg_surf_grp

	.word	bgm_frlg_surf_1
	.word	bgm_frlg_surf_2
	.word	bgm_frlg_surf_3
	.word	bgm_frlg_surf_4
	.word	bgm_frlg_surf_5
	.word	bgm_frlg_surf_6
	.word	bgm_frlg_surf_7

	.end
