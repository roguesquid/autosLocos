#include <iostream>
#include <string>
#include <cstdlib>
#include "ListaVehiculos.h"

using namespace std;

/**
 * Agrega un nuevo vehículo a la lista de vehículos.
 *
 * @param lista: Puntero a un puntero al inicio de la lista de vehículos.
 */
void menuAgregar(tVehiculoPtr *lista)
{
  tVehiculo temporal;
  bool repetir = true;

  cin.ignore();
  while (repetir)
  {
    system("cls"); // Limpia la pantalla
    // Imprime el encabezado del menú
    generarLogo();
    cout << "\n\n\t\t\tMENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t-------------------------" << endl;

    cout << "\n\tIngrese el nombre del vehiculo en espanol: ";
    getline(cin, temporal.nombreEspanol);
    cout << "\n\tIngrese el nombre del vehiculo en ingles: ";
    getline(cin, temporal.nombreIngles);
    cout << "\n\tIngrese el nombre del/los conductor/es: ";
    getline(cin, temporal.nombreConductores);
    cout << "\n\tIngrese el tipo de caucho: ";
    getline(cin, temporal.tipoCaucho);
    cout << "\n\tIngrese el tamano del caucho: ";
    getline(cin, temporal.tamanoDelCaucho);

    // validacion de los datos ingresados
    bool datosValidos = !existeNombre(*lista, temporal.nombreEspanol);
    if (datosValidos)
    {
      repetir = false;
    }
    else
    {
      cout << "\n\tLos Datos ingresados son invalidos, ingreselos nuevamente" << endl;
      cout << "\tPresione Enter para continuar...";
      cin.get();
    }
  }

  agregarNodoVehiculo(lista, crearNodoVehiculo(temporal));

  // Informacion del vehiculo
  system("cls");
  cout << "\n\n\t\t\tINFORMACION DEL VEHICULO" << endl;
  cout << "\t\t\t-------------------------" << endl;
  mostrarVehiculo(*lista, *lista);
  cout << "\tPresione Enter para continuar...";
  cin.get();
}

/*
void menuModificar(tVehiculoPtr lista)
{
  string nombre;
  bool repetir = true;

  cin.ignore();
  while (repetir)
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t\t\tMENU MODIFICAR VEHICULO" << endl;
    cout << "\t\t\t-------------------------" << endl;

    cout << "\n\tIngrese el nombre del vehiculo a modificar: ";
    getline(cin, nombre);

    if (existeNombre(lista, nombre))
    {
      repetir = false;
    }
    else
    {
      cout << "\nVehiculo no encontrado" << endl;
      cout << "Presione Enter para continuar...";
      cin.get();
    }

  }
}*/

/**
 * Elimina un vehículo de la lista enlazada.
 * Muestra el vehiculo luego de ser eliminado.
 *
 * @param lista Puntero a la lista enlazada de vehículos.
 */
void menuEliminarVehiculo(tVehiculoPtr *lista)
{
  string nombre;
  bool repetir = true;
  cin.ignore();

  while (repetir)
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t\t\tMENU ELIMINAR VEHICULO" << endl;
    cout << "\t\t\t-------------------------" << endl;

    cout << "\n\tIngrese el nombre del vehiculo a eliminar: ";
    getline(cin, nombre);

    if (existeNombre(*lista, nombre))
    {
      repetir = false;
    }
    else
    {
      cout << "\n\tVehiculo no encontrado" << endl;
      cout << "\tPresione Enter para continuar...";
      cin.get();
    }
  }

  // Elimina el vehiculo
  tVehiculoPtr nodoAEliminar = buscarVehiculo(*lista, nombre);
  tVehiculo aux = *nodoAEliminar;             // guardo en una variable estatica el nodo que voy a eliminar
  eliminarNodoVehiculo(lista, nodoAEliminar); // elimino el vehiculo

  system("cls"); // limpio la pantalla
  generarLogo(); // genero el logo
  cout << "\n\n\tVehiculo eliminado con exito" << endl;
  mostrarVehiculo(*lista, &aux); // muestro el vehiculo eliminado
  cout << "\t\nPresione Enter para continuar...";
  cin.get();
}

/**
 * Muestra en pantalla la lista de vehículos.
 *
 * @param lista: Puntero a la lista de vehículos.
 */
void menuListar(tVehiculoPtr lista)
{
  system("cls"); // Limpia la pantalla
  generarLogo(); // Muestra el logo del programa
  cout << "\n\n\t\t\t\tLISTAR VEHICULOS" << endl;
  cout << "\t\t\t-------------------------" << endl;
  cout << "\n\n";
  listarVehiculos(lista); // Llama a la función listarVehiculos para mostrar la lista de vehículos
}

/**
 * Muestra el menú de gestión de vehículos y permite al usuario realizar operaciones.
 *
 * @param lista: Puntero a la lista de vehículos.
 */
void menuGestionDeVehiculos(tVehiculoPtr *lista)
{
  string opcion;
  bool repetir = true;

  do
  {
    system("cls"); // Limpia la pantalla
    generarLogo(); // Muestra el logo del programa
    cout << "\n\n\t\t\tMENU GESTION DE VEHICULOS" << endl;
    cout << "\t\t\t-------------------------" << endl;
    cout << "\n\t1. Agregar vehiculo" << endl;
    cout << "\t2. Modificar vehiculo" << endl;
    cout << "\t3. Eliminar vehiculo" << endl;
    cout << "\t4. Consultar vehiculo" << endl;
    cout << "\t5. Listar vehiculos" << endl;
    cout << "\t0. Salir" << endl;

    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    // Implemento un if/else ya que el switch no puede comparar strings
    if (opcion == "1")
    {
      // Agregar vehiculo: implementa la lógica para agregar un vehículo
      menuAgregar(lista);
    }
    else if (opcion == "2")
    {
      // Modificar vehiculo: implementa la lógica para modificar un vehículo existente
      // menuModificar(*lista);
    }
    else if (opcion == "3")
    {
      // Eliminar vehiculo: implementa la lógica para eliminar un vehículo existente
      menuEliminarVehiculo(lista);
    }
    else if (opcion == "4")
    {
      // Consultar vehiculo: implementa la lógica para consultar la información de un vehículo
    }
    else if (opcion == "5")
    {
      // Listar vehiculos: implementa la lógica para mostrar una lista de vehículos
      menuListar(*lista);
    }
    else if (opcion == "0")
    {
      repetir = false; // Termina el ciclo y sale del programa
    }
  } while (repetir);
}

int main()
{
  tVehiculoPtr listaVehiculos = NULL;
  menuGestionDeVehiculos(&listaVehiculos); // Llama a la función principal para mostrar el menú de gestión de vehículos
}