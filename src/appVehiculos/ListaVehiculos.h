#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Definición de la estructura de un vehículo
typedef struct vehiculo
{
  string nombreEspanol;
  string nombreIngles;
  string nombreConductores;
  string tipoCaucho;
  string tamanoDelCaucho;
  string velocidad;
  int tiempoDeDisminucionVelocidad;
  struct vehiculo *prox;
} tVehiculo;

typedef tVehiculo *tVehiculoPtr;

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
tVehiculoPtr crearNodoVehiculo(string nombreEspanol, string nombreIngles, string nombreConductores, string tipoCaucho, string tamanoDelCaucho, string velocidad, int tiempoDeDisminucionVelocidad)
{
  tVehiculoPtr nodo = new tVehiculo;
  nodo->nombreEspanol = nombreEspanol;
  nodo->nombreIngles = nombreIngles;
  nodo->nombreConductores = nombreConductores;
  nodo->tipoCaucho = tipoCaucho;
  nodo->tamanoDelCaucho = tamanoDelCaucho;
  nodo->velocidad = velocidad;
  nodo->tiempoDeDisminucionVelocidad = tiempoDeDisminucionVelocidad;
  nodo->prox = NULL;
  return nodo;
}

/**
 * Agrega un nodo de vehículo a una lista enlazada.
 *
 * @param lista: Puntero al puntero inicial de la lista.
 * @param nodo: Puntero al nodo de vehículo a agregar.
 * @return El puntero al nodo de vehículo agregado, que ahora es el nuevo primer nodo de la lista.
 */
tVehiculoPtr agregarNodoVehiculo(tVehiculoPtr *lista, tVehiculoPtr nodo)
{
  if (*lista != NULL)
  {
    nodo->prox = *lista;
  }
  *lista = nodo;
  return (*lista);
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