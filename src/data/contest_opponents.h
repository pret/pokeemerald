
#include "global.h"
#include "contest.h"

#define CONTEST_OPPONENT_JIMMY 0
#define CONTEST_OPPONENT_EDITH 1
#define CONTEST_OPPONENT_EVAN 2
#define CONTEST_OPPONENT_KELSEY 3
#define CONTEST_OPPONENT_MADISON 4
#define CONTEST_OPPONENT_RAYMOND 5
#define CONTEST_OPPONENT_GRANT 6
#define CONTEST_OPPONENT_PAIGE 7
#define CONTEST_OPPONENT_ALEC 8
#define CONTEST_OPPONENT_SYDNEY 9
#define CONTEST_OPPONENT_MORRIS 10
#define CONTEST_OPPONENT_MARIAH 11
#define CONTEST_OPPONENT_RUSSELL 12
#define CONTEST_OPPONENT_MELANIE 13
#define CONTEST_OPPONENT_CHANCE 14
#define CONTEST_OPPONENT_AGATHA 15
#define CONTEST_OPPONENT_BEAU 16
#define CONTEST_OPPONENT_KAY 17
#define CONTEST_OPPONENT_CALE 18
#define CONTEST_OPPONENT_CAITLIN 19
#define CONTEST_OPPONENT_COLBY 20
#define CONTEST_OPPONENT_KYLIE 21
#define CONTEST_OPPONENT_LIAM 22
#define CONTEST_OPPONENT_MILO 23
#define CONTEST_OPPONENT_KARINA 24
#define CONTEST_OPPONENT_BOBBY 25
#define CONTEST_OPPONENT_CLAIRE 26
#define CONTEST_OPPONENT_WILLIE 27
#define CONTEST_OPPONENT_CASSIDY 28
#define CONTEST_OPPONENT_MORGAN 29
#define CONTEST_OPPONENT_SUMMER 30
#define CONTEST_OPPONENT_MILES 31
#define CONTEST_OPPONENT_AUDREY 32
#define CONTEST_OPPONENT_AVERY 33
#define CONTEST_OPPONENT_ARIANA 34
#define CONTEST_OPPONENT_ASHTON 35
#define CONTEST_OPPONENT_SANDRA 36
#define CONTEST_OPPONENT_CARSON 37
#define CONTEST_OPPONENT_KATRINA 38
#define CONTEST_OPPONENT_LUKE 39
#define CONTEST_OPPONENT_RAUL 40
#define CONTEST_OPPONENT_JADA 41
#define CONTEST_OPPONENT_ZEEK 42
#define CONTEST_OPPONENT_DIEGO 43
#define CONTEST_OPPONENT_ALIYAH 44
#define CONTEST_OPPONENT_NATALIA 45
#define CONTEST_OPPONENT_DEVIN 46
#define CONTEST_OPPONENT_TYLOR 47
#define CONTEST_OPPONENT_RONNIE 48
#define CONTEST_OPPONENT_CLAUDIA 49
#define CONTEST_OPPONENT_ELIAS 50
#define CONTEST_OPPONENT_JADE 51
#define CONTEST_OPPONENT_FRANCIS 52
#define CONTEST_OPPONENT_ALISHA 53
#define CONTEST_OPPONENT_SAUL 54
#define CONTEST_OPPONENT_FELICIA 55
#define CONTEST_OPPONENT_EMILIO 56
#define CONTEST_OPPONENT_KARLA 57
#define CONTEST_OPPONENT_DARRYL 58
#define CONTEST_OPPONENT_SELENA 59
#define CONTEST_OPPONENT_NOEL 60
#define CONTEST_OPPONENT_LACEY 61
#define CONTEST_OPPONENT_CORBIN 62
#define CONTEST_OPPONENT_GRACIE 63
#define CONTEST_OPPONENT_COLTIN 64
#define CONTEST_OPPONENT_ELLIE 65
#define CONTEST_OPPONENT_MARCUS 66
#define CONTEST_OPPONENT_KIARA 67
#define CONTEST_OPPONENT_BRYCE 68
#define CONTEST_OPPONENT_JAMIE 69
#define CONTEST_OPPONENT_JORGE 70
#define CONTEST_OPPONENT_DEVON 71
#define CONTEST_OPPONENT_JUSTINA 72
#define CONTEST_OPPONENT_RALPH 73
#define CONTEST_OPPONENT_ROSA 74
#define CONTEST_OPPONENT_KEATON 75
#define CONTEST_OPPONENT_MAYRA 76
#define CONTEST_OPPONENT_LAMAR 77
#define CONTEST_OPPONENT_AUBREY 78
#define CONTEST_OPPONENT_NIGEL 79
#define CONTEST_OPPONENT_CAMILLE 80
#define CONTEST_OPPONENT_DEON 81
#define CONTEST_OPPONENT_JANELLE 82
#define CONTEST_OPPONENT_HEATH 83
#define CONTEST_OPPONENT_SASHA 84
#define CONTEST_OPPONENT_FRANKIE 85
#define CONTEST_OPPONENT_HELEN 86
#define CONTEST_OPPONENT_CAMILE 87
#define CONTEST_OPPONENT_MARTIN 88
#define CONTEST_OPPONENT_SERGIO 89
#define CONTEST_OPPONENT_KAILEY 90
#define CONTEST_OPPONENT_PERLA 91
#define CONTEST_OPPONENT_CLARA 92
#define CONTEST_OPPONENT_JAKOB 93
#define CONTEST_OPPONENT_TREY 94
#define CONTEST_OPPONENT_LANE 95

// All contest opponents have a common set of AI flags (which contains all of the actually
// useful AI scripts, as well as some dummys) and a random combination of 2-3 dummy flags.
// Seems that like the battle AI they had more plans for this than what ended up in the final game
#define CONTEST_AI_SET_1  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_2  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_19 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_3  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_4  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_5  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_6  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_7  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_8  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_9  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_A  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_11 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_B  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_C  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_D  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_22 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_E  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_24)
#define CONTEST_AI_SET_F  (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_10 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_23)
#define CONTEST_AI_SET_11 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_18 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_12 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_17 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_13 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_16 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_14 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_15 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_22)
#define CONTEST_AI_SET_16 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_13 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_17 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_23 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_18 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_10 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_19 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_9  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1A (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_8  | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1B (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1C (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_6  | CONTEST_AI_DUMMY_21)
#define CONTEST_AI_SET_1D (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_20 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1E (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_15 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_1F (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_14 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_20 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_12 | CONTEST_AI_DUMMY_25)
#define CONTEST_AI_SET_21 (CONTEST_AI_COMMON | CONTEST_AI_DUMMY_7  | CONTEST_AI_DUMMY_25)

const struct ContestWinner gDefaultContestWinners[] =
{
    [CONTEST_WINNER_HALL_1 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_ELECTRIKE,
        .contestCategory = CONTEST_CATEGORY_CUTE,
    #if FRENCH
        .monName = _("DYNONO"),
        .trainerName = _("AXEL"),
    #elif ITALIAN
        .monName = _("ELECTER"),
        .trainerName = _("EZRA"),
    #else //ENGLISH
        .monName = _("ELECTER"),
        .trainerName = _("EZRA"),
    #endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_2 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_TROPIUS,
        .contestCategory = CONTEST_CATEGORY_COOL,
    #if FRENCH
        .monName = _("TROPO"),
        .trainerName = _("NICOLAS"),
    #elif ITALIAN
        .monName = _("TROPO"),
        .trainerName = _("ALLAN"),
    #else //ENGLISH
        .monName = _("TROPO"),
        .trainerName = _("ALLAN"),
    #endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_3 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_XATU,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
    #if FRENCH
        .monName = _("TUXA"),
        .trainerName = _("JULIA"),
    #elif ITALIAN
        .monName = _("TUXA"),
        .trainerName = _("JULIET"),
    #else //ENGLISH
        .monName = _("TUXA"),
        .trainerName = _("JULIET"),
    #endif
        .contestRank = CONTEST_RANK_NORMAL
    },
    [CONTEST_WINNER_HALL_4 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_PLUSLE,
        .contestCategory = CONTEST_CATEGORY_TOUGH,
    #if FRENCH
        .monName = _("POSSI"),
        .trainerName = _("ELTON"),
    #elif ITALIAN
        .monName = _("PULSE"),
        .trainerName = _("LEIO"),
    #else //ENGLISH
        .monName = _("PULSE"),
        .trainerName = _("BAILY"),
    #endif
        .contestRank = CONTEST_RANK_MASTER
    },
    [CONTEST_WINNER_HALL_5 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_SHUPPET,
        .contestCategory = CONTEST_CATEGORY_SMART,
    #if FRENCH
        .monName = _("CHOMBY"),
        .trainerName = _("MELANIE"),
    #elif ITALIAN
        .monName = _("SHUPUP"),
        .trainerName = _("MELANY"),
    #else //ENGLISH
        .monName = _("SHUPUP"),
        .trainerName = _("MELANY"),
    #endif
        .contestRank = CONTEST_RANK_SUPER
    },
    [CONTEST_WINNER_HALL_6 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_ZANGOOSE,
        .contestCategory = CONTEST_CATEGORY_COOL,
    #if FRENCH
        .monName = _("GRIFFIK"),
        .trainerName = _("ANNE"),
    #elif ITALIAN
        .monName = _("GOOZAN"),
        .trainerName = _("HANA"),
    #else //ENGLISH
        .monName = _("GOOZAN"),
        .trainerName = _("HANA"),
    #endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_1 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_LOUDRED,
        .contestCategory = CONTEST_CATEGORY_BEAUTY,
    #if FRENCH
        .monName = _("BABOUM"),
        .trainerName = _("JACO"),
    #elif ITALIAN
        .monName = _("LOUDED"),
        .trainerName = _("BERTO"),
    #else //ENGLISH
        .monName = _("LOUDED"),
        .trainerName = _("BRYANT"),
    #endif
        .contestRank = CONTEST_RANK_HYPER
    },
    [CONTEST_WINNER_HALL_UNUSED_2 - 1] = {
        .personality = 0,
        .trainerId = 0xFFFF,
        .species = SPECIES_DELCATTY,
        .contestCategory = CONTEST_CATEGORY_CUTE,
    #if FRENCH
        .monName = _("KITSY"),
        .trainerName = _("OMAR"),
    #elif ITALIAN
        .monName = _("KITSY"),
        .trainerName = _("OMAR"),
    #else //ENGLISH
        .monName = _("KITSY"),
        .trainerName = _("OMAR"),
    #endif
        .contestRank = CONTEST_RANK_MASTER
    }
};

const struct ContestPokemon gContestOpponents[] =
{
    [CONTEST_OPPONENT_JIMMY] = {
        .species = SPECIES_POOCHYENA,
    #if FRENCH
        .nickname = _("PUPUCE"),
        .trainerName = _("OLIVE"),
    #elif ITALIAN
        .nickname = _("POOCHY"),
        .trainerName = _("JIMMY"),
    #else //ENGLISH
        .nickname = _("POOCHY"),
        .trainerName = _("JIMMY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_BITE,
            MOVE_TAKE_DOWN,
            MOVE_HOWL
        },
        .cool = 10,
        .beauty = 4,
        .cute = 10,
        .smart = 3,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EDITH] = {
        .species = SPECIES_ILLUMISE,
    #if FRENCH
        .nickname = _("MUMI"),
        .trainerName = _("EDITH"),
    #elif ITALIAN
        .nickname = _("MUSILLE"),
        .trainerName = _("AMBRA"),
    #else //ENGLISH
        .nickname = _("MUSILLE"),
        .trainerName = _("EDITH"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_REST,
            MOVE_FACADE,
            MOVE_TACKLE,
            MOVE_COVET
        },
        .cool = 10,
        .beauty = 10,
        .cute = 6,
        .smart = 1,
        .tough = 2,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EVAN] = {
        .species = SPECIES_DUSTOX,
    #if FRENCH
        .nickname = _("PINOX"),
        .trainerName = _("HUGUES"),
    #elif ITALIAN
        .nickname = _("DUSTER"),
        .trainerName = _("IVANO"),
    #else //ENGLISH
        .nickname = _("DUSTER"),
        .trainerName = _("EVAN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SILVER_WIND,
            MOVE_MOONLIGHT,
            MOVE_LIGHT_SCREEN,
            MOVE_GUST
        },
        .cool = 2,
        .beauty = 10,
        .cute = 10,
        .smart = 12,
        .tough = 4,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KELSEY] = {
        .species = SPECIES_SEEDOT,
    #if FRENCH
        .nickname = _("NIPIOT"),
        .trainerName = _("JOHANN"),
    #elif ITALIAN
        .nickname = _("DOTS"),
        .trainerName = _("CAROLA"),
    #else //ENGLISH
        .nickname = _("DOTS"),
        .trainerName = _("KELSEY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BIDE,
            MOVE_SYNTHESIS,
            MOVE_BULLET_SEED,
            MOVE_GROWTH
        },
        .cool = 3,
        .beauty = 3,
        .cute = 5,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MADISON] = {
        .species = SPECIES_TAILLOW,
    #if FRENCH
        .nickname = _("NINI"),
        .trainerName = _("ANNE"),
    #elif ITALIAN
        .nickname = _("TATAY"),
        .trainerName = _("LILLY"),
    #else //ENGLISH
        .nickname = _("TATAY"),
        .trainerName = _("MADISON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WING_ATTACK,
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_GROWL
        },
        .cool = 1,
        .beauty = 3,
        .cute = 3,
        .smart = 5,
        .tough = 4,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RAYMOND] = {
        .species = SPECIES_NINCADA,
    #if FRENCH
        .nickname = _("GRINJA"),
        .trainerName = _("SEB"),
    #elif ITALIAN
        .nickname = _("NINDA"),
        .trainerName = _("RAYMOND"),
    #else //ENGLISH
        .nickname = _("NINDA"),
        .trainerName = _("RAYMOND"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_LEECH_LIFE,
            MOVE_FALSE_SWIPE,
            MOVE_FURY_SWIPES,
            MOVE_MIND_READER
        },
        .cool = 5,
        .beauty = 2,
        .cute = 10,
        .smart = 7,
        .tough = 8,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_GRANT] = {
        .species = SPECIES_SHROOMISH,
    #if FRENCH
        .nickname = _("BOUBOU"),
        .trainerName = _("QUENTIN"),
    #elif ITALIAN
        .nickname = _("SMISH"),
        .trainerName = _("GIGIO"),
    #else //ENGLISH
        .nickname = _("SMISH"),
        .trainerName = _("GRANT"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_STUN_SPORE,
            MOVE_LEECH_SEED,
            MOVE_MEGA_DRAIN,
            MOVE_ATTRACT
        },
        .cool = 3,
        .beauty = 3,
        .cute = 10,
        .smart = 2,
        .tough = 2,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_PAIGE] = {
        .species = SPECIES_SPHEAL,
    #if FRENCH
        .nickname = _("OBLIE"),
        .trainerName = _("CHANCE"),
    #elif ITALIAN
        .nickname = _("SPHELI"),
        .trainerName = _("LORENA"),
    #else //ENGLISH
        .nickname = _("SLEAL"),
        .trainerName = _("PAIGE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AURORA_BEAM,
            MOVE_WATER_GUN,
            MOVE_GROWL,
            MOVE_ROCK_TOMB
        },
        .cool = 3,
        .beauty = 5,
        .cute = 1,
        .smart = 10,
        .tough = 10,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ALEC] = {
        .species = SPECIES_SLAKOTH,
    #if FRENCH
        .nickname = _("PATROVIT"),
        .trainerName = _("STEF"),
    #elif ITALIAN
        .nickname = _("SLOKTH"),
        .trainerName = _("EZIO"),
    #else //ENGLISH
        .nickname = _("SLOKTH"),
        .trainerName = _("ALEC"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_COUNTER,
            MOVE_YAWN,
            MOVE_ENCORE
        },
        .cool = 10,
        .beauty = 4,
        .cute = 4,
        .smart = 5,
        .tough = 18,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SYDNEY] = {
        .species = SPECIES_WHISMUR,
    #if FRENCH
        .nickname = _("CHUTI"),
        .trainerName = _("ALBANE"),
    #elif ITALIAN
        .nickname = _("WHIRIS"),
        .trainerName = _("LUANA"),
    #else //ENGLISH
        .nickname = _("WHIRIS"),
        .trainerName = _("SYDNEY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_SCREECH,
            MOVE_UPROAR,
            MOVE_HYPER_VOICE
        },
        .cool = 2,
        .beauty = 2,
        .cute = 7,
        .smart = 2,
        .tough = 7,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MORRIS] = {
        .species = SPECIES_MAKUHITA,
    #if FRENCH
        .nickname = _("MAHITA"),
        .trainerName = _("DANIEL"),
    #elif ITALIAN
        .nickname = _("MAHITA"),
        .trainerName = _("SABINO"),
    #else //ENGLISH
        .nickname = _("MAHITA"),
        .trainerName = _("MORRIS"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_B,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_VITAL_THROW,
            MOVE_TACKLE,
            MOVE_REVERSAL
        },
        .cool = 9,
        .beauty = 1,
        .cute = 1,
        .smart = 8,
        .tough = 1,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MARIAH] = {
        .species = SPECIES_ARON,
    #if FRENCH
        .nickname = _("GALI"),
        .trainerName = _("MARION"),
    #elif ITALIAN
        .nickname = _("RONAR"),
        .trainerName = _("LIALA"),
    #else //ENGLISH
        .nickname = _("RONAR"),
        .trainerName = _("MARIAH"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_C,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_CLAW,
            MOVE_IRON_DEFENSE,
            MOVE_HEADBUTT,
            MOVE_TAKE_DOWN
        },
        .cool = 5,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 2,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RUSSELL] = {
        .species = SPECIES_CROBAT,
    #if FRENCH
        .nickname = _("FEFE"),
        .trainerName = _("DENIS"),
    #elif ITALIAN
        .nickname = _("BATRO"),
        .trainerName = _("GIULIO"),
    #else //ENGLISH
        .nickname = _("BATRO"),
        .trainerName = _("RUSSELL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_D,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HAZE,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_LEECH_LIFE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 2,
        .smart = 2,
        .tough = 10,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MELANIE] = {
        .species = SPECIES_GULPIN,
    #if FRENCH
        .nickname = _("SLURP"),
        .trainerName = _("JOANNE"),
    #elif ITALIAN
        .nickname = _("GULIN"),
        .trainerName = _("MELANIE"),
    #else //ENGLISH
        .nickname = _("GULIN"),
        .trainerName = _("MELANIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_E,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SLUDGE,
            MOVE_AMNESIA,
            MOVE_TOXIC,
            MOVE_YAWN
        },
        .cool = 1,
        .beauty = 10,
        .cute = 1,
        .smart = 10,
        .tough = 5,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CHANCE] = {
        .species = SPECIES_MANECTRIC,
    #if FRENCH
        .nickname = _("DYNI"),
        .trainerName = _("ALEX"),
    #elif ITALIAN
        .nickname = _("RIKELEC"),
        .trainerName = _("BIAGIO"),
    #else //ENGLISH
        .nickname = _("RIKELEC"),
        .trainerName = _("CHANCE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPARK,
            MOVE_THUNDER_WAVE,
            MOVE_THUNDER,
            MOVE_ROAR
        },
        .cool = 20,
        .beauty = 10,
        .cute = 1,
        .smart = 1,
        .tough = 1,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AGATHA] = {
        .species = SPECIES_BULBASAUR,
    #if FRENCH
        .nickname = _("BULBI"),
        .trainerName = _("AGATHA"),
    #elif ITALIAN
        .nickname = _("BULBY"),
        .trainerName = _("AGATHA"),
    #else //ENGLISH
        .nickname = _("BULBY"),
        .trainerName = _("AGATHA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_LEECH_SEED,
            MOVE_TACKLE,
            MOVE_SWEET_SCENT
        },
        .cool = 5,
        .beauty = 3,
        .cute = 10,
        .smart = 10,
        .tough = 4,
        .sheen = 50,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_BEAU] = {
        .species = SPECIES_BUTTERFREE,
    #if FRENCH
        .nickname = _("PAPILOU"),
        .trainerName = _("JANIE"),
    #elif ITALIAN
        .nickname = _("FUTTERBE"),
        .trainerName = _("BEBA"),
    #else //ENGLISH
        .nickname = _("FUTTERBE"),
        .trainerName = _("BEAU"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SUPERSONIC,
            MOVE_WHIRLWIND,
            MOVE_SILVER_WIND,
            MOVE_SAFEGUARD
        },
        .cool = 3,
        .beauty = 10,
        .cute = 2,
        .smart = 10,
        .tough = 4,
        .sheen = 60,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KAY] = {
        .species = SPECIES_PIDGEOTTO,
    #if FRENCH
        .nickname = _("KOUKOU"),
        .trainerName = _("KATY"),
    #elif ITALIAN
        .nickname = _("PIDEOT"),
        .trainerName = _("KALY"),
    #else //ENGLISH
        .nickname = _("PIDEOT"),
        .trainerName = _("KAY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_QUICK_ATTACK,
            MOVE_AERIAL_ACE,
            MOVE_FEATHER_DANCE
        },
        .cool = 10,
        .beauty = 8,
        .cute = 4,
        .smart = 2,
        .tough = 3,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CALE] = {
        .species = SPECIES_DIGLETT,
    #if FRENCH
        .nickname = _("PIKPIK"),
        .trainerName = _("AYMERIC"),
    #elif ITALIAN
        .nickname = _("DIGLE"),
        .trainerName = _("CARLINO"),
    #else //ENGLISH
        .nickname = _("DIGLE"),
        .trainerName = _("CALE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DIG,
            MOVE_EARTHQUAKE,
            MOVE_FISSURE,
            MOVE_MAGNITUDE
        },
        .cool = 4,
        .beauty = 2,
        .cute = 3,
        .smart = 5,
        .tough = 10,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CAITLIN] = {
        .species = SPECIES_POLIWAG,
    #if FRENCH
        .nickname = _("TARPI"),
        .trainerName = _("EMMA"),
    #elif ITALIAN
        .nickname = _("POLI"),
        .trainerName = _("CADALIA"),
    #else //ENGLISH
        .nickname = _("WAGIL"),
        .trainerName = _("CAITLIN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TUBER_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BODY_SLAM,
            MOVE_ICE_BEAM
        },
        .cool = 2,
        .beauty = 10,
        .cute = 5,
        .smart = 3,
        .tough = 10,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_COLBY] = {
        .species = SPECIES_TOTODILE,
    #if FRENCH
        .nickname = _("KAKIM"),
        .trainerName = _("KEVIN"),
    #elif ITALIAN
        .nickname = _("TOTDIL"),
        .trainerName = _("CICCO"),
    #else //ENGLISH
        .nickname = _("TOTDIL"),
        .trainerName = _("COLBY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_NINJA_BOY,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_RAGE,
            MOVE_SCREECH,
            MOVE_SURF,
            MOVE_BLIZZARD
        },
        .cool = 6,
        .beauty = 10,
        .cute = 2,
        .smart = 1,
        .tough = 5,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KYLIE] = {
        .species = SPECIES_LEDYBA,
    #if FRENCH
        .nickname = _("KOXX"),
        .trainerName = _("MARIE"),
    #elif ITALIAN
        .nickname = _("BALEDY"),
        .trainerName = _("KYLIE"),
    #else //ENGLISH
        .nickname = _("BALEDY"),
        .trainerName = _("KYLIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_BATON_PASS,
            MOVE_AGILITY,
            MOVE_SWIFT,
            MOVE_ATTRACT
        },
        .cool = 8,
        .beauty = 6,
        .cute = 8,
        .smart = 6,
        .tough = 2,
        .sheen = 90,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LIAM] = {
        .species = SPECIES_DELIBIRD,
    #if FRENCH
        .nickname = _("DIZY"),
        .trainerName = _("LIAM"),
    #elif ITALIAN
        .nickname = _("BIRDLY"),
        .trainerName = _("LARO"),
    #else //ENGLISH
        .nickname = _("BIRDLY"),
        .trainerName = _("LIAM"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PRESENT,
            MOVE_FACADE,
            MOVE_FOCUS_PUNCH,
            MOVE_RETURN
        },
        .cool = 4,
        .beauty = 3,
        .cute = 10,
        .smart = 5,
        .tough = 3,
        .sheen = 80,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MILO] = {
        .species = SPECIES_LARVITAR,
    #if FRENCH
        .nickname = _("BRIBRI"),
        .trainerName = _("SAM"),
    #elif ITALIAN
        .nickname = _("TARVITAR"),
        .trainerName = _("MILO"),
    #else //ENGLISH
        .nickname = _("TARVITAR"),
        .trainerName = _("MILO"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_NORMAL,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_TORMENT,
            MOVE_CRUNCH,
            MOVE_DIG
        },
        .cool = 8,
        .beauty = 5,
        .cute = 5,
        .smart = 8,
        .tough = 10,
        .sheen = 70,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KARINA] = {
        .species = SPECIES_ROSELIA,
    #if FRENCH
        .nickname = _("RELIA"),
        .trainerName = _("LYDIA"),
    #elif ITALIAN
        .nickname = _("RELIA"),
        .trainerName = _("BRUNA"),
    #else //ENGLISH
        .nickname = _("RELIA"),
        .trainerName = _("KARINA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_10,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_MAGICAL_LEAF,
            MOVE_GRASS_WHISTLE,
            MOVE_INGRAIN
        },
        .cool = 50,
        .beauty = 15,
        .cute = 75,
        .smart = 10,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_BOBBY] = {
        .species = SPECIES_DODRIO,
    #if FRENCH
        .nickname = _("DUODO"),
        .trainerName = _("NICO"),
    #elif ITALIAN
        .nickname = _("DUODO"),
        .trainerName = _("BOBBY"),
    #else //ENGLISH
        .nickname = _("DUODO"),
        .trainerName = _("BOBBY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_PECK,
            MOVE_FURY_ATTACK,
            MOVE_RETURN,
            MOVE_GROWL
        },
        .cool = 15,
        .beauty = 21,
        .cute = 15,
        .smart = 85,
        .tough = 35,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CLAIRE] = {
        .species = SPECIES_TRAPINCH,
    #if FRENCH
        .nickname = _("KRAKY"),
        .trainerName = _("FRANCE"),
    #elif ITALIAN
        .nickname = _("PINCHIN"),
        .trainerName = _("CLARA"),
    #else //ENGLISH
        .nickname = _("PINCHIN"),
        .trainerName = _("CLAIRE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BITE,
            MOVE_SAND_ATTACK,
            MOVE_DIG,
            MOVE_FAINT_ATTACK
        },
        .cool = 75,
        .beauty = 25,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_WILLIE] = {
        .species = SPECIES_CACNEA,
    #if FRENCH
        .nickname = _("NACAC"),
        .trainerName = _("YANNICK"),
    #elif ITALIAN
        .nickname = _("NACAC"),
        .trainerName = _("WILLY"),
    #else //ENGLISH
        .nickname = _("NACAC"),
        .trainerName = _("WILLIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPIKES,
            MOVE_LEER,
            MOVE_POISON_STING,
            MOVE_SAND_ATTACK
        },
        .cool = 10,
        .beauty = 30,
        .cute = 25,
        .smart = 65,
        .tough = 25,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CASSIDY] = {
        .species = SPECIES_SANDSLASH,
    #if FRENCH
        .nickname = _("BLETTE"),
        .trainerName = _("RAISSA"),
    #elif ITALIAN
        .nickname = _("SHRAND"),
        .trainerName = _("CLOE"),
    #else //ENGLISH
        .nickname = _("SHRAND"),
        .trainerName = _("CASSIDY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_13,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SLASH,
            MOVE_DEFENSE_CURL,
            MOVE_SWIFT,
            MOVE_FURY_SWIPES
        },
        .cool = 30,
        .beauty = 90,
        .cute = 30,
        .smart = 10,
        .tough = 100,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MORGAN] = {
        .species = SPECIES_BALTOY,
    #if FRENCH
        .nickname = _("BALBU"),
        .trainerName = _("DIMITRI"),
    #elif ITALIAN
        .nickname = _("TOYBAL"),
        .trainerName = _("DAVIDE"),
    #else //ENGLISH
        .nickname = _("TOYBAL"),
        .trainerName = _("MORGAN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_14,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SELF_DESTRUCT,
            MOVE_ROCK_TOMB,
            MOVE_PSYBEAM,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 40,
        .cute = 10,
        .smart = 35,
        .tough = 35,
        .sheen = 150,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SUMMER] = {
        .species = SPECIES_MEDICHAM,
    #if FRENCH
        .nickname = _("CHARMILLE"),
        .trainerName = _("OLGA"),
    #elif ITALIAN
        .nickname = _("CHAMCHAM"),
        .trainerName = _("DIANA"),
    #else //ENGLISH
        .nickname = _("CHAMCHAM"),
        .trainerName = _("SUMMER"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_15,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_THUNDER_PUNCH,
            MOVE_FIRE_PUNCH,
            MOVE_ICE_PUNCH
        },
        .cool = 40,
        .beauty = 20,
        .cute = 40,
        .smart = 40,
        .tough = 40,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MILES] = {
        .species = SPECIES_SPINDA,
    #if FRENCH
        .nickname = _("SPININ"),
        .trainerName = _("XAVIER"),
    #elif ITALIAN
        .nickname = _("SPININ"),
        .trainerName = _("MARK"),
    #else //ENGLISH
        .nickname = _("SPININ"),
        .trainerName = _("MILES"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_TEETER_DANCE,
            MOVE_PSYCH_UP,
            MOVE_HYPNOSIS,
            MOVE_UPROAR
        },
        .cool = 25,
        .beauty = 75,
        .cute = 25,
        .smart = 10,
        .tough = 25,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AUDREY] = {
        .species = SPECIES_SWABLU,
    #if FRENCH
        .nickname = _("VEGA"),
        .trainerName = _("AUDREY"),
    #elif ITALIAN
        .nickname = _("SWABY"),
        .trainerName = _("AZZURRA"),
    #else //ENGLISH
        .nickname = _("SWABY"),
        .trainerName = _("AUDREY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_17,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MIRROR_MOVE,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD,
            MOVE_MIST
        },
        .cool = 30,
        .beauty = 30,
        .cute = 40,
        .smart = 30,
        .tough = 25,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AVERY] = {
        .species = SPECIES_SPOINK,
    #if FRENCH
        .nickname = _("PIGPIG"),
        .trainerName = _("GREG"),
    #elif ITALIAN
        .nickname = _("POINKER"),
        .trainerName = _("FABIO"),
    #else //ENGLISH
        .nickname = _("POINKER"),
        .trainerName = _("AVERY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SPLASH,
            MOVE_CONFUSE_RAY,
            MOVE_SNORE,
            MOVE_REST
        },
        .cool = 40,
        .beauty = 10,
        .cute = 30,
        .smart = 40,
        .tough = 30,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ARIANA] = {
        .species = SPECIES_KECLEON,
    #if FRENCH
        .nickname = _("CAMY"),
        .trainerName = _("ARIANE"),
    #elif ITALIAN
        .nickname = _("KECON"),
        .trainerName = _("TAMY"),
    #else //ENGLISH
        .nickname = _("KECON"),
        .trainerName = _("ARIANA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THIEF,
            MOVE_SCREECH,
            MOVE_ANCIENT_POWER,
            MOVE_BIND
        },
        .cool = 10,
        .beauty = 10,
        .cute = 40,
        .smart = 75,
        .tough = 35,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ASHTON] = {
        .species = SPECIES_GOLDEEN,
    #if FRENCH
        .nickname = _("RENA"),
        .trainerName = _("HUBERT"),
    #elif ITALIAN
        .nickname = _("GOLDEN"),
        .trainerName = _("ENZO"),
    #else //ENGLISH
        .nickname = _("GOLDEN"),
        .trainerName = _("ASHTON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK,
            MOVE_HORN_DRILL,
            MOVE_TAIL_WHIP
        },
        .cool = 70,
        .beauty = 30,
        .cute = 5,
        .smart = 30,
        .tough = 25,
        .sheen = 150,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SANDRA] = {
        .species = SPECIES_BARBOACH,
    #if FRENCH
        .nickname = _("BOBACHE"),
        .trainerName = _("SANDRA"),
    #elif ITALIAN
        .nickname = _("BOBOACH"),
        .trainerName = _("SANDRA"),
    #else //ENGLISH
        .nickname = _("BOBOACH"),
        .trainerName = _("SANDRA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MUD_SPORT,
            MOVE_WATER_SPORT,
            MOVE_EARTHQUAKE,
            MOVE_FUTURE_SIGHT
        },
        .cool = 45,
        .beauty = 45,
        .cute = 60,
        .smart = 25,
        .tough = 15,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CARSON] = {
        .species = SPECIES_SKARMORY,
    #if FRENCH
        .nickname = _("ARRY"),
        .trainerName = _("CARSON"),
    #elif ITALIAN
        .nickname = _("SKARMY"),
        .trainerName = _("PIERRE"),
    #else //ENGLISH
        .nickname = _("CORPY"),
        .trainerName = _("CARSON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1B,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_DOUBLE_TEAM,
            MOVE_AGILITY,
            MOVE_CUT
        },
        .cool = 40,
        .beauty = 30,
        .cute = 25,
        .smart = 60,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KATRINA] = {
        .species = SPECIES_LOTAD,
    #if FRENCH
        .nickname = _("PTIPIO"),
        .trainerName = _("GWEN"),
    #elif ITALIAN
        .nickname = _("TADO"),
        .trainerName = _("KATRINA"),
    #else //ENGLISH
        .nickname = _("TADO"),
        .trainerName = _("KATRINA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_1C,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ASTONISH,
            MOVE_GROWL,
            MOVE_RAIN_DANCE,
            MOVE_WATER_PULSE
        },
        .cool = 15,
        .beauty = 15,
        .cute = 30,
        .smart = 15,
        .tough = 75,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LUKE] = {
        .species = SPECIES_SLOWBRO,
    #if FRENCH
        .nickname = _("GADOSS"),
        .trainerName = _("LUKE"),
    #elif ITALIAN
        .nickname = _("BROWLO"),
        .trainerName = _("LUKE"),
    #else //ENGLISH
        .nickname = _("BROWLO"),
        .trainerName = _("LUKE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_FAT_MAN,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_YAWN,
            MOVE_DISABLE,
            MOVE_GROWL,
            MOVE_CONFUSION
        },
        .cool = 20,
        .beauty = 40,
        .cute = 40,
        .smart = 30,
        .tough = 20,
        .sheen = 100,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RAUL] = {
        .species = SPECIES_FARFETCHD,
    #if FRENCH
        .nickname = _("ARTICHO"),
        .trainerName = _("RAUL"),
    #elif ITALIAN
        .nickname = _("FARFI"),
        .trainerName = _("RINO"),
    #else //ENGLISH
        .nickname = _("FETCHIN"),
        .trainerName = _("RAUL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_5,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_FURY_CUTTER,
            MOVE_FLY,
            MOVE_RETURN
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 110,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JADA] = {
        .species = SPECIES_SEEL,
    #if FRENCH
        .nickname = _("RIAM"),
        .trainerName = _("JADE"),
    #elif ITALIAN
        .nickname = _("SEELEY"),
        .trainerName = _("JADA"),
    #else //ENGLISH
        .nickname = _("SEELEY"),
        .trainerName = _("JADA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ICE_BEAM,
            MOVE_SAFEGUARD,
            MOVE_GROWL
        },
        .cool = 10,
        .beauty = 30,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ZEEK] = {
        .species = SPECIES_DROWZEE,
    #if FRENCH
        .nickname = _("SUPORI"),
        .trainerName = _("ROBERTO"),
    #elif ITALIAN
        .nickname = _("DROWZIN"),
        .trainerName = _("JACK"),
    #else //ENGLISH
        .nickname = _("DROWZIN"),
        .trainerName = _("ZEEK"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DISABLE,
            MOVE_FUTURE_SIGHT,
            MOVE_HIDDEN_POWER,
            MOVE_RETURN
        },
        .cool = 10,
        .beauty = 40,
        .cute = 50,
        .smart = 30,
        .tough = 45,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DIEGO] = {
        .species = SPECIES_HITMONCHAN,
    #if FRENCH
        .nickname = _("PIFPAF"),
        .trainerName = _("DIEGO"),
    #elif ITALIAN
        .nickname = _("HITEMON"),
        .trainerName = _("GIOVI"),
    #else //ENGLISH
        .nickname = _("HITEMON"),
        .trainerName = _("DIEGO"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SKY_UPPERCUT,
            MOVE_DETECT,
            MOVE_REVENGE,
            MOVE_MEGA_PUNCH
        },
        .cool = 45,
        .beauty = 20,
        .cute = 10,
        .smart = 20,
        .tough = 45,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ALIYAH] = {
        .species = SPECIES_BLISSEY,
    #if FRENCH
        .nickname = _("PHORIE"),
        .trainerName = _("ALIYAH"),
    #elif ITALIAN
        .nickname = _("BLISS"),
        .trainerName = _("LELY"),
    #else //ENGLISH
        .nickname = _("BLISS"),
        .trainerName = _("ALIYAH"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TEALA,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SING,
            MOVE_SOFT_BOILED,
            MOVE_EGG_BOMB,
            MOVE_DOUBLE_EDGE
        },
        .cool = 20,
        .beauty = 35,
        .cute = 40,
        .smart = 20,
        .tough = 20,
        .sheen = 150,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_NATALIA] = {
        .species = SPECIES_ELEKID,
    #if FRENCH
        .nickname = _("KIDLEK"),
        .trainerName = _("NATALIA"),
    #elif ITALIAN
        .nickname = _("KIDLEK"),
        .trainerName = _("NATALIA"),
    #else //ENGLISH
        .nickname = _("KIDLEK"),
        .trainerName = _("NATALIA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_QUICK_ATTACK,
            MOVE_SCREECH,
            MOVE_ATTRACT
        },
        .cool = 40,
        .beauty = 10,
        .cute = 40,
        .smart = 25,
        .tough = 25,
        .sheen = 140,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DEVIN] = {
        .species = SPECIES_SNUBBULL,
    #if FRENCH
        .nickname = _("SNUBBINS"),
        .trainerName = _("MARCO"),
    #elif ITALIAN
        .nickname = _("SNUBBINS"),
        .trainerName = _("DEVIN"),
    #else //ENGLISH
        .nickname = _("SNUBBINS"),
        .trainerName = _("DEVIN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCARY_FACE,
            MOVE_TAUNT,
            MOVE_TAIL_WHIP,
            MOVE_BITE
        },
        .cool = 20,
        .beauty = 20,
        .cute = 20,
        .smart = 20,
        .tough = 20,
        .sheen = 130,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_TYLOR] = {
        .species = SPECIES_MISDREAVUS,
    #if FRENCH
        .nickname = _("FEUVI"),
        .trainerName = _("LILOU"),
    #elif ITALIAN
        .nickname = _("DREAVIS"),
        .trainerName = _("TATA"),
    #else //ENGLISH
        .nickname = _("DREAVIS"),
        .trainerName = _("TYLOR"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_SUPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_CONFUSE_RAY,
            MOVE_PAIN_SPLIT
        },
        .cool = 10,
        .beauty = 35,
        .cute = 10,
        .smart = 45,
        .tough = 20,
        .sheen = 120,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RONNIE] = {
        .species = SPECIES_LAIRON,
    #if FRENCH
        .nickname = _("GAN"),
        .trainerName = _("ETIENNE"),
    #elif ITALIAN
        .nickname = _("LAIRN"),
        .trainerName = _("RONNIE"),
    #else //ENGLISH
        .nickname = _("LAIRN"),
        .trainerName = _("RONNIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_HIKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_METAL_SOUND,
            MOVE_METAL_CLAW,
            MOVE_HARDEN,
            MOVE_TAKE_DOWN
        },
        .cool = 30,
        .beauty = 50,
        .cute = 35,
        .smart = 100,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CLAUDIA] = {
        .species = SPECIES_SHIFTRY,
    #if FRENCH
        .nickname = _("GALOU"),
        .trainerName = _("CLAUDIA"),
    #elif ITALIAN
        .nickname = _("SHIFTY"),
        .trainerName = _("DENISE"),
    #else //ENGLISH
        .nickname = _("SHIFTY"),
        .trainerName = _("CLAUDIA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWTH,
            MOVE_RAZOR_WIND,
            MOVE_EXPLOSION,
            MOVE_EXTRASENSORY
        },
        .cool = 75,
        .beauty = 75,
        .cute = 65,
        .smart = 35,
        .tough = 70,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ELIAS] = {
        .species = SPECIES_NINJASK,
    #if FRENCH
        .nickname = _("NINAS"),
        .trainerName = _("GONTRAN"),
    #elif ITALIAN
        .nickname = _("NINAS"),
        .trainerName = _("ELIAS"),
    #else //ENGLISH
        .nickname = _("NINAS"),
        .trainerName = _("ELIAS"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SCREECH,
            MOVE_FURY_SWIPES,
            MOVE_SAND_ATTACK,
            MOVE_BATON_PASS
        },
        .cool = 30,
        .beauty = 50,
        .cute = 95,
        .smart = 70,
        .tough = 70,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JADE] = {
        .species = SPECIES_SWELLOW,
    #if FRENCH
        .nickname = _("HELEDEL"),
        .trainerName = _("ZADIA"),
    #elif ITALIAN
        .nickname = _("WELOW"),
        .trainerName = _("GIADA"),
    #else //ENGLISH
        .nickname = _("WELOW"),
        .trainerName = _("JADE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_AERIAL_ACE,
            MOVE_WING_ATTACK,
            MOVE_FLY
        },
        .cool = 65,
        .beauty = 85,
        .cute = 35,
        .smart = 75,
        .tough = 40,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FRANCIS] = {
        .species = SPECIES_MIGHTYENA,
    #if FRENCH
        .nickname = _("YENA"),
        .trainerName = _("FRANCIS"),
    #elif ITALIAN
        .nickname = _("YENA"),
        .trainerName = _("FRANCIS"),
    #else //ENGLISH
        .nickname = _("YENA"),
        .trainerName = _("FRANCIS"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAUNT,
            MOVE_THIEF,
            MOVE_ODOR_SLEUTH,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 80,
        .cute = 35,
        .smart = 70,
        .tough = 70,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ALISHA] = {
        .species = SPECIES_BEAUTIFLY,
    #if FRENCH
        .nickname = _("CARMA"),
        .trainerName = _("YVANA"),
    #elif ITALIAN
        .nickname = _("TIFLY"),
        .trainerName = _("ALISHA"),
    #else //ENGLISH
        .nickname = _("TIFLY"),
        .trainerName = _("ALISHA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MORNING_SUN,
            MOVE_SILVER_WIND,
            MOVE_STUN_SPORE,
            MOVE_SECRET_POWER
        },
        .cool = 40,
        .beauty = 70,
        .cute = 25,
        .smart = 80,
        .tough = 100,
        .sheen = 250,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SAUL] = {
        .species = SPECIES_SEAKING,
    #if FRENCH
        .nickname = _("ROIPI"),
        .trainerName = _("ENZO"),
    #elif ITALIAN
        .nickname = _("KINGSEA"),
        .trainerName = _("SAUL"),
    #else //ENGLISH
        .nickname = _("KINGSEA"),
        .trainerName = _("SAUL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FLAIL,
            MOVE_SUPERSONIC,
            MOVE_HORN_ATTACK,
            MOVE_FURY_ATTACK
        },
        .cool = 80,
        .beauty = 60,
        .cute = 30,
        .smart = 70,
        .tough = 90,
        .sheen = 200,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FELICIA] = {
        .species = SPECIES_CASTFORM,
    #if FRENCH
        .nickname = _("PHEO"),
        .trainerName = _("NOLWENN"),
    #elif ITALIAN
        .nickname = _("CASTER"),
        .trainerName = _("LIZIA"),
    #else //ENGLISH
        .nickname = _("CASTER"),
        .trainerName = _("FELICIA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SUNNY_DAY,
            MOVE_WEATHER_BALL,
            MOVE_SANDSTORM,
            MOVE_RETURN
        },
        .cool = 70,
        .beauty = 80,
        .cute = 80,
        .smart = 50,
        .tough = 65,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_EMILIO] = {
        .species = SPECIES_MACHOKE,
    #if FRENCH
        .nickname = _("MACHIP"),
        .trainerName = _("ARNAUD"),
    #elif ITALIAN
        .nickname = _("CHOKEM"),
        .trainerName = _("PACO"),
    #else //ENGLISH
        .nickname = _("CHOKEM"),
        .trainerName = _("EMILIO"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SEISMIC_TOSS,
            MOVE_FOCUS_ENERGY,
            MOVE_KARATE_CHOP,
            MOVE_SCARY_FACE
        },
        .cool = 70,
        .beauty = 85,
        .cute = 25,
        .smart = 60,
        .tough = 50,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KARLA] = {
        .species = SPECIES_LOMBRE,
    #if FRENCH
        .nickname = _("LOMBE"),
        .trainerName = _("CARLA"),
    #elif ITALIAN
        .nickname = _("LOMBE"),
        .trainerName = _("CARLA"),
    #else //ENGLISH
        .nickname = _("LOMBE"),
        .trainerName = _("KARLA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_FLASH,
            MOVE_UPROAR,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 60,
        .cute = 90,
        .smart = 45,
        .tough = 70,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DARRYL] = {
        .species = SPECIES_SEVIPER,
    #if FRENCH
        .nickname = _("VIPES"),
        .trainerName = _("NORBERT"),
    #elif ITALIAN
        .nickname = _("VIPES"),
        .trainerName = _("RAUL"),
    #else //ENGLISH
        .nickname = _("VIPES"),
        .trainerName = _("DARRYL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_POISON_FANG,
            MOVE_GLARE,
            MOVE_WRAP,
            MOVE_SCREECH
        },
        .cool = 35,
        .beauty = 50,
        .cute = 90,
        .smart = 40,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SELENA] = {
        .species = SPECIES_WAILMER,
    #if FRENCH
        .nickname = _("MERAIL"),
        .trainerName = _("SELENE"),
    #elif ITALIAN
        .nickname = _("MERAIL"),
        .trainerName = _("SELENA"),
    #else //ENGLISH
        .nickname = _("MERAIL"),
        .trainerName = _("SELENA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_WATER_PULSE,
            MOVE_REST,
            MOVE_WATER_SPOUT,
            MOVE_SPLASH
        },
        .cool = 30,
        .beauty = 100,
        .cute = 100,
        .smart = 50,
        .tough = 30,
        .sheen = 250,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_NOEL] = {
        .species = SPECIES_MAGIKARP,
    #if FRENCH
        .nickname = _("KARPAG"),
        .trainerName = _("NOEL"),
    #elif ITALIAN
        .nickname = _("KARPAG"),
        .trainerName = _("NOEL"),
    #else //ENGLISH
        .nickname = _("KARPAG"),
        .trainerName = _("NOEL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TACKLE,
            MOVE_SPLASH,
            MOVE_FLAIL,
            MOVE_TACKLE
        },
        .cool = 30,
        .beauty = 30,
        .cute = 160,
        .smart = 50,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LACEY] = {
        .species = SPECIES_LUNATONE,
    #if FRENCH
        .nickname = _("KARTIE"),
        .trainerName = _("LAURIE"),
    #elif ITALIAN
        .nickname = _("LUNONE"),
        .trainerName = _("LACEY"),
    #else //ENGLISH
        .nickname = _("LUNONE"),
        .trainerName = _("LACEY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_FUTURE_SIGHT,
            MOVE_PSYCHIC,
            MOVE_CONFUSION
        },
        .cool = 50,
        .beauty = 70,
        .cute = 60,
        .smart = 70,
        .tough = 50,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CORBIN] = {
        .species = SPECIES_ABSOL,
    #if FRENCH
        .nickname = _("ABSO"),
        .trainerName = _("BRAHIM"),
    #elif ITALIAN
        .nickname = _("ABSO"),
        .trainerName = _("ELIO"),
    #else //ENGLISH
        .nickname = _("ABSO"),
        .trainerName = _("CORBIN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MANIAC,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_HAIL,
            MOVE_HYPER_BEAM,
            MOVE_SLASH
        },
        .cool = 95,
        .beauty = 80,
        .cute = 85,
        .smart = 35,
        .tough = 35,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_GRACIE] = {
        .species = SPECIES_EXEGGUTOR,
    #if FRENCH
        .nickname = _("KIKO"),
        .trainerName = _("GRACE"),
    #elif ITALIAN
        .nickname = _("EGGSOR"),
        .trainerName = _("GRACIE"),
    #else //ENGLISH
        .nickname = _("EGGSOR"),
        .trainerName = _("GRACIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STOMP,
            MOVE_HYPNOSIS,
            MOVE_EGG_BOMB,
            MOVE_SKILL_SWAP
        },
        .cool = 40,
        .beauty = 50,
        .cute = 60,
        .smart = 100,
        .tough = 80,
        .sheen = 200,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_COLTIN] = {
        .species = SPECIES_CUBONE,
    #if FRENCH
        .nickname = _("OCELO"),
        .trainerName = _("THIERRY"),
    #elif ITALIAN
        .nickname = _("CUBIN"),
        .trainerName = _("COLTIN"),
    #else //ENGLISH
        .nickname = _("CUBIN"),
        .trainerName = _("COLTIN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_4,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_BONE_CLUB,
            MOVE_BONEMERANG,
            MOVE_BONE_RUSH,
            MOVE_GROWL
        },
        .cool = 40,
        .beauty = 35,
        .cute = 85,
        .smart = 35,
        .tough = 100,
        .sheen = 210,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ELLIE] = {
        .species = SPECIES_HITMONLEE,
    #if FRENCH
        .nickname = _("BRICLEE"),
        .trainerName = _("ELLIE"),
    #elif ITALIAN
        .nickname = _("HITMON"),
        .trainerName = _("ELLIE"),
    #else //ENGLISH
        .nickname = _("HITMON"),
        .trainerName = _("ELLIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_F,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_REVERSAL,
            MOVE_REVENGE,
            MOVE_FOCUS_ENERGY,
            MOVE_MEGA_KICK
        },
        .cool = 85,
        .beauty = 30,
        .cute = 25,
        .smart = 50,
        .tough = 100,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MARCUS] = {
        .species = SPECIES_SQUIRTLE,
    #if FRENCH
        .nickname = _("PUPI"),
        .trainerName = _("FABIEN"),
    #elif ITALIAN
        .nickname = _("SURTLE"),
        .trainerName = _("MARZIO"),
    #else //ENGLISH
        .nickname = _("SURTLE"),
        .trainerName = _("MARCUS"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_TAIL_WHIP,
            MOVE_BUBBLE,
            MOVE_FOCUS_PUNCH,
            MOVE_WITHDRAW
        },
        .cool = 30,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 95,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KIARA] = {
        .species = SPECIES_KANGASKHAN,
    #if FRENCH
        .nickname = _("GIGO"),
        .trainerName = _("KIARA"),
    #elif ITALIAN
        .nickname = _("KHANKAN"),
        .trainerName = _("KIARA"),
    #else //ENGLISH
        .nickname = _("KHANKAN"),
        .trainerName = _("KIARA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_3,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEGA_PUNCH,
            MOVE_RAGE,
            MOVE_FOCUS_PUNCH,
            MOVE_TAIL_WHIP
        },
        .cool = 100,
        .beauty = 50,
        .cute = 30,
        .smart = 50,
        .tough = 100,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_BRYCE] = {
        .species = SPECIES_PINECO,
    #if FRENCH
        .nickname = _("POMDAPY"),
        .trainerName = _("BRYCE"),
    #elif ITALIAN
        .nickname = _("PINOC"),
        .trainerName = _("BICIO"),
    #else //ENGLISH
        .nickname = _("PINOC"),
        .trainerName = _("BRYCE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BUG_CATCHER,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_SPIKES,
            MOVE_LIGHT_SCREEN,
            MOVE_GIGA_DRAIN
        },
        .cool = 80,
        .beauty = 80,
        .cute = 80,
        .smart = 80,
        .tough = 80,
        .sheen = 250,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JAMIE] = {
        .species = SPECIES_DUNSPARCE,
    #if FRENCH
        .nickname = _("MIMISSE"),
        .trainerName = _("JANIE"),
    #elif ITALIAN
        .nickname = _("DILTOT"),
        .trainerName = _("JAMIE"),
    #else //ENGLISH
        .nickname = _("DILTOT"),
        .trainerName = _("JAMIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_5,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SPITE,
            MOVE_YAWN,
            MOVE_DEFENSE_CURL,
            MOVE_TAKE_DOWN
        },
        .cool = 40,
        .beauty = 35,
        .cute = 100,
        .smart = 40,
        .tough = 110,
        .sheen = 240,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JORGE] = {
        .species = SPECIES_HOUNDOOM,
    #if FRENCH
        .nickname = _("MOLOM"),
        .trainerName = _("JOSE"),
    #elif ITALIAN
        .nickname = _("DOOMOND"),
        .trainerName = _("JORGE"),
    #else //ENGLISH
        .nickname = _("DOOMOND"),
        .trainerName = _("JORGE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GENTLEMAN,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ROAR,
            MOVE_FLAMETHROWER,
            MOVE_FAINT_ATTACK,
            MOVE_SUNNY_DAY
        },
        .cool = 100,
        .beauty = 100,
        .cute = 30,
        .smart = 25,
        .tough = 80,
        .sheen = 230,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DEVON] = {
        .species = SPECIES_MILTANK,
    #if FRENCH
        .nickname = _("MOUMI"),
        .trainerName = _("DEVON"),
    #elif ITALIAN
        .nickname = _("MILKAN"),
        .trainerName = _("DANI"),
    #else //ENGLISH
        .nickname = _("MILKAN"),
        .trainerName = _("DEVON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_M,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_HYPER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_MILK_DRINK,
            MOVE_HEAL_BELL,
            MOVE_DEFENSE_CURL,
            MOVE_BLIZZARD
        },
        .cool = 50,
        .beauty = 110,
        .cute = 100,
        .smart = 35,
        .tough = 40,
        .sheen = 220,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JUSTINA] = {
        .species = SPECIES_GYARADOS,
    #if FRENCH
        .nickname = _("LELIV"),
        .trainerName = _("JUSTINE"),
    #elif ITALIAN
        .nickname = _("RADOS"),
        .trainerName = _("JUSTINA"),
    #else //ENGLISH
        .nickname = _("RADOS"),
        .trainerName = _("JUSTINA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_PICNICKER,
        .aiFlags = CONTEST_AI_SET_1D,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_BEAM,
            MOVE_HYDRO_PUMP,
            MOVE_RAIN_DANCE,
            MOVE_BITE
        },
        .cool = 160,
        .beauty = 200,
        .cute = 20,
        .smart = 40,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_RALPH] = {
        .species = SPECIES_LOUDRED,
    #if FRENCH
        .nickname = _("BOUMBY"),
        .trainerName = _("RAPH"),
    #elif ITALIAN
        .nickname = _("LOUDERD"),
        .trainerName = _("RALPH"),
    #else //ENGLISH
        .nickname = _("LOUDERD"),
        .trainerName = _("RALPH"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_EXPERT_M,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_HYPER_VOICE,
            MOVE_STOMP,
            MOVE_ROAR,
            MOVE_HOWL
        },
        .cool = 170,
        .beauty = 50,
        .cute = 55,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_ROSA] = {
        .species = SPECIES_SKITTY,
    #if FRENCH
        .nickname = _("SITTY"),
        .trainerName = _("LOANA"),
    #elif ITALIAN
        .nickname = _("SITTY"),
        .trainerName = _("ROSALIA"),
    #else //ENGLISH
        .nickname = _("SITTY"),
        .trainerName = _("ROSA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_1,
        .aiFlags = CONTEST_AI_SET_11,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_ATTRACT,
            MOVE_ASSIST,
            MOVE_FAINT_ATTACK,
            MOVE_TAIL_WHIP
        },
        .cool = 40,
        .beauty = 200,
        .cute = 150,
        .smart = 185,
        .tough = 60,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KEATON] = {
        .species = SPECIES_SLAKING,
    #if FRENCH
        .nickname = _("YAPAFEU"),
        .trainerName = _("KARIM"),
    #elif ITALIAN
        .nickname = _("SLING"),
        .trainerName = _("KEATON"),
    #else //ENGLISH
        .nickname = _("SLING"),
        .trainerName = _("KEATON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LITTLE_BOY,
        .aiFlags = CONTEST_AI_SET_12,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COVET,
            MOVE_COUNTER,
            MOVE_ENCORE,
            MOVE_SLACK_OFF
        },
        .cool = 85,
        .beauty = 85,
        .cute = 170,
        .smart = 110,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MAYRA] = {
        .species = SPECIES_ALTARIA,
    #if FRENCH
        .nickname = _("TARIA"),
        .trainerName = _("AURELIE"),
    #elif ITALIAN
        .nickname = _("TARIA"),
        .trainerName = _("MARA"),
    #else //ENGLISH
        .nickname = _("TARIA"),
        .trainerName = _("MAYRA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_POKEFAN_F,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_DRAGON_DANCE,
            MOVE_HYPER_BEAM,
            MOVE_PERISH_SONG,
            MOVE_SAFEGUARD
        },
        .cool = 170,
        .beauty = 150,
        .cute = 30,
        .smart = 30,
        .tough = 90,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LAMAR] = {
        .species = SPECIES_KIRLIA,
    #if FRENCH
        .nickname = _("KIPO"),
        .trainerName = _("NACER"),
    #elif ITALIAN
        .nickname = _("LIRKI"),
        .trainerName = _("FIORE"),
    #else //ENGLISH
        .nickname = _("LIRKI"),
        .trainerName = _("LAMAR"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_RICH_BOY,
        .aiFlags = CONTEST_AI_SET_1E,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SHOCK_WAVE,
            MOVE_SHADOW_BALL,
            MOVE_SKILL_SWAP,
            MOVE_RETURN
        },
        .cool = 230,
        .beauty = 60,
        .cute = 60,
        .smart = 230,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_AUBREY] = {
        .species = SPECIES_BELLOSSOM,
    #if FRENCH
        .nickname = _("LIFLI"),
        .trainerName = _("MAYRA"),
    #elif ITALIAN
        .nickname = _("BLOSSOM"),
        .trainerName = _("ROBERTA"),
    #else //ENGLISH
        .nickname = _("BLOSSOM"),
        .trainerName = _("AUBREY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_4,
        .aiFlags = CONTEST_AI_SET_1F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PETAL_DANCE,
            MOVE_SWEET_SCENT,
            MOVE_STUN_SPORE,
            MOVE_FLASH
        },
        .cool = 35,
        .beauty = 200,
        .cute = 150,
        .smart = 130,
        .tough = 40,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_NIGEL] = {
        .species = SPECIES_SABLEYE,
    #if FRENCH
        .nickname = _("TENEF"),
        .trainerName = _("WILFRID"),
    #elif ITALIAN
        .nickname = _("EYESAB"),
        .trainerName = _("NIGEL"),
    #else //ENGLISH
        .nickname = _("EYESAB"),
        .trainerName = _("NIGEL"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_CAMPER,
        .aiFlags = CONTEST_AI_SET_16,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_MEAN_LOOK,
            MOVE_FAINT_ATTACK,
            MOVE_KNOCK_OFF,
            MOVE_CONFUSE_RAY
        },
        .cool = 25,
        .beauty = 35,
        .cute = 230,
        .smart = 150,
        .tough = 160,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CAMILLE] = {
        .species = SPECIES_NATU,
    #if FRENCH
        .nickname = _("UTAN"),
        .trainerName = _("CAMILLE"),
    #elif ITALIAN
        .nickname = _("UTAN"),
        .trainerName = _("CAMILLA"),
    #else //ENGLISH
        .nickname = _("UTAN"),
        .trainerName = _("CAMILLE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_LASS,
        .aiFlags = CONTEST_AI_SET_20,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_NIGHT_SHADE,
            MOVE_FUTURE_SIGHT,
            MOVE_CONFUSE_RAY,
            MOVE_PSYCHIC
        },
        .cool = 35,
        .beauty = 35,
        .cute = 150,
        .smart = 130,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_DEON] = {
        .species = SPECIES_SHARPEDO,
    #if FRENCH
        .nickname = _("PEDOS"),
        .trainerName = _("LEON"),
    #elif ITALIAN
        .nickname = _("PEDOS"),
        .trainerName = _("LEONIO"),
    #else //ENGLISH
        .nickname = _("PEDOS"),
        .trainerName = _("DEON"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SCHOOL_KID_M,
        .aiFlags = CONTEST_AI_SET_A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_AGILITY,
            MOVE_SWAGGER,
            MOVE_TAUNT,
            MOVE_TAKE_DOWN
        },
        .cool = 140,
        .beauty = 70,
        .cute = 140,
        .smart = 75,
        .tough = 100,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JANELLE] = {
        .species = SPECIES_LUVDISC,
    #if FRENCH
        .nickname = _("LOVY"),
        .trainerName = _("EMMA"),
    #elif ITALIAN
        .nickname = _("LUVIS"),
        .trainerName = _("JANETTE"),
    #else //ENGLISH
        .nickname = _("LUVIS"),
        .trainerName = _("JANELLE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_GIRL_2,
        .aiFlags = CONTEST_AI_SET_18,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_TAKE_DOWN,
            MOVE_CHARM
        },
        .cool = 50,
        .beauty = 100,
        .cute = 220,
        .smart = 40,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_HEATH] = {
        .species = SPECIES_HERACROSS,
    #if FRENCH
        .nickname = _("HEROSS"),
        .trainerName = _("NATHAN"),
    #elif ITALIAN
        .nickname = _("HEROSS"),
        .trainerName = _("HEATH"),
    #else //ENGLISH
        .nickname = _("HEROSS"),
        .trainerName = _("HEATH"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_MAN_3,
        .aiFlags = CONTEST_AI_SET_19,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_STRENGTH,
            MOVE_ENDURE,
            MOVE_REVERSAL,
            MOVE_ROCK_TOMB
        },
        .cool = 170,
        .beauty = 70,
        .cute = 110,
        .smart = 240,
        .tough = 140,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SASHA] = {
        .species = SPECIES_ELECTRODE,
    #if FRENCH
        .nickname = _("RODLECT"),
        .trainerName = _("FABOU"),
    #elif ITALIAN
        .nickname = _("RODLECT"),
        .trainerName = _("SASHA"),
    #else //ENGLISH
        .nickname = _("RODLECT"),
        .trainerName = _("SASHA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_1A,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_EXPLOSION,
            MOVE_LIGHT_SCREEN,
            MOVE_SWIFT,
            MOVE_FLASH
        },
        .cool = 200,
        .beauty = 200,
        .cute = 30,
        .smart = 35,
        .tough = 50,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_FRANKIE] = {
        .species = SPECIES_PICHU,
    #if FRENCH
        .nickname = _("CHUPY"),
        .trainerName = _("FRANKY"),
    #elif ITALIAN
        .nickname = _("CHUPY"),
        .trainerName = _("VICTOR"),
    #else //ENGLISH
        .nickname = _("CHUPY"),
        .trainerName = _("FRANKIE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_YOUNGSTER,
        .aiFlags = CONTEST_AI_SET_21,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWEET_KISS,
            MOVE_ATTRACT,
            MOVE_REST,
            MOVE_TAIL_WHIP
        },
        .cool = 25,
        .beauty = 150,
        .cute = 180,
        .smart = 115,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_HELEN] = {
        .species = SPECIES_WOBBUFFET,
    #if FRENCH
        .nickname = _("TOCTOC"),
        .trainerName = _("ELSA"),
    #elif ITALIAN
        .nickname = _("WOBET"),
        .trainerName = _("HELEN"),
    #else //ENGLISH
        .nickname = _("WOBET"),
        .trainerName = _("HELEN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_1,
        .aiFlags = CONTEST_AI_SET_F,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_COUNTER,
            MOVE_MIRROR_COAT,
            MOVE_SAFEGUARD,
            MOVE_DESTINY_BOND
        },
        .cool = 60,
        .beauty = 230,
        .cute = 50,
        .smart = 220,
        .tough = 210,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CAMILE] = {
        .species = SPECIES_GENGAR,
    #if FRENCH
        .nickname = _("PLASMI"),
        .trainerName = _("CAMILLE"),
    #elif ITALIAN
        .nickname = _("GAREN"),
        .trainerName = _("CAMILLE"),
    #else //ENGLISH
        .nickname = _("GAREN"),
        .trainerName = _("CAMILE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_HEX_MANIAC,
        .aiFlags = CONTEST_AI_SET_1,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_DESTINY_BOND,
            MOVE_CONFUSE_RAY,
            MOVE_LICK,
            MOVE_SLUDGE_BOMB
        },
        .cool = 200,
        .beauty = 100,
        .cute = 50,
        .smart = 80,
        .tough = 180,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_MARTIN] = {
        .species = SPECIES_PORYGON,
    #if FRENCH
        .nickname = _("GONPY"),
        .trainerName = _("MARTIN"),
    #elif ITALIAN
        .nickname = _("GONPOR"),
        .trainerName = _("MARTIN"),
    #else //ENGLISH
        .nickname = _("GONPOR"),
        .trainerName = _("MARTIN"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SCIENTIST_1,
        .aiFlags = CONTEST_AI_SET_2,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_CONVERSION_2,
            MOVE_CONVERSION,
            MOVE_RETURN,
            MOVE_RECYCLE
        },
        .cool = 130,
        .beauty = 130,
        .cute = 130,
        .smart = 130,
        .tough = 130,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_SERGIO] = {
        .species = SPECIES_DRAGONITE,
    #if FRENCH
        .nickname = _("DRACKY"),
        .trainerName = _("DJAMEL"),
    #elif ITALIAN
        .nickname = _("DRITE"),
        .trainerName = _("SERENO"),
    #else //ENGLISH
        .nickname = _("DRITE"),
        .trainerName = _("SERGIO"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BOY_1,
        .aiFlags = CONTEST_AI_SET_3,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_OUTRAGE,
            MOVE_SLAM,
            MOVE_TWISTER,
            MOVE_EARTHQUAKE
        },
        .cool = 150,
        .beauty = 140,
        .cute = 50,
        .smart = 120,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_KAILEY] = {
        .species = SPECIES_MEOWTH,
    #if FRENCH
        .nickname = _("MISSI"),
        .trainerName = _("KALYA"),
    #elif ITALIAN
        .nickname = _("MEOWY"),
        .trainerName = _("KAILEY"),
    #else //ENGLISH
        .nickname = _("MEOWY"),
        .trainerName = _("KAILEY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_TWIN,
        .aiFlags = CONTEST_AI_SET_4,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_TAUNT,
            MOVE_PAY_DAY,
            MOVE_BITE
        },
        .cool = 125,
        .beauty = 110,
        .cute = 180,
        .smart = 170,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_PERLA] = {
        .species = SPECIES_JYNX,
    #if FRENCH
        .nickname = _("LIPPIX"),
        .trainerName = _("PERLINE"),
    #elif ITALIAN
        .nickname = _("NYX"),
        .trainerName = _("PEPA"),
    #else //ENGLISH
        .nickname = _("NYX"),
        .trainerName = _("PERLA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BEAUTY,
        .aiFlags = CONTEST_AI_SET_5,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = TRUE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_PERISH_SONG,
            MOVE_MEAN_LOOK,
            MOVE_LOVELY_KISS,
            MOVE_FAKE_TEARS
        },
        .cool = 100,
        .beauty = 150,
        .cute = 100,
        .smart = 150,
        .tough = 120,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_CLARA] = {
        .species = SPECIES_TOGEPI,
    #if FRENCH
        .nickname = _("PIGETO"),
        .trainerName = _("CLARA"),
    #elif ITALIAN
        .nickname = _("GEPITO"),
        .trainerName = _("CLARA"),
    #else //ENGLISH
        .nickname = _("GEPITO"),
        .trainerName = _("CLARA"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_WOMAN_2,
        .aiFlags = CONTEST_AI_SET_6,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_GROWL,
            MOVE_YAWN,
            MOVE_ENCORE,
            MOVE_FOLLOW_ME
        },
        .cool = 80,
        .beauty = 120,
        .cute = 200,
        .smart = 120,
        .tough = 80,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_JAKOB] = {
        .species = SPECIES_ESPEON,
    #if FRENCH
        .nickname = _("TALIX"),
        .trainerName = _("JACOB"),
    #elif ITALIAN
        .nickname = _("SPEON"),
        .trainerName = _("JAKOB"),
    #else //ENGLISH
        .nickname = _("SPEON"),
        .trainerName = _("JAKOB"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_PSYCHIC_M,
        .aiFlags = CONTEST_AI_SET_7,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = TRUE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = FALSE,
        .moves =
        {
            MOVE_SWIFT,
            MOVE_QUICK_ATTACK,
            MOVE_MORNING_SUN,
            MOVE_TAIL_WHIP
        },
        .cool = 180,
        .beauty = 150,
        .cute = 100,
        .smart = 80,
        .tough = 150,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_TREY] = {
        .species = SPECIES_SLOWKING,
    #if FRENCH
        .nickname = _("CARPY"),
        .trainerName = _("KAMEL"),
    #elif ITALIAN
        .nickname = _("SLOWGO"),
        .trainerName = _("TREY"),
    #else //ENGLISH
        .nickname = _("SLOWGO"),
        .trainerName = _("TREY"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_SAILOR,
        .aiFlags = CONTEST_AI_SET_8,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = FALSE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = TRUE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_FACADE,
            MOVE_CURSE,
            MOVE_YAWN,
            MOVE_FOCUS_PUNCH
        },
        .cool = 100,
        .beauty = 80,
        .cute = 200,
        .smart = 110,
        .tough = 170,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    },
    [CONTEST_OPPONENT_LANE] = {
        .species = SPECIES_URSARING,
    #if FRENCH
        .nickname = _("URSING"),
        .trainerName = _("VICTOR"),
    #elif ITALIAN
        .nickname = _("URSING"),
        .trainerName = _("LENO"),
    #else //ENGLISH
        .nickname = _("URSING"),
        .trainerName = _("LANE"),
    #endif
        .trainerGfxId = OBJ_EVENT_GFX_BLACK_BELT,
        .aiFlags = CONTEST_AI_SET_9,
        .whichRank = CONTEST_RANK_MASTER,
        .aiPool_Cool = TRUE,
        .aiPool_Beauty = FALSE,
        .aiPool_Cute = FALSE,
        .aiPool_Smart = FALSE,
        .aiPool_Tough = TRUE,
        .moves =
        {
            MOVE_THRASH,
            MOVE_AERIAL_ACE,
            MOVE_FAKE_TEARS,
            MOVE_LEER
        },
        .cool = 180,
        .beauty = 140,
        .cute = 30,
        .smart = 80,
        .tough = 190,
        .sheen = 255,
        .personality = 0,
        .otId = 0xFFFF
    }
};


const u8 gPostgameContestOpponentFilter[] =
{
    [CONTEST_OPPONENT_JIMMY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EDITH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EVAN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KELSEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MADISON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RAYMOND] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_GRANT] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_PAIGE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ALEC] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SYDNEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MORRIS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MARIAH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RUSSELL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MELANIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CHANCE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AGATHA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_BEAU] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KAY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CALE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CAITLIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_COLBY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KYLIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_LIAM] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MILO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KARINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_BOBBY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CLAIRE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_WILLIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CASSIDY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MORGAN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SUMMER] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MILES] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AUDREY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AVERY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ARIANA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ASHTON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SANDRA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CARSON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KATRINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LUKE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_RAUL] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JADA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ZEEK] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DIEGO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ALIYAH] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_NATALIA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DEVIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_TYLOR] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_RONNIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CLAUDIA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ELIAS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_JADE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FRANCIS] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ALISHA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SAUL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FELICIA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_EMILIO] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KARLA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_DARRYL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SELENA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_NOEL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LACEY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CORBIN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_GRACIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_COLTIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_ELLIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MARCUS] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KIARA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_BRYCE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JAMIE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JORGE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_DEVON] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JUSTINA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_RALPH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_ROSA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_KEATON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_MAYRA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_LAMAR] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_AUBREY] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_NIGEL] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CAMILLE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_DEON] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_JANELLE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_HEATH] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_SASHA] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_FRANKIE] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_HELEN] = CONTEST_FILTER_NONE,
    [CONTEST_OPPONENT_CAMILE] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_MARTIN] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_SERGIO] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_KAILEY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_PERLA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_CLARA] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_JAKOB] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_TREY] = CONTEST_FILTER_ONLY_POSTGAME,
    [CONTEST_OPPONENT_LANE] = CONTEST_FILTER_ONLY_POSTGAME
};
