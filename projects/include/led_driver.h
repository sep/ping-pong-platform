#ifndef __LED_DRIVER_H__
#define __LED_DRIVER_H__

#include <stdint.h>
#include "types.h"

typedef struct {
	uint8_t input;
	uint8_t output;
	uint8_t direction;
	uint8_t interrupt_flag;
	uint8_t interrupt_edge_select;
	uint8_t port_select;
	uint8_t resistor_enable;
} led_addresses_s;

typedef enum {
	LED_OFF,
	LED_RED,
	LED_GREEN
} led_color_e;

void led_initialize(led_addresses_s*);
PPBOOL set_led_color(led_color_e);

#endif // __LED_DRIVER_H__
