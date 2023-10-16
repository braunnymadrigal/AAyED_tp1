#ifndef ARBOLHMIHD2_HH
#define ARBOLHMIHD2_HH

struct Nodo {
	char etiqueta;
	bool ultHijo;
	Nodo* hmi;
	Nodo* hd;
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
		void VaciarR(Nodo*,Nodo*);
		void NumNodosR(Nodo*,int &ref);
		void printArbolR(Nodo*);
		void getNodoR(char, Nodo* &n, Nodo*);	
};

#endif
