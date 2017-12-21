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
	.macro call destination
	.byte 0x04
	.4byte \destination
	.endm

	@ Jumps to destination and continues script execution from there.
	.macro goto destination
	.byte 0x05
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to destination and continues script execution from there.
	.macro goto_if condition, destination
	.byte 0x06
	.byte \condition
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls destination.
	.macro call_if condition, destination
	.byte 0x07
	.byte \condition
	.4byte \destination
	.endm

	@ Jumps to the standard function at index function.
	.macro gotostd function
	.byte 0x08
	.byte \function
	.endm

	@ Calls the standard function at index function.
	.macro callstd function
	.byte 0x09
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to the standard function at index function.
	.macro gotostd_if condition, function
	.byte 0x0a
	.byte \condition
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls the standard function at index function.
	.macro callstd_if condition, function
	.byte 0x0b
	.byte \condition
	.byte \function
	.endm

	@ Executes a script stored in a default RAM location.
	.macro gotoram 
	.byte 0x0c
	.endm

	@ Terminates script execution and "resets the script RAM".
	.macro killscript 
	.byte 0x0d
	.endm

	@ Sets some status related to Mystery Event.
	.macro setmysteryeventstatus value
	.byte 0x0e
	.byte \value
	.endm

	@ Sets the specified script bank to value.
	.macro loadword destination, value
	.byte 0x0f
	.byte \destination
	.4byte \value
	.endm

	@ Sets the specified script bank to value.
	.macro loadbyte destination, value
	.byte 0x10
	.byte \destination
	.byte \value
	.endm

	@ Sets the byte at offset to value.
	.macro writebytetoaddr value, offset
	.byte 0x11
	.byte \value
	.4byte \offset
	.endm

	@ Copies the byte value at source into the specified script bank.
	.macro loadbytefromaddr destination, source
	.byte 0x12
	.byte \destination
	.4byte \source
	.endm

	@ Not sure. Judging from XSE's description I think it takes the least-significant byte in bank source and writes it to destination.
	.macro setptrbyte source, destination
	.byte 0x13
	.byte \source
	.4byte \destination
	.endm

	@ Copies the contents of bank source into bank destination.
	.macro copylocal destination, source
	.byte 0x14
	.byte \destination
	.byte \source
	.endm

	@ Copies the byte at source to destination, replacing whatever byte was previously there.
	.macro copybyte destination, source
	.byte 0x15
	.4byte \destination
	.4byte \source
	.endm

	@ Changes the value of destination to value.
	.macro setvar destination, value
	.byte 0x16
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by adding value to it. Overflow is not prevented (0xFFFF + 1 = 0x0000).
	.macro addvar destination, value
	.byte 0x17
	.2byte \destination
	.2byte \value
	.endm

	@ Changes the value of destination by subtracting value to it. Overflow is not prevented (0x0000 - 1 = 0xFFFF).
	.macro subvar destination, value
	.byte 0x18
	.2byte \destination
	.2byte \value
	.endm

	@ Copies the value of source into destination.
	.macro copyvar destination, source
	.byte 0x19
	.2byte \destination
	.2byte \source
	.endm

	@ If source is not a variable, then this function acts like setvar. Otherwise, it acts like copyvar.
	.macro setorcopyvar destination, source
	.byte 0x1a
	.2byte \destination
	.2byte \source
	.endm

	@ Compares the values of script banks a and b, after forcing the values to bytes.
	.macro compare_local_to_local byte1, byte2
	.byte 0x1b
	.byte \byte1
	.byte \byte2
	.endm

	@ Compares the least-significant byte of the value of script bank a to a fixed byte value (b).
	.macro compare_local_to_value a, b
	.byte 0x1c
	.byte \a
	.byte \b
	.endm

	@ Compares the least-significant byte of the value of script bank a to the byte located at offset b.
	.macro compare_local_to_addr a, b
	.byte 0x1d
	.byte \a
	.4byte \b
	.endm

	@ Compares the byte located at offset a to the least-significant byte of the value of script bank b.
	.macro compare_addr_to_local a, b
	.byte 0x1e
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to a fixed byte value (b).
	.macro compare_addr_to_value a, b
	.byte 0x1f
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to the byte located at offset b.
	.macro compare_addr_to_addr a, b
	.byte 0x20
	.4byte \a
	.4byte \b
	.endm

	@ Compares the value of `var` to a fixed word value (b).
	.macro compare_var_to_value var, value
	.byte 0x21
	.2byte \var
	.2byte \value
	.endm

	@ Compares the value of `var1` to the value of `var2`.
	.macro compare_var_to_var var1, var2
	.byte 0x22
	.2byte \var1
	.2byte \var2
	.endm

	@ Generic compare macro which attempts to deduce argument types based on their values
	@ Any values between 0x4000 to 0x4FFF and 0x8000 to 0x8FFF are considered event variable identifiers
	.macro compare arg1, arg2
		.if ((\arg1 >> 12) == 4 || (\arg1 >> 12) == 8) && ((\arg2 >> 12) == 4 || (\arg2 >> 12) == 8)
			compare_var_to_var \arg1, \arg2
		.elseif ((\arg1 >> 12) == 4 || (\arg1 >> 12) == 8) && (\arg2 >= 0 && \arg2 <= 0xFFFF)
			compare_var_to_value \arg1, \arg2
		.else
			.error "Invalid arguments for 'compare'"
		.endif
	.endm

	@ Calls the native C function stored at `func`.
	.macro callnative func
	.byte 0x23
	.4byte \func
	.endm

	@ Replaces the script with the function stored at `func`. Execution returns to the bytecode script when func returns TRUE.
	.macro gotonative func
	.byte 0x24
	.4byte \func
	.endm

	@ Calls a special function; that is, a function designed for use by scripts and listed in a table of pointers.
	.macro special function
	.byte 0x25
	.2byte SPECIAL_\function
	.endm

	@ Calls a special function. That function's output (if any) will be written to the variable you specify.
	.macro specialvar output, function
	.byte 0x26
	.2byte \output
	.2byte SPECIAL_\function
	.endm

	@ Blocks script execution until a command or ASM code manually unblocks it. Generally used with specific commands and specials. If this command runs, and a subsequent command or piece of ASM does not unblock state, the script will remain blocked indefinitely (essentially a hang).
	.macro waitstate 
	.byte 0x27
	.endm

	@ Blocks script execution for time (frames? milliseconds?).
	.macro delay time
	.byte 0x28
	.2byte \time
	.endm

	@ Sets a to 1.
	.macro setflag a
	.byte 0x29
	.2byte \a
	.endm

	@ Sets a to 0.
	.macro clearflag a
	.byte 0x2a
	.2byte \a
	.endm

	@ Compares a to 1.
	.macro checkflag a
	.byte 0x2b
	.2byte \a
	.endm

	@ Initializes the RTC`s local time offset to the given hour and minute. In FireRed, this command is a nop.
	.macro initclock hour, minute
	.byte 0x2c
	.byte \hour
	.byte \minute
	.endm

	@ Runs time based events. In FireRed, this command is a nop.
	.macro dodailyevents 
	.byte 0x2d
	.endm

	@ Sets the values of variables 0x8000, 0x8001, and 0x8002 to the current hour, minute, and second. In FRLG, this command sets those variables to zero.
	.macro gettime 
	.byte 0x2e
	.endm

	@ Plays the specified (sound_number) sound. Only one sound may play at a time, with newer ones interrupting older ones.
	.macro playse sound_number
	.byte 0x2f
	.2byte \sound_number
	.endm

	@ Blocks script execution until the currently-playing sound (triggered by playse) finishes playing.
	.macro waitse 
	.byte 0x30
	.endm

	@ Plays the specified (fanfare_number) fanfare.
	.macro playfanfare fanfare_number
	.byte 0x31
	.2byte \fanfare_number
	.endm

	@ Blocks script execution until all currently-playing fanfares finish.
	.macro waitfanfare 
	.byte 0x32
	.endm

	@ Plays the specified (song_number) song. The byte is apparently supposed to be 0x00.
	.macro playbgm song_number, unknown
	.byte 0x33
	.2byte \song_number
	.byte \unknown
	.endm

	@ Saves the specified (song_number) song to be played later.
	.macro savebgm song_number
	.byte 0x34
	.2byte \song_number
	.endm

	@ Crossfades the currently-playing song into the map's default song.
	.macro fadedefaultbgm 
	.byte 0x35
	.endm

	@ Crossfades the currently-playng song into the specified (song_number) song.
	.macro fadenewbgm song_number
	.byte 0x36
	.2byte \song_number
	.endm

	@ Fades out the currently-playing song.
	.macro fadeoutbgm speed
	.byte 0x37
	.byte \speed
	.endm

	@ Fades the previously-playing song back in.
	.macro fadeinbgm speed
	.byte 0x38
	.byte \speed
	.endm

	@ Sends the player to Warp warp on Map bank.map. If the specified warp is 0xFF, then the player will instead be sent to (X, Y) on the map.
	.macro warp map, warp, X, Y
	.byte 0x39
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Clone of warp that does not play a sound effect.
	.macro warpsilent map, warp, X, Y
	.byte 0x3a
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Clone of warp that plays a door opening animation before stepping upwards into it.
	.macro warpdoor map, warp, X, Y
	.byte 0x3b
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Warps the player to another map using a hole animation.
	.macro warphole map
	.byte 0x3c
	map \map
	.endm

	@ Clone of warp that uses a teleport effect. It is apparently only used in R/S/E.
	.macro warpteleport map, warp, X, Y
	.byte 0x3d
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Sets the warp destination to be used later.
	.macro setwarp map, warp, X, Y
	.byte 0x3e
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Sets the warp destination that a warp to Warp 127 on Map 127.127 will connect to. Useful when a map has warps that need to go to script-controlled locations (i.e. elevators).
	.macro setdynamicwarp map, warp, X, Y
	.byte 0x3f
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Sets the destination that diving or emerging from a dive will take the player to.
	.macro setdivewarp map, warp, X, Y
	.byte 0x40
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Sets the destination that falling into a hole will take the player to.
	.macro setholewarp map, warp, X, Y
	.byte 0x41
	map \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Retrieves the player's zero-indexed X- and Y-coordinates in the map, and stores them in the specified variables.
	.macro getplayerxy X, Y
	.byte 0x42
	.2byte \X
	.2byte \Y
	.endm

	@ Retrieves the number of Pokemon in the player's party, and stores that number in variable 0x800D (LASTRESULT).
	.macro getpartysize 
	.byte 0x43
	.endm

	@ Attempts to add quantity of item index to the player's Bag. If the player has enough room, the item will be added and variable 0x800D (LASTRESULT) will be set to 0x0001; otherwise, LASTRESULT is set to 0x0000.
	.macro giveitem index, quantity
	.byte 0x44
	.2byte \index
	.2byte \quantity
	.endm

	@ Removes quantity of item index from the player's Bag.
	.macro takeitem index, quantity
	.byte 0x45
	.2byte \index
	.2byte \quantity
	.endm

	@ Checks if the player has enough space in their Bag to hold quantity more of item index. Sets variable 0x800D (LASTRESULT) to 0x0001 if there is room, or 0x0000 is there is no room.
	.macro checkitemspace index, quantity
	.byte 0x46
	.2byte \index
	.2byte \quantity
	.endm

	@ Checks if the player has quantity or more of item index in their Bag. Sets variable 0x800D (LASTRESULT) to 0x0001 if the player has enough of the item, or 0x0000 if they have fewer than quantity of the item.
	.macro checkitem index, quantity
	.byte 0x47
	.2byte \index
	.2byte \quantity
	.endm

	@ Checks which Bag pocket the specified (index) item belongs in, and writes the value to variable 0x800D (LASTRESULT). This script is used to show the name of the proper Bag pocket when the player receives an item via callstd (simplified to giveitem in XSE).
	.macro checkitemtype index
	.byte 0x48
	.2byte \index
	.endm

	@ Adds a quantity amount of item index to the player's PC. Both arguments can be variables.
	.macro givepcitem index, quantity
	.byte 0x49
	.2byte \index
	.2byte \quantity
	.endm

	@ Checks for quantity amount of item index in the player's PC. Both arguments can be variables.
	.macro checkpcitem index, quantity
	.byte 0x4a
	.2byte \index
	.2byte \quantity
	.endm

	@ Adds decoration to the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro givedecoration decoration
	.byte 0x4b
	.2byte \decoration
	.endm

	@ Removes a decoration from the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro takedecoration decoration
	.byte 0x4c
	.2byte \decoration
	.endm

	@ Checks for decoration in the player's PC. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro checkdecor decoration
	.byte 0x4d
	.2byte \decoration
	.endm

	@ Checks if the player has enough space in their PC to hold decoration. Sets variable 0x800D (LASTRESULT) to 0x0001 if there is room, or 0x0000 is there is no room. In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro checkdecorspace decoration
	.byte 0x4e
	.2byte \decoration
	.endm

	@ Applies the movement data at movements to the specified (index) Object. Also closes any standard message boxes that are still open.
	@ If no map is specified, then the current map is used.
	.macro applymovement index, movements, map
		.ifb \map
			.byte 0x4f
			.2byte \index
			.4byte \movements
		.else
			@ Really only useful if the object has followed from one map to another (e.g. Wally during the catching event).
			.byte 0x50
			.2byte \index
			.4byte \movements
			map \map
		.endif
	.endm

	@ Blocks script execution until the movements being applied to the specified (index) Object finish. If the specified Object is 0x0000, then the command will block script execution until all Objects affected by applymovement finish their movements. If the specified Object is not currently being manipulated with applymovement, then this command does nothing.
	@ If no map is specified, then the current map is used.
	.macro waitmovement index, map
		.ifb \map
			.byte 0x51
			.2byte \index
		.else
			.byte 0x52
			.2byte \index
			map \map
		.endif
	.endm

	@ Attempts to hide the specified (index) Object on the specified (map_group, map_num) map, by setting its visibility flag if it has a valid one. If the Object does not have a valid visibility flag, this command does nothing.
	@ If no map is specified, then the current map is used.
	.macro removeobject index, map
		.ifb \map
			.byte 0x53
			.2byte \index
		.else
			.byte 0x54
			.2byte \index
			map \map
		.endif
	.endm

	@ Unsets the specified (index) Object's visibility flag on the specified (map_group, map_num) map if it has a valid one. If the Object does not have a valid visibility flag, this command does nothing.
	@ If no map is specified, then the current map is used.
	.macro addobject index, map
		.ifb \map
			.byte 0x55
			.2byte \index
		.else
			.byte 0x56
			.2byte \index
			map \map
		.endif
	.endm

	@ Sets the specified (index) Object's position on the current map.
	.macro setobjectxy index, x, y
	.byte 0x57
	.2byte \index
	.2byte \x
	.2byte \y
	.endm

	.macro showobjectat index, map
	.byte 0x58
	.2byte \index
	map \map
	.endm

	.macro hideobjectat index, map
	.byte 0x59
	.2byte \index
	map \map
	.endm

	@ If the script was called by an Object, then that Object will turn to face toward the metatile that the player is standing on.
	.macro faceplayer 
	.byte 0x5a
	.endm

	.macro turnobject index, direction
	.byte 0x5b
	.2byte \index
	.byte \direction
	.endm

	@ If the Trainer flag for Trainer index is not set, this command does absolutely nothing.
	.macro trainerbattle type, trainer, word, pointer1, pointer2, pointer3, pointer4
	.byte 0x5c
	.byte \type
	.2byte \trainer
	.2byte \word
	.if \type == 0
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == 1
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ event script
	.elseif \type == 2
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ event script
	.elseif \type == 3
		.4byte \pointer1 @ text
	.elseif \type == 4
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
	.elseif \type == 5
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == 6
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
		.4byte \pointer4 @ event script
	.elseif \type == 7
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
	.elseif \type == 8
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
		.4byte \pointer3 @ text
		.4byte \pointer4 @ event script
	.elseif \type == 9
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == 10
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == 11
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.elseif \type == 12
		.4byte \pointer1 @ text
		.4byte \pointer2 @ text
	.endif
	.endm


	@ Starts a trainer battle using the battle information stored in RAM (usually by trainerbattle, which actually calls this command behind-the-scenes), and blocks script execution until the battle finishes.
	.macro trainerbattlebegin 
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

	@ Compares Flag (trainer + 0x500) to 1. (If the flag is set, then the trainer has been defeated by the player.)
	.macro checktrainerflag trainer
	.byte 0x60
	.2byte \trainer
	.endm

	@ Sets Flag (trainer + 0x500).
	.macro settrainerflag trainer
	.byte 0x61
	.2byte \trainer
	.endm

	@ Clears Flag (trainer + 0x500).
	.macro cleartrainerflag trainer
	.byte 0x62
	.2byte \trainer
	.endm

	.macro setobjectxyperm index, x, y
	.byte 0x63
	.2byte \index
	.2byte \x
	.2byte \y
	.endm

	.macro moveobjectoffscreen index
	.byte 0x64
	.2byte \index
	.endm

	.macro setobjectmovementtype word, byte
	.byte 0x65
	.2byte \word
	.byte \byte
	.endm

	@ If a standard message box (or its text) is being drawn on-screen, this command blocks script execution until the box and its text have been fully drawn.
	.macro waitmessage 
	.byte 0x66
	.endm

	@ Starts displaying a standard message box containing the specified text. If text is a pointer, then the string at that offset will be loaded and used. If text is script bank 0, then the value of script bank 0 will be treated as a pointer to the text. (You can use loadpointer to place a string pointer in a script bank.)
	.macro message text
	.byte 0x67
	.4byte \text
	.endm

	@ Closes the current message box.
	.macro closemessage 
	.byte 0x68
	.endm

	@ Ceases movement for all Objects on-screen.
	.macro lockall 
	.byte 0x69
	.endm

	@ If the script was called by an Object, then that Object's movement will cease.
	.macro lock 
	.byte 0x6a
	.endm

	@ Resumes normal movement for all Objects on-screen, and closes any standard message boxes that are still open.
	.macro releaseall 
	.byte 0x6b
	.endm

	@ If the script was called by an Object, then that Object's movement will resume. This command also closes any standard message boxes that are still open.
	.macro release 
	.byte 0x6c
	.endm

	@ Blocks script execution until the player presses any key.
	.macro waitbuttonpress 
	.byte 0x6d
	.endm

	@ Displays a YES/NO multichoice box at the specified coordinates, and blocks script execution until the user makes a selection. Their selection is stored in variable 0x800D (LASTRESULT); 0x0000 for "NO" or if the user pressed B, and 0x0001 for "YES".
	.macro yesnobox x, y
	.byte 0x6e
	.byte \x
	.byte \y
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. If b is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoice x, y, list, b
	.byte 0x6f
	.byte \x
	.byte \y
	.byte \list
	.byte \b
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. The default argument determines the initial position of the cursor when the box is first opened; it is zero-indexed, and if it is too large, it is treated as 0x00. If b is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoicedefault x, y, list, default, b
	.byte 0x70
	.byte \x
	.byte \y
	.byte \list
	.byte \default
	.byte \b
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. The per_row argument determines how many list items will be shown on a single row of the box.
	.macro multichoicegrid x, y, list, per_row, B
	.byte 0x71
	.byte \x
	.byte \y
	.byte \list
	.byte \per_row
	.byte \B
	.endm

	@ Nopped in Emerald.
	.macro drawbox 
	.byte 0x72
	.endm

	@ Nopped in Emerald, but still consumes parameters.
	.macro erasebox byte1, byte2, byte3, byte4
	.byte 0x73
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.byte \byte4
	.endm

	@ Nopped in Emerald, but still consumes parameters.
	.macro drawboxtext byte1, byte2, byte3, byte4
	.byte 0x74
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.byte \byte4
	.endm

	@ Displays a box containing the front sprite for the specified (species) Pokemon species.
	.macro drawmonpic species, x, y
	.byte 0x75
	.2byte \species
	.byte \x
	.byte \y
	.endm

	@ Hides all boxes displayed with drawmonpic.
	.macro erasemonpic 
	.byte 0x76
	.endm

	@ Draws an image of the winner of the contest. In FireRed, this command is a nop. (The argument is discarded.)
	.macro drawcontestwinner a
	.byte 0x77
	.byte \a
	.endm

	@ Displays the string at pointer as braille text in a standard message box. The string must be formatted to use braille characters and needs to provide six extra starting characters that are skipped (in RS, these characters determined the box's size and position, but in Emerald these are calculated automatically).
	.macro braillemessage text
	.byte 0x78
	.4byte \text
	.endm

	@ Gives the player one of the specified (species) Pokemon at level level holding item. The unknown arguments should all be zeroes.
	.macro givemon species, level, item, unknown1, unknown2, unknown3
	.byte 0x79
	.2byte \species
	.byte \level
	.2byte \item
	.4byte \unknown1
	.4byte \unknown2
	.byte \unknown3
	.endm

	.macro giveegg species
	.byte 0x7a
	.2byte \species
	.endm

	.macro setmonmove index, slot, move
	.byte 0x7b
	.byte \index
	.byte \slot
	.2byte \move
	.endm

	@ Checks if at least one Pokemon in the player's party knows the specified (index) attack. If so, variable 0x800D (LASTRESULT) is set to the (zero-indexed) slot number of the first Pokemon that knows the move. If not, LASTRESULT is set to 0x0006. Variable 0x8004 is also set to this Pokemon's species.
	.macro checkpartymove index
	.byte 0x7c
	.2byte \index
	.endm

	@ Writes the name of the Pokemon at index species to the specified buffer.
	.macro bufferspeciesname out, species
	.byte 0x7d
	.byte \out
	.2byte \species
	.endm

	@ Writes the name of the species of the first Pokemon in the player's party to the specified buffer.
	.macro bufferleadmonspeciesname out
	.byte 0x7e
	.byte \out
	.endm

	@ Writes the nickname of the Pokemon in slot slot (zero-indexed) of the player's party to the specified buffer. If an empty or invalid slot is specified, ten spaces ("") are written to the buffer.
	.macro bufferpartymonnick out, slot
	.byte 0x7f
	.byte \out
	.2byte \slot
	.endm

	@ Writes the name of the item at index item to the specified buffer. If the specified index is larger than the number of items in the game (0x176), the name of item 0 ("????????") is buffered instead.
	.macro bufferitemname out, item
	.byte 0x80
	.byte \out
	.2byte \item
	.endm

	@ Writes the name of the decoration at index decoration to the specified buffer. In FireRed, this command is a nop.
	.macro bufferdecorationname out, decoration
	.byte 0x81
	.byte \out
	.2byte \decoration
	.endm

	@ Writes the name of the move at index move to the specified buffer.
	.macro buffermovename out, move
	.byte 0x82
	.byte \out
	.2byte \move
	.endm

	@ Converts the value of input to a decimal string, and writes that string to the specified buffer.
	.macro buffernumberstring out, input
	.byte 0x83
	.byte \out
	.2byte \input
	.endm

	@ Writes the standard string identified by index to the specified buffer. This command has no protections in place at all, so specifying an invalid standard string (e.x. 0x2B) can and usually will cause data corruption.
	.macro bufferstdstring out, index
	.byte 0x84
	.byte \out
	.2byte \index
	.endm

	@ Copies the string at offset to the specified buffer.
	.macro bufferstring out, offset
	.byte 0x85
	.byte \out
	.4byte \offset
	.endm

	@ Opens the Pokemart system, offering the specified products for sale.
	.macro pokemart products
	.byte 0x86
	.4byte \products
	.endm

	@ Opens the Pokemart system and treats the list of items as decorations.
	.macro pokemartdecoration products
	.byte 0x87
	.4byte \products
	.endm

	@ Apparent clone of pokemartdecoration.
	.macro pokemartdecoration2 products
	.byte 0x88
	.4byte \products
	.endm

	@ Starts up the slot machine minigame.
	.macro playslotmachine word
	.byte 0x89
	.2byte \word
	.endm

	@ Sets a berry tree's specific berry and growth stage. In FireRed, this command is a nop.
	.macro setberrytree tree_id, berry, growth_stage
	.byte 0x8a
	.byte \tree_id
	.byte \berry
	.byte \growth_stage
	.endm

	@ This allows you to choose a Pokemon to use in a contest. In FireRed, this command sets the byte at 0x03000EA8 to 0x01.
	.macro choosecontestmon 
	.byte 0x8b
	.endm

	@ Starts a contest. In FireRed, this command is a nop.
	.macro startcontest 
	.byte 0x8c
	.endm

	@ Shows the results of a contest. In FireRed, this command is a nop.
	.macro showcontestresults 
	.byte 0x8d
	.endm

	@ Starts a contest over a link connection. In FireRed, this command is a nop.
	.macro contestlinktransfer 
	.byte 0x8e
	.endm

	@ Stores a random integer between 0 and limit in variable 0x800D (LASTRESULT).
	.macro random limit
	.byte 0x8f
	.2byte \limit
	.endm

	@ If check is 0x00, this command adds value to the player's money.
	.macro givemoney value, check
	.byte 0x90
	.4byte \value
	.byte \check
	.endm

	@ If check is 0x00, this command subtracts value from the player's money.
	.macro takemoney value, check
	.byte 0x91
	.4byte \value
	.byte \check
	.endm

	@ If check is 0x00, this command will check if the player has value or more money; script variable 0x800D (LASTRESULT) is set to 0x0001 if the player has enough money, or 0x0000 if the do not.
	.macro checkmoney value, check
	.byte 0x92
	.4byte \value
	.byte \check
	.endm

	@ Spawns a secondary box showing how much money the player has.
	.macro showmoneybox x, y, check
	.byte 0x93
	.byte \x
	.byte \y
	.byte \check
	.endm

	@ Hides the secondary box spawned by showmoney.
	.macro hidemoneybox 
	.byte 0x94
	.endm

	@ Updates the secondary box spawned by showmoney. Consumes but does not use arguments.
	.macro updatemoneybox x, y
	.byte 0x95
	.byte \x
	.byte \y
	.endm

	@ Gets the price reduction for the index given. In FireRed, this command is a nop.
	.macro getpricereduction index
	.byte 0x96
	.2byte \index
	.endm

	@ Fades the screen to and from black and white. Mode 0x00 fades from black, mode 0x01 fades out to black, mode 0x2 fades in from white, and mode 0x3 fades out to white.
	.macro fadescreen effect
	.byte 0x97
	.byte \effect
	.endm

	@ Fades the screen to and from black and white. Mode 0x00 fades from black, mode 0x01 fades out to black, mode 0x2 fades in from white, and mode 0x3 fades out to white. Other modes may exist.
	.macro fadescreenspeed effect, speed
	.byte 0x98
	.byte \effect
	.byte \speed
	.endm

	.macro setflashradius word
	.byte 0x99
	.2byte \word
	.endm

	.macro animateflash byte
	.byte 0x9a
	.byte \byte
	.endm

	.macro messageautoscroll pointer
	.byte 0x9b
	.4byte \pointer
	.endm

	@ Executes the specified field move animation.
	.macro dofieldeffect animation
	.byte 0x9c
	.2byte \animation
	.endm

	@ Sets up the field effect argument argument with the value value.
	.macro setfieldeffectargument argument, param
	.byte 0x9d
	.byte \argument
	.2byte \param
	.endm

	@ Blocks script execution until all playing field move animations complete.
	.macro waitfieldeffect animation
	.byte 0x9e
	.2byte \animation
	.endm

	@ Sets which healing place the player will return to if all of the Pokemon in their party faint.
	.macro setrespawn heallocation
	.byte 0x9f
	.2byte \heallocation
	.endm

	@ Checks the player's gender. If male, then 0x0000 is stored in variable 0x800D (LASTRESULT). If female, then 0x0001 is stored in LASTRESULT.
	.macro checkplayergender 
	.byte 0xa0
	.endm

	@ Plays the specified (species) Pokemon's cry. You can use waitcry to block script execution until the sound finishes.
	.macro playmoncry species, effect
	.byte 0xa1
	.2byte \species
	.2byte \effect
	.endm

	@ Changes the metatile at (x, y) on the current map.
	.macro setmetatile x, y, metatile_number, tile_attrib
	.byte 0xa2
	.2byte \x
	.2byte \y
	.2byte \metatile_number
	.2byte \tile_attrib
	.endm

	@ Queues a weather change to the default weather for the map.
	.macro resetweather 
	.byte 0xa3
	.endm

	@ Queues a weather change to type weather.
	.macro setweather type
	.byte 0xa4
	.2byte \type
	.endm

	@ Executes the weather change queued with resetweather or setweather. The current weather will smoothly fade into the queued weather.
	.macro doweather 
	.byte 0xa5
	.endm

	@ This command manages cases in which maps have tiles that change state when stepped on (specifically, cracked/breakable floors).
	.macro setstepcallback subroutine
	.byte 0xa6
	.byte \subroutine
	.endm

	.macro setmaplayoutindex index
	.byte 0xa7
	.2byte \index
	.endm

	.macro setobjectpriority index, map, priority
	.byte 0xa8
	.2byte \index
	map \map
	.byte \priority
	.endm

	.macro resetobjectpriority index, map
	.byte 0xa9
	.2byte \index
	map \map
	.endm

	.macro createvobject sprite, byte2, x, y, elevation, direction
	.byte 0xaa
	.byte \sprite
	.byte \byte2
	.2byte \x
	.2byte \y
	.byte \elevation
	.byte \direction
	.endm

	.macro turnvobject index, direction
	.byte 0xab
	.byte \index
	.byte \direction
	.endm

	@ Opens the door metatile at (X, Y) with an animation.
	.macro opendoor x, y
	.byte 0xac
	.2byte \x
	.2byte \y
	.endm

	@ Closes the door metatile at (X, Y) with an animation.
	.macro closedoor x, y
	.byte 0xad
	.2byte \x
	.2byte \y
	.endm

	@ Waits for the door animation started with opendoor or closedoor to finish.
	.macro waitdooranim 
	.byte 0xae
	.endm

	@ Sets the door tile at (x, y) to be open without an animation.
	.macro setdooropen x, y
	.byte 0xaf
	.2byte \x
	.2byte \y
	.endm

	@ Sets the door tile at (x, y) to be closed without an animation.
	.macro setdoorclosed x, y
	.byte 0xb0
	.2byte \x
	.2byte \y
	.endm

	@ In Emerald, this command consumes its parameters and does nothing. In FireRed, this command is a nop.
	.macro addelevmenuitem a, b, c, d
	.byte 0xb1
	.byte \a
	.2byte \b
	.2byte \c
	.2byte \d
	.endm

	@ In FireRed and Emerald, this command is a nop.
	.macro showelevmenu 
	.byte 0xb2
	.endm

	.macro checkcoins out
	.byte 0xb3
	.2byte \out
	.endm

	.macro givecoins count
	.byte 0xb4
	.2byte \count
	.endm

	.macro takecoins count
	.byte 0xb5
	.2byte \count
	.endm

	@ Prepares to start a wild battle against a species at Level level holding item. Running this command will not affect normal wild battles. You start the prepared battle with dowildbattle.
	.macro setwildbattle species, level, item
	.byte 0xb6
	.2byte \species
	.byte \level
	.2byte \item
	.endm

	@ Starts a wild battle against the Pokemon generated by setwildbattle. Blocks script execution until the battle finishes.
	.macro dowildbattle 
	.byte 0xb7
	.endm

	.macro setvaddress long, word
	.byte 0xb8
	.4byte \long
	.2byte \word
	.endm

	.macro vgoto pointer
	.byte 0xb9
	.4byte \pointer
	.endm

	.macro vcall pointer
	.byte 0xba
	.4byte \pointer
	.endm

	.macro vgoto_if byte, pointer
	.byte 0xbb
	.byte \byte
	.4byte \pointer
	.endm

	.macro vcall_if byte, pointer
	.byte 0xbc
	.byte \byte
	.4byte \pointer
	.endm

	.macro vmessage pointer
	.byte 0xbd
	.4byte \pointer
	.endm

	.macro vloadptr pointer
	.byte 0xbe
	.4byte \pointer
	.endm

	.macro vbufferstring byte, pointer
	.byte 0xbf
	.byte \byte
	.4byte \pointer
	.endm

	@ Spawns a secondary box showing how many Coins the player has.
	.macro showcoinsbox x, y
	.byte 0xc0
	.byte \x
	.byte \y
	.endm

	@ Hides the secondary box spawned by showcoins. It consumes its arguments but doesn't use them.
	.macro hidecoinsbox x, y
	.byte 0xc1
	.byte \x
	.byte \y
	.endm

	@ Updates the secondary box spawned by showcoins. It consumes its arguments but doesn't use them.
	.macro updatecoinsbox x, y
	.byte 0xc2
	.byte \x
	.byte \y
	.endm

	@ Increases the value of the specified game stat by 1. The stat's value will not be allowed to exceed 0x00FFFFFF.
	.macro incrementgamestat stat
	.byte 0xc3
	.byte \stat
	.endm

	@ Sets the destination that using an Escape Rope or Dig will take the player to.
	.macro setescapewarp map, warp, x, y
	.byte 0xc4
	map \map
	.byte \warp
	.2byte \x
	.2byte \y
	.endm

	@ Blocks script execution until cry finishes.
	.macro waitmoncry 
	.byte 0xc5
	.endm

	@ Writes the name of the specified (box) PC box to the specified buffer.
	.macro bufferboxname out, box
	.byte 0xc6
	.byte \out
	.2byte \box
	.endm

	@ Sets the color of the text in standard message boxes. 0x00 produces blue (male) text, 0x01 produces red (female) text, 0xFF resets the color to the default for the current OW's gender, and all other values produce black text.
	.macro textcolor color
	.byte 0xc7
	.byte \color
	.endm

	@ The exact purpose of this command is unknown, but it is related to the blue help-text box that appears on the bottom of the screen when the Main Menu is opened.
	.macro loadhelp pointer
	.byte 0xc8
	.4byte \pointer
	.endm

	@ The exact purpose of this command is unknown, but it is related to the blue help-text box that appears on the bottom of the screen when the Main Menu is opened.
	.macro unloadhelp 
	.byte 0xc9
	.endm

	@ After using this command, all standard message boxes will use the signpost frame.
	.macro signmsg 
	.byte 0xca
	.endm

	@ Ends the effects of signmsg, returning message box frames to normal.
	.macro normalmsg 
	.byte 0xcb
	.endm

	@ Compares the value of a hidden variable to a dword.
	.macro comparehiddenvar a, value
	.byte 0xcc
	.byte \a
	.4byte \value
	.endm

	@ Makes the Pokemon in the specified slot of the player's party obedient. It will not randomly disobey orders in battle.
	.macro setmonobedient slot
	.byte 0xcd
	.2byte \slot
	.endm

	@ Checks if the Pokemon in the specified slot of the player's party is obedient. If the Pokemon is disobedient, 0x0001 is written to script variable 0x800D (LASTRESULT). If the Pokemon is obedient (or if the specified slot is empty or invalid), 0x0000 is written.
	.macro checkmonobedience slot
	.byte 0xce
	.2byte \slot
	.endm

	@ Depending on factors I haven't managed to understand yet, this command may cause script execution to jump to the offset specified by the pointer at 0x020375C0.
	.macro execram 
	.byte 0xcf
	.endm

	@ Sets worldmapflag to 1. This allows the player to Fly to the corresponding map, if that map has a flightspot.
	.macro setworldmapflag worldmapflag
	.byte 0xd0
	.2byte \worldmapflag
	.endm

	@ Clone of warpteleport? It is apparently only used in FR/LG, and only with specials.[source]
	.macro warpteleport2 map, warp, x, y
	.byte 0xd1
	map \map
	.byte \warp
	.2byte \x
	.2byte \y
	.endm

	@ Changes the location where the player caught the Pokemon in the specified slot of their party.
	.macro setmonmetlocation slot, location
	.byte 0xd2
	.2byte \slot
	.byte \location
	.endm

	.macro mossdeepgym1 unknown
	.byte 0xd3
	.2byte \unknown
	.endm

	.macro mossdeepgym2 
	.byte 0xd4
	.endm

	@ In FireRed, this command is a nop.
	.macro mossdeepgym3 var
	.byte 0xd5
	.2byte \var
	.endm

	.macro mossdeepgym4 
	.byte 0xd6
	.endm

	.macro warp7 map, byte, word1, word2
	.byte 0xd7
	map \map
	.byte \byte
	.2byte \word1
	.2byte \word2
	.endm

	.macro cmdD8 
	.byte 0xd8
	.endm

	.macro cmdD9 
	.byte 0xd9
	.endm

	.macro hidebox2 
	.byte 0xda
	.endm

	.macro message3 pointer
	.byte 0xdb
	.4byte \pointer
	.endm

	.macro fadescreenswapbuffers byte
	.byte 0xdc
	.byte \byte
	.endm

	.macro buffertrainerclassname out, class
	.byte 0xdd
	.byte \out
	.2byte \class
	.endm

	.macro buffertrainername out, trainer
	.byte 0xde
	.byte \out
	.2byte \trainer
	.endm

	.macro pokenavcall pointer
	.byte 0xdf
	.4byte \pointer
	.endm

	.macro warp8 map, byte, word1, word2
	.byte 0xe0
	map \map
	.byte \byte
	.2byte \word1
	.2byte \word2
	.endm

	.macro buffercontesttypestring out, word
	.byte 0xe1
	.byte \out
	.2byte \word
	.endm

	@ Writes the name of the specified (item) item to the specified buffer. If the specified item is a Berry (0x85 - 0xAE) or Poke Ball (0x4) and if the quantity is 2 or more, the buffered string will be pluralized ("IES" or "S" appended). If the specified item is the Enigma Berry, I have no idea what this command does (but testing showed no pluralization). If the specified index is larger than the number of items in the game (0x176), the name of item 0 ("????????") is buffered instead.
	.macro bufferitemnameplural out, item, quantity
	.byte 0xe2
	.byte \out
	.2byte \item
	.2byte \quantity
	.endm


@ Supplementary

	.macro goto_eq dest
	goto_if 1, \dest
	.endm

	.macro switch var
	copyvar 0x8000, \var
	.endm

	.macro case condition, dest
	compare_var_to_value 0x8000, \condition
	goto_eq \dest
	.endm

	.macro msgbox text, type=4
	loadword 0, \text
	callstd \type
	.endm

	@ Message box types
	MSGBOX_YESNO = 5

	YES = 1
	NO  = 0

	.macro giveitem_std item, amount=1, function=0
	setorcopyvar 0x8000, \item
	setorcopyvar 0x8001, \amount
	callstd \function
	.endm

	.macro givedecoration_std decoration
	setorcopyvar 0x8000, \decoration
	callstd 7
	.endm
