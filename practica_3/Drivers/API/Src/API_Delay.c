/*
 * API_Delay.c
 *
 *  Created on: Sep 14, 2025
 *      Author: valentin
 */

#include "main.h"      // This should include stm32f4xx_hal.h
#include "API_Delay.h"

/**
 * @brief Inicializa una estructura de delay no bloqueante
 * @param delay: Puntero a la estructura delay_t a inicializar
 * @param duration: Duración del delay en milisegundos
 * @note Esta función debe ser llamada antes de usar delayRead()
 */
void delayInit(delay_t * delay, tick_t duration) {
    delay->duration = duration;    // Establece la duración del delay
    delay->running = false;        // Marca el delay como no iniciado
}

/**
 * @brief Lee el estado de un delay no bloqueante
 * @param delay: Puntero a la estructura delay_t a verificar
 * @retval true si el delay ha expirado, false en caso contrario
 * @note En la primera llamada inicia el delay, en las siguientes verifica si expiró
 */
bool_t delayRead(delay_t * delay) {
    if (!delay->running) {
        // Primera vez que se llama: iniciar el delay
        delay->startTime = HAL_GetTick();  // Captura tiempo actual
        delay->running = true;             // Marca delay como iniciado
        return false;                      // Delay recién iniciado, no ha expirado
    } else {
        // Delay ya iniciado: verificar si ha transcurrido el tiempo
        tick_t now = HAL_GetTick();        // Obtiene tiempo actual
        if ((now - delay->startTime) >= delay->duration) {
            // El tiempo ha transcurrido
            delay->running = false;         // Resetea el delay para próximo uso
            return true;                   // Indica que el delay expiró
        }
        return false;                      // Delay aún no ha expirado
    }
}

/**
 * @brief Modifica la duración de un delay existente
 * @param delay: Puntero a la estructura delay_t a modificar
 * @param duration: Nueva duración del delay en milisegundos
 * @note Solo debe usarse cuando el delay no esté corriendo (verificar con delayIsRunning)
 */
void delayWrite(delay_t * delay, tick_t duration) {
    delay->duration = duration;    // Actualiza la duración del delay
}

/**
 * @brief Verifica si un delay está actualmente corriendo
 * @param delay: Puntero a la estructura delay_t a verificar
 * @retval true si el delay está corriendo, false si está detenido
 * @note Función auxiliar para verificar estado antes de usar delayWrite()
 */
bool_t delayIsRunning(delay_t * delay) {
    return delay->running;         // Devuelve copia del campo running
}
