	.include "MPlayDef.s"

	.equ	bgm_frlg_pallet_town_grp, voicegroup_86AA4BC
	.equ	bgm_frlg_pallet_town_pri, 0
	.equ	bgm_frlg_pallet_town_rev, reverb_set+50
	.equ	bgm_frlg_pallet_town_mvl, 127
	.equ	bgm_frlg_pallet_town_key, 0
	.equ	bgm_frlg_pallet_town_tbs, 1
	.equ	bgm_frlg_pallet_town_exg, 0
	.equ	bgm_frlg_pallet_town_cmp, 1

	.section .rodata
	.global	bgm_frlg_pallet_town
	.align	2

@********************** Track  1 **********************@

bgm_frlg_pallet_town_1:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_1_B1:
	.byte	TEMPO , 88*bgm_frlg_pallet_town_tbs/2
	.byte		VOICE , 5
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+32
	.byte		MOD   , 0
	.byte		VOL   , 25*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , Cs3 , v108
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Dn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , An2 
	.byte	W12
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N24   , An3 
	.byte	W06
	.byte		BEND  , c_v+1
	.byte	W06
	.byte		MOD   , 4
	.byte		BEND  , c_v+0
	.byte	W12
	.byte		MOD   , 0
	.byte		N12   , En3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 4
	.byte	W12
	.byte		        0
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_frlg_pallet_town_2:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_2_B1:
	.byte		VOICE , 80
	.byte		PAN   , c_v+0
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		MOD   , 0
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , En5 , v040
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An5 , v024
	.byte	W12
	.byte		        Fs5 , v040
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N36   , En5 , v028
	.byte	W12
	.byte		MOD   , 3
	.byte	W24
	.byte		        0
	.byte		N12   , Cs5 , v040
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N60   , Dn5 
	.byte	W15
	.byte		MOD   , 4
	.byte	W44
	.byte	W01
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 3
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W09
	.byte		MOD   , 4
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        An5 , v024
	.byte	W12
	.byte		        Gs5 , v040
	.byte	W12
	.byte		        Gs5 , v028
	.byte	W12
	.byte		        An5 , v032
	.byte	W12
	.byte		N36   , Fs5 , v040
	.byte	W12
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		MOD   , 7
	.byte	W36
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N60   , An4 
	.byte	W12
	.byte		MOD   , 5
	.byte	W48
	.byte		VOICE , 83
	.byte		MOD   , 0
	.byte		N12   
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		LFOS  , 50
	.byte		N48   , Dn5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        76*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N36   , En5 , v032
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        76*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N12   , Dn5 , v040
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N48   , Cs5 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        76*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		N03   , As4 , v016
	.byte	W03
	.byte		N09   , An4 , v040
	.byte	W09
	.byte		N12   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N06   , Dn5 
	.byte	W21
	.byte		N03   , Cs5 , v016
	.byte	W03
	.byte		N24   , Dn5 , v040
	.byte	W12
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N36   , En5 , v032
	.byte	W12
	.byte		MOD   , 5
	.byte	W03
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        79*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        66*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N06   , Dn5 , v040
	.byte	W06
	.byte		        En5 , v028
	.byte	W06
	.byte		N48   , Cs5 , v040
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        81*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        46*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        32*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N48   , Bn4 
	.byte	W12
	.byte		MOD   , 5
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        84*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        64*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        50*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        33*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , Fs4 
	.byte	W12
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N18   , Cs5 
	.byte	W12
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		N06   , Cn5 , v024
	.byte	W06
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N48   , Bn4 , v040
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        81*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        45*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        33*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , An4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		N48   , Gs4 
	.byte	W12
	.byte		MOD   , 4
	.byte	W03
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        81*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        62*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        44*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        27*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , An4 
	.byte	W12
	.byte		VOL   , 83*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , Cs5 
	.byte	W09
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        63*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        50*bgm_frlg_pallet_town_mvl/mxv
	.byte		N42   
	.byte	W12
	.byte		MOD   , 5
	.byte	W06
	.byte		VOL   , 68*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        86*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        100*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		N06   , Cn5 , v016
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte		N36   , Bn4 , v028
	.byte	W12
	.byte		VOL   , 88*bgm_frlg_pallet_town_mvl/mxv
	.byte	W03
	.byte		MOD   , 4
	.byte	W03
	.byte		        5
	.byte	W06
	.byte		VOL   , 73*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        43*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		VOICE , 80
	.byte		MOD   , 0
	.byte		N06   , Cs5 , v012
	.byte	W03
	.byte		VOL   , 99*bgm_frlg_pallet_town_mvl/mxv
	.byte	W03
	.byte		N06   , Dn5 , v016
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_2_B1
	.byte		MOD   , 0
	.byte		VOL   , 100*bgm_frlg_pallet_town_mvl/mxv
	.byte	FINE

@********************** Track  3 **********************@

bgm_frlg_pallet_town_3:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_3_B1:
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-40
	.byte		VOL   , 40*bgm_frlg_pallet_town_mvl/mxv
	.byte		N36   , An3 , v127
	.byte	W36
	.byte		        Fs3 
	.byte	W36
	.byte		N24   , Gs3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An3 , v112
	.byte	W12
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , An3 
	.byte	W36
	.byte		        Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , En3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An2 
	.byte	W06
	.byte		BEND  , c_v-6
	.byte	W06
	.byte		        c_v+0
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , En3 
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W06
	.byte		N12   , Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N36   , Dn3 
	.byte	W36
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N24   , Cs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		N12   , Fs2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Ds2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N06   , Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N12   , En2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		N12   , An2 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		N06   , An3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_frlg_pallet_town_4:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_4_B1:
	.byte		VOICE , 81
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		MOD   , 0
	.byte		PAN   , c_v-5
	.byte		VOL   , 50*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , An1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , An1 , v096
	.byte	W12
	.byte		N24   , Dn2 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N12   , Bn1 , v096
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		N24   , Cs2 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , Gs1 , v096
	.byte	W12
	.byte		        Fs2 , v108
	.byte	W12
	.byte		        Cs2 , v096
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N24   , Dn2 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		        En2 , v096
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		N24   , En1 
	.byte	W24
	.byte		        An1 , v112
	.byte	W24
	.byte		        Dn2 , v096
	.byte	W24
	.byte		BEND  , c_v+0
	.byte		N24   , En2 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , En1 , v092
	.byte	W03
	.byte		BEND  , c_v-3
	.byte	W03
	.byte		        c_v+0
	.byte	W06
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , An1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , En1 , v096
	.byte	W12
	.byte		N24   , Dn2 , v112
	.byte	W24
	.byte		N12   , Cs2 , v096
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 , v112
	.byte	W36
	.byte		        Gs1 , v096
	.byte	W12
	.byte		        Cs2 , v112
	.byte	W12
	.byte		        Gs2 , v096
	.byte	W12
	.byte		        En2 , v112
	.byte	W12
	.byte		        Bn1 , v096
	.byte	W12
	.byte		N24   , Dn2 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Bn1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , En1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Gs1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N72   , An1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W60
	.byte		        0
	.byte		N24   , Cs2 , v096
	.byte	W24
	.byte		N48   , Dn1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W36
	.byte		        0
	.byte		N36   , En1 
	.byte	W12
	.byte		MOD   , 11
	.byte	W24
	.byte		        0
	.byte		N12   , Gs1 , v096
	.byte	W12
	.byte		N48   , An1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W36
	.byte		        0
	.byte		N24   , Fs1 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Cs1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N48   , Dn1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W36
	.byte		        0
	.byte		N36   , Fn1 
	.byte	W36
	.byte		N12   , An1 , v096
	.byte	W12
	.byte		N24   , Fs1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Fn1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , En1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Ds1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Dn1 , v112
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte	W12
	.byte		N12   , Dn1 , v096
	.byte	W12
	.byte		MOD   , 11
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		MOD   , 0
	.byte	W24
	.byte		N12   , An1 , v096
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , Ds1 , v112
	.byte	W36
	.byte		        Ds1 , v096
	.byte	W12
	.byte		        Ds1 , v112
	.byte	W12
	.byte		        An1 , v096
	.byte	W24
	.byte		        Fs1 
	.byte	W12
	.byte		BEND  , c_v+0
	.byte		N12   , En1 , v112
	.byte	W36
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v112
	.byte	W36
	.byte		        En1 , v096
	.byte	W12
	.byte	W12
	.byte		        En1 , v112
	.byte	W24
	.byte		        En1 , v096
	.byte	W12
	.byte		        En1 , v112
	.byte	W12
	.byte		        En1 , v096
	.byte	W24
	.byte		        En1 , v112
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_frlg_pallet_town_5:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_5_B1:
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 40*bgm_frlg_pallet_town_mvl/mxv
	.byte		PAN   , c_v-21
	.byte		N36   , Cs3 , v112
	.byte	W36
	.byte		        Dn3 
	.byte	W36
	.byte		N12   , En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N03   , En3 
	.byte	W24
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Bn2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		N36   , An2 
	.byte	W36
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N12   , An2 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Gs2 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N24   , Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte		N12   , Dn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		N36   , An2 
	.byte	W36
	.byte		N12   , En2 
	.byte	W12
	.byte		N24   , An2 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte	W24
	.byte		N06   , Dn3 
	.byte	W48
	.byte		        En3 
	.byte	W24
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte	W24
	.byte		        Dn3 
	.byte	W48
	.byte		N06   
	.byte	W24
	.byte	W24
	.byte		        Fn3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Dn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        An3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte	W24
	.byte		        Bn2 
	.byte	W48
	.byte		        Dn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte	W24
	.byte		        Dn3 
	.byte	W24
	.byte		        Gs3 
	.byte	W12
	.byte		        Dn3 
	.byte	W24
	.byte		        En3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_frlg_pallet_town_6:
	.byte	KEYSH , bgm_frlg_pallet_town_key+0
bgm_frlg_pallet_town_6_B1:
	.byte		VOICE , 4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N12   , En5 , v120
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		N36   , En5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N60   , Dn5 
	.byte	W15
	.byte		MOD   , 6
	.byte	W44
	.byte	W01
	.byte		        0
	.byte		N12   , Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N36   , Cs5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W03
	.byte		MOD   , 0
	.byte	W03
	.byte		N06   , Cs5 
	.byte	W06
	.byte		N48   , Bn4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        An5 
	.byte	W12
	.byte		N36   , Fs5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W24
	.byte		        0
	.byte		N12   , En5 
	.byte	W12
	.byte		N48   
	.byte	W12
	.byte		MOD   , 6
	.byte	W36
	.byte		        0
	.byte		N12   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N60   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W48
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		BEND  , c_v+0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        11*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        12*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N12   , Dn4 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		N48   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 32*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        19*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        12*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte	W06
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		N03   , As3 , v064
	.byte	W03
	.byte		N09   , An3 , v120
	.byte	W09
	.byte		N12   , Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W21
	.byte		N03   , Cs4 , v072
	.byte	W03
	.byte		N24   , Dn4 , v120
	.byte	W24
	.byte		N36   , En4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        37*bgm_frlg_pallet_town_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N48   , Cs4 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 32*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        12*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N48   , Bn3 
	.byte	W09
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W03
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        12*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        7*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N18   , Cs4 
	.byte	W18
	.byte		N06   , Cn4 , v088
	.byte	W06
	.byte		N48   , Bn3 , v120
	.byte	W12
	.byte		MOD   , 4
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        11*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , An3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N48   , Gs3 
	.byte	W12
	.byte		MOD   , 6
	.byte		VOL   , 29*bgm_frlg_pallet_town_mvl/mxv
	.byte	W12
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        12*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , An3 
	.byte	W24
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte		N24   , Cs4 
	.byte	W12
	.byte		VOL   , 31*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        24*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        18*bgm_frlg_pallet_town_mvl/mxv
	.byte		MOD   , 5
	.byte		N42   
	.byte	W09
	.byte		VOL   , 21*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		        25*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        37*bgm_frlg_pallet_town_mvl/mxv
	.byte	W18
	.byte		MOD   , 0
	.byte		N06   , Cn4 , v088
	.byte	W06
	.byte		MOD   , 0
	.byte		N36   , Bn3 , v104
	.byte	W09
	.byte		VOL   , 29*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		MOD   , 6
	.byte		VOL   , 22*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        15*bgm_frlg_pallet_town_mvl/mxv
	.byte	W06
	.byte		        10*bgm_frlg_pallet_town_mvl/mxv
	.byte	W09
	.byte		VOICE , 4
	.byte		VOL   , 33*bgm_frlg_pallet_town_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Cs5 , v068
	.byte	W06
	.byte		        Dn5 , v080
	.byte	W06
	.byte	GOTO
	 .word	bgm_frlg_pallet_town_6_B1
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_frlg_pallet_town_mvl/mxv
	.byte	FINE

@******************************************************@
	.align	2

bgm_frlg_pallet_town:
	.byte	6	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_frlg_pallet_town_pri	@ Priority
	.byte	bgm_frlg_pallet_town_rev	@ Reverb.

	.word	bgm_frlg_pallet_town_grp

	.word	bgm_frlg_pallet_town_1
	.word	bgm_frlg_pallet_town_2
	.word	bgm_frlg_pallet_town_3
	.word	bgm_frlg_pallet_town_4
	.word	bgm_frlg_pallet_town_5
	.word	bgm_frlg_pallet_town_6

	.end
