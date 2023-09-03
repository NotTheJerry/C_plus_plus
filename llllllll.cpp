#include <stdio.h>

int sumar(int n1, int n2){
	return n1+n2;
}

int restar(int n1, int n2){
	return n1-n2;
}

int multiplicar(int n1, int n2){
	return n1*n2;
}

int dividir(int n1, int n2){
	return n1/n2;
}

int main(){
		printf("\n ------------------------------------------------------------\n");
		printf("\n\tBienvenido al sistema\n");
		printf("\n ------------------------------------------------------------\n");
		printf("\n\t1)Sumar\n");
		printf("\n\t2)Restar\n");
		printf("\n\t3)Multiplicar\n");
		printf("\n\t4)Dividir\n");
		printf("\n\t5)Salir\n");
		printf("\n\tEscriba una opcion: "); scanf("%i",&o);
		
		switch(o){
			case 1:
				int n1, n2;
				printf("\n\tEscriba un numero: "); scanf("%i",&n1);
				printf("\n\tEscriba un numero: "); scanf("%i",&n2);
				int s = sumar(1,2);
				printf("La suma de lso dos numeros es: %i", s);
				printf("\n ------------------------------------------------------------\n");
		}
		
}
