#ifndef GUARD_DATA2_H
#define GUARD_DATA2_H

struct MonCoords
{
    // This would use a bitfield, but some function
    // uses it as a u8 and casting won't match.
    u8 coords; // u8 x:4, y:4;
    u8 y_offset;
};

extern struct MonCoords gTrainerBackPicCoords[];
extern struct MonCoords gTrainerFrontPicCoords[];

extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const u8 gMoveNames[][13];
extern const u8 gAbilityNames[][13];
extern const u8 gTypeNames[][7];

#endif // GUARD_DATA2_H
