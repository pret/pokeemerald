#include "global.h"
#include "mevent_client.h"
#include "mevent_server.h"

const u8 gText_CanceledReadingCard[] = _("Canceled reading\nthe Card.");


const struct mevent_client_cmd gUnknown_082F2598[] = {
    {.instr =  2, .parameter = 16},
    {.instr =  4, .parameter = 0}
};

const struct mevent_client_cmd gUnknown_082F25A8[] = {
    {.instr =  8, .parameter = 0},
    {.instr =  3, .parameter = 0},
    {.instr =  2, .parameter = 16},
    {.instr =  4, .parameter = 0}
};

const struct mevent_client_cmd gUnknown_082F25C8[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 10}
};

const struct mevent_client_cmd gUnknown_082F25D8[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 11}
};

const struct mevent_client_cmd gUnknown_082F25E8[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 0}
};

const struct mevent_client_cmd gUnknown_082F25F8[] = {
    {.instr =  2, .parameter = 22},
    {.instr = 10, .parameter = 0},
    {.instr =  2, .parameter = 25},
    {.instr = 17, .parameter = 0},
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 2}
};

const struct mevent_client_cmd gUnknown_082F2628[] = {
    {.instr =  2, .parameter = 23},
    {.instr =  9, .parameter = 0},
    {.instr =  3, .parameter = 0},
    {.instr =  2, .parameter = 16},
    {.instr =  4, .parameter = 0}
};

const struct mevent_client_cmd gUnknown_082F2650[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 7}
};

const struct mevent_client_cmd gUnknown_082F2660[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 3}
};

const struct mevent_client_cmd gUnknown_082F2670[] = {
    {.instr = 13, .parameter = 0},
    {.instr = 14, .parameter = 0},
    {.instr =  3, .parameter = 0},
    {.instr =  2, .parameter = 16},
    {.instr =  4, .parameter = 0}
};

const struct mevent_client_cmd gUnknown_082F2698[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 9}
};

const struct mevent_client_cmd gUnknown_082F26A8[] = {
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 5}
};

const struct mevent_client_cmd gUnknown_082F26B8[] = {
    {.instr =  2, .parameter = 21},
    {.instr = 12, .parameter = 0},
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 14},
    {.instr =  2, .parameter = 21},
    {.instr = 12, .parameter = 0},
    {.instr = 20, .parameter = 0},
    {.instr =  1, .parameter = 13}
};

const struct mevent_cmd gUnknown_082F26F8[] = {
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F25C8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x0a, .parameter = NULL},
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F25D8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x0b, .parameter = NULL},
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F2698},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x09, .parameter = NULL}
};

const struct mevent_cmd gUnknown_082F2788[] = {
    {.instr = 18, .flag = 0x20, .parameter = gUnknown_082F26B8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr = 20, .flag = 0x1b, .parameter = gText_CanceledReadingCard},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x09, .parameter = NULL}
};

const struct mevent_cmd gUnknown_082F27D0[] = {
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F2650},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x07, .parameter = NULL}
};

const struct mevent_cmd gUnknown_082F2800[] = {
    {.instr = 18, .flag = 0x28, .parameter = gUnknown_082F2628},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr = 14, .flag = 0x00, .parameter = NULL},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x13, .parameter = NULL},
    {.instr =  8, .flag = 0x00, .parameter = NULL},
    {.instr =  4, .flag = 0x01, .parameter = gUnknown_082F27D0},
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F2660},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x03, .parameter = NULL}
};

const struct mevent_cmd gUnknown_082F2884[] = {
    {.instr = 18, .flag = 0x30, .parameter = gUnknown_082F25F8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr = 13, .flag = 0x00, .parameter = NULL},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr = 15, .flag = 0x00, .parameter = NULL},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x02, .parameter = NULL}
};

const struct mevent_cmd gUnknown_082F28E4[] = {
    {.instr = 18, .flag = 0x28, .parameter = gUnknown_082F2670},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x13, .parameter = NULL},
    {.instr =  8, .flag = 0x00, .parameter = NULL},
    {.instr =  4, .flag = 0x00, .parameter = gUnknown_082F2884},
    {.instr =  3, .flag = 0x00, .parameter = gUnknown_082F2788}
};

const struct mevent_cmd gUnknown_082F292C[] = {
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F26A8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x05, .parameter = NULL},
    {.instr = 18, .flag = 0x10, .parameter = gUnknown_082F25E8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x14, .parameter = NULL},
    {.instr =  0, .flag = 0x00, .parameter = NULL}
};

const struct mevent_cmd s_mevent_wonder_news[] = {
    {.instr = 27, .flag = 0x00, .parameter = NULL},
    {.instr = 18, .flag = 0x20, .parameter = gUnknown_082F25A8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x11, .parameter = NULL},
    {.instr =  5, .flag = 0x00, .parameter = NULL},
    {.instr = 30, .flag = 0x00, .parameter = NULL},
    {.instr =  4, .flag = 0x00, .parameter = gUnknown_082F26F8},
    {.instr =  3, .flag = 0x00, .parameter = gUnknown_082F2800}
};

const struct mevent_cmd s_mevent_wonder_card[] = {
    {.instr = 26, .flag = 0x00, .parameter = NULL},
    {.instr = 28, .flag = 0x00, .parameter = NULL},
    {.instr = 18, .flag = 0x20, .parameter = gUnknown_082F25A8},
    {.instr =  1, .flag = 0x00, .parameter = NULL},
    {.instr =  2, .flag = 0x11, .parameter = NULL},
    {.instr =  5, .flag = 0x00, .parameter = NULL},
    {.instr =  6, .flag = 0x00, .parameter = NULL},
    {.instr =  4, .flag = 0x00, .parameter = gUnknown_082F26F8},
    {.instr =  7, .flag = 0x00, .parameter = NULL},
    {.instr =  4, .flag = 0x02, .parameter = gUnknown_082F28E4},
    {.instr =  4, .flag = 0x00, .parameter = gUnknown_082F2884},
    {.instr =  3, .flag = 0x00, .parameter = gUnknown_082F292C}
};
