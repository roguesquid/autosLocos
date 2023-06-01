#include <iostream>
#include <cmath> // esta libreria es para la función sqrt que calcula raiz cuadrada, podemos usarla?

using namespace std;

// algunos comentarios.
// debemos usar las variables que tiene luis en el programa y las que agregue Levin, pero esta seria una estructura y funciones
//  Faltaria llamar las funciones para poner los carros creados por luis en los carriles.
//  pensaba en agregar una bandera o algo de finish al final
// también pensé en poner en librerias estas funciones e incluirlo en el principal que tiene luis y el de levin tambien por libreria

// Definición de la estructura del nodo secundario
struct NodoSecundario
{
    int valor;
    int posicion;
    NodoSecundario *siguiente;
    NodoSecundario *anterior;
};

// Definición de la estructura del nodo principal
struct NodoPrincipal
{
    int valor;
    int num_vehiculos;
    NodoSecundario *primer_vehiculo;
    NodoSecundario *ultimo_vehiculo;
    NodoPrincipal *siguiente;
    NodoPrincipal *anterior;
};

// Función para insertar un nuevo nodo principal en la lista
void insertarNodoPrincipal(NodoPrincipal *&cabeza, int valor)
{
    NodoPrincipal *nuevoNodo = new NodoPrincipal;
    nuevoNodo->valor = valor;
    nuevoNodo->num_vehiculos = 0;
    nuevoNodo->primer_vehiculo = nullptr;
    nuevoNodo->ultimo_vehiculo = nullptr;
    nuevoNodo->siguiente = cabeza;
    nuevoNodo->anterior = nullptr;
    if (cabeza != nullptr)
    {
        cabeza->anterior = nuevoNodo;
    }
    cabeza = nuevoNodo;
}

// Función para insertar un nuevo nodo secundario en la lista enlazada secundaria de un nodo principal dado
void insertarNodoSecundario(NodoPrincipal *nodoPrincipal, int valor)
{
    NodoSecundario *nuevoNodo = new NodoSecundario;
    nuevoNodo->valor = valor;
    nuevoNodo->posicion = 0;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->anterior = nullptr;
    if (nodoPrincipal->primer_vehiculo == nullptr)
    {
        nodoPrincipal->primer_vehiculo = nuevoNodo;
        nodoPrincipal->ultimo_vehiculo = nuevoNodo;
    }
    else
    {
        nuevoNodo->anterior = nodoPrincipal->ultimo_vehiculo;
        nodoPrincipal->ultimo_vehiculo->siguiente = nuevoNodo;
        nodoPrincipal->ultimo_vehiculo = nuevoNodo;
    }
    nodoPrincipal->num_vehiculos++;
}

// Función para agregar carriles a la lista enlazada secundaria de cada nodo principal
void agregarCarriles(NodoPrincipal *cabeza)
{
    NodoPrincipal *nodoActual = cabeza;
    while (nodoActual != nullptr)
    {
        int num_carriles = sqrt(nodoActual->num_vehiculos);
        NodoSecundario *vehiculoActual = nodoActual->primer_vehiculo;
        int posicion = 1;
        while (vehiculoActual != nullptr)
        {
            vehiculoActual->posicion = posicion;
            for (int i = 0; i < num_carriles; i++)
            {
                insertarNodoSecundario(nodoActual, 0);
            }
            vehiculoActual = vehiculoActual->siguiente;
            posicion++;
        }
        nodoActual = nodoActual->siguiente;
    }
}

void dibujarPista(NodoPrincipal *cabeza)
{
    // Limpiar la consola
    system("cls");

    // Definir los caracteres para dibujar los carriles y la línea central
    char carril = '|';
    char lineaCentral = '-';

    // Recorrer la lista enlazada secundaria de cada nodo principal
    NodoPrincipal *actual = cabeza;
    while (actual != nullptr)
    {
        NodoSecundario *actualSecundario = actual->secundario;
        while (actualSecundario != nullptr)
        {
            // Dibujar los carriles
            for (int i = 0; i < actualSecundario->carriles; i++)
            {
                cout << carril;
            }
            cout << endl;

            // Dibujar la línea central
            for (int i = 0; i < actualSecundario->carriles; i++)
            {
                cout << lineaCentral;
            }
            cout << endl;

            // Dibujar los vehículos
            for (int i = 0; i < actualSecundario->vehiculos; i++)
            {
                cout << "&";
                cout << "*";
                cout << "+"; // aqui deberiamos agregar los vehiculos con su signo dependiendo el que elija la persona
            }
            cout << endl;

            actualSecundario = actualSecundario->siguiente;
        }

        actual = actual->siguiente;
    }
}

// Función para imprimir la lista enlazada completa con la posicion de los carros
void imprimirLista(NodoPrincipal *cabeza)
{
    NodoPrincipal *nodoActual = cabeza;
    while (nodoActual != nullptr)
    {
        cout << "Nodo principal: " << nodoActual->valor << endl;
        NodoSecundario *vehiculoActual = nodoActual->primer_vehiculo;
        while (vehiculoActual != nullptr)
        {
            cout << "Vehiculo: " << vehiculoActual->valor << " - Posicion: " << vehiculoActual->posicion << endl;
            vehiculoActual = vehiculoActual->siguiente;
        }
        nodoActual = nodoActual->siguiente;
    }
}

int main()
{
    NodoPrincipal *cabeza = nullptr;
    insertarNodoPrincipal(cabeza, 1);
    insertarNodoPrincipal(cabeza, 2);
    insertarNodoPrincipal(cabeza, 3);
    insertarNodoPrincipal(cabeza, 4);
    insertarNodoPrincipal(cabeza, 5);
    insertarNodoSecundario(cabeza, 10);
    insertarNodoSecundario(cabeza, 20);
    insertarNodoSecundario(cabeza, 30);
    insertarNodoSecundario(cabeza, 40);
    insertarNodoSecundario(cabeza, 50);
    insertarNodoSecundario(cabeza, 60);
    insertarNodoSecundario(cabeza, 70);
    insertarNodoSecundario(cabeza, 80);
    insertarNodoSecundario(cabeza, 90);
    insertarNodoSecundario(cabeza, 100);
    dibujarPista(cabeza);
    agregarCarriles(cabeza);
    imprimirLista(cabeza);
    return 0;
}