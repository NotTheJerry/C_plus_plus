#include <iostream> //stdout stdin
#include <stdlib.h> //system("clear")
#include <string> //getline
#include <vector>

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

void getcha () { cout<<"\n\n\tIngrese cualquier tecla para continuar\t"; getch(); }
void getchi() { string o; cout<<"\n\n\tIngrese cualquier tecla para continuar\t"; getline(cin, o); }
void opcionInvalida() { system("clear"); cout<<"\n\tERROR DE INGRESO DE OPCION"<<el; cout<<"\n\tNo ingresaste una opcion valida"; getchi(); }

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
            getcha();
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
            getcha();
        } 
};

class Profesor: public Persona
{
    public:
        void setDatos() override {
            system("clear");
            cin.ignore();
            cout<<"\n\tESTABLECER DATOS PROFESOR"<<el;
            cout<<"\n\tIngrese su nombre: "; getline(cin, nombre); cout<<el;
            cout<<"\n\tIngrese su profesion es: "; getline(cin, profesion); cout<<el;
            cout<<"\n\tIngrese el numero de materias que imparte actualmente: "; cin>>numMaterias; cout<<el;
            cin.ignore();

            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t"<<i+1<<". Materia: "; getline(cin, materias[i]); cout<<el;
            }
            getcha();
        }

        void leerDatos() override {
            system("clear"); string aux;
            cout<<"\n\tESTABLECER DATOS PROFESOR"<<el;
            cout<<"\n\tSu nombre es: "<<nombre<<el;
            cout<<"\n\tSu profesion es: "<<profesion<<el;
            cout<<"\n\tLas materias que imparte son"<<el;
            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t\t "<<i+1<<". Materia: "<<materias[i]<<el;
             }
            getcha();
        } 
};

class Admin {
    public:
        void leerDatos(vector<Profesor> vectorProfesores, vector<Alumno> vectorAlumnos) {
            system("clear"); string aux;
            cout<<"\n\tDATOS DE TODOS LOS ALUMNOS"<<el;
            for (int i = 0; i < vectorAlumnos.size(); i++) {
                cout<<"\n\tSu nombre es: "<<vectorAlumnos[i].nombre<<el;
                cout<<"\n\tSu profesion es: "<<vectorAlumnos[i].profesion<<el;
                cout<<"\n\tLas materias que imparte son"<<el;
                for (int j=0; j < vectorAlumnos[i].numMaterias; j++) {
                    cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorAlumnos[i].materias[j]<<el;
                }
            }
            cout<<"\n\n\n\tDATOS DE TODOS LOS PROFESORES"<<el;
            for (int i = 0; i < vectorProfesores.size(); i++) {
                cout<<"\n\tSu nombre es: "<<vectorProfesores[i].nombre<<el;
                cout<<"\n\tSu profesion es: "<<vectorProfesores[i].profesion<<el;
                cout<<"\n\tLas materias que imparte son"<<el;
                for (int j=0; j < vectorProfesores[i].numMaterias; j++) {
                    cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorProfesores[i].materias[j]<<el;
                }
            }
            getcha();
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

Alumno menuAlumnos() {
    int opcion = 0;
    Alumno alumno1;

    while(opcion != 3) {
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

    return alumno1;
}

Profesor menuProfesores() {
    int opcion = 0;
    Profesor profesor1;

    while(opcion != 3) {
    system("clear");
    cout<<"\n\tMENU PROFESORES"<<el;
    cout<<"\n\t1. Ingresar sus datos"<<el;
    cout<<"\n\t2. Imprimir sus datos"<<el;
    cout<<"\n\t3. Salir al menu"<<el;
    cout<<"\n\tSeleccione una opcion:\t"; cin>>opcion;
    
    
        switch(opcion){
        case 1:
            profesor1.setDatos();
            break;
        case 2:
            profesor1.leerDatos();
            break;
        case 3:
            opcion = 3;
            break;
        default:
            opcionInvalida();
        }
    }
    return profesor1;
}

void menuAdmin(vector<Profesor> vectorProfesores, vector<Alumno> vectorAlumnos) {
    int opcion = 0;
    Admin admin;
    while(opcion != 2) {
    system("clear");
    cout<<"\n\tMENU ADMIN"<<el;
    cout<<"\n\t1. Mostrar los datos de todos los alumnos"<<el;
    cout<<"\n\t2. Salir al menu"<<el;
    cout<<"\n\tSeleccione una opcion:\t"; cin>>opcion;
    
    
        switch(opcion){
        case 1:
            admin.leerDatos(vectorProfesores, vectorAlumnos);
            break;
        case 2:
            opcion = 2;
            break;
        default:
            opcionInvalida();
        }
    }
}

void finPrograma() {

}

void menu() {
    int opcion;
    vector<Profesor> vectorProfesores;
    vector<Alumno> vectorAlumnos;
    Alumno alumno; 
    Profesor profesor;
    while(opcion != 4) {
        system("clear");
        cout<<"\n\tMENU"<<el;
        cout<<"\n\t1. Alumnos"<<el;
        cout<<"\n\t2. Profesores"<<el;
        cout<<"\n\t3. Administrador"<<el;
        cout<<"\n\t4. Salir"<<el;
        cout<<"\n\tSeleccione una opcion:\t"; cin>>opcion;
        
        switch(opcion){
        case 1:
            alumno = menuAlumnos();
            vectorAlumnos.push_back(alumno);
            break;
        case 2:
            profesor = menuProfesores();
            vectorProfesores.push_back(profesor);
            break;
        case 3:
            menuAdmin(vectorProfesores, vectorAlumnos);
            break;
        case 4:
            break;
        default:
            opcionInvalida();
        }
    }
}



int main()
{
    int opcion;
    // bienvenida();
	menu();

    finPrograma();
    return 0;
}