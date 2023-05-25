#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Definición de la estructura de un vehículo
typedef struct tVehiculo
{
  string nombreEspanol;
  string nombreIngles;
  string nombreConductores;
  string tipoCaucho;
  string tamanoDelCaucho;
  string velocidad;
  int tiempoDeDisminucionVelocidad;
  struct tVehiculo *prox;
} tVehiculo;

typedef tVehiculo *tVehiculoPtr;

void generarLogo()
{
  cout << "" << endl;
  cout << "\t\t   ___       __           __                   " << endl;
  cout << "\t\t  / _ |__ __/ /____  ___ / /  ___  _______  ___" << endl;
  cout << "\t\t / __ / // / __/ _ \\(_-</ /__/ _ \\/ __/ _ \\(_-<" << endl;
  cout << "\t\t/_/ |_\\_,_/\\__/\\___/___/____/\\___/\\__/\\___/___/" << endl;
}

/**
 * Crea un nuevo nodo de vehículo con los valores proporcionados.
 *
 * @param nombreEspanol: Nombre del vehículo en español.
 * @param nombreIngles: Nombre del vehículo en inglés.
 * @param nombreConductores: Nombre del conductor del vehículo.
 * @param tipoCaucho: Tipo de caucho utilizado en el vehículo.
 * @param tamanoDelCaucho: Tamaño del caucho utilizado en el vehículo.
 * @param velocidad: Velocidad del vehículo.
 * @param tiempoDeDisminucionVelocidad: Tiempo de disminución de velocidad del vehículo.
 * @return Un puntero al nuevo nodo de vehículo creado.
 */
tVehiculoPtr crearNodoVehiculo(tVehiculo temporal)
{
  tVehiculoPtr nodo = new tVehiculo;
  nodo->nombreEspanol = temporal.nombreEspanol;
  nodo->nombreIngles = temporal.nombreIngles;
  nodo->nombreConductores = temporal.nombreConductores;
  nodo->tipoCaucho = temporal.tipoCaucho;
  nodo->tamanoDelCaucho = temporal.tamanoDelCaucho;
  nodo->prox = NULL;
  return nodo;
}

bool verificarNombre(tVehiculoPtr lista, string nombreEspanolVehiculo)
{
  if (lista)
  {
    tVehiculoPtr aux = lista;
    while (aux != NULL)
    {
      if (aux->nombreEspanol == nombreEspanolVehiculo)
      {
        return true;
      }
      aux = aux->prox;
    }
  }
  return false;
}

void mostrarVehiculo(tVehiculoPtr lista, tVehiculoPtr nodo)
{
  system("cls"); // Limpia la pantalla

  // Imprime el encabezado del menú
  generarLogo();
  cout << "\n\n\t\t\tINFORMACION DEL VEHICULO" << endl;
  cout << "\t\t\t-------------------------" << endl;

  cout << "\n\tNombre Vehiculo en espanol: " << nodo->nombreEspanol << endl;
  cout << "\tNombre Vehiculo en ingles: " << nodo->nombreIngles << endl;
  cout << "\tConductor/es: " << nodo->nombreConductores << endl;
  cout << "\tTipo de caucho: " << nodo->tipoCaucho << endl;
  cout << "\tTamaño del caucho: " << nodo->tamanoDelCaucho << endl;
  cout << "\tVelocidad: " << nodo->velocidad << endl;
  cout << "\tResistencia: " << nodo->tiempoDeDisminucionVelocidad << endl;
  system("pause");
}

tVehiculoPtr buscarVehiculo(tVehiculoPtr lista, string nombreEspanolVehiculo)
{
  if (lista)
  {
    tVehiculoPtr aux = lista;
    while (aux != NULL)
    {
      if (aux->nombreEspanol == nombreEspanolVehiculo)
      {
        return aux;
      }
      aux = aux->prox;
    }
  }
  return NULL;
}

/**
 * Agrega un nodo de vehículo a una lista enlazada.
 *
 * @param lista: Puntero al puntero inicial de la lista.
 * @param nodo: Puntero al nodo de vehículo a agregar.
 */
void agregarNodoVehiculo(tVehiculoPtr *lista, tVehiculoPtr nodo)
{
  if (*lista != NULL)
  {
    nodo->prox = *lista;
  }
  *lista = nodo;
  mostrarVehiculo(*lista, nodo);
  // Falta actualizar el archivo cuando se agregue un nuevo vehiculo
}

/**
 * Elimina un nodo de vehículo de una lista enlazada.
 *
 * @param lista: Puntero al puntero inicial de la lista.
 * @param nodo: Puntero al nodo de vehículo a eliminar.
 */
void eliminarNodoVehiculo(tVehiculoPtr *lista, tVehiculoPtr nodo)
{
  tVehiculoPtr aux = *lista;
  if (aux == nodo)
  {
    *lista = aux->prox;
    delete aux;
  }
  else
  {
    while (aux != NULL)
    {
      if (aux->prox == nodo)
      {
        tVehiculoPtr t = aux->prox;
        aux->prox = aux->prox->prox;
        delete t;
      }
      aux = aux->prox;
    }
  }
}