#ifndef GUARD_TYPE_ICONS_H
#define GUARD_TYPE_ICONS_H

void LoadTypeIcons(enum BattlerId battler);

#define TYPE_ICON_TAG 0x2720
#define TYPE_ICON_TAG_2 0x2721
#define NUM_FRAMES_HIDE_TYPE_ICON 10

#define tMonPosition      data[0]
#define tBattlerId        data[1]
#define tHideIconTimer    data[2]
#define tVerticalPosition data[3]

#define TYPE_ICON_1_FRAME(monType) ((monType - 1) * 2)
#define TYPE_ICON_2_FRAME(monType) ((monType - 11) * 2)

#endif // GUARD_TYPE_ICONS_H
