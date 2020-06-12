gText_Follower::
  .string "{STR_VAR_1} loves you!$"

.macro playfirstmoncry
callfunc ScrFunc_playfirstmoncry
.endm

.macro bufferlivemonspeciesname out:req
callfunc ScrFunc_bufferlivemonspeciesname
.byte \out
.endm


EventScript_Follower::
  lock
  faceplayer
  playfirstmoncry
  applymovement 0xFE ContestHall_Movement_Heart
  waitmoncry
  bufferlivemonspeciesname 0
  msgbox gText_Follower, MSGBOX_DEFAULT
  release
  end
