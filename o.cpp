#include <stdio.h>
#include <conio.h>
#include <windows.h>
int main(){
	while(true) {
	system("cls");
	int matriz[2][3];
	int i, j,o;
	printf("\n ------------------------------------------------------------\n");
	printf("\n\t\t BIENVENIDO AL PROGRAMA\n");
	printf("\n ------------------------------------------------------------\n\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			printf("\tDigite un valor: "); scanf("%i",&matriz[i][j]); printf("\n");
				}
			printf("\n\n");
		}
		
	printf("\tLos valores ingresados en la matriz (2x3):\n\n");
		
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			Sleep(600); printf("\t\t%i",matriz[i][j]);
						}
		printf("\n\n");
		}
	printf("\n ------------------------------------------------------------\n\n");
	printf("\tDesea salir del programa? Digite 1 para salir...\t"); scanf("%i",&o);
	if (o==1) {break;}
	} //while
	printf("\n ------------------------------------------------------------\n\n");
	printf("\tPresione <enter> para salir del programa\n\n");
	return 0;
}
