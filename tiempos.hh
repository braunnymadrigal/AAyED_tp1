#include "algArbol.hh"
#include <chrono>
#include <random>
#include <ctime>
#include <iomanip>

class Tiempos {
public:

void Ejecutar(); 
void CrearArbolSemiBalanceado(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
void CrearArbolUltraAncho(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);  
void CrearArbolUltraProfundo(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n); 

void TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
void TestAlgHermIzqNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
void TestOpPadreNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
void TestAlgAlturaNodoPO(Arbol *&A, std::vector<Arbol::Node> *&vecNodes); 
void TestAlgListarHijos(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
};
