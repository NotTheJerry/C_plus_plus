#include <iostream> //stdout stdin
#include <stdlib.h> //system("clear")
#include <string> //getline

#define el endl;

using namespace std;


#include <termios.h>
#include <unistd.h>

char getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");
    return (buf);
}



void getchi() { cout<<"\n\n\tPresione cualquier tecla para continuar\t"; getch(); }
void opcionInvalida() { system("clear"); cout<<"\n\tERROR DE INGRESO DE OPCION"<<el; cout<<"\n\tNo ingresaste una opcion valida"; getchi(); }
// void getch() { int aux; cout<<"\n\n\tIngrese cualquier letra/numero para continuar\t"; cin>>aux; }

class Persona {
    public:
    int numMaterias;
    string nombre, profesion, materias[20];

    virtual void leerDatos() = 0;
    virtual void setDatos() = 0;

};

class Alumno : public Persona
{
    public:
        void setDatos() override {
            system("clear");
            cin.ignore();
            cout<<"\n\tESTABLECER DATOS ALUMNO"<<el;
            cout<<"\n\tIngrese su nombre: "; getline(cin, nombre); cout<<el;
            cout<<"\n\tIngrese su profesion es: "; getline(cin, profesion); cout<<el;
            cout<<"\n\tIngrese el numero de materias que esta cursando: "; cin>>numMaterias; cout<<el;
            cin.ignore();
            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t"<<i+1<<". Materia: "; getline(cin, materias[i]); cout<<el;
            }
        }

        void leerDatos() override {
            system("clear"); string aux;
            cout<<"\n\tESTABLECER DATOS ALUMNO"<<el;
            cout<<"\n\tSu nombre es: "<<nombre<<el;
            cout<<"\n\tSu profesion es: "<<profesion<<el;
            cout<<"\n\tSus materias son"<<el;
            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t\t "<<i+1<<". Materia: "<<materias[i]<<el;
             }
            getchi();
        } 
};

void bienvenida(){
    int c, intentos;
    while (true) {
        system("clear");
        cout<<"\n\tBIENVENIDO AL PROGRAMA"<<el;
        cout<<"\n\tIntento: "<<intentos<<"\n\n\tIngrese la contrasenha para ingresar al sistema: "; cin>>c;
    if (c==12345) { break; } intentos++;
    }    
}

int menuAlumnos() {
    int opcion = 0;
    Alumno alumno1;

    while(opcion != 3) {
    cin.ignore();
    system("clear");
    cout<<"\n\tMENU ALUMNOS"<<el;
    cout<<"\n\t1. Ingresar sus datos"<<el;
    cout<<"\n\t2. Imprimir sus datos"<<el;
    cout<<"\n\t3. Salir al menu"<<el;
    cout<<"\n\tSeleccione una opcion:\t"; cin>>opcion;
    
    
        switch(opcion){
        case 1:
            alumno1.setDatos();
            break;
        case 2:
            alumno1.leerDatos();
            break;
        case 3:
            opcion = 3;
            break;
        default:
            opcionInvalida();
        }
    }

    return 0;
}

void menuProfesores() {

}

void finPrograma() {

}

void menu() {
    int opcion;
    while(opcion != 3) {
        system("clear");
        cout<<"\n\tMENU"<<el;
        cout<<"\n\t1. Alumnos"<<el;
        cout<<"\n\t2. Profesores"<<el;
        cout<<"\n\t3. Salir"<<el;
        cout<<"\n\tSeleccione una opcion:\t"; cin>>opcion;
        
        switch(opcion){
        case 1:
            menuAlumnos();
            break;
        case 2:
            menuProfesores();
            break;
        case 3:
            break;
        default:
            opcionInvalida();
        }
    }
}



int main()
{
    int opcion;
    bienvenida();
	menu();
    while(opcion != 3) {
        switch(opcion){
        case 1:
            menuAlumnos();
            break;
        case 2:
            menuProfesores();
            break;
        case 3:
            break;
        default:
            cout<<"\n\tNo ingresaste una opcion valida";
        }
    }

    finPrograma();
    return 0;
}