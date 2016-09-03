gEasyChatWord_Excl:: @ 8599890
	.string "!$"

gEasyChatWord_ExclExcl:: @ 8599892
	.string "!!$"

gEasyChatWord_QuesExcl:: @ 8599895
	.string "?!$"

gEasyChatWord_Ques:: @ 8599898
	.string "?$"

gEasyChatWord_Ellipsis:: @ 859989A
	.string "…$"

gEasyChatWord_EllipsisExcl:: @ 859989C
	.string "…!$"

gEasyChatWord_EllipsisEllipsisEllipsis:: @ 859989F
	.string "………$"

gEasyChatWord_Dash:: @ 85998A3
	.string "-$"

gEasyChatWord_DashDashDash:: @ 85998A5
	.string "- - -$"

gEasyChatWord_UhOh:: @ 85998AB
	.string "UH-OH$"

gEasyChatWord_Waaah:: @ 85998B1
	.string "WAAAH$"

gEasyChatWord_Ahaha:: @ 85998B7
	.string "AHAHA$"

gEasyChatWord_OhQues:: @ 85998BD
	.string "OH?$"

gEasyChatWord_Nope:: @ 85998C1
	.string "NOPE$"

gEasyChatWord_Urgh:: @ 85998C6
	.string "URGH$"

gEasyChatWord_Hmm:: @ 85998CB
	.string "HMM$"

gEasyChatWord_Whoah:: @ 85998CF
	.string "WHOAH$"

gEasyChatWord_WroooaarExcl:: @ 85998D5
	.string "WROOOAAR!$"

gEasyChatWord_Wow:: @ 85998DF
	.string "WOW$"

gEasyChatWord_Giggle:: @ 85998E3
	.string "GIGGLE$"

gEasyChatWord_Sigh:: @ 85998EA
	.string "SIGH$"

gEasyChatWord_Unbelievable:: @ 85998EF
	.string "UNBELIEVABLE$"

gEasyChatWord_Cries:: @ 85998FC
	.string "CRIES$"

gEasyChatWord_Agree:: @ 8599902
	.string "AGREE$"

gEasyChatWord_EhQues:: @ 8599908
	.string "EH?$"

gEasyChatWord_Cry:: @ 859990C
	.string "CRY$"

gEasyChatWord_Ehehe:: @ 8599910
	.string "EHEHE$"

gEasyChatWord_OiOiOi:: @ 8599916
	.string "OI, OI, OI$"

gEasyChatWord_OhYeah:: @ 8599921
	.string "OH, YEAH$"

gEasyChatWord_Oh:: @ 859992A
	.string "OH$"

gEasyChatWord_Oops:: @ 859992D
	.string "OOPS$"

gEasyChatWord_Shocked:: @ 8599932
	.string "SHOCKED$"

gEasyChatWord_Eek:: @ 859993A
	.string "EEK$"

gEasyChatWord_Graaah:: @ 859993E
	.string "GRAAAH$"

gEasyChatWord_Gwahahaha:: @ 8599945
	.string "GWAHAHAHA$"

gEasyChatWord_Way:: @ 859994F
	.string "WAY$"

gEasyChatWord_Tch:: @ 8599953
	.string "TCH$"

gEasyChatWord_Hehe:: @ 8599957
	.string "HEHE$"

gEasyChatWord_Hah:: @ 859995C
	.string "HAH$"

gEasyChatWord_Yup:: @ 8599960
	.string "YUP$"

gEasyChatWord_Hahaha:: @ 8599964
	.string "HAHAHA$"

gEasyChatWord_Aiyeeh:: @ 859996B
	.string "AIYEEH$"

gEasyChatWord_Hiyah:: @ 8599972
	.string "HIYAH$"

gEasyChatWord_Fufufu:: @ 8599978
	.string "FUFUFU$"

gEasyChatWord_Lol:: @ 859997F
	.string "LOL$"

gEasyChatWord_Snort:: @ 8599983
	.string "SNORT$"

gEasyChatWord_Humph:: @ 8599989
	.string "HUMPH$"

gEasyChatWord_Hehehe:: @ 859998F
	.string "HEHEHE$"

gEasyChatWord_Heh:: @ 8599996
	.string "HEH$"

gEasyChatWord_Hohoho:: @ 859999A
	.string "HOHOHO$"

gEasyChatWord_UhHuh:: @ 85999A1
	.string "UH-HUH$"

gEasyChatWord_OhDear:: @ 85999A8
	.string "OH, DEAR$"

gEasyChatWord_Arrgh:: @ 85999B1
	.string "ARRGH$"

gEasyChatWord_Mufufu:: @ 85999B7
	.string "MUFUFU$"

gEasyChatWord_Mmm:: @ 85999BE
	.string "MMM$"

gEasyChatWord_OhKay:: @ 85999C2
	.string "OH-KAY$"

gEasyChatWord_Okay:: @ 85999C9
	.string "OKAY$"

gEasyChatWord_Lalala:: @ 85999CE
	.string "LALALA$"

gEasyChatWord_Yay:: @ 85999D5
	.string "YAY$"

gEasyChatWord_Aww:: @ 85999D9
	.string "AWW$"

gEasyChatWord_Wowee:: @ 85999DD
	.string "WOWEE$"

gEasyChatWord_Gwah:: @ 85999E3
	.string "GWAH$"

gEasyChatWord_Wahahaha:: @ 85999E8
	.string "WAHAHAHA$"

	.align 2, 0

gEasyChatGroup_Voices:: @ 85999F4
	.4byte gEasyChatWord_Excl
	.4byte 0 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_ExclExcl
	.4byte 1 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_QuesExcl
	.4byte 7 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Ques
	.4byte 8 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Ellipsis
	.4byte 4 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_EllipsisExcl
	.4byte 5 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_EllipsisEllipsisEllipsis
	.4byte 6 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Dash
	.4byte 3 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_DashDashDash
	.4byte 2 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_UhOh
	.4byte 23 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Waaah
	.4byte 11 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Ahaha
	.4byte 41 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_OhQues
	.4byte 52 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Nope
	.4byte 59 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Urgh
	.4byte 22 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hmm
	.4byte 25 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Whoah
	.4byte 32 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_WroooaarExcl
	.4byte 24 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Wow
	.4byte 26 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Giggle
	.4byte 43 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Sigh
	.4byte 19 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Unbelievable
	.4byte 33 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Cries
	.4byte 61 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Agree
	.4byte 34 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_EhQues
	.4byte 38 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Cry
	.4byte 40 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Ehehe
	.4byte 48 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_OiOiOi
	.4byte 37 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_OhYeah
	.4byte 47 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Oh
	.4byte 42 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Oops
	.4byte 15 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Shocked
	.4byte 49 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Eek
	.4byte 46 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Graaah
	.4byte 57 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Gwahahaha
	.4byte 44 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Way
	.4byte 54 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Tch
	.4byte 53 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hehe
	.4byte 13 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hah
	.4byte 29 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Yup
	.4byte 51 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hahaha
	.4byte 28 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Aiyeeh
	.4byte 55 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hiyah
	.4byte 12 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Fufufu
	.4byte 27 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Lol
	.4byte 56 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Snort
	.4byte 30 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Humph
	.4byte 31 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hehehe
	.4byte 20 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Heh
	.4byte 45 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Hohoho
	.4byte 36 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_UhHuh
	.4byte 50 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_OhDear
	.4byte 9 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Arrgh
	.4byte 21 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Mufufu
	.4byte 14 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Mmm
	.4byte 10 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_OhKay
	.4byte 62 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Okay
	.4byte 35 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Lalala
	.4byte 16 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Yay
	.4byte 18 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Aww
	.4byte 60 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Wowee
	.4byte 17 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Gwah
	.4byte 58 @ alphabetical order
	.4byte TRUE @ enabled

	.4byte gEasyChatWord_Wahahaha
	.4byte 39 @ alphabetical order
	.4byte TRUE @ enabled
