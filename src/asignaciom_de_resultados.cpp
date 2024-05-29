#include "asignaciom_de_resultados.h"
#include "Entrenador.h"
#include "Equipos.h"
#include "login.h"
#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include <random>
#include <cstdlib>
#include <ctime>
#include<iomanip>
//Implementación de Bitácora realizado por: Pablo Romeo Palencia Rosales 9959-23-736
#include "Bitacora.h"
#include"Horarios.h"
#include"deporte.h"

using namespace std;
string users;


void asignaciom_de_resultados::Menu()
{//Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "4500", "ADR"); // Parámetros
        int opcion;
        char  x;
        do
        {
        	system("cls");

    cout<<"\t\t\t+------------------------------------------+"<<endl;
    cout<<"\t\t\t|      BIENVENIDO AL MENU DE LA CORPORACION|"<<endl;
    cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|1. Asignacion De resultados               |"<<endl;
	cout<<"\t\t\t|2. Imprimir Acta                          |"<<endl;
	cout<<"\t\t\t|3. regresar al menu anterior              |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4]                |"<<endl;
	cout<<"\t\t\t+------------------------------------------+"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>opcion;

    switch(opcion){
    case 1:

         {
          asignarse_resultado();
            //Realiza el proceso de asignar maestro a curso y se registra en la bitacora
            bitacora.ingresoBitacora(usuarioActual,"4002","ASG"); //ASG = Asignación de resultados
            //mandamos a auditoria un ingreso a la bitacora que registra el usuario que realiza dicha accion, el codigo de proceso y la accion que hace
            break;
        }


    case 2:
        {
            actas();
            //Realiza el proceso de imprimir las actas y luego se registra en la bitacora
           bitacora.ingresoBitacora(usuarioActual,"4002","DAC"); //DAC = Despliega Actas
            //mandamos al usuario, el codigo del proceso/accion y 3 letras que resumen la accion
            break;

        }
    case 3:

        {

            //Realiza el proceso de imprimir el acta deseada y luego se registra en la bitacora
           bitacora.ingresoBitacora(usuarioActual,"4002","REA");; //RAC = Read Acta
            //mandamos usuario, codigo de proceso y 3 letras que resumen la accion/proceso realizado
            return;
        }
        default:
		cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        break;
        }
        }while(opcion!= 3);
    }

void asignaciom_de_resultados::asignarse_resultado()
 {
     system("cls");
    char res='S'; //variable que controla la validacion: Pablo Palencia 9959-23-736

//Proceso asignación maestro a curso realizado por Kathia Contreras 9959-23-8246

int num=1;
Asignacion Asigna;



/* **********   DESPLIEGUE Deportes.DAT   ********** */
    cout<<"----------------- Sedes Existentes---------------------"<<endl;
    ifstream archivo11("Deportes.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo11) {
        cout << "No hay Producto registradas." << endl;
        return;
    }
    Deporte deporte1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo11.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) {

        cout << num<< ". " << deporte1.id <<"-|- "<<deporte1.nombre<<endl;

        num++;
    }
    archivo11.close(); // Cerrar el archivo

do
{
    string ideporte;
    cout<<"ingrese codigo de la sede : ";
    cin >> ideporte;
    fstream archivo25("Deportes.dat", ios::binary | ios::in | ios::out);
    if (!archivo25) {
        cout << "No hay sede registrados." << endl;
        return;
    }
    Deporte deporte1;
    bool encontrada = false;
    while (archivo25.read(reinterpret_cast<char*>(&deporte1), sizeof(Deporte))) {
        if (deporte1.id == ideporte) {
            archivo25.seekp(-static_cast<int>(sizeof(Deporte)), ios::cur);
            strcpy(Asigna.id_deporte,(ideporte).c_str());
             strcpy(Asigna.nombre_deporte,(deporte1.nombre));
            cin.ignore();
            encontrada = true;
             res='N';
            break;
        }
    }
    archivo25.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
            system("cls");


//------------------------------------------------------------------------------------------------
    string idequipo;

/* **********   DESPLIEGUE EQUIPOS.DAT   ********** */
    cout<<"---------------- Productos Existentes---------------------"<<endl;
    ifstream archivo55("Equipos.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo55) {
        cout << "No hay productos registradas." << endl;
        return;
    }
    EquiposC equipoa;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo55.read(reinterpret_cast<char*>(&equipoa), sizeof(EquiposC))) {

        cout << num<< ". " << equipoa.id <<"-|- "<<equipoa.nombre<<endl;

        num++;
    }
    archivo55.close(); // Cerrar el archivo

do
{
    cout<<"ingrese codigo del producto 1: ";
    cin >> idequipo;
    fstream archivo15("Equipos.dat", ios::binary | ios::in | ios::out);
    if (!archivo15) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    EquiposC equipo;
    bool encontrada = false;
    while (archivo15.read(reinterpret_cast<char*>(&equipo), sizeof(EquiposC))) {
        if (equipo.id == idequipo) {
            archivo15.seekp(-static_cast<int>(sizeof(EquiposC)), ios::cur);
            strcpy(Asigna.codigo_equipo,(idequipo).c_str());
             strcpy(Asigna.nombre_equipo,(equipo.nombre));
            cin.ignore();
            encontrada = true;
             res='N';
            break;
        }
    }
    archivo15.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
            system("cls");

 // Inicializar el generador de números aleatorios con una semilla
    srand(time(0)); // Establece la semilla basada en el tiempo actual
    int numero = rand() % 9000 + 1000; // Genera un número aleatorio
    // Generar un número aleatorio para el campo acta
    Asigna.acta = numero;
    //-----------------------------------------------------------------------------------------------------------------------------


/* **********   DESPLIEGUE productos.DAT   ********** */
    cout<<"---------------- Productos Existentes---------------------"<<endl;
    ifstream archivo7("Entrenadores.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo7) {
        cout << "No hay productos registradas." << endl;
        return;
    }
    EntrenadorC entrenador1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo7.read(reinterpret_cast<char*>(&entrenador1), sizeof(EntrenadorC))) {

        cout << num<< ". " << entrenador1.id <<"-|- "<<entrenador1.nombre<<"-|-"<<entrenador1.Apellido<< endl;

        num++;
    }
    archivo7.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string identre="";
cout <<"ingrese el ID del trabajador que vendio el producto :";
    cin >> identre;
    fstream archivo70("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo70) {
        cout << "No hay trabajdor registradas." << endl;
        return;
    }
   EntrenadorC entrenador1;
    bool encontrada = false;
    while (archivo70.read(reinterpret_cast<char*>(&entrenador1), sizeof(EntrenadorC))) {
        if (entrenador1.id == identre) {
            archivo70.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);
            strcpy(Asigna.id_entrenador,(identre).c_str());
             strcpy(Asigna.nombre_entrenador,(entrenador1.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo70.close();
    if (!encontrada) {
        cout << "No se encontro la sede registrada, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------


/* **********   DESPLIEGUE productos.DAT   ********** */
    cout<<"---------------- productos existentes---------------------"<<endl;
    ifstream archivo74("Equipos.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo74) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    EquiposC equipo2;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo74.read(reinterpret_cast<char*>(&equipo2), sizeof(EquiposC))) {

        cout << num<< ". " << equipo2.id <<"-|- "<<equipo2.nombre<<endl;

        num++;
    }
    archivo74.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;


do
{ //repite----------------------------------------------------------------------------------PR
string idequipo2;
    cout<<"ingrese codigo de producto 2: ";
    cin >> idequipo2;
    fstream archivo87("Equipos.dat", ios::binary | ios::in | ios::out);
    if (!archivo87) {
        cout << "No hay productos registrados." << endl;
        return;
    }
    EquiposC equipo2;
    bool encontrada = false;
    while (archivo87.read(reinterpret_cast<char*>(&equipo2), sizeof(EquiposC))) {
        if (equipo2.id == idequipo2) {
            archivo87.seekp(-static_cast<int>(sizeof(EquiposC)), ios::cur);
            strcpy(Asigna.codigo_equipo2,(idequipo2).c_str());
             strcpy(Asigna.nombre_equipo2,(equipo2.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo87.close();
    if (!encontrada) {
        cout << "No se encontro un producto con el ID proporcionado, intente de nuevo" << endl;
     res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");

//--------------------------------------------------------------------------------------------------------------

/* **********   DESPLIEGUE Entrenadores.DAT   ********** */
    cout<<"---------------- trabajadores existentes---------------------"<<endl;
    ifstream archivo54("Entrenadores.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo54) {
        cout << "No hay trabajadores registrados." << endl;
        return;
    }
    EntrenadorC entrenador2;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo54.read(reinterpret_cast<char*>(&entrenador2), sizeof(EntrenadorC))) {

        cout << num<< ". " << entrenador2.id <<"-|- "<<entrenador2.nombre<<"-|-"<<entrenador2.Apellido<< endl;

        num++;
    }
    archivo54.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string identre2="";
cout <<"ingrese el ide del trabajador que atendio:";
    cin >> identre2;
    fstream archivo10("Entrenadores.dat", ios::binary | ios::in | ios::out);
    if (!archivo10) {
        cout << "No hay trabajador 2 registradas." << endl;
        return;
    }
   EntrenadorC entrenador2;
    bool encontrada = false;
    while (archivo10.read(reinterpret_cast<char*>(&entrenador2), sizeof(EntrenadorC))) {
        if (entrenador2.id == identre2) {
            archivo10.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);
            strcpy(Asigna.id_entrenador2,(identre2).c_str());
             strcpy(Asigna.nombre_entrenador2,(entrenador2.nombre));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo10.close();
    if (!encontrada) {
        cout << "No se encontro la trabajadores registrados, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------

/* **********   DESPLIEGUE HORARIOS.DAT   ********** */
    cout<<"---------------- Horarios existentes---------------------"<<endl;
    ifstream archivo77("horarios.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo77) {
        cout << "No hay horarios registradas." << endl;
        return;
    }
    HorariosC horario1;
        num=1;

    // Recorrer el archivo y mostrar los datos de cada aula
    while (archivo77.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {

        cout << num<< ". " << horario1.id <<"-|- "<<horario1.jornada<<"-|-"<<horario1.dia<<"-1-"<<horario1.horario <<endl;

        num++;
    }
    archivo77.close(); // Cerrar el archivo


cout << "------------------------------------------------" << endl;
do
{ //repite----------------------------------------------------------------------------------PR
string idhorario="";
cout <<"ingrese el ID del horario de trabajo :";
    cin >> idhorario;
    fstream archivo78("horarios.dat", ios::binary | ios::in | ios::out);
    if (!archivo78) {
        cout << "No hay Horarios registradas." << endl;
        return;
    }
   HorariosC horario1;
    bool encontrada = false;
    while (archivo78.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {
        if (horario1.id == idhorario) {
            archivo78.seekp(-static_cast<int>(sizeof(HorariosC)), ios::cur);
            strcpy(Asigna.id_horario,(idhorario).c_str());
             strcpy(Asigna.jornada,(horario1.jornada));
              strcpy(Asigna.dia,(horario1.dia));
               strcpy(Asigna.horario,(horario1.horario));
            cin.ignore();
            encontrada = true;
            res='N';
            break;
        }
    }
    archivo78.close();
    if (!encontrada) {
        cout << "No se encontro el horario registrado, intente de nuevo..." << endl;
        res='S';
        system("pause");
    }
    }while(res=='S');
system("cls");
//--------------------------------------------------------------------------------------------------------------

    cout<<"Numero de Acta: " <<Asigna.acta<<endl;
    cin.ignore();
    system("pause");


    ofstream archivo8("asignaciones.dat", ios::binary | ios::app);
    archivo8.write(reinterpret_cast<const char*>(&Asigna), sizeof(Asignacion));
    archivo8.close();
    cout << "Asignacion ingresada exitosamente!" << endl;
    cout << "------------------------------------------------" << endl;

    // Mostrar el número de acta


         system("cls");


}


void asignaciom_de_resultados::actas()
{
    // ACTAS HECHO POR KATHIA CONTRERAS 9959-23-8246
    system("cls");
    cout << "------------------ ASIGNACIONES TECNOLOGICAS --------------------" << endl << endl;

    // Pedir al usuario que ingrese el número de acta
    int numeroActa;
    cout << "Ingrese el numero de acta: ";
    cin >> numeroActa;

    // Abrir el archivo de aulas en modo lectura binaria
    ifstream archivo("asignaciones.dat", ios::binary);
    // Verificar si el archivo se abrió correctamente
    if (!archivo) {
        cout << "No hay asignaciones registradas." << endl;
        return;
    }

    // Declarar una variable para el aula
    Asignacion asign1;
    bool encontrado = false;
    // Recorrer el archivo y mostrar los datos del acta correspondiente
    while (archivo.read(reinterpret_cast<char*>(&asign1), sizeof(Asignacion))) {
        if (asign1.acta == numeroActa) {
            cout << "NO. Acta: " << asign1.acta << endl;
            cout << "DEPORTE: " << asign1.nombre_deporte << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "|    " << "Codigo de producto:   " << asign1.codigo_equipo << endl;
            cout << "|    " << "Nombre del producto:   " << asign1.nombre_equipo << endl;
            cout << "|    " << "codigo del trabajdor que atendio:   " << asign1.id_entrenador << endl;
            cout << "|    " << "nombre del trabajador que atendio:   " << asign1.nombre_entrenador << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "|" << "Codigo de producto:   " << asign1.codigo_equipo2 << endl;
            cout << "|" << "Nombre de producto 2:   " << asign1.nombre_equipo2 << endl;
            cout << "|" << "codigo del trabajador que atendio:   " << asign1.id_entrenador2 << endl;
            cout << "|" << "nombre del trabajador que atendio:   " << asign1.nombre_entrenador2 << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "ID Horario:   " << asign1.id_horario << endl;
            cout << "Jornada :   " << asign1.jornada << endl;
            cout << "Dia :   " << asign1.dia << endl;
            cout << "Hora :   " << asign1.horario << endl;
            cout << "--------------------------------------------------------------------------------------" << endl;
            cout << "************************************************************************************************" << endl;
            encontrado = true;
            break;  // Salir del bucle después de encontrar el acta
        }
    }

    if (!encontrado) {
        cout << "No se encontro el acta con el numero ingresado." << endl;
    }

    archivo.close();
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}



