#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <regex>

using namespace std;

// Definición de la estructura de un vehículo
typedef struct tVehiculo
{

  char simbolo;
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
 * Espera a que el usuario presione la tecla Enter para continuar.
 */
void esperar()
{
  cout << "\n\tPresione Enter para continuar...";
  cin.get();
}

/**
 * Verifica si un tipo de caucho es válido.
 *
 * @param tipoCaucho El tipo de caucho a verificar.
 * @return True si el tipo de caucho es válido, False en caso contrario.
 */
bool tipoCauchoValido(string tipoCaucho)
{
  return ((tipoCaucho == "normales") || (tipoCaucho == "anti coleo") || (tipoCaucho == "todo terreno 1") || (tipoCaucho == "todo terreno 2") || (tipoCaucho == "todo terreno 3") || (tipoCaucho == "todo terreno 4") || (tipoCaucho == "todo terreno 5"));
}

/**
 * Verifica si un tamano de caucho es válido.
 *
 * @param tamanoCaucho El tamano de caucho a verificar.
 * @return True si el tamano de caucho es válido, False en caso contrario.
 */
bool tamanoCauchoValido(string tamanoCaucho)
{
  return ((tamanoCaucho == "pegado al piso") || (tamanoCaucho == "normales") || (tamanoCaucho == "monstertruck"));
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
  const string simbolos = "#$%&*ºª@?!*^£☺☻♥♦♣•◘○◙♪♫☼►◄§▬▲▼%&"; // Lista de símbolos disponibles (34, pero maximo puedo usar 30 de ellos)
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
  nodo->velocidad = temporal.velocidad;                 // Asigna la velocidad al nodo
  nodo->simbolo = temporal.simbolo;                     // Asigna la velocidad al nodo
  nodo->tiempoDeDisminucionVelocidad = 0;               // Asigna la velocidad al nodo
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

/**
 * Muestra los nombres en español de los vehículos de una lista enlazada.
 * @param lista Puntero al primer nodo de la lista.
 */
void listarNombres(tVehiculoPtr lista)
{
  tVehiculoPtr aux = lista; // Puntero auxiliar para recorrer la lista
  int i = 1;                // Contador de índice

  while (aux != NULL)
  {
    cout << "\t" << i << ". " << aux->nombreEspanol << endl; // Muestra el número de índice y el nombre en español
    aux = aux->prox;                                         // Avanza al siguiente nodo de la lista
    i++;                                                     // Incrementa el contador de índice
  }
}

/**
 * Obtiene el nodo de una lista de vehiculos en una posición específica.
 *
 * @param lista El puntero al primer nodo de la lista de vehiculos.
 * @param posicion La posición del nodo a obtener.
 * @return El apuntador al nodo en la posición deseada, o NULL si no se encuentra.
 */
tVehiculoPtr obtenerNodoPorPosicion(tVehiculoPtr lista, int posicion)
{
  if (lista == NULL)
  {
    return NULL; // La lista está vacía
  }

  tVehiculoPtr aux = lista;
  int contador = 1;

  while (aux != NULL)
  {
    if (contador == posicion)
    {
      return aux; // Se encontró el nodo en la posición deseada
    }
    contador++;
    aux = aux->prox;
  }

  return NULL; // No se encontró el nodo en la posición deseada
}

/**
 * Cuenta la cantidad de nodos en la lista de vehiculos.
 *
 * @param lista El puntero al primer nodo de la lista vehiculos.
 * @return El número de nodos en la lista vehiculos.
 */
int contarNodos(tVehiculoPtr lista)
{
  if (lista == NULL)
  {
    return 0; // La lista está vacía
  }

  tVehiculoPtr aux = lista;
  int contador = 0;

  while (aux != NULL)
  {
    aux = aux->prox;
    contador++;
  }

  return contador; // Retorna el número de nodos en la lista
}

// ------------------ARCHIVOS------------------
/**
 * Crea o actualiza el archivo de vehiculos añadiendo en el, la lista de vehiculos.
 *
 * @param lista El puntero al primer nodo de la lista enlazada.
 */
void escribirListaEnArchivo(tVehiculoPtr lista)
{
  ofstream archivo; // ofstream representa un tipo de dato de archivo de entrada output-file-stream

  archivo.open("datos/autos.txt", ios::out); // abro el archivo en modo escribir

  // Si no se pudo crear o abrir el archivo
  if (archivo.fail())
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t ERROR: no se pudo abrir el archivo" << endl;
    cout << "\t Intente reiniciar la aplicacion" << endl;
    esperar();
    exit(1);
  }

  tVehiculoPtr aux = lista;
  while (aux != NULL)
  {
    archivo << aux->simbolo << endl;
    archivo << aux->nombreEspanol << endl;
    archivo << aux->nombreIngles << endl;
    archivo << aux->nombreConductores << endl;
    archivo << aux->tipoCaucho << endl;
    archivo << aux->tamanoDelCaucho << endl;
    archivo << aux->velocidad << endl;
    archivo << aux->tiempoDeDisminucionVelocidad << endl;
    if (aux->prox != NULL)
    {
      archivo << "\n";
    }
    aux = aux->prox;
  }

  archivo.close(); // cierro el archivo
}

void leerListaDeArchivo(tVehiculoPtr *lista)
{
  ifstream archivo; // ifstream representa un tipo de dato de archivo de entrada input-file-stream

  archivo.open("datos/autos.txt", ios::in); // abro el archivo en modo leer

  // Si no se pudo crear o abrir el archivo
  if (archivo.fail())
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t ERROR: no se pudo abrir el archivo" << endl;
    cout << "\t Intente reiniciar la aplicacion" << endl;
    esperar();
    exit(1);
  }

  tVehiculo aux; // creo un vehiculo en memoria estatica

  string simbolo;
  string tiempoDeDisminucionVelocidad;
  string separador;
  while (!archivo.eof())
  { // mientras no sea el final del archivo

    // recibe toda la info de un vehiculo
    getline(archivo, simbolo);
    aux.simbolo = simbolo[0];
    getline(archivo, aux.nombreEspanol);
    getline(archivo, aux.nombreIngles);
    getline(archivo, aux.nombreConductores);
    getline(archivo, aux.tipoCaucho);
    getline(archivo, aux.tamanoDelCaucho);
    getline(archivo, aux.velocidad);
    getline(archivo, tiempoDeDisminucionVelocidad);
    // aux.tiempoDeDisminucionVelocidad = stoi(tiempoDeDisminucionVelocidad);
    getline(archivo, separador);

    //  crea el vehiculo en la lista
    agregarNodoVehiculo(lista, crearNodoVehiculo(aux));
  }
}