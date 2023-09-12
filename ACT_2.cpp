#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
using namespace std;

/*
Se quiere tener un sistema que tenga un menu con tres opciones:

1. Maestro

2. Alumno

3. Salir

Para el maestro se quiere calcular su sueldo quincenal de acuerdo a la hora clase que se le paga. 
Si el maestro tiene m�s de 10 a�os de antig�edad recibe 120.00 la hora, si tiene m�s de 20 a�os de antig�edad recibe 210.00 
y si tiene menos de 10 a�os recibe 95.00 la hora. Tomar en cuenta que el maestro trabaja de lunes a viernes.
 El maestro cuenta con c�digo, nombre y n�mero de grupos a los que da clase. Imprimir todos los datos m�s el sueldo quincenal.

Para el Alumno es necesario mostrar en pantalla los datos del alumno
(primero se le preguntan al usuario del sistema) codigo, nombre, semestre y n�mero de calificaciones.  
Preguntar que calificaci�n sac� de acuerdo al n�mero espec�ficado. La calificaci�n ser� de 0 a 100. Sacar el promedio de las calificaciones. Imprimir todos los datos m�s el promedio.

En cada opci�n preguntar si quiere regresar al men�

En la tercera opci�n preguntar al usuario si se quiere salir del programa, de ser as� escribir un mensaje indicando 
que el programa a terminado, de lo contrario regresar al men�
*/

class Maestro {
	public:
		int codigo;
		string nombre;
		int numgrupos;
		int ayosAntiguedad;
		float calcularSueldoQuincenal();
		void imprimirDatos();
		//Maestro(int codigo,	string nombre, int numGrupos, int ayosAntiguedad);
		//Maestro();
};

class Alumno : public Maestro {
	public:
		int semestre;
		int numcalificaciones;
		float calcularPromedio();
		void imprimirDatos(float p);
		//Alumno(int codigo, string nombre, int semestre, int numcalificaciones);
		//Alumno();
};

float Maestro::calcularSueldoQuincenal(){

	if (this->ayosAntiguedad > 10 && this->ayosAntiguedad < 20) { return ( 10 * ( 120 * this->numgrupos ) );  }
	
	if (this->ayosAntiguedad > 20) { return ( 10 * ( 210 * this->numgrupos ) );  }
	
	if (this->ayosAntiguedad < 10) { return ( 10 * ( 95 * this->numgrupos ) );  } 

	return 0;

}

float Alumno::calcularPromedio(){
	
	float promedio, calificacion;
	
	for (int i=0; i < this->numcalificaciones; i++) {
		cout<<"\n\tIngresa una calificacion: "; cin>>calificacion;
		promedio = promedio + calificacion;
	}
	
	return (promedio/this->numcalificaciones);
	
}

void Maestro::imprimirDatos() {

	cout<<"\n\tSu codigo es: "<<this->codigo;
	cout<<"\n\tSu nombre es: "<<this->nombre;
	cout<<"\n\tSu antiguedad en la institucion es de: "<<this->ayosAntiguedad; if (  this->ayosAntiguedad == 1 ){ cout<<" ayo"; } else { cout<<" ayos"; }  
	cout<<"\n\tEl numero de grupos que usted da clase son "<<this->numgrupos; if (  this->numgrupos == 1 ){ cout<<" grupo"; } else { cout<<" grupos"; }  
	cout<<"\n\tSu sueldo quincenal es de "<<this->calcularSueldoQuincenal()<<" pesos";

}

void Alumno::imprimirDatos(float p) {

	cout<<"\n\tSu codigo es: "<<this->codigo;
	cout<<"\n\tSu nombre es: "<<this->nombre;
	cout<<"\n\tEstas cursando el "<<this->semestre<<" semestre";
	cout<<"\n\tTu promedio es de "<<p;

}

int main() {
	
	int opcion = 0;
	
	while ( opcion != 3 ) {
		system("cls");
		cout<<"\n\tMENU DE OPCIONES";
		cout<<"\n\tDigite un numero de acuerdo a la opcion que gustes ingresar";
		cout<<"\n\t1. Maestro";
		cout<<"\n\t2. Alumno"; 
		cout<<"\n\t3. Salir\t\t\t"; cin>>opcion;
		
		switch (opcion) {
			case 1:
			{
				Maestro maestro1;
				cout<<"\n\tDigite su codigo de maestro: "; cin>>maestro1.codigo;
				cout<<"\n\tDigite su nombre: "; cin.ignore(); getline(cin, maestro1.nombre);
				cout<<"\n\tDigite el numero de ayos que lleva en la institucion: "; cin>>maestro1.ayosAntiguedad;
				cout<<"\n\tDigite el numero de grupos que tiene actualmente: "; cin>>maestro1.numgrupos;
				maestro1.imprimirDatos();
				cout<<"\n\n\tIngrese el numero 3 para salir del programa o cualquier otro numero para regresar al menu\t"; cin>>opcion;
				break;
			}
			case 2:
			{
				Alumno alumno1;
				cout<<"\n\tDigite su codigo de alumno: "; cin>>alumno1.codigo;
				cout<<"\n\tDigite su nombre: "; cin>>alumno1.nombre;
				cout<<"\n\tDigite el numero de semestre que esta cursando: "; cin>>alumno1.semestre;
				cout<<"\n\tDigite el numero de calificaciones que obtuvo: "; cin>>alumno1.numcalificaciones;
				float p = alumno1.calcularPromedio();
				alumno1.imprimirDatos(p);

				cout<<"\n\n\tIngrese el numero 3 para salir del programa o cualquier otro numero para regresar al menu\t"; cin>>opcion;
				break;
			}
			case 3: {
				cout<<"\n\n\tIngrese el numero 3 para confirmar el cierre del programa o cualquier otro numero para regresar al menu\n\n\t"; cin>>opcion;
			}
			
		} //Fin switch
		
	} //Fin while
	
	cout<<"\n\tUsted salio del programa";
	cout<<"\n\n\tVuelva pronto   :)\n\n\n";
	
	return 0;
}