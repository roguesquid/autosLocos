#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include "../appVehiculos/ListaVehiculos.h"

void movimiento(tVehiculoPtr vehiculo, int y, int obstaculo, int tipoObstaculo)
{
  bool finJuego = false;
  int x = 20;
  int maxPantallaX = 100;
  while (!finJuego)
  {
    int speed = velocidad(vehiculo);
    if (x <= maxPantallaX)
    {
      // efecto obstaculo
      if ((x - 20) == obstaculo)
      {
        int esperar;
        if (tipoObstaculo == 1)
        {
          esperar = (speed * bomba(vehiculo) * 10) / 2;
        }
        else if (tipoObstaculo == 2)
        {
          esperar = (speed * piedra(vehiculo) * 10) / 2;
        }
        else if (tipoObstaculo == 3)
        {
          esperar = (speed * liquido(vehiculo) * 10) / 2;
        }

        Sleep(esperar);
      }
      COORD coord;
      coord.X = x;
      coord.Y = y;
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
      cout << vehiculo->simbolo;
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

int tiempo(tVehiculoPtr vehiculo, int y, int obstaculo, int tipoObstaculo)
{
  clock_t tiempoInicio, tiempoFin;
  double tiempo;
  tiempoInicio = clock();

  movimiento(vehiculo, y, obstaculo, tipoObstaculo);

  tiempoFin = clock();

  tiempo = ((double)(tiempoFin - tiempoInicio)) / CLOCKS_PER_SEC;

  return tiempo;
}
