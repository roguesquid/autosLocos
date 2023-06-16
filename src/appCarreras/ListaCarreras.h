#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <unistd.h>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <windows.h>
#include "movimiento.h"

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
  int tiempo;
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

void imprimirCarriles(tCarrilesPtr carriles)
{
  tCarrilesPtr auxCarriles = carriles;
  while (auxCarriles != NULL)
  {
    cout << setw(20) << auxCarriles->vehiculoAsignado->nombreEspanol;
    tCarrilPtr auxCarril = auxCarriles->aba;
    while (auxCarril != NULL)
    {
      cout << auxCarril->simbolo;
      auxCarril = auxCarril->prox;
    }
    auxCarril = auxCarriles->aba;
    cout << "\n\t";
    while (auxCarril != NULL)
    {
      cout << "-";
      auxCarril = auxCarril->prox;
    }
    cout << "\n";
    auxCarriles = auxCarriles->prox;
  }
}

void mostrarTablaTiempos(tCarrilesPtr lista)
{
  system("cls");
  generarLogo();
  cout << "\n\n\t\tTabla de tiempos" << endl;
  cout << "\t\t----------------" << endl;
  cout << "\t\tNombre" << setw(10) << "Tiempo" << endl;
  cout << "\t\t----------------" << endl;
  tCarrilesPtr aux = lista;
  while (aux != nullptr)
  {
    cout << "\t\t" << aux->vehiculoAsignado->nombreEspanol << setw(10) << aux->tiempo << endl;
    aux = aux->prox;
  }
  cout << "----------------" << endl;
  esperar();
}

void recorrerCarriles(tCarrilesPtr carriles)
{
  int y = 16;
  tCarrilesPtr auxCarriles = carriles;
  while (auxCarriles != NULL)
  {
    auxCarriles->tiempo = tiempo(auxCarriles->vehiculoAsignado, y);
    auxCarriles = auxCarriles->prox;
    y += 2;
  }
  mostrarTablaTiempos(carriles);
}

/**
 * Verifica si la carrera ha terminado, es decir, si todos los carriles han alcanzado el final.
 *
 * @param carriles Puntero al primer nodo de la multilista de carriles.
 * @return Verdadero si la carrera ha terminado, falso en caso contrario.
 */
bool terminoCarrera(tCarrilesPtr carriles)
{
  tCarrilesPtr auxCarriles = carriles;

  // Iterar sobre todos los carriles en la multilista
  while (auxCarriles != NULL)
  {
    tCarrilPtr auxCarril = auxCarriles->aba;

    // Avanzar hasta la posición 80 en el carril
    while (auxCarril->prox != NULL)
    {
      auxCarril = auxCarril->prox;
    }

    // Verificar si el símbolo en la posición final es un espacio en blanco
    if (auxCarril->simbolo == ' ')
    {
      return false; // La carrera no ha terminado, al menos un carril no ha alcanzado el final
    }

    auxCarriles = auxCarriles->prox;
  }

  return true; // Todos los carriles han alcanzado el final, la carrera ha terminado
}