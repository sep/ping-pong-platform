#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include "types.h"

void communication_register(PPEvent_t eventType, PPListenerCallback_cb callback);

#endif // __COMMUNICATION_H__
