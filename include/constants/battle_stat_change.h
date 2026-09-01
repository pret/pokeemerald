#ifndef GUARD_CONSTANTS_BATTLE_MOVE_STAT_CHANGE_H
#define GUARD_CONSTANTS_BATTLE_MOVE_STAT_CHANGE_H

enum StatChangeResult
{
    STAT_CHANGE_WORKED,
    STAT_CHANGE_DIDNT_WORK,
    STAT_CHANGE_BLOCKED_BY_TARGET,
};

#define STAT_CHANGE_NO_FLAGS             0
#define STAT_CHANGE_ONLY_CHECKING       (1 << 0)
#define STAT_CHANGE_IGNORE_SELF         (1 << 1)
#define STAT_CHANGE_IGNORE_MIRROR_ARMOR (1 << 2)
#define STAT_CHANGE_SILENT_FAILURE      (1 << 3)
#define STAT_CHANGE_INTIMIDATE          (1 << 4)
#define STAT_CHANGE_SECOND_QUEUE        (1 << 5)
#define STAT_CHANGE_CERTAIN             (1 << 6)
#define STAT_CHANGE_ITEM                (1 << 7)
#define STAT_CHANGE_DEFOG               (1 << 8)
#define STAT_CHANGE_STICKY_WEB          (1 << 9)
#define STAT_CHANGE_MIRROR_HERB         (1 << 10)
#define STAT_CHANGE_OPPORTUNIST         (1 << 11)

#endif // GUARD_BATTLE_MOVE_STAT_CHANGE_H
