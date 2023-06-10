/*
 ============================================================================
 Name        : app.c
 Author      : Belal
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Source file for the APPLICATION
 ============================================================================
 */
#include "app.h"

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

const Button_ConfigType Button_Configuration = {
		{PORTD_ID, PIN6_ID}
};


const Led_ConfigType Led_Configuration = {
	   {{LED_CAR_RED,       		PORTA_ID, PIN0_ID},
		{LED_CAR_YELLOW,    		PORTA_ID, PIN1_ID},
		{LED_CAR_GREEN,     		PORTA_ID, PIN2_ID},
		{LED_pedestrian_RED,		PORTA_ID, PIN3_ID},
		{LED_pedestrian_YELLOW,		PORTA_ID, PIN4_ID},
		{LED_pedestrian_GREEN,		PORTA_ID, PIN5_ID}}
};

uint8 g_intruptCall = INTERRUPT_FNISHED;


//void INT0_Init(void)
//{
//	CLEAR_BIT(SREG, 7);		 // Disable interrupts by clearing I-bit
//	CLEAR_BIT(DDRB, PB2);	 // Configure INT2/PB2 as input pin
//	SET_BIT(GICR, INT0);	 // Enable external interrupt pin INT2
//	SET_BIT(MCUCSR, ISC00);	 // Trigger INT0 with the raising edge
//	SET_BIT(MCUCSR, ISC01);	 // Trigger INT0 with the raising edge
//	SET_BIT(SREG, 7);		 // Enable interrupts by setting I-bit
//}
/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}



void blink(){
	for (int i = 0; i < 5; ++i) {
		led_on(LED_CAR_YELLOW);
		led_on(LED_pedestrian_YELLOW);
		_delay_ms(ONE_SEC);
		led_off(LED_CAR_YELLOW);
		led_off(LED_pedestrian_YELLOW);
		_delay_ms(ONE_SEC);
	}
	led_off(LED_CAR_YELLOW);
	led_off(LED_pedestrian_YELLOW);
}
void interruptEnd(){
	led_off(LED_CAR_RED);
	led_on(LED_pedestrian_GREEN);
	blink();
	led_off(LED_CAR_RED);
	led_off(LED_pedestrian_GREEN);
}


void car_led_ON(LED_NAME ledName){
	if(ledName == LED_CAR_RED)
	{
		led_on(LED_CAR_RED);
		led_off(LED_CAR_YELLOW);
		led_off(LED_CAR_GREEN);

		pedestrian_led_ON(LED_CAR_RED);
	}
	else if(ledName == LED_CAR_YELLOW)
	{
		led_off(LED_CAR_RED);
		led_on(LED_CAR_YELLOW);
		led_off(LED_CAR_GREEN);

		pedestrian_led_ON(LED_CAR_YELLOW);
	}
	else if(ledName == LED_CAR_GREEN)
	{
		led_off(LED_CAR_RED);
		led_off(LED_CAR_YELLOW);
		led_on(LED_CAR_GREEN);

		pedestrian_led_ON(LED_CAR_GREEN);
	}
}

void pedestrian_led_ON(LED_NAME ledName){
	if(ledName == LED_CAR_RED)
	{
		led_off(LED_pedestrian_RED);
		led_off(LED_pedestrian_YELLOW);
		led_on(LED_pedestrian_GREEN);
	}
	else if(ledName == LED_CAR_YELLOW)
	{
		led_on(LED_pedestrian_RED);
		led_off(LED_pedestrian_YELLOW);
		led_off(LED_pedestrian_GREEN);
	}
	else if(ledName == LED_CAR_GREEN)
	{
		led_on(LED_pedestrian_RED);
		led_off(LED_pedestrian_YELLOW);
		led_off(LED_pedestrian_GREEN);
	}
}

void leds_start(){
	// car LEDs
	led_on(LED_CAR_RED);
	led_off(LED_CAR_YELLOW);
	led_off(LED_CAR_GREEN);

	// pedestrian LEDs
	led_on(LED_CAR_RED);
	led_off(LED_CAR_YELLOW);
	led_off(LED_CAR_GREEN);
}

ISR(INT0_vect)
{
////////////////////////////////////////////////////////////////////////
	CLEAR_BIT(SREG, 7);		 // Disable interrupts by clearing I-bit
////////////////////////////////////////////////////////////////////////

		if(led_state(LED_CAR_RED) == LED_ON)
		{
	//		led_off(LED_CAR_RED);
	//
	//		led_off(LED_pedestrian_RED);
	//		led_on(LED_pedestrian_GREEN);
	//
	//		_delay_ms(FIVE_SEC);
	//
	//		interruptEnd();
	//
	//		led_off(LED_pedestrian_GREEN);
	//
	//		led_on(LED_pedestrian_RED);
			led_on(LED_CAR_RED);

		}
		else if(led_state(LED_CAR_YELLOW) == LED_ON)
		{
			led_on(LED_pedestrian_RED);

			blink();

			led_off(LED_pedestrian_RED);

			led_off(LED_CAR_YELLOW);
			led_on(LED_CAR_RED);

			led_on(LED_pedestrian_GREEN);
			_delay_ms(FIVE_SEC);
			interruptEnd();

			led_on(LED_CAR_YELLOW);
			led_on(LED_pedestrian_YELLOW);
		}
		else if(led_state(LED_CAR_GREEN) == LED_ON)
		{
			led_on(LED_pedestrian_RED);

			led_off(LED_pedestrian_GREEN);
			led_on(LED_pedestrian_RED);

			blink();

			led_off(LED_CAR_GREEN);
			led_off(LED_pedestrian_RED);

			led_on(LED_CAR_RED);
			led_on(LED_pedestrian_GREEN);
			_delay_ms(FIVE_SEC);
			interruptEnd();

			led_on(LED_CAR_GREEN);
			led_on(LED_pedestrian_RED);
		}

//////////////////////////////////////////////////////////////////////
	SET_BIT(SREG, 7);		 // Enable interrupts by setting I-bit
//////////////////////////////////////////////////////////////////////

}

int app(void)
{
	INT0_Init();              // Enable external INT0

	led_init(&Led_Configuration);
	button_init(&Button_Configuration);

	leds_start();

	while(1){
		car_led_ON(LED_CAR_RED);
		_delay_ms(FIVE_SEC);
		car_led_ON(LED_CAR_YELLOW);
		_delay_ms(FIVE_SEC);
		car_led_ON(LED_CAR_GREEN);
		_delay_ms(FIVE_SEC);
	}

}


























