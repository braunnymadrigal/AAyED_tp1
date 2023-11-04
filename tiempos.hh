#include "algArbol.hh"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <random>

class Tiempos {
public:
    void Ejecutar();
    void CrearArbolSemiBalanceado(
        Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
    void
    CrearArbolUltraAncho(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
    void CrearArbolUltraProfundo(
        Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);

    void TestAlgEtiqRepetidas(Arbol *A);
    void TestAlgListarHijos(Arbol *A, std::vector<Arbol::Node> *vecNodes);
    void TestAlgProfundidadNodo(Arbol *A, std::vector<Arbol::Node> *vecNodes);
    void TestAlgBorrarSubArbol(Arbol *A, std::vector<Arbol::Node> *vecNodes);
};
