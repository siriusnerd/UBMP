/*==============================================================================
	Project: ButtonTest
	Version: 1.0 				Date: February 18, 2016
	Target: UBMP1.0				Processor: PIC16F1459

	UBMP board button test program.
==============================================================================*/

#include	"xc.h"				// XC general include file

#include	"stdint.h"			// Include integer definitions
#include	"stdbool.h"			// Include Boolean (true/false) definitions

#include	"UBMP.h"			// Include UBMP constant symbols and functions

// TODO Set linker ROM ranges to 'default,-0-B03' under "Memory model" pull-down.
// TODO Set linker Code offset to '0xB04' under "Additional options" pull-down.

/*==============================================================================
	Main program loop. The main() function is called first by the compiler.
==============================================================================*/

int main(void)
{
	initOsc();					// Initialize oscillator
	initPorts();				// Initialize I/O pins and peripherals
	
	// Repeat the main loop continuously
	while(1)
	{
		if(S2 == 0)				// If switch S2 is pressed, turn its LED on.
			LED3 = 1;			// (Pressed = 0 for pull-up resistor circuits.)
		else					// Otherwise, turn the LED off.
			LED3 = 0;

		
		if(S1 == 0)				// Enter the bootloader if S1 is pressed.
		{
			asm("movlp 0x00");
			asm("goto 0x001C");
		}
	}
}
