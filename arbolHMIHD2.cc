#include "arbolHMIHD2.hh"
#include <iostream>

Arbol::Arbol() {
	this->Iniciar();
}


Arbol::~Arbol() {
	this->Destruir();
}


void Arbol::Iniciar() {
	raiz = nullptr;
}


void Arbol::Destruir(){
	this->Vaciar();
	delete this->raiz;
}

void Arbol::Vaciar() {
	VaciarR(this->raiz, nullptr);
	this->raiz = nullptr;
}

void Arbol::VaciarR(Nodo* nodoA, Nodo* nodoP) {
	if (nodoA != nullptr){
		VaciarR(nodoA->hmi, nodoA);
		if(nodoA->hd == nodoP) {
			VaciarR(nullptr, nodoP);
		} else {
			VaciarR(nodoA->hd, nodoP);
		}
	}
	delete nodoA;
}

		
bool Arbol::Vacio() {
	bool vacia = false;
	if(raiz == nullptr) {
		vacia = true;	
	}
	return vacia;
}


void Arbol::PonerRaiz(char e) {
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->etiqueta = e;
	nuevoNodo->ultHijo = 1;
	nuevoNodo->hmi = nullptr;
	nuevoNodo->hd = nullptr;
	raiz = nuevoNodo;
}


Nodo* Arbol::AgregarHijo(Nodo* n, char e, int i) {
	Nodo* nodoPadre = n; 
	Nodo* nodoHijo = nodoPadre->hmi;
	int cantHijos = 0;
	
	while(cantHijos+1 != i && nodoHijo != nullptr){
		++cantHijos;
		if(cantHijos+1 != i && nodoHijo->hd != nullptr && nodoHijo->hd != nodoPadre){
			Nodo* nAux = nodoHijo->hd;
			if (nAux == nodoPadre) {
				nodoHijo = nullptr;
			} else {
				nodoHijo = nAux;
			}
		}
	}
	
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->etiqueta = e;
	nuevoNodo->ultHijo = 0;
	nuevoNodo->hmi = nullptr;
	nuevoNodo->hd = nullptr;
	
	if(cantHijos == 0){
		nodoPadre->hmi = nuevoNodo;
		nuevoNodo->hd = nodoHijo;
		if(nuevoNodo->hd == nullptr) {
			nuevoNodo->hd = n;
			nuevoNodo->ultHijo = 1;
		}
	}
	else{
		Nodo* aux = nodoHijo->hd;
		nodoHijo->hd = nuevoNodo;
		nuevoNodo->hd = aux;
		if(nuevoNodo->hd == nodoPadre) {
			nuevoNodo->ultHijo = 1;
			nodoHijo->ultHijo = 0;
		}
	}
	return nuevoNodo;
}


void Arbol::BorrarHoja(Nodo* nodo) {
	Nodo* nodoPadre = this->Padre(nodo);
	
	if(nodoPadre != nullptr){
		if(nodoPadre->hmi == nodo){
			nodoPadre->hmi = nodo->hd;
			if(nodo->hd == nodoPadre) {
				nodoPadre->hmi = nullptr;
			} else {
				if(nodo->hd->hd == nodoPadre) {
					nodo->hd->ultHijo = 1;
				}
			}
		}
		else{
			Nodo* hermanoIzq = nodoPadre->hmi;
            while (hermanoIzq->hd != nodo) {
                hermanoIzq = hermanoIzq->hd;
            }
			hermanoIzq->hd = nodo->hd;
			if(hermanoIzq->hd == nodoPadre) {
				hermanoIzq->ultHijo = 1;
			}
		}
	}
	else{
		this->raiz = nullptr;
	}
	
	delete nodo;
}


void Arbol::ModificarEtiqueta(Nodo* n, char e) {
	n->etiqueta = e;
}


Nodo* Arbol::Raiz() {
	return raiz;
}


Nodo* Arbol::Padre(Nodo* n) {
	Nodo* nPadre = nullptr;
	Nodo* nAct = n;
	while(nAct != nullptr && nAct->ultHijo == 0) {
		nAct = nAct->hd;
	}
	if(nAct != nullptr) {
		nPadre = nAct->hd;
	}
	return nPadre;
}


Nodo* Arbol::HijoMasIzq(Nodo* n) {
	return n->hmi;
}


Nodo* Arbol::HermanoDer(Nodo* n) {
	return n->hd;
}


char Arbol::Etiqueta(Nodo* n) {
	return n->etiqueta;
}


int Arbol::NumHijos(Nodo* n) {
	int hijos = 0;
	Nodo* nh = n->hmi;
	while(nh != nullptr && nh != n) {
		++hijos;
		nh = nh->hd;
	}
	return hijos;
}


int Arbol::NumNodos() {
	int nodos = 0;
	if(!this->Vacio()) {
		NumNodosR(this->Raiz(), nodos);
	}
	return nodos;		
}


void Arbol::NumNodosR(Nodo* n, int &nodos) {
	++nodos;
	Nodo* nAuxPadre = n;
	n = this->HijoMasIzq(n);
	while( n != nullptr) {
		NumNodosR(n, nodos);
		Nodo* nAux = this->HermanoDer(n);
		if(nAux == nAuxPadre) {
			n = nullptr;
		} else {
			n = nAux;
		}
	}
}
		
		
void Arbol::printArbol() {
	if(!this->Vacio()) {
		printArbolR(this->Raiz());
	}
	std::cout << std::endl;	
}


void Arbol::printArbolR(Nodo* n) {
	std::cout << this->Etiqueta(n) << " ";
	Nodo* nAuxPadre = n;
	n = this->HijoMasIzq(n);
	while( n != nullptr) {
		printArbolR(n);
		Nodo* nAux = this->HermanoDer(n);
		if(nAux == nAuxPadre) {
			n = nullptr;
		} else {
			n = nAux;
		}
	}	
}


Nodo* Arbol::getNodo(char etiqueta) {
    Nodo* nodo = nullptr;
    if (!this->Vacio()) {
        getNodoR(etiqueta, nodo, this->raiz);
    }

    return nodo;
}

void Arbol::getNodoR(char etiqueta, Nodo* &nodo, Nodo* nodoActual) {
    if (nodo == nullptr && nodoActual != nullptr && nodoActual->etiqueta == etiqueta) {
        nodo = nodoActual;
    } else {
    	Nodo* nAuxPadre = nodoActual;
        Nodo* nodoHijo = nodoActual->hmi;
        while (nodo == nullptr && nodoHijo != nullptr) {
            getNodoR(etiqueta, nodo, nodoHijo);
            Nodo* nAux = nodoHijo->hd;
			if(nAux == nAuxPadre) {
				nodoHijo = nullptr;
			} else {
				nodoHijo = nAux;
			}            
        }
    }
}

	
