#include "constants/tms_hms.h"

	enum_start ITEM_TM01
#define EQUIV_TM(id) enum ITEM_TM_ ## id;
FOREACH_TM(EQUIV_TM)

	enum_start ITEM_HM01
#define EQUIV_HM(id) enum ITEM_HM_ ## id;
FOREACH_HM(EQUIV_HM)
