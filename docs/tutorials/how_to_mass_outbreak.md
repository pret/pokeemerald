# Mass outbreaks

## Vanilla mass outbreaks

After you've beaten the game, there is a one in 200 chance everytime you finish a battle to add a mass outbreak program to the list of active tv shows. When adding a mass outbreak program, the game will roll a random mass outbreak from the mass outbreak table and add it to the tv show data. After two days have passed, if there is no mass outbreak active in the overwold, you can watch the mass outbreak program on TV and this is start the mass outbreak that you rolled earlier.

## Expansion features

### Static outbreaks

The data in the mass outbreak data table has been expanded, properties that previously existed only on the save file for active mass outbreak can now be set in the mass outbreak data table (map group, probability, duration). These were previously fixed in vanilla and can now be changed. The complete list of fields is:

- `species` : the species of the mass outbreak encounter
- `moves` : the moves the mas outbreak encounter has
- `level` : the level of the mass outbreak encounter
- `location` : the map id where the mass outbreak is happening
- `probability` : the percent chance you get a mass outbreak encounter instead of a regular wild encounter
- `duration` : the number of days the mass outbreak will last

All the properties are preserved even when the outbreak is started the "vanilla" way. Because they are stored in a ROM table and immutable, they are referred as static outbreaks. However expansion also adds the possiblity to create new outbreaks at run time or change outbreaks that are already happening. We call those dynamic outbreaks.

### Dynamic outbreaks

You can interact with outbreak through script commands or through the debug menu (Encounters -> Mass Outbreaks submenu).
The following commands are available to the user:

 - `startoutbreak` : starts an outbreak (will not work if there is already an active outbreak). Can start an active outbreak is used with  a number/constant `startoutbreak OUTBREAK_ROUTE102` or can start a dynamic by specifying each parameter
 - `editoutbreak`: changes the properties of an active outbreak
 - `clearactiveoutbreak`:  ends the current active outbreak
 - `checkhasactiveoutbreak`: sets var result to TRUE if a outbreak is active and FALSE if there is no active outbreak
 - `getmassoutbreakdata`: allows you to set the properties of the active outbreak into a variable


#### `startoutbreak` / `editoutbreak`

When starting or modifying an outbreak, the function is by default called with these values
`species=SPECIES_NONE, level=0, move1=MOVES_COUNT, move2=MOVES_COUNT, move3=MOVES_COUNT, move4=MOVES_COUNT, probability=0xFF, daysLeft=0x3FFF, map=MAP_UNDEFINED`

These are default values that tells the game nothing needs to change. So you can set one, multiple or all values at the same time when calling the command.

