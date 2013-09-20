#ifndef __TYPES_H__
#define __TYPES_H__

typedef enum {
  PPTrue,
  PPFalse
} PPBOOL;

typedef enum {
  PPEvent_Switch
} PPEvent_t;

typedef enum {
  PPSwitch_On,
  PPSwitch_Off
} PPSwitchState_t;

typedef void (*PPListenerCallback_cb)(PPEvent_t, PPSwitchState_t);

#endif // __TYPES_H__
