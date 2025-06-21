	.include "MPlayDef.s"

	.equ	se_m_moonlight_grp, voicegroup_rs_sfx_2
	.equ	se_m_moonlight_pri, 4
	.equ	se_m_moonlight_rev, reverb_set+50
	.equ	se_m_moonlight_mvl, 127
	.equ	se_m_moonlight_key, 0
	.equ	se_m_moonlight_tbs, 1
	.equ	se_m_moonlight_exg, 0
	.equ	se_m_moonlight_cmp, 1

	.section .rodata
	.global	se_m_moonlight
	.align	2

@********************** Track  1 **********************@

se_m_moonlight_1:
	.byte	KEYSH , se_m_moonlight_key+0
	.byte	TEMPO , 150*se_m_moonlight_tbs/2
	.byte		VOICE , 46
	.byte		VOL   , 100*se_m_moonlight_mvl/mxv
	.byte		BENDR , 4
	.byte		PAN   , c_v+0
	.byte		MOD   , 6
	.byte		BEND  , c_v+3
	.byte		N01   , Ds6 , v092
	.byte	W01
	.byte		        Dn6
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		N20   , Gn6 , v100
	.byte	W21
se_m_moonlight_1_000:
	.byte		N01   , Ds6 , v056
	.byte	W01
	.byte		        Dn6
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		N20   , Gn6 , v064
	.byte	W03
	.byte		PAN   , c_v+6
	.byte	W04
	.byte		        c_v-4
	.byte	W05
	.byte		        c_v+6
	.byte	W05
	.byte		        c_v-4
	.byte	W04
	.byte	PEND
se_m_moonlight_1_001:
	.byte		PAN   , c_v+0
	.byte		N01   , Gs5 , v092
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		        Cn5
	.byte	W01
	.byte		N20   , Cn6 , v100
	.byte	W21
	.byte	PEND
se_m_moonlight_1_002:
	.byte		PAN   , c_v+16
	.byte		N01   , Gs5 , v056
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		        Cn5
	.byte	W01
	.byte		N20   , Cn6 , v064
	.byte	W21
	.byte	PEND
se_m_moonlight_1_003:
	.byte		PAN   , c_v-16
	.byte		N01   , Gs5 , v040
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		        Cn5
	.byte	W01
	.byte		N20   , Cn6
	.byte	W21
	.byte	PEND
se_m_moonlight_1_004:
	.byte		PAN   , c_v+32
	.byte		N01   , Gs5 , v020
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		        Cn5
	.byte	W01
	.byte		PAN   , c_v-32
	.byte		N20   , Cn6
	.byte	W21
	.byte	PEND
	.byte		PAN   , c_v+0
	.byte		N01   , Ds6 , v092
	.byte	W01
	.byte		        Dn6
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		N20   , Gn6 , v100
	.byte	W21
	.byte	PATT
	 .word	se_m_moonlight_1_000
	.byte	PATT
	 .word	se_m_moonlight_1_001
	.byte	PATT
	 .word	se_m_moonlight_1_002
	.byte	PATT
	 .word	se_m_moonlight_1_003
	.byte	PATT
	 .word	se_m_moonlight_1_004
	.byte	FINE

@********************** Track  2 **********************@

se_m_moonlight_2:
	.byte	KEYSH , se_m_moonlight_key+0
	.byte		VOICE , 55
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*se_m_moonlight_mvl/mxv
	.byte		BEND  , c_v-4
	.byte	W10
	.byte		N01   , Ds6 , v112
	.byte	W02
	.byte		        Dn6
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		N04   , Gn6
	.byte	W05
	.byte		        Gn6 , v096
	.byte	W05
se_m_moonlight_2_000:
	.byte		PAN   , c_v+50
	.byte		N04   , Gn6 , v080
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		N04   , Gn6 , v064
	.byte	W05
	.byte		PAN   , c_v+50
	.byte		N04   , Gn6 , v048
	.byte	W05
	.byte		PAN   , c_v-49
	.byte		N04   , Gn6 , v032
	.byte	W10
	.byte	PEND
se_m_moonlight_2_001:
	.byte		PAN   , c_v+0
	.byte	W10
	.byte		N01   , Gs5 , v112
	.byte	W02
	.byte		        Gn5
	.byte	W01
	.byte		        Cn5
	.byte	W01
	.byte		N04   , Cn6
	.byte	W05
	.byte		        Cn6 , v096
	.byte	W05
	.byte	PEND
se_m_moonlight_2_002:
	.byte		PAN   , c_v+50
	.byte		N04   , Cn6 , v080
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		N04   , Cn6 , v064
	.byte	W05
	.byte		PAN   , c_v+50
	.byte		N04   , Cn6 , v048
	.byte	W05
	.byte		PAN   , c_v-49
	.byte		N04   , Cn6 , v032
	.byte	W10
	.byte	PEND
	.byte	W24
	.byte	W24
	.byte		PAN   , c_v+0
	.byte	W10
	.byte		N01   , Ds6 , v112
	.byte	W02
	.byte		        Dn6
	.byte	W01
	.byte		        Gn5
	.byte	W01
	.byte		N04   , Gn6
	.byte	W05
	.byte		        Gn6 , v096
	.byte	W05
	.byte	PATT
	 .word	se_m_moonlight_2_000
	.byte	PATT
	 .word	se_m_moonlight_2_001
	.byte	PATT
	 .word	se_m_moonlight_2_002
	.byte	W24
	.byte	W24
	.byte	FINE

@******************************************************@
	.align	2

se_m_moonlight:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_moonlight_pri	@ Priority
	.byte	se_m_moonlight_rev	@ Reverb.

	.word	se_m_moonlight_grp

	.word	se_m_moonlight_1
	.word	se_m_moonlight_2

	.end
