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
#include "UART_test.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1 GPIO_PIN0
#define MOTOR_PIN2 GPIO_PIN1

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN2

/* Callback */

void Bluetooth_UART_Callback(u8 Copy_u8Data)
{
    if (Copy_u8Data == 'f') // forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_HIGH);
    }
    else if (Copy_u8Data == 's') // stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_LOW);
    }
}

void UART_Test(void)
{
    /* GPIO Init */
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    /* UART Init */
    UART_RX_Init();
    UART_TX_Init();

    /* Register callback */
    UART_SetCallback(Bluetooth_UART_Callback);

    // SET_BIT(INTCON, GIE);  // Global Interrupt Enable
    // SET_BIT(INTCON, PEIE); // Peripheral Interrupt Enable
    // SET_BIT(PIE1, RCIE);  // UART RX Interrupt Enable

    while(1);
}