#include <iostream>
#include <string>
#include <cstdlib>
#include "ListaCarreras.h"

using namespace std;

/**
 * Verifica si una cadena de caracteres representa un número entero de máximo dos dígitos.
 *
 * @param cadena La cadena de caracteres a verificar.
 * @return true si la cadena representa un número entero de máximo dos dígitos, false en caso contrario.
 */
bool caracterNumericoDeMaxDosDigitos(const string &cadena)
{
  regex regex("^\\d{0,2}$");
  return regex_match(cadena, regex);
}

void carrera(tCarrilesPtr carriles, int numeroCarriles)
{
  cin.ignore();
  system("cls");
  generarLogo();
  cout << "\n\n\t\t\t\tCARRERA!!!\n";
  cout << "\t\t\t\t----------\n\n\n\n";
  cout << "\n\n\t\tPresione cualquier tecla para iniciar la carrera...\n";
  cin.get();
  imprimirCarriles(carriles);
  recorrerCarriles(carriles);
}

/**
 * Asigna aleatoriamente un vehículo único a cada carril en la multilista de carriles.
 *
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @param numeroCarriles Número total de carriles en la multilista.
 */
void vehiculosAleatorios(tCarrilesPtr carriles, int numeroCarriles)
{
  cin.ignore();
  tVehiculoPtr listaNoAsignados = NULL;
  leerListaDeArchivo(&listaNoAsignados);

  for (int i = 1; i <= numeroCarriles; i++)
  {
    int cantidadDeVehiculosNoAsignados = contarNodos(listaNoAsignados);
    int indiceAleatorio = (rand() % cantidadDeVehiculosNoAsignados) + 1;
    tVehiculoPtr carroAAsignar = obtenerNodoPorPosicion(listaNoAsignados, indiceAleatorio);

    tCarrilesPtr carrilASerAsignado = recorrerMultilistaHastaPosicion(carriles, i);
    carrilASerAsignado->vehiculoAsignado = crearNodoVehiculo(*carroAAsignar);
    carrilASerAsignado->aba->simbolo = carrilASerAsignado->vehiculoAsignado->simbolo;
    eliminarNodoVehiculo(&listaNoAsignados, carroAAsignar);
  }

  system("cls");
  generarLogo();
  cout << "\n\n\t\t\tMENU SELECCION DE VEHICULOS\n";
  cout << "\t\t\t---------------------------\n\n";
  cout << "\t\tVEHICULOS ASIGNADOS CORRECTAMENTE!\n\n";
  esperar();

  carrera(carriles, numeroCarriles);
}

/**
 * Verifica la opción seleccionada por el usuario para asignar un vehículo al carril.
 * @param opcion La opción seleccionada por el usuario en formato de cadena.
 * @param vehiculosNoAsignados El número de vehículos no asignados disponibles.
 * @return `true` si la opción es válida, `false` en caso contrario.
 */
bool verificarOpcionVehiculoSeleccionado(string opcion, int vehiculosNoAsignados)
{
  if (!caracterNumericoDeMaxDosDigitos(opcion))
  {
    return false;
  }
  int opcionInt = stoi(opcion);
  if ((opcionInt < 1) || (opcionInt > vehiculosNoAsignados))
  {
    return false;
  }
  return true;
}

/**
 * Muestra el menú de selección de vehículos y asigna los vehículos seleccionados a los carriles correspondientes.
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @param listaVehiculos Puntero al primer nodo de la lista de vehículos.
 * @param numeroCarriles El número total de carriles.
 */
void menuSeleccionDeVehiculos(tCarrilesPtr carriles, int numeroCarriles)
{
  tVehiculoPtr listaNoAsignados = NULL;
  leerListaDeArchivo(&listaNoAsignados);
  for (int i = 1; i <= numeroCarriles; i++)
  {
    bool repetir = true;
    string opcion;
    while (repetir)
    {
      system("cls");
      generarLogo();
      cout << "\n\n\t\t\tMENU SELECCION DE VEHICULOS\n";
      cout << "\t\t\t---------------------------\n\n";
      listarNombres(listaNoAsignados);
      int vehiculosNoAsignados = contarNodos(listaNoAsignados);
      cout << "\n\tSeleccione un vehiculo a asignar al carril " << i << ": ";
      cin >> opcion;

      // Verifica la entrada ingresada
      if (verificarOpcionVehiculoSeleccionado(opcion, vehiculosNoAsignados))
      {
        repetir = false;
      }
      cout << "\n\n\tOpcion invalida, ingresela nuevamente";
      esperar();
    }
    int opcionInt = stoi(opcion);                                                     // convierte el
    tCarrilesPtr carrilAsignar = recorrerMultilistaHastaPosicion(carriles, i);        // busca el carril a asignarle el vehiculo seleccionado
    tVehiculoPtr carroAAsignar = obtenerNodoPorPosicion(listaNoAsignados, opcionInt); // busca el vehiculo a asignar
    carrilAsignar->vehiculoAsignado = crearNodoVehiculo(*carroAAsignar);
    carrilAsignar->aba->simbolo = carrilAsignar->vehiculoAsignado->simbolo;

    eliminarNodoVehiculo(&listaNoAsignados, carroAAsignar);
  }

  carrera(carriles, numeroCarriles);
}

/**
 * Menu que permite seleccionar si los carriles seran aleatorios o el usuario podra elegir en que carril ira cada uno.
 * @param numeroCarriles Numero de carriles que tendra la carrera.
 */
void menuOpcionesCarrera(int numeroCarriles)
{
  // repetir hasta que tenga un numero valido
  bool repetir = true;
  string opcion;
  while (repetir)
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t\t\t MENU CONFIGURAR CARRERA" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\t\t\t---OPCIONES DE CARRERA---";
    cout << "\n\n\t1.	Vehiculos aleatorios: asigna un vehiculo a cada carril de manera aleatoria.";
    cout << "\n\t2.	Seleccion de vehiculos: permite seleccionar el vehiculo que ocupara cada carril.";

    cout << "\n\n\tSeleccione una opcion: ";
    cin >> opcion;

    ((opcion == "1") || (opcion == "2")) ? repetir = false : repetir = true;
  }

  // GENERO LOS CARRILES DE LA CARRERA
  tCarrilesPtr carriles = generarCarriles(numeroCarriles);
  if (opcion == "1")
  {
    vehiculosAleatorios(carriles, numeroCarriles);
  }
  else if (opcion == "2")
  {
    menuSeleccionDeVehiculos(carriles, numeroCarriles);
  }
}

/**
 * Muestra el menú que permite configurar el número de carriles para la carrera.
 * @param listaVehiculos Puntero a la lista de vehículos.
 */
void menuJuego(tVehiculoPtr listaVehiculos)
{
  int numeroCarriles;

  // Repetir hasta que se ingrese un número válido de carriles
  bool repetir = true;
  while (repetir)
  {
    string numeroCarrilesString;
    system("cls");
    generarLogo();
    cout << "\n\n\t\t\t MENU CONFIGURAR CARRERA" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tCuantos autos correran?: ";
    cin >> numeroCarrilesString;

    cin.ignore();
    if (!caracterNumericoDeMaxDosDigitos(numeroCarrilesString))
    {
      cout << "\n\tNumero Inválido, ingréselo nuevamente";
      esperar();
    }
    else if (stoi(numeroCarrilesString) > contarNodos(listaVehiculos))
    {
      cout << "\n\tMas carriles que vehiculos, ingrese la opcion nuevamente";
      esperar();
    }
    else
    {
      numeroCarriles = stoi(numeroCarrilesString);
      repetir = false; // Salir del bucle
    }
  }

  menuOpcionesCarrera(numeroCarriles);
}

int main()
{
  // creo la lista de vehiculos y la leo del archivo
  tVehiculoPtr listaVehiculos = NULL;
  leerListaDeArchivo(&listaVehiculos);
  menuJuego(listaVehiculos);
  return 0;
}