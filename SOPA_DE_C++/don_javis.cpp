#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#define MAX_CLIENTES 50
#define MAX_CAMPOS 5
#define MAX_PRODUCTOS 100


void gotoxy(int x, int y) {
    HANDLE Prim = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coordenada;
    coordenada.X = x;
    coordenada.Y = y;
    SetConsoleCursorPosition(Prim, coordenada);
}

void bienvenida() {
    char Usuarios [] = "Javiercito";
    char Usuario [25] = "";
    char Contras [] = "javierpro";
    char Contra [25] = "";
    int j= 0;

    //Logo//
    gotoxy(32,5);
    printf("MMMMMMMMMMMMMMMMWWNNXKK0000OOOOOO0000KXXNNWMMMMMMMMMMMMMMMMM\n");
    gotoxy(32,6);
    printf("MMMMMMMMMMMMMWNXK00OOOOOOOOOOOOOOOOOOOOOO00KXNWMMMMMMMMMMMMM\n");
    gotoxy(32,7);
    printf("MMMMMMMMMMWNXK0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0KXNWMMMMMMMMMM\n");
    gotoxy(32,8);
    printf("MMMMMMMMWNK0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0KNWMMMMMMMM\n");
    gotoxy(32,9);
    printf("MMMMMMWNKOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOKNWMMMMMM\n");
    gotoxy(32,10);
    printf("MMMMWNK0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0KNWMMMM\n");
    gotoxy(32,11);
    printf("MMMWX0OOOOOOOOOOOOOOOOOOOOOOOOOOO000000OOOOOOOOOOOOOOO0XWMMM\n");
    gotoxy(32,12);
    printf("MMWX0OOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOO0XWMM\n");
    gotoxy(32,13);
    printf("MWXOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOXWM\n");
    gotoxy(32,14);
    printf("WX0OOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOO0XW\n");
    gotoxy(32,15);
    printf("N0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOO0N\n");
    gotoxy(32,16);
    printf("KOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOOOK\n");
    gotoxy(32,17);
    printf("0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOOO0\n");
    gotoxy(32,18);
    printf("0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOOO0\n");
    gotoxy(32,19);
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOOOO\n");
    gotoxy(32,20);
    printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO       0OOOOOOOOOOOOOOOOOOO0\n");
    gotoxy(32,21);
    printf("0OOOOOOOOOOOOOOOOO0       OOOOOO       0OOOOOOOOOOOOOOOOOOO0\n");
    gotoxy(32,22);
    printf("KOOOOOOOOOOOOOOOOO0       OOOOOO       0OOOOOOOOOOOOOOOOOOOK\n");
    gotoxy(32,23);
    printf("X0OOOOOOOOOOOOOOOO0       OOOOOO       0OOOOOOOOOOOOOOOOOO0X\n");
    gotoxy(32,24);
    printf("WKOOOOOOOOOOOOOOOOO                    OOOOOOOOOOOOOOOOOOOKW\n");
    gotoxy(32,25);
    printf("MNKOOOOOOOOOOOOOOOO0                  0OOOOOOOOOOOOOOOOOO0NM\n");
    gotoxy(32,26);
    printf("MWN0OOOOOOOOOOOOOOOOO              0OOOOOOOOOOOOOOOOOOO0NMMM\n");
    gotoxy(32,27);
    printf("MMMNKOOOOOOOOOOOOOOOOOOO00      00OOOOOOOOOOOOOOOOOOOOOKNMMM\n");
    gotoxy(32,28);
    printf("MMMMWX0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0XWMMMM\n");
    gotoxy(32,29);
    printf("MMMMMWNKOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOKNWMMMMM\n");
    gotoxy(32,30);
    printf("MMMMMMMWXKOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0KXWMMMMMMM\n");
    gotoxy(32,31);
    printf("MMMMMMMMMWNK0OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO0KNWMMMMMMMMM\n");
    gotoxy(32,32);
    printf("MMMMMMMMMMMMWNK00OOOOOOOOOOOOOOOOOOOOOOOOOO00KNWWMMMMMMMMMMM\n");
    gotoxy(32,33);
    printf("MMMMMMMMMMMMMMMWNXXK00OOOOOOOOOOOOOOOO00KXXNWMMMMMMMMMMMMMMM\n");
    gotoxy(32,34);
    printf("MMMMMMMMMMMMMMMMMMMWWNXKK0000000000KKXNWWMMMMMMMMMMMMMMMMMMM\n");
    sleep(1);
    system("cls");

    //Bienvenida//
    gotoxy(48,2);
    printf("Bienvenido a Hubris.");
    gotoxy(40,6);
    printf("    .;dO00kxkko,      l0KKKKKKl");
    gotoxy(40,7);
    printf("    .;dO00kxkko,      l0KKKKKKl");
    gotoxy(40,8);
    printf("   'xXXXk;.;kXX0;     .,:kXXXXo");
    gotoxy(40,9);
    printf("  .oXXXXl  cKXXO,        lXXXXo");
    gotoxy(40,10);
    printf("':lOXXXXx        cllolc,.lXXXXo");
    gotoxy(40,11);
    printf("l00XXXXXK00o   kKXXK0OkkxOXXXXo.");
    gotoxy(40,12);
    printf("..,kXXXXo    lKXXXk;.. .c0XXXXo");
    gotoxy(40,13);
    printf("  .xXXXKc   ,OXXXKc     .xXXXXo ");
    gotoxy(40,14);
    printf("  .xXXXKc   :KXXX0;     .dXXXXo.");
    gotoxy(40,15);
    printf("  .xXXXKc   ,0XXXKc     .xXXXXo.  ");
    gotoxy(40,16);
    printf(".':OXXXXx,'..oXXXXk,.  .c0XXXXx;..");
    gotoxy(40,17);
    printf("oKXXXXXXXXKc .l0XXX0kxdxxOXXXXXXKl");
    gotoxy(0,27);
    printf("Programa creado por Javier Galindo.");
    gotoxy(0,28);
    printf("Todos los derechos reservados.");
    gotoxy(0,29);
    printf("Creado para: Ferroreparaciones Davi's.<\n");
    sleep(2);

    while(j == 0){
        system("cls");

    //Menu principal//
    system (" color 8F");
    gotoxy(40,1);
    printf("    .;dO00kxkko,      l0KKKKKKl");
    gotoxy(40,2);
    printf("    .;dO00kxkko,      l0KKKKKKl");
    gotoxy(40,3);
    printf("   'xXXXk;.;kXX0;     .,:kXXXXo");
    gotoxy(40,4);
    printf("  .oXXXXl  cKXXO,        lXXXXo");
    gotoxy(40,5);
    printf("':lOXXXXx        cllolc,.lXXXXo");
    gotoxy(40,6);
    printf("l00XXXXXK00o   kKXXK0OkkxOXXXXo.");
    gotoxy(40,7);
    printf("..,kXXXXo    lKXXXk;.. .c0XXXXo");
    gotoxy(40,8);
    printf("  .xXXXKc   ,OXXXKc     .xXXXXo ");
    gotoxy(40,9);
    printf("  .xXXXKc   :KXXX0;     .dXXXXo.");
    gotoxy(40,10);
    printf("  .xXXXKc   ,0XXXKc     .xXXXXo.  ");
    gotoxy(40,11);
    printf(".':OXXXXx,'..oXXXXk,.  .c0XXXXx;..");
    gotoxy(40,12);
    printf("oKXXXXXXXXKc .l0XXX0kxdxxOXXXXXXKl");
    gotoxy(40,18);
    printf("User: \t\t");
    scanf("%s", Usuario);
    gotoxy(40,19);
    printf("Password: \t");
    scanf("%s", Contra);

        if (strcmp(Contra, Contras) == 0)
        { // Compara las dos cadenas y retorna 0 si son iguales
            break;
        } else
        {
        gotoxy(50,20);
        printf("Datos incorrectos");
        getch();
        sleep(1);
        }

    }

    gotoxy(50,20);
    printf("Bienvenido!!");
}

struct Cliente {
    int id;
    char nombre_c[50], rfc_c[50], correo_c[50], celular_c[50], motor_c[50],bloque_c[50], marca_c[50], ns_c[50];
};

struct producto {
    char producto[50];
    float cantidad;
};

int menu () {
        int opcion_principal, opcion_submenu, idc = 1,buscar_id = idc;
        int num_productos = 0;
        char producto[50];
        int cantidad;
        char opcion_inv;
        struct Cliente clientes[MAX_CLIENTES];
        struct producto productos[MAX_PRODUCTOS];
    do { //Inicio primer do
        printf("----- MENU -----\n");
        printf("1. Clientes\n");
        printf("2. Inventarios\n");
        printf("3. Reparaciones\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion_principal);

        switch (opcion_principal) {
            case 1:
                do {
                    printf("----- CLIENTES -----\n");
                    printf("1. Alta de cliente\n");
                    printf("2. Informacion del cliente\n");
                    printf("0. Regresar al menu principal\n");
                    printf("Ingrese una opción: ");
                    scanf("%d", &opcion_submenu);

                    switch (opcion_submenu) {
                        case 1:
                            printf("----- ALTA DE CLIENTE -----\n");
                            printf("Nombre del cliente: \n");
                            scanf("%s", &clientes[idc].nombre_c);
                            printf("RFC: \n");
                            scanf("%s", &clientes[idc].rfc_c);
                            printf("Correo electronico: \n");
                            scanf("%s", &clientes[idc].correo_c);
                            printf("Telefono celular de contacto: \n");
                            scanf("%s", &clientes[idc].celular_c);
                            printf("Motor: \n");
                            scanf("%s",&clientes[idc].motor_c);
                            printf("Numero de Serie:\t\n#");
                            scanf("d",&clientes[idc].ns_c);
                            printf("Tipo de Bloque: \n");
                            scanf("%s", &clientes[idc].bloque_c);
                            printf("Marca:\t\n");
                            scanf("%s",&clientes[idc].marca_c);
                            getch();
                            idc++;
                            printf("GUARDAR ESTE ID UNICO EN LIBRETA CON NOMBRE\n");
                            printf("Se ha agregado un nuevo cliente con ID %d\n", idc);
                            break;
                        case 2:
                            printf("----- INFORMACION DEL CLIENTE -----");
                            printf("Ingrese el ID unico del cliente que desea buscar su informacion.");
                            scanf("%d", &buscar_id);
                            idc = buscar_id;
                            printf("Estos son los datos que tenemos del cliente: \n");
                            printf("Nombre: %s\n", clientes[idc].nombre_c);
                            printf("RFC: %s\n", clientes[idc].rfc_c);
                            printf("Correo electronico: %s\n",clientes[idc].correo_c);
                            printf("Telefono: %s", clientes[idc].celular_c);
                            printf("Motor: %s\n", clientes[idc].motor_c);
                            printf("Numero de serie:%s\n", clientes[idc].ns_c);
                            printf("Tipo de bloque: %s\n", clientes[idc].bloque_c);
                            printf("Marca: %s\n", clientes[idc].marca_c);
                            break;
                        case 0:
                            printf("----- REGRESAR AL MENU PRINCIPAL -----");
                            return 178;
                            break;

                            default:
                            printf("Opción inválida. Intente de nuevo.\n");
                            break;
                    }
                } while (opcion_submenu != 1 && opcion_submenu != 2 && opcion_submenu != 0);
                break;

            case 2:
                do {
                    strcpy(productos[num_productos].producto, "Aceite sintetico para motor");
                    productos[num_productos].cantidad = 45 ;
                    num_productos++;
                    strcpy(productos[num_productos].producto, "Bujias");
                    productos[num_productos].cantidad = 12;
                    num_productos++;
                    strcpy(productos[num_productos].producto, "Filtros de aceite");
                    productos[num_productos].cantidad = 6;
                    num_productos++;
                    strcpy(productos[num_productos].producto, "Filtros de aire");
                    productos[num_productos].cantidad = 5;
                    num_productos++;
                    strcpy(productos[num_productos].producto, "Aceite para frenos");
                    productos[num_productos].cantidad = 12;
                    num_productos++;
                    strcpy(productos[num_productos].producto, "Aceite para direccion hidraulica");
                    productos[num_productos].cantidad = 11;
                    num_productos++;
                    printf("----- INVENTARIOS -----\n");
                    printf("1. Alta de producto\n");
                    printf("2. Baja de producto\n");
                    printf("3. Existencia del producto\n");
                    printf("0. Regresar al menu principal\n");
                    printf("Ingrese una opción: ");
                    scanf("%d", &opcion_submenu);

                    switch (opcion_submenu) {
                        case 1:
                            printf("----- ALTA DE PRODUCTO -----\n");
                                do {
                                    printf("Ingrese el nombre del producto: ");
                                    scanf("%s", producto);
                                    printf("Ingrese la cantidad en inventario del producto: ");
                                    scanf("%d", &cantidad);
                                    strcpy(productos[num_productos].producto, producto);
                                    productos[num_productos].cantidad = cantidad;
                                    num_productos++;
                                    printf("¿Desea agregar otro producto? (s/n): ");
                                    scanf(" %c", &opcion_inv);
                                    } while (opcion_inv == 's' && num_productos < MAX_PRODUCTOS);
                            break;
                        case 2:
                            printf("----- BAJA DE PRODUCTO -----");

                        case 3:
                            printf("----- EXISTENCIA DEL PRODUCTO -----");
                            printf("\nLista de productos:\n");
                            int i;
                            for (i = 0; i < num_productos; i++) {
                            printf("%s - %d unidades\n", productos[i].producto, productos[i].cantidad);
                        } //Agrege este
                            break;
                        case 0:
                            printf("----- REGRESAR AL MENU PRINCIPAL -----");
                            return 178;
                            break;
                        default:
                            printf("Opción inválida. Intente de nuevo.\n");
                            break;
                    }
                } while (opcion_submenu != 1 && opcion_submenu != 2 && opcion_submenu != 3 && opcion_submenu != 0);
                break;

            case 3:
                do {
                    printf("----- REPARACIONES -----\n");
                    printf("1. Nueva reparacion\n");
                    printf("2. Actualizar reparacion\n");
                    printf("3. Finalizar reparacion\n");
                    printf("0. Regresar al menu principal\n");
                    printf("Ingrese una opción: ");
                    scanf("%d", &opcion_submenu);
                    switch (opcion_submenu) {
                        case 1:
                            printf("----- NUEVA REPARACION -----");
                            break;
                        case 2:
                            printf("----- ACTUALIZAR REPARACION -----");
                            break;
                        case 3:
                            printf("----- FINALIZAR REPARACION -----");
                            break;
                        case 0:
                            printf("----- REGRESAR AL MENU PRINCIPAL -----");
                            return 178;
                            default:
                            printf("Opción inválida. Intente de nuevo.\n");
                            break;
                    }
                } while (opcion_submenu != 1 && opcion_submenu != 2 && opcion_submenu != 3 && opcion_submenu != 0);
                break;

                default:
                printf("Opción inválida. Intente de nuevo.\n");
                break;
        }while (opcion_principal != 4);
    return 0;

    } while(1==1); //Fin primer do

}







void main(){
bienvenida();
menu();
}
