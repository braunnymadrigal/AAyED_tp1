#pragma once

#include "algArbol.hh"

class Interfaz {
public:
    void pruebas();
    void probarOps(Arbol *&arbol);
    void probarAlg(Arbol *&arbol);
    void mostrarOperadoresArbol();
    void mostrarAlgoritmosArbol();
    void bienvenida();
    int getOpcion();
    void mostrarManual();
};
