	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.align 2

gUnknown_082ED82C:: @ 82ED82C
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00

gUnknown_082ED84B:: @ 82ED84B
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00

gUnknown_082ED85B:: @ 82ED85B
	.byte 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
	.byte 0x00, 0x20, 0x00, 0x2a, 0x00

gUnknown_082ED868:: @ 82ED868
	.asciz "NOWSLOT"

	.asciz "           "

	.asciz "CLOCK DRIFT"

	.asciz "BUSY SEND  "

	.asciz "CMD REJECT "

	.asciz "CLOCK SLAVE"

	.ascii "CHILD "

	.align 2
	.ascii "PARENT"

	.align 2
	.ascii "SEARCH"

	.align 2
gText_EmptyString:: @ 82ED8C4
	.string "$"

	.align 2
gText_Colon:: @ 82ED8C8
	.string ":$"

	.align 2
gText_UnkCtrlCodeF907:: @ 82ED8CC
	.string "{ID}$"

	.align 2
gText_PleaseStartOver:: @ 82ED8D0
	.string "Please start over from the beginning.$"

	.align 2
gText_WirelessSearchCanceled:: @ 82ED8F8
	.string "The WIRELESS COMMUNICATION\nSYSTEM search has been canceled.$"

	.align 2
	.string "Awaiting communication\nfrom another player.$"

	.align 2
gText_AwaitingCommunication:: @ 82ED960
	.string "{STR_VAR_1}! Awaiting\ncommunication from another player.$"

gText_AwaitingLink:: @ 82ED990
	.string "{STR_VAR_1}! Awaiting link!\nPress START when everyone's ready.$"

	.align 2
gJPText_SingleBattle:: @ 82ED9C8
	.string "シングルバトルを かいさいする$" @ "shingurubatoruwo kaisaisuru" ("hold a single battle" in Japanese)

	.align 2
gJPText_DoubleBattle:: @ 82ED9D8
	.string "ダブルバトルを かいさいする$" @ "daburubatoruwo kaisaisuru" ("hold a double battle" in Japanese)

	.align 2
gJPText_MultiBattle:: @ 82ED9E8
	.string "マルチバトルを かいさいする$" @ "maruchibatoruwo kaisaisuru" ("hold a multi battle" in Japanese)

	.align 2
gJPText_TradePokemon:: @ 82ED9F8
	.string "ポケモンこうかんを かいさいする$" @ "pokemonkoukanwo kaisaisuru" ("trade Pokémon" in Japanese)

	.align 2
gJPText_Chat:: @ 82EDA0C
	.string "チャットを かいさいする$" @ "chattowo kaisaisuru" ("chat" in Japanese)

	.align 2
gJPText_DistWonderCard:: @ 82EDA1C
	.string "ふしぎなカードをくばる$" @ "fushiginakaadowokubaru" ("distribute Wonder Card" in Japanese)

	.align 2
gJPText_DistWonderNews:: @ 82EDA28
	.string "ふしぎなニュースをくばる$" @ "fushiginanyuusuwokubaru" ("distribute Wonder News" in Japanese)

	.align 2
	.string "ふしぎなできごとを かいさいする$" @ "fushiginadekigotowo kaisaisuru" ("hold a session of Mystery Event" in Japanese)

	.align 2
gJPText_HoldPokemonJump:: @ 82EDA4C
	.string "なわとびを かいさいする$" @ "nawatobiwo kaisaisuru" ("hold a session of Jump" in Japanese)

	.align 2
gJPText_HoldBerryCrush:: @ 82EDA5C
	.string "きのみマッシャーを かいさいする$" @ "kinomimassha-wo kaisaisuru" ("hold a session of Berry Masher" in Japanese)

	.align 2
gJPText_HoldBerryPicking:: @ 82EDA70
	.string "きのみどりを かいさいする$" @ "kinomidoriwo kaisaisuru" ("hold a session of Berry Picking" in Japanese)

	.align 2
gJPText_HoldSpinTrade:: @ 82EDA80
	.string "ぐるぐるこうかんを かいさいする$" @ "gurugurukoukanwo kaisaisuru" ("hold a session of Spin Trade" in Japanese)

	.align 2
gJPText_HoldSpinShop:: @ 82EDA94
	.string "ぐるぐるショップを かいさいする$" @ "gurugurushoppuwo kaisaisuru" ("hold a session of Spin Shop" in Japanese)

	.align 2
	.4byte gJPText_SingleBattle
	.4byte gJPText_DoubleBattle
	.4byte gJPText_MultiBattle
	.4byte gJPText_TradePokemon
	.4byte gJPText_Chat
	.4byte gJPText_DistWonderCard
	.4byte gJPText_DistWonderNews
	.4byte gJPText_DistWonderCard
	.4byte gJPText_HoldPokemonJump
	.4byte gJPText_HoldBerryCrush
	.4byte gJPText_HoldBerryPicking
	.4byte gJPText_HoldBerryPicking
	.4byte gJPText_HoldSpinTrade
	.4byte gJPText_HoldSpinShop

gText_1PlayerNeeded:: @ 82EDAE0
	.string "1 player\nneeded.$"

gText_2PlayersNeeded:: @ 82EDAF1
	.string "2 players\nneeded.$"

gText_3PlayersNeeded:: @ 82EDB03
	.string "3 players\nneeded.$"

gText_4PlayersNeeded:: @ 82EDB15
	.string "4 players\nneeded.$"

gText_2PlayerMode:: @ 82EDB27
	.string "2-PLAYER\nMODE$"

gText_3PlayerMode:: @ 82EDB35
	.string "3-PLAYER\nMODE$"

gText_4PlayerMode:: @ 82EDB43
	.string "4-PLAYER\nMODE$"

gText_5PlayerMode:: @ 82EDB51
	.string "5-PLAYER\nMODE$"

	.align 2
gUnknown_082EDB60:: @ 82EDB60
	.4byte gText_1PlayerNeeded
	.4byte gText_2PlayerMode
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gText_3PlayersNeeded
	.4byte gText_2PlayersNeeded
	.4byte gText_1PlayerNeeded
	.4byte gText_4PlayerMode
	.4byte NULL
	.4byte gText_1PlayerNeeded
	.4byte gText_2PlayerMode
	.4byte gText_3PlayerMode
	.4byte gText_4PlayerMode
	.4byte gText_5PlayerMode
	.4byte gText_2PlayersNeeded
	.4byte gText_1PlayerNeeded
	.4byte gText_3PlayerMode
	.4byte gText_4PlayerMode
	.4byte gText_5PlayerMode
	.4byte gText_1PlayerNeeded
	.4byte gText_2PlayerMode
	.4byte gText_3PlayerMode
	.4byte gText_4PlayerMode
	.4byte NULL

	.align 2
gUnknown_082EDBC4:: @ 82EDBC4
	.string "{B_BUTTON}CANCEL$"

	.align 2
	.string "ため\nさんかしゃ ぼしゅうちゅう です！$" @ "tame\nsankasha boshuuchuu desu!"

	.align 2
gUnknown_082EDBE8:: @ 82EDBE8
	.string "{STR_VAR_2} contacted you for\n{STR_VAR_1}. Accept?$"

	.align 2
gUnknown_082EDC0C:: @ 82EDC0C
	.string "{STR_VAR_2} contacted you.\nWill you share {STR_VAR_1}?$"

	.align 2
gUnknown_082EDC34:: @ 82EDC34
	.string "{STR_VAR_2} contacted you.\nAdd to the members?$"

	.align 2
gUnknown_082EDC5C:: @ 82EDC5C
	.string "{STR_VAR_1}!\nAre these members OK?$"

	.align 2
gUnknown_082EDC78:: @ 82EDC78
	.string "Cancel {STR_VAR_1} MODE\nwith these members?$"

	.align 2
gUnknown_082EDC9C:: @ 82EDC9C
	.string "An “OK” was sent\nto {STR_VAR_1}.$"

	.align 2
gUnknown_082EDCB4:: @ 82EDCB4
	.string "The other TRAINER doesn't appear\nto be available now…\p$"

	.align 2
gUnknown_082EDCEC:: @ 82EDCEC
	.string "You can't transmit with a TRAINER\nwho is too far away.\p$"

	.align 2
gUnknown_082EDD24:: @ 82EDD24
	.string "The other TRAINER(S) is/are not\nready yet.\p$"

	.align 2
gUnknown_082EDD50:: @ 82EDD50
	.4byte gUnknown_082EDCEC
	.4byte gUnknown_082EDD24

	.align 2
gUnknown_082EDD58:: @ 82EDD58
	.string "The {STR_VAR_1} MODE with\nthese members will be canceled.{PAUSE 60}$"

	.align 2
gUnknown_082EDD8C:: @ 82EDD8C
	.string "There is a member who can no\nlonger remain available.\p$"

	.align 2
gUnknown_082EDDC4:: @ 82EDDC4
	.4byte gUnknown_082EDCB4
	.4byte gUnknown_082EDD8C

	.align 2
gUnknown_082EDDCC:: @ 82EDDCC
	.string "The other TRAINER appears\nunavailable…\p$"

	.align 2
gUnknown_082EDDF4:: @ 82EDDF4
	.string "{STR_VAR_1} sent back an “OK”!$"

	.align 2
gUnknown_082EDE0C:: @ 82EDE0C
	.string "{STR_VAR_1} OK'd your registration as\na member.$"

	.align 2
gUnknown_082EDE34:: @ 82EDE34
	.string "{STR_VAR_1} replied, “No…”\p$"

	.align 2
gUnknown_082EDE48:: @ 82EDE48
	.string "{STR_VAR_1}!\nAwaiting other members!$"

	.align 2
gUnknown_082EDE64:: @ 82EDE64
	.string "Quit being a member?$"

	.align 2
gUnknown_082EDE7C:: @ 82EDE7C
	.string "You stopped being a member.\p$"

	.align 2
gUnknown_082EDE9C:: @ 82EDE9C
	.4byte NULL
	.4byte gUnknown_082EDD8C
	.4byte gUnknown_082EDDCC
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDE34
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDE7C

	.align 2
gUnknown_082EDEC4:: @ 82EDEC4
	.string "The WIRELESS COMMUNICATION\nSYSTEM link has been established.$"

	.align 2
gUnknown_082EDF04:: @ 82EDF04
	.string "The WIRELESS COMMUNICATION\nSYSTEM link has been dropped…$"

	.align 2
gUnknown_082EDF40:: @ 82EDF40
	.string "The link with your friend has been\ndropped…$"

	.align 2
gUnknown_082EDF6C:: @ 82EDF6C
	.string "{STR_VAR_1} replied, “No…”$"

	.align 2
gUnknown_082EDF80:: @ 82EDF80
	.4byte NULL
	.4byte gUnknown_082EDF40
	.4byte gUnknown_082EDF40
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EDF6C
	.4byte NULL
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_082EDFA8:: @ 82EDF80
	.string "Do you want the {STR_VAR_2}\nMODE?$"

	.align 2
gUnknown_082EDFC4:: @ 82EDFC4
	.string "Do you want the {STR_VAR_2}\nMODE?$"

	.align 2
	.4byte gUnknown_082EDFA8
	.4byte gUnknown_082EDFC4

	.align 2
	.string "Communicating…\nPlease wait.$"

	.align 2
gUnknown_082EE004:: @ 82EE004
	.string "Awaiting {STR_VAR_1}'s response about\nthe trade…$"

	.align 2
gUnknown_082EE02C:: @ 82EE02C
	.string "Communicating{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE098:: @ 82EE098
	.string "Communicating with {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE104:: @ 82EE104
	.string "Please wait a while{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.$"

	.align 2
gUnknown_082EE17C:: @ 82EE17C
	.4byte gUnknown_082EE02C
	.4byte gUnknown_082EE098
	.4byte gUnknown_082EE104

	.align 2
gUnknown_082EE188:: @ 82EE188
	.string "Hiya! Is there something that you\nwanted to do?$"

	.align 2
gUnknown_082EE1B8:: @ 82EE1B8
	.string "Hello!\nWould you like to do something?$"

	.align 2
gUnknown_082EE1E0:: @ 82EE1E0
	.string "{STR_VAR_1}: Hiya, we meet again!\nWhat are you up for this time?$"

	.align 2
gUnknown_082EE218:: @ 82EE218
	.string "{STR_VAR_1}: Oh! {PLAYER}, hello!\nWould you like to do something?$"

	.align 2
gUnknown_082EE24C:: @ 82EE24C
	.4byte gUnknown_082EE188
	.4byte gUnknown_082EE1B8
	.4byte gUnknown_082EE1E0
	.4byte gUnknown_082EE218

	.align 2
gUnknown_082EE25C:: @ 82EE25C
	.string "Want to do something?$"

	.align 2
gUnknown_082EE274:: @ 82EE274
	.string "Would you like to do something?$"

	.align 2
gUnknown_082EE294:: @ 82EE294
	.string "{STR_VAR_1}: What would you like to\ndo now?$"

	.align 2
	.string "{STR_VAR_1}: Want to do anything else?$"

	.align 2
	.4byte gUnknown_082EE25C
	.4byte gUnknown_082EE274
	.4byte gUnknown_082EE294
	.4byte gUnknown_082EE294

	.align 2
gUnknown_082EE2E8:: @ 82EE2E8
	.string "Somebody has contacted you.{PAUSE 60}$"

	.align 2
gUnknown_082EE308:: @ 82EE308
	.string "{STR_VAR_1} has contacted you.{PAUSE 60}$"

	.align 2
gUnknown_082EE324:: @ 82EE324
	.4byte gUnknown_082EE2E8
	.4byte gUnknown_082EE308

	.align 2
gUnknown_082EE32C:: @ 82EE32C
	.string "Awaiting a response from\nthe other TRAINER…$"

	.align 2
gUnknown_082EE358:: @ 82EE358
	.string "Awaiting a response from\n{STR_VAR_1}…$"

	.align 2
gUnknown_082EE378:: @ 82EE378
	.4byte gUnknown_082EE32C
	.4byte gUnknown_082EE358

	.align 2
gUnknown_082EE380:: @ 82EE380
	.string "The other TRAINER showed\nyou their TRAINER CARD.\pWould you like to show your\nTRAINER CARD?$"

	.align 2
gUnknown_082EE3DC:: @ 82EE3DC
	.string "The other TRAINER challenges you\nto battle.\pWill you accept the battle\nchallenge?$"

	.align 2
gUnknown_082EE430:: @ 82EE430
	.string "The other TRAINER invites you\nto chat.\pWill you accept the chat\ninvitation?$"

	.align 2
gUnknown_082EE47C:: @ 82EE47C
	.string "There is an offer to trade your\nregistered Lv. {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}\pin exchange for a\nLv. {SPECIAL_F7 0x02} {SPECIAL_F7 0x03}.\pWill you accept this trade\noffer?$"

	.align 2
gUnknown_082EE4F0:: @ 82EE4F0
	.string "There is an offer to trade your\nregistered EGG.\lWill you accept this trade offer?$"

	.align 2
gUnknown_082EE544:: @ 82EE544
	.string "The chat has been dropped.\p$"

	.align 2
gUnknown_082EE560:: @ 82EE560
	.string "You declined the offer.\p$"

	.align 2
gUnknown_082EE57C:: @ 82EE57C
	.string "You declined the offer.\p$"

	.align 2
gUnknown_082EE598:: @ 82EE598
	.string "The chat was ended.\p$"

	.align 2
	.4byte gUnknown_082EE380
	.4byte gUnknown_082EE3DC
	.4byte gUnknown_082EE430
	.4byte gUnknown_082EE47C

	.align 2
gUnknown_082EE5C0:: @ 82EE5C0
	.string "Oh, hey! We're in a chat right now.\nWant to join us?$"

	.align 2
gUnknown_082EE5F8:: @ 82EE5F8
	.string "{STR_VAR_1}: Hey, {PLAYER}!\nWe're having a chat right now.\lWant to join us?$"

	.align 2
gUnknown_082EE638:: @ 82EE638
	.string "Oh, hi! We're having a chat now.\nWould you like to join us?$"

	.align 2
gUnknown_082EE674:: @ 82EE674
	.string "{STR_VAR_1}: Oh, hi, {PLAYER}!\nWe're having a chat now.\lWould you like to join us?$"

	.align 2
gUnknown_082EE6B8:: @ 82EE6B8
	.4byte gUnknown_082EE5C0
	.4byte gUnknown_082EE638
	.4byte gUnknown_082EE5F8
	.4byte gUnknown_082EE674

	.align 2
gUnknown_082EE6C8:: @ 82EE6C8
	.string "……\nThe TRAINER appears to be busy…\p$"

	.align 2
gUnknown_082EE6EC:: @ 82EE6EC
	.string "A battle, huh?\nAll right, just give me some time.$"

	.align 2
gUnknown_082EE720:: @ 82EE720
	.string "You want to chat, huh?\nSure, just wait a little.$"

	.align 2
gUnknown_082EE754:: @ 82EE754
	.string "Sure thing! As my “Greetings,”\nhere's my TRAINER CARD.$"

	.align 2
gUnknown_082EE78C:: @ 82EE78C
	.string "A battle? Of course, but I need\ntime to get ready.$"

	.align 2
gUnknown_082EE7C0:: @ 82EE7C0
	.string "Did you want to chat?\nOkay, but please wait a moment.$"

	.align 2
gUnknown_082EE7F8:: @ 82EE7F8
	.string "As my introduction, I'll show you\nmy TRAINER CARD.$"

	.align 2
gUnknown_082EE82C:: @ 82EE82C
	.4byte gUnknown_082EE6EC
	.4byte gUnknown_082EE720
	.4byte NULL
	.4byte gUnknown_082EE754
	.4byte gUnknown_082EE78C
	.4byte gUnknown_082EE7C0
	.4byte NULL
	.4byte gUnknown_082EE7F8

	.align 2
	.string "You want to chat, huh?\nSure, just wait a little.$"

	.align 2
gUnknown_082EE880:: @ 82EE880
	.string "Thanks for waiting!\nLet's get our battle started!{PAUSE 60}$"

	.align 2
gUnknown_082EE8B8:: @ 82EE880
	.string "All right!\nLet's chat!{PAUSE 60}$"

	.align 2
gUnknown_082EE8D4:: @ 82EE8D4
	.string "Sorry I made you wait!\nLet's get started!{PAUSE 60}$"

	.align 2
gUnknown_082EE904:: @ 82EE904
	.string "Sorry I made you wait!\nLet's chat.{PAUSE 60}$"

	.align 2
gUnknown_082EE92C:: @ 82EE92C
	.string "The trade will be started.{PAUSE 60}$"

	.align 2
gUnknown_082EE94C:: @ 82EE94C
	.string "The battle will be started.{PAUSE 60}$"

	.align 2
gUnknown_082EE96C:: @ 82EE96C
	.string "Entering the chat…{PAUSE 60}$"

	.align 2
gUnknown_082EE984:: @ 82EE984
	.4byte gUnknown_082EE94C
	.4byte gUnknown_082EE96C
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE94C
	.4byte gUnknown_082EE96C
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE880
	.4byte gUnknown_082EE8B8
	.4byte gUnknown_082EE92C
	.4byte gUnknown_082EE8D4
	.4byte gUnknown_082EE904
	.4byte gUnknown_082EE92C

	.align 2
gUnknown_082EE9B4:: @ 82EE9B4
	.string "Sorry! My POKéMON don't seem to\nbe feeling too well right now.\lLet me battle you another time.\p$"

	.align 2
gUnknown_082EEA14:: @ 82EEA14
	.string "I'm terribly sorry, but my POKéMON\naren't feeling well…\pLet's battle another time.\p$"

	.align 2
gUnknown_082EEA68:: @ 82EEA68
	.4byte gUnknown_082EE9B4
	.4byte gUnknown_082EEA14

	.align 2
gUnknown_082EEA70:: @ 82EEA70
	.string "Huh? My TRAINER CARD…\nWhere'd it go now?\lSorry! I'll show you another time!\p$"

	.align 2
gUnknown_082EEAC0:: @ 82EEAC0
	.string "Oh? Now where did I put my\nTRAINER CARD?…\lSorry! I'll show you later!\p$"

	.align 2
gUnknown_082EEB08:: @ 82EEB08
	.4byte gUnknown_082EEA70
	.4byte gUnknown_082EEAC0

	.align 2
gUnknown_082EEB10:: @ 82EEB10
	.string "If you want to do something with\nme, just give me a shout!\p$"

	.align 2
gUnknown_082EEB4C:: @ 82EEB4C
	.string "If you want to do something with\nme, don't be shy.\p$"

	.align 2
gUnknown_082EEB80:: @ 82EEB80
	.4byte gUnknown_082EEB10
	.4byte gUnknown_082EEB4C

	.align 2
gUnknown_082EEB88:: @ 82EEB88
	.string "Whoops! Sorry, but I have to do\nsomething else.\lAnother time, okay?\p$"

	.align 2
gUnknown_082EEBD0:: @ 82EEBD0
	.string "If you want to battle, you need\ntwo POKéMON that are below\lLv. 30.\p$"

	.align 2
gUnknown_082EEC14:: @ 82EEC14
	.string "For a battle, you need two\nPOKéMON that are below Lv. 30.\p$"

	.align 2
gUnknown_082EEC50:: @ 82EEC50
	.string "Oh, all right.\nCome see me anytime, okay?\p$"

	.align 2
gUnknown_082EEC7C:: @ 82EEC7C
	.string "Oh…\nPlease come by anytime.\p$"

	.align 2
gUnknown_082EEC9C:: @ 82EEC9C
	.4byte gUnknown_082EEC50
	.4byte gUnknown_082EEC7C

	.align 2
gUnknown_082EECA4:: @ 82EECA4
	.string "Oh, sorry!\nI just can't right this instant.\lLet's chat another time.\p$"

	.align 2
gUnknown_082EECEC:: @ 82EECEC
	.string "Oh, I'm sorry.\nI have too much to do right now.\lLet's chat some other time.\p$"

	.align 2
gUnknown_082EED3C:: @ 82EED3C
	.4byte gUnknown_082EECA4
	.4byte gUnknown_082EECEC

	.align 2
gUnknown_082EED44:: @ 82EED3C
	.string "Whoa!\nI can tell you're pretty tough!\p$"

	.align 2
gUnknown_082EED6C:: @ 82EED6C
	.string "You used that move?\nThat's good strategy!\p$"

	.align 2
gUnknown_082EED98:: @ 82EED98
	.string "Way to go!\nThat was an eye-opener!\p$"

	.align 2
gUnknown_082EEDBC:: @ 82EEDBC
	.string "Oh! How could you use that\nPOKéMON in that situation?\p$"

	.align 2
gUnknown_082EEDF4:: @ 82EEDF4
	.string "That POKéMON…\nIt's been raised really well!\p$"

	.align 2
gUnknown_082EEE24:: @ 82EEE24
	.string "That's it!\nThis is the right move now!\p$"

	.align 2
gUnknown_082EEE4C:: @ 82EEE4C
	.string "That's awesome!\nYou can battle that way?\p$"

	.align 2
gUnknown_082EEE78:: @ 82EEE78
	.string "You have exquisite timing for\nswitching POKéMON!\p$"

	.align 2
gUnknown_082EEEAC:: @ 82EEEAC
	.4byte gUnknown_082EED44
	.4byte gUnknown_082EED6C
	.4byte gUnknown_082EED98
	.4byte gUnknown_082EEDBC
	.4byte gUnknown_082EEDF4
	.4byte gUnknown_082EEE24
	.4byte gUnknown_082EEE4C
	.4byte gUnknown_082EEE78

	.align 2
gUnknown_082EEECC:: @ 82EEECC
	.string "Oh, I see!\nThis is educational!\p$"

	.align 2
gUnknown_082EEEF0:: @ 82EEEF0
	.string "Don't say anything funny anymore!\nI'm sore from laughing!\p$"

	.align 2
gUnknown_082EEF2C:: @ 82EEF2C
	.string "Oh?\nSomething like that happened.\p$"

	.align 2
gUnknown_082EEF50:: @ 82EEF50
	.string "Hmhm… What?\nSo is this what you're saying?\p$"

	.align 2
gUnknown_082EEF7C:: @ 82EEF7C
	.string "Is that right?\nI didn't know that.\p$"

	.align 2
gUnknown_082EEFA0:: @ 82EEFA0
	.string "Ahaha!\nWhat is that about?\p$"

	.align 2
gUnknown_082EEFBC:: @ 82EEFBC
	.string "Yes, that's exactly it!\nThat's what I meant.\p$"

	.align 2
gUnknown_082EEFEC:: @ 82EEFEC
	.string "In other words…\nYes! That's right!\p$"

	.align 2
gUnknown_082EF010:: @ 82EF010
	.4byte gUnknown_082EEECC
	.4byte gUnknown_082EEEF0
	.4byte gUnknown_082EEF2C
	.4byte gUnknown_082EEF50
	.4byte gUnknown_082EEF7C
	.4byte gUnknown_082EEFA0
	.4byte gUnknown_082EEFBC
	.4byte gUnknown_082EEFEC

	.align 2
gUnknown_082EF030:: @ 82EF030
	.string "I'm just showing my TRAINER CARD\nas my way of greeting.\p$"

	.align 2
gUnknown_082EF06C:: @ 82EF06C
	.string "I hope I get to know you better!\p$"

	.align 2
gUnknown_082EF090:: @ 82EF010
	.string "We're showing each other our\nTRAINER CARDS to get acquainted.\p$"

	.align 2
gUnknown_082EF0D0:: @ 82EF0D0
	.string "Glad to meet you.\nPlease don't be a stranger!\p$"

	.align 2
gUnknown_082EF100:: @ 82EF100
	.4byte gUnknown_082EF030
	.4byte gUnknown_082EF06C
	.4byte gUnknown_082EF090
	.4byte gUnknown_082EF0D0

	.align 2
gUnknown_082EF110:: @ 82EF110
	.string "Yeahah!\nI really wanted this POKéMON!\p$"

	.align 2
gUnknown_082EF138:: @ 82EF138
	.string "Finally, a trade got me that\nPOKéMON I'd wanted a long time.\p$"

	.align 2
gUnknown_082EF178:: @ 82EF178
	.string "I'm trading POKéMON right now.\p$"

	.align 2
gUnknown_082EF198:: @ 82EF198
	.string "I finally got that POKéMON I\nwanted in a trade!\p$"

	.align 2
gUnknown_082EF1CC:: @ 82EF1CC
	.4byte gUnknown_082EF110
	.4byte gUnknown_082EF138
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EF178
	.4byte gUnknown_082EF198
	.4byte NULL
	.4byte NULL

	.align 2
gUnknown_082EF1EC:: @ 82EF1EC
	.string "{STR_VAR_1} checked the\nTRADING BOARD.\p$"

	.align 2
gUnknown_082EF20C:: @ 82EF20C
	.string "Welcome to the TRADING BOARD.\pYou may register your POKéMON\nand offer it up for a trade.\pWould you like to register one of\nyour POKéMON?$"

	.align 2
gUnknown_082EF298:: @ 82EF298
	.string "This TRADING BOARD is used for\noffering a POKéMON for a trade.\pAll you need to do is register a\nPOKéMON for a trade.\pAnother TRAINER may offer a party\nPOKéMON in return for the trade.\pWe hope you will register POKéMON\nand trade them with many, many\lother TRAINERS.\pWould you like to register one of\nyour POKéMON?$"

	.align 2
	.string "We have registered your POKéMON for\ntrade on the TRADING BOARD.\pThank you for using this service!\p$"

	.align 2
	.string "Nobody has registered any POKéMON\nfor trade on the TRADING BOARD.\p\n$"

	.align 2
gUnknown_082EF47C:: @ 82EF47C
	.string "Please choose the type of POKéMON\nthat you would like in the trade.\n$"

	.align 2
gUnknown_082EF4C4:: @ 82EF4C4
	.string "Which of your party POKéMON will\nyou offer in trade?\p$"

	.align 2
gUnknown_082EF4FC:: @ 82EF4FC
	.string "Registration has been canceled.\p$"

	.align 2
gUnknown_082EF520:: @ 82EF520
	.string "Registration has been completed.\p$"

	.align 2
gUnknown_082EF544:: @ 82EF544
	.string "The trade has been canceled.\p$"

	.align 2
gUnknown_082EF564:: @ 82EF564
	.string "Cancel the registration of your\nLv. {STR_VAR_2} {STR_VAR_1}?$"

	.align 2
gUnknown_082EF590:: @ 82EF590
	.string "Cancel the registration of your\nEGG?$"

	.align 2
gUnknown_082EF5B8:: @ 82EF5B8
	.string "The registration has been canceled.\p$"

	.align 2
	.string "TRAINERS wishing to make a trade\nwill be listed.$"

	.align 2
	.string "Please choose the TRAINER with whom\nyou would like to trade POKéMON.$"

	.align 2
gUnknown_082EF65C:: @ 82EF65C
	.string "Would you like to ask {STR_VAR_1} to\nmake a trade?$"

	.align 2
	.string "Awaiting a response from\nthe other TRAINER…$"

	.align 2
	.string "You have not registered a POKéMON\nfor trading.\p$"

	.align 2
gUnknown_082EF6E4:: @ 82EF6E4
	.string "You don't have a {STR_VAR_2}-type\nPOKéMON that {STR_VAR_1} wants.\p$"

	.align 2
gUnknown_082EF718:: @ 82EF718
	.string "You don't have an EGG that\n{STR_VAR_1} wants.\p$"

	.align 2
gUnknown_082EF740:: @ 82EF740
	.string "{STR_VAR_1} can't make a trade for\nyour POKéMON right now.\p$"

	.align 2
gUnknown_082EF774:: @ 82EF774
	.string "You can't make a trade for\n{STR_VAR_1}'s POKéMON right now.\p$"

	.align 2
	.4byte gUnknown_082EF740
	.4byte gUnknown_082EF774

	.align 2
gUnknown_082EF7B0:: @ 82EF7B0
	.string "Your trade offer was rejected.\p$"

	.align 2
gUnknown_082EF7D0:: @ 82EF7D0
	.string "EGG TRADE$"

	.align 2
gUnknown_082EF7DC:: @ 82EF7DC
	.string "{DPAD_UPDOWN}CHOOSE  {A_BUTTON}JOIN  {B_BUTTON}CANCEL$"

	.align 2
gUnknown_082EF7F8:: @ 82EF7F8
	.string "Please choose a TRAINER.$"

	.align 2
gUnknown_082EF814:: @ 82EF814
	.string "Please choose a TRAINER for\na SINGLE BATTLE.$"

	.align 2
gUnknown_082EF844:: @ 82EF844
	.string "Please choose a TRAINER for\na DOUBLE BATTLE.$"

	.align 2
gUnknown_082EF874:: @ 82EF874
	.string "Please choose the LEADER\nfor a MULTI BATTLE.$"

	.align 2
gUnknown_082EF8A4:: @ 82EF8A4
	.string "Please choose the TRAINER to\ntrade with.$"

	.align 2
gUnknown_082EF8D0:: @ 82EF8D0
	.string "Please choose the TRAINER who is\nsharing WONDER CARDS.$"

	.align 2
gUnknown_082EF908:: @ 82EF908
	.string "Please choose the TRAINER who is\nsharing WONDER NEWS.$"

	.align 2
gUnknown_082EF940:: @ 82EF940
	.string "Jump with mini POKéMON!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF974:: @ 82EF974
	.string "BERRY CRUSH!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF99C:: @ 82EF974
	.string "DODRIO BERRY-PICKING!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF9CC:: @ 82EF9CC
	.string "BERRY BLENDER!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EF9F8:: @ 82EF9F8
	.string "RECORD CORNER!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA24:: @ 82EFA24
	.string "COOLNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA50:: @ 82EFA50
	.string "BEAUTY CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFA7C:: @ 82EFA7C
	.string "CUTENESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFAA8:: @ 82EFAA8
	.string "SMARTNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFAD8:: @ 82EFAD8
	.string "TOUGHNESS CONTEST!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB08:: @ 82EFB08
	.string "BATTLE TOWER LEVEL 50!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB3C:: @ 82EFB3C
	.string "BATTLE TOWER OPEN LEVEL!\nPlease choose the LEADER.$"

	.align 2
gUnknown_082EFB70:: @ 82EFB70
	.4byte gUnknown_082EF814
	.4byte gUnknown_082EF844
	.4byte gUnknown_082EF874
	.4byte gUnknown_082EF8A4
	.4byte gUnknown_082EF940
	.4byte gUnknown_082EF974
	.4byte gUnknown_082EF99C
	.4byte gUnknown_082EF8D0
	.4byte gUnknown_082EF908
	.4byte NULL
	.4byte NULL
	.4byte NULL
	.4byte gUnknown_082EF9F8
	.4byte gUnknown_082EF9CC
	.4byte NULL
	.4byte gUnknown_082EFA24
	.4byte gUnknown_082EFA50
	.4byte gUnknown_082EFA7C
	.4byte gUnknown_082EFAA8
	.4byte gUnknown_082EFAD8
	.4byte gUnknown_082EFB08
	.4byte gUnknown_082EFB3C

	.align 2
gUnknown_082EFBC8:: @ 82EFBC8
	.string "Searching for a WIRELESS\nCOMMUNICATION SYSTEM. Wait...$"

	.align 2
	.string "For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p$"

	.align 2
gUnknown_082EFC3C:: @ 82EFC3C
	.string "Awaiting {STR_VAR_1}'s response…$"

	.align 2
gUnknown_082EFC54:: @ 82EFC54
	.string "{STR_VAR_1} has been asked to register\nyou as a member. Please wait.$"

	.align 2
gUnknown_082EFC90:: @ 82EFC90
	.string "Awaiting a response from the\nWIRELESS COMMUNICATION SYSTEM.$"

	.align 2
	.string "Please wait for other TRAINERS to\ngather and get ready.$"

	.align 2
gUnknown_082EFD04:: @ 82EFD04
	.string "No CARDS appear to be shared \nright now.$"

	.align 2
gUnknown_082EFD30:: @ 82EFD30
	.string "No NEWS appears to be shared\nright now.$"

	.align 2
gUnknown_082EFD58:: @ 82EFD58
	.4byte gUnknown_082EFD04
	.4byte gUnknown_082EFD30

	.align 2
gUnknown_082EFD60:: @ 82EFD60
	.string "BATTLE$"

	.align 2
gUnknown_082EFD68:: @ 82EFD68
	.string "CHAT$"

	.align 2
gUnknown_082EFD70:: @ 82EFD70
	.string "GREETINGS$"

	.align 2
gUnknown_082EFD7C:: @ 82EFD7C
	.string "EXIT$"

	.align 2
gUnknown_082EFD84:: @ 82EFD84
	.string "EXIT$"

	.align 2
gUnknown_082EFD8C:: @ 82EFD8C
	.string "INFO$"

	.align 2
gUnknown_082EFD94:: @ 82EFD94
	.string "NAME{CLEAR_TO 0x3C}WANTED{CLEAR_TO 0x6E}OFFER{CLEAR_TO 0xC6}LV.$"

	.align 2
gUnknown_082EFDB0:: @ 82EFDB0
	.string "SINGLE BATTLE$"

	.align 2
gUnknown_082EFDC0:: @ 82EFDC0
	.string "DOUBLE BATTLE$"

	.align 2
gUnknown_082EFDD0:: @ 82EFDD0
	.string "MULTI BATTLE$"

	.align 2
gUnknown_082EFDE0:: @ 82EFDE0
	.string "POKéMON TRADES$"

	.align 2
gUnknown_082EFDF0:: @ 82EFDF0
	.string "CHAT$"

	.align 2
gUnknown_082EFDF8:: @ 82EFDF8
	.string "CARDS$"

	.align 2
gUnknown_082EFE00:: @ 82EFE00
	.string "WONDER CARDS$"

	.align 2
gUnknown_082EFE10:: @ 82EFE10
	.string "WONDER NEWS$"

	.align 2
gUnknown_082EFE1C:: @ 82EFE1C
	.string "POKéMON JUMP$"

	.align 2
gUnknown_082EFE2C:: @ 82EFE2C
	.string "BERRY CRUSH$"

	.align 2
gUnknown_082EFE38:: @ 82EFE38
	.string "BERRY-PICKING$"

	.align 2
gUnknown_082EFE48:: @ 82EFE48
	.string "SEARCH$"

	.align 2
gUnknown_082EFE50:: @ 82EFE50
	.string "BERRY BLENDER$"

	.align 2
gUnknown_082EFE60:: @ 82EFE60
	.string "RECORD CORNER$"

	.align 2
gUnknown_082EFE70:: @ 82EFE70
	.string "COOL CONTEST$"

	.align 2
gUnknown_082EFE80:: @ 82EFE80
	.string "BEAUTY CONTEST$"

	.align 2
gUnknown_082EFE90:: @ 82EFE90
	.string "CUTE CONTEST$"

	.align 2
gUnknown_082EFEA0:: @ 82EFEA0
	.string "SMART CONTEST$"

	.align 2
gUnknown_082EFEB0:: @ 82EFEB0
	.string "TOUGH CONTEST$"

	.align 2
gUnknown_082EFEC0:: @ 82EFEC0
	.string "BATTLE TOWER LV. 50$"

	.align 2
gUnknown_082EFED4:: @ 82EFED4
	.string "BATTLE TOWER OPEN LEVEL$"

	.align 2
gUnknown_082EFEEC:: @ 82EFEEC
	.string "It's a NORMAL CARD.$"

	.align 2
gUnknown_082EFF00:: @ 82EFF00
	.string "It's a BRONZE CARD!$"

	.align 2
gUnknown_082EFF14:: @ 82EFF14
	.string "It's a COPPER CARD!$"

	.align 2
gUnknown_082EFF28:: @ 82EFF28
	.string "It's a SILVER CARD!$"

	.align 2
gUnknown_082EFF3C:: @ 82EFF3C
	.string "It's a GOLD CARD!$"

	.align 2
gUnknown_082EFF50:: @ 82EFF50
	.4byte gUnknown_082EFEEC
	.4byte gUnknown_082EFF00
	.4byte gUnknown_082EFF14
	.4byte gUnknown_082EFF28
	.4byte gUnknown_082EFF3C

gUnknown_082EFF64:: @ 82EFF64
	.string "This is {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}'s\nTRAINER CARD…\l{SPECIAL_F7 0x02}\pPOKéDEX: {SPECIAL_F7 0x03}\nTIME:    {SPECIAL_F7 0x04}:{SPECIAL_F7 0x05}\p$"

	.align 2
gUnknown_082EFFA4:: @ 82EFFA4
	.string "BATTLES: WINS: {SPECIAL_F7 0x00}  LOSSES: {SPECIAL_F7 0x02}\nTRADES: {SPECIAL_F7 0x03}\p“{SPECIAL_F7 0x04} {SPECIAL_F7 0x05}\n{SPECIAL_F7 0x06} {SPECIAL_F7 0x07}”\p$"

	.align 2
gUnknown_082EFFDC:: @ 82EFFDC
	.string "{SPECIAL_F7 0x01}: Glad to have met you!{PAUSE 60}$"

	.align 2
gUnknown_082EFFFC:: @ 82EFFFC
	.string "{SPECIAL_F7 0x01}: Glad to meet you!{PAUSE 60}$"

	.align 2
gUnknown_082F0018:: @ 82F0018
	.4byte gUnknown_082EFFDC
	.4byte gUnknown_082EFFFC

	.align 2
gUnknown_082F0020:: @ 82F0020
	.string "Finished checking {SPECIAL_F7 0x01}'s\nTRAINER CARD.{PAUSE 60}$"

	.align 2
gUnknown_082F0048:: @ 82F0048
	.4byte gText_EmptyString
	.4byte gUnknown_082EFDB0
	.4byte gUnknown_082EFDC0
	.4byte gUnknown_082EFDD0
	.4byte gUnknown_082EFDE0
	.4byte gUnknown_082EFDF0
	.4byte gUnknown_082EFE00
	.4byte gUnknown_082EFE10
	.4byte gUnknown_082EFDF8
	.4byte gUnknown_082EFE1C
	.4byte gUnknown_082EFE2C
	.4byte gUnknown_082EFE38
	.4byte gUnknown_082EFE48
	.4byte gText_EmptyString
	.4byte gUnknown_082EFED4
	.4byte gUnknown_082EFE60
	.4byte gUnknown_082EFE50
	.4byte gText_EmptyString
	.4byte gText_EmptyString
	.4byte gText_EmptyString
	.4byte gText_EmptyString
	.4byte gUnknown_082EFE00
	.4byte gUnknown_082EFE10
	.4byte gUnknown_082EFE70
	.4byte gUnknown_082EFE80
	.4byte gUnknown_082EFE90
	.4byte gUnknown_082EFEA0
	.4byte gUnknown_082EFEB0
	.4byte gUnknown_082EFEC0

	.align 2
gUnknown_082F00BC:: @ 82F00BC
	window_template 0x00, 0x00, 0x00, 0x1E, 0x02, 0x0F, 0x0008

	.align 2
gUnknown_082F00C4:: @ 82F00C4
	.byte 0x01, 0x02, 0x00, 0x00
	.byte 0x02, 0x02, 0x00, 0x00
	.byte 0x03, 0x04, 0x00, 0x00
	.byte 0x04, 0x02, 0x00, 0x00
	.byte 0x09, 0x25, 0x00, 0x00
	.byte 0x0a, 0x25, 0x00, 0x00
	.byte 0x0b, 0x35, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x0f, 0x24, 0x00, 0x00
	.byte 0x10, 0x24, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00
	.byte 0x17, 0x24, 0x00, 0x00
	.byte 0x18, 0x24, 0x00, 0x00
	.byte 0x19, 0x24, 0x00, 0x00
	.byte 0x1a, 0x24, 0x00, 0x00
	.byte 0x1b, 0x24, 0x00, 0x00
	.byte 0x1c, 0x02, 0x00, 0x00
	.byte 0x0e, 0x02, 0x00, 0x00

	.align 2
gUnknown_082F011C:: @ 82F011C
	window_template 0x00, 0x01, 0x03, 0x0d, 0x08, 0x0f, 0x0044

	.align 2
gUnknown_082F0124:: @ 82F0124
	window_template 0x00, 0x01, 0x03, 0x0d, 0x0a, 0x0f, 0x0044

	.align 2
gUnknown_082F012C:: @ 82F012C
	window_template 0x00, 0x10, 0x03, 0x07, 0x04, 0x0f, 0x00c6

	.align 2
gUnknown_082F0134:: @ 82F0134
	.4byte gText_EmptyString
	.4byte 0x00000000
	.4byte gText_EmptyString
	.4byte 0x00000001
	.4byte gText_EmptyString
	.4byte 0x00000002
	.4byte gText_EmptyString
	.4byte 0x00000003
	.4byte gText_EmptyString
	.4byte 0x00000004

	.align 2
gUnknown_082F015C:: @ 82F015C struct ListMenuTemplate
	.4byte gUnknown_082F0134
	.4byte NULL
	.4byte sub_8013278
	.byte 0x05, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x21, 0x31, 0x00, 0x41

	.align 2
gUnknown_082F0174:: @ 82F0174
	window_template 0x00, 0x01, 0x03, 0x11, 0x0a, 0x0f, 0x0044

	.align 2
gUnknown_082F017C:: @ 82F017C
	window_template 0x00, 0x14, 0x03, 0x07, 0x04, 0x0f, 0x00ee

	.align 2
gUnknown_082F0184:: @ 82F0184
	.4byte gText_EmptyString, 0x00000000
	.4byte gText_EmptyString, 0x00000001
	.4byte gText_EmptyString, 0x00000002
	.4byte gText_EmptyString, 0x00000003
	.4byte gText_EmptyString, 0x00000004
	.4byte gText_EmptyString, 0x00000005
	.4byte gText_EmptyString, 0x00000006
	.4byte gText_EmptyString, 0x00000007
	.4byte gText_EmptyString, 0x00000008
	.4byte gText_EmptyString, 0x00000009
	.4byte gText_EmptyString, 0x0000000a
	.4byte gText_EmptyString, 0x0000000b
	.4byte gText_EmptyString, 0x0000000c
	.4byte gText_EmptyString, 0x0000000d
	.4byte gText_EmptyString, 0x0000000e
	.4byte gText_EmptyString, 0x0000000f

	.align 2
gUnknown_082F0204:: @ 82F0204 struct ListMenuTemplate
	.4byte gUnknown_082F0184
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte sub_8013DF4
	.byte 0x10, 0x00, 0x05, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x40, 0x01

	.align 2
gUnknown_082F021C:: @ 82F021C
	window_template 0x00, 0x14, 0x05, 0x10, 0x08, 0x0f, 0x0001

	.align 2
gUnknown_082F0224:: @ 82F0224
	.4byte gUnknown_082EFD70, 0x00000208
	.4byte gUnknown_082EFD60, 0x00000241
	.4byte gUnknown_082EFD68, 0x00000245
	.4byte gUnknown_082EFD7C, 0x00000040

	.align 2
gUnknown_082F0244:: @ 82F0244 struct ListMenuTemplate
	.4byte gUnknown_082F0224
	.byte 0x79, 0xf0, 0x1a, 0x08
	.4byte NULL
	.byte 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F025C:: @ 82F025C
	window_template 0x00, 0x12, 0x07, 0x10, 0x06, 0x0f, 0x0001

gUnknown_082F0264:: @ 82F0264
	.4byte gText_Register, 0x00000001
	.4byte gUnknown_082EFD8C, 0x00000002
	.4byte gUnknown_082EFD7C, 0x00000003

	.align 2
gUnknown_082F027C:: @ 82F027C
	.4byte gUnknown_082F0264
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0294:: @ 82F0294
	window_template 0x00, 0x14, 0x01, 0x10, 0x0c, 0x0f, 0x0001

	.align 2
gUnknown_082F029C:: @ 82F029C
	.4byte gTypeNames, 0x00000000 @ NORMAL
	.4byte gTypeNames+0x46, 0x0000000a @ FIRE
	.4byte gTypeNames+0x4D, 0x0000000b @ WATER
	.4byte gTypeNames+0x5B, 0x0000000d @ ELECTR
	.4byte gTypeNames+0x54, 0x0000000c @ GRASS
	.4byte gTypeNames+0x69, 0x0000000f @ ICE
	.4byte gTypeNames+0x1C, 0x00000004 @ GROUND
	.4byte gTypeNames+0x23, 0x00000005 @ ROCK
	.4byte gTypeNames+0x0E, 0x00000002 @ FLYING
	.4byte gTypeNames+0x62, 0x0000000e @ PSYCHC
	.4byte gTypeNames+0x07, 0x00000001 @ FIGHT
	.4byte gTypeNames+0x15, 0x00000003 @ POISON
	.4byte gTypeNames+0x2A, 0x00000006 @ BUG
	.4byte gTypeNames+0x31, 0x00000007 @ GHOST
	.4byte gTypeNames+0x70, 0x00000010 @ DRAGON
	.4byte gTypeNames+0x38, 0x00000008 @ STEEL
	.4byte gTypeNames+0x77, 0x00000011 @ DARK
	.4byte gUnknown_082EFD7C, 0x00000012 @ EXIT

	.align 2
gUnknown_082F032C:: @ 82F032C
	.4byte gUnknown_082F029C
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x12, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0344:: @ 82F0344
	window_template 0x00, 0x01, 0x01, 0x1c, 0x02, 0x0d, 0x0001

	.align 2
gUnknown_082F034C:: @ 82F034C
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0c, 0x0d, 0x0039

	.align 2
gUnknown_082F0354:: @ 82F0354
	.4byte gText_EmptyString, 0xfffffffd
	.4byte gText_EmptyString, 0x00000000
	.4byte gText_EmptyString, 0x00000001
	.4byte gText_EmptyString, 0x00000002
	.4byte gText_EmptyString, 0x00000003
	.4byte gText_EmptyString, 0x00000004
	.4byte gText_EmptyString, 0x00000005
	.4byte gText_EmptyString, 0x00000006
	.4byte gText_EmptyString, 0x00000007
	.4byte gUnknown_082EFD84, 0x00000008

	.align 2
gUnknown_082F03A4:: @ 82F03A4
	.4byte gUnknown_082F0354
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte sub_8017BE8
	.byte 0x0a, 0x00, 0x06, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0xe1, 0xdf, 0x00, 0x01

	.align 2
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0c, 0x0d, 0x0039

	.align 2
gUnknown_082F03C4:: @ 82F03C4
	.4byte gText_EmptyString, 0x00000000
	.4byte gText_EmptyString, 0x00000001
	.4byte gText_EmptyString, 0x00000002
	.4byte gText_EmptyString, 0x00000003
	.4byte gText_EmptyString, 0x00000004
	.4byte gText_EmptyString, 0x00000005
	.4byte gText_EmptyString, 0x00000006
	.4byte gText_EmptyString, 0x00000007
	.4byte gText_EmptyString, 0x00000008
	.4byte gText_EmptyString, 0x00000009
	.4byte gText_EmptyString, 0x0000000a
	.4byte gText_EmptyString, 0x0000000b
	.4byte gText_EmptyString, 0x0000000c
	.4byte gText_EmptyString, 0x0000000d
	.4byte gText_EmptyString, 0x0000000e
	.4byte gText_EmptyString, 0x0000000f

	.align 2
	.4byte gUnknown_082F03C4
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte nullsub_14
	.byte 0x10, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x40, 0x01

	.align 2
gUnknown_082F045C:: @ 82F045C
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F0474:: @ 82F0474
	.byte 0x01, 0xff

	.align 2
gUnknown_082F0478:: @ 82F0478
	.byte 0x02, 0xff

	.align 2
gUnknown_082F047C:: @ 82F047C
	.byte 0x03, 0xff

	.align 2
gUnknown_082F0480:: @ 82F0480
	.byte 0x04, 0xff

	.align 2
gUnknown_082F0484:: @ 82F0484
	.byte 0x09, 0xff

	.align 2
gUnknown_082F0488:: @ 82F0488
	.byte 0x0a, 0xff

	.align 2
gUnknown_082F048C:: @ 82F048C
	.byte 0x0b, 0xff

	.align 2
gUnknown_082F0490:: @ 82F0490
	.byte 0x15, 0xff

	.align 2
gUnknown_082F0494:: @ 82F0494
	.byte 0x16, 0xff

	.align 2
gUnknown_082F0498:: @ 82F0498
	.byte 0x40, 0x41, 0x44, 0x45, 0x48, 0x51, 0x52, 0x53, 0x54, 0xff

	.align 2
gUnknown_082F04A4:: @ 82F04A4
	.byte 0x0c, 0xff

	.align 2
gUnknown_082F04A8:: @ 82F04A8
	.byte 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x15, 0x16, 0x0d, 0xff

	.align 2
gUnknown_082F04B4:: @ 82F04B4
	.byte 0x0f, 0xff

	.align 2
gUnknown_082F04B8:: @ 82F04B8
	.byte 0x10, 0xff

	.align 2
gUnknown_082F04BC:: @ 82F04BC
	.byte 0x17, 0xff

	.align 2
gUnknown_082F04C0:: @ 82F04C0
	.byte 0x18, 0xff

	.align 2
gUnknown_082F04C4:: @ 82F04C4
	.byte 0x19, 0xff

	.align 2
gUnknown_082F04C8:: @ 82F04C8
	.byte 0x1a, 0xff

	.align 2
gUnknown_082F04CC:: @ 82F04CC
	.byte 0x1b, 0xff

	.align 2
gUnknown_082F04D0:: @ 82F04D0
	.byte 0x1c, 0xff

	.align 2
gUnknown_082F04D4:: @ 82F04D4
	.byte 0x0e, 0xff

	.align 2
gUnknown_082F04D8:: @ 82F04D8
	.4byte gUnknown_082F0474
	.4byte gUnknown_082F0478
	.4byte gUnknown_082F047C
	.4byte gUnknown_082F0480
	.4byte gUnknown_082F0484
	.4byte gUnknown_082F0488
	.4byte gUnknown_082F048C
	.4byte gUnknown_082F0490
	.4byte gUnknown_082F0494
	.4byte gUnknown_082F0498
	.4byte gUnknown_082F04A4
	.4byte gUnknown_082F04A8
	.4byte gUnknown_082F04B4
	.4byte gUnknown_082F04B8
	.4byte NULL
	.4byte gUnknown_082F04BC
	.4byte gUnknown_082F04C0
	.4byte gUnknown_082F04C4
	.4byte gUnknown_082F04C8
	.4byte gUnknown_082F04CC
	.4byte gUnknown_082F04D0
	.4byte gUnknown_082F04D4

	.align 2
gUnknown_082F0530:: @ 82F0530
	.byte 0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x15
	.byte 0x16, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x00, 0x17
	.byte 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x0e, 0x00, 0x00

	.align 2
gUnkTextboxBorderPal:: @ 82F0548
	.incbin "graphics/interface/unk_textbox_border.gbapal"

	.align 2
gUnkTextboxBorderGfx:: @ 82F0568
	.incbin "graphics/interface/unk_textbox_border.4bpp.lz"

	.align 2
gUnknown_082F0598:: @ 82F0598 struct BgTemplate
	.4byte 0x000000f8
	.4byte 0x000010e1
	.4byte 0x000020d2
	.4byte 0x000030c3

	.align 2
gUnknown_082F05A8:: @ 82F05A8
	window_template 0x00, 0x00, 0x00, 0x1e, 0x02, 0x0c, 0x0013
	window_template 0x00, 0x01, 0x0f, 0x1c, 0x04, 0x0c, 0x004f
	window_template 0x00, 0x00, 0x0f, 0x1e, 0x05, 0x0d, 0x004f
	null_window_template

	.align 2
gUnknown_082F05C8:: @ 82F05C8
	window_template 0x00, 0x01, 0x0f, 0x1c, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05D0:: @ 82F05D0
	window_template 0x00, 0x01, 0x0f, 0x14, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05D8:: @ 82F05D8
	window_template 0x00, 0x01, 0x0f, 0x13, 0x04, 0x0c, 0x00e5

	.align 2
gUnknown_082F05E0:: @ 82F05E0
	window_template 0x00, 0x08, 0x06, 0x0e, 0x06, 0x0c, 0x0155

	.align 2
gUnknown_082F05E8:: @ 82F05E8
	window_template 0x00, 0x17, 0x0f, 0x06, 0x04, 0x0c, 0x0155

	.align 2
gUnknown_082F05F0:: @ 82F05F0
	window_template 0x00, 0x16, 0x0b, 0x07, 0x08, 0x0c, 0x0155

	.align 2
gUnknown_082F05F8:: @ 82F05F8
	window_template 0x00, 0x16, 0x0d, 0x07, 0x06, 0x0c, 0x0155

	.align 2
gUnknown_082F0600:: @ 82F0600
	window_template 0x00, 0x16, 0x0f, 0x07, 0x04, 0x0c, 0x0155

	.align 2
gUnknown_082F0608:: @ 82F0608
	.4byte gText_WonderCards, 0x00000000
	.4byte gText_WonderNews, 0x00000001
	.4byte gText_Exit3, 0xfffffffe

	.align 2
gUnknown_082F0620:: @ 82F0620
	.4byte gText_WirelessCommunication, 0x00000000
	.4byte gText_Friend2, 0x00000001
	.4byte gText_Cancel2, 0xfffffffe

	.align 2
gUnknown_082F0638:: @ 82F0638 struct ListMenuTemplate
	.4byte NULL
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F0650:: @ 82F0650
	.4byte gText_Receive, 0x00000000
	.4byte gText_Send, 0x00000001
	.4byte gText_Toss, 0x00000002
	.4byte gText_Cancel2, 0xfffffffe

	.align 2
gUnknown_082F0670:: @ 82F0670
	.4byte gText_Receive, 0x00000000
	.4byte gText_Toss, 0x00000002
	.4byte gText_Cancel2, 0xfffffffe

	.align 2
gUnknown_082F0688:: @ 82F0688
	.4byte gText_Receive, 0x00000000
	.4byte gText_Send, 0x00000001
	.4byte gText_Cancel2, 0xfffffffe

	.align 2
gUnknown_082F06A0:: @ 82F06A0
	.4byte gText_Receive, 0x00000000
	.4byte gText_Cancel2, 0xfffffffe

	.align 2
gUnknown_082F06B0:: @ 82F06B0 struct ListMenuTemplate
	.4byte gUnknown_082F0650
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06C8:: @ 82F06C8
	.4byte gUnknown_082F0670
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06E0:: @ 82F06E0
	.4byte gUnknown_082F0688
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
gUnknown_082F06F8:: @ 82F06F8
	.4byte gUnknown_082F06A0
	.4byte ListMenuDefaultCursorMoveFunc
	.4byte NULL
	.byte 0x02, 0x00, 0x02, 0x00, 0x00, 0x00, 0x08, 0x00
	.byte 0x21, 0x31, 0x00, 0x01

	.align 2
	.4byte gText_VarietyOfEventsImportedWireless
	.4byte gText_WonderCardsInPossession
	.4byte gText_ReadNewsThatArrived
	.4byte gText_ReturnToTitle

	.align 2
gUnknown_082F0720:: @ 82F0720
	.byte 0x00, 0x01, 0x02

	.align 2
	.byte 0x00, 0x01, 0x02

	.align 2
gUnknown_082F0728:: @ 82F0728
	.byte 0x01, 0x02, 0x03

	.align 2
gUnknown_082F072C:: @ 82F072C
	.byte 0x21, 0x2c, 0x1f, 0x23, 0x25, 0x24, 0x41, 0x42
	.byte 0x00, 0x00, 0x22, 0x28, 0x20, 0x2f, 0x2f, 0x0e
	.byte 0x14, 0x2d, 0x00, 0x00

	.align 2
gUnknown_082F0740:: @ 82F0740
	.2byte 0x0004, 0x0006, 0x000d, 0x0008
	.2byte 0x000a, 0x0006, 0x0001, 0x0008
	.2byte 0x000d, 0x0004, 0x0007, 0x0004
	.2byte 0x0001, 0x0004, 0x0007, 0x0008

	.align 2
gUnknown_082F0760:: @ 82F0760
	.byte 0x00, 0x00, 0x01, 0x00, 0x00, 0xff, 0xff, 0x00
	.byte 0x00, 0x01

gUnknown_082F076A:: @ 82F076A
	.byte 0x00, 0x02, 0x01, 0x04, 0x03

gUnknown_082F076F:: @ 82F076F
	.byte 0x01, 0x03, 0x01, 0x04, 0x02

gUnknown_082F0774:: @ 82F0774
	.byte 0x09, 0x08, 0x07, 0x02, 0x06, 0x05, 0x04, 0x03
	.byte 0xbf, 0x02, 0xc0, 0x02, 0xc1, 0x02, 0xc2, 0x02
	.byte 0xc3, 0x02, 0xc4, 0x02, 0xc5, 0x02, 0xc6, 0x02

gUnknown_082F078C:: @ 82F078C
	.byte 0x9c, 0xfe

gUnknown_082F078E:: @ 82F078E
	.byte 0x9d, 0xfe

	.align 2
gWirelessInfoScreenPal:: @ 82F0790
	.incbin "graphics/interface/wireless_info_screen.gbapal"

	.align 2
gWirelessInfoScreenGfx:: @ 82F0990
	.incbin "graphics/interface/wireless_info_screen.4bpp.lz"

	.align 2
gWirelessInfoScreenTilemap:: @ 82F0BA0
	.incbin "graphics/interface/wireless_info_screen.bin.lz"

	.align 2
gUnknown_082F0D34:: @ 82F0D34
	.4byte 0x000001f8
    .4byte 0x00001081

	.align 2
gUnknown_082F0D3C:: @ 82F0D3C
	window_template 0x00, 0x03, 0x00, 0x18, 0x03, 0x0f, 0x0001
	window_template 0x00, 0x03, 0x04, 0x15, 0x0f, 0x0f, 0x0049
	window_template 0x00, 0x18, 0x04, 0x03, 0x0f, 0x0f, 0x0184
	null_window_template

	.align 2
gUnknown_082F0D5C:: @ 82F0D5C
	.4byte gText_WirelessCommStatus
	.4byte gText_PeopleTrading
	.4byte gText_PeopleBattling
	.4byte gText_PeopleInUnionRoom
	.4byte gText_PeopleCommunicating

	.align 2
gUnknown_082F0D70:: @ 82F0D70
	.byte 0x01, 0x01, 0x02, 0x02, 0x01, 0x02, 0x03, 0x01
	.byte 0x04, 0x04, 0x00, 0x02, 0x06, 0x03, 0x02, 0x07
	.byte 0x03, 0x02, 0x09, 0x03, 0x00, 0x0a, 0x03, 0x00
	.byte 0x0b, 0x03, 0x00, 0x0c, 0xff, 0x00, 0x0d, 0x00
	.byte 0x00, 0x10, 0x03, 0x00, 0x0f, 0x03, 0x00, 0x40
	.byte 0x02, 0x01, 0x41, 0x02, 0x02, 0x44, 0x02, 0x02
	.byte 0x45, 0x02, 0x00, 0x48, 0x02, 0x02, 0x54, 0x02
	.byte 0x01, 0x53, 0x02, 0x02, 0x51, 0x02, 0x01, 0x52
	.byte 0x02, 0x01, 0x15, 0x03, 0x02, 0x16, 0x03, 0x02
	.byte 0x17, 0x03, 0x00, 0x18, 0x03, 0x00, 0x19, 0x03
	.byte 0x00, 0x1a, 0x03, 0x00, 0x1b, 0x03, 0x00, 0x1c
	.byte 0x01, 0x02, 0x0e, 0x01, 0x02, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F0DD0:: @ 82F0DD0
	.4byte 0x000001FC

	.align 2
gUnknown_082F0DD4:: @ 82F0DD4
	window_template 0x00, 0x03, 0x0f, 0x18, 0x04, 0x0e, 0x0014
	null_window_template

	.align 2
gUnknown_082F0DE4:: @ 82F0DE4
	.byte 0x01, 0x02, 0x03
