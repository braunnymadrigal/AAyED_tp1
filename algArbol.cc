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
	Arbol::Node n = A->Padre(nU);
	while( n != A->NodoNulo ) {
		++profundidad;
		n = A->Padre(n);
	}
	return profundidad;
}

int Algoritmos::CantNivelesPreOrden(Arbol *A){
	int niveles = 0;
	if( !A->Vacio()){
		niveles = CantNivelesPreOrdenR(A, A->Raiz());
	}
	return niveles;
}

int Algoritmos::CantNivelesPreOrdenR(Arbol *A, Arbol::Node n) {
	Arbol::Node nh = A->HijoMasIzq(n);
	int niveles = 0;
	while( nh != A->NodoNulo ){
		int nivelesNH = CantNivelesPreOrdenR(A, nh);
		if( niveles < nivelesNH ) {
			niveles = nivelesNH;
		}
		nh = A->HermanoDer( nh );
	}
	return niveles + 1;
}


int Algoritmos::CantNivelesPorNiveles(Arbol *A) {
	int niveles = 0;
	int k = 0;
	if(!A->Vacio()) {
		k = 1;
		std::vector<std::pair<Arbol::Node, int>> *L = new std::vector<std::pair<Arbol::Node, int>>;
		L->push_back(std::make_pair(A->Raiz(), k));
		int u = 0;
		int p = 0;
		Arbol::Node n;
		Arbol::Node nh;
		int tamLista;
		int i;
		int nivPadre;
		Arbol::Node nPadre;
		bool encontrado;
		while(u != (p-1) ) {
			n = (*L)[p].first;
			++p;
			nh = A->HijoMasIzq(n);
			if(nh != A->NodoNulo) {
				++k;
			}
			while(nh != A->NodoNulo) {
				i = 0;
				tamLista = L->size();
				encontrado = false;
				nPadre = A->Padre(nh);
				while(i < tamLista && !encontrado) {
					if(nPadre == (*L)[i].first) {
						encontrado = true;
						nivPadre = (*L)[i].second;
					} else {
						++i;
					}
				}
				if(k-nivPadre != 1) {
					--k;
				}
				L->push_back(std::make_pair(nh, k));
				++u;
				nh = A->HermanoDer(nh);
			}
		}
		delete L;
	}
	niveles = k;
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
