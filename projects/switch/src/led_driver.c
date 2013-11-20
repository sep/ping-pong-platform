#include "led_driver.h"

#define LED_RED_PIN_VALUE 1
#define LED_GREEN_PIN_VALUE 64

led_addresses_s* address = PPNULL;

void led_initialize(led_addresses_s* params)
{
	address = params;
	address->direction |= LED_RED_PIN_VALUE + LED_GREEN_PIN_VALUE;
	address->output &= ~(LED_RED_PIN_VALUE + LED_GREEN_PIN_VALUE);
}

PPBOOL set_led_color(led_color_e value)
{
	if (address == PPNULL)
	{
		return PPFalse;
	}
	
	switch(value)
	{
		case LED_RED:
			address->output |= LED_RED_PIN_VALUE;
			break;
		case LED_GREEN:
			address->output |= LED_GREEN_PIN_VALUE;
			break;
		case LED_OFF:
		default:
			address->output &= ~(LED_RED_PIN_VALUE + LED_GREEN_PIN_VALUE);
			break;
	}

	return PPTrue;
}
