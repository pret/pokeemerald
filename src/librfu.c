#include "global.h"
#include "librfu.h"

struct RfuSlotStatusUNI* gRfuSlotStatusUNI[4];
struct RfuSlotStatusNI* gRfuSlotStatusNI[4];
struct RfuLinkStatus *gRfuLinkStatus;
u32 *gRfuStatic;
struct RfuFixed* gRfuFixed;
u8 gRfuSIO32Id[12];
