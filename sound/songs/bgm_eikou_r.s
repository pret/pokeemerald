	.include "MPlayDef.s"

	.equ	bgm_eikou_r_grp, voicegroup_8691C7C
	.equ	bgm_eikou_r_pri, 0
	.equ	bgm_eikou_r_rev, reverb_set+50
	.equ	bgm_eikou_r_mvl, 127
	.equ	bgm_eikou_r_key, 0
	.equ	bgm_eikou_r_tbs, 1
	.equ	bgm_eikou_r_exg, 0
	.equ	bgm_eikou_r_cmp, 1

	.section .rodata
	.global	bgm_eikou_r
	.align	2

@********************** Track  1 **********************@

bgm_eikou_r_1:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte	TEMPO , 114*bgm_eikou_r_tbs/2
	.byte		VOICE , 46
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 47*bgm_eikou_r_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W24
bgm_eikou_r_1_B1:
	.byte		PAN   , c_v-42
	.byte		N04   , As3 , v112
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Ds5 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        Dn2 
	.byte	W04
	.byte		        An1 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        Ds2 
	.byte	W04
	.byte		        As1 
	.byte	W04
	.byte		        Cn2 
	.byte	W04
	.byte		        Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte		N04   , Gn4 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		        Fn5 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , En5 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Gn2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        As3 
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Ds4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Cn5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Dn5 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , As4 
	.byte	W04
	.byte		        Gn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Fn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        As4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , En4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v+41
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , Dn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Dn4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte		PAN   , c_v-42
	.byte		N04   , Fs4 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Cs5 
	.byte	W04
	.byte		        An4 
	.byte	W04
	.byte		        Fs4 
	.byte	W04
	.byte		        En4 
	.byte	W04
	.byte	GOTO
	 .word	bgm_eikou_r_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_eikou_r_2:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+11
	.byte		VOL   , 31*bgm_eikou_r_mvl/mxv
	.byte		N04   , En3 , v112
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Bn3 
	.byte	W04
	.byte		        Cs4 
	.byte	W04
bgm_eikou_r_2_B1:
	.byte		N96   , Dn4 , v112
	.byte	W96
	.byte		        Cs4 
	.byte	W96
	.byte		N88   , Dn4 
	.byte	W88
	.byte		N08   , Ds4 
	.byte	W08
	.byte		N96   , En4 
	.byte	W96
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N96   , Dn4 
	.byte	W96
	.byte		        Cs4 
	.byte	W96
	.byte		        Dn4 
	.byte	W96
	.byte		        En4 
	.byte	W96
	.byte		TIE   , Fn4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , En4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_eikou_r_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_eikou_r_3:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 36
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 67*bgm_eikou_r_mvl/mxv
	.byte	W24
bgm_eikou_r_3_B1:
bgm_eikou_r_3_000:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N04   
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Dn2 
	.byte	W08
	.byte		N04   , Cn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PATT
	 .word	bgm_eikou_r_3_000
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N08   , Gn1 
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte	PATT
	 .word	bgm_eikou_r_3_000
	.byte	PATT
	 .word	bgm_eikou_r_3_000
	.byte	PATT
	 .word	bgm_eikou_r_3_000
	.byte		N08   , Dn1 , v112
	.byte	W08
	.byte		N04   , An1 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		N08   , Cn2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		N08   , An1 
	.byte	W08
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		N08   , Cn1 
	.byte	W08
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N32   , Ds1 
	.byte	W32
	.byte		N04   , As0 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte		        As0 
	.byte	W16
	.byte		N16   , Ds1 
	.byte	W16
	.byte		N12   , As1 
	.byte	W16
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N08   , En2 
	.byte	W08
	.byte		N04   , Dn2 
	.byte	W08
	.byte		        An1 
	.byte	W08
	.byte		N24   , Fs1 
	.byte	W24
	.byte		N04   , Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N32   , As1 
	.byte	W32
	.byte		N04   , Gn1 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		        Gn1 
	.byte	W16
	.byte		N16   , As1 
	.byte	W16
	.byte		N08   , Gn1 
	.byte	W16
	.byte		N32   , An1 
	.byte	W32
	.byte		N04   , Cn2 
	.byte	W08
	.byte		        As1 
	.byte	W08
	.byte		N32   , Cn2 
	.byte	W32
	.byte		N08   , Fn1 
	.byte	W16
	.byte		N40   , Dn2 
	.byte	W40
	.byte		N04   , As1 
	.byte	W08
	.byte		N16   , Fn1 
	.byte	W16
	.byte		        As1 
	.byte	W16
	.byte		        Cn2 
	.byte	W16
	.byte		N24   , Dn2 
	.byte	W24
	.byte		N08   , Fn2 
	.byte	W08
	.byte		N04   , En2 
	.byte	W08
	.byte		        Ds2 
	.byte	W08
	.byte		N48   , Dn2 
	.byte	W48
	.byte		N16   , En2 
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		        Fs1 
	.byte	W16
	.byte		        An1 
	.byte	W16
	.byte		        Cs2 
	.byte	W16
	.byte		N32   , En2 
	.byte	W32
	.byte		N08   , Ds2 
	.byte	W08
	.byte		        Dn2 
	.byte	W08
	.byte		N48   , Cs2 
	.byte	W48
	.byte	GOTO
	 .word	bgm_eikou_r_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_eikou_r_4:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-11
	.byte		VOL   , 31*bgm_eikou_r_mvl/mxv
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
bgm_eikou_r_4_B1:
	.byte		PAN   , c_v-10
	.byte		VOL   , 31*bgm_eikou_r_mvl/mxv
	.byte		N96   , Gn3 , v112
	.byte	W96
	.byte		        Fs3 
	.byte	W96
	.byte		        Gn3 
	.byte	W96
	.byte		        An3 
	.byte	W96
	.byte		TIE   , As3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 50*bgm_eikou_r_mvl/mxv
	.byte		N40   , Gn3 
	.byte	W40
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N04   , Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		N48   , An3 
	.byte	W48
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N12   , Cn4 
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		N40   , Cn4 
	.byte	W40
	.byte		N08   , Cs4 
	.byte	W08
	.byte		N40   , Dn4 
	.byte	W40
	.byte		N04   , As3 
	.byte	W08
	.byte		N16   , Fn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		        Cn4 
	.byte	W16
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W08
	.byte		N04   , As3 
	.byte	W08
	.byte		        Cn4 
	.byte	W08
	.byte		N48   , Dn4 
	.byte	W48
	.byte		N24   , Cs4 
	.byte	W24
	.byte		N04   , En4 
	.byte	W08
	.byte		        Ds4 
	.byte	W08
	.byte		        Dn4 
	.byte	W08
	.byte		N24   , Cs4 
	.byte	W32
	.byte		N04   , An3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N96   , Cs4 
	.byte	W96
	.byte	GOTO
	 .word	bgm_eikou_r_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_eikou_r_5:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-64
	.byte		VOL   , 34*bgm_eikou_r_mvl/mxv
	.byte		N04   , Gn2 , v112
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        As2 
	.byte	W04
	.byte		        Bn2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
bgm_eikou_r_5_B1:
	.byte		N96   , Ds3 , v112
	.byte	W96
	.byte		        Dn3 
	.byte	W96
	.byte		        Ds3 
	.byte	W96
	.byte		        Fn3 
	.byte	W96
	.byte		TIE   , Gn3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Fs3 
	.byte	W96
	.byte	W96
	.byte		EOT   
bgm_eikou_r_5_000:
	.byte		N32   , Ds3 , v112
	.byte	W32
	.byte		N04   , Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		N08   , As2 
	.byte	W08
	.byte		N16   , Gn2 
	.byte	W16
	.byte		        As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte	PEND
	.byte		N40   , Dn3 
	.byte	W40
	.byte		N08   , An2 
	.byte	W08
	.byte		N24   , Fs2 
	.byte	W24
	.byte		N04   , Dn2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Fs2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte	PATT
	 .word	bgm_eikou_r_5_000
	.byte		N40   , Fn3 , v112
	.byte	W40
	.byte		N08   , Cn3 
	.byte	W08
	.byte		N12   , An2 
	.byte	W12
	.byte		N04   , Fn2 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        An2 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N40   , Fn3 
	.byte	W40
	.byte		N04   , Dn3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Dn3 
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   , As2 
	.byte	W08
	.byte		        Cn3 
	.byte	W08
	.byte		        Dn3 
	.byte	W08
	.byte		N48   , Fn3 
	.byte	W48
	.byte		TIE   , Fs3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_eikou_r_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_eikou_r_6:
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 34*bgm_eikou_r_mvl/mxv
	.byte		N04   , Cs3 , v112
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
bgm_eikou_r_6_B1:
	.byte		N96   , As3 , v112
	.byte	W96
	.byte		        An3 
	.byte	W96
	.byte		        As3 
	.byte	W96
	.byte		        Cn4 
	.byte	W96
	.byte		TIE   , Dn4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		TIE   , Cs4 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte		N32   , As3 
	.byte	W32
	.byte		N04   , Cn4 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		N08   , Gn3 
	.byte	W08
	.byte		N16   , Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N04   , An2 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Dn3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		N32   , Gn3 
	.byte	W32
	.byte		N04   , As3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		N08   , Ds3 
	.byte	W08
	.byte		N16   , As2 
	.byte	W16
	.byte		        Ds3 
	.byte	W16
	.byte		        Gn3 
	.byte	W16
	.byte		N40   , An3 
	.byte	W40
	.byte		N08   
	.byte	W08
	.byte		N12   , Fn3 
	.byte	W12
	.byte		N04   , Cn3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        An3 
	.byte	W04
	.byte		        Cn4 
	.byte	W04
	.byte		        Fn4 
	.byte	W04
	.byte		N40   , As3 
	.byte	W40
	.byte		N04   , Fn3 
	.byte	W08
	.byte		N16   , Dn3 
	.byte	W16
	.byte		        Fn3 
	.byte	W16
	.byte		        As3 
	.byte	W16
	.byte		N24   
	.byte	W24
	.byte		N04   , Dn3 
	.byte	W08
	.byte		        Fn3 
	.byte	W08
	.byte		        An3 
	.byte	W08
	.byte		N48   , As3 
	.byte	W48
	.byte		TIE   , An3 
	.byte	W96
	.byte	W96
	.byte		EOT   
	.byte	GOTO
	 .word	bgm_eikou_r_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_eikou_r_7:
	.byte		VOL   , 80*bgm_eikou_r_mvl/mxv
	.byte	KEYSH , bgm_eikou_r_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte	W24
bgm_eikou_r_7_B1:
bgm_eikou_r_7_000:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N12   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
	.byte	PATT
	 .word	bgm_eikou_r_7_000
bgm_eikou_r_7_001:
	.byte		N04   , Dn1 , v112
	.byte	W24
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Dn2 
	.byte	W16
	.byte		        Dn1 
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	PATT
	 .word	bgm_eikou_r_7_001
	.byte	GOTO
	 .word	bgm_eikou_r_7_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_eikou_r:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_eikou_r_pri	@ Priority
	.byte	bgm_eikou_r_rev	@ Reverb.

	.word	bgm_eikou_r_grp

	.word	bgm_eikou_r_1
	.word	bgm_eikou_r_2
	.word	bgm_eikou_r_3
	.word	bgm_eikou_r_4
	.word	bgm_eikou_r_5
	.word	bgm_eikou_r_6
	.word	bgm_eikou_r_7

	.end
