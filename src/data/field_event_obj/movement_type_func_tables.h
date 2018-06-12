#ifndef GUARD_MOVEMENT_TYPE_FUNC_TABLES_H
#define GUARD_MOVEMENT_TYPE_FUNC_TABLES_H

u8 (*const gUnknown_0850D6F4[])(struct EventObject *, struct Sprite *) = {
    sub_808F44C,
    sub_808F460,
    sub_808F48C,
    sub_808F4C8,
    sub_808F4E8,
    sub_808F534,
    sub_808F564,
};

const u8 gUnknown_0850D710[] = {DIR_SOUTH, DIR_NORTH, DIR_WEST, DIR_EAST};

u8 (*const gUnknown_0850D714[])(s16, s16, s16, s16) = {
    GetRegularRunningPastFacingDirection,
    GetNorthSouthRunningPastFacingDirection,
    GetEastWestRunningPastFacingDirection,
    GetNorthEastRunningPastFacingDirection,
    GetNorthWestRunningPastFacingDirection,
    GetSouthEastRunningPastFacingDirection,
    GetSouthWestRunningPastFacingDirection,
    GetNonEastRunningPastFacingDirection,
    GetNonWestRunningPastFacingDirection,
    GetNonSouthRunningPastFacingDirection,
    GetNonNorthRunningPastFacingDirection,
};

u8 (*const gUnknown_0850D740[])(struct EventObject *, struct Sprite *) = {
    sub_808F988,
    sub_808F99C,
    sub_808F9C8,
    sub_808FA0C,
    sub_808FA3C,
};

u8 (*const gUnknown_0850D754[])(struct EventObject *, struct Sprite *) = {
    sub_808FAC8,
    sub_808FADC,
    sub_808FB08,
    sub_808FB44,
    sub_808FB64,
    sub_808FBB0,
    sub_808FBE0,
};

const u8 gUnknown_0850D770[] = {DIR_SOUTH, DIR_NORTH};

u8 (*const gUnknown_0850D774[])(struct EventObject *, struct Sprite *) = {
    sub_808FC4C,
    sub_808FC60,
    sub_808FC8C,
    sub_808FCC8,
    sub_808FCE8,
    sub_808FD34,
    sub_808FD64,
};

const u8 gUnknown_0850D790[] = {DIR_WEST, DIR_EAST};

u8 (*const gUnknown_0850D794[])(struct EventObject *, struct Sprite *) = {
    sub_808FDD0,
    sub_808FDFC,
    sub_808FE1C,
};

u8 (*const gUnknown_0850D7A0[])(struct EventObject *, struct Sprite *) = {
    do_berry_tree_growth_sparkle_1,
    sub_808FF48,
    do_berry_tree_growth_sparkle_2,
    sub_808FFB4,
    sub_8090004,
};

u8 (*const gUnknown_0850D7B4[])(struct EventObject *, struct Sprite *) = {
    sub_8090094,
    sub_80900A8,
    sub_80900D4,
    sub_8090118,
    sub_8090148,
};

u8 (*const gUnknown_0850D7C8[])(struct EventObject *, struct Sprite *) = {
    sub_80901D4,
    sub_80901E8,
    sub_8090214,
    sub_8090258,
    sub_8090288,
};

u8 (*const gUnknown_0850D7DC[])(struct EventObject *, struct Sprite *) = {
    sub_8090314,
    sub_8090328,
    sub_8090354,
    sub_8090398,
    sub_80903C8,
};

const u8 gUnknown_0850D7F0[] = {DIR_NORTH, DIR_WEST};

u8 (*const gUnknown_0850D7F4[])(struct EventObject *, struct Sprite *) = {
    sub_8090454,
    sub_8090468,
    sub_8090494,
    sub_80904D8,
    sub_8090508,
};

const u8 gUnknown_0850D808[] = {DIR_NORTH, DIR_EAST};

u8 (*const gUnknown_0850D80C[])(struct EventObject *, struct Sprite *) = {
    sub_8090594,
    sub_80905A8,
    sub_80905D4,
    sub_8090618,
    sub_8090648,
};

const u8 gUnknown_0850D820[] = {DIR_SOUTH, DIR_WEST};

u8 (*const gUnknown_0850D824[])(struct EventObject *, struct Sprite *) = {
    sub_80906D4,
    sub_80906E8,
    sub_8090714,
    sub_8090758,
    sub_8090788,
};

const u8 gUnknown_0850D838[] = {DIR_SOUTH, DIR_EAST};

u8 (*const gUnknown_0850D83C[])(struct EventObject *, struct Sprite *) = {
    sub_8090814,
    sub_8090828,
    sub_8090854,
    sub_8090898,
    sub_80908C8,
};

const u8 gUnknown_0850D850[] = {DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_SOUTH};

u8 (*const gUnknown_0850D854[])(struct EventObject *, struct Sprite *) = {
    sub_8090954,
    sub_8090968,
    sub_8090994,
    sub_80909D8,
    sub_8090A08,
};

const u8 gUnknown_0850D868[] = {DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_SOUTH};

u8 (*const gUnknown_0850D86C[])(struct EventObject *, struct Sprite *) = {
    sub_8090A94,
    sub_8090AA8,
    sub_8090AD4,
    sub_8090B18,
    sub_8090B48,
};

const u8 gUnknown_0850D880[] = {DIR_NORTH, DIR_WEST, DIR_EAST, DIR_NORTH};

u8 (*const gUnknown_0850D884[])(struct EventObject *, struct Sprite *) = {
    sub_8090BD4,
    sub_8090BE8,
    sub_8090C14,
    sub_8090C58,
    sub_8090C88,
};

const u8 gUnknown_0850D898[] = {DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_SOUTH};

u8 (*const gUnknown_0850D89C[])(struct EventObject *, struct Sprite *) = {
    sub_8090D14,
    sub_8090D40,
    sub_8090D64,
    sub_8090D90,
};

const u8 gUnknown_0850D8AC[] = {DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH};

u8 (*const gUnknown_0850D8B4[])(struct EventObject *, struct Sprite *) = {
    sub_8090E18,
    sub_8090E44,
    sub_8090E68,
    sub_8090E94,
};

const u8 gUnknown_0850D8C4[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

u8 (*const gUnknown_0850D8CC[])(struct EventObject *, struct Sprite *) = {
    sub_8090F1C,
    sub_8090F30,
    sub_8090F68,
    sub_8091020,
};

u8 (*const gUnknown_0850D8DC[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_809117C,
    sub_8091110,
};

const u8 gUnknown_0850D8E8[] = {DIR_NORTH, DIR_EAST, DIR_WEST, DIR_SOUTH};

u8 (*const gUnknown_0850D8EC[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091208,
    sub_8091110,
};

const u8 gUnknown_0850D8F8[] = {DIR_EAST, DIR_WEST, DIR_SOUTH, DIR_NORTH};

u8 (*const gUnknown_0850D8FC[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091294,
    sub_8091110,
};

const u8 gUnknown_0850D908[] = {DIR_SOUTH, DIR_NORTH, DIR_EAST, DIR_WEST};

u8 (*const gUnknown_0850D90C[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091320,
    sub_8091110,
};

const u8 gUnknown_0850D918[] = {DIR_WEST, DIR_SOUTH, DIR_NORTH, DIR_EAST};

u8 (*const gUnknown_0850D91C[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_80913AC,
    sub_8091110,
};

const u8 gUnknown_0850D928[] = {DIR_NORTH, DIR_WEST, DIR_EAST, DIR_SOUTH};

u8 (*const gUnknown_0850D92C[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091438,
    sub_8091110,
};

const u8 gUnknown_0850D938[] = {DIR_WEST, DIR_EAST, DIR_SOUTH, DIR_NORTH};

u8 (*const gUnknown_0850D93C[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_80914C4,
    sub_8091110,
};

u8 (*const gUnknown_0850D948[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091550,
    sub_8091110,
};

const u8 gUnknown_0850D954[] = {DIR_EAST, DIR_SOUTH, DIR_NORTH, DIR_WEST};

u8 (*const gUnknown_0850D958[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_80915DC,
    sub_8091110,
};

const u8 gUnknown_0850D964[] = {DIR_WEST, DIR_NORTH, DIR_SOUTH, DIR_EAST};

u8 (*const gUnknown_0850D968[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091668,
    sub_8091110,
};

const u8 gUnknown_0850D974[] = {DIR_NORTH, DIR_SOUTH, DIR_EAST, DIR_WEST};

u8 (*const gUnknown_0850D978[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_80916F4,
    sub_8091110,
};

const u8 gUnknown_0850D984[] = {DIR_EAST, DIR_WEST, DIR_NORTH, DIR_SOUTH};

u8 (*const gUnknown_0850D988[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091780,
    sub_8091110,
};

const u8 gUnknown_0850D994[] = {DIR_SOUTH, DIR_EAST, DIR_WEST, DIR_NORTH};

u8 (*const gUnknown_0850D998[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_809180C,
    sub_8091110,
};

const u8 gUnknown_0850D9A4[] = {DIR_EAST, DIR_NORTH, DIR_SOUTH, DIR_WEST};

u8 (*const gUnknown_0850D9A8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091898,
    sub_8091110,
};

const u8 gUnknown_0850D9B4[] = {DIR_NORTH, DIR_SOUTH, DIR_WEST, DIR_EAST};

u8 (*const gUnknown_0850D9B8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091924,
    sub_8091110,
};

const u8 gUnknown_0850D9C4[] = {DIR_WEST, DIR_EAST, DIR_NORTH, DIR_SOUTH};

u8 (*const gUnknown_0850D9C8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_80919B0,
    sub_8091110,
};

const u8 gUnknown_0850D9D4[] = {DIR_SOUTH, DIR_WEST, DIR_EAST, DIR_NORTH};

u8 (*const gUnknown_0850D9D8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091A3C,
    sub_8091110,
};

const u8 gUnknown_0850D9E4[] = {DIR_NORTH, DIR_WEST, DIR_SOUTH, DIR_EAST};

u8 (*const gUnknown_0850D9E8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091AC8,
    sub_8091110,
};

const u8 gUnknown_0850D9F4[] = {DIR_SOUTH, DIR_EAST, DIR_NORTH, DIR_WEST};

u8 (*const gUnknown_0850D9F8[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091B54,
    sub_8091110,
};

const u8 gUnknown_0850DA04[] = {DIR_WEST, DIR_SOUTH, DIR_EAST, DIR_NORTH};

u8 (*const gUnknown_0850DA08[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091BE0,
    sub_8091110,
};

const u8 gUnknown_0850DA14[] = {DIR_EAST, DIR_NORTH, DIR_WEST, DIR_SOUTH};

u8 (*const gUnknown_0850DA18[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091C6C,
    sub_8091110,
};

const u8 gUnknown_0850DA24[] = {DIR_NORTH, DIR_EAST, DIR_SOUTH, DIR_WEST};

u8 (*const gUnknown_0850DA28[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091CF8,
    sub_8091110,
};

const u8 gUnknown_0850DA34[] = {DIR_SOUTH, DIR_WEST, DIR_NORTH, DIR_EAST};

u8 (*const gUnknown_0850DA38[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091D84,
    sub_8091110,
};

const u8 gUnknown_0850DA44[] = {DIR_WEST, DIR_NORTH, DIR_EAST, DIR_SOUTH};

u8 (*const gUnknown_0850DA48[])(struct EventObject *, struct Sprite *) = {
    sub_8091048,
    sub_8091E10,
    sub_8091110,
};

const u8 gUnknown_0850DA54[] = {DIR_EAST, DIR_SOUTH, DIR_WEST, DIR_NORTH};

u8 (*const gUnknown_0850DA58[])(struct EventObject *, struct Sprite *) = {
    mss_npc_reset_oampriv3_1_unk2_unk3,
    sub_8091EC0,
    sub_8091F20,
};

bool8 (*const gUnknown_0850DA64[])(struct EventObject *, struct Sprite *, u8, bool8(u8)) = {
    sub_8091F48,
    sub_8091F4C,
    sub_8091F94,
    sub_80920A4,
    sub_809215C,
    sub_8092214,
    cph_IM_DIFFERENT,
    sub_8092314,
    oac_hopping,
    sub_8091F48,
    sub_8091F48,
};

u8 (*const gUnknown_0850DA90[])(struct EventObject *, struct Sprite *) = {
    mss_npc_reset_oampriv3_1_unk2_unk3,
    mss_08062EA4,
    sub_8091F20,
};

u8 (*const gUnknown_0850DA9C[])(struct EventObject *, struct Sprite *) = {
    sub_80926AC,
};

u8 (*const gUnknown_0850DAA0[])(struct EventObject *, struct Sprite *) = {
    sub_8092718,
    sub_80926B8,
};

u8 (*const gUnknown_0850DAA8[])(struct EventObject *, struct Sprite *) = {
    sub_8092788,
    sub_80926B8,
};

u8 (*const gUnknown_0850DAB0[])(struct EventObject *, struct Sprite *) = {
    sub_80927F8,
    sub_80926B8,
};

u8 (*const gUnknown_0850DAB8[])(struct EventObject *, struct Sprite *) = {
    sub_8092868,
    sub_80926B8,
};

u8 (*const gUnknown_0850DAC0[])(struct EventObject *, struct Sprite *) = {
    sub_80928D8,
    sub_809290C,
    sub_809292C,
};

#endif //GUARD_MOVEMENT_TYPE_FUNC_TABLES_H
