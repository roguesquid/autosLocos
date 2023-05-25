#include <iostream>
#include <string>
#include <cstdlib>
#include "ListaVehiculos.h"

using namespace std;

void menuAgregar(tVehiculoPtr *lista)
{
  system("cls"); // Limpia la pantalla
  tVehiculo temporal;

  // Imprime el encabezado del menú
  generarLogo();
  cout << "\n\n\t\t\tMENU AGREGAR VEHICULO" << endl;
  cout << "\t\t\t-------------------------" << endl;

  cout << "\n\tIngrese el nombre del vehiculo en espanol: ";
  cin >> temporal.nombreEspanol;
  cout << "\n\tIngrese el nombre del vehiculo en ingles: ";
  cin >> temporal.nombreIngles;
  cout << "\n\tIngrese el nombre del/los conductor/es: ";
  cin >> temporal.nombreConductores;
  cout << "\n\tIngrese el tipo de caucho: ";
  cin >> temporal.tipoCaucho;
  cout << "\n\tIngrese el tamaño del caucho: ";
  cin >> temporal.tamanoDelCaucho;

  agregarNodoVehiculo(lista, crearNodoVehiculo(temporal));
}

// Función para mostrar el menú de gestión de vehículos
void menuGestionDeVehiculos(tVehiculoPtr *lista)
{
  int opcion;
  bool repetir = true;

  do
  {
    system("cls"); // Limpia la pantalla

    // Imprime el encabezado del menú
    generarLogo();
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

    switch (opcion)
    {
    case 1:
      // Agregar vehiculo: implementa la lógica para agregar un vehículo
      menuAgregar(lista);
      break;

    case 2:
      // Modificar vehiculo: implementa la lógica para modificar un vehículo existente
      break;

    case 3:
      // Eliminar vehiculo: implementa la lógica para eliminar un vehículo existente
      break;

    case 4:
      // Consultar vehiculo: implementa la lógica para consultar la información de un vehículo
      break;

    case 5:
      // Listar vehiculos: implementa la lógica para mostrar una lista de vehículos
      break;

    case 0:
      repetir = false; // Termina el ciclo y sale del programa
      break;
    }
  } while (repetir);
}

int main()
{
  tVehiculoPtr listaVehiculos = NULL;
  menuGestionDeVehiculos(&listaVehiculos); // Llama a la función principal para mostrar el menú de gestión de vehículos
}