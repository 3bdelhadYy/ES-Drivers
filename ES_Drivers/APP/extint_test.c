#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "extint_test.h"

void EXTINT_Test(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    EXT_INT_Init();
    EXT_INT_SetCallback(App_ToggleLed);
    EXT_INT_Enable();


    while(1);
    {
         
    }
}


void App_ToggleLed(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}