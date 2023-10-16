#include <iostream>
#include "arbolASP.hh"

Arbol::Arbol(){
	this->Iniciar();
}

 
Arbol::~Arbol() { //Destroy the tree
	this->Destruir();
}


void Arbol::Iniciar() {
	this->raiz = -1;
	this->ultimo = -1;
}

void Arbol::Destruir(){
	
}

void Arbol::Vaciar() { //"Vaciar" only puts the values in -1
	this->raiz = -1;
	this->ultimo = -1;
}


bool Arbol::Vacio(){ //if "raiz == -1" it means that there's not a root, so it empty
	return (raiz == -1);
}


void Arbol::PonerRaiz(char etiqueta){
	Nodo nuevoNodo;
	nuevoNodo.etiqueta = etiqueta;
	nuevoNodo.padre = -1;
	
	this->arbol[0] = nuevoNodo;
	this->raiz = 0;
	this->ultimo = 0;
}

//Todos los getNodo, se van a realizar en la interfaz, es decir, los metodos, si se van a manipular por nodos
Nodo Arbol::AgregarHijo(int nodoPadre, char etiqueta, int lugarDelHijo){
	int cantHijos = 0;
	
	//Busca el lugar donde se deberia de agregar el nodo, para respetar el orden de los hijos.	
	int i = nodoPadre+1;
	while((cantHijos + 1) != lugarDelHijo && i <= this->tamArbol){
		if(this->arbol[i].padre == nodoPadre){
			++cantHijos;
		}
		++i;
	}
	
	this->abrirCampo(i);
	//Crear y agregar nodo
	Nodo nuevoNodo;
	nuevoNodo.etiqueta = etiqueta;
	nuevoNodo.padre = nodoPadre;
	arbol[i] = nuevoNodo;
	
	++this->ultimo;
	
	return nuevoNodo;
}


void Arbol::BorrarHoja(int nodo){	
	this->cerrarCampo(nodo);
	--this->ultimo;
}

void Arbol::ModificarEtiqueta(int nodo, char etiqNueva){
	this->arbol[nodo].etiqueta = etiqNueva; 
}

int Arbol::Raiz(){
	return this->raiz;
}

char Arbol::Etiqueta(int nodo){
	return this->arbol[nodo].etiqueta;
}

int Arbol::Padre(int nodo){
	return this->arbol[nodo].padre;
}

int Arbol::HijoMasIzq(int nodoPadre){
	int hijoIzq = -1;
	
	int i = nodoPadre + 1;
	while(this->arbol[i].padre != nodoPadre && i <= this->ultimo){
		++i;
	}
	
	if(i < this->ultimo+1){
		hijoIzq = i;
	}

	return hijoIzq;
}

int Arbol::HermanoDer(int nodo){
	int hermDer = -1;
	
	int padre = this->arbol[nodo].padre;
	int i = nodo + 1;
	while(this->arbol[i].padre != padre && i <= this->ultimo){
		++i;
	}
	
	if(i != this->ultimo+1){
		hermDer = i;
	}

	return hermDer;
}

int Arbol::NumNodos(){
	return this->ultimo+1;
}

int Arbol::NumHijos(int padre){
	int hijos = 0;
	
	for(int i = padre+1; i <= this->ultimo; ++i){
		if(this->arbol[i].padre == padre){
			++hijos;
		}
	}
	
	return hijos;
}

//funciones auxiliares
void  Arbol::printArbol(){
	for(int i = this->raiz; i <= ultimo; ++i){
		std::cout << arbol[i].etiqueta << " "; 
	}
}

//Esta funcion se va a encargar de traducir de etiquetas a nodos
int Arbol::getNodo(char etiqueta){
	int nodo = this->raiz;
	
	while(this->arbol[nodo].etiqueta != etiqueta && nodo <= this->tamArbol){
		++nodo;
	}
	
	return nodo;
}

void Arbol::abrirCampo(int i){
	int nodoAux = this->ultimo + 1;
	while(nodoAux > i){
		this->arbol[nodoAux] = this->arbol[nodoAux-1];
		--nodoAux;
	}
}

void Arbol::cerrarCampo(int i){
	while(i < this->ultimo){
		this->arbol[i] = this->arbol[i+1];
		++i;
	}
}

