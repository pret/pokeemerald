#include "global.h"
#include "mevent_client.h"
#include "mevent_server.h"

const u8 gText_CanceledReadingCard[] = _("Canceled reading\nthe Card.");


const struct MysteryGiftClientCmd gUnknown_082F2598[] = {
    {.instr = CLI_RECV, .parameter = 16},
    {.instr = CLI_COPY_RECV}
};

const struct MysteryGiftClientCmd gUnknown_082F25A8[] = {
    {.instr = CLI_8},
    {.instr = CLI_SEND_LOADED},
    {.instr = CLI_RECV, .parameter = 16},
    {.instr = CLI_COPY_RECV}
};

const struct MysteryGiftClientCmd gUnknown_082F25C8[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 10}
};

const struct MysteryGiftClientCmd gUnknown_082F25D8[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 11}
};

const struct MysteryGiftClientCmd gUnknown_082F25E8[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 0}
};

const struct MysteryGiftClientCmd gUnknown_082F25F8[] = {
    {.instr = CLI_RECV, .parameter = 22},
    {.instr = CLI_10},
    {.instr = CLI_RECV, .parameter = 25},
    {.instr = CLI_17},
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 2}
};

const struct MysteryGiftClientCmd gUnknown_082F2628[] = {
    {.instr = CLI_RECV, .parameter = 23},
    {.instr = CLI_9},
    {.instr = CLI_SEND_LOADED},
    {.instr = CLI_RECV, .parameter = 16},
    {.instr = CLI_COPY_RECV}
};

const struct MysteryGiftClientCmd gUnknown_082F2650[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 7}
};

const struct MysteryGiftClientCmd gUnknown_082F2660[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 3}
};

const struct MysteryGiftClientCmd gUnknown_082F2670[] = {
    {.instr = CLI_ASK_TOSS},
    {.instr = CLI_LOAD_TOSS_RESPONSE},
    {.instr = CLI_SEND_LOADED},
    {.instr = CLI_RECV, .parameter = 16},
    {.instr = CLI_COPY_RECV}
};

const struct MysteryGiftClientCmd gUnknown_082F2698[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 9}
};

const struct MysteryGiftClientCmd gUnknown_082F26A8[] = {
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 5}
};

const struct MysteryGiftClientCmd gUnknown_082F26B8[] = {
    {.instr = CLI_RECV, .parameter = 21},
    {.instr = CLI_12},
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 14}
};

// Unused
const struct MysteryGiftClientCmd gUnknown_082F26B8_1[] = {
    {.instr = CLI_RECV, .parameter = 21},
    {.instr = CLI_12},
    {.instr = CLI_20},
    {.instr = CLI_RETURN, .parameter = 13}
};

const struct mevent_cmd gUnknown_082F26F8[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F25C8), .parameter = gUnknown_082F25C8},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x0a},
    {.instr = 18, .flag = sizeof(gUnknown_082F25D8), .parameter = gUnknown_082F25D8},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x0b},
    {.instr = 18, .flag = sizeof(gUnknown_082F2698), .parameter = gUnknown_082F2698},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x09}
};

const struct mevent_cmd gUnknown_082F2788[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F26B8), .parameter = gUnknown_082F26B8},
    {.instr =  1},
    {.instr = 20, .flag = 0x1b, .parameter = gText_CanceledReadingCard},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x09}
};

const struct mevent_cmd gUnknown_082F27D0[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F2650), .parameter = gUnknown_082F2650},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x07}
};

const struct mevent_cmd gUnknown_082F2800[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F2628), .parameter = gUnknown_082F2628},
    {.instr =  1},
    {.instr = 14},
    {.instr =  1},
    {.instr =  2, .flag = 0x13},
    {.instr =  8},
    {.instr =  4, .flag = 0x01, .parameter = gUnknown_082F27D0},
    {.instr = 18, .flag = sizeof(gUnknown_082F2660), .parameter = gUnknown_082F2660},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x03}
};

const struct mevent_cmd gUnknown_082F2884[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F25F8), .parameter = gUnknown_082F25F8},
    {.instr =  1},
    {.instr = 13},
    {.instr =  1},
    {.instr = 15},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x02}
};

const struct mevent_cmd gUnknown_082F28E4[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F2670), .parameter = gUnknown_082F2670},
    {.instr =  1},
    {.instr =  2, .flag = 0x13},
    {.instr =  8},
    {.instr =  4, .parameter = gUnknown_082F2884},
    {.instr =  3, .parameter = gUnknown_082F2788}
};

const struct mevent_cmd gUnknown_082F292C[] = {
    {.instr = 18, .flag = sizeof(gUnknown_082F26A8), .parameter = gUnknown_082F26A8},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0, .flag = 0x05},
    {.instr = 18, .flag = sizeof(gUnknown_082F25E8), .parameter = gUnknown_082F25E8},
    {.instr =  1},
    {.instr =  2, .flag = 0x14},
    {.instr =  0}
};

const struct mevent_cmd s_mevent_wonder_news[] = {
    {.instr = 27},
    {.instr = 18, .flag = sizeof(gUnknown_082F25A8), .parameter = gUnknown_082F25A8},
    {.instr =  1},
    {.instr =  2, .flag = 0x11},
    {.instr =  5},
    {.instr = 30},
    {.instr =  4, .parameter = gUnknown_082F26F8},
    {.instr =  3, .parameter = gUnknown_082F2800}
};

const struct mevent_cmd s_mevent_wonder_card[] = {
    {.instr = 26},
    {.instr = 28},
    {.instr = 18, .flag = sizeof(gUnknown_082F25A8), .parameter = gUnknown_082F25A8},
    {.instr =  1},
    {.instr =  2, .flag = 0x11},
    {.instr =  5},
    {.instr =  6},
    {.instr =  4, .parameter = gUnknown_082F26F8},
    {.instr =  7},
    {.instr =  4, .flag = 0x02, .parameter = gUnknown_082F28E4},
    {.instr =  4, .parameter = gUnknown_082F2884},
    {.instr =  3, .parameter = gUnknown_082F292C}
};
