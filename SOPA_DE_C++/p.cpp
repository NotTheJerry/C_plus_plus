#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()
{	
	setlocale(LC_ALL,"spanish");
	int a[15], positivos=0, negativos=0, sumap=0, suman=0, cero=0;
	printf("\n ------------------------------------------------------------\n");
	printf("\n\tBienvenido al programa\n");
	printf("\n ------------------------------------------------------------\n");
	for(int i=0;i<15; i++){
		printf("\n\tEscriba un valor: "); scanf("%i",&a[i]);
		printf("\n ------------------------------------------------------------\n");
		if(a[i]>0){
			sumap += a[i];
			positivos++;
		} else if(a[i]==0){
			cero++;
		} else {
			suman += a[i];
			negativos++;
			} //else
	} //for
		
	printf("\n\tUsted ingreso %i numeros positivos",positivos); 
	
	printf("\n\tUsted ingreso %i numeros negativos",negativos);
	
	printf("\n\tUsted ingreso %i numeros cero",cero);  	
		
	printf("\n\tLa suma de los numeros positivos es: %i", sumap); 
		
	printf("\n\tLa suma de los numeros negativos es: %i", suman);

	printf("\n\n ------------------------------------------------------------");
	printf("\n\n\tPresione <enter> para salir del programa\n\n");
	printf(" ------------------------------------------------------------\n");
		
	return 0;
}
