#include "m_cheat.h"
#include "doomdef.h"
#include "d_englsh.h"
#include "p_inter.h"
#include "g_game.h"
#include "global_data.h"


static void cheat_god(void);
static void cheat_choppers(void);
static void cheat_idkfa(void);
static void cheat_ammo(void);
static void cheat_noclip(void);
static void cheat_invincibility(void);
static void cheat_beserk(void);
static void cheat_invisibility(void);
static void cheat_map(void);
static void cheat_goggles(void);
static void cheat_exit(void);
static void cheat_rockets(void);
static void cheat_fps(void);



typedef struct c_cheat
{
    char* name;
    byte sequence[8];
    unsigned int packed_sequence;
    void (*cheat_function)(void);
} c_cheat;

#define CHEAT_PACK(a,b,c,d,e,f,g,h) ((a << 28)|(b << 24)|(c << 20)|(d << 16)|(e << 12)|(f << 8)|(g << 4)|(h))

#define CHEAT_SEQ(a,b,c,d,e,f,g,h) {a,b,c,d,e,f,g,h}, CHEAT_PACK(a,b,c,d,e,f,g,h)

static const c_cheat cheat_def[] =
{
    {"Chainsaw",        CHEAT_SEQ(KEYD_L,   KEYD_UP,    KEYD_UP,    KEYD_LEFT,  KEYD_L,     KEYD_SELECT,    KEYD_SELECT,    KEYD_UP),       cheat_choppers},
    {"God mode",        CHEAT_SEQ(KEYD_UP,  KEYD_UP,    KEYD_DOWN,  KEYD_DOWN,  KEYD_LEFT,  KEYD_LEFT,      KEYD_RIGHT,     KEYD_RIGHT),    cheat_god},
    {"Ammo & Keys",     CHEAT_SEQ(KEYD_L,   KEYD_LEFT,  KEYD_R,     KEYD_RIGHT, KEYD_SELECT,KEYD_UP,        KEYD_SELECT,    KEYD_UP),       cheat_idkfa},
    {"Ammo",            CHEAT_SEQ(KEYD_R,   KEYD_R,     KEYD_SELECT,KEYD_R,     KEYD_SELECT,KEYD_UP,        KEYD_UP,        KEYD_LEFT),     cheat_ammo},
    {"No Clipping",     CHEAT_SEQ(KEYD_UP,  KEYD_DOWN,  KEYD_LEFT,  KEYD_RIGHT, KEYD_UP,    KEYD_DOWN,      KEYD_LEFT,      KEYD_RIGHT),    cheat_noclip},
    {"Invincibility",   CHEAT_SEQ(KEYD_A,   KEYD_B,     KEYD_L,     KEYD_R,     KEYD_L,     KEYD_R,         KEYD_SELECT,    KEYD_SELECT),   cheat_invincibility},
    {"Berserk",         CHEAT_SEQ(KEYD_B,   KEYD_B,     KEYD_R,     KEYD_UP,    KEYD_A,     KEYD_A,         KEYD_R,         KEYD_B),        cheat_beserk},
    {"Invisibility",    CHEAT_SEQ(KEYD_A,   KEYD_A,     KEYD_SELECT,KEYD_B,     KEYD_A,     KEYD_SELECT,    KEYD_L,         KEYD_B),        cheat_invisibility},
    {"Auto-map",        CHEAT_SEQ(KEYD_L,   KEYD_SELECT,KEYD_R,     KEYD_B,     KEYD_A,     KEYD_R,         KEYD_L,         KEYD_UP),       cheat_map},
    {"Lite-Amp Goggles",CHEAT_SEQ(KEYD_DOWN,KEYD_LEFT,  KEYD_R,     KEYD_LEFT,  KEYD_R,     KEYD_L,         KEYD_L,         KEYD_SELECT),   cheat_goggles},
    {"Exit Level",      CHEAT_SEQ(KEYD_LEFT,KEYD_R,     KEYD_LEFT,  KEYD_L,     KEYD_B,     KEYD_LEFT,      KEYD_RIGHT,     KEYD_A),        cheat_exit},

    //Because Goldeneye!
    {"Enemy Rockets",   CHEAT_SEQ(KEYD_A,   KEYD_B,     KEYD_L,     KEYD_R,     KEYD_R,     KEYD_L,         KEYD_B,         KEYD_A),        cheat_rockets},
	{"FPS Counter Ammo",CHEAT_SEQ(KEYD_A,   KEYD_B,     KEYD_L,     KEYD_UP,    KEYD_DOWN,  KEYD_B,         KEYD_LEFT,     KEYD_LEFT),      cheat_fps},
};

static const unsigned int num_cheats = sizeof(cheat_def) / sizeof (c_cheat);

static boolean CheckCheats(unsigned int keybuff)
{
    for(int i = 0; i < num_cheats; i++)
    {
        if(cheat_def[i].packed_sequence == keybuff)
        {
            if(cheat_def[i].cheat_function)
                cheat_def[i].cheat_function();

            return true;
        }
    }

    return false;
}

boolean C_Responder (event_t *ev)
{
    if(ev->type == ev_keydown)
    {
        //To enable fast cheat searching without having to
        //maintain buffer of keypresses, we ensure that
        //cheats are 8 keys long and the key-code is less
        //than 16 so they fit in 4 bits.

        //We can store a full 8 presses in a 32bit int.

        //Adding a press to the list just means shifting the
        //whole thing by 4 and ORing the next press into the
        //low bits.

        //We can test a cheat sequence with a simple int comparison.

        unsigned int cb = _g->cheat_buffer << 4;
        cb |= ev->data1 & 0xf;

        _g->cheat_buffer = cb;

        if(CheckCheats(cb))
            return true; //eat last cheat key.
    }

    return false;
}

static void cheat_god()
{
    _g->player.cheats ^= CF_GODMODE;

    if(_g->player.cheats & CF_GODMODE)
    {
        _g->player.health = god_health;

        _g->player.message = STSTR_DQDON;
    }
    else
    {
        _g->player.message = STSTR_DQDOFF;

    }
}

static void cheat_choppers()
{
    _g->player.weaponowned[wp_chainsaw] = true;
    _g->player.pendingweapon = wp_chainsaw;

    P_GivePower(&_g->player, pw_invulnerability);

    _g->player.message = STSTR_CHOPPERS;
}

static void cheat_idkfa()
{
    int i;

    player_t* plyr = &_g->player;

    if (!plyr->backpack)
    {
        for (i=0 ; i<NUMAMMO ; i++)
            plyr->maxammo[i] *= 2;

        plyr->backpack = true;
    }

    plyr->armorpoints = idfa_armor;      // Ty 03/09/98 - deh
    plyr->armortype = idfa_armor_class;  // Ty 03/09/98 - deh

    // You can't own weapons that aren't in the game // phares 02/27/98
    for (i=0;i<NUMWEAPONS;i++)
        if (!(((i == wp_plasma || i == wp_bfg) && _g->gamemode == shareware) ||
              (i == wp_supershotgun && _g->gamemode != commercial)))
            plyr->weaponowned[i] = true;

    for (i=0;i<NUMAMMO;i++)
        if (i!=am_cell || _g->gamemode!=shareware)
            plyr->ammo[i] = plyr->maxammo[i];

    for (i=0;i<NUMCARDS;i++)
            plyr->cards[i] = true;

    plyr->message = STSTR_KFAADDED;
}

static void cheat_ammo()
{
    int i;
    player_t* plyr = &_g->player;

    if (!plyr->backpack)
    {
        for (i=0 ; i<NUMAMMO ; i++)
            plyr->maxammo[i] *= 2;

        plyr->backpack = true;
    }

    plyr->armorpoints = idfa_armor;      // Ty 03/09/98 - deh
    plyr->armortype = idfa_armor_class;  // Ty 03/09/98 - deh

    // You can't own weapons that aren't in the game // phares 02/27/98
    for (i=0;i<NUMWEAPONS;i++)
        if (!(((i == wp_plasma || i == wp_bfg) && _g->gamemode == shareware) ||
              (i == wp_supershotgun && _g->gamemode != commercial)))
            plyr->weaponowned[i] = true;

    for (i=0;i<NUMAMMO;i++)
        if (i!=am_cell || _g->gamemode!=shareware)
            plyr->ammo[i] = plyr->maxammo[i];

    plyr->message = STSTR_FAADDED;
}

static void cheat_noclip()
{
    _g->player.cheats ^= CF_NOCLIP;

    if(_g->player.cheats & CF_NOCLIP)
    {
        _g->player.message = STSTR_NCON;
    }
    else
    {
        _g->player.message = STSTR_NCOFF;

    }
}

static void cheat_invincibility()
{
    P_GivePower(&_g->player, pw_invulnerability);
}

static void cheat_beserk()
{
    P_GivePower(&_g->player, pw_strength);
}

static void cheat_invisibility()
{
    P_GivePower(&_g->player, pw_invisibility);
}

static void cheat_map()
{
    P_GivePower(&_g->player, pw_allmap);
}

static void cheat_goggles()
{
    P_GivePower(&_g->player, pw_infrared);
}

static void cheat_exit()
{
    G_ExitLevel();
}

static void cheat_rockets()
{
    _g->player.cheats ^= CF_ENEMY_ROCKETS;

    if(_g->player.cheats & CF_ENEMY_ROCKETS)
    {
        _g->player.health = god_health;

        _g->player.weaponowned[wp_missile] = true;
        _g->player.ammo[am_misl] = _g->player.maxammo[am_misl];

        _g->player.pendingweapon = wp_missile;

        _g->player.message = STSTR_ROCKETON;
    }
    else
    {
        _g->player.message = STSTR_ROCKETOFF;
    }
}

static void cheat_fps()
{
    _g->fps_show = !_g->fps_show;
	if(_g->fps_show)
	{
		_g->player.message = STSTR_FPSON;
	}else
	{
		_g->player.message = STSTR_FPSOFF;
	}
}