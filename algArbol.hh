#pragma once

#include <iostream>
#include <limits>

#include "colaLSE.hh"
//#include "arbolASP.hh"
#include "arbolLSE.hh"
//#include "arbolHMIHD.hh"
//#include "arbolHMIHD2.hh"

class Algoritmos {
public:
	//01• Averiguar cuál es el hermano izquierdo de un nodo n
	//Node HermanoIzq(Arbol* A, Node n) {}
	
	//02• Averiguar si el árbol tiene etiquetas repetidas
	//bool EtiqRepetidas(Arbol* A) {}
	
	//03• Averiguar la altura de un nodo n (distancia que hay desde el nodo n hasta la hoja descendiente más alejada) haciendo un recorrido en pre-orden
	//int AlturaNodoPreOrden(Arbol* A, Node n) {}
	
	//04• Averiguar la profundidad de un nodo n (distancia que hay desde el nodo n hasta la raíz)
	//int ProfundidadNodo(Arbol* A, Node n) {}
	
	//05• Averiguar cuántos niveles tiene el árbol haciendo un recorrido en pre-orden
	//int CantNivelesPreOrden(Arbol* A) {}
	
	//06• Averiguar cuántos niveles tiene el árbol haciendo un recorrido por niveles
	//int CantNivelesPorNiveles(Arbol* A) {}
	
	//07• Listar las etiquetas del i-ésimo nivel
	void ListarIesimoNivel(Arbol* A, int i) {}
	
	//08• Listar el árbol en pre-orden
	void ListarPreOrden(Arbol* A) {}
	
	//09• Listar el árbol por niveles
	void ListarPorNiveles(Arbol* A) {}
	
	//10• Buscar una etiqueta
	//Node BuscarEtiq(Arbol* A, char e) {}
	
	//11• Borrar el subárbol que se genera a partir del nodo n
	void BorrarSubArbol(Arbol* A, Arbol::Node n) {}
	
	//12• Listar los hijos de un nodo
	void ListarHijos(Arbol* A, Arbol::Node n) {}
};
