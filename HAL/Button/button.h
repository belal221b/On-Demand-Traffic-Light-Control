/*
 ============================================================================
 Name        : button.h
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Header file for the LED driver
 ============================================================================
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/*******************************************************************************
 *                                 Includes                                    *
 *******************************************************************************/

#include "../../common_includes/includes/std_types.h"
#include "../../MCAL/GPIO_Driver/GPIO.h"

 /*******************************************************************************
  *                                Definitions                                  *
  *******************************************************************************/

#define BUTTON_INITIALIZED                (1U)
#define BUTTON_NOT_INITIALIZED            (0U)

#define ONE_BUTTON            			  (1U)

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/


typedef uint8 Button_Port;
typedef uint8 Button_Pin;




typedef enum
{
	BUTTON_RETURN_OK, BUTTON_RETURN_ERROR
}BUTTON_ERROR_STATE;
typedef enum
{
	OFF, ON
}BUTTON_STATE;

typedef struct Button_ConfigButton
{
	Button_Port buttonPort;
	Button_Pin buttonPin;
} Button_ConfigButton;

typedef struct Button_ConfigType
{
	Button_ConfigButton button;
} Button_ConfigType;



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/


BUTTON_ERROR_STATE button_init(const Button_ConfigType * ConfigPtr);

BUTTON_STATE butttonState();

//BUTTON_ERROR_STATE pushButton();

#endif /* HAL_BUTTON_BUTTON_H_ */
