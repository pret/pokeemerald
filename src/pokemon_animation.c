#include "global.h"
#include "pokemon.h"
#include "sprite.h"
#include "pokemon_animation.h"
#include "trig.h"
#include "task.h"
#include "blend_palette.h"

struct UnkAnimStruct
{
    u16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    s16 field_8;
};

extern u16 gBattlePartyID[];
extern bool32 gUnknown_03001274;
extern struct UnkAnimStruct gUnknown_03001240[];
extern u8 gUnknown_03001270;

// this file's functions
void pokemonanimfunc_00(struct Sprite *sprite);
void pokemonanimfunc_01(struct Sprite *sprite);
void pokemonanimfunc_02(struct Sprite *sprite);
void pokemonanimfunc_03(struct Sprite *sprite);
void pokemonanimfunc_04(struct Sprite *sprite);
void pokemonanimfunc_05(struct Sprite *sprite);
void pokemonanimfunc_06(struct Sprite *sprite);
void pokemonanimfunc_07(struct Sprite *sprite);
void pokemonanimfunc_08(struct Sprite *sprite);
void pokemonanimfunc_09(struct Sprite *sprite);
void pokemonanimfunc_0A(struct Sprite *sprite);
void pokemonanimfunc_0B(struct Sprite *sprite);
void pokemonanimfunc_0C(struct Sprite *sprite);
void pokemonanimfunc_0D(struct Sprite *sprite);
void pokemonanimfunc_0E(struct Sprite *sprite);
void pokemonanimfunc_0F(struct Sprite *sprite);
void pokemonanimfunc_10(struct Sprite *sprite);
void pokemonanimfunc_11(struct Sprite *sprite);
void pokemonanimfunc_12(struct Sprite *sprite);
void pokemonanimfunc_13(struct Sprite *sprite);
void pokemonanimfunc_14(struct Sprite *sprite);
void pokemonanimfunc_15(struct Sprite *sprite);
void pokemonanimfunc_16(struct Sprite *sprite);
void pokemonanimfunc_17(struct Sprite *sprite);
void pokemonanimfunc_18(struct Sprite *sprite);
void pokemonanimfunc_19(struct Sprite *sprite);
void pokemonanimfunc_1A(struct Sprite *sprite);
void pokemonanimfunc_1B(struct Sprite *sprite);
void pokemonanimfunc_1C(struct Sprite *sprite);
void pokemonanimfunc_1D(struct Sprite *sprite);
void pokemonanimfunc_1E(struct Sprite *sprite);
void pokemonanimfunc_1F(struct Sprite *sprite);
void pokemonanimfunc_20(struct Sprite *sprite);
void pokemonanimfunc_21(struct Sprite *sprite);
void pokemonanimfunc_22(struct Sprite *sprite);
void pokemonanimfunc_23(struct Sprite *sprite);
void pokemonanimfunc_24(struct Sprite *sprite);
void pokemonanimfunc_25(struct Sprite *sprite);
void pokemonanimfunc_26(struct Sprite *sprite);
void pokemonanimfunc_27(struct Sprite *sprite);
void pokemonanimfunc_28(struct Sprite *sprite);
void pokemonanimfunc_29(struct Sprite *sprite);
void pokemonanimfunc_2A(struct Sprite *sprite);
void pokemonanimfunc_2B(struct Sprite *sprite);
void pokemonanimfunc_2C(struct Sprite *sprite);
void pokemonanimfunc_2D(struct Sprite *sprite);
void pokemonanimfunc_2E(struct Sprite *sprite);
void pokemonanimfunc_2F(struct Sprite *sprite);
void pokemonanimfunc_30(struct Sprite *sprite);
void pokemonanimfunc_31(struct Sprite *sprite);
void pokemonanimfunc_32(struct Sprite *sprite);
void pokemonanimfunc_33(struct Sprite *sprite);
void pokemonanimfunc_34(struct Sprite *sprite);
void pokemonanimfunc_35(struct Sprite *sprite);
void pokemonanimfunc_36(struct Sprite *sprite);
void pokemonanimfunc_37(struct Sprite *sprite);
void pokemonanimfunc_38(struct Sprite *sprite);
void pokemonanimfunc_39(struct Sprite *sprite);
void pokemonanimfunc_3A(struct Sprite *sprite);
void pokemonanimfunc_3B(struct Sprite *sprite);
void pokemonanimfunc_3C(struct Sprite *sprite);
void pokemonanimfunc_3D(struct Sprite *sprite);
void pokemonanimfunc_3E(struct Sprite *sprite);
void pokemonanimfunc_3F(struct Sprite *sprite);
void pokemonanimfunc_40(struct Sprite *sprite);
void pokemonanimfunc_41(struct Sprite *sprite);
void pokemonanimfunc_42(struct Sprite *sprite);
void pokemonanimfunc_43(struct Sprite *sprite);
void pokemonanimfunc_44(struct Sprite *sprite);
void pokemonanimfunc_45(struct Sprite *sprite);
void pokemonanimfunc_46(struct Sprite *sprite);
void pokemonanimfunc_47(struct Sprite *sprite);
void pokemonanimfunc_48(struct Sprite *sprite);
void pokemonanimfunc_49(struct Sprite *sprite);
void pokemonanimfunc_4A(struct Sprite *sprite);
void pokemonanimfunc_4B(struct Sprite *sprite);
void pokemonanimfunc_4C(struct Sprite *sprite);
void pokemonanimfunc_4D(struct Sprite *sprite);
void pokemonanimfunc_4E(struct Sprite *sprite);
void pokemonanimfunc_4F(struct Sprite *sprite);
void pokemonanimfunc_50(struct Sprite *sprite);
void pokemonanimfunc_51(struct Sprite *sprite);
void pokemonanimfunc_52(struct Sprite *sprite);
void pokemonanimfunc_53(struct Sprite *sprite);
void pokemonanimfunc_54(struct Sprite *sprite);
void pokemonanimfunc_55(struct Sprite *sprite);
void pokemonanimfunc_56(struct Sprite *sprite);
void pokemonanimfunc_57(struct Sprite *sprite);
void pokemonanimfunc_58(struct Sprite *sprite);
void pokemonanimfunc_59(struct Sprite *sprite);
void pokemonanimfunc_5A(struct Sprite *sprite);
void pokemonanimfunc_5B(struct Sprite *sprite);
void pokemonanimfunc_5C(struct Sprite *sprite);
void pokemonanimfunc_5D(struct Sprite *sprite);
void pokemonanimfunc_5E(struct Sprite *sprite);
void pokemonanimfunc_5F(struct Sprite *sprite);
void pokemonanimfunc_60(struct Sprite *sprite);
void pokemonanimfunc_61(struct Sprite *sprite);
void pokemonanimfunc_62(struct Sprite *sprite);
void pokemonanimfunc_63(struct Sprite *sprite);
void pokemonanimfunc_64(struct Sprite *sprite);
void pokemonanimfunc_65(struct Sprite *sprite);
void pokemonanimfunc_66(struct Sprite *sprite);
void pokemonanimfunc_67(struct Sprite *sprite);
void pokemonanimfunc_68(struct Sprite *sprite);
void pokemonanimfunc_69(struct Sprite *sprite);
void pokemonanimfunc_6A(struct Sprite *sprite);
void pokemonanimfunc_6B(struct Sprite *sprite);
void pokemonanimfunc_6C(struct Sprite *sprite);
void pokemonanimfunc_6D(struct Sprite *sprite);
void pokemonanimfunc_6E(struct Sprite *sprite);
void pokemonanimfunc_6F(struct Sprite *sprite);
void pokemonanimfunc_70(struct Sprite *sprite);
void pokemonanimfunc_71(struct Sprite *sprite);
void pokemonanimfunc_72(struct Sprite *sprite);
void pokemonanimfunc_73(struct Sprite *sprite);
void pokemonanimfunc_74(struct Sprite *sprite);
void pokemonanimfunc_75(struct Sprite *sprite);
void pokemonanimfunc_76(struct Sprite *sprite);
void pokemonanimfunc_77(struct Sprite *sprite);
void pokemonanimfunc_78(struct Sprite *sprite);
void pokemonanimfunc_79(struct Sprite *sprite);
void pokemonanimfunc_7A(struct Sprite *sprite);
void pokemonanimfunc_7B(struct Sprite *sprite);
void pokemonanimfunc_7C(struct Sprite *sprite);
void pokemonanimfunc_7D(struct Sprite *sprite);
void pokemonanimfunc_7E(struct Sprite *sprite);
void pokemonanimfunc_7F(struct Sprite *sprite);
void pokemonanimfunc_80(struct Sprite *sprite);
void pokemonanimfunc_81(struct Sprite *sprite);
void pokemonanimfunc_82(struct Sprite *sprite);
void pokemonanimfunc_83(struct Sprite *sprite);
void pokemonanimfunc_84(struct Sprite *sprite);
void pokemonanimfunc_85(struct Sprite *sprite);
void pokemonanimfunc_86(struct Sprite *sprite);
void pokemonanimfunc_87(struct Sprite *sprite);
void pokemonanimfunc_88(struct Sprite *sprite);
void pokemonanimfunc_89(struct Sprite *sprite);
void pokemonanimfunc_8A(struct Sprite *sprite);
void pokemonanimfunc_8B(struct Sprite *sprite);
void pokemonanimfunc_8C(struct Sprite *sprite);
void pokemonanimfunc_8D(struct Sprite *sprite);
void pokemonanimfunc_8E(struct Sprite *sprite);
void pokemonanimfunc_8F(struct Sprite *sprite);
void pokemonanimfunc_90(struct Sprite *sprite);
void pokemonanimfunc_91(struct Sprite *sprite);
void pokemonanimfunc_92(struct Sprite *sprite);
void pokemonanimfunc_93(struct Sprite *sprite);
void pokemonanimfunc_94(struct Sprite *sprite);
void pokemonanimfunc_95(struct Sprite *sprite);
void pokemonanimfunc_96(struct Sprite *sprite);

void SpriteCB_SetDummyOnAnimEnd(struct Sprite *sprite);

// const rom data
static const u8 sSpeciesToBackAnimId[] =
{
    0x00, // SPECIES_NONE
    0x13, // SPECIES_BULBASAUR
    0x02, // SPECIES_IVYSAUR
    0x08, // SPECIES_VENUSAUR
    0x12, // SPECIES_CHARMANDER
    0x15, // SPECIES_CHARMELEON
    0x17, // SPECIES_CHARIZARD
    0x12, // SPECIES_SQUIRTLE
    0x12, // SPECIES_WARTORTLE
    0x19, // SPECIES_BLASTOISE
    0x02, // SPECIES_CATERPIE
    0x13, // SPECIES_METAPOD
    0x11, // SPECIES_BUTTERFREE
    0x02, // SPECIES_WEEDLE
    0x13, // SPECIES_KAKUNA
    0x01, // SPECIES_BEEDRILL
    0x0f, // SPECIES_PIDGEY
    0x15, // SPECIES_PIDGEOTTO
    0x0f, // SPECIES_PIDGEOT
    0x0a, // SPECIES_RATTATA
    0x0a, // SPECIES_RATICATE
    0x0f, // SPECIES_SPEAROW
    0x15, // SPECIES_FEAROW
    0x0f, // SPECIES_EKANS
    0x09, // SPECIES_ARBOK
    0x16, // SPECIES_PIKACHU
    0x16, // SPECIES_RAICHU
    0x12, // SPECIES_SANDSHREW
    0x10, // SPECIES_SANDSLASH
    0x12, // SPECIES_NIDORAN_F
    0x15, // SPECIES_NIDORINA
    0x09, // SPECIES_NIDOQUEEN
    0x12, // SPECIES_NIDORAN_M
    0x15, // SPECIES_NIDORINO
    0x09, // SPECIES_NIDOKING
    0x13, // SPECIES_CLEFAIRY
    0x13, // SPECIES_CLEFABLE
    0x10, // SPECIES_VULPIX
    0x01, // SPECIES_NINETALES
    0x13, // SPECIES_JIGGLYPUFF
    0x06, // SPECIES_WIGGLYTUFF
    0x11, // SPECIES_ZUBAT
    0x09, // SPECIES_GOLBAT
    0x02, // SPECIES_ODDISH
    0x02, // SPECIES_GLOOM
    0x14, // SPECIES_VILEPLUME
    0x02, // SPECIES_PARAS
    0x08, // SPECIES_PARASECT
    0x0a, // SPECIES_VENONAT
    0x11, // SPECIES_VENOMOTH
    0x09, // SPECIES_DIGLETT
    0x09, // SPECIES_DUGTRIO
    0x10, // SPECIES_MEOWTH
    0x0f, // SPECIES_PERSIAN
    0x02, // SPECIES_PSYDUCK
    0x14, // SPECIES_GOLDUCK
    0x10, // SPECIES_MANKEY
    0x10, // SPECIES_PRIMEAPE
    0x15, // SPECIES_GROWLITHE
    0x15, // SPECIES_ARCANINE
    0x12, // SPECIES_POLIWAG
    0x09, // SPECIES_POLIWHIRL
    0x0e, // SPECIES_POLIWRATH
    0x14, // SPECIES_ABRA
    0x14, // SPECIES_KADABRA
    0x0d, // SPECIES_ALAKAZAM
    0x15, // SPECIES_MACHOP
    0x09, // SPECIES_MACHOKE
    0x09, // SPECIES_MACHAMP
    0x0b, // SPECIES_BELLSPROUT
    0x0b, // SPECIES_WEEPINBELL
    0x0b, // SPECIES_VICTREEBEL
    0x02, // SPECIES_TENTACOOL
    0x02, // SPECIES_TENTACRUEL
    0x0e, // SPECIES_GEODUDE
    0x08, // SPECIES_GRAVELER
    0x08, // SPECIES_GOLEM
    0x17, // SPECIES_PONYTA
    0x15, // SPECIES_RAPIDASH
    0x02, // SPECIES_SLOWPOKE
    0x13, // SPECIES_SLOWBRO
    0x0f, // SPECIES_MAGNEMITE
    0x0f, // SPECIES_MAGNETON
    0x02, // SPECIES_FARFETCHD
    0x0f, // SPECIES_DODUO
    0x15, // SPECIES_DODRIO
    0x13, // SPECIES_SEEL
    0x02, // SPECIES_DEWGONG
    0x0b, // SPECIES_GRIMER
    0x0c, // SPECIES_MUK
    0x13, // SPECIES_SHELLDER
    0x0f, // SPECIES_CLOYSTER
    0x01, // SPECIES_GASTLY
    0x01, // SPECIES_HAUNTER
    0x14, // SPECIES_GENGAR
    0x09, // SPECIES_ONIX
    0x13, // SPECIES_DROWZEE
    0x14, // SPECIES_HYPNO
    0x0a, // SPECIES_KRABBY
    0x09, // SPECIES_KINGLER
    0x15, // SPECIES_VOLTORB
    0x15, // SPECIES_ELECTRODE
    0x02, // SPECIES_EXEGGCUTE
    0x10, // SPECIES_EXEGGUTOR
    0x15, // SPECIES_CUBONE
    0x10, // SPECIES_MAROWAK
    0x02, // SPECIES_HITMONLEE
    0x0f, // SPECIES_HITMONCHAN
    0x02, // SPECIES_LICKITUNG
    0x06, // SPECIES_KOFFING
    0x06, // SPECIES_WEEZING
    0x0e, // SPECIES_RHYHORN
    0x0e, // SPECIES_RHYDON
    0x12, // SPECIES_CHANSEY
    0x0b, // SPECIES_TANGELA
    0x12, // SPECIES_KANGASKHAN
    0x13, // SPECIES_HORSEA
    0x11, // SPECIES_SEADRA
    0x11, // SPECIES_GOLDEEN
    0x11, // SPECIES_SEAKING
    0x13, // SPECIES_STARYU
    0x19, // SPECIES_STARMIE
    0x14, // SPECIES_MR_MIME
    0x0f, // SPECIES_SCYTHER
    0x13, // SPECIES_JYNX
    0x16, // SPECIES_ELECTABUZZ
    0x17, // SPECIES_MAGMAR
    0x0e, // SPECIES_PINSIR
    0x0e, // SPECIES_TAUROS
    0x10, // SPECIES_MAGIKARP
    0x09, // SPECIES_GYARADOS
    0x19, // SPECIES_LAPRAS
    0x05, // SPECIES_DITTO
    0x12, // SPECIES_EEVEE
    0x19, // SPECIES_VAPOREON
    0x16, // SPECIES_JOLTEON
    0x17, // SPECIES_FLAREON
    0x01, // SPECIES_PORYGON
    0x13, // SPECIES_OMANYTE
    0x13, // SPECIES_OMASTAR
    0x13, // SPECIES_KABUTO
    0x15, // SPECIES_KABUTOPS
    0x15, // SPECIES_AERODACTYL
    0x13, // SPECIES_SNORLAX
    0x19, // SPECIES_ARTICUNO
    0x16, // SPECIES_ZAPDOS
    0x17, // SPECIES_MOLTRES
    0x02, // SPECIES_DRATINI
    0x0f, // SPECIES_DRAGONAIR
    0x09, // SPECIES_DRAGONITE
    0x0d, // SPECIES_MEWTWO
    0x12, // SPECIES_MEW
    0x12, // SPECIES_CHIKORITA
    0x02, // SPECIES_BAYLEEF
    0x09, // SPECIES_MEGANIUM
    0x12, // SPECIES_CYNDAQUIL
    0x15, // SPECIES_QUILAVA
    0x17, // SPECIES_TYPHLOSION
    0x15, // SPECIES_TOTODILE
    0x15, // SPECIES_CROCONAW
    0x09, // SPECIES_FERALIGATR
    0x12, // SPECIES_SENTRET
    0x10, // SPECIES_FURRET
    0x11, // SPECIES_HOOTHOOT
    0x0f, // SPECIES_NOCTOWL
    0x0a, // SPECIES_LEDYBA
    0x11, // SPECIES_LEDIAN
    0x0a, // SPECIES_SPINARAK
    0x02, // SPECIES_ARIADOS
    0x0f, // SPECIES_CROBAT
    0x0b, // SPECIES_CHINCHOU
    0x16, // SPECIES_LANTURN
    0x12, // SPECIES_PICHU
    0x13, // SPECIES_CLEFFA
    0x13, // SPECIES_IGGLYBUFF
    0x13, // SPECIES_TOGEPI
    0x11, // SPECIES_TOGETIC
    0x12, // SPECIES_NATU
    0x14, // SPECIES_XATU
    0x12, // SPECIES_MAREEP
    0x13, // SPECIES_FLAAFFY
    0x16, // SPECIES_AMPHAROS
    0x11, // SPECIES_BELLOSSOM
    0x12, // SPECIES_MARILL
    0x13, // SPECIES_AZUMARILL
    0x02, // SPECIES_SUDOWOODO
    0x10, // SPECIES_POLITOED
    0x11, // SPECIES_HOPPIP
    0x11, // SPECIES_SKIPLOOM
    0x11, // SPECIES_JUMPLUFF
    0x10, // SPECIES_AIPOM
    0x13, // SPECIES_SUNKERN
    0x02, // SPECIES_SUNFLORA
    0x11, // SPECIES_YANMA
    0x0b, // SPECIES_WOOPER
    0x02, // SPECIES_QUAGSIRE
    0x14, // SPECIES_ESPEON
    0x14, // SPECIES_UMBREON
    0x12, // SPECIES_MURKROW
    0x13, // SPECIES_SLOWKING
    0x01, // SPECIES_MISDREAVUS
    0x14, // SPECIES_UNOWN
    0x0b, // SPECIES_WOBBUFFET
    0x14, // SPECIES_GIRAFARIG
    0x08, // SPECIES_PINECO
    0x09, // SPECIES_FORRETRESS
    0x0f, // SPECIES_DUNSPARCE
    0x05, // SPECIES_GLIGAR
    0x09, // SPECIES_STEELIX
    0x15, // SPECIES_SNUBBULL
    0x09, // SPECIES_GRANBULL
    0x0d, // SPECIES_QWILFISH
    0x15, // SPECIES_SCIZOR
    0x13, // SPECIES_SHUCKLE
    0x15, // SPECIES_HERACROSS
    0x0f, // SPECIES_SNEASEL
    0x13, // SPECIES_TEDDIURSA
    0x09, // SPECIES_URSARING
    0x17, // SPECIES_SLUGMA
    0x17, // SPECIES_MAGCARGO
    0x0a, // SPECIES_SWINUB
    0x08, // SPECIES_PILOSWINE
    0x02, // SPECIES_CORSOLA
    0x02, // SPECIES_REMORAID
    0x05, // SPECIES_OCTILLERY
    0x0f, // SPECIES_DELIBIRD
    0x02, // SPECIES_MANTINE
    0x15, // SPECIES_SKARMORY
    0x09, // SPECIES_HOUNDOUR
    0x09, // SPECIES_HOUNDOOM
    0x19, // SPECIES_KINGDRA
    0x15, // SPECIES_PHANPY
    0x0e, // SPECIES_DONPHAN
    0x01, // SPECIES_PORYGON2
    0x13, // SPECIES_STANTLER
    0x02, // SPECIES_SMEARGLE
    0x0f, // SPECIES_TYROGUE
    0x07, // SPECIES_HITMONTOP
    0x02, // SPECIES_SMOOCHUM
    0x08, // SPECIES_ELEKID
    0x17, // SPECIES_MAGBY
    0x02, // SPECIES_MILTANK
    0x13, // SPECIES_BLISSEY
    0x16, // SPECIES_RAIKOU
    0x17, // SPECIES_ENTEI
    0x19, // SPECIES_SUICUNE
    0x0e, // SPECIES_LARVITAR
    0x09, // SPECIES_PUPITAR
    0x0e, // SPECIES_TYRANITAR
    0x19, // SPECIES_LUGIA
    0x17, // SPECIES_HO_OH
    0x18, // SPECIES_CELEBI
    0x00, // SPECIES_OLD_UNOWN_B
    0x00, // SPECIES_OLD_UNOWN_C
    0x00, // SPECIES_OLD_UNOWN_D
    0x00, // SPECIES_OLD_UNOWN_E
    0x00, // SPECIES_OLD_UNOWN_F
    0x00, // SPECIES_OLD_UNOWN_G
    0x00, // SPECIES_OLD_UNOWN_H
    0x00, // SPECIES_OLD_UNOWN_I
    0x00, // SPECIES_OLD_UNOWN_J
    0x00, // SPECIES_OLD_UNOWN_K
    0x00, // SPECIES_OLD_UNOWN_L
    0x00, // SPECIES_OLD_UNOWN_M
    0x00, // SPECIES_OLD_UNOWN_N
    0x00, // SPECIES_OLD_UNOWN_O
    0x00, // SPECIES_OLD_UNOWN_P
    0x00, // SPECIES_OLD_UNOWN_Q
    0x00, // SPECIES_OLD_UNOWN_R
    0x00, // SPECIES_OLD_UNOWN_S
    0x00, // SPECIES_OLD_UNOWN_T
    0x00, // SPECIES_OLD_UNOWN_U
    0x00, // SPECIES_OLD_UNOWN_V
    0x00, // SPECIES_OLD_UNOWN_W
    0x00, // SPECIES_OLD_UNOWN_X
    0x00, // SPECIES_OLD_UNOWN_Y
    0x00, // SPECIES_OLD_UNOWN_Z
    0x10, // SPECIES_TREECKO
    0x15, // SPECIES_GROVYLE
    0x09, // SPECIES_SCEPTILE
    0x12, // SPECIES_TORCHIC
    0x10, // SPECIES_COMBUSKEN
    0x17, // SPECIES_BLAZIKEN
    0x02, // SPECIES_MUDKIP
    0x12, // SPECIES_MARSHTOMP
    0x19, // SPECIES_SWAMPERT
    0x12, // SPECIES_POOCHYENA
    0x08, // SPECIES_MIGHTYENA
    0x0f, // SPECIES_ZIGZAGOON
    0x15, // SPECIES_LINOONE
    0x0b, // SPECIES_WURMPLE
    0x08, // SPECIES_SILCOON
    0x11, // SPECIES_BEAUTIFLY
    0x08, // SPECIES_CASCOON
    0x0f, // SPECIES_DUSTOX
    0x02, // SPECIES_LOTAD
    0x10, // SPECIES_LOMBRE
    0x10, // SPECIES_LUDICOLO
    0x13, // SPECIES_SEEDOT
    0x09, // SPECIES_NUZLEAF
    0x14, // SPECIES_SHIFTRY
    0x0a, // SPECIES_NINCADA
    0x01, // SPECIES_NINJASK
    0x14, // SPECIES_SHEDINJA
    0x12, // SPECIES_TAILLOW
    0x15, // SPECIES_SWELLOW
    0x13, // SPECIES_SHROOMISH
    0x15, // SPECIES_BRELOOM
    0x07, // SPECIES_SPINDA
    0x11, // SPECIES_WINGULL
    0x11, // SPECIES_PELIPPER
    0x03, // SPECIES_SURSKIT
    0x11, // SPECIES_MASQUERAIN
    0x19, // SPECIES_WAILMER
    0x19, // SPECIES_WAILORD
    0x13, // SPECIES_SKITTY
    0x12, // SPECIES_DELCATTY
    0x01, // SPECIES_KECLEON
    0x13, // SPECIES_BALTOY
    0x14, // SPECIES_CLAYDOL
    0x0e, // SPECIES_NOSEPASS
    0x17, // SPECIES_TORKOAL
    0x01, // SPECIES_SABLEYE
    0x0b, // SPECIES_BARBOACH
    0x09, // SPECIES_WHISCASH
    0x04, // SPECIES_LUVDISC
    0x0f, // SPECIES_CORPHISH
    0x15, // SPECIES_CRAWDAUNT
    0x03, // SPECIES_FEEBAS
    0x19, // SPECIES_MILOTIC
    0x04, // SPECIES_CARVANHA
    0x15, // SPECIES_SHARPEDO
    0x13, // SPECIES_TRAPINCH
    0x01, // SPECIES_VIBRAVA
    0x0f, // SPECIES_FLYGON
    0x0e, // SPECIES_MAKUHITA
    0x0e, // SPECIES_HARIYAMA
    0x15, // SPECIES_ELECTRIKE
    0x09, // SPECIES_MANECTRIC
    0x0e, // SPECIES_NUMEL
    0x17, // SPECIES_CAMERUPT
    0x13, // SPECIES_SPHEAL
    0x09, // SPECIES_SEALEO
    0x09, // SPECIES_WALREIN
    0x0a, // SPECIES_CACNEA
    0x08, // SPECIES_CACTURNE
    0x0f, // SPECIES_SNORUNT
    0x0f, // SPECIES_GLALIE
    0x13, // SPECIES_LUNATONE
    0x13, // SPECIES_SOLROCK
    0x10, // SPECIES_AZURILL
    0x10, // SPECIES_SPOINK
    0x14, // SPECIES_GRUMPIG
    0x12, // SPECIES_PLUSLE
    0x12, // SPECIES_MINUN
    0x09, // SPECIES_MAWILE
    0x14, // SPECIES_MEDITITE
    0x14, // SPECIES_MEDICHAM
    0x11, // SPECIES_SWABLU
    0x11, // SPECIES_ALTARIA
    0x12, // SPECIES_WYNAUT
    0x01, // SPECIES_DUSKULL
    0x01, // SPECIES_DUSCLOPS
    0x18, // SPECIES_ROSELIA
    0x02, // SPECIES_SLAKOTH
    0x10, // SPECIES_VIGOROTH
    0x08, // SPECIES_SLAKING
    0x0b, // SPECIES_GULPIN
    0x0b, // SPECIES_SWALOT
    0x0e, // SPECIES_TROPIUS
    0x13, // SPECIES_WHISMUR
    0x09, // SPECIES_LOUDRED
    0x0d, // SPECIES_EXPLOUD
    0x13, // SPECIES_CLAMPERL
    0x11, // SPECIES_HUNTAIL
    0x11, // SPECIES_GOREBYSS
    0x14, // SPECIES_ABSOL
    0x01, // SPECIES_SHUPPET
    0x01, // SPECIES_BANETTE
    0x0b, // SPECIES_SEVIPER
    0x15, // SPECIES_ZANGOOSE
    0x02, // SPECIES_RELICANTH
    0x15, // SPECIES_ARON
    0x09, // SPECIES_LAIRON
    0x0e, // SPECIES_AGGRON
    0x11, // SPECIES_CASTFORM
    0x11, // SPECIES_VOLBEAT
    0x11, // SPECIES_ILLUMISE
    0x0c, // SPECIES_LILEEP
    0x0b, // SPECIES_CRADILY
    0x0f, // SPECIES_ANORITH
    0x09, // SPECIES_ARMALDO
    0x14, // SPECIES_RALTS
    0x14, // SPECIES_KIRLIA
    0x14, // SPECIES_GARDEVOIR
    0x09, // SPECIES_BAGON
    0x09, // SPECIES_SHELGON
    0x08, // SPECIES_SALAMENCE
    0x0f, // SPECIES_BELDUM
    0x15, // SPECIES_METANG
    0x09, // SPECIES_METAGROSS
    0x09, // SPECIES_REGIROCK
    0x09, // SPECIES_REGICE
    0x09, // SPECIES_REGISTEEL
    0x19, // SPECIES_KYOGRE
    0x17, // SPECIES_GROUDON
    0x0d, // SPECIES_RAYQUAZA
    0x01, // SPECIES_LATIAS
    0x01, // SPECIES_LATIOS
    0x11, // SPECIES_JIRACHI
    0x14, // SPECIES_DEOXYS
    0x11, // SPECIES_CHIMECHO
};

const u8 gUnknown_0860AA64[] = {0x00, 0x05, 0x01, 0x01, 0x00, 0x0f, 0x01, 0x04, 0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x01, 0x02, 0x00, 0x02, 0x00, 0xff};

const u8 gUnknown_0860AA80[][2] =
{
    {6,     30},
    {0xFE,  15},
    {6,     30},
    {0xFF,  0}
};

static void (* const sMonAnimFunctions[])(struct Sprite *sprite) =
{
    pokemonanimfunc_00,
    pokemonanimfunc_01,
    pokemonanimfunc_02,
    pokemonanimfunc_03,
    pokemonanimfunc_04,
    pokemonanimfunc_05,
    pokemonanimfunc_06,
    pokemonanimfunc_07,
    pokemonanimfunc_08,
    pokemonanimfunc_09,
    pokemonanimfunc_0A,
    pokemonanimfunc_0B,
    pokemonanimfunc_0C,
    pokemonanimfunc_0D,
    pokemonanimfunc_0E,
    pokemonanimfunc_0F,
    pokemonanimfunc_10,
    pokemonanimfunc_11,
    pokemonanimfunc_12,
    pokemonanimfunc_13,
    pokemonanimfunc_14,
    pokemonanimfunc_15,
    pokemonanimfunc_16,
    pokemonanimfunc_17,
    pokemonanimfunc_18,
    pokemonanimfunc_19,
    pokemonanimfunc_1A,
    pokemonanimfunc_1B,
    pokemonanimfunc_1C,
    pokemonanimfunc_1D,
    pokemonanimfunc_1E,
    pokemonanimfunc_1F,
    pokemonanimfunc_20,
    pokemonanimfunc_21,
    pokemonanimfunc_22,
    pokemonanimfunc_23,
    pokemonanimfunc_24,
    pokemonanimfunc_25,
    pokemonanimfunc_26,
    pokemonanimfunc_27,
    pokemonanimfunc_28,
    pokemonanimfunc_29,
    pokemonanimfunc_2A,
    pokemonanimfunc_2B,
    pokemonanimfunc_2C,
    pokemonanimfunc_2D,
    pokemonanimfunc_2E,
    pokemonanimfunc_2F,
    pokemonanimfunc_30,
    pokemonanimfunc_31,
    pokemonanimfunc_32,
    pokemonanimfunc_33,
    pokemonanimfunc_34,
    pokemonanimfunc_35,
    pokemonanimfunc_36,
    pokemonanimfunc_37,
    pokemonanimfunc_38,
    pokemonanimfunc_39,
    pokemonanimfunc_3A,
    pokemonanimfunc_3B,
    pokemonanimfunc_3C,
    pokemonanimfunc_3D,
    pokemonanimfunc_3E,
    pokemonanimfunc_3F,
    pokemonanimfunc_40,
    pokemonanimfunc_41,
    pokemonanimfunc_42,
    pokemonanimfunc_43,
    pokemonanimfunc_44,
    pokemonanimfunc_45,
    pokemonanimfunc_46,
    pokemonanimfunc_47,
    pokemonanimfunc_48,
    pokemonanimfunc_49,
    pokemonanimfunc_4A,
    pokemonanimfunc_4B,
    pokemonanimfunc_4C,
    pokemonanimfunc_4D,
    pokemonanimfunc_4E,
    pokemonanimfunc_4F,
    pokemonanimfunc_50,
    pokemonanimfunc_51,
    pokemonanimfunc_52,
    pokemonanimfunc_53,
    pokemonanimfunc_54,
    pokemonanimfunc_55,
    pokemonanimfunc_56,
    pokemonanimfunc_57,
    pokemonanimfunc_58,
    pokemonanimfunc_59,
    pokemonanimfunc_5A,
    pokemonanimfunc_5B,
    pokemonanimfunc_5C,
    pokemonanimfunc_5D,
    pokemonanimfunc_5E,
    pokemonanimfunc_5F,
    pokemonanimfunc_60,
    pokemonanimfunc_61,
    pokemonanimfunc_62,
    pokemonanimfunc_63,
    pokemonanimfunc_64,
    pokemonanimfunc_65,
    pokemonanimfunc_66,
    pokemonanimfunc_67,
    pokemonanimfunc_68,
    pokemonanimfunc_69,
    pokemonanimfunc_6A,
    pokemonanimfunc_6B,
    pokemonanimfunc_6C,
    pokemonanimfunc_6D,
    pokemonanimfunc_6E,
    pokemonanimfunc_6F,
    pokemonanimfunc_70,
    pokemonanimfunc_71,
    pokemonanimfunc_72,
    pokemonanimfunc_73,
    pokemonanimfunc_74,
    pokemonanimfunc_75,
    pokemonanimfunc_76,
    pokemonanimfunc_77,
    pokemonanimfunc_78,
    pokemonanimfunc_79,
    pokemonanimfunc_7A,
    pokemonanimfunc_7B,
    pokemonanimfunc_7C,
    pokemonanimfunc_7D,
    pokemonanimfunc_7E,
    pokemonanimfunc_7F,
    pokemonanimfunc_80,
    pokemonanimfunc_81,
    pokemonanimfunc_82,
    pokemonanimfunc_83,
    pokemonanimfunc_84,
    pokemonanimfunc_85,
    pokemonanimfunc_86,
    pokemonanimfunc_87,
    pokemonanimfunc_88,
    pokemonanimfunc_89,
    pokemonanimfunc_8A,
    pokemonanimfunc_8B,
    pokemonanimfunc_8C,
    pokemonanimfunc_8D,
    pokemonanimfunc_8E,
    pokemonanimfunc_8F,
    pokemonanimfunc_90,
    pokemonanimfunc_91,
    pokemonanimfunc_92,
    pokemonanimfunc_93,
    pokemonanimfunc_94,
    pokemonanimfunc_95,
    pokemonanimfunc_96
};

// counting from Id 1, because 0 in sSpeciesToBackAnimId is used for mons with no back animation
static const u8 sBackAnimationIds[] =
{
    0x60, 0x5f, 0x02, // 1
    0x5e, 0x03, 0x46, // 2
    0x6d, 0x3e, 0x6e, // 3
    0x6f, 0x70, 0x3f, // 4
    0x71, 0x13, 0x72, // 5
    0x6c, 0x6b, 0x3a, // 6
    0x64, 0x14, 0x4f, // 7
    0x5d, 0x0f, 0x4c, // 8
    0x61, 0x57, 0x58, // 9
    0x67, 0x66, 0x59, // 0xA
    0x74, 0x73, 0x5a, // 0xB
    0x75, 0x76, 0x5b, // 0xC
    0x77, 0x78, 0x65, // 0xD
    0x63, 0x5c, 0x62, // 0xE
    0x6a, 0x69, 0x68, // 0xF
    0x7b, 0x7a, 0x79, // 0x10
    0x7e, 0x7d, 0x7c, // 0x11
    0x81, 0x80, 0x7f, // 0x12
    0x84, 0x82, 0x83, // 0x13
    0x85, 0x86, 0x87, // 0x14
    0x88, 0x89, 0x8a, // 0x15
    0x8b, 0x8c, 0x8d, // 0x16
    0x8e, 0x8f, 0x90, // 0x17
    0x91, 0x92, 0x93, // 0x18
    0x94, 0x95, 0x96, // 0x19
};

static const u8 sBackAnimNatureModTable[] =
{
    0x00, // NATURE_HARDY
	0x02, // NATURE_LONELY
	0x00, // NATURE_BRAVE
	0x00, // NATURE_ADAMANT
	0x00, // NATURE_NAUGHTY
	0x01, // NATURE_BOLD
	0x01, // NATURE_DOCILE
	0x01, // NATURE_RELAXED
	0x00, // NATURE_IMPISH
	0x01, // NATURE_LAX
	0x02, // NATURE_TIMID
	0x00, // NATURE_HASTY
	0x01, // NATURE_SERIOUS
	0x00, // NATURE_JOLLY
	0x00, // NATURE_NAIVE
	0x02, // NATURE_MODEST
	0x02, // NATURE_MILD
	0x02, // NATURE_QUIET
	0x02, // NATURE_BASHFUL
	0x01, // NATURE_RASH
	0x01, // NATURE_CALM
	0x02, // NATURE_GENTLE
	0x01, // NATURE_SASSY
	0x02, // NATURE_CAREFUL
	0x01, // NATURE_QUIRKY
};

static const union AffineAnimCmd gSpriteAffineAnim_860AD48[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMDTYPE_END
};

static const union AffineAnimCmd gSpriteAffineAnim_860AD58[] =
{
    AFFINEANIMCMD_FRAME(-0x100, 0x100, 0, 0),
    AFFINEANIMCMDTYPE_END
};

static const union AffineAnimCmd *const gSpriteAffineAnimTable_860AD68[] =
{
    gSpriteAffineAnim_860AD48,
    gSpriteAffineAnim_860AD58
};

extern const s8 gUnknown_0860AD70[][3];

// code
void MonAnimDummySpriteCallback(struct Sprite *sprite)
{
}

void sub_817F3F0(struct Sprite *sprite, s16 index, s16 amplitudeX, s16 amplitudeY)
{
    s16 xAdder, yAdder;

    amplitudeX *= -1;
    amplitudeY *= -1;

    xAdder = Cos(index, amplitudeX) - Sin(index, amplitudeY);
    yAdder = Cos(index, amplitudeY) + Sin(index, amplitudeX);

    amplitudeX *= -1;
    amplitudeY *= -1;

    sprite->pos2.x = xAdder + amplitudeX;
    sprite->pos2.y = yAdder + amplitudeY;
}

u8 GetSpeciesBackAnimId(u16 species)
{
    if (sSpeciesToBackAnimId[species] != 0)
        return sSpeciesToBackAnimId[species] - 1;
    else
        return 0;
}

void sub_817F498(u8 taskId)
{
    u32 i;
    struct Sprite *sprite = (struct Sprite*)(u32)((gTasks[taskId].data[1] << 0x10) | (gTasks[taskId].data[2]));

    if (gTasks[taskId].data[0] == 0)
    {
        gTasks[taskId].data[4] = sprite->data[0];
        gTasks[taskId].data[5] = sprite->data[2];
        sprite->data[1] = 1;
        sprite->data[0] = 0;

        for (i = 2; i < 8; i++)
            sprite->data[i] = 0;

        sprite->callback = sMonAnimFunctions[gTasks[taskId].data[3]];
        gUnknown_03001274 = FALSE;

        gTasks[taskId].data[0]++;
    }
    if (sprite->callback == SpriteCallbackDummy)
    {
        sprite->data[0] = gTasks[taskId].data[4];
        sprite->data[2] = gTasks[taskId].data[5];
        sprite->data[1] = 0;

        DestroyTask(taskId);
    }
}

void LaunchAnimationTaskForFrontSprite(struct Sprite *sprite, u8 frontAnimId)
{
    u8 taskId = CreateTask(sub_817F498, 128);
    gTasks[taskId].data[1] = (u32)(sprite) >> 0x10;
    gTasks[taskId].data[2] = (u32)(sprite);
    gTasks[taskId].data[3] = frontAnimId;
}

void sub_817F578(struct Sprite *sprite, u8 frontAnimId)
{
    gUnknown_03001274 = TRUE;
    sprite->callback = sMonAnimFunctions[frontAnimId];
}

void LaunchAnimationTaskForBackSprite(struct Sprite *sprite, u8 backAnimId)
{
    u8 nature, taskId, animId, bank;

    taskId = CreateTask(sub_817F498, 128);
    gTasks[taskId].data[1] = (u32)(sprite) >> 0x10;
    gTasks[taskId].data[2] = (u32)(sprite);

    bank = sprite->data[0];
    nature = GetNature(&gPlayerParty[gBattlePartyID[bank]]);

    animId = 3 * backAnimId + sBackAnimNatureModTable[nature];
    gTasks[taskId].data[3] = sBackAnimationIds[animId];
}

void sub_817F60C(struct Sprite *sprite)
{
    sprite->callback = MonAnimDummySpriteCallback;
}

void SetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    u8 matrixNum;
    struct ObjAffineSrcData affineSrcData;
    struct OamMatrix dest;

    affineSrcData.xScale = xScale;
    affineSrcData.yScale = yScale;
    affineSrcData.rotation = rotation;

    matrixNum = sprite->oam.matrixNum;

    ObjAffineSet(&affineSrcData, &dest, 1, 2);
    gOamMatrices[matrixNum].a = dest.a;
    gOamMatrices[matrixNum].b = dest.b;
    gOamMatrices[matrixNum].c = dest.c;
    gOamMatrices[matrixNum].d = dest.d;
}

void HandleStartAffineAnim(struct Sprite *sprite)
{
    sprite->oam.affineMode = 3;
    sprite->affineAnims = gSpriteAffineAnimTable_860AD68;

    if (gUnknown_03001274 == TRUE)
        InitSpriteAffineAnim(sprite);

    if (!sprite->data[1])
        StartSpriteAffineAnim(sprite, 1);
    else
        StartSpriteAffineAnim(sprite, 0);

    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);
    sprite->affineAnimPaused = 1;
}

void HandleSetAffineData(struct Sprite *sprite, s16 xScale, s16 yScale, u16 rotation)
{
    if (!sprite->data[1])
    {
        xScale *= -1;
        rotation *= -1;
    }

    SetAffineData(sprite, xScale, yScale, rotation);
}

void sub_817F70C(struct Sprite *sprite)
{
    if (!sprite->data[1])
        sprite->pos2.x *= -1;
}

bool32 sub_817F724(u8 id)
{
    if (id >= 4)
    {
        return FALSE;
    }
    else
    {
        gUnknown_03001240[id].field_6 = 0;
        gUnknown_03001240[id].field_0 = 0;
        gUnknown_03001240[id].field_4 = 1;
        gUnknown_03001240[id].field_2 = 0;
        gUnknown_03001240[id].field_8 = 0;
        return TRUE;
    }
}

u8 sub_817F758(void)
{
    gUnknown_03001270 = (gUnknown_03001270 + 1) % 4;
    sub_817F724(gUnknown_03001270);
    return gUnknown_03001270;
}

void sub_817F77C(struct Sprite *sprite)
{
    sprite->oam.affineMode = 1;
    CalcCenterToCornerVec(sprite, sprite->oam.shape, sprite->oam.size, sprite->oam.affineMode);

    if (gUnknown_03001274 == TRUE)
    {
        if (!sprite->data[1])
            sprite->hFlip = 1;
        else
            sprite->hFlip = 0;

        FreeOamMatrix(sprite->oam.matrixNum);
        sprite->oam.matrixNum |= (sprite->hFlip << 3);
        sprite->oam.affineMode = 0;
    }
}

void pokemonanimfunc_01(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 var = (sprite->data[2] * 512 / 40) % 256;

        sprite->data[4] = Sin(var, 32) + 256;
        sprite->data[5] = Cos(var, 32) + 256;
        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void pokemonanimfunc_02(struct Sprite *sprite)
{
    if (sprite->data[2] > 40)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s8 var;

        if (!(sprite->data[2] & 1))
            var = 1;
        else
            var = -1;

        sprite->pos2.x = Sin((sprite->data[2] * 128 / 40) % 256, 6) * var;
    }

    sprite->data[2]++;
}

void sub_817F8FC(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x = Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6);
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

void pokemonanimfunc_03(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sub_817F8FC(sprite);
    sprite->callback = sub_817F8FC;
}

void sub_817F978(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] > sprite->data[0])
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = -(Sin((sprite->data[2] * 384 / sprite->data[0]) % 256, 6));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

void pokemonanimfunc_04(struct Sprite *sprite)
{
    sprite->data[0] = 40;
    sub_817F978(sprite);
    sprite->callback = sub_817F978;
}

#ifdef NONMATCHING
void sub_817F9F4(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 384)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s32 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->pos2.y = -(Sin(counter % 128, sprite->data[0] * 2));
            break;
        case 2:
        case 3:
            sprite->pos2.y = -(Sin(counter - 256, sprite->data[0] * 3));
            break;
        }
    }

    sprite->data[2] += 12;
}

#else
__attribute__((naked))
void sub_817F9F4(struct Sprite *sprite)
{
    asm(".syntax unified\n\
        	push {r4,lr}\n\
	adds r4, r0, 0\n\
	movs r0, 0x32\n\
	ldrsh r1, [r4, r0]\n\
	movs r0, 0xC0\n\
	lsls r0, 1\n\
	cmp r1, r0\n\
	ble _0817FA14\n\
	ldr r0, =SpriteCB_SetDummyOnAnimEnd\n\
	str r0, [r4, 0x1C]\n\
	movs r0, 0\n\
	strh r0, [r4, 0x24]\n\
	b _0817FA5E\n\
	.pool\n\
_0817FA14:\n\
	adds r0, r1, 0\n\
	cmp r1, 0\n\
	bge _0817FA1C\n\
	adds r0, 0x7F\n\
_0817FA1C:\n\
	asrs r2, r0, 7\n\
	lsls r0, r2, 16\n\
	asrs r0, 16\n\
	cmp r0, 0\n\
	blt _0817FA60\n\
	cmp r0, 0x1\n\
	ble _0817FA48\n\
	cmp r0, 0x3\n\
	bgt _0817FA60\n\
	ldr r2, =0xffffff00\n\
	adds r1, r2\n\
	lsls r0, r1, 16\n\
	asrs r0, 16\n\
	movs r1, 0x2E\n\
	ldrsh r2, [r4, r1]\n\
	lsls r1, r2, 1\n\
	adds r1, r2\n\
	lsls r1, 16\n\
	b _0817FA56\n\
	.pool\n\
_0817FA48:\n\
	lsls r0, r2, 7\n\
	subs r0, r1, r0\n\
	lsls r0, 16\n\
	asrs r0, 16\n\
	movs r2, 0x2E\n\
	ldrsh r1, [r4, r2]\n\
	lsls r1, 17\n\
_0817FA56:\n\
	asrs r1, 16\n\
	bl Sin\n\
	negs r0, r0\n\
_0817FA5E:\n\
	strh r0, [r4, 0x26]\n\
_0817FA60:\n\
	ldrh r0, [r4, 0x32]\n\
	adds r0, 0xC\n\
	strh r0, [r4, 0x32]\n\
	pop {r4}\n\
	pop {r0}\n\
	bx r0\n\
        .syntax divided");
}

#endif // NONMATCHING

void pokemonanimfunc_1E(struct Sprite *sprite)
{
    sprite->data[0] = 4;
    sub_817F9F4(sprite);
    sprite->callback = sub_817F9F4;
}

void pokemonanimfunc_06(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 768)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s16 divCounter = counter / 128;

        switch (divCounter)
        {
        case 0:
        case 1:
            sprite->pos2.x = 0;
            break;
        case 2:
            counter = 0;
            break;
        case 3:
            sprite->pos2.x = -(counter % 128 * 8) / 128;
            break;
        case 4:
            sprite->pos2.x = (counter % 128) / 8 - 8;
            break;
        case 5:
            sprite->pos2.x = -(counter % 128 * 8) / 128 + 8;
            break;
        }

        sprite->pos2.y = -(Sin(counter % 128, 8));
    }

    sprite->data[2] += 12;
}

void pokemonanimfunc_09(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256 / 40) % 256;

        if (sprite->data[2] % 2 == 0)
        {
            sprite->data[4] = Sin(index, 32) + 256;
            sprite->data[5] = Sin(index, 32) + 256;
        }
        else
        {
            sprite->data[4] = Sin(index, 8) + 256;
            sprite->data[5] = Sin(index, 8) + 256;
        }

        HandleSetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void sub_817FC20(struct Sprite *sprite)
{
    sub_817F70C(sprite);

    if (sprite->data[2] == 0)
        sprite->data[3] = 0;

    if (gUnknown_0860AD70[sprite->data[3]][2] == sprite->data[2])
    {
        if (gUnknown_0860AD70[sprite->data[3]][2] == 0)
        {
            sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        }
        else
        {
            sprite->data[3]++;
            sprite->data[2] = 0;
        }
    }

    if (gUnknown_0860AD70[sprite->data[3]][2] == 0)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->pos2.x += gUnknown_0860AD70[sprite->data[3]][0];
        sprite->pos2.y += gUnknown_0860AD70[sprite->data[3]][1];
        sprite->data[2]++;
        sub_817F70C(sprite);
    }
}

void pokemonanimfunc_0A(struct Sprite *sprite)
{
    sub_817FC20(sprite);
    sprite->callback = sub_817FC20;
}

void sub_817FCDC(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        sprite->pos2.x = Sin(counter % 256, sprite->data[7]);
    }

    sprite->data[2] += sprite->data[0];
}

void pokemonanimfunc_0F(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sprite->data[7] = 3;
    sub_817FCDC(sprite);
    sprite->callback = sub_817FCDC;
}

void sub_817FD44(struct Sprite *sprite)
{
    s32 counter = sprite->data[2];

    if (counter > 2304)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin(counter % 256, 3);
    }

    sprite->data[2] += sprite->data[0];
}

void pokemonanimfunc_10(struct Sprite *sprite)
{
    sprite->data[0] = 60;
    sub_817FD44(sprite);
    sprite->callback = sub_817FD44;
}

void pokemonanimfunc_11(struct Sprite *sprite)
{
    if (sprite->data[2] > 512)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
    }
    else
    {
        s8 var;
        s32 index, amplitude;

        if (!(sprite->data[2] & 1))
            var = 1;
        else
            var = -1;

        amplitude = Sin(sprite->data[2] / 4, 8);
        index = sprite->data[2] % 256;

        sprite->pos2.y = Sin(index, amplitude) * var;
        sprite->pos2.x = Cos(index, amplitude) * var;
    }

    sprite->data[2] += 9;
}

void sub_817FE30(struct Sprite *sprite)
{
    s16 id = sprite->data[0];

    if (gUnknown_03001240[id].field_0 != 0)
    {
        gUnknown_03001240[id].field_0--;
    }
    else
    {
        if (sprite->data[2] == 0 && gUnknown_03001240[id].field_8 == 0)
        {
            HandleStartAffineAnim(sprite);
            gUnknown_03001240[id].field_8++;
        }

        if (sprite->data[2] > gUnknown_03001240[id].field_6)
        {
            HandleSetAffineData(sprite, 0x100, 0x100, 0);

            if (gUnknown_03001240[id].field_4 > 1)
            {
                gUnknown_03001240[id].field_4--;
                gUnknown_03001240[id].field_0 = 10;
                sprite->data[2] = 0;
            }
            else
            {
                sub_817F77C(sprite);
                sprite->callback = SpriteCB_SetDummyOnAnimEnd;
            }
        }
        else
        {
            sprite->data[6] = Sin(sprite->data[2] % 256, 4096);
            HandleSetAffineData(sprite, 0x100, 0x100, sprite->data[6]);
        }

        sprite->data[2] += 16;
    }
}

void pokemonanimfunc_12(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    gUnknown_03001240[id].field_6 = 512;
    gUnknown_03001240[id].field_0 = 0;
    sub_817FE30(sprite);
    sprite->callback = sub_817FE30;
}

void sub_817FF3C(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > gUnknown_03001240[id].field_0)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = (65536 / gUnknown_03001240[id].field_8) * sprite->data[2];
        HandleSetAffineData(sprite, 0x100, 0x100, sprite->data[6]);
    }

    sprite->data[2]++;
}

void pokemonanimfunc_1F(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    gUnknown_03001240[id].field_0 = 60;
    gUnknown_03001240[id].field_8 = 20;
    sub_817FF3C(sprite);
    sprite->callback = sub_817FF3C;
}

void sub_817FFF0(struct Sprite *sprite)
{
    u8 id = sprite->data[0];

    sub_817F70C(sprite);

    if (sprite->data[2] > gUnknown_03001240[id].field_6)
    {
        sprite->pos2.x = 0;
        sprite->pos2.y = 0;
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] + 192) % 256;

        sprite->pos2.x = -(Cos(index, gUnknown_03001240[id].field_8 * 2));
        sprite->pos2.y = Sin(index, gUnknown_03001240[id].field_8) + gUnknown_03001240[id].field_8;
    }

    sprite->data[2] += gUnknown_03001240[id].field_2;
    sub_817F70C(sprite);
}

void pokemonanimfunc_14(struct Sprite *sprite)
{
    u8 id = sprite->data[0] = sub_817F758();

    gUnknown_03001240[id].field_6 = 512;
    gUnknown_03001240[id].field_8 = 6;
    gUnknown_03001240[id].field_2 = 24;
    sub_817FFF0(sprite);
    sprite->callback = sub_817FFF0;
}

void pokemonanimfunc_15(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        sprite->data[7] = (sprite->oam.paletteNum * 16) + 256;

    if (sprite->data[2] > 128)
    {
        BlendPalette(sprite->data[7], 0x10, 0, 0);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        sprite->data[6] = Sin(sprite->data[2], 16);
        BlendPalette(sprite->data[7], 0x10, sprite->data[6], 0);
    }

    sprite->data[2]++;
}

void pokemonanimfunc_16(struct Sprite *sprite)
{
    s16 index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (sprite->data[1] == 0)
            sprite->data[4] = (Sin(index2, 40) - 256) + Sin(index1, 16);
        else
            sprite->data[4] = (256 - Sin(index2, 40)) - Sin(index1, 16);

        sprite->data[5] = Sin(index2, 16) + 256;
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void pokemonanimfunc_17(struct Sprite *sprite)
{
    s16 posY = 0, index1 = 0, index2 = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 40)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = posY;
    }
    else
    {
        index2 = (sprite->data[2] * 128) / 40;

        if (sprite->data[2] >= 10 && sprite->data[2] <= 29)
        {
            sprite->data[7] += 51;
            index1 = 0xFF & sprite->data[7];
        }

        if (sprite->data[1] == 0)
            sprite->data[4] = -(Sin(index2, 16)) - 256;
        else
            sprite->data[4] = Sin(index2, 16) + 256;

        sprite->data[5] = (256 - Sin(index2, 40)) - Sin(index1, 8);

        if (sprite->data[5] != 256)
            posY = (256 - sprite->data[5]) / 8;

        sprite->pos2.y = -(posY);
        SetAffineData(sprite, sprite->data[4], sprite->data[5], 0);
    }

    sprite->data[2]++;
}

void sub_818031C(struct Sprite *sprite)
{
    u8 index = sprite->data[2];
    u8 var7 = sprite->data[6];
    u8 var5 = gUnknown_0860AA80[sprite->data[5]][0];
    u8 var6 = gUnknown_0860AA80[sprite->data[5]][1];
    u8 amplitude = 0;

    if (var5 != 0xFE)
        amplitude = (var6 - var7) * var5 / var6;
    else
        amplitude = 0;

    if (var5 == 0xFF)
    {
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.y = 0;
    }
    else
    {
        sprite->pos2.y = Sin(index, amplitude);

        if (var7 == var6)
        {
            sprite->data[5]++;
            sprite->data[6] = 0;
        }
        else
        {
            sprite->data[2] += sprite->data[0];
            sprite->data[6]++;
        }
    }
}

void pokemonanimfunc_19(struct Sprite *sprite)
{
    sprite->data[0] = 48;
    sub_818031C(sprite);
    sprite->callback = sub_818031C;
}

void pokemonanimfunc_1A(struct Sprite *sprite)
{
    u8 counter = 0;

    sub_817F70C(sprite);
    counter = sprite->data[2];

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 35)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
        sprite->pos2.x = 0;
    }
    else
    {
        s16 index = ((counter - 10) * 128) / 20;

        if (counter < 10)
            HandleSetAffineData(sprite, 0x100, 0x100, counter / 2 * 512);
        else if (counter >= 10 && counter <= 29)
            sprite->pos2.x = -(Sin(index, 5));
        else
            HandleSetAffineData(sprite, 0x100, 0x100, (35 - counter) / 2 * 1024);
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}

void pokemonanimfunc_1B(struct Sprite *sprite)
{
    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 index = (sprite->data[2] * 256) / 100;
        sprite->pos2.y = Sin(index, 10);
        HandleSetAffineData(sprite, 0x100, 0x100, Sin(index, 3276));
    }

    sprite->data[2]++;
}

void sub_81804F8(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->pos2.y = Sin(index, sprite->data[0]);
        HandleSetAffineData(sprite, 0x100, 0x100, Sin(var, 3276));
    }

    sprite->data[2]++;
}

void pokemonanimfunc_1C(struct Sprite *sprite)
{
    sprite->data[0] = 10;
    sub_81804F8(sprite);
    sprite->callback = sub_81804F8;
}

void sub_81805B0(struct Sprite *sprite)
{
    s32 var = 0;
    s16 index = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sprite->pos2.y = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        index = (sprite->data[2] * 256) / 100;
        var = (sprite->data[2] * 512) / 100;
        var &= 0xFF;
        sprite->pos2.y = -(Sin(index / 2, sprite->data[0] * 2));
        HandleSetAffineData(sprite, 0x100, 0x100, Sin(var, 3276));
    }

    sprite->data[2]++;
}

void pokemonanimfunc_18(struct Sprite *sprite)
{
    sprite->data[0] = 5;
    sub_81805B0(sprite);
    sprite->callback = sub_81805B0;
}

void pokemonanimfunc_1D(struct Sprite *sprite)
{
    s32 var;
    s16 index = 0;

    sub_817F70C(sprite);
    var = 0;

    if (sprite->data[2] == 0)
        HandleStartAffineAnim(sprite);

    if (sprite->data[2] > 100)
    {
        HandleSetAffineData(sprite, 0x100, 0x100, 0);
        sprite->pos2.x = 0;
        sub_817F77C(sprite);
        sprite->callback = SpriteCB_SetDummyOnAnimEnd;
    }
    else
    {
        s16 toDiv = 100;

        index = (sprite->data[2] * 256) / toDiv;
        var = (sprite->data[2] * 512) / toDiv;
        var &= 0xFF;
        sprite->pos2.x = Sin(index, 8);
        HandleSetAffineData(sprite, 0x100, 0x100, Sin(var, 3276));
    }

    sprite->data[2]++;
    sub_817F70C(sprite);
}
