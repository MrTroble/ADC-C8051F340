#include <C8051F340.h>

void main() {

    ADC0CN |= 0x80; // Enable ADC0 subsystem
    AMX0N = 0x1F; // Set negative mux to GND -> use singel end mode
    // use AMX0P default config -> P1.0
    while (1) { // Unlimited loop
        ADC0CN |= 0x10; // or 16 to trigger AD0BUSY
        while (!(ADC0CN & 0x20 /* or 32*/)) {} // wait for the AD0INT to become 1
        // go ahead after thread block
        P3 = ADC0L; // Put low bits in P3
        P0_0 = ADC0H & 1; // Put first bit of high bits into P0.0
        P0_1 = ADC0H & 2; // Put second bit of high bits into P0.1
    }
    
}
