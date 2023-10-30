#include "algArbol.hh"
#include <chrono>

class Tiempos {
public:

void Ejecutar(); //este imprime PEOR Y PROM tiempo
//NO TIENE SENTIDO SACAR MEJOR TIEMPO
void CrearArbolSemiBalanceado(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);
void CrearArbolUltraAncho(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n);  
void CrearArbolUltraProfundo(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n); 

//importante : los metodos test imprimen el peor y prom tiempo adentro del propio metodo

void TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
//void TestAlgHermIzqNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
//void TestOpPadreNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
//void TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes); 
//void TestAlgRandomAlg(Arbol *&A, std::vector<Arbol::Node> *&vecNodes);
};
