#include "tiempos.hh"

void Tiempos::Ejecutar() {
	// BALANCEADOS
	Arbol* arbolBXS = new Arbol;
	std::vector<Arbol::Node> *nodosBXS = new std::vector<Arbol::Node>;

	Arbol* arbolBS = new Arbol;
	std::vector<Arbol::Node> *nodosBS = new std::vector<Arbol::Node>;	
	
	Arbol* arbolBM = new Arbol;
	std::vector<Arbol::Node> *nodosBM = new std::vector<Arbol::Node>;	
	
	Arbol* arbolBL = new Arbol;
	std::vector<Arbol::Node> *nodosBL = new std::vector<Arbol::Node>;
	
	Arbol* arbolBXL = new Arbol;
	std::vector<Arbol::Node> *nodosBXL = new std::vector<Arbol::Node>;	
	


	// ANCHOS
	Arbol* arbolAXS = new Arbol;
	std::vector<Arbol::Node> *nodosAXS = new std::vector<Arbol::Node>;

	Arbol* arbolAS = new Arbol;
	std::vector<Arbol::Node> *nodosAS = new std::vector<Arbol::Node>;	
	
	Arbol* arbolAM = new Arbol;
	std::vector<Arbol::Node> *nodosAM = new std::vector<Arbol::Node>;	
	
	Arbol* arbolAL = new Arbol;
	std::vector<Arbol::Node> *nodosAL = new std::vector<Arbol::Node>;
	
	Arbol* arbolAXL = new Arbol;
	std::vector<Arbol::Node> *nodosAXL = new std::vector<Arbol::Node>;		
	
	
	
	// PROFUNDOS
	Arbol* arbolPXS = new Arbol;
	std::vector<Arbol::Node> *nodosPXS = new std::vector<Arbol::Node>;

	Arbol* arbolPS = new Arbol;
	std::vector<Arbol::Node> *nodosPS = new std::vector<Arbol::Node>;	
	
	Arbol* arbolPM = new Arbol;
	std::vector<Arbol::Node> *nodosPM = new std::vector<Arbol::Node>;	
	
	Arbol* arbolPL = new Arbol;
	std::vector<Arbol::Node> *nodosPL = new std::vector<Arbol::Node>;
	
	Arbol* arbolPXL = new Arbol;
	std::vector<Arbol::Node> *nodosPXL = new std::vector<Arbol::Node>;		
		
	
	//hacerlos Balanceados
	CrearArbolSemiBalanceado(arbolBXS, nodosBXS, 100);
	CrearArbolSemiBalanceado(arbolBS, nodosBS, 1000);
	CrearArbolSemiBalanceado(arbolBM, nodosBM, 10000);	
	CrearArbolSemiBalanceado(arbolBL, nodosBL, 100000);
	CrearArbolSemiBalanceado(arbolBXL, nodosBXL, 1000000);
	
	//hacerlos Anchos
	CrearArbolUltraAncho(arbolAXS, nodosAXS, 100);
	CrearArbolUltraAncho(arbolAS, nodosAS, 1000);
	CrearArbolUltraAncho(arbolAM, nodosAM, 10000);	
	CrearArbolUltraAncho(arbolAL, nodosAL, 100000);
	CrearArbolUltraAncho(arbolAXL, nodosAXL, 1000000);

	//hacerlos Profundos
	CrearArbolUltraProfundo(arbolPXS, nodosPXS, 100);
	CrearArbolUltraProfundo(arbolPS, nodosPS, 1000);
	CrearArbolUltraProfundo(arbolPM, nodosPM, 10000);	
	CrearArbolUltraProfundo(arbolPL, nodosPL, 100000);
	CrearArbolUltraProfundo(arbolPXL, nodosPXL, 1000000);
	
	// TIEMPOS
	// ALG 1 
	std::cout << "Algoritmo 1" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBalanceado: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgProfNodoN(arbolBXS, nodosBXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgProfNodoN(arbolBS, nodosBS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgProfNodoN(arbolBM, nodosBM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgProfNodoN(arbolBL, nodosBL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgProfNodoN(arbolBXL, nodosBXL);
	std::cout << std::endl;
	
	//	ANCHO
	std::cout << "\tANCHO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgProfNodoN(arbolAXS, nodosAXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgProfNodoN(arbolAS, nodosAS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgProfNodoN(arbolAM, nodosAM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgProfNodoN(arbolAL, nodosAL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgProfNodoN(arbolAXL, nodosAXL);
	std::cout << std::endl;
	
	//	PROFUNDO
	std::cout << "\tPROFUNDO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgProfNodoN(arbolPXS, nodosPXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgProfNodoN(arbolPS, nodosPS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgProfNodoN(arbolPM, nodosPM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgProfNodoN(arbolPL, nodosPL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgProfNodoN(arbolPXL, nodosPXL);
	std::cout << std::endl;
	
	
	//ALG 2
		/* etc
		 * etc
		 * etc
		*/
	
	//Algoritmos alg;
	//alg.ListarPreOrden(arbolBL);

////////	
	delete arbolBXS;
	delete nodosBXS;
	delete arbolBS;
	delete nodosBS;
	delete arbolBM;
	delete nodosBM;
	delete arbolBL;
	delete nodosBL;
	delete arbolBXL;
	delete nodosBXL;
///////
	delete arbolAXS;
	delete nodosAXS;
	delete arbolAS;
	delete nodosAS;
	delete arbolAM;
	delete nodosAM;
	delete arbolAL;
	delete nodosAL;
	delete arbolAXL;
	delete nodosAXL;
///////
	delete arbolPXS;
	delete nodosPXS;
	delete arbolPS;
	delete nodosPS;
	delete arbolPM;
	delete nodosPM;
	delete arbolPL;
	delete nodosPL;
	delete arbolPXL;
	delete nodosPXL;
}

void Tiempos::CrearArbolSemiBalanceado(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
	// generador de randoms listo
	A->PonerRaiz(randomChar);
	vecNodes->push_back(A->getNodo(randomChar));
	int posicion;
	int numHijos;
	// seteo inicial listo
	for (int i = 0; i < n-1; ++i) {
		if(vecNodes->size() <= n) {
			randomChar = characterSet[distribution(rng)];
			posicion = 1;
			numHijos = A->NumHijos( (*vecNodes)[i] );
			if(numHijos == 1) {
				++posicion;
			} else if (numHijos == 2) {
				++i;
			} 
			vecNodes->push_back( A->AgregarHijo( (*vecNodes)[i], randomChar, posicion ) );
			
		} else {
			i = n;
		}
	}
}

void Tiempos::CrearArbolUltraAncho(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
	//generador de randoms listo
	A->PonerRaiz(randomChar);
	Arbol::Node nodoRaiz = A->getNodo(randomChar);
	vecNodes->push_back(nodoRaiz);
	//seteo inicial listo
	for(int i = 1; i < n; ++i) {
		randomChar = characterSet[distribution(rng)];
		vecNodes->push_back( A->AgregarHijo(nodoRaiz, randomChar, i) );
	}
}

void Tiempos::CrearArbolUltraProfundo(Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
	//generador de randoms listo
	A->PonerRaiz(randomChar);
	vecNodes->push_back(A->getNodo(randomChar));
	//seteo inicial listo
	for(int i = 0; i < n-1; ++i) {
		randomChar = characterSet[distribution(rng)];
		vecNodes->push_back( A->AgregarHijo( (*vecNodes)[i], randomChar, 1 ) );
	}
} 

void Tiempos::TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes) {
		
}
