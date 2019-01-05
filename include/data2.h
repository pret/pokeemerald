#ifndef GUARD_DATA2_H
#define GUARD_DATA2_H

struct MonCoords
{
    // This would use a bitfield, but some function
    // uses it as a u8 and casting won't match.
    u8 size; // u8 width:4, height:4;
    u8 y_offset;
};

extern const struct MonCoords gTrainerBackPicCoords[];
extern const struct MonCoords gTrainerFrontPicCoords[];

extern const u8 gSpeciesNames[][POKEMON_NAME_LENGTH + 1];
extern const u8 gMoveNames[][MOVE_NAME_LENGTH + 1];
extern struct CompressedSpriteSheet gUnknown_0831C620;
extern struct CompressedSpritePalette gUnknown_0831C628;
extern const struct SpriteTemplate gUnknown_0831C688;
extern const struct CompressedSpriteSheet gMonBackPicTable[];

#endif // GUARD_DATA2_H
