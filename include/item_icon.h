//
// Created by scott on 10/20/2017.
//

#ifndef GUARD_ITEM_ICON_H
#define GUARD_ITEM_ICON_H

extern EWRAM_DATA void *gUnknown_0203CEBC;
extern EWRAM_DATA void *gUnknown_0203CEC0;

extern const struct SpriteTemplate gUnknown_08614FF4;

bool8 AllocItemIconTemporaryBuffers(void);
void CopyItemIconPicTo4x4Buffer(void *src, void *dest);
void FreeItemIconTemporaryBuffers(void);

#endif //GUARD_ITEM_ICON_H
