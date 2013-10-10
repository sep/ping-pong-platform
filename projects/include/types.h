#ifndef __TYPES_H__
#define __TYPES_H__

typedef enum {
  PPTrue,
  PPFalse
} PPBOOL;

typedef enum {
  PPEvent_Switch,
  PPEvent_Status
} PPEvent_t;

typedef enum {
  PPSwitch_On,
  PPSwitch_Off
} PPSwitchState_t;

typedef enum {
  PPSwitchStatus_LowBattery
} PPSwitchStatus_t;

typedef void (*PPSwitchListenerCallback_cb)(PPSwitchState_t);
typedef void (*PPStatusListenerCallback_cb)(PPSwitchStatus_t);

#endif // __TYPES_H__
