/*
 ============================================================================
 Name        : practica1.c
 Author      : valentin
 Version     :
 Copyright   : Your copyright notice
 Description : calculo de deprececiacion de bienes en 3 formas distintas
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int modo, n, anual;
	float valor, temp, depre;

	while(modo !=4){
		printf("Inserte modo de calcular depreciación,(1-LR \t2-BD \t3-SDA \t4-Fin) \n ");
		scanf("%d", &modo);
		if (modo >= 1 && modo <= 3) {
			printf("Valor original: ");
			scanf("%f",&valor);
			printf("Numero de años: ");
			scanf("%d",&n);
		}
		switch (modo) {
			case 1:
				printf("primer caso, depreciacion lineal \n");
				depre = valor/n;
				for( anual =1; anual <= n ; ++anual ){
					valor -= depre;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", depre);
					printf(" Valor actual: %8.2f\n", valor);
				}
				break;
			case 2:
				printf("segundo caso, balance DD \n");
				for (anual =1; anual <=n; ++anual){
					depre = valor/n;
					valor -= depre;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", depre);
					printf(" Valor actual: %8.2f\n", valor);
				}
				break;
			case 3:
				printf("tercer caso, suma de digitos de los años \n ");
				temp = valor;
				for (anual= 1; anual <=n; ++anual){
					depre = (n-anual+1)*temp/(n*(n+1)/2);
					valor -= depre;
					printf("Fin de año %2d", anual);
					printf(" Depreciacion: %7.2f", depre);
					printf(" Valor actual: %8.2f\n", valor);
				}
				break;
			case 4:
				printf("exit");
				break;
			default:
				printf("Vamos de vuelta");
		}
	}
}
