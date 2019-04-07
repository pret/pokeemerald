static const union AnimCmd gAnimCmd_Brendan_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_May_Steven_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_Wally_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_Red_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_Leaf_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_RubySapphireBrendan_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd gAnimCmd_RubySapphireMay_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

static const union AnimCmd *const sBackAnims_Brendan[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_Brendan_1,
};

static const union AnimCmd *const sBackAnims_May[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_May_Steven_1,
};

static const union AnimCmd *const sBackAnims_Red[] =
{
    sAnim_GeneralFrame0,
    gAnimCmd_Red_1,
};

static const union AnimCmd *const sBackAnims_Leaf[] =
{
    sAnim_GeneralFrame0,
    gAnimCmd_Leaf_1,
};

static const union AnimCmd *const sBackAnims_RubySapphireBrendan[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_RubySapphireBrendan_1,
};

static const union AnimCmd *const sBackAnims_RubySapphireMay[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_RubySapphireMay_1,
};

static const union AnimCmd *const sBackAnims_Wally[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_Wally_1,
};

static const union AnimCmd *const sBackAnims_Steven[] =
{
    sAnim_GeneralFrame3,
    gAnimCmd_May_Steven_1,
};

const union AnimCmd *const *const gTrainerBackAnimsPtrTable[] =
{
    [TRAINER_BACK_PIC_BRENDAN] = sBackAnims_Brendan,
    [TRAINER_BACK_PIC_MAY] = sBackAnims_May,
    [TRAINER_BACK_PIC_RED] = sBackAnims_Red,
    [TRAINER_BACK_PIC_LEAF] = sBackAnims_Leaf,
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = sBackAnims_RubySapphireBrendan,
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = sBackAnims_RubySapphireMay,
    [TRAINER_BACK_PIC_WALLY] = sBackAnims_Wally,
    [TRAINER_BACK_PIC_STEVEN] = sBackAnims_Steven,
};
