
#include "main.h"
#include <msp430.h>

#include "led_driver.h"

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;
	
	//Set clock to 1MHz
	BCSCTL1 = CALBC1_1MHZ;
	DCOCTL = CALDCO_1MHZ;

	led_initialize((led_addresses_s*)P1IN_);
	
	P1DIR |= 0x04;
	P1SEL |= 0x06;
	P1SEL2 |= 0x06;
	
	UCA0CTL0 |= 0x00;
	UCA0CTL1 |= UCSSEL_2;
	UCA0BR0 = 104;
	UCA0BR1 = 0x00;
	UCA0MCTL = UCBRS0;
	
	UCA0CTL1 &= ~UCSWRST;
	
	set_led_color(LED_GREEN);

	while(1)
	{

		if((IFG2 & UCA0TXIFG) == UCA0TXIFG)
		{
			UCA0TXBUF = 0x5a;
		}
		
		//IE2 |= UCA0TXIE;                                 // Enable USCI_A0 TX interrupt
		//__bis_SR_register(LPM0_bits + GIE); // Enter LPM0, interrupts enabled
	}
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void TX_Ready(void)
{
	if((IFG2 & UCA0TXIFG) == UCA0TXIFG)
	{
		UCA0TXBUF = 0x5a;
	}
}
