#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ListaVehiculos.h"

using namespace std;

tVehiculoPtr listaAutos = NULL;
tVehiculoPtr ultimo = NULL;

tVehiculoPtr extraerDatos(){
    ifstream archivo("Autos.txt");
    tVehiculoPtr listaVehiculos = NULL;
    tVehiculoPtr ultimoVehiculo = NULL;
    while (!archivo.eof()){
        string linea;
        getline(archivo, linea);
        if (linea != "|"){
            tVehiculoPtr nuevoVehiculo = new tVehiculo;
            istringstream ss(linea);
            ss >> nuevoVehiculo->nombreEspanol >> nuevoVehiculo->nombreIngles >>
            nuevoVehiculo->nombreConductores >> nuevoVehiculo->tipoCaucho >>
            nuevoVehiculo->tamanoDelCaucho >> nuevoVehiculo->velocidad >>
            nuevoVehiculo->tiempoDeDisminucionVelocidad >> nuevoVehiculo->simbolo;
            nuevoVehiculo->prox = NULL;
            if (listaVehiculos == NULL){
                listaVehiculos = nuevoVehiculo;
            } else {
                ultimoVehiculo->prox = nuevoVehiculo;
            }
            ultimoVehiculo = nuevoVehiculo;
        }
    }
    archivo.close();
    return listaVehiculos;
} 

int main(){
    tVehiculoPtr listaVehiculos = extraerDatos();
    if (listaVehiculos != NULL){
        cout << listaVehiculos->nombreEspanol << endl;
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
    }
    else {
        cout << "La lista de vehiculos esta vacia" << endl;
    }
    return 0;
}