gRibbonDescriptionPart1_Champion:: @ 862383C
	.string "CHAMPION-beating, HALL$"

gRibbonDescriptionPart2_Champion:: @ 8623853
	.string "OF FAME Member RIBBON$"

gRibbonDescriptionPart1_CoolContest:: @ 8623869
	.string "COOL CONTEST$"

gRibbonDescriptionPart1_BeautyContest:: @ 8623876
	.string "BEAUTY CONTEST$"

gRibbonDescriptionPart1_CuteContest:: @ 8623885
	.string "CUTE CONTEST$"

gRibbonDescriptionPart1_SmartContest:: @ 8623892
	.string "SMART CONTEST$"

gRibbonDescriptionPart1_ToughContest:: @ 86238A0
	.string "TOUGH CONTEST$"

gRibbonDescriptionPart2_NormalRank:: @ 86238AE
	.string "Normal Rank winner!$"

gRibbonDescriptionPart2_SuperRank:: @ 86238C2
	.string "Super Rank winner!$"

gRibbonDescriptionPart2_HyperRank:: @ 86238D5
	.string "Hyper Rank winner!$"

gRibbonDescriptionPart2_MasterRank:: @ 86238E8
	.string "Master Rank winner!$"

gRibbonDescriptionPart1_Winning:: @ 86238FC
	.string "For clearing LV50$"

gRibbonDescriptionPart2_Winning:: @ 862390E
	.string "at the BATTLE TOWER.$"

gRibbonDescriptionPart1_Victory:: @ 8623923
	.string "For clearing Open Level$"

gRibbonDescriptionPart2_Victory:: @ 862393B
	.string "at the BATTLE TOWER.$"

gRibbonDescriptionPart1_Artist:: @ 8623950
	.string "RIBBON for being chosen$"

gRibbonDescriptionPart2_Artist:: @ 8623968
	.string "as a super sketch model.$"

gRibbonDescriptionPart1_Effort:: @ 8623981
	.string "RIBBON awarded for$"

gRibbonDescriptionPart2_Effort:: @ 8623994
	.string "being a hard worker.$"

	.align 2
gRibbonDescriptionPointers:: @ 86239AC
	.4byte gRibbonDescriptionPart1_Champion,      gRibbonDescriptionPart2_Champion
	.4byte gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_NormalRank
	.4byte gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_SuperRank
	.4byte gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_HyperRank
	.4byte gRibbonDescriptionPart1_CoolContest,   gRibbonDescriptionPart2_MasterRank
	.4byte gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_NormalRank
	.4byte gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_SuperRank
	.4byte gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_HyperRank
	.4byte gRibbonDescriptionPart1_BeautyContest, gRibbonDescriptionPart2_MasterRank
	.4byte gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_NormalRank
	.4byte gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_SuperRank
	.4byte gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_HyperRank
	.4byte gRibbonDescriptionPart1_CuteContest,   gRibbonDescriptionPart2_MasterRank
	.4byte gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_NormalRank
	.4byte gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_SuperRank
	.4byte gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_HyperRank
	.4byte gRibbonDescriptionPart1_SmartContest,  gRibbonDescriptionPart2_MasterRank
	.4byte gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_NormalRank
	.4byte gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_SuperRank
	.4byte gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_HyperRank
	.4byte gRibbonDescriptionPart1_ToughContest,  gRibbonDescriptionPart2_MasterRank
	.4byte gRibbonDescriptionPart1_Winning,       gRibbonDescriptionPart2_Winning
	.4byte gRibbonDescriptionPart1_Victory,       gRibbonDescriptionPart2_Victory
	.4byte gRibbonDescriptionPart1_Artist,        gRibbonDescriptionPart2_Artist
	.4byte gRibbonDescriptionPart1_Effort,        gRibbonDescriptionPart2_Effort
