/*
 ============================================================================
 Name        : led.c
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Source file for the LED driver
 ============================================================================
 */
#include "led.h"

static const Led_ConfigLed * leds = NULL_PTR;
static uint8 g_led_init_called = LED_NOT_INITIALIZED;



// pass Led_Configuration to it
LED_ERROR_STATE led_init(const Led_ConfigType * ConfigPtr){
	if(g_led_init_called == LED_NOT_INITIALIZED){
		for (int i = 0; i < LED_COUNT; ++i) {
			if(GPIO_setupPinDirection(ConfigPtr->leds[i].ledPort, ConfigPtr->leds[i].ledPin, PIN_OUTPUT) == GPIO_RETURN_OK){
				GPIO_writePin(ConfigPtr->leds[i].ledPort, ConfigPtr->leds[i].ledPin, LOGIC_LOW);
				continue;
			}else{
				return LED_RETURN_ERROR;
			}
		}
	}else{
		return LED_RETURN_ERROR;
	}
	leds = ConfigPtr->leds;
	g_led_init_called = LED_INITIALIZED;
	return LED_RETURN_OK;
}

LED_ERROR_STATE led_on(LED_NAME ledName){
	if(g_led_init_called == LED_INITIALIZED){
		GPIO_writePin(leds[ledName].ledPort,leds[ledName].ledPin, LOGIC_HIGH);
	}else{
		return LED_RETURN_ERROR;
	}
	return LED_RETURN_OK;
}






LED_ERROR_STATE led_off(LED_NAME ledName){
	if(g_led_init_called == LED_INITIALIZED){
		GPIO_writePin(leds[ledName].ledPort,leds[ledName].ledPin, LOGIC_LOW);
	}else{
		return LED_RETURN_ERROR;
	}
	return LED_RETURN_OK;
}

LED_STATE led_state(LED_NAME ledName){
	return GPIO_readPin(leds[ledName].ledPort,leds[ledName].ledPin);
}
