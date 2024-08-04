gText_FollowerLovesYou::
	.string "{STR_VAR_1} is regarding you with\nadoration!$"

gText_FollowerLostInThought::
	.string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
	.string "ERROR 404: Script not found.$"

gText_WantsToFly::
	.string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to use FLY?$"

EventScript_Follower::
	lock
	bufferlivemonnickname 0
	playfirstmoncry
	getfolloweraction
EventScript_FollowerEnd::
	waitfieldeffect FLDEFF_EMOTE
	release
	end

EventScript_FollowerLovesYou::
	applymovement OBJ_EVENT_ID_FOLLOWER, ContestHall_Movement_Heart
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitmoncry
	msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
	return

@ Message address must be loaded into bank 0
EventScript_FollowerGeneric:: @ similar to Std_MsgboxDefault
	faceplayer
EventScript_FollowerGenericSkipFace:
	waitfieldeffect FLDEFF_EMOTE
	message 0x0
	waitmessage
	waitbuttonpress
	return

EventScript_FollowerJump::
	faceplayer
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSplashMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	waitfieldeffect FLDEFF_EMOTE
	message 0x0
	waitmessage
	waitbuttonpress
	return

EnterPokeballMovement::
	enter_pokeball
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
	walk_in_place_fast_up
	walk_in_place_fast_left
	walk_in_place_fast_down
	walk_in_place_fast_right
	walk_in_place_fast_up
	walk_in_place_fast_left
	walk_in_place_fast_down
	walk_in_place_fast_right
	jump_in_place_up
	jump_in_place_down
	jump_in_place_up
	face_player
	step_end

@ Movement scripts

EventScript_FollowerIsShivering::
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShiverHorizontal:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerNostalgia::
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerNostalgiaMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerHopping::
	faceplayer
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerSkippingMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

JumpOnN:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

JumpOnW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerJumpOnPlayerWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerJumpOnPlayer::
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleS:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleE:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CuddleW:
	applymovement OBJ_EVENT_ID_FOLLOWER, FollowerCuddlingWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerCuddling:: @ similar to Std_MsgboxDefault
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleS:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverVerticalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleE:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

ShCuddleW:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerShiverHorizontalMovement
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerCuddlingWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerShiverCuddling::
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserS:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserE:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

CreepCloserW:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerGetCloser::
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserNorth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerS:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserSouth
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerE:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserEast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

PokePlayerW:
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerGetCloserWest
	waitmovement OBJ_EVENT_ID_FOLLOWER
	return

EventScript_FollowerPokingPlayer::
	faceplayer
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
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAround
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerLookAway::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayBark::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayBark
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAwayPoke::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAwayPokeG
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerPokeGround::
	faceplayer
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerPokeGround
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerStartled::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerStartled
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFastHopping::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerHopFast
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerDizzy::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDizzy
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerLookAroundScared::
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAroundScared
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGeneric

EventScript_FollowerDance::
	faceplayer
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceUp::
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceResult:: @ Face towards direction in VAR_RESULT
	switch VAR_RESULT
	case DIR_SOUTH, EventScript_FollowerFaceDown
	case DIR_NORTH, EventScript_FollowerFaceUp
	case DIR_WEST, EventScript_FollowerFaceLeft
	case DIR_EAST, EventScript_FollowerFaceRight
	goto EventScript_FollowerGeneric

EventScript_FollowerFaceDown:
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceLeft:
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace

EventScript_FollowerFaceRight:
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_FOLLOWER
	goto EventScript_FollowerGenericSkipFace
