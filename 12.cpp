#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

void menu();
void farenheitacentigrados();
void centigradosafarenheit();
void centigradosakelvin();
void kelvinacentigrados();

int main(){
	setlocale(LC_ALL,"");
	menu();
	printf("\n\n    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tUsted salió del programa\n\n");
	
	return 0;
}

void menu(){
	int o;
	do {
		system("cls");
		printf("\n    ----------------------------------------------------------------------------------------------------\n\n");
		printf("\tBienvenido al programa\n\n");
		printf("    ----------------------------------------------------------------------------------------------------\n");
		printf("\n\t1.-Grados °F a °C\n\n");
		printf("\n\t2.-Grados °C a °F\n\n");
		printf("\n\t3.-Grados °C a °K\n\n");
		printf("\n\t4.-Grados °K a °C\n\n");
		printf("\n\t5.-Salir\n\n"); 
		printf("\tEscoga una opción: "); scanf("%i",&o);
		
		switch(o){
			case 1: farenheitacentigrados(); break;
			case 2: centigradosafarenheit(); break;
			case 3: centigradosakelvin(); break;
			case 4: kelvinacentigrados();
		}
	
	} while(o != 5);
}

void farenheitacentigrados(){ float o,n, con; system("cls");
		system("cls");
		printf("\n    ----------------------------------------------------------------------------------------------------\n\n");
		printf("\tFarenheit a centigrados\n\n");
		printf("    ----------------------------------------------------------------------------------------------------\n\n");
		printf("\tIngrese los grados farenheit: "); scanf("%f",&o);
		printf("\n    ----------------------------------------------------------------------------------------------------\n");
		con = (o-32)/1.8;
		printf("\n\t%0.2f grados farenheit son %0.2f grados centígrados     ",o,con);
		printf("\n\n    ----------------------------------------------------------------------------------------------------");
		printf("\n\n\tPresione una tecla para continuar\n");  getch();
}

void centigradosafarenheit(){ float o,con; system("cls");
	printf("\n    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tCentigrados a farenheit\n\n");
	printf("    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tIngrese los grados centígrados: "); scanf("%f",&o);
	printf("\n    ----------------------------------------------------------------------------------------------------\n");
	con = (o*1.8)+32;
	printf("\n\t%0.2f grados centígrados son %0.2f grados farenheit     ",o,con); getch();
}

void centigradosakelvin(){ float o,con; system("cls");
	printf("\n    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tCentígrados a kelvin\n\n");
	printf("    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tIngrese los grados centígrados: "); scanf("%f",&o);
	printf("\n    ----------------------------------------------------------------------------------------------------\n");
	con = o + 273;
	printf("\n\t%0.2f grados centígrados son %0.2f grados kelvin     ",o,con); getch();
}

void kelvinacentigrados(){ float o,con; system("cls");
	printf("\n    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tKelvin a centígrados\n\n");
	printf("    ----------------------------------------------------------------------------------------------------\n\n");
	printf("\tIngrese los grados kelvin: "); scanf("%f",&o);
	printf("\n    ----------------------------------------------------------------------------------------------------\n");
	con = o - 273.15;
	printf("\n\t%0.2f grados kelvin son %0.2f grados centígrados     ",o,con); getch();
}

