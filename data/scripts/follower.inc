gText_FollowerLovesYou::
  .string "{STR_VAR_1} loves you!$"

gText_FollowerLostInThought::
  .string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
  .string "ERROR 404: Script not found.$"

gText_FollowerHasWetFeet::
  .string "{STR_VAR_1} frowns at you. It shuffles\nits wet feet.$"

gText_FollowerSplashesAround::
  .string "{STR_VAR_1} splashes around happily!$"

gText_WantsToFly::
  .string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

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
  checkpartymove MOVE_FLY
  compare VAR_RESULT 6
  goto_if_eq EventScript_FollowerEnd
  bufferlivemonspeciesname 0
  msgbox gText_WantsToFly, MSGBOX_YESNO
  switch VAR_RESULT
  case NO, EventScript_FollowerEnd
  case YES, EventScript_FollowerFly
  case MULTI_B_PRESSED, EventScript_FollowerEnd
EventScript_FollowerFly::
  callfunc ScrFunc_followerfly
EventScript_FollowerEnd::
  release
  end

EventScript_FollowerHasWetFeet::
  bufferlivemonspeciesname 0
  playfirstmoncry
  msgbox gText_FollowerHasWetFeet, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerSplashesAbout::
  bufferlivemonspeciesname 0
  playfirstmoncry
  applymovement 0xFE FollowerSplashMovement
  waitmovement 0xFE
  msgbox gText_FollowerSplashesAround, MSGBOX_DEFAULT
  return

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
  return
