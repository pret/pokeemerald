gText_FollowerLovesYou::
  .string "123456789012345678901234567890123\n$"

gText_FollowerLostInThought::
  .string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
  .string "ERROR 404: Script not found.$"

gText_FollowerUnhappyToBeWet::
  .string "{STR_VAR_1} looks unhappy to be wet.$"

gText_FollowerSplashesAround::
  .string "{STR_VAR_1} splashes around happily!$"

gText_WantsToFly::
  .string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

gText_FollowerUnhappyFace::
  .string "{STR_VAR_1} is making an unhappy face...$"

gText_FollowerHappyRain::
  .string "{STR_VAR_1} seems to be happy\nabout the rain!$"

gText_FollowerMetLocation::
  .string "{STR_VAR_1} looks around fondly.\nIt seems familiar with this place.$"

gText_FollowerSkeptical::
  .string "{STR_VAR_1} looks skeptical...\pWhat could it mean?$"

gText_FollowerAppraising::
  .string "{STR_VAR_1} carefully follows behind.$"

gText_FollowerHappyWalk::
  .string "{STR_VAR_1} skips happily behind you!$"

gText_FollowerAboutToFall::
  .string "{STR_VAR_1} seems to be about\nto fall over!$"

gText_FollowerTryingToKeepUp::
  .string "{STR_VAR_1} is trying very hard\nto keep up with you...$"

gText_FollowerIsShivering::
  .string "{STR_VAR_1} is shivering.$"

gText_FollowerBurnPainful::
  .string "{STR_VAR_1}'s burn looks painful!$'"

.macro playfirstmoncry
callfunc ScrFunc_playfirstmoncry
.endm

.macro bufferlivemonspeciesname out:req
callfunc ScrFunc_bufferlivemonspeciesname
.byte \out
.endm

.macro emote obj:req id:req
callfunc ScrFunc_emote
.byte \obj
.byte \id
.endm

EventScript_Follower::
  lock
  faceplayer
  bufferlivemonspeciesname 0
  playfirstmoncry
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
  waitfieldeffect FLDEFF_EMOTE
  release
  end

EventScript_FollowerHappyWalk::
  msgbox gText_FollowerHappyWalk, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerAppraising::
  msgbox gText_FollowerAppraising, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerSkeptical::
  msgbox gText_FollowerSkeptical, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerMetLocation::
  applymovement 0xFE Common_Movement_QuestionMark
  waitmoncry
  waitmovement 0xFE
  msgbox gText_FollowerMetLocation, MSGBOX_DEFAULT
  return

EventScript_FollowerUnhappyFace::
  msgbox gText_FollowerUnhappyFace, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerHappyRain::
  msgbox gText_FollowerHappyRain, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerUnhappyToBeWet::
  msgbox gText_FollowerUnhappyToBeWet, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerSplashesAbout::
  applymovement 0xFE FollowerSplashMovement
  waitmovement 0xFE
  msgbox gText_FollowerSplashesAround, MSGBOX_DEFAULT
  return

EventScript_FollowerLovesYou::
  applymovement 0xFE ContestHall_Movement_Heart
  waitmovement 0xFE
  waitmoncry
  msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
  return

EventScript_FollowerAboutToFall::
  msgbox gText_FollowerAboutToFall, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerTryingToKeepUp::
  msgbox gText_FollowerTryingToKeepUp, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerIsShivering::
  msgbox gText_FollowerIsShivering, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerBurnPainful::
  msgbox gText_FollowerBurnPainful, MSGBOX_DEFAULT
  waitmoncry
  return

@ Message address must be loaded into bank 0
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
  waitfieldeffect FLDEFF_EMOTE
  message 0x0
  waitmessage
  waitbuttonpress
  return

EventScript_FollowerJump::
  applymovement 0xFE FollowerSplashMovement
  waitmovement 0xFE
  waitfieldeffect FLDEFF_EMOTE
  message 0x0
  waitmessage
  waitbuttonpress
  return

EnterPokeballMovement::
  .byte 0x9F @ EnterPokeball
  step_end

FollowerSplashMovement:: @ defined in movement.inc
  jump_in_place_down
  delay_4
  jump_in_place_down
  face_player
  step_end
