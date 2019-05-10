#include <C8051F340.h>

void main() {

    ADC0CN |= 0x80; // Enable ADC0 subsystem
    AMX0N = 0x1F; // Set negative mux to GND -> use singel end mode
}
