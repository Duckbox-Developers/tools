#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#if HAVE_SPARK_HARDWARE
#define RC_DEVICE "/dev/input/nevis_ir"
#define RC_DEVICE_FALLBACK "/dev/input/event1"

#elif HAVE_DUCKBOX_HARDWARE
#define RC_DEVICE "/dev/input/event0"
#define RC_DEVICE_FALLBACK "/dev/input/event1"

#elif BOXMODEL_H7
#define RC_DEVICE "/dev/input/event2"
#define RC_DEVICE_FALLBACK "/dev/input/event1"

#elif BOXMODEL_DM8000 || BOXMODEL_DM800SE || BOXMODEL_DM800SEV2 || BOXMODEL_DM7020HD || BOXMODEL_DM7080 || BOXMODEL_DM820 || BOXMODEL_DM900 || BOXMODEL_DM920
#define RC_DEVICE "/dev/input/event1"
#define RC_DEVICE_FALLBACK "/dev/input/event4"

#else
#define RC_DEVICE "/dev/input/event1"
#define RC_DEVICE_FALLBACK "/dev/input/event0"

#endif
