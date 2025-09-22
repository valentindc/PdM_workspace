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
   tick_t startTime;   // Tiempo de inicio del delay (en ticks del sistema)
   tick_t duration;    // Duración del delay (en milisegundos)
   bool_t running;     // Estado del delay: true = corriendo, false = detenido
} delay_t;

/* Function prototypes */
void delayInit( delay_t * delay, tick_t duration );     // Inicializa delay no bloqueante
bool_t delayRead( delay_t * delay );                    // Lee estado del delay (inicia o verifica)
void delayWrite( delay_t * delay, tick_t duration );    // Modifica duración del delay
bool_t delayIsRunning( delay_t * delay );               // Verifica si delay está corriendo

void debounceFSM_init();
bool_t readKey();
void debounceFSM_update();


#endif /* API_INC_API_DELAY_H_ */
