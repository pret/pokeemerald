ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
#if FRENCH
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Veuillez recommencer depuis le début.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("La recherche de la COMMUNICATION\nSANS FIL a été annulée.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Awaiting communication\nfrom another player."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Attente \nd’un autre joueur.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Attente de\nlink! App. sur START une fois prêts.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Inizia daccapo.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("SISTEMA COMUNICAZIONE WIRELESS:\nla ricerca è stata annullata.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Awaiting communication\nfrom another player.");
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! In attesa di\ncomunicazione da altro giocatore.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Quando siete\ntutti pronti, premi START.");
#else //ENGLISH
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Please start over from the beginning.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("The WIRELESS COMMUNICATION\nSYSTEM search has been canceled.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("Awaiting communication\nfrom another player."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1}! Awaiting\ncommunication from another player.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Awaiting link!\nPress START when everyone's ready.");
#endif
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

#if FRENCH
static const u8 sText_1PlayerNeeded[] = _("Manque\n1 J.");
static const u8 sText_2PlayersNeeded[] = _("Manque\n2 J.");
static const u8 sText_3PlayersNeeded[] = _("Manque\n3 J.");
static const u8 sText_4PlayersNeeded[] = _("4 players\nneeded."); // Unused
static const u8 sText_2PlayerMode[] = _("MODE\n2 JOUEURS");
static const u8 sText_3PlayerMode[] = _("MODE\n3 JOUEURS");
static const u8 sText_4PlayerMode[] = _("MODE\n4 JOUEURS");
static const u8 sText_5PlayerMode[] = _("MODE\n5 JOUEURS");
#elif ITALIAN
static const u8 sText_1PlayerNeeded[] = _("Manca 1\ngiocatore.");
static const u8 sText_2PlayersNeeded[] = _("Mancano 2\ngiocatori.");
static const u8 sText_3PlayersNeeded[] = _("Mancano 3\ngiocatori.");
static const u8 sText_4PlayersNeeded[] = _("4 players\nneeded."); // Unused
static const u8 sText_2PlayerMode[] = _("MODALITÀ\n2 GIOC.");
static const u8 sText_3PlayerMode[] = _("MODALITÀ\n3 GIOC.");
static const u8 sText_4PlayerMode[] = _("MODALITÀ\n4 GIOC.");
static const u8 sText_5PlayerMode[] = _("MODALITÀ\n5 GIOC.");
#else //ENGLISH
static const u8 sText_1PlayerNeeded[] = _("1 player\nneeded.");
static const u8 sText_2PlayersNeeded[] = _("2 players\nneeded.");
static const u8 sText_3PlayersNeeded[] = _("3 players\nneeded.");
static const u8 sText_4PlayersNeeded[] = _("4 players\nneeded."); // Unused
static const u8 sText_2PlayerMode[] = _("2-PLAYER\nMODE");
static const u8 sText_3PlayerMode[] = _("3-PLAYER\nMODE");
static const u8 sText_4PlayerMode[] = _("4-PLAYER\nMODE");
static const u8 sText_5PlayerMode[] = _("5-PLAYER\nMODE");
#endif

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}RETOUR");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} vous contacte pour:\n{STR_VAR_1}.\lAccepter?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} vous a contacté.\nPartager {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} vous a contacté.\nL’ajouter aux membres?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nOK avec ces membres?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Annuler le MODE\n{STR_VAR_1}\lavec ces membres?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("“OK” a été envoyé\nà {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("L’autre DRESSEUR ne semble\npas être disponible…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Transmission impossible avec\nun DRESSEUR trop éloigné.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Tous les DRESSEURS\nne sont pas prêts.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}ESCI");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} ti ha contattato per\n“{STR_VAR_1}”. Accetti?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} ti ha contattato.\nCondividi le {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} ti ha contattato.\nAggiungi ai partecipanti?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nVanno bene questi partecipanti?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Annulli MODALITÀ {STR_VAR_1}\ncon questi partecipanti?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("Inviato “OK”\na {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("L’altro ALLENATORE non è\ndisponibile al momento.\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Non puoi comunicare con un\nALLENATORE troppo distante.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("L’altro ALLENATORE o gli altri\nALLENATORI non sono disponibili.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}CANCEL");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} contacted you for\n{STR_VAR_1}. Accept?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} contacted you.\nWill you share {STR_VAR_1}?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} contacted you.\nAdd to the members?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1}!\nAre these members OK?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Cancel {STR_VAR_1} MODE\nwith these members?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("An “OK” was sent\nto {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("The other TRAINER doesn't appear\nto be available now…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("You can't transmit with a TRAINER\nwho is too far away.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("The other TRAINER(S) is/are not\nready yet.\p");
#endif

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

#if FRENCH
ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("Le MODE {STR_VAR_1}\navec ces membres va être annulé.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Un des membres ne sera\nbientôt plus disponible.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("La MODALITÀ {STR_VAR_1} con\nquesti partecipanti sarà annullata.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Uno dei partecipanti non può\ncontinuare.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("The {STR_VAR_1} MODE with\nthese members will be canceled.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("There is a member who can no\nlonger remain available.\p");
#endif

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

#if FRENCH
ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("L’autre DRESSEUR est\nindisponible…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} renvoie un “OK”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} vous accepte comme\nmembre.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} répond “Non…”.\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nAttente d’autres membres!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Se désinscrire?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Vous n’êtes plus membre.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("L’altro ALLENATORE non è\ndisponibile.\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} ha risposto con un\n“OK”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} ti ha accettato tra i\npartecipanti.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} ha risposto con un\n“no”!\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nIn attesa di altri partecipanti…");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Vuoi uscire?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Non sei più tra i partecipanti.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("The other TRAINER appears\nunavailable…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} sent back an “OK”!");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} OK'd your registration as\na member.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} replied, “No…”\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nAwaiting other members!");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Quit being a member?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("You stopped being a member.\p");
#endif

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

#if FRENCH
ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("Le réseau de COMMUNICATION SANS\nFIL a été établi.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("Le réseau de COMMUNICATION SANS\nFIL a été interrompu.");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Le link avec votre ami a été\ninterrompu…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} répond “Non…”.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("Stabilito collegamento SISTEMA\nCOMUNICAZIONE WIRELESS.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("Interrotto collegamento SISTEMA\nCOMUNICAZIONE WIRELESS.");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("Il collegamento è stato interrotto.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} ha risposto\ncon un “no”…");
#else //ENGLISH
ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("The WIRELESS COMMUNICATION\nSYSTEM link has been established.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("The WIRELESS COMMUNICATION\nSYSTEM link has been dropped…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("The link with your friend has been\ndropped…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} replied, “No…”");
#endif

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

#if FRENCH
ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Voulez-vous le MODE\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Voulez-vous le MODE\n{STR_VAR_2}?");
#elif ITALIAN
ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Vuoi la MODALITÀ\n{STR_VAR_2}?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Vuoi la MODALITÀ\n{STR_VAR_2}?");
#else //ENGLISH
ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Do you want the {STR_VAR_2}\nMODE?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Do you want the {STR_VAR_2}\nMODE?");
#endif

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Communicating…\nPlease wait."); // Unused
#if FRENCH
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _(
    "Attente d’une réponse de {STR_VAR_1}\n"
    "pour l’échange…");
ALIGNED(4) static const u8 sText_Communicating[] = _(
    "Communication en cours{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _(
    "Communication avec {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _(
    "Patienter un instant{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _(
    "In attesa di risposta da {STR_VAR_1}\n"
    "sullo scambio…");
ALIGNED(4) static const u8 sText_Communicating[] = _(
    "Comunicazione in corso{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _(
    "Comunicazione con {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _(
    "Attendi{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
#else //ENGLISH
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _(
    "Awaiting {STR_VAR_1}'s response about\n"
    "the trade…");
ALIGNED(4) static const u8 sText_Communicating[] = _(
    "Communicating{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _(
    "Communicating with {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _(
    "Please wait a while{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
    "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
#endif

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

#if FRENCH
ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Salut! Vous vouliez quelque chose?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Bonjour jeune fille.\nJe peux vous aider?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Content de vous revoir!\nQu’est-ce que ça sera cette fois?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! Bonjour, {PLAYER}!\nVous désirez quelque chose?");
#elif ITALIAN
ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Ciao! Che cosa vuoi fare?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Ehi, ciao! Che cosa vuoi fare?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Ciao, ci si rincontra!\nCosa vuoi fare questa volta?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Ciao, {PLAYER}!\nChe cosa vuoi fare?");
#else //ENGLISH
ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Hiya! Is there something that you\nwanted to do?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Hello!\nWould you like to do something?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Hiya, we meet again!\nWhat are you up for this time?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! {PLAYER}, hello!\nWould you like to do something?");
#endif

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};
#if FRENCH
ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Quelque chose vous tente?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Vous désirez quelque chose?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Qu’est-ce que vous\nvoulez faire maintenant?");
#elif ITALIAN
ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Che cosa vuoi fare?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Che cosa vuoi fare?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Che cosa vuoi fare ora?");
#else //ENGLISH
ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Want to do something?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Would you like to do something?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: What would you like to\ndo now?");
#endif
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}: Want to do anything else?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Quelqu’un vous contacte.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} essaie de vous contacter.{PAUSE 60}");
#elif ITALIAN
ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Qualcuno ti ha contattato.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} ti ha contattato.{PAUSE 60}");
#else //ENGLISH
ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Somebody has contacted you.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} has contacted you.{PAUSE 60}");
#endif

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

#if FRENCH
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("En attente d’une réponse de\nl’autre DRESSEUR…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("En attente d’une réponse de\n{STR_VAR_1}…");
#elif ITALIAN
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("In attesa di risposta\ndall’altro ALLENATORE…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("In attesa di risposta\nda {STR_VAR_1}…");
#else //ENGLISH
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Awaiting a response from\nthe other TRAINER…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("Awaiting a response from\n{STR_VAR_1}…");
#endif

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

#if FRENCH
ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("L’autre DRESSEUR vous montre\nsa CARTE DE DRESSEUR.\pVoulez-vous montrer votre\nCARTE DE DRESSEUR?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("L’autre DRESSEUR veut se\nbattre contre vous.\pAccepter le combat?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("L’autre DRESSEUR vous invite\nà discuter.\pAccepter l’invitation?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Il y a une offre d’échange pour\nvotre {DYNAMIC 1} de N. {DYNAMIC 0}\pcontre un\n{DYNAMIC 3} de N. {DYNAMIC 2}.\pAccepter l’échange?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Il y a une offre d’échange pour\nvotre OEUF enregistré.\lAccepter l’offre d’échange?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("La communication est abandonnée.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Vous déclinez l’offre.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("L’offre est déclinée.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Le tchat est terminé.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("L’altro ALLENATORE ti ha mostrato\nla sua SCHEDA ALLENATORE.\pVuoi mostrargli la tua SCHEDA\nALLENATORE?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("L’altro ALLENATORE ti sfida\na lottare.\pAccetti la sfida?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("L’altro ALLENATORE ti invita\na chattare.\pAccetti l’invito?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Ricevuta offerta di scambio: il tuo\n{DYNAMIC 1} di L. {DYNAMIC 0} registrato\pper {DYNAMIC 3} di L. {DYNAMIC 2}.\pAccetti l’offerta?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Ricevuta offerta di scambio\nper il tuo UOVO registrato.\lAccetti l’offerta?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Il contatto è stato interrotto.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Hai rifiutato l’offerta.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Hai rifiutato l’offerta.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("Il contatto è stato rifiutato.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("The other TRAINER showed\nyou their TRAINER CARD.\pWould you like to show your\nTRAINER CARD?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("The other TRAINER challenges you\nto battle.\pWill you accept the battle\nchallenge?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("The other TRAINER invites you\nto chat.\pWill you accept the chat\ninvitation?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("There is an offer to trade your\nregistered Lv. {DYNAMIC 0} {DYNAMIC 1}\pin exchange for a\nLv. {DYNAMIC 2} {DYNAMIC 3}.\pWill you accept this trade\noffer?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("There is an offer to trade your\nregistered EGG.\lWill you accept this trade offer?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("The chat has been dropped.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("You declined the offer.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("You declined the offer.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("The chat was ended.\p");
#endif

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

#if FRENCH
ALIGNED(4) static const u8 sText_JoinChatMale[] = _("On est en plein dans un tchat.\nTu nous rejoins?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Salut, {PLAYER}!\nOn est en train de tchater.\lTu veux nous rejoindre?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Bonjour! On est en plein tchat.\nTu nous rejoins?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, coucou, {PLAYER}!\nNous sommes en train de tchater.\lTu te joins à nous?");
#elif ITALIAN
ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Ehi, ciao! Siamo in chat!\nVuoi partecipare?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Ehi, {PLAYER}!\nSiamo in chat!\lVuoi partecipare?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Ciao! Siamo in chat!\nVuoi partecipare?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Ciao, {PLAYER}!\nSiamo in chat!\lVuoi partecipare?");
#else //ENGLISH
ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Oh, hey! We're in a chat right now.\nWant to join us?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Hey, {PLAYER}!\nWe're having a chat right now.\lWant to join us?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Oh, hi! We're having a chat now.\nWould you like to join us?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, hi, {PLAYER}!\nWe're having a chat now.\lWould you like to join us?");
#endif

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nLe DRESSEUR est occupé…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Un combat, hein?\nTrès bien, juste un instant.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Un tchat?\nPas de problème, juste un instant.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Pareil pour moi!\nVoilà ma CARTE DE DRESSEUR.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Un combat? Bien sûr!\nJuste un instant, je me prépare.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Un tchat?\nPas de problème, juste un instant.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("On se présente?\nVoilà ma CARTE DE DRESSEUR.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nL’ALLENATORE è\loccupato…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Una lotta?\nVa bene! Dammi solo un momento!");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Vuoi chattare?\nBenissimo! Dammi solo un momento!");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Senz’altro! Eccoti la mia SCHEDA\nALLENATORE, come saluto!");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Una lotta?\nVa bene! Aspetta solo un momento!");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Vuoi chattare?\nOK, aspetta un momento.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Per presentarmi ti mostro la\nmia SCHEDA ALLENATORE!");
#else //ENGLISH
ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nThe TRAINER appears to be busy…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("A battle, huh?\nAll right, just give me some time.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("You want to chat, huh?\nSure, just wait a little.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Sure thing! As my “Greetings,”\nhere's my TRAINER CARD.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("A battle? Of course, but I need\ntime to get ready.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Did you want to chat?\nOkay, but please wait a moment.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("As my introduction, I'll show you\nmy TRAINER CARD.");
#endif

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("You want to chat, huh?\nSure, just wait a little."); // Unused
#if FRENCH
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Merci d’avoir patienté!\nAllez, commençons le combat!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Parfait!\nCommençons le tchat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Tu n’as pas trop attendu?\nCommençons!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Tu n’as pas trop attendu?\nCommençons le tchat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("L’échange va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Le combat va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Début du tchat…{PAUSE 60}");
#elif ITALIAN
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Scusa, t’ho fatto attendere!\nDiamo inizio alla lotta!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Bene!\nDai, chattiamo un po’!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Scusa, t’ho fatto attendere.\nDai, iniziamo!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Scusa, t’ho fatto attendere.\nDai, chattiamo!{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Ha inizio lo scambio.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Ha inizio la lotta.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Ha inizio la chat.{PAUSE 60}");
#else //ENGLISH
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Thanks for waiting!\nLet's get our battle started!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("All right!\nLet's chat!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Sorry I made you wait!\nLet's get started!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Sorry I made you wait!\nLet's chat.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("The trade will be started.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("The battle will be started.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Entering the chat…{PAUSE 60}");
#endif

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Dommage! Mes POKéMON ne sont\npas vraiment en forme.\lJe t’écraserai une prochaine fois.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Je suis désolée, mais mes POKéMON\nne se sentent pas bien…\pBattons-nous une prochaine fois!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Scusa, ma i miei POKéMON non si\nsentono molto bene al momento.\lLotteremo un’altra volta!\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Mi spiace, ma i miei POKéMON non\nsi sentono bene in questo momento.\lSarà per un’altra volta!\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Sorry! My POKéMON don't seem to\nbe feeling too well right now.\lLet me battle you another time.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("I'm terribly sorry, but my POKéMON\naren't feeling well…\pLet's battle another time.\p");
#endif

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};
#if FRENCH
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Hein? Ma CARTE DE DRESSEUR…\nJ’l’ai mise où?\lTant pis, la prochaine fois alors!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh! Mais où est passée ma\nCARTE DE DRESSEUR?\lDésolée! La prochaine fois alors!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Dov’è finita la mia SCHEDA\nALLENATORE?! Scusa, te la\lmostrerò un’altra volta.\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Ma dove avrò messo la mia SCHEDA\nALLENATORE?! Scusa ma non\lte la posso mostrare.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Huh? My TRAINER CARD…\nWhere'd it go now?\lSorry! I'll show you another time!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh? Now where did I put my\nTRAINER CARD?…\lSorry! I'll show you later!\p");
#endif


static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

#if FRENCH
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Si tu as besoin de moi,\nfais-moi signe!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Si tu veux faire un truc, n’hésite\npas à demander.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Se hai bisogno di aiuto,\nfammi un fischio.\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Se hai bisogno di me,\nsai dove trovarmi.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("If you want to do something with\nme, just give me a shout!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("If you want to do something with\nme, don't be shy.\p");
#endif

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

#if FRENCH
ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Oups! Dommage, j’ai autre \nchose à faire.\lUne autre fois, OK?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Si tu veux te battre, il te faut\ndeux POKéMON de niveau\linférieur à 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Pour combattre, il te faut deux\nPOKéMON de niveau inférieur\là 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Bon, OK.\nA la prochaine alors.\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nA la prochaine alors.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Scusa ma ho qualcos’altro da\nfare. Sarà per la prossima volta!\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Per lottare, devi avere due\nPOKéMON sotto il L. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Puoi lottare se hai due\nPOKéMON sotto il L. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Oh… va bene.\nTorna a trovarmi quando vuoi!\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh… beh, torna\nquando vuoi!\p");

#else //ENGLISH
ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Whoops! Sorry, but I have to do\nsomething else.\lAnother time, okay?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("If you want to battle, you need\ntwo POKéMON that are below\lLv. 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("For a battle, you need two\nPOKéMON that are below Lv. 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Oh, all right.\nCome see me anytime, okay?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nPlease come by anytime.\p");
#endif

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

#if FRENCH
ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Bon…\nC’est pas vraiment le moment.\lOn tchatera une prochaine fois.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Vraiment navrée.\nJ’ai plein de choses à faire.\lCe sera pour la prochaine fois.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Scusa ma non posso in questo\nmomento.\lChatteremo un’altra volta.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Scusa, in questo momento non\nposso proprio. Avremo altre\loccasioni per chattare.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Oh, sorry!\nI just can't right this instant.\lLet's chat another time.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Oh, I'm sorry.\nI have too much to do right now.\lLet's chat some other time.\p");
#endif

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

#if FRENCH
ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Waouh!\nT’en as dans le ventre!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("T’as utilisé cette capacité?\nBonne stratégie!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Voilà!\nC’est comme ça qu’y faut faire!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! C’est pas le bon moment\npour utiliser ce POKéMON!\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Ce POKéMON…\nIl est super bien dressé!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("C’est ça!\nC’est la bonne capacité!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Incroyable!\nTu peux te battre comme ça?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Tu sais vraiment changer de\nPOKéMON au bon moment!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Ti ho visto: sei forte!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Ho visto la mossa che hai\nusato!\lGrande strategia!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Così si fa!\nSei stupefacente!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Come fai a guidare così bene\ni tuoi POKéMON nella lotta?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Quel tuo POKéMON…\nè davvero notevole!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("Proprio la mossa giusta!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Incredibile!\nCome fai a lottare in quel modo?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Sai perfettamente quando sostituire\ni POKéMON!\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Whoa!\nI can tell you're pretty tough!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("You used that move?\nThat's good strategy!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Way to go!\nThat was an eye-opener!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! How could you use that\nPOKéMON in that situation?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("That POKéMON…\nIt's been raised really well!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("That's it!\nThis is the right move now!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("That's awesome!\nYou can battle that way?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("You have exquisite timing for\nswitching POKéMON!\p");
#endif

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, je vois!\nC’était plutôt instructif!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Ne dis plus rien! J’ai des crampes\nà force de rire!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nC’est vraiment arrivé?\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hm… Quoi?\nSi tu le dis…\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Vraiment?\nJe savais pas.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nVraiment?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Oui, c’est ça!\nC’est ce que je voulais dire.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("En d’autres termes…\nOui, c’est ça!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Ah, davvero? Non lo sapevo!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Sei troppo divertente! Mi sto\nsbellicando dalle risate!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Eh?\nNon ci credo!\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Dici davvero?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Ma va’?\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Non ho capito. Puoi ripetere?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Mi hai tolto le parole di bocca!\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Certo! Hai ragione!\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, I see!\nThis is educational!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Don't say anything funny anymore!\nI'm sore from laughing!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nSomething like that happened.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… What?\nSo is this what you're saying?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Is that right?\nI didn't know that.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nWhat is that about?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Yes, that's exactly it!\nThat's what I meant.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("In other words…\nYes! That's right!\p");
#endif

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Je montre toujours ma CARTE DE\nDRESSEUR pour me présenter.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("J’espère qu’on apprendra à se\nconnaître!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("On se présente notre CARTE DE\nDRESSEUR pour faire connaissance.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("On va bien s’entendre.\nJe le sens!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Questa è la mia SCHEDA\nALLENATORE, per presentarmi.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Spero che faremo amicizia!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Mostriamoci le SCHEDE ALLENATORE,\ncosì ci conosciamo!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Piacere di conoscerti.\nDico davvero!\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("I'm just showing my TRAINER CARD\nas my way of greeting.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("I hope I get to know you better!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("We're showing each other our\nTRAINER CARDS to get acquainted.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Glad to meet you.\nPlease don't be a stranger!\p");
#endif

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Cool! \nJe le voulais vraiment ce POKéMON!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Finalement, j’obtiens ce\nPOKéMON grâce à un échange.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Je suis en train de faire\nun échange.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("C’est le POKéMON que je voulais\ntellement!\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Grandioso!\nProprio il POKéMON che volevo!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Era tanto che volevo ottenere\nquesto POKéMON! Ottimo scambio!\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Sto facendo uno scambio di\nPOKéMON.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Ecco il POKéMON che cercavo!\nSono felice dello scambio!\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Yeahah!\nI really wanted this POKéMON!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Finally, a trade got me that\nPOKéMON I'd wanted a long time.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("I'm trading POKéMON right now.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("I finally got that POKéMON I\nwanted in a trade!\p");
#endif

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

#if FRENCH
ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _(
    "{STR_VAR_1} vérifie le\n"
    "PANNEAU D’ECHANGE.\p");

ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _(
    "Bienvenue au PANNEAU D’ECHANGE.\p"
    "Vous pouvez enregistrer vos\n"
    "POKéMON pour un échange.\p"
    "Voulez-vous enregistrer un de vos\n"
    "POKéMON?");

ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _(
    "Ce PANNEAU D’ECHANGE sert aux\n"
    "échanges de POKéMON.\p"
    "Tout ce que vous devez faire c’est\n"
    "enregistrer un POKéMON avant.\p"
    "Un autre DRESSEUR peut offrir un\n"
    "POKéMON de son équipe en retour.\p"
    "Nous espérons que vous échangerez\n"
    "vos POKéMON avec le plus de \l"
    "DRESSEURS possible.\p"
    "Voulez-vous enregistrer un de vos\n"
    "POKéMON?");

// Unused
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _(
    "We have registered your POKéMON for\n"
    "trade on the TRADING BOARD.\p"
    "Thank you for using this service!\p");

// Unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _(
    "Nobody has registered any POKéMON\n"
    "for trade on the TRADING BOARD.\p\n");

ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _(
    "Choisissez le type de POKéMON\n"
    "que vous voulez pour l’échange.\n");

ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _(
    "Quel POKéMON de votre équipe\n"
    "voulez-vous échanger?\p");

ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("L’enregistrement a été annulé.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("L’enregistrement est terminé.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("L’échange a été annulé.\p");

ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _(
    "Annuler l’enregistrement de votre\n"
    "{STR_VAR_1} de N. {STR_VAR_2}?");

ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _(
    "Annuler l’enregistrement de votre\n"
    "OEUF?");

ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("L’enregistrement a été annulé.\p");

// Unused
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _(
    "TRAINERS wishing to make a trade\n"
    "will be listed.");

// Unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _(
    "Please choose the TRAINER with whom\n"
    "you would like to trade POKéMON.");

ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _(
    "Voulez-vous demander à {STR_VAR_1}\n"
    "de faire un échange?");

// Unused
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _(
    "Awaiting a response from\n"
    "the other TRAINER…");

// Unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _(
    "You have not registered a POKéMON\n"
    "for trading.\p");

ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _(
    "Vous n’avez pas de POKéMON\n"
    "du type {STR_VAR_2}\p"
    "que veut {STR_VAR_1}.\p");

ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _(
    "Vous n’avez pas l’OEUF que veut\n"
    "{STR_VAR_1}.\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _(
    "{STR_VAR_1} ne peut pas faire d’échange\n"
    "pour votre POKéMON maintenant.\p");

ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _(
    "Vous ne pouvez pas échanger le\n"
    "POKéMON de {STR_VAR_1} maintenant.\p");
#elif ITALIAN
ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} visita\nl’AREA SCAMBI.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Questa è l’AREA SCAMBI.\pQui puoi registrare i tuoi POKéMON,\noffrendoli per uno scambio.\pVuoi registrare uno dei tuoi\nPOKéMON?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("Nell’AREA SCAMBI si può offrire un\nPOKéMON per uno scambio.\pNon devi fare altro che registrare\nil POKéMON che vuoi scambiare.\pUn altro ALLENATORE potrebbe\noffrire uno dei suoi POKéMON per\llo scambio.\pSperiamo che tu possa fare\ntantissimi scambi in questo\lmodo!\pVuoi registrare uno dei tuoi\nPOKéMON?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("We have registered your POKéMON for\ntrade on the TRADING BOARD.\pThank you for using this service!\p");
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Nobody has registered any POKéMON\nfor trade on the TRADING BOARD.\p\n");
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Scegli il tipo del POKéMON che\ncerchi.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Quale POKéMON della tua squadra\nvuoi offrire per uno scambio?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("La registrazione è stata annullata.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("La registrazione è stata\ncompletata.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("Lo scambio è stato annullato.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Annulli la registrazione di\n{STR_VAR_1} di L. {STR_VAR_2}?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Annulli la registrazione\ndell’UOVO?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("La registrazione è stata annullata.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("TRAINERS wishing to make a trade\nwill be listed.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Please choose the TRAINER with whom\nyou would like to trade POKéMON.");
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Vuoi chiedere a {STR_VAR_1} di fare\nuno scambio?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("Awaiting a response from\nthe other TRAINER…");
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("You have not registered a POKéMON\nfor trading.\p");
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("{STR_VAR_1} cerca un POKéMON di tipo\n{STR_VAR_2}, che tu non hai.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("{STR_VAR_1} cerca un UOVO, che tu non\nhai.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} non può fare uno scambio\nper il tuo POKéMON al momento.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Non puoi fare uno scambio per\nil POKéMON di {STR_VAR_1} al momento.\p");
#else //ENGLISH
ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _(
    "{STR_VAR_1} checked the\n"
    "TRADING BOARD.\p");

ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _(
    "Welcome to the TRADING BOARD.\p"
    "You may register your POKéMON\n"
    "and offer it up for a trade.\p"
    "Would you like to register one of\n"
    "your POKéMON?");

ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _(
    "This TRADING BOARD is used for\n"
    "offering a POKéMON for a trade.\p"
    "All you need to do is register a\n"
    "POKéMON for a trade.\p"
    "Another TRAINER may offer a party\n"
    "POKéMON in return for the trade.\p"
    "We hope you will register POKéMON\n"
    "and trade them with many, many\l"
    "other TRAINERS.\p"
    "Would you like to register one of\n"
    "your POKéMON?");

// Unused
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _(
    "We have registered your POKéMON for\n"
    "trade on the TRADING BOARD.\p"
    "Thank you for using this service!\p");

// Unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _(
    "Nobody has registered any POKéMON\n"
    "for trade on the TRADING BOARD.\p\n");

ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _(
    "Please choose the type of POKéMON\n"
    "that you would like in the trade.\n");

ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _(
    "Which of your party POKéMON will\n"
    "you offer in trade?\p");

ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("Registration has been canceled.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("Registration has been completed.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("The trade has been canceled.\p");

ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _(
    "Cancel the registration of your\n"
    "Lv. {STR_VAR_2} {STR_VAR_1}?");

ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _(
    "Cancel the registration of your\n"
    "EGG?");

ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("The registration has been canceled.\p");

// Unused
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _(
    "TRAINERS wishing to make a trade\n"
    "will be listed.");

// Unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _(
    "Please choose the TRAINER with whom\n"
    "you would like to trade POKéMON.");

ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _(
    "Would you like to ask {STR_VAR_1} to\n"
    "make a trade?");

// Unused
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _(
    "Awaiting a response from\n"
    "the other TRAINER…");

// Unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _(
    "You have not registered a POKéMON\n"
    "for trading.\p");

ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _(
    "You don't have a {STR_VAR_2}-type\n"
    "POKéMON that {STR_VAR_1} wants.\p");

ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _(
    "You don't have an EGG that\n"
    "{STR_VAR_1} wants.\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _(
    "{STR_VAR_1} can't make a trade for\n"
    "your POKéMON right now.\p");

ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _(
    "You can't make a trade for\n"
    "{STR_VAR_1}'s POKéMON right now.\p");

#endif

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

#if FRENCH
ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Votre offre d’échange a\nété refusée.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("ECHANGE D’OEUF");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOISIR  {A_BUTTON}JOINDRE  {B_BUTTON}ANNULER");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Veuillez choisir un DRESSEUR.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Veuillez choisir un DRESSEUR\npour un COMBAT SOLO.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Veuillez choisir un DRESSEUR\npour un COMBAT DUO.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Veuillez choisir un DRESSEUR\npour un COMBAT MULTI.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Veuillez choisir le DRESSEUR avec\nqui faire l’échange.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Veuillez choisir le DRESSEUR qui\npartage les CARTES MIRACLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Veuillez choisir le DRESSEUR qui\npartage les INFOS MIRACLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Sautez avec un mini POKéMON!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BROYEUR DE BAIES!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("ATTRAPE-BAIES DODRIO!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("MIXEUR!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("CENTRE DE DONNEES!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("CONCOURS DE SANG-FROID!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("CONCOURS DE BEAUTE!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("CONCOURS DE GRACE!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("CONCOURS D’INTELLIGENCE!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("CONCOURS DE ROBUSTESSE!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("Niveau 50 à la TOUR DE COMBAT!\nChoisissez le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("Niveau libre à la TOUR DE COMBAT!\nChoisissez le MENEUR.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("La tua offerta di scambio è stata\nrifiutata.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("SCAMBIO UOVA");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}SCEGLI  {A_BUTTON}PARTECIPA  {B_BUTTON}ANNULLA");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Scegli un ALLENATORE.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Scegli un ALLENATORE per\nuna LOTTA in SINGOLO.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Scegli un ALLENATORE per\nuna LOTTA in DOPPIO.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Scegli un ALLENATORE per\nuna LOTTA MULTIPLA.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Scegli un ALLENATORE per\nfare scambi.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Scegli un ALLENATORE che\ncondivide SCHEDE SEGRETE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Scegli un ALLENATORE che\ncondivide le NOTIZIE SEGRETE.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Salta con piccoli POKéMON!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("MACINABACCHE!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO PIGLIABACCHE!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("MIXER BACCHE!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("BANCO REGISTRO!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("GARA di CLASSE!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("GARA di BELLEZZA!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("GARA di GRAZIA!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("GARA di ACUME!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("GARA di GRINTA!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("TORRE LOTTA: LIVELLO 50!\nScegli il CAPOGRUPPO.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("TORRE LOTTA: LIVELLO LIBERO!\nScegli il CAPOGRUPPO.");
#else //ENGLISH
ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Your trade offer was rejected.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("EGG TRADE");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOOSE  {A_BUTTON}JOIN  {B_BUTTON}CANCEL");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Please choose a TRAINER.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Please choose a TRAINER for\na SINGLE BATTLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Please choose a TRAINER for\na DOUBLE BATTLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Please choose the LEADER\nfor a MULTI BATTLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Please choose the TRAINER to\ntrade with.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Please choose the TRAINER who is\nsharing WONDER CARDS.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Please choose the TRAINER who is\nsharing WONDER NEWS.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Jump with mini POKéMON!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BERRY CRUSH!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO BERRY-PICKING!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("BERRY BLENDER!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("RECORD CORNER!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("COOLNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("BEAUTY CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("CUTENESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("SMARTNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("TOUGHNESS CONTEST!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("BATTLE TOWER LEVEL 50!\nPlease choose the LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL!\nPlease choose the LEADER.");
#endif

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
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
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

#if FRENCH
ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Recherche d’un système de\nCOMMUNICATION SANS FIL. Patienter.");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p");
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Attente d’une réponse de {STR_VAR_1}…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} doit vous enregistrer\ncomme membre. Veuillez patienter.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Attente d’une réponse d’un système\nde COMMUNICATION SANS FIL.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Please wait for other TRAINERS to\ngather and get ready.");
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Aucune CARTE n’est échangée pour\nl’instant.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Aucune INFO n’est échangée pour\nl’instant.");
#elif ITALIAN
ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Ricerca di un SISTEMA\nCOMUNICAZIONE WIRELESS. Attendi…");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p");
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("In attesa di risposta da {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} ha ricevuto la tua\nrichiesta di partecipare. Attendi…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("In attesa di risposta dal SISTEMA\nCOMUNICAZIONE WIRELESS.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Please wait for other TRAINERS to\ngather and get ready.");
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Non ci sono SCHEDE condivise\nal momento.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Non ci sono NOTIZIE condivise\nal momento.");
#else //ENGLISH
ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Searching for a WIRELESS\nCOMMUNICATION SYSTEM. Wait...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("For a DOUBLE BATTLE, you must have\nat least two POKéMON.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("Awaiting {STR_VAR_1}'s response…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} has been asked to register\nyou as a member. Please wait.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("Awaiting a response from the\nWIRELESS COMMUNICATION SYSTEM.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Please wait for other TRAINERS to\ngather and get ready."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("No CARDS appear to be shared \nright now.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("No NEWS appears to be shared\nright now.");
#endif

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

#if FRENCH
ALIGNED(4) static const u8 sText_Battle[] = _("COMBAT");
ALIGNED(4) static const u8 sText_Chat2[] = _("TCHAT");
ALIGNED(4) static const u8 sText_Greetings[] = _("SALUT");
ALIGNED(4) static const u8 sText_Exit[] = _("RETOUR");
ALIGNED(4) static const u8 sText_Exit2[] = _("RETOUR");
ALIGNED(4) static const u8 sText_Info[] = _("INFOS");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NOM{CLEAR_TO 60}RECHERCHE{CLEAR_TO 110}OFFRE{CLEAR_TO 198}N.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("COMBAT SOLO");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("COMBAT DUO");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("COMBAT MULTI.");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("ECHANGES DE PKMN");
ALIGNED(4) static const u8 sText_Chat[] = _("TCHAT");
ALIGNED(4) static const u8 sText_Cards[] = _("CARTES");
ALIGNED(4) static const u8 sText_WonderCards[] = _("CARTES MIRACLE");
ALIGNED(4) static const u8 sText_WonderNews[] = _("INFOS MIRACLE");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("SAUT POKéMON");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("BROYEUR DE BAIES");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("ATTRAPE-BAIES");
ALIGNED(4) static const u8 sText_Search[] = _("RECHERCHE");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("MIXEUR");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("CENTRE DE DONNEES");
ALIGNED(4) static const u8 sText_CoolContest[] = _("CONCOURS DE SANG-FROID");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("CONCOURS DE BEAUTE");
ALIGNED(4) static const u8 sText_CuteContest[] = _("CONCOURS DE GRACE");
ALIGNED(4) static const u8 sText_SmartContest[] = _("CONCOURS D’INTELLIGENCE");
ALIGNED(4) static const u8 sText_ToughContest[] = _("CONCOURS DE ROBUSTESSE");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("NIV. 50 à la TOUR DE COMBAT");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("TOUR DE COMBAT NIV. LIBRE!");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("C’est une carte NORMALE!");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("C’est une carte en BRONZE!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("C’est une carte en CUIVRE!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("C’est une carte en ARGENT!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("C’est une carte en OR!");
#elif ITALIAN
ALIGNED(4) static const u8 sText_Battle[] = _("LOTTA");
ALIGNED(4) static const u8 sText_Chat2[] = _("CHAT");
ALIGNED(4) static const u8 sText_Greetings[] = _("SALUTI");
ALIGNED(4) static const u8 sText_Exit[] = _("ESCI");
ALIGNED(4) static const u8 sText_Exit2[] = _("ESCI");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NOME{CLEAR_TO 60}CERCO{CLEAR_TO 110}OFFRO{CLEAR_TO 198}L.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("LOTTA in SINGOLO");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("LOTTA in DOPPIO");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("LOTTA MULTIPLA");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("SCAMBI POKéMON");
ALIGNED(4) static const u8 sText_Chat[] = _("CHAT");
ALIGNED(4) static const u8 sText_Cards[] = _("SCHEDE");
ALIGNED(4) static const u8 sText_WonderCards[] = _("SCHEDE SEGRETE");
ALIGNED(4) static const u8 sText_WonderNews[] = _("NOTIZIE SEGRETE");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéSALTI");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("MACINABACCHE");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("PIGLIABACCHE");
ALIGNED(4) static const u8 sText_Search[] = _("RICERCA");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("MIXER BACCHE");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("BANCO REGISTRO");
ALIGNED(4) static const u8 sText_CoolContest[] = _("GARA di CLASSE");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("GARA di BELLEZZA");
ALIGNED(4) static const u8 sText_CuteContest[] = _("GARA di GRAZIA");
ALIGNED(4) static const u8 sText_SmartContest[] = _("GARA di ACUME");
ALIGNED(4) static const u8 sText_ToughContest[] = _("GARA di GRINTA");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("TORRE LOTTA: LIVELLO 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("TORRE LOTTA: L. LIBERO");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("È una SCHEDA NORMALE!");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("È una SCHEDA di BRONZO!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("È una SCHEDA di RAME!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("È una SCHEDA d’ARGENTO!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("È una SCHEDA d’ORO!");
#else //ENGLISH
ALIGNED(4) static const u8 sText_Battle[] = _("BATTLE");
ALIGNED(4) static const u8 sText_Chat2[] = _("CHAT");
ALIGNED(4) static const u8 sText_Greetings[] = _("GREETINGS");
ALIGNED(4) static const u8 sText_Exit[] = _("EXIT");
ALIGNED(4) static const u8 sText_Exit2[] = _("EXIT");
ALIGNED(4) static const u8 sText_Info[] = _("INFO");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NAME{CLEAR_TO 60}WANTED{CLEAR_TO 110}OFFER{CLEAR_TO 198}LV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("SINGLE BATTLE");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("DOUBLE BATTLE");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("MULTI BATTLE");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("POKéMON TRADES");
ALIGNED(4) static const u8 sText_Chat[] = _("CHAT");
ALIGNED(4) static const u8 sText_Cards[] = _("CARDS");
ALIGNED(4) static const u8 sText_WonderCards[] = _("WONDER CARDS");
ALIGNED(4) static const u8 sText_WonderNews[] = _("WONDER NEWS");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéMON JUMP");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("BERRY CRUSH");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("BERRY-PICKING");
ALIGNED(4) static const u8 sText_Search[] = _("SEARCH");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("BERRY BLENDER");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("RECORD CORNER");
ALIGNED(4) static const u8 sText_CoolContest[] = _("COOL CONTEST");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("BEAUTY CONTEST");
ALIGNED(4) static const u8 sText_CuteContest[] = _("CUTE CONTEST");
ALIGNED(4) static const u8 sText_SmartContest[] = _("SMART CONTEST");
ALIGNED(4) static const u8 sText_ToughContest[] = _("TOUGH CONTEST");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("BATTLE TOWER LV. 50");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("BATTLE TOWER OPEN LEVEL");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("It's a NORMAL CARD.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("It's a BRONZE CARD!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("It's a COPPER CARD!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("It's a SILVER CARD!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("It's a GOLD CARD!");
#endif

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

#if FRENCH
ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("C’est la CARTE DE DRESSEUR\nde {DYNAMIC 0} {DYNAMIC 1}…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nTEMPS:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("COMBATS: {DYNAMIC 0} VICT.  {DYNAMIC 2} DEF.\nECHANGES:  {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Ravi de te connaître!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Ravie de te connaître!{PAUSE 60}");
#elif ITALIAN
ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("Questa è la SCHEDA\nALLENATORE di\l{DYNAMIC 1}, {DYNAMIC 0}.\p{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nTEMPO: {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("LOTTE: VINTE {DYNAMIC 0}  PERSE {DYNAMIC 2}\nSCAMBI: VOLTE {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Piacere di conoscerti!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Piacere!{PAUSE 60}");
#else //ENGLISH
ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("This is {DYNAMIC 0} {DYNAMIC 1}'s\nTRAINER CARD…\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nTIME:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("BATTLES: WINS: {DYNAMIC 0}  LOSSES: {DYNAMIC 2}\nTRADES: {DYNAMIC 3}\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Glad to have met you!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Glad to meet you!{PAUSE 60}");
#endif

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

#if FRENCH
ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("La CARTE DE DRESSEUR de\n{DYNAMIC 1} a été lue.{PAUSE 60}");
#elif ITALIAN
ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Completata la lettura della SCHEDA\nALLENATORE di {DYNAMIC 1}.{PAUSE 60}");
#else //ENGLISH
ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Finished checking {DYNAMIC 1}'s\nTRAINER CARD.{PAUSE 60}");
#endif

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max)(((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity)(capacity & 0x0F)
#define GROUP_MIN(capacity)(capacity >> 4)
#define GROUP_MIN2(capacity)(capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
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
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
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
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
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
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
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
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
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
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
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
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
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
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
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
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
