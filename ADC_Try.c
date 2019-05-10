#include <C8051F340.h>

void main() {

    ADC0CN |= 0x80; // Enable ADC0 subsystem
    AMX0N = 0x1F; // Set negative mux to GND -> use singel end mode
    while (1) { // Unlimited loop
        ADC0CN |= 0x10; // or 16 to trigger AD0BUSY
        while (!(ADC0CN & 0x20 /* or 32*/)) {} // wait for the AD0INT to become 1
        // go ahead after thread block
        
    }
    
}
