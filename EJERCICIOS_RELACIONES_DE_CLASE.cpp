#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

class Bicicleta {
    public:
        string marca;
        int modelo;
        string color;
        string estadoDeLaBicicleta;
};

class Motor {
    public:
        int numeroDeSerieDelMotor;
};

class Auto {
    public:
        Motor motor;
        string marca;
        int modelo;
        string placa;
        string numeroDeSerieDelAuto;
        void asignarDatosDelCarro();
        void imprimirDatosDelAuto( ); 
};


class Cita {
    public:
        Auto car;
};

class Taller {
    public:
        string nombreDelTaller = "El TALLER DE LOS PROGRAMADORES";
        string telefonoDelTaller = "333-400-5599";
        vector<Cita> citasActuales;  
        void impresionDeDatosDelTaller();

};

void Taller::impresionDeDatosDelTaller() {
    cout<<"\n\tNombre del taller: "<<nombreDelTaller;
    cout<<"\n\tTelefono del taller: "<<telefonoDelTaller;
}

class Vehiculos {
    Auto autos;
    Bicicleta bicicletas;
};

void Auto::asignarDatosDelCarro() {
    cout<<"\n\tIngrese la marca del auto: "; cin>>marca;
    cout<<"\n\tIngrese el modelo del auto: "; cin>>modelo;
    cout<<"\n\tIngrese la placa del auto: "; cin>>placa;
    cout<<"\n\tIngrese el numero de serie del auto es: "; cin>>numeroDeSerieDelAuto;
}

void Auto::imprimirDatosDelAuto( ) {
    cout<<"\n\tLa marca del auto es: "<<marca;
    cout<<"\n\tEl modelo del auto es: "<<modelo;
    cout<<"\n\tLa placa del auto es: "<<placa;
    cout<<"\n\tEl numero de serie del auto es: "<<numeroDeSerieDelAuto;
}

void opcionSalir() { cout<<"\n\n\tIngrese el numero 4 para salir del programa o cualquier otro numero para regresar al menu\t"; }


int main () {

    Taller taller;
    int opcion;

    while (opcion != 4) {
        system("cls");
        cout<<"\n\tMENU DE OPCIONES TALLER DE LOS PROGRAMADORES";
        cout<<"\n\t1. Agregar una nueva cita";
        cout<<"\n\t2. Imprimir datos de la cita";
        cout<<"\n\t3. Imprimir datos del taller";
        cout<<"\n\t4. Salir\t\t\t"; cin>>opcion;


        switch (opcion) {
            case 1:
            {
                if ( taller.citasActuales.size() != 5 ) {
                    // Auto auto; Por que no se puede eso??
                    Cita cita;
                    Auto car;

                    car.asignarDatosDelCarro();            
                    cita.car = car;
                    taller.citasActuales.push_back(cita);

                    cout<<"\n\tCita creada exitosamente. Numero de cita: "<<taller.citasActuales.size()-1; 

                    opcionSalir(); cin>>opcion;
                    break;
                }

                cout<<"\n\tNo hay citas disponibles. Por favor espere a que se libere una o contactenos al telefono "<<taller.telefonoDelTaller;
                opcionSalir(); cin>>opcion;

                break;
            }
            case 2:
            {
                cout<<"\n\tIngrese el numero de la cita: "; cin>>opcion;

                if ( taller.citasActuales.size() == 0 || opcion < 0 || opcion+1 > taller.citasActuales.size() ) {  cout<<"\n\tPerdona, pero no tenemos en el sistema citas con ese numero, vuelva a intentarlo ";  }
                else {
                    Cita cita = taller.citasActuales[opcion];
                    cita.car.imprimirDatosDelAuto();    
                }
                            
                opcionSalir(); cin>>opcion;
                break;
            }
            case 3: {
                taller.impresionDeDatosDelTaller();
                opcionSalir(); cin>>opcion;
                break;
            }
            case 4: {
                cout<<"\n\n\tIngrese el numero 4 para confirmar el cierre del programa o cualquier otro numero para regresar al menu\n\n\t"; cin>>opcion;
            }
            
        } //Fin switch

    } //Fin del while

    cout<<"\n\tEl programa finzalizo. Vuelva pronto :)\n\n";

    return 0;

}