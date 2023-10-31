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
	CrearArbolSemiBalanceado(arbolBXS, nodosBXS, 50);
	CrearArbolSemiBalanceado(arbolBS, nodosBS, 100);
	CrearArbolSemiBalanceado(arbolBM, nodosBM, 500);	
	CrearArbolSemiBalanceado(arbolBL, nodosBL, 1000);
	CrearArbolSemiBalanceado(arbolBXL, nodosBXL, 2500);
	
	//hacerlos Anchos
	CrearArbolUltraAncho(arbolAXS, nodosAXS, 50);
	CrearArbolUltraAncho(arbolAS, nodosAS, 100);
	CrearArbolUltraAncho(arbolAM, nodosAM, 500);	
	CrearArbolUltraAncho(arbolAL, nodosAL, 1000);
	CrearArbolUltraAncho(arbolAXL, nodosAXL, 2500);

	//hacerlos Profundos
	CrearArbolUltraProfundo(arbolPXS, nodosPXS, 50);
	CrearArbolUltraProfundo(arbolPS, nodosPS, 100);
	CrearArbolUltraProfundo(arbolPM, nodosPM, 500);	
	CrearArbolUltraProfundo(arbolPL, nodosPL, 1000);
	CrearArbolUltraProfundo(arbolPXL, nodosPXL, 2500);
	
	// TIEMPOS
	// ALG 1 -------------------------------
	std::cout << "ALGORITMO: PROFUNDIDAD NODO" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBALACEADO: " << std::endl;
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
	
	
	//ALG 2 ---------------------------------------
	std::cout << "ALGORITMO: HERMANO IZQUIERDO" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBALACEADO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgHermIzqNodoN(arbolBXS, nodosBXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgHermIzqNodoN(arbolBS, nodosBS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgHermIzqNodoN(arbolBM, nodosBM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgHermIzqNodoN(arbolBL, nodosBL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgHermIzqNodoN(arbolBXL, nodosBXL);
	std::cout << std::endl;
	
	//	ANCHO
	std::cout << "\tANCHO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgHermIzqNodoN(arbolAXS, nodosAXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgHermIzqNodoN(arbolAS, nodosAS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgHermIzqNodoN(arbolAM, nodosAM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgHermIzqNodoN(arbolAL, nodosAL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgHermIzqNodoN(arbolAXL, nodosAXL);
	std::cout << std::endl;
	
	//	PROFUNDO
	std::cout << "\tPROFUNDO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgHermIzqNodoN(arbolPXS, nodosPXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgHermIzqNodoN(arbolPS, nodosPS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgHermIzqNodoN(arbolPM, nodosPM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgHermIzqNodoN(arbolPL, nodosPL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgHermIzqNodoN(arbolPXL, nodosPXL);
	std::cout << std::endl;
	
	
	// ALG 3 ----------------------------------
	std::cout << "OPERADOR BASICO: PADRE" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBALACEADO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestOpPadreNodoN(arbolBXS, nodosBXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestOpPadreNodoN(arbolBS, nodosBS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestOpPadreNodoN(arbolBM, nodosBM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestOpPadreNodoN(arbolBL, nodosBL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestOpPadreNodoN(arbolBXL, nodosBXL);
	std::cout << std::endl;
	
	//	ANCHO
	std::cout << "\tANCHO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestOpPadreNodoN(arbolAXS, nodosAXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestOpPadreNodoN(arbolAS, nodosAS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestOpPadreNodoN(arbolAM, nodosAM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestOpPadreNodoN(arbolAL, nodosAL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestOpPadreNodoN(arbolAXL, nodosAXL);
	std::cout << std::endl;
	
	//	PROFUNDO
	std::cout << "\tPROFUNDO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestOpPadreNodoN(arbolPXS, nodosPXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestOpPadreNodoN(arbolPS, nodosPS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestOpPadreNodoN(arbolPM, nodosPM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestOpPadreNodoN(arbolPL, nodosPL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestOpPadreNodoN(arbolPXL, nodosPXL);
	std::cout << std::endl;	
	
	
	
	//ALG 4-----------------------------------
	std::cout << "ALGORITMO: ALTURA NODO PREORDEN" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBALACEADO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgAlturaNodoPO(arbolBXS, nodosBXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgAlturaNodoPO(arbolBS, nodosBS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgAlturaNodoPO(arbolBM, nodosBM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgAlturaNodoPO(arbolBL, nodosBL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgAlturaNodoPO(arbolBXL, nodosBXL);
	std::cout << std::endl;
	
	//	ANCHO
	std::cout << "\tANCHO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgAlturaNodoPO(arbolAXS, nodosAXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgAlturaNodoPO(arbolAS, nodosAS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgAlturaNodoPO(arbolAM, nodosAM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgAlturaNodoPO(arbolAL, nodosAL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgAlturaNodoPO(arbolAXL, nodosAXL);
	std::cout << std::endl;
	
	//	PROFUNDO
	std::cout << "\tPROFUNDO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgAlturaNodoPO(arbolPXS, nodosPXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgAlturaNodoPO(arbolPS, nodosPS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgAlturaNodoPO(arbolPM, nodosPM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgAlturaNodoPO(arbolPL, nodosPL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgAlturaNodoPO(arbolPXL, nodosPXL);
	std::cout << std::endl;
	
	
	//ALG 5-----------------------------------------------------
	std::cout << "ALGORITMO: LISTAR HIJOS" << std::endl;
	//	BALANCEADO 
	std::cout << "\tBALACEADO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgListarHijos(arbolBXS, nodosBXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgListarHijos(arbolBS, nodosBS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgListarHijos(arbolBM, nodosBM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgListarHijos(arbolBL, nodosBL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgListarHijos(arbolBXL, nodosBXL);
	std::cout << std::endl;
	
	//	ANCHO
	std::cout << "\tANCHO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgListarHijos(arbolAXS, nodosAXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgListarHijos(arbolAS, nodosAS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgListarHijos(arbolAM, nodosAM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgListarHijos(arbolAL, nodosAL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgListarHijos(arbolAXL, nodosAXL);
	std::cout << std::endl;
	
	//	PROFUNDO
	std::cout << "\tPROFUNDO: " << std::endl;
	std::cout << "\t\tXS: ";
	TestAlgListarHijos(arbolPXS, nodosPXS);
	std::cout << std::endl;
	std::cout << "\t\tS: ";
	TestAlgListarHijos(arbolPS, nodosPS);
	std::cout << std::endl;
	std::cout << "\t\tM: ";
	TestAlgListarHijos(arbolPM, nodosPM);
	std::cout << std::endl;
	std::cout << "\t\tL: ";
	TestAlgListarHijos(arbolPL, nodosPL);
	std::cout << std::endl;
	std::cout << "\t\tXL: ";
	TestAlgListarHijos(arbolPXL, nodosPXL);
	std::cout << std::endl;
	
	

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
	int j = 0;
	// seteo inicial listo
	for (int i = 0; i < n-1; ++i) {
		if(vecNodes->size() <= n) {
			randomChar = characterSet[distribution(rng)];
			posicion = 1;
			numHijos = A->NumHijos( (*vecNodes)[j] );
			if(numHijos == 1) {
				++posicion;
			} else if (numHijos == 2) {
				++j;
			} 
			vecNodes->push_back( A->AgregarHijo( (*vecNodes)[j], randomChar, posicion ) );
			
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


/*
------------------------
TEST DE LOS ALGORITMOS
------------------------
*/

void Tiempos::TestAlgProfNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes) {
	Algoritmos alg;
	int64_t peorTiempo = 0;
	int64_t promTiempo = 0;
	int vecSize = vecNodes->size();
	for(int i = 0; i < vecSize; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		alg.ProfundidadNodo(A, (*vecNodes)[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    	int64_t durationInMicroseconds = duration.count();
    	promTiempo += durationInMicroseconds; 
    	if(durationInMicroseconds > peorTiempo) {
    		peorTiempo = durationInMicroseconds;
    	}
	}
	promTiempo = promTiempo / vecSize;
	std::cout << "PEOR: " << peorTiempo << "\tPROM: " << promTiempo;		
}

void Tiempos::TestAlgHermIzqNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes) {
	Algoritmos alg;
	int64_t peorTiempo = 0;
	int64_t promTiempo = 0;
	int vecSize = vecNodes->size();
	for(int i = 0; i < vecSize; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		alg.HermanoIzq(A, (*vecNodes)[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    	int64_t durationInMicroseconds = duration.count();
    	promTiempo += durationInMicroseconds; 
    	if(durationInMicroseconds > peorTiempo) {
    		peorTiempo = durationInMicroseconds;
    	}
	}
	promTiempo = promTiempo / vecSize;
	std::cout << "PEOR: " << peorTiempo << "\tPROM: " << promTiempo;		
}

void Tiempos::TestOpPadreNodoN(Arbol *&A, std::vector<Arbol::Node> *&vecNodes) {
	int64_t peorTiempo = 0;
	int64_t promTiempo = 0;
	int vecSize = vecNodes->size();
	for(int i = 0; i < vecSize; ++i) {
		auto start = std::chrono::high_resolution_clock::now();
		A->Padre((*vecNodes)[i]);
		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    	int64_t durationInMicroseconds = duration.count();
    	promTiempo += durationInMicroseconds; 
    	if(durationInMicroseconds > peorTiempo) {
    		peorTiempo = durationInMicroseconds;
    	}
	}
	promTiempo = promTiempo / vecSize;
	std::cout << "PEOR: " << peorTiempo << "\tPROM: " << promTiempo;		
}

void Tiempos::TestAlgAlturaNodoPO(Arbol *&A, std::vector<Arbol::Node> *&vecNodes){
    Algoritmos alg;
    int64_t peorTiempo = 0;
    int64_t promTiempo = 0;
    int vecSize = vecNodes->size();
	
    for(int i = 0; i < vecSize; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        alg.AlturaNodoPreOrden(A, (*vecNodes)[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        int64_t durationInMicroseconds = duration.count();
        promTiempo += durationInMicroseconds; 
        if(durationInMicroseconds > peorTiempo) {
            peorTiempo = durationInMicroseconds;
        }
    }
	
    promTiempo = promTiempo / vecSize;
    std::cout << "PEOR: " << peorTiempo << "\tPROM: " << promTiempo;
}

void Tiempos::TestAlgListarHijos(Arbol *&A, std::vector<Arbol::Node> *&vecNodes){
	Algoritmos alg;
    int64_t peorTiempo = 0;
    int64_t promTiempo = 0;
    int vecSize = vecNodes->size();
	freopen("salida.txt", "w", stdout);
	
    for(int i = 0; i < vecSize; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        alg.ListarHijos(A, (*vecNodes)[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        int64_t durationInMicroseconds = duration.count();
        promTiempo += durationInMicroseconds; 
        if(durationInMicroseconds > peorTiempo) {
            peorTiempo = durationInMicroseconds;
        }
    }
	
	freopen("/dev/tty", "w", stdout); //Para Linux
	//freopen("CON", "w", stdout); Para windows
	
    promTiempo = promTiempo / vecSize;
    std::cout << "PEOR: " << peorTiempo << "\tPROM: " << promTiempo;
}

