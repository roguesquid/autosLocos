#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct
{
  string nombreEspanol;
  string nombreIngles;
  string nombreConductores[2];
  string tipoCaucho;
  string tamañoDelCaucho;
  string velocidad;
  int tiempoDeDisminucionVelocidad;
} tvehiculo;