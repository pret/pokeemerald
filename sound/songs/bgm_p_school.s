	.include "MPlayDef.s"

	.equ	bgm_p_school_grp, voicegroup_868DC74
	.equ	bgm_p_school_pri, 0
	.equ	bgm_p_school_rev, reverb_set+50
	.equ	bgm_p_school_mvl, 127
	.equ	bgm_p_school_key, 0
	.equ	bgm_p_school_tbs, 1
	.equ	bgm_p_school_exg, 0
	.equ	bgm_p_school_cmp, 1

	.section .rodata
	.global	bgm_p_school
	.align	2

@********************** Track  1 **********************@

bgm_p_school_1:
	.byte	KEYSH , bgm_p_school_key+0
bgm_p_school_1_B1:
	.byte	TEMPO , 116*bgm_p_school_tbs/2
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		VOL   , 87*bgm_p_school_mvl/mxv
	.byte		PAN   , c_v+4
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		VOL   , 96*bgm_p_school_mvl/mxv
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
	.byte	W84
	.byte		N06   , En3 , v064
	.byte	W12
	.byte	W60
	.byte		        Gn3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	W12
	.byte		        An3 
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N18   , En3 
	.byte	W24
	.byte	GOTO
	 .word	bgm_p_school_1_B1
	.byte	FINE

@********************** Track  2 **********************@

bgm_p_school_2:
	.byte		VOL   , 100*bgm_p_school_mvl/mxv
	.byte	KEYSH , bgm_p_school_key+0
bgm_p_school_2_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W96
	.byte	W84
	.byte		N06   , Fs4 , v064
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Gn4 
	.byte	W24
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		        Dn4 
	.byte	W12
	.byte		        En4 
	.byte	W12
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		N06   , An4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W06
	.byte		N24   , An4 
	.byte	W24
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		        Gn4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		N06   , Gn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W06
	.byte		N24   , Gn4 
	.byte	W24
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		N06   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		        Gn4 
	.byte	W03
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        Fs4 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W24
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		        En4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		N48   , Cs5 
	.byte	W36
	.byte		N06   , En3 
	.byte	W12
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		        Gn3 
	.byte		N06   , Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        Gn3 
	.byte		N06   , Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W24
	.byte		        Bn4 
	.byte	W12
	.byte		N03   , Cs5 
	.byte	W03
	.byte		        Dn5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		N48   , An4 
	.byte	W48
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Cs5 
	.byte	W03
	.byte		N06   , Bn4 
	.byte	W06
	.byte		        An4 
	.byte	W12
	.byte		        Gs4 
	.byte	W12
	.byte		        An4 
	.byte	W06
	.byte		        En4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N48   , En5 
	.byte	W48
	.byte	W12
	.byte		N12   , Bn4 
	.byte	W12
	.byte		N06   , Cs5 
	.byte	W12
	.byte		        Dn5 
	.byte	W12
	.byte		        En5 
	.byte	W12
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        En5 
	.byte	W03
	.byte		N06   , Dn5 
	.byte	W06
	.byte		        Cs5 
	.byte	W12
	.byte		        Bn4 
	.byte	W12
	.byte		        Cs5 
	.byte	W12
	.byte		        An4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		        An4 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Bn4 
	.byte	W06
	.byte		        Cs5 
	.byte	W06
	.byte		        Dn5 
	.byte	W06
	.byte		N18   , En5 
	.byte	W24
	.byte	GOTO
	 .word	bgm_p_school_2_B1
	.byte	FINE

@********************** Track  3 **********************@

bgm_p_school_3:
	.byte		VOL   , 100*bgm_p_school_mvl/mxv
	.byte	KEYSH , bgm_p_school_key+0
bgm_p_school_3_B1:
	.byte		VOICE , 1
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte		LFOS  , 44
	.byte		N06   , Dn2 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
bgm_p_school_3_000:
	.byte		N06   , Dn2 , v064
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_3_000
bgm_p_school_3_001:
	.byte		N06   , En2 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Bn1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
bgm_p_school_3_002:
	.byte		N06   , Bn1 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte	PEND
bgm_p_school_3_003:
	.byte		N06   , Gn1 , v064
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Bn2 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte		        An1 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_3_000
	.byte	PATT
	 .word	bgm_p_school_3_001
	.byte	PATT
	 .word	bgm_p_school_3_002
	.byte	PATT
	 .word	bgm_p_school_3_003
bgm_p_school_3_004:
	.byte		N06   , Gn2 , v064
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte		        Dn2 
	.byte	W12
	.byte		        Bn3 
	.byte	W12
	.byte	PEND
bgm_p_school_3_005:
	.byte		N06   , An2 , v064
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        En3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
bgm_p_school_3_006:
	.byte		N06   , Gn2 , v064
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Fs2 
	.byte	W12
	.byte		        Gn2 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte	PEND
	.byte		        An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        An2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte		        En2 
	.byte	W12
	.byte		        An3 
	.byte	W12
	.byte	PATT
	 .word	bgm_p_school_3_004
	.byte	PATT
	 .word	bgm_p_school_3_005
	.byte	PATT
	 .word	bgm_p_school_3_006
	.byte		N06   , An2 , v064
	.byte	W24
	.byte		        En2 
	.byte	W24
	.byte		        An2 
	.byte	W24
	.byte		N12   , An1 
	.byte	W12
	.byte		        Cs2 
	.byte	W12
	.byte	GOTO
	 .word	bgm_p_school_3_B1
	.byte	FINE

@********************** Track  4 **********************@

bgm_p_school_4:
	.byte		VOL   , 100*bgm_p_school_mvl/mxv
	.byte	KEYSH , bgm_p_school_key+0
bgm_p_school_4_B1:
	.byte		VOICE , 1
	.byte		LFOS  , 44
	.byte		BENDR , 12
	.byte	W12
	.byte		N06   , Fs3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
bgm_p_school_4_000:
	.byte	W12
	.byte		N06   , Fs3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_4_000
bgm_p_school_4_001:
	.byte	W12
	.byte		N06   , Gn3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_4_000
bgm_p_school_4_002:
	.byte	W12
	.byte		N06   , Gn3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		        An3 
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_4_000
	.byte	PATT
	 .word	bgm_p_school_4_001
	.byte	PATT
	 .word	bgm_p_school_4_000
	.byte	PATT
	 .word	bgm_p_school_4_002
bgm_p_school_4_003:
	.byte	W12
	.byte		N06   , Dn4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
bgm_p_school_4_004:
	.byte	W12
	.byte		N06   , Cs4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
bgm_p_school_4_005:
	.byte	W12
	.byte		N06   , Bn3 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	bgm_p_school_4_004
	.byte	PATT
	 .word	bgm_p_school_4_003
	.byte	PATT
	 .word	bgm_p_school_4_004
	.byte	PATT
	 .word	bgm_p_school_4_005
	.byte	W12
	.byte		N06   , Cs4 , v064
	.byte	W24
	.byte		N06   
	.byte	W24
	.byte		N06   
	.byte	W12
	.byte		N18   , An3 
	.byte	W24
	.byte	GOTO
	 .word	bgm_p_school_4_B1
	.byte	FINE

@******************************************************@
	.align	2

bgm_p_school:
	.byte	4	@ NumTrks
	.byte	0	@ NumBlks
	.byte	bgm_p_school_pri	@ Priority
	.byte	bgm_p_school_rev	@ Reverb.

	.word	bgm_p_school_grp

	.word	bgm_p_school_1
	.word	bgm_p_school_2
	.word	bgm_p_school_3
	.word	bgm_p_school_4

	.end
