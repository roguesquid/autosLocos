#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void menuGestionDeVehiculos()
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

    cout << "\n\n\t\t\tMENU GESTION DE VEHICULOS" << endl;
    cout << "\t\t\t-------------------------" << endl;
    cout << "\n\t1. Agregar vehiculo" << endl;
    cout << "\t2. Modificar vehiculo" << endl;
    cout << "\t3. Eliminar vehiculo" << endl;
    cout << "\t4. Consultar vehiculo" << endl;
    cout << "\t5. Listar vehiculo" << endl;
    cout << "\t0. REGRESAR" << endl;

    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      break;

    case 2:
      break;

    case 3:
      break;

    case 4:
      break;

    case 5:
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}
void menuSimulacionDeCarreras()
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

    cout << "\n\n\t\t\tMENU SIMULACION DE CARRERAS" << endl;
    cout << "\t\t\t-------------------------" << endl;
    cout << "\n\t1. " << endl;
    cout << "\t0. REGRESAR" << endl;

    cout << "\n\tIngrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
      break;

    case 0:
      repetir = false;
      break;
    }
  } while (repetir);
}

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
      menuGestionDeVehiculos();
      break;

    case 2:
      menuSimulacionDeCarreras();
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