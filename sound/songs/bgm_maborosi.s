	.include "MPlayDef.s"

	.equ	bgm_maborosi_grp, voicegroup_868E67C
	.equ	bgm_maborosi_pri, 0
	.equ	bgm_maborosi_rev, reverb_set+50
	.equ	bgm_maborosi_mvl, 127
	.equ	bgm_maborosi_key, 0
	.equ	bgm_maborosi_tbs, 1
	.equ	bgm_maborosi_exg, 0
	.equ	bgm_maborosi_cmp, 1

	.section .rodata
	.global	bgm_maborosi
	.align	2

@********************** Track  1 **********************@

bgm_maborosi_1:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_1_B1:
	.byte	TEMPO , 140*bgm_maborosi_tbs/2
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 100*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W60
	.byte		N06   , An2 , v064
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		VOICE , 60
	.byte		N60   , Bn2 , v080
	.byte	W60
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N60   , As3 
	.byte	W60
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		TIE   , Fn3 
	.byte	W72
	.byte	W48
	.byte		EOT   
	.byte		N12   , Ds3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		N60   , Fs3 
	.byte	W60
	.byte		N06   , An3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N60   , Bn3 
	.byte	W60
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte	W06
	.byte		N60   , As3 
	.byte	W60
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N60   , Cn4 
	.byte	W60
	.byte		N06   , Bn3 , v064
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		N72   , Gs3 
	.byte	W72
	.byte		N24   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte	W72
	.byte	W72
	.byte		VOICE , 14
	.byte		N60   , Fs3 , v060
	.byte	W60
	.byte		N06   , Dn3 , v064
	.byte	W12
	.byte		N60   , Fs3 
	.byte	W60
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N72   , As3 
	.byte	W72
	.byte		VOICE , 73
	.byte		N06   , Fn4 , v048
	.byte	W12
	.byte		        As3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N60   , Bn4 
	.byte	W60
	.byte		N06   , Cn5 , v040
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N60   , Dn5 
	.byte	W60
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N48   , Cs5 
	.byte	W48
	.byte		N06   , Ds5 , v064
	.byte	W12
	.byte		        Bn4 , v040
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Gs4 
	.byte	W12
	.byte		N60   , Dn4 , v048
	.byte	W60
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        As3 
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		N60   , Cn4 
	.byte	W60
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N60   , Cn4 
	.byte	W60
	.byte		VOICE , 60
	.byte		N06   , An2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte	GOTO
	 .word	bgm_maborosi_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_maborosi_2:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_2_B1:
	.byte		VOICE , 46
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		VOL   , 84*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v-32
	.byte		N06   , Bn2 , v064
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
bgm_maborosi_2_000:
	.byte		PAN   , c_v-16
	.byte		N06   , Fs4 , v064
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte	PEND
bgm_maborosi_2_001:
	.byte		PAN   , c_v+48
	.byte		N06   , As5 , v064
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte	PEND
	.byte		PAN   , c_v+24
	.byte		N04   , As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , Ds4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N06   , Bn2 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_2_000
	.byte	PATT
	 .word	bgm_maborosi_2_001
	.byte		PAN   , c_v+27
	.byte		N04   , As4 , v064
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , Cn4 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		PAN   , c_v-32
	.byte		N06   , Dn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Gs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		N06   , Gs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Fs5 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		        Bn5 
	.byte	W12
	.byte		PAN   , c_v+48
	.byte		N06   , Cs6 
	.byte	W12
	.byte		        Gs5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Fn5 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Ds5 
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		N04   , Cn5 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		PAN   , c_v-48
	.byte		N04   , Fn4 
	.byte	W08
	.byte		        Cn4 
	.byte	W04
	.byte		VOICE , 47
	.byte		PAN   , c_v-32
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fs1 , v048
	.byte	W06
	.byte		PAN   , c_v+34
	.byte		VOL   , 100*bgm_maborosi_mvl/mxv
	.byte		N12   , Bn1 , v064
	.byte	W60
	.byte		PAN   , c_v-32
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Fs1 , v044
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N06   , Bn1 , v032
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		        Bn1 , v040
	.byte	W12
	.byte		        Bn1 , v048
	.byte	W12
	.byte		        Bn1 , v068
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		N06   , Ds1 , v084
	.byte	W06
	.byte		        Ds1 , v064
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N12   , As1 
	.byte	W60
	.byte		PAN   , c_v-32
	.byte		N06   , Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+31
	.byte		N12   , Cn2 
	.byte	W24
	.byte		PAN   , c_v-33
	.byte		N06   , Fs1 , v048
	.byte	W12
	.byte		PAN   , c_v+30
	.byte		N06   , Fs2 , v064
	.byte	W12
	.byte		PAN   , c_v-33
	.byte		N12   , Fs1 , v048
	.byte	W12
	.byte		N06   , Fs1 , v044
	.byte	W12
	.byte		VOICE , 73
	.byte		PAN   , c_v+0
	.byte		N60   , Fs4 , v064
	.byte	W60
	.byte		N03   , Gs4 , v036
	.byte	W03
	.byte		        An4 , v040
	.byte	W03
	.byte		        Bn4 , v044
	.byte	W03
	.byte		        Cs5 , v048
	.byte	W03
	.byte		VOL   , 85*bgm_maborosi_mvl/mxv
	.byte		N60   , Dn5 , v064
	.byte	W60
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N60   , Cs5 
	.byte	W60
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Fn4 , v044
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Bn4 , v064
	.byte	W06
	.byte		        Fn4 , v044
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Cn5 , v064
	.byte	W06
	.byte		        Fn4 , v044
	.byte	W06
	.byte		        As4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N60   , Dn5 , v064
	.byte	W60
	.byte		N06   , Ds5 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		N60   , Fs5 
	.byte	W60
	.byte		N06   , Ds5 
	.byte	W12
	.byte		N48   , Fn5 
	.byte	W48
	.byte		N06   , Fs5 
	.byte	W12
	.byte		        Ds5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		N12   , As4 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N06   , Bn4 
	.byte	W12
bgm_maborosi_2_002:
	.byte		N60   , As4 , v064
	.byte	W60
	.byte		N06   , Gs4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte	PEND
	.byte		N24   , Fn4 
	.byte	W24
	.byte		        Fs4 
	.byte	W24
	.byte		        Gs4 
	.byte	W24
	.byte	PATT
	 .word	bgm_maborosi_2_002
	.byte		N60   , Fn4 , v064
	.byte	W72
	.byte	GOTO
	 .word	bgm_maborosi_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_maborosi_3:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_3_B1:
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 73*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v+18
	.byte		N12   , Fs4 , v024
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Gs4 , v036
	.byte	W12
	.byte		        Fs4 , v040
	.byte	W12
	.byte		        Gs4 , v044
	.byte	W12
bgm_maborosi_3_000:
	.byte		N12   , Fs4 , v048
	.byte	W12
	.byte		        Gs4 , v052
	.byte	W12
	.byte		        Fs4 , v056
	.byte	W12
	.byte		        Gs4 , v060
	.byte	W12
	.byte		        Fs4 , v064
	.byte	W12
	.byte		        Gs4 , v068
	.byte	W12
	.byte	PEND
bgm_maborosi_3_001:
	.byte		N12   , Fn4 , v072
	.byte	W12
	.byte		        As4 , v068
	.byte	W12
	.byte		        Fn4 , v064
	.byte	W12
	.byte		        As4 , v060
	.byte	W12
	.byte		        Fn4 , v056
	.byte	W12
	.byte		        As4 , v048
	.byte	W12
	.byte	PEND
bgm_maborosi_3_002:
	.byte		N12   , Fn4 , v044
	.byte	W12
	.byte		        As4 , v040
	.byte	W12
	.byte		        Fn4 , v036
	.byte	W12
	.byte		        As4 , v028
	.byte	W12
	.byte		        Fn4 , v024
	.byte	W12
	.byte		        As4 , v020
	.byte	W12
	.byte	PEND
bgm_maborosi_3_003:
	.byte		N12   , Fs4 , v024
	.byte	W12
	.byte		        Gs4 , v028
	.byte	W12
	.byte		        Fs4 , v032
	.byte	W12
	.byte		        Gs4 , v036
	.byte	W12
	.byte		        Fs4 , v040
	.byte	W12
	.byte		        Gs4 , v044
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_maborosi_3_000
	.byte		N12   , Fn4 , v076
	.byte	W12
	.byte		        As4 , v072
	.byte	W12
	.byte		        Fn4 , v064
	.byte	W12
	.byte		        As4 , v060
	.byte	W12
	.byte		        Fn4 , v056
	.byte	W12
	.byte		        As4 , v052
	.byte	W12
	.byte		        Fn4 , v048
	.byte	W12
	.byte		        As4 , v044
	.byte	W12
	.byte		        Fn4 , v040
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		        Fn4 , v028
	.byte	W12
	.byte		        As4 , v024
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_3_003
	.byte	PATT
	 .word	bgm_maborosi_3_000
bgm_maborosi_3_004:
	.byte		N12   , Fn4 , v072
	.byte	W12
	.byte		        As4 , v068
	.byte	W12
	.byte		        Fn4 , v064
	.byte	W12
	.byte		        As4 , v060
	.byte	W12
	.byte		        Fn4 , v056
	.byte	W12
	.byte		        As4 , v052
	.byte	W12
	.byte	PEND
	.byte		        Fn4 , v044
	.byte	W12
	.byte		        As4 , v040
	.byte	W12
	.byte		        Fn4 , v036
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		        Fn4 , v028
	.byte	W12
	.byte		        As4 , v024
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_3_003
	.byte	PATT
	 .word	bgm_maborosi_3_000
	.byte	PATT
	 .word	bgm_maborosi_3_004
	.byte		N12   , Fn4 , v044
	.byte	W12
	.byte		        As4 , v040
	.byte	W12
	.byte		        Fn4 , v036
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		        Fn4 , v028
	.byte	W12
	.byte		        As4 , v020
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_3_003
	.byte	PATT
	 .word	bgm_maborosi_3_000
	.byte	PATT
	 .word	bgm_maborosi_3_004
	.byte		N12   , Fn4 , v048
	.byte	W12
	.byte		        As4 , v044
	.byte	W12
	.byte		        Fn4 , v036
	.byte	W12
	.byte		        As4 , v032
	.byte	W12
	.byte		        Fn4 , v028
	.byte	W12
	.byte		        As4 , v024
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_3_003
	.byte	PATT
	 .word	bgm_maborosi_3_000
	.byte		N12   , Fn4 , v076
	.byte	W12
	.byte		        As4 , v072
	.byte	W12
	.byte		        Fn4 , v068
	.byte	W12
	.byte		        As4 , v060
	.byte	W12
	.byte		        Fn4 , v056
	.byte	W12
	.byte		        As4 , v052
	.byte	W12
	.byte		        Fn4 , v048
	.byte	W12
	.byte		        As4 , v044
	.byte	W12
	.byte		        Fn4 , v040
	.byte	W12
	.byte		        As4 , v036
	.byte	W12
	.byte		        Fn4 , v032
	.byte	W12
	.byte		        As4 , v028
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_3_003
	.byte	PATT
	 .word	bgm_maborosi_3_000
	.byte	PATT
	 .word	bgm_maborosi_3_001
	.byte	PATT
	 .word	bgm_maborosi_3_002
	.byte	GOTO
	 .word	bgm_maborosi_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_maborosi_4:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_4_B1:
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v-62
	.byte		TIE   , Dn3 , v064
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
bgm_maborosi_4_000:
	.byte		N60   , Fn3 , v064
	.byte	W60
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte	PEND
bgm_maborosi_4_001:
	.byte		N60   , Cn3 , v064
	.byte	W60
	.byte		N06   , Bn2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte	PEND
	.byte		TIE   , Dn3 
	.byte	W72
	.byte	W66
	.byte		EOT   
	.byte		N06   , Cs3 
	.byte	W06
bgm_maborosi_4_002:
	.byte		N60   , Cn3 , v064
	.byte	W60
	.byte		N06   , As2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte	PEND
bgm_maborosi_4_003:
	.byte		N66   , Fn2 , v064
	.byte	W66
	.byte		N06   , Fs2 
	.byte	W06
	.byte	PEND
	.byte		TIE   , Gn2 
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
bgm_maborosi_4_004:
	.byte		N60   , Fs3 , v064
	.byte	W60
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte	PEND
	.byte		N72   , Fn3 
	.byte	W72
	.byte		TIE   , Dn3 
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_4_000
	.byte	PATT
	 .word	bgm_maborosi_4_001
	.byte		TIE   , Dn3 , v064
	.byte	W72
	.byte	W66
	.byte		EOT   
	.byte		N06   , Cs3 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_4_002
	.byte	PATT
	 .word	bgm_maborosi_4_003
	.byte		TIE   , Gn2 , v064
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   , Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_4_004
	.byte		N72   , Fn3 , v064
	.byte	W72
	.byte		TIE   , Dn3 
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_4_000
	.byte	PATT
	 .word	bgm_maborosi_4_001
	.byte	GOTO
	 .word	bgm_maborosi_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_maborosi_5:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_5_B1:
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 50*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		TIE   , Gs3 , v064
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		TIE   , As3 
	.byte	W72
	.byte	W66
	.byte		EOT   
	.byte		N06   , An3 
	.byte	W06
bgm_maborosi_5_000:
	.byte		N60   , Gs3 , v064
	.byte	W60
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
bgm_maborosi_5_001:
	.byte		N60   , Dn4 , v064
	.byte	W60
	.byte		N12   , Bn3 
	.byte	W12
	.byte	PEND
bgm_maborosi_5_002:
	.byte		N60   , Cs4 , v064
	.byte	W60
	.byte		N12   , As3 
	.byte	W12
	.byte	PEND
bgm_maborosi_5_003:
	.byte		N66   , Cn4 , v064
	.byte	W66
	.byte		N06   , Fn3 
	.byte	W06
	.byte	PEND
bgm_maborosi_5_004:
	.byte		N60   , Fs3 , v064
	.byte	W60
	.byte		N06   , Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_maborosi_5_001
bgm_maborosi_5_005:
	.byte		N60   , Cs4 , v064
	.byte	W60
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte	PEND
	.byte		N72   , Cn4 
	.byte	W72
	.byte		TIE   , Gs3 
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		TIE   , As3 
	.byte	W72
	.byte	W66
	.byte		EOT   
	.byte		N06   , An3 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_5_000
	.byte	PATT
	 .word	bgm_maborosi_5_001
	.byte	PATT
	 .word	bgm_maborosi_5_002
	.byte	PATT
	 .word	bgm_maborosi_5_003
	.byte	PATT
	 .word	bgm_maborosi_5_004
	.byte	PATT
	 .word	bgm_maborosi_5_001
	.byte	PATT
	 .word	bgm_maborosi_5_005
	.byte		N72   , Cn4 , v064
	.byte	W72
	.byte		TIE   , Gs3 
	.byte	W72
	.byte	W60
	.byte		EOT   
	.byte		N06   
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		TIE   , As3 
	.byte	W72
	.byte	W66
	.byte		EOT   
	.byte		N06   , An3 
	.byte	W06
	.byte	GOTO
	 .word	bgm_maborosi_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_maborosi_6:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_6_B1:
	.byte		VOICE , 0
	.byte		VOL   , 93*bgm_maborosi_mvl/mxv
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
	.byte	W72
	.byte	W72
	.byte		N48   , An2 , v052
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
	.byte	W72
	.byte	W72
	.byte	GOTO
	 .word	bgm_maborosi_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_maborosi_7:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_7_B1:
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 75*bgm_maborosi_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N60   , Bn1 , v064
	.byte	W60
	.byte		N06   , Fs1 
	.byte	W12
bgm_maborosi_7_000:
	.byte		N24   , Bn1 , v064
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N03   , As1 
	.byte	W03
	.byte		N09   , Bn1 
	.byte	W09
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PEND
bgm_maborosi_7_001:
	.byte		N60   , Fs1 , v064
	.byte	W60
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PEND
bgm_maborosi_7_002:
	.byte		N30   , Fs1 , v064
	.byte	W36
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W03
	.byte		N09   , Fs1 
	.byte	W09
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PEND
bgm_maborosi_7_003:
	.byte		N60   , Bn1 , v064
	.byte	W60
	.byte		N06   , Fs1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	bgm_maborosi_7_000
	.byte	PATT
	 .word	bgm_maborosi_7_001
	.byte		N24   , Fs1 , v064
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Cn1 
	.byte	W12
	.byte		N03   , Fn1 
	.byte	W03
	.byte		N09   , Fs1 
	.byte	W09
	.byte		N06   , Dn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
bgm_maborosi_7_004:
	.byte		N60   , Gn1 , v064
	.byte	W60
	.byte		N06   , Bn0 
	.byte	W12
	.byte	PEND
bgm_maborosi_7_005:
	.byte		N48   , Gn1 , v064
	.byte	W48
	.byte		N06   , Bn0 
	.byte	W12
	.byte		N12   , Gn1 
	.byte	W12
	.byte	PEND
bgm_maborosi_7_006:
	.byte		N48   , Fs1 , v064
	.byte	W48
	.byte		N06   , Cs1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	PEND
	.byte		N36   , Fs1 
	.byte	W36
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N06   , As1 
	.byte	W12
bgm_maborosi_7_007:
	.byte		N60   , Bn1 , v064
	.byte	W60
	.byte		N06   , Fs1 
	.byte	W12
	.byte	PEND
	.byte		N24   , Bn1 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		N12   , Bn1 
	.byte	W12
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_7_001
	.byte		N30   , Fs1 , v064
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_7_003
	.byte		N60   , Bn1 , v064
	.byte	W60
	.byte		N06   , An1 
	.byte	W06
	.byte		        Gn1 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_7_001
	.byte		N24   , Fs1 , v064
	.byte	W36
	.byte		N06   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W06
	.byte		        Fs1 
	.byte	W06
	.byte	PATT
	 .word	bgm_maborosi_7_004
	.byte	PATT
	 .word	bgm_maborosi_7_005
	.byte	PATT
	 .word	bgm_maborosi_7_006
	.byte		N36   , Fs1 , v064
	.byte	W36
	.byte		N06   , Cn1 
	.byte	W12
	.byte		N12   , Fs1 
	.byte	W12
	.byte		N06   , Cn1 
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_7_007
	.byte	PATT
	 .word	bgm_maborosi_7_000
	.byte	PATT
	 .word	bgm_maborosi_7_001
	.byte	PATT
	 .word	bgm_maborosi_7_002
	.byte	GOTO
	 .word	bgm_maborosi_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_maborosi_8:
	.byte	KEYSH , bgm_maborosi_key+0
bgm_maborosi_8_B1:
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 100*bgm_maborosi_mvl/mxv
	.byte		PAN   , c_v-17
	.byte		N12   , Bn3 , v024
	.byte	W12
	.byte		        Dn4 , v028
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 , v036
	.byte	W12
	.byte		        Bn3 , v040
	.byte	W12
	.byte		        Dn4 , v044
	.byte	W12
bgm_maborosi_8_000:
	.byte		N12   , Bn3 , v048
	.byte	W12
	.byte		        Dn4 , v052
	.byte	W12
	.byte		        Bn3 , v056
	.byte	W12
	.byte		        Dn4 , v060
	.byte	W12
	.byte		        Bn3 , v064
	.byte	W12
	.byte		        Dn4 , v068
	.byte	W12
	.byte	PEND
bgm_maborosi_8_001:
	.byte		N12   , As3 , v072
	.byte	W12
	.byte		        Cn4 , v068
	.byte	W12
	.byte		        As3 , v064
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W12
	.byte		        As3 , v056
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte	PEND
bgm_maborosi_8_002:
	.byte		N12   , As3 , v044
	.byte	W12
	.byte		        Cn4 , v040
	.byte	W12
	.byte		        As3 , v036
	.byte	W12
	.byte		        Cn4 , v028
	.byte	W12
	.byte		        As3 , v024
	.byte	W12
	.byte		        Cn4 , v020
	.byte	W12
	.byte	PEND
bgm_maborosi_8_003:
	.byte		N12   , Bn3 , v032
	.byte	W12
	.byte		        Dn4 , v068
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte	PEND
bgm_maborosi_8_004:
	.byte		N12   , Bn3 , v052
	.byte	W12
	.byte		        Dn4 , v064
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Bn3 , v036
	.byte	W12
	.byte		        Dn4 , v048
	.byte	W12
	.byte	PEND
bgm_maborosi_8_005:
	.byte		N12   , As3 , v064
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        As3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
bgm_maborosi_8_006:
	.byte		N12   , As3 , v052
	.byte	W12
	.byte		        Cn4 , v064
	.byte	W12
	.byte		        As3 , v032
	.byte	W12
	.byte		        Cn4 
	.byte	W12
	.byte		        As3 , v036
	.byte	W12
	.byte		        Cn4 , v048
	.byte	W12
	.byte	PEND
bgm_maborosi_8_007:
	.byte		N12   , Fs3 , v064
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs3 , v032
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
bgm_maborosi_8_008:
	.byte		N12   , Gn3 , v052
	.byte	W12
	.byte		        Bn3 , v064
	.byte	W12
	.byte		        Gn3 , v032
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn3 , v036
	.byte	W12
	.byte		        Bn3 , v048
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_maborosi_8_005
	.byte	PATT
	 .word	bgm_maborosi_8_006
bgm_maborosi_8_009:
	.byte		N12   , Bn3 , v024
	.byte	W12
	.byte		        Dn4 , v028
	.byte	W12
	.byte		        Bn3 , v032
	.byte	W12
	.byte		        Dn4 , v036
	.byte	W12
	.byte		        Bn3 , v040
	.byte	W12
	.byte		        Dn4 , v044
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_maborosi_8_000
	.byte		N12   , As3 , v076
	.byte	W12
	.byte		        Cn4 , v072
	.byte	W12
	.byte		        As3 , v068
	.byte	W12
	.byte		        Cn4 , v060
	.byte	W12
	.byte		        As3 , v056
	.byte	W12
	.byte		        Cn4 , v052
	.byte	W12
	.byte		        As3 , v044
	.byte	W12
	.byte		        Cn4 , v040
	.byte	W12
	.byte		        As3 , v036
	.byte	W12
	.byte		        Cn4 , v032
	.byte	W12
	.byte		        As3 , v024
	.byte	W12
	.byte		        Cn4 , v020
	.byte	W12
	.byte	PATT
	 .word	bgm_maborosi_8_003
	.byte	PATT
	 .word	bgm_maborosi_8_004
	.byte	PATT
	 .word	bgm_maborosi_8_005
	.byte	PATT
	 .word	bgm_maborosi_8_006
	.byte	PATT
	 .word	bgm_maborosi_8_007
	.byte	PATT
	 .word	bgm_maborosi_8_008
	.byte	PATT
	 .word	bgm_maborosi_8_005
	.byte	PATT
	 .word	bgm_maborosi_8_006
	.byte	PATT
	 .word	bgm_maborosi_8_009
	.byte	PATT
	 .word	bgm_maborosi_8_000
	.byte	PATT
	 .word	bgm_maborosi_8_001
	.byte	PATT
	 .word	bgm_maborosi_8_002
	.byte	GOTO
	 .word	bgm_maborosi_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_maborosi:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_maborosi_pri	@ Priority
	.byte	bgm_maborosi_rev	@ Reverb.

	.word	bgm_maborosi_grp

	.word	bgm_maborosi_1
	.word	bgm_maborosi_2
	.word	bgm_maborosi_3
	.word	bgm_maborosi_4
	.word	bgm_maborosi_5
	.word	bgm_maborosi_6
	.word	bgm_maborosi_7
	.word	bgm_maborosi_8

	.end
