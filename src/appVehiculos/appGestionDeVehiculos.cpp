#include <iostream>
#include <string>
#include <cstdlib>
#include <regex>
#include "ListaVehiculos.h"

using namespace std;

/**
 * Convierte un string a minúsculas.
 * @param str El string a convertir.
 * @return El string convertido a minúsculas.
 */
string convertirMinusculas(string str)
{
  // for each
  // char &c es una referencia para cada elemento del contenedor iterable str
  for (char &c : str)
  {
    c = tolower(c); // Convierte cada carácter a minúsculas
  }
  return str;
}

/**
 * Verifica si una cadena de caracteres está vacía.
 * @param str Cadena de caracteres a verificar.
 * @return Devuelve true si la cadena está vacía, de lo contrario, devuelve false.
 */
bool stringVacio(string str)
{
  return (str.length() == 0); // Comprueba si la longitud de la cadena es igual a cero
}

/**
 * Comprueba si un string de un solo carácter es numérico.
 *
 * @param str El string que se desea comprobar.
 * @return true si el string es numérico, false en caso contrario.
 */
bool esCaracterNumerico(const std::string &str)
{
  // Expresión regular para verificar si el string es numérico
  std::regex regex("\\d");

  // Comprobar si el string tiene exactamente un carácter y si coincide con la expresión regular
  return std::regex_match(str, regex);
}

/**
 * Permite al usuario ingresar y validar los nombres de un vehículo en español e inglés.
 *
 * @param lista: Puntero a la lista enlazada de vehículos.
 * @param nombreEspanol: Puntero a un string donde se almacenará el nombre en español ingresado.
 * @param nombreIngles: Puntero a un string donde se almacenará el nombre en inglés ingresado.
 */
void leerNombres(tVehiculoPtr lista, string *nombreEspanol, string *nombreIngles)
{
  bool repetir = true; // Variable para controlar el bucle de repetición
  string nombreEspanolAux;
  string nombreInglesAux;

  while (repetir) // Bucle para solicitar y validar los nombres
  {
    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\t MENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tNombre vehiculo\n";

    cout << "\n\tIngrese el nombre del vehiculo en espanol: ";
    getline(cin, nombreEspanolAux); // Lee el nombre en español ingresado por el usuario

    cout << "\n\tIngrese el nombre del vehiculo en ingles: ";
    getline(cin, nombreInglesAux); // Lee el nombre en inglés ingresado por el usuario

    bool nombreEspValido = !existeNombre(lista, nombreEspanolAux) && !stringVacio(nombreEspanolAux); // Verifica si el nombre en español es válido
    bool nombreIngValido = !stringVacio(nombreInglesAux);                                            // Verifica si el nombre en inglés es válido

    if (nombreEspValido && nombreIngValido) // Si ambos nombres son válidos
    {
      *nombreEspanol = nombreEspanolAux; // Asigna el nombre en español ingresado al puntero correspondiente
      *nombreIngles = nombreInglesAux;   // Asigna el nombre en inglés ingresado al puntero correspondiente
      repetir = false;                   // Sale del bucle de repetición
    }
    else // Si algún nombre es inválido
    {
      cout << "\n\tNombres invalidos, ingreselos nuevamente";
      esperar(); // Pausa la ejecución y espera a que el usuario presione Enter para continuar
    }
  }
}

/**
 * Permite al usuario ingresar y validar el nombre del o los conductores de un vehículo.
 *
 * @param nombreConductores: Puntero a un string donde se almacenará el nombre del o los conductores ingresado.
 */
void leerConductores(string *nombreConductores)
{
  string nombreConductoresAux; // Variable auxiliar para almacenar el nombre del o los conductores ingresado
  bool repetir = true;         // Variable para controlar el bucle de repetición

  while (repetir) // Bucle para solicitar y validar el nombre del o los conductores
  {
    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\t MENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tNombre conductores\n";

    cout << "\n\tIngrese el nombre del/los conductor/es: ";
    getline(cin, nombreConductoresAux); // Lee el nombre del o los conductores ingresado por el usuario

    bool nombreConductoresValido = !stringVacio(nombreConductoresAux); // Verifica si el nombre del o los conductores no está vacío

    if (nombreConductoresValido) // Si el nombre del o los conductores es válido
    {
      *nombreConductores = nombreConductoresAux; // Asigna el nombre del o los conductores ingresado al puntero correspondiente
      repetir = false;                           // Sale del bucle de repetición
    }
    else // Si el nombre del o los conductores es inválido (vacío)
    {
      cout << "\n\tNombre de conductores vacio, ingreselo nuevamente";
      esperar(); // Pausa la ejecución y espera a que el usuario presione Enter para continuar
    }
  }
}

/**
 * Permite al usuario ingresar y validar el tipo de caucho de un vehículo.
 *
 * @param tipoCaucho: Puntero a un string donde se almacenará el tipo de caucho ingresado.
 */
void leerTipoCaucho(string *tipoCaucho)
{
  string tipoCauchoAux; // Variable auxiliar para almacenar el tipo de caucho ingresado
  bool repetir = true;  // Variable para controlar el bucle de repetición

  while (repetir) // Bucle para solicitar y validar el tipo de caucho
  {
    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\t MENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tTipo de Caucho\n";

    cout << "\t\t-Normales\n";
    cout << "\t\t-Anti coleo\n";
    cout << "\t\t-Todo terreno 1\n";
    cout << "\t\t-Todo terreno 2\n";
    cout << "\t\t-Todo terreno 3\n";
    cout << "\t\t-Todo terreno 4\n";
    cout << "\t\t-Todo terreno 5\n";

    cout << "\n\tIngrese el tipo de caucho: ";
    getline(cin, tipoCauchoAux);                        // Lee el tipo de caucho ingresado por el usuario
    tipoCauchoAux = convertirMinusculas(tipoCauchoAux); // Convierte el tipo de caucho a minúsculas

    bool tipoDeCauchoValido = tipoCauchoValido(tipoCauchoAux); // Verifica si el tipo de caucho es válido

    if (tipoDeCauchoValido) // Si el tipo de caucho es válido
    {
      *tipoCaucho = tipoCauchoAux; // Asigna el tipo de caucho ingresado al puntero correspondiente
      repetir = false;             // Sale del bucle de repetición
    }
    else // Si el tipo de caucho es inválido
    {
      cout << "\n\tTipo de caucho invalido, ingreselo nuevamente";
      esperar(); // Pausa la ejecución y espera a que el usuario presione Enter para continuar
    }
  }
}

/**
 * Permite al usuario ingresar y validar el tamano de caucho de un vehículo.
 *
 * @param tamanoCaucho: Puntero a un string donde se almacenará el tamano de caucho ingresado.
 */
void leerTamanoCaucho(string *tamanoCaucho)
{
  string tamanoCauchoAux; // Variable auxiliar para almacenar el tamano de caucho ingresado
  bool repetir = true;    // Variable para controlar el bucle de repetición

  while (repetir) // Bucle para solicitar y validar el tamano de caucho
  {
    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\t MENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tTamano de Caucho\n";

    cout << "\t\t-Pegado al piso\n";
    cout << "\t\t-Normales\n";
    cout << "\t\t-MonsterTruck\n";

    cout << "\n\tIngrese el tamano de caucho: ";
    getline(cin, tamanoCauchoAux);                          // Lee el tamano de caucho ingresado por el usuario
    tamanoCauchoAux = convertirMinusculas(tamanoCauchoAux); // Convierte el tamano de caucho a minúsculas

    bool tamanoDeCauchoValido = tamanoCauchoValido(tamanoCauchoAux); // Verifica si el tamano de caucho es válido

    if (tamanoDeCauchoValido) // Si el tamano de caucho es válido
    {
      *tamanoCaucho = tamanoCauchoAux; // Asigna el tamano de caucho ingresado al puntero correspondiente
      repetir = false;                 // Sale del bucle de repetición
    }
    else // Si el tamano de caucho es inválido
    {
      cout << "\n\tTamano de caucho invalido, ingreselo nuevamente";
      esperar(); // Pausa la ejecución y espera a que el usuario presione Enter para continuar
    }
  }
}

/**
 * Permite al usuario ingresar y validar la velocidad de un vehículo,
 * según el tamaño de los neumáticos.
 *
 * @param tamanoCaucho: El tamaño de los neumáticos del vehículo.
 * @param velocidad: Puntero a un string donde se almacenará la velocidad ingresada.
 */
void leerVelocidad(string tamanoCaucho, string *velocidad)
{
  string velocidadAux;
  bool repetir = true;

  while (repetir)
  {
    system("cls");
    generarLogo();
    cout << "\n\n\t\t\t MENU AGREGAR VEHICULO" << endl;
    cout << "\t\t\t----------------------" << endl;
    cout << "\n\n\tVelocidad\n";
    if (tamanoCaucho == "pegado al piso")
    {
      cout << "\t\t-El super ferrari\n";
      cout << "\t\t-Delorean\n";
      cout << "\n\tIngrese la velocidad: ";
      getline(cin, velocidadAux);
      velocidadAux = convertirMinusculas(velocidadAux);
      if ((velocidadAux == "el super ferrari") || (velocidadAux == "delorean"))
      {
        *velocidad = velocidadAux;
        repetir = false;
      }
      else
      {
        cout << "\n\n\tVelocidad invalida";
        esperar();
      }
    }
    else if (tamanoCaucho == "normales")
    {
      cout << "\t\t-Crucero\n";
      cout << "\t\t-Perezoso\n";
      cout << "\n\tIngrese la velocidad: ";
      getline(cin, velocidadAux);
      velocidadAux = convertirMinusculas(velocidadAux);
      if ((velocidadAux == "perezoso") || (velocidadAux == "crucero"))
      {
        *velocidad = velocidadAux;
        repetir = false;
      }
      else
      {
        cout << "\n\n\tVelocidad invalida";
        esperar();
      }
    }
    else if (tamanoCaucho == "monstertruck")
    {
      cout << "\t\t-Perezoso\n";
      cout << "\n\tIngrese la velocidad: ";
      getline(cin, velocidadAux);
      velocidadAux = convertirMinusculas(velocidadAux);
      if (velocidadAux == "perezoso")
      {
        *velocidad = velocidadAux;
        repetir = false;
      }
      else
      {
        cout << "\n\n\tVelocidad invalida";
        esperar();
      }
    }
  }
}

/**
 * Agrega un nuevo vehículo a la lista de vehículos.
 *
 * @param lista: Puntero a un puntero al inicio de la lista de vehículos.
 */
void agregar(tVehiculoPtr *lista)
{
  tVehiculo temporal;

  // establezco un limite maximo de 30 vehiculos por la cantidad de caracteres disponibles para representarlos
  if (contarNodos(*lista) <= 30)
  {
    cin.ignore();
    leerNombres(*lista, &(temporal.nombreEspanol), &(temporal.nombreIngles));
    leerConductores(&(temporal.nombreConductores));
    leerTipoCaucho(&(temporal.tipoCaucho));
    leerTamanoCaucho(&(temporal.tamanoDelCaucho));
    leerVelocidad(temporal.tamanoDelCaucho, &(temporal.velocidad));
    temporal.simbolo = generarSimboloAleatorio(*lista); // le asigno un simbolo unico

    agregarNodoVehiculo(lista, crearNodoVehiculo(temporal)); // agrego a la lista

    escribirListaEnArchivo(*lista); // actualizo el archivo

    // Mostrar Informacion del vehiculo agregado
    system("cls");
    cout << "\n\n\t\t\tINFORMACION DEL VEHICULO" << endl;
    cout << "\t\t\t-------------------------" << endl;
    mostrarVehiculo(*lista, *lista);
    cout << "\n\n\tVehiculo agregado con exito" << endl;
    cout << "\tPresione Enter para continuar...";
    cin.get();
  }
}

/**
 * Verifica si una opcion esta en el rango de nodos y si es caracter numerico.
 * @param lista Puntero al primer nodo de la lista de vehículos.
 * @param opcion Opción ingresada por el usuario.
 * @return Devuelve true si la opción es válida, de lo contrario, devuelve false.
 */
bool opcionValida(tVehiculoPtr lista, string opcion)
{
  if (esCaracterNumerico(opcion))
  {
    bool rangoValido = (stoi(opcion) <= contarNodos(lista)) && (stoi(opcion) >= 1); // Convierte el string a entero y verifica si está dentro del rango válido
    if (rangoValido)
    {
      return true; // La opción es válida
    }
  }

  return false; // La opción no es válida
}

/**
 * Pide un vehiculo a traves de un menu de todos los vehiculos disponibles y realiza todas las comprobaciones.
 * @param lista Puntero al primer nodo de la lista de vehículos.
 * @return Devuelve el apuntador al vehiculo que el usuario selecciono.
 */
tVehiculoPtr pedirVehiculo(tVehiculoPtr lista)
{
  string opcion;
  bool repetir = true;
  do
  {
    listarNombres(lista);
    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    if (opcionValida(lista, opcion)) // verifica si esta en el rango de nodos y si es numerico
    {
      repetir = false;
    }
  } while (repetir);

  // pedir el campo a modificar
  cin.ignore(); // Descartar el carácter de nueva línea pendiente
  int opcionInt = stoi(opcion);
  tVehiculoPtr vehiculo = obtenerNodoPorPosicion(lista, opcionInt);
  return vehiculo;
}

/**
 * Permite al usuario seleccionar el campo a modificar de un vehículo.
 *
 * @return El número entero correspondiente al campo seleccionado.
 */
int pedirCampoAModificar()
{
  string opcion;       // Variable para almacenar la opción ingresada por el usuario
  bool repetir = true; // Variable para controlar el bucle de repetición

  do
  {
    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\tMENU MODIFICAR VEHICULO" << endl;
    cout << "\t\t\t-----------------------" << endl;
    cout << "\n\t Ingrese el campo a modificar" << endl;
    cout << "\n\t 1. Nombres";
    cout << "\n\t 2. Nombre de conductores";
    cout << "\n\t 3. Tipo de caucho";
    cout << "\n\t 4. Tamano de caucho";
    cout << "\n\t 5. Velocidad" << endl;
    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    if ((opcion >= "1") && (opcion <= "6") && (esCaracterNumerico(opcion))) // Verifica si la opción ingresada es válida
    {
      repetir = false; // Sale del bucle de repetición
    }
  } while (repetir);

  int opcionInt = stoi(opcion); // Convierte la opción ingresada a un número entero
  return opcionInt;             // Retorna el número entero correspondiente al campo seleccionado
}

/**
 * Permite al usuario seleccionar un vehículo y el campo que desea modificar.
 * Realiza la modificación del campo seleccionado según la opción ingresada.
 *
 * @param lista Puntero a la lista de vehículos.
 */
void modificar(tVehiculoPtr lista)
{
  system("cls");
  generarLogo();
  cout << "\n\n\t\t\tMENU MODIFICAR VEHICULO" << endl;
  cout << "\t\t\t-----------------------\n\n";
  cin.ignore();
  if (contarNodos(lista) > 0)
  { // si existen nodos
    // Pedir el vehículo a modificar
    tVehiculoPtr nodo = pedirVehiculo(lista);

    // Pedir el campo a modificar
    int opcion = pedirCampoAModificar();

    switch (opcion)
    {
    case 1:
      // Modificar nombres
      cin.ignore();
      leerNombres(lista, &(nodo->nombreEspanol), &(nodo->nombreIngles));
      break;
    case 2:
      // Modificar nombre de conductores
      leerConductores(&(nodo->nombreConductores));
      break;
    case 3:
      // Modificar tipo de caucho
      leerTipoCaucho(&(nodo->tipoCaucho));
      break;
    case 4:
      // Modificar tamaño de caucho
      leerTamanoCaucho(&(nodo->tamanoDelCaucho));
      leerVelocidad(nodo->tamanoDelCaucho, &(nodo->velocidad));
      break;
    case 5:
      // Modificar tamaño de caucho y velocidad
      leerTamanoCaucho(&(nodo->tamanoDelCaucho));
      leerVelocidad(nodo->tamanoDelCaucho, &(nodo->velocidad));
      break;
    }

    escribirListaEnArchivo(lista); // actualizo el archivo

    system("cls"); // Limpia la pantalla de la consola
    generarLogo(); // Muestra un logo en la consola
    cout << "\n\n\t\t\tMENU MODIFICAR VEHICULO" << endl;
    cout << "\t\t\t-----------------------" << endl;
    mostrarVehiculo(lista, nodo); // Muestra la información actualizada del vehículo modificado
    cout << "\n\t Modificacion existosa";
  }
  else
  {
    cout << "No hay nada que modificar";
  }
  esperar();
}

/**
 * Elimina un vehículo de la lista enlazada.
 * Muestra el vehiculo luego de ser eliminado.
 *
 * @param lista Puntero a la lista enlazada de vehículos.
 */
void eliminar(tVehiculoPtr *lista)
{
  system("cls");
  generarLogo();
  cout << "\n\n\t\t\tMENU ELIMINAR VEHICULO" << endl;
  cout << "\t\t\t----------------------\n\n";
  cin.ignore();
  tVehiculoPtr nodoAEliminar = pedirVehiculo(*lista);
  tVehiculo aux = *nodoAEliminar;             // guardo en una variable estatica el nodo que voy a eliminar
  eliminarNodoVehiculo(lista, nodoAEliminar); // elimino el vehiculo

  escribirListaEnArchivo(*lista); // actualizo el archivo

  // Muestra el vehiculo eliminado
  system("cls"); // limpio la pantalla
  generarLogo(); // genero el logo
  cout << "\n\n\t\t\tMENU ELIMINAR VEHICULO" << endl;
  cout << "\t\t\t----------------------\n\n";
  mostrarVehiculo(*lista, &aux); // muestro el vehiculo eliminado
  cout << "\n\n\tVehiculo eliminado con exito" << endl;
  esperar();
}

/**
 * Muestra un menú para consultar un vehículo de una lista enlazada.
 * @param lista Puntero al primer nodo de la lista de vehículos.
 */
void consultar(tVehiculoPtr lista)
{
  system("cls");
  generarLogo();
  cout << "\n\n\t\t\tCONSULTAR VEHICULO" << endl;
  cout << "\t\t\t------------------" << endl;
  cin.ignore();
  tVehiculoPtr vehiculo = pedirVehiculo(lista);

  system("cls");
  generarLogo();
  cout << "\n\n\t\t\tCONSULTAR VEHICULO" << endl;
  cout << "\t\t\t------------------" << endl;
  mostrarVehiculo(lista, vehiculo);
  esperar();
}

/**
 * Muestra en pantalla la lista de vehículos.
 *
 * @param lista: Puntero a la lista de vehículos.
 */
void listar(tVehiculoPtr lista)
{
  system("cls"); // Limpia la pantalla
  generarLogo(); // Muestra el logo del programa
  cout << "\n\n\t\t\tLISTAR VEHICULOS" << endl;
  cout << "\t\t\t----------------" << endl;
  cin.ignore();
  listarVehiculos(lista); // Llama a la función listarVehiculos para mostrar la lista de vehículos
  esperar();
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
      agregar(lista);
    }
    else if (opcion == "2")
    {
      // Modificar vehiculo: implementa la lógica para modificar un vehículo existente
      modificar(*lista);
    }
    else if (opcion == "3")
    {
      // Eliminar vehiculo: implementa la lógica para eliminar un vehículo existente
      eliminar(lista);
    }
    else if (opcion == "4")
    {
      // Consultar vehiculo: implementa la lógica para consultar la información de un vehículo
      consultar(*lista);
    }
    else if (opcion == "5")
    {
      // Listar vehiculos: implementa la lógica para mostrar una lista de vehículos
      listar(*lista);
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