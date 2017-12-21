	.include "MPlayDef.s"

	.equ	bgm_inter_v_grp, voicegroup_869407C
	.equ	bgm_inter_v_pri, 0
	.equ	bgm_inter_v_rev, reverb_set+50
	.equ	bgm_inter_v_mvl, 127
	.equ	bgm_inter_v_key, 0
	.equ	bgm_inter_v_tbs, 1
	.equ	bgm_inter_v_exg, 0
	.equ	bgm_inter_v_cmp, 1

	.section .rodata
	.global	bgm_inter_v
	.align	2

@********************** Track  1 **********************@

bgm_inter_v_1:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte	TEMPO , 142*bgm_inter_v_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 39*bgm_inter_v_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N03   , Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W12
	.byte		        Gn5 , v116
	.byte	W12
	.byte		        Gn5 , v112
	.byte	W12
	.byte		        Gn5 , v060
	.byte	W12
	.byte		        Gn5 , v092
	.byte	W12
	.byte		        Gn5 , v064
	.byte	W12
bgm_inter_v_1_B1:
	.byte		N03   , Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v080
	.byte	W06
	.byte		        Gn5 , v064
	.byte	W18
	.byte		        Gn5 , v112
	.byte	W03
	.byte		        Gn5 , v076
	.byte	W03
	.byte		        Gn5 , v068
	.byte	W06
	.byte		        Gn5 , v112
	.byte	W06
	.byte		        Gn5 , v096
	.byte	W06
	.byte	GOTO
	 .word	bgm_inter_v_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

bgm_inter_v_2:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+13
	.byte		VOL   , 62*bgm_inter_v_mvl/mxv
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        An4 
	.byte	W12
	.byte		N18   , Gs4 
	.byte	W18
	.byte		N06   , An4 
	.byte	W06
	.byte		        Gs4 
	.byte	W12
	.byte		        En4 
	.byte	W24
	.byte		N36   , Fs4 
	.byte	W36
bgm_inter_v_2_B1:
	.byte		VOICE , 13
	.byte		VOL   , 27*bgm_inter_v_mvl/mxv
	.byte		N03   , Bn5 , v112
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn5 , v080
	.byte	W06
	.byte		        Bn5 , v112
	.byte	W06
	.byte		        Bn5 , v080
	.byte	W06
bgm_inter_v_2_000:
	.byte		N03   , Bn5 , v112
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Bn5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Bn5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn5 , v080
	.byte	W06
	.byte		        Bn5 , v112
	.byte	W06
	.byte		        Bn5 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_inter_v_2_000
	.byte	PATT
	 .word	bgm_inter_v_2_000
	.byte	GOTO
	 .word	bgm_inter_v_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

bgm_inter_v_3:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 61*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
bgm_inter_v_3_B1:
	.byte		BEND  , c_v+0
	.byte		N18   , Bn0 , v112
	.byte	W18
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn0 
	.byte	W06
	.byte		N03   , Bn1 
	.byte	W06
	.byte		BEND  , c_v-5
	.byte		N24   , Bn0 
	.byte	W06
	.byte		BEND  , c_v+0
	.byte	W30
	.byte		N06   , An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
bgm_inter_v_3_000:
	.byte		N15   , Bn0 , v112
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte		N15   , Bn0 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte	PEND
	.byte		N18   , Bn0 
	.byte	W18
	.byte		N03   , Bn1 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N24   , Bn0 
	.byte	W36
	.byte		N06   , An0 
	.byte	W06
	.byte		        As0 
	.byte	W06
	.byte	PATT
	 .word	bgm_inter_v_3_000
	.byte	GOTO
	 .word	bgm_inter_v_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

bgm_inter_v_4:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 60*bgm_inter_v_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N18   , En3 
	.byte	W18
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        Cs4 
	.byte	W12
	.byte		N18   , Bn3 
	.byte	W18
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W36
bgm_inter_v_4_B1:
	.byte		VOICE , 13
	.byte		VOL   , 27*bgm_inter_v_mvl/mxv
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		N06   , En5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , En5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
bgm_inter_v_4_000:
	.byte		N03   , En5 , v112
	.byte	W06
	.byte		N06   , En5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , En5 , v064
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En5 , v112
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte		        En5 , v112
	.byte	W06
	.byte		        En5 , v080
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_inter_v_4_000
	.byte	PATT
	 .word	bgm_inter_v_4_000
	.byte	GOTO
	 .word	bgm_inter_v_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

bgm_inter_v_5:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 47*bgm_inter_v_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W06
	.byte	W96
	.byte	W96
bgm_inter_v_5_B1:
	.byte	W84
	.byte		N12   , En5 , v096
	.byte	W12
	.byte	W84
	.byte		N12   
	.byte	W12
	.byte	W24
	.byte		N12   
	.byte	W60
	.byte		N12   
	.byte	W12
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W36
	.byte	GOTO
	 .word	bgm_inter_v_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

bgm_inter_v_6:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		PAN   , c_v-61
	.byte		N03   , Bn4 , v108
	.byte	W03
	.byte		        Ds5 
	.byte	W03
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Dn6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        En6 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
	.byte		        Fs6 
	.byte	W06
bgm_inter_v_6_B1:
	.byte		VOICE , 83
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N84   , Bn2 , v112
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        26*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        19*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        15*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        8*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		N96   , Fs2 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        23*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        16*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        12*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        9*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        2*bgm_inter_v_mvl/mxv
	.byte	W13
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N84   , Bn2 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        40*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        25*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        18*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        9*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        6*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W01
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N06   , En3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N96   , Fs3 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        34*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        32*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        27*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        23*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        20*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        16*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        12*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        7*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_inter_v_6_B1
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

bgm_inter_v_7:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		N03   , Gs4 , v108
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        En5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Gs5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Bn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Cs6 
	.byte	W06
bgm_inter_v_7_B1:
	.byte		VOICE , 84
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N84   , Fs3 , v112
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        26*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        19*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        15*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        8*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N96   , Bn2 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        23*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        16*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        12*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        9*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        2*bgm_inter_v_mvl/mxv
	.byte	W13
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N84   , Fs3 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        40*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        33*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        29*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        25*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        18*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        9*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        6*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W01
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N96   , Bn3 
	.byte	W36
	.byte		MOD   , 5
	.byte		VOL   , 44*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		        34*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        32*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        27*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        23*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        20*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        16*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        12*bgm_inter_v_mvl/mxv
	.byte	W05
	.byte		        7*bgm_inter_v_mvl/mxv
	.byte	W07
	.byte		        4*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte	GOTO
	 .word	bgm_inter_v_7_B1
	.byte		MOD   , 0
	.byte		VOL   , 37*bgm_inter_v_mvl/mxv
	.byte	W96
	.byte	FINE

@********************** Track  8 **********************@

bgm_inter_v_8:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 58*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte		N24   , An2 , v080
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte		N24   , An2 , v068
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte		N36   , An2 , v076
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v112
	.byte		N24   , An2 , v072
	.byte	W18
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 , v116
	.byte		N24   , An2 , v072
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W12
	.byte		        Dn1 
	.byte		N36   , An2 , v072
	.byte	W12
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
bgm_inter_v_8_B1:
	.byte		N48   , An2 , v092
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	bgm_inter_v_8_B1
	.byte	W96
	.byte	FINE

@********************** Track  9 **********************@

bgm_inter_v_9:
	.byte	KEYSH , bgm_inter_v_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 60*bgm_inter_v_mvl/mxv
	.byte	W06
	.byte		N06   , En1 , v112
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , En2 
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        Ds1 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , Dn2 
	.byte	W06
	.byte		N12   , Dn1 
	.byte	W12
	.byte		N06   , Cs1 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N06   , Cs2 
	.byte	W12
	.byte		N12   , Cs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Cn2 
	.byte	W12
	.byte		N06   , Dn1 
	.byte	W12
	.byte		N12   , Dn2 
	.byte	W12
bgm_inter_v_9_B1:
	.byte		VOL   , 27*bgm_inter_v_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N18   , Bn1 , v112
	.byte	W18
	.byte		N03   , Bn2 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N06   , Bn1 
	.byte	W06
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N24   , Bn1 
	.byte	W36
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
bgm_inter_v_9_000:
	.byte		N15   , Bn1 , v112
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		N15   , Bn1 
	.byte	W18
	.byte		N03   
	.byte	W18
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PEND
	.byte		N18   , Bn1 
	.byte	W18
	.byte		N03   , Bn2 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N24   , Bn1 
	.byte	W36
	.byte		N06   , An1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PATT
	 .word	bgm_inter_v_9_000
	.byte	GOTO
	 .word	bgm_inter_v_9_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

bgm_inter_v:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_inter_v_pri	@ Priority
	.byte	bgm_inter_v_rev	@ Reverb.

	.word	bgm_inter_v_grp

	.word	bgm_inter_v_1
	.word	bgm_inter_v_2
	.word	bgm_inter_v_3
	.word	bgm_inter_v_4
	.word	bgm_inter_v_5
	.word	bgm_inter_v_6
	.word	bgm_inter_v_7
	.word	bgm_inter_v_8
	.word	bgm_inter_v_9

	.end
