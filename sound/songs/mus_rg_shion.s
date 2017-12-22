	.include "MPlayDef.s"

	.equ	mus_rg_shion_grp, voicegroup_86A3BD4
	.equ	mus_rg_shion_pri, 0
	.equ	mus_rg_shion_rev, reverb_set+50
	.equ	mus_rg_shion_mvl, 127
	.equ	mus_rg_shion_key, 0
	.equ	mus_rg_shion_tbs, 1
	.equ	mus_rg_shion_exg, 0
	.equ	mus_rg_shion_cmp, 1

	.section .rodata
	.global	mus_rg_shion
	.align	2

@********************** Track  1 **********************@

mus_rg_shion_1:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte	TEMPO , 128*mus_rg_shion_tbs/2
	.byte		VOICE , 17
	.byte		PAN   , c_v+0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		LFOS  , 50
	.byte		BENDR , 12
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        c_v+0
	.byte	W96
mus_rg_shion_1_B1:
	.byte		VOICE , 17
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Gn4 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , En4 
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 89*mus_rg_shion_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , An4 , v064
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		        Fs4 
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cs4 , v127
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Gn4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Fs4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Gn4 , v064
	.byte	W03
	.byte		        Gs4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        As4 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
mus_rg_shion_1_000:
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Gn5 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PEND
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , En5 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 11
	.byte	W12
	.byte		        0
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte		N24   , En5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        0
	.byte		N12   , Bn5 
	.byte	W12
	.byte		MOD   , 13
	.byte		N03   , An5 , v048
	.byte	W03
	.byte		        Gn5 
	.byte	W03
	.byte		        Fs5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cs5 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	mus_rg_shion_1_000
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Fs5 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs5 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Gn5 , v048
	.byte	W03
	.byte		        Gs5 
	.byte	W03
	.byte		        An5 
	.byte	W03
	.byte		        As5 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Bn5 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		VOICE , 21
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Gn4 , v100
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , En4 
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cs4 
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
mus_rg_shion_1_001:
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Gn4 , v100
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PEND
mus_rg_shion_1_002:
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Fs4 , v100
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PEND
mus_rg_shion_1_003:
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn4 , v100
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PEND
	.byte		        0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cn5 
	.byte	W06
	.byte		MOD   , 8
	.byte	W18
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 8
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	mus_rg_shion_1_001
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , En4 , v100
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , En4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   , Cs4 
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W15
	.byte		VOL   , 79*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        68*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte	PATT
	 .word	mus_rg_shion_1_001
	.byte	PATT
	 .word	mus_rg_shion_1_002
	.byte	PATT
	 .word	mus_rg_shion_1_003
	.byte		MOD   , 0
	.byte		N48   , Cn4 , v100
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_shion_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_rg_shion_2:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+48
	.byte		MOD   , 4
	.byte		VOL   , 31*mus_rg_shion_mvl/mxv
	.byte		N06   , Cn5 , v127
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Gn5 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   , Bn5 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N06   , Fs5 
	.byte	W24
mus_rg_shion_2_000:
	.byte		PAN   , c_v-48
	.byte		N06   , Cn5 , v127
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N06   , Gn5 
	.byte	W24
	.byte		PAN   , c_v+48
	.byte		N06   , Bn5 
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Fs5 
	.byte	W24
	.byte	PEND
mus_rg_shion_2_001:
	.byte		PAN   , c_v+48
	.byte		N06   , Cn5 , v127
	.byte	W24
	.byte		PAN   , c_v-16
	.byte		N06   , Gn5 
	.byte	W24
	.byte		PAN   , c_v-48
	.byte		N06   , Bn5 
	.byte	W24
	.byte		PAN   , c_v+16
	.byte		N06   , Fs5 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shion_2_000
mus_rg_shion_2_B1:
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	PATT
	 .word	mus_rg_shion_2_001
	.byte	PATT
	 .word	mus_rg_shion_2_000
	.byte	GOTO
	 .word	mus_rg_shion_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_rg_shion_3:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 48
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v-32
	.byte		MOD   , 4
	.byte		VOL   , 42*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		        c_v+0
	.byte	W72
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+16
	.byte		N24   , En2 , v096
	.byte	W12
	.byte		VOL   , 22*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+10
	.byte	W06
	.byte		VOL   , 34*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+5
	.byte	W06
mus_rg_shion_3_B1:
	.byte		PAN   , c_v-32
	.byte		VOL   , 42*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N96   , En2 , v108
	.byte	W06
	.byte		PAN   , c_v-24
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+25
	.byte	W06
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-22
	.byte	W06
	.byte		        c_v-27
	.byte	W06
mus_rg_shion_3_000:
	.byte		N96   , Dn2 , v108
	.byte	W06
	.byte		PAN   , c_v-24
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+25
	.byte	W06
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-22
	.byte	W06
	.byte		        c_v-27
	.byte	W06
	.byte	PEND
mus_rg_shion_3_001:
	.byte		N96   , Cn2 , v108
	.byte	W06
	.byte		PAN   , c_v-24
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+25
	.byte	W06
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-22
	.byte	W06
	.byte		        c_v-27
	.byte	W06
	.byte	PEND
mus_rg_shion_3_002:
	.byte		PAN   , c_v-32
	.byte		N24   , En2 , v108
	.byte	W24
	.byte		        Cn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Bn1 
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte	PEND
mus_rg_shion_3_003:
	.byte		PAN   , c_v-32
	.byte		N96   , En2 , v108
	.byte	W06
	.byte		PAN   , c_v-24
	.byte	W06
	.byte		        c_v-16
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v+8
	.byte	W06
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+25
	.byte	W06
	.byte		        c_v+32
	.byte	W12
	.byte		        c_v+16
	.byte	W06
	.byte		        c_v+5
	.byte	W06
	.byte		        c_v+0
	.byte	W06
	.byte		        c_v-7
	.byte	W06
	.byte		        c_v-22
	.byte	W06
	.byte		        c_v-27
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte		VOICE , 24
	.byte		PAN   , c_v-32
	.byte		N24   , Bn4 , v108
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Fs4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Bn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gn4 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Fs4 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Bn4 
	.byte	W24
	.byte		VOICE , 73
	.byte		PAN   , c_v-32
	.byte		N24   , Bn5 , v068
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Gn5 
	.byte	W24
	.byte		PAN   , c_v-32
	.byte		N24   , Fs5 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Bn5 
	.byte	W24
	.byte		VOICE , 48
	.byte		PAN   , c_v-32
	.byte		N24   , En2 , v108
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte		VOICE , 24
	.byte		PAN   , c_v-32
	.byte		MOD   , 8
	.byte		VOL   , 52*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn4 , v108
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 8
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		MOD   , 8
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 8
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		MOD   , 8
	.byte		N24   
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 8
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v-32
	.byte		MOD   , 8
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		PAN   , c_v+32
	.byte		MOD   , 8
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        13
	.byte		VOL   , 56*mus_rg_shion_mvl/mxv
	.byte		PAN   , c_v+32
	.byte		N24   , Bn5 
	.byte	W12
	.byte		MOD   , 20
	.byte	W12
	.byte		        13
	.byte		PAN   , c_v-32
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 21
	.byte	W12
	.byte		        12
	.byte		PAN   , c_v+32
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 21
	.byte	W12
	.byte		        12
	.byte		PAN   , c_v-32
	.byte		N24   , Bn5 
	.byte	W12
	.byte		MOD   , 20
	.byte	W12
	.byte		VOICE , 48
	.byte		MOD   , 4
	.byte		PAN   , c_v-32
	.byte		VOL   , 42*mus_rg_shion_mvl/mxv
	.byte		N24   , En2 
	.byte	W24
	.byte		        Gn2 
	.byte	W24
	.byte		PAN   , c_v+32
	.byte		N24   , Fs2 
	.byte	W24
	.byte		        Bn2 
	.byte	W24
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte	PATT
	 .word	mus_rg_shion_3_003
	.byte	PATT
	 .word	mus_rg_shion_3_000
	.byte	PATT
	 .word	mus_rg_shion_3_001
	.byte	PATT
	 .word	mus_rg_shion_3_002
	.byte	GOTO
	 .word	mus_rg_shion_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_rg_shion_4:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 78
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+32
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		        3*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		        5*mus_rg_shion_mvl/mxv
	.byte	W06
	.byte		        6*mus_rg_shion_mvl/mxv
	.byte	W03
	.byte		        7*mus_rg_shion_mvl/mxv
	.byte	W03
mus_rg_shion_4_B1:
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
	.byte		N92   , En3 , v120
	.byte	W92
	.byte	W01
	.byte		N03   , Ds3 
	.byte	W03
mus_rg_shion_4_000:
	.byte		N92   , Dn3 , v127
	.byte	W92
	.byte	W01
	.byte		N03   , Cs3 , v120
	.byte	W03
	.byte	PEND
mus_rg_shion_4_001:
	.byte		N84   , Cn3 , v127
	.byte	W84
	.byte	W03
	.byte		N03   , Cs3 , v120
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte	PEND
mus_rg_shion_4_002:
	.byte		N15   , En3 , v127
	.byte	W15
	.byte		N03   , Ds3 , v120
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		N24   , Cn3 , v127
	.byte	W24
	.byte		N12   , Bn2 
	.byte	W12
	.byte		N03   , Cn3 , v120
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		N24   , En3 , v127
	.byte	W24
	.byte	PEND
mus_rg_shion_4_003:
	.byte		N92   , En3 , v127
	.byte	W92
	.byte	W01
	.byte		N03   , Ds3 , v120
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shion_4_000
	.byte	PATT
	 .word	mus_rg_shion_4_001
	.byte	PATT
	 .word	mus_rg_shion_4_002
	.byte	PATT
	 .word	mus_rg_shion_4_003
	.byte	PATT
	 .word	mus_rg_shion_4_000
	.byte	PATT
	 .word	mus_rg_shion_4_001
	.byte	PATT
	 .word	mus_rg_shion_4_002
	.byte		VOICE , 58
	.byte		VOL   , 22*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn4 , v127
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+16
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v+7
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-11
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-18
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-27
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-32
	.byte		N24   
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-37
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-40
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-44
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-34
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-28
	.byte	W12
	.byte		MOD   , 0
	.byte		PAN   , c_v-21
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 16
	.byte		PAN   , c_v-9
	.byte	W12
	.byte		VOICE , 78
	.byte		PAN   , c_v+0
	.byte		MOD   , 6
	.byte		N24   , Bn4 , v068
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        6
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        7
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		        7
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 16
	.byte	W12
	.byte		VOICE , 78
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
	.byte		N18   , En3 , v127
	.byte	W18
	.byte		N03   , Fn3 , v120
	.byte	W03
	.byte		        Fs3 
	.byte	W03
	.byte		N24   , Gn3 , v127
	.byte	W24
	.byte		N12   , Fs3 
	.byte	W12
	.byte		N03   , Gn3 , v120
	.byte	W03
	.byte		        Gs3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N24   , Bn3 , v127
	.byte	W24
	.byte	PATT
	 .word	mus_rg_shion_4_003
	.byte	PATT
	 .word	mus_rg_shion_4_000
	.byte	PATT
	 .word	mus_rg_shion_4_001
	.byte	PATT
	 .word	mus_rg_shion_4_002
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		MOD   , 5
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte	W12
	.byte		        12
	.byte	W12
	.byte		        5
	.byte	W12
	.byte		        12
	.byte	W12
	.byte		        5
	.byte	W12
	.byte		        12
	.byte	W12
	.byte		VOICE , 58
	.byte		MOD   , 5
	.byte		VOL   , 14*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn4 , v080
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		PAN   , c_v-32
	.byte		N24   , Bn4 , v096
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Gn4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Fs4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Bn4 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		VOICE , 73
	.byte		MOD   , 5
	.byte		PAN   , c_v+0
	.byte		VOL   , 13*mus_rg_shion_mvl/mxv
	.byte		N24   , Bn5 , v112
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Gn5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Fs5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		        5
	.byte		N24   , Bn5 
	.byte	W12
	.byte		MOD   , 12
	.byte	W12
	.byte		VOICE , 78
	.byte		MOD   , 0
	.byte		PAN   , c_v+32
	.byte		VOL   , 11*mus_rg_shion_mvl/mxv
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
	 .word	mus_rg_shion_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_rg_shion_5:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 22*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+2
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_shion_5_B1:
mus_rg_shion_5_000:
	.byte		N48   , Gn2 , v096
	.byte	W09
	.byte		MOD   , 8
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N42   
	.byte	W09
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		N03   , Fs2 , v092
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_001:
	.byte		MOD   , 0
	.byte		N48   , En2 , v096
	.byte	W09
	.byte		MOD   , 8
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N42   
	.byte	W09
	.byte		MOD   , 8
	.byte	W32
	.byte	W01
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_002:
	.byte		MOD   , 0
	.byte		N24   , Gn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N21   , Fs2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , En2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N09   , Bn2 , v096
	.byte	W09
	.byte		N03   , As2 , v088
	.byte	W03
	.byte		MOD   , 7
	.byte		N03   , Gs2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        En2 , v092
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_003:
	.byte		MOD   , 0
	.byte		N48   , Cs2 , v096
	.byte	W09
	.byte		MOD   , 8
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N32   
	.byte	W09
	.byte		MOD   , 8
	.byte	W24
	.byte		N03   , Dn2 , v092
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_004:
	.byte		MOD   , 0
	.byte		N48   , Gn2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte	PEND
mus_rg_shion_5_005:
	.byte		MOD   , 0
	.byte		N48   , Fs2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N36   
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte	W03
	.byte		N03   , Gn2 , v092
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_006:
	.byte		MOD   , 0
	.byte		N15   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , As2 , v092
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Gn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs2 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Gn2 , v092
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte	PEND
mus_rg_shion_5_007:
	.byte		MOD   , 0
	.byte		N48   , Cn3 , v096
	.byte	W06
	.byte		MOD   , 8
	.byte	W42
	.byte		        0
	.byte		N36   
	.byte	W09
	.byte		MOD   , 8
	.byte	W24
	.byte	W03
	.byte		N03   , Bn2 , v092
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_008:
	.byte		MOD   , 0
	.byte		N48   , Gn2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N42   
	.byte	W09
	.byte		MOD   , 7
	.byte	W32
	.byte	W01
	.byte		N03   , Fs2 , v092
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_009:
	.byte		MOD   , 0
	.byte		N48   , En2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N42   
	.byte	W09
	.byte		MOD   , 7
	.byte	W32
	.byte	W01
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_010:
	.byte		MOD   , 0
	.byte		N24   , Gn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N21   , Fs2 
	.byte	W12
	.byte		MOD   , 7
	.byte	W09
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , En2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Fn2 , v092
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , An2 , v092
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_011:
	.byte		MOD   , 0
	.byte		N48   , Cs2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N36   
	.byte	W09
	.byte		MOD   , 7
	.byte	W24
	.byte	W03
	.byte		N03   , Dn2 , v092
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fs2 
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shion_5_004
	.byte	PATT
	 .word	mus_rg_shion_5_005
mus_rg_shion_5_012:
	.byte		MOD   , 0
	.byte		N15   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W03
	.byte		N03   , As2 , v092
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N24   , Gn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte	W12
	.byte		        0
	.byte		N12   , Fs2 
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , Gn2 , v092
	.byte	W03
	.byte		        Gs2 
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		MOD   , 0
	.byte		N12   , Bn2 , v096
	.byte	W12
	.byte		MOD   , 7
	.byte		N03   , An2 , v092
	.byte	W03
	.byte		        Gn2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte	PEND
mus_rg_shion_5_013:
	.byte		MOD   , 0
	.byte		N48   , Cn2 , v096
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte		        0
	.byte		N48   
	.byte	W09
	.byte		MOD   , 7
	.byte	W36
	.byte	W03
	.byte	PEND
	.byte		        0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_5_000
	.byte	PATT
	 .word	mus_rg_shion_5_001
	.byte	PATT
	 .word	mus_rg_shion_5_002
	.byte	PATT
	 .word	mus_rg_shion_5_003
	.byte	PATT
	 .word	mus_rg_shion_5_004
	.byte	PATT
	 .word	mus_rg_shion_5_005
	.byte	PATT
	 .word	mus_rg_shion_5_006
	.byte	PATT
	 .word	mus_rg_shion_5_007
	.byte	PATT
	 .word	mus_rg_shion_5_008
	.byte	PATT
	 .word	mus_rg_shion_5_009
	.byte	PATT
	 .word	mus_rg_shion_5_010
	.byte	PATT
	 .word	mus_rg_shion_5_011
	.byte	PATT
	 .word	mus_rg_shion_5_004
	.byte	PATT
	 .word	mus_rg_shion_5_005
	.byte	PATT
	 .word	mus_rg_shion_5_012
	.byte	PATT
	 .word	mus_rg_shion_5_013
	.byte		MOD   , 0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_shion_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_rg_shion_6:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 10
	.byte		VOL   , 67*mus_rg_shion_mvl/mxv
	.byte		PAN   , c_v+30
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_shion_6_B1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W06
	.byte		VOL   , 69*mus_rg_shion_mvl/mxv
	.byte	W90
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N48   , Cn3 , v048
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W48
	.byte		N48   
	.byte	W48
	.byte	W96
	.byte	W96
	.byte		N48   
	.byte	W96
	.byte	GOTO
	 .word	mus_rg_shion_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_rg_shion_7:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		MOD   , 5
	.byte		PAN   , c_v+63
	.byte		VOL   , 21*mus_rg_shion_mvl/mxv
	.byte		BEND  , c_v+1
	.byte		N06   , Cn5 , v064
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , Bn5 
	.byte	W24
	.byte		        Fs5 
	.byte	W24
mus_rg_shion_7_000:
	.byte		PAN   , c_v-64
	.byte		N06   , Cn5 , v064
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		PAN   , c_v+63
	.byte		N06   , Bn5 
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte	PEND
mus_rg_shion_7_001:
	.byte		PAN   , c_v+63
	.byte		N06   , Cn5 , v064
	.byte	W24
	.byte		        Gn5 
	.byte	W24
	.byte		PAN   , c_v-64
	.byte		N06   , Bn5 
	.byte	W24
	.byte		        Fs5 
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_rg_shion_7_000
mus_rg_shion_7_B1:
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	PATT
	 .word	mus_rg_shion_7_001
	.byte	PATT
	 .word	mus_rg_shion_7_000
	.byte	GOTO
	 .word	mus_rg_shion_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_rg_shion_8:
	.byte	KEYSH , mus_rg_shion_key+0
	.byte		VOICE , 0
	.byte		VOL   , 90*mus_rg_shion_mvl/mxv
	.byte		PAN   , c_v+0
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
mus_rg_shion_8_B1:
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
	.byte		N48   , Ds5 , v120
	.byte	W96
mus_rg_shion_8_000:
	.byte		N48   , Bn4 , v032
	.byte	W48
	.byte		        En5 , v052
	.byte	W48
	.byte	PEND
	.byte		        Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
	.byte		N48   , Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
mus_rg_shion_8_001:
	.byte		N48   , Ds5 , v120
	.byte	W48
	.byte		        Bn4 , v032
	.byte	W48
	.byte	PEND
mus_rg_shion_8_002:
	.byte		N48   , Ds5 , v120
	.byte	W48
	.byte		        En5 , v052
	.byte	W48
	.byte	PEND
	.byte		        Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
	.byte	PATT
	 .word	mus_rg_shion_8_001
	.byte		N48   , En5 , v052
	.byte	W96
	.byte		        Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
	.byte		N48   , Ds5 , v120
	.byte	W96
	.byte		        En5 , v052
	.byte	W96
	.byte		        Ds5 , v120
	.byte	W96
	.byte		        Bn4 , v032
	.byte	W48
	.byte		        En5 , v056
	.byte	W48
	.byte		        Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
	.byte		N48   , Ds5 , v120
	.byte	W96
	.byte	PATT
	 .word	mus_rg_shion_8_000
	.byte	PATT
	 .word	mus_rg_shion_8_002
	.byte	W48
	.byte		N48   , Bn4 , v032
	.byte	W48
	.byte	GOTO
	 .word	mus_rg_shion_8_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_rg_shion:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_rg_shion_pri	@ Priority
	.byte	mus_rg_shion_rev	@ Reverb.

	.word	mus_rg_shion_grp

	.word	mus_rg_shion_1
	.word	mus_rg_shion_2
	.word	mus_rg_shion_3
	.word	mus_rg_shion_4
	.word	mus_rg_shion_5
	.word	mus_rg_shion_6
	.word	mus_rg_shion_7
	.word	mus_rg_shion_8

	.end
