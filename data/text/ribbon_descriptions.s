gRibbonDescriptionPart1_Champion: @ 862383C
	.charmapstr "CHAMPION-beating, HALL$"

gRibbonDescriptionPart2_Champion: @ 8623853
	.charmapstr "OF FAME Member RIBBON$"

gRibbonDescriptionPart1_CoolContest: @ 8623869
	.charmapstr "COOL CONTEST$"

gRibbonDescriptionPart1_BeautyContest: @ 8623876
	.charmapstr "BEAUTY CONTEST$"

gRibbonDescriptionPart1_CuteContest: @ 8623885
	.charmapstr "CUTE CONTEST$"

gRibbonDescriptionPart1_SmartContest: @ 8623892
	.charmapstr "SMART CONTEST$"

gRibbonDescriptionPart1_ToughContest: @ 86238A0
	.charmapstr "TOUGH CONTEST$"

gRibbonDescriptionPart2_NormalRank: @ 86238AE
	.charmapstr "Normal Rank winner!$"

gRibbonDescriptionPart2_SuperRank: @ 86238C2
	.charmapstr "Super Rank winner!$"

gRibbonDescriptionPart2_HyperRank: @ 86238D5
	.charmapstr "Hyper Rank winner!$"

gRibbonDescriptionPart2_MasterRank: @ 86238E8
	.charmapstr "Master Rank winner!$"

gRibbonDescriptionPart1_Winning: @ 86238FC
	.charmapstr "For clearing LV50$"

gRibbonDescriptionPart2_Winning: @ 862390E
	.charmapstr "at the BATTLE TOWER.$"

gRibbonDescriptionPart1_Victory: @ 8623923
	.charmapstr "For clearing Open Level$"

gRibbonDescriptionPart2_Victory: @ 862393B
	.charmapstr "at the BATTLE TOWER.$"

gRibbonDescriptionPart1_Artist: @ 8623950
	.charmapstr "RIBBON for being chosen$"

gRibbonDescriptionPart2_Artist: @ 8623968
	.charmapstr "as a super sketch model.$"

gRibbonDescriptionPart1_Effort: @ 8623981
	.charmapstr "RIBBON awarded for$"

gRibbonDescriptionPart2_Effort: @ 8623994
	.charmapstr "being a hard worker.$"

	.align 2, 0

gRibbonDescriptionPointers: @ 86239AC
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
