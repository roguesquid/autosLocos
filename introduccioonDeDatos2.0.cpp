#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaVehiculos.h"

using namespace std;

tVehiculoPtr listaAutos = NULL;
tVehiculoPtr ultimoVehiculo = NULL;

tVehiculoPtr llenarNodo(tVehiculoPtr nuevoVehiculo){
    ifstream archivo("Autos.txt");
    string linea;
    while (!archivo.eof()){
        getline(archivo, linea);
        if (linea != "|"){
            istringstream ss(linea);
            ss >> nuevoVehiculo->nombreEspanol >> nuevoVehiculo->nombreIngles >>
            nuevoVehiculo->nombreConductores >> nuevoVehiculo->tipoCaucho >>
            nuevoVehiculo->tamanoDelCaucho >> nuevoVehiculo->velocidad >>
            nuevoVehiculo->tiempoDeDisminucionVelocidad >> nuevoVehiculo->simbolo;
            nuevoVehiculo->prox = NULL;
        }
    }
    archivo.close();
    return nuevoVehiculo;
} 

tVehiculoPtr crearListaAutos(){
    ifstream archivo("Autos.txt");
    while (!archivo.eof()){
        tVehiculoPtr nuevoVehiculo = new tVehiculo;
        nuevoVehiculo = llenarNodo(nuevoVehiculo);
        if (listaAutos == NULL){
            listaAutos = nuevoVehiculo;
            ultimoVehiculo = nuevoVehiculo;
        } else {
            ultimoVehiculo->prox = nuevoVehiculo;
        }
}
}

int main(){
    tVehiculoPtr listaVehiculos = crearListaAutos();
    if (listaVehiculos != NULL){
        tVehiculoPtr nodo = listaVehiculos;
        while (nodo != NULL){
            cout <<nodo->nombreEspanol << endl;
            cout << nodo->nombreIngles <<endl;
            cout << nodo->nombreConductores << endl;
            cout << nodo->tipoCaucho << endl;
            cout << nodo->tamanoDelCaucho << endl;
            cout << nodo->velocidad << endl;
            cout << nodo->tiempoDeDisminucionVelocidad << endl;
            cout << nodo->simbolo << endl;
            nodo = nodo->prox;
        }
        nodo = nodo->prox;
    }
    else {
        cout << "La lista de vehiculos esta vacia" << endl;
    }
    return 0;
}