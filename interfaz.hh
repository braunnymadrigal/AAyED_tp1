#pragma once

#include <iostream>
#include <limits>
#include <memory>

#include "colaLSE.hh"
//#include "arbolASP.hh"
#include "arbolLSE.hh"
//#include "arbolHMIHD.hh"
//#include "arbolHMIHD2.hh"

class Interfaz {
public:
  void pruebas();
  void probarOps(Arbol *&arbol);
  // void probarAlg(Arbol*& arbol);
  void mostrarOperadoresArbol();
  void bienvenida();
  int getOpcion();
  void mostrarManual();
};
