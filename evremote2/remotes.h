#ifndef REMOTES_H_
#define REMOTES_H_

#include <stdio.h>
#include <stdlib.h>
#include "global.h"

#define getRCvalue(context, field) \
	(((RemoteControl_t*) context->r)->field)

typedef struct RemoteControl_s
{
		char *Name;
		eBoxType Type;
		int (* Init)(Context_t *context, int argc, char *argv[]);
		int (* Shutdown)(Context_t *context);
		int (* Read)(Context_t *context);    // 00 NN 00 KK
		int (* Notification)(Context_t *context, const int on);

		void/*tButton*/ * RemoteControl;
		void/*tButton*/ * Frontpanel;

		void *private;
		unsigned char supportsLongKeyPress;
		tLongKeyPressSupport *LongKeyPressSupport;
} RemoteControl_t;

#if BOXMODEL_UFS910
extern RemoteControl_t Ufs910_1W_RC;
extern RemoteControl_t Ufs910_14W_RC;
#elif BOXMODEL_UFS922
extern RemoteControl_t UFS922_RC;
#else
extern RemoteControl_t Tf7700_RC;
extern RemoteControl_t Fortis_RC;
extern RemoteControl_t UFS912_RC;
extern RemoteControl_t Spark_RC;
extern RemoteControl_t Cuberevo_RC;
extern RemoteControl_t Ipbox_RC;
#endif
extern RemoteControl_t LircdName_RC;

int selectRemote(Context_t  *context, eBoxType type);

#endif
