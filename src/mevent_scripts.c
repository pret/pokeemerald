#include "global.h"
#include "mevent_server_ish.h"
#include "mevent_server.h"

const u8 gText_CanceledReadingCard[] = _("Canceled reading\nthe Card.");


const struct mevent_cmd_ish gUnknown_082F2598[] = {
    { 2, 16},
    { 4, 0}
};

const struct mevent_cmd_ish gUnknown_082F25A8[] = {
    { 8, 0},
    { 3, 0},
    { 2, 16},
    { 4, 0}
};

const struct mevent_cmd_ish gUnknown_082F25C8[] = {
    {20, 0},
    { 1, 10}
};

const struct mevent_cmd_ish gUnknown_082F25D8[] = {
    {20, 0},
    { 1, 11}
};

const struct mevent_cmd_ish gUnknown_082F25E8[] = {
    {20, 0},
    { 1, 0}
};

const struct mevent_cmd_ish gUnknown_082F25F8[] = {
    { 2, 22},
    {10, 0},
    { 2, 25},
    {17, 0},
    {20, 0},
    { 1, 2}
};

const struct mevent_cmd_ish gUnknown_082F2628[] = {
    { 2, 23},
    { 9, 0},
    { 3, 0},
    { 2, 16},
    { 4, 0}
};

const struct mevent_cmd_ish gUnknown_082F2650[] = {
    {20, 0},
    { 1, 7}
};

const struct mevent_cmd_ish gUnknown_082F2660[] = {
    {20, 0},
    { 1, 3}
};

const struct mevent_cmd_ish gUnknown_082F2670[] = {
    {13, 0},
    {14, 0},
    { 3, 0},
    { 2, 16},
    { 4, 0}
};

const struct mevent_cmd_ish gUnknown_082F2698[] = {
    {20, 0},
    { 1, 9}
};

const struct mevent_cmd_ish gUnknown_082F26A8[] = {
    {20, 0},
    { 1, 5}
};

const struct mevent_cmd_ish gUnknown_082F26B8[] = {
    { 2, 21},
    {12, 0},
    {20, 0},
    { 1, 14},
    { 2, 21},
    {12, 0},
    {20, 0},
    { 1, 13}
};

const struct mevent_cmd gUnknown_082F26F8[] = {
    {18, 0x10, gUnknown_082F25C8},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x0a, NULL},
    {18, 0x10, gUnknown_082F25D8},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x0b, NULL},
    {18, 0x10, gUnknown_082F2698},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x09, NULL}
};

const struct mevent_cmd gUnknown_082F2788[] = {
    {18, 0x20, gUnknown_082F26B8},
    { 1, 0x00, NULL},
    {20, 0x1b, gText_CanceledReadingCard},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x09, NULL}
};

const struct mevent_cmd gUnknown_082F27D0[] = {
    {18, 0x10, gUnknown_082F2650},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x07, NULL}
};

const struct mevent_cmd gUnknown_082F2800[] = {
    {18, 0x28, gUnknown_082F2628},
    { 1, 0x00, NULL},
    {14, 0x00, NULL},
    { 1, 0x00, NULL},
    { 2, 0x13, NULL},
    { 8, 0x00, NULL},
    { 4, 0x01, gUnknown_082F27D0},
    {18, 0x10, gUnknown_082F2660},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x03, NULL}
};

const struct mevent_cmd gUnknown_082F2884[] = {
    {18, 0x30, gUnknown_082F25F8},
    { 1, 0x00, NULL},
    {13, 0x00, NULL},
    { 1, 0x00, NULL},
    {15, 0x00, NULL},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x02, NULL}
};

const struct mevent_cmd gUnknown_082F28E4[] = {
    {18, 0x28, gUnknown_082F2670},
    { 1, 0x00, NULL},
    { 2, 0x13, NULL},
    { 8, 0x00, NULL},
    { 4, 0x00, gUnknown_082F2884},
    { 3, 0x00, gUnknown_082F2788}
};

const struct mevent_cmd gUnknown_082F292C[] = {
    {18, 0x10, gUnknown_082F26A8},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x05, NULL},
    {18, 0x10, gUnknown_082F25E8},
    { 1, 0x00, NULL},
    { 2, 0x14, NULL},
    { 0, 0x00, NULL}
};

const struct mevent_cmd s_mevent_wonder_news[] = {
    {27, 0x00, NULL},
    {18, 0x20, gUnknown_082F25A8},
    { 1, 0x00, NULL},
    { 2, 0x11, NULL},
    { 5, 0x00, NULL},
    {30, 0x00, NULL},
    { 4, 0x00, gUnknown_082F26F8},
    { 3, 0x00, gUnknown_082F2800}
};

const struct mevent_cmd s_mevent_wonder_card[] = {
    {26, 0x00, NULL},
    {28, 0x00, NULL},
    {18, 0x20, gUnknown_082F25A8},
    {1,  0x00, NULL},
    {2,  0x11, NULL},
    {5,  0x00, NULL},
    {6,  0x00, NULL},
    {4,  0x00, gUnknown_082F26F8},
    {7,  0x00, NULL},
    {4,  0x02, gUnknown_082F28E4},
    {4,  0x00, gUnknown_082F2884},
    {3,  0x00, gUnknown_082F292C},
};
