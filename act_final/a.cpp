#include <iostream> //stdout stdin
#include <stdlib.h> //system("clear")
#include <string> //getline
#include <vector>
#include <termios.h>  //getch() en LINUX
#include <unistd.h>  //getch() en LINUX
// #include <conio.h>

#define el endl;
#ifdef _WIN32
    #define SISTEMA 1
#elif defined(__linux__)
    #define SISTEMA 2
#endif

using namespace std;

void limpiarpantalla () { 
    if(SISTEMA == 1)
        system("cls");   
    else
        system("clear");
}

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

void getcha () { cout<<"\n\n\tIngrese cualquier tecla para continuar\t"; getch(); }  //Si es OS Windows, comentar funcion getch()  liberia "termios" y "unistd" y descomentar libreria conio.h
void opcionInvalida() { limpiarpantalla(); cout<<"\n\tERROR DE INGRESO DE OPCION"<<el; cout<<"\n\tNo ingresaste una opcion valida"; getcha(); }

class Persona {
    public:
    int numMaterias;
    string nombre, profesion, materias[20];

    virtual void leerDatos() = 0;
    virtual void setDatos() = 0;

};

class Alumno : public Persona
{
    private:
        int codigoAlumno;

    public:
        void setDatos() override {
            limpiarpantalla();
            cin.ignore();
            cout<<"\n\tESTABLECER DATOS ALUMNO"<<el;
            cout<<"\n\tIngrese su nombre: "; getline(cin, nombre); cout<<el;
            cout<<"\n\tIngrese su profesion es: "; getline(cin, profesion); cout<<el;
            cout<<"\n\tIngrese su codigo: "; cin>>codigoAlumno; cout<<el;
            cout<<"\n\tIngrese el numero de materias que esta cursando: "; cin>>numMaterias; cout<<el;
            cin.ignore();

            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t"<<i+1<<". Materia: "; getline(cin, materias[i]); cout<<el;
            }
            getcha();
        }

        void leerDatos() override {
            limpiarpantalla();
            cout<<"\n\tESTABLECER DATOS ALUMNO"<<el;
            cout<<"\n\tSu nombre es: "<<nombre<<el;
            cout<<"\n\tSu profesion es: "<<profesion<<el;
            cout<<"\n\tSu codigo es: "<<codigoAlumno<<el;
            cout<<"\n\tSus materias son"<<el;
            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t\t "<<i+1<<". Materia: "<<materias[i]<<el;
             }
            getcha();
        } 

         int getCodigoAlumno(){
            return codigoAlumno;
        }
};

class Profesor: public Persona
{
    private:
        int codigoProfesor;

    public:
        int getCodigo() {
            return codigoProfesor;
        }

        void setDatos() override {
            limpiarpantalla();
            cout<<"\n\tESTABLECER DATOS PROFESOR"<<el; cin.ignore();
            cout<<"\n\tIngrese su nombre: "; getline(cin, nombre); cout<<el;
            cout<<"\n\tIngrese su profesion es: "; getline(cin, profesion); cout<<el;
            cout<<"\n\tIngrese su codigo: "; cin>>codigoProfesor; cout<<el;
            cout<<"\n\tIngrese el numero de materias que imparte actualmente: "; cin>>numMaterias; cout<<el;

            cin.ignore();

            for(int i=0; i < numMaterias; i++){ 
                cout<<"\n\t"<<i+1<<". Materia: "; getline(cin, materias[i]); cout<<el;
            }
            getcha();
        }

        void leerDatos() override {
            limpiarpantalla(); 
            cout<<"\n\tESTABLECER DATOS PROFESOR"<<el;
            cout<<"\n\tSu nombre es: "<<nombre<<el;
            cout<<"\n\tSu codigo de alumno es: "<<codigoProfesor<<el;
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
        int leerDatos(vector<Profesor> vectorProfesores, vector<Alumno> vectorAlumnos) {
            limpiarpantalla();
            if (vectorAlumnos.empty() && vectorProfesores.empty()) { 
                cout<<"\n\tNO HAY REGISTROS DE NINGUN MAESTRO NI NINGUN ALUMNO"<<el;
                getcha();   return 0;
             }

            cout<<"\n\tDATOS DE TODOS LOS ALUMNOS"<<el;
            for (int i = 0; i < vectorAlumnos.size(); i++) {
                cout<<"\n\tSu nombre es: "<<vectorAlumnos[i].nombre<<el;
                cout<<"\n\tSu profesion es: "<<vectorAlumnos[i].profesion<<el;
                cout<<"\n\tSu codigo de alumno es: "<<vectorAlumnos[i].getCodigoAlumno()<<el;
                cout<<"\n\tLas materias que imparte son"<<el;
                for (int j=0; j < vectorAlumnos[i].numMaterias; j++) {
                    cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorAlumnos[i].materias[j]<<el;
                }
            }
            cout<<"\n\n\n\tDATOS DE TODOS LOS PROFESORES"<<el;
            for (int i = 0; i < vectorProfesores.size(); i++) {
                cout<<"\n\tSu nombre es: "<<vectorProfesores[i].nombre<<el;
                cout<<"\n\tSu profesion es: "<<vectorProfesores[i].profesion<<el;
                cout<<"\n\tSu codigo de profesor es: "<<vectorProfesores[i].getCodigo()<<el;
                cout<<"\n\tLas materias que imparte son"<<el;
                for (int j=0; j < vectorProfesores[i].numMaterias; j++) {
                    cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorProfesores[i].materias[j]<<el;
                }
            }
            getcha();
            return 0;
        } 
};

void verificacion(int pass, string w = " "){
    int c, intentos;
    while (true) {
        limpiarpantalla();
        cout<<"\n\tVERIFICACION "<<w<<el;
        cout<<"\n\tIntento: "<<intentos<<"\n\n\tIngrese la contrasenha para ingresar al sistema: "; cin>>c;
    if (c==pass) { break; } intentos++;
    }    
}

Alumno menuAlumnos() {
    int opcion = 0;
    Alumno alumno1;

    while(opcion != 3) {
    limpiarpantalla();
    cout<<"\n\tMENU ALUMNOS\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"   NOTA"<<el;
    cout<<"\n\t1. Ingresar sus datos\t\t\t\t\t\t\t\t\t"<<"   Para guardar la informacion del alumno salga al menu principal"<<el;
    cout<<"\n\t2. Imprimir sus datos\t\t\t\t\t\t\t\t"<<"Si quiere sobreescribir el alumno ingresado, ingrese los datos del nuevo alumno sin salir"<<el;
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
    limpiarpantalla();
    cout<<"\n\tMENU PROFESORES\t\t\t\t\t\t\t\t\t\t\t\t\t\t"<<"   NOTA"<<el;
    cout<<"\n\t1. Ingresar sus datos\t\t\t\t\t\t\t\t\t"<<"    Para guardar la informacion del profesor salga al menu principal"<<el;
    cout<<"\n\t2. Imprimir sus datos\t\t\t\t\t\t\t\t"<<"Si quiere sobreescribir el profesor ingresado, ingrese los datos del nuevo profesor sin salir"<<el;
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
    limpiarpantalla();
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
    limpiarpantalla();
    cout<<"\n\tFIN DEL PROGRAMA"<<el;
    cout<<"\n\tGracias por utilizarlo. Vuelva pronto... ;)\n\n\n\n"<<el;
}

void menuBusquedaIndividual(vector<Profesor> vectorProfesores, vector<Alumno> vectorAlumnos) {
    int opcion = 10;
    Admin admin;
    while(opcion != 0) {
    limpiarpantalla();
    cout<<"\n\tBUSQUEDA DE UN ALUMNO/PROFESOR DE FORMA INDIVIDUAL"<<el;
    cout<<"\n\tIngresa el codigo del alumno o profesor que quieres que se muestre su informacion"<<el;
    cout<<"\n\tPresiona 0 para salir al menu principal"<<el;
    cout<<"\n\tIngrese una opcion:\t"; cin>>opcion;
    
    
        switch(opcion){
        case 0:
            break;
        default:
            bool a = false;
            for (int i = 0; i < vectorProfesores.size(); i++) {
                if (vectorProfesores[i].getCodigo() == opcion) {
                    limpiarpantalla();
                    cout<<"\n\tINFORMACION ENCONTRADA DE UN PROFESOR"<<el;
                    cout<<"\n\tSu nombre es: "<<vectorProfesores[i].nombre<<el;
                    cout<<"\n\tSu profesion es: "<<vectorProfesores[i].profesion<<el;
                    cout<<"\n\tLas materias que imparte son"<<el;
                    for (int j=0; j < vectorProfesores[i].numMaterias; j++) {
                        cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorProfesores[i].materias[j]<<el;
                    }
                    a = true;
                    getcha();
                } // if     
            } //1er for

            for (int i = 0; i < vectorAlumnos.size(); i++) {
                if (vectorAlumnos[i].getCodigoAlumno() == opcion) {
                    limpiarpantalla();
                    cout<<"\n\tINFORMACION ENCONTRADA DE UN ALUMNO"<<el;
                    cout<<"\n\tSu nombre es: "<<vectorAlumnos[i].nombre<<el;
                    cout<<"\n\tSu profesion es: "<<vectorAlumnos[i].profesion<<el;
                    cout<<"\n\tLas materias que imparte son"<<el;
                    for (int j=0; j < vectorAlumnos[i].numMaterias; j++) {
                        cout<<"\n\t\t "<<j+1<<". Materia: "<<vectorAlumnos[i].materias[j]<<el;
                    }
                    a = true;
                    getcha();
                } // if     
            } //1er for

            if (!a) { cout<<"\n\tNO SE ENCONTRO NADA DE INFORMACION DE ACUERDO AL CODIGO QUE INGRESASTE"<<el; getcha(); } 
        } //switch
    } //while
} //menuBusquedaIndividual

void menu() {
    int opcion;
    vector<Profesor> vectorProfesores;
    vector<Alumno> vectorAlumnos;
    Alumno alumno; 
    Profesor profesor;
    while(opcion != 5) {
        limpiarpantalla();
        cout<<"\n\tMENU"<<el;
        cout<<"\n\t1. Alumnos"<<el;
        cout<<"\n\t2. Profesores"<<el;
        cout<<"\n\t3. Administrador"<<el;
        cout<<"\n\t4. Consulta informacion de un alumno/profesor"<<el;
        cout<<"\n\t5. Salir"<<el;
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
            verificacion(8080, "ADMINISTRADOR");
            menuAdmin(vectorProfesores, vectorAlumnos);
            break;
        case 4:
            menuBusquedaIndividual(vectorProfesores, vectorAlumnos);
            break;
        case 5:
            break;
        default:
            opcionInvalida();
        }
    }

    finPrograma();
}



int main()
{
    verificacion(1010);
	menu();

    return 0;
}