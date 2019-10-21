    .include "asm/macros.inc"

    .section .rodata

RotatingTilePuzzle_Movement_ShiftRight:: @ 8612698
    store_lock_anim
    walk_right
    free_unlock_anim
    step_end

RotatingTilePuzzle_Movement_ShiftDown:: @ 861269C
    store_lock_anim
    walk_down
    free_unlock_anim
    step_end

RotatingTilePuzzle_Movement_ShiftLeft:: @ 86126A0
    store_lock_anim
    walk_left
    free_unlock_anim
    step_end

RotatingTilePuzzle_Movement_ShiftUp:: @ 86126A4
    store_lock_anim
    walk_up
    free_unlock_anim
    step_end

RotatingTilePuzzle_Movement_FaceRight:: @ 86126A8
    face_right
    step_end

RotatingTilePuzzle_Movement_FaceDown:: @ 86126AA
    face_down
    step_end

RotatingTilePuzzle_Movement_FaceLeft:: @ 86126AC
    face_left
    step_end

RotatingTilePuzzle_Movement_FaceUp:: @ 86126AE
    face_up
    step_end
