#ifndef GUARD_CONSTANTS_PARTY_MENU_H
#define GUARD_CONSTANTS_PARTY_MENU_H

#define PC_MON_CHOSEN 0xFE
#define PARTY_NOTHING_CHOSEN 0xFF

#define AILMENT_NONE  0
#define AILMENT_PSN   1
#define AILMENT_PRZ   2
#define AILMENT_SLP   3
#define AILMENT_FRZ   4
#define AILMENT_BRN   5
#define AILMENT_PKRS  6
#define AILMENT_FNT   7
#define AILMENT_FRB   8

#define PARTY_ACTION_CHOOSE_MON         0
#define PARTY_ACTION_SEND_OUT           1
#define PARTY_ACTION_CANT_SWITCH        2
#define PARTY_ACTION_USE_ITEM           3
#define PARTY_ACTION_ABILITY_PREVENTS   4
#define PARTY_ACTION_GIVE_ITEM          5
#define PARTY_ACTION_GIVE_PC_ITEM       6   // Unused. Not possible to give non-mail items directly from PC
#define PARTY_ACTION_GIVE_MAILBOX_MAIL  7
#define PARTY_ACTION_SWITCH             8
#define PARTY_ACTION_SWITCHING          9
#define PARTY_ACTION_SOFTBOILED         10
#define PARTY_ACTION_CHOOSE_AND_CLOSE   11
#define PARTY_ACTION_MOVE_TUTOR         12
#define PARTY_ACTION_MINIGAME           13
#define PARTY_ACTION_SEND_MON_TO_BOX    14
#define PARTY_ACTION_CHOOSE_FAINTED_MON 15

// IDs for DisplayPartyMenuStdMessage, to display the message at the bottom of the party menu
#define PARTY_MSG_CHOOSE_MON                0
#define PARTY_MSG_CHOOSE_MON_OR_CANCEL      1
#define PARTY_MSG_CHOOSE_MON_AND_CONFIRM    2
#define PARTY_MSG_MOVE_TO_WHERE             3
#define PARTY_MSG_TEACH_WHICH_MON           4
#define PARTY_MSG_USE_ON_WHICH_MON          5
#define PARTY_MSG_GIVE_TO_WHICH_MON         6
#define PARTY_MSG_NOTHING_TO_CUT            7
#define PARTY_MSG_CANT_SURF_HERE            8
#define PARTY_MSG_ALREADY_SURFING           9
#define PARTY_MSG_CURRENT_TOO_FAST          10
#define PARTY_MSG_ENJOY_CYCLING             11
#define PARTY_MSG_ALREADY_IN_USE            12
#define PARTY_MSG_CANT_USE_HERE             13
#define PARTY_MSG_NO_MON_FOR_BATTLE         14
#define PARTY_MSG_CHOOSE_MON_2              15
#define PARTY_MSG_NOT_ENOUGH_HP             16
#define PARTY_MSG_X_MONS_ARE_NEEDED         17
#define PARTY_MSG_MONS_CANT_BE_SAME         18
#define PARTY_MSG_NO_SAME_HOLD_ITEMS        19
#define PARTY_MSG_UNUSED                    20
#define PARTY_MSG_DO_WHAT_WITH_MON          21
#define PARTY_MSG_RESTORE_WHICH_MOVE        22
#define PARTY_MSG_BOOST_PP_WHICH_MOVE       23
#define PARTY_MSG_DO_WHAT_WITH_ITEM         24
#define PARTY_MSG_DO_WHAT_WITH_MAIL         25
#define PARTY_MSG_ALREADY_HOLDING_ONE       26
#define PARTY_MSG_WHICH_APPLIANCE           27
#define PARTY_MSG_CHOOSE_SECOND_FUSION      28
#define PARTY_MSG_NO_POKEMON                29
#define PARTY_MSG_CHOOSE_MON_FOR_BOX        30
#define PARTY_MSG_MOVE_ITEM_WHERE           31

#define PARTY_MSG_NONE                      127

// IDs for DisplayPartyPokemonDescriptionText, to display a message in the party Pokémon's box
#define PARTYBOX_DESC_NO_USE      0
#define PARTYBOX_DESC_ABLE_3      1
#define PARTYBOX_DESC_FIRST       2
#define PARTYBOX_DESC_SECOND      3
#define PARTYBOX_DESC_THIRD       4
#define PARTYBOX_DESC_FOURTH      5
#define PARTYBOX_DESC_ABLE        6
#define PARTYBOX_DESC_NOT_ABLE    7
#define PARTYBOX_DESC_ABLE_2      8
#define PARTYBOX_DESC_NOT_ABLE_2  9
#define PARTYBOX_DESC_LEARNED     10
#define PARTYBOX_DESC_HAVE        11
#define PARTYBOX_DESC_DONT_HAVE   12

#define SELECTWINDOW_ACTIONS     0
#define SELECTWINDOW_ITEM        1
#define SELECTWINDOW_MAIL        2
#define SELECTWINDOW_MOVES       3
#define SELECTWINDOW_CATALOG     4
#define SELECTWINDOW_ZYGARDECUBE 5

enum PcMonSelectionType
{
    SELECT_PC_MON_NORMAL,
    SELECT_PC_MON_TRADE, // Also used for Lotad / Seedot size check
    SELECT_PC_MON_DAYCARE,
    SELECT_PC_MON_MOVE_TUTOR,
    SELECT_PC_MON_MOVE_DELETER,
    SELECT_PC_MON_MOVE_RELEARNER,
    SELECT_PC_MON_EVOLUTION,
};

enum CanMoveBeLearned
{
    CAN_LEARN_MOVE,
    CANNOT_LEARN_MOVE,
    ALREADY_KNOWS_MOVE,
    CANNOT_LEARN_MOVE_IS_EGG
};

#endif // GUARD_CONSTANTS_PARTY_MENU_H
