#ifndef INTERFAZ_HH
#define INTERFAZ_HH
//#include "arbolASP.hh"
//#include "arbolHMIHD.hh"
//#include "arbolHMIHD2.hh"
#include "arbolLSE.hh"
#include "colaLSE.hh"
#include <iostream>

class Interfaz{
	private:
		
		
	public:
		void probarArbol(Arbol*&);
		void probarCola(Cola*&);
		
		void mostrarOperadoresArbol();
		void mostrarOperadoresCola();
	
		void pruebas();
		void bienvenida();
		int getOpcion();
		void mostrarManual();
		
};

#endif