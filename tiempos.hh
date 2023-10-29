#include "algArbol.hh"
#include <chrono>

class Tiempos {
public:

void Ejecutar();
void CrearArbolSemiBalanceado(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
void CrearArbolUltraAlto(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);  
void CrearArbolUltraProfundo(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n); 
double* TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
double* TestAlgHermIzqNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
double* TestOpPadreNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
//double* TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes); //si no ocupa los nodos obviamente no pase el vector como param
//double* TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
};
