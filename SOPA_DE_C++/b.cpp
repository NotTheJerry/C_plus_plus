#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()
{	
	setlocale(LC_ALL,"spanish");
	int a[15], p[15], positivos=0, n[15], negativos=0, sumap=0, suman=0;
	printf("\n ------------------------------------------------------------\n");
	printf("\n\tBienvenido al programa\n");
	printf("\n ------------------------------------------------------------\n");
	for(int i=0;i<15; i++){
		printf("\n\tEscriba un valor: "); scanf("%i",&a[i]);
		printf("\n ------------------------------------------------------------\n");
		if(a[i]>0){
			p[i] = a[i];
			positivos++;
		} else {
			n[i] = a[i];
			negativos++;
			} //else
	} //for
	
//	printf("\n\tLos valores del arreglo p son: "); Sleep(400);
//	
//	for(int i=0;i<15; i++){
//		printf("%i ",p[i]);
//		}
//	
	printf("\n\tLos valores del arreglo n son: "); Sleep(400);
	
	for(int i=0;i<15; i++){
		printf("%i ",n[i]);
		}
	
	for(int i=0;i<positivos; i++){
		sumap = sumap + p[i];
	}
		
	printf("\n\tUsted ingreso %i numeros positivos",positivos); 
	
	printf("\n\tUsted ingreso %i numeros negativos",negativos); 	
		
	printf("\n\tLa suma de los numeros positivos es: %i", sumap); 
	
	for(int i=0;i<negativos; i++){
		suman = suman + (n[i]);
	}
		
	printf("\n\tLa suma de los numeros negativos es: %i", suman);

	printf("\n\n ------------------------------------------------------------");
	printf("\n\n\tPresione <enter> para salir del programa\n\n");
	printf(" ------------------------------------------------------------\n");
		
	return 0;
}
