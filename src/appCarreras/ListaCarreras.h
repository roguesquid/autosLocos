#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <fstream>
#include "../appVehiculos/ListaVehiculos.h"

using namespace std;

// Lista enlazada de carriles
typedef struct tCarril
{
  int kilometro;        // Número del kilómetro en el carril
  char simbolo;         // Símbolo que representa el carril
  struct tCarril *prox; // Puntero al siguiente nodo de la lista
} tCarril;
typedef tCarril *tCarrilPtr;

// Multilista de carriles
typedef struct tCarriles
{
  tVehiculoPtr vehiculoAsignado; // Puntero al vehículo asignado al carril
  struct tCarriles *prox;        // Puntero al siguiente nodo de la multilista
  struct tCarril *aba;           // Puntero al primer nodo de la lista de carriles
} tCarriles;
typedef tCarriles *tCarrilesPtr;

// GENERACION DE LISTA CARRIL

/**
 * Genera un obstáculo aleatorio seleccionado de una lista predefinida.
 * @return Carácter que representa el obstáculo aleatorio generado.
 */
char generarObstaculoAleatorio()
{
  string obstaculos = "¤¶≠";
  return obstaculos[rand() % obstaculos.length()];
}

/**
 * Crea un nuevo nodo de carril con el kilómetro y símbolo especificados.
 * @param kilometro El número de kilómetro del carril.
 * @param simbolo El símbolo asociado al carril.
 * @return Puntero al nuevo nodo de carril creado.
 */
tCarrilPtr crearNodoCarril(int kilometro, char simbolo)
{
  tCarrilPtr nodo = new tCarril;
  nodo->kilometro = kilometro;
  nodo->simbolo = simbolo;
  nodo->prox = NULL;
  return nodo;
}

/**
 * Agrega un nodo al principio de la lista de carriles.
 * @param listaCarril Puntero al puntero de la lista de carriles.
 * @param nodo Puntero al nodo de carril que se desea agregar.
 */
void agregarNodoCarril(tCarrilPtr *listaCarril, tCarrilPtr nodo)
{
  nodo->prox = *listaCarril;
  *listaCarril = nodo;
}

/**
 * Genera una lista de carriles con obstáculos aleatorios en una posición específica.
 * @return Puntero al primer nodo de la lista de carriles generada.
 */
tCarrilPtr generarCarril()
{
  tCarrilPtr lista = NULL;

  int longitudPista = 80;
  int posicionObstaculo = (rand() % longitudPista) + 1;

  for (int i = longitudPista; i >= 1; i--)
  {
    char simbolo = (i == posicionObstaculo) ? generarObstaculoAleatorio() : ' ';
    tCarrilPtr nodo = crearNodoCarril(i, simbolo);
    agregarNodoCarril(&lista, nodo);
  }

  return lista;
}

// GENERACION DE MULTILISTA CARRILES
/**
 * Crea un nuevo nodo de carriles con una lista de carriles generada mediante la función generarCarril().
 * @return Puntero al nuevo nodo de carriles creado.
 */
tCarrilesPtr crearNodoCarriles()
{
  tCarrilesPtr nodo = new tCarriles;
  nodo->aba = generarCarril();
  nodo->prox = NULL;
  return nodo;
}

/**
 * Agrega un nodo al principio de la lista de carriles.
 * @param listaCarriles Puntero al puntero de la lista de carriles.
 * @param nodo Puntero al nodo de carriles que se desea agregar.
 */
void agregarNodoCarriles(tCarrilesPtr *listaCarriles, tCarrilesPtr nodo)
{
  nodo->prox = *listaCarriles;
  *listaCarriles = nodo;
}

/**
 * Genera una lista de carriles con la cantidad especificada de nodos de carriles, cada uno con su lista de carriles generada.
 * @param numeroCarriles El número de nodos de carriles a generar.
 * @return Puntero al primer nodo de la multilista de carriles generada.
 */
tCarrilesPtr generarCarriles(int numeroCarriles)
{
  tCarrilesPtr carriles = NULL;
  for (int i = 0; i < numeroCarriles; i++)
  {
    tCarrilesPtr nodo = crearNodoCarriles();
    agregarNodoCarriles(&carriles, nodo);
  }
  return carriles;
}

/**
 * Verifica si un vehículo está asignado en alguno de los nodos de la multilista de carriles.
 *
 * @param listaCarriles Puntero al primer nodo de la multilista de carriles.
 * @param vehiculoAConsultar Puntero al vehículo que se desea buscar.
 * @return True si el vehículo está asignado en algún nodo de la multilista, False en caso contrario.
 */
bool vehiculoAsignado(tCarrilesPtr listaCarriles, tVehiculoPtr vehiculoAConsultar)
{
  tCarrilesPtr aux = listaCarriles;

  while (aux != NULL)
  {
    if (aux->vehiculoAsignado == vehiculoAConsultar)
    {
      return true;
    }
    aux = aux->prox;
  }

  return false;
}

/**
 * Lista los vehículos que no están asignados en ningún nodo de la multilista de carriles.
 *
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @param listaVehiculos Puntero al primer nodo de la lista de vehículos.
 * @return Cantidad de vehiculos no asignados
 */
int listarVehiculosNoAsignados(tCarrilesPtr carriles, tVehiculoPtr listaVehiculos)
{
  tVehiculoPtr aux = listaVehiculos; // Puntero auxiliar para recorrer la lista
  int i = 1;                         // Contador de índice

  while (aux != NULL)
  {
    if (!vehiculoAsignado(carriles, aux))
    {
      cout << "\t" << i << ". " << aux->nombreEspanol << endl; // Muestra el número de índice y el nombre en español
      aux = aux->prox;                                         // Avanza al siguiente nodo de la lista
      i++;                                                     // Incrementa el contador de índice
    }
  }
}

/**
 * Busca y devuelve el puntero al vehículo no asignado que se encuentra en la posición RELATIVA a no asignados.
 * @param lista Puntero al primer nodo de la lista de vehículos.
 * @param posicionDeNoAsignados La posición deseada del vehículo no asignado.
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @return Puntero al vehículo no asignado que se encuentra en la posición deseada, o nullptr si no se encuentra en la lista.
 */
tVehiculoPtr buscarVehiculoNoAsignadoPorPosicion(tVehiculoPtr lista, int posicionDeNoAsignados, tCarrilesPtr carriles)
{
  tVehiculoPtr aux = lista; // Puntero auxiliar para recorrer la lista
  int i = 1;                // Contador de índice

  while (aux != NULL)
  {
    if (!vehiculoAsignado(carriles, aux))
    {
      if (posicionDeNoAsignados == i)
      {
        return aux; // Devolver el puntero al vehículo no asignado en la posición deseada
      }
      i++; // Incrementar el contador de índice solo cuando el vehiculo no este asignado
    }
    aux = aux->prox; // Avanzar al siguiente nodo de la lista
  }

  return nullptr; // El vehículo no asignado en la posición deseada no se encuentra en la lista
}

/**
 * Recorre la multilista de carriles hasta la posición deseada y devuelve el puntero al nodo correspondiente.
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @param posicionDeseada La posición deseada a la que se desea llegar.
 * @return Puntero al nodo de la multilista que se encuentra en la posición deseada, o NULL si la posición no se encuentra en la lista.
 */
tCarrilesPtr recorrerMultilistaHastaPosicion(tCarrilesPtr carriles, int posicionDeseada)
{
  tCarrilesPtr aux = carriles; // Puntero auxiliar para recorrer la multilista
  int posicionActual = 1;      // Contador de posición actual

  while (aux != NULL && posicionActual <= posicionDeseada)
  {
    if (posicionActual == posicionDeseada)
    {
      return aux; // Devolver el puntero al nodo en la posición deseada
    }

    aux = aux->prox;  // Avanzar al siguiente nodo de la multilista
    posicionActual++; // Incrementar el contador de posición actual
  }

  return NULL; // La posición deseada no se encuentra en la lista
}