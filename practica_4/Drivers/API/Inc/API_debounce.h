/*
 * API_debounce.h
 *
 *  Created on: Sep 21, 2025
 *      Author: valentin
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_


#include <stdint.h>
#include <stdbool.h>
#include "API_Delay.h"

#ifndef LD2_GPIO_Port
#define LD2_GPIO_Port GPIOA
#endif

#ifndef LD2_Pin
#define LD2_Pin GPIO_PIN_5
#endif

#ifndef B1_Pin
#define B1_Pin GPIO_PIN_13
#endif

#ifndef B1_GPIO_Port
#define B1_GPIO_Port GPIOC
#endif

void debounceFSM_init();
void debounceFSM_update();
bool_t readButton();


#endif /* API_INC_API_DEBOUNCE_H_ */
