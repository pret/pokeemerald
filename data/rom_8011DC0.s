@ the second big chunk of data

#include "constants/species.h"
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

	.align 2
gUnknown_082F0DE8:: @ 82F0DE8
	.2byte 0x013a, 0x013b, 0x013c, 0x013d, 0x013e, 0x013f, 0x0140, 0x0141
	.2byte 0x0142, 0x0143, 0x0144, 0x0145, 0x0146, 0x0147, 0x0148, 0x0149
	.2byte 0x014a, 0x014b, 0x014c, 0x014d

	.align 2
gUnknown_082F0E10:: @ 82F0E10
	.byte 0x00, 0x02, 0x03
	.byte 0x00, 0x01, 0x02

	.align 2
gUnknown_082F0E18:: @ 82F0E18
	.byte 0x07, 0x04, 0x07, 0x00

	.align 2
gUnknown_082F0E1C:: @ 82F0E1C
	window_template 0x01, 0x01, 0x01, 0x19, 0x04, 0x02, 0x029C
	window_template 0x01, 0x01, 0x06, 0x1C, 0x08, 0x02, 0x01BC
	window_template 0x01, 0x01, 0x0E, 0x1C, 0x05, 0x02, 0x0130

	.align 2
gWonderCardBgPal1:: @ 82F0E34
	.incbin "graphics/wonder_transfers/wonder_card_1.gbapal"

	.align 2
gWonderCardBgPal2:: @ 82F0E54
	.incbin "graphics/wonder_transfers/wonder_card_2.gbapal"

	.align 2
gWonderCardBgPal3:: @ 82F0E74
	.incbin "graphics/wonder_transfers/wonder_card_3.gbapal"

	.align 2
gWonderCardBgPal4:: @ 82F0E94
	.incbin "graphics/wonder_transfers/wonder_card_4.gbapal"

	.align 2
gWonderCardBgPal5:: @ 82F0EB4
	.incbin "graphics/wonder_transfers/wonder_card_5.gbapal"

	.align 2
gWonderCardBgPal6:: @ 82F0ED4
	.incbin "graphics/wonder_transfers/wonder_card_6.gbapal"

	.align 2
gWonderCardBgPal7:: @ 82F0EF4
	.incbin "graphics/wonder_transfers/wonder_card_7.gbapal"

	.align 2
gWonderCardBgPal8:: @ 82F0F14
	.incbin "graphics/wonder_transfers/wonder_card_8.gbapal"

	.align 2
gWonderCardBgGfx1:: @ 82F0F34
	.incbin "graphics/wonder_transfers/wonder_card_1.4bpp.lz"

	.align 2
gWonderCardBgTilemap1:: @ 82F1030
	.incbin "graphics/wonder_transfers/wonder_card_1.bin.lz"

	.align 2
gWonderCardBgGfx2:: @ 82F1124
	.incbin "graphics/wonder_transfers/wonder_card_2.4bpp.lz"

	.align 2
gWonderCardBgTilemap2:: @ 82F1218
	.incbin "graphics/wonder_transfers/wonder_card_2.bin.lz"

	.align 2
gWonderCardBgGfx3:: @ 82F1300
	.incbin "graphics/wonder_transfers/wonder_card_3.4bpp.lz"

	.align 2
gWonderCardBgTilemap3:: @ 82F13D4
	.incbin "graphics/wonder_transfers/wonder_card_3.bin.lz"

	.align 2
gWonderCardBgGfx7:: @ 82F14A8
	.incbin "graphics/wonder_transfers/wonder_card_7.4bpp.lz"

	.align 2
gWonderCardBgTilemap7:: @ 82F16DC
	.incbin "graphics/wonder_transfers/wonder_card_7.bin.lz"

	.align 2
gWonderCardBgGfx8:: @ 82F1824
	.incbin "graphics/wonder_transfers/wonder_card_8.4bpp.lz"

	.align 2
gWonderCardBgTilemap8:: @ 82F1A54
	.incbin "graphics/wonder_transfers/wonder_card_8.bin.lz"

	.align 2
gWonderCardShadowPal1:: @ 82F1B9C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_1.gbapal"

	.align 2
gWonderCardShadowPal2:: @ 82F1BBC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_2.gbapal"

	.align 2
gWonderCardShadowPal3:: @ 82F1BDC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_3.gbapal"

	.align 2
gWonderCardShadowPal4:: @ 82F1BFC
	.incbin "graphics/wonder_transfers/wonder_card_shadow_4.gbapal"

	.align 2
gWonderCardShadowPal5:: @ 82F1C1C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_5.gbapal"

	.align 2
gWonderCardShadowPal6:: @ 82F1C3C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_6.gbapal"

	.align 2
gWonderCardShadowPal7:: @ 82F1C5C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_7.gbapal"

	.align 2
gWonderCardShadowPal8:: @ 82F1C7C
	.incbin "graphics/wonder_transfers/wonder_card_shadow_8.gbapal"

	.align 2
gWonderCardShadowGfx:: @ 82F1C9C
	.incbin "graphics/wonder_transfers/wonder_card_shadow.4bpp.lz"

	.align 2
gUnknown_082F1D00:: @ 82F1D00 struct CompressedSpriteSheet
	.4byte gWonderCardShadowGfx
	.2byte 0x0100
	.2byte 0x8000

	.align 2
gUnknown_082F1D08:: @ 82F1D08 struct SpritePalette
	.4byte gWonderCardShadowPal1
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal2
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal3
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal4
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal5
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal6
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal7
	.2byte 0x8000

	.align 2
	.4byte gWonderCardShadowPal8
	.2byte 0x8000

	.align 2
gUnknown_082F1D48:: @ 82F1D48
	spr_template 0x8000, 0x8000, gUnknown_08524934, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F1D60:: @ 82F1D60
	.4byte 0x00000001, gWonderCardBgGfx1, gWonderCardBgTilemap1, gWonderCardBgPal1
	.4byte 0x00001001, gWonderCardBgGfx2, gWonderCardBgTilemap2, gWonderCardBgPal2
	.4byte 0x00002001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal3
	.4byte 0x00003001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal4
	.4byte 0x00004001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal5
	.4byte 0x00005001, gWonderCardBgGfx3, gWonderCardBgTilemap3, gWonderCardBgPal6
	.4byte 0x00006001, gWonderCardBgGfx7, gWonderCardBgTilemap7, gWonderCardBgPal7
	.4byte 0x00007001, gWonderCardBgGfx8, gWonderCardBgTilemap8, gWonderCardBgPal8

gUnknown_082F1DE0:: @ 82F1DE0
	.byte 0x00, 0x02, 0x03, 0x00, 0x01, 0x02, 0x00, 0x00

gUnknown_082F1DE8:: @ 82F1DE8
	window_template 0x00, 0x01, 0x00, 0x1C, 0x03, 0x02, 0x02AC
	window_template 0x02, 0x01, 0x03, 0x1C, 0x14, 0x02, 0x007C

gUnknown_082F1DF8:: @ 82F1DF8
	.4byte 0x0318e802, 0x000098e8, 0x10000002, 0x00001000

	.align 2
gWonderNewsPal1:: @ 82F1E08
	.incbin "graphics/wonder_transfers/wonder_news_1.gbapal"

	.align 2
gWonderNewsPal7:: @ 82F1E28
	.incbin "graphics/wonder_transfers/wonder_news_7.gbapal"

	.align 2
gWonderNewsPal8:: @ 82F1E48
	.incbin "graphics/wonder_transfers/wonder_news_8.gbapal"

	.align 2
gWonderNewsGfx1:: @ 82F1E68
	.incbin "graphics/wonder_transfers/wonder_news_1.4bpp.lz"

	.align 2
gWonderNewsTilemap1:: @ 82F1EE8
	.incbin "graphics/wonder_transfers/wonder_news_1.bin.lz"

	.align 2
gWonderNewsGfx2:: @ 82F1FC4
	.incbin "graphics/wonder_transfers/wonder_news_2.4bpp.lz"

	.align 2
gWonderNewsTilemap2:: @ 82F1FF4
	.incbin "graphics/wonder_transfers/wonder_news_2.bin.lz"

	.align 2
gWonderNewsGfx3:: @ 82F20B4
	.incbin "graphics/wonder_transfers/wonder_news_3.4bpp.lz"

	.align 2
gWonderNewsTilemap3:: @ 82F2124
	.incbin "graphics/wonder_transfers/wonder_news_3.bin.lz"

	.align 2
gWonderNewsGfx7:: @ 82F21F0
	.incbin "graphics/wonder_transfers/wonder_news_7.4bpp.lz"

	.align 2
gWonderNewsTilemap7:: @ 82F2280
	.incbin "graphics/wonder_transfers/wonder_news_7.bin.lz"

	.align 2
gWonderNewsGfx8:: @ 82F235C
	.incbin "graphics/wonder_transfers/wonder_news_8.4bpp.lz"

	.align 2
gWonderNewsTilemap8:: @ 82F23EC
	.incbin "graphics/wonder_transfers/wonder_news_8.bin.lz"

	.align 2
gUnknown_082F24C8:: @ 82F24C8
	.4byte 0x00000001, gWonderNewsGfx1, gWonderNewsTilemap1, gWonderNewsPal1
	.4byte 0x00000001, gWonderNewsGfx2, gWonderNewsTilemap2, gWonderCardBgPal2
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal3
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal4
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal5
	.4byte 0x00000001, gWonderNewsGfx3, gWonderNewsTilemap3, gWonderCardBgPal6
	.4byte 0x00000001, gWonderNewsGfx7, gWonderNewsTilemap7, gWonderNewsPal7
	.4byte 0x00000001, gWonderNewsGfx8, gWonderNewsTilemap8, gWonderNewsPal8

	.align 2
gUnknown_082F2548:: @ 82F2548
	.4byte sub_801D1AC
	.4byte sub_801D1B4
	.4byte sub_801D1B8
	.4byte sub_801D1D4
	.4byte sub_801D1F0

	.align 2
gUnknown_082F255C:: @ 82F255C
	.4byte sub_801D5D0
	.4byte sub_801D5F8
	.4byte sub_801D5FC
	.4byte sub_801D61C
	.4byte sub_801D63C
	.4byte sub_801D810
	.4byte sub_801D828
	.4byte sub_801D860

	.align 2
gText_CanceledReadingCard:: @ 82F257C
	.string "Canceled reading\nthe Card.$"

	.align 2
gUnknown_082F2598:: @ 82F2598
	.byte 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F25A8:: @ 82F25A8
	.byte 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F25C8:: @ 82F25C8
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F25D8:: @ 82F25D8
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F25E8:: @ 82F25E8
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F25F8:: @ 82F25F8
	.byte 0x02, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00
	.byte 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00
	.byte 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2628:: @ 82F2628
	.byte 0x02, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2650:: @ 82F2650
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2660:: @ 82F2660
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2670:: @ 82F2670
	.byte 0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2698:: @ 82F2698
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F26A8:: @ 82F26A8
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F26B8:: @ 82F26B8
	.byte 0x02, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00
	.byte 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00
	.byte 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F26F8:: @ 82F26F8
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25C8
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25D8
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2698
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2788:: @ 82F2788
	.byte 0x12, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00

	.4byte gUnknown_082F26B8
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00

	.4byte gText_CanceledReadingCard
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F27D0:: @ 82F27D0
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2650
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2800:: @ 82F2800
	.byte 0x12, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2628
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00

	.4byte gUnknown_082F27D0
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2660
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2884:: @ 82F2884
	.byte 0x12, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25F8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F28E4:: @ 82F28E4
	.byte 0x12, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2670
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2884
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2788

	.align 2
gUnknown_082F292C:: @ 82F292C
	.byte 0x12, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F26A8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x10, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25E8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F298C:: @ 82F298C
	.byte 0x1b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x20, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25A8
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.byte 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F26F8
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2800

	.align 2
gUnknown_082F29EC:: @ 82F29EC
	.byte 0x1a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x12, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00

	.4byte gUnknown_082F25A8
	.byte 0x01, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F26F8
	.byte 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00
	.byte 0x02, 0x00, 0x00, 0x00

	.4byte gUnknown_082F28E4
	.byte 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F2884
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gUnknown_082F292C

	.align 2
gUnknown_082F2A7C:: @ 82F2A7C
	.4byte sub_801DFAC
	.4byte sub_801E030
	.4byte sub_801E120
	.4byte sub_801E240
	.4byte sub_801E764
	.4byte sub_801E838
	.4byte sub_801E460
	.4byte sub_801E5C4
	.4byte sub_801E668
	.4byte sub_801E978

	.align 2
gUnknown_082F2AA4:: @ 82F2AA4
	.byte 0x09, 0x09, 0x09, 0x09

	.align 2
gUnknown_082F2AA8:: @ 82F2AA8
	.byte 0x00, 0x16, 0x17, 0x68, 0x19, 0x1a, 0x1b, 0x1c
	.byte 0x1d, 0x1e, 0x00, 0x20, 0x21, 0x22, 0x23, 0x24
	.byte 0x25, 0x26, 0x27, 0x28, 0x29, 0x15, 0x01, 0x02
	.byte 0x00, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00
	.byte 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12
	.byte 0x13, 0x14, 0x2a, 0x2b, 0x2c, 0x2d, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x36, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x53, 0x54, 0x55, 0x56, 0x00
	.byte 0x00, 0x00, 0x6f, 0x5b, 0x5c, 0x5d, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5a
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x84, 0x85, 0x86, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7
	.byte 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf
	.byte 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5, 0xb6, 0xb7
	.byte 0xb8, 0xb9, 0xba, 0xd5, 0xd6, 0xd7, 0xd8, 0xd9
	.byte 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xdf, 0xe0, 0xe1
	.byte 0xe2, 0xe3, 0xe4, 0xe5, 0xe6, 0xe7, 0xe8, 0xe9
	.byte 0xea, 0xeb, 0xec, 0xed, 0xee, 0xbb, 0xbc, 0xbd
	.byte 0xbe, 0xbf, 0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5
	.byte 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd
	.byte 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xef
	.byte 0xf0, 0xf4, 0xf5, 0xf6, 0xf1, 0xf2, 0xf3, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F2BA8:: @ 82F2BA8
	.4byte gUnknown_0862B9F9
	.4byte gUnknown_0862B9FF
	.4byte gUnknown_0862BA05
	.4byte gUnknown_0862BA0B
	.4byte gUnknown_0862BA11
	.4byte gUnknown_0862BA17
	.4byte gUnknown_0862BA1D
	.4byte gUnknown_0862BA23
	.4byte gUnknown_0862BA29
	.4byte gUnknown_0862BA2F
	.4byte gUnknown_0862BA35
	.4byte gUnknown_0862BA3B
	.4byte gUnknown_0862BA41
	.4byte gUnknown_0862BA47
	.4byte gUnknown_0862BA4D
	.4byte gUnknown_0862BA53
	.4byte gUnknown_0862BA59
	.4byte gUnknown_0862BA5F
	.4byte gUnknown_0862BA65
	.4byte gUnknown_0862BA6B
	.4byte gUnknown_0862BA79
	.4byte gUnknown_0862BA84
	.4byte gUnknown_0862BA8F
	.4byte gUnknown_0862BA9A
	.4byte gUnknown_0862BAA3
	.4byte gUnknown_0862BAAE
	.4byte gUnknown_0862BAB9
	.4byte gUnknown_0862BAC4
	.4byte gUnknown_0862BACF
	.4byte gUnknown_0862BADA

	.align 2
gUnknown_082F2C20:: @ 82F2C20
	.incbin "graphics/interface/unk_palette1.gbapal"

	.align 2
gUnknown_082F2C40:: @ 82F2C40
	.incbin "graphics/interface/unk_palette2.gbapal"

	.align 2
gUnknown_082F2C60:: @ 82F2C60 struct BgTemplate
	.4byte 0x00000070, 0x000011fd, 0x0000217a, 0x000070f7

	.align 2
gUnknown_082F2C70:: @ 82F2C70
	window_template 0x03, 0x08, 0x01, 0x15, 0x13, 0x0f, 0x0001
	window_template 0x01, 0x09, 0x12, 0x0f, 0x02, 0x0c, 0x007a
	window_template 0x01, 0x00, 0x02, 0x06, 0x0f, 0x07, 0x0020
	window_template 0x00, 0x01, 0x02, 0x07, 0x09, 0x0e, 0x0013
	null_window_template

	.align 2
gUnknown_082F2C98:: @ 82F2C98
	.4byte 0x00000000, sub_801F658
	.4byte 0x00000003, sub_801F6F8
	.4byte 0x00000004, sub_801F730
	.4byte 0x00000005, sub_801F768
	.4byte 0x00000001, sub_801F7D4
	.4byte 0x00000006, sub_801F7E0
	.4byte 0x00000007, sub_801F82C
	.4byte 0x00000008, sub_801F870
	.4byte 0x00000009, sub_801F8DC
	.4byte 0x0000000a, sub_801F984
	.4byte 0x0000000b, sub_801FA2C
	.4byte 0x0000000c, sub_801FA68
	.4byte 0x00000002, sub_801FB44
	.4byte 0x0000000d, sub_801FB70
	.4byte 0x00000012, sub_801FBB4
	.4byte 0x00000013, sub_801FBF8
	.4byte 0x0000000e, sub_801FC4C
	.4byte 0x0000000f, sub_801FC9C
	.4byte 0x00000010, sub_801FCEC
	.4byte 0x00000011, sub_801FD30
	.4byte 0x00000014, sub_801FD88

	.align 2
gUnknown_082F2D40:: @ 82F2D40
	.4byte gText_QuitChatting
	.byte 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gText_RegisterTextWhere
	.byte 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gText_RegisterTextHere
	.byte 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gText_InputText
	.byte 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gText_ExitingChat
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00

	.4byte gText_LeaderLeftEndingChat
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00

	.4byte gText_RegisteredTextChanged
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00

	.4byte gText_AlreadySavedFile_Unused
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00

	.4byte gText_SavingDontTurnOff_Unused
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00

	.4byte gText_PlayerSavedGame_Unused
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00

	.4byte gText_IfLeaderLeavesChatEnds
	.byte 0x02, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00

	.align 2
gText_Ellipsis:: @ 82F2DC4
	.string "…$"

	.align 2
gUnknown_082F2DC8:: @ 82F2DC8
	.4byte gText_Upper, 0x00000000
	.4byte gText_Lower, 0x00000000
	.4byte gText_Symbols, 0x00000000
	.4byte gText_Register2, 0x00000000
	.4byte gText_Exit2, 0x00000000

	.align 2
gUnknown_082F2DF0:: @ 82F2DF0
	.incbin "graphics/interface/unk_palette3.gbapal"

	.align 2
gUnknown_082F2E10:: @ 82F2E10
	.incbin "graphics/interface/unk_cursor.4bpp.lz"

	.align 2
gUnknown_082F3094:: @ 82F3094
	.incbin "graphics/interface/unk_dash.4bpp.lz"

	.align 2
gUnknown_082F30B4:: @ 82F30B4
	.incbin "graphics/interface/unk_cursor_arrow.4bpp.lz"

	.align 2
gUnknown_082F30E0:: @ 82F30E0
	.incbin "graphics/interface/unk_rbutton.4bpp.lz"

	.align 2
gUnknown_082F3134:: @ 82F3134
	.4byte gUnknown_082F2E10
	.2byte 0x1000, 0x0000

	.4byte gUnknown_082F30B4
	.2byte 0x0040, 0x0001

	.4byte gUnknown_082F3094
	.2byte 0x0040, 0x0002

	.4byte gUnknown_082F30E0
	.2byte 0x0080, 0x0003

	.4byte gUnknown_08DD4CF8
	.2byte 0x0400, 0x0004

	.align 2
gUnknown_082F315C:: @ 82F315C struct SpritePalette
	.4byte gUnknown_082F2DF0
	.2byte 0x0000

	.align 2
gUnknown_082F3164:: @ 82F3164
	.2byte 0x4000, 0xc000, 0x0400, 0x0000

	.align 2
gUnknown_082F316C:: @ 82F316C
	.2byte 0x0000, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F3174:: @ 82F3174
	.2byte 0x0020, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F317C:: @ 82F317C
	.2byte 0x0040, 0x001e, 0xffff, 0x0000

	.align 2
gUnknown_082F3184:: @ 82F3184
	.2byte 0x0060, 0x001e, 0xffff, 0x0000

gUnknown_082F318C:: @ 82F318C
	.4byte gUnknown_082F316C
	.4byte gUnknown_082F3174
	.4byte gUnknown_082F317C
	.4byte gUnknown_082F3184

	.align 2
gUnknown_082F319C:: @ 82F319C
	spr_template 0x0000, 0x0000, gUnknown_082F3164, gUnknown_082F318C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F31B4:: @ 82F31B4
	.byte 0x00, 0x80, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31BC:: @ 82F31BC
	spr_template 0x0002, 0x0000, gUnknown_082F31B4, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8020ABC

	.align 2
gUnknown_082F31D4:: @ 82F31D4
	spr_template 0x0001, 0x0000, gUnknown_082F31B4, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, sub_8020AF4

	.align 2
gUnknown_082F31EC:: @ 82F31EC
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31F4:: @ 82F31F4
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082F31FC:: @ 82F31FC
	.2byte 0x0000, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F3204:: @ 82F3204
	.2byte 0x0008, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F320C:: @ 82F320C
	.2byte 0x0010, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F3214:: @ 82F3214
	.2byte 0x0018, 0x0002, 0xffff, 0x0000

	.align 2
gUnknown_082F321C:: @ 82F321C
	.4byte gUnknown_082F31FC
	.4byte gUnknown_082F3204
	.4byte gUnknown_082F320C
	.4byte gUnknown_082F3214

	.align 2
gUnknown_082F322C:: @ 82F322C
	spr_template 0x0003, 0x0000, gUnknown_082F31EC, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F3244:: @ 82F3244
	spr_template 0x0004, 0x0000, gUnknown_082F31F4, gUnknown_082F321C, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F325C:: @ 82F325C
	.byte 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80

	.align 2
gUnknown_082F3264:: @ 82F3264
	.byte 0x00, 0x01, 0x02, 0x03, 0x05, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F326C:: @ 82F326C
	.byte 0x04, 0x01, 0x00, 0xff, 0x00, 0x00, 0x00, 0x04
	.byte 0x02, 0x00, 0xff, 0x00, 0x00, 0x00, 0x04, 0x02
	.byte 0x00, 0xfe, 0x00, 0x00, 0x00, 0x06, 0x03, 0x01
	.byte 0xff, 0xfd, 0xff, 0x00, 0x06, 0x04, 0x01, 0xfe
	.byte 0xfc, 0xfe, 0x00, 0x00

	.align 2
gUnknown_082F3290:: @ 82F3290
	.byte 0x03, 0x02, 0x01, 0x00, 0x03, 0x03, 0x01, 0x00
	.byte 0x03, 0x03, 0x02, 0x00, 0x03, 0x04, 0x02, 0x00
	.byte 0x03, 0x05, 0x03, 0x00

	.align 2
gUnknown_082F32A4:: @ 82F32A4
	.4byte gText_ReadyToBerryCrush
	.4byte gText_WaitForAllChooseBerry
	.4byte gText_EndedWithXUnitsPowder
	.4byte gText_RecordingGameResults
	.4byte gText_PlayBerryCrushAgain
	.4byte gText_YouHaveNoBerries
	.4byte gText_MemberDroppedOut
	.4byte gText_TimesUpNoGoodPowder
	.4byte gText_CommunicationStandby2

	.align 2
gUnknown_082F32C8:: @ 82F32C8 struct BgTemplate
	.4byte 0x000000F8

	.align 2
gUnknown_082F32CC:: @ 82F32CC struct BgTemplate? not sure
	.byte 0xd1, 0x14, 0x00, 0x00, 0xc2, 0x20, 0x00, 0x00
	.byte 0xb3, 0x30, 0x00, 0x00

	.align 2
gUnknown_082F32D8:: @ 82F32D8
	.byte 0x01, 0x02, 0x03

gUnknown_082F32DB:: @ 82F32DB
	.byte 0x00, 0x01, 0x02

gUnknown_082F32DE:: @ 82F32DE
	.byte 0x00, 0x03, 0x04

gUnknown_082F32E1:: @ 82F32E1
	.byte 0x01, 0x08, 0x09
	.byte 0x01, 0x06, 0x07

gUnknown_082F32E7:: @ 82F32E7
	.byte 0x01, 0x04, 0x05

	.align 2
gUnknown_082F32EC:: @ 82F32EC
	window_template 0x00, 0x03, 0x04, 0x18, 0x0d, 0x0f, 0x0001

	.align 2
gUnknown_082F32F4:: @ 82F32F4
	window_template 0x00, 0x00, 0x00, 0x09, 0x02, 0x08, 0x03ed
	window_template 0x00, 0x00, 0x03, 0x09, 0x02, 0x08, 0x03db
	window_template 0x00, 0x00, 0x06, 0x09, 0x02, 0x08, 0x03c9
	window_template 0x00, 0x15, 0x03, 0x09, 0x02, 0x08, 0x03b7
	window_template 0x00, 0x15, 0x06, 0x09, 0x02, 0x08, 0x03a5
	null_window_template

	window_template 0x00, 0x05, 0x02, 0x14, 0x10, 0x0f, 0x0001
	window_template 0x00, 0x05, 0x02, 0x14, 0x10, 0x0f, 0x0001
	window_template 0x00, 0x04, 0x02, 0x16, 0x10, 0x0f, 0x0001
	null_window_template

	.align 2
gUnknown_082F3344:: @ 82F3344
	.byte 0x06, 0x08, 0x09, 0x0b, 0x0c, 0x0e, 0x0f, 0x10

	.align 2
gUnknown_082F334C:: @ 82F334C
	.byte 0x80, 0xf0, 0xfa, 0x02, 0x40, 0x78, 0x7d, 0x01
	.byte 0x20, 0xbc, 0xbe, 0x00, 0x10, 0x5e, 0x5f, 0x00
	.byte 0x08, 0xaf, 0x2f, 0x00, 0x84, 0xd7, 0x17, 0x00
	.byte 0xc2, 0xeb, 0x0b, 0x00, 0xe1, 0xf5, 0x05, 0x00

	.align 2
gBerryCrushGrinderBasePal:: @ 82F336C
	.incbin "graphics/link_games/berrycrush_grinder_base.gbapal"

	.align 2
gBerryCrushMiscSpritesPal:: @ 82F338C
	.incbin "graphics/link_games/berrycrush_misc.gbapal"

	.align 2
gBerryCrushTimerDigitsPal:: @ 82F33AC
	.incbin "graphics/link_games/berrycrush_timerdigits.gbapal"

	.align 2
gBerryCrushGrinderBaseGfx:: @ 82F33CC
	.incbin "graphics/link_games/berrycrush_grinder_base.4bpp.lz"

	.align 2
gBerryCrushBtnPressGfx:: @ 82F36F8
	.incbin "graphics/link_games/berrycrush_btnpress.4bpp.lz"

	.align 2
gBerryCrushSparkleGfx:: @ 82F3A74
	.incbin "graphics/link_games/berrycrush_sparkle.4bpp.lz"

	.align 2
gBerryCrushTimerDigitsGfx:: @ 82F3BC0
	.incbin "graphics/link_games/berrycrush_timerdigits.4bpp.lz"

	.align 2
gBerryCrushGrinderTopTilemap:: @ 82F3C8C
	.incbin "graphics/link_games/berrycrush_grinder_top.bin.lz"

	.align 2
gBerryCrushContainerCapTilemap:: @ 82F3DBC
	.incbin "graphics/link_games/berrycrush_container_cap.bin.lz"

	.align 2
gBerryCrushBackgroundTilemap:: @ 82F3F54
	.incbin "graphics/link_games/berrycrush_background.bin.lz"

	.align 2
gUnknown_082F417C:: @ 82F417C
	.byte 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03
	.byte 0x00, 0x00, 0x01, 0x03, 0x02, 0x04, 0x00, 0x00
	.byte 0x01, 0x03, 0x02, 0x04

	.align 2
gUnknown_082F4190:: @ 82F4190
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xff
	.byte 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00
	.byte 0xe4, 0xff, 0xfc, 0xff, 0xe8, 0xff, 0x10, 0x00
	.byte 0x02, 0x00, 0x06, 0x00, 0xf0, 0xff, 0x14, 0x00
	.byte 0xf8, 0xff, 0x10, 0x00, 0x03, 0x14, 0x03, 0x00
	.byte 0x1c, 0x00, 0xfc, 0xff, 0x20, 0x00, 0xf8, 0xff
	.byte 0x04, 0x14, 0x06, 0x00, 0x10, 0x00, 0x14, 0x00
	.byte 0x10, 0x00, 0xf8, 0xff

	.align 2
gUnknown_082F41CC:: @ 82F41CC
	.byte 0x00, 0x00, 0xff, 0x00, 0x01, 0x01, 0x00, 0x00
	.byte 0xf0, 0xfc, 0x10, 0xfc, 0xf8, 0xfe, 0x08, 0xfe
	.byte 0xe8, 0xf8, 0x18, 0xf8, 0xe0, 0xf4, 0x20, 0xf4
	.byte 0xd8, 0xf0, 0x28, 0xf0

	.align 2
gUnknown_082F41E8:: @ 82F41E8
	.2byte 0x0005, 0x0006, 0x0007, 0x0008, 0x0009, 0x0000

	.align 2
gUnknown_082F41F4:: @ 82F41F4
	.4byte gBerryCrushGrinderBaseGfx
	.2byte 0x0800, 0x0001

	.4byte gBerryCrushBtnPressGfx
	.2byte 0x0e00, 0x0002

	.4byte gBerryCrushSparkleGfx
	.2byte 0x0700, 0x0003

	.align 2
gUnknown_082F420C:: @ 82F420C
	.4byte gBerryCrushTimerDigitsGfx
	.2byte 0x02c0, 0x0004

	.4byte NULL
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082F421C:: @ 82F421C
	.4byte gBerryCrushGrinderBasePal
	.2byte 0x0001

	.align 2
	.4byte gBerryCrushMiscSpritesPal
	.2byte 0x0002

	.align 2
gUnknown_082F422C:: @ 82F422C
	.align 2
	.4byte gBerryCrushTimerDigitsPal
	.2byte 0x0004

	.align 2
	.4byte NULL
	.2byte 0x0000

	.align 2
gUnknown_082F423C:: @ 82F423C
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082F4244:: @ 82F4244
	.2byte 0x0000, 0x0004, 0x0010, 0x0004, 0x0020, 0x0004, 0xffff, 0x0000

	.align 2
gUnknown_082F4254:: @ 82F4254
	.2byte 0x0030, 0x0002, 0x0040, 0x0002, 0x0050, 0x0002, 0x0060, 0x0002
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082F4268:: @ 82F4268
	.2byte 0x0000, 0x0002, 0x0004, 0x0002, 0x0008, 0x0002, 0x000c, 0x0002
	.2byte 0x0010, 0x0002, 0x0014, 0x0002, 0xfffe, 0x0000

	.align 2
gUnknown_082F4284:: @ 82F4284
	.2byte 0x0018, 0x0004, 0x001c, 0x0004, 0x0020, 0x0004, 0x0024, 0x0004
	.2byte 0x0028, 0x0004, 0x002c, 0x0004, 0x0030, 0x0004, 0x0034, 0x0004
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082F42A8:: @ 82F42A8
	.2byte 0x0014, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082F42B0:: @ 82F42B0
	.2byte 0x0000, 0x0000, 0xffff, 0x0000

	.align 2
gUnknown_082F42B8:: @ 82F42B8
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x0102, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_082F42D0:: @ 82F42D0
	.2byte 0x0100, 0x0100, 0x0000, 0x0000, 0x0000, 0x0000, 0x01fe, 0x0000
	.2byte 0x7ffe, 0x0001, 0x0000, 0x0000

	.align 2
gUnknown_082F42E8:: @ 82F42E8
	.4byte gUnknown_082F423C

	.align 2
gUnknown_082F42EC:: @ 82F42EC
	.4byte gUnknown_082F4244
	.4byte gUnknown_082F4254

	.align 2
gUnknown_082F42F4:: @ 82F42F4
	.4byte gUnknown_082F4268
	.4byte gUnknown_082F4284

	.align 2
gUnknown_082F42FC:: @ 82F42FC
	.4byte gUnknown_082F42A8

	.align 2
gUnknown_082F4300:: @ 82F4300
	.4byte gUnknown_082F42B0

	.align 2
gUnknown_082F4304:: @ 82F4304
	.4byte gUnknown_082F42B8
	.4byte gUnknown_082F42D0

	.align 2
gUnknown_082F430C:: @ 82F430C
	spr_template 0x0001, 0x0001, gUnknown_0852491C, gUnknown_082F42E8, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F4324:: @ 82F4324
	spr_template 0x0002, 0x0002, gUnknown_08524914, gUnknown_082F42EC, NULL, gDummySpriteAffineAnimTable, sub_8022A20

	.align 2
gUnknown_082F433C:: @ 82F433C
	spr_template 0x0003, 0x0002, gUnknown_0852490C, gUnknown_082F42F4, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F4354:: @ 82F4354
	spr_template 0x0004, 0x0004, gUnknown_08524944, gUnknown_082F42FC, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082F436C:: @ 82F436C
	spr_template 0x0005, 0x0005, gUnknown_085249D4, gUnknown_082F4300, NULL, gUnknown_082F4304, SpriteCallbackDummy

	.align 2
gUnknown_082F4384:: @ 82F4384
	.byte 0x09, 0x02, 0x08, 0x00, 0x9c, 0x00, 0x00, 0x00
	.4byte gUnknown_082F420C
	.4byte gUnknown_082F422C

	.byte 0x08, 0x02, 0x08, 0x00, 0xb4, 0x00, 0x00, 0x00
	.4byte gUnknown_082F420C
	.4byte gUnknown_082F422C

	.byte 0x08, 0x02, 0x08, 0x00, 0xcc, 0x00, 0x00, 0x00
	.4byte gUnknown_082F420C
	.4byte gUnknown_082F422C

	.align 2
gUnknown_082F43B4:: @ 82F43B4
	.4byte gText_SpaceTimes2
	.4byte gText_XDotY
	.4byte gText_Var1Berry
	.4byte gText_NeatnessRankings
	.4byte gText_CoopRankings
	.4byte gText_PressingPowerRankings

	.align 2
gUnknown_082F43CC:: @ 82F43CC
	.4byte NULL
	.4byte sub_8022C58
	.4byte sub_8022CB0
	.4byte sub_8022D14
	.4byte sub_8022E1C
	.4byte sub_8022E3C
	.4byte sub_8022E5C
	.4byte sub_8022EAC
	.4byte sub_8022F04
	.4byte sub_8022F1C
	.4byte sub_8023070
	.4byte sub_80231B8
	.4byte sub_80232EC
	.4byte sub_80238F0
	.4byte sub_8023998
	.4byte sub_8023A30
	.4byte sub_8023BC0
	.4byte sub_8023CAC
	.4byte sub_8024048
	.4byte sub_8024134
	.4byte sub_8024228
	.4byte sub_80242E0
	.4byte sub_80243BC
	.4byte sub_8024444
	.4byte sub_8024508
	.4byte sub_8024568

	.align 2
gUnknown_082F4434:: @ 82F4434
	.byte 0x02, 0x04, 0x06, 0x07, 0x03, 0x05, 0x08, 0x0b
	.byte 0x03, 0x07, 0x0b, 0x0f, 0x04, 0x08, 0x0c, 0x11

gUnknown_082F4444:: @ 82F4444
	.byte 0x05, 0x07, 0x09, 0x0c

gUnknown_082F4448:: @ 82F4448
	.byte 0x03, 0x07, 0x0f, 0x1f

	.align 2
gUnknown_082F7BA4_UnrefDupe:: @ 82F444C struct BgTemplate
	.4byte 0x000001e0
	.4byte 0x000012c9
	.4byte 0x000012ea
	.4byte 0x000021ff
	.4byte 0x000000ff
	.4byte 0x00000000

	.align 2
gUnknown_082F7BBC_UnrefDupe:: @ 82F4464
	window_template 0x00, 0x01, 0x01, 0x1c, 0x02, 0x0d, 0x0013
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0e, 0x0d, 0x004b

	.align 2
gUnknown_082F7BCC_UnrefDupe:: @ 82F4474
	window_template 0x00, 0x01, 0x05, 0x1c, 0x07, 0x0d, 0x004b

	.align 2
gUnknown_082F7BD4_UnrefDupe:: @ 82F447C
	window_template 0x00, 0x01, 0x08, 0x13, 0x03, 0x0d, 0x0013
	window_template 0x00, 0x16, 0x07, 0x06, 0x04, 0x0d, 0x004c

	.align 2
gUnknown_082F7BE4_UnrefDupe:: @ 82F448C
	window_template 0x00, 0x04, 0x06, 0x16, 0x05, 0x0d, 0x0013

	.align 2
gUnknown_082F7BEC_UnrefDupe:: @ 82F4494
	window_template 0x00, 0x05, 0x08, 0x13, 0x03, 0x0d, 0x0013

	.align 2
gUnknown_082F449C:: @ 82F449C
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
	.byte 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x03, 0x08
	.byte 0x09, 0x00, 0x00, 0x01, 0x02, 0x05, 0x06, 0x03
	.byte 0x04, 0x05, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
	.byte 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x02, 0x09
	.byte 0x00, 0x00, 0x01, 0x04, 0x05, 0x06, 0x07, 0x02
	.byte 0x03, 0x04, 0x09, 0x00, 0x00, 0x01, 0x06, 0x07
	.byte 0x02, 0x03, 0x04, 0x05, 0x06, 0x09, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02
	.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x00
	.byte 0x00, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01
	.byte 0x02, 0x03, 0x00, 0x00, 0x05, 0x06, 0x07, 0x08
	.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x07
	.byte 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03
	.byte 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x02
	.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00
	.byte 0x01, 0x02, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08
	.byte 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06
	.byte 0x08, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05
	.byte 0x06, 0x07, 0x08, 0x04, 0x05, 0x06, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x03, 0x04, 0x05, 0x05, 0x06, 0x03
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x04, 0x05, 0x06, 0x06, 0x07, 0x02, 0x02
	.byte 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x04, 0x05, 0x05, 0x06, 0x07, 0x07, 0x08
	.byte 0x01, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00, 0x04
	.byte 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09, 0x00
	.byte 0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x01, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01
	.byte 0x02, 0x01, 0x02, 0x03, 0x02, 0x03, 0x00, 0x00
	.byte 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x01, 0x02
	.byte 0x01, 0x02, 0x03, 0x02, 0x03, 0x04, 0x03, 0x04
	.byte 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09
	.byte 0x01, 0x01, 0x01, 0x09, 0x09, 0x09, 0x09, 0x09
	.byte 0x09, 0x09, 0x00, 0x00, 0x01, 0x01, 0x00, 0x09
	.byte 0x09, 0x09, 0x09, 0x09, 0x02, 0x02, 0x00, 0x00
	.byte 0x01, 0x01, 0x01, 0x09, 0x09, 0x09, 0x03, 0x03
	.byte 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x09
	.byte 0x03, 0x03, 0x04, 0x04, 0x00, 0x00, 0x01, 0x01
	.byte 0x02, 0x02, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x06, 0x00, 0x00, 0x00, 0x03, 0x05, 0x07
	.byte 0x00, 0x00, 0x02, 0x04, 0x06, 0x08, 0x00, 0x01
	.byte 0x03, 0x05, 0x06, 0x09

	.align 2
gUnknown_082F7DF0_UnrefDupe:: @ 82F4698
	.incbin "graphics/link_games/dodrioberry_bg1.gbapal"

	.align 2
	.incbin "graphics/link_games/dodrioberry_bg2.gbapal"

	.align 2
gUnknown_082F7E30_UnrefDupe:: @ 82F46B8
	.incbin "graphics/link_games/dodrioberry_pkmn.gbapal"

	.align 2
gUnknown_082F7E50_UnrefDupe:: @ 82F46D8
	.incbin "graphics/link_games/dodrioberry_shiny.gbapal"

	.align 2
gUnknown_082F7E70_UnrefDupe:: @ 82F46F8
	.incbin "graphics/link_games/dodrioberry_status.gbapal"

	.align 2
gUnknown_082F7E90_UnrefDupe:: @ 82F4718
	.incbin "graphics/link_games/dodrioberry_berrysprites.gbapal"

	.align 2
gUnknown_082F7EB0_UnrefDupe:: @ 82F4738
	.incbin "graphics/link_games/dodrioberry_berrysprites.4bpp.lz"

	.align 2
gUnknown_082F8064_UnrefDupe:: @ 82F490C
	.incbin "graphics/link_games/dodrioberry_platform.gbapal"

	.align 2
gUnknown_082F8084_UnrefDupe:: @ 82F492C
	.incbin "graphics/link_games/dodrioberry_bg1.4bpp.lz"

	.align 2
gUnknown_082F8914_UnrefDupe:: @ 82F51BC
	.incbin "graphics/link_games/dodrioberry_bg2.4bpp.lz"

	.align 2
gUnknown_082F96E0_UnrefDupe:: @ 82F5F88
	.incbin "graphics/link_games/dodrioberry_status.4bpp.lz"

	.align 2
gUnknown_082F9774_UnrefDupe:: @ 82F601C
	.incbin "graphics/link_games/dodrioberry_platform.4bpp.lz"

	.align 2
gUnknown_082F98BC_UnrefDupe:: @ 82F6164
	.incbin "graphics/link_games/dodrioberry_pkmn.4bpp.lz"

	.align 2
gUnknown_082FAAD8_UnrefDupe:: @ 82F7380
	.incbin "graphics/link_games/dodrioberry_bg1.bin.lz"

	.align 2
gUnknown_082FAD44_UnrefDupe:: @ 82F75EC
	.incbin "graphics/link_games/dodrioberry_bg2right.bin.lz"

	.align 2
gUnknown_082FAF94_UnrefDupe:: @ 82F783C
	.incbin "graphics/link_games/dodrioberry_bg2left.bin.lz"

	.align 2
gUnknown_082F7A88:: @ 82F7A88
	.byte 0x28, 0x18, 0x0d, 0x20, 0x13, 0x0a, 0x16, 0x0d
	.byte 0x07, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F7A94:: @ 82F7A94
	.byte 0x08, 0x05, 0x08, 0x0b, 0x0f, 0x00, 0x00, 0x00

	.align 2
gUnknown_082F7A9C:: @ 82F7A9C
	.byte 0x05, 0x0a, 0x14, 0x1e, 0x32, 0x46, 0x64, 0x00

	.align 2
gUnknown_082F7AA4:: @ 82F7AA4
	.byte 0x0f, 0x10, 0x11, 0x12, 0x13, 0x13, 0x12, 0x11
	.byte 0x10, 0x0f, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19
	.byte 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21
	.byte 0x22, 0x22, 0x21, 0x20, 0x1f, 0x1e, 0x00, 0x00

	.align 2
gUnknown_082F7AC4:: @ 82F7AC4
	.4byte sub_8024DBC
	.4byte sub_8024E00
	.4byte sub_8024E38
	.4byte sub_8024F10
	.4byte sub_8024F38
	.4byte sub_8025198
	.4byte sub_8025324
	.4byte sub_8025470
	.4byte sub_8025644
	.4byte sub_80256AC
	.4byte sub_8025758
	.4byte sub_80250D4

	.align 2
gUnknown_082F7AF4:: @ 82F7AF4
	.4byte sub_8024DBC
	.4byte sub_8024E00
	.4byte sub_8024E38
	.4byte sub_8024F10
	.4byte sub_8024FFC
	.4byte sub_8025230
	.4byte sub_8025324
	.4byte sub_8025470
	.4byte sub_8025644
	.4byte sub_80256AC
	.4byte sub_8025758
	.4byte sub_8025158

	.align 2
gUnknown_082F7B24:: @ 82F7B24
	.2byte 0x000a, 0x001e, 0x0032, 0x0032

	.align 2
gUnknown_082F7B2C:: @ 82F7B2C
	.byte 0x00, 0x05, 0x01, 0x14, 0x0b, 0x0f, 0x01, 0x00

	.align 2
gUnknown_082F7B34:: @ 82F7B34
	.4byte gText_BerriesPicked
	.4byte gText_BestScore
	.4byte gText_BerriesInRowFivePlayers

	.align 2
gUnknown_082F7B40:: @ 82F7B40
	.byte 0x04, 0x07, 0x04, 0x00

	.align 2
gUnknown_082F7B44:: @ 82F7B44
	.2byte 0x0019, 0x0029, 0x0039

gUnknown_082F7B4A:: @ 82F7B4A
	.2byte 0x0019, 0x0029, 0x0049

	.align 2
gUnknown_082F7B50:: @ 82F7B50
	.2byte 0x270f, 0x0000, 0x005a, 0x270f, 0x270f, 0x270f, 0x0046, 0x270f
	.2byte 0x270f, 0x0000, 0x270f, 0x0000, 0x270f, 0x270f, 0x003c, 0x0000
	.2byte 0x270f, 0x270f, 0x270f, 0x0000

	.align 2
gUnknown_082F7B78:: @ 82F7B78
	.string "ÀÁÂÇÈÉÊ$"

	.align 2
gUnknown_082F7B80:: @ 82F7B80
	.string "ABCDEFG$"

	.align 2
gUnknown_082F7B88:: @ 82F7B88
	.string "0123456$"

	.align 2
gUnknown_082F7B90:: @ 82F7B90
	.4byte gUnknown_082F7B78
	.4byte gUnknown_082F7B78
	.4byte gUnknown_082F7B78
	.4byte gUnknown_082F7B80
	.4byte gUnknown_082F7B88

	.align 2
gUnknown_082F7BA4:: @ 82F7BA4 struct BgTemplate
	.4byte 0x000001e0
	.4byte 0x000012c9
	.4byte 0x000012ea
	.4byte 0x000021ff
	.4byte 0x000000ff
	.4byte 0x00000000

	.align 2
gUnknown_082F7BBC:: @ 82F7BBC
	window_template 0x00, 0x01, 0x01, 0x1c, 0x02, 0x0d, 0x0013
	window_template 0x00, 0x01, 0x05, 0x1c, 0x0e, 0x0d, 0x004b

	.align 2
gUnknown_082F7BCC:: @ 82F7BCC
	window_template 0x00, 0x01, 0x05, 0x1c, 0x07, 0x0d, 0x004b

	.align 2
gUnknown_082F7BD4:: @ 82F7BD4
	window_template 0x00, 0x01, 0x08, 0x13, 0x03, 0x0d, 0x0013
	window_template 0x00, 0x16, 0x07, 0x06, 0x04, 0x0d, 0x004c

	.align 2
gUnknown_082F7BE4:: @ 82F7BE4
	window_template 0x00, 0x04, 0x06, 0x16, 0x05, 0x0d, 0x0013

	.align 2
gUnknown_082F7BEC:: @ 82F7BEC
	window_template 0x00, 0x05, 0x08, 0x13, 0x03, 0x0d, 0x0013

	.align 2
gUnknown_082F449C_UnrefDupe:: @ 82F7BF4
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
	.byte 0x08, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x03, 0x08
	.byte 0x09, 0x00, 0x00, 0x01, 0x02, 0x05, 0x06, 0x03
	.byte 0x04, 0x05, 0x08, 0x09, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
	.byte 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x02, 0x09
	.byte 0x00, 0x00, 0x01, 0x04, 0x05, 0x06, 0x07, 0x02
	.byte 0x03, 0x04, 0x09, 0x00, 0x00, 0x01, 0x06, 0x07
	.byte 0x02, 0x03, 0x04, 0x05, 0x06, 0x09, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02
	.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01, 0x00
	.byte 0x00, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x01
	.byte 0x02, 0x03, 0x00, 0x00, 0x05, 0x06, 0x07, 0x08
	.byte 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x07
	.byte 0x08, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x03
	.byte 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00, 0x02
	.byte 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x00
	.byte 0x01, 0x02, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08
	.byte 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06
	.byte 0x08, 0x09, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05
	.byte 0x06, 0x07, 0x08, 0x04, 0x05, 0x06, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x03, 0x04, 0x05, 0x05, 0x06, 0x03
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x04, 0x05, 0x06, 0x06, 0x07, 0x02, 0x02
	.byte 0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x03, 0x04, 0x05, 0x05, 0x06, 0x07, 0x07, 0x08
	.byte 0x01, 0x01, 0x02, 0x03, 0x00, 0x00, 0x00, 0x04
	.byte 0x05, 0x06, 0x06, 0x07, 0x08, 0x08, 0x09, 0x00
	.byte 0x00, 0x01, 0x02, 0x02, 0x03, 0x04, 0x01, 0x00
	.byte 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01
	.byte 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01, 0x00
	.byte 0x01, 0x02, 0x01, 0x02, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01
	.byte 0x02, 0x01, 0x02, 0x03, 0x02, 0x03, 0x00, 0x00
	.byte 0x00, 0x00, 0x04, 0x00, 0x01, 0x00, 0x01, 0x02
	.byte 0x01, 0x02, 0x03, 0x02, 0x03, 0x04, 0x03, 0x04
	.byte 0x00, 0x00, 0x00, 0x00, 0x09, 0x09, 0x09, 0x09
	.byte 0x01, 0x01, 0x01, 0x09, 0x09, 0x09, 0x09, 0x09
	.byte 0x09, 0x09, 0x00, 0x00, 0x01, 0x01, 0x00, 0x09
	.byte 0x09, 0x09, 0x09, 0x09, 0x02, 0x02, 0x00, 0x00
	.byte 0x01, 0x01, 0x01, 0x09, 0x09, 0x09, 0x03, 0x03
	.byte 0x00, 0x00, 0x01, 0x01, 0x02, 0x02, 0x03, 0x09
	.byte 0x03, 0x03, 0x04, 0x04, 0x00, 0x00, 0x01, 0x01
	.byte 0x02, 0x02, 0x03, 0x05, 0x00, 0x00, 0x00, 0x00
	.byte 0x04, 0x06, 0x00, 0x00, 0x00, 0x03, 0x05, 0x07
	.byte 0x00, 0x00, 0x02, 0x04, 0x06, 0x08, 0x00, 0x01
	.byte 0x03, 0x05, 0x06, 0x09

	.align 2
gDodrioBerryBgPal1:: @ 82F7DF0
	.incbin "graphics/link_games/dodrioberry_bg1.gbapal"

	.align 2
	.incbin "graphics/link_games/dodrioberry_bg2.gbapal"

	.align 2
gDodrioBerryPkmnPal:: @ 82F7E30
	.incbin "graphics/link_games/dodrioberry_pkmn.gbapal"

	.align 2
gDodrioBerryShinyPal:: @ 82F7E50
	.incbin "graphics/link_games/dodrioberry_shiny.gbapal"

	.align 2
gDodrioBerryStatusPal:: @ 82F7E70
	.incbin "graphics/link_games/dodrioberry_status.gbapal"

	.align 2
gDodrioBerrySpritesPal:: @ 82F7E90
	.incbin "graphics/link_games/dodrioberry_berrysprites.gbapal"

	.align 2
gDodrioBerrySpritesGfx:: @ 82F7EB0
	.incbin "graphics/link_games/dodrioberry_berrysprites.4bpp.lz"

	.align 2
gDodrioBerryPlatformPal:: @ 82F8064
	.incbin "graphics/link_games/dodrioberry_platform.gbapal"

	.align 2
gDodrioBerryBgGfx1:: @ 82F8084
	.incbin "graphics/link_games/dodrioberry_bg1.4bpp.lz"

	.align 2
gDodrioBerryBgGfx2:: @ 82F8914
	.incbin "graphics/link_games/dodrioberry_bg2.4bpp.lz"

	.align 2
gDodrioBerryStatusGfx:: @ 82F96E0
	.incbin "graphics/link_games/dodrioberry_status.4bpp.lz"

	.align 2
gDodrioBerryPlatformGfx:: @ 82F9774
	.incbin "graphics/link_games/dodrioberry_platform.4bpp.lz"

	.align 2
gDodrioBerryPkmnGfx:: @ 82F98BC
	.incbin "graphics/link_games/dodrioberry_pkmn.4bpp.lz"

	.align 2
gDodrioBerryBgTilemap1:: @ 82FAAD8
	.incbin "graphics/link_games/dodrioberry_bg1.bin.lz"

	.align 2
gDodrioBerryBgTilemap2Right:: @ 82FAD44
	.incbin "graphics/link_games/dodrioberry_bg2right.bin.lz"

	.align 2
gDodrioBerryBgTilemap2Left:: @ 82FAF94
	.incbin "graphics/link_games/dodrioberry_bg2left.bin.lz"

	.align 2
gUnknown_082FB1E0:: @ 82FB1E0
	.byte 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FB1E8:: @ 82FB1E8
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FB1F0:: @ 82FB1F0
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FB1F8:: @ 82FB1F8
	.byte 0x00, 0x40, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x00

	.align 2
gUnknown_082FB200:: @ 82FB200
	.2byte 0x0000, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB208:: @ 82FB208
	.2byte 0x0040, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB210:: @ 82FB210
	.2byte 0x0080, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB218:: @ 82FB218
	.2byte 0x00c0, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB220:: @ 82FB220
	.2byte 0x0100, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB228:: @ 82FB228
	.4byte gUnknown_082FB200
	.4byte gUnknown_082FB208
	.4byte gUnknown_082FB210
	.4byte gUnknown_082FB218
	.4byte gUnknown_082FB220

	.align 2
gUnknown_082FB23C:: @ 82FB23C
	.2byte 0x0000, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB244:: @ 82FB244
	.2byte 0x0004, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB24C:: @ 82FB24C
	.2byte 0x0008, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB254:: @ 82FB254
	.4byte gUnknown_082FB23C
	.4byte gUnknown_082FB244
	.4byte gUnknown_082FB24C

	.align 2
gUnknown_082FB260:: @ 82FB260
	.2byte 0x0000, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB268:: @ 82FB268
	.2byte 0x0004, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB270:: @ 82FB270
	.2byte 0x0008, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB278:: @ 82FB278
	.2byte 0x000c, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB280:: @ 82FB280
	.2byte 0x0010, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB288:: @ 82FB288
	.2byte 0x0014, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB290:: @ 82FB290
	.2byte 0x0018, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB298:: @ 82FB298
	.2byte 0x001c, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB2A0:: @ 82FB2A0
	.2byte 0x0020, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB2A8:: @ 82FB2A8
	.4byte gUnknown_082FB260
	.4byte gUnknown_082FB268
	.4byte gUnknown_082FB270
	.4byte gUnknown_082FB278
	.4byte gUnknown_082FB280
	.4byte gUnknown_082FB288
	.4byte gUnknown_082FB290
	.4byte gUnknown_082FB298
	.4byte gUnknown_082FB2A0

	.align 2
gUnknown_082FB2CC:: @ 82FB2CC
	.2byte 0x0000, 0x0014
	.2byte 0xfffe, 0x0000

	.align 2
gUnknown_082FB2D4:: @ 82FB2D4
	.4byte gUnknown_082FB2CC

	.align 2
gUnknown_082FB2D8:: @ 82FB2D8
	obj_pal gDodrioBerryPkmnPal, 0x0000

	.align 2
gUnknown_082FB2E0:: @ 82FB2E0
	obj_pal gDodrioBerryShinyPal, 0x0001

	.align 2
gUnknown_082FB2E8:: @ 82FB2E8
	obj_pal gDodrioBerryStatusPal, 0x0002

	.align 2
gUnknown_082FB2F0:: @ 82FB2F0
	spr_template 0x0001, 0x0002, gUnknown_082FB1E8, gUnknown_082FB254, NULL, gDummySpriteAffineAnimTable, nullsub_15

	.align 2
	.byte 0xD4, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44
	.byte 0x45, 0xFB, 0x00, 0x00

	.align 2
gUnknown_082FB314:: @ 82FB314
	obj_pal gDodrioBerrySpritesPal, 0x0003

	.align 2
gUnknown_082FB31C:: @ 82FB31C
	.2byte 0x0058, 0x0080, 0x00a8, 0x00d0

	.align 2
gUnknown_082FB324:: @ 82FB324
	spr_template 0x0002, 0x0003, gUnknown_082FB1F0, gUnknown_082FB2A8, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FB33C:: @ 82FB33C
	spr_template 0x0002, 0x0003, gUnknown_082FB1E8, gUnknown_082FB2A8, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FB354:: @ 82FB354
	.byte 0x1E, 0x14

gUnknown_082FB356:: @ 82FB356
	.byte 0xE6, 0x00

	.align 2
gUnknown_082FB358:: @ 82FB358
	.2byte 0x0037, 0x001e, 0x004a, 0x0000

	.align 2
gUnknown_082FB360:: @ 82FB360
	obj_pal gDodrioBerryPlatformPal, 0x0006

	.align 2
gUnknown_082FB368:: @ 82FB368
	spr_template 0x0005, 0x0006, gUnknown_082FB1F8, gUnknown_082FB2D4, NULL, gDummySpriteAffineAnimTable, sub_8028CF4

	.align 2
gUnknown_082FB380:: @ 82FB380
	.byte 0x01, 0x02, 0x03

gUnknown_082FB383:: @ 82FB383
	.byte 0x01, 0x04, 0x05
	.byte 0x01, 0x08, 0x09
	.byte 0x01, 0x06, 0x07

	.align 2
gUnknown_082FB38C:: @ 82FB38C
	.byte 0x0c, 0x06, 0x00, 0x00

	.align 2
gUnknown_082FB390:: @ 82FB390
	.byte 0x09, 0x0a, 0x00, 0x00, 0x0f, 0x06, 0x00, 0x00

	.align 2
gUnknown_082FB398:: @ 82FB398
	.byte 0x0c, 0x06, 0x00, 0x00, 0x12, 0x0a, 0x00, 0x00
	.byte 0x06, 0x0a, 0x00, 0x00

	.align 2
gUnknown_082FB3A4:: @ 82FB3A4
	.byte 0x09, 0x0a, 0x00, 0x00, 0x0f, 0x06, 0x00, 0x00
	.byte 0x15, 0x0a, 0x00, 0x00, 0x03, 0x06, 0x00, 0x00

	.align 2
gUnknown_082FB3B4:: @ 82FB3B4
	.byte 0x0c, 0x06, 0x00, 0x00, 0x12, 0x0a, 0x00, 0x00
	.byte 0x17, 0x06, 0x00, 0x00, 0x01, 0x06, 0x00, 0x00
	.byte 0x06, 0x0a, 0x00, 0x00

	.align 2
gUnknown_082FB3C8:: @ 82FB3C8
	.4byte gUnknown_082FB38C
	.4byte gUnknown_082FB390
	.4byte gUnknown_082FB398
	.4byte gUnknown_082FB3A4
	.4byte gUnknown_082FB3B4

	.align 2
gUnknown_082FB3DC:: @ 82FB3DC
	.4byte gText_1Colon
	.4byte gText_2Colon
	.4byte gText_3Colon
	.4byte gText_4Colon
	.4byte gText_5Colon

	.align 2
gUnknown_082FB3F0:: @ 82FB3F0
	.2byte 0x005c, 0x0084, 0x00ac, 0x00d4

gUnknown_082FB3F8:: @ 82FB3F8
	.2byte 0x0021, 0x0031, 0x0041, 0x0051, 0x0061

gUnknown_082FB402:: @ 82FB402
	.2byte 0x0011, 0x0021, 0x0031, 0x0041, 0x0051

	.align 2
gUnknown_082FB40C:: @ 82FB40C
	.4byte 0x00000000, sub_8029338
	.4byte 0x00000001, sub_8029440
	.4byte 0x00000002, sub_802988C
	.4byte 0x00000003, sub_802A010
	.4byte 0x00000004, sub_802A380
	.4byte 0x00000005, sub_802A454
	.4byte 0x00000006, sub_802A534
	.4byte 0x00000007, sub_802A588
	.4byte 0x00000008, unused_0
	.4byte 0x00000009, nullsub_16

	.align 2
gUnknown_082FB45C:: @ 82FB45C
	.byte 0x00, 0x01, 0x02, 0x03, 0x04, 0x00, 0x00, 0x00

	.align 2
gPkmnJumpSpecies:: @ 82FB464
	.2byte SPECIES_BULBASAUR,	0x0002
	.2byte SPECIES_CHARMANDER,	0x0001
	.2byte SPECIES_SQUIRTLE,	0x0000
	.2byte SPECIES_CATERPIE,	0x0001
	.2byte SPECIES_METAPOD,		0x0001
	.2byte SPECIES_WEEDLE,		0x0001
	.2byte SPECIES_KAKUNA,		0x0001
	.2byte SPECIES_RATTATA,		0x0001
	.2byte SPECIES_RATICATE,	0x0001
	.2byte SPECIES_PIKACHU,		0x0000
	.2byte SPECIES_SANDSHREW,	0x0000
	.2byte SPECIES_NIDORAN_F,	0x0000
	.2byte SPECIES_NIDORAN_M,	0x0000
	.2byte SPECIES_CLEFAIRY,	0x0000
	.2byte SPECIES_VULPIX,		0x0000
	.2byte SPECIES_JIGGLYPUFF,	0x0002
	.2byte SPECIES_ODDISH,		0x0002
	.2byte SPECIES_PARAS,		0x0001
	.2byte SPECIES_MEOWTH,		0x0000
	.2byte SPECIES_PSYDUCK,		0x0002
	.2byte SPECIES_MANKEY,		0x0001
	.2byte SPECIES_GROWLITHE,	0x0001
	.2byte SPECIES_POLIWAG,		0x0002
	.2byte SPECIES_BELLSPROUT,	0x0002
	.2byte SPECIES_SHELLDER,	0x0001
	.2byte SPECIES_KRABBY,		0x0001
	.2byte SPECIES_EXEGGCUTE,	0x0002
	.2byte SPECIES_CUBONE,		0x0000
	.2byte SPECIES_DITTO,		0x0002
	.2byte SPECIES_EEVEE,		0x0000
	.2byte SPECIES_OMANYTE,		0x0001
	.2byte SPECIES_KABUTO,		0x0001
	.2byte SPECIES_CHIKORITA,	0x0002
	.2byte SPECIES_CYNDAQUIL,	0x0001
	.2byte SPECIES_TOTODILE,	0x0000
	.2byte SPECIES_SPINARAK,	0x0001
	.2byte SPECIES_PICHU,		0x0000
	.2byte SPECIES_CLEFFA,		0x0000
	.2byte SPECIES_IGGLYBUFF,	0x0002
	.2byte SPECIES_TOGEPI,		0x0002
	.2byte SPECIES_MAREEP,		0x0000
	.2byte SPECIES_BELLOSSOM,	0x0002
	.2byte SPECIES_MARILL,		0x0002
	.2byte SPECIES_SUNKERN,		0x0002
	.2byte SPECIES_WOOPER,		0x0002
	.2byte SPECIES_PINECO,		0x0002
	.2byte SPECIES_SNUBBULL,	0x0000
	.2byte SPECIES_SHUCKLE,		0x0002
	.2byte SPECIES_TEDDIURSA,	0x0000
	.2byte SPECIES_SLUGMA,		0x0002
	.2byte SPECIES_SWINUB,		0x0000
	.2byte SPECIES_HOUNDOUR,	0x0001
	.2byte SPECIES_PHANPY,		0x0000
	.2byte SPECIES_PORYGON2,	0x0000
	.2byte SPECIES_TYROGUE,		0x0001
	.2byte SPECIES_SMOOCHUM,	0x0002
	.2byte SPECIES_ELEKID,		0x0001
	.2byte SPECIES_MAGBY,		0x0001
	.2byte SPECIES_LARVITAR,	0x0001
	.2byte SPECIES_TREECKO,		0x0001
	.2byte SPECIES_TORCHIC,		0x0002
	.2byte SPECIES_MUDKIP,		0x0000
	.2byte SPECIES_MARSHTOMP,	0x0000
	.2byte SPECIES_POOCHYENA,	0x0001
	.2byte SPECIES_ZIGZAGOON,	0x0000
	.2byte SPECIES_LINOONE,		0x0000
	.2byte SPECIES_WURMPLE,		0x0001
	.2byte SPECIES_SILCOON,		0x0002
	.2byte SPECIES_CASCOON,		0x0002
	.2byte SPECIES_LOTAD,		0x0002
	.2byte SPECIES_SEEDOT,		0x0001
	.2byte SPECIES_RALTS,		0x0000
	.2byte SPECIES_KIRLIA,		0x0000
	.2byte SPECIES_SURSKIT,		0x0002
	.2byte SPECIES_SHROOMISH,	0x0002
	.2byte SPECIES_NINCADA,		0x0001
	.2byte SPECIES_WHISMUR,		0x0000
	.2byte SPECIES_AZURILL,		0x0002
	.2byte SPECIES_SKITTY,		0x0000
	.2byte SPECIES_SABLEYE,		0x0000
	.2byte SPECIES_MAWILE,		0x0000
	.2byte SPECIES_ARON,		0x0001
	.2byte SPECIES_MEDITITE,	0x0002
	.2byte SPECIES_ELECTRIKE,	0x0001
	.2byte SPECIES_PLUSLE,		0x0001
	.2byte SPECIES_MINUN,		0x0001
	.2byte SPECIES_VOLBEAT,		0x0000
	.2byte SPECIES_ILLUMISE,	0x0000
	.2byte SPECIES_ROSELIA,		0x0002
	.2byte SPECIES_GULPIN,		0x0002
	.2byte SPECIES_NUMEL,		0x0002
	.2byte SPECIES_TORKOAL,		0x0002
	.2byte SPECIES_SPOINK,		0x0000
	.2byte SPECIES_TRAPINCH,	0x0002
	.2byte SPECIES_CACNEA,		0x0002
	.2byte SPECIES_ANORITH,		0x0001
	.2byte SPECIES_WYNAUT,		0x0000
	.2byte SPECIES_SNORUNT,		0x0000
	.2byte SPECIES_CLAMPERL,	0x0001
	.2byte SPECIES_BAGON,		0x0001

	.align 2
gUnknown_082FB5F4:: @ 82FB5F4
	.4byte sub_802B248
	.4byte sub_802B2D4
	.4byte sub_802B368
	.4byte sub_802B3D4
	.4byte sub_802B4CC
	.4byte sub_802B5C8
	.4byte sub_802B664
	.4byte sub_802B6B8
	.4byte sub_802B720

	.align 2
gUnknown_082FB618:: @ 82FB618
	.4byte sub_802B29C
	.4byte sub_802B31C
	.4byte sub_802B3B4
	.4byte sub_802B470
	.4byte sub_802B568
	.4byte sub_802B628
	.4byte sub_802B664
	.4byte sub_802B704
	.4byte sub_802B720

	.align 2
gUnknown_082FB63C:: @ 82FB63C
	.2byte 0x001a, 0x001f, 0x0024, 0x0029, 0x002e, 0x0033, 0x0038, 0x003d

	.align 2
gUnknown_082FB64C:: @ 82FB64C
	.2byte 0x0000, 0x0001, 0x0001, 0x0002

	.align 2
gUnknown_082FB654:: @ 82FB654
	.2byte 0x005f, 0x0066, 0x00e4, 0x0105

	.align 2
gUnknown_082FB65C:: @ 82FB65C
	.byte 0xfd, 0xfa, 0xf8, 0xf6, 0xf3, 0xf1, 0xef, 0xed
	.byte 0xeb, 0xe9, 0xe7, 0xe5, 0xe4, 0xe3, 0xe2, 0xe2
	.byte 0xe2, 0xe4, 0xe5, 0xe6, 0xe7, 0xe9, 0xea, 0xec
	.byte 0xee, 0xef, 0xf1, 0xf3, 0xf5, 0xf8, 0xfa, 0xfc
	.byte 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xfd, 0xfa, 0xf7, 0xf5, 0xf2, 0xf0, 0xee, 0xec
	.byte 0xea, 0xe8, 0xe6, 0xe4, 0xe3, 0xe2, 0xe2, 0xe4
	.byte 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf5
	.byte 0xf7, 0xfa, 0xfc, 0xff, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0xfd, 0xfa, 0xf7, 0xf5, 0xf3, 0xf1, 0xef, 0xed
	.byte 0xeb, 0xe9, 0xe7, 0xe5, 0xe4, 0xe3, 0xe2, 0xe2
	.byte 0xe2, 0xe2, 0xe3, 0xe3, 0xe4, 0xe4, 0xe5, 0xe5
	.byte 0xe6, 0xe7, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2
	.byte 0xf4, 0xf5, 0xf7, 0xfa, 0xfc, 0xff, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FB6EC:: @ 82FB6EC
	.4byte 0x00000000, 0x00000000, 0x00000032, 0x00000064
	.4byte 0x000000c8, 0x000001f4

	.align 2
gUnknown_082FB704:: @ 82FB704
	.2byte 0x008a, 0x008d, 0x008e, 0x008f, 0x0090, 0x0091, 0x0092, 0x0093

	.align 2
gUnknown_082FB714:: @ 82FB714
	.4byte 0x00001388, 0x00000001, 0x00001f40, 0x00000002
	.4byte 0x00002ee0, 0x00000003, 0x00003e80, 0x00000004
	.4byte 0x00004e20, 0x00000005

	.align 2
gPkmnJumpPal1:: @ 82FB73C
	.incbin "graphics/link_games/pkmnjump_pal1.gbapal"

	.align 2
gPkmnJumpPal2:: @ 82FB75C
	.incbin "graphics/link_games/pkmnjump_pal2.gbapal"

	.align 2
gPkmnJumpRopeGfx1:: @ 82FB77C
	.incbin "graphics/link_games/pkmnjump_rope1.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx2:: @ 82FB89C
	.incbin "graphics/link_games/pkmnjump_rope2.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx3:: @ 82FBA70
	.incbin "graphics/link_games/pkmnjump_rope3.4bpp.lz"

	.align 2
gPkmnJumpRopeGfx4:: @ 82FBBA0
	.incbin "graphics/link_games/pkmnjump_rope4.4bpp.lz"

	.align 2
gPkmnJumpStarGfx:: @ 82FBC9C
	.incbin "graphics/link_games/pkmnjump_star.4bpp.lz"

	.align 2
gUnknown_082FBE08:: @ 82FBE08
	obj_tiles gPkmnJumpRopeGfx1, 0x0600, 0x0005

	.align 2
	obj_tiles gPkmnJumpRopeGfx2, 0x0c00, 0x0006

	.align 2
	obj_tiles gPkmnJumpRopeGfx3, 0x0600, 0x0007

	.align 2
	obj_tiles gPkmnJumpRopeGfx4, 0x0600, 0x0008

	.align 2
	obj_tiles gPkmnJumpStarGfx, 0x0200, 0x000a

	.align 2
gUnknown_082FBE30:: @ 82FBE30
	obj_pal gPkmnJumpPal1, 0x0005

	.align 2
	obj_pal gPkmnJumpPal2, 0x0006

	.align 2
gUnknown_082FBE40:: @ 82FBE40
	spr_template 0x0000, 0x0000, gUnknown_082FBEC8, gDummySpriteAnimTable, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

gUnknown_082FBE58:: @ 82FBE58
	.2byte 0x0060, 0x0060, 0x0060, 0x0072, 0x0078, 0x0078, 0x0078, 0x0072
	.2byte 0x0060, 0x0060, 0x0046, 0x0050, 0x0060, 0x0072, 0x0078, 0x0080
	.2byte 0x0078, 0x0072, 0x0060, 0x0050, 0x0032, 0x0048, 0x0060, 0x0072
	.2byte 0x0080, 0x0088, 0x0080, 0x0072, 0x0060, 0x0048, 0x002a, 0x0048
	.2byte 0x0060, 0x0072, 0x0080, 0x0088, 0x0080, 0x0072, 0x0060, 0x0048

gUnknown_082FBEA8:: @ 82FBEA8
	.2byte 0x0010, 0x0028, 0x0048, 0x0068, 0x0088, 0x00a8, 0x00c8, 0x00e0

	.align 2
gUnknown_082FBEB8:: @ 82FBEB8
	.4byte gUnknown_082FBF78
	.4byte gUnknown_082FBF90
	.4byte gUnknown_082FBFA8
	.4byte gUnknown_082FBFC0

	.align 2
gUnknown_082FBEC8:: @ 82FBED0
	.byte 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBED0:: @ 82FBED0
	.byte 0x00, 0x80, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBED8:: @ 82FBED8
	.byte 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBEE0:: @ 82FBEE0
	.byte 0x00, 0x40, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00

	.align 2
gUnknown_082FBEE8:: @ 82FBEE8
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBEF0:: @ 82FBEF0
	.2byte 0x0008, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBEF8:: @ 82FBEF8
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF00:: @ 82FBF00
	.2byte 0x0018, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF08:: @ 82FBF08
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF10:: @ 82FBF10
	.2byte 0x0028, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF18:: @ 82FBF18
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF20:: @ 82FBF20
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF28:: @ 82FBF28
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF30:: @ 82FBF30
	.2byte 0x0030, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF38:: @ 82FBF38
	.2byte 0x0040, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF40:: @ 82FBF40
	.2byte 0x0050, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBF48:: @ 82FBF48
	.4byte gUnknown_082FBEE8
	.4byte gUnknown_082FBEF0
	.4byte gUnknown_082FBEF8
	.4byte gUnknown_082FBF00
	.4byte gUnknown_082FBF08
	.4byte gUnknown_082FBF10

	.align 2
gUnknown_082FBF60:: @ 82FBF60
	.4byte gUnknown_082FBF18
	.4byte gUnknown_082FBF20
	.4byte gUnknown_082FBF28
	.4byte gUnknown_082FBF30
	.4byte gUnknown_082FBF38
	.4byte gUnknown_082FBF40

	.align 2
gUnknown_082FBF78:: @ 82FBF78
	spr_template 0x0005, 0x0005, gUnknown_082FBED0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBF90:: @ 82FBF90
	spr_template 0x0006, 0x0005, gUnknown_082FBED8, gUnknown_082FBF60, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFA8:: @ 82FBFA8
	spr_template 0x0007, 0x0005, gUnknown_082FBEE0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFC0:: @ 82FBFC0
	spr_template 0x0008, 0x0005, gUnknown_082FBEE0, gUnknown_082FBF48, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FBFD8:: @ 82FBFD8
	.byte 0x00, 0x00, 0x00, 0x40, 0x00, 0x04, 0x00, 0x00

	.align 2
gUnknown_082FBFE0:: @ 82FBFE0
	.2byte 0x0000, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FBFE8:: @ 82FBFE8
	.2byte 0x0000, 0x0004
	.2byte 0x0004, 0x0004
	.2byte 0x0008, 0x0004
	.2byte 0x000c, 0x0004
	.2byte 0xfffd, 0x0001
	.2byte 0x0000, 0x0004
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FC004:: @ 82FC004
	.4byte gUnknown_082FBFE0
	.4byte gUnknown_082FBFE8

	.align 2
gUnknown_082FC00C:: @ 82FC00C
	spr_template 0x000a, 0x0005, gUnknown_082FBFD8, gUnknown_082FC004, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gPkmnJumpPal3:: @ 82FC024
	.incbin "graphics/link_games/pkmnjump_pal3.gbapal"

	.align 2
gPkmnJumpBgPal:: @ 82FC044
	.incbin "graphics/link_games/pkmnjump_bg.gbapal"

	.align 2
gPkmnJumpBgGfx:: @ 82FC064
	.incbin "graphics/link_games/pkmnjump_bg.4bpp.lz"

	.align 2
gPkmnJumpBgTilemap:: @ 82FC290
	.incbin "graphics/link_games/pkmnjump_bg.bin.lz"

	.align 2
gPkmnJumpVenusaurPal:: @ 82FC440
	.incbin "graphics/link_games/pkmnjump_venusaur.gbapal"

	.align 2
gPkmnJumpVenusaurGfx:: @ 82FC460
	.incbin "graphics/link_games/pkmnjump_venusaur.4bpp.lz"

	.align 2
gPkmnJumpVenusaurTilemap:: @ 82FCDB0
	.incbin "graphics/link_games/pkmnjump_venusaur.bin.lz"

	.align 2
gPkmnJumpResultsPal:: @ 82FD168
	.incbin "graphics/link_games/pkmnjump_results.gbapal"

	.align 2
gPkmnJumpResultsGfx:: @ 82FD188
	.incbin "graphics/link_games/pkmnjump_results.4bpp.lz"

	.align 2
gPkmnJumpResultsTilemap:: @ 82FDC38
	.incbin "graphics/link_games/pkmnjump_results.bin.lz"

	.align 2
gUnknown_082FE164:: @ 82FE164 struct BgTemplate
	.4byte 0x000001b0, 0x000025e6, 0x000016c9, 0x000031df

	.align 2
gUnknown_082FE174:: @ 82FE174
	window_template 0x00, 0x13, 0x00, 0x06, 0x02, 0x02, 0x0013
	window_template 0x00, 0x08, 0x00, 0x06, 0x02, 0x02, 0x001f
	null_window_template

	.align 2
gUnknown_082FE18C:: @ 82FE18C
	.4byte 0x00000000, sub_802D150
	.4byte 0x00000001, sub_802D2E4
	.4byte 0x00000002, sub_802D350
	.4byte 0x00000003, sub_802D3BC
	.4byte 0x00000004, sub_802D448
	.4byte 0x00000005, sub_802D4F4
	.4byte 0x00000006, sub_802D598
	.4byte 0x00000007, sub_802D5E4
	.4byte 0x00000009, sub_802D72C
	.4byte 0x00000008, sub_802D688

	.align 2
gUnknown_082FE1DC:: @ 82FE1DC
	.byte 0x00, 0x02, 0x03

gUnknown_082FE1DF:: @ 82FE1DF
	.byte 0x02, 0x02, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00
	.byte 0x00, 0x02, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FE1EC:: @ 82FE1EC
	obj_tiles gUnknown_082FF1F8, 0x0000, 0x0320

	.align 2
gUnknown_082FE1F4:: @ 82FE1F4
	obj_pal gUnknown_082FF1D8, 0x0320

	.align 2
gUnknown_082FE1FC:: @ 82FE1FC
	.2byte 0x0006, 0x0008, 0x0010, 0x0008

	.align 2
gUnknown_082FE204:: @ 82FE204
	.2byte 0x0006, 0x0008, 0x000b, 0x0006, 0x0010, 0x0008

	.align 2
gUnknown_082FE210:: @ 82FE210
	.2byte 0x0002, 0x0006, 0x0006, 0x0008, 0x0010, 0x0008, 0x0014, 0x0006

	.align 2
gUnknown_082FE220:: @ 82FE220
	.2byte 0x0002, 0x0006, 0x0006, 0x0008, 0x000b, 0x0006
	.2byte 0x0010, 0x0008, 0x0014, 0x0006

	.align 2
gUnknown_082FE234:: @ 82FE234
	.4byte gUnknown_082FE1FC
	.4byte gUnknown_082FE204
	.4byte gUnknown_082FE210
	.4byte gUnknown_082FE220

	.align 2
gUnknown_082FE244:: @ 82FE244
	.2byte 0x0058, 0x0098

gUnknown_082FE248:: @ 82FE248
	.2byte 0x0058, 0x0078, 0x0098

gUnknown_082FE24E:: @ 82FE24E
	.2byte 0x0038, 0x0058, 0x0098, 0x00b8

gUnknown_082FE256:: @ 82FE256
	.2byte 0x0038, 0x0058, 0x0078, 0x0098, 0x00b8

	.align 2
gUnknown_082FE260:: @ 82FE260
	.4byte gUnknown_082FE244
	.4byte gUnknown_082FE248
	.4byte gUnknown_082FE24E
	.4byte gUnknown_082FE256

	.align 2
gUnknown_082FE270:: @ 82FE270
	.4byte 0x1c010100, 0x00010f09

	.align 2
gUnknown_082FE278:: @ 82FE278
	.4byte gText_JumpsInARow
	.4byte gText_BestScore2
	.4byte gText_ExcellentsInARow

	.align 2
gPkmnJump321StartPal1:: @ 82FE284
	.incbin "graphics/link_games/pkmnjump_321start1.gbapal"

	.align 2
gPkmnJump321StartGfx1:: @ 82FE2A4
	.incbin "graphics/link_games/pkmnjump_321start1.4bpp.lz"

	.align 2
gUnknown_082FE6C8:: @ 82FE6C8
	obj_tiles gPkmnJump321StartGfx1, 0x0c00, 0x2000
	null_obj_tiles

	.align 2
gUnknown_082FE6D8:: @ 82FE6D8
	obj_pal gPkmnJump321StartPal1, 0x2000
    null_obj_pal

	.align 2
gUnknown_082FE6E8:: @ 82FE6E8
	.2byte 0x0000, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE6F0:: @ 82FE6F0
	.2byte 0x0010, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE6F8:: @ 82FE6F8
	.2byte 0x0020, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE700:: @ 82FE700
	.2byte 0x0040, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE708:: @ 82FE708
	.2byte 0x0030, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE710:: @ 82FE710
	.2byte 0x0050, 0x0000
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FE718:: @ 82FE718
	.4byte gUnknown_082FE6E8
	.4byte gUnknown_082FE6F0
	.4byte gUnknown_082FE6F8
	.4byte gUnknown_082FE700
	.4byte gUnknown_082FE708
	.4byte gUnknown_082FE710

	.align 2
gUnknown_082FE730:: @ 82FE730
	spr_template 0x2000, 0x2000, gUnknown_08524914, gUnknown_082FE718, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

	.align 2
gUnknown_082FE748:: @ 82FE748
	.4byte sub_802E83C
	.4byte sub_802E8C8
	.4byte sub_802EA50
	.4byte sub_802EAB0

	.align 2
gPkmnJump321StartPal2:: @ 82FE758
	.incbin "graphics/link_games/pkmnjump_321start2.gbapal"

	.align 2
gPkmnJump321StartGfx2:: @ 82FE778
	.incbin "graphics/link_games/pkmnjump_321start2.4bpp.lz"

	.align 2
gUnknown_082FEBCC:: @ 82FEBCC
	obj_tiles gPkmnJump321StartGfx2, 0x0e00, 0x0000

	.align 2
gUnknown_082FEBD4:: @ 82FEBD4
	obj_pal gPkmnJump321StartPal2, 0x0000

	.align 2
gUnknown_082FEBDC:: @ 82FEBDC
	.byte 0x00, 0x03, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FEBE4:: @ 82FEBE4
	.byte 0x00, 0x40, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00

	.align 2
gUnknown_082FEBEC:: @ 82FEBEC
	.2byte 0x0000, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEBF4:: @ 82FEBF4
	.2byte 0x0010, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEBFC:: @ 82FEBFC
	.2byte 0x0020, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC04:: @ 82FEC04
	.4byte gUnknown_082FEBEC
	.4byte gUnknown_082FEBF4
	.4byte gUnknown_082FEBFC

	.align 2
gUnknown_082FEC10:: @ 82FEC10
	.2byte 0x0030, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC18:: @ 82FEC18
	.2byte 0x0050, 0x0001
	.2byte 0xffff, 0x0000

	.align 2
gUnknown_082FEC20:: @ 82FEC20
	.4byte gUnknown_082FEC10
	.4byte gUnknown_082FEC18

	.align 2
gUnknown_082FEC28:: @ 82FEC28
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC38:: @ 82FEC38
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x0010, 0xfff0
	.2byte 0x0800, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC50:: @ 82FEC50
	.2byte 0xffee, 0x0012
	.2byte 0x0800, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC60:: @ 82FEC60
	.2byte 0x0006, 0xfffa
	.2byte 0x0800, 0x0000
	.2byte 0xfffc, 0x0004
	.2byte 0x0800, 0x0000
	.2byte 0x0100, 0x0100
	.2byte 0x0000, 0x0000
	.2byte 0x7fff, 0x0000
	.2byte 0x0000, 0x0000

	.align 2
gUnknown_082FEC80:: @ 82FEC80
	.4byte gUnknown_082FEC28
	.4byte gUnknown_082FEC38
	.4byte gUnknown_082FEC50
	.4byte gUnknown_082FEC60

gUnknown_082FEC90:: @ 82FEC90
	spr_template 0x0000, 0x0000, gUnknown_082FEBDC, gUnknown_082FEC04, NULL, gUnknown_082FEC80, SpriteCallbackDummy

gUnknown_082FECA8:: @ 82FECA8
	spr_template 0x0000, 0x0000, gUnknown_082FEBE4, gUnknown_082FEC20, NULL, gDummySpriteAffineAnimTable, SpriteCallbackDummy

