	.include "MPlayDef.s"

	.equ	mus_tozan_grp, voicegroup052
	.equ	mus_tozan_pri, 0
	.equ	mus_tozan_rev, reverb_set+50
	.equ	mus_tozan_mvl, 127
	.equ	mus_tozan_key, 0
	.equ	mus_tozan_tbs, 1
	.equ	mus_tozan_exg, 0
	.equ	mus_tozan_cmp, 1

	.section .rodata
	.global	mus_tozan
	.align	2

@********************** Track  1 **********************@

mus_tozan_1:
	.byte	KEYSH , mus_tozan_key+0
	.byte	TEMPO , 124*mus_tozan_tbs/2
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        Cn4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 125
	.byte		N03   , Gn4 , v112
	.byte	W09
	.byte		VOICE , 127
	.byte	W03
	.byte		N03   , Cn4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 125
	.byte		N03   , Gn4 , v112
	.byte	W09
	.byte		VOICE , 127
	.byte	W03
	.byte		N03   , Cn4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 127
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        Cn4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   , Cn4 , v112
	.byte	W04
	.byte		        Cn4 , v088
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        Cn4 , v096
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
mus_tozan_1_B1:
mus_tozan_1_000:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v124
	.byte	W24
	.byte	PEND
mus_tozan_1_001:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v124
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W12
	.byte	PEND
mus_tozan_1_002:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v124
	.byte	W24
	.byte	PEND
mus_tozan_1_003:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		VOICE , 125
	.byte		VOL   , 15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_1_000
	.byte	PATT
	 .word	mus_tozan_1_001
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		        Gn3 , v124
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte	PATT
	 .word	mus_tozan_1_000
mus_tozan_1_004:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v124
	.byte	W12
	.byte		N03   , Gn3 , v064
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_1_002
mus_tozan_1_005:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte	PEND
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 24*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W03
	.byte		VOL   , 27*mus_tozan_mvl/mxv
	.byte	W09
	.byte		N03   , En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N03   , Gn3 , v124
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_1_001
	.byte	PATT
	 .word	mus_tozan_1_002
mus_tozan_1_006:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		N02   
	.byte	W04
	.byte		        Cn4 , v088
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , Gn3 , v124
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Cn4 
	.byte	W06
	.byte		        Cn4 , v096
	.byte	W06
	.byte	PEND
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 29*mus_tozan_mvl/mxv
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v108
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
mus_tozan_1_007:
	.byte		PAN   , c_v-62
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N02   , En4 , v112
	.byte	W04
	.byte		        En4 , v068
	.byte	W04
	.byte		        En4 , v092
	.byte	W04
	.byte		N03   , En4 , v076
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v108
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_1_007
mus_tozan_1_008:
	.byte		PAN   , c_v-62
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+63
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v108
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_1_008
	.byte		PAN   , c_v-62
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N03   , En4 , v112
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		N02   , En4 , v112
	.byte	W04
	.byte		        En4 , v096
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N03   , En4 , v116
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		        En4 , v112
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		        En4 , v060
	.byte	W06
	.byte		        En4 , v064
	.byte	W06
	.byte		PAN   , c_v-62
	.byte		VOL   , 39*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        Cn4 , v088
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Gn3 , v076
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        En4 , v092
	.byte	W06
mus_tozan_1_009:
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N06   , Gn3 , v124
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_1_001
	.byte	PATT
	 .word	mus_tozan_1_002
	.byte	PATT
	 .word	mus_tozan_1_003
	.byte	PATT
	 .word	mus_tozan_1_009
	.byte	PATT
	 .word	mus_tozan_1_001
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		PAN   , c_v-1
	.byte	W12
	.byte		N03   , Dn4 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		        An3 , v124
	.byte	W06
	.byte		        An3 , v112
	.byte	W06
	.byte		        Dn4 
	.byte	W06
	.byte		        Dn4 , v096
	.byte	W06
	.byte		PAN   , c_v-64
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte	PATT
	 .word	mus_tozan_1_000
	.byte	PATT
	 .word	mus_tozan_1_004
	.byte	PATT
	 .word	mus_tozan_1_002
	.byte	PATT
	 .word	mus_tozan_1_005
	.byte		VOICE , 127
	.byte		PAN   , c_v-64
	.byte		VOL   , 27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W12
	.byte		        En4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W24
	.byte		N03   
	.byte	W12
	.byte		VOICE , 125
	.byte		PAN   , c_v+0
	.byte		N03   , Gn3 , v124
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_1_001
	.byte	PATT
	 .word	mus_tozan_1_002
	.byte	PATT
	 .word	mus_tozan_1_006
	.byte	W24
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte	W24
	.byte		VOICE , 126
	.byte		VOL   , 3*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-1
	.byte		N48   , Fn4 , v120
	.byte	W02
	.byte		VOL   , 4*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        6*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        8*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		VOL   , 15*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        27*mus_tozan_mvl/mxv
	.byte		N03   , Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		        Cn4 , v112
	.byte	W06
	.byte		        Cn4 , v064
	.byte	W06
	.byte		VOL   , 9*mus_tozan_mvl/mxv
	.byte		N24   , Fn4 , v112
	.byte	W02
	.byte		VOL   , 11*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        27*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        39*mus_tozan_mvl/mxv
	.byte	W30
	.byte	W01
	.byte		        9*mus_tozan_mvl/mxv
	.byte		N24   
	.byte	W02
	.byte		VOL   , 9*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        13*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        40*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W24
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_1_B1
	.byte	FINE

@********************** Track  2 **********************@

mus_tozan_2:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 47
	.byte		LFOS  , 44
	.byte		VOL   , 70*mus_tozan_mvl/mxv
	.byte		BENDR , 12
	.byte		PAN   , c_v+19
	.byte		BEND  , c_v+0
	.byte		N12   , Ds2 , v108
	.byte	W48
	.byte		PAN   , c_v-25
	.byte		N16   , Gn1 , v120
	.byte	W36
	.byte		N03   , As1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v+19
	.byte		N12   , Ds2 
	.byte	W24
	.byte		PAN   , c_v-22
	.byte		N12   , As1 
	.byte	W24
	.byte		N36   , Ds1 
	.byte	W36
	.byte		PAN   , c_v+14
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
mus_tozan_2_B1:
	.byte		PAN   , c_v+16
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W84
mus_tozan_2_000:
	.byte		N03   , Bn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W24
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W24
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_tozan_2_001:
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W72
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_tozan_2_002:
	.byte		N03   , Ds2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W24
	.byte		N03   , Bn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W36
	.byte	PEND
mus_tozan_2_003:
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W72
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_tozan_2_004:
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W24
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Ds1 
	.byte	W36
	.byte	PEND
	.byte	W96
mus_tozan_2_005:
	.byte		VOICE , 56
	.byte	W06
	.byte		N03   , Ds3 , v112
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		        Ds3 
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		        Cs3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		N03   , Fn3 , v072
	.byte	W03
	.byte		        Ds3 , v068
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		        Cn3 , v060
	.byte	W03
	.byte		        As2 
	.byte	W06
	.byte	PEND
mus_tozan_2_006:
	.byte		VOICE , 47
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N05   , Gs1 
	.byte	W84
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_2_000
	.byte	PATT
	 .word	mus_tozan_2_001
mus_tozan_2_007:
	.byte		N03   , Ds2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs1 
	.byte	W84
	.byte	PEND
mus_tozan_2_008:
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N05   , Ds1 
	.byte	W72
	.byte		N03   , As2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_2_004
	.byte		VOICE , 56
	.byte	W96
mus_tozan_2_009:
	.byte	W48
	.byte		VOICE , 60
	.byte		N48   , Gn3 , v112
	.byte	W32
	.byte	W01
	.byte		VOICE , 47
	.byte	W15
	.byte	PEND
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N12   , Ds2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W84
	.byte	PATT
	 .word	mus_tozan_2_000
	.byte	PATT
	 .word	mus_tozan_2_001
	.byte	PATT
	 .word	mus_tozan_2_002
	.byte	PATT
	 .word	mus_tozan_2_003
	.byte	PATT
	 .word	mus_tozan_2_004
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_2_005
	.byte	PATT
	 .word	mus_tozan_2_006
	.byte	PATT
	 .word	mus_tozan_2_000
	.byte	PATT
	 .word	mus_tozan_2_001
	.byte	PATT
	 .word	mus_tozan_2_007
	.byte	PATT
	 .word	mus_tozan_2_008
	.byte	PATT
	 .word	mus_tozan_2_004
	.byte		VOICE , 56
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_2_009
mus_tozan_2_010:
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W36
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_2_010
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		        Gs2 
	.byte	W24
	.byte		PAN   , c_v+24
	.byte		N06   
	.byte	W12
	.byte		PAN   , c_v-18
	.byte		N12   , Gs1 , v127
	.byte	W60
	.byte		PAN   , c_v+23
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-19
	.byte		N12   , Gs1 , v127
	.byte	W60
	.byte		PAN   , c_v+23
	.byte	W12
	.byte		N03   , Gs2 , v096
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		PAN   , c_v-19
	.byte		N12   , Gs1 , v127
	.byte	W60
	.byte		PAN   , c_v+23
	.byte	W12
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gs2 
	.byte	W12
	.byte		PAN   , c_v-19
	.byte		N12   , Gs1 , v127
	.byte	W84
	.byte	GOTO
	 .word	mus_tozan_2_B1
	.byte	FINE

@********************** Track  3 **********************@

mus_tozan_3:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 56
	.byte		LFOS  , 44
	.byte		VOL   , 32*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+16
	.byte		BEND  , c_v+0
	.byte		N24   , Gn1 , v112
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v-16
	.byte		MOD   , 0
	.byte		N24   , Ds2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOL   , 41*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+47
	.byte		MOD   , 0
	.byte		N24   , As1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		PAN   , c_v-46
	.byte		MOD   , 0
	.byte		N24   , Gn2 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		        6
	.byte	W12
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+9
	.byte		MOD   , 0
	.byte		N96   , As2 
	.byte	W12
	.byte		VOL   , 36*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        21*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        17*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        14*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        14*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        17*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        18*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte		MOD   , 5
	.byte	W02
	.byte		VOL   , 29*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        31*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        41*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        55*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        60*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        62*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        64*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        68*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        72*mus_tozan_mvl/mxv
	.byte	W04
mus_tozan_3_B1:
	.byte		VOICE , 56
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte		MOD   , 1
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        An3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
mus_tozan_3_000:
	.byte		PAN   , c_v-48
	.byte		VOL   , 74*mus_tozan_mvl/mxv
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		N09   , Bn3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		        Dn4 , v112
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W03
	.byte		N06   , Dn4 , v032
	.byte	W03
	.byte	PEND
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-18
	.byte	W03
	.byte		        c_v-16
	.byte	W06
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		VOICE , 56
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-24
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Bn4 , v032
	.byte	W03
	.byte		N06   , Bn4 , v112
	.byte	W06
mus_tozan_3_001:
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W54
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N09   , Ds4 , v032
	.byte	W12
	.byte	PEND
mus_tozan_3_002:
	.byte	W06
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		N06   , Gn3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        As3 , v032
	.byte	W24
	.byte		        Gn2 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte	PEND
	.byte		N96   , Ds3 
	.byte	W03
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        43*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        27*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        32*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        33*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        39*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        40*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        44*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        47*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        49*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 54*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        60*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        66*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        68*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte		MOD   , 1
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn4 , v072
	.byte	W03
	.byte		        Cn4 , v068
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
mus_tozan_3_003:
	.byte		PAN   , c_v-48
	.byte		VOL   , 74*mus_tozan_mvl/mxv
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		        Bn3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		        Dn4 , v032
	.byte	W06
	.byte		        Bn3 , v112
	.byte	W06
	.byte		N03   , Dn4 
	.byte	W06
	.byte	PEND
	.byte		PAN   , c_v-32
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte		N03   , Ds3 
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Bn4 , v032
	.byte	W03
	.byte		N06   , Bn4 , v112
	.byte	W06
mus_tozan_3_004:
	.byte		N06   , Ds5 , v112
	.byte	W06
	.byte		N03   , Dn5 
	.byte	W03
	.byte		        Cn5 , v064
	.byte	W03
	.byte		        Bn4 
	.byte	W03
	.byte		        An4 
	.byte	W03
	.byte		        Gn4 
	.byte	W54
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		        Ds4 , v032
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_3_002
mus_tozan_3_005:
	.byte		N96   , Ds3 , v112
	.byte	W48
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        62*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        61*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        55*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        48*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        41*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 34*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        12*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        7*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        3*mus_tozan_mvl/mxv
	.byte	W04
	.byte	PEND
	.byte		VOICE , 60
	.byte		MOD   , 1
	.byte		VOL   , 68*mus_tozan_mvl/mxv
	.byte		N96   , Ds2 
	.byte	W72
	.byte		MOD   , 7
	.byte	W24
	.byte		VOICE , 56
	.byte		MOD   , 1
	.byte		PAN   , c_v+16
	.byte		VOL   , 68*mus_tozan_mvl/mxv
	.byte		N06   , Fs4 
	.byte	W06
	.byte		N03   , Fn4 , v076
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W78
	.byte	W48
	.byte		        Gs3 , v112
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N03   , Fn3 , v104
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W48
	.byte	W03
	.byte	W48
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte	W96
	.byte		VOL   , 68*mus_tozan_mvl/mxv
	.byte	W48
	.byte		N03   , As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte		PAN   , c_v-32
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W03
	.byte		N06   , Fn3 , v032
	.byte	W09
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v032
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		        Dn3 , v112
	.byte	W03
	.byte		        Dn3 , v032
	.byte	W03
	.byte		        Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W03
	.byte		MOD   , 1
	.byte		PAN   , c_v-39
	.byte		VOL   , 57*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		        En3 
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		        An3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		N06   , As3 , v032
	.byte	W09
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		N12   , Gs3 , v112
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_3_000
	.byte		PAN   , c_v-32
	.byte		VOL   , 54*mus_tozan_mvl/mxv
	.byte	W09
	.byte		N03   , En3 , v112
	.byte	W03
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        Ds3 , v032
	.byte	W06
	.byte		VOICE , 56
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOL   , 67*mus_tozan_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Bn4 , v032
	.byte	W03
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_3_001
	.byte	PATT
	 .word	mus_tozan_3_002
	.byte		N96   , Ds3 , v112
	.byte	W03
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        43*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        27*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        25*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        27*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        30*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        41*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 46*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        49*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        69*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        75*mus_tozan_mvl/mxv
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte		MOD   , 1
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v032
	.byte	W09
	.byte		N03   , Cs4 , v112
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Cs4 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v032
	.byte	W03
	.byte		        Gn3 , v112
	.byte	W03
	.byte		        Gn3 , v032
	.byte	W03
	.byte		        As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Ds4 
	.byte	W06
	.byte		N03   , Dn4 , v072
	.byte	W03
	.byte		        Cn4 , v068
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        An3 , v060
	.byte	W03
	.byte		        Gn3 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 54*mus_tozan_mvl/mxv
	.byte	W12
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W12
	.byte		        Gn3 
	.byte	W12
	.byte		        An3 
	.byte	W06
	.byte		        As3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_3_003
	.byte		PAN   , c_v-32
	.byte		VOL   , 54*mus_tozan_mvl/mxv
	.byte		N03   , Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		        Ds3 , v112
	.byte	W03
	.byte		        Ds3 , v032
	.byte	W03
	.byte		N06   , As3 , v112
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gn3 , v112
	.byte	W03
	.byte		N06   , Gn3 , v032
	.byte	W09
	.byte		N24   , As3 , v112
	.byte	W24
	.byte		N12   , Gs3 
	.byte	W12
	.byte		        Fn3 
	.byte	W12
	.byte		VOL   , 66*mus_tozan_mvl/mxv
	.byte		N06   , Fs3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W09
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		N06   , Gs3 , v032
	.byte	W15
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v032
	.byte	W03
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		        Ds4 
	.byte	W06
	.byte		N03   , Gs4 
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		        Gs4 , v112
	.byte	W03
	.byte		        Gs4 , v032
	.byte	W03
	.byte		N06   , Gn4 , v112
	.byte	W06
	.byte		        Gs4 
	.byte	W06
	.byte		N03   , Bn4 
	.byte	W03
	.byte		        Bn4 , v032
	.byte	W03
	.byte		N06   , Bn4 , v112
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_3_004
	.byte	PATT
	 .word	mus_tozan_3_002
	.byte	PATT
	 .word	mus_tozan_3_005
	.byte		VOICE , 60
	.byte		MOD   , 1
	.byte		VOL   , 71*mus_tozan_mvl/mxv
	.byte		N96   , Ds2 , v112
	.byte	W72
	.byte		MOD   , 7
	.byte	W24
	.byte		        1
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Gn3 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   
	.byte	W06
	.byte		        Gs3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Bn3 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N12   , Gs3 
	.byte	W12
	.byte		N06   , Gn3 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		VOICE , 56
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As3 
	.byte	W06
	.byte		        An3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_3_B1
	.byte	FINE

@********************** Track  4 **********************@

mus_tozan_4:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 60
	.byte		LFOS  , 44
	.byte		MOD   , 1
	.byte		PAN   , c_v-48
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte		BEND  , c_v+0
	.byte		N24   , Ds2 , v112
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+42
	.byte		N24   , As2 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		PAN   , c_v-31
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte		MOD   , 0
	.byte		N24   , Gn2 
	.byte	W12
	.byte		MOD   , 3
	.byte	W12
	.byte		        0
	.byte		PAN   , c_v+23
	.byte		N24   , Cs3 
	.byte	W03
	.byte		MOD   , 0
	.byte	W09
	.byte		        3
	.byte	W12
	.byte		VOL   , 72*mus_tozan_mvl/mxv
	.byte		MOD   , 0
	.byte		PAN   , c_v+0
	.byte		N96   , Ds3 , v124
	.byte	W09
	.byte		VOL   , 67*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        60*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        48*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        47*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        48*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        50*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        50*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        51*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        55*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 4
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        60*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        62*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        65*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 67*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        69*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        70*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        75*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        76*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        77*mus_tozan_mvl/mxv
	.byte	W04
mus_tozan_4_B1:
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		MOD   , 0
	.byte		VOL   , 74*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , As3 , v088
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v020
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W09
	.byte		N03   , Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		N06   , Fs4 , v020
	.byte	W09
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
mus_tozan_4_000:
	.byte		VOICE , 56
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v020
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v020
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v020
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		N09   , Ds4 , v020
	.byte	W03
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+32
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		N03   , Bn3 , v112
	.byte	W03
	.byte		N06   , Bn3 , v032
	.byte	W09
	.byte		        As3 , v112
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte	PEND
mus_tozan_4_001:
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte	W09
	.byte		N03   , An3 , v112
	.byte	W03
	.byte		N06   , Gs3 
	.byte	W06
	.byte		        Gs3 , v020
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W06
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
	.byte		VOICE , 56
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N60   , Gs4 
	.byte	W06
	.byte		VOL   , 67*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		VOL   , 46*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 33*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-48
	.byte	W03
	.byte		VOL   , 29*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        32*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 38*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 42*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOL   , 47*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W02
	.byte		VOL   , 63*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        72*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        78*mus_tozan_mvl/mxv
	.byte	W03
	.byte		VOICE , 60
	.byte		MOD   , 1
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds4 
	.byte	W03
	.byte		VOL   , 75*mus_tozan_mvl/mxv
	.byte	W03
	.byte		N06   , As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W06
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v020
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v020
	.byte	W09
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v020
	.byte	W09
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v020
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N09   , Ds3 , v020
	.byte	W12
mus_tozan_4_002:
	.byte		VOICE , 56
	.byte	W06
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v020
	.byte	W09
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v020
	.byte	W03
	.byte		N06   , Gn2 , v112
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        As2 , v020
	.byte	W24
	.byte		VOICE , 60
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte	PEND
	.byte		N96   , As3 
	.byte	W03
	.byte		VOL   , 69*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        39*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        31*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        30*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        33*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        40*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        42*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        49*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        50*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 54*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        68*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        75*mus_tozan_mvl/mxv
	.byte	W10
mus_tozan_4_003:
	.byte		MOD   , 1
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		N12   , As3 , v020
	.byte	W96
	.byte	PEND
mus_tozan_4_004:
	.byte	W12
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W09
	.byte		N03   , Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		N06   , Fs4 , v020
	.byte	W09
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PEND
mus_tozan_4_005:
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v020
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		        Ds4 , v020
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v020
	.byte	W03
	.byte		        Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W03
	.byte		VOICE , 56
	.byte		PAN   , c_v+32
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte	W12
	.byte		N03   , Bn3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N06   , As3 
	.byte	W06
	.byte		        As3 , v032
	.byte	W06
	.byte		        Gn3 , v112
	.byte	W06
	.byte		N03   , As3 
	.byte	W06
	.byte	PEND
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 74*mus_tozan_mvl/mxv
	.byte		N03   , Gs3 
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W06
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N60   , Gs4 
	.byte	W06
	.byte		VOL   , 67*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		VOL   , 46*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 33*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v-48
	.byte	W03
	.byte		VOL   , 29*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        32*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 38*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 42*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W03
	.byte		VOL   , 47*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 55*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W02
	.byte		VOL   , 63*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        72*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        78*mus_tozan_mvl/mxv
	.byte	W03
	.byte		MOD   , 1
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W06
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v020
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v020
	.byte	W09
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v020
	.byte	W09
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v020
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_4_002
mus_tozan_4_006:
	.byte		PAN   , c_v-5
	.byte		TIE   , As3 , v104
	.byte	W12
	.byte		PAN   , c_v-23
	.byte	W12
	.byte		        c_v-39
	.byte	W12
	.byte		        c_v-53
	.byte	W12
	.byte		        c_v-62
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        68*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        63*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        48*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        44*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        41*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        37*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        31*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        27*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v-23
	.byte		VOL   , 22*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        17*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W04
	.byte	PEND
mus_tozan_4_007:
	.byte		MOD   , 3
	.byte		PAN   , c_v+48
	.byte	W02
	.byte		VOL   , 22*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		VOL   , 31*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        37*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        45*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        49*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        56*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        61*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        66*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W12
	.byte		MOD   , 7
	.byte		PAN   , c_v+62
	.byte	W12
	.byte		        c_v+24
	.byte	W12
	.byte	PEND
	.byte		EOT   , As3 
	.byte		MOD   , 1
	.byte		PAN   , c_v-1
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		VOICE , 60
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte		N60   , Ds4 
	.byte	W12
	.byte		PAN   , c_v+0
	.byte	W05
	.byte		        c_v+9
	.byte	W07
	.byte		        c_v+25
	.byte	W05
	.byte		        c_v+41
	.byte	W07
	.byte		        c_v+50
	.byte	W05
	.byte		        c_v+63
	.byte	W07
	.byte		MOD   , 7
	.byte	W05
	.byte		PAN   , c_v+41
	.byte	W07
	.byte		MOD   , 1
	.byte		PAN   , c_v+24
	.byte		N06   , Cs4 
	.byte	W05
	.byte		PAN   , c_v+11
	.byte	W01
	.byte		N06   , Cs4 , v020
	.byte	W06
	.byte		PAN   , c_v+2
	.byte	W12
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v020
	.byte	W06
	.byte		PAN   , c_v-1
	.byte		N96   , As3 , v112
	.byte	W05
	.byte		PAN   , c_v-16
	.byte	W07
	.byte		        c_v-32
	.byte	W05
	.byte		        c_v-39
	.byte	W07
	.byte		        c_v-48
	.byte	W05
	.byte		        c_v-53
	.byte	W07
	.byte		        c_v-58
	.byte	W05
	.byte		        c_v-62
	.byte	W30
	.byte	W01
	.byte		MOD   , 7
	.byte		PAN   , c_v-53
	.byte	W05
	.byte		        c_v-28
	.byte	W07
	.byte		        c_v+0
	.byte	W12
	.byte		MOD   , 1
	.byte		N60   , Cs4 
	.byte	W24
	.byte		PAN   , c_v+2
	.byte	W05
	.byte		        c_v+11
	.byte	W07
	.byte		        c_v+24
	.byte	W05
	.byte		        c_v+16
	.byte	W07
	.byte		MOD   , 7
	.byte		PAN   , c_v+25
	.byte	W05
	.byte		        c_v+32
	.byte	W07
	.byte		MOD   , 1
	.byte		PAN   , c_v+54
	.byte		N06   , Cs4 , v020
	.byte	W05
	.byte		PAN   , c_v+63
	.byte	W07
	.byte		N06   , Bn3 , v112
	.byte	W06
	.byte		        Bn3 , v020
	.byte	W06
	.byte		        Cs4 , v112
	.byte	W06
	.byte		        Bn3 
	.byte	W06
	.byte		PAN   , c_v+34
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		N60   , Gs3 
	.byte	W21
	.byte		PAN   , c_v+32
	.byte	W05
	.byte		        c_v+25
	.byte	W06
	.byte		        c_v+20
	.byte	W04
	.byte		MOD   , 7
	.byte		PAN   , c_v+16
	.byte	W05
	.byte		        c_v+15
	.byte	W03
	.byte		        c_v+9
	.byte	W06
	.byte		        c_v+8
	.byte	W03
	.byte		        c_v+6
	.byte	W03
	.byte		        c_v+0
	.byte	W04
	.byte		MOD   , 1
	.byte		N06   , Gs3 , v020
	.byte	W24
	.byte		N36   , Fs3 , v112
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N06   , Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W06
	.byte		N24   , Gs3 
	.byte	W24
	.byte		        Ds3 
	.byte	W24
	.byte		N36   , Gs3 
	.byte	W24
	.byte		MOD   , 7
	.byte	W12
	.byte		        1
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N24   , As3 
	.byte	W24
	.byte		N03   , Gs3 , v092
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 , v088
	.byte	W03
	.byte		        Ds3 , v080
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 , v076
	.byte	W03
	.byte		        As2 
	.byte	W06
	.byte		VOICE , 56
	.byte		VOL   , 72*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , As3 , v112
	.byte	W03
	.byte		N06   , As3 , v020
	.byte	W09
	.byte		N03   , Fn3 , v112
	.byte	W03
	.byte		        Fn3 , v020
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v020
	.byte	W03
	.byte		        As3 , v112
	.byte	W03
	.byte		        As3 , v020
	.byte	W03
	.byte		        Dn4 , v112
	.byte	W03
	.byte		        Dn4 , v020
	.byte	W03
	.byte		        Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v020
	.byte	W03
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte	W06
	.byte		N03   , As3 , v088
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		N06   , Gs3 , v112
	.byte	W06
	.byte		        Gs3 , v020
	.byte	W06
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W09
	.byte		N03   , Fn4 , v112
	.byte	W03
	.byte		        Fn4 , v020
	.byte	W03
	.byte		        Fs4 , v112
	.byte	W03
	.byte		N06   , Fs4 , v020
	.byte	W09
	.byte		N03   , Fs4 , v112
	.byte	W03
	.byte		        Fs4 , v020
	.byte	W03
	.byte		N12   , Fn4 , v112
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_4_000
	.byte	PATT
	 .word	mus_tozan_4_001
	.byte		VOICE , 56
	.byte		N06   , Dn4 , v112
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N60   , Gs4 
	.byte	W09
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-48
	.byte	W21
	.byte		MOD   , 7
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-32
	.byte	W02
	.byte		VOL   , 71*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+0
	.byte	W02
	.byte		VOL   , 70*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+16
	.byte	W02
	.byte		VOL   , 68*mus_tozan_mvl/mxv
	.byte	W01
	.byte		PAN   , c_v+32
	.byte	W03
	.byte		VOL   , 65*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+48
	.byte	W02
	.byte		VOL   , 61*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        52*mus_tozan_mvl/mxv
	.byte	W04
	.byte		VOICE , 60
	.byte		MOD   , 1
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W06
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v020
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v020
	.byte	W09
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v020
	.byte	W09
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v020
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N09   , Ds3 , v020
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_4_002
	.byte		N96   , As3 , v112
	.byte	W03
	.byte		VOL   , 69*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        58*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        39*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        31*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        22*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        23*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W06
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        28*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        33*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        35*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        38*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        40*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 7
	.byte		VOL   , 43*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        49*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        55*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        61*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        66*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        71*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        73*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        76*mus_tozan_mvl/mxv
	.byte	W03
	.byte	PATT
	 .word	mus_tozan_4_003
	.byte	PATT
	 .word	mus_tozan_4_004
	.byte	PATT
	 .word	mus_tozan_4_005
	.byte		VOICE , 60
	.byte		PAN   , c_v+0
	.byte		VOL   , 73*mus_tozan_mvl/mxv
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		        Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v020
	.byte	W03
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Dn4 , v112
	.byte	W03
	.byte		N06   , Dn4 , v020
	.byte	W06
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N24   , Fs4 
	.byte	W24
	.byte		N12   , Fn4 
	.byte	W12
	.byte		        Cs4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W06
	.byte		N03   , Ds4 
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W09
	.byte		N03   , Ds4 , v112
	.byte	W03
	.byte		N06   , Ds4 , v020
	.byte	W12
	.byte		N03   , Gn4 , v112
	.byte	W03
	.byte		N60   , Gs4 
	.byte	W09
	.byte		PAN   , c_v-16
	.byte	W03
	.byte		        c_v-32
	.byte	W03
	.byte		        c_v-48
	.byte	W21
	.byte		MOD   , 7
	.byte		PAN   , c_v+21
	.byte	W03
	.byte		        c_v+26
	.byte	W03
	.byte		        c_v+36
	.byte	W03
	.byte		        c_v+48
	.byte	W03
	.byte		        c_v+48
	.byte	W12
	.byte		MOD   , 1
	.byte		PAN   , c_v+0
	.byte		N06   , Ds4 
	.byte	W06
	.byte		        As3 
	.byte	W06
	.byte		        Gn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W06
	.byte		N03   , Cs3 , v112
	.byte	W03
	.byte		N06   , Cs3 , v020
	.byte	W09
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v020
	.byte	W09
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v020
	.byte	W09
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v020
	.byte	W03
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		        Ds3 , v020
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_4_002
	.byte	PATT
	 .word	mus_tozan_4_006
	.byte	PATT
	 .word	mus_tozan_4_007
	.byte		EOT   , As3 
	.byte		MOD   , 1
	.byte		PAN   , c_v+0
	.byte		N24   , Cs4 , v112
	.byte	W24
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Dn4 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		        0
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   
	.byte	W06
	.byte		        Ds4 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Fs4 
	.byte	W15
	.byte		MOD   , 6
	.byte	W09
	.byte		VOICE , 60
	.byte		MOD   , 0
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N12   , Ds4 
	.byte	W12
	.byte		N06   , Dn4 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		VOICE , 56
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs4 
	.byte	W06
	.byte		        Fn4 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_4_B1
	.byte	FINE

@********************** Track  5 **********************@

mus_tozan_5:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 48
	.byte		PAN   , c_v+0
	.byte		VOL   , 48*mus_tozan_mvl/mxv
	.byte		LFOS  , 44
	.byte	W96
	.byte	W96
mus_tozan_5_B1:
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
	.byte		VOL   , 48*mus_tozan_mvl/mxv
	.byte		N04   , Bn2 , v112
	.byte	W04
	.byte		        Ds3 , v084
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Bn2 , v112
	.byte	W04
	.byte		        Ds3 , v084
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Bn2 , v112
	.byte	W04
	.byte		        Ds3 , v084
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Bn2 , v112
	.byte	W04
	.byte		        Ds3 , v084
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        As3 
	.byte	W04
	.byte		        Fs3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		PAN   , c_v-16
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		PAN   , c_v-32
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		PAN   , c_v-48
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		PAN   , c_v-62
	.byte		N04   , As2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        Fn3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N04   , An2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		        An2 , v112
	.byte	W04
	.byte		        Cs3 , v084
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Gs3 
	.byte	W04
	.byte		        En3 
	.byte	W04
	.byte		        Cs3 
	.byte	W04
	.byte		PAN   , c_v+16
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v+32
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v+48
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v+63
	.byte		N04   , Gs2 , v112
	.byte	W04
	.byte		        Cn3 , v084
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Gn3 
	.byte	W04
	.byte		        Ds3 
	.byte	W04
	.byte		        Cn3 
	.byte	W04
	.byte		PAN   , c_v+0
	.byte		N36   , As2 , v112
	.byte	W36
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		N24   , Cn3 
	.byte	W24
	.byte		N06   , Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Cn3 
	.byte	W06
	.byte		        Cs3 
	.byte	W06
	.byte		N36   , En3 
	.byte	W36
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		N24   , Fn3 
	.byte	W48
	.byte	W48
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
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_5_B1
	.byte	FINE

@********************** Track  6 **********************@

mus_tozan_6:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 87
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 12
	.byte		PAN   , c_v+0
	.byte		BENDR , 12
	.byte		VOL   , 39*mus_tozan_mvl/mxv
	.byte		N12   , Ds2 , v112
	.byte	W48
	.byte		        As1 
	.byte	W36
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N09   , Ds2 
	.byte	W24
	.byte		        As1 
	.byte	W24
	.byte		        Ds1 
	.byte	W36
	.byte		N06   , Gn1 
	.byte	W06
	.byte		        As1 
	.byte	W06
mus_tozan_6_B1:
	.byte		VOICE , 81
	.byte		PAN   , c_v+0
	.byte		VOL   , 39*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , As2 , v088
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		N06   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W09
	.byte		N03   , Fn3 
	.byte	W03
mus_tozan_6_000:
	.byte		PAN   , c_v-64
	.byte		N03   , Fs3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Bn2 , v068
	.byte	W03
	.byte		        Dn3 
	.byte	W03
	.byte		N06   , Fn3 , v112
	.byte	W12
	.byte		        Cs3 
	.byte	W06
	.byte		N03   , Fn3 
	.byte	W06
	.byte	PEND
mus_tozan_6_001:
	.byte		PAN   , c_v+0
	.byte	W12
	.byte		N03   , Gs2 , v112
	.byte	W12
	.byte		        Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W09
	.byte		        Gn3 
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
	.byte		N06   , Dn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		N03   
	.byte	W15
	.byte		        Gn3 
	.byte	W03
	.byte		N60   , Gs3 
	.byte	W18
	.byte		VOL   , 32*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        20*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        15*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        14*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        19*mus_tozan_mvl/mxv
	.byte	W04
	.byte		MOD   , 8
	.byte		VOL   , 23*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        33*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        43*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        47*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        47*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        55*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        57*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        60*mus_tozan_mvl/mxv
	.byte	W03
	.byte		MOD   , 0
	.byte		VOL   , 38*mus_tozan_mvl/mxv
	.byte		N06   , Ds3 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W18
	.byte	W96
	.byte	W96
	.byte	W96
mus_tozan_6_002:
	.byte	W12
	.byte		N06   , Fs3 , v112
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W09
	.byte		N03   , Fn3 
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_6_000
mus_tozan_6_003:
	.byte		PAN   , c_v+0
	.byte		N03   , Gs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W09
	.byte		        Gn3 
	.byte	W03
	.byte		N24   , Fs3 
	.byte	W24
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W12
	.byte	PEND
mus_tozan_6_004:
	.byte		N06   , Dn3 , v112
	.byte	W06
	.byte		N03   , Ds3 
	.byte	W12
	.byte		N03   
	.byte	W15
	.byte		        Gn3 
	.byte	W03
	.byte		N60   , Gs3 
	.byte	W36
	.byte		MOD   , 8
	.byte	W24
	.byte	PEND
mus_tozan_6_005:
	.byte		MOD   , 0
	.byte		N06   , Ds3 , v112
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W12
	.byte		N03   , Cs2 
	.byte	W12
	.byte		        As1 
	.byte	W12
	.byte		        Gn1 
	.byte	W12
	.byte		        Ds1 
	.byte	W06
	.byte		N06   , Dn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W18
	.byte	PEND
	.byte	W96
	.byte	W96
mus_tozan_6_006:
	.byte		VOICE , 60
	.byte	W24
	.byte		N48   , As2 , v112
	.byte	W72
	.byte	PEND
	.byte		VOICE , 81
	.byte		VOL   , 43*mus_tozan_mvl/mxv
	.byte		PAN   , c_v-63
	.byte		N06   , As3 
	.byte	W06
	.byte		N03   , Gs3 , v076
	.byte	W03
	.byte		        Gn3 
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Cs3 
	.byte	W78
	.byte	W48
	.byte		        Cs3 , v112
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W12
	.byte		N03   , As2 
	.byte	W06
	.byte		N06   , Fn3 
	.byte	W06
	.byte		N03   , Ds3 , v076
	.byte	W03
	.byte		        Cs3 
	.byte	W03
	.byte		        Cn3 
	.byte	W03
	.byte		        As2 
	.byte	W09
	.byte		        En3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W54
	.byte	W48
	.byte		        Ds3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W06
	.byte		N06   , Gs3 
	.byte	W06
	.byte		N03   , Gn3 , v076
	.byte	W03
	.byte		        Fn3 
	.byte	W03
	.byte		        Ds3 
	.byte	W03
	.byte		        Cs3 
	.byte	W09
	.byte	W96
	.byte	W48
	.byte		        Fn3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte	W06
	.byte		        Dn3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , As2 , v088
	.byte	W03
	.byte		        An2 
	.byte	W03
	.byte		N06   , Gs2 , v112
	.byte	W12
	.byte		N03   , Ds3 
	.byte	W12
	.byte		        Dn3 
	.byte	W12
	.byte		        Fn3 
	.byte	W06
	.byte		        Fs3 
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		N12   , Fn3 
	.byte	W12
	.byte		        Cs3 
	.byte	W09
	.byte		N03   , Fn3 
	.byte	W03
	.byte	PATT
	 .word	mus_tozan_6_000
	.byte	PATT
	 .word	mus_tozan_6_001
	.byte	PATT
	 .word	mus_tozan_6_004
	.byte	PATT
	 .word	mus_tozan_6_005
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_6_002
	.byte	PATT
	 .word	mus_tozan_6_000
	.byte	PATT
	 .word	mus_tozan_6_003
	.byte	PATT
	 .word	mus_tozan_6_004
	.byte	PATT
	 .word	mus_tozan_6_005
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_6_006
	.byte		N03   , Gs2 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		VOICE , 60
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Dn3 
	.byte	W24
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   
	.byte	W06
	.byte		        Ds3 
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N24   , Fs3 
	.byte	W24
	.byte		VOICE , 60
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		VOICE , 56
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N12   , Ds3 
	.byte	W12
	.byte		N06   , Dn3 
	.byte	W12
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Fs3 
	.byte	W06
	.byte		        Fn3 
	.byte	W06
	.byte		N03   , Gs2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_6_B1
	.byte	FINE

@********************** Track  7 **********************@

mus_tozan_7:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 80
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 16
	.byte		BENDR , 12
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+0
	.byte		BEND  , c_v+1
	.byte		N24   , Ds1 , v112
	.byte	W03
	.byte		BEND  , c_v+0
	.byte	W09
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , As1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Gn1 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		        0
	.byte		N24   , Cs2 
	.byte	W12
	.byte		MOD   , 6
	.byte	W12
	.byte		VOICE , 83
	.byte		PAN   , c_v+0
	.byte		VOL   , 14*mus_tozan_mvl/mxv
	.byte		MOD   , 0
	.byte		N72   , Ds4 
	.byte	W02
	.byte		VOL   , 18*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        21*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        24*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        26*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        29*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        33*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        36*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        38*mus_tozan_mvl/mxv
	.byte		MOD   , 4
	.byte	W02
	.byte		VOL   , 41*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        46*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        47*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        50*mus_tozan_mvl/mxv
	.byte	W02
	.byte		        54*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        56*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        61*mus_tozan_mvl/mxv
	.byte	W04
	.byte		        65*mus_tozan_mvl/mxv
	.byte		MOD   , 8
	.byte	W02
	.byte		VOL   , 71*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        71*mus_tozan_mvl/mxv
	.byte	W03
	.byte		        61*mus_tozan_mvl/mxv
	.byte	W01
	.byte		        74*mus_tozan_mvl/mxv
	.byte	W15
	.byte		MOD   , 1
	.byte		VOL   , 63*mus_tozan_mvl/mxv
	.byte		N03   , Cs4 , v088
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gn3 , v084
	.byte	W03
	.byte		        Ds3 , v080
	.byte	W03
	.byte		        Cs3 , v072
	.byte	W03
	.byte		        As2 , v068
	.byte	W03
	.byte		        Gn2 , v064
	.byte	W03
	.byte		        Ds2 , v060
	.byte	W03
mus_tozan_7_B1:
	.byte		VOICE , 88
	.byte		PAN   , c_v-63
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
mus_tozan_7_000:
	.byte		PAN   , c_v-63
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte	PEND
mus_tozan_7_001:
	.byte		PAN   , c_v-63
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte	PEND
mus_tozan_7_002:
	.byte		PAN   , c_v-63
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		        Cs2 , v112
	.byte	W03
	.byte		        Cs2 , v036
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , As1 , v112
	.byte	W03
	.byte		        As1 , v036
	.byte	W03
	.byte		        Gn1 , v112
	.byte	W03
	.byte		        Gn1 , v036
	.byte	W03
	.byte	PEND
mus_tozan_7_003:
	.byte		PAN   , c_v-63
	.byte		N18   , Ds1 , v112
	.byte	W18
	.byte		N03   , As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte	PEND
mus_tozan_7_004:
	.byte		PAN   , c_v-63
	.byte		N18   , Ds1 , v112
	.byte	W18
	.byte		N03   , As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N03   , As1 
	.byte	W03
	.byte		        As1 , v036
	.byte	W03
	.byte		        Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N12   , Gn1 , v112
	.byte	W12
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_7_003
mus_tozan_7_005:
	.byte		PAN   , c_v-63
	.byte		N18   , Ds1 , v112
	.byte	W18
	.byte		N03   , As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Gn1 , v036
	.byte	W03
	.byte		        Cs2 , v112
	.byte	W03
	.byte		        Cs2 , v036
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v072
	.byte	W03
	.byte		        Gn2 , v080
	.byte	W03
	.byte		        As2 , v096
	.byte	W03
	.byte		        Cs3 , v104
	.byte	W03
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_7_001
	.byte	PATT
	 .word	mus_tozan_7_000
	.byte		PAN   , c_v-63
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_7_002
	.byte	PATT
	 .word	mus_tozan_7_003
	.byte	PATT
	 .word	mus_tozan_7_004
	.byte	PATT
	 .word	mus_tozan_7_003
mus_tozan_7_006:
	.byte		PAN   , c_v-63
	.byte		N18   , Ds1 , v112
	.byte	W18
	.byte		N03   , As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N03   , Gn1 
	.byte	W03
	.byte		        Gn1 , v036
	.byte	W03
	.byte		        Cs2 , v112
	.byte	W03
	.byte		        Cs2 , v036
	.byte	W03
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		        Gn2 , v036
	.byte	W03
	.byte	PEND
	.byte		VOICE , 80
	.byte		N08   , Bn1 , v112
	.byte	W08
	.byte		        Fs1 
	.byte	W10
	.byte		N03   , Fs2 
	.byte	W03
	.byte		N06   , Fs2 , v036
	.byte	W15
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		N06   , As2 , v036
	.byte	W15
	.byte		N03   , As2 , v112
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		N12   , Ds2 , v112
	.byte	W12
	.byte		N06   , Fs2 
	.byte	W06
	.byte		        Fs2 , v036
	.byte	W06
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		N08   , As1 , v112
	.byte	W08
	.byte		        Fn1 
	.byte	W10
	.byte		N03   , Fn2 
	.byte	W03
	.byte		N06   , Fn2 , v036
	.byte	W15
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W15
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N03   , Fn2 
	.byte	W03
	.byte		        Fn2 , v036
	.byte	W03
	.byte		        Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		N12   , As1 , v112
	.byte	W12
	.byte		N08   , An1 
	.byte	W08
	.byte		        En1 
	.byte	W10
	.byte		N03   , En2 
	.byte	W03
	.byte		N06   , En2 , v036
	.byte	W15
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		N06   , Gs2 , v036
	.byte	W15
	.byte		N03   , Gs2 , v112
	.byte	W03
	.byte		        Gs2 , v036
	.byte	W03
	.byte		N12   , Cs2 , v112
	.byte	W12
	.byte		N06   , En2 
	.byte	W06
	.byte		        En2 , v036
	.byte	W06
	.byte		        An1 , v112
	.byte	W06
	.byte		        An1 , v036
	.byte	W06
	.byte		N08   , Gs1 , v112
	.byte	W08
	.byte		        Ds1 
	.byte	W10
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N06   , Gn2 , v036
	.byte	W15
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		        Gn2 , v036
	.byte	W03
	.byte		N12   , Cn2 , v112
	.byte	W12
	.byte		N03   , Ds2 
	.byte	W03
	.byte		        Ds2 , v036
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		        Gn2 , v036
	.byte	W03
	.byte		N12   , Gs1 , v112
	.byte	W12
	.byte		N18   , Fs1 
	.byte	W18
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W12
	.byte		        Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte		        Fn1 , v112
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        Cn2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		        Fn2 , v112
	.byte	W06
	.byte		        Fn2 , v036
	.byte	W06
	.byte		        Gn2 , v112
	.byte	W06
	.byte		N18   , En1 
	.byte	W18
	.byte		N06   , Bn1 
	.byte	W06
	.byte		        Bn1 , v036
	.byte	W12
	.byte		        Ds2 , v112
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Fn1 
	.byte	W06
	.byte		        Gs1 
	.byte	W06
	.byte		        As1 
	.byte	W06
	.byte		        Dn2 
	.byte	W06
	.byte		        Fn2 
	.byte	W06
	.byte		        Gs2 
	.byte	W06
	.byte		        As2 
	.byte	W06
	.byte		        As2 , v036
	.byte	W06
	.byte		N03   , Dn2 , v112
	.byte	W03
	.byte		N06   , Dn2 , v036
	.byte	W09
	.byte		N03   , Dn2 , v112
	.byte	W06
	.byte		N03   
	.byte	W03
	.byte		        Dn2 , v036
	.byte	W03
	.byte		        As2 , v112
	.byte	W03
	.byte		        As2 , v036
	.byte	W03
	.byte		        Dn2 , v112
	.byte	W03
	.byte		        Dn2 , v036
	.byte	W03
	.byte		        An1 , v112
	.byte	W03
	.byte		        An1 , v036
	.byte	W03
	.byte		PAN   , c_v-63
	.byte		VOL   , 58*mus_tozan_mvl/mxv
	.byte		N18   , Gs1 , v112
	.byte	W18
	.byte		N03   , Ds2 
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		N06   , Bn2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Bn2 , v112
	.byte	W03
	.byte		        Bn2 , v036
	.byte	W03
	.byte		N12   , Bn1 , v112
	.byte	W12
	.byte		N06   , Ds2 
	.byte	W06
	.byte		        Ds2 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Cs2 , v112
	.byte	W06
	.byte		        Cs2 , v036
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_7_000
	.byte	PATT
	 .word	mus_tozan_7_001
	.byte	PATT
	 .word	mus_tozan_7_002
	.byte	PATT
	 .word	mus_tozan_7_003
	.byte	PATT
	 .word	mus_tozan_7_004
	.byte	PATT
	 .word	mus_tozan_7_003
	.byte	PATT
	 .word	mus_tozan_7_005
	.byte	PATT
	 .word	mus_tozan_7_001
	.byte	PATT
	 .word	mus_tozan_7_000
	.byte	PATT
	 .word	mus_tozan_7_001
	.byte	PATT
	 .word	mus_tozan_7_002
	.byte		PAN   , c_v-63
	.byte		N18   , Ds1 , v112
	.byte	W18
	.byte		N03   , As1 
	.byte	W03
	.byte		N06   , As1 , v036
	.byte	W15
	.byte		PAN   , c_v+0
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W09
	.byte		PAN   , c_v+63
	.byte	W06
	.byte		N03   , Ds2 , v112
	.byte	W03
	.byte		N06   , Ds2 , v036
	.byte	W03
	.byte		N12   , Ds1 , v112
	.byte	W12
	.byte		N06   , As1 
	.byte	W06
	.byte		        As1 , v036
	.byte	W06
	.byte		PAN   , c_v+0
	.byte		N06   , Gn1 , v112
	.byte	W06
	.byte		        Gn1 , v036
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_7_004
	.byte	PATT
	 .word	mus_tozan_7_003
	.byte	PATT
	 .word	mus_tozan_7_006
	.byte		VOICE , 88
	.byte		PAN   , c_v+0
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Gs1 , v036
	.byte	W12
	.byte		N01   , Gs1 , v048
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W06
	.byte		        Gs1 , v072
	.byte	W06
	.byte		        Gs1 , v084
	.byte	W06
	.byte		        Gs1 , v096
	.byte	W06
	.byte		        Gs1 , v104
	.byte	W06
	.byte		        Gs1 , v112
	.byte	W03
	.byte		N03   , Bn1 , v096
	.byte	W03
	.byte		        Cs2 
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Gs1 , v036
	.byte	W12
	.byte		N01   , Gs1 , v048
	.byte	W06
	.byte		        Gs1 , v060
	.byte	W06
	.byte		        Gs1 , v072
	.byte	W06
	.byte		        Gs1 , v084
	.byte	W06
	.byte		        Gs1 , v096
	.byte	W06
	.byte		        Gs1 , v104
	.byte	W06
	.byte		        Gs1 , v112
	.byte	W06
	.byte		N03   , Cs2 , v096
	.byte	W03
	.byte		        Dn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        En2 
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Gs1 , v036
	.byte	W12
	.byte		N03   , Gs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		        Gs1 
	.byte	W12
	.byte		N06   , Gs1 , v036
	.byte	W12
	.byte		N03   , Gs1 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte		N12   , Gs2 , v112
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W03
	.byte		N03   , Gn2 , v112
	.byte	W03
	.byte		N12   , Gs2 
	.byte	W12
	.byte		N06   , Gs1 
	.byte	W06
	.byte		        Gs1 , v036
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO
	 .word	mus_tozan_7_B1
	.byte	FINE

@********************** Track  8 **********************@

mus_tozan_8:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 0
	.byte		PAN   , c_v+0
	.byte		VOL   , 63*mus_tozan_mvl/mxv
	.byte		N06   , En1 , v112
	.byte		N72   , An2 
	.byte	W12
	.byte		N06   , En1 
	.byte	W06
	.byte		N03   , En1 , v064
	.byte	W03
	.byte		        En1 , v020
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		        En1 , v088
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        En1 , v080
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
mus_tozan_8_B1:
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v064
	.byte	W12
	.byte		        Fs1 , v084
	.byte	W06
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N12   , As1 , v064
	.byte	W12
mus_tozan_8_000:
	.byte		N06   , Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte	PEND
mus_tozan_8_001:
	.byte		N06   , Cn1 , v124
	.byte	W18
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte	PEND
	.byte		        En1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W21
	.byte		N03   , En1 , v080
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W12
mus_tozan_8_002:
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v072
	.byte	W06
	.byte		N12   , As1 , v064
	.byte	W12
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N03   , Cn1 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte	PEND
mus_tozan_8_003:
	.byte		N06   , Cn1 , v124
	.byte	W18
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W24
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , En1 
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W12
	.byte	PEND
mus_tozan_8_004:
	.byte		N06   , Cn1 , v124
	.byte	W18
	.byte		        Cn1 , v112
	.byte	W18
	.byte		N06   
	.byte	W18
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W12
	.byte		        Dn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte	PEND
	.byte		N48   , An2 
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v076
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 , v116
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
mus_tozan_8_005:
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v064
	.byte	W12
	.byte		        Fs1 , v116
	.byte	W06
	.byte		N06   , Dn1 , v112
	.byte	W24
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_8_000
	.byte	PATT
	 .word	mus_tozan_8_001
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W21
	.byte		N03   , En1 , v084
	.byte	W03
	.byte		N06   , En1 , v127
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_8_002
	.byte	PATT
	 .word	mus_tozan_8_001
	.byte	PATT
	 .word	mus_tozan_8_004
	.byte	W48
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v076
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 , v116
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		VOL   , 70*mus_tozan_mvl/mxv
	.byte		N48   , An2 
	.byte	W48
	.byte		N06   , Cn1 , v048
	.byte	W06
	.byte		        Dn1 , v040
	.byte	W06
	.byte		        Cn1 , v064
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v080
	.byte	W12
	.byte		N12   , As1 , v064
	.byte	W12
	.byte		N04   , Cn1 , v112
	.byte	W08
	.byte		        Cn1 , v068
	.byte	W08
	.byte		        Cn1 , v076
	.byte	W05
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N06   , En1 , v100
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N03   , Fs1 , v064
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		N06   , Cn1 , v104
	.byte	W12
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v108
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v076
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Dn1 , v088
	.byte	W06
	.byte		        Dn1 , v068
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W08
	.byte		N04   , Cn1 , v068
	.byte	W08
	.byte		        Cn1 , v076
	.byte	W02
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v108
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		N12   , As1 , v064
	.byte	W12
	.byte		N06   , Cn1 , v112
	.byte	W18
	.byte		N03   , En1 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		        Dn1 , v080
	.byte	W06
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        Dn1 
	.byte	W06
	.byte		        Cn1 
	.byte	W06
	.byte		N03   , En1 , v044
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte	W12
	.byte		        En1 , v108
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W06
	.byte		        En1 
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 , v116
	.byte	W06
	.byte		        Cn1 , v108
	.byte	W06
	.byte		        En1 , v124
	.byte	W12
	.byte		        Cn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		N03   , En1 , v068
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v088
	.byte	W06
	.byte		        En1 , v096
	.byte	W06
	.byte		        En1 , v104
	.byte	W06
	.byte		        En1 , v116
	.byte	W06
	.byte		VOL   , 39*mus_tozan_mvl/mxv
	.byte	W06
	.byte		N03   , Gs1 , v112
	.byte	W12
	.byte		        Gs1 , v076
	.byte	W06
	.byte		        Gs1 , v112
	.byte	W06
	.byte		        Gs1 , v076
	.byte	W06
	.byte		N12   , As1 , v072
	.byte	W12
	.byte		VOL   , 70*mus_tozan_mvl/mxv
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v064
	.byte	W12
	.byte		        Fs1 , v084
	.byte	W06
	.byte		N06   , Dn1 , v112
	.byte	W12
	.byte		N12   , As1 , v064
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_8_000
	.byte	PATT
	 .word	mus_tozan_8_001
	.byte		N06   , En1 , v112
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W21
	.byte		N03   , En1 , v072
	.byte	W03
	.byte		N06   , En1 , v116
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_8_002
	.byte	PATT
	 .word	mus_tozan_8_003
	.byte	PATT
	 .word	mus_tozan_8_004
	.byte		N48   , An2 , v112
	.byte	W48
	.byte		N03   , Fs1 
	.byte	W06
	.byte		        Fs1 , v076
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 , v120
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_8_005
	.byte		N06   , Dn1 , v120
	.byte	W06
	.byte		        Dn1 , v076
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W06
	.byte		        Dn1 , v072
	.byte	W06
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        En1 , v084
	.byte	W12
	.byte		        Dn1 , v112
	.byte	W12
	.byte		        En1 
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte	PATT
	 .word	mus_tozan_8_001
	.byte		N06   , En1 , v120
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte		        Cn1 
	.byte	W12
	.byte		        En1 
	.byte	W12
	.byte		        Cn1 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte		N06   
	.byte	W21
	.byte		N03   , En1 , v072
	.byte	W03
	.byte		N06   , En1 , v116
	.byte	W12
	.byte		        Dn1 , v096
	.byte	W12
	.byte	PATT
	 .word	mus_tozan_8_002
	.byte	PATT
	 .word	mus_tozan_8_001
	.byte	PATT
	 .word	mus_tozan_8_004
	.byte	W48
	.byte		N03   , Fs1 , v112
	.byte	W06
	.byte		        Fs1 , v076
	.byte	W06
	.byte		        Fs1 , v068
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Cn1 , v112
	.byte	W06
	.byte		        Cn1 , v092
	.byte	W06
	.byte		        En1 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte	W06
	.byte	W72
	.byte		N24   , Gn2 
	.byte	W24
	.byte	W72
	.byte		        An2 
	.byte	W24
	.byte	W24
	.byte		        Gn2 
	.byte	W48
	.byte		        An2 
	.byte	W24
	.byte		        Gn2 , v076
	.byte	W24
	.byte		        An2 , v080
	.byte	W24
	.byte		        Gn2 , v096
	.byte	W24
	.byte		        An2 
	.byte	W12
	.byte		N02   , En1 , v112
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N02   
	.byte	W04
	.byte		N06   
	.byte		N72   , An2 
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v084
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N03   , En1 
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N03   
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N03   , Dn3 , v084
	.byte	W03
	.byte		        Dn3 , v048
	.byte	W03
	.byte		N06   , En1 , v088
	.byte		N03   , Dn3 , v048
	.byte	W03
	.byte		N03   
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v080
	.byte		N06   , Dn3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		        En3 
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v084
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N03   , En1 
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 , v032
	.byte	W03
	.byte		N03   
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N03   , Dn3 , v084
	.byte	W03
	.byte		        Dn3 , v032
	.byte	W03
	.byte		N06   , En1 , v088
	.byte		N03   , Dn3 , v048
	.byte	W03
	.byte		        Dn3 , v032
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v080
	.byte		N06   , Dn3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , En3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , Dn3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N06   , En1 , v112
	.byte		N06   , En3 , v084
	.byte	W06
	.byte		        En1 , v112
	.byte		N06   , Dn3 , v064
	.byte	W06
	.byte		N03   , En1 , v032
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte		N03   
	.byte		N06   , En3 
	.byte	W03
	.byte		N03   , En1 
	.byte	W03
	.byte	GOTO
	 .word	mus_tozan_8_B1
	.byte	FINE

@********************** Track  9 **********************@

mus_tozan_9:
	.byte	KEYSH , mus_tozan_key+0
	.byte		VOICE , 29
	.byte		LFOS  , 44
	.byte		XCMD  , xIECV , 18
	.byte		        xIECV , 12
	.byte		BENDR , 12
	.byte		VOL   , 49*mus_tozan_mvl/mxv
	.byte		PAN   , c_v+63
	.byte		BEND  , c_v+0
	.byte	W96
	.byte		N96   , Ds2 , v112
	.byte	W96
mus_tozan_9_B1:
mus_tozan_9_000:
	.byte	W92
	.byte	W01
	.byte		N03   , Dn3 , v112
	.byte	W03
	.byte	PEND
mus_tozan_9_001:
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		        Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W18
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W06
	.byte		        Gn2 , v068
	.byte	W03
	.byte		        As2 
	.byte	W03
	.byte		N06   , Cs3 , v112
	.byte	W12
	.byte		        As2 
	.byte	W06
	.byte		N03   , Cs3 
	.byte	W06
	.byte	PEND
	.byte	W96
mus_tozan_9_002:
	.byte	W36
	.byte		N03   , Ds3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Dn3 
	.byte	W06
	.byte		        Ds3 
	.byte	W06
	.byte		N03   , Gs3 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , Gn3 
	.byte	W06
	.byte		        Gs3 
	.byte	W06
	.byte		N03   , Bn3 
	.byte	W06
	.byte		N06   
	.byte	W06
	.byte	PEND
mus_tozan_9_003:
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Dn4 , v064
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        Bn3 
	.byte	W03
	.byte		        An3 
	.byte	W03
	.byte		        Gn3 
	.byte	W78
	.byte	PEND
	.byte	W96
	.byte	W96
mus_tozan_9_004:
	.byte	W06
	.byte		N03   , Gn2 , v112
	.byte	W12
	.byte		        Fn2 
	.byte	W06
	.byte		        Fs2 , v084
	.byte	W03
	.byte		        Gn2 , v112
	.byte	W03
	.byte		        En2 
	.byte	W06
	.byte		        Ds2 
	.byte	W06
	.byte		        Cs2 
	.byte	W06
	.byte		        Gn2 
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N06   , As2 
	.byte	W06
	.byte		N03   , An2 , v048
	.byte	W03
	.byte		        Gn2 , v052
	.byte	W03
	.byte		        Fn2 
	.byte	W03
	.byte		        Ds2 
	.byte	W03
	.byte		        Cs2 
	.byte	W06
	.byte	PEND
	.byte	PATT
	 .word	mus_tozan_9_000
	.byte	PATT
	 .word	mus_tozan_9_001
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_9_002
	.byte	PATT
	 .word	mus_tozan_9_003
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N06   , Fs4 , v112
	.byte	W06
	.byte		N03   , Fn4 , v076
	.byte	W03
	.byte		        En4 
	.byte	W03
	.byte		        Ds4 
	.byte	W03
	.byte		        Cs4 
	.byte	W03
	.byte		        Bn3 
	.byte	W78
	.byte	W48
	.byte		        Gs3 , v112
	.byte	W06
	.byte		N06   , Cs4 
	.byte	W06
	.byte		        Cs4 , v032
	.byte	W06
	.byte		N03   , Fn3 , v104
	.byte	W03
	.byte		        Fn3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte		        Cs4 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W12
	.byte		N03   
	.byte	W03
	.byte		N06   , Cs4 , v032
	.byte	W48
	.byte	W03
	.byte	W48
	.byte		N03   , Gs3 , v112
	.byte	W06
	.byte		N06   , Cn4 
	.byte	W06
	.byte		        Cn4 , v032
	.byte	W06
	.byte		N03   , Gs3 , v112
	.byte	W03
	.byte		        Gs3 , v032
	.byte	W03
	.byte		N06   , Ds4 , v112
	.byte	W06
	.byte		N03   , Cs4 , v076
	.byte	W03
	.byte		        Cn4 
	.byte	W03
	.byte		        As3 
	.byte	W03
	.byte		        Gs3 
	.byte	W09
	.byte	W96
	.byte	W48
	.byte		        As3 , v112
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W06
	.byte		N03   
	.byte	W30
	.byte	W48
	.byte		PAN   , c_v+63
	.byte	W92
	.byte	W01
	.byte		N03   , Dn3 
	.byte	W03
	.byte	PATT
	 .word	mus_tozan_9_001
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_9_002
	.byte	PATT
	 .word	mus_tozan_9_003
	.byte	W96
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_9_004
	.byte	PATT
	 .word	mus_tozan_9_000
	.byte	PATT
	 .word	mus_tozan_9_001
	.byte	W96
	.byte	PATT
	 .word	mus_tozan_9_002
	.byte	PATT
	 .word	mus_tozan_9_003
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
	 .word	mus_tozan_9_B1
	.byte	FINE

@******************************************************@
	.align	2

mus_tozan:
	.byte	9	@ NumTrks
	.byte	0	@ NumBlks
	.byte	mus_tozan_pri	@ Priority
	.byte	mus_tozan_rev	@ Reverb.

	.word	mus_tozan_grp

	.word	mus_tozan_1
	.word	mus_tozan_2
	.word	mus_tozan_3
	.word	mus_tozan_4
	.word	mus_tozan_5
	.word	mus_tozan_6
	.word	mus_tozan_7
	.word	mus_tozan_8
	.word	mus_tozan_9

	.end
