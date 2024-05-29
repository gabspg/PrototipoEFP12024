//Creado por Jose Gallardo 9959-23-106

//Incluyendo Librerias
#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <unistd.h>

//Incluyendo encabezados
#include "Bitacora.h"
#include "usuarios.h"
#include "Login.h"
#include"Entrenador.h"
#include"asignaciom_de_resultados.h"
#include"Equipos.h"
#include"deporte.h"
#include "Horarios.h"
using namespace std;

//Funciones
void menuGeneral();
void catalogos();
void reportes();
void procesos();
void seguridad();

//Variable string
string codigoPrograma="1";



int main() {
    cout << "                                              PROYECTO UMG " << endl;
    Login login; // Creación de un objeto Login

// Validación del inicio de sesión
if (login.validacion()) {
    menuGeneral(); // Si la validación es exitosa, muestra el menú principal
} else {
    cout << "Intentelo nuevamente..." << endl; // Si la validación falla, muestra un mensaje de error
}

return 0; // Finaliza el programa
}



//Funcion menu general
void menuGeneral()
{
    //Variable int
    int choice;

    do
    {
        //Limpiando pantalla
        system("cls");
        //Diseño del sistema
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION UMG     |"<< endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Catalogos" << endl;
        cout << "\t\t\t 2. Procesos" << endl;
        cout << "\t\t\t 3. Reportes" << endl;
        cout << "\t\t\t 4. Seguridad" << endl;
        cout << "\t\t\t 5. Salir del Sistema" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t|Opcion a escoger:[1/2/3/4/5]  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        //Opciones
        switch (choice)
        {
        //Opcion 1
        case 1:
            catalogos();
            break;

        //Opcion 1
        case 2:
            {
                asignaciom_de_resultados asignacion1;
                asignacion1.Menu();
               break;
            }
        //Opcion 3
        case 3:
        {



                break;
            }
        //Opcion 4
        case 4:
            {
                Bitacora bitacora;
                bitacora.mostrarBitacora();
                break;
            }

        //Opcion 5
        case 5:
            {
            //Implementacion de la bitacora
            string usuarioActual = Login::getUsuarioActual();

            // Crear una instancia de la clase Bitacora para registrar el ingreso
            Bitacora bitacora;

            // Registro del ingreso en la bitácora
            bitacora.ingresoBitacora(usuarioActual, "2600", "LGO");
            exit(0);
            }

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    //Si es 6 sale del sistema
    } while (choice != 5);
}


void catalogos()
{
    //Variable int
    int choice;

    do
    {
        //Limpiando pantalla
        system("cls");
        //Diseño del sistema de gestion
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t|   SISTEMA DE GESTION CORPORACION - CATALOGOS      |" << endl;
        cout << "\t\t\t--------------------------------------------" << endl;
        cout << "\t\t\t  1. TRABAJADOR" << endl;
        cout << "\t\t\t  2. PRODUCTO" << endl;
         cout << "\t\t\t 3. HORARIOS" << endl;
        cout << "\t\t\t  4. SEDE" << endl;
        cout << "\t\t\t  5. REGRESAR" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\t | Opcion a escoger:[1/2/3/4/5/]|" << endl;
        cout << "\t\t\t --------------------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Entrenador Entrenador1;
            Entrenador1.menu();
            break;
        }


        case 2:
        {
            //Lammada al equipoCreud
            Equipos equipos1;
            equipos1.menuFUT();
            break;}


        case 3:{
            //Lammada al HorariosCreud
            Horarios horario1;
            horario1.menuHorario();
            break;
            }
        case 4:{
            deporte deporte1;
            deporte1.menudeportes();
            }
            break;
        case 5:
            //Funcion menu general
            menuGeneral();
            break;
        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.ignore();
            cin.get();
        }
    //Si es 12 retorna al menu anterior
    }while (choice != 5);
}

