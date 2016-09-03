	@ Does nothing.
	.macro snop
	.byte 0x00
	.endm

	@ Does nothing.
	.macro snop1
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
	.macro jump destination
	.byte 0x05
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to destination and continues script execution from there.
	.macro jumpif condition, destination
	.byte 0x06
	.byte \condition
	.4byte \destination
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls destination.
	.macro callif condition, destination
	.byte 0x07
	.byte \condition
	.4byte \destination
	.endm

	@ Jumps to the standard function at index function.
	.macro jumpstd function
	.byte 0x08
	.byte \function
	.endm

	@ Calls the standard function at index function.
	.macro callstd function
	.byte 0x09
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), jumps to the standard function at index function.
	.macro jumpstdif condition, function
	.byte 0x0a
	.byte \condition
	.byte \function
	.endm

	@ If the result of the last comparison matches condition (see Comparison operators), calls the standard function at index function.
	.macro callstdif condition, function
	.byte 0x0b
	.byte \condition
	.byte \function
	.endm

	@ Executes a script stored in a default RAM location.
	.macro jumpram
	.byte 0x0c
	.endm

	@ Terminates script execution and "resets the script RAM".
	.macro die
	.byte 0x0d
	.endm

	@ Pads the specified value to a dword, and then writes that dword to a predefined address (0x0203AAA8).
	.macro setbyte value
	.byte 0x0e
	.byte \value
	.endm

	@ Sets the specified script bank to value.
	.macro loadptr destination, value
	.byte 0x0f
	.byte \destination
	.4byte \value
	.endm

	@ Sets the specified script bank to value.
	.macro setbufferbyte destination, value
	.byte 0x10
	.byte \destination
	.byte \value
	.endm

	@ Sets the byte at offset to value.
	.macro writebytetooffset value, offset
	.byte 0x11
	.byte \value
	.4byte \offset
	.endm

	@ Copies the byte value at source into the specified script bank.
	.macro loadbytefrompointer destination, source
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
	.macro copybuffers destination, source
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
	.macro comparebuffers byte1, byte2
	.byte 0x1b
	.byte \byte1
	.byte \byte2
	.endm

	@ Compares the least-significant byte of the value of script bank a to a fixed byte value (b).
	.macro comparebuffertobyte a, b
	.byte 0x1c
	.byte \a
	.byte \b
	.endm

	@ Compares the least-significant byte of the value of script bank a to the byte located at offset b.
	.macro comparebuffertoptrbyte a, b
	.byte 0x1d
	.byte \a
	.4byte \b
	.endm

	@ Compares the byte located at offset a to the least-significant byte of the value of script bank b.
	.macro compareptrbytetobuffer a, b
	.byte 0x1e
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to a fixed byte value (b).
	.macro compareptrbytetobyte a, b
	.byte 0x1f
	.4byte \a
	.byte \b
	.endm

	@ Compares the byte located at offset a to the byte located at offset b.
	.macro compareptrbytes a, b
	.byte 0x20
	.4byte \a
	.4byte \b
	.endm

	@ Compares the value of a to a fixed word value (b).
	.macro compare a, b
	.byte 0x21
	.2byte \a
	.2byte \b
	.endm

	@ Compares the value of a to the value of b.
	.macro comparevars a, b
	.byte 0x22
	.2byte \a
	.2byte \b
	.endm

	@ Calls the ASM routine stored at code. Script execution is blocked until the ASM returns (bx lr, mov pc, lr, etc.). Remember to add 1 to the offset when calling THUMB code.
	.macro callasm code
	.byte 0x23
	.4byte \code
	.endm

	@ Replaces a pointer in the script engine RAM with asm_pointer.
	.macro jumpasm asm_pointer
	.byte 0x24
	.4byte \asm_pointer
	.endm

	@ Calls a special function; that is, a piece of ASM code designed for use by scripts and listed in a table of pointers.
	.macro special function
	.byte 0x25
	.2byte \function
	.endm

	@ Calls a special function. That function's output (if any) will be written to the variable you specify.
	.macro specialval output, function
	.byte 0x26
	.2byte \output
	.2byte \function
	.endm

	@ Blocks script execution until a command or ASM code manually unblocks it. Generally used with specific commands and specials. If this command runs, and a subsequent command or piece of ASM does not unblock state, the script will remain blocked indefinitely (essentially a hang).
	.macro waitstate
	.byte 0x27
	.endm

	@ Blocks script execution for time (frames? milliseconds?).
	.macro pause time
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

	@ In FireRed, this command is a nop.
	.macro compareflags
	.byte 0x2c
	.endm

	@ In FireRed, this command is a nop.
	.macro checkdailyflags
	.byte 0x2d
	.endm

	@ Resets the values of variables 0x8000, 0x8001, and 0x8002. Related to RTC in RSE?
	.macro resetvars
	.byte 0x2e
	.endm

	@ Plays the specified (sound_number) sound. Only one sound may play at a time, with newer ones interrupting older ones.
	.macro playsfx sound_number
	.byte 0x2f
	.2byte \sound_number
	.endm

	@ Blocks script execution until the currently-playing sound (triggered by sound) finishes playing.
	.macro checksound
	.byte 0x30
	.endm

	@ Plays the specified (fanfare_number) fanfare.
	.macro fanfare fanfare_number
	.byte 0x31
	.2byte \fanfare_number
	.endm

	@ Blocks script execution until all currently-playing fanfares finish.
	.macro waitfanfare
	.byte 0x32
	.endm

	@ Plays the specified (song_number) song. The byte is apparently supposed to be 0x00.
	.macro playmusic song_number, unknown
	.byte 0x33
	.2byte \song_number
	.byte \unknown
	.endm

	@ Plays the specified (song_number) song.
	.macro playmusicbattle song_number
	.byte 0x34
	.2byte \song_number
	.endm

	@ Crossfades the currently-playing song into the map's default song.
	.macro fadedefault
	.byte 0x35
	.endm

	@ Crossfades the currently-playng song into the specified (song_number) song.
	.macro fademusic song_number
	.byte 0x36
	.2byte \song_number
	.endm

	@ Fades out the currently-playing song.
	.macro fadeout speed
	.byte 0x37
	.byte \speed
	.endm

	@ Fades the currently-playing song back in.
	.macro fadein speed
	.byte 0x38
	.byte \speed
	.endm

	@ Sends the player to Warp warp on Map bank.map. If the specified warp is 0xFF, then the player will instead be sent to (X, Y) on the map.
	.macro warp bank, map, warp, X, Y
	.byte 0x39
	.byte \bank
	.byte \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Clone of warp that does not play a sound effect.
	.macro warpmuted
	.byte 0x3a
	.endm

	@ Clone of warp that uses "a walking effect".
	.macro warpwalk
	.byte 0x3b
	.endm

	@ Warps the player to another map using a hole animation.
	.macro warphole bank, map
	.byte 0x3c
	.byte \bank
	.byte \map
	.endm

	@ Clone of warp that uses a teleport effect. It is apparently only used in R/S/E.[source]
	.macro warpteleport
	.byte 0x3d
	.endm

	@ Clone of warp. Used by an (unused?) Safari Zone script to return the player to the gatehouse and end the Safari Game.
	.macro warp3
	.byte 0x3e
	.endm

	@ Sets a default warp place. If a warp tries to send the player to Warp 127 on Map 127.127, they will instead be sent here. Useful when a map has warps that need to go to script-controlled locations (i.e. elevators).
	.macro warpplace bank, map, warp, X, Y
	.byte 0x3f
	.byte \bank
	.byte \map
	.byte \warp
	.2byte \X
	.2byte \Y
	.endm

	@ Clone of warp3, except that this writes data to different offsets...
	.macro warp4
	.byte 0x40
	.endm

	@ Clone of warp3, except that this writes data to different offsets...
	.macro warp5
	.byte 0x41
	.endm

	@ Retrieves the player's zero-indexed X- and Y-coordinates in the map, and stores them in the specified variables.
	.macro getplayerxy X, Y
	.byte 0x42
	.2byte \X
	.2byte \Y
	.endm

	@ Retrieves the number of Pokmon in the player's party, and stores that number in variable 0x800D (LASTRESULT).
	.macro countpokemon
	.byte 0x43
	.endm

	@ Attempts to add quantity of item index to the player's Bag. If the player has enough room, the item will be added and variable 0x800D (LASTRESULT) will be set to 0x0001; otherwise, LASTRESULT is set to 0x0000.
	.macro additem index, quantity
	.byte 0x44
	.2byte \index
	.2byte \quantity
	.endm

	@ Removes quantity of item index from the player's Bag.
	.macro removeitem index, quantity
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
	.macro addpcitem index, quantity
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

	@ In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro adddecor a
	.byte 0x4b
	.2byte \a
	.endm

	@ In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro removedecor a
	.byte 0x4c
	.2byte \a
	.endm

	@ In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro testdecor a
	.byte 0x4d
	.2byte \a
	.endm

	@ In FireRed, this command is a nop. (The argument is read, but not used for anything.)
	.macro checkdecor a
	.byte 0x4e
	.2byte \a
	.endm

	@ Applies the movement data at movements to the specified (index) Person event. Also closes any standard message boxes that are still open.
	.macro move index, movements
	.byte 0x4f
	.2byte \index
	.4byte \movements
	.endm

	@ Apparent clone of applymovement. Oddly, it doesn't seem to work at all if applied to any Person other than the player (0xFF), and the X and Y arguments don't seem to do anything.
	@ This command in fact uses variables to access the Person event ID. So, for example, if you setvar 0x8000 to 0x3, and then use applymovementpos 0x8000 @move1, Person event 3 will have the movements at @move1 applied to them. Thank you Shiny Quagsire for bringing this to my attention.
	.macro movecoords variable, movements
	.byte 0x50
	.2byte \variable
	.4byte \movements
	.endm

	@ Blocks script execution until the movements being applied to the specified (index) Person event finish. If the specified Person event is 0x0000, then the command will block script execution until all Person events affected by applymovement finish their movements. If the specified Person event is not currently being manipulated with applymovement, then this command does nothing.
	.macro waitmove index
	.byte 0x51
	.2byte \index
	.endm

	@ Apparent clone of waitmovement. Oddly, it doesn't seem to work at all if applied to any Person other than the player (0xFF), and the X and Y arguments don't seem to do anything.
	.macro waitmovexy index, X, Y
	.byte 0x52
	.2byte \index
	.byte \X
	.byte \Y
	.endm

	@ Attempts to hide the specified (local_ID, a local ID) Person event on the current map, by setting its visibility flag if it has a valid one. If the Person does not have a valid visibility flag, this command does nothing.
	.macro disappear local_ID
	.byte 0x53
	.2byte \local_ID
	.endm

	@ Clone of hidesprite that also moves the Person? Test it!
	.macro disappearxy index, X, Y
	.byte 0x54
	.2byte \index
	.byte \X
	.byte \Y
	.endm

	.macro reappear word
	.byte 0x55
	.2byte \word
	.endm

	.macro reappearxy word, byte1, byte2
	.byte 0x56
	.2byte \word
	.byte \byte1
	.byte \byte2
	.endm

	.macro movesprite word1, word2, word3
	.byte 0x57
	.2byte \word1
	.2byte \word2
	.2byte \word3
	.endm

	.macro spritevisible word, byte1, byte2
	.byte 0x58
	.2byte \word
	.byte \byte1
	.byte \byte2
	.endm

	.macro spriteinvisible word, byte1, byte2
	.byte 0x59
	.2byte \word
	.byte \byte1
	.byte \byte2
	.endm

	@ If the script was called by a Person event, then that Person will turn to face toward the tile that the player is stepping off of.
	.macro faceplayer
	.byte 0x5a
	.endm

	.macro spriteface word, byte
	.byte 0x5b
	.2byte \word
	.byte \byte
	.endm

	@ If the Trainer flag for Trainer index is not set, this command does absolutely nothing.
	.macro trainerbattle byte, word1, word2, pointer1, pointer2, pointer3, pointer4
	.byte 0x5c
	.byte \byte
	.2byte \word1
	.2byte \word2
	.4byte \pointer1
	.4byte \pointer2
	.4byte \pointer3
	.4byte \pointer4
	.endm

	@ Starts a trainer battle using the battle information stored in RAM (usually by trainerbattle, which actually calls this command behind-the-scenes), and blocks script execution until the battle finishes.
	.macro reptrainerbattle
	.byte 0x5d
	.endm

	.macro endtrainerbattle
	.byte 0x5e
	.endm

	.macro endtrainerbattle2
	.byte 0x5f
	.endm

	@ Compares Flag (trainer + 0x500) to 1. (If the flag is set, then the trainer has been defeated by the player.)
	.macro checktrainerflag trainer
	.byte 0x60
	.2byte \trainer
	.endm

	@ Sets Flag (trainer + 0x500). (I didn't make a mistake. The command names actually are backwards.)
	.macro cleartrainerflag trainer
	.byte 0x61
	.2byte \trainer
	.endm

	@ Clears Flag (trainer + 0x500). (I didn't make a mistake. The command names actually are backwards.)
	.macro settrainerflag trainer
	.byte 0x62
	.2byte \trainer
	.endm

	.macro movespriteperm word1, word2, word3
	.byte 0x63
	.2byte \word1
	.2byte \word2
	.2byte \word3
	.endm

	.macro moveoffscreen word
	.byte 0x64
	.2byte \word
	.endm

	.macro spritebehave word, byte
	.byte 0x65
	.2byte \word
	.byte \byte
	.endm

	@ If a standard message box (or its text) is being drawn on-screen, this command blocks script execution until the box and its text have been fully drawn.
	.macro waittext
	.byte 0x66
	.endm

	@ Starts displaying a standard message box containing the specified text. If text is a pointer, then the string at that offset will be loaded and used. If text is script bank 0, then the value of script bank 0 will be treated as a pointer to the text. (You can use loadpointer to place a string pointer in a script bank.)
	.macro message text
	.byte 0x67
	.4byte \text
	.endm

	@ Holds the current message box open until the player presses a key. The message box is then closed.
	.macro closebutton
	.byte 0x68
	.endm

	@ Ceases movement for all OWs on-screen.
	.macro lockall
	.byte 0x69
	.endm

	@ If the script was called by a Person event, then that Person's movement will cease.
	.macro lock
	.byte 0x6a
	.endm

	@ Resumes normal movement for all OWs on-screen, and closes any standard message boxes that are still open.
	.macro releaseall
	.byte 0x6b
	.endm

	@ If the script was called by a Person event, then that Person's movement will resume. This command also closes any standard message boxes that are still open.
	.macro release
	.byte 0x6c
	.endm

	@ Blocks script execution until the player presses any key.
	.macro waitbutton
	.byte 0x6d
	.endm

	@ Displays a YES/NO multichoice box at the specified coordinates, and blocks script execution until the user makes a selection. Their selection is stored in variable 0x800D (LASTRESULT); 0x0000 for "NO" or if the user pressed B, and 0x0001 for "YES".
	.macro yesnobox X, Y
	.byte 0x6e
	.byte \X
	.byte \Y
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. If B is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoice X, Y, list, B
	.byte 0x6f
	.byte \X
	.byte \Y
	.byte \list
	.byte \B
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. The default argument determines the initial position of the cursor when the box is first opened; it is zero-indexed, and if it is too large, it is treated as 0x00. If B is set to a non-zero value, then the user will not be allowed to back out of the multichoice with the B button.
	.macro multichoicedef X, Y, list, default, B
	.byte 0x70
	.byte \X
	.byte \Y
	.byte \list
	.byte \default
	.byte \B
	.endm

	@ Displays a multichoice box from which the user can choose a selection, and blocks script execution until a selection is made. Lists of options are predefined and the one to be used is specified with list. The per_row argument determines how many list items will be shown on a single row of the box.
	.macro multichoicerow X, Y, list, per_row, B
	.byte 0x71
	.byte \X
	.byte \Y
	.byte \list
	.byte \per_row
	.byte \B
	.endm

	.macro showbox byte1, byte2, byte3, byte4
	.byte 0x72
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.byte \byte4
	.endm

	.macro hidebox byte1, byte2, byte3, byte4
	.byte 0x73
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.byte \byte4
	.endm

	.macro clearbox byte1, byte2, byte3, byte4
	.byte 0x74
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.byte \byte4
	.endm

	@ Displays a box containing the front sprite for the specified (species) Pokmon species.
	.macro showpokepic species, X, Y
	.byte 0x75
	.2byte \species
	.byte \X
	.byte \Y
	.endm

	@ Hides all boxes displayed with showpokepic.
	.macro hidepokepic
	.byte 0x76
	.endm

	@ In FireRed, this command is a nop. (The argument is discarded.)
	.macro showcontestwinner a
	.byte 0x77
	.byte \a
	.endm

	@ Displays the string at pointer as braille text in a standard message box. The string must be formatted to use braille characters.
	.macro braille text
	.byte 0x78
	.4byte \text
	.endm

	@ Gives the player one of the specified (species) Pokmon at level level holding item. The unknown arguments should all be zeroes.
	.macro givepokemon species, level, item, unknown1, unknown2, unknown3
	.byte 0x79
	.2byte \species
	.byte \level
	.2byte \item
	.4byte \unknown1
	.4byte \unknown2
	.byte \unknown3
	.endm

	.macro giveegg word
	.byte 0x7a
	.2byte \word
	.endm

	.macro setpokemove byte1, byte2, word
	.byte 0x7b
	.byte \byte1
	.byte \byte2
	.2byte \word
	.endm

	@ Checks if at least one Pokmon in the player's party knows the specified (index) attack. If so, variable 0x800D (LASTRESULT) is set to the (zero-indexed) slot number of the Pokmon that knows the move. If not, LASTRESULT is set to 0x0006.
	.macro checkattack index
	.byte 0x7c
	.2byte \index
	.endm

	@ Writes the name of the Pokmon at index species to the specified buffer.
	.macro bufferpoke out, species
	.byte 0x7d
	.byte \out
	.2byte \species
	.endm

	@ Writes the name of the first Pokmon in the player's party to the specified buffer.
	.macro bufferfirstpoke out
	.byte 0x7e
	.byte \out
	.endm

	@ Writes the name of the Pokmon in slot slot (zero-indexed) of the player's party to the specified buffer. If an empty or invalid slot is specified, ten spaces ("") are written to the buffer.
	.macro bufferpartypoke out, slot
	.byte 0x7f
	.byte \out
	.2byte \slot
	.endm

	@ Writes the name of the item at index item to the specified buffer. If the specified index is larger than the number of items in the game (0x176), the name of item 0 ("????????") is buffered instead.
	.macro bufferitem out, item
	.byte 0x80
	.byte \out
	.2byte \item
	.endm

	@ In FireRed, this command is a nop. (The first argument is discarded immediately. The second argument is read, but not used for anything.)
	.macro bufferdecor a, b
	.byte 0x81
	.byte \a
	.2byte \b
	.endm

	@ Writes the name of the attack at index attack to the specified buffer.
	.macro bufferattack out, attack
	.byte 0x82
	.byte \out
	.2byte \attack
	.endm

	@ Converts the value of input to a decimal string, and writes that string to the specified buffer.
	.macro buffernum out, input
	.byte 0x83
	.byte \out
	.2byte \input
	.endm

	@ Writes the standard string identified by index to the specified buffer. Specifying an invalid standard string (e.x. 0x2B) can and usually will cause data corruption (I've observed destruction of the stored player name and crashes when entering/exiting certain menu screens).
	.macro bufferstd out, index
	.byte 0x84
	.byte \out
	.2byte \index
	.endm

	@ Copies the string at offset to the specified buffer.
	.macro buffertext out, offset
	.byte 0x85
	.byte \out
	.4byte \offset
	.endm

	@ Opens the Pokemart system, offering the specified products for sale.
	.macro pokemart products
	.byte 0x86
	.4byte \products
	.endm

	@ Apparent clone of pokemart.
	.macro pokemartdecor products
	.byte 0x87
	.4byte \products
	.endm

	@ Apparent clone of pokemart.
	.macro pokemartbp products
	.byte 0x88
	.4byte \products
	.endm

	.macro pokecasino word
	.byte 0x89
	.2byte \word
	.endm

	@ In FireRed, this command is a nop.
	.macro event_8a
	.byte 0x8a
	.endm

	@ In FireRed, this command sets the byte at 0x03000EA8 to 0x01. I do not know what that means.
	.macro choosecontestpkmn
	.byte 0x8b
	.endm

	@ In FireRed, this command is a nop.
	.macro startcontest
	.byte 0x8c
	.endm

	@ In FireRed, this command is a nop.
	.macro showcontestresults
	.byte 0x8d
	.endm

	@ In FireRed, this command is a nop.
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
	.macro paymoney value, check
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
	.macro showmoney X, Y
	.byte 0x93
	.byte \X
	.byte \Y
	.endm

	@ Hides the secondary box spawned by showmoney.
	.macro hidemoney X, Y
	.byte 0x94
	.byte \X
	.byte \Y
	.endm

	@ Updates the secondary box spawned by showmoney. (What does it do with its arguments?)
	.macro updatemoney X, Y
	.byte 0x95
	.byte \X
	.byte \Y
	.endm

	@ In FireRed, this command is a nop.
	.macro event_96
	.byte 0x96
	.endm

	@ Fades the screen to black or back, using the specified effect. Effect 0x00 fades in, and effect 0x01 fades out. I don't know if other effects exist.
	.macro fadescreen effect
	.byte 0x97
	.byte \effect
	.endm

	.macro fadescreendelay byte1, byte2
	.byte 0x98
	.byte \byte1
	.byte \byte2
	.endm

	.macro darken word
	.byte 0x99
	.2byte \word
	.endm

	.macro lighten byte
	.byte 0x9a
	.byte \byte
	.endm

	.macro message2 pointer
	.byte 0x9b
	.4byte \pointer
	.endm

	@ Executes the specified field move animation.
	.macro doanimation animation
	.byte 0x9c
	.2byte \animation
	.endm

	@ Tells the game which party Pokmon to use for the next field move animation.
	.macro setanimation animation, slot
	.byte 0x9d
	.byte \animation
	.2byte \slot
	.endm

	@ Blocks script execution until all playing field move animations complete.
	.macro checkanimation animation
	.byte 0x9e
	.2byte \animation
	.endm

	@ Sets which healing place the player will return to if all of the Pokmon in their party faint. A list of available healing places can be found on PokeCommunity.
	.macro sethealplace flightspot
	.byte 0x9f
	.2byte \flightspot
	.endm

	@ Checks the player's gender. If male, then 0x0000 is stored in variable 0x800D (LASTRESULT). If female, then 0x0001 is stored in LASTRESULT.
	.macro checkgender
	.byte 0xa0
	.endm

	@ Plays the specified (species) Pokmon's cry. You can use waitcry to block script execution until the sound finishes.
	.macro pokecry species, effect
	.byte 0xa1
	.2byte \species
	.2byte \effect
	.endm

	@ Changes the tile at (X, Y) on the current map.
	.macro setmaptile X, Y, tile_number, tile_attrib
	.byte 0xa2
	.2byte \X
	.2byte \Y
	.2byte \tile_number
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
	.macro tileeffect subroutine
	.byte 0xa6
	.byte \subroutine
	.endm

	.macro setmapfooter word
	.byte 0xa7
	.2byte \word
	.endm

	.macro spritelevelup word, byte1, byte2, byte3
	.byte 0xa8
	.2byte \word
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.endm

	.macro restorespritelevel word, byte1, byte2
	.byte 0xa9
	.2byte \word
	.byte \byte1
	.byte \byte2
	.endm

	.macro createvsprite byte1, byte2, word1, word2, byte3, byte4
	.byte 0xaa
	.byte \byte1
	.byte \byte2
	.2byte \word1
	.2byte \word2
	.byte \byte3
	.byte \byte4
	.endm

	.macro vspriteface byte1, byte2
	.byte 0xab
	.byte \byte1
	.byte \byte2
	.endm

	@ Queues the opening of the door tile at (X, Y) with an animation.
	.macro setdooropened X, Y
	.byte 0xac
	.2byte \X
	.2byte \Y
	.endm

	@ Queues the closing of the door tile at (X, Y) with an animation.
	.macro setdoorclosed X, Y
	.byte 0xad
	.2byte \X
	.2byte \Y
	.endm

	@ Executes the state changes queued with setdooropened, setdoorclosed, setdooropened2, and setdoorclosed2.
	.macro doorchange
	.byte 0xae
	.endm

	@ Queues the opening of the door tile at (X, Y) without an animation.
	.macro setdooropened2 X, Y
	.byte 0xaf
	.2byte \X
	.2byte \Y
	.endm

	@ Queues the closing of the door tile at (X, Y) without an animation.
	.macro setdoorclosed2 X, Y
	.byte 0xb0
	.2byte \X
	.2byte \Y
	.endm

	@ In FireRed, this command is a nop.
	.macro event_b1
	.byte 0xb1
	.endm

	@ In FireRed, this command is a nop.
	.macro event_b2
	.byte 0xb2
	.endm

	.macro checkcoins word
	.byte 0xb3
	.2byte \word
	.endm

	.macro givecoins word
	.byte 0xb4
	.2byte \word
	.endm

	.macro removecoins word
	.byte 0xb5
	.2byte \word
	.endm

	@ Prepares to start a wild battle against a species at Level level holding item. Running this command will not affect normal wild battles. You start the prepared battle with dowildbattle.
	.macro setwildbattle species, level, item
	.byte 0xb6
	.2byte \species
	.byte \level
	.2byte \item
	.endm

	@ Starts a wild battle against the Pokmon generated by setwildbattle. Blocks script execution until the battle finishes.
	.macro dowildbattle
	.byte 0xb7
	.endm

	.macro setvaddress long, word
	.byte 0xb8
	.4byte \long
	.2byte \word
	.endm

	.macro vjump pointer
	.byte 0xb9
	.4byte \pointer
	.endm

	.macro vcall pointer
	.byte 0xba
	.4byte \pointer
	.endm

	.macro if5 byte, pointer
	.byte 0xbb
	.byte \byte
	.4byte \pointer
	.endm

	.macro if6 byte, pointer
	.byte 0xbc
	.byte \byte
	.4byte \pointer
	.endm

	.macro vtext pointer
	.byte 0xbd
	.4byte \pointer
	.endm

	.macro vloadptr pointer
	.byte 0xbe
	.4byte \pointer
	.endm

	.macro vbuffer byte, pointer
	.byte 0xbf
	.byte \byte
	.4byte \pointer
	.endm

	@ Spawns a secondary box showing how many Coins the player has.
	.macro showcoins X, Y
	.byte 0xc0
	.byte \X
	.byte \Y
	.endm

	@ Hides the secondary box spawned by showcoins. It doesn't appear to use its arguments, but they are still required.
	.macro hidecoins X, Y
	.byte 0xc1
	.byte \X
	.byte \Y
	.endm

	@ Updates the secondary box spawned by showcoins. (What does it do with its arguments?)
	.macro updatecoins X, Y
	.byte 0xc2
	.byte \X
	.byte \Y
	.endm

	@ Increases the value of the specified hidden variable by 1. The hidden variable's value will not be allowed to exceed 0x00FFFFFF.
	.macro inccounter a
	.byte 0xc3
	.byte \a
	.endm

	@ Clone of warp... Except that it doesn't appear to have any effect when used in some of FireRed's default level scripts. (If it did, Berry Forest would be impossible to enter...)
	.macro warp6
	.byte 0xc4
	.endm

	@ Blocks script execution until cry finishes.
	.macro waitpokecry
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

	@ Makes the Pokmon in the specified slot of the player's party obedient. It will not randomly disobey orders in battle.
	.macro setobedience slot
	.byte 0xcd
	.2byte \slot
	.endm

	@ Checks if the Pokmon in the specified slot of the player's party is obedient. If the Pokmon is disobedient, 0x0001 is written to script variable 0x800D (LASTRESULT). If the Pokmon is obedient (or if the specified slot is empty or invalid), 0x0000 is written.
	.macro checkobedience slot
	.byte 0xce
	.2byte \slot
	.endm

	@ Depending on factors I haven't managed to understand yet, this command may cause script execution to jump to the offset specified by the pointer at 0x020370A4.
	.macro execram
	.byte 0xcf
	.endm

	@ Sets worldmapflag to 1. This allows the player to Fly to the corresponding map, if that map has a flightspot.
	.macro setworldflag worldmapflag
	.byte 0xd0
	.2byte \worldmapflag
	.endm

	@ Clone of warpteleport? It is apparently only used in FR/LG, and only with specials.[source]
	.macro warpteleport2
	.byte 0xd1
	.endm

	@ Changes the location where the player caught the Pokmon in the specified slot of their party. A list of valid catch locations can be found on PokeCommunity.
	.macro setcatchlocale slot, location
	.byte 0xd2
	.2byte \slot
	.byte \location
	.endm

	@ Sets variable 0x8004 to a value based on the width of the braille string at text.
	.macro braille2 text
	.byte 0xd3
	.4byte \text
	.endm

	@ Writes the name of the specified (item) item to the specified buffer. If the specified item is a Berry (0x85 - 0xAE) or Poke Ball (0x4) and if the quantity is 2 or more, the buffered string will be pluralized ("IES" or "S" appended). If the specified item is the Enigma Berry, I have no idea what this command does (but testing showed no pluralization). If the specified index is larger than the number of items in the game (0x176), the name of item 0 ("????????") is buffered instead.
	.macro storeitems out, item, quantity
	.byte 0xd4
	.byte \out
	.2byte \item
	.2byte \quantity
	.endm

	@ In FireRed, this command is a nop.
	.macro event_d5
	.byte 0xd5
	.endm

	.macro event_d6
	.byte 0xd6
	.endm

	.macro warp7 byte1, byte2, byte3, word1, word2
	.byte 0xd7
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.2byte \word1
	.2byte \word2
	.endm

	.macro event_d8
	.byte 0xd8
	.endm

	.macro event_d9
	.byte 0xd9
	.endm

	.macro hidebox2
	.byte 0xda
	.endm

	.macro message3 pointer
	.byte 0xdb
	.4byte \pointer
	.endm

	.macro fadescreen3 byte
	.byte 0xdc
	.byte \byte
	.endm

	.macro buffertrainerclass byte, word
	.byte 0xdd
	.byte \byte
	.2byte \word
	.endm

	.macro buffertrainername byte, word
	.byte 0xde
	.byte \byte
	.2byte \word
	.endm

	.macro pokenavcall pointer
	.byte 0xdf
	.4byte \pointer
	.endm

	.macro warp8 byte1, byte2, byte3, word1, word2
	.byte 0xe0
	.byte \byte1
	.byte \byte2
	.byte \byte3
	.2byte \word1
	.2byte \word2
	.endm

	.macro buffercontesttype byte, word
	.byte 0xe1
	.byte \byte
	.2byte \word
	.endm

	.macro storeitems2 byte, word1, word2
	.byte 0xe2
	.byte \byte
	.2byte \word1
	.2byte \word2
	.endm
