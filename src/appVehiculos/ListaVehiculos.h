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
  char simbolo;
  struct tVehiculo *prox;
} tVehiculo;

typedef tVehiculo *tVehiculoPtr;

/**
 * Genera y muestra un logotipo en la salida estándar.
 * El logotipo consiste en una representación gráfica de texto.
 * con base en caracteres ASCII
 */
void generarLogo()
{
  cout << "" << endl;
  cout << "\t\t   ___       __           __                   " << endl;
  cout << "\t\t  / _ |__ __/ /____  ___ / /  ___  _______  ___" << endl;
  cout << "\t\t / __ / // / __/ _ \\(_-</ /__/ _ \\/ __/ _ \\(_-<" << endl;
  cout << "\t\t/_/ |_\\_,_/\\__/\\___/___/____/\\___/\\__/\\___/___/" << endl;
}

/**
 * Verifica si un símbolo está asignado a algún vehículo en la lista enlazada.
 * @param lista: Puntero al primer nodo de la lista de vehículos.
 * @param simbolo: Símbolo a verificar.
 * @return true si el símbolo está asignado a otro vehículo en la lista, false de lo contrario.
 */
bool existeSimbolo(tVehiculoPtr lista, char simbolo)
{
  if (lista)
  {
    tVehiculoPtr aux = lista;
    while (aux != NULL)
    {
      if (aux->simbolo == simbolo)
      {
        return true; // El símbolo ya está asignado a otro vehículo
      }
      aux = aux->prox;
    }
  }
  return false; // El símbolo no está asignado a ningún vehículo
}

/**
 * Genera un símbolo aleatorio que no esté asignado a ningún vehículo en la lista.
 * @param lista: Puntero al primer nodo de la lista de vehículos.
 * @return Un símbolo aleatorio que no esté asignado a ningún vehículo en la lista.
 */
char generarSimboloAleatorio(tVehiculoPtr lista)
{
  const string simbolos = "#$%&*ºª@?!*^£☺☻♥♦♣•◘○◙♪♫☼►◄¶§▬▲▼%&"; // Lista de símbolos disponibles
  char simbolo;

  do
  {
    simbolo = simbolos[rand() % simbolos.length()]; // Genera un índice aleatorio en el rango de los símbolos
  } while (existeSimbolo(lista, simbolo));          // Verifica si el símbolo ya está asignado a otro vehículo

  return simbolo;
}

/**
 * Crea un nuevo nodo de vehículo con los valores proporcionados.
 *
 * @param temporal: Objeto temporal que contiene los datos del vehículo.
 * @return Un puntero al nuevo nodo de vehículo creado.
 */
tVehiculoPtr crearNodoVehiculo(tVehiculo temporal)
{
  tVehiculoPtr nodo = new tVehiculo;                    // Crea un nuevo nodo de vehículo en memoria
  nodo->nombreEspanol = temporal.nombreEspanol;         // Asigna el nombre en español al nodo
  nodo->nombreIngles = temporal.nombreIngles;           // Asigna el nombre en inglés al nodo
  nodo->nombreConductores = temporal.nombreConductores; // Asigna el nombre del conductor al nodo
  nodo->tipoCaucho = temporal.tipoCaucho;               // Asigna el tipo de caucho al nodo
  nodo->tamanoDelCaucho = temporal.tamanoDelCaucho;     // Asigna el tamaño del caucho al nodo
  // nodo->simbolo = generarSimboloAleatorio(lista);
  nodo->prox = NULL; // Establece el puntero "prox" del nodo como NULL (sin siguiente nodo)

  return nodo; // Devuelve el puntero al nuevo nodo de vehículo creado
}

/**
 * Verifica si un nombre de vehículo en español dado existe en la lista de vehículos.
 *
 * @param lista: Puntero al primer nodo de la lista de vehículos.
 * @param nombreEspanolVehiculo: Nombre del vehículo en español a verificar.
 * @return true si el nombre de vehículo existe en la lista, false en caso contrario.
 */
bool existeNombre(tVehiculoPtr lista, string nombreEspanolVehiculo)
{
  if (lista)
  {
    tVehiculoPtr aux = lista; // Crea un puntero auxiliar y lo inicializa con el primer nodo de la lista

    while (aux != NULL)
    {
      if (aux->nombreEspanol == nombreEspanolVehiculo) // Compara el nombre de vehículo en español con el nombre proporcionado
      {
        return true; // El nombre de vehículo existe en la lista, se devuelve true
      }
      aux = aux->prox; // Avanza al siguiente nodo de la lista
    }
  }

  return false; // El nombre de vehículo no se encontró en la lista, se devuelve false
}

/**
 * Muestra la información de un vehículo en la salida estándar.
 *
 * @param lista: Puntero al inicio de la lista de vehículos.
 * @param nodo: Puntero al nodo de vehículo que se desea mostrar.
 */
void mostrarVehiculo(tVehiculoPtr lista, tVehiculoPtr nodo)
{
  cout << "\n\t" << nodo->nombreEspanol << endl;
  cout << "\n";
  cout << "\tNombre Vehiculo en ingles: " << nodo->nombreIngles << endl;
  cout << "\tConductor/es: " << nodo->nombreConductores << endl;
  cout << "\tTipo de caucho: " << nodo->tipoCaucho << endl;
  cout << "\tTamano del caucho: " << nodo->tamanoDelCaucho << endl;
  cout << "\tVelocidad: " << nodo->velocidad << endl;
  cout << "\tResistencia: " << nodo->tiempoDeDisminucionVelocidad << endl;
  cout << "\n";
}

/**
 * Muestra la información de todos los vehículos en la lista en la salida estándar.
 *
 * @param lista: Puntero al inicio de la lista de vehículos.
 */
void listarVehiculos(tVehiculoPtr lista)
{
  tVehiculoPtr aux = lista;
  while (aux != NULL)
  {
    mostrarVehiculo(lista, aux);
    aux = aux->prox;
  }
  system("pause");
}

/**
 * Busca un vehículo en la lista por su nombre en español y devuelve un puntero al nodo del vehículo encontrado.
 *
 * @param lista: Puntero al inicio de la lista de vehículos.
 * @param nombreEspanolVehiculo: Nombre del vehículo en español a buscar.
 * @return Puntero al nodo del vehículo encontrado o NULL si no se encuentra.
 */
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