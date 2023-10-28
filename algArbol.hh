#pragma once

#include <iostream>
#include <limits>
#include <vector>

#include "colaLSE.hh"
#include "arbolASP.hh"
//#include "arbolLSE.hh"
//#include "arbolHMIHD.hh"
//#include "arbolHMIHD2.hh"

class Algoritmos {
public:
  Arbol::Node HermanoIzq(Arbol *A, Arbol::Node n);

  bool EtiqRepetidas(Arbol *A);

  int AlturaNodoPreOrden(Arbol *A, Arbol::Node n);

  int ProfundidadNodo(Arbol *A, Arbol::Node n);

  int CantNivelesPreOrden(Arbol *A);

  int CantNivelesPorNiveles(Arbol *A);

  void ListarIesimoNivel(Arbol *A, int i);

  void ListarPreOrden(Arbol *A);

  void ListarPorNiveles(Arbol *A);

  Arbol::Node BuscarEtiq(Arbol *A, char e);

  void BorrarSubArbol(Arbol *&A, Arbol::Node n);

  void ListarHijos(Arbol *A, Arbol::Node n);

private:
  void AlturaNodoPreOrdenR(Arbol *A, Arbol::Node n, int &altura, int k);
  
  void CantNivelesPreOrdenR(Arbol *A, Arbol::Node n, int &niveles, int k);
  
  void ListarIesimoNivelR(Arbol *A, Arbol::Node n, int i, int nivAct);
  
  void ListarPreOrdenR(Arbol *A, Arbol::Node n);
  
  void BorrarSubArbolR(Arbol *&A, Arbol::Node nh);
  
  void ProfundidadNodoR(Arbol *A, Arbol::Node n, Arbol::Node nU, int &profundidad, int k);
};
