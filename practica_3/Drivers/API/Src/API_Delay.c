/*
 * API_Delay.c
 *
 *  Created on: Sep 14, 2025
 *      Author: valentin
 */


#include "main.h"      // This should include stm32f4xx_hal.h
#include "API_Delay.h"

void delayInit(delay_t * delay, tick_t duration) {
    delay->duration = duration;
    delay->running = false;
}

bool_t delayRead(delay_t * delay) {
    if (!delay->running) {
        delay->startTime = HAL_GetTick();
        delay->running = true;
        return false;
    } else {
        tick_t now = HAL_GetTick();
        if ((now - delay->startTime) >= delay->duration) {
            delay->running = false;
            return true;
        }
        return false;
    }
}

void delayWrite(delay_t * delay, tick_t duration) {
    delay->duration = duration;
}


bool_t delayIsRunning(delay_t * delay) {
    return delay->running;
}
