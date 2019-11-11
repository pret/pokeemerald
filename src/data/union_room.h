// const rom data

ALIGNED(4) const u8 gText_EmptyString[] = _("");
ALIGNED(4) const u8 gText_Colon[] = _(":");
ALIGNED(4) const u8 gText_UnkCtrlCodeF907[] = _("{ID}");
ALIGNED(4) const u8 gText_PleaseStartOver[] = _("Please start over from the beginning.");
ALIGNED(4) const u8 gText_WirelessSearchCanceled[] = _("The WIRELESS COMMUNICATION\nSYSTEM search has been canceled.");
ALIGNED(4) const u8 unref_text_union_room_0[] = _("Awaiting communication\nfrom another player.");
ALIGNED(4) const u8 gText_AwaitingCommunication[] = _("{STR_VAR_1}! Awaiting\ncommunication from another player.");
ALIGNED(4) const u8 gText_AwaitingLink[] = _("{STR_VAR_1}! Awaiting link!\nPress START when everyone's ready.");
ALIGNED(4) const u8 gJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) const u8 gJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) const u8 gJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) const u8 gJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) const u8 gJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) const u8 gJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) const u8 gJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) const u8 unref_text_union_room_1[] = _("ふしぎなできごとを かいさいする");
ALIGNED(4) const u8 gJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) const u8 gJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) const u8 gJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) const u8 gJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) const u8 gJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

const u8 *const unref_text_ptrs_union_room_0[] = {
    gJPText_SingleBattle,
    gJPText_DoubleBattle,
    gJPText_MultiBattle,
    gJPText_TradePokemon,
    gJPText_Chat,
    gJPText_DistWonderCard,
    gJPText_DistWonderNews,
    gJPText_DistWonderCard,
    gJPText_HoldPokemonJump,
    gJPText_HoldBerryCrush,
    gJPText_HoldBerryPicking,
    gJPText_HoldBerryPicking,
    gJPText_HoldSpinTrade,
    gJPText_HoldSpinShop
};

const u8 gText_1PlayerNeeded[] = _("1 player\nneeded.");
const u8 gText_2PlayersNeeded[] = _("2 players\nneeded.");
const u8 gText_3PlayersNeeded[] = _("3 players\nneeded.");
const u8 gText_4PlayersNeeded[] = _("4 players\nneeded.");
const u8 gText_2PlayerMode[] = _("2-PLAYER\nMODE");
const u8 gText_3PlayerMode[] = _("3-PLAYER\nMODE");
const u8 gText_4PlayerMode[] = _("4-PLAYER\nMODE");
const u8 gText_5PlayerMode[] = _("5-PLAYER\nMODE");

const u8 *const gUnknown_082EDB60[][5] = {
    {
        gText_1PlayerNeeded,
        gText_2PlayerMode
    }, {
        gText_3PlayersNeeded,
        gText_2PlayersNeeded,
        gText_1PlayerNeeded,
        gText_4PlayerMode
    }, {
        gText_1PlayerNeeded,
        gText_2PlayerMode,
        gText_3PlayerMode,
        gText_4PlayerMode,
        gText_5PlayerMode
    }, {
        gText_2PlayersNeeded,
        gText_1PlayerNeeded,
        gText_3PlayerMode,
        gText_4PlayerMode,
        gText_5PlayerMode
    }, {
        gText_1PlayerNeeded,
        gText_2PlayerMode,
        gText_3PlayerMode,
        gText_4PlayerMode
    }
};

ALIGNED(4) const u8 gUnknown_082EDBC4[] = _("{B_BUTTON}CANCEL");
ALIGNED(4) const u8 unref_text_union_room_2[] = _("ため\nさんかしゃ ぼしゅうちゅう です！");
ALIGNED(4) const u8 gUnknown_082EDBE8[] = _("{STR_VAR_2} contacted you for\n{STR_VAR_1}. Accept?");
ALIGNED(4) const u8 gUnknown_082EDC0C[] = _("{STR_VAR_2} contacted you.\nWill you share {STR_VAR_1}?");
ALIGNED(4) const u8 gUnknown_082EDC34[] = _("{STR_VAR_2} contacted you.\nAdd to the members?");
ALIGNED(4) const u8 gUnknown_082EDC5C[] = _("{STR_VAR_1}!\nAre these members OK?");
ALIGNED(4) const u8 gUnknown_082EDC78[] = _("Cancel {STR_VAR_1} MODE\nwith these members?");
ALIGNED(4) const u8 gUnknown_082EDC9C[] = _("An “OK” was sent\nto {STR_VAR_1}.");
ALIGNED(4) const u8 gUnknown_082EDCB4[] = _("The other TRAINER doesn't appear\nto be available now…\p");
ALIGNED(4) const u8 gUnknown_082EDCEC[] = _("You can't transmit with a TRAINER\nwho is too far away.\p");
ALIGNED(4) const u8 gUnknown_082EDD24[] = _("The other TRAINER(S) is/are not\nready yet.\p");

const u8 *const gUnknown_082EDD50[] = {
    gUnknown_082EDCEC,
    gUnknown_082EDD24
};

ALIGNED(4) const u8 gUnknown_082EDD58[] = _("The {STR_VAR_1} MODE with\nthese members will be canceled.{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EDD8C[] = _("There is a member who can no\nlonger remain available.\p");

const u8 *const gUnknown_082EDDC4[] = {
    gUnknown_082EDCB4,
    gUnknown_082EDD8C
};

ALIGNED(4) const u8 gUnknown_082EDDCC[] = _("The other TRAINER appears\nunavailable…\p");
ALIGNED(4) const u8 gUnknown_082EDDF4[] = _("{STR_VAR_1} sent back an “OK”!");
ALIGNED(4) const u8 gUnknown_082EDE0C[] = _("{STR_VAR_1} OK'd your registration as\na member.");
ALIGNED(4) const u8 gUnknown_082EDE34[] = _("{STR_VAR_1} replied, “No…”\p");
ALIGNED(4) const u8 gUnknown_082EDE48[] = _("{STR_VAR_1}!\nAwaiting other members!");
ALIGNED(4) const u8 gUnknown_082EDE64[] = _("Quit being a member?");
ALIGNED(4) const u8 gUnknown_082EDE7C[] = _("You stopped being a member.\p");

const u8 *const gUnknown_082EDE9C[] = {
    NULL,
    gUnknown_082EDD8C,
    gUnknown_082EDDCC,
    NULL,
    NULL,
    NULL,
    gUnknown_082EDE34,
    NULL,
    NULL,
    gUnknown_082EDE7C
};

ALIGNED(4) const u8 gUnknown_082EDEC4[] = _("The WIRELESS COMMUNICATION\nSYSTEM link has been established.");
ALIGNED(4) const u8 gUnknown_082EDF04[] = _("The WIRELESS COMMUNICATION\nSYSTEM link has been dropped…");
ALIGNED(4) const u8 gUnknown_082EDF40[] = _("The link with your friend has been\ndropped…");
ALIGNED(4) const u8 gUnknown_082EDF6C[] = _("{STR_VAR_1} replied, “No…”");

const u8 *const gUnknown_082EDF80[] = {
    NULL,
    gUnknown_082EDF40,
    gUnknown_082EDF40,
    NULL,
    NULL,
    NULL,
    gUnknown_082EDF6C,
    NULL,
    NULL,
    NULL
};

ALIGNED(4) const u8 gUnknown_082EDFA8[] = _("Do you want the {STR_VAR_2}\nMODE?");
ALIGNED(4) const u8 gUnknown_082EDFC4[] = _("Do you want the {STR_VAR_2}\nMODE?");

const u8 *const unref_text_ptrs_union_room_1[] = {
    gUnknown_082EDFA8,
    gUnknown_082EDFC4
};

ALIGNED(4) const u8 unref_text_union_room_3[] = _("Communicating…\nPlease wait.");
ALIGNED(4) const u8 gUnknown_082EE004[] = _("Awaiting {STR_VAR_1}'s response about\nthe trade…");
ALIGNED(4) const u8 gUnknown_082EE02C[] = _("Communicating{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) const u8 gUnknown_082EE098[] = _("Communicating with {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) const u8 gUnknown_082EE104[] = _("Please wait a while{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

const u8 *const gUnknown_082EE17C[] = {
    gUnknown_082EE02C,
    gUnknown_082EE098,
    gUnknown_082EE104
};

ALIGNED(4) const u8 gUnknown_082EE188[] = _("Hiya! Is there something that you\nwanted to do?");
ALIGNED(4) const u8 gUnknown_082EE1B8[] = _("Hello!\nWould you like to do something?");
ALIGNED(4) const u8 gUnknown_082EE1E0[] = _("{STR_VAR_1}: Hiya, we meet again!\nWhat are you up for this time?");
ALIGNED(4) const u8 gUnknown_082EE218[] = _("{STR_VAR_1}: Oh! {PLAYER}, hello!\nWould you like to do something?");

const u8 *const gUnknown_082EE24C[][2] = {
    {
        gUnknown_082EE188,
        gUnknown_082EE1B8
    }, {
        gUnknown_082EE1E0,
        gUnknown_082EE218
    }
};

ALIGNED(4) const u8 gUnknown_082EE25C[] = _("Want to do something?");
ALIGNED(4) const u8 gUnknown_082EE274[] = _("Would you like to do something?");
ALIGNED(4) const u8 gUnknown_082EE294[] = _("{STR_VAR_1}: What would you like to\ndo now?");
ALIGNED(4) const u8 unref_text_union_room_4[] = _("{STR_VAR_1}: Want to do anything else?");

const u8 *const unref_text_ptrs_union_room_2[][2] = {
    {
        gUnknown_082EE25C,
        gUnknown_082EE274
    }, {
        gUnknown_082EE294,
        gUnknown_082EE294
    }
};

ALIGNED(4) const u8 sText_SomebodyHasContactedYou[] = _("Somebody has contacted you.{PAUSE 60}");
ALIGNED(4) const u8 sText_XHasContactedYou[] = _("{STR_VAR_1} has contacted you.{PAUSE 60}");

static const u8 *const gUnknown_082EE324[] = {
    sText_SomebodyHasContactedYou,
    sText_XHasContactedYou
};

ALIGNED(4) const u8 sUnionRoom_AwaitingResponseFromTrainer[] = _("Awaiting a response from\nthe other TRAINER…");
ALIGNED(4) const u8 sUnionRoom_AwaitingResponseFromX[] = _("Awaiting a response from\n{STR_VAR_1}…");

static const u8 *const sUnionRoomTexts_AwaitingResponse[] = {
    sUnionRoom_AwaitingResponseFromTrainer,
    sUnionRoom_AwaitingResponseFromX
};

ALIGNED(4) const u8 sText_ShowTrainerCard[] = _("The other TRAINER showed\nyou their TRAINER CARD.\pWould you like to show your\nTRAINER CARD?");
ALIGNED(4) const u8 sText_BattleChallenge[] = _("The other TRAINER challenges you\nto battle.\pWill you accept the battle\nchallenge?");
ALIGNED(4) const u8 sText_ChatInvitation[] = _("The other TRAINER invites you\nto chat.\pWill you accept the chat\ninvitation?");
ALIGNED(4) const u8 sText_OfferToTradeMon[] = _("There is an offer to trade your\nregistered Lv. {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}\pin exchange for a\nLv. {SPECIAL_F7 0x02} {SPECIAL_F7 0x03}.\pWill you accept this trade\noffer?");
ALIGNED(4) const u8 sText_OfferToTradeEgg[] = _("There is an offer to trade your\nregistered EGG.\lWill you accept this trade offer?");
ALIGNED(4) const u8 sText_ChatDropped[] = _("The chat has been dropped.\p");
ALIGNED(4) const u8 sText_OfferDeclined1[] = _("You declined the offer.\p");
ALIGNED(4) const u8 sText_OfferDeclined2[] = _("You declined the offer.\p");
ALIGNED(4) const u8 sText_ChatEnded[] = _("The chat was ended.\p");

// Unused
static const u8 *const sUnionRoomTexts_Invitation[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) const u8 sText_JoinChatMale[] = _("Oh, hey! We're in a chat right now.\nWant to join us?");
ALIGNED(4) const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Hey, {PLAYER}!\nWe're having a chat right now.\lWant to join us?");
ALIGNED(4) const u8 sText_JoinChatFemale[] = _("Oh, hi! We're having a chat now.\nWould you like to join us?");
ALIGNED(4) const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, hi, {PLAYER}!\nWe're having a chat now.\lWould you like to join us?");

const u8 *const sUnionRoomTexts_JoinChat[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 sText_TrainerAppearsBusy[] = _("……\nThe TRAINER appears to be busy…\p");
ALIGNED(4) const u8 gUnknown_082EE6EC[] = _("A battle, huh?\nAll right, just give me some time.");
ALIGNED(4) const u8 gUnknown_082EE720[] = _("You want to chat, huh?\nSure, just wait a little.");
ALIGNED(4) const u8 gUnknown_082EE754[] = _("Sure thing! As my “Greetings,”\nhere's my TRAINER CARD.");
ALIGNED(4) const u8 gUnknown_082EE78C[] = _("A battle? Of course, but I need\ntime to get ready.");
ALIGNED(4) const u8 gUnknown_082EE7C0[] = _("Did you want to chat?\nOkay, but please wait a moment.");
ALIGNED(4) const u8 gUnknown_082EE7F8[] = _("As my introduction, I'll show you\nmy TRAINER CARD.");

const u8 *const gUnknown_082EE82C[][4] = {
    {
        gUnknown_082EE6EC,
        gUnknown_082EE720,
        NULL,
        gUnknown_082EE754
    }, {
        gUnknown_082EE78C,
        gUnknown_082EE7C0,
        NULL,
        gUnknown_082EE7F8
    }
};

ALIGNED(4) const u8 unref_text_union_room_5[] = _("You want to chat, huh?\nSure, just wait a little.");
ALIGNED(4) const u8 gUnknown_082EE880[] = _("Thanks for waiting!\nLet's get our battle started!{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE8B8[] = _("All right!\nLet's chat!{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE8D4[] = _("Sorry I made you wait!\nLet's get started!{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE904[] = _("Sorry I made you wait!\nLet's chat.{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE92C[] = _("The trade will be started.{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE94C[] = _("The battle will be started.{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EE96C[] = _("Entering the chat…{PAUSE 60}");

const u8 *const gUnknown_082EE984[][2][3] = {
    {
        {
            gUnknown_082EE94C,
            gUnknown_082EE96C,
            gUnknown_082EE92C
        }, {
            gUnknown_082EE94C,
            gUnknown_082EE96C,
            gUnknown_082EE92C
        }
    }, {
        {
            gUnknown_082EE880,
            gUnknown_082EE8B8,
            gUnknown_082EE92C
        }, {
            gUnknown_082EE8D4,
            gUnknown_082EE904,
            gUnknown_082EE92C
        }
    }
};

ALIGNED(4) const u8 gUnknown_082EE9B4[] = _("Sorry! My POKéMON don't seem to\nbe feeling too well right now.\lLet me battle you another time.\p");
ALIGNED(4) const u8 gUnknown_082EEA14[] = _("I'm terribly sorry, but my POKéMON\naren't feeling well…\pLet's battle another time.\p");

const u8 *const gUnknown_082EEA68[] = {
    gUnknown_082EE9B4,
    gUnknown_082EEA14
};

ALIGNED(4) const u8 gUnknown_082EEA70[] = _("Huh? My TRAINER CARD…\nWhere'd it go now?\lSorry! I'll show you another time!\p");
ALIGNED(4) const u8 gUnknown_082EEAC0[] = _("Oh? Now where did I put my\nTRAINER CARD?…\lSorry! I'll show you later!\p");

const u8 *const gUnknown_082EEB08[] = {
    gUnknown_082EEA70,
    gUnknown_082EEAC0
};

ALIGNED(4) const u8 gUnknown_082EEB10[] = _("If you want to do something with\nme, just give me a shout!\p");
ALIGNED(4) const u8 gUnknown_082EEB4C[] = _("If you want to do something with\nme, don't be shy.\p");

const u8 *const gUnknown_082EEB80[] = {
    gUnknown_082EEB10,
    gUnknown_082EEB4C
};

ALIGNED(4) const u8 sText_TrainerBattleBusy[] = _("Whoops! Sorry, but I have to do\nsomething else.\lAnother time, okay?\p");
ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("If you want to battle, you need\ntwo POKéMON that are below\lLv. 30.\p");
ALIGNED(4) const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("For a battle, you need two\nPOKéMON that are below Lv. 30.\p");
ALIGNED(4) const u8 sText_DeclineBattleMale[] = _("Oh, all right.\nCome see me anytime, okay?\p");
ALIGNED(4) const u8 sText_DeclineBattleFemale[] = _("Oh…\nPlease come by anytime.\p");

const u8 *const sUnionRoomTexts_DeclineBattle[GENDER_COUNT] = {
    [MALE]  = sText_DeclineBattleMale,
    [FEMALE] = sText_DeclineBattleFemale
};

ALIGNED(4) const u8 gUnknown_082EECA4[] = _("Oh, sorry!\nI just can't right this instant.\lLet's chat another time.\p");
ALIGNED(4) const u8 gUnknown_082EECEC[] = _("Oh, I'm sorry.\nI have too much to do right now.\lLet's chat some other time.\p");

const u8 *const gUnknown_082EED3C[] = {
    gUnknown_082EECA4,
    gUnknown_082EECEC
};

ALIGNED(4) const u8 gUnknown_082EED44[] = _("Whoa!\nI can tell you're pretty tough!\p");
ALIGNED(4) const u8 gUnknown_082EED6C[] = _("You used that move?\nThat's good strategy!\p");
ALIGNED(4) const u8 gUnknown_082EED98[] = _("Way to go!\nThat was an eye-opener!\p");
ALIGNED(4) const u8 gUnknown_082EEDBC[] = _("Oh! How could you use that\nPOKéMON in that situation?\p");
ALIGNED(4) const u8 gUnknown_082EEDF4[] = _("That POKéMON…\nIt's been raised really well!\p");
ALIGNED(4) const u8 gUnknown_082EEE24[] = _("That's it!\nThis is the right move now!\p");
ALIGNED(4) const u8 gUnknown_082EEE4C[] = _("That's awesome!\nYou can battle that way?\p");
ALIGNED(4) const u8 gUnknown_082EEE78[] = _("You have exquisite timing for\nswitching POKéMON!\p");

const u8 *const gUnknown_082EEEAC[GENDER_COUNT][4] = {
    [MALE] = 
    {
        gUnknown_082EED44,
        gUnknown_082EED6C,
        gUnknown_082EED98,
        gUnknown_082EEDBC
    }, 
    [FEMALE] = 
    {
        gUnknown_082EEDF4,
        gUnknown_082EEE24,
        gUnknown_082EEE4C,
        gUnknown_082EEE78
    }
};

ALIGNED(4) const u8 gUnknown_082EEECC[] = _("Oh, I see!\nThis is educational!\p");
ALIGNED(4) const u8 gUnknown_082EEEF0[] = _("Don't say anything funny anymore!\nI'm sore from laughing!\p");
ALIGNED(4) const u8 gUnknown_082EEF2C[] = _("Oh?\nSomething like that happened.\p");
ALIGNED(4) const u8 gUnknown_082EEF50[] = _("Hmhm… What?\nSo is this what you're saying?\p");
ALIGNED(4) const u8 gUnknown_082EEF7C[] = _("Is that right?\nI didn't know that.\p");
ALIGNED(4) const u8 gUnknown_082EEFA0[] = _("Ahaha!\nWhat is that about?\p");
ALIGNED(4) const u8 gUnknown_082EEFBC[] = _("Yes, that's exactly it!\nThat's what I meant.\p");
ALIGNED(4) const u8 gUnknown_082EEFEC[] = _("In other words…\nYes! That's right!\p");

const u8 *const gUnknown_082EF010[GENDER_COUNT][4] = {
    [MALE] =
    {
        gUnknown_082EEECC,
        gUnknown_082EEEF0,
        gUnknown_082EEF2C,
        gUnknown_082EEF50
    }, 
    [FEMALE] =
    {
        gUnknown_082EEF7C,
        gUnknown_082EEFA0,
        gUnknown_082EEFBC,
        gUnknown_082EEFEC
    }
};

ALIGNED(4) const u8 gUnknown_082EF030[] = _("I'm just showing my TRAINER CARD\nas my way of greeting.\p");
ALIGNED(4) const u8 gUnknown_082EF06C[] = _("I hope I get to know you better!\p");
ALIGNED(4) const u8 gUnknown_082EF090[] = _("We're showing each other our\nTRAINER CARDS to get acquainted.\p");
ALIGNED(4) const u8 gUnknown_082EF0D0[] = _("Glad to meet you.\nPlease don't be a stranger!\p");

const u8 *const gUnknown_082EF100[GENDER_COUNT][2] = {
    [MALE] = 
    {
        gUnknown_082EF030,
        gUnknown_082EF06C
    }, 
    [FEMALE] = 
    {
        gUnknown_082EF090,
        gUnknown_082EF0D0
    }
};

ALIGNED(4) const u8 sText_MaleTraded1[] = _("Yeahah!\nI really wanted this POKéMON!\p");
ALIGNED(4) const u8 sText_MaleTraded2[] = _("Finally, a trade got me that\nPOKéMON I'd wanted a long time.\p");
ALIGNED(4) const u8 sText_FemaleTraded1[] = _("I'm trading POKéMON right now.\p");
ALIGNED(4) const u8 sText_FemaleTraded2[] = _("I finally got that POKéMON I\nwanted in a trade!\p");

const u8 *const sUnionRoomTexts_Traded[GENDER_COUNT][4] = {
    [MALE] = 
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, 
    [FEMALE] = 
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} checked the\nTRADING BOARD.\p");
ALIGNED(4) const u8 sText_RegisterMonAtTradingBoard[] = _("Welcome to the TRADING BOARD.\pYou may register your POKéMON\nand offer it up for a trade.\pWould you like to register one of\nyour POKéMON?");
ALIGNED(4) const u8 sText_TradingBoardInfo[] = _("This TRADING BOARD is used for\noffering a POKéMON for a trade.\pAll you need to do is register a\nPOKéMON for a trade.\pAnother TRAINER may offer a party\nPOKéMON in return for the trade.\pWe hope you will register POKéMON\nand trade them with many, many\lother TRAINERS.\pWould you like to register one of\nyour POKéMON?");
ALIGNED(4) const u8 sText_ThankYouForRegistering[] = _("We have registered your POKéMON for\ntrade on the TRADING BOARD.\pThank you for using this service!\p"); // unused
ALIGNED(4) const u8 sText_NobodyHasRegistered[] = _("Nobody has registered any POKéMON\nfor trade on the TRADING BOARD.\p\n"); // unused
ALIGNED(4) const u8 sText_ChooseRequestedMonType[] = _("Please choose the type of POKéMON\nthat you would like in the trade.\n");
ALIGNED(4) const u8 sText_WhichMonWillYouOffer[] = _("Which of your party POKéMON will\nyou offer in trade?\p");
ALIGNED(4) const u8 sText_RegistrationCanceled[] = _("Registration has been canceled.\p");
ALIGNED(4) const u8 sText_RegistraionCompleted[] = _("Registration has been completed.\p");
ALIGNED(4) const u8 sText_TradeCanceled[] = _("The trade has been canceled.\p");
ALIGNED(4) const u8 sText_CancelRegistrationOfMon[] = _("Cancel the registration of your\nLv. {STR_VAR_2} {STR_VAR_1}?");
ALIGNED(4) const u8 sText_CancelRegistrationOfEgg[] = _("Cancel the registration of your\nEGG?");
ALIGNED(4) const u8 sText_RegistrationCanceled2[] = _("The registration has been canceled.\p");
ALIGNED(4) const u8 sText_TradeTrainersWillBeListed[] = _("TRAINERS wishing to make a trade\nwill be listed."); // unused
ALIGNED(4) const u8 sText_ChooseTrainerToTradeWith2[] = _("Please choose the TRAINER with whom\nyou would like to trade POKéMON."); // unused
ALIGNED(4) const u8 sText_AskTrainerToMakeTrade[] = _("Would you like to ask {STR_VAR_1} to\nmake a trade?");
ALIGNED(4) const u8 sText_AwaitingResponseFromTrainer[] = _("Awaiting a response from\nthe other TRAINER…"); // unused
ALIGNED(4) const u8 sText_NotRegisteredAMonForTrade[] = _("You have not registered a POKéMON\nfor trading.\p"); // unused
ALIGNED(4) const u8 sText_DontHaveTypeTrainerWants[] = _("You don't have a {STR_VAR_2}-type\nPOKéMON that {STR_VAR_1} wants.\p");
ALIGNED(4) const u8 sText_DontHaveEggTrainerWants[] = _("You don't have an EGG that\n{STR_VAR_1} wants.\p");
ALIGNED(4) const u8 sText_CantTradeMonRightNow[] = _("{STR_VAR_1} can't make a trade for\nyour POKéMON right now.\p");
ALIGNED(4) const u8 sText_CantTradePartnersMonRightNow[] = _("You can't make a trade for\n{STR_VAR_1}'s POKéMON right now.\p");

// unused
const u8 *const sUnionRoomTexts_CantTradeRightNow[] = {
    sText_CantTradeMonRightNow,
    sText_CantTradePartnersMonRightNow
};

ALIGNED(4) const u8 sText_TradeOfferRejected[] = _("Your trade offer was rejected.\p");
ALIGNED(4) const u8 sText_EggTrade[] = _("EGG TRADE");
ALIGNED(4) const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOOSE  {A_BUTTON}JOIN  {B_BUTTON}CANCEL");
ALIGNED(4) const u8 sText_ChooseTrainer[] = _("Please choose a TRAINER.");
ALIGNED(4) const u8 sText_ChooseTrainerSingleBattle[] = _("Please choose a TRAINER for\na SINGLE BATTLE.");
ALIGNED(4) const u8 sText_ChooseTrainerDoubleBattle[] = _("Please choose a TRAINER for\na DOUBLE BATTLE.");
ALIGNED(4) const u8 sText_ChooseLeaderMultiBattle[] = _("Please choose the LEADER\nfor a MULTI BATTLE.");
ALIGNED(4) const u8 sText_ChooseTrainerToTradeWith[] = _("Please choose the TRAINER to\ntrade with.");
ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderCards[] = _("Please choose the TRAINER who is\nsharing WONDER CARDS.");
ALIGNED(4) const u8 sText_ChooseTrainerToShareWonderNews[] = _("Please choose the TRAINER who is\nsharing WONDER NEWS.");
ALIGNED(4) const u8 sText_ChooseLeaderPokemonJump[] = _("Jump with mini POKéMON!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryCrush[] = _("BERRY CRUSH!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BERRY-PICKING!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBerryBlender[] = _("BERRY BLENDER!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderRecordCorner[] = _("RECORD CORNER!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderCoolContest[] = _("COOLNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBeautyContest[] = _("BEAUTY CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderCuteContest[] = _("CUTENESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderSmartContest[] = _("SMARTNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderToughContest[] = _("TOUGHNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerLv50[] = _("BATTLE TOWER LEVEL 50!\nPlease choose the LEADER.");
ALIGNED(4) const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL!\nPlease choose the LEADER.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] = 
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNK_9]             = NULL,
    [LINK_GROUP_UNK_10]            = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) const u8 gUnknown_082EFBC8[] = _("Searching for a WIRELESS\nCOMMUNICATION SYSTEM. Wait...");
ALIGNED(4) const u8 unref_text_union_room_12[] = _("For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p");
ALIGNED(4) const u8 gUnknown_082EFC3C[] = _("Awaiting {STR_VAR_1}'s response…");
ALIGNED(4) const u8 gUnknown_082EFC54[] = _("{STR_VAR_1} has been asked to register\nyou as a member. Please wait.");
ALIGNED(4) const u8 gUnknown_082EFC90[] = _("Awaiting a response from the\nWIRELESS COMMUNICATION SYSTEM.");
ALIGNED(4) const u8 unref_text_union_room_13[] = _("Please wait for other TRAINERS to\ngather and get ready.");
ALIGNED(4) const u8 gUnknown_082EFD04[] = _("No CARDS appear to be shared \nright now.");
ALIGNED(4) const u8 gUnknown_082EFD30[] = _("No NEWS appears to be shared\nright now.");

const u8 *const gUnknown_082EFD58[] = {
    gUnknown_082EFD04,
    gUnknown_082EFD30
};

ALIGNED(4) const u8 gUnknown_082EFD60[] = _("BATTLE");
ALIGNED(4) const u8 gUnknown_082EFD68[] = _("CHAT");
ALIGNED(4) const u8 gUnknown_082EFD70[] = _("GREETINGS");
ALIGNED(4) const u8 gUnknown_082EFD7C[] = _("EXIT");
ALIGNED(4) const u8 gUnknown_082EFD84[] = _("EXIT");
ALIGNED(4) const u8 gUnknown_082EFD8C[] = _("INFO");
ALIGNED(4) const u8 gUnknown_082EFD94[] = _("NAME{CLEAR_TO 0x3C}WANTED{CLEAR_TO 0x6E}OFFER{CLEAR_TO 0xC6}LV.");
ALIGNED(4) const u8 sText_SingleBattle[] = _("SINGLE BATTLE");
ALIGNED(4) const u8 sText_DoubleBattle[] = _("DOUBLE BATTLE");
ALIGNED(4) const u8 sText_MultiBattle[] = _("MULTI BATTLE");
ALIGNED(4) const u8 sText_PokemonTrades[] = _("POKéMON TRADES");
ALIGNED(4) const u8 sText_Chat[] = _("CHAT");
ALIGNED(4) const u8 sText_Cards[] = _("CARDS");
ALIGNED(4) const u8 sText_WonderCards[] = _("WONDER CARDS");
ALIGNED(4) const u8 sText_WonderNews[] = _("WONDER NEWS");
ALIGNED(4) const u8 sText_PokemonJump[] = _("POKéMON JUMP");
ALIGNED(4) const u8 sText_BerryCrush[] = _("BERRY CRUSH");
ALIGNED(4) const u8 sText_BerryPicking[] = _("BERRY-PICKING");
ALIGNED(4) const u8 sText_Search[] = _("SEARCH");
ALIGNED(4) const u8 sText_BerryBlender[] = _("BERRY BLENDER");
ALIGNED(4) const u8 sText_RecordCorner[] = _("RECORD CORNER");
ALIGNED(4) const u8 sText_CoolContest[] = _("COOL CONTEST");
ALIGNED(4) const u8 sText_BeautyContest[] = _("BEAUTY CONTEST");
ALIGNED(4) const u8 sText_CuteContest[] = _("CUTE CONTEST");
ALIGNED(4) const u8 sText_SmartContest[] = _("SMART CONTEST");
ALIGNED(4) const u8 sText_ToughContest[] = _("TOUGH CONTEST");
ALIGNED(4) const u8 sText_BattleTowerLv50[] = _("BATTLE TOWER LV. 50");
ALIGNED(4) const u8 sText_BattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL");
ALIGNED(4) const u8 sText_ItsNormalCard[] = _("It's a NORMAL CARD.");
ALIGNED(4) const u8 sText_ItsBronzeCard[] = _("It's a BRONZE CARD!");
ALIGNED(4) const u8 sText_ItsCopperCard[] = _("It's a COPPER CARD!");
ALIGNED(4) const u8 sText_ItsSilverCard[] = _("It's a SILVER CARD!");
ALIGNED(4) const u8 sText_ItsGoldCard[] = _("It's a GOLD CARD!");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 gUnknown_082EFF64[] = _("This is {SPECIAL_F7 0x00} {SPECIAL_F7 0x01}'s\nTRAINER CARD…\l{SPECIAL_F7 0x02}\pPOKéDEX: {SPECIAL_F7 0x03}\nTIME:    {SPECIAL_F7 0x04}:{SPECIAL_F7 0x05}\p");
ALIGNED(4) const u8 gUnknown_082EFFA4[] = _("BATTLES: WINS: {SPECIAL_F7 0x00}  LOSSES: {SPECIAL_F7 0x02}\nTRADES: {SPECIAL_F7 0x03}\p“{SPECIAL_F7 0x04} {SPECIAL_F7 0x05}\n{SPECIAL_F7 0x06} {SPECIAL_F7 0x07}”\p");
ALIGNED(4) const u8 gUnknown_082EFFDC[] = _("{SPECIAL_F7 0x01}: Glad to have met you!{PAUSE 60}");
ALIGNED(4) const u8 gUnknown_082EFFFC[] = _("{SPECIAL_F7 0x01}: Glad to meet you!{PAUSE 60}");

const u8 *const gUnknown_082F0018[] = {
    gUnknown_082EFFDC,
    gUnknown_082EFFFC
};

ALIGNED(4) const u8 gUnknown_082F0020[] = _("Finished checking {SPECIAL_F7 0x01}'s\nTRAINER CARD.{PAUSE 60}");

const u8 *const gUnknown_082F0048[] = {
    gText_EmptyString,
    sText_SingleBattle,
    sText_DoubleBattle,
    sText_MultiBattle,
    sText_PokemonTrades,
    sText_Chat,
    sText_WonderCards,
    sText_WonderNews,
    sText_Cards,
    sText_PokemonJump,
    sText_BerryCrush,
    sText_BerryPicking,
    sText_Search,
    gText_EmptyString,
    sText_BattleTowerOpenLv,
    sText_RecordCorner,
    sText_BerryBlender,
    gText_EmptyString,
    gText_EmptyString,
    gText_EmptyString,
    gText_EmptyString,
    sText_WonderCards,
    sText_WonderNews,
    sText_CoolContest,
    sText_BeautyContest,
    sText_CuteContest,
    sText_SmartContest,
    sText_ToughContest,
    sText_BattleTowerLv50
};

const struct WindowTemplate gUnknown_082F00BC = {
    .bg = 0x00,
    .tilemapLeft = 0x00,
    .tilemapTop = 0x00,
    .width = 0x1E,
    .height = 0x02,
    .paletteNum = 0x0F,
    .baseBlock = 0x0008
};

const u32 gUnknown_082F00C4[NUM_LINK_GROUP_TYPES] = {
    0x0201,
    0x0202,
    0x0403,
    0x0204,
    0x2509,
    0x250a,
    0x350b,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x240f,
    0x2410,
    0x0000,
    0x2417,
    0x2418,
    0x2419,
    0x241a,
    0x241b,
    0x021c,
    0x020e
};

const struct WindowTemplate gUnknown_082F011C = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x03,
    .width = 0x0d,
    .height = 0x08,
    .paletteNum = 0x0f,
    .baseBlock = 0x0044
};

const struct WindowTemplate gUnknown_082F0124 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x03,
    .width = 0x0d,
    .height = 0x0a,
    .paletteNum = 0x0f,
    .baseBlock = 0x0044
};

const struct WindowTemplate gUnknown_082F012C = {
    .bg = 0x00,
    .tilemapLeft = 0x10,
    .tilemapTop = 0x03,
    .width = 0x07,
    .height = 0x04,
    .paletteNum = 0x0f,
    .baseBlock = 0x00c6
};

const struct ListMenuItem gUnknown_082F0134[] = {
    { gText_EmptyString, 0 },
    { gText_EmptyString, 1 },
    { gText_EmptyString, 2 },
    { gText_EmptyString, 3 },
    { gText_EmptyString, 4 }
};

const struct ListMenuTemplate gUnknown_082F015C = {
    .items = gUnknown_082F0134,
    .moveCursorFunc = NULL,
    .itemPrintFunc = sub_8013278,
    .totalItems = 5,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 1
};

const struct WindowTemplate gUnknown_082F0174 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x03,
    .width = 0x11,
    .height = 0x0a,
    .paletteNum = 0x0f,
    .baseBlock = 0x0044
};

const struct WindowTemplate gUnknown_082F017C = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x03,
    .width = 0x07,
    .height = 0x04,
    .paletteNum = 0x0f,
    .baseBlock = 0x00ee
};

const struct ListMenuItem gUnknown_082F0184[] = {
    { gText_EmptyString,  0 },
    { gText_EmptyString,  1 },
    { gText_EmptyString,  2 },
    { gText_EmptyString,  3 },
    { gText_EmptyString,  4 },
    { gText_EmptyString,  5 },
    { gText_EmptyString,  6 },
    { gText_EmptyString,  7 },
    { gText_EmptyString,  8 },
    { gText_EmptyString,  9 },
    { gText_EmptyString, 10 },
    { gText_EmptyString, 11 },
    { gText_EmptyString, 12 },
    { gText_EmptyString, 13 },
    { gText_EmptyString, 14 },
    { gText_EmptyString, 15 }
};

const struct ListMenuTemplate gUnknown_082F0204 = {
    .items = gUnknown_082F0184,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = sub_8013DF4,
    .totalItems = 16,
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate gUnknown_082F021C = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x05,
    .width = 0x10,
    .height = 0x08,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

const struct ListMenuItem gUnknown_082F0224[] = {
    { gUnknown_082EFD70, 0x208 },
    { gUnknown_082EFD60, 0x241 },
    { gUnknown_082EFD68, 0x245 },
    { gUnknown_082EFD7C, 0x040 }
};

const struct ListMenuTemplate gUnknown_082F0244 = {
    .items = gUnknown_082F0224,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 4,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate gUnknown_082F025C = {
    .bg = 0x00,
    .tilemapLeft = 0x12,
    .tilemapTop = 0x07,
    .width = 0x10,
    .height = 0x06,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

const struct ListMenuItem gUnknown_082F0264[] = {
    { gText_Register, 1 },
    { gUnknown_082EFD8C, 2 },
    { gUnknown_082EFD7C, 3 }
};

const struct ListMenuTemplate gUnknown_082F027C = {
    .items = gUnknown_082F0264,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = 3,
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate gUnknown_082F0294 = {
    .bg = 0x00,
    .tilemapLeft = 0x14,
    .tilemapTop = 0x01,
    .width = 0x10,
    .height = 0x0c,
    .paletteNum = 0x0f,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { gUnknown_082EFD7C,         NUMBER_OF_MON_TYPES }
};

const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = NUMBER_OF_MON_TYPES,
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate gUnknown_082F0344 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x01,
    .width = 0x1c,
    .height = 0x02,
    .paletteNum = 0x0d,
    .baseBlock = 0x0001
};

const struct WindowTemplate gUnknown_082F034C = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x05,
    .width = 0x1c,
    .height = 0x0c,
    .paletteNum = 0x0d,
    .baseBlock = 0x0039
};

const struct ListMenuItem gUnknown_082F0354[] = {
    { gText_EmptyString, -3 },
    { gText_EmptyString,  0 },
    { gText_EmptyString,  1 },
    { gText_EmptyString,  2 },
    { gText_EmptyString,  3 },
    { gText_EmptyString,  4 },
    { gText_EmptyString,  5 },
    { gText_EmptyString,  6 },
    { gText_EmptyString,  7 },
    { gUnknown_082EFD84,  8 }
};

const struct ListMenuTemplate gUnknown_082F03A4 = {
    .items = gUnknown_082F0354,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = sub_8017BE8,
    .totalItems = 10,
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 0,
    .fontId = 1,
    .cursorKind = 0
};

const struct WindowTemplate UnrefWindowTemplate_082F03B4 = {
    .bg = 0x00,
    .tilemapLeft = 0x01,
    .tilemapTop = 0x05,
    .width = 0x1c,
    .height = 0x0c,
    .paletteNum = 0x0d,
    .baseBlock = 0x0039
};

const struct ListMenuItem gUnknown_082F03C4[] = {
    { gText_EmptyString,  0 },
    { gText_EmptyString,  1 },
    { gText_EmptyString,  2 },
    { gText_EmptyString,  3 },
    { gText_EmptyString,  4 },
    { gText_EmptyString,  5 },
    { gText_EmptyString,  6 },
    { gText_EmptyString,  7 },
    { gText_EmptyString,  8 },
    { gText_EmptyString,  9 },
    { gText_EmptyString, 10 },
    { gText_EmptyString, 11 },
    { gText_EmptyString, 12 },
    { gText_EmptyString, 13 },
    { gText_EmptyString, 14 },
    { gText_EmptyString, 15 }
};

const struct ListMenuTemplate UnrefListMenuTemplate_082F0444 = {
    .items = gUnknown_082F03C4,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = nullsub_14,
    .totalItems = 16,
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = 1,
    .fontId = 1,
    .cursorKind = 0
};

const struct UnkStruct_Shared gUnknown_082F045C = {0};

ALIGNED(4) const u8 gUnknown_082F0474[] = {0x01, 0xff};
ALIGNED(4) const u8 gUnknown_082F0478[] = {0x02, 0xff};
ALIGNED(4) const u8 gUnknown_082F047C[] = {0x03, 0xff};
ALIGNED(4) const u8 gUnknown_082F0480[] = {0x04, 0xff};
ALIGNED(4) const u8 gUnknown_082F0484[] = {0x09, 0xff};
ALIGNED(4) const u8 gUnknown_082F0488[] = {0x0a, 0xff};
ALIGNED(4) const u8 gUnknown_082F048C[] = {0x0b, 0xff};
ALIGNED(4) const u8 gUnknown_082F0490[] = {0x15, 0xff};
ALIGNED(4) const u8 gUnknown_082F0494[] = {0x16, 0xff};
ALIGNED(4) const u8 gUnknown_082F0498[] = {0x40, 0x41, 0x44, 0x45, 0x48, 0x51, 0x52, 0x53, 0x54, 0xff};
ALIGNED(4) const u8 gUnknown_082F04A4[] = {0x0c, 0xff};
ALIGNED(4) const u8 gUnknown_082F04A8[] = {0x01, 0x02, 0x03, 0x04, 0x09, 0x0a, 0x0b, 0x15, 0x16, 0x0d, 0xff};
ALIGNED(4) const u8 gUnknown_082F04B4[] = {0x0f, 0xff};
ALIGNED(4) const u8 gUnknown_082F04B8[] = {0x10, 0xff};
ALIGNED(4) const u8 gUnknown_082F04BC[] = {0x17, 0xff};
ALIGNED(4) const u8 gUnknown_082F04C0[] = {0x18, 0xff};
ALIGNED(4) const u8 gUnknown_082F04C4[] = {0x19, 0xff};
ALIGNED(4) const u8 gUnknown_082F04C8[] = {0x1a, 0xff};
ALIGNED(4) const u8 gUnknown_082F04CC[] = {0x1b, 0xff};
ALIGNED(4) const u8 gUnknown_082F04D0[] = {0x1c, 0xff};
ALIGNED(4) const u8 gUnknown_082F04D4[] = {0x0e, 0xff};

const u8 *const gUnknown_082F04D8[NUM_LINK_GROUP_TYPES] = {
    gUnknown_082F0474,
    gUnknown_082F0478,
    gUnknown_082F047C,
    gUnknown_082F0480,
    gUnknown_082F0484,
    gUnknown_082F0488,
    gUnknown_082F048C,
    gUnknown_082F0490,
    gUnknown_082F0494,
    gUnknown_082F0498,
    gUnknown_082F04A4,
    gUnknown_082F04A8,
    gUnknown_082F04B4,
    gUnknown_082F04B8,
    NULL,
    gUnknown_082F04BC,
    gUnknown_082F04C0,
    gUnknown_082F04C4,
    gUnknown_082F04C8,
    gUnknown_082F04CC,
    gUnknown_082F04D0,
    gUnknown_082F04D4
};

// Link group type to ID for gUnknown_02022C2C
const u8 gUnknown_082F0530[NUM_LINK_GROUP_TYPES + 2] = 
{
    0x01, 
    0x02, 
    0x03, 
    0x04, 
    0x09, 
    0x0a, 
    0x0b, 
    0x15,
    0x16, 
    0x00, 
    0x00, 
    0x00, 
    0x0f, 
    0x10, 
    0x00, 
    0x17,
    0x18, 
    0x19, 
    0x1a, 
    0x1b, 
    0x1c, 
    0x0e
};
