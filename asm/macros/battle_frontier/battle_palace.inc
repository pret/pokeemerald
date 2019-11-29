@ To be populated with macros for CallBattlePalaceFunction

    @ Buffer the opponents intro speech to gStringVar4. Also used by Battle Arena and Factory 
    .macro palace_getopponentintro
    setvar VAR_0x8004, BATTLE_PALACE_FUNC_GET_OPPONENT_INTRO
    special CallBattlePalaceFunction
    .endm
