/*
 * API_Delay.h
 *
 *  Created on: Sep 14, 2025
 *      Author: valentin
 */



#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_


#include <stdint.h>   // for uint32_t
#include <stdbool.h>  // for bool

/* Type definitions */
typedef uint32_t tick_t;
typedef bool bool_t;

/* Structure definition */
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

/* Function prototypes */
void delayInit( delay_t * delay, tick_t duration );
bool_t delayRead( delay_t * delay );
void delayWrite( delay_t * delay, tick_t duration );


bool_t delayIsRunning( delay_t * delay );



#endif /* API_INC_API_DELAY_H_ */
