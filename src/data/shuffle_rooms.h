static const struct RoomInfo Rooms[TOTAL_ROOMS] = {
    {
        .id = MAP_START_MAP,
        .warpIds = { 1, -1, -1, -1},
    }, {
        .id = MAP_DOUBLE_TRAINER_FIGHT,
        .warpIds = { 2,  1, -1, -1},
    }, {
        .id = MAP_TWO_WILD_ENCOUNTERS,
        .warpIds = { 0, 0, 0, 0},
    }, {
        .id = MAP_HEALER_ROOM,
        .warpIds = { 0, 0, 0, 0},
    }, {
        .id = MAP_CHOICE_MAP1,
        .warpIds = { 0, 0, 0, 0},
    }, {
        .id = MAP_END_MAP,
        .warpIds = { 0,  1, -1, -1},
    }
};
