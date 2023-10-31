#include "algArbol.hh"
#include <chrono>
#include <random>
#include <ctime>

class Tiempos {
public:

void Ejecutar(); 
void CrearArbolSemiBalanceado(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
void CrearArbolUltraAncho(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);  
void CrearArbolUltraProfundo(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n); 

void TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
void TestAlgHermIzqNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
void TestOpPadreNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
//void TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes); 
//void TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
};
