#include <iostream>
#ifndef ARBOLHMIHD_HH
#define ARBOLHMIHD_HH

struct Nodo{
	char etiqueta;
	Nodo* hijoIzq = nullptr;
	Nodo* hermanoDer = nullptr;
};

class Arbol{
	private:
		Nodo* raiz;
		
	public:
		Arbol();
		~Arbol();
		
		void Crear();
		void Destruir();
		
		void Vaciar();
		void VaciarPostOrden(Nodo*);
		
		bool Vacio();
		void PonerRaiz(char);
		Nodo* AgregarHijo(Nodo*, char, int); //requiere un int con la posicion del nodo valida, es decir un numero entre 1-cantHijos + 1
		
		void BorrarHoja(Nodo*);
		
		void ModificarEtiqueta(Nodo*, char);
		
		Nodo* Raiz();
		
		Nodo* Padre(Nodo*);
		
		char Etiqueta(Nodo*);
		
		void PadrePreOrdenR(Nodo*, Nodo*&, Nodo*); 
		
		Nodo* HijoMasIzq(Nodo*);
		Nodo* HermanoDer(Nodo*);
		
		int NumNodos();
		void numNodosPreOrdenR(Nodo*, int&);
		
		int NumHijos(Nodo*);
		void numHijosPreOrdenR(Nodo*, int&);
		
		//funciones auxiliares
		void printArbol();
		void printArbolPreOrdenR(Nodo*);
		
		Nodo* getNodo(char);
		void getNodoPreOrdenR(char, Nodo*&, Nodo*);
		
};

#endif
