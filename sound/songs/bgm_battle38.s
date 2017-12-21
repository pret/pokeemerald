	.include "MPlayDef.s"

	.equ	bgm_battle38_grp, voicegroup_869C704
	.equ	bgm_battle38_pri, 1
	.equ	bgm_battle38_rev, reverb_set+50
	.equ	bgm_battle38_mvl, 127
	.equ	bgm_battle38_key, 0
	.equ	bgm_battle38_tbs, 1
	.equ	bgm_battle38_exg, 0
	.equ	bgm_battle38_cmp, 1

	.section .rodata
	.global	bgm_battle38
	.align	2

@********************** Track  1 **********************@

bgm_battle38_1:
	.byte	KEYSH , bgm_battle38_key+0
	.byte	TEMPO , 214*bgm_battle38_tbs/2
	.byte		VOICE , 60
	.byte		LFOS  , 15
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N12   , An3 , v108
	.byte	W48
	.byte		TIE   , Ds4 
	.byte	W48
	.byte	W96
	.byte		EOT   
	.byte		N12   , Dn4 
	.byte	W96
bgm_battle38_1_000:
	.byte		N12   , Dn4 , v096
	.byte	W72
	.byte		N24   , Ds4 , v108
	.byte	W24
	.byte	PEND
	.byte		N12   , Fn4 
	.byte	W72
	.byte		        Ds4 
	.byte	W24
	.byte		        Dn4 
	.byte	W48
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N12   , Dn4 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle38_1_000
	.byte		N12   , Fn4 , v108
	.byte	W72
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W36
	.byte		        Cn4 
	.byte	W36
	.byte		N24   , Ds4 
	.byte	W24
bgm_battle38_1_B1:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v+10
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , An3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		VOICE , 48
	.byte		N12   , Ds3 , v100
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		VOICE , 56
	.byte		N06   , An3 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , As3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Cn4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		N06   , An3 
	.byte	W12
	.byte		N12   , Ds3 , v100
	.byte	W03
	.byte		VOICE , 48
	.byte	W09
	.byte		N12   , Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N24   , Dn4 , v096
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		        Ds4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Fn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		        Dn4 
	.byte	W24
	.byte		        Cn4 
	.byte	W24
	.byte		N48   , Gs4 
	.byte	W48
	.byte		        Gn4 
	.byte	W48
	.byte		N12   , An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		N48   , Fs4 
	.byte	W48
	.byte		        An4 
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Fs4 
	.byte	W48
	.byte		        An3 , v088
	.byte	W48
	.byte		        Dn4 
	.byte	W48
	.byte		        Fs3 , v072
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte		VOICE , 48
	.byte		PAN   , c_v+36
	.byte	W24
	.byte		TIE   , Gn3 , v088
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte	W24
	.byte		TIE   , Fs3 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte	W24
	.byte		TIE   , Gn3 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 60
	.byte	W24
	.byte		PAN   , c_v+6
	.byte		TIE   , Gn3 , v096
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte	W24
	.byte		TIE   , Fs3 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte	W24
	.byte		TIE   , Gn3 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N24   , Ds4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		TIE   , An3 
	.byte	W96
	.byte	W30
	.byte		VOL   , 78*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        76*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        70*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        65*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        58*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        54*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        44*bgm_battle38_mvl/mxv
	.byte	W06
	.byte		        32*bgm_battle38_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		N36   , Bn3 
	.byte	W36
	.byte		        An3 
	.byte	W36
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N36   , An3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N36   , Gn3 
	.byte	W36
	.byte		        Fs3 
	.byte	W36
	.byte		N24   , En3 
	.byte	W24
	.byte		N36   , Fs3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		PAN   , c_v+22
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Fs3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Dn3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_battle38_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_battle38_2:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 15
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N12   , Dn4 , v108
	.byte	W48
	.byte		TIE   , As4 
	.byte	W48
	.byte	W96
	.byte		EOT   
	.byte		N12   , An4 
	.byte	W96
bgm_battle38_2_000:
	.byte		N12   , An4 , v096
	.byte	W72
	.byte		N24   , As4 , v108
	.byte	W24
	.byte	PEND
	.byte		N12   , Cn5 
	.byte	W72
	.byte		        As4 
	.byte	W24
	.byte		        An4 
	.byte	W48
	.byte		N48   , As4 
	.byte	W48
	.byte		N12   , An4 
	.byte	W96
	.byte	PATT
	 .word	bgm_battle38_2_000
	.byte		N12   , Cn5 , v108
	.byte	W72
	.byte		N24   , As4 
	.byte	W24
	.byte		N12   , An4 
	.byte	W36
	.byte		        Gn4 
	.byte	W36
	.byte		N24   , As4 
	.byte	W24
bgm_battle38_2_B1:
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Dn4 , v112
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Dn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N24   , Ds4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Ds4 
	.byte	W12
	.byte		N24   , Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An4 
	.byte	W24
	.byte		        Dn4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As4 
	.byte	W24
	.byte		N36   , An4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Dn4 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , An4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , As4 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Ds4 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , As4 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , Cn5 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Fn4 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Cn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N48   , Ds5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		N48   , Dn5 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte	W24
	.byte		VOICE , 48
	.byte		N12   , Cn5 , v100
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        As4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		TIE   , Dn5 
	.byte	W96
	.byte	W96
	.byte		VOL   , 74*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        70*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        65*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        60*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        53*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        45*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        35*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        25*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        15*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        7*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		EOT   
	.byte	W06
	.byte	W96
	.byte		VOICE , 60
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		N24   , As3 
	.byte	W24
	.byte		TIE   , Cn4 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte		N24   , An3 
	.byte	W24
	.byte		TIE   , Dn4 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte		N24   , An3 
	.byte	W24
	.byte		TIE   , Ds4 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		TIE   , Fs4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 48
	.byte		N24   , As3 
	.byte	W24
	.byte		TIE   , Cn5 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte		N24   , An3 
	.byte	W24
	.byte		TIE   , Dn5 
	.byte	W72
	.byte	W96
	.byte		EOT   
	.byte		N24   , An3 
	.byte	W24
	.byte		TIE   , Ds5 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N24   , Cn5 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		TIE   , Fs4 
	.byte	W96
	.byte	W30
	.byte		VOL   , 78*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        76*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        70*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        65*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        58*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        54*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        44*bgm_battle38_mvl/mxv
	.byte	W06
	.byte		        32*bgm_battle38_mvl/mxv
	.byte	W03
	.byte		EOT   
	.byte	W03
	.byte		VOICE , 56
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		N36   , Gn3 , v116
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Fs3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , Fs3 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , En3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Dn3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , En3 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , Dn3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N36   , Dn3 
	.byte	W18
	.byte		MOD   , 6
	.byte	W18
	.byte		        0
	.byte		N36   , En3 
	.byte	W21
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte		N24   , Fs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 48
	.byte		MOD   , 0
	.byte		N36   , Gn4 , v100
	.byte	W36
	.byte		        Fs4 
	.byte	W36
	.byte		N24   , En4 
	.byte	W24
	.byte		N36   , Fs4 
	.byte	W36
	.byte		        En4 
	.byte	W36
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N36   , En4 
	.byte	W36
	.byte		        Dn4 
	.byte	W36
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N36   , Dn4 
	.byte	W36
	.byte		        En4 
	.byte	W36
	.byte		N24   , Fs4 
	.byte	W24
	.byte		TIE   , Cn4 
	.byte	W96
	.byte	W84
	.byte		EOT   
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W84
	.byte		EOT   
	.byte		N06   
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_battle38_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_battle38_3:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 38
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		N12   , Dn1 , v120
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte		N12   
	.byte	W48
bgm_battle38_3_000:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte	PEND
bgm_battle38_3_001:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , An1 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_3_000
bgm_battle38_3_002:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		N24   , Cn2 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_3_000
	.byte	PATT
	 .word	bgm_battle38_3_001
	.byte	PATT
	 .word	bgm_battle38_3_000
	.byte	PATT
	 .word	bgm_battle38_3_002
bgm_battle38_3_B1:
bgm_battle38_3_003:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte		N12   , Ds1 , v120
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Ds1 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
bgm_battle38_3_004:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
bgm_battle38_3_005:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
bgm_battle38_3_006:
	.byte		N12   , Dn1 , v120
	.byte	W24
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_006
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_006
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_004
	.byte	PATT
	 .word	bgm_battle38_3_005
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
bgm_battle38_3_007:
	.byte		N12   , Dn1 , v120
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_3_007
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	PATT
	 .word	bgm_battle38_3_003
	.byte	GOTO
	 .word	bgm_battle38_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_battle38_4:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 80
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		LFOS  , 15
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v-48
	.byte		N12   , Dn3 , v060
	.byte	W48
	.byte		TIE   , As3 
	.byte	W48
	.byte		MOD   , 7
	.byte	W96
	.byte		EOT   
	.byte		MOD   , 0
	.byte		N12   , An3 
	.byte	W96
	.byte		PAN   , c_v+0
	.byte		N12   , An3 , v052
	.byte	W72
	.byte		N24   , As3 , v060
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W72
	.byte		        As3 
	.byte	W24
	.byte		        An3 
	.byte	W48
	.byte		N48   , As3 
	.byte	W48
	.byte		N12   , An3 
	.byte	W96
	.byte		        An3 , v052
	.byte	W72
	.byte		N24   , As3 , v060
	.byte	W24
	.byte		N12   , Cn4 
	.byte	W72
	.byte		N24   , As3 
	.byte	W24
	.byte		N12   , An3 
	.byte	W36
	.byte		        Gn3 
	.byte	W36
	.byte		N24   , As3 
	.byte	W24
bgm_battle38_4_B1:
	.byte		PAN   , c_v+0
	.byte		N36   , Dn3 , v072
	.byte	W36
	.byte		N24   , An2 
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W96
	.byte		N36   
	.byte	W36
	.byte		N24   , Ds3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W96
	.byte		N12   , Dn3 , v060
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N24   , Gn3 
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		N24   , An3 
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOICE , 81
	.byte		PAN   , c_v-48
	.byte		N12   , Ds3 , v048
	.byte	W12
	.byte		        Ds2 
	.byte	W12
	.byte		        As2 
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
bgm_battle38_4_000:
	.byte		N12   , Dn3 , v048
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
bgm_battle38_4_001:
	.byte		N12   , Dn3 , v048
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_001
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_001
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	PATT
	 .word	bgm_battle38_4_000
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 80
	.byte		N12   , Cn3 , v060
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 , v048
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 , v044
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        An4 , v036
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W12
	.byte		        Gn4 , v024
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 , v020
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 , v016
	.byte	W12
	.byte		        Gn2 , v060
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 , v048
	.byte	W12
	.byte		        Gn4 , v044
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 , v040
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 , v036
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 , v028
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 , v024
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 , v020
	.byte	W12
	.byte		        An3 , v016
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle38_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_battle38_5:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 82
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		LFOS  , 15
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v+0
	.byte		N12   , An2 , v060
	.byte	W48
	.byte		        Ds3 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		MOD   , 7
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		MOD   , 0
	.byte		N12   , Dn3 
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
bgm_battle38_5_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 80
	.byte		PAN   , c_v+48
	.byte		BEND  , c_v-2
	.byte		N48   , Ds3 , v052
	.byte	W48
	.byte		        Dn3 
	.byte	W48
	.byte		N84   , Cn4 
	.byte	W84
	.byte		N12   , Cs4 , v060
	.byte	W12
	.byte		N48   , Dn4 
	.byte	W48
	.byte		        Cn4 
	.byte	W48
	.byte		        Bn3 
	.byte	W48
	.byte		        An3 
	.byte	W48
	.byte		        Fs3 
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte		        Dn3 , v052
	.byte	W48
	.byte		        En3 
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		BEND  , c_v+0
	.byte	W24
	.byte		VOICE , 82
	.byte		N12   , Cn4 , v060
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W24
	.byte		VOICE , 82
	.byte		N12   , Dn4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	W24
	.byte		VOICE , 82
	.byte		N12   , Ds4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		VOICE , 82
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N24   
	.byte	W24
	.byte		N12   , Dn4 
	.byte	W12
	.byte		VOICE , 83
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W06
	.byte		VOL   , 78*bgm_battle38_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 76*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        70*bgm_battle38_mvl/mxv
	.byte		N12   
	.byte	W09
	.byte		VOL   , 65*bgm_battle38_mvl/mxv
	.byte	W03
	.byte		N12   
	.byte	W06
	.byte		VOL   , 58*bgm_battle38_mvl/mxv
	.byte	W06
	.byte		N12   
	.byte	W03
	.byte		VOL   , 54*bgm_battle38_mvl/mxv
	.byte	W09
	.byte		        44*bgm_battle38_mvl/mxv
	.byte		N12   
	.byte	W06
	.byte		VOL   , 32*bgm_battle38_mvl/mxv
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 82
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte	W12
	.byte		N12   , Cn3 , v052
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Cn5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 , v044
	.byte	W12
	.byte		        Cn5 , v040
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cn5 , v036
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 , v032
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 , v028
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 , v024
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 , v028
	.byte	W12
	.byte		        Gn2 , v052
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 , v036
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 , v028
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        Dn4 , v024
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	GOTO
	 .word	bgm_battle38_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_battle38_6:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 80
	.byte		XCMD  , xIECV , 10
	.byte		        xIECL , 8
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
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
bgm_battle38_6_B1:
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
	.byte		VOICE , 4
	.byte		N06   , Gn4 , v060
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gn4 , v052
	.byte	W12
	.byte		        An4 , v048
	.byte	W12
	.byte		        Gn4 , v040
	.byte	W12
	.byte		        An4 , v032
	.byte	W60
	.byte		        An4 , v060
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 , v052
	.byte	W12
	.byte		        Bn4 , v044
	.byte	W12
	.byte		        An4 , v040
	.byte	W12
	.byte		        Bn4 , v032
	.byte	W60
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
	 .word	bgm_battle38_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_battle38_7:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 0
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Dn1 , v056
	.byte	W06
	.byte		        Dn1 , v060
	.byte	W06
	.byte		        Dn1 , v064
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v092
	.byte	W06
	.byte		        Dn1 , v096
	.byte	W06
	.byte		        Dn1 , v100
	.byte	W06
	.byte		        Dn1 , v104
	.byte	W06
	.byte		N12   , Dn1 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle38_7_B1:
bgm_battle38_7_000:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
bgm_battle38_7_001:
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	W24
	.byte		N12   , Dn1 , v112
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
bgm_battle38_7_002:
	.byte	W24
	.byte		N12   , Ds1 , v092
	.byte	W48
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_7_002
	.byte	PATT
	 .word	bgm_battle38_7_002
	.byte	W24
	.byte		N12   , Ds1 , v092
	.byte	W48
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_001
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_001
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_000
	.byte	PATT
	 .word	bgm_battle38_7_001
	.byte	GOTO
	 .word	bgm_battle38_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_battle38_8:
	.byte	KEYSH , bgm_battle38_key+0
	.byte		VOICE , 47
	.byte		VOL   , 80*bgm_battle38_mvl/mxv
	.byte		PAN   , c_v-8
	.byte		N12   , Dn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
bgm_battle38_8_000:
	.byte		N12   , Dn2 , v112
	.byte	W48
	.byte		N12   
	.byte	W48
	.byte	PEND
bgm_battle38_8_001:
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
	.byte	PATT
	 .word	bgm_battle38_8_001
bgm_battle38_8_B1:
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	W12
	.byte		N12   , Dn2 , v112
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
bgm_battle38_8_002:
	.byte		N12   , Dn2 , v112
	.byte	W36
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_002
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	PATT
	 .word	bgm_battle38_8_000
	.byte	GOTO
	 .word	bgm_battle38_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_battle38:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_battle38_pri	@ Priority
	.byte	bgm_battle38_rev	@ Reverb.

	.word	bgm_battle38_grp

	.word	bgm_battle38_1
	.word	bgm_battle38_2
	.word	bgm_battle38_3
	.word	bgm_battle38_4
	.word	bgm_battle38_5
	.word	bgm_battle38_6
	.word	bgm_battle38_7
	.word	bgm_battle38_8

	.end
