#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Battle Message: Send-in message depends on foe HP")
{
    u32 hp;

    PARAMETRIZE { hp = 100; }
    PARAMETRIZE { hp = 69; }
    PARAMETRIZE { hp = 39; }
    PARAMETRIZE { hp = 9; }
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        PLAYER(SPECIES_WYNAUT);
        OPPONENT(SPECIES_WOBBUFFET) { HP(hp); MaxHP(100); }
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        if (hp > 69)
            MESSAGE("Go! Wynaut!");
        else if (hp > 39)
            MESSAGE("You're in charge, Wynaut!");
        else if (hp > 9)
            MESSAGE("Go for it, Wynaut!");
        else
            MESSAGE("Your opponent's weak! Get 'em, Wynaut!");
    }
}

SINGLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Singles)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_GIRAFARIG);
    } WHEN {
        TURN { SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("You are challenged by 2!");
        MESSAGE("2 sent out Wobbuffet!");
        MESSAGE("Go! Gastly!");
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Girafarig!");
    }
}

AI_SINGLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Singles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { EXPECT_SWITCH(opponent, 1); }
    } SCENE {
        MESSAGE("You are challenged by " AI_TRAINER_NAME "!");
        MESSAGE(AI_TRAINER_NAME " sent out Wobbuffet!");
        MESSAGE("Go! Gastly!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wobbuffet!");
        MESSAGE(AI_TRAINER_NAME " sent out Girafarig!");
    }
}

DOUBLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Doubles)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GIRAFARIG);
        OPPONENT(SPECIES_FARIGIRAF);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 3);
            SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("You are challenged by 2!");
        MESSAGE("2 sent out Wobbuffet and Wynaut!");
        MESSAGE("Go! Gastly and Haunter!");
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Farigiraf!");
        MESSAGE("2 withdrew Wynaut!");
        MESSAGE("2 sent out Girafarig!");
    }
}

AI_DOUBLE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Doubles)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
        OPPONENT(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            EXPECT_SWITCH(opponentLeft, 3);
            EXPECT_SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("You are challenged by " AI_TRAINER_NAME "!");
        MESSAGE(AI_TRAINER_NAME " sent out Wobbuffet and Wynaut!");
        MESSAGE("Go! Gastly and Haunter!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wobbuffet!");
        MESSAGE(AI_TRAINER_NAME " sent out Farigiraf!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wynaut!");
        MESSAGE(AI_TRAINER_NAME " sent out Girafarig!");
    }
}

MULTI_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (Multi)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_FARIGIRAF);
        OPPONENT_B(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_GIRAFARIG);
    } WHEN {
        TURN {
            SWITCH(playerRight, 1);
            SWITCH(opponentLeft, 1);
            SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("You are challenged by 2 and 4!");
        MESSAGE("2 sent out Wobbuffet! 4 sent out Wynaut!");
        MESSAGE("3 sent out Haunter! Go, Gastly!");
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Farigiraf!");
        MESSAGE("3 withdrew Haunter!");
        MESSAGE("3 sent out Gengar!");
        MESSAGE("4 withdrew Wynaut!");
        MESSAGE("4 sent out Girafarig!");
    }
}

AI_MULTI_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI Multi)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT_A(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT_A(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
        OPPONENT_B(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT_B(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            SWITCH(playerRight, 1);
            EXPECT_SWITCH(opponentLeft, 1);
            EXPECT_SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("You are challenged by " AI_TRAINER_NAME " and " AI_TRAINER_2_NAME "!");
        MESSAGE(AI_TRAINER_NAME " sent out Wobbuffet! " AI_TRAINER_2_NAME " sent out Wynaut!");
        MESSAGE(AI_PARTNER_NAME " sent out Haunter! Go, Gastly!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wobbuffet!");
        MESSAGE(AI_TRAINER_NAME " sent out Farigiraf!");
        MESSAGE(AI_PARTNER_NAME " withdrew Haunter!");
        MESSAGE(AI_PARTNER_NAME " sent out Gengar!");
        MESSAGE(AI_TRAINER_2_NAME " withdrew Wynaut!");
        MESSAGE(AI_TRAINER_2_NAME " sent out Girafarig!");
    }
}

TWO_VS_ONE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (2v1)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WYNAUT);
        OPPONENT(SPECIES_GIRAFARIG);
        OPPONENT(SPECIES_FARIGIRAF);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 3);
            SWITCH(playerRight, 1);
            SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("You are challenged by 2!");
        MESSAGE("2 sent out Wobbuffet and Wynaut!");
        MESSAGE("3 sent out Haunter! Go, Gastly!");
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Farigiraf!");
        MESSAGE("2 withdrew Wynaut!");
        MESSAGE("2 sent out Girafarig!");
        MESSAGE("3 withdrew Haunter!");
        MESSAGE("3 sent out Gengar!");
    }
}

AI_TWO_VS_ONE_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI 2v1)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PARTNER(SPECIES_HAUNTER);
        PARTNER(SPECIES_GENGAR);
        OPPONENT(SPECIES_WOBBUFFET) { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_WYNAUT)    { Moves(MOVE_TACKLE);  }
        OPPONENT(SPECIES_GIRAFARIG) { Moves(MOVE_PSYCHIC); }
        OPPONENT(SPECIES_FARIGIRAF) { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN {
            EXPECT_SWITCH(opponentLeft, 3);
            SWITCH(playerRight, 1);
            EXPECT_SWITCH(opponentRight, 2);
        }
    } SCENE {
        MESSAGE("You are challenged by " AI_TRAINER_NAME "!");
        MESSAGE(AI_TRAINER_NAME " sent out Wobbuffet and Wynaut!");
        MESSAGE(AI_PARTNER_NAME " sent out Haunter! Go, Gastly!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wobbuffet!");
        MESSAGE(AI_TRAINER_NAME " sent out Farigiraf!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wynaut!");
        MESSAGE(AI_TRAINER_NAME " sent out Girafarig!");
        MESSAGE(AI_PARTNER_NAME " withdrew Haunter!");
        MESSAGE(AI_PARTNER_NAME " sent out Gengar!");
    }
}

ONE_VS_TWO_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (1v2)")
{
    GIVEN {
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_FARIGIRAF);
        OPPONENT_B(SPECIES_WYNAUT);
        OPPONENT_B(SPECIES_GIRAFARIG);
    } WHEN {
        TURN {
            SWITCH(opponentLeft, 1);
            SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("You are challenged by 2 and 4!");
        MESSAGE("2 sent out Wobbuffet! 4 sent out Wynaut!");
        MESSAGE("Go! Gastly and Haunter!");
        MESSAGE("2 withdrew Wobbuffet!");
        MESSAGE("2 sent out Farigiraf!");
        MESSAGE("4 withdrew Wynaut!");
        MESSAGE("4 sent out Girafarig!");
    }
}

AI_ONE_VS_TWO_BATTLE_TEST("Battle Message: STRINGID_INTROMSG, STRINGID_INTROSENDOUT, STRINGID_RETURNMON, and STRINGID_SWITCHINMON (AI 1v2)")
{
    GIVEN {
        AI_FLAGS(AI_FLAG_SMART_TRAINER);
        PLAYER(SPECIES_GASTLY);
        PLAYER(SPECIES_HAUNTER);
        OPPONENT_A(SPECIES_WOBBUFFET)   { Moves(MOVE_TACKLE);  }
        OPPONENT_A(SPECIES_FARIGIRAF)   { Moves(MOVE_PSYCHIC); }
        OPPONENT_B(SPECIES_WYNAUT)      { Moves(MOVE_TACKLE);  }
        OPPONENT_B(SPECIES_GIRAFARIG)   { Moves(MOVE_PSYCHIC); }
    } WHEN {
        TURN { 
            EXPECT_SWITCH(opponentLeft, 1);
            EXPECT_SWITCH(opponentRight, 1);
        }
    } SCENE {
        MESSAGE("You are challenged by " AI_TRAINER_NAME " and " AI_TRAINER_2_NAME "!");
        MESSAGE(AI_TRAINER_NAME " sent out Wobbuffet! " AI_TRAINER_2_NAME " sent out Wynaut!");
        MESSAGE("Go! Gastly and Haunter!");
        MESSAGE(AI_TRAINER_NAME " withdrew Wobbuffet!");
        MESSAGE(AI_TRAINER_NAME " sent out Farigiraf!");
        MESSAGE(AI_TRAINER_2_NAME " withdrew Wynaut!");
        MESSAGE(AI_TRAINER_2_NAME " sent out Girafarig!");
    }
}

TO_DO_BATTLE_TEST("Battle Message: Switch-out message changes based on conditions")
/*{
    GIVEN {
        PLAYER(SPECIES_WYNAUT);
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { SWITCH(player, 1); }
    } SCENE {
        if (???)
            MESSAGE("Wynaut, that's enough! Come back!");
        else if (???)
            MESSAGE("Wynaut, come back!");
        else if (???)
            MESSAGE("Wynaut, OK! Come back!");
        else
            MESSAGE("Wynaut, good! Come back!");
    }
}*/
