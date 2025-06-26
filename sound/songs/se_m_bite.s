	.include "MPlayDef.s"

	.equ	se_m_bite_grp, voicegroup_rs_sfx_2
	.equ	se_m_bite_pri, 4
	.equ	se_m_bite_rev, reverb_set+50
	.equ	se_m_bite_mvl, 127
	.equ	se_m_bite_key, 0
	.equ	se_m_bite_tbs, 1
	.equ	se_m_bite_exg, 0
	.equ	se_m_bite_cmp, 1

	.section .rodata
	.global	se_m_bite
	.align	2

@********************** Track  1 **********************@

se_m_bite_1:
	.byte	KEYSH , se_m_bite_key+0
	.byte	TEMPO , 220*se_m_bite_tbs/2
	.byte		VOICE , 26
	.byte		BENDR , 12
	.byte		PAN   , c_v+6
	.byte		VOL   , 110*se_m_bite_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N02   , Gn3 , v112
	.byte	W02
	.byte		        Gs3
	.byte	W01
	.byte		PAN   , c_v-7
	.byte	W01
	.byte		N02   , An3
	.byte	W02
	.byte		PAN   , c_v+7
	.byte	W02
	.byte		        c_v-8
	.byte	W02
	.byte		VOICE , 21
	.byte		PAN   , c_v+0
	.byte		N01   , Cn5 , v116
	.byte	W02
	.byte		PAN   , c_v+10
	.byte		N01   , Cn4 , v108
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		N01   , Gn4 , v104
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 , v096
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		N01   , Cn4 , v088
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		N01   , Cn3 , v080
	.byte	W02
	.byte		PAN   , c_v+0
	.byte		N01   , Gn3 , v072
	.byte	W01
	.byte		PAN   , c_v+10
	.byte		N01   , Gn2 , v064
	.byte	W01
	.byte		PAN   , c_v-8
	.byte		N01   , Cn3 , v056
	.byte	W01
	.byte		PAN   , c_v+0
	.byte		N01   , Gn2 , v048
	.byte	W03
	.byte	FINE

@********************** Track  2 **********************@

se_m_bite_2:
	.byte	KEYSH , se_m_bite_key+0
	.byte		VOICE , 27
	.byte		VOL   , 110*se_m_bite_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+0
	.byte	W10
	.byte		N01   , Gn2 , v040
	.byte	W08
	.byte		N01
	.byte	W06
	.byte	FINE

@******************************************************@
	.align	2

se_m_bite:
	.byte	2	@ NumTrks
	.byte	0	@ NumBlks
	.byte	se_m_bite_pri	@ Priority
	.byte	se_m_bite_rev	@ Reverb.

	.word	se_m_bite_grp

	.word	se_m_bite_1
	.word	se_m_bite_2

	.end
