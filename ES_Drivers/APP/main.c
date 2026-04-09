#include "LED_test.h"
#include "extint_test.h"
#include "timer_test.h"
#include "PWM_test.h"
#include "ADC_test.h"
#include "UART_test.h"

void main()
{
    LED_Test();        // 0
    // EXTINT_Test();     // 1
    // TIMER_Test();      // 1
    // PWM_Test();        // 0
    // ADC_Test();        // 0
    // UART_Test();       // 1
        while(1)
    {
    }
}