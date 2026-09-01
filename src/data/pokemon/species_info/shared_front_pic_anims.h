static const union AnimCmd *const sAnims_SingleFramePlaceHolder[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_TwoFramePlaceHolder[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 30),
        ANIMCMD_FRAME(1, 30),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};

#if P_FAMILY_RATTATA
#if P_ALOLAN_FORMS
static const union AnimCmd *const sAnims_RaticateAlola[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 11),
            ANIMCMD_FRAME(0, 1),
	        ANIMCMD_END,
	},
};
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_RATTATA

#if P_FAMILY_CUBONE
#if P_ALOLAN_FORMS
static const union AnimCmd *const sAnims_MarowakAlola[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
            ANIMCMD_FRAME(1, 14),
            ANIMCMD_FRAME(0, 14),
	        ANIMCMD_END,
	},
};
#endif //P_ALOLAN_FORMS
#endif //P_FAMILY_CUBONE

#if P_FAMILY_BURMY
static const union AnimCmd *const sAnims_Burmy[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 32),
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Wormadam[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Mothim[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(1, 4),
        ANIMCMD_FRAME(0, 6),
        ANIMCMD_FRAME(1, 6),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 5),
        ANIMCMD_FRAME(0, 25),
        ANIMCMD_FRAME(1, 6),
        ANIMCMD_FRAME(0, 6),
        ANIMCMD_FRAME(1, 4),
        ANIMCMD_FRAME(0, 4),
        ANIMCMD_FRAME(1, 5),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_BURMY

#if P_FAMILY_SHELLOS
static const union AnimCmd *const sAnims_Shellos[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_FRAME(1, 36),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Gastrodon[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_SHELLOS

#if P_FAMILY_ARCEUS
static const union AnimCmd *const sAnims_Arceus[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 12),
        ANIMCMD_FRAME(1, 45),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_ARCEUS

#if P_FAMILY_BASCULIN
static const union AnimCmd *const sAnims_Basculin[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 20),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_BASCULIN

#if P_FAMILY_DEERLING
static const union AnimCmd *const sAnims_Deerling[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Sawsbuck[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_DEERLING

#if P_FAMILY_GENESECT
static const union AnimCmd *const sAnims_Genesect[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 5),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 25),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 5),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 5),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_GENESECT

#if P_FAMILY_FROAKIE
static const union AnimCmd *const sAnims_Greninja[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 32),
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_GRENINJA

#if P_FAMILY_SCATTERBUG
static const union AnimCmd *const sAnims_Scatterbug[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 35),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Spewpa[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 18),
        ANIMCMD_FRAME(1, 18),
        ANIMCMD_FRAME(0, 18),
        ANIMCMD_FRAME(1, 18),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Vivillon[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 50),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_SCATTERBUG

#if P_FAMILY_FLABEBE
static const union AnimCmd *const sAnims_Flabebe[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 27),
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_FRAME(1, 23),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Floette[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 25),
        ANIMCMD_FRAME(1, 50),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Florges[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 45),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_FLABEBE

#if P_FAMILY_FURFROU
static const union AnimCmd *const sAnims_Furfrou[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 27),
        ANIMCMD_FRAME(1, 6),
        ANIMCMD_FRAME(0, 6),
        ANIMCMD_FRAME(1, 6),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_FURFROU

#if P_FAMILY_ESPURR
static const union AnimCmd *const sAnims_Meowstic[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 12),
        ANIMCMD_FRAME(1, 45),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_MEOWSTIC

#if P_FAMILY_PUMPKABOO
static const union AnimCmd *const sAnims_Pumpkaboo[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 12),
        ANIMCMD_FRAME(0, 12),
        ANIMCMD_FRAME(1, 12),
        ANIMCMD_FRAME(0, 30),
        ANIMCMD_FRAME(1, 12),
        ANIMCMD_FRAME(0, 12),
        ANIMCMD_FRAME(1, 12),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Gourgeist[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_FRAME(1, 15),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_PUMPKABOO

#if P_FAMILY_XERNEAS
static const union AnimCmd *const sAnims_Xerneas[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 12),
        ANIMCMD_FRAME(1, 45),
        ANIMCMD_FRAME(0, 15),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_XERNEAS

#if P_FAMILY_ZYGARDE
static const union AnimCmd *const sAnims_Zygarde50[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 25),
        ANIMCMD_FRAME(0, 30),
        ANIMCMD_END,
    },
};

static const union AnimCmd *const sAnims_Zygarde10[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_ZYGARDE

#if P_FAMILY_YUNGOOS
static const union AnimCmd *const sAnims_Gumshoos[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 60),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_YUNGOOS

#if P_FAMILY_GRUBBIN
static const union AnimCmd *const sAnims_Vikavolt[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 10),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_GRUBBIN

#if P_FAMILY_CUTIEFLY
static const union AnimCmd *const sAnims_Ribombee[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_CUTIEFLY

#if P_FAMILY_ROCKRUFF
static const union AnimCmd *const sAnims_Rockruff[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 9),
        ANIMCMD_FRAME(0, 8),
        ANIMCMD_FRAME(1, 8),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_ROCKRUFF

#if P_FAMILY_DEWPIDER
static const union AnimCmd *const sAnims_Araquanid[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_FRAME(1, 45),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_DEWPIDER

#if P_FAMILY_FOMANTIS
static const union AnimCmd *const sAnims_Lurantis[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_FRAME(1, 35),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_FOMANTIS

#if P_FAMILY_SALANDIT
static const union AnimCmd *const sAnims_Salazzle[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 30),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_SALANDIT

#if P_FAMILY_TOGEDEMARU
static const union AnimCmd *const sAnims_Togedemaru[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 30),
        ANIMCMD_FRAME(0, 5),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_TOGEDEMARU

#if P_FAMILY_MIMIKYU
static const union AnimCmd *const sAnims_MimikyuDisguised[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 30),
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 20),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_MIMIKYU

#if P_FAMILY_JANGMO_O
static const union AnimCmd *const sAnims_Kommo_O[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(0, 10),
        ANIMCMD_FRAME(1, 20),
        ANIMCMD_FRAME(0, 20),
        ANIMCMD_FRAME(1, 20),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_JANGMO_O

#if P_FAMILY_MAGEARNA
static const union AnimCmd *const sAnims_Magearna[] =
{
    sAnim_GeneralFrame0,
    (const union AnimCmd[]) {
        ANIMCMD_FRAME(1, 40),
        ANIMCMD_FRAME(1, 40),
        ANIMCMD_FRAME(1, 40),
        ANIMCMD_FRAME(0, 1),
        ANIMCMD_END,
    },
};
#endif //P_FAMILY_JANGMO_O
