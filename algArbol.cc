#include "algArbol.hh"

Arbol::Node Algoritmos::HermanoIzq(Arbol *A, Arbol::Node nU) {
	Arbol::Node nodoDevolver = A->NodoNulo;
	bool encontrado = false;
	Cola<Arbol::Node> *C = new Cola<Arbol::Node>();
	C->Encolar(A->Raiz());
	Arbol::Node n;
	Arbol::Node nh;
	Arbol::Node nAux;
	while(!C->Vacio() && !encontrado) {
		n = C->Desencolar();
		nh = A->HijoMasIzq(n);
		if(nh == nU) {
			encontrado = true;
		}
		while(nh != A->NodoNulo && !encontrado) {
			C->Encolar(nh);
			nAux = nh;
			nh = A->HermanoDer(nh);
			if(nh == nU) {
				encontrado = true;
				nodoDevolver = nAux;
			}
		}
	}
	delete C;
	return nodoDevolver;
}

bool Algoritmos::EtiqRepetidas(Arbol *A) {
	bool repetidas = false;
	if(!A->Vacio()) {
		std::vector<Arbol::Node> *L = new std::vector<Arbol::Node>;
		L->push_back(A->Raiz());
		int u = 0;
		int p = 0;
		Arbol::Node n;
		Arbol::Node nh;
		int tamLista;
		int i;
		char etiqNH;
		while(u != (p-1) && !repetidas) {
			n = (*L)[p];
			++p;
			nh = A->HijoMasIzq(n);
			while(nh != A->NodoNulo && !repetidas) {
				i = 0;
				tamLista = L->size();
				etiqNH = A->Etiqueta(nh);
				while(i < tamLista && !repetidas) {
					if(etiqNH == A->Etiqueta((*L)[i])) {
						repetidas = true;
					} else {
						++i;
					}
				}
				L->push_back(nh);
				++u;
				nh = A->HermanoDer(nh);
			}
		}
		delete L;
	}
	return repetidas;
}

int Algoritmos::AlturaNodoPreOrden(Arbol *A, Arbol::Node n) {
	int altura = 0;
	AlturaNodoPreOrdenR(A, n, altura, 0);
	return altura;
}

void Algoritmos::AlturaNodoPreOrdenR(Arbol *A, Arbol::Node n, int &altura, int k) {
	if(A->HijoMasIzq(n) == A->NodoNulo) {
		if(k > altura) {
			altura = k;
		}
	} else {
		n = A->HijoMasIzq(n);
		++k;
		while(n != A->NodoNulo) {
			AlturaNodoPreOrdenR(A, n, altura, k);
			n = A->HermanoDer(n);
		}
	}
}

int Algoritmos::ProfundidadNodo(Arbol *A, Arbol::Node nU) {
	int profundidad = 0;
	if(A->Raiz() != nU) {
		ProfundidadNodoR(A, A->Raiz(), nU, profundidad, 0);
	}
	return profundidad;
}

void Algoritmos::ProfundidadNodoR(Arbol *A, Arbol::Node n, Arbol::Node nU, int &profundidad, int k) {
	if(n == nU) {
		profundidad = k;
	} else {
		n = A->HijoMasIzq(n);
		++k;
		while(n != A->NodoNulo) {
			ProfundidadNodoR(A, n, nU, profundidad, k);
			n = A->HermanoDer(n);
		}
	}
}

int Algoritmos::CantNivelesPreOrden(Arbol *A) {
	int niveles = 0;
	if(!A->Vacio()) {
		CantNivelesPreOrdenR(A, A->Raiz(), niveles, 1);
	}
	return niveles;
}

void Algoritmos::CantNivelesPreOrdenR(Arbol *A, Arbol::Node n, int &niveles, int k) {
	if(A->HijoMasIzq(n) == A->NodoNulo) {
		if(k > niveles) {
			niveles = k;
		}
	} else {
		n = A->HijoMasIzq(n);
		++k;
		while(n != A->NodoNulo) {
			CantNivelesPreOrdenR(A, n, niveles, k);
			n = A->HermanoDer(n);
		}
	}
}

int Algoritmos::CantNivelesPorNiveles(Arbol *A) {
	int niveles = 0;
	if(!A->Vacio()) {
		int k = 1;
		Cola<Arbol::Node> *C = new Cola<Arbol::Node>();
		C->Encolar(A->Raiz());
		Arbol::Node n;
		Arbol::Node nh;
		while(!C->Vacio()) {
			n = C->Desencolar();
			nh = A->HijoMasIzq(n);
			if(nh == A->NodoNulo) {
				if( k > niveles) { //creo que este if es innecesario, comprobable en debugger
					niveles = k;
				}
			} else {
				++k;
				while(nh != A->NodoNulo) {
					C->Encolar(nh);
					nh = A->HermanoDer(nh);
				}
			}
		}
		delete C;
	}
	return niveles;
}

void Algoritmos::ListarIesimoNivel(Arbol *A, int i) {
	if(!A->Vacio()) {
		ListarIesimoNivelR(A, A->Raiz(), i, 1);
	}
}

void Algoritmos::ListarIesimoNivelR(Arbol *A, Arbol::Node n, int i, int nivAct) {
	if(nivAct == i) {
		std::cout << A->Etiqueta(n) << " ";
	}
	n = A->HijoMasIzq(n);
	++nivAct;
	while(n != A->NodoNulo) {
		ListarIesimoNivelR(A, n, i, nivAct);
		n = A->HermanoDer(n);
	}
}

void Algoritmos::ListarPreOrden(Arbol *A) {
	if(!A->Vacio()) {
		ListarPreOrdenR(A, A->Raiz());
	}
}

void Algoritmos::ListarPreOrdenR(Arbol *A, Arbol::Node n) {
	std::cout << A->Etiqueta(n) << " ";
	n = A->HijoMasIzq(n);
	while(n != A->NodoNulo) {
		ListarPreOrdenR(A, n);
		n = A->HermanoDer(n);
	}
}

void Algoritmos::ListarPorNiveles(Arbol *A) {
	if(!A->Vacio()) {
		Cola<Arbol::Node> *C = new Cola<Arbol::Node>();
		C->Encolar(A->Raiz());
		Arbol::Node n;
		Arbol::Node nh;
		while(!C->Vacio()) {
			n = C->Desencolar();
			std::cout << A->Etiqueta(n) << " ";
			nh = A->HijoMasIzq(n);
			while(nh != A->NodoNulo) {
				C->Encolar(nh);
				nh = A->HermanoDer(nh);
			}
		}
		delete C;
	}
}

Arbol::Node Algoritmos::BuscarEtiq(Arbol *A, char e) {
	Arbol::Node nodoRetorno = A->NodoNulo;
	if(!A->Vacio()) {
		Cola<Arbol::Node> *C = new Cola<Arbol::Node>();
		C->Encolar(A->Raiz());
		Arbol::Node n;
		Arbol::Node nh;
		while(!C->Vacio() && nodoRetorno == A->NodoNulo) {
			n = C->Desencolar();
			if(A->Etiqueta(n) == e) {
				nodoRetorno = n;
			}
			nh = A->HijoMasIzq(n);
			while(nh != A->NodoNulo && nodoRetorno == A->NodoNulo) {
				C->Encolar(nh);
				nh = A->HermanoDer(nh);
			}
		}
		delete C;
	}
	return nodoRetorno;
}

void Algoritmos::BorrarSubArbol(Arbol *&A, Arbol::Node n) {
	Arbol::Node nh = A->HijoMasIzq(n);
	if(nh != A->NodoNulo) {
    	BorrarSubArbolR(A, nh);
    } 
    A->BorrarHoja(n);
}

void Algoritmos::BorrarSubArbolR(Arbol *&A, Arbol::Node nh) {
	if(nh != A->NodoNulo) {
    	if (A->HijoMasIzq(nh) != A->NodoNulo) {
      		BorrarSubArbolR(A, A->HijoMasIzq(nh));
         	BorrarSubArbolR(A, A->HermanoDer(nh));
    	} 
    	A->BorrarHoja(nh);
    }
}

void Algoritmos::ListarHijos(Arbol *A, Arbol::Node n) {
	n = A->HijoMasIzq(n);
	while(n != A->NodoNulo) {
		std::cout << A->Etiqueta(n) << " ";
		n = A->HermanoDer(n);
	}
}
