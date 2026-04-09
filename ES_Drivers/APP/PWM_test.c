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
#include "PWM_test.h"


/* State: 0→25%, 1→50%, 2→75%, 3→100% */
volatile u8 duty_state = 0;
volatile u8 flag_update_pwm = 1;

void PWM_Test(void)
{
    // CLR_BIT(INTCON, GIE);
    // CLR_BIT(INTCON, PEIE);
    /* Disable analog */
    ADCON1 = 0x06;

    /* Button (RB0) */
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);

    /* PWM Output (RC2 / CCP1) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    /* Init */
    PWM_voidInit();

    /* Interrupt setup */
    OPTION_REG &= 0b00111111;   // Falling edge
    SET_BIT(INTCON, 7); // GIE
    SET_BIT(INTCON, 6); // PEIE

    /* Start from 0% */
    duty_state = 0;
    PWM_voidSetDutyCycle(0);
    flag_update_pwm = 0;

    CLR_BIT(INTCON, INTF);

    while (1)
    {
        if (flag_update_pwm)
        {
            u8 duty = (duty_state + 1) * 25;

            flag_update_pwm = 0;
            PWM_voidSetDutyCycle(duty);
        }
    }
}
/*
void interrupt()
{
    if (GET_BIT(INTCON, INTF))
    {
        CLR_BIT(INTCON, INTF);

        duty_state++;
        if (duty_state > 3)
            duty_state = 0;

        flag_update_pwm = 1;
    }
}
*/
