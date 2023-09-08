#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <iostream.h>

int main()
{	
	setlocale(LC_ALL,"spanish");
	int a[15], b[15], v=14;
	cout<<"Hola";
	printf("\n ------------------------------------------------------------\n");
	printf("\n\tBienvenido al programa\n");
	printf("\n ------------------------------------------------------------\n");
	for(int i=0;i<15; i++){
		printf("\n\tEscriba un valor: "); scanf("%i",&a[i]);
		printf("\n ------------------------------------------------------------\n");
		b[v]=a[i];
		v--;
		}
		
	printf("\n\tLos valores del vector original son: "); Sleep(400);
	
	for(int i=0;i<15; i++){
		printf("%i ",a[i]);
		}
		
	printf("\n\tLos valores del vector resultante son: "); Sleep(400);
	
	for(int i=0;i<15; i++){
		printf("%i ",b[i]);
		}

	printf("\n\n ------------------------------------------------------------");
	printf("\n\n\tPresione <enter> para salir del programa\n\n");
	printf(" ------------------------------------------------------------\n");
		
	return 0;
}

