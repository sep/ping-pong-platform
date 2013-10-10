#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include "types.h"

void communication_register_switch(PPSwitchListenerCallback_cb callback);
void communication_register_status(PPStatusListenerCallback_cb callback);

#endif // __COMMUNICATION_H__
