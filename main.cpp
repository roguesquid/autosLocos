#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void menuPrincipal()
{
  int opcion;
  bool repetir = true;

  do
  {
    system("cls");
    cout << "" << endl;
    cout << "\t   ___       __           __                   " << endl;
    cout << "\t  / _ |__ __/ /____  ___ / /  ___  _______  ___" << endl;
    cout << "\t / __ / // / __/ _ \\(_-</ /__/ _ \\/ __/ _ \\(_-<" << endl;
    cout << "\t/_/ |_\\_,_/\\__/\\___/___/____/\\___/\\__/\\___/___/" << endl;

    cout << "\n\n\t\t\tMENU PRINCIPAL" << endl;
    cout << "\t\t\t--------------" << endl;
    cout << "\n\t1. Aplicacion de gestion de vehiculos" << endl;
    cout << "\t2. Aplicacion de simulacion de carreras" << endl;
    cout << "\t0. SALIR" << endl;

    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      break;

    case 2:
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}

int main()
{
  menuPrincipal();
  return 0;
}