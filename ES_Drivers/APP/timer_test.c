#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "timer_test.h"



volatile unsigned int tick_counter = 0;

void TimerApp_Callback(void)
{
    tick_counter++;

    if (tick_counter % 1000 == 0)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN2);
    }

    if (tick_counter >= 2000)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        tick_counter = 0;
    }
}

void TIMER_Test(void)
{
    /* 1. Init LEDs */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    /* 2. Init Timer */
    Timer0_Init();

    /* 3. Register the callback */
    Timer0_SetCallback(TimerApp_Callback);

    /* 4. Enable Global Interrupts */
    SET_BIT(INTCON, GIE);  // Global
    SET_BIT(INTCON, PEIE); // Peripheral
    SET_BIT(INTCON, TMR0IE); // enable timer


    while(1);
}