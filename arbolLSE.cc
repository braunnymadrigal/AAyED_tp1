#include "arbolLSE.hh"
#include <iostream>

Arbol::Arbol() {
	Iniciar();
}


Arbol::~Arbol() {
	Destruir();
}


void Arbol::Iniciar() {
	raiz = nullptr;
}


void Arbol::Destruir() {
	while(raiz != nullptr) {
		Nodo* raizAux = raiz;
		SubLista* subL = raizAux->sublista;
		while(subL != nullptr) {
			SubLista* subLAux = subL;
			subL = subL->siguiente;
			delete subLAux;
		}
		raiz = raiz->abajo;
		delete raizAux;
	}
}


void Arbol::Vaciar() {
	while(raiz != nullptr) {
		Nodo* raizAux = raiz;
		SubLista* subL = raizAux->sublista;
		while(subL != nullptr) {
			SubLista* subLAux = subL;
			subL = subL->siguiente;
			subLAux = nullptr;
		}
		raiz = raiz->abajo;
		raizAux = nullptr;
	}
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
	nuevoNodo->abajo = nullptr;
	nuevoNodo->sublista = nullptr;
	raiz = nuevoNodo;
}


Nodo* Arbol::AgregarHijo(Nodo* n,char e, int i) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->etiqueta = e;
    nuevoNodo->abajo = nullptr;
    nuevoNodo->sublista = nullptr;

    Nodo* nodoAct = n;
    while (nodoAct->abajo != nullptr) {
        nodoAct = nodoAct->abajo;
    }
    nodoAct->abajo = nuevoNodo;
	
	
	SubLista* nuevoSub = new SubLista;
	nuevoSub->siguiente = nullptr;
	nuevoSub->nodoOrg = nodoAct->abajo;
	
    if (i == 1) {
        nuevoSub->siguiente = n->sublista;
        n->sublista = nuevoSub;
    } else {
		SubLista* actual = n->sublista;
		int j = 1;

		while (j < i-1) {
		    actual = actual->siguiente;
		    ++j;
		}

		nuevoSub->siguiente = actual->siguiente;
		actual->siguiente = nuevoSub;	
	}

    return nuevoNodo; 
}


void Arbol::BorrarHoja(Nodo* n) {
 
 	bool borrado = false;
    Nodo* nodoAct = raiz;
    while (!borrado && nodoAct != nullptr) {
        SubLista* subAnt = nullptr;
        SubLista* subAct = nodoAct->sublista;
        while (! borrado && subAct != nullptr) {
            if (subAct->nodoOrg == n) {
                if (subAnt == nullptr) {
                    nodoAct->sublista = subAct->siguiente;
                } else {
                    subAnt->siguiente = subAct->siguiente;
                }
                delete subAct;
                borrado = true;
            } else {
                subAnt = subAct;
                subAct = subAct->siguiente;
            }
        }
        nodoAct = nodoAct->abajo;
    }

    
    borrado = false;
    Nodo* nodoAnt = nullptr;
    nodoAct = raiz;
    while (!borrado && nodoAct != nullptr) {
        if (nodoAct == n) {
            if (nodoAnt == nullptr) {
                raiz = nodoAct->abajo;
            } else {
                nodoAnt->abajo = nodoAct->abajo;
            }
            delete nodoAct;
            borrado = true;
        } else {
            nodoAnt = nodoAct;
            nodoAct = nodoAct->abajo;
        }
    }
}


void Arbol::ModificarEtiqueta(Nodo* n,char e) {
	n->etiqueta = e;
}


Nodo* Arbol::Raiz() {
	return raiz;
}


Nodo* Arbol::Padre(Nodo* n) {
	Nodo* padre = nullptr;
	Nodo* nAct = raiz;
	while(nAct != nullptr && padre == nullptr) {
		SubLista* subLAct = nAct->sublista;
		while(subLAct != nullptr && padre == nullptr) {
			if(subLAct->nodoOrg == n) {
				padre = nAct;
			} else {
				subLAct = subLAct->siguiente;
			}
		}
		nAct = nAct->abajo;
	}
	return padre;
}


Nodo* Arbol::HijoMasIzq(Nodo* n) {
	Nodo* hmi = nullptr;
	if(n->sublista != nullptr) {
		hmi = n->sublista->nodoOrg;
	}
	return hmi;
}


Nodo* Arbol::HermanoDer(Nodo* n) {
	Nodo* hd = nullptr;
	Nodo* nAct = raiz;
	bool encontrado = false;
	while(nAct != nullptr && !encontrado) {
		SubLista* subLAct = nAct->sublista;
		while(subLAct != nullptr && !encontrado) {
			if(subLAct->nodoOrg == n) {
				encontrado = true;
				if(subLAct->siguiente != nullptr) {
					hd = subLAct->siguiente->nodoOrg;
				}
			} else {
				subLAct = subLAct->siguiente;
			}
		}
		nAct = nAct->abajo; 
	}
	return hd;
}


char Arbol::Etiqueta(Nodo* n) {
	return n->etiqueta;
}


int Arbol::NumNodos() {
	int numNodos = 0;
	Nodo* nAct = raiz;
	while(nAct != nullptr) {
		++numNodos;
		nAct = nAct->abajo;
	}
	return numNodos;
}


int Arbol::NumHijos(Nodo* n) {
	int numHijos = 0;
	SubLista* subLAct = n->sublista;
	while(subLAct != nullptr) {
		++numHijos;
		subLAct = subLAct->siguiente;
	}
	return numHijos;
}


void Arbol::printArbol() {
	Nodo* nAct = raiz;
	while(nAct != nullptr) {
		std::cout << Etiqueta(nAct) << ": ";
		SubLista* sAct = nAct->sublista;
		while(sAct != nullptr) {
			std::cout << Etiqueta(sAct->nodoOrg) << ",";
			sAct = sAct->siguiente;
		}
		nAct = nAct->abajo;
		std::cout << std::endl;
	}
}


Nodo* Arbol::getNodo(char e) {
	Nodo* nodoEquivalente = nullptr;
	Nodo* nAct = raiz;
	while(nAct != nullptr && nodoEquivalente == nullptr) {
		if(nAct->etiqueta == e) {
			nodoEquivalente = nAct;
		} else {
			nAct = nAct->abajo;
		}
	}
	return nodoEquivalente;
}		

