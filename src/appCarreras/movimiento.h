#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "../appVehiculos/ListaVehiculos.h"

void movimiento(tVehiculoPtr vehiculo, int y)
{
  bool finJuego = false;
  int x = 20;
  int maxPantallaX = 100;
  while (!finJuego)
  {
    if (x <= maxPantallaX)
    {
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      cout << vehiculo->simbolo;
      int speed = velocidad(vehiculo);
      Sleep(speed);
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      cout << " ";
      x++;
    }
    else
    {
      finJuego = true;
    }
  }
}

int tiempo(tVehiculoPtr vehiculo, int y)
{
  clock_t tiempoInicio, tiempoFin;
  double tiempo;
  tiempoInicio = clock();

  movimiento(vehiculo, y);

  tiempoFin = clock();

  tiempo = ((double)(tiempoFin - tiempoInicio)) / CLOCKS_PER_SEC;

  return tiempo;
}
