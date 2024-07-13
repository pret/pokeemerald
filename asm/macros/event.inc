	@ Does nothing.
	.macro nop
	.byte 0x00
	.endm

	@ Does nothing.
	.macro nop1
	.byte 0x01
	.endm

	@ Terminates script execution.
	.macro end
	.byte 0x02
	.endm

	@ Jumps back to after the last-executed call statement, and continues script execution from there.
	.macro return
	.byte 0x03
	.endm

	@ Jumps to destination and continues script execution from there. The location of the calling script is remembered and can be returned to later.
	.macro call destination:req
	.byte 0x04
	.4byte \destination
	.endm

	@ Jumps to destination and continues script execution from there.
	.macro goto destination:req
	.byte 0x05
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to destination and continues script execution from there.
	.macro goto_if condition:req, destination:req
	.byte 0x06
	.byte \condition
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls destination.
	.macro call_if condition:req, destination:req
	.byte 0x07
	.byte \condition
	.4byte \destination
	.endm

	@ Jumps to the script in gStdScripts at index function.
	.macro gotostd function:req
	.byte 0x08
	.byte \function
	.endm

	@ callstd function names
	STD_OBTAIN_ITEM = 0
	STD_FIND_ITEM = 1
	STD_OBTAIN_DECORATION = 7
	STD_REGISTER_MATCH_CALL = 8

	@ Calls the script in gStdScripts at index function.
	.macro callstd function:req
	.byte 0x09
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to the script in gStdScripts at index function.
	.macro gotostd_if condition:req, function:req
	.byte 0x0a
	.byte \condition
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls the script in gStdScripts at index function.
	.macro callstd_if condition:req, function:req
	.byte 0x0b
	.byte \condition
	.byte \function
	.endm

	@ Equivalent to the 'return' command for a RAM script.
	.macro returnram
	.byte 0x0c
	.endm

	@ Equivalent to the 'end' command for a RAM script.
	.macro endram
	.byte 0x0d
	.endm

	@ Sets the Mystery Event script status (MEVENT_STATUS_*).
	.macro setmysteryeventstatus value:req
	.byte 0x0e
	.byte \value
	.endm

	@ Sets the value at the specified script data index to a fixed 4-byte value.
	.macro loadword destIndex:req, value:req
	.byte 0x0f
	.byte \destIndex
	.4byte \value
	.endm

	@ Sets the value at the specified script data index to a fixed byte value.
	.macro loadbyte destIndex:req, value:req
	.byte 0x10
	.byte \destIndex
	.byte \value
	.endm

	@ Sets the value at the specified pointer.
	.macro setptr value:req, ptr:req
	.byte 0x11
	.byte \value
	.4byte \ptr
	.endm

	@ Sets the value at the specified script data index to the value at pointer 'source'.
	.macro loadbytefromptr destIndex:req, source:req
	.byte 0x12
	.byte \destIndex
	.4byte \source
	.endm

	@ Sets the value at pointer 'destination' to the contents of the script data at 'srcIndex'.
	.macro setptrbyte srcIndex:req, destination:req
	.byte 0x13
	.byte \srcIndex
	.4byte \destination
	.endm

	@ Copies the contents of the script data from one index to another.
	.macro copylocal destIndex:req, srcIndex:req
	.byte 0x14
	.byte \destIndex
	.byte \srcIndex
	.endm

	@ Copies the byte at source to destination, replacing whatever byte was previously there.
	.macro copybyte destination:req, source:req
	.byte 0x15
	.4byte \destination
	.4byte \source
	.endm

	@ Changes the value of destination to value.
	.macro setvar destination:req, value:req
	.byte 0x16
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by adding value to it. Overflow is not prevented (0xFFFF + 1 = 0x0000).
	.macro addvar destination:req, value:req
	.byte 0x17
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by subtracting value to it. Overflow is not prevented (0x0000 - 1 = 0xFFFF).
	.macro subvar destination:req, value:req
	.byte 0x18
	.2byte \destination
	.2byte \value
	.endm

	@ Copies the value of source into destination.
	.macro copyvar destination:req, source:req
	.byte 0x19
	.2byte \destination
	.2byte \source
	.endm

	@ If source is not a variable, then this function acts like setvar. Otherwise, it acts like copyvar.
	.macro setorcopyvar destination:req, source:req
	.byte 0x1a
	.2byte \destination
	.2byte \source
	.endm

	@ Compares the values of the script data at indexes 'local1' and 'local2'.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_local_to_local local1:req, local2:req
	.byte 0x1b
	.byte \local1
	.byte \local2
	.endm

	@ Compares the value of the script data at index 'local' to a fixed value.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_local_to_value local:req, value:req
	.byte 0x1c
	.byte \local
	.byte \value
	.endm

	@ Compares the value of the script data at index 'local' to the value at 'ptr'
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_local_to_ptr local:req, ptr:req
	.byte 0x1d
	.byte \local
	.4byte \ptr
	.endm

	@ Compares the value at 'ptr' to the value of the script data at index 'local'.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_ptr_to_local ptr:req, local:req
	.byte 0x1e
	.4byte \ptr
	.byte \local
	.endm

	@ Compares the value at 'ptr' to a fixed value.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_ptr_to_value ptr:req, value:req
	.byte 0x1f
	.4byte \ptr
	.byte \value
	.endm

	@ Compares the value at 'ptr1' to the value at 'ptr2'.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_ptr_to_ptr ptr1:req, ptr2:req
	.byte 0x20
	.4byte \ptr1
	.4byte \ptr2
	.endm

	@ Compares the value of 'var' to a fixed value.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_var_to_value var:req, value:req
	.byte 0x21
	.2byte \var
	.2byte \value
	.endm

	@ Compares the value of 'var1' to the value of 'var2'.
	@ The result is stored in comparisonResult to be acted on by goto_if / call_if
	.macro compare_var_to_var var1:req, var2:req
	.byte 0x22
	.2byte \var1
	.2byte \var2
	.endm

	@ Generic compare macro which attempts to deduce argument types based on their values
	@ Any values between VARS_START to VARS_END and SPECIAL_VARS_START to SPECIAL_VARS_END are considered event variable identifiers
	.macro compare var:req, arg:req
		.if ((\arg >= VARS_START && \arg <= VARS_END) || (\arg >= SPECIAL_VARS_START && \arg <= SPECIAL_VARS_END))
			compare_var_to_var \var, \arg
		.else
			compare_var_to_value \var, \arg
		.endif
	.endm

	@ Calls the native C function stored at func.
	.macro callnative func:req
	.byte 0x23
	.4byte \func
	.endm

	@ Replaces the script with the function stored at func. Execution returns to the bytecode script when func returns TRUE.
	.macro gotonative func:req
	.byte 0x24
	.4byte \func
	.endm

	@ Calls a function listed in the table in data/specials.inc.
	.macro special function:req
	.byte 0x25
	.2byte SPECIAL_\function
	.endm

	@ Calls a function listed in the table in data/specials.inc.
	@ That function's output (if any) will be written to the variable specified by 'output'.
	.macro specialvar output:req, function:req
	.byte 0x26
	.2byte \output
	.2byte SPECIAL_\function
	.endm

	@ Blocks script execution until a command or C code manually unblocks it. Generally used with specific
	@ commands and specials. Calling ScriptContext_Enable for instance will allow execution to continue.
	.macro waitstate
	.byte 0x27
	.endm

	@ Blocks script execution for frames. (Pokemon Emerald runs at just shy of 60 frames per second.)
	.macro delay frames:req
	.byte 0x28
	.2byte \frames
	.endm

	@ Sets flag to TRUE.
	.macro setflag flag:req
	.byte 0x29
	.2byte \flag
	.endm

	@ Sets flag to FALSE.
	.macro clearflag flag:req
	.byte 0x2a
	.2byte \flag
	.endm

	@ Compares flag to TRUE and stores the result in comparisonResult to be used by goto_if, etc
	@ See additional _if_unset and _if_set macros
	.macro checkflag flag:req
	.byte 0x2b
	.2byte \flag
	.endm

	@ Initializes the RTC`s local time offset to the given hour and minute.
	.macro initclock hour:req, minute:req
	.byte 0x2c
	.2byte \hour
	.2byte \minute
	.endm

	@ Updates local time using the RTC and runs time based events.
	.macro dotimebasedevents
	.byte 0x2d
	.endm

	@ Sets the values of variables VAR_0x8000, VAR_0x8001, and VAR_0x8002 to the current hour, minute, and second.
	.macro gettime
	.byte 0x2e
	.endm

	@ Plays the specified sound. Only one sound may play at a time, with newer ones interrupting older ones.
	.macro playse song:req
	.byte 0x2f
	.2byte \song
	.endm

	@ Blocks script execution until the currently-playing sound (triggered by playse) finishes playing.
	.macro waitse
	.byte 0x30
	.endm

	@ Plays the fanfare specified by the song number. If the specified song is not a fanfare it will instead play the first song in sFanfares.
	.macro playfanfare song:req
	.byte 0x31
	.2byte \song
	.endm

	@ Blocks script execution until all currently-playing fanfares finish.
	.macro waitfanfare
	.byte 0x32
	.endm

	@ Plays the specified song. If save_song is TRUE, the
	@ specified song will be saved as if savebgm was called with it.
	.macro playbgm song:req, save_song:req
	.byte 0x33
	.2byte \song
	.byte \save_song
	.endm

	@ Saves the specified song to be played later. Saved music may be played when Overworld_PlaySpecialMapMusic is called. This occurs on
	@ exiting most warps.
	.macro savebgm song:req
	.byte 0x34
	.2byte \song
	.endm

	@ Crossfades the currently-playing song into the map's default song.
	.macro fadedefaultbgm
	.byte 0x35
	.endm

	@ Crossfades the currently-playing song into the specified song.
	.macro fadenewbgm song:req
	.byte 0x36
	.2byte \song
	.endm

	@ Fades out the currently-playing song.
	.macro fadeoutbgm speed:req
	.byte 0x37
	.byte \speed
	.endm

	@ Fades the previously-playing song back in.
	.macro fadeinbgm speed:req
	.byte 0x38
	.byte \speed
	.endm

	@ Helper macro for warp commands that formats their arguments.
	@ It allows warp macros to either provide 1. a valid id for which warp location to use,
	@ or 2. a pair of x/y coordinates to use. Both may be provided but at least one will be
	@ ignored by SetPlayerCoordsFromWarp. If none are provided it will use dummy arguments,
	@ and the warp will send the player to the center of the map.
	@ Examples of valid inputs for a warp command:
	@ - warp MAP, x, y
	@ - warp MAP, warpId
	@ - warp MAP
	@ - warp MAP, warpId, x, y
	.macro formatwarp map:req, a, b, c
	map \map
	.ifb \a @ No arguments provided, use dummy warpId and coords.
		.byte WARP_ID_NONE
		.2byte -1 @ x
		.2byte -1 @ y
	.else
	.ifb \b @ Only one argument provided, treat it as a warpId and use dummy coords.
		.byte \a   @ warpId
		.2byte -1  @ x
		.2byte -1  @ y
	.else
	.ifb \c @ Only two arguments provided, treat them as a coord pair and use dummy warpId.
		.byte WARP_ID_NONE
		.2byte \a  @ x
		.2byte \b  @ y
	.else @ All three arguments provided. Output them and let the warp sort out which to use.
		.byte \a  @ warpId
		.2byte \b @ x
		.2byte \c @ y
	.endif
	.endif
	.endif
	.endm


	@ Warps the player to the specified map.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warp map:req, a, b, c
	.byte 0x39
	formatwarp \map, \a, \b, \c
	.endm

	@ Warps the player to the specified map without playing a sound effect.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpsilent map:req, a, b, c
	.byte 0x3a
	formatwarp \map, \a, \b, \c
	.endm

	@ Warps the player to the specified map and plays a door opening animation before stepping upwards into it.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpdoor map:req, a, b, c
	.byte 0x3b
	formatwarp \map, \a, \b, \c
	.endm

	@ Warps the player to another map using a hole animation. If the specified map is MAP_UNDEFINED it will instead
	@ use the map set by setholewarp. In either case the target coordinates on the destination map will be the
	@ player's current position.
	.macro warphole map:req
	.byte 0x3c
	map \map
	.endm

	@ Warps the player to the specified map using a teleport effect. Effect is similar to warpspinenter but
	@ this warp has a fade out first and doesn't maintain the original facing direction.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpteleport map:req, a, b, c
	.byte 0x3d
	formatwarp \map, \a, \b, \c
	.endm

	@ Sets the warp destination to be used later.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro setwarp map:req, a, b, c
	.byte 0x3e
	formatwarp \map, \a, \b, \c
	.endm

	@ Sets the dynamic warp destination. Warps with a destination map of MAP_DYNAMIC will target this destination.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro setdynamicwarp map:req, a, b, c
	.byte 0x3f
	formatwarp \map, \a, \b, \c
	.endm

	@ Sets the destination that diving or emerging from a dive will take the player to. Note that this only
	@ applies if the current map does not have a dive/emerge connection. If it does have a corresponding
	@ map connection then that map and the player's current coordinates will be used as the destination instead.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro setdivewarp map:req, a, b, c
	.byte 0x40
	formatwarp \map, \a, \b, \c
	.endm

	@ Sets the destination that falling into a hole will take the player to.
	@ While it does accept and set the x/y coordinates and warpId, they are ultimately ignored.
	@ This is only used to set the map the player should fall to. The exact location on the
	@ map to fall to is determined by warphole.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro setholewarp map:req, a=0, b=0, c
	.byte 0x41
	formatwarp \map, \a, \b, \c
	.endm

	@ Retrieves the player's zero-indexed x- and y-coordinates in the map, and stores them in the specified variables.
	.macro getplayerxy x:req, y:req
	.byte 0x42
	.2byte \x
	.2byte \y
	.endm

	@ Retrieves the number of Pokemon in the player's party, and stores that number in VAR_RESULT.
	.macro getpartysize
	.byte 0x43
	.endm

	@ Attempts to add quantity of the specified item to the player's Bag. If the player has enough room, the item will
	@ be added and VAR_RESULT will be set to TRUE; otherwise, VAR_RESULT is set to FALSE.
	.macro additem itemId:req, quantity=1
	.byte 0x44
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Removes quantity of the specified item from the player's Bag. If the player has fewer than 'quantity' in their bag
	@ then none will be removed and VAR_RESULT will be set to FALSE. Otherwise it will be set to TRUE.
	.macro removeitem itemId:req, quantity=1
	.byte 0x45
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Checks if the player has enough space in their Bag to hold quantity more of the specified item. Sets VAR_RESULT to
	@ TRUE if there is room, or FALSE is there is no room.
	.macro checkitemspace itemId:req, quantity=1
	.byte 0x46
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Checks if the player has quantity or more of the specified item in their Bag. Sets VAR_RESULT to TRUE if the player has
	@ enough of the item, or FALSE if they have fewer than quantity of the item.
	.macro checkitem itemId:req, quantity=1
	.byte 0x47
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Checks which Bag pocket the specified item belongs in, and writes the pocket value (POCKET_*) to VAR_RESULT.
	@ This is used to show the name of the proper Bag pocket when the player receives an item via callstd.
	.macro checkitemtype itemId:req
	.byte 0x48
	.2byte \itemId
	.endm

	@ Adds quantity of the specified item to the player's PC.
	.macro addpcitem itemId:req, quantity=1
	.byte 0x49
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Checks for quantity of the specified item in the player's PC.
	.macro checkpcitem itemId:req, quantity=1
	.byte 0x4a
	.2byte \itemId
	.2byte \quantity
	.endm

	@ Adds a decoration to the player's PC.
	.macro adddecoration decoration:req
	.byte 0x4b
	.2byte \decoration
	.endm

	@ Removes a decoration from the player's PC.
	.macro removedecoration decoration:req
	.byte 0x4c
	.2byte \decoration
	.endm

	@ Checks for decoration in the player's PC.
	.macro checkdecor decoration:req
	.byte 0x4d
	.2byte \decoration
	.endm

	@ Checks if the player has enough space in their PC to hold the decoration.
	@ Sets VAR_RESULT to TRUE if there is room, or FALSE is there is no room.
	.macro checkdecorspace decoration:req
	.byte 0x4e
	.2byte \decoration
	.endm

	@ Applies the movement data at movements to the specified (localId) object. If no map is specified, then the current map is used.
	.macro applymovement localId:req, movements:req, map
		.ifb \map
			.byte 0x4f
			.2byte \localId
			.4byte \movements
		.else
			@ Really only useful if the object has followed from one map to another (e.g. Wally during the catching event).
			.byte 0x50
			.2byte \localId
			.4byte \movements
			map \map
		.endif
	.endm

	@ Blocks script execution until the movements being applied to the specified (localId) object finish.
	@ If localId is 0, then the id of the last-moved object will be used instead. If the specified object
	@ is not currently being manipulated with applymovement, then this command does nothing.
	@ If no map is specified, then the current map is used.
	.macro waitmovement localId:req, map
		.ifb \map
			.byte 0x51
			.2byte \localId
		.else
			.byte 0x52
			.2byte \localId
			map \map
		.endif
	.endm

	@ Attempts to despawn the specified (localId) object on the specified map.
	@ It also sets the object's visibility flag if it has one.
	@ If no map is specified, then the current map is used.
	.macro removeobject localId:req, map
		.ifb \map
			.byte 0x53
			.2byte \localId
		.else
			.byte 0x54
			.2byte \localId
			map \map
		.endif
	.endm

	@ Attempts to spawn the specified (localId) object the specified map.
	@ Note that unlike removeobject this does not modify the object's flag.
	@ If no map is specified, then the current map is used.
	.macro addobject localId:req, map
		.ifb \map
			.byte 0x55
			.2byte \localId
		.else
			.byte 0x56
			.2byte \localId
			map \map
		.endif
	.endm

	@ Sets the specified (localId) object's position on the current map.
	.macro setobjectxy localId:req, x:req, y:req
	.byte 0x57
	.2byte \localId
	.2byte \x
	.2byte \y
	.endm

	@ Sets the specified object's invisibility to FALSE.
	.macro showobjectat localId:req, map:req
	.byte 0x58
	.2byte \localId
	map \map
	.endm

	@ Sets the specified object's invisibility to TRUE.
	.macro hideobjectat localId:req, map:req
	.byte 0x59
	.2byte \localId
	map \map
	.endm

	@ Turns the currently selected object (if there is one) to face the player.
	.macro faceplayer
	.byte 0x5a
	.endm

	@ Turns the specified object in the specified direction.
	.macro turnobject localId:req, direction:req
	.byte 0x5b
	.2byte \localId
	.byte \direction
	.endm

	@ Configures the arguments for a trainer battle, then jumps to the appropriate script in scripts/trainer_battle.inc
	.macro trainerbattle type:req, trainer:req, local_id:req, pointer1:req, pointer2, pointer3, pointer4
	.byte 0x5c
	.byte \type
	.2byte \trainer
	.2byte \local_id
	.if \type == TRAINER_BATTLE_SINGLE
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ event script
	.elseif \type == TRAINER_BATTLE_CONTINUE_SCRIPT
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ event script
	.elseif \type == TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT
		.4byte \pointer1 @ text
	.elseif \type == TRAINER_BATTLE_DOUBLE
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
	.elseif \type == TRAINER_BATTLE_REMATCH
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
		.4byte \pointer4 @ event script
	.elseif \type == TRAINER_BATTLE_REMATCH_DOUBLE
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
	.elseif \type == TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
		.4byte \pointer4 @ event script
	.elseif \type == TRAINER_BATTLE_PYRAMID
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == TRAINER_BATTLE_SET_TRAINER_A
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == TRAINER_BATTLE_SET_TRAINER_B
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == TRAINER_BATTLE_HILL
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.endif
	.endm

	NO_MUSIC = FALSE

	@ Starts a single trainer battle. Takes a trainer, intro text, loss text, and an optional event script.
	@ When used with an event script, you can also pass in an optional flag to disable music
	.macro trainerbattle_single trainer:req, intro_text:req, lose_text:req, event_script=FALSE, music=TRUE
	.if \event_script == FALSE
	trainerbattle TRAINER_BATTLE_SINGLE, \trainer, 0, \intro_text, \lose_text
	.elseif \music == TRUE
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, \trainer, 0, \intro_text, \lose_text, \event_script
	.else
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_NO_MUSIC, \trainer, 0, \intro_text, \lose_text, \event_script
	.endif
	.endm

	@ Starts a double trainer battle. Takes a trainer, intro text, loss text, text for when you have too few pokemon
	@ and an optional event script. When used with an event script you can pass in an optional flag to disable music
	.macro trainerbattle_double trainer:req, intro_text:req, lose_text:req, not_enough_pkmn_text:req, event_script=FALSE, music=TRUE
	.if \event_script == FALSE
	trainerbattle TRAINER_BATTLE_DOUBLE, \trainer, 0, \intro_text, \lose_text, \not_enough_pkmn_text
	.elseif \music == TRUE
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE, \trainer, 0, \intro_text, \lose_text, \not_enough_pkmn_text, \event_script
	.else
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT_DOUBLE_NO_MUSIC, \trainer, 0, \intro_text, \lose_text, \not_enough_pkmn_text, \event_script
	.endif
	.endm

	@ Starts a rematch battle. Takes a trainer, intro text and loss text
	.macro trainerbattle_rematch trainer:req, intro_text:req, lose_text:req
	trainerbattle TRAINER_BATTLE_REMATCH, \trainer, 0, \intro_text, \lose_text
	.endm

	@ Starts a rematch double battle. Takes a trainer, intro text, loss text, and text for when you have too few pokemon
	.macro trainerbattle_rematch_double trainer:req, intro_text:req, lose_text:req, not_enough_pkmn_text:req
	trainerbattle TRAINER_BATTLE_REMATCH_DOUBLE, \trainer, 0, \intro_text, \lose_text, \not_enough_pkmn_text
	.endm

	@ Starts a trainer battle, skipping intro text. Takes a trainer and loss text
	.macro trainerbattle_no_intro trainer:req, lose_text:req
	trainerbattle TRAINER_BATTLE_SINGLE_NO_INTRO_TEXT, \trainer, 0, \lose_text
	.endm

	@ Starts a double battle with the player against two trainers
	@ Takes two trainers and defeat text for each
	.macro trainerbattle_two_trainers trainer_a:req, lose_text_a:req, trainer_b:req, lose_text_b:req
	.byte 0x5c
	.byte TRAINER_BATTLE_TWO_TRAINERS_NO_INTRO
	.2byte \trainer_a
	.4byte \lose_text_a
	.2byte \trainer_b
	.4byte \lose_text_b
	.endm

	@ Starts a trainer battle using the battle information stored in RAM (usually by the scripts in trainer_battle.inc, which
	@ are run by trainerbattle), and blocks script execution until the battle finishes.
	.macro dotrainerbattle
	.byte 0x5d
	.endm

	@ Goes to address after the trainerbattle command (called by the battle functions, see battle_setup.c)
	.macro gotopostbattlescript
	.byte 0x5e
	.endm

	@ Goes to address specified in the trainerbattle command (called by the battle functions, see battle_setup.c)
	.macro gotobeatenscript
	.byte 0x5f
	.endm

	@ Checks if the trainer has been defeated by the player (by comparing the flag 'trainer + TRAINER_FLAGS_START' to TRUE).
	.macro checktrainerflag trainer:req
	.byte 0x60
	.2byte \trainer
	.endm

	@ Sets the trainer flag (trainer + TRAINER_FLAGS_START) to TRUE (defeated).
	.macro settrainerflag trainer:req
	.byte 0x61
	.2byte \trainer
	.endm

	@ Sets the trainer flag (trainer + TRAINER_FLAGS_START) to FALSE (not defeated).
	.macro cleartrainerflag trainer:req
	.byte 0x62
	.2byte \trainer
	.endm

	@ Sets the coordinates of an object's template, so that if the sprite goes off screen
	@ it'll still be there when it comes back on screen.
	.macro setobjectxyperm localId:req, x:req, y:req
	.byte 0x63
	.2byte \localId
	.2byte \x
	.2byte \y
	.endm

	@ Copies a live object event's xy position to its template, so that if the sprite goes off screen
	@ it'll still be there when it comes back on screen.
	.macro copyobjectxytoperm localId:req
	.byte 0x64
	.2byte \localId
	.endm

	@ Sets the movement type (MOVEMENT_TYPE_*) for an object's template.
	.macro setobjectmovementtype localId:req, movementType:req
	.byte 0x65
	.2byte \localId
	.byte \movementType
	.endm

	@ If a standard message box (or its text) is being drawn on-screen, this command blocks script execution until the
	@ box and its text have been fully drawn.
	.macro waitmessage
	.byte 0x66
	.endm

	@ Starts displaying a standard message box containing the specified text. If text is a pointer, then the string at
	@ that offset will be loaded and used. If text is NULL, then the value of script data 0 will be treated as
	@ a pointer to the text. The 'loadword 0' in msgbox sets this value, for instance.
	.macro message text:req
	.byte 0x67
	.4byte \text
	.endm

	@ Closes the current message box.
	.macro closemessage
	.byte 0x68
	.endm

	@ Freezes all objects immediately except the player. The player is frozen once their movement is finished.
	.macro lockall
	.byte 0x69
	.endm

	@ Freezes all objects immediately except the player and the selected object. The player and selected object are frozen once their movement is finished.
	.macro lock
	.byte 0x6a
	.endm

	@ Resumes normal movement for all objects on-screen, and closes any standard message boxes that are still open.
	.macro releaseall
	.byte 0x6b
	.endm

	@ Resumes normal movement for the selected object (if there is one) and the player. Also closes any standard message boxes that are still open.
	.macro release
	.byte 0x6c
	.endm

	@ Blocks script execution until the player presses the A or B button.
	.macro waitbuttonpress
	.byte 0x6d
	.endm

	@ Displays a YES/NO multichoice box at the specified coordinates, and blocks script execution until the user makes a selection.
	@ Their selection is stored in VAR_RESULT as NO (0) or YES (1). Pressing B is equivalent to answering NO
	.macro yesnobox x:req, y:req
	.byte 0x6e
	.byte \x
	.byte \y
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made.
	@ Lists of options are predefined (sMultichoiceLists) and the one to be used is specified with multichoiceId.
	@ If ignoreBPress is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoice x:req, y:req, multichoiceId:req, ignoreBPress:req
	.byte 0x6f
	.byte \x
	.byte \y
	.byte \multichoiceId
	.byte \ignoreBPress
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made.
	@ Lists of options are predefined (sMultichoiceLists) and the one to be used is specified with multichoiceId.
	@ The default argument determines the initial position of the cursor when the box is first opened; it is zero-indexed, and if it is too large, it is treated as 0.
	@ If ignoreBPress is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoicedefault x:req, y:req, multichoiceId:req, default:req, ignoreBPress:req
	.byte 0x70
	.byte \x
	.byte \y
	.byte \multichoiceId
	.byte \default
	.byte \ignoreBPress
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made.
	@ Lists of options are predefined (sMultichoiceLists) and the one to be used is specified with multichoiceId.
	@ The per_row argument determines how many list items will be shown on a single row of the box.
	@ If ignoreBPress is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoicegrid x:req, y:req, multichoiceId:req, per_row:req, ignoreBPress:req
	.byte 0x71
	.byte \x
	.byte \y
	.byte \multichoiceId
	.byte \per_row
	.byte \ignoreBPress
	.endm

	@ Nopped in Emerald.
	.macro drawbox
	.byte 0x72
	.endm

	@ Nopped in Emerald, but still consumes parameters.
	.macro erasebox left:req, top:req, right:req, bottom:req
	.byte 0x73
	.byte \left
	.byte \top
	.byte \right
	.byte \bottom
	.endm

	@ Nopped in Emerald, but still consumes parameters.
	.macro drawboxtext left:req, top:req, multichoiceId:req, ignoreBPress:req
	.byte 0x74
	.byte \left
	.byte \top
	.byte \multichoiceId
	.byte \ignoreBPress
	.endm

	@ Displays a box containing the front sprite for the specified Pokemon species.
	.macro showmonpic species:req, x:req, y:req
	.byte 0x75
	.2byte \species
	.byte \x
	.byte \y
	.endm

	@ Hides the box displayed by showmonpic.
	.macro hidemonpic
	.byte 0x76
	.endm

	@ Draws an image of the winner of the contest. winnerId is any CONTEST_WINNER_* constant.
	.macro showcontestpainting winnerId:req
	.byte 0x77
	.byte \winnerId
	.endm

	@ Displays the given string as braille text in a standard message box. The string should use the .braille directive
	@ to convert text to braille, and be preceded by brailleformat. The brailleformat data is skipped over (in RS, these
	@ bytes determined the box's size and position, but in Emerald these are calculated automatically).
	.macro braillemessage text:req
	.byte 0x78
	.4byte \text
	.endm

	@ Formatting for the braille window, to be put at the start of a pointer used by braillemessage.
	@ These are from RS and are ignored in Emerald (see ScrCmd_braillemessage, and comment above)
	.macro brailleformat winLeft:req, winTop:req, winRight:req, winBottom:req, textLeft:req, textTop:req
	.byte \winLeft
	.byte \winTop
	.byte \winRight
	.byte \winBottom
	.byte \textLeft
	.byte \textTop
	.endm

	@ Gives the player a Pokémon of the specified species and level, and allows to customize extra parameters.
	@ VAR_RESULT will be set to MON_GIVEN_TO_PARTY, MON_GIVEN_TO_PC, or MON_CANT_GIVE depending on the outcome.
	.macro givemon species:req, level:req, item, ball, nature, abilityNum, gender, hpEv, atkEv, defEv, speedEv, spAtkEv, spDefEv, hpIv, atkIv, defIv, speedIv, spAtkIv, spDefIv, move1, move2, move3, move4, isShiny, ggMaxFactor, teraType
	callnative ScrCmd_createmon
	.byte 0
	.byte 6	@ PARTY_SIZE - assign to first empty slot
	.set givemon_flags, 0
	.2byte \species
	.2byte \level
	.ifnb \item; .set givemon_flags, givemon_flags | (1 << 0); .endif
	.ifnb \ball; .set givemon_flags, givemon_flags | (1 << 1); .endif
	.ifnb \nature; .set givemon_flags, givemon_flags | (1 << 2); .endif
	.ifnb \abilityNum; .set givemon_flags, givemon_flags | (1 << 3); .endif
	.ifnb \gender; .set givemon_flags, givemon_flags | (1 << 4); .endif
	.ifnb \hpEv; .set givemon_flags, givemon_flags | (1 << 5); .endif
	.ifnb \atkEv; .set givemon_flags, givemon_flags | (1 << 6); .endif
	.ifnb \defEv; .set givemon_flags, givemon_flags | (1 << 7); .endif
	.ifnb \speedEv; .set givemon_flags, givemon_flags | (1 << 8); .endif
	.ifnb \spAtkEv; .set givemon_flags, givemon_flags | (1 << 9); .endif
	.ifnb \spDefEv; .set givemon_flags, givemon_flags | (1 << 10); .endif
	.ifnb \hpIv; .set givemon_flags, givemon_flags | (1 << 11); .endif
	.ifnb \atkIv; .set givemon_flags, givemon_flags | (1 << 12); .endif
	.ifnb \defIv; .set givemon_flags, givemon_flags | (1 << 13); .endif
	.ifnb \speedIv; .set givemon_flags, givemon_flags | (1 << 14); .endif
	.ifnb \spAtkIv; .set givemon_flags, givemon_flags | (1 << 15); .endif
	.ifnb \spDefIv; .set givemon_flags, givemon_flags | (1 << 16); .endif
	.ifnb \move1; .set givemon_flags, givemon_flags | (1 << 17); .endif
	.ifnb \move2; .set givemon_flags, givemon_flags | (1 << 18); .endif
	.ifnb \move3; .set givemon_flags, givemon_flags | (1 << 19); .endif
	.ifnb \move4; .set givemon_flags, givemon_flags | (1 << 20); .endif
	.ifnb \isShiny; .set givemon_flags, givemon_flags | (1 << 21); .endif
	.ifnb \ggMaxFactor; .set givemon_flags, givemon_flags | (1 << 22); .endif
	.ifnb \teraType; .set givemon_flags, givemon_flags | (1 << 23); .endif
	.4byte givemon_flags
	.ifnb \item; .2byte \item; .endif
	.ifnb \ball; .2byte \ball; .endif
	.ifnb \nature; .2byte \nature; .endif
	.ifnb \abilityNum; .2byte \abilityNum; .endif
	.ifnb \gender; .2byte \gender; .endif
	.ifnb \hpEv; .2byte \hpEv; .endif
	.ifnb \atkEv; .2byte \atkEv; .endif
	.ifnb \defEv; .2byte \defEv; .endif
	.ifnb \speedEv; .2byte \speedEv; .endif
	.ifnb \spAtkEv; .2byte \spAtkEv; .endif
	.ifnb \spDefEv; .2byte \spDefEv; .endif
	.ifnb \hpIv; .2byte \hpIv; .endif
	.ifnb \atkIv; .2byte \atkIv; .endif
	.ifnb \defIv; .2byte \defIv; .endif
	.ifnb \speedIv; .2byte \speedIv; .endif
	.ifnb \spAtkIv; .2byte \spAtkIv; .endif
	.ifnb \spDefIv; .2byte \spDefIv; .endif
	.ifnb \move1; .2byte \move1; .endif
	.ifnb \move2; .2byte \move2; .endif
	.ifnb \move3; .2byte \move3; .endif
	.ifnb \move4; .2byte \move4; .endif
	.ifnb \isShiny; .2byte \isShiny; .endif
	.ifnb \ggMaxFactor; .2byte \ggMaxFactor; .endif
	.ifnb \teraType; .2byte \teraType; .endif
	.endm

	@ creates a mon for a given party and slot
	@ otherwise
	.macro createmon side:req, slot:req, species:req, level:req, item, ball, nature, abilityNum, gender, hpEv, atkEv, defEv, speedEv, spAtkEv, spDefEv, hpIv, atkIv, defIv, speedIv, spAtkIv, spDefIv, move1, move2, move3, move4, isShiny, ggMaxFactor, teraType
	callnative ScrCmd_createmon
	.byte \side	 @ 0 - player, 1 - opponent
	.byte \slot	 @ 0-5
	.set givemon_flags, 0
	.2byte \species
	.2byte \level
	.ifnb \item; .set givemon_flags, givemon_flags | (1 << 0); .endif
	.ifnb \ball; .set givemon_flags, givemon_flags | (1 << 1); .endif
	.ifnb \nature; .set givemon_flags, givemon_flags | (1 << 2); .endif
	.ifnb \abilityNum; .set givemon_flags, givemon_flags | (1 << 3); .endif
	.ifnb \gender; .set givemon_flags, givemon_flags | (1 << 4); .endif
	.ifnb \hpEv; .set givemon_flags, givemon_flags | (1 << 5); .endif
	.ifnb \atkEv; .set givemon_flags, givemon_flags | (1 << 6); .endif
	.ifnb \defEv; .set givemon_flags, givemon_flags | (1 << 7); .endif
	.ifnb \speedEv; .set givemon_flags, givemon_flags | (1 << 8); .endif
	.ifnb \spAtkEv; .set givemon_flags, givemon_flags | (1 << 9); .endif
	.ifnb \spDefEv; .set givemon_flags, givemon_flags | (1 << 10); .endif
	.ifnb \hpIv; .set givemon_flags, givemon_flags | (1 << 11); .endif
	.ifnb \atkIv; .set givemon_flags, givemon_flags | (1 << 12); .endif
	.ifnb \defIv; .set givemon_flags, givemon_flags | (1 << 13); .endif
	.ifnb \speedIv; .set givemon_flags, givemon_flags | (1 << 14); .endif
	.ifnb \spAtkIv; .set givemon_flags, givemon_flags | (1 << 15); .endif
	.ifnb \spDefIv; .set givemon_flags, givemon_flags | (1 << 16); .endif
	.ifnb \move1; .set givemon_flags, givemon_flags | (1 << 17); .endif
	.ifnb \move2; .set givemon_flags, givemon_flags | (1 << 18); .endif
	.ifnb \move3; .set givemon_flags, givemon_flags | (1 << 19); .endif
	.ifnb \move4; .set givemon_flags, givemon_flags | (1 << 20); .endif
	.ifnb \isShiny; .set givemon_flags, givemon_flags | (1 << 21); .endif
	.ifnb \ggMaxFactor; .set givemon_flags, givemon_flags | (1 << 22); .endif
	.ifnb \teraType; .set givemon_flags, givemon_flags | (1 << 23); .endif
	.4byte givemon_flags
	.ifnb \item; .2byte \item; .endif
	.ifnb \ball; .2byte \ball; .endif
	.ifnb \nature; .2byte \nature; .endif
	.ifnb \abilityNum; .2byte \abilityNum; .endif
	.ifnb \gender; .2byte \gender; .endif
	.ifnb \hpEv; .2byte \hpEv; .endif
	.ifnb \atkEv; .2byte \atkEv; .endif
	.ifnb \defEv; .2byte \defEv; .endif
	.ifnb \speedEv; .2byte \speedEv; .endif
	.ifnb \spAtkEv; .2byte \spAtkEv; .endif
	.ifnb \spDefEv; .2byte \spDefEv; .endif
	.ifnb \hpIv; .2byte \hpIv; .endif
	.ifnb \atkIv; .2byte \atkIv; .endif
	.ifnb \defIv; .2byte \defIv; .endif
	.ifnb \speedIv; .2byte \speedIv; .endif
	.ifnb \spAtkIv; .2byte \spAtkIv; .endif
	.ifnb \spDefIv; .2byte \spDefIv; .endif
	.ifnb \move1; .2byte \move1; .endif
	.ifnb \move2; .2byte \move2; .endif
	.ifnb \move3; .2byte \move3; .endif
	.ifnb \move4; .2byte \move4; .endif
	.ifnb \isShiny; .2byte \isShiny; .endif
	.ifnb \ggMaxFactor; .2byte \ggMaxFactor; .endif
	.ifnb \teraType; .2byte \teraType; .endif
	.endm

	@ Gives the player an Egg of the specified species.
	@ VAR_RESULT will be set to MON_GIVEN_TO_PARTY, MON_GIVEN_TO_PC, or MON_CANT_GIVE depending on the outcome.
	.macro giveegg species:req
	.byte 0x7a
	.2byte \species
	.endm

	@ Replaces the move at 'slot' of the Pokémon in the player's party at 'partyIndex' with the specified move.
	@ If a value greater than PARTY_SIZE is given for partyIndex it will use the last Pokémon in the party instead.
	@ Note that this means in vanilla a value equal to PARTY_SIZE for partyIndex will go out of bounds.
	.macro setmonmove partyIndex:req, slot:req, move:req
	.byte 0x7b
	.byte \partyIndex
	.byte \slot
	.2byte \move
	.endm

	@ Checks if at least one Pokemon in the player's party knows the specified move. If so, VAR_RESULT is set to the
	@ (zero-indexed) slot number of the first Pokemon that knows the move. If not, VAR_RESULT is set to PARTY_SIZE.
	@ VAR_0x8004 is also set to this Pokemon's species.
	.macro checkpartymove move:req
	.byte 0x7c
	.2byte \move
	.endm

	@ Converts STR_VAR_1, STR_VAR_2, or STR_VAR_3 to its corresponding index into sScriptStringVars (0, 1, or 2).
	@ If given anything else it will output it directly.
	@ Note: Because the STR_VAR_# arguments given to this macro are not part of a processed string they are not
	@       replaced with their charmap values, they are just passed as the literal characters "STR_VAR_#".
	.macro stringvar id:req
	.if \id == STR_VAR_1
		.byte 0
	.elseif \id == STR_VAR_2
		.byte 1
	.elseif \id == STR_VAR_3
		.byte 2
	.else
		.byte \id
	.endif
	.endm

	@ Writes the name of the given Pokemon species to the specified buffer.
	.macro bufferspeciesname stringVarId:req, species:req
	.byte 0x7d
	stringvar \stringVarId
	.2byte \species
	.endm

	@ Writes the name of the species of the first Pokemon in the player's party to the specified buffer.
	.macro bufferleadmonspeciesname stringVarId:req
	.byte 0x7e
	stringvar \stringVarId
	.endm

	@ Writes the nickname of the Pokemon in 'slot' (zero-indexed) of the player's party to the specified buffer.
	@ If an empty or invalid slot is specified, ten spaces ("") are written to the buffer.
	.macro bufferpartymonnick stringVarId:req, slot:req
	.byte 0x7f
	stringvar \stringVarId
	.2byte \slot
	.endm

	@ Writes the name of the specified item to the specified buffer. If itemId is >= ITEMS_COUNT,
	@ then the name of ITEM_NONE ("????????") is buffered instead.
	.macro bufferitemname stringVarId:req, item:req
	.byte 0x80
	stringvar \stringVarId
	.2byte \item
	.endm

	@ Writes the name of the specified decoration to the specified buffer.
	.macro bufferdecorationname stringVarId:req, decoration:req
	.byte 0x81
	stringvar \stringVarId
	.2byte \decoration
	.endm

	@ Writes the name of the specified move to the specified buffer.
	.macro buffermovename stringVarId:req, move:req
	.byte 0x82
	stringvar \stringVarId
	.2byte \move
	.endm

	@ Converts the value of input to a decimal string, and writes that string to the specified buffer.
	.macro buffernumberstring stringVarId:req, input:req
	.byte 0x83
	stringvar \stringVarId
	.2byte \input
	.endm

	@ Writes the given standard string (STDSTRING_*) to the specified buffer. Invalid std string ids are not handled.
	.macro bufferstdstring stringVarId:req, index:req
	.byte 0x84
	stringvar \stringVarId
	.2byte \index
	.endm

	@ Copies the string at the given pointer to the specified buffer.
	.macro bufferstring stringVarId:req, text:req
	.byte 0x85
	stringvar \stringVarId
	.4byte \text
	.endm

	@ Opens the Pokemart system, offering the specified products for sale.
	@ Products should be a list of .2byte item values preceded by an .align 2
	.macro pokemart products:req
	.byte 0x86
	.4byte \products
	.endm

	@ Opens the Pokemart system and treats the list of items as decorations.
	@ Products should be a list of .2byte decoration values preceded by an .align 2
	.macro pokemartdecoration products:req
	.byte 0x87
	.4byte \products
	.endm

	@ Identical to pokemartdecoration, but with slight changes to the clerk dialogue. See uses of MART_TYPE_DECOR2.
	.macro pokemartdecoration2 products:req
	.byte 0x88
	.4byte \products
	.endm

	@ Starts up the slot machine minigame. id is a SLOT_MACHINE_* value that influences probabilities of certain reel outcomes.
	.macro playslotmachine id:req
	.byte 0x89
	.2byte \id
	.endm

	@ Sets a berry tree's berry and growth stage. treeId is any BERRY_TREE_* constant (an index into berryTrees in SaveBlock1),
	@ berry is any ITEM_TO_BERRY(ITEM_BERRY_NAME) value, and growthStage is any BERRY_STAGE_* constant.
	.macro setberrytree treeId:req, berry:req, growthStage:req
	.byte 0x8a
	.byte \treeId
	.byte \berry
	.byte \growthStage
	.endm

	@ Opens the party menu to select a Pokemon for a contest.
	.macro choosecontestmon
	.byte 0x8b
	.endm

	@ Starts the appeals round of a contest.
	.macro startcontest
	.byte 0x8c
	.endm

	@ Shows the results screen of a contest.
	.macro showcontestresults
	.byte 0x8d
	.endm

	@ Starts communication to initialize a link contest.
	.macro contestlinktransfer
	.byte 0x8e
	.endm

	@ Stores a random integer between 0 and limit (exclusive of limit) in VAR_RESULT.
	.macro random limit:req
	.byte 0x8f
	.2byte \limit
	.endm

	@ Adds value to the player's money. If adding 'value' money would exceed MAX_MONEY, the player's money is set to MAX_MONEY.
	@ If 'disable' is set to anything but 0 then this command does nothing.
	.macro addmoney value:req, disable=0
	.byte 0x90
	.4byte \value
	.byte \disable
	.endm

	@ Subtracts value from the player's money. If the player has less than 'value' money, their money is set to 0.
	@ If 'disable' is set to anything but 0 then this command does nothing.
	.macro removemoney value:req, disable=0
	.byte 0x91
	.4byte \value
	.byte \disable
	.endm

	@ Checks if the player has money >= value. VAR_RESULT is set to TRUE if the player has enough money, or FALSE if they do not.
	@ If 'disable' is set to anything but 0 then this command does nothing.
	.macro checkmoney value:req, disable=0
	.byte 0x92
	.4byte \value
	.byte \disable
	.endm

	@ Creates a window showing how much money the player has.
	@ If 'disable' is set to anything but 0 then this command does nothing.
	.macro showmoneybox x:req, y:req, disable=0
	.byte 0x93
	.byte \x
	.byte \y
	.byte \disable
	.endm

	@ Destroys the window created by showmoneybox. Consumption of the x and y arguments was dummied out.
	.macro hidemoneybox
	.byte 0x94
	.byte 0  @ \x
	.byte 0  @ \y
	.endm

	@ Updates the window created by showmoneybox. Consumption of the x and y arguments was dummied out.
	@ If 'disable' is set to anything but 0 then this command does nothing.
	.macro updatemoneybox disable=0
	.byte 0x95
	.byte 0  @ \x
	.byte 0  @ \y
	.byte \disable
	.endm

	@ Gets whether the effects of the specified PokeNews program are active. newsKind is a POKENEWS_* constant.
	.macro getpokenewsactive newsKind:req
	.byte 0x96
	.2byte \newsKind
	.endm

	@ Fades the screen to and from black and white. Modes are FADE_(TO/FROM)_(WHITE/BLACK)
	.macro fadescreen mode:req
	.byte 0x97
	.byte \mode
	.endm

	@ Fades the screen to and from black and white. Modes are FADE_(TO/FROM)_(WHITE/BLACK)
	.macro fadescreenspeed mode:req, speed:req
	.byte 0x98
	.byte \mode
	.byte \speed
	.endm

	@ Sets the flash level. A level of 0 is fully bright, a level of 1 is the largest flash radius, a level
	@ of 7 is the smallest flash radius, a level of 8 is fully black.
	.macro setflashlevel level:req
	.byte 0x99
	.2byte \level
	.endm

	@ Animates the flash radius from its current size to the size it would be at the specified level.
	@ Note that this does not actually change the current flash level. It's typically used just before a setflashlevel.
	.macro animateflash level:req
	.byte 0x9a
	.byte \level
	.endm

	@ Automatically scrolls through the message without player input and at a fixed speed.
	.macro messageautoscroll text:req
	.byte 0x9b
	.4byte \text
	.endm

	@ Executes the specified field effect animation (FLDEFF_*).
	.macro dofieldeffect animation:req
	.byte 0x9c
	.2byte \animation
	.endm

	@ Sets the field effect argument at index 'argNum' to 'value.'
	.macro setfieldeffectargument argNum:req, value:req
	.byte 0x9d
	.byte \argNum
	.2byte \value
	.endm

	@ Blocks script execution until all playing field effect animations complete.
	.macro waitfieldeffect animation:req
	.byte 0x9e
	.2byte \animation
	.endm

	@ Sets which healing location (HEAL_LOCATION_*) the player will return to if all of the Pokemon in their party faint.
	.macro setrespawn heallocation:req
	.byte 0x9f
	.2byte \heallocation
	.endm

	@ Checks the player's gender. Stores the result (MALE (0) or FEMALE (1)) in VAR_RESULT.
	.macro checkplayergender
	.byte 0xa0
	.endm

	@ Plays the cry of the given species. Mode is any CRY_MODE_* constant.
	@ You can use waitmoncry to block script execution until the cry finishes.
	.macro playmoncry species:req, mode:req
	.byte 0xa1
	.2byte \species
	.2byte \mode
	.endm

	@ Set the metatile at (x, y) on the current map to the given metatile and impassability.
	.macro setmetatile x:req, y:req, metatileId:req, impassable:req
	.byte 0xa2
	.2byte \x
	.2byte \y
	.2byte \metatileId
	.2byte \impassable
	.endm

	@ Queues a weather change to the default weather for the map.
	.macro resetweather
	.byte 0xa3
	.endm

	@ Queues a weather change to type weather.
	.macro setweather type:req
	.byte 0xa4
	.2byte \type
	.endm

	@ Executes the weather change queued with resetweather or setweather. The current weather will smoothly fade into the queued weather.
	.macro doweather
	.byte 0xa5
	.endm

	@ Enables the overworld task specified by stepCbId (STEP_CB_*). Only 1 can be active at a time. See src/field_tasks.c for more.
	.macro setstepcallback stepCbId:req
	.byte 0xa6
	.byte \stepCbId
	.endm

	@ Sets the current map layout to the one specified by index (LAYOUT_*).
	@ This should be done before the layout is loaded, typically in the ON_TRANSITION map script.
	.macro setmaplayoutindex index:req
	.byte 0xa7
	.2byte \index
	.endm

	@ Sets the specified object's sprite's subpriority, and sets fixedPriority to TRUE.
	@ Only used to hide the player and Briney behind the boat.
	.macro setobjectsubpriority localId:req, map:req, subpriority:req
	.byte 0xa8
	.2byte \localId
	map \map
	.byte \subpriority
	.endm

	@ Sets the specified object's fixedPriority to FALSE. Does not change the subpriority field.
	.macro resetobjectsubpriority localId:req, map:req
	.byte 0xa9
	.2byte \localId
	map \map
	.endm

	@ Creates a sprite with object graphics. Used when creating large groups of static NPCs that exceed
	@ the object event limit (e.g. Contest / Battle Dome audiences and Union Room group members).
	@ The specified id can be used to refer to the sprite again later with turnvobject.
	.macro createvobject graphicsId:req, id:req, x:req, y:req, elevation=3, direction=DIR_SOUTH
	.byte 0xaa
	.2byte \graphicsId
	.byte \id
	.2byte \x
	.2byte \y
	.byte \elevation
	.byte \direction
	.endm

	@ Turns a sprite created with createvobject.
	.macro turnvobject id:req, direction:req
	.byte 0xab
	.byte \id
	.byte \direction
	.endm

	@ Opens the door metatile at (x, y) with an animation.
	.macro opendoor x:req, y:req
	.byte 0xac
	.2byte \x
	.2byte \y
	.endm

	@ Closes the door metatile at (x, y) with an animation.
	.macro closedoor x:req, y:req
	.byte 0xad
	.2byte \x
	.2byte \y
	.endm

	@ Waits for the door animation started with opendoor or closedoor to finish.
	.macro waitdooranim
	.byte 0xae
	.endm

	@ Sets the door metatile at (x, y) to be open without an animation.
	.macro setdooropen x:req, y:req
	.byte 0xaf
	.2byte \x
	.2byte \y
	.endm

	@ Sets the door metatile at (x, y) to be closed without an animation.
	.macro setdoorclosed x:req, y:req
	.byte 0xb0
	.2byte \x
	.2byte \y
	.endm

	@ Consumes its parameters and does nothing. It is implemented but unused in Ruby/Sapphire.
	.macro addelevmenuitem a:req, b:req, c:req, d:req
	.byte 0xb1
	.byte \a
	.2byte \b
	.2byte \c
	.2byte \d
	.endm

	@ Does nothing. It is implemented but unused in Ruby/Sapphire.
	.macro showelevmenu
	.byte 0xb2
	.endm

	@ Gets the number of coins the player has and stores it in the variable 'out'.
	.macro checkcoins out:req
	.byte 0xb3
	.2byte \out
	.endm

	@ Gives 'count' coins to the player, up to a total of MAX_COINS.
	@ If the player already has MAX_COINS then VAR_RESULT is set to TRUE, otherwise it is set to FALSE.
	.macro addcoins count:req
	.byte 0xb4
	.2byte \count
	.endm

	@ Takes 'count' coins from the player.
	@ If the player has fewer than 'count' coins then no coins are taken and VAR_RESULT is set to TRUE.
	@ Otherwise VAR_RESULT is set to FALSE.
	.macro removecoins count:req
	.byte 0xb5
	.2byte \count
	.endm

	@ Prepares to start a wild battle against a 'species' at 'level' holding 'item'.
	@ If 'species2' is something other than SPECIES_NONE, then the battle is a double battle
	@ that is also against 'species2' at 'level2' holding 'item2'.
	@ Running this command will not affect normal wild battles. You start the prepared battle with dowildbattle.
	@ If the player only has one Pokemon, a scripted double battle will be buggy.
	.macro setwildbattle species:req, level:req, item=ITEM_NONE, species2=SPECIES_NONE, level2=0, item2=ITEM_NONE
	.byte 0xb6
	.2byte \species
	.byte \level
	.2byte \item
	.2byte \species2
	.byte \level2
	.2byte \item2
	.endm

	@ Starts a wild battle against the Pokemon generated by setwildbattle. Blocks script execution until the battle finishes.
	.macro dowildbattle
	.byte 0xb7
	.endm

	@ Sets a relative address to be used by the other vcommands as part of a Mystery Gift script.
	.macro setvaddress pointer:req
	.byte 0xb8
	.4byte \pointer
	.endm

	@ Equivalent to goto using the relative address set by setvaddress.
	.macro vgoto destination:req
	.byte 0xb9
	.4byte \destination
	.endm

	@ Equivalent to call using the relative address set by setvaddress.
	.macro vcall destination:req
	.byte 0xba
	.4byte \destination
	.endm

	@ Equivalent to goto_if using the relative address set by setvaddress.
	.macro vgoto_if condition:req, destination:req
	.byte 0xbb
	.byte \condition
	.4byte \destination
	.endm

	@ Equivalent to call_if using the relative address set by setvaddress.
	.macro vcall_if condition:req, destination:req
	.byte 0xbc
	.byte \condition
	.4byte \destination
	.endm

	@ Equivalent to message using the relative address set by setvaddress.
	.macro vmessage text:req
	.byte 0xbd
	.4byte \text
	.endm

	@ Expands the given text at the pointer (- the relative address set by setvaddress) into gStringVar4
	.macro vbuffermessage text:req
	.byte 0xbe
	.4byte \text
	.endm

	@ Equivalent to bufferstring using the relative address set by setvaddress.
	.macro vbufferstring stringVarIndex:req, text:req
	.byte 0xbf
	stringvar \stringVarIndex
	.4byte \text
	.endm

	@ Create a window showing how many Coins the player has.
	.macro showcoinsbox x:req, y:req
	.byte 0xc0
	.byte \x
	.byte \y
	.endm

	@ Destroys the window created by showcoins. It consumes its arguments but doesn't use them.
	.macro hidecoinsbox x:req, y:req
	.byte 0xc1
	.byte \x
	.byte \y
	.endm

	@ Updates the window created by showcoins. It consumes its arguments but doesn't use them.
	.macro updatecoinsbox x:req, y:req
	.byte 0xc2
	.byte \x
	.byte \y
	.endm

	@ Increases the value of the specified game stat by 1. The maximum value of a stat is 0xFFFFFF. See include/constants/game_stat.h
	.macro incrementgamestat stat:req
	.byte 0xc3
	.byte \stat
	.endm

	@ Sets the destination that using an Escape Rope or Dig will take the player to.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro setescapewarp map:req, a, b, c
	.byte 0xc4
	formatwarp \map, \a, \b, \c
	.endm

	@ Blocks script execution until cry finishes.
	.macro waitmoncry
	.byte 0xc5
	.endm

	@ Writes the name of the specified PC box to the specified buffer.
	.macro bufferboxname stringVarId:req, box:req
	.byte 0xc6
	stringvar \stringVarId
	.2byte \box
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro textcolor color:req
	.byte 0xc7
	.byte \color
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro loadhelp text:req
	.byte 0xc8
	.4byte \text
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro unloadhelp
	.byte 0xc9
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro signmsg
	.byte 0xca
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro normalmsg
	.byte 0xcb
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro comparehiddenvar a:req, value:req
	.byte 0xcc
	.byte \a
	.4byte \value
	.endm

	@ Sets the modernFatefulEncounter bit for the Pokemon in the specified slot of the player's party.
	.macro setmodernfatefulencounter slot:req
	.byte 0xcd
	.2byte \slot
	.endm

	@ Checks if the modernFatefulEncounter bit is set for the Pokemon in the specified slot of the player's party. If it isn't set,
	@ VAR_RESULT is TRUE. If the bit is set (or if the specified slot is empty or invalid), VAR_RESULT is FALSE.
	.macro checkmodernfatefulencounter slot:req
	.byte 0xce
	.2byte \slot
	.endm

	@ Jumps to the ram script saved from a Wonder Card. If there is no valid saved Wonder Card or if the
	@ ram script is invalid then this does nothing.
	.macro trywondercardscript
	.byte 0xcf
	.endm

	@ Used only in FireRed/LeafGreen, does nothing in Emerald.
	.macro setworldmapflag worldmapflag:req
	.byte 0xd0
	.2byte \worldmapflag
	.endm

	@ Warps the player to the specified map using a teleport effect. Effect is similar to warpteleport, but
	@ this warp has no fade out and maintains the original facing direction.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpspinenter map:req, a, b, c
	.byte 0xd1
	formatwarp \map, \a, \b, \c
	.endm

	@ Changes the location where the player caught the Pokemon in the specified slot of their party.
	.macro setmonmetlocation slot:req, location:req
	.byte 0xd2
	.2byte \slot
	.byte \location
	.endm

	@ For the rotating tile puzzles in Mossdeep Gym / Trick House Room 7. Moves the objects one rotation
	@ on the colored puzzle specified by puzzleNumber.
	.macro moverotatingtileobjects puzzleNumber:req
	.byte 0xd3
	.2byte \puzzleNumber
	.endm

	@ For the rotating tile puzzles in Mossdeep Gym / Trick House Room 7. Updates the facing direction of all objects on the puzzle tiles
	.macro turnrotatingtileobjects
	.byte 0xd4
	.endm

	@ For the rotating tile puzzles in Mossdeep Gym / Trick House Room 7. Allocates memory for the puzzle objects.
	@ isTrickHouse is needed to determine which of the two maps the puzzle is on, in order to know where in the tileset
	@ the puzzle tiles start (TRUE for Trick House Room, FALSE for Mossdeep Gym).
	.macro initrotatingtilepuzzle isTrickHouse:req
	.byte 0xd5
	.2byte \isTrickHouse
	.endm

	@ For the rotating tile puzzles in Mossdeep Gym / Trick House Room 7. Frees the memory allocated for the puzzle objects.
	.macro freerotatingtilepuzzle
	.byte 0xd6
	.endm

	@ Warp used by the teleport tiles in the Mossdeep Gym. Plays SE_WARP_IN and does a simple fade transition.
	@ Also skips reloading object events by setting SKIP_OBJECT_EVENT_LOAD.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpmossdeepgym map:req, a, b, c
	.byte 0xd7
	formatwarp \map, \a, \b, \c
	.endm

	@ Sets the selected object to the id of the currently approaching trainer.
	.macro selectapproachingtrainer
	.byte 0xd8
	.endm

	@ Freezes all objects immediately except the player and the approaching trainers.
	@ The player and trainers are frozen once their movement is finished.
	.macro lockfortrainer
	.byte 0xd9
	.endm

	@ Destroys the window created by braillemessage.
	.macro closebraillemessage
	.byte 0xda
	.endm

	@ Prints and draws the message all at once rather than character by character.
	@ Does not wait for player input to continue.
	.macro messageinstant text:req
	.byte 0xdb
	.4byte \text
	.endm

	@ Equivalent to fadescreen but copies gPlttBufferUnfaded to gPaletteDecompressionBuffer on the fade out
	@ and the reverse on the fade in, in effect saving gPlttBufferUnfaded to restore it.
	.macro fadescreenswapbuffers mode:req
	.byte 0xdc
	.byte \mode
	.endm

	@ Buffers the specified trainer's class name to the given string var.
	@ If the trainer id is >= TRAINERS_COUNT it will be treated as TRAINER_NONE.
	.macro buffertrainerclassname stringVarId:req, trainerId:req
	.byte 0xdd
	stringvar \stringVarId
	.2byte \trainerId
	.endm

	@ Buffers the specified trainer's name to the given string var.
	@ If the trainer id is >= TRAINERS_COUNT it will be treated as TRAINER_NONE.
	.macro buffertrainername stringVarId:req, trainerId:req
	.byte 0xde
	stringvar \stringVarId
	.2byte \trainerId
	.endm

	@ Starts a Pokenav call with the given text.
	.macro pokenavcall text:req
	.byte 0xdf
	.4byte \text
	.endm

	@ Warp with a fade to white. Used during the Sootopolis legendary fight.
	@ Warp commands can be given either the id of which warp location to go to on the destination map
	@ or a pair of x/y coordinates to go to directly on the destination map.
	.macro warpwhitefade map:req, a, b, c
	.byte 0xe0
	formatwarp \map, \a, \b, \c
	.endm

	@ Buffers the name of the contest category to the buffer.
	@ For example a category of CONTEST_CATEGORY_COOL will buffer the string "COOLNESS CONTEST".
	.macro buffercontestname stringVarId:req, category:req
	.byte 0xe1
	stringvar \stringVarId
	.2byte \category
	.endm

	@ Writes the name of the specified item to the specified buffer. If 'item' is a Berry or ITEM_POKE_BALL
	@ and if the quantity is 2 or more, the buffered string will be pluralized ("IES" or "S" appended).
	@ If the specified item is >= ITEMS_COUNT then the name of ITEM_NONE ("????????") is buffered instead.
	.macro bufferitemnameplural stringVarId:req, item:req, quantity:req
	.byte 0xe2
	stringvar \stringVarId
	.2byte \item
	.2byte \quantity
	.endm

	.macro _dynmultichoice left:req, top:req, ignoreBPress:req, maxBeforeScroll:req, shouldSort:req, initialSelected:req, callbacks:req argv:vararg
	.byte 0xe3
	.2byte \left
	.2byte \top
	.byte \ignoreBPress
	.byte \maxBeforeScroll
	.byte \shouldSort
	.2byte \initialSelected
	.byte \callbacks
	.byte (.Ldynmultichoice_\@_2 - .Ldynmultichoice_\@_1) / 4
.Ldynmultichoice_\@_1:
	.4byte \argv
.Ldynmultichoice_\@_2:
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made.
	@ Lists of options are provided in argv.
	@ If ignoreBPress is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro dynmultichoice left:req, top:req, ignoreBPress:req, maxBeforeScroll:req, initialSelected:req, callbacks:req argv:vararg
	_dynmultichoice \left, \top, \ignoreBPress, \maxBeforeScroll, FALSE, \initialSelected, \callbacks, \argv
	.endm

	.macro dynmultipush name:req, id:req
	.byte 0xe4
	.4byte \name
	.2byte \id
	.endm

	.macro dynmultistack left:req, top:req, ignoreBPress:req, maxBeforeScroll:req, shouldSort:req, initialSelected:req, callbacks:req
	_dynmultichoice \left, \top, \ignoreBPress, \maxBeforeScroll, \shouldSort, \initialSelected, \callbacks, NULL
	.endm

@ Supplementary

	.macro goto_if_unset flag:req, dest:req
	checkflag \flag
	goto_if FALSE, \dest
	.endm

	.macro goto_if_set flag:req, dest:req
	checkflag \flag
	goto_if TRUE, \dest
	.endm

	@ Allows 'compare' followed by a conditional goto/call to be combined into a single statement.
	@ The following are examples of the two acceptable formats this facilitates:
	@ compare VAR_RESULT, TRUE
	@ goto_if_eq MyScript
	@ - or -
	@ goto_if_eq VAR_RESULT, TRUE, MyScript
	@
	@ The first two arguments to this macro are the base command, e.g. 'goto_if 1' for goto_if_eq.
	@ The remaining arguments 'a, b, c' depend on the format:
	@ For a single statement, 'a' and 'b' are the values to compare and 'c' is the destination pointer.
	@ For a statement preceded by a compare, 'a' is the destination pointer and 'b/c' are not provided.
	.macro trycompare jump:req, condition:req, a:req, b, c
	.ifnb \c
		compare \a, \b
		\jump \condition, \c
	.else
		\jump \condition, \a
	.endif
	.endm

	.macro goto_if_lt a:req, b, c @ LESS THAN
	trycompare goto_if, 0, \a, \b, \c
	.endm

	.macro goto_if_eq a:req, b, c @ EQUAL
	trycompare goto_if, 1, \a, \b, \c
	.endm

	.macro goto_if_gt a:req, b, c @ GREATER THAN
	trycompare goto_if, 2, \a, \b, \c
	.endm

	.macro goto_if_le a:req, b, c @ LESS THAN OR EQUAL
	trycompare goto_if, 3, \a, \b, \c
	.endm

	.macro goto_if_ge a:req, b, c @ GREATER THAN OR EQUAL
	trycompare goto_if, 4, \a, \b, \c
	.endm

	.macro goto_if_ne a:req, b, c @ NOT EQUAL
	trycompare goto_if, 5, \a, \b, \c
	.endm

	.macro call_if_unset flag:req, dest:req
	checkflag \flag
	call_if FALSE, \dest
	.endm

	.macro call_if_set flag:req, dest:req
	checkflag \flag
	call_if TRUE, \dest
	.endm

	.macro call_if_lt a:req, b, c @ LESS THAN
	trycompare call_if, 0, \a, \b, \c
	.endm

	.macro call_if_eq a:req, b, c @ EQUAL
	trycompare call_if, 1, \a, \b, \c
	.endm

	.macro call_if_gt a:req, b, c @ GREATER THAN
	trycompare call_if, 2, \a, \b, \c
	.endm

	.macro call_if_le a:req, b, c @ LESS THAN OR EQUAL
	trycompare call_if, 3, \a, \b, \c
	.endm

	.macro call_if_ge a:req, b, c @ GREATER THAN OR EQUAL
	trycompare call_if, 4, \a, \b, \c
	.endm

	.macro call_if_ne a:req, b, c @ NOT EQUAL
	trycompare call_if, 5, \a, \b, \c
	.endm

	.macro vgoto_if_eq a:req, b, c
	trycompare vgoto_if, TRUE, \a, \b, \c
	.endm

	.macro vgoto_if_ne a:req, b, c
	trycompare vgoto_if, FALSE, \a, \b, \c
	.endm

	.macro vgoto_if_unset flag:req, dest:req
	checkflag \flag
	vgoto_if FALSE, \dest
	.endm

	.macro vgoto_if_set flag:req, dest:req
	checkflag \flag
	vgoto_if TRUE, \dest
	.endm

	.macro goto_if_defeated trainer:req, dest:req
	checktrainerflag \trainer
	goto_if TRUE, \dest
	.endm

	.macro goto_if_not_defeated trainer:req, dest:req
	checktrainerflag \trainer
	goto_if FALSE, \dest
	.endm

	.macro call_if_defeated trainer:req, dest:req
	checktrainerflag \trainer
	call_if TRUE, \dest
	.endm

	.macro call_if_not_defeated trainer:req, dest:req
	checktrainerflag \trainer
	call_if FALSE, \dest
	.endm

	.macro switch var:req
	copyvar VAR_0x8000, \var
	.endm

	.macro case condition:req, dest:req
	compare VAR_0x8000, \condition
	goto_if_eq \dest
	.endm

	@ Message box types
	MSGBOX_NPC = 2
	MSGBOX_SIGN = 3
	MSGBOX_DEFAULT = 4
	MSGBOX_YESNO = 5
	MSGBOX_AUTOCLOSE = 6
	MSGBOX_GETPOINTS = 9
	MSGBOX_POKENAV = 10

	YES = 1
	NO  = 0

	@ Buffers the given text and calls the relevant standard message script (see gStdScripts).
	.macro msgbox text:req, type=MSGBOX_DEFAULT
	loadword 0, \text
	callstd \type
	.endm

	@ Gives 'amount' of the specified 'item' to the player and prints a message with fanfare.
	@ If the player doesn't have space for all the items then as many are added as possible, the
	@ message indicates there is no room, and VAR_RESULT is set to FALSE.
	@ Otherwise VAR_RESULT is set to TRUE, and the message indicates they have received the item(s).
	.macro giveitem item:req, amount=1
	setorcopyvar VAR_0x8000, \item
	setorcopyvar VAR_0x8001, \amount
	callstd STD_OBTAIN_ITEM
	.endm

	@ For picking up items in the overworld. Similar to giveitem, but with different language and
	@ sets the flag of the last-talked to object (the item the player picked up).
	.macro finditem item:req, amount=1
	setorcopyvar VAR_0x8000, \item
	setorcopyvar VAR_0x8001, \amount
	callstd STD_FIND_ITEM
	.endm

	@ Equivalent to giveitem but for a single decoration.
	.macro givedecoration decoration:req
	setorcopyvar VAR_0x8000, \decoration
	callstd STD_OBTAIN_DECORATION
	.endm

	@ Registers the specified trainer in Match Call and plays a fanfare with a notification message.
	.macro register_matchcall trainer:req
	setvar VAR_0x8004, \trainer
	special SetMatchCallRegisteredFlag
	setorcopyvar VAR_0x8000, \trainer
	callstd STD_REGISTER_MATCH_CALL
	.endm

	@ Does a sparkle field effect (e.g. when the Trick Master is hiding) at the given coordinates.
	.macro dofieldeffectsparkle x:req, y:req, priority:req
	setfieldeffectargument 0, \x
	setfieldeffectargument 1, \y
	setfieldeffectargument 2, \priority
	dofieldeffect FLDEFF_SPARKLE
	.endm

	@ Prints a braille message, waits for an A or B press, then closes the message.
	.macro braillemsgbox text:req
	braillemessage \text
	waitbuttonpress
	closebraillemessage
	.endm

	@ Creates a Pokémon with the modernFatefulEncounter bit set for an encounter
	.macro seteventmon species:req, level:req, item=ITEM_NONE
	setvar VAR_0x8004, \species
	setvar VAR_0x8005, \level
	setvar VAR_0x8006, \item
	special CreateEnemyEventMon
	.endm

	.macro setdynamicaifunc func:req
	callnative ScriptSetDynamicAiFunc
	.4byte \func
	.endm

	@ Set up a totem boost for the next battle.
	@ 'battler' is the position of the mon you want to gain a boost. see B_POSITION_xx in include/constants/battle.h.
	@ The rest of the arguments are the stat change values to each stat.
	@ For example, giving the first opponent +1 to atk and -2 to speed would be: settotemboost B_POSITION_OPPONENT_LEFT, 1, 0, -2
	.macro settotemboost battler:req, atk=0,def=0,speed=0,spatk=0,spdef=0,acc=0,evas=0
	setvar VAR_0x8000, \battler
	setvar VAR_0x8001, \atk
	setvar VAR_0x8002, \def
	setvar VAR_0x8003, \speed
	setvar VAR_0x8004, \spatk
	setvar VAR_0x8005, \spdef
	setvar VAR_0x8006, \acc
	setvar VAR_0x8007, \evas
	special SetTotemBoost
	.endm

	@ useful totem boost macros
	.macro totemboost_atk1 battler:req
	settotemboost \battler, 1
	.endm
	.macro totemboost_def1 battler:req
	settotemboost \battler, 0, 1
	.endm
	.macro totemboost_speed1 battler:req
	settotemboost \battler, 0, 0, 1
	.endm
	.macro totemboost_spatk1 battler:req
	settotemboost \battler, 0, 0, 0, 1
	.endm
	.macro totemboost_spdef1 battler:req
	settotemboost \battler, 0, 0, 0, 0, 1
	.endm
	.macro totemboost_acc1 battler:req
	settotemboost \battler, 0, 0, 0, 0, 0, 1
	.endm
	.macro totemboost_evas1 battler:req
	settotemboost \battler, 0, 0, 0, 0, 0, 0, 1
	.endm

	.macro totemboost_atk2 battler:req
	settotemboost \battler, 2
	.endm
	.macro totemboost_def2 battler:req
	settotemboost \battler, 0, 2
	.endm
	.macro totemboost_speed2 battler:req
	settotemboost \battler, 0, 0, 2
	.endm
	.macro totemboost_spatk2 battler:req
	settotemboost \battler, 0, 0, 0, 2
	.endm
	.macro totemboost_spdef2 battler:req
	settotemboost \battler, 0, 0, 0, 0, 2
	.endm
	.macro totemboost_acc2 battler:req
	settotemboost \battler, 0, 0, 0, 0, 0, 2
	.endm
	.macro totemboost_evas2 battler:req
	settotemboost \battler, 0, 0, 0, 0, 0, 0, 2
	.endm

	@ Attempts to trigger a special evolution method in the overworld.
	@ There may be other conditions required which are coded for in GetEvolutionTargetSpecies.
	@ EX: tryspecialevo EVO_WATER_SCROLL, FALSE, FALSE triggers Kubfu's EVO_WATER_SCROLL evolution
	@ 	  method, cannot be cancelled in the evolution scene, and will only evolve one Kubfu if there
	@	  are multiple in the player's party.
	.macro tryspecialevo evoMethod:req, canStopEvo=TRUE, tryMultiple=TRUE
	setvar VAR_0x8000, \evoMethod
	setvar VAR_0x8001, \canStopEvo
	setvar VAR_0x8002, \tryMultiple
	special TrySpecialOverworldEvo
	.endm

	.macro ai_vs_ai_battle trainer1:req, trainer2:req
	setflag B_FLAG_AI_VS_AI_BATTLE
	setvar VAR_0x8004, \trainer1
	callnative CreateTrainerPartyForPlayer
	trainerbattle_no_intro \trainer2, NULL
	.endm

	@ Sets VAR_RESULT to TRUE if stat can be hyper trained, or to
	@ FALSE otherwise.
	.macro canhypertrain stat:req, slot:req
	callnative CanHyperTrain
	.byte \stat
	.2byte \slot
	.endm

	@ Hyper Trains a stat.
	.macro hypertrain stat:req, slot:req
	callnative HyperTrain
	.byte \stat
	.2byte \slot
	.endm

	@ Sets VAR_RESULT to TRUE if the Pokemon has the Gigantamax Factor,
	@ or to FALSE otherwise.
	.macro hasgigantamaxfactor slot:req
	callnative HasGigantamaxFactor
	.2byte \slot
	.endm

	@ Toggles the Gigantamax Factor for a Pokemon.
	@ Fails for Melmetal (vanilla behavior).
	@ Sets VAR_RESULT to TRUE if it succeeds, and FALSE otherwise.
	.macro togglegigantamaxfactor slot:req
	callnative ToggleGigantamaxFactor
	.2byte \slot
	.endm

	@ Sets VAR_RESULT to one of the arguments (via setorcopyvar).
	.macro randomelement element:req, elements:vararg
	.set _randomelement_n, 0
	.irp el, \element, \elements
	.set _randomelement_n, _randomelement_n + 1
	.endr
		random _randomelement_n

	.set _randomelement_n, 0
	.irp el, \element, \elements
		goto_if_ne VAR_RESULT, _randomelement_n, 1f
		setorcopyvar VAR_RESULT, \el
		goto 2f
	1:
	.set _randomelement_n, _randomelement_n + 1
	.endr
	2:
	.endm

	@ Sets VAR_RESULT to TRUE with probability 'percent', and FALSE
	@ with probability '100% - percent'.
	.macro randompercentage percent:req
		random 100
		goto_if_lt VAR_RESULT, \percent, 1f
		setvar VAR_RESULT, FALSE
		goto 2f
	1:
		setvar VAR_RESULT, TRUE
	2:
	.endm

	@ Inflicts \status1 to the Pokémon in \slot.
	@ If \slot is greater or equal than PARTY_SIZE, the status is inflicted on each of the Player's Pokémon.
	.macro setstatus1 status1:req, slot:req
	callnative Script_SetStatus1
	.2byte \status1
	.2byte \slot
	.endm

	@ Sets VAR_RESULT to the Pokémon in \slot's Tera Type
	.macro checkteratype slot:req
	callnative CheckTeraType
	.2byte \slot
	.endm

	@ Sets the Pokémon in \slot's Tera Type
	.macro setteratype type:req, slot:req
	callnative SetTeraType
	.byte \type
	.2byte \slot
	.endm

	@ Saves species and forms of Daycare Pokémon to specific vars. Saves the amount of Daycare mon to VAR_RESULT.
	.macro getdaycaregfx varSpecies1:req varSpecies2:req varForm1:req varForm2:req
	callnative GetDaycareGraphics
	.2byte \varSpecies1
	.2byte \varSpecies2
	.2byte \varForm1
	.2byte \varForm2
	.endm

	@ Plays the cry of the first alive party member.
	.macro playfirstmoncry
	callnative PlayFirstMonCry
	.endm

	@ Buffers the nickname of the first alive party member.
	.macro bufferlivemonnickname out:req
	callnative BufferFirstLiveMonNickname
	.byte \out
	.endm

	@ Executes Follower actions
	.macro getfolloweraction
	callnative GetFollowerAction
	.endm

	@ Checks if Field move is being used by the current follower.
	.macro isfollowerfieldmoveuser var:req
	callnative IsFollowerFieldMoveUser
	.2byte \var
	.endm

	@ Saves the direction from where source object event would need to turn to to face the target into the specified var.
	.macro getdirectiontoface var:req, sourceId:req, targetId:req
	callnative GetDirectionToFaceScript
	.2byte \var
	.byte \sourceId
	.byte \targetId
	.endm

	@ set the wild double battle flag
	@ can be used in conjunection with createmon to set up a wild battle with 2 player mons vs. 1 enemy mon
	.macro setwilddoubleflag
	callnative ScriptSetDoubleBattleFlag
	.endm

	@ When OW_USE_FAKE_RTC and OW_FLAG_PAUSE_TIME is assigned, this macro will stop the flow of time.
	.macro pausefakertc
	callnative Script_PauseFakeRtc
	.endm

	@ When OW_USE_FAKE_RTC and OW_FLAG_PAUSE_TIME is assigned, this macro will resume the flow of time.
	.macro resumefakertc
	callnative Script_ResumeFakeRtc
	.endm

	@ When OW_USE_FAKE_RTC and OW_FLAG_PAUSE_TIME is assigned, this macro will resume the flow of time if paused, and stop the flow of time otherwise.
	.macro togglefakertc
	callnative Script_ToggleFakeRtc
	.endm
