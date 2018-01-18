	.include "MPlayDef.s"

	.equ	mus_rg_load01_grp, voicegroup_86A7240
	.equ	mus_rg_load01_pri, 0
	.equ	mus_rg_load01_rev, reverb_set+50
	.equ	mus_rg_load01_mvl, 127
	.equ	mus_rg_load01_key, 0
	.equ	mus_rg_load01_tbs, 1
	.equ	mus_rg_load01_exg, 0
	.equ	mus_rg_load01_cmp, 1

	.section .rodata
	.global	mus_rg_load01
	.align	2

@********************** Track  1 **********************@

mus_rg_load01_1:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte	TEMPO , 116*mus_rg_load01_tbs/2
	.byte		VOICE , 1
	.byte		PAN   , c_v+41
	.byte		VOL   , 44*mus_rg_load01_mvl/mxv
	.byte	W12
mus_rg_load01_1_B1:
	.byte		MOD   , 0
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Dn4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Dn4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Cs4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Cs4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Dn4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Dn4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		        Bn3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , Cs4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Gn4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , En4 , v127
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , En4 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , Fs4 , v127
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte	W12
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , Bn3 , v127
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , Gn3 , v127
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Cs3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , An3 , v127
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , Bn3 , v127
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , Bn3 , v064
	.byte	W12
	.byte		PAN   , c_v+40
	.byte		N03   , Dn4 , v127
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v064
	.byte	W12
	.byte	GOTO
	 .word	mus_rg_load01_1_B1
	.byte		PAN   , c_v+40
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_load01_2:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte		N06   , Dn4 , v127
	.byte	W06
	.byte		        En4 
	.byte	W06
mus_rg_load01_2_B1:
mus_rg_load01_2_000:
	.byte		N12   , Fs4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	PEND
mus_rg_load01_2_001:
	.byte		N12   , Fs4 , v127
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N18   , Gn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W36
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte	PEND
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		N12   , En4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W24
	.byte		N12   , Fs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_load01_2_000
	.byte	PATT
	 .word	mus_rg_load01_2_001
	.byte		N12   , En4 , v127
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N24   , Bn4 
	.byte	W24
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		N06   , Bn3 
	.byte	W06
	.byte		N18   , An3 
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		N36   , Dn4 
	.byte	W36
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N18   , Dn4 
	.byte	W18
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N36   , En4 
	.byte	W36
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N18   , Bn4 
	.byte	W18
	.byte		N06   , Gn4 
	.byte	W06
	.byte		N12   , An4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_load01_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_load01_3:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+3
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte	W12
mus_rg_load01_3_B1:
mus_rg_load01_3_000:
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Dn2 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Cs2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Bn1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PEND
mus_rg_load01_3_001:
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Dn2 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Bn1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Cs2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Bn1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Cn2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
mus_rg_load01_3_002:
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Cs2 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Dn2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_load01_3_000
	.byte	PATT
	 .word	mus_rg_load01_3_001
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Cs2 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , Bn1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N15   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte		MOD   , 9
	.byte	W03
	.byte		VOL   , 62*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PATT
	 .word	mus_rg_load01_3_002
mus_rg_load01_3_003:
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Dn2 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Gn1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , An1 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , Cs2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	PATT
	 .word	mus_rg_load01_3_003
	.byte		VOL   , 79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , An1 , v112
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        79*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Dn2 
	.byte	W03
	.byte		VOL   , 73*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        68*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        62*mus_rg_load01_mvl/mxv
	.byte		MOD   , 13
	.byte	W03
	.byte		VOL   , 56*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        51*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        38*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        22*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        17*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        11*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        6*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        3*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        0*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte	GOTO
	 .word	mus_rg_load01_3_B1
	.byte		MOD   , 0
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_load01_4:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 28*mus_rg_load01_mvl/mxv
	.byte		N03   , Dn3 , v127
	.byte	W06
	.byte		        En3 
	.byte	W06
mus_rg_load01_4_B1:
	.byte		BEND  , c_v+0
	.byte		N03   , Fs3 , v127
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn3 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte	W06
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   , En3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Fs3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N15   , Dn3 
	.byte	W03
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		N09   , Fs3 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N03   , Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn3 
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N24   , En3 
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		        0
	.byte		N03   , Cs3 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        En3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		N15   , Bn3 , v108
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Bn2 , v127
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Bn2 
	.byte	W06
	.byte		N06   , An2 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N21   , Dn3 
	.byte	W06
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte	W12
	.byte		N03   , Fs3 , v096
	.byte	W06
	.byte		        Gn3 , v104
	.byte	W06
	.byte		N06   , An3 , v100
	.byte	W12
	.byte		N09   , An3 , v096
	.byte	W03
	.byte		MOD   , 4
	.byte	W09
	.byte		        0
	.byte		N03   , Fs3 , v104
	.byte	W12
	.byte		        Dn3 , v127
	.byte	W12
	.byte		N06   , Dn4 , v080
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		N09   , Cs4 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   , An3 , v112
	.byte	W12
	.byte		        Fs3 
	.byte	W12
	.byte		N09   , Dn3 , v127
	.byte	W18
	.byte		N03   , Fs3 
	.byte	W06
	.byte		N21   , En3 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N03   , Fs3 , v100
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		N06   , An3 , v104
	.byte	W12
	.byte		N03   , An3 , v100
	.byte	W12
	.byte		        Fs3 , v104
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		N06   , Dn4 , v092
	.byte	W12
	.byte		N03   , Cs4 
	.byte	W12
	.byte		N09   , Bn3 
	.byte	W03
	.byte		MOD   , 7
	.byte	W06
	.byte		        0
	.byte	W09
	.byte		N03   , Gn3 
	.byte	W06
	.byte		N09   , An3 , v108
	.byte	W12
	.byte		N03   , Dn4 , v084
	.byte	W12
	.byte		N09   , Cs4 
	.byte	W12
	.byte		N03   , En4 
	.byte	W12
	.byte		N15   , Dn4 , v076
	.byte	W06
	.byte		MOD   , 4
	.byte	W18
	.byte		VOICE , 78
	.byte		MOD   , 0
	.byte	W12
	.byte		N03   , Dn3 , v127
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_load01_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_load01_5:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 83
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 38*mus_rg_load01_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N03   , Dn4 , v127
	.byte	W06
	.byte		        En4 
	.byte	W06
mus_rg_load01_5_B1:
mus_rg_load01_5_000:
	.byte		N03   , Fs4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	PEND
	.byte		        Fs4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn4 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte	W06
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N24   , En4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W24
	.byte		        0
	.byte	W06
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N15   , Dn4 
	.byte	W03
	.byte		MOD   , 6
	.byte	W15
	.byte		        0
	.byte	W06
	.byte		N09   , Fs4 
	.byte	W03
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	PATT
	 .word	mus_rg_load01_5_000
	.byte		N03   , Fs4 , v127
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N09   , Gn4 
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N24   , En4 
	.byte	W09
	.byte		MOD   , 6
	.byte	W24
	.byte	W03
	.byte		        0
	.byte		N03   , Cs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W12
	.byte		        Gn4 
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N15   , Bn4 
	.byte	W06
	.byte		MOD   , 5
	.byte	W12
	.byte		        0
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W06
	.byte		N06   , An3 
	.byte	W06
	.byte		        Cs4 
	.byte	W06
	.byte		N21   , Dn4 
	.byte	W06
	.byte		MOD   , 7
	.byte	W18
	.byte		        0
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W12
	.byte		N09   
	.byte	W03
	.byte		MOD   , 4
	.byte	W09
	.byte		        0
	.byte		N03   , Fs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		N06   , Dn5 , v092
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N09   , Cs5 
	.byte	W06
	.byte		MOD   , 6
	.byte	W06
	.byte		        0
	.byte		N03   , An4 , v112
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		N09   , Dn4 , v127
	.byte	W18
	.byte		N03   , Fs4 
	.byte	W06
	.byte		N21   , En4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		        0
	.byte	W12
	.byte		N03   , Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N06   , An4 
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		        Fs4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   , Dn5 , v092
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W12
	.byte		N09   , Bn4 
	.byte	W03
	.byte		MOD   , 7
	.byte	W06
	.byte		        0
	.byte	W09
	.byte		N03   , Gn4 
	.byte	W06
	.byte		N09   , An4 , v127
	.byte	W12
	.byte		N03   , Dn5 , v084
	.byte	W12
	.byte		N09   , Cs5 
	.byte	W12
	.byte		N03   , En5 
	.byte	W12
	.byte		N15   , Dn5 , v076
	.byte	W06
	.byte		MOD   , 4
	.byte	W18
	.byte		        0
	.byte	W12
	.byte		N03   , Dn4 , v127
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte	GOTO
	 .word	mus_rg_load01_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_load01_6:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-52
	.byte		VOL   , 45*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte	W12
mus_rg_load01_6_B1:
	.byte		PAN   , c_v-63
	.byte	W12
	.byte		N06   , Fs3 , v127
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte	W12
	.byte		N06   , Fs3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		VOL   , 13*mus_rg_load01_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , Fs3 
	.byte	W03
	.byte		VOL   , 21*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_load01_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 48*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 45*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Gn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v-63
	.byte		MOD   , 0
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		PAN   , c_v-63
	.byte	W12
	.byte		N06   , En3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte	W12
	.byte		N06   , Cs3 
	.byte	W12
	.byte		VOL   , 13*mus_rg_load01_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , En3 
	.byte	W03
	.byte		VOL   , 21*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_load01_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 48*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		VOL   , 45*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Cs3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Fs3 
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		N06   , An3 
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , As3 , v096
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 45*mus_rg_load01_mvl/mxv
	.byte		N84   , An3 
	.byte	W12
	.byte		VOL   , 39*mus_rg_load01_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 34*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        31*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        28*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        24*mus_rg_load01_mvl/mxv
	.byte	W24
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        41*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        48*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        53*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W15
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N06   , Fs3 , v127
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		VOL   , 13*mus_rg_load01_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N24   , An3 
	.byte	W03
	.byte		VOL   , 21*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_load01_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 48*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N06   
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Gn3 
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N06   , Fs3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N24   , En3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs3 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 13*mus_rg_load01_mvl/mxv
	.byte		MOD   , 0
	.byte		N36   , En3 
	.byte	W03
	.byte		VOL   , 21*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        29*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        36*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        43*mus_rg_load01_mvl/mxv
	.byte		MOD   , 6
	.byte	W03
	.byte		VOL   , 48*mus_rg_load01_mvl/mxv
	.byte	W03
	.byte		        56*mus_rg_load01_mvl/mxv
	.byte	W06
	.byte		        45*mus_rg_load01_mvl/mxv
	.byte	W12
	.byte		PAN   , c_v-64
	.byte		MOD   , 0
	.byte		N06   , Dn3 
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N06   , En3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N24   , An3 , v096
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , An2 , v127
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v+63
	.byte		MOD   , 0
	.byte		N06   , Cs3 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , An3 , v096
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , Dn3 , v127
	.byte	W24
	.byte		PAN   , c_v+0
	.byte		N06   , Dn4 , v100
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_load01_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_load01_7:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*mus_rg_load01_mvl/mxv
	.byte	W12
mus_rg_load01_7_B1:
mus_rg_load01_7_000:
	.byte	W12
	.byte		N12   , Ds1 , v100
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte	PEND
mus_rg_load01_7_001:
	.byte	W12
	.byte		N12   , Ds1 , v100
	.byte	W24
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_load01_7_000
	.byte	W12
	.byte		N12   , Ds1 , v100
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	PATT
	 .word	mus_rg_load01_7_000
	.byte	PATT
	 .word	mus_rg_load01_7_001
	.byte	PATT
	 .word	mus_rg_load01_7_000
	.byte	PATT
	 .word	mus_rg_load01_7_001
	.byte	W12
	.byte		N12   , Ds1 , v096
	.byte	W12
	.byte		        Ds1 , v100
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
mus_rg_load01_7_002:
	.byte	W12
	.byte		N12   , Ds1 , v100
	.byte	W12
	.byte		N12   
	.byte	W36
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_load01_7_002
	.byte	W12
	.byte		N12   , Ds1 , v100
	.byte	W12
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte		N12   
	.byte	W12
	.byte		N12   
	.byte	W24
	.byte	GOTO
	 .word	mus_rg_load01_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_load01_8:
	.byte	KEYSH , mus_rg_load01_key+0
	.byte		VOICE , 126
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 26*mus_rg_load01_mvl/mxv
	.byte	W12
mus_rg_load01_8_B1:
	.byte	W96
mus_rg_load01_8_000:
	.byte	W60
	.byte		N06   , En5 , v112
	.byte	W12
	.byte		N06   
	.byte	W24
	.byte	PEND
	.byte	W96
mus_rg_load01_8_001:
	.byte	W60
	.byte		N06   , En5 , v112
	.byte	W12
	.byte		N04   
	.byte	W24
	.byte	PEND
	.byte	W96
	.byte	PATT
	 .word	mus_rg_load01_8_000
	.byte	W96
	.byte	PATT
	 .word	mus_rg_load01_8_001
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_load01_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_load01:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_load01_pri	@ Priority
	.byte	mus_rg_load01_rev	@ Reverb.

	.word	mus_rg_load01_grp

	.word	mus_rg_load01_1
	.word	mus_rg_load01_2
	.word	mus_rg_load01_3
	.word	mus_rg_load01_4
	.word	mus_rg_load01_5
	.word	mus_rg_load01_6
	.word	mus_rg_load01_7
	.word	mus_rg_load01_8

	.end
