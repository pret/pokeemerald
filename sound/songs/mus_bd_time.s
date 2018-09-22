	.include "MPlayDef.s"

	.equ	mus_bd_time_grp, voicegroup038
	.equ	mus_bd_time_pri, 0
	.equ	mus_bd_time_rev, reverb_set+50
	.equ	mus_bd_time_mvl, 127
	.equ	mus_bd_time_key, 0
	.equ	mus_bd_time_tbs, 1
	.equ	mus_bd_time_exg, 0
	.equ	mus_bd_time_cmp, 1

	.section .rodata
	.global	mus_bd_time
	.align	2

@********************** Track  1 **********************@

mus_bd_time_1:
	.byte	KEYSH , mus_bd_time_key+0
	.byte	TEMPO , 180*mus_bd_time_tbs/2
	.byte	W48
	.byte		VOICE , 38
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		PAN   , c_v-6
	.byte		N06   , Dn1 , v127
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
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An0 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Bn0 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	TEMPO , 170*mus_bd_time_tbs/2
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	TEMPO , 160*mus_bd_time_tbs/2
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	TEMPO , 150*mus_bd_time_tbs/2
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	TEMPO , 140*mus_bd_time_tbs/2
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	TEMPO , 130*mus_bd_time_tbs/2
	.byte		        Fn1 
	.byte	W12
	.byte		        Cn2 
	.byte	W12
	.byte	TEMPO , 120*mus_bd_time_tbs/2
	.byte		        Cn1 
	.byte	W12
	.byte		        Fn1 
	.byte	W12
	.byte	TEMPO , 110*mus_bd_time_tbs/2
	.byte		        Dn1 
	.byte	W12
	.byte		        Fs1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
mus_bd_time_1_000:
	.byte		N06   , An1 , v127
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_bd_time_1_000
mus_bd_time_1_B1:
	.byte	PATT
	 .word	mus_bd_time_1_000
	.byte	PATT
	 .word	mus_bd_time_1_000
	.byte	GOTO
	 .word	mus_bd_time_1_B1
	.byte	W96
	.byte	FINE

@********************** Track  2 **********************@

mus_bd_time_2:
	.byte	KEYSH , mus_bd_time_key+0
	.byte		VOICE , 17
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Dn3 , v092
	.byte	W06
	.byte		        Fs3 , v072
	.byte	W06
	.byte		        An3 , v040
	.byte	W06
	.byte		        Cs4 , v048
	.byte	W06
	.byte		        En4 , v056
	.byte	W06
	.byte		        Gn4 , v064
	.byte	W06
	.byte		        Bn4 , v068
	.byte	W06
	.byte		        Dn5 , v076
	.byte	W06
	.byte		N03   , Dn5 , v080
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , An4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N03   , Fn5 
	.byte	W12
	.byte		N12   , Cn5 
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W36
	.byte		N03   
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W12
	.byte		N12   , Dn5 
	.byte	W12
	.byte		N32   , Gn4 
	.byte	W36
	.byte		N03   
	.byte	W12
	.byte		        Gn5 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N03   , Gn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
mus_bd_time_2_000:
	.byte		N06   , An4 , v080
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		N24   , En4 
	.byte	W24
	.byte		        Gn4 
	.byte	W24
	.byte	PEND
mus_bd_time_2_001:
	.byte		N06   , An4 , v080
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	PEND
mus_bd_time_2_B1:
	.byte	PATT
	 .word	mus_bd_time_2_000
	.byte	PATT
	 .word	mus_bd_time_2_001
	.byte	GOTO
	 .word	mus_bd_time_2_B1
	.byte	W96
	.byte	FINE

@********************** Track  3 **********************@

mus_bd_time_3:
	.byte	KEYSH , mus_bd_time_key+0
	.byte		VOICE , 17
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		PAN   , c_v-10
	.byte	W03
	.byte		N06   , En3 , v080
	.byte	W06
	.byte		        Gn3 , v064
	.byte	W06
	.byte		        Bn3 , v044
	.byte	W06
	.byte		        Dn4 , v052
	.byte	W06
	.byte		        Fs4 , v060
	.byte	W06
	.byte		        An4 , v064
	.byte	W06
	.byte		        Cs5 , v072
	.byte	W06
	.byte		N03   , En5 , v080
	.byte	W03
	.byte		        An4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , An3 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Cn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N03   , Cn5 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N12   , Fn4 
	.byte	W12
	.byte		N32   , Dn4 
	.byte	W36
	.byte		N03   
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Gn4 
	.byte	W12
	.byte		N32   , Dn4 
	.byte	W36
	.byte		N03   
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		N12   , Dn4 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W12
	.byte		N12   , Gn3 
	.byte	W12
mus_bd_time_3_000:
	.byte		N06   , En4 , v080
	.byte	W12
	.byte		N06   
	.byte	W36
	.byte		N24   , An3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte	PEND
mus_bd_time_3_001:
	.byte		N06   , En4 , v080
	.byte	W12
	.byte		N06   
	.byte	W60
	.byte		N06   
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	PEND
mus_bd_time_3_B1:
	.byte	PATT
	 .word	mus_bd_time_3_000
	.byte	PATT
	 .word	mus_bd_time_3_001
	.byte	GOTO
	 .word	mus_bd_time_3_B1
	.byte	W96
	.byte	FINE

@********************** Track  4 **********************@

mus_bd_time_4:
	.byte	KEYSH , mus_bd_time_key+0
	.byte	W48
	.byte		VOICE , 4
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Dn5 , v052
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
mus_bd_time_4_000:
	.byte		N06   , Fn5 , v052
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bd_time_4_000
mus_bd_time_4_001:
	.byte		N06   , Gn5 , v052
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bd_time_4_001
mus_bd_time_4_002:
	.byte		N06   , An5 , v052
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bd_time_4_002
mus_bd_time_4_B1:
	.byte	PATT
	 .word	mus_bd_time_4_002
	.byte	PATT
	 .word	mus_bd_time_4_002
	.byte	GOTO
	 .word	mus_bd_time_4_B1
	.byte	W96
	.byte	FINE

@********************** Track  5 **********************@

mus_bd_time_5:
	.byte	KEYSH , mus_bd_time_key+0
	.byte	W48
	.byte		VOICE , 5
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W12
	.byte		N06   , Dn5 , v032
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Fn5 
	.byte	W06
	.byte		        Cn5 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Gn5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
mus_bd_time_5_000:
	.byte		N06   , En5 , v032
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte	PEND
mus_bd_time_5_B1:
	.byte		N06   , En5 , v032
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte		        Fs5 
	.byte	W06
	.byte		        En5 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        An5 
	.byte	W06
	.byte	PATT
	 .word	mus_bd_time_5_000
	.byte	GOTO
	 .word	mus_bd_time_5_B1
	.byte	W96
	.byte	FINE

@********************** Track  6 **********************@

mus_bd_time_6:
	.byte	KEYSH , mus_bd_time_key+0
	.byte	W48
	.byte		VOICE , 81
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		N03   , Dn2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		        Bn2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
mus_bd_time_6_000:
	.byte		N03   , An2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte	PEND
mus_bd_time_6_001:
	.byte		N03   , An2 , v064
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte	PEND
mus_bd_time_6_B1:
	.byte	PATT
	 .word	mus_bd_time_6_000
	.byte	PATT
	 .word	mus_bd_time_6_001
	.byte	GOTO
	 .word	mus_bd_time_6_B1
	.byte	W96
	.byte	FINE

@********************** Track  7 **********************@

mus_bd_time_7:
	.byte	KEYSH , mus_bd_time_key+0
	.byte	W48
	.byte		VOICE , 0
	.byte		VOL   , 80*mus_bd_time_mvl/mxv
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
mus_bd_time_7_000:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte	PEND
mus_bd_time_7_001:
	.byte		N06   , Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W12
	.byte		        Cn1 , v120
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        Fs1 , v072
	.byte	W06
	.byte		        Cn1 , v120
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_bd_time_7_000
	.byte	PATT
	 .word	mus_bd_time_7_001
	.byte	PATT
	 .word	mus_bd_time_7_000
	.byte	PATT
	 .word	mus_bd_time_7_001
	.byte	PATT
	 .word	mus_bd_time_7_000
mus_bd_time_7_B1:
	.byte	PATT
	 .word	mus_bd_time_7_001
	.byte	PATT
	 .word	mus_bd_time_7_000
	.byte	GOTO
	 .word	mus_bd_time_7_B1
	.byte	W96
	.byte	FINE

@******************************************************@
	.align	2

mus_bd_time:
	.byte	7	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_bd_time_pri	@ Priority
	.byte	mus_bd_time_rev	@ Reverb.

	.word	mus_bd_time_grp

	.word	mus_bd_time_1
	.word	mus_bd_time_2
	.word	mus_bd_time_3
	.word	mus_bd_time_4
	.word	mus_bd_time_5
	.word	mus_bd_time_6
	.word	mus_bd_time_7

	.end
