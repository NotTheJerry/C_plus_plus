#include <stdio.h>
#include <conio.h>
#include <windows.h>

int main(){
	int matriz[2][3];
	
	int i, j;
	
	printf("\n ------------------------------------------------------------\n");
	printf("\n\tBIENVENIDO AL PROGRAMA\n");
	printf("\n ------------------------------------------------------------\n\n");
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("\tDigite un numero entero: "); scanf("%i",&matriz[i][j]); printf("\n");
		}
		printf("\n");
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			Sleep(600); printf("          %i",matriz[i][j]);
			fflush(stdin);
		}
		printf("\n");
	}
	
	printf("\n ------------------------------------------------------------\n\n");
	printf("\tPresione <enter> para salir del programa\n\n");
	
	return 0;
}

