
#include "main.h"
#include <msp430.h>

#include "led_driver.h"

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	led_initialize((led_addresses_s*)P1IN_);
	
	set_led_color(LED_RED);
	while(1)
	{
		
	}
}
