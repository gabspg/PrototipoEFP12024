#include "Horarios.h"


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

using namespace std;

//Constructor alumnos y sus parametros
Horarios::Horarios(string id, string jornada,string dia,string horario)
{
    // Asignando los valores de los parámetros a los atributos del objeto


    this->id = id;
    this->jornada = jornada;
    this->dia = dia;
    this->horario = horario;


}


//Estableciendo la id de los alumnos
string Horarios::setid(string id)
{
    this->id = id;
    return id;
}

//Obteniendo la id del alumno
string Horarios::getid()
{
    return id;
}

//Estableciendo el nombre del alumno
string Horarios::setjornada(string jornada)
{
    this->jornada = jornada;
    return jornada;
}

//Obteniendo el nombre del alumno
string Horarios::getjornada()
{
    return jornada;
}

//Estableciendo el nombre del alumno
string Horarios::setdia(string dia)
{
    this->dia = dia;
    return dia;
}

//Obteniendo el nombre del alumno
string Horarios::getdia()
{
    return dia;
}

//Funcion menu donde muestra el sistema de gestion de alumnos
void Horarios::menuHorario()
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
		cout<<"|  BIENVENIDO AL SISTEMA DE GESTION DE HORARIOS    |"<<endl;
		cout<<"+-----------------------------------------------------+"<<endl;
		cout<<"|            1. Agregar Horarios                   |"<<endl;
		cout<<"|            2. Mostrar Horarios                    |"<<endl;
		cout<<"|            3. Modificar Horarios                  |"<<endl;
		cout<<"|            4. Borrar Horarios                     |"<<endl;
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
					cout<<" -> ¿Deseas ingresar a otro horario? (S/N): ";
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
void Horarios::insertar()
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
    HorariosC horario1;

    //Estableciendo variable int dando valor de "24"
    int year = 24;
    //Generando un numero aleatorio
    int numAleatorio = (rand() % 9998) + 1;

    //Agregando un id aleatorio para cada alumno
    string idString = "1010-" + to_string(year) + "-" + to_string(numAleatorio);

    for (int i = 0; i < idString.length(); ++i) {
        horario1.id[i] = idString[i];
    }
    horario1.id[idString.length()] = '\0';

    //Mensaje generando carnet
    cout<<"       -> Generando id del Horario: " << horario1.id<<endl;
    cin.ignore();

    //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese la Jornada:  ";
    cout<<" +--------------------------------------------------+"<< endl;
    cout<<"|     MATUTINA    |   VESPERTINA  |    NOCTURNA   |"<< endl;
    cout<<"+-------------------------------------------------+"<< endl;

    cin.getline(horario1.jornada, 20);

     //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese la dia:  ";
    cout<<" +-----------------------------------------------------------------+"<< endl;
    cout<<"| Lunes | Martes | Miercoles| jueves | viernes | sabado| domingo |"<< endl;
    cout<<"+-----------------------------------------------------------------+"<< endl;

    cin.getline(horario1.dia, 15);

      //Mensaje para ingresar el nombre del alumno
    cout<<"       -> Ingrese la Hora:  ";
    cout<<" +------------------------------------------------+"<< endl;
    cout<<"| 5:00 | 6:00 | 7:00 | 8:00| 9:00 | 10:00 | 11:00|"<< endl;
    cout<<"+-------------------------------------------------+"<< endl;

    cin.getline(horario1.horario, 20);


    cout<<"+---------------------------------------------------------+"<< endl;

    //Escribiendo los datos del obteto alumno en un archivo binario llamado en modo de escritura binaria, agregando los datos al final del archivo si ya existe.
    ofstream archivo("Horarios.dat", ios::binary | ios::app);
    archivo.write(reinterpret_cast<const char*>(&horario1), sizeof(horario1));
    archivo.close();
}

void Horarios::desplegar()
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
    cout << "+                            Tabla de Detalles del Horarios                 +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //Abriendo un archivo binario llamado en modo de lectura binaria y se comprueba si la apertura fue exitosa
  //-> // ifstream archivo("ProcesoAlumnos.dat", ios::binary | ios::in);
    ifstream archivo3("Horarios.dat", ios::binary | ios::in);
  //->  //if (!archivo || !archivo3) {
    if (!archivo3){
            //Si no encuentra informacion muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion..." << endl;
        return;
    }

    // instancia de la clase Alumno llamada alumno
    HorariosC horario1;
    // instancia de la clase Procealumnos llamada procealumnos
 //->   //Procealumnos procealumnos;

    //Ciclo while para leer los datos del archivo binario  y los almacenan en un objeto alumno llamado alumno y repite este procedimiento hasta que se acaben los datos por leer
  while (archivo3.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) //archivo.read(reinterpret_cast<char*>(&procealumnos), sizeof(Procealumnos)) &&
    {

        //Se muestra los detalles del estudiante
        cout << "                        Mostrando -> ID del Horario: " << horario1.id << endl;
        cout << "                        Mostrando ->  Jornada: " << horario1.jornada << endl;
        cout << "                        Mostrando ->  Dia: " << horario1.dia << endl;
        cout << "                        Mostrando ->  Hora: " << horario1.horario << endl;



        cout << "+---------------------------------------------------------------------------------+" << endl;
    }
    archivo3.close(); //cierra el archivo

    //Mensaje al usuario
    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}

//Funcion para modificar los alumnos ya registrados
void Horarios::modificar()
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
    string idhorario;

    //Variable bool con valor false
    bool encontrado = false;

    cout << "+---------------------------------------------------------------------------------+" << endl;
    cout << "+                       Modificar Detalles del Producto                         +" << endl;
    cout << "+---------------------------------------------------------------------------------+" << endl;

    //abre un archivo binario en modo de lectura y escritura
    archivo1.open("Horarios.dat", ios::binary | ios::in | ios::out);
    //verificacion si se abre el archivo
    if (!archivo1) {
        //si no se pudo muestra el siguiente mensaje
        cout << "Error, no se encuentra informacion...";
        return;
    }
    //si se pudo abrir correctament pide la id de la persona
    cout << "Ingrese el ID del Horario que desea modificar: ";
    cin >> idhorario;

    HorariosC horario1;
    // Lee cada registro del archivo y busca el ID proporcionado por el usuario
    while (archivo1.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC))) {
        if (horario1.id == idhorario) {
            // Establece el indicador como verdadero si se encuentra el estudiante
            encontrado = true;

            //Muestra mensajes para poder ingresar los detalles para poder modificar del alumnno
            cout << "Ingrese el nuevo ID del horario: ";
            cin >> horario1.id;
            system("cls");
   cout<<" +--------------------------------------------------+"<< endl;
    cout<<"|     MATUTINA    |   VESPERTINA  |    NOCTURNA   |"<< endl;
    cout<<"+-------------------------------------------------+"<< endl;
            cout << "Ingrese la nueva jornada  : ";
            cin >> horario1.jornada;

            system("cls");
    cout<<" +-----------------------------------------------------------------+"<< endl;
    cout<<"| Lunes | Martes | Miercoles| jueves | viernes | sabado| domingo |"<< endl;
    cout<<"+-----------------------------------------------------------------+"<< endl;
    cout<<" Ingrese el nuevo dia:  ";

            system("cls");


      //Mensaje para ingresar el nombre del alumno

cout<<" +------------------------------------------------+"<< endl;
    cout<<"| 5:00 | 6:00 | 7:00 | 8:00| 9:00 | 10:00 | 11:00|"<< endl;
    cout<<"+-------------------------------------------------+"<< endl;
        cout<<"  Ingrese la nueva hora:  ";
    cin.getline(horario1.horario, 20);


            // Posiciona el puntero de escritura al inicio del registro que se está modificando
            archivo1.seekp(-static_cast<int>(sizeof(HorariosC)), ios::cur);

            // Escribe  nuevos detalles del entrenador en el archivo
            archivo1.write(reinterpret_cast<char*>(&horario1), sizeof(HorariosC));
            break;
        }
    }

    archivo1.close(); // Cierra el archivo

    //si no lo encuentra mostrara el siguiente mensaje
    if (!encontrado) {
        cout << "No se encontró un Producto con el ID proporcionado." << endl;
    }

    cout << "Presione Enter Para Continuar";
    cin.ignore();
    cin.get();
}
//funcion para borrarr a las alumnos registradas
void Horarios::borrar()
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
	string idhorario;

	//Muestra el encabezado de la tabla para eliminar un estudiante
    cout<<"+---------------------------------------------------------------------------------+"<<endl;
	cout<<"+                             Eliminar Horario                                +"<<endl;
    cout<<"+---------------------------------------------------------------------------------+"<<endl;


    // Abre el archivo binario alumnos.dat en modo de lectura
    ifstream archivo("Horarios.dat", ios::binary);

    //verifica si se abrio el archivo
	if(!archivo)
	{
        //si no se abrio imprime el siguiente mensaje
		cout<<"Error, no se encuentra informacion...";
		return;
	}
    // Crea un nuevo archivo binario en modo de escritura
	ofstream archivo2("Horarios2.dat", ios::binary);

	HorariosC horario1;

    //Muestra el mensaje para poder borrar el alumno
    cout<<"-> Ingrese el ID del Horario que desea eliminar: ";
    cin>>idhorario;

    // Crea un nuevo archivo binario en modo de escritura
    bool resta = false;

        // Lee cada registro del archivo y busca el usuario proporcionado por el usuario
		while(archivo.read(reinterpret_cast<char*>(&horario1), sizeof(HorariosC)))
		{
		    // Si el nombre del usuario no coincide con el proporcionado, se escribe en el nuevo archivo
			if(horario1.id != idhorario)
			{
				archivo2.write(reinterpret_cast<const char*>(&horario1), sizeof(HorariosC));
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
		remove("Horarios.dat");

        //y renombra el Alumnos2.dat a alumnos.dat
		rename("Horarios2.dat","horarios.dat");

		if (resta)
        {
        //Si se encuentra el alumno muestra el mensaje
        cout << "horario eliminado con exito." << endl;
        }
        else
        {
        //Si no se encuentra el alumno muestra el mensaje
        cout << "No se a podido encontrar el codigo del horario" << endl;
        }
}
//----------------------------------------------------------------------------------------------------------------------------------------------
