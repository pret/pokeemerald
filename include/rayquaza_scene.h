#ifndef GUARD_RAYQUAZA_SCENE_H
#define GUARD_RAYQUAZA_SCENE_H

void DoRayquazaScene(u8 animId, bool8 onlyOneAnim, void (*callback)(void));

enum
{
    RAY_ANIM_DUO_FIGHT_PRE,
    RAY_ANIM_DUO_FIGHT,
    RAY_ANIM_TAKES_FLIGHT,
    RAY_ANIM_DESCENDS,
    RAY_ANIM_CHARGES,
    RAY_ANIM_CHACES_AWAY,
    RAY_ANIM_END
};

#endif // GUARD_RAYQUAZA_SCENE_H
