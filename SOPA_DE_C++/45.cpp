#include <stdio.h>

void uno();
void dos();
void tres();
void cuatro();
void cinco();
void seis();
void siete();
void ocho();
void nueve();
void diez();
void menu();

int main(){
	
	menu();
	
	return 0;
}

void menu(){
	int opc;
	
	do {
		printf("\nPresione un numero entero entre 1 y el 10 (Presione 11 para salir):      ");
		scanf("%i",&opc);
		
		switch(opc){
			case 1: uno(); break;
			case 2: dos(); break;
			case 3: tres(); break;
			case 4: cuatro(); break;
			case 5: cinco(); break;
			case 6: seis(); break;
			case 7: siete(); break;
			case 8: ocho(); break;
			case 9: nueve(); break;
			case 10: diez(); break;
		}
		
	}while(opc != 11);
}

void uno(){printf("\nUno ");}
void dos(){printf("\nDos ");}
void tres(){printf("\nTres ");}
void cuatro(){printf("\nCuatro ");}
void cinco(){printf("\nCinco ");}
void seis(){printf("\nSeis ");}
void siete(){printf("\nSiete ");}
void ocho(){printf("\nOcho ");}
void nueve(){printf("\nNueve ");}
void diez(){printf("\nDiez ");}
