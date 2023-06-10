/*
 ============================================================================
 Name        : app.h
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Header file for the APPLICATION
 ============================================================================
 */

#ifndef APP_APP_H_
#define APP_APP_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/


#include "../common_includes/includes.h"
#include "../HAL/Button/button.h"
#include "../HAL/LED/led.h"
#include "../HAL/Configrations.h"

/* LED_ERROR_STATE led_init(const Led_ConfigType * ConfigPtr);
 * LED_ERROR_STATE led_on(LED_NAME ledName);
 * LED_ERROR_STATE led_off(LED_NAME ledName);
 * LED_STATE led_state(LED_NAME ledName);*/
/*typedef enum
{
	LED_CAR_RED,        // PIN 0
	LED_CAR_YELLOW,		// PIN 1
	LED_CAR_GREEN,		// PIN 2
	LED_pedestrian_RED,		// PIN 3
	LED_pedestrian_YELLOW,	// PIN 4
	LED_pedestrian_GREEN	// PIN 5
}LED_NAME;*/
/* BUTTON_ERROR_STATE button_init(const Button_ConfigType * ConfigPtr);
 * BUTTON_STATE butttonState();*/

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define FIVE_SEC 5000
#define ONE_SEC 1000


#define INTERRUPT_NOT_FNISHED        (uint8)1
#define INTERRUPT_FNISHED            (uint8)0

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

void blink();
void interruptEnd();
void pedestrian_led_ON(LED_NAME ledName);
void car_led_ON(LED_NAME ledName);
void leds_start();
int app(void);


#endif /* APP_APP_H_ */
