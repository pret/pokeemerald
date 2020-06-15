gText_FollowerLovesYou::
  .string "{STR_VAR_1} loves you!$"

gText_FollowerLostInThought::
  .string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
  .string "ERROR 404: Script not found.$"

gText_FollowerHasWetFeet::
  .string "{STR_VAR_1} seems unhappy about getting\nits feet wet.$"

gText_FollowerSplashesAround::
  .string "{STR_VAR_1} splashes around happily!$"

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
  callfunc ScrFunc_getfolloweraction
  msgbox gText_FollowerDefault, MSGBOX_DEFAULT
  release
  end

EventScript_FollowerHasWetFeet::
  bufferlivemonspeciesname 0
  playfirstmoncry
  msgbox gText_FollowerHasWetFeet, MSGBOX_DEFAULT
  waitmoncry
  release
  end

EventScript_FollowerSplashesAbout::
  bufferlivemonspeciesname 0
  playfirstmoncry
  applymovement 0xFE FollowerSplashMovement
  waitmovement 0xFE
  msgbox gText_FollowerSplashesAround, MSGBOX_DEFAULT
  release
  end

EnterPokeballMovement::
  .byte 0x9F @ EnterPokeball
  step_end

FollowerSplashMovement::
  jump_in_place_left_right
  jump_in_place_left_right
  face_player
  step_end

EventScript_FollowerLovesYou::
  playfirstmoncry
  applymovement 0xFE ContestHall_Movement_Heart
  waitmovement 0xFE
  waitmoncry
  bufferlivemonspeciesname 0
  msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
  release
  end
