/*
 ============================================================================
 Name        : led.h
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Header file for the LED driver
 ============================================================================
 */
#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_
/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/


#include "../../common_includes/includes/std_types.h"
#include "../../MCAL/GPIO_Driver/GPIO.h"
#include "../Configrations.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define LED_COUNT          				(uint8)6

#define LED_INITIALIZED                (uint8)1
#define LED_NOT_INITIALIZED            (uint8)0

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


typedef uint8 Led_Name;
typedef uint8 Led_Port;
typedef uint8 Led_Pin;


typedef enum
{
	LED_CAR_RED = 0,        		// PIN 0
	LED_CAR_YELLOW = 1,				// PIN 1
	LED_CAR_GREEN = 2,				// PIN 2
	LED_pedestrian_RED = 3,			// PIN 3
	LED_pedestrian_YELLOW = 4,		// PIN 4
	LED_pedestrian_GREEN = 5,		// PIN 5
}LED_NAME;


typedef enum
{
	LED_RETURN_OK,LED_RETURN_ERROR
}LED_ERROR_STATE;
typedef enum
{
	LED_OFF, LED_ON
}LED_STATE;

typedef struct
{
	LED_NAME ledName;
	Led_Port ledPort;
	Led_Pin ledPin;
}Led_ConfigLed;

typedef struct Led_ConfigType
{
	Led_ConfigLed leds[LED_COUNT];
} Led_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


LED_ERROR_STATE led_init(const Led_ConfigType * ConfigPtr);

LED_ERROR_STATE led_on(LED_NAME ledName);

LED_ERROR_STATE led_off(LED_NAME ledName);

LED_STATE led_state(LED_NAME ledName);


#endif /* HAL_LED_LED_H_ */
