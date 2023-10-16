#include <iostream>
#include "arbolHMIHD.hh"
#include "colaLSE.hh"

Arbol::Arbol(){
	this->Crear();
}

Arbol::~Arbol(){
	this->Destruir();
}

void Arbol::Crear(){
	this->raiz = nullptr;
}

void Arbol::Destruir(){
	this->Vaciar();
	delete this->raiz;
}

void Arbol::Vaciar() {
	VaciarPostOrden(this->raiz);
	this->raiz = nullptr;
}

void Arbol::VaciarPostOrden(Nodo* nodo) {
	if (nodo != nullptr){
		VaciarPostOrden(nodo->hijoIzq);
		VaciarPostOrden(nodo->hermanoDer);
	}
	delete nodo;
}


bool Arbol::Vacio(){
	return (this->raiz == nullptr);
}

void Arbol::PonerRaiz(char etiqueta){
	if (this->raiz == nullptr) {
        Nodo* nuevoNodo = new Nodo;
        nuevoNodo->etiqueta = etiqueta;
        this->raiz = nuevoNodo;
    }
}

Nodo* Arbol::AgregarHijo(Nodo* nodoPadre, char etiqueta, int lugarDelHijo){ 
	Nodo* nodoHijo = nodoPadre -> hijoIzq;
	int cantHijos = 0;
	
	while(cantHijos+1 != lugarDelHijo && nodoHijo != nullptr){
		++cantHijos;
		if(cantHijos+1 != lugarDelHijo && nodoHijo ->hermanoDer != nullptr){
			nodoHijo = nodoHijo ->hermanoDer;
		}
	}
	
	 //Crear nodo
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->etiqueta = etiqueta;
	
	if(cantHijos == 0){
		nodoPadre -> hijoIzq = nuevoNodo;
		nuevoNodo -> hermanoDer = nodoHijo;
	}
	else{
		Nodo* aux = nodoHijo -> hermanoDer;
		nodoHijo -> hermanoDer = nuevoNodo;
		nuevoNodo -> hermanoDer = aux;
	}
	
	return nuevoNodo;
}


void Arbol::BorrarHoja(Nodo* nodo){
	Nodo* nodoPadre = this->Padre(nodo);
	
	if(nodoPadre != nullptr){
		if(nodoPadre -> hijoIzq == nodo){
			nodoPadre->hijoIzq = nodo -> hermanoDer;
		}
		else{
			Nodo* hermanoIzq = nodoPadre->hijoIzq;
            while (hermanoIzq->hermanoDer != nodo) {
                hermanoIzq = hermanoIzq->hermanoDer;
            }
			hermanoIzq->hermanoDer = nodo->hermanoDer;
		}
	}
	else{
		this->raiz = nullptr;
	}
	
	delete nodo;
}

Nodo* Arbol::Padre(Nodo* nodo){
	Nodo* nodoPadre = nullptr;
	if (!this->Vacio()) {
        PadrePreOrdenR(nodo, nodoPadre, this->raiz);
    }

    return nodoPadre;
	
}

char Arbol::Etiqueta(Nodo* nodo){
	return nodo -> etiqueta;
}

void Arbol::PadrePreOrdenR(Nodo* nodo, Nodo* &nodoPadre, Nodo* nodoActual) {
	Nodo* nodoHijo = nodoActual -> hijoIzq;
	
	while (nodoPadre == nullptr && nodoHijo != nullptr) {
		if(nodoHijo == nodo){
			nodoPadre = nodoActual;
		}
		else{
			PadrePreOrdenR(nodo, nodoPadre, nodoHijo);
			nodoHijo = nodoHijo->hermanoDer;
		}
	}
}


void Arbol::ModificarEtiqueta(Nodo* nodo, char etiqNueva){
	nodo->etiqueta = etiqNueva;
}

Nodo* Arbol::Raiz(){
	return this->raiz;
}

Nodo* Arbol::HijoMasIzq(Nodo* nodo){
	return nodo->hijoIzq;
}

Nodo* Arbol::HermanoDer(Nodo* nodo){
	return nodo->hermanoDer;
}

int Arbol::NumNodos(){
	int cantNodos = 0;
	if (!this->Vacio()) {
		++cantNodos;
        numNodosPreOrdenR(this->raiz, cantNodos);
    }

    return cantNodos;
	
}
void Arbol::numNodosPreOrdenR(Nodo* nodo, int& cantNodos) {
	Nodo* nodoHijo = nodo -> hijoIzq;
	
	while (nodoHijo != nullptr) {
		++cantNodos;
		numNodosPreOrdenR(nodoHijo, cantNodos);
		nodoHijo = nodoHijo->hermanoDer;
	}
}

int Arbol::NumHijos(Nodo* nodo){
	int cantHijos = 0;
	if (!this->Vacio()) {
        numHijosPreOrdenR(nodo, cantHijos);
    }

    return cantHijos;
	
}
void Arbol::numHijosPreOrdenR(Nodo* nodo, int& cantHijos) {
	Nodo* nodoHijo = nodo -> hijoIzq;
	
	while (nodoHijo != nullptr) {
		++cantHijos;
		nodoHijo = nodoHijo->hermanoDer;
	}
}


//Funciones Auxiliares

//Esta funcion se va a encargar de traducir de etiquetas a nodos
Nodo* Arbol::getNodo(char etiqueta) {
    Nodo* nodo = nullptr;
    if (!this->Vacio()) {
        getNodoPreOrdenR(etiqueta, nodo, this->raiz);
    }

    return nodo;
}

void Arbol::getNodoPreOrdenR(char etiqueta, Nodo* &nodo, Nodo* nodoActual) {
    if (nodo == nullptr && nodoActual != nullptr && nodoActual->etiqueta == etiqueta) {
        nodo = nodoActual;
    } else {
        Nodo* nodoHijo = nodoActual->hijoIzq;
        while (nodo == nullptr && nodoHijo != nullptr) {
            getNodoPreOrdenR(etiqueta, nodo, nodoHijo);
            nodoHijo = nodoHijo->hermanoDer;
        }
    }
}

void Arbol::printArbol() {
    if(!this->Vacio()) {
        printArbolPreOrdenR(this->raiz);
    }
	std::cout << std::endl;
}

void Arbol::printArbolPreOrdenR(Nodo* nodoActual) {
    std::cout << nodoActual -> etiqueta << " "; 
	Nodo* nodoHijo = nodoActual->hijoIzq;
	while(nodoHijo != nullptr) {
		printArbolPreOrdenR(nodoHijo);
		nodoHijo = nodoHijo->hermanoDer;
	}
}