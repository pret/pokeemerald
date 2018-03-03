#include "constants/flags.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/vars.h"
#include "constants/trainers.h"
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
	.4byte gSpecialVar_0x8014
	.4byte gTrainerBattleOpponent_A

	.include "data/specials.inc"

gStdScripts:: @ 81DC2A0
	.4byte Std_ObtainItem
	.4byte Std_FindItem
	.4byte Std_2
	.4byte Std_3
	.4byte Std_4
	.4byte Std_5
	.4byte Std_6
	.4byte Std_ObtainDecoration
	.4byte Std_RegisteredInMatchCall
	.4byte Std_9
	.4byte Std_10

gStdScripts_End:: @ 81DC2CC
	map_script 3, PetalburgCity_MapScript1_1DC2D7
	map_script 2, PetalburgCity_MapScript2_1DC31C
	.byte 0

	.include "data/scripts/maps/PetalburgCity.inc"
	.include "data/scripts/maps/SlateportCity.inc"
	.include "data/scripts/maps/MauvilleCity.inc"
	.include "data/scripts/maps/RustboroCity.inc"
	.include "data/scripts/maps/FortreeCity.inc"
	.include "data/scripts/maps/LilycoveCity.inc"
	.include "data/scripts/maps/MossdeepCity.inc"
	.include "data/scripts/maps/SootopolisCity.inc"
	.include "data/scripts/maps/EverGrandeCity.inc"
	.include "data/scripts/maps/LittlerootTown.inc"
	.include "data/scripts/maps/OldaleTown.inc"
	.include "data/scripts/maps/DewfordTown.inc"
	.include "data/scripts/maps/LavaridgeTown.inc"
	.include "data/scripts/maps/FallarborTown.inc"
	.include "data/scripts/maps/VerdanturfTown.inc"
	.include "data/scripts/maps/PacifidlogTown.inc"
	.include "data/scripts/maps/Route101.inc"
	.include "data/scripts/maps/Route102.inc"
	.include "data/scripts/maps/Route103.inc"
	.include "data/scripts/maps/Route104.inc"
	.include "data/scripts/maps/Route105.inc"
	.include "data/scripts/maps/Route106.inc"
	.include "data/scripts/maps/Route107.inc"
	.include "data/scripts/maps/Route108.inc"
	.include "data/scripts/maps/Route109.inc"
	.include "data/scripts/maps/Route110.inc"
	.include "data/scripts/maps/Route111.inc"
	.include "data/scripts/maps/Route112.inc"
	.include "data/scripts/maps/Route113.inc"
	.include "data/scripts/maps/Route114.inc"
	.include "data/scripts/maps/Route115.inc"
	.include "data/scripts/maps/Route116.inc"
	.include "data/scripts/maps/Route117.inc"
	.include "data/scripts/maps/Route118.inc"
	.include "data/scripts/maps/Route119.inc"
	.include "data/scripts/maps/Route120.inc"
	.include "data/scripts/maps/Route121.inc"
	.include "data/scripts/maps/Route122.inc"
	.include "data/scripts/maps/Route123.inc"
	.include "data/scripts/maps/Route124.inc"
	.include "data/scripts/maps/Route125.inc"
	.include "data/scripts/maps/Route126.inc"
	.include "data/scripts/maps/Route127.inc"
	.include "data/scripts/maps/Route128.inc"
	.include "data/scripts/maps/Route129.inc"
	.include "data/scripts/maps/Route130.inc"
	.include "data/scripts/maps/Route131.inc"
	.include "data/scripts/maps/Route132.inc"
	.include "data/scripts/maps/Route133.inc"
	.include "data/scripts/maps/Route134.inc"
	.include "data/scripts/maps/Underwater1.inc"
	.include "data/scripts/maps/Underwater2.inc"
	.include "data/scripts/maps/Underwater3.inc"
	.include "data/scripts/maps/Underwater4.inc"
	.include "data/scripts/maps/Underwater5.inc"
	.include "data/scripts/maps/Underwater6.inc"
	.include "data/scripts/maps/Underwater7.inc"
	.include "data/scripts/maps/LittlerootTown_BrendansHouse_1F.inc"
	.include "data/scripts/maps/LittlerootTown_BrendansHouse_2F.inc"
	.include "data/scripts/maps/LittlerootTown_MaysHouse_1F.inc"
	.include "data/scripts/maps/LittlerootTown_MaysHouse_2F.inc"
	.include "data/scripts/maps/LittlerootTown_ProfessorBirchsLab.inc"
	.include "data/scripts/maps/OldaleTown_House1.inc"
	.include "data/scripts/maps/OldaleTown_House2.inc"
	.include "data/scripts/maps/OldaleTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/OldaleTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/OldaleTown_Mart.inc"
	.include "data/scripts/maps/DewfordTown_House1.inc"
	.include "data/scripts/maps/DewfordTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/DewfordTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/DewfordTown_Gym.inc"
	.include "data/scripts/maps/DewfordTown_Hall.inc"
	.include "data/scripts/maps/DewfordTown_House2.inc"
	.include "data/scripts/maps/LavaridgeTown_HerbShop.inc"
	.include "data/scripts/maps/LavaridgeTown_Gym_1F.inc"
	.include "data/scripts/maps/LavaridgeTown_Gym_B1F.inc"
	.include "data/scripts/maps/LavaridgeTown_House.inc"
	.include "data/scripts/maps/LavaridgeTown_Mart.inc"
	.include "data/scripts/maps/LavaridgeTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/LavaridgeTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/FallarborTown_Mart.inc"
	.include "data/scripts/maps/FallarborTown_BattleTentLobby.inc"
	.include "data/scripts/maps/FallarborTown_BattleTentCorridor.inc"
	.include "data/scripts/maps/FallarborTown_BattleTentBattleRoom.inc"
	.include "data/scripts/maps/FallarborTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/FallarborTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/FallarborTown_House1.inc"
	.include "data/scripts/maps/FallarborTown_House2.inc"
	.include "data/scripts/maps/VerdanturfTown_BattleTentLobby.inc"
	.include "data/scripts/maps/VerdanturfTown_BattleTentCorridor.inc"
	.include "data/scripts/maps/VerdanturfTown_BattleTentBattleRoom.inc"
	.include "data/scripts/maps/VerdanturfTown_Mart.inc"
	.include "data/scripts/maps/VerdanturfTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/VerdanturfTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/VerdanturfTown_WandasHouse.inc"
	.include "data/scripts/maps/VerdanturfTown_FriendshipRatersHouse.inc"
	.include "data/scripts/maps/VerdanturfTown_House.inc"
	.include "data/scripts/maps/PacifidlogTown_PokemonCenter_1F.inc"
	.include "data/scripts/maps/PacifidlogTown_PokemonCenter_2F.inc"
	.include "data/scripts/maps/PacifidlogTown_House1.inc"
	.include "data/scripts/maps/PacifidlogTown_House2.inc"
	.include "data/scripts/maps/PacifidlogTown_House3.inc"
	.include "data/scripts/maps/PacifidlogTown_House4.inc"
	.include "data/scripts/maps/PacifidlogTown_House5.inc"
	.include "data/scripts/maps/PetalburgCity_WallysHouse.inc"
	.include "data/scripts/maps/PetalburgCity_Gym.inc"
	.include "data/scripts/maps/PetalburgCity_House1.inc"
	.include "data/scripts/maps/PetalburgCity_House2.inc"
	.include "data/scripts/maps/PetalburgCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/PetalburgCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/PetalburgCity_Mart.inc"
	.include "data/scripts/maps/SlateportCity_SternsShipyard_1F.inc"
	.include "data/scripts/maps/SlateportCity_SternsShipyard_2F.inc"
	.include "data/scripts/maps/SlateportCity_BattleTentLobby.inc"
	.include "data/scripts/maps/SlateportCity_BattleTentCorridor.inc"
	.include "data/scripts/maps/SlateportCity_BattleTentBattleRoom.inc"
	.include "data/scripts/maps/SlateportCity_House1.inc"
	.include "data/scripts/maps/SlateportCity_PokemonFanClub.inc"
	.include "data/scripts/maps/SlateportCity_OceanicMuseum_1F.inc"
	.include "data/scripts/maps/SlateportCity_OceanicMuseum_2F.inc"
	.include "data/scripts/maps/SlateportCity_Harbor.inc"
	.include "data/scripts/maps/SlateportCity_House2.inc"
	.include "data/scripts/maps/SlateportCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/SlateportCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/SlateportCity_Mart.inc"
	.include "data/scripts/maps/MauvilleCity_Gym.inc"
	.include "data/scripts/maps/MauvilleCity_BikeShop.inc"
	.include "data/scripts/maps/MauvilleCity_House1.inc"
	.include "data/scripts/maps/MauvilleCity_GameCorner.inc"
	.include "data/scripts/maps/MauvilleCity_House2.inc"
	.include "data/scripts/maps/MauvilleCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/MauvilleCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/MauvilleCity_Mart.inc"
	.include "data/scripts/maps/RustboroCity_DevonCorp_1F.inc"
	.include "data/scripts/maps/RustboroCity_DevonCorp_2F.inc"
	.include "data/scripts/maps/RustboroCity_DevonCorp_3F.inc"
	.include "data/scripts/maps/RustboroCity_Gym.inc"
	.include "data/scripts/maps/RustboroCity_PokemonSchool.inc"
	.include "data/scripts/maps/RustboroCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/RustboroCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/RustboroCity_Mart.inc"
	.include "data/scripts/maps/RustboroCity_Flat1_1F.inc"
	.include "data/scripts/maps/RustboroCity_Flat1_2F.inc"
	.include "data/scripts/maps/RustboroCity_House1.inc"
	.include "data/scripts/maps/RustboroCity_CuttersHouse.inc"
	.include "data/scripts/maps/RustboroCity_House2.inc"
	.include "data/scripts/maps/RustboroCity_Flat2_1F.inc"
	.include "data/scripts/maps/RustboroCity_Flat2_2F.inc"
	.include "data/scripts/maps/RustboroCity_Flat2_3F.inc"
	.include "data/scripts/maps/RustboroCity_House3.inc"
	.include "data/scripts/maps/FortreeCity_House1.inc"
	.include "data/scripts/maps/FortreeCity_Gym.inc"
	.include "data/scripts/maps/FortreeCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/FortreeCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/FortreeCity_Mart.inc"
	.include "data/scripts/maps/FortreeCity_House2.inc"
	.include "data/scripts/maps/FortreeCity_House3.inc"
	.include "data/scripts/maps/FortreeCity_House4.inc"
	.include "data/scripts/maps/FortreeCity_House5.inc"
	.include "data/scripts/maps/FortreeCity_DecorationShop.inc"
	.include "data/scripts/maps/LilycoveCity_CoveLilyMotel_1F.inc"
	.include "data/scripts/maps/LilycoveCity_CoveLilyMotel_2F.inc"
	.include "data/scripts/maps/LilycoveCity_LilycoveMuseum_1F.inc"
	.include "data/scripts/maps/LilycoveCity_LilycoveMuseum_2F.inc"
	.include "data/scripts/maps/LilycoveCity_ContestLobby.inc"
	.include "data/scripts/maps/LilycoveCity_ContestHall.inc"
	.include "data/scripts/maps/LilycoveCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/LilycoveCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/LilycoveCity_UnusedMart.inc"
	.include "data/scripts/maps/LilycoveCity_PokemonTrainerFanClub.inc"
	.include "data/scripts/maps/LilycoveCity_Harbor.inc"
	.include "data/scripts/maps/LilycoveCity_MoveDeletersHouse.inc"
	.include "data/scripts/maps/LilycoveCity_House1.inc"
	.include "data/scripts/maps/LilycoveCity_House2.inc"
	.include "data/scripts/maps/LilycoveCity_House3.inc"
	.include "data/scripts/maps/LilycoveCity_House4.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStore_1F.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStore_2F.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStore_3F.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStore_4F.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStore_5F.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStoreRooftop.inc"
	.include "data/scripts/maps/LilycoveCity_DepartmentStoreElevator.inc"
	.include "data/scripts/maps/MossdeepCity_Gym.inc"
	.include "data/scripts/maps/MossdeepCity_House1.inc"
	.include "data/scripts/maps/MossdeepCity_House2.inc"
	.include "data/scripts/maps/MossdeepCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/MossdeepCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/MossdeepCity_Mart.inc"
	.include "data/scripts/maps/MossdeepCity_House3.inc"
	.include "data/scripts/maps/MossdeepCity_StevensHouse.inc"
	.include "data/scripts/maps/MossdeepCity_House4.inc"
	.include "data/scripts/maps/MossdeepCity_SpaceCenter_1F.inc"
	.include "data/scripts/maps/MossdeepCity_SpaceCenter_2F.inc"
	.include "data/scripts/maps/MossdeepCity_GameCorner_1F.inc"
	.include "data/scripts/maps/MossdeepCity_GameCorner_B1F.inc"
	.include "data/scripts/maps/SootopolisCity_Gym_1F.inc"
	.include "data/scripts/maps/SootopolisCity_Gym_B1F.inc"
	.include "data/scripts/maps/SootopolisCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/SootopolisCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/SootopolisCity_Mart.inc"
	.include "data/scripts/maps/SootopolisCity_House1.inc"
	.include "data/scripts/maps/SootopolisCity_House2.inc"
	.include "data/scripts/maps/SootopolisCity_House3.inc"
	.include "data/scripts/maps/SootopolisCity_House4.inc"
	.include "data/scripts/maps/SootopolisCity_House5.inc"
	.include "data/scripts/maps/SootopolisCity_House6.inc"
	.include "data/scripts/maps/SootopolisCity_House7.inc"
	.include "data/scripts/maps/SootopolisCity_LotadAndSeedotHouse.inc"
	.include "data/scripts/maps/SootopolisCity_MysteryEventsHouse_1F.inc"
	.include "data/scripts/maps/SootopolisCity_MysteryEventsHouse_B1F.inc"
	.include "data/scripts/maps/EverGrandeCity_SidneysRoom.inc"
	.include "data/scripts/maps/EverGrandeCity_PhoebesRoom.inc"
	.include "data/scripts/maps/EverGrandeCity_GlaciasRoom.inc"
	.include "data/scripts/maps/EverGrandeCity_DrakesRoom.inc"
	.include "data/scripts/maps/EverGrandeCity_ChampionsRoom.inc"
	.include "data/scripts/maps/EverGrandeCity_Hall1.inc"
	.include "data/scripts/maps/EverGrandeCity_Hall2.inc"
	.include "data/scripts/maps/EverGrandeCity_Hall3.inc"
	.include "data/scripts/maps/EverGrandeCity_Hall4.inc"
	.include "data/scripts/maps/EverGrandeCity_Hall5.inc"
	.include "data/scripts/maps/EverGrandeCity_PokemonLeague_1F.inc"
	.include "data/scripts/maps/EverGrandeCity_HallOfFame.inc"
	.include "data/scripts/maps/EverGrandeCity_PokemonCenter_1F.inc"
	.include "data/scripts/maps/EverGrandeCity_PokemonCenter_2F.inc"
	.include "data/scripts/maps/EverGrandeCity_PokemonLeague_2F.inc"
	.include "data/scripts/maps/Route104_MrBrineysHouse.inc"
	.include "data/scripts/maps/Route104_PrettyPetalFlowerShop.inc"
	.include "data/scripts/maps/Route111_WinstrateFamilysHouse.inc"
	.include "data/scripts/maps/Route111_OldLadysRestStop.inc"
	.include "data/scripts/maps/Route112_CableCarStation.inc"
	.include "data/scripts/maps/MtChimney_CableCarStation.inc"
	.include "data/scripts/maps/Route114_FossilManiacsHouse.inc"
	.include "data/scripts/maps/Route114_FossilManiacsTunnel.inc"
	.include "data/scripts/maps/Route114_LanettesHouse.inc"
	.include "data/scripts/maps/Route116_TunnelersRestHouse.inc"
	.include "data/scripts/maps/Route117_PokemonDayCare.inc"
	.include "data/scripts/maps/Route121_SafariZoneEntrance.inc"
	.include "data/scripts/maps/MeteorFalls_1F_1R.inc"
	.include "data/scripts/maps/MeteorFalls_1F_2R.inc"
	.include "data/scripts/maps/MeteorFalls_B1F_1R.inc"
	.include "data/scripts/maps/MeteorFalls_B1F_2R.inc"
	.include "data/scripts/maps/RusturfTunnel.inc"
	.include "data/scripts/maps/Underwater_SootopolisCity.inc"
	.include "data/scripts/maps/DesertRuins.inc"
	.include "data/scripts/maps/GraniteCave_1F.inc"
	.include "data/scripts/maps/GraniteCave_B1F.inc"
	.include "data/scripts/maps/GraniteCave_B2F.inc"
	.include "data/scripts/maps/GraniteCave_StevensRoom.inc"
	.include "data/scripts/maps/PetalburgWoods.inc"
	.include "data/scripts/maps/MtChimney.inc"
	.include "data/scripts/maps/JaggedPass.inc"
	.include "data/scripts/maps/FieryPath.inc"
	.include "data/scripts/maps/MtPyre_1F.inc"
	.include "data/scripts/maps/MtPyre_2F.inc"
	.include "data/scripts/maps/MtPyre_3F.inc"
	.include "data/scripts/maps/MtPyre_4F.inc"
	.include "data/scripts/maps/MtPyre_5F.inc"
	.include "data/scripts/maps/MtPyre_6F.inc"
	.include "data/scripts/maps/MtPyre_Exterior.inc"
	.include "data/scripts/maps/MtPyre_Summit.inc"
	.include "data/scripts/maps/AquaHideout_1F.inc"
	.include "data/scripts/maps/AquaHideout_B1F.inc"
	.include "data/scripts/maps/AquaHideout_B2F.inc"
	.include "data/scripts/maps/Underwater_SeafloorCavern.inc"
	.include "data/scripts/maps/SeafloorCavern_Entrance.inc"
	.include "data/scripts/maps/SeafloorCavern_Room1.inc"
	.include "data/scripts/maps/SeafloorCavern_Room2.inc"
	.include "data/scripts/maps/SeafloorCavern_Room3.inc"
	.include "data/scripts/maps/SeafloorCavern_Room4.inc"
	.include "data/scripts/maps/SeafloorCavern_Room5.inc"
	.include "data/scripts/maps/SeafloorCavern_Room6.inc"
	.include "data/scripts/maps/SeafloorCavern_Room7.inc"
	.include "data/scripts/maps/SeafloorCavern_Room8.inc"
	.include "data/scripts/maps/SeafloorCavern_Room9.inc"
	.include "data/scripts/maps/CaveOfOrigin_Entrance.inc"
	.include "data/scripts/maps/CaveOfOrigin_1F.inc"
	.include "data/scripts/maps/CaveOfOrigin_UnusedRubySapphireMap1.inc"
	.include "data/scripts/maps/CaveOfOrigin_UnusedRubySapphireMap2.inc"
	.include "data/scripts/maps/CaveOfOrigin_UnusedRubySapphireMap3.inc"
	.include "data/scripts/maps/CaveOfOrigin_B1F.inc"
	.include "data/scripts/maps/VictoryRoad_1F.inc"
	.include "data/scripts/maps/VictoryRoad_B1F.inc"
	.include "data/scripts/maps/VictoryRoad_B2F.inc"
	.include "data/scripts/maps/ShoalCave_LowTideEntranceRoom.inc"
	.include "data/scripts/maps/ShoalCave_LowTideInnerRoom.inc"
	.include "data/scripts/maps/ShoalCave_LowTideStairsRoom.inc"
	.include "data/scripts/maps/ShoalCave_LowTideLowerRoom.inc"
	.include "data/scripts/maps/ShoalCave_HighTideEntranceRoom.inc"
	.include "data/scripts/maps/ShoalCave_HighTideInnerRoom.inc"
	.include "data/scripts/maps/NewMauville_Entrance.inc"
	.include "data/scripts/maps/NewMauville_Inside.inc"
	.include "data/scripts/maps/AbandonedShip_Deck.inc"
	.include "data/scripts/maps/AbandonedShip_Corridors_1F.inc"
	.include "data/scripts/maps/AbandonedShip_Rooms_1F.inc"
	.include "data/scripts/maps/AbandonedShip_Corridors_B1F.inc"
	.include "data/scripts/maps/AbandonedShip_Rooms_B1F.inc"
	.include "data/scripts/maps/AbandonedShip_Rooms2_B1F.inc"
	.include "data/scripts/maps/AbandonedShip_Underwater1.inc"
	.include "data/scripts/maps/AbandonedShip_Room_B1F.inc"
	.include "data/scripts/maps/AbandonedShip_Rooms2_1F.inc"
	.include "data/scripts/maps/AbandonedShip_CaptainsOffice.inc"
	.include "data/scripts/maps/AbandonedShip_Underwater2.inc"
	.include "data/scripts/maps/AbandonedShip_HiddenFloorCorridors.inc"
	.include "data/scripts/maps/AbandonedShip_HiddenFloorRooms.inc"
	.include "data/scripts/maps/IslandCave.inc"
	.include "data/scripts/maps/AncientTomb.inc"
	.include "data/scripts/maps/Underwater_Route134.inc"
	.include "data/scripts/maps/Underwater_SealedChamber.inc"
	.include "data/scripts/maps/SealedChamber_OuterRoom.inc"
	.include "data/scripts/maps/SealedChamber_InnerRoom.inc"
	.include "data/scripts/maps/ScorchedSlab.inc"
	.include "data/scripts/maps/AquaHideout_UnusedRubyMap1.inc"
	.include "data/scripts/maps/AquaHideout_UnusedRubyMap2.inc"
	.include "data/scripts/maps/AquaHideout_UnusedRubyMap3.inc"
	.include "data/scripts/maps/SkyPillar_Entrance.inc"
	.include "data/scripts/maps/SkyPillar_Outside.inc"
	.include "data/scripts/maps/SkyPillar_1F.inc"
	.include "data/scripts/maps/SkyPillar_2F.inc"
	.include "data/scripts/maps/SkyPillar_3F.inc"
	.include "data/scripts/maps/SkyPillar_4F.inc"
	.include "data/scripts/maps/ShoalCave_LowTideIceRoom.inc"
	.include "data/scripts/maps/SkyPillar_5F.inc"
	.include "data/scripts/maps/SkyPillar_Top.inc"
	.include "data/scripts/maps/MagmaHideout_1F.inc"
	.include "data/scripts/maps/MagmaHideout_2F_1R.inc"
	.include "data/scripts/maps/MagmaHideout_2F_2R.inc"
	.include "data/scripts/maps/MagmaHideout_3F_1R.inc"
	.include "data/scripts/maps/MagmaHideout_3F_2R.inc"
	.include "data/scripts/maps/MagmaHideout_4F.inc"
	.include "data/scripts/maps/MagmaHideout_3F_3R.inc"
	.include "data/scripts/maps/MagmaHideout_2F_3R.inc"
	.include "data/scripts/maps/MirageTower_1F.inc"
	.include "data/scripts/maps/MirageTower_2F.inc"
	.include "data/scripts/maps/MirageTower_3F.inc"
	.include "data/scripts/maps/MirageTower_4F.inc"
	.include "data/scripts/maps/DesertUnderpass.inc"
	.include "data/scripts/maps/ArtisanCave_B1F.inc"
	.include "data/scripts/maps/ArtisanCave_1F.inc"
	.include "data/scripts/maps/Underwater_MarineCave.inc"
	.include "data/scripts/maps/MarineCave_Entrance.inc"
	.include "data/scripts/maps/MarineCave_End.inc"
	.include "data/scripts/maps/TerraCave_Entrance.inc"
	.include "data/scripts/maps/TerraCave_End.inc"
	.include "data/scripts/maps/AlteringCave.inc"
	.include "data/scripts/maps/MeteorFalls_StevensCave.inc"
	.include "data/scripts/maps/SecretBase_BlueCave1.inc"
	.include "data/scripts/maps/SecretBase_BlueCave2.inc"
	.include "data/scripts/maps/SecretBase_BlueCave3.inc"
	.include "data/scripts/maps/SecretBase_BlueCave4.inc"
	.include "data/scripts/maps/SecretBase_BrownCave1.inc"
	.include "data/scripts/maps/SecretBase_BrownCave2.inc"
	.include "data/scripts/maps/SecretBase_BrownCave3.inc"
	.include "data/scripts/maps/SecretBase_BrownCave4.inc"
	.include "data/scripts/maps/SecretBase_RedCave1.inc"
	.include "data/scripts/maps/SecretBase_RedCave2.inc"
	.include "data/scripts/maps/SecretBase_RedCave3.inc"
	.include "data/scripts/maps/SecretBase_RedCave4.inc"
	.include "data/scripts/maps/SecretBase_Shrub1.inc"
	.include "data/scripts/maps/SecretBase_Shrub2.inc"
	.include "data/scripts/maps/SecretBase_Shrub3.inc"
	.include "data/scripts/maps/SecretBase_Shrub4.inc"
	.include "data/scripts/maps/SecretBase_Tree1.inc"
	.include "data/scripts/maps/SecretBase_Tree2.inc"
	.include "data/scripts/maps/SecretBase_Tree3.inc"
	.include "data/scripts/maps/SecretBase_Tree4.inc"
	.include "data/scripts/maps/SecretBase_YellowCave1.inc"
	.include "data/scripts/maps/SecretBase_YellowCave2.inc"
	.include "data/scripts/maps/SecretBase_YellowCave3.inc"
	.include "data/scripts/maps/SecretBase_YellowCave4.inc"

gUnknown_0823B4BB:: @ 823B4BB
	lockall
	playse 2
	message Text_276805
	dofieldeffect 61
	waitstate
	waitmessage
	waitbuttonpress
	playse 5
	goto EventScript_23B4D3
	end

EventScript_23B4D3:: @ 823B4D3
	message Text_27681A
	waitmessage
	checkflag FLAG_0x10C
	goto_eq EventScript_23B4EF
	goto EventScript_23B531
	end

gUnknown_0823B4E8:: @ 823B4E8
	lockall
	goto EventScript_23B4D3
	end

EventScript_23B4EF:: @ 823B4EF
	multichoice 0, 0, 6, 0
	switch VAR_RESULT
	case 0, EventScript_23B581
	case 1, EventScript_23B568
	case 2, EventScript_23B585
	case 3, EventScript_23B66E
	case 127, EventScript_23B66E
	end

EventScript_23B531:: @ 823B531
	multichoice 0, 0, 5, 0
	switch VAR_RESULT
	case 0, EventScript_23B581
	case 1, EventScript_23B568
	case 2, EventScript_23B66E
	case 127, EventScript_23B66E
	end

EventScript_23B568:: @ 823B568
	msgbox Text_2766AA, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_23B4D3
	closemessage
	special sub_80E9AC0
	releaseall
	end

EventScript_23B581:: @ 823B581
	special sub_80E9C74
	end

EventScript_23B585:: @ 823B585
	special sub_80E9C88
	end

gUnknown_0823B589:: @ 823B589
	lockall
	message Text_276805
	playse 2
	dofieldeffect 61
	waitstate
	waitmessage
	waitbuttonpress
	playse 5
	goto EventScript_23B5A1
	end

EventScript_23B5A1:: @ 823B5A1
	message Text_27681A
	waitmessage
	multichoice 0, 0, 7, 0
	switch VAR_RESULT
	case 0, EventScript_23B5F0
	case 1, EventScript_23B585
	case 2, EventScript_23B660
	case 3, EventScript_23B66E
	case 127, EventScript_23B66E
	end

gUnknown_0823B5E9:: @ 823B5E9
	lockall
	goto EventScript_23B5A1
	end

EventScript_23B5F0:: @ 823B5F0
	special sub_80E9BDC
	compare VAR_RESULT, 1
	goto_eq EventScript_23B62F
	compare VAR_RESULT, 2
	goto_eq EventScript_23B652
	special sub_80E980C
	msgbox Text_276707, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_23B5A1
	msgbox Text_2767D1, 3
	special sub_80E9C2C
	special sub_80FA57C
	releaseall
	end

EventScript_23B62F:: @ 823B62F
	msgbox Text_276731, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_23B5A1
	msgbox Text_2767E9, 3
	special sub_80E9C2C
	special sub_80FA57C
	releaseall
	end

EventScript_23B652:: @ 823B652
	msgbox Text_27676F, 3
	special sub_80FA57C
	closemessage
	releaseall
	end

EventScript_23B660:: @ 823B660
	msgbox Text_276835, 4
	goto EventScript_23B5A1
	end

EventScript_23B66E:: @ 823B66E
	special sub_80FA57C
	closemessage
	releaseall
	end

EventScript_23B674:: @ 823B674
	special sub_80EB498
	end

EventScript_23B678:: @ 823B678
	special sub_80EB56C
	end

EventScript_23B67C:: @ 823B67C
	special sub_80EB9E0
	end

EventScript_23B680:: @ 823B680
	special sub_80EBB28
	end

gUnknown_0823B684:: @ 823B684
	special sub_80EBE7C
	dofieldeffect 52
	waitstate
	end

gUnknown_0823B68C:: @ 823B68C
	special sub_80FAC78
	compare VAR_RESULT, 0
	goto_eq EventScript_23B6BC
	compare VAR_RESULT, 1
	goto_eq EventScript_23B6C5
	compare VAR_RESULT, 2
	goto_eq EventScript_23B6CE
	compare VAR_RESULT, 3
	goto_eq EventScript_23B6D7
	end

EventScript_23B6BC:: @ 823B6BC
	msgbox Text_27692B, 3
	end

EventScript_23B6C5:: @ 823B6C5
	msgbox Text_276974, 3
	end

EventScript_23B6CE:: @ 823B6CE
	msgbox Text_2769B8, 3
	end

EventScript_23B6D7:: @ 823B6D7
	msgbox Text_2769FF, 3
	end

gText_23B6E0:: @ 823B6E0
	.string "There’s a small indent in the wall.$"

gText_23B704:: @ 823B704
	.string "There’s a small indent in the wall.\p"
	.string "Use the SECRET POWER?$"

gText_23B73E:: @ 823B73E
	.string "Discovered a small cavern!$"

SecretBase_RedCave1_Text_23B759: @ 823B759
	.string "Want to make your SECRET BASE here?$"

	.include "data/scripts/maps/SingleBattleColosseum.inc"
	.include "data/scripts/maps/TradeCenter.inc"
	.include "data/scripts/maps/RecordCorner.inc"
	.include "data/scripts/maps/DoubleBattleColosseum.inc"
	.include "data/scripts/maps/LinkContestRoom1.inc"
	.include "data/scripts/maps/LinkContestRoom2.inc"
	.include "data/scripts/maps/LinkContestRoom3.inc"
	.include "data/scripts/maps/LinkContestRoom4.inc"
	.include "data/scripts/maps/LinkContestRoom5.inc"
	.include "data/scripts/maps/LinkContestRoom6.inc"
	.include "data/scripts/maps/UnknownMap_25_29.inc"
	.include "data/scripts/maps/UnknownMap_25_30.inc"
	.include "data/scripts/maps/UnknownMap_25_31.inc"
	.include "data/scripts/maps/UnknownMap_25_32.inc"
	.include "data/scripts/maps/UnknownMap_25_33.inc"
	.include "data/scripts/maps/UnknownMap_25_34.inc"
	.include "data/scripts/maps/InsideOfTruck.inc"
	.include "data/scripts/maps/SSTidalCorridor.inc"
	.include "data/scripts/maps/SSTidalLowerDeck.inc"
	.include "data/scripts/maps/SSTidalRooms.inc"
	.include "data/scripts/maps/BattlePyramidSquare01.inc"
	.include "data/scripts/maps/BattlePyramidSquare02.inc"
	.include "data/scripts/maps/BattlePyramidSquare03.inc"
	.include "data/scripts/maps/BattlePyramidSquare04.inc"
	.include "data/scripts/maps/BattlePyramidSquare05.inc"
	.include "data/scripts/maps/BattlePyramidSquare06.inc"
	.include "data/scripts/maps/BattlePyramidSquare07.inc"
	.include "data/scripts/maps/BattlePyramidSquare08.inc"
	.include "data/scripts/maps/BattlePyramidSquare09.inc"
	.include "data/scripts/maps/BattlePyramidSquare10.inc"
	.include "data/scripts/maps/BattlePyramidSquare11.inc"
	.include "data/scripts/maps/BattlePyramidSquare12.inc"
	.include "data/scripts/maps/BattlePyramidSquare13.inc"
	.include "data/scripts/maps/BattlePyramidSquare14.inc"
	.include "data/scripts/maps/BattlePyramidSquare15.inc"
	.include "data/scripts/maps/BattlePyramidSquare16.inc"
	.include "data/scripts/maps/UnionRoom.inc"
	.include "data/scripts/maps/SafariZone_Northwest.inc"
	.include "data/scripts/maps/SafariZone_North.inc"
	.include "data/scripts/maps/SafariZone_Southwest.inc"
	.include "data/scripts/maps/SafariZone_South.inc"
	.include "data/scripts/maps/BattleFrontier_OutsideWest.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerElevator.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerCorridor.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerBattleRoom.inc"
	.include "data/scripts/maps/SouthernIsland_Exterior.inc"
	.include "data/scripts/maps/SouthernIsland_Interior.inc"
	.include "data/scripts/maps/SafariZone_RestHouse.inc"
	.include "data/scripts/maps/SafariZone_Northeast.inc"
	.include "data/scripts/maps/SafariZone_Southeast.inc"
	.include "data/scripts/maps/BattleFrontier_OutsideEast.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerMultiBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerCorridor2.inc"
	.include "data/scripts/maps/BattleFrontier_BattleTowerBattleRoom2.inc"
	.include "data/scripts/maps/BattleFrontier_BattleDomeLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattleDomeCorridor.inc"
	.include "data/scripts/maps/BattleFrontier_BattleDomePreBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattleDomeBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePalaceLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePalaceCorridor.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePalaceBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePyramidLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePyramidEmptySquare.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePyramidTop.inc"
	.include "data/scripts/maps/BattleFrontier_BattleArenaLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattleArenaCorridor.inc"
	.include "data/scripts/maps/BattleFrontier_BattleArenaBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattleFactoryLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattleFactoryPreBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattleFactoryBattleRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeLobby.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeCorridor.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeThreePathRoom.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeRandomRoom1.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeRandomRoom2.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePikeRandomRoom3.inc"
	.include "data/scripts/maps/BattleFrontier_RankingHall.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge1.inc"
	.include "data/scripts/maps/BattleFrontier_BattlePointExchangeServiceCorner.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge2.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge3.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge4.inc"
	.include "data/scripts/maps/BattleFrontier_ScottsHouse.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge5.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge6.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge7.inc"
	.include "data/scripts/maps/BattleFrontier_ReceptionGate.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge8.inc"
	.include "data/scripts/maps/BattleFrontier_Lounge9.inc"
	.include "data/scripts/maps/BattleFrontier_PokemonCenter_1F.inc"
	.include "data/scripts/maps/BattleFrontier_PokemonCenter_2F.inc"
	.include "data/scripts/maps/BattleFrontier_Mart.inc"
	.include "data/scripts/maps/FarawayIsland_Entrance.inc"
	.include "data/scripts/maps/FarawayIsland_Interior.inc"
	.include "data/scripts/maps/BirthIsland_Exterior.inc"
	.include "data/scripts/maps/BirthIsland_Harbor.inc"
	.include "data/scripts/maps/TrainerHill_Entrance.inc"
	.include "data/scripts/maps/TrainerHill_1F.inc"
	.include "data/scripts/maps/TrainerHill_2F.inc"
	.include "data/scripts/maps/TrainerHill_3F.inc"
	.include "data/scripts/maps/TrainerHill_4F.inc"
	.include "data/scripts/maps/TrainerHill_Roof.inc"
	.include "data/scripts/maps/NavelRock_Exterior.inc"
	.include "data/scripts/maps/NavelRock_Harbor.inc"
	.include "data/scripts/maps/NavelRock_Entrance.inc"
	.include "data/scripts/maps/NavelRock_B1F.inc"
	.include "data/scripts/maps/NavelRock_Fork.inc"
	.include "data/scripts/maps/NavelRock_Up1.inc"
	.include "data/scripts/maps/NavelRock_Up2.inc"
	.include "data/scripts/maps/NavelRock_Up3.inc"
	.include "data/scripts/maps/NavelRock_Up4.inc"
	.include "data/scripts/maps/NavelRock_Top.inc"
	.include "data/scripts/maps/NavelRock_Down01.inc"
	.include "data/scripts/maps/NavelRock_Down02.inc"
	.include "data/scripts/maps/NavelRock_Down03.inc"
	.include "data/scripts/maps/NavelRock_Down04.inc"
	.include "data/scripts/maps/NavelRock_Down05.inc"
	.include "data/scripts/maps/NavelRock_Down06.inc"
	.include "data/scripts/maps/NavelRock_Down07.inc"
	.include "data/scripts/maps/NavelRock_Down08.inc"
	.include "data/scripts/maps/NavelRock_Down09.inc"
	.include "data/scripts/maps/NavelRock_Down10.inc"
	.include "data/scripts/maps/NavelRock_Down11.inc"
	.include "data/scripts/maps/NavelRock_Bottom.inc"
	.include "data/scripts/maps/TrainerHill_Elevator.inc"
	.include "data/scripts/maps/Route104_Prototype.inc"
	.include "data/scripts/maps/Route104_PrototypePrettyPetalFlowerShop.inc"
	.include "data/scripts/maps/Route109_SeashoreHouse.inc"
	.include "data/scripts/maps/Route110_TrickHouseEntrance.inc"
	.include "data/scripts/maps/Route110_TrickHouseEnd.inc"
	.include "data/scripts/maps/Route110_TrickHouseCorridor.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle1.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle2.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle3.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle4.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle5.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle6.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle7.inc"
	.include "data/scripts/maps/Route110_TrickHousePuzzle8.inc"
	.include "data/scripts/maps/Route110_SeasideCyclingRoadEntrance1.inc"
	.include "data/scripts/maps/Route110_SeasideCyclingRoadEntrance2.inc"
	.include "data/scripts/maps/Route113_GlassWorkshop.inc"
	.include "data/scripts/maps/Route123_BerryMastersHouse.inc"
	.include "data/scripts/maps/Route119_WeatherInstitute_1F.inc"
	.include "data/scripts/maps/Route119_WeatherInstitute_2F.inc"
	.include "data/scripts/maps/Route119_House.inc"
	.include "data/scripts/maps/Route124_DivingTreasureHuntersHouse.inc"

Std_2: @ 8271315
	lock
	faceplayer
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

Std_3: @ 8271320
	lockall
	message 0x0
	waitmessage
	waitbuttonpress
	releaseall
	return

Std_4: @ 827132A
	message 0x0
	waitmessage
	waitbuttonpress
	return

Std_5: @ 8271332
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

EventScript_27134E: @ 827134E
	return

BattleFrontier_BattleArenaLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattleDomeLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattleFactoryLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattlePalaceLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattlePikeLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattlePyramidLobby_EventScript_27134F:: @ 827134F
BattleFrontier_BattleTowerLobby_EventScript_27134F:: @ 827134F
FallarborTown_BattleTentLobby_EventScript_27134F:: @ 827134F
LilycoveCity_ContestLobby_EventScript_27134F:: @ 827134F
MossdeepCity_GameCorner_1F_EventScript_27134F:: @ 827134F
OldaleTown_PokemonCenter_2F_EventScript_27134F:: @ 827134F
SecretBase_RedCave1_EventScript_27134F:: @ 827134F
SlateportCity_BattleTentLobby_EventScript_27134F:: @ 827134F
SootopolisCity_MysteryEventsHouse_1F_EventScript_27134F:: @ 827134F
TrainerHill_Entrance_EventScript_27134F:: @ 827134F
VerdanturfTown_BattleTentLobby_EventScript_27134F:: @ 827134F
	special sub_809FF80
	waitstate
	return

EventScript_271354:: @ 8271354
	cmdD8
	cmdD9

EventScript_271356:: @ 8271356
	special SetUpTrainerEncounterMusic
	special EndTrainerApproach
	waitstate
	goto EventScript_ShowTrainerIntroMsg

EventScript_271362:: @ 8271362
	lock
	faceplayer
	applymovement VAR_LAST_TALKED, Movement_27143A
	waitmovement 0
	specialvar VAR_RESULT, GetTrainerFlag
	compare VAR_RESULT, 0
	goto_if 5, EventScript_271389
	special SetUpTrainerEncounterMusic
	special sub_80B16D8
	goto EventScript_ShowTrainerIntroMsg

EventScript_271389:: @ 8271389
	gotopostbattlescript

EventScript_TryDoDoubleTrainerBattle:: @ 827138A
	lock
	faceplayer
	call EventScript_27142F
	specialvar VAR_RESULT, GetTrainerFlag
	compare VAR_RESULT, 0
	goto_if 5, EventScript_2713C1
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, 0
	goto_if 5, EventScript_NotEnoughMonsForDoubleBattle
	special SetUpTrainerEncounterMusic
	special sub_80B16D8
	goto EventScript_ShowTrainerIntroMsg

EventScript_NotEnoughMonsForDoubleBattle:: @ 82713BA
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_2713C1:: @ 82713C1
	gotopostbattlescript

EventScript_2713C2:: @ 82713C2
	applymovement VAR_LAST_TALKED, Movement_27143A
	waitmovement 0
	special SetUpTrainerEncounterMusic
	trainerbattlebegin
	gotopostbattlescript

EventScript_2713D1:: @ 82713D1
	call EventScript_27142F
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, 0
	goto_eq EventScript_2713F7
	special SetUpTrainerEncounterMusic
	special sub_80B16D8
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_2713F7:: @ 82713F7
	gotopostbattlescript

EventScript_TryDoDoubleRematchBattle:: @ 82713F8
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, 0
	goto_eq EventScript_271427
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, 0
	goto_if 5, EventScript_NotEnoughMonsForDoubleRematchBattle
	special SetUpTrainerEncounterMusic
	special sub_80B16D8
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special BattleSetup_StartRematchBattle
	waitstate
	releaseall
	end

EventScript_271427:: @ 8271427
	gotopostbattlescript

EventScript_NotEnoughMonsForDoubleRematchBattle:: @ 8271428
	special ShowTrainerCantBattleSpeech
	waitmessage
	waitbuttonpress
	release
	end

EventScript_27142F:: @ 827142F
	applymovement VAR_LAST_TALKED, Movement_27143A
	waitmovement 0
	return

Movement_27143A: @ 827143A
	step_59
	step_end

EventScript_ShowTrainerIntroMsg:: @ 827143C
	special ShowTrainerIntroSpeech
	waitmessage
	waitbuttonpress
	special sub_80B45D0
	compare VAR_RESULT, 1
	goto_eq EventScript_271356
	goto EventScript_DoTrainerBattle

EventScript_DoTrainerBattle:: @ 8271454
	trainerbattlebegin
	specialvar VAR_RESULT, GetTrainerBattleMode
	compare VAR_RESULT, 0
	goto_eq EventScript_271491
	compare VAR_RESULT, 2
	goto_eq EventScript_271491
	compare VAR_RESULT, 1
	goto_eq EventScript_271491
	compare VAR_RESULT, 6
	goto_eq EventScript_271491
	compare VAR_RESULT, 8
	goto_eq EventScript_271491

EventScript_271491:: @ 8271491
	gotobeatenscript
	releaseall
	end

Std_6:: @ 8271494
	message 0x0
	waitmessage
	waitbuttonpress
	release
	return

EventScript_27149D:: @ 827149D
	setberrytree 2, 7, 5
	setberrytree 1, 3, 5
	setberrytree 11, 7, 5
	setberrytree 13, 3, 5
	setberrytree 4, 7, 5
	setberrytree 76, 1, 5
	setberrytree 8, 1, 5
	setberrytree 10, 6, 5
	setberrytree 25, 20, 5
	setberrytree 26, 2, 5
	setberrytree 66, 2, 5
	setberrytree 67, 20, 5
	setberrytree 69, 22, 5
	setberrytree 70, 22, 5
	setberrytree 71, 22, 5
	setberrytree 55, 17, 5
	setberrytree 56, 17, 5
	setberrytree 5, 1, 5
	setberrytree 6, 6, 5
	setberrytree 7, 1, 5
	setberrytree 16, 18, 5
	setberrytree 17, 18, 5
	setberrytree 18, 18, 5
	setberrytree 29, 19, 5
	setberrytree 28, 19, 5
	setberrytree 27, 19, 5
	setberrytree 24, 4, 5
	setberrytree 23, 3, 5
	setberrytree 22, 3, 5
	setberrytree 21, 4, 5
	setberrytree 19, 16, 5
	setberrytree 20, 16, 5
	setberrytree 80, 7, 5
	setberrytree 81, 7, 5
	setberrytree 77, 8, 5
	setberrytree 78, 8, 5
	setberrytree 68, 8, 5
	setberrytree 31, 10, 5
	setberrytree 33, 10, 5
	setberrytree 34, 21, 5
	setberrytree 35, 21, 5
	setberrytree 36, 21, 5
	setberrytree 83, 24, 5
	setberrytree 84, 24, 5
	setberrytree 85, 10, 5
	setberrytree 86, 6, 5
	setberrytree 37, 5, 5
	setberrytree 38, 5, 5
	setberrytree 39, 5, 5
	setberrytree 40, 3, 5
	setberrytree 41, 3, 5
	setberrytree 42, 3, 5
	setberrytree 46, 19, 5
	setberrytree 45, 20, 5
	setberrytree 44, 18, 5
	setberrytree 43, 16, 5
	setberrytree 47, 8, 5
	setberrytree 48, 5, 5
	setberrytree 49, 4, 5
	setberrytree 50, 2, 5
	setberrytree 52, 18, 5
	setberrytree 53, 18, 5
	setberrytree 62, 6, 5
	setberrytree 64, 6, 5
	setberrytree 58, 21, 5
	setberrytree 59, 21, 5
	setberrytree 60, 25, 5
	setberrytree 61, 25, 5
	setberrytree 79, 23, 5
	setberrytree 14, 23, 5
	setberrytree 15, 21, 5
	setberrytree 30, 21, 5
	setberrytree 65, 25, 5
	setberrytree 72, 25, 5
	setberrytree 73, 23, 5
	setberrytree 74, 23, 5
	setberrytree 87, 3, 5
	setberrytree 88, 10, 5
	setberrytree 89, 4, 5
	setberrytree 82, 36, 5
	return

EventScript_2715DE:: @ 82715DE
	setflag FLAG_0x056
	setflag FLAG_0x301
	setflag FLAG_0x302
	setflag FLAG_0x303
	setflag FLAG_0x2D1
	setflag FLAG_0x379
	setflag FLAG_0x32B
	setflag FLAG_0x32C
	setflag FLAG_0x346
	setflag FLAG_0x2D6
	setflag FLAG_0x363
	setflag FLAG_0x2DB
	setflag FLAG_0x2DC
	setflag FLAG_0x32E
	setflag FLAG_0x34C
	setflag FLAG_0x364
	setflag FLAG_0x2E3
	setflag FLAG_0x371
	setflag FLAG_0x2E2
	setflag FLAG_0x2E4
	setflag FLAG_0x2E5
	setflag FLAG_0x2E7
	setflag FLAG_0x2E8
	setflag FLAG_0x38A
	setflag FLAG_0x345
	setflag FLAG_0x306
	setflag FLAG_0x37F
	setflag FLAG_0x308
	setflag FLAG_0x309
	setflag FLAG_0x30A
	setflag FLAG_0x30B
	setflag FLAG_0x30C
	setflag FLAG_0x30D
	setflag FLAG_0x338
	setflag FLAG_0x2E9
	setflag FLAG_0x2EA
	setflag FLAG_0x2F8
	setflag FLAG_0x2D2
	setflag FLAG_0x2DE
	setflag FLAG_0x351
	setflag FLAG_0x32F
	setflag FLAG_0x315
	setflag FLAG_0x316
	setflag FLAG_0x317
	setflag FLAG_0x318
	setflag FLAG_0x2DA
	setflag FLAG_0x31D
	setflag FLAG_0x31E
	setflag FLAG_0x31F
	setflag FLAG_0x385
	setflag FLAG_0x386
	setflag FLAG_0x387
	setflag FLAG_0x388
	setflag FLAG_0x323
	setflag FLAG_0x322
	setflag FLAG_0x326
	setflag FLAG_0x328
	setflag FLAG_0x329
	setflag FLAG_0x3D8
	setflag FLAG_0x2FE
	setflag FLAG_0x33E
	setflag FLAG_0x362
	setflag FLAG_0x365
	setflag FLAG_0x33C
	setflag FLAG_0x33D
	setflag FLAG_0x33F
	setflag FLAG_0x35B
	setflag FLAG_0x355
	setflag FLAG_0x349
	setflag FLAG_0x34D
	setflag FLAG_0x34E
	setflag FLAG_0x35C
	setflag FLAG_0x35D
	setflag FLAG_0x343
	setflag FLAG_0x348
	setflag FLAG_0x350
	setflag FLAG_0x353
	setflag FLAG_0x312
	setflag FLAG_0x3CD
	setflag FLAG_0x330
	setflag FLAG_0x366
	setflag FLAG_0x368
	setflag FLAG_0x36D
	setflag FLAG_0x3E2
	setflag FLAG_0x36F
	setflag FLAG_0x37B
	setflag FLAG_0x370
	setflag FLAG_0x36E
	setflag FLAG_0x327
	setflag FLAG_0x3D7
	setflag FLAG_0x376
	setflag FLAG_0x374
	setflag FLAG_0x375
	setflag FLAG_SPRITEVIS_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_0x378
	setflag FLAG_0x2F0
	setflag FLAG_0x2F5
	setflag FLAG_0x31A
	setflag FLAG_0x31B
	setflag FLAG_0x37C
	setflag FLAG_0x380
	setflag FLAG_0x381
	setflag FLAG_0x382
	setflag FLAG_0x38D
	setflag FLAG_0x2EC
	setflag FLAG_0x38E
	setflag FLAG_0x38F
	setflag FLAG_0x393
	setflag FLAG_0x358
	setflag FLAG_SPRITEVIS_MAUVILLE_CITY_WATTSON
	setflag FLAG_0x2FD
	setflag FLAG_0x398
	setflag FLAG_0x399
	setflag FLAG_0x39A
	setflag FLAG_0x39B
	setflag FLAG_0x2CF
	setflag FLAG_0x39D
	setflag FLAG_0x3A1
	setflag FLAG_0x3A2
	setflag FLAG_0x3A6
	setflag FLAG_0x3AA
	setflag FLAG_0x3AC
	setflag FLAG_0x3A0
	setflag FLAG_0x3E0
	setflag FLAG_0x342
	setflag FLAG_0x3B0
	setflag FLAG_0x3B1
	setflag FLAG_0x3B3
	setflag FLAG_0x3B4
	setflag FLAG_0x2ED
	setflag FLAG_0x35A
	setflag FLAG_0x2EF
	setflag FLAG_0x3B6
	setflag FLAG_0x3C7
	setflag FLAG_0x3C8
	setflag FLAG_0x2D7
	setflag FLAG_0x3D3
	setflag FLAG_0x3DF
	setflag FLAG_0x3E3
	setflag FLAG_0x3E4
	setflag FLAG_0x3E5
	setflag FLAG_0x3E6
	setflag FLAG_0x356
	setflag FLAG_0x33A
	setflag FLAG_0x33B
	setflag FLAG_0x36C
	setflag FLAG_0x36B
	setflag FLAG_0x36A
	setflag FLAG_0x337
	setflag FLAG_0x2F4
	setflag FLAG_0x35E
	setflag FLAG_0x35F
	setflag FLAG_0x340
	setflag FLAG_0x2FB
	setflag FLAG_0x2EB
	setflag FLAG_0x2FF
	setflag FLAG_0x319
	setflag FLAG_0x357
	setflag FLAG_0x050
	call EventScript_27149D
	end

EverGrandeCity_HallOfFame_EventScript_2717C1:: @ 82717C1
	special sub_81AFDD0
	setflag FLAG_0x87F
	call EverGrandeCity_HallOfFame_EventScript_271829
	compare VAR_0x40CC, 0
	call_if 1, EverGrandeCity_HallOfFame_EventScript_271839
	clearflag FLAG_0x39D
	call EverGrandeCity_HallOfFame_EventScript_2718CC
	setflag FLAG_0x365
	clearflag FLAG_0x3B6
	clearflag FLAG_0x2D7
	setvar VAR_0x40C6, 2
	setflag FLAG_0x35A
	clearflag FLAG_0x2EF
	clearflag FLAG_0x35C
	clearflag FLAG_0x35D
	setflag FLAG_0x2CD
	clearflag FLAG_0x2EB
	setflag FLAG_0x3CB
	special sub_813BA60
	checkflag FLAG_0x123
	call_if 0, EverGrandeCity_HallOfFame_EventScript_271843
	checkflag FLAG_0x12A
	call_if 0, EverGrandeCity_HallOfFame_EventScript_27183F
	setflag FLAG_0x2F8
	setflag FLAG_0x2D2
	compare VAR_0x40D3, 0
	call_if 1, EverGrandeCity_HallOfFame_EventScript_271851
	return

EverGrandeCity_HallOfFame_EventScript_271829:: @ 8271829
	clearflag FLAG_0x1C7
	clearflag FLAG_0x1C8
	clearflag FLAG_0x1AC
	clearflag FLAG_0x1DD
	clearflag FLAG_0x1DC
	return

EverGrandeCity_HallOfFame_EventScript_271839:: @ 8271839
	setvar VAR_0x40CC, 1
	return

EverGrandeCity_HallOfFame_EventScript_27183F:: @ 827183F
	clearflag FLAG_0x3C8
	return

EverGrandeCity_HallOfFame_EventScript_271843:: @ 8271843
	setvar VAR_0x4082, 3
	setvar VAR_0x408C, 3
	clearflag FLAG_0x2DE
	return

EverGrandeCity_HallOfFame_EventScript_271851:: @ 8271851
	setvar VAR_0x40D3, 1
	return

EventScript_WhiteOut:: @ 8271857
	call EverGrandeCity_HallOfFame_EventScript_2718CC
	goto EventScript_271862
	end

EventScript_271862:: @ 8271862
	compare VAR_0x4096, 1
	goto_eq EverGrandeCity_HallOfFame_EventScript_271884
	compare VAR_0x4096, 2
	goto_eq EverGrandeCity_HallOfFame_EventScript_27189A
	compare VAR_0x4096, 3
	goto_eq EverGrandeCity_HallOfFame_EventScript_2718B3
	end

EverGrandeCity_HallOfFame_EventScript_271884:: @ 8271884
	setflag FLAG_0x2E4
	setflag FLAG_0x2E7
	setflag FLAG_0x2E5
	setflag FLAG_0x2E8
	clearflag FLAG_0x2E6
	clearflag FLAG_0x2E3
	clearflag FLAG_0x371
	end

EverGrandeCity_HallOfFame_EventScript_27189A:: @ 827189A
	setflag FLAG_0x2E5
	setflag FLAG_0x2E8
	setflag FLAG_0x2E2
	setflag FLAG_0x2E6
	setflag FLAG_0x2E3
	setflag FLAG_0x371
	clearflag FLAG_0x2E4
	clearflag FLAG_0x2E7
	end

EverGrandeCity_HallOfFame_EventScript_2718B3:: @ 82718B3
	setflag FLAG_0x2E2
	setflag FLAG_0x2E6
	setflag FLAG_0x2E3
	setflag FLAG_0x371
	setflag FLAG_0x2E4
	setflag FLAG_0x2E7
	clearflag FLAG_0x2E5
	clearflag FLAG_0x2E8
	end

EverGrandeCity_HallOfFame_EventScript_2718CC:: @ 82718CC
	clearflag FLAG_0x4FB
	clearflag FLAG_0x4FC
	clearflag FLAG_0x4FD
	clearflag FLAG_0x4FE
	setvar VAR_0x409C, 0
	return

DewfordTown_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
FallarborTown_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
LavaridgeTown_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
MauvilleCity_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
OldaleTown_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
PetalburgCity_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
RustboroCity_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
SlateportCity_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
VerdanturfTown_PokemonCenter_1F_EventScript_2718DE:: @ 82718DE
	checkflag FLAG_0x0BC
	goto_if 0, OldaleTown_PokemonCenter_1F_EventScript_27374E
	checkflag FLAG_0x4F4
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_27374E
	checkflag FLAG_0x2E6
	goto_if 0, OldaleTown_PokemonCenter_1F_EventScript_27190C
	checkflag FLAG_0x2E4
	goto_if 0, OldaleTown_PokemonCenter_1F_EventScript_271912
	checkflag FLAG_0x2E5
	goto_if 0, OldaleTown_PokemonCenter_1F_EventScript_271918
	return

OldaleTown_PokemonCenter_1F_EventScript_27190C:: @ 827190C
	setvar VAR_0x4096, 1
	return

OldaleTown_PokemonCenter_1F_EventScript_271912:: @ 8271912
	setvar VAR_0x4096, 2
	return

OldaleTown_PokemonCenter_1F_EventScript_271918:: @ 8271918
	setvar VAR_0x4096, 3
	return

BattleFrontier_PokemonCenter_1F_EventScript_27191E:: @ 827191E
DewfordTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
EverGrandeCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
EverGrandeCity_PokemonLeague_1F_EventScript_27191E:: @ 827191E
FallarborTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
FortreeCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
LavaridgeTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
LilycoveCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
MauvilleCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
MossdeepCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
OldaleTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
PacifidlogTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
PetalburgCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
RustboroCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
SlateportCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
SootopolisCity_PokemonCenter_1F_EventScript_27191E:: @ 827191E
TrainerHill_Entrance_EventScript_27191E:: @ 827191E
VerdanturfTown_PokemonCenter_1F_EventScript_27191E:: @ 827191E
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, sub_80C2E40
	compare VAR_RESULT, 4
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A68
	msgbox gUnknown_082726EB, 5
	compare VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_27195A
	compare VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271954
	end

OldaleTown_PokemonCenter_1F_EventScript_271954:: @ 8271954
	message gUnknown_082727DB
	return

OldaleTown_PokemonCenter_1F_EventScript_27195A:: @ 827195A
	incrementgamestat 15
	compare VAR_0x8004, 0
	call_if 1, OldaleTown_PokemonCenter_1F_EventScript_271987
	compare VAR_0x8004, 1
	call_if 1, OldaleTown_PokemonCenter_1F_EventScript_27198D
	waitmessage
	call OldaleTown_PokemonCenter_1F_EventScript_271993
	checkflag FLAG_0x111
	goto_if 0, OldaleTown_PokemonCenter_1F_EventScript_271A43
	goto OldaleTown_PokemonCenter_1F_EventScript_2719B1
	end

OldaleTown_PokemonCenter_1F_EventScript_271987:: @ 8271987
	message gUnknown_08272768
	return

OldaleTown_PokemonCenter_1F_EventScript_27198D:: @ 827198D
	message gUnknown_082729C0
	return

OldaleTown_PokemonCenter_1F_EventScript_271993:: @ 8271993
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_2725A4
	waitmovement 0
	dofieldeffect 25
	waitfieldeffect 25
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_2725AA
	waitmovement 0
	special HealPlayerParty
	return

OldaleTown_PokemonCenter_1F_EventScript_2719B1:: @ 82719B1
	specialvar VAR_RESULT, sub_8139ED0
	compare VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719E2
	specialvar VAR_RESULT, sp182_move_string
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719E2
	compare VAR_0x8008, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A19
	end

OldaleTown_PokemonCenter_1F_EventScript_2719E2:: @ 82719E2
	compare VAR_0x8004, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A03
	message gUnknown_08272798
	waitmessage
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_271AD0
	waitmovement 0
	message gUnknown_082727DB
	return

OldaleTown_PokemonCenter_1F_EventScript_271A03:: @ 8271A03
	message gUnknown_082729F0
	waitmessage
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_271AD0
	waitmovement 0
	message gUnknown_08272A07
	return

OldaleTown_PokemonCenter_1F_EventScript_271A19:: @ 8271A19
	checkflag FLAG_0x880
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719E2
	msgbox gUnknown_08272798, 4
	setflag FLAG_0x880
	message OldaleTown_PokemonCenter_1F_Text_278A48
	waitmessage
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_271AD0
	waitmovement 0
	message gUnknown_082727DB
	return

OldaleTown_PokemonCenter_1F_EventScript_271A43:: @ 8271A43
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A5F
	compare VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719B1
	end

OldaleTown_PokemonCenter_1F_EventScript_271A5F:: @ 8271A5F
	message gUnknown_08272F07
	setflag FLAG_0x111
	return

OldaleTown_PokemonCenter_1F_EventScript_271A68:: @ 8271A68
	checkflag FLAG_0x159
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271AAC
	setflag FLAG_0x159
	msgbox gUnknown_082727F5, 4
	playse SE_PIN
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_272598
	waitmovement 0
	applymovement VAR_0x800B, OldaleTown_PokemonCenter_1F_Movement_27259A
	waitmovement 0
	msgbox gUnknown_08272860, 5
	compare VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271AC5
	message gUnknown_08272A07
	return

OldaleTown_PokemonCenter_1F_EventScript_271AAC:: @ 8271AAC
	msgbox gUnknown_08272982, 5
	compare VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271AC5
	message gUnknown_08272A07
	return

OldaleTown_PokemonCenter_1F_EventScript_271AC5:: @ 8271AC5
	setvar VAR_0x8004, 1
	goto OldaleTown_PokemonCenter_1F_EventScript_27195A
	end

OldaleTown_PokemonCenter_1F_Movement_271AD0: @ 8271AD0
	step_4f
	step_12
	step_end

Std_ObtainItem:: @ 8271AD3
	giveitem VAR_0x8000, 32769
	copyvar VAR_0x8007, VAR_RESULT
	call EventScript_271AE3
	return

EventScript_271AE3:: @ 8271AE3
	bufferitemnameplural 1, VAR_0x8000, 32769
	checkitemtype VAR_0x8000
	call EventScript_271B08
	compare VAR_0x8007, 1
	call_if 1, EventScript_271B95
	compare VAR_0x8007, 0
	call_if 1, EventScript_271BA9
	return

EventScript_271B08:: @ 8271B08
	switch VAR_RESULT
	case 1, EventScript_271B45
	case 5, EventScript_271B55
	case 2, EventScript_271B65
	case 3, EventScript_271B75
	case 4, EventScript_271B85
	end

EventScript_271B45:: @ 8271B45
	bufferstdstring 2, 14
	compare VAR_0x8007, 1
	call_if 1, EventScript_271BAF
	return

EventScript_271B55:: @ 8271B55
	bufferstdstring 2, 15
	compare VAR_0x8007, 1
	call_if 1, EventScript_271BAF
	return

EventScript_271B65:: @ 8271B65
	bufferstdstring 2, 16
	compare VAR_0x8007, 1
	call_if 1, EventScript_271BAF
	return

EventScript_271B75:: @ 8271B75
	bufferstdstring 2, 17
	compare VAR_0x8007, 1
	call_if 1, EventScript_271BB3
	return

EventScript_271B85:: @ 8271B85
	bufferstdstring 2, 18
	compare VAR_0x8007, 1
	call_if 1, EventScript_271BAF
	return

EventScript_271B95:: @ 8271B95
	message gUnknown_08272A78
	waitfanfare
	msgbox gUnknown_08272A9A, 4
	setvar VAR_RESULT, 1
	return

EventScript_271BA9:: @ 8271BA9
	setvar VAR_RESULT, 0
	return

EventScript_271BAF:: @ 8271BAF
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
	call_if 1, EventScript_271BE0
	compare VAR_0x8007, 0
	call_if 1, EventScript_271BF7
	return

EventScript_271BE0:: @ 8271BE0
	playfanfare MUS_FANFA4
	message gUnknown_08272B09
	waitfanfare
	msgbox gUnknown_08272B48, 4
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
	checkitemspace VAR_0x8000, 32769
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8000, 32769
	checkitemtype VAR_0x8000
	call EventScript_271B08
	compare VAR_0x8007, 1
	call_if 1, EventScript_271C3A
	compare VAR_0x8007, 0
	call_if 1, EventScript_271CA1
	release
	return

EventScript_271C3A:: @ 8271C3A
	removeobject VAR_LAST_TALKED
	giveitem VAR_0x8004, 32773
	specialvar VAR_RESULT, sub_81398C0
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 1
	call_if 1, EventScript_271C8F
	compare VAR_0x8008, 0
	call_if 1, EventScript_271C9B
	waitfanfare
	waitmessage
	bufferitemnameplural 1, VAR_0x8004, 32773
	setvar VAR_0x8004, 12
	special sub_81A8E7C
	compare VAR_RESULT, 1
	goto_eq EventScript_271C86
	msgbox gUnknown_08272A9A, 4
	return

EventScript_271C86:: @ 8271C86
	msgbox gUnknown_08272AEA, 4
	return

EventScript_271C8F:: @ 8271C8F
	bufferitemnameplural 0, VAR_0x8004, 32773
	message gUnknown_082731A9
	return

EventScript_271C9B:: @ 8271C9B
	message gUnknown_08272ABF
	return

EventScript_271CA1:: @ 8271CA1
	msgbox gUnknown_08272A78, 4
	msgbox gUnknown_08272AD0, 4
	setvar VAR_RESULT, 0
	return

EventScript_271CB7:: @ 8271CB7
	lockall
	waitse
	giveitem VAR_0x8005, 1
	copyvar VAR_0x8007, VAR_RESULT
	bufferitemnameplural 1, VAR_0x8005, 1
	checkitemtype VAR_0x8005
	call EventScript_271B08
	compare VAR_0x8007, 1
	goto_eq EventScript_271CE8
	compare VAR_0x8007, 0
	goto_eq EventScript_271D47
	end

EventScript_271CE8:: @ 8271CE8
	copyvar VAR_0x8008, VAR_0x8004
	copyvar VAR_0x8004, VAR_0x8005
	specialvar VAR_RESULT, sub_81398C0
	compare VAR_RESULT, 1
	goto_eq EventScript_271D0E
	compare VAR_RESULT, 0
	goto_eq EventScript_271D1F
	end

EventScript_271D0E:: @ 8271D0E
	bufferitemnameplural 0, VAR_0x8004, 1
	message gUnknown_082731A9
	goto EventScript_271D2A
	end

EventScript_271D1F:: @ 8271D1F
	message gUnknown_08272ABF
	goto EventScript_271D2A
	end

EventScript_271D2A:: @ 8271D2A
	waitmessage
	waitfanfare
	bufferitemnameplural 1, VAR_0x8004, 1
	copyvar VAR_0x8004, VAR_0x8008
	msgbox gUnknown_08272A9A, 4
	special sub_80EDCE8
	special SetFlagInVar
	releaseall
	end

EventScript_271D47:: @ 8271D47
	msgbox gUnknown_08272ABF, 4
	msgbox gUnknown_08272AD0, 4
	setvar VAR_RESULT, 0
	releaseall
	end

EventScript_271D5E:: @ 8271D5E
	lock
	faceplayer
	msgbox Text_27260D, 5
	compare VAR_RESULT, 1
	goto_eq EventScript_271D83
	compare VAR_RESULT, 0
	goto_eq EventScript_271D89
	goto EventScript_271D89

EventScript_271D83:: @ 8271D83
	special sub_80E6BE8
	waitstate
	lock
	faceplayer

EventScript_271D89:: @ 8271D89
	message Text_272640
	waitmessage
	waitbuttonpress
	release
	end

EventScript_271D92:: @ 8271D92
	lockall
	setvar VAR_0x8004, 0
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox Text_27265A, 4
	goto EventScript_271DAC
	end

EventScript_271DAC:: @ 8271DAC
	message gUnknown_0827266F
	waitmessage
	special ScrSpecial_CreatePCMenu
	waitstate
	goto EventScript_271DBC
	end

EventScript_271DBC:: @ 8271DBC
	switch VAR_RESULT
	case 0, EventScript_271E0E
	case 1, EventScript_271DF9
	case 2, EventScript_271E54
	case 3, EventScript_271E47
	case 127, EventScript_271E47
	end

EventScript_271DF9:: @ 8271DF9
	playse SE_PC_LOGIN
	msgbox gUnknown_082726C2, 4
	special sub_816AE98
	waitstate
	goto EventScript_271DAC
	end

EventScript_271E0E:: @ 8271E0E
	playse SE_PC_LOGIN
	checkflag FLAG_SYS_PC_LANETTE
	call_if 0, EventScript_271E35
	checkflag FLAG_SYS_PC_LANETTE
	call_if 1, EventScript_271E3E
	msgbox gUnknown_082726A3, 4
	special sub_80C7578
	waitstate
	goto EventScript_271DAC
	end

EventScript_271E35:: @ 8271E35
	msgbox gUnknown_0827268C, 4
	return

EventScript_271E3E:: @ 8271E3E
	msgbox gUnknown_082726D4, 4
	return

EventScript_271E47:: @ 8271E47
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

EventScript_271E54:: @ 8271E54
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, EventScript_271E47
	playse SE_PC_LOGIN
	special AccessHallOfFamePC
	waitstate
	goto EventScript_271DBC
	end

BattleFrontier_OutsideWest_EventScript_271E6A:: @ 8271E6A
FallarborTown_EventScript_271E6A:: @ 8271E6A
FortreeCity_EventScript_271E6A:: @ 8271E6A
LavaridgeTown_EventScript_271E6A:: @ 8271E6A
MauvilleCity_EventScript_271E6A:: @ 8271E6A
MossdeepCity_EventScript_271E6A:: @ 8271E6A
OldaleTown_EventScript_271E6A:: @ 8271E6A
PetalburgCity_EventScript_271E6A:: @ 8271E6A
RustboroCity_EventScript_271E6A:: @ 8271E6A
SlateportCity_EventScript_271E6A:: @ 8271E6A
SootopolisCity_EventScript_271E6A:: @ 8271E6A
VerdanturfTown_EventScript_271E6A:: @ 8271E6A
	msgbox gUnknown_08272B6A, 3
	end

BattleFrontier_OutsideEast_EventScript_271E73:: @ 8271E73
DewfordTown_EventScript_271E73:: @ 8271E73
EverGrandeCity_EventScript_271E73:: @ 8271E73
FallarborTown_EventScript_271E73:: @ 8271E73
FortreeCity_EventScript_271E73:: @ 8271E73
LavaridgeTown_EventScript_271E73:: @ 8271E73
LilycoveCity_EventScript_271E73:: @ 8271E73
MauvilleCity_EventScript_271E73:: @ 8271E73
MossdeepCity_EventScript_271E73:: @ 8271E73
OldaleTown_EventScript_271E73:: @ 8271E73
PacifidlogTown_EventScript_271E73:: @ 8271E73
PetalburgCity_EventScript_271E73:: @ 8271E73
RustboroCity_EventScript_271E73:: @ 8271E73
SlateportCity_EventScript_271E73:: @ 8271E73
SootopolisCity_EventScript_271E73:: @ 8271E73
VerdanturfTown_EventScript_271E73:: @ 8271E73
	msgbox gUnknown_08272B9E, 3
	end

BattleFrontier_BattleTowerLobby_EventScript_271E7C:: @ 8271E7C
DewfordTown_EventScript_271E7C:: @ 8271E7C
LilycoveCity_ContestLobby_EventScript_271E7C:: @ 8271E7C
LilycoveCity_PokemonTrainerFanClub_EventScript_271E7C:: @ 8271E7C
MauvilleCity_PokemonCenter_1F_EventScript_271E7C:: @ 8271E7C
PetalburgCity_PokemonCenter_1F_EventScript_271E7C:: @ 8271E7C
Route111_EventScript_271E7C:: @ 8271E7C
Route123_BerryMastersHouse_EventScript_271E7C:: @ 8271E7C
SlateportCity_OceanicMuseum_1F_EventScript_271E7C:: @ 8271E7C
SlateportCity_PokemonFanClub_EventScript_271E7C:: @ 8271E7C
	fadescreen 1
	special easy_chat_input_maybe
	fadescreen 0
	return

DewfordTown_Gym_EventScript_271E84:: @ 8271E84
LavaridgeTown_Gym_1F_EventScript_271E84:: @ 8271E84
MauvilleCity_Gym_EventScript_271E84:: @ 8271E84
RustboroCity_Gym_EventScript_271E84:: @ 8271E84
	clearflag FLAG_0x30D
	setflag FLAG_0x128
	return

DewfordTown_EventScript_271E8B:: @ 8271E8B
DewfordTown_Hall_EventScript_271E8B:: @ 8271E8B
	dodailyevents
	setvar VAR_0x8004, 0
	special sub_8122998
	return

DewfordTown_EventScript_271E95:: @ 8271E95
Route104_MrBrineysHouse_EventScript_271E95:: @ 8271E95
Route109_EventScript_271E95:: @ 8271E95
	copyvar VAR_0x8008, VAR_0x4096
	setvar VAR_0x4096, 0
	return

EventScript_271EA0:: @ 8271EA0
	checkpartymove MOVE_SURF
	compare VAR_RESULT, 6
	goto_eq EventScript_271ED6
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gUnknown_08272FD6, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_271ED5
	msgbox gUnknown_0827300D, 4
	dofieldeffect 9

EventScript_271ED5:: @ 8271ED5
	releaseall

EventScript_271ED6:: @ 8271ED6
	end

EverGrandeCity_ChampionsRoom_EventScript_271ED7:: @ 8271ED7
LavaridgeTown_EventScript_271ED7:: @ 8271ED7
LilycoveCity_EventScript_271ED7:: @ 8271ED7
LittlerootTown_EventScript_271ED7:: @ 8271ED7
LittlerootTown_ProfessorBirchsLab_EventScript_271ED7:: @ 8271ED7
OldaleTown_EventScript_271ED7:: @ 8271ED7
Route103_EventScript_271ED7:: @ 8271ED7
Route104_EventScript_271ED7:: @ 8271ED7
Route110_EventScript_271ED7:: @ 8271ED7
Route119_EventScript_271ED7:: @ 8271ED7
RustboroCity_EventScript_271ED7:: @ 8271ED7
	checkplayergender
	compare VAR_RESULT, 0
	goto_eq RustboroCity_EventScript_271EEF
	compare VAR_RESULT, 1
	goto_eq RustboroCity_EventScript_271EF5
	end

RustboroCity_EventScript_271EEF:: @ 8271EEF
	setvar VAR_0x4010, 105
	return

RustboroCity_EventScript_271EF5:: @ 8271EF5
	setvar VAR_0x4010, 100
	return

LavaridgeTown_EventScript_271EFB:: @ 8271EFB
Route110_EventScript_271EFB:: @ 8271EFB
Route119_EventScript_271EFB:: @ 8271EFB
	checkplayergender
	compare VAR_RESULT, 0
	goto_eq LavaridgeTown_EventScript_271F13
	compare VAR_RESULT, 1
	goto_eq LavaridgeTown_EventScript_271F19
	end

LavaridgeTown_EventScript_271F13:: @ 8271F13
	setvar VAR_0x4013, 106
	return

LavaridgeTown_EventScript_271F19:: @ 8271F19
	setvar VAR_0x4013, 101
	return

EventScript_271F1F:: @ 8271F1F
	checkplayergender
	compare VAR_RESULT, 0
	goto_eq EventScript_271F37
	compare VAR_RESULT, 1
	goto_eq EventScript_271F3D
	end

EventScript_271F37:: @ 8271F37
	setvar VAR_0x4010, 100
	return

EventScript_271F3D:: @ 8271F3D
	setvar VAR_0x4010, 105
	return

DewfordTown_Gym_EventScript_271F43:: @ 8271F43
FortreeCity_Gym_EventScript_271F43:: @ 8271F43
LavaridgeTown_Gym_1F_EventScript_271F43:: @ 8271F43
MauvilleCity_Gym_EventScript_271F43:: @ 8271F43
MossdeepCity_Gym_EventScript_271F43:: @ 8271F43
PetalburgCity_Gym_EventScript_271F43:: @ 8271F43
RustboroCity_Gym_EventScript_271F43:: @ 8271F43
SootopolisCity_Gym_1F_EventScript_271F43:: @ 8271F43
	switch VAR_0x8008
	case 1, DewfordTown_Gym_EventScript_271FA1
	case 2, DewfordTown_Gym_EventScript_271FAB
	case 3, DewfordTown_Gym_EventScript_271FBE
	case 4, DewfordTown_Gym_EventScript_271FCE
	case 5, DewfordTown_Gym_EventScript_271FE7
	case 6, DewfordTown_Gym_EventScript_271FFD
	case 7, DewfordTown_Gym_EventScript_272010
	case 8, DewfordTown_Gym_EventScript_272035
	end

DewfordTown_Gym_EventScript_271FA1:: @ 8271FA1
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	return

DewfordTown_Gym_EventScript_271FAB:: @ 8271FAB
	settrainerflag TRAINER_TAKAO
	settrainerflag TRAINER_JOCELYN
	settrainerflag TRAINER_LAURA
	settrainerflag TRAINER_BRENDEN
	settrainerflag TRAINER_CRISTIAN
	settrainerflag TRAINER_LILITH
	return

DewfordTown_Gym_EventScript_271FBE:: @ 8271FBE
	settrainerflag TRAINER_KIRK
	settrainerflag TRAINER_SHAWN
	settrainerflag TRAINER_BEN
	settrainerflag TRAINER_VIVIAN
	settrainerflag TRAINER_ANGELO
	return

DewfordTown_Gym_EventScript_271FCE:: @ 8271FCE
	settrainerflag TRAINER_COLE
	settrainerflag TRAINER_AXLE
	settrainerflag TRAINER_KEEGAN
	settrainerflag TRAINER_GERALD
	settrainerflag TRAINER_DANIELLE
	settrainerflag TRAINER_JACE
	settrainerflag TRAINER_JEFF
	settrainerflag TRAINER_ELI
	return

DewfordTown_Gym_EventScript_271FE7:: @ 8271FE7
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return

DewfordTown_Gym_EventScript_271FFD:: @ 8271FFD
	settrainerflag TRAINER_JARED
	settrainerflag TRAINER_FLINT
	settrainerflag TRAINER_ASHLEY
	settrainerflag TRAINER_EDWARDO
	settrainerflag TRAINER_HUMBERTO
	settrainerflag TRAINER_DARIUS
	return

DewfordTown_Gym_EventScript_272010:: @ 8272010
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

DewfordTown_Gym_EventScript_272035:: @ 8272035
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

DewfordTown_Gym_EventScript_272054:: @ 8272054
DewfordTown_Hall_EventScript_272054:: @ 8272054
FallarborTown_House1_EventScript_272054:: @ 8272054
FortreeCity_Gym_EventScript_272054:: @ 8272054
FortreeCity_House2_EventScript_272054:: @ 8272054
FortreeCity_House4_EventScript_272054:: @ 8272054
LavaridgeTown_Gym_1F_EventScript_272054:: @ 8272054
LavaridgeTown_HerbShop_EventScript_272054:: @ 8272054
LilycoveCity_EventScript_272054:: @ 8272054
LilycoveCity_House2_EventScript_272054:: @ 8272054
LittlerootTown_BrendansHouse_1F_EventScript_272054:: @ 8272054
MauvilleCity_EventScript_272054:: @ 8272054
MauvilleCity_Gym_EventScript_272054:: @ 8272054
MossdeepCity_EventScript_272054:: @ 8272054
MossdeepCity_Gym_EventScript_272054:: @ 8272054
MossdeepCity_SpaceCenter_1F_EventScript_272054:: @ 8272054
MtPyre_1F_EventScript_272054:: @ 8272054
PacifidlogTown_House2_EventScript_272054:: @ 8272054
PetalburgCity_Gym_EventScript_272054:: @ 8272054
PetalburgWoods_EventScript_272054:: @ 8272054
Route104_EventScript_272054:: @ 8272054
Route104_PrettyPetalFlowerShop_EventScript_272054:: @ 8272054
Route109_EventScript_272054:: @ 8272054
Route111_EventScript_272054:: @ 8272054
Route111_WinstrateFamilysHouse_EventScript_272054:: @ 8272054
Route114_EventScript_272054:: @ 8272054
Route114_FossilManiacsHouse_EventScript_272054:: @ 8272054
Route120_EventScript_272054:: @ 8272054
Route123_BerryMastersHouse_EventScript_272054:: @ 8272054
Route123_EventScript_272054:: @ 8272054
RustboroCity_DevonCorp_3F_EventScript_272054:: @ 8272054
RustboroCity_Flat2_2F_EventScript_272054:: @ 8272054
RustboroCity_Gym_EventScript_272054:: @ 8272054
RustboroCity_PokemonSchool_EventScript_272054:: @ 8272054
SSTidalRooms_EventScript_272054:: @ 8272054
ShoalCave_LowTideEntranceRoom_EventScript_272054:: @ 8272054
ShoalCave_LowTideInnerRoom_EventScript_272054:: @ 8272054
ShoalCave_LowTideLowerRoom_EventScript_272054:: @ 8272054
ShoalCave_LowTideStairsRoom_EventScript_272054:: @ 8272054
SlateportCity_BattleTentLobby_EventScript_272054:: @ 8272054
SlateportCity_Harbor_EventScript_272054:: @ 8272054
SlateportCity_PokemonFanClub_EventScript_272054:: @ 8272054
SootopolisCity_EventScript_272054:: @ 8272054
SootopolisCity_Gym_1F_EventScript_272054:: @ 8272054
SootopolisCity_House1_EventScript_272054:: @ 8272054
VerdanturfTown_BattleTentLobby_EventScript_272054:: @ 8272054
	msgbox gUnknown_08272AD0, 4
	release
	end

DewfordTown_Gym_EventScript_27205E:: @ 827205E
FortreeCity_Gym_EventScript_27205E:: @ 827205E
LavaridgeTown_Gym_1F_EventScript_27205E:: @ 827205E
LilycoveCity_ContestLobby_EventScript_27205E:: @ 827205E
LinkContestRoom1_EventScript_27205E:: @ 827205E
MauvilleCity_GameCorner_EventScript_27205E:: @ 827205E
MauvilleCity_Gym_EventScript_27205E:: @ 827205E
MossdeepCity_Gym_EventScript_27205E:: @ 827205E
PetalburgCity_Gym_EventScript_27205E:: @ 827205E
Route110_TrickHouseEnd_EventScript_27205E:: @ 827205E
Route110_TrickHouseEntrance_EventScript_27205E:: @ 827205E
Route113_GlassWorkshop_EventScript_27205E:: @ 827205E
SootopolisCity_Gym_1F_EventScript_27205E:: @ 827205E
	msgbox gUnknown_08272AD0, 4
	return

Route114_LanettesHouse_EventScript_272067:: @ 8272067
	msgbox gUnknown_08272B1A, 4
	release
	end

LilycoveCity_LilycoveMuseum_2F_EventScript_272071:: @ 8272071
MauvilleCity_GameCorner_EventScript_272071:: @ 8272071
Route110_TrickHouseEnd_EventScript_272071:: @ 8272071
Route110_TrickHouseEntrance_EventScript_272071:: @ 8272071
Route113_GlassWorkshop_EventScript_272071:: @ 8272071
	msgbox gUnknown_08272B1A, 4
	return

EverGrandeCity_EventScript_27207A:: @ 827207A
LilycoveCity_EventScript_27207A:: @ 827207A
MossdeepCity_EventScript_27207A:: @ 827207A
Route124_EventScript_27207A:: @ 827207A
Route125_EventScript_27207A:: @ 827207A
Route126_EventScript_27207A:: @ 827207A
Route127_EventScript_27207A:: @ 827207A
Route128_EventScript_27207A:: @ 827207A
Route129_EventScript_27207A:: @ 827207A
Route130_EventScript_27207A:: @ 827207A
Route131_EventScript_27207A:: @ 827207A
SkyPillar_Outside_EventScript_27207A:: @ 827207A
SootopolisCity_EventScript_27207A:: @ 827207A
	setweather 15
	return

DewfordTown_Gym_EventScript_27207E:: @ 827207E
FortreeCity_Gym_EventScript_27207E:: @ 827207E
LavaridgeTown_Gym_1F_EventScript_27207E:: @ 827207E
LilycoveCity_CoveLilyMotel_2F_EventScript_27207E:: @ 827207E
MauvilleCity_Gym_EventScript_27207E:: @ 827207E
MossdeepCity_Gym_EventScript_27207E:: @ 827207E
PetalburgCity_Gym_EventScript_27207E:: @ 827207E
RustboroCity_Gym_EventScript_27207E:: @ 827207E
SootopolisCity_Gym_1F_EventScript_27207E:: @ 827207E
	playfanfare MUS_ME_BACHI
	waitfanfare
	return

LittlerootTown_BrendansHouse_1F_EventScript_272083:: @ 8272083
Route111_OldLadysRestStop_EventScript_272083:: @ 8272083
Route119_WeatherInstitute_1F_EventScript_272083:: @ 8272083
RustboroCity_DevonCorp_3F_EventScript_272083:: @ 8272083
SSTidalRooms_EventScript_272083:: @ 8272083
	fadescreen 1
	playfanfare MUS_ME_ASA
	waitfanfare
	special HealPlayerParty
	fadescreen 0
	return

EventScript_27208F:: @ 827208F
	lockall
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F8820, 4
	fadescreen 1
	special FieldShowRegionMap
	waitstate
	releaseall
	end

DewfordTown_EventScript_2720A0:: @ 82720A0
Route104_EventScript_2720A0:: @ 82720A0
Route109_EventScript_2720A0:: @ 82720A0
	setflag FLAG_SPECIAL_FLAG_0x4001
	playbgm MUS_M_BOAT, 0
	return

DewfordTown_EventScript_2720A8:: @ 82720A8
Route104_EventScript_2720A8:: @ 82720A8
Route109_EventScript_2720A8:: @ 82720A8
	clearflag FLAG_SPECIAL_FLAG_0x4001
	fadedefaultbgm
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2720AD:: @ 82720AD
Route101_EventScript_2720AD:: @ 82720AD
Route103_EventScript_2720AD:: @ 82720AD
	compare VAR_0x4085, 0
	goto_eq Route101_EventScript_27374E
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 0
	call_if 1, Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 1
	call_if 1, Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 2
	call_if 1, Route101_EventScript_272127
	compare VAR_BIRCH_STATE, 3
	call_if 1, Route101_EventScript_272127
	compare VAR_BIRCH_STATE, 4
	call_if 1, Route101_EventScript_272134
	compare VAR_BIRCH_STATE, 5
	call_if 1, Route101_EventScript_272134
	compare VAR_BIRCH_STATE, 6
	call_if 1, Route101_EventScript_27211A
	compare VAR_BIRCH_STATE, 7
	call_if 1, Route101_EventScript_27211A
	return

Route101_EventScript_27211A:: @ 827211A
	clearflag FLAG_0x2D1
	clearflag FLAG_0x380
	setflag FLAG_0x381
	setflag FLAG_0x382
	return

Route101_EventScript_272127:: @ 8272127
	clearflag FLAG_0x381
	setflag FLAG_0x2D1
	setflag FLAG_0x380
	setflag FLAG_0x382
	return

Route101_EventScript_272134:: @ 8272134
	clearflag FLAG_0x382
	setflag FLAG_0x381
	setflag FLAG_0x2D1
	setflag FLAG_0x380
	return

LittlerootTown_ProfessorBirchsLab_EventScript_272141:: @ 8272141
Route101_EventScript_272141:: @ 8272141
Route103_EventScript_272141:: @ 8272141
	lock
	faceplayer
	checkflag FLAG_HAS_MATCH_CALL
	goto_if 0, Route101_EventScript_272155
	checkflag FLAG_0x119
	goto_if 0, Route101_EventScript_1FA2D2

Route101_EventScript_272155:: @ 8272155
	msgbox gUnknown_082A5C9C, 5
	compare VAR_RESULT, 0
	goto_eq Route101_EventScript_27216F
	call Route101_EventScript_272184
	release
	end

Route101_EventScript_27216F:: @ 827216F
	msgbox Route101_Text_2A5CEB, 4
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
	msgbox gUnknown_082A5D2C, 4
	call Route101_EventScript_272179
	compare VAR_0x800A, 0
	goto_eq Route101_EventScript_27374E
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, ScriptGetPokedexInfo
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	buffernumberstring 0, VAR_0x8008
	buffernumberstring 1, VAR_0x8009
	msgbox gUnknown_082A633D, 4
	return

BattleFrontier_OutsideWest_EventScript_2721E2:: @ 82721E2
LilycoveCity_Harbor_EventScript_2721E2:: @ 82721E2
SlateportCity_Harbor_EventScript_2721E2:: @ 82721E2
	delay 60
	applymovement VAR_0x8004, SlateportCity_Harbor_Movement_2721F0
	waitmovement 0
	return

SlateportCity_Harbor_Movement_2721F0: @ 82721F0
	slow_step_right
	slow_step_right
	slow_step_right
	step_right
	step_right
	step_right
	step_right
	step_end

PetalburgCity_Gym_EventScript_2721F8:: @ 82721F8
	setflag FLAG_0x2E4
	setflag FLAG_0x2E7
	setflag FLAG_0x2E5
	setflag FLAG_0x2E8
	setflag FLAG_0x2E2
	setflag FLAG_0x2E6
	setflag FLAG_0x2E3
	setflag FLAG_0x371
	setvar VAR_0x4096, 0
	return

RusturfTunnel_EventScript_272216:: @ 8272216
	removeobject 1
	removeobject 10
	clearflag FLAG_0x328
	clearflag FLAG_0x3D8
	setvar VAR_0x409A, 6
	setflag FLAG_0x0C7
	return

EventScript_27222B:: @ 827222B
	delay 30
	applymovement 255, PetalburgCity_Movement_2725A6
	waitmovement 0
	showobjectat 255, PETALBURG_CITY
	delay 30
	applymovement 255, Movement_27224E
	waitmovement 0
	delay 30
	return

Movement_27224E: @ 827224E
	step_up
	step_end

BattleFrontier_OutsideWest_EventScript_272250:: @ 8272250
BirthIsland_Harbor_EventScript_272250:: @ 8272250
FarawayIsland_Entrance_EventScript_272250:: @ 8272250
NavelRock_Harbor_EventScript_272250:: @ 8272250
SouthernIsland_Exterior_EventScript_272250:: @ 8272250
	compare VAR_FACING, 1
	call_if 1, BattleFrontier_OutsideWest_EventScript_242A21
	compare VAR_FACING, 3
	call_if 1, BattleFrontier_OutsideWest_EventScript_242A2C
	delay 30
	hideobjectat 255, PETALBURG_CITY
	call BattleFrontier_OutsideWest_EventScript_2721E2
	return

EventScript_272274:: @ 8272274
	lockall
	waitse
	playmoncry SPECIES_KYOGRE, 2
	waitmoncry
	setvar VAR_0x4005, 1
	releaseall
	end

EventScript_272283:: @ 8272283
	lockall
	setvar VAR_0x4001, 1
	goto EventScript_2722A7
	end

EventScript_27228F:: @ 827228F
	lockall
	setvar VAR_0x4002, 1
	goto EventScript_2722A7
	end

EventScript_27229B:: @ 827229B
	lockall
	setvar VAR_0x4003, 1
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
	setvar VAR_0x4001, 1
	setvar VAR_0x4002, 1
	setvar VAR_0x4003, 1
	setvar VAR_0x4004, 1
	setvar VAR_0x4005, 1
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
	goto_eq Route119_EventScript_272350
	msgbox Route119_Text_1F5D00, 4
	release
	end

Route119_EventScript_272350:: @ 8272350
	msgbox Route119_Text_1F5D23, 5
	compare VAR_RESULT, 1
	goto_eq Route119_EventScript_272365
	release
	end

Route119_EventScript_272365:: @ 8272365
	msgbox Route119_Text_1F5D63, 4
	closemessage
	applymovement VAR_LAST_TALKED, Route119_Movement_27259E
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
	specialvar VAR_RESULT, sub_8138B80
	compare VAR_RESULT, 1
	goto_eq Route119_EventScript_2723C1
	compare VAR_RESULT, 4
	goto_eq Route119_EventScript_2723C1
	compare VAR_RESULT, 5
	goto_eq Route119_EventScript_2723C1
	release
	end

Route119_EventScript_2723C1:: @ 82723C1
	goto Route119_EventScript_27376D
	end

FortreeCity_Movement_2723C7: @ 82723C7
Route119_Movement_2723C7: @ 82723C7
Route120_Movement_2723C7: @ 82723C7
	step_55
	step_12
	step_54
	step_12
	step_55
	step_12
	step_54
	step_12
	step_55
	step_13
	step_54
	step_13
	step_55
	step_13
	step_54
	step_13
	step_55
	step_14
	step_54
	step_14
	step_55
	step_end

LittlerootTown_ProfessorBirchsLab_EventScript_2723DD:: @ 82723DD
MossdeepCity_StevensHouse_EventScript_2723DD:: @ 82723DD
Route119_WeatherInstitute_2F_EventScript_2723DD:: @ 82723DD
RustboroCity_DevonCorp_2F_EventScript_2723DD:: @ 82723DD
SlateportCity_House1_EventScript_2723DD:: @ 82723DD
	fadescreen 1
	special ChangePokemonNickname
	waitstate
	return

FallarborTown_House1_EventScript_2723E4:: @ 82723E4
GraniteCave_StevensRoom_EventScript_2723E4:: @ 82723E4
SlateportCity_OceanicMuseum_2F_EventScript_2723E4:: @ 82723E4
	bufferitemname 0, VAR_0x8004
	playfanfare MUS_ME_WAZA
	message gUnknown_08273161
	waitmessage
	waitfanfare
	takeitem VAR_0x8004, 1
	return

EverGrandeCity_DrakesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_GlaciasRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_PhoebesRoom_EventScript_2723F8:: @ 82723F8
EverGrandeCity_SidneysRoom_EventScript_2723F8:: @ 82723F8
	applymovement 255, EverGrandeCity_SidneysRoom_Movement_2725C6
	waitmovement 0
	playse SE_DOOR
	setmetatile 6, 1, 836, 0
	setmetatile 6, 2, 837, 0
	setmetatile 0, 2, 734, 1
	setmetatile 1, 2, 733, 1
	setmetatile 2, 2, 734, 1
	setmetatile 3, 2, 733, 1
	setmetatile 4, 2, 734, 1
	setmetatile 8, 2, 733, 1
	setmetatile 9, 2, 734, 1
	setmetatile 10, 2, 733, 1
	setmetatile 11, 2, 734, 1
	setmetatile 12, 2, 733, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_GlaciasRoom_EventScript_272475:: @ 8272475
EverGrandeCity_PhoebesRoom_EventScript_272475:: @ 8272475
EverGrandeCity_SidneysRoom_EventScript_272475:: @ 8272475
	applymovement 255, EverGrandeCity_SidneysRoom_Movement_2725BA
	waitmovement 0
	playse SE_TRACK_DOOR
	setmetatile 5, 12, 518, 1
	setmetatile 6, 12, 518, 1
	setmetatile 7, 12, 518, 1
	setmetatile 5, 13, 526, 1
	setmetatile 6, 13, 526, 1
	setmetatile 7, 13, 526, 1
	special DrawWholeMapView
	return

EverGrandeCity_DrakesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_GlaciasRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_PhoebesRoom_EventScript_2724BC:: @ 82724BC
EverGrandeCity_SidneysRoom_EventScript_2724BC:: @ 82724BC
	setmetatile 6, 1, 836, 0
	setmetatile 6, 2, 837, 0
	setmetatile 5, 12, 518, 1
	setmetatile 6, 12, 518, 1
	setmetatile 7, 12, 518, 1
	setmetatile 5, 13, 526, 1
	setmetatile 6, 13, 526, 1
	setmetatile 7, 13, 526, 1
	setmetatile 0, 2, 734, 1
	setmetatile 1, 2, 733, 1
	setmetatile 2, 2, 734, 1
	setmetatile 3, 2, 733, 1
	setmetatile 4, 2, 734, 1
	setmetatile 8, 2, 733, 1
	setmetatile 9, 2, 734, 1
	setmetatile 10, 2, 733, 1
	setmetatile 11, 2, 734, 1
	setmetatile 12, 2, 733, 1
	return

EverGrandeCity_DrakesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_GlaciasRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_PhoebesRoom_EventScript_27255F:: @ 827255F
EverGrandeCity_SidneysRoom_EventScript_27255F:: @ 827255F
	setmetatile 5, 12, 518, 1
	setmetatile 6, 12, 518, 1
	setmetatile 7, 12, 518, 1
	setmetatile 5, 13, 526, 1
	setmetatile 6, 13, 526, 1
	setmetatile 7, 13, 526, 1
	return

SlateportCity_Movement_272596: @ 8272596
	step_57
	step_end

AquaHideout_B2F_Movement_272598: @ 8272598
BattleFrontier_BattleTowerBattleRoom_Movement_272598: @ 8272598
BattleFrontier_ReceptionGate_Movement_272598: @ 8272598
CaveOfOrigin_B1F_Movement_272598: @ 8272598
EverGrandeCity_ChampionsRoom_Movement_272598: @ 8272598
FarawayIsland_Interior_Movement_272598: @ 8272598
JaggedPass_Movement_272598: @ 8272598
LavaridgeTown_Movement_272598: @ 8272598
LilycoveCity_ContestLobby_Movement_272598: @ 8272598
LilycoveCity_CoveLilyMotel_1F_Movement_272598: @ 8272598
LilycoveCity_Harbor_Movement_272598: @ 8272598
LittlerootTown_BrendansHouse_1F_Movement_272598: @ 8272598
LittlerootTown_BrendansHouse_2F_Movement_272598: @ 8272598
LittlerootTown_MaysHouse_1F_Movement_272598: @ 8272598
LittlerootTown_MaysHouse_2F_Movement_272598: @ 8272598
LittlerootTown_Movement_272598: @ 8272598
MauvilleCity_House2_Movement_272598: @ 8272598
MauvilleCity_Movement_272598: @ 8272598
MeteorFalls_1F_1R_Movement_272598: @ 8272598
MeteorFalls_StevensCave_Movement_272598: @ 8272598
MossdeepCity_SpaceCenter_2F_Movement_272598: @ 8272598
MossdeepCity_StevensHouse_Movement_272598: @ 8272598
MtChimney_Movement_272598: @ 8272598
MtPyre_Summit_Movement_272598: @ 8272598
OldaleTown_PokemonCenter_1F_Movement_272598: @ 8272598
PetalburgCity_Gym_Movement_272598: @ 8272598
PetalburgCity_Movement_272598: @ 8272598
Route103_Movement_272598: @ 8272598
Route104_Movement_272598: @ 8272598
Route110_Movement_272598: @ 8272598
Route110_TrickHouseEnd_Movement_272598: @ 8272598
Route110_TrickHouseEntrance_Movement_272598: @ 8272598
Route110_TrickHousePuzzle5_Movement_272598: @ 8272598
Route119_WeatherInstitute_2F_Movement_272598: @ 8272598
RustboroCity_DevonCorp_2F_Movement_272598: @ 8272598
RustboroCity_Movement_272598: @ 8272598
RusturfTunnel_Movement_272598: @ 8272598
SeafloorCavern_Entrance_Movement_272598: @ 8272598
SeafloorCavern_Room9_Movement_272598: @ 8272598
SlateportCity_Movement_272598: @ 8272598
SlateportCity_OceanicMuseum_1F_Movement_272598: @ 8272598
SlateportCity_PokemonFanClub_Movement_272598: @ 8272598
	step_56
	step_end

BattleFrontier_BattleTowerBattleRoom_Movement_27259A: @ 827259A
BattleFrontier_ReceptionGate_Movement_27259A: @ 827259A
CaveOfOrigin_B1F_Movement_27259A: @ 827259A
EverGrandeCity_ChampionsRoom_Movement_27259A: @ 827259A
FarawayIsland_Interior_Movement_27259A: @ 827259A
JaggedPass_Movement_27259A: @ 827259A
LavaridgeTown_Movement_27259A: @ 827259A
LilycoveCity_CoveLilyMotel_1F_Movement_27259A: @ 827259A
LilycoveCity_Harbor_Movement_27259A: @ 827259A
LittlerootTown_BrendansHouse_1F_Movement_27259A: @ 827259A
LittlerootTown_BrendansHouse_2F_Movement_27259A: @ 827259A
LittlerootTown_MaysHouse_1F_Movement_27259A: @ 827259A
LittlerootTown_MaysHouse_2F_Movement_27259A: @ 827259A
MauvilleCity_House2_Movement_27259A: @ 827259A
MauvilleCity_Movement_27259A: @ 827259A
MeteorFalls_1F_1R_Movement_27259A: @ 827259A
MeteorFalls_StevensCave_Movement_27259A: @ 827259A
MossdeepCity_SpaceCenter_2F_Movement_27259A: @ 827259A
MossdeepCity_StevensHouse_Movement_27259A: @ 827259A
MtChimney_Movement_27259A: @ 827259A
MtPyre_Summit_Movement_27259A: @ 827259A
OldaleTown_PokemonCenter_1F_Movement_27259A: @ 827259A
PetalburgCity_Gym_Movement_27259A: @ 827259A
PetalburgCity_Movement_27259A: @ 827259A
Route103_Movement_27259A: @ 827259A
Route104_Movement_27259A: @ 827259A
Route110_Movement_27259A: @ 827259A
Route110_TrickHouseEntrance_Movement_27259A: @ 827259A
Route110_TrickHousePuzzle5_Movement_27259A: @ 827259A
Route119_WeatherInstitute_2F_Movement_27259A: @ 827259A
RustboroCity_DevonCorp_2F_Movement_27259A: @ 827259A
RustboroCity_Movement_27259A: @ 827259A
RusturfTunnel_Movement_27259A: @ 827259A
SeafloorCavern_Entrance_Movement_27259A: @ 827259A
SeafloorCavern_Room9_Movement_27259A: @ 827259A
SlateportCity_Movement_27259A: @ 827259A
SlateportCity_OceanicMuseum_1F_Movement_27259A: @ 827259A
SlateportCity_PokemonFanClub_Movement_27259A: @ 827259A
	step_14
	step_14
	step_14
	step_end

AquaHideout_B2F_Movement_27259E: @ 827259E
BattleFrontier_BattlePyramidLobby_Movement_27259E: @ 827259E
BattleFrontier_ScottsHouse_Movement_27259E: @ 827259E
CaveOfOrigin_B1F_Movement_27259E: @ 827259E
EverGrandeCity_PokemonLeague_1F_Movement_27259E: @ 827259E
FallarborTown_House2_Movement_27259E: @ 827259E
FortreeCity_House4_Movement_27259E: @ 827259E
JaggedPass_Movement_27259E: @ 827259E
LilycoveCity_ContestHall_Movement_27259E: @ 827259E
LilycoveCity_CoveLilyMotel_1F_Movement_27259E: @ 827259E
LilycoveCity_DepartmentStore_1F_Movement_27259E: @ 827259E
LilycoveCity_DepartmentStore_5F_Movement_27259E: @ 827259E
LilycoveCity_Harbor_Movement_27259E: @ 827259E
LilycoveCity_LilycoveMuseum_1F_Movement_27259E: @ 827259E
LilycoveCity_LilycoveMuseum_2F_Movement_27259E: @ 827259E
LilycoveCity_MoveDeletersHouse_Movement_27259E: @ 827259E
LilycoveCity_Movement_27259E: @ 827259E
LittlerootTown_BrendansHouse_1F_Movement_27259E: @ 827259E
LittlerootTown_BrendansHouse_2F_Movement_27259E: @ 827259E
MagmaHideout_4F_Movement_27259E: @ 827259E
MauvilleCity_Movement_27259E: @ 827259E
MeteorFalls_StevensCave_Movement_27259E: @ 827259E
MossdeepCity_SpaceCenter_2F_Movement_27259E: @ 827259E
MtChimney_Movement_27259E: @ 827259E
OldaleTown_Movement_27259E: @ 827259E
PetalburgCity_Gym_Movement_27259E: @ 827259E
PetalburgCity_Movement_27259E: @ 827259E
Route103_Movement_27259E: @ 827259E
Route104_Movement_27259E: @ 827259E
Route110_TrickHouseEnd_Movement_27259E: @ 827259E
Route110_TrickHouseEntrance_Movement_27259E: @ 827259E
Route110_TrickHousePuzzle5_Movement_27259E: @ 827259E
Route111_Movement_27259E: @ 827259E
Route119_Movement_27259E: @ 827259E
RustboroCity_Flat1_2F_Movement_27259E: @ 827259E
RustboroCity_Movement_27259E: @ 827259E
RusturfTunnel_Movement_27259E: @ 827259E
SeafloorCavern_Room9_Movement_27259E: @ 827259E
SlateportCity_Movement_27259E: @ 827259E
SlateportCity_SternsShipyard_1F_Movement_27259E: @ 827259E
SootopolisCity_Movement_27259E: @ 827259E
	step_3e
	step_end

BattleFrontier_OutsideWest_Movement_2725A0: @ 82725A0
	step_3f
	step_end

BattleFrontier_Lounge3_Movement_2725A2: @ 82725A2
BattleFrontier_OutsideWest_Movement_2725A2: @ 82725A2
EverGrandeCity_PokemonLeague_1F_Movement_2725A2: @ 82725A2
JaggedPass_Movement_2725A2: @ 82725A2
LilycoveCity_ContestHall_Movement_2725A2: @ 82725A2
LilycoveCity_ContestLobby_Movement_2725A2: @ 82725A2
LilycoveCity_CoveLilyMotel_1F_Movement_2725A2: @ 82725A2
LilycoveCity_House3_Movement_2725A2: @ 82725A2
LilycoveCity_LilycoveMuseum_1F_Movement_2725A2: @ 82725A2
LilycoveCity_Movement_2725A2: @ 82725A2
LittlerootTown_Movement_2725A2: @ 82725A2
MauvilleCity_GameCorner_Movement_2725A2: @ 82725A2
MauvilleCity_Movement_2725A2: @ 82725A2
MossdeepCity_Movement_2725A2: @ 82725A2
MossdeepCity_SpaceCenter_1F_Movement_2725A2: @ 82725A2
MossdeepCity_SpaceCenter_2F_Movement_2725A2: @ 82725A2
MtChimney_Movement_2725A2: @ 82725A2
OldaleTown_Movement_2725A2: @ 82725A2
PetalburgCity_Movement_2725A2: @ 82725A2
Route109_Movement_2725A2: @ 82725A2
Route110_Movement_2725A2: @ 82725A2
Route111_Movement_2725A2: @ 82725A2
Route111_WinstrateFamilysHouse_Movement_2725A2: @ 82725A2
Route112_Movement_2725A2: @ 82725A2
Route119_Movement_2725A2: @ 82725A2
RustboroCity_DevonCorp_3F_Movement_2725A2: @ 82725A2
RustboroCity_Movement_2725A2: @ 82725A2
RusturfTunnel_Movement_2725A2: @ 82725A2
SlateportCity_Harbor_Movement_2725A2: @ 82725A2
SlateportCity_Movement_2725A2: @ 82725A2
SlateportCity_OceanicMuseum_2F_Movement_2725A2: @ 82725A2
SlateportCity_SternsShipyard_1F_Movement_2725A2: @ 82725A2
SootopolisCity_Movement_2725A2: @ 82725A2
VerdanturfTown_Movement_2725A2: @ 82725A2
	step_4e
	step_end

AquaHideout_B2F_Movement_2725A4: @ 82725A4
BattleFrontier_BattleFactoryBattleRoom_Movement_2725A4: @ 82725A4
BattleFrontier_OutsideWest_Movement_2725A4: @ 82725A4
BattleFrontier_ScottsHouse_Movement_2725A4: @ 82725A4
DewfordTown_Hall_Movement_2725A4: @ 82725A4
EverGrandeCity_ChampionsRoom_Movement_2725A4: @ 82725A4
EverGrandeCity_HallOfFame_Movement_2725A4: @ 82725A4
LavaridgeTown_Movement_2725A4: @ 82725A4
LilycoveCity_Harbor_Movement_2725A4: @ 82725A4
LilycoveCity_PokemonTrainerFanClub_Movement_2725A4: @ 82725A4
LittlerootTown_BrendansHouse_1F_Movement_2725A4: @ 82725A4
LittlerootTown_BrendansHouse_2F_Movement_2725A4: @ 82725A4
LittlerootTown_MaysHouse_1F_Movement_2725A4: @ 82725A4
LittlerootTown_MaysHouse_2F_Movement_2725A4: @ 82725A4
LittlerootTown_Movement_2725A4: @ 82725A4
LittlerootTown_ProfessorBirchsLab_Movement_2725A4: @ 82725A4
MeteorFalls_1F_1R_Movement_2725A4: @ 82725A4
MossdeepCity_SpaceCenter_2F_Movement_2725A4: @ 82725A4
MossdeepCity_StevensHouse_Movement_2725A4: @ 82725A4
MtChimney_Movement_2725A4: @ 82725A4
MtPyre_Summit_Movement_2725A4: @ 82725A4
OldaleTown_PokemonCenter_1F_Movement_2725A4: @ 82725A4
PetalburgCity_Gym_Movement_2725A4: @ 82725A4
PetalburgCity_Movement_2725A4: @ 82725A4
PetalburgWoods_Movement_2725A4: @ 82725A4
Route101_Movement_2725A4: @ 82725A4
Route110_Movement_2725A4: @ 82725A4
Route110_TrickHouseEnd_Movement_2725A4: @ 82725A4
Route111_Movement_2725A4: @ 82725A4
Route112_Movement_2725A4: @ 82725A4
Route116_Movement_2725A4: @ 82725A4
Route120_Movement_2725A4: @ 82725A4
Route128_Movement_2725A4: @ 82725A4
RustboroCity_Movement_2725A4: @ 82725A4
SeafloorCavern_Entrance_Movement_2725A4: @ 82725A4
SeafloorCavern_Room9_Movement_2725A4: @ 82725A4
SkyPillar_Outside_Movement_2725A4: @ 82725A4
SlateportCity_Movement_2725A4: @ 82725A4
SlateportCity_OceanicMuseum_1F_Movement_2725A4: @ 82725A4
SlateportCity_OceanicMuseum_2F_Movement_2725A4: @ 82725A4
SootopolisCity_Movement_2725A4: @ 82725A4
	step_27
	step_end

BattleFrontier_BattleTowerCorridor2_Movement_2725A6: @ 82725A6
BattleFrontier_BattleTowerMultiBattleRoom_Movement_2725A6: @ 82725A6
BattleFrontier_OutsideWest_Movement_2725A6: @ 82725A6
BattleFrontier_ReceptionGate_Movement_2725A6: @ 82725A6
BattleFrontier_ScottsHouse_Movement_2725A6: @ 82725A6
CaveOfOrigin_B1F_Movement_2725A6: @ 82725A6
DewfordTown_Hall_Movement_2725A6: @ 82725A6
EverGrandeCity_ChampionsRoom_Movement_2725A6: @ 82725A6
EverGrandeCity_HallOfFame_Movement_2725A6: @ 82725A6
LavaridgeTown_Movement_2725A6: @ 82725A6
LilycoveCity_DepartmentStore_5F_Movement_2725A6: @ 82725A6
LilycoveCity_Harbor_Movement_2725A6: @ 82725A6
LittlerootTown_BrendansHouse_1F_Movement_2725A6: @ 82725A6
LittlerootTown_BrendansHouse_2F_Movement_2725A6: @ 82725A6
LittlerootTown_MaysHouse_2F_Movement_2725A6: @ 82725A6
LittlerootTown_Movement_2725A6: @ 82725A6
LittlerootTown_ProfessorBirchsLab_Movement_2725A6: @ 82725A6
MagmaHideout_4F_Movement_2725A6: @ 82725A6
MeteorFalls_1F_1R_Movement_2725A6: @ 82725A6
MossdeepCity_SpaceCenter_2F_Movement_2725A6: @ 82725A6
MtPyre_Summit_Movement_2725A6: @ 82725A6
NewMauville_Entrance_Movement_2725A6: @ 82725A6
OldaleTown_PokemonCenter_2F_Movement_2725A6: @ 82725A6
PetalburgCity_Gym_Movement_2725A6: @ 82725A6
PetalburgCity_Movement_2725A6: @ 82725A6
PetalburgWoods_Movement_2725A6: @ 82725A6
Route104_Movement_2725A6: @ 82725A6
Route110_TrickHouseEnd_Movement_2725A6: @ 82725A6
Route110_TrickHouseEntrance_Movement_2725A6: @ 82725A6
Route111_Movement_2725A6: @ 82725A6
Route114_FossilManiacsTunnel_Movement_2725A6: @ 82725A6
Route120_Movement_2725A6: @ 82725A6
Route121_SafariZoneEntrance_Movement_2725A6: @ 82725A6
Route128_Movement_2725A6: @ 82725A6
RustboroCity_Movement_2725A6: @ 82725A6
RusturfTunnel_Movement_2725A6: @ 82725A6
SeafloorCavern_Entrance_Movement_2725A6: @ 82725A6
SeafloorCavern_Room9_Movement_2725A6: @ 82725A6
SlateportCity_BattleTentCorridor_Movement_2725A6: @ 82725A6
SlateportCity_Harbor_Movement_2725A6: @ 82725A6
SlateportCity_Movement_2725A6: @ 82725A6
SlateportCity_OceanicMuseum_2F_Movement_2725A6: @ 82725A6
SootopolisCity_MysteryEventsHouse_1F_Movement_2725A6: @ 82725A6
VerdanturfTown_BattleTentBattleRoom_Movement_2725A6: @ 82725A6
	step_26
	step_end

BattleFrontier_BattleFactoryBattleRoom_Movement_2725A8: @ 82725A8
BattleFrontier_BattlePalaceBattleRoom_Movement_2725A8: @ 82725A8
BattleFrontier_OutsideWest_Movement_2725A8: @ 82725A8
BattleFrontier_ScottsHouse_Movement_2725A8: @ 82725A8
DewfordTown_Hall_Movement_2725A8: @ 82725A8
EverGrandeCity_ChampionsRoom_Movement_2725A8: @ 82725A8
EverGrandeCity_HallOfFame_Movement_2725A8: @ 82725A8
LavaridgeTown_Movement_2725A8: @ 82725A8
LilycoveCity_DepartmentStore_1F_Movement_2725A8: @ 82725A8
LilycoveCity_PokemonTrainerFanClub_Movement_2725A8: @ 82725A8
LittlerootTown_BrendansHouse_1F_Movement_2725A8: @ 82725A8
LittlerootTown_BrendansHouse_2F_Movement_2725A8: @ 82725A8
LittlerootTown_MaysHouse_1F_Movement_2725A8: @ 82725A8
LittlerootTown_Movement_2725A8: @ 82725A8
LittlerootTown_ProfessorBirchsLab_Movement_2725A8: @ 82725A8
MagmaHideout_4F_Movement_2725A8: @ 82725A8
MauvilleCity_Movement_2725A8: @ 82725A8
MossdeepCity_SpaceCenter_1F_Movement_2725A8: @ 82725A8
MossdeepCity_SpaceCenter_2F_Movement_2725A8: @ 82725A8
MtPyre_Summit_Movement_2725A8: @ 82725A8
OldaleTown_Movement_2725A8: @ 82725A8
PetalburgCity_Gym_Movement_2725A8: @ 82725A8
PetalburgCity_Movement_2725A8: @ 82725A8
Route101_Movement_2725A8: @ 82725A8
Route110_Movement_2725A8: @ 82725A8
Route110_TrickHouseEnd_Movement_2725A8: @ 82725A8
Route112_Movement_2725A8: @ 82725A8
Route116_Movement_2725A8: @ 82725A8
Route120_Movement_2725A8: @ 82725A8
Route128_Movement_2725A8: @ 82725A8
RustboroCity_Movement_2725A8: @ 82725A8
SSTidalCorridor_Movement_2725A8: @ 82725A8
SeafloorCavern_Entrance_Movement_2725A8: @ 82725A8
SkyPillar_Outside_Movement_2725A8: @ 82725A8
SlateportCity_Harbor_Movement_2725A8: @ 82725A8
SlateportCity_Movement_2725A8: @ 82725A8
SlateportCity_OceanicMuseum_1F_Movement_2725A8: @ 82725A8
SlateportCity_OceanicMuseum_2F_Movement_2725A8: @ 82725A8
SootopolisCity_Movement_2725A8: @ 82725A8
VerdanturfTown_BattleTentBattleRoom_Movement_2725A8: @ 82725A8
	step_28
	step_end

BattleFrontier_OutsideWest_Movement_2725AA: @ 82725AA
BattleFrontier_ScottsHouse_Movement_2725AA: @ 82725AA
BirthIsland_Harbor_Movement_2725AA: @ 82725AA
DewfordTown_Hall_Movement_2725AA: @ 82725AA
EverGrandeCity_ChampionsRoom_Movement_2725AA: @ 82725AA
FarawayIsland_Entrance_Movement_2725AA: @ 82725AA
LilycoveCity_CoveLilyMotel_1F_Movement_2725AA: @ 82725AA
LilycoveCity_DepartmentStoreElevator_Movement_2725AA: @ 82725AA
LilycoveCity_Harbor_Movement_2725AA: @ 82725AA
LilycoveCity_Movement_2725AA: @ 82725AA
LilycoveCity_PokemonTrainerFanClub_Movement_2725AA: @ 82725AA
LittlerootTown_BrendansHouse_1F_Movement_2725AA: @ 82725AA
LittlerootTown_MaysHouse_1F_Movement_2725AA: @ 82725AA
LittlerootTown_Movement_2725AA: @ 82725AA
MauvilleCity_Movement_2725AA: @ 82725AA
MeteorFalls_1F_1R_Movement_2725AA: @ 82725AA
MossdeepCity_SpaceCenter_2F_Movement_2725AA: @ 82725AA
MtPyre_Summit_Movement_2725AA: @ 82725AA
NavelRock_Harbor_Movement_2725AA: @ 82725AA
OldaleTown_PokemonCenter_1F_Movement_2725AA: @ 82725AA
PetalburgCity_Gym_Movement_2725AA: @ 82725AA
PetalburgCity_Movement_2725AA: @ 82725AA
PetalburgWoods_Movement_2725AA: @ 82725AA
Route110_Movement_2725AA: @ 82725AA
Route110_TrickHouseEnd_Movement_2725AA: @ 82725AA
Route114_FossilManiacsTunnel_Movement_2725AA: @ 82725AA
Route119_Movement_2725AA: @ 82725AA
Route120_Movement_2725AA: @ 82725AA
Route128_Movement_2725AA: @ 82725AA
RustboroCity_Movement_2725AA: @ 82725AA
RustboroCity_PokemonSchool_Movement_2725AA: @ 82725AA
RusturfTunnel_Movement_2725AA: @ 82725AA
SeafloorCavern_Entrance_Movement_2725AA: @ 82725AA
SeafloorCavern_Room9_Movement_2725AA: @ 82725AA
SkyPillar_Outside_Movement_2725AA: @ 82725AA
SlateportCity_Harbor_Movement_2725AA: @ 82725AA
SlateportCity_Movement_2725AA: @ 82725AA
SlateportCity_OceanicMuseum_2F_Movement_2725AA: @ 82725AA
SouthernIsland_Exterior_Movement_2725AA: @ 82725AA
VerdanturfTown_BattleTentBattleRoom_Movement_2725AA: @ 82725AA
VictoryRoad_1F_Movement_2725AA: @ 82725AA
	step_25
	step_end

RustboroCity_Movement_2725AC: @ 82725AC
	step_03
	step_end

RustboroCity_Movement_2725AE: @ 82725AE
	step_02
	step_end

BattleFrontier_Mart_Movement_2725B0: @ 82725B0
MeteorFalls_1F_1R_Movement_2725B0: @ 82725B0
	step_00
	step_end

MarineCave_End_Movement_2725B2: @ 82725B2
MtPyre_Summit_Movement_2725B2: @ 82725B2
Route118_Movement_2725B2: @ 82725B2
SkyPillar_Top_Movement_2725B2: @ 82725B2
SlateportCity_Movement_2725B2: @ 82725B2
TerraCave_End_Movement_2725B2: @ 82725B2
	step_01
	step_end

BattleFrontier_BattleDomeBattleRoom_Movement_2725B4: @ 82725B4
MeteorFalls_1F_1R_Movement_2725B4: @ 82725B4
	step_1d
	step_end

BattleFrontier_BattlePalaceBattleRoom_Movement_2725B6: @ 82725B6
BattleFrontier_BattleTowerBattleRoom_Movement_2725B6: @ 82725B6
	step_1f
	step_end

Route121_Movement_2725B8: @ 82725B8
	step_20
	step_end

EverGrandeCity_SidneysRoom_Movement_2725BA: @ 82725BA
	step_up
	step_up
	step_up
	step_up
	step_up
	step_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_2725C1: @ 82725C1
	step_up
	step_up
	step_up
	step_up
	step_end

EverGrandeCity_SidneysRoom_Movement_2725C6: @ 82725C6
	step_14
	step_14
	step_end

Route110_TrickHouseEntrance_Movement_2725C9: @ 82725C9
	step_up
	step_end

Movement_2725CB:: @ 82725CB
	step_up
	step_up
	step_end

EventScript_2725CE:: @ 82725CE
	msgbox Text_2A81E5, 3
	end

EventScript_2725D7:: @ 82725D7
	msgbox Text_2A820D, 3
	end

EventScript_2725E0:: @ 82725E0
	msgbox Text_2A8232, 3
	end

EventScript_2725E9:: @ 82725E9
	msgbox Text_2A8276, 3
	end

EventScript_2725F2:: @ 82725F2
	msgbox Text_2A82B3, 3
	end

EventScript_2725FB:: @ 82725FB
	msgbox Text_2A82BF, 3
	end

EventScript_272604:: @ 8272604
	msgbox Text_2A82F7, 3
	end

Text_27260D: @ 827260D
	.string "Would you like to mix records with\n"
	.string "other TRAINERS?$"

Text_272640: @ 8272640
	.string "We hope to see you again!$"

Text_27265A: @ 827265A
	.string "{PLAYER} booted up the PC.$"

gUnknown_0827266F:: @ 827266F
	.string "Which PC should be accessed?$"

gUnknown_0827268C:: @ 827268C
	.string "Accessed SOMEONE’S PC.$"

gUnknown_082726A3:: @ 82726A3
	.string "POKéMON Storage System opened.$"

gUnknown_082726C2:: @ 82726C2
	.string "Accessed {PLAYER}’s PC.$"

gUnknown_082726D4:: @ 82726D4
	.string "Accessed LANETTE’s PC.$"

gUnknown_082726EB:: @ 82726EB
	.string "Hello, and welcome to\nthe POKéMON CENTER.\pWe restore your tired POKéMON\nto full health.\pWould you like to rest your POKéMON?$"

gUnknown_08272768:: @ 8272768
	.string "Okay, I’ll take your POKéMON\nfor a few seconds.$"

gUnknown_08272798:: @ 8272798
	.string "Thank you for waiting.\pWe’ve restored your POKéMON\nto full health.$"

gUnknown_082727DB:: @ 82727DB
	.string "We hope to see you again!$"

gUnknown_082727F5:: @ 82727F5
	.string "Hello, and welcome to\nthe POKéMON CENTER.\pWe restore your tired POKéMON\nto full health.\pWould you like to…$"

gUnknown_08272860:: @ 8272860
	.string "Th-that card…\nCould it be… The GOLD CARD?!\pOh, the gold color is brilliant!\nThe four stars seem to sparkle!\pI’ve seen several TRAINERS with\na SILVER CARD before, but, {PLAYER},\lyou’re the first TRAINER I’ve ever\lseen with a GOLD CARD!\pOkay, {PLAYER}, please allow me\nthe honor of resting your POKéMON!$"

gUnknown_08272982:: @ 8272982
	.string "I’m delighted to see you, {PLAYER}!\nYou want the usual, am I right?$"

gUnknown_082729C0:: @ 82729C0
	.string "Okay, I’ll take your POKéMON\nfor a few seconds.$"

gUnknown_082729F0:: @ 82729F0
	.string "Thank you for waiting.$"

gUnknown_08272A07:: @ 8272A07
	.string "We hope to see you again!$"

gUnknown_08272A21:: @ 8272A21
	.string "Welcome!\pHow may I serve you?$"

gUnknown_08272A3F:: @ 8272A3F
	.string "Please come again!$"

gUnknown_08272A52:: @ 8272A52
	.string "{PLAYER}{STRING 5}, welcome!\pWhat can I do for you?$"

gUnknown_08272A78:: @ 8272A78
	.string "Obtained the {STR_VAR_2}!$"

gUnknown_08272A89:: @ 8272A89
	.string "The BAG is full…$"

gUnknown_08272A9A:: @ 8272A9A
	.string "{PLAYER} put away the {STR_VAR_2}\nin the {STR_VAR_3} POCKET.$"

gUnknown_08272ABF:: @ 8272ABF
	.string "{PLAYER} found one {STR_VAR_2}!$"

gUnknown_08272AD0:: @ 8272AD0
	.string "Too bad!\nThe BAG is full…$"

gUnknown_08272AEA:: @ 8272AEA
	.string "{PLAYER} put away the {STR_VAR_2}\nin the BAG.$"

gUnknown_08272B09:: @ 8272B09
	.string "Obtained the {STR_VAR_2}!$"

gUnknown_08272B1A:: @ 8272B1A
	.string "Too bad! There’s no room left for\nanother {STR_VAR_2}…$"

gUnknown_08272B48:: @ 8272B48
	.string "The {STR_VAR_2} was transferred\nto the PC.$"

gUnknown_08272B6A:: @ 8272B6A
	.string "“Selected items for your convenience!”\nPOKéMON MART$"

gUnknown_08272B9E:: @ 8272B9E
	.string "“Rejuvenate your tired partners!”\nPOKéMON CENTER$"

gUnknown_08272BCF:: @ 8272BCF
	.string "{STR_VAR_1} might like this program.\n… … … … … … … … … … … … … … … …\pBetter get going!$"

gUnknown_08272C1D:: @ 8272C1D
	.string "Welcome to LILYCOVE DEPARTMENT STORE.\pWhich floor would you like?$"

gUnknown_08272C5F:: @ 8272C5F
	.string "The sandstorm is vicious.\nIt’s impossible to keep going.$"

gUnknown_08272C98:: @ 8272C98
	.string "An item in the BAG can be\nregistered to SELECT for easy use.$"

gUnknown_08272CD5:: @ 8272CD5
	.string "There’s an e-mail from POKéMON TRAINER\nSCHOOL.\p… … … … … …\pA POKéMON may learn up to four moves.\pA TRAINER’s expertise is tested on the\nmove sets chosen for POKéMON.\p… … … … … …$"

gUnknown_08272D87:: @ 8272D87
	.string "{PLAYER} booted up the PC.$"

gUnknown_08272D9C:: @ 8272D9C
	.string "The link was canceled.$"

gUnknown_08272DB3:: @ 8272DB3
	.string "Want to give a nickname to\nthe {STR_VAR_2} you received?$"

gUnknown_08272DE3:: @ 8272DE3
	.string "{PLAYER} is out of usable\nPOKéMON!\p{PLAYER} whited out!$"

gUnknown_08272E0F:: @ 8272E0F
	.string "Registered {STR_VAR_1} {STR_VAR_2}\nin the POKéNAV.$"

gUnknown_08272E30:: @ 8272E30
	.string "Do you know the TM SECRET POWER?\pOur group, we love the TM SECRET\nPOWER.\pOne of our members will give it to you.\nCome back and show me if you get it.\pWe’ll accept you as a member and sell\nyou good stuff in secrecy.$"

gUnknown_08272F07:: @ 8272F07
	.string "Your POKéMON may be infected with\nPOKéRUS.\pLittle is known about the POKéRUS\nexcept that they are microscopic life-\lforms that attach to POKéMON.\pWhile infected, POKéMON are said to\ngrow exceptionally well.$"

	.include "data/text/surf.inc"

gUnknown_0827301B:: @ 827301B
	.string "It sounded as if a door opened\nsomewhere far away.$"

gUnknown_0827304E:: @ 827304E
	.string "There is a big hole in the wall.$"

gUnknown_0827306F:: @ 827306F
	.string "I’m terribly sorry.\nThe POKéMON WIRELESS CLUB is\lundergoing adjustments now.$"

gUnknown_082730BC:: @ 82730BC
	.string "It appears to be undergoing\nadjustments…$"

gUnknown_082730E5:: @ 82730E5
	.string "I’m terribly sorry. The TRADE CENTER\nis undergoing inspections.$"

gUnknown_08273125:: @ 8273125
	.string "I’m terribly sorry. The RECORD CORNER\nis under preparation.$"

gUnknown_08273161:: @ 8273161
	.string "{PLAYER} handed over the\n{STR_VAR_1}.$"

gUnknown_08273178:: @ 8273178
	.string "Thank you for accessing the\nMYSTERY GIFT System.$"

gUnknown_082731A9:: @ 82731A9
	.string "{PLAYER} found one {STR_VAR_1}\n{STR_VAR_2}!$"

gUnknown_082731BD:: @ 82731BD
	.string "The weird tree doesn’t like the\nWAILMER PAIL!\pThe weird tree attacked!$"

gUnknown_08273204:: @ 8273204
	.string "The {STR_VAR_1} flew away!$"

gText_PkmnTransferredSomeonesPC:: @ 8273216
	.string "{STR_VAR_2} was transferred to\nSOMEONE’S PC.\pIt was placed in \nBOX “{STR_VAR_1}.”$"

gText_PkmnTransferredLanettesPC:: @ 8273256
	.string "{STR_VAR_2} was transferred to\nLANETTE’S PC.\pIt was placed in \nBOX “{STR_VAR_1}.”$"

gText_PkmnBoxSomeonesPCFull:: @ 8273296
	.string "BOX “{STR_VAR_3}” on\nSOMEONE’S PC was full.\p{STR_VAR_2} was transferred to\nBOX “{STR_VAR_1}.”$"

gText_PkmnBoxLanettesPCFull:: @ 82732D9
	.string "BOX “{STR_VAR_3}” on\nLANETTE’S PC was full.\p{STR_VAR_2} was transferred to\nBOX “{STR_VAR_1}.”$"

gUnknown_0827331C:: @ 827331C
	.string "There’s no more room for POKéMON!\pThe POKéMON BOXES are full and\ncan’t accept any more!$"

gUnknown_08273374:: @ 8273374
	.string "Do you want to give a nickname to\nthis {STR_VAR_1}?$"

gUnknown_0827339F:: @ 827339F
	.string "There is a questionnaire.\nWould you like to fill it out?$"

gUnknown_082733D8:: @ 82733D8
	.string "Thank you for taking the time to\nfill out our questionnaire.\pYour feedback will be used for\nfuture reference.$"

gUnknown_08273446:: @ 8273446
	.string "Oh, hello!\nYou know those words?\pThat means you must know about\nthe MYSTERY GIFT.\pFrom now on, you should be\nreceiving MYSTERY GIFTS!$"

gUnknown_082734CC:: @ 82734CC
	.string "Once you save your game, you can\naccess the MYSTERY GIFT.$"

gUnknown_08273506:: @ 8273506
	.string "Oh, hello!\nYou know those words?\pThat means you must know about\nthe MYSTERY EVENT.$"

gUnknown_08273559:: @ 8273559
	.string "Once you save your game, you can\naccess the MYSTERY EVENT.$"

gUnknown_08273594:: @ 8273594
	.string "Thank you for using the MYSTERY\nEVENT System.\pYou must be {PLAYER}.\nThere is a ticket here for you.$"

gUnknown_082735F2:: @ 82735F2
	.string "It appears to be for use at\nthe LILYCOVE CITY port.\pWhy not give it a try and see what\nit is about?$"

gUnknown_08273656:: @ 8273656
	.string "The massive downpour appears to\nhave stopped…$"

gUnknown_08273684:: @ 8273684
	.string "The intense sunshine appears to\nhave subsided…$"

EventScript_2736B3:: @ 82736B3
	msgbox gUnknown_08272C98, 3
	end

EventScript_2736BC:: @ 82736BC
	lockall
	special sub_80F972C
	waitstate
	compare VAR_RESULT, 1
	goto_eq EventScript_2736D9
	compare VAR_RESULT, 2
	goto_eq EventScript_2736F8
	releaseall
	end

EventScript_2736D9:: @ 82736D9
	message gUnknown_08272DE3
	waitmessage
	waitbuttonpress
	special sub_80B05B4
	waitstate
	fadescreen 1
	checkflag FLAG_0x06C
	call_if 1, EventScript_2736F4
	special sp0C8_whiteout_maybe
	waitstate
	end

EventScript_2736F4:: @ 82736F4
	setrespawn 16
	return

EventScript_2736F8:: @ 82736F8
	message gUnknown_08272DE3
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 16
	special sub_81A703C
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4222
	setvar VAR_0x8004, 12
	special sub_81A8E7C
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePyramidTop_EventScript_252B42
	compare VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePyramidTop_EventScript_252B42
	setvar VAR_0x8004, 10
	special sp194_trainer_tower
	compare VAR_RESULT, 1
	goto_eq TrainerHill_1F_EventScript_2C83C9
	special sub_80B05B4
	waitstate
	fadescreen 1
	special sp0C8_whiteout_maybe
	waitstate
	end

AncientTomb_EventScript_27374E:: @ 827374E
AquaHideout_B1F_EventScript_27374E:: @ 827374E
BattleFrontier_BattleDomeBattleRoom_EventScript_27374E:: @ 827374E
BattleFrontier_OutsideEast_EventScript_27374E:: @ 827374E
BirthIsland_Exterior_EventScript_27374E:: @ 827374E
DesertRuins_EventScript_27374E:: @ 827374E
EverGrandeCity_PokemonCenter_1F_EventScript_27374E:: @ 827374E
FarawayIsland_Interior_EventScript_27374E:: @ 827374E
IslandCave_EventScript_27374E:: @ 827374E
LilycoveCity_Harbor_EventScript_27374E:: @ 827374E
MarineCave_End_EventScript_27374E:: @ 827374E
NavelRock_Bottom_EventScript_27374E:: @ 827374E
NavelRock_Top_EventScript_27374E:: @ 827374E
NewMauville_Inside_EventScript_27374E:: @ 827374E
OldaleTown_PokemonCenter_1F_EventScript_27374E:: @ 827374E
PacifidlogTown_House2_EventScript_27374E:: @ 827374E
Route101_EventScript_27374E:: @ 827374E
Route119_EventScript_27374E:: @ 827374E
Route120_EventScript_27374E:: @ 827374E
SkyPillar_Top_EventScript_27374E:: @ 827374E
SouthernIsland_Interior_EventScript_27374E:: @ 827374E
TerraCave_End_EventScript_27374E:: @ 827374E
	return

EventScript_27374F:: @ 827374F
	setvar VAR_RESULT, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_273755:: @ 8273755
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

AncientTomb_EventScript_27376D:: @ 827376D
AquaHideout_B1F_EventScript_27376D:: @ 827376D
DesertRuins_EventScript_27376D:: @ 827376D
IslandCave_EventScript_27376D:: @ 827376D
MarineCave_End_EventScript_27376D:: @ 827376D
NewMauville_Inside_EventScript_27376D:: @ 827376D
Route119_EventScript_27376D:: @ 827376D
TerraCave_End_EventScript_27376D:: @ 827376D
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	release
	end

AncientTomb_EventScript_273776:: @ 8273776
BirthIsland_Exterior_EventScript_273776:: @ 8273776
DesertRuins_EventScript_273776:: @ 8273776
FarawayIsland_Interior_EventScript_273776:: @ 8273776
IslandCave_EventScript_273776:: @ 8273776
MarineCave_End_EventScript_273776:: @ 8273776
NavelRock_Bottom_EventScript_273776:: @ 8273776
NavelRock_Top_EventScript_273776:: @ 8273776
SouthernIsland_Interior_EventScript_273776:: @ 8273776
TerraCave_End_EventScript_273776:: @ 8273776
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	bufferspeciesname 0, VAR_0x8004
	msgbox gUnknown_08273204, 4
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_27378B:: @ 827378B
MossdeepCity_StevensHouse_EventScript_27378B:: @ 827378B
Route119_WeatherInstitute_2F_EventScript_27378B:: @ 827378B
RustboroCity_DevonCorp_2F_EventScript_27378B:: @ 827378B
	getpartysize
	subvar VAR_RESULT, 1
	copyvar VAR_0x8004, VAR_RESULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_273797:: @ 8273797
MossdeepCity_StevensHouse_EventScript_273797:: @ 8273797
Route119_WeatherInstitute_2F_EventScript_273797:: @ 8273797
RustboroCity_DevonCorp_2F_EventScript_273797:: @ 8273797
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
	bufferboxname 0, 16438
	bufferspeciesname 1, VAR_0x4001
	checkflag FLAG_SYS_PC_LANETTE
	call_if 0, LittlerootTown_ProfessorBirchsLab_EventScript_2737BB
	checkflag FLAG_SYS_PC_LANETTE
	call_if 1, LittlerootTown_ProfessorBirchsLab_EventScript_2737E6
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737BB:: @ 82737BB
	specialvar VAR_RESULT, sub_813B21C
	compare VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_2737D4
	msgbox gText_PkmnTransferredSomeonesPC, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737D4:: @ 82737D4
	specialvar VAR_RESULT, get_unknown_box_id
	bufferboxname 2, 32781
	msgbox gText_PkmnBoxSomeonesPCFull, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737E6:: @ 82737E6
	specialvar VAR_RESULT, sub_813B21C
	compare VAR_RESULT, 1
	goto_eq LittlerootTown_ProfessorBirchsLab_EventScript_2737FF
	msgbox gText_PkmnTransferredLanettesPC, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_2737FF:: @ 82737FF
	specialvar VAR_RESULT, get_unknown_box_id
	bufferboxname 2, 32781
	msgbox gText_PkmnBoxLanettesPCFull, 4
	return

LittlerootTown_ProfessorBirchsLab_EventScript_273811:: @ 8273811
MossdeepCity_StevensHouse_EventScript_273811:: @ 8273811
Route119_WeatherInstitute_2F_EventScript_273811:: @ 8273811
RustboroCity_DevonCorp_2F_EventScript_273811:: @ 8273811
	msgbox gUnknown_0827331C, 4
	release
	end

EventScript_27381B:: @ 827381B
	lockall
	msgbox gUnknown_0827339F, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_2738FD
	setvar VAR_0x8004, 20
	call MauvilleCity_PokemonCenter_1F_EventScript_271E7C
	lock
	faceplayer
	specialvar VAR_0x8008, sub_813B490
	compare VAR_0x8004, 1
	goto_eq EventScript_27386D
	compare VAR_0x8004, 2
	goto_eq EventScript_2738B5
	compare VAR_RESULT, 0
	goto_eq EventScript_2738FD
	compare VAR_RESULT, 1
	goto_eq EventScript_2738FF
	end

EventScript_27386D:: @ 827386D
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if 0, EventScript_2738FF
	checkflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	goto_eq EventScript_2738FF
	applymovement VAR_0x8008, BattleFrontier_Mart_Movement_2725B0
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, BattleFrontier_ReceptionGate_Movement_272598
	waitmovement 0
	applymovement VAR_0x8008, BattleFrontier_ReceptionGate_Movement_27259A
	waitmovement 0
	msgbox gUnknown_08273506, 4
	setflag FLAG_SYS_MYSTERY_EVENT_ENABLE
	msgbox gUnknown_08273559, 4
	releaseall
	end

EventScript_2738B5:: @ 82738B5
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if 0, EventScript_2738FF
	checkflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	goto_eq EventScript_2738FF
	applymovement VAR_0x8008, BattleFrontier_Mart_Movement_2725B0
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8008, BattleFrontier_ReceptionGate_Movement_272598
	waitmovement 0
	applymovement VAR_0x8008, BattleFrontier_ReceptionGate_Movement_27259A
	waitmovement 0
	msgbox gUnknown_08273446, 4
	setflag FLAG_SYS_MYSTERY_GIFT_ENABLE
	msgbox gUnknown_082734CC, 4
	releaseall
	end

EventScript_2738FD:: @ 82738FD
	releaseall
	end

EventScript_2738FF:: @ 82738FF
	applymovement VAR_0x8008, BattleFrontier_Mart_Movement_2725B0
	waitmovement 0
	msgbox gUnknown_082733D8, 4
	releaseall
	end

Route114_EventScript_273913:: @ 8273913
	setmetatile 7, 3, 839, 1
	setmetatile 7, 4, 847, 0
	return

Route114_EventScript_273926:: @ 8273926
	setmetatile 6, 45, 601, 1
	setmetatile 6, 46, 609, 0
	return

Route115_EventScript_273939:: @ 8273939
	setmetatile 21, 5, 601, 1
	setmetatile 21, 6, 609, 0
	return

Route115_EventScript_27394C:: @ 827394C
	setmetatile 36, 9, 601, 1
	setmetatile 36, 10, 609, 0
	return

Route116_EventScript_27395F:: @ 827395F
	setmetatile 59, 12, 159, 1
	setmetatile 59, 13, 167, 0
	return

Route116_EventScript_273972:: @ 8273972
	setmetatile 79, 5, 159, 1
	setmetatile 79, 6, 167, 0
	return

Route118_EventScript_273985:: @ 8273985
	setmetatile 42, 5, 159, 1
	setmetatile 42, 6, 167, 0
	return

Route118_EventScript_273998:: @ 8273998
	setmetatile 9, 5, 159, 1
	setmetatile 9, 6, 167, 0
	return

Route105_EventScript_2739AB:: @ 82739AB
	setmetatile 10, 28, 334, 0
	setmetatile 11, 28, 334, 0
	setmetatile 9, 29, 334, 0
	setmetatile 10, 29, 335, 0
	setmetatile 11, 29, 335, 0
	setmetatile 12, 29, 334, 0
	setmetatile 9, 30, 334, 0
	setmetatile 10, 30, 335, 0
	setmetatile 11, 30, 335, 0
	setmetatile 12, 30, 334, 0
	setmetatile 10, 31, 334, 0
	setmetatile 11, 31, 334, 0
	return

Route105_EventScript_273A18:: @ 8273A18
	setmetatile 20, 53, 334, 0
	setmetatile 21, 53, 334, 0
	setmetatile 19, 54, 334, 0
	setmetatile 20, 54, 335, 0
	setmetatile 21, 54, 335, 0
	setmetatile 22, 54, 334, 0
	setmetatile 19, 55, 334, 0
	setmetatile 20, 55, 335, 0
	setmetatile 21, 55, 335, 0
	setmetatile 22, 55, 334, 0
	setmetatile 20, 56, 334, 0
	setmetatile 21, 56, 334, 0
	return

Route125_EventScript_273A85:: @ 8273A85
	setmetatile 8, 16, 334, 0
	setmetatile 9, 16, 334, 0
	setmetatile 7, 17, 334, 0
	setmetatile 8, 17, 335, 0
	setmetatile 9, 17, 335, 0
	setmetatile 10, 17, 334, 0
	setmetatile 7, 18, 334, 0
	setmetatile 8, 18, 335, 0
	setmetatile 9, 18, 335, 0
	setmetatile 10, 18, 334, 0
	setmetatile 8, 19, 334, 0
	setmetatile 9, 19, 334, 0
	return

Route125_EventScript_273AF2:: @ 8273AF2
	setmetatile 53, 18, 334, 0
	setmetatile 54, 18, 334, 0
	setmetatile 52, 19, 334, 0
	setmetatile 53, 19, 335, 0
	setmetatile 54, 19, 335, 0
	setmetatile 55, 19, 334, 0
	setmetatile 52, 20, 334, 0
	setmetatile 53, 20, 335, 0
	setmetatile 54, 20, 335, 0
	setmetatile 55, 20, 334, 0
	setmetatile 53, 21, 334, 0
	setmetatile 54, 21, 334, 0
	return

Route127_EventScript_273B5F:: @ 8273B5F
	setmetatile 57, 9, 334, 0
	setmetatile 58, 9, 334, 0
	setmetatile 56, 10, 334, 0
	setmetatile 57, 10, 335, 0
	setmetatile 58, 10, 335, 0
	setmetatile 59, 10, 334, 0
	setmetatile 56, 11, 334, 0
	setmetatile 57, 11, 335, 0
	setmetatile 58, 11, 335, 0
	setmetatile 59, 11, 334, 0
	setmetatile 57, 12, 334, 0
	setmetatile 58, 12, 334, 0
	return

Route127_EventScript_273BCC:: @ 8273BCC
	setmetatile 61, 30, 334, 0
	setmetatile 62, 30, 334, 0
	setmetatile 60, 31, 334, 0
	setmetatile 61, 31, 335, 0
	setmetatile 62, 31, 335, 0
	setmetatile 63, 31, 334, 0
	setmetatile 60, 32, 334, 0
	setmetatile 61, 32, 335, 0
	setmetatile 62, 32, 335, 0
	setmetatile 63, 32, 334, 0
	setmetatile 61, 33, 334, 0
	setmetatile 62, 33, 334, 0
	return

Route129_EventScript_273C39:: @ 8273C39
	setmetatile 16, 14, 334, 0
	setmetatile 17, 14, 334, 0
	setmetatile 15, 15, 334, 0
	setmetatile 16, 15, 335, 0
	setmetatile 17, 15, 335, 0
	setmetatile 18, 15, 334, 0
	setmetatile 15, 16, 334, 0
	setmetatile 16, 16, 335, 0
	setmetatile 17, 16, 335, 0
	setmetatile 18, 16, 334, 0
	setmetatile 16, 17, 334, 0
	setmetatile 17, 17, 334, 0
	return

Route129_EventScript_273CA6:: @ 8273CA6
	setmetatile 42, 19, 334, 0
	setmetatile 43, 19, 334, 0
	setmetatile 41, 20, 334, 0
	setmetatile 42, 20, 335, 0
	setmetatile 43, 20, 335, 0
	setmetatile 44, 20, 334, 0
	setmetatile 41, 21, 334, 0
	setmetatile 42, 21, 335, 0
	setmetatile 43, 21, 335, 0
	setmetatile 44, 21, 334, 0
	setmetatile 42, 22, 334, 0
	setmetatile 43, 22, 334, 0
	return

Route105_EventScript_273D13:: @ 8273D13
Route114_EventScript_273D13:: @ 8273D13
Route115_EventScript_273D13:: @ 8273D13
Route116_EventScript_273D13:: @ 8273D13
Route118_EventScript_273D13:: @ 8273D13
Route125_EventScript_273D13:: @ 8273D13
Route127_EventScript_273D13:: @ 8273D13
Route129_EventScript_273D13:: @ 8273D13
	setflag FLAG_SPECIAL_FLAG_0x4000
	return

Route105_EventScript_273D17:: @ 8273D17
Route125_EventScript_273D17:: @ 8273D17
Route127_EventScript_273D17:: @ 8273D17
Route129_EventScript_273D17:: @ 8273D17
	setweather 13
	return

Route114_EventScript_273D1B:: @ 8273D1B
Route115_EventScript_273D1B:: @ 8273D1B
Route116_EventScript_273D1B:: @ 8273D1B
Route118_EventScript_273D1B:: @ 8273D1B
	setweather 12
	return

gUnknown_08273D1F:: @ 8273D1F

gUnknown_08273D1F:: @ 8273D1F
	lockall
	compare VAR_0x4037, 9
	goto_if 4, Route105_EventScript_273D51
	goto Route105_EventScript_273D5F
	end

Route105_EventScript_273D31:: @ 8273D31
	closemessage
	fadescreenswapbuffers 1
	setweather 2
	doweather
	call Route105_EventScript_273D6D
	special DrawWholeMapView
	setvar VAR_0x4037, 0
	setvar VAR_0x4039, 0
	clearflag FLAG_SPECIAL_FLAG_0x4000
	fadescreenswapbuffers 0
	releaseall
	end

Route105_EventScript_273D51:: @ 8273D51
	msgbox gUnknown_08273656, 4
	goto Route105_EventScript_273D31
	end

Route105_EventScript_273D5F:: @ 8273D5F
	msgbox gUnknown_08273684, 4
	goto Route105_EventScript_273D31
	end

Route105_EventScript_273D6D:: @ 8273D6D
	switch VAR_0x4037
	case 1, Route105_EventScript_273E23
	case 2, Route105_EventScript_273E36
	case 3, Route105_EventScript_273E49
	case 4, Route105_EventScript_273E5C
	case 5, Route105_EventScript_273E6F
	case 6, Route105_EventScript_273E82
	case 7, Route105_EventScript_273E95
	case 8, Route105_EventScript_273EA8
	case 9, Route105_EventScript_273EBB
	case 10, Route105_EventScript_273F28
	case 11, Route105_EventScript_273F95
	case 12, Route105_EventScript_274002
	case 13, Route105_EventScript_27406F
	case 14, Route105_EventScript_2740DC
	case 15, Route105_EventScript_274149
	case 16, Route105_EventScript_2741B6
	return

Route105_EventScript_273E23:: @ 8273E23
	setmetatile 7, 3, 617, 1
	setmetatile 7, 4, 617, 1
	return

Route105_EventScript_273E36:: @ 8273E36
	setmetatile 6, 45, 613, 1
	setmetatile 6, 46, 613, 1
	return

Route105_EventScript_273E49:: @ 8273E49
	setmetatile 21, 5, 613, 1
	setmetatile 21, 6, 613, 1
	return

Route105_EventScript_273E5C:: @ 8273E5C
	setmetatile 36, 9, 613, 1
	setmetatile 36, 10, 613, 1
	return

Route105_EventScript_273E6F:: @ 8273E6F
	setmetatile 59, 12, 124, 1
	setmetatile 59, 13, 124, 1
	return

Route105_EventScript_273E82:: @ 8273E82
	setmetatile 79, 5, 124, 1
	setmetatile 79, 6, 124, 1
	return

Route105_EventScript_273E95:: @ 8273E95
	setmetatile 42, 5, 124, 1
	setmetatile 42, 6, 121, 1
	return

Route105_EventScript_273EA8:: @ 8273EA8
	setmetatile 9, 5, 124, 1
	setmetatile 9, 6, 121, 1
	return

Route105_EventScript_273EBB:: @ 8273EBB
	setmetatile 10, 28, 368, 0
	setmetatile 11, 28, 368, 0
	setmetatile 9, 29, 368, 0
	setmetatile 10, 29, 368, 0
	setmetatile 11, 29, 368, 0
	setmetatile 12, 29, 368, 0
	setmetatile 9, 30, 368, 0
	setmetatile 10, 30, 368, 0
	setmetatile 11, 30, 368, 0
	setmetatile 12, 30, 368, 0
	setmetatile 10, 31, 368, 0
	setmetatile 11, 31, 368, 0
	return

Route105_EventScript_273F28:: @ 8273F28
	setmetatile 20, 53, 368, 0
	setmetatile 21, 53, 368, 0
	setmetatile 19, 54, 368, 0
	setmetatile 20, 54, 368, 0
	setmetatile 21, 54, 368, 0
	setmetatile 22, 54, 368, 0
	setmetatile 19, 55, 368, 0
	setmetatile 20, 55, 368, 0
	setmetatile 21, 55, 368, 0
	setmetatile 22, 55, 368, 0
	setmetatile 20, 56, 368, 0
	setmetatile 21, 56, 368, 0
	return

Route105_EventScript_273F95:: @ 8273F95
	setmetatile 8, 16, 368, 0
	setmetatile 9, 16, 368, 0
	setmetatile 7, 17, 368, 0
	setmetatile 8, 17, 368, 0
	setmetatile 9, 17, 368, 0
	setmetatile 10, 17, 368, 0
	setmetatile 7, 18, 368, 0
	setmetatile 8, 18, 368, 0
	setmetatile 9, 18, 368, 0
	setmetatile 10, 18, 368, 0
	setmetatile 8, 19, 368, 0
	setmetatile 9, 19, 368, 0
	return

Route105_EventScript_274002:: @ 8274002
	setmetatile 53, 18, 368, 0
	setmetatile 54, 18, 368, 0
	setmetatile 52, 19, 368, 0
	setmetatile 53, 19, 368, 0
	setmetatile 54, 19, 368, 0
	setmetatile 55, 19, 368, 0
	setmetatile 52, 20, 368, 0
	setmetatile 53, 20, 368, 0
	setmetatile 54, 20, 368, 0
	setmetatile 55, 20, 368, 0
	setmetatile 53, 21, 368, 0
	setmetatile 54, 21, 368, 0
	return

Route105_EventScript_27406F:: @ 827406F
	setmetatile 57, 9, 368, 0
	setmetatile 58, 9, 368, 0
	setmetatile 56, 10, 368, 0
	setmetatile 57, 10, 368, 0
	setmetatile 58, 10, 368, 0
	setmetatile 59, 10, 368, 0
	setmetatile 56, 11, 368, 0
	setmetatile 57, 11, 368, 0
	setmetatile 58, 11, 368, 0
	setmetatile 59, 11, 368, 0
	setmetatile 57, 12, 368, 0
	setmetatile 58, 12, 368, 0
	return

Route105_EventScript_2740DC:: @ 82740DC
	setmetatile 61, 30, 368, 0
	setmetatile 62, 30, 368, 0
	setmetatile 60, 31, 368, 0
	setmetatile 61, 31, 368, 0
	setmetatile 62, 31, 368, 0
	setmetatile 63, 31, 368, 0
	setmetatile 60, 32, 368, 0
	setmetatile 61, 32, 368, 0
	setmetatile 62, 32, 368, 0
	setmetatile 63, 32, 368, 0
	setmetatile 61, 33, 368, 0
	setmetatile 62, 33, 368, 0
	return

Route105_EventScript_274149:: @ 8274149
	setmetatile 16, 14, 368, 0
	setmetatile 17, 14, 368, 0
	setmetatile 15, 15, 368, 0
	setmetatile 16, 15, 368, 0
	setmetatile 17, 15, 368, 0
	setmetatile 18, 15, 368, 0
	setmetatile 15, 16, 368, 0
	setmetatile 16, 16, 368, 0
	setmetatile 17, 16, 368, 0
	setmetatile 18, 16, 368, 0
	setmetatile 16, 17, 368, 0
	setmetatile 17, 17, 368, 0
	return

Route105_EventScript_2741B6:: @ 82741B6
	setmetatile 42, 19, 368, 0
	setmetatile 43, 19, 368, 0
	setmetatile 41, 20, 368, 0
	setmetatile 42, 20, 368, 0
	setmetatile 43, 20, 368, 0
	setmetatile 44, 20, 368, 0
	setmetatile 41, 21, 368, 0
	setmetatile 42, 21, 368, 0
	setmetatile 43, 21, 368, 0
	setmetatile 44, 21, 368, 0
	setmetatile 42, 22, 368, 0
	setmetatile 43, 22, 368, 0
	return

Underwater3_EventScript_274223:: @ 8274223
Underwater5_EventScript_274223:: @ 8274223
Underwater6_EventScript_274223:: @ 8274223
Underwater7_EventScript_274223:: @ 8274223
	switch VAR_0x4037
	case 9, Underwater3_EventScript_274281
	case 10, Underwater3_EventScript_27428A
	case 11, Underwater3_EventScript_274293
	case 12, Underwater3_EventScript_27429C
	case 13, Underwater3_EventScript_2742A5
	case 14, Underwater3_EventScript_2742AE
	case 15, Underwater3_EventScript_2742B7
	case 16, Underwater3_EventScript_2742C0
	return

Underwater3_EventScript_274281:: @ 8274281
	setescapewarp ROUTE_105, 255, 11, 29
	return

Underwater3_EventScript_27428A:: @ 827428A
	setescapewarp ROUTE_105, 255, 21, 54
	return

Underwater3_EventScript_274293:: @ 8274293
	setescapewarp ROUTE_125, 255, 9, 17
	return

Underwater3_EventScript_27429C:: @ 827429C
	setescapewarp ROUTE_125, 255, 54, 19
	return

Underwater3_EventScript_2742A5:: @ 82742A5
	setescapewarp ROUTE_127, 255, 58, 10
	return

Underwater3_EventScript_2742AE:: @ 82742AE
	setescapewarp ROUTE_127, 255, 62, 31
	return

Underwater3_EventScript_2742B7:: @ 82742B7
	setescapewarp ROUTE_129, 255, 17, 15
	return

Underwater3_EventScript_2742C0:: @ 82742C0
	setescapewarp ROUTE_129, 255, 43, 20
	return

Std_RegisteredInMatchCall:: @ 82742C9
	buffertrainerclassname 0, VAR_0x8000
	buffertrainername 1, VAR_0x8000
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox gUnknown_08272E0F, 4
	waitfanfare
	closemessage
	delay 30
	return

EventScript_TryGetTrainerScript:: @ 82742E6
	special ShouldTryGetTrainerScript
	compare VAR_RESULT, 1
	goto_eq EventScript_GotoTrainerScript
	releaseall
	end

EventScript_GotoTrainerScript:: @ 82742F6
	gotobeatenscript
	releaseall
	end

	.include "data/scripts/berry_tree.inc"

Text_274746: @ 8274746
	.string "If some vines drop down, this tree can\n"
	.string "be climbed.$"

Text_274779: @ 8274779
	.string "If some vines drop down, this tree can\n"
	.string "be climbed.\p"
	.string "Use the SECRET POWER?$"

Text_2747C2: @ 82747C2
	.string "A thick vine dropped down!$"

Text_2747DD: @ 82747DD
	.string "If this clump of grass can be moved,\n"
	.string "it might be possible to go inside.$"

Text_274825: @ 8274825
	.string "If this clump of grass can be moved,\n"
	.string "it might be possible to go inside.\p"
	.string "Use the SECRET POWER?$"

Text_274883: @ 8274883
	.string "Discovered a small entrance!$"

SecretBase_RedCave1_Text_2748A0: @ 82748A0
	.string "Have you made a SECRET BASE already?\p"
	.string "I went here, there, everywhere before\n"
	.string "choosing this place.\p"
	.string "Since you’re already here, how would\n"
	.string "you like to battle?$"

SecretBase_RedCave1_Text_274939: @ 8274939
	.string "Okay!\n"
	.string "Here we come!$"

SecretBase_RedCave1_Text_27494D: @ 827494D
	.string "Hunh?\n"
	.string "Oh, you can’t now…$"

SecretBase_RedCave1_Text_274966:: @ 8274966
	.string "Waaargh! You’re too strong!\n"
	.string "About me losing… Please keep it secret!$"

SecretBase_RedCave1_Text_2749AA: @ 82749AA
	.string "What do you think of my SECRET BASE?\n"
	.string "Come visit me again tomorrow.$"

SecretBase_RedCave1_Text_2749ED: @ 82749ED
	.string "Have you made a SECRET BASE already?\p"
	.string "I went here, there, everywhere before\n"
	.string "choosing this place.\p"
	.string "Feel free to hang out!$"

SecretBase_RedCave1_Text_274A64: @ 8274A64
	.string "There’re a lot of places where\n"
	.string "you can make a SECRET BASE.\p"
	.string "But I like this spot best.\n"
	.string "Don’t you think it’s nice?\p"
	.string "Oh, would you like to have a battle?$"

SecretBase_RedCave1_Text_274AFA: @ 8274AFA
	.string "Okay, here goes!$"

SecretBase_RedCave1_Text_274B0B: @ 8274B0B
	.string "Oh…\n"
	.string "You can’t now, okay.$"

SecretBase_RedCave1_Text_274B24:: @ 8274B24
	.string "Hmmm… It’s our loss…\n"
	.string "But don’t tell anyone!\l"
	.string "It’s a confidential secret!$"

SecretBase_RedCave1_Text_274B6C: @ 8274B6C
	.string "If you’re in this area again,\n"
	.string "I hope you’ll visit me.$"

SecretBase_RedCave1_Text_274BA2: @ 8274BA2
	.string "There’re a lot of places where you can\n"
	.string "make a SECRET BASE.\p"
	.string "But I like this spot best.\n"
	.string "Don’t you think it’s nice?$"

SecretBase_RedCave1_Text_274C13: @ 8274C13
	.string "This is a popular spot.\n"
	.string "It’s always taken.\p"
	.string "Oh! Were you thinking about\n"
	.string "taking this spot, too?\p"
	.string "I’ll tell you what, you can have this\n"
	.string "spot if you can beat me.$"

SecretBase_RedCave1_Text_274CB0: @ 8274CB0
	.string "Okay!\n"
	.string "I’m going to defend my SECRET BASE!$"

SecretBase_RedCave1_Text_274CDA: @ 8274CDA
	.string "Hunh? Is that right?\n"
	.string "You’re not interested in this spot?$"

SecretBase_RedCave1_Text_274D13:: @ 8274D13
	.string "I can’t keep going!\n"
	.string "I surrender!$"

SecretBase_RedCave1_Text_274D34: @ 8274D34
	.string "Okay, when I move one day,\n"
	.string "this place will be yours!$"

SecretBase_RedCave1_Text_274D69: @ 8274D69
	.string "This is a popular spot.\n"
	.string "It’s always taken.\p"
	.string "I waited a long time for it to open.\n"
	.string "I finally got to use it!$"

SecretBase_RedCave1_Text_274DD2: @ 8274DD2
	.string "Welcome to my POKéMON LAB.\p"
	.string "I carry out research on battling in\n"
	.string "secrecy.\p"
	.string "Would you like to see how strong I am?$"

SecretBase_RedCave1_Text_274E41: @ 8274E41
	.string "I’m going to go all out!$"

SecretBase_RedCave1_Text_274E5A: @ 8274E5A
	.string "Oh.\n"
	.string "Some other time, then!$"

SecretBase_RedCave1_Text_274E75:: @ 8274E75
	.string "Hmm… I’ve still got lots to learn.\n"
	.string "I have to study some more.$"

SecretBase_RedCave1_Text_274EB3: @ 8274EB3
	.string "Thanks for battling with me.\n"
	.string "Please come back again tomorrow.$"

SecretBase_RedCave1_Text_274EF1: @ 8274EF1
	.string "Welcome to my POKéMON LAB.\p"
	.string "I carry out research on battling in\n"
	.string "secrecy.$"

SecretBase_RedCave1_Text_274F39: @ 8274F39
	.string "A big mansion is nice, but I like this\n"
	.string "sort of place more.\p"
	.string "I like it because all kinds of people\n"
	.string "come visit me.\p"
	.string "So, how would you like a battle?$"

SecretBase_RedCave1_Text_274FCA: @ 8274FCA
	.string "That’s the way!$"

SecretBase_RedCave1_Text_274FDA: @ 8274FDA
	.string "When you’re ready, give me a shout!$"

SecretBase_RedCave1_Text_274FFE:: @ 8274FFE
	.string "Aww! Done in!\n"
	.string "But it’s still fun to battle!$"

SecretBase_RedCave1_Text_27502A: @ 827502A
	.string "Well, anyway, I should go buy some\n"
	.string "decorations and furniture.\p"
	.string "I want my SECRET BASE to be a place\n"
	.string "other people can enjoy.$"

SecretBase_RedCave1_Text_2750A4: @ 82750A4
	.string "A big mansion is nice, but I like this\n"
	.string "sort of place more.\p"
	.string "I like it because all kinds of people\n"
	.string "come visit me.$"

SecretBase_RedCave1_Text_275114: @ 8275114
	.string "I simply adore shopping for decorations\n"
	.string "and furniture.\p"
	.string "I also love raising POKéMON just\n"
	.string "as much.\p"
	.string "If you would be so kind, will you battle\n"
	.string "with my POKéMON?$"

SecretBase_RedCave1_Text_2751AF: @ 82751AF
	.string "Thank you.\n"
	.string "Shall we begin?$"

SecretBase_RedCave1_Text_2751CA: @ 82751CA
	.string "Oh.\n"
	.string "How disappointing…$"

SecretBase_RedCave1_Text_2751E1:: @ 82751E1
	.string "I concede…$"

SecretBase_RedCave1_Text_2751EC: @ 82751EC
	.string "That was all in good fun!\n"
	.string "I should go enjoy shopping now.$"

SecretBase_RedCave1_Text_275226: @ 8275226
	.string "I simply adore shopping for decorations\n"
	.string "and furniture.\p"
	.string "I also love raising POKéMON just\n"
	.string "as much.$"

SecretBase_RedCave1_Text_275287: @ 8275287
	.string "Some people make their SECRET BASES in\n"
	.string "hard-to-find places.\l"
	.string "Do they want to just lie low?\p"
	.string "But since you found me, how about we\n"
	.string "have a battle?$"

SecretBase_RedCave1_Text_275315: @ 8275315
	.string "I’m not going down easily!$"

SecretBase_RedCave1_Text_275330: @ 8275330
	.string "Oh… Are you maybe tired from searching\n"
	.string "for this place?$"

SecretBase_RedCave1_Text_275367:: @ 8275367
	.string "I went down…$"

SecretBase_RedCave1_Text_275374: @ 8275374
	.string "Where’s your SECRET BASE?\n"
	.string "I should go visit you there.$"

SecretBase_RedCave1_Text_2753AB: @ 82753AB
	.string "Some people make their SECRET BASES in\n"
	.string "hard-to-find places.\l"
	.string "Do they want to just lie low?$"

SecretBase_RedCave1_Text_275405: @ 8275405
	.string "People have told me that you can get\n"
	.string "decorations in several ways.\p"
	.string "We should have a race to see who can\n"
	.string "get nicer decorations and furniture!\p"
	.string "In the meantime, want to battle?$"

SecretBase_RedCave1_Text_2754B2: @ 82754B2
	.string "This is my SECRET BASE.\n"
	.string "I can’t lose!$"

SecretBase_RedCave1_Text_2754D8: @ 82754D8
	.string "I’ll battle with you anytime.$"

SecretBase_RedCave1_Text_2754F6:: @ 82754F6
	.string "Huh?\n"
	.string "Did I just lose?$"

SecretBase_RedCave1_Text_27550C: @ 827550C
	.string "I won’t lose at collecting decorations.\n"
	.string "Come visit again!$"

SecretBase_RedCave1_Text_275546: @ 8275546
	.string "People have told me that you can get\n"
	.string "decorations in several ways.\p"
	.string "We should have a race to see who can\n"
	.string "get nicer decorations and furniture!$"

SecretBase_RedCave1_Text_2755D2: @ 82755D2
	.string "I found a spot I liked, and I did it up\n"
	.string "with my favorite decorations.\p"
	.string "I raise my favorite POKéMON and grow\n"
	.string "stronger with it.\p"
	.string "That’s what I do.\n"
	.string "Want to battle with me?$"

SecretBase_RedCave1_Text_275679: @ 8275679
	.string "Show me what you’re made of!$"

SecretBase_RedCave1_Text_275696: @ 8275696
	.string "I guess there are times when you’re not\n"
	.string "into it.$"

SecretBase_RedCave1_Text_2756C7:: @ 82756C7
	.string "I know exactly what you’re made of now.$"

SecretBase_RedCave1_Text_2756EF: @ 82756EF
	.string "We can both become stronger.\n"
	.string "Let’s keep at it!$"

SecretBase_RedCave1_Text_27571E: @ 827571E
	.string "I found a spot I liked, and I did it up\n"
	.string "with my favorite decorations.\p"
	.string "I raise my favorite POKéMON and grow\n"
	.string "stronger with it.\p"
	.string "Every day is a great day.$"

SecretBase_RedCave1_Text_2757B5: @ 82757B5
	.string "You can learn a lot about the taste\n"
	.string "and sense of people by the kinds of\l"
	.string "decorations they have, and how they\l"
	.string "display them.\p"
	.string "What do you think of my taste?\n"
	.string "Are you speechless?\p"
	.string "Want to see my taste in battling?$"

SecretBase_RedCave1_Text_275884: @ 8275884
	.string "There’s no holding back!$"

SecretBase_RedCave1_Text_27589D: @ 827589D
	.string "I’ll be happy to demonstrate my style\n"
	.string "anytime.$"

SecretBase_RedCave1_Text_2758CC:: @ 82758CC
	.string "You’re supremely talented!\n"
	.string "Your power seems to be limitless…$"

SecretBase_RedCave1_Text_275909: @ 8275909
	.string "What did you think of my style?\n"
	.string "I’ll keep on polishing it!$"

SecretBase_RedCave1_Text_275944: @ 8275944
	.string "You can learn a lot about the taste\n"
	.string "and sense of people by the kinds of\l"
	.string "decorations they have, and how they\l"
	.string "display them.\p"
	.string "What do you think of my taste?\n"
	.string "Are you speechless?$"

EventScript_2759F1:: @ 82759F1
	special sub_80E8C98
	special sub_80E8BC8
	compare VAR_RESULT, 1
	goto_eq EventScript_275BE8
	checkpartymove MOVE_SECRET_POWER
	setfieldeffectargument 0, VAR_RESULT
	buffermovename 1, MOVE_SECRET_POWER
	compare VAR_0x8007, 1
	goto_eq EventScript_275A50
	compare VAR_0x8007, 2
	goto_eq EventScript_275A50
	compare VAR_0x8007, 3
	goto_eq EventScript_275A50
	compare VAR_0x8007, 4
	goto_eq EventScript_275A50
	compare VAR_0x8007, 5
	goto_eq EventScript_275AA9
	compare VAR_0x8007, 6
	goto_eq EventScript_275B02
	end

EventScript_275A50:: @ 8275A50
	lockall
	compare VAR_RESULT, 6
	goto_eq EventScript_275A91
	bufferpartymonnick 0, VAR_RESULT
	msgbox gText_23B704, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	msgbox Route103_Text_290771, 4
	closemessage
	dofieldeffect 11
	waitstate
	goto EventScript_275A9B
	end

EventScript_275A86:: @ 8275A86
	lockall
	dofieldeffect 11
	waitstate
	goto EventScript_275A9B
	end

EventScript_275A91:: @ 8275A91
	msgbox gText_23B6E0, 4
	releaseall
	end

EventScript_275A9B:: @ 8275A9B
	msgbox gText_23B73E, 4
	goto EventScript_275B5B
	end

EventScript_275AA9:: @ 8275AA9
	lockall
	compare VAR_RESULT, 6
	goto_eq EventScript_275AEA
	bufferpartymonnick 0, VAR_RESULT
	msgbox Text_274779, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	msgbox Route103_Text_290771, 4
	closemessage
	dofieldeffect 26
	waitstate
	goto EventScript_275AF4
	end

EventScript_275ADF:: @ 8275ADF
	lockall
	dofieldeffect 26
	waitstate
	goto EventScript_275AF4
	end

EventScript_275AEA:: @ 8275AEA
	msgbox Text_274746, 4
	releaseall
	end

EventScript_275AF4:: @ 8275AF4
	msgbox Text_2747C2, 4
	goto EventScript_275B5B
	end

EventScript_275B02:: @ 8275B02
	lockall
	compare VAR_RESULT, 6
	goto_eq EventScript_275B43
	bufferpartymonnick 0, VAR_RESULT
	msgbox Text_274825, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	msgbox Route103_Text_290771, 4
	closemessage
	dofieldeffect 27
	waitstate
	goto EventScript_275B4D
	end

EventScript_275B38:: @ 8275B38
	lockall
	dofieldeffect 27
	waitstate
	goto EventScript_275B4D
	end

EventScript_275B43:: @ 8275B43
	msgbox Text_2747DD, 4
	releaseall
	end

EventScript_275B4D:: @ 8275B4D
	msgbox Text_274883, 4
	goto EventScript_275B5B
	end

EventScript_275B5B:: @ 8275B5B
	closemessage
	playse SE_KAIDAN
	setvar VAR_0x4097, 0
	setflag FLAG_0x0AD
	special sub_80E8E18
	special sub_80E9068
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special sub_80E933C
	setvar VAR_0x4089, 1
	waitstate
	end

SecretBase_RedCave1_EventScript_275B81:: @ 8275B81
	applymovement 255, SecretBase_RedCave1_Movement_275BB4
	waitmovement 0
	setvar VAR_0x4097, 1
	msgbox SecretBase_RedCave1_Text_23B759, 5
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275BAB
	closemessage
	playse SE_KAIDAN
	special sub_80E9A90
	end

SecretBase_RedCave1_EventScript_275BAB:: @ 8275BAB
	closemessage
	setflag FLAG_0x060
	special sub_80E91F8
	waitstate
	end

SecretBase_RedCave1_Movement_275BB4: @ 8275BB4
	step_up
	step_up
	step_end

EventScript_275BB7:: @ 8275BB7
	lockall
	setvar VAR_0x4097, 1
	playse SE_KAIDAN
	special sub_80E9744
	compare VAR_RESULT, 0
	goto_eq EventScript_275BDB
	clearflag FLAG_0x0AD
	special sub_80E9068
	setvar VAR_0x4089, 0
	waitstate
	end

EventScript_275BDB:: @ 8275BDB
	setflag FLAG_0x0AD
	special sub_80E9068
	setvar VAR_0x4089, 0
	waitstate
	end

EventScript_275BE8:: @ 8275BE8
	checkpartymove MOVE_SECRET_POWER
	compare VAR_RESULT, 6
	goto_eq EventScript_275C9A
	setfieldeffectargument 0, VAR_RESULT
	setorcopyvar VAR_0x8004, VAR_RESULT
	lockall
	special GetSecretBaseNearbyMapName
	msgbox Text_276A3D, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	msgbox Text_2766AA, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	fadescreenswapbuffers 1
	special sub_80E9B70
	closemessage
	fadescreenswapbuffers 0
	msgbox Text_276A95, 5
	compare VAR_RESULT, 0
	goto_eq EventScript_275CDE
	bufferpartymonnick 0, VAR_0x8004
	buffermovename 1, MOVE_SECRET_POWER
	msgbox Route103_Text_290771, 4
	closemessage
	closemessage
	compare VAR_0x8007, 1
	goto_eq EventScript_275A86
	compare VAR_0x8007, 2
	goto_eq EventScript_275A86
	compare VAR_0x8007, 3
	goto_eq EventScript_275A86
	compare VAR_0x8007, 4
	goto_eq EventScript_275A86
	compare VAR_0x8007, 5
	goto_eq EventScript_275ADF
	compare VAR_0x8007, 6
	goto_eq EventScript_275B38
	releaseall
	end

EventScript_275C9A:: @ 8275C9A
	lockall
	compare VAR_0x8007, 1
	goto_eq EventScript_275A91
	compare VAR_0x8007, 2
	goto_eq EventScript_275A91
	compare VAR_0x8007, 3
	goto_eq EventScript_275A91
	compare VAR_0x8007, 4
	goto_eq EventScript_275A91
	compare VAR_0x8007, 5
	goto_eq EventScript_275AEA
	compare VAR_0x8007, 6
	goto_eq EventScript_275B43
	end

EventScript_275CDE:: @ 8275CDE
	closemessage
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_275CE1:: @ 8275CE1
LittlerootTown_MaysHouse_2F_EventScript_275CE1:: @ 8275CE1
SecretBase_RedCave1_EventScript_275CE1:: @ 8275CE1
	setflag FLAG_0x0AE
	setflag FLAG_0x0AF
	setflag FLAG_0x0B0
	setflag FLAG_0x0B1
	setflag FLAG_0x0B2
	setflag FLAG_0x0B3
	setflag FLAG_0x0B4
	setflag FLAG_0x0B5
	setflag FLAG_0x0B6
	setflag FLAG_0x0B7
	setflag FLAG_0x0B8
	setflag FLAG_0x0B9
	setflag FLAG_0x0BA
	setflag FLAG_0x0BB
	return

EventScript_275D0C:: @ 8275D0C
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special sub_80E933C
	setvar VAR_0x4089, 1
	end

EventScript_275D1F:: @ 8275D1F
	setvar VAR_0x8005, 0
	goto EventScript_275D2A
	end

EventScript_275D2A:: @ 8275D2A
	special sub_8127E18
	end

EventScript_275D2E:: @ 8275D2E
	setvar VAR_0x8004, 0
	goto EventScript_275D39
	end

EventScript_275D39:: @ 8275D39
	special sub_8129708
	compare VAR_RESULT, 1
	goto_eq EventScript_275D63
	addvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	goto_eq EventScript_275D39
	removeobject VAR_0x8006
	setflag 0x8005
	goto EventScript_275D39
	end

EventScript_275D63:: @ 8275D63
	end

SecretBase_BlueCave1_EventScript_275D64:: @ 8275D64
SecretBase_BlueCave2_EventScript_275D64:: @ 8275D64
SecretBase_BlueCave3_EventScript_275D64:: @ 8275D64
SecretBase_BlueCave4_EventScript_275D64:: @ 8275D64
SecretBase_BrownCave1_EventScript_275D64:: @ 8275D64
SecretBase_BrownCave2_EventScript_275D64:: @ 8275D64
SecretBase_BrownCave3_EventScript_275D64:: @ 8275D64
SecretBase_BrownCave4_EventScript_275D64:: @ 8275D64
SecretBase_RedCave1_EventScript_275D64:: @ 8275D64
SecretBase_RedCave2_EventScript_275D64:: @ 8275D64
SecretBase_RedCave3_EventScript_275D64:: @ 8275D64
SecretBase_RedCave4_EventScript_275D64:: @ 8275D64
SecretBase_Shrub1_EventScript_275D64:: @ 8275D64
SecretBase_Shrub2_EventScript_275D64:: @ 8275D64
SecretBase_Shrub3_EventScript_275D64:: @ 8275D64
SecretBase_Shrub4_EventScript_275D64:: @ 8275D64
SecretBase_Tree1_EventScript_275D64:: @ 8275D64
SecretBase_Tree2_EventScript_275D64:: @ 8275D64
SecretBase_Tree3_EventScript_275D64:: @ 8275D64
SecretBase_Tree4_EventScript_275D64:: @ 8275D64
SecretBase_YellowCave1_EventScript_275D64:: @ 8275D64
SecretBase_YellowCave2_EventScript_275D64:: @ 8275D64
SecretBase_YellowCave3_EventScript_275D64:: @ 8275D64
SecretBase_YellowCave4_EventScript_275D64:: @ 8275D64
	special sub_80EA354
	compare VAR_0x8004, 0
	goto_eq SecretBase_RedCave1_EventScript_275DD6
	compare VAR_0x8004, 1
	goto_eq SecretBase_RedCave1_EventScript_275E4E
	compare VAR_0x8004, 2
	goto_eq SecretBase_RedCave1_EventScript_275EC6
	compare VAR_0x8004, 3
	goto_eq SecretBase_RedCave1_EventScript_275F3E
	compare VAR_0x8004, 4
	goto_eq SecretBase_RedCave1_EventScript_275FB6
	compare VAR_0x8004, 5
	goto_eq SecretBase_RedCave1_EventScript_27602E
	compare VAR_0x8004, 6
	goto_eq SecretBase_RedCave1_EventScript_2760A6
	compare VAR_0x8004, 7
	goto_eq SecretBase_RedCave1_EventScript_27611E
	compare VAR_0x8004, 8
	goto_eq SecretBase_RedCave1_EventScript_276196
	compare VAR_0x8004, 9
	goto_eq SecretBase_RedCave1_EventScript_27620E
	end

SecretBase_RedCave1_EventScript_275DD6:: @ 8275DD6
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_275E25
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275E44
	msgbox SecretBase_RedCave1_Text_2748A0, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275E2F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275E2F
	msgbox SecretBase_RedCave1_Text_274939, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_275E25:: @ 8275E25
	msgbox SecretBase_RedCave1_Text_2749ED, 4
	release
	end

SecretBase_RedCave1_EventScript_275E2F:: @ 8275E2F
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_27494D, 4
	release
	end

SecretBase_RedCave1_EventScript_275E44:: @ 8275E44
	msgbox SecretBase_RedCave1_Text_2749AA, 4
	release
	end

SecretBase_RedCave1_EventScript_275E4E:: @ 8275E4E
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_275E9D
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275EBC
	msgbox SecretBase_RedCave1_Text_274C13, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275EA7
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275EA7
	msgbox SecretBase_RedCave1_Text_274CB0, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_275E9D:: @ 8275E9D
	msgbox SecretBase_RedCave1_Text_274D69, 4
	release
	end

SecretBase_RedCave1_EventScript_275EA7:: @ 8275EA7
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_274CDA, 4
	release
	end

SecretBase_RedCave1_EventScript_275EBC:: @ 8275EBC
	msgbox SecretBase_RedCave1_Text_274D34, 4
	release
	end

SecretBase_RedCave1_EventScript_275EC6:: @ 8275EC6
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_275F15
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275F34
	msgbox SecretBase_RedCave1_Text_274F39, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F1F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F1F
	msgbox SecretBase_RedCave1_Text_274FCA, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_275F15:: @ 8275F15
	msgbox SecretBase_RedCave1_Text_2750A4, 4
	release
	end

SecretBase_RedCave1_EventScript_275F1F:: @ 8275F1F
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_274FDA, 4
	release
	end

SecretBase_RedCave1_EventScript_275F34:: @ 8275F34
	msgbox SecretBase_RedCave1_Text_27502A, 4
	release
	end

SecretBase_RedCave1_EventScript_275F3E:: @ 8275F3E
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_275F8D
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275FAC
	msgbox SecretBase_RedCave1_Text_275287, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F97
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F97
	msgbox SecretBase_RedCave1_Text_275315, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_275F8D:: @ 8275F8D
	msgbox SecretBase_RedCave1_Text_2753AB, 4
	release
	end

SecretBase_RedCave1_EventScript_275F97:: @ 8275F97
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_275330, 4
	release
	end

SecretBase_RedCave1_EventScript_275FAC:: @ 8275FAC
	msgbox SecretBase_RedCave1_Text_275374, 4
	release
	end

SecretBase_RedCave1_EventScript_275FB6:: @ 8275FB6
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_276005
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276024
	msgbox SecretBase_RedCave1_Text_2755D2, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_27600F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_27600F
	msgbox SecretBase_RedCave1_Text_275679, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_276005:: @ 8276005
	msgbox SecretBase_RedCave1_Text_27571E, 4
	release
	end

SecretBase_RedCave1_EventScript_27600F:: @ 827600F
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_275696, 4
	release
	end

SecretBase_RedCave1_EventScript_276024:: @ 8276024
	msgbox SecretBase_RedCave1_Text_2756EF, 4
	release
	end

SecretBase_RedCave1_EventScript_27602E:: @ 827602E
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_27607D
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27609C
	msgbox SecretBase_RedCave1_Text_274A64, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276087
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276087
	msgbox SecretBase_RedCave1_Text_274AFA, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_27607D:: @ 827607D
	msgbox SecretBase_RedCave1_Text_274BA2, 4
	release
	end

SecretBase_RedCave1_EventScript_276087:: @ 8276087
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_274B0B, 4
	release
	end

SecretBase_RedCave1_EventScript_27609C:: @ 827609C
	msgbox SecretBase_RedCave1_Text_274B6C, 4
	release
	end

SecretBase_RedCave1_EventScript_2760A6:: @ 82760A6
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_2760F5
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276114
	msgbox SecretBase_RedCave1_Text_274DD2, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2760FF
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2760FF
	msgbox SecretBase_RedCave1_Text_274E41, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_2760F5:: @ 82760F5
	msgbox SecretBase_RedCave1_Text_274EF1, 4
	release
	end

SecretBase_RedCave1_EventScript_2760FF:: @ 82760FF
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_274E5A, 4
	release
	end

SecretBase_RedCave1_EventScript_276114:: @ 8276114
	msgbox SecretBase_RedCave1_Text_274EB3, 4
	release
	end

SecretBase_RedCave1_EventScript_27611E:: @ 827611E
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_27616D
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27618C
	msgbox SecretBase_RedCave1_Text_275114, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276177
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276177
	msgbox SecretBase_RedCave1_Text_2751AF, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_27616D:: @ 827616D
	msgbox SecretBase_RedCave1_Text_275226, 4
	release
	end

SecretBase_RedCave1_EventScript_276177:: @ 8276177
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_2751CA, 4
	release
	end

SecretBase_RedCave1_EventScript_27618C:: @ 827618C
	msgbox SecretBase_RedCave1_Text_2751EC, 4
	release
	end

SecretBase_RedCave1_EventScript_276196:: @ 8276196
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_2761E5
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276204
	msgbox SecretBase_RedCave1_Text_275405, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2761EF
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2761EF
	msgbox SecretBase_RedCave1_Text_2754B2, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_2761E5:: @ 82761E5
	msgbox SecretBase_RedCave1_Text_275546, 4
	release
	end

SecretBase_RedCave1_EventScript_2761EF:: @ 82761EF
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_2754D8, 4
	release
	end

SecretBase_RedCave1_EventScript_276204:: @ 8276204
	msgbox SecretBase_RedCave1_Text_27550C, 4
	release
	end

SecretBase_RedCave1_EventScript_27620E:: @ 827620E
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_27625D
	compare VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27627C
	msgbox SecretBase_RedCave1_Text_2757B5, 5
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276267
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276267
	msgbox SecretBase_RedCave1_Text_275884, 4
	goto SecretBase_RedCave1_EventScript_276286
	end

SecretBase_RedCave1_EventScript_27625D:: @ 827625D
	msgbox SecretBase_RedCave1_Text_275944, 4
	release
	end

SecretBase_RedCave1_EventScript_276267:: @ 8276267
	special sub_80EB300
	setvar VAR_RESULT, 0
	special sub_80EA30C
	msgbox SecretBase_RedCave1_Text_27589D, 4
	release
	end

SecretBase_RedCave1_EventScript_27627C:: @ 827627C
	msgbox SecretBase_RedCave1_Text_275909, 4
	release
	end

SecretBase_RedCave1_EventScript_276286:: @ 8276286
	special sub_80EA2E4
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	special sub_8163AC4
	waitstate
	compare VAR_RESULT, 3
	call_if 1, SecretBase_RedCave1_EventScript_2762BD
	compare VAR_RESULT, 1
	call_if 1, SecretBase_RedCave1_EventScript_2762C1
	compare VAR_RESULT, 2
	call_if 1, SecretBase_RedCave1_EventScript_2762C5
	special HealPlayerParty
	release
	end

SecretBase_RedCave1_EventScript_2762BD:: @ 82762BD
	special sub_80EB438
	return

SecretBase_RedCave1_EventScript_2762C1:: @ 82762C1
	special sub_80EB368
	return

SecretBase_RedCave1_EventScript_2762C5:: @ 82762C5
	special sub_80EB3D0
	return

	.include "data/scripts/secret_power_tm.inc"

Text_2766AA: @ 82766AA
	.string "All decorations and furniture in your\n"
	.string "SECRET BASE will be returned to your PC.\p"
	.string "Is that okay?$"

Text_276707: @ 8276707
	.string "Do you want to register\n"
	.string "{STR_VAR_1}’s SECRET BASE?$"

Text_276731: @ 8276731
	.string "This data is already registered.\n"
	.string "Would you like to delete it?$"

Text_27676F: @ 827676F
	.string "Up to 10 locations can be registered.\p"
	.string "Delete a location if you want to\n"
	.string "register another location.$"

Text_2767D1: @ 82767D1
	.string "Registration completed.$"

Text_2767E9: @ 82767E9
	.string "Data has been unregistered.$"

Text_276805: @ 8276805
	.string "{PLAYER} booted up the PC.$"

Text_27681A: @ 827681A
	.string "What would you like to do?$"

Text_276835: @ 8276835
	.string "Once registered, a SECRET BASE will not\n"
	.string "disappear unless the other TRAINER\l"
	.string "moves it to a different location.\p"
	.string "If a SECRET BASE is deleted from the\n"
	.string "registered list, another one may take\l"
	.string "its place.\p"
	.string "Up to ten SECRET BASE locations\n"
	.string "may be registered.$"

Text_27692B: @ 827692B
	.string "A shield of {STR_VAR_2} that marks winning\n"
	.string "{STR_VAR_1} times in a row at the BATTLE TOWER.$"

Text_276974: @ 8276974
	.string "A realistic toy TV. It could be easily\n"
	.string "mistaken for the real thing.$"

Text_2769B8: @ 82769B8
	.string "A toy TV shaped like a SEEDOT.\n"
	.string "It looks ready to roll away on its own…$"

Text_2769FF: @ 82769FF
	.string "A toy TV shaped like a SKITTY.\n"
	.string "It looks ready to stroll away…$"

Text_276A3D: @ 8276A3D
	.string "You may only make one SECRET BASE.\p"
	.string "Would you like to move from the SECRET\n"
	.string "BASE near {STR_VAR_1}?$"

Text_276A95: @ 8276A95
	.string "Moving completed.\p"
	.string "Would you like to use the SECRET POWER?$"

	.include "data/scripts/cable_club.inc"
	.include "data/scripts/contest_hall.inc"
	.include "data/text/contest_strings.inc"

gUnknown_0827E8CE:: @ 827E8CE
	.string "Missed turn$"

gUnknown_0827E8DA:: @ 827E8DA
	.string "Link standby!$"

gUnknown_0827E8E8:: @ 827E8E8
	.string "The winner is {STR_VAR_1}’s {STR_VAR_2}!\n"
	.string "Congratulations!$"

gUnknown_0827E910:: @ 827E910
	.string "The winner is {STR_VAR_1}’s {STR_VAR_2}!{PAUSE_UNTIL_PRESS}$"

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
	.string "{STR_VAR_1}’s {STR_VAR_2}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E9B9:: @ 827E9B9
	.string "Set event: No. {STR_VAR_1}{PAUSE_UNTIL_PRESS}$"

gUnknown_0827E9CD:: @ 827E9CD
	.string "A link TV program will not be made\n"
	.string "because the TRAINER lost.{PAUSE_UNTIL_PRESS}$"

gUnknown_0827EA0C:: @ 827EA0C
	.string "{STR_VAR_1}\n"
	.string "{STR_VAR_2}’s {STR_VAR_3}$"

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
	.string "This century’s last Venus--\n"
	.string "the beautiful {STR_VAR_1}$"

gContestPaintingBeauty2::
	.string "{STR_VAR_1}’s dazzling,\n"
	.string "glittering smile$"

gContestPaintingBeauty3::
	.string "POKéMON CENTER’s super idol--\n"
	.string "the incomparable {STR_VAR_1}$"

gContestPaintingCute1::
	.string "The lovely and sweet {STR_VAR_1}$"

gContestPaintingCute2::
	.string "The pretty {STR_VAR_1}’s\n"
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
	.string "The excellent {STR_VAR_1}’s\n"
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

gUnknown_0827ECBC:: @ 27ECBC
	.string "ODDISH$"

gUnknown_0827ECC3:: @ 27ECC3
	.string "POOCHYENA$"

gUnknown_0827ECCD:: @ 27ECCD
	.string "TAILLOW$"

gUnknown_0827ECD5:: @ 27ECD5
	.string "AZURILL$"

gUnknown_0827ECDD:: @ 27ECDD
	.string "LOTAD$"

gUnknown_0827ECE3:: @ 27ECE3
	.string "WINGULL$"

gUnknown_0827ECEB:: @ 27ECEB
	.string "DUSTOX$"

gUnknown_0827ECF2:: @ 27ECF2
	.string "ZUBAT$"

gUnknown_0827ECF8:: @ 27ECF8
	.string "NINCADA$"

gUnknown_0827ED00:: @ 27ED00
	.string "RALTS$"

gUnknown_0827ED06:: @ 27ED06
	.string "ZIGZAGOON$"

gUnknown_0827ED10:: @ 27ED10
	.string "SLAKOTH$"

gUnknown_0827ED18:: @ 27ED18
	.string "POOCHYENA$"

gUnknown_0827ED22:: @ 27ED22
	.string "SHROOMISH$"

gUnknown_0827ED2C:: @ 27ED2C
	.string "ZIGZAGOON$"

gUnknown_0827ED36:: @ 27ED36
	.string "POOCHYENA$"

gUnknown_0827ED40:: @ 27ED40
	.string "ZUBAT$"

gUnknown_0827ED46:: @ 27ED46
	.string "CARVANHA$"

gUnknown_0827ED4F:: @ 27ED4F
	.string "BURN HEAL$"

gUnknown_0827ED59:: @ 27ED59
	.string "HARBOR MAIL$"

gUnknown_0827ED65:: @ 27ED65
	.string "Same price$"

gUnknown_0827ED70:: @ 27ED70
	.string "¥60$"

gUnknown_0827ED74:: @ 27ED74
	.string "¥55$"

gUnknown_0827ED78:: @ 27ED78
	.string "Nothing$"

gUnknown_0827ED80:: @ 27ED80
	.string "They will cost more.$"

gUnknown_0827ED95:: @ 27ED95
	.string "They will cost less.$"

gUnknown_0827EDAA:: @ 27EDAA
	.string "Same price$"

gUnknown_0827EDB5:: @ 27EDB5
	.string "Male$"

gUnknown_0827EDBA:: @ 27EDBA
	.string "Female$"

gUnknown_0827EDC1:: @ 27EDC1
	.string "Neither$"

gUnknown_0827EDC9:: @ 27EDC9
	.string "Elderly men$"

gUnknown_0827EDD5:: @ 27EDD5
	.string "Elderly ladies$"

gUnknown_0827EDE4:: @ 27EDE4
	.string "Same number$"

gUnknown_0827EDF0:: @ 27EDF0
	.string "None$"

gUnknown_0827EDF5:: @ 27EDF5
	.string "1$"

gUnknown_0827EDF7:: @ 27EDF7
	.string "2$"

gUnknown_0827EDF9:: @ 27EDF9
	.string "2$"

gUnknown_0827EDFB:: @ 27EDFB
	.string "3$"

gUnknown_0827EDFD:: @ 27EDFD
	.string "4$"

gUnknown_0827EDFF:: @ 27EDFF
	.string "6$"

gUnknown_0827EE01:: @ 27EE01
	.string "7$"

gUnknown_0827EE03:: @ 27EE03
	.string "8$"

gUnknown_0827EE05:: @ 27EE05
	.string "6$"

gUnknown_0827EE07:: @ 27EE07
	.string "7$"

gUnknown_0827EE09:: @ 27EE09
	.string "8$"

	.include "data/scripts/tv.inc"
	.include "data/text/tv.inc"

BattleFrontier_BattleTowerLobby_EventScript_28C7E9:: @ 828C7E9
LilycoveCity_ContestLobby_EventScript_28C7E9:: @ 828C7E9
SlateportCity_OceanicMuseum_1F_EventScript_28C7E9:: @ 828C7E9
SlateportCity_PokemonFanClub_EventScript_28C7E9:: @ 828C7E9
	special InterviewAfter
	incrementgamestat 6
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C7F0:: @ 828C7F0
	setvar VAR_0x8005, 1
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C879
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280674, 5
	compare VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C827
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C85C
	end

SlateportCity_PokemonFanClub_EventScript_28C827:: @ 828C827
	msgbox SlateportCity_PokemonFanClub_Text_28073B, 4
	setvar VAR_0x8004, 5
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 1
	call SlateportCity_PokemonFanClub_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C866
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C85C
	end

SlateportCity_PokemonFanClub_EventScript_28C85C:: @ 828C85C
	msgbox SlateportCity_PokemonFanClub_Text_2805E2, 4
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C866:: @ 828C866
	msgbox SlateportCity_PokemonFanClub_Text_280789, 4
	setvar VAR_0x8005, 1
	goto SlateportCity_PokemonFanClub_EventScript_28C7E9
	end

SlateportCity_PokemonFanClub_EventScript_28C879:: @ 828C879
	msgbox SlateportCity_PokemonFanClub_Text_28062E, 4
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C883:: @ 828C883
	lock
	faceplayer
	setvar VAR_0x8005, 2
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C939
	copyvar VAR_0x8009, VAR_0x8006
	checkflag FLAG_0x069
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8C8
	setflag FLAG_0x069
	msgbox SlateportCity_OceanicMuseum_1F_Text_2811A0, 5
	compare VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare VAR_RESULT, 0
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C8C8:: @ 828C8C8
	msgbox SlateportCity_OceanicMuseum_1F_Text_28126D, 5
	compare VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare VAR_RESULT, 0
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C8E7:: @ 828C8E7
	msgbox SlateportCity_OceanicMuseum_1F_Text_2812F2, 4
	setvar VAR_0x8004, 5
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call SlateportCity_OceanicMuseum_1F_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C926
	compare VAR_RESULT, 0
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C91C:: @ 828C91C
	msgbox SlateportCity_OceanicMuseum_1F_Text_281367, 4
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C926:: @ 828C926
	msgbox SlateportCity_OceanicMuseum_1F_Text_2813B9, 4
	setvar VAR_0x8005, 2
	goto SlateportCity_OceanicMuseum_1F_EventScript_28C7E9
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C939:: @ 828C939
	msgbox SlateportCity_OceanicMuseum_1F_Text_28144D, 4
	release
	end

SlateportCity_PokemonFanClub_EventScript_28C943:: @ 828C943
	lock
	faceplayer
	specialvar VAR_RESULT, sub_80EF8F8
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C7F0
	setvar VAR_0x8005, 3
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA4F
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280270, 5
	compare VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C98C
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	end

SlateportCity_PokemonFanClub_EventScript_28C98C:: @ 828C98C
	msgbox SlateportCity_PokemonFanClub_Text_28034F, 4
	random 3
	copyvar VAR_0x800A, VAR_RESULT
	switch VAR_RESULT
	case 0, SlateportCity_PokemonFanClub_EventScript_28C9C3
	case 1, SlateportCity_PokemonFanClub_EventScript_28C9D1
	case 2, SlateportCity_PokemonFanClub_EventScript_28C9DF
	end

SlateportCity_PokemonFanClub_EventScript_28C9C3:: @ 828C9C3
	msgbox SlateportCity_PokemonFanClub_Text_280393, 4
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9D1:: @ 828C9D1
	msgbox SlateportCity_PokemonFanClub_Text_2803EF, 4
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9DF:: @ 828C9DF
	msgbox SlateportCity_PokemonFanClub_Text_280454, 4
	goto SlateportCity_PokemonFanClub_EventScript_28C9ED
	end

SlateportCity_PokemonFanClub_EventScript_28C9ED:: @ 828C9ED
	setvar VAR_0x8004, 7
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call SlateportCity_PokemonFanClub_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	msgbox SlateportCity_PokemonFanClub_Text_2804AC, 4
	setvar VAR_0x8006, 1
	call SlateportCity_PokemonFanClub_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	msgbox SlateportCity_PokemonFanClub_Text_280523, 4
	copyvar VAR_0x8007, VAR_0x800A
	setvar VAR_0x8005, 3
	goto SlateportCity_PokemonFanClub_EventScript_28C7E9
	end

SlateportCity_PokemonFanClub_EventScript_28CA45:: @ 828CA45
	msgbox SlateportCity_PokemonFanClub_Text_2805E2, 4
	release
	end

SlateportCity_PokemonFanClub_EventScript_28CA4F:: @ 828CA4F
	msgbox SlateportCity_PokemonFanClub_Text_28062E, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_28CA59:: @ 828CA59
	lock
	faceplayer
	checkflag FLAG_0x002
	goto_eq LilycoveCity_ContestLobby_EventScript_28CB21
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CB21
	copyvar VAR_0x8009, VAR_0x8006
	msgbox LilycoveCity_ContestLobby_Text_27EF15, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CA9B
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	end

LilycoveCity_ContestLobby_EventScript_28CA9B:: @ 828CA9B
	msgbox LilycoveCity_ContestLobby_Text_27EFE7, 4
	setvar VAR_0x8004, 11
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call LilycoveCity_ContestLobby_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CADA
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	end

LilycoveCity_ContestLobby_EventScript_28CAD0:: @ 828CAD0
	msgbox LilycoveCity_ContestLobby_Text_27F1EF, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_28CADA:: @ 828CADA
	setvar VAR_0x8004, 24
	special SetContestCategoryStringVarForInterview
	msgbox LilycoveCity_ContestLobby_Text_27F03E, 4
	setvar VAR_0x8004, 11
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 1
	call LilycoveCity_ContestLobby_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_28CAD0
	msgbox LilycoveCity_ContestLobby_Text_27F0EC, 4
	setflag FLAG_0x002
	setvar VAR_0x8005, 6
	goto LilycoveCity_ContestLobby_EventScript_28C7E9
	end

LilycoveCity_ContestLobby_EventScript_28CB21:: @ 828CB21
	msgbox LilycoveCity_ContestLobby_Text_27F23F, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_28CB2B:: @ 828CB2B
	compare VAR_0x4086, 2
	goto_if 5, LilycoveCity_ContestLobby_EventScript_28CB95
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CB95
	switch VAR_0x4088
	case 0, LilycoveCity_ContestLobby_EventScript_28CB95
	case 2, LilycoveCity_ContestLobby_EventScript_28CB91
	case 1, LilycoveCity_ContestLobby_EventScript_28CB91
	case 3, LilycoveCity_ContestLobby_EventScript_28CB91
	case 4, LilycoveCity_ContestLobby_EventScript_28CB91
	case 5, LilycoveCity_ContestLobby_EventScript_28CB95
	end

LilycoveCity_ContestLobby_EventScript_28CB91:: @ 828CB91
	clearflag FLAG_0x322
	return

LilycoveCity_ContestLobby_EventScript_28CB95:: @ 828CB95
	return

BattleFrontier_BattleTowerLobby_EventScript_28CB96:: @ 828CB96
	lock
	faceplayer
	checkflag FLAG_0x002
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC7A
	setvar VAR_0x8005, 7
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC7A
	copyvar VAR_0x8009, VAR_0x8006
	msgbox BattleFrontier_BattleTowerLobby_Text_27F704, 5
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CBD8
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC2E
	end

BattleFrontier_BattleTowerLobby_EventScript_28CBD8:: @ 828CBD8
	message BattleFrontier_BattleTowerLobby_Text_27F7BA
	waitmessage
	multichoice 20, 8, 45, 1
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_RESULT, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_28CC38
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_28CC41
	msgbox BattleFrontier_BattleTowerLobby_Text_27F97A, 4
	setvar VAR_0x8004, 12
	copyvar VAR_0x8005, VAR_0x8009
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC4A
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC2E:: @ 828CC2E
	msgbox BattleFrontier_BattleTowerLobby_Text_27F84C, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC38:: @ 828CC38
	msgbox BattleFrontier_BattleTowerLobby_Text_27F8AE, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_28CC41:: @ 828CC41
	msgbox BattleFrontier_BattleTowerLobby_Text_27F921, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_28CC4A:: @ 828CC4A
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
	msgbox BattleFrontier_BattleTowerLobby_Text_27F9FD, 4
	setflag FLAG_0x002
	copyvar VAR_0x8004, VAR_0x8008
	setvar VAR_0x8005, 7
	goto BattleFrontier_BattleTowerLobby_EventScript_28C7E9
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC70:: @ 828CC70
	msgbox BattleFrontier_BattleTowerLobby_Text_27FA6F, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC7A:: @ 828CC7A
	msgbox BattleFrontier_BattleTowerLobby_Text_27FAF3, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC84:: @ 828CC84
	compare VAR_0x40BC, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
	setvar VAR_0x8005, 7
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
	clearflag FLAG_0x396
	return

BattleFrontier_BattleTowerLobby_EventScript_28CCA6:: @ 828CCA6
	setflag FLAG_0x396
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

EventScript_292DE5:: @ 8292DE5
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7F66, 3
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

gUnknown_082942FD:: @ 82942FD
	.string " is$"

gUnknown_08294301:: @ 8294301
	.string "\n"
	.string "Don’t you agree?$"

gUnknown_08294313:: @ 8294313
	.string "I so want to go on a vacation.\n"
	.string "Would you happen to know a nice place?$"

gUnknown_08294359:: @ 8294359
	.string "I bought crayons with 120 colors!\n"
	.string "Don’t you think that’s nice?$"

gUnknown_08294398:: @ 8294398
	.string "Wouldn’t it be nice if we could float\n"
	.string "away on a cloud of bubbles?$"

gUnknown_082943DA:: @ 82943DA
	.string "When you write on a sandy beach,\n"
	.string "they wash away. It makes me sad.$"

gUnknown_0829441C:: @ 829441C
	.string "What’s the bottom of the sea like?\n"
	.string "Just once I would so love to go!$"

gUnknown_08294460:: @ 8294460
	.string "When you see the setting sun, does it\n"
	.string "make you want to go home?$"

gUnknown_082944A0:: @ 82944A0
	.string "Lying back in the green grass…\n"
	.string "Oh, it’s so, so nice!$"

gUnknown_082944D5:: @ 82944D5
	.string "SECRET BASES are so wonderful!\n"
	.string "Can’t you feel the excitement?$"

	.include "data/text/trainers.inc"

EventScript_RepelWoreOff:: @ 82A4B2A
	msgbox Text_RepelWoreOff, 3
	end

Text_RepelWoreOff: @ 82A4B33
	.string "REPEL’s effect wore off…$"

	.include "data/scripts/safari_zone.inc"

MauvilleCity_GameCorner_EventScript_2A5AB1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 0
	getpricereduction 2
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5ADF:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 1
	getpricereduction 2
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5B0D:: @ 82A5B0D
	special sub_8142BC8
	waitstate
	end

	.include "data/text/roulette.inc"
	.include "data/text/pokedex_rating.inc"
	.include "data/text/lottery_corner.inc"
	.include "data/text/eon_ticket.inc"
	.include "data/text/braille.inc"
	.include "data/text/berries.inc"
	.include "data/text/shoal_cave.inc"

Text_2A81E5: @ 82A81E5
	.string "There’s a set of POKéMON picture books.$"

Text_2A820D: @ 82A820D
	.string "It’s filled with all sorts of books.$"

Text_2A8232: @ 82A8232
	.string "POKéMON magazines!\n"
	.string "POKéMON PAL…\p"
	.string "POKéMON HANDBOOK…\n"
	.string "ADORABLE POKéMON…$"

Text_2A8276: @ 82A8276
	.string "This vase looks expensive…\n"
	.string "Peered inside…\p"
	.string "But, it was empty.$"

Text_2A82B3: @ 82A82B3
	.string "It’s empty.$"

Text_2A82BF: @ 82A82BF
	.string "The shelves brim with all sorts of\n"
	.string "POKéMON merchandise.$"

Text_2A82F7: @ 82A82F7
	.string "A blueprint of some sort?\n"
	.string "It’s too complicated!$"

GraniteCave_B1F_MapScript2_2A8327: @ 82A8327
MirageTower_2F_MapScript2_2A8327: @ 82A8327
MirageTower_3F_MapScript2_2A8327: @ 82A8327
MtPyre_2F_MapScript2_2A8327: @ 82A8327
SkyPillar_2F_MapScript2_2A8327: @ 82A8327
SkyPillar_4F_MapScript2_2A8327: @ 82A8327
	map_script_2 VAR_ICE_STEP_COUNT, 0, gUnknown_082A8337
	.2byte 0

GraniteCave_B1F_MapScript1_2A8331: @ 82A8331
MirageTower_2F_MapScript1_2A8331: @ 82A8331
MirageTower_3F_MapScript1_2A8331: @ 82A8331
MtPyre_2F_MapScript1_2A8331: @ 82A8331
	copyvar VAR_ICE_STEP_COUNT, 0x1
	end

gUnknown_082A8337:: @ 82A8337
	lockall
	delay 20
	applymovement 255, GraniteCave_B1F_Movement_2A8369
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	warphole UNDEFINED
	waitstate
	end

gUnknown_082A8350:: @ 82A8350
	lockall
	delay 20
	applymovement 255, GraniteCave_B1F_Movement_2A8369
	waitmovement 0
	playse SE_RU_HYUU
	delay 60
	special sp13F_fall_to_last_warp
	waitstate
	end

GraniteCave_B1F_Movement_2A8369: @ 82A8369
	step_54
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_2A836B:: @ 82A836B
	special sub_818DAEC
	switch VAR_RESULT
	case 0, LilycoveCity_PokemonCenter_1F_EventScript_2A8554
	case 1, LilycoveCity_PokemonCenter_1F_EventScript_2A8395
	case 2, LilycoveCity_PokemonCenter_1F_EventScript_2A882A
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8395:: @ 82A8395
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8A69, 4
	specialvar VAR_RESULT, sub_818DBE8
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83D0
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83C6
	compare VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8510
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A83C6:: @ 82A83C6
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8AB1, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A83D0:: @ 82A83D0
	special sub_818DC2C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8A7D, 4
	specialvar VAR_RESULT, sub_818DC60
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8435
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83F7
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A83F7:: @ 82A83F7
	special sub_818DCC8
	special sub_818DD14
	specialvar VAR_RESULT, sub_818DD54
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8419
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8427
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8419:: @ 82A8419
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8ACE, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8435
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8427:: @ 82A8427
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8B36, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8435
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8435:: @ 82A8435
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8B69, 5
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A845E
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8454:: @ 82A8454
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BCD, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A845E:: @ 82A845E
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BAD, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A846C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A846C:: @ 82A846C
	fadescreen 1
	setvar VAR_RESULT, 0
	special sub_818DD78
	waitstate
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A848E
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84AD
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A848E:: @ 82A848E
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BEE, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A846C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84AD:: @ 82A84AD
	specialvar VAR_RESULT, sub_818DE44
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84C9
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84D6
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84C9:: @ 82A84C9
	special sub_818DC2C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8C0F, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84D6:: @ 82A84D6
	specialvar VAR_RESULT, sub_818DE5C
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84F2
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84FF
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84F2:: @ 82A84F2
	special sub_818DC2C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8C6F, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84FF:: @ 82A84FF
	special sub_818DC2C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8CC8, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8510
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8510:: @ 82A8510
	setvar VAR_0x8004, 0
	specialvar VAR_0x8004, sub_818DEA0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8D5D, 4
	giveitem_std VAR_0x8004
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8545
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A854F
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8545:: @ 82A8545
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8DBD, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A854F:: @ 82A854F
	special sub_818DEDC
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8554:: @ 82A8554
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8E2B, 4
	specialvar VAR_RESULT, sub_818E038
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8585
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85AC
	compare VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86EC
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8585:: @ 82A8585
	specialvar VAR_RESULT, sub_818E06C
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85C8
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85D2
	compare VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85E0
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85AC:: @ 82A85AC
	specialvar VAR_RESULT, sub_818E2D8
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8759
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85C8
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85C8:: @ 82A85C8
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8E4E, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85D2:: @ 82A85D2
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EAC, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A85EE
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85E0:: @ 82A85E0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EAC, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A85EE
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85EE:: @ 82A85EE
	setvar VAR_0x8004, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8EEC, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A861C
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8612
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8612:: @ 82A8612
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F65, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A861C:: @ 82A861C
	special sub_818E3BC
	compare VAR_0x8004, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A864C
	compare VAR_0x8004, 15
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8656

LilycoveCity_PokemonCenter_1F_EventScript_2A8635:: @ 82A8635
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8660
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8689
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A864C:: @ 82A864C
	special sub_811A858
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8635
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8656:: @ 82A8656
	special sub_818E2FC
	waitstate
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8635
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8660:: @ 82A8660
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F7E, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A867F
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A861C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A867F:: @ 82A867F
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F9A, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8689:: @ 82A8689
	special sub_818E37C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F4D, 4
	specialvar VAR_RESULT, sub_818E308
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86C7
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86B0
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A86B0:: @ 82A86B0
	playse SE_SEIKAI
	delay 10
	playse SE_SEIKAI
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8FC7, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A86EC
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A86C7:: @ 82A86C7
	special sub_818E538
	special sub_818E274
	playse SE_HAZURE
	delay 10
	playse SE_HAZURE
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A90A5, 4
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A90CD, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8759
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A86EC:: @ 82A86EC
	specialvar VAR_RESULT, sub_818E298
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8708
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8716
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8708:: @ 82A8708
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9007, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8724
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8716:: @ 82A8716
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9007, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8724
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8724:: @ 82A8724
	setvar VAR_0x8005, 0
	special sub_818E358
	special sub_818E37C
	giveitem_std VAR_0x8005
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A874C
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8759
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A874C:: @ 82A874C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A906A, 4
	special sub_818E39C
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8759:: @ 82A8759
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A90FB, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8785
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8778:: @ 82A8778
	special sub_818E3EC
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9131, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8785:: @ 82A8785
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9153, 4

LilycoveCity_PokemonCenter_1F_EventScript_2A878D:: @ 82A878D
	fadescreen 1
	setvar VAR_RESULT, 0
	special sub_818E3E0
	waitstate
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87AF
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87CE
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A87AF:: @ 82A87AF
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9212, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A878D
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A87CE:: @ 82A87CE
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9270, 4
	special sub_818E430
	special sub_818E3BC
	setvar VAR_0x8004, 16

LilycoveCity_PokemonCenter_1F_EventScript_2A87E1:: @ 82A87E1
	fadescreen 1
	special sub_818E47C
	waitstate
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87F8
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8817
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A87F8:: @ 82A87F8
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A92D3, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87E1
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8817:: @ 82A8817
	special sub_818E490
	special sub_818E4A4
	special sub_818E510
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9336, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A882A:: @ 82A882A
	lock
	faceplayer
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A93A7, 4
	specialvar VAR_RESULT, sub_818E8B4
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8850
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A886C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8850:: @ 82A8850
	specialvar VAR_RESULT, sub_818E8E0
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8876
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A886C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A886C:: @ 82A886C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A93D6, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8876:: @ 82A8876
	special sub_818E914
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A93F4, 4
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A89AE
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A94E8, 5
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88BA
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A88B0:: @ 82A88B0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9556, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A88BA:: @ 82A88BA
	fadescreen 1
	special sub_818E92C
	waitstate
	compare VAR_RESULT, 65535
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88D7
	compare VAR_RESULT, 65535
	goto_if 5, LilycoveCity_PokemonCenter_1F_EventScript_2A88F6
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A88D7:: @ 82A88D7
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9537, 5
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88BA
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A88F6:: @ 82A88F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9571, 4
	special sub_818E940
	special sub_818E960
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A890A
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A890A:: @ 82A890A
	applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_2A89B8
	waitmovement 0
	delay 60
	applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_2A89BB
	waitmovement 0
	delay 60
	waitse
	playmoncry VAR_0x8005, 0
	delay 120
	waitmoncry
	compare VAR_0x8004, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A893F
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A894C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A893F:: @ 82A893F
	applymovement 5, LilycoveCity_PokemonCenter_1F_Movement_2A89C2
	waitmovement 0
	delay 60

LilycoveCity_PokemonCenter_1F_EventScript_2A894C:: @ 82A894C
	applymovement 4, LilycoveCity_PokemonCenter_1F_Movement_2A89C0
	waitmovement 0
	delay 60
	compare VAR_0x8004, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8970
	compare VAR_0x8004, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A897E
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8970:: @ 82A8970
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A95AD, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A898F
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A897E:: @ 82A897E
	special sub_818E914
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9605, 4
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A898F
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A898F:: @ 82A898F
	specialvar VAR_RESULT, sub_818E8E0
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A89A1
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A89A1:: @ 82A89A1
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9669, 4
	special PutLilycoveContestLadyShowOnTheAir
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A89AE:: @ 82A89AE
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9451, 4
	release
	end

LilycoveCity_PokemonCenter_1F_Movement_2A89B8: @ 82A89B8
	step_03
	step_13
	step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89BB: @ 82A89BB
	step_02
	step_13
	step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89BE: @ 82A89BE
	step_00
	step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89C0: @ 82A89C0
	step_3e
	step_end

LilycoveCity_PokemonCenter_1F_Movement_2A89C2: @ 82A89C2
	step_51
	step_48
	step_51
	step_48
	step_end

LilycoveCity_PokemonCenter_1F_EventScript_2A89C7:: @ 82A89C7
	specialvar VAR_RESULT, sub_818E990
	special sub_818E914
	special sub_818E960
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A0A
	compare VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A1D
	compare VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A30
	compare VAR_RESULT, 3
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A43
	compare VAR_RESULT, 4
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A56
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A0A:: @ 82A8A0A
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A96DA, 4
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A1D:: @ 82A8A1D
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A970E, 4
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A30:: @ 82A8A30
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A96F6, 4
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A43:: @ 82A8A43
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A96E6, 4
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8A56:: @ 82A8A56
	lock
	faceplayer
	waitse
	playmoncry VAR_0x8005, 0
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9703, 4
	waitmoncry
	release
	end

LilycoveCity_PokemonCenter_1F_Text_2A8A69: @ 82A8A69
	.string "I’m the FAVOR LADY…$"

LilycoveCity_PokemonCenter_1F_Text_2A8A7D: @ 82A8A7D
	.string "I’ve recently developed an obsession\n"
	.string "for {STR_VAR_1} things…$"

LilycoveCity_PokemonCenter_1F_Text_2A8AB1: @ 82A8AB1
	.string "Oh…\n"
	.string "Thank you for last time…$"

LilycoveCity_PokemonCenter_1F_Text_2A8ACE: @ 82A8ACE
	.string "Before, I think it was {STR_VAR_3}…\p"
	.string "{STR_VAR_3} gave me one {STR_VAR_2},\n"
	.string "saying it was {STR_VAR_1}.\p"
	.string "But it wasn’t {STR_VAR_1}.\n"
	.string "Not in the least bit.$"

LilycoveCity_PokemonCenter_1F_Text_2A8B36: @ 82A8B36
	.string "Before, {STR_VAR_3} gave me a very\n"
	.string "{STR_VAR_1} {STR_VAR_2}.\p"
	.string "I cherish it now.$"

LilycoveCity_PokemonCenter_1F_Text_2A8B69: @ 82A8B69
	.string "Listen, if you have anything that\n"
	.string "is {STR_VAR_1}, will you share it\l"
	.string "with me?$"

LilycoveCity_PokemonCenter_1F_Text_2A8BAD: @ 82A8BAD
	.string "…Really?\n"
	.string "What will you give me?$"

LilycoveCity_PokemonCenter_1F_Text_2A8BCD: @ 82A8BCD
	.string "Is that so?\n"
	.string "Then, it’s good-bye…$"

LilycoveCity_PokemonCenter_1F_Text_2A8BEE: @ 82A8BEE
	.string "Oh…\n"
	.string "You’re not willing to share?$"

LilycoveCity_PokemonCenter_1F_Text_2A8C0F: @ 82A8C0F
	.string "Oh?\n"
	.string "That {STR_VAR_2} is {STR_VAR_1}?\p"
	.string "…Oh, is that right?\p"
	.string "Well, I owe you a thanks anyway.\n"
	.string "I’ll try to cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_2A8C6F: @ 82A8C6F
	.string "Oh…\p"
	.string "That’s a quite {STR_VAR_1}\n"
	.string "{STR_VAR_2}…\p"
	.string "Isn’t it nice?\n"
	.string "It’s so dreamy…\p"
	.string "Thank you…\n"
	.string "I will cherish this…$"

LilycoveCity_PokemonCenter_1F_Text_2A8CC8: @ 82A8CC8
	.string "…Oh, oh, oh…\p"
	.string "This is amazing!\n"
	.string "This really is {STR_VAR_1}!\p"
	.string "I never knew that one {STR_VAR_2}\n"
	.string "could be this {STR_VAR_1}!\p"
	.string "Thank you!\p"
	.string "I will treasure this for the rest\n"
	.string "of my life!$"

LilycoveCity_PokemonCenter_1F_Text_2A8D5D: @ 82A8D5D
	.string "I’ll give you this wonderful item in\n"
	.string "return for your fabulous gift.\p"
	.string "I hope you will cherish it…$"

LilycoveCity_PokemonCenter_1F_Text_2A8DBD: @ 82A8DBD
	.string "Oh, you can’t have it if you don’t have\n"
	.string "the space for it.\p"
	.string "Please come see me when you get\n"
	.string "your BAG organized…$"

LilycoveCity_PokemonCenter_1F_Text_2A8E2B: @ 82A8E2B
	.string "I’m the QUIZ LADY!\n"
	.string "I love quizzes!$"

LilycoveCity_PokemonCenter_1F_Text_2A8E4E: @ 82A8E4E
	.string "Oh?\p"
	.string "I’m waiting for a challenger to answer\n"
	.string "the quiz you made.\p"
	.string "We can chat another time, okay?$"

LilycoveCity_PokemonCenter_1F_Text_2A8EAC: @ 82A8EAC
	.string "I’m waiting for someone to challenge\n"
	.string "a quiz this {STR_VAR_1} thought up!$"

LilycoveCity_PokemonCenter_1F_Text_2A8EEC: @ 82A8EEC
	.string "If you answer correctly, you can win\n"
	.string "fabulous prizes!\p"
	.string "Would you like to take the quiz\n"
	.string "challenge?$"

LilycoveCity_PokemonCenter_1F_Text_2A8F4D: @ 82A8F4D
	.string "… … … … … …\n"
	.string "… … … … … …$"

LilycoveCity_PokemonCenter_1F_Text_2A8F65: @ 82A8F65
	.string "Oh, how boring!\n"
	.string "Bye-bye!$"

LilycoveCity_PokemonCenter_1F_Text_2A8F7E: @ 82A8F7E
	.string "Awww!\n"
	.string "You’re going to quit?$"

LilycoveCity_PokemonCenter_1F_Text_2A8F9A: @ 82A8F9A
	.string "Please take the quiz challenge\n"
	.string "another time!$"

LilycoveCity_PokemonCenter_1F_Text_2A8FC7: @ 82A8FC7
	.string "You’re amazing! You’ve got it right!\n"
	.string "You’re one sharp customer!$"

LilycoveCity_PokemonCenter_1F_Text_2A9007: @ 82A9007
	.string "Congratulations!\n"
	.string "You’ve got the quiz right!\p"
	.string "You’ve won a prize provided by\n"
	.string "{STR_VAR_1}!$"

LilycoveCity_PokemonCenter_1F_Text_2A9056: @ 82A9056
	.string "{STR_VAR_1} received\n"
	.string "one {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_2A906A: @ 82A906A
	.string "Oh? Your BAG is filled up!\n"
	.string "Come see me when you have room.$"

LilycoveCity_PokemonCenter_1F_Text_2A90A5: @ 82A90A5
	.string "Hmm… Wrong!\n"
	.string "The correct answer is “{STR_VAR_3}”!$"

LilycoveCity_PokemonCenter_1F_Text_2A90CD: @ 82A90CD
	.string "Too bad!\p"
	.string "I get to keep the quiz prize\n"
	.string "{STR_VAR_1} now!$"

LilycoveCity_PokemonCenter_1F_Text_2A90FB: @ 82A90FB
	.string "Listen, listen!\n"
	.string "Would you like to make your own quiz?$"

LilycoveCity_PokemonCenter_1F_Text_2A9131: @ 82A9131
	.string "Oh, I see…\n"
	.string "Well, maybe next time!$"

LilycoveCity_PokemonCenter_1F_Text_2A9153: @ 82A9153
	.string "Okay, the first thing you have to do\n"
	.string "is pick the prize for the person that\l"
	.string "answers your quiz correctly.\p"
	.string "But beware, if the person taking\n"
	.string "the quiz can’t get it right, I get to\l"
	.string "keep the prize!$"

LilycoveCity_PokemonCenter_1F_Text_2A9212: @ 82A9212
	.string "If you don’t choose a prize,\n"
	.string "your quiz can’t be made.\p"
	.string "Are you going to quit making\n"
	.string "your quiz?$"

LilycoveCity_PokemonCenter_1F_Text_2A9270: @ 82A9270
	.string "Oh, how nice!\n"
	.string "That’s a wonderful prize!\p"
	.string "Next, you need to write your quiz\n"
	.string "question and its answer.$"

LilycoveCity_PokemonCenter_1F_Text_2A92D3: @ 82A92D3
	.string "Are you going to quit writing\n"
	.string "your quiz question?$"

LilycoveCity_PokemonCenter_1F_Text_2A9305: @ 82A9305
	.string "Are you going to quit choosing\n"
	.string "your quiz answer?$"

LilycoveCity_PokemonCenter_1F_Text_2A9336: @ 82A9336
	.string "Thank you!\n"
	.string "You’ve put together a nice quiz.\p"
	.string "I’ll go look for someone who’ll take\n"
	.string "your quiz challenge right away.$"

LilycoveCity_PokemonCenter_1F_Text_2A93A7: @ 82A93A7
	.string "I’m the CONTEST LADY!\n"
	.string "I sure do love CONTESTS!$"

LilycoveCity_PokemonCenter_1F_Text_2A93D6: @ 82A93D6
	.string "Thanks for your {POKEBLOCK} before!$"

LilycoveCity_PokemonCenter_1F_Text_2A93F4: @ 82A93F4
	.string "This is my friend {STR_VAR_1}!\n"
	.string "It’s the epitome of {STR_VAR_2}!\p"
	.string "But I think that it will display\n"
	.string "even more {STR_VAR_2}!$"

LilycoveCity_PokemonCenter_1F_Text_2A9451: @ 82A9451
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I’m asking for is one!\p"
	.string "…Oh, but…\n"
	.string "Don’t you have a {POKEBLOCK} CASE?\l"
	.string "That’s no good. Next time, then!$"

LilycoveCity_PokemonCenter_1F_Text_2A94E8: @ 82A94E8
	.string "So, I need your help!\p"
	.string "Please, may I have one {POKEBLOCK}?\n"
	.string "All I’m asking for is one!$"

LilycoveCity_PokemonCenter_1F_Text_2A9537: @ 82A9537
	.string "Awww!\n"
	.string "I can’t have one {POKEBLOCK}?!$"

LilycoveCity_PokemonCenter_1F_Text_2A9556: @ 82A9556
	.string "Sheesh!\n"
	.string "What a cheapskate!$"

LilycoveCity_PokemonCenter_1F_Text_2A9571: @ 82A9571
	.string "Yay!\n"
	.string "Thank you!\p"
	.string "I’ll feed my POKéMON your {POKEBLOCK}\n"
	.string "right away.$"

LilycoveCity_PokemonCenter_1F_Text_2A95AD: @ 82A95AD
	.string "…It doesn’t seem to have changed\n"
	.string "in any way at all…\p"
	.string "Hmm…\p"
	.string "Oh, well!\n"
	.string "Thank you very much!$"

LilycoveCity_PokemonCenter_1F_Text_2A9605: @ 82A9605
	.string "Oh, yay!\n"
	.string "It’s really delighted!\p"
	.string "I think it really improved {STR_VAR_1}’s\n"
	.string "{STR_VAR_2} quality, too.\p"
	.string "Thank you so much!$"

LilycoveCity_PokemonCenter_1F_Text_2A9669: @ 82A9669
	.string "Hmm…\p"
	.string "I think we may be ready to enter\n"
	.string "some CONTESTS.\p"
	.string "If you see us in one somewhere,\n"
	.string "I hope you’ll cheer for us.$"

LilycoveCity_PokemonCenter_1F_Text_2A96DA: @ 82A96DA
	.string "{STR_VAR_1}: Guguuh!$"

LilycoveCity_PokemonCenter_1F_Text_2A96E6: @ 82A96E6
	.string "{STR_VAR_1}: Igigigiiih!$"

LilycoveCity_PokemonCenter_1F_Text_2A96F6: @ 82A96F6
	.string "{STR_VAR_1}: Baaarun…$"

LilycoveCity_PokemonCenter_1F_Text_2A9703: @ 82A9703
	.string "{STR_VAR_1}: Pikka!$"

LilycoveCity_PokemonCenter_1F_Text_2A970E: @ 82A970E
	.string "{STR_VAR_1}: Umyaaaan!$"

BattleFrontier_PokeNav_2A971C:: @ 82A971C
	.string "Hi! {PLAYER}{STRING 5}, hello!\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I saw this {STR_VAR_2} a while back\n"
	.string "but I couldn’t catch it.\p"
	.string "It was so close, too!\n"
	.string "Well, see you again!$"

BattleFrontier_PokeNav_2A9798:: @ 82A9798
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "I tried to catch a nice {STR_VAR_2}\n"
	.string "a little while ago.\p"
	.string "But, it got away.\n"
	.string "I was sure disappointed!\p"
	.string "Okay, bye!$"

BattleFrontier_PokeNav_2A9813:: @ 82A9813
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I just took a shot at catching\n"
	.string "this {STR_VAR_2}, but it took off.\p"
	.string "I came oh so close, too!\p"
	.string "It spoiled my day…\n"
	.string "All right, see you!$"

BattleFrontier_PokeNav_2A98A8:: @ 82A98A8
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "You know the POKéMON {STR_VAR_2}?\n"
	.string "I came close to getting one.\p"
	.string "It was just a while back.\n"
	.string "I thought I had it but it escaped.\p"
	.string "If I see it again, I’ll get it for\n"
	.string "sure, though.\p"
	.string "Okay, catch you later.$"

BattleFrontier_PokeNav_2A9977:: @ 82A9977
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\l"
	.string "Catching any POKéMON lately?\p"
	.string "A little while ago I came close to\n"
	.string "nabbing one, but it got loose.\p"
	.string "Right, take care!$"

BattleFrontier_PokeNav_2A99FD:: @ 82A99FD
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\l"
	.string "Caught any POKéMON lately?\p"
	.string "I nearly nabbed one the other day.\n"
	.string "But it evaded me somehow.\p"
	.string "You take care.$"

BattleFrontier_PokeNav_2A9A78:: @ 82A9A78
	.string "…Uh, {PLAYER}{STRING 5}?\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "Oh, wait! Wait!\n"
	.string "I can catch this {STR_VAR_2}…\p"
	.string "Aaarrrgh! It bolted loose!\n"
	.string "That wasn’t just close!$"

BattleFrontier_PokeNav_2A9AE8:: @ 82A9AE8
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\p"
	.string "Have you had success catching\n"
	.string "POKéMON lately?\p"
	.string "I came very close a little while\n"
	.string "ago, but my target got free.\p"
	.string "I need to try harder!\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2A9BA7:: @ 82A9BA7
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "So? Are you getting more POKéMON\n"
	.string "together?\p"
	.string "I’m having a rotten time of it!\n"
	.string "They all get away from me!\p"
	.string "See you!$"

BattleFrontier_PokeNav_2A9C36:: @ 82A9C36
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Listen, I came within a whisker of\n"
	.string "catching this {STR_VAR_2}…\p"
	.string "But, it gave me the slip…\p"
	.string "I need to try harder.\n"
	.string "See you around.$"

BattleFrontier_PokeNav_2A9CC8:: @ 82A9CC8
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "How are things with you?\p"
	.string "I tried to catch a wild {STR_VAR_2}\n"
	.string "earlier, but it managed to flee.\p"
	.string "I feel defeated…$"

BattleFrontier_PokeNav_2A9D44:: @ 82A9D44
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you still catching POKéMON?\p"
	.string "I’ve been trying to catch them\n"
	.string "myself, but it’s not so easy.\p"
	.string "The way of POKéMON is deep!$"

BattleFrontier_PokeNav_2A9DD7:: @ 82A9DD7
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "Have you been catching POKéMON?\p"
	.string "I’ve been trying to catch them\n"
	.string "myself, but with little success.\p"
	.string "The way of POKéMON is deep!$"

BattleFrontier_PokeNav_2A9E70:: @ 82A9E70
	.string "Oh, hi, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Just now, I tried to catch a cute\n"
	.string "{STR_VAR_2}.\p"
	.string "It got away, though!\n"
	.string "Oh, you bet I was disappointed!\p"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2A9EFD:: @ 82A9EFD
	.string "Hey, {PLAYER}!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I’ve been thinking about trying\n"
	.string "to catch me some POKéMON.\p"
	.string "But I can’t seem to find any.\n"
	.string "It’s a real puzzler for me!\p"
	.string "I’m at my wit’s end!\n"
	.string "See you around!$"

BattleFrontier_PokeNav_2A9FAB:: @ 82A9FAB
	.string "Hi! {PLAYER}{STRING 5}, hello!\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I tried battling another TRAINER,\n"
	.string "but I lost.\p"
	.string "It was really disappointing.\n"
	.string "Well, see you again!$"

BattleFrontier_PokeNav_2AA028:: @ 82AA028
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "I challenged someone else after\n"
	.string "we battled.\p"
	.string "I came close, but I ended up\n"
	.string "losing. Oh, well!$"

BattleFrontier_PokeNav_2AA099:: @ 82AA099
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I just got cleaned in a battle.\p"
	.string "I guess I need to raise my team\n"
	.string "some more!$"

BattleFrontier_PokeNav_2AA100:: @ 82AA100
	.string "Hey, {PLAYER}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "I tried another battle yesterday,\n"
	.string "but I couldn’t pull out the win.\p"
	.string "My team needs more raising.\n"
	.string "Okay, catch you later.$"

BattleFrontier_PokeNav_2AA188:: @ 82AA188
	.string "Hiya, {PLAYER}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "How are things with you?\p"
	.string "I’ve been battling on,\n"
	.string "but I haven’t won very often.\p"
	.string "I can’t get it together.\n"
	.string "Right, take care!$"

BattleFrontier_PokeNav_2AA214:: @ 82AA214
	.string "Hey, {PLAYER}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "How’s it going for you?\p"
	.string "I’ve been battling hard lately,\n"
	.string "but to little success.\p"
	.string "I can’t get into the groove.\n"
	.string "You take care.$"

BattleFrontier_PokeNav_2AA2A1:: @ 82AA2A1
	.string "{STR_VAR_1} here.\n"
	.string "How’s it going lately?\p"
	.string "I lost a battle yesterday,\n"
	.string "and it’s filled my thoughts.\p"
	.string "I have to devise a plan…\n"
	.string "See you.$"

BattleFrontier_PokeNav_2AA31B:: @ 82AA31B
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\p"
	.string "How are your POKéMON doing?\n"
	.string "I lost a match the other day.\p"
	.string "I need to try harder!\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2AA3A8:: @ 82AA3A8
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "Listen, listen, you have to hear\n"
	.string "this!\p"
	.string "I had a POKéMON battle earlier,\n"
	.string "but I lost at the last second.\p"
	.string "Oh, it burns me up!$"

BattleFrontier_PokeNav_2AA442:: @ 82AA442
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "A little earlier, I was in a battle.\n"
	.string "I lost, though.\p"
	.string "I need to raise my POKéMON more.\n"
	.string "See you around.$"

BattleFrontier_PokeNav_2AA4C5:: @ 82AA4C5
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "How are your POKéMON?\p"
	.string "I just lost yet another battle.\p"
	.string "Well, see you!$"

BattleFrontier_PokeNav_2AA520:: @ 82AA520
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you still battling hard?\p"
	.string "As for me, I lost recently, so I’ve\n"
	.string "been training my team all over.\p"
	.string "Let’s meet again.$"

BattleFrontier_PokeNav_2AA5AD:: @ 82AA5AD
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I hope you’ve been keeping well.\p"
	.string "I was in a battle just a little\n"
	.string "while before this.\p"
	.string "{PLAYER}{STRING 5}, try to be active like me.\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2AA64D:: @ 82AA64D
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Are you doing good?\p"
	.string "You should go home every so often,\n"
	.string "though.\p"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2AA6AF:: @ 82AA6AF
	.string "Hi! {PLAYER}{STRING 5}, hello!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I battled another TRAINER earlier.\n"
	.string "I won! I won!\p"
	.string "My {STR_VAR_2} really worked hard\n"
	.string "for me. This is so great!$"

BattleFrontier_PokeNav_2AA730:: @ 82AA730
	.string "Hello, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}!\p"
	.string "I had a battle yesterday and\n"
	.string "I won! It’s fantastic!$"

BattleFrontier_PokeNav_2AA77A:: @ 82AA77A
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}!\l"
	.string "How’s your battling?\p"
	.string "Me, I had a battle the other day,\n"
	.string "and my {STR_VAR_2} came up huge!\p"
	.string "The next time I battle you,\n"
	.string "{PLAYER}, it won’t be me losing!$"

BattleFrontier_PokeNav_2AA81C:: @ 82AA81C
	.string "Hey, {PLAYER}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "I had a match earlier.\n"
	.string "I managed to win, but it was close.\p"
	.string "My {STR_VAR_2} put on one\n"
	.string "inspired showing.$"

BattleFrontier_PokeNav_2AA88C:: @ 82AA88C
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "How are things with you?\n"
	.string "Battling much?\p"
	.string "I just won a while back!\n"
	.string "My {STR_VAR_2} was brilliant!\p"
	.string "You wait. I’m going to beat you\n"
	.string "next time! Right, take care!$"

BattleFrontier_PokeNav_2AA934:: @ 82AA934
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "How’s it going for you?\p"
	.string "I’ve been riding a hot streak.\n"
	.string "Why, I just won a battle.\p"
	.string "When we have our next battle,\n"
	.string "I’m sure not going to lose!$"

BattleFrontier_PokeNav_2AA9D3:: @ 82AA9D3
	.string "{PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here.\p"
	.string "My {STR_VAR_2} is a force!\n"
	.string "It won me another battle just now!\p"
	.string "I can’t wait to have a rematch\n"
	.string "with you.$"

BattleFrontier_PokeNav_2AAA40:: @ 82AAA40
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\p"
	.string "I hope you’ve been well.\n"
	.string "I wanted to tell you I just won.\p"
	.string "My {STR_VAR_2} worked especially\n"
	.string "hard to get the win.\p"
	.string "See you again!$"

BattleFrontier_PokeNav_2AAAE4:: @ 82AAAE4
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "How are your POKéMON holding up?\n"
	.string "Mine just won a battle!\p"
	.string "My {STR_VAR_2} was spectacular,\n"
	.string "I must say!\p"
	.string "I wish I could’ve shown you!\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2AAB8C:: @ 82AAB8C
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "How has life been treating you?\p"
	.string "My POKéMON appear to be charged\n"
	.string "with energy.\p"
	.string "I just won a battle with them.\n"
	.string "See you around.$"

BattleFrontier_PokeNav_2AAC25:: @ 82AAC25
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Been in any battles lately?\n"
	.string "I just won another one today!\p"
	.string "I’m on a roll! Gahahaha!\n"
	.string "Well, see you!$"

BattleFrontier_PokeNav_2AAC9D:: @ 82AAC9D
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I trust you’ve been well?\n"
	.string "I’m still bursting with life!\p"
	.string "Why, just now, I won another match.\n"
	.string "I’m not stepping aside to you\l"
	.string "youngsters yet!$"

BattleFrontier_PokeNav_2AAD41:: @ 82AAD41
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I hope you’ve been keeping well.\n"
	.string "I still have a bounce in my step!\p"
	.string "Why, I just won a battle yet again.\n"
	.string "Oh, I won’t lose to young people\l"
	.string "quite yet!\p"
	.string "See you again!$"

BattleFrontier_PokeNav_2AAE00:: @ 82AAE00
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I was in a battle recently, and my\n"
	.string "{STR_VAR_2} was exceptional!\p"
	.string "I wish you could have seen it,\n"
	.string "{PLAYER}{STRING 5}. Bye-bye!$"

BattleFrontier_PokeNav_2AAE7F:: @ 82AAE7F
	.string "Hi! {PLAYER}, hello!\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Huh? Wait, you’re near\n"
	.string "{STR_VAR_2}?\p"
	.string "Oh, wow, we have to battle, then!\n"
	.string "I’ll be waiting! See you!$"

BattleFrontier_PokeNav_2AAEF1:: @ 82AAEF1
	.string "Hello, {PLAYER}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "Oh? You happen to be around\n"
	.string "{STR_VAR_2} right now?\p"
	.string "Would you like to battle now?\n"
	.string "I’ll wait for you! See you!$"

BattleFrontier_PokeNav_2AAF69:: @ 82AAF69
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "Oh, hey, are you near\n"
	.string "{STR_VAR_2} right now?\p"
	.string "How would you like to battle with\n"
	.string "me right now?\p"
	.string "I’m not losing again!\n"
	.string "I’ll be waiting! Catch you soon!$"

BattleFrontier_PokeNav_2AB010:: @ 82AB010
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "Whereabouts are you now?\n"
	.string "Huh? {STR_VAR_2}?\p"
	.string "Want to battle now?\n"
	.string "I’ll wait for you. See you!$"

BattleFrontier_PokeNav_2AB076:: @ 82AB076
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\l"
	.string "How are things with you?\p"
	.string "You’re where now?\n"
	.string "{STR_VAR_2}?\p"
	.string "Well, how about we have a quick\n"
	.string "rematch right away?\p"
	.string "I’ll keep an eye out for you.\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2AB11A:: @ 82AB11A
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\l"
	.string "How are your POKéMON keeping?\p"
	.string "Oh, is that right? You’re around\n"
	.string "{STR_VAR_2}?\p"
	.string "Well, then, we’d better have\n"
	.string "a rematch.\p"
	.string "I can wait, sure.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AB1B4:: @ 82AB1B4
	.string "…Er, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here…\p"
	.string "Oh, you happen to be around\n"
	.string "{STR_VAR_2}?\p"
	.string "Then, let’s battle.\n"
	.string "Right away, I mean.\p"
	.string "I’ll show you my POKéMON.\n"
	.string "I’ll wait for you.$"

BattleFrontier_PokeNav_2AB23D:: @ 82AB23D
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\p"
	.string "I hope you’re doing well.\n"
	.string "Oh, you’re near {STR_VAR_2}.\p"
	.string "Would you like to have a battle\n"
	.string "with me, then?\p"
	.string "I’ll wait for you.\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2AB2E9:: @ 82AB2E9
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "Are you keeping up?\n"
	.string "Oh, you’re near {STR_VAR_2}?\p"
	.string "Oh, well, then don’t you think we\n"
	.string "should battle?\p"
	.string "Don’t keep me waiting too long!$"

BattleFrontier_PokeNav_2AB382:: @ 82AB382
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "How are things with you?\n"
	.string "Oh, you’re near {STR_VAR_2}.\p"
	.string "We should have a battle now, then.\p"
	.string "I’m ready and waiting.\n"
	.string "Be quick!$"

BattleFrontier_PokeNav_2AB410:: @ 82AB410
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Ah, so where you are now is\n"
	.string "{STR_VAR_2}?\p"
	.string "Well, then, we just have to have\n"
	.string "a battle, don’t you think?\p"
	.string "I’ll wait around for you!\n"
	.string "See you real quick!$"

BattleFrontier_PokeNav_2AB4B0:: @ 82AB4B0
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Where might you be now?\p"
	.string "{STR_VAR_2}?\n"
	.string "That’s quite close by!\p"
	.string "What do you say we have a battle\n"
	.string "now?\p"
	.string "I can wait.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AB538:: @ 82AB538
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I hope you’ve been keeping well.\n"
	.string "Oh, you’re near {STR_VAR_2}?\p"
	.string "Since that’s not very far away,\n"
	.string "come see me for a battle.\p"
	.string "I’ll wait for you.\n"
	.string "Bye for now.$"

BattleFrontier_PokeNav_2AB5E4:: @ 82AB5E4
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You’re what? …{STR_VAR_2}?\n"
	.string "That’s very close.\p"
	.string "Don’t you think we ought to have\n"
	.string "a battle?\p"
	.string "I’ll be looking for you!\n"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2AB670:: @ 82AB670
	.string "Hi! {PLAYER}, hello!\n"
	.string "This is {STR_VAR_1}.\p"
	.string "Want to have a battle with me?\p"
	.string "I’ll be waiting for you around\n"
	.string "{STR_VAR_2}!$"

BattleFrontier_PokeNav_2AB6CD:: @ 82AB6CD
	.string "Hello, {PLAYER}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "Would you like to have a battle\n"
	.string "with me again?\p"
	.string "You can find me around\n"
	.string "{STR_VAR_2}. I’ll be waiting!$"

BattleFrontier_PokeNav_2AB73C:: @ 82AB73C
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "My POKéMON have grown a lot\n"
	.string "tougher since last time.\p"
	.string "I want to see how strong they’ve\n"
	.string "become with your POKéMON, {PLAYER}.\p"
	.string "So, let’s have a battle!\p"
	.string "I’ll be waiting for you around\n"
	.string "{STR_VAR_2}.$"

BattleFrontier_PokeNav_2AB808:: @ 82AB808
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\l"
	.string "How are things with you?\p"
	.string "My POKéMON have grown pretty\n"
	.string "tough lately.\p"
	.string "Hey, how would you like to have\n"
	.string "another battle with me?\p"
	.string "Let’s meet up around\n"
	.string "{STR_VAR_2}, okay?$"

BattleFrontier_PokeNav_2AB8B7:: @ 82AB8B7
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "My POKéMON are growing up in\n"
	.string "decent ways.\p"
	.string "I’d really like to have another\n"
	.string "battle with you.\p"
	.string "I’ll keep an eye out for you around\n"
	.string "{STR_VAR_2}. See you soon!$"

BattleFrontier_PokeNav_2AB95D:: @ 82AB95D
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\l"
	.string "I hope you’re on top of things.\p"
	.string "I was thinking I’d like another\n"
	.string "battle with you. What do you say?\p"
	.string "If you feel like a battle,\n"
	.string "come to {STR_VAR_2}.\p"
	.string "See you!$"

BattleFrontier_PokeNav_2ABA03:: @ 82ABA03
	.string "…Er, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here…\l"
	.string "So? Are your POKéMON growing?\p"
	.string "Mine sure got stronger.\n"
	.string "I’d like to show you.\p"
	.string "I’ll be around {STR_VAR_2}.\n"
	.string "Come see me for a match.\p"
	.string "See you around.$"

BattleFrontier_PokeNav_2ABA9F:: @ 82ABA9F
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\p"
	.string "I hope you’re doing well.\n"
	.string "My POKéMON are very frisky.\p"
	.string "If you’re ever in the area, please\n"
	.string "give me a rematch.\p"
	.string "I’ll be around {STR_VAR_2}.\n"
	.string "Until then, good-bye!$"

BattleFrontier_PokeNav_2ABB62:: @ 82ABB62
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "How are your POKéMON doing?\p"
	.string "My POKéMON keep getting better.\n"
	.string "I’d like to show you, {PLAYER}{STRING 5}.\p"
	.string "I’m around {STR_VAR_2} now,\n"
	.string "so let’s battle if you’re close by.\p"
	.string "Hope I see you soon!$"

BattleFrontier_PokeNav_2ABC26:: @ 82ABC26
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\l"
	.string "So, how are things with you?\p"
	.string "My POKéMON have grown much\n"
	.string "stronger than before.\p"
	.string "I’d love another battle with you,\n"
	.string "{PLAYER}{STRING 5}.\p"
	.string "I’ll be around {STR_VAR_2}.\n"
	.string "Come see me if you’re close.$"

BattleFrontier_PokeNav_2ABCE9:: @ 82ABCE9
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "Where might you be now?\p"
	.string "My POKéMON are full of life.\n"
	.string "They appear to be looking forward\l"
	.string "to seeing your POKéMON, {PLAYER}{STRING 5}.\p"
	.string "I’m around {STR_VAR_2} now.\n"
	.string "I hope you’ll seek us out.$"

BattleFrontier_PokeNav_2ABDA2:: @ 82ABDA2
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I should tell you, my POKéMON have\n"
	.string "grown to be quite robust lately.\p"
	.string "I would like to see them in a battle\n"
	.string "with you, {PLAYER}{STRING 5}.\p"
	.string "We’ll be around {STR_VAR_2}.\n"
	.string "Come see us anytime!$"

BattleFrontier_PokeNav_2ABE5E:: @ 82ABE5E
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "Are your POKéMON keeping well?\p"
	.string "My POKéMON have been so healthy,\n"
	.string "they don’t look capable of losing!\p"
	.string "I would surely love to have another\n"
	.string "battle with you.\p"
	.string "If you’re near {STR_VAR_2},\n"
	.string "do come see us.$"

BattleFrontier_PokeNav_2ABF36:: @ 82ABF36
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "Keeping well, I hope.\p"
	.string "Oh, yes! My POKéMON are\n"
	.string "much stronger than before.\p"
	.string "Don’t you think we ought to have\n"
	.string "a battle, {PLAYER}{STRING 5}?\p"
	.string "We’ll be waiting for you around\n"
	.string "{STR_VAR_2}.\p"
	.string "Come see us anytime, okay?$"

BattleFrontier_PokeNav_2AC009:: @ 82AC009
	.string "It’s me, the mountain-loving\n"
	.string "{STR_VAR_1}!\p"
	.string "Well, since we met, have you grown\n"
	.string "to appreciate the mountains more?\p"
	.string "I rarely see you in the mountains…\p"
	.string "Next time, we’ll meet somewhere\n"
	.string "around {STR_VAR_2}.$"

BattleFrontier_PokeNav_2AC0BD:: @ 82AC0BD
	.string "This is {STR_VAR_1}.\n"
	.string "Hello.\p"
	.string "I was just telling a new TRAINER\n"
	.string "about you.\p"
	.string "I told her about a strong TRAINER\n"
	.string "who raises POKéMON with care.\p"
	.string "I hope you’ll become a TRAINER\n"
	.string "that everyone will admire.\p"
	.string "I hope we meet again!$"

BattleFrontier_PokeNav_2AC18C:: @ 82AC18C
	.string "Hello! It’s {STR_VAR_1}.\p"
	.string "I love where I am now.\n"
	.string "It’s pleasant with sweet aromas!\p"
	.string "I think someone planted BERRIES,\n"
	.string "and they burst into bloom.\p"
	.string "See you again sometime!$"

BattleFrontier_PokeNav_2AC228:: @ 82AC228
	.string "Hello! Thirty years of exploration,\n"
	.string "{STR_VAR_1} at your service!\p"
	.string "It seems that you’re energetically\n"
	.string "traveling here and there.\p"
	.string "Have you discovered any new ruins?\n"
	.string "Please tell if you have!\p"
	.string "Now, if you’ll excuse me,\n"
	.string "I have ruins to explore.$"

BattleFrontier_PokeNav_2AC30C:: @ 82AC30C
	.string "It’s {STR_VAR_1}!\p"
	.string "Know what I’m doing today?\n"
	.string "Looking at waves from the beach!\p"
	.string "Sigh… The waves are all sparkly.\n"
	.string "The sea is the prettiest from here.\l"
	.string "I’m getting hungry, so bye-bye!$"

BattleFrontier_PokeNav_2AC3B6:: @ 82AC3B6
	.string "Munch-chew…\n"
	.string "Oh, hi, it’s {STR_VAR_1}.\l"
	.string "I love eating on the beach.\p"
	.string "My POKéMON and I have been doing\n"
	.string "great. We’re fully fueled!\l"
	.string "I’m going for a swim. Bye!$"

BattleFrontier_PokeNav_2AC446:: @ 82AC446
	.string "Hello, this is {STR_VAR_1}…\p"
	.string "I’ve grown a little jaded with this\n"
	.string "whole COOLTRAINER thing…\p"
	.string "Everyone thinks I’m a perfect\n"
	.string "TRAINER, and that makes me try to\l"
	.string "live up to that expectation.\p"
	.string "But I guess that goes with being\n"
	.string "a COOLTRAINER.\p"
	.string "I’ll just have to buckle down…\n"
	.string "and grin and bear it.\p"
	.string "You’re the only person that I could\n"
	.string "confide in like this.\p"
	.string "But when I see you next,\n"
	.string "don’t worry, I won’t whine!$"

BattleFrontier_PokeNav_2AC5C7:: @ 82AC5C7
	.string "Yahoo, it’s {STR_VAR_1}!\n"
	.string "How do you do?\p"
	.string "I’ve been raising my POKéMON with\n"
	.string "you as the target.\p"
	.string "I don’t intend to lose when we\n"
	.string "battle again.\p"
	.string "Isn’t it great to have TRAINER\n"
	.string "friends? Let’s meet again!$"

BattleFrontier_PokeNav_2AC682:: @ 82AC682
	.string "It’s {STR_VAR_1}…\n"
	.string "Right now, behind you…\l"
	.string "Wasn’t there something…?\p"
	.string "The power of the POKéMON that\n"
	.string "sleep here at MT. PYRE…\p"
	.string "It’s telling me about you…\p"
	.string "You should walk away quickly and\n"
	.string "never once look back…\p"
	.string "Giggle…\n"
	.string "Farewell…$"

BattleFrontier_PokeNav_2AC755:: @ 82AC755
	.string "This is {STR_VAR_1}.\n"
	.string "How do you do?\p"
	.string "Isn’t it convenient that we can\n"
	.string "chat like this at a distance?\p"
	.string "Before, if I wanted to speak with\n"
	.string "anyone, I had to have my father\l"
	.string "drive me…\p"
	.string "I should be going now.\n"
	.string "I’m glad we had this chat.$"

BattleFrontier_PokeNav_2AC82C:: @ 82AC82C
	.string "It’s {STR_VAR_1}!\n"
	.string "Will you listen to this?\p"
	.string "I like the SAFARI ZONE a lot,\n"
	.string "but whenever I go, I get lost!\p"
	.string "All that tall grass!\n"
	.string "And it’s much too spread out!\p"
	.string "I feel better getting that off\n"
	.string "my chest!\p"
	.string "I’m off to the SAFARI ZONE again!\n"
	.string "Catch you!$"

BattleFrontier_PokeNav_2AC914:: @ 82AC914
	.string "Hello, {STR_VAR_1} here.\n"
	.string "Yes, correct, I am rich, yes.\p"
	.string "I should tell you, my wealth has\n"
	.string "grown since we last met.\p"
	.string "What’s more, my POKéMON have also\n"
	.string "grown stronger.\p"
	.string "I can’t shake the feeling that\n"
	.string "this world exists for me!\p"
	.string "Oh, no need to say a word!\n"
	.string "Everyone knows it’s true!\p"
	.string "Oh, you must excuse me, I have this\n"
	.string "formal dinner to attend.$"

BattleFrontier_PokeNav_2ACA59:: @ 82ACA59
	.string "Ufufufufu…\n"
	.string "It’s me, {STR_VAR_1}…\p"
	.string "Can you guess what I’m seeing?\n"
	.string "A pair of {STR_VAR_2} in a battle.\p"
	.string "Maybe I’ll try catching the winner…\n"
	.string "Ufufufufufu…\p"
	.string "I… I’m kind of busy now.\n"
	.string "I have to go.$"

BattleFrontier_PokeNav_2ACB02:: @ 82ACB02
	.string "Oh, it’s {STR_VAR_1}!\p"
	.string "I was just thinking I’m getting\n"
	.string "bored of the ABANDONED SHIP.\p"
	.string "But since I’m already here,\n"
	.string "and I want to beat you once,\l"
	.string "I’ll be sticking around a bit more.\p"
	.string "If you feel compelled, why don’t\n"
	.string "you come see me?\p"
	.string "I think today will be the day that\n"
	.string "I finally challenge the man next\l"
	.string "door to a match.\p"
	.string "Be seeing you!$"

BattleFrontier_PokeNav_2ACC3F:: @ 82ACC3F
	.string "I’m {STR_VAR_1}!\n"
	.string "The man of the sea!\p"
	.string "You know what I think?\p"
	.string "The TRAINERS out at sea are\n"
	.string "the toughest of the tough!\p"
	.string "You should learn from me and train\n"
	.string "in the sea…\p"
	.string "Whoops, giant surf rising!\p"
	.string "It’s a great training opportunity!\n"
	.string "Sorry, but I have to go!$"

BattleFrontier_PokeNav_2ACD2F:: @ 82ACD2F
	.string "It’s {STR_VAR_1}! Listen, I’ve been\n"
	.string "teaching karate to my POKéMON.\p"
	.string "But now they’re better than me!\n"
	.string "I’ve done nothing but lose to them!\p"
	.string "But even though I may lose to\n"
	.string "POKéMON, I won’t lose to another\l"
	.string "TRAINER, no sir!\p"
	.string "We have to battle again!\n"
	.string "Ugwaah!$"

BattleFrontier_PokeNav_2ACE1E:: @ 82ACE1E
	.string "It’s me, {STR_VAR_1}.\n"
	.string "How’re your travels unwinding?\p"
	.string "…Whoa, is that right?\n"
	.string "Sounds awfully stimulating!\p"
	.string "I think I could write a song about\n"
	.string "one of your episodes.\p"
	.string "…Oh, hey, I’m feeling it.\n"
	.string "I hear the riffs in my head.\p"
	.string "I’d better get this tune properly\n"
	.string "written, so I’ve got to fly! Later!$"

BattleFrontier_PokeNav_2ACF32:: @ 82ACF32
	.string "This is {STR_VAR_1}…\n"
	.string "Hear my new song.\p"
	.string "Lalala, {STR_VAR_2}, {STR_VAR_2}!\n"
	.string "Why are you that {STR_VAR_2}?\l"
	.string "Why can’t I be you, {STR_VAR_2}?\l"
	.string "Lala, {STR_VAR_2} and {STR_VAR_1},\l"
	.string "{STR_VAR_1} and {STR_VAR_2}…\p"
	.string "Repeat chorus, fade…$"

BattleFrontier_PokeNav_2ACFBE:: @ 82ACFBE
	.string "I’m {STR_VAR_1}, you know,\n"
	.string "the camping expert!\p"
	.string "When we battled, I couldn’t help\n"
	.string "but lose to you.\p"
	.string "After all, my expertise is in\n"
	.string "camping.\p"
	.string "But win or lose, I like to battle\n"
	.string "when I’m camping.\p"
	.string "Battle with us again, okay?\n"
	.string "Oh, and let’s go camping, too!$"

BattleFrontier_PokeNav_2AD0AC:: @ 82AD0AC
	.string "It’s me, me, {STR_VAR_1}!\p"
	.string "I’d like to climb other mountains\n"
	.string "than this one, to be honest.\p"
	.string "But I’m not sure if there’d be any\n"
	.string "ladies like on MT. CHIMNEY.\p"
	.string "If you know any other mountain\n"
	.string "with ladies around, let me know!\p"
	.string "Ehehehe, see you around!$"

BattleFrontier_PokeNav_2AD194:: @ 82AD194
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "It’s {STR_VAR_1}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "That’s all today…$"

BattleFrontier_PokeNav_2AD1DF:: @ 82AD1DF
	.string "This is {STR_VAR_1}. Today, I had\n"
	.string "this feeling I would chat with you.\p"
	.string "My desire to defeat you builds\n"
	.string "by day and by night.\p"
	.string "You have a rival like that, yes?\n"
	.string "I wish it were me…\p"
	.string "I’m glad you heard me out.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AD2A8:: @ 82AD2A8
	.string "It’s {STR_VAR_1}.\p"
	.string "When there’s a strong TRAINER\n"
	.string "nearby, I can sometimes sense that\l"
	.string "somehow.\p"
	.string "Did you pass close by, {PLAYER}{STRING 5}?\n"
	.string "Maybe it was you.\p"
	.string "I’ll be waiting for your visit.\n"
	.string "Bye!$"

BattleFrontier_PokeNav_2AD34F:: @ 82AD34F
	.string "Hello, this is {STR_VAR_1}.\n"
	.string "You sound well, {PLAYER}{STRING 5}.\p"
	.string "I’ve traveled around the world,\n"
	.string "but I must say I’ve taken a great\l"
	.string "shine to this region.\p"
	.string "I plan to stay here a while.\n"
	.string "Perhaps we can meet again?\p"
	.string "I’ve not forgotten your dazzling\n"
	.string "techniques.\p"
	.string "I do hope for a rematch.$"

BattleFrontier_PokeNav_2AD44E:: @ 82AD44E
	.string "Snivel… It’s… {STR_VAR_1}…\n"
	.string "…Sob…\p"
	.string "ROXANNE chewed me out in class\n"
	.string "today.\p"
	.string "But I don’t dislike her or anything.\p"
	.string "ROXANNE tells me exactly what\n"
	.string "I did wrong so I can learn from it.\p"
	.string "You bet I’ll be going to\n"
	.string "the TRAINER’S SCHOOL tomorrow!\p"
	.string "See you later!$"

BattleFrontier_PokeNav_2AD53A:: @ 82AD53A
	.string "It’s {STR_VAR_1}!\p"
	.string "ROXANNE let me battle with her\n"
	.string "yesterday.\p"
	.string "The results…\n"
	.string "Terrible, like you needed to ask.\p"
	.string "But I was delighted that ROXANNE\n"
	.string "would even let me challenge her!\p"
	.string "You wouldn’t believe how much\n"
	.string "more I admire her!\p"
	.string "I’m going to really focus and work!\n"
	.string "I’d better go!$"

BattleFrontier_PokeNav_2AD642:: @ 82AD642
	.string "Hi, it’s ANNA! I’m with my junior\n"
	.string "partner MEG again today.\p"
	.string "I really love caring for MEG and\n"
	.string "POKéMON. They’re so cute!\p"
	.string "I wish I could look after them\n"
	.string "as if they were my siblings!\p"
	.string "Oh, hi, MEG!\n"
	.string "Did you get the buns?\p"
	.string "Huh? No, no, I’m not treating you\n"
	.string "like my personal slave!\p"
	.string "You lost the match, so you have\n"
	.string "to go buy the bread as punishment!\p"
	.string "I wouldn’t treat you like a slave,\n"
	.string "MEG! You’re too special to me!\p"
	.string "I have to go now.\n"
	.string "It’s time for our snack!$"

BattleFrontier_PokeNav_2AD801:: @ 82AD801
	.string "I love POKéMON!\n"
	.string "It’s {STR_VAR_1} from the FAN CLUB!\p"
	.string "You have to hear this!\n"
	.string "My sweet POKéMON…\p"
	.string "Snort! Wahaha!\n"
	.string "I can’t say any more! It’s a secret!\l"
	.string "It’s just too cute for words!\p"
	.string "Oh, my sweet {STR_VAR_2} is begging\n"
	.string "for a {POKEBLOCK}!\p"
	.string "It’s the picture of cuteness!\p"
	.string "Sorry, but I can’t talk now!\n"
	.string "You’ll have to hear this next time!$"

BattleFrontier_PokeNav_2AD92E:: @ 82AD92E
	.string "Ohoho!\p"
	.string "This is {STR_VAR_1}! I can’t wait to\n"
	.string "tell you about my darling POKéMON!\p"
	.string "Please, you must listen to this.\n"
	.string "It’s about my darling {STR_VAR_2}.\p"
	.string "Whenever anyone picks it up,\n"
	.string "it leaps straight into my arms!\p"
	.string "Oh… Oh… Could there be anything\n"
	.string "more blissful?\p"
	.string "Oh, it feels so heavenly!\p"
	.string "I’m so glad I could share some of\n"
	.string "my happiness with you.\p"
	.string "Well, I must be going.\n"
	.string "Bye, now!$"

BattleFrontier_PokeNav_2ADA8F:: @ 82ADA8F
	.string "I am… {STR_VAR_1}.\n"
	.string "People call me an EXPERT.\p"
	.string "But there is one thing I know.\n"
	.string "I could not be an EXPERT on my own\l"
	.string "power.\p"
	.string "Only with the help of POKéMON can\n"
	.string "a TRAINER become an EXPERT.\p"
	.string "Humph! I believe I may have said\n"
	.string "something deep and profound!\p"
	.string "I shall leave you in good spirits!$"

BattleFrontier_PokeNav_2ADB9B:: @ 82ADB9B
	.string "It’s {STR_VAR_1}.\n"
	.string "I’m glad to chat with you!\p"
	.string "I am feeling alive and refreshed\n"
	.string "soaking in this hot-spring tub.\p"
	.string "I’ve been battling young TRAINERS\n"
	.string "since we met, but you’re still\l"
	.string "the best of the lot.\p"
	.string "I imagine you’ll become an EXPERT\n"
	.string "in your old age! Ohohoho…$"

BattleFrontier_PokeNav_2ADC92:: @ 82ADC92
	.string "Yay! This is {STR_VAR_1}!\n"
	.string "What’s up?\p"
	.string "I might be imagining this, but when\n"
	.string "I win battles, my shorts seem to\l"
	.string "feel, like, better. Materially.\p"
	.string "What do I mean by that?\n"
	.string "It’s kind of hard to explain, but…\l"
	.string "How would I say this now…\l"
	.string "My shorts feel silkier!\p"
	.string "And when I battled you, {PLAYER}{STRING 5},\n"
	.string "my shorts felt icky and coarse.\p"
	.string "… … … … … …\n"
	.string "You didn’t really believe that?\l"
	.string "Ehehehe, that’s all! Bye now!$"

BattleFrontier_PokeNav_2ADE08:: @ 82ADE08
	.string "Ahoy!\n"
	.string "{STR_VAR_1} here!\p"
	.string "As always, I’m fishing with wild\n"
	.string "abandon!\p"
	.string "Are there other places I can fish\n"
	.string "than the sea and rivers?\p"
	.string "I get these powerful urges to\n"
	.string "fish just about anywhere!\p"
	.string "Oh, gosh, darn it!\n"
	.string "My line’s tangled up!\p"
	.string "Gotta go!\n"
	.string "Find me some new fishing spots!$"

BattleFrontier_PokeNav_2ADF07:: @ 82ADF07
	.string "Hey, there! It’s {STR_VAR_1}.\n"
	.string "Are you taking it casually?\p"
	.string "Ever since I was a kid, you know,\n"
	.string "I’ve always been placid, huh?\p"
	.string "I never was much for getting all\n"
	.string "stressed or rushing things.\p"
	.string "But wouldn’t you know it,\n"
	.string "I’m now a TRIATHLETE.\p"
	.string "You just can’t tell where life will\n"
	.string "take you, if you get my drift.\p"
	.string "You’re a TRAINER now, but who\n"
	.string "knows what the future holds, huh?\p"
	.string "Imagine yourself as a teacher,\n"
	.string "or maybe an artist. Cool, huh?\p"
	.string "But, hey, be cool. Take it casual.\n"
	.string "See you around.$"

BattleFrontier_PokeNav_2AE0D9:: @ 82AE0D9
	.string "This is {STR_VAR_1}!\n"
	.string "I’m cycling right now.\p"
	.string "I love swimming and running,\n"
	.string "but cycling is my first love!\p"
	.string "It makes my whole body feel as if\n"
	.string "I’m one with the wind.\p"
	.string "It exhilarates me as if I were\n"
	.string "flying!\p"
	.string "Okay! Today, I’m going to set a new\n"
	.string "CYCLING ROAD record!\p"
	.string "You should make the challenge, too!\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AE1FD:: @ 82AE1FD
	.string "Yo, this is {STR_VAR_1}! I’m smack\n"
	.string "in the middle of a triathlon!\p"
	.string "But, hey, I’ve always got time to\n"
	.string "shoot the breeze!\p"
	.string "Working out with POKéMON feels\n"
	.string "mighty good!\p"
	.string "Without exchanging words, we synch\n"
	.string "as if we shared a heart.\p"
	.string "It’s inspiring!\p"
	.string "Gasp… Chatting while running…\n"
	.string "I’m getting run down…\l"
	.string "Gasp… Have…to…go…$"

BattleFrontier_PokeNav_2AE327:: @ 82AE327
	.string "Hi, it’s {STR_VAR_1}.\n"
	.string "If you want to improve endurance,\l"
	.string "high-altitude training is it!\p"
	.string "Try running on a mountaintop.\n"
	.string "You’ll be gasping in no time!\p"
	.string "I’m getting oxygen starved, too!\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AE3DA:: @ 82AE3DA
	.string "Oh, it’s {STR_VAR_1}, hello.\p"
	.string "I’ve been swimming a lot but I still\n"
	.string "can’t seem to reach EVERGRANDE.\p"
	.string "Maybe I’m just going in circles.\p"
	.string "No, no, that can’t be possible.\n"
	.string "Wahahaha.\l"
	.string "Take care!$"

BattleFrontier_PokeNav_2AE489:: @ 82AE489
	.string "Hey, it’s {STR_VAR_1}…\n"
	.string "Whoops!\p"
	.string "Splash!\p"
	.string "Blug-blug-blug-blug…\p"
	.string "Sploosh!\p"
	.string "Whiff-whiff! Whiff-whiff!\p"
	.string "Hey! Sorry about that!\n"
	.string "I just put on some suntan oil.\p"
	.string "So my POKéNAV went whoopsy\n"
	.string "out of my hand into the water!\p"
	.string "But, boy, DEVON’s POKéNAV is built\n"
	.string "tough. It survived that dunking!\p"
	.string "Anyways, I’m busy sunbathing,\n"
	.string "so let’s chat another time.$"

BattleFrontier_PokeNav_2AE5CD:: @ 82AE5CD
	.string "Hello, this is {STR_VAR_1}.\p"
	.string "Out of the three triathlon events,\n"
	.string "I like swimming best.\p"
	.string "But if I stay in the sea too long,\n"
	.string "won’t I get all prune-like?\p"
	.string "Ooh, triathlon is such a grueling\n"
	.string "test of human endurance! Bye!$"

BattleFrontier_PokeNav_2AE698:: @ 82AE698
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "How are your POKéMON doing?\p"
	.string "My DRAGON POKéMON appear to be\n"
	.string "in peak form. Bye for now.$"

BattleFrontier_PokeNav_2AE704:: @ 82AE704
	.string "{STR_VAR_1} here.\p"
	.string "My {STR_VAR_2} has grown even more\n"
	.string "tough than that last time.\p"
	.string "I’m not going to lose again to you.\n"
	.string "You wait till next time!\p"
	.string "See you around!$"

BattleFrontier_PokeNav_2AE78F:: @ 82AE78F
	.string "It is {STR_VAR_1} here.\p"
	.string "I have continued with my studies\n"
	.string "in the art of concealment.\p"
	.string "But I have been too successful.\n"
	.string "No one has been able to find me.\l"
	.string "My success makes me lonely…\p"
	.string "Like smoke I disappear!\n"
	.string "Farewell!$"

BattleFrontier_PokeNav_2AE859:: @ 82AE859
	.string "This is {STR_VAR_1}.\n"
	.string "I kept up my training since we met.\p"
	.string "My {STR_VAR_2} is getting pretty\n"
	.string "tough.\p"
	.string "Training on a beach is effective,\n"
	.string "just as I thought. Bye now!$"

BattleFrontier_PokeNav_2AE8E6:: @ 82AE8E6
	.string "How do you do?\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I wonder when this yucky volcanic\n"
	.string "ash will stop falling?\p"
	.string "If it gets too deep, it will cover\n"
	.string "up the pattern on my parasol…\p"
	.string "Let’s promise to meet again!$"

BattleFrontier_PokeNav_2AE998:: @ 82AE998
	.string "Hi, {STR_VAR_1} here.\p"
	.string "Did you know that it’s easier to\n"
	.string "float in the sea than a pool?\p"
	.string "Just by lying still, your body will\n"
	.string "float on its own.\p"
	.string "But if you float for too long,\n"
	.string "watch that you don’t get carried\l"
	.string "off too far out.\p"
	.string "…Where am I, anyway?\n"
	.string "I’d better go!$"

BattleFrontier_PokeNav_2AEA8F:: @ 82AEA8F
	.string "Oh, {PLAYER}{STRING 5}, hello!\n"
	.string "This is {STR_VAR_1}.\l"
	.string "I’m up in the mountains now.\p"
	.string "But the ground is too bumpy.\n"
	.string "I can’t pitch my tent here…\p"
	.string "Oh, I had a brilliant idea!\p"
	.string "Maybe I can get my POKéMON to tamp\n"
	.string "the ground flat here!\p"
	.string "I’m going to try that!\n"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2AEB77:: @ 82AEB77
	.string "Oh, hi, hi, this is {STR_VAR_1}!\p"
	.string "I’m raising POKéMON with LIV!\n"
	.string "We’re trying very hard!\p"
	.string "If we try harder, can we become\n"
	.string "number one? Bye-bye!$"

BattleFrontier_PokeNav_2AEBFA:: @ 82AEBFA
	.string "{STR_VAR_1} here!\p"
	.string "I’m a SAILOR, but I’m not on a boat\n"
	.string "now.\p"
	.string "It makes me wonder--what should\n"
	.string "a SAILOR on land be called?\p"
	.string "That’s what I’ve been thinking\n"
	.string "while staring out across the waves.\p"
	.string "All right, next time!$"

BattleFrontier_PokeNav_2AECC1:: @ 82AECC1
	.string "It’s {STR_VAR_1}.\n"
	.string "So? Get any more POKéMON?\p"
	.string "If you catch a new POKéMON,\n"
	.string "you have to come show me.\p"
	.string "I won’t whine for it, honest.\n"
	.string "I’ll be waiting. See you.$"

BattleFrontier_PokeNav_2AED52:: @ 82AED52
	.string "This is {STR_VAR_1}.\p"
	.string "Are you raising your POKéMON\n"
	.string "in the optimal way?\p"
	.string "The air is clean where I am.\n"
	.string "It’s the perfect environment for\l"
	.string "raising POKéMON.\p"
	.string "If you’re going to focus on raising\n"
	.string "POKéMON, you should come out to\l"
	.string "{STR_VAR_2}. Take care now.$"

BattleFrontier_PokeNav_2AEE35:: @ 82AEE35
	.string "Hi, this is {STR_VAR_1}.\p"
	.string "I gave a {POKEBLOCK} to my {STR_VAR_2}.\n"
	.string "It seemed to enjoy it very much.\p"
	.string "It looks like POKéMON have their\n"
	.string "likes and dislikes with {POKEBLOCK}S.\p"
	.string "I find that quite fascinating.\n"
	.string "Please do take care.$"

BattleFrontier_PokeNav_2AEEF4:: @ 82AEEF4
	.string "{STR_VAR_1} here.\p"
	.string "If you cooperate with POKéMON,\n"
	.string "one can be comfortable in the wild.\p"
	.string "Everyone should realize that and\n"
	.string "cooperate with POKéMON more.\p"
	.string "That would be ideal.\n"
	.string "I really think so.\p"
	.string "I think you’re on the right track!\n"
	.string "Catch you later!$"

BattleFrontier_PokeNav_2AEFDA:: @ 82AEFDA
	.string "Hi, it’s {STR_VAR_1}. You know,\n"
	.string "the TRAINER who’s always prepared!\p"
	.string "{PLAYER}{STRING 5}, do you have enough items?\n"
	.string "Are your POKéMON fit for action?\p"
	.string "Keeping everything perfect around\n"
	.string "you all the time is the secret to\l"
	.string "keeping your journey going.\p"
	.string "I’d better go check my own\n"
	.string "supplies! Be vigilant!$"

BattleFrontier_PokeNav_2AF0E7:: @ 82AF0E7
	.string "It’s {STR_VAR_1}!\n"
	.string "It’s {STR_VAR_1}!\p"
	.string "{STR_VAR_2} is a very busy\n"
	.string "thoroughfare, so I get challenged\l"
	.string "by all kinds of TRAINERS every day.\p"
	.string "Today, I won five battles and lost\n"
	.string "only three!\p"
	.string "How did you do today?\n"
	.string "Tell me about it next time, okay?$"

BattleFrontier_PokeNav_2AF1B8:: @ 82AF1B8
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I’m popular because I have lots\n"
	.string "of BUG POKéMON, right?\p"
	.string "Well, I took a bunch of my fave\n"
	.string "bugs to school today.\p"
	.string "This girl I like started crying!\n"
	.string "Go ahead and laugh if you want.\p"
	.string "I have to try teaching her what\n"
	.string "makes BUG POKéMON so appealing.\p"
	.string "Snivel…\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AF2C4:: @ 82AF2C4
	.string "Hah! Hah! Hah! Hah!\p"
	.string "Hi! It’s {STR_VAR_1}! Hah! Hah!\p"
	.string "Trying to chat…\n"
	.string "While climbing…\l"
	.string "Is harsh exercise… Hah! Hah!\p"
	.string "Urgh! Oof…\n"
	.string "It’s steeper now…\l"
	.string "We’ll chat…another time…\l"
	.string "Hah! Hah! Hah!$"

BattleFrontier_PokeNav_2AF371:: @ 82AF371
	.string "Oh, hi!\p"
	.string "I’m still searching for treasures\n"
	.string "with KIRA!\p"
	.string "Maybe there isn’t any treasure\n"
	.string "here at all…\p"
	.string "But the important thing is for me\n"
	.string "to search alongside KIRA.\p"
	.string "Oh, hey, KIRA!\n"
	.string "Wh-why are you angry?\p"
	.string "I’m not ignoring you, honey!\n"
	.string "You’re my one and only!\p"
	.string "…{PLAYER}, I have to go, bye!$"

BattleFrontier_PokeNav_2AF480:: @ 82AF480
	.string "This is {STR_VAR_1}!\p"
	.string "I went to DEWFORD’s GYM again\n"
	.string "for training.\p"
	.string "BRAWLY, the GYM LEADER, seems\n"
	.string "to be tougher now.\p"
	.string "Something about being toughened\n"
	.string "by the wild waves…\p"
	.string "But he’s still as cool as ever.\n"
	.string "The ladies adore him!\l"
	.string "It makes me envious, frankly.\p"
	.string "I wonder… Is his friend BRUNO\n"
	.string "the same way as BRAWLY?\p"
	.string "You know, all sweaty or smelly,\n"
	.string "and prone to calling people\l"
	.string "“big wave,” that sort of thing.\p"
	.string "But, hey, this jealousy thing isn’t\n"
	.string "very seemly, is it?\p"
	.string "Forget this chat ever happened,\n"
	.string "how about it? So long!$"

BattleFrontier_PokeNav_2AF671:: @ 82AF671
	.string "It’s a pleasure to chat with\n"
	.string "a young TRAINER like you.\p"
	.string "I imagine that you will continue to\n"
	.string "enjoy POKéMON whatever your age.\p"
	.string "Wouldn’t it be good if you had\n"
	.string "a partnership like ours?\p"
	.string "Of course, {PLAYER}{STRING 5}, you already\n"
	.string "enjoy the trust and companionship\l"
	.string "of your POKéMON now.\p"
	.string "You have the makings of long and\n"
	.string "enduring relationships already!\p"
	.string "Hahaha!\n"
	.string "Never be discouraged!$"

BattleFrontier_PokeNav_2AF7D8:: @ 82AF7D8
	.string "Hi, this is {STR_VAR_1}!\n"
	.string "We just won a battle!\p"
	.string "We don’t win often, but it was this\n"
	.string "cool SWIMMER guy.\p"
	.string "My sister was steamed!\p"
	.string "She wanted to pretend that she\n"
	.string "was weak to make an impression!\p"
	.string "She always chews me out whether\n"
	.string "we win or lose!\p"
	.string "{PLAYER}{STRING 5}, can you say something\n"
	.string "to her next time?\p"
	.string "Okay, see you!$"

BattleFrontier_PokeNav_2AF8F7:: @ 82AF8F7
	.string "{STR_VAR_1} here, yes.\n"
	.string "I headed out to sea yesterday.\p"
	.string "I had been hoping to find a new\n"
	.string "ruin to explore.\p"
	.string "But the tides somehow seemed to\n"
	.string "carry me back where I started.\p"
	.string "I’m still weak at battling, too…\n"
	.string "Feel free to mock me…\l"
	.string "But I won’t give up.\p"
	.string "My day will come when I discover\n"
	.string "a new ruin!\p"
	.string "That’s all I have to say!\n"
	.string "Farewell for now!$"

BattleFrontier_PokeNav_2AFA39:: @ 82AFA39
	.string "Ahoy there!\n"
	.string "It’s me, {STR_VAR_1}!\l"
	.string "I’m out on ROUTE 108 now!\l"
	.string "In other words, where I always am!\p"
	.string "Today, a gorgeous SWIMMER \n"
	.string "swam by me!\p"
	.string "So I startled her with a shout!\p"
	.string "And she gave me a nasty glare!\p"
	.string "That’s all from ROUTE 108!\n"
	.string "Brought to you by {STR_VAR_1}!$"

BattleFrontier_PokeNav_2AFB26:: @ 82AFB26
	.string "It’s {STR_VAR_1}!\p"
	.string "I’m kind of busy, but I figured\n"
	.string "I should let you know that I’ve\l"
	.string "beaten five TRAINERS again today.\p"
	.string "If I keep this pace up, I can\n"
	.string "probably beat you next time.\p"
	.string "I think we’ll be good rivals,\n"
	.string "you and I. Good-bye for now!$"

BattleFrontier_PokeNav_2AFC07:: @ 82AFC07
	.string "Hi! This is {STR_VAR_1}.\n"
	.string "I heard the news!\p"
	.string "They say you did excellent at\n"
	.string "the {STR_VAR_2}.\p"
	.string "It’s awesome, {STR_VAR_3} straight wins?\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AFC78:: @ 82AFC78
	.string "Hello, it’s {STR_VAR_1}!\n"
	.string "I heard about you!\p"
	.string "They said you won {STR_VAR_3} straight\n"
	.string "battles at the {STR_VAR_2}.\p"
	.string "That’s special! I should try\n"
	.string "harder, too! See you!$"

BattleFrontier_PokeNav_2AFCFF:: @ 82AFCFF
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I heard you went on a tear at\n"
	.string "the {STR_VAR_2}!\p"
	.string "A big {STR_VAR_3}-win streak…\n"
	.string "That is a big record, isn’t it?\p"
	.string "I’d better get it together, too!\n"
	.string "Catch you soon!$"

BattleFrontier_PokeNav_2AFDA7:: @ 82AFDA7
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here. What’s up?\p"
	.string "There’s a rumor going around that\n"
	.string "you strung together {STR_VAR_3} straight\l"
	.string "wins at the {STR_VAR_2}.\p"
	.string "I’d better step it up, too.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2AFE3D:: @ 82AFE3D
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "You were at the {STR_VAR_2}\n"
	.string "and won {STR_VAR_3} battles in a row?\l"
	.string "Isn’t that something!\p"
	.string "I’d better work on my POKéMON more.\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2AFECA:: @ 82AFECA
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here. How are you?\p"
	.string "By the way, I heard you pulled off\n"
	.string "the feat of {STR_VAR_3} straight wins at\l"
	.string "the {STR_VAR_2}.\p"
	.string "That inspires me to focus on\n"
	.string "raising my team.$"

BattleFrontier_PokeNav_2AFF64:: @ 82AFF64
	.string "…Er, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here…\p"
	.string "Oh, yeah, you were over at\n"
	.string "the {STR_VAR_2}, right?\p"
	.string "And you won {STR_VAR_3} battles in a row.\p"
	.string "Oh, there goes a rare POKéMON!\n"
	.string "I have to go!$"

BattleFrontier_PokeNav_2AFFF0:: @ 82AFFF0
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\l"
	.string "I hope you’re doing well.\p"
	.string "Oh, but, you are. I’ve heard that\n"
	.string "you won {STR_VAR_3} matches in a row at\l"
	.string "the {STR_VAR_2}.\p"
	.string "That’s very impressive!\n"
	.string "I hope you stay successful.$"

BattleFrontier_PokeNav_2B00B5:: @ 82B00B5
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I heard! Your {STR_VAR_3}-win streak at\n"
	.string "the {STR_VAR_2}!\p"
	.string "That is so cool!\n"
	.string "I’d better try harder, too!$"

BattleFrontier_PokeNav_2B0129:: @ 82B0129
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You won {STR_VAR_3} straight battles at\n"
	.string "the {STR_VAR_2}?\p"
	.string "That’s quite the accomplishment.\n"
	.string "I need to work harder.$"

BattleFrontier_PokeNav_2B01A5:: @ 82B01A5
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I hear you’re the terror of\n"
	.string "the {STR_VAR_2}?\p"
	.string "You won, what, {STR_VAR_3} matches in\n"
	.string "a row?\p"
	.string "You’re good, you.\n"
	.string "I wonder how many I can win?$"

BattleFrontier_PokeNav_2B0232:: @ 82B0232
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you keeping well?\p"
	.string "Someone passed on word about you.\n"
	.string "How you won {STR_VAR_3} straight battles\l"
	.string "at a place named {STR_VAR_2}?\p"
	.string "That’s quite the tale.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B02D9:: @ 82B02D9
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "I hope you’ve been keeping well.\p"
	.string "They say you won {STR_VAR_3} straight\n"
	.string "battles at the {STR_VAR_2}.\p"
	.string "I admire your energy!\n"
	.string "Bye now.$"

BattleFrontier_PokeNav_2B0366:: @ 82B0366
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I heard about you!\n"
	.string "Didn’t you just win {STR_VAR_3} battles in\l"
	.string "a row at the {STR_VAR_2}?\p"
	.string "You’re an inspiration!\n"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2B03E6:: @ 82B03E6
	.string "Hi! This is {STR_VAR_1}.\n"
	.string "I heard the news!\p"
	.string "They say you did excellent at\n"
	.string "the {STR_VAR_2}.\p"
	.string "It’s awesome--{STR_VAR_3} straight wins?\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B0457:: @ 82B0457
	.string "Hello, it’s {STR_VAR_1}!\n"
	.string "I heard about you!\p"
	.string "They said you won {STR_VAR_3} straight\n"
	.string "battles at the {STR_VAR_2}.\p"
	.string "That’s special! I should try\n"
	.string "harder, too! See you!$"

BattleFrontier_PokeNav_2B04DE:: @ 82B04DE
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\p"
	.string "I heard you went on a tear at\n"
	.string "the {STR_VAR_2}!\p"
	.string "A big {STR_VAR_3}-win streak…\n"
	.string "That is a big record, isn’t it?\p"
	.string "I’d better get it together, too!\n"
	.string "Catch you soon!$"

BattleFrontier_PokeNav_2B0586:: @ 82B0586
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here. What’s up?\p"
	.string "There’s a rumor going around that\n"
	.string "you strung together {STR_VAR_3} straight\l"
	.string "wins at the {STR_VAR_2}.\p"
	.string "I’d better step it up, too.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B061C:: @ 82B061C
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "You were at the {STR_VAR_2}\n"
	.string "and won {STR_VAR_3} battles in a row?\l"
	.string "Isn’t that something!\p"
	.string "Me? I’d say I’m coming along.\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2B06A3:: @ 82B06A3
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here. How are you?\p"
	.string "By the way, I heard you pulled off\n"
	.string "the feat of {STR_VAR_3} straight wins at\l"
	.string "the {STR_VAR_2}.\p"
	.string "I’d better try harder myself!\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2B073B:: @ 82B073B
	.string "…Er, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here…\p"
	.string "Oh, yeah, you were over at\n"
	.string "the {STR_VAR_2}, right?\p"
	.string "And you won {STR_VAR_3} battles in a row.\p"
	.string "Oh, there goes a rare POKéMON!\n"
	.string "I have to go!$"

BattleFrontier_PokeNav_2B07C7:: @ 82B07C7
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\l"
	.string "I hope you’re doing well.\p"
	.string "Oh, but, you are. I’ve heard that\n"
	.string "you won {STR_VAR_3} matches in a row at\l"
	.string "the {STR_VAR_2}.\p"
	.string "That’s very impressive!\n"
	.string "I’d better work on my POKéMON, too!$"

BattleFrontier_PokeNav_2B0894:: @ 82B0894
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I heard! Your {STR_VAR_3}-win streak at\n"
	.string "the {STR_VAR_2}!\p"
	.string "That is so cool!\n"
	.string "I’d better try harder, too!$"

BattleFrontier_PokeNav_2B0908:: @ 82B0908
	.string "Oh, {PLAYER}{STRING 5}, hello…\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You won {STR_VAR_3} straight battles at\n"
	.string "the {STR_VAR_2}?\p"
	.string "That’s quite the accomplishment.\n"
	.string "I need to work harder.$"

BattleFrontier_PokeNav_2B0984:: @ 82B0984
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I hear you’re the terror of\n"
	.string "the {STR_VAR_2}?\p"
	.string "You won, what, {STR_VAR_3} matches in\n"
	.string "a row?\p"
	.string "You’re good, you.\n"
	.string "I wonder how many I can win?$"

BattleFrontier_PokeNav_2B0A11:: @ 82B0A11
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you keeping well?\p"
	.string "Someone passed on word about you.\n"
	.string "How you won {STR_VAR_3} straight battles\l"
	.string "at a place named {STR_VAR_2}?\p"
	.string "That’s quite the tale.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B0AB8:: @ 82B0AB8
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "I hope you’ve been keeping well.\p"
	.string "They say you won {STR_VAR_3} straight\n"
	.string "battles at the {STR_VAR_2}.\p"
	.string "I admire your energy!\n"
	.string "Bye now.$"

BattleFrontier_PokeNav_2B0B45:: @ 82B0B45
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "I heard about you!\p"
	.string "Didn’t you just win {STR_VAR_3} battles in\n"
	.string "a row at the {STR_VAR_2}?\p"
	.string "You’re an inspiration!\n"
	.string "Bye-bye!$"

BattleFrontier_PokeNav_2B0BC5:: @ 82B0BC5
	.string "Hi! {PLAYER}?\n"
	.string "Hello, this is {STR_VAR_1}!\l"
	.string "I heard the news!\p"
	.string "You became the champion at\n"
	.string "the {STR_VAR_2} {STR_VAR_3} times?\p"
	.string "It’s awesome! I have to do better!\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B0C4A:: @ 82B0C4A
	.string "Hello, it’s {STR_VAR_1}!\n"
	.string "I heard about you!\p"
	.string "They said you won {STR_VAR_3} titles\n"
	.string "at the {STR_VAR_2}.\p"
	.string "That’s super! I wonder if I can\n"
	.string "become a champion?$"

BattleFrontier_PokeNav_2B0CC7:: @ 82B0CC7
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "How’s it going?\p"
	.string "I heard you won events {STR_VAR_3} times\n"
	.string "at the {STR_VAR_2}!\p"
	.string "Make it one more next time!\n"
	.string "Catch you soon!$"

BattleFrontier_PokeNav_2B0D4A:: @ 82B0D4A
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "I heard you became the champion\n"
	.string "at the {STR_VAR_2} {STR_VAR_3} times.\p"
	.string "Sounds like you’re working hard.\n"
	.string "I’ll try to keep up!$"

BattleFrontier_PokeNav_2B0DC8:: @ 82B0DC8
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "I heard you won {STR_VAR_3} times\n"
	.string "outright at the {STR_VAR_2}.\p"
	.string "I’d better get with it, too!\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2B0E35:: @ 82B0E35
	.string "Hey, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here. How are you?\p"
	.string "By the way, I heard you became\n"
	.string "the champion {STR_VAR_3} times at\l"
	.string "the {STR_VAR_2}.\p"
	.string "I’d better raise my POKéMON before\n"
	.string "you pull farther ahead.$"

BattleFrontier_PokeNav_2B0ED1:: @ 82B0ED1
	.string "{PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here.\p"
	.string "You were at the {STR_VAR_2}\n"
	.string "and became the champ {STR_VAR_3} times?\p"
	.string "That’s neat. By the way, have you\n"
	.string "caught any rare POKéMON lately?\p"
	.string "Oh, is that right.\n"
	.string "Okay, bye.$"

BattleFrontier_PokeNav_2B0F72:: @ 82B0F72
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\l"
	.string "I hope you’re doing well.\l"
	.string "Oh, but, you are.\p"
	.string "I’ve heard that you won {STR_VAR_3} titles\n"
	.string "at the {STR_VAR_2}.\p"
	.string "I must raise my POKéMON like you.\n"
	.string "See you again.$"

BattleFrontier_PokeNav_2B102A:: @ 82B102A
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I heard! You took the title\n"
	.string "{STR_VAR_3} times at the {STR_VAR_2}!\p"
	.string "That is so cool!\n"
	.string "I’d better try harder, too!$"

BattleFrontier_PokeNav_2B10A7:: @ 82B10A7
	.string "Oh, {PLAYER}{STRING 5}, hello.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You won {STR_VAR_3} straight times at\n"
	.string "the {STR_VAR_2}?\p"
	.string "That’s quite the accomplishment.\n"
	.string "I need to work harder.$"

BattleFrontier_PokeNav_2B1121:: @ 82B1121
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I hear you’re the terror of\n"
	.string "the {STR_VAR_2}?\p"
	.string "You won, what, {STR_VAR_3} straight times\n"
	.string "now?\p"
	.string "I wonder if I can ever become\n"
	.string "a champion?\p"
	.string "…Pretty well impossible?\n"
	.string "Well, see you!$"

BattleFrontier_PokeNav_2B11D3:: @ 82B11D3
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you keeping well?\p"
	.string "You’ve won {STR_VAR_3} events at a place\n"
	.string "named {STR_VAR_2}?\p"
	.string "That’s quite the tale.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B124D:: @ 82B124D
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "I hope you’ve been keeping well.\p"
	.string "They say you won {STR_VAR_3} events\n"
	.string "at the {STR_VAR_2}?\p"
	.string "I admire your energy!\n"
	.string "Bye now.$"

BattleFrontier_PokeNav_2B12D0:: @ 82B12D0
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "I heard about you!\p"
	.string "Didn’t you win {STR_VAR_3} titles\n"
	.string "at the {STR_VAR_2}?\p"
	.string "You’re an inspiration!\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2B1347:: @ 82B1347
	.string "Hi! {PLAYER}?\n"
	.string "Hello, this is {STR_VAR_1}!\l"
	.string "I heard the news!\p"
	.string "You got through {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}!\p"
	.string "That’s awesome!\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B13B1:: @ 82B13B1
	.string "Hello, it’s {STR_VAR_1}!\n"
	.string "I heard about you!\p"
	.string "They said you won your way through\n"
	.string "{STR_VAR_3} rooms at the {STR_VAR_2}.\p"
	.string "I have to try much harder!\n"
	.string "Bye!$"

BattleFrontier_PokeNav_2B142B:: @ 82B142B
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "How’s it going?\p"
	.string "I heard you won through {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}!\p"
	.string "Try to do even better next time!\n"
	.string "Catch you soon!$"

BattleFrontier_PokeNav_2B14B4:: @ 82B14B4
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "I heard you blew through {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}.\p"
	.string "I’d better train my POKéMON and\n"
	.string "try to keep up!$"

BattleFrontier_PokeNav_2B1525:: @ 82B1525
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "I heard you got past {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}.\p"
	.string "I’d better get with it, too!\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2B158E:: @ 82B158E
	.string "Hey, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here. How are you?\p"
	.string "By the way, I heard you got through\n"
	.string "{STR_VAR_3} rooms at the {STR_VAR_2}.\p"
	.string "I’d better raise my POKéMON before\n"
	.string "you pull further ahead.$"

BattleFrontier_PokeNav_2B1622:: @ 82B1622
	.string "{PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here.\p"
	.string "You were at the {STR_VAR_2}\n"
	.string "and won your way past {STR_VAR_3} rooms?\p"
	.string "That’s wicked.\p"
	.string "Oh, there goes a rare POKéMON!\n"
	.string "Okay, bye.$"

BattleFrontier_PokeNav_2B169D:: @ 82B169D
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\l"
	.string "I hope you’re doing well.\l"
	.string "Oh, but, you are.\p"
	.string "I’ve heard that you got through\n"
	.string "{STR_VAR_3} rooms at the {STR_VAR_2}.\p"
	.string "That’s quite impressive!\n"
	.string "I must raise my POKéMON like you.\l"
	.string "See you again.$"

BattleFrontier_PokeNav_2B1775:: @ 82B1775
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I heard! You won your way through\n"
	.string "{STR_VAR_3} rooms at the {STR_VAR_2}!\p"
	.string "That is so cool!\n"
	.string "I’d better try harder, too!$"

BattleFrontier_PokeNav_2B17F8:: @ 82B17F8
	.string "Oh, {PLAYER}{STRING 5}, hello.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You won your way past {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}?\p"
	.string "That’s quite the accomplishment.\n"
	.string "I need to work harder.$"

BattleFrontier_PokeNav_2B1877:: @ 82B1877
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I hear you’re the terror of\n"
	.string "the {STR_VAR_2}?\p"
	.string "You got through, what, {STR_VAR_3} rooms?\n"
	.string "That’s gotta count for something.\p"
	.string "I wonder if I can ever become\n"
	.string "a champion?\p"
	.string "…Pretty well impossible?\n"
	.string "Well, see you!$"

BattleFrontier_PokeNav_2B1946:: @ 82B1946
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you keeping well?\p"
	.string "You’ve won through {STR_VAR_3} rooms at\n"
	.string "a place named {STR_VAR_2}?\p"
	.string "That’s quite the tale.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B19C7:: @ 82B19C7
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "I hope you’ve been keeping well.\p"
	.string "They say you won in {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}?\p"
	.string "I admire your energy!\n"
	.string "Bye now.$"

BattleFrontier_PokeNav_2B1A4C:: @ 82B1A4C
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "I heard about you!\p"
	.string "Didn’t you get through {STR_VAR_3} rooms\n"
	.string "at the {STR_VAR_2}?\p"
	.string "You’re an inspiration!\n"
	.string "See you again!$"

BattleFrontier_PokeNav_2B1ACA:: @ 82B1ACA
	.string "Hi! {PLAYER}?\n"
	.string "Hello, this is {STR_VAR_1}!\l"
	.string "I heard the news!\p"
	.string "You climbed {STR_VAR_3} floors inside\n"
	.string "the {STR_VAR_2}, right?\p"
	.string "That’s awesome!\n"
	.string "I should try that challenge.$"

BattleFrontier_PokeNav_2B1B50:: @ 82B1B50
	.string "Hello, it’s {STR_VAR_1}!\n"
	.string "I heard about you!\p"
	.string "They said you won your way through\n"
	.string "{STR_VAR_3} floors in the {STR_VAR_2}.\p"
	.string "Wow, that’s fantastic!\n"
	.string "I’d better raise my POKéMON, too!$"

BattleFrontier_PokeNav_2B1BE4:: @ 82B1BE4
	.string "Hey there, {PLAYER}!\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "How’s it going?\p"
	.string "I heard you climbed {STR_VAR_3} floors\n"
	.string "in the {STR_VAR_2}!\p"
	.string "Try to do even better next time!\n"
	.string "Catch you soon!$"

BattleFrontier_PokeNav_2B1C6A:: @ 82B1C6A
	.string "Hey, {PLAYER}{STRING 5}.\n"
	.string "{STR_VAR_1} here.\p"
	.string "I heard you scaled {STR_VAR_3} floors\n"
	.string "in the {STR_VAR_2}.\p"
	.string "I’d better work hard and try\n"
	.string "to keep up!$"

BattleFrontier_PokeNav_2B1CCF:: @ 82B1CCF
	.string "Hiya, {PLAYER}{STRING 5}!\n"
	.string "It’s {STR_VAR_1}.\p"
	.string "I heard you climbed {STR_VAR_3} floors\n"
	.string "in the {STR_VAR_2}.\p"
	.string "I’d better get with it, too!\n"
	.string "See you soon!$"

BattleFrontier_PokeNav_2B1D38:: @ 82B1D38
	.string "Hey, {PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here. How are you?\p"
	.string "By the way, I heard you got through\n"
	.string "{STR_VAR_3} floors in the {STR_VAR_2}.\p"
	.string "I’d better raise my POKéMON before\n"
	.string "you pull further ahead.$"

BattleFrontier_PokeNav_2B1DCD:: @ 82B1DCD
	.string "{PLAYER}{STRING 5}?\n"
	.string "{STR_VAR_1} here.\p"
	.string "You were at the {STR_VAR_2}\n"
	.string "and won your way up {STR_VAR_3} floors?\p"
	.string "Neat. Were there any rare POKéMON\n"
	.string "there?\p"
	.string "No, huh?\n"
	.string "Okay, bye.$"

BattleFrontier_PokeNav_2B1E4B:: @ 82B1E4B
	.string "Oh, {PLAYER}{STRING 5}, how do you do?\n"
	.string "This is {STR_VAR_1} speaking.\l"
	.string "I hope you’re doing well.\l"
	.string "Oh, but, you are.\p"
	.string "I’ve heard that you got through\n"
	.string "{STR_VAR_3} floors in the {STR_VAR_2}.\p"
	.string "That’s quite impressive!\n"
	.string "I must raise my POKéMON like you.\l"
	.string "See you again.$"

BattleFrontier_PokeNav_2B1F24:: @ 82B1F24
	.string "Oh, {PLAYER}{STRING 5}, hi there!\n"
	.string "This is {STR_VAR_1}!\p"
	.string "I heard! You won your way through\n"
	.string "{STR_VAR_3} floors in the {STR_VAR_2}!\p"
	.string "That is so cool!\n"
	.string "I’d better try harder, too!$"

BattleFrontier_PokeNav_2B1FA8:: @ 82B1FA8
	.string "Oh, {PLAYER}{STRING 5}, hello.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "You climbed {STR_VAR_3} floors inside\n"
	.string "the {STR_VAR_2}?\p"
	.string "That’s quite the accomplishment.\n"
	.string "I need to work harder.$"

BattleFrontier_PokeNav_2B2022:: @ 82B2022
	.string "Ah, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\p"
	.string "I hear you’re the terror of\n"
	.string "the {STR_VAR_2}?\p"
	.string "You rose through, what, {STR_VAR_3} floors?\n"
	.string "That’s gotta count for something.\p"
	.string "I wonder if I can ever become\n"
	.string "a champion?\p"
	.string "…Pretty well impossible?\n"
	.string "Well, see you!$"

BattleFrontier_PokeNav_2B20F3:: @ 82B20F3
	.string "Hello, {PLAYER}{STRING 5}.\n"
	.string "It’s me, {STR_VAR_1}.\l"
	.string "Are you keeping well?\p"
	.string "You’ve won through {STR_VAR_3} floors in\n"
	.string "a place named {STR_VAR_2}?\p"
	.string "That’s quite the tale.\n"
	.string "See you!$"

BattleFrontier_PokeNav_2B2175:: @ 82B2175
	.string "Ah, hello, {PLAYER}{STRING 5}!\n"
	.string "This is {STR_VAR_1}!\l"
	.string "I hope you’ve been keeping well.\p"
	.string "They say you climbed {STR_VAR_3} floors\n"
	.string "in the {STR_VAR_2}?\p"
	.string "I admire your energy!\n"
	.string "Bye now.$"

BattleFrontier_PokeNav_2B21FC:: @ 82B21FC
	.string "Oh, hi, {PLAYER}{STRING 5}.\n"
	.string "This is {STR_VAR_1}.\l"
	.string "I heard about you!\p"
	.string "Didn’t you get through {STR_VAR_3} floors\n"
	.string "in the {STR_VAR_2}?\p"
	.string "You’re an inspiration!\n"
	.string "See you again!$"

gText_Mom_Pokenav_2B227B:: @ 82B227B
	.string "MOM: Your father and you…\n"
	.string "Everyone is captivated by POKéMON.\p"
	.string "What is the charm of POKéMON?\p"
	.string "Me?\n"
	.string "I adore POKéMON that help me with\l"
	.string "my everyday chores.$"

gText_Mom_Pokenav_2B2310:: @ 82B2310
	.string "MOM: Hi, {PLAYER}!\n"
	.string "Your father keeps himself locked\l"
	.string "away in the PETALBURG GYM.\p"
	.string "He comes home every so often.\n"
	.string "But he goes back to the GYM when\l"
	.string "he’s eaten everything he can.\p"
	.string "I’m guessing that losing to you\n"
	.string "was a big blow to his pride!$"

gText_Mom_Pokenav_2B23F3:: @ 82B23F3
	.string "MOM: {PLAYER}…\n"
	.string "Don’t worry about me or the house.\p"
	.string "Wear those RUNNING SHOES until\n"
	.string "they fall apart, honey!$"

gText_Roxanne_Pokenav_2B2456:: @ 82B2456
	.string "ROXANNE: Oh, hello, {PLAYER}!\p"
	.string "I’ve been hard at work retraining\n"
	.string "since we met.\p"
	.string "I will still need some more time\n"
	.string "before I can reopen the GYM.\p"
	.string "But when I do, please visit my GYM\n"
	.string "for a rematch!$"

gText_Roxanne_Pokenav_2B250E:: @ 82B250E
	.string "ROXANNE: Is this {PLAYER}?\n"
	.string "Congratulations!\l"
	.string "I’ve been hearing about you!\p"
	.string "As for me, I need some more time\n"
	.string "before I can reopen the GYM.\p"
	.string "But when I do, please visit my GYM\n"
	.string "for a rematch!$"

gText_Roxanne_Pokenav_2B25C1:: @ 82B25C1
	.string "ROXANNE: {PLAYER}!\n"
	.string "My GYM is ready!\p"
	.string "Please visit RUSTBORO whenever\n"
	.string "you can!$"

gText_Roxanne_Pokenav_2B2607:: @ 82B2607
	.string "ROXANNE: At the RUSTBORO GYM,\n"
	.string "the fact that we battled, {PLAYER},\l"
	.string "is a matter of pride.$"

gText_Brawly_Pokenav_2B2659:: @ 82B2659
	.string "BRAWLY: Hey, there, {PLAYER}{STRING 5}!\p"
	.string "I learned a lot from the battle we\n"
	.string "had together.\p"
	.string "I intend to do my training over,\n"
	.string "then reopen the GYM.\p"
	.string "It’s going to take some time before\n"
	.string "I’m ready to run the GYM again.\p"
	.string "But if I can reopen the GYM,\n"
	.string "I want you to challenge us again.$"

gText_Brawly_Pokenav_2B275D:: @ 82B275D
	.string "BRAWLY: Hey, {PLAYER}{STRING 5}!\n"
	.string "Congratulations!\p"
	.string "Word about your exploits arrived\n"
	.string "on tidal winds!\p"
	.string "It appears as if I need to work on\n"
	.string "my training some more.\p"
	.string "It’s going to take some time before\n"
	.string "I’m ready to run the GYM again.\p"
	.string "But if I can reopen the GYM,\n"
	.string "I want you to challenge us again.$"

gText_Brawly_Pokenav_2B286F:: @ 82B286F
	.string "BRAWLY: Hey, {PLAYER}{STRING 5}!\n"
	.string "My GYM’s ready for action!\p"
	.string "Come back to DEWFORD anytime\n"
	.string "for another challenge!$"

gText_Brawly_Pokenav_2B28D1:: @ 82B28D1
	.string "BRAWLY: {PLAYER}{STRING 5}, I don’t think\n"
	.string "I’ll ever get bored of battling you!$"

gText_Wattson_Pokenav_2B2912:: @ 82B2912
	.string "WATTSON: Oh, it’s you!\p"
	.string "After you left, I’ve been redoing\n"
	.string "my training from scratch.\p"
	.string "I’d say I could use a wee bit more\n"
	.string "time to reopen my GYM.\p"
	.string "You’ll have to wait till then!\n"
	.string "Wahahahaha!$"

gText_Wattson_Pokenav_2B29CA:: @ 82B29CA
	.string "WATTSON: Wahahahaha!\p"
	.string "You’ve really done it, haven’t you?\n"
	.string "I’ve been getting word about you!\p"
	.string "It seems I need to retrain some\n"
	.string "more still.\p"
	.string "I’d say I could use a wee bit more\n"
	.string "time to reopen my GYM.\p"
	.string "You’ll have to wait till then!\n"
	.string "Wahahahaha!$"

gText_Wattson_Pokenav_2B2AB6:: @ 82B2AB6
	.string "WATTSON: Oh, it’s you!\n"
	.string "My GYM’s ready!\p"
	.string "Visit MAUVILLE anytime!\n"
	.string "Wahahahaha!$"

gText_Wattson_Pokenav_2B2B01:: @ 82B2B01
	.string "WATTSON: Wahahaha!\p"
	.string "A battle with you is always charged\n"
	.string "with shocking power!$"

gText_Flannery_Pokenav_2B2B4D:: @ 82B2B4D
	.string "FLANNERY: {PLAYER}…\p"
	.string "When we battled, I learned exactly\n"
	.string "how immature I was.\p"
	.string "But I’m not done yet!\p"
	.string "I’m going to redo my training and\n"
	.string "reopen the GYM.\p"
	.string "When the time comes, {PLAYER},\n"
	.string "please challenge us again.$"

gText_Flannery_Pokenav_2B2C0E:: @ 82B2C0E
	.string "FLANNERY: Hello, {PLAYER}?\n"
	.string "Congratulations!\p"
	.string "Word of your success has reached\n"
	.string "us like the heat of a volcano!\p"
	.string "Our training is coming along very\n"
	.string "well here.\p"
	.string "When the GYM’s ready, a mark will\n"
	.string "appear beside my name in the\l"
	.string "MATCH CALL list.$"

gText_Flannery_Pokenav_2B2CF1:: @ 82B2CF1
	.string "FLANNERY: Oh, {PLAYER}?\n"
	.string "Our GYM’s ready!\p"
	.string "Come to LAVARIDGE for a soak\n"
	.string "in the hot spring and a challenge!$"

gText_Flannery_Pokenav_2B2D54:: @ 82B2D54
	.string "FLANNERY: {PLAYER}…\n"
	.string "I’m positive that you keep getting\l"
	.string "better at training every time.$"

gText_Winona_Pokenav_2B2DA4:: @ 82B2DA4
	.string "WINONA: Hello, {PLAYER}!\p"
	.string "Thanks to our battle, I’ve come\n"
	.string "to understand my weak points!\p"
	.string "When I reopen the GYM, I won’t go\n"
	.string "down in defeat again!$"

gText_Winona_Pokenav_2B2E2B:: @ 82B2E2B
	.string "WINONA: You’ve done it, {PLAYER}!\p"
	.string "News about the new CHAMPION\n"
	.string "has reached us in FORTREE!\p"
	.string "But… The next time we battle,\n"
	.string "it’s not going to end the same way.$"

gText_Winona_Pokenav_2B2EC2:: @ 82B2EC2
	.string "WINONA: Is this {PLAYER}?\n"
	.string "Our GYM is back in operation!\p"
	.string "We’re waiting for you in FORTREE!$"

gText_Winona_Pokenav_2B2F16:: @ 82B2F16
	.string "WINONA: {PLAYER}…\n"
	.string "Though I have lost, my wings will\l"
	.string "never break.\p"
	.string "Yes, in exactly the same way that\n"
	.string "you never lost sight of your dream.$"

gText_TateLiza_Pokenav_2B2F97:: @ 82B2F97
	.string "TATE: Oh! You’re…\n"
	.string "LIZA: {PLAYER}!\p"
	.string "TATE: We’re in training again…\n"
	.string "LIZA: So we can reopen our GYM!\p"
	.string "TATE: When our GYM is ready…\n"
	.string "LIZA: When our GYM is ready…\p"
	.string "TATE: A mark’ll appear by our name…\n"
	.string "LIZA: On the MATCH CALL list.$"

gText_TateLiza_Pokenav_2B306E:: @ 82B306E
	.string "TATE: {PLAYER}, congratulations!\n"
	.string "LIZA: {PLAYER}, congratulations!\p"
	.string "TATE: The two of us are…\n"
	.string "LIZA: Still in training!\p"
	.string "TATE: We need some more time, but…\n"
	.string "LIZA: When our GYM is ready…\p"
	.string "TATE: A mark’ll appear by our name…\n"
	.string "LIZA: On the MATCH CALL list.$"

gText_TateLiza_Pokenav_2B3158:: @ 82B3158
	.string "TATE: {PLAYER}!\n"
	.string "LIZA: {PLAYER}!\p"
	.string "TATE: Our GYM is ready!\n"
	.string "LIZA: Our GYM is ready!\p"
	.string "TATE: Please come visit…\n"
	.string "LIZA: MOSSDEEP anytime!$"

gText_TateLiza_Pokenav_2B31CD:: @ 82B31CD
	.string "TATE: {PLAYER}, the battle we had…\n"
	.string "LIZA: Is an invaluable experience.\p"
	.string "TATE: It would be nice if…\n"
	.string "LIZA: We could all battle again!$"

gText_Juan_Pokenav_2B3249:: @ 82B3249
	.string "JUAN: Hmm…\n"
	.string "{PLAYER}{STRING 5}… Was it?\p"
	.string "Our battle together--it brought\n"
	.string "to me memories of when I first\l"
	.string "encountered WALLACE.\p"
	.string "Perhaps you are a genius who may\n"
	.string "yet surpass WALLACE!$"

gText_Juan_Pokenav_2B32EC:: @ 82B32EC
	.string "JUAN: Fufu… {PLAYER}{STRING 5}…\n"
	.string "You’ve finally achieved your goal.\p"
	.string "My eye for appraising talent wasn’t\n"
	.string "mistaken…\p"
	.string "I wish for another chance to meet\n"
	.string "you, for you have scaled the peak\l"
	.string "of power and prestige.$"

gText_Juan_Pokenav_2B33AA:: @ 82B33AA
	.string "JUAN: Hoho… {PLAYER}{STRING 5}…\p"
	.string "Our SOOTOPOLIS GYM has finally\n"
	.string "reopened.\p"
	.string "If you wish to see me, you are\n"
	.string "welcome to visit anytime.$"

gText_Juan_Pokenav_2B341E:: @ 82B341E
	.string "JUAN: {PLAYER}{STRING 5}…\p"
	.string "Like the finest music, the battles\n"
	.string "we wage together strike chords\l"
	.string "of inspiration in my heart…\p"
	.string "When I close my eyes, I see visions\n"
	.string "of you soaring with the melody…$"

gText_Sidney_Pokenav_2B34CC:: @ 82B34CC
	.string "SIDNEY: Yo, {PLAYER}!\p"
	.string "If you want to battle with me\n"
	.string "again, you come on back whenever\l"
	.string "you like to the POKéMON LEAGUE.\p"
	.string "I’ll always be here!\n"
	.string "I’ll be waiting!$"

gText_Phoebe_Pokenav_2B3561:: @ 82B3561
	.string "PHOEBE: Hi, {PLAYER}!\p"
	.string "How about coming back here again\n"
	.string "sometime?\p"
	.string "I’d like to see how much tighter\n"
	.string "your bond has grown with your\l"
	.string "POKéMON.$"

gText_Glacia_Pokenav_2B35E4:: @ 82B35E4
	.string "GLACIA: Hello, {PLAYER}.\p"
	.string "I trust you haven’t become\n"
	.string "complacent with your power?\p"
	.string "If you feel the need to cool your\n"
	.string "hot emotions just a little, do come\l"
	.string "to the POKéMON LEAGUE…$"

gText_Drake_Pokenav_2B368B:: @ 82B368B
	.string "DRAKE: That voice… {PLAYER}, is it?\n"
	.string "You sound well…\p"
	.string "I understand that there is now\n"
	.string "a facility called the BATTLE\l"
	.string "FRONTIER that tests the skills of\l"
	.string "TRAINERS.\p"
	.string "However, if you wish to have real\n"
	.string "battles, there is no substitute for\l"
	.string "the POKéMON LEAGUE!\p"
	.string "Don’t you agree, {PLAYER}?$"

gText_Wallace_Pokenav_2B3790:: @ 82B3790
	.string "WALLACE: Hello, {PLAYER}{STRING 5}.\n"
	.string "Have you met STEVEN?\p"
	.string "He is…\n"
	.string "Actually incredibly skilled.\p"
	.string "However, he’s an odd soul who\n"
	.string "rarely battles.\p"
	.string "Instead, he would rather look for\n"
	.string "rare stones.\p"
	.string "I’m sure he’s digging in a cave or\n"
	.string "a craggy mountain somewhere.\p"
	.string "But what is a rare stone exactly?\n"
	.string "All I can think of is a METEORITE…$"

MossdeepCity_SpaceCenter_2F_Text_2B38C1: @ 82B38C1
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "MAY: Hi, {PLAYER}{KUN}!\p"
	.string "I was just in PACIFIDLOG a little\n"
	.string "while ago.\p"
	.string "I saw a giant green POKéMON\n"
	.string "flying high in the sky.\p"
	.string "I…\n"
	.string "I’ve never seen anything like it.\p"
	.string "I wonder what it was.\n"
	.string "Is this maybe a major discovery?\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

MossdeepCity_SpaceCenter_2F_Text_2B39C6: @ 82B39C6
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "BRENDAN: Hey, {PLAYER}!\n"
	.string "I was in PACIFIDLOG just now.\p"
	.string "I saw this huge green POKéMON\n"
	.string "flying across the sky.\p"
	.string "I’ve never seen anything that\n"
	.string "amazing before.\p"
	.string "I wish you could’ve seen it,\n"
	.string "{PLAYER}.\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

gText_May_Pokenav_2B3AB3:: @ 2B3AB3
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "MR. BRINEY retired as a SAILOR,\n"
	.string "but I still see him out on the sea\l"
	.string "with his pet PEEKO sometimes.\p"
	.string "He must love the sea still.$"

gText_May_Pokenav_2B3B3F:: @ 2B3B3F
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "You know how little towns like\n"
	.string "PETALBURG and DEWFORD have GYMS?\p"
	.string "For some reason, the big port of\n"
	.string "SLATEPORT doesn’t have a GYM.\p"
	.string "When they finally build a GYM there,\n"
	.string "I should apply to be the LEADER.$"

gText_May_Pokenav_2B3C13:: @ 2B3C13
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "Do you remember a man named\n"
	.string "the CUTTER in RUSTBORO?\l"
	.string "He had a house there, remember?\p"
	.string "Well, I found out his younger\n"
	.string "brother lives in MAUVILLE.\p"
	.string "Can you guess his name?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "The ROCK SMASH GUY!$"

gText_May_Pokenav_2B3CF3:: @ 2B3CF3
	.string "MAY: {PLAYER}{STRING 5}?\p"
	.string "RUSTURF TUNNEL…\n"
	.string "They named it that because it\l"
	.string "joins RUSTBORO and VERDANTURF.$"

gText_May_Pokenav_2B3D4B:: @ 2B3D4B
	.string "MAY: {PLAYER}{STRING 5}, how are you?\p"
	.string "I’m out on ROUTE 111 now.\p"
	.string "I’m going to get a rest at an old\n"
	.string "lady’s house.\p"
	.string "She lives just north of\n"
	.string "the desert.$"

gText_May_Pokenav_2B3DD1:: @ 2B3DD1
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "Did you know about the MIRAGE\n"
	.string "TOWER in the desert?\p"
	.string "They say, like a mirage, it seems\n"
	.string "to mysteriously come and go.\p"
	.string "I wish I could see it.$"

gText_May_Pokenav_2B3E69:: @ 2B3E69
	.string "MAY: {PLAYER}{STRING 5}, yahoo!\n"
	.string "I’m on ROUTE 119 now.\p"
	.string "There’s a big river here, and\n"
	.string "it often rains.\p"
	.string "I got soaked!$"

gText_May_Pokenav_2B3ECD:: @ 2B3ECD
	.string "MAY: {PLAYER}{STRING 5}, hi.\p"
	.string "MT. PYRE is a memorial to POKéMON\n"
	.string "whose lives have ended.\p"
	.string "Maybe as a result, it’s infested\n"
	.string "with many GHOST-type POKéMON!$"

gText_May_Pokenav_2B3F2B:: @ 2B3F2B
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "I was thinking of going to the hot\n"
	.string "spring in LAVARIDGE.\p"
	.string "But on the way, around JAGGED\n"
	.string "PASS, I ran into some bad-looking\l"
	.string "characters. The mood was ugly!$"

gText_May_Pokenav_2B3FFB:: @ 2B3FFB
	.string "MAY: Hi, {PLAYER}{STRING 5}!\n"
	.string "Did you see the news?\p"
	.string "They say CAPT. STERN discovered\n"
	.string "the SEAFLOOR CAVERN while on his\l"
	.string "submarine expedition.$"

gText_May_Pokenav_2B402B:: @ 2B402B
	.string "MAY: Hi, {PLAYER}{STRING 5}!\n"
	.string "Don’t you think it’s neat?\p"
	.string "Even if you don’t have a boat,\n"
	.string "you can cross the sea using\l"
	.string "a POKéMON’s move.\p"
	.string "Did you know there’s more?\p"
	.string "There’s a POKéMON move that lets\n"
	.string "you go to the bottom of the sea.$"

gText_May_Pokenav_2B414B:: @ 2B414B
	.string "MAY: Hi, {PLAYER}{STRING 5}!\n"
	.string "Hope things are okay!\p"
	.string "Have you been on the sea and\n"
	.string "found your way to the other side\l"
	.string "blocked?\p"
	.string "Try diving deep underwater and\n"
	.string "following trenches.\p"
	.string "When you get to the other side,\n"
	.string "come up to the surface. Easy!$"

gText_May_Pokenav_2B4228:: @ 2B4228
	.string "MAY: Hi, {PLAYER}{STRING 5}!\p"
	.string "How’s it going?\n"
	.string "Are you filling your POKéDEX?\p"
	.string "I heard a rumor that there are\n"
	.string "super-ancient POKéMON out there.\l"
	.string "And there are three of them!\p"
	.string "I would love to see even one…$"

gText_May_Pokenav_2B42E0:: @ 2B42E0
	.string "MAY: {PLAYER}{STRING 5}!\n"
	.string "I heard the rumors!\p"
	.string "You beat the SOOTOPOLIS GYM\n"
	.string "LEADER?\p"
	.string "That means you don’t have far\n"
	.string "to go, do you?$"

gText_May_Pokenav_2B4350:: @ 2B4350
	.string "MAY: There isn’t a single TRAINER\n"
	.string "left in HOENN who doesn’t know who\l"
	.string "you are, {PLAYER}{STRING 5}!\p"
	.string "When I tell people that I’m friends\n"
	.string "with you, {PLAYER}{STRING 5}, they’re all\l"
	.string "surprised!$"

gText_Brendan_Pokenav_2B43EF:: @ 2B43EF
	.string "BRENDAN: Hey, {PLAYER}!\p"
	.string "MR. BRINEY retired as a SAILOR,\n"
	.string "but I still see him out on the sea\l"
	.string "with his pet PEEKO sometimes.\p"
	.string "I guess he must love\n"
	.string "the sea still.$"

gText_Brendan_Pokenav_2B4486:: @ 2B4486
	.string "BRENDAN: Hey, {PLAYER}!\p"
	.string "I don’t get how little towns like\n"
	.string "PETALBURG and DEWFORD have GYMS.\p"
	.string "I mean, not when the big port of\n"
	.string "SLATEPORT doesn’t have a GYM.\p"
	.string "When they finally build a GYM there,\n"
	.string "I should apply to be the LEADER.$"

gText_Brendan_Pokenav_2B4560:: @ 2B4560
	.string "BRENDAN: Yo, {PLAYER}!\p"
	.string "Do you remember a guy named\n"
	.string "the CUTTER in RUSTBORO?\l"
	.string "He had a house there, right?\p"
	.string "Well, it turns out his little\n"
	.string "brother lives in MAUVILLE.\p"
	.string "Can you guess his name?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "The ROCK SMASH GUY!$"

gText_Brendan_Pokenav_2B463F:: @ 2B463F
	.string "BRENDAN: This voice… {PLAYER}?\p"
	.string "They gave RUSTURF TUNNEL its name\n"
	.string "because it joins RUSTBORO and\l"
	.string "VERDANTURF.\p"
	.string "Did you know that?$"

gText_Brendan_Pokenav_2B46B7:: @ 2B46B7
	.string "BRENDAN: {PLAYER}, what’s up?\p"
	.string "Hey, I’m out on ROUTE 111 now.\p"
	.string "I’m going to rest up at an old\n"
	.string "lady’s house north of the desert.\p"
	.string "If you’re in the area, you should\n"
	.string "visit her, too.$"

gText_Brendan_Pokenav_2B4761:: @ 2B4761
	.string "BRENDAN: Hey, {PLAYER}!\p"
	.string "Did you know about the MIRAGE\n"
	.string "TOWER in the desert?\p"
	.string "They say, like a mirage, it can be\n"
	.string "seen only sometimes.\p"
	.string "I’d like to see that!$"

gText_Brendan_Pokenav_2B47F4:: @ 2B47F4
	.string "BRENDAN: Who’s this? Oh, {PLAYER}?\n"
	.string "Guess what? I’m on ROUTE 119 now.\p"
	.string "There’s a big river here, and\n"
	.string "it rains all the time.\p"
	.string "I got soaked to the bone!$"

gText_Brendan_Pokenav_2B4882:: @ 2B4882
	.string "BRENDAN: {PLAYER}!\p"
	.string "MT. PYRE is a memorial to POKéMON\n"
	.string "whose lives have ended.\p"
	.string "That’s probably why it’s infested\n"
	.string "with many GHOST-type POKéMON!$"

gText_Brendan_Pokenav_2B4909:: @ 2B4909
	.string "BRENDAN: Hey there, {PLAYER}.\p"
	.string "I was on my way back to the hot\n"
	.string "spring in LAVARIDGE.\p"
	.string "But around JAGGED PASS, I ran into\n"
	.string "some nasty-looking characters.\p"
	.string "Those creeps…\n"
	.string "I think they were TEAM MAGMA.$"

gText_Brendan_Pokenav_2B49C4:: @ 2B49C4
	.string "BRENDAN: Hi, {PLAYER}!\n"
	.string "Did you catch the news?\p"
	.string "They say CAPT. STERN discovered\n"
	.string "the SEAFLOOR CAVERN while on his\l"
	.string "submarine expedition.$"

gText_Brendan_Pokenav_2B4A44:: @ 2B4A44
	.string "BRENDAN: Hey there, {PLAYER}!\n"
	.string "Don’t you think it’s awesome?\p"
	.string "Even if you don’t have a boat,\n"
	.string "you can cross the sea using\l"
	.string "a POKéMON’s move.\p"
	.string "And, there’s a move that lets you\n"
	.string "travel to the bottom of the sea.\p"
	.string "Man, POKéMON can do anything!$"

gText_Brendan_Pokenav_2B4B28:: @ 2B4B28
	.string "BRENDAN: Howdy, {PLAYER}!\n"
	.string "How are you holding up?\p"
	.string "Ever found your way to the other\n"
	.string "side blocked while on the sea?\p"
	.string "Try diving deep underwater and\n"
	.string "following trenches at the bottom.\p"
	.string "When you get to the other side,\n"
	.string "come up to the surface. Simple!$"

gText_Brendan_Pokenav_2B4C15:: @ 2B4C15
	.string "BRENDAN: Hey there, {PLAYER}!\p"
	.string "How’s it going? Filling up your\n"
	.string "POKéDEX successfully?\p"
	.string "I heard a rumor that there are\n"
	.string "super-ancient POKéMON out there.\l"
	.string "And not just one--three!\p"
	.string "I’d love to catch even one…$"

gText_Brendan_Pokenav_2B4CD8:: @ 2B4CD8
	.string "BRENDAN: {PLAYER}!\n"
	.string "I heard the rumors!\p"
	.string "You beat the SOOTOPOLIS GYM\n"
	.string "LEADER? Awesome!\p"
	.string "You’re getting awful close now!$"

gText_Brendan_Pokenav_2B4D46:: @ 2B4D46
	.string "BRENDAN: There isn’t a TRAINER in\n"
	.string "all of HOENN who doesn’t know who\l"
	.string "you are, {PLAYER}!\p"
	.string "When I tell people that I’m friends\n"
	.string "with you, {PLAYER}, they get pretty\l"
	.string "envious!$"

gText_Wally_Pokenav_2B4DE2:: @ 2B4DE2
	.string "WALLY: Oh, {PLAYER}!\p"
	.string "I’ve been getting healthier and\n"
	.string "more physically fit.\p"
	.string "I hope I can become a TRAINER like\n"
	.string "you soon, {PLAYER}!$"

gText_Wally_Pokenav_2B4E57:: @ 2B4E57
	.string "WALLY: {PLAYER}, hello!\p"
	.string "After RUSTURF TUNNEL went\n"
	.string "through, WANDA’s been very happy!$"

gText_Wally_Pokenav_2B4EA5:: @ 2B4EA5
	.string "WALLY: Oh, {PLAYER}!\p"
	.string "I… I left my uncle’s place in\n"
	.string "VERDANTURF without telling anyone.\p"
	.string "I wonder if he’s furious with me…\p"
	.string "{PLAYER}, you understand how\n"
	.string "I feel, don’t you?$"

gText_Wally_Pokenav_2B4F41:: @ 2B4F41
	.string "WALLY: {PLAYER}?\n"
	.string "It’s me, WALLY!\p"
	.string "The world of TRAINERS is amazing!\p"
	.string "When I have my POKéMON with me,\n"
	.string "all sorts of people say hi!\p"
	.string "It’s as if everyone’s getting\n"
	.string "connected through POKéMON!$"

gText_Wally_Pokenav_2B4FF3:: @ 2B4FF3
	.string "WALLY: {PLAYER}? It’s awesome!\n"
	.string "That RALTS we caught together?\l"
	.string "It evolved, {PLAYER}!\p"
	.string "Maybe I’m talented…\p"
	.string "Oh, but I shouldn’t get a big head\n"
	.string "like that!\p"
	.string "After all, it’s the POKéMON that\n"
	.string "should be praised!$"

gText_Wally_Pokenav_2B50B1:: @ 2B50B1
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "WALLY appears to be out of\n"
	.string "the POKéNAV’s service area…$"

gText_Wally_Pokenav_2B5100:: @ 2B5100
	.string "WALLY: Oh, {PLAYER}!\p"
	.string "Before I met you, I hardly ever\n"
	.string "left my house…\p"
	.string "But now, I’m on an adventure with\n"
	.string "my very own POKéMON…\p"
	.string "{PLAYER}…\n"
	.string "Thank you…$"

gText_Scott_Pokenav_2B5184:: @ 2B5184
	.string "SCOTT: Howdy, {PLAYER}{STRING 5}!\p"
	.string "You know how POKéMON can be found\n"
	.string "everywhere?\p"
	.string "Like in the mountains, in the sea,\n"
	.string "in tall grass anywhere?\p"
	.string "Just like POKéMON, you can find\n"
	.string "TRAINERS everywhere, too.\p"
	.string "As a result, I have to hurry\n"
	.string "everywhere, too. Busy, busy!$"

gText_Scott_Pokenav_2B5275:: @ 2B5275
	.string "SCOTT: I’m on ROUTE 119 right now.\n"
	.string "It’s teeming with TRAINERS!\p"
	.string "It’s also overgrown with tall grass\n"
	.string "everywhere, it seems.\p"
	.string "Walking around in shorts here\n"
	.string "makes me all ticklish!$"

gText_Scott_Pokenav_2B5323:: @ 2B5323
	.string "SCOTT: Hi, hi, {PLAYER}{STRING 5}!\p"
	.string "Have you had the chance to climb\n"
	.string "MT. PYRE?\p"
	.string "The place is a memorial to POKéMON\n"
	.string "that have passed away.\p"
	.string "It’s somewhere every TRAINER\n"
	.string "should climb to the top of once.$"

gText_Scott_Pokenav_2B53DB:: @ 2B53DB
	.string "SCOTT: Hi, {PLAYER}{STRING 5}!\p"
	.string "I’ve been hearing about these odd\n"
	.string "gangs being a nuisance.\p"
	.string "TEAM MAGMA and TEAM AQUA,\n"
	.string "I think they were.\p"
	.string "I would think there’d be some\n"
	.string "skilled TRAINERS among them.\p"
	.string "…But if they’re thugs…$"

gText_Scott_Pokenav_2B54A5:: @ 2B54A5
	.string "SCOTT: Oh, hi, {PLAYER}{STRING 5}.\p"
	.string "Might there be tough TRAINERS\n"
	.string "at the bottom of the sea?\p"
	.string "I can’t go check for myself.\n"
	.string "I can’t swim, for one.\l"
	.string "And I don’t raise POKéMON…$"

gText_Scott_Pokenav_2B5541:: @ 2B5541
	.string "SCOTT: Hi, hi, {PLAYER}{STRING 5}!\p"
	.string "You know that you can challenge\n"
	.string "the POKéMON LEAGUE when you’ve\l"
	.string "collected all the GYM BADGES?\p"
	.string "With your talent, becoming the\n"
	.string "CHAMPION isn’t a pipe dream.\p"
	.string "But did you know?\n"
	.string "There’s somewhere even better.\p"
	.string "But, that’s all I’m willing to say\n"
	.string "for the time being.\p"
	.string "It’s something you can look\n"
	.string "forward to.\p"
	.string "When you’ve won your way through\n"
	.string "the POKéMON LEAGUE into the HALL\l"
	.string "OF FAME!$"

gText_Scott_Pokenav_2B56CA:: @ 2B56CA
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "SCOTT appears to be out of\n"
	.string "the POKéNAV’s service area…$"

gText_Norman_Pokenav_2B5719:: @ 82B5719
	.string "DAD: In RUSTBORO, there’s a man\n"
	.string "that goes by the odd name of\l"
	.string "the CUTTER.\p"
	.string "If you’re in the area, you should\n"
	.string "pay him a visit.$"

gText_Norman_Pokenav_2B5795:: @ 82B5795
	.string "DAD: Hm… Little by little, but also\n"
	.string "very surely, you’re getting\l"
	.string "tougher, {PLAYER}.\p"
	.string "The stronger you get, the farther\n"
	.string "and higher you soar from Mother\l"
	.string "and me…\p"
	.string "This feeling is hard to explain.$"

gText_Norman_Pokenav_2B584D:: @ 82B584D
	.string "DAD: I see…\n"
	.string "You’ve collected four GYM BADGES…\p"
	.string "There’s no avoiding it now.\n"
	.string "We will battle like I promised.\p"
	.string "Come anytime.\n"
	.string "We’ll all be waiting for you!$"

gText_Norman_Pokenav_2B58E3:: @ 82B58E3
	.string "DAD: {PLAYER}! You’d better go visit\n"
	.string "Mother every so often.\p"
	.string "I’m going to remain here and\n"
	.string "redouble my training.\p"
	.string "The way of battling is deep\n"
	.string "and unforgiving!$"

gText_Norman_Pokenav_2B5979:: @ 82B5979
	.string "DAD: Oh, hi, {PLAYER}!\p"
	.string "What’s that? MAGMA EMBLEM?\n"
	.string "I don’t know what that’s about.\p"
	.string "But with a name like that, it may\n"
	.string "be somehow linked to a volcano!$"

gText_Norman_Pokenav_2B5A07:: @ 82B5A07
	.string "DAD: Hiyah! Haah! Dwah!\p"
	.string "…Oh? {PLAYER}!\p"
	.string "You caught me right in the middle\n"
	.string "of a POKéMON training session!$"

gText_Norman_Pokenav_2B5A69:: @ 82B5A69
	.string "DAD: {PLAYER}!\p"
	.string "Who would’ve thought you’d become\n"
	.string "the POKéMON LEAGUE CHAMPION…\p"
	.string "Okay!\n"
	.string "I won’t be left behind!$"

gText_Norman_Pokenav_2B5ACF:: @ 82B5ACF
	.string "DAD: Hm? {PLAYER}?\n"
	.string "What good timing!\p"
	.string "This time, I’m going to challenge\n"
	.string "you to battle.\p"
	.string "I’m waiting in the PETALBURG GYM.\n"
	.string "Accept my challenge anytime!$"

gText_Norman_Pokenav_2B5B5E:: @ 82B5B5E
	.string "DAD: …You amaze me, {PLAYER}.\n"
	.string "How much higher will you soar?$"

gText_Steven_Pokenav_2B5B95:: @ 82B5B95
	.string "STEVEN: Hi, {PLAYER}{STRING 5}!\p"
	.string "Have you been to MAUVILLE\n"
	.string "already?\p"
	.string "You should visit the BIKE SHOP\n"
	.string "and get a MACH BIKE.\p"
	.string "Then, try exploring the GRANITE\n"
	.string "CAVE thoroughly.\p"
	.string "You may make a new discovery\n"
	.string "there.$"

gText_Steven_Pokenav_2B5C53:: @ 82B5C53
	.string "STEVEN: Hi, {PLAYER}{STRING 5}!\p"
	.string "I’ve met a lot of different\n"
	.string "TRAINERS so far.\p"
	.string "But you’re one of a kind.\n"
	.string "You’re not like anyone else.$"

gText_Steven_Pokenav_2B5CC9:: @ 82B5CC9
	.string "STEVEN: Hi, {PLAYER}{STRING 5}!\p"
	.string "When you’re on an adventure with\n"
	.string "your POKéMON, what do you think?\p"
	.string "Do you consider them to be strong\n"
	.string "partners?\p"
	.string "Do you think of them as fun\n"
	.string "companions?\p"
	.string "Depending on how you think, your\n"
	.string "adventure’s significance changes.$"

gText_Steven_Pokenav_2B5DB4:: @ 82B5DB4
	.string "STEVEN: Hello?\n"
	.string "{PLAYER}{STRING 5}?\p"
	.string "I’m involved in a spot of trouble\n"
	.string "at the SPACE CENTER.\p"
	.string "I’m sorry, but I can’t talk now.\n"
	.string "Bye!$"

gText_Steven_Pokenav_2B5E26:: @ 82B5E26
	.string "STEVEN: Oh!\n"
	.string "{PLAYER}{STRING 5}!\p"
	.string "There’s no need to talk.\n"
	.string "It’s past time for talking.\p"
	.string "You have to believe in yourself\n"
	.string "and do what’s right.$"

gText_Steven_Pokenav_2B5EA2:: @ 82B5EA2
	.string "… … … … … …\p"
	.string "STEVEN appears not to be getting\n"
	.string "the call…$"

gText_Steven_Pokenav_2B5ED9:: @ 82B5ED9
	.string "STEVEN: {PLAYER}{STRING 5}… Congratulations\n"
	.string "for entering the HALL OF FAME.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I hope we can meet again\n"
	.string "somewhere!$"

Route101_Text_2B5F52: @ 82B5F52
	.string "PROF. BIRCH: Oh, {PLAYER}{KUN}!\n"
	.string "I’ve already heard about you!\p"
	.string "It seems your POKéNAV’s been\n"
	.string "upgraded with MATCH CALL.\p"
	.string "Well, I should register, too!\p"
	.string "That way, I’d be able to examine\n"
	.string "your POKéDEX even while you’re\l"
	.string "out in the field.\p"
	.string "… … … … … …$"

Route101_Text_2B603A: @ 82B603A
	.string "Registered PROF. BIRCH\n"
	.string "in the POKéNAV.$"

	.string "PROF. BIRCH: When one has both\n"
	.string "the POKéDEX and POKéNAV, studying\l"
	.string "POKéMON becomes more fun, eh?$"

gText_MrStone_Pokenav_2B60C0:: @ 82B60C0
	.string "MR. STONE: Oh? {PLAYER}{STRING 5}!\p"
	.string "Since you called me, the POKéNAV\n"
	.string "must be working properly!\p"
	.string "Other people will be registered,\n"
	.string "so try calling them up, too!\p"
	.string "Good! Good!\n"
	.string "You seem to be quite happy!\p"
	.string "Hm…\n"
	.string "How could I know that?\p"
	.string "It’s because I’m looking down at\n"
	.string "you from my office window!\p"
	.string "Wahahaha!\n"
	.string "See you again!$"

gText_MrStone_Pokenav_2B61E6:: @ 82B61E6
	.string "MR. STONE: Oh? {PLAYER}{STRING 5}!\p"
	.string "What’s wrong? Have you forgotten\n"
	.string "about that little errand of mine?\p"
	.string "I need you to deliver my letter\n"
	.string "to STEVEN in DEWFORD.\p"
	.string "After that, deliver our parcel to\n"
	.string "CAPT. STERN in SLATEPORT.\p"
	.string "You remember, don’t you?\p"
	.string "Now, since I am a busy PRESIDENT,\n"
	.string "I have to go! Bye-bye!$"

gText_MrStone_Pokenav_2B6302:: @ 82B6302
	.string "MR. STONE: Oh! {PLAYER}{STRING 5}!\p"
	.string "Ah, so you’ve met STEVEN!\n"
	.string "I’d better reward you, then!\p"
	.string "When you visit RUSTBORO again,\n"
	.string "come see me at my office.\p"
	.string "I’ll be waiting for you!$"

gText_MrStone_Pokenav_2B63A0:: @ 82B63A0
	.string "MR. STONE: Oh! {PLAYER}{STRING 5}!\p"
	.string "Did you know that DEVON was\n"
	.string "digging the RUSTURF TUNNEL?\p"
	.string "But we shut down the operation to\n"
	.string "protect the POKéMON in the area.\p"
	.string "It’s a no-brainer, really.\p"
	.string "It’s more important to let POKéMON\n"
	.string "live in peace than worry about our\l"
	.string "own convenience.$"

gText_MrStone_Pokenav_2B64A2:: @ 82B64A2
	.string "MR. STONE: Hello, hello, {PLAYER}{STRING 5}!\p"
	.string "I heard from someone in PETALBURG\n"
	.string "that you’re NORMAN’s child!\p"
	.string "No wonder you’re such a capable\n"
	.string "being!$"

gText_MrStone_Pokenav_2B6526:: @ 82B6526
	.string "MR. STONE: What’s that?\p"
	.string "You battled your own father and\n"
	.string "defeated him?\p"
	.string "That’s astounding!\p"
	.string "I had no idea that I befriended\n"
	.string "someone so special! Wahaha!$"

gText_MrStone_Pokenav_2B65BB:: @ 82B65BB
	.string "Hello!\n"
	.string "This is DEVON CORPORATI…\l"
	.string "Oh, hello, {PLAYER}!\p"
	.string "Our PRESIDENT was here a little\n"
	.string "while ago, but he’s gone out.\p"
	.string "Our PRESIDENT is busy, but you\n"
	.string "seem to be just as busy, {PLAYER}.$"

gText_MrStone_Pokenav_2B6664:: @ 82B6664
	.string "…Huh? …What’s that?\p"
	.string "GROU… Yes? …DON?\p"
	.string "You’re breaking up…\n"
	.string "…can’t hear…\p"
	.string "BZZZZ…$"

gText_MrStone_Pokenav_2B66B1:: @ 82B66B1
	.string "…Huh? …What’s that?\p"
	.string "Seaflo… Yes? …Caver…?\p"
	.string "You’re breaking up…\n"
	.string "…can’t hear…\p"
	.string "BZZZZ…$"

gText_MrStone_Pokenav_2B6703:: @ 82B6703
	.string "MR. STONE: {PLAYER}{STRING 5}! It’s me!\p"
	.string "You were apparently involved in all\n"
	.string "sorts of things, but I, being busy,\l"
	.string "haven’t a clue exactly what!\p"
	.string "However, I urge you to take\n"
	.string "the road you believe in and walk it.\p"
	.string "I’ll always be in your corner!\n"
	.string "Take care!$"

gText_MrStone_Pokenav_2B67ED:: @ 82B67ED
	.string "MR. STONE: … … … … … …\n"
	.string "Is this maybe {PLAYER}{STRING 5}?\p"
	.string "Your voice is so full of confidence,\n"
	.string "I didn’t recognize you right off!\p"
	.string "Hm! You must come visit us at DEVON\n"
	.string "sometime!$"

BattleFrontier_BattleTowerLobby_EventScript_2B688D:: @ 82B688D
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special sub_81A085C
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6900
	setvar VAR_0x8004, 10
	special sub_81A085C
	compare VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B68BE
	checkflag FLAG_0x934
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6E90

BattleFrontier_BattleTowerLobby_EventScript_2B68BE:: @ 82B68BE
	setvar VAR_0x8004, 11
	special sub_81A085C
	compare VAR_RESULT, 2
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B69D3
	compare VAR_RESULT, 4
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ACF
	compare VAR_RESULT, 3
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C77
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D5C
	compare VAR_RESULT, 5
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6DD4
	release
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6900:: @ 82B6900
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 6
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A085C
	waitstate

BattleFrontier_BattleTowerLobby_EventScript_2B6925:: @ 82B6925
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 6
	special sub_81A085C
	waitstate
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B69BB
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 0
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 1
	setorcopyvar VAR_0x8005, VAR_RESULT
	addvar VAR_0x8005, 1
	special sub_81A085C
	setvar VAR_0x8004, 3
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 8
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 3
	special sub_81A085C
	waitstate
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B69BB:: @ 82B69BB
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 1
	special sub_81A085C
	waitstate
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6925

BattleFrontier_BattleTowerLobby_EventScript_2B69D3:: @ 82B69D3
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 2
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 1
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 6
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 2
	special sub_81A085C
	waitstate
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6ABA
	compare VAR_0x8005, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6AC0
	setvar VAR_0x8004, 12
	special sub_81A085C
	copyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 13
	special sub_81A085C
	setvar VAR_0x8004, 5
	special sub_81A085C
	setvar VAR_0x8004, 12
	special sub_81A085C
	compare VAR_RESULT, 3
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6AC6
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special sub_81A085C
	setvar VAR_0x8004, 15
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 7
	special sub_81A085C
	waitstate
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6ABA:: @ 82B6ABA
	setvar VAR_0x8007, 0
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC0:: @ 82B6AC0
	setvar VAR_0x8007, 1
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6AC6:: @ 82B6AC6
	setvar VAR_0x8004, 4
	special sub_81A085C
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6ACF:: @ 82B6ACF
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 10
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 15
	special sub_81A085C

BattleFrontier_BattleTowerLobby_EventScript_2B6B09:: @ 82B6B09
	fadescreen 1
	setvar VAR_RESULT, 0
	setvar VAR_0x8004, 19
	special sub_81A085C
	waitstate
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B81
	setvar VAR_0x8004, 20
	special sub_81A085C
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C0C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 5
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 12
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 5
	special sub_81A085C
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6B81:: @ 82B6B81
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 13
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 15
	special sub_81A085C
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09

BattleFrontier_BattleTowerLobby_EventScript_2B6BD4:: @ 82B6BD4
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 14
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 5
	special sub_81A085C
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C0C:: @ 82B6C0C
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 4
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 5
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 2
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 16
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 4
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 15
	special sub_81A085C
	compare VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B09
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6BD4
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6C77:: @ 82B6C77
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 3
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 2
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 3
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 4
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 8
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 3
	special sub_81A085C
	waitstate
	copyvar VAR_0x8005, VAR_RESULT
	compare VAR_0x8005, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6D50
	compare VAR_0x8005, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6D56
	setvar VAR_0x8004, 17
	special sub_81A085C
	setvar VAR_0x8004, 5
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	copyvar VAR_0x8006, VAR_0x8007
	special sub_81A085C
	setvar VAR_0x8004, 15
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 9
	special sub_81A085C
	waitstate
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6D50:: @ 82B6D50
	setvar VAR_0x8007, 3
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D56:: @ 82B6D56
	setvar VAR_0x8007, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6D5C:: @ 82B6D5C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 7
	setvar VAR_0x8005, 1
	special sub_81A085C
	waitstate
	copyvar VAR_0x8005, VAR_RESULT
	setvar VAR_0x8004, 18
	special sub_81A085C
	setvar VAR_0x8004, 5
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 9
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 5
	special sub_81A085C
	waitstate
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6DD4:: @ 82B6DD4
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 11
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 25
	special sub_81A085C
	setvar VAR_0x8004, 19
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	setvar VAR_0x8004, 21
	special sub_81A085C
	setvar VAR_0x8004, 16
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 7
	special sub_81A085C
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 15
	special sub_81A085C
	waitstate
	setvar VAR_0x8004, 9
	special sub_81A085C
	call BattleFrontier_BattleTowerLobby_EventScript_2B6E4D
	release
	releaseall
	switch VAR_FACING
	case 2, BattleFrontier_BattleTowerLobby_EventScript_2B6E54
	goto BattleFrontier_BattleTowerLobby_EventScript_2B6E72
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E4D:: @ 82B6E4D
	setflag FLAG_0x2BD
	setflag FLAG_0x934
	return

BattleFrontier_BattleTowerLobby_EventScript_2B6E54:: @ 82B6E54
	setvar VAR_0x8004, 24
	special sub_81A085C
	compare VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6E93
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E94
	waitmovement 0
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E72:: @ 82B6E72
	setvar VAR_0x8004, 24
	special sub_81A085C
	compare VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6E93
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E95
	waitmovement 0
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E90:: @ 82B6E90
	release
	releaseall
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E93:: @ 82B6E93
	end

BattleFrontier_BattleTowerLobby_Movement_2B6E94: @ 82B6E94
	step_18

BattleFrontier_BattleTowerLobby_Movement_2B6E95: @ 82B6E95
	step_15
	step_15
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_18
	step_54
	step_31
	step_31
	step_31
	step_end

gText_082B6EA5:: @ 82B6EA5
	.string "Um, I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Snivel… This tension is getting to me…$"

gText_082B6EEC:: @ 82B6EEC
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!\n"
	.string "Here we come!$"

gText_082B6F16:: @ 82B6F16
	.string "I’m the no. {STR_VAR_2} apprentice of {STR_VAR_1}!\n"
	.string "Accept my challenge!$"

gText_082B6F4C:: @ 82B6F4C
	.string "Um… I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice…\n"
	.string "Do you think someone like me can win?$"

gText_082B6F92:: @ 82B6F92
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!\n"
	.string "I’ll let you challenge me!$"

gText_082B6FC9:: @ 82B6FC9
	.string "I’m horribly busy, but I also happen\n"
	.string "to be {STR_VAR_1}’s no. {STR_VAR_2} apprentice.$"

gText_082B700C:: @ 82B700C
	.string "I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Glad to meet you!$"

gText_082B703A:: @ 82B703A
	.string "I serve as {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "May I begin?$"

gText_082B706A:: @ 82B706A
	.string "Eek! I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!\n"
	.string "I’ll do my best!$"

gText_082B709C:: @ 82B709C
	.string "Yeehaw! I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!\n"
	.string "Put ’em up!$"

gText_082B70CC:: @ 82B70CC
	.string "I’m {STR_VAR_1}’s 1,000th apprentice!\n"
	.string "Actually, I’m no. {STR_VAR_2}! Here goes!$"

gText_082B710A:: @ 82B710A
	.string "Yeah, I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice!\n"
	.string "Let’s get rockin’ and a-rollin’!$"

gText_082B714D:: @ 82B714D
	.string "Yippee-yahoo! I’m what you call\n"
	.string "{STR_VAR_1}’s no. {STR_VAR_2} apprentice!$"

gText_082B7185:: @ 82B7185
	.string "Cough! I’m {STR_VAR_1}’s no. {STR_VAR_2} apprentice.\n"
	.string "Good to meet you! Cough!$"

gText_082B71C1:: @ 82B71C1
	.string "This is nerve-racking…\n"
	.string "I’m the no. {STR_VAR_2} apprentice of {STR_VAR_1}.$"

gText_082B71F9:: @ 82B71F9
	.string "I am {STR_VAR_1}’s no. {STR_VAR_2} apprentice,\n"
	.string "and that’s no lie.$"

gText_082B7229:: @ 82B7229
	.string "Are you… {PLAYER}?\n"
	.string "Oh! Sniff…sob…\p"
	.string "Oh! S-sorry…\n"
	.string "I’m so nervous, I can’t help crying…\p"
	.string "I’m {STR_VAR_1}, and I really look up\n"
	.string "to you, {PLAYER}.\p"
	.string "I… I had this dream of one day meeting\n"
	.string "you and asking you about POKéMON.\p"
	.string "Please, please, {PLAYER}!\n"
	.string "Please teach me about POKéMON!$"

gText_082B731C:: @ 82B731C
	.string "Oh… B-but…\n"
	.string "Snivel… Waaaaaaah!\p"
	.string "Please!\n"
	.string "I’m begging you, please!$"

gText_082B735B:: @ 82B735B
	.string "Oh, really? You will?\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Oh… I’m sorry…\n"
	.string "I’m so happy, I’m crying…\p"
	.string "Um… Then please tell me!\n"
	.string "It’s about the BATTLE TOWER.\p"
	.string "Which would be better for me: Level 50\n"
	.string "or the Open Level?$"

gText_082B7423:: @ 82B7423
	.string "{STR_VAR_1}?\n"
	.string "Waaaaah!\p"
	.string "Oh! I’m so sorry!\n"
	.string "You’ve made me happy by choosing\l"
	.string "the level for me, and it’s made me cry…\p"
	.string "Snivel…\n"
	.string "Thank you so much!\l"
	.string "Please talk with me again!$"

gText_082B74C1:: @ 82B74C1
	.string "Wowee! You’re {PLAYER}, aren’t you?\n"
	.string "You’re awesomely strong, aren’t you?\p"
	.string "I’m {STR_VAR_1}!\n"
	.string "I just became a TRAINER!\p"
	.string "Please, {PLAYER}!\n"
	.string "Can you be my teacher and tell me\l"
	.string "lots about being a TRAINER?$"

gText_082B756F:: @ 82B756F
	.string "Aww, why?\n"
	.string "Oh, please? Pretty please?\l"
	.string "Please be my teacher, please!$"

gText_082B75B2:: @ 82B75B2
	.string "Yay! Great!\p"
	.string "The first thing I wanted to ask you is\n"
	.string "about the BATTLE TOWER!\p"
	.string "The Level 50 and Open Level Rooms…\n"
	.string "Which would be perfect for me?$"

gText_082B763F:: @ 82B763F
	.string "{STR_VAR_1}, huh? That’s true!\n"
	.string "I’ll do my best there!\p"
	.string "If we meet here again, please teach\n"
	.string "me something else, teacher!$"

gText_082B76AC:: @ 82B76AC
	.string "Um… Are you {PLAYER}?\n"
	.string "My name is {STR_VAR_1}.\p"
	.string "I want to become a POKéMON TRAINER,\n"
	.string "but I don’t know what to do…\p"
	.string "So I thought maybe I could ask you for\n"
	.string "advice because you’re so famous.\p"
	.string "{PLAYER}, could you give me advice?$"

gText_082B7772:: @ 82B7772
	.string "Oh, but…\p"
	.string "I sincerely want to become a POKéMON\n"
	.string "TRAINER!\p"
	.string "Please, can you answer my questions?$"

gText_082B77CE:: @ 82B77CE
	.string "Thank you!\n"
	.string "Here’s my first question right away!\p"
	.string "The BATTLE TOWER has two levels,\n"
	.string "Level 50 and Open Level, right?\p"
	.string "Which level do you think is more\n"
	.string "suitable for me?$"

gText_082B7871:: @ 82B7871
	.string "Oh, the {STR_VAR_1} challenge?\n"
	.string "Understood!\p"
	.string "If I have another question, I’ll come\n"
	.string "back here for your advice!$"

gText_082B78D4:: @ 82B78D4
	.string "Oh? Huh? You’re…\n"
	.string "No, that can’t be true.\p"
	.string "There isn’t any way that someone\n"
	.string "like me could meet {PLAYER}.\p"
	.string "…You really are {PLAYER}?\n"
	.string "I can’t believe I’m talking to you!\p"
	.string "When something this good happens,\n"
	.string "only terrible things will happen to me\l"
	.string "now, I just know it…\p"
	.string "…I’m sorry…\n"
	.string "I’m… {STR_VAR_1}…\p"
	.string "There isn’t anything special about\n"
	.string "me that I can be proud of…\p"
	.string "I shouldn’t even say anything about\n"
	.string "myself because you’ll forget…\p"
	.string "I had this dream that if I ever met\n"
	.string "you, {PLAYER}, that maybe I could ask\l"
	.string "you for advice as a TRAINER.\p"
	.string "But I don’t think you would agree\n"
	.string "to that.\p"
	.string "…Or will you be so kind as to give\n"
	.string "me advice?$"

gText_082B7B1A:: @ 82B7B1A
	.string "I knew it…\p"
	.string "It had to happen because I’m such\n"
	.string "a really boring nobody…\p"
	.string "But I thought just maybe…\n"
	.string "You won’t reconsider, will you?\p"
	.string "But I can’t give up just like that.\n"
	.string "I’ll ask you while I’m still lucky!\p"
	.string "Please, will you be so kind as to give\n"
	.string "me advice?$"

gText_082B7C13:: @ 82B7C13
	.string "Really? I can’t believe it!\n"
	.string "I can’t believe you’ll advise me!\l"
	.string "I… I’m so happy…\p"
	.string "What I want to ask you is really\n"
	.string "trivial, but I can’t decide…\p"
	.string "At the BATTLE TOWER, they let you\n"
	.string "choose Level 50 or Open Level.\p"
	.string "Which course do you think even I may\n"
	.string "have a chance at?$"

gText_082B7D18:: @ 82B7D18
	.string "{STR_VAR_1}? Okay!\n"
	.string "But do you really think someone like\l"
	.string "me would have a chance?\p"
	.string "I’ll do my best, even though I don’t\n"
	.string "think it will work.\p"
	.string "Thank you very much for spending\n"
	.string "time with someone like me.$"

gText_082B7DD4:: @ 82B7DD4
	.string "Oh! You’re {PLAYER}{STRING 5}, aren’t you?\p"
	.string "I’ve heard that you’re tough at\n"
	.string "POKéMON!\p"
	.string "I’m {STR_VAR_1}!\n"
	.string "I’ll be your friend!\p"
	.string "Did you know?\p"
	.string "You can’t win at the BATTLE FRONTIER\n"
	.string "if all you know is what they teach at\l"
	.string "the TRAINER’S SCHOOL.\p"
	.string "I’m willing to listen to your advice.\n"
	.string "You’ll agree, of course?$"

gText_082B7EE5:: @ 82B7EE5
	.string "Huh? Why are you refusing me?\n"
	.string "It’s me who’s asking you!\l"
	.string "You have to reconsider!$"

gText_082B7F35:: @ 82B7F35
	.string "Okay, so there is this something.\n"
	.string "I want you to decide it for me.\p"
	.string "You know that the BATTLE TOWER has\n"
	.string "Level 50 and Open Level Rooms?\p"
	.string "Which do you think would be good\n"
	.string "for me, {PLAYER}{STRING 5}?$"

gText_082B7FE8:: @ 82B7FE8
	.string "Okay, {STR_VAR_1} is suitable for me?\n"
	.string "Thank you!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082B8087:: @ 82B8087
	.string "Oh, hi, there! {PLAYER}{STRING 5}!\n"
	.string "I know you because you’re famous!\l"
	.string "Call me {STR_VAR_1}! Glad to meet you!\p"
	.string "I’m a TRIATHLETE, so I keep myself\n"
	.string "fit even while I raise POKéMON.\p"
	.string "I’m also involved with other things\n"
	.string "like work, napping, ballroom dancing…\p"
	.string "Being this busy, it’s not so easy for\n"
	.string "me to become a decent TRAINER.\p"
	.string "So, I have a proposition!\p"
	.string "There must be a reason why we met.\n"
	.string "So, {PLAYER}{STRING 5}, how about sharing your\l"
	.string "wisdom with me every so often?$"

gText_082B822B:: @ 82B822B
	.string "Oh, but, please?\n"
	.string "A guy like me needs someone like\l"
	.string "you, {PLAYER}{STRING 5}!\p"
	.string "Honestly, I need your advice!$"

gText_082B8286:: @ 82B8286
	.string "Thank you! That’s more like it!\n"
	.string "So, let’s start with an easy one!\p"
	.string "You know about the BATTLE TOWER’s\n"
	.string "two courses, right?\l"
	.string "You know, Level 50 and Open Level.\p"
	.string "Me being a busy guy, which one should\n"
	.string "I gear up for?$"

gText_082B8356:: @ 82B8356
	.string "{STR_VAR_1}, huh? Okay, gotcha.\n"
	.string "I’ll find time somehow and give it a go!\p"
	.string "…Whoops, I’d better go to work!\n"
	.string "Thanks! See you around!$"

gText_082B83CE:: @ 82B83CE
	.string "No way! Uh-uh!\n"
	.string "Are you maybe the real {PLAYER}?\p"
	.string "A-hah! Awesome! I’m {STR_VAR_1},\n"
	.string "so pleased to meet you!\p"
	.string "{PLAYER}, you’re very strong,\n"
	.string "aren’t you?\p"
	.string "Everyone’s talking about you!\p"
	.string "Oh! I just had this great idea!\n"
	.string "I’ll get advice off you, {PLAYER}!\l"
	.string "I’m sure it will make me tougher!\p"
	.string "Isn’t it a great idea?\n"
	.string "Please, I want your advice!$"

gText_082B84FC:: @ 82B84FC
	.string "Ahahaha, you can pretend to be mean,\n"
	.string "but you can’t fool me!\l"
	.string "You really mean okay, don’t you?$"

gText_082B8559:: @ 82B8559
	.string "Yay! I knew you’d have a big heart,\n"
	.string "{PLAYER}!\p"
	.string "What should I ask you first?\n"
	.string "…Oh, I thought of something!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I were to take a BATTLE TOWER\n"
	.string "challenge, which way should I go?\p"
	.string "Level 50 or Open Level?\n"
	.string "Which suits me more?$"

gText_082B8656:: @ 82B8656
	.string "Oh-oh-oh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thank you for a totally cool reply!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082B86EA:: @ 82B86EA
	.string "I beg your pardon, but…\n"
	.string "Are you {PLAYER}?\p"
	.string "I’m {STR_VAR_1}, and I am delighted to\n"
	.string "make your acquaintance.\p"
	.string "I have long been an admirer\n"
	.string "of yours…\p"
	.string "… … … … … …\p"
	.string "Um… I hope you don’t find this\n"
	.string "request too much of a burden, but…\p"
	.string "May I become your apprentice,\n"
	.string "{PLAYER}?$"

gText_082B87DA:: @ 82B87DA
	.string "Oh…!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "…I must have fainted from shock.\n"
	.string "I’m sorry, I must have misheard you.\p"
	.string "Please! Please say that you will\n"
	.string "accept me as your apprentice!$"

gText_082B887C:: @ 82B887C
	.string "Oh… I’m delighted!\p"
	.string "I don’t wish to waste your time,\n"
	.string "so please advise me on this.\p"
	.string "I plan to take a BATTLE TOWER\n"
	.string "challenge soon.\p"
	.string "However, there are two levels…\p"
	.string "Which would be most suitable for me?\n"
	.string "Level 50 or Open Level?$"

gText_082B8957:: @ 82B8957
	.string "{STR_VAR_1} is your choice!\n"
	.string "I see. I will do my best!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082B89C6:: @ 82B89C6
	.string "Eek! Eek! {PLAYER}!\n"
	.string "You spoke to me!\l"
	.string "I… I’m overjoyed!\p"
	.string "Me! My name is {STR_VAR_1}!\n"
	.string "I just became a TRAINER!\p"
	.string "I’m delighted I met you, {PLAYER},\n"
	.string "the big name in POKéMON circles!\p"
	.string "Oh-oh-oh, I know!\n"
	.string "May I ask a huge favor, {PLAYER}?\p"
	.string "Please take me in as your apprentice!\n"
	.string "I want to learn from you!$"

gText_082B8ACF:: @ 82B8ACF
	.string "Waaaah!\n"
	.string "{PLAYER} turned me down…\l"
	.string "It… It’s an invaluable experience!\p"
	.string "{PLAYER}, please! I want to hear\n"
	.string "an affirmative answer this time!\p"
	.string "I beg you for your guidance!$"

gText_082B8B66:: @ 82B8B66
	.string "Hieeeeh! {PLAYER} said yes!\n"
	.string "{PLAYER} said yes!\p"
	.string "I won’t be able to sleep tonight…\n"
	.string "Thank you ever so much!\p"
	.string "Then, here’s my question!\p"
	.string "At the BATTLE TOWER, what is right\n"
	.string "for me, Level 50 or Open Level?$"

gText_082B8C20:: @ 82B8C20
	.string "{STR_VAR_1}! Perfectly understood!\n"
	.string "I understand perfectly!\l"
	.string "I’m deliriously delighted!\p"
	.string "I hope you’ll be willing to teach me\n"
	.string "some more another time.$"

gText_082B8CAA:: @ 82B8CAA
	.string "Whoa! Could you be…\n"
	.string "Might you be… {PLAYER}{STRING 5}?!\l"
	.string "That strong and famous TRAINER?\l"
	.string "Well, hello, aren’t I just the luckiest!\p"
	.string "Hello, the name’s {STR_VAR_1}!\p"
	.string "I’ve been on the lookout for\n"
	.string "a POKéMON teacher.\p"
	.string "And with impeccably good timing,\n"
	.string "along came you, {PLAYER}{STRING 5}!\p"
	.string "So, there you have it, {PLAYER}{STRING 5}!\n"
	.string "Let me apprentice under you!$"

gText_082B8DD3:: @ 82B8DD3
	.string "Gwaaaah!\n"
	.string "You’re quite cool and tough…\p"
	.string "Don’t be that way, please.\n"
	.string "I’m asking you!$"

gText_082B8E24:: @ 82B8E24
	.string "Oh, yeah! That’s a solid reply!\n"
	.string "Excellent, I might add!\p"
	.string "So how about a first piece of advice\n"
	.string "on the BATTLE TOWER?\p"
	.string "If I were to go, what would be better?\n"
	.string "Level 50 or Open Level?$"

gText_082B8ED5:: @ 82B8ED5
	.string "Uh-huh, {STR_VAR_1} it is!\n"
	.string "OK, A-OK!\l"
	.string "I’ll go show my mettle, like, jam!\p"
	.string "All right, I’ll look to you as my mentor!\n"
	.string "Adios!$"

gText_082B8F45:: @ 82B8F45
	.string "Oh, hey, {PLAYER}{STRING 5}, right?\n"
	.string "The police were looking for you!\p"
	.string "… … …\n"
	.string "Of course I’m lying!\p"
	.string "Me, I’m {STR_VAR_1}. Despite the way\n"
	.string "I look, I’m the POKéMON CHAMPION!\l"
	.string "…That’s a lie, too!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at battling.\p"
	.string "So, how about you becoming my master\n"
	.string "about all things POKéMON?$"

gText_082B905F:: @ 82B905F
	.string "If you’re going to act cold like that,\n"
	.string "I’ll show you what I’ll do!\p"
	.string "Waaah! Waaah! Waaah!\n"
	.string "Hiccup!\p"
	.string "Hahaha, that was my FAKE TEARS!\p"
	.string "Come on, will you please be\n"
	.string "my POKéMON master?$"

gText_082B910E:: @ 82B910E
	.string "Yippee!\n"
	.string "I’ll buy you a boat for that!\p"
	.string "Of course I’m lying again!\n"
	.string "But… Thank you, master!\p"
	.string "You know how there’s Level 50 and\n"
	.string "Open Level at the BATTLE TOWER?\p"
	.string "I’m having trouble deciding which\n"
	.string "level I should challenge…\p"
	.string "Can you decide for me, master?$"

gText_082B9204:: @ 82B9204
	.string "Okay, so {STR_VAR_1} is better!\n"
	.string "I’ll go to the other level, then!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082B929C:: @ 82B929C
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy, and it means hi!\p"
	.string "I’m {STR_VAR_1}, the rappin’ SAILOR\n"
	.string "am I!\p"
	.string "Your turn now, tell me a little about\n"
	.string "yourself, give it a try!\p"
	.string "Uh-huh, uh-huh!\n"
	.string "{PLAYER}{STRING 5}’s your name,\l"
	.string "and POKéMON’s your game!\p"
	.string "And you’re at a delicate age\n"
	.string "when all the world’s your stage!\p"
	.string "Anyway, I just want to say,\n"
	.string "that you’re the tenth TRAINER\l"
	.string "I’ve spoken to today.\p"
	.string "Let’s make that a celebration!\n"
	.string "Become my mentor for commemoration!$"

gText_082B9438:: @ 82B9438
	.string "But!\n"
	.string "You have to work with me!\p"
	.string "Don’t be such a tease!\n"
	.string "Become my mentor, please!$"

gText_082B9488:: @ 82B9488
	.string "That’s it!\n"
	.string "{PLAYER}, you’ve got the spirit!\p"
	.string "So here’s my first question\n"
	.string "that begs your suggestion!\p"
	.string "It’s about the BATTLE TOWER,\n"
	.string "and it hinges on my power!\p"
	.string "Level 50 and Open Level there be,\n"
	.string "which is the one that’s good for me?$"

gText_082B9564:: @ 82B9564
	.string "Okay, {STR_VAR_1} it is, you say!\n"
	.string "I’ll go and take it on my way!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082B95D8:: @ 82B95D8
	.string "Say, hey, aren’t you {PLAYER}?\n"
	.string "What should I do? Talk to you?\l"
	.string "Why not? I’m already talking to you!\p"
	.string "{PLAYER}, are you surprised at me?\n"
	.string "I’d better tell you who I happen to be!\p"
	.string "{STR_VAR_1} is what you can call me.\n"
	.string "The brightest star in guitardom,\l"
	.string "that’s me!\p"
	.string "Are you receiving me?\n"
	.string "You are receiving me!\p"
	.string "My luck’s at its best,\n"
	.string "I’ll hit you with a request!\p"
	.string "{PLAYER}, let me be your underling!\n"
	.string "I want you to teach me everything!$"

gText_082B9763:: @ 82B9763
	.string "You’re turning me down, then?\n"
	.string "I’ll just have to ask you again!\p"
	.string "{PLAYER}, I beg to be your underling!\n"
	.string "I need you to teach me everything!$"

gText_082B97E5:: @ 82B97E5
	.string "Lucky, yeah, woohoo!\n"
	.string "Should I pop a question to you?\p"
	.string "Since we’re near the BATTLE TOWER,\n"
	.string "how about a question about its power?\p"
	.string "Of the choices you see,\n"
	.string "which is the right one for me?$"

gText_082B989A:: @ 82B989A
	.string "If {STR_VAR_1} is what you suggest,\n"
	.string "it must be the very best!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082B992D:: @ 82B992D
	.string "Oh, hi! You there!\n"
	.string "Can I get you to massage my shoulder?\p"
	.string "…Yes, there! That’s it!\n"
	.string "Ouch, ouch! Oooh, that feels great!\p"
	.string "My name’s {STR_VAR_1}.\n"
	.string "I take karate training, but my body’s\l"
	.string "not built to take the abuse…\p"
	.string "I decided I’ll battle POKéMON and\n"
	.string "toughen myself up.\p"
	.string "You’re {PLAYER}{STRING 5}, aren’t you?\n"
	.string "The POKéMON LEAGUE CHAMP?\p"
	.string "Listen, can I get you to give me\n"
	.string "advice?$"

gText_082B9A84:: @ 82B9A84
	.string "Oh, why?\p"
	.string "I won’t be a big bother, I promise!\n"
	.string "Please?$"

gText_082B9AB9:: @ 82B9AB9
	.string "Thank you. Mighty good of you!\n"
	.string "…Cough! Cough!\p"
	.string "Oogh, I have to toughen up quick…\p"
	.string "I’ll be heading off to the BATTLE TOWER\n"
	.string "right away, but what would be better\l"
	.string "for me? Level 50 or Open Level?$"

gText_082B9B76:: @ 82B9B76
	.string "Hm, all right. That’s {STR_VAR_1}.\n"
	.string "I’ll go there right away.\p"
	.string "I hope I can keep hitting you up for\n"
	.string "help--after all, you’re my mentor!$"

gText_082B9BF2:: @ 82B9BF2
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don’t look at me that way.\n"
	.string "You’re making me all self-conscious.\p"
	.string "I… I’m {STR_VAR_1}.\p"
	.string "I’m really embarrassed to say this,\n"
	.string "but I explore ancient ruins and such.\p"
	.string "I’m even more embarrassed to admit\n"
	.string "I’m interested in the BATTLE FRONTIER.\p"
	.string "{PLAYER}{STRING 5}, you have a reputation as\n"
	.string "a tough TRAINER…\p"
	.string "It’s hard for me to say this,\n"
	.string "but I want to ask something.\p"
	.string "Could you become my teacher and\n"
	.string "give me advice?$"

gText_082B9D83:: @ 82B9D83
	.string "Please don’t brush me off like this!\n"
	.string "I can’t live with the humiliation.\p"
	.string "Please become my teacher!\n"
	.string "I need your advice!$"

gText_082B9DF9:: @ 82B9DF9
	.string "Th-thank you…\p"
	.string "But please don’t look at me like that.\n"
	.string "It makes me all flustered.\p"
	.string "Please, answer me without looking\n"
	.string "at my eyes.\p"
	.string "At the BATTLE TOWER…\n"
	.string "Which level should I attempt?$"

gText_082B9EAA:: @ 82B9EAA
	.string "Oh… Okay!\n"
	.string "I’ll try my hand at that.\p"
	.string "I hope I can make a valiant challenge\n"
	.string "without getting all flustered…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082B9F55:: @ 82B9F55
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "You may call me {STR_VAR_1}.\p"
	.string "I have been toying with the idea of\n"
	.string "apprenticing under a strong TRAINER.\p"
	.string "So, I must say I’m lucky you came along!\n"
	.string "…You really are {PLAYER}{STRING 5}, yes?\p"
	.string "No, no, if you are real, it’s fine.\n"
	.string "I merely want you to recognize me\l"
	.string "as your apprentice.$"

gText_082BA084:: @ 82BA084
	.string "Oh?\n"
	.string "But what would compel you to refuse?\p"
	.string "I apologize for being skeptical about\n"
	.string "your identity.\p"
	.string "Please accept my apology and\n"
	.string "accept me as your apprentice.$"

gText_082BA11D:: @ 82BA11D
	.string "You really are accepting me?\n"
	.string "I don’t wish to celebrate prematurely.\p"
	.string "If it is true, I apologize.\n"
	.string "But now, I need your advice.\p"
	.string "If I were to enter the BATTLE TOWER,\n"
	.string "what would be worthy of me?\l"
	.string "Level 50 or Open Level?$"

gText_082BA1F3:: @ 82BA1F3
	.string "{STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I realize I can annoy, but it delights\n"
	.string "me that you have accepted me.\p"
	.string "Let us meet again!$"

gText_082BA2A3:: @ 82BA2A3
	.string "Sigh… Sob…\n"
	.string "Oh, {PLAYER}!\p"
	.string "I’m all tangled up in a dilemma\n"
	.string "that I can’t decide.\p"
	.string "I can’t decide what I should make\n"
	.string "my {STR_VAR_1} hold.\p"
	.string "Please tell me, {PLAYER}.\n"
	.string "What item should I make it hold?$"

gText_082BA34E:: @ 82BA34E
	.string "Oh, really? I shouldn’t make\n"
	.string "my {STR_VAR_1} hold anything?$"

gText_082BA380:: @ 82BA380
	.string "Oh, okay! I’m delighted it’s settled!\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Thank you so much!$"

gText_082BA3D2:: @ 82BA3D2
	.string "Oh, I’m so glad…\n"
	.string "I think I have that {STR_VAR_1}, too.\p"
	.string "I’m delighted it’s settled!\n"
	.string "Awesome! Wicked! Awoooh!\p"
	.string "Thank you so much!$"

gText_082BA448:: @ 82BA448
	.string "Waaaah! Please don’t be mean!\p"
	.string "That item {STR_VAR_1} was already\n"
	.string "recommended to me before, sob…\p"
	.string "Or do you mean I shouldn’t make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BA4D3:: @ 82BA4D3
	.string "Yay! It’s {PLAYER}!\n"
	.string "Great! I wanted to ask you something!\p"
	.string "Do you make your POKéMON hold items?\n"
	.string "I want to make mine hold items, but…\p"
	.string "What item would be good for\n"
	.string "{STR_VAR_1} to hold?\p"
	.string "What do you think?$"

gText_082BA58C:: @ 82BA58C
	.string "Huh? You mean my {STR_VAR_1} doesn’t\n"
	.string "have to hold anything?$"

gText_082BA5BF:: @ 82BA5BF
	.string "Oh, I get it! I’ll do that!\n"
	.string "Thanks for teaching me!$"

gText_082BA5F3:: @ 82BA5F3
	.string "Oh, wow! One {STR_VAR_1}, huh?\n"
	.string "Okay, I’ll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BA635:: @ 82BA635
	.string "Oh, uh, no, that’s not what I meant.\n"
	.string "I want to know about a different item\l"
	.string "than the ones I already know.\p"
	.string "Or do you mean that my POKéMON doesn’t\n"
	.string "have to hold anything this time?$"

gText_082BA6E6:: @ 82BA6E6
	.string "{PLAYER}, hello!\n"
	.string "It’s about my {STR_VAR_1}…\p"
	.string "I want to make it hold a good item.\n"
	.string "What would be good for it?$"

gText_082BA742:: @ 82BA742
	.string "Oh, then my {STR_VAR_1} doesn’t have\n"
	.string "to hold anything?$"

gText_082BA770:: @ 82BA770
	.string "Okay, I got it!\n"
	.string "See you again!$"

gText_082BA78F:: @ 82BA78F
	.string "Oh, the item {STR_VAR_1}?\n"
	.string "Understood!\p"
	.string "I’ll do my best to find one!\n"
	.string "See you again!$"

gText_082BA7D8:: @ 82BA7D8
	.string "Somebody taught me about\n"
	.string "the {STR_VAR_1} already.\p"
	.string "I want my POKéMON to hold a different\n"
	.string "kind of item.\p"
	.string "Or do you think {STR_VAR_2} doesn’t\n"
	.string "have to hold anything?$"

gText_082BA867:: @ 82BA867
	.string "Hello, {PLAYER}…\n"
	.string "I’m sorry to disturb you, but I have\l"
	.string "something else I wanted to ask you.\p"
	.string "I don’t think I’m good enough to win\n"
	.string "matches on my own, so I’m thinking of\l"
	.string "making my {STR_VAR_1} hold an item.\p"
	.string "But I don’t know what would be good.\p"
	.string "{PLAYER}, please, could you decide\n"
	.string "for me?$"

gText_082BA96B:: @ 82BA96B
	.string "A POKéMON belonging to someone like me\n"
	.string "would be better off without an item?$"

gText_082BA9B7:: @ 82BA9B7
	.string "I understand…\n"
	.string "You’re saying I shouldn’t rely on items.\l"
	.string "I’ll do my best not to!\p"
	.string "Thank you very much!$"

gText_082BAA1B:: @ 82BAA1B
	.string "The item {STR_VAR_1}, okay.\n"
	.string "I’m not sure if I can get one…\l"
	.string "No! I’ll do my best to get it.\p"
	.string "Thank you very much!$"

gText_082BAA81:: @ 82BAA81
	.string "Oh, but…\n"
	.string "I think I’ve heard about that before…\p"
	.string "Is it maybe because I haven’t handled\n"
	.string "the item {STR_VAR_1} very well?\p"
	.string "Or do you mean I shouldn’t make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BAB22:: @ 82BAB22
	.string "Oh, {PLAYER}{STRING 5}.\n"
	.string "There’s something I wanted to ask you.\p"
	.string "You know how you decided which\n"
	.string "POKéMON I should have for me?\p"
	.string "But I never asked you what item\n"
	.string "it should be holding.\p"
	.string "Since you already gave me advice,\n"
	.string "how about seeing this to the end?\p"
	.string "What would be good? I want to make\n"
	.string "my {STR_VAR_1} hold something.$"

gText_082BAC43:: @ 82BAC43
	.string "Oh! So my {STR_VAR_1} should do\n"
	.string "the best it can empty-handed?$"

gText_082BAC78:: @ 82BAC78
	.string "If you think that’s best, I’ll do that.\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082BAD17:: @ 82BAD17
	.string "The item {STR_VAR_1}, huh?\n"
	.string "Not bad. I’ll use it!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082BADB6:: @ 82BADB6
	.string "Huh? What are you saying?\n"
	.string "You told me about the {STR_VAR_1}\l"
	.string "already before.\p"
	.string "Or do you mean my {STR_VAR_2} should\n"
	.string "do the best it can empty-handed?$"

gText_082BAE36:: @ 82BAE36
	.string "Yo, {PLAYER}{STRING 5}!\p"
	.string "We’re both busy, but we seem to run\n"
	.string "into each other often anyway!\p"
	.string "Today I have to do some walking,\n"
	.string "cleaning, and brushing.\p"
	.string "I haven’t even had the time to buy\n"
	.string "my precious {STR_VAR_1} anything.\p"
	.string "I don’t have any time, so how about\n"
	.string "giving me advice on what I should make\l"
	.string "my {STR_VAR_1} hold?$"

gText_082BAF4E:: @ 82BAF4E
	.string "Oh, so me being a busy guy, you say\n"
	.string "my {STR_VAR_1} doesn’t need anything?$"

gText_082BAF8F:: @ 82BAF8F
	.string "Okay, gotcha.\n"
	.string "I won’t need any time for that.\p"
	.string "Thanks today!\n"
	.string "See you around!$"

gText_082BAFDB:: @ 82BAFDB
	.string "Okay, gotcha.\n"
	.string "I’ll find time somehow and find\l"
	.string "that {STR_VAR_1} you recommended.\p"
	.string "I’m glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082BB05F:: @ 82BB05F
	.string "Huh? I already know about\n"
	.string "that {STR_VAR_1}.\p"
	.string "Oh, right, I get it.\n"
	.string "So me being a busy guy, you say\l"
	.string "my {STR_VAR_2} doesn’t need anything?$"

gText_082BB0D4:: @ 82BB0D4
	.string "Hiya, {PLAYER}! It’s me!\n"
	.string "I need to tap your mind again today.\l"
	.string "Please, I need your advice!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I want to make my {STR_VAR_1} hold\n"
	.string "an item, what should it be?$"

gText_082BB18C:: @ 82BB18C
	.string "Is that right? My {STR_VAR_1} doesn’t\n"
	.string "need to hold an item, you’re saying.$"

gText_082BB1CE:: @ 82BB1CE
	.string "Okay, that’s what I’ll do!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082BB242:: @ 82BB242
	.string "Uh-huh! One {STR_VAR_1}.\n"
	.string "What a cool choice!\l"
	.string "I’ll definitely try that!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082BB2D9:: @ 82BB2D9
	.string "Ahahah! That’s silly!\n"
	.string "You already told me about that\l"
	.string "{STR_VAR_1} before!\p"
	.string "Are you feeling okay, {PLAYER}?\p"
	.string "Oh, wait! My {STR_VAR_2} doesn’t\n"
	.string "need to hold an item, you’re saying.$"

gText_082BB370:: @ 82BB370
	.string "Hello, {PLAYER}. I hope you’ve been\n"
	.string "keeping well.\p"
	.string "May I approach you for advice?\p"
	.string "In a recent battle, my opponent\n"
	.string "seemed to have given his POKéMON\l"
	.string "an item to hold.\p"
	.string "As a result, I was defeated…\p"
	.string "I don’t wish to be left behind.\n"
	.string "I would like to make my {STR_VAR_1}\l"
	.string "hold an item, too.\p"
	.string "It would please me if you could decide\n"
	.string "what would be right for my POKéMON…$"

gText_082BB4C3:: @ 82BB4C3
	.string "In other words… My POKéMON has\n"
	.string "no need to hold an item?$"

gText_082BB4FB:: @ 82BB4FB
	.string "I understand clearly now!\n"
	.string "I will keep trying like this.\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BB575:: @ 82BB575
	.string "One {STR_VAR_1} it is!\n"
	.string "I will order it right away.\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BB5E1:: @ 82BB5E1
	.string "You’ve already told me about that,\n"
	.string "and I already have it.\p"
	.string "Or are you saying… My POKéMON has\n"
	.string "no need to hold an item?$"

gText_082BB656:: @ 82BB656
	.string "Eek! {PLAYER}!\n"
	.string "I… I’m overjoyed to see you again!\p"
	.string "Oh-oh-oh! There’s something I just\n"
	.string "had to ask you, {PLAYER}!\p"
	.string "Please decide what my {STR_VAR_1}\n"
	.string "should be holding!$"

gText_082BB6E5:: @ 82BB6E5
	.string "Oh, wow! I didn’t expect that answer!\n"
	.string "So, a hold item isn’t necessary?$"

gText_082BB72C:: @ 82BB72C
	.string "Perfectly understood!\n"
	.string "I’ll keep at this without an item!\p"
	.string "I hope you’ll be willing to teach me\n"
	.string "some more another time.$"

gText_082BB7A2:: @ 82BB7A2
	.string "{STR_VAR_1}! I’ll use that!\p"
	.string "Um… Could it be, {PLAYER}, you also\n"
	.string "make your POKéMON hold that item?\p"
	.string "I’ll be sure to get it!\n"
	.string "I hope you’ll be willing to teach me\l"
	.string "some more another time.$"

gText_082BB84A:: @ 82BB84A
	.string "Oh? You recommended that\n"
	.string "{STR_VAR_1} before, too.\p"
	.string "Or is it the best thing to hold?\n"
	.string "Or do you mean that my {STR_VAR_2}\l"
	.string "doesn’t need anything to hold?$"

gText_082BB8CD:: @ 82BB8CD
	.string "Hola!\n"
	.string "My maestro, {PLAYER}{STRING 5}!\p"
	.string "I want to hit you up for advice on\n"
	.string "POKéMON tools.\p"
	.string "What do you think would be good for\n"
	.string "my {STR_VAR_1} to hold?\p"
	.string "Don’t be shy now.\n"
	.string "Let’s blurt it out!$"

gText_082BB970:: @ 82BB970
	.string "Oh? So, you’re saying my {STR_VAR_1}\n"
	.string "can win without holding any item?$"

gText_082BB9AE:: @ 82BB9AE
	.string "Si, bueno!\n"
	.string "I’ll give it my best shot, like, slam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BBA05:: @ 82BBA05
	.string "Uh-huh, that’s one {STR_VAR_1}?\n"
	.string "Si, bueno!\l"
	.string "I’ll go find me one, like, bam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BBA6C:: @ 82BBA6C
	.string "No, no! You already told me about\n"
	.string "that {STR_VAR_1} thing before.\p"
	.string "Oh, now wait just one minute here…\n"
	.string "So, you’re saying my {STR_VAR_2}\l"
	.string "can win without holding any item?$"

gText_082BBB01:: @ 82BBB01
	.string "{PLAYER}{STRING 5}, something unbelievable\n"
	.string "has happened!\p"
	.string "I woke up this morning, and my POKéMON\n"
	.string "had 10 NUGGETS!\p"
	.string "Of course I’m lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at thinking about\l"
	.string "what items POKéMON should hold.\p"
	.string "So, how about deciding for me what\n"
	.string "my {STR_VAR_1} should hold, master?$"

gText_082BBC1C:: @ 82BBC1C
	.string "What’s that mean?\n"
	.string "Don’t make it hold anything?$"

gText_082BBC4B:: @ 82BBC4B
	.string "Okay, so it shouldn’t hold anything.\n"
	.string "Then, I’d better get something for it!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082BBCF6:: @ 82BBCF6
	.string "Okay, so it’s one {STR_VAR_1}!\n"
	.string "I’ll make it hold anything but that!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082BBD90:: @ 82BBD90
	.string "Um, you told me about that before,\n"
	.string "didn’t you?\p"
	.string "Isn’t there something else?\p"
	.string "Or do you mean, don’t make\n"
	.string "my {STR_VAR_2} hold anything?$"

gText_082BBE0B:: @ 82BBE0B
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin’ SAILOR am I!\n"
	.string "I present to you a question\l"
	.string "that’s pretty fly!\p"
	.string "It’s an item question\n"
	.string "that begs your suggestion!\p"
	.string "My {STR_VAR_1} needs an item to hold,\n"
	.string "What should it be, if I may be bold?$"

gText_082BBEE5:: @ 82BBEE5
	.string "Is that right?\n"
	.string "My {STR_VAR_1} doesn’t need to be\l"
	.string "holding anything tight?$"

gText_082BBF25:: @ 82BBF25
	.string "Okay, I hear you, sure I do!\n"
	.string "My POKéMON will go empty-handed, too!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082BBFA4:: @ 82BBFA4
	.string "Okay, one {STR_VAR_1},\n"
	.string "that’s what I’ll use.\l"
	.string "I was right to make you choose!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082BC024:: @ 82BC024
	.string "Okay, one {STR_VAR_1}, you say?\n"
	.string "You told me that the other day.\l"
	.string "I need a new idea, a brand new way.\p"
	.string "Or, what, is that right?\n"
	.string "My POKéMON doesn’t need to hold\l"
	.string "anything tight?$"

gText_082BC0C8:: @ 82BC0C8
	.string "Say, hey, {PLAYER}!\n"
	.string "I found you again today!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I’m already talking to you!\p"
	.string "{PLAYER}, are you getting sick of me?\n"
	.string "Nah, no way, that can’t be.\p"
	.string "Will you hear me out?\n"
	.string "I’m looking for advice--that’s what\l"
	.string "I’m talking about.\p"
	.string "It’s about a hold item for\n"
	.string "my {STR_VAR_1} that’d be good.\l"
	.string "My indecision is making me brood.$"

gText_082BC213:: @ 82BC213
	.string "My {STR_VAR_1} needs nothing?\n"
	.string "Doesn’t need to hold anything?$"

gText_082BC247:: @ 82BC247
	.string "If holding nothing is the best,\n"
	.string "I’ll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BC2DD:: @ 82BC2DD
	.string "If holding that {STR_VAR_1} is\n"
	.string "the best, I’ll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BC373:: @ 82BC373
	.string "Haven’t I heard about that\n"
	.string "{STR_VAR_1} before?\l"
	.string "I’m certain I have, that’s for sure!\p"
	.string "I need a new something!\n"
	.string "Or, my {STR_VAR_2} needs nothing?\l"
	.string "Doesn’t need to hold anything?$"

gText_082BC40E:: @ 82BC40E
	.string "Gwah! Ouch! {PLAYER}{STRING 5}, my arm’s broken!\n"
	.string "Don’t touch it, please!\p"
	.string "I must’ve broken it while I was trying\n"
	.string "out different hold items with my posse\l"
	.string "of POKéMON.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, what do you think would be\n"
	.string "good for my {STR_VAR_1} to hold?$"

gText_082BC514:: @ 82BC514
	.string "Ouch…\p"
	.string "So your suggestion is my {STR_VAR_1}\n"
	.string "doesn’t have to hold anything?$"

gText_082BC555:: @ 82BC555
	.string "Hm, all right. That would be easier\n"
	.string "for me, the way things are now.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BC5CE:: @ 82BC5CE
	.string "Hm, all right. That’s one {STR_VAR_1}.\n"
	.string "My POKéMON’s arm is fine, so I’ll make\l"
	.string "it hold that item right away.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BC666:: @ 82BC666
	.string "No, no, you told me about that\n"
	.string "{STR_VAR_1} before, remember?\p"
	.string "How about telling me something\n"
	.string "even better?\p"
	.string "Oh, wait a second.\n"
	.string "So your suggestion is my {STR_VAR_2}\l"
	.string "doesn’t have to hold anything?$"

gText_082BC714:: @ 82BC714
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…\p"
	.string "Please, don’t look at me that way.\n"
	.string "My POKéMON don’t have anything.\p"
	.string "I… I’m really embarrassed about this,\n"
	.string "but I really need your advice.\p"
	.string "I can’t decide what hold item would\n"
	.string "make my {STR_VAR_1} strong.\p"
	.string "{PLAYER}{STRING 5}, what do you think would\n"
	.string "be good?$"

gText_082BC808:: @ 82BC808
	.string "Oh… Then, you think it would be better\n"
	.string "if my {STR_VAR_1} didn’t have an item?$"

gText_082BC84D:: @ 82BC84D
	.string "Oh… Okay!\n"
	.string "I’ll go without an item.\p"
	.string "This is nerve-racking, though.\n"
	.string "Wouldn’t it be too cool?\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BC8EA:: @ 82BC8EA
	.string "Oh… Okay!\n"
	.string "I’ll go with that {STR_VAR_1}.\p"
	.string "This is nerve-racking, though.\n"
	.string "Wouldn’t it be too cool?\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BC984:: @ 82BC984
	.string "B-but I already heard about that.\p"
	.string "Please don’t brush me off like this!\n"
	.string "I can’t live with the humiliation.\p"
	.string "Oh… Am I jumping to conclusions?\n"
	.string "Do you think it would be better if\l"
	.string "my {STR_VAR_2} didn’t have an item?$"

gText_082BCA4D:: @ 82BCA4D
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps you’re a twin?\p"
	.string "Oh, no, no, no, don’t worry!\n"
	.string "If you really are {PLAYER}, please\l"
	.string "forget about my rudeness.\p"
	.string "What I would like is some more of\n"
	.string "your fine advice.\p"
	.string "I have here my {STR_VAR_1} that I wish\n"
	.string "to make hold a convenient item.\p"
	.string "What would be worthy of it?$"

gText_082BCB75:: @ 82BCB75
	.string "It’s better if it held nothing?\n"
	.string "Are you certain?$"

gText_082BCBA6:: @ 82BCBA6
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "Let us meet again!$"

gText_082BCBFC:: @ 82BCBFC
	.string "One {STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope my POKéMON will be able to\n"
	.string "put it to good use.\p"
	.string "Let us meet again!$"

gText_082BCCA4:: @ 82BCCA4
	.string "No, no, wait a minute.\n"
	.string "I believe you taught me that before.\p"
	.string "I would like you to recommend\n"
	.string "something different this time.\p"
	.string "Perhaps you’re suggesting that\n"
	.string "my {STR_VAR_2} should hold nothing?\l"
	.string "Are you certain?$"

gText_082BCD68:: @ 82BCD68
	.string "Waah, {PLAYER}!\n"
	.string "I have a dilemma, sob…\p"
	.string "I want to begin battling other people,\n"
	.string "but I don’t know what to do.\p"
	.string "How should I line up my POKéMON\n"
	.string "so they’ll be at their strongest?\p"
	.string "Please tell me, {PLAYER}.\n"
	.string "If you were me, which of these POKéMON\l"
	.string "would you send out first?$"

gText_082BCE64:: @ 82BCE64
	.string "My {STR_VAR_1} should go first?\n"
	.string "Waaaaah!\p"
	.string "Oh! I’m so sorry!\n"
	.string "You’ve made me happy by choosing\l"
	.string "my first POKéMON, and it’s made me cry…\p"
	.string "Thank you so much!$"

gText_082BCEF2:: @ 82BCEF2
	.string "Yay! It’s {PLAYER}!\n"
	.string "Great! I wanted to ask you something!\p"
	.string "Um, of my POKéMON, which do you\n"
	.string "think should go out first?$"

gText_082BCF61:: @ 82BCF61
	.string "My {STR_VAR_1}? That’s true.\n"
	.string "Okay, I’ll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BCFA1:: @ 82BCFA1
	.string "{PLAYER}, hello!\p"
	.string "I think, in a battle, it’s very important\n"
	.string "which POKéMON comes out first.\p"
	.string "Out of the POKéMON that I have,\n"
	.string "which would be good to send out first?$"

gText_082BD03C:: @ 82BD03C
	.string "My {STR_VAR_1} goes first?\n"
	.string "Okay, I got it!\p"
	.string "See you again!$"

gText_082BD06D:: @ 82BD06D
	.string "Hello, {PLAYER}…\n"
	.string "I’m sorry to disturb you again with\l"
	.string "another question.\p"
	.string "I have so little confidence, I don’t\n"
	.string "know what I’d do without you, {PLAYER}.\p"
	.string "It may be a waste of time for me to\n"
	.string "even worry about it, but I just can’t\l"
	.string "decide something…\p"
	.string "Which of my POKéMON should I send\n"
	.string "out first in a battle?$"

gText_082BD18A:: @ 82BD18A
	.string "My {STR_VAR_1}?\n"
	.string "Understood!\p"
	.string "I can’t believe that you would bother\n"
	.string "to answer my questions so often!\p"
	.string "I’m so grateful that you would even\n"
	.string "speak with me… Thank you!$"

gText_082BD222:: @ 82BD222
	.string "Oh, {PLAYER}{STRING 5}! It’s me!\n"
	.string "I’m so glad to see you because I have\l"
	.string "this little problem.\p"
	.string "I can’t decide how my POKéMON should\n"
	.string "be lined up. Could you decide for me?\p"
	.string "Oh, you don’t need to decide the whole\n"
	.string "party right now.\p"
	.string "How about deciding just the first\n"
	.string "POKéMON for me?$"

gText_082BD325:: @ 82BD325
	.string "My {STR_VAR_1}? That’s great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082BD3B1:: @ 82BD3B1
	.string "Hi, my teacher {PLAYER}{STRING 5}!\n"
	.string "I’m busy again today!\p"
	.string "I have to do some cycling, shopping,\n"
	.string "and humming.\p"
	.string "I haven’t even had the time to decide\n"
	.string "how to line up my POKéMON team.\p"
	.string "So, how about checking out my team?\n"
	.string "Which one should go first?$"

gText_082BD493:: @ 82BD493
	.string "Okay, gotcha.\n"
	.string "I have enough time at least to put\l"
	.string "my {STR_VAR_1} at the head of the line!\p"
	.string "Whoops, my girlfriend’s waiting!\n"
	.string "Thanks! See you around!$"

gText_082BD51C:: @ 82BD51C
	.string "Yoohoo! Hiya, {PLAYER}!\n"
	.string "You always walk around looking tough!\p"
	.string "Listen, I need something from you\n"
	.string "again! It’s the usual thing!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is about my team.\p"
	.string "Which POKéMON of mine should be first\n"
	.string "to go out in a battle?$"

gText_082BD609:: @ 82BD609
	.string "Hmhm!\n"
	.string "My {STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082BD697:: @ 82BD697
	.string "Thank you so much for stopping to\n"
	.string "chat with me, {PLAYER}.\p"
	.string "I know I’m taking advantage of your\n"
	.string "kindness, but may I ask for advice?\p"
	.string "I would like you to decide on the order\n"
	.string "of my POKéMON team.\p"
	.string "It would please me if you could decide\n"
	.string "which POKéMON should come first.$"

gText_082BD797:: @ 82BD797
	.string "My {STR_VAR_1} it is!\n"
	.string "I will put it first right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BD806:: @ 82BD806
	.string "Eek! {PLAYER}!\n"
	.string "I… I’m overjoyed to see you again!\p"
	.string "My POKéMON have become much\n"
	.string "stronger!\p"
	.string "But I don’t always win. It seems to\n"
	.string "depend on which POKéMON goes first.\p"
	.string "{PLAYER}, please, I need your help!\p"
	.string "Please decide which of my POKéMON\n"
	.string "should go out first!$"

gText_082BD8F5:: @ 82BD8F5
	.string "Sigh… I’m overwhelmed with happiness…\p"
	.string "It’s like a dream having you decide\n"
	.string "for me, {PLAYER}.\p"
	.string "But perfectly understood!\n"
	.string "I will go with my {STR_VAR_1} first!\p"
	.string "I hope you’ll be willing to teach me\n"
	.string "some more another time.$"

gText_082BD9BE:: @ 82BD9BE
	.string "Hello, hello!\n"
	.string "My mentor, {PLAYER}{STRING 5}!\l"
	.string "Hit me with your sage advice today!\p"
	.string "You see, I pulled together a team of\n"
	.string "three POKéMON. So far so good.\p"
	.string "But the team’s battling order’s not\n"
	.string "settled yet.\p"
	.string "This is where you come in, {PLAYER}{STRING 5}!\n"
	.string "You decide which POKéMON leads off!\p"
	.string "Don’t be shy now.\n"
	.string "Let’s blurt it out!$"

gText_082BDAE1:: @ 82BDAE1
	.string "Uh-huh, my {STR_VAR_1} leads off!\n"
	.string "OK, A-OK!\l"
	.string "I’ll reorder the lineup, like, wham!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BDB4E:: @ 82BDB4E
	.string "{PLAYER}{STRING 5}, listen!\n"
	.string "It’s a crisis!\p"
	.string "My POKéMON, all three of them, go into\n"
	.string "battle at once!\p"
	.string "Of course that’s impossible!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at thinking about\l"
	.string "how I should line up my POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "POKéMON should go first, master?$"

gText_082BDC6B:: @ 82BDC6B
	.string "Okay, so it’s my {STR_VAR_1} you chose?\n"
	.string "I’ll let any but that one go first!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082BDD0D:: @ 82BDD0D
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin’ SAILOR am I!\n"
	.string "I present to you a question\l"
	.string "that’s pretty fly!\p"
	.string "It’s a team lineup question\n"
	.string "that begs your suggestion!\p"
	.string "Out of this lot, which should go first\n"
	.string "as the first on the spot?$"

gText_082BDDEC:: @ 82BDDEC
	.string "Okay, I hear you, sure I do!\n"
	.string "I’ll switch them up, that I’ll do!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082BDE68:: @ 82BDE68
	.string "Yahoo, {PLAYER}!\n"
	.string "How do you do?\p"
	.string "What should I do? Go ahead and ask?\n"
	.string "Uh-huh, I have something to ask!\l"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\p"
	.string "You have to decide, which of my\n"
	.string "POKéMON is the first to ride!\l"
	.string "Into battle, I mean to say.$"

gText_082BDF4D:: @ 82BDF4D
	.string "My {STR_VAR_1}? Yes!\n"
	.string "That’ll do, there’s no distress!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BDFD8:: @ 82BDFD8
	.string "…Oof…ooch… {PLAYER}{STRING 5}…\n"
	.string "My stomach’s hurting all of a sudden…\p"
	.string "…It’s getting better now…\p"
	.string "I must’ve worried myself sick racking\n"
	.string "my brains on how I should line up\l"
	.string "my posse of POKéMON.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, which of my POKéMON should\n"
	.string "go first? So I’d win, I mean.$"

gText_082BE0FD:: @ 82BE0FD
	.string "Hm, all right.\n"
	.string "My {STR_VAR_1} goes first.\p"
	.string "I’ll fix the lineup like that after\n"
	.string "I have my supper.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BE189:: @ 82BE189
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}?\p"
	.string "Please, don’t look at me that way.\n"
	.string "You’re making me feel all flustered.\p"
	.string "Um…\n"
	.string "I really need your advice.\p"
	.string "It makes me bashful to say this,\n"
	.string "but I chose my 3-POKéMON team.\l"
	.string "I can’t decide on the order, though.\p"
	.string "Which POKéMON should I send out first\n"
	.string "so I at least look capable?$"

gText_082BE2A5:: @ 82BE2A5
	.string "Oh… Okay!\n"
	.string "I’ll lead with my {STR_VAR_1}.\p"
	.string "I hope I can do my best without\n"
	.string "getting all flustered.\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BE33E:: @ 82BE33E
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps you’re a clever look-alike?\p"
	.string "Oh, no, no, no, don’t worry!\n"
	.string "If you really are {PLAYER}, please\l"
	.string "forget about my rudeness.\p"
	.string "What I would like is your fine advice.\p"
	.string "I have here my POKéMON team.\n"
	.string "I would like you to tell me which one\l"
	.string "should go first in a battle.$"

gText_082BE46C:: @ 82BE46C
	.string "My {STR_VAR_1}…\n"
	.string "You aren’t pulling my leg?\p"
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I am as you see, but I shall do\n"
	.string "my best.\p"
	.string "Let us meet again!$"

gText_082BE50D:: @ 82BE50D
	.string "Snivel…\n"
	.string "Oh, {PLAYER}!\p"
	.string "What perfect timing!\n"
	.string "There’s something I just can’t decide…\p"
	.string "I can’t decide which POKéMON I should\n"
	.string "be using.\p"
	.string "I can’t decide between the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}…\p"
	.string "{PLAYER}, which do you think will give\n"
	.string "even me a chance at winning?$"

gText_082BE5F5:: @ 82BE5F5
	.string "Snivel… I… I understand!\n"
	.string "Oh! I’m so sorry!\l"
	.string "You’ve made me so happy, I’m crying…\p"
	.string "I’ll do my best to catch one\n"
	.string "{STR_VAR_1}!\p"
	.string "Thank you so much!$"

gText_082BE679:: @ 82BE679
	.string "Yay! It’s {PLAYER}!\n"
	.string "Yay, you came at the right time, too!\l"
	.string "I need your advice again!\p"
	.string "Um, I’m all mixed up--should I use\n"
	.string "my {STR_VAR_1} or {STR_VAR_2}…\p"
	.string "Which do you think I should raise,\n"
	.string "{PLAYER}?$"

gText_082BE71E:: @ 82BE71E
	.string "Oh, so my {STR_VAR_1} is better!\n"
	.string "Okay, I’ll do that!\p"
	.string "Thanks for teaching me!$"

gText_082BE762:: @ 82BE762
	.string "{PLAYER}, hello!\n"
	.string "I have a question I wanted to ask.\p"
	.string "I’m in a dilemma over whether I should\n"
	.string "raise one {STR_VAR_1} or {STR_VAR_2}.\p"
	.string "Which POKéMON do you think will\n"
	.string "be stronger?$"

gText_082BE7F8:: @ 82BE7F8
	.string "{STR_VAR_1} is your choice?\n"
	.string "Okay, I got it!\p"
	.string "I’ll go catch a strong {STR_VAR_1}\n"
	.string "right away!\p"
	.string "See you again!$"

gText_082BE850:: @ 82BE850
	.string "Hello, {PLAYER}…\p"
	.string "Um, you’ve probably already forgotten\n"
	.string "about someone like me…\p"
	.string "…But that doesn’t matter if you\n"
	.string "could give me advice…\p"
	.string "I can’t decide on the one kind of\n"
	.string "POKéMON I should raise…\p"
	.string "I’ve narrowed the field to the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, but that’s\l"
	.string "where I became stuck…\p"
	.string "{PLAYER}, you probably don’t want to\n"
	.string "bother, but please decide for me.$"

gText_082BE99C:: @ 82BE99C
	.string "But will a wild {STR_VAR_1} even pay\n"
	.string "attention to me?\p"
	.string "I will try!\p"
	.string "But will I even be able to catch one…\n"
	.string "No! I’ll do my best!\p"
	.string "Thank you!$"

gText_082BEA1B:: @ 82BEA1B
	.string "Oh, {PLAYER}{STRING 5}! I’m so glad to see you!\n"
	.string "I was about to go looking for you!\p"
	.string "Can you decide what kind of POKéMON\n"
	.string "I should use?\p"
	.string "For instance…\n"
	.string "How about the POKéMON {STR_VAR_1}\l"
	.string "and {STR_VAR_2}?\p"
	.string "Which one do you think would be\n"
	.string "better?$"

gText_082BEAE9:: @ 82BEAE9
	.string "{STR_VAR_1}? That’s great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082BEB72:: @ 82BEB72
	.string "If it isn’t {PLAYER}{STRING 5}! How’s it going?\n"
	.string "I’m busy again as always!\p"
	.string "I want to do good with POKéMON, too,\n"
	.string "but I haven’t been able to decide\l"
	.string "which POKéMON I should use.\p"
	.string "You know how {STR_VAR_1} look strong?\n"
	.string "But {STR_VAR_2} are tough to ignore.\p"
	.string "{PLAYER}{STRING 5}, give me some of your good\n"
	.string "advice! Which one’d be good for me?$"

gText_082BEC8E:: @ 82BEC8E
	.string "Okay, gotcha.\n"
	.string "I’ll find time somehow and catch me\l"
	.string "that {STR_VAR_1} you recommended.\p"
	.string "I’m glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082BED16:: @ 82BED16
	.string "Oh!\n"
	.string "Yay, it’s {PLAYER}!\p"
	.string "I didn’t waste any time boasting to\n"
	.string "my friends about meeting you!\p"
	.string "I need to tap your mind again today.\n"
	.string "It’s an easy one for you!\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "If I were to raise a POKéMON,\n"
	.string "and the choices were one {STR_VAR_1}\l"
	.string "or {STR_VAR_2}, which should it be?$"

gText_082BEE29:: @ 82BEE29
	.string "Ahhh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082BEEB4:: @ 82BEEB4
	.string "Oh, is it you, {PLAYER}?\n"
	.string "I’m delighted to see you again!\p"
	.string "Ever since I became your apprentice,\n"
	.string "my confidence has been blooming.\p"
	.string "I think I’m ready to raise a POKéMON\n"
	.string "of my own!\p"
	.string "{PLAYER}, may I impose on you to choose\n"
	.string "which POKéMON I should raise?\p"
	.string "The choices are the POKéMON\n"
	.string "{STR_VAR_1} or {STR_VAR_2}…\l"
	.string "Which POKéMON is right for me?$"

gText_082BEFE2:: @ 82BEFE2
	.string "One {STR_VAR_1} it is!\n"
	.string "I will find one right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082BF04E:: @ 82BF04E
	.string "Eek! {PLAYER}! I met you again!\n"
	.string "I… I’m overjoyed!\p"
	.string "Oh-oh-oh, I know!\n"
	.string "I shouldn’t pass up this opportunity!\p"
	.string "May I ask a huge favor, {PLAYER}?\n"
	.string "Please choose a POKéMON for me!\p"
	.string "Please decide which would be better,\n"
	.string "{STR_VAR_1} or {STR_VAR_2}!$"

gText_082BF11D:: @ 82BF11D
	.string "Wow! You decided for me!\n"
	.string "One {STR_VAR_1} is what I’ll raise to\l"
	.string "the best of my ability.\p"
	.string "I hope you’ll be willing to teach me\n"
	.string "some more another time.$"

gText_082BF1A8:: @ 82BF1A8
	.string "Hey, hey!\n"
	.string "My mentor, {PLAYER}{STRING 5}!\p"
	.string "Hello, I’ve been looking for you\n"
	.string "for some more of your sage advice!\p"
	.string "Which kind of POKéMON would be right\n"
	.string "for me, one {STR_VAR_1} or {STR_VAR_2}?\p"
	.string "Don’t be shy now.\n"
	.string "Let’s blurt it out!$"

gText_082BF268:: @ 82BF268
	.string "Uh-huh, one {STR_VAR_1} it is!\n"
	.string "OK, A-OK!\l"
	.string "I’ll get one in a BALL, like, cram!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082BF2D1:: @ 82BF2D1
	.string "{PLAYER}{STRING 5}, listen! Big news!\n"
	.string "I caught a mirage POKéMON!\p"
	.string "Of course I’m lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at catching\l"
	.string "POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "kind of POKéMON I should catch,\l"
	.string "master?\p"
	.string "Which would be better?\n"
	.string "{STR_VAR_1} or {STR_VAR_2}?$"

gText_082BF3CF:: @ 82BF3CF
	.string "Okay, so it’s {STR_VAR_1} you chose?\n"
	.string "I’ll grab the other kind, then!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082BF46A:: @ 82BF46A
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin’ SAILOR am I!\n"
	.string "Surely you remember who am I?\p"
	.string "Today, I have a POKéMON question\n"
	.string "that begs your suggestion!\p"
	.string "I have the choice between this\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, you see.\l"
	.string "Which is the one to catch for me?$"

gText_082BF551:: @ 82BF551
	.string "{STR_VAR_1}, you say, hey, hey!\n"
	.string "I’ll go get me one right away!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082BF5C3:: @ 82BF5C3
	.string "Oh, wow, if it isn’t {PLAYER}!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I’m already talking to you!\p"
	.string "It’s been a long time. Let me break\n"
	.string "the ice. I’m also looking for advice!\l"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\p"
	.string "My POKéMON--which should I use?\n"
	.string "It’s either {STR_VAR_1} or {STR_VAR_2}.\l"
	.string "Which do you choose?$"

gText_082BF6E5:: @ 82BF6E5
	.string "If that {STR_VAR_1} is the best,\n"
	.string "I’ll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082BF773:: @ 82BF773
	.string "Oh, hi, {PLAYER}{STRING 5}…\n"
	.string "I have this horrible headache…\p"
	.string "I must’ve worried too much about\n"
	.string "the kind of POKéMON I should raise.\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, if I had to choose between\n"
	.string "the POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}, which should it be?$"

gText_082BF869:: @ 82BF869
	.string "Hm, one {STR_VAR_1}, all right.\n"
	.string "I’ll go look for one when I get better.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082BF8DD:: @ 82BF8DD
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don’t look at me that way.\n"
	.string "I’m getting all flustered…\l"
	.string "I… I need your advice.\p"
	.string "I… I’m really embarrassed, but I can’t\n"
	.string "decide which POKéMON to use.\p"
	.string "If the choices were {STR_VAR_1} or\n"
	.string "{STR_VAR_2}, which would be better?$"

gText_082BF9BA:: @ 82BF9BA
	.string "Oh… Okay!\n"
	.string "I’ll do my best with one {STR_VAR_1}.\p"
	.string "I hope I can do my best without\n"
	.string "getting all flustered.\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082BFA5A:: @ 82BFA5A
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "No, no, if you are real, it’s fine.\n"
	.string "Incidentally, I would like to obtain\l"
	.string "your advice.\p"
	.string "It’s about the POKéMON I am to use.\p"
	.string "If the choices are the POKéMON\n"
	.string "{STR_VAR_1} and {STR_VAR_2}, which is\l"
	.string "more worthy of me?$"

gText_082BFB4E:: @ 82BFB4E
	.string "{STR_VAR_1}?\n"
	.string "Are you certain?\p"
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope it is something even I can\n"
	.string "handle with aplomb.\p"
	.string "Let us meet again!$"

gText_082BFBF2:: @ 82BFBF2
	.string "Waaah! Oh, {PLAYER}!\n"
	.string "Snivel… Hiccup…\p"
	.string "I have a dilemma!\n"
	.string "I can’t decide on a move for\l"
	.string "my {STR_VAR_1}…\p"
	.string "Please, please, {PLAYER}.\n"
	.string "Can you decide for me?\p"
	.string "For my {STR_VAR_1}, which move would\n"
	.string "be the better choice: {STR_VAR_2}\l"
	.string "or {STR_VAR_3}?$"

gText_082BFCAE:: @ 82BFCAE
	.string "{STR_VAR_1}?\n"
	.string "Waaaaah!\p"
	.string "Oh! I’m so sorry, {PLAYER}!\n"
	.string "You’ve made me so happy by deciding\l"
	.string "the move, I’m crying…\p"
	.string "Snivel…\n"
	.string "Thank you so much!$"

gText_082BFD26:: @ 82BFD26
	.string "Yay! Hi, {PLAYER}!\n"
	.string "I need your advice again!\p"
	.string "I want to teach my {STR_VAR_1}\n"
	.string "a cool move.\p"
	.string "I like either of the moves\n"
	.string "{STR_VAR_2} or {STR_VAR_3}.\l"
	.string "What’s your recommendation?$"

gText_082BFDB1:: @ 82BFDB1
	.string "{STR_VAR_1} is better? I guess so!\n"
	.string "Okay, I’ll go with that!\p"
	.string "If we meet here again, please teach\n"
	.string "me something else, teacher!$"

gText_082BFE24:: @ 82BFE24
	.string "{PLAYER}, hello!\n"
	.string "It’s about my {STR_VAR_1}, but I’m\l"
	.string "worried about its moves.\p"
	.string "You see, it’s the moves {STR_VAR_2}\n"
	.string "and {STR_VAR_3}.\p"
	.string "Which is stronger and better for\n"
	.string "my {STR_VAR_1}?$"

gText_082BFEAD:: @ 82BFEAD
	.string "{STR_VAR_1} is your choice?\n"
	.string "Okay, I got it!\p"
	.string "I’ll go teach {STR_VAR_1} to\n"
	.string "my POKéMON right away!\p"
	.string "See you again!$"

gText_082BFF0A:: @ 82BFF0A
	.string "Ohhh, {PLAYER}…\n"
	.string "I’m hopeless, no, really!\p"
	.string "I’ve decided to raise a POKéMON,\n"
	.string "but now I can’t even decide what\l"
	.string "move I should let it learn…\p"
	.string "I know that it doesn’t mean anything\n"
	.string "to you, {PLAYER}.\p"
	.string "But it means a lot to me…\p"
	.string "Please, {PLAYER}, could you choose\n"
	.string "a move for my {STR_VAR_1}?\p"
	.string "If you could even choose between\n"
	.string "{STR_VAR_2} and {STR_VAR_3}…$"

gText_082C0032:: @ 82C0032
	.string "I understand!\p"
	.string "But will it even be willing to learn\n"
	.string "{STR_VAR_1} for me…\l"
	.string "No! I’ll do my best!\p"
	.string "Thank you!$"

gText_082C0090:: @ 82C0090
	.string "Oh, {PLAYER}{STRING 5}!\n"
	.string "I was just hoping to see you, too!\p"
	.string "I was wondering what move would\n"
	.string "be suitable for my {STR_VAR_1}.\p"
	.string "I can’t decide, so can you decide\n"
	.string "for me instead?\p"
	.string "For instance… How about the moves\n"
	.string "{STR_VAR_2} and {STR_VAR_3}?\l"
	.string "Which one would be better?$"

gText_082C016E:: @ 82C016E
	.string "{STR_VAR_1}? That’s great!\p"
	.string "Knowing that you made the decision,\n"
	.string "{PLAYER}{STRING 5}, I won’t be so upset if\l"
	.string "I lose.\p"
	.string "Okay, I’ll look to you for advice again.\n"
	.string "Bye!$"

gText_082C01F7:: @ 82C01F7
	.string "How could things be this busy?\n"
	.string "Hey, if it isn’t {PLAYER}{STRING 5}!\l"
	.string "How’s it going?\p"
	.string "Since I got up this morning, I’ve done\n"
	.string "my jogging, swimming, and cooking!\p"
	.string "You wouldn’t believe how busy I am!\p"
	.string "I can’t even decide what move\n"
	.string "my {STR_VAR_1} should learn!\p"
	.string "{STR_VAR_2} looks good, huh?\n"
	.string "But {STR_VAR_3}’s also decent.\p"
	.string "{PLAYER}{STRING 5}, give me some of your good\n"
	.string "advice! Which move’d be good for me?$"

gText_082C034C:: @ 82C034C
	.string "Okay, gotcha.\n"
	.string "I’ll make room in my schedule and\l"
	.string "teach that move.\p"
	.string "I’m glad I met a good mentor in you.\n"
	.string "Thanks! See you around!$"

gText_082C03CA:: @ 82C03CA
	.string "Oh! Lucky!\n"
	.string "I met you again, {PLAYER}!\l"
	.string "I need to tap your mind again today.\p"
	.string "Drum roll, please!\n"
	.string "The question I have is…\p"
	.string "For my {STR_VAR_1}, which is the move\n"
	.string "best suited, {STR_VAR_2} or\l"
	.string "{STR_VAR_3}?$"

gText_082C046E:: @ 82C046E
	.string "Ahhh!\n"
	.string "{STR_VAR_1}, you say!\l"
	.string "Thanks for a most cool answer!\p"
	.string "I guess that’s about all I wanted\n"
	.string "to ask you today.\p"
	.string "Let’s meet here again, okay?\n"
	.string "Thanks!$"

gText_082C04F9:: @ 82C04F9
	.string "Oh, hello, {PLAYER}.\n"
	.string "I trust you’ve been well?\p"
	.string "I have to seek your advice again.\n"
	.string "It’s about my dearest {STR_VAR_1}.\p"
	.string "What would be the ideal move for\n"
	.string "my lovable {STR_VAR_1}?\l"
	.string "{STR_VAR_2} or {STR_VAR_3}?$"

gText_082C0598:: @ 82C0598
	.string "{STR_VAR_1} it is!\n"
	.string "I will teach that right away!\p"
	.string "Thank you, {PLAYER}.\n"
	.string "I hope I can count on you again.\l"
	.string "Please take care!$"

gText_082C0602:: @ 82C0602
	.string "Eek! {PLAYER}! I met you again!\n"
	.string "I… I’m overjoyed!\p"
	.string "Whenever I’m in need, you’re always\n"
	.string "there for me, {PLAYER}!\p"
	.string "Today, I want you to recommend\n"
	.string "a move for me!\p"
	.string "Please choose a move for\n"
	.string "my {STR_VAR_1}!\p"
	.string "Which move would be better,\n"
	.string "{STR_VAR_2} or {STR_VAR_3}?$"

gText_082C06D8:: @ 82C06D8
	.string "Oh-oh-oh! Thank you!\n"
	.string "{STR_VAR_1} is it!\l"
	.string "Perfectly understood!\p"
	.string "I hope you’ll be willing to teach me\n"
	.string "some more another time.$"

gText_082C074A:: @ 82C074A
	.string "Hola, {PLAYER}{STRING 5}, bueno!\n"
	.string "I’m hoping for some more of\l"
	.string "your sage advice today!\p"
	.string "What would be the best move for\n"
	.string "my {STR_VAR_1}?\p"
	.string "It should be something that’ll\n"
	.string "let me win just like that!\p"
	.string "Would it be {STR_VAR_2}?\n"
	.string "Or {STR_VAR_3}?$"

gText_082C0809:: @ 82C0809
	.string "Uh-huh, {STR_VAR_1} it is!\n"
	.string "Si, bueno!\l"
	.string "I’ll get it taught, like, ka-blam!\p"
	.string "All right, thanks, as always!\n"
	.string "Adios!$"

gText_082C086E:: @ 82C086E
	.string "{PLAYER}{STRING 5}, it’s completely wild!\p"
	.string "My POKéMON!\n"
	.string "It learned six moves!\p"
	.string "Of course I’m lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at choosing moves\l"
	.string "for my POKéMON.\p"
	.string "So, how about deciding for me which\n"
	.string "kind of move I should teach?\p"
	.string "{STR_VAR_2} or {STR_VAR_3}--which\n"
	.string "would go with my {STR_VAR_1} best?$"

gText_082C0982:: @ 82C0982
	.string "Okay, so it’s {STR_VAR_1} you chose?\n"
	.string "I’ll choose another move, then!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks, master!\n"
	.string "I hope you’ll keep teaching me!$"

gText_082C0A1D:: @ 82C0A1D
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin’ SAILOR am I!\n"
	.string "I’m always with it, don’t ask me why.\p"
	.string "Today, I have a move question\n"
	.string "that begs your suggestion!\p"
	.string "{STR_VAR_2} and {STR_VAR_3} are\n"
	.string "the moves. What would be the best\l"
	.string "for my {STR_VAR_1} so it grooves?$"

gText_082C0AFD:: @ 82C0AFD
	.string "{STR_VAR_1}, you say, hey, hey!\n"
	.string "I’ll go teach that right away!\p"
	.string "If it’s advice I ever need,\n"
	.string "{PLAYER}, your word I’ll always heed!$"

gText_082C0B6F:: @ 82C0B6F
	.string "Oh, yeahah, if it isn’t {PLAYER}!\p"
	.string "What should I do? Get your advice?\n"
	.string "Why not? I’m already talking to you!\p"
	.string "{PLAYER}, are you surprised by me?\n"
	.string "I want your advice, can’t you see?\p"
	.string "Are you receiving me?\n"
	.string "You are receiving me!\p"
	.string "My {STR_VAR_1}--what should it use?\n"
	.string "It’s {STR_VAR_2} or {STR_VAR_3},\l"
	.string "what do you choose?$"

gText_082C0C7D:: @ 82C0C7D
	.string "If that {STR_VAR_1} is the best,\n"
	.string "I’ll do as you suggest!\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me.\p"
	.string "See you again, my smart friend!$"

gText_082C0D0B:: @ 82C0D0B
	.string "Gahack! Gaah! Oh, {PLAYER}{STRING 5}…\n"
	.string "I have this lousy cold, I do…\p"
	.string "I want to pick a move for my POKéMON,\n"
	.string "but I’m not up to it…\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me.\p"
	.string "{PLAYER}{STRING 5}, if I had to choose between\n"
	.string "{STR_VAR_2} and {STR_VAR_3} for\l"
	.string "my {STR_VAR_1}, which would it be?$"

gText_082C0DFE:: @ 82C0DFE
	.string "Hm, {STR_VAR_1}, all right. Cough!\n"
	.string "I’ll go teach it when I get better.\p"
	.string "I hope I can keep hitting you up\n"
	.string "for help like this.$"

gText_082C0E71:: @ 82C0E71
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…?\p"
	.string "Please, don’t look at me that way.\n"
	.string "I’m getting all flustered…\l"
	.string "I… I need your advice.\p"
	.string "I… I’m really embarrassed, but I can’t\n"
	.string "decide what move I should teach\l"
	.string "my POKéMON.\p"
	.string "It’s for my {STR_VAR_1}.\n"
	.string "If the choices were {STR_VAR_2} or\l"
	.string "{STR_VAR_3}, which would be better?$"

gText_082C0F6D:: @ 82C0F6D
	.string "Oh… Okay!\n"
	.string "I’ll try that {STR_VAR_1}.\p"
	.string "I hope I can teach that move…\n"
	.string "This is so nerve-racking…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "If we meet again, I hope you will be\l"
	.string "as helpful.$"

gText_082C1003:: @ 82C1003
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really real?\p"
	.string "Perhaps you’re one of those popular\n"
	.string "mimics?\p"
	.string "No, no, if you are real, it’s fine.\n"
	.string "No need to be upset, I assure you!\p"
	.string "Incidentally, I would like to obtain\n"
	.string "your advice.\p"
	.string "It’s about my {STR_VAR_1}.\p"
	.string "Which move would be better for it to\n"
	.string "use, {STR_VAR_2} or {STR_VAR_3}?$"

gText_082C1122:: @ 82C1122
	.string "{STR_VAR_1}?\n"
	.string "There’s no question about that?\p"
	.string "I see. If that’s the case, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope it is something even\n"
	.string "my POKéMON can learn.\p"
	.string "Let us meet again!$"

gText_082C11D1:: @ 82C11D1
	.string "Oh… {PLAYER}?\n"
	.string "It is {PLAYER}!\l"
	.string "Oh! Sniff…sob… Please, listen!\p"
	.string "I… When I battle, I get so nervous,\n"
	.string "I can’t help crying even if I win…\p"
	.string "I wish I could say something cool\n"
	.string "when I win…\p"
	.string "Please, please, {PLAYER}!\n"
	.string "Could you maybe teach me something\l"
	.string "cool to say when I win so I don’t cry?$"

gText_082C12D5:: @ 82C12D5
	.string "{STR_VAR_1}\p"
	.string "Awesome! Wicked! Awoooh!\n"
	.string "It’s really cool!\p"
	.string "Oh… I’m sorry…\n"
	.string "I’m so happy, I’m crying…\p"
	.string "Snivel… {PLAYER}!\n"
	.string "Thank you so much for everything!\p"
	.string "I will battle the best I can for\n"
	.string "your sake, {PLAYER}!\p"
	.string "{PLAYER}…\n"
	.string "Next time… We should battle!$"

gText_082C13AB:: @ 82C13AB
	.string "Yay! It’s {PLAYER}! Hello!\n"
	.string "I wanted to ask you something!\p"
	.string "I want to say something cool when\n"
	.string "I win a match.\p"
	.string "Do you have a cool saying that\n"
	.string "you could recommend?$"

gText_082C1444:: @ 82C1444
	.string "{STR_VAR_1}\p"
	.string "Oh, wow! That is so cool!\n"
	.string "Okay, I’ll say that!\p"
	.string "Thanks for teaching me all this time!\n"
	.string "I’m going to do the best I can\l"
	.string "wherever I go from now on!\p"
	.string "When we meet again, it’ll be for\n"
	.string "a battle!$"

gText_082C1501:: @ 82C1501
	.string "{PLAYER}, hello!\p"
	.string "My POKéMON and I are ready for\n"
	.string "anything, except for one thing.\p"
	.string "I think it would be good if I had\n"
	.string "something to shout when I win.\p"
	.string "Could you think up something good\n"
	.string "to say?$"

gText_082C15B6:: @ 82C15B6
	.string "{STR_VAR_1}\p"
	.string "…Cool!\n"
	.string "I will use that!\p"
	.string "I’m going out to battle all over\n"
	.string "the place.\p"
	.string "Who knows, I may even get to battle\n"
	.string "you one day, {PLAYER}.\p"
	.string "Next time, let’s meet at a place\n"
	.string "of battle!$"

gText_082C165E:: @ 82C165E
	.string "Hello, {PLAYER}…\n"
	.string "I’m sorry to bug you, but I’m hopeless…\p"
	.string "Even when…\n"
	.string "Even when I win, I don’t have anything\l"
	.string "special to say…\p"
	.string "I know that it doesn’t mean anything\n"
	.string "to you, {PLAYER}.\p"
	.string "But it means a lot to me…\p"
	.string "Please, {PLAYER}, what should I say\n"
	.string "if I win a battle?$"

gText_082C174F:: @ 82C174F
	.string "{STR_VAR_1}\p"
	.string "That’s inspired…\p"
	.string "Uh… Is it okay for someone like me\n"
	.string "to even say that?\p"
	.string "No! I’ll do my best!\p"
	.string "{PLAYER}, thank you so much for\n"
	.string "putting up with me for so long…\p"
	.string "I promise to do my best from now on.\p"
	.string "I’m sure you’ll quickly forget about\n"
	.string "someone like me, but let’s meet\l"
	.string "somewhere again!$"

gText_082C1862:: @ 82C1862
	.string "Oh, {PLAYER}{STRING 5}.\n"
	.string "There’s something I want you to hear.\p"
	.string "I know that I don’t always sound\n"
	.string "nice or polite…\p"
	.string "When I win a battle, I think I come\n"
	.string "across as being arrogant.\p"
	.string "I don’t want people to dislike me,\n"
	.string "so I want to say something nice to\l"
	.string "someone I beat.\p"
	.string "But I can’t think of anything good!\n"
	.string "Could you think something up for me?$"

gText_082C19A0:: @ 82C19A0
	.string "{STR_VAR_1}\p"
	.string "Not bad!\n"
	.string "Yup, that’s what I’ll go with!\p"
	.string "I’m going to hit the road and do what\n"
	.string "I can with what you taught me in\l"
	.string "my head and heart.\p"
	.string "I’m sorry that I’ve been so pushy\n"
	.string "with you!\p"
	.string "Next time, we battle, okay?\n"
	.string "See you!$"

gText_082C1A76:: @ 82C1A76
	.string "Oh, I can’t get over how busy I am!\n"
	.string "Oh, hey, I was looking for you, {PLAYER}{STRING 5}.\p"
	.string "Are you well as usual?\n"
	.string "Things haven’t changed for me at all.\p"
	.string "I’ve got running, fighting, and mapping\n"
	.string "to do. Why am I so busy?\p"
	.string "But even though I’m busy, it’d be rude\n"
	.string "to just turn on my heels and walk away\l"
	.string "from a win without saying a word.\p"
	.string "So, what would be a cool saying to\n"
	.string "underline my coolness when I’m done\l"
	.string "and walking away? {PLAYER}{STRING 5}, help me!$"

gText_082C1C16:: @ 82C1C16
	.string "{STR_VAR_1}\p"
	.string "Okay, gotcha.\n"
	.string "I can find time to say that!\p"
	.string "Honestly, I’m glad I met a good mentor\n"
	.string "like you.\p"
	.string "I’m going to make time somehow so\n"
	.string "I can get into battling.\p"
	.string "Thanks for everything, {PLAYER}{STRING 5}!\n"
	.string "We have to battle, you and me, one day!$"

gText_082C1CF5:: @ 82C1CF5
	.string "I lucked out again!\n"
	.string "{PLAYER}! Am I glad to see you!\l"
	.string "Like usual, I need your advice!\p"
	.string "Drum roll, please!\n"
	.string "The last question I have is…\p"
	.string "If I win a battle and want to end\n"
	.string "it with a cool flourish, what\l"
	.string "should I say?$"

gText_082C1DC1:: @ 82C1DC1
	.string "{STR_VAR_1}\p"
	.string "That… That’s fabulous!\n"
	.string "It’s dignified and cool! I claim it!\p"
	.string "…Listen, I think I’m getting decent\n"
	.string "at this, huh?\p"
	.string "So, I’m thinking of challenging other\n"
	.string "TRAINERS from now on.\p"
	.string "{PLAYER}, your advice really helped me.\p"
	.string "Maybe one day, there’ll be a time when\n"
	.string "we battle!\p"
	.string "Thank you for everything!$"

gText_082C1EDC:: @ 82C1EDC
	.string "Oh, {PLAYER}.\n"
	.string "I’m so glad I met you!\p"
	.string "I no longer have any concerns with\n"
	.string "regard to my POKéMON.\p"
	.string "It’s myself that worries me…\p"
	.string "Do you know how a TRAINER says\n"
	.string "a few things upon winning a battle?\p"
	.string "Definitely, I wish I could do that,\n"
	.string "too!\p"
	.string "Please, what should I say when\n"
	.string "I win a battle?$"

gText_082C1FEC:: @ 82C1FEC
	.string "{STR_VAR_1}\p"
	.string "Ah! That saying! It refreshes me\n"
	.string "and makes me feel reborn!\p"
	.string "I must use that right away!\p"
	.string "And now, I must take my leave,\n"
	.string "{PLAYER}…\p"
	.string "I will go out to battle many others,\n"
	.string "but never will I forget your teachings.\p"
	.string "Perhaps one day…\n"
	.string "Farewell!$"

gText_082C20D1:: @ 82C20D1
	.string "Eek! I spotted {PLAYER}!\n"
	.string "I… I’m overjoyed to see you!\p"
	.string "Oh-oh-oh! There’s something I just\n"
	.string "had to ask you!\p"
	.string "A little while ago, I won a battle.\n"
	.string "That part was giddying!\p"
	.string "But it made me so overjoyed that\n"
	.string "I choked up and couldn’t say a thing!\p"
	.string "So now, {PLAYER}, please, I want you to\n"
	.string "think up an exit line for when I win!$"

gText_082C21FF:: @ 82C21FF
	.string "{STR_VAR_1}\p"
	.string "Waaaaah!\n"
	.string "I’m going to say that?!\l"
	.string "I… I’m delirious with joy!\p"
	.string "Th-th-thank you!\n"
	.string "I have nothing left to regret now!\p"
	.string "I’m going to travel now and battle\n"
	.string "all sorts of people.\p"
	.string "Everything, I owe it to you, {PLAYER}.\n"
	.string "Really, really, thank you!\p"
	.string "I’ve got to go now, but let’s meet\n"
	.string "in battle one day!$"

gText_082C231C:: @ 82C231C
	.string "Hola, bueno!\n"
	.string "{PLAYER}{STRING 5}!\p"
	.string "You know, I’m getting the itch to roam\n"
	.string "and battle where I may.\p"
	.string "But before I do, I want your advice\n"
	.string "once again, please!\p"
	.string "If I were to win a battle, what would\n"
	.string "be a good boast I could say to my\l"
	.string "fallen TRAINER opponent?$"

gText_082C2407:: @ 82C2407
	.string "{STR_VAR_1}\p"
	.string "Uh-huh, that’s sweet!\n"
	.string "Si, bueno!\l"
	.string "I’ll try saying that, like, ham!\p"
	.string "And now, it’s time to say good-bye!\n"
	.string "Thanks for all sorts of things!\p"
	.string "Give me a battle one day, OK?\n"
	.string "Adios!$"

gText_082C24B5:: @ 82C24B5
	.string "{PLAYER}{STRING 5}, there’s big trouble!\p"
	.string "When I win a battle, I brag about it\n"
	.string "for an hour at least!\p"
	.string "Of course I’m lying!\n"
	.string "Wahahaha!\p"
	.string "This is no lie, though.\n"
	.string "I’m not very good at chatting.\p"
	.string "So, how about deciding for me what\n"
	.string "I should say after winning a battle,\l"
	.string "master?$"

gText_082C25B1:: @ 82C25B1
	.string "{STR_VAR_1}\p"
	.string "That’s what I should say, huh?\n"
	.string "Then, I’ll stay away from that!\p"
	.string "Just kidding!\n"
	.string "I’ll obey your teaching, master!\p"
	.string "Thanks for teaching me all this time,\n"
	.string "master!\p"
	.string "I’m finally understanding what being\n"
	.string "a TRAINER is about.\p"
	.string "I’m going to go out and win battles\n"
	.string "against any TRAINER.\p"
	.string "Maybe it’ll be you one day, master!\p"
	.string "That’s all!\n"
	.string "Farewell, my master!$"

gText_082C2707:: @ 82C2707
	.string "A-H-O-Y!\n"
	.string "And that spells ahoy!\p"
	.string "The rappin’ SAILOR am I!\n"
	.string "This will be my last question,\l"
	.string "don’t you cry!\p"
	.string "It’s a saying question\n"
	.string "that begs your suggestion!\p"
	.string "If I win a match, what can I say\n"
	.string "in a real cool way?$"

gText_082C27D4:: @ 82C27D4
	.string "{STR_VAR_1}\p"
	.string "Perfect! That’s what I’ll use.\n"
	.string "I was right to make you choose!\p"
	.string "And now, I think it’d be best,\n"
	.string "if I were to fly the nest!\p"
	.string "Thanks for all you taught me.\n"
	.string "I’ll be off on a battle spree!\p"
	.string "B-O-N-V-O-Y-A-G-E!\n"
	.string "And that spells bon voyage,\l"
	.string "to you this is my homage!$"

gText_082C28D6:: @ 82C28D6
	.string "Oh, yeah, {PLAYER}!\n"
	.string "I found you again today!\p"
	.string "What should I do? Ask you again?\n"
	.string "Why not? I’m already asking you!\p"
	.string "Anyways, {PLAYER}…\n"
	.string "Are you receiving me?\l"
	.string "You are receiving me!\l"
	.string "I need some more advice for me!\p"
	.string "It’s about what I should yell.\n"
	.string "Something cool to holler when\l"
	.string "a battle ends well.\p"
	.string "Come on, I wanna hear you say it!$"

gText_082C2A0B:: @ 82C2A0B
	.string "{STR_VAR_1}\p"
	.string "All right, all right!\n"
	.string "I’ll use that because it’s so tight!\p"
	.string "I’m out of things to ask you.\n"
	.string "Waving bye is all that’s left to do.\p"
	.string "But maybe one day we’ll meet, with one\n"
	.string "destined to go down in defeat.\p"
	.string "But, it really is time to say farewell.\p"
	.string "Well, {PLAYER}, I have to roam free,\n"
	.string "but don’t you forget about me!\p"
	.string "Take care, {PLAYER}!\n"
	.string "Love ya!$"

gText_082C2B50:: @ 82C2B50
	.string "{PLAYER}{STRING 5}, I’m finished…\n"
	.string "My nose won’t stop dripping…\p"
	.string "I was trying to think up something\n"
	.string "cool to say when I win a battle.\p"
	.string "It inspired me so much, it made me cry,\n"
	.string "and now my nose won’t stop running…\p"
	.string "So, things being this way,\n"
	.string "I need you to decide for me, {PLAYER}{STRING 5}.\p"
	.string "When I win a battle,\n"
	.string "what should I say?$"

gText_082C2C77:: @ 82C2C77
	.string "{STR_VAR_1}\p"
	.string "… … …That’s good.\n"
	.string "No, it’s awe inspiring!\l"
	.string "It’s bringing fresh tears to my eyes!\p"
	.string "But in spite of my tears and runny\n"
	.string "nose, I will use that saying!\p"
	.string "I’m plumb out of things to ask you,\n"
	.string "{PLAYER}{STRING 5}.\p"
	.string "From now on, we’re rivals!\n"
	.string "Thanks for everything!$"

gText_082C2D67:: @ 82C2D67
	.string "Er… Um…\n"
	.string "{PLAYER}{STRING 5}…\p"
	.string "Please, don’t look at me that way.\n"
	.string "You’re making me all nervous.\p"
	.string "I… I need your advice again.\n"
	.string "I’ll make it my last, though…\p"
	.string "It’s really embarrassing to ask,\n"
	.string "but what if I win a battle?\l"
	.string "What should I say?$"

gText_082C2E41:: @ 82C2E41
	.string "{STR_VAR_1}\p"
	.string "Oh… Okay!\n"
	.string "I’ll try to say that!\l"
	.string "I might be too nervous to say it…\p"
	.string "Thank you, {PLAYER}{STRING 5}.\n"
	.string "I have to say good-bye now.\p"
	.string "I’ll obey all that you’ve taught me,\n"
	.string "{PLAYER}{STRING 5}, and do the best I can.$"

gText_082C2EF5:: @ 82C2EF5
	.string "Hm? You appear to be {PLAYER}{STRING 5}…\n"
	.string "But are you really?\l"
	.string "Perhaps a clever {PLAYER} DOLL?\p"
	.string "Oh, no, no, no, don’t worry!\n"
	.string "If you really are real, please\l"
	.string "forget about my rudeness.\p"
	.string "No need to be so angry. All I wish for\n"
	.string "is more of your fine advice.\p"
	.string "It concerns a saying.\p"
	.string "More precisely, what should I say\n"
	.string "if I win a battle?$"

gText_082C3023:: @ 82C3023
	.string "{STR_VAR_1}\p"
	.string "… … … … … …\n"
	.string "When I win a match…\p"
	.string "{STR_VAR_1}\p"
	.string "…Are you serious?\p"
	.string "I see. If you are serious, that’s fine.\n"
	.string "I thank you for your time.\p"
	.string "I do hope even I will be able to\n"
	.string "put that saying to good use.\p"
	.string "I seem to have run dry on what advice\n"
	.string "I need.\p"
	.string "I do believe it’s high time I bid you\n"
	.string "farewell and strike out on my own.\p"
	.string "Thank you, my mentor!\n"
	.string "I apologize for my skepticism!$"

gBattleDomeOpponentPotential1::
	.string "The best candidate to be a champ!$"

gBattleDomeOpponentPotential2::
	.string "A sure-finalist team.$"

gBattleDomeOpponentPotential3::
	.string "A likely top-three finisher.$"
	
gBattleDomeOpponentPotential4::
	.string "A candidate to finish first.$"

gBattleDomeOpponentPotential5::
	.string "A team with top-class potential.$"

gBattleDomeOpponentPotential6::
	.string "The dark horse team this tournament.$"

gBattleDomeOpponentPotential7::
	.string "A better-than-average team.$"

gBattleDomeOpponentPotential8::
	.string "This tournament’s average team.$"

gBattleDomeOpponentPotential9::
	.string "A team with average potential.$"

gBattleDomeOpponentPotential10::
	.string "A weaker-than-average team.$"

gBattleDomeOpponentPotential11::
	.string "A team looking for its first win.$"

gBattleDomeOpponentPotential12::
	.string "One win will make this team proud.$"

gBattleDomeOpponentPotential13::
	.string "Overall, a weak team.$"

gBattleDomeOpponentPotential14::
	.string "A team with very low potential.$"

gBattleDomeOpponentPotential15::
	.string "A team unlikely to win the tournament.$"

gBattleDomeOpponentPotential16::
	.string "The team most unlikely to win.$"

gBattleDomeOpponentPotential17::
	.string "The perfect, invincible superstar!$"

gBattleDomeOpponentStyle1::	
	.string "Willing to risk total disaster at times.$"

gBattleDomeOpponentStyle2::
	.string "Skilled at enduring long battles.$"

gBattleDomeOpponentStyle3::
	.string "Varies tactics to suit the opponent.$"

gBattleDomeOpponentStyle4::
	.string "Has a tough winning pattern.$"

gBattleDomeOpponentStyle5::
	.string "Occasionally uses a very rare move.$"

gBattleDomeOpponentStyle6::
	.string "Uses startling and disruptive moves.$"

gBattleDomeOpponentStyle7::
	.string "Constantly watches HP in battle.$"

gBattleDomeOpponentStyle8::
	.string "Good at storing then loosing power.$"

gBattleDomeOpponentStyle9::
	.string "Skilled at enfeebling foes.$"

gBattleDomeOpponentStyle10::
	.string "Prefers tactics that rely on luck.$"

gBattleDomeOpponentStyle11::
	.string "Attacks with a regal atmosphere.$"

gBattleDomeOpponentStyle12::
	.string "Attacks with powerful, low-PP moves.$"

gBattleDomeOpponentStyle13::
	.string "Skilled at enfeebling, then attacking.$"

gBattleDomeOpponentStyle14::
	.string "Battles while enduring all attacks.$"

gBattleDomeOpponentStyle15::
	.string "Skilled at upsetting foes emotionally.$"

gBattleDomeOpponentStyle16::
	.string "Uses strong and straightforward moves.$"

gBattleDomeOpponentStyle17::
	.string "Aggressively uses strong moves.$"

gBattleDomeOpponentStyle18::
	.string "Battles while cleverly dodging attacks.$"

gBattleDomeOpponentStyle19::
	.string "Skilled at using upsetting attacks.$"

gBattleDomeOpponentStyle20::
	.string "Uses many popular moves.$"

gBattleDomeOpponentStyle21::
	.string "Has moves for powerful combinations.$"

gBattleDomeOpponentStyle22::
	.string "Uses high-probability attacks.$"

gBattleDomeOpponentStyle23::
	.string "Aggressively uses spectacular moves.$"

gBattleDomeOpponentStyle24::
	.string "Emphasizes offense over defense.$"

gBattleDomeOpponentStyle25::
	.string "Emphasizes defense over offense.$"

gBattleDomeOpponentStyle26::
	.string "Attacks quickly with strong moves.$"

gBattleDomeOpponentStyle27::
	.string "Often uses moves with added effects.$"

gBattleDomeOpponentStyle28::
	.string "Uses a well-balanced mix of moves.$"

gBattleDomeOpponentStyleUnused1::
	.string "This is sample message 1.$"

gBattleDomeOpponentStyleUnused2::
	.string "This is sample message 2.$"

gBattleDomeOpponentStyleUnused3::
	.string "This is sample message 3.$"

gBattleDomeOpponentStyleUnused4::
	.string "This is sample message 4.$"

gBattleDomeOpponentStats1::
	.string "Emphasizes HP and ATTACK.$"

gBattleDomeOpponentStats2::
	.string "Emphasizes HP and DEFENSE.$"

gBattleDomeOpponentStats3::
	.string "Emphasizes HP and SPEED.$"

gBattleDomeOpponentStats4::
	.string "Emphasizes HP and SP. ATTACK.$"

gBattleDomeOpponentStats5::
	.string "Emphasizes HP and SP. DEFENSE.$"

gBattleDomeOpponentStats6::
	.string "Emphasizes ATTACK and DEFENSE.$"

gBattleDomeOpponentStats7::
	.string "Emphasizes ATTACK and SPEED.$"

gBattleDomeOpponentStats8::
	.string "Emphasizes ATTACK and SP. ATTACK.$"

gBattleDomeOpponentStats9::
	.string "Emphasizes ATTACK and SP. DEFENSE.$"

gBattleDomeOpponentStats10::
	.string "Emphasizes DEFENSE and SPEED.$"

gBattleDomeOpponentStats11::
	.string "Emphasizes DEFENSE and SP. ATTACK.$"

gBattleDomeOpponentStats12::
	.string "Emphasizes DEFENSE and SP. DEFENSE.$"

gBattleDomeOpponentStats13::
	.string "Emphasizes SPEED and SP. ATTACK.$"

gBattleDomeOpponentStats14::
	.string "Emphasizes SPEED and SP. DEFENSE.$"

gBattleDomeOpponentStats15::
	.string "Emphasizes SP. ATTACK and SP. DEFENSE.$"

gBattleDomeOpponentStats16::
	.string "Emphasizes HP.$"

gBattleDomeOpponentStats17::
	.string "Emphasizes ATTACK.$"

gBattleDomeOpponentStats18::
	.string "Emphasizes DEFENSE.$"

gBattleDomeOpponentStats19::
	.string "Emphasizes SPEED.$"

gBattleDomeOpponentStats20::
	.string "Emphasizes SP. ATTACK.$"

gBattleDomeOpponentStats21::
	.string "Emphasizes SP. DEFENSE.$"

gBattleDomeOpponentStats22::
	.string "Neglects HP and ATTACK.$"

gBattleDomeOpponentStats23::
	.string "Neglects HP and DEFENSE.$"

gBattleDomeOpponentStats24::
	.string "Neglects HP and SPEED.$"

gBattleDomeOpponentStats25::
	.string "Neglects HP and SP. ATTACK.$"

gBattleDomeOpponentStats26::
	.string "Neglects HP and SP. DEFENSE.$"

gBattleDomeOpponentStats27::
	.string "Neglects ATTACK and DEFENSE.$"

gBattleDomeOpponentStats28::
	.string "Neglects ATTACK and SPEED.$"

gBattleDomeOpponentStats29::
	.string "Neglects ATTACK and SP. ATTACK.$"

gBattleDomeOpponentStats30::
	.string "Neglects ATTACK and SP. DEFENSE.$"

gBattleDomeOpponentStats31::
	.string "Neglects DEFENSE and SPEED.$"

gBattleDomeOpponentStats32::
	.string "Neglects DEFENSE and SP. ATTACK.$"

gBattleDomeOpponentStats33::
	.string "Neglects DEFENSE and SP. DEFENSE.$"

gBattleDomeOpponentStats34::
	.string "Neglects SPEED and SP. ATTACK.$"

gBattleDomeOpponentStats35::
	.string "Neglects SPEED and SP. DEFENSE.$"

gBattleDomeOpponentStats36::
	.string "Neglects SP. ATTACK and SP. DEFENSE.$"

gBattleDomeOpponentStats37::
	.string "Neglects HP.$"

gBattleDomeOpponentStats38::
	.string "Neglects ATTACK.$"

gBattleDomeOpponentStats39::
	.string "Neglects DEFENSE.$"

gBattleDomeOpponentStats40::
	.string "Neglects SPEED.$"

gBattleDomeOpponentStats41::
	.string "Neglects SP. ATTACK.$"

gBattleDomeOpponentStats42::
	.string "Neglects SP. DEFENSE.$"

gBattleDomeOpponentStats43::
	.string "Raises POKéMON in a well-balanced way.$"

gBattleDomeWinStrings1::
	.string "Let the battle begin!$"

gBattleDomeWinStrings2::
	.string "{STR_VAR_1} won using {STR_VAR_2}!$"

gBattleDomeWinStrings3::
	.string "{STR_VAR_1} became the champ!$"

gBattleDomeWinStrings4::
	.string "{STR_VAR_1} won by default!$"

gBattleDomeWinStrings5::
	.string "{STR_VAR_1} won outright by default!$"

gBattleDomeWinStrings6::
	.string "{STR_VAR_1} won without using a move!$"

gBattleDomeWinStrings7::
	.string "{STR_VAR_1} won outright with no moves!$"

gBattleDomeMatchNumber1::
	.string "Round 1, Match 1$"

gBattleDomeMatchNumber2::
	.string "Round 1, Match 2$"

gBattleDomeMatchNumber3::
	.string "Round 1, Match 3$"

gBattleDomeMatchNumber4::
	.string "Round 1, Match 4$"

gBattleDomeMatchNumber5::
	.string "Round 1, Match 5$"

gBattleDomeMatchNumber6::
	.string "Round 1, Match 6$"

gBattleDomeMatchNumber7::
	.string "Round 1, Match 7$"

gBattleDomeMatchNumber8::
	.string "Round 1, Match 8$"

gBattleDomeMatchNumber9::
	.string "Round 2, Match 1$"

gBattleDomeMatchNumber10::
	.string "Round 2, Match 2$"

gBattleDomeMatchNumber11::
	.string "Round 2, Match 3$"

gBattleDomeMatchNumber12::
	.string "Round 2, Match 4$"

gBattleDomeMatchNumber13::
	.string "Semifinal Match 1$"

gBattleDomeMatchNumber14::
	.string "Semifinal Match 2$"

gBattleDomeMatchNumber15::
	.string "Final Match$"

BattleFrontier_BattlePikeRandomRoom1_MapScripts_2C3E1B: @ 82C3E1B
	map_script 3, BattleFrontier_BattlePikeRandomRoom1_MapScript1_2C3E25
	map_script 4, BattleFrontier_BattlePikeRandomRoom1_MapScript2_2C3EDE

BattleFrontier_BattlePikeRandomRoom1_MapScript1_2C3E25: @ 82C3E25
	setvar VAR_0x8004, 4
	special sub_81A703C
	setvar VAR_0x8004, 5
	special sub_81A703C
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EB1
	case 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EB1
	case 2, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EC0
	case 3, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EA2
	case 4, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EB1
	case 7, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3E93
	case 6, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EA2
	case 8, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3ECF
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3E93:: @ 82C3E93
	setobjectxyperm 1, 2, 5
	setobjectxyperm 2, 6, 5
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EA2:: @ 82C3EA2
	setobjectxyperm 1, 4, 4
	setobjectxyperm 2, 3, 4
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EB1:: @ 82C3EB1
	setobjectxyperm 1, 4, 4
	setobjectxyperm 2, 0, 0
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EC0:: @ 82C3EC0
	setobjectxyperm 1, 5, 5
	setobjectxyperm 2, 0, 0
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3ECF:: @ 82C3ECF
	setobjectxyperm 1, 4, 3
	setobjectxyperm 2, 4, 4
	end

BattleFrontier_BattlePikeRandomRoom1_MapScript2_2C3EDE: @ 82C3EDE
	map_script_2 VAR_0x4004, 0, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EE8
	.2byte 0

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3EE8:: @ 82C3EE8
	setvar VAR_0x4011, 28
	setvar VAR_0x4010, 28
	setvar VAR_0x8004, 5
	special sub_81A703C
	compare VAR_RESULT, 3
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare VAR_RESULT, 6
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare VAR_RESULT, 7
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare VAR_RESULT, 8
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F3F
	hideobjectat 2, BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM_1
	setvar VAR_0x4004, 1
	turnobject 255, 2
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35:: @ 82C3F35
	setvar VAR_0x4004, 1
	turnobject 255, 2
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F3F:: @ 82C3F3F
	setvar VAR_0x4004, 1
	turnobject 255, 2
	hideobjectat 1, BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM_1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F4E:: @ 82C3F4E
	setvar VAR_0x8007, 0
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F6F
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F59:: @ 82C3F59
	setvar VAR_0x8007, 1
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F6F
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F64:: @ 82C3F64
	setvar VAR_0x8007, 2
	goto BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F6F
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C3F6F:: @ 82C3F6F
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_81A703C
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A703C
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	setvar VAR_0x8004, 0
	special sub_81A703C
	setvar VAR_0x8004, 5
	special sub_81A703C
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 1, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 2, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 3, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 4, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 5, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4049
	case 6, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 7, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	case 8, BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4030:: @ 82C4030
	applymovement 255, BattleFrontier_BattlePikeThreePathRoom_Movement_2C427A
	waitmovement 0
	call BattleFrontier_BattlePikeThreePathRoom_EventScript_25BB49
	warpsilent BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM_1, 255, 4, 7
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4049:: @ 82C4049
	applymovement 255, BattleFrontier_BattlePikeThreePathRoom_Movement_2C427A
	waitmovement 0
	call BattleFrontier_BattlePikeThreePathRoom_EventScript_25BB49
	warpsilent BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM_3, 255, 4, 19
	waitstate
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4062:: @ 82C4062
	setvar VAR_0x4003, 1
	setvar VAR_0x4002, 1
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C406D:: @ 82C406D
	setvar VAR_0x4003, 0
	setvar VAR_0x4002, 0
	lockall
	msgbox BattleFrontier_BattlePikeThreePathRoom_Text_25CE36, 4
	closemessage
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4082:: @ 82C4082
	setvar VAR_0x4003, 1
	setvar VAR_0x4002, 1
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C408D:: @ 82C408D
	setvar VAR_0x4003, 0
	setvar VAR_0x4002, 0
	lockall
	msgbox BattleFrontier_BattlePikeRandomRoom1_Text_25CE36, 4
	closemessage
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C40A2:: @ 82C40A2
	setvar VAR_0x8004, 25
	special sub_81A703C
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4128
	compare VAR_RESULT, 1
	call_if 5, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4136
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_81A703C
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A703C
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	setvar VAR_0x8004, 3
	special sub_81A703C
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4144
	compare VAR_RESULT, 0
	call_if 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C415C
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4128:: @ 82C4128
BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4128:: @ 82C4128
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 1
	special sub_81A703C
	return

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4136:: @ 82C4136
BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4136:: @ 82C4136
	setvar VAR_0x8004, 24
	setvar VAR_0x8005, 0
	special sub_81A703C
	return

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4144:: @ 82C4144
BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4144:: @ 82C4144
	applymovement 255, BattleFrontier_BattlePikeRandomRoom1_Movement_2C427A
	waitmovement 0
	call BattleFrontier_BattlePikeRandomRoom1_EventScript_25BB49
	warpsilent BATTLE_FRONTIER_BATTLE_PIKE_RANDOM_ROOM_2, 255, 2, 7
	return

BattleFrontier_BattlePikeRandomRoom1_EventScript_2C415C:: @ 82C415C
BattleFrontier_BattlePikeRandomRoom3_EventScript_2C415C:: @ 82C415C
	applymovement 255, BattleFrontier_BattlePikeRandomRoom1_Movement_2C427A
	waitmovement 0
	call BattleFrontier_BattlePikeRandomRoom1_EventScript_25BB49
	warpsilent BATTLE_FRONTIER_BATTLE_PIKE_THREE_PATH_ROOM, 255, 6, 10
	return

BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4174:: @ 82C4174
	setvar VAR_0x8004, 7
	special sub_81A703C
	setvar VAR_0x8004, 25
	special sub_81A703C
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4128
	compare VAR_RESULT, 1
	call_if 5, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4136
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	special sub_81A703C
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 1
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A703C
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	special sub_81A1780
	addvar VAR_RESULT, 1
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	copyvar VAR_0x8006, VAR_RESULT
	special sub_81A1780
	setvar VAR_0x8004, 3
	special sub_81A703C
	compare VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4144
	compare VAR_RESULT, 0
	call_if 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C415C
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4202:: @ 82C4202
	setvar VAR_0x4003, 1
	setvar VAR_0x4002, 1
	end

BattleFrontier_BattlePikeRandomRoom3_EventScript_2C420D:: @ 82C420D
	setvar VAR_0x4003, 0
	setvar VAR_0x4002, 0
	lockall
	msgbox BattleFrontier_BattlePikeRandomRoom3_Text_25CE36, 4
	closemessage
	end

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4222:: @ 82C4222
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 4
	special sub_81A1780
	warp BATTLE_FRONTIER_BATTLE_PIKE_LOBBY, 255, 5, 6
	waitstate
	end

BattleFrontier_BattlePikeRandomRoom1_MapScript1_2C423E: @ 82C423E
BattleFrontier_BattlePikeThreePathRoom_MapScript1_2C423E: @ 82C423E
	setorcopyvar VAR_0x8006, VAR_RESULT
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 0
	special sub_81A1780
	compare VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B
	compare VAR_RESULT, 1
	goto_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B
	call BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4271

BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B:: @ 82C426B
	setorcopyvar VAR_RESULT, VAR_0x8006
	end

BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4271:: @ 82C4271
BattleFrontier_BattlePikeThreePathRoom_EventScript_2C4271:: @ 82C4271
	setvar VAR_0x8004, 21
	special sub_81A1780
	return

BattleFrontier_BattlePikeRandomRoom1_Movement_2C427A: @ 82C427A
BattleFrontier_BattlePikeThreePathRoom_Movement_2C427A: @ 82C427A
	step_54
	step_end

LilycoveCity_ContestLobby_Text_2C427C: @ 82C427C
	.string "BLEND MASTER: Indeed I am!\n"
	.string "The BLEND MASTER am I!\p"
	.string "Blend with me, and you shall witness\n"
	.string "the mastery I bring to blending!$"

LilycoveCity_ContestLobby_Text_2C42F4: @ 82C42F4
	.string "BLEND MASTER: Hmmm! So, you wish to\n"
	.string "see my mastery in action?$"

LilycoveCity_ContestLobby_Text_2C4332: @ 82C4332
	.string "Hmmm!\p"
	.string "So, you are too busy now, I see!\p"
	.string "But fear not!\n"
	.string "I shall be here all day!\l"
	.string "Hurry back from your errand!$"

LilycoveCity_ContestLobby_Text_2C439D: @ 82C439D
	.string "Hmmm!\p"
	.string "You haven’t got a single BERRY!\p"
	.string "I shall be here all day!\n"
	.string "Hurry back with some BERRIES!$"

LilycoveCity_ContestLobby_Text_2C43FA: @ 82C43FA
	.string "Of course!\n"
	.string "Of course!\p"
	.string "Incidentally…\n"
	.string "You do know how to blend {POKEBLOCK}S\l"
	.string "from BERRIES?$"

LilycoveCity_ContestLobby_Text_2C444C: @ 82C444C
	.string "Hmmm!\p"
	.string "Ah, but it is a simple process!\p"
	.string "When the BLENDER’s arrow comes to\n"
	.string "your marker, just press the A Button.\p"
	.string "That’s all you have to do.\p"
	.string "When you see how precisely I press\n"
	.string "the A Button, you will understand.$"

LilycoveCity_ContestLobby_Text_2C451B: @ 82C451B
	.string "Fine!\p"
	.string "Let’s get started, then!\p"
	.string "All together with the BLEND MASTER,\n"
	.string "let’s BERRY BLENDER!$"

LilycoveCity_ContestLobby_Text_2C4573: @ 82C4573
	.string "Hmmm!\p"
	.string "You don’t appear to have gotten\n"
	.string "the {POKEBLOCK} CASE!\p"
	.string "I shall be here all day!\n"
	.string "Obtain the {POKEBLOCK} CASE and hurry back!$"

LilycoveCity_ContestLobby_Text_2C45E8: @ 82C45E8
	.string "Hmmm!\p"
	.string "Your {POKEBLOCK} CASE appears to be full!\p"
	.string "I shall be here all day!\n"
	.string "Use some {POKEBLOCK}S and hurry back!$"

LilycoveCity_ContestLobby_Text_2C464B: @ 82C464B
	.string "Whoa!\n"
	.string "Awesome!$"

LilycoveCity_ContestLobby_Text_2C465A: @ 82C465A
	.string "Wickedly fast!$"

LilycoveCity_ContestLobby_Text_2C4669: @ 82C4669
	.string "What an expert!$"

LilycoveCity_ContestLobby_Text_2C4679: @ 82C4679
	.string "When I blended with the MASTER,\n"
	.string "we made amazing {POKEBLOCK}S!$"

LilycoveCity_ContestLobby_Text_2C46B1: @ 82C46B1
	.string "Eyes that track the arrow with\n"
	.string "machinelike intensity…\p"
	.string "A hand that taps the A Button\n"
	.string "with clockwork-like precision…\p"
	.string "Possessing these qualities makes\n"
	.string "the BLEND MASTER truly great.$"

LilycoveCity_ContestLobby_Text_2C4763: @ 82C4763
	.string "The BLEND MASTER’s supposed to work\n"
	.string "on his skills deep in the mountains.\p"
	.string "Sometimes, he comes to LILYCOVE\n"
	.string "to blend BERRIES all day long.$"

FallarborTown_BattleTentLobby_Text_2C47EB: @ 82C47EB
	.string "I welcome you to the BATTLE TENT\n"
	.string "FALLARBOR SITE!\p"
	.string "I am your guide to the Set KO Tourney!$"

FallarborTown_BattleTentLobby_Text_2C4843: @ 82C4843
	.string "Now, do you wish to take the challenge\n"
	.string "of a Set KO Tourney?$"

FallarborTown_BattleTentLobby_Text_2C487F: @ 82C487F
	.string "We await your challenge on\n"
	.string "another occasion!$"

FallarborTown_BattleTentLobby_Text_2C48AC: @ 82C48AC
	.string "In the FALLARBOR BATTLE TENT,\n"
	.string "we undertake the Set KO Tourney.\p"
	.string "All participants enter with a team of\n"
	.string "three POKéMON.\p"
	.string "The three POKéMON must be lined up\n"
	.string "in the order that they are to appear in.\p"
	.string "During battle, the POKéMON will appear\n"
	.string "one at a time in the preset order.\p"
	.string "Once a POKéMON enters battle, it must\n"
	.string "remain out until the match is decided.\p"
	.string "If a match remains undecided in\n"
	.string "three turns, it goes to judging.\p"
	.string "If you wish to interrupt your challenge,\n"
	.string "please save the game.\p"
	.string "If you don’t save, you will not be able\n"
	.string "to continue with your challenge.\p"
	.string "If you pull off the feat of beating\n"
	.string "three TRAINERS in succession,\l"
	.string "we will present you with a fine prize.$"

FallarborTown_BattleTentLobby_Text_2C4B35: @ 82C4B35
	.string "Before showing you to the BATTLE\n"
	.string "TENT, I must save. Is that okay?$"

FallarborTown_BattleTentLobby_Text_2C4B77: @ 82C4B77
	.string "We offer two levels of challenge,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which is your choice?$"

FallarborTown_BattleTentLobby_Text_2C4BC8: @ 82C4BC8
	.string "Very well, now select your\n"
	.string "three POKéMON, please.$"

FallarborTown_BattleTentLobby_Text_2C4BFA: @ 82C4BFA
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

FallarborTown_BattleTentLobby_Text_2C4CC0: @ 82C4CC0
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

FallarborTown_BattleTentLobby_Text_2C4DC3: @ 82C4DC3
	.string "I shall now guide you to\n"
	.string "the BATTLE TENT.$"

FallarborTown_BattleTentLobby_Text_2C4DED: @ 82C4DED
	.string "My dear challenger!\p"
	.string "You did not save the game before\n"
	.string "shutting down, did you?\p"
	.string "It is unfortunate, but that has\n"
	.string "resulted in your disqualification\l"
	.string "from your challenge.\p"
	.string "You may, of course, start with a fresh\n"
	.string "challenge.$"

FallarborTown_BattleTentLobby_Text_2C4EC3: @ 82C4EC3
	.string "How splendid! You have beaten\n"
	.string "three TRAINERS in succession!$"

FallarborTown_BattleTentLobby_Text_2C4EFF: @ 82C4EFF
	.string "Please wait while I save the game.$"

FallarborTown_BattleTentLobby_Text_2C4F22: @ 82C4F22
	.string "In commemoration of your 3-win streak,\n"
	.string "we present you with this prize.$"

FallarborTown_BattleTentLobby_Text_2C4F69: @ 82C4F69
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

FallarborTown_BattleTentLobby_Text_2C4F83: @ 82C4F83
	.string "Oh?\n"
	.string "Your BAG seems to be full.\p"
	.string "I urge you to clear space and\n"
	.string "return for your prize.$"

FallarborTown_BattleTentLobby_Text_2C4FD7: @ 82C4FD7
	.string "Thank you so much for participating!\p"
	.string "Please wait while I save the game.$"

FallarborTown_BattleTentLobby_Text_2C501F: @ 82C501F
	.string "We await your challenge on\n"
	.string "another occasion!$"

FallarborTown_BattleTentLobby_Text_2C504C: @ 82C504C
	.string "We have been looking forward to\n"
	.string "your arrival.\p"
	.string "Before I show you to the BATTLE TENT,\n"
	.string "I must save the game. Please wait.$"

VerdanturfTown_BattleTentLobby_Text_2C50C3: @ 82C50C3
	.string "I welcome you to the BATTLE TENT\n"
	.string "VERDANTURF SITE!\p"
	.string "Here, the TRAINER’s trust toward\n"
	.string "POKéMON is tested.$"

VerdanturfTown_BattleTentLobby_Text_2C5129: @ 82C5129
	.string "Do you wish to take the VERDANTURF\n"
	.string "BATTLE TENT challenge?$"

VerdanturfTown_BattleTentLobby_Text_2C5163: @ 82C5163
	.string "In the VERDANTURF BATTLE TENT,\n"
	.string "there is one crucial rule that must\l"
	.string "be obeyed.\p"
	.string "TRAINERS are permitted only to switch\n"
	.string "their POKéMON in and out.\p"
	.string "TRAINERS are otherwise forbidden to\n"
	.string "command their POKéMON.\p"
	.string "The POKéMON are to behave according\n"
	.string "to their nature and battle on their own.\p"
	.string "You must put your trust in your\n"
	.string "POKéMON and watch over them.\p"
	.string "If you achieve the honor of beating\n"
	.string "three TRAINERS in succession,\l"
	.string "we will present you with a prize.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don’t save before interrupting,\n"
	.string "you will be disqualified.$"

VerdanturfTown_BattleTentLobby_Text_2C539A: @ 82C539A
	.string "When you have fortified your heart\n"
	.string "and POKéMON, you must return.$"

VerdanturfTown_BattleTentLobby_Text_2C53DB: @ 82C53DB
	.string "There are two levels of difficulty,\n"
	.string "Level 50 and Open Level.\l"
	.string "Which is your choice of a challenge?$"

VerdanturfTown_BattleTentLobby_Text_2C543D: @ 82C543D
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"

VerdanturfTown_BattleTentLobby_Text_2C5538: @ 82C5538
	.string "Sigh…\p"
	.string "You do not have the three POKéMON\n"
	.string "required for the challenge.\p"
	.string "To enter, you must provide three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not be holding\n"
	.string "the same kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Come back when you have made\n"
	.string "your preparations.$"

VerdanturfTown_BattleTentLobby_Text_2C5633: @ 82C5633
	.string "Good. Now, you must select your\n"
	.string "three POKéMON.$"

VerdanturfTown_BattleTentLobby_Text_2C5662: @ 82C5662
	.string "I must save before I show you to\n"
	.string "the BATTLE TENT. Is that okay?$"

VerdanturfTown_BattleTentLobby_Text_2C56A2: @ 82C56A2
	.string "Good.\n"
	.string "Now, follow me.$"

VerdanturfTown_BattleTentLobby_Text_2C56B8: @ 82C56B8
	.string "I feel privileged for having seen\n"
	.string "your POKéMON’s exploits.\p"
	.string "The results will be recorded.\n"
	.string "I must ask you to briefly wait.$"

VerdanturfTown_BattleTentLobby_Text_2C5731: @ 82C5731
	.string "To achieve a 3-win streak…\p"
	.string "The bonds that bind your heart with\n"
	.string "your POKéMON seem firm and true.$"

VerdanturfTown_BattleTentLobby_Text_2C5791: @ 82C5791
	.string "Your feat will be recorded.\n"
	.string "I must ask you to briefly wait.$"

VerdanturfTown_BattleTentLobby_Text_2C57CD: @ 82C57CD
	.string "For the feat of your 3-win streak,\n"
	.string "we present you with this prize.$"

SlateportCity_BattleTentLobby_Text_2C5810: @ 82C5810
	.string "Welcome to the BATTLE TENT\n"
	.string "SLATEPORT SITE!\p"
	.string "I am your guide to the Battle Swap\n"
	.string "Tournament.$"

SlateportCity_BattleTentLobby_Text_2C586A: @ 82C586A
	.string "Would you like to take the Battle\n"
	.string "Swap challenge?$"

SlateportCity_BattleTentLobby_Text_2C589C: @ 82C589C
	.string "Here at the SLATEPORT BATTLE TENT,\n"
	.string "we hold Battle Swap events\l"
	.string "using rental POKéMON.\p"
	.string "First, you will be loaned three\n"
	.string "POKéMON specifically for this event.\p"
	.string "Using the supplied rental POKéMON,\n"
	.string "you must conduct a SINGLE BATTLE.\p"
	.string "If you win, you are permitted to trade\n"
	.string "one of your rental POKéMON.\p"
	.string "Repeat this cycle of battling and\n"
	.string "trading--if you win three times in\l"
	.string "a row, you will earn a fine prize.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don’t save before interrupting,\n"
	.string "you will be disqualified.$"

SlateportCity_BattleTentLobby_Text_2C5AA5: @ 82C5AA5
	.string "We look forward to your next visit.$"

SlateportCity_BattleTentLobby_Text_2C5AC9: @ 82C5AC9
	.string "Which level do you wish to challenge?\n"
	.string "Level 50 or Level 100?$"

SlateportCity_BattleTentLobby_Text_2C5B06: @ 82C5B06
	.string "Before you begin your challenge,\n"
	.string "I need to save data. Is that okay?$"

SlateportCity_BattleTentLobby_Text_2C5B4A: @ 82C5B4A
	.string "Okay, I will hold your POKéMON for\n"
	.string "safekeeping while you compete.$"

SlateportCity_BattleTentLobby_Text_2C5B8C: @ 82C5B8C
	.string "Please step this way.$"

SlateportCity_BattleTentLobby_Text_2C5BA2: @ 82C5BA2
	.string "Thank you for participating!\p"
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.\p"
	.string "I must also save your event results.\n"
	.string "Please wait.$"

SlateportCity_BattleTentLobby_Text_2C5C30: @ 82C5C30
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.$"

SlateportCity_BattleTentLobby_Text_2C5C6F: @ 82C5C6F
	.string "Congratulations!\n"
	.string "You’ve won three straight matches!\p"
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.\p"
	.string "I must also save your event results.\n"
	.string "Please wait.$"

SlateportCity_BattleTentLobby_Text_2C5D14: @ 82C5D14
	.string "In recognition of your 3-win streak,\n"
	.string "we award you this prize.$"

SlateportCity_BattleTentLobby_Text_2C5D52: @ 82C5D52
	.string "Oh?\n"
	.string "You seem to have no room for this.\p"
	.string "Please make room in your BAG and\n"
	.string "let me know.$"

SlateportCity_BattleTentLobby_Text_2C5DA7: @ 82C5DA7
	.string "We’ve been waiting for you!\p"
	.string "Before we resume your challenge,\n"
	.string "I must save the game.$"

SlateportCity_BattleTentLobby_Text_2C5DFA: @ 82C5DFA
	.string "I’m sorry to say this, but you didn’t\n"
	.string "save before you quit playing last time.\p"
	.string "As a result, you have been disqualified\n"
	.string "from your challenge.$"

SlateportCity_BattleTentLobby_Text_2C5E85: @ 82C5E85
	.string "We’ll return your personal POKéMON.$"

SlateportCity_BattleTentLobby_Text_2C5EA9: @ 82C5EA9
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

SlateportCity_BattleTentLobby_Text_2C5EC3: @ 82C5EC3
	.string "The Battle Swap rules are listed.$"

SlateportCity_BattleTentLobby_Text_2C5EE5: @ 82C5EE5
	.string "Which heading do you want to read?$"

SlateportCity_BattleTentLobby_Text_2C5F08: @ 82C5F08
	.string "In a Battle Swap event, you may use\n"
	.string "only three POKéMON.\p"
	.string "Whether you are renting or swapping,\n"
	.string "your team may not have two or more\l"
	.string "of the same POKéMON.$"

SlateportCity_BattleTentLobby_Text_2C5F9D: @ 82C5F9D
	.string "You may swap POKéMON only with\n"
	.string "the TRAINER you have just defeated.\p"
	.string "You may swap for only those POKéMON\n"
	.string "used by the beaten TRAINER.$"

SlateportCity_BattleTentLobby_Text_2C6020: @ 82C6020
	.string "After every battle you win, you may\n"
	.string "swap for one of your defeated\l"
	.string "opponent’s POKéMON.\p"
	.string "You will not be able to swap POKéMON\n"
	.string "with the third TRAINER in the event.$"

SlateportCity_BattleTentLobby_Text_2C60C0: @ 82C60C0
	.string "There are two key points to be aware\n"
	.string "of when swapping POKéMON.\p"
	.string "First, when swapping, you can’t check\n"
	.string "the stats of the POKéMON you are\l"
	.string "about to receive.\p"
	.string "Second, the POKéMON on your team\n"
	.string "are lined up in sequence, depending on\l"
	.string "the order in which you rented them.\p"
	.string "This sequence remains unchanged\n"
	.string "even when swaps are made.$"

SlateportCity_BattleTentLobby_Text_2C61FE: @ 82C61FE
	.string "The POKéMON of the SLATEPORT\n"
	.string "BATTLE TENT are all rentals.\p"
	.string "All rental POKéMON are kept at\n"
	.string "Level 30.$"

VerdanturfTown_BattleTentLobby_Text_2C6261: @ 82C6261
	.string "The VERDANTURF BATTLE TENT\n"
	.string "rules are listed.$"

VerdanturfTown_BattleTentLobby_Text_2C628E: @ 82C628E
	.string "Which heading do you want to read?$"

VerdanturfTown_BattleTentLobby_Text_2C62B1: @ 82C62B1
	.string "Here at the VERDANTURF BATTLE TENT,\n"
	.string "POKéMON are required to think and\l"
	.string "battle by themselves.\p"
	.string "Unlike in the wild, POKéMON that live\n"
	.string "with people behave differently\l"
	.string "depending on their nature.$"

VerdanturfTown_BattleTentLobby_Text_2C636D: @ 82C636D
	.string "Depending on its nature, a POKéMON\n"
	.string "may prefer to attack no matter what.\p"
	.string "Another POKéMON may prefer to protect\n"
	.string "itself from any harm.\p"
	.string "Yet another may enjoy vexing or\n"
	.string "confounding its foes.\p"
	.string "Depending on its nature, a POKéMON\n"
	.string "will have favorite moves that it is good\l"
	.string "at using.\p"
	.string "It may also dislike certain moves that\n"
	.string "it has trouble using.$"

VerdanturfTown_BattleTentLobby_Text_2C64BA: @ 82C64BA
	.string "There are offensive moves that inflict\n"
	.string "direct damage on the foe.\p"
	.string "There are defensive moves that are\n"
	.string "used to prepare for enemy attacks or\l"
	.string "used to heal HP and so on.\p"
	.string "There are also other somewhat-odd\n"
	.string "moves that may enfeeble the foes with\l"
	.string "stat problems including poison and \l"
	.string "paralysis.\p"
	.string "POKéMON will consider using moves in\n"
	.string "these three categories.$"

VerdanturfTown_BattleTentLobby_Text_2C6612: @ 82C6612
	.string "When not under command by its TRAINER,\n"
	.string "a POKéMON may be unable to effectively\l"
	.string "use certain moves.\p"
	.string "A POKéMON is not good at using any\n"
	.string "move that it dislikes.\p"
	.string "If a POKéMON only knows moves that\n"
	.string "do not match its nature, it will often\l"
	.string "be unable to live up to its potential.$"

VerdanturfTown_BattleTentLobby_Text_2C671E: @ 82C671E
	.string "Depending on its nature, a POKéMON may\n"
	.string "start using moves that don’t match its\l"
	.string "nature when it is in trouble.\p"
	.string "If a POKéMON begins behaving oddly\n"
	.string "in a pinch, watch it carefully.$"

FallarborTown_BattleTentLobby_Text_2C67CD: @ 82C67CD
VerdanturfTown_BattleTentLobby_Text_2C67CD: @ 82C67CD
	.string "At this BATTLE TENT, the levels of\n"
	.string "your opponents will be adjusted to\l"
	.string "match the levels of your POKéMON.\p"
	.string "However, no TRAINER you face will\n"
	.string "have any POKéMON below Level 30.$"

VerdanturfTown_BattleTentLobby_Text_2C6878: @ 82C6878
	.string "The VERDANTURF BATTLE TENT\n"
	.string "rules are listed.$"

LilycoveCity_Harbor_Text_2C68A5: @ 82C68A5
	.string "What’s up, youngster?\p"
	.string "What, it’s you who’s supposed to have\n"
	.string "a tattered old map?\p"
	.string "Let’s have a look.\n"
	.string "… … … … … …\p"
	.string "Boy, this is quite a ways away.\n"
	.string "I’m afraid I can’t help you…$"

LilycoveCity_Harbor_Text_2C6951: @ 82C6951
	.string "BRINEY: Hold on a second!\p"
	.string "What’s the idea of turning down\n"
	.string "someone that I owe so much to?$"

LilycoveCity_Harbor_Text_2C69AA: @ 82C69AA
	.string "{PLAYER}{KUN}, I’m terribly sorry.\p"
	.string "You came to me seeking my help,\n"
	.string "and we almost turned you away.\p"
	.string "Well, let me make things right.\p"
	.string "We’ll sail right away, of course!\p"
	.string "Let’s find this island on\n"
	.string "this OLD SEA MAP!$"

LilycoveCity_Harbor_Text_2C6A71: @ 82C6A71
	.string "Is it you who brought that odd\n"
	.string "ticket?\p"
	.string "Where you’re trying to go is an island\n"
	.string "that’s far, far away.\p"
	.string "No one knows what awaits there…\p"
	.string "The very thought excites my blood\n"
	.string "as a sailing man!\p"
	.string "Get on board, youngster!$"

FarawayIsland_Entrance_Text_2C6B42: @ 82C6B42
	.string "CAPT. BRINEY can be so maddeningly\n"
	.string "fickle…\p"
	.string "Do you want to return to LILYCOVE?$"

BirthIsland_Harbor_Text_2C6B90: @ 82C6B90
	.string "What an oddly shaped island, eh?\n"
	.string "Do you want to return to LILYCOVE?$"

LilycoveCity_Harbor_Text_2C6BD4: @ 82C6BD4
	.string "Is it you who brought those\n"
	.string "odd tickets?\p"
	.string "… … …Hm.\p"
	.string "These tickets will get you to islands\n"
	.string "that are far, far away.\p"
	.string "No one knows what awaits there,\n"
	.string "or what may happen there.\p"
	.string "The very thought excites my blood\n"
	.string "as a sailing man!\p"
	.string "Get on board, youngster!\n"
	.string "Where shall we sail first?$"

NavelRock_Harbor_Text_2C6CE6: @ 82C6CE6
	.string "Did… Did you hear that?\n"
	.string "That low growling from deep in there.\p"
	.string "Are you sure it’s safe?\n"
	.string "Do you think we should leave?$"

FarawayIsland_Entrance_Text_2C6D5A: @ 82C6D5A
	.string "The writing is fading as if it was\n"
	.string "written a long time ago…\p"
	.string "“…ber, 6th day\n"
	.string "If any human…sets foot here…\l"
	.string "again…et it be a kindhearted pers…\l"
	.string "…ith that hope, I depar…”$"

FarawayIsland_Interior_Text_2C6DFF: @ 82C6DFF
	.string "Myuu…$"

MauvilleCity_Text_2C6E05: @ 82C6E05
	.string "This move can be learned only\n"
	.string "once. Is that okay?$"

SlateportCity_PokemonFanClub_Text_2C6E37: @ 82C6E37
	.string "Heh! My POKéMON totally rules!\n"
	.string "It’s cooler than any POKéMON!\p"
	.string "I was lipping off with a swagger in\n"
	.string "my step like that when the CHAIRMAN\l"
	.string "chewed me out.\p"
	.string "That took the swagger out of my step.\p"
	.string "If you’d like, I’ll teach the move\n"
	.string "SWAGGER to a POKéMON of yours.$"

SlateportCity_PokemonFanClub_Text_2C6F33: @ 82C6F33
	.string "What, no? Can’t you get into\n"
	.string "the spirit of things?$"

SlateportCity_PokemonFanClub_Text_2C6F66: @ 82C6F66
	.string "All right, which POKéMON wants to\n"
	.string "learn how to SWAGGER?$"

SlateportCity_PokemonFanClub_Text_2C6F9E: @ 82C6F9E
	.string "I’ll just praise my POKéMON from now\n"
	.string "on without the swagger.$"

MauvilleCity_Text_2C6FDB: @ 82C6FDB
	.string "Did you know that you can go from\n"
	.string "here a long way in that direction\l"
	.string "without changing direction?\p"
	.string "I might even be able to roll\n"
	.string "that way.\p"
	.string "Do you think your POKéMON will\n"
	.string "want to roll, too?\p"
	.string "I can teach one the move ROLLOUT\n"
	.string "if you’d like.$"

MauvilleCity_Text_2C70C4: @ 82C70C4
	.string "You don’t need to be shy about it.\n"
	.string "Let’s roll!$"

MauvilleCity_Text_2C70F3: @ 82C70F3
	.string "Ehehe, sure thing! It’d be great if\n"
	.string "the POKéMON looked like me.$"

MauvilleCity_Text_2C7133: @ 82C7133
	.string "Rolling around in the grass makes me\n"
	.string "happy. Come on, let’s roll!$"

VerdanturfTown_PokemonCenter_1F_Text_2C7174: @ 82C7174
	.string "There’s a move that gets stronger\n"
	.string "when you keep using it in a row.\p"
	.string "It’s a BUG-type move, and it is\n"
	.string "wickedly cool.\p"
	.string "It’s called FURY CUTTER.\n"
	.string "Want me to teach it to a POKéMON?$"

VerdanturfTown_PokemonCenter_1F_Text_2C7221: @ 82C7221
	.string "We’re not on the same wavelength.$"

VerdanturfTown_PokemonCenter_1F_Text_2C7243: @ 82C7243
	.string "Yay!\n"
	.string "Show me which POKéMON I should teach.$"

VerdanturfTown_PokemonCenter_1F_Text_2C726E: @ 82C726E
	.string "I get a thrill watching to see if\n"
	.string "the move keeps hitting in succession!$"

LavaridgeTown_House_Text_2C72B6: @ 82C72B6
	.string "Ah, young one!\p"
	.string "I am also a young one, but I mimic\n"
	.string "the styles and speech of the elderly\l"
	.string "folks of this town.\p"
	.string "What do you say, young one?\n"
	.string "Would you agree to it if I were to\l"
	.string "offer to teach the move MIMIC?$"

LavaridgeTown_House_Text_2C737F: @ 82C737F
	.string "Oh, boo! I wanted to teach MIMIC\n"
	.string "to your POKéMON!$"

LavaridgeTown_House_Text_2C73B1: @ 82C73B1
	.string "Fwofwo! And so I shall!\n"
	.string "Let me see the POKéMON\l"
	.string "you wish me to teach.$"

LavaridgeTown_House_Text_2C73F6: @ 82C73F6
	.string "MIMIC is a move of great depth.\p"
	.string "Could you execute it to perfection\n"
	.string "as well as me…?$"

FallarborTown_Mart_Text_2C7449: @ 82C7449
	.string "I want all sorts of things!\n"
	.string "But I used up my allowance…\p"
	.string "Wouldn’t it be nice if there were\n"
	.string "a spell that made money appear when\l"
	.string "you waggle a finger?\p"
	.string "If you want, I can teach your POKéMON\n"
	.string "the move METRONOME.\p"
	.string "Money won’t appear, but your POKéMON\n"
	.string "will waggle a finger. Yes?$"

FallarborTown_Mart_Text_2C7556: @ 82C7556
	.string "Okay. I’ll be here if you change\n"
	.string "your mind.$"

FallarborTown_Mart_Text_2C7582: @ 82C7582
	.string "Okay! I’ll teach it!\n"
	.string "Which POKéMON should I teach?$"

FallarborTown_Mart_Text_2C75B5: @ 82C75B5
	.string "When a POKéMON waggles its finger\n"
	.string "like a METRONOME, all sorts of nice\l"
	.string "things happen.\p"
	.string "Wouldn’t it be nice if we could\n"
	.string "use it, too?$"

FortreeCity_House2_Text_2C7637: @ 82C7637
	.string "Humph! My wife relies on HIDDEN\n"
	.string "POWER to stay awake.\p"
	.string "She should just take a nap like I do,\n"
	.string "and SLEEP TALK.\p"
	.string "I can teach your POKéMON how to\n"
	.string "SLEEP TALK instead. Interested?$"

FortreeCity_House2_Text_2C76E2: @ 82C76E2
	.string "Oh, fine, fine. You want to stay awake\n"
	.string "with HIDDEN POWER, too…$"

FortreeCity_House2_Text_2C7721: @ 82C7721
	.string "Ah, an appreciative child!\n"
	.string "Which POKéMON should I teach?$"

FortreeCity_House2_Text_2C775A: @ 82C775A
	.string "I’ve never once gotten my wife’s\n"
	.string "coin trick right.\p"
	.string "I would be happy if I got it right\n"
	.string "even as I SLEEP TALK…$"

LilycoveCity_DepartmentStoreRooftop_Text_2C77C6: @ 82C77C6
	.string "When I see the wide world from up\n"
	.string "here on the roof…\p"
	.string "I think about how nice it would be\n"
	.string "if there were more than just one me\l"
	.string "so I could enjoy all sorts of lives.\p"
	.string "Of course it’s not possible.\n"
	.string "Giggle…\p"
	.string "I know! Would you be interested in\n"
	.string "having a POKéMON learn SUBSTITUTE?$"

LilycoveCity_DepartmentStoreRooftop_Text_2C78D1: @ 82C78D1
	.string "Oh, no?\p"
	.string "A POKéMON can make a copy of\n"
	.string "itself using it, you know.$"

LilycoveCity_DepartmentStoreRooftop_Text_2C7911: @ 82C7911
	.string "Giggle…\n"
	.string "Which POKéMON do you want me to\l"
	.string "teach SUBSTITUTE?$"

LilycoveCity_DepartmentStoreRooftop_Text_2C794B: @ 82C794B
	.string "We human beings should enjoy our\n"
	.string "own lives to the utmost!\p"
	.string "I hope you’ll get that way, too!$"

MossdeepCity_Text_2C79A6: @ 82C79A6
	.string "I can’t do this anymore!\p"
	.string "It’s utterly hopeless!\p"
	.string "I’m a FIGHTING-type TRAINER,\n"
	.string "so I can’t win at the MOSSDEEP GYM\l"
	.string "no matter how hard I try!\p"
	.string "Argh! Punch! Punch! Punch!\n"
	.string "Punch! Punch! Punch!\p"
	.string "What, don’t look at me that way!\n"
	.string "I’m only hitting the ground!\p"
	.string "Or do you want me to teach your\n"
	.string "POKéMON DYNAMICPUNCH?$"

MossdeepCity_Text_2C7AD4: @ 82C7AD4
	.string "Darn! You’re even making fun of me?\n"
	.string "Punch! Punch! Punch!$"

MossdeepCity_Text_2C7B0D: @ 82C7B0D
	.string "What? You do? You’re a good person!\n"
	.string "Which POKéMON should I teach?$"

MossdeepCity_Text_2C7B4F: @ 82C7B4F
	.string "I want you to win at the MOSSDEEP GYM\n"
	.string "using that DYNAMICPUNCH!$"

SootopolisCity_PokemonCenter_1F_Text_2C7B8E: @ 82C7B8E
	.string "Sigh…\p"
	.string "SOOTOPOLIS’s GYM LEADER is really\n"
	.string "lovably admirable.\p"
	.string "But that also means I have many\n"
	.string "rivals for his attention.\p"
	.string "He’s got appeal with a DOUBLE-EDGE.\n"
	.string "I couldn’t even catch his eye.\p"
	.string "Please, let me teach your POKéMON\n"
	.string "the move DOUBLE-EDGE!$"

SootopolisCity_PokemonCenter_1F_Text_2C7C7E: @ 82C7C7E
	.string "Oh…\n"
	.string "Even you rejected me…$"

SootopolisCity_PokemonCenter_1F_Text_2C7C98: @ 82C7C98
	.string "Okay, which POKéMON should I teach\n"
	.string "DOUBLE-EDGE?$"

SootopolisCity_PokemonCenter_1F_Text_2C7CC8: @ 82C7CC8
	.string "I won’t live for love anymore!\n"
	.string "I’ll become tough!$"

PacifidlogTown_PokemonCenter_1F_Text_2C7CFA: @ 82C7CFA
	.string "I don’t intend to be going nowhere\n"
	.string "fast in the sticks like this forever.\p"
	.string "You watch me, I’ll get out to the city\n"
	.string "and become a huge hit.\p"
	.string "Seriously, I’m going to cause\n"
	.string "a huge EXPLOSION of popularity!\p"
	.string "If you overheard that, I’ll happily\n"
	.string "teach EXPLOSION to your POKéMON!$"

PacifidlogTown_PokemonCenter_1F_Text_2C7E04: @ 82C7E04
	.string "Gaah! You’re turning me down because\n"
	.string "I live in the country?$"

PacifidlogTown_PokemonCenter_1F_Text_2C7E40: @ 82C7E40
	.string "Fine! An EXPLOSION it is!\n"
	.string "Which POKéMON wants to blow up?$"

PacifidlogTown_PokemonCenter_1F_Text_2C7E7A: @ 82C7E7A
	.string "For a long time, I’ve taught POKéMON\n"
	.string "how to use EXPLOSION, but I’ve yet\l"
	.string "to ignite my own EXPLOSION…\p"
	.string "Maybe it’s because deep down,\n"
	.string "I would rather stay here…$"

SlateportCity_PokemonFanClub_EventScript_2C7F16:: @ 82C7F16
	lock
	faceplayer
	checkflag FLAG_0x1B1
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F74
	msgbox SlateportCity_PokemonFanClub_Text_2C6E37, 5
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F6A
	call SlateportCity_PokemonFanClub_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F6A
	msgbox SlateportCity_PokemonFanClub_Text_2C6F66, 4
	setvar VAR_0x8005, 23
	call SlateportCity_PokemonFanClub_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F6A
	setflag FLAG_0x1B1
	goto SlateportCity_PokemonFanClub_EventScript_2C7F74
	end

SlateportCity_PokemonFanClub_EventScript_2C7F6A:: @ 82C7F6A
	msgbox SlateportCity_PokemonFanClub_Text_2C6F33, 4
	release
	end

SlateportCity_PokemonFanClub_EventScript_2C7F74:: @ 82C7F74
	msgbox SlateportCity_PokemonFanClub_Text_2C6F9E, 4
	release
	end

MauvilleCity_EventScript_2C7F7E:: @ 82C7F7E
	lock
	faceplayer
	checkflag FLAG_0x1B2
	goto_eq MauvilleCity_EventScript_2C7FDC
	msgbox MauvilleCity_Text_2C6FDB, 5
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_2C7FD2
	call MauvilleCity_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_2C7FD2
	msgbox MauvilleCity_Text_2C70F3, 4
	setvar VAR_0x8005, 16
	call MauvilleCity_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_2C7FD2
	setflag FLAG_0x1B2
	goto MauvilleCity_EventScript_2C7FDC
	end

MauvilleCity_EventScript_2C7FD2:: @ 82C7FD2
	msgbox MauvilleCity_Text_2C70C4, 4
	release
	end

MauvilleCity_EventScript_2C7FDC:: @ 82C7FDC
	msgbox MauvilleCity_Text_2C7133, 4
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_2C7FE6:: @ 82C7FE6
	lock
	faceplayer
	checkflag FLAG_0x1B3
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C8044
	msgbox VerdanturfTown_PokemonCenter_1F_Text_2C7174, 5
	compare VAR_RESULT, 0
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C803A
	call VerdanturfTown_PokemonCenter_1F_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C803A
	msgbox VerdanturfTown_PokemonCenter_1F_Text_2C7243, 4
	setvar VAR_0x8005, 29
	call VerdanturfTown_PokemonCenter_1F_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C803A
	setflag FLAG_0x1B3
	goto VerdanturfTown_PokemonCenter_1F_EventScript_2C8044
	end

VerdanturfTown_PokemonCenter_1F_EventScript_2C803A:: @ 82C803A
	msgbox VerdanturfTown_PokemonCenter_1F_Text_2C7221, 4
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_2C8044:: @ 82C8044
	msgbox VerdanturfTown_PokemonCenter_1F_Text_2C726E, 4
	release
	end

LavaridgeTown_House_EventScript_2C804E:: @ 82C804E
	lock
	faceplayer
	checkflag FLAG_0x1B4
	goto_eq LavaridgeTown_House_EventScript_2C80AC
	msgbox LavaridgeTown_House_Text_2C72B6, 5
	compare VAR_RESULT, 0
	goto_eq LavaridgeTown_House_EventScript_2C80A2
	call LavaridgeTown_House_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq LavaridgeTown_House_EventScript_2C80A2
	msgbox LavaridgeTown_House_Text_2C73B1, 4
	setvar VAR_0x8005, 7
	call LavaridgeTown_House_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq LavaridgeTown_House_EventScript_2C80A2
	setflag FLAG_0x1B4
	goto LavaridgeTown_House_EventScript_2C80AC
	end

LavaridgeTown_House_EventScript_2C80A2:: @ 82C80A2
	msgbox LavaridgeTown_House_Text_2C737F, 4
	release
	end

LavaridgeTown_House_EventScript_2C80AC:: @ 82C80AC
	msgbox LavaridgeTown_House_Text_2C73F6, 4
	release
	end

FallarborTown_Mart_EventScript_2C80B6:: @ 82C80B6
	lock
	faceplayer
	checkflag FLAG_0x1B5
	goto_eq FallarborTown_Mart_EventScript_2C8114
	msgbox FallarborTown_Mart_Text_2C7449, 5
	compare VAR_RESULT, 0
	goto_eq FallarborTown_Mart_EventScript_2C810A
	call FallarborTown_Mart_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq FallarborTown_Mart_EventScript_2C810A
	msgbox FallarborTown_Mart_Text_2C7582, 4
	setvar VAR_0x8005, 8
	call FallarborTown_Mart_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq FallarborTown_Mart_EventScript_2C810A
	setflag FLAG_0x1B5
	goto FallarborTown_Mart_EventScript_2C8114
	end

FallarborTown_Mart_EventScript_2C810A:: @ 82C810A
	msgbox FallarborTown_Mart_Text_2C7556, 4
	release
	end

FallarborTown_Mart_EventScript_2C8114:: @ 82C8114
	msgbox FallarborTown_Mart_Text_2C75B5, 4
	release
	end

FortreeCity_House2_EventScript_2C811E:: @ 82C811E
	lock
	faceplayer
	checkflag FLAG_0x1B6
	goto_eq FortreeCity_House2_EventScript_2C817C
	msgbox FortreeCity_House2_Text_2C7637, 5
	compare VAR_RESULT, 0
	goto_eq FortreeCity_House2_EventScript_2C8172
	call FortreeCity_House2_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq FortreeCity_House2_EventScript_2C8172
	msgbox FortreeCity_House2_Text_2C7721, 4
	setvar VAR_0x8005, 24
	call FortreeCity_House2_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq FortreeCity_House2_EventScript_2C8172
	setflag FLAG_0x1B6
	goto FortreeCity_House2_EventScript_2C817C
	end

FortreeCity_House2_EventScript_2C8172:: @ 82C8172
	msgbox FortreeCity_House2_Text_2C76E2, 4
	release
	end

FortreeCity_House2_EventScript_2C817C:: @ 82C817C
	msgbox FortreeCity_House2_Text_2C775A, 4
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2C8186:: @ 82C8186
	lock
	faceplayer
	checkflag FLAG_0x1B7
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81E4
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2C77C6, 5
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA
	call LilycoveCity_DepartmentStoreRooftop_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2C7911, 4
	setvar VAR_0x8005, 14
	call LilycoveCity_DepartmentStoreRooftop_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA
	setflag FLAG_0x1B7
	goto LilycoveCity_DepartmentStoreRooftop_EventScript_2C81E4
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA:: @ 82C81DA
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2C78D1, 4
	release
	end

LilycoveCity_DepartmentStoreRooftop_EventScript_2C81E4:: @ 82C81E4
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2C794B, 4
	release
	end

MossdeepCity_EventScript_2C81EE:: @ 82C81EE
	lock
	faceplayer
	checkflag FLAG_0x1B8
	goto_eq MossdeepCity_EventScript_2C824C
	msgbox MossdeepCity_Text_2C79A6, 5
	compare VAR_RESULT, 0
	goto_eq MossdeepCity_EventScript_2C8242
	call MossdeepCity_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq MossdeepCity_EventScript_2C8242
	msgbox MossdeepCity_Text_2C7B0D, 4
	setvar VAR_0x8005, 15
	call MossdeepCity_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq MossdeepCity_EventScript_2C8242
	setflag FLAG_0x1B8
	goto MossdeepCity_EventScript_2C824C
	end

MossdeepCity_EventScript_2C8242:: @ 82C8242
	msgbox MossdeepCity_Text_2C7AD4, 4
	release
	end

MossdeepCity_EventScript_2C824C:: @ 82C824C
	msgbox MossdeepCity_Text_2C7B4F, 4
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_2C8256:: @ 82C8256
	lock
	faceplayer
	checkflag FLAG_0x1B9
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82B4
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7B8E, 5
	compare VAR_RESULT, 0
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	call SootopolisCity_PokemonCenter_1F_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7C98, 4
	setvar VAR_0x8005, 4
	call SootopolisCity_PokemonCenter_1F_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	setflag FLAG_0x1B9
	goto SootopolisCity_PokemonCenter_1F_EventScript_2C82B4
	end

SootopolisCity_PokemonCenter_1F_EventScript_2C82AA:: @ 82C82AA
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7C7E, 4
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_2C82B4:: @ 82C82B4
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7CC8, 4
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2C82BE:: @ 82C82BE
	lock
	faceplayer
	checkflag FLAG_0x1BA
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C831C
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2C7CFA, 5
	compare VAR_RESULT, 0
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C8312
	call PacifidlogTown_PokemonCenter_1F_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C8312
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2C7E40, 4
	setvar VAR_0x8005, 12
	call PacifidlogTown_PokemonCenter_1F_EventScript_2C8326
	compare VAR_RESULT, 0
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C8312
	setflag FLAG_0x1BA
	goto PacifidlogTown_PokemonCenter_1F_EventScript_2C831C
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2C8312:: @ 82C8312
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2C7E04, 4
	release
	end

PacifidlogTown_PokemonCenter_1F_EventScript_2C831C:: @ 82C831C
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2C7E7A, 4
	release
	end

FallarborTown_Mart_EventScript_2C8326:: @ 82C8326
FortreeCity_House2_EventScript_2C8326:: @ 82C8326
LavaridgeTown_House_EventScript_2C8326:: @ 82C8326
LilycoveCity_DepartmentStoreRooftop_EventScript_2C8326:: @ 82C8326
MauvilleCity_EventScript_2C8326:: @ 82C8326
MossdeepCity_EventScript_2C8326:: @ 82C8326
PacifidlogTown_PokemonCenter_1F_EventScript_2C8326:: @ 82C8326
SlateportCity_PokemonFanClub_EventScript_2C8326:: @ 82C8326
SootopolisCity_PokemonCenter_1F_EventScript_2C8326:: @ 82C8326
VerdanturfTown_PokemonCenter_1F_EventScript_2C8326:: @ 82C8326
	special sub_81B892C
	waitstate
	lock
	faceplayer
	return

FallarborTown_Mart_EventScript_2C832D:: @ 82C832D
FortreeCity_House2_EventScript_2C832D:: @ 82C832D
LavaridgeTown_House_EventScript_2C832D:: @ 82C832D
LilycoveCity_DepartmentStoreRooftop_EventScript_2C832D:: @ 82C832D
MauvilleCity_EventScript_2C832D:: @ 82C832D
MossdeepCity_EventScript_2C832D:: @ 82C832D
PacifidlogTown_PokemonCenter_1F_EventScript_2C832D:: @ 82C832D
SlateportCity_PokemonFanClub_EventScript_2C832D:: @ 82C832D
SootopolisCity_PokemonCenter_1F_EventScript_2C832D:: @ 82C832D
VerdanturfTown_PokemonCenter_1F_EventScript_2C832D:: @ 82C832D
	msgbox MauvilleCity_Text_2C6E05, 5
	return

TrainerHill_1F_MapScript1_2C8336: @ 82C8336
TrainerHill_2F_MapScript1_2C8336: @ 82C8336
TrainerHill_3F_MapScript1_2C8336: @ 82C8336
TrainerHill_4F_MapScript1_2C8336: @ 82C8336
TrainerHill_Roof_MapScript1_2C8336: @ 82C8336
	setvar VAR_0x4002, 0
	setvar VAR_0x8004, 4
	special sp194_trainer_tower
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 5
	special sub_81A1780
	compare VAR_RESULT, 2
	goto_eq TrainerHill_1F_EventScript_2C83C9
	compare VAR_RESULT, 3
	goto_eq TrainerHill_1F_EventScript_2C83C9
	compare VAR_RESULT, 9
	goto_eq TrainerHill_1F_EventScript_2C83C9
	end

TrainerHill_1F_MapScript2_2C8372: @ 82C8372
TrainerHill_2F_MapScript2_2C8372: @ 82C8372
	map_script_2 VAR_0x4003, 0, TrainerHill_1F_EventScript_2C837C
	.2byte 0

TrainerHill_1F_EventScript_2C837C:: @ 82C837C
	setvar VAR_0x4003, 1
@ forced stop

TrainerHill_1F_MapScript2_2C8381: @ 82C8381
TrainerHill_2F_MapScript2_2C8381: @ 82C8381
TrainerHill_3F_MapScript2_2C8381: @ 82C8381
TrainerHill_4F_MapScript2_2C8381: @ 82C8381
TrainerHill_Roof_MapScript2_2C8381: @ 82C8381
	map_script_2 VAR_0x4002, 0, TrainerHill_1F_EventScript_2C83A6
	map_script_2 VAR_0x4001, 1, TrainerHill_1F_EventScript_2C83DF
	.2byte 0

TrainerHill_1F_EventScript_2C8393:: @ 82C8393
	lockall
	setvar VAR_0x8004, 7
	special sp194_trainer_tower
	msgbox TrainerHill_Entrance_Text_268D47, 4
	releaseall
	end

TrainerHill_1F_EventScript_2C83A6:: @ 82C83A6
	setvar VAR_0x4002, 1
	setvar VAR_0x8004, 9
	special sp194_trainer_tower
	compare VAR_RESULT, 1
	goto_eq TrainerHill_1F_EventScript_2C83BF
	end

TrainerHill_1F_EventScript_2C83BF:: @ 82C83BF
	warpsilent TRAINER_HILL_ENTRANCE, 255, 9, 6
	waitstate
	end

TrainerHill_1F_EventScript_2C83C9:: @ 82C83C9
	setvar VAR_0x8004, 12
	special sp194_trainer_tower
	setvar VAR_0x8004, 5
	special sp194_trainer_tower
	setvar VAR_0x4001, 1
	end

TrainerHill_1F_EventScript_2C83DF:: @ 82C83DF
TrainerHill_Entrance_EventScript_2C83DF:: @ 82C83DF
	setvar VAR_0x4001, 0
	warp TRAINER_HILL_ENTRANCE, 255, 9, 6
	waitstate
	end

TrainerHill_1F_Movement_2C83EE:: @ 82C83EE
	step_54
	step_end

EventScript_2C83F0:: @ 82C83F0
	trainerbattle 12, TRAINER_PHILLIP, 0, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D, BattleFrontier_BattlePyramidEmptySquare_Text_252C8D
	setvar VAR_0x8004, 11
	special sp194_trainer_tower
	waitmessage
	waitbuttonpress
	closemessage
	end

Text_ThisIsATestSignpostMsg:: @ 82C840A
	.string "This is a test message.\n"
	.string "This is a signpost.$"

EventScript_TestSignpostMsg:: @ 82C8436
	msgbox Text_ThisIsATestSignpostMsg, 3
	end

gText_082C843F:: @ 82C843F
	.string "It’s very disappointing…$"

gText_082C8458:: @ 82C8458
	.string "Okay, I understand…$"

gText_082C846C:: @ 82C846C
	.string "I’m terribly sorry…$"

gText_082C8480:: @ 82C8480
	.string "Thank you…$"

gText_082C848B:: @ 82C848B
	.string "Ahahaha! Aren’t you embarrassed?\n"
	.string "Everyone’s watching!$"

gText_082C84C1:: @ 82C84C1
	.string "Grr…\n"
	.string "What the…$"

gText_082C84D0:: @ 82C84D0
	.string "My DOME ACE title isn’t just for show!$"

gText_082C84F7:: @ 82C84F7
	.string "Ahahaha!\n"
	.string "You’re inspiring!$"

gText_082C8512:: @ 82C8512
	.string "Way to work!\n"
	.string "That was a good lesson, eh?$"

gText_082C853B:: @ 82C853B
	.string "Good job!\n"
	.string "You know what you’re doing!$"

gText_082C8561:: @ 82C8561
	.string "Hey, hey, hey!\n"
	.string "You’re finished already?$"

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
	.string "you’re wimpy as a TRAINER!$"

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
	.string "Hey! What’s wrong with you!\n"
	.string "Let’s see some effort! Get up!$"

gText_082C86FE:: @ 82C86FE
	.string "That’s it! You’ve done great!\n"
	.string "You’ve worked hard for this!$"

gText_082C8739:: @ 82C8739
	.string "Hey! Don’t you give up now!\n"
	.string "Get up! Don’t lose faith in yourself!$"

gText_082C877B:: @ 82C877B
	.string "That’s it! You’ve done it!\n"
	.string "You kept working for this!$"

	.align 2
	.include "data/text/save.inc"
	.include "data/text/birch_speech.inc"
