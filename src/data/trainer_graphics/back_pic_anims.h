const union AnimCmd gAnimCmd_Brendan_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_May_Steven_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_Wally_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_Red_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_Leaf_1[] =
{
    ANIMCMD_FRAME(1, 20),
    ANIMCMD_FRAME(2, 6),
    ANIMCMD_FRAME(3, 6),
    ANIMCMD_FRAME(4, 24),
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_RubySapphireBrendan_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24),
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

const union AnimCmd gAnimCmd_RubySapphireMay_1[] =
{
    ANIMCMD_FRAME(0, 24),
    ANIMCMD_FRAME(1, 9),
    ANIMCMD_FRAME(2, 24), 
    ANIMCMD_FRAME(0, 9),
    ANIMCMD_FRAME(3, 50),
    ANIMCMD_END,
};

const union AnimCmd *const gTrainerBackAnims_Brendan[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_Brendan_1,
};

const union AnimCmd *const gTrainerBackAnims_May[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_May_Steven_1,
};

const union AnimCmd *const gTrainerBackAnims_Red[] =
{
    gAnimCmd_General_Frame0,
    gAnimCmd_Red_1,
};

const union AnimCmd *const gTrainerBackAnims_Leaf[] =
{
    gAnimCmd_General_Frame0,
    gAnimCmd_Leaf_1,
};

const union AnimCmd *const gTrainerBackAnims_RubySapphireBrendan[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_RubySapphireBrendan_1,
};

const union AnimCmd *const gTrainerBackAnims_RubySapphireMay[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_RubySapphireMay_1,
};

const union AnimCmd *const gTrainerBackAnims_Wally[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_Wally_1,
};

const union AnimCmd *const gTrainerBackAnims_Steven[] =
{
    gAnimCmd_General_Frame3,
    gAnimCmd_May_Steven_1,
};

const union AnimCmd *const *const gTrainerBackAnimsPtrTable[] =
{
    gTrainerBackAnims_Brendan,
    gTrainerBackAnims_May,
    gTrainerBackAnims_Red,
    gTrainerBackAnims_Leaf,
    gTrainerBackAnims_RubySapphireBrendan,
    gTrainerBackAnims_RubySapphireMay,
    gTrainerBackAnims_Wally,
    gTrainerBackAnims_Steven,
};
