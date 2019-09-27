#include "constants/global.h"
#include "constants/battle.h"
#include "constants/battle_frontier.h"
#include "constants/battle_setup.h"
#include "constants/berry.h"
#include "constants/contest.h"
#include "constants/daycare.h"
#include "constants/decorations.h"
#include "constants/easy_chat.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement_constants.h"
#include "constants/field_effects.h"
#include "constants/field_specials.h"
#include "constants/flags.h"
#include "constants/game_stat.h"
#include "constants/item.h"
#include "constants/items.h"
#include "constants/heal_locations.h"
#include "constants/layouts.h"
#include "constants/lilycove_lady.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/metatile_labels.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/script_menu.h"
#include "constants/secret_bases.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/trainer_hill.h"
#include "constants/trainers.h"
#include "constants/vars.h"
#include "constants/weather.h"
	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ 81DB67C
	.include "data/script_cmd_table.inc"

gSpecialVars:: @ 81DBA0C
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
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts:: @ 81DC2A0
	.4byte Std_ObtainItem
	.4byte Std_FindItem
	.4byte Std_MsgboxNPC
	.4byte Std_MsgboxSign
	.4byte Std_MsgboxDefault
	.4byte Std_MsgboxYesNo
	.4byte Std_MsgboxAutoclose
	.4byte Std_ObtainDecoration
	.4byte Std_RegisteredInMatchCall
	.4byte Std_9
	.4byte Std_10
gStdScripts_End:: @ 81DC2CC

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
	.include "data/maps/Underwater1/scripts.inc"
	.include "data/maps/Underwater2/scripts.inc"
	.include "data/maps/Underwater3/scripts.inc"
	.include "data/maps/Underwater4/scripts.inc"
	.include "data/maps/Underwater5/scripts.inc"
	.include "data/maps/Underwater6/scripts.inc"
	.include "data/maps/Underwater7/scripts.inc"
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
	.include "data/maps/FallarborTown_House1/scripts.inc"
	.include "data/maps/FallarborTown_House2/scripts.inc"
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
	.include "data/maps/SlateportCity_House1/scripts.inc"
	.include "data/maps/SlateportCity_PokemonFanClub/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_1F/scripts.inc"
	.include "data/maps/SlateportCity_OceanicMuseum_2F/scripts.inc"
	.include "data/maps/SlateportCity_Harbor/scripts.inc"
	.include "data/maps/SlateportCity_House2/scripts.inc"
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
	.include "data/maps/SingleBattleColosseum/scripts.inc"
	.include "data/maps/TradeCenter/scripts.inc"
	.include "data/maps/RecordCorner/scripts.inc"
	.include "data/maps/DoubleBattleColosseum/scripts.inc"
	.include "data/maps/LinkContestRoom1/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_29/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_30/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_31/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_32/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_33/scripts.inc"
	.include "data/maps/UnknownLinkContestRoom_25_34/scripts.inc"
	.include "data/maps/LinkContestRoom2/scripts.inc"
	.include "data/maps/LinkContestRoom3/scripts.inc"
	.include "data/maps/LinkContestRoom4/scripts.inc"
	.include "data/maps/LinkContestRoom5/scripts.inc"
	.include "data/maps/LinkContestRoom6/scripts.inc"
	.include "data/maps/InsideOfTruck/scripts.inc"
	.include "data/maps/SSTidalCorridor/scripts.inc"
	.include "data/maps/SSTidalLowerDeck/scripts.inc"
	.include "data/maps/SSTidalRooms/scripts.inc"
	.include "data/maps/BattlePyramidSquare01/scripts.inc"
	.include "data/maps/BattlePyramidSquare02/scripts.inc"
	.include "data/maps/BattlePyramidSquare03/scripts.inc"
	.include "data/maps/BattlePyramidSquare04/scripts.inc"
	.include "data/maps/BattlePyramidSquare05/scripts.inc"
	.include "data/maps/BattlePyramidSquare06/scripts.inc"
	.include "data/maps/BattlePyramidSquare07/scripts.inc"
	.include "data/maps/BattlePyramidSquare08/scripts.inc"
	.include "data/maps/BattlePyramidSquare09/scripts.inc"
	.include "data/maps/BattlePyramidSquare10/scripts.inc"
	.include "data/maps/BattlePyramidSquare11/scripts.inc"
	.include "data/maps/BattlePyramidSquare12/scripts.inc"
	.include "data/maps/BattlePyramidSquare13/scripts.inc"
	.include "data/maps/BattlePyramidSquare14/scripts.inc"
	.include "data/maps/BattlePyramidSquare15/scripts.inc"
	.include "data/maps/BattlePyramidSquare16/scripts.inc"
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
	.include "data/maps/BattleFrontier_BattleTowerMultiBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerCorridor2/scripts.inc"
	.include "data/maps/BattleFrontier_BattleTowerBattleRoom2/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomePreBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattleDomeBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceCorridor/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePalaceBattleRoom/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidLobby/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePyramidEmptySquare/scripts.inc"
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
	.include "data/maps/BattleFrontier_BattlePikeRandomRoom1/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRandomRoom2/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePikeRandomRoom3/scripts.inc"
	.include "data/maps/BattleFrontier_RankingHall/scripts.inc"
	.include "data/maps/BattleFrontier_Lounge1/scripts.inc"
	.include "data/maps/BattleFrontier_BattlePointExchangeServiceCorner/scripts.inc"
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
	.include "data/maps/Route110_SeasideCyclingRoadNorthEntrance/scripts.inc"
	.include "data/maps/Route110_SeasideCyclingRoadSouthEntrance/scripts.inc"
	.include "data/maps/Route113_GlassWorkshop/scripts.inc"
	.include "data/maps/Route123_BerryMastersHouse/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_1F/scripts.inc"
	.include "data/maps/Route119_WeatherInstitute_2F/scripts.inc"
	.include "data/maps/Route119_House/scripts.inc"
	.include "data/maps/Route124_DivingTreasureHuntersHouse/scripts.inc"

Std_MsgboxNPC: @ 8271315
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_MsgboxSign: @ 8271320
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_MsgboxDefault: @ 827132A
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_MsgboxYesNo: @ 8271332
	message 0x0
	waitmessage
	yesnobox 20, 8
	return

Std_9: @ 827133C
	message 0x0
	playfanfare MUS_ME_POINTGET
	waitfanfare
	waitmessage
	return

Std_10: @ 8271347
	pokenavcall 0x0
	waitmessage
	return

EventScript_UnusedReturn: @ 827134E
	return

Common_EventScript_SaveGame:: @ 827134F
	special SaveGame
	waitstate
	return

EventScript_271354:: @ 8271354
	cmdD8
	cmdD9

	.include "data/scripts/trainer_battle.inc"

Std_MsgboxAutoclose:: @ 8271494
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

EventScript_ResetAllBerries:: @ 827149D
	setberrytree 2, ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES
	setberrytree 1, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 11, ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES
	setberrytree 13, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 4, ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES
	setberrytree 76, ITEM_TO_BERRY(ITEM_CHERI_BERRY), BERRY_STAGE_BERRIES
	setberrytree 8, ITEM_TO_BERRY(ITEM_CHERI_BERRY), BERRY_STAGE_BERRIES
	setberrytree 10, ITEM_TO_BERRY(ITEM_LEPPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 25, ITEM_TO_BERRY(ITEM_PINAP_BERRY), BERRY_STAGE_BERRIES
	setberrytree 26, ITEM_TO_BERRY(ITEM_CHESTO_BERRY), BERRY_STAGE_BERRIES
	setberrytree 66, ITEM_TO_BERRY(ITEM_CHESTO_BERRY), BERRY_STAGE_BERRIES
	setberrytree 67, ITEM_TO_BERRY(ITEM_PINAP_BERRY), BERRY_STAGE_BERRIES
	setberrytree 69, ITEM_TO_BERRY(ITEM_KELPSY_BERRY), BERRY_STAGE_BERRIES
	setberrytree 70, ITEM_TO_BERRY(ITEM_KELPSY_BERRY), BERRY_STAGE_BERRIES
	setberrytree 71, ITEM_TO_BERRY(ITEM_KELPSY_BERRY), BERRY_STAGE_BERRIES
	setberrytree 55, ITEM_TO_BERRY(ITEM_BLUK_BERRY), BERRY_STAGE_BERRIES
	setberrytree 56, ITEM_TO_BERRY(ITEM_BLUK_BERRY), BERRY_STAGE_BERRIES
	setberrytree 5, ITEM_TO_BERRY(ITEM_CHERI_BERRY), BERRY_STAGE_BERRIES
	setberrytree 6, ITEM_TO_BERRY(ITEM_LEPPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 7, ITEM_TO_BERRY(ITEM_CHERI_BERRY), BERRY_STAGE_BERRIES
	setberrytree 16, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 17, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 18, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 29, ITEM_TO_BERRY(ITEM_WEPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 28, ITEM_TO_BERRY(ITEM_WEPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 27, ITEM_TO_BERRY(ITEM_WEPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 24, ITEM_TO_BERRY(ITEM_RAWST_BERRY), BERRY_STAGE_BERRIES
	setberrytree 23, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 22, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 21, ITEM_TO_BERRY(ITEM_RAWST_BERRY), BERRY_STAGE_BERRIES
	setberrytree 19, ITEM_TO_BERRY(ITEM_RAZZ_BERRY), BERRY_STAGE_BERRIES
	setberrytree 20, ITEM_TO_BERRY(ITEM_RAZZ_BERRY), BERRY_STAGE_BERRIES
	setberrytree 80, ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES
	setberrytree 81, ITEM_TO_BERRY(ITEM_ORAN_BERRY), BERRY_STAGE_BERRIES
	setberrytree 77, ITEM_TO_BERRY(ITEM_PERSIM_BERRY), BERRY_STAGE_BERRIES
	setberrytree 78, ITEM_TO_BERRY(ITEM_PERSIM_BERRY), BERRY_STAGE_BERRIES
	setberrytree 68, ITEM_TO_BERRY(ITEM_PERSIM_BERRY), BERRY_STAGE_BERRIES
	setberrytree 31, ITEM_TO_BERRY(ITEM_SITRUS_BERRY), BERRY_STAGE_BERRIES
	setberrytree 33, ITEM_TO_BERRY(ITEM_SITRUS_BERRY), BERRY_STAGE_BERRIES
	setberrytree 34, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 35, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 36, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 83, ITEM_TO_BERRY(ITEM_HONDEW_BERRY), BERRY_STAGE_BERRIES
	setberrytree 84, ITEM_TO_BERRY(ITEM_HONDEW_BERRY), BERRY_STAGE_BERRIES
	setberrytree 85, ITEM_TO_BERRY(ITEM_SITRUS_BERRY), BERRY_STAGE_BERRIES
	setberrytree 86, ITEM_TO_BERRY(ITEM_LEPPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 37, ITEM_TO_BERRY(ITEM_ASPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 38, ITEM_TO_BERRY(ITEM_ASPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 39, ITEM_TO_BERRY(ITEM_ASPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 40, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 41, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 42, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 46, ITEM_TO_BERRY(ITEM_WEPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 45, ITEM_TO_BERRY(ITEM_PINAP_BERRY), BERRY_STAGE_BERRIES
	setberrytree 44, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 43, ITEM_TO_BERRY(ITEM_RAZZ_BERRY), BERRY_STAGE_BERRIES
	setberrytree 47, ITEM_TO_BERRY(ITEM_PERSIM_BERRY), BERRY_STAGE_BERRIES
	setberrytree 48, ITEM_TO_BERRY(ITEM_ASPEAR_BERRY), BERRY_STAGE_BERRIES
	setberrytree 49, ITEM_TO_BERRY(ITEM_RAWST_BERRY), BERRY_STAGE_BERRIES
	setberrytree 50, ITEM_TO_BERRY(ITEM_CHESTO_BERRY), BERRY_STAGE_BERRIES
	setberrytree 52, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 53, ITEM_TO_BERRY(ITEM_NANAB_BERRY), BERRY_STAGE_BERRIES
	setberrytree 62, ITEM_TO_BERRY(ITEM_LEPPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 64, ITEM_TO_BERRY(ITEM_LEPPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 58, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 59, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 60, ITEM_TO_BERRY(ITEM_GREPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 61, ITEM_TO_BERRY(ITEM_GREPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 79, ITEM_TO_BERRY(ITEM_QUALOT_BERRY), BERRY_STAGE_BERRIES
	setberrytree 14, ITEM_TO_BERRY(ITEM_QUALOT_BERRY), BERRY_STAGE_BERRIES
	setberrytree 15, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 30, ITEM_TO_BERRY(ITEM_POMEG_BERRY), BERRY_STAGE_BERRIES
	setberrytree 65, ITEM_TO_BERRY(ITEM_GREPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 72, ITEM_TO_BERRY(ITEM_GREPA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 73, ITEM_TO_BERRY(ITEM_QUALOT_BERRY), BERRY_STAGE_BERRIES
	setberrytree 74, ITEM_TO_BERRY(ITEM_QUALOT_BERRY), BERRY_STAGE_BERRIES
	setberrytree 87, ITEM_TO_BERRY(ITEM_PECHA_BERRY), BERRY_STAGE_BERRIES
	setberrytree 88, ITEM_TO_BERRY(ITEM_SITRUS_BERRY), BERRY_STAGE_BERRIES
	setberrytree 89, ITEM_TO_BERRY(ITEM_RAWST_BERRY), BERRY_STAGE_BERRIES
	setberrytree 82, ITEM_TO_BERRY(ITEM_LIECHI_BERRY), BERRY_STAGE_BERRIES
	return

EventScript_ResetAllMapFlags:: @ 82715DE
	setflag FLAG_LINK_CONTEST_POKE_BALL
	setflag FLAG_HIDE_ROUTE_111_VICTORIA_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VIVI_WINSTRATE
	setflag FLAG_HIDE_ROUTE_111_VICKY_WINSTRATE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CYNDAQUIL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_TOTODILE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_POKEBALL_CHIKORITA
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setflag FLAG_UNKNOWN_0x363
	setflag FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_HIDE_RUSBORO_CITY_RIVAL
	setflag FLAG_HIDE_RUSTBORO_CITY_SCIENTIST
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	setflag FLAG_HIDE_ROUTE_110_BIRCH
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_1
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_CONTEST_ATTENDANT_2
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_1
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_2
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_3
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_PATRON_4
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_TOURISTS
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_UNCLE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	setflag FLAG_HIDE_FANCLUB_OLD_LADY
	setflag FLAG_HIDE_FANCLUB_BOY
	setflag FLAG_HIDE_FANCLUB_LITTLE_BOY
	setflag FLAG_HIDE_FANCLUB_LADY
	setflag FLAG_HIDE_LILYCOVE_FAN_CLUB_INTERVIEWER
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_1
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_1
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_3
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_120_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_111_GABBY_AND_TY_2
	setflag FLAG_HIDE_ROUTE_118_GABBY_AND_TY_3
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_MAN
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_WOMAN
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_UNCLE
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_1
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_1
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	setflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	setflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	setflag FLAG_HIDE_ROUTE_119_SCOTT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDE_LANETTES_HOUSE_LANETTE
	setflag FLAG_HIDE_TRICK_HOUSE_ENTRANCE_MAN
	setflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	setflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_OLD_MAN
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_LOVER_MAN
	setflag FLAG_HIDE_RUSTURF_TUNNEL_LOVER_WOMAN
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2
	setflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_HIDE_BATTLE_TOWER_OPPONENT
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setflag FLAG_HIDE_LITTLE_ROOT_TOWN_PLAYERS_BEDROOM_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR
	setflag FLAG_HIDE_LILYCOVE_HARBOR_EVENT_TICKET_TAKER
	setflag FLAG_HIDE_SOUTHERN_ISLAND_EON_STONE
	setflag FLAG_HIDE_SOUTHERN_ISLAND_UNCHOSEN_EON_DUO_MON
	setflag FLAG_UNKNOWN_0x393
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setflag FLAG_HIDE_MAUVILLE_CITY_SCOTT
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
	setflag FLAG_HIDE_ROUTE_110_RIVAL_2
	setflag FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	setflag FLAG_HIDE_LILCOVE_MOTEL_GAME_DESIGNERS
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_1
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_2
	setflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	setflag FLAG_HIDE_FALLARBOR_HOUSE_1_PROF_COZMO
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	setflag FLAG_HIDE_ROUTE_128_STEVEN
	setflag FLAG_HIDE_ROUTE_128_ARCHIE
	setflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	setflag FLAG_HIDE_SLATEPORT_CITY_SCOTT
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setflag FLAG_HIDE_ROUTE_101_BOY
	setflag FLAG_HIDE_PETALBURG_CITY_SCOTT
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_ROUTE_111_DESERT_FOSSIL
	setflag FLAG_HIDE_ROUTE_111_PLAYER_DESCENT
	setflag FLAG_HIDE_DESERT_UNDERPASS_FOSSIL
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_BLEND_MASTER_ONLOOKERS
	setflag FLAG_HIDE_DEOXYS
	setflag FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION
	setflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
	setflag FLAG_HIDE_EVER_GRANDE_POKEMON_CENTER_1F_SCOTT
	setflag FLAG_HIDE_SKY_PILLAR_WALLACE
	setflag FLAG_RAYQUAZA_ON_SKY_TOWER_SUMMIT
	call EventScript_ResetAllBerries
	end

EverGrandeCity_HallOfFame_EventScript_2717C1:: @ 82717C1
	special sub_81AFDD0
	setflag FLAG_IS_CHAMPION
	call EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries
	compare VAR_FOSSIL_MANIAC_STATE, 0
	call_if_eq EverGrandeCity_HallOfFame_EventScript_271839
	clearflag FLAG_HIDE_LILCOVE_MOTEL_GAME_DESIGNERS
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	setflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_HIDE_SS_TIDAL_CORRIDOR_MR_BRINEY
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_INVISIBLE_NINJA_BOY
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	clearflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	setflag FLAG_HIDE_SAFARI_ZONE_SOUTH_CONSTRUCTION_WORKERS
	clearflag FLAG_HIDE_SAFARI_ZONE_SOUTH_EAST_EXPANSION
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	special sub_813BA60
	call_if_unset FLAG_RECEIVED_SS_TICKET, EverGrandeCity_HallOfFame_EventScript_271843
	call_if_unset FLAG_RECEIVED_BELDUM, EverGrandeCity_HallOfFame_EventScript_27183F
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	compare VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 0
	call_if_eq EverGrandeCity_HallOfFame_EventScript_271851
	return

EverGrandeCity_HallOfFame_EventScript_ResetDefeatedEventLegendaries:: @ 8271829
	clearflag FLAG_DEFEATED_MEW
	clearflag FLAG_DEFEATED_LATIAS_OR_LATIOS
	clearflag FLAG_DEFEATED_DEOXYS
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_DEFEATED_HO_OH
	return

EverGrandeCity_HallOfFame_EventScript_271839:: @ 8271839
	setvar VAR_FOSSIL_MANIAC_STATE, 1
	return

EverGrandeCity_HallOfFame_EventScript_27183F:: @ 827183F
	clearflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_BELDUM_POKEBALL
	return

EverGrandeCity_HallOfFame_EventScript_271843:: @ 8271843
	setvar VAR_LITTLEROOT_HOUSES_STATE, 3
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 3
	clearflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	return

EverGrandeCity_HallOfFame_EventScript_271851:: @ 8271851
	setvar VAR_DEX_UPGRADE_JOHTO_STARTER_STATE, 1
	return

EventScript_WhiteOut:: @ 8271857
	call EverGrandeCity_HallOfFame_EventScript_ResetEliteFour
	goto EventScript_ResetMrBriney
	end

EventScript_ResetMrBriney:: @ 8271862
	compare VAR_BRINEY_LOCATION, 1
	goto_if_eq EventScript_MoveMrBrineyToHouse
	compare VAR_BRINEY_LOCATION, 2
	goto_if_eq EventScript_MoveMrBrineyToDewford
	compare VAR_BRINEY_LOCATION, 3
	goto_if_eq EventScript_MoveMrBrineyToRoute108
	end

EventScript_MoveMrBrineyToHouse:: @ 8271884
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	end

EventScript_MoveMrBrineyToDewford:: @ 827189A
	setflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	end

EventScript_MoveMrBrineyToRoute108:: @ 82718B3
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	clearflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	end

EverGrandeCity_HallOfFame_EventScript_ResetEliteFour:: @ 82718CC
	clearflag FLAG_DEFEATED_ELITE_4_SIDNEY
	clearflag FLAG_DEFEATED_ELITE_4_PHOEBE
	clearflag FLAG_DEFEATED_ELITE_4_GLACIA
	clearflag FLAG_DEFEATED_ELITE_4_DRAKE
	setvar VAR_ELITE_4_STATE, 0
	return

Common_EventScript_UpdateBrineyLocation:: @ 82718DE
	goto_if_unset FLAG_RECEIVED_POKENAV, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_NopReturn
	goto_if_unset FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT, EventScript_SetBrineyLocation_House
	goto_if_unset FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN, EventScript_SetBrineyLocation_Dewford
	goto_if_unset FLAG_HIDE_ROUTE_108_MR_BRINEY, EventScript_SetBrineyLocation_Route108
	return

EventScript_SetBrineyLocation_House:: @ 827190C
	setvar VAR_BRINEY_LOCATION, 1
	return

EventScript_SetBrineyLocation_Dewford:: @ 8271912
	setvar VAR_BRINEY_LOCATION, 2
	return

EventScript_SetBrineyLocation_Route108:: @ 8271918
	setvar VAR_BRINEY_LOCATION, 3
	return

	.include "data/scripts/pkmn_center_nurse.inc"

Std_ObtainItem:: @ 8271AD3
	giveitem VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_271AE3
	return

EventScript_271AE3:: @ 8271AE3
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	call_if_eq EventScript_271B95
	compare VAR_0x8007, 0
	call_if_eq EventScript_271BA9
	return

EventScript_BufferStdString:: @ 8271B08
	switch VAR_RESULT
	case POCKET_ITEMS, EventScript_StdStringItem
	case POCKET_KEY_ITEMS, EventScript_StdStringKeyItems
	case POCKET_POKE_BALLS, EventScript_StdStringPokeballs
	case POCKET_TM_HM, EventScript_StdStringTMHMS
	case POCKET_BERRIES, EventScript_StdStringBerries
	end

EventScript_StdStringItem:: @ 8271B45
	bufferstdstring 2, STDSTRING_ITEMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfare4
	return

EventScript_StdStringKeyItems:: @ 8271B55
	bufferstdstring 2, STDSTRING_KEYITEMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfare4
	return

EventScript_StdStringPokeballs:: @ 8271B65
	bufferstdstring 2, STDSTRING_POKEBALLS
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfare4
	return

EventScript_StdStringTMHMS:: @ 8271B75
	bufferstdstring 2, STDSTRING_TMHMS
	compare VAR_0x8007, 1
	call_if_eq EventScript_271BB3
	return

EventScript_StdStringBerries:: @ 8271B85
	bufferstdstring 2, STDSTRING_BERRIES
	compare VAR_0x8007, 1
	call_if_eq EventScript_PlayFanfare4
	return

EventScript_271B95:: @ 8271B95
	message gText_ObtainedTheItem
	waitfanfare
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

EventScript_271BA9:: @ 8271BA9
	setvar VAR_RESULT, 0
	return

EventScript_PlayFanfare4:: @ 8271BAF
	playfanfare MUS_FANFA4
	return

EventScript_271BB3:: @ 8271BB3
	playfanfare MUS_ME_WAZA
	return

Std_ObtainDecoration:: @ 8271BB7
	givedecoration VAR_0x8000
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_271BC5
	return

EventScript_271BC5:: @ 8271BC5
	bufferdecorationname 1, VAR_0x8000
	compare VAR_0x8007, 1
	call_if_eq EventScript_271BE0
	compare VAR_0x8007, 0
	call_if_eq EventScript_271BF7
	return

EventScript_271BE0:: @ 8271BE0
	playfanfare MUS_FANFA4
	message gText_ObtainedTheMon
	waitfanfare
	msgbox gText_TheMonWasTransferredToThePC, MSGBOX_DEFAULT
	setvar VAR_RESULT, 1
	return

EventScript_271BF7:: @ 8271BF7
	setvar VAR_RESULT, 0
	return

Std_FindItem:: @ 8271BFD
	lock
	faceplayer
	waitse
	copyvar VAR_0x8004, VAR_0x8000
	copyvar VAR_0x8005, VAR_0x8001
	checkitemspace VAR_0x8000, VAR_0x8001
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8000, VAR_0x8001
	checkitemtype VAR_0x8000
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	call_if_eq EventScript_PickItemUp
	compare VAR_0x8007, 0
	call_if_eq EventScript_271CA1
	release
	return

EventScript_PickItemUp:: @ 8271C3A
	removeobject VAR_LAST_TALKED
	giveitem VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 1
	call_if_eq EventScript_271C8F
	compare VAR_0x8008, 0
	call_if_eq EventScript_271C9B
	waitfanfare
	waitmessage
	bufferitemnameplural 1, VAR_0x8004, VAR_0x8005
	setvar VAR_0x8004, 12
	special CallBattlePyramidFunction
	compare VAR_RESULT, 1
	goto_if_eq EventScript_271C86
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	return

EventScript_271C86:: @ 8271C86
	msgbox gText_PlayerPutItemInBag, MSGBOX_DEFAULT
	return

EventScript_271C8F:: @ 8271C8F
	bufferitemnameplural 0, VAR_0x8004, VAR_0x8005
	message gText_PlayerFoundOneItemTwoLines
	return

EventScript_271C9B:: @ 8271C9B
	message gText_PlayerFoundOneItem
	return

EventScript_271CA1:: @ 8271CA1
	msgbox gText_ObtainedTheItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	return

EventScript_HiddenItemScript:: @ 8271CB7
	lockall
	waitse
	giveitem VAR_0x8005, 1
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_BufferStdString
	compare VAR_0x8007, 1
	goto_if_eq EventScript_271CE8
	compare VAR_0x8007, 0
	goto_if_eq EventScript_271D47
	end

EventScript_271CE8:: @ 8271CE8
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, BufferTMHMMoveName
	compare VAR_RESULT, 1
	goto_if_eq EventScript_271D0E
	compare VAR_RESULT, 0
	goto_if_eq EventScript_271D1F
	end

EventScript_271D0E:: @ 8271D0E
	bufferitemnameplural 0, VAR_0x8004, 1
	message gText_PlayerFoundOneItemTwoLines
	goto EventScript_271D2A
	end

EventScript_271D1F:: @ 8271D1F
	message gText_PlayerFoundOneItem
	goto EventScript_271D2A
	end

EventScript_271D2A:: @ 8271D2A
	waitmessage
	waitfanfare
	bufferitemnameplural 1, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	msgbox gText_PutItemInPocket, MSGBOX_DEFAULT
	special sub_80EDCE8
	special SetFlagInVar
	releaseall
	end

EventScript_271D47:: @ 8271D47
	msgbox gText_PlayerFoundOneItem, MSGBOX_DEFAULT
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_271D5E:: @ 8271D5E
	lock
	faceplayer
	msgbox Text_WouldYouLikeToMixRecords, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq EventScript_271D83
	compare VAR_RESULT, 0
	goto_if_eq EventScript_271D89
	goto EventScript_271D89

EventScript_271D83:: @ 8271D83
	special RecordMixingPlayerSpotTriggered
	waitstate
	lock
	faceplayer

EventScript_271D89:: @ 8271D89
	message Text_WouldNotLikeToMixRecords
	waitmessage
	waitbuttonpress
	release
	end

EventScript_PC:: @ 8271D92
	lockall
	setvar VAR_0x8004, 0
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_BootUpPC, MSGBOX_DEFAULT
	goto EventScript_271DAC
	end

EventScript_271DAC:: @ 8271DAC
	message gText_WhichPCShouldBeAccessed
	waitmessage
	special ScriptMenu_CreatePCMultichoice
	waitstate
	goto EventScript_271DBC
	end

EventScript_271DBC:: @ 8271DBC
	switch VAR_RESULT
	case 0, EventScript_271E0E
	case 1, EventScript_271DF9
	case 2, EventScript_271E54
	case 3, EventScript_271E47
	case MULTI_B_PRESSED, EventScript_271E47
	end

EventScript_271DF9:: @ 8271DF9
	playse SE_PC_LOGIN
	msgbox gText_AccessedPlayersPC, MSGBOX_DEFAULT
	special PlayerPC
	waitstate
	goto EventScript_271DAC
	end

EventScript_271E0E:: @ 8271E0E
	playse SE_PC_LOGIN
	call_if_unset FLAG_SYS_PC_LANETTE, EventScript_271E35
	call_if_set FLAG_SYS_PC_LANETTE, EventScript_271E3E
	msgbox gText_StorageSystemOpened, MSGBOX_DEFAULT
	special ShowPokemonStorageSystemPC
	waitstate
	goto EventScript_271DAC
	end

EventScript_271E35:: @ 8271E35
	msgbox gText_AccessedSomeonesPC, MSGBOX_DEFAULT
	return

EventScript_271E3E:: @ 8271E3E
	msgbox gText_AccessedLanettesPC, MSGBOX_DEFAULT
	return

EventScript_271E47:: @ 8271E47
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_271E54:: @ 8271E54
	goto_if_unset FLAG_SYS_GAME_CLEAR, EventScript_271E47
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_271DBC
	end

Common_EventScript_ShowPokemartSign:: @ 8271E6A
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end

Common_EventScript_ShowPokemonCenterSign:: @ 8271E73
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end

Common_ShowEasyChatScreen:: @ 8271E7C
	fadescreen 1
	special ShowEasyChatScreen
	fadescreen 0
	return

DewfordTown_Gym_EventScript_271E84:: @ 8271E84
LavaridgeTown_Gym_1F_EventScript_271E84:: @ 8271E84
MauvilleCity_Gym_EventScript_271E84:: @ 8271E84
RustboroCity_Gym_EventScript_271E84:: @ 8271E84
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	return

DewfordTown_EventScript_271E8B:: @ 8271E8B
DewfordTown_Hall_EventScript_271E8B:: @ 8271E8B
	dotimebasedevents
	setvar VAR_0x8004, 0
	special BufferTrendyPhraseString
	return

DewfordTown_EventScript_271E95:: @ 8271E95
Route104_MrBrineysHouse_EventScript_271E95:: @ 8271E95
Route109_EventScript_271E95:: @ 8271E95
	copyvar VAR_0x8008, VAR_BRINEY_LOCATION
	setvar VAR_BRINEY_LOCATION, 0
	return

EventScript_UseSurf:: @ 8271EA0
	checkpartymove MOVE_SURF
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantSurf
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_CancelSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF

EventScript_CancelSurf:: @ 8271ED5
	releaseall

EventScript_CantSurf:: @ 8271ED6
	end

Common_EventScript_SetupRivalGfxId:: @ 8271ED7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EventScript_SetupRivalGfxIdFemale
	compare VAR_RESULT, FEMALE
	goto_if_eq EventScript_SetupRivalGfxIdMale
	end

EventScript_SetupRivalGfxIdFemale:: @ 8271EEF
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

EventScript_SetupRivalGfxIdMale:: @ 8271EF5
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

Common_EventScript_SetupRivalOnBikeGfxId:: @ 8271EFB
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdFemale
	compare VAR_RESULT, FEMALE
	goto_if_eq EventScript_SetupRivalOnBikeGfxIdMale
	end

EventScript_SetupRivalOnBikeGfxIdFemale:: @ 8271F13
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_RIVAL_MAY_MACH_BIKE
	return

EventScript_SetupRivalOnBikeGfxIdMale:: @ 8271F19
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_RIVAL_BRENDAN_MACH_BIKE
	return

@ Unused
Common_EventScript_SetupRivalGfxIdSameGender:: @ 8271F1F
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq EventScript_SetupRivalGfxIdMale2
	compare VAR_RESULT, FEMALE
	goto_if_eq EventScript_SetupRivalGfxIdFemale2
	end

EventScript_SetupRivalGfxIdMale2:: @ 8271F37
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

EventScript_SetupRivalGfxIdFemale2:: @ 8271F3D
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return

Common_EventScript_SetGymTrainers:: @ 8271F43
	switch VAR_0x8008
	case 1, RusboroCity_Gym_SetGymTrainers
	case 2, DewfordTown_Gym_SetGymTrainers
	case 3, MauvilleCity_Gym_SetGymTrainers
	case 4, LavaridgeTown_Gym_SetGymTrainers
	case 5, PetalburgCity_Gym_SetGymTrainers
	case 6, FortreeCity_Gym_SetGymTrainers
	case 7, MossdeepCity_Gym_SetGymTrainers
	case 8, SootopolisCity_Gym_SetGymTrainers
	end

RusboroCity_Gym_SetGymTrainers:: @ 8271FA1
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	return

DewfordTown_Gym_SetGymTrainers:: @ 8271FAB
	settrainerflag TRAINER_TAKAO
	settrainerflag TRAINER_JOCELYN
	settrainerflag TRAINER_LAURA
	settrainerflag TRAINER_BRENDEN
	settrainerflag TRAINER_CRISTIAN
	settrainerflag TRAINER_LILITH
	return

MauvilleCity_Gym_SetGymTrainers:: @ 8271FBE
	settrainerflag TRAINER_KIRK
	settrainerflag TRAINER_SHAWN
	settrainerflag TRAINER_BEN
	settrainerflag TRAINER_VIVIAN
	settrainerflag TRAINER_ANGELO
	return

LavaridgeTown_Gym_SetGymTrainers:: @ 8271FCE
	settrainerflag TRAINER_COLE
	settrainerflag TRAINER_AXLE
	settrainerflag TRAINER_KEEGAN
	settrainerflag TRAINER_GERALD
	settrainerflag TRAINER_DANIELLE
	settrainerflag TRAINER_JACE
	settrainerflag TRAINER_JEFF
	settrainerflag TRAINER_ELI
	return

PetalburgCity_Gym_SetGymTrainers:: @ 8271FE7
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return

FortreeCity_Gym_SetGymTrainers:: @ 8271FFD
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_FLINT
	settrainerflag TRAINER_ASHLEY
	settrainerflag TRAINER_EDWARDO
	settrainerflag TRAINER_HUMBERTO
	settrainerflag TRAINER_DARIUS
	return

MossdeepCity_Gym_SetGymTrainers:: @ 8272010
	settrainerflag TRAINER_PRESTON
	settrainerflag TRAINER_VIRGIL
	settrainerflag TRAINER_BLAKE
	settrainerflag TRAINER_HANNAH
	settrainerflag TRAINER_SAMANTHA
	settrainerflag TRAINER_MAURA
	settrainerflag TRAINER_SYLVIA
	settrainerflag TRAINER_NATE
	settrainerflag TRAINER_KATHLEEN
	settrainerflag TRAINER_CLIFFORD
	settrainerflag TRAINER_MACEY
	settrainerflag TRAINER_NICHOLAS
	return

SootopolisCity_Gym_SetGymTrainers:: @ 8272035
	settrainerflag TRAINER_ANDREA
	settrainerflag TRAINER_CRISSY
	settrainerflag TRAINER_BRIANNA
	settrainerflag TRAINER_CONNIE
	settrainerflag TRAINER_BRIDGET
	settrainerflag TRAINER_OLIVIA
	settrainerflag TRAINER_TIFFANY
	settrainerflag TRAINER_BETHANY
	settrainerflag TRAINER_ANNIKA
	settrainerflag TRAINER_DAPHNE
	return

Common_EventScript_ShowBagIsFull:: @ 8272054
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Common_EventScript_BagIsFull:: @ 827205E
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_272067:: @ 8272067
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	release
	end

Common_EventScript_NoRoomLeftForAnother:: @ 8272071
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	return

Common_EventScript_SetWeather15:: @ 827207A
	setweather WEATHER_ALTERNATING
	return

Common_EventScript_PlayGymBadgeFanfare:: @ 827207E
	playfanfare MUS_ME_BACHI
	waitfanfare
	return

Common_EventScript_OutOfCenterPartyHeal:: @ 8272083
	fadescreen 1
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	fadescreen 0
	return

EventScript_RegionMap:: @ 827208F
	lockall
	msgbox Common_Text_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen 1
	special FieldShowRegionMap
	waitstate
	releaseall
	end

Common_EventScript_PlayBrineysBoatMusic:: @ 82720A0
	setflag FLAG_SPECIAL_FLAG_0x4001
	playbgm MUS_M_BOAT, 0
	return

Common_EventScript_StopBrineysBoatMusic:: @ 82720A8
	clearflag FLAG_SPECIAL_FLAG_0x4001
	fadedefaultbgm
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2720AD:: @ 82720AD
Route101_EventScript_2720AD:: @ 82720AD
Route103_EventScript_2720AD:: @ 82720AD
	compare VAR_PETALBURG_GYM_STATE, 0
	goto_if_eq Common_EventScript_NopReturn
	goto_if_set FLAG_SYS_GAME_CLEAR, Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 0
	call_if_eq Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 1
	call_if_eq Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 2
	call_if_eq Route101_EventScript_272127
	compare VAR_BIRCH_STATE, 3
	call_if_eq Route101_EventScript_272127
	compare VAR_BIRCH_STATE, 4
	call_if_eq Route101_EventScript_272134
	compare VAR_BIRCH_STATE, 5
	call_if_eq Route101_EventScript_272134
	compare VAR_BIRCH_STATE, 6
	call_if_eq Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 7
	call_if_eq Route101_EventScript_27211A
	return

Route101_EventScript_27211A:: @ 827211A
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

Route101_EventScript_272127:: @ 8272127
	clearflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	return

Route101_EventScript_272134:: @ 8272134
	clearflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380
	return

LittlerootTown_ProfessorBirchsLab_EventScript_272141:: @ 8272141
Route101_EventScript_272141:: @ 8272141
Route103_EventScript_272141:: @ 8272141
	lock
	faceplayer
	goto_if_unset FLAG_HAS_MATCH_CALL, Route101_EventScript_272155
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, Route101_EventScript_1FA2D2

Route101_EventScript_272155:: @ 8272155
	msgbox gBirchDexRatingText_AreYouCurious, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Route101_EventScript_27216F
	call Route101_EventScript_272184
	release
	end

Route101_EventScript_27216F:: @ 827216F
	msgbox gBirchDexRatingText_Cancel, MSGBOX_DEFAULT
	release
	end

Route101_EventScript_272179:: @ 8272179
	copyvar VAR_0x8004, VAR_0x8009
	special ShowPokedexRatingMessage
	waitmessage
	waitbuttonpress
	return

EverGrandeCity_ChampionsRoom_EventScript_272184:: @ 8272184
Route101_EventScript_272184:: @ 8272184
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring 0, VAR_0x8008
	buffernumberstring 1, VAR_0x8009
	msgbox gBirchDexRatingText_SoYouveSeenAndCaught, MSGBOX_DEFAULT
	call Route101_EventScript_272179
	compare VAR_0x800A, 0
	goto_if_eq Common_EventScript_NopReturn
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008
	buffernumberstring 1, VAR_0x8009
	msgbox gBirchDexRatingText_OnANationwideBasis, MSGBOX_DEFAULT
	return

Common_EventScript_FerryDepart:: @ 82721E2
	delay 60
	applymovement VAR_0x8004, Movement_FerryDepart
	waitmovement 0
	return

Movement_FerryDepart: @ 82721F0
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

PetalburgCity_Gym_EventScript_2721F8:: @ 82721F8
	setflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 0
	return

RusturfTunnel_EventScript_272216:: @ 8272216
	removeobject 1
	removeobject 10
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_MAN
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_WOMAN
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	return

EventScript_27222B:: @ 827222B
	delay 30
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	showobjectat 255, MAP_PETALBURG_CITY
	delay 30
	applymovement EVENT_OBJ_ID_PLAYER, Movement_27224E
	waitmovement 0
	delay 30
	return

Movement_27224E: @ 827224E
	walk_up
	step_end

BattleFrontier_OutsideWest_EventScript_272250:: @ 8272250
BirthIsland_Harbor_EventScript_272250:: @ 8272250
FarawayIsland_Entrance_EventScript_272250:: @ 8272250
NavelRock_Harbor_EventScript_272250:: @ 8272250
SouthernIsland_Exterior_EventScript_272250:: @ 8272250
	compare VAR_FACING, 1
	call_if_eq BattleFrontier_OutsideWest_EventScript_242A21
	compare VAR_FACING, 3
	call_if_eq BattleFrontier_OutsideWest_EventScript_242A2C
	delay 30
	hideobjectat 255, MAP_PETALBURG_CITY
	call Common_EventScript_FerryDepart
	return

EventScript_272274:: @ 8272274
	lockall
	waitse
	playmoncry SPECIES_KYOGRE, 2
	waitmoncry
	setvar VAR_TEMP_5, 1
	releaseall
	end

EventScript_272283:: @ 8272283
	lockall
	setvar VAR_TEMP_1, 1
	goto EventScript_2722A7
	end

EventScript_27228F:: @ 827228F
	lockall
	setvar VAR_TEMP_2, 1
	goto EventScript_2722A7
	end

EventScript_27229B:: @ 827229B
	lockall
	setvar VAR_TEMP_3, 1
	goto EventScript_2722A7
	end

EventScript_2722A7:: @ 82722A7
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special sub_8139560
	waitstate
	releaseall
	end

CaveOfOrigin_1F_EventScript_2722C1:: @ 82722C1
CaveOfOrigin_UnusedRubySapphireMap1_EventScript_2722C1:: @ 82722C1
CaveOfOrigin_UnusedRubySapphireMap2_EventScript_2722C1:: @ 82722C1
CaveOfOrigin_UnusedRubySapphireMap3_EventScript_2722C1:: @ 82722C1
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_5, 1
	return

Route120_EventScript_2722DB:: @ 82722DB
	lock
	faceplayer
	setvar VAR_0x8009, 1
	goto Route120_EventScript_272336
	end

Route120_EventScript_2722E8:: @ 82722E8
	lock
	faceplayer
	setvar VAR_0x8009, 2
	goto Route120_EventScript_272336
	end

Route120_EventScript_2722F5:: @ 82722F5
	lock
	faceplayer
	setvar VAR_0x8009, 3
	goto Route120_EventScript_272336
	end

Route120_EventScript_272302:: @ 8272302
	lock
	faceplayer
	setvar VAR_0x8009, 4
	goto Route120_EventScript_272336
	end

Route120_EventScript_27230F:: @ 827230F
	lock
	faceplayer
	setvar VAR_0x8009, 5
	goto Route120_EventScript_272336
	end

Route119_EventScript_27231C:: @ 827231C
	lock
	faceplayer
	setvar VAR_0x8009, 6
	goto Route119_EventScript_272336
	end

Route119_EventScript_272329:: @ 8272329
	lock
	faceplayer
	setvar VAR_0x8009, 7
	goto Route119_EventScript_272336
	end

Route119_EventScript_272336:: @ 8272336
Route120_EventScript_272336:: @ 8272336
	checkitem ITEM_DEVON_SCOPE, 1
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_272350
	msgbox Route119_Text_1F5D00, MSGBOX_DEFAULT
	release
	end

Route119_EventScript_272350:: @ 8272350
	msgbox Route119_Text_1F5D23, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_272365
	release
	end

Route119_EventScript_272365:: @ 8272365
	msgbox Route119_Text_1F5D63, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	applymovement VAR_LAST_TALKED, Route119_Movement_2723C7
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq EventScript_RemoveKecleon
	compare VAR_RESULT, 4
	goto_if_eq EventScript_RemoveKecleon
	compare VAR_RESULT, 5
	goto_if_eq EventScript_RemoveKecleon
	release
	end

EventScript_RemoveKecleon:: @ 82723C1
	goto Common_EventScript_RemoveStaticPokemon
	end

FortreeCity_Movement_2723C7: @ 82723C7
Route119_Movement_2723C7: @ 82723C7
Route120_Movement_2723C7: @ 82723C7
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end

Common_EventScript_NameReceivedPartyMon:: @ 82723DD
	fadescreen 1
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_PlayerHandedOverTheItem:: @ 82723E4
	bufferitemname 0, VAR_0x8004
	playfanfare MUS_ME_WAZA
	message gText_PlayerHandedOverTheItem
	waitmessage
	waitfanfare
	takeitem VAR_0x8004, 1
	return

EverGrandeCity_DrakesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_GlaciasRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_PhoebesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_SidneysRoom_EventScript_2723F8:: @ 82723F8
PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles:: @ 82723F8
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_SidneysRoom_Movement_2725C6
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_GlaciasRoom_EventScript_272475:: @ 8272475
EverGrandeCity_PhoebesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_SidneysRoom_EventScript_272475:: @ 8272475
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_SidneysRoom_Movement_2725BA
	waitmovement 0
	playse SE_TRACK_DOOR
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_GlaciasRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_PhoebesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_SidneysRoom_EventScript_2724BC:: @ 82724BC
	setmetatile 6, 1, METATILE_EliteFour_OpenDoor_Frame, 0
	setmetatile 6, 2, METATILE_EliteFour_OpenDoor_Opening, 0
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 0, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 1, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 2, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 3, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 4, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 8, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 9, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 10, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	setmetatile 11, 2, METATILE_EliteFour_RightSpotlightOff, 1
	setmetatile 12, 2, METATILE_EliteFour_LeftSpotlightOff, 1
	return

EverGrandeCity_DrakesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_GlaciasRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_PhoebesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_SidneysRoom_EventScript_27255F:: @ 827255F
	setmetatile 5, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 6, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 7, 12, METATILE_EliteFour_EntryDoor_ClosedTop, 1
	setmetatile 5, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 6, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	setmetatile 7, 13, METATILE_EliteFour_EntryDoor_ClosedBottom, 1
	return

SlateportCity_Movement_272596: @ 8272596
	emote_question_mark
	step_end

Common_Movement_ExclamationMark: @ 8272598
	emote_exclamation_mark
	step_end

Common_Movement_Delay48: @ 827259A
	delay_16
	delay_16
	delay_16
	step_end

Common_Movement_FacePlayer: @ 827259E
	face_player
	step_end

Common_Movement_FaceAwayPlayer: @ 82725A0
	face_away_player
	step_end

Common_Movement_FaceOriginalDirection: @ 82725A2
	face_original_direction
	step_end

Common_Movement_WalkInPlaceLeft: @ 82725A4
	walk_in_place_fastest_left
	step_end

Common_Movement_WalkInPlaceUp: @ 82725A6
	walk_in_place_fastest_up
	step_end

Common_Movement_WalkInPlaceRight: @ 82725A8
	walk_in_place_fastest_right
	step_end

Common_Movement_WalkInPlaceDown: @ 82725AA
	walk_in_place_fastest_down
	step_end

RustboroCity_Movement_2725AC: @ 82725AC
	face_right
	step_end

RustboroCity_Movement_2725AE: @ 82725AE
	face_left
	step_end

Common_Movement_FaceDown: @ 82725B0
	face_down
	step_end

Common_Movement_FaceUp: @ 82725B2
	face_up
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_2725B4: @ 82725B4
MeteorFalls_1F_1R_Movement_2725B4: @ 82725B4
	walk_in_place_down
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_2725B6: @ 82725B6
BattleFrontier_BattleTowerBattleRoom_Movement_2725B6: @ 82725B6
	walk_in_place_left
	step_end

Route121_Movement_2725B8: @ 82725B8
	walk_in_place_right
	step_end

EverGrandeCity_SidneysRoom_Movement_2725BA: @ 82725BA
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_2725C1: @ 82725C1
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EverGrandeCity_SidneysRoom_Movement_2725C6: @ 82725C6
	delay_16
	delay_16
	step_end

Route110_TrickHouseEntrance_Movement_2725C9: @ 82725C9
	walk_up
	step_end

Movement_2725CB:: @ 82725CB
	walk_up
	walk_up
	step_end

EventScript_PictureBookShelf:: @ 82725CE
	msgbox Text_PictureBookShelf, MSGBOX_SIGN
	end

EventScript_BookShelf:: @ 82725D7
	msgbox Text_BookShelf, MSGBOX_SIGN
	end

EventScript_PokemonCenterBookShelf:: @ 82725E0
	msgbox Text_PokemonCenterBookShelf, MSGBOX_SIGN
	end

EventScript_Vase:: @ 82725E9
	msgbox Text_Vase, MSGBOX_SIGN
	end

EventScript_EmptyTrashCan:: @ 82725F2
	msgbox Text_EmptyTrashCan, MSGBOX_SIGN
	end

EventScript_ShopShelf:: @ 82725FB
	msgbox Text_ShopShelf, MSGBOX_SIGN
	end

EventScript_Blueprint:: @ 8272604
	msgbox Text_Blueprint, MSGBOX_SIGN
	end

Text_WouldYouLikeToMixRecords: @ 827260D
	.string "Would you like to mix records with\n"
	.string "other TRAINERS?$"

Text_WouldNotLikeToMixRecords: @ 8272640
	.string "We hope to see you again!$"

Text_BootUpPC: @ 827265A
	.string "{PLAYER} booted up the PC.$"

gText_WhichPCShouldBeAccessed:: @ 827266F
	.string "Which PC should be accessed?$"

gText_AccessedSomeonesPC:: @ 827268C
	.string "Accessed SOMEONE'S PC.$"

gText_StorageSystemOpened:: @ 82726A3
	.string "POKéMON Storage System opened.$"

gText_AccessedPlayersPC:: @ 82726C2
	.string "Accessed {PLAYER}'s PC.$"

gText_AccessedLanettesPC:: @ 82726D4
	.string "Accessed LANETTE's PC.$"

	.include "data/text/pkmn_center_nurse.inc"

gText_HowMayIServeYou:: @ 8272A21
	.string "Welcome!\p"
	.string "How may I serve you?$"

gText_PleaseComeAgain:: @ 8272A3F
	.string "Please come again!$"

gText_PlayerWhatCanIDoForYou:: @ 8272A52
	.string "{PLAYER}{STRING 5}, welcome!\p"
	.string "What can I do for you?$"

gText_ObtainedTheItem:: @ 8272A78
	.string "Obtained the {STR_VAR_2}!$"

gText_TheBagIsFull:: @ 8272A89
	.string "The BAG is full…$"

gText_PutItemInPocket:: @ 8272A9A
	.string "{PLAYER} put away the {STR_VAR_2}\n"
	.string "in the {STR_VAR_3} POCKET.$"

gText_PlayerFoundOneItem:: @ 8272ABF
	.string "{PLAYER} found one {STR_VAR_2}!$"

gText_TooBadBagIsFull:: @ 8272AD0
	.string "Too bad!\n"
	.string "The BAG is full…$"

gText_PlayerPutItemInBag:: @ 8272AEA
	.string "{PLAYER} put away the {STR_VAR_2}\n"
	.string "in the BAG.$"

gText_ObtainedTheMon:: @ 8272B09
	.string "Obtained the {STR_VAR_2}!$"

gText_NoRoomLeftForAnother:: @ 8272B1A
	.string "Too bad! There's no room left for\n"
	.string "another {STR_VAR_2}…$"

gText_TheMonWasTransferredToThePC:: @ 8272B48
	.string "The {STR_VAR_2} was transferred\n"
	.string "to the PC.$"

gText_PokemartSign:: @ 8272B6A
	.string "“Selected items for your convenience!”\n"
	.string "POKéMON MART$"

gText_PokemonCenterSign:: @ 8272B9E
	.string "“Rejuvenate your tired partners!”\n"
	.string "POKéMON CENTER$"

gText_MomOrDadMightLikeThisProgram:: @ 8272BCF
	.string "{STR_VAR_1} might like this program.\n"
	.string "… … … … … … … … … … … … … … … …\p"
	.string "Better get going!$"

gText_WhichFloorWouldYouLike:: @ 8272C1D
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\p"
	.string "Which floor would you like?$"

gText_SandstormIsVicious:: @ 8272C5F
	.string "The sandstorm is vicious.\n"
	.string "It's impossible to keep going.$"

gText_SelectWithoutRegisteredItem:: @ 8272C98
	.string "An item in the BAG can be\n"
	.string "registered to SELECT for easy use.$"

gText_PokemonTrainerSchoolEmail:: @ 8272CD5
	.string "There's an e-mail from POKéMON TRAINER\n"
	.string "SCHOOL.\p"
	.string "… … … … … …\p"
	.string "A POKéMON may learn up to four moves.\p"
	.string "A TRAINER's expertise is tested on the\n"
	.string "move sets chosen for POKéMON.\p"
	.string "… … … … … …$"

gText_PlayerHouseBootPC:: @ 8272D87
	.string "{PLAYER} booted up the PC.$"

gText_PokeblockLinkCanceled:: @ 8272D9C
	.string "The link was canceled.$"

gText_UnusedNicknameReceivedPokemon:: @ 8272DB3
	.string "Want to give a nickname to\n"
	.string "the {STR_VAR_2} you received?$"

gText_PlayerWhitedOut:: @ 8272DE3
	.string "{PLAYER} is out of usable\n"
	.string "POKéMON!\p{PLAYER} whited out!$"

gText_RegisteredTrainerinPokeNav:: @ 8272E0F
	.string "Registered {STR_VAR_1} {STR_VAR_2}\n"
	.string "in the POKéNAV.$"

gText_ComeBackWithSecretPower:: @ 8272E30
	.string "Do you know the TM SECRET POWER?\p"
	.string "Our group, we love the TM SECRET\n"
	.string "POWER.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"

gText_PokerusExplanation:: @ 8272F07
	.string "Your POKéMON may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to POKéMON.\p"
	.string "While infected, POKéMON are said to\n"
	.string "grow exceptionally well.$"

	.include "data/text/surf.inc"

gText_DoorOpenedFarAway:: @ 827301B
	.string "It sounded as if a door opened\n"
	.string "somewhere far away.$"

gText_BigHoleInTheWall:: @ 827304E
	.string "There is a big hole in the wall.$"

gText_SorryWirelessClubAdjustments:: @ 827306F
	.string "I'm terribly sorry.\n"
	.string "The POKéMON WIRELESS CLUB is\l"
	.string "undergoing adjustments now.$"

gText_UndergoingAdjustments:: @ 82730BC
	.string "It appears to be undergoing\n"
	.string "adjustments…$"

@ Unused
gText_SorryTradeCenterInspections:: @ 82730E5
	.string "I'm terribly sorry. The TRADE CENTER\n"
	.string "is undergoing inspections.$"

@ Unused
gText_SorryRecordCornerPreparation:: @ 8273125
	.string "I'm terribly sorry. The RECORD CORNER\n"
	.string "is under preparation.$"

gText_PlayerHandedOverTheItem:: @ 8273161
	.string "{PLAYER} handed over the\n"
	.string "{STR_VAR_1}.$"

gText_ThankYouForAccessingMysteryGift:: @ 8273178
	.string "Thank you for accessing the\n"
	.string "MYSTERY GIFT System.$"

gText_PlayerFoundOneItemTwoLines:: @ 82731A9
	.string "{PLAYER} found one {STR_VAR_1}\n"
	.string "{STR_VAR_2}!$"

gText_Sudowoodo_Attacked:: @ 82731BD
	.string "The weird tree doesn't like the\n"
	.string "WAILMER PAIL!\p"
	.string "The weird tree attacked!$"

gText_LegendaryFlewAway:: @ 8273204
	.string "The {STR_VAR_1} flew away!$"

gText_PkmnTransferredSomeonesPC:: @ 8273216
	.string "{STR_VAR_2} was transferred to\n"
	.string "SOMEONE'S PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC:: @ 8273256
	.string "{STR_VAR_2} was transferred to\nLANETTE'S PC.\p"
	.string "It was placed in \n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnBoxSomeonesPCFull:: @ 8273296
	.string "BOX “{STR_VAR_3}” on\n"
	.string "SOMEONE'S PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_PkmnBoxLanettesPCFull:: @ 82732D9
	.string "BOX “{STR_VAR_3}” on\n"
	.string "LANETTE'S PC was full.\p"
	.string "{STR_VAR_2} was transferred to\n"
	.string "BOX “{STR_VAR_1}.”$"

gText_NoMoreRoomForPokemon:: @ 827331C
	.string "There's no more room for POKéMON!\p"
	.string "The POKéMON BOXES are full and\n"
	.string "can't accept any more!$"

gText_NicknameThisPokemon:: @ 8273374
	.string "Do you want to give a nickname to\n"
	.string "this {STR_VAR_1}?$"

gText_FillOutQuestionnaire:: @ 827339F
	.string "There is a questionnaire.\n"
	.string "Would you like to fill it out?$"

gText_ThankYouForTakingQuestionnaire:: @ 82733D8
	.string "Thank you for taking the time to\n"
	.string "fill out our questionnaire.\p"
	.string "Your feedback will be used for\n"
	.string "future reference.$"

gUnknown_08273446:: @ 8273446
	.string "Oh, hello!\n"
	.string "You know those words?\p"
	.string "That means you must know about\n"
	.string "the MYSTERY GIFT.\p"
	.string "From now on, you should be\n"
	.string "receiving MYSTERY GIFTS!$"

gUnknown_082734CC:: @ 82734CC
	.string "Once you save your game, you can\n"
	.string "access the MYSTERY GIFT.$"

gUnknown_08273506:: @ 8273506
	.string "Oh, hello!\n"
	.string "You know those words?\p"
	.string "That means you must know about\n"
	.string "the MYSTERY EVENT.$"

gUnknown_08273559:: @ 8273559
	.string "Once you save your game, you can\n"
	.string "access the MYSTERY EVENT.$"

gUnknown_08273594:: @ 8273594
	.string "Thank you for using the MYSTERY\n"
	.string "EVENT System.\p"
	.string "You must be {PLAYER}.\n"
	.string "There is a ticket here for you.$"

gUnknown_082735F2:: @ 82735F2
	.string "It appears to be for use at\n"
	.string "the LILYCOVE CITY port.\p"
	.string "Why not give it a try and see what\n"
	.string "it is about?$"

gText_UnusualWeatherEnded_Rain:: @ 8273656
	.string "The massive downpour appears to\n"
	.string "have stopped…$"

gText_UnusualWeatherEnded_Sun:: @ 8273684
	.string "The intense sunshine appears to\n"
	.string "have subsided…$"

EventScript_SelectWithoutRegisteredItem:: @ 82736B3
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

EventScript_Poison:: @ 82736BC
	lockall
	special ExecuteWhiteOut
	waitstate
	compare VAR_RESULT, 1
	goto_if_eq EventScript_2736D9
	compare VAR_RESULT, 2
	goto_if_eq EventScript_2736F8
	releaseall
	end

EventScript_2736D9:: @ 82736D9
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	special sub_80B05B4
	waitstate
	fadescreen 1
	call_if_set FLAG_FLANNERY_GIVES_BADGE_INFO, EventScript_2736F4
	special sp0C8_whiteout_maybe
	waitstate
	end

EventScript_2736F4:: @ 82736F4
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	return

EventScript_2736F8:: @ 82736F8
	message gText_PlayerWhitedOut
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 16
	special CallBattlePikeFunction
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4222
	setvar VAR_0x8004, 12
	special CallBattlePyramidFunction
	compare VAR_RESULT, 1
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_252B42
	compare VAR_RESULT, 2
	goto_if_eq BattleFrontier_BattlePyramidTop_EventScript_252B42
	setvar VAR_0x8004, TRAINER_HILL_FUNC_10
	special CallTrainerHillFunction
	compare VAR_RESULT, 1
	goto_if_eq TrainerHill_1F_EventScript_2C83C9
	special sub_80B05B4
	waitstate
	fadescreen 1
	special sp0C8_whiteout_maybe
	waitstate
	end

Common_EventScript_NopReturn:: @ 827374E
	return

@ Unused
EventScript_CableClub_SetVarResult1:: @ 827374F
	setvar VAR_RESULT, 1
	return

EventScript_CableClub_SetVarResult0:: @ 8273755
	setvar VAR_RESULT, 0
	return

BattleFrontier_PokemonCenter_2F_EventScript_27375B:: @ 827375B
DewfordTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
EverGrandeCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
EverGrandeCity_PokemonLeague_2F_EventScript_27375B:: @ 827375B
FallarborTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
FortreeCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
LavaridgeTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
LilycoveCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
MauvilleCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
MossdeepCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
OldaleTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
PacifidlogTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
PetalburgCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
RustboroCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
SlateportCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
SootopolisCity_PokemonCenter_2F_EventScript_27375B:: @ 827375B
VerdanturfTown_PokemonCenter_2F_EventScript_27375B:: @ 827375B
	call OldaleTown_PokemonCenter_2F_EventScript_27751B
	end

BattleFrontier_PokemonCenter_2F_EventScript_273761:: @ 8273761
DewfordTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
EverGrandeCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
EverGrandeCity_PokemonLeague_2F_EventScript_273761:: @ 8273761
FallarborTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
FortreeCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
LavaridgeTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
LilycoveCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
MauvilleCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
MossdeepCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
OldaleTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
PacifidlogTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
PetalburgCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
RustboroCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
SlateportCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
SootopolisCity_PokemonCenter_2F_EventScript_273761:: @ 8273761
VerdanturfTown_PokemonCenter_2F_EventScript_273761:: @ 8273761
	call OldaleTown_PokemonCenter_2F_EventScript_277672
	end

BattleFrontier_PokemonCenter_2F_EventScript_273767:: @ 8273767
DewfordTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
EverGrandeCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
EverGrandeCity_PokemonLeague_2F_EventScript_273767:: @ 8273767
FallarborTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
FortreeCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
LavaridgeTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
LilycoveCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
MauvilleCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
MossdeepCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
OldaleTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
PacifidlogTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
PetalburgCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
RustboroCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
SlateportCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
SootopolisCity_PokemonCenter_2F_EventScript_273767:: @ 8273767
VerdanturfTown_PokemonCenter_2F_EventScript_273767:: @ 8273767
	call OldaleTown_PokemonCenter_2F_EventScript_2776A4
	end

Common_EventScript_RemoveStaticPokemon:: @ 827376D
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	release
	end

Common_EventScript_LegendaryFlewAway:: @ 8273776
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	bufferspeciesname 0, VAR_0x8004
	msgbox gText_LegendaryFlewAway, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8004 here is used by ChangePokemonNickname
Common_EventScript_GetGiftMonPartySlot:: @ 827378B
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	return

Common_EventScript_NameReceivedBoxMon:: @ 8273797
	fadescreen 1
	special ChangeBoxPokemonNickname
	waitstate
	lock
	faceplayer
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737A0:: @ 82737A0
MossdeepCity_StevensHouse_EventScript_2737A0:: @ 82737A0
Route119_WeatherInstitute_2F_EventScript_2737A0:: @ 82737A0
RustboroCity_DevonCorp_2F_EventScript_2737A0:: @ 82737A0
	bufferboxname 0, VAR_PC_BOX_TO_SEND_MON
	bufferspeciesname 1, VAR_TEMP_1
	call_if_unset FLAG_SYS_PC_LANETTE, LittlerootTown_ProfessorBirchsLab_EventScript_2737BB
	call_if_set FLAG_SYS_PC_LANETTE, LittlerootTown_ProfessorBirchsLab_EventScript_2737E6
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737BB:: @ 82737BB
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_2737D4
	msgbox gText_PkmnTransferredSomeonesPC, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737D4:: @ 82737D4
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname 2, VAR_RESULT
	msgbox gText_PkmnBoxSomeonesPCFull, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737E6:: @ 82737E6
	specialvar VAR_RESULT, ShouldShowBoxWasFullMessage
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_2737FF
	msgbox gText_PkmnTransferredLanettesPC, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737FF:: @ 82737FF
	specialvar VAR_RESULT, GetPCBoxToSendMon
	bufferboxname 2, VAR_RESULT
	msgbox gText_PkmnBoxLanettesPCFull, MSGBOX_DEFAULT
	return

Common_EventScript_NoMoreRoomForPokemon:: @ 8273811
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	release
	end

EventScript_Questionnaire:: @ 827381B
	lockall
	msgbox gText_FillOutQuestionnaire, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_2738FD
	setvar VAR_0x8004, EASY_CHAT_TYPE_QUESTIONNAIRE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	specialvar VAR_0x8008, GetMartEmployeeObjectEventId
	compare VAR_0x8004, 1
	goto_if_eq EventScript_27386D
	compare VAR_0x8004, 2
	goto_if_eq EventScript_2738B5
	compare VAR_RESULT, 0
	goto_if_eq EventScript_2738FD
	compare VAR_RESULT, 1
	goto_if_eq EventScript_2738FF
	end

EventScript_27386D:: @ 827386D
	goto_if_unset FLAG_SYS_POKEDEX_GET, EventScript_2738FF
	goto_if_set FLAG_SYS_MYSTERY_EVENT_ENABLE, EventScript_2738FF
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox gUnknown_08273506, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	msgbox gUnknown_08273559, MSGBOX_DEFAULT
	releaseall
	end

EventScript_2738B5:: @ 82738B5
	goto_if_unset FLAG_SYS_POKEDEX_GET, EventScript_2738FF
	goto_if_set FLAG_SYS_MYSTERY_GIFT_ENABLE, EventScript_2738FF
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_Delay48
	waitmovement 0
	msgbox gUnknown_08273446, MSGBOX_DEFAULT
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	msgbox gUnknown_082734CC, MSGBOX_DEFAULT
	releaseall
	end

EventScript_2738FD:: @ 82738FD
	releaseall
	end

EventScript_2738FF:: @ 82738FF
	applymovement VAR_0x8008, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_ThankYouForTakingQuestionnaire, MSGBOX_DEFAULT
	releaseall
	end

UnusualWeather_EventScript_PlaceTilesRoute114North:: @ 8273913
	setmetatile 7, 3, METATILE_Fallarbor_RedCaveEntrance_Top, 1
	setmetatile 7, 4, METATILE_Fallarbor_RedCaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute114South:: @ 8273926
	setmetatile 6, 45, METATILE_Fallarbor_BrownCaveEntrance_Top, 1
	setmetatile 6, 46, METATILE_Fallarbor_BrownCaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute115West:: @ 8273939
	setmetatile 21, 5, METATILE_Fallarbor_BrownCaveEntrance_Top, 1
	setmetatile 21, 6, METATILE_Fallarbor_BrownCaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute115East:: @ 827394C
	setmetatile 36, 9, METATILE_Fallarbor_BrownCaveEntrance_Top, 1
	setmetatile 36, 10, METATILE_Fallarbor_BrownCaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute116North:: @ 827395F
	setmetatile 59, 12, METATILE_General_CaveEntrance_Top, 1
	setmetatile 59, 13, METATILE_General_CaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute116South:: @ 8273972
	setmetatile 79, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 79, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute118East:: @ 8273985
	setmetatile 42, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 42, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute118West:: @ 8273998
	setmetatile 9, 5, METATILE_General_CaveEntrance_Top, 1
	setmetatile 9, 6, METATILE_General_CaveEntrance_Bottom, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute105North:: @ 82739AB
	setmetatile 10, 28, METATILE_General_RoughWater, 0
	setmetatile 11, 28, METATILE_General_RoughWater, 0
	setmetatile 9, 29, METATILE_General_RoughWater, 0
	setmetatile 10, 29, METATILE_General_RoughDeepWater, 0
	setmetatile 11, 29, METATILE_General_RoughDeepWater, 0
	setmetatile 12, 29, METATILE_General_RoughWater, 0
	setmetatile 9, 30, METATILE_General_RoughWater, 0
	setmetatile 10, 30, METATILE_General_RoughDeepWater, 0
	setmetatile 11, 30, METATILE_General_RoughDeepWater, 0
	setmetatile 12, 30, METATILE_General_RoughWater, 0
	setmetatile 10, 31, METATILE_General_RoughWater, 0
	setmetatile 11, 31, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute105South:: @ 8273A18
	setmetatile 20, 53, METATILE_General_RoughWater, 0
	setmetatile 21, 53, METATILE_General_RoughWater, 0
	setmetatile 19, 54, METATILE_General_RoughWater, 0
	setmetatile 20, 54, METATILE_General_RoughDeepWater, 0
	setmetatile 21, 54, METATILE_General_RoughDeepWater, 0
	setmetatile 22, 54, METATILE_General_RoughWater, 0
	setmetatile 19, 55, METATILE_General_RoughWater, 0
	setmetatile 20, 55, METATILE_General_RoughDeepWater, 0
	setmetatile 21, 55, METATILE_General_RoughDeepWater, 0
	setmetatile 22, 55, METATILE_General_RoughWater, 0
	setmetatile 20, 56, METATILE_General_RoughWater, 0
	setmetatile 21, 56, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute125West:: @ 8273A85
	setmetatile 8, 16, METATILE_General_RoughWater, 0
	setmetatile 9, 16, METATILE_General_RoughWater, 0
	setmetatile 7, 17, METATILE_General_RoughWater, 0
	setmetatile 8, 17, METATILE_General_RoughDeepWater, 0
	setmetatile 9, 17, METATILE_General_RoughDeepWater, 0
	setmetatile 10, 17, METATILE_General_RoughWater, 0
	setmetatile 7, 18, METATILE_General_RoughWater, 0
	setmetatile 8, 18, METATILE_General_RoughDeepWater, 0
	setmetatile 9, 18, METATILE_General_RoughDeepWater, 0
	setmetatile 10, 18, METATILE_General_RoughWater, 0
	setmetatile 8, 19, METATILE_General_RoughWater, 0
	setmetatile 9, 19, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute125East:: @ 8273AF2
	setmetatile 53, 18, METATILE_General_RoughWater, 0
	setmetatile 54, 18, METATILE_General_RoughWater, 0
	setmetatile 52, 19, METATILE_General_RoughWater, 0
	setmetatile 53, 19, METATILE_General_RoughDeepWater, 0
	setmetatile 54, 19, METATILE_General_RoughDeepWater, 0
	setmetatile 55, 19, METATILE_General_RoughWater, 0
	setmetatile 52, 20, METATILE_General_RoughWater, 0
	setmetatile 53, 20, METATILE_General_RoughDeepWater, 0
	setmetatile 54, 20, METATILE_General_RoughDeepWater, 0
	setmetatile 55, 20, METATILE_General_RoughWater, 0
	setmetatile 53, 21, METATILE_General_RoughWater, 0
	setmetatile 54, 21, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute127North:: @ 8273B5F
	setmetatile 57, 9, METATILE_General_RoughWater, 0
	setmetatile 58, 9, METATILE_General_RoughWater, 0
	setmetatile 56, 10, METATILE_General_RoughWater, 0
	setmetatile 57, 10, METATILE_General_RoughDeepWater, 0
	setmetatile 58, 10, METATILE_General_RoughDeepWater, 0
	setmetatile 59, 10, METATILE_General_RoughWater, 0
	setmetatile 56, 11, METATILE_General_RoughWater, 0
	setmetatile 57, 11, METATILE_General_RoughDeepWater, 0
	setmetatile 58, 11, METATILE_General_RoughDeepWater, 0
	setmetatile 59, 11, METATILE_General_RoughWater, 0
	setmetatile 57, 12, METATILE_General_RoughWater, 0
	setmetatile 58, 12, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute127South:: @ 8273BCC
	setmetatile 61, 30, METATILE_General_RoughWater, 0
	setmetatile 62, 30, METATILE_General_RoughWater, 0
	setmetatile 60, 31, METATILE_General_RoughWater, 0
	setmetatile 61, 31, METATILE_General_RoughDeepWater, 0
	setmetatile 62, 31, METATILE_General_RoughDeepWater, 0
	setmetatile 63, 31, METATILE_General_RoughWater, 0
	setmetatile 60, 32, METATILE_General_RoughWater, 0
	setmetatile 61, 32, METATILE_General_RoughDeepWater, 0
	setmetatile 62, 32, METATILE_General_RoughDeepWater, 0
	setmetatile 63, 32, METATILE_General_RoughWater, 0
	setmetatile 61, 33, METATILE_General_RoughWater, 0
	setmetatile 62, 33, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute129West:: @ 8273C39
	setmetatile 16, 14, METATILE_General_RoughWater, 0
	setmetatile 17, 14, METATILE_General_RoughWater, 0
	setmetatile 15, 15, METATILE_General_RoughWater, 0
	setmetatile 16, 15, METATILE_General_RoughDeepWater, 0
	setmetatile 17, 15, METATILE_General_RoughDeepWater, 0
	setmetatile 18, 15, METATILE_General_RoughWater, 0
	setmetatile 15, 16, METATILE_General_RoughWater, 0
	setmetatile 16, 16, METATILE_General_RoughDeepWater, 0
	setmetatile 17, 16, METATILE_General_RoughDeepWater, 0
	setmetatile 18, 16, METATILE_General_RoughWater, 0
	setmetatile 16, 17, METATILE_General_RoughWater, 0
	setmetatile 17, 17, METATILE_General_RoughWater, 0
	return

UnusualWeather_EventScript_PlaceTilesRoute129East:: @ 8273CA6
	setmetatile 42, 19, METATILE_General_RoughWater, 0
	setmetatile 43, 19, METATILE_General_RoughWater, 0
	setmetatile 41, 20, METATILE_General_RoughWater, 0
	setmetatile 42, 20, METATILE_General_RoughDeepWater, 0
	setmetatile 43, 20, METATILE_General_RoughDeepWater, 0
	setmetatile 44, 20, METATILE_General_RoughWater, 0
	setmetatile 41, 21, METATILE_General_RoughWater, 0
	setmetatile 42, 21, METATILE_General_RoughDeepWater, 0
	setmetatile 43, 21, METATILE_General_RoughDeepWater, 0
	setmetatile 44, 21, METATILE_General_RoughWater, 0
	setmetatile 42, 22, METATILE_General_RoughWater, 0
	setmetatile 43, 22, METATILE_General_RoughWater, 0
	return

Route105_EventScript_273D13:: @ 8273D13
Route114_EventScript_273D13:: @ 8273D13
Route115_EventScript_273D13:: @ 8273D13
Route116_EventScript_273D13:: @ 8273D13
Route118_EventScript_273D13:: @ 8273D13
Route125_EventScript_273D13:: @ 8273D13
Route127_EventScript_273D13:: @ 8273D13
Route129_EventScript_273D13:: @ 8273D13
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

UnusualWeather_StartKyogreWeather:: @ 8273D17
	setweather WEATHER_RAIN_HEAVY
	return

UnusualWeather_StartGroudonWeather:: @ 8273D1B
	setweather WEATHER_DROUGHT
	return

UnusualWeather_EventScript_EndEventAndCleanup_1:: @ 8273D1F
	lockall
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_KYOGRE_LOCATIONS_START
	goto_if_ge UnusualWeather_EventScript_ShowRainEndedMessage
	goto UnusualWeather_EventScript_ShowSunEndedMessage
	end

UnusualWeather_EventScript_EndEventAndCleanup_2:: @ 8273D31
	closemessage
	fadescreenswapbuffers 1
	setweather WEATHER_SUNNY
	doweather
	call UnusualWeather_EventScript_CleanupMapTiles
	special DrawWholeMapView
	setvar VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_NONE
	setvar VAR_SHOULD_END_UNUSUAL_WEATHER, 0
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	fadescreenswapbuffers 0
	releaseall
	end

UnusualWeather_EventScript_ShowRainEndedMessage:: @ 8273D51
	msgbox gText_UnusualWeatherEnded_Rain, MSGBOX_DEFAULT
	goto UnusualWeather_EventScript_EndEventAndCleanup_2
	end

UnusualWeather_EventScript_ShowSunEndedMessage:: @ 8273D5F
	msgbox gText_UnusualWeatherEnded_Sun, MSGBOX_DEFAULT
	goto UnusualWeather_EventScript_EndEventAndCleanup_2
	end

UnusualWeather_EventScript_CleanupMapTiles:: @ 8273D6D
	switch VAR_UNUSUAL_WEATHER_LOCATION
	case UNUSUAL_WEATHER_ROUTE_114_NORTH, UnusualWeather_EventScript_CleanupRoute114North
	case UNUSUAL_WEATHER_ROUTE_114_SOUTH, UnusualWeather_EventScript_CleanupRoute114South
	case UNUSUAL_WEATHER_ROUTE_115_WEST, UnusualWeather_EventScript_CleanupRoute115West
	case UNUSUAL_WEATHER_ROUTE_115_EAST, UnusualWeather_EventScript_CleanupRoute115East
	case UNUSUAL_WEATHER_ROUTE_116_NORTH, UnusualWeather_EventScript_CleanupRoute116North
	case UNUSUAL_WEATHER_ROUTE_116_SOUTH, UnusualWeather_EventScript_CleanupRoute116South
	case UNUSUAL_WEATHER_ROUTE_118_EAST, UnusualWeather_EventScript_CleanupRoute118East
	case UNUSUAL_WEATHER_ROUTE_118_WEST, UnusualWeather_EventScript_CleanupRoute118West
	case UNUSUAL_WEATHER_ROUTE_105_NORTH, UnusualWeather_EventScript_CleanupRoute105North
	case UNUSUAL_WEATHER_ROUTE_105_SOUTH, UnusualWeather_EventScript_CleanupRoute105South
	case UNUSUAL_WEATHER_ROUTE_125_WEST, UnusualWeather_EventScript_CleanupRoute125West
	case UNUSUAL_WEATHER_ROUTE_125_EAST, UnusualWeather_EventScript_CleanupRoute125East
	case UNUSUAL_WEATHER_ROUTE_127_NORTH, UnusualWeather_EventScript_CleanupRoute127North
	case UNUSUAL_WEATHER_ROUTE_127_SOUTH, UnusualWeather_EventScript_CleanupRoute127South
	case UNUSUAL_WEATHER_ROUTE_129_WEST, UnusualWeather_EventScript_CleanupRoute129West
	case UNUSUAL_WEATHER_ROUTE_129_EAST, UnusualWeather_EventScript_CleanupRoute129East
	return

UnusualWeather_EventScript_CleanupRoute114North:: @ 8273E23
	setmetatile 7, 3, METATILE_Fallarbor_RedRockWall, 1
	setmetatile 7, 4, METATILE_Fallarbor_RedRockWall, 1
	return

UnusualWeather_EventScript_CleanupRoute114South:: @ 8273E36
	setmetatile 6, 45, METATILE_Fallarbor_BrownRockWall, 1
	setmetatile 6, 46, METATILE_Fallarbor_BrownRockWall, 1
	return

UnusualWeather_EventScript_CleanupRoute115West:: @ 8273E49
	setmetatile 21, 5, METATILE_Fallarbor_BrownRockWall, 1
	setmetatile 21, 6, METATILE_Fallarbor_BrownRockWall, 1
	return

UnusualWeather_EventScript_CleanupRoute115East:: @ 8273E5C
	setmetatile 36, 9, METATILE_Fallarbor_BrownRockWall, 1
	setmetatile 36, 10, METATILE_Fallarbor_BrownRockWall, 1
	return

UnusualWeather_EventScript_CleanupRoute116North:: @ 8273E6F
	setmetatile 59, 12, METATILE_General_RockWall_RockBase, 1
	setmetatile 59, 13, METATILE_General_RockWall_RockBase, 1
	return

UnusualWeather_EventScript_CleanupRoute116South:: @ 8273E82
	setmetatile 79, 5, METATILE_General_RockWall_RockBase, 1
	setmetatile 79, 6, METATILE_General_RockWall_RockBase, 1
	return

UnusualWeather_EventScript_CleanupRoute118East:: @ 8273E95
	setmetatile 42, 5, METATILE_General_RockWall_RockBase, 1
	setmetatile 42, 6, METATILE_General_RockWall_GrassBase, 1
	return

UnusualWeather_EventScript_CleanupRoute118West:: @ 8273EA8
	setmetatile 9, 5, METATILE_General_RockWall_RockBase, 1
	setmetatile 9, 6, METATILE_General_RockWall_GrassBase, 1
	return

UnusualWeather_EventScript_CleanupRoute105North:: @ 8273EBB
	setmetatile 10, 28, METATILE_General_CalmWater, 0
	setmetatile 11, 28, METATILE_General_CalmWater, 0
	setmetatile 9, 29, METATILE_General_CalmWater, 0
	setmetatile 10, 29, METATILE_General_CalmWater, 0
	setmetatile 11, 29, METATILE_General_CalmWater, 0
	setmetatile 12, 29, METATILE_General_CalmWater, 0
	setmetatile 9, 30, METATILE_General_CalmWater, 0
	setmetatile 10, 30, METATILE_General_CalmWater, 0
	setmetatile 11, 30, METATILE_General_CalmWater, 0
	setmetatile 12, 30, METATILE_General_CalmWater, 0
	setmetatile 10, 31, METATILE_General_CalmWater, 0
	setmetatile 11, 31, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute105South:: @ 8273F28
	setmetatile 20, 53, METATILE_General_CalmWater, 0
	setmetatile 21, 53, METATILE_General_CalmWater, 0
	setmetatile 19, 54, METATILE_General_CalmWater, 0
	setmetatile 20, 54, METATILE_General_CalmWater, 0
	setmetatile 21, 54, METATILE_General_CalmWater, 0
	setmetatile 22, 54, METATILE_General_CalmWater, 0
	setmetatile 19, 55, METATILE_General_CalmWater, 0
	setmetatile 20, 55, METATILE_General_CalmWater, 0
	setmetatile 21, 55, METATILE_General_CalmWater, 0
	setmetatile 22, 55, METATILE_General_CalmWater, 0
	setmetatile 20, 56, METATILE_General_CalmWater, 0
	setmetatile 21, 56, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute125West:: @ 8273F95
	setmetatile 8, 16, METATILE_General_CalmWater, 0
	setmetatile 9, 16, METATILE_General_CalmWater, 0
	setmetatile 7, 17, METATILE_General_CalmWater, 0
	setmetatile 8, 17, METATILE_General_CalmWater, 0
	setmetatile 9, 17, METATILE_General_CalmWater, 0
	setmetatile 10, 17, METATILE_General_CalmWater, 0
	setmetatile 7, 18, METATILE_General_CalmWater, 0
	setmetatile 8, 18, METATILE_General_CalmWater, 0
	setmetatile 9, 18, METATILE_General_CalmWater, 0
	setmetatile 10, 18, METATILE_General_CalmWater, 0
	setmetatile 8, 19, METATILE_General_CalmWater, 0
	setmetatile 9, 19, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute125East:: @ 8274002
	setmetatile 53, 18, METATILE_General_CalmWater, 0
	setmetatile 54, 18, METATILE_General_CalmWater, 0
	setmetatile 52, 19, METATILE_General_CalmWater, 0
	setmetatile 53, 19, METATILE_General_CalmWater, 0
	setmetatile 54, 19, METATILE_General_CalmWater, 0
	setmetatile 55, 19, METATILE_General_CalmWater, 0
	setmetatile 52, 20, METATILE_General_CalmWater, 0
	setmetatile 53, 20, METATILE_General_CalmWater, 0
	setmetatile 54, 20, METATILE_General_CalmWater, 0
	setmetatile 55, 20, METATILE_General_CalmWater, 0
	setmetatile 53, 21, METATILE_General_CalmWater, 0
	setmetatile 54, 21, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute127North:: @ 827406F
	setmetatile 57, 9, METATILE_General_CalmWater, 0
	setmetatile 58, 9, METATILE_General_CalmWater, 0
	setmetatile 56, 10, METATILE_General_CalmWater, 0
	setmetatile 57, 10, METATILE_General_CalmWater, 0
	setmetatile 58, 10, METATILE_General_CalmWater, 0
	setmetatile 59, 10, METATILE_General_CalmWater, 0
	setmetatile 56, 11, METATILE_General_CalmWater, 0
	setmetatile 57, 11, METATILE_General_CalmWater, 0
	setmetatile 58, 11, METATILE_General_CalmWater, 0
	setmetatile 59, 11, METATILE_General_CalmWater, 0
	setmetatile 57, 12, METATILE_General_CalmWater, 0
	setmetatile 58, 12, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute127South:: @ 82740DC
	setmetatile 61, 30, METATILE_General_CalmWater, 0
	setmetatile 62, 30, METATILE_General_CalmWater, 0
	setmetatile 60, 31, METATILE_General_CalmWater, 0
	setmetatile 61, 31, METATILE_General_CalmWater, 0
	setmetatile 62, 31, METATILE_General_CalmWater, 0
	setmetatile 63, 31, METATILE_General_CalmWater, 0
	setmetatile 60, 32, METATILE_General_CalmWater, 0
	setmetatile 61, 32, METATILE_General_CalmWater, 0
	setmetatile 62, 32, METATILE_General_CalmWater, 0
	setmetatile 63, 32, METATILE_General_CalmWater, 0
	setmetatile 61, 33, METATILE_General_CalmWater, 0
	setmetatile 62, 33, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute129West:: @ 8274149
	setmetatile 16, 14, METATILE_General_CalmWater, 0
	setmetatile 17, 14, METATILE_General_CalmWater, 0
	setmetatile 15, 15, METATILE_General_CalmWater, 0
	setmetatile 16, 15, METATILE_General_CalmWater, 0
	setmetatile 17, 15, METATILE_General_CalmWater, 0
	setmetatile 18, 15, METATILE_General_CalmWater, 0
	setmetatile 15, 16, METATILE_General_CalmWater, 0
	setmetatile 16, 16, METATILE_General_CalmWater, 0
	setmetatile 17, 16, METATILE_General_CalmWater, 0
	setmetatile 18, 16, METATILE_General_CalmWater, 0
	setmetatile 16, 17, METATILE_General_CalmWater, 0
	setmetatile 17, 17, METATILE_General_CalmWater, 0
	return

UnusualWeather_EventScript_CleanupRoute129East:: @ 82741B6
	setmetatile 42, 19, METATILE_General_CalmWater, 0
	setmetatile 43, 19, METATILE_General_CalmWater, 0
	setmetatile 41, 20, METATILE_General_CalmWater, 0
	setmetatile 42, 20, METATILE_General_CalmWater, 0
	setmetatile 43, 20, METATILE_General_CalmWater, 0
	setmetatile 44, 20, METATILE_General_CalmWater, 0
	setmetatile 41, 21, METATILE_General_CalmWater, 0
	setmetatile 42, 21, METATILE_General_CalmWater, 0
	setmetatile 43, 21, METATILE_General_CalmWater, 0
	setmetatile 44, 21, METATILE_General_CalmWater, 0
	setmetatile 42, 22, METATILE_General_CalmWater, 0
	setmetatile 43, 22, METATILE_General_CalmWater, 0
	return

UnusualWeather_Underwater_SetupEscapeWarp:: @ 8274223
	switch VAR_UNUSUAL_WEATHER_LOCATION
	case UNUSUAL_WEATHER_ROUTE_105_NORTH, UnusualWeather_Underwater_SetupEscapeWarpRoute105North
	case UNUSUAL_WEATHER_ROUTE_105_SOUTH, UnusualWeather_Underwater_SetupEscapeWarpRoute105South
	case UNUSUAL_WEATHER_ROUTE_125_WEST, UnusualWeather_Underwater_SetupEscapeWarpRoute125West
	case UNUSUAL_WEATHER_ROUTE_125_EAST, UnusualWeather_Underwater_SetupEscapeWarpRoute125East
	case UNUSUAL_WEATHER_ROUTE_127_NORTH, UnusualWeather_Underwater_SetupEscapeWarpRoute127North
	case UNUSUAL_WEATHER_ROUTE_127_SOUTH, UnusualWeather_Underwater_SetupEscapeWarpRoute127South
	case UNUSUAL_WEATHER_ROUTE_129_WEST, UnusualWeather_Underwater_SetupEscapeWarpRoute129West
	case UNUSUAL_WEATHER_ROUTE_129_EAST, UnusualWeather_Underwater_SetupEscapeWarpRoute129East
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute105North:: @ 8274281
	setescapewarp MAP_ROUTE105, 255, 11, 29
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute105South:: @ 827428A
	setescapewarp MAP_ROUTE105, 255, 21, 54
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute125West:: @ 8274293
	setescapewarp MAP_ROUTE125, 255, 9, 17
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute125East:: @ 827429C
	setescapewarp MAP_ROUTE125, 255, 54, 19
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute127North:: @ 82742A5
	setescapewarp MAP_ROUTE127, 255, 58, 10
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute127South:: @ 82742AE
	setescapewarp MAP_ROUTE127, 255, 62, 31
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute129West:: @ 82742B7
	setescapewarp MAP_ROUTE129, 255, 17, 15
	return

UnusualWeather_Underwater_SetupEscapeWarpRoute129East:: @ 82742C0
	setescapewarp MAP_ROUTE129, 255, 43, 20
	return

Std_RegisteredInMatchCall:: @ 82742C9
	buffertrainerclassname 0, VAR_0x8000
	buffertrainername 1, VAR_0x8000
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox gText_RegisteredTrainerinPokeNav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	return

EventScript_TryGetTrainerScript:: @ 82742E6
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_if_eq EventScript_GotoTrainerScript
	releaseall
	end

EventScript_GotoTrainerScript:: @ 82742F6
	gotobeatenscript
	releaseall
	end

	.include "data/scripts/berry_tree.inc"
	.include "data/scripts/secret_base.inc"
	.include "data/scripts/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"

gUnknown_0827E8CE:: @ 827E8CE
	.string "Missed turn$"

gText_LinkStandby4:: @ 827E8DA
	.string "Link standby!$"

gUnknown_0827E8E8:: @ 827E8E8
	.string "The winner is {STR_VAR_1}'s {STR_VAR_2}!\n"
	.string "Congratulations!$"

gUnknown_0827E910:: @ 827E910
	.string "The winner is {STR_VAR_1}'s {STR_VAR_2}!{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E929:: @ 827E929
	.string "Primary judging: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E943:: @ 827E943
	.string "Secondary judging: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E95F:: @ 827E95F
	.string "Set event: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E973:: @ 827E973
	.string "The move used most often:\n"
	.string "{STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E992:: @ 827E992
	.string "The most impressive POKéMON:\n"
	.string "{STR_VAR_1}'s {STR_VAR_2}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E9B9:: @ 827E9B9
	.string "Set event: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E9CD:: @ 827E9CD
	.string "A link TV program will not be made\n"
	.string "because the TRAINER lost.{PAUSE_UNTIL_PRESS}$"

gUnknown_0827EA0C:: @ 827EA0C
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_2}'s {STR_VAR_3}$"

gUnknown_0827EA17:: @ 827EA17
	.string "CONTEST$"

gContestRankNormal::
	.string "NORMAL RANK$"

gContestRankSuper::
	.string "SUPER RANK$"

gContestRankHyper::
	.string "HYPER RANK$"

gContestRankMaster::
	.string "MASTER RANK$"

gContestLink::
	.string "LINK$"

gContestCoolness::
	.string "COOLNESS$"

gContestBeauty::
	.string "BEAUTY$"

gContestCuteness::
	.string "CUTENESS$"

gContestSmartness::
	.string "SMARTNESS$"

gContestToughness::
	.string "TOUGHNESS$"

gContestPaintingCool1::
	.string "Nonstop supercool--\n"
	.string "the inestimable {STR_VAR_1}$"

gContestPaintingCool2::
	.string "Hey, there!\n"
	.string "The good-looking POKéMON {STR_VAR_1}$"

gContestPaintingCool3::
	.string "The marvelous, wonderful, and\n"
	.string "very great {STR_VAR_1}$"

gContestPaintingBeauty1::
	.string "This century's last Venus--\n"
	.string "the beautiful {STR_VAR_1}$"

gContestPaintingBeauty2::
	.string "{STR_VAR_1}'s dazzling,\n"
	.string "glittering smile$"

gContestPaintingBeauty3::
	.string "POKéMON CENTER's super idol--\n"
	.string "the incomparable {STR_VAR_1}$"

gContestPaintingCute1::
	.string "The lovely and sweet {STR_VAR_1}$"

gContestPaintingCute2::
	.string "The pretty {STR_VAR_1}'s\n"
	.string "winning portrait$"

gContestPaintingCute3::
	.string "Give us a wink!\n"
	.string "The cutie POKéMON {STR_VAR_1}$"

gContestPaintingSmart1::
	.string "The smartness maestro--\n"
	.string "the wise POKéMON {STR_VAR_1}$"

gContestPaintingSmart2::
	.string "{STR_VAR_1}--the one chosen\n"
	.string "above all POKéMON$"

gContestPaintingSmart3::
	.string "The excellent {STR_VAR_1}'s\n"
	.string "moment of elegance$"

gContestPaintingTough1::
	.string "The powerfully muscular\n"
	.string "speedster {STR_VAR_1}$"

gContestPaintingTough2::
	.string "The strong, stronger, and\n"
	.string "strongest {STR_VAR_1}$"

gContestPaintingTough3::
	.string "The mighty tough\n"
	.string "hyper POKéMON {STR_VAR_1}$"

gTrickHouse_Mechadoll_Oddish:: @ 27ECBC
	.string "ODDISH$"

gTrickHouse_Mechadoll_Poochyena:: @ 27ECC3
	.string "POOCHYENA$"

gTrickHouse_Mechadoll_Taillow:: @ 27ECCD
	.string "TAILLOW$"

gTrickHouse_Mechadoll_Azurill:: @ 27ECD5
	.string "AZURILL$"

gTrickHouse_Mechadoll_Lotad:: @ 27ECDD
	.string "LOTAD$"

gTrickHouse_Mechadoll_Wingull:: @ 27ECE3
	.string "WINGULL$"

gTrickHouse_Mechadoll_Dustox:: @ 27ECEB
	.string "DUSTOX$"

gTrickHouse_Mechadoll_Zubat:: @ 27ECF2
	.string "ZUBAT$"

gTrickHouse_Mechadoll_Nincada:: @ 27ECF8
	.string "NINCADA$"

gTrickHouse_Mechadoll_Ralts:: @ 27ED00
	.string "RALTS$"

gTrickHouse_Mechadoll_Zigzagoon:: @ 27ED06
	.string "ZIGZAGOON$"

gTrickHouse_Mechadoll_Slakoth:: @ 27ED10
	.string "SLAKOTH$"

gTrickHouse_Mechadoll_Poochyena2:: @ 27ED18
	.string "POOCHYENA$"

gTrickHouse_Mechadoll_Shroomish:: @ 27ED22
	.string "SHROOMISH$"

gTrickHouse_Mechadoll_Zigzagoon2:: @ 27ED2C
	.string "ZIGZAGOON$"

gTrickHouse_Mechadoll_Poochyena3:: @ 27ED36
	.string "POOCHYENA$"

gTrickHouse_Mechadoll_Zubat2:: @ 27ED40
	.string "ZUBAT$"

gTrickHouse_Mechadoll_Carvanha:: @ 27ED46
	.string "CARVANHA$"

gTrickHouse_Mechadoll_BurnHeal:: @ 27ED4F
	.string "BURN HEAL$"

gTrickHouse_Mechadoll_HarborMail:: @ 27ED59
	.string "HARBOR MAIL$"

gTrickHouse_Mechadoll_SamePrice:: @ 27ED65
	.string "Same price$"

gTrickHouse_Mechadoll_60Yen:: @ 27ED70
	.string "¥60$"

gTrickHouse_Mechadoll_55Yen:: @ 27ED74
	.string "¥55$"

gTrickHouse_Mechadoll_Nothing:: @ 27ED78
	.string "Nothing$"

gTrickHouse_Mechadoll_CostMore:: @ 27ED80
	.string "They will cost more.$"

gTrickHouse_Mechadoll_CostLess:: @ 27ED95
	.string "They will cost less.$"

gTrickHouse_Mechadoll_SamePrice2:: @ 27EDAA
	.string "Same price$"

gTrickHouse_Mechadoll_Male:: @ 27EDB5
	.string "Male$"

gTrickHouse_Mechadoll_Female:: @ 27EDBA
	.string "Female$"

gTrickHouse_Mechadoll_Neither:: @ 27EDC1
	.string "Neither$"

gTrickHouse_Mechadoll_ElderlyMen:: @ 27EDC9
	.string "Elderly men$"

gTrickHouse_Mechadoll_ElderlyLadies:: @ 27EDD5
	.string "Elderly ladies$"

gTrickHouse_Mechadoll_SameNumber:: @ 27EDE4
	.string "Same number$"

gTrickHouse_Mechadoll_None:: @ 27EDF0
	.string "None$"

gTrickHouse_Mechadoll_One:: @ 27EDF5
	.string "1$"

gTrickHouse_Mechadoll_Two:: @ 27EDF7
	.string "2$"

gTrickHouse_Mechadoll_Two2:: @ 27EDF9
	.string "2$"

gTrickHouse_Mechadoll_Three:: @ 27EDFB
	.string "3$"

gTrickHouse_Mechadoll_Four:: @ 27EDFD
	.string "4$"

gTrickHouse_Mechadoll_Six:: @ 27EDFF
	.string "6$"

gTrickHouse_Mechadoll_Seven:: @ 27EE01
	.string "7$"

gTrickHouse_Mechadoll_Eight:: @ 27EE03
	.string "8$"

gTrickHouse_Mechadoll_Six2:: @ 27EE05
	.string "6$"

gTrickHouse_Mechadoll_Seven2:: @ 27EE07
	.string "7$"

gTrickHouse_Mechadoll_Eight2:: @ 27EE09
	.string "8$"

	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"

BattleFrontier_BattleTowerLobby_EventScript_28C7E9:: @ 828C7E9
LilycoveCity_ContestLobby_EventScript_28C7E9:: @ 828C7E9
SlateportCity_OceanicMuseum_1F_EventScript_28C7E9:: @ 828C7E9
SlateportCity_PokemonFanClub_EventScript_28C7E9:: @ 828C7E9
	special InterviewAfter
	incrementgamestat GAME_STAT_GOT_INTERVIEWED
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C7F0:: @ 828C7F0
	setvar VAR_0x8005, 1
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C879
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280674, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C827
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C85C
	end

SlateportCity_PokemonFanClub_EventScript_28C827:: @ 828C827
	msgbox SlateportCity_PokemonFanClub_Text_28073B, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, EASY_CHAT_PERSON_REPORTER_FEMALE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C866
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C85C
	end

SlateportCity_PokemonFanClub_EventScript_28C85C:: @ 828C85C
	msgbox SlateportCity_PokemonFanClub_Text_2805E2, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C866:: @ 828C866
	msgbox SlateportCity_PokemonFanClub_Text_280789, MSGBOX_DEFAULT
	setvar VAR_0x8005, 1
	goto SlateportCity_PokemonFanClub_EventScript_28C7E9
	end

SlateportCity_PokemonFanClub_EventScript_28C879:: @ 828C879
	msgbox SlateportCity_PokemonFanClub_Text_28062E, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C883:: @ 828C883
	lock
	faceplayer
	setvar VAR_0x8005, 2
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C939
	copyvar VAR_0x8009, VAR_0x8006
	goto_if_set FLAG_OCEANIC_MUSEUM_MET_REPORTER, SlateportCity_OceanicMuseum_1F_EventScript_28C8C8
	setflag FLAG_OCEANIC_MUSEUM_MET_REPORTER
	msgbox SlateportCity_OceanicMuseum_1F_Text_2811A0, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C8C8:: @ 828C8C8
	msgbox SlateportCity_OceanicMuseum_1F_Text_28126D, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C8E7:: @ 828C8E7
	msgbox SlateportCity_OceanicMuseum_1F_Text_2812F2, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, EASY_CHAT_PERSON_REPORTER_MALE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C926
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C91C:: @ 828C91C
	msgbox SlateportCity_OceanicMuseum_1F_Text_281367, MSGBOX_DEFAULT
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C926:: @ 828C926
	msgbox SlateportCity_OceanicMuseum_1F_Text_2813B9, MSGBOX_DEFAULT
	setvar VAR_0x8005, 2
	goto SlateportCity_OceanicMuseum_1F_EventScript_28C7E9
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C939:: @ 828C939
	msgbox SlateportCity_OceanicMuseum_1F_Text_28144D, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C943:: @ 828C943
	lock
	faceplayer
	specialvar VAR_RESULT, sub_80EF8F8
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C7F0
	setvar VAR_0x8005, 3
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28CA4F
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280270, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28C98C
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	end

SlateportCity_PokemonFanClub_EventScript_28C98C:: @ 828C98C
	msgbox SlateportCity_PokemonFanClub_Text_28034F, MSGBOX_DEFAULT
	random 3
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, SlateportCity_PokemonFanClub_EventScript_28C9C3
	case 1, SlateportCity_PokemonFanClub_EventScript_28C9D1
	case 2, SlateportCity_PokemonFanClub_EventScript_28C9DF
	end

SlateportCity_PokemonFanClub_EventScript_28C9C3:: @ 828C9C3
	msgbox SlateportCity_PokemonFanClub_Text_280393, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9D1:: @ 828C9D1
	msgbox SlateportCity_PokemonFanClub_Text_2803EF, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9DF:: @ 828C9DF
	msgbox SlateportCity_PokemonFanClub_Text_280454, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9ED:: @ 828C9ED
	setvar VAR_0x8004, EASY_CHAT_TYPE_FAN_CLUB
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	msgbox SlateportCity_PokemonFanClub_Text_2804AC, MSGBOX_DEFAULT
	setvar VAR_0x8006, 1
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	msgbox SlateportCity_PokemonFanClub_Text_280523, MSGBOX_DEFAULT
	copyvar VAR_0x8007, VAR_0x800A
	setvar VAR_0x8005, 3
	goto SlateportCity_PokemonFanClub_EventScript_28C7E9
	end

SlateportCity_PokemonFanClub_EventScript_28CA45:: @ 828CA45
	msgbox SlateportCity_PokemonFanClub_Text_2805E2, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_28CA4F:: @ 828CA4F
	msgbox SlateportCity_PokemonFanClub_Text_28062E, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_28CA59:: @ 828CA59
	lock
	faceplayer
	goto_if_set FLAG_TEMP_2, LilycoveCity_ContestLobby_EventScript_28CB21
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CB21
	copyvar VAR_0x8009, VAR_0x8006
	msgbox LilycoveCity_ContestLobby_Text_27EF15, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CA9B
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	end

LilycoveCity_ContestLobby_EventScript_28CA9B:: @ 828CA9B
	msgbox LilycoveCity_ContestLobby_Text_27EFE7, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_CONTEST_INTERVIEW
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CADA
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	end

LilycoveCity_ContestLobby_EventScript_28CAD0:: @ 828CAD0
	msgbox LilycoveCity_ContestLobby_Text_27F1EF, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_28CADA:: @ 828CADA
	setvar VAR_0x8004, 24
	special SetContestCategoryStringVarForInterview
	msgbox LilycoveCity_ContestLobby_Text_27F03E, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_CONTEST_INTERVIEW
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 1
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	msgbox LilycoveCity_ContestLobby_Text_27F0EC, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	setvar VAR_0x8005, 6
	goto LilycoveCity_ContestLobby_EventScript_28C7E9
	end

LilycoveCity_ContestLobby_EventScript_28CB21:: @ 828CB21
	msgbox LilycoveCity_ContestLobby_Text_27F23F, MSGBOX_DEFAULT
	release
	end

LilycoveCity_ContestLobby_EventScript_28CB2B:: @ 828CB2B
	compare VAR_LINK_CONTEST_ROOM_STATE, 2
	goto_if_ne LilycoveCity_ContestLobby_EventScript_28CB95
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_ContestLobby_EventScript_28CB95
	switch VAR_CONTEST_LOCATION
	case 0, LilycoveCity_ContestLobby_EventScript_28CB95
	case 2, LilycoveCity_ContestLobby_EventScript_28CB91
	case 1, LilycoveCity_ContestLobby_EventScript_28CB91
	case 3, LilycoveCity_ContestLobby_EventScript_28CB91
	case 4, LilycoveCity_ContestLobby_EventScript_28CB91
	case 5, LilycoveCity_ContestLobby_EventScript_28CB95
	end

LilycoveCity_ContestLobby_EventScript_28CB91:: @ 828CB91
	clearflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	return

LilycoveCity_ContestLobby_EventScript_28CB95:: @ 828CB95
	return

BattleFrontier_BattleTowerLobby_EventScript_28CB96:: @ 828CB96
    lock
    faceplayer
    goto_if_set FLAG_TEMP_2, BattleFrontier_BattleTowerLobby_EventScript_28CC7A
    setvar VAR_0x8005, 7
    special InterviewBefore
    compare VAR_RESULT, 1
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC7A
    copyvar VAR_0x8009, VAR_0x8006
    msgbox BattleFrontier_BattleTowerLobby_Text_27F704, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CBD8
    compare VAR_RESULT, 0
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC2E
    end

BattleFrontier_BattleTowerLobby_EventScript_28CBD8:: @ 828CBD8
    message BattleFrontier_BattleTowerLobby_Text_27F7BA
    waitmessage
    multichoice 20, 8, MULTI_SATISFACTION, 1
    copyvar VAR_0x8008, VAR_RESULT
    compare VAR_RESULT, 0
    call_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC38
    compare VAR_RESULT, 1
    call_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC41
    msgbox BattleFrontier_BattleTowerLobby_Text_27F97A, MSGBOX_DEFAULT
    setvar VAR_0x8004, EASY_CHAT_TYPE_BATTLE_TOWER_INTERVIEW
    copyvar VAR_0x8005, VAR_0x8009
    call Common_ShowEasyChatScreen
    lock
    faceplayer
    compare VAR_RESULT, 1
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC4A
    compare VAR_RESULT, 0
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
    end

BattleFrontier_BattleTowerLobby_EventScript_28CC2E:: @ 828CC2E
    msgbox BattleFrontier_BattleTowerLobby_Text_27F84C, MSGBOX_DEFAULT
    release
    end

BattleFrontier_BattleTowerLobby_EventScript_28CC38:: @ 828CC38
    msgbox BattleFrontier_BattleTowerLobby_Text_27F8AE, MSGBOX_DEFAULT
    return

BattleFrontier_BattleTowerLobby_EventScript_28CC41:: @ 828CC41
    msgbox BattleFrontier_BattleTowerLobby_Text_27F921, MSGBOX_DEFAULT
    return

BattleFrontier_BattleTowerLobby_EventScript_28CC4A:: @ 828CC4A
    compare VAR_RESULT, 0
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
    msgbox BattleFrontier_BattleTowerLobby_Text_27F9FD, MSGBOX_DEFAULT
    setflag FLAG_TEMP_2
    copyvar VAR_0x8004, VAR_0x8008
    setvar VAR_0x8005, 7
    goto BattleFrontier_BattleTowerLobby_EventScript_28C7E9
    end

BattleFrontier_BattleTowerLobby_EventScript_28CC70:: @ 828CC70
    msgbox BattleFrontier_BattleTowerLobby_Text_27FA6F, MSGBOX_DEFAULT
    release
    end

BattleFrontier_BattleTowerLobby_EventScript_28CC7A:: @ 828CC7A
    msgbox BattleFrontier_BattleTowerLobby_Text_27FAF3, MSGBOX_DEFAULT
    release
    end

BattleFrontier_BattleTowerLobby_EventScript_28CC84:: @ 828CC84
    compare VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
    setvar VAR_0x8005, 7
    special InterviewBefore
    compare VAR_RESULT, 1
    goto_if_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
    clearflag FLAG_HIDE_BATTLE_TOWER_REPORTER
    return

BattleFrontier_BattleTowerLobby_EventScript_28CCA6:: @ 828CCA6
    setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
    return

	.include "data/scripts/gabby_and_ty.inc"
	.include "data/text/pokemon_news.inc"
	.include "data/scripts/mauville_man.inc"
	.include "data/scripts/field_move_scripts.inc"
	.include "data/scripts/item_ball_scripts.inc"
	.include "data/scripts/mystery_event_club.inc"
	.include "data/scripts/day_care.inc"

EventScript_2926F8:: @ 82926F8
	animateflash 1
	setflashradius 1
	end

	.include "data/scripts/players_house.inc"

EventScript_RunningShoesManual:: @ 8292DE5
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7F66, MSGBOX_SIGN
	end

	.include "data/scripts/pokeblocks.inc"

gText_SoPretty:: @ 8294295
	.string " so pretty!$"

gText_SoDarling:: @ 82942A1
	.string " so darling!$"

gText_SoRelaxed:: @ 82942AE
	.string " so relaxed!$"

gText_SoSunny:: @ 82942BB
	.string " so sunny!$"

gText_SoDesirable:: @ 82942C6
	.string " so desirable!$"

gText_SoExciting:: @ 82942D5
	.string " so exciting!$"

gText_SoAmusing:: @ 82942E3
	.string " so amusing!$"

gText_SoMagical:: @ 82942F0
	.string " so magical!$"

gOtherText_Is:: @ 82942FD
	.string " is$"

gOtherText_DontYouAgree:: @ 8294301
	.string "\n"
	.string "Don't you agree?$"

gMauvilleManText_ISoWantToGoOnAVacation:: @ 8294313
	.string "I so want to go on a vacation.\n"
	.string "Would you happen to know a nice place?$"

gMauvilleManText_IBoughtCrayonsWith120Colors:: @ 8294359
	.string "I bought crayons with 120 colors!\n"
	.string "Don't you think that's nice?$"

gMauvilleManText_WouldntItBeNiceIfWeCouldFloat:: @ 8294398
	.string "Wouldn't it be nice if we could float\n"
	.string "away on a cloud of bubbles?$"

gMauvilleManText_WhenYouWriteOnASandyBeach:: @ 82943DA
	.string "When you write on a sandy beach,\n"
	.string "they wash away. It makes me sad.$"

gMauvilleManText_WhatsTheBottomOfTheSeaLike:: @ 829441C
	.string "What's the bottom of the sea like?\n"
	.string "Just once I would so love to go!$"

gMauvilleManText_WhenYouSeeTheSettingSunDoesIt:: @ 8294460
	.string "When you see the setting sun, does it\n"
	.string "make you want to go home?$"

gMauvilleManText_LyingBackInTheGreenGrass:: @ 82944A0
	.string "Lying back in the green grass…\n"
	.string "Oh, it's so, so nice!$"

gMauvilleManText_SecretBasesAreSoWonderful:: @ 82944D5
	.string "SECRET BASES are so wonderful!\n"
	.string "Can't you feel the excitement?$"

	.include "data/text/trainers.inc"

EventScript_RepelWoreOff:: @ 82A4B2A
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
	end

Text_RepelWoreOff: @ 82A4B33
	.string "REPEL's effect wore off…$"

	.include "data/scripts/safari_zone.inc"
	.include "data/scripts/roulette.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/event_ticket_1.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"

Text_PictureBookShelf: @ 82A81E5
	.string "There's a set of POKéMON picture books.$"

Text_BookShelf: @ 82A820D
	.string "It's filled with all sorts of books.$"

Text_PokemonCenterBookShelf: @ 82A8232
	.string "POKéMON magazines!\n"
	.string "POKéMON PAL…\p"
	.string "POKéMON HANDBOOK…\n"
	.string "ADORABLE POKéMON…$"

Text_Vase: @ 82A8276
	.string "This vase looks expensive…\n"
	.string "Peered inside…\p"
	.string "But, it was empty.$"

Text_EmptyTrashCan: @ 82A82B3
	.string "It's empty.$"

Text_ShopShelf: @ 82A82BF
	.string "The shelves brim with all sorts of\n"
	.string "POKéMON merchandise.$"

Text_Blueprint: @ 82A82F7
	.string "A blueprint of some sort?\n"
	.string "It's too complicated!$"

GraniteCave_B1F_MapScript2_2A8327: @ 82A8327
MirageTower_2F_MapScript2_2A8327: @ 82A8327
MirageTower_3F_MapScript2_2A8327: @ 82A8327
MtPyre_2F_MapScript2_2A8327: @ 82A8327
SkyPillar_2F_MapScript2_2A8327: @ 82A8327
SkyPillar_4F_MapScript2_2A8327: @ 82A8327
	map_script_2 VAR_ICE_STEP_COUNT, 0, EventScript_FallDownHole
	.2byte 0

GraniteCave_B1F_MapScript1_2A8331: @ 82A8331
MirageTower_2F_MapScript1_2A8331: @ 82A8331
MirageTower_3F_MapScript1_2A8331: @ 82A8331
MtPyre_2F_MapScript1_2A8331: @ 82A8331
	copyvar VAR_ICE_STEP_COUNT, 0x1
	end

EventScript_FallDownHole:: @ 82A8337
	lockall
	delay 20
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_B1F_Movement_2A8369
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warphole MAP_UNDEFINED
	waitstate
	end

gUnknown_082A8350:: @ 82A8350
	lockall
	delay 20
	applymovement EVENT_OBJ_ID_PLAYER, GraniteCave_B1F_Movement_2A8369
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	special DoFallWarp
	waitstate
	end

GraniteCave_B1F_Movement_2A8369: @ 82A8369
	set_invisible
	step_end

	.include "data/scripts/lilycove_lady.inc"
	.include "data/text/match_call.inc"
	.include "data/scripts/apprentice.inc"
	.include "data/text/battle_dome.inc"
	.include "data/scripts/battle_pike.inc"
	.include "data/text/contest_hall.inc"
	.include "data/text/battle_tent.inc"
	.include "data/text/event_ticket_2.inc"
	.include "data/text/move_tutors.inc"
	.include "data/scripts/move_tutors.inc"
	.include "data/scripts/trainer_hill.inc"

Text_ThisIsATestSignpostMsg:: @ 82C840A
	.string "This is a test message.\n"
	.string "This is a signpost.$"

EventScript_TestSignpostMsg:: @ 82C8436
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end

gText_082C843F:: @ 82C843F
	.string "It's very disappointing…$"

gText_082C8458:: @ 82C8458
	.string "Okay, I understand…$"

gText_082C846C:: @ 82C846C
	.string "I'm terribly sorry…$"

gText_082C8480:: @ 82C8480
	.string "Thank you…$"

gText_082C848B:: @ 82C848B
	.string "Ahahaha! Aren't you embarrassed?\n"
	.string "Everyone's watching!$"

gText_082C84C1:: @ 82C84C1
	.string "Grr…\n"
	.string "What the…$"

gText_082C84D0:: @ 82C84D0
	.string "My DOME ACE title isn't just for show!$"

gText_082C84F7:: @ 82C84F7
	.string "Ahahaha!\n"
	.string "You're inspiring!$"

gText_082C8512:: @ 82C8512
	.string "Way to work!\n"
	.string "That was a good lesson, eh?$"

gText_082C853B:: @ 82C853B
	.string "Good job!\n"
	.string "You know what you're doing!$"

gText_082C8561:: @ 82C8561
	.string "Hey, hey, hey!\n"
	.string "You're finished already?$"

gText_082C8589:: @ 82C8589
	.string "What happened here?$"

gText_082C859D:: @ 82C859D
	.string "Humph…$"

gText_082C85A4:: @ 82C85A4
	.string "Urk…$"

gText_082C85A9:: @ 82C85A9
	.string "Hah!$"

gText_082C85AE:: @ 82C85AE
	.string "Darn!$"

gText_082C85B4:: @ 82C85B4
	.string "Oh, come on!\n"
	.string "You have to try harder than that!$"

gText_082C85E3:: @ 82C85E3
	.string "No way!\n"
	.string "Good job!$"

gText_082C85F5:: @ 82C85F5
	.string "Heheh!\n"
	.string "What did you expect?$"

gText_082C8611:: @ 82C8611
	.string "Huh?\n"
	.string "Are you serious?!$"

gText_082C8628:: @ 82C8628
	.string "Your POKéMON are wimpy because\n"
	.string "you're wimpy as a TRAINER!$"

gText_082C8662:: @ 82C8662
	.string "Ah…\n"
	.string "Now this is something else…$"

gText_082C8682:: @ 82C8682
	.string "Gwahahaha!\n"
	.string "My brethren, we have nothing to fear!$"

gText_082C86B3:: @ 82C86B3
	.string "Gwah!\n"
	.string "Hahahaha!$"

gText_082C86C3:: @ 82C86C3
	.string "Hey! What's wrong with you!\n"
	.string "Let's see some effort! Get up!$"

gText_082C86FE:: @ 82C86FE
	.string "That's it! You've done great!\n"
	.string "You've worked hard for this!$"

gText_082C8739:: @ 82C8739
	.string "Hey! Don't you give up now!\n"
	.string "Get up! Don't lose faith in yourself!$"

gText_082C877B:: @ 82C877B
	.string "That's it! You've done it!\n"
	.string "You kept working for this!$"

	.align 2
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"
