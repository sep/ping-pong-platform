
#include "main.h"
#include <msp430.h>

#include "led_driver.h"

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;

	led_initialize((led_addresses_s*)P1IN_);
	
	P1DIR = 0x04;
	P1SEL = 0x06;
	
	UCA0CTL0 = 0x00;
	UCA0CTL1 = UCSSEL_3;
	UCA0BR0 = 104;
	UCA0BR1 = 0x00;
	UCA0MCTL = 0x03 << 4;
	
	set_led_color(LED_GREEN);
	
	while(1)
	{
		if(UCA0STAT & 0x01 == 0x00)
		{
			UCA0TXBUF = 0x5a;
		}
	}
}
