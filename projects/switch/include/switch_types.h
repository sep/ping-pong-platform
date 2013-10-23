#ifndef __SWITCH_TYPES_H__
#define __SWITCH_TYPES_H__

typedef void (*switch_cb_t)(void);

typedef struct {
	switch_cb_t disableWatchdogFunction;
} switch_functions_s;

#endif // __SWITCH_TYPES_H__
