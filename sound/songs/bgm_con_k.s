	.include "MPlayDef.s"

	.equ	bgm_con_k_grp, voicegroup_869167C
	.equ	bgm_con_k_pri, 0
	.equ	bgm_con_k_rev, reverb_set+50
	.equ	bgm_con_k_mvl, 127
	.equ	bgm_con_k_key, 0
	.equ	bgm_con_k_tbs, 1
	.equ	bgm_con_k_exg, 0
	.equ	bgm_con_k_cmp, 1

	.section .rodata
	.global	bgm_con_k
	.align	2

@********************** Track  1 **********************@

bgm_con_k_1:
	.byte	KEYSH , bgm_con_k_key+0
	.byte	TEMPO , 128*bgm_con_k_tbs/2
	.byte		VOICE , 127
	.byte		LFOS  , 44
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 46*bgm_con_k_mvl/mxv
	.byte	W24
bgm_con_k_1_B1:
bgm_con_k_1_000:
	.byte		N02   , Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte	PEND
bgm_con_k_1_001:
	.byte		N02   , Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W04
	.byte		        Gn5 , v060
	.byte	W04
	.byte		        Gn5 , v064
	.byte	W08
	.byte		        Gn5 , v112
	.byte	W08
	.byte		        Gn5 , v064
	.byte	W08
	.byte		N02   
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_con_k_1_000
	.byte	PATT
	 .word	bgm_con_k_1_001
	.byte	PATT
	 .word	bgm_con_k_1_000
	.byte	PATT
	 .word	bgm_con_k_1_001
	.byte	PATT
	 .word	bgm_con_k_1_000
	.byte	PATT
	 .word	bgm_con_k_1_001
	.byte	GOTO
	 .word	bgm_con_k_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_con_k_2:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 57*bgm_con_k_mvl/mxv
	.byte	W24
bgm_con_k_2_B1:
	.byte		N20   , Bn3 , v112
	.byte	W24
	.byte		N04   , As3 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W16
	.byte		N04   , En4 
	.byte	W08
	.byte		N08   , Bn3 
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        Gs3 
	.byte	W16
	.byte		N04   , Ds4 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W08
	.byte		N04   , Gs3 
	.byte	W08
	.byte		        Fs3 
	.byte	W08
	.byte		N08   , En3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        Fs3 
	.byte	W24
	.byte		        En3 
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		        Gs3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		N12   , Bn3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        As3 
	.byte	W08
	.byte		        Bn3 
	.byte	W08
	.byte		N08   , Cs4 
	.byte	W24
	.byte		        Bn3 
	.byte	W16
	.byte		N04   , As3 
	.byte	W08
	.byte		N08   , Fs3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        Bn3 
	.byte	W24
	.byte		        Cs4 
	.byte	W24
	.byte		        En3 
	.byte		N24   , En4 
	.byte	W24
	.byte		N08   , En3 
	.byte		N08   , Ds4 
	.byte	W16
	.byte		        Bn3 
	.byte	W08
	.byte		        Fs3 
	.byte		N08   , Cn4 
	.byte	W24
	.byte		        En3 
	.byte		N08   , Cs4 
	.byte	W24
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N08   , Fn3 
	.byte	W16
	.byte		        Fs3 
	.byte	W08
	.byte		        Bn3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	GOTO
	 .word	bgm_con_k_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_con_k_3:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 38
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		PAN   , c_v+0
	.byte		VOL   , 80*bgm_con_k_mvl/mxv
	.byte		BEND  , c_v-48
	.byte		N24   , Bn0 , v112
	.byte	W04
	.byte		BEND  , c_v-32
	.byte	W04
	.byte		        c_v-18
	.byte	W04
	.byte		        c_v+0
	.byte	W12
bgm_con_k_3_B1:
	.byte		BEND  , c_v+0
	.byte		N32   , En1 , v112
	.byte	W32
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N04   
	.byte	W08
bgm_con_k_3_000:
	.byte		N32   , Ds1 , v112
	.byte	W32
	.byte		N08   , Dn1 
	.byte	W08
	.byte		N04   , Cs1 
	.byte	W08
	.byte		N16   , Bn0 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , As0 
	.byte	W08
	.byte		N04   , Bn0 
	.byte	W08
	.byte	PEND
bgm_con_k_3_001:
	.byte		N32   , Cs1 , v112
	.byte	W32
	.byte		N04   , Cn1 
	.byte	W08
	.byte		        Cs1 
	.byte	W08
	.byte		N16   , Fs1 
	.byte	W24
	.byte		N08   
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte		        Ds1 
	.byte	W08
	.byte	PEND
bgm_con_k_3_002:
	.byte		N24   , Bn0 , v112
	.byte	W24
	.byte		N08   , As0 
	.byte	W16
	.byte		N04   , Bn0 
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte	PEND
	.byte		N12   , En1 
	.byte	W16
	.byte		N04   
	.byte	W16
	.byte		N08   , Ds1 
	.byte	W08
	.byte		N04   , En1 
	.byte	W08
	.byte		N36   
	.byte	W40
	.byte		N04   
	.byte	W08
	.byte	PATT
	 .word	bgm_con_k_3_000
	.byte	PATT
	 .word	bgm_con_k_3_001
	.byte	PATT
	 .word	bgm_con_k_3_002
	.byte	GOTO
	 .word	bgm_con_k_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_con_k_4:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 24
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		PAN   , c_v+2
	.byte		VOL   , 50*bgm_con_k_mvl/mxv
	.byte		N24   , Fs3 , v112
	.byte	W24
bgm_con_k_4_B1:
	.byte	W16
	.byte		N08   , Gs4 , v112
	.byte	W08
	.byte		N04   , As4 
	.byte	W04
	.byte		N08   , As4 , v032
	.byte	W12
	.byte		N04   , Bn4 , v112
	.byte	W08
	.byte		N16   , As4 
	.byte	W16
	.byte		N08   , As4 , v032
	.byte	W08
	.byte		N24   , Gs4 , v112
	.byte	W24
	.byte		N48   , Fs4 
	.byte	W24
	.byte		VOL   , 48*bgm_con_k_mvl/mxv
	.byte		MOD   , 6
	.byte	W01
	.byte		VOL   , 45*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        43*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        37*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        36*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        35*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        28*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        25*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        20*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        18*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        16*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        15*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        49*bgm_con_k_mvl/mxv
	.byte		MOD   , 0
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W40
	.byte	W16
	.byte		        En4 , v112
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W04
	.byte		N08   , Fs4 , v032
	.byte	W12
	.byte		N04   , Gs4 , v112
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W16
	.byte		N32   , En4 
	.byte	W32
	.byte		N48   , Ds4 
	.byte	W24
	.byte		MOD   , 7
	.byte		VOL   , 48*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        45*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        43*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        37*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        36*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        35*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        28*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        25*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        20*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        18*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		        16*bgm_con_k_mvl/mxv
	.byte	W01
	.byte		        15*bgm_con_k_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 49*bgm_con_k_mvl/mxv
	.byte		N08   , Fs4 
	.byte	W08
	.byte		        Fs4 , v032
	.byte	W40
	.byte	W16
	.byte		N04   , Gs4 , v112
	.byte	W08
	.byte		N08   , As4 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        As4 
	.byte	W08
	.byte		        As4 , v032
	.byte	W08
	.byte		N04   , Bn4 , v112
	.byte	W08
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W08
	.byte		N04   , Cs5 , v112
	.byte	W08
	.byte		N08   , Ds5 , v100
	.byte	W08
	.byte		        Ds5 , v032
	.byte	W08
	.byte		N04   , Bn4 , v096
	.byte	W04
	.byte		N08   , Bn4 , v032
	.byte	W28
	.byte	W16
	.byte		        En5 , v100
	.byte	W08
	.byte		N04   , Ds5 
	.byte	W04
	.byte		N08   , Ds5 , v032
	.byte	W12
	.byte		N04   , Bn4 , v112
	.byte	W08
	.byte		        Cn5 
	.byte	W04
	.byte		N08   , Cn5 , v032
	.byte	W20
	.byte		N04   , Cs5 , v112
	.byte	W04
	.byte		N08   , Cs5 , v032
	.byte	W20
	.byte		        Bn4 , v112
	.byte	W08
	.byte		        Bn4 , v032
	.byte	W88
	.byte	GOTO
	 .word	bgm_con_k_4_B1
	.byte	FINE

@********************** Track  5 **********************@

bgm_con_k_5:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v-62
	.byte		VOL   , 46*bgm_con_k_mvl/mxv
	.byte	W24
bgm_con_k_5_B1:
	.byte		N20   , En3 , v112
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
bgm_con_k_5_000:
	.byte		N08   , As2 , v112
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
bgm_con_k_5_001:
	.byte		N08   , Gs2 , v112
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        As2 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
bgm_con_k_5_002:
	.byte		N24   , An2 , v112
	.byte	W24
	.byte		N08   , Gs2 
	.byte	W16
	.byte		        An2 
	.byte	W08
	.byte		        Bn2 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
	.byte		N12   , En3 
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PATT
	 .word	bgm_con_k_5_000
	.byte	PATT
	 .word	bgm_con_k_5_001
	.byte	PATT
	 .word	bgm_con_k_5_002
	.byte	GOTO
	 .word	bgm_con_k_5_B1
	.byte	FINE

@********************** Track  6 **********************@

bgm_con_k_6:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 81
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+63
	.byte		VOL   , 45*bgm_con_k_mvl/mxv
	.byte	W24
bgm_con_k_6_B1:
	.byte		N20   , Gs3 , v112
	.byte	W24
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
bgm_con_k_6_000:
	.byte		N08   , Cs3 , v112
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
bgm_con_k_6_001:
	.byte		N08   , Bn2 , v112
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte		        Cs3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
bgm_con_k_6_002:
	.byte		N24   , Cs3 , v112
	.byte	W24
	.byte		N08   
	.byte	W16
	.byte		N08   
	.byte	W08
	.byte		        Ds3 
	.byte	W24
	.byte		N08   
	.byte	W24
	.byte	PEND
	.byte	W16
	.byte		N04   , Gs3 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		N08   , As3 
	.byte	W24
	.byte		        Gs3 
	.byte	W24
	.byte	PATT
	 .word	bgm_con_k_6_000
	.byte	PATT
	 .word	bgm_con_k_6_001
	.byte	PATT
	 .word	bgm_con_k_6_002
	.byte	GOTO
	 .word	bgm_con_k_6_B1
	.byte	FINE

@********************** Track  7 **********************@

bgm_con_k_7:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 0
	.byte		VOL   , 70*bgm_con_k_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N04   , Dn1 , v112
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte		        Cn1 
	.byte	W08
bgm_con_k_7_B1:
bgm_con_k_7_000:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte	W24
	.byte	PEND
bgm_con_k_7_001:
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Dn1 , v088
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Dn1 
	.byte	W08
	.byte	PEND
	.byte	PATT
	 .word	bgm_con_k_7_000
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Cn1 
	.byte	W08
	.byte		N04   
	.byte	W16
	.byte		        Dn1 
	.byte	W08
	.byte	PATT
	 .word	bgm_con_k_7_000
	.byte	PATT
	 .word	bgm_con_k_7_001
	.byte	PATT
	 .word	bgm_con_k_7_000
	.byte		N04   , Cn1 , v112
	.byte	W24
	.byte		        Dn1 
	.byte	W16
	.byte		        Cn1 , v084
	.byte	W08
	.byte		        Cn1 , v112
	.byte	W16
	.byte		N04   
	.byte	W08
	.byte		        Dn1 
	.byte	W08
	.byte		        Cn1 , v088
	.byte	W08
	.byte		N04   
	.byte	W08
	.byte	GOTO
	 .word	bgm_con_k_7_B1
	.byte	FINE

@********************** Track  8 **********************@

bgm_con_k_8:
	.byte	KEYSH , bgm_con_k_key+0
	.byte		VOICE , 82
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		PAN   , c_v+0
	.byte		VOL   , 34*bgm_con_k_mvl/mxv
	.byte	W24
bgm_con_k_8_B1:
	.byte	W16
	.byte		N08   , Gs4 , v112
	.byte	W08
	.byte		N04   , As4 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		N16   , As4 
	.byte	W24
	.byte		N24   , Gs4 
	.byte	W24
	.byte		N48   , Fs4 
	.byte	W48
	.byte		N08   , Bn4 
	.byte	W48
	.byte	W16
	.byte		        En4 
	.byte	W08
	.byte		N04   , Fs4 
	.byte	W16
	.byte		        Gs4 
	.byte	W08
	.byte		N08   , Fs4 
	.byte	W16
	.byte		N32   , En4 
	.byte	W32
	.byte		N48   , Ds4 
	.byte	W48
	.byte		N08   , Fs4 
	.byte	W16
	.byte		BEND  , c_v+1
	.byte	W32
	.byte	W16
	.byte		N04   , Gs4 
	.byte	W08
	.byte		N08   , As4 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte		        Cs5 
	.byte	W16
	.byte		N08   , Bn4 
	.byte	W08
	.byte		        As4 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W08
	.byte	W16
	.byte		        As4 
	.byte	W08
	.byte		N08   , Bn4 
	.byte	W16
	.byte		N04   , Cs5 
	.byte	W08
	.byte		N08   , Ds5 
	.byte	W16
	.byte		N04   , Bn4 
	.byte	W32
	.byte	W16
	.byte		N08   , En5 
	.byte	W08
	.byte		N04   , Ds5 
	.byte	W16
	.byte		        Bn4 
	.byte	W08
	.byte		        Cn5 
	.byte	W24
	.byte		        Cs5 
	.byte	W24
	.byte		N08   , Bn4 
	.byte	W96
	.byte	GOTO
	 .word	bgm_con_k_8_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_con_k:
	.byte	8	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_con_k_pri	@ Priority
	.byte	bgm_con_k_rev	@ Reverb.

	.word	bgm_con_k_grp

	.word	bgm_con_k_1
	.word	bgm_con_k_2
	.word	bgm_con_k_3
	.word	bgm_con_k_4
	.word	bgm_con_k_5
	.word	bgm_con_k_6
	.word	bgm_con_k_7
	.word	bgm_con_k_8

	.end
