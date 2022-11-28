@ All unused / leftover scripts from RS
CaveOfOrigin_EventScript_LegendaryCry::
	lockall
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER  @ SPECIES_GROUDON in Ruby
	waitmoncry
	setvar VAR_TEMP_5, 1
	releaseall
	end

CaveOfOrigin_EventScript_Shake1::
	lockall
	setvar VAR_TEMP_1, 1
	goto CaveOfOrigin_EventScript_Shake
	end

CaveOfOrigin_EventScript_Shake2::
	lockall
	setvar VAR_TEMP_2, 1
	goto CaveOfOrigin_EventScript_Shake
	end

CaveOfOrigin_EventScript_Shake3::
	lockall
	setvar VAR_TEMP_3, 1
	goto CaveOfOrigin_EventScript_Shake
	end

CaveOfOrigin_EventScript_Shake::
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	releaseall
	end

CaveOfOrigin_EventScript_DisableTriggers::
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 1
	setvar VAR_TEMP_3, 1
	setvar VAR_TEMP_4, 1
	setvar VAR_TEMP_5, 1
	return
