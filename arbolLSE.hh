#ifndef ARBOLLSE_HH
#define ARBOLLSE_HH

struct SubLista;

struct Nodo {
	char etiqueta;
	Nodo* abajo;
	SubLista* sublista;
};


struct SubLista {
	SubLista* siguiente;
	Nodo* nodoOrg;
};


class Arbol {
	public:
	
		//ops basicos
		Arbol();
		~Arbol();
		void Iniciar();
		void Destruir();
		void Vaciar();
		bool Vacio();
		void PonerRaiz(char);
		Nodo* AgregarHijo(Nodo*,char,int);
		void BorrarHoja(Nodo*);
		void ModificarEtiqueta(Nodo*,char);
		Nodo* Raiz();
		Nodo* Padre(Nodo*);
		Nodo* HijoMasIzq(Nodo*);
		Nodo* HermanoDer(Nodo*);
		char Etiqueta(Nodo*);
		int NumHijos(Nodo*);
		int NumNodos();
		
		
		//auxs
		void printArbol();
		Nodo* getNodo(char);		
		
	private:
		Nodo* raiz;	
};

#endif
