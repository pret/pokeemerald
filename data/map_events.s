#include "constants/global.h"
#include "constants/event_bg.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_scripts.h"
#include "constants/maps.h"
#include "constants/secret_bases.h"
#include "constants/vars.h"
#include "constants/weather.h"
#include "constants/trainer_hill.h"
#include "constants/trainer_types.h"
#include "constants/berry.h"
	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.include "data/maps/events.inc"

