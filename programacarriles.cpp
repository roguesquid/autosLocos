#include <iostream>
#include <cmath> // esta libreria es para la función sqrt que calcula raiz cuadrada, podemos usarla?

using namespace std;

// algunos comentarios.
// debemos usar las variables que tiene luis en el programa y las que agregue Levin, pero esta seria una estructura y funciones
// Faltaria llamar las funciones para poner los carros creados por luis en los carriles.
// pensaba en agregar una bandera o algo de finish al final
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

struct Obstaculo
{ // nos faltaria agregar lo del archivo con los simbolos de los obstaculos y los calculos
    int posicion;
    Obstaculo *siguiente;
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

void generarObstaculo(Obstaculo *&cabeza, int longitudPista)
{
    // Generar una posición aleatoria para el obstáculo
    int posicion = rand() % longitudPista * 1000;

    // Crear un nuevo obstáculo
    Obstaculo *nuevoObstaculo = new Obstaculo;
    nuevoObstaculo->posicion = posicion;
    nuevoObstaculo->siguiente = nullptr;

    // Agregar el obstáculo a la lista
    if (cabeza == nullptr)
    {
        cabeza = nuevoObstaculo;
    }
    else
    {
        Obstaculo *actual = cabeza;
        while (actual->siguiente != nullptr)
        {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoObstaculo;
    }
}

void dibujarPista(NodoPrincipal *cabeza, int longitudPista, Obstaculo *cabezaObstaculos)
{
    // Limpiar la consola
    system("cls");

    // Definir los caracteres para dibujar los carriles y la línea central
    char carril = '|';
    char lineaCentral = '-';

    // Definir la posición de la meta
    int meta = longitudPista * 1000;

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

            // Dibujar las líneas cada kilómetro, cada linea dibujada equivale a 1 km, pista de 80km en total
            for (int i = 0; i < longitudPista; i++)
            {
                if ((i + 1) % 10 == 0)
                {
                    cout << "+";
                }
                else
                {
                    cout << "-";
                }

                // Dibujar los obstáculos
                Obstaculo *actualObstaculo = cabezaObstaculos;
                while (actualObstaculo != nullptr)
                {
                    if (actualObstaculo->posicion == (i + 1) * 1000)
                    {
                        cout << "O"; // aqui pondremos los diferentes obstaculos que hay que utilizar
                    }
                    actualObstaculo = actualObstaculo->siguiente;
                }
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
                cout << "V"; // aqui dibujamos los vehiculos con los diferentes simbolos
            }
            cout << endl;

            // Verificar si se llegó a la meta
            if (actualSecundario->posicion >= meta)
            {
                cout << "¡Los vehículos han llegado a la meta!" << endl;
            }

            actualSecundario = actualSecundario->siguiente;
        }

        actual = actual->siguiente;
    }
}

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

void simularCarrera(NodoPrincipal *cabeza)
{
    // Definir la longitud de la pista y la cantidad de obstáculos
    int longitudPista = 80; // puse longitud de 80km
    int numObstaculos = 5;

    // Generar los obstáculos de manera aleatoria
    Obstaculo *cabezaObstaculos = nullptr;
    for (int i = 0; i < numObstaculos; i++)
    {
        generarObstaculo(cabezaObstaculos, longitudPista);
    }

    // Simular la carrera
    while (true)
    {
        // Dibujar la pista de carreras
        dibujarPista(cabeza, longitudPista, cabezaObstaculos);

        // Falta mover los vehículos

        // Falta verificar si los vehículos chocan con los obstáculos
    }
}

// Función para imprimir la lista enlazada completa con la posicion de los carros

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
    // falta llamar a las otras funciones necesarias.s
    return 0;
}