/*
 ============================================================================
 Name        : button.c
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Source file for the LED driver
 ============================================================================
 */
#include "button.h"
static const Button_ConfigType * button = NULL_PTR;

static int g_button_init_called = BUTTON_NOT_INITIALIZED;

BUTTON_ERROR_STATE button_init(const Button_ConfigType * ConfigPtr){
	if(g_button_init_called == BUTTON_NOT_INITIALIZED){
		GPIO_setupPinDirection(ConfigPtr->button.buttonPort, ConfigPtr->button.buttonPin, PIN_INPUT);
	}else{
		return BUTTON_RETURN_ERROR;
	}
	button = ConfigPtr;
	g_button_init_called = BUTTON_INITIALIZED;
	return BUTTON_RETURN_OK;
}

//BUTTON_ERROR_STATE pushButton(){
//	if(g_button_init_called == BUTTON_INITIALIZED){
//		GPIO_writePin(button->buttonPort, button->buttonPin, );
//	}else{
//		return BUTTON_RETURN_ERROR;
//	}
//	return LED_RETURN_OK;
//}

BUTTON_STATE butttonState(){
	return GPIO_readPin(button->button.buttonPort, button->button.buttonPin);
}
