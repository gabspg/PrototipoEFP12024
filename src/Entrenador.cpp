
//Incluyendo las librerias a utilizar
#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<string>

//Incluyendo el encabezado de bitacora
#include "Bitacora.h"
#include "Login.h"
#include "Entrenador.h"

using namespace std;


//Constructor alumnos y sus parametros
Entrenador::Entrenador(string id,string nombre,string nombre2, string Apellido,string Apellido2,string fechadenacimiento)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->id = id;
    this->nombre = nombre;
   this->nombre2=nombre2;
   this->Apellido=Apellido;
   this->Apellido2=Apellido2;
   this->fechadenacimiento=fechadenacimiento;

}


//Estableciendo la id de los alumnos
string Entrenador::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del alumno
string Entrenador::getid()
{
    return id;
}

//Estableciendo el nombre del alumno
string Entrenador::setnombre(string nombre)
{
    this->nombre = nombre;
    return nombre;
}

//Obteniendo el nombre del alumno
string Entrenador::getnombre()
{
    return nombre;
}
//Estableciendo el nombre del alumno
string Entrenador::setnombre2(string nombre2)
{
    this->nombre2 = nombre2;
    return nombre2;
}

//Obteniendo el nombre del alumno
string Entrenador::getnombre2()
{
    return nombre2;
}

//Estableciendo el telefono del alumno
string Entrenador::setApellido(string Apellido)
{
    this->Apellido = Apellido;
    return Apellido;
}

//Obteniendo el telefono del alumno
string Entrenador::getApellido()
{
    return Apellido;
}

//Estableciendo el telefono del alumno
string Entrenador::setApellido2(string Apellido2)
{
    this->Apellido2 = Apellido2;
    return Apellido2;
}

//Obteniendo el telefono del alumno
string Entrenador::getApellido2()
{
    return Apellido2;
}
//Estableciendo la direccion del alumno
string Entrenador::setFechanaci(string fechadenacimiento)
{
    this->fechadenacimiento= fechadenacimiento;
    return fechadenacimiento;
}


//Obteniendo la direccion del alumno
string Entrenador::getFechanaci()
{
    return fechadenacimiento;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void Entrenador::menu()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2200", "ALM"); // Parámetros

    //Definiendo Variable int
    int opcion;
    //Definiendo Variable char
	char continuar;

	do
    {
        //Limpiando pantalla
		system("cls");

		//Se muestra el diseño del sistema de gestion de alumnos
		cout<<"+-----------------------------------------------+"<<endl;
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE TRABAJADORES   |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Trabajador                    |"<<endl;
		cout<<"|            2. Mostrar Trabajador                    |"<<endl;
		cout<<"|            3. Modificar Trabajador                  |"<<endl;
		cout<<"|            4. Borrar Trabajador                     |"<<endl;
		cout<<"|            5. Regresar al menu                      |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|        Ingrese su opcion [1/2/3/4/5/]              |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cin>>opcion;

        //Permitiendo que el usuario eliga una opcion
		switch(opcion)
		{
		    //Opcion 1
			case 1:
				do
				{
				    //Funcion para insertar un alumno
					insertar();
					//Luego de ingresar un alumno mostrara el mensaje
					cout<<" -> ¿Deseas ingresar a otro trabajador? (S/N): ";
					cin>>continuar;

                //Si la respuesta es s o S, insertara otro estudiante
				}while(continuar=='S' || continuar=='s');
				break;

            //Opcion 2
			case 2:
			    //Funcion para poder desplegar los alumnos registrados
                desplegar(  );
				break;

            //Opcion 3
			case 3:
			    //Funcion para modificar un alumno registrado
                modificar();
				break;

            //Opcion 4
			case 4:
			    //Funcion para borrar un alumno registrado

                borrar();
                break;

            case 5:
				break;
				//Si no elige una de las 5 opciones, mostrara el siguiente mensaje
			default:
				cout<<"ERROR, OPCION NO VALIDA, INTENTELO DE NUEVO PORFAVOR";
		}
		getch();
    //Indica que si el usuario elige 6 finaliza el ciclo
    }while(opcion != 5);
}

//Funcion para insertar un estudiando
void Entrenador::insertar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2201", "ALMI"); // Parámetros


    //Limpiando pantalla
    system("cls");

    //Encabezado del diseño insertar estudiante
    cout<<"+---------------------------------------------------------+"<< endl;
    cout<<"|                Agregar detalles del Trabajador          |"<< endl;
    cout<<"+---------------------------------------------------------+"<< endl;

    //Inicializando un generador de numeros aleatorios
    srand(time(NULL));

    //Constructor
    EntrenadorC entrenador;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "7575-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        entrenador.id[i] = idString[i];
    }
    entrenador.id[idString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Generando carnet del Trabajador: " << entrenador.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese el primer nombre del Trabajador:  ";
    cin.getline(entrenador.nombre, 50);

//Mensaje para ingresar el segundo nombre
    cout<<"       -> Ingrese el segundo nombre del Trabajador:  ";
    cin.getline(entrenador.nombre2, 50);

//Mensaje para ingresar el apellido
    cout<<"       -> Ingrese el primer Apellido del Trabajador:  ";
    cin.getline(entrenador.Apellido, 50);
    //Mensaje para ingresar el segundo apellido
    cout<<"       -> Ingrese el segundo Apellido del Trabajador:  ";
    cin.getline(entrenador.Apellido2, 50);
    //Mensaje para ingresar fecha de naciminto entrenador
    cout<<"       -> Ingrese la fecha de nacimiento del Trabajador (DD/MM/AA): ";
    cin.getline(entrenador.fechadenacimiento, 50);

    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Entrenadores.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&entrenador), sizeof(entrenador));
    archivo.close();
}

void Entrenador::desplegar()
{
    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2202", "ALMD"); // Parámetros

    //Limpiando pantalla
    system("cls");


    //Mostrando el encabezado de la tabla de detalles del estudiante
    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                            Tabla de Detalles del Trabajador                   +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Abriendo un archivo binario llamado en modo de lectura binaria y se comprueba si la apertura fue exitosa
  //-> // ifstream archivo("ProcesoAlumnos.dat", ios::binary | ios::in);
    ifstream archivo3("Entrenadores.dat", ios::binary | ios::in);
  //->  //if (!archivo || !archivo3) {
    if (!archivo3){
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }

    // instancia de la clase Alumno llamada alumno
    EntrenadorC entrenador;
    // instancia de la clase Procealumnos llamada procealumnos
 //->   //Procealumnos procealumnos;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
  while (archivo3.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC))) //archivo.read(reinterpret_cast<char*>(&procealumnos), sizeof(Procealumnos)) &&
    {

        //Se muestra los detalles del estudiante
        cout << "                        Mostrando -> ID del Trabajador: " << entrenador.id << endl;
        cout << "                        Mostrando -> 1r Nombre del Trabajador: " << entrenador.nombre << endl;
        cout << "                        Mostrando -> 2d0 Nombre del Trabajador: " << entrenador.nombre2 << endl;
        //cout << "                        Mostrando -> Estatus del estudiante (solvente=1 | pendiente=0): " << procealumnos.solvente << endl;
         cout << "                        Mostrando -> 1r Apellido del Trabajador: " << entrenador.Apellido << endl;
        cout << "                        Mostrando -> 2d0 Apellido del Trabajador: " << entrenador.Apellido2 << endl;
        cout << "                        Mostrando -> fecha de nacimiento del Trabajador: " << entrenador.fechadenacimiento << endl;

        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los alumnos ya registrados
void Entrenador::modificar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2203", "ALMM"); // Parámetros


    //Limpiando pantalla
	system("cls");
	//Declarando variables tipo fstream y string
    fstream archivo1;
    string idPersona;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del Trabajador                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo1.open("Entrenadores.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo1) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID de la persona que desea modificar: ";
    cin >> idPersona;

    EntrenadorC entrenador;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario
    while (archivo1.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC))) {
        if (entrenador.id == idPersona) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo ID del Trabajador: ";
            cin >> entrenador.id;
            cout << "Ingrese el nuevo 1re nombre del Trabajador: ";
            cin >> entrenador.nombre;
            cout << "Ingrese el nuevo 2do nombre del Trabajador: ";
            cin >> entrenador.nombre2;
            cout << "Ingrese el nuevo 1re Apellido del Trabajador: ";
            cin >> entrenador.Apellido;
            cout << "Ingrese el nuevo 2do Apellido del Trabajador: ";
            cin >> entrenador.Apellido2;
            cout << "Ingrese la nueva Fecha de nacimiento (dd/mm/aaaa) : ";
            cin >> entrenador.fechadenacimiento;



            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo1.seekp(-static_cast<int>(sizeof(EntrenadorC)), ios::cur);

            // Escribe  nuevos detalles del entrenador en el archivo
            archivo1.write(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un Trabajador con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//funcion para borrarr a las alumnos registradas
void Entrenador::borrar()
{

    //Implementacion de la bitacora
    // Obtener el usuario actual que ha iniciado sesión
    string usuarioActual = Login::getUsuarioActual();

    // Crear una instancia de la clase Bitacora para registrar el ingreso
    Bitacora bitacora;

    // Registro del ingreso en la bitácora
    bitacora.ingresoBitacora(usuarioActual, "2204", "ALMB"); // Parámetros


    //Limpia pantalla
	system("cls");
	//declara una variable string
	string idPersona;

	//Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Trabajador                                 +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Entrenadores.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Entrenadores2.dat", ios::binary);

	EntrenadorC entrenador;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID de la persona que desea eliminar: ";
    cin>>idPersona;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&entrenador), sizeof(EntrenadorC)))
		{
		    // Si el nombre del usuario no coincide con el proporcionado, se escribe en el nuevo archivo
			if(entrenador.id != idPersona)
			{
				archivo2.write(reinterpret_cast<const char*>(&entrenador), sizeof(EntrenadorC));
			}
			else
			{
			    resta = true;
			}

		}
        //cierra ambos archivos
		archivo.close();
		archivo2.close();

        //remueve el Alumnos.dat
		remove("Entrenadores.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Entrenadores2.dat","Entrenadores.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "Trabajador eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del Trabajador" << endl;
        }
}

