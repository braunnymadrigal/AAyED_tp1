#ifndef Arbol_HH
#define Arbol_HH

#include <iostream>

struct Nodo{
	char etiqueta;
	int padre;
};

class Arbol{
	private:
		Nodo arbol[20];
		int raiz;
		int ultimo;
		int tamArbol = 20;
		
	public:
		Arbol();
		~Arbol();
		
		void Iniciar();
		void Destruir();
		void Vaciar();
		bool Vacio();
		void PonerRaiz(char);
		Nodo AgregarHijo(int, char, int); //requiere un int con la posicion del nodo valida, es decir un numero entre 1-cantHijos + 1
		void BorrarHoja(int);
		void ModificarEtiqueta(int, char);
		int Raiz();
		int Padre(int);
		int HijoMasIzq(int);
		int HermanoDer(int);
		char Etiqueta(int);
		
		int NumNodos();
		int NumHijos(int);
		
		
		//funciones auxiliares
		void printArbol();
		int getNodo(char);
		void abrirCampo(int);
		void cerrarCampo(int);
};

#endif