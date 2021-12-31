gText_FollowerLovesYou::
  .string "123456789012345678901234567890123\n$"

gText_FollowerLostInThought::
  .string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
  .string "ERROR 404: Script not found.$"

gText_WantsToFly::
  .string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

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

EventScript_FollowerLovesYou::
  applymovement 0xFE ContestHall_Movement_Heart
  waitmovement 0xFE
  waitmoncry
  msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
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

@ Movement scripts below, movements are defined in movement.inc

FollowerSplashMovement::
  jump_in_place_down
  delay_4
  jump_in_place_down
  face_player
  step_end

FollowerShiverVerticalMovement:
  lock_facing_direction
  slide_left
  slide_right
  slide_right
  slide_left
  unlock_facing_direction
  step_end

FollowerShiverHorizontalMovement:
  lock_facing_direction
  slide_up
  slide_down
  slide_down
  slide_up
  unlock_facing_direction
  step_end

FollowerNostalgiaMovement:
  face_away_player
  lock_facing_direction
  jump_in_place_down
  jump_in_place_down
  jump_in_place_down
  unlock_facing_direction
  face_player
  lock_facing_direction
  jump_in_place_down
  unlock_facing_direction
  step_end

FollowerSkippingMovement:
  lock_facing_direction
  jump_in_place_down
  delay_4
  jump_in_place_down
  unlock_facing_direction
  step_end

FollowerJumpOnPlayerNorth:
  jump_up
  delay_4
  lock_facing_direction
  walk_fast_down
  unlock_facing_direction
  step_end

FollowerJumpOnPlayerSouth:
  jump_down
  delay_4
  lock_facing_direction
  walk_fast_up
  unlock_facing_direction
  step_end

FollowerJumpOnPlayerEast:
  jump_right
  delay_4
  lock_facing_direction
  walk_fast_left
  unlock_facing_direction
  step_end

FollowerJumpOnPlayerWest:
  jump_left
  delay_4
  lock_facing_direction
  walk_fast_right
  unlock_facing_direction
  step_end

FollowerCuddlingNorth:
  face_left
  lock_facing_direction
  walk_up
  walk_in_place_left
  walk_in_place_left
  unlock_facing_direction
  walk_down
  face_player
  step_end

FollowerCuddlingSouth:
  face_right
  lock_facing_direction
  walk_down
  walk_in_place_right
  walk_in_place_right
  unlock_facing_direction
  walk_up
  face_player
  step_end

FollowerCuddlingEast:
  face_down
  lock_facing_direction
  walk_right
  walk_in_place_down
  walk_in_place_down
  unlock_facing_direction
  walk_left
  face_player
  step_end

FollowerCuddlingWest:
  face_down
  lock_facing_direction
  walk_left
  walk_in_place_down
  walk_in_place_down
  unlock_facing_direction
  walk_right
  face_player
  step_end

FollowerGetCloserNorth:
  walk_up
  delay_16
  lock_facing_direction
  walk_down
  unlock_facing_direction
  step_end

FollowerGetCloserSouth:
  walk_down
  delay_16
  lock_facing_direction
  walk_up
  unlock_facing_direction
  step_end

FollowerGetCloserEast:
  walk_right
  delay_16
  lock_facing_direction
  walk_left
  unlock_facing_direction
  step_end

FollowerGetCloserWest:
  walk_left
  delay_16
  lock_facing_direction
  walk_right
  unlock_facing_direction
  step_end

FollowerPokeNorth:
  walk_faster_up
  delay_8
  lock_facing_direction
  walk_faster_down
  delay_4
  walk_faster_up
  delay_4
  walk_faster_down
  unlock_facing_direction
  step_end

FollowerPokeSouth:
  walk_faster_down
  delay_8
  lock_facing_direction
  walk_faster_up
  delay_4
  walk_faster_down
  delay_4
  walk_faster_up
  unlock_facing_direction
  step_end

FollowerPokeEast:
  walk_faster_right
  delay_8
  lock_facing_direction
  walk_faster_left
  delay_4
  walk_faster_right
  delay_4
  walk_faster_left
  unlock_facing_direction
  step_end

FollowerPokeWest:
  walk_faster_left
  delay_8
  lock_facing_direction
  walk_faster_right
  delay_4
  walk_faster_left
  delay_4
  walk_faster_right
  unlock_facing_direction
  step_end

FollowerLookAround:
  face_away_player
  delay_16
  delay_16
  face_left
  delay_16
  delay_16
  face_up
  delay_16
  delay_16
  face_down
  delay_16
  delay_16
  step_end

FollowerLookAway:
  face_away_player
  delay_16
  delay_16
  step_end

FollowerLookAwayBark:
  face_away_player
  lock_facing_direction
  jump_in_place_down
  jump_in_place_down
  unlock_facing_direction
  step_end

FollowerLookAwayPokeG:
  face_away_player
  lock_facing_direction
  walk_in_place_down
  walk_in_place_down
  walk_in_place_down
  unlock_facing_direction
  step_end

FollowerPokeGround:
  lock_facing_direction
  walk_in_place_down
  walk_in_place_down
  walk_in_place_down
  unlock_facing_direction
  step_end

FollowerStartled:
  face_away_player
  lock_facing_direction
  jump_in_place_down
  unlock_facing_direction
  face_player
  step_end

FollowerHopFast:
  jump_in_place_up
  jump_in_place_down
  jump_in_place_left
  jump_in_place_right
  face_player
  step_end

FollowerDizzy:
  walk_in_place_left
  walk_in_place_fast_right
  walk_in_place_slow_up
  walk_in_place_fast_down
  delay_4
  face_away_player
  step_end

FollowerLookAroundScared:
  face_up
  delay_16
  face_down
  delay_16
  face_left
  delay_16
  face_right
  delay_16
  face_up
  delay_16
  face_down
  delay_16
  face_left
  delay_16
  face_right
  delay_16
  face_player
  step_end

FollowerDance:
  lock_facing_direction
  jump_in_place_up
  unlock_facing_direction
  walk_in_place_faster_up
  walk_in_place_faster_left
  walk_in_place_faster_down
  walk_in_place_faster_right
  walk_in_place_faster_up
  walk_in_place_faster_left
  walk_in_place_faster_down
  walk_in_place_faster_right
  walk_in_place_faster_up
  walk_in_place_faster_left
  walk_in_place_faster_down
  walk_in_place_faster_right
  walk_in_place_faster_up
  walk_in_place_faster_left
  walk_in_place_faster_down
  walk_in_place_faster_right
  walk_in_place_faster_up
  walk_in_place_faster_left
  walk_in_place_faster_down
  walk_in_place_faster_right
  jump_in_place_up
  jump_in_place_down
  jump_in_place_up
  face_player
  step_end

@ Movement scripts

EventScript_FollowerIsShivering::
  compare VAR_FACING, DIR_NORTH
  call_if_eq ShiverVertical
  compare VAR_FACING, DIR_SOUTH
  call_if_eq ShiverVertical
  compare VAR_FACING, DIR_WEST
  call_if_eq ShiverHorizontal
  compare VAR_FACING, DIR_EAST
  call_if_eq ShiverHorizontal
  goto EventScript_FollowerGeneric

ShiverVertical:
  applymovement 0xFE FollowerShiverVerticalMovement
  waitmovement 0xFE
  return

ShiverHorizontal:
  applymovement 0xFE FollowerShiverHorizontalMovement
  waitmovement 0xFE
  return

EventScript_FollowerNostalgia::
  applymovement 0xFE FollowerNostalgiaMovement
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerHopping::
  applymovement 0xFE FollowerSkippingMovement
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

JumpOnN:
  applymovement 0xFE FollowerJumpOnPlayerNorth
  waitmovement 0xFE
  return

JumpOnS:
  applymovement 0xFE FollowerJumpOnPlayerSouth
  waitmovement 0xFE
  return

JumpOnE:
  applymovement 0xFE FollowerJumpOnPlayerEast
  waitmovement 0xFE
  return

JumpOnW:
  applymovement 0xFE FollowerJumpOnPlayerWest
  waitmovement 0xFE
  return

EventScript_FollowerJumpOnPlayer::
  compare VAR_FACING, DIR_NORTH
  call_if_eq JumpOnS
  compare VAR_FACING, DIR_SOUTH
  call_if_eq JumpOnN
  compare VAR_FACING, DIR_WEST
  call_if_eq JumpOnE
  compare VAR_FACING, DIR_EAST
  call_if_eq JumpOnW
  goto EventScript_FollowerGeneric

CuddleN:
  applymovement 0xFE FollowerCuddlingNorth
  waitmovement 0xFE
  return

CuddleS:
  applymovement 0xFE FollowerCuddlingSouth
  waitmovement 0xFE
  return

CuddleE:
  applymovement 0xFE FollowerCuddlingEast
  waitmovement 0xFE
  return

CuddleW:
  applymovement 0xFE FollowerCuddlingWest
  waitmovement 0xFE
  return

EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
  compare VAR_FACING, DIR_NORTH
  call_if_eq CuddleS
  compare VAR_FACING, DIR_SOUTH
  call_if_eq CuddleN
  compare VAR_FACING, DIR_WEST
  call_if_eq CuddleE
  compare VAR_FACING, DIR_EAST
  call_if_eq CuddleW
  goto EventScript_FollowerGeneric

ShCuddleN:
  applymovement 0xFE FollowerShiverVerticalMovement
  waitmovement 0xFE
  applymovement 0xFE FollowerCuddlingNorth
  waitmovement 0xFE
  return

ShCuddleS:
  applymovement 0xFE FollowerShiverVerticalMovement
  waitmovement 0xFE
  applymovement 0xFE FollowerCuddlingSouth
  waitmovement 0xFE
  return

ShCuddleE:
  applymovement 0xFE FollowerShiverHorizontalMovement
  waitmovement 0xFE
  applymovement 0xFE FollowerCuddlingEast
  waitmovement 0xFE
  return

ShCuddleW:
  applymovement 0xFE FollowerShiverHorizontalMovement
  waitmovement 0xFE
  applymovement 0xFE FollowerCuddlingWest
  waitmovement 0xFE
  return

EventScript_FollowerShiverCuddling::
  compare VAR_FACING, DIR_NORTH
  call_if_eq ShCuddleS
  compare VAR_FACING, DIR_SOUTH
  call_if_eq ShCuddleN
  compare VAR_FACING, DIR_WEST
  call_if_eq ShCuddleE
  compare VAR_FACING, DIR_EAST
  call_if_eq ShCuddleW
  goto EventScript_FollowerGeneric

CreepCloserN:
  applymovement 0xFE FollowerGetCloserNorth
  waitmovement 0xFE
  return

CreepCloserS:
  applymovement 0xFE FollowerGetCloserSouth
  waitmovement 0xFE
  return

CreepCloserE:
  applymovement 0xFE FollowerGetCloserEast
  waitmovement 0xFE
  return

CreepCloserW:
  applymovement 0xFE FollowerGetCloserWest
  waitmovement 0xFE
  return

EventScript_FollowerGetCloser::
  compare VAR_FACING, DIR_NORTH
  call_if_eq CreepCloserS
  compare VAR_FACING, DIR_SOUTH
  call_if_eq CreepCloserN
  compare VAR_FACING, DIR_WEST
  call_if_eq CreepCloserE
  compare VAR_FACING, DIR_EAST
  call_if_eq CreepCloserW
  goto EventScript_FollowerGeneric

PokePlayerN:
  applymovement 0xFE FollowerGetCloserNorth
  waitmovement 0xFE
  return

PokePlayerS:
  applymovement 0xFE FollowerGetCloserSouth
  waitmovement 0xFE
  return

PokePlayerE:
  applymovement 0xFE FollowerGetCloserEast
  waitmovement 0xFE
  return

PokePlayerW:
  applymovement 0xFE FollowerGetCloserWest
  waitmovement 0xFE
  return

EventScript_FollowerPokingPlayer::
  compare VAR_FACING, DIR_NORTH
  call_if_eq PokePlayerS
  compare VAR_FACING, DIR_SOUTH
  call_if_eq PokePlayerN
  compare VAR_FACING, DIR_WEST
  call_if_eq PokePlayerE
  compare VAR_FACING, DIR_EAST
  call_if_eq PokePlayerW
  goto EventScript_FollowerGeneric

EventScript_FollowerLookAround::
  applymovement 0xFE FollowerLookAround
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerLookAway::
  applymovement 0xFE FollowerLookAway
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerLookAwayBark::
  applymovement 0xFE FollowerLookAwayBark
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerLookAwayPoke::
  applymovement 0xFE FollowerLookAwayPokeG
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerPokeGround::
  applymovement 0xFE FollowerPokeGround
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerStartled::
  applymovement 0xFE FollowerStartled
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerFastHopping::
  applymovement 0xFE FollowerHopFast
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerDizzy::
  applymovement 0xFE FollowerDizzy
  waitmovement 0
  goto EventScript_FollowerGeneric

EventScript_FollowerLookAroundScared::
  applymovement 0xFE FollowerLookAroundScared
  waitmovement 0xFE
  goto EventScript_FollowerGeneric

EventScript_FollowerDance::
  applymovement 0xFE FollowerDance
  waitmovement 0
  goto EventScript_FollowerGeneric
