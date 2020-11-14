#include "unity.h"
#include "leds.h"

//XDespués de la inicialización todos los LEDs deben quedar apagados.
//X Se puede prender un LED individual.
//X Se puede apagar un LED individual.
//X Se pueden prender y apagar múltiples LED’s.
//X Se pueden prender todos los LEDs de una vez.
//X Se pueden apagar todos los LEDs de una vez.
//X Se puede consultar el estado de un LED

uint16_t ledsVirtuales;

void setUp(void){
    Leds_Create(&ledsVirtuales);    
}

void tearDown(void){
}

void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);    
    TEST_ASSERT_EQUAL_HEX16(0,ledsVirtuales);
}

//se puede prender un LED individual
void test_prender_led_individual(void){
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

//se puede apagar un LED individual
void test_apagar_led_individual(void){
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

//Se pueden prender y apagar múltiples LED’s.
void test_apagar_prender_multiples_led(void){
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1<<3, ledsVirtuales);
}

//Se pueden prender todos los LEDs de una vez.
void test_prender_todos_los_led(void){
    Leds_All_On();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

//Se pueden apagar todos los LEDs de una vez.
void test_apagar_todos_los_led(void){
    Leds_All_On();
    Leds_All_Off();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

//Se puede consultar el estado de un LED
void test_consultar_el_estado_de_un_led(void){
    Leds_On(3);
    TEST_ASSERT_EQUAL_HEX16(1, Led_State(3));
}


/*
void test_inicializacion(void){
    TEST_FAIL_MESSAGE("Empezamos");
}*/
