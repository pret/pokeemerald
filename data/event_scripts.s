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

	.include "data/scripts/new_game.inc"

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

	.include "data/scripts/pc.inc"

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

	.include "data/scripts/prof_birch.inc"

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

	.include "data/scripts/cave_of_origin.inc"
	.include "data/scripts/kecleon.inc"

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

	.include "data/scripts/elite_four.inc"
	.include "data/scripts/movement.inc"
	.include "data/scripts/check_furniture.inc"

Text_WouldYouLikeToMixRecords: @ 827260D
	.string "Would you like to mix records with\n"
	.string "other TRAINERS?$"

Text_WouldNotLikeToMixRecords: @ 8272640
	.string "We hope to see you again!$"

	.include "data/text/pc.inc"
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

	.include "data/text/mevent.inc"
	.include "data/text/unusual_weather.inc"

EventScript_SelectWithoutRegisteredItem:: @ 82736B3
	msgbox gText_SelectWithoutRegisteredItem, MSGBOX_SIGN
	end

	.include "data/scripts/field_poison.inc"

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

	.include "data/scripts/mevent.inc"
	.include "data/scripts/unusual_weather.inc"

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
	.include "data/text/contest_link.inc"
	.include "data/text/contest_painting.inc"
	.include "data/text/trick_house_mechadolls.inc"
	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"
	.include "data/scripts/interview.inc"
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
	.include "data/scripts/pokeblocks.inc"
	.include "data/text/mauville_man.inc"
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
	.include "data/text/check_furniture.inc"
	.include "data/scripts/cave_hole.inc"
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

	.include "data/text/frontier_brain.inc"

	.align 2
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"
