#include "leds.h"

#define LEDS_ALL_OFF 0X0000
#define LEDS_ALL_ON 0XFFFF
#define LED_OFFSET 1

#define LedToMask(led) (1<<(led-LED_OFFSET))

static uint16_t *direccion;

void Leds_Create(uint16_t *puerto)
{
    *puerto=LEDS_ALL_OFF;
    direccion=puerto;
}

void Leds_On(uint8_t led)
{
    *direccion|=LedToMask(led);   
}

void Leds_Off(uint8_t led)
{
    *direccion&=~LedToMask(led);   
}

uint8_t Led_State(uint8_t led)
{
    return (*direccion>>(led-LED_OFFSET))&1;   
}

void Leds_All_On(void)
{
    *direccion=LEDS_ALL_ON;   
}

void Leds_All_Off(void)
{
    *direccion=LEDS_ALL_OFF;   
}

