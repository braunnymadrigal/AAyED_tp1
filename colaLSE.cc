#include "colaLSE.hh"


Cola::Cola() {
	Iniciar();
}


Cola::~Cola() {
	Destruir();
}


void Cola::Iniciar() {
	primero = nullptr;
	ultimo = nullptr;
}


void Cola::Destruir() {
	while(primero != nullptr){
		Caja* primeroAux = primero;
		primero = primero->siguiente;
		delete primeroAux;
	}		
}


void Cola::Vaciar() {
	while(primero != nullptr) {
		Caja* primeroAux = primero;
		primero = primero->siguiente;
		primeroAux = nullptr;
	}
}


bool Cola::Vacio() {
	bool vacio = false;
	if(primero == nullptr){
		vacio = true;
	}
	return vacio;
}


void Cola::Encolar(char e) {
	Caja* nuevaCaja = new Caja;
	nuevaCaja->elemento = e;
	nuevaCaja->siguiente = nullptr;
	if(primero == nullptr){
		primero = nuevaCaja;
		ultimo = nuevaCaja;
	} else {
		ultimo->siguiente = nuevaCaja;
		ultimo = ultimo->siguiente;
	}
}


char Cola::Desencolar() {
	Caja* primeroAux = primero;
	primero = primero->siguiente;
	char e = primeroAux->elemento;
	if(primeroAux == ultimo){
		ultimo = ultimo->siguiente;
	}
	delete primeroAux;
	return e;
}


char Cola::Frente() {
	return primero->elemento;
}



