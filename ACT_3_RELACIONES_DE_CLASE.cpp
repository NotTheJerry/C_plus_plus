#include <iostream>
#include <vector>

using namespace std;

/*
La empresa "X" cuenta con obreros y directivos. Todos los empleados tienen un código numérico conocido en la empresa como "id".

Al obrero se le asigna cierta cantidad de horas al día que pueden ser de 7 a 10 horas de trabajo diarias, el sistema pedirá cuantas horas serán asignadas en ese día de lunes a viernes. Y dependiendo de las horas trabajadas el programa determinará su sueldo a la semana para que aparezca en pantalla el id del obrero, las horas totales que trabajo a la semana y el sueldo semanal.

Para el directivo se cuenta con cuatro tipo de puestos: el tipo 1 es gerente de sucursal, el tipo 2 es jefe de unidad,  el tipo 3 es coordinador de área y el tipo 4 es administrativo.  A los directivos se les asigna una oficina según sea el tipo de puesto que tengan.

Las Oficinas que tiene la empresa están asignadas por tres ubicaciones: ubicación A son oficinas privadas, ubicación B son cubículos compartidos y ubicación C son escritorios establecidos fuera de las ubicaciones A yB. Las oficinas se ubicarán de acuerdo al tipo de puesto que tenga el directivo.
*/

class Obrero {
    public:
        int id;
        int horasSemanal;
        float sueldo;

        void calcularSueldo();
};

class Directivo {

    public:
        string tipoDePuesto;
        void asignarPuesto( int p );

};

void Obrero::calcularSueldo(){
    vector<string> diasDeLaSemana = {"lunes", "martes", "miercoles", "jueves", "viernes"};
    int horasDelDia, precioPorHora = 10;

    for( int i = 0; i < diasDeLaSemana.size(); i++ ){
        cout<<"\n\tCuantas horas trabajaras el dia "<<diasDeLaSemana[i]<<"?"; 
        if ( diasDeLaSemana[i] == diasDeLaSemana[2] || diasDeLaSemana[i] == diasDeLaSemana[4] ){ cout<<"\t"; } else{ cout<<"\t\t"; } cin>>horasDelDia;
        this->horasSemanal = this->horasSemanal + horasDelDia;
    }
    
    this->sueldo = ( this->horasSemanal * precioPorHora );

}

void Directivo::asignarPuesto( int p ) {
    vector<string> tiposDePuestos = {"Gerente de sucursal","Jefe de unidad","Coordinador de tarea","Administrativo"};

    this->tipoDePuesto = tiposDePuestos[p-1];

}

int main(int argc, char const *argv[])
{
    int opcion;

    while (opcion != 3) {
        system("cls");
        cout<<"\n\tMENU DE OPCIONES";
        cout<<"\n\tDigite un numero de acuerdo a la opcion que gustes ingresar";
        cout<<"\n\t1. Obrero";
        cout<<"\n\t2. Directivo"; 
        cout<<"\n\t3. Salir\t\t\t"; cin>>opcion;

        switch (opcion) {
            case 1:
            {
                Obrero obrero1;
                cout<<"\n\tDigite su ID: "; cin>>obrero1.id;
                // cout<<"\n\tDigite su nombre: "; cin.ignore(); getline(cin, obreo1.nombre);
                obrero1.calcularSueldo();
                cout<<"\n\tEl numero total de horas trabajadas esta semana es de "<<obrero1.horasSemanal<<" hrs";
                cout<<"\n\n\tSu sueldo semanal es de "<<obrero1.sueldo<<" pesos";
                cout<<"\n\n\tIngrese el numero 3 para salir del programa o cualquier otro numero para regresar al menu\t"; cin>>opcion;
                break;
            }
            case 2:
            {
                Directivo directivo1;
                int n;
                // cout<<"\n\tDigite su ID: "; cin>>directivo1.id;
                // cout<<"\n\tDigite su nombre: "; cin.ignore(); getline(cin, obreo1.nombre);
                cout<<"\n\tIngrese el numero de tipo de su puesto: "; cin>>n; directivo1.asignarPuesto(n); 
                cout<<"\n\tSu tipo de puesto es: "<<directivo1.tipoDePuesto; 

                cout<<"\n\n\tIngrese el numero 3 para salir del programa o cualquier otro numero para regresar al menu\t"; cin>>opcion;
                break;
            }
            case 3: {
                cout<<"\n\n\tIngrese el numero 3 para confirmar el cierre del programa o cualquier otro numero para regresar al menu\n\n\t"; cin>>opcion;
            }
            
        } //Fin switch

    } //Fin del while

    return 0;
}
