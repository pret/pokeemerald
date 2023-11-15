#include "global.h"
#include "overworld.h"
#include "battle_pyramid.h"
#include "battle_setup.h"
#include "berry.h"
#include "bg.h"
#include "cable_club.h"
#include "clock.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_camera.h"
#include "field_control_avatar.h"
#include "field_door.h"
#include "field_effect.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_special_scene.h"
#include "field_specials.h"
#include "field_tasks.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "gpu_regs.h"
#include "heal_location.h"
#include "io_reg.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "malloc.h"
#include "m4a.h"
#include "map_name_popup.h"
#include "match_call.h"
#include "menu.h"
#include "metatile_behavior.h"
#include "mirage_tower.h"
#include "money.h"
#include "new_game.h"
#include "palette.h"
#include "play_time.h"
#include "pokemon.h"
#include "random.h"
#include "roamer.h"
#include "rotating_gate.h"
#include "safari_zone.h"
#include "save.h"
#include "save_location.h"
#include "script.h"
#include "script_pokemon_util.h"
#include "secret_base.h"
#include "sound.h"
#include "sprite.h"
#include "start_menu.h"
#include "task.h"
#include "tileset_anims.h"
#include "time_events.h"
#include "trainer_hill.h"
#include "trainer_pokemon_sprites.h"
#include "tv.h"
#include "scanline_effect.h"
#include "wild_encounter.h"
#include "frontier_util.h"
#include "follow_me.h"
#include "constants/abilities.h"
#include "constants/layouts.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "constants/songs.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/items.h"

struct CableClubPlayer
{
    u8 playerId;
    u8 isLocalPlayer;
    u8 movementMode;
    u8 facing;
    struct MapPosition pos;
    u16 metatileBehavior;
};

#define PLAYER_LINK_STATE_IDLE 0x80
#define PLAYER_LINK_STATE_BUSY 0x81
#define PLAYER_LINK_STATE_READY 0x82
#define PLAYER_LINK_STATE_EXITING_ROOM 0x83

#define FACING_NONE 0
#define FACING_UP 1
#define FACING_DOWN 2
#define FACING_LEFT 3
#define FACING_RIGHT 4
#define FACING_FORCED_UP 7
#define FACING_FORCED_DOWN 8
#define FACING_FORCED_LEFT 9
#define FACING_FORCED_RIGHT 10

extern const struct MapLayout *const gMapLayouts[];
extern const struct MapHeader *const *const gMapGroups[];

static void Overworld_ResetStateAfterWhiteOut(void);
static void CB2_ReturnToFieldLocal(void);
static void CB2_ReturnToFieldLink(void);
static void CB2_LoadMapOnReturnToFieldCableClub(void);
static void CB2_LoadMap2(void);
static void VBlankCB_Field(void);
static void SpriteCB_LinkPlayer(struct Sprite *);
static void ChooseAmbientCrySpecies(void);
static void DoMapLoadLoop(u8 *);
static bool32 LoadMapInStepsLocal(u8 *, bool32);
static bool32 LoadMapInStepsLink(u8 *);
static bool32 ReturnToFieldLocal(u8 *);
static bool32 ReturnToFieldLink(u8 *);
static void InitObjectEventsLink(void);
static void InitObjectEventsLocal(void);
static void InitOverworldGraphicsRegisters(void);
static u8 GetSpriteForLinkedPlayer(u8);
static u16 KeyInterCB_SendNothing(u32);
static void ResetMirageTowerAndSaveBlockPtrs(void);
static void ResetScreenForMapLoad(void);
static void OffsetCameraFocusByLinkPlayerId(void);
static void SpawnLinkPlayers(void);
static void SetCameraToTrackGuestPlayer(void);
static void ResumeMap(bool32);
static void SetCameraToTrackPlayer(void);
static void InitObjectEventsReturnToField(void);
static void InitViewGraphics(void);
static void SetCameraToTrackGuestPlayer_2(void);
static void CreateLinkPlayerSprites(void);
static void ClearAllPlayerKeys(void);
static void ResetAllPlayerLinkStates(void);
static void UpdateHeldKeyCode(u16);
static void UpdateAllLinkPlayers(u16 *, s32);
static u8 FlipVerticalAndClearForced(u8, u8);
static u8 LinkPlayerGetCollision(u8, u8, s16, s16);
static void CreateLinkPlayerSprite(u8, u8);
static void GetLinkPlayerCoords(u8, u16 *, u16 *);
static u8 GetLinkPlayerFacingDirection(u8);
static u8 GetLinkPlayerElevation(u8);
static u8 GetLinkPlayerIdAt(s16, s16);
static void SetPlayerFacingDirection(u8, u8);
static void ZeroObjectEvent(struct ObjectEvent *);
static void SpawnLinkPlayerObjectEvent(u8, s16, s16, u8);
static void InitLinkPlayerObjectEventPos(struct ObjectEvent *, s16, s16);
static u8 GetSpriteForLinkedPlayer(u8);
static void RunTerminateLinkScript(void);
static u32 GetLinkSendQueueLength(void);
static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *);
static const u8 *TryInteractWithPlayer(struct CableClubPlayer *);
static u16 GetDirectionForEventScript(const u8 *);
static void InitLinkPlayerQueueScript(void);
static void InitLinkRoomStartMenuScript(void);
static void RunInteractLocalPlayerScript(const u8 *);
static void RunConfirmLeaveCableClubScript(void);
static void InitMenuBasedScript(const u8 *);
static void LoadCableClubPlayer(s32, s32, struct CableClubPlayer *);
static bool32 IsCableClubPlayerUnfrozen(struct CableClubPlayer *);
static bool32 CanCableClubPlayerPressStart(struct CableClubPlayer *);
static const u8 *TryGetTileEventScript(struct CableClubPlayer *);
static bool32 PlayerIsAtSouthExit(struct CableClubPlayer *);
static const u8 *TryInteractWithPlayer(struct CableClubPlayer *);
static u16 KeyInterCB_DeferToRecvQueue(u32);
static u16 KeyInterCB_DeferToSendQueue(u32);
static void ResetPlayerHeldKeys(u16 *);
static u16 KeyInterCB_SelfIdle(u32);
static u16 KeyInterCB_DeferToEventScript(u32);
static u16 GetDirectionForDpadKey(u16);
static void CB1_OverworldLink(void);
static void SetKeyInterceptCallback(u16 (*func)(u32));
static void SetFieldVBlankCallback(void);
static void FieldClearVBlankHBlankCallbacks(void);
static void TransitionMapMusic(void);
static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *, u16, u8);
static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *, u8, u16, u8);
static u16 GetCenterScreenMetatileBehavior(void);

static void *sUnusedOverworldCallback;
static u8 sPlayerLinkStates[MAX_LINK_PLAYERS];
// This callback is called with a player's key code. It then returns an
// adjusted key code, effectively intercepting the input before anything
// can process it.
static u16 (*sPlayerKeyInterceptCallback)(u32);
static bool8 sReceivingFromLink;
static u8 sRfuKeepAliveTimer;

u16 *gOverworldTilemapBuffer_Bg2;
u16 *gOverworldTilemapBuffer_Bg1;
u16 *gOverworldTilemapBuffer_Bg3;
u16 gHeldKeyCodeToSend;
void (*gFieldCallback)(void);
bool8 (*gFieldCallback2)(void);
u8 gLocalLinkPlayerId; // This is our player id in a multiplayer mode.
u8 gFieldLinkPlayerCount;

EWRAM_DATA static u8 sObjectEventLoadFlag = 0;
EWRAM_DATA struct WarpData gLastUsedWarp = {0};
EWRAM_DATA static struct WarpData sWarpDestination = {0};  // new warp position
EWRAM_DATA static struct WarpData sFixedDiveWarp = {0};
EWRAM_DATA static struct WarpData sFixedHoleWarp = {0};
EWRAM_DATA static u16 sLastMapSectionId = 0;
EWRAM_DATA static struct InitialPlayerAvatarState sInitialPlayerAvatarState = {0};
EWRAM_DATA static u16 sAmbientCrySpecies = 0;
EWRAM_DATA static bool8 sIsAmbientCryWaterMon = FALSE;
EWRAM_DATA struct LinkPlayerObjectEvent gLinkPlayerObjectEvents[4] = {0};

static const u8 FollowerSparkleCoords[][6] =
{
    {15, 9, 15, 9, 11, 9}, // Bulbasaur
    {15, 11, 15, 9, 10, 9}, // Ivysaur
    {16, 13, 16, 12, 13, 13}, // Venusaur
    {16, 9, 16, 10, 11, 9}, // Charmander
    {15, 12, 15, 10, 10, 11}, // Charmeleon
    {16, 13, 16, 13, 16, 13}, // Charizard
    {15, 9, 15, 9, 7, 9}, // Squirtle
    {16, 10, 15, 9, 9, 11}, // Wartortle
    {16, 13, 16, 13, 14, 12}, // Blastoise
    {15, 10, 15, 9, 9, 10}, // Caterpie
    {16, 10, 16, 11, 8, 10}, // Metapod
    {16, 13, 16, 13, 12, 12}, // Butterfree
    {16, 10, 16, 10, 8, 9}, // Weedle
    {15, 10, 15, 10, 8, 10}, // Kakuna
    {15, 13, 15, 15, 9, 13}, // Beedrill
    {15, 8, 15, 8, 7, 8}, // Pidgey
    {15, 16, 15, 15, 11, 14}, // Pidgeotto
    {16, 17, 16, 17, 15, 16}, // Pidgeot
    {16, 11, 16, 9, 9, 8}, // Rattata
    {16, 12, 16, 9, 11, 8}, // Raticate
    {16, 8, 16, 8, 10, 8}, // Spearow
    {16, 15, 16, 16, 15, 19}, // Fearow
    {16, 10, 13, 11, 9, 10}, // Ekans
    {15, 12, 14, 13, 13, 12}, // Arbok
    {16, 10, 16, 9, 8, 10}, // Pikachu
    {13, 12, 20, 12, 14, 11}, // Raichu
    {16, 9, 16, 9, 9, 9}, // Sandshrew
    {15, 11, 15, 11, 10, 11}, // Sandslash
    {16, 9, 16, 9, 7, 9}, // Nidoran_F
    {15, 10, 15, 10, 11, 10}, // Nidorina
    {16, 12, 16, 12, 13, 12}, // Nidoqueen
    {16, 9, 16, 9, 8, 8}, // Nidoran_M
    {16, 10, 16, 11, 11, 9}, // Nidorino
    {16, 12, 16, 12, 14, 12}, // Nidoking
    {15, 9, 16, 9, 7, 9}, // Clefairy
    {16, 11, 16, 11, 9, 11}, // Clefable
    {15, 11, 15, 11, 12, 9}, // Vulpix
    {15, 13, 15, 14, 13, 11}, // Ninetales
    {15, 9, 15, 9, 7, 9}, // Jigglypuff
    {15, 11, 15, 11, 8, 11}, // Wigglytuff
    {15, 12, 15, 13, 10, 11}, // Zubat
    {16, 12, 16, 12, 12, 12}, // Golbat
    {15, 8, 15, 8, 7, 8}, // Oddish
    {16, 10, 16, 10, 9, 11}, // Gloom
    {16, 10, 16, 10, 11, 10}, // Vileplume
    {16, 9, 16, 8, 9, 9}, // Paras
    {15, 13, 16, 12, 12, 12}, // Parasect
    {16, 10, 16, 10, 11, 10}, // Venonat
    {15, 14, 15, 14, 13, 14}, // Venomoth
    {15, 7, 16, 7, 7, 7}, // Diglett
    {16, 11, 16, 11, 11, 11}, // Dugtrio
    {16, 13, 15, 11, 11, 9}, // Meowth
    {15, 14, 15, 12, 13, 9}, // Persian
    {15, 10, 15, 10, 7, 10}, // Psyduck
    {15, 12, 15, 12, 8, 11}, // Golduck
    {15, 9, 15, 9, 9, 9}, // Mankey
    {15, 11, 15, 11, 9, 12}, // Primeape
    {16, 11, 16, 11, 9, 10}, // Growlithe
    {15, 15, 15, 15, 16, 12}, // Arcanine
    {16, 9, 16, 9, 9, 9}, // Poliwag
    {16, 9, 16, 9, 7, 10}, // Poliwhirl
    {15, 11, 15, 11, 10, 11}, // Poliwrath
    {15, 11, 15, 11, 11, 12}, // Abra
    {15, 11, 16, 11, 12, 11}, // Kadabra
    {16, 12, 16, 13, 11, 13}, // Alakazam
    {15, 9, 15, 9, 8, 10}, // Machop
    {15, 12, 15, 12, 8, 12}, // Machoke
    {16, 13, 16, 13, 12, 12}, // Machamp
    {15, 11, 15, 11, 7, 10}, // Bellsprout
    {15, 11, 15, 10, 7, 11}, // Weepinbell
    {15, 14, 15, 14, 14, 13}, // Victreebel
    {16, 10, 16, 10, 9, 10}, // Tentacool
    {15, 13, 15, 13, 13, 12}, // Tentacruel
    {15, 10, 15, 10, 7, 11}, // Geodude
    {15, 9, 15, 9, 10, 11}, // Graveler
    {15, 11, 15, 11, 12, 11}, // Golem
    {15, 12, 15, 12, 11, 11}, // Ponyta
    {15, 15, 15, 14, 15, 13}, // Rapidash
    {15, 11, 15, 9, 12, 8}, // Slowpoke
    {16, 11, 16, 11, 14, 11}, // Slowbro
    {15, 10, 15, 10, 8, 11}, // Magnemite
    {15, 15, 15, 15, 10, 15}, // Magneton
    {16, 11, 16, 11, 8, 11}, // Farfetch'd
    {15, 11, 15, 11, 9, 12}, // Doduo
    {16, 16, 15, 16, 15, 15}, // Dodrio
    {15, 11, 15, 11, 13, 10}, // Seel
    {15, 13, 15, 12, 15, 12}, // Dewgong
    {16, 9, 16, 9, 9, 10}, // Grimer
    {15, 11, 15, 11, 11, 11}, // Muk
    {15, 9, 15, 8, 7, 9}, // Shellder
    {15, 13, 15, 13, 13, 14}, // Cloyster
    {15, 15, 16, 15, 10, 14}, // Gastly
    {16, 13, 16, 13, 10, 14}, // Haunter
    {15, 11, 15, 11, 9, 11}, // Gengar
    {16, 15, 15, 16, 13, 16}, // Onix
    {16, 10, 16, 10, 10, 11}, // Drowzee
    {16, 12, 16, 12, 10, 12}, // Hypno
    {16, 9, 16, 9, 13, 7}, // Krabby
    {16, 13, 16, 12, 16, 13}, // Kingler
    {15, 9, 15, 9, 7, 9}, // Voltorb
    {16, 12, 16, 12, 13, 12}, // Electrode
    {16, 13, 16, 11, 14, 12}, // Exeggcute
    {16, 15, 16, 14, 12, 14}, // Exeggutor
    {14, 10, 16, 10, 9, 11}, // Cubone
    {14, 11, 16, 11, 10, 12}, // Marowak
    {15, 11, 15, 11, 9, 11}, // Hitmonlee
    {16, 12, 16, 11, 9, 11}, // Hitmonchan
    {15, 11, 15, 11, 12, 10}, // Lickitung
    {17, 13, 17, 13, 12, 12}, // Koffing
    {15, 14, 16, 14, 13, 13}, // Weezing
    {15, 12, 15, 11, 14, 9}, // Rhyhorn
    {16, 12, 16, 12, 16, 12}, // Rhydon
    {15, 10, 15, 10, 10, 10}, // Chansey
    {16, 11, 16, 11, 10, 10}, // Tangela
    {16, 12, 16, 12, 12, 13}, // Kangaskhan
    {15, 9, 15, 9, 9, 9}, // Horsea
    {15, 13, 15, 13, 11, 12}, // Seadra
    {15, 11, 15, 10, 12, 9}, // Goldeen
    {15, 13, 15, 11, 14, 13}, // Seaking
    {16, 10, 16, 10, 8, 10}, // Staryu
    {16, 12, 16, 12, 9, 13}, // Starmie
    {16, 11, 16, 10, 10, 12}, // Mr. Mime
    {15, 13, 15, 13, 12, 13}, // Scyther
    {16, 13, 16, 12, 11, 13}, // Jynx
    {16, 12, 16, 12, 12, 12}, // Electabuzz
    {15, 13, 15, 13, 12, 12}, // Magmar
    {15, 12, 15, 12, 11, 12}, // Pinsir
    {15, 15, 16, 12, 15, 11}, // Tauros
    {16, 10, 16, 11, 12, 10}, // Magikarp
    {16, 16, 16, 16, 15, 16}, // Gyarados
    {16, 12, 16, 13, 14, 13}, // Lapras
    {16, 8, 16, 8, 9, 7}, // Ditto
    {15, 9, 15, 9, 11, 9}, // Eevee
    {15, 15, 15, 12, 15, 11}, // Vaporeon
    {15, 12, 15, 11, 14, 10}, // Jolteon
    {15, 13, 15, 12, 14, 11}, // Flareon
    {15, 10, 15, 10, 12, 9}, // Porygon
    {15, 10, 15, 10, 10, 9}, // Omanyte
    {15, 12, 15, 12, 12, 11}, // Omastar
    {15, 8, 15, 8, 9, 8}, // Kabuto
    {16, 11, 15, 11, 11, 12}, // Kabutops
    {15, 16, 15, 16, 16, 15}, // Aerodactyl
    {16, 14, 16, 14, 12, 15}, // Snorlax
    {15, 17, 15, 16, 14, 17}, // Articuno
    {15, 18, 15, 17, 14, 15}, // Zapdos
    {15, 16, 15, 17, 15, 17}, // Moltres
    {17, 12, 14, 11, 12, 11}, // Dratini
    {18, 15, 14, 15, 14, 14}, // Dragonair
    {15, 16, 15, 16, 13, 15}, // Dragonite
    {15, 15, 15, 14, 13, 14}, // Mewtwo
    {16, 13, 16, 11, 13, 13}, // Mew
    {16, 10, 15, 10, 9, 10}, // Chikorita
    {16, 13, 15, 14, 13, 13}, // Bayleef
    {15, 14, 15, 15, 14, 15}, // Meganium
    {16, 11, 16, 10, 12, 9}, // Cyndaquil
    {15, 13, 15, 14, 15, 10}, // Quilava
    {15, 14, 15, 14, 14, 13}, // Typhlosion
    {16, 10, 16, 10, 10, 10}, // Totodile
    {15, 13, 15, 14, 13, 13}, // Croconaw
    {15, 15, 15, 15, 15, 15}, // Feraligatr
    {15, 10, 15, 10, 12, 9}, // Sentret
    {15, 14, 15, 13, 15, 11}, // Furret
    {16, 10, 16, 10, 10, 10}, // Hoothoot
    {15, 13, 15, 14, 14, 16}, // Noctowl
    {15, 14, 15, 12, 13, 12}, // Ledyba
    {16, 12, 16, 13, 13, 16}, // Ledian
    {15, 9, 15, 9, 11, 7}, // Spinarak
    {15, 13, 15, 12, 15, 13}, // Ariados
    {15, 13, 15, 13, 12, 15}, // Crobat
    {16, 8, 16, 8, 10, 8}, // Chinchou
    {16, 14, 16, 13, 15, 11}, // Lanturn
    {15, 9, 15, 9, 9, 9}, // Pichu
    {16, 8, 16, 8, 9, 8}, // Cleffa
    {15, 9, 15, 9, 8, 9}, // Igglybuff
    {16, 9, 16, 9, 9, 9}, // Togepi
    {15, 14, 15, 15, 10, 13}, // Togetic
    {16, 8, 16, 8, 9, 9}, // Natu
    {16, 12, 16, 12, 12, 12}, // Xatu
    {16, 11, 15, 10, 12, 10}, // Mareep
    {18, 12, 15, 11, 12, 11}, // Flaaffy
    {16, 13, 16, 13, 13, 13}, // Ampharos
    {15, 10, 15, 10, 8, 10}, // Bellossom
    {19, 8, 12, 8, 12, 9}, // Marill
    {18, 10, 13, 10, 12, 11}, // Azumarill
    {16, 12, 16, 12, 10, 12}, // Sudowoodo
    {15, 12, 15, 12, 9, 12}, // Politoed
    {16, 12, 16, 12, 9, 12}, // Hoppip
    {15, 10, 15, 10, 9, 13}, // Skiploom
    {16, 14, 16, 14, 9, 13}, // Jumpluff
    {16, 12, 16, 11, 13, 11}, // Aipom
    {16, 8, 16, 8, 7, 9}, // Sunkern
    {15, 11, 15, 11, 7, 11}, // Sunflora
    {16, 15, 16, 15, 15, 13}, // Yanma
    {16, 8, 16, 8, 8, 8}, // Wooper
    {17, 11, 15, 11, 12, 11}, // Quagsire
    {15, 14, 15, 12, 13, 12}, // Espeon
    {15, 13, 15, 12, 14, 11}, // Umbreon
    {15, 10, 15, 10, 9, 10}, // Murkrow
    {16, 14, 16, 14, 10, 13}, // Slowking
    {16, 14, 16, 13, 11, 13}, // Misdreavus
    {15, 10, 15, 10, 7, 11}, // Unown (A)
    {16, 11, 16, 11, 10, 11}, // Wobbuffet
    {16, 13, 16, 13, 15, 13}, // Girafarig
    {16, 9, 16, 9, 8, 9}, // Pineco
    {16, 10, 16, 10, 11, 10}, // Forretress
    {15, 13, 15, 9, 13, 8}, // Dunsparce
    {15, 12, 15, 12, 11, 13}, // Gligar
    {33, 17, 32, 19, 36, 17}, // Steelix
    {16, 10, 16, 10, 10, 10}, // Snubbull
    {16, 12, 16, 12, 10, 13}, // Granbull
    {16, 12, 16, 10, 14, 9}, // Qwilfish
    {16, 13, 16, 12, 12, 13}, // Scizor
    {16, 10, 16, 11, 11, 10}, // Shuckle
    {15, 13, 15, 13, 12, 14}, // Heracross
    {17, 10, 15, 10, 9, 10}, // Sneasel
    {15, 10, 15, 10, 9, 10}, // Teddiursa
    {16, 13, 16, 13, 11, 14}, // Ursaring
    {15, 11, 16, 11, 11, 10}, // Slugma
    {16, 13, 14, 12, 15, 11}, // Magcargo
    {15, 8, 15, 8, 11, 8}, // Swinub
    {15, 11, 15, 12, 12, 11}, // Piloswine
    {16, 9, 16, 9, 10, 10}, // Corsola
    {16, 10, 16, 10, 13, 7}, // Remoraid
    {15, 11, 15, 12, 11, 11}, // Ocitllery
    {16, 10, 15, 10, 9, 11}, // Delibird
    {16, 15, 16, 15, 16, 16}, // Mantine
    {15, 13, 15, 16, 15, 16}, // Skarmory
    {16, 9, 16, 10, 11, 10}, // Houndour
    {15, 12, 15, 13, 14, 12}, // Houndoom
    {16, 14, 16, 14, 14, 13}, // Kingdra
    {16, 9, 16, 9, 11, 9}, // Phanpy
    {16, 11, 16, 11, 15, 12}, // Donphan
    {16, 11, 16, 12, 13, 12}, // Porygon2
    {16, 14, 15, 14, 12, 15}, // Stantler
    {14, 11, 18, 11, 9, 11}, // Smeargle
    {15, 10, 15, 10, 8, 10}, // Tyrogue
    {15, 12, 15, 12, 9, 11}, // Hitmontop
    {15, 10, 15, 10, 9, 10}, // Smoochum
    {15, 10, 15, 10, 8, 10}, // Elekid
    {16, 10, 16, 10, 8, 10}, // Magby
    {16, 11, 16, 11, 12, 11}, // Miltank
    {16, 11, 16, 11, 11, 12}, // Blissey
    {15, 15, 15, 13, 15, 13}, // Raikou
    {15, 15, 15, 13, 15, 12}, // Entei 
    {15, 15, 15, 13, 16, 12}, // Suicune
    {15, 10, 15, 10, 10, 10}, // Larvitar
    {15, 11, 15, 11, 8, 11}, // Pupitar
    {15, 14, 15, 14, 14, 13}, // Tyranitar
    {32, 21, 32, 23, 40, 21}, // Lugia
    {32, 22, 31, 22, 38, 24}, // Ho-oh
    {16, 14, 16, 14, 9, 14}, // Celebi
    {15, 9, 15, 9, 9, 9}, // Treecko
    {16, 11, 16, 11, 11, 11}, // Grovyle
    {15, 13, 15, 13, 15, 14}, // Sceptile
    {15, 10, 15, 10, 8, 10}, // Torchic
    {15, 11, 15, 11, 8, 11}, // Combusken
    {16, 13, 16, 13, 12, 13}, // Blaziken
    {15, 9, 15, 9, 10, 9}, // Mudkip
    {15, 10, 15, 10, 9, 10}, // Marshtomp
    {15, 13, 15, 13, 15, 13}, // Swampert
    {15, 10, 15, 10, 12, 10}, // Poochyena
    {16, 14, 16, 12, 15, 12}, // Mightyena
    {16, 12, 16, 10, 14, 9}, // Zigzagoon
    {16, 13, 14, 10, 15, 8}, // Linoone
    {15, 10, 15, 11, 11, 9}, // Wurmple
    {16, 8, 16, 8, 10, 8}, // Silcoon
    {16, 13, 16, 13, 13, 12}, // Beautifly
    {16, 8, 16, 8, 10, 8}, // Cascoon
    {15, 11, 15, 11, 12, 15}, // Dustox
    {15, 9, 15, 9, 10, 9}, // Lotad
    {15, 12, 15, 12, 10, 11}, // Lombre
    {16, 14, 16, 14, 13, 14}, // Ludicolo
    {15, 9, 15, 9, 8, 9}, // Seedot
    {15, 12, 15, 12, 9, 12}, // Nuzleaf
    {16, 12, 16, 12, 13, 12}, // Shiftry
#ifndef POKEMON_EXPANSION
    {15, 9, 15, 8, 12, 8}, // Nincada
    {15, 12, 15, 12, 12, 12}, // Ninjask
    {16, 13, 16, 14, 12, 13}, // Shedinja
    {15, 9, 15, 9, 10, 8}, // Taillow
    {15, 13, 15, 12, 16, 15}, // Swellow
    {15, 9, 15, 9, 10, 9}, // Shroomish
    {16, 12, 16, 12, 12, 12}, // Breloom
    {16, 10, 16, 10, 9, 11}, // Spinda
    {15, 11, 15, 10, 12, 13}, // Wingull
    {16, 14, 16, 14, 14, 13}, // Pelipper
    {15, 9, 15, 9, 10, 9}, // Surskit
    {16, 14, 16, 15, 10, 14}, // Masquerain
    {16, 11, 16, 11, 13, 11}, // Wailmer
    {32, 19, 32, 18, 38, 12}, // Wailord
    {15, 10, 15, 9, 12, 9}, // Skitty
    {16, 13, 16, 12, 13, 12}, // Delcatty
    {16, 11, 16, 11, 10, 11}, // Kecleon
    {16, 11, 16, 11, 7, 11}, // Baltoy
    {16, 14, 16, 14, 11, 13}, // Claydol
    {15, 11, 15, 11, 11, 11}, // Nosepass
    {16, 10, 16, 11, 15, 10}, // Torkoal
    {16, 9, 16, 9, 9, 10}, // Sableye
    {15, 9, 16, 9, 9, 11}, // Barboach
    {15, 10, 15, 11, 14, 9}, // Whiscash
    {16, 9, 16, 9, 8, 9}, // Luvdisc
    {15, 10, 15, 11, 11, 10}, // Corphish
    {16, 13, 16, 13, 13, 12}, // Crawdaunt
    {16, 9, 16, 9, 10, 9}, // Feebas
    {19, 13, 11, 12, 14, 13}, // Milotic
    {15, 12, 15, 12, 11, 11}, // Carvanha
    {16, 14, 16, 12, 13, 14}, // Sharpedo
    {16, 8, 16, 8, 10, 8}, // Trapinch
    {16, 13, 16, 11, 15, 14}, // Vibrava
    {16, 17, 16, 17, 15, 14}, // Flygon
    {16, 10, 16, 10, 9, 11}, // Makuhita
    {14, 14, 14, 13, 14, 13}, // Hariyama
    {15, 11, 15, 9, 13, 8}, // Electrike
    {15, 13, 15, 13, 14, 13}, // Manectric
    {15, 12, 15, 12, 15, 12}, // Numel
    {15, 14, 15, 14, 17, 12}, // Camerupt
    {15, 9, 15, 9, 11, 9}, // Spheal
    {15, 12, 15, 13, 15, 12}, // Sealeo
    {15, 13, 15, 14, 16, 14}, // Walrein
    {15, 9, 15, 9, 8, 9}, // Cacnea
    {15, 12, 15, 12, 11, 12}, // Cacturne
    {15, 9, 15, 9, 9, 9}, // Snorunt
    {16, 12, 16, 12, 11, 14}, // Glalie
    {16, 11, 16, 11, 10, 11}, // Lunatone
    {16, 13, 16, 13, 8, 13}, // Solrock
    {17, 9, 14, 8, 13, 7}, // Azurill
    {15, 11, 15, 11, 8, 10}, // Spoink
    {15, 11, 15, 11, 11, 11}, // Grumpig
    {15, 9, 15, 9, 9, 9}, // Plusle
    {15, 9, 15, 9, 9, 9}, // Minun
    {17, 11, 14, 11, 13, 11}, // Mawile
    {15, 12, 15, 11, 8, 11}, // Meditite
    {15, 13, 15, 13, 8, 13}, // Medicham
    {16, 12, 16, 11, 11, 10}, // Swablu
    {16, 16, 16, 16, 14, 15}, // Altaria
    {16, 10, 16, 10, 10, 9}, // Wynaut
    {16, 12, 16, 11, 9, 12}, // Duskull
    {15, 13, 15, 13, 13, 13}, // Dusclops
    {15, 10, 15, 10, 8, 10}, // Roselia
    {15, 9, 15, 9, 12, 8}, // Slakoth
    {16, 11, 16, 11, 14, 11}, // Vigoroth
    {16, 15, 16, 14, 14, 14}, // Slaking
    {16, 9, 16, 9, 10, 9}, // Gulpin
    {16, 14, 16, 14, 14, 14}, // Swalot
    {16, 13, 16, 13, 16, 13}, // Tropius
    {16, 8, 16, 8, 8, 8}, // Whismur
    {16, 11, 16, 11, 9, 12}, // Loudred
    {16, 14, 16, 14, 17, 15}, // Exploud
    {15, 8, 15, 8, 8, 9}, // Clamperl
    {18, 15, 11, 14, 14, 14}, // Huntail
    {17, 16, 12, 14, 15, 11}, // Gorebyss
    {14, 14, 16, 14, 15, 13}, // Absol
    {15, 11, 15, 11, 8, 11}, // Shuppet
    {17, 10, 16, 10, 9, 10}, // Banette
    {18, 14, 14, 14, 16, 10}, // Seviper
    {15, 12, 15, 12, 13, 12}, // Zangoose
    {15, 13, 15, 12, 14, 10}, // Relicanth
    {16, 8, 16, 8, 9, 8}, // Aron
    {15, 13, 15, 12, 16, 10}, // Lairon
    {15, 15, 15, 14, 16, 14}, // Aggron
    {15, 11, 15, 10, 7, 10}, // Castform
    {15, 14, 15, 14, 12, 12}, // Volbeat
    {16, 13, 16, 13, 11, 12}, // Illumise
    {16, 11, 16, 12, 10, 11}, // Lileep
    {16, 15, 16, 15, 12, 15}, // Cradily
    {16, 11, 16, 10, 14, 9}, // Anorith
    {15, 13, 15, 12, 13, 13}, // Armaldo
    {15, 9, 15, 9, 9, 9}, // Ralts
    {15, 11, 15, 11, 9, 11}, // Kirlia
    {16, 12, 16, 13, 10, 12}, // Gardevoir
    {16, 11, 16, 11, 10, 10}, // Bagon
    {16, 10, 16, 10, 11, 10}, // Shelgon
    {16, 14, 16, 13, 16, 13}, // Salamence
    {15, 13, 15, 12, 12, 12}, // Beldum
    {16, 14, 16, 13, 15, 13}, // Metang
    {16, 14, 16, 14, 13, 13}, // Metagross
    {15, 14, 15, 14, 11, 14}, // Regirock
    {15, 13, 15, 13, 12, 13}, // Regice
    {16, 13, 16, 13, 10, 13}, // Registeel
    {16, 17, 16, 15, 16, 14}, // Kyogre
    {15, 16, 16, 16, 16, 16}, // Groudon
    {16, 17, 16, 16, 16, 16}, // Rayquaza
    {16, 15, 16, 14, 16, 15}, // Latias
    {16, 15, 16, 14, 15, 15}, // Latios
    {15, 13, 15, 13, 10, 12}, // Jirachi
    {16, 14, 16, 14, 9, 13}, // Deoxys (Normal)
    {16, 11, 16, 11, 7, 11}, // Chimecho
#else
    {15, 9, 15, 9, 10, 8}, // Taillow
    {15, 13, 15, 12, 16, 15}, // Swellow
    {15, 11, 15, 10, 12, 13}, // Wingull
    {16, 14, 16, 14, 14, 13}, // Pelipper
    {9, 15, 9, 9, 9}, // Ralts
    {15, 11, 15, 11, 9, 11}, // Kirlia
    {16, 12, 16, 13, 10, 12}, // Gardevoir
    {15, 9, 15, 9, 10, 9}, // Surskit
    {16, 14, 16, 15, 10, 14}, // Masquerain
    {15, 9, 15, 9, 10, 9}, // Shroomish
    {16, 12, 16, 12, 12, 12}, // Breloom
    {15, 9, 15, 9, 12, 8}, // Slakoth
    {16, 11, 16, 11, 14, 11}, // Vigoroth
    {16, 15, 16, 14, 14, 14}, // Slaking
    {15, 9, 15, 8, 12, 8}, // Nincada
    {15, 12, 15, 12, 12, 12}, // Ninjask
    {16, 13, 16, 14, 12, 13}, // Shedinja
    {16, 8, 16, 8, 8, 8}, // Whismur
    {16, 11, 16, 11, 9, 12}, // Loudred
    {16, 14, 16, 14, 17, 15}, // Exploud
    {16, 10, 16, 10, 9, 11}, // Makuhita
    {14, 14, 14, 13, 14, 13}, // Hariyama
    {17, 9, 14, 8, 13, 7}, // Azurill
    {15, 11, 15, 11, 11, 11}, // Nosepass
    {15, 10, 15, 9, 12, 9}, // Skitty
    {16, 13, 16, 12, 13, 12}, // Delcatty
    {16, 9, 16, 9, 9, 10}, // Sableye
    {17, 11, 14, 11, 13, 11}, // Mawile
    {16, 8, 16, 8, 9, 8}, // Aron
    {15, 13, 15, 12, 16, 10}, // Lairon
    {15, 15, 15, 14, 16, 14}, // Aggron
    {15, 12, 15, 11, 8, 11}, // Meditite
    {15, 13, 15, 13, 8, 13}, // Medicham
    {15, 11, 15, 9, 13, 8}, // Electrike
    {15, 13, 15, 13, 14, 13}, // Manectric
    {15, 9, 15, 9, 9, 9}, // Plusle
    {15, 9, 15, 9, 9, 9}, // Minun
    {15, 14, 15, 14, 12, 12}, // Volbeat
    {16, 13, 16, 13, 11, 12}, // Illumise
    {15, 10, 15, 10, 8, 10}, // Roselia
    {16, 9, 16, 9, 10, 9}, // Gulpin
    {16, 14, 16, 14, 14, 14}, // Swalot
    {15, 12, 15, 12, 11, 11}, // Carvanha
    {16, 14, 16, 12, 13, 14}, // Sharpedo
    {16, 11, 16, 11, 13, 11}, // Wailmer
    {32, 19, 32, 18, 38, 12}, // Wailord
    {15, 12, 15, 12, 15, 12}, // Numel
    {15, 14, 15, 14, 17, 12}, // Camerupt
    {16, 10, 16, 11, 15, 10}, // Torkoal
    {15, 11, 15, 11, 8, 10}, // Spoink
    {15, 11, 15, 11, 11, 11}, // Grumpig
    {16, 10, 16, 10, 9, 11}, // Spinda
    {16, 8, 16, 8, 10, 8}, // Trapinch
    {16, 13, 16, 11, 15, 14}, // Vibrava
    {16, 17, 16, 17, 15, 14}, // Flygon
    {15, 9, 15, 9, 8, 9}, // Cacnea
    {15, 12, 15, 12, 11, 12}, // Cacturne
    {16, 12, 16, 11, 11, 10}, // Swablu
    {16, 16, 16, 16, 14, 15}, // Altaria
    {15, 12, 15, 12, 13, 12}, // Zangoose
    {18, 14, 14, 14, 16, 10}, // Seviper
    {16, 11, 16, 11, 10, 11}, // Lunatone
    {16, 13, 16, 13, 8, 13}, // Solrock
    {15, 9, 16, 9, 9, 11}, // Barboach
    {15, 10, 15, 11, 14, 9}, // Whiscash
    {15, 10, 15, 11, 11, 10}, // Corphish
    {16, 13, 16, 13, 13, 12}, // Crawdaunt
    {16, 11, 16, 11, 7, 11}, // Baltoy
    {16, 14, 16, 14, 11, 13}, // Claydol
    {16, 11, 16, 12, 10, 11}, // Lileep
    {16, 15, 16, 15, 12, 15}, // Cradily
    {16, 11, 16, 10, 14, 9}, // Anorith
    {15, 13, 15, 12, 13, 13}, // Armaldo
    {16, 9, 16, 9, 10, 9}, // Feebas
    {19, 13, 11, 12, 14, 13}, // Milotic
    {15, 11, 15, 10, 7, 10}, // Castform
    {16, 11, 16, 11, 10, 11}, // Kecleon
    {15, 11, 15, 11, 8, 11}, // Shuppet
    {17, 10, 16, 10, 9, 10}, // Banette
    {16, 12, 16, 11, 9, 12}, // Duskull
    {15, 13, 15, 13, 13, 13}, // Dusclops
    {16, 13, 16, 13, 16, 13}, // Tropius
    {16, 11, 16, 11, 7, 11}, // Chimecho
    {14, 14, 16, 14, 15, 13}, // Absol
    {16, 10, 16, 10, 10, 9}, // Wynaut
    {15, 9, 15, 9, 9, 9}, // Snorunt
    {16, 12, 16, 12, 11, 14}, // Glalie
    {15, 9, 15, 9, 11, 9}, // Spheal
    {15, 12, 15, 13, 15, 12}, // Sealeo
    {15, 13, 15, 14, 16, 14}, // Walrein
    {15, 8, 15, 8, 8, 9}, // Clamperl
    {18, 15, 11, 14, 14, 14}, // Huntail
    {17, 16, 12, 14, 15, 11}, // Gorebyss
    {15, 13, 15, 12, 14, 10}, // Relicanth
    {16, 9, 16, 9, 8, 9}, // Luvdisc
    {16, 11, 16, 11, 10, 10}, // Bagon
    {16, 10, 16, 10, 11, 10}, // Shelgon
    {16, 14, 16, 13, 16, 13}, // Salamence
    {15, 13, 15, 12, 12, 12}, // Beldum
    {16, 14, 16, 13, 15, 13}, // Metang
    {16, 14, 16, 14, 13, 13}, // Metagross
    {15, 14, 15, 14, 11, 14}, // Regirock
    {15, 13, 15, 13, 12, 13}, // Regice
    {16, 13, 16, 13, 10, 13}, // Registeel
    {16, 15, 16, 14, 16, 15}, // Latias
    {16, 15, 16, 14, 15, 15}, // Latios
    {16, 17, 16, 15, 16, 14}, // Kyogre
    {15, 16, 16, 16, 16, 16}, // Groudon
    {16, 17, 16, 16, 16, 16}, // Rayquaza
    {15, 13, 15, 13, 10, 12}, // Jirachi
    {16, 14, 16, 14, 9, 13}, // Deoxys (Normal)
#endif
    {15, 10, 15, 10, 10, 10}, // Turtwig
    {15, 10, 15, 10, 13, 10}, // Grotle
    {16, 13, 16, 13, 15, 12}, // Torterra
    {15, 11, 15, 11, 9, 11}, // Chimchar
    {15, 12, 15, 12, 12, 12}, // Monferno
    {16, 16, 16, 15, 12, 15}, // Infernape
    {15, 9, 15, 9, 8, 9}, // Piplup
    {15, 11, 15, 11, 9, 12}, // Prinplup
    {15, 14, 15, 14, 11, 14}, // Empoleon
    {15, 10, 15, 10, 10, 9}, // Starly
    {15, 16, 15, 16, 14, 14}, // Staravia
    {15, 15, 15, 15, 14, 15}, // Staraptor
    {15, 9, 15, 9, 12, 8}, // Bidoof
    {15, 13, 15, 11, 17, 10}, // Bibarel
    {16, 9, 16, 9, 9, 10}, // Kricketot
    {15, 13, 15, 13, 11, 13}, // Kricketune
    {15, 11, 15, 9, 12, 8}, // Shinx
    {15, 13, 15, 11, 14, 11}, // Luxio
    {15, 16, 15, 13, 14, 12}, // Luxray
    {15, 9, 15, 9, 7, 9}, // Budew
    {16, 12, 16, 12, 10, 12}, // Roserade
    {16, 10, 16, 10, 8, 10}, // Cranidos
    {15, 14, 15, 14, 15, 14}, // Rampardos
    {15, 9, 15, 9, 10, 9}, // Shieldon
    {16, 12, 16, 12, 14, 12}, // Bastiodon
    {16, 10, 16, 10, 9, 10}, // Burmy
    {15, 13, 15, 13, 9, 13}, // Wormadam
    {15, 14, 15, 14, 12, 12}, // Mothim
    {16, 9, 16, 9, 7, 9}, // Combee
    {16, 15, 16, 13, 11, 14}, // Vespiquen
    {15, 10, 15, 9, 11, 9}, // Pachirisu
    {16, 11, 16, 10, 15, 8}, // Buizel
    {15, 14, 15, 14, 13, 14}, // Floatzel
    {16, 9, 15, 9, 8, 10}, // Cherubi
    {15, 10, 15, 10, 7, 10}, // Cherrim
    {15, 10, 15, 9, 10, 9}, // Shellos (East)
    {15, 12, 15, 13, 15, 12}, // Gastrodon (East)
    {16, 15, 16, 13, 13, 14}, // Ambipom
    {15, 12, 15, 12, 7, 12}, // Drifloon
    {16, 14, 16, 14, 10, 14}, // Drifblim
    {16, 10, 15, 10, 8, 11}, // Buneary
    {15, 13, 15, 13, 10, 13}, // Lopunny
    {15, 17, 15, 17, 13, 17}, // Mismagius
    {15, 11, 15, 11, 13, 11}, // Honchkrow
    {16, 13, 16, 9, 11, 9}, // Glameow
    {15, 12, 15, 11, 12, 11}, // Purugly
    {15, 10, 15, 9, 8, 10}, // Chingling
    {15, 11, 15, 9, 12, 8}, // Stunky
    {15, 12, 15, 12, 14, 10}, // Skuntank
    {16, 10, 16, 10, 7, 10}, // Bronzor
    {15, 14, 15, 14, 9, 14}, // Bronzong
    {16, 10, 16, 10, 8, 10}, // Bonsly
    {16, 11, 16, 11, 8, 11}, // Mime Jr.
    {15, 11, 15, 10, 9, 11}, // Happiny
    {15, 10, 15, 11, 11, 11}, // Chatot
    {14, 12, 15, 12, 8, 13}, // Spiritomb
    {15, 11, 15, 10, 10, 10}, // Gible
    {16, 12, 16, 12, 12, 12}, // Gabite
    {15, 15, 15, 14, 15, 16}, // Garchomp
    {15, 10, 15, 10, 8, 11}, // Munchlax
    {16, 11, 16, 11, 9, 11}, // Riolu
    {16, 13, 16, 13, 11, 14}, // Lucario
    {15, 11, 15, 10, 12, 9}, // Hippopotas
    {15, 12, 15, 11, 17, 10}, // Hippowdon
    {15, 11, 15, 9, 12, 9}, // Skorupi
    {15, 14, 15, 11, 15, 11}, // Drapion
    {16, 9, 16, 9, 8, 9}, // Croagunk
    {15, 11, 15, 11, 9, 11}, // Toxicroak
    {15, 14, 16, 13, 10, 14}, // Carnivine
    {15, 10, 15, 9, 11, 8}, // Finneon
    {16, 10, 16, 10, 12, 10}, // Lumineon
    {15, 8, 16, 10, 11, 9}, // Mantyke
    {16, 11, 16, 10, 10, 11}, // Snover
    {15, 14, 15, 13, 13, 13}, // Abomasnow
    {15, 11, 15, 11, 9, 11}, // Weavile
    {15, 14, 15, 14, 14, 13}, // Magnezone
    {15, 12, 16, 12, 13, 12}, // Lickilicky
    {16, 12, 16, 12, 15, 12}, // Rhyperior
    {16, 13, 16, 13, 12, 13}, // Tangrowth
    {16, 13, 16, 13, 14, 13}, // Electivire
    {15, 14, 15, 15, 12, 15}, // Magmortar
    {15, 14, 15, 12, 12, 10}, // Togekiss
    {16, 14, 16, 14, 16, 15}, // Yanmega
    {15, 13, 15, 11, 14, 11}, // Leafeon
    {15, 12, 15, 11, 13, 11}, // Glaceon
    {15, 13, 15, 13, 11, 13}, // Gliscor
    {15, 13, 15, 13, 16, 13}, // Mamoswine
    {15, 15, 15, 15, 10, 14}, // Porygon-Z
    {16, 14, 16, 14, 9, 14}, // Gallade
    {15, 15, 15, 15, 14, 15}, // Probopass
    {15, 15, 15, 15, 11, 15}, // Dusknoir
    {16, 14, 16, 14, 9, 14}, // Froslass
    {16, 12, 16, 12, 11, 12}, // Rotom
    {15, 12, 15, 11, 13, 12}, // Uxie
    {15, 12, 15, 11, 13, 11}, // Mesprit
    {15, 13, 15, 12, 13, 11}, // Azelf
    {31, 20, 31, 20, 37, 21}, // Dialga
    {31, 20, 31, 20, 41, 18}, // Palkia
    {15, 12, 15, 12, 15, 12}, // Heatran
    {32, 19, 32, 19, 30, 19}, // Regigigas
    {31, 20, 31, 20, 37, 20}, // Giratina
    {15, 15, 15, 15, 13, 15}, // Cresselia
    {15, 11, 15, 10, 12, 10}, // Phione
    {16, 11, 14, 10, 11, 11}, // Manaphy
    {15, 15, 15, 15, 13, 16}, // Darkrai
    {15, 8, 15, 8, 10, 8}, // Shaymin (Land)
    {32, 20, 32, 20, 32, 19}, // Arceus

    {16, 15, 16, 15, 12, 13}, // Deoxys (Speed)
    {16, 13, 16, 13, 10, 13}, // Deoxys (Defense)
    {16, 14, 16, 14, 10, 14}, // Deoxys (Attack)
    {16, 10, 16, 10, 9, 10}, // Burmy (Sand)
    {16, 10, 16, 10, 9, 10}, // Burmy (Trash)
    {15, 12, 15, 12, 9, 13}, // Wormadam (Sand)
    {15, 12, 15, 12, 9, 13}, // Wormadam (Trash)
    {15, 11, 15, 10, 10, 10}, // Shellos (West)
    {15, 12, 15, 13, 15, 13}, // Gastrodon (West)
    {15, 12, 15, 12, 13, 12}, // Rotom (Heat)
    {17, 12, 14, 12, 14, 12}, // Rotom (Wash)
    {15, 13, 15, 13, 12, 13}, // Rotom (Frost)
    {15, 13, 15, 13, 14, 14}, // Rotom (Fan)
    {17, 11, 14, 11, 14, 11}, // Rotom (Mow)
    {31, 20, 31, 21, 37, 20}, // Giratina (Origin)
    {16, 10, 16, 11, 10, 11}, // Shaymin (Sky)
};

static const struct WarpData sDummyWarpData =
{
    .mapGroup = MAP_GROUP(UNDEFINED),
    .mapNum = MAP_NUM(UNDEFINED),
    .warpId = WARP_ID_NONE,
    .x = -1,
    .y = -1,
};

static const u32 sUnusedData[] =
{
    1200, 3600, 1200, 2400, 50, 80, -44, 44
};

const struct UCoords32 gDirectionToVectors[] =
{
    [DIR_NONE] =
    {
        .x =  0,
        .y =  0,
    },
    [DIR_SOUTH] =
    {
        .x =  0,
        .y =  1,
    },
    [DIR_NORTH] =
    {
        .x =  0,
        .y = -1,
    },
    [DIR_WEST] =
    {
        .x = -1,
        .y =  0,
    },
    [DIR_EAST] =
    {
        .x =  1,
        .y =  0,
    },
    [DIR_SOUTHWEST] =
    {
        .x = -1,
        .y =  1,
    },
    [DIR_SOUTHEAST] =
    {
        .x =  1,
        .y =  1,
    },
    [DIR_NORTHWEST] =
    {
        .x = -1,
        .y = -1,
    },
    [DIR_NORTHEAST] =
    {
        .x =  1,
        .y = -1,
    },
};

static const struct BgTemplate sOverworldBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    },
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 29,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 0
    }
};

static const struct ScanlineEffectParams sFlashEffectParams =
{
    &REG_WIN0H,
    ((DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16) | 1,
    1,
    0,
};

static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 MovementEventModeCB_Scripted(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

static u8 (*const sLinkPlayerMovementModes[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    [MOVEMENT_MODE_FREE]     = MovementEventModeCB_Normal,
    [MOVEMENT_MODE_FROZEN]   = MovementEventModeCB_Ignored,
    [MOVEMENT_MODE_SCRIPTED] = MovementEventModeCB_Scripted,
};

static u8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);
static u8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8);

// These handlers return TRUE if the movement was scripted and successful, and FALSE otherwise.
static bool8 (*const sLinkPlayerFacingHandlers[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *, u8) =
{
    FacingHandler_DoNothing,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DpadMovement,
    FacingHandler_DoNothing,
    FacingHandler_DoNothing,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
    FacingHandler_ForcedFacingChange,
};

static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *, struct ObjectEvent *);
static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *, struct ObjectEvent *);

// These handlers are run after an attempted movement.
static void (*const sMovementStatusHandler[])(struct LinkPlayerObjectEvent *, struct ObjectEvent *) =
{
    // FALSE:
    MovementStatusHandler_EnterFreeMode,
    // TRUE:
    MovementStatusHandler_TryAdvanceScript,
};

// code
void DoWhiteOut(void)
{
    RunScriptImmediately(EventScript_WhiteOut);
    #if B_WHITEOUT_MONEY == GEN_3
    SetMoney(&gSaveBlock1Ptr->money, GetMoney(&gSaveBlock1Ptr->money) / 2);
    #endif
    HealPlayerParty();
    Overworld_ResetStateAfterWhiteOut();
    SetWarpDestinationToLastHealLocation();
    UpdateFollowerPokemonGraphic();
    WarpIntoMap();
}

void Overworld_ResetStateAfterFly(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

void Overworld_ResetStateAfterTeleport(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
    RunScriptImmediately(EventScript_ResetMrBriney);
}

void Overworld_ResetStateAfterDigEscRope(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
}

#if B_RESET_FLAGS_VARS_AFTER_WHITEOUT  == TRUE
    void Overworld_ResetBattleFlagsAndVars(void)
{
    #if VAR_TERRAIN != 0
        VarSet(VAR_TERRAIN, 0);
    #endif

    #if B_VAR_WILD_AI_FLAGS != 0
        VarSet(B_VAR_WILD_AI_FLAGS,0);
    #endif

    FlagClear(B_FLAG_INVERSE_BATTLE);
    FlagClear(B_FLAG_FORCE_DOUBLE_WILD);
    FlagClear(B_SMART_WILD_AI_FLAG);
    FlagClear(B_FLAG_NO_BAG_USE);
    FlagClear(B_FLAG_NO_CATCHING);
}
#endif

static void Overworld_ResetStateAfterWhiteOut(void)
{
    ResetInitialPlayerAvatarState();
    FlagClear(FLAG_SYS_CYCLING_ROAD);
    FlagClear(FLAG_SYS_CRUISE_MODE);
    FlagClear(FLAG_SYS_SAFARI_MODE);
    FlagClear(FLAG_SYS_USE_STRENGTH);
    FlagClear(FLAG_SYS_USE_FLASH);
#if B_RESET_FLAGS_VARS_AFTER_WHITEOUT  == TRUE
    Overworld_ResetBattleFlagsAndVars();
#endif
    // If you were defeated by Kyogre/Groudon and the step counter has
    // maxed out, end the abnormal weather.
    if (VarGet(VAR_SHOULD_END_ABNORMAL_WEATHER) == 1)
    {
        VarSet(VAR_SHOULD_END_ABNORMAL_WEATHER, 0);
        VarSet(VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_NONE);
    }
    
    FollowMe_TryRemoveFollowerOnWhiteOut();
}

static void UpdateMiscOverworldStates(void)
{
    FlagClear(FLAG_SYS_SAFARI_MODE);
    ChooseAmbientCrySpecies();
    ResetCyclingRoadChallengeData();
    UpdateLocationHistoryForRoamer();
    RoamerMoveToOtherLocationSet();
}

void ResetGameStats(void)
{
    s32 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        SetGameStat(i, 0);
}

void IncrementGameStat(u8 index)
{
    if (index < NUM_USED_GAME_STATS)
    {
        u32 statVal = GetGameStat(index);
        if (statVal < 0xFFFFFF)
            statVal++;
        else
            statVal = 0xFFFFFF;

        SetGameStat(index, statVal);
    }
}

u32 GetGameStat(u8 index)
{
    if (index >= NUM_USED_GAME_STATS)
        return 0;

    return gSaveBlock1Ptr->gameStats[index] ^ gSaveBlock2Ptr->encryptionKey;
}

void SetGameStat(u8 index, u32 value)
{
    if (index < NUM_USED_GAME_STATS)
        gSaveBlock1Ptr->gameStats[index] = value ^ gSaveBlock2Ptr->encryptionKey;
}

void ApplyNewEncryptionKeyToGameStats(u32 newKey)
{
    u8 i;

    for (i = 0; i < NUM_GAME_STATS; i++)
        ApplyNewEncryptionKeyToWord(&gSaveBlock1Ptr->gameStats[i], newKey);
}

void LoadObjEventTemplatesFromHeader(void)
{
    // Clear map object templates
    CpuFill32(0, gSaveBlock1Ptr->objectEventTemplates, sizeof(gSaveBlock1Ptr->objectEventTemplates));

    // Copy map header events to save block
    CpuCopy32(gMapHeader.events->objectEvents,
              gSaveBlock1Ptr->objectEventTemplates,
              gMapHeader.events->objectEventCount * sizeof(struct ObjectEventTemplate));
}

void LoadSaveblockObjEventScripts(void)
{
    const struct ObjectEventTemplate *mapHeaderObjTemplates = gMapHeader.events->objectEvents;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    s32 i;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
        savObjTemplates[i].script = mapHeaderObjTemplates[i].script;
}

void SetObjEventTemplateCoords(u8 localId, s16 x, s16 y)
{
    s32 i;
    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;

    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->x = x;
            objectEventTemplate->y = y;
            return;
        }
    }
}

void SetObjEventTemplateMovementType(u8 localId, u8 movementType)
{
    s32 i;

    struct ObjectEventTemplate *savObjTemplates = gSaveBlock1Ptr->objectEventTemplates;
    for (i = 0; i < OBJECT_EVENT_TEMPLATES_COUNT; i++)
    {
        struct ObjectEventTemplate *objectEventTemplate = &savObjTemplates[i];
        if (objectEventTemplate->localId == localId)
        {
            objectEventTemplate->movementType = movementType;
            return;
        }
    }
}

static void InitMapView(void)
{
    ResetFieldCamera();
    CopyMapTilesetsToVram(gMapHeader.mapLayout);
    LoadMapTilesetPalettes(gMapHeader.mapLayout);
    DrawWholeMapView();
    InitTilesetAnimations();
}

const struct MapLayout *GetMapLayout(u16 mapLayoutId)
{
    return gMapLayouts[mapLayoutId - 1];
}

void ApplyCurrentWarp(void)
{
    gLastUsedWarp = gSaveBlock1Ptr->location;
    gSaveBlock1Ptr->location = sWarpDestination;
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
}

static void ClearDiveAndHoleWarps(void)
{
    sFixedDiveWarp = sDummyWarpData;
    sFixedHoleWarp = sDummyWarpData;
}

static void SetWarpData(struct WarpData *warp, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    warp->mapGroup = mapGroup;
    warp->mapNum = mapNum;
    warp->warpId = warpId;
    warp->x = x;
    warp->y = y;
}

static bool32 IsDummyWarp(struct WarpData *warp)
{
    if (warp->mapGroup != (s8)MAP_GROUP(UNDEFINED))
        return FALSE;
    else if (warp->mapNum != (s8)MAP_NUM(UNDEFINED))
        return FALSE;
    else if (warp->warpId != WARP_ID_NONE)
        return FALSE;
    else if (warp->x != -1)
        return FALSE;
    else if (warp->y != -1)
        return FALSE;
    else
        return TRUE;
}

struct MapHeader const *const Overworld_GetMapHeaderByGroupAndId(u16 mapGroup, u16 mapNum)
{
    return gMapGroups[mapGroup][mapNum];
}

struct MapHeader const *const GetDestinationWarpMapHeader(void)
{
    return Overworld_GetMapHeaderByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
}

static void LoadCurrentMapData(void)
{
    sLastMapSectionId = gMapHeader.regionMapSectionId;
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gSaveBlock1Ptr->mapLayoutId = gMapHeader.mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout(gMapHeader.mapLayoutId);
}

static void LoadSaveblockMapHeader(void)
{
    gMapHeader = *Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    gMapHeader.mapLayout = GetMapLayout(gMapHeader.mapLayoutId);
}

static void SetPlayerCoordsFromWarp(void)
{
    if (gSaveBlock1Ptr->location.warpId >= 0 && gSaveBlock1Ptr->location.warpId < gMapHeader.events->warpCount)
    {
        // warpId is a valid warp for this map, use the coords of that warp.
        gSaveBlock1Ptr->pos.x = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].x;
        gSaveBlock1Ptr->pos.y = gMapHeader.events->warps[gSaveBlock1Ptr->location.warpId].y;
    }
    else if (gSaveBlock1Ptr->location.x >= 0 && gSaveBlock1Ptr->location.y >= 0)
    {
        // Invalid warpId given. The given coords are valid, use those instead.
        // WARP_ID_NONE is used to reach this intentionally.
        gSaveBlock1Ptr->pos.x = gSaveBlock1Ptr->location.x;
        gSaveBlock1Ptr->pos.y = gSaveBlock1Ptr->location.y;
    }
    else
    {
        // Invalid warpId and coords given. Put player in center of map.
        gSaveBlock1Ptr->pos.x = gMapHeader.mapLayout->width / 2;
        gSaveBlock1Ptr->pos.y = gMapHeader.mapLayout->height / 2;
    }
}

static void SetFollowerCoordsFromWarp(void)
{
    struct ObjectEvent* player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent* follower = &gObjectEvents[gSaveBlock2Ptr->follower.objId];

    gSaveBlock2Ptr->follower.warpEnd = 0;        
    
    // Based on value passed in via setfollowerwarppos macro, place the follower relative to the player.
    // If DIR_NONE, then setup for follower popping out of pokeball
    switch(gSpecialVar_Result)
    {
        case DIR_NONE:
            MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y);
            gSaveBlock2Ptr->follower.createSurfBlob = 2;
            break;
        case DIR_SOUTH:
            MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y + 1);
            follower->invisible = FALSE;
            gSaveBlock2Ptr->follower.createSurfBlob = 0;
            break;
        case DIR_NORTH:
            MoveObjectEventToMapCoords(follower, player->currentCoords.x, player->currentCoords.y - 1);
            follower->invisible = FALSE;
            gSaveBlock2Ptr->follower.createSurfBlob = 0;
            break;
        case DIR_WEST:
            MoveObjectEventToMapCoords(follower, player->currentCoords.x - 1, player->currentCoords.y);
            follower->invisible = FALSE;
            gSaveBlock2Ptr->follower.createSurfBlob = 0;
            break;
        case DIR_EAST:
            MoveObjectEventToMapCoords(follower, player->currentCoords.x + 1, player->currentCoords.y);
            follower->invisible = FALSE;
            gSaveBlock2Ptr->follower.createSurfBlob = 0;
            break;
    }
}

void WarpIntoMap(void)
{
    ApplyCurrentWarp();
    LoadCurrentMapData();
    SetPlayerCoordsFromWarp();
}

void SetWarpDestination(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sWarpDestination, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToMapWarp(s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpDestination(mapGroup, mapNum, warpId, -1, -1);
}

void SetDynamicWarp(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, gSaveBlock1Ptr->pos.x, gSaveBlock1Ptr->pos.y);
}

void SetDynamicWarpWithCoords(s32 unused, s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->dynamicWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToDynamicWarp(u8 unusedWarpId)
{
    sWarpDestination = gSaveBlock1Ptr->dynamicWarp;
}

void SetWarpDestinationToHealLocation(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpDestination(healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void SetWarpDestinationToLastHealLocation(void)
{
    sWarpDestination = gSaveBlock1Ptr->lastHealLocation;
}

void SetLastHealLocationWarp(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpData(&gSaveBlock1Ptr->lastHealLocation, healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void UpdateEscapeWarp(s16 x, s16 y)
{
    u8 currMapType = GetCurrentMapType();
    u8 destMapType = GetMapTypeByGroupAndId(sWarpDestination.mapGroup, sWarpDestination.mapNum);
    if (IsMapTypeOutdoors(currMapType) && IsMapTypeOutdoors(destMapType) != TRUE)
        SetEscapeWarp(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE, x - MAP_OFFSET, y - MAP_OFFSET + 1);
}

void SetEscapeWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->escapeWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToEscapeWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->escapeWarp;
}

void SetFixedDiveWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedDiveWarp, mapGroup, mapNum, warpId, x, y);
}

static void SetWarpDestinationToDiveWarp(void)
{
    sWarpDestination = sFixedDiveWarp;
}

void SetFixedHoleWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&sFixedHoleWarp, mapGroup, mapNum, warpId, x, y);
}

void SetWarpDestinationToFixedHoleWarp(s16 x, s16 y)
{
    if (IsDummyWarp(&sFixedHoleWarp) == TRUE)
        sWarpDestination = gLastUsedWarp;
    else
        SetWarpDestination(sFixedHoleWarp.mapGroup, sFixedHoleWarp.mapNum, WARP_ID_NONE, x, y);
}

static void SetWarpDestinationToContinueGameWarp(void)
{
    sWarpDestination = gSaveBlock1Ptr->continueGameWarp;
}

void SetContinueGameWarp(s8 mapGroup, s8 mapNum, s8 warpId, s8 x, s8 y)
{
    SetWarpData(&gSaveBlock1Ptr->continueGameWarp, mapGroup, mapNum, warpId, x, y);
}

void SetContinueGameWarpToHealLocation(u8 healLocationId)
{
    const struct HealLocation *healLocation = GetHealLocation(healLocationId);
    if (healLocation)
        SetWarpData(&gSaveBlock1Ptr->continueGameWarp, healLocation->group, healLocation->map, WARP_ID_NONE, healLocation->x, healLocation->y);
}

void SetContinueGameWarpToDynamicWarp(int unused)
{
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->dynamicWarp;
}

const struct MapConnection *GetMapConnection(u8 dir)
{
    s32 i;
    s32 count = gMapHeader.connections->count;
    const struct MapConnection *connection = gMapHeader.connections->connections;

    if (connection == NULL)
        return NULL;

    for(i = 0; i < count; i++, connection++)
        if (connection->direction == dir)
            return connection;

    return NULL;
}

static bool8 SetDiveWarp(u8 dir, u16 x, u16 y)
{
    const struct MapConnection *connection = GetMapConnection(dir);

    if (connection != NULL)
    {
        SetWarpDestination(connection->mapGroup, connection->mapNum, WARP_ID_NONE, x, y);
    }
    else
    {
        RunOnDiveWarpMapScript();
        if (IsDummyWarp(&sFixedDiveWarp))
            return FALSE;
        SetWarpDestinationToDiveWarp();
    }
    return TRUE;
}

bool8 SetDiveWarpEmerge(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_EMERGE, x, y);
}

bool8 SetDiveWarpDive(u16 x, u16 y)
{
    return SetDiveWarp(CONNECTION_DIVE, x, y);
}

void LoadMapFromCameraTransition(u8 mapGroup, u8 mapNum)
{
    s32 paletteIndex;

    SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, -1, -1);

    // Dont transition map music between BF Outside West/East
    if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER)
        TransitionMapMusic();

    ApplyCurrentWarp();
    LoadCurrentMapData();
    LoadObjEventTemplatesFromHeader();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
    TryUpdateRandomTrainerRematches(mapGroup, mapNum);
    DoTimeBasedEvents();
    SetSavedWeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    RunOnTransitionMapScript();
    InitMap();
    CopySecondaryTilesetToVramUsingHeap(gMapHeader.mapLayout);
    LoadSecondaryTilesetPalette(gMapHeader.mapLayout);

    for (paletteIndex = NUM_PALS_IN_PRIMARY; paletteIndex < NUM_PALS_TOTAL; paletteIndex++)
        ApplyWeatherColorMapToPal(paletteIndex);

    InitSecondaryTilesetAnimation();
    UpdateLocationHistoryForRoamer();
    RoamerMove();
    DoCurrentWeather();
    ResetFieldTasksArgs();
    RunOnResumeMapScript();

    if (gMapHeader.regionMapSectionId != MAPSEC_BATTLE_FRONTIER
     || gMapHeader.regionMapSectionId != sLastMapSectionId)
        ShowMapNamePopup();
}

static void LoadMapFromWarp(bool32 a1)
{
    bool8 isOutdoors;
    bool8 isIndoors;

    LoadCurrentMapData();
    if (!(sObjectEventLoadFlag & SKIP_OBJECT_EVENT_LOAD))
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
            LoadBattlePyramidObjectEventTemplates();
        else if (InTrainerHill())
            LoadTrainerHillObjectEventTemplates();
        else
            LoadObjEventTemplatesFromHeader();
    }

    isOutdoors = IsMapTypeOutdoors(gMapHeader.mapType);
    isIndoors = IsMapTypeIndoors(gMapHeader.mapType);

    CheckLeftFriendsSecretBase();
    TrySetMapSaveWarpStatus();
    ClearTempFieldEventData();
    ResetCyclingRoadChallengeData();
    RestartWildEncounterImmunitySteps();
    TryUpdateRandomTrainerRematches(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum);
    if (a1 != TRUE)
        DoTimeBasedEvents();
    SetSavedWeatherFromCurrMapHeader();
    ChooseAmbientCrySpecies();
    if (isOutdoors)
        FlagClear(FLAG_SYS_USE_FLASH);
    SetDefaultFlashLevel();
    Overworld_ClearSavedMusic();
    RunOnTransitionMapScript();
    UpdateLocationHistoryForRoamer();
    RoamerMoveToOtherLocationSet();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(FALSE);
    else if (InTrainerHill())
        InitTrainerHillMap();
    else
        InitMap();

    if (a1 != TRUE && isIndoors)
    {
        UpdateTVScreensOnMap(gBackupMapLayout.width, gBackupMapLayout.height);
        InitSecretBaseAppearance(TRUE);
    }
}

void ResetInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = DIR_SOUTH;
    sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

void StoreInitialPlayerAvatarState(void)
{
    sInitialPlayerAvatarState.direction = GetPlayerFacingDirection();

    if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_ACRO_BIKE))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ACRO_BIKE;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_SURFING;
    else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_UNDERWATER))
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_UNDERWATER;
    else
        sInitialPlayerAvatarState.transitionFlags = PLAYER_AVATAR_FLAG_ON_FOOT;
}

static struct InitialPlayerAvatarState *GetInitialPlayerAvatarState(void)
{
    struct InitialPlayerAvatarState playerStruct;
    u8 mapType = GetCurrentMapType();
    u16 metatileBehavior = GetCenterScreenMetatileBehavior();
    u8 transitionFlags = GetAdjustedInitialTransitionFlags(&sInitialPlayerAvatarState, metatileBehavior, mapType);
    playerStruct.transitionFlags = transitionFlags;
    playerStruct.direction = GetAdjustedInitialDirection(&sInitialPlayerAvatarState, transitionFlags, metatileBehavior, mapType);
    sInitialPlayerAvatarState = playerStruct;
    return &sInitialPlayerAvatarState;
}

static u8 GetAdjustedInitialTransitionFlags(struct InitialPlayerAvatarState *playerStruct, u16 metatileBehavior, u8 mapType)
{
    if (mapType != MAP_TYPE_INDOOR && FlagGet(FLAG_SYS_CRUISE_MODE))
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (mapType == MAP_TYPE_UNDERWATER)
        return PLAYER_AVATAR_FLAG_UNDERWATER;
    else if (MetatileBehavior_IsSurfableWaterOrUnderwater(metatileBehavior) == TRUE)
        return PLAYER_AVATAR_FLAG_SURFING;
    else if (Overworld_IsBikingAllowed() != TRUE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else if (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_MACH_BIKE)
        return PLAYER_AVATAR_FLAG_MACH_BIKE;
    else if (playerStruct->transitionFlags != PLAYER_AVATAR_FLAG_ACRO_BIKE)
        return PLAYER_AVATAR_FLAG_ON_FOOT;
    else
        return PLAYER_AVATAR_FLAG_ACRO_BIKE;
}

static u8 GetAdjustedInitialDirection(struct InitialPlayerAvatarState *playerStruct, u8 transitionFlags, u16 metatileBehavior, u8 mapType)
{
    if (FlagGet(FLAG_SYS_CRUISE_MODE) && mapType == MAP_TYPE_OCEAN_ROUTE)
        return DIR_EAST;
    else if (MetatileBehavior_IsDeepSouthWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNonAnimDoor(metatileBehavior) == TRUE || MetatileBehavior_IsDoor(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsSouthArrowWarp(metatileBehavior) == TRUE)
        return DIR_NORTH;
    else if (MetatileBehavior_IsNorthArrowWarp(metatileBehavior) == TRUE)
        return DIR_SOUTH;
    else if (MetatileBehavior_IsWestArrowWarp(metatileBehavior) == TRUE)
        return DIR_EAST;
    else if (MetatileBehavior_IsEastArrowWarp(metatileBehavior) == TRUE)
        return DIR_WEST;
    else if ((playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER  && transitionFlags == PLAYER_AVATAR_FLAG_SURFING)
          || (playerStruct->transitionFlags == PLAYER_AVATAR_FLAG_SURFING && transitionFlags == PLAYER_AVATAR_FLAG_UNDERWATER))
        return playerStruct->direction;
    else if (MetatileBehavior_IsLadder(metatileBehavior) == TRUE)
        return playerStruct->direction;
    else
        return DIR_SOUTH;
}

static u16 GetCenterScreenMetatileBehavior(void)
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1Ptr->pos.x + MAP_OFFSET, gSaveBlock1Ptr->pos.y + MAP_OFFSET);
}

bool32 Overworld_IsBikingAllowed(void)
{
    if (!gMapHeader.allowCycling)
        return FALSE;
    else
        return TRUE;
}

// Flash level of 0 is fully bright
// Flash level of 1 is the largest flash radius
// Flash level of 7 is the smallest flash radius
// Flash level of 8 is fully black
void SetDefaultFlashLevel(void)
{
    if (!gMapHeader.cave)
        gSaveBlock1Ptr->flashLevel = 0;
    else if (FlagGet(FLAG_SYS_USE_FLASH))
        gSaveBlock1Ptr->flashLevel = 1;
    else
        gSaveBlock1Ptr->flashLevel = gMaxFlashLevel - 1;
}

void SetFlashLevel(s32 flashLevel)
{
    if (flashLevel < 0 || flashLevel > gMaxFlashLevel)
        flashLevel = 0;
    gSaveBlock1Ptr->flashLevel = flashLevel;
}

u8 GetFlashLevel(void)
{
    return gSaveBlock1Ptr->flashLevel;
}

void SetCurrentMapLayout(u16 mapLayoutId)
{
    gSaveBlock1Ptr->mapLayoutId = mapLayoutId;
    gMapHeader.mapLayout = GetMapLayout(mapLayoutId);
}

void SetObjectEventLoadFlag(u8 flag)
{
    sObjectEventLoadFlag = flag;
}

// sObjectEventLoadFlag is read directly
static u8 UNUSED GetObjectEventLoadFlag(void)
{
    return sObjectEventLoadFlag;
}

static bool16 ShouldLegendaryMusicPlayAtLocation(struct WarpData *warp)
{
    if (!FlagGet(FLAG_SYS_WEATHER_CTRL))
        return FALSE;
    if (warp->mapGroup == 0)
    {
        switch (warp->mapNum)
        {
        case MAP_NUM(LILYCOVE_CITY):
        case MAP_NUM(MOSSDEEP_CITY):
        case MAP_NUM(SOOTOPOLIS_CITY):
        case MAP_NUM(EVER_GRANDE_CITY):
        case MAP_NUM(ROUTE124):
        case MAP_NUM(ROUTE125):
        case MAP_NUM(ROUTE126):
        case MAP_NUM(ROUTE127):
        case MAP_NUM(ROUTE128):
            return TRUE;
        default:
            if (VarGet(VAR_SOOTOPOLIS_CITY_STATE) < 4)
                return FALSE;
            switch (warp->mapNum)
            {
            case MAP_NUM(ROUTE129):
            case MAP_NUM(ROUTE130):
            case MAP_NUM(ROUTE131):
                return TRUE;
            }
        }
    }
    return FALSE;
}

static bool16 NoMusicInSotopolisWithLegendaries(struct WarpData *warp)
{
    if (VarGet(VAR_SKY_PILLAR_STATE) != 1)
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(SOOTOPOLIS_CITY))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(SOOTOPOLIS_CITY))
        return TRUE;
    else
        return FALSE;
}

static bool16 IsInfiltratedWeatherInstitute(struct WarpData *warp)
{
    if (VarGet(VAR_WEATHER_INSTITUTE_STATE))
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(ROUTE119_WEATHER_INSTITUTE_1F))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_1F)
     || warp->mapNum == MAP_NUM(ROUTE119_WEATHER_INSTITUTE_2F))
        return TRUE;
    else
        return FALSE;
}

static bool16 IsInflitratedSpaceCenter(struct WarpData *warp)
{
    if (VarGet(VAR_MOSSDEEP_CITY_STATE) == 0)
        return FALSE;
    else if (VarGet(VAR_MOSSDEEP_CITY_STATE) > 2)
        return FALSE;
    else if (warp->mapGroup != MAP_GROUP(MOSSDEEP_CITY_SPACE_CENTER_1F))
        return FALSE;
    else if (warp->mapNum == MAP_NUM(MOSSDEEP_CITY_SPACE_CENTER_1F)
     || warp->mapNum == MAP_NUM(MOSSDEEP_CITY_SPACE_CENTER_2F))
        return TRUE;
    return FALSE;
}

u16 GetLocationMusic(struct WarpData *warp)
{
    if (NoMusicInSotopolisWithLegendaries(warp) == TRUE)
        return MUS_NONE;
    else if (ShouldLegendaryMusicPlayAtLocation(warp) == TRUE)
        return MUS_ABNORMAL_WEATHER;
    else if (IsInflitratedSpaceCenter(warp) == TRUE)
        return MUS_ENCOUNTER_MAGMA;
    else if (IsInfiltratedWeatherInstitute(warp) == TRUE)
        return MUS_MT_CHIMNEY;
    else
        return Overworld_GetMapHeaderByGroupAndId(warp->mapGroup, warp->mapNum)->music;
}

u16 GetCurrLocationDefaultMusic(void)
{
    u16 music;

    // Play the desert music only when the sandstorm is active on Route 111.
    if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE111)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE111)
     && GetSavedWeather() == WEATHER_SANDSTORM)
        return MUS_DESERT;

    music = GetLocationMusic(&gSaveBlock1Ptr->location);
    if (music != MUS_ROUTE118)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->pos.x < 24)
            return MUS_ROUTE110;
        else
            return MUS_ROUTE119;
    }
}

u16 GetWarpDestinationMusic(void)
{
    u16 music = GetLocationMusic(&sWarpDestination);
    if (music != MUS_ROUTE118)
    {
        return music;
    }
    else
    {
        if (gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MAUVILLE_CITY)
         && gSaveBlock1Ptr->location.mapNum == MAP_NUM(MAUVILLE_CITY))
            return MUS_ROUTE110;
        else
            return MUS_ROUTE119;
    }
}

void Overworld_ResetMapMusic(void)
{
    ResetMapMusic();
}

void Overworld_PlaySpecialMapMusic(void)
{
    u16 music = GetCurrLocationDefaultMusic();

    if (music != MUS_ABNORMAL_WEATHER && music != MUS_NONE)
    {
        if (gSaveBlock1Ptr->savedMusic)
            music = gSaveBlock1Ptr->savedMusic;
        else if (GetCurrentMapType() == MAP_TYPE_UNDERWATER)
            music = MUS_UNDERWATER;
        else if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
            music = MUS_SURF;
    }

    if (music != GetCurrentMapMusic())
        PlayNewMapMusic(music);
}

void Overworld_SetSavedMusic(u16 songNum)
{
    gSaveBlock1Ptr->savedMusic = songNum;
}

void Overworld_ClearSavedMusic(void)
{
    gSaveBlock1Ptr->savedMusic = MUS_DUMMY;
}

static void TransitionMapMusic(void)
{
    if (FlagGet(FLAG_DONT_TRANSITION_MUSIC) != TRUE)
    {
        u16 newMusic = GetWarpDestinationMusic();
        u16 currentMusic = GetCurrentMapMusic();
        if (newMusic != MUS_ABNORMAL_WEATHER && newMusic != MUS_NONE)
        {
            if (currentMusic == MUS_UNDERWATER || currentMusic == MUS_SURF)
                return;
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_SURFING))
                newMusic = MUS_SURF;
        }
        if (newMusic != currentMusic)
        {
            if (TestPlayerAvatarFlags(PLAYER_AVATAR_FLAG_MACH_BIKE | PLAYER_AVATAR_FLAG_ACRO_BIKE))
                FadeOutAndFadeInNewMapMusic(newMusic, 4, 4);
            else
                FadeOutAndPlayNewMapMusic(newMusic, 8);
        }
    }
}

void Overworld_ChangeMusicToDefault(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != GetCurrLocationDefaultMusic())
        FadeOutAndPlayNewMapMusic(GetCurrLocationDefaultMusic(), 8);
}

void Overworld_ChangeMusicTo(u16 newMusic)
{
    u16 currentMusic = GetCurrentMapMusic();
    if (currentMusic != newMusic && currentMusic != MUS_ABNORMAL_WEATHER)
        FadeOutAndPlayNewMapMusic(newMusic, 8);
}

u8 GetMapMusicFadeoutSpeed(void)
{
    const struct MapHeader *mapHeader = GetDestinationWarpMapHeader();
    if (IsMapTypeIndoors(mapHeader->mapType) == TRUE)
        return 2;
    else
        return 4;
}

void TryFadeOutOldMapMusic(void)
{
    u16 currentMusic = GetCurrentMapMusic();
    u16 warpMusic = GetWarpDestinationMusic();
    if (FlagGet(FLAG_DONT_TRANSITION_MUSIC) != TRUE && warpMusic != GetCurrentMapMusic())
    {
        if (currentMusic == MUS_SURF
            && VarGet(VAR_SKY_PILLAR_STATE) == 2
            && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && gSaveBlock1Ptr->location.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && sWarpDestination.mapGroup == MAP_GROUP(SOOTOPOLIS_CITY)
            && sWarpDestination.mapNum == MAP_NUM(SOOTOPOLIS_CITY)
            && sWarpDestination.x == 29
            && sWarpDestination.y == 53)
            return;
        FadeOutMapMusic(GetMapMusicFadeoutSpeed());
    }
}

bool8 BGMusicStopped(void)
{
    return IsNotWaitingForBGMStop();
}

void Overworld_FadeOutMapMusic(void)
{
    FadeOutMapMusic(4);
}

static void PlayAmbientCry(void)
{
    s16 x, y;
    s8 pan;
    s8 volume;

    PlayerGetDestCoords(&x, &y);
    if (sIsAmbientCryWaterMon == TRUE
     && !MetatileBehavior_IsSurfableWaterOrUnderwater(MapGridGetMetatileBehaviorAt(x, y)))
        return;
    pan = (Random() % 88) + 212;
    volume = (Random() % 30) + 50;
    PlayCry_NormalNoDucking(sAmbientCrySpecies, pan, volume, CRY_PRIORITY_AMBIENT);
}

// States for UpdateAmbientCry
enum {
    AMB_CRY_INIT,
    AMB_CRY_FIRST,
    AMB_CRY_RESET,
    AMB_CRY_WAIT,
    AMB_CRY_IDLE,
};

void UpdateAmbientCry(s16 *state, u16 *delayCounter)
{
    u8 i, monsCount, divBy;

    switch (*state)
    {
    case AMB_CRY_INIT:
        // This state will be revisited whenever ResetFieldTasksArgs is called (which happens on map transition)
        if (sAmbientCrySpecies == SPECIES_NONE)
            *state = AMB_CRY_IDLE;
        else
            *state = AMB_CRY_FIRST;
        break;
    case AMB_CRY_FIRST:
        // It takes between 1200-3599 frames (~20-60 seconds) to play the first ambient cry after entering a map
        *delayCounter = (Random() % 2400) + 1200;
        *state = AMB_CRY_WAIT;
        break;
    case AMB_CRY_RESET:
        divBy = 1;
        monsCount = CalculatePlayerPartyCount();
        for (i = 0; i < monsCount; i++)
        {
            if (!GetMonData(&gPlayerParty[i], MON_DATA_SANITY_IS_EGG)
                && GetMonAbility(&gPlayerParty[0]) == ABILITY_SWARM)
            {
                divBy = 2;
                break;
            }
        }
        // Ambient cries after the first one take between 1200-2399 frames (~20-40 seconds)
        // If the player has a pokemon with the ability Swarm in their party, the time is halved to 600-1199 frames (~10-20 seconds)
        *delayCounter = ((Random() % 1200) + 1200) / divBy;
        *state = AMB_CRY_WAIT;
        break;
    case AMB_CRY_WAIT:
        if (--(*delayCounter) == 0)
        {
            PlayAmbientCry();
            *state = AMB_CRY_RESET;
        }
        break;
    case AMB_CRY_IDLE:
        // No land/water pokemon on this map
        break;
    }
}

static void ChooseAmbientCrySpecies(void)
{
    if ((gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ROUTE130)
     && gSaveBlock1Ptr->location.mapNum == MAP_NUM(ROUTE130))
     && !IsMirageIslandPresent())
    {
        // Only play water pokemon cries on this route
        // when Mirage Island is not present
        sIsAmbientCryWaterMon = TRUE;
        sAmbientCrySpecies = GetLocalWaterMon();
    }
    else
    {
        sAmbientCrySpecies = GetLocalWildMon(&sIsAmbientCryWaterMon);
    }
}

u8 GetMapTypeByGroupAndId(s8 mapGroup, s8 mapNum)
{
    return Overworld_GetMapHeaderByGroupAndId(mapGroup, mapNum)->mapType;
}

u8 GetMapTypeByWarpData(struct WarpData *warp)
{
    return GetMapTypeByGroupAndId(warp->mapGroup, warp->mapNum);
}

u8 GetCurrentMapType(void)
{
    return GetMapTypeByWarpData(&gSaveBlock1Ptr->location);
}

u8 GetLastUsedWarpMapType(void)
{
    return GetMapTypeByWarpData(&gLastUsedWarp);
}

bool8 IsMapTypeOutdoors(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_UNDERWATER
     || mapType == MAP_TYPE_CITY
     || mapType == MAP_TYPE_OCEAN_ROUTE)
        return TRUE;
    else
        return FALSE;
}

bool8 Overworld_MapTypeAllowsTeleportAndFly(u8 mapType)
{
    if (mapType == MAP_TYPE_ROUTE
     || mapType == MAP_TYPE_TOWN
     || mapType == MAP_TYPE_OCEAN_ROUTE
     || mapType == MAP_TYPE_CITY)
        return TRUE;
    else
        return FALSE;
}

bool8 IsMapTypeIndoors(u8 mapType)
{
    if (mapType == MAP_TYPE_INDOOR
     || mapType == MAP_TYPE_SECRET_BASE)
        return TRUE;
    else
        return FALSE;
}

u8 GetSavedWarpRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->dynamicWarp.mapGroup, gSaveBlock1Ptr->dynamicWarp.mapNum)->regionMapSectionId;
}

u8 GetCurrentRegionMapSectionId(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->regionMapSectionId;
}

u8 GetCurrentMapBattleScene(void)
{
    return Overworld_GetMapHeaderByGroupAndId(gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum)->battleType;
}

static void InitOverworldBgs(void)
{
    InitBgsFromTemplates(0, sOverworldBgTemplates, ARRAY_COUNT(sOverworldBgTemplates));
    SetBgAttribute(1, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(2, BG_ATTR_MOSAIC, 1);
    SetBgAttribute(3, BG_ATTR_MOSAIC, 1);
    gOverworldTilemapBuffer_Bg1 = AllocZeroed(BG_SCREEN_SIZE);
    gOverworldTilemapBuffer_Bg2 = AllocZeroed(BG_SCREEN_SIZE);
    gOverworldTilemapBuffer_Bg3 = AllocZeroed(BG_SCREEN_SIZE);
    SetBgTilemapBuffer(1, gOverworldTilemapBuffer_Bg1);
    SetBgTilemapBuffer(2, gOverworldTilemapBuffer_Bg2);
    SetBgTilemapBuffer(3, gOverworldTilemapBuffer_Bg3);
    InitStandardTextBoxWindows();
}

void CleanupOverworldWindowsAndTilemaps(void)
{
    ClearMirageTowerPulseBlendEffect();
    FreeAllOverworldWindowBuffers();
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg3);
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg2);
    TRY_FREE_AND_SET_NULL(gOverworldTilemapBuffer_Bg1);
}

static void ResetSafariZoneFlag_(void)
{
    ResetSafariZoneFlag();
}

bool32 IsOverworldLinkActive(void)
{
    if (gMain.callback1 == CB1_OverworldLink)
        return TRUE;
    else
        return FALSE;
}

static void DoCB1_Overworld(u16 newKeys, u16 heldKeys)
{
    struct FieldInput inputStruct;

    UpdatePlayerAvatarTransitionState();
    FieldClearPlayerInput(&inputStruct);
    FieldGetPlayerInput(&inputStruct, newKeys, heldKeys);
    if (!ArePlayerFieldControlsLocked())
    {
        if (ProcessPlayerFieldInput(&inputStruct) == 1)
        {
            LockPlayerFieldControls();
            HideMapNamePopUpWindow();
        }
        else
        {
            PlayerStep(inputStruct.dpadDirection, newKeys, heldKeys);
        }
    }
    
    // if stop running but keep holding B -> fix follower frame
    if (PlayerHasFollower() && IsPlayerOnFoot() && IsPlayerStandingStill())
        ObjectEventSetHeldMovement(&gObjectEvents[GetFollowerObjectId()], GetFaceDirectionAnimNum(gObjectEvents[GetFollowerObjectId()].facingDirection));
}

void CB1_Overworld(void)
{
    if (gMain.callback2 == CB2_Overworld)
        DoCB1_Overworld(gMain.newKeys, gMain.heldKeys);
}

static void OverworldBasic(void)
{
    ScriptContext_RunScript();
    RunTasks();
    AnimateSprites();
    CameraUpdate();
    UpdateCameraPanning();
    BuildOamBuffer();
    UpdatePaletteFade();
    UpdateTilesetAnimations();
    DoScheduledBgTilemapCopiesToVram();
}

// This CB2 is used when starting
void CB2_OverworldBasic(void)
{
    OverworldBasic();
}

void CB2_Overworld(void)
{
    bool32 fading = (gPaletteFade.active != 0);
    if (fading)
        SetVBlankCallback(NULL);
    OverworldBasic();
    if (fading)
        SetFieldVBlankCallback();
    
    // Make sure follower's sprite is properly positioned when map reloads.
    if (gSaveBlock2Ptr->follower.inProgress)
    {
        switch(gObjectEvents[gSaveBlock2Ptr->follower.objId].facingDirection)
        {
            case DIR_EAST:
                gSprites[gObjectEvents[gSaveBlock2Ptr->follower.objId].spriteId].x2 = -8;
                break;
            case DIR_WEST:
                gSprites[gObjectEvents[gSaveBlock2Ptr->follower.objId].spriteId].x2 = 8;
                break;
        }
    }
}

void SetMainCallback1(MainCallback cb)
{
    gMain.callback1 = cb;
}

// This function is never called.
void SetUnusedCallback(void *func)
{
    sUnusedOverworldCallback = func;
}

static bool8 RunFieldCallback(void)
{
    if (gFieldCallback2)
    {
        if (!gFieldCallback2())
        {
            return FALSE;
        }
        else
        {
            gFieldCallback2 = NULL;
            gFieldCallback = NULL;
        }
    }
    else
    {
        if (gFieldCallback)
            gFieldCallback();
        else
            FieldCB_DefaultWarpExit();

        gFieldCallback = NULL;
    }

    return TRUE;
}

void CB2_NewGame(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    NewGameInitData();
    ResetInitialPlayerAvatarState();
    PlayTimeCounter_Start();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    gFieldCallback = ExecuteTruckSequence;
    gFieldCallback2 = NULL;
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}

void CB2_WhiteOut(void)
{
    u8 state;

    if (++gMain.state >= 120)
    {
        FieldClearVBlankHBlankCallbacks();
        StopMapMusic();
        ResetSafariZoneFlag_();
        DoWhiteOut();
        ResetInitialPlayerAvatarState();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        gFieldCallback = FieldCB_WarpExitFadeFromBlack;
        state = 0;
        DoMapLoadLoop(&state);
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_LoadMap(void)
{
    FieldClearVBlankHBlankCallbacks();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    SetMainCallback1(NULL);
    SetMainCallback2(CB2_DoChangeMap);
    gMain.savedCallback = CB2_LoadMap2;
}

static void CB2_LoadMap2(void)
{
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
    
    // Handle placing follower after warp as determined via setfollowerwarppos macro
    if (gSaveBlock2Ptr->follower.inProgress && gSaveBlock2Ptr->follower.createSurfBlob == 1)
        SetFollowerCoordsFromWarp();
}

void CB2_ReturnToFieldContestHall(void)
{
    if (!gMain.state)
    {
        FieldClearVBlankHBlankCallbacks();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        SetMainCallback1(NULL);
    }
    if (LoadMapInStepsLocal(&gMain.state, TRUE))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_Overworld);
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToFieldCableClub(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    SetMainCallback2(CB2_LoadMapOnReturnToFieldCableClub);
}

static void CB2_LoadMapOnReturnToFieldCableClub(void)
{
    if (LoadMapInStepsLink(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback1(CB1_OverworldLink);
        ResetAllMultiplayerState();
        SetMainCallback2(CB2_Overworld);
    }
}

void CB2_ReturnToField(void)
{
    if (IsOverworldLinkActive() == TRUE)
    {
        SetMainCallback2(CB2_ReturnToFieldLink);
    }
    else
    {
        FieldClearVBlankHBlankCallbacks();
        SetMainCallback2(CB2_ReturnToFieldLocal);
    }
}

static void CB2_ReturnToFieldLocal(void)
{
    if (ReturnToFieldLocal(&gMain.state))
    {
        SetFieldVBlankCallback();
        SetMainCallback2(CB2_Overworld);
    }
}

static void CB2_ReturnToFieldLink(void)
{
    if (!Overworld_IsRecvQueueAtMax() && ReturnToFieldLink(&gMain.state))
        SetMainCallback2(CB2_Overworld);
}

void CB2_ReturnToFieldFromMultiplayer(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    SetMainCallback1(CB1_OverworldLink);
    ResetAllMultiplayerState();

    if (gWirelessCommType != 0)
        gFieldCallback = FieldCB_ReturnToFieldWirelessLink;
    else
        gFieldCallback = FieldCB_ReturnToFieldCableLink;

    ScriptContext_Init();
    UnlockPlayerFieldControls();
    CB2_ReturnToField();
}

void CB2_ReturnToFieldWithOpenMenu(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback2 = FieldCB_ReturnToFieldOpenStartMenu;
    UpdateFollowerPokemonGraphic();
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScript(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScript;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldContinueScriptPlayMapMusic(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_ContinueScriptHandleMusic;
    CB2_ReturnToField();
}

void CB2_ReturnToFieldFadeFromBlack(void)
{
    FieldClearVBlankHBlankCallbacks();
    gFieldCallback = FieldCB_WarpExitFadeFromBlack;
    CB2_ReturnToField();
}

static void FieldCB_FadeTryShowMapPopup(void)
{
    if (gMapHeader.showMapName == TRUE && SecretBaseMapPopupEnabled() == TRUE)
        ShowMapNamePopup();
    FieldCB_WarpExitFadeFromBlack();
}

void CB2_ContinueSavedGame(void)
{
    u8 trainerHillMapId;

    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag_();
    if (gSaveFileStatus == SAVE_STATUS_ERROR)
        ResetWinStreaks();

    LoadSaveblockMapHeader();
    ClearDiveAndHoleWarps();
    trainerHillMapId = GetCurrentTrainerHillMapId();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        LoadBattlePyramidFloorObjectEventScripts();
    else if (trainerHillMapId != 0 && trainerHillMapId != TRAINER_HILL_ENTRANCE)
        LoadTrainerHillFloorObjectEventScripts();
    else
        LoadSaveblockObjEventScripts();

    UnfreezeObjectEvents();
    DoTimeBasedEvents();
    UpdateMiscOverworldStates();
    if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR)
        InitBattlePyramidMap(TRUE);
    else if (trainerHillMapId != 0)
        InitTrainerHillMap();
    else
        InitMapFromSavedGame();

    PlayTimeCounter_Start();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    InitMatchCallCounters();
    if (UseContinueGameWarp() == TRUE)
    {
        ClearContinueGameWarpStatus();
        SetWarpDestinationToContinueGameWarp();
        WarpIntoMap();
        TryPutTodaysRivalTrainerOnAir();
        SetMainCallback2(CB2_LoadMap);
    }
    else
    {
        TryPutTodaysRivalTrainerOnAir();
        gFieldCallback = FieldCB_FadeTryShowMapPopup;
        SetMainCallback1(CB1_Overworld);
        CB2_ReturnToField();
    }
}

static void FieldClearVBlankHBlankCallbacks(void)
{
    if (UsedPokemonCenterWarp() == TRUE)
        CloseLink();

    if (gWirelessCommType != 0)
    {
        EnableInterrupts(INTR_FLAG_VBLANK | INTR_FLAG_VCOUNT | INTR_FLAG_TIMER3 | INTR_FLAG_SERIAL);
        DisableInterrupts(INTR_FLAG_HBLANK);
    }
    else
    {
        u16 savedIme = REG_IME;
        REG_IME = 0;
        REG_IE &= ~INTR_FLAG_HBLANK;
        REG_IE |= INTR_FLAG_VBLANK;
        REG_IME = savedIme;
    }

    SetVBlankCallback(NULL);
    SetHBlankCallback(NULL);
}

static void SetFieldVBlankCallback(void)
{
    SetVBlankCallback(VBlankCB_Field);
}

static void VBlankCB_Field(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
    FieldUpdateBgTilemapScroll();
    TransferPlttBuffer();
    TransferTilesetAnimsBuffer();
}

static void InitCurrentFlashLevelScanlineEffect(void)
{
    u8 flashLevel;

    if (InBattlePyramid_())
    {
        WriteBattlePyramidViewScanlineEffectBuffer();
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
    else if ((flashLevel = GetFlashLevel()))
    {
        WriteFlashScanlineEffectBuffer(flashLevel);
        ScanlineEffect_SetParams(sFlashEffectParams);
    }
}

static bool32 LoadMapInStepsLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        InitOverworldBgs();
        ScriptContext_Init();
        UnlockPlayerFieldControls();
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 1:
        LoadMapFromWarp(TRUE);
        (*state)++;
        break;
    case 2:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 3:
        OffsetCameraFocusByLinkPlayerId();
        InitObjectEventsLink();
        SpawnLinkPlayers();
        SetCameraToTrackGuestPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 LoadMapInStepsLocal(u8 *state, bool32 a2)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        LoadMapFromWarp(a2);
        (*state)++;
        break;
    case 1:
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 2:
        ResumeMap(a2);
        (*state)++;
        break;
    case 3:
        InitObjectEventsLocal();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 4:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 5:
        ResetFieldCamera();
        (*state)++;
        break;
    case 6:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 8:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 9:
        DrawWholeMapView();
        (*state)++;
        break;
    case 10:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gMapHeader.showMapName == TRUE && SecretBaseMapPopupEnabled() == TRUE)
            ShowMapNamePopup();
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 13:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLocal(u8 *state)
{
    switch (*state)
    {
    case 0:
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        ResumeMap(FALSE);
        InitObjectEventsReturnToField();
        SetCameraToTrackPlayer();
        (*state)++;
        break;
    case 1:
        InitViewGraphics();
        
    #if FAST_FOLLOWERS == TRUE
        if (FlagGet(FLAG_FOLLOWER_IN_BUILDING))
            FieldSetDoorOpened(gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.x, gObjectEvents[gPlayerAvatar.objectEventId].currentCoords.y - 1);
    #endif
        
        TryLoadTrainerHillEReaderPalette();
        (*state)++;
        break;
    case 2:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 3:
        return TRUE;
    }

    return FALSE;
}

static bool32 ReturnToFieldLink(u8 *state)
{
    switch (*state)
    {
    case 0:
        FieldClearVBlankHBlankCallbacks();
        ResetMirageTowerAndSaveBlockPtrs();
        ResetScreenForMapLoad();
        (*state)++;
        break;
    case 1:
        ResumeMap(TRUE);
        (*state)++;
        break;
    case 2:
        CreateLinkPlayerSprites();
        InitObjectEventsReturnToField();
        SetCameraToTrackGuestPlayer_2();
        (*state)++;
        break;
    case 3:
        InitCurrentFlashLevelScanlineEffect();
        InitOverworldGraphicsRegisters();
        InitTextBoxGfxAndPrinters();
        (*state)++;
        break;
    case 4:
        ResetFieldCamera();
        (*state)++;
        break;
    case 5:
        CopyPrimaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 6:
        CopySecondaryTilesetToVram(gMapHeader.mapLayout);
        (*state)++;
        break;
    case 7:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LoadMapTilesetPalettes(gMapHeader.mapLayout);
            (*state)++;
        }
        break;
    case 8:
        DrawWholeMapView();
        (*state)++;
        break;
    case 9:
        InitTilesetAnimations();
        (*state)++;
        break;
    case 11:
        if (gWirelessCommType != 0)
        {
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(0, 0);
        }
        (*state)++;
        break;
    case 12:
        if (RunFieldCallback())
            (*state)++;
        break;
    case 10:
        (*state)++;
        break;
    case 13:
        SetFieldVBlankCallback();
        (*state)++;
        return TRUE;
    }

    return FALSE;
}

static void DoMapLoadLoop(u8 *state)
{
    while (!LoadMapInStepsLocal(state, FALSE));
}

static void ResetMirageTowerAndSaveBlockPtrs(void)
{
    ClearMirageTowerPulseBlend();
    MoveSaveBlocks_ResetHeap();
}

static void ResetScreenForMapLoad(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    ScanlineEffect_Stop();

    DmaClear16(3, PLTT + 2, PLTT_SIZE - 2);
    DmaFillLarge16(3, 0, (void *)VRAM, VRAM_SIZE, 0x1000);
    ResetOamRange(0, 128);
    LoadOam();
}

static void InitViewGraphics(void)
{
    InitCurrentFlashLevelScanlineEffect();
    InitOverworldGraphicsRegisters();
    InitTextBoxGfxAndPrinters();
    InitMapView();
}

static void InitOverworldGraphicsRegisters(void)
{
    ClearScheduledBgCopiesToVram();
    ResetTempTileDataBuffers();
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG0 | WINOUT_WINOBJ_BG0);
    SetGpuReg(REG_OFFSET_WIN0H, 0xFF);
    SetGpuReg(REG_OFFSET_WIN0V, 0xFF);
    SetGpuReg(REG_OFFSET_WIN1H, 0xFFFF);
    SetGpuReg(REG_OFFSET_WIN1V, 0xFFFF);
    SetGpuReg(REG_OFFSET_BLDCNT, gOverworldBackgroundLayerFlags[1] | gOverworldBackgroundLayerFlags[2] | gOverworldBackgroundLayerFlags[3]
                               | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(13, 7));
    InitOverworldBgs();
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_WIN0_ON | DISPCNT_WIN1_ON
                                | DISPCNT_OBJ_1D_MAP | DISPCNT_HBLANK_INTERVAL);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    InitFieldMessageBox();
}

static void ResumeMap(bool32 a1)
{
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    ScanlineEffect_Clear();
    ResetAllPicSprites();
    ResetCameraUpdateInfo();
    InstallCameraPanAheadCallback();
    FreeAllSpritePalettes();

    FieldEffectActiveListClear();
    StartWeather();
    ResumePausedWeather();
    if (!a1)
        SetUpFieldTasks();
    RunOnResumeMapScript();
    TryStartMirageTowerPulseBlendEffect();
}

static void InitObjectEventsLink(void)
{
    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    TrySpawnObjectEvents(0, 0);
    TryRunOnWarpIntoMapScript();
}

static void InitObjectEventsLocal(void)
{
    u16 x, y;
    struct InitialPlayerAvatarState *player;

    gTotalCameraPixelOffsetX = 0;
    gTotalCameraPixelOffsetY = 0;
    ResetObjectEvents();
    GetCameraFocusCoords(&x, &y);
    player = GetInitialPlayerAvatarState();
    InitPlayerAvatar(x, y, player->direction, gSaveBlock2Ptr->playerGender);
    SetPlayerAvatarTransitionFlags(player->transitionFlags);
    ResetInitialPlayerAvatarState();
    TrySpawnObjectEvents(0, 0);
    TryRunOnWarpIntoMapScript();
    FollowMe_HandleSprite();
}

static void InitObjectEventsReturnToField(void)
{
    SpawnObjectEventsOnReturnToField(0, 0);
    RotatingGate_InitPuzzleAndGraphics();
    RunOnReturnToFieldMapScript();
}

static void SetCameraToTrackPlayer(void)
{
    gObjectEvents[gPlayerAvatar.objectEventId].trackedByCamera = TRUE;
    InitCameraUpdateCallback(gPlayerAvatar.spriteId);
}

static void SetCameraToTrackGuestPlayer(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

// Duplicate function.
static void SetCameraToTrackGuestPlayer_2(void)
{
    InitCameraUpdateCallback(GetSpriteForLinkedPlayer(gLocalLinkPlayerId));
}

static void OffsetCameraFocusByLinkPlayerId(void)
{
    u16 x, y;
    GetCameraFocusCoords(&x, &y);

    // This is a hack of some kind; it's undone in SpawnLinkPlayers, which is called
    // soon after this function.
    SetCameraFocusCoords(x + gLocalLinkPlayerId, y);
}

static void SpawnLinkPlayers(void)
{
    u16 i;
    u16 x, y;

    GetCameraFocusCoords(&x, &y);
    x -= gLocalLinkPlayerId;

    for (i = 0; i < gFieldLinkPlayerCount; i++)
    {
        SpawnLinkPlayerObjectEvent(i, i + x, y, gLinkPlayers[i].gender);
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
    }

    ClearAllPlayerKeys();
}

static void CreateLinkPlayerSprites(void)
{
    u16 i;
    for (i = 0; i < gFieldLinkPlayerCount; i++)
        CreateLinkPlayerSprite(i, gLinkPlayers[i].version);
}


static void CB1_OverworldLink(void)
{
    if (gWirelessCommType == 0 || !IsRfuRecvQueueEmpty() || !IsSendingKeysToLink())
    {
        u8 selfId = gLocalLinkPlayerId;
        UpdateAllLinkPlayers(gLinkPartnersHeldKeys, selfId);

        // Note: Because guestId is between 0 and 4, while the smallest key code is
        // LINK_KEY_CODE_EMPTY, this is functionally equivalent to `sPlayerKeyInterceptCallback(0)`.
        // It is expecting the callback to be KeyInterCB_SelfIdle, and that will
        // completely ignore any input parameters.
        //
        // UpdateHeldKeyCode performs a sanity check on its input; if
        // sPlayerKeyInterceptCallback echoes back the argument, which is selfId, then
        // it'll use LINK_KEY_CODE_EMPTY instead.
        //
        // Note 2: There are some key intercept callbacks that treat the key as a player
        // ID. It's so hacky.
        UpdateHeldKeyCode(sPlayerKeyInterceptCallback(selfId));
        ClearAllPlayerKeys();
    }
}

void ResetAllMultiplayerState(void)
{
    ResetAllPlayerLinkStates();
    SetKeyInterceptCallback(KeyInterCB_SelfIdle);
}

static void ClearAllPlayerKeys(void)
{
    ResetPlayerHeldKeys(gLinkPartnersHeldKeys);
}

static void SetKeyInterceptCallback(u16 (*func)(u32))
{
    sRfuKeepAliveTimer = 0;
    sPlayerKeyInterceptCallback = func;
}

// Once every ~60 frames, if the link state hasn't changed (timer reset by calls
// to SetKeyInterceptCallback), it does a bunch of sanity checks on the connection.
// I'm not sure if sRfuKeepAliveTimer is reset in the process, though; rfu stuff is
// still undocumented.
static void CheckRfuKeepAliveTimer(void)
{
    if (gWirelessCommType != 0 && ++sRfuKeepAliveTimer > 60)
        LinkRfu_FatalError();
}

static void ResetAllPlayerLinkStates(void)
{
    s32 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
        sPlayerLinkStates[i] = PLAYER_LINK_STATE_IDLE;
}

// Returns true if all connected players are in state.
static bool32 AreAllPlayersInLinkState(u16 state)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerLinkStates[i] != state)
            return FALSE;
    return TRUE;
}

static bool32 IsAnyPlayerInLinkState(u16 state)
{
    s32 i;
    s32 count = gFieldLinkPlayerCount;

    for (i = 0; i < count; i++)
        if (sPlayerLinkStates[i] == state)
            return TRUE;
    return FALSE;
}

static void HandleLinkPlayerKeyInput(u32 playerId, u16 key, struct CableClubPlayer *trainer, u16 *forceFacing)
{
    const u8 *script;

    if (sPlayerLinkStates[playerId] == PLAYER_LINK_STATE_IDLE)
    {
        script = TryGetTileEventScript(trainer);
        if (script)
        {
            *forceFacing = GetDirectionForEventScript(script);
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                RunInteractLocalPlayerScript(script);
            }
            return;
        }
        if (IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
        {
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
            if (trainer->isLocalPlayer)
            {
                SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                RunTerminateLinkScript();
            }
            return;
        }

        switch (key)
        {
        case LINK_KEY_CODE_START_BUTTON:
            if (CanCableClubPlayerPressStart(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitLinkRoomStartMenuScript();
                }
            }
            break;
        case LINK_KEY_CODE_DPAD_DOWN:
            if (PlayerIsAtSouthExit(trainer) == TRUE)
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    RunConfirmLeaveCableClubScript();
                }
            }
            break;
        case LINK_KEY_CODE_A_BUTTON:
            script = TryInteractWithPlayer(trainer);
            if (script)
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
                    InitMenuBasedScript(script);
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_RECV_QUEUE:
            if (IsCableClubPlayerUnfrozen(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToRecvQueue);
                    InitLinkPlayerQueueScript();
                }
            }
            break;
        case LINK_KEY_CODE_HANDLE_SEND_QUEUE:
            if (IsCableClubPlayerUnfrozen(trainer))
            {
                sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
                if (trainer->isLocalPlayer)
                {
                    SetKeyInterceptCallback(KeyInterCB_DeferToSendQueue);
                    InitLinkPlayerQueueScript();
                }
            }
            break;
        }
    }

    switch (key)
    {
    case LINK_KEY_CODE_EXIT_ROOM:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_EXITING_ROOM;
        break;
    case LINK_KEY_CODE_READY:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_READY;
        break;
    case LINK_KEY_CODE_IDLE:
        sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_IDLE;
        if (trainer->isLocalPlayer)
            SetKeyInterceptCallback(KeyInterCB_SelfIdle);
        break;
    case LINK_KEY_CODE_EXIT_SEAT:
        if (sPlayerLinkStates[playerId] == PLAYER_LINK_STATE_READY)
            sPlayerLinkStates[playerId] = PLAYER_LINK_STATE_BUSY;
        break;
    }
}

static void UpdateAllLinkPlayers(u16 *keys, s32 selfId)
{
    struct CableClubPlayer trainer;
    s32 i;

    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        u8 key = keys[i];
        u16 setFacing = FACING_NONE;
        LoadCableClubPlayer(i, selfId, &trainer);
        HandleLinkPlayerKeyInput(i, key, &trainer, &setFacing);
        if (sPlayerLinkStates[i] == PLAYER_LINK_STATE_IDLE)
            setFacing = GetDirectionForDpadKey(key);
        SetPlayerFacingDirection(i, setFacing);
    }
}

static void UpdateHeldKeyCode(u16 key)
{
    if (key >= LINK_KEY_CODE_EMPTY && key < LINK_KEY_CODE_UNK_8)
        gHeldKeyCodeToSend = key;
    else
        gHeldKeyCodeToSend = LINK_KEY_CODE_EMPTY;

    if (gWirelessCommType != 0
        && GetLinkSendQueueLength() > 1
        && IsOverworldLinkActive() == TRUE
        && IsSendingKeysToLink() == TRUE)
    {
        switch (key)
        {
        case LINK_KEY_CODE_EMPTY:
        case LINK_KEY_CODE_DPAD_DOWN:
        case LINK_KEY_CODE_DPAD_UP:
        case LINK_KEY_CODE_DPAD_LEFT:
        case LINK_KEY_CODE_DPAD_RIGHT:
        case LINK_KEY_CODE_START_BUTTON:
        case LINK_KEY_CODE_A_BUTTON:
            gHeldKeyCodeToSend = LINK_KEY_CODE_NULL;
            break;
        }
    }
}

static u16 KeyInterCB_ReadButtons(u32 key)
{
    if (JOY_HELD(DPAD_UP))
        return LINK_KEY_CODE_DPAD_UP;
    if (JOY_HELD(DPAD_DOWN))
        return LINK_KEY_CODE_DPAD_DOWN;
    if (JOY_HELD(DPAD_LEFT))
        return LINK_KEY_CODE_DPAD_LEFT;
    if (JOY_HELD(DPAD_RIGHT))
        return LINK_KEY_CODE_DPAD_RIGHT;
    if (JOY_NEW(START_BUTTON))
        return LINK_KEY_CODE_START_BUTTON;
    if (JOY_NEW(A_BUTTON))
        return LINK_KEY_CODE_A_BUTTON;
    return LINK_KEY_CODE_EMPTY;
}

static u16 GetDirectionForDpadKey(u16 key)
{
    switch (key)
    {
    case LINK_KEY_CODE_DPAD_RIGHT:
        return FACING_RIGHT;
    case LINK_KEY_CODE_DPAD_LEFT:
        return FACING_LEFT;
    case LINK_KEY_CODE_DPAD_UP:
        return FACING_UP;
    case LINK_KEY_CODE_DPAD_DOWN:
        return FACING_DOWN;
    default:
        return FACING_NONE;
    }
}

// Overwrites the keys with 0x11
static void ResetPlayerHeldKeys(u16 *keys)
{
    s32 i;
    for (i = 0; i < 4; i++)
        keys[i] = LINK_KEY_CODE_EMPTY;
}


static u16 KeyInterCB_SelfIdle(u32 key)
{
    if (ArePlayerFieldControlsLocked() == TRUE)
        return LINK_KEY_CODE_EMPTY;
    if (GetLinkRecvQueueLength() > 4)
        return LINK_KEY_CODE_HANDLE_RECV_QUEUE;
    if (GetLinkSendQueueLength() <= 4)
        return KeyInterCB_ReadButtons(key);
    return LINK_KEY_CODE_HANDLE_SEND_QUEUE;
}

static u16 KeyInterCB_Idle(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

// Ignore the player's inputs as long as there is an event script being executed.
static u16 KeyInterCB_DeferToEventScript(u32 key)
{
    u16 retVal;
    if (ArePlayerFieldControlsLocked() == TRUE)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being recived.
static u16 KeyInterCB_DeferToRecvQueue(u32 key)
{
    u16 retVal;
    if (GetLinkRecvQueueLength() >= OVERWORLD_RECV_QUEUE_MAX)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        UnlockPlayerFieldControls();
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

// Ignore the player's inputs as long as there are events being sent.
static u16 KeyInterCB_DeferToSendQueue(u32 key)
{
    u16 retVal;
    if (GetLinkSendQueueLength() > 2)
    {
        retVal = LINK_KEY_CODE_EMPTY;
    }
    else
    {
        retVal = LINK_KEY_CODE_IDLE;
        UnlockPlayerFieldControls();
        SetKeyInterceptCallback(KeyInterCB_Idle);
    }
    return retVal;
}

static u16 KeyInterCB_ExitingSeat(u32 key)
{
    CheckRfuKeepAliveTimer();
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_Ready(u32 keyOrPlayerId)
{
    if (sPlayerLinkStates[keyOrPlayerId] == PLAYER_LINK_STATE_READY)
    {
        if (JOY_NEW(B_BUTTON))
        {
            SetKeyInterceptCallback(KeyInterCB_ExitingSeat);
            return LINK_KEY_CODE_EXIT_SEAT;
        }
        else
        {
            return LINK_KEY_CODE_EMPTY;
        }
    }
    else
    {
        CheckRfuKeepAliveTimer();
        return LINK_KEY_CODE_EMPTY;
    }
}

static u16 KeyInterCB_SetReady(u32 key)
{
    SetKeyInterceptCallback(KeyInterCB_Ready);
    return LINK_KEY_CODE_READY;
}

static u16 KeyInterCB_SendNothing(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_WaitForPlayersToExit(u32 keyOrPlayerId)
{
    // keyOrPlayerId could be any keycode. This callback does no sanity checking
    // on the size of the key. It's assuming that it is being called from
    // CB1_OverworldLink.
    if (sPlayerLinkStates[keyOrPlayerId] != PLAYER_LINK_STATE_EXITING_ROOM)
        CheckRfuKeepAliveTimer();
    if (AreAllPlayersInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
    {
        ScriptContext_SetupScript(EventScript_DoLinkRoomExit);
        SetKeyInterceptCallback(KeyInterCB_SendNothing);
    }
    return LINK_KEY_CODE_EMPTY;
}

static u16 KeyInterCB_SendExitRoomKey(u32 key)
{
    SetKeyInterceptCallback(KeyInterCB_WaitForPlayersToExit);
    return LINK_KEY_CODE_EXIT_ROOM;
}

// Identical to KeyInterCB_SendNothing
static u16 KeyInterCB_InLinkActivity(u32 key)
{
    return LINK_KEY_CODE_EMPTY;
}

u32 GetCableClubPartnersReady(void)
{
    if (IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM) == TRUE)
        return CABLE_SEAT_FAILED;
    if (sPlayerKeyInterceptCallback == KeyInterCB_Ready && sPlayerLinkStates[gLocalLinkPlayerId] != PLAYER_LINK_STATE_READY)
        return CABLE_SEAT_WAITING;
    if (sPlayerKeyInterceptCallback == KeyInterCB_ExitingSeat && sPlayerLinkStates[gLocalLinkPlayerId] == PLAYER_LINK_STATE_BUSY)
        return CABLE_SEAT_FAILED;
    if (AreAllPlayersInLinkState(PLAYER_LINK_STATE_READY))
        return CABLE_SEAT_SUCCESS;
    return CABLE_SEAT_WAITING;
}

static bool32 UNUSED IsAnyPlayerExitingCableClub(void)
{
    return IsAnyPlayerInLinkState(PLAYER_LINK_STATE_EXITING_ROOM);
}

u16 SetInCableClubSeat(void)
{
    SetKeyInterceptCallback(KeyInterCB_SetReady);
    return 0;
}

u16 SetLinkWaitingForScript(void)
{
    SetKeyInterceptCallback(KeyInterCB_DeferToEventScript);
    return 0;
}

// The exit room key will be sent at the next opportunity.
// The return value is meaningless.
u16 QueueExitLinkRoomKey(void)
{
    SetKeyInterceptCallback(KeyInterCB_SendExitRoomKey);
    return 0;
}

u16 SetStartedCableClubActivity(void)
{
    SetKeyInterceptCallback(KeyInterCB_InLinkActivity);
    return 0;
}

static void LoadCableClubPlayer(s32 linkPlayerId, s32 myPlayerId, struct CableClubPlayer *trainer)
{
    s16 x, y;

    trainer->playerId = linkPlayerId;
    trainer->isLocalPlayer = (linkPlayerId == myPlayerId) ? 1 : 0;
    trainer->movementMode = gLinkPlayerObjectEvents[linkPlayerId].movementMode;
    trainer->facing = GetLinkPlayerFacingDirection(linkPlayerId);
    GetLinkPlayerCoords(linkPlayerId, &x, &y);
    trainer->pos.x = x;
    trainer->pos.y = y;
    trainer->pos.elevation = GetLinkPlayerElevation(linkPlayerId);
    trainer->metatileBehavior = MapGridGetMetatileBehaviorAt(x, y);
}

static bool32 IsCableClubPlayerUnfrozen(struct CableClubPlayer *player)
{
    u8 mode = player->movementMode;
    if (mode == MOVEMENT_MODE_SCRIPTED || mode == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

// Identical to IsCableClubPlayerUnfrozen
static bool32 CanCableClubPlayerPressStart(struct CableClubPlayer *player)
{
    u8 mode = player->movementMode;
    if (mode == MOVEMENT_MODE_SCRIPTED || mode == MOVEMENT_MODE_FREE)
        return TRUE;
    else
        return FALSE;
}

static const u8 *TryGetTileEventScript(struct CableClubPlayer *player)
{
    if (player->movementMode != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;
    return GetCoordEventScriptAtMapPosition(&player->pos);
}

static bool32 PlayerIsAtSouthExit(struct CableClubPlayer *player)
{
    if (player->movementMode != MOVEMENT_MODE_SCRIPTED && player->movementMode != MOVEMENT_MODE_FREE)
        return FALSE;
    else if (!MetatileBehavior_IsSouthArrowWarp(player->metatileBehavior))
        return FALSE;
    else if (player->facing != DIR_SOUTH)
        return FALSE;
    else
        return TRUE;
}

static const u8 *TryInteractWithPlayer(struct CableClubPlayer *player)
{
    struct MapPosition otherPlayerPos;
    u8 linkPlayerId;

    if (player->movementMode != MOVEMENT_MODE_FREE && player->movementMode != MOVEMENT_MODE_SCRIPTED)
        return FACING_NONE;

    otherPlayerPos = player->pos;
    otherPlayerPos.x += gDirectionToVectors[player->facing].x;
    otherPlayerPos.y += gDirectionToVectors[player->facing].y;
    otherPlayerPos.elevation = 0;
    linkPlayerId = GetLinkPlayerIdAt(otherPlayerPos.x, otherPlayerPos.y);

    if (linkPlayerId != MAX_LINK_PLAYERS)
    {
        if (!player->isLocalPlayer)
            return CableClub_EventScript_TooBusyToNotice;
        else if (sPlayerLinkStates[linkPlayerId] != PLAYER_LINK_STATE_IDLE)
            return CableClub_EventScript_TooBusyToNotice;
        else if (!GetLinkTrainerCardColor(linkPlayerId))
            return CableClub_EventScript_ReadTrainerCard;
        else
            return CableClub_EventScript_ReadTrainerCardColored;
    }

    return GetInteractedLinkPlayerScript(&otherPlayerPos, player->metatileBehavior, player->facing);
}

// This returns which direction to force the player to look when one of
// these event scripts runs.
static u16 GetDirectionForEventScript(const u8 *script)
{
    if (script == EventScript_BattleColosseum_4P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_4P_PlayerSpot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_RecordCenter_Spot2)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_RecordCenter_Spot3)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_BattleColosseum_2P_PlayerSpot1)
        return FACING_FORCED_LEFT;
    else if (script == EventScript_TradeCenter_Chair0)
        return FACING_FORCED_RIGHT;
    else if (script == EventScript_TradeCenter_Chair1)
        return FACING_FORCED_LEFT;
    else
        return FACING_NONE;
}

static void InitLinkPlayerQueueScript(void)
{
    LockPlayerFieldControls();
}

static void InitLinkRoomStartMenuScript(void)
{
    PlaySE(SE_WIN_OPEN);
    ShowStartMenu();
    LockPlayerFieldControls();
}

static void RunInteractLocalPlayerScript(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext_SetupScript(script);
    LockPlayerFieldControls();
}

static void RunConfirmLeaveCableClubScript(void)
{
    PlaySE(SE_WIN_OPEN);
    ScriptContext_SetupScript(EventScript_ConfirmLeaveCableClubRoom);
    LockPlayerFieldControls();
}

static void InitMenuBasedScript(const u8 *script)
{
    PlaySE(SE_SELECT);
    ScriptContext_SetupScript(script);
    LockPlayerFieldControls();
}

static void RunTerminateLinkScript(void)
{
    ScriptContext_SetupScript(EventScript_TerminateLink);
    LockPlayerFieldControls();
}

bool32 Overworld_IsRecvQueueAtMax(void)
{
    if (!IsOverworldLinkActive())
        return FALSE;
    if (GetLinkRecvQueueLength() >= OVERWORLD_RECV_QUEUE_MAX)
        sReceivingFromLink = TRUE;
    else
        sReceivingFromLink = FALSE;
    return sReceivingFromLink;
}

bool32 Overworld_RecvKeysFromLinkIsRunning(void)
{
    u8 temp;

    if (GetLinkRecvQueueLength() < OVERWORLD_RECV_QUEUE_MAX - 1)
        return FALSE;
    else if (IsOverworldLinkActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToRecvQueue)
        return TRUE;
    else if (sPlayerKeyInterceptCallback != KeyInterCB_DeferToEventScript)
        return FALSE;

    temp = sReceivingFromLink;
    sReceivingFromLink = FALSE;

    if (temp == TRUE)
        return TRUE;
    else if (gPaletteFade.active && gPaletteFade.softwareFadeFinishing)
        return TRUE;
    else
        return FALSE;
}

bool32 Overworld_SendKeysToLinkIsRunning(void)
{
    if (GetLinkSendQueueLength() < 2)
        return FALSE;
    else if (IsOverworldLinkActive() != TRUE)
        return FALSE;
    else if (IsSendingKeysToLink() != TRUE)
        return FALSE;
    else if (sPlayerKeyInterceptCallback == KeyInterCB_DeferToSendQueue)
        return TRUE;
    else
        return FALSE;
}

bool32 IsSendingKeysOverCable(void)
{
    if (gWirelessCommType != 0)
        return FALSE;
    else if (!IsSendingKeysToLink())
        return FALSE;
    else
        return TRUE;
}

static u32 GetLinkSendQueueLength(void)
{
    if (gWirelessCommType != 0)
        return gRfu.sendQueue.count;
    else
        return gLink.sendQueue.count;
}

static void ZeroLinkPlayerObjectEvent(struct LinkPlayerObjectEvent *linkPlayerObjEvent)
{
    memset(linkPlayerObjEvent, 0, sizeof(struct LinkPlayerObjectEvent));
}

void ClearLinkPlayerObjectEvents(void)
{
    memset(gLinkPlayerObjectEvents, 0, sizeof(gLinkPlayerObjectEvents));
}

static void ZeroObjectEvent(struct ObjectEvent *objEvent)
{
    memset(objEvent, 0, sizeof(struct ObjectEvent));
}

// Note: Emerald reuses the direction and range variables during Link mode
// as special gender and direction values. The types and placement
// conflict with the usual Event Object struct, thus the definitions.
#define linkGender(obj) obj->singleMovementActive
// not even one can reference *byte* aligned bitfield members...
#define linkDirection(obj) ((u8 *)obj)[offsetof(typeof(*obj), fieldEffectSpriteId) - 1] // -> rangeX

static void SpawnLinkPlayerObjectEvent(u8 linkPlayerId, s16 x, s16 y, u8 gender)
{
    u8 objEventId = GetFirstInactiveObjectEventId();
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    ZeroLinkPlayerObjectEvent(linkPlayerObjEvent);
    ZeroObjectEvent(objEvent);

    linkPlayerObjEvent->active = TRUE;
    linkPlayerObjEvent->linkPlayerId = linkPlayerId;
    linkPlayerObjEvent->objEventId = objEventId;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;

    objEvent->active = TRUE;
    linkGender(objEvent) = gender;
    linkDirection(objEvent) = DIR_NORTH;
    objEvent->spriteId = MAX_SPRITES;

    InitLinkPlayerObjectEventPos(objEvent, x, y);
}

static void InitLinkPlayerObjectEventPos(struct ObjectEvent *objEvent, s16 x, s16 y)
{
    objEvent->currentCoords.x = x;
    objEvent->currentCoords.y = y;
    objEvent->previousCoords.x = x;
    objEvent->previousCoords.y = y;
    SetSpritePosToMapCoords(x, y, &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    objEvent->initialCoords.x += 8;
    ObjectEventUpdateElevation(objEvent);
}

static void UNUSED SetLinkPlayerObjectRange(u8 linkPlayerId, u8 dir)
{
    if (gLinkPlayerObjectEvents[linkPlayerId].active)
    {
        u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
        struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
        linkDirection(objEvent) = dir;
    }
}

static void UNUSED DestroyLinkPlayerObject(u8 linkPlayerId)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    if (objEvent->spriteId != MAX_SPRITES)
        DestroySprite(&gSprites[objEvent->spriteId]);
    linkPlayerObjEvent->active = 0;
    objEvent->active = 0;
}

// Returns the spriteId corresponding to this player.
static u8 GetSpriteForLinkedPlayer(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->spriteId;
}

static void GetLinkPlayerCoords(u8 linkPlayerId, u16 *x, u16 *y)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    *x = objEvent->currentCoords.x;
    *y = objEvent->currentCoords.y;
}

static u8 GetLinkPlayerFacingDirection(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return linkDirection(objEvent);
}

static u8 GetLinkPlayerElevation(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return objEvent->currentElevation;
}

static s32 UNUSED GetLinkPlayerObjectStepTimer(u8 linkPlayerId)
{
    u8 objEventId = gLinkPlayerObjectEvents[linkPlayerId].objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    return 16 - (s8)objEvent->directionSequenceIndex;
}

static u8 GetLinkPlayerIdAt(s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < MAX_LINK_PLAYERS; i++)
    {
        if (gLinkPlayerObjectEvents[i].active
         && (gLinkPlayerObjectEvents[i].movementMode == 0 || gLinkPlayerObjectEvents[i].movementMode == 2))
        {
            struct ObjectEvent *objEvent = &gObjectEvents[gLinkPlayerObjectEvents[i].objEventId];
            if (objEvent->currentCoords.x == x && objEvent->currentCoords.y == y)
                return i;
        }
    }
    return 4;
}

static void SetPlayerFacingDirection(u8 linkPlayerId, u8 facing)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];

    if (linkPlayerObjEvent->active)
    {
        if (facing > FACING_FORCED_RIGHT)
        {
            objEvent->triggerGroundEffectsOnMove = 1;
        }
        else
        {
            // This is a hack to split this code onto two separate lines, without declaring a local variable.
            // C++ style inline variables would be nice here.
            #define TEMP sLinkPlayerMovementModes[linkPlayerObjEvent->movementMode](linkPlayerObjEvent, objEvent, facing)

            sMovementStatusHandler[TEMP](linkPlayerObjEvent, objEvent);

            // Clean up the hack.
            #undef TEMP
        }
    }
}


static u8 MovementEventModeCB_Normal(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return sLinkPlayerFacingHandlers[dir](linkPlayerObjEvent, objEvent, dir);
}

static u8 MovementEventModeCB_Ignored(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return FACING_UP;
}

// Identical to MovementEventModeCB_Normal
static u8 MovementEventModeCB_Scripted(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return sLinkPlayerFacingHandlers[dir](linkPlayerObjEvent, objEvent, dir);
}

static bool8 FacingHandler_DoNothing(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    return FALSE;
}

static bool8 FacingHandler_DpadMovement(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    s16 x, y;

    linkDirection(objEvent) = FlipVerticalAndClearForced(dir, linkDirection(objEvent));
    ObjectEventMoveDestCoords(objEvent, linkDirection(objEvent), &x, &y);

    if (LinkPlayerGetCollision(linkPlayerObjEvent->objEventId, linkDirection(objEvent), x, y))
    {
        return FALSE;
    }
    else
    {
        objEvent->directionSequenceIndex = 16;
        ShiftObjectEventCoords(objEvent, x, y);
        ObjectEventUpdateElevation(objEvent);
        return TRUE;
    }
}

static bool8 FacingHandler_ForcedFacingChange(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent, u8 dir)
{
    linkDirection(objEvent) = FlipVerticalAndClearForced(dir, linkDirection(objEvent));
    return FALSE;
}

// This is called every time a free movement happens. Most of the time it's a No-Op.
static void MovementStatusHandler_EnterFreeMode(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FREE;
}

static void MovementStatusHandler_TryAdvanceScript(struct LinkPlayerObjectEvent *linkPlayerObjEvent, struct ObjectEvent *objEvent)
{
    objEvent->directionSequenceIndex--;
    linkPlayerObjEvent->movementMode = MOVEMENT_MODE_FROZEN;
    MoveCoords(linkDirection(objEvent), &objEvent->initialCoords.x, &objEvent->initialCoords.y);
    if (!objEvent->directionSequenceIndex)
    {
        ShiftStillObjectEventCoords(objEvent);
        linkPlayerObjEvent->movementMode = MOVEMENT_MODE_SCRIPTED;
    }
}

// Flip Up/Down facing codes. If newFacing doesn't specify a direction, default
// to oldFacing. Note that this clears also the "FORCED" part of the facing code,
// even for Left/Right codes.
static u8 FlipVerticalAndClearForced(u8 newFacing, u8 oldFacing)
{
    switch (newFacing)
    {
    case FACING_UP:
    case FACING_FORCED_UP:
        return DIR_NORTH;
    case FACING_DOWN:
    case FACING_FORCED_DOWN:
        return DIR_SOUTH;
    case FACING_LEFT:
    case FACING_FORCED_LEFT:
        return DIR_WEST;
    case FACING_RIGHT:
    case FACING_FORCED_RIGHT:
        return DIR_EAST;
    }
    return oldFacing;
}

static u8 LinkPlayerGetCollision(u8 selfObjEventId, u8 direction, s16 x, s16 y)
{
    u8 i;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (i != selfObjEventId)
        {
            if ((gObjectEvents[i].currentCoords.x == x && gObjectEvents[i].currentCoords.y == y)
             || (gObjectEvents[i].previousCoords.x == x && gObjectEvents[i].previousCoords.y == y))
            {
                return 1;
            }
        }
    }
    return MapGridGetCollisionAt(x, y);
}

static void CreateLinkPlayerSprite(u8 linkPlayerId, u8 gameVersion)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[linkPlayerId];
    u8 objEventId = linkPlayerObjEvent->objEventId;
    struct ObjectEvent *objEvent = &gObjectEvents[objEventId];
    struct Sprite *sprite;

    if (linkPlayerObjEvent->active)
    {
        switch (gameVersion)
        {
        case VERSION_FIRE_RED:
        case VERSION_LEAF_GREEN:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetFRLGAvatarGraphicsIdByGender(linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_RUBY:
        case VERSION_SAPPHIRE:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetRSAvatarGraphicsIdByGender(linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        case VERSION_EMERALD:
            objEvent->spriteId = CreateObjectGraphicsSprite(GetRivalAvatarGraphicsIdByStateIdAndGender(PLAYER_AVATAR_STATE_NORMAL, linkGender(objEvent)), SpriteCB_LinkPlayer, 0, 0, 0);
            break;
        }

        sprite = &gSprites[objEvent->spriteId];
        sprite->coordOffsetEnabled = TRUE;
        sprite->data[0] = linkPlayerId;
        objEvent->triggerGroundEffectsOnMove = 0;
    }
}

static void SpriteCB_LinkPlayer(struct Sprite *sprite)
{
    struct LinkPlayerObjectEvent *linkPlayerObjEvent = &gLinkPlayerObjectEvents[sprite->data[0]];
    struct ObjectEvent *objEvent = &gObjectEvents[linkPlayerObjEvent->objEventId];
    sprite->x = objEvent->initialCoords.x;
    sprite->y = objEvent->initialCoords.y;
    SetObjectSubpriorityByElevation(objEvent->previousElevation, sprite, 1);
    sprite->oam.priority = ElevationToPriority(objEvent->previousElevation);

    if (linkPlayerObjEvent->movementMode == MOVEMENT_MODE_FREE)
        StartSpriteAnim(sprite, GetFaceDirectionAnimNum(linkDirection(objEvent)));
    else
        StartSpriteAnimIfDifferent(sprite, GetMoveDirectionAnimNum(linkDirection(objEvent)));

    UpdateObjectEventSpriteInvisibility(sprite, FALSE);
    if (objEvent->triggerGroundEffectsOnMove)
    {
        sprite->invisible = ((sprite->data[7] & 4) >> 2);
        sprite->data[7]++;
    }
}

void UpdateFollowerPokemonGraphic(void)
{
    // Loaded in case the player changed the species of the Pokemon in the lead of the party.
    // If so, the following Pokemon needs to change.
    u16 leadMonGraphicId = GetMonData(&gPlayerParty[GetLeadMonNotFaintedIndex()], MON_DATA_SPECIES, NULL) + OBJ_EVENT_GFX_BULBASAUR - 1;
    struct ObjectEvent *follower = &gObjectEvents[gSaveBlock2Ptr->follower.objId];

    if(gSaveBlock2Ptr->follower.inProgress && leadMonGraphicId != gSaveBlock2Ptr->follower.graphicsId)
    {
        // Sets the follower's graphic data to the proper following Pokemon graphic data
        gSaveBlock2Ptr->follower.graphicsId = leadMonGraphicId;

        // Sets the current follower object's graphic data to the proper data.
        // Necessary because, without it, the follower's sprite won't change until entering a loading zone.
        follower->graphicsId = leadMonGraphicId;

        // Specifically for Pokemon Center, if lead Pokemon is revived, deletes old follower and creates new one
        if(gSpecialVar_Unused_0x8014 == 1)
        {
            u8 newSpriteId;
            struct ObjectEventTemplate clone;
            struct ObjectEvent backupFollower = *follower;
            backupFollower.graphicsId = gSaveBlock2Ptr->follower.graphicsId;
            DestroySprite(&gSprites[gObjectEvents[gSaveBlock2Ptr->follower.objId].spriteId]);
            RemoveObjectEvent(&gObjectEvents[gSaveBlock2Ptr->follower.objId]);

            clone = *GetObjectEventTemplateByLocalIdAndMap(gSaveBlock2Ptr->follower.map.id, gSaveBlock2Ptr->follower.map.number, gSaveBlock2Ptr->follower.map.group);
            clone.graphicsId = gSaveBlock2Ptr->follower.graphicsId;;
            gSaveBlock2Ptr->follower.objId = TrySpawnObjectEventTemplate(&clone, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup, clone.x, clone.y);

            follower = &gObjectEvents[gSaveBlock2Ptr->follower.objId];
            newSpriteId = follower->spriteId;
            *follower = backupFollower;
            follower->spriteId = newSpriteId;
            MoveObjectEventToMapCoords(follower, follower->currentCoords.x, follower->currentCoords.y);
            ObjectEventTurn(follower, follower->facingDirection);
            gSpecialVar_Unused_0x8014 = 0;
        }
    }
}

static void SparkleCallback(struct Sprite *sprite)
{    
    if (++sprite->data[0] >= 19)
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

static void BigSparkleCallback(struct Sprite *sprite)
{   
    if (sprite->data[0] % 2 == 0)
    {
        switch(sprite->data[7])
        {
            // North Sparkle
            case 0:
                sprite->x++;
                break;
            // NorthEast Sparkle
            case 1:
                if (sprite->data[0] % 4 == 0)
                    sprite->y++;
                else
                    sprite->x++;
                break;
            // East sparkle
            case 2:
                sprite->y++;
                break;
            // SouthEast Sparkle
            case 3:
                if (sprite->data[0] % 4 == 0)
                    sprite->y++;
                else
                    sprite->x--;
                break;
            // South Sparkle
            case 4:
                sprite->x--;
                break;
            // SouthWest Sparkle
            case 5:
                if (sprite->data[0] % 4 == 0)
                    sprite->y--;
                else
                    sprite->x--;
                break;
            // West Sparkle
            case 6:
                sprite->y--;
                break;
            // NorthWest Sparkle
            case 7:
                if (sprite->data[0] % 4 == 0)
                    sprite->y--;
                else
                    sprite->x++;
                break;
        }
    }

    if (++sprite->data[0] >= 19)
    {
        FreeSpriteOamMatrix(sprite);
        DestroySprite(sprite);
    }
}

bool8 IsBigSprite(u16 graphicsId)
{
    switch(graphicsId)
    {
        case OBJ_EVENT_GFX_STEELIX:
        case OBJ_EVENT_GFX_LUGIA_FOLLOWER:
        case OBJ_EVENT_GFX_HOOH_FOLLOWER:
        case OBJ_EVENT_GFX_WAILORD:
        case OBJ_EVENT_GFX_DIALGA:
        case OBJ_EVENT_GFX_PALKIA:
        case OBJ_EVENT_GFX_REGIGIGAS:
        case OBJ_EVENT_GFX_GIRATINA_NORMAL:
        case OBJ_EVENT_GFX_ARCEUS_NORMAL:
            return TRUE;
        default:
            return FALSE;
    }
}

static void SparklePokeballCallback(struct Sprite *sprite)
{    
    sprite->data[0]++;

    if (sprite->data[0] >= 10)
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        struct ObjectEvent *follower = &gObjectEvents[gSaveBlock2Ptr->follower.objId];
        s16 x = gSprites[follower->spriteId].x;
        s16 y = gSprites[follower->spriteId].y;
        u8 spriteId;
        u16 graphicsId;

        DestroySprite(sprite);

        gSprites[follower->spriteId].oam.priority = ElevationToPriority(follower->previousElevation);
        gSprites[gPlayerAvatar.spriteId].oam.priority = ElevationToPriority(player->previousElevation);
        player->fixedPriority = FALSE;

        // Shift the location of the sparkle, depending on which way the follower will be facing
        #ifndef POKEMON_EXPANSION
        if (gSaveBlock2Ptr->follower.graphicsId > OBJ_EVENT_GFX_CELEBI) // Gen 3+ OBJ_EVENT_GFX constants are 25 too high due to OLD_UNOWN constants.
            graphicsId = gSaveBlock2Ptr->follower.graphicsId - OBJ_EVENT_GFX_BULBASAUR - 25;
        else
        #endif
            graphicsId = gSaveBlock2Ptr->follower.graphicsId - OBJ_EVENT_GFX_BULBASAUR;

        switch(gObjectEvents[gPlayerAvatar.objectEventId].facingDirection)
        {
            case DIR_SOUTH:
                x -= 16 - FollowerSparkleCoords[graphicsId][0];
                if (IsBigSprite(follower->graphicsId))
                    x -= 16;

                y += 16 - FollowerSparkleCoords[graphicsId][1];

                break;
            case DIR_NORTH:
                x -= 16 - FollowerSparkleCoords[graphicsId][2];
                if (IsBigSprite(follower->graphicsId))
                    x -= 16;

                y += 16 - FollowerSparkleCoords[graphicsId][3];

                break;
            case DIR_EAST:
                x += 7 - FollowerSparkleCoords[graphicsId][4]; // 7 looks better than 8
                if (IsBigSprite(follower->graphicsId))
                    x += 16;

                y += 16 - FollowerSparkleCoords[graphicsId][5];

                break;
            case DIR_WEST:
                x -= 8 - FollowerSparkleCoords[graphicsId][4];
                if (IsBigSprite(follower->graphicsId))
                    x -= 16;

                y += 16 - FollowerSparkleCoords[graphicsId][5];

                break;
        }

        if (IsBigSprite(follower->graphicsId))
        {
            // North sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 0);
            }

            // NorthEast sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 1;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 1);
            }

            // East sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 2;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 2);
            }

            // SouthEast sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 3;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 3);
            }

            // South sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 4;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 4);
            }

            // SouthWest sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 5;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 5);
            }

            // West sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 6;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 6);
            }

            // NorthWest sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &BigSparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].data[7] = 7;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 7);
            }
        }
        else
        {
            // North sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 0);
            }

            // NorthEast sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 1);
            }

            // East sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 2);
            }

            // SouthEast sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 3);
            }

            // South sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 4);
            }

            // SouthWest sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 5);
            }

            // West sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 6);
            }

            // NorthWest sparkle
            spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_EXPANDING_SPARKLE, &SparkleCallback, x, y, 0);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].coordOffsetEnabled = TRUE;
                gSprites[spriteId].oam.priority = 1;
                gSprites[spriteId].data[0] = 0;
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_NORMAL;
                InitSpriteAffineAnim(&gSprites[spriteId]);
                StartSpriteAffineAnim(&gSprites[spriteId], 7);
            }
        }
    }
}

void FollowerPokeballSparkle(void)
{
    if (gObjectEvents[gSaveBlock2Ptr->follower.objId].invisible == TRUE && gSaveBlock2Ptr->follower.comeOutDoorStairs == 0 && !(gPlayerAvatar.flags & PLAYER_AVATAR_FLAG_UNDERWATER) && gSaveBlock2Ptr->follower.inProgress)
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        struct ObjectEvent *follower = &gObjectEvents[gSaveBlock2Ptr->follower.objId];
        s16 x = player->currentCoords.x;
        s16 y = player->currentCoords.y;
        u8 spriteId;

        switch(player->facingDirection)
        {
            case DIR_SOUTH:
                SetSpritePosToOffsetMapCoords(&x, &y, 8, 4);
                gSprites[follower->spriteId].y = y - 4;
                break;
            case DIR_NORTH:
                SetSpritePosToOffsetMapCoords(&x, &y, 8, 0);
                gSprites[follower->spriteId].y = y;
                break;
            case DIR_EAST:
            case DIR_WEST:
                SetSpritePosToOffsetMapCoords(&x, &y, 8, 8);
                gSprites[follower->spriteId].y = y - 8;
                break;
        }    
        gSprites[follower->spriteId].x = x;

        switch(GetMonData(&gPlayerParty[GetLeadMonNotFaintedIndex()], MON_DATA_POKEBALL))
        {
            case ITEM_MASTER_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MASTER_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_ULTRA_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_ULTRA_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_GREAT_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_GREAT_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_SAFARI_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_SAFARI_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_NET_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_NET_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_DIVE_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_DIVE_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_NEST_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_NEST_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_REPEAT_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_REPEAT_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_TIMER_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_TIMER_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_LUXURY_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_LUXURY_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_PREMIER_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_PREMIER_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            #ifdef ITEM_EXPANSION
            case ITEM_HEAL_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_HEAL_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_DUSK_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_DUSK_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_QUICK_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_QUICK_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_LEVEL_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_LEVEL_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_LURE_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_LURE_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_MOON_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MOON_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_FRIEND_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_FRIEND_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_LOVE_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_LOVE_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_FAST_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_FAST_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_HEAVY_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_HEAVY_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_DREAM_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_DREAM_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_SPORT_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_SPORT_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_PARK_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_PARK_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            case ITEM_CHERISH_BALL:
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_CHERISH_BALL, &SparklePokeballCallback, x, y, 2);
                break;
            #endif
            default: // PokeBall
                spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_ITEM_BALL, &SparklePokeballCallback, x, y, 2);
                break;
        }

        if (spriteId != MAX_SPRITES)
        {
            gSprites[spriteId].coordOffsetEnabled = TRUE;
            gSprites[spriteId].oam.priority = 2;
            gSprites[spriteId].data[0] = 0;
        }

        follower->currentCoords.x = player->currentCoords.x;
        follower->currentCoords.y = player->currentCoords.y;
        follower->facingDirection = player->facingDirection;

        gSprites[follower->spriteId].animNum = player->facingDirection - 1;

        if (player->facingDirection == DIR_NORTH)
        {
            gSprites[follower->spriteId].oam.priority = 0;
            gSprites[follower->spriteId].subpriority = 0;
            gSprites[gPlayerAvatar.spriteId].oam.priority = 1;
            gSprites[gPlayerAvatar.spriteId].subpriority = 1; 
        }
        else
        {
            gSprites[follower->spriteId].oam.priority = 1;
            gSprites[follower->spriteId].subpriority = 1;
            gSprites[gPlayerAvatar.spriteId].oam.priority = 0;
            gSprites[gPlayerAvatar.spriteId].subpriority = 0; 
        }
        player->fixedPriority = TRUE;
        gPlayerAvatar.preventStep = TRUE;

        SeekSpriteAnim(&gSprites[follower->spriteId], 0);        
        ObjectEventForceSetHeldMovement(follower, MOVEMENT_ACTION_FOLLOWING_POKEMON_GROW);
    }
}

void FollowerIntoPokeball(void)
{
    if (gObjectEvents[gSaveBlock2Ptr->follower.objId].invisible == FALSE && gSaveBlock2Ptr->follower.inProgress)
    {
        gSaveBlock2Ptr->follower.comeOutDoorStairs = 0;
        gPlayerAvatar.preventStep = TRUE;
        ObjectEventForceSetHeldMovement(&gObjectEvents[gSaveBlock2Ptr->follower.objId], MOVEMENT_ACTION_FOLLOWING_POKEMON_SHRINK);
        gSpecialVar_Unused_0x8014 = 1;
    }
}
