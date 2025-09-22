/*
 * API_debounce.c
 *
 *  Created on: Sep 21, 2025
 *      Author: valentin
 */
#include "API_debounce.h"
#include "stm32f4xx_hal.h"

typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RAISING,
} debounceState_t;

static void buttonPressed();
static void buttonReleased();
bool_t readButton();

static debounceState_t state;
static bool_t keyState = false;

const uint32_t HOLD_TIME = 40; //Time of debounce


void debounceFSM_init(){		// debe cargar el estado inicial
	state = BUTTON_UP;
}


/*
 * This function must read the input, solve the
 * logic of states transition and update the output
 */
void debounceFSM_update(void) {

	bool_t button = readButton();      // raw read
	static delay_t d;                  // persistent debounce timer

	switch (state) {
	case BUTTON_UP:
	    if (button) {            // Change from !button to button
	        state = BUTTON_FALLING;
	        delayInit(&d, HOLD_TIME);
	        delayRead(&d);
	    }
	    break;

	case BUTTON_FALLING:
	    if (button) {            // Change from !button to button
	        if (delayRead(&d)) {
	            state = BUTTON_DOWN;
	            buttonPressed();
	        }
	    } else {
	        state = BUTTON_UP;
	    }
	    break;

	case BUTTON_DOWN:
	    if (!button) {           // Change from button to !button
	        state = BUTTON_RAISING;
	        delayInit(&d, HOLD_TIME);
	        delayRead(&d);
	    }
	    break;

	case BUTTON_RAISING:
	    if (!button) {           // Change from button to !button
	        if (delayRead(&d)) {
	            state = BUTTON_UP;
	            buttonReleased();
	        }
	    } else {
	        state = BUTTON_DOWN;
	    }
	    break;
	}
}


/*
 * @brief Turns the LED on  when button is pressed
*/
void buttonPressed(){
    HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
    keyState = true;  // Add this line
}


/*
 * @brief Turns the LED back off when button is released
*/
void buttonReleased(){
	HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
}


/*
 * @brief Reads the state of the button (0 if down)
 * @retval boolean corresponding to button state (True = pressed)
*/
bool_t readButton(){
	return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin);
}

bool_t readKey(){
	bool_t auxState = keyState;
	if (keyState){
		keyState = false;
	}
	return auxState;
}



