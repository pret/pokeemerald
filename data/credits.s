	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

    .align 2
gUnknown_085E56F0:: @ 85E56F0
	.incbin "graphics/credits/credits_1.gbapal"
	.incbin "graphics/credits/credits_2.gbapal"
	.incbin "graphics/credits/credits_3.gbapal"
	.incbin "graphics/credits/credits_4.gbapal"

    .align 2
gUnknown_085E5770:: @ 85E5770
	.incbin "graphics/credits/the_end_copyright.4bpp.lz"

gUnknown_085E5BAC:: @ 85E5BAC
	.byte 0x00, 0x01, 0x00, 0xff, 0x01, 0xff, 0xff, 0x01, 0xff, 0xff, 0x01, 0xff, 0xff, 0x01, 0xff

gUnknown_085E5BBB:: @ 85E5BBB
	.byte 0x01, 0xff, 0x01, 0x01, 0xff, 0x01, 0x01, 0x02, 0x01, 0x01, 0xff, 0x01, 0x01, 0xff, 0x01

gUnknown_085E5BCA:: @ 85E5BCA
	.byte 0x01, 0x00, 0x00, 0x01, 0xff, 0xff, 0x01, 0x02, 0x02, 0x01, 0xff, 0xff, 0x01, 0x80, 0x80

gUnknown_085E5BD9:: @ 85E5BD9
	.byte 0x01, 0x03, 0x01, 0x01, 0x04, 0x01, 0x01, 0x05, 0x01, 0x01, 0xc4, 0x01, 0x01, 0xc3, 0x01

gUnknown_085E5BE8:: @ 85E5BE8
	.byte 0x01, 0x06, 0x07, 0x01, 0x08, 0x09, 0x01, 0xff, 0x01, 0x01, 0x88, 0x89, 0x01, 0x86, 0x87

gCreditsText_EmptyString:: @ 85E5BF7
	.string "$"

gCreditsText_PkmnEmeraldVersion:: @ 85E5BF8
	.string "POKéMON EMERALD VERSION$"

gCreditsText_Credits:: @ 85E5C10
	.string "Credits$"

gCreditsText_ExecutiveDirector:: @ 85E5C18
	.string "Executive Director$"

gCreditsText_Director:: @ 85E5C2B
	.string "Director$"

gCreditsText_ArtDirector:: @ 85E5C34
	.string "Art Director$"

gCreditsText_BattleDirector:: @ 85E5C41
	.string "Battle Director$"

gCreditsText_MainProgrammer:: @ 85E5C51
	.string "Main Programmer$"

gCreditsText_BattleSystemPgrms:: @ 85E5C61
	.string "Battle System Programmers$"

gCreditsText_FieldSystemPgrms:: @ 85E5C7B
	.string "Field System Programmer$"

gCreditsText_Programmers:: @ 85E5C93
	.string "Programmers$"

gCreditsText_MainGraphicDesigner:: @ 85E5C9F
	.string "Main Graphic Designer$"

gCreditsText_GraphicDesigners:: @ 85E5CB5
	.string "Graphic Designers$"

gCreditsText_PkmnDesigners:: @ 85E5CC7
	.string "POKéMON Designers$"

gCreditsText_MusicComposition:: @ 85E5CD9
	.string "Music Composition$"

gCreditsText_SoundEffectsAndPkmnVoices:: @ 85E5CEB
	.string "Sound Effects & POKéMON Voices$"

gCreditsText_GameDesigners:: @ 85E5D0A
	.string "Game Designers$"

gCreditsText_ScenarioPlot:: @ 85E5D19
	.string "Scenario Plot$"

gCreditsText_Scenario:: @ 85E5D27
	.string "Scenario$"

gCreditsText_ScriptDesigners:: @ 85E5D30
	.string "Script Designers$"

gCreditsText_MapDesigners:: @ 85E5D41
	.string "Map Designers$"

gCreditsText_MapDataDesigners:: @ 85E5D4F
	.string "Map Data Designers$"

gCreditsText_ParametricDesigners:: @ 85E5D62
	.string "Parametric Designers$"

gCreditsText_PokedexText:: @ 85E5D77
	.string "POKéDEX Text$"

gCreditsText_EnvAndToolPgrms:: @ 85E5D84
	.string "Environment & Tool Programmers$"

gCreditsText_NCLProductTesting:: @ 85E5DA3
	.string "NCL Product Testing$"

gCreditsText_SpecialThanks:: @ 85E5DB7
	.string "Special Thanks$"

gCreditsText_Coordinators:: @ 85E5DC6
	.string "Coordinators$"

gCreditsText_Producers:: @ 85E5DD3
	.string "Producers$"

gCreditsText_ExecProducers:: @ 85E5DDD
	.string "Executive Producers$"

gCreditsText_InfoSupervisors:: @ 85E5DF1
	.string "Information Supervisors$"

gCreditsText_TaskManagers:: @ 85E5E09
	.string "Task Managers$"

gCreditsText_BrailleCodeCheck:: @ 85E5E17
	.string "Braille Code Check$"

gCreditsText_WorldDirector:: @ 85E5E2A
	.string "World Director$"

gCreditsText_BattleFrontierData:: @ 85E5E39
	.string "Battle Frontier Data$"

gCreditsText_SupportProgrammers:: @ 85E5E4E
	.string "Support Programmers$"

gCreditsText_Artwork:: @ 85E5E62
	.string "Artwork$"

gCreditsText_LeadProgrammer:: @ 85E5E6A
	.string "Lead Programmer$"

gCreditsText_LeadGraphicArtist:: @ 85E5E7A
	.string "Lead Graphic Artist$"

gCreditsText_SatoshiTajiri:: @ 85E5E8E
	.string "Satoshi Tajiri$"

gCreditsText_JunichiMasuda:: @ 85E5E9D
	.string "Junichi Masuda$"

gCreditsText_KenSugimori:: @ 85E5EAC
	.string "Ken Sugimori$"

gCreditsText_ShigekiMorimoto:: @ 85E5EB9
	.string "Shigeki Morimoto$"

gCreditsText_TetsuyaWatanabe:: @ 85E5ECA
	.string "Tetsuya Watanabe$"

gCreditsText_HisashiSogabe:: @ 85E5EDB
	.string "Hisashi Sogabe$"

gCreditsText_SosukeTamada:: @ 85E5EEA
	.string "Sosuke Tamada$"

gCreditsText_AkitoMori:: @ 85E5EF8
	.string "Akito Mori$"

gCreditsText_KeitaKagaya:: @ 85E5F03
	.string "Keita Kagaya$"

gCreditsText_YoshinoriMatsuda:: @ 85E5F10
	.string "Yoshinori Matsuda$"

gCreditsText_HiroyukiNakamura:: @ 85E5F22
	.string "Hiroyuki Nakamura$"

gCreditsText_MasaoTaya:: @ 85E5F34
	.string "Masao Taya$"

gCreditsText_SatoshiNohara:: @ 85E5F3F
	.string "Satoshi Nohara$"

gCreditsText_TomomichiOhta:: @ 85E5F4E
	.string "Tomomichi Ohta$"

gCreditsText_MiyukiIwasawa:: @ 85E5F5D
	.string "Miyuki Iwasawa$"

gCreditsText_TakenoriOhta:: @ 85E5F6C
	.string "Takenori Ohta$"

gCreditsText_HironobuYoshida:: @ 85E5F7A
	.string "Hironobu Yoshida$"

gCreditsText_MotofumiFujiwara:: @ 85E5F8B
	.string "Motofumi Fujiwara$"

gCreditsText_SatoshiOhta:: @ 85E5F9D
	.string "Satoshi Ohta$"

gCreditsText_AsukaIwashita:: @ 85E5FAA
	.string "Asuka Iwashita$"

gCreditsText_AimiTomita:: @ 85E5FB9
	.string "Aimi Tomita$"

gCreditsText_TakaoUnno:: @ 85E5FC5
	.string "Takao Unno$"

gCreditsText_KanakoEo:: @ 85E5FD0
	.string "Kanako Eo$"

gCreditsText_JunOkutani:: @ 85E5FDA
	.string "Jun Okutani$"

gCreditsText_AtsukoNishida:: @ 85E5FE6
	.string "Atsuko Nishida$"

gCreditsText_MuneoSaito:: @ 85E5FF5
	.string "Muneo Saito$"

gCreditsText_RenaYoshikawa:: @ 85E6001
	.string "Rena Yoshikawa$"

gCreditsText_GoIchinose:: @ 85E6010
	.string "Go Ichinose$"

gCreditsText_MorikazuAoki:: @ 85E601C
	.string "Morikazu Aoki$"

gCreditsText_KojiNishino:: @ 85E602A
	.string "Koji Nishino$"

gCreditsText_KenjiMatsushima:: @ 85E6037
	.string "Kenji Matsushima$"

gCreditsText_TetsujiOhta:: @ 85E6048
	.string "Tetsuji Ohta$"

gCreditsText_HitomiSato:: @ 85E6055
	.string "Hitomi Sato$"

gCreditsText_TakeshiKawachimaru:: @ 85E6061
	.string "Takeshi Kawachimaru$"

gCreditsText_TeruyukiShimoyamada:: @ 85E6075
	.string "Teruyuki Shimoyamada$"

gCreditsText_ShigeruOhmori:: @ 85E608A
	.string "Shigeru Ohmori$"

gCreditsText_TadashiTakahashi:: @ 85E6099
	.string "Tadashi Takahashi$"

gCreditsText_ToshinobuMatsumiya:: @ 85E60AB
	.string "Toshinobu Matsumiya$"

gCreditsText_AkihitoTomisawa:: @ 85E60BF
	.string "Akihito Tomisawa$"

gCreditsText_HirokiEnomoto:: @ 85E60D0
	.string "Hiroki Enomoto$"

gCreditsText_KazuyukiTerada:: @ 85E60DF
	.string "Kazuyuki Terada$"

gCreditsText_YuriSakurai:: @ 85E60EF
	.string "Yuri Sakurai$"

gCreditsText_HiromiSagawa:: @ 85E60FC
	.string "Hiromi Sagawa$"

gCreditsText_KenjiTominaga:: @ 85E610A
	.string "Kenji Tominaga$"

gCreditsText_YoshioTajiri:: @ 85E6119
	.string "Yoshio Tajiri$"

gCreditsText_TeikoSasaki:: @ 85E6127
	.string "Teiko Sasaki$"

gCreditsText_SachikoHamano:: @ 85E6134
	.string "Sachiko Hamano$"

gCreditsText_ChieMatsumiya:: @ 85E6143
	.string "Chie Matsumiya$"

gCreditsText_AkikoShinozaki:: @ 85E6152
	.string "Akiko Shinozaki$"

gCreditsText_AstukoFujii:: @ 85E6162
	.string "Astuko Fujii$"

gCreditsText_NozomuSaito:: @ 85E616F
	.string "Nozomu Saito$"

gCreditsText_KenkichiToyama:: @ 85E617C
	.string "Kenkichi Toyama$"

gCreditsText_SuguruNakatsui:: @ 85E618C
	.string "Suguru Nakatsui$"

gCreditsText_YumiFunasaka:: @ 85E619C
	.string "Yumi Funasaka$"

gCreditsText_NaokoYanase:: @ 85E61AA
	.string "Naoko Yanase$"

gCreditsText_NCLSuperMarioClub:: @ 85E61B7
	.string "NCL Super Mario Club$"

gCreditsText_AtsushiTada:: @ 85E61CC
	.string "Atsushi Tada$"

gCreditsText_TakahiroOhnishi:: @ 85E61D9
	.string "Takahiro Ohnishi$"

gCreditsText_NorihideOkamura:: @ 85E61EA
	.string "Norihide Okamura$"

gCreditsText_HiroNakamura:: @ 85E61FB
	.string "Hiro Nakamura$"

gCreditsText_HiroyukiUesugi:: @ 85E6209
	.string "Hiroyuki Uesugi$"

gCreditsText_TerukiMurakawa:: @ 85E6219
	.string "Teruki Murakawa$"

gCreditsText_AkiraKinashi:: @ 85E6229
	.string "Akira Kinashi$"

gCreditsText_MichikoTakizawa:: @ 85E6237
	.string "Michiko Takizawa$"

gCreditsText_MakikoTakada:: @ 85E6248
	.string "Makiko Takada$"

gCreditsText_TakanaoKondo:: @ 85E6256
	.string "Takanao Kondo$"

gCreditsText_AiMashima:: @ 85E6264
	.string "Ai Mashima$"

gCreditsText_GakujiNomoto:: @ 85E626F
	.string "Gakuji Nomoto$"

gCreditsText_TakehiroIzushi:: @ 85E627D
	.string "Takehiro Izushi$"

gCreditsText_HitoshiYamagami:: @ 85E628D
	.string "Hitoshi Yamagami$"

gCreditsText_KyokoWatanabe:: @ 85E629E
	.string "Kyoko Watanabe$"

gCreditsText_TakaoNakano:: @ 85E62AD
	.string "Takao Nakano$"

gCreditsText_HiroyukiJinnai:: @ 85E62BA
	.string "Hiroyuki Jinnai$"

gCreditsText_HiroakiTsuru:: @ 85E62CA
	.string "Hiroaki Tsuru$"

gCreditsText_TsunekazIshihara:: @ 85E62D8
	.string "Tsunekaz Ishihara$"

gCreditsText_SatoruIwata:: @ 85E62EA
	.string "Satoru Iwata$"

gCreditsText_KazuyaSuyama:: @ 85E62F7
	.string "Kazuya Suyama$"

gCreditsText_SatoshiMitsuhara:: @ 85E6305
	.string "Satoshi Mitsuhara$"

gCreditsText_JapanBrailleLibrary:: @ 85E6317
	.string "Japan Braille Library$"

gCreditsText_TomotakaKomura:: @ 85E632D
	.string "Tomotaka Komura$"

gCreditsText_MikikoOhhashi:: @ 85E633D
	.string "Mikiko Ohhashi$"

gCreditsText_DaisukeHoshino:: @ 85E634C
	.string "Daisuke Hoshino$"

gCreditsText_KenjiroIto:: @ 85E635C
	.string "Kenjiro Ito$"

gCreditsText_RuiKawaguchi:: @ 85E6368
	.string "Rui Kawaguchi$"

gCreditsText_ShunsukeKohori:: @ 85E6376
	.string "Shunsuke Kohori$"

gCreditsText_SachikoNakamichi:: @ 85E6386
	.string "Sachiko Nakamichi$"

gCreditsText_FujikoNomura:: @ 85E6398
	.string "Fujiko Nomura$"

gCreditsText_KazukiYoshihara:: @ 85E63A6
	.string "Kazuki Yoshihara$"

gCreditsText_RetsujiNomoto:: @ 85E63B7
	.string "Retsuji Nomoto$"

gCreditsText_AzusaTajima:: @ 85E63C6
	.string "Azusa Tajima$"

gCreditsText_ShusakuEgami:: @ 85E63D3
	.string "Shusaku Egami$"

gCreditsText_PackageAndManual:: @ 85E63E1
	.string "Package & Manual Illustration$"

gCreditsText_EnglishVersion:: @ 85E63FF
	.string "English Version Coordinators$"

gCreditsText_Translator:: @ 85E641C
	.string "Translator$"

gCreditsText_TextEditor:: @ 85E6427
	.string "Text Editor$"

gCreditsText_NCLCoordinator:: @ 85E6433
	.string "NCL Coordinator$"

gCreditsText_GraphicDesigner:: @ 85E6443
	.string "Graphic Designer$"

gCreditsText_NOAProductTesting:: @ 85E6454
	.string "NOA Product Testing$"

gCreditsText_HideyukiNakajima:: @ 85E6468
	.string "Hideyuki Nakajima$"

gCreditsText_HidenoriSaeki:: @ 85E647A
	.string "Hidenori Saeki$"

gCreditsText_YokoWatanabe:: @ 85E6489
	.string "Yoko Watanabe$"

gCreditsText_SakaeKimura:: @ 85E6497
	.string "Sakae Kimura$"

gCreditsText_ChiakiShinkai:: @ 85E64A4
	.string "Chiaki Shinkai$"

gCreditsText_SethMcMahill:: @ 85E64B3
	.string "Seth McMahill$"

gCreditsText_NobOgasawara:: @ 85E64C1
	.string "Nob Ogasawara$"

gCreditsText_TeresaLillygren:: @ 85E64CF
	.string "Teresa Lillygren$"

gCreditsText_KimikoNakamichi:: @ 85E64E0
	.string "Kimiko Nakamichi$"

gCreditsText_SouichiYamamoto:: @ 85E64F1
	.string "Souichi Yamamoto$"

gCreditsText_YuichiroIto:: @ 85E6502
	.string "Yuichiro Ito$"

gCreditsText_ThomasHertzog:: @ 85E650F
	.string "Thomas Hertzog$"

gCreditsText_MikaKurosawa:: @ 85E651E
	.string "Mika Kurosawa$"

gCreditsText_NationalFederationBlind:: @ 85E652C
	.string "National Federation of the Blind$"

gCreditsText_PatriciaAMaurer:: @ 85E654D
	.string "Patricia A. Maurer$"

gCreditsText_EuropeanBlindUnion:: @ 85E6560
	.string "European Blind Union$"

gCreditsText_AustralianBrailleAuthority:: @ 85E6575
	.string "Australian Braille Authority$"

gCreditsText_RoyalNewZealandFederationBlind:: @ 85E6592
	.string "Royal New Zealand Federation for the Blind$"

gCreditsText_MotoyasuTojima:: @ 85E65BD
	.string "Motoyasu Tojima$"

gCreditsText_NicolaPrattBarlow:: @ 85E65CD
	.string "Nicola Pratt-Barlow$"

gCreditsText_ShellieDow:: @ 85E65E1
	.string "Shellie Dow$"

gCreditsText_ErikJohnson:: @ 85E65ED
	.string "Erik Johnson$"

	.align 2
gCreditsEntry_EmptyString:: @ 85E65FC
	.4byte 0x00000000, gCreditsText_EmptyString

	.align 2
gCreditsEntry_PkmnEmeraldVersion:: @ 85E6604
	.4byte 0x00000107, gCreditsText_PkmnEmeraldVersion

	.align 2
gCreditsEntry_Credits:: @ 85E660C
	.4byte 0x0000010b, gCreditsText_Credits

	.align 2
gCreditsEntry_ExecutiveDirector:: @ 85E6614
	.4byte 0x00000108, gCreditsText_ExecutiveDirector

	.align 2
gCreditsEntry_Director:: @ 85E661C
	.4byte 0x0000010c, gCreditsText_Director

	.align 2
gCreditsEntry_ArtDirector:: @ 85E6624
	.4byte 0x0000010a, gCreditsText_ArtDirector

	.align 2
gCreditsEntry_BattleDirector:: @ 85E662C
	.4byte 0x0000010a, gCreditsText_BattleDirector

	.align 2
gCreditsEntry_MainProgrammer:: @ 85E6634
	.4byte 0x0000010a, gCreditsText_MainProgrammer

	.align 2
gCreditsEntry_BattleSystemPgrms:: @ 85E663C
	.4byte 0x00000108, gCreditsText_BattleSystemPgrms

	.align 2
gCreditsEntry_FieldSystemPgrms:: @ 85E6644
	.4byte 0x00000107, gCreditsText_FieldSystemPgrms

	.align 2
gCreditsEntry_Programmers:: @ 85E664C
	.4byte 0x0000010c, gCreditsText_Programmers

	.align 2
gCreditsEntry_MainGraphicDesigner:: @ 85E6654
	.4byte 0x00000107, gCreditsText_MainGraphicDesigner

	.align 2
gCreditsEntry_GraphicDesigners:: @ 85E665C
	.4byte 0x00000109, gCreditsText_GraphicDesigners

	.align 2
gCreditsEntry_PkmnDesigners:: @ 85E6664
	.4byte 0x0000010a, gCreditsText_PkmnDesigners

	.align 2
gCreditsEntry_MusicComposition:: @ 85E666C
	.4byte 0x0000010d, gCreditsText_MusicComposition

	.align 2
gCreditsEntry_SoundEffectsAndPkmnVoices:: @ 85E6674
	.4byte 0x00000104, gCreditsText_SoundEffectsAndPkmnVoices

	.align 2
gCreditsEntry_GameDesigners:: @ 85E667C
	.4byte 0x0000010b, gCreditsText_GameDesigners

	.align 2
gCreditsEntry_ScenarioPlot:: @ 85E6684
	.4byte 0x0000010b, gCreditsText_ScenarioPlot

	.align 2
gCreditsEntry_Scenario:: @ 85E668C
	.4byte 0x0000010d, gCreditsText_Scenario

	.align 2
gCreditsEntry_ScriptDesigners:: @ 85E6694
	.4byte 0x0000010a, gCreditsText_ScriptDesigners

	.align 2
gCreditsEntry_MapDesigners:: @ 85E669C
	.4byte 0x0000010b, gCreditsText_MapDesigners

	.align 2
gCreditsEntry_MapDataDesigners:: @ 85E66A4
	.4byte 0x00000109, gCreditsText_MapDataDesigners

	.align 2
gCreditsEntry_ParametricDesigners:: @ 85E66AC
	.4byte 0x00000109, gCreditsText_ParametricDesigners

	.align 2
gCreditsEntry_PokedexText:: @ 85E66B4
	.4byte 0x0000010b, gCreditsText_PokedexText

	.align 2
gCreditsEntry_EnvAndToolPgrms:: @ 85E66BC
	.4byte 0x00000106, gCreditsText_EnvAndToolPgrms

	.align 2
gCreditsEntry_NCLProductTesting:: @ 85E66C4
	.4byte 0x0000010b, gCreditsText_NCLProductTesting

	.align 2
gCreditsEntry_SpecialThanks:: @ 85E66CC
	.4byte 0x0000010a, gCreditsText_SpecialThanks

	.align 2
gCreditsEntry_Coordinators:: @ 85E66D4
	.4byte 0x0000010b, gCreditsText_Coordinators

	.align 2
gCreditsEntry_Producers:: @ 85E66DC
	.4byte 0x0000010b, gCreditsText_Producers

	.align 2
gCreditsEntry_ExecProducers:: @ 85E66E4
	.4byte 0x00000107, gCreditsText_ExecProducers

	.align 2
gCreditsEntry_InfoSupervisors:: @ 85E66EC
	.4byte 0x0000010a, gCreditsText_InfoSupervisors

	.align 2
gCreditsEntry_TaskManagers:: @ 85E66F4
	.4byte 0x00000108, gCreditsText_TaskManagers

	.align 2
gCreditsEntry_BrailleCodeCheck:: @ 85E66FC
	.4byte 0x0000010a, gCreditsText_BrailleCodeCheck

	.align 2
gCreditsEntry_WorldDirector:: @ 85E6704
	.4byte 0x0000010a, gCreditsText_WorldDirector

	.align 2
gCreditsEntry_BattleFrontierData:: @ 85E670C
	.4byte 0x00000108, gCreditsText_BattleFrontierData

	.align 2
gCreditsEntry_SupportProgrammers:: @ 85E6714
	.4byte 0x0000010a, gCreditsText_SupportProgrammers

	.align 2
gCreditsEntry_Artwork:: @ 85E671C
	.4byte 0x0000010c, gCreditsText_Artwork

	.align 2
gCreditsEntry_LeadProgrammer:: @ 85E6724
	.4byte 0x0000010a, gCreditsText_LeadProgrammer

	.align 2
gCreditsEntry_LeadGraphicArtist:: @ 85E672C
	.4byte 0x00000109, gCreditsText_LeadGraphicArtist

	.align 2
gCreditsEntry_SatoshiTajiri:: @ 85E6734
	.4byte 0x0000000b, gCreditsText_SatoshiTajiri

	.align 2
gCreditsEntry_JunichiMasuda:: @ 85E673C
	.4byte 0x0000000b, gCreditsText_JunichiMasuda

	.align 2
gCreditsEntry_KenSugimori:: @ 85E6744
	.4byte 0x0000000b, gCreditsText_KenSugimori

	.align 2
gCreditsEntry_ShigekiMorimoto:: @ 85E674C
	.4byte 0x0000000b, gCreditsText_ShigekiMorimoto

	.align 2
gCreditsEntry_TetsuyaWatanabe:: @ 85E6754
	.4byte 0x0000000b, gCreditsText_TetsuyaWatanabe

	.align 2
gCreditsEntry_HisashiSogabe:: @ 85E675C
	.4byte 0x0000000b, gCreditsText_HisashiSogabe

	.align 2
gCreditsEntry_SosukeTamada:: @ 85E6764
	.4byte 0x0000000b, gCreditsText_SosukeTamada

	.align 2
gCreditsEntry_AkitoMori:: @ 85E676C
	.4byte 0x0000000b, gCreditsText_AkitoMori

	.align 2
gCreditsEntry_KeitaKagaya:: @ 85E6774
	.4byte 0x0000000b, gCreditsText_KeitaKagaya

	.align 2
gCreditsEntry_YoshinoriMatsuda:: @ 85E677C
	.4byte 0x0000000b, gCreditsText_YoshinoriMatsuda

	.align 2
gCreditsEntry_HiroyukiNakamura:: @ 85E6784
	.4byte 0x0000000b, gCreditsText_HiroyukiNakamura

	.align 2
gCreditsEntry_MasaoTaya:: @ 85E678C
	.4byte 0x0000000b, gCreditsText_MasaoTaya

	.align 2
gCreditsEntry_SatoshiNohara:: @ 85E6794
	.4byte 0x0000000b, gCreditsText_SatoshiNohara

	.align 2
gCreditsEntry_TomomichiOhta:: @ 85E679C
	.4byte 0x0000000b, gCreditsText_TomomichiOhta

	.align 2
gCreditsEntry_MiyukiIwasawa:: @ 85E67A4
	.4byte 0x0000000b, gCreditsText_MiyukiIwasawa

	.align 2
gCreditsEntry_TakenoriOhta:: @ 85E67AC
	.4byte 0x0000000b, gCreditsText_TakenoriOhta

	.align 2
gCreditsEntry_HironobuYoshida:: @ 85E67B4
	.4byte 0x0000000b, gCreditsText_HironobuYoshida

	.align 2
gCreditsEntry_MotofumiFujiwara:: @ 85E67BC
	.4byte 0x0000000b, gCreditsText_MotofumiFujiwara

	.align 2
gCreditsEntry_SatoshiOhta:: @ 85E67C4
	.4byte 0x0000000b, gCreditsText_SatoshiOhta

	.align 2
gCreditsEntry_AsukaIwashita:: @ 85E67CC
	.4byte 0x0000000b, gCreditsText_AsukaIwashita

	.align 2
gCreditsEntry_AimiTomita:: @ 85E67D4
	.4byte 0x0000000b, gCreditsText_AimiTomita

	.align 2
gCreditsEntry_TakaoUnno:: @ 85E67DC
	.4byte 0x0000000b, gCreditsText_TakaoUnno

	.align 2
gCreditsEntry_KanakoEo:: @ 85E67E4
	.4byte 0x0000000b, gCreditsText_KanakoEo

	.align 2
gCreditsEntry_JunOkutani:: @ 85E67EC
	.4byte 0x0000000b, gCreditsText_JunOkutani

	.align 2
gCreditsEntry_AtsukoNishida:: @ 85E67F4
	.4byte 0x0000000b, gCreditsText_AtsukoNishida

	.align 2
gCreditsEntry_MuneoSaito:: @ 85E67FC
	.4byte 0x0000000b, gCreditsText_MuneoSaito

	.align 2
gCreditsEntry_RenaYoshikawa:: @ 85E6804
	.4byte 0x0000000b, gCreditsText_RenaYoshikawa

	.align 2
gCreditsEntry_GoIchinose:: @ 85E680C
	.4byte 0x0000000b, gCreditsText_GoIchinose

	.align 2
gCreditsEntry_MorikazuAoki:: @ 85E6814
	.4byte 0x0000000b, gCreditsText_MorikazuAoki

	.align 2
gCreditsEntry_KojiNishino:: @ 85E681C
	.4byte 0x0000000b, gCreditsText_KojiNishino

	.align 2
gCreditsEntry_KenjiMatsushima:: @ 85E6824
	.4byte 0x0000000b, gCreditsText_KenjiMatsushima

	.align 2
gCreditsEntry_TetsujiOhta:: @ 85E682C
	.4byte 0x0000000b, gCreditsText_TetsujiOhta

	.align 2
gCreditsEntry_HitomiSato:: @ 85E6834
	.4byte 0x0000000b, gCreditsText_HitomiSato

	.align 2
gCreditsEntry_TakeshiKawachimaru:: @ 85E683C
	.4byte 0x0000000b, gCreditsText_TakeshiKawachimaru

	.align 2
gCreditsEntry_TeruyukiShimoyamada:: @ 85E6844
	.4byte 0x0000000b, gCreditsText_TeruyukiShimoyamada

	.align 2
gCreditsEntry_ShigeruOhmori:: @ 85E684C
	.4byte 0x0000000b, gCreditsText_ShigeruOhmori

	.align 2
gCreditsEntry_TadashiTakahashi:: @ 85E6854
	.4byte 0x0000000b, gCreditsText_TadashiTakahashi

	.align 2
gCreditsEntry_ToshinobuMatsumiya:: @ 85E685C
	.4byte 0x0000000b, gCreditsText_ToshinobuMatsumiya

	.align 2
gCreditsEntry_AkihitoTomisawa:: @ 85E6864
	.4byte 0x0000000b, gCreditsText_AkihitoTomisawa

	.align 2
gCreditsEntry_HirokiEnomoto:: @ 85E686C
	.4byte 0x0000000b, gCreditsText_HirokiEnomoto

	.align 2
gCreditsEntry_KazuyukiTerada:: @ 85E6874
	.4byte 0x0000000b, gCreditsText_KazuyukiTerada

	.align 2
gCreditsEntry_YuriSakurai:: @ 85E687C
	.4byte 0x0000000b, gCreditsText_YuriSakurai

	.align 2
gCreditsEntry_HiromiSagawa:: @ 85E6884
	.4byte 0x0000000b, gCreditsText_HiromiSagawa

	.align 2
gCreditsEntry_KenjiTominaga:: @ 85E688C
	.4byte 0x0000000b, gCreditsText_KenjiTominaga

	.align 2
gCreditsEntry_YoshioTajiri:: @ 85E6894
	.4byte 0x0000000b, gCreditsText_YoshioTajiri

	.align 2
gCreditsEntry_TeikoSasaki:: @ 85E689C
	.4byte 0x0000000b, gCreditsText_TeikoSasaki

	.align 2
gCreditsEntry_SachikoHamano:: @ 85E68A4
	.4byte 0x0000000b, gCreditsText_SachikoHamano

	.align 2
gCreditsEntry_ChieMatsumiya:: @ 85E68AC
	.4byte 0x0000000b, gCreditsText_ChieMatsumiya

	.align 2
gCreditsEntry_AkikoShinozaki:: @ 85E68B4
	.4byte 0x0000000b, gCreditsText_AkikoShinozaki

	.align 2
gCreditsEntry_AstukoFujii:: @ 85E68BC
	.4byte 0x0000000b, gCreditsText_AstukoFujii

	.align 2
gCreditsEntry_NozomuSaito:: @ 85E68C4
	.4byte 0x0000000b, gCreditsText_NozomuSaito

	.align 2
gCreditsEntry_KenkichiToyama:: @ 85E68CC
	.4byte 0x0000000b, gCreditsText_KenkichiToyama

	.align 2
gCreditsEntry_SuguruNakatsui:: @ 85E68D4
	.4byte 0x0000000b, gCreditsText_SuguruNakatsui

	.align 2
gCreditsEntry_YumiFunasaka:: @ 85E68DC
	.4byte 0x0000000b, gCreditsText_YumiFunasaka

	.align 2
gCreditsEntry_NaokoYanase:: @ 85E68E4
	.4byte 0x0000000b, gCreditsText_NaokoYanase

	.align 2
gCreditsEntry_NCLSuperMarioClub:: @ 85E68EC
	.4byte 0x0000000b, gCreditsText_NCLSuperMarioClub

	.align 2
gCreditsEntry_AtsushiTada:: @ 85E68F4
	.4byte 0x0000000b, gCreditsText_AtsushiTada

	.align 2
gCreditsEntry_TakahiroOhnishi:: @ 85E68FC
	.4byte 0x0000000b, gCreditsText_TakahiroOhnishi

	.align 2
gCreditsEntry_NorihideOkamura:: @ 85E6904
	.4byte 0x0000000b, gCreditsText_NorihideOkamura

	.align 2
gCreditsEntry_HiroNakamura:: @ 85E690C
	.4byte 0x0000000b, gCreditsText_HiroNakamura

	.align 2
gCreditsEntry_HiroyukiUesugi:: @ 85E6914
	.4byte 0x0000000b, gCreditsText_HiroyukiUesugi

	.align 2
gCreditsEntry_TerukiMurakawa:: @ 85E691C
	.4byte 0x0000000b, gCreditsText_TerukiMurakawa

	.align 2
gCreditsEntry_AkiraKinashi:: @ 85E6924
	.4byte 0x0000000b, gCreditsText_AkiraKinashi

	.align 2
gCreditsEntry_MichikoTakizawa:: @ 85E692C
	.4byte 0x0000000b, gCreditsText_MichikoTakizawa

	.align 2
gCreditsEntry_MakikoTakada:: @ 85E6934
	.4byte 0x0000000b, gCreditsText_MakikoTakada

	.align 2
gCreditsEntry_TakanaoKondo:: @ 85E693C
	.4byte 0x0000000b, gCreditsText_TakanaoKondo

	.align 2
gCreditsEntry_AiMashima:: @ 85E6944
	.4byte 0x0000000b, gCreditsText_AiMashima

	.align 2
gCreditsEntry_GakujiNomoto:: @ 85E694C
	.4byte 0x0000000b, gCreditsText_GakujiNomoto

	.align 2
gCreditsEntry_TakehiroIzushi:: @ 85E6954
	.4byte 0x0000000b, gCreditsText_TakehiroIzushi

	.align 2
gCreditsEntry_HitoshiYamagami:: @ 85E695C
	.4byte 0x0000000b, gCreditsText_HitoshiYamagami

	.align 2
gCreditsEntry_KyokoWatanabe:: @ 85E6964
	.4byte 0x0000000b, gCreditsText_KyokoWatanabe

	.align 2
gCreditsEntry_TakaoNakano:: @ 85E696C
	.4byte 0x0000000b, gCreditsText_TakaoNakano

	.align 2
gCreditsEntry_HiroyukiJinnai:: @ 85E6974
	.4byte 0x0000000b, gCreditsText_HiroyukiJinnai

	.align 2
gCreditsEntry_HiroakiTsuru:: @ 85E697C
	.4byte 0x0000000b, gCreditsText_HiroakiTsuru

	.align 2
gCreditsEntry_TsunekazIshihara:: @ 85E6984
	.4byte 0x0000000b, gCreditsText_TsunekazIshihara

	.align 2
gCreditsEntry_SatoruIwata:: @ 85E698C
	.4byte 0x0000000b, gCreditsText_SatoruIwata

	.align 2
gCreditsEntry_KazuyaSuyama:: @ 85E6994
	.4byte 0x0000000b, gCreditsText_KazuyaSuyama

	.align 2
gCreditsEntry_SatoshiMitsuhara:: @ 85E699C
	.4byte 0x0000000b, gCreditsText_SatoshiMitsuhara

	.align 2
gCreditsEntry_JapanBrailleLibrary:: @ 85E69A4
	.4byte 0x00000009, gCreditsText_JapanBrailleLibrary

	.align 2
gCreditsEntry_TomotakaKomura:: @ 85E69AC
	.4byte 0x0000000b, gCreditsText_TomotakaKomura

	.align 2
gCreditsEntry_MikikoOhhashi:: @ 85E69B4
	.4byte 0x0000000b, gCreditsText_MikikoOhhashi

	.align 2
gCreditsEntry_DaisukeHoshino:: @ 85E69BC
	.4byte 0x0000000b, gCreditsText_DaisukeHoshino

	.align 2
gCreditsEntry_KenjiroIto:: @ 85E69C4
	.4byte 0x0000000b, gCreditsText_KenjiroIto

	.align 2
gCreditsEntry_RuiKawaguchi:: @ 85E69CC
	.4byte 0x0000000b, gCreditsText_RuiKawaguchi

	.align 2
gCreditsEntry_ShunsukeKohori:: @ 85E69D4
	.4byte 0x0000000b, gCreditsText_ShunsukeKohori

	.align 2
gCreditsEntry_SachikoNakamichi:: @ 85E69DC
	.4byte 0x0000000b, gCreditsText_SachikoNakamichi

	.align 2
gCreditsEntry_FujikoNomura:: @ 85E69E4
	.4byte 0x0000000b, gCreditsText_FujikoNomura

	.align 2
gCreditsEntry_KazukiYoshihara:: @ 85E69EC
	.4byte 0x0000000b, gCreditsText_KazukiYoshihara

	.align 2
gCreditsEntry_RetsujiNomoto:: @ 85E69F4
	.4byte 0x0000000b, gCreditsText_RetsujiNomoto

	.align 2
gCreditsEntry_AzusaTajima:: @ 85E69FC
	.4byte 0x0000000b, gCreditsText_AzusaTajima

	.align 2
gCreditsEntry_ShusakuEgami:: @ 85E6A04
	.4byte 0x0000000b, gCreditsText_ShusakuEgami

	.align 2
gCreditsEntry_PackageAndManual:: @ 85E6A0C
	.4byte 0x00000100, gCreditsText_PackageAndManual

	.align 2
gCreditsEntry_EnglishVersion:: @ 85E6A14
	.4byte 0x00000100, gCreditsText_EnglishVersion

	.align 2
gCreditsEntry_Translator:: @ 85E6A1C
	.4byte 0x00000100, gCreditsText_Translator

	.align 2
gCreditsEntry_TextEditor:: @ 85E6A24
	.4byte 0x00000100, gCreditsText_TextEditor

	.align 2
gCreditsEntry_NCLCoordinator:: @ 85E6A2C
	.4byte 0x00000100, gCreditsText_NCLCoordinator

	.align 2
gCreditsEntry_GraphicDesigner:: @ 85E6A34
	.4byte 0x00000100, gCreditsText_GraphicDesigner

	.align 2
gCreditsEntry_NOAProductTesting:: @ 85E6A3C
	.4byte 0x00000100, gCreditsText_NOAProductTesting

	.align 2
gCreditsEntry_HideyukiNakajima:: @ 85E6A44
	.4byte 0x00000000, gCreditsText_HideyukiNakajima

	.align 2
gCreditsEntry_HidenoriSaeki:: @ 85E6A4C
	.4byte 0x00000000, gCreditsText_HidenoriSaeki

	.align 2
gCreditsEntry_YokoWatanabe:: @ 85E6A54
	.4byte 0x00000000, gCreditsText_YokoWatanabe

	.align 2
gCreditsEntry_SakaeKimura:: @ 85E6A5C
	.4byte 0x00000000, gCreditsText_SakaeKimura

	.align 2
gCreditsEntry_ChiakiShinkai:: @ 85E6A64
	.4byte 0x00000000, gCreditsText_ChiakiShinkai

	.align 2
gCreditsEntry_SethMcMahill:: @ 85E6A6C
	.4byte 0x00000000, gCreditsText_SethMcMahill

	.align 2
gCreditsEntry_NobOgasawara:: @ 85E6A74
	.4byte 0x00000000, gCreditsText_NobOgasawara

	.align 2
gCreditsEntry_TeresaLillygren:: @ 85E6A7C
	.4byte 0x00000000, gCreditsText_TeresaLillygren

	.align 2
gCreditsEntry_KimikoNakamichi:: @ 85E6A84
	.4byte 0x00000000, gCreditsText_KimikoNakamichi

	.align 2
gCreditsEntry_SouichiYamamoto:: @ 85E6A8C
	.4byte 0x00000000, gCreditsText_SouichiYamamoto

	.align 2
gCreditsEntry_YuichiroIto:: @ 85E6A94
	.4byte 0x00000000, gCreditsText_YuichiroIto

	.align 2
gCreditsEntry_ThomasHertzog:: @ 85E6A9C
	.4byte 0x00000000, gCreditsText_ThomasHertzog

	.align 2
gCreditsEntry_MikaKurosawa:: @ 85E6AA4
	.4byte 0x00000000, gCreditsText_MikaKurosawa

	.align 2
gCreditsEntry_NationalFederationBlind:: @ 85E6AAC
	.4byte 0x00000000, gCreditsText_NationalFederationBlind

	.align 2
gCreditsEntry_PatriciaAMaurer:: @ 85E6AB4
	.4byte 0x00000000, gCreditsText_PatriciaAMaurer

	.align 2
gCreditsEntry_EuropeanBlindUnion:: @ 85E6ABC
	.4byte 0x00000000, gCreditsText_EuropeanBlindUnion

	.align 2
gCreditsEntry_AustralianBrailleAuthority:: @ 85E6AC4
	.4byte 0x00000000, gCreditsText_AustralianBrailleAuthority

	.align 2
gCreditsEntry_RoyalNewZealandFederationBlind:: @ 85E6ACC
	.4byte 0x00000000, gCreditsText_RoyalNewZealandFederationBlind

	.align 2
gCreditsEntry_MotoyasuTojima:: @ 85E6AD4
	.4byte 0x00000000, gCreditsText_MotoyasuTojima

	.align 2
gCreditsEntry_NicolaPrattBarlow:: @ 85E6ADC
	.4byte 0x00000000, gCreditsText_NicolaPrattBarlow

	.align 2
gCreditsEntry_ShellieDow:: @ 85E6AE4
	.4byte 0x00000000, gCreditsText_ShellieDow

	.align 2
gCreditsEntry_ErikJohnson:: @ 85E6AEC
	.4byte 0x00000000, gCreditsText_ErikJohnson

    .align 2
gUnknown_085E6AF4:: @ 85E6AF4
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_PkmnEmeraldVersion
	.4byte gCreditsEntry_Credits
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_Director
	.4byte gCreditsEntry_ShigekiMorimoto
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_ArtDirector
	.4byte gCreditsEntry_KenSugimori
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_WorldDirector
	.4byte gCreditsEntry_JunichiMasuda
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_LeadProgrammer
	.4byte gCreditsEntry_HisashiSogabe
	.4byte gCreditsEntry_LeadGraphicArtist
	.4byte gCreditsEntry_MotofumiFujiwara
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Programmers
	.4byte gCreditsEntry_HisashiSogabe
	.4byte gCreditsEntry_TomomichiOhta
	.4byte gCreditsEntry_NozomuSaito
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Programmers
	.4byte gCreditsEntry_AkitoMori
	.4byte gCreditsEntry_HiroyukiNakamura
	.4byte gCreditsEntry_MasaoTaya
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Programmers
	.4byte gCreditsEntry_SatoshiNohara
	.4byte gCreditsEntry_MiyukiIwasawa
	.4byte gCreditsEntry_YoshinoriMatsuda
	.4byte gCreditsEntry_KeitaKagaya

	.4byte gCreditsEntry_Programmers
	.4byte gCreditsEntry_TetsuyaWatanabe
	.4byte gCreditsEntry_SosukeTamada
	.4byte gCreditsEntry_TakenoriOhta
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_GraphicDesigners
	.4byte gCreditsEntry_MotofumiFujiwara
	.4byte gCreditsEntry_SatoshiOhta
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_GraphicDesigners
	.4byte gCreditsEntry_KenkichiToyama
	.4byte gCreditsEntry_AsukaIwashita
	.4byte gCreditsEntry_TakaoUnno
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_GraphicDesigners
	.4byte gCreditsEntry_KenSugimori
	.4byte gCreditsEntry_HironobuYoshida
	.4byte gCreditsEntry_AimiTomita
	.4byte gCreditsEntry_KanakoEo

	.4byte gCreditsEntry_MusicComposition
	.4byte gCreditsEntry_GoIchinose
	.4byte gCreditsEntry_JunichiMasuda
	.4byte gCreditsEntry_MorikazuAoki
	.4byte gCreditsEntry_HitomiSato

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_SoundEffectsAndPkmnVoices
	.4byte gCreditsEntry_GoIchinose
	.4byte gCreditsEntry_MorikazuAoki
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_GameDesigners
	.4byte gCreditsEntry_ShigekiMorimoto
	.4byte gCreditsEntry_TeruyukiShimoyamada
	.4byte gCreditsEntry_TakeshiKawachimaru
	.4byte gCreditsEntry_AkihitoTomisawa

	.4byte gCreditsEntry_GameDesigners
	.4byte gCreditsEntry_SuguruNakatsui
	.4byte gCreditsEntry_TetsujiOhta
	.4byte gCreditsEntry_HitomiSato
	.4byte gCreditsEntry_KenjiMatsushima

	.4byte gCreditsEntry_GameDesigners
	.4byte gCreditsEntry_JunichiMasuda
	.4byte gCreditsEntry_KojiNishino
	.4byte gCreditsEntry_ShigeruOhmori
	.4byte gCreditsEntry_TadashiTakahashi

	.4byte gCreditsEntry_ScenarioPlot
	.4byte gCreditsEntry_AkihitoTomisawa
	.4byte gCreditsEntry_JunichiMasuda
	.4byte gCreditsEntry_KojiNishino
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Scenario
	.4byte gCreditsEntry_AkihitoTomisawa
	.4byte gCreditsEntry_HitomiSato
	.4byte gCreditsEntry_ToshinobuMatsumiya
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_ScriptDesigners
	.4byte gCreditsEntry_TomomichiOhta
	.4byte gCreditsEntry_SatoshiNohara
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_MapDesigners
	.4byte gCreditsEntry_SuguruNakatsui
	.4byte gCreditsEntry_TeruyukiShimoyamada
	.4byte gCreditsEntry_ShigeruOhmori
	.4byte gCreditsEntry_TetsujiOhta

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_BattleFrontierData
	.4byte gCreditsEntry_TetsujiOhta
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_ParametricDesigners
	.4byte gCreditsEntry_TeruyukiShimoyamada
	.4byte gCreditsEntry_ShigekiMorimoto
	.4byte gCreditsEntry_TetsujiOhta
	.4byte gCreditsEntry_KojiNishino

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_PokedexText
	.4byte gCreditsEntry_KenjiMatsushima
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EnvAndToolPgrms
	.4byte gCreditsEntry_HisashiSogabe
	.4byte gCreditsEntry_SosukeTamada
	.4byte gCreditsEntry_HiroyukiNakamura
	.4byte gCreditsEntry_AkitoMori

	.4byte gCreditsEntry_PkmnDesigners
	.4byte gCreditsEntry_KenSugimori
	.4byte gCreditsEntry_MotofumiFujiwara
	.4byte gCreditsEntry_ShigekiMorimoto
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_PkmnDesigners
	.4byte gCreditsEntry_HironobuYoshida
	.4byte gCreditsEntry_SatoshiOhta
	.4byte gCreditsEntry_AsukaIwashita
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_PkmnDesigners
	.4byte gCreditsEntry_TakaoUnno
	.4byte gCreditsEntry_KanakoEo
	.4byte gCreditsEntry_AimiTomita
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_PkmnDesigners
	.4byte gCreditsEntry_AtsukoNishida
	.4byte gCreditsEntry_MuneoSaito
	.4byte gCreditsEntry_RenaYoshikawa
	.4byte gCreditsEntry_JunOkutani

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_SupportProgrammers
	.4byte gCreditsEntry_SatoshiMitsuhara
	.4byte gCreditsEntry_DaisukeHoshino
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_NCLProductTesting
	.4byte gCreditsEntry_NCLSuperMarioClub
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_PackageAndManual
	.4byte gCreditsEntry_KenSugimori
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_SpecialThanks
	.4byte gCreditsEntry_KenjiTominaga
	.4byte gCreditsEntry_HirokiEnomoto
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_SpecialThanks
	.4byte gCreditsEntry_KazuyaSuyama
	.4byte gCreditsEntry_KenjiroIto
	.4byte gCreditsEntry_MichikoTakizawa
	.4byte gCreditsEntry_MakikoTakada

	.4byte gCreditsEntry_SpecialThanks
	.4byte gCreditsEntry_MikikoOhhashi
	.4byte gCreditsEntry_TakanaoKondo
	.4byte gCreditsEntry_RuiKawaguchi
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_SpecialThanks
	.4byte gCreditsEntry_TakahiroOhnishi
	.4byte gCreditsEntry_NorihideOkamura
	.4byte gCreditsEntry_ShunsukeKohori
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_InfoSupervisors
	.4byte gCreditsEntry_KazuyukiTerada
	.4byte gCreditsEntry_YuriSakurai
	.4byte gCreditsEntry_YumiFunasaka
	.4byte gCreditsEntry_NaokoYanase

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_Artwork
	.4byte gCreditsEntry_SachikoNakamichi
	.4byte gCreditsEntry_FujikoNomura
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_Artwork
	.4byte gCreditsEntry_HideyukiNakajima
	.4byte gCreditsEntry_HidenoriSaeki
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Artwork
	.4byte gCreditsEntry_YokoWatanabe
	.4byte gCreditsEntry_SakaeKimura
	.4byte gCreditsEntry_ChiakiShinkai
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Coordinators
	.4byte gCreditsEntry_KazukiYoshihara
	.4byte gCreditsEntry_AkiraKinashi
	.4byte gCreditsEntry_RetsujiNomoto
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EnglishVersion
	.4byte gCreditsEntry_HiroNakamura
	.4byte gCreditsEntry_SethMcMahill
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_Translator
	.4byte gCreditsEntry_NobOgasawara
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_TextEditor
	.4byte gCreditsEntry_TeresaLillygren
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_NCLCoordinator
	.4byte gCreditsEntry_KimikoNakamichi
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Programmers
	.4byte gCreditsEntry_TerukiMurakawa
	.4byte gCreditsEntry_SouichiYamamoto
	.4byte gCreditsEntry_YuichiroIto
	.4byte gCreditsEntry_AkiraKinashi

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_GraphicDesigner
	.4byte gCreditsEntry_AkiraKinashi
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EnvAndToolPgrms
	.4byte gCreditsEntry_TerukiMurakawa
	.4byte gCreditsEntry_SouichiYamamoto
	.4byte gCreditsEntry_KimikoNakamichi
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_NOAProductTesting
	.4byte gCreditsEntry_ThomasHertzog
	.4byte gCreditsEntry_ErikJohnson
	.4byte gCreditsEntry_MikaKurosawa
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_BrailleCodeCheck
	.4byte gCreditsEntry_NationalFederationBlind
	.4byte gCreditsEntry_PatriciaAMaurer
	.4byte gCreditsEntry_JapanBrailleLibrary
	.4byte gCreditsEntry_EuropeanBlindUnion

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_BrailleCodeCheck
	.4byte gCreditsEntry_AustralianBrailleAuthority
	.4byte gCreditsEntry_RoyalNewZealandFederationBlind
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_SpecialThanks
	.4byte gCreditsEntry_HiroyukiUesugi
	.4byte gCreditsEntry_MotoyasuTojima
	.4byte gCreditsEntry_NicolaPrattBarlow
	.4byte gCreditsEntry_ShellieDow

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_TaskManagers
	.4byte gCreditsEntry_AzusaTajima
	.4byte gCreditsEntry_ShusakuEgami
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_Producers
	.4byte gCreditsEntry_HiroyukiJinnai
	.4byte gCreditsEntry_HitoshiYamagami
	.4byte gCreditsEntry_GakujiNomoto
	.4byte gCreditsEntry_HiroakiTsuru

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_ExecutiveDirector
	.4byte gCreditsEntry_SatoshiTajiri
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_ExecProducers
	.4byte gCreditsEntry_SatoruIwata
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_ExecProducers
	.4byte gCreditsEntry_TsunekazIshihara
	.4byte gCreditsEntry_EmptyString
	.4byte gCreditsEntry_EmptyString

	.align 2
gUnknown_085E6F68:: @ 85E6F68 struct BgTemplate
	.4byte 0x000001C8

	.align 2
gUnknown_085E6F6C:: @ 85E6F6C
	window_template 0x00, 0x00, 0x09, 0x1e, 0x0c, 0x08, 0x0001
	null_window_template

	.align 2
gUnknown_085E6F7C:: @ 85E6F7C
	.byte 0x68, 0x24, 0x78, 0x24, 0x88, 0x24, 0x00, 0x00

	.align 2
gUnknown_085E6F84:: @ 85E6F84
	.2byte 0x0000, 0x0008, 0x0040, 0x0008, 0x0080, 0x0008, 0x00c0, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_085E6F98:: @ 85E6F98
	.2byte 0x0000, 0x0004, 0x0040, 0x0004, 0x0080, 0x0004, 0x00c0, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_085E6FAC:: @ 85E6FAC
	.2byte 0x0100, 0x0004, 0x0140, 0x0004, 0x0180, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085E6FBC:: @ 85E6FBC
	.2byte 0x0180, 0x001e, 0x0140, 0x001e, 0x0100, 0x001e, 0x0100, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_085E6FD0:: @ 85E6FD0
	.4byte gUnknown_085E6F84
	.4byte gUnknown_085E6F98
	.4byte gUnknown_085E6FAC
	.4byte gUnknown_085E6FBC

	.align 2
gUnknown_085E6FE0:: @ 85E6FE0
	.2byte 0x0000, 0x0008, 0x0040, 0x0008, 0x0080, 0x0008, 0x00c0, 0x0008, 0xfffe, 0x0000

	.align 2
gUnknown_085E6FF4:: @ 85E6FF4
	.2byte 0x0000, 0x0004, 0x0040, 0x0004, 0x0080, 0x0004, 0x00c0, 0x0004, 0xfffe, 0x0000

	.align 2
gUnknown_085E7008:: @ 85E7008
	.2byte 0x0000, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_085E7010:: @ 85E7010
	.4byte gUnknown_085E6FE0
	.4byte gUnknown_085E6FF4
	.4byte gUnknown_085E7008

	.align 2
gUnknown_085E701C:: @ 85E701C
	obj_tiles gDecompressionBuffer, 0x1800, 0x03E9
	null_obj_tiles

	.align 2
gUnknown_085E702C:: @ 85E702C
	obj_pal gDecompressionBuffer + 0x1800, 0x03E9
	null_obj_pal

	.align 2
gUnknown_085E703C:: @ 85E703C
	.2byte 0x00a0, 0xc000, 0x0400, 0x0000
	
	.align 2
gUnknown_085E7044:: @ 85E7044
	.2byte 0x0000, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E704C:: @ 85E704C
	.2byte 0x0040, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E7054:: @ 85E7054
	.2byte 0x0080, 0x0008, 0xffff, 0x0000

	.align 2
gUnknown_085E705C:: @ 85E705C
	.4byte gUnknown_085E7044
	.4byte gUnknown_085E704C
	.4byte gUnknown_085E7054

	.align 2
gUnknown_085E7068:: @ 85E7068
	spr_template 0x03e9, 0x03e9, gUnknown_085E703C, gUnknown_085E705C, NULL, gDummySpriteAffineAnimTable, sub_81772B8
