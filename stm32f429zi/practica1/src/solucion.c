/*
 * solucion.c
 *
 *  Created on: Aug 24, 2025
 *      Author: valentin
 *      Calcular la depreciacion utilizando uno de tres metodos diferentes
 */

#include <stdio.h>

void main() {
	int n, anual, eleccion = 0;
	float val, aux, deprec;
	while (eleccion != 4) {
		/* Leer datos de entrada */
		printf("\n Metodo: (1-LR \t2-BD \t3-SDA \t4-Fin)");
		scanf("%d", &eleccion);
		if (eleccion >= 1 && eleccion <= 3) {
			printf("Valor original: ");
			scanf("%f",&val);
			printf("Numero de años: ");
			scanf("%d",&n);
		}
		switch (eleccion) {
			case 1:
				//metodo de la linea recta
				printf("\nMetodo de la linea recta\n\n");
				deprec = val / n;
				for (anual = 1; anual <= n; ++anual) {
					val -= deprec;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", deprec);
					printf(" Valor actual: %8.2f\n", val);
				}
				break;
			case 2:
				//metodo de balance doblemente declinante
				printf("\nMetodo de balance doblemente declinante\n\n");
				for (anual = 1; anual <= n; ++anual) {
					deprec = 2*val/n;
					val -= deprec;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", deprec);
					printf(" Valor actual: %8.2f\n", val);
				}
				break;
			case 3:
				//metodo de la suma de los digitos de los años
				printf("\nMetodo de la suma de los digitos ");
				printf("de los años\n\n");
				aux = val;
				for (anual = 1; anual <= n; ++anual) {
					deprec = (n-anual+1)*aux / (n*(n+1)/2);
					val -= deprec;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", deprec);
					printf(" Valor actual: %8.2f\n", val);
				}
				break;
			case 4:
				printf("\nHasta luego y que tenga un buen dia\n");
				break;
			default:
				printf("\nEntrada de datos incorrecta");
				printf(" - repite por favor\n");
		}//fin de switch
	}//fin de while
}
