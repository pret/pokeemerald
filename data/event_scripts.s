#include "config/general.h"
#include "config/battle.h"
#include "config/item.h"
#include "constants/global.h"
#include "constants/apprentice.h"
#include "constants/apricorn_tree.h"
#include "constants/battle.h"
#include "constants/battle_arena.h"
#include "constants/battle_dome.h"
#include "constants/battle_factory.h"
#include "constants/battle_frontier.h"
#include "constants/battle_palace.h"
#include "constants/battle_pike.h"
#include "constants/battle_pyramid.h"
#include "constants/battle_special.h"
#include "constants/battle_tent.h"
#include "constants/battle_tower.h"
#include "constants/berry.h"
#include "constants/cable_club.h"
#include "constants/coins.h"
#include "constants/comparison_operators.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/difficulty.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/fame_checker.h"
#include "constants/field_effects.h"
#include "constants/field_move.h"
#include "constants/field_poison.h"
#include "constants/field_specials.h"
#include "constants/field_tasks.h"
#include "constants/field_weather.h"
#include "constants/flags.h"
#include "constants/follower_npc.h"
#include "constants/frontier_util.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/mass_outbreak.h"
#include "constants/mauville_old_man.h"
#include "constants/metatile_labels.h"
#include "constants/move_relearner.h"
#include "constants/moves.h"
#include "constants/mystery_gift.h"
#include "constants/party_menu.h"
#include "constants/pokeball.h"
#include "constants/pokedex.h"
#include "constants/pokemon.h"
#include "constants/pokemon_size_record.h"
#include "constants/random_mon_generation.h"
#include "constants/rtc.h"
#include "constants/roulette.h"
#include "constants/script_menu.h"
#include "constants/seagallop.h"
#include "constants/secret_bases.h"
#include "constants/siirtc.h"
#include "constants/songs.h"
#include "constants/sound.h"
#include "constants/species.h"
#include "constants/trade.h"
#include "constants/trainer_hill.h"
#include "constants/trainer_tower.h"
#include "constants/trainers.h"
#include "constants/trainer_card.h"
#include "constants/tv.h"
#include "constants/union_room.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/speaker_names.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.set ALLOCATE_SCRIPT_CMD_TABLE, 1
	.include "data/script_cmd_table.inc"

.align 2
gSpecialVars::
	.4byte gSpecialVar_0x8000
	.4byte gSpecialVar_0x8001
	.4byte gSpecialVar_0x8002
	.4byte gSpecialVar_0x8003
	.4byte gSpecialVar_0x8004
	.4byte gSpecialVar_0x8005
	.4byte gSpecialVar_0x8006
	.4byte gSpecialVar_0x8007
	.4byte gSpecialVar_0x8008
	.4byte gSpecialVar_0x8009
	.4byte gSpecialVar_0x800A
	.4byte gSpecialVar_0x800B
	.4byte gSpecialVar_Facing
	.4byte gSpecialVar_Result
	.4byte gSpecialVar_ItemId
	.4byte gSpecialVar_LastTalked
	.4byte gSpecialVar_ContestRank
	.4byte gSpecialVar_ContestCategory
	.4byte gSpecialVar_MonBoxId
	.4byte gSpecialVar_MonBoxPos
	.4byte gSpecialVar_Unused_0x8014
	.4byte gTrainerBattleParameter + 2 // gTrainerBattleParameter.params.opponentA

	.purgem def_special
	.set ALLOCATE_SPECIAL_TABLE, 1
	.include "data/specials.inc"

gStdScripts::
	.4byte Std_ObtainItem              @ STD_OBTAIN_ITEM
	.4byte Std_FindItem                @ STD_FIND_ITEM
	.4byte Std_MsgboxNPC               @ MSGBOX_NPC
	.4byte Std_MsgboxSign              @ MSGBOX_SIGN
	.4byte Std_MsgboxDefault           @ MSGBOX_DEFAULT
	.4byte Std_MsgboxYesNo             @ MSGBOX_YESNO
	.4byte Std_MsgboxAutoclose         @ MSGBOX_AUTOCLOSE
	.4byte Std_ObtainDecoration        @ STD_OBTAIN_DECORATION
	.4byte Std_RegisteredInMatchCall   @ STD_REGISTER_MATCH_CALL
	.4byte Std_MsgboxGetPoints         @ MSGBOX_GETPOINTS
	.4byte Std_MsgboxPokenav           @ MSGBOX_POKENAV
	.4byte Std_PutItemAway             @ STD_PUT_ITEM_AWAY
	.4byte Std_ReceivedItem            @ STD_RECEIVED_ITEM
gStdScripts_End::


	.include "data/maps/PetalburgCity/scripts.inc"
	.include "data/maps/SlateportCity/scripts.inc"
	.include "data/maps/MauvilleCity/scripts.inc"
	.include "data/maps/RustboroCity/scripts.inc"
	.include "data/maps/FortreeCity/scripts.inc"
	.include "data/maps/LilycoveCity/scripts.inc"
	.include "data/maps/MossdeepCity/scripts.inc"
	.include "data/maps/SootopolisCity/scripts.inc"
	.include "data/maps/EverGrandeCity/scripts.inc"
	.include "data/maps/LittlerootTown/scripts.inc"
	.include "data/maps/OldaleTown/scripts.inc"
	.include "data/maps/DewfordTown/scripts.inc"
	.include "data/maps/LavaridgeTown/scripts.inc"
	.include "data/maps/FallarborTown/scripts.inc"
	.include "data/maps/VerdanturfTown/scripts.inc"
	.include "data/maps/PacifidlogTown/scripts.inc"
	.include "data/maps/Route101/scripts.inc"
	.include "data/maps/Route102/scripts.inc"
	.include "data/maps/Route103/scripts.inc"
	.include "data/maps/Route104/scripts.inc"
	.include "data/maps/Route105/scripts.inc"
	.include "data/maps/Route106/scripts.inc"
	.include "data/maps/Route107/scripts.inc"
	.include "data/maps/Route108/scripts.inc"
	.include "data/maps/Route109/scripts.inc"
	.include "data/maps/Route110/scripts.inc"
	.include "data/maps/Route111/scripts.inc"
	.include "data/maps/Route112/scripts.inc"
	.include "data/maps/Route113/scripts.inc"
	.include "data/maps/Route114/scripts.inc"
	.include "data/maps/Route115/scripts.inc"
	.include "data/maps/Route116/scripts.inc"
	.include "data/maps/Route117/scripts.inc"
	.include "data/maps/Route118/scripts.inc"
	.include "data/maps/Route119/scripts.inc"
	.include "data/maps/Route120/scripts.inc"
	.include "data/maps/Route121/scripts.inc"
	.include "data/maps/Route122/scripts.inc"
	.include "data/maps/Route123/scripts.inc"
	.include "data/maps/Route124/scripts.inc"
	.include "data/maps/Route125/scripts.inc"
	.include "data/maps/Route126/scripts.inc"
	.include "data/maps/Route127/scripts.inc"
	.include "data/maps/Route128/scripts.inc"
	.include "data/maps/Route129/scripts.inc"
	.include "data/maps/Route130/scripts.inc"
	.include "data/maps/Route131/scripts.inc"
	.include "data/maps/Route132/scripts.inc"
	.include "data/maps/Route133/scripts.inc"
	.include "data/maps/Route134/scripts.inc"
	.include "data/maps/Underwater_Route124/scripts.inc"
	.include "data/maps/Underwater_Route126/scripts.inc"
	.include "data/maps/Underwater_Route127/scripts.inc"
	.include "data/maps/Underwater_Route128/scripts.inc"
	.include "data/maps/Underwater_Route129/scripts.inc"
	.include "data/maps/Underwater_Route105/scripts.inc"
	.include "data/maps/Underwater_Route125/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_BrendansHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_MaysHouse_1F/scripts.inc"
	.include "data/maps/LittlerootTown_MaysHouse_2F/scripts.inc"
	.include "data/maps/LittlerootTown_ProfessorBirchsLab/scripts.inc"
	.include "data/maps/OldaleTown_House1/scripts.inc"
	.include "data/maps/OldaleTown_House2/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/OldaleTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/OldaleTown_Mart/scripts.inc"
	.include "data/maps/DewfordTown_House1/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/DewfordTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/DewfordTown_Gym/scripts.inc"
	.include "data/maps/DewfordTown_Hall/scripts.inc"
	.include "data/maps/DewfordTown_House2/scripts.inc"
	.include "data/maps/LavaridgeTown_HerbShop/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_Gym_B1F/scripts.inc"
	.include "data/maps/LavaridgeTown_House/scripts.inc"
	.include "data/maps/LavaridgeTown_Mart/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LavaridgeTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_Mart/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentLobby/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/FallarborTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FallarborTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FallarborTown_CozmosHouse/scripts.inc"
	.include "data/maps/FallarborTown_MoveRelearnersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentLobby/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentCorridor/scripts.inc"
	.include "data/maps/VerdanturfTown_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/VerdanturfTown_Mart/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/VerdanturfTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/VerdanturfTown_WandasHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_FriendshipRatersHouse/scripts.inc"
	.include "data/maps/VerdanturfTown_House/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PacifidlogTown_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PacifidlogTown_House1/scripts.inc"
	.include "data/maps/PacifidlogTown_House2/scripts.inc"
	.include "data/maps/PacifidlogTown_House3/scripts.inc"
	.include "data/maps/PacifidlogTown_House4/scripts.inc"
	.include "data/maps/PacifidlogTown_House5/scripts.inc"
	.include "data/maps/PetalburgCity_WallysHouse/scripts.inc"
	.include "data/maps/PetalburgCity_Gym/scripts.inc"
	.include "data/maps/PetalburgCity_House1/scripts.inc"
	.include "data/maps/PetalburgCity_House2/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/PetalburgCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/PetalburgCity_Mart/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_1F/scripts.inc"
	.include "data/maps/SlateportCity_SternsShipyard_2F/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentLobby/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentCorridor/scripts.inc"
	.include "data/maps/SlateportCity_BattleTentBattleRoom/scripts.inc"
	.include "data/maps/SlateportCity_NameRatersHouse/scripts.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc"
	.include "data/maps/SlateportCity_Harbor/scripts.inc"
	.include "data/maps/SlateportCity_House/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SlateportCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SlateportCity_Mart/scripts.inc"
	.include "data/maps/MauvilleCity_Gym/scripts.inc"
	.include "data/maps/MauvilleCity_BikeShop/scripts.inc"
	.include "data/maps/MauvilleCity_House1/scripts.inc"
	.include "data/maps/MauvilleCity_GameCorner/scripts.inc"
	.include "data/maps/MauvilleCity_House2/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MauvilleCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MauvilleCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_1F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_2F/scripts.inc"
	.include "data/maps/RustboroCity_DevonCorp_3F/scripts.inc"
	.include "data/maps/RustboroCity_Gym/scripts.inc"
	.include "data/maps/RustboroCity_PokemonSchool/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/RustboroCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/RustboroCity_Mart/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat1_2F/scripts.inc"
	.include "data/maps/RustboroCity_House1/scripts.inc"
	.include "data/maps/RustboroCity_CuttersHouse/scripts.inc"
	.include "data/maps/RustboroCity_House2/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_1F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_2F/scripts.inc"
	.include "data/maps/RustboroCity_Flat2_3F/scripts.inc"
	.include "data/maps/RustboroCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House1/scripts.inc"
	.include "data/maps/FortreeCity_Gym/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/FortreeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/FortreeCity_Mart/scripts.inc"
	.include "data/maps/FortreeCity_House2/scripts.inc"
	.include "data/maps/FortreeCity_House3/scripts.inc"
	.include "data/maps/FortreeCity_House4/scripts.inc"
	.include "data/maps/FortreeCity_House5/scripts.inc"
	.include "data/maps/FortreeCity_DecorationShop/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_1F/scripts.inc"
	.include "data/maps/LilycoveCity_CoveLilyMotel_2F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_1F/scripts.inc"
	.include "data/maps/LilycoveCity_LilycoveMuseum_2F/scripts.inc"
	.include "data/maps/LilycoveCity_ContestLobby/scripts.inc"
	.include "data/maps/LilycoveCity_ContestHall/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/LilycoveCity_UnusedMart/scripts.inc"
	.include "data/maps/LilycoveCity_PokemonTrainerFanClub/scripts.inc"
	.include "data/maps/LilycoveCity_Harbor/scripts.inc"
	.include "data/maps/LilycoveCity_MoveDeletersHouse/scripts.inc"
	.include "data/maps/LilycoveCity_House1/scripts.inc"
	.include "data/maps/LilycoveCity_House2/scripts.inc"
	.include "data/maps/LilycoveCity_House3/scripts.inc"
	.include "data/maps/LilycoveCity_House4/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_1F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_2F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_3F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_4F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStore_5F/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreRooftop/scripts.inc"
	.include "data/maps/LilycoveCity_DepartmentStoreElevator/scripts.inc"
	.include "data/maps/MossdeepCity_Gym/scripts.inc"
	.include "data/maps/MossdeepCity_House1/scripts.inc"
	.include "data/maps/MossdeepCity_House2/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_Mart/scripts.inc"
	.include "data/maps/MossdeepCity_House3/scripts.inc"
	.include "data/maps/MossdeepCity_StevensHouse/scripts.inc"
	.include "data/maps/MossdeepCity_House4/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_1F/scripts.inc"
	.include "data/maps/MossdeepCity_SpaceCenter_2F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_1F/scripts.inc"
	.include "data/maps/MossdeepCity_GameCorner_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_1F/scripts.inc"
	.include "data/maps/SootopolisCity_Gym_B1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/SootopolisCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/SootopolisCity_Mart/scripts.inc"
	.include "data/maps/SootopolisCity_House1/scripts.inc"
	.include "data/maps/SootopolisCity_House2/scripts.inc"
	.include "data/maps/SootopolisCity_House3/scripts.inc"
	.include "data/maps/SootopolisCity_House4/scripts.inc"
	.include "data/maps/SootopolisCity_House5/scripts.inc"
	.include "data/maps/SootopolisCity_House6/scripts.inc"
	.include "data/maps/SootopolisCity_House7/scripts.inc"
	.include "data/maps/SootopolisCity_LotadAndSeedotHouse/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_1F/scripts.inc"
	.include "data/maps/SootopolisCity_MysteryEventsHouse_B1F/scripts.inc"
	.include "data/maps/EverGrandeCity_SidneysRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_PhoebesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_GlaciasRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_DrakesRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_ChampionsRoom/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall1/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall2/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall3/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall4/scripts.inc"
	.include "data/maps/EverGrandeCity_Hall5/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_HallOfFame/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_1F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonCenter_2F/scripts.inc"
	.include "data/maps/EverGrandeCity_PokemonLeague_2F/scripts.inc"
	.include "data/maps/Route104_MrBrineysHouse/scripts.inc"
	.include "data/maps/Route104_PrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route111_WinstrateFamilysHouse/scripts.inc"
	.include "data/maps/Route111_OldLadysRestStop/scripts.inc"
	.include "data/maps/Route112_CableCarStation/scripts.inc"
	.include "data/maps/MtChimney_CableCarStation/scripts.inc"
	.include "data/maps/Route114_FossilManiacsHouse/scripts.inc"
	.include "data/maps/Route114_FossilManiacsTunnel/scripts.inc"
	.include "data/maps/Route114_LanettesHouse/scripts.inc"
	.include "data/maps/Route116_TunnelersRestHouse/scripts.inc"
	.include "data/maps/Route117_PokemonDayCare/scripts.inc"
	.include "data/maps/Route121_SafariZoneEntrance/scripts.inc"
	.include "data/maps/MeteorFalls_1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_1F_2R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_1R/scripts.inc"
	.include "data/maps/MeteorFalls_B1F_2R/scripts.inc"
	.include "data/maps/RusturfTunnel/scripts.inc"
	.include "data/maps/Underwater_SootopolisCity/scripts.inc"
	.include "data/maps/DesertRuins/scripts.inc"
	.include "data/maps/GraniteCave_1F/scripts.inc"
	.include "data/maps/GraniteCave_B1F/scripts.inc"
	.include "data/maps/GraniteCave_B2F/scripts.inc"
	.include "data/maps/GraniteCave_StevensRoom/scripts.inc"
	.include "data/maps/PetalburgWoods/scripts.inc"
	.include "data/maps/MtChimney/scripts.inc"
	.include "data/maps/JaggedPass/scripts.inc"
	.include "data/maps/FieryPath/scripts.inc"
	.include "data/maps/MtPyre_1F/scripts.inc"
	.include "data/maps/MtPyre_2F/scripts.inc"
	.include "data/maps/MtPyre_3F/scripts.inc"
	.include "data/maps/MtPyre_4F/scripts.inc"
	.include "data/maps/MtPyre_5F/scripts.inc"
	.include "data/maps/MtPyre_6F/scripts.inc"
	.include "data/maps/MtPyre_Exterior/scripts.inc"
	.include "data/maps/MtPyre_Summit/scripts.inc"
	.include "data/maps/AquaHideout_1F/scripts.inc"
	.include "data/maps/AquaHideout_B1F/scripts.inc"
	.include "data/maps/AquaHideout_B2F/scripts.inc"
	.include "data/maps/Underwater_SeafloorCavern/scripts.inc"
	.include "data/maps/SeafloorCavern_Entrance/scripts.inc"
	.include "data/maps/SeafloorCavern_Room1/scripts.inc"
	.include "data/maps/SeafloorCavern_Room2/scripts.inc"
	.include "data/maps/SeafloorCavern_Room3/scripts.inc"
	.include "data/maps/SeafloorCavern_Room4/scripts.inc"
	.include "data/maps/SeafloorCavern_Room5/scripts.inc"
	.include "data/maps/SeafloorCavern_Room6/scripts.inc"
	.include "data/maps/SeafloorCavern_Room7/scripts.inc"
	.include "data/maps/SeafloorCavern_Room8/scripts.inc"
	.include "data/maps/SeafloorCavern_Room9/scripts.inc"
	.include "data/maps/CaveOfOrigin_Entrance/scripts.inc"
	.include "data/maps/CaveOfOrigin_1F/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap1/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap2/scripts.inc"
	.include "data/maps/CaveOfOrigin_UnusedRubySapphireMap3/scripts.inc"
	.include "data/maps/CaveOfOrigin_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_1F/scripts.inc"
	.include "data/maps/VictoryRoad_B1F/scripts.inc"
	.include "data/maps/VictoryRoad_B2F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideInnerRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideStairsRoom/scripts.inc"
	.include "data/maps/ShoalCave_LowTideLowerRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideEntranceRoom/scripts.inc"
	.include "data/maps/ShoalCave_HighTideInnerRoom/scripts.inc"
	.include "data/maps/NewMauville_Entrance/scripts.inc"
	.include "data/maps/NewMauville_Inside/scripts.inc"
	.include "data/maps/AbandonedShip_Deck/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_1F/scripts.inc"
	.include "data/maps/AbandonedShip_Corridors_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater1/scripts.inc"
	.include "data/maps/AbandonedShip_Room_B1F/scripts.inc"
	.include "data/maps/AbandonedShip_Rooms2_1F/scripts.inc"
	.include "data/maps/AbandonedShip_CaptainsOffice/scripts.inc"
	.include "data/maps/AbandonedShip_Underwater2/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorCorridors/scripts.inc"
	.include "data/maps/AbandonedShip_HiddenFloorRooms/scripts.inc"
	.include "data/maps/IslandCave/scripts.inc"
	.include "data/maps/AncientTomb/scripts.inc"
	.include "data/maps/Underwater_Route134/scripts.inc"
	.include "data/maps/Underwater_SealedChamber/scripts.inc"
	.include "data/maps/SealedChamber_OuterRoom/scripts.inc"
	.include "data/maps/SealedChamber_InnerRoom/scripts.inc"
	.include "data/maps/ScorchedSlab/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap1/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap2/scripts.inc"
	.include "data/maps/AquaHideout_UnusedRubyMap3/scripts.inc"
	.include "data/maps/SkyPillar_Entrance/scripts.inc"
	.include "data/maps/SkyPillar_Outside/scripts.inc"
	.include "data/maps/SkyPillar_1F/scripts.inc"
	.include "data/maps/SkyPillar_2F/scripts.inc"
	.include "data/maps/SkyPillar_3F/scripts.inc"
	.include "data/maps/SkyPillar_4F/scripts.inc"
	.include "data/maps/ShoalCave_LowTideIceRoom/scripts.inc"
	.include "data/maps/SkyPillar_5F/scripts.inc"
	.include "data/maps/SkyPillar_Top/scripts.inc"
	.include "data/maps/MagmaHideout_1F/scripts.inc"
	.include "data/maps/MagmaHideout_2F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_1R/scripts.inc"
	.include "data/maps/MagmaHideout_3F_2R/scripts.inc"
	.include "data/maps/MagmaHideout_4F/scripts.inc"
	.include "data/maps/MagmaHideout_3F_3R/scripts.inc"
	.include "data/maps/MagmaHideout_2F_3R/scripts.inc"
	.include "data/maps/MirageTower_1F/scripts.inc"
	.include "data/maps/MirageTower_2F/scripts.inc"
	.include "data/maps/MirageTower_3F/scripts.inc"
	.include "data/maps/MirageTower_4F/scripts.inc"
	.include "data/maps/DesertUnderpass/scripts.inc"
	.include "data/maps/ArtisanCave_B1F/scripts.inc"
	.include "data/maps/ArtisanCave_1F/scripts.inc"
	.include "data/maps/Underwater_MarineCave/scripts.inc"
	.include "data/maps/MarineCave_Entrance/scripts.inc"
	.include "data/maps/MarineCave_End/scripts.inc"
	.include "data/maps/TerraCave_Entrance/scripts.inc"
	.include "data/maps/TerraCave_End/scripts.inc"
	.include "data/maps/AlteringCave/scripts.inc"
	.include "data/maps/MeteorFalls_StevensCave/scripts.inc"
	.include "data/scripts/shared_secret_base.inc"
	.include "data/maps/BattleColosseum_2P/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/BattleColosseum_4P/scripts.inc"
	.include "data/maps/ContestHall/scripts.inc"
	.include "data/maps/InsideOfTruck/scripts.inc"
	.include "data/maps/SSTidalCorridor/scripts.inc"
	.include "data/maps/SSTidalLowerDeck/scripts.inc"
	.include "data/maps/SSTidalRooms/scripts.inc"
	.include "data/maps/BattlePyramidSquare01/scripts.inc"
	.include "data/maps/UnionRoom/scripts.inc"
	.include "data/maps/SafariZone_Northwest/scripts.inc"
	.include "data/maps/SafariZone_North/scripts.inc"
	.include "data/maps/SafariZone_Southwest/scripts.inc"
	.include "data/maps/SafariZone_South/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideWest/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerElevator/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom/scripts.inc"
	.include "data/maps/SouthernIsland_Exterior/scripts.inc"
	.include "data/maps/SouthernIsland_Interior/scripts.inc"
	.include "data/maps/SafariZone_RestHouse/scripts.inc"
	.include "data/maps/SafariZone_Northeast/scripts.inc"
	.include "data/maps/SafariZone_Southeast/scripts.inc"
	.include "data/maps/BattleFrontier_OutsideEast/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiPartnerRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidFloor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidTop/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleArenaBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryPreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleFactoryBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeThreePathRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomNormal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomFinal/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRoomWildMons/scripts.inc"
	.include "data/maps/BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/BattleFrontier_ExchangeServiceCorner/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge2/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge3/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge4/scripts.inc"
	.include "data/maps/BattleFrontier_ScottsHouse/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge5/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge6/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge7/scripts.inc"
	.include "data/maps/BattleFrontier_ReceptionGate/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge8/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge9/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_1F/scripts.inc"
	.include "data/maps/BattleFrontier_PokemonCenter_2F/scripts.inc"
	.include "data/maps/BattleFrontier_Mart/scripts.inc"
	.include "data/maps/FarawayIsland_Entrance/scripts.inc"
	.include "data/maps/FarawayIsland_Interior/scripts.inc"
	.include "data/maps/BirthIsland_Exterior/scripts.inc"
	.include "data/maps/BirthIsland_Harbor/scripts.inc"
	.include "data/maps/TrainerHill_Entrance/scripts.inc"
	.include "data/maps/TrainerHill_1F/scripts.inc"
	.include "data/maps/TrainerHill_2F/scripts.inc"
	.include "data/maps/TrainerHill_3F/scripts.inc"
	.include "data/maps/TrainerHill_4F/scripts.inc"
	.include "data/maps/TrainerHill_Roof/scripts.inc"
	.include "data/maps/NavelRock_Exterior/scripts.inc"
	.include "data/maps/NavelRock_Harbor/scripts.inc"
	.include "data/maps/NavelRock_Entrance/scripts.inc"
	.include "data/maps/NavelRock_B1F/scripts.inc"
	.include "data/maps/NavelRock_Fork/scripts.inc"
	.include "data/maps/NavelRock_Up1/scripts.inc"
	.include "data/maps/NavelRock_Up2/scripts.inc"
	.include "data/maps/NavelRock_Up3/scripts.inc"
	.include "data/maps/NavelRock_Up4/scripts.inc"
	.include "data/maps/NavelRock_Top/scripts.inc"
	.include "data/maps/NavelRock_Down01/scripts.inc"
	.include "data/maps/NavelRock_Down02/scripts.inc"
	.include "data/maps/NavelRock_Down03/scripts.inc"
	.include "data/maps/NavelRock_Down04/scripts.inc"
	.include "data/maps/NavelRock_Down05/scripts.inc"
	.include "data/maps/NavelRock_Down06/scripts.inc"
	.include "data/maps/NavelRock_Down07/scripts.inc"
	.include "data/maps/NavelRock_Down08/scripts.inc"
	.include "data/maps/NavelRock_Down09/scripts.inc"
	.include "data/maps/NavelRock_Down10/scripts.inc"
	.include "data/maps/NavelRock_Down11/scripts.inc"
	.include "data/maps/NavelRock_Bottom/scripts.inc"
	.include "data/maps/TrainerHill_Elevator/scripts.inc"
	.include "data/maps/Route104_Prototype/scripts.inc"
	.include "data/maps/Route104_PrototypePrettyPetalFlowerShop/scripts.inc"
	.include "data/maps/Route109_SeashoreHouse/scripts.inc"
	.include "data/maps/Route110_TrickHouseEntrance/scripts.inc"
	.include "data/maps/Route110_TrickHouseEnd/scripts.inc"
	.include "data/maps/Route110_TrickHouseCorridor/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle1/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle2/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle3/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle4/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle5/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle6/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle7/scripts.inc"
	.include "data/maps/Route110_TrickHousePuzzle8/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc"
	.include "data/maps/Route113_GlassWorkshop/scripts.inc"
	.include "data/maps/Route123_BerryMastersHouse/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_1F/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_2F/scripts.inc"
	.include "data/maps/Route119_House/scripts.inc"
	.include "data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc"

.if IS_FRLG

@ FRLG scripts
	.include "data/maps/BattleColosseum_2P_Frlg/scripts.inc"
	.include "data/maps/TradeCenter_Frlg/scripts.inc"
	.include "data/maps/RecordCorner_Frlg/scripts.inc"
	.include "data/maps/BattleColosseum_4P_Frlg/scripts.inc"
	.include "data/maps/UnionRoom_Frlg/scripts.inc"
	.include "data/maps/ViridianForest_Frlg/scripts.inc"
	.include "data/maps/MtMoon_1F_Frlg/scripts.inc"
	.include "data/maps/MtMoon_B1F_Frlg/scripts.inc"
	.include "data/maps/MtMoon_B2F_Frlg/scripts.inc"
	.include "data/maps/SSAnne_Exterior_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Corridor_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Corridor_Frlg/scripts.inc"
	.include "data/maps/SSAnne_3F_Corridor_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Corridor_Frlg/scripts.inc"
	.include "data/maps/SSAnne_Deck_Frlg/scripts.inc"
	.include "data/maps/SSAnne_Kitchen_Frlg/scripts.inc"
	.include "data/maps/SSAnne_CaptainsOffice_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room1_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room2_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room3_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room4_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room5_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room7_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room1_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room2_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room3_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room4_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room5_Frlg/scripts.inc"
	.include "data/maps/SSAnne_2F_Room6_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Room1_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Room2_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Room3_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Room4_Frlg/scripts.inc"
	.include "data/maps/SSAnne_B1F_Room5_Frlg/scripts.inc"
	.include "data/maps/SSAnne_1F_Room6_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_NorthEntrance_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_NorthSouthTunnel_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_SouthEntrance_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_WestEntrance_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_EastWestTunnel_Frlg/scripts.inc"
	.include "data/maps/UndergroundPath_EastEntrance_Frlg/scripts.inc"
	.include "data/maps/DiglettsCave_NorthEntrance_Frlg/scripts.inc"
	.include "data/maps/DiglettsCave_B1F_Frlg/scripts.inc"
	.include "data/maps/DiglettsCave_SouthEntrance_Frlg/scripts.inc"
	.include "data/maps/VictoryRoad_1F_Frlg/scripts.inc"
	.include "data/maps/VictoryRoad_2F_Frlg/scripts.inc"
	.include "data/maps/VictoryRoad_3F_Frlg/scripts.inc"
	.include "data/maps/RocketHideout_B1F_Frlg/scripts.inc"
	.include "data/maps/RocketHideout_B2F_Frlg/scripts.inc"
	.include "data/maps/RocketHideout_B3F_Frlg/scripts.inc"
	.include "data/maps/RocketHideout_B4F_Frlg/scripts.inc"
	.include "data/maps/RocketHideout_Elevator_Frlg/scripts.inc"
	.include "data/maps/SilphCo_1F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_2F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_3F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_4F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_5F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_6F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_7F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_8F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_9F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_10F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_11F_Frlg/scripts.inc"
	.include "data/maps/SilphCo_Elevator_Frlg/scripts.inc"
	.include "data/maps/PokemonMansion_1F_Frlg/scripts.inc"
	.include "data/maps/PokemonMansion_2F_Frlg/scripts.inc"
	.include "data/maps/PokemonMansion_3F_Frlg/scripts.inc"
	.include "data/maps/PokemonMansion_B1F_Frlg/scripts.inc"
	.include "data/maps/SafariZone_Center_Frlg/scripts.inc"
	.include "data/maps/SafariZone_East_Frlg/scripts.inc"
	.include "data/maps/SafariZone_North_Frlg/scripts.inc"
	.include "data/maps/SafariZone_West_Frlg/scripts.inc"
	.include "data/maps/SafariZone_Center_RestHouse_Frlg/scripts.inc"
	.include "data/maps/SafariZone_East_RestHouse_Frlg/scripts.inc"
	.include "data/maps/SafariZone_North_RestHouse_Frlg/scripts.inc"
	.include "data/maps/SafariZone_West_RestHouse_Frlg/scripts.inc"
	.include "data/maps/SafariZone_SecretHouse_Frlg/scripts.inc"
	.include "data/maps/CeruleanCave_1F_Frlg/scripts.inc"
	.include "data/maps/CeruleanCave_2F_Frlg/scripts.inc"
	.include "data/maps/CeruleanCave_B1F_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_LoreleisRoom_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_BrunosRoom_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_AgathasRoom_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_LancesRoom_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_ChampionsRoom_Frlg/scripts.inc"
	.include "data/maps/PokemonLeague_HallOfFame_Frlg/scripts.inc"
	.include "data/maps/RockTunnel_1F_Frlg/scripts.inc"
	.include "data/maps/RockTunnel_B1F_Frlg/scripts.inc"
	.include "data/maps/SeafoamIslands_1F_Frlg/scripts.inc"
	.include "data/maps/SeafoamIslands_B1F_Frlg/scripts.inc"
	.include "data/maps/SeafoamIslands_B2F_Frlg/scripts.inc"
	.include "data/maps/SeafoamIslands_B3F_Frlg/scripts.inc"
	.include "data/maps/SeafoamIslands_B4F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_1F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_2F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_3F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_4F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_5F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_6F_Frlg/scripts.inc"
	.include "data/maps/PokemonTower_7F_Frlg/scripts.inc"
	.include "data/maps/PowerPlant_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B4F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_Exterior_Frlg/scripts.inc"
	.include "data/maps/MtEmber_SummitPath_1F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_SummitPath_2F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_SummitPath_3F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_Summit_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B5F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_1F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B1F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B2F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B3F_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B1F_Stairs_Frlg/scripts.inc"
	.include "data/maps/MtEmber_RubyPath_B2F_Stairs_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_BerryForest_Frlg/scripts.inc"
	.include "data/maps/FourIsland_IcefallCave_Entrance_Frlg/scripts.inc"
	.include "data/maps/FourIsland_IcefallCave_1F_Frlg/scripts.inc"
	.include "data/maps/FourIsland_IcefallCave_B1F_Frlg/scripts.inc"
	.include "data/maps/FourIsland_IcefallCave_Back_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_RocketWarehouse_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_1F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_B1F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_B2F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_B3F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_B4F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_DottedHole_SapphireRoom_Frlg/scripts.inc"
	.include "data/maps/SixIsland_PatternBush_Frlg/scripts.inc"
	.include "data/maps/SixIsland_AlteringCave_Frlg/scripts.inc"
	.include "data/maps/NavelRock_Exterior_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_1F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_2F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_3F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_4F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_5F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_6F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_7F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_8F_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_Roof_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_Lobby_Frlg/scripts.inc"
	.include "data/maps/TrainerTower_Elevator_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Entrance_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room1_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room2_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room3_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room4_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room5_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room6_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room7_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room8_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room9_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room10_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room11_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room12_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room13_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_LostCave_Room14_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_MoneanChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_LiptooChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_WeepthChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_DilfordChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_ScufibChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_RixyChamber_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_ViapoisChamber_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_DunsparceTunnel_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_SevaultCanyon_TanobyKey_Frlg/scripts.inc"
	.include "data/maps/NavelRock_1F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_Summit_Frlg/scripts.inc"
	.include "data/maps/NavelRock_Base_Frlg/scripts.inc"
	.include "data/maps/NavelRock_SummitPath_2F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_SummitPath_3F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_SummitPath_4F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_SummitPath_5F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B1F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B2F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B3F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B4F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B5F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B6F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B7F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B8F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B9F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B10F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_BasePath_B11F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_B1F_Frlg/scripts.inc"
	.include "data/maps/NavelRock_Fork_Frlg/scripts.inc"
	.include "data/maps/BirthIsland_Exterior_Frlg/scripts.inc"
	.include "data/maps/OneIsland_KindleRoad_EmberSpa_Frlg/scripts.inc"
	.include "data/maps/BirthIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/NavelRock_Harbor_Frlg/scripts.inc"
	.include "data/maps/PalletTown_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_Frlg/scripts.inc"
	.include "data/maps/PewterCity_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_Frlg/scripts.inc"
	.include "data/maps/IndigoPlateau_Exterior_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_Connection_Frlg/scripts.inc"
	.include "data/maps/OneIsland_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_Frlg/scripts.inc"
	.include "data/maps/FourIsland_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_Frlg/scripts.inc"
	.include "data/maps/SixIsland_Frlg/scripts.inc"
	.include "data/maps/Route1_Frlg/scripts.inc"
	.include "data/maps/Route2_Frlg/scripts.inc"
	.include "data/maps/Route3_Frlg/scripts.inc"
	.include "data/maps/Route4_Frlg/scripts.inc"
	.include "data/maps/Route5_Frlg/scripts.inc"
	.include "data/maps/Route6_Frlg/scripts.inc"
	.include "data/maps/Route7_Frlg/scripts.inc"
	.include "data/maps/Route8_Frlg/scripts.inc"
	.include "data/maps/Route9_Frlg/scripts.inc"
	.include "data/maps/Route10_Frlg/scripts.inc"
	.include "data/maps/Route11_Frlg/scripts.inc"
	.include "data/maps/Route12_Frlg/scripts.inc"
	.include "data/maps/Route13_Frlg/scripts.inc"
	.include "data/maps/Route14_Frlg/scripts.inc"
	.include "data/maps/Route15_Frlg/scripts.inc"
	.include "data/maps/Route16_Frlg/scripts.inc"
	.include "data/maps/Route17_Frlg/scripts.inc"
	.include "data/maps/Route18_Frlg/scripts.inc"
	.include "data/maps/Route19_Frlg/scripts.inc"
	.include "data/maps/Route20_Frlg/scripts.inc"
	.include "data/maps/Route21_North_Frlg/scripts.inc"
	.include "data/maps/Route21_South_Frlg/scripts.inc"
	.include "data/maps/Route22_Frlg/scripts.inc"
	.include "data/maps/Route23_Frlg/scripts.inc"
	.include "data/maps/Route24_Frlg/scripts.inc"
	.include "data/maps/Route25_Frlg/scripts.inc"
	.include "data/maps/OneIsland_KindleRoad_Frlg/scripts.inc"
	.include "data/maps/OneIsland_TreasureBeach_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_CapeBrink_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_BondBridge_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_Port_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_ResortGorgeous_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_WaterLabyrinth_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_Meadow_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_MemorialPillar_Frlg/scripts.inc"
	.include "data/maps/SixIsland_OutcastIsland_Frlg/scripts.inc"
	.include "data/maps/SixIsland_GreenPath_Frlg/scripts.inc"
	.include "data/maps/SixIsland_WaterPath_Frlg/scripts.inc"
	.include "data/maps/SixIsland_RuinValley_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TrainerTower_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_SevaultCanyon_Entrance_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_SevaultCanyon_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_TanobyRuins_Frlg/scripts.inc"
	.include "data/maps/PalletTown_PlayersHouse_1F_Frlg/scripts.inc"
	.include "data/maps/PalletTown_PlayersHouse_2F_Frlg/scripts.inc"
	.include "data/maps/PalletTown_RivalsHouse_Frlg/scripts.inc"
	.include "data/maps/PalletTown_ProfessorOaksLab_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_House_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_Gym_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_School_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_Mart_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/ViridianCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/PewterCity_Museum_1F_Frlg/scripts.inc"
	.include "data/maps/PewterCity_Museum_2F_Frlg/scripts.inc"
	.include "data/maps/PewterCity_Gym_Frlg/scripts.inc"
	.include "data/maps/PewterCity_Mart_Frlg/scripts.inc"
	.include "data/maps/PewterCity_House1_Frlg/scripts.inc"
	.include "data/maps/PewterCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/PewterCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/PewterCity_House2_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_House1_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_House2_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_House3_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_Gym_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_BikeShop_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_Mart_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_House4_Frlg/scripts.inc"
	.include "data/maps/CeruleanCity_House5_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_VolunteerPokemonHouse_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_House1_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_House2_Frlg/scripts.inc"
	.include "data/maps/LavenderTown_Mart_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_House1_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_PokemonFanClub_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_House2_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_Mart_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_Gym_Frlg/scripts.inc"
	.include "data/maps/VermilionCity_House3_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_1F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_2F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_3F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_4F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_5F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_Roof_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_DepartmentStore_Elevator_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Condominiums_1F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Condominiums_2F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Condominiums_3F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Condominiums_Roof_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Condominiums_RoofRoom_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_GameCorner_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_GameCorner_PrizeRoom_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Gym_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Restaurant_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_House1_Frlg/scripts.inc"
	.include "data/maps/CeladonCity_Hotel_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_SafariZone_Entrance_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_Mart_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_SafariZone_Office_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_Gym_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_House1_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_WardensHouse_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_House2_Frlg/scripts.inc"
	.include "data/maps/FuchsiaCity_House3_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_Gym_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonLab_Entrance_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonLab_Lounge_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonLab_ResearchRoom_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/CinnabarIsland_Mart_Frlg/scripts.inc"
	.include "data/maps/IndigoPlateau_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/IndigoPlateau_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_CopycatsHouse_1F_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_CopycatsHouse_2F_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_Dojo_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_Gym_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_House_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_Mart_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_MrPsychicsHouse_Frlg/scripts.inc"
	.include "data/maps/SaffronCity_PokemonTrainerFanClub_Frlg/scripts.inc"
	.include "data/maps/Route2_ViridianForest_SouthEntrance_Frlg/scripts.inc"
	.include "data/maps/Route2_House_Frlg/scripts.inc"
	.include "data/maps/Route2_EastBuilding_Frlg/scripts.inc"
	.include "data/maps/Route2_ViridianForest_NorthEntrance_Frlg/scripts.inc"
	.include "data/maps/Route4_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/Route4_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/Route5_PokemonDayCare_Frlg/scripts.inc"
	.include "data/maps/Route5_SouthEntrance_Frlg/scripts.inc"
	.include "data/maps/Route6_NorthEntrance_Frlg/scripts.inc"
	.include "data/maps/Route6_UnusedHouse_Frlg/scripts.inc"
	.include "data/maps/Route7_EastEntrance_Frlg/scripts.inc"
	.include "data/maps/Route8_WestEntrance_Frlg/scripts.inc"
	.include "data/maps/Route10_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/Route10_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/Route11_EastEntrance_1F_Frlg/scripts.inc"
	.include "data/maps/Route11_EastEntrance_2F_Frlg/scripts.inc"
	.include "data/maps/Route12_NorthEntrance_1F_Frlg/scripts.inc"
	.include "data/maps/Route12_NorthEntrance_2F_Frlg/scripts.inc"
	.include "data/maps/Route12_FishingHouse_Frlg/scripts.inc"
	.include "data/maps/Route15_WestEntrance_1F_Frlg/scripts.inc"
	.include "data/maps/Route15_WestEntrance_2F_Frlg/scripts.inc"
	.include "data/maps/Route16_House_Frlg/scripts.inc"
	.include "data/maps/Route16_NorthEntrance_1F_Frlg/scripts.inc"
	.include "data/maps/Route16_NorthEntrance_2F_Frlg/scripts.inc"
	.include "data/maps/Route18_EastEntrance_1F_Frlg/scripts.inc"
	.include "data/maps/Route18_EastEntrance_2F_Frlg/scripts.inc"
	.include "data/maps/Route22_NorthEntrance_Frlg/scripts.inc"
	.include "data/maps/Route25_SeaCottage_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_House_Room1_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_House_Room2_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_Mart_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/OneIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/OneIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/OneIsland_House1_Frlg/scripts.inc"
	.include "data/maps/OneIsland_House2_Frlg/scripts.inc"
	.include "data/maps/OneIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_JoyfulGameCorner_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_House_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_House1_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_Mart_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_House2_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_House3_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_House4_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_House5_Frlg/scripts.inc"
	.include "data/maps/FourIsland_PokemonDayCare_Frlg/scripts.inc"
	.include "data/maps/FourIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/FourIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/FourIsland_House1_Frlg/scripts.inc"
	.include "data/maps/FourIsland_LoreleisHouse_Frlg/scripts.inc"
	.include "data/maps/FourIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/FourIsland_House2_Frlg/scripts.inc"
	.include "data/maps/FourIsland_Mart_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_House1_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_House2_Frlg/scripts.inc"
	.include "data/maps/SixIsland_PokemonCenter_1F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_PokemonCenter_2F_Frlg/scripts.inc"
	.include "data/maps/SixIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/SixIsland_House_Frlg/scripts.inc"
	.include "data/maps/SixIsland_Mart_Frlg/scripts.inc"
	.include "data/maps/ThreeIsland_Harbor_Frlg/scripts.inc"
	.include "data/maps/FiveIsland_ResortGorgeous_House_Frlg/scripts.inc"
	.include "data/maps/TwoIsland_CapeBrink_House_Frlg/scripts.inc"
	.include "data/maps/SixIsland_WaterPath_House1_Frlg/scripts.inc"
	.include "data/maps/SixIsland_WaterPath_House2_Frlg/scripts.inc"
	.include "data/maps/SevenIsland_SevaultCanyon_House_Frlg/scripts.inc"

	.include "data/scripts/trainer_tower.inc"
	.include "data/scripts/fame_checker_frlg.inc"
	.include "data/text/fame_checker_frlg.inc"
	.include "data/scripts/item_ball_scripts_frlg.inc"
	.include "data/scripts/silphco_doors.inc"
	.include "data/scripts/move_tutors_frlg.inc"
	.include "data/scripts/cable_club_frlg.inc"
	.include "data/scripts/trainer_card_frlg.inc"
	.include "data/text/trainer_card_frlg.inc"
	.include "data/scripts/mystery_event_club.inc"
	.include "data/scripts/day_care_frlg.inc"
	.include "data/text/day_care_frlg.inc"
	.include "data/scripts/seagallop.inc"
	.include "data/scripts/static_pokemon.inc"
	.include "data/scripts/aide.inc"
	.include "data/scripts/pokemon_mansion.inc"
	.include "data/scripts/pokemon_league.inc"
	.include "data/scripts/route23.inc"
	.include "data/text/new_game_intro_frlg.inc"
	.include "data/scripts/trainers_frlg.inc"
	.include "data/text/trainers_frlg.inc"
	.include "data/text/ingame_trade_frlg.inc"
	.include "data/scripts/flavor_text.inc"
	.include "data/scripts/pkmn_center_nurse_frlg.inc"

.endif

	.include "data/scripts/std_msgbox.inc"
	.include "data/scripts/trainer_battle.inc"
	.include "data/scripts/new_game.inc"
	.include "data/scripts/hall_of_fame.inc"
	.include "data/scripts/hall_of_fame_frlg.inc"

	.include "data/scripts/config.inc"
	.include "data/scripts/debug.inc"

EventScript_WhiteOut::
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	goto EventScript_ResetMrBriney
	end

EventScript_AfterWhiteOutHeal::
	lockall
	msgbox gText_FirstShouldRestoreMonsHealth
	call EventScript_PkmnCenterNurse_TakeAndHealPkmn
	call_if_unset FLAG_DEFEATED_RUSTBORO_GYM, EventScript_AfterWhiteOutHealMsgPreFirstBoss
	call_if_set FLAG_DEFEATED_RUSTBORO_GYM, EventScript_AfterWhiteOutHealMsg
	applymovement VAR_LAST_TALKED, Movement_PkmnCenterNurse_Bow
	waitmovement 0
	fadedefaultbgm
	releaseall
	end

EventScript_AfterWhiteOutHealMsgPreFirstBoss::
	msgbox gText_MonsHealedShouldBuyPotions
	return

EventScript_AfterWhiteOutHealMsg::
	msgbox gText_MonsHealed
	return

EventScript_AfterWhiteOutMomHeal::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement LOCALID_PLAYERS_HOUSE_1F_MOM, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox gText_HadQuiteAnExperienceTakeRest
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox gText_MomExplainHPGetPotions
	fadedefaultbgm
	releaseall
	end

EventScript_ResetMrBriney::
	goto_if_eq VAR_BRINEY_LOCATION, 1, EventScript_MoveMrBrineyToHouse
	goto_if_eq VAR_BRINEY_LOCATION, 2, EventScript_MoveMrBrineyToDewford
	goto_if_eq VAR_BRINEY_LOCATION, 3, EventScript_MoveMrBrineyToRoute109
	end

EventScript_MoveMrBrineyToHouse::
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	end

EventScript_MoveMrBrineyToDewford::
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	end

EventScript_MoveMrBrineyToRoute109::
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour::
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

Common_EventScript_UpdateBrineyLocation::
	goto_if_unset FLAG_RECEIVED_POKENAV, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_NopReturn
	goto_if_unset FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT, EventScript_SetBrineyLocation_House
	goto_if_unset FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN, EventScript_SetBrineyLocation_Dewford
	goto_if_unset FLAG_HIDE_ROUTE_109_MR_BRINEY, EventScript_SetBrineyLocation_Route109
	return

EventScript_SetBrineyLocation_House::
	setvar VAR_BRINEY_LOCATION, 1
	return

EventScript_SetBrineyLocation_Dewford::
	setvar VAR_BRINEY_LOCATION, 2
	return

EventScript_SetBrineyLocation_Route109::
	setvar VAR_BRINEY_LOCATION, 3
	return

	.include "data/scripts/pkmn_center_nurse.inc"
	.include "data/scripts/obtain_item.inc"
	.include "data/scripts/record_mix.inc"
	.include "data/scripts/pc.inc"
	.include "data/scripts/move_relearner.inc"

@ scripts/notices.inc? signs.inc? See comment about text/notices.inc
Common_EventScript_ShowPokemartSign::
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign::
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen::
	fadescreen FADE_TO_BLACK
	special ShowEasyChatScreen
	fadescreen FADE_FROM_BLACK
	return

Common_EventScript_ReadyPetalburgGymForBattle::
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	return

Common_EventScript_BufferTrendyPhrase::
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

EventScript_BackupMrBrineyLocation::
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

	.include "data/scripts/surf.inc"
	.include "data/scripts/rival_graphics.inc"
	.include "data/scripts/set_gym_trainers.inc"

EventScript_CancelMessageBox::
	special UseBlankMessageToCancelPokemonPic
	release
	end

Common_EventScript_ShowBagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

EventScript_BagIsFull::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox gText_TooBadBagIsFull
	release
	end

Common_EventScript_ShowNoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomForDecor::
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetAbnormalWeather::
	setweather WEATHER_ABNORMAL
	return

Common_EventScript_PlayGymBadgeFanfare::
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal::
	fadescreenswapbuffers FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	fadescreenswapbuffers FADE_FROM_BLACK
	return

EventScript_RegionMap::
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special FieldShowRegionMap
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic::
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_SAILING, FALSE
	return

Common_EventScript_StopBrineysBoatMusic::
	clearflag FLAG_DONT_TRANSITION_MUSIC
	fadedefaultbgm
	return

	.include "data/scripts/prof_birch.inc"

@ Below could be split as ferry.inc aside from the Rusturf tunnel script
Common_EventScript_FerryDepart::
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

EventScript_HideMrBriney::
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 0
	return

RusturfTunnel_EventScript_SetRusturfTunnelOpen::
	removeobject LOCALID_RUSTURF_TUNNEL_WANDAS_BF
	removeobject LOCALID_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WANDA
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	return

EventScript_UnusedBoardFerry::
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	showplayer
	delay 30
	applymovement LOCALID_PLAYER, Movement_UnusedBoardFerry
	waitmovement 0
	delay 30
	return

Movement_UnusedBoardFerry:
	walk_up
	step_end

Common_EventScript_FerryDepartIsland::
	call_if_eq VAR_FACING, DIR_SOUTH, Ferry_EventScript_DepartIslandSouth
	call_if_eq VAR_FACING, DIR_WEST, Ferry_EventScript_DepartIslandWest
	delay 30
	hideplayer
	call Common_EventScript_FerryDepart
	return

	.include "data/scripts/cave_of_origin.inc"
	.include "data/scripts/kecleon.inc"

Common_EventScript_NameReceivedPartyMon::
	fadescreen FADE_TO_BLACK
	special ChangePokemonNickname
	return

Common_EventScript_PlayerHandedOverTheItem::
	bufferitemname STR_VAR_1, VAR_0x8004
	playfanfare MUS_OBTAIN_TMHM
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	removeitem VAR_0x8004
	return

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"
	.include "data/scripts/mart_clerk.inc"
	.include "data/text/record_mix.inc"
	.include "data/text/pc.inc"
	.include "data/text/pkmn_center_nurse.inc"
	.include "data/text/obtain_item.inc"
	.include "data/text/move_relearner.inc"

@ The below and surf.inc could be split into some text/notices.inc
gText_PokemartSign::
	.string "“Selected items for your convenience!”\n"
	.string "POKéMON MART$"

gText_PokemonCenterSign::
	.string "“Rejuvenate your tired partners!”\n"
	.string "POKéMON CENTER$"

gText_MomOrDadMightLikeThisProgram::
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WhichFloorWouldYouLike::
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "Which floor would you like?$"

gText_SandstormIsVicious::
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem::
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

gText_PokemonTrainerSchoolEmail::
	.string "There's an e-mail from POKéMON TRAINER\n"
	.string "SCHOOL.\p"
	.string "… … … … … …\p"
	.string "A POKéMON may learn up to four moves.\p"
	.string "A TRAINER's expertise is tested on the\n"
	.string "move sets chosen for POKéMON.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC::
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled::
	.string "The link was canceled.$"

gText_UnusedNicknameReceivedPokemon::
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_PlayerWhitedOut::
	.string "{PLAYER} is out of usable\n"
	.string "POKéMON!\p{PLAYER} whited out!$"

gText_FirstShouldRestoreMonsHealth::
	.string "First, you should restore your\n"
	.string "POKéMON to full health.$"

gText_MonsHealedShouldBuyPotions::
	.string "Your POKéMON have been healed\n"
	.string "to perfect health.\p"
	.string "If your POKéMON's energy, HP,\n"
	.string "is down, please come see us.\p"
	.string "If you're planning to go far in the\n"
	.string "field, you should buy some POTIONS\l"
	.string "at the POKéMON MART.\p"
	.string "We hope you excel!$"

gText_MonsHealed::
	.string "Your POKéMON have been healed\n"
	.string "to perfect health.\p"
	.string "We hope you excel!$"

gText_HadQuiteAnExperienceTakeRest::
	.string "MOM: {PLAYER}!\n"
	.string "Welcome home.\p"
	.string "It sounds like you had quite\n"
	.string "an experience.\p"
	.string "Maybe you should take a quick\n"
	.string "rest.$"

gText_MomExplainHPGetPotions::
	.string "MOM: Oh, good! You and your\n"
	.string "POKéMON are looking great.\p"
	.string "I just heard from {STR_VAR_1}.\p"
	.string "He said that POKéMON's energy is\n"
	.string "measured in HP.\p"
	.string "If your POKéMON lose their HP,\n"
	.string "you can restore them at any\l"
	.string "POKéMON CENTER.\p"
	.string "If you're going to travel far away,\n"
	.string "the smart TRAINER stocks up on\l"
	.string "POTIONS at the POKéMON MART.\p"
	.string "Make me proud, honey!\p"
	.string "Take care!$"

gText_RegisteredTrainerinPokeNav::
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the POKéNAV.$"

gText_ComeBackWithSecretPower::
	.string "Do you know the TM SECRET POWER?\p"
	.string "Our group, we love the TM SECRET\n"
	.string "POWER.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation::
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway::
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall::
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments::
	.string "I'm terribly sorry.\n"
	.string "The POKéMON WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments::
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

@ Unused
gText_SorryTradeCenterInspections::
	.string "I'm terribly sorry. The TRADE CENTER\n"
	.string "is undergoing inspections.$"

@ Unused
gText_SorryRecordCornerPreparation::
	.string "I'm terribly sorry. The RECORD CORNER\n"
	.string "is under preparation.$"

gText_PlayerHandedOverTheItem::
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

gText_ThankYouForAccessingMysteryGift::
	.string "Thank you for accessing the\n"
	.string "MYSTERY GIFT System.$"

gText_PlayerFoundOneTMHM::
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_PlayerFoundTMHMs::
	.string "{PLAYER} found {STR_VAR_3} {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_Sudowoodo_Attacked::
	.string "The weird tree doesn't like the\n"
	.string "WAILMER PAIL!\p"
	.string "The weird tree attacked!$"

gText_LegendaryFlewAway::
	.string "The {STR_VAR_1} flew away!$"

gText_WantWhichFloor::
	.string "Which floor do you want?$"

	.include "data/text/pc_transfer.inc"
	.include "data/text/questionnaire.inc"
	.include "data/text/abnormal_weather.inc"

EventScript_GetInGameTradeSpeciesInfo::
	copyvar VAR_0x8005, VAR_0x8008
	specialvar VAR_0x8009, GetInGameTradeSpeciesInfo
	return

EventScript_ChooseMonForInGameTrade::
	special ChoosePartyMon
	lock
	faceplayer
	return

EventScript_GetInGameTradeSpecies::
	specialvar VAR_RESULT, GetTradeSpecies
	return

EventScript_DoInGameTrade::
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	lock
	faceplayer
	return

EventScript_SelectWithoutRegisteredItem::
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

Common_EventScript_NopReturn::
	return

EventScript_SetResultTrue::
	setvar VAR_RESULT, TRUE
	return

EventScript_SetResultFalse::
	setvar VAR_RESULT, FALSE
	return

EventScript_GetElevatorFloor::
	special GetElevatorFloor
	return

@ Unused
EventScript_CableClub_SetVarResult1::
	setvar VAR_RESULT, 1
	return

EventScript_CableClub_SetVarResult0::
	setvar VAR_RESULT, 0
	return

Common_EventScript_UnionRoomAttendant::
#if IS_FRLG
	call CableClub_EventScript_UnionRoomAttendant_Frlg
#else
	call CableClub_EventScript_UnionRoomAttendant
#endif
	end

Common_EventScript_WirelessClubAttendant::
#if IS_FRLG
	call CableClub_EventScript_WirelessClubAttendant_Frlg
#else
	call CableClub_EventScript_WirelessClubAttendant
#endif
	end

Common_EventScript_DirectCornerAttendant::
#if IS_FRLG
	call CableClub_EventScript_DirectCornerAttendant_Frlg
#else
	call CableClub_EventScript_DirectCornerAttendant
#endif
	end

Common_EventScript_RemoveStaticPokemon::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end

Common_EventScript_LegendaryFlewAway::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	bufferspeciesname STR_VAR_1, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

EventScript_VsSeekerChargingDone::
	special VsSeekerFreezeObjectsAfterChargeComplete
	waitstate
	special VsSeekerResetObjectMovementAfterChargeComplete
	releaseall
	end

@ FRLG scripts

EventScript_SetExitingCyclingRoad::
	lockall
	clearflag FLAG_SYS_ON_CYCLING_ROAD
	setvar VAR_MAP_SCENE_ROUTE16, 0
	releaseall
	end

EventScript_SetEnteringCyclingRoad::
	lockall
	setvar VAR_MAP_SCENE_ROUTE16, 1
	releaseall
	end

EventScript_TryDarkenRuins::
	goto_if_set FLAG_SYS_UNLOCKED_TANOBY_RUINS, Common_EventScript_NopReturn
	setweather WEATHER_SHADE
	doweather
	return

Text_MonFlewAway::
	.string "The {STR_VAR_1} flew away!$"

@ Call for legendary bird trio
Text_Gyaoo::
	.string "Gyaoo!$"

EventScript_BrailleCursorWaitButton::
	special BrailleCursorToggle
	waitbuttonpress
	closebraillemessage
	playse SE_SELECT
	setvar VAR_0x8006, 1
	special BrailleCursorToggle
	return

EventScript_PalletTown_PlayersHouse_2F_ShutDownPC::
	setvar VAR_0x8004, PC_LOCATION_PLAYER_HOUSE_FRLG
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_PalletTown_PlayersHouse_2F_TurnOnPC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_PLAYER_HOUSE_FRLG
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC
	special BedroomPC
	releaseall
	end


	.include "data/scripts/pc_transfer.inc"
	.include "data/scripts/questionnaire.inc"
	.include "data/scripts/abnormal_weather.inc"
	.include "data/scripts/trainer_script.inc"
	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/text/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
	.include "data/scripts/gabby_and_ty.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/profile_man.inc"
	.include "data/scripts/day_care.inc"
	.include "data/scripts/flash.inc"
	.include "data/scripts/players_house.inc"
	.include "data/scripts/berry_blender.inc"
	.include "data/text/mauville_man.inc"
	.include "data/text/trainers.inc"
	.include "data/scripts/repel.inc"
	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/roulette.inc"
	.include "data/scripts/pokedex_rating.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/match_call.inc"
	.include "data/scripts/apprentice.inc"
	.include "data/text/apprentice.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/blend_master.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/text/move_tutors.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_hill.inc"
	.include "data/scripts/test_signpost.inc"
	.include "data/scripts/follower.inc"
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"

	.include "data/maps/PlayerBasement/scripts.inc"
	.include "data/scripts/dexnav.inc"
	.include "data/scripts/battle_frontier.inc"
	.include "data/scripts/apricorn_tree.inc"
	.include "data/scripts/wild_encounter.inc"
