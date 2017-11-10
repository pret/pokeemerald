	.include "asm/macros.inc"
	.include "asm/macros/event.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

@ 81DB67C
	.include "data/event_script_command_function_table.inc"

gScriptCmdTableEnd:: @ 81DBA08
	.incbin "baserom.gba", 0x1dba08, 0x4

gSpecialVars:: @ 81DBA0C
	.incbin "baserom.gba", 0x1dba0c, 0x58

	.include "data/specials.inc"

gStdScripts:: @ 81DC2A0
	.incbin "baserom.gba", 0x1dc2a0, 0x2c

gStdScripts_End:: @ 81DC2CC
	map_script 3, PetalburgCity_MapScript1_1DC2D7
	map_script 2, PetalburgCity_MapScript2_1DC31C
	.byte 0

    .include "data/maps/scripts/PetalburgCity.inc"
	.include "data/maps/scripts/SlateportCity.inc"
	.include "data/maps/scripts/MauvilleCity.inc"
	.include "data/maps/scripts/RustboroCity.inc"
	.include "data/maps/scripts/FortreeCity.inc"
	.include "data/maps/scripts/LilycoveCity.inc"
	.include "data/maps/scripts/MossdeepCity.inc"
	.include "data/maps/scripts/SootopolisCity.inc"
	.include "data/maps/scripts/EverGrandeCity.inc"
	.include "data/maps/scripts/LittlerootTown.inc"
	.include "data/maps/scripts/OldaleTown.inc"
	.include "data/maps/scripts/DewfordTown.inc"
	.include "data/maps/scripts/LavaridgeTown.inc"
	.include "data/maps/scripts/FallarborTown.inc"
	.include "data/maps/scripts/VerdanturfTown.inc"
	.include "data/maps/scripts/PacifidlogTown.inc"
	.include "data/maps/scripts/Route101.inc"
	.include "data/maps/scripts/Route102.inc"
	.include "data/maps/scripts/Route103.inc"
	.include "data/maps/scripts/Route104.inc"
	.include "data/maps/scripts/Route105.inc"
	.include "data/maps/scripts/Route106.inc"
	.include "data/maps/scripts/Route107.inc"
	.include "data/maps/scripts/Route108.inc"
	.include "data/maps/scripts/Route109.inc"
	.include "data/maps/scripts/Route110.inc"
	.include "data/maps/scripts/Route111.inc"
	.include "data/maps/scripts/Route112.inc"
	.include "data/maps/scripts/Route113.inc"
	.include "data/maps/scripts/Route114.inc"
	.include "data/maps/scripts/Route115.inc"
	.include "data/maps/scripts/Route116.inc"
	.include "data/maps/scripts/Route117.inc"
	.include "data/maps/scripts/Route118.inc"
	.include "data/maps/scripts/Route119.inc"
	.include "data/maps/scripts/Route120.inc"
	.include "data/maps/scripts/Route121.inc"
	.include "data/maps/scripts/Route122.inc"
	.include "data/maps/scripts/Route123.inc"
	.include "data/maps/scripts/Route124.inc"
	.include "data/maps/scripts/Route125.inc"
	.include "data/maps/scripts/Route126.inc"
	.include "data/maps/scripts/Route127.inc"
	.include "data/maps/scripts/Route128.inc"
	.include "data/maps/scripts/Route129.inc"
	.include "data/maps/scripts/Route130.inc"
	.include "data/maps/scripts/Route131.inc"
	.include "data/maps/scripts/Route132.inc"
	.include "data/maps/scripts/Route133.inc"
	.include "data/maps/scripts/Route134.inc"
	.include "data/maps/scripts/Underwater1.inc"
	.include "data/maps/scripts/Underwater2.inc"
	.include "data/maps/scripts/Underwater3.inc"
	.include "data/maps/scripts/Underwater4.inc"
	.include "data/maps/scripts/Underwater5.inc"
	.include "data/maps/scripts/Underwater6.inc"
	.include "data/maps/scripts/Underwater7.inc"
	.include "data/maps/scripts/LittlerootTown_BrendansHouse_1F.inc"
	.include "data/maps/scripts/LittlerootTown_BrendansHouse_2F.inc"
	.include "data/maps/scripts/LittlerootTown_MaysHouse_1F.inc"
	.include "data/maps/scripts/LittlerootTown_MaysHouse_2F.inc"
	.include "data/maps/scripts/LittlerootTown_ProfessorBirchsLab.inc"
	.include "data/maps/scripts/OldaleTown_House1.inc"
	.include "data/maps/scripts/OldaleTown_House2.inc"
	.include "data/maps/scripts/OldaleTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/OldaleTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/OldaleTown_Mart.inc"
	.include "data/maps/scripts/DewfordTown_House1.inc"
	.include "data/maps/scripts/DewfordTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/DewfordTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/DewfordTown_Gym.inc"
	.include "data/maps/scripts/DewfordTown_Hall.inc"
	.include "data/maps/scripts/DewfordTown_House2.inc"
	.include "data/maps/scripts/LavaridgeTown_HerbShop.inc"
	.include "data/maps/scripts/LavaridgeTown_Gym_1F.inc"
	.include "data/maps/scripts/LavaridgeTown_Gym_B1F.inc"
	.include "data/maps/scripts/LavaridgeTown_House.inc"
	.include "data/maps/scripts/LavaridgeTown_Mart.inc"
	.include "data/maps/scripts/LavaridgeTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/LavaridgeTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/FallarborTown_Mart.inc"
	.include "data/maps/scripts/FallarborTown_BattleTentLobby.inc"
	.include "data/maps/scripts/FallarborTown_BattleTentCorridor.inc"
	.include "data/maps/scripts/FallarborTown_BattleTentBattleRoom.inc"
	.include "data/maps/scripts/FallarborTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/FallarborTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/FallarborTown_House1.inc"
	.include "data/maps/scripts/FallarborTown_House2.inc"
	.include "data/maps/scripts/VerdanturfTown_BattleTentLobby.inc"
	.include "data/maps/scripts/VerdanturfTown_BattleTentCorridor.inc"
	.include "data/maps/scripts/VerdanturfTown_BattleTentBattleRoom.inc"
	.include "data/maps/scripts/VerdanturfTown_Mart.inc"
	.include "data/maps/scripts/VerdanturfTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/VerdanturfTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/VerdanturfTown_WandasHouse.inc"
	.include "data/maps/scripts/VerdanturfTown_FriendshipRatersHouse.inc"
	.include "data/maps/scripts/VerdanturfTown_House.inc"
	.include "data/maps/scripts/PacifidlogTown_PokemonCenter_1F.inc"
	.include "data/maps/scripts/PacifidlogTown_PokemonCenter_2F.inc"
	.include "data/maps/scripts/PacifidlogTown_House1.inc"
	.include "data/maps/scripts/PacifidlogTown_House2.inc"
	.include "data/maps/scripts/PacifidlogTown_House3.inc"
	.include "data/maps/scripts/PacifidlogTown_House4.inc"
	.include "data/maps/scripts/PacifidlogTown_House5.inc"
	.include "data/maps/scripts/PetalburgCity_WallysHouse.inc"
	.include "data/maps/scripts/PetalburgCity_Gym.inc"
	.include "data/maps/scripts/PetalburgCity_House1.inc"
	.include "data/maps/scripts/PetalburgCity_House2.inc"
	.include "data/maps/scripts/PetalburgCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/PetalburgCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/PetalburgCity_Mart.inc"
	.include "data/maps/scripts/SlateportCity_SternsShipyard_1F.inc"
	.include "data/maps/scripts/SlateportCity_SternsShipyard_2F.inc"
	.include "data/maps/scripts/SlateportCity_BattleTentLobby.inc"
	.include "data/maps/scripts/SlateportCity_BattleTentCorridor.inc"
	.include "data/maps/scripts/SlateportCity_BattleTentBattleRoom.inc"
	.include "data/maps/scripts/SlateportCity_House1.inc"
	.include "data/maps/scripts/SlateportCity_PokemonFanClub.inc"
	.include "data/maps/scripts/SlateportCity_OceanicMuseum_1F.inc"
	.include "data/maps/scripts/SlateportCity_OceanicMuseum_2F.inc"
	.include "data/maps/scripts/SlateportCity_Harbor.inc"
	.include "data/maps/scripts/SlateportCity_House2.inc"
	.include "data/maps/scripts/SlateportCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/SlateportCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/SlateportCity_Mart.inc"
	.include "data/maps/scripts/MauvilleCity_Gym.inc"
	.include "data/maps/scripts/MauvilleCity_BikeShop.inc"
	.include "data/maps/scripts/MauvilleCity_House1.inc"
	.include "data/maps/scripts/MauvilleCity_GameCorner.inc"
	.include "data/maps/scripts/MauvilleCity_House2.inc"
	.include "data/maps/scripts/MauvilleCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/MauvilleCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/MauvilleCity_Mart.inc"
	.include "data/maps/scripts/RustboroCity_DevonCorp_1F.inc"
	.include "data/maps/scripts/RustboroCity_DevonCorp_2F.inc"
	.include "data/maps/scripts/RustboroCity_DevonCorp_3F.inc"
	.include "data/maps/scripts/RustboroCity_Gym.inc"
	.include "data/maps/scripts/RustboroCity_PokemonSchool.inc"
	.include "data/maps/scripts/RustboroCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/RustboroCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/RustboroCity_Mart.inc"
	.include "data/maps/scripts/RustboroCity_Flat1_1F.inc"
	.include "data/maps/scripts/RustboroCity_Flat1_2F.inc"
	.include "data/maps/scripts/RustboroCity_House1.inc"
	.include "data/maps/scripts/RustboroCity_CuttersHouse.inc"
	.include "data/maps/scripts/RustboroCity_House2.inc"
	.include "data/maps/scripts/RustboroCity_Flat2_1F.inc"
	.include "data/maps/scripts/RustboroCity_Flat2_2F.inc"
	.include "data/maps/scripts/RustboroCity_Flat2_3F.inc"
	.include "data/maps/scripts/RustboroCity_House3.inc"
	.include "data/maps/scripts/FortreeCity_House1.inc"
	.include "data/maps/scripts/FortreeCity_Gym.inc"
	.include "data/maps/scripts/FortreeCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/FortreeCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/FortreeCity_Mart.inc"
	.include "data/maps/scripts/FortreeCity_House2.inc"
	.include "data/maps/scripts/FortreeCity_House3.inc"
	.include "data/maps/scripts/FortreeCity_House4.inc"
	.include "data/maps/scripts/FortreeCity_House5.inc"
	.include "data/maps/scripts/FortreeCity_DecorationShop.inc"
	.include "data/maps/scripts/LilycoveCity_CoveLilyMotel_1F.inc"
	.include "data/maps/scripts/LilycoveCity_CoveLilyMotel_2F.inc"
	.include "data/maps/scripts/LilycoveCity_LilycoveMuseum_1F.inc"
	.include "data/maps/scripts/LilycoveCity_LilycoveMuseum_2F.inc"
	.include "data/maps/scripts/LilycoveCity_ContestLobby.inc"
	.include "data/maps/scripts/LilycoveCity_ContestHall.inc"
	.include "data/maps/scripts/LilycoveCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/LilycoveCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/LilycoveCity_UnusedMart.inc"
	.include "data/maps/scripts/LilycoveCity_PokemonTrainerFanClub.inc"
	.include "data/maps/scripts/LilycoveCity_Harbor.inc"
	.include "data/maps/scripts/LilycoveCity_MoveDeletersHouse.inc"
	.include "data/maps/scripts/LilycoveCity_House1.inc"
	.include "data/maps/scripts/LilycoveCity_House2.inc"
	.include "data/maps/scripts/LilycoveCity_House3.inc"
	.include "data/maps/scripts/LilycoveCity_House4.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStore_1F.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStore_2F.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStore_3F.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStore_4F.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStore_5F.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStoreRooftop.inc"
	.include "data/maps/scripts/LilycoveCity_DepartmentStoreElevator.inc"
	.include "data/maps/scripts/MossdeepCity_Gym.inc"
	.include "data/maps/scripts/MossdeepCity_House1.inc"
	.include "data/maps/scripts/MossdeepCity_House2.inc"
	.include "data/maps/scripts/MossdeepCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/MossdeepCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/MossdeepCity_Mart.inc"
	.include "data/maps/scripts/MossdeepCity_House3.inc"
	.include "data/maps/scripts/MossdeepCity_StevensHouse.inc"
	.include "data/maps/scripts/MossdeepCity_House4.inc"
	.include "data/maps/scripts/MossdeepCity_SpaceCenter_1F.inc"
	.include "data/maps/scripts/MossdeepCity_SpaceCenter_2F.inc"
	.include "data/maps/scripts/MossdeepCity_GameCorner_1F.inc"
	.include "data/maps/scripts/MossdeepCity_GameCorner_B1F.inc"
	.include "data/maps/scripts/SootopolisCity_Gym_1F.inc"
	.include "data/maps/scripts/SootopolisCity_Gym_B1F.inc"
	.include "data/maps/scripts/SootopolisCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/SootopolisCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/SootopolisCity_Mart.inc"
	.include "data/maps/scripts/SootopolisCity_House1.inc"
	.include "data/maps/scripts/SootopolisCity_House2.inc"
	.include "data/maps/scripts/SootopolisCity_House3.inc"
	.include "data/maps/scripts/SootopolisCity_House4.inc"
	.include "data/maps/scripts/SootopolisCity_House5.inc"
	.include "data/maps/scripts/SootopolisCity_House6.inc"
	.include "data/maps/scripts/SootopolisCity_House7.inc"
	.include "data/maps/scripts/SootopolisCity_LotadAndSeedotHouse.inc"
	.include "data/maps/scripts/SootopolisCity_MysteryEventsHouse_1F.inc"
	.include "data/maps/scripts/SootopolisCity_MysteryEventsHouse_B1F.inc"
	.include "data/maps/scripts/EverGrandeCity_SidneysRoom.inc"
	.include "data/maps/scripts/EverGrandeCity_PhoebesRoom.inc"
	.include "data/maps/scripts/EverGrandeCity_GlaciasRoom.inc"
	.include "data/maps/scripts/EverGrandeCity_DrakesRoom.inc"
	.include "data/maps/scripts/EverGrandeCity_ChampionsRoom.inc"
	.include "data/maps/scripts/EverGrandeCity_Hall1.inc"
	.include "data/maps/scripts/EverGrandeCity_Hall2.inc"
	.include "data/maps/scripts/EverGrandeCity_Hall3.inc"
	.include "data/maps/scripts/EverGrandeCity_Hall4.inc"
	.include "data/maps/scripts/EverGrandeCity_Hall5.inc"
	.include "data/maps/scripts/EverGrandeCity_PokemonLeague_1F.inc"
	.include "data/maps/scripts/EverGrandeCity_HallOfFame.inc"
	.include "data/maps/scripts/EverGrandeCity_PokemonCenter_1F.inc"
	.include "data/maps/scripts/EverGrandeCity_PokemonCenter_2F.inc"
	.include "data/maps/scripts/EverGrandeCity_PokemonLeague_2F.inc"
	.include "data/maps/scripts/Route104_MrBrineysHouse.inc"
	.include "data/maps/scripts/Route104_PrettyPetalFlowerShop.inc"
	.include "data/maps/scripts/Route111_WinstrateFamilysHouse.inc"
	.include "data/maps/scripts/Route111_OldLadysRestStop.inc"
	.include "data/maps/scripts/Route112_CableCarStation.inc"
	.include "data/maps/scripts/MtChimney_CableCarStation.inc"
	.include "data/maps/scripts/Route114_FossilManiacsHouse.inc"
	.include "data/maps/scripts/Route114_FossilManiacsTunnel.inc"
	.include "data/maps/scripts/Route114_LanettesHouse.inc"
	.include "data/maps/scripts/Route116_TunnelersRestHouse.inc"
	.include "data/maps/scripts/Route117_PokemonDayCare.inc"
	.include "data/maps/scripts/Route121_SafariZoneEntrance.inc"
	.include "data/maps/scripts/MeteorFalls_1F_1R.inc"
	.include "data/maps/scripts/MeteorFalls_1F_2R.inc"
	.include "data/maps/scripts/MeteorFalls_B1F_1R.inc"
	.include "data/maps/scripts/MeteorFalls_B1F_2R.inc"
	.include "data/maps/scripts/RusturfTunnel.inc"
	.include "data/maps/scripts/Underwater_SootopolisCity.inc"
	.include "data/maps/scripts/DesertRuins.inc"
	.include "data/maps/scripts/GraniteCave_1F.inc"
	.include "data/maps/scripts/GraniteCave_B1F.inc"
	.include "data/maps/scripts/GraniteCave_B2F.inc"
	.include "data/maps/scripts/GraniteCave_StevensRoom.inc"
	.include "data/maps/scripts/PetalburgWoods.inc"
	.include "data/maps/scripts/MtChimney.inc"
	.include "data/maps/scripts/JaggedPass.inc"
	.include "data/maps/scripts/FieryPath.inc"
	.include "data/maps/scripts/MtPyre_1F.inc"
	.include "data/maps/scripts/MtPyre_2F.inc"
	.include "data/maps/scripts/MtPyre_3F.inc"
	.include "data/maps/scripts/MtPyre_4F.inc"
	.include "data/maps/scripts/MtPyre_5F.inc"
	.include "data/maps/scripts/MtPyre_6F.inc"
	.include "data/maps/scripts/MtPyre_Exterior.inc"
	.include "data/maps/scripts/MtPyre_Summit.inc"
	.include "data/maps/scripts/AquaHideout_1F.inc"
	.include "data/maps/scripts/AquaHideout_B1F.inc"
	.include "data/maps/scripts/AquaHideout_B2F.inc"
	.include "data/maps/scripts/Underwater_SeafloorCavern.inc"
	.include "data/maps/scripts/SeafloorCavern_Entrance.inc"
	.include "data/maps/scripts/SeafloorCavern_Room1.inc"
	.include "data/maps/scripts/SeafloorCavern_Room2.inc"
	.include "data/maps/scripts/SeafloorCavern_Room3.inc"
	.include "data/maps/scripts/SeafloorCavern_Room4.inc"
	.include "data/maps/scripts/SeafloorCavern_Room5.inc"
	.include "data/maps/scripts/SeafloorCavern_Room6.inc"
	.include "data/maps/scripts/SeafloorCavern_Room7.inc"
	.include "data/maps/scripts/SeafloorCavern_Room8.inc"
	.include "data/maps/scripts/SeafloorCavern_Room9.inc"
	.include "data/maps/scripts/CaveOfOrigin_Entrance.inc"
	.include "data/maps/scripts/CaveOfOrigin_1F.inc"
	.include "data/maps/scripts/CaveOfOrigin_UnusedRubySapphireMap1.inc"
	.include "data/maps/scripts/CaveOfOrigin_UnusedRubySapphireMap2.inc"
	.include "data/maps/scripts/CaveOfOrigin_UnusedRubySapphireMap3.inc"
	.include "data/maps/scripts/CaveOfOrigin_B1F.inc"
	.include "data/maps/scripts/VictoryRoad_1F.inc"
	.include "data/maps/scripts/VictoryRoad_B1F.inc"
	.include "data/maps/scripts/VictoryRoad_B2F.inc"
	.include "data/maps/scripts/ShoalCave_LowTideEntranceRoom.inc"
	.include "data/maps/scripts/ShoalCave_LowTideInnerRoom.inc"
	.include "data/maps/scripts/ShoalCave_LowTideStairsRoom.inc"
	.include "data/maps/scripts/ShoalCave_LowTideLowerRoom.inc"
	.include "data/maps/scripts/ShoalCave_HighTideEntranceRoom.inc"
	.include "data/maps/scripts/ShoalCave_HighTideInnerRoom.inc"
	.include "data/maps/scripts/NewMauville_Entrance.inc"
	.include "data/maps/scripts/NewMauville_Inside.inc"
	.include "data/maps/scripts/AbandonedShip_Deck.inc"
	.include "data/maps/scripts/AbandonedShip_Corridors_1F.inc"
	.include "data/maps/scripts/AbandonedShip_Rooms_1F.inc"
	.include "data/maps/scripts/AbandonedShip_Corridors_B1F.inc"
	.include "data/maps/scripts/AbandonedShip_Rooms_B1F.inc"
	.include "data/maps/scripts/AbandonedShip_Rooms2_B1F.inc"
	.include "data/maps/scripts/AbandonedShip_Underwater1.inc"
	.include "data/maps/scripts/AbandonedShip_Room_B1F.inc"
	.include "data/maps/scripts/AbandonedShip_Rooms2_1F.inc"
	.include "data/maps/scripts/AbandonedShip_CaptainsOffice.inc"
	.include "data/maps/scripts/AbandonedShip_Underwater2.inc"
	.include "data/maps/scripts/AbandonedShip_HiddenFloorCorridors.inc"
	.include "data/maps/scripts/AbandonedShip_HiddenFloorRooms.inc"
	.include "data/maps/scripts/IslandCave.inc"
	.include "data/maps/scripts/AncientTomb.inc"
	.include "data/maps/scripts/Underwater_Route134.inc"
	.include "data/maps/scripts/Underwater_SealedChamber.inc"
	.include "data/maps/scripts/SealedChamber_OuterRoom.inc"
	.include "data/maps/scripts/SealedChamber_InnerRoom.inc"
	.include "data/maps/scripts/ScorchedSlab.inc"
	.include "data/maps/scripts/AquaHideout_UnusedRubyMap1.inc"
	.include "data/maps/scripts/AquaHideout_UnusedRubyMap2.inc"
	.include "data/maps/scripts/AquaHideout_UnusedRubyMap3.inc"
	.include "data/maps/scripts/SkyPillar_Entrance.inc"
	.include "data/maps/scripts/SkyPillar_Outside.inc"
	.include "data/maps/scripts/SkyPillar_1F.inc"
	.include "data/maps/scripts/SkyPillar_2F.inc"
	.include "data/maps/scripts/SkyPillar_3F.inc"
	.include "data/maps/scripts/SkyPillar_4F.inc"
	.include "data/maps/scripts/ShoalCave_LowTideIceRoom.inc"
	.include "data/maps/scripts/SkyPillar_5F.inc"
	.include "data/maps/scripts/SkyPillar_Top.inc"
	.include "data/maps/scripts/MagmaHideout_1F.inc"
	.include "data/maps/scripts/MagmaHideout_2F_1R.inc"
	.include "data/maps/scripts/MagmaHideout_2F_2R.inc"
	.include "data/maps/scripts/MagmaHideout_3F_1R.inc"
	.include "data/maps/scripts/MagmaHideout_3F_2R.inc"
	.include "data/maps/scripts/MagmaHideout_4F.inc"
	.include "data/maps/scripts/MagmaHideout_3F_3R.inc"
	.include "data/maps/scripts/MagmaHideout_2F_3R.inc"
	.include "data/maps/scripts/MirageTower_1F.inc"
	.include "data/maps/scripts/MirageTower_2F.inc"
	.include "data/maps/scripts/MirageTower_3F.inc"
	.include "data/maps/scripts/MirageTower_4F.inc"
	.include "data/maps/scripts/DesertUnderpass.inc"
	.include "data/maps/scripts/ArtisanCave_B1F.inc"
	.include "data/maps/scripts/ArtisanCave_1F.inc"
	.include "data/maps/scripts/Underwater_MarineCave.inc"
	.include "data/maps/scripts/MarineCave_Entrance.inc"
	.include "data/maps/scripts/MarineCave_End.inc"
	.include "data/maps/scripts/TerraCave_Entrance.inc"
	.include "data/maps/scripts/TerraCave_End.inc"
	.include "data/maps/scripts/AlteringCave.inc"
	.include "data/maps/scripts/MeteorFalls_StevensCave.inc"
	.include "data/maps/scripts/SecretBase_BlueCave1.inc"
	.include "data/maps/scripts/SecretBase_BlueCave2.inc"
	.include "data/maps/scripts/SecretBase_BlueCave3.inc"
	.include "data/maps/scripts/SecretBase_BlueCave4.inc"
	.include "data/maps/scripts/SecretBase_BrownCave1.inc"
	.include "data/maps/scripts/SecretBase_BrownCave2.inc"
	.include "data/maps/scripts/SecretBase_BrownCave3.inc"
	.include "data/maps/scripts/SecretBase_BrownCave4.inc"
	.include "data/maps/scripts/SecretBase_RedCave1.inc"
	.include "data/maps/scripts/SecretBase_RedCave2.inc"
	.include "data/maps/scripts/SecretBase_RedCave3.inc"
	.include "data/maps/scripts/SecretBase_RedCave4.inc"
	.include "data/maps/scripts/SecretBase_Shrub1.inc"
	.include "data/maps/scripts/SecretBase_Shrub2.inc"
	.include "data/maps/scripts/SecretBase_Shrub3.inc"
	.include "data/maps/scripts/SecretBase_Shrub4.inc"
	.include "data/maps/scripts/SecretBase_Tree1.inc"
	.include "data/maps/scripts/SecretBase_Tree2.inc"
	.include "data/maps/scripts/SecretBase_Tree3.inc"
	.include "data/maps/scripts/SecretBase_Tree4.inc"
	.include "data/maps/scripts/SecretBase_YellowCave1.inc"
	.include "data/maps/scripts/SecretBase_YellowCave2.inc"
	.include "data/maps/scripts/SecretBase_YellowCave3.inc"
	.include "data/maps/scripts/SecretBase_YellowCave4.inc"

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
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq EventScript_23B62F
	compare_var_to_value VAR_RESULT, 2
	goto_eq EventScript_23B652
	special sub_80E980C
	msgbox Text_276707, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq EventScript_23B5A1
	msgbox Text_2767D1, 3
	special sub_80E9C2C
	special sub_80FA57C
	releaseall
	end

EventScript_23B62F:: @ 823B62F
	msgbox Text_276731, 5
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq EventScript_23B6BC
	compare_var_to_value VAR_RESULT, 1
	goto_eq EventScript_23B6C5
	compare_var_to_value VAR_RESULT, 2
	goto_eq EventScript_23B6CE
	compare_var_to_value VAR_RESULT, 3
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

	.include "data/maps/scripts/SingleBattleColosseum.inc"
	.include "data/maps/scripts/TradeCenter.inc"
	.include "data/maps/scripts/RecordCorner.inc"
	.include "data/maps/scripts/DoubleBattleColosseum.inc"
	.include "data/maps/scripts/LinkContestRoom1.inc"
	.include "data/maps/scripts/LinkContestRoom2.inc"
	.include "data/maps/scripts/LinkContestRoom3.inc"
	.include "data/maps/scripts/LinkContestRoom4.inc"
	.include "data/maps/scripts/LinkContestRoom5.inc"
	.include "data/maps/scripts/LinkContestRoom6.inc"
	.include "data/maps/scripts/UnknownMap_25_29.inc"
	.include "data/maps/scripts/UnknownMap_25_30.inc"
	.include "data/maps/scripts/UnknownMap_25_31.inc"
	.include "data/maps/scripts/UnknownMap_25_32.inc"
	.include "data/maps/scripts/UnknownMap_25_33.inc"
	.include "data/maps/scripts/UnknownMap_25_34.inc"
	.include "data/maps/scripts/InsideOfTruck.inc"
	.include "data/maps/scripts/SSTidalCorridor.inc"
	.include "data/maps/scripts/SSTidalLowerDeck.inc"
	.include "data/maps/scripts/SSTidalRooms.inc"
	.include "data/maps/scripts/BattlePyramidSquare01.inc"
	.include "data/maps/scripts/BattlePyramidSquare02.inc"
	.include "data/maps/scripts/BattlePyramidSquare03.inc"
	.include "data/maps/scripts/BattlePyramidSquare04.inc"
	.include "data/maps/scripts/BattlePyramidSquare05.inc"
	.include "data/maps/scripts/BattlePyramidSquare06.inc"
	.include "data/maps/scripts/BattlePyramidSquare07.inc"
	.include "data/maps/scripts/BattlePyramidSquare08.inc"
	.include "data/maps/scripts/BattlePyramidSquare09.inc"
	.include "data/maps/scripts/BattlePyramidSquare10.inc"
	.include "data/maps/scripts/BattlePyramidSquare11.inc"
	.include "data/maps/scripts/BattlePyramidSquare12.inc"
	.include "data/maps/scripts/BattlePyramidSquare13.inc"
	.include "data/maps/scripts/BattlePyramidSquare14.inc"
	.include "data/maps/scripts/BattlePyramidSquare15.inc"
	.include "data/maps/scripts/BattlePyramidSquare16.inc"
	.include "data/maps/scripts/UnionRoom.inc"
	.include "data/maps/scripts/SafariZone_Northwest.inc"
	.include "data/maps/scripts/SafariZone_North.inc"
	.include "data/maps/scripts/SafariZone_Southwest.inc"
	.include "data/maps/scripts/SafariZone_South.inc"
	.include "data/maps/scripts/BattleFrontier_OutsideWest.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerElevator.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerCorridor.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerBattleRoom.inc"
	.include "data/maps/scripts/SouthernIsland_Exterior.inc"
	.include "data/maps/scripts/SouthernIsland_Interior.inc"
	.include "data/maps/scripts/SafariZone_RestHouse.inc"
	.include "data/maps/scripts/SafariZone_Northeast.inc"
	.include "data/maps/scripts/SafariZone_Southeast.inc"
	.include "data/maps/scripts/BattleFrontier_OutsideEast.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerMultiBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerCorridor2.inc"
	.include "data/maps/scripts/BattleFrontier_BattleTowerBattleRoom2.inc"
	.include "data/maps/scripts/BattleFrontier_BattleDomeLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattleDomeCorridor.inc"
	.include "data/maps/scripts/BattleFrontier_BattleDomePreBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattleDomeBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePalaceLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePalaceCorridor.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePalaceBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePyramidLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePyramidEmptySquare.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePyramidTop.inc"
	.include "data/maps/scripts/BattleFrontier_BattleArenaLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattleArenaCorridor.inc"
	.include "data/maps/scripts/BattleFrontier_BattleArenaBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattleFactoryLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattleFactoryPreBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattleFactoryBattleRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeLobby.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeCorridor.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeThreePathRoom.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeRandomRoom1.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeRandomRoom2.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePikeRandomRoom3.inc"
	.include "data/maps/scripts/BattleFrontier_RankingHall.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge1.inc"
	.include "data/maps/scripts/BattleFrontier_BattlePointExchangeServiceCorner.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge2.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge3.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge4.inc"
	.include "data/maps/scripts/BattleFrontier_ScottsHouse.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge5.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge6.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge7.inc"
	.include "data/maps/scripts/BattleFrontier_ReceptionGate.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge8.inc"
	.include "data/maps/scripts/BattleFrontier_Lounge9.inc"
	.include "data/maps/scripts/BattleFrontier_PokemonCenter_1F.inc"
	.include "data/maps/scripts/BattleFrontier_PokemonCenter_2F.inc"
	.include "data/maps/scripts/BattleFrontier_Mart.inc"
	.include "data/maps/scripts/FarawayIsland_Entrance.inc"
	.include "data/maps/scripts/FarawayIsland_Interior.inc"
	.include "data/maps/scripts/BirthIsland_Exterior.inc"
	.include "data/maps/scripts/BirthIsland_Harbor.inc"
	.include "data/maps/scripts/TrainerHill_Entrance.inc"
	.include "data/maps/scripts/TrainerHill_1F.inc"
	.include "data/maps/scripts/TrainerHill_2F.inc"
	.include "data/maps/scripts/TrainerHill_3F.inc"
	.include "data/maps/scripts/TrainerHill_4F.inc"
	.include "data/maps/scripts/TrainerHill_Roof.inc"
	.include "data/maps/scripts/NavelRock_Exterior.inc"
	.include "data/maps/scripts/NavelRock_Harbor.inc"
	.include "data/maps/scripts/NavelRock_Entrance.inc"
	.include "data/maps/scripts/NavelRock_B1F.inc"
	.include "data/maps/scripts/NavelRock_Fork.inc"
	.include "data/maps/scripts/NavelRock_Up1.inc"
	.include "data/maps/scripts/NavelRock_Up2.inc"
	.include "data/maps/scripts/NavelRock_Up3.inc"
	.include "data/maps/scripts/NavelRock_Up4.inc"
	.include "data/maps/scripts/NavelRock_Top.inc"
	.include "data/maps/scripts/NavelRock_Down01.inc"
	.include "data/maps/scripts/NavelRock_Down02.inc"
	.include "data/maps/scripts/NavelRock_Down03.inc"
	.include "data/maps/scripts/NavelRock_Down04.inc"
	.include "data/maps/scripts/NavelRock_Down05.inc"
	.include "data/maps/scripts/NavelRock_Down06.inc"
	.include "data/maps/scripts/NavelRock_Down07.inc"
	.include "data/maps/scripts/NavelRock_Down08.inc"
	.include "data/maps/scripts/NavelRock_Down09.inc"
	.include "data/maps/scripts/NavelRock_Down10.inc"
	.include "data/maps/scripts/NavelRock_Down11.inc"
	.include "data/maps/scripts/NavelRock_Bottom.inc"
	.include "data/maps/scripts/TrainerHill_Elevator.inc"
	.include "data/maps/scripts/Route104_Prototype.inc"
	.include "data/maps/scripts/Route104_PrototypePrettyPetalFlowerShop.inc"
	.include "data/maps/scripts/Route109_SeashoreHouse.inc"
	.include "data/maps/scripts/Route110_TrickHouseEntrance.inc"
	.include "data/maps/scripts/Route110_TrickHouseEnd.inc"
	.include "data/maps/scripts/Route110_TrickHouseCorridor.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle1.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle2.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle3.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle4.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle5.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle6.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle7.inc"
	.include "data/maps/scripts/Route110_TrickHousePuzzle8.inc"
	.include "data/maps/scripts/Route110_SeasideCyclingRoadEntrance1.inc"
	.include "data/maps/scripts/Route110_SeasideCyclingRoadEntrance2.inc"
	.include "data/maps/scripts/Route113_GlassWorkshop.inc"
	.include "data/maps/scripts/Route123_BerryMastersHouse.inc"
	.include "data/maps/scripts/Route119_WeatherInstitute_1F.inc"
	.include "data/maps/scripts/Route119_WeatherInstitute_2F.inc"
	.include "data/maps/scripts/Route119_House.inc"
	.include "data/maps/scripts/Route124_DivingTreasureHuntersHouse.inc"

gUnknown_08271354:: @ 8271354
	.incbin "baserom.gba", 0x271354, 0xe

gUnknown_08271362:: @ 8271362
	.incbin "baserom.gba", 0x271362, 0x28

gUnknown_0827138A:: @ 827138A
	.incbin "baserom.gba", 0x27138a, 0x38

gUnknown_082713C2:: @ 82713C2
	.incbin "baserom.gba", 0x2713c2, 0xf

gUnknown_082713D1:: @ 82713D1
	.incbin "baserom.gba", 0x2713d1, 0x27

gUnknown_082713F8:: @ 82713F8
	.incbin "baserom.gba", 0x2713f8, 0x1e6

gUnknown_082715DE:: @ 82715DE

	.incbin "baserom.gba", 0x2715de, 0x1e3

EverGrandeCity_HallOfFame_EventScript_2717C1:: @ 82717C1
	special sub_81AFDD0
	setflag FLAG_0x87F
	call EverGrandeCity_HallOfFame_EventScript_271829
	compare_var_to_value VAR_0x40CC, 0
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
	compare_var_to_value VAR_0x40D3, 0
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

gUnknown_08271857:: @ 8271857
	.incbin "baserom.gba", 0x271857, 0xb

gUnknown_08271862:: @ 8271862

	.incbin "baserom.gba", 0x271862, 0x6a

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
	compare_var_to_value VAR_RESULT, 4
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A68
	msgbox gUnknown_082726EB, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_27195A
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271954
	end

OldaleTown_PokemonCenter_1F_EventScript_271954:: @ 8271954
	message gUnknown_082727DB
	return

OldaleTown_PokemonCenter_1F_EventScript_27195A:: @ 827195A
	incrementgamestat 15
	compare_var_to_value VAR_0x8004, 0
	call_if 1, OldaleTown_PokemonCenter_1F_EventScript_271987
	compare_var_to_value VAR_0x8004, 1
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
	special sp000_heal_pokemon
	return

OldaleTown_PokemonCenter_1F_EventScript_2719B1:: @ 82719B1
	specialvar VAR_RESULT, sub_8139ED0
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719E2
	specialvar VAR_RESULT, sp182_move_string
	copyvar VAR_0x8008, VAR_RESULT
	compare_var_to_value VAR_0x8008, 0
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_2719E2
	compare_var_to_value VAR_0x8008, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A19
	end

OldaleTown_PokemonCenter_1F_EventScript_2719E2:: @ 82719E2
	compare_var_to_value VAR_0x8004, 1
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
	specialvar VAR_RESULT, sub_8139540
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271A5F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_1F_EventScript_271AC5
	message gUnknown_08272A07
	return

OldaleTown_PokemonCenter_1F_EventScript_271AAC:: @ 8271AAC
	msgbox gUnknown_08272982, 5
	compare_var_to_value VAR_RESULT, 1
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

	.incbin "baserom.gba", 0x271ad3, 0x1e4

gUnknown_08271CB7:: @ 8271CB7
	.incbin "baserom.gba", 0x271cb7, 0xdb

gUnknown_08271D92:: @ 8271D92

	.incbin "baserom.gba", 0x271d92, 0xd8

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

gUnknown_08271EA0:: @ 8271EA0

	.incbin "baserom.gba", 0x271ea0, 0x37

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
	compare_var_to_value VAR_RESULT, 0
	goto_eq RustboroCity_EventScript_271EEF
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LavaridgeTown_EventScript_271F13
	compare_var_to_value VAR_RESULT, 1
	goto_eq LavaridgeTown_EventScript_271F19
	end

LavaridgeTown_EventScript_271F13:: @ 8271F13
	setvar VAR_0x4013, 106
	return

LavaridgeTown_EventScript_271F19:: @ 8271F19
	setvar VAR_0x4013, 101
	return

	.incbin "baserom.gba", 0x271f1f, 0x24

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
	playfanfare BGM_ME_BACHI
	waitfanfare
	return

LittlerootTown_BrendansHouse_1F_EventScript_272083:: @ 8272083
Route111_OldLadysRestStop_EventScript_272083:: @ 8272083
Route119_WeatherInstitute_1F_EventScript_272083:: @ 8272083
RustboroCity_DevonCorp_3F_EventScript_272083:: @ 8272083
SSTidalRooms_EventScript_272083:: @ 8272083
	fadescreen 1
	playfanfare BGM_ME_ASA
	waitfanfare
	special sp000_heal_pokemon
	fadescreen 0
	return

gUnknown_0827208F:: @ 827208F

	.incbin "baserom.gba", 0x27208f, 0x11

DewfordTown_EventScript_2720A0:: @ 82720A0
Route104_EventScript_2720A0:: @ 82720A0
Route109_EventScript_2720A0:: @ 82720A0
	setflag FLAG_SPECIAL_FLAG_0x4001
	playbgm BGM_M_BOAT, 0
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
	compare_var_to_value VAR_0x4085, 0
	goto_eq Route101_EventScript_27374E
	checkflag FLAG_SYS_GAME_CLEAR
	goto_eq Route101_EventScript_27211A
	compare_var_to_value VAR_BIRCH_STATE, 0
	call_if 1, Route101_EventScript_27211A
	compare_var_to_value VAR_BIRCH_STATE, 1
	call_if 1, Route101_EventScript_27211A
	compare_var_to_value VAR_BIRCH_STATE, 2
	call_if 1, Route101_EventScript_272127
	compare_var_to_value VAR_BIRCH_STATE, 3
	call_if 1, Route101_EventScript_272127
	compare_var_to_value VAR_BIRCH_STATE, 4
	call_if 1, Route101_EventScript_272134
	compare_var_to_value VAR_BIRCH_STATE, 5
	call_if 1, Route101_EventScript_272134
	compare_var_to_value VAR_BIRCH_STATE, 6
	call_if 1, Route101_EventScript_27211A
	compare_var_to_value VAR_BIRCH_STATE, 7
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
	checkflag FLAG_0x12F
	goto_if 0, Route101_EventScript_272155
	checkflag FLAG_0x119
	goto_if 0, Route101_EventScript_1FA2D2

Route101_EventScript_272155:: @ 8272155
	msgbox gUnknown_082A5C9C, 5
	compare_var_to_value VAR_RESULT, 0
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
	special sub_8137C10
	waitmessage
	waitbuttonpress
	return

EverGrandeCity_ChampionsRoom_EventScript_272184:: @ 8272184
Route101_EventScript_272184:: @ 8272184
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, sub_8137A4C
	copyvar VAR_0x8008, VAR_0x8005
	copyvar VAR_0x8009, VAR_0x8006
	copyvar VAR_0x800A, VAR_RESULT
	buffernumberstring 0, VAR_0x8008
	buffernumberstring 1, VAR_0x8009
	msgbox gUnknown_082A5D2C, 4
	call Route101_EventScript_272179
	compare_var_to_value VAR_0x800A, 0
	goto_eq Route101_EventScript_27374E
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, sub_8137A4C
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

	.incbin "baserom.gba", 0x27222b, 0x25

BattleFrontier_OutsideWest_EventScript_272250:: @ 8272250
BirthIsland_Harbor_EventScript_272250:: @ 8272250
FarawayIsland_Entrance_EventScript_272250:: @ 8272250
NavelRock_Harbor_EventScript_272250:: @ 8272250
SouthernIsland_Exterior_EventScript_272250:: @ 8272250
	compare_var_to_value VAR_FACING, 1
	call_if 1, BattleFrontier_OutsideWest_EventScript_242A21
	compare_var_to_value VAR_FACING, 3
	call_if 1, BattleFrontier_OutsideWest_EventScript_242A2C
	delay 30
	hideobjectat 255, PETALBURG_CITY
	call BattleFrontier_OutsideWest_EventScript_2721E2
	return

	.incbin "baserom.gba", 0x272274, 0x4d

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
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route119_EventScript_272350
	msgbox Route119_Text_1F5D00, 4
	release
	end

Route119_EventScript_272350:: @ 8272350
	msgbox Route119_Text_1F5D23, 5
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route119_EventScript_2723C1
	compare_var_to_value VAR_RESULT, 4
	goto_eq Route119_EventScript_2723C1
	compare_var_to_value VAR_RESULT, 5
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
	playfanfare BGM_ME_WAZA
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

	.incbin "baserom.gba", 0x2725cb, 0x3

gUnknown_082725CE:: @ 82725CE
	.incbin "baserom.gba", 0x2725ce, 0x9

gUnknown_082725D7:: @ 82725D7
	.incbin "baserom.gba", 0x2725d7, 0x9

gUnknown_082725E0:: @ 82725E0
	.incbin "baserom.gba", 0x2725e0, 0x9

gUnknown_082725E9:: @ 82725E9
	.incbin "baserom.gba", 0x2725e9, 0x9

gUnknown_082725F2:: @ 82725F2
	.incbin "baserom.gba", 0x2725f2, 0x9

gUnknown_082725FB:: @ 82725FB
	.incbin "baserom.gba", 0x2725fb, 0x9

gUnknown_08272604:: @ 8272604
	.incbin "baserom.gba", 0x272604, 0x6b

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


gUnknown_08272FD6:: @ 8272FD6
	.string "The water is dyed a deep blue…\nWould you like to SURF?$"


gUnknown_0827300D:: @ 827300D
	.string "{STR_VAR_1} used SURF!$"


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

gUnknown_082736B3:: @ 82736B3
	.incbin "baserom.gba", 0x2736b3, 0x9

gUnknown_082736BC:: @ 82736BC

	.incbin "baserom.gba", 0x2736bc, 0x92

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

	.incbin "baserom.gba", 0x27374f, 0x6

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
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
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

gUnknown_0827381B:: @ 827381B

	.incbin "baserom.gba", 0x27381b, 0xf8

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
	compare_var_to_value VAR_0x4037, 9
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

	.incbin "baserom.gba", 0x2742c9, 0x1d

gUnknown_082742E6:: @ 82742E6

	.incbin "baserom.gba", 0x2742e6, 0x10

LavaridgeTown_Gym_1F_EventScript_2742F6:: @ 82742F6
	ontrainerbattleendgoto
	releaseall
	end

BerryTreeScript:: @ 82742F9

BerryTreeScript:: @ 82742F9
	special FieldObjectInteractionGetBerryTreeData
	switch VAR_0x8004
	case 255, Route102_EventScript_27434F
	case 0, Route102_EventScript_274359
	case 1, Route102_EventScript_2743B1
	case 2, Route102_EventScript_2743C1
	case 3, Route102_EventScript_2743D1
	case 4, Route102_EventScript_2743E1
	case 5, Route102_EventScript_274421
	end

Route102_EventScript_27434F:: @ 827434F
	lockall
	message Route102_Text_274744
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_274359:: @ 8274359
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route102_EventScript_274374
	message Route102_Text_2744F0
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274374:: @ 8274374
	msgbox Route102_Text_274507, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route102_EventScript_274393
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route102_EventScript_2743AF
	end

Route102_EventScript_274393:: @ 8274393
	fadescreen 1
	closemessage
	special Bag_ChooseBerry
	waitstate
	compare_var_to_value VAR_ITEM_ID, 0
	goto_eq Route102_EventScript_2743AF
	takeitem VAR_ITEM_ID, 1
	call Route102_EventScript_2744DD

Route102_EventScript_2743AF:: @ 82743AF
	release
	end

Route102_EventScript_2743B1:: @ 82743B1
	lockall
	special FieldObjectInteractionGetBerryCountString
	message Route102_Text_274560
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743C1:: @ 82743C1
	lockall
	special FieldObjectInteractionGetBerryName
	message Route102_Text_274579
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743D1:: @ 82743D1
	lockall
	special FieldObjectInteractionGetBerryName
	message Route102_Text_27458A
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743E1:: @ 82743E1
	call Route102_EventScript_2743F6
	lockall
	special FieldObjectInteractionGetBerryName
	message Route102_Text_2745AB
	waitmessage
	waitbuttonpress
	goto Route102_EventScript_27448D

Route102_EventScript_2743F6:: @ 82743F6
	compare_var_to_value VAR_0x8005, 0
	goto_eq Route102_EventScript_27441A
	compare_var_to_value VAR_0x8005, 4
	goto_eq Route102_EventScript_274413
	bufferstring 1, Route102_Text_2745E5
	return

Route102_EventScript_274413:: @ 8274413
	bufferstring 1, Route102_Text_2745CD
	return

Route102_EventScript_27441A:: @ 827441A
	bufferstring 1, Route102_Text_2745DE
	return

Route102_EventScript_274421:: @ 8274421
	buffernumberstring 1, VAR_0x8006
	lock
	faceplayer
	special FieldObjectInteractionGetBerryCountString
	msgbox Route102_Text_2745EE, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route102_EventScript_274448
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route102_EventScript_274479

Route102_EventScript_274448:: @ 8274448
	special FieldObjectInteractionPickBerryTree
	compare_var_to_value VAR_0x8004, 0
	goto_eq Route102_EventScript_274470
	special sub_80EED34
	special FieldObjectInteractionRemoveBerryTree
	message Route102_Text_27461B
	playfanfare BGM_ME_KINOMI
	waitmessage
	waitfanfare
	waitbuttonpress
	message Route102_Text_274630
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274470:: @ 8274470
	message Route102_Text_27468F
	waitmessage
	waitbuttonpress
	release
	end

Route102_EventScript_274479:: @ 8274479
	message Route102_Text_2746CB
	waitmessage
	waitbuttonpress
	release
	end

gUnknown_08274482:: @ 8274482

	.incbin "baserom.gba", 0x274482, 0xb

Route102_EventScript_27448D:: @ 827448D
	checkitem ITEM_WAILMER_PAIL, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route102_EventScript_2744BE
	special FieldObjectInteractionGetBerryName
	msgbox Route102_Text_2746E4, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route102_EventScript_2744C4
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route102_EventScript_2744BE

Route102_EventScript_2744BE:: @ 82744BE
	releaseall
	end

gUnknown_082744C0:: @ 82744C0

	.incbin "baserom.gba", 0x2744c0, 0x4

Route102_EventScript_2744C4:: @ 82744C4
	special FieldObjectInteractionGetBerryName
	message Route102_Text_274710
	waitmessage
	special FieldObjectInteractionWaterBerryTree
	special sub_80FAFF8
	waitstate
	message Route102_Text_274723
	waitmessage
	waitbuttonpress
	releaseall
	end

Route102_EventScript_2744DD:: @ 82744DD
	special FieldObjectInteractionPlantBerryTree
	incrementgamestat 3
	special sub_80EED10
	special FieldObjectInteractionGetBerryCountString
	message Route102_Text_274535
	waitmessage
	waitbuttonpress
	return

Route102_Text_2744F0: @ 82744F0
	.string "It’s soft, loamy soil.$"

Route102_Text_274507: @ 8274507
	.string "It’s soft, loamy soil.\n"
	.string "Want to plant a BERRY?$"

Route102_Text_274535: @ 8274535
	.string "{PLAYER} planted one {STR_VAR_1} in\n"
	.string "the soft, loamy soil.$"

Route102_Text_274560: @ 8274560
	.string "One {STR_VAR_1} was planted here.$"

Route102_Text_274579: @ 8274579
	.string "{STR_VAR_1} has sprouted.$"

Route102_Text_27458A: @ 827458A
	.string "This {STR_VAR_1} plant is growing taller.$"

Route102_Text_2745AB: @ 82745AB
	.string "These {STR_VAR_1} flowers are blooming\n"
	.string "{STR_VAR_2}.$"

Route102_Text_2745CD: @ 82745CD
	.string "very beautifully$"

Route102_Text_2745DE: @ 82745DE
	.string "cutely$"

Route102_Text_2745E5: @ 82745E5
	.string "prettily$"

Route102_Text_2745EE: @ 82745EE
	.string "You found {STR_VAR_2} {STR_VAR_1}!\p"
	.string "Do you want to pick the\n"
	.string "{STR_VAR_1}?$"

Route102_Text_27461B: @ 827461B
	.string "{PLAYER} picked the {STR_VAR_2} {STR_VAR_1}.$"

Route102_Text_274630: @ 8274630
	.string "{PLAYER} put away the {STR_VAR_1}\n"
	.string "in the BAG’s BERRIES POCKET.\p"
	.string "The soil returned to its soft and\n"
	.string "loamy state.$"

Route102_Text_27468F: @ 827468F
	.string "The BAG’s BERRIES POCKET is full.\p"
	.string "The {STR_VAR_1} couldn’t be taken.$"

Route102_Text_2746CB: @ 82746CB
	.string "{PLAYER} left the {STR_VAR_1}\n"
	.string "unpicked.$"

Route102_Text_2746E4: @ 82746E4
	.string "Want to water the {STR_VAR_1} with the\n"
	.string "WAILMER PAIL?$"

Route102_Text_274710: @ 8274710
	.string "{PLAYER} watered the {STR_VAR_1}.$"

Route102_Text_274723: @ 8274723
	.string "The plant seems to be delighted.$"

Route102_Text_274744: @ 8274744
	.string "!$"

	.incbin "baserom.gba", 0x274746, 0x15a

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

gUnknown_08274966:: @ 8274966

	.incbin "baserom.gba", 0x274966, 0x44

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

gUnknown_08274B24:: @ 8274B24

	.incbin "baserom.gba", 0x274b24, 0x48

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

gUnknown_08274D13:: @ 8274D13

	.incbin "baserom.gba", 0x274d13, 0x21

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

gUnknown_08274E75:: @ 8274E75

	.incbin "baserom.gba", 0x274e75, 0x3e

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

gUnknown_08274FFE:: @ 8274FFE

	.incbin "baserom.gba", 0x274ffe, 0x2c

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

gUnknown_082751E1:: @ 82751E1

	.incbin "baserom.gba", 0x2751e1, 0xb

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

gUnknown_08275367:: @ 8275367

	.incbin "baserom.gba", 0x275367, 0xd

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

gUnknown_082754F6:: @ 82754F6

	.incbin "baserom.gba", 0x2754f6, 0x16

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

gUnknown_082756C7:: @ 82756C7

	.incbin "baserom.gba", 0x2756c7, 0x28

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

gUnknown_082758CC:: @ 82758CC

	.incbin "baserom.gba", 0x2758cc, 0x3d

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

gUnknown_082759F1:: @ 82759F1
	.incbin "baserom.gba", 0x2759f1, 0x95

gUnknown_08275A86:: @ 8275A86
	.incbin "baserom.gba", 0x275a86, 0x59

gUnknown_08275ADF:: @ 8275ADF
	.incbin "baserom.gba", 0x275adf, 0x59

gUnknown_08275B38:: @ 8275B38

	.incbin "baserom.gba", 0x275b38, 0x49

SecretBase_RedCave1_EventScript_275B81:: @ 8275B81
	applymovement 255, SecretBase_RedCave1_Movement_275BB4
	waitmovement 0
	setvar VAR_0x4097, 1
	msgbox SecretBase_RedCave1_Text_23B759, 5
	compare_var_to_value VAR_RESULT, 1
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

gUnknown_08275BB7:: @ 8275BB7

	.incbin "baserom.gba", 0x275bb7, 0x12a

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

gUnknown_08275D0C:: @ 8275D0C

gUnknown_08275D0C:: @ 8275D0C
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	special sub_80E933C
	setvar VAR_0x4089, 1
	end

gUnknown_08275D1F:: @ 8275D1F
	.incbin "baserom.gba", 0x275d1f, 0xf

gUnknown_08275D2E:: @ 8275D2E

	.incbin "baserom.gba", 0x275d2e, 0x36

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
	compare_var_to_value VAR_0x8004, 0
	goto_eq SecretBase_RedCave1_EventScript_275DD6
	compare_var_to_value VAR_0x8004, 1
	goto_eq SecretBase_RedCave1_EventScript_275E4E
	compare_var_to_value VAR_0x8004, 2
	goto_eq SecretBase_RedCave1_EventScript_275EC6
	compare_var_to_value VAR_0x8004, 3
	goto_eq SecretBase_RedCave1_EventScript_275F3E
	compare_var_to_value VAR_0x8004, 4
	goto_eq SecretBase_RedCave1_EventScript_275FB6
	compare_var_to_value VAR_0x8004, 5
	goto_eq SecretBase_RedCave1_EventScript_27602E
	compare_var_to_value VAR_0x8004, 6
	goto_eq SecretBase_RedCave1_EventScript_2760A6
	compare_var_to_value VAR_0x8004, 7
	goto_eq SecretBase_RedCave1_EventScript_27611E
	compare_var_to_value VAR_0x8004, 8
	goto_eq SecretBase_RedCave1_EventScript_276196
	compare_var_to_value VAR_0x8004, 9
	goto_eq SecretBase_RedCave1_EventScript_27620E
	end

SecretBase_RedCave1_EventScript_275DD6:: @ 8275DD6
	lock
	faceplayer
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if 0, SecretBase_RedCave1_EventScript_275E25
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275E44
	msgbox SecretBase_RedCave1_Text_2748A0, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275E2F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275EBC
	msgbox SecretBase_RedCave1_Text_274C13, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275EA7
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275F34
	msgbox SecretBase_RedCave1_Text_274F39, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F1F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_275FAC
	msgbox SecretBase_RedCave1_Text_275287, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_275F97
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276024
	msgbox SecretBase_RedCave1_Text_2755D2, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_27600F
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27609C
	msgbox SecretBase_RedCave1_Text_274A64, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276087
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276114
	msgbox SecretBase_RedCave1_Text_274DD2, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2760FF
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27618C
	msgbox SecretBase_RedCave1_Text_275114, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276177
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_276204
	msgbox SecretBase_RedCave1_Text_275405, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_2761EF
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SecretBase_RedCave1_EventScript_27627C
	msgbox SecretBase_RedCave1_Text_2757B5, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq SecretBase_RedCave1_EventScript_276267
	setvar VAR_RESULT, 1
	special sub_80EA30C
	call SecretBase_RedCave1_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 3
	call_if 1, SecretBase_RedCave1_EventScript_2762BD
	compare_var_to_value VAR_RESULT, 1
	call_if 1, SecretBase_RedCave1_EventScript_2762C1
	compare_var_to_value VAR_RESULT, 2
	call_if 1, SecretBase_RedCave1_EventScript_2762C5
	special sp000_heal_pokemon
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

Route111_Text_2762C9: @ 82762C9
	.string "What’s that?\n"
	.string "What am I doing?\p"
	.string "I’m thinking about making my own room\n"
	.string "here using a POKéMON move.\p"
	.string "I know! I’ll give you this TM.\n"
	.string "Will you use it to make your own room?$"

Route111_Text_27636E: @ 827636E
	.string "Find a big tree that looks like it might\n"
	.string "drop some vines.\p"
	.string "Use SECRET POWER in front of the tree.\n"
	.string "Some vines should get free and drop\l"
	.string "down, so you can climb the tree.\p"
	.string "You’ll find a lot of space for putting\n"
	.string "your favorite things.\p"
	.string "It’ll be your own secret room…\n"
	.string "A SECRET BASE!\p"
	.string "You should make one, too.\p"
	.string "Another thing, you don’t always have\n"
	.string "to make your SECRET BASE in a tree.\p"
	.string "Try using SECRET POWER on rock walls\n"
	.string "that have small indents in them.\p"
	.string "I’m going to look for other places, too.\n"
	.string "Okay, bye!$"

Route111_Text_27655C: @ 827655C
	.string "Oh, you don’t want this?\n"
	.string "If you change your mind, tell me, okay?$"

Route111_Text_27659D: @ 827659D
	.string "Oh, you don’t have any room for this.\p"
	.string "I’ll hold on to it, so come back for it\n"
	.string "another time, okay?$"

Route111_EventScript_2765FF:: @ 82765FF
	lock
	faceplayer
	msgbox Route111_Text_2762C9, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route111_EventScript_27661E
	msgbox Route111_Text_27655C, 4
	release
	end

Route111_EventScript_27661E:: @ 827661E
	giveitem_std ITEM_TM43
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_276680
	msgbox Route111_Text_27636E, 4
	closemessage
	setflag FLAG_0x060
	clearflag FLAG_0x3B4
	compare_var_to_value VAR_FACING, 3
	call_if 1, Route111_EventScript_27666A
	compare_var_to_value VAR_FACING, 4
	call_if 1, Route111_EventScript_27666A
	compare_var_to_value VAR_FACING, 2
	call_if 1, Route111_EventScript_276675
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_27666A:: @ 827666A
	applymovement VAR_LAST_TALKED, Route111_Movement_27668A
	waitmovement 0
	return

Route111_EventScript_276675:: @ 8276675
	applymovement VAR_LAST_TALKED, Route111_Movement_276696
	waitmovement 0
	return

Route111_EventScript_276680:: @ 8276680
	msgbox Route111_Text_27659D, 4
	release
	end

Route111_Movement_27668A: @ 827668A
	step_down
	step_down
	step_down
	step_down
	step_down
	step_left
	step_left
	step_left
	step_left
	step_down
	step_down
	step_end

Route111_Movement_276696: @ 8276696
	step_left
	step_down
	step_down
	step_down
	step_down
	step_down
	step_left
	step_left
	step_left
	step_down
	step_down
	step_end

gUnknown_082766A2:: @ 82766A2
	.incbin "baserom.gba", 0x2766a2, 0x4

gUnknown_082766A6:: @ 82766A6


	.incbin "baserom.gba", 0x2766a6, 0x4

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

	.incbin "baserom.gba", 0x276a3d, 0x92

BattleFrontier_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
DewfordTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
EverGrandeCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
EverGrandeCity_PokemonLeague_2F_MapScript1_276ACF: @ 8276ACF
FallarborTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
FortreeCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
LavaridgeTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
LilycoveCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
MauvilleCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
MossdeepCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
OldaleTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
PacifidlogTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
PetalburgCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
RustboroCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
SlateportCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
SootopolisCity_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
VerdanturfTown_PokemonCenter_2F_MapScript1_276ACF: @ 8276ACF
	call OldaleTown_PokemonCenter_2F_EventScript_276AD5
	end

OldaleTown_PokemonCenter_2F_EventScript_276AD5:: @ 8276AD5
	specialvar VAR_RESULT, sub_813B514
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276AFB
	specialvar VAR_RESULT, sub_801B27C
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276AFF
	goto OldaleTown_PokemonCenter_2F_EventScript_276AFB
	end

OldaleTown_PokemonCenter_2F_EventScript_276AFB:: @ 8276AFB
	clearflag FLAG_0x2BE
	return

OldaleTown_PokemonCenter_2F_EventScript_276AFF:: @ 8276AFF
	setflag FLAG_0x2BE
	return

BattleFrontier_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
DewfordTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
EverGrandeCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
EverGrandeCity_PokemonLeague_2F_EventScript_276B03:: @ 8276B03
FallarborTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
FortreeCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
LavaridgeTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
LilycoveCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
MauvilleCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
MossdeepCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
OldaleTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
PacifidlogTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
PetalburgCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
RustboroCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
SlateportCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
SootopolisCity_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
VerdanturfTown_PokemonCenter_2F_EventScript_276B03:: @ 8276B03
	specialvar VAR_RESULT, sub_813B514
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276B23
	goto OldaleTown_PokemonCenter_2F_EventScript_276B19
	end

OldaleTown_PokemonCenter_2F_EventScript_276B19:: @ 8276B19
	execram

	.incbin "baserom.gba", 0x276b1a, 0x9

OldaleTown_PokemonCenter_2F_EventScript_276B23:: @ 8276B23
	checkitem ITEM_EON_TICKET, 1
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276B19
	checkflag FLAG_SYS_HAS_EON_TICKET
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276B19
	msgbox gUnknown_08273594, 4
	giveitem_std ITEM_EON_TICKET
	setflag FLAG_SYS_HAS_EON_TICKET
	setvar VAR_0x403F, 0
	msgbox gUnknown_082735F2, 4
	release
	end

	.incbin "baserom.gba", 0x276b62, 0xa

BattleFrontier_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
DewfordTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
EverGrandeCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
EverGrandeCity_PokemonLeague_2F_MapScript2_276B6C: @ 8276B6C
FallarborTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
FortreeCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
LavaridgeTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
LilycoveCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
MauvilleCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
MossdeepCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
OldaleTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
PacifidlogTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
PetalburgCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
RustboroCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
SlateportCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
SootopolisCity_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
VerdanturfTown_PokemonCenter_2F_MapScript2_276B6C: @ 8276B6C
	map_script_2 VAR_0x4087, 1, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 2, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 5, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 3, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 4, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 6, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 7, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	map_script_2 VAR_0x4087, 8, OldaleTown_PokemonCenter_2F_EventScript_276BAE
	.2byte 0

MossdeepCity_GameCorner_1F_EventScript_276BAE:: @ 8276BAE
OldaleTown_PokemonCenter_2F_EventScript_276BAE:: @ 8276BAE
	compare_var_to_value VAR_0x8007, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276BBD
	turnobject VAR_0x8007, 3

OldaleTown_PokemonCenter_2F_EventScript_276BBD:: @ 8276BBD
	end

BattleFrontier_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
DewfordTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
EverGrandeCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
EverGrandeCity_PokemonLeague_2F_MapScript1_276BBE: @ 8276BBE
FallarborTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
FortreeCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
LavaridgeTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
LilycoveCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
MauvilleCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
MossdeepCity_GameCorner_1F_MapScript1_276BBE: @ 8276BBE
MossdeepCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
OldaleTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
PacifidlogTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
PetalburgCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
RustboroCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
SlateportCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
SootopolisCity_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
VerdanturfTown_PokemonCenter_2F_MapScript1_276BBE: @ 8276BBE
	compare_var_to_value VAR_0x4087, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare_var_to_value VAR_0x4087, 2
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare_var_to_value VAR_0x4087, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C17
	compare_var_to_value VAR_0x4087, 3
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C1D
	compare_var_to_value VAR_0x4087, 4
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C23
	compare_var_to_value VAR_0x4087, 6
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C29
	compare_var_to_value VAR_0x4087, 7
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C2F
	compare_var_to_value VAR_0x4087, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276C35
	end

OldaleTown_PokemonCenter_2F_EventScript_276C17:: @ 8276C17
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C1D:: @ 8276C1D
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C23:: @ 8276C23
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C29:: @ 8276C29
	call OldaleTown_PokemonCenter_2F_EventScript_277BBE
	end

OldaleTown_PokemonCenter_2F_EventScript_276C2F:: @ 8276C2F
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	end

OldaleTown_PokemonCenter_2F_EventScript_276C35:: @ 8276C35
	call OldaleTown_PokemonCenter_2F_EventScript_277C0A
	end

BattleFrontier_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
DewfordTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
EverGrandeCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
EverGrandeCity_PokemonLeague_2F_MapScript2_276C3B: @ 8276C3B
FallarborTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
FortreeCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
LavaridgeTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
LilycoveCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
MauvilleCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
MossdeepCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
OldaleTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
PacifidlogTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
PetalburgCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
RustboroCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
SlateportCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
SootopolisCity_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
VerdanturfTown_PokemonCenter_2F_MapScript2_276C3B: @ 8276C3B
	map_script_2 VAR_0x40CD, 1, OldaleTown_PokemonCenter_2F_EventScript_276DE0
	map_script_2 VAR_0x4087, 1, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_0x4087, 2, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_0x4087, 5, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_0x4087, 3, OldaleTown_PokemonCenter_2F_EventScript_276CE7
	map_script_2 VAR_0x4087, 4, OldaleTown_PokemonCenter_2F_EventScript_276D2C
	map_script_2 VAR_0x4087, 6, OldaleTown_PokemonCenter_2F_EventScript_276D6C
	map_script_2 VAR_0x4087, 7, OldaleTown_PokemonCenter_2F_EventScript_276C85
	map_script_2 VAR_0x4087, 8, OldaleTown_PokemonCenter_2F_EventScript_276C9D
	.2byte 0

OldaleTown_PokemonCenter_2F_EventScript_276C85:: @ 8276C85
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CB5
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_276C9D:: @ 8276C9D
OldaleTown_PokemonCenter_2F_EventScript_276C9D:: @ 8276C9D
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CB5
	call OldaleTown_PokemonCenter_2F_EventScript_277C1D
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276CB5:: @ 8276CB5
	special sub_80097E8
	setvar VAR_0x4087, 0
	compare_var_to_value VAR_0x8007, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276CE7:: @ 8276CE7
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276CFF
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276CFF:: @ 8276CFF
	special sub_80097E8
	setvar VAR_0x4087, 0
	compare_var_to_value VAR_0x8007, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735E
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	call OldaleTown_PokemonCenter_2F_EventScript_276DAE
	return

OldaleTown_PokemonCenter_2F_EventScript_276D2C:: @ 8276D2C
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276D44
	call OldaleTown_PokemonCenter_2F_EventScript_277BF7
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276D44:: @ 8276D44
	special sub_80097E8
	setvar VAR_0x4087, 0
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	compare_var_to_value VAR_0x8007, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276D6B
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0

OldaleTown_PokemonCenter_2F_EventScript_276D6B:: @ 8276D6B
	return

OldaleTown_PokemonCenter_2F_EventScript_276D6C:: @ 8276D6C
	lockall
	call OldaleTown_PokemonCenter_2F_EventScript_276D84
	call OldaleTown_PokemonCenter_2F_EventScript_277BD1
	special DrawWholeMapView
	playse SE_TK_KASYA
	erasebox 0, 0, 29, 19
	releaseall
	end

OldaleTown_PokemonCenter_2F_EventScript_276D84:: @ 8276D84
	setvar VAR_0x4087, 0
	compare_var_to_value VAR_0x8007, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276DD5
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735E
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	call OldaleTown_PokemonCenter_2F_EventScript_276DAE
	return

OldaleTown_PokemonCenter_2F_EventScript_276DAE:: @ 8276DAE
	message OldaleTown_PokemonCenter_2F_Text_278521
	waitmessage
	playse SE_PIN
	delay 60
	message OldaleTown_PokemonCenter_2F_Text_27854C
	waitmessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	applymovement VAR_0x8007, OldaleTown_PokemonCenter_2F_Movement_277349
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276DD5:: @ 8276DD5
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27734F
	waitmovement 0
	return

OldaleTown_PokemonCenter_2F_EventScript_276DE0:: @ 8276DE0
	lockall
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_2725A6
	waitmovement 0
	msgbox OldaleTown_PokemonCenter_2F_Text_27964A, 4
	closemessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_276E10
	waitmovement 0
	delay 30
	msgbox OldaleTown_PokemonCenter_2F_Text_279718, 4
	setvar VAR_0x40CD, 2
	releaseall
	end

OldaleTown_PokemonCenter_2F_Movement_276E10: @ 8276E10
	step_up
	step_up
	step_end

OldaleTown_PokemonCenter_2F_EventScript_276E13:: @ 8276E13
	message OldaleTown_PokemonCenter_2F_Text_277EA4
	waitmessage
	delay 28
	goto OldaleTown_PokemonCenter_2F_EventScript_276E30
	end

	.incbin "baserom.gba", 0x276e22, 0xe

OldaleTown_PokemonCenter_2F_EventScript_276E30:: @ 8276E30
	setvar VAR_0x8004, 0
	checkflag FLAG_VISITED_MAUVILLE_CITY
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276E75
	multichoice 0, 0, 74, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2770B2
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276EB7
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276E75:: @ 8276E75
	multichoice 0, 0, 76, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2770B2
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276EB7
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2771DB
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276EB7:: @ 8276EB7
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276EC2:: @ 8276EC2
	message OldaleTown_PokemonCenter_2F_Text_2790BE
	waitmessage
	multichoice 0, 0, 18, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_276F23
	case 1, OldaleTown_PokemonCenter_2F_EventScript_276F2E
	case 2, OldaleTown_PokemonCenter_2F_EventScript_276F55
	case 3, OldaleTown_PokemonCenter_2F_EventScript_276F15
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_276F15:: @ 8276F15
	msgbox OldaleTown_PokemonCenter_2F_Text_279142, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276F23:: @ 8276F23
	setvar VAR_0x8004, 1
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F2E:: @ 8276F2E
	special sub_80F92F8
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, OldaleTown_PokemonCenter_2F_EventScript_276F47
	setvar VAR_0x8004, 2
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F47:: @ 8276F47
	msgbox OldaleTown_PokemonCenter_2F_Text_277FEE, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_276EC2
	end

OldaleTown_PokemonCenter_2F_EventScript_276F55:: @ 8276F55
	setvar VAR_0x8004, 5
	goto OldaleTown_PokemonCenter_2F_EventScript_276F60
	end

OldaleTown_PokemonCenter_2F_EventScript_276F60:: @ 8276F60
	call OldaleTown_PokemonCenter_2F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gUnknown_08278091
	waitmessage
	special sub_80B2DA4
	waitstate
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276FBD
	compare_var_to_value VAR_RESULT, 2
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare_var_to_value VAR_RESULT, 3
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare_var_to_value VAR_RESULT, 4
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277046
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare_var_to_value VAR_RESULT, 6
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	end

OldaleTown_PokemonCenter_2F_EventScript_276FBD:: @ 8276FBD
	special sp000_heal_pokemon
	special copy_player_party_to_sav1
	special copy_bags_and_unk_data_from_save_blocks
	copyvar VAR_0x4087, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	compare_var_to_value VAR_0x8004, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277036
	special sub_809D2BC
	warp SINGLE_BATTLE_COLOSSEUM, 255, 6, 8
	special sub_80AF948
	waitstate
	end

	.incbin "baserom.gba", 0x27702b, 0xb

OldaleTown_PokemonCenter_2F_EventScript_277036:: @ 8277036
	special sub_809D2BC
	warp DOUBLE_BATTLE_COLOSSEUM, 255, 5, 8
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277046:: @ 8277046
	switch VAR_0x8004
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277094
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277083
	case 5, OldaleTown_PokemonCenter_2F_EventScript_277072
	goto OldaleTown_PokemonCenter_2F_EventScript_27730E
	end

OldaleTown_PokemonCenter_2F_EventScript_277072:: @ 8277072
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_27833D, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_277083:: @ 8277083
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278307, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_277094:: @ 8277094
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_2782D1, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_2770A5
	end

OldaleTown_PokemonCenter_2F_EventScript_2770A5:: @ 82770A5
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278372, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2770B2:: @ 82770B2
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call OldaleTown_PokemonCenter_2F_EventScript_277199
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call OldaleTown_PokemonCenter_2F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gUnknown_08278091
	waitmessage
	special sub_80B2E4C
	waitstate
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27713A
	compare_var_to_value VAR_RESULT, 2
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare_var_to_value VAR_RESULT, 3
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare_var_to_value VAR_RESULT, 4
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27730E
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare_var_to_value VAR_RESULT, 6
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	compare_var_to_value VAR_RESULT, 7
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772AB
	compare_var_to_value VAR_RESULT, 9
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772B8
	end

OldaleTown_PokemonCenter_2F_EventScript_27713A:: @ 827713A
	setvar VAR_0x8004, 3
	copyvar VAR_0x4087, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special sub_809D2BC
	setwarp TRADE_CENTER, 255, 5, 8
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277199:: @ 8277199
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare_var_to_value VAR_RESULT, 2
	goto_if 0, OldaleTown_PokemonCenter_2F_EventScript_2771BF
	specialvar VAR_RESULT, sub_80F9370
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2771CD
	setvar VAR_RESULT, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_2771BF:: @ 82771BF
	msgbox OldaleTown_PokemonCenter_2F_Text_278027, 4
	setvar VAR_RESULT, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_2771CD:: @ 82771CD
	msgbox OldaleTown_PokemonCenter_2F_Text_278061, 4
	setvar VAR_RESULT, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_2771DB:: @ 82771DB
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call OldaleTown_PokemonCenter_2F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	message gUnknown_08278091
	waitmessage
	special sub_80B2E74
	waitstate
	special sub_80B2EA8
	waitstate
	compare_var_to_value VAR_RESULT, 12
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277328
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27724C
	compare_var_to_value VAR_RESULT, 2
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772D2
	compare_var_to_value VAR_RESULT, 3
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772DF
	compare_var_to_value VAR_RESULT, 4
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27730E
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	compare_var_to_value VAR_RESULT, 6
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772C5
	end

OldaleTown_PokemonCenter_2F_EventScript_27724C:: @ 827724C
	setvar VAR_0x8004, 4
	copyvar VAR_0x4087, VAR_0x8004
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_278197
	waitmessage
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	special sub_809D2BC
	setwarp RECORD_CORNER, 255, 8, 9
	special sub_80AF948
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_2772AB:: @ 82772AB
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278565, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772B8:: @ 82772B8
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_2785C9, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_2772C5:: @ 82772C5
OldaleTown_PokemonCenter_2F_EventScript_2772C5:: @ 82772C5
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_27821C, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_2772D2:: @ 82772D2
OldaleTown_PokemonCenter_2F_EventScript_2772D2:: @ 82772D2
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_2781C7, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772DF:: @ 82772DF
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278255, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_2772EC:: @ 82772EC
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278291, 4
	release
	end

MossdeepCity_GameCorner_1F_EventScript_2772F9:: @ 82772F9
	special sub_80097E8
	msgbox MossdeepCity_GameCorner_1F_Text_278D51, 4
	release
	end

	.incbin "baserom.gba", 0x277306, 0x8

OldaleTown_PokemonCenter_2F_EventScript_27730E:: @ 827730E
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_2782A8, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_27731B:: @ 827731B
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_2785E9, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_277328:: @ 8277328
	special sub_80097E8
	msgbox OldaleTown_PokemonCenter_2F_Text_278651, 4
	release
	end

OldaleTown_PokemonCenter_2F_EventScript_277335:: @ 8277335
	msgbox gUnknown_0827306F, 4
	release
	end

	.incbin "baserom.gba", 0x27733f, 0xa

OldaleTown_PokemonCenter_2F_Movement_277349: @ 8277349
	step_00
	step_end

	.incbin "baserom.gba", 0x27734b, 0x2

MossdeepCity_GameCorner_1F_Movement_27734D: @ 827734D
OldaleTown_PokemonCenter_2F_Movement_27734D: @ 827734D
	step_02
	step_end

OldaleTown_PokemonCenter_2F_Movement_27734F: @ 827734F
	step_down
	step_down
	step_end

	.incbin "baserom.gba", 0x277352, 0x4

OldaleTown_PokemonCenter_2F_Movement_277356: @ 8277356
	step_left
	step_up
	step_up
	step_end

OldaleTown_PokemonCenter_2F_Movement_27735A: @ 827735A
	step_up
	step_end

	.incbin "baserom.gba", 0x27735c, 0x2

OldaleTown_PokemonCenter_2F_Movement_27735E: @ 827735E
	step_03
	step_end

MossdeepCity_GameCorner_1F_Movement_277360: @ 8277360
	step_left
	step_up
	step_up
	step_up
	step_end

gUnknown_08277365:: @ 8277365
	.incbin "baserom.gba", 0x277365, 0xf

gUnknown_08277374:: @ 8277374

gUnknown_08277374:: @ 8277374
	setvar VAR_0x8005, 0
	special sub_80B3968
	waitstate
	end

gUnknown_0827737E:: @ 827737E

gUnknown_0827737E:: @ 827737E
	setvar VAR_0x8005, 1
	special sub_80B3968
	waitstate
	end

gUnknown_08277388:: @ 8277388

gUnknown_08277388:: @ 8277388
	fadescreen 1
	special sub_80F9438
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq DoubleBattleColosseum_EventScript_2773F4
	setvar VAR_0x8005, 0
	special sub_80B3968
	waitstate
	end

gUnknown_082773A3:: @ 82773A3

gUnknown_082773A3:: @ 82773A3
	fadescreen 1
	special sub_80F9438
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq DoubleBattleColosseum_EventScript_2773F4
	setvar VAR_0x8005, 1
	special sub_80B3968
	waitstate
	end

gUnknown_082773BE:: @ 82773BE

gUnknown_082773BE:: @ 82773BE
	fadescreen 1
	special sub_80F9438
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq DoubleBattleColosseum_EventScript_2773F4
	setvar VAR_0x8005, 2
	special sub_80B3968
	waitstate
	end

gUnknown_082773D9:: @ 82773D9

gUnknown_082773D9:: @ 82773D9
	fadescreen 1
	special sub_80F9438
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq DoubleBattleColosseum_EventScript_2773F4
	setvar VAR_0x8005, 3
	special sub_80B3968
	waitstate
	end

DoubleBattleColosseum_EventScript_2773F4:: @ 82773F4
	end

gUnknown_082773F5:: @ 82773F5

gUnknown_082773F5:: @ 82773F5
	setvar VAR_0x8005, 0
	special sub_80B3924
	waitstate
	end

gUnknown_082773FF:: @ 82773FF

gUnknown_082773FF:: @ 82773FF
	setvar VAR_0x8005, 1
	special sub_80B3924
	waitstate
	end

	.incbin "baserom.gba", 0x277409, 0x14

gUnknown_0827741D:: @ 827741D

gUnknown_0827741D:: @ 827741D
	setvar VAR_0x8005, 0
	special sub_80E6BE8
	waitstate
	compare_var_to_value VAR_0x4001, 0
	goto_if 5, RecordCorner_EventScript_277471
	end

gUnknown_08277432:: @ 8277432

gUnknown_08277432:: @ 8277432
	setvar VAR_0x8005, 1
	special sub_80E6BE8
	waitstate
	compare_var_to_value VAR_0x4001, 0
	goto_if 5, RecordCorner_EventScript_277471
	end

gUnknown_08277447:: @ 8277447

gUnknown_08277447:: @ 8277447
	setvar VAR_0x8005, 2
	special sub_80E6BE8
	waitstate
	compare_var_to_value VAR_0x4001, 0
	goto_if 5, RecordCorner_EventScript_277471
	end

gUnknown_0827745C:: @ 827745C

gUnknown_0827745C:: @ 827745C
	setvar VAR_0x8005, 3
	special sub_80E6BE8
	waitstate
	compare_var_to_value VAR_0x4001, 0
	goto_if 5, RecordCorner_EventScript_277471
	end

RecordCorner_EventScript_277471:: @ 8277471
	bufferitemname 1, VAR_0x4001
	message RecordCorner_Text_27863C
	waitmessage
	waitbuttonpress
	releaseall
	end

gUnknown_0827747E:: @ 827747E
	.incbin "baserom.gba", 0x27747e, 0xf

gUnknown_0827748D:: @ 827748D
	.incbin "baserom.gba", 0x27748d, 0xf

gUnknown_0827749C:: @ 827749C

	.incbin "baserom.gba", 0x27749c, 0xa

SingleBattleColosseum_EventScript_2774A6:: @ 82774A6
	special sub_8098574
	msgbox SingleBattleColosseum_Text_2784B4, 4
	special sub_809859C
	closemessage
	end

TradeCenter_EventScript_2774B6:: @ 82774B6
	special sub_8098574
	msgbox TradeCenter_Text_2784E2, 4
	special sub_809859C
	closemessage
	end

RecordCorner_EventScript_2774C6:: @ 82774C6
	compare_var_to_value VAR_0x4000, 0
	goto_if 5, RecordCorner_EventScript_2774E0
	special sub_8098574
	message RecordCorner_Text_27861C
	waitmessage
	waitbuttonpress
	special sub_809859C
	closemessage
	end

RecordCorner_EventScript_2774E0:: @ 82774E0
	special sub_8098574
	message RecordCorner_Text_27850E
	waitmessage
	waitbuttonpress
	special sub_809859C
	closemessage
	end

gUnknown_082774EF:: @ 82774EF
	.incbin "baserom.gba", 0x2774ef, 0x1a

gUnknown_08277509:: @ 8277509
	.incbin "baserom.gba", 0x277509, 0xa

gUnknown_08277513:: @ 8277513

	.incbin "baserom.gba", 0x277513, 0x8

OldaleTown_PokemonCenter_2F_EventScript_27751B:: @ 827751B
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 8
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if 0, OldaleTown_PokemonCenter_2F_EventScript_277335
	specialvar VAR_RESULT, sub_813990C
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27731B
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, sub_80093CC
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277668
	message OldaleTown_PokemonCenter_2F_Text_27940D
	waitmessage
	goto OldaleTown_PokemonCenter_2F_EventScript_27755C
	end

OldaleTown_PokemonCenter_2F_EventScript_27755C:: @ 827755C
	multichoice 17, 6, 17, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27759F
	case 1, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277593
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277593:: @ 8277593
	message OldaleTown_PokemonCenter_2F_Text_2794B8
	waitmessage
	goto OldaleTown_PokemonCenter_2F_EventScript_27755C
	end

OldaleTown_PokemonCenter_2F_EventScript_27759F:: @ 827759F
	call OldaleTown_PokemonCenter_2F_EventScript_277626
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call OldaleTown_PokemonCenter_2F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	msgbox OldaleTown_PokemonCenter_2F_Text_27961C, 4
	closemessage
	special sp000_heal_pokemon
	setvar VAR_0x8004, 6
	copyvar VAR_0x4087, VAR_0x8004
	call OldaleTown_PokemonCenter_2F_EventScript_277BBE
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	closedoor 5, 1
	waitdooranim
	special sub_8018090
	special sub_809D2BC
	warpteleport2 UNION_ROOM, 255, 7, 11
	waitstate
	special UnionRoomSpecial
	waitstate
	end

OldaleTown_PokemonCenter_2F_EventScript_277626:: @ 8277626
	specialvar VAR_RESULT, sub_80C7008
	compare_var_to_value VAR_RESULT, 2
	goto_if 0, OldaleTown_PokemonCenter_2F_EventScript_27764C
	specialvar VAR_RESULT, sub_80F9370
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27765A
	setvar VAR_RESULT, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_27764C:: @ 827764C
	msgbox OldaleTown_PokemonCenter_2F_Text_27893E, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_273755
	end

OldaleTown_PokemonCenter_2F_EventScript_27765A:: @ 827765A
	msgbox OldaleTown_PokemonCenter_2F_Text_27897B, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_273755
	end

OldaleTown_PokemonCenter_2F_EventScript_277668:: @ 8277668
	msgbox OldaleTown_PokemonCenter_2F_Text_2789B5, 4
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277672:: @ 8277672
	lock
	faceplayer
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if 0, OldaleTown_PokemonCenter_2F_EventScript_277335
	msgbox OldaleTown_PokemonCenter_2F_Text_279937, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27769A
	msgbox OldaleTown_PokemonCenter_2F_Text_2799AA, 4
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_27769A:: @ 827769A
	msgbox OldaleTown_PokemonCenter_2F_Text_279C91, 4
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_2776A4:: @ 82776A4
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, 9
	checkflag FLAG_SYS_POKEDEX_GET
	goto_if 0, OldaleTown_PokemonCenter_2F_EventScript_277335
	specialvar VAR_RESULT, sub_813990C
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27731B
	specialvar VAR_RESULT, sub_80093CC
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_276E13
	message OldaleTown_PokemonCenter_2F_Text_279013
	waitmessage
	delay 28
	goto OldaleTown_PokemonCenter_2F_EventScript_2776E3
	end

OldaleTown_PokemonCenter_2F_EventScript_2776E3:: @ 82776E3
	checkitem ITEM_POWDER_JAR, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27778B
	checkflag FLAG_VISITED_MAUVILLE_CITY
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_27773E
	multichoice 0, 0, 78, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778F7
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27773E:: @ 827773E
	multichoice 0, 0, 79, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778D9
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2778F7
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27778B:: @ 827778B
	checkflag FLAG_VISITED_MAUVILLE_CITY
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2777CB
	multichoice 0, 0, 75, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_2777CB:: @ 82777CB
	multichoice 0, 0, 77, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27780D
	case 1, OldaleTown_PokemonCenter_2F_EventScript_27783B
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778D9
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27780D:: @ 827780D
	msgbox OldaleTown_PokemonCenter_2F_Text_27909D, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	call OldaleTown_PokemonCenter_2F_EventScript_277199
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	setvar VAR_0x8004, 3
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_27783B:: @ 827783B
	message OldaleTown_PokemonCenter_2F_Text_2790BE
	waitmessage
	multichoice 0, 0, 18, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_27788E
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277899
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2778C0
	case 3, OldaleTown_PokemonCenter_2F_EventScript_2778CB
	case 4, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_27788E:: @ 827788E
	setvar VAR_0x8004, 0
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_277899:: @ 8277899
	special sub_80F92F8
	compare_var_to_value VAR_RESULT, 0
	goto_if 5, OldaleTown_PokemonCenter_2F_EventScript_2778B2
	setvar VAR_0x8004, 1
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778B2:: @ 82778B2
	msgbox OldaleTown_PokemonCenter_2F_Text_277FEE, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_27783B
	end

OldaleTown_PokemonCenter_2F_EventScript_2778C0:: @ 82778C0
	setvar VAR_0x8004, 2
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778CB:: @ 82778CB
	msgbox OldaleTown_PokemonCenter_2F_Text_279142, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_27783B
	end

OldaleTown_PokemonCenter_2F_EventScript_2778D9:: @ 82778D9
	msgbox OldaleTown_PokemonCenter_2F_Text_2790E8, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	setvar VAR_0x8004, 12
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_2778F7:: @ 82778F7
	msgbox OldaleTown_PokemonCenter_2F_Text_279114, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	special HasAtLeastOneBerry
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277923
	setvar VAR_0x8004, 5
	goto OldaleTown_PokemonCenter_2F_EventScript_277931
	end

OldaleTown_PokemonCenter_2F_EventScript_277923:: @ 8277923
	msgbox OldaleTown_PokemonCenter_2F_Text_2788FC, 4
	goto OldaleTown_PokemonCenter_2F_EventScript_2776E3
	end

OldaleTown_PokemonCenter_2F_EventScript_277931:: @ 8277931
	call OldaleTown_PokemonCenter_2F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2772EC
	switch VAR_0x8004
	case 3, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277989
	case 2, OldaleTown_PokemonCenter_2F_EventScript_277A16
	case 5, OldaleTown_PokemonCenter_2F_EventScript_277AA3
	case 12, OldaleTown_PokemonCenter_2F_EventScript_277AA3
	end

OldaleTown_PokemonCenter_2F_EventScript_277989:: @ 8277989
	message OldaleTown_PokemonCenter_2F_Text_2792CD
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_2779EE
	case 1, OldaleTown_PokemonCenter_2F_EventScript_2779C6
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_2779C6:: @ 82779C6
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277989
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2779C6
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_2779EE:: @ 82779EE
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277989
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_2779EE
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277A16:: @ 8277A16
	message OldaleTown_PokemonCenter_2F_Text_279334
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277A7B
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277A53
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277A53:: @ 8277A53
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277A16
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277A53
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277A7B:: @ 8277A7B
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277A16
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277A7B
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277AA3:: @ 8277AA3
	message OldaleTown_PokemonCenter_2F_Text_2793A3
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, OldaleTown_PokemonCenter_2F_EventScript_277B08
	case 1, OldaleTown_PokemonCenter_2F_EventScript_277AE0
	case 2, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	case 127, OldaleTown_PokemonCenter_2F_EventScript_2772EC
	end

OldaleTown_PokemonCenter_2F_EventScript_277AE0:: @ 8277AE0
	call OldaleTown_PokemonCenter_2F_EventScript_277B30
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277AA3
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277AE0
	release
	return

OldaleTown_PokemonCenter_2F_EventScript_277B08:: @ 8277B08
	call OldaleTown_PokemonCenter_2F_EventScript_277B35
	compare_var_to_value VAR_RESULT, 1
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B3A
	compare_var_to_value VAR_RESULT, 5
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277AA3
	compare_var_to_value VAR_RESULT, 8
	goto_eq OldaleTown_PokemonCenter_2F_EventScript_277B08
	release
	return

BattleFrontier_BattleTowerLobby_EventScript_277B30:: @ 8277B30
MossdeepCity_GameCorner_1F_EventScript_277B30:: @ 8277B30
OldaleTown_PokemonCenter_2F_EventScript_277B30:: @ 8277B30
	special BerryBlenderLinkBecomeLeader
	waitstate
	return

BattleFrontier_BattleTowerLobby_EventScript_277B35:: @ 8277B35
MossdeepCity_GameCorner_1F_EventScript_277B35:: @ 8277B35
OldaleTown_PokemonCenter_2F_EventScript_277B35:: @ 8277B35
	special BerryBlenderLinkJoinGroup
	waitstate
	return

OldaleTown_PokemonCenter_2F_EventScript_277B3A:: @ 8277B3A
	messageautoscroll OldaleTown_PokemonCenter_2F_Text_2781A5
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call OldaleTown_PokemonCenter_2F_EventScript_277BE4
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, OldaleTown_PokemonCenter_2F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_277356
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement 255, OldaleTown_PokemonCenter_2F_Movement_27735A
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

gUnknown_08277B8A:: @ 8277B8A

	.incbin "baserom.gba", 0x277b8a, 0x34

OldaleTown_PokemonCenter_2F_EventScript_277BBE:: @ 8277BBE
	setmetatile 5, 2, 732, 0
	setmetatile 5, 3, 740, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277BD1:: @ 8277BD1
	setmetatile 5, 2, 542, 1
	setmetatile 5, 3, 605, 1
	return

OldaleTown_PokemonCenter_2F_EventScript_277BE4:: @ 8277BE4
	setmetatile 9, 2, 732, 0
	setmetatile 9, 3, 740, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277BF7:: @ 8277BF7
	setmetatile 9, 2, 542, 1
	setmetatile 9, 3, 605, 1
	return

MossdeepCity_GameCorner_1F_EventScript_277C0A:: @ 8277C0A
OldaleTown_PokemonCenter_2F_EventScript_277C0A:: @ 8277C0A
	setmetatile 5, 2, 556, 0
	setmetatile 5, 3, 564, 0
	return

OldaleTown_PokemonCenter_2F_EventScript_277C1D:: @ 8277C1D
	setmetatile 5, 2, 554, 1
	setmetatile 5, 3, 562, 1
	return

BattleFrontier_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
DewfordTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
EverGrandeCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
EverGrandeCity_PokemonLeague_1F_MapScript1_277C30: @ 8277C30
FallarborTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
FortreeCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
LavaridgeTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
LilycoveCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
MauvilleCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
MossdeepCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
OldaleTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
PacifidlogTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
PetalburgCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
RustboroCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
SlateportCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
SootopolisCity_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
VerdanturfTown_PokemonCenter_1F_MapScript1_277C30: @ 8277C30
	special sub_8016934
	end

MossdeepCity_GameCorner_1F_EventScript_277C34:: @ 8277C34
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_278A7D
	waitmessage
	multichoice 0, 0, 80, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277C73
	case 1, MossdeepCity_GameCorner_1F_EventScript_277C7D
	case 2, MossdeepCity_GameCorner_1F_EventScript_277C87
	case 127, MossdeepCity_GameCorner_1F_EventScript_277C87
	end

MossdeepCity_GameCorner_1F_EventScript_277C73:: @ 8277C73
	msgbox MossdeepCity_GameCorner_1F_Text_278ACB, 4
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C7D:: @ 8277C7D
	msgbox MossdeepCity_GameCorner_1F_Text_278BF1, 4
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C87:: @ 8277C87
	msgbox MossdeepCity_GameCorner_1F_Text_278CAC, 4
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277C91:: @ 8277C91
	lock
	faceplayer
	message MossdeepCity_GameCorner_1F_Text_278CEB
	waitmessage
	specialvar VAR_RESULT, sub_80093CC
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277E48
	delay 60
	message MossdeepCity_GameCorner_1F_Text_278DAD
	waitmessage
	multichoice 0, 0, 80, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277CE9
	case 1, MossdeepCity_GameCorner_1F_EventScript_277D35
	case 2, MossdeepCity_GameCorner_1F_EventScript_2772F9
	case 127, MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277CE9:: @ 8277CE9
	setvar VAR_0x8005, 0
	special sub_802C920
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278DD9, 4
	fadescreen 1
	setvar VAR_0x8005, 0
	special sub_81B8958
	waitstate
	compare_var_to_value VAR_0x8004, 6
	goto_if 4, MossdeepCity_GameCorner_1F_EventScript_2772F9
	call MossdeepCity_GameCorner_1F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	setvar VAR_0x8004, 4
	goto MossdeepCity_GameCorner_1F_EventScript_277D81
	end

MossdeepCity_GameCorner_1F_EventScript_277D35:: @ 8277D35
	setvar VAR_0x8005, 1
	special sub_8027A5C
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278DD9, 4
	fadescreen 1
	setvar VAR_0x8005, 1
	special sub_81B8958
	waitstate
	compare_var_to_value VAR_0x8004, 6
	goto_if 4, MossdeepCity_GameCorner_1F_EventScript_2772F9
	call MossdeepCity_GameCorner_1F_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	setvar VAR_0x8004, 6
	goto MossdeepCity_GameCorner_1F_EventScript_277D81
	end

MossdeepCity_GameCorner_1F_EventScript_277D81:: @ 8277D81
	message MossdeepCity_GameCorner_1F_Text_2793A3
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, MossdeepCity_GameCorner_1F_EventScript_277DE6
	case 1, MossdeepCity_GameCorner_1F_EventScript_277DBE
	case 2, MossdeepCity_GameCorner_1F_EventScript_2772F9
	case 127, MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277DBE:: @ 8277DBE
	call MossdeepCity_GameCorner_1F_EventScript_277B30
	compare_var_to_value VAR_RESULT, 1
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277E0E
	compare_var_to_value VAR_RESULT, 5
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277D81
	compare_var_to_value VAR_RESULT, 8
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277DBE
	release
	return

MossdeepCity_GameCorner_1F_EventScript_277DE6:: @ 8277DE6
	call MossdeepCity_GameCorner_1F_EventScript_277B35
	compare_var_to_value VAR_RESULT, 1
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277E0E
	compare_var_to_value VAR_RESULT, 5
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277D81
	compare_var_to_value VAR_RESULT, 8
	goto_eq MossdeepCity_GameCorner_1F_EventScript_277DE6
	release
	return

MossdeepCity_GameCorner_1F_EventScript_277E0E:: @ 8277E0E
	messageautoscroll MossdeepCity_GameCorner_1F_Text_278E00
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call MossdeepCity_GameCorner_1F_EventScript_277C0A
	special DrawWholeMapView
	playse SE_TK_KASYA
	delay 60
	applymovement VAR_LAST_TALKED, MossdeepCity_GameCorner_1F_Movement_27734D
	waitmovement 0
	closemessage
	applymovement 255, MossdeepCity_GameCorner_1F_Movement_277360
	waitmovement 0
	hideobjectat 255, PETALBURG_CITY
	release
	waitstate
	end

MossdeepCity_GameCorner_1F_EventScript_277E48:: @ 8277E48
	delay 60
	msgbox MossdeepCity_GameCorner_1F_Text_278D68, 4
	release
	end

MossdeepCity_GameCorner_1F_EventScript_277E55:: @ 8277E55
	msgbox MossdeepCity_GameCorner_1F_Text_278E60, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_GameCorner_1F_EventScript_2772F9
	compare_var_to_value VAR_0x8005, 0
	call_if 1, MossdeepCity_GameCorner_1F_EventScript_277E84
	compare_var_to_value VAR_0x8005, 1
	call_if 1, MossdeepCity_GameCorner_1F_EventScript_277E8D
	goto MossdeepCity_GameCorner_1F_EventScript_2772F9
	end

MossdeepCity_GameCorner_1F_EventScript_277E84:: @ 8277E84
	msgbox MossdeepCity_GameCorner_1F_Text_278EDC, 4
	return

MossdeepCity_GameCorner_1F_EventScript_277E8D:: @ 8277E8D
	msgbox MossdeepCity_GameCorner_1F_Text_278FA4, 4
	return

MossdeepCity_GameCorner_1F_EventScript_277E96:: @ 8277E96
	lockall
	special sub_802E3C4
	waitstate
	releaseall
	end

MossdeepCity_GameCorner_1F_EventScript_277E9D:: @ 8277E9D
	lockall
	special sub_8027AAC
	waitstate
	releaseall
	end

OldaleTown_PokemonCenter_2F_Text_277EA4: @ 8277EA4
	.string "Welcome to the POKéMON CABLE\n"
	.string "CLUB.\p"
	.string "Which of our services do you wish\n"
	.string "to use?$"

	.incbin "baserom.gba", 0x277ef1, 0xfd

OldaleTown_PokemonCenter_2F_Text_277FEE: @ 8277FEE
	.string "For a DOUBLE BATTLE, you must\n"
	.string "have at least two POKéMON.$"

OldaleTown_PokemonCenter_2F_Text_278027: @ 8278027
	.string "For trading, you must have at\n"
	.string "least two POKéMON with you.$"

OldaleTown_PokemonCenter_2F_Text_278061: @ 8278061
	.string "A POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY can’t be traded.$"

gUnknown_08278091:: @ 8278091

gUnknown_08278091: @ 8278091
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

gUnknown_082780B3:: @ 82780B3
	.incbin "baserom.gba", 0x2780b3, 0x3f

gUnknown_082780F2:: @ 82780F2
	.incbin "baserom.gba", 0x2780f2, 0x3f

gUnknown_08278131:: @ 8278131

	.incbin "baserom.gba", 0x278131, 0x66

OldaleTown_PokemonCenter_2F_Text_278197: @ 8278197
	.string "Please enter.$"

OldaleTown_PokemonCenter_2F_Text_2781A5: @ 82781A5
	.string "I’ll direct you to your room now.$"

LilycoveCity_ContestLobby_Text_2781C7: @ 82781C7
OldaleTown_PokemonCenter_2F_Text_2781C7: @ 82781C7
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"

LilycoveCity_ContestLobby_Text_27821C: @ 827821C
OldaleTown_PokemonCenter_2F_Text_27821C: @ 827821C
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"

BattleFrontier_BattleTowerLobby_Text_278255: @ 8278255
LilycoveCity_ContestLobby_Text_278255: @ 8278255
OldaleTown_PokemonCenter_2F_Text_278255: @ 8278255
	.string "The link partners appear to have\n"
	.string "made different selections.$"

OldaleTown_PokemonCenter_2F_Text_278291: @ 8278291
	.string "Please do visit again.$"

BattleFrontier_BattleTowerLobby_Text_2782A8: @ 82782A8
OldaleTown_PokemonCenter_2F_Text_2782A8: @ 82782A8
	.string "The number of participants is\n"
	.string "incorrect.$"

OldaleTown_PokemonCenter_2F_Text_2782D1: @ 82782D1
	.string "The SINGLE BATTLE Mode can’t be\n"
	.string "played by {STR_VAR_1} players.$"

OldaleTown_PokemonCenter_2F_Text_278307: @ 8278307
	.string "The DOUBLE BATTLE Mode can’t be\n"
	.string "played by {STR_VAR_1} players.$"

OldaleTown_PokemonCenter_2F_Text_27833D: @ 827833D
	.string "There must be four players to play\n"
	.string "this Battle Mode.$"

OldaleTown_PokemonCenter_2F_Text_278372: @ 8278372
	.string "Please confirm the number of\n"
	.string "players and start again.$"

	.incbin "baserom.gba", 0x2783a8, 0x10c

SingleBattleColosseum_Text_2784B4: @ 82784B4
	.string "Please take your place and start\n"
	.string "your battle.$"

TradeCenter_Text_2784E2: @ 82784E2
	.string "Please take your seat and start\n"
	.string "your trade.$"

RecordCorner_Text_27850E: @ 827850E
	.string "Thanks for coming.$"

OldaleTown_PokemonCenter_2F_Text_278521: @ 8278521
	.string "The TRAINER CARD data will\n"
	.string "be overwritten.$"

OldaleTown_PokemonCenter_2F_Text_27854C: @ 827854C
	.string "I hope to see you again!$"

OldaleTown_PokemonCenter_2F_Text_278565: @ 8278565
	.string "I’m awfully sorry.\p"
	.string "We’re not set up to conduct trades\n"
	.string "with TRAINERS far away in another\l"
	.string "region yet…$"

OldaleTown_PokemonCenter_2F_Text_2785C9: @ 82785C9
	.string "The other TRAINER is not ready.$"

OldaleTown_PokemonCenter_2F_Text_2785E9: @ 82785E9
	.string "You have at least one POKéMON\n"
	.string "that can’t be taken.$"

RecordCorner_Text_27861C: @ 827861C
	.string "Please take your seat and wait.$"

RecordCorner_Text_27863C: @ 827863C
	.string "{STR_VAR_1} sent over one\n"
	.string "{STR_VAR_2}.$"

OldaleTown_PokemonCenter_2F_Text_278651: @ 8278651
	.string "Sorry, there is a transmission error.\p"
	.string "You may not mix records with  \n"
	.string "Japanese Ruby or Sapphire games.\p"
	.string "Also, you can’t mix records with\n"
	.string "Japanese Emerald and overseas Ruby\l"
	.string "or Sapphire games at the same time.$"

	.incbin "baserom.gba", 0x27871f, 0x1dd

OldaleTown_PokemonCenter_2F_Text_2788FC: @ 82788FC
	.string "To use the BERRY CRUSH service,\n"
	.string "you must have at least one BERRY.$"

OldaleTown_PokemonCenter_2F_Text_27893E: @ 827893E
	.string "To enter the UNION ROOM, you must\n"
	.string "have at least two POKéMON.$"

OldaleTown_PokemonCenter_2F_Text_27897B: @ 827897B
	.string "No POKéMON holding the {STR_VAR_1}\n"
	.string "BERRY may enter the UNION ROOM.$"

OldaleTown_PokemonCenter_2F_Text_2789B5: @ 82789B5
	.string "This is the POKéMON WIRELESS CLUB\n"
	.string "UNION ROOM.\p"
	.string "Unfortunately, your Wireless\n"
	.string "Adapter is not connected properly.\p"
	.string "Please do come again.$"

	.incbin "baserom.gba", 0x278a39, 0xf

OldaleTown_PokemonCenter_1F_Text_278A48: @ 8278A48
	.string "It appears as if {STR_VAR_1} is playing\n"
	.string "right now.\l"
	.string "Go for it!$"

MossdeepCity_GameCorner_1F_Text_278A7D: @ 8278A7D
	.string "I can explain game rules to you,\n"
	.string "if you’d like.\p"
	.string "Which game should I describe?$"

MossdeepCity_GameCorner_1F_Text_278ACB: @ 8278ACB
	.string "“POKéMON JUMP”\p"
	.string "Make your POKéMON skip the VINE WHIP\n"
	.string "rope with the A Button.\p"
	.string "Only mini POKéMON around 28 inches\n"
	.string "or less may participate.\p"
	.string "POKéMON that only swim, burrow,\n"
	.string "or fly are not good at jumping.\p"
	.string "As a result, those POKéMON may not\n"
	.string "participate.\p"
	.string "Good things happen if everyone\n"
	.string "jumps in time.$"

MossdeepCity_GameCorner_1F_Text_278BF1: @ 8278BF1
	.string "“DODRIO BERRY-PICKING”\p"
	.string "Command DODRIO’s three heads to\n"
	.string "catch falling BERRIES.\p"
	.string "Press right, up, or left on the\n"
	.string "{0xF9}Ç Control Pad to move the heads.\p"
	.string "To play this game, you must have\n"
	.string "a DODRIO.$"

MossdeepCity_GameCorner_1F_Text_278CAC: @ 8278CAC
	.string "If you want to play a game,\n"
	.string "please tell the old man beside me.$"

MossdeepCity_GameCorner_1F_Text_278CEB: @ 8278CEB
	.string "Hi, welcome!\n"
	.string "Are you here to play games using\l"
	.string "Wireless Communication?\p"
	.string "Can you wait just a little bit?$"

MossdeepCity_GameCorner_1F_Text_278D51: @ 8278D51
	.string "All right, come again!$"

MossdeepCity_GameCorner_1F_Text_278D68: @ 8278D68
	.string "The Wireless Adapter isn’t connected.\n"
	.string "Come back when it’s hooked up!$"

MossdeepCity_GameCorner_1F_Text_278DAD: @ 8278DAD
	.string "All right, which game did you want\n"
	.string "to play?$"

MossdeepCity_GameCorner_1F_Text_278DD9: @ 8278DD9
	.string "Which POKéMON would you like to\n"
	.string "enter?$"

MossdeepCity_GameCorner_1F_Text_278E00: @ 8278E00
	.string "Okay, you’re all good to go.\n"
	.string "Don’t let the others beat you!$"

	.incbin "baserom.gba", 0x278e3c, 0x24

MossdeepCity_GameCorner_1F_Text_278E60: @ 8278E60
	.string "It doesn’t look like you have any\n"
	.string "POKéMON that you can enter…\p"
	.string "Would you like me to explain what\n"
	.string "kinds of POKéMON can enter?$"

MossdeepCity_GameCorner_1F_Text_278EDC: @ 8278EDC
	.string "“POKéMON JUMP” is open to POKéMON\n"
	.string "around 28 inches or less.\p"
	.string "What you can’t enter are those\n"
	.string "POKéMON that can’t jump.\p"
	.string "You know, like POKéMON that only\n"
	.string "swim, burrow, or fly.\p"
	.string "That’s all you need to know.$"

MossdeepCity_GameCorner_1F_Text_278FA4: @ 8278FA4
	.string "DODRIO BERRY-PICKING is a game that \n"
	.string "only DODRIO may enter.$"

	.incbin "baserom.gba", 0x278fe0, 0x33

OldaleTown_PokemonCenter_2F_Text_279013: @ 8279013
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB DIRECT CORNER.\p"
	.string "You may interact directly with\n"
	.string "your friends here.\p"
	.string "Which room would you like to\n"
	.string "enter?$"

OldaleTown_PokemonCenter_2F_Text_27909D: @ 827909D
	.string "Would you like to trade POKéMON?$"

OldaleTown_PokemonCenter_2F_Text_2790BE: @ 82790BE
	.string "Which Battle Mode would you like\n"
	.string "to play?$"

OldaleTown_PokemonCenter_2F_Text_2790E8: @ 82790E8
	.string "Would you like to access\n"
	.string "the RECORD CORNER?$"

OldaleTown_PokemonCenter_2F_Text_279114: @ 8279114
	.string "Would you like to use the\n"
	.string "BERRY CRUSH System?$"

OldaleTown_PokemonCenter_2F_Text_279142: @ 8279142
	.string "There are three Battle Modes.\p"
	.string "SINGLE BATTLE is for two TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.\p"
	.string "DOUBLE BATTLE is for two TRAINERS\n"
	.string "with two or more POKéMON each.\p"
	.string "Each TRAINER will send out two\n"
	.string "POKéMON in battle at a time.\p"
	.string "MULTI BATTLE is for four TRAINERS\n"
	.string "with one or more POKéMON each.\p"
	.string "Each TRAINER can have one POKéMON\n"
	.string "in battle at a time.$"

BattleFrontier_BattleTowerLobby_Text_2792CD: @ 82792CD
OldaleTown_PokemonCenter_2F_Text_2792CD: @ 82792CD
	.string "Please decide which of you two\n"
	.string "will become the LEADER.\p"
	.string "The other player must then choose\n"
	.string "“JOIN GROUP.”$"

OldaleTown_PokemonCenter_2F_Text_279334: @ 8279334
	.string "Please decide which of you four\n"
	.string "will become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

MossdeepCity_GameCorner_1F_Text_2793A3: @ 82793A3
OldaleTown_PokemonCenter_2F_Text_2793A3: @ 82793A3
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

OldaleTown_PokemonCenter_2F_Text_27940D: @ 827940D
	.string "Welcome to the POKéMON WIRELESS\n"
	.string "CLUB UNION ROOM.\p"
	.string "You may interact directly with\n"
	.string "other TRAINERS here, some of\l"
	.string "whom you may not even know.\p"
	.string "Would you like to enter the ROOM?$"

OldaleTown_PokemonCenter_2F_Text_2794B8: @ 82794B8
	.string "The TRAINERS in the UNION ROOM\n"
	.string "will be those players around you\l"
	.string "who have also entered the ROOM.\p"
	.string "You may do all sorts of things\n"
	.string "here, such as exchanging greetings.\p"
	.string "You may enter two POKéMON up to\n"
	.string "Lv. 30 for a one-on-one battle.\p"
	.string "You may take part in a chat with\n"
	.string "two to five people.\p"
	.string "Or, you may register a POKéMON for\n"
	.string "trade.\p"
	.string "Would you like to enter the ROOM?$"

OldaleTown_PokemonCenter_2F_Text_27961C: @ 827961C
	.string "I hope you enjoy your time in\n"
	.string "the UNION ROOM.$"

OldaleTown_PokemonCenter_2F_Text_27964A: @ 827964A
	.string "Hello!\n"
	.string "My name is TEALA.\p"
	.string "This must be your first time\n"
	.string "up here.\p"
	.string "I’ll show you how the Wireless\n"
	.string "Communication System works.\p"
	.string "First, I need to show you this\n"
	.string "floor of our POKéMON CENTER.\p"
	.string "Right this way, please.$"

OldaleTown_PokemonCenter_2F_Text_279718: @ 8279718
	.string "On the top floor, there are two\n"
	.string "rooms.\p"
	.string "First, the room on the left.\n"
	.string "It’s the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "If the Wireless Adapter isn’t\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

OldaleTown_PokemonCenter_2F_Text_279937: @ 8279937
	.string "Hello, {PLAYER}!\p"
	.string "It’s me, TEALA, the POKéMON\n"
	.string "CENTER 2F attendant.\p"
	.string "Is there something you needed to\n"
	.string "ask me about linking?$"

OldaleTown_PokemonCenter_2F_Text_2799AA: @ 82799AA
	.string "Let me explain how the POKéMON\n"
	.string "WIRELESS CLUB works.\p"
	.string "On this, the top floor, there are\n"
	.string "two rooms.\p"
	.string "First, the room on the left.\n"
	.string "It’s the UNION ROOM.\p"
	.string "You may link up with TRAINERS\n"
	.string "around you who have also entered\l"
	.string "the UNION ROOM.\p"
	.string "With them, you may do things like\n"
	.string "chat, battle, and trade.\p"
	.string "Second, the room on the right is\n"
	.string "the DIRECT CORNER.\p"
	.string "You may trade or battle POKéMON\n"
	.string "with your friends in this room.\p"
	.string "Sometimes, you may not be able to\n"
	.string "find your friends in the UNION ROOM\l"
	.string "or the DIRECT CORNER.\p"
	.string "In that case, please move closer\n"
	.string "to your friends.\p"
	.string "If the Wireless Adapter isn’t\n"
	.string "connected, you may still link up\l"
	.string "using a GBA Game Link cable.\p"
	.string "If that is the case, you must go\n"
	.string "to the DIRECT CORNER.\p"
	.string "I hope you enjoy the Wireless \n"
	.string "Communication System.$"

OldaleTown_PokemonCenter_2F_Text_279C91: @ 8279C91
	.string "I hope you enjoy the Wireless\n"
	.string "Communication System.$"

LilycoveCity_ContestLobby_EventScript_279CC5:: @ 8279CC5
	lock
	faceplayer
	compare_var_to_value VAR_0x408A, 0
	goto_if 5, LilycoveCity_ContestLobby_EventScript_279D13
	checkflag FLAG_0x05F
	call_if 1, LilycoveCity_ContestLobby_EventScript_279CEA
	checkflag FLAG_0x05F
	call_if 0, LilycoveCity_ContestLobby_EventScript_279CF3
	goto LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279CEA:: @ 8279CEA
	msgbox LilycoveCity_ContestLobby_Text_27AEA8, 4
	return

LilycoveCity_ContestLobby_EventScript_279CF3:: @ 8279CF3
	msgbox LilycoveCity_ContestLobby_Text_27ADA7, 4
	giveitem_std ITEM_POKEBLOCK_CASE
	setflag FLAG_0x05F
	msgbox LilycoveCity_ContestLobby_Text_27AE47, 4
	return

LilycoveCity_ContestLobby_EventScript_279D13:: @ 8279D13
	msgbox LilycoveCity_ContestLobby_Text_27B67B, 4
	switch VAR_0x408A
	case 4, LilycoveCity_ContestLobby_EventScript_279D2C
	end

LilycoveCity_ContestLobby_EventScript_279D2C:: @ 8279D2C
	giveitem_std ITEM_LUXURY_BALL
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_279D4B
	setvar VAR_0x408A, 0
	closemessage
	release
	end

LilycoveCity_ContestLobby_EventScript_279D4B:: @ 8279D4B
	call LilycoveCity_ContestLobby_EventScript_27205E
	msgbox LilycoveCity_ContestLobby_Text_27B6E7, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_279D5A:: @ 8279D5A
	message LilycoveCity_ContestLobby_Text_27AF28
	waitmessage
	multichoice 0, 0, 2, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E62
	case 1, LilycoveCity_ContestLobby_EventScript_279D97
	case 2, LilycoveCity_ContestLobby_EventScript_279E09
	case 127, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279D97:: @ 8279D97
	message LilycoveCity_ContestLobby_Text_27AF5E
	waitmessage
	multichoice 0, 0, 3, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279DDF
	case 1, LilycoveCity_ContestLobby_EventScript_279DED
	case 2, LilycoveCity_ContestLobby_EventScript_279DFB
	case 3, LilycoveCity_ContestLobby_EventScript_279D5A
	case 127, LilycoveCity_ContestLobby_EventScript_279D5A
	end

LilycoveCity_ContestLobby_EventScript_279DDF:: @ 8279DDF
	msgbox LilycoveCity_ContestLobby_Text_27AF7A, 4
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DED:: @ 8279DED
	msgbox LilycoveCity_ContestLobby_Text_27B17D, 4
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279DFB:: @ 8279DFB
	msgbox LilycoveCity_ContestLobby_Text_27B221, 4
	goto LilycoveCity_ContestLobby_EventScript_279D97
	end

LilycoveCity_ContestLobby_EventScript_279E09:: @ 8279E09
	msgbox LilycoveCity_ContestLobby_Text_27BD4F, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_279E13:: @ 8279E13
	msgbox LilycoveCity_ContestLobby_Text_27B44A, 4
	choosecontestpkmn
	compare_var_to_value VAR_0x8004, 255
	goto_eq LilycoveCity_ContestLobby_EventScript_279E09
	special sub_80F7F30
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_279F12
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_279F87
	compare_var_to_value VAR_RESULT, 2
	goto_eq LilycoveCity_ContestLobby_EventScript_279F45
	compare_var_to_value VAR_RESULT, 3
	goto_eq LilycoveCity_ContestLobby_EventScript_279F69
	compare_var_to_value VAR_RESULT, 4
	goto_eq LilycoveCity_ContestLobby_EventScript_279F78
	end

LilycoveCity_ContestLobby_EventScript_279E62:: @ 8279E62
	message LilycoveCity_ContestLobby_Text_27B3FF
	waitmessage
	multichoice 0, 0, 82, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279EB5
	case 1, LilycoveCity_ContestLobby_EventScript_279EC0
	case 2, LilycoveCity_ContestLobby_EventScript_279ECB
	case 3, LilycoveCity_ContestLobby_EventScript_279ED6
	case 4, LilycoveCity_ContestLobby_EventScript_279E09
	case 127, LilycoveCity_ContestLobby_EventScript_279E09
	end

LilycoveCity_ContestLobby_EventScript_279EB5:: @ 8279EB5
	setvar VAR_CONTEST_RANK, 0
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EC0:: @ 8279EC0
	setvar VAR_CONTEST_RANK, 1
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ECB:: @ 8279ECB
	setvar VAR_CONTEST_RANK, 2
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279ED6:: @ 8279ED6
	setvar VAR_CONTEST_RANK, 3
	goto LilycoveCity_ContestLobby_EventScript_279EE1
	end

LilycoveCity_ContestLobby_EventScript_279EE1:: @ 8279EE1
	message LilycoveCity_ContestLobby_Text_27B423
	waitmessage
	multichoice 0, 0, 4, 0
	switch VAR_RESULT
	case 5, LilycoveCity_ContestLobby_EventScript_279E09
	case 127, LilycoveCity_ContestLobby_EventScript_279E09
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto LilycoveCity_ContestLobby_EventScript_279E13
	end

LilycoveCity_ContestLobby_EventScript_279F12:: @ 8279F12
	msgbox LilycoveCity_ContestLobby_Text_27B471, 4
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

	.incbin "baserom.gba", 0x279f21, 0x24

LilycoveCity_ContestLobby_EventScript_279F45:: @ 8279F45
	msgbox LilycoveCity_ContestLobby_Text_27B547, 5
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_279E13
	case 1, LilycoveCity_ContestLobby_EventScript_279F87
	end

LilycoveCity_ContestLobby_EventScript_279F69:: @ 8279F69
	msgbox LilycoveCity_ContestLobby_Text_27B4C4, 4
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F78:: @ 8279F78
	msgbox LilycoveCity_ContestLobby_Text_27B501, 4
	goto LilycoveCity_ContestLobby_EventScript_279E13
	release
	end

LilycoveCity_ContestLobby_EventScript_279F87:: @ 8279F87
	msgbox LilycoveCity_ContestLobby_Text_27B5E2, 4
	closemessage
	releaseall
	setvar VAR_0x4086, 1
	return

LinkContestRoom1_EventScript_279F97:: @ 8279F97
	special sub_80F90DC
	setvar VAR_0x8006, 0
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD43
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD09
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_279FF2
	call LinkContestRoom1_EventScript_27A03C
	call LinkContestRoom1_EventScript_27A097
	call LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A801
	call LinkContestRoom1_EventScript_27A8A5
	call LinkContestRoom1_EventScript_27A987
	call LinkContestRoom1_EventScript_27A9D4
	call LinkContestRoom1_EventScript_27AA1B
	call LinkContestRoom1_EventScript_27AB36
	setvar VAR_0x4086, 2
	return

LinkContestRoom1_EventScript_279FF2:: @ 8279FF2
	switch VAR_CONTEST_RANK
	case 0, LinkContestRoom1_EventScript_27A024
	case 1, LinkContestRoom1_EventScript_27A02A
	case 2, LinkContestRoom1_EventScript_27A030
	case 3, LinkContestRoom1_EventScript_27A036
	return

LinkContestRoom1_EventScript_27A024:: @ 827A024
	setvar VAR_0x8009, 5
	return

LinkContestRoom1_EventScript_27A02A:: @ 827A02A
	setvar VAR_0x8009, 6
	return

LinkContestRoom1_EventScript_27A030:: @ 827A030
	setvar VAR_0x8009, 7
	return

LinkContestRoom1_EventScript_27A036:: @ 827A036
	setvar VAR_0x8009, 8
	return

LinkContestRoom1_EventScript_27A03C:: @ 827A03C
	switch VAR_CONTEST_CATEGORY
	case 0, LinkContestRoom1_EventScript_27A079
	case 1, LinkContestRoom1_EventScript_27A07F
	case 2, LinkContestRoom1_EventScript_27A085
	case 3, LinkContestRoom1_EventScript_27A08B
	case 4, LinkContestRoom1_EventScript_27A091
	return

LinkContestRoom1_EventScript_27A079:: @ 827A079
	setvar VAR_0x8008, 0
	return

LinkContestRoom1_EventScript_27A07F:: @ 827A07F
	setvar VAR_0x8008, 1
	return

LinkContestRoom1_EventScript_27A085:: @ 827A085
	setvar VAR_0x8008, 2
	return

LinkContestRoom1_EventScript_27A08B:: @ 827A08B
	setvar VAR_0x8008, 3
	return

LinkContestRoom1_EventScript_27A091:: @ 827A091
	setvar VAR_0x8008, 4
	return

LinkContestRoom1_EventScript_27A097:: @ 827A097
	buffercontesttypestring 1, 32776
	bufferstdstring 2, VAR_0x8009
	call LinkContestRoom1_EventScript_27A0B1
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD0B
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A0B1:: @ 827A0B1
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A0C7
	lockall
	msgbox LinkContestRoom1_Text_27B711, 4
	releaseall
	return

LinkContestRoom1_EventScript_27A0C7:: @ 827A0C7
	specialvar VAR_RESULT, sub_80F9160
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27A0DE
	messageautoscroll LinkContestRoom1_Text_27B78F
	waitmessage
	return

LinkContestRoom1_EventScript_27A0DE:: @ 827A0DE
	messageautoscroll LinkContestRoom1_Text_27C929
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27C972
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A0F5:: @ 827A0F5
	call LinkContestRoom1_EventScript_27A149
	call LinkContestRoom1_EventScript_27A1D2
	call LinkContestRoom1_EventScript_27A34F
	call LinkContestRoom1_EventScript_27A2D5
	call LinkContestRoom1_EventScript_27A77A
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A133
	addvar VAR_0x8006, 1
	compare_var_to_value VAR_0x8006, 4
	goto_if 5, LinkContestRoom1_EventScript_27A0F5
	call LinkContestRoom1_EventScript_27A230
	setvar VAR_0x4001, 6
	return

LinkContestRoom1_EventScript_27A133:: @ 827A133
	specialvar VAR_RESULT, sub_80F9160
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27A144
	return

LinkContestRoom1_EventScript_27A144:: @ 827A144
	special sub_80F905C
	waitstate
	return

LinkContestRoom1_EventScript_27A149:: @ 827A149
	compare_var_to_value VAR_0x8006, 0
	goto_eq LinkContestRoom1_EventScript_27A176
	compare_var_to_value VAR_0x8006, 1
	goto_eq LinkContestRoom1_EventScript_27A18D
	compare_var_to_value VAR_0x8006, 2
	goto_eq LinkContestRoom1_EventScript_27A1A4
	compare_var_to_value VAR_0x8006, 3
	goto_eq LinkContestRoom1_EventScript_27A1BB
	return

LinkContestRoom1_EventScript_27A176:: @ 827A176
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 3, LinkContestRoom1_Movement_27AD52
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 3
	return

LinkContestRoom1_EventScript_27A18D:: @ 827A18D
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 4, LinkContestRoom1_Movement_27AD5E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 4
	return

LinkContestRoom1_EventScript_27A1A4:: @ 827A1A4
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 5, LinkContestRoom1_Movement_27AD66
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 5
	return

LinkContestRoom1_EventScript_27A1BB:: @ 827A1BB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement 14, LinkContestRoom1_Movement_27AD6E
	waitmovement 0
	releaseall
	setvar VAR_0x800B, 14
	return

LinkContestRoom1_EventScript_27A1D2:: @ 827A1D2
	special sub_80F8850
	addvar VAR_0x8006, 1
	buffernumberstring 1, VAR_0x8006
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27AD80
	addobject 13
	playse SE_DANSA
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD20
	waitmovement 0
	releaseall
	addvar VAR_0x8006, 65535
	playse SE_BOWA2
	special sub_80F8D28
	call LinkContestRoom1_EventScript_27A217
	return

LinkContestRoom1_EventScript_27A217:: @ 827A217
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A229
	message LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A229:: @ 827A229
	messageautoscroll LinkContestRoom1_Text_27B815
	waitmessage
	return

LinkContestRoom1_EventScript_27A230:: @ 827A230
	call LinkContestRoom1_EventScript_27A26C
	call LinkContestRoom1_EventScript_27A2B9
	playse SE_W227B
	waitmessage
	call LinkContestRoom1_EventScript_27AA1B
	applymovement 1, LinkContestRoom1_Movement_27AD23
	waitmovement 0
	applymovement 2, LinkContestRoom1_Movement_27AD25
	waitmovement 0
	delay 20
	applymovement 1, LinkContestRoom1_Movement_27AD13
	applymovement 2, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A26C:: @ 827A26C
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A280
	msgbox LinkContestRoom1_Text_27B830, 4
	return

LinkContestRoom1_EventScript_27A280:: @ 827A280
	specialvar VAR_RESULT, sub_80F9160
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27A297
	messageautoscroll LinkContestRoom1_Text_27B830
	waitmessage
	return

LinkContestRoom1_EventScript_27A297:: @ 827A297
	messageautoscroll LinkContestRoom1_Text_27C9AF
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA04
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA42
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2B9:: @ 827A2B9
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A2CA
	message LinkContestRoom1_Text_27B8F2
	return

LinkContestRoom1_EventScript_27A2CA:: @ 827A2CA
	messageautoscroll LinkContestRoom1_Text_27B8F2
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A2D5:: @ 827A2D5
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	playse SE_W227B
	call LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD3B
	waitmovement 0
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD45
	waitmovement 0
	applymovement 1, LinkContestRoom1_Movement_27AD4E
	applymovement 2, LinkContestRoom1_Movement_27AD49
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A34F:: @ 827A34F
	special sub_80F82FC
	compare_var_to_value VAR_0x4088, 1
	call_if 1, LinkContestRoom1_EventScript_27A454
	compare_var_to_value VAR_0x4088, 2
	call_if 1, LinkContestRoom1_EventScript_27A4B2
	compare_var_to_value VAR_0x4088, 3
	call_if 1, LinkContestRoom1_EventScript_27A510
	compare_var_to_value VAR_0x4088, 4
	call_if 1, LinkContestRoom1_EventScript_27A56E
	compare_var_to_value VAR_0x4088, 5
	call_if 1, LinkContestRoom1_EventScript_27A5CC
	setvar VAR_0x4001, 9
	setvar VAR_0x4002, 9
	setvar VAR_0x4003, 9
	setvar VAR_0x4004, 9
	setvar VAR_0x4005, 9
	setvar VAR_0x4006, 9
	setvar VAR_0x4007, 9
	setvar VAR_0x4008, 9
	compare_var_to_value VAR_0x4000, 0
	call_if 2, LinkContestRoom1_EventScript_27A3E5
	setvar VAR_0x4001, 0
	setvar VAR_0x4002, 0
	setvar VAR_0x4003, 0
	setvar VAR_0x4004, 0
	setvar VAR_0x4005, 0
	setvar VAR_0x4006, 0
	setvar VAR_0x4007, 0
	setvar VAR_0x4008, 0
	return

LinkContestRoom1_EventScript_27A3E5:: @ 827A3E5
	setvar VAR_RESULT, 8
	special sub_80F8FE8
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LinkContestRoom1_EventScript_27A65A
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LinkContestRoom1_EventScript_27A67E
	compare_var_to_value VAR_RESULT, 2
	call_if 1, LinkContestRoom1_EventScript_27A6A2
	compare_var_to_value VAR_RESULT, 3
	call_if 1, LinkContestRoom1_EventScript_27A6C6
	compare_var_to_value VAR_RESULT, 4
	call_if 1, LinkContestRoom1_EventScript_27A6EA
	compare_var_to_value VAR_RESULT, 5
	call_if 1, LinkContestRoom1_EventScript_27A70E
	compare_var_to_value VAR_RESULT, 6
	call_if 1, LinkContestRoom1_EventScript_27A732
	compare_var_to_value VAR_RESULT, 7
	call_if 1, LinkContestRoom1_EventScript_27A756
	compare_var_to_value VAR_0x4000, 0
	goto_if 2, LinkContestRoom1_EventScript_27A3E5
	waitmovement 0
	return

LinkContestRoom1_EventScript_27A454:: @ 827A454
	compare_var_to_value VAR_0x8004, 80
	goto_if 2, LinkContestRoom1_EventScript_27A654
	compare_var_to_value VAR_0x8004, 70
	goto_if 2, LinkContestRoom1_EventScript_27A64E
	compare_var_to_value VAR_0x8004, 60
	goto_if 2, LinkContestRoom1_EventScript_27A648
	compare_var_to_value VAR_0x8004, 50
	goto_if 2, LinkContestRoom1_EventScript_27A642
	compare_var_to_value VAR_0x8004, 40
	goto_if 2, LinkContestRoom1_EventScript_27A63C
	compare_var_to_value VAR_0x8004, 30
	goto_if 2, LinkContestRoom1_EventScript_27A636
	compare_var_to_value VAR_0x8004, 20
	goto_if 2, LinkContestRoom1_EventScript_27A630
	compare_var_to_value VAR_0x8004, 10
	goto_if 2, LinkContestRoom1_EventScript_27A62A
	setvar VAR_0x4000, 0
	return

LinkContestRoom1_EventScript_27A4B2:: @ 827A4B2
	compare_var_to_value VAR_0x8004, 230
	goto_if 2, LinkContestRoom1_EventScript_27A654
	compare_var_to_value VAR_0x8004, 210
	goto_if 2, LinkContestRoom1_EventScript_27A64E
	compare_var_to_value VAR_0x8004, 190
	goto_if 2, LinkContestRoom1_EventScript_27A648
	compare_var_to_value VAR_0x8004, 170
	goto_if 2, LinkContestRoom1_EventScript_27A642
	compare_var_to_value VAR_0x8004, 150
	goto_if 2, LinkContestRoom1_EventScript_27A63C
	compare_var_to_value VAR_0x8004, 130
	goto_if 2, LinkContestRoom1_EventScript_27A636
	compare_var_to_value VAR_0x8004, 110
	goto_if 2, LinkContestRoom1_EventScript_27A630
	compare_var_to_value VAR_0x8004, 90
	goto_if 2, LinkContestRoom1_EventScript_27A62A
	setvar VAR_0x4000, 0
	return

LinkContestRoom1_EventScript_27A510:: @ 827A510
	compare_var_to_value VAR_0x8004, 380
	goto_if 2, LinkContestRoom1_EventScript_27A654
	compare_var_to_value VAR_0x8004, 350
	goto_if 2, LinkContestRoom1_EventScript_27A64E
	compare_var_to_value VAR_0x8004, 320
	goto_if 2, LinkContestRoom1_EventScript_27A648
	compare_var_to_value VAR_0x8004, 290
	goto_if 2, LinkContestRoom1_EventScript_27A642
	compare_var_to_value VAR_0x8004, 260
	goto_if 2, LinkContestRoom1_EventScript_27A63C
	compare_var_to_value VAR_0x8004, 230
	goto_if 2, LinkContestRoom1_EventScript_27A636
	compare_var_to_value VAR_0x8004, 200
	goto_if 2, LinkContestRoom1_EventScript_27A630
	compare_var_to_value VAR_0x8004, 170
	goto_if 2, LinkContestRoom1_EventScript_27A62A
	setvar VAR_0x4000, 0
	return

LinkContestRoom1_EventScript_27A56E:: @ 827A56E
	compare_var_to_value VAR_0x8004, 600
	goto_if 2, LinkContestRoom1_EventScript_27A654
	compare_var_to_value VAR_0x8004, 560
	goto_if 2, LinkContestRoom1_EventScript_27A64E
	compare_var_to_value VAR_0x8004, 520
	goto_if 2, LinkContestRoom1_EventScript_27A648
	compare_var_to_value VAR_0x8004, 480
	goto_if 2, LinkContestRoom1_EventScript_27A642
	compare_var_to_value VAR_0x8004, 440
	goto_if 2, LinkContestRoom1_EventScript_27A63C
	compare_var_to_value VAR_0x8004, 400
	goto_if 2, LinkContestRoom1_EventScript_27A636
	compare_var_to_value VAR_0x8004, 360
	goto_if 2, LinkContestRoom1_EventScript_27A630
	compare_var_to_value VAR_0x8004, 320
	goto_if 2, LinkContestRoom1_EventScript_27A62A
	setvar VAR_0x4000, 0
	return

LinkContestRoom1_EventScript_27A5CC:: @ 827A5CC
	compare_var_to_value VAR_0x8004, 600
	goto_if 2, LinkContestRoom1_EventScript_27A654
	compare_var_to_value VAR_0x8004, 550
	goto_if 2, LinkContestRoom1_EventScript_27A64E
	compare_var_to_value VAR_0x8004, 500
	goto_if 2, LinkContestRoom1_EventScript_27A648
	compare_var_to_value VAR_0x8004, 450
	goto_if 2, LinkContestRoom1_EventScript_27A642
	compare_var_to_value VAR_0x8004, 400
	goto_if 2, LinkContestRoom1_EventScript_27A63C
	compare_var_to_value VAR_0x8004, 300
	goto_if 2, LinkContestRoom1_EventScript_27A636
	compare_var_to_value VAR_0x8004, 200
	goto_if 2, LinkContestRoom1_EventScript_27A630
	compare_var_to_value VAR_0x8004, 100
	goto_if 2, LinkContestRoom1_EventScript_27A62A
	setvar VAR_0x4000, 0
	return

LinkContestRoom1_EventScript_27A62A:: @ 827A62A
	setvar VAR_0x4000, 1
	return

LinkContestRoom1_EventScript_27A630:: @ 827A630
	setvar VAR_0x4000, 2
	return

LinkContestRoom1_EventScript_27A636:: @ 827A636
	setvar VAR_0x4000, 3
	return

LinkContestRoom1_EventScript_27A63C:: @ 827A63C
	setvar VAR_0x4000, 4
	return

LinkContestRoom1_EventScript_27A642:: @ 827A642
	setvar VAR_0x4000, 5
	return

LinkContestRoom1_EventScript_27A648:: @ 827A648
	setvar VAR_0x4000, 6
	return

LinkContestRoom1_EventScript_27A64E:: @ 827A64E
	setvar VAR_0x4000, 7
	return

LinkContestRoom1_EventScript_27A654:: @ 827A654
	setvar VAR_0x4000, 8
	return

LinkContestRoom1_EventScript_27A65A:: @ 827A65A
	compare_var_to_value VAR_0x4001, 1
	goto_eq LinkContestRoom1_EventScript_27A67D
	applymovement 6, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4001, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A67D:: @ 827A67D
	return

LinkContestRoom1_EventScript_27A67E:: @ 827A67E
	compare_var_to_value VAR_0x4002, 1
	goto_eq LinkContestRoom1_EventScript_27A6A1
	applymovement 12, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4002, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A6A1:: @ 827A6A1
	return

LinkContestRoom1_EventScript_27A6A2:: @ 827A6A2
	compare_var_to_value VAR_0x4003, 1
	goto_eq LinkContestRoom1_EventScript_27A6C5
	applymovement 7, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4003, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A6C5:: @ 827A6C5
	return

LinkContestRoom1_EventScript_27A6C6:: @ 827A6C6
	compare_var_to_value VAR_0x4004, 1
	goto_eq LinkContestRoom1_EventScript_27A6E9
	applymovement 8, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4004, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A6E9:: @ 827A6E9
	return

LinkContestRoom1_EventScript_27A6EA:: @ 827A6EA
	compare_var_to_value VAR_0x4005, 1
	goto_eq LinkContestRoom1_EventScript_27A70D
	applymovement 9, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4005, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A70D:: @ 827A70D
	return

LinkContestRoom1_EventScript_27A70E:: @ 827A70E
	compare_var_to_value VAR_0x4006, 1
	goto_eq LinkContestRoom1_EventScript_27A731
	applymovement 10, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4006, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A731:: @ 827A731
	return

LinkContestRoom1_EventScript_27A732:: @ 827A732
	compare_var_to_value VAR_0x4007, 1
	goto_eq LinkContestRoom1_EventScript_27A755
	applymovement 11, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4007, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A755:: @ 827A755
	return

LinkContestRoom1_EventScript_27A756:: @ 827A756
	compare_var_to_value VAR_0x4008, 1
	goto_eq LinkContestRoom1_EventScript_27A779
	applymovement 15, LinkContestRoom1_Movement_27AD11
	playse SE_PIN
	delay 14
	setvar VAR_0x4008, 1
	addvar VAR_0x4000, 65535
	return

LinkContestRoom1_EventScript_27A779:: @ 827A779
	return

LinkContestRoom1_EventScript_27A77A:: @ 827A77A
	closemessage
	release
	removeobject 13
	special sub_80F8EB8
	call LinkContestRoom1_EventScript_27A133
	switch VAR_0x8006
	case 0, LinkContestRoom1_EventScript_27A7B9
	case 1, LinkContestRoom1_EventScript_27A7CB
	case 2, LinkContestRoom1_EventScript_27A7DD
	case 3, LinkContestRoom1_EventScript_27A7EF
	return

LinkContestRoom1_EventScript_27A7B9:: @ 827A7B9
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD58
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7CB:: @ 827A7CB
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD62
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7DD:: @ 827A7DD
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD6A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A7EF:: @ 827A7EF
	call LinkContestRoom1_EventScript_27A133
	lockall
	applymovement VAR_0x800B, LinkContestRoom1_Movement_27AD74
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A801:: @ 827A801
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD27
	waitmovement 0
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A853
	waitmessage
	applymovement 1, LinkContestRoom1_Movement_27AD15
	applymovement 2, LinkContestRoom1_Movement_27AD19
	waitmovement 0
	releaseall
	call LinkContestRoom1_EventScript_27A133
	setvar VAR_0x4009, 1
	special sub_80F910C
	startcontest
	special sub_80F90DC
	setvar VAR_0x4009, 0
	lockall
	applymovement 1, LinkContestRoom1_Movement_27AD19
	applymovement 2, LinkContestRoom1_Movement_27AD15
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27A853:: @ 827A853
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A867
	msgbox LinkContestRoom1_Text_27B904, 4
	return

LinkContestRoom1_EventScript_27A867:: @ 827A867
	specialvar VAR_RESULT, sub_80F9160
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27A87E
	messageautoscroll LinkContestRoom1_Text_27B904
	waitmessage
	return

LinkContestRoom1_EventScript_27A87E:: @ 827A87E
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CA71
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CAD0
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27CB55
	waitmessage
	call LinkContestRoom1_EventScript_27A133
	return

LinkContestRoom1_EventScript_27A8A5:: @ 827A8A5
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A8FB
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A91E
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD0F
	waitmovement 0
	call LinkContestRoom1_EventScript_27A941
	call LinkContestRoom1_EventScript_27A133
	call LinkContestRoom1_EventScript_27A964
	call LinkContestRoom1_EventScript_27A133
	applymovement 1, LinkContestRoom1_Movement_27AD13
	waitmovement 0
	closemessage
	releaseall
	special sub_80F910C
	setvar VAR_0x4009, 1
	showcontestresults
	setvar VAR_0x4009, 0
	playbgm BGM_CON_FAN, 0
	return

LinkContestRoom1_EventScript_27A8FB:: @ 827A8FB
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A90F
	msgbox LinkContestRoom1_Text_27BA15, 4
	return

LinkContestRoom1_EventScript_27A90F:: @ 827A90F
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA15
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A91E:: @ 827A91E
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A932
	msgbox LinkContestRoom1_Text_27BA30, 4
	return

LinkContestRoom1_EventScript_27A932:: @ 827A932
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BA30
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A941:: @ 827A941
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A955
	msgbox LinkContestRoom1_Text_27BAAC, 4
	return

LinkContestRoom1_EventScript_27A955:: @ 827A955
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BAAC
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A964:: @ 827A964
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27A978
	msgbox LinkContestRoom1_Text_27BB25, 4
	return

LinkContestRoom1_EventScript_27A978:: @ 827A978
	call LinkContestRoom1_EventScript_27A133
	messageautoscroll LinkContestRoom1_Text_27BB25
	waitmessage
	delay 30
	return

LinkContestRoom1_EventScript_27A987:: @ 827A987
	special sub_80F831C
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27A9BC
	case 1, LinkContestRoom1_EventScript_27A9C2
	case 2, LinkContestRoom1_EventScript_27A9C8
	case 3, LinkContestRoom1_EventScript_27A9CE
	return

LinkContestRoom1_EventScript_27A9BC:: @ 827A9BC
	setvar VAR_0x4003, 3
	return

LinkContestRoom1_EventScript_27A9C2:: @ 827A9C2
	setvar VAR_0x4003, 4
	return

LinkContestRoom1_EventScript_27A9C8:: @ 827A9C8
	setvar VAR_0x4003, 5
	return

LinkContestRoom1_EventScript_27A9CE:: @ 827A9CE
	setvar VAR_0x4003, 14
	return

LinkContestRoom1_EventScript_27A9D4:: @ 827A9D4
	special sub_80F834C
	special sub_80F8390
	addvar VAR_0x8005, 1
	buffernumberstring 1, VAR_0x8005
	addvar VAR_0x8005, 65535
	call LinkContestRoom1_EventScript_27AA00
	applymovement VAR_0x4003, LinkContestRoom1_Movement_27AD1D
	waitmovement 0
	playse SE_W227B
	setvar VAR_0x4001, 0
	return

LinkContestRoom1_EventScript_27AA00:: @ 827AA00
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27AA14
	msgbox LinkContestRoom1_Text_27BB4C, 4
	return

LinkContestRoom1_EventScript_27AA14:: @ 827AA14
	messageautoscroll LinkContestRoom1_Text_27BB4C
	waitmessage
	return

LinkContestRoom1_EventScript_27AA1B:: @ 827AA1B
	addvar VAR_0x4001, 1
	lockall
	compare_var_to_value VAR_0x4088, 1
	call_if 2, LinkContestRoom1_EventScript_27AA6F
	applymovement 9, LinkContestRoom1_Movement_27AD3B
	applymovement 12, LinkContestRoom1_Movement_27AD3F
	applymovement 7, LinkContestRoom1_Movement_27AD3B
	delay 30
	applymovement 10, LinkContestRoom1_Movement_27AD33
	applymovement 11, LinkContestRoom1_Movement_27AD3F
	applymovement 6, LinkContestRoom1_Movement_27AD37
	applymovement 8, LinkContestRoom1_Movement_27AD33
	compare_var_to_value VAR_0x4001, 4
	goto_if 5, LinkContestRoom1_EventScript_27AA1B
	delay 30
	return

LinkContestRoom1_EventScript_27AA6F:: @ 827AA6F
	turnvobject 0, 1
	turnvobject 2, 1
	turnvobject 4, 4
	turnvobject 6, 1
	turnvobject 8, 1
	turnvobject 10, 1
	turnvobject 12, 1
	turnvobject 14, 1
	turnvobject 16, 1
	turnvobject 18, 1
	turnvobject 20, 4
	turnvobject 22, 4
	turnvobject 25, 4
	turnvobject 27, 3
	turnvobject 28, 4
	delay 10
	turnvobject 0, 4
	turnvobject 2, 4
	turnvobject 4, 4
	turnvobject 6, 4
	turnvobject 8, 4
	turnvobject 10, 3
	turnvobject 12, 3
	turnvobject 14, 3
	turnvobject 16, 3
	turnvobject 18, 3
	turnvobject 20, 1
	turnvobject 22, 1
	turnvobject 25, 2
	turnvobject 27, 2
	turnvobject 28, 2
	delay 10
	turnvobject 1, 2
	turnvobject 3, 2
	turnvobject 5, 2
	turnvobject 7, 2
	turnvobject 9, 4
	turnvobject 11, 2
	turnvobject 15, 2
	turnvobject 13, 2
	turnvobject 17, 2
	turnvobject 19, 2
	turnvobject 21, 3
	turnvobject 23, 3
	turnvobject 24, 3
	turnvobject 26, 4
	turnvobject 29, 3
	turnvobject 30, 3
	delay 10
	turnvobject 1, 4
	turnvobject 3, 4
	turnvobject 5, 4
	turnvobject 7, 4
	turnvobject 9, 4
	turnvobject 11, 3
	turnvobject 15, 3
	turnvobject 13, 3
	turnvobject 17, 3
	turnvobject 19, 3
	turnvobject 21, 1
	turnvobject 23, 1
	turnvobject 24, 1
	turnvobject 26, 2
	turnvobject 29, 2
	turnvobject 30, 2
	delay 10
	return

LinkContestRoom1_EventScript_27AB36:: @ 827AB36
	compare_var_to_value VAR_0x4088, 5
	goto_eq LinkContestRoom1_EventScript_27ABD8
	call LinkContestRoom1_EventScript_27AB9E
	checkflag FLAG_0x002
	goto_eq LinkContestRoom1_EventScript_27AB82
	lockall
	msgbox LinkContestRoom1_Text_27BBA8, 4
	releaseall
	call LinkContestRoom1_EventScript_27ABF8
	call LinkContestRoom1_EventScript_27AC5E
	playse SE_W227B
	setvar VAR_0x4001, 0
	call LinkContestRoom1_EventScript_27AA1B
	delay 30
	special sub_80F88E8
	compare_var_to_value VAR_0x8004, 1
	goto_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB82:: @ 827AB82
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, 4
	releaseall
	delay 90
	special sub_80F88E8
	compare_var_to_value VAR_0x8004, 1
	goto_eq LinkContestRoom1_EventScript_27ABD2
	return

LinkContestRoom1_EventScript_27AB9E:: @ 827AB9E
	specialvar VAR_RESULT, sub_80F7F7C
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27ABAF
	return

LinkContestRoom1_EventScript_27ABAF:: @ 827ABAF
	special sub_80F831C
	compare_var_to_value VAR_0x8005, 3
	goto_eq LinkContestRoom1_EventScript_27ABBE
	return

LinkContestRoom1_EventScript_27ABBE:: @ 827ABBE
	compare_var_to_value VAR_CONTEST_RANK, 3
	goto_eq LinkContestRoom1_EventScript_27ABCD
	setflag FLAG_0x002
	return

LinkContestRoom1_EventScript_27ABCD:: @ 827ABCD
	return

LinkContestRoom1_EventScript_27ABCE:: @ 827ABCE
	setflag FLAG_0x10E
	return

LinkContestRoom1_EventScript_27ABD2:: @ 827ABD2
	setvar VAR_0x4099, 1
	return

LinkContestRoom1_EventScript_27ABD8:: @ 827ABD8
	delay 60
	special sub_80F84B0
	special sub_80F831C
	special sub_80F88E8
	compare_var_to_value VAR_0x8004, 1
	goto_eq LinkContestRoom1_EventScript_27ABF1
	closemessage
	return

LinkContestRoom1_EventScript_27ABF1:: @ 827ABF1
	setvar VAR_0x4099, 2
	return

	.incbin "baserom.gba", 0x27abf7, 0x1

LinkContestRoom1_EventScript_27ABF8:: @ 827ABF8
	switch VAR_0x8005
	case 0, LinkContestRoom1_EventScript_27AC2A
	case 1, LinkContestRoom1_EventScript_27AC37
	case 2, LinkContestRoom1_EventScript_27AC44
	case 3, LinkContestRoom1_EventScript_27AC51
	return

LinkContestRoom1_EventScript_27AC2A:: @ 827AC2A
	lockall
	applymovement VAR_0x4003, LinkContestRoom1_Movement_27AD7A
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC37:: @ 827AC37
	lockall
	applymovement VAR_0x4003, LinkContestRoom1_Movement_27AD7E
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC44:: @ 827AC44
	lockall
	applymovement VAR_0x4003, LinkContestRoom1_Movement_27AD29
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC51:: @ 827AC51
	lockall
	applymovement VAR_0x4003, LinkContestRoom1_Movement_27AD2D
	waitmovement 0
	releaseall
	return

LinkContestRoom1_EventScript_27AC5E:: @ 827AC5E
	special sub_80F831C
	compare_var_to_value VAR_0x8005, 3
	goto_eq LinkContestRoom1_EventScript_27AC77
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, 4
	releaseall
	return

LinkContestRoom1_EventScript_27AC77:: @ 827AC77
	compare_var_to_value VAR_0x4088, 2
	call_if 1, LinkContestRoom1_EventScript_27ABCE
	specialvar VAR_RESULT, sub_80F7F7C
	compare_var_to_value VAR_RESULT, 0
	goto_eq LinkContestRoom1_EventScript_27ACDF
	compare_var_to_value VAR_CONTEST_RANK, 3
	goto_eq LinkContestRoom1_EventScript_27ACBD
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, 4
	releaseall
	return

LinkContestRoom1_EventScript_27ACA8:: @ 827ACA8
	lockall
	call LinkContestRoom1_EventScript_27205E
	msgbox LinkContestRoom1_Text_27BC2F, 4
	releaseall
	setvar VAR_0x408A, 4
	return

LinkContestRoom1_EventScript_27ACBD:: @ 827ACBD
	giveitem_std ITEM_LUXURY_BALL
	compare_var_to_value VAR_RESULT, 0
	goto_eq LinkContestRoom1_EventScript_27ACA8
	lockall
	msgbox LinkContestRoom1_Text_27BB7A, 4
	releaseall
	return

LinkContestRoom1_EventScript_27ACDF:: @ 827ACDF
	special sub_80F7FFC
	incrementgamestat 42
	setflag FLAG_SYS_RIBBON_GET
	lockall
	msgbox LinkContestRoom1_Text_27BBD4, 4
	playfanfare BGM_FANFA4
	msgbox LinkContestRoom1_Text_27BC00, 4
	waitfanfare
	special sub_80F8390
	msgbox LinkContestRoom1_Text_27BC16, 4
	releaseall
	return

LinkContestRoom1_Movement_27AD09: @ 827AD09
	step_down
	step_end

LinkContestRoom1_Movement_27AD0B: @ 827AD0B
	step_40
	step_up
	step_41
	step_end

LinkContestRoom1_Movement_27AD0F: @ 827AD0F
	step_28
	step_end

LinkContestRoom1_Movement_27AD11: @ 827AD11
	step_58
	step_end

LinkContestRoom1_Movement_27AD13: @ 827AD13
	step_25
	step_end

LinkContestRoom1_Movement_27AD15: @ 827AD15
	step_left
	step_left
	step_25
	step_end

LinkContestRoom1_Movement_27AD19: @ 827AD19
	step_right
	step_right
	step_25
	step_end

LinkContestRoom1_Movement_27AD1D: @ 827AD1D
	step_up
	step_25
	step_end

LinkContestRoom1_Movement_27AD20: @ 827AD20
	step_14
	step_14
	step_end

LinkContestRoom1_Movement_27AD23: @ 827AD23
	step_28
	step_end

LinkContestRoom1_Movement_27AD25: @ 827AD25
	step_27
	step_end

LinkContestRoom1_Movement_27AD27: @ 827AD27
	step_25
	step_end

LinkContestRoom1_Movement_27AD29: @ 827AD29
	step_left
	step_left
	step_up
	step_end

LinkContestRoom1_Movement_27AD2D: @ 827AD2D
	step_left
	step_left
	step_left
	step_left
	step_up
	step_end

LinkContestRoom1_Movement_27AD33: @ 827AD33
	step_02
	step_14
	step_4e
	step_end

LinkContestRoom1_Movement_27AD37: @ 827AD37
	step_01
	step_14
	step_4e
	step_end

LinkContestRoom1_Movement_27AD3B: @ 827AD3B
	step_03
	step_14
	step_4e
	step_end

LinkContestRoom1_Movement_27AD3F: @ 827AD3F
	step_00
	step_14
	step_4e
	step_end

LinkContestRoom1_Movement_27AD43: @ 827AD43
	step_01
	step_end

LinkContestRoom1_Movement_27AD45: @ 827AD45
	step_01
	step_14
	step_28
	step_end

LinkContestRoom1_Movement_27AD49: @ 827AD49
	step_27
	step_14
	step_14
	step_25
	step_end

LinkContestRoom1_Movement_27AD4E: @ 827AD4E
	step_14
	step_14
	step_25
	step_end

LinkContestRoom1_Movement_27AD52: @ 827AD52
	step_up
	step_right
	step_right
	step_right
	step_26
	step_end

LinkContestRoom1_Movement_27AD58: @ 827AD58
	step_17
	step_17
	step_17
	step_15
	step_26
	step_end

LinkContestRoom1_Movement_27AD5E: @ 827AD5E
	step_up
	step_right
	step_26
	step_end

LinkContestRoom1_Movement_27AD62: @ 827AD62
	step_17
	step_15
	step_26
	step_end

LinkContestRoom1_Movement_27AD66: @ 827AD66
	step_up
	step_left
	step_26
	step_end

LinkContestRoom1_Movement_27AD6A: @ 827AD6A
	step_18
	step_15
	step_26
	step_end

LinkContestRoom1_Movement_27AD6E: @ 827AD6E
	step_up
	step_left
	step_left
	step_left
	step_26
	step_end

LinkContestRoom1_Movement_27AD74: @ 827AD74
	step_18
	step_18
	step_18
	step_15
	step_26
	step_end

LinkContestRoom1_Movement_27AD7A: @ 827AD7A
	step_right
	step_right
	step_up
	step_end

LinkContestRoom1_Movement_27AD7E: @ 827AD7E
	step_up
	step_end

LinkContestRoom1_EventScript_27AD80:: @ 827AD80
	specialvar VAR_RESULT, sub_80F9134
	compare_var_to_value VAR_RESULT, 1
	goto_eq LinkContestRoom1_EventScript_27AD91
	return

LinkContestRoom1_EventScript_27AD91:: @ 827AD91
	return

LilycoveCity_ContestLobby_EventScript_27AD92:: @ 827AD92
	specialvar VAR_RESULT, sub_80F9134
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_27ADA3
	return

LilycoveCity_ContestLobby_EventScript_27ADA3:: @ 827ADA3
	delay 9
	return

LilycoveCity_ContestLobby_Text_27ADA7: @ 827ADA7
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.\p"
	.string "Oh? It appears that you don’t have\n"
	.string "a {POKEBLOCK} CASE yet.\p"
	.string "In that case, we need to provide you\n"
	.string "with this!$"

LilycoveCity_ContestLobby_Text_27AE47: @ 827AE47
	.string "Okay, now that we’ve cleared that\n"
	.string "up…\p"
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

LilycoveCity_ContestLobby_Text_27AEA8: @ 827AEA8
	.string "Hello!\p"
	.string "This is the reception counter for\n"
	.string "POKéMON CONTESTS.$"

	.incbin "baserom.gba", 0x27aee3, 0x45

LilycoveCity_ContestLobby_Text_27AF28: @ 827AF28
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"

LilycoveCity_ContestLobby_Text_27AF5E: @ 827AF5E
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_27AF7A: @ 827AF7A
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"

LilycoveCity_ContestLobby_Text_27B17D: @ 827B17D
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"

LilycoveCity_ContestLobby_Text_27B221: @ 827B221
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER, and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up to the SUPER Rank\l"
	.string "in the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and\l"
	.string "a HYPER Rank winner can advance to\l"
	.string "the MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"

LilycoveCity_ContestLobby_Text_27B3FF: @ 827B3FF
	.string "Which Rank would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B423: @ 827B423
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B44A: @ 827B44A
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_27B471: @ 827B471
	.string "I’m terribly sorry, but your POKéMON\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"

LilycoveCity_ContestLobby_Text_27B4C4: @ 827B4C4
	.string "I’m sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_27B501: @ 827B501
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_27B547: @ 827B547
	.string "Oh, but that RIBBON…\p"
	.string "Your POKéMON has won this CONTEST\n"
	.string "before, hasn’t it?\p"
	.string "Would you like to enter it in this\n"
	.string "CONTEST anyway?$"

	.incbin "baserom.gba", 0x27b5c4, 0x1e

LilycoveCity_ContestLobby_Text_27B5E2: @ 827B5E2
	.string "Okay, your POKéMON will be entered\n"
	.string "in this CONTEST.\p"
	.string "Your POKéMON is Entry No. 4.\n"
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_27B653: @ 827B653
	.string "Please come in through here.\n"
	.string "Good luck!$"

LilycoveCity_ContestLobby_Text_27B67B: @ 827B67B
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"

LilycoveCity_ContestLobby_Text_27B6E7: @ 827B6E7
	.string "Please come back for your prize\n"
	.string "later on.$"

LinkContestRoom1_Text_27B711: @ 827B711
	.string "MC: Hello! We’re just getting started\n"
	.string "with a {STR_VAR_3} Rank POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27B78F: @ 827B78F
	.string "MC: Hello! We’re just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!\p"
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27B815: @ 827B815
	.string "MC: Entry No. {STR_VAR_2}!\n"
	.string "{STR_VAR_1}’s {STR_VAR_3}!$"

LinkContestRoom1_Text_27B830: @ 827B830
	.string "MC: We’ve just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it’s time for primary judging!\p"
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.\p"
	.string "Without any further ado, let the\n"
	.string "voting begin!$"

LinkContestRoom1_Text_27B8F2: @ 827B8F2
	.string "Voting under way…$"

LinkContestRoom1_Text_27B904: @ 827B904
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let’s move on to secondary judging!\p"
	.string "The second stage of judging is the\n"
	.string "much anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!\p"
	.string "Let’s see a little enthusiasm!\n"
	.string "Let’s appeal!$"

LinkContestRoom1_Text_27BA15: @ 827BA15
	.string "MC: That’s it for judging!$"

LinkContestRoom1_Text_27BA30: @ 827BA30
	.string "Thank you all for a most wonderful\n"
	.string "display of quality appeals!\p"
	.string "This concludes all judging!\n"
	.string "Thank you for your fine efforts!$"

LinkContestRoom1_Text_27BAAC: @ 827BAAC
	.string "Now, all that remains is the pulse-\n"
	.string "pounding proclamation of the winner.\p"
	.string "The JUDGE looks ready to make\n"
	.string "the announcement!$"

LinkContestRoom1_Text_27BB25: @ 827BB25
	.string "JUDGE: We will now declare the winner!$"

LinkContestRoom1_Text_27BB4C: @ 827BB4C
	.string "MC: Entry No. {STR_VAR_2}!\p"
	.string "{STR_VAR_3} and {STR_VAR_1},\n"
	.string "congratulations!$"

LinkContestRoom1_Text_27BB7A: @ 827BB7A
	.string "MC: Congratulations!\n"
	.string "Please do compete again!$"

LinkContestRoom1_Text_27BBA8: @ 827BBA8
	.string "MC: Here you are!\n"
	.string "Please accept your prize!$"

LinkContestRoom1_Text_27BBD4: @ 827BBD4
	.string "We confer on you this RIBBON\n"
	.string "as your prize!$"

LinkContestRoom1_Text_27BC00: @ 827BC00
	.string "{PLAYER} received a RIBBON.$"

LinkContestRoom1_Text_27BC16: @ 827BC16
	.string "{PLAYER} put the RIBBON on\n"
	.string "{STR_VAR_1}.$"

LinkContestRoom1_Text_27BC2F: @ 827BC2F
	.string "Please pick up your prize at\n"
	.string "the reception counter later.\l"
	.string "Please do compete again!$"

	.incbin "baserom.gba", 0x27bc82, 0x95

LilycoveCity_ContestLobby_Text_27BD17: @ 827BD17
	.string "Before entering a CONTEST, your\n"
	.string "progress will be saved.$"

LilycoveCity_ContestLobby_Text_27BD4F: @ 827BD4F
	.string "We hope you will participate another\n"
	.string "time.$"

	.incbin "baserom.gba", 0x27bd7a, 0x172

LilycoveCity_ContestLobby_Text_27BEEC: @ 827BEEC
	.string "Transmitting…$"

LilycoveCity_ContestLobby_Text_27BEFA: @ 827BEFA
	.string "Transmission error…$"

LilycoveCity_ContestLobby_Text_27BF0E: @ 827BF0E
	.string "You may have chosen a different\n"
	.string "CONTEST than another player.$"

LilycoveCity_ContestLobby_Text_27BF4B: @ 827BF4B
	.string "You may have made a different\n"
	.string "choice than another player.$"

LilycoveCity_ContestLobby_Text_27BF85: @ 827BF85
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

	.incbin "baserom.gba", 0x27bfa7, 0x51

LilycoveCity_ContestLobby_Text_27BFF8: @ 827BFF8
	.string "Your POKéMON will be entered in\n"
	.string "the CONTEST.\p"
	.string "Your POKéMON is Entry No. {STR_VAR_2}.$"

LilycoveCity_ContestLobby_Text_27C043: @ 827C043
	.string "The CONTEST will begin shortly.$"

LilycoveCity_ContestLobby_Text_27C063: @ 827C063
	.string "Welcome! This is the POKéMON CONTEST\n"
	.string "link reception counter.\p"
	.string "You may enter CONTESTS together with\n"
	.string "one or more friends.$"

LilycoveCity_ContestLobby_Text_27C0DA: @ 827C0DA
	.string "Which topic would you like?$"

LilycoveCity_ContestLobby_Text_27C0F6: @ 827C0F6
	.string "Would you like to enter a CONTEST?$"

LilycoveCity_ContestLobby_Text_27C119: @ 827C119
	.string "Which CONTEST would you like to enter?$"

LilycoveCity_ContestLobby_Text_27C140: @ 827C140
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"

LilycoveCity_ContestLobby_Text_27C186: @ 827C186
	.string "I’m sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"

LilycoveCity_ContestLobby_Text_27C1C3: @ 827C1C3
	.string "Which POKéMON would you like to enter?$"

LilycoveCity_ContestLobby_Text_27C1EA: @ 827C1EA
	.string "Please decide which of you will\n"
	.string "become the GROUP LEADER.\p"
	.string "The other players must then choose\n"
	.string "“JOIN GROUP.”$"

LilycoveCity_ContestLobby_Text_27C254: @ 827C254
	.string "At least one player has entered using\n"
	.string "the 4-player reception counter.\p"
	.string "There must be four players connected\n"
	.string "using a GBA Game Link cable.\p"
	.string "When the four players are ready,\n"
	.string "select G-MODE (GLOBAL MODE),\l"
	.string "then register to enter again, please.$"

LilycoveCity_ContestLobby_Text_27C340: @ 827C340
	.string "This is a CONTEST for two to four\n"
	.string "players linked using a Wireless\l"
	.string "Adapter or a GBA Game Link cable.\p"
	.string "Participants are first asked to choose\n"
	.string "the mode they wish to enter.\p"
	.string "There are two different modes.\p"
	.string "E-MODE (EMERALD MODE) is for\n"
	.string "two to four players, each with a\l"
	.string "POKéMON Emerald Game Pak.\p"
	.string "G-MODE (GLOBAL MODE) is only for\n"
	.string "four players, each with a POKéMON\l"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The players should discuss which mode\n"
	.string "they want, then choose the same mode.\p"
	.string "Once all the players have chosen\n"
	.string "the same CONTEST in the same mode,\l"
	.string "the entry registration is complete.\p"
	.string "After that, a CONTEST will start in\n"
	.string "the usual manner.$"

LilycoveCity_ContestLobby_Text_27C5B1: @ 827C5B1
	.string "In E-MODE (EMERALD MODE),\n"
	.string "a LINK CONTEST can be held with\l"
	.string "two to four players. Each player must\l"
	.string "have a POKéMON Emerald Game Pak.\p"
	.string "The players must be linked with each\n"
	.string "other using Wireless Adapters or\l"
	.string "GBA Game Link cables.\p"
	.string "If there are fewer than four players,\n"
	.string "TRAINERS in the hall will join to fill\l"
	.string "the 4-player CONTEST lineup.\p"
	.string "Please be aware that E-MODE is not\n"
	.string "available in POKéMON Ruby or Sapphire.$"

LilycoveCity_ContestLobby_Text_27C742: @ 827C742
	.string "G-MODE (GLOBAL MODE) is specifically\n"
	.string "for four players who are linked using\l"
	.string "GBA Game Link cables.\p"
	.string "Each player must have a POKéMON\n"
	.string "Emerald, Ruby, or Sapphire Game Pak.\p"
	.string "The CONTEST starts after all players\n"
	.string "choose G-MODE (POKéMON Emerald) or\l"
	.string "enter through the 4-player reception\l"
	.string "counter (POKéMON Ruby or Sapphire).$"

LilycoveCity_ContestLobby_Text_27C879: @ 827C879
	.string "I’m terribly sorry.\p"
	.string "G-MODE does not function\n"
	.string "with Wireless Adapters.\p"
	.string "Please select E-MODE or try\n"
	.string "again using a GBA Game Link cable.$"

LilycoveCity_ContestLobby_Text_27C8FD: @ 827C8FD
	.string "Which CONTEST MODE would you like\n"
	.string "to enter?$"

LinkContestRoom1_Text_27C929: @ 827C929
	.string "MC: Hello! We’re just getting started\n"
	.string "with a 4-player linked POKéMON\l"
	.string "{STR_VAR_2}!$"

LinkContestRoom1_Text_27C972: @ 827C972
	.string "The participating TRAINERS and their\n"
	.string "POKéMON are as follows:$"

LinkContestRoom1_Text_27C9AF: @ 827C9AF
	.string "MC: We’ve just seen the four POKéMON\n"
	.string "contestants.\p"
	.string "Now it’s time for primary judging!$"

LinkContestRoom1_Text_27CA04: @ 827CA04
	.string "The audience will vote on their\n"
	.string "favorite POKéMON contestants.$"

LinkContestRoom1_Text_27CA42: @ 827CA42
	.string "Without any further ado,\n"
	.string "let the voting begin!$"

LinkContestRoom1_Text_27CA71: @ 827CA71
	.string "Voting is now complete!\p"
	.string "While the votes are being tallied,\n"
	.string "let’s move on to secondary judging!$"

LinkContestRoom1_Text_27CAD0: @ 827CAD0
	.string "The second stage of judging is\n"
	.string "the much-anticipated appeal time!\p"
	.string "May the contestants amaze us with\n"
	.string "superb appeals of dazzling moves!$"

LinkContestRoom1_Text_27CB55: @ 827CB55
	.string "Let’s see a little enthusiasm!\n"
	.string "Let’s appeal!$"

@ 827CB82
	.include "data/text/contest_text.inc"

gUnknown_0827D507:: @ 827D507
	.incbin "baserom.gba", 0x27d507, 0x2a

gUnknown_0827D531:: @ 827D531
	.incbin "baserom.gba", 0x27d531, 0x29

gUnknown_0827D55A:: @ 827D55A
	.incbin "baserom.gba", 0x27d55a, 0x15

gUnknown_0827D56F:: @ 827D56F
	.incbin "baserom.gba", 0x27d56f, 0x28

gUnknown_0827D597:: @ 827D597
	.incbin "baserom.gba", 0x27d597, 0xd67

gUnknown_0827E2FE:: @ 827E2FE
	.incbin "baserom.gba", 0x27e2fe, 0x30

gUnknown_0827E32E:: @ 827E32E
	.incbin "baserom.gba", 0x27e32e, 0x2d

gUnknown_0827E35B:: @ 827E35B
	.incbin "baserom.gba", 0x27e35b, 0x32

gUnknown_0827E38D:: @ 827E38D
	.incbin "baserom.gba", 0x27e38d, 0x1fd

gUnknown_0827E58A:: @ 827E58A
	.incbin "baserom.gba", 0x27e58a, 0x159

gUnknown_0827E6E3:: @ 827E6E3
	.incbin "baserom.gba", 0x27e6e3, 0x34

gUnknown_0827E717:: @ 827E717
	.incbin "baserom.gba", 0x27e717, 0x25

gUnknown_0827E73C:: @ 827E73C
	.incbin "baserom.gba", 0x27e73c, 0x2e

gUnknown_0827E76A:: @ 827E76A
	.incbin "baserom.gba", 0x27e76a, 0x29

gUnknown_0827E793:: @ 827E793
	.incbin "baserom.gba", 0x27e793, 0x57

gUnknown_0827E7EA:: @ 827E7EA
	.incbin "baserom.gba", 0x27e7ea, 0x2d

gUnknown_0827E817:: @ 827E817
	.incbin "baserom.gba", 0x27e817, 0x20

gUnknown_0827E837:: @ 827E837
	.incbin "baserom.gba", 0x27e837, 0x8

gUnknown_0827E83F:: @ 827E83F
	.incbin "baserom.gba", 0x27e83f, 0x8

gUnknown_0827E847:: @ 827E847
	.incbin "baserom.gba", 0x27e847, 0x9

gUnknown_0827E850:: @ 827E850
	.incbin "baserom.gba", 0x27e850, 0xa

gUnknown_0827E85A:: @ 827E85A
	.incbin "baserom.gba", 0x27e85a, 0x80

gUnknown_0827E8DA:: @ 827E8DA
	.incbin "baserom.gba", 0x27e8da, 0x132

gUnknown_0827EA0C:: @ 827EA0C
	.incbin "baserom.gba", 0x27ea0c, 0x2b0

gUnknown_0827ECBC:: @ 27ECBC
	.incbin "baserom.gba", 0x27ecbc, 0x7

gUnknown_0827ECC3:: @ 27ECC3
	.incbin "baserom.gba", 0x27ecc3, 0xa

gUnknown_0827ECCD:: @ 27ECCD
	.incbin "baserom.gba", 0x27eccd, 0x8

gUnknown_0827ECD5:: @ 27ECD5
	.incbin "baserom.gba", 0x27ecd5, 0x8

gUnknown_0827ECDD:: @ 27ECDD
	.incbin "baserom.gba", 0x27ecdd, 0x6

gUnknown_0827ECE3:: @ 27ECE3
	.incbin "baserom.gba", 0x27ece3, 0x8

gUnknown_0827ECEB:: @ 27ECEB
	.incbin "baserom.gba", 0x27eceb, 0x7

gUnknown_0827ECF2:: @ 27ECF2
	.incbin "baserom.gba", 0x27ecf2, 0x6

gUnknown_0827ECF8:: @ 27ECF8
	.incbin "baserom.gba", 0x27ecf8, 0x8

gUnknown_0827ED00:: @ 27ED00
	.incbin "baserom.gba", 0x27ed00, 0x6

gUnknown_0827ED06:: @ 27ED06
	.incbin "baserom.gba", 0x27ed06, 0xa

gUnknown_0827ED10:: @ 27ED10
	.incbin "baserom.gba", 0x27ed10, 0x8

gUnknown_0827ED18:: @ 27ED18
	.incbin "baserom.gba", 0x27ed18, 0xa

gUnknown_0827ED22:: @ 27ED22
	.incbin "baserom.gba", 0x27ed22, 0xa

gUnknown_0827ED2C:: @ 27ED2C
	.incbin "baserom.gba", 0x27ed2c, 0xa

gUnknown_0827ED36:: @ 27ED36
	.incbin "baserom.gba", 0x27ed36, 0xa

gUnknown_0827ED40:: @ 27ED40
	.incbin "baserom.gba", 0x27ed40, 0x6

gUnknown_0827ED46:: @ 27ED46
	.incbin "baserom.gba", 0x27ed46, 0x9

gUnknown_0827ED4F:: @ 27ED4F
	.incbin "baserom.gba", 0x27ed4f, 0xa

gUnknown_0827ED59:: @ 27ED59
	.incbin "baserom.gba", 0x27ed59, 0xc

gUnknown_0827ED65:: @ 27ED65
	.incbin "baserom.gba", 0x27ed65, 0xb

gUnknown_0827ED70:: @ 27ED70
	.incbin "baserom.gba", 0x27ed70, 0x4

gUnknown_0827ED74:: @ 27ED74
	.incbin "baserom.gba", 0x27ed74, 0x4

gUnknown_0827ED78:: @ 27ED78
	.incbin "baserom.gba", 0x27ed78, 0x8

gUnknown_0827ED80:: @ 27ED80
	.incbin "baserom.gba", 0x27ed80, 0x15

gUnknown_0827ED95:: @ 27ED95
	.incbin "baserom.gba", 0x27ed95, 0x15

gUnknown_0827EDAA:: @ 27EDAA
	.incbin "baserom.gba", 0x27edaa, 0xb

gUnknown_0827EDB5:: @ 27EDB5
	.incbin "baserom.gba", 0x27edb5, 0x5

gUnknown_0827EDBA:: @ 27EDBA
	.incbin "baserom.gba", 0x27edba, 0x7

gUnknown_0827EDC1:: @ 27EDC1
	.incbin "baserom.gba", 0x27edc1, 0x8

gUnknown_0827EDC9:: @ 27EDC9
	.incbin "baserom.gba", 0x27edc9, 0xc

gUnknown_0827EDD5:: @ 27EDD5
	.incbin "baserom.gba", 0x27edd5, 0xf

gUnknown_0827EDE4:: @ 27EDE4
	.incbin "baserom.gba", 0x27ede4, 0xc

gUnknown_0827EDF0:: @ 27EDF0
	.incbin "baserom.gba", 0x27edf0, 0x5

gUnknown_0827EDF5:: @ 27EDF5
	.incbin "baserom.gba", 0x27edf5, 0x2

gUnknown_0827EDF7:: @ 27EDF7
	.incbin "baserom.gba", 0x27edf7, 0x2

gUnknown_0827EDF9:: @ 27EDF9
	.incbin "baserom.gba", 0x27edf9, 0x2

gUnknown_0827EDFB:: @ 27EDFB
	.incbin "baserom.gba", 0x27edfb, 0x2

gUnknown_0827EDFD:: @ 27EDFD
	.incbin "baserom.gba", 0x27edfd, 0x2

gUnknown_0827EDFF:: @ 27EDFF
	.incbin "baserom.gba", 0x27edff, 0x2

gUnknown_0827EE01:: @ 27EE01
	.incbin "baserom.gba", 0x27ee01, 0x2

gUnknown_0827EE03:: @ 27EE03
	.incbin "baserom.gba", 0x27ee03, 0x2

gUnknown_0827EE05:: @ 27EE05
	.incbin "baserom.gba", 0x27ee05, 0x2

gUnknown_0827EE07:: @ 27EE07
	.incbin "baserom.gba", 0x27ee07, 0x2

gUnknown_0827EE09:: @ 27EE09
	.incbin "baserom.gba", 0x27ee09, 0x2

gUnknown_0827EE0B:: @ 827EE0B

	.incbin "baserom.gba", 0x27ee0b, 0x10a

LilycoveCity_ContestLobby_Text_27EF15: @ 827EF15
	.string "Oh, hello! You were in a POKéMON\n"
	.string "CONTEST, weren’t you?\l"
	.string "It’s easy to tell from your POKéMON.\p"
	.string "I’m a reporter. I’m working on a story\n"
	.string "on POKéMON CONTESTS.\p"
	.string "If I may, would you be willing to answer\n"
	.string "a few questions?$"

LilycoveCity_ContestLobby_Text_27EFE7: @ 827EFE7
	.string "Oh, you will?\n"
	.string "Thank you.\p"
	.string "Briefly, how would you describe the\n"
	.string "CONTEST you just entered?$"

LilycoveCity_ContestLobby_Text_27F03E: @ 827F03E
	.string "Ah, I see.\n"
	.string "That’s a very edifying comment.\p"
	.string "You get a good feel for what\n"
	.string "the CONTEST was like.\p"
	.string "I’ve got one last question.\p"
	.string "When you hear the word “{STR_VAR_2},”\n"
	.string "what image do you get?$"

LilycoveCity_ContestLobby_Text_27F0EC: @ 827F0EC
	.string "I see!\p"
	.string "So that’s how you imagine the concept\n"
	.string "of “{STR_VAR_2}” to be.\p"
	.string "Thank you!\n"
	.string "You’ve given me some good ideas.\p"
	.string "I think I can write a good story on\n"
	.string "POKéMON CONTESTS now.\p"
	.string "Maybe, just maybe, this story will even\n"
	.string "make it to television.\l"
	.string "I hope you’ll look forward to it!$"

LilycoveCity_ContestLobby_Text_27F1EF: @ 827F1EF
	.string "Oh, too bad…\p"
	.string "Well, if you come across a good story,\n"
	.string "please do share it with me.$"

LilycoveCity_ContestLobby_Text_27F23F: @ 827F23F
	.string "I’ll be looking forward to your next\n"
	.string "POKéMON CONTEST.$"

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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C879
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280674, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C827
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C866
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C939
	copyvar VAR_0x8009, VAR_0x8006
	checkflag FLAG_0x069
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8C8
	setflag FLAG_0x069
	msgbox SlateportCity_OceanicMuseum_1F_Text_2811A0, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare_var_to_value VAR_RESULT, 0
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C91C
	end

SlateportCity_OceanicMuseum_1F_EventScript_28C8C8:: @ 828C8C8
	msgbox SlateportCity_OceanicMuseum_1F_Text_28126D, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C8E7
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_OceanicMuseum_1F_EventScript_28C926
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C7F0
	setvar VAR_0x8005, 3
	special InterviewBefore
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA4F
	copyvar VAR_0x8009, VAR_0x8006
	msgbox SlateportCity_PokemonFanClub_Text_280270, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq SlateportCity_PokemonFanClub_EventScript_28C98C
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_28CA45
	msgbox SlateportCity_PokemonFanClub_Text_2804AC, 4
	setvar VAR_0x8006, 1
	call SlateportCity_PokemonFanClub_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CB21
	copyvar VAR_0x8009, VAR_0x8006
	msgbox LilycoveCity_ContestLobby_Text_27EF15, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CA9B
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_28CADA
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_0x4086, 2
	goto_if 5, LilycoveCity_ContestLobby_EventScript_28CB95
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC7A
	copyvar VAR_0x8009, VAR_0x8006
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F704, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CBD8
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC2E
	end

BattleFrontier_BattleTowerLobby_EventScript_28CBD8:: @ 828CBD8
	message BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F7BA
	waitmessage
	multichoice 20, 8, 45, 1
	copyvar VAR_0x8008, VAR_RESULT
	compare_var_to_value VAR_RESULT, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_28CC38
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_28CC41
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F97A, 4
	setvar VAR_0x8004, 12
	copyvar VAR_0x8005, VAR_0x8009
	call BattleFrontier_BattleTowerLobby_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC4A
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC2E:: @ 828CC2E
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F84C, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC38:: @ 828CC38
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F8AE, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_28CC41:: @ 828CC41
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F921, 4
	return

BattleFrontier_BattleTowerLobby_EventScript_28CC4A:: @ 828CC4A
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CC70
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27F9FD, 4
	setflag FLAG_0x002
	copyvar VAR_0x8004, VAR_0x8008
	setvar VAR_0x8005, 7
	goto BattleFrontier_BattleTowerLobby_EventScript_28C7E9
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC70:: @ 828CC70
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27FA6F, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC7A:: @ 828CC7A
	msgbox BATTLE_FRONTIER_BATTLE_TOWER_LOBBY_Text_27FAF3, 4
	release
	end

BattleFrontier_BattleTowerLobby_EventScript_28CC84:: @ 828CC84
	compare_var_to_value VAR_0x40BC, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
	setvar VAR_0x8005, 7
	special InterviewBefore
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_28CCA6
	clearflag FLAG_0x396
	return

BattleFrontier_BattleTowerLobby_EventScript_28CCA6:: @ 828CCA6
	setflag FLAG_0x396
	return

	.incbin "baserom.gba", 0x28ccaa, 0x1d

Route111_EventScript_28CCC7:: @ 828CCC7
Route118_EventScript_28CCC7:: @ 828CCC7
Route120_EventScript_28CCC7:: @ 828CCC7
	cleartrainerflag TRAINER_GABBY_AND_TY_6
	specialvar VAR_RESULT, GabbyAndTyGetBattleNum
	switch VAR_RESULT
	case 0, Route111_EventScript_28CD38
	case 1, Route111_EventScript_28CD3E
	case 2, Route111_EventScript_28CD49
	case 3, Route111_EventScript_28CD54
	case 4, Route111_EventScript_28CD5F
	case 5, Route111_EventScript_28CD6A
	case 6, Route111_EventScript_28CD75
	case 7, Route111_EventScript_28CD80
	case 8, Route111_EventScript_28CD8B
	end

Route111_EventScript_28CD38:: @ 828CD38
	call Route111_EventScript_28CD9A
	return

Route111_EventScript_28CD3E:: @ 828CD3E
	call Route111_EventScript_28CDA2
	call Route111_EventScript_28CD96
	return

Route111_EventScript_28CD49:: @ 828CD49
	call Route111_EventScript_28CDAA
	call Route111_EventScript_28CD9E
	return

Route111_EventScript_28CD54:: @ 828CD54
	call Route111_EventScript_28CDB2
	call Route111_EventScript_28CDA6
	return

Route111_EventScript_28CD5F:: @ 828CD5F
	call Route111_EventScript_28CDBA
	call Route111_EventScript_28CDAE
	return

Route111_EventScript_28CD6A:: @ 828CD6A
	call Route111_EventScript_28CDC2
	call Route111_EventScript_28CDB6
	return

Route111_EventScript_28CD75:: @ 828CD75
	call Route111_EventScript_28CDCA
	call Route111_EventScript_28CDBE
	return

Route111_EventScript_28CD80:: @ 828CD80
	call Route111_EventScript_28CDD2
	call Route111_EventScript_28CDC6
	return

Route111_EventScript_28CD8B:: @ 828CD8B
	call Route111_EventScript_28CDC2
	call Route111_EventScript_28CDCE
	return

Route111_EventScript_28CD96:: @ 828CD96
	setflag FLAG_0x31C
	return

Route111_EventScript_28CD9A:: @ 828CD9A
	clearflag FLAG_0x31C
	return

Route111_EventScript_28CD9E:: @ 828CD9E
	setflag FLAG_0x31D
	return

Route111_EventScript_28CDA2:: @ 828CDA2
	clearflag FLAG_0x31D
	return

Route111_EventScript_28CDA6:: @ 828CDA6
	setflag FLAG_0x31E
	return

Route111_EventScript_28CDAA:: @ 828CDAA
	clearflag FLAG_0x31E
	return

Route111_EventScript_28CDAE:: @ 828CDAE
	setflag FLAG_0x31F
	return

Route111_EventScript_28CDB2:: @ 828CDB2
	clearflag FLAG_0x31F
	return

Route111_EventScript_28CDB6:: @ 828CDB6
	setflag FLAG_0x385
	return

Route111_EventScript_28CDBA:: @ 828CDBA
	clearflag FLAG_0x385
	return

Route111_EventScript_28CDBE:: @ 828CDBE
	setflag FLAG_0x386
	return

Route111_EventScript_28CDC2:: @ 828CDC2
	clearflag FLAG_0x386
	return

Route111_EventScript_28CDC6:: @ 828CDC6
	setflag FLAG_0x387
	return

Route111_EventScript_28CDCA:: @ 828CDCA
	clearflag FLAG_0x387
	return

Route111_EventScript_28CDCE:: @ 828CDCE
	setflag FLAG_0x388
	return

Route111_EventScript_28CDD2:: @ 828CDD2
	clearflag FLAG_0x388
	return

Route111_EventScript_28CDD6:: @ 828CDD6
	trainerbattle 6, TRAINER_GABBY_AND_TY_1, 0, Route111_Text_28AF05, Route111_Text_28B000, Route111_Text_28B5EC, Route111_EventScript_28CF56
	msgbox Route111_Text_28B5C0, 4
	release
	end

Route111_EventScript_28CDF6:: @ 828CDF6
	trainerbattle 6, TRAINER_GABBY_AND_TY_1, 0, Route111_Text_28B75C, Route111_Text_28B8B1, Route111_Text_28B841, Route111_EventScript_28CF56
	msgbox Route111_Text_28B805, 4
	release
	end

Route118_EventScript_28CE16:: @ 828CE16
	trainerbattle 6, TRAINER_GABBY_AND_TY_2, 0, Route118_Text_28AF7D, Route118_Text_28B719, Route118_Text_28B5EC, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B5C0, 4
	release
	end

Route118_EventScript_28CE36:: @ 828CE36
	trainerbattle 6, TRAINER_GABBY_AND_TY_2, 0, Route118_Text_28B7B1, Route118_Text_28B8F6, Route118_Text_28B841, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B805, 4
	release
	end

Route120_EventScript_28CE56:: @ 828CE56
	trainerbattle 6, TRAINER_GABBY_AND_TY_3, 0, Route120_Text_28AF7D, Route120_Text_28B719, Route120_Text_28B5EC, Route120_EventScript_28CFC3
	msgbox Route120_Text_28B5C0, 4
	release
	end

Route120_EventScript_28CE76:: @ 828CE76
	trainerbattle 6, TRAINER_GABBY_AND_TY_3, 0, Route120_Text_28B7B1, Route120_Text_28B8F6, Route120_Text_28B841, Route120_EventScript_28CFC3
	msgbox Route120_Text_28B805, 4
	release
	end

Route111_EventScript_28CE96:: @ 828CE96
	trainerbattle 6, TRAINER_GABBY_AND_TY_4, 0, Route111_Text_28AF7D, Route111_Text_28B719, Route111_Text_28B5EC, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B5C0, 4
	release
	end

Route111_EventScript_28CEB6:: @ 828CEB6
	trainerbattle 6, TRAINER_GABBY_AND_TY_4, 0, Route111_Text_28B7B1, Route111_Text_28B8F6, Route111_Text_28B841, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B805, 4
	release
	end

Route118_EventScript_28CED6:: @ 828CED6
	trainerbattle 6, TRAINER_GABBY_AND_TY_5, 0, Route118_Text_28AF7D, Route118_Text_28B719, Route118_Text_28B5EC, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B5C0, 4
	release
	end

Route118_EventScript_28CEF6:: @ 828CEF6
	trainerbattle 6, TRAINER_GABBY_AND_TY_5, 0, Route118_Text_28B7B1, Route118_Text_28B8F6, Route118_Text_28B841, Route118_EventScript_28CFC3
	msgbox Route118_Text_28B805, 4
	release
	end

Route111_EventScript_28CF16:: @ 828CF16
Route118_EventScript_28CF16:: @ 828CF16
Route120_EventScript_28CF16:: @ 828CF16
	trainerbattle 6, TRAINER_GABBY_AND_TY_6, 0, Route111_Text_28AF7D, Route111_Text_28B719, Route111_Text_28B5EC, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B5C0, 4
	release
	end

Route111_EventScript_28CF36:: @ 828CF36
Route118_EventScript_28CF36:: @ 828CF36
Route120_EventScript_28CF36:: @ 828CF36
	trainerbattle 6, TRAINER_GABBY_AND_TY_6, 0, Route111_Text_28B7B1, Route111_Text_28B8F6, Route111_Text_28B841, Route111_EventScript_28CFC3
	msgbox Route111_Text_28B805, 4
	release
	end

Route111_EventScript_28CF56:: @ 828CF56
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToFieldObjectLocalIds
	compare_var_to_value VAR_FACING, 2
	call_if 1, Route111_EventScript_28CF94
	compare_var_to_value VAR_FACING, 1
	call_if 1, Route111_EventScript_28CF9F
	compare_var_to_value VAR_FACING, 4
	call_if 1, Route111_EventScript_28CFB1
	checkflag FLAG_0x001
	goto_eq Route111_EventScript_28D0EE
	msgbox Route111_Text_28B042, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28CF94:: @ 828CF94
	applymovement VAR_0x8004, Route111_Movement_28D04D
	waitmovement 0
	return

Route111_EventScript_28CF9F:: @ 828CF9F
	applymovement VAR_0x8004, Route111_Movement_28D04F
	applymovement VAR_0x8005, Route111_Movement_2725A6
	waitmovement 0
	return

Route111_EventScript_28CFB1:: @ 828CFB1
	applymovement VAR_0x8004, Route111_Movement_28D051
	applymovement VAR_0x8005, Route111_Movement_2725A4
	waitmovement 0
	return

Route111_EventScript_28CFC3:: @ 828CFC3
Route118_EventScript_28CFC3:: @ 828CFC3
Route120_EventScript_28CFC3:: @ 828CFC3
	special GabbyAndTyBeforeInterview
	special GabbyAndTySetScriptVarsToFieldObjectLocalIds
	compare_var_to_value VAR_FACING, 2
	call_if 1, Route111_EventScript_28CF94
	compare_var_to_value VAR_FACING, 1
	call_if 1, Route111_EventScript_28CF9F
	compare_var_to_value VAR_FACING, 4
	call_if 1, Route111_EventScript_28CFB1
	checkflag FLAG_0x001
	goto_eq Route111_EventScript_28D0EE
	specialvar VAR_RESULT, GabbyAndTyGetLastQuote
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_28D053
	msgbox Route111_Text_28B137, 4
	specialvar VAR_RESULT, GabbyAndTyGetLastBattleTrivia
	switch VAR_RESULT
	case 0, Route111_EventScript_28D061
	case 1, Route111_EventScript_28D06F
	case 2, Route111_EventScript_28D07D
	case 3, Route111_EventScript_28D08B
	case 4, Route111_EventScript_28D099
	end

Route111_Movement_28D04D: @ 828D04D
	step_1d
	step_end

Route111_Movement_28D04F: @ 828D04F
	step_1e
	step_end

Route111_Movement_28D051: @ 828D051
	step_1f
	step_end

Route111_EventScript_28D053:: @ 828D053
	msgbox Route111_Text_28B62D, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D061:: @ 828D061
	msgbox Route111_Text_28B3F3, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D06F:: @ 828D06F
	msgbox Route111_Text_28B1B3, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D07D:: @ 828D07D
	msgbox Route111_Text_28B23D, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D08B:: @ 828D08B
	msgbox Route111_Text_28B2FA, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D099:: @ 828D099
	msgbox Route111_Text_28B379, 5
	goto Route111_EventScript_28D0A7
	end

Route111_EventScript_28D0A7:: @ 828D0A7
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_28D0E1
	msgbox Route111_Text_28B433, 4
	setvar VAR_0x8004, 10
	call Route111_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_28D0E1
	msgbox Route111_Text_28B4AB, 4
	special GabbyAndTyAfterInterview
	setflag FLAG_0x001
	release
	end

Route111_EventScript_28D0E1:: @ 828D0E1
	msgbox Route111_Text_28B577, 4
	setflag FLAG_0x001
	release
	end

Route111_EventScript_28D0EE:: @ 828D0EE
	msgbox Route111_Text_28B5C0, 4
	release
	end

	.include "data/text/pokemon_news.inc"


MauvilleCity_PokemonCenter_1F_EventScript_28E066:: @ 828E066
	special sub_81201DC
	switch VAR_RESULT
	case 0, MauvilleCity_PokemonCenter_1F_EventScript_28E0A6
	case 1, MauvilleCity_PokemonCenter_1F_EventScript_28E167
	case 2, MauvilleCity_PokemonCenter_1F_EventScript_28E4D4
	case 3, MauvilleCity_PokemonCenter_1F_EventScript_29014A
	case 4, MauvilleCity_PokemonCenter_1F_EventScript_2902F6
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0A6:: @ 828E0A6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_29038E, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0C7
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0EA
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0C7:: @ 828E0C7
	setvar VAR_0x8004, 0
	special sub_8120340
	delay 60
	special sub_81201F4
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_2903E6, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0EA:: @ 828E0EA
	msgbox MauvilleCity_PokemonCenter_1F_Text_2903C0, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E0F4:: @ 828E0F4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290421, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E113
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E15D
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E113:: @ 828E113
	setvar VAR_0x8004, 6
	call MauvilleCity_PokemonCenter_1F_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_2904C1, 4
	setvar VAR_0x8004, 1
	special sub_8120340
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_2904EB, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E113
	special sub_8120210
	msgbox MauvilleCity_PokemonCenter_1F_Text_290514, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E15D:: @ 828E15D
	msgbox MauvilleCity_PokemonCenter_1F_Text_29049B, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E167:: @ 828E167
	lock
	faceplayer
	setflag FLAG_SYS_HIPSTER_MEET
	msgbox MauvilleCity_PokemonCenter_1F_Text_29054C, 4
	special sub_8120358
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E18C
	msgbox MauvilleCity_PokemonCenter_1F_Text_290598, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E18C:: @ 828E18C
	special sub_812038C
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290602, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E1A4:: @ 828E1A4
	msgbox MauvilleCity_PokemonCenter_1F_Text_290666, 4
	special sub_8120374
	release
	end

MauvilleCity_PokemonCenter_1F_Text_28E1B1: @ 828E1B1
	.string "Hi, I’m the TRADER.\n"
	.string "Want to trade decorations with me?$"

MauvilleCity_PokemonCenter_1F_Text_28E1E8: @ 828E1E8
	.string "Oh…\n"
	.string "You’ve left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_28E20E: @ 828E20E
	.string "But we’ve traded decorations already,\n"
	.string "you and I.$"

MauvilleCity_PokemonCenter_1F_Text_28E23F: @ 828E23F
	.string "If you see any decorative item that\n"
	.string "you want of mine, speak up.$"

MauvilleCity_PokemonCenter_1F_Text_28E27F: @ 828E27F
	.string "You don’t want anything?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_28E2A9: @ 828E2A9
	.string "That decorative item once belonged\n"
	.string "to {STR_VAR_1}.\p"
	.string "Do you want it?$"

MauvilleCity_PokemonCenter_1F_Text_28E2E3: @ 828E2E3
	.string "Uh… Wait a second. You don’t have a\n"
	.string "single piece of decoration!$"

MauvilleCity_PokemonCenter_1F_Text_28E323: @ 828E323
	.string "Okay, pick the decoration that you’ll\n"
	.string "trade to me.$"

MauvilleCity_PokemonCenter_1F_Text_28E356: @ 828E356
	.string "You won’t trade with me?\n"
	.string "I feel unwanted…$"

MauvilleCity_PokemonCenter_1F_Text_28E380: @ 828E380
	.string "You’ve got all the {STR_VAR_2}S that can\n"
	.string "be stored. You’ve no room for this.$"

MauvilleCity_PokemonCenter_1F_Text_28E3C4: @ 828E3C4
	.string "Okay, so we’ll trade my {STR_VAR_3}\n"
	.string "for your {STR_VAR_2}?$"

MauvilleCity_PokemonCenter_1F_Text_28E3EC: @ 828E3EC
	.string "That piece of decoration is in use.\n"
	.string "You can’t trade it.$"

MauvilleCity_PokemonCenter_1F_Text_28E424: @ 828E424
	.string "Then we’ll trade!\n"
	.string "I’ll send my decoration to your PC.$"

MauvilleCity_PokemonCenter_1F_Text_28E45A: @ 828E45A
	.string "Oops! Sorry! That’s a really rare\n"
	.string "piece of decoration.\l"
	.string "I can’t trade that one away!\p"
	.string "Can I interest you in something else?$"

MauvilleCity_PokemonCenter_1F_EventScript_28E4D4:: @ 828E4D4
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E1B1, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E503
	special sub_8133CD8
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E50D
	message MauvilleCity_PokemonCenter_1F_Text_28E23F
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E503:: @ 828E503
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E1E8, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E50D:: @ 828E50D
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E20E, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E517:: @ 828E517
	special sub_8133EC0
	waitstate
	compare_var_to_value VAR_0x8004, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E558
	compare_var_to_value VAR_0x8004, 65535
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E562
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E2A9, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E56E
	special sub_8133CF4
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E57A
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E584
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E558:: @ 828E558
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E27F, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E562:: @ 828E562
	message MauvilleCity_PokemonCenter_1F_Text_28E45A
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E56E:: @ 828E56E
	message MauvilleCity_PokemonCenter_1F_Text_28E23F
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E517
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E57A:: @ 828E57A
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E2E3, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E584:: @ 828E584
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E323, 4
	special sub_8133D8C
	waitstate
	compare_var_to_value VAR_0x8006, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5D4
	compare_var_to_value VAR_0x8006, 65535
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5DE
	special sub_8133D2C
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E3C4, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_28E584
	special sub_8133E38
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E424, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5D4:: @ 828E5D4
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E356, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5DE:: @ 828E5DE
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E3EC, 4
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E584
	end

MauvilleCity_PokemonCenter_1F_EventScript_28E5EC:: @ 828E5EC
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E380, 4
	release
	end

MauvilleCity_PokemonCenter_1F_Text_28E5F6: @ 828E5F6
	.string "I’m the STORYTELLER.\n"
	.string "I’ll tell you tales of legendary\l"
	.string "TRAINERS.\p"
	.string "Will you hear my tale?$"

MauvilleCity_PokemonCenter_1F_Text_28E64D: @ 828E64D
	.string "Oh…\n"
	.string "You’ve left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_28E673: @ 828E673
	.string "I know of these legends.\n"
	.string "Which tale will you have me tell?$"

MauvilleCity_PokemonCenter_1F_Text_28E6AE: @ 828E6AE
	.string "But, I know of no legendary TRAINERS.\n"
	.string "Hence, I know no tales.\p"
	.string "Where does one find a TRAINER worthy\n"
	.string "of a legendary tale?$"

MauvilleCity_PokemonCenter_1F_Text_28E726: @ 828E726
	.string "What’s that?!\n"
	.string "You… You…\p"
	.string "{STR_VAR_2}\n"
	.string "{STR_VAR_1} time(s)?!\p"
	.string "That is indeed magnificent!\n"
	.string "It’s the birth of a new legend!$"

MauvilleCity_PokemonCenter_1F_Text_28E78A: @ 828E78A
	.string "It gets me thinking, could there be\n"
	.string "other TRAINERS with more impressive\l"
	.string "legends awaiting discovery?$"

MauvilleCity_PokemonCenter_1F_Text_28E7EE: @ 828E7EE
	.string "Are you a TRAINER?\p"
	.string "Then tell me, have you any tales that\n"
	.string "are even remotely legendary?$"

	.incbin "baserom.gba", 0x28e844, 0x3d

MauvilleCity_PokemonCenter_1F_Text_28E881: @ 828E881
	.string "Hmm…\n"
	.string "I’m not satisfied…\p"
	.string "I wish you would bring me news worthy\n"
	.string "of being called a legend.$"

	.incbin "baserom.gba", 0x28e8d9, 0x1871

MauvilleCity_PokemonCenter_1F_EventScript_29014A:: @ 829014A
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E5F6, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290219
	specialvar VAR_RESULT, sub_81213B0
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_2901DA
	message MauvilleCity_PokemonCenter_1F_Text_28E673
	waitmessage
	special sub_8121388
	waitstate
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_2901B7
	setvar VAR_0x8008, 1
	special sub_812139C
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, sub_81213D8
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_2901BD
	goto MauvilleCity_PokemonCenter_1F_EventScript_29020F

MauvilleCity_PokemonCenter_1F_EventScript_2901B7:: @ 82901B7
	goto MauvilleCity_PokemonCenter_1F_EventScript_290219
	end

MauvilleCity_PokemonCenter_1F_EventScript_2901BD:: @ 82901BD
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E78A, 4
	specialvar VAR_RESULT, sub_8121424
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_29022D
	goto MauvilleCity_PokemonCenter_1F_EventScript_2901E2

MauvilleCity_PokemonCenter_1F_EventScript_2901DA:: @ 82901DA
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E6AE, 4

MauvilleCity_PokemonCenter_1F_EventScript_2901E2:: @ 82901E2
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E7EE, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290219
	specialvar VAR_RESULT, sub_8121450
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_29020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E881, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_29020F:: @ 829020F
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E726, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_290219:: @ 8290219
	msgbox MauvilleCity_PokemonCenter_1F_Text_28E64D, 4
	release
	end

	.incbin "baserom.gba", 0x290223, 0xa

MauvilleCity_PokemonCenter_1F_EventScript_29022D:: @ 829022D
	release
	end

MauvilleCity_PokemonCenter_1F_Text_29022F: @ 829022F
	.string "I’m GIDDY!\n"
	.string "I have a scintillating story for you!\p"
	.string "Would you like to hear my story?$"

MauvilleCity_PokemonCenter_1F_Text_290281: @ 8290281
	.string "Oh…\n"
	.string "You’ve left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2902A7: @ 82902A7
	.string "Also, I was thinking…$"

MauvilleCity_PokemonCenter_1F_Text_2902BD: @ 82902BD
	.string "That’s about it, I think…\p"
	.string "We should chat again!\n"
	.string "Bye-bye!$"

MauvilleCity_PokemonCenter_1F_EventScript_2902F6:: @ 82902F6
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_29022F, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290317
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_29037A
	end

MauvilleCity_PokemonCenter_1F_EventScript_290317:: @ 8290317
	special sub_81203C4
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290359
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290384
	end

MauvilleCity_PokemonCenter_1F_EventScript_290331:: @ 8290331
	special sub_81203C4
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_29034B
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290384
	end

MauvilleCity_PokemonCenter_1F_EventScript_29034B:: @ 829034B
	msgbox MauvilleCity_PokemonCenter_1F_Text_2902A7, 4
	goto MauvilleCity_PokemonCenter_1F_EventScript_290359
	end

MauvilleCity_PokemonCenter_1F_EventScript_290359:: @ 8290359
	special sub_81203FC
	special sub_8138AC0
	waitmessage
	yesnobox 20, 8
	compare_var_to_value VAR_RESULT, 1
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290331
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_PokemonCenter_1F_EventScript_290331
	end

MauvilleCity_PokemonCenter_1F_EventScript_29037A:: @ 829037A
	msgbox MauvilleCity_PokemonCenter_1F_Text_290281, 4
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_290384:: @ 8290384
	msgbox MauvilleCity_PokemonCenter_1F_Text_2902BD, 4
	release
	end

MauvilleCity_PokemonCenter_1F_Text_29038E: @ 829038E
	.string "Hi, I’m the BARD.\n"
	.string "Would you like to hear my song?$"

MauvilleCity_PokemonCenter_1F_Text_2903C0: @ 82903C0
	.string "Oh…\n"
	.string "You’ve left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2903E6: @ 82903E6
	.string "Oh, what a moving song…\n"
	.string "I wish I could play it for others…$"

MauvilleCity_PokemonCenter_1F_Text_290421: @ 8290421
	.string "So?\n"
	.string "How do you like my song?\p"
	.string "But I’m none too happy about\n"
	.string "the lyrics.\p"
	.string "How would you like to write some\n"
	.string "new lyrics for me?$"

MauvilleCity_PokemonCenter_1F_Text_29049B: @ 829049B
	.string "Oh…\n"
	.string "You’ve left me feeling the blues…$"

MauvilleCity_PokemonCenter_1F_Text_2904C1: @ 82904C1
	.string "Thank you kindly!\n"
	.string "Let me sing it for you.$"

MauvilleCity_PokemonCenter_1F_Text_2904EB: @ 82904EB
	.string "Was that how you wanted your song\n"
	.string "to go?$"

MauvilleCity_PokemonCenter_1F_Text_290514: @ 8290514
	.string "Okay! That’s it, then.\n"
	.string "I’ll sing this song for a while.$"

MauvilleCity_PokemonCenter_1F_Text_29054C: @ 829054C
	.string "Hey, yo! They call me the HIPSTER.\n"
	.string "I’ll teach you what’s hip and happening.$"

MauvilleCity_PokemonCenter_1F_Text_290598: @ 8290598
	.string "But, hey, I taught you what’s hip and\n"
	.string "happening already.\p"
	.string "I’d like to spread the good word to\n"
	.string "other folks.$"

MauvilleCity_PokemonCenter_1F_Text_290602: @ 8290602
	.string "But, hey, you already know a lot about\n"
	.string "what’s hip and happening.\p"
	.string "I’ve got nothing new to teach you!$"

MauvilleCity_PokemonCenter_1F_Text_290666: @ 8290666
	.string "Hey, have you heard about\n"
	.string "“{STR_VAR_1}”?\p"
	.string "What’s it mean? Well…\n"
	.string "Ask your daddy or mommy, okay?$"

PetalburgWoods_EventScript_2906BB:: @ 82906BB
Route103_EventScript_2906BB:: @ 82906BB
Route104_EventScript_2906BB:: @ 82906BB
Route110_TrickHousePuzzle1_EventScript_2906BB:: @ 82906BB
Route111_EventScript_2906BB:: @ 82906BB
Route116_EventScript_2906BB:: @ 82906BB
Route117_EventScript_2906BB:: @ 82906BB
Route118_EventScript_2906BB:: @ 82906BB
Route120_EventScript_2906BB:: @ 82906BB
Route121_EventScript_2906BB:: @ 82906BB
Route123_EventScript_2906BB:: @ 82906BB
	lockall
	checkflag FLAG_BADGE01_GET
	goto_if 0, Route103_EventScript_290721
	checkpartymove MOVE_CUT
	compare_var_to_value VAR_RESULT, 6
	goto_eq Route103_EventScript_290721
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_CUT
	msgbox Route103_Text_29072E, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route103_EventScript_29072B
	msgbox Route103_Text_290771, 4
	closemessage
	dofieldeffect 2
	waitstate
	goto Route103_EventScript_290710
	end

gUnknown_08290705:: @ 8290705

	.incbin "baserom.gba", 0x290705, 0xb

Route103_EventScript_290710:: @ 8290710
	applymovement VAR_LAST_TALKED, Route103_Movement_29071F
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Route103_Movement_29071F: @ 829071F
	step_5b
	step_end

Route103_EventScript_290721:: @ 8290721
	msgbox Route103_Text_29077D, 4
	releaseall
	end

Route103_EventScript_29072B:: @ 829072B
	closemessage
	releaseall
	end

Route103_Text_29072E: @ 829072E
	.string "This tree looks like it can be\n"
	.string "CUT down!\p"
	.string "Would you like to CUT it?$"

Route103_Text_290771: @ 8290771
Route111_Text_290771: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Route103_Text_29077D: @ 829077D
	.string "This tree looks like it can be\n"
	.string "CUT down!$"

GraniteCave_B2F_EventScript_2907A6:: @ 82907A6
MirageTower_3F_EventScript_2907A6:: @ 82907A6
MirageTower_4F_EventScript_2907A6:: @ 82907A6
Route110_TrickHousePuzzle3_EventScript_2907A6:: @ 82907A6
Route111_EventScript_2907A6:: @ 82907A6
Route114_EventScript_2907A6:: @ 82907A6
Route115_EventScript_2907A6:: @ 82907A6
RusturfTunnel_EventScript_2907A6:: @ 82907A6
SafariZone_North_EventScript_2907A6:: @ 82907A6
SafariZone_Northeast_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room1_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room2_EventScript_2907A6:: @ 82907A6
SeafloorCavern_Room5_EventScript_2907A6:: @ 82907A6
VictoryRoad_B1F_EventScript_2907A6:: @ 82907A6
	lockall
	checkflag FLAG_BADGE03_GET
	goto_if 0, Route111_EventScript_29082D
	checkpartymove MOVE_ROCK_SMASH
	compare_var_to_value VAR_RESULT, 6
	goto_eq Route111_EventScript_29082D
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Route111_Text_29083A, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_290837
	msgbox Route111_Text_290771, 4
	closemessage
	dofieldeffect 37
	waitstate
	goto Route111_EventScript_2907FB
	end

gUnknown_082907F0:: @ 82907F0

	.incbin "baserom.gba", 0x2907f0, 0xb

Route111_EventScript_2907FB:: @ 82907FB
	applymovement VAR_LAST_TALKED, Route111_Movement_29082B
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, sub_81393FC
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route111_EventScript_290829
	special rock_smash_wild_pokemon_encounter
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route111_EventScript_290829
	waitstate
	releaseall
	end

Route111_EventScript_290829:: @ 8290829
	releaseall
	end

Route111_Movement_29082B: @ 829082B
	step_5a
	step_end

Route111_EventScript_29082D:: @ 829082D
	msgbox Route111_Text_29087F, 4
	releaseall
	end

Route111_EventScript_290837:: @ 8290837
	closemessage
	releaseall
	end

Route111_Text_29083A: @ 829083A
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use ROCK SMASH?$"

Route111_Text_29087F: @ 829087F
	.string "It’s a rugged rock, but a POKéMON\n"
	.string "may be able to smash it.$"

FieryPath_EventScript_2908BA:: @ 82908BA
MagmaHideout_1F_EventScript_2908BA:: @ 82908BA
Route110_TrickHousePuzzle4_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room1_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room2_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room3_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room5_EventScript_2908BA:: @ 82908BA
SeafloorCavern_Room8_EventScript_2908BA:: @ 82908BA
ShoalCave_LowTideLowerRoom_EventScript_2908BA:: @ 82908BA
VictoryRoad_B1F_EventScript_2908BA:: @ 82908BA
	lockall
	checkflag FLAG_BADGE04_GET
	goto_if 0, FieryPath_EventScript_290915
	checkflag FLAG_SYS_USE_STRENGTH
	goto_eq FieryPath_EventScript_29091F
	checkpartymove MOVE_STRENGTH
	compare_var_to_value VAR_RESULT, 6
	goto_eq FieryPath_EventScript_290915
	setfieldeffectargument 0, VAR_RESULT
	msgbox FieryPath_Text_29092C, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq FieryPath_EventScript_290929
	closemessage
	dofieldeffect 40
	waitstate
	goto FieryPath_EventScript_290908
	end

gUnknown_082908FD:: @ 82908FD

	.incbin "baserom.gba", 0x2908fd, 0xb

FieryPath_EventScript_290908:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox FieryPath_Text_29098C, 4
	releaseall
	end

FieryPath_EventScript_290915:: @ 8290915
	msgbox FieryPath_Text_2909D6, 4
	releaseall
	end

FieryPath_EventScript_29091F:: @ 829091F
	msgbox FieryPath_Text_290A16, 4
	releaseall
	end

FieryPath_EventScript_290929:: @ 8290929
	closemessage
	releaseall
	end

FieryPath_Text_29092C: @ 829092C
	.string "It’s a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use STRENGTH?$"

FieryPath_Text_29098C: @ 829098C
	.string "{STR_VAR_1} used STRENGTH!\p"
	.string "{STR_VAR_1}’s STRENGTH made it\n"
	.string "possible to move boulders around!$"

FieryPath_Text_2909D6: @ 82909D6
	.string "It’s a big boulder, but a POKéMON\n"
	.string "may be able to push it aside.$"

FieryPath_Text_290A16: @ 8290A16
	.string "STRENGTH made it possible to move\n"
	.string "boulders around.$"

gUnknown_08290A49:: @ 8290A49
	.incbin "baserom.gba", 0x290a49, 0x3a

gUnknown_08290A83:: @ 8290A83
	.incbin "baserom.gba", 0x290a83, 0x8c

gUnknown_08290B0F:: @ 8290B0F
	.incbin "baserom.gba", 0x290b0f, 0x4b

gUnknown_08290B5A:: @ 8290B5A
	.incbin "baserom.gba", 0x290b5a, 0x154

gUnknown_08290CAE:: @ 8290CAE

	.incbin "baserom.gba", 0x290cae, 0x2a

Route102_EventScript_290CD8:: @ 8290CD8
	giveitem_std ITEM_POTION, 1, 1
	end

Route103_EventScript_290CE5:: @ 8290CE5
	giveitem_std ITEM_GUARD_SPEC, 1, 1
	end

Route103_EventScript_290CF2:: @ 8290CF2
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route104_EventScript_290CFF:: @ 8290CFF
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route104_EventScript_290D0C:: @ 8290D0C
	giveitem_std ITEM_POKE_BALL, 1, 1
	end

Route104_EventScript_290D19:: @ 8290D19
	giveitem_std ITEM_X_ACCURACY, 1, 1
	end

Route104_EventScript_290D26:: @ 8290D26
	giveitem_std ITEM_POTION, 1, 1
	end

Route105_EventScript_290D33:: @ 8290D33
	giveitem_std ITEM_IRON, 1, 1
	end

Route106_EventScript_290D40:: @ 8290D40
	giveitem_std ITEM_PROTEIN, 1, 1
	end

Route108_EventScript_290D4D:: @ 8290D4D
	giveitem_std ITEM_STAR_PIECE, 1, 1
	end

Route109_EventScript_290D5A:: @ 8290D5A
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route109_EventScript_290D67:: @ 8290D67
	giveitem_std ITEM_POTION, 1, 1
	end

Route110_EventScript_290D74:: @ 8290D74
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

Route110_EventScript_290D81:: @ 8290D81
	giveitem_std ITEM_DIRE_HIT, 1, 1
	end

Route110_EventScript_290D8E:: @ 8290D8E
	giveitem_std ITEM_ELIXIR, 1, 1
	end

Route111_EventScript_290D9B:: @ 8290D9B
	giveitem_std ITEM_TM37, 1, 1
	end

Route111_EventScript_290DA8:: @ 8290DA8
	giveitem_std ITEM_STARDUST, 1, 1
	end

Route111_EventScript_290DB5:: @ 8290DB5
	giveitem_std ITEM_HP_UP, 1, 1
	end

Route111_EventScript_290DC2:: @ 8290DC2
	giveitem_std ITEM_ELIXIR, 1, 1
	end

Route112_EventScript_290DCF:: @ 8290DCF
	giveitem_std ITEM_NUGGET, 1, 1
	end

Route113_EventScript_290DDC:: @ 8290DDC
	giveitem_std ITEM_MAX_ETHER, 1, 1
	end

Route113_EventScript_290DE9:: @ 8290DE9
	giveitem_std ITEM_SUPER_REPEL, 1, 1
	end

Route113_EventScript_290DF6:: @ 8290DF6
	giveitem_std ITEM_HYPER_POTION, 1, 1
	end

Route114_EventScript_290E03:: @ 8290E03
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

Route114_EventScript_290E10:: @ 8290E10
	giveitem_std ITEM_PROTEIN, 1, 1
	end

Route114_EventScript_290E1D:: @ 8290E1D
	giveitem_std ITEM_ENERGY_POWDER, 1, 1
	end

Route115_EventScript_290E2A:: @ 8290E2A
	giveitem_std ITEM_SUPER_POTION, 1, 1
	end

Route115_EventScript_290E37:: @ 8290E37
	giveitem_std ITEM_TM01, 1, 1
	end

Route115_EventScript_290E44:: @ 8290E44
	giveitem_std ITEM_IRON, 1, 1
	end

Route115_EventScript_290E51:: @ 8290E51
	giveitem_std ITEM_GREAT_BALL, 1, 1
	end

Route115_EventScript_290E5E:: @ 8290E5E
	giveitem_std ITEM_HEAL_POWDER, 1, 1
	end

Route115_EventScript_290E6B:: @ 8290E6B
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route116_EventScript_290E78:: @ 8290E78
	giveitem_std ITEM_X_SPECIAL, 1, 1
	end

Route116_EventScript_290E85:: @ 8290E85
	giveitem_std ITEM_ETHER, 1, 1
	end

Route116_EventScript_290E92:: @ 8290E92
	giveitem_std ITEM_REPEL, 1, 1
	end

Route116_EventScript_290E9F:: @ 8290E9F
	giveitem_std ITEM_HP_UP, 1, 1
	end

Route116_EventScript_290EAC:: @ 8290EAC
	giveitem_std ITEM_POTION, 1, 1
	end

Route117_EventScript_290EB9:: @ 8290EB9
	giveitem_std ITEM_GREAT_BALL, 1, 1
	end

Route117_EventScript_290EC6:: @ 8290EC6
	giveitem_std ITEM_REVIVE, 1, 1
	end

Route118_EventScript_290ED3:: @ 8290ED3
	giveitem_std ITEM_HYPER_POTION, 1, 1
	end

Route119_EventScript_290EE0:: @ 8290EE0
	giveitem_std ITEM_SUPER_REPEL, 1, 1
	end

Route119_EventScript_290EED:: @ 8290EED
	giveitem_std ITEM_ZINC, 1, 1
	end

Route119_EventScript_290EFA:: @ 8290EFA
	giveitem_std ITEM_ELIXIR, 1, 1
	end

Route119_EventScript_290F07:: @ 8290F07
	giveitem_std ITEM_LEAF_STONE, 1, 1
	end

Route119_EventScript_290F14:: @ 8290F14
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

Route119_EventScript_290F21:: @ 8290F21
	giveitem_std ITEM_HYPER_POTION, 1, 1
	end

Route119_EventScript_290F2E:: @ 8290F2E
	giveitem_std ITEM_HYPER_POTION, 1, 1
	end

Route119_EventScript_290F3B:: @ 8290F3B
	giveitem_std ITEM_ELIXIR, 1, 1
	end

Route120_EventScript_290F48:: @ 8290F48
	giveitem_std ITEM_NUGGET, 1, 1
	end

Route120_EventScript_290F55:: @ 8290F55
	giveitem_std ITEM_FULL_HEAL, 1, 1
	end

Route120_EventScript_290F62:: @ 8290F62
	giveitem_std ITEM_HYPER_POTION, 1, 1
	end

Route120_EventScript_290F6F:: @ 8290F6F
	giveitem_std ITEM_NEST_BALL, 1, 1
	end

Route120_EventScript_290F7C:: @ 8290F7C
	giveitem_std ITEM_REVIVE, 1, 1
	end

Route121_EventScript_290F89:: @ 8290F89
	giveitem_std ITEM_CARBOS, 1, 1
	end

Route121_EventScript_290F96:: @ 8290F96
	giveitem_std ITEM_REVIVE, 1, 1
	end

Route121_EventScript_290FA3:: @ 8290FA3
	giveitem_std ITEM_ZINC, 1, 1
	end

Route123_EventScript_290FB0:: @ 8290FB0
	giveitem_std ITEM_CALCIUM, 1, 1
	end

Route123_EventScript_290FBD:: @ 8290FBD
	giveitem_std ITEM_ULTRA_BALL, 1, 1
	end

Route123_EventScript_290FCA:: @ 8290FCA
	giveitem_std ITEM_ELIXIR, 1, 1
	end

Route123_EventScript_290FD7:: @ 8290FD7
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route123_EventScript_290FE4:: @ 8290FE4
	giveitem_std ITEM_REVIVAL_HERB, 1, 1
	end

Route124_EventScript_290FF1:: @ 8290FF1
	giveitem_std ITEM_RED_SHARD, 1, 1
	end

Route124_EventScript_290FFE:: @ 8290FFE
	giveitem_std ITEM_BLUE_SHARD, 1, 1
	end

Route124_EventScript_29100B:: @ 829100B
	giveitem_std ITEM_YELLOW_SHARD, 1, 1
	end

Route125_EventScript_291018:: @ 8291018
	giveitem_std ITEM_BIG_PEARL, 1, 1
	end

Route126_EventScript_291025:: @ 8291025
	giveitem_std ITEM_GREEN_SHARD, 1, 1
	end

Route127_EventScript_291032:: @ 8291032
	giveitem_std ITEM_ZINC, 1, 1
	end

Route127_EventScript_29103F:: @ 829103F
	giveitem_std ITEM_CARBOS, 1, 1
	end

Route127_EventScript_29104C:: @ 829104C
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

Route132_EventScript_291059:: @ 8291059
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

Route132_EventScript_291066:: @ 8291066
	giveitem_std ITEM_PROTEIN, 1, 1
	end

Route133_EventScript_291073:: @ 8291073
	giveitem_std ITEM_BIG_PEARL, 1, 1
	end

Route133_EventScript_291080:: @ 8291080
	giveitem_std ITEM_STAR_PIECE, 1, 1
	end

Route133_EventScript_29108D:: @ 829108D
	giveitem_std ITEM_MAX_REVIVE, 1, 1
	end

Route134_EventScript_29109A:: @ 829109A
	giveitem_std ITEM_CARBOS, 1, 1
	end

Route134_EventScript_2910A7:: @ 82910A7
	giveitem_std ITEM_STAR_PIECE, 1, 1
	end

PetalburgCity_EventScript_2910B4:: @ 82910B4
	giveitem_std ITEM_MAX_REVIVE, 1, 1
	end

PetalburgCity_EventScript_2910C1:: @ 82910C1
	giveitem_std ITEM_ETHER, 1, 1
	end

MauvilleCity_EventScript_2910CE:: @ 82910CE
	giveitem_std ITEM_X_SPEED, 1, 1
	end

RustboroCity_EventScript_2910DB:: @ 82910DB
	giveitem_std ITEM_X_DEFEND, 1, 1
	end

LilycoveCity_EventScript_2910E8:: @ 82910E8
	giveitem_std ITEM_MAX_REPEL, 1, 1
	end

MossdeepCity_EventScript_2910F5:: @ 82910F5
	giveitem_std ITEM_NET_BALL, 1, 1
	end

PetalburgWoods_EventScript_291102:: @ 8291102
	giveitem_std ITEM_X_ATTACK, 1, 1
	end

PetalburgWoods_EventScript_29110F:: @ 829110F
	giveitem_std ITEM_GREAT_BALL, 1, 1
	end

PetalburgWoods_EventScript_29111C:: @ 829111C
	giveitem_std ITEM_ETHER, 1, 1
	end

PetalburgWoods_EventScript_291129:: @ 8291129
	giveitem_std ITEM_PARALYZE_HEAL, 1, 1
	end

RusturfTunnel_EventScript_291136:: @ 8291136
	giveitem_std ITEM_POKE_BALL, 1, 1
	end

RusturfTunnel_EventScript_291143:: @ 8291143
	giveitem_std ITEM_MAX_ETHER, 1, 1
	end

GraniteCave_1F_EventScript_291150:: @ 8291150
	giveitem_std ITEM_ESCAPE_ROPE, 1, 1
	end

GraniteCave_B1F_EventScript_29115D:: @ 829115D
	giveitem_std ITEM_POKE_BALL, 1, 1
	end

GraniteCave_B2F_EventScript_29116A:: @ 829116A
	giveitem_std ITEM_REPEL, 1, 1
	end

GraniteCave_B2F_EventScript_291177:: @ 8291177
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

JaggedPass_EventScript_291184:: @ 8291184
	giveitem_std ITEM_BURN_HEAL, 1, 1
	end

FieryPath_EventScript_291191:: @ 8291191
	giveitem_std ITEM_FIRE_STONE, 1, 1
	end

FieryPath_EventScript_29119E:: @ 829119E
	giveitem_std ITEM_TM06, 1, 1
	end

MeteorFalls_1F_1R_EventScript_2911AB:: @ 82911AB
	giveitem_std ITEM_TM23, 1, 1
	end

MeteorFalls_1F_1R_EventScript_2911B8:: @ 82911B8
	giveitem_std ITEM_FULL_HEAL, 1, 1
	end

MeteorFalls_1F_1R_EventScript_2911C5:: @ 82911C5
	giveitem_std ITEM_MOON_STONE, 1, 1
	end

MeteorFalls_1F_1R_EventScript_2911D2:: @ 82911D2
	giveitem_std ITEM_PP_UP, 1, 1
	end

MeteorFalls_B1F_2R_EventScript_2911DF:: @ 82911DF
	giveitem_std ITEM_TM02, 1, 1
	end

NewMauville_Inside_EventScript_2911EC:: @ 82911EC
	giveitem_std ITEM_ULTRA_BALL, 1, 1
	end

NewMauville_Inside_EventScript_2911F9:: @ 82911F9
	giveitem_std ITEM_ESCAPE_ROPE, 1, 1
	end

NewMauville_Inside_EventScript_291206:: @ 8291206
	giveitem_std ITEM_THUNDER_STONE, 1, 1
	end

NewMauville_Inside_EventScript_291213:: @ 8291213
	giveitem_std ITEM_FULL_HEAL, 1, 1
	end

NewMauville_Inside_EventScript_291220:: @ 8291220
	giveitem_std ITEM_PARALYZE_HEAL, 1, 1
	end

AbandonedShip_Rooms_1F_EventScript_29122D:: @ 829122D
	giveitem_std ITEM_HARBOR_MAIL, 1, 1
	end

AbandonedShip_Rooms_B1F_EventScript_29123A:: @ 829123A
	giveitem_std ITEM_ESCAPE_ROPE, 1, 1
	end

AbandonedShip_Rooms2_B1F_EventScript_291247:: @ 8291247
	giveitem_std ITEM_DIVE_BALL, 1, 1
	end

AbandonedShip_Room_B1F_EventScript_291254:: @ 8291254
	giveitem_std ITEM_TM13, 1, 1
	end

AbandonedShip_Rooms2_1F_EventScript_291261:: @ 8291261
	giveitem_std ITEM_REVIVE, 1, 1
	end

AbandonedShip_CaptainsOffice_EventScript_29126E:: @ 829126E
	giveitem_std ITEM_STORAGE_KEY, 1, 1
	end

AbandonedShip_HiddenFloorRooms_EventScript_29127B:: @ 829127B
	giveitem_std ITEM_LUXURY_BALL, 1, 1
	end

AbandonedShip_HiddenFloorRooms_EventScript_291288:: @ 8291288
	giveitem_std ITEM_SCANNER, 1, 1
	end

AbandonedShip_HiddenFloorRooms_EventScript_291295:: @ 8291295
	giveitem_std ITEM_WATER_STONE, 1, 1
	end

AbandonedShip_HiddenFloorRooms_EventScript_2912A2:: @ 82912A2
	giveitem_std ITEM_TM18, 1, 1
	end

ScorchedSlab_EventScript_2912AF:: @ 82912AF
	giveitem_std ITEM_TM11, 1, 1
	end

SafariZone_Northwest_EventScript_2912BC:: @ 82912BC
	giveitem_std ITEM_TM22, 1, 1
	end

SafariZone_North_EventScript_2912C9:: @ 82912C9
	giveitem_std ITEM_CALCIUM, 1, 1
	end

SafariZone_Southwest_EventScript_2912D6:: @ 82912D6
	giveitem_std ITEM_MAX_REVIVE, 1, 1
	end

SafariZone_Northeast_EventScript_2912E3:: @ 82912E3
	giveitem_std ITEM_NUGGET, 1, 1
	end

SafariZone_Southeast_EventScript_2912F0:: @ 82912F0
	giveitem_std ITEM_BIG_PEARL, 1, 1
	end

MtPyre_2F_EventScript_2912FD:: @ 82912FD
	giveitem_std ITEM_ULTRA_BALL, 1, 1
	end

MtPyre_3F_EventScript_29130A:: @ 829130A
	giveitem_std ITEM_SUPER_REPEL, 1, 1
	end

MtPyre_4F_EventScript_291317:: @ 8291317
	giveitem_std ITEM_SEA_INCENSE, 1, 1
	end

MtPyre_5F_EventScript_291324:: @ 8291324
	giveitem_std ITEM_LAX_INCENSE, 1, 1
	end

MtPyre_6F_EventScript_291331:: @ 8291331
	giveitem_std ITEM_TM30, 1, 1
	end

MtPyre_Exterior_EventScript_29133E:: @ 829133E
	giveitem_std ITEM_MAX_POTION, 1, 1
	end

MtPyre_Exterior_EventScript_29134B:: @ 829134B
	giveitem_std ITEM_TM48, 1, 1
	end

AquaHideout_B1F_EventScript_291358:: @ 8291358
	giveitem_std ITEM_MASTER_BALL, 1, 1
	end

AquaHideout_B1F_EventScript_291365:: @ 8291365
	giveitem_std ITEM_NUGGET, 1, 1
	end

AquaHideout_B1F_EventScript_291372:: @ 8291372
	giveitem_std ITEM_MAX_ELIXIR, 1, 1
	end

AquaHideout_B2F_EventScript_29137F:: @ 829137F
	giveitem_std ITEM_NEST_BALL, 1, 1
	end

	.incbin "baserom.gba", 0x29138c, 0xd

Route119_EventScript_291399:: @ 8291399
	giveitem_std ITEM_NUGGET, 1, 1
	end

	.incbin "baserom.gba", 0x2913a6, 0x1a

ShoalCave_LowTideEntranceRoom_EventScript_2913C0:: @ 82913C0
	giveitem_std ITEM_BIG_PEARL, 1, 1
	end

ShoalCave_LowTideInnerRoom_EventScript_2913CD:: @ 82913CD
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

ShoalCave_LowTideStairsRoom_EventScript_2913DA:: @ 82913DA
	giveitem_std ITEM_ICE_HEAL, 1, 1
	end

ShoalCave_LowTideIceRoom_EventScript_2913E7:: @ 82913E7
	giveitem_std ITEM_TM07, 1, 1
	end

ShoalCave_LowTideIceRoom_EventScript_2913F4:: @ 82913F4
	giveitem_std ITEM_NEVER_MELT_ICE, 1, 1
	end

SeafloorCavern_Room9_EventScript_291401:: @ 8291401
	giveitem_std ITEM_TM26, 1, 1
	end

Route110_TrickHousePuzzle1_EventScript_29140E:: @ 829140E
	giveitem_std ITEM_ORANGE_MAIL, 1, 1
	end

Route110_TrickHousePuzzle2_EventScript_29141B:: @ 829141B
	giveitem_std ITEM_HARBOR_MAIL, 1, 1
	end

Route110_TrickHousePuzzle2_EventScript_291428:: @ 8291428
	giveitem_std ITEM_WAVE_MAIL, 1, 1
	end

Route110_TrickHousePuzzle3_EventScript_291435:: @ 8291435
	giveitem_std ITEM_SHADOW_MAIL, 1, 1
	end

Route110_TrickHousePuzzle3_EventScript_291442:: @ 8291442
	giveitem_std ITEM_WOOD_MAIL, 1, 1
	end

Route110_TrickHousePuzzle4_EventScript_29144F:: @ 829144F
	giveitem_std ITEM_MECH_MAIL, 1, 1
	end

Route110_TrickHousePuzzle6_EventScript_29145C:: @ 829145C
	giveitem_std ITEM_GLITTER_MAIL, 1, 1
	end

Route110_TrickHousePuzzle7_EventScript_291469:: @ 8291469
	giveitem_std ITEM_TROPIC_MAIL, 1, 1
	end

Route110_TrickHousePuzzle8_EventScript_291476:: @ 8291476
	giveitem_std ITEM_BEAD_MAIL, 1, 1
	end

VictoryRoad_1F_EventScript_291483:: @ 8291483
	giveitem_std ITEM_MAX_ELIXIR, 1, 1
	end

VictoryRoad_1F_EventScript_291490:: @ 8291490
	giveitem_std ITEM_PP_UP, 1, 1
	end

VictoryRoad_B1F_EventScript_29149D:: @ 829149D
	giveitem_std ITEM_TM29, 1, 1
	end

VictoryRoad_B1F_EventScript_2914AA:: @ 82914AA
	giveitem_std ITEM_FULL_RESTORE, 1, 1
	end

VictoryRoad_B2F_EventScript_2914B7:: @ 82914B7
	giveitem_std ITEM_FULL_HEAL, 1, 1
	end

ArtisanCave_B1F_EventScript_2914C4:: @ 82914C4
	giveitem_std ITEM_HP_UP, 1, 1
	end

ArtisanCave_1F_EventScript_2914D1:: @ 82914D1
	giveitem_std ITEM_CARBOS, 1, 1
	end

MagmaHideout_1F_EventScript_2914DE:: @ 82914DE
	giveitem_std ITEM_RARE_CANDY, 1, 1
	end

MagmaHideout_2F_2R_EventScript_2914EB:: @ 82914EB
	giveitem_std ITEM_MAX_ELIXIR, 1, 1
	end

MagmaHideout_2F_2R_EventScript_2914F8:: @ 82914F8
	giveitem_std ITEM_FULL_RESTORE, 1, 1
	end

MagmaHideout_3F_1R_EventScript_291505:: @ 8291505
	giveitem_std ITEM_NUGGET, 1, 1
	end

MagmaHideout_3F_2R_EventScript_291512:: @ 8291512
	giveitem_std ITEM_PP_MAX, 1, 1
	end

MagmaHideout_4F_EventScript_29151F:: @ 829151F
	giveitem_std ITEM_MAX_REVIVE, 1, 1
	end

MagmaHideout_3F_3R_EventScript_29152C:: @ 829152C
	giveitem_std ITEM_ESCAPE_ROPE, 1, 1
	end

PetalburgCity_PokemonCenter_1F_EventScript_291539:: @ 8291539
	lock
	faceplayer
	checkflag FLAG_SYS_CHAT_USED
	goto_eq PetalburgCity_PokemonCenter_1F_EventScript_2915F5
	msgbox PetalburgCity_PokemonCenter_1F_Text_291687, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_291552
	end

PetalburgCity_PokemonCenter_1F_EventScript_291552:: @ 8291552
	msgbox PetalburgCity_PokemonCenter_1F_Text_2916FF, 4
	multichoice 17, 6, 20, 0
	switch VAR_RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_29159F
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_2915EB
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_291591
	case 127, PetalburgCity_PokemonCenter_1F_EventScript_2915EB
	end

PetalburgCity_PokemonCenter_1F_EventScript_291591:: @ 8291591
	msgbox PetalburgCity_PokemonCenter_1F_Text_291729, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_291552
	end

PetalburgCity_PokemonCenter_1F_EventScript_29159F:: @ 829159F
	msgbox PetalburgCity_PokemonCenter_1F_Text_291969, 4
	closemessage
	setvar VAR_0x8004, 0
	call PetalburgCity_PokemonCenter_1F_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 0
	goto_eq PetalburgCity_PokemonCenter_1F_EventScript_2915CB
	compare_var_to_value VAR_RESULT, 1
	goto_eq PetalburgCity_PokemonCenter_1F_EventScript_2915D5
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915CB:: @ 82915CB
	msgbox PetalburgCity_PokemonCenter_1F_Text_2919DC, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915D5:: @ 82915D5
	setvar VAR_0x8004, 0
	special sub_811EECC
	waitmessage
	delay 80
	msgbox PetalburgCity_PokemonCenter_1F_Text_291B22, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915EB:: @ 82915EB
	msgbox PetalburgCity_PokemonCenter_1F_Text_291991, 4
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_2915F5:: @ 82915F5
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A1B, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_291603
	end

PetalburgCity_PokemonCenter_1F_EventScript_291603:: @ 8291603
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A4F, 4
	multichoice 17, 6, 20, 0
	switch VAR_RESULT
	case 0, PetalburgCity_PokemonCenter_1F_EventScript_291650
	case 1, PetalburgCity_PokemonCenter_1F_EventScript_29167C
	case 2, PetalburgCity_PokemonCenter_1F_EventScript_291642
	case 127, PetalburgCity_PokemonCenter_1F_EventScript_29167C
	end

PetalburgCity_PokemonCenter_1F_EventScript_291642:: @ 8291642
	msgbox PetalburgCity_PokemonCenter_1F_Text_291729, 4
	goto PetalburgCity_PokemonCenter_1F_EventScript_291603
	end

PetalburgCity_PokemonCenter_1F_EventScript_291650:: @ 8291650
	msgbox PetalburgCity_PokemonCenter_1F_Text_291A6B, 4
	closemessage
	setvar VAR_0x8004, 0
	call PetalburgCity_PokemonCenter_1F_EventScript_271E7C
	lock
	faceplayer
	compare_var_to_value VAR_RESULT, 0
	goto_eq PetalburgCity_PokemonCenter_1F_EventScript_2915CB
	compare_var_to_value VAR_RESULT, 1
	goto_eq PetalburgCity_PokemonCenter_1F_EventScript_2915D5
	end

PetalburgCity_PokemonCenter_1F_EventScript_29167C:: @ 829167C
	msgbox PetalburgCity_PokemonCenter_1F_Text_291ABA, 4
	release
	end

	.incbin "baserom.gba", 0x291686, 0x1

PetalburgCity_PokemonCenter_1F_Text_291687: @ 8291687
	.string "Hello there, TRAINER!\n"
	.string "You’ve got a wonderful smile, there.\p"
	.string "I have a hobby--collecting the profiles\n"
	.string "of POKéMON TRAINERS.$"

PetalburgCity_PokemonCenter_1F_Text_2916FF: @ 82916FF
	.string "So, how about it?\n"
	.string "May I see your profile?$"

PetalburgCity_PokemonCenter_1F_Text_291729: @ 8291729
	.string "You make your own profile by putting\n"
	.string "together four words or phrases.\p"
	.string "Here, I’ll show you an example of a\n"
	.string "profile using four pieces of text.\p"
	.string "You can switch those four pieces with\n"
	.string "other text pieces any which way you\l"
	.string "like to make your own profile.\p"
	.string "There are a lot of text pieces that\n"
	.string "you can use.\p"
	.string "They are arranged in groups like\n"
	.string "POKéMON, lifestyles, and hobbies so\l"
	.string "it is easier to look them up.\p"
	.string "So, first, choose the group of text\n"
	.string "pieces to display a list of choices.\p"
	.string "Then, pick the choice you want.\p"
	.string "Repeat for the remaining text choices,\n"
	.string "and you’ll have your very own profile.$"

PetalburgCity_PokemonCenter_1F_Text_291969: @ 8291969
	.string "Yes! Thank you!\n"
	.string "So, let’s see it, then.$"

PetalburgCity_PokemonCenter_1F_Text_291991: @ 8291991
	.string "Oh, no, really?\p"
	.string "I imagine someone like you would have\n"
	.string "a wonderful profile…$"

PetalburgCity_PokemonCenter_1F_Text_2919DC: @ 82919DC
	.string "Oh? You’re not into it right now?\p"
	.string "Well, anytime is good by me!$"

PetalburgCity_PokemonCenter_1F_Text_291A1B: @ 8291A1B
	.string "Hello there, TRAINER!\n"
	.string "You’ve got a wonderful smile.$"

PetalburgCity_PokemonCenter_1F_Text_291A4F: @ 8291A4F
	.string "May I see your new profile?$"

PetalburgCity_PokemonCenter_1F_Text_291A6B: @ 8291A6B
	.string "Yes! Thank you!\p"
	.string "I hope it’s even better than the profile\n"
	.string "you showed me before.$"

PetalburgCity_PokemonCenter_1F_Text_291ABA: @ 8291ABA
	.string "Oh, you like your profile the way it is.\p"
	.string "I don’t blame you--it’s a wonderful\n"
	.string "profile the way it is now.$"

PetalburgCity_PokemonCenter_1F_Text_291B22: @ 8291B22
	.string "F-fantastic!\p"
	.string "Your profile, it’s wonderful!\n"
	.string "It really says what you’re about.\p"
	.string "Why, anyone hearing this profile would\n"
	.string "be captivated by you!\p"
	.string "Thank you!$"

	.incbin "baserom.gba", 0x291bb7, 0x61

Route117_EventScript_291C18:: @ 8291C18
	lock
	faceplayer
	special sp0B5_daycare
	specialvar VAR_RESULT, sp0B6_daycare
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_EventScript_291C4D
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_EventScript_291CD1
	compare_var_to_value VAR_RESULT, 3
	goto_eq Route117_EventScript_291CE8
	msgbox Route117_Text_291FCF, 4
	release
	end

Route117_EventScript_291C4D:: @ 8291C4D
	msgbox Route117_Text_29205D, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_EventScript_291C83
	msgbox Route117_Text_2922C6, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_EventScript_291C83
	msgbox Route117_Text_292149, 4
	clearflag FLAG_0x086
	special sub_8070728
	release
	end

Route117_EventScript_291C83:: @ 8291C83
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare_var_to_value VAR_RESULT, 6
	goto_if 5, Route117_EventScript_291C9D
	msgbox Route117_Text_29216A, 4
	release
	end

Route117_EventScript_291C9D:: @ 8291C9D
	message Route117_Text_2921A4
	playfanfare BGM_FANFA1
	waitfanfare
	waitbuttonpress
	msgbox Route117_Text_2921CF, 4
	special sp0B8_daycare
	clearflag FLAG_0x086
	release
	end

Route117_EventScript_291CB7:: @ 8291CB7
	specialvar VAR_RESULT, sub_8071614
	compare_var_to_value VAR_RESULT, 1
	call_if 1, Route117_EventScript_291CC8
	return

Route117_EventScript_291CC8:: @ 8291CC8
	msgbox Route117_Text_2921E5, 4
	return

Route117_EventScript_291CD1:: @ 8291CD1
	special sp0B5_daycare
	msgbox Route117_Text_292114, 4
	setvar VAR_0x8004, 0
	call Route117_EventScript_291CB7
	release
	end

Route117_EventScript_291CE8:: @ 8291CE8
	special sp0B5_daycare
	msgbox Route117_Text_292299, 4
	special sp0B9_daycare_relationship_comment
	special sub_8138AC0
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_291CB7
	setvar VAR_0x8004, 1
	call Route117_EventScript_291CB7
	release
	end

Route117_PokemonDayCare_EventScript_291D11:: @ 8291D11
	lock
	faceplayer
	specialvar VAR_RESULT, sp0B6_daycare
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291E0B
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291E2F
	compare_var_to_value VAR_RESULT, 3
	goto_eq Route117_PokemonDayCare_EventScript_291F5C
	msgbox Route117_PokemonDayCare_Text_2922F4, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291D56
	msgbox Route117_PokemonDayCare_Text_292416, 4
	release
	end

Route117_PokemonDayCare_EventScript_291D56:: @ 8291D56
	specialvar VAR_RESULT, sub_80C7008
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291DED
	specialvar VAR_RESULT, sub_80722E0
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291E01
	msgbox Route117_PokemonDayCare_Text_292349, 4
	fadescreen 1
	special sub_8071330
	waitstate
	compare_var_to_value VAR_0x8004, 255
	goto_eq Route117_PokemonDayCare_EventScript_291DCA
	specialvar VAR_RESULT, sub_80C70AC
	compare_var_to_value VAR_RESULT, 0
	goto_eq Route117_PokemonDayCare_EventScript_291DF7
	specialvar VAR_0x8005, sub_8070C58
	waitse
	playmoncry VAR_0x8005, 0
	msgbox Route117_PokemonDayCare_Text_292370, 4
	waitmoncry
	special daycare_send_selected_pokemon
	incrementgamestat 47
	specialvar VAR_RESULT, sp0B6_daycare
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291DD4
	release
	end

Route117_PokemonDayCare_EventScript_291DCA:: @ 8291DCA
	msgbox Route117_PokemonDayCare_Text_292476, 4
	release
	end

Route117_PokemonDayCare_EventScript_291DD4:: @ 8291DD4
	msgbox Route117_PokemonDayCare_Text_2923AF, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291D56
	goto Route117_PokemonDayCare_EventScript_291DCA
	end

Route117_PokemonDayCare_EventScript_291DED:: @ 8291DED
	msgbox Route117_PokemonDayCare_Text_2925BB, 4
	release
	end

Route117_PokemonDayCare_EventScript_291DF7:: @ 8291DF7
	msgbox Route117_PokemonDayCare_Text_292617, 4
	release
	end

Route117_PokemonDayCare_EventScript_291E01:: @ 8291E01
	msgbox Route117_PokemonDayCare_Text_29266D, 4
	release
	end

Route117_PokemonDayCare_EventScript_291E0B:: @ 8291E0B
	msgbox Route117_PokemonDayCare_Text_2923F6, 4
	release
	end

Route117_PokemonDayCare_EventScript_291E15:: @ 8291E15
	msgbox Route117_PokemonDayCare_Text_2924CC, 4
	return

Route117_PokemonDayCare_EventScript_291E1E:: @ 8291E1E
	specialvar VAR_RESULT, sub_806FF30
	compare_var_to_value VAR_RESULT, 0
	call_if 5, Route117_PokemonDayCare_EventScript_291E15
	return

Route117_PokemonDayCare_EventScript_291E2F:: @ 8291E2F
	msgbox Route117_PokemonDayCare_Text_292488, 4
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_291E1E
	msgbox Route117_PokemonDayCare_Text_2923AF, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291D56
	msgbox Route117_PokemonDayCare_Text_2925F6, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291E6D
	goto Route117_PokemonDayCare_EventScript_291DCA
	end

Route117_PokemonDayCare_EventScript_291E6D:: @ 8291E6D
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	compare_var_to_value VAR_RESULT, 6
	goto_eq Route117_PokemonDayCare_EventScript_291F3D
	specialvar VAR_RESULT, sp0B6_daycare
	setvar VAR_0x8004, 0
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291EAC
	special sub_80712C0
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291DCA
	goto Route117_PokemonDayCare_EventScript_291EAC
	end

Route117_PokemonDayCare_EventScript_291EAC:: @ 8291EAC
	special sub_806FED8
	msgbox Route117_PokemonDayCare_Text_292549, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291EC8
	goto Route117_PokemonDayCare_EventScript_291DCA
	end

Route117_PokemonDayCare_EventScript_291EC8:: @ 8291EC8
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291EE2
	msgbox Route117_PokemonDayCare_Text_292432, 4
	release
	end

Route117_PokemonDayCare_EventScript_291EE2:: @ 8291EE2
	applymovement 1, Route117_PokemonDayCare_Movement_291F47
	waitmovement 0
	specialvar VAR_RESULT, sub_806FDC4
	special SubtractMoneyFromVar0x8005
	playse SE_REGI
	msgbox Route117_PokemonDayCare_Text_292575, 4
	waitse
	playmoncry VAR_RESULT, 0
	msgbox Route117_PokemonDayCare_Text_292593, 4
	waitmoncry
	specialvar VAR_RESULT, sp0B6_daycare
	compare_var_to_value VAR_RESULT, 2
	goto_eq Route117_PokemonDayCare_EventScript_291F24
	goto Route117_PokemonDayCare_EventScript_291DCA
	end

Route117_PokemonDayCare_EventScript_291F24:: @ 8291F24
	msgbox Route117_PokemonDayCare_Text_29244F, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291E6D
	goto Route117_PokemonDayCare_EventScript_291DCA
	end

Route117_PokemonDayCare_EventScript_291F3D:: @ 8291F3D
	msgbox Route117_PokemonDayCare_Text_2924EF, 4
	release
	end

Route117_PokemonDayCare_Movement_291F47: @ 8291F47
	step_14
	step_14
	step_02
	step_14
	step_14
	step_03
	step_14
	step_14
	step_01
	slow_step_up
	step_54
	step_14
	step_14
	step_14
	step_14
	step_14
	step_00
	step_55
	slow_step_down
	step_end

	.incbin "baserom.gba", 0x291f5b, 0x1

Route117_PokemonDayCare_EventScript_291F5C:: @ 8291F5C
	msgbox Route117_PokemonDayCare_Text_292488, 4
	setvar VAR_0x8004, 0
	call Route117_PokemonDayCare_EventScript_291E1E
	setvar VAR_0x8004, 1
	call Route117_PokemonDayCare_EventScript_291E1E
	msgbox Route117_PokemonDayCare_Text_2925F6, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq Route117_PokemonDayCare_EventScript_291E6D
	msgbox Route117_PokemonDayCare_Text_292476, 4
	release
	end

	.incbin "baserom.gba", 0x291f95, 0x2b

gUnknown_08291FC0:: @ 8291FC0

	.incbin "baserom.gba", 0x291fc0, 0xf

Route117_Text_291FCF: @ 8291FCF
	.string "I’m the DAY-CARE MAN.\p"
	.string "I help take care of the precious\n"
	.string "POKéMON of TRAINERS.\p"
	.string "If you’d like me to raise your POKéMON,\n"
	.string "have a word with my wife.$"

Route117_Text_29205D: @ 829205D
	.string "Ah, it’s you!\p"
	.string "We were raising your POKéMON,\n"
	.string "and my goodness, were we surprised!\p"
	.string "Your POKéMON had an EGG!\p"
	.string "We don’t know how it got there,\n"
	.string "but your POKéMON had it.\p"
	.string "You do want it, yes?$"

Route117_Text_292114: @ 8292114
	.string "Ah, it’s you! Good to see you.\n"
	.string "Your {STR_VAR_1}’s doing fine.$"

Route117_Text_292149: @ 8292149
	.string "Well then, I’ll keep it.\n"
	.string "Thanks!$"

Route117_Text_29216A: @ 829216A
	.string "You have no room for it…\n"
	.string "Come back when you’ve made room.$"

Route117_Text_2921A4: @ 82921A4
	.string "{PLAYER} received the EGG from\n"
	.string "the DAY-CARE MAN.$"

Route117_Text_2921CF: @ 82921CF
	.string "Take good care of it.$"

Route117_Text_2921E5: @ 82921E5
	.string "By the way, about your {STR_VAR_1},\n"
	.string "it seemed to be friendly with\l"
	.string "{STR_VAR_2}’s {STR_VAR_3}.\p"
	.string "I may even have seen it receiving\n"
	.string "a piece of MAIL.$"

	.incbin "baserom.gba", 0x29225a, 0x3f

Route117_Text_292299: @ 8292299
	.string "Ah, it’s you! Your {STR_VAR_1} and\n"
	.string "{STR_VAR_2} are doing fine.$"

Route117_Text_2922C6: @ 82922C6
	.string "I really will keep it.\n"
	.string "You do want this, yes?$"

Route117_PokemonDayCare_Text_2922F4: @ 82922F4
	.string "I’m the DAY-CARE LADY.\p"
	.string "We can raise POKéMON for you.\p"
	.string "Would you like us to raise one?$"

Route117_PokemonDayCare_Text_292349: @ 8292349
	.string "Which POKéMON should we raise for\n"
	.string "you?$"

Route117_PokemonDayCare_Text_292370: @ 8292370
	.string "Fine, we’ll raise your {STR_VAR_1}\n"
	.string "for a while.\p"
	.string "Come back for it later.$"

Route117_PokemonDayCare_Text_2923AF: @ 82923AF
	.string "We can raise two of your POKéMON.\n"
	.string "Would you like us to raise one more?$"

Route117_PokemonDayCare_Text_2923F6: @ 82923F6
	.string "My husband was looking for you.$"

Route117_PokemonDayCare_Text_292416: @ 8292416
	.string "Oh, fine, then.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_292432: @ 8292432
	.string "You don’t have enough money…$"

Route117_PokemonDayCare_Text_29244F: @ 829244F
	.string "Will you take back the other one,\n"
	.string "too?$"

Route117_PokemonDayCare_Text_292476: @ 8292476
	.string "Fine.\n"
	.string "Come again.$"

Route117_PokemonDayCare_Text_292488: @ 8292488
	.string "Ah, it’s you! Good to see you.\n"
	.string "Your POKéMON can only be doing good!$"

Route117_PokemonDayCare_Text_2924CC: @ 82924CC
	.string "By level, your {STR_VAR_1} has\n"
	.string "grown by {STR_VAR_2}.$"

Route117_PokemonDayCare_Text_2924EF: @ 82924EF
	.string "Your POKéMON team is full.\n"
	.string "Make room, then come see me.$"

	.incbin "baserom.gba", 0x292527, 0x22

Route117_PokemonDayCare_Text_292549: @ 8292549
	.string "If you want your {STR_VAR_1} back,\n"
	.string "it will cost ¥{STR_VAR_2}.$"

Route117_PokemonDayCare_Text_292575: @ 8292575
	.string "Perfect!\n"
	.string "Here’s your POKéMON.$"

Route117_PokemonDayCare_Text_292593: @ 8292593
	.string "{PLAYER} took back {STR_VAR_1} from\n"
	.string "the DAY-CARE LADY.$"

Route117_PokemonDayCare_Text_2925BB: @ 82925BB
	.string "Oh? But you have just one\n"
	.string "POKéMON.\p"
	.string "Come back another time.$"

Route117_PokemonDayCare_Text_2925F6: @ 82925F6
	.string "Will you take your POKéMON back?$"

Route117_PokemonDayCare_Text_292617: @ 8292617
	.string "If you leave me that POKéMON,\n"
	.string "what will you battle with?\p"
	.string "Come back another time.$"

	.incbin "baserom.gba", 0x292668, 0x5

Route117_PokemonDayCare_Text_29266D: @ 829266D
	.string "Huh?\n"
	.string "Now, now.\p"
	.string "If you leave that POKéMON with\n"
	.string "me, you’ll be left with just one.\p"
	.string "You will be better off if you catch\n"
	.string "some more, I dare say.$"

gUnknown_082926F8:: @ 82926F8

	.incbin "baserom.gba", 0x2926f8, 0x6

LittlerootTown_BrendansHouse_2F_EventScript_2926FE:: @ 82926FE
LittlerootTown_MaysHouse_2F_EventScript_2926FE:: @ 82926FE
	setvar VAR_0x4092, 5
	return

LittlerootTown_BrendansHouse_1F_EventScript_292704:: @ 8292704
LittlerootTown_MaysHouse_1F_EventScript_292704:: @ 8292704
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A1C, 4
	applymovement VAR_0x8004, LittlerootTown_BrendansHouse_1F_Movement_27259E
	waitmovement 0
	compare_var_to_value VAR_0x8005, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_29274D
	compare_var_to_value VAR_0x8005, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292758
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A46, 4
	closemessage
	setvar VAR_0x4092, 4
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292763
	applymovement VAR_0x8004, LittlerootTown_BrendansHouse_1F_Movement_2725A6
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_29274D:: @ 829274D
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292758:: @ 8292758
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_292763: @ 8292763
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292765:: @ 8292765
LittlerootTown_MaysHouse_1F_EventScript_292765:: @ 8292765
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7B24, 4
	closemessage
	applymovement VAR_0x8004, LittlerootTown_BrendansHouse_1F_Movement_2725A6
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292AF0
	waitmovement 0
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_292781:: @ 8292781
	lockall
	setvar VAR_0x8004, 0
	goto LittlerootTown_BrendansHouse_2F_EventScript_292799
	end

LittlerootTown_MaysHouse_2F_EventScript_29278D:: @ 829278D
	lockall
	setvar VAR_0x8004, 1
	goto LittlerootTown_MaysHouse_2F_EventScript_292799
	end

LittlerootTown_BrendansHouse_2F_EventScript_292799:: @ 8292799
LittlerootTown_MaysHouse_2F_EventScript_292799:: @ 8292799
	checkflag FLAG_0x051
	goto_eq LittlerootTown_BrendansHouse_2F_EventScript_29283F
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F8668, 4
	call LittlerootTown_BrendansHouse_2F_EventScript_292849
	delay 30
	setvar VAR_0x4092, 6
	setflag FLAG_0x051
	setflag FLAG_0x2F2
	setflag FLAG_0x2F3
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_2927DF
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_BrendansHouse_2F_EventScript_29280F
	playse SE_KAIDAN
	removeobject VAR_0x8008
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_2927DF:: @ 82927DF
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292850
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A8
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F869A, 4
	closemessage
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292857
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_29280F:: @ 829280F
	setvar VAR_0x8008, 14
	addobject VAR_0x8008
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_29285B
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_2F_Movement_2725A4
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_2F_Text_1F869A, 4
	closemessage
	applymovement VAR_0x8008, LittlerootTown_BrendansHouse_2F_Movement_292862
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_29283F:: @ 829283F
	incrementgamestat 45
	fadescreen 1
	special Special_ViewWallClock
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_292849:: @ 8292849
	fadescreen 1
	special Special_StartWallClock
	waitstate
	return

LittlerootTown_BrendansHouse_2F_Movement_292850: @ 8292850
	step_13
	step_down
	step_27
	step_14
	step_13
	step_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_292857: @ 8292857
	step_right
	step_up
	step_13
	step_end

LittlerootTown_BrendansHouse_2F_Movement_29285B: @ 829285B
	step_13
	step_down
	step_28
	step_14
	step_13
	step_right
	step_end

LittlerootTown_BrendansHouse_2F_Movement_292862: @ 8292862
	step_left
	step_up
	step_13
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292866:: @ 8292866
LittlerootTown_MaysHouse_1F_EventScript_292866:: @ 8292866
	setvar VAR_0x4092, 7
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_29286D:: @ 829286D
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2725A8
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_29294B
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292AE0
	waitmovement 0
	playbgm BGM_INTER_V, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7BBC, 4
	closemessage
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2929B7
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292AE6
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_29296C
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7BF1, 4
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7C35, 4
	closemessage
	setvar VAR_0x4001, 1
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_2929BD
	waitmovement 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_292866
	end

LittlerootTown_MaysHouse_1F_EventScript_2928DC:: @ 82928DC
	applymovement VAR_0x8005, LittlerootTown_MaysHouse_1F_Movement_2725A4
	waitmovement 0
	call LittlerootTown_MaysHouse_1F_EventScript_29294B
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_292AE8
	waitmovement 0
	playbgm BGM_INTER_V, 0
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7BBC, 4
	closemessage
	applymovement VAR_0x8005, LittlerootTown_MaysHouse_1F_Movement_2929BA
	waitmovement 0
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_292AEE
	waitmovement 0
	call LittlerootTown_MaysHouse_1F_EventScript_29296C
	applymovement 255, LittlerootTown_MaysHouse_1F_Movement_2725A8
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7BF1, 4
	msgbox LittlerootTown_MaysHouse_1F_Text_1F7C35, 4
	closemessage
	setvar VAR_0x4001, 1
	applymovement VAR_0x8005, LittlerootTown_MaysHouse_1F_Movement_2929C1
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_292866
	end

LittlerootTown_BrendansHouse_1F_EventScript_29294B:: @ 829294B
LittlerootTown_MaysHouse_1F_EventScript_29294B:: @ 829294B
	playse SE_PIN
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_272598
	waitmovement 0
	applymovement VAR_0x8005, LittlerootTown_BrendansHouse_1F_Movement_27259A
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7B96, 4
	closemessage
	return

LittlerootTown_BrendansHouse_1F_EventScript_29296C:: @ 829296C
LittlerootTown_MaysHouse_1F_EventScript_29296C:: @ 829296C
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A6
	waitmovement 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EC6, 4
	fadedefaultbgm
	special TurnOffTVScreen
	setflag FLAG_SYS_TV_HOME
	delay 35
	return

LittlerootTown_BrendansHouse_1F_Movement_292989: @ 8292989
	step_up
	step_right
	step_right
	step_right
	step_right
	step_down
	step_28
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292991: @ 8292991
	step_up
	step_left
	step_left
	step_left
	step_left
	step_down
	step_27
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292999: @ 8292999
	step_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299B: @ 829299B
	step_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_29299D: @ 829299D
	step_27
	step_14
	step_14
	step_14
	step_14
	step_28
	step_14
	step_14
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929A6: @ 82929A6
	step_28
	step_14
	step_14
	step_14
	step_14
	step_27
	step_14
	step_14
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929AF: @ 82929AF
	step_up
	step_left
	step_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B3: @ 82929B3
	step_up
	step_right
	step_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929B7: @ 82929B7
	step_left
	step_28
	step_end

LittlerootTown_MaysHouse_1F_Movement_2929BA: @ 82929BA
	step_right
	step_27
	step_end

LittlerootTown_BrendansHouse_1F_Movement_2929BD: @ 82929BD
	step_left
	step_down
	step_28
	step_end

LittlerootTown_MaysHouse_1F_Movement_2929C1: @ 82929C1
	step_right
	step_down
	step_27
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_2929C5:: @ 82929C5
LittlerootTown_MaysHouse_1F_EventScript_2929C5:: @ 82929C5
	lock
	faceplayer
	compare_var_to_value VAR_0x4082, 4
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	compare_var_to_value VAR_0x408C, 4
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A0F
	checkflag FLAG_0x12F
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A19
	checkflag FLAG_0x052
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A86
	compare_var_to_value VAR_0x4001, 1
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A94
	compare_var_to_value VAR_0x4092, 7
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292AB0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7A1C, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A0F:: @ 8292A0F
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7DBE, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A19:: @ 8292A19
	checkflag FLAG_0x0D8
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A43
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7E0E, 4
	closemessage
	delay 30
	playfanfare BGM_ME_MATCH_CALL
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7E89, 4
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_0x0D8
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A43:: @ 8292A43
	checkflag FLAG_BADGE05_GET
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A51
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A86

LittlerootTown_BrendansHouse_1F_EventScript_292A51:: @ 8292A51
	checkflag FLAG_0x085
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_292A86
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D73, 4
	giveitem_std ITEM_AMULET_COIN
	compare_var_to_value VAR_RESULT, 0
	goto_eq LittlerootTown_BrendansHouse_1F_EventScript_272054
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7DBE, 4
	setflag FLAG_0x085
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A86:: @ 8292A86
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D08, 4
	goto LittlerootTown_BrendansHouse_1F_EventScript_292A9E
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A94:: @ 8292A94
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7CC3, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292A9E:: @ 8292A9E
	closemessage
	call LittlerootTown_BrendansHouse_1F_EventScript_272083
	incrementgamestat 16
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7D5C, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292AB0:: @ 8292AB0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7CD8, 4
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ABA:: @ 8292ABA
LittlerootTown_MaysHouse_1F_EventScript_292ABA:: @ 8292ABA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EA8, 4
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_292ACD:: @ 8292ACD
LittlerootTown_MaysHouse_1F_EventScript_292ACD:: @ 8292ACD
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIGOROTH, 0
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F7EB3, 4
	waitmoncry
	release
	end

LittlerootTown_BrendansHouse_1F_Movement_292AE0: @ 8292AE0
	step_down
	step_down
	step_left
	step_left
	step_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292AE6: @ 8292AE6
	step_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_292AE8: @ 8292AE8
	step_down
	step_down
	step_right
	step_right
	step_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_292AEE: @ 8292AEE
	step_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292AF0: @ 8292AF0
	step_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_292AF2:: @ 8292AF2
LittlerootTown_MaysHouse_1F_EventScript_292AF2:: @ 8292AF2
	lockall
	checkplayergender
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292C76
	compare_var_to_value VAR_RESULT, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292C86
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D08
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D13
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_27259E
	waitmovement 0
	playse SE_PIN
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_272598
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_27259A
	waitmovement 0
	delay 20
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292C96
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292CA1
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F800E, 4
	giveitem_std ITEM_SS_TICKET
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F80FE, 4
	closemessage
	delay 20
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292CAC
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292CC1
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F815B, 4
	closemessage
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292CD6
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292CEF
	playse SE_DOOR
	removeobject VAR_0x8009
	setflag FLAG_0x123
	delay 30
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D48
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D5D
	delay 20
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F81B9, 4
	closemessage
	setflag FLAG_SYS_TV_LATI
	special TurnOnTVScreen
	delay 60
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D72
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D7D
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F824B, 4
	closemessage
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D1E
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D33
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F826F, 4
	closemessage
	clearflag FLAG_SYS_TV_LATI
	setflag FLAG_0x0FF
	special TurnOffTVScreen
	compare_var_to_value VAR_0x8008, 0
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D88
	compare_var_to_value VAR_0x8008, 1
	call_if 1, LittlerootTown_BrendansHouse_1F_EventScript_292D9D
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F8351, 4
	multichoice 22, 8, 108, 1
	copyvar VAR_0x8004, VAR_RESULT
	special InitRoamer
	copyvar VAR_0x40D5, VAR_RESULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_1F83A1, 4
	closemessage
	setvar VAR_0x4082, 4
	setvar VAR_0x408C, 4
	releaseall
	end

	.incbin "baserom.gba", 0x292c72, 0x4

LittlerootTown_BrendansHouse_1F_EventScript_292C76:: @ 8292C76
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C86:: @ 8292C86
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 1
	return

LittlerootTown_BrendansHouse_1F_EventScript_292C96:: @ 8292C96
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CA1:: @ 8292CA1
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB5
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CAC:: @ 8292CAC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292989
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DB8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CC1:: @ 8292CC1
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292991
	waitmovement 0
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBA
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CD6:: @ 8292CD6
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DBC
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292CEF:: @ 8292CEF
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292DCC
	applymovement VAR_0x8009, LittlerootTown_BrendansHouse_1F_Movement_292DC1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D08:: @ 8292D08
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DC6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D13:: @ 8292D13
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DD1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D1E:: @ 8292D1E
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DD7
	waitmovement 0
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D33:: @ 8292D33
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_292DDE
	waitmovement 0
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2725A8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D48:: @ 8292D48
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_292999
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D5D:: @ 8292D5D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299B
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D72:: @ 8292D72
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_29299D
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D7D:: @ 8292D7D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929A6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D88:: @ 8292D88
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929AF
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A8
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_292D9D:: @ 8292D9D
	applymovement VAR_0x800A, LittlerootTown_BrendansHouse_1F_Movement_2929B3
	waitmovement 0
	applymovement 255, LittlerootTown_BrendansHouse_1F_Movement_2725A4
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_292DB2: @ 8292DB2
	step_right
	step_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB5: @ 8292DB5
	step_left
	step_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DB8: @ 8292DB8
	step_02
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBA: @ 8292DBA
	step_03
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DBC: @ 8292DBC
	step_down
	step_right
	step_down
	step_13
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC1: @ 8292DC1
	step_down
	step_left
	step_down
	step_13
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DC6: @ 8292DC6
	step_14
	step_down
	step_down
	step_down
	step_27
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DCC: @ 8292DCC
	step_13
	step_14
	step_14
	step_25
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD1: @ 8292DD1
	step_14
	step_down
	step_down
	step_down
	step_28
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DD7: @ 8292DD7
	step_up
	step_left
	step_left
	step_left
	step_left
	step_26
	step_end

LittlerootTown_BrendansHouse_1F_Movement_292DDE: @ 8292DDE
	step_up
	step_right
	step_right
	step_right
	step_right
	step_26
	step_end

gUnknown_08292DE5:: @ 8292DE5

	.incbin "baserom.gba", 0x292de5, 0x9

LilycoveCity_ContestLobby_Text_292DEE: @ 8292DEE
	.string "Oh? Did you want to make some {POKEBLOCK}S\n"
	.string "with this old-timer?$"

LilycoveCity_ContestLobby_Text_292E28: @ 8292E28
	.string "Excellent!$"

LilycoveCity_ContestLobby_Text_292E33: @ 8292E33
	.string "Oh…\n"
	.string "You’ve made this old-timer sad…$"

LilycoveCity_ContestLobby_Text_292E57: @ 8292E57
	.string "Do you know how to make a {POKEBLOCK}?$"

LilycoveCity_ContestLobby_Text_292E78: @ 8292E78
	.string "Let’s get started, then!\p"
	.string "Let’s BERRY BLENDER!$"

LilycoveCity_ContestLobby_Text_292EA6: @ 8292EA6
	.string "Okay, a little explanation, then.\p"
	.string "Oh, don’t worry, it’s quite simple.\p"
	.string "When the BLENDER’s arrow comes to\n"
	.string "your marker, just press the A Button.\p"
	.string "That’s all you have to do.\n"
	.string "You’ll see how easy it is when you try.$"

LilycoveCity_ContestLobby_Text_292F77: @ 8292F77
	.string "Oh?\n"
	.string "You don’t have any BERRIES?\p"
	.string "If you don’t have any BERRIES,\n"
	.string "you can’t make any {POKEBLOCK}S.$"

LilycoveCity_ContestLobby_Text_292FD1: @ 8292FD1
	.string "Well, that won’t do at all now, will it?\p"
	.string "If you don’t mind leftovers, you can\n"
	.string "have one of my BERRIES.\p"
	.string "That way, we could make some {POKEBLOCK}S\n"
	.string "together using the BERRY BLENDER.$"

LilycoveCity_ContestLobby_Text_29307D: @ 829307D
	.string "If I had some BERRIES left over,\n"
	.string "I’d gladly give you one…\p"
	.string "But, I don’t have any to spare today.\n"
	.string "We’ll have to do this another time.$"

LilycoveCity_ContestLobby_Text_293101: @ 8293101
	.string "But your {POKEBLOCK} CASE is full.\p"
	.string "You should use some {POKEBLOCK}S before\n"
	.string "you come see me again.$"

LilycoveCity_ContestLobby_Text_293157: @ 8293157
	.string "But you don’t have a {POKEBLOCK} CASE.\p"
	.string "You should get a {POKEBLOCK} CASE and then\n"
	.string "come see me.$"

LilycoveCity_ContestLobby_Text_2931AA: @ 82931AA
	.string "Let’s get blending already!$"

LilycoveCity_ContestLobby_Text_2931C6: @ 82931C6
	.string "I wonder what kind of {POKEBLOCK} I’ll get?\n"
	.string "This is so exciting!$"

LilycoveCity_ContestLobby_Text_293201: @ 8293201
	.string "Hi, there! Did you want to blend some\n"
	.string "{POKEBLOCK}S with us?$"

LilycoveCity_ContestLobby_Text_293237: @ 8293237
	.string "Okay!$"

LilycoveCity_ContestLobby_Text_29323D: @ 829323D
	.string "That’s too bad…\p"
	.string "But we’ll always be around whenever\n"
	.string "you get the urge to blend!$"

LilycoveCity_ContestLobby_Text_29328C: @ 829328C
	.string "Of course, you do know how to\n"
	.string "blend {POKEBLOCK}S, don’t you?$"

LilycoveCity_ContestLobby_Text_2932C3: @ 82932C3
	.string "Let’s get started, then!\p"
	.string "Let’s BERRY BLENDER!$"

LilycoveCity_ContestLobby_Text_2932F1: @ 82932F1
	.string "Okay!\n"
	.string "Let me explain it to you!\p"
	.string "When the spinning BLENDER’s arrow\n"
	.string "reaches your marker, just press\l"
	.string "the A Button.\p"
	.string "That’s all it takes.\n"
	.string "Pretty easy, don’t you think?$"

LilycoveCity_ContestLobby_Text_293394: @ 8293394
	.string "Oh, but wait a second here…\n"
	.string "You don’t have any BERRIES.\p"
	.string "You can’t make any {POKEBLOCK}S without\n"
	.string "BERRIES…\p"
	.string "We’ll always be around whenever you\n"
	.string "get hold of some BERRIES to blend.$"

LilycoveCity_ContestLobby_Text_29343E: @ 829343E
	.string "Oh, but wait a second here…\n"
	.string "Your {POKEBLOCK} CASE is full.\p"
	.string "You should use some {POKEBLOCK}S and\n"
	.string "then come back.$"

LilycoveCity_ContestLobby_Text_2934A2: @ 82934A2
	.string "Oh, but wait a second here…\n"
	.string "You don’t have a {POKEBLOCK} CASE.\p"
	.string "You should get a {POKEBLOCK} CASE and\n"
	.string "then come back.$"

	.incbin "baserom.gba", 0x29350b, 0x43

LilycoveCity_ContestLobby_Text_29354E: @ 829354E
	.string "Oh, dear!$"

LilycoveCity_ContestLobby_Text_293558: @ 8293558
	.string "Oh, dear me…\p"
	.string "You’ve left us in shock!$"

LilycoveCity_ContestLobby_Text_29357E: @ 829357E
	.string "Naturally, you know how to make\n"
	.string "{POKEBLOCK}S, don’t you?$"

LilycoveCity_ContestLobby_Text_2935B1: @ 82935B1
	.string "Okay, dear!\n"
	.string "Let’s get started!\p"
	.string "Let’s BERRY BLENDER!$"

LilycoveCity_ContestLobby_Text_2935E5: @ 82935E5
	.string "Oh, dear!\p"
	.string "Then, I’ll explain it to you nicely.\p"
	.string "When the BLENDER’s arrow spins to\n"
	.string "your marker, press the A Button.\p"
	.string "That’s all it takes.\n"
	.string "Isn’t it simple?$"

LilycoveCity_ContestLobby_Text_29367D: @ 829367D
	.string "You don’t have any BERRIES,\n"
	.string "do you?\p"
	.string "If you don’t have any BERRIES,\n"
	.string "you can’t make any {POKEBLOCK}S.\p"
	.string "We’ll always be making {POKEBLOCK}S here,\n"
	.string "so let’s make some together when\l"
	.string "you get a BERRY or two.$"

LilycoveCity_ContestLobby_Text_293738: @ 8293738
	.string "Your {POKEBLOCK} CASE is full,\n"
	.string "it looks like.\p"
	.string "You should use some {POKEBLOCK}S up\n"
	.string "and then come back.$"

LilycoveCity_ContestLobby_Text_293792: @ 8293792
	.string "You haven’t gotten a {POKEBLOCK} CASE\n"
	.string "yet, it looks like.\p"
	.string "You need to get a {POKEBLOCK} CASE before\n"
	.string "you come back.$"

LilycoveCity_ContestLobby_Text_2937F9: @ 82937F9
	.string "Okay! Today’s going to be the day that\n"
	.string "I set a new BLENDER speed record!$"

LilycoveCity_ContestLobby_Text_293842: @ 8293842
	.string "Oh, dear!\n"
	.string "You look as if you’re good at blending.\l"
	.string "Would you like to join us?$"

LilycoveCity_ContestLobby_Text_29388F: @ 829388F
	.string "I’m going to make delicious {POKEBLOCK}S\n"
	.string "and make my POKéMON cuter.$"

LilycoveCity_ContestLobby_Text_2938CD: @ 82938CD
	.string "{POKEBLOCK}S will be made with your friends \n"
	.string "from BERRIES in the BERRY BLENDER.\p"
	.string "Is it okay to save the game before\n"
	.string "linking with your friends?$"

LilycoveCity_ContestLobby_Text_293955: @ 8293955
	.string "Searching for your friends…\n"
	.string "… … B Button: Cancel$"

LilycoveCity_ContestLobby_Text_293986: @ 8293986
	.string "{STR_VAR_1} arrived.$"

LilycoveCity_ContestLobby_Text_293992: @ 8293992
	.string "{STR_VAR_1} and {STR_VAR_2} arrived.$"

LilycoveCity_ContestLobby_Text_2939A5: @ 82939A5
	.string "{STR_VAR_1}, {STR_VAR_2}, and\n"
	.string "{STR_VAR_3} arrived.$"

LilycoveCity_ContestLobby_Text_2939BD: @ 82939BD
	.string "You have no BERRIES.\n"
	.string "The BERRY BLENDER can’t be used.$"

LilycoveCity_ContestLobby_Text_2939F3: @ 82939F3
	.string "Your {POKEBLOCK} CASE is full.\n"
	.string "The BERRY BLENDER can’t be used.$"

LilycoveCity_ContestLobby_Text_293A2D: @ 8293A2D
	.string "You don’t have a {POKEBLOCK} CASE.\n"
	.string "The BERRY BLENDER can’t be used.$"

LilycoveCity_ContestLobby_Text_293A6B: @ 8293A6B
	.string "I love making {POKEBLOCK}S.\p"
	.string "I always have some BERRIES with me.$"

LilycoveCity_ContestLobby_Text_293AA5: @ 8293AA5
	.string "If you’d like, we could make some\n"
	.string "{POKEBLOCK}S together using the\l"
	.string "BERRY BLENDER.$"

LilycoveCity_ContestLobby_Text_293AF0: @ 8293AF0
	.string "Oh?\n"
	.string "You don’t have any BERRIES?\p"
	.string "Well, that won’t do at all now, will it?\p"
	.string "If you don’t mind leftovers, you can\n"
	.string "have one of my BERRIES.$"

LilycoveCity_ContestLobby_Text_293B76: @ 8293B76
	.string "We’ll use it to make {POKEBLOCK}S together\n"
	.string "using the BERRY BLENDER.$"

LilycoveCity_ContestLobby_Text_293BB4: @ 8293BB4
	.string "Oh?\n"
	.string "You don’t have any BERRIES?\p"
	.string "If I had some left over, I’d gladly\n"
	.string "give you one…\p"
	.string "But, I don’t have any to spare today.\n"
	.string "Sorry about that.$"

LilycoveCity_ContestLobby_EventScript_293C3E:: @ 8293C3E
	lockall
	checkflag FLAG_0x340
	goto_if 0, LilycoveCity_ContestLobby_EventScript_293EFB
	setvar VAR_0x8009, 1
	applymovement 16, LilycoveCity_ContestLobby_Movement_294053
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_292DEE, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293CEE
	goto LilycoveCity_ContestLobby_EventScript_293C70
	end

LilycoveCity_ContestLobby_EventScript_293C70:: @ 8293C70
	msgbox LilycoveCity_ContestLobby_Text_292E33, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293C7A:: @ 8293C7A
	msgbox LilycoveCity_ContestLobby_Text_292F77, 4
	dodailyevents
	checkflag FLAG_0x921
	goto_eq LilycoveCity_ContestLobby_EventScript_293C92
	goto LilycoveCity_ContestLobby_EventScript_293C9C
	end

LilycoveCity_ContestLobby_EventScript_293C92:: @ 8293C92
	msgbox LilycoveCity_ContestLobby_Text_29307D, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293C9C:: @ 8293C9C
	msgbox LilycoveCity_ContestLobby_Text_292FD1, 4
	giveitem_std ITEM_PECHA_BERRY
	setflag FLAG_0x921
	goto LilycoveCity_ContestLobby_EventScript_293CB9
	end

LilycoveCity_ContestLobby_EventScript_293CB9:: @ 8293CB9
	msgbox LilycoveCity_ContestLobby_Text_292E57, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293CD2
	goto LilycoveCity_ContestLobby_EventScript_293CE0
	end

LilycoveCity_ContestLobby_EventScript_293CD2:: @ 8293CD2
	msgbox LilycoveCity_ContestLobby_Text_292E78, 4
	goto LilycoveCity_ContestLobby_EventScript_293D2C
	end

LilycoveCity_ContestLobby_EventScript_293CE0:: @ 8293CE0
	msgbox LilycoveCity_ContestLobby_Text_292EA6, 4
	goto LilycoveCity_ContestLobby_EventScript_293CD2
	end

LilycoveCity_ContestLobby_EventScript_293CEE:: @ 8293CEE
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293D43
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_293D39
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293C7A
	msgbox LilycoveCity_ContestLobby_Text_292E28, 4
	goto LilycoveCity_ContestLobby_EventScript_293CB9
	end

LilycoveCity_ContestLobby_EventScript_293D2C:: @ 8293D2C
	copyvar VAR_0x8004, VAR_0x8009
	fadescreen 1
	special sub_807FA80
	waitstate
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293D39:: @ 8293D39
	msgbox LilycoveCity_ContestLobby_Text_293101, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293D43:: @ 8293D43
	msgbox LilycoveCity_ContestLobby_Text_293157, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293D4D:: @ 8293D4D
	lockall
	setvar VAR_0x8009, 2
	applymovement 10, LilycoveCity_ContestLobby_Movement_2725A2
	applymovement 3, LilycoveCity_ContestLobby_Movement_294053
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_293201, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293DC6
	goto LilycoveCity_ContestLobby_EventScript_293D7D
	end

LilycoveCity_ContestLobby_EventScript_293D7D:: @ 8293D7D
	msgbox LilycoveCity_ContestLobby_Text_29323D, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293D87:: @ 8293D87
	msgbox LilycoveCity_ContestLobby_Text_293394, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_293D91:: @ 8293D91
	msgbox LilycoveCity_ContestLobby_Text_29328C, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293DAA
	goto LilycoveCity_ContestLobby_EventScript_293DB8
	end

LilycoveCity_ContestLobby_EventScript_293DAA:: @ 8293DAA
	msgbox LilycoveCity_ContestLobby_Text_2932C3, 4
	goto LilycoveCity_ContestLobby_EventScript_293D2C
	end

LilycoveCity_ContestLobby_EventScript_293DB8:: @ 8293DB8
	msgbox LilycoveCity_ContestLobby_Text_2932F1, 4
	goto LilycoveCity_ContestLobby_EventScript_293DAA
	end

LilycoveCity_ContestLobby_EventScript_293DC6:: @ 8293DC6
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293D87
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293E14
	msgbox LilycoveCity_ContestLobby_Text_293237, 4
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_if 5, LilycoveCity_ContestLobby_EventScript_293D91
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_293E0A
	end

LilycoveCity_ContestLobby_EventScript_293E0A:: @ 8293E0A
	msgbox LilycoveCity_ContestLobby_Text_29343E, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293E14:: @ 8293E14
	msgbox LilycoveCity_ContestLobby_Text_2934A2, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293E1E:: @ 8293E1E
	lockall
	setvar VAR_0x8008, 15
	setvar VAR_0x8009, 3
	applymovement 9, LilycoveCity_ContestLobby_Movement_2725A2
	applymovement 17, LilycoveCity_ContestLobby_Movement_2725A2
	applymovement VAR_0x8008, LilycoveCity_ContestLobby_Movement_294053
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_293842, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293EA3
	goto LilycoveCity_ContestLobby_EventScript_293E5A
	end

LilycoveCity_ContestLobby_EventScript_293E5A:: @ 8293E5A
	msgbox LilycoveCity_ContestLobby_Text_293558, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293E64:: @ 8293E64
	msgbox LilycoveCity_ContestLobby_Text_29367D, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_293E6E:: @ 8293E6E
	msgbox LilycoveCity_ContestLobby_Text_29357E, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293E87
	goto LilycoveCity_ContestLobby_EventScript_293E95
	end

LilycoveCity_ContestLobby_EventScript_293E87:: @ 8293E87
	msgbox LilycoveCity_ContestLobby_Text_2935B1, 4
	goto LilycoveCity_ContestLobby_EventScript_293D2C
	end

LilycoveCity_ContestLobby_EventScript_293E95:: @ 8293E95
	msgbox LilycoveCity_ContestLobby_Text_2935E5, 4
	goto LilycoveCity_ContestLobby_EventScript_293E87
	end

LilycoveCity_ContestLobby_EventScript_293EA3:: @ 8293EA3
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293E64
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293EF1
	msgbox LilycoveCity_ContestLobby_Text_29354E, 4
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_if 5, LilycoveCity_ContestLobby_EventScript_293E6E
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_293EE7
	end

LilycoveCity_ContestLobby_EventScript_293EE7:: @ 8293EE7
	msgbox LilycoveCity_ContestLobby_Text_293738, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293EF1:: @ 8293EF1
	msgbox LilycoveCity_ContestLobby_Text_293792, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293EFB:: @ 8293EFB
	lockall
	setvar VAR_0x8009, 1
	msgbox LilycoveCity_ContestLobby_Text_2C42F4, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293F28
	msgbox LilycoveCity_ContestLobby_Text_2C4332, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293F1E:: @ 8293F1E
	msgbox LilycoveCity_ContestLobby_Text_2C439D, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293F28:: @ 8293F28
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293F8E
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293F1E
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_if 5, LilycoveCity_ContestLobby_EventScript_293F64
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_293F98
	end

LilycoveCity_ContestLobby_EventScript_293F64:: @ 8293F64
	msgbox LilycoveCity_ContestLobby_Text_2C43FA, 5
	compare_var_to_value VAR_RESULT, 0
	call_if 1, LilycoveCity_ContestLobby_EventScript_293F85
	msgbox LilycoveCity_ContestLobby_Text_2C451B, 4
	goto LilycoveCity_ContestLobby_EventScript_293D2C
	end

LilycoveCity_ContestLobby_EventScript_293F85:: @ 8293F85
	msgbox LilycoveCity_ContestLobby_Text_2C444C, 4
	return

LilycoveCity_ContestLobby_EventScript_293F8E:: @ 8293F8E
	msgbox LilycoveCity_ContestLobby_Text_2C4573, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293F98:: @ 8293F98
	msgbox LilycoveCity_ContestLobby_Text_2C45E8, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_293FA2:: @ 8293FA2
	msgbox LilycoveCity_ContestLobby_Text_2937F9, 2
	end

LilycoveCity_ContestLobby_EventScript_293FAB:: @ 8293FAB
	msgbox LilycoveCity_ContestLobby_Text_293842, 2
	end

LilycoveCity_ContestLobby_EventScript_293FB4:: @ 8293FB4
	msgbox LilycoveCity_ContestLobby_Text_29388F, 2
	end

LilycoveCity_ContestLobby_EventScript_293FBD:: @ 8293FBD
	setvar VAR_0x8008, 15
	goto LilycoveCity_ContestLobby_EventScript_293FC8
	end

LilycoveCity_ContestLobby_EventScript_293FC8:: @ 8293FC8
	lock
	faceplayer
	msgbox LilycoveCity_ContestLobby_Text_293A6B, 4
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_293FEE
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_293FF8
	end

LilycoveCity_ContestLobby_EventScript_293FEE:: @ 8293FEE
	msgbox LilycoveCity_ContestLobby_Text_293AA5, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_293FF8:: @ 8293FF8
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_294028
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_294028
	dodailyevents
	checkflag FLAG_0x921
	goto_eq LilycoveCity_ContestLobby_EventScript_294028
	goto LilycoveCity_ContestLobby_EventScript_294032
	end

LilycoveCity_ContestLobby_EventScript_294028:: @ 8294028
	msgbox LilycoveCity_ContestLobby_Text_293BB4, 4
	release
	end

LilycoveCity_ContestLobby_EventScript_294032:: @ 8294032
	msgbox LilycoveCity_ContestLobby_Text_293AF0, 4
	giveitem_std ITEM_PECHA_BERRY
	setflag FLAG_0x921
	msgbox LilycoveCity_ContestLobby_Text_293B76, 4
	release
	end

LilycoveCity_ContestLobby_Movement_294053: @ 8294053
	step_28
	step_end

LilycoveCity_ContestLobby_EventScript_294055:: @ 8294055
	lockall
	specialvar VAR_RESULT, PlayerHasBerries
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_2940B1
	checkitem ITEM_POKEBLOCK_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_29416C
	specialvar VAR_RESULT, sub_8136EF4
	compare_var_to_value VAR_RESULT, 65535
	goto_if 5, LilycoveCity_ContestLobby_EventScript_294092
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_ContestLobby_EventScript_294162
	end

LilycoveCity_ContestLobby_EventScript_294092:: @ 8294092
	msgbox LilycoveCity_ContestLobby_Text_2938CD, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_2940BB
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_294160
	end

LilycoveCity_ContestLobby_EventScript_2940B1:: @ 82940B1
	msgbox LilycoveCity_ContestLobby_Text_2939BD, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_2940BB:: @ 82940BB
	call LilycoveCity_ContestLobby_EventScript_27134F
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_ContestLobby_EventScript_294160
	specialvar VAR_RESULT, sub_80093CC
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_2941ED
	message LilycoveCity_ContestLobby_Text_293955
	waitmessage
	special sub_80B2FD8
	waitstate
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_2941AA
	compare_var_to_value VAR_RESULT, 2
	goto_eq LilycoveCity_ContestLobby_EventScript_294176
	compare_var_to_value VAR_RESULT, 3
	goto_eq LilycoveCity_ContestLobby_EventScript_294183
	compare_var_to_value VAR_RESULT, 5
	goto_eq LilycoveCity_ContestLobby_EventScript_294190
	compare_var_to_value VAR_RESULT, 6
	goto_eq LilycoveCity_ContestLobby_EventScript_29419D
	end

LilycoveCity_ContestLobby_EventScript_29411D:: @ 829411D
	msgbox LilycoveCity_ContestLobby_Text_293986, 4
	goto LilycoveCity_ContestLobby_EventScript_294147
	end

LilycoveCity_ContestLobby_EventScript_29412B:: @ 829412B
	msgbox LilycoveCity_ContestLobby_Text_293992, 4
	goto LilycoveCity_ContestLobby_EventScript_294147
	end

LilycoveCity_ContestLobby_EventScript_294139:: @ 8294139
	msgbox LilycoveCity_ContestLobby_Text_2939A5, 4
	goto LilycoveCity_ContestLobby_EventScript_294147
	end

LilycoveCity_ContestLobby_EventScript_294147:: @ 8294147
	setvar VAR_0x8004, 0
	fadescreen 1
	removeobject 240
	removeobject 239
	removeobject 238
	removeobject 237
	special sub_807FA80
	waitstate
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_294160:: @ 8294160
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_294162:: @ 8294162
	msgbox LilycoveCity_ContestLobby_Text_2939F3, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_29416C:: @ 829416C
	msgbox LilycoveCity_ContestLobby_Text_293A2D, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_294176:: @ 8294176
	special sub_80097E8
	msgbox LilycoveCity_ContestLobby_Text_2781C7, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_294183:: @ 8294183
	special sub_80097E8
	msgbox LilycoveCity_ContestLobby_Text_278255, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_294190:: @ 8294190
	special sub_80097E8
	msgbox gUnknown_08272D9C, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_29419D:: @ 829419D
	special sub_80097E8
	msgbox LilycoveCity_ContestLobby_Text_27821C, 4
	releaseall
	end

LilycoveCity_ContestLobby_EventScript_2941AA:: @ 82941AA
	fadescreen 1
	specialvar VAR_RESULT, sub_8138240
	copyvar VAR_0x8008, VAR_RESULT
	copyvar VAR_0x8004, VAR_0x8008
	special SpawnLinkPartnerFieldObject
	goto LilycoveCity_ContestLobby_EventScript_2941C4
	end

LilycoveCity_ContestLobby_EventScript_2941C4:: @ 82941C4
	fadescreen 0
	switch VAR_0x8008
	case 2, LilycoveCity_ContestLobby_EventScript_29411D
	case 3, LilycoveCity_ContestLobby_EventScript_29412B
	case 4, LilycoveCity_ContestLobby_EventScript_294139
	end

LilycoveCity_ContestLobby_EventScript_2941ED:: @ 82941ED
	setvar VAR_0x8004, 13
	goto LilycoveCity_ContestLobby_EventScript_2941F8
	end

LilycoveCity_ContestLobby_EventScript_2941F8:: @ 82941F8
	message LilycoveCity_ContestLobby_Text_27C1EA
	waitmessage
	multichoice 16, 6, 81, 0
	switch VAR_RESULT
	case 0, LilycoveCity_ContestLobby_EventScript_29425D
	case 1, LilycoveCity_ContestLobby_EventScript_294235
	case 2, LilycoveCity_ContestLobby_EventScript_294190
	case 127, LilycoveCity_ContestLobby_EventScript_294190
	end

LilycoveCity_ContestLobby_EventScript_294235:: @ 8294235
	call LilycoveCity_ContestLobby_EventScript_294285
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_29428F
	compare_var_to_value VAR_RESULT, 5
	goto_eq LilycoveCity_ContestLobby_EventScript_2941F8
	compare_var_to_value VAR_RESULT, 8
	goto_eq LilycoveCity_ContestLobby_EventScript_294235
	release
	end

LilycoveCity_ContestLobby_EventScript_29425D:: @ 829425D
	call LilycoveCity_ContestLobby_EventScript_29428A
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_ContestLobby_EventScript_29428F
	compare_var_to_value VAR_RESULT, 5
	goto_eq LilycoveCity_ContestLobby_EventScript_2941F8
	compare_var_to_value VAR_RESULT, 8
	goto_eq LilycoveCity_ContestLobby_EventScript_29425D
	release
	end

LilycoveCity_ContestLobby_EventScript_294285:: @ 8294285
	special BerryBlenderLinkBecomeLeader
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_29428A:: @ 829428A
	special BerryBlenderLinkJoinGroup
	waitstate
	return

LilycoveCity_ContestLobby_EventScript_29428F:: @ 829428F
	goto LilycoveCity_ContestLobby_EventScript_2941AA
	end

	.incbin "baserom.gba", 0x294295, 0x68

gUnknown_082942FD:: @ 82942FD
	.incbin "baserom.gba", 0x2942fd, 0x4

gUnknown_08294301:: @ 8294301

	.incbin "baserom.gba", 0x294301, 0x212

Route102_Text_294513: @ 8294513
	.string "If you have POKéMON with you, then\n"
	.string "you’re an official POKéMON TRAINER!\l"
	.string "You can’t say no to my challenge!$"

Route102_Text_29457C: @ 829457C
	.string "Arrgh, I lost…\n"
	.string "I should have trained mine more…$"

Route102_Text_2945AC: @ 82945AC
	.string "Listen, you. If you’re strong,\n"
	.string "you should have told me before!$"

Route102_Text_2945EB: @ 82945EB
	.string "I’ve been working hard at this since\n"
	.string "I saw you before.\p"
	.string "I’d like to battle you again, so can\n"
	.string "you register me in your POKéNAV?$"

Route102_Text_294668: @ 8294668
	.string "I’d like to battle you again, so can\n"
	.string "you register me in your POKéNAV?$"

Route102_Text_2946AE: @ 82946AE
	.string "Ever since I lost to you, I desperately\n"
	.string "trained my POKéMON.\l"
	.string "You can’t say no to my challenge!$"

Route102_Text_29470C: @ 829470C
	.string "Arrgh, I lost…\n"
	.string "Is my training method not right?$"

Route102_Text_29473C: @ 829473C
	.string "If you’re going to get stronger,\n"
	.string "I’ll get stronger, too.$"

Route102_Text_294775: @ 8294775
	.string "Did you just become a TRAINER?\n"
	.string "We’re both beginners!$"

Route102_Text_2947AA: @ 82947AA
	.string "I called you because I thought\n"
	.string "I could beat you…$"

Route102_Text_2947DB: @ 82947DB
	.string "I haven’t won once yet…\n"
	.string "I wish I would win soon…$"

Route102_Text_29480C: @ 829480C
	.string "Hahah! Our eyes met!\n"
	.string "I’ll take you on with my BUG POKéMON!$"

Route102_Text_294847: @ 8294847
	.string "Ow! Down and out!$"

Route102_Text_294859: @ 8294859
	.string "If you lock eyes with a TRAINER,\n"
	.string "you have to challenge! It’s a rule!$"

Route102_Text_29489E: @ 829489E
	.string "I’m going to keep winning and aim\n"
	.string "to be the best TRAINER.\p"
	.string "Help me further my career!$"

Route102_Text_2948F3: @ 82948F3
	.string "I ended up furthering your career…$"

Route102_Text_294916: @ 8294916
	.string "To keep winning my way up, I see that\n"
	.string "I have to catch more POKéMON.$"

Route103_Text_29495A: @ 829495A
	.string "Did you feel the tug of our\n"
	.string "soul-soothing fragrance?$"

Route103_Text_29498F: @ 829498F
	.string "You weren’t led astray by our aroma…$"

Route103_Text_2949B4: @ 82949B4
	.string "Aromatherapy is a form of mental\n"
	.string "healing that works with fragrances.$"

Route103_Text_2949F9: @ 82949F9
	.string "AMY: I’m AMY.\n"
	.string "And this is my little sister LIV.\l"
	.string "We battle together!$"

Route103_Text_294A3D: @ 8294A3D
	.string "AMY: Uh-oh, we lost.$"

Route103_Text_294A52: @ 8294A52
	.string "AMY: You have to think about all\n"
	.string "kinds of things when you’re battling\l"
	.string "against two TRAINERS.$"

Route103_Text_294AAE: @ 8294AAE
	.string "AMY: Uh-oh, you have only one\n"
	.string "POKéMON with you.\l"
	.string "You can’t battle us like that.$"

Route103_Text_294AFD: @ 8294AFD
	.string "LIV: We battle together as one\n"
	.string "team.$"

Route103_Text_294B22: @ 8294B22
	.string "LIV: Oh, we lost, big sister…$"

Route103_Text_294B40: @ 8294B40
	.string "LIV: We work perfectly together,\n"
	.string "me and my big sister…\p"
	.string "But we still lost…$"

Route103_Text_294B8A: @ 8294B8A
	.string "LIV: Really, we’re a lot better…\n"
	.string "It’s true! We’ll show you next time!$"

Route103_Text_294BD0: @ 8294BD0
	.string "LIV: If you want to battle us,\n"
	.string "you have to have two POKéMON!\l"
	.string "It’s not fair if you don’t!$"

Route103_Text_294C29: @ 8294C29
	.string "AMY: I’m AMY.\n"
	.string "And this is my little sister LIV.\l"
	.string "We battle together!$"

Route103_Text_294C6D: @ 8294C6D
	.string "AMY: Aww, boo!\n"
	.string "We couldn’t win again…$"

Route103_Text_294C93: @ 8294C93
	.string "AMY: You have to think about all\n"
	.string "kinds of things when you’re battling\l"
	.string "against two TRAINERS.$"

Route103_Text_294CEF: @ 8294CEF
	.string "AMY: Uh-oh, you have only one\n"
	.string "POKéMON with you.\l"
	.string "You can’t battle us like that.$"

Route103_Text_294D3E: @ 8294D3E
	.string "LIV: We battle together as one\n"
	.string "team.$"

Route103_Text_294D63: @ 8294D63
	.string "LIV: Awww, we lost again…\n"
	.string "Big sister…$"

Route103_Text_294D89: @ 8294D89
	.string "LIV: We work perfectly together,\n"
	.string "me and my big sister…\p"
	.string "But why did we lose again?$"

Route103_Text_294DDB: @ 8294DDB
	.string "LIV: If you want to battle us, you\n"
	.string "have to have two POKéMON!\l"
	.string "It’s not fair if you don’t!$"

Route103_Text_294E34: @ 8294E34
	.string "Gah! My fishing line’s all snarled up!\n"
	.string "I’m getting frustrated and mean!\l"
	.string "That’s it! Battle me!$"

Route103_Text_294E92: @ 8294E92
	.string "Gah! Lost it!\n"
	.string "I’m even more annoyed now!$"

Route103_Text_294EBB: @ 8294EBB
	.string "Gah, I’m still boiling mad…\n"
	.string "Grrrrr…$"

Route103_Text_294EDF: @ 8294EDF
	.string "My POKéMON is delightfully adorable!\n"
	.string "Don’t be shy--I’ll show you!$"

Route103_Text_294F21: @ 8294F21
	.string "Oh, my gosh!\n"
	.string "My darling POKéMON!$"

Route103_Text_294F42: @ 8294F42
	.string "My delightful POKéMON looks darling\n"
	.string "even when it’s fainted!$"

Route103_Text_294F7E: @ 8294F7E
	.string "I’ll get you to come out and look in\n"
	.string "on my delightful POKéMON again!$"

Route103_Text_294FC3: @ 8294FC3
	.string "Hi, you! My delightfully adorable\n"
	.string "POKéMON has become more darling!$"

Route103_Text_295006: @ 8295006
	.string "Oh!\n"
	.string "My darling POKéMON!$"

Route103_Text_29501E: @ 829501E
	.string "The more I spend time with it,\n"
	.string "the more adorable my POKéMON becomes.$"

Route103_Text_295063: @ 8295063
	.string "This sort of distance…\n"
	.string "You should just swim it!$"

Route103_Text_295093: @ 8295093
	.string "Oh, that’s good going!$"

Route103_Text_2950AA: @ 82950AA
	.string "Oh, I understand where you’re coming\n"
	.string "from now.\p"
	.string "If I had a POKéMON that trusty,\n"
	.string "I’d want to SURF on it, too!$"

Route103_Text_295116: @ 8295116
	.string "Watch where you’re going!\n"
	.string "We’re going to crash!$"

Route103_Text_295146: @ 8295146
	.string "Groan…$"

Route103_Text_29514D: @ 829514D
	.string "I’m a poor swimmer so I was practicing…\n"
	.string "Sorry for almost crashing into you.$"

Route103_Text_295199: @ 8295199
	.string "Whoa!\n"
	.string "How’d you get into a space this small?$"

Route103_Text_2951C6: @ 82951C6
	.string "Whoa!\n"
	.string "The kid can rock!$"

Route103_Text_2951DE: @ 82951DE
	.string "Do you like cramped quarters\n"
	.string "like this?$"

Route103_Text_295206: @ 8295206
	.string "Did my guitar’s wailing draw you in?$"

Route103_Text_29522B: @ 829522B
	.string "My one-man show is ruined…$"

Route103_Text_295246: @ 8295246
	.string "I was playing my guitar where few\n"
	.string "people were around, but a lot of fans\l"
	.string "have gathered.\p"
	.string "Heh, maybe I should turn pro.$"

Route104_Text_2952BB: @ 82952BB
	.string "GINA: Okay, let’s battle with our\n"
	.string "POKéMON!$"

Route104_Text_2952E6: @ 82952E6
	.string "GINA: Losing upsets me!$"

Route104_Text_2952FE: @ 82952FE
	.string "GINA: You are strong!\n"
	.string "We have to train lots more!$"

Route104_Text_295330: @ 8295330
	.string "GINA: Oh? Only one POKéMON?\n"
	.string "Then, we don’t battle with you.\p"
	.string "If there’s only one POKéMON, it will\n"
	.string "be lonesome. That’s not nice.$"

Route104_Text_2953AF: @ 82953AF
	.string "MIA: We are twins, so we battle\n"
	.string "POKéMON together.$"

Route104_Text_2953E1: @ 82953E1
	.string "MIA: We battled together, but we\n"
	.string "both lost…$"

Route104_Text_29540D: @ 829540D
	.string "MIA: We will train our POKéMON more\n"
	.string "and be strong like you.$"

Route104_Text_295449: @ 8295449
	.string "MIA: You want to battle with us?\p"
	.string "It’s a big no-no if you don’t have two\n"
	.string "POKéMON with you.\l"
	.string "We’re too strong for you!$"

Route104_Text_2954BD: @ 82954BD
	.string "Why keep it a secret?\n"
	.string "I’m the WATER POKéMON expert!\p"
	.string "Huh?\n"
	.string "You don’t know me?$"

Route104_Text_295509: @ 8295509
	.string "I thought I wasn’t too bad, if I may\n"
	.string "say so, but I guess not… Bleah…$"

Route104_Text_29554E: @ 829554E
	.string "I got too into fishing.\n"
	.string "I forgot I had to raise my POKéMON…$"

Route104_Text_29558A: @ 829558A
	.string "Leaving footprints in the sand is\n"
	.string "so fun!$"

Route104_Text_2955B4: @ 82955B4
	.string "Waah! I got sand in my runners!\n"
	.string "They’re all gritty!$"

Route104_Text_2955E8: @ 82955E8
	.string "I want to leave my footprints in\n"
	.string "the sand everywhere, but they\l"
	.string "disappear quickly…$"

Route104_Text_29563A: @ 829563A
	.string "Should I…\n"
	.string "Or shouldn’t I?\p"
	.string "Okay, sure, I will battle!$"

Route104_Text_29566F: @ 829566F
	.string "I shouldn’t have battled…$"

Route104_Text_295689: @ 8295689
	.string "If you’re faced with a decision and\n"
	.string "you let someone else choose for you,\l"
	.string "you will regret it, however things\l"
	.string "turn out.$"

Route104_Text_2956FF: @ 82956FF
	.string "You’re strong, but should I register\n"
	.string "you in my POKéNAV?\l"
	.string "Maybe I shouldn’t…\p"
	.string "Okay, sure, I will register you!$"

Route104_Text_29576B: @ 829576B
	.string "You’re strong, but should I register\n"
	.string "you in my POKéNAV?\l"
	.string "Maybe I shouldn’t…\p"
	.string "Okay, sure, I will register you!$"

Route104_Text_2957D7: @ 82957D7
	.string "Come on, battle with me!$"

Route104_Text_2957F0: @ 82957F0
	.string "Ohh…\n"
	.string "I thought I could win…$"

Route104_Text_29580C: @ 829580C
	.string "I made the decision to battle, so\n"
	.string "I can accept this loss with grace.\p"
	.string "I am still upset about losing!$"

Route104_Text_295870: @ 8295870
	.string "Oh, sure, I’ll accept your challenge.\n"
	.string "I have a lot of money.$"

Route104_Text_2958AD: @ 82958AD
	.string "Why couldn’t I win?$"

Route104_Text_2958C1: @ 82958C1
	.string "There are some things money can’t buy.\n"
	.string "That’s POKéMON…$"

Route104_Text_2958F8: @ 82958F8
	.string "Hm?\n"
	.string "Ah, you’ve obtained a POKéNAV.\p"
	.string "I will gladly register you.\n"
	.string "After all, I have plenty of money.$"

Route104_Text_29595A: @ 829595A
	.string "Hm?\n"
	.string "Ah, you’ve obtained a POKéNAV.\p"
	.string "I will gladly register you.\n"
	.string "After all, I have plenty of money.$"

Route104_Text_2959BC: @ 82959BC
	.string "After I lost to you, I learned a bunch\n"
	.string "of things about POKéMON.$"

Route104_Text_2959FC: @ 82959FC
	.string "I lost again?\n"
	.string "Why couldn’t I win?$"

Route104_Text_295A1E: @ 8295A1E
	.string "I’m fabulously wealthy, but I can’t\n"
	.string "seem to win at POKéMON…\p"
	.string "It’s so deep, the world of POKéMON…$"

Route104_Text_295A7E: @ 8295A7E
	.string "We must have been fated to meet.\n"
	.string "May I ask you for a battle?$"

Route104_Text_295ABB: @ 8295ABB
	.string "Oh, my!$"

Route104_Text_295AC3: @ 8295AC3
	.string "“Hello” is the beginning of “good-bye.”\n"
	.string "I hope we meet again.$"

Route104_Text_295B01: @ 8295B01
	.string "Hello, we meet again.\p"
	.string "We seem to be drawn together. Let’s\n"
	.string "register each other in our POKéNAVS.$"

Route104_Text_295B60: @ 8295B60
	.string "We should commemorate how we seem\n"
	.string "to be drawn to each other.\p"
	.string "Let’s register each other in our\n"
	.string "POKéNAVS.$"

Route104_Text_295BC8: @ 8295BC8
	.string "Hello, we meet again.\n"
	.string "May I ask you for a battle?$"

Route104_Text_295BFA: @ 8295BFA
	.string "Oh, my…\n"
	.string "I did the best that I could…$"

Route104_Text_295C1F: @ 8295C1F
	.string "“Hello” is the beginning of “good-bye.”\n"
	.string "I hope we meet again.$"

Route104_Text_295C5D: @ 8295C5D
	.string "I fished up a tough-looking POKéMON!\p"
	.string "It has this magical quality to it!\n"
	.string "It surely looks tough, yes it does!$"

Route104_Text_295CC9: @ 8295CC9
	.string "What the…$"

Route104_Text_295CD3: @ 8295CD3
	.string "Hey, MAGIKARP, you sure don’t live up\n"
	.string "to your name, do you?$"

Route105_Text_295D0F: @ 8295D0F
	.string "There’s supposed to be a mystical\n"
	.string "rock around here.\l"
	.string "Do you know anything about it?$"

Route105_Text_295D62: @ 8295D62
	.string "I was thinking too much about that\n"
	.string "rock, while my POKéMON remained weak…$"

Route105_Text_295DAB: @ 8295DAB
	.string "I can spend hours and hours staring\n"
	.string "at a nice rock without growing bored.$"

Route105_Text_295DF5: @ 8295DF5
	.string "Whew! I was worried that a kid was\n"
	.string "drowning when I saw you.\p"
	.string "You seem to be okay, so what do you\n"
	.string "say to a battle?$"

Route105_Text_295E66: @ 8295E66
	.string "Glub… Glub…$"

Route105_Text_295E72: @ 8295E72
	.string "If you are drowning, the signal is to\n"
	.string "wave one arm toward the beach.$"

Route105_Text_295EB7: @ 8295EB7
	.string "Swimming the deep blue sea…\n"
	.string "It feels the greatest!$"

Route105_Text_295EEA: @ 8295EEA
	.string "I lost…\n"
	.string "Now I’m feeling blue…$"

Route105_Text_295F08: @ 8295F08
	.string "Why is the sea blue?\p"
	.string "I learned about that at the MUSEUM in\n"
	.string "SLATEPORT, but I forgot.$"

Route105_Text_295F5C: @ 8295F5C
	.string "My body feels lighter in the water.\n"
	.string "It’s as if I’ve gotten slimmer!$"

Route105_Text_295FA0: @ 8295FA0
	.string "I’m floating…$"

Route105_Text_295FAE: @ 8295FAE
	.string "Your body weight is reduced to just\n"
	.string "one tenth in the water.\p"
	.string "That would make me…\n"
	.string "Whoops! I’m not telling you my weight!$"

Route105_Text_296025: @ 8296025
	.string "The blue, blue sky…\n"
	.string "The vast sea…\l"
	.string "It’s so peaceful…$"

Route105_Text_296059: @ 8296059
	.string "I lost while I was lounging!$"

Route105_Text_296076: @ 8296076
	.string "I want to be told I’m relaxing to be\n"
	.string "with. Giggle.$"

Route105_Text_2960A9: @ 82960A9
	.string "I’m convinced that the sea keeps\n"
	.string "secrets from us.$"

Route105_Text_2960DB: @ 82960DB
	.string "Yes…\n"
	.string "I am no good at battling…$"

Route105_Text_2960FA: @ 82960FA
	.string "I’m sure there are many secrets to be\n"
	.string "discovered in the world’s seas.\p"
	.string "I mean to find them all!$"

Route105_Text_296159: @ 8296159
	.string "Huh? I’m so weak, but you’re willing\n"
	.string "to register me in your POKéNAV?$"

Route105_Text_29619E: @ 829619E
	.string "I’ve told you that I’m weak…\n"
	.string "Are you sure you want to do this?$"

Route105_Text_2961DD: @ 82961DD
	.string "Yes…\n"
	.string "I didn’t think I could win.$"

Route105_Text_2961FE: @ 82961FE
	.string "I may be weak at battling, but my\n"
	.string "drive to explore can’t be bested.\p"
	.string "I will travel the seas all around\n"
	.string "the world!$"

Route105_Text_29626F: @ 829626F
	.string "I’m exhausted from swimming.\n"
	.string "I’m just not used to it.\p"
	.string "I need a battle for a change of pace!$"

Route105_Text_2962CB: @ 82962CB
	.string "I lost because I battled at sea.$"

Route105_Text_2962EC: @ 82962EC
	.string "Yeah, for me, the sky is a much better\n"
	.string "match than the sea.$"

Route106_Text_296327: @ 8296327
	.string "Which do you prefer, fishing in the\n"
	.string "sea or a stream?$"

Route106_Text_29635C: @ 829635C
	.string "Like in deep-sea fishing, I lost\n"
	.string "spectacularly!$"

Route106_Text_29638C: @ 829638C
	.string "Fishing is the greatest whether it’s\n"
	.string "in the sea or a stream.\l"
	.string "You agree with me, right?$"

Route106_Text_2963E3: @ 82963E3
	.string "Fishing’s great, but so is battling.\n"
	.string "If you don’t mind, can we meet again?$"

Route106_Text_29642E: @ 829642E
	.string "I caught a bunch of POKéMON fishing.\n"
	.string "I’ll show you an impressive battle!$"

Route106_Text_296477: @ 8296477
	.string "I lost again spectacularly!$"

Route106_Text_296493: @ 8296493
	.string "Win or lose, POKéMON are the greatest!\n"
	.string "You agree with me, right?$"

Route106_Text_2964D4: @ 82964D4
	.string "What do people do if they need to go\n"
	.string "to a washroom?\p"
	.string "What if my ROD hooks a big one while\n"
	.string "I’m in the washroom? I just can’t go…$"

Route106_Text_296553: @ 8296553
	.string "I lost because I’m trying to not go\n"
	.string "to the washroom…$"

Route106_Text_296588: @ 8296588
	.string "Oh, no! I’ve got this feeling I’ll hook\n"
	.string "a big one!$"

Route106_Text_2965BB: @ 82965BB
	.string "Hahahah! I’m a lousy runner, but in\n"
	.string "the water you can’t catch me!$"

Route106_Text_2965FD: @ 82965FD
	.string "I give up!$"

Route106_Text_296608: @ 8296608
	.string "I wouldn’t lose in a swim race…$"

Route106_Text_296628: @ 8296628
	.string "The sea is my backyard. I’m not going\n"
	.string "to take it easy because you’re a kid!$"

Route106_Text_296674: @ 8296674
	.string "Did you take it easy on me by any\n"
	.string "chance?$"

Route106_Text_29669E: @ 829669E
	.string "Drifting along with the waves…\n"
	.string "I love it! Why don’t you give it a try?$"

Route107_Text_2966E5: @ 82966E5
	.string "Yawn…\p"
	.string "I must have drifted off to sleep while\n"
	.string "I was drifting in the waves.$"

Route107_Text_29672F: @ 829672F
	.string "Ahaha, I lost…\n"
	.string "I’ll take a snooze, I think…$"

Route107_Text_29675B: @ 829675B
	.string "Floating and being rocked by\n"
	.string "the waves--it’s like sleeping in\l"
	.string "a plush, comfy bed.$"

Route107_Text_2967AD: @ 82967AD
	.string "The sea is like my backyard.\n"
	.string "Let’s battle!$"

Route107_Text_2967D8: @ 82967D8
	.string "I lost on my home field…\n"
	.string "I’m in shock!$"

Route107_Text_2967FF: @ 82967FF
	.string "I swim the seas with a heart full of\n"
	.string "dreams…\p"
	.string "It’s a song!\n"
	.string "Anyways, I’m swimming some more.$"

Route107_Text_29685A: @ 829685A
	.string "You’ve shocked me to the bone!\n"
	.string "Well, so you won’t forget me…$"

Route107_Text_296897: @ 8296897
	.string "Swimming in the big, wide sea,\n"
	.string "my POKéMON has grown stronger!$"

Route107_Text_2968D5: @ 82968D5
	.string "What a shock!\p"
	.string "My POKéMON has gotten stronger, but\n"
	.string "I stayed weak as a TRAINER!$"

Route107_Text_296923: @ 8296923
	.string "What you learn in battle makes you\n"
	.string "a stronger TRAINER.\l"
	.string "The waves taught me that.$"

Route107_Text_296974: @ 8296974
	.string "Do you know a little town called\n"
	.string "DEWFORD?$"

Route107_Text_29699E: @ 829699E
	.string "I hate this!$"

Route107_Text_2969AB: @ 82969AB
	.string "A weird saying is getting really\n"
	.string "trendy at DEWFORD HALL.$"

Route107_Text_2969E4: @ 82969E4
	.string "Did you want to battle me?\n"
	.string "Sure, I’ll go with you!$"

Route107_Text_296A17: @ 8296A17
	.string "I wasn’t good enough for you.$"

Route107_Text_296A35: @ 8296A35
	.string "I think you’re going to keep getting\n"
	.string "better. I’ll go for it, too!$"

Route107_Text_296A77: @ 8296A77
	.string "LISA: We challenge you as a sister\n"
	.string "and brother!$"

Route107_Text_296AA7: @ 8296AA7
	.string "LISA: Awesome.\n"
	.string "You’re in a different class of tough.$"

Route107_Text_296ADC: @ 8296ADC
	.string "LISA: Do you have any friends who\n"
	.string "would go to the beach with you?$"

Route107_Text_296B1E: @ 8296B1E
	.string "LISA: If you want to battle with us,\n"
	.string "bring more POKéMON.$"

Route107_Text_296B57: @ 8296B57
	.string "RAY: We always battle POKéMON,\n"
	.string "me and my sister.\p"
	.string "I always lose, but we can beat you\n"
	.string "2-on-2!$"

Route107_Text_296BB3: @ 8296BB3
	.string "RAY: Wowee, you’re at a higher level\n"
	.string "than us!$"

Route107_Text_296BE1: @ 8296BE1
	.string "RAY: My sister gave me my POKéMON.\n"
	.string "I raised it, and now it’s my important\l"
	.string "partner!$"

Route107_Text_296C34: @ 8296C34
	.string "RAY: If you want to battle us,\n"
	.string "go bring some more POKéMON!$"

Route107_Text_296C6F: @ 8296C6F
	.string "I’m in the middle of a triathlon,\n"
	.string "but I’m nowhere near tired!$"

Route107_Text_296CAD: @ 8296CAD
	.string "That exhausted me…$"

Route107_Text_296CC0: @ 8296CC0
	.string "I still have swimming and running left\n"
	.string "to do after this.\p"
	.string "Am I going to be okay?$"

Route108_Text_296D10: @ 8296D10
	.string "My dream is to swim the world’s seven\n"
	.string "seas!$"

Route108_Text_296D3C: @ 8296D3C
	.string "I won’t be able to swim the seven seas\n"
	.string "like this…$"

Route108_Text_296D6E: @ 8296D6E
	.string "Playing with marine POKéMON is one of\n"
	.string "the pleasures of swimming!$"

Route108_Text_296DAF: @ 8296DAF
	.string "Ahoy, there! Are you going out to\n"
	.string "the ABANDONED SHIP, too?$"

Route108_Text_296DEA: @ 8296DEA
	.string "I’m sinking!\n"
	.string "Glub… Glub…$"

Route108_Text_296E03: @ 8296E03
	.string "Some people even go inside that\n"
	.string "ABANDONED SHIP.$"

Route108_Text_296E33: @ 8296E33
	.string "My liar of a boyfriend told me that\n"
	.string "I look great in a bikini…$"

Route108_Text_296E71: @ 8296E71
	.string "Oh, boo!$"

Route108_Text_296E7A: @ 8296E7A
	.string "Even if it’s a lie, I love being told\n"
	.string "I look great…\l"
	.string "We girls are so complex…$"

Route108_Text_296EC7: @ 8296EC7
	.string "I love the sea!\n"
	.string "I forget all my worries when I swim!$"

Route108_Text_296EFC: @ 8296EFC
	.string "When I lose a battle, I get all\n"
	.string "stressed out!$"

Route108_Text_296F2A: @ 8296F2A
	.string "Work off your stress by swimming!\n"
	.string "It’s so healthy!$"

Route108_Text_296F5D: @ 8296F5D
	.string "I love WATER-type POKéMON.\n"
	.string "I love other POKéMON, too!$"

Route108_Text_296F93: @ 8296F93
	.string "Waaah! I lost!\n"
	.string "Waaah! Waaah!$"

Route108_Text_296FB0: @ 8296FB0
	.string "Shouting is good for me!\n"
	.string "It uplifts me!$"

Route108_Text_296FD8: @ 8296FD8
	.string "I love tough TRAINERS, too!\n"
	.string "Register me in your POKéNAV!$"

Route108_Text_297011: @ 8297011
	.string "Win or lose, I love battling at sea!$"

Route108_Text_297036: @ 8297036
	.string "Waaah! I lost again!\n"
	.string "Waaah! Waaah!$"

Route108_Text_297059: @ 8297059
	.string "If you’re faced with a challenge,\n"
	.string "try shouting at the sea!$"

Route108_Text_297094: @ 8297094
	.string "I take huge pride in my POKéMON.\n"
	.string "We’ll show you one speedy battle!$"

Route108_Text_2970D7: @ 82970D7
	.string "That wasn’t cute at all.$"

Route108_Text_2970F0: @ 82970F0
	.string "Since I’m at sea like this, I wouldn’t\n"
	.string "mind putting on a pink, frilly swimsuit…$"

Route109_Text_297140: @ 8297140
	.string "Hiyah! Look at my chiseled abs!\n"
	.string "This is what you call “cut”!$"

Route109_Text_29717D: @ 829717D
	.string "Aiyah!\n"
	.string "Flubbed out!$"

Route109_Text_297191: @ 8297191
	.string "Hiyah!\p"
	.string "My sculpted abs have nothing to do\n"
	.string "with POKéMON battles!$"

Route109_Text_2971D1: @ 82971D1
	.string "Are you properly protected against\n"
	.string "the sun?$"

Route109_Text_2971FD: @ 82971FD
	.string "Ouch, ouch, ouch!$"

Route109_Text_29720F: @ 829720F
	.string "Cheeks are the most prone to burning!$"

Route109_Text_297235: @ 8297235
	.string "I’ve laid anchor in ports around\n"
	.string "the world, but SLATEPORT’s the best.$"

Route109_Text_29727B: @ 829727B
	.string "You’re the best!$"

Route109_Text_29728C: @ 829728C
	.string "In the best port was the best\n"
	.string "TRAINER…$"

Route109_Text_2972B3: @ 82972B3
	.string "Urrrrppp…\n"
	.string "Battle? With me?$"

Route109_Text_2972CE: @ 82972CE
	.string "Urp… Ooooooohhhhhh…\n"
	.string "Urrrrpppp…$"

Route109_Text_2972ED: @ 82972ED
	.string "I’m usually stronger than this!\n"
	.string "I’m just seasick as a dog!\p"
	.string "I’m a SAILOR, but…$"

Route109_Text_29733B: @ 829733B
	.string "I’m thirsty… I could go for a SODA POP\n"
	.string "at the SEASHORE HOUSE…$"

Route109_Text_297379: @ 8297379
	.string "Groan…$"

Route109_Text_297380: @ 8297380
	.string "I’m getting famished… My inner tube\n"
	.string "looks like a giant doughnut…$"

Route109_Text_2973C1: @ 82973C1
	.string "Will you have another match with me\n"
	.string "when I’m not all thirsty?$"

Route109_Text_2973FF: @ 82973FF
	.string "I’m hungry, but I’ve got enough pep in\n"
	.string "me for a battle!$"

Route109_Text_297437: @ 8297437
	.string "I lost…\n"
	.string "It’s because I’m hungry…$"

Route109_Text_297458: @ 8297458
	.string "When you eat on a beach, everything\n"
	.string "seems to taste a little better.$"

Route109_Text_29749C: @ 829749C
	.string "Doesn’t a beach umbrella look like\n"
	.string "a giant flower?$"

Route109_Text_2974CF: @ 82974CF
	.string "Mommy!$"

Route109_Text_2974D6: @ 82974D6
	.string "If you look at the beach from the sky,\n"
	.string "it looks like a big flower garden!$"

Route109_Text_297520: @ 8297520
	.string "Me?\n"
	.string "I’m here every day!$"

Route109_Text_297538: @ 8297538
	.string "I’m not losing to you again!\n"
	.string "That’s why I have my inner tube!$"

Route109_Text_297576: @ 8297576
	.string "Mommy!$"

Route109_Text_29757D: @ 829757D
	.string "If I have an inner tube, me and my\n"
	.string "POKéMON’s cuteness goes way up!$"

Route109_Text_2975C0: @ 82975C0
	.string "I can’t swim without my inner tube,\n"
	.string "but I won’t lose at POKéMON!$"

Route109_Text_297601: @ 8297601
	.string "Did I lose because I have an inner\n"
	.string "tube?$"

Route109_Text_29762A: @ 829762A
	.string "My inner tube is a fashion item.\n"
	.string "I can’t be seen without it.$"

Route109_Text_297667: @ 8297667
	.string "Hi, big TRAINER.\n"
	.string "Will you battle with me?$"

Route109_Text_297691: @ 8297691
	.string "Oh, you’re strong.$"

Route109_Text_2976A4: @ 82976A4
	.string "How did you get to be so strong?$"

Route109_Text_2976C5: @ 82976C5
	.string "Wahahah! This dude’s going to catch\n"
	.string "himself a big one!$"

Route109_Text_2976FC: @ 82976FC
	.string "This dude just lost one…$"

Route109_Text_297715: @ 8297715
	.string "This dude thinks you’re a big one.\n"
	.string "No, you’re a big-one-to-be!$"

Route109_Text_297754: @ 8297754
	.string "PAUL: Well, this is a mood-breaker.\p"
	.string "I wish you wouldn’t disturb our\n"
	.string "precious time together.$"

Route109_Text_2977B0: @ 82977B0
	.string "PAUL: Well, I give up.$"

Route109_Text_2977C7: @ 82977C7
	.string "PAUL: Well, don’t tell anyone that\n"
	.string "we’re here.\l"
	.string "This is just our private world of two!$"

Route109_Text_29781D: @ 829781D
	.string "PAUL: We’re totally, deeply in love.\n"
	.string "That’s why we make our POKéMON battle\l"
	.string "together.$"

Route109_Text_297872: @ 8297872
	.string "MEL: We’re, like, totally in love.\n"
	.string "Our romance is heating up all of HOENN!$"

Route109_Text_2978BD: @ 82978BD
	.string "MEL: We lost, and it’s my fault!\n"
	.string "PAUL will hate me!$"

Route109_Text_2978F1: @ 82978F1
	.string "MEL: Um, PAUL, are you angry with me?\n"
	.string "Please don’t be angry.$"

Route109_Text_29792E: @ 829792E
	.string "MEL: We’re, like, deeply and truly in love.\n"
	.string "That’s why we make our POKéMON\l"
	.string "battle together.$"

Route109_Text_29798A: @ 829798A
	.string "Tadaah! See?\n"
	.string "My inner tube’s round!$"

Route109_Text_2979AE: @ 82979AE
	.string "Oh, oh!\n"
	.string "Too bad!$"

Route109_Text_2979BF: @ 82979BF
	.string "After I showed you my round inner\n"
	.string "tube, too…$"

Route109_Text_2979EC: @ 82979EC
	.string "I can’t swim, so I’m pretending\n"
	.string "to swim.$"

Route109_Text_297A15: @ 8297A15
	.string "I thought so!\n"
	.string "I didn’t think we could win.$"

Route109_Text_297A40: @ 8297A40
	.string "When I learn how to swim, I think\n"
	.string "my POKéMON will become tougher.$"

Route109_Text_297A82: @ 8297A82
	.string "For a guy as macho as me, this kind\n"
	.string "of POKéMON is the perfect match!$"

Route109_Text_297AC7: @ 8297AC7
	.string "I’m cool even in defeat, hey?$"

Route109_Text_297AE5: @ 8297AE5
	.string "For a guy as macho as me, a port\n"
	.string "is the perfect setting!\p"
	.string "I guess I’ll head for SLATEPORT.$"

Route110_Text_297B3F: @ 8297B3F
	.string "Whoa! Watch it!\n"
	.string "I guess you’re not used to BIKE racing.$"

Route110_Text_297B77: @ 8297B77
	.string "Whoa!\n"
	.string "My brakes failed!$"

Route110_Text_297B8F: @ 8297B8F
	.string "Flat tires and brake problems can\n"
	.string "cause serious injury!\l"
	.string "Inspect your BIKE for problems!$"

Route110_Text_297BE7: @ 8297BE7
	.string "Yo, you!\n"
	.string "Can you keep up with my speed?$"

Route110_Text_297C0F: @ 8297C0F
	.string "Crash and burn!$"

Route110_Text_297C1F: @ 8297C1F
	.string "Speed alone won’t let me win at POKéMON.\n"
	.string "I need to reconsider this…$"

Route110_Text_297C63: @ 8297C63
	.string "Don’t panic if your BIKE’s going fast!$"

Route110_Text_297C8A: @ 8297C8A
	.string "I shouldn’t panic during POKéMON\n"
	.string "battles…$"

Route110_Text_297CB4: @ 8297CB4
	.string "There’s no need to panic or stress.\n"
	.string "Take it easy. There’s plenty of time.$"

Route110_Text_297CFE: @ 8297CFE
	.string "I’ll keep chugging on without stressing.\n"
	.string "Give me a shout if you’re up to it.$"

Route110_Text_297D4B: @ 8297D4B
	.string "Aren’t you going a little too fast?\n"
	.string "Take it easy and let’s battle.$"

Route110_Text_297D8E: @ 8297D8E
	.string "I didn’t panic, but I still lost…$"

Route110_Text_297DB0: @ 8297DB0
	.string "There’s no need to panic or stress.\n"
	.string "Take it easy. There’s plenty of time.$"

Route110_Text_297DFA: @ 8297DFA
	.string "The triathlon is hard in the extreme.\p"
	.string "You have to complete the three events\n"
	.string "of swimming, cycling, and running.$"

Route110_Text_297E69: @ 8297E69
	.string "POKéMON battles are hard, too!$"

Route110_Text_297E88: @ 8297E88
	.string "I’m exhausted, so I need a break.\n"
	.string "It’s important to get proper rest.$"

Route110_Text_297ECD: @ 8297ECD
	.string "You know, I like you!\n"
	.string "Let’s have a rematch on CYCLING ROAD.$"

Route110_Text_297F09: @ 8297F09
	.string "Isn’t it neat to hold a battle while\n"
	.string "cycling?$"

Route110_Text_297F37: @ 8297F37
	.string "Wow…\n"
	.string "How could you be so strong?$"

Route110_Text_297F58: @ 8297F58
	.string "Were you going after a record?\p"
	.string "I’m sorry if I held you up!$"

Route110_Text_297F93: @ 8297F93
	.string "I’ve been riding without stopping.\n"
	.string "My thighs are like rocks!$"

Route110_Text_297FD0: @ 8297FD0
	.string "I’m worried about muscle cramps…$"

Route110_Text_297FF1: @ 8297FF1
	.string "Oh, you have some GYM BADGES?\n"
	.string "No wonder you’re so strong!$"

Route110_Text_29802B: @ 829802B
	.string "I have foreseen your intentions!\n"
	.string "I cannot possibly lose!$"

Route110_Text_298064: @ 8298064
	.string "I failed to prophesize my own demise!$"

Route110_Text_29808A: @ 829808A
	.string "I see your future…\p"
	.string "Hmm…\n"
	.string "I see a shining light…$"

Route110_Text_2980B9: @ 82980B9
	.string "Ahahahaha!\n"
	.string "I’ll dazzle you with my wonders!$"

Route110_Text_2980E5: @ 82980E5
	.string "I wondrously lost!$"

Route110_Text_2980F8: @ 82980F8
	.string "You managed to win only because it was\n"
	.string "a wonder! Yes, a wonder!\l"
	.string "Don’t think you can win all the time!$"

Route110_Text_29815E: @ 829815E
	.string "Could I see your POKéMON?\n"
	.string "Just one look, please?$"

Route110_Text_29818F: @ 829818F
	.string "I wanted to complete\n"
	.string "my collection…$"

Route110_Text_2981B3: @ 82981B3
	.string "When I see a POKéMON that I don’t know,\n"
	.string "my passion as a collector is ignited!$"

Route110_Text_298201: @ 8298201
	.string "I like collecting MATCH CALL\n"
	.string "registrations, too…$"

Route110_Text_298232: @ 8298232
	.string "Hi, have you caught any new POKéMON?\p"
	.string "Could I see your POKéMON?\n"
	.string "Just one look, please?$"

Route110_Text_298288: @ 8298288
	.string "Your POKéMON…\n"
	.string "I envy you.$"

Route110_Text_2982A2: @ 82982A2
	.string "Oh, I long to make all rare POKéMON\n"
	.string "mine!$"

Route110_Text_2982CC: @ 82982CC
	.string "Hey!\n"
	.string "Don’t sneak up behind me like that!$"

Route110_Text_2982F5: @ 82982F5
	.string "I lost!\n"
	.string "Drat!$"

Route110_Text_298303: @ 8298303
	.string "Fishing is all about concentration.\n"
	.string "You have to focus on the floater.$"

Route110_Text_298349: @ 8298349
	.string "Ahahaha! I would go anywhere to show\n"
	.string "off my delightful POKéMON.$"

Route110_Text_298389: @ 8298389
	.string "Oh, dear, this won’t do.$"

Route110_Text_2983A2: @ 82983A2
	.string "Rather than battling, perhaps I should\n"
	.string "show off my POKéMON at the FAN CLUB.$"

Route110_Text_2983EE: @ 82983EE
	.string "That wasn’t close to what I could\n"
	.string "do to show off my POKéMON.\p"
	.string "I’ll have you as my captive audience\n"
	.string "as often as possible!$"

Route110_Text_298466: @ 8298466
	.string "Ahahahaha! I would be happy to show\n"
	.string "off my POKéMON as often as you like!$"

Route110_Text_2984AF: @ 82984AF
	.string "Oh, dear, this won’t do.$"

Route110_Text_2984C8: @ 82984C8
	.string "I don’t think that I could ever stop\n"
	.string "from showing off my POKéMON.\p"
	.string "But I like to battle, too!$"

Route110_Text_298525: @ 8298525
	.string "I found some cool POKéMON in the grass\n"
	.string "around here!$"

Route110_Text_298559: @ 8298559
	.string "Being cool isn’t enough to win…$"

Route110_Text_298579: @ 8298579
	.string "It’s hard to battle with POKéMON you\n"
	.string "just caught.$"

Route110_Text_2985AB: @ 82985AB
	.string "I fell off CYCLING ROAD…\p"
	.string "I’ll get over my embarrassment by\n"
	.string "battling with you!$"

Route110_Text_2985F9: @ 82985F9
	.string "Oops!\n"
	.string "I ended up losing!$"

Route110_Text_298612: @ 8298612
	.string "Falling… Losing…\n"
	.string "This is so humiliating for me!$"

Route110_Text_298642: @ 8298642
	.string "Okay! Full-throttle time! If you can’t\n"
	.string "groove, you get left behind!$"

Route110_Text_298686: @ 8298686
	.string "You got into the groove all right…$"

Route110_Text_2986A9: @ 82986A9
	.string "This isn’t going to bring me down!\n"
	.string "Losing has made me a better man!$"

Route110_Text_2986ED: @ 82986ED
	.string "When cute POKéMON help each other…\n"
	.string "You won’t see a more adorable sight!$"

Route110_Text_298735: @ 8298735
	.string "Have you no compassion or pity?$"

Route110_Text_298755: @ 8298755
	.string "Okay, okay, you’ve done the best you\n"
	.string "could, my pretties.$"

Route111_Text_29878E: @ 829878E
	.string "Oh, hey! Those GO-GOGGLES suit you.\n"
	.string "But I think they look better on me.\p"
	.string "Let’s decide who they look better on\n"
	.string "with a battle!$"

Route111_Text_29880A: @ 829880A
	.string "I couldn’t see what was happening at\n"
	.string "my sides because of the GO-GOGGLES.$"

Route111_Text_298853: @ 8298853
	.string "The GO-GOGGLES make it possible to\n"
	.string "get through sandstorms.\l"
	.string "That makes me happy!$"

Route111_Text_2988A3: @ 82988A3
	.string "I’m having a picnic in the desert.\p"
	.string "You can always find a TRAINER,\n"
	.string "so I can enjoy a battle here, too!$"

Route111_Text_298908: @ 8298908
	.string "Ohhh! You’re mean!$"

Route111_Text_29891B: @ 829891B
	.string "When you’re battling in a sandstorm,\n"
	.string "watch out for your POKéMON’s HP.\p"
	.string "It can faint if you don’t keep\n"
	.string "an eye on it!$"

Route111_Text_29898E: @ 829898E
	.string "Wearing these GO-GOGGLES makes me\n"
	.string "feel like a superhero.\l"
	.string "Right now, nobody can beat me!$"

Route111_Text_2989E6: @ 82989E6
	.string "I can’t win on spirit alone…$"

Route111_Text_298A03: @ 8298A03
	.string "I’m going to be a real hero one day.\n"
	.string "I’m going to work harder to make me\l"
	.string "and my POKéMON stronger.$"

Route111_Text_298A65: @ 8298A65
	.string "I heard there are fossils to be found\n"
	.string "in the desert. Where could they be?$"

Route111_Text_298AAF: @ 8298AAF
	.string "I came up short…$"

Route111_Text_298AC0: @ 8298AC0
	.string "If they can find fossils in the desert,\n"
	.string "it must have been a sea before.$"

Route111_Text_298B08: @ 8298B08
	.string "For thirty years I have searched for\n"
	.string "ancient ruins!\l"
	.string "I am to be challenged?$"

Route111_Text_298B53: @ 8298B53
	.string "While I have searched for ruins,\n"
	.string "I’ve not searched for strong POKéMON.$"

Route111_Text_298B9A: @ 8298B9A
	.string "For thirty years I have searched for\n"
	.string "ancient ruins!\p"
	.string "No, wait, was that forty years?\n"
	.string "Which was it now?$"

Route111_Text_298C00: @ 8298C00
	.string "I haven’t been searching for any\n"
	.string "tough POKéMON.\p"
	.string "But, for some reason, I sure do like\n"
	.string "POKéNAVS.$"

Route111_Text_298C5F: @ 8298C5F
	.string "For thirty years I have searched for\n"
	.string "ancient ruins!\p"
	.string "No, wait, was that forty years?\n"
	.string "Anyway, am I to be challenged?$"

Route111_Text_298CD2: @ 8298CD2
	.string "I’ve found no ruins, nor have I found\n"
	.string "any strong POKéMON…$"

Route111_Text_298D0C: @ 8298D0C
	.string "For thirty years I have searched for\n"
	.string "ancient ruins!\p"
	.string "No, wait, was that forty years\n"
	.string "I’ve searched?\p"
	.string "Hmm… It could even be fifty…\n"
	.string "How long have I been at this?$"

Route111_Text_298DA9: @ 8298DA9
	.string "I’m full of pep!\n"
	.string "And my POKéMON is peppy, too!$"

Route111_Text_298DD8: @ 8298DD8
	.string "My POKéMON lost its pep…$"

Route111_Text_298DF1: @ 8298DF1
	.string "When I see a TRAINER with a lot of pep,\n"
	.string "I can’t help looking.$"

Route111_Text_298E2F: @ 8298E2F
	.string "I don’t know where you’re going,\n"
	.string "but would you like to battle?$"

Route111_Text_298E6E: @ 8298E6E
	.string "Oh, you’re disgustingly good!$"

Route111_Text_298E8C: @ 8298E8C
	.string "I’m thinking that I should go to\n"
	.string "MT. CHIMNEY, but the view around\l"
	.string "here is very nice, too.$"

Route111_Text_298EE6: @ 8298EE6
	.string "To train myself, I challenge all\n"
	.string "whom I meet!$"

Route111_Text_298F14: @ 8298F14
	.string "Uncle! I give up!$"

Route111_Text_298F26: @ 8298F26
	.string "All I can do is keep training until\n"
	.string "I can defeat strong TRAINERS such\l"
	.string "as yourself.$"

Route111_Text_298F79: @ 8298F79
	.string "Show me how much you’ve toughened\n"
	.string "your POKéMON.$"

Route111_Text_298FA9: @ 8298FA9
	.string "I see, you’ve toughened them\n"
	.string "considerably.$"

Route111_Text_298FD4: @ 8298FD4
	.string "POKéMON and TRAINERS learn much\n"
	.string "through battling.\p"
	.string "What’s important is to never give up\n"
	.string "even if you lose.$"

Route111_Text_29903D: @ 829903D
	.string "There is much to be learned from\n"
	.string "your training style.\p"
	.string "I request a rematch if it\n"
	.string "behooves you.$"

Route111_Text_29909B: @ 829909B
	.string "We’re training here to elevate our\n"
	.string "game to the next level.\l"
	.string "Stay and train with us!$"

Route111_Text_2990EE: @ 82990EE
	.string "Ooh, you’re decent!$"

Route111_Text_299102: @ 8299102
	.string "Since you’re that strong, you should\n"
	.string "aim for the POKéMON LEAGUE.$"

Route111_Text_299143: @ 8299143
	.string "Oh, your POKéMON look like serious\n"
	.string "actors.\l"
	.string "I have to ask you for an engagement.$"

Route111_Text_299193: @ 8299193
	.string "They didn’t just look strong,\n"
	.string "they are strong!$"

Route111_Text_2991C2: @ 82991C2
	.string "I thought I was raising my POKéMON\n"
	.string "diligently, but, oh no, there is still\l"
	.string "much to be done.$"

Route111_Text_29921D: @ 829921D
	.string "I wish I could become friends with\n"
	.string "more strong people like you!$"

Route111_Text_29925D: @ 829925D
	.string "You can make POKéMON stronger or\n"
	.string "weaker depending on the moves you\l"
	.string "teach them.\p"
	.string "What kinds of moves do your POKéMON\n"
	.string "know?$"

Route111_Text_2992D6: @ 82992D6
	.string "You’ve taught them good moves!$"

Route111_Text_2992F5: @ 82992F5
	.string "Maybe I should have stopped my\n"
	.string "POKéMON from evolving until they\l"
	.string "learned better moves…$"

Route111_Text_29934B: @ 829934B
	.string "I shouldn’t have come to a place like\n"
	.string "this for a picnic!$"

Route111_Text_299384: @ 8299384
	.string "Aww!\n"
	.string "I really shouldn’t have come!$"

Route111_Text_2993A7: @ 82993A7
	.string "In a sandstorm like this, I can’t set\n"
	.string "the places for a picnic even with my\l"
	.string "GO-GOGGLES on…$"

Route111_Text_299401: @ 8299401
	.string "How tough are you?\n"
	.string "We shall expose that secret!$"

Route111_Text_299431: @ 8299431
	.string "Oh! Your strength!\n"
	.string "It is shrouded in mystery!$"

Route111_Text_29945F: @ 829945F
	.string "This desert hoards mysteries in\n"
	.string "its shifting sands!$"

Route111_Text_299493: @ 8299493
	.string "I’ll give you some of my sandwich\n"
	.string "if you’ll lose.$"

Route111_Text_2994C5: @ 82994C5
	.string "Tch! I thought a sandwich would be\n"
	.string "enough of a bribe…$"

Route111_Text_2994FB: @ 82994FB
	.string "My SANDSHREW loves eating\n"
	.string "my sandwiches.$"

Route111_Text_299524: @ 8299524
	.string "This is my favorite kind of POKéMON!$"

Route111_Text_299549: @ 8299549
	.string "Wait!\n"
	.string "Did you get a good look at my POKéMON?$"

Route111_Text_299576: @ 8299576
	.string "When having a battle, I get a kick out\n"
	.string "of showing off my POKéMON.\p"
	.string "I bet everyone feels that way when\n"
	.string "they enter a battle!$"

Route111_Text_2995F0: @ 82995F0
	.string "Show me how to put a little excitement\n"
	.string "into my life.$"

Route111_Text_299625: @ 8299625
	.string "Oh… My…\n"
	.string "That was too much excitement.$"

Route111_Text_29964B: @ 829964B
	.string "My pulse is still racing.\n"
	.string "You’re one fabulous TRAINER.$"

Route111_Text_299682: @ 8299682
	.string "When you’re as famished as I am,\n"
	.string "there is no room for pity!$"

Route111_Text_2996BE: @ 82996BE
	.string "Groan…$"

Route111_Text_2996C5: @ 82996C5
	.string "My stomach is grumbling!\n"
	.string "Maybe I can grill some BERRIES…$"

Route111_Text_2996FE: @ 82996FE
	.string "Did you come from MAUVILLE?\n"
	.string "Then you should be full of energy!$"

Route111_Text_29973D: @ 829973D
	.string "Ooh lala!\n"
	.string "That’s a lot to take!$"

Route111_Text_29975D: @ 829975D
	.string "This road here…\n"
	.string "You have quite a ways to travel.$"

Route112_Text_29978E: @ 829978E
	.string "Hahahaha!\n"
	.string "How about we have a battle?\l"
	.string "You and me!\l"
	.string "Hahahaha!$"

Route112_Text_2997CA: @ 82997CA
	.string "I lost!\n"
	.string "Hahahaha!$"

Route112_Text_2997DC: @ 82997DC
	.string "Hahahahaha! Something flew up my nose!\n"
	.string "Hahahaha-hatchoo!$"

Route112_Text_299815: @ 8299815
	.string "My legs are solid from pounding up\n"
	.string "and down the mountains.\p"
	.string "They’re not going to buckle easily,\n"
	.string "friend!$"

Route112_Text_29987C: @ 829987C
	.string "Ouch! My legs cramped up!$"

Route112_Text_299896: @ 8299896
	.string "Try hiking, and I mean really\n"
	.string "pounding, on these mountain trails\l"
	.string "with a heavy pack weighing dozens of\l"
	.string "pounds.\p"
	.string "That, my friend, will get your body\n"
	.string "into serious shape.$"

Route112_Text_29993C: @ 829993C
	.string "Ow, my legs have cramped up.\n"
	.string "Can you grab me some bandages from\l"
	.string "my backpack?\p"
	.string "No, that’s my POKéNAV!\n"
	.string "Oh, fine, I’ll register you.$"

Route112_Text_2999BD: @ 82999BD
	.string "I’ve been keeping fit by hiking.\n"
	.string "Power, I have in spades!$"

Route112_Text_2999F7: @ 82999F7
	.string "I got trumped in power?$"

Route112_Text_299A0F: @ 8299A0F
	.string "I hear there are some seriously tough\n"
	.string "TRAINERS on top of MT. CHIMNEY.\p"
	.string "I intend to get up there and give them\n"
	.string "a challenge!$"

Route112_Text_299A89: @ 8299A89
	.string "I’m strong.\n"
	.string "I won’t cry if I lose.$"

Route112_Text_299AAC: @ 8299AAC
	.string "Waaaah!$"

Route112_Text_299AB4: @ 8299AB4
	.string "I’m not crying because I miss my mommy!\n"
	.string "Snivel…$"

Route112_Text_299AE4: @ 8299AE4
	.string "When you’re out on a picnic, why,\n"
	.string "you simply have to sing!\l"
	.string "Come on, sing with me!$"

Route112_Text_299B36: @ 8299B36
	.string "Oh, you’re so strong!$"

Route112_Text_299B4C: @ 8299B4C
	.string "It doesn’t matter if you’re good or bad\n"
	.string "at singing or POKéMON.\p"
	.string "If you have the most fun, you win!$"

Route112_Text_299BAE: @ 8299BAE
	.string "I caught hot POKéMON in FIERY PATH!\n"
	.string "Take a look!$"

Route112_Text_299BDF: @ 8299BDF
	.string "What a bumpy ride that was!$"

Route112_Text_299BFB: @ 8299BFB
	.string "I like the way you battle.\n"
	.string "It has a certain flair to it.$"

Route112_Text_299C34: @ 8299C34
	.string "Oh, aren’t you an adorable TRAINER!\n"
	.string "Please, I need a romantic battle!\l"
	.string "I’m somewhat decent!$"

Route112_Text_299C8F: @ 8299C8F
	.string "Oh, how strong you are!\n"
	.string "You’ve given me quite a shock!$"

Route112_Text_299CC6: @ 8299CC6
	.string "Are you busy right now?\n"
	.string "I was thinking that maybe we can have\l"
	.string "a rematch right now…\l"
	.string "But it’s all right if you’re busy.$"

Route113_Text_299D3C: @ 8299D3C
	.string "Can you guess why it’s so cool\n"
	.string "around here?$"

Route113_Text_299D68: @ 8299D68
	.string "Peeuuw!\n"
	.string "That stinks!$"

Route113_Text_299D7D: @ 8299D7D
	.string "The volcanic ash blocks the sun,\n"
	.string "so it doesn’t get very warm.\p"
	.string "That’s good for me--I can’t stand heat!$"

Route113_Text_299DE3: @ 8299DE3
	.string "The volcano’s eruption is proof that\n"
	.string "the earth is alive.$"

Route113_Text_299E1C: @ 8299E1C
	.string "You’re some kind of strong!$"

Route113_Text_299E38: @ 8299E38
	.string "Ouch! Owww! I can’t see!\n"
	.string "I got ashes in my eyelashes!\p"
	.string "Get it? Ashes and eyelashes?\p"
	.string "Okay, that was bad, sorry…$"

Route113_Text_299EA6: @ 8299EA6
	.string "I use this parasol to ward off this\n"
	.string "filthy, yucky volcanic ash from\l"
	.string "my dear NUMEL.$"

Route113_Text_299EF9: @ 8299EF9
	.string "Huff, huff…\n"
	.string "I am exhausted…$"

Route113_Text_299F15: @ 8299F15
	.string "You’re very good at this.\n"
	.string "I must say I’m impressed!$"

Route113_Text_299F49: @ 8299F49
	.string "Here, slide under my parasol.\n"
	.string "Let me register you in my POKéNAV.$"

Route113_Text_299F8A: @ 8299F8A
	.string "Oh, hello, hasn’t it been a while?\n"
	.string "May I invite you to battle?$"

Route113_Text_299FC9: @ 8299FC9
	.string "Oh, how super!$"

Route113_Text_299FD8: @ 8299FD8
	.string "You’ve remained very good at this.\n"
	.string "I must say I’m impressed!$"

Route113_Text_29A015: @ 829A015
	.string "From out of the ashes I leap! Hiyah!\n"
	.string "I challenge thee!$"

Route113_Text_29A04C: @ 829A04C
	.string "With honor I admit defeat!$"

Route113_Text_29A067: @ 829A067
	.string "I must refine the art of concealment.\n"
	.string "I bid thee farewell.$"

Route113_Text_29A0A2: @ 829A0A2
	.string "Yiiyaah! Witness the ancient ninja\n"
	.string "technique of POKéNAV registration!$"

Route113_Text_29A0E8: @ 829A0E8
	.string "From out of the ashes I leap! Hiyah!\n"
	.string "I challenge thee!$"

Route113_Text_29A11F: @ 829A11F
	.string "With honor I admit defeat!$"

Route113_Text_29A13A: @ 829A13A
	.string "My flawless concealment was let down\n"
	.string "by my immature battle skills…\p"
	.string "I bid thee farewell.$"

Route113_Text_29A192: @ 829A192
	.string "Thanks for finding me!\n"
	.string "But we still have to battle!$"

Route113_Text_29A1C6: @ 829A1C6
	.string "I’ll use my ninjutsu on you…\n"
	.string "“VOLCANIC ASH SWIRL CLOAK”!\p"
	.string "…What?\n"
	.string "It’s already over?$"

Route113_Text_29A219: @ 829A219
	.string "You know what’s crummy about hiding?\n"
	.string "It’s lonely if no one comes along.$"

Route113_Text_29A261: @ 829A261
	.string "TORI: Both of us, we collect ashes.\n"
	.string "We battle POKéMON, too.$"

Route113_Text_29A29D: @ 829A29D
	.string "TORI: We lost… It’s boring, so I’m going\n"
	.string "to get some more ashes.$"

Route113_Text_29A2DE: @ 829A2DE
	.string "TORI: How much ash do we have?\n"
	.string "Enough for a WHITE FLUTE, I hope.$"

Route113_Text_29A31F: @ 829A31F
	.string "TORI: We want to battle 2-on-2.\n"
	.string "If we didn’t, we would lose!$"

Route113_Text_29A35C: @ 829A35C
	.string "TIA: Both of us, we collect ashes.\n"
	.string "We battle POKéMON, too.$"

Route113_Text_29A397: @ 829A397
	.string "TIA: We couldn’t win… It’s boring,\n"
	.string "so I’m getting some more ashes.$"

Route113_Text_29A3DA: @ 829A3DA
	.string "TIA: We have a lot of ashes!\n"
	.string "I think enough for a WHITE FLUTE!$"

Route113_Text_29A419: @ 829A419
	.string "TIA: We want to battle 2-on-2.\n"
	.string "If we don’t, we won’t win!$"

Route113_Text_29A453: @ 829A453
	.string "Pfft, with these wings I can\n"
	.string "flick you away!$"

Route113_Text_29A480: @ 829A480
	.string "A… What?$"

Route113_Text_29A489: @ 829A489
	.string "I don’t know what to say when I get\n"
	.string "beaten so easily…$"

Route113_Text_29A4BF: @ 829A4BF
	.string "The warmth here is making me drowsy.\n"
	.string "Battle with me so I can stay awake.$"

Route113_Text_29A508: @ 829A508
	.string "This is a dream.\n"
	.string "I’m sure of it…$"

Route113_Text_29A529: @ 829A529
	.string "Losing burns me up…\n"
	.string "I’m just going to sleep right here!\l"
	.string "Zzz!$"

Route113_Text_29A566: @ 829A566
	.string "Were you maybe in the middle\n"
	.string "of gathering volcanic ashes?$"

Route113_Text_29A5A0: @ 829A5A0
	.string "Ehehe.\n"
	.string "We got beaten cleanly.$"

Route113_Text_29A5BE: @ 829A5BE
	.string "I ought to hide under the ashes, too.$"

Route113_Text_29A5E4: @ 829A5E4
	.string "Y-you want to battle with me?\n"
	.string "Even though I just caught my POKéMON?$"

Route113_Text_29A628: @ 829A628
	.string "Y-you’re all happy to win?\n"
	.string "Even though it’s only me?$"

Route113_Text_29A65D: @ 829A65D
	.string "Oh, so now you want to say a word to\n"
	.string "the loser?\p"
	.string "Aren’t you just the coolest?\n"
	.string "Humph!$"

Route114_Text_29A6B1: @ 829A6B1
	.string "Yodelayhihoo!\p"
	.string "… …\p"
	.string "You’re supposed to shout\n"
	.string "“yodelayhihoo” since it doesn’t\l"
	.string "echo here!$"

Route114_Text_29A707: @ 829A707
	.string "Yodelayhihoo!$"

Route114_Text_29A715: @ 829A715
	.string "When I was a wee tyke, I believed there\n"
	.string "was someone copying me and shouting\l"
	.string "back, “Yodelayhihoo.”$"

Route114_Text_29A777: @ 829A777
	.string "If you’re not prepared, you shouldn’t\n"
	.string "be up in the mountains!$"

Route114_Text_29A7B5: @ 829A7B5
	.string "The mountains are unforgiving…$"

Route114_Text_29A7D4: @ 829A7D4
	.string "In the winter, mountains turn deadly\n"
	.string "with blizzards and avalanches.$"

Route114_Text_29A818: @ 829A818
	.string "Camping’s fun! You can fish, roast\n"
	.string "marshmallows, and tell spooky stories!\p"
	.string "But the best of all are the POKéMON\n"
	.string "battles!$"

Route114_Text_29A88F: @ 829A88F
	.string "Way too strong!$"

Route114_Text_29A89F: @ 829A89F
	.string "I think it’s great that I can go\n"
	.string "camping with my POKéMON.$"

Route114_Text_29A8D9: @ 829A8D9
	.string "I need to exercise after a meal.\n"
	.string "Let’s have a match!$"

Route114_Text_29A90E: @ 829A90E
	.string "Oh, no!$"

Route114_Text_29A916: @ 829A916
	.string "I just had a tasty meal.\n"
	.string "I’m getting drowsy…$"

Route114_Text_29A943: @ 829A943
	.string "Ufufufufufu…\n"
	.string "Want to battle against my POKéMON?$"

Route114_Text_29A973: @ 829A973
	.string "M-My POKéMON…$"

Route114_Text_29A981: @ 829A981
	.string "A big body that’s all lumpy and hard,\n"
	.string "enormous horns, and vicious fangs…\p"
	.string "Ufufufufu…\n"
	.string "I wish I had a POKéMON like that…$"

Route114_Text_29A9F7: @ 829A9F7
	.string "Don’t forget what you’ve done to me!\n"
	.string "I’ll make it so you can’t forget!$"

Route114_Text_29AA3E: @ 829AA3E
	.string "Ufufufufufu…\n"
	.string "Come on, battle my POKéMON…$"

Route114_Text_29AA67: @ 829AA67
	.string "I feel so lucky getting to see your\n"
	.string "POKéMON…$"

Route114_Text_29AA94: @ 829AA94
	.string "Ufufufufufu…\p"
	.string "When I see POKéMON battling, I get all\n"
	.string "shivery and shaky…$"

Route114_Text_29AADB: @ 829AADB
	.string "If you’re lighting a campfire,\n"
	.string "make sure you have water handy.$"

Route114_Text_29AB1A: @ 829AB1A
	.string "Thanks for dousing my fire!$"

Route114_Text_29AB36: @ 829AB36
	.string "You really do have to be careful with\n"
	.string "any sort of fire in a forest.\p"
	.string "Don’t ever underestimate the power\n"
	.string "of fire.$"

Route114_Text_29ABA6: @ 829ABA6
	.string "You set my spirit on fire.\n"
	.string "Let’s register each other!$"

Route114_Text_29ABDC: @ 829ABDC
	.string "Have you learned to keep water handy\n"
	.string "for campfires?$"

Route114_Text_29AC10: @ 829AC10
	.string "I got hosed down before I could\n"
	.string "flare up, I guess.$"

Route114_Text_29AC43: @ 829AC43
	.string "You really do have to be careful with\n"
	.string "any sort of fire in a forest.\p"
	.string "Don’t ever underestimate the power\n"
	.string "of fire.$"

Route114_Text_29ACB3: @ 829ACB3
	.string "If we were fishing, you wouldn’t stand\n"
	.string "a chance against me.\l"
	.string "So, bring on your POKéMON!$"

Route114_Text_29AD0A: @ 829AD0A
	.string "If we were fishing, I would’ve won…$"

Route114_Text_29AD2E: @ 829AD2E
	.string "I think I’ll try my luck at landing\n"
	.string "a big one at METEOR FALLS.\p"
	.string "There has to be something in there.\n"
	.string "I just know it.$"

Route114_Text_29ADA1: @ 829ADA1
	.string "I like to fish. But I also like to\n"
	.string "battle!\p"
	.string "If anyone challenges me, I’m there,\n"
	.string "even if I’m fishing.$"

Route114_Text_29AE05: @ 829AE05
	.string "I like to battle, but that doesn’t\n"
	.string "mean I’m good at it…$"

Route114_Text_29AE3D: @ 829AE3D
	.string "This time I’ll do it!\p"
	.string "I always think that, so I can’t walk\n"
	.string "away from fishing or POKéMON.$"

Route114_Text_29AE96: @ 829AE96
	.string "TYRA: Well, sure.\n"
	.string "I’m in the mood for it.\l"
	.string "I’ll teach you a little about POKéMON.$"

Route114_Text_29AEE7: @ 829AEE7
	.string "TYRA: What an amazing battle style!$"

Route114_Text_29AF0B: @ 829AF0B
	.string "TYRA: I was teaching my junior IVY\n"
	.string "about POKéMON.$"

Route114_Text_29AF3D: @ 829AF3D
	.string "TYRA: Giggle…\n"
	.string "If you want to battle with us, just one\l"
	.string "POKéMON isn’t enough!$"

Route114_Text_29AF89: @ 829AF89
	.string "IVY: Who taught you about POKéMON?$"

Route114_Text_29AFAC: @ 829AFAC
	.string "IVY: What an amazing battle style!$"

Route114_Text_29AFCF: @ 829AFCF
	.string "IVY: I started training POKéMON\n"
	.string "because TYRA, my student mentor,\l"
	.string "taught me!$"

Route114_Text_29B01B: @ 829B01B
	.string "IVY: Do you only have one POKéMON?\n"
	.string "I think it must feel lonesome.$"

Route114_Text_29B05D: @ 829B05D
	.string "I landed a big one!\n"
	.string "A huge one, I tell you!$"

Route114_Text_29B089: @ 829B089
	.string "What was that about?\n"
	.string "Did mine lose in size?$"

Route114_Text_29B0B5: @ 829B0B5
	.string "Okay!\n"
	.string "I’ll just fish me a bigger one!$"

Route114_Text_29B0DB: @ 829B0DB
	.string "Me!\n"
	.string "I’m not just a pretty face!$"

Route114_Text_29B0FB: @ 829B0FB
	.string "That wasn’t cute in the least!$"

Route114_Text_29B11A: @ 829B11A
	.string "I don’t want a POKéMON that’s\n"
	.string "just cute.\p"
	.string "I adore cute ones that have a quirk\n"
	.string "or two!$"

Route114_Text_29B16F: @ 829B16F
	.string "Have you made your POKéMON evolve\n"
	.string "very much?$"

Route114_Text_29B19C: @ 829B19C
	.string "Oh, I see.\n"
	.string "That’s good to know.$"

Route114_Text_29B1BC: @ 829B1BC
	.string "Some POKéMON change so much when\n"
	.string "they evolve, it’s startling!$"

Route115_Text_29B1FA: @ 829B1FA
	.string "Hm…\n"
	.string "You seem rather capable…\l"
	.string "Let me keep you company!$"

Route115_Text_29B230: @ 829B230
	.string "You’re much stronger than\n"
	.string "I’d imagined!$"

Route115_Text_29B258: @ 829B258
	.string "There is no such thing as a born genius.\n"
	.string "It all depends on effort!\l"
	.string "That is what I believe…$"

Route115_Text_29B2B3: @ 829B2B3
	.string "Hmm… A loss this thorough has been\n"
	.string "a distant memory.\p"
	.string "If you would allow it, I wish for\n"
	.string "another opportunity to do battle.$"

Route115_Text_29B32C: @ 829B32C
	.string "Hm… As always, your agility speaks\n"
	.string "for itself.\l"
	.string "Come, keep me company!$"

Route115_Text_29B372: @ 829B372
	.string "As strong as ever!$"

Route115_Text_29B385: @ 829B385
	.string "All it takes is effort!\p"
	.string "I lost because I haven’t put in enough\n"
	.string "effort!$"

Route115_Text_29B3CC: @ 829B3CC
	.string "You!\p"
	.string "My MACHOP!\p"
	.string "Demand a battle!$"

Route115_Text_29B3ED: @ 829B3ED
	.string "Ouch, ouch, ouch!$"

Route115_Text_29B3FF: @ 829B3FF
	.string "My MACHOP crew!\p"
	.string "So long as they seek power, I will\n"
	.string "grow strong with them!$"

Route115_Text_29B449: @ 829B449
	.string "My strongest skill is busting bricks\n"
	.string "with my forehead!$"

Route115_Text_29B480: @ 829B480
	.string "Ugwaaaah!\n"
	.string "My head is busted!$"

Route115_Text_29B49D: @ 829B49D
	.string "I’ve been teaching my POKéMON karate.\p"
	.string "It looks like they’ll get a lot better\n"
	.string "than me. I’m excited about that.$"

Route115_Text_29B50B: @ 829B50B
	.string "You impress me! Give me a rematch\n"
	.string "after I redo my training!$"

Route115_Text_29B547: @ 829B547
	.string "After you beat me, we trained hard to\n"
	.string "improve our skills.\l"
	.string "Come on, give us a rematch!$"

Route115_Text_29B59D: @ 829B59D
	.string "Ugwaaah!\n"
	.string "We lost again!$"

Route115_Text_29B5B5: @ 829B5B5
	.string "My POKéMON will grow stronger!\n"
	.string "I’ll redouble my training!$"

Route115_Text_29B5EF: @ 829B5EF
	.string "This beach is my secret training spot!\n"
	.string "Don’t come butting in!$"

Route115_Text_29B62D: @ 829B62D
	.string "I haven’t trained enough!$"

Route115_Text_29B647: @ 829B647
	.string "The sand acts as a cushion to reduce\n"
	.string "impact and prevent injury.\l"
	.string "This is the perfect place to train.$"

Route115_Text_29B6AB: @ 829B6AB
	.string "Okay, fine, you’re free to come here.\n"
	.string "In return, I’d like to battle you again.$"

Route115_Text_29B6FA: @ 829B6FA
	.string "Okay, let’s get this battle on!$"

Route115_Text_29B71A: @ 829B71A
	.string "I can battle but my POKéMON…$"

Route115_Text_29B737: @ 829B737
	.string "Even when I lose, I still get some\n"
	.string "enjoyment out of it.\l"
	.string "It must be that I love POKéMON.$"

Route115_Text_29B78F: @ 829B78F
	.string "I have a rare POKéMON!\n"
	.string "Would you like me to show you?$"

Route115_Text_29B7C5: @ 829B7C5
	.string "You…\n"
	.string "You want my POKéMON, don’t you?$"

Route115_Text_29B7EA: @ 829B7EA
	.string "I have this rare POKéMON.\n"
	.string "It’s enough to keep me satisfied.$"

Route115_Text_29B826: @ 829B826
	.string "I’ll battle while I’m running!\n"
	.string "Try to keep up with me!$"

Route115_Text_29B85D: @ 829B85D
	.string "Gasp, gasp…$"

Route115_Text_29B869: @ 829B869
	.string "I made the mistake of trying to battle\n"
	.string "while running!\p"
	.string "I should take a run to calm down…$"

Route115_Text_29B8C1: @ 829B8C1
	.string "Take that!\n"
	.string "Ultra POKéMON ninja attack!$"

Route115_Text_29B8E8: @ 829B8E8
	.string "Waaah!\n"
	.string "Our strategy failed!$"

Route115_Text_29B904: @ 829B904
	.string "But my POKéMON were ultra,\n"
	.string "weren’t they?$"

Route115_Text_29B92D: @ 829B92D
	.string "My POKéMON have black belt-level\n"
	.string "strength!$"

Route115_Text_29B958: @ 829B958
	.string "This is too humiliating!$"

Route115_Text_29B971: @ 829B971
	.string "I rarely meet anyone who’s better\n"
	.string "than me…\p"
	.string "I get it now!\n"
	.string "You’re a GYM LEADER, aren’t you?$"

Route115_Text_29B9CB: @ 829B9CB
	.string "Our eyes met!\n"
	.string "There’s no getting away now!$"

Route115_Text_29B9F6: @ 829B9F6
	.string "Gah!\n"
	.string "Not bad!$"

Route115_Text_29BA04: @ 829BA04
	.string "Oh, well.\n"
	.string "I think I will TELEPORT home.$"

Route115_Text_29BA2C: @ 829BA2C
	.string "You’ve disturbed my meditation…\n"
	.string "You’ll be punished for it.$"

Route115_Text_29BA67: @ 829BA67
	.string "You’ve broken my concentration!$"

Route115_Text_29BA87: @ 829BA87
	.string "I was meditating with my POKéMON.\n"
	.string "But this place isn’t very peaceful…$"

Route116_Text_29BACD: @ 829BACD
	.string "If the tunnel doesn’t go through, then\n"
	.string "I’ll just go over the top.$"

Route116_Text_29BB0F: @ 829BB0F
	.string "Gasp… Gasp…\n"
	.string "Losing made me tired…$"

Route116_Text_29BB31: @ 829BB31
	.string "It’s no big deal if there’s no tunnel.\n"
	.string "To a HIKER, mountains are roads!$"

Route116_Text_29BB79: @ 829BB79
	.string "My POKéMON rule!\n"
	.string "Check them out!$"

Route116_Text_29BB9A: @ 829BB9A
	.string "Ouch! A scrape!\n"
	.string "I have to put on a bandage!$"

Route116_Text_29BBC6: @ 829BBC6
	.string "Bandages are signs of toughness!\n"
	.string "I’ve got another one!$"

Route116_Text_29BBFD: @ 829BBFD
	.string "My BUG POKéMON are tough!\n"
	.string "Let’s battle!$"

Route116_Text_29BC25: @ 829BC25
	.string "I lost!\n"
	.string "I thought I had you!$"

Route116_Text_29BC42: @ 829BC42
	.string "BUG POKéMON evolve quickly.\n"
	.string "So they get strong quickly, too.$"

Route116_Text_29BC7F: @ 829BC7F
	.string "Let me teach you how strong my\n"
	.string "adorable POKéMON is!$"

Route116_Text_29BCB3: @ 829BCB3
	.string "You’re a notch above me…$"

Route116_Text_29BCCC: @ 829BCCC
	.string "POKéMON that possess cuteness and\n"
	.string "power, that’s ideal, I think.$"

Route116_Text_29BD0C: @ 829BD0C
	.string "We learn all sorts of things at the\n"
	.string "TRAINER’S SCHOOL.\p"
	.string "I want to test things out for real!$"

Route116_Text_29BD66: @ 829BD66
	.string "I slacked off in school…\n"
	.string "That’s why I lost.$"

Route116_Text_29BD92: @ 829BD92
	.string "I’ll have to redo some courses at\n"
	.string "the TRAINER’S SCHOOL.\l"
	.string "If I don’t, ROXANNE will be steamed.$"

Route116_Text_29BDEF: @ 829BDEF
	.string "I learned at the TRAINER’S SCHOOL\n"
	.string "that a POKéNAV can register TRAINERS.\p"
	.string "I don’t really get what that means,\n"
	.string "so can I just try it?$"

Route116_Text_29BE71: @ 829BE71
	.string "I learned at the TRAINER’S SCHOOL\n"
	.string "that a POKéNAV can register TRAINERS.\p"
	.string "I don’t really get what that means,\n"
	.string "so can I just try it?$"

Route116_Text_29BEF3: @ 829BEF3
	.string "I’ve been studying seriously at the\n"
	.string "TRAINER’S SCHOOL.\l"
	.string "I won’t lose like I did last time.$"

Route116_Text_29BF4C: @ 829BF4C
	.string "Hunh?\n"
	.string "I studied diligently.$"

Route116_Text_29BF68: @ 829BF68
	.string "I’ll have to redo some courses at\n"
	.string "the TRAINER’S SCHOOL.\l"
	.string "If I don’t, ROXANNE will be steamed.$"

Route116_Text_29BFC5: @ 829BFC5
	.string "I study at school, and I study on\n"
	.string "the way home, too!$"

Route116_Text_29BFFA: @ 829BFFA
	.string "I’m in shock--I lost?$"

Route116_Text_29C010: @ 829C010
	.string "Awww, I’ll never become an elegant\n"
	.string "TRAINER like ROXANNE this way!$"

Route116_Text_29C052: @ 829C052
	.string "Oh, wow! Isn’t that a POKéNAV?\n"
	.string "I have one, too! Please register me!$"

Route116_Text_29C096: @ 829C096
	.string "Oh, wow! Isn’t that a POKéNAV?\n"
	.string "I have one, too! Please register me!$"

Route116_Text_29C0DA: @ 829C0DA
	.string "I studied a whole lot since I saw you.\n"
	.string "You must see my achievements!$"

Route116_Text_29C11F: @ 829C11F
	.string "I’m in shock.\n"
	.string "I lost again?$"

Route116_Text_29C13B: @ 829C13B
	.string "You’ve beaten ROXANNE?\n"
	.string "I can’t beat you, then. Not yet.$"

Route116_Text_29C173: @ 829C173
	.string "Just so you know, I’ve never once been\n"
	.string "bested by anyone at anything.$"

Route116_Text_29C1B8: @ 829C1B8
	.string "Oh, my goodness.\n"
	.string "This is a new experience for me.$"

Route116_Text_29C1EA: @ 829C1EA
	.string "My life of luxury affords me all that\n"
	.string "I could possibly desire.\p"
	.string "However, when it comes to POKéMON,\n"
	.string "my wealth has no meaning.$"

Route116_Text_29C266: @ 829C266
	.string "When you lay your eyes on my POKéMON’s\n"
	.string "gorgeous fur, their beauty will render\l"
	.string "you helpless!$"

Route116_Text_29C2C2: @ 829C2C2
	.string "Oh, baby, say it isn’t so!$"

Route116_Text_29C2DD: @ 829C2DD
	.string "Oh, no, no, no!\n"
	.string "You’ve mussed up my POKéMON’s fur!\l"
	.string "You’ve ruined my hairdo, too!\l"
	.string "I’ll have to call my stylist now!$"

Route116_Text_29C350: @ 829C350
	.string "We’ll rock you hard!$"

Route116_Text_29C365: @ 829C365
	.string "Aiyiyi!\n"
	.string "No contest at all!$"

Route116_Text_29C380: @ 829C380
	.string "I should try different POKéMON\n"
	.string "types, that’s what I ought to do.$"

Route116_Text_29C3C1: @ 829C3C1
	.string "It’s a dead end up here.\n"
	.string "I’m bored, so can we battle?$"

Route116_Text_29C3F7: @ 829C3F7
	.string "That was fun even though I lost.$"

Route116_Text_29C418: @ 829C418
	.string "Want to stay here and keep\n"
	.string "me company?$"

Route117_Text_29C43F: @ 829C43F
	.string "Listen, could I get you to battle\n"
	.string "the POKéMON I’m raising?$"

Route117_Text_29C47A: @ 829C47A
	.string "You’ve raised yours superbly…$"

Route117_Text_29C498: @ 829C498
	.string "POKéMON isn’t all about power.\p"
	.string "Polishing a unique aspect of one’s\n"
	.string "character is another way of enjoying\l"
	.string "POKéMON.$"

Route117_Text_29C508: @ 829C508
	.string "I’m going to redouble my training.\n"
	.string "Would you come look in on us?$"

Route117_Text_29C549: @ 829C549
	.string "The POKéMON I’ve been raising are\n"
	.string "looking good, just like before.$"

Route117_Text_29C58B: @ 829C58B
	.string "You know how to raise them properly.\n"
	.string "You might have DAY CARE skills…$"

Route117_Text_29C5D0: @ 829C5D0
	.string "Your POKéMON are growing good!\n"
	.string "You should enter them in CONTESTS.$"

Route117_Text_29C612: @ 829C612
	.string "Please, allow me to evaluate if you\n"
	.string "have raised your POKéMON properly.$"

Route117_Text_29C659: @ 829C659
	.string "Yes, they are growing properly.$"

Route117_Text_29C679: @ 829C679
	.string "Try raising POKéMON with more\n"
	.string "attention to their character traits.$"

Route117_Text_29C6BC: @ 829C6BC
	.string "I’m glad I met a superb TRAINER in you.\n"
	.string "I hope to see you again.$"

Route117_Text_29C6FD: @ 829C6FD
	.string "Allow me to reevaluate if you have\n"
	.string "raised your POKéMON properly.$"

Route117_Text_29C73E: @ 829C73E
	.string "They are growing admirably.$"

Route117_Text_29C75A: @ 829C75A
	.string "POKéMON seem to like different kinds\n"
	.string "of {POKEBLOCK}S, depending on their nature.$"

Route117_Text_29C7A5: @ 829C7A5
	.string "I’m in the middle of a triathlon, but,\n"
	.string "whatever, let’s have a battle!$"

Route117_Text_29C7EB: @ 829C7EB
	.string "I ran out of energy!$"

Route117_Text_29C800: @ 829C800
	.string "I may have blown it…\p"
	.string "I might have dropped to last during\n"
	.string "that battle…$"

Route117_Text_29C846: @ 829C846
	.string "POKéMON have to be strong, too?\n"
	.string "I’d like you to train me!$"

Route117_Text_29C880: @ 829C880
	.string "I’m smack in the middle of a triathlon,\n"
	.string "but I’m comfortably ahead.\l"
	.string "Let’s make this a quick battle!$"

Route117_Text_29C8E3: @ 829C8E3
	.string "I ran out of energy again!$"

Route117_Text_29C8FE: @ 829C8FE
	.string "I was tops in swimming and cycling,\n"
	.string "but I’m not quite that confident with\l"
	.string "POKéMON yet.$"

Route117_Text_29C955: @ 829C955
	.string "I do my triathlon training with POKéMON,\n"
	.string "so I’m pretty confident about my speed.$"

Route117_Text_29C9A6: @ 829C9A6
	.string "I need to get more practices in,\n"
	.string "I guess.$"

Route117_Text_29C9D0: @ 829C9D0
	.string "Training is meaningful only if you\n"
	.string "keep it up regularly.\p"
	.string "Okay! I’ll resume my training!\n"
	.string "Tomorrow!$"

Route117_Text_29CA32: @ 829CA32
	.string "You appear to be training properly…\n"
	.string "If you’d like, I’ll battle you later!$"

Route117_Text_29CA7C: @ 829CA7C
	.string "Are you keeping up with your training?\n"
	.string "I sure am!\l"
	.string "Let me show you the evidence!$"

Route117_Text_29CACC: @ 829CACC
	.string "I need to get more practices in,\n"
	.string "I guess.$"

Route117_Text_29CAF6: @ 829CAF6
	.string "I’ll resume training tomorrow.\n"
	.string "Let’s battle again sometime!$"

Route117_Text_29CB32: @ 829CB32
	.string "Once a BUG CATCHER!\n"
	.string "And now a BUG MANIAC!\p"
	.string "But my love for POKéMON remains\n"
	.string "unchanged!$"

Route117_Text_29CB87: @ 829CB87
	.string "My ineptitude also remains\n"
	.string "unchanged…$"

Route117_Text_29CBAD: @ 829CBAD
	.string "All I did was follow my heart, and now\n"
	.string "they call me a BUG MANIAC…\p"
	.string "Still, I am an expert on BUG POKéMON,\n"
	.string "so it’s only natural that they call me\l"
	.string "a BUG MANIAC.$"

Route117_Text_29CC4A: @ 829CC4A
	.string "ANNA: I’m with my pretty junior student\n"
	.string "partner. I have to do good!$"

Route117_Text_29CC8E: @ 829CC8E
	.string "ANNA: I’m with my pretty junior student\n"
	.string "partner! Let me win!$"

Route117_Text_29CCCB: @ 829CCCB
	.string "ANNA: Your POKéMON have some good\n"
	.string "combinations.\p"
	.string "I’d say you’re second only to us!$"

Route117_Text_29CD1D: @ 829CD1D
	.string "ANNA: We can’t take this lying down!\n"
	.string "You will come back, won’t you?$"

Route117_Text_29CD61: @ 829CD61
	.string "ANNA: If you want to battle us,\n"
	.string "bring two POKéMON with you.$"

Route117_Text_29CD9D: @ 829CD9D
	.string "MEG: I’m going to tag up with my super\n"
	.string "senior student partner and beat you!$"

Route117_Text_29CDE9: @ 829CDE9
	.string "MEG: Oh, no!\n"
	.string "I’m sorry, ANNA! I let you down…$"

Route117_Text_29CE17: @ 829CE17
	.string "MEG: I dragged ANNA down…\n"
	.string "If I didn’t, she would have won!$"

Route117_Text_29CE52: @ 829CE52
	.string "MEG: Do you only have one POKéMON?\n"
	.string "We can’t battle with you, then.\p"
	.string "We want to have a 2-on-2 battle.$"

Route117_Text_29CEB6: @ 829CEB6
	.string "ANNA: I can’t keep losing in front of\n"
	.string "my junior partner, right?$"

Route117_Text_29CEF6: @ 829CEF6
	.string "ANNA: I couldn’t get into the groove.$"

Route117_Text_29CF1C: @ 829CF1C
	.string "ANNA: Your POKéMON have some good\n"
	.string "combinations.\p"
	.string "I’d say you’re second only to us!$"

Route117_Text_29CF6E: @ 829CF6E
	.string "ANNA: If you want to battle us,\n"
	.string "bring two POKéMON with you.$"

Route117_Text_29CFAA: @ 829CFAA
	.string "MEG: I’m going to tag up with my\n"
	.string "senior partner and win this time!$"

Route117_Text_29CFED: @ 829CFED
	.string "MEG: Too strong!$"

Route117_Text_29CFFE: @ 829CFFE
	.string "MEG: I battled together with my\n"
	.string "senior partner, but we lost…\p"
	.string "That’s so discouraging…$"

Route117_Text_29D053: @ 829D053
	.string "MEG: Do you only have one POKéMON?\n"
	.string "We can’t battle with you, then.\p"
	.string "We want to have a 2-on-2 battle.$"

Route117_Text_29D0B7: @ 829D0B7
	.string "Isn’t it nice? To battle while looking\n"
	.string "at pretty flowers?$"

Route117_Text_29D0F1: @ 829D0F1
	.string "Oh, that’s quite impressive!$"

Route117_Text_29D10E: @ 829D10E
	.string "It feels wonderful to go for a jog\n"
	.string "while looking at flowers.$"

Route117_Text_29D14B: @ 829D14B
	.string "Let me demonstrate the power\n"
	.string "hidden within a PSYCHIC POKéMON!$"

Route117_Text_29D189: @ 829D189
	.string "Astonishing!$"

Route117_Text_29D196: @ 829D196
	.string "PSYCHIC POKéMON are complex.\n"
	.string "You should try catching some.$"

Route117_Text_29D1D1: @ 829D1D1
	.string "Concentrate on getting the win.\n"
	.string "That’s how I battle!$"

Route117_Text_29D206: @ 829D206
	.string "I don’t waste any time being angry\n"
	.string "over a loss--I would rather train.$"

Route117_Text_29D24C: @ 829D24C
	.string "I think that if you worry about losing,\n"
	.string "you’re more likely to lose.$"

Route118_Text_29D290: @ 829D290
	.string "The aroma of flowers has a magical\n"
	.string "power. It cleanses us body and soul.$"

Route118_Text_29D2D8: @ 829D2D8
	.string "Oh, dear me.\n"
	.string "I seem to have lost.$"

Route118_Text_29D2FA: @ 829D2FA
	.string "Flowers, POKéMON…\n"
	.string "I love whatever smells nice.\p"
	.string "Stinky things…\n"
	.string "I’ll pass.$"

Route118_Text_29D343: @ 829D343
	.string "Sniff… That odor--it’s a POKéNAV!\n"
	.string "We must register each other!$"

Route118_Text_29D382: @ 829D382
	.string "Were you drawn here by the sweet\n"
	.string "aroma?$"

Route118_Text_29D3AA: @ 829D3AA
	.string "The power of aroma…\n"
	.string "It didn’t seem to do much.$"

Route118_Text_29D3D9: @ 829D3D9
	.string "If you use a sweet aroma properly,\n"
	.string "POKéMON will be attracted by it.$"

Route118_Text_29D41D: @ 829D41D
	.string "BIRD POKéMON that FLY elegantly in\n"
	.string "the sky… They’re the best!$"

Route118_Text_29D45B: @ 829D45B
	.string "Urgh…\n"
	.string "I crashed…$"

Route118_Text_29D46C: @ 829D46C
	.string "You’ve got great POKéMON.\n"
	.string "I’ll have to train mine better.$"

Route118_Text_29D4A6: @ 829D4A6
	.string "Take flight!\n"
	.string "My BIRD POKéMON!$"

Route118_Text_29D4C4: @ 829D4C4
	.string "They did take flight…$"

Route118_Text_29D4DA: @ 829D4DA
	.string "If they’d get stronger, they’d be able\n"
	.string "to fly more freely…$"

Route118_Text_29D515: @ 829D515
	.string "I’m a FISHERMAN, but also a TRAINER.\n"
	.string "I’m raising the POKéMON I caught.$"

Route118_Text_29D55C: @ 829D55C
	.string "I thought I was doing okay in my\n"
	.string "training…$"

Route118_Text_29D587: @ 829D587
	.string "I couldn’t win by training POKéMON\n"
	.string "while I fished…\p"
	.string "Was I doing things in half measures?$"

Route118_Text_29D5DF: @ 829D5DF
	.string "For FISHERMEN, equipment is the key.\p"
	.string "But for TRAINERS, the key ingredients\n"
	.string "are POKéMON and heart, of course!$"

Route118_Text_29D64C: @ 829D64C
	.string "I was beaten in heart?$"

Route118_Text_29D663: @ 829D663
	.string "Come to think of it, fishing is a battle\n"
	.string "between a FISHERMAN and a POKéMON.$"

Route118_Text_29D6AF: @ 829D6AF
	.string "Let my melody rock your soul!$"

Route118_Text_29D6CD: @ 829D6CD
	.string "La-lalala…$"

Route118_Text_29D6D8: @ 829D6D8
	.string "An electric guitar doesn’t always\n"
	.string "have to be noisy…\p"
	.string "It can be strummed to squeeze out\n"
	.string "this heart-stirring melody…$"

Route118_Text_29D74A: @ 829D74A
	.string "When I compose better melodies,\n"
	.string "you have to come listen, okay?$"

Route118_Text_29D789: @ 829D789
	.string "A melody from my POKéMON and me…\n"
	.string "Let us deliver it to your soul.$"

Route118_Text_29D7CA: @ 829D7CA
	.string "La-lalala…$"

Route118_Text_29D7D5: @ 829D7D5
	.string "When I play, my emotions should reach\n"
	.string "you through my electric guitar…$"

Route118_Text_29D81B: @ 829D81B
	.string "Go, go, go!\n"
	.string "POKéMON 1, 2, and 3!$"

Route118_Text_29D83C: @ 829D83C
	.string "Come in, POKéMON! Are you okay?\n"
	.string "POKéMON 1, 2, and 3?!$"

Route118_Text_29D872: @ 829D872
	.string "Isn’t it cool that I have a POKéMON\n"
	.string "battle team?\p"
	.string "You can copy me--I don’t mind!$"

Route119_Text_29D8C2: @ 829D8C2
	.string "We’re the MIMIC CIRCLE!\n"
	.string "We MIMIC what you do!$"

Route119_Text_29D8F0: @ 829D8F0
	.string "Whoopsie!\n"
	.string "I lost!$"

Route119_Text_29D902: @ 829D902
	.string "What’s so good about mimicry?\p"
	.string "Fufufu…\n"
	.string "You’ll never understand…$"

Route119_Text_29D941: @ 829D941
	.string "So, we finally meet!\n"
	.string "My BUG POKéMON will keep you company!$"

Route119_Text_29D97C: @ 829D97C
	.string "I wish we’d never met…$"

Route119_Text_29D993: @ 829D993
	.string "I want to MIMIC you some more.\n"
	.string "Can you hurry up and move?$"

Route119_Text_29D9CD: @ 829D9CD
	.string "If you step forward, we step forward.\p"
	.string "If you turn right, we turn, too…$"

Route119_Text_29DA14: @ 829DA14
	.string "But if you win, I lose…$"

Route119_Text_29DA2C: @ 829DA2C
	.string "I can’t MIMIC you winning the match.\n"
	.string "That’s just impossible…\l"
	.string "It’s burning me up…$"

Route119_Text_29DA7D: @ 829DA7D
	.string "Yep, you’ve finally caught me!\n"
	.string "Or were you trying to avoid me?$"

Route119_Text_29DABC: @ 829DABC
	.string "Whoop, that was a great match!$"

Route119_Text_29DADB: @ 829DADB
	.string "We’re the MIMIC CIRCLE!\n"
	.string "I hope you enjoyed our performance.$"

Route119_Text_29DB17: @ 829DB17
	.string "You don’t know who I am, do you?\p"
	.string "But, I also don’t know you.\n"
	.string "So, we’ll battle!$"

Route119_Text_29DB66: @ 829DB66
	.string "You’re pretty strong!$"

Route119_Text_29DB7C: @ 829DB7C
	.string "Until you go away somewhere, we’ll\n"
	.string "keep on mimicking your every move.$"

Route119_Text_29DBC2: @ 829DBC2
	.string "The MIMIC CIRCLE was formed by people\n"
	.string "who like to MIMIC.\p"
	.string "A battle starts the instant we meet!$"

Route119_Text_29DC20: @ 829DC20
	.string "I give up!$"

Route119_Text_29DC2B: @ 829DC2B
	.string "Won’t you join our MIMIC CIRCLE?$"

Route119_Text_29DC4C: @ 829DC4C
	.string "Who has the knowledge and\n"
	.string "the technique for survival?\p"
	.string "POKéMON RANGERS, that’s who!$"

Route119_Text_29DC9F: @ 829DC9F
	.string "I didn’t have enough POKéMON\n"
	.string "know-how…$"

Route119_Text_29DCC6: @ 829DCC6
	.string "To break away from civilization and\n"
	.string "awaken the wild spirit within!\p"
	.string "That’s our vision.$"

Route119_Text_29DD1C: @ 829DD1C
	.string "I hope you’ll give me a rematch without\n"
	.string "mocking my lack of knowledge.$"

Route119_Text_29DD62: @ 829DD62
	.string "I’m going to regain my wild spirit by\n"
	.string "being together with POKéMON.$"

Route119_Text_29DDA5: @ 829DDA5
	.string "You’ve remained strong!$"

Route119_Text_29DDBD: @ 829DDBD
	.string "Believe in your POKéMON.\n"
	.string "Believe in yourself.\p"
	.string "The road will reveal itself to you.$"

Route119_Text_29DE0F: @ 829DE0F
	.string "Oh? Look at you.\p"
	.string "For someone on an adventure,\n"
	.string "you’re traveling awfully light.$"

Route119_Text_29DE5D: @ 829DE5D
	.string "Accidents happen when you’re not\n"
	.string "prepared!$"

Route119_Text_29DE88: @ 829DE88
	.string "You’re traveling light but you have\n"
	.string "everything you need.\p"
	.string "You’re on top of things mentally and\n"
	.string "physically, too.$"

Route119_Text_29DEF7: @ 829DEF7
	.string "Do you have a POKéNAV?\n"
	.string "It’s a must-have tool for any TRAINER.\p"
	.string "Oh, you do have one!\n"
	.string "Let’s register each other, then!$"

Route119_Text_29DF6B: @ 829DF6B
	.string "How’s your journey with POKéMON\n"
	.string "going?$"

Route119_Text_29DF92: @ 829DF92
	.string "I’m still missing something…$"

Route119_Text_29DFAF: @ 829DFAF
	.string "In the same way that you, as a TRAINER,\n"
	.string "rely on your POKéMON, your POKéMON\l"
	.string "rely on you.$"

Route119_Text_29E007: @ 829E007
	.string "The vast sky holds untold promise!\p"
	.string "Nothing can compare to the sheer\n"
	.string "exhilaration of flight!$"

Route119_Text_29E063: @ 829E063
	.string "Down and out!$"

Route119_Text_29E071: @ 829E071
	.string "My BIRD POKéMON made my dreams of\n"
	.string "flying come true!$"

Route119_Text_29E0A5: @ 829E0A5
	.string "I’ll show you the true potential of me\n"
	.string "and my BIRD POKéMON!$"

Route119_Text_29E0E1: @ 829E0E1
	.string "We lacked potential…$"

Route119_Text_29E0F6: @ 829E0F6
	.string "Ever since I was a little kid, I always\n"
	.string "admired BIRD POKéMON…$"

Route119_Text_29E134: @ 829E134
	.string "To lurk in shadows, and live in\n"
	.string "darkness… That is my destiny.\p"
	.string "I emerge to challenge you!$"

Route119_Text_29E18D: @ 829E18D
	.string "I admit defeat!$"

Route119_Text_29E19D: @ 829E19D
	.string "Those defeated in battle withdraw\n"
	.string "quietly back into the shadows.\l"
	.string "That, too, is destiny…$"

Route119_Text_29E1F5: @ 829E1F5
	.string "If you’re not on your guard,\n"
	.string "you’re in for some pain!$"

Route119_Text_29E22B: @ 829E22B
	.string "You’re surprisingly good!$"

Route119_Text_29E245: @ 829E245
	.string "My surprise attack ended in\n"
	.string "failure…$"

Route119_Text_29E26A: @ 829E26A
	.string "To hide a tree, use a forest!$"

Route119_Text_29E288: @ 829E288
	.string "I bow to your superiority.$"

Route119_Text_29E2A3: @ 829E2A3
	.string "To hide a tree, use a forest!\n"
	.string "To hide a POKéMON, use a POKéMON!\p"
	.string "There is no deep, hidden meaning\n"
	.string "to that.$"

Route119_Text_29E30D: @ 829E30D
	.string "You spoke to me…\n"
	.string "So you want to challenge me!\p"
	.string "Sure! I’ll try out the POKéMON I caught\n"
	.string "while SURFING!$"

Route119_Text_29E372: @ 829E372
	.string "I don’t have a clue about what it\n"
	.string "takes to win.$"

Route119_Text_29E3A2: @ 829E3A2
	.string "Go for a SURF on my POKéMON…\p"
	.string "Then fish off its back…\p"
	.string "It’s an indescribably luxuriant moment!$"

Route119_Text_29E3FF: @ 829E3FF
	.string "Hit me with a power chord!\n"
	.string "Victory is mine!\l"
	.string "It’s our time to shine, whoa, yeah!$"

Route119_Text_29E44F: @ 829E44F
	.string "You showed me who’s the boss!\n"
	.string "We’ll have to take the loss, oh, no!$"

Route119_Text_29E492: @ 829E492
	.string "Hit me with another power chord!\n"
	.string "Leave me alone!\l"
	.string "Your win you have to atone!$"

Route119_Text_29E4DF: @ 829E4DF
	.string "Hohoho!\n"
	.string "I like kid TRAINERS!\l"
	.string "Let’s have a good one!$"

Route119_Text_29E513: @ 829E513
	.string "You’re pretty amazing!\n"
	.string "Hohoho!$"

Route119_Text_29E532: @ 829E532
	.string "Hohoho!\n"
	.string "I’ll try emulating the pep of kid\l"
	.string "TRAINERS like you!$"

Route119_Text_29E56F: @ 829E56F
	.string "Wherever and whenever I may be,\n"
	.string "I always have my parasol in hand.$"

Route119_Text_29E5B1: @ 829E5B1
	.string "Oh, but…\n"
	.string "That’s not fair.$"

Route119_Text_29E5CB: @ 829E5CB
	.string "You’re asking if my parasol is heavy?\n"
	.string "Your BAG is filled with more junk than\l"
	.string "I ever carry around.$"

Route120_Text_29E62D: @ 829E62D
	.string "Do you have any moves that can strike\n"
	.string "a flying POKéMON?$"

Route120_Text_29E665: @ 829E665
	.string "You soared above me!$"

Route120_Text_29E67A: @ 829E67A
	.string "The move FLY is convenient,\n"
	.string "don’t you think?\p"
	.string "While the POKéMON is flying,\n"
	.string "almost no moves can strike it.$"

Route120_Text_29E6E3: @ 829E6E3
	.string "My POKéMON is strong!\n"
	.string "How about yours?$"

Route120_Text_29E70A: @ 829E70A
	.string "Your POKéMON were stronger…$"

Route120_Text_29E726: @ 829E726
	.string "A POKéMON that grows steadily is one\n"
	.string "you can count on.$"

Route120_Text_29E75D: @ 829E75D
	.string "You can be counted on to get better.\n"
	.string "I’d like to register you in my POKéNAV!$"

Route120_Text_29E7AA: @ 829E7AA
	.string "A POKéMON that grows steadily is one\n"
	.string "you can count on.$"

Route120_Text_29E7E1: @ 829E7E1
	.string "Your POKéMON are seriously strong.$"

Route120_Text_29E804: @ 829E804
	.string "My POKéMON are growing stronger.\n"
	.string "I have to grow stronger, too.$"

Route120_Text_29E843: @ 829E843
	.string "I’ll check your POKéMON and see if\n"
	.string "they’re fit for the outdoors.$"

Route120_Text_29E884: @ 829E884
	.string "With POKéMON that strong, you’re in\n"
	.string "no danger of needing rescue!$"

Route120_Text_29E8C5: @ 829E8C5
	.string "To travel wherever your heart desires\n"
	.string "with POKéMON…\l"
	.string "That’s the joy of being a TRAINER.$"

Route120_Text_29E91C: @ 829E91C
	.string "How’s your physical fitness?\n"
	.string "If you’re not fit, you could have a\l"
	.string "rough time in critical situations.$"

Route120_Text_29E980: @ 829E980
	.string "I’m totally fit, but…$"

Route120_Text_29E996: @ 829E996
	.string "Fitness training is in my routine.\n"
	.string "I always run with my POKéMON.$"

Route120_Text_29E9D7: @ 829E9D7
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "Want to battle?$"

Route120_Text_29E9FF: @ 829E9FF
	.string "Lost it…$"

Route120_Text_29EA08: @ 829EA08
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "I’ll try harder…$"

Route120_Text_29EA31: @ 829EA31
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "Do you have a POKéNAV…?$"

Route120_Text_29EA61: @ 829EA61
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "Want to battle again?$"

Route120_Text_29EA8F: @ 829EA8F
	.string "… … … … … …\n"
	.string "I lost again…$"

Route120_Text_29EAA9: @ 829EAA9
	.string "… … … … … …\n"
	.string "… … … … … …\l"
	.string "I’ll try harder…\l"
	.string "For my precious BUG POKéMON…$"

Route120_Text_29EAEF: @ 829EAEF
	.string "POKéMON have many special abilities.\n"
	.string "If you want to become a first-class\l"
	.string "TRAINER, learn about them.$"

Route120_Text_29EB53: @ 829EB53
	.string "You’re obviously thinking.$"

Route120_Text_29EB6E: @ 829EB6E
	.string "The special abilities of POKéMON\n"
	.string "will make battle styles change.$"

Route120_Text_29EBAF: @ 829EBAF
	.string "Who might you be?\p"
	.string "Are you perhaps searching for ancient\n"
	.string "ruins that are rumored to possibly\l"
	.string "exist according to legend?$"

Route120_Text_29EC25: @ 829EC25
	.string "What a disgraceful setback…$"

Route120_Text_29EC41: @ 829EC41
	.string "That giant rock… I would like to\n"
	.string "believe it may indeed contain ancient\l"
	.string "ruins. But I see no entrance.$"

Route120_Text_29ECA6: @ 829ECA6
	.string "Why am I carrying this parasol?\p"
	.string "I’ll tell you if you can win against me.$"

Route120_Text_29ECEF: @ 829ECEF
	.string "A parasol can’t ward off POKéMON\n"
	.string "attacks…$"

Route120_Text_29ED19: @ 829ED19
	.string "I don’t think strong sunlight is good\n"
	.string "for my POKéMON.\l"
	.string "So I shield them with my parasol.$"

Route120_Text_29ED71: @ 829ED71
	.string "Me, POKéMON, and my parasol…\p"
	.string "If any one of them is missing,\n"
	.string "the picture of beauty will be ruined.$"

Route120_Text_29EDD3: @ 829EDD3
	.string "You’ve completely ruined my beauty…$"

Route120_Text_29EDF7: @ 829EDF7
	.string "A parasol wouldn’t suit you at all.\p"
	.string "Why, something like this would only\n"
	.string "get in your way.$"

Route120_Text_29EE50: @ 829EE50
	.string "I will adopt the movements of POKéMON\n"
	.string "and create new ninja techniques.$"

Route120_Text_29EE97: @ 829EE97
	.string "The creation of new ninja techniques\n"
	.string "is but a distant dream…$"

Route120_Text_29EED4: @ 829EED4
	.string "Perhaps I ought to apprentice under\n"
	.string "a ninja sensei.$"

Route120_Text_29EF08: @ 829EF08
	.string "We ninja conceal ourselves under our\n"
	.string "camouflage cloaks.\l"
	.string "I bet you didn’t know where I was!$"

Route120_Text_29EF63: @ 829EF63
	.string "I lost!\n"
	.string "I should camouflage my shame!$"

Route120_Text_29EF89: @ 829EF89
	.string "Our camouflage cloaks are all\n"
	.string "handmade.$"

Route120_Text_29EFB1: @ 829EFB1
	.string "If you don’t pay attention,\n"
	.string "you could get hurt!$"

Route120_Text_29EFE1: @ 829EFE1
	.string "Ouch!\n"
	.string "I was the one to get hurt.$"

Route120_Text_29F002: @ 829F002
	.string "I wonder… Should I evolve my POKéMON?\n"
	.string "They’re cute the way they are, though.$"

Route120_Text_29F04F: @ 829F04F
	.string "Your party POKéMON…\n"
	.string "Do you have different types?$"

Route120_Text_29F080: @ 829F080
	.string "I’ve seen your policy in action!$"

Route120_Text_29F0A1: @ 829F0A1
	.string "I think it’s awesome you’re so strong\n"
	.string "battling with your favorite POKéMON.$"

Route121_Text_29F0EC: @ 829F0EC
	.string "Will you play with my delightfully\n"
	.string "pretty POKéMON?$"

Route121_Text_29F11F: @ 829F11F
	.string "This isn’t what I meant!$"

Route121_Text_29F138: @ 829F138
	.string "I’m going to a CONTEST in LILYCOVE.\p"
	.string "My POKéMON should have no problem\n"
	.string "sweeping the MASTER CLASS.$"

Route121_Text_29F199: @ 829F199
	.string "With my POKéMON, I have traveled\n"
	.string "to the world’s four corners.\p"
	.string "You might say I have some confidence\n"
	.string "in my abilities.$"

Route121_Text_29F20D: @ 829F20D
	.string "Ah, well played.$"

Route121_Text_29F21E: @ 829F21E
	.string "I would like to circle the globe once\n"
	.string "again with my POKéMON.$"

Route121_Text_29F25B: @ 829F25B
	.string "Your POKéMON prowess is remarkable.\n"
	.string "Allow me to register you as a memento.$"

Route121_Text_29F2A6: @ 829F2A6
	.string "With my POKéMON, I have traveled\n"
	.string "to the world’s four corners.\p"
	.string "You might say I have some confidence\n"
	.string "in my abilities.$"

Route121_Text_29F31A: @ 829F31A
	.string "Ah, well played.$"

Route121_Text_29F32B: @ 829F32B
	.string "Your POKéMON and you…\p"
	.string "Your prowess together will be\n"
	.string "considered strong, even overseas.$"

Route121_Text_29F381: @ 829F381
	.string "There are powers beyond our\n"
	.string "understanding in the world…$"

Route121_Text_29F3B9: @ 829F3B9
	.string "I have lost…$"

Route121_Text_29F3C6: @ 829F3C6
	.string "MT. PYRE…\n"
	.string "There is a mysterious power\l"
	.string "at work there…$"

Route121_Text_29F3FB: @ 829F3FB
	.string "KATE: Together, we’re fearless!\n"
	.string "We’ll demonstrate how tough we are!$"

Route121_Text_29F43F: @ 829F43F
	.string "KATE: I blew it in front of my junior\n"
	.string "student partner…$"

Route121_Text_29F476: @ 829F476
	.string "KATE: When someone’s relying on me,\n"
	.string "I get this urge to look cool in front\l"
	.string "of them…$"

Route121_Text_29F4C9: @ 829F4C9
	.string "KATE: If you’ve only got one POKéMON,\n"
	.string "we can’t battle with you.\p"
	.string "That would be bullying.$"

Route121_Text_29F521: @ 829F521
	.string "JOY: Together, we’re fearless!\n"
	.string "We’ll demonstrate how tough we are!$"

Route121_Text_29F564: @ 829F564
	.string "JOY: Please forgive me, KATE!$"

Route121_Text_29F582: @ 829F582
	.string "JOY: Ehehe, I’ll have to train with KATE,\n"
	.string "my senior student partner, again.$"

Route121_Text_29F5CE: @ 829F5CE
	.string "JOY: You need at least two POKéMON\n"
	.string "if you’re going to challenge us!$"

Route121_Text_29F612: @ 829F612
	.string "Stop! Have a good look at my precious\n"
	.string "POKéMON!$"

Route121_Text_29F641: @ 829F641
	.string "Oh, how dare you!\n"
	.string "Don’t take it so seriously!$"

Route121_Text_29F66F: @ 829F66F
	.string "Maybe I’ll go catch more POKéMON at\n"
	.string "the SAFARI.$"

Route121_Text_29F69F: @ 829F69F
	.string "I took it easy on you this time!\n"
	.string "It won’t be that way the next time!$"

Route121_Text_29F6E4: @ 829F6E4
	.string "My precious POKéMON grew!\n"
	.string "Have a good look!$"

Route121_Text_29F710: @ 829F710
	.string "Oh, how dare you!\n"
	.string "You still won’t take it easy!$"

Route121_Text_29F740: @ 829F740
	.string "Maybe I’ll go catch more POKéMON at\n"
	.string "the SAFARI.$"

Route121_Text_29F770: @ 829F770
	.string "I have this routine.\n"
	.string "Defeat five TRAINERS a day.\l"
	.string "Guess what? You’re number five!$"

Route121_Text_29F7C1: @ 829F7C1
	.string "No!\n"
	.string "You’re horrid!$"

Route121_Text_29F7D4: @ 829F7D4
	.string "I didn’t expect to lose this easily…\n"
	.string "I’ll win next time!$"

Route121_Text_29F80D: @ 829F80D
	.string "That was total humiliation!\n"
	.string "I won’t forget you…\l"
	.string "Hand over your POKéNAV!$"

Route121_Text_29F855: @ 829F855
	.string "I have this new routine.\n"
	.string "Defeat ten TRAINERS a day.\l"
	.string "Guess what? You’re number ten!$"

Route121_Text_29F8A8: @ 829F8A8
	.string "Wait! That’s nasty!\n"
	.string "I demand a rematch!$"

Route121_Text_29F8D0: @ 829F8D0
	.string "An opponent I just can’t beat…\n"
	.string "Snivel…\l"
	.string "I can’t believe this is happening…$"

Route121_Text_29F91A: @ 829F91A
	.string "Can’t you see that I have all this\n"
	.string "stuff with me?\p"
	.string "Despite that, you still insist that\n"
	.string "we battle?$"

Route121_Text_29F97B: @ 829F97B
	.string "Of course I lost!\n"
	.string "I’m holding stuff in both hands!$"

Route121_Text_29F9AE: @ 829F9AE
	.string "I bought too much stuff at\n"
	.string "the LILYCOVE DEPT. STORE.\p"
	.string "It’s up the road from here.\n"
	.string "I wish I had a BAG like yours.$"

Route121_Text_29FA1E: @ 829FA1E
	.string "There’s nothing I love more than\n"
	.string "checking out other people’s POKéMON!$"

Route121_Text_29FA64: @ 829FA64
	.string "Super awesome!$"

Route121_Text_29FA73: @ 829FA73
	.string "They’re great, your POKéMON!\n"
	.string "How do you raise them?$"

Route121_Text_29FAA7: @ 829FAA7
	.string "I want everybody to see the POKéMON\n"
	.string "I’ve raised!$"

Route121_Text_29FAD8: @ 829FAD8
	.string "Wow!\n"
	.string "Spectacular!$"

Route121_Text_29FAEA: @ 829FAEA
	.string "I raise every POKéMON with the same\n"
	.string "love and care--I don’t pick favorites.$"

Route121_Text_29FB35: @ 829FB35
	.string "My POKéMON have never tasted defeat!\n"
	.string "On their next win, I’m entering them\l"
	.string "in CONTESTS.$"

Route121_Text_29FB8C: @ 829FB8C
	.string "Oh, now what happened here?$"

Route121_Text_29FBA8: @ 829FBA8
	.string "I may have to train my gang some more\n"
	.string "before entering any CONTEST.$"

Route123_Text_29FBEB: @ 829FBEB
	.string "Want to determine how strong you are?\n"
	.string "I’ll be the test!$"

Route123_Text_29FC23: @ 829FC23
	.string "You passed with flying colors!$"

Route123_Text_29FC42: @ 829FC42
	.string "To best even me…\n"
	.string "Your strength is marvelous!$"

Route123_Text_29FC6F: @ 829FC6F
	.string "You seem to have a big collection\n"
	.string "of GYM BADGES.\p"
	.string "Let me see if you’re actually worthy of\n"
	.string "those BADGES!$"

Route123_Text_29FCD6: @ 829FCD6
	.string "Oh, you’re worthy, all right!$"

Route123_Text_29FCF4: @ 829FCF4
	.string "You did your BADGES proud in that\n"
	.string "match!$"

Route123_Text_29FD1D: @ 829FD1D
	.string "They say that good times are filled\n"
	.string "with good aromas.$"

Route123_Text_29FD53: @ 829FD53
	.string "Oh…\n"
	.string "I smell the bitter scent of misery…$"

Route123_Text_29FD7B: @ 829FD7B
	.string "The BERRY MASTER’s garden is filled\n"
	.string "with uplifting fragrances.$"

Route123_Text_29FDBA: @ 829FDBA
	.string "Being a psychic is about willpower.\p"
	.string "I’ve willed myself not to lose to\n"
	.string "anyone. That makes me strong!$"

Route123_Text_29FE1E: @ 829FE1E
	.string "I feel sad…$"

Route123_Text_29FE2A: @ 829FE2A
	.string "Being a psychic is about willpower.\n"
	.string "I thought I wouldn’t lose to you…$"

Route123_Text_29FE70: @ 829FE70
	.string "I sense it!\n"
	.string "You and I shall battle again!\l"
	.string "I can’t tell if I’ll win, though…\p"
	.string "Let’s see your POKéNAV.$"

Route123_Text_29FED4: @ 829FED4
	.string "I’ve convinced myself that I won’t\n"
	.string "lose anymore. That makes me strong!$"

Route123_Text_29FF1B: @ 829FF1B
	.string "I feel sad…$"

Route123_Text_29FF27: @ 829FF27
	.string "I should train at MT. PYRE…\n"
	.string "I’ll never beat you this way…$"

Route123_Text_29FF61: @ 829FF61
	.string "Don’t be too happy if your POKéMON\n"
	.string "develop psychic powers.\p"
	.string "You need to refine those powers to\n"
	.string "make them really useful.$"

Route123_Text_29FFD8: @ 829FFD8
	.string "Overwhelmed!$"

Route123_Text_29FFE5: @ 829FFE5
	.string "We all have psychic powers.\n"
	.string "We’ve just forgotten how to use them.$"

Route123_Text_2A0027: @ 82A0027
	.string "I would like to face you again.\n"
	.string "Is that okay with you?$"

Route123_Text_2A005E: @ 82A005E
	.string "Have you awoken the psychic powers\n"
	.string "within you?$"

Route123_Text_2A008D: @ 82A008D
	.string "Astounding!$"

Route123_Text_2A0099: @ 82A0099
	.string "Your power with POKéMON…\n"
	.string "That could be a psychic power, too.$"

Route123_Text_2A00D6: @ 82A00D6
	.string "MIU: Hello, TRAINER. I hope your\n"
	.string "POKéMON won’t cry when they lose.$"

Route123_Text_2A0119: @ 82A0119
	.string "MIU: Uh-oh, we lost.$"

Route123_Text_2A012E: @ 82A012E
	.string "MIU: TRAINER, your POKéMON are\n"
	.string "strong because you are friends.$"

Route123_Text_2A016D: @ 82A016D
	.string "MIU: It’s no fun to battle if you\n"
	.string "don’t have two POKéMON.$"

Route123_Text_2A01A7: @ 82A01A7
	.string "YUKI: Okay!\n"
	.string "We’re beating the TRAINER’s POKéMON!$"

Route123_Text_2A01D8: @ 82A01D8
	.string "YUKI: Uh-oh, we lost.$"

Route123_Text_2A01EE: @ 82A01EE
	.string "YUKI: Why are you so strong?\n"
	.string "We’ve never lost before.$"

Route123_Text_2A0224: @ 82A0224
	.string "YUKI: It’s no fun to battle if you\n"
	.string "don’t have two POKéMON.$"

Route123_Text_2A025F: @ 82A025F
	.string "MT. PYRE…\n"
	.string "Where the spirits of POKéMON sleep…\l"
	.string "Will your POKéMON sleep?$"

Route123_Text_2A02A6: @ 82A02A6
	.string "Overflowing with vitality…$"

Route123_Text_2A02C1: @ 82A02C1
	.string "MT. PYRE…\n"
	.string "Where the spirits of POKéMON sleep…\p"
	.string "It must overflow with a power that\n"
	.string "soothes spirits…$"

Route123_Text_2A0323: @ 82A0323
	.string "I’ll turn your lights out while\n"
	.string "I rip through this tune!$"

Route123_Text_2A035C: @ 82A035C
	.string "Hey, hold it!\n"
	.string "I was still playing the intro!$"

Route123_Text_2A0389: @ 82A0389
	.string "You’re rock steady.\n"
	.string "I’d like to write a tune about you.$"

Route123_Text_2A03C1: @ 82A03C1
	.string "The next time, lend your ears to\n"
	.string "the full tune, will you?$"

Route123_Text_2A03FB: @ 82A03FB
	.string "Today’s the day I’m going to do it!\n"
	.string "I’ll turn out your lights before\l"
	.string "I finish singing my song!$"

Route123_Text_2A045A: @ 82A045A
	.string "Hey, hold it!\n"
	.string "I haven’t even hit the chorus!$"

Route123_Text_2A0487: @ 82A0487
	.string "I thought you’d be so enthralled\n"
	.string "by my tune, you’d lose.$"

Route123_Text_2A04C0: @ 82A04C0
	.string "This is my awesome BUG POKéMON!\n"
	.string "My big brother got it for me.$"

Route123_Text_2A04FE: @ 82A04FE
	.string "Waaaah!\n"
	.string "You meanie!$"

Route123_Text_2A0512: @ 82A0512
	.string "Don’t tell my brother I lost.\n"
	.string "You have to keep it a secret!$"

Route123_Text_2A054E: @ 82A054E
	.string "My confidence will get a boost by\n"
	.string "beating someone obviously strong!$"

Route123_Text_2A0592: @ 82A0592
	.string "There goes my confidence…$"

Route123_Text_2A05AC: @ 82A05AC
	.string "They say that you can’t judge a person\n"
	.string "by their appearance.\p"
	.string "But often, their looks don’t lie…$"

Route123_Text_2A060A: @ 82A060A
	.string "Hello, child!\n"
	.string "Can you spare some time?$"

Route123_Text_2A0631: @ 82A0631
	.string "Ah, a mighty capable child!\n"
	.string "Let me contribute to your allowance.$"

Route123_Text_2A0672: @ 82A0672
	.string "Contribute to your allowance?\n"
	.string "Wasn’t the prize money enough?$"

Route123_Text_2A06AF: @ 82A06AF
	.string "I have to tell you, BIRD POKéMON\n"
	.string "are my obsession!\p"
	.string "Birds are cool!\n"
	.string "They’re the best!$"

Route123_Text_2A0704: @ 82A0704
	.string "Even in defeat, BIRD POKéMON are cool!$"

Route123_Text_2A072B: @ 82A072B
	.string "I gather BIRD POKéMON feathers that\n"
	.string "scatter during battles.\p"
	.string "I’m going to make a hat with\n"
	.string "BIRD POKéMON feathers.$"

Route123_Text_2A079B: @ 82A079B
	.string "When there are no TRAINERS around,\n"
	.string "I let my POKéMON battle each other.\l"
	.string "I watch them.$"

Route123_Text_2A07F0: @ 82A07F0
	.string "I kind of like your POKéMON.$"

Route123_Text_2A080D: @ 82A080D
	.string "Hehe, I’m swiping your battling ideas!\n"
	.string "I think they’ll make me better.$"

Route123_Text_2A0854: @ 82A0854
	.string "I lay in ambush, and a TRAINER has\n"
	.string "landed in my trap!$"

Route123_Text_2A088A: @ 82A088A
	.string "If you don’t lose, how am I supposed\n"
	.string "to have fun playing ninja?$"

Route123_Text_2A08CA: @ 82A08CA
	.string "I’m going to ambush a weaker-looking\n"
	.string "TRAINER next time.$"

Route123_Text_2A0902: @ 82A0902
	.string "I just bought this parasol.\n"
	.string "My cuteness should be up by a third!$"

Route123_Text_2A0943: @ 82A0943
	.string "You’re better than me by about\n"
	.string "five times!$"

Route123_Text_2A096E: @ 82A096E
	.string "Using accessories effectively is\n"
	.string "the secret behind fashion appeal.$"

Route124_Text_2A09B1: @ 82A09B1
	.string "Hey, are you lost at sea?\p"
	.string "If you can beat my POKéMON,\n"
	.string "I can serve as your pilot.$"

Route124_Text_2A0A02: @ 82A0A02
	.string "I lost my bearings in battle!$"

Route124_Text_2A0A20: @ 82A0A20
	.string "Many people lose their bearings at sea.\p"
	.string "If you’re that sort, you should refer\n"
	.string "to the POKéNAV’s MAP.$"

Route124_Text_2A0A84: @ 82A0A84
	.string "Hm! You’re riding a POKéMON instead\n"
	.string "of swimming yourself…\p"
	.string "I am envious!$"

Route124_Text_2A0ACC: @ 82A0ACC
	.string "Oh!\n"
	.string "I can’t…$"

Route124_Text_2A0AD9: @ 82A0AD9
	.string "I’m getting chilled…\n"
	.string "I’ve been in the water too long…\p"
	.string "I wish I could ride a POKéMON like you…$"

Route124_Text_2A0B37: @ 82A0B37
	.string "If you just float in the sea like\n"
	.string "this, POKéMON come around to play.$"

Route124_Text_2A0B7C: @ 82A0B7C
	.string "Oh, darn.\n"
	.string "I’ve gone and lost.$"

Route124_Text_2A0B9A: @ 82A0B9A
	.string "While swimming, I noticed that some\n"
	.string "POKéMON attack, and some just watch.\p"
	.string "I guess POKéMON have personalities\n"
	.string "of their own.$"

Route124_Text_2A0C14: @ 82A0C14
	.string "It’s only on a whim, but maybe I’ll get\n"
	.string "you to register me in your POKéNAV.$"

Route124_Text_2A0C60: @ 82A0C60
	.string "If you just float in the sea like this,\n"
	.string "TRAINERS challenge you!$"

Route124_Text_2A0CA0: @ 82A0CA0
	.string "That’s strange…\n"
	.string "I lost again…$"

Route124_Text_2A0CBE: @ 82A0CBE
	.string "This has nothing to do with anything,\n"
	.string "but maybe I’ll visit the TRICK HOUSE.$"

Route124_Text_2A0D0A: @ 82A0D0A
	.string "I’m growing bored of swimming…\n"
	.string "How about a battle?$"

Route124_Text_2A0D3D: @ 82A0D3D
	.string "I had no idea that you were\n"
	.string "this strong!$"

Route124_Text_2A0D66: @ 82A0D66
	.string "All the effort you put in must have\n"
	.string "made you this strong.$"

Route124_Text_2A0DA0: @ 82A0DA0
	.string "Fufufufu… I dive deep underwater\n"
	.string "to go deep under cover.\l"
	.string "Plumbing the depths is where I excel!$"

Route124_Text_2A0DFF: @ 82A0DFF
	.string "Glub, glub, glub…\n"
	.string "I’m sinking…$"

Route124_Text_2A0E1E: @ 82A0E1E
	.string "I have it on good authority that\n"
	.string "there’s a DIVE spot around here.\p"
	.string "It gives me the urge to go deep\n"
	.string "again…$"

Route124_Text_2A0E87: @ 82A0E87
	.string "LILA: Sigh…\p"
	.string "Here I am in the sea, but who’s with me?\n"
	.string "My little brother!\p"
	.string "Let’s battle so I won’t have to dwell\n"
	.string "on that!$"

Route124_Text_2A0EFE: @ 82A0EFE
	.string "LILA: ROY! It’s your fault we lost!\n"
	.string "You’re in for it later!$"

Route124_Text_2A0F3A: @ 82A0F3A
	.string "LILA: Sigh…\p"
	.string "If only it wasn’t my little brother\n"
	.string "next to me, but a nice boyfriend…$"

Route124_Text_2A0F8C: @ 82A0F8C
	.string "LILA: You’re planning to battle us?\n"
	.string "Not unless you have two POKéMON.$"

Route124_Text_2A0FD1: @ 82A0FD1
	.string "ROY: My big sister is tough at POKéMON!\p"
	.string "Don’t cry when you lose!$"

Route124_Text_2A1012: @ 82A1012
	.string "ROY: Uh-oh…\n"
	.string "My big sister will chew me out…$"

Route124_Text_2A103E: @ 82A103E
	.string "ROY: My big sister is really scary\n"
	.string "when she gets angry.\p"
	.string "That’s why she doesn’t have a\n"
	.string "boyfriend.$"

Route124_Text_2A109F: @ 82A109F
	.string "ROY: Will you battle with us again?\n"
	.string "But take it easy next time, okay?$"

Route124_Text_2A10E5: @ 82A10E5
	.string "ROY: Did you want to battle us?\n"
	.string "Bring two POKéMON, then.$"

Route124_Text_2A111E: @ 82A111E
	.string "LILA: Sigh…\p"
	.string "Here I am in the sea, but who’s with me?\n"
	.string "My little brother!\p"
	.string "Oh, hi, it’s been a while. Let’s battle\n"
	.string "so I won’t have to dwell on things!$"

Route124_Text_2A11B2: @ 82A11B2
	.string "LILA: ROY!\n"
	.string "It’s your fault we lost again!\p"
	.string "We’re having a training session later!$"

Route124_Text_2A1203: @ 82A1203
	.string "LILA: Sigh…\p"
	.string "If I had a nice boyfriend, we’d beat\n"
	.string "anyone with lovely combinations…$"

Route124_Text_2A1255: @ 82A1255
	.string "LILA: You’re planning to battle us?\n"
	.string "Not unless you have two POKéMON.$"

Route124_Text_2A129A: @ 82A129A
	.string "ROY: If we lose, I’ll catch heck.\n"
	.string "I’m going to go totally all out!$"

Route124_Text_2A12DD: @ 82A12DD
	.string "ROY: Uh-oh…\n"
	.string "My big sister will chew me out again.$"

Route124_Text_2A130F: @ 82A130F
	.string "ROY: My big sister is really scary\n"
	.string "when she gets angry.\p"
	.string "She’s going to make me train really\n"
	.string "hard with POKéMON later…$"

Route124_Text_2A1384: @ 82A1384
	.string "ROY: Did you want to battle us?\n"
	.string "Bring two POKéMON, then.$"

Route124_Text_2A13BD: @ 82A13BD
	.string "Here I am swimming by my lonesome\n"
	.string "on this wide, beautiful sea.\p"
	.string "There’s no other word for it.\n"
	.string "This is pathetic!$"

Route124_Text_2A142C: @ 82A142C
	.string "I’m feeling blue.\n"
	.string "Blue as the sky…$"

Route124_Text_2A144F: @ 82A144F
	.string "I should chat up lady SWIMMERS\n"
	.string "and invite them on a long swim.$"

Route124_Text_2A148E: @ 82A148E
	.string "I’m not going to lose to some\n"
	.string "surfer TRAINER.$"

Route124_Text_2A14BC: @ 82A14BC
	.string "I’ve only got sweat in my eyes!\n"
	.string "I am not crying!$"

Route124_Text_2A14ED: @ 82A14ED
	.string "You can find pretty colored shards\n"
	.string "of things around here.$"

Route125_Text_2A1527: @ 82A1527
	.string "I heard you approaching, so I hung\n"
	.string "around for you!$"

Route125_Text_2A155A: @ 82A155A
	.string "I surrender!$"

Route125_Text_2A1567: @ 82A1567
	.string "Sound travels faster in water than\n"
	.string "it does through air.$"

Route125_Text_2A159F: @ 82A159F
	.string "Hey, there!\n"
	.string "Check out my sweet POKéMON!$"

Route125_Text_2A15C7: @ 82A15C7
	.string "I floundered…$"

Route125_Text_2A15D5: @ 82A15D5
	.string "I was blown away by HORSEA’s charm,\n"
	.string "so I started swimming, too.$"

Route125_Text_2A1615: @ 82A1615
	.string "I’m tired of swimming.\n"
	.string "Are you up for a battle with me?$"

Route125_Text_2A164D: @ 82A164D
	.string "You’re too much!$"

Route125_Text_2A165E: @ 82A165E
	.string "Whew…\n"
	.string "Which way is it to MOSSDEEP CITY?$"

Route125_Text_2A1686: @ 82A1686
	.string "How would you like to take on the\n"
	.string "WATER-type POKéMON I raised?$"

Route125_Text_2A16C5: @ 82A16C5
	.string "Lost it…$"

Route125_Text_2A16CE: @ 82A16CE
	.string "Your power… You’re the real deal.\n"
	.string "I’m amazed!$"

Route125_Text_2A16FC: @ 82A16FC
	.string "Ahoy! I’m a buff, tough SAILOR!\n"
	.string "I’ve braved the world’s seas!$"

Route125_Text_2A173A: @ 82A173A
	.string "Gwrroooar!\n"
	.string "I couldn’t win!$"

Route125_Text_2A1755: @ 82A1755
	.string "The tide ebbs and flows inside the\n"
	.string "SHOAL CAVE.\p"
	.string "By the way, it’s about six hours from\n"
	.string "high tide to low tide. Did you know?$"

Route125_Text_2A17CF: @ 82A17CF
	.string "Register me in your POKéNAV,\n"
	.string "and I’ll tell you something good.$"

Route125_Text_2A180E: @ 82A180E
	.string "It’s high time I get my payback\n"
	.string "from you! Come on, we’re battling!$"

Route125_Text_2A1851: @ 82A1851
	.string "I couldn’t win!\n"
	.string "I flat out couldn’t win!$"

Route125_Text_2A187A: @ 82A187A
	.string "The SHOAL CAVE…\p"
	.string "There are places you can and can’t\n"
	.string "get to depending on the rise and fall\l"
	.string "of the tide.\p"
	.string "By the way, it’s about six hours from\n"
	.string "high tide to low tide. Don’t forget!$"

Route125_Text_2A192B: @ 82A192B
	.string "KIM: A funny old man lives in the\n"
	.string "SHOAL CAVE. Someone told me.\l"
	.string "Are you going to see him, too?$"

Route125_Text_2A1989: @ 82A1989
	.string "KIM: I thought we would win.$"

Route125_Text_2A19A6: @ 82A19A6
	.string "KIM: A funny old man lives in the\n"
	.string "SHOAL CAVE, doesn’t he?\p"
	.string "Let’s go see him, IRIS!$"

Route125_Text_2A19F8: @ 82A19F8
	.string "KIM: No, no, no! You need two POKéMON,\n"
	.string "or it’s just no good!$"

Route125_Text_2A1A35: @ 82A1A35
	.string "IRIS: KIM, can you tell me what we’re\n"
	.string "looking for out here?$"

Route125_Text_2A1A71: @ 82A1A71
	.string "IRIS: Oh, we came sort of close.$"

Route125_Text_2A1A92: @ 82A1A92
	.string "IRIS: KIM, are we really going into\n"
	.string "the SHOAL CAVE?\l"
	.string "We’ll get all wet.$"

Route125_Text_2A1AD9: @ 82A1AD9
	.string "IRIS: Oh, we could never, ever do\n"
	.string "anything like a 2-on-1 battle.$"

Route125_Text_2A1B1A: @ 82A1B1A
	.string "Why would a BIRDKEEPER like me\n"
	.string "come out to the sea?$"

Route125_Text_2A1B4E: @ 82A1B4E
	.string "Okay.\n"
	.string "I’ll tell you why I’m here.$"

Route125_Text_2A1B70: @ 82A1B70
	.string "I put a message in a bottle and put\n"
	.string "it out to sea.\p"
	.string "I’m sure that a girl SWIMMER will\n"
	.string "find it!$"

Route125_Text_2A1BCE: @ 82A1BCE
	.string "Hey! Was it you throwing garbage\n"
	.string "into the sea?$"

Route125_Text_2A1BFD: @ 82A1BFD
	.string "Oh, you weren’t throwing trash into\n"
	.string "the sea.$"

Route125_Text_2A1C2A: @ 82A1C2A
	.string "I found an unsightly bottle bobbing\n"
	.string "in the waves earlier.\p"
	.string "It angers me that someone would\n"
	.string "pollute the sea!$"

Route126_Text_2A1C95: @ 82A1C95
	.string "Swimming is a full-body workout!\n"
	.string "You will get fit!$"

Route126_Text_2A1CC8: @ 82A1CC8
	.string "I admit it!\n"
	.string "You win!$"

Route126_Text_2A1CDD: @ 82A1CDD
	.string "Thanks to my daily swimming routine…\n"
	.string "Look! Feast your eyes on this physique!$"

Route126_Text_2A1D2A: @ 82A1D2A
	.string "This towering white mountain of rock\n"
	.string "is SOOTOPOLIS CITY.$"

Route126_Text_2A1D63: @ 82A1D63
	.string "I was done in?$"

Route126_Text_2A1D72: @ 82A1D72
	.string "I can’t find the entrance to\n"
	.string "SOOTOPOLIS. Where could it be?$"

Route126_Text_2A1DAE: @ 82A1DAE
	.string "Ufufufufu!\n"
	.string "I’m a mermaid!$"

Route126_Text_2A1DC8: @ 82A1DC8
	.string "My fantasy burst as if it were a bubble!\n"
	.string "Blub, blub, blub…$"

Route126_Text_2A1E03: @ 82A1E03
	.string "You thrashed me… I want to\n"
	.string "disappear in a wave of despair…$"

Route126_Text_2A1E3E: @ 82A1E3E
	.string "Hello, kiddo!\n"
	.string "Want a battle with me?$"

Route126_Text_2A1E63: @ 82A1E63
	.string "Oh, noooooh!$"

Route126_Text_2A1E70: @ 82A1E70
	.string "I love frolicking with POKéMON in\n"
	.string "the sea like this!$"

Route126_Text_2A1EA5: @ 82A1EA5
	.string "Check out this sculpted body!\n"
	.string "I’m more cut than a BLACK BELT!$"

Route126_Text_2A1EE3: @ 82A1EE3
	.string "Whoops! Too strong!\n"
	.string "Not bad! Not bad at all!$"

Route126_Text_2A1F10: @ 82A1F10
	.string "Losing to you stimulated my senses!\n"
	.string "I’ll train myself and POKéMON harder!$"

Route126_Text_2A1F5A: @ 82A1F5A
	.string "Yep, you’re not bad at all!\n"
	.string "I’d like to get to know you more!$"

Route126_Text_2A1F98: @ 82A1F98
	.string "Check out this beautiful body!\n"
	.string "I’m more shapely than a SWIMMER!$"

Route126_Text_2A1FD8: @ 82A1FD8
	.string "Whoops! Really too strong!\n"
	.string "Not bad! Not bad at all!$"

Route126_Text_2A200C: @ 82A200C
	.string "I’m going to train even harder!\n"
	.string "You’re a great motivator!\l"
	.string "You have to come back again!$"

Route126_Text_2A2063: @ 82A2063
	.string "I couldn’t even swim last year,\n"
	.string "but now I’m a decent SWIMMER.\p"
	.string "I think I’m capable of anything now.$"

Route126_Text_2A20C6: @ 82A20C6
	.string "Sheesh, getting greedy didn’t do\n"
	.string "a thing for me.$"

Route126_Text_2A20F7: @ 82A20F7
	.string "If you practice at something,\n"
	.string "you will get better at it.\p"
	.string "You’re young--don’t be afraid to\n"
	.string "try all sorts of things!$"

Route126_Text_2A216A: @ 82A216A
	.string "If seawater gets up your nose,\n"
	.string "doesn’t it feel terrible?$"

Route126_Text_2A21A3: @ 82A21A3
	.string "Ack! Why, you…\n"
	.string "Glub!$"

Route126_Text_2A21B8: @ 82A21B8
	.string "Ooh, I choked on some water!\n"
	.string "It’s bitter! It’s salty!!$"

Route126_Text_2A21EF: @ 82A21EF
	.string "I’m throwing my whole heart\n"
	.string "into this!$"

Route126_Text_2A2216: @ 82A2216
	.string "You had more heart!$"

Route126_Text_2A222A: @ 82A222A
	.string "I need to cool down now…\n"
	.string "I think I’ll go for a dive.$"

Route127_Text_2A225F: @ 82A225F
	.string "I can see it in your face.\n"
	.string "You want to challenge me.$"

Route127_Text_2A2294: @ 82A2294
	.string "Awawawawawa…$"

Route127_Text_2A22A1: @ 82A22A1
	.string "A well-played match leaves me feeling\n"
	.string "refreshed and serene.$"

Route127_Text_2A22DD: @ 82A22DD
	.string "Do you have a rival whom you just\n"
	.string "hate to lose against?$"

Route127_Text_2A2315: @ 82A2315
	.string "Arrrgh!\n"
	.string "I hate losing!$"

Route127_Text_2A232C: @ 82A232C
	.string "If you have a rival, don’t you get the\n"
	.string "feeling that you have to keep getting\l"
	.string "better?$"

Route127_Text_2A2381: @ 82A2381
	.string "Through fishing, I have attained a\n"
	.string "state of becalmed serenity…\p"
	.string "Please, allow me to demonstrate…$"

Route127_Text_2A23E1: @ 82A23E1
	.string "Though I have lost, my heart remains\n"
	.string "calm…$"

Route127_Text_2A240C: @ 82A240C
	.string "It matters not that I catch nothing.\n"
	.string "The line remains in the water…$"

Route127_Text_2A2450: @ 82A2450
	.string "Whoops! Don’t tell me I snagged\n"
	.string "a SURFING POKéMON?$"

Route127_Text_2A2483: @ 82A2483
	.string "I can’t keep up!$"

Route127_Text_2A2494: @ 82A2494
	.string "It’d be a handful if I hooked\n"
	.string "your tough POKéMON!$"

Route127_Text_2A24C6: @ 82A24C6
	.string "Well, hey! This is a match between\n"
	.string "a POKéMON fan and a fishing buff!$"

Route127_Text_2A250B: @ 82A250B
	.string "No! My line’s all tangled!\n"
	.string "The party’s over!$"

Route127_Text_2A2538: @ 82A2538
	.string "My fishing line’s doing a dance!\n"
	.string "The tangle tango! Hahaha, snarl!$"

Route127_Text_2A257A: @ 82A257A
	.string "BIRD POKéMON have excellent vision.\n"
	.string "They spot prey from great heights.$"

Route127_Text_2A25C1: @ 82A25C1
	.string "Whew… I give up.$"

Route127_Text_2A25D2: @ 82A25D2
	.string "There’re lots of diving spots in\n"
	.string "the sea around here.\p"
	.string "You can spot them easily from the sky\n"
	.string "because of their darker color.$"

Route127_Text_2A264D: @ 82A264D
	.string "Run in your bare feet.\n"
	.string "That will toughen up your soles!$"

Route127_Text_2A2685: @ 82A2685
	.string "Yowch!\n"
	.string "I got a pebble under a toenail!$"

Route127_Text_2A26AC: @ 82A26AC
	.string "Going barefoot feels great.\n"
	.string "But your RUNNING SHOES are cool, too.$"

Route127_Text_2A26EE: @ 82A26EE
	.string "This is what I do to people who beat me!\n"
	.string "I hope we can do this again.$"

Route127_Text_2A2734: @ 82A2734
	.string "I still run in my bare feet daily.\n"
	.string "My soles are tough!$"

Route127_Text_2A276B: @ 82A276B
	.string "Yowch!\n"
	.string "Pebbles dug into my arches!$"

Route127_Text_2A278E: @ 82A278E
	.string "Want to go barefoot for a while?\n"
	.string "So I can try your RUNNING SHOES?$"

Route127_Text_2A27D0: @ 82A27D0
	.string "We should have a slow and methodical\n"
	.string "match.$"

Route127_Text_2A27FC: @ 82A27FC
	.string "You didn’t give me the chance to\n"
	.string "do any strategizing.$"

Route127_Text_2A2832: @ 82A2832
	.string "When I’m surrounded by the blue sea\n"
	.string "and sky, it feels as if time slows down.$"

Route128_Text_2A287F: @ 82A287F
	.string "EVER GRANDE CITY is still a long ways\n"
	.string "away…$"

Route128_Text_2A28AB: @ 82A28AB
	.string "My first victory seems to be far\n"
	.string "away, too…$"

Route128_Text_2A28D7: @ 82A28D7
	.string "My whole life has been about losing,\n"
	.string "but I will never give up!$"

Route128_Text_2A2916: @ 82A2916
	.string "I know I’m not good now, but I think\n"
	.string "I can win eventually.\p"
	.string "Please register me in your POKéNAV.$"

Route128_Text_2A2975: @ 82A2975
	.string "I’m still feeling good. I’ll keep on\n"
	.string "swimming to EVER GRANDE CITY.$"

Route128_Text_2A29B8: @ 82A29B8
	.string "I’ve yet to taste my first victory…$"

Route128_Text_2A29DC: @ 82A29DC
	.string "I’ll eventually reach EVER GRANDE CITY\n"
	.string "where I can eventually win…$"

Route128_Text_2A2A1F: @ 82A2A1F
	.string "You have to swim, cycle, and then run\n"
	.string "a marathon in a triathlon.\p"
	.string "It’s a grueling race that consists\n"
	.string "of three events.$"

Route128_Text_2A2A94: @ 82A2A94
	.string "A POKéMON battle is grueling, too…$"

Route128_Text_2A2AB7: @ 82A2AB7
	.string "I have to ride a BIKE next, but…\n"
	.string "I’m about to throw in the towel…$"

Route128_Text_2A2AF9: @ 82A2AF9
	.string "Well, I may as well make the best\n"
	.string "of this. I’d like a rematch sometime.$"

Route128_Text_2A2B41: @ 82A2B41
	.string "A triathlon is long. But I guess the\n"
	.string "road to become the POKéMON CHAMPION\l"
	.string "is also a long and grueling one.$"

Route128_Text_2A2BAB: @ 82A2BAB
	.string "A POKéMON battle really is harsh\n"
	.string "and unforgiving…$"

Route128_Text_2A2BDD: @ 82A2BDD
	.string "You should give serious thought to\n"
	.string "challenges on VICTORY ROAD.$"

Route128_Text_2A2C1C: @ 82A2C1C
	.string "We’ve been working so hard to mount\n"
	.string "a POKéMON LEAGUE challenge…\p"
	.string "We can’t afford to lose now!$"

Route128_Text_2A2C79: @ 82A2C79
	.string "Oh!\n"
	.string "How could this happen?!$"

Route128_Text_2A2C95: @ 82A2C95
	.string "After all I’ve done to get here,\n"
	.string "I won’t give up after one setback.$"

Route128_Text_2A2CD9: @ 82A2CD9
	.string "There is no stronger TRAINER than I!$"

Route128_Text_2A2CFE: @ 82A2CFE
	.string "This can’t be!$"

Route128_Text_2A2D0D: @ 82A2D0D
	.string "There probably is no stronger TRAINER\n"
	.string "than you!$"

Route128_Text_2A2D3D: @ 82A2D3D
	.string "I want to visit EVER GRANDE, so I\n"
	.string "caught myself a POKéMON that knows\l"
	.string "the move WATERFALL to crest the falls.$"

Route128_Text_2A2DA9: @ 82A2DA9
	.string "I’m crestfallen!$"

Route128_Text_2A2DBA: @ 82A2DBA
	.string "Awww, phooey!\p"
	.string "My POKéMON knows WATERFALL, but\n"
	.string "I don’t have the SOOTOPOLIS GYM BADGE!$"

Route128_Text_2A2E0F: @ 82A2E0F
	.string "You’re looking awfully tough.\n"
	.string "I wonder if I can win?$"

Route128_Text_2A2E44: @ 82A2E44
	.string "Ouch!\n"
	.string "I guess it was impossible to win.$"

Route128_Text_2A2E6C: @ 82A2E6C
	.string "There are tough TRAINERS galore\n"
	.string "around EVER GRANDE.\p"
	.string "Do you think I may be out\n"
	.string "of my league?$"

Route128_Text_2A2EC8: @ 82A2EC8
	.string "The sunlight seems to be more harsh\n"
	.string "in this area.$"

Route128_Text_2A2EFA: @ 82A2EFA
	.string "I couldn’t see very well because of\n"
	.string "the sun’s glare.$"

Route128_Text_2A2F2F: @ 82A2F2F
	.string "I should go back soon.\n"
	.string "I need to reapply my sunscreen.$"

Route129_Text_2A2F66: @ 82A2F66
	.string "This is my first triathlon.\n"
	.string "I’m all tense and nervous!$"

Route129_Text_2A2F9D: @ 82A2F9D
	.string "Wroooaaar!\n"
	.string "I failed to win!$"

Route129_Text_2A2FB9: @ 82A2FB9
	.string "If I’m all tensed up, I won’t be able to\n"
	.string "give it my all.$"

Route129_Text_2A2FF2: @ 82A2FF2
	.string "I’m in the middle of a triathlon,\n"
	.string "but, sure, why don’t we battle?$"

Route129_Text_2A3034: @ 82A3034
	.string "I was sure I’d win!$"

Route129_Text_2A3048: @ 82A3048
	.string "Do you know what’s the greatest thing\n"
	.string "about triathlons?\p"
	.string "Testing the limits of your own\n"
	.string "strength and endurance against\l"
	.string "Mother Nature!$"

Route129_Text_2A30CD: @ 82A30CD
	.string "Say hey, hey!\n"
	.string "Let’s get on with it!$"

Route129_Text_2A30F1: @ 82A30F1
	.string "Beat, I’m beaten.\n"
	.string "That’s it, done!$"

Route129_Text_2A3114: @ 82A3114
	.string "There’s nothing for a loser.\n"
	.string "Time for me to beat it home.$"

Route129_Text_2A314E: @ 82A314E
	.string "What’s the hurry?\n"
	.string "Let’s take it slow and easy.$"

Route129_Text_2A317D: @ 82A317D
	.string "Oh, my.\n"
	.string "I wanted to relax a little more…$"

Route129_Text_2A31A6: @ 82A31A6
	.string "Don’t you hate making mistakes when\n"
	.string "you’re in a rush?\p"
	.string "That’s why I try to take things\n"
	.string "slowly.$"

Route129_Text_2A3204: @ 82A3204
	.string "Surfing isn’t as easy as it seems,\n"
	.string "isn’t that right?$"

Route129_Text_2A3239: @ 82A3239
	.string "Winning sure isn’t easy.$"

Route129_Text_2A3252: @ 82A3252
	.string "You have your sights on the POKéMON\n"
	.string "LEAGUE? Keep at it!$"

Route130_Text_2A328A: @ 82A328A
	.string "What a surprise! I didn’t expect to\n"
	.string "see a TRAINER out in the sea.\p"
	.string "I think we should battle!$"

Route130_Text_2A32E6: @ 82A32E6
	.string "This kid’s awfully tough…$"

Route130_Text_2A3300: @ 82A3300
	.string "Your eyes have that look of someone\n"
	.string "who’s experienced harsh challenges\l"
	.string "and won. It suits you well!$"

Route130_Text_2A3363: @ 82A3363
	.string "In the deep blue sea,\n"
	.string "my shattered blue heart finds\l"
	.string "comfort among waves.$"

Route130_Text_2A33AC: @ 82A33AC
	.string "Like the vast blue sea,\n"
	.string "the world of POKéMON spans\l"
	.string "depths beyond belief.$"

Route130_Text_2A33F5: @ 82A33F5
	.string "The world’s children dream\n"
	.string "of one day becoming\l"
	.string "the POKéMON CHAMPION.$"

Route130_Text_2A343A: @ 82A343A
	.string "Floating on the open sea like this…\n"
	.string "It’s peaceful.$"

Route130_Text_2A346D: @ 82A346D
	.string "I needed to be a little less peaceful!$"

Route130_Text_2A3494: @ 82A3494
	.string "Swimming and battling like this…\n"
	.string "I’m one happy guy…$"

Route131_Text_2A34C8: @ 82A34C8
	.string "The sea is teeming with POKéMON.\n"
	.string "It’s not easy swimming, I tell you.$"

Route131_Text_2A350D: @ 82A350D
	.string "POKéMON raised by TRAINERS are\n"
	.string "seriously tough…$"

Route131_Text_2A353D: @ 82A353D
	.string "Gasp… Gasp…\n"
	.string "I’m wiped out…\p"
	.string "The going’s easy. It’s the leaving\n"
	.string "that’s the hard part.\p"
	.string "Will I have any energy left to make\n"
	.string "the return trip?$"

Route131_Text_2A35C6: @ 82A35C6
	.string "The sea… The sea… The sea…\n"
	.string "The sea as far as these eyes can see!\l"
	.string "I’m sick and tired of the sea!$"

Route131_Text_2A3626: @ 82A3626
	.string "Bleah!$"

Route131_Text_2A362D: @ 82A362D
	.string "Bored I am by the sea, but swim I must.\p"
	.string "I’m a born swimmer!\n"
	.string "That’s what I am.$"

Route131_Text_2A367B: @ 82A367B
	.string "Hi, sweetie, wait!\n"
	.string "We should battle, you and I!$"

Route131_Text_2A36AB: @ 82A36AB
	.string "You’re tough in spite of the way\n"
	.string "you look!$"

Route131_Text_2A36D6: @ 82A36D6
	.string "Did you see a guy over there who whines\n"
	.string "that he’s bored of the sea?\p"
	.string "That’s all talk.\n"
	.string "He’s hopelessly in love with the sea!$"

Route131_Text_2A3751: @ 82A3751
	.string "Why do men love bathing suits so much?\p"
	.string "They all ogle me!$"

Route131_Text_2A378A: @ 82A378A
	.string "I’m out of my depth!$"

Route131_Text_2A379F: @ 82A379F
	.string "Maybe it’s not my bathing suit that\n"
	.string "makes men look. It must be my beauty!$"

Route131_Text_2A37E9: @ 82A37E9
	.string "RELI: We’ll work together as siblings\n"
	.string "to take you on!$"

Route131_Text_2A381F: @ 82A381F
	.string "RELI: We couldn’t win even though we\n"
	.string "worked together…$"

Route131_Text_2A3855: @ 82A3855
	.string "RELI: The people of PACIFIDLOG are\n"
	.string "together with the sea and POKéMON from\l"
	.string "the time they are born.$"

Route131_Text_2A38B7: @ 82A38B7
	.string "RELI: You don’t have two POKéMON?\n"
	.string "We can’t enjoy a battle, then.$"

Route131_Text_2A38F8: @ 82A38F8
	.string "IAN: I’m doing my best together with\n"
	.string "my sis!$"

Route131_Text_2A3925: @ 82A3925
	.string "IAN: I did my best with my sis,\n"
	.string "but we still couldn’t win…$"

Route131_Text_2A3960: @ 82A3960
	.string "IAN: You know how PACIFIDLOG is\n"
	.string "a floating town?\p"
	.string "So, wherever there is the sea,\n"
	.string "that’s a part of PACIFIDLOG!$"

Route131_Text_2A39CD: @ 82A39CD
	.string "IAN: If you have two POKéMON,\n"
	.string "we’ll take you on!$"

Route131_Text_2A39FE: @ 82A39FE
	.string "If you can beat me, I’ll give you some\n"
	.string "great information!$"

Route131_Text_2A3A38: @ 82A3A38
	.string "Oh?\n"
	.string "Did I lose?$"

Route131_Text_2A3A48: @ 82A3A48
	.string "There is an odd place nearby.\n"
	.string "There’s a huge tower there.\l"
	.string "Why don’t you go take a look?$"

Route131_Text_2A3AA0: @ 82A3AA0
	.string "The people of PACIFIDLOG are\n"
	.string "a peaceful bunch.\p"
	.string "They never get angry.\n"
	.string "That goes for me, too.$"

Route131_Text_2A3AFC: @ 82A3AFC
	.string "Oops!$"

Route131_Text_2A3B02: @ 82A3B02
	.string "Tch! …Oh, wait.\n"
	.string "I’m not angry. Honestly!\p"
	.string "But, boy, you’re strong!\n"
	.string "Hahaha!$"

Route132_Text_2A3B4C: @ 82A3B4C
	.string "I used to catch colds all the time as\n"
	.string "a kid, but I became totally fit after\l"
	.string "I started swimming.$"

Route132_Text_2A3BAC: @ 82A3BAC
	.string "I crave more power…$"

Route132_Text_2A3BC0: @ 82A3BC0
	.string "TRAINERS travel the fields and\n"
	.string "mountains, so they must be fit, too.$"

Route132_Text_2A3C04: @ 82A3C04
	.string "I try not to swim where the currents\n"
	.string "are too strong.$"

Route132_Text_2A3C39: @ 82A3C39
	.string "Oh, please, no!$"

Route132_Text_2A3C49: @ 82A3C49
	.string "If I get swept away, I’ll lose all my\n"
	.string "sense of place…$"

Route132_Text_2A3C7F: @ 82A3C7F
	.string "Win or lose, you’ll never know until\n"
	.string "you try!$"

Route132_Text_2A3CAD: @ 82A3CAD
	.string "Waah!\n"
	.string "I sank in defeat!$"

Route132_Text_2A3CC5: @ 82A3CC5
	.string "I never battle when I know I’ll win.\n"
	.string "I like to battle at the razor’s edge of\l"
	.string "victory and defeat!$"

Route132_Text_2A3D26: @ 82A3D26
	.string "I contemplate POKéMON 24 hours a day.\n"
	.string "How could you possibly beat me?$"

Route132_Text_2A3D6C: @ 82A3D6C
	.string "I lose.\n"
	.string "I will concede defeat.$"

Route132_Text_2A3D8B: @ 82A3D8B
	.string "Urggh…\n"
	.string "You’re a POKéMON fanatic, aren’t you?\p"
	.string "You must contemplate POKéMON 24 hours\n"
	.string "a day, don’t you?$"

Route132_Text_2A3DF0: @ 82A3DF0
	.string "I’m always with my husband,\n"
	.string "but I can win even without him.$"

Route132_Text_2A3E2C: @ 82A3E2C
	.string "Oh, I guess I wasn’t good enough.$"

Route132_Text_2A3E4E: @ 82A3E4E
	.string "That young man over there looks just\n"
	.string "like my husband when he was young.\p"
	.string "He’s making me blush!$"

Route132_Text_2A3EAC: @ 82A3EAC
	.string "Someone’s been watching me intently.\n"
	.string "Was it you?$"

Route132_Text_2A3EDD: @ 82A3EDD
	.string "Wow!\n"
	.string "That’s pretty strong, all right!$"

Route132_Text_2A3F03: @ 82A3F03
	.string "I can’t shake this feeling that\n"
	.string "someone’s watching me.\p"
	.string "I can’t concentrate!$"

Route132_Text_2A3F4F: @ 82A3F4F
	.string "Now where could my wife have gone?\n"
	.string "I’m always with her.\l"
	.string "I wonder if I can win on my own.$"

Route132_Text_2A3FA8: @ 82A3FA8
	.string "Ah, I see that I couldn’t manage\n"
	.string "to win on my own after all.$"

Route132_Text_2A3FE5: @ 82A3FE5
	.string "My wife must be looking for me.\n"
	.string "I’d best go find her right away.$"

Route132_Text_2A4026: @ 82A4026
	.string "I liked training here by myself.\n"
	.string "It’s awful that all these people came!$"

Route132_Text_2A406E: @ 82A406E
	.string "Okay! I won’t complain about other\n"
	.string "people being here.$"

Route132_Text_2A40A4: @ 82A40A4
	.string "I suppose I can partner up with that\n"
	.string "old man and challenge that other team.$"

Route133_Text_2A40F0: @ 82A40F0
	.string "Did the currents carry you here, too?\n"
	.string "This must have been fated.\l"
	.string "Let’s battle!$"

Route133_Text_2A413F: @ 82A413F
	.string "Strong!\n"
	.string "Too much so!$"

Route133_Text_2A4154: @ 82A4154
	.string "It’s just my luck that a tough TRAINER\n"
	.string "like you would drift here…\l"
	.string "I must be cursed…$"

Route133_Text_2A41A8: @ 82A41A8
	.string "I’ve led a life of woe and misery…\n"
	.string "I’ve been cast away, and this is where\l"
	.string "I’ve drifted…$"

Route133_Text_2A4200: @ 82A4200
	.string "Another loss…$"

Route133_Text_2A420E: @ 82A420E
	.string "A life adrift…\n"
	.string "I don’t want it anymore!$"

Route133_Text_2A4236: @ 82A4236
	.string "Welcome!\n"
	.string "I’ve been expecting you!$"

Route133_Text_2A4258: @ 82A4258
	.string "No! Please!$"

Route133_Text_2A4264: @ 82A4264
	.string "A strong child TRAINER…\n"
	.string "That’s so annoying!$"

Route133_Text_2A4290: @ 82A4290
	.string "I want to win like everyone else, but I\n"
	.string "won’t raise POKéMON like everyone else.$"

Route133_Text_2A42E0: @ 82A42E0
	.string "Darn it!\n"
	.string "My way is still too slack!$"

Route133_Text_2A4304: @ 82A4304
	.string "It’s way more fun to do things the way\n"
	.string "I want than to be like everybody else.\l"
	.string "I mean, that’s obvious!$"

Route133_Text_2A436A: @ 82A436A
	.string "I came all the way out here with my\n"
	.string "BIRD POKéMON.$"

Route133_Text_2A439C: @ 82A439C
	.string "You…\n"
	.string "You’re stunningly cool!$"

Route133_Text_2A43B9: @ 82A43B9
	.string "I’d like to go back to FORTREE,\n"
	.string "but I’ve grown to like this place, too.$"

Route133_Text_2A4401: @ 82A4401
	.string "I must have battled thousands\n"
	.string "of times. I’ve lost count.$"

Route133_Text_2A443A: @ 82A443A
	.string "I may have lost thousands of times,\n"
	.string "but a loss still stings.$"

Route133_Text_2A4477: @ 82A4477
	.string "Keep at this, youngster. So you can\n"
	.string "become like my husband and me.$"

Route133_Text_2A44BA: @ 82A44BA
	.string "Young people are too happy to go with\n"
	.string "the flow. They’re without direction.$"

Route133_Text_2A4505: @ 82A4505
	.string "You have a firm sense of purpose.$"

Route133_Text_2A4527: @ 82A4527
	.string "Don’t let others lead you astray.\n"
	.string "Don’t lose direction as you grow older.$"

Route134_Text_2A4571: @ 82A4571
	.string "Even those POKéMON that can swim are\n"
	.string "carried along by the rapid currents.$"

Route134_Text_2A45BB: @ 82A45BB
	.string "Aiyeeeeh!$"

Route134_Text_2A45C5: @ 82A45C5
	.string "I think POKéMON enjoy the fast-running\n"
	.string "currents around these parts.$"

Route134_Text_2A4609: @ 82A4609
	.string "My LUVDISC are looking for a fun\n"
	.string "match. Will you join us?$"

Route134_Text_2A4643: @ 82A4643
	.string "Oopsie!$"

Route134_Text_2A464B: @ 82A464B
	.string "There’s a collector who’s after\n"
	.string "the SCALES of LUVDISC.$"

Route134_Text_2A4682: @ 82A4682
	.string "Okeydokey! That’s enough rest, gang!\n"
	.string "It’s time for a match!$"

Route134_Text_2A46BE: @ 82A46BE
	.string "Tuckered out again…$"

Route134_Text_2A46D2: @ 82A46D2
	.string "My BIRD POKéMON get tired quickly after\n"
	.string "a long flight…$"

Route134_Text_2A4709: @ 82A4709
	.string "You’re a POKéMON TRAINER.\n"
	.string "No need for words. We battle now.$"

Route134_Text_2A4745: @ 82A4745
	.string "… … … … … …\n"
	.string "… … … … … …$"

Route134_Text_2A475D: @ 82A475D
	.string "It was I who challenged you, and yet\n"
	.string "I lost. I am deeply shamed…$"

Route134_Text_2A479E: @ 82A479E
	.string "The savage tide in this area serves to\n"
	.string "make us stronger than ever.$"

Route134_Text_2A47E1: @ 82A47E1
	.string "I willingly concede defeat.$"

Route134_Text_2A47FD: @ 82A47FD
	.string "We will return for more training at\n"
	.string "METEOR FALLS.\p"
	.string "If you’d like, you should go, too.\n"
	.string "It will definitely toughen you up!$"

Route134_Text_2A4875: @ 82A4875
	.string "O-our boat!\n"
	.string "The tide carried it away!$"

Route134_Text_2A489B: @ 82A489B
	.string "Awawawawah!\n"
	.string "Please, stop! Please!$"

Route134_Text_2A48BD: @ 82A48BD
	.string "If we can’t SURF, how are we supposed\n"
	.string "to get home?\p"
	.string "Actually, I know a fainted POKéMON\n"
	.string "can still SURF, but it feels wrong.$"

Route134_Text_2A4937: @ 82A4937
	.string "Can your POKéMON dodge our\n"
	.string "lightning-quick attacks?$"

Route134_Text_2A496B: @ 82A496B
	.string "I never knew such a technique existed!\n"
	.string "You’ve defeated us thoroughly.$"

Route134_Text_2A49B1: @ 82A49B1
	.string "I haven’t lost my passion for speed.\n"
	.string "I will try harder.$"

Route134_Text_2A49E9: @ 82A49E9
	.string "My POKéMON can’t be taken down\n"
	.string "easily!$"

Route134_Text_2A4A10: @ 82A4A10
	.string "You’re kidding!\n"
	.string "Explain how I lost!$"

Route134_Text_2A4A34: @ 82A4A34
	.string "Haha!\n"
	.string "You won, all right!\p"
	.string "I’ll work my way back up by taking on\n"
	.string "TRAINERS I happen to meet!$"

Route134_Text_2A4A8F: @ 82A4A8F
	.string "Listen, have you seen another SAILOR\n"
	.string "around here?$"

Route134_Text_2A4AC1: @ 82A4AC1
	.string "Now, that’s something!$"

Route134_Text_2A4AD8: @ 82A4AD8
	.string "Our boat drifted out to sea.\p"
	.string "My buddy’s a timid fellow, so I’m\n"
	.string "worried about him.$"

gUnknown_082A4B2A:: @ 82A4B2A
	.incbin "baserom.gba", 0x2a4b2a, 0x22

gUnknown_082A4B4C:: @ 82A4B4C
	.incbin "baserom.gba", 0x2a4b4c, 0x23

gUnknown_082A4B6F:: @ 82A4B6F
	.incbin "baserom.gba", 0x2a4b6f, 0x1b

gUnknown_082A4B8A:: @ 82A4B8A
	.incbin "baserom.gba", 0x2a4b8a, 0x11

gUnknown_082A4B9B:: @ 82A4B9B
	.incbin "baserom.gba", 0x2a4b9b, 0x11

gUnknown_082A4BAC:: @ 82A4BAC

	.incbin "baserom.gba", 0x2a4bac, 0x166

Route121_SafariZoneEntrance_Text_2A4D12: @ 82A4D12
	.string "Welcome to the SAFARI ZONE!\p"
	.string "Here, you may witness many kinds of\n"
	.string "POKéMON rarely seen in HOENN.\p"
	.string "And, you’ll see them in their wild,\n"
	.string "untamed state in natural habitats.\p"
	.string "What’s more, we’ve thrown open the\n"
	.string "gates to POKéMON TRAINERS.\p"
	.string "You’re encouraged to catch POKéMON\n"
	.string "for keeps!\p"
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4E46: @ 82A4E46
	.string "Welcome to the SAFARI ZONE!\n"
	.string "Is it your first time here?$"

Route121_SafariZoneEntrance_Text_2A4E7E: @ 82A4E7E
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4EA1: @ 82A4EA1
	.string "When you enter the SAFARI ZONE, you\n"
	.string "start with 30 SAFARI BALLS for\l"
	.string "catching POKéMON.\p"
	.string "The SAFARI Game is over when you run\n"
	.string "out of SAFARI BALLS, or when you’ve\l"
	.string "walked 500 steps.\p"
	.string "Come in and enjoy the SAFARI ZONE!$"

Route121_SafariZoneEntrance_Text_2A4F74: @ 82A4F74
	.string "Welcome to the SAFARI ZONE!\p"
	.string "All you can catch for just ¥500!\n"
	.string "Would you like to play a SAFARI Game?$"

Route121_SafariZoneEntrance_Text_2A4FD7: @ 82A4FD7
	.string "Okay.\n"
	.string "Please play another time!$"

Route121_SafariZoneEntrance_Text_2A4FF7: @ 82A4FF7
	.string "You don’t have enough money.\n"
	.string "Sorry.$"

Route121_SafariZoneEntrance_Text_2A501B: @ 82A501B
	.string "That will be ¥500, please.$"

Route121_SafariZoneEntrance_Text_2A5036: @ 82A5036
	.string "Here are your SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_2A5052: @ 82A5052
	.string "{PLAYER} received 30 SAFARI BALLS.$"

Route121_SafariZoneEntrance_Text_2A506F: @ 82A506F
	.string "We’ll let you know when your game\n"
	.string "is over.\p"
	.string "So, until then, enjoy yourself, please!\n"
	.string "Off you go on your wild excursion!$"

Route121_SafariZoneEntrance_Text_2A50E5: @ 82A50E5
	.string "Excuse me!\n"
	.string "Your PC BOX is full.$"

Route121_SafariZoneEntrance_Text_2A5105: @ 82A5105
	.string "Excuse me!\n"
	.string "You seem to be without a {POKEBLOCK} CASE.\p"
	.string "Your SAFARI Game will be much more\n"
	.string "fruitful if you use {POKEBLOCK}S.\p"
	.string "Please come back with a {POKEBLOCK} CASE.\p"
	.string "You may obtain a {POKEBLOCK} CASE from\n"
	.string "the LILYCOVE CONTEST HALL.$"

SafariZone_South_Text_2A51D4: @ 82A51D4
	.string "You still have time left. Would you like\n"
	.string "to exit the SAFARI ZONE now?$"

SafariZone_South_Text_2A521A: @ 82A521A
	.string "Please enjoy the rest of your wild\n"
	.string "adventure!$"

SafariZone_South_Text_2A5248: @ 82A5248
	.string "Okay.\p"
	.string "I’ll take back your remaining SAFARI\n"
	.string "BALLS.\p"
	.string "Thank you for playing.\n"
	.string "We hope to see you again.$"

SafariZone_South_Text_2A52AB: @ 82A52AB
	.string "Good luck!\p"
	.string "If you need anything, don’t hesitate\n"
	.string "to tell me, please!$"

SafariZone_South_Text_2A52EF: @ 82A52EF
	.string "Did you know?\p"
	.string "If you put a {POKEBLOCK} in that square box,\n"
	.string "POKéMON gather around.$"

SafariZone_South_Text_2A533B: @ 82A533B
	.string "I want to keep going deeper, but I\n"
	.string "forgot to bring a BIKE.\p"
	.string "Something tells me that rare POKéMON\n"
	.string "live in the outlying areas.$"

SafariZone_Southwest_Text_2A53B7: @ 82A53B7
	.string "Sometimes, when I toss a {POKEBLOCK} at \n"
	.string "POKéMON, it gets ignored.\p"
	.string "Do POKéMON have likes and dislikes\n"
	.string "about what they eat?$"

SafariZone_Northwest_Text_2A542C: @ 82A542C
	.string "Gasp… Gasp…\n"
	.string "I…made it out here…but…\p"
	.string "I’m exhausted… I don’t have the\n"
	.string "energy to catch POKéMON…$"

SafariZone_North_Text_2A5489: @ 82A5489
	.string "I’m on a mission to find WATER POKéMON\n"
	.string "you don’t see in HOENN.\p"
	.string "Do you have any idea where the lake is?$"

SafariZone_North_Text_2A54F0: @ 82A54F0
	.string "I’m going to catch a lot of rare POKéMON\n"
	.string "here and trade them with my friends!$"

SafariZone_South_Text_2A553E: @ 82A553E
	.string "I put a {POKEBLOCK} on the {POKEBLOCK} FEEDER.\n"
	.string "But it seems to have disappeared.\p"
	.string "I guess POKéMON must have eaten it\n"
	.string "without me noticing.$"

Route121_SafariZoneEntrance_Text_2A55BB: @ 82A55BB
	.string "SAFARI ZONE TRAINER TIP!\p"
	.string "Throw {POKEBLOCK}S at wild POKéMON to make\n"
	.string "them less likely to flee.$"

SafariZone_Southwest_Text_2A5613: @ 82A5613
	.string "“Relieve your tired feet.”\n"
	.string "REST HOUSE$"

SafariZone_RestHouse_Text_2A5639: @ 82A5639
	.string "I don’t have any {POKEBLOCK}S, but I caught\n"
	.string "a good number of POKéMON.\p"
	.string "You can improve your chances of making\n"
	.string "a catch by getting closer to them\l"
	.string "before throwing a SAFARI BALL.$"

SafariZone_RestHouse_Text_2A56E1: @ 82A56E1
	.string "If you use {POKEBLOCK}S, wild POKéMON won’t\n"
	.string "be so quick to run away.\p"
	.string "It’s not much use to give {POKEBLOCK}S to\n"
	.string "POKéMON that don’t flee easily.$"

SafariZone_RestHouse_Text_2A5764: @ 82A5764
	.string "If you put a {POKEBLOCK} on the FEEDER,\n"
	.string "POKéMON are attracted to it.\p"
	.string "I think POKéMON with the same sort of\n"
	.string "nature are drawn by a certain {POKEBLOCK}.$"

SafariZone_South_Text_2A57EE: @ 82A57EE
	.string "This area is still under construction.\n"
	.string "It’s off-limits, sorry!$"

SafariZone_Southeast_Text_2A582D: @ 82A582D
	.string "The SAFARI ZONE’s expansion project\n"
	.string "is finished now.\p"
	.string "We hope you will enjoy the new area.$"

SafariZone_South_Text_2A5887: @ 82A5887
	.string "This area is still under construction.\n"
	.string "It’s off-limits, sorry!$"

SafariZone_Southeast_Text_2A58C6: @ 82A58C6
	.string "Wow! Whee! I haven’t seen any of\n"
	.string "these POKéMON before!$"

SafariZone_Southeast_Text_2A58FD: @ 82A58FD
	.string "The POKéMON in this area are all\n"
	.string "new to me.\p"
	.string "And I’m allowed to catch these rare\n"
	.string "POKéMON! Too cool!$"

SafariZone_Southeast_Text_2A5960: @ 82A5960
	.string "The POKéMON around here seem to be\n"
	.string "from somewhere other than HOENN.$"

SafariZone_Northeast_Text_2A59A4: @ 82A59A4
	.string "I only have a couple SAFARI BALLS left.\p"
	.string "I’m having a hard time trying to\n"
	.string "decide what I should catch.$"

SafariZone_Northeast_Text_2A5A09: @ 82A5A09
	.string "I heard that you can see PIKACHU here.\n"
	.string "Where might one be?$"

SafariZone_Northeast_Text_2A5A44: @ 82A5A44
	.string "Oh, boo!\n"
	.string "I can’t seem to catch anything!\p"
	.string "I’ll end up wasting the admission\n"
	.string "price if I don’t catch something!$"

MauvilleCity_GameCorner_EventScript_2A5AB1:: @ 82A5AB1
	checkitem ITEM_COIN_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 0
	getpricereduction 2
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5ADF:: @ 82A5ADF
	checkitem ITEM_COIN_CASE, 1
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_210456
	setvar VAR_0x8004, 1
	getpricereduction 2
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_GameCorner_EventScript_2A5B0D
	addvar VAR_0x8004, 128
	goto MauvilleCity_GameCorner_EventScript_2A5B0D
	end

MauvilleCity_GameCorner_EventScript_2A5B0D:: @ 82A5B0D
	special sub_8142BC8
	waitstate
	end

gUnknown_082A5B12:: @ 82A5B12
	.incbin "baserom.gba", 0x2a5b12, 0x3c

gUnknown_082A5B4E:: @ 82A5B4E
	.incbin "baserom.gba", 0x2a5b4e, 0x1d

gUnknown_082A5B6B:: @ 82A5B6B
	.incbin "baserom.gba", 0x2a5b6b, 0x1e

gUnknown_082A5B89:: @ 82A5B89
	.incbin "baserom.gba", 0x2a5b89, 0x42

gUnknown_082A5BCB:: @ 82A5BCB
	.incbin "baserom.gba", 0x2a5bcb, 0xc

gUnknown_082A5BD7:: @ 82A5BD7
	.incbin "baserom.gba", 0x2a5bd7, 0x9

gUnknown_082A5BE0:: @ 82A5BE0
	.incbin "baserom.gba", 0x2a5be0, 0xf

gUnknown_082A5BEF:: @ 82A5BEF
	.incbin "baserom.gba", 0x2a5bef, 0x15

gUnknown_082A5C04:: @ 82A5C04
	.incbin "baserom.gba", 0x2a5c04, 0xf

gUnknown_082A5C13:: @ 82A5C13
	.incbin "baserom.gba", 0x2a5c13, 0xe

gUnknown_082A5C21:: @ 82A5C21
	.incbin "baserom.gba", 0x2a5c21, 0x40

gUnknown_082A5C61:: @ 82A5C61
	.incbin "baserom.gba", 0x2a5c61, 0x3b

gUnknown_082A5C9C:: @ 82A5C9C

gUnknown_082A5C9C: @ 82A5C9C
	.string "PROF. BIRCH: Ah, {PLAYER}{KUN}!\p"
	.string "Are you curious about how your\n"
	.string "POKéDEX is coming along?$"

Route101_Text_2A5CEB: @ 82A5CEB
	.string "Hm? Oh, you haven’t caught enough\n"
	.string "POKéMON to make it worthwhile.$"

gUnknown_082A5D2C:: @ 82A5D2C

gUnknown_082A5D2C: @ 82A5D2C
	.string "Hmhm…\p"
	.string "So, you’ve seen {STR_VAR_1} POKéMON,\n"
	.string "and you’ve caught {STR_VAR_2} POKéMON…$"

gUnknown_082A5D6C:: @ 82A5D6C
	.incbin "baserom.gba", 0x2a5d6c, 0x3f

gUnknown_082A5DAB:: @ 82A5DAB
	.incbin "baserom.gba", 0x2a5dab, 0x46

gUnknown_082A5DF1:: @ 82A5DF1
	.incbin "baserom.gba", 0x2a5df1, 0x43

gUnknown_082A5E34:: @ 82A5E34
	.incbin "baserom.gba", 0x2a5e34, 0x4f

gUnknown_082A5E83:: @ 82A5E83
	.incbin "baserom.gba", 0x2a5e83, 0x36

gUnknown_082A5EB9:: @ 82A5EB9
	.incbin "baserom.gba", 0x2a5eb9, 0x3b

gUnknown_082A5EF4:: @ 82A5EF4
	.incbin "baserom.gba", 0x2a5ef4, 0x45

gUnknown_082A5F39:: @ 82A5F39
	.incbin "baserom.gba", 0x2a5f39, 0x49

gUnknown_082A5F82:: @ 82A5F82
	.incbin "baserom.gba", 0x2a5f82, 0x37

gUnknown_082A5FB9:: @ 82A5FB9
	.incbin "baserom.gba", 0x2a5fb9, 0x5f

gUnknown_082A6018:: @ 82A6018
	.incbin "baserom.gba", 0x2a6018, 0x49

gUnknown_082A6061:: @ 82A6061
	.incbin "baserom.gba", 0x2a6061, 0x3b

gUnknown_082A609C:: @ 82A609C
	.incbin "baserom.gba", 0x2a609c, 0x39

gUnknown_082A60D5:: @ 82A60D5
	.incbin "baserom.gba", 0x2a60d5, 0x4f

gUnknown_082A6124:: @ 82A6124
	.incbin "baserom.gba", 0x2a6124, 0x4b

gUnknown_082A616F:: @ 82A616F
	.incbin "baserom.gba", 0x2a616f, 0x67

gUnknown_082A61D6:: @ 82A61D6
	.incbin "baserom.gba", 0x2a61d6, 0x64

gUnknown_082A623A:: @ 82A623A
	.incbin "baserom.gba", 0x2a623a, 0x4d

gUnknown_082A6287:: @ 82A6287
	.incbin "baserom.gba", 0x2a6287, 0x42

gUnknown_082A62C9:: @ 82A62C9
	.incbin "baserom.gba", 0x2a62c9, 0x49

gUnknown_082A6312:: @ 82A6312
	.incbin "baserom.gba", 0x2a6312, 0x2b

gUnknown_082A633D:: @ 82A633D

gUnknown_082A633D: @ 82A633D
	.string "Hmhm…\n"
	.string "On a nationwide basis…\p"
	.string "You’ve seen {STR_VAR_1} POKéMON,\n"
	.string "and you’ve caught {STR_VAR_2} POKéMON…$"

LilycoveCity_DepartmentStore_1F_Text_2A6390: @ 82A6390
	.string "This is the POKéMON LOTTERY CORNER.\p"
	.string "All shoppers at our DEPARTMENT STORE\n"
	.string "get to draw a POKéMON LOTO TICKET.\p"
	.string "If the LOTO TICKET’s number matches\n"
	.string "the ID number of any of your POKéMON,\l"
	.string "you will receive a fabulous gift.\p"
	.string "Would you like to draw a POKéMON\n"
	.string "LOTO TICKET?$"

LilycoveCity_DepartmentStore_1F_Text_2A6496: @ 82A6496
	.string "Please come back tomorrow.$"

LilycoveCity_DepartmentStore_1F_Text_2A64B1: @ 82A64B1
	.string "Please do visit again.$"

LilycoveCity_DepartmentStore_1F_Text_2A64C8: @ 82A64C8
	.string "Please pick a LOTO TICKET.\n"
	.string "…{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}…{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}…{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}{PAUSE 0x8}$"

LilycoveCity_DepartmentStore_1F_Text_2A650B: @ 82A650B
	.string "The LOTO TICKET number is {STR_VAR_1}.\p"
	.string "I need to run a check on this number\n"
	.string "to see if it matches any of your\l"
	.string "POKéMON’s ID numbers. Please wait.$"

LilycoveCity_DepartmentStore_1F_Text_2A6592: @ 82A6592
	.string "Congratulations!\p"
	.string "The ID number of your team’s\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET’s number!$"

LilycoveCity_DepartmentStore_1F_Text_2A65E6: @ 82A65E6
	.string "Congratulations!\p"
	.string "The ID number of your PC-boxed\n"
	.string "{STR_VAR_1} matches your\l"
	.string "LOTO TICKET’s number!$"

LilycoveCity_DepartmentStore_1F_Text_2A663C: @ 82A663C
	.string "I’m sorry.\n"
	.string "None of the numbers matched.$"

LilycoveCity_DepartmentStore_1F_Text_2A6664: @ 82A6664
	.string "Two digits matched, so you win the\n"
	.string "third prize!\l"
	.string "You’ve won the {STR_VAR_1}!$"

LilycoveCity_DepartmentStore_1F_Text_2A66A7: @ 82A66A7
	.string "Three digits matched, so you win the\n"
	.string "second prize!\l"
	.string "You’ve won the {STR_VAR_1}!$"

LilycoveCity_DepartmentStore_1F_Text_2A66ED: @ 82A66ED
	.string "Four digits matched, so you win the\n"
	.string "first prize!\l"
	.string "You’ve won the {STR_VAR_1}!$"

LilycoveCity_DepartmentStore_1F_Text_2A6731: @ 82A6731
	.string "Oh, my goodness, all five digits\n"
	.string "matched!\p"
	.string "You’ve won the jackpot prize!\n"
	.string "You’ve won the {STR_VAR_1}!$"

LilycoveCity_DepartmentStore_1F_Text_2A678C: @ 82A678C
	.string "Oh?\n"
	.string "You seem to have no room for this.\p"
	.string "Please make room in your BAG and\n"
	.string "let me know.$"

LilycoveCity_DepartmentStore_1F_Text_2A67E1: @ 82A67E1
	.string "{PLAYER}?\n"
	.string "Yes, I’ve been expecting you.\p"
	.string "This is the prize we’ve been holding\n"
	.string "for you.$"

LilycoveCity_DepartmentStore_1F_Text_2A6831: @ 82A6831
	.string "Please do visit again.$"

LilycoveCity_Harbor_Text_2A6848: @ 82A6848
	.string "The ferry to SLATEPORT is…\p"
	.string "I beg your pardon?\n"
	.string "Can we sail to this place on the map?\p"
	.string "I know someone who will help you better.\n"
	.string "Please wait.$"

LilycoveCity_Harbor_Text_2A68D2: @ 82A68D2
	.string "The ferry to SLATEPORT is…\p"
	.string "Oh?\n"
	.string "That PASS…$"

LilycoveCity_Harbor_Text_2A68FC: @ 82A68FC
	.string "Aye, mate, are you the one who brought\n"
	.string "that mighty odd PASS?\p"
	.string "I’ll tell you, you’re trying to reach a\n"
	.string "tiny spit of an island far in the south.\p"
	.string "There’s no telling what we’ll encounter\n"
	.string "once we reach there, aye.\l"
	.string "That shivers my timbers!\p"
	.string "All aboard!$"

SouthernIsland_Exterior_Text_2A69F1: @ 82A69F1
	.string "Aye, mate, there’s nothing here to\n"
	.string "see or do on this forgettable island.\p"
	.string "What say we sail back to LILYCOVE?$"

BirthIsland_Harbor_Text_2A6A5D: @ 82A6A5D
FarawayIsland_Entrance_Text_2A6A5D: @ 82A6A5D
NavelRock_Harbor_Text_2A6A5D: @ 82A6A5D
SouthernIsland_Exterior_Text_2A6A5D: @ 82A6A5D
	.string "Aye, right, then!\n"
	.string "Sail home we will!$"

BirthIsland_Harbor_Text_2A6A82: @ 82A6A82
FarawayIsland_Entrance_Text_2A6A82: @ 82A6A82
LilycoveCity_Harbor_Text_2A6A82: @ 82A6A82
NavelRock_Harbor_Text_2A6A82: @ 82A6A82
SouthernIsland_Exterior_Text_2A6A82: @ 82A6A82
	.string "Aye, right, as you like, then.$"

SouthernIsland_Interior_Text_2A6AA1: @ 82A6AA1
	.string "“All dreams are but another reality.\n"
	.string "Never forget…”$"

SouthernIsland_Exterior_Text_2A6AD5: @ 82A6AD5
	.string "“Those whose memories fade seek to\n"
	.string "carve them in their hearts…”$"

Underwater_SealedChamber_Braille_2A6B15: @ 82A6B15
	.byte 4
	.byte 6
	.byte 26
	.byte 13
	.byte 7
	.byte 9
	.braille "GO UP HERE.$"

SealedChamber_OuterRoom_Braille_2A6B27: @ 82A6B27
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "ABC$"

SealedChamber_OuterRoom_Braille_2A6B31: @ 82A6B31
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "GHI$"

SealedChamber_OuterRoom_Braille_2A6B3B: @ 82A6B3B
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "MNO$"

SealedChamber_OuterRoom_Braille_2A6B45: @ 82A6B45
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "TUV$"

SealedChamber_OuterRoom_Braille_2A6B4F: @ 82A6B4F
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "DEF$"

SealedChamber_OuterRoom_Braille_2A6B59: @ 82A6B59
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "JKL$"

SealedChamber_OuterRoom_Braille_2A6B63: @ 82A6B63
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "PQRS$"

SealedChamber_OuterRoom_Braille_2A6B6E: @ 82A6B6E
	.byte 9
	.byte 6
	.byte 19
	.byte 13
	.byte 12
	.byte 9
	.braille ".$"

SealedChamber_OuterRoom_Braille_2A6B76: @ 82A6B76
	.byte 7
	.byte 6
	.byte 21
	.byte 13
	.byte 10
	.byte 9
	.braille "WXYZ$"

SealedChamber_OuterRoom_Braille_2A6B81: @ 82A6B81
	.byte 9
	.byte 6
	.byte 19
	.byte 13
	.byte 12
	.byte 9
	.braille ",$"

SealedChamber_OuterRoom_Braille_2A6B89: @ 82A6B89
	.byte 7
	.byte 4
	.byte 23
	.byte 15
	.byte 10
	.byte 7
	.braille "DIG HERE.$"

SealedChamber_InnerRoom_Braille_2A6B99: @ 82A6B99
	.byte 0
	.byte 0
	.byte 29
	.byte 19
	.byte 3
	.byte 3
	.braille "FIRST COMES\n"
	.braille "WAILORD.\n"
	.braille "LAST COMES\n"
	.braille "RELICANTH.$"

SealedChamber_InnerRoom_Braille_2A6BCA: @ 82A6BCA
	.byte 2
	.byte 0
	.byte 26
	.byte 19
	.byte 5
	.byte 3
	.braille "IN THIS\n"
	.braille "CAVE WE\n"
	.braille "HAVE\n"
	.braille "LIVED.$"

SealedChamber_InnerRoom_Braille_2A6BEC: @ 82A6BEC
	.byte 7
	.byte 2
	.byte 23
	.byte 17
	.byte 10
	.byte 5
	.braille "WE OWE ALL\n"
	.braille "TO THE\n"
	.braille "POKEMON.$"

SealedChamber_InnerRoom_Braille_2A6C0D: @ 82A6C0D
	.byte 3
	.byte 0
	.byte 25
	.byte 19
	.byte 6
	.byte 3
	.braille "BUT, WE\n"
	.braille "SEALED THE\n"
	.braille "POKEMON\n"
	.braille "AWAY.$"

SealedChamber_InnerRoom_Braille_2A6C34: @ 82A6C34
	.byte 5
	.byte 6
	.byte 25
	.byte 13
	.byte 8
	.byte 9
	.braille "WE FEARED IT.$"

SealedChamber_InnerRoom_Braille_2A6C48: @ 82A6C48
	.byte 6
	.byte 0
	.byte 24
	.byte 19
	.byte 9
	.byte 3
	.braille "THOSE WITH\n"
	.braille "COURAGE,\n"
	.braille "THOSE WITH\n"
	.braille "HOPE.$"

SealedChamber_InnerRoom_Braille_2A6C73: @ 82A6C73
	.byte 3
	.byte 2
	.byte 27
	.byte 17
	.byte 6
	.byte 5
	.braille "OPEN A DOOR.\n"
	.braille "AN ETERNAL\n"
	.braille "POKEMON\n"
	.braille "WAITS.$"

DesertRuins_Braille_2A6CA0: @ 82A6CA0
	.byte 1
	.byte 0
	.byte 27
	.byte 19
	.byte 4
	.byte 3
	.braille "LEFT, LEFT,\n"
	.braille "DOWN, DOWN.\n"
	.braille "THEN, USE\n"
	.braille "ROCK SMASH.$"

IslandCave_Braille_2A6CD4: @ 82A6CD4
	.byte 5
	.byte 0
	.byte 25
	.byte 19
	.byte 8
	.byte 3
	.braille "STAY CLOSE\n"
	.braille "TO THE WALL.\n"
	.braille "RUN AROUND\n"
	.braille "ONE LAP.$"

AncientTomb_Braille_2A6D06: @ 82A6D06
	.byte 3
	.byte 0
	.byte 25
	.byte 19
	.byte 6
	.byte 3
	.braille "THOSE WHO\n"
	.braille "INHERIT OUR\n"
	.braille "WILL, SHINE\n"
	.braille "IN THE MIDDLE.$"

PetalburgCity_Gym_Text_2A6D3D: @ 82A6D3D
	.string "DAD: Hi, {PLAYER}!\p"
	.string "I just received a very rare BERRY.\n"
	.string "I’d like you to have it.$"

Route104_Text_2A6D86: @ 82A6D86
	.string "If you see BERRIES growing in loamy\n"
	.string "soil, feel free to take them.\p"
	.string "But make sure you plant a BERRY in the\n"
	.string "same spot. That’s common courtesy.\p"
	.string "Here, I’ll share this with you.$"

Route104_Text_2A6E32: @ 82A6E32
	.string "The way you look, you must be a\n"
	.string "TRAINER, no?\p"
	.string "TRAINERS often make POKéMON hold\n"
	.string "BERRIES.\p"
	.string "It’s up to you whether to grow BERRIES\n"
	.string "or use them.$"

Route111_Text_2A6EBD: @ 82A6EBD
	.string "I watered the plants every day.\n"
	.string "They grew lots of flowers.\p"
	.string "And they gave me lots of BERRIES, too.\p"
	.string "Here you go!\n"
	.string "You can have it!$"

Route111_Text_2A6F3D: @ 82A6F3D
	.string "I’m going to try really hard and make\n"
	.string "BERRIES in different colors.\p"
	.string "I hope you try hard, too!$"

Route111_Text_2A6F9A: @ 82A6F9A
	.string "I wonder what color BERRIES I’ll look\n"
	.string "for today?$"

Route114_Text_2A6FCB: @ 82A6FCB
	.string "I love using the BERRY CRUSH machine,\n"
	.string "so I’m collecting BERRIES.\p"
	.string "I’ll share one with you, if you’d like.$"

Route114_Text_2A7034: @ 82A7034
	.string "You should try the BERRY CRUSH\n"
	.string "machine with your friends.$"

Route114_Text_2A706E: @ 82A706E
	.string "Which BERRY should be planted?\n"
	.string "Should you use or hoard BERRIES?\p"
	.string "It’s fun to think about.$"

Route120_Text_2A70C7: @ 82A70C7
	.string "BERRIES grow by soaking up sunlight.\p"
	.string "We help the BERRIES grow by watering\n"
	.string "them regularly.\p"
	.string "It’s an expression of love, isn’t it?$"

Route120_Text_2A7147: @ 82A7147
	.string "Yes, yes.\n"
	.string "You understand what I mean.\p"
	.string "You should take this.$"

Route120_Text_2A7183: @ 82A7183
	.string "Oh… But it is important to make your\n"
	.string "own impressions, I guess…\p"
	.string "You can have this.$"

Route120_Text_2A71D5: @ 82A71D5
	.string "I think that BERRY is rare.\n"
	.string "I hope you raise it with loving care.$"

Route120_Text_2A7217: @ 82A7217
	.string "I’ll get more BERRIES from\n"
	.string "the BERRY MASTER.$"

LilycoveCity_Text_2A7244: @ 82A7244
	.string "When it gets right down to it…\p"
	.string "The same way suits suit me perfectly,\n"
	.string "a crisp breeze suits the sea.\p"
	.string "And you, a BERRY suits you to a “T”…\p"
	.string "Why should that be so?$"

LilycoveCity_Text_2A72E3: @ 82A72E3
	.string "When it gets right down to it…\p"
	.string "It’s because you’re a TRAINER!$"

LilycoveCity_Text_2A7321: @ 82A7321
	.string "When it gets right down to it…\p"
	.string "The way dignified simplicity suits me,\n"
	.string "{POKEBLOCK}S perfectly suit POKéMON.$"

Route123_BerryMastersHouse_Text_2A7386: @ 82A7386
	.string "You may call me the BERRY MASTER.\p"
	.string "I dream of filling the world with\n"
	.string "beautiful flowers, so I raise BERRIES\l"
	.string "and hand them out to everyone.\p"
	.string "You’re deserving of one!$"

Route123_BerryMastersHouse_Text_2A7428: @ 82A7428
	.string "Why be stingy?\n"
	.string "Take another!$"

Route123_BerryMastersHouse_Text_2A7445: @ 82A7445
	.string "Be sure to visit the PRETTY PETAL\n"
	.string "flower shop near RUSTBORO.\p"
	.string "Let flowers fill the world!$"

Route123_BerryMastersHouse_Text_2A749E: @ 82A749E
	.string "I’m done for today.\n"
	.string "Come again another day.\p"
	.string "Let flowers fill the world!$"

Route123_BerryMastersHouse_Text_2A74E6: @ 82A74E6
	.string "The way my husband grows BERRIES,\n"
	.string "oh, he’s the best in the world.\p"
	.string "He makes me proud, that he does.\p"
	.string "Incidentally, child, have you heard\n"
	.string "a good saying lately?$"

Route123_BerryMastersHouse_Text_2A7583: @ 82A7583
	.string "Ah! What a remarkable saying!\n"
	.string "Inspirational, it is!\p"
	.string "I want you to have this.$"

Route123_BerryMastersHouse_Text_2A75D0: @ 82A75D0
	.string "Oh! A good saying it is.\n"
	.string "You’re quite remarkable.\p"
	.string "I want you to have this.$"

Route123_BerryMastersHouse_Text_2A761B: @ 82A761B
	.string "Our four grandchildren should become\n"
	.string "more accomplished than my husband.\p"
	.string "Joy never goes out of my life!$"

Route123_BerryMastersHouse_Text_2A7682: @ 82A7682
	.string "Ah…$"

Route104_PrettyPetalFlowerShop_Text_2A7686: @ 82A7686
	.string "Hello!\p"
	.string "This is the PRETTY PETAL flower shop.\n"
	.string "Spreading flowers all over the world!$"

Route104_PrettyPetalFlowerShop_Text_2A76D9: @ 82A76D9
	.string "{PLAYER}{KUN}, would you like to learn about\n"
	.string "BERRIES?$"

Route104_PrettyPetalFlowerShop_Text_2A7706: @ 82A7706
	.string "Your name is?\p"
	.string "{PLAYER}{KUN}.\n"
	.string "That’s a nice name.\p"
	.string "{PLAYER}{KUN}, would you like to learn about\n"
	.string "BERRIES?$"

Route104_PrettyPetalFlowerShop_Text_2A775B: @ 82A775B
	.string "BERRIES grow on trees that thrive\n"
	.string "only in soft, loamy soil.\p"
	.string "If you take some BERRIES, be sure to\n"
	.string "plant one in the loamy soil again.\p"
	.string "A planted BERRY will soon sprout,\n"
	.string "grow into a plant, flower beautifully,\l"
	.string "then grow BERRIES again.\p"
	.string "I want to see the whole wide world\n"
	.string "filled with beautiful flowers.\l"
	.string "That’s my dream.\p"
	.string "Please help me, {PLAYER}{KUN}. Plant BERRIES\n"
	.string "and bring more flowers into the world.$"

Route104_PrettyPetalFlowerShop_Text_2A78DF: @ 82A78DF
	.string "Flowers bring so much happiness to\n"
	.string "people, don’t they?$"

Route104_PrettyPetalFlowerShop_Text_2A7916: @ 82A7916
	.string "Hello!\p"
	.string "The more attention you give to flowers,\n"
	.string "the more beautifully they bloom.\p"
	.string "You’ll like tending flowers. I’m sure\n"
	.string "of it. You can have this.$"

Route104_PrettyPetalFlowerShop_Text_2A79A6: @ 82A79A6
	.string "While BERRY plants are growing,\n"
	.string "water them with the WAILMER PAIL.\p"
	.string "Oh, another thing.\p"
	.string "If you don’t pick BERRIES for a while,\n"
	.string "they’ll drop off onto the ground.\l"
	.string "But they’ll sprout again.\p"
	.string "Isn’t that awesome?\n"
	.string "It’s like they have the will to live.$"

Route104_PrettyPetalFlowerShop_Text_2A7A98: @ 82A7A98
	.string "I’m trying to be like my big sisters.\n"
	.string "I’m growing flowers, too!\p"
	.string "Here you go!\n"
	.string "It’s for you!$"

Route104_PrettyPetalFlowerShop_Text_2A7AF3: @ 82A7AF3
	.string "You can plant a BERRY and grow it big,\n"
	.string "or you can make a POKéMON hold it.\p"
	.string "But now they have a machine that mixes\n"
	.string "up different BERRIES and makes candies\l"
	.string "for POKéMON.\p"
	.string "I want some candy, too.$"

SootopolisCity_Text_2A7BB0: @ 82A7BB0
	.string "Hi, what’s your name?\p"
	.string "… … …  … … …  … … …\n"
	.string "Okay. That’s nice!\p"
	.string "My name is KIRI.\p"
	.string "My mommy and daddy named me that so\n"
	.string "I would grow healthy and warmhearted.\l"
	.string "That’s what they wished.\p"
	.string "You can have one of these.$"

SootopolisCity_Text_2A7C7C: @ 82A7C7C
	.string "KIRI will give you this BERRY, too!\n"
	.string "I really like it lots!$"

SootopolisCity_Text_2A7CB7: @ 82A7CB7
	.string "I wonder what kind of wish is included\n"
	.string "in your name.$"

SootopolisCity_Text_2A7CEC: @ 82A7CEC
	.string "Spring, summer, autumn, and winter.\p"
	.string "If you’re born in springtime, do you like\n"
	.string "the spring, and if you’re born in the\l"
	.string "summer, do you like the summer?$"

SootopolisCity_Text_2A7D80: @ 82A7D80
	.string "Then KIRI was born in the autumn,\n"
	.string "so I love the autumn!\p"
	.string "Which season do you like?$"

SootopolisCity_Text_2A7DD2: @ 82A7DD2
	.string "Oh…\n"
	.string "It doesn’t matter…\p"
	.string "There’s so much that I want to know…$"

ShoalCave_LowTideEntranceRoom_Text_2A7E0E: @ 82A7E0E
	.string "Are you planning on going deep\n"
	.string "in there?\p"
	.string "How about bringing me back some\n"
	.string "SHOAL SALT and SHOAL SHELLS?\p"
	.string "I can make you something good if\n"
	.string "you bring me the ingredients.$"

ShoalCave_LowTideEntranceRoom_Text_2A7EB3: @ 82A7EB3
	.string "If you bring me four each of the\n"
	.string "SHOAL SALT and SHOAL SHELLS,\l"
	.string "I can make you a SHELL BELL…\p"
	.string "You can get those ingredients\n"
	.string "every day.$"

ShoalCave_LowTideEntranceRoom_Text_2A7F37: @ 82A7F37
	.string "Oh, hey! SHOAL SALT and SHOAL SHELLS!\n"
	.string "And enough of them, too!\p"
	.string "Would you like me to make you\n"
	.string "a SHELL BELL with them?$"

ShoalCave_LowTideEntranceRoom_Text_2A7FAC: @ 82A7FAC
	.string "All righty, then! I’ll make you\n"
	.string "a SHELL BELL right away.\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "There! Done!$"

ShoalCave_LowTideEntranceRoom_Text_2A8012: @ 82A8012
	.string "Have a POKéMON hold on to that.\n"
	.string "It’ll love it, that’s for certain.\p"
	.string "Why, the SHELL BELL’s chime…\n"
	.string "It’s simply sublime!\p"
	.string "You can get its ingredients every day,\n"
	.string "so I can make you more.$"

ShoalCave_LowTideEntranceRoom_Text_2A80C6: @ 82A80C6
	.string "Oh… Is that so…\n"
	.string "I wanted to make a SHELL BELL…$"

ShoalCave_LowTideEntranceRoom_Text_2A80F5: @ 82A80F5
	.string "You don’t have space in your BAG\n"
	.string "if I were to make it for you.\p"
	.string "You should make room and come back\n"
	.string "for a SHELL BELL.$"

ShoalCave_LowTideInnerRoom_Text_2A8169: @ 82A8169
ShoalCave_LowTideLowerRoom_Text_2A8169: @ 82A8169
ShoalCave_LowTideStairsRoom_Text_2A8169: @ 82A8169
	.string "There was some SHOAL SALT here.\n"
	.string "But, there’s nothing here now.$"

ShoalCave_LowTideInnerRoom_Text_2A81A8: @ 82A81A8
	.string "There was a SHOAL SHELL here.\n"
	.string "But, there’s nothing here now.$"

	.incbin "baserom.gba", 0x2a81e5, 0x142

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

	.incbin "baserom.gba", 0x2a8350, 0x19

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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83D0
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83C6
	compare_var_to_value VAR_RESULT, 2
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8435
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A83F7
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A83F7:: @ 82A83F7
	special sub_818DCC8
	special sub_818DD14
	specialvar VAR_RESULT, sub_818DD54
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8419
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A848E
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84AD
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A848E:: @ 82A848E
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8BEE, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8454
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A846C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84AD:: @ 82A84AD
	specialvar VAR_RESULT, sub_818DE44
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84C9
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84D6
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84C9:: @ 82A84C9
	special sub_818DC2C
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8C0F, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A84D6:: @ 82A84D6
	specialvar VAR_RESULT, sub_818DE5C
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A84F2
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8545
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8585
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85AC
	compare_var_to_value VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86EC
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8585:: @ 82A8585
	specialvar VAR_RESULT, sub_818E06C
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85C8
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85D2
	compare_var_to_value VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A85E0
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A85AC:: @ 82A85AC
	specialvar VAR_RESULT, sub_818E2D8
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8759
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A861C
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8612
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8612:: @ 82A8612
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A8F65, 4
	release
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A861C:: @ 82A861C
	special sub_818E3BC
	compare_var_to_value VAR_0x8004, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A864C
	compare_var_to_value VAR_0x8004, 15
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8656

LilycoveCity_PokemonCenter_1F_EventScript_2A8635:: @ 82A8635
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8660
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A867F
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A86C7
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8708
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8785
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87AF
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87CE
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A87AF:: @ 82A87AF
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9212, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A87F8
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A8817
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A87F8:: @ 82A87F8
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A92D3, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8778
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8850
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A886C
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A8850:: @ 82A8850
	specialvar VAR_RESULT, sub_818E8E0
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8876
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A89AE
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A94E8, 5
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 65535
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88D7
	compare_var_to_value VAR_RESULT, 65535
	goto_if 5, LilycoveCity_PokemonCenter_1F_EventScript_2A88F6
	end

LilycoveCity_PokemonCenter_1F_EventScript_2A88D7:: @ 82A88D7
	msgbox LilycoveCity_PokemonCenter_1F_Text_2A9537, 5
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A88B0
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_0x8004, 1
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
	compare_var_to_value VAR_0x8004, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8970
	compare_var_to_value VAR_0x8004, 1
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
	compare_var_to_value VAR_RESULT, 1
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

	.incbin "baserom.gba", 0x2a89be, 0x2

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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A0A
	compare_var_to_value VAR_RESULT, 1
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A1D
	compare_var_to_value VAR_RESULT, 2
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A30
	compare_var_to_value VAR_RESULT, 3
	goto_eq LilycoveCity_PokemonCenter_1F_EventScript_2A8A43
	compare_var_to_value VAR_RESULT, 4
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

	.incbin "baserom.gba", 0x2a9056, 0x14

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

	.incbin "baserom.gba", 0x2a9305, 0x31

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


	.incbin "baserom.gba", 0x2a971c, 0xa1a5

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

	.incbin "baserom.gba", 0x2b3ab3, 0x249f

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

	.incbin "baserom.gba", 0x2b6061, 0x82c

BattleFrontier_BattleTowerLobby_EventScript_2B688D:: @ 82B688D
	lock
	faceplayer
	setvar VAR_0x8004, 0
	special sub_81A085C
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6900
	setvar VAR_0x8004, 10
	special sub_81A085C
	compare_var_to_value VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B68BE
	checkflag FLAG_0x934
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6E90

BattleFrontier_BattleTowerLobby_EventScript_2B68BE:: @ 82B68BE
	setvar VAR_0x8004, 11
	special sub_81A085C
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B69D3
	compare_var_to_value VAR_RESULT, 4
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6ACF
	compare_var_to_value VAR_RESULT, 3
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6C77
	compare_var_to_value VAR_RESULT, 1
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6D5C
	compare_var_to_value VAR_RESULT, 5
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
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_0x8005, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6ABA
	compare_var_to_value VAR_0x8005, 1
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
	compare_var_to_value VAR_RESULT, 3
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6B81
	setvar VAR_0x8004, 20
	special sub_81A085C
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_0x8005, 0
	call_if 1, BattleFrontier_BattleTowerLobby_EventScript_2B6D50
	compare_var_to_value VAR_0x8005, 1
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
	compare_var_to_value VAR_0x8004, 0
	goto_eq BattleFrontier_BattleTowerLobby_EventScript_2B6E93
	applymovement 6, BattleFrontier_BattleTowerLobby_Movement_2B6E94
	waitmovement 0
	end

BattleFrontier_BattleTowerLobby_EventScript_2B6E72:: @ 82B6E72
	setvar VAR_0x8004, 24
	special sub_81A085C
	compare_var_to_value VAR_0x8004, 0
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

	.incbin "baserom.gba", 0x2b6ea5, 0xcf80

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
	compare_var_to_value VAR_RESULT, 3
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare_var_to_value VAR_RESULT, 6
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare_var_to_value VAR_RESULT, 7
	goto_eq BattleFrontier_BattlePikeRandomRoom1_EventScript_2C3F35
	compare_var_to_value VAR_RESULT, 8
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
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4128
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom1_EventScript_2C4144
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4128
	compare_var_to_value VAR_RESULT, 1
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
	compare_var_to_value VAR_RESULT, 1
	call_if 1, BattleFrontier_BattlePikeRandomRoom3_EventScript_2C4144
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 2
	goto_eq BattleFrontier_BattlePikeThreePathRoom_EventScript_2C426B
	compare_var_to_value VAR_RESULT, 1
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

	.incbin "baserom.gba", 0x2c4b77, 0x51

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

	.incbin "baserom.gba", 0x2c53db, 0x62

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

	.incbin "baserom.gba", 0x2c5ac9, 0x3d

SlateportCity_BattleTentLobby_Text_2C5B06: @ 82C5B06
	.string "Before you begin your challenge,\n"
	.string "I need to save data. Is that okay?$"

	.incbin "baserom.gba", 0x2c5b4a, 0x42

SlateportCity_BattleTentLobby_Text_2C5B8C: @ 82C5B8C
	.string "Please step this way.$"

SlateportCity_BattleTentLobby_Text_2C5BA2: @ 82C5BA2
	.string "Thank you for participating!\p"
	.string "I will return your POKéMON in exchange\n"
	.string "for our rental POKéMON.\p"
	.string "I must also save your event results.\n"
	.string "Please wait.$"

	.incbin "baserom.gba", 0x2c5c30, 0x3f

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

	.incbin "baserom.gba", 0x2c5e85, 0x83

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

	.incbin "baserom.gba", 0x2c6261, 0x56c

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
	compare_var_to_value VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F6A
	call SlateportCity_PokemonFanClub_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq SlateportCity_PokemonFanClub_EventScript_2C7F6A
	msgbox SlateportCity_PokemonFanClub_Text_2C6F66, 4
	setvar VAR_0x8005, 23
	call SlateportCity_PokemonFanClub_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_2C7FD2
	call MauvilleCity_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq MauvilleCity_EventScript_2C7FD2
	msgbox MauvilleCity_Text_2C70F3, 4
	setvar VAR_0x8005, 16
	call MauvilleCity_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C803A
	call VerdanturfTown_PokemonCenter_1F_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq VerdanturfTown_PokemonCenter_1F_EventScript_2C803A
	msgbox VerdanturfTown_PokemonCenter_1F_Text_2C7243, 4
	setvar VAR_0x8005, 29
	call VerdanturfTown_PokemonCenter_1F_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LavaridgeTown_House_EventScript_2C80A2
	call LavaridgeTown_House_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq LavaridgeTown_House_EventScript_2C80A2
	msgbox LavaridgeTown_House_Text_2C73B1, 4
	setvar VAR_0x8005, 7
	call LavaridgeTown_House_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq FallarborTown_Mart_EventScript_2C810A
	call FallarborTown_Mart_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq FallarborTown_Mart_EventScript_2C810A
	msgbox FallarborTown_Mart_Text_2C7582, 4
	setvar VAR_0x8005, 8
	call FallarborTown_Mart_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq FortreeCity_House2_EventScript_2C8172
	call FortreeCity_House2_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq FortreeCity_House2_EventScript_2C8172
	msgbox FortreeCity_House2_Text_2C7721, 4
	setvar VAR_0x8005, 24
	call FortreeCity_House2_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA
	call LilycoveCity_DepartmentStoreRooftop_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq LilycoveCity_DepartmentStoreRooftop_EventScript_2C81DA
	msgbox LilycoveCity_DepartmentStoreRooftop_Text_2C7911, 4
	setvar VAR_0x8005, 14
	call LilycoveCity_DepartmentStoreRooftop_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_EventScript_2C8242
	call MossdeepCity_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq MossdeepCity_EventScript_2C8242
	msgbox MossdeepCity_Text_2C7B0D, 4
	setvar VAR_0x8005, 15
	call MossdeepCity_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	call SootopolisCity_PokemonCenter_1F_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7C98, 4
	setvar VAR_0x8005, 4
	call SootopolisCity_PokemonCenter_1F_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 0
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C8312
	call PacifidlogTown_PokemonCenter_1F_EventScript_2C832D
	compare_var_to_value VAR_RESULT, 0
	goto_eq PacifidlogTown_PokemonCenter_1F_EventScript_2C8312
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2C7E40, 4
	setvar VAR_0x8005, 12
	call PacifidlogTown_PokemonCenter_1F_EventScript_2C8326
	compare_var_to_value VAR_RESULT, 0
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
	compare_var_to_value VAR_RESULT, 2
	goto_eq TrainerHill_1F_EventScript_2C83C9
	compare_var_to_value VAR_RESULT, 3
	goto_eq TrainerHill_1F_EventScript_2C83C9
	compare_var_to_value VAR_RESULT, 9
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

gUnknown_082C8393:: @ 82C8393

	.incbin "baserom.gba", 0x2c8393, 0x13

TrainerHill_1F_EventScript_2C83A6:: @ 82C83A6
	setvar VAR_0x4002, 1
	setvar VAR_0x8004, 9
	special sp194_trainer_tower
	compare_var_to_value VAR_RESULT, 1
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

	.incbin "baserom.gba", 0x2c83ee, 0x2

gUnknown_082C83F0:: @ 82C83F0
	.incbin "baserom.gba", 0x2c83f0, 0x46

gUnknown_082C8436:: @ 82C8436
	.incbin "baserom.gba", 0x2c8436, 0x37e

gUnknown_082C87B4:: @ 82C87B4
	.incbin "baserom.gba", 0x2c87b4, 0x21

gUnknown_082C87D5:: @ 82C87D5
	.incbin "baserom.gba", 0x2c87d5, 0x3b

gUnknown_082C8810:: @ 82C8810
	.incbin "baserom.gba", 0x2c8810, 0x22

gUnknown_082C8832:: @ 82C8832
	.incbin "baserom.gba", 0x2c8832, 0x13

gUnknown_082C8845:: @ 82C8845
	.incbin "baserom.gba", 0x2c8845, 0xe5

gUnknown_082C892A:: @ 82C892A
	.incbin "baserom.gba", 0x2c892a, 0x2f

gUnknown_082C8959:: @ 82C8959
	.incbin "baserom.gba", 0x2c8959, 0x22

gUnknown_082C897B:: @ 82C897B
	.incbin "baserom.gba", 0x2c897b, 0xa4

gUnknown_082C8A1F:: @ 82C8A1F
	.incbin "baserom.gba", 0x2c8a1f, 0x1b1

gUnknown_082C8BD0:: @ 82C8BD0
	.incbin "baserom.gba", 0x2c8bd0, 0xd

gUnknown_082C8BDD:: @ 82C8BDD
	.incbin "baserom.gba", 0x2c8bdd, 0x22

gUnknown_082C8BFF:: @ 82C8BFF
	.incbin "baserom.gba", 0x2c8bff, 0x1d

gUnknown_082C8C1C:: @ 82C8C1C
	.incbin "baserom.gba", 0x2c8c1c, 0xe

gUnknown_082C8C2A:: @ 82C8C2A
	.incbin "baserom.gba", 0x2c8c2a, 0x50

gUnknown_082C8C7A:: @ 82C8C7A
	.incbin "baserom.gba", 0x2c8c7a, 0xea
