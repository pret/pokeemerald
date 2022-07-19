#include "global.h"
#include "mystery_gift_client.h"
#include "mystery_gift_server.h"
#include "mystery_gift.h"

static const u8 sText_CanceledReadingCard[] = _("Annuler la lecture\nde la carte.");


//==================
// Client scripts
//==================

const struct MysteryGiftClientCmd gMysteryGiftClientScript_Init[] = {
    {CLI_RECV, MG_LINKID_CLIENT_SCRIPT},
    {CLI_COPY_RECV}
};

static const struct MysteryGiftClientCmd sClientScript_SendGameData[] = {
    {CLI_LOAD_GAME_DATA},
    {CLI_SEND_LOADED},
    {CLI_RECV, MG_LINKID_CLIENT_SCRIPT},
    {CLI_COPY_RECV}
};

static const struct MysteryGiftClientCmd sClientScript_CantAccept[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_CANT_ACCEPT}
};

static const struct MysteryGiftClientCmd sClientScript_CommError[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_COMM_ERROR}
};

static const struct MysteryGiftClientCmd sClientScript_NothingSent[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_NOTHING_SENT}
};

static const struct MysteryGiftClientCmd sClientScript_SaveCard[] = {
    {CLI_RECV, MG_LINKID_CARD},
    {CLI_SAVE_CARD},
    {CLI_RECV, MG_LINKID_RAM_SCRIPT},
    {CLI_SAVE_RAM_SCRIPT},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_CARD_RECEIVED}
};

static const struct MysteryGiftClientCmd sClientScript_SaveNews[] = {
    {CLI_RECV, MG_LINKID_NEWS},
    {CLI_SAVE_NEWS},
    {CLI_SEND_LOADED}, // Send whether or not the News was saved (read by sServerScript_SendNews)
    {CLI_RECV, MG_LINKID_CLIENT_SCRIPT},
    {CLI_COPY_RECV}
};

static const struct MysteryGiftClientCmd sClientScript_HadNews[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_HAD_NEWS}
};

static const struct MysteryGiftClientCmd sClientScript_NewsReceived[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_NEWS_RECEIVED}
};

static const struct MysteryGiftClientCmd sClientScript_AskToss[] = {
    {CLI_ASK_TOSS},
    {CLI_LOAD_TOSS_RESPONSE},
    {CLI_SEND_LOADED},
    {CLI_RECV, MG_LINKID_CLIENT_SCRIPT},
    {CLI_COPY_RECV}
};

static const struct MysteryGiftClientCmd sClientScript_Canceled[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_COMM_CANCELED}
};

static const struct MysteryGiftClientCmd sClientScript_HadCard[] = {
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_HAD_CARD}
};

static const struct MysteryGiftClientCmd sClientScript_DynamicError[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_FAILURE}
};

static const struct MysteryGiftClientCmd sClientScript_DynamicSuccess[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_SUCCESS}
};


//==================
// Server scripts
//==================

// Create arguments for SVR_LOAD_CLIENT_SCRIPT or SVR_LOAD_MSG
// (a script/text size and pointer to send to the client)
#define PTR_ARG(pointer) .parameter = sizeof(pointer), .ptr = pointer

static const struct MysteryGiftServerCmd sServerScript_CantSend[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_CantAccept)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CANT_SEND_GIFT_1}
};

static const struct MysteryGiftServerCmd sServerScript_CommError[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_CommError)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_COMM_ERROR}
};

static const struct MysteryGiftServerCmd sServerScript_ClientCanceledNews[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_Canceled)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};

static const struct MysteryGiftServerCmd sServerScript_ClientCanceledCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_DynamicError)},
    {SVR_SEND},
    {SVR_LOAD_MSG, PTR_ARG(sText_CanceledReadingCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};

static const struct MysteryGiftServerCmd sServerScript_HasNews[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_HadNews)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_HAS_NEWS}
};

static const struct MysteryGiftServerCmd sServerScript_SendNews[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_SaveNews)},
    {SVR_SEND},
    {SVR_LOAD_NEWS},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_RESPONSE},
    {SVR_READ_RESPONSE},
    {SVR_GOTO_IF_EQ, TRUE, sServerScript_HasNews}, // Wonder News was not saved
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_NewsReceived)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_NEWS_SENT}
};

static const struct MysteryGiftServerCmd sServerScript_SendCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_SaveCard)},
    {SVR_SEND},
    {SVR_LOAD_CARD},
    {SVR_SEND},
    {SVR_LOAD_RAM_SCRIPT},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CARD_SENT}
};

static const struct MysteryGiftServerCmd sServerScript_TossPrompt[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_AskToss)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_RESPONSE},
    {SVR_READ_RESPONSE},
    {SVR_GOTO_IF_EQ, FALSE, sServerScript_SendCard},       // Tossed old card, send new one
    {SVR_GOTO, .ptr = sServerScript_ClientCanceledCard} // Kept old card, cancel new one
};

static const struct MysteryGiftServerCmd sServerScript_HasCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_HadCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_HAS_CARD}
};

static const struct MysteryGiftServerCmd sServerScript_NothingSent[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_NothingSent)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_NOTHING_SENT}
};

const struct MysteryGiftServerCmd gMysteryGiftServerScript_SendWonderNews[] = {
    {SVR_COPY_SAVED_NEWS},
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_SendGameData)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_GAME_DATA},
    {SVR_COPY_GAME_DATA},
    {SVR_CHECK_GAME_DATA_NEWS},
    {SVR_GOTO_IF_EQ, FALSE, sServerScript_CantSend},
    {SVR_GOTO, .ptr = sServerScript_SendNews}
};

const struct MysteryGiftServerCmd gMysteryGiftServerScript_SendWonderCard[] = {
    {SVR_COPY_SAVED_CARD},
    {SVR_COPY_SAVED_RAM_SCRIPT},
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_SendGameData)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_GAME_DATA},
    {SVR_COPY_GAME_DATA},
    {SVR_CHECK_GAME_DATA_CARD},
    {SVR_GOTO_IF_EQ, FALSE, sServerScript_CantSend},
    {SVR_CHECK_EXISTING_CARD},
    {SVR_GOTO_IF_EQ, HAS_DIFF_CARD, sServerScript_TossPrompt},
    {SVR_GOTO_IF_EQ, HAS_NO_CARD, sServerScript_SendCard},
    {SVR_GOTO, .ptr = sServerScript_HasCard} // HAS_SAME_CARD
};
