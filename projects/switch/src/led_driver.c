#include "led_driver.h"

#define LED_RED_PIN_VALUE 1
#define LED_GREEN_PIN_VALUE 64

PPBOOL is_initialized = PPFalse;

void led_initialize(led_addresses_s* params)
{
	params->direction |= LED_RED_PIN_VALUE + LED_GREEN_PIN_VALUE;
	params->output &= ~(LED_RED_PIN_VALUE + LED_GREEN_PIN_VALUE);

	is_initialized = PPTrue;
}

PPBOOL set_led_color(led_color_e value){
	if (PPFalse == is_initialized)
	{
		return PPFalse;
	}

	return PPTrue;
}
