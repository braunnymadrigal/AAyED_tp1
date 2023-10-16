#include <iostream>
#include <limits>
#include "interfaz.hh"

void Interfaz::pruebas(){
	//Estructuras
	Arbol* arbol = new Arbol();
	Cola* cola = new Cola();
	
	//Mensaje de Bienvenida
	this->bienvenida();
	
	int opcion = -1;
	while(opcion != 0){
		std::cout << "MENU PRINCIPAL:\n\t0. Salir\n\t1. Trabajar con la cola.\n\t2. Trabajar con el arbol.\n\t3. Ver manual.";
		opcion = this->getOpcion();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); //limpiar buffer
		switch(opcion){
			case 1:
				this->probarCola(cola);
				break;
			case 2:
				this->probarArbol(arbol);
				break;
			case 3:
				this->mostrarManual();
				break;
		}
		system("clear");
	}
	
	delete arbol;
	delete cola;
}

void Interfaz::probarArbol(Arbol*& arbol){
	int opcion = -1;
	char etiqueta1 = ' ';
	char etiqueta2 = ' ';
	int enteroAux = 0;
	
	while(opcion != 0){
		this->mostrarOperadoresArbol();
		opcion = this->getOpcion();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		switch(opcion){
			case 1:
				arbol = new Arbol();
				std::cout << "Arbol creado... :)" << std::endl << "Ya podemos empezar" << std::endl;
				
				break;
				
			case 2:
				delete arbol;
				std::cout << "Arbol eliminado... :(" << std::endl << "Recuerda que no puedes trabajar con un arbol destruido, te recomendamos que crees uno :)" << std::endl;
				
				break;
				
			case 3:
				arbol -> Vaciar();
				std::cout << "El arbol se vacio..." << std::endl;
				
				break;
				
			case 4:
				if(arbol -> Vacio()){
					std::cout << "El arbol SÍ está vacio." << std::endl;
				}
				else{
					std::cout << "El arbol NO está vacio." << std::endl;
				}
				
				break;
				
			case 5:
				std::cout << "*Recuerda que es un arbol de tipo de elemento char*" << std::endl << "¿Cúal quieres que sea la raiz?: ";
				std::cin >> etiqueta1;
				arbol -> PonerRaiz(etiqueta1);
				std::cout << "La nueva raiz es:" << etiqueta1;
				
				break;
				
			case 6:
				std::cout << "*Recuerda que es un arbol de tipo de elemento char y que la posición del nodo va desde el 1 hasta la cantidad de hijos + 1*" << std::endl << "¿Cúal quieres que sea el padre?: ";
				std::cin >> etiqueta1;
				
				std::cout << "\n¿Cúal quieres que sea el nuevo nodo?: ";
				std::cin >> etiqueta2;
				
				std::cout << "\n¿En que posición quieres que este el nodo?: ";
				std::cin >> enteroAux;
				
				arbol->AgregarHijo(arbol->getNodo(etiqueta1), etiqueta2, enteroAux);
				
				std::cout << "Se agrego el nuevo nodo ";
				
				break;
				
			case 7: //borrar
				std::cout << "*Recuerda que el nodo debe ser una etiqueta*\n¿Cúal nodo quieres borrar?: ";
				std::cin >> etiqueta1;
				arbol -> BorrarHoja(arbol->getNodo(etiqueta1));
				
				std::cout << "Se borro el nodo." << etiqueta1;
				
				break;
				
			case 8: //m
				std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿Cúal nodo quieres modificar?: ";
				std::cin >> etiqueta1;
				
				std::cout << "\n¿Cúal quieres que sea la nueva etiqueta?: ";
				std::cin >> etiqueta2;
				
				arbol -> ModificarEtiqueta(arbol->getNodo(etiqueta1), etiqueta2);
				
				std::cout << "Se modifico el nodo.";
				
				break;
				
			case 9:
				//nodoAux = arbol->Raiz();
				if(arbol -> Vacio()){
					std::cout << "El árbol no tiene raíz, puedes agregarle una :)";
				}
				else{
					std::cout << "La raíz del arbol es: " << arbol -> Etiqueta(arbol->Raiz());
				}
				
				break;
				
			case 10:
				std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal nodo quieres saber el padre?: ";
				std::cin >> etiqueta1;
				
				std::cout << "El padre del nodo " << etiqueta1 << " es: " ;
				
				if(arbol -> Vacio() || etiqueta1 == arbol -> Etiqueta(arbol->Raiz())){
					std::cout << " ";
				}
				else{
					std::cout << arbol -> Etiqueta(arbol->Padre(arbol->getNodo(etiqueta1)));
				}
				
				break;
				
			case 11:
				std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal nodo quieres saber el hijo más izquierdo?: ";
				std::cin >> etiqueta1;
				
				std::cout << "El hijo más izquierdo del nodo " << etiqueta1 << " es: ";
				if(arbol->NumHijos(arbol->getNodo(etiqueta1)) < 1){
					std::cout << " ";
				}
				else{
					std::cout << arbol -> Etiqueta(arbol->HijoMasIzq(arbol->getNodo(etiqueta1)));
				}
				
				break;
				
			case 12:
				std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal nodo quieres saber el hermano derecho?: ";
				std::cin >> etiqueta1;
				try {
					std::cout << "El hermano derecho del nodo " << etiqueta1 << " es: " << arbol->Etiqueta(arbol->HermanoDer(arbol->getNodo(etiqueta1)));
				} catch (const std::invalid_argument& e) {
					
				} catch (const std::exception& e) {
	
				}

				break;
				
			case 13:
				enteroAux = arbol -> NumNodos();
				std::cout << "El número de nodos del árbol es: " << enteroAux;
				
				break;
				
			case 14:
				std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal nodo quieres saber la cantidad de hijos?: ";
				std::cin >> etiqueta1;
				enteroAux = arbol->NumHijos(arbol->getNodo(etiqueta1));
				std::cout << "El número de nodos hijos del nodo " << etiqueta1 << ": " << enteroAux;
				
				break;
				
			case 15:
				arbol->printArbol();
	
				break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		std::cin.get();
		system("clear");
	}
}

void Interfaz::probarCola(Cola*& cola){
	int opcion = -1;
	char etiquetaAux = ' ';
	while(opcion != 0){
		this->mostrarOperadoresCola();
		opcion = this->getOpcion();
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		
		switch(opcion){
			case 1:
				cola = new Cola();
				std::cout << "Cola creada... :)" << std::endl << "Ya podemos empezar" << std::endl;
				
				break;
				
			case 2:
				delete cola;
				std::cout << "Cola eliminado... :(" << std::endl << "Recuerda que no puedes trabajar con un cola destruida, te recomendamos que crees una :)" << std::endl;
				
				break;
				
			case 3:
				cola -> Vaciar();
				std::cout << "El cola se vacio..." << std::endl;
				
				break;
				
			case 4:
				if(cola -> Vacio()){
					std::cout << "La cola SÍ está vacia." << std::endl;
				}
				else{
					std::cout << "El cola NO está vacia." << std::endl;
				}
				
				break;
				
			case 5:
				std::cout << "*Recuerda que es una cola de tipo de elemento char*" << std::endl << "¿Qué quieres encolar?: ";
				std::cin >> etiquetaAux;
				cola -> Encolar(etiquetaAux);
				std::cout << "Elemento agregado...";
				
				break;
				
			case 6:
				etiquetaAux = cola -> Desencolar();
				std::cout << "El primer elemento de la cola era: " << etiquetaAux;
				break;
				
			case 7:
				etiquetaAux = cola -> Frente();
				std::cout << "El elemento al frente de la cola es: " << etiquetaAux;
				break;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n'); 
		std::cin.get();
		system("clear");
	}
	
}

void Interfaz::mostrarOperadoresArbol(){
	std::cout << "OPERADORES BASICOS DEL ARBOL:\n"<<
				  "\t0. Salir.\n" <<
				  "\t1. Crear.\n" <<
				  "\t2. Destruir.\n" <<
				  "\t3. Vaciar.\n" <<
				  "\t4. Vacio.\n" <<
				  "\t5. Poner Raiz.\n" <<
				  "\t6. Agregar Hijo.\n" <<
				  "\t7. Borrar Hoja.\n" <<
				  "\t8. Modificar Etiqueta.\n" <<
				  "\t9. Raiz.\n" <<
				  "\t10. Padre.\n" <<
				  "\t11. Hijo mas Izquierdo.\n" <<
				  "\t12. Hermano Derecho.\n" <<
				  "\t13. Numero de Nodos.\n" <<
				  "\t14. Numero de Hijos.\n"<<
				  "\t15. Imprimir Arbol (no es basico, es extra).\n";
}

void Interfaz::mostrarOperadoresCola(){
	std::cout << "OPERADORES BASICOS DEL COLA:\n"<<
				  "\t0. Regresar.\n" <<
				  "\t1. Crear.\n" <<
				  "\t2. Destruir.\n" <<
				  "\t3. Vaciar.\n" <<
				  "\t4. Vacia.\n" <<
				  "\t5. Agregar.\n" <<
				  "\t6. Sacar.\n" <<
				  "\t7. Frente.\n";
}


void Interfaz::bienvenida(){
	system("clear");
	std::cout << "BIENVENIDO.\nEste es programa que permite probar las siguientes estructuras de datos: \n\tCola.\n\tArbol n-ario tal que sí importa el orden entre los hijos.\n\nPresione enter para continuar.";
	std::cin.get();
	system("clear");
}

int Interfaz::getOpcion(){
	int opcion = -1;
	std::cout << "\n¿Que deseas hacer?:";
	std::string entrada = "";
	std::cin >> entrada;
	std::cout << std::endl;
	try {
		opcion = std::stoi(entrada);
	} catch (const std::invalid_argument& e) {
		std::cerr << "Error: Entrada no válida. No es un número entero." << std::endl;
	}
	return opcion;
}

void Interfaz::mostrarManual(){
	system("clear");
	std::string reglas = "MANUAL DE OPERADORES:\nCOLA\nIniciar(Cola C)\n\tEfecto: Inicializa la cola C como una cola vacía.\n\tRequiere: Una cola C no inicializada o destruida.\n\tModifica: La cola C.\nDestruir (Cola C)\n\tEfecto: Destruye la cola C dejándola inutilizable.\n\tRequiere: Una cola C inicializada.\n\tModifica: La cola C.\nVaciar (Cola C)\n\tEfecto: Limpia la cola C, dejándola con 0 elementos.\n\tRequiere: Una cola C inicializada.\n\tModifica: La cola C.\nVacia (Cola C) -> booleano\n\tEfecto: Comprueba si la cola esta vacía. Devuelve verdadero si lo está, falso en caso contrario.\n\tRequiere: Una cola C inicializada.\n\tModifica: N/A.\nEncolar (Elemento e, Cola C)\n\tEfecto: Agrega el elemento e al final de la cola C.\n\tRequiere: Una cola C inicializada y un elemento e válido.\n\tModifica: La cola C.\nDesencolar (Cola) -> elemento\n\tEfecto: Borra y devuelve el elemento que está al frente de la cola.\n\tRequiere: Una cola C inicializada y no vacía.\n\tModifica: La cola C.\nFrente (Cola c) -> elemento\n\tEfecto: Devuelve el elemento que está al frente de la cola.\n\tRequiere: Una cola C inicializada y no vacía.\n\tModifica: N/A.\n\nARBOL\nIniciar (Arbol A)\n\tEfecto: Inicializa el árbol como un árbol vacío.\n\tRequiere: Un árbol A no inicializado o destruido.\n\tModifica: El árbol A.\nDestruir (Arbol A)\n\tEfecto: Destruye el árbol A dejándolo inutilizable.\n\tRequiere: Un árbol A inicializado.\n\tModifica: EL árbol A.\nVaciar (Arbol A)\n\tEfecto: Limpia el árbol A, dejándolo con 0 nodos.\n\tRequiere: Un árbol A inicializado.\n\tModifica: El árbol A.\nVacio (Arbol A) -> booleano\n\tEfecto: Comprueba si el árbol esta vacío. Devuelve verdadero si lo está, falso en caso contrario.\n\tRequiere: Un árbol A inicializado.\tModifica: N/A.\n PonerRaíz (Etiqueta e, Arbol A)\n\tEfecto: Pone en el árbol A, un nodo raíz que contiene la etiqueta e, de esta forma le quita el estatus de vacío al árbol.\n\tRequiere: Un árbol A inicializado y vacío y una etiqueta.\n\tModifica: El árbol A.\nAgregarHijo (Nodo n, Etiqueta e, int i, Arbol A) -> nodo\n\tEfecto: Pone en el árbol A, un nodo que contiene la etiqueta e como hijo del nodo n en la posición i dentro de sus hijos y devuelve el nuevo nodo agregado.\n\tRequiere: Un árbol A inicializado, no vacío, un nodo n distinto a nodoNulo, una etiqueta e y una posición i menor o igual que el número de hijos del nodo n más 1, pero con i mayor que 0.\n\tModifica: El árbol A.\nBorrarHoja (Nodo n, Arbol A)\n\tEfecto: Elimina el nodo n.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo n sea un nodo hoja.\n\tModifica: El árbol A.\nModificarEtiqueta (Nodo n, Etiqueta e, Árbol A)\n\tEfecto: Modifica la etiqueta que contiene el nodo n, por la etiqueta e.\n\tRequiere: Un árbol A inicializado, no vacío, un nodo n distinto a nodoNulo y una etiqueta e.\n\tModifica: El árbol A, específicamente el nodo n.\nRaiz (Arbol A) -> nodo\n\tEfecto: Devuelve el nodo raíz del árbol y si está vacío devuelve nodoNulo.\n\tRequiere: Un árbol A inicializado.\n\tModifica: N/A.\nPadre (Nodo n, Árbol A) -> nodo\n\tEfecto: Devuelve el nodo padre del nodo n y si no tiene padre devuelve nodoNulo.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo distinto a nodoNulo.\n\tModifica: N/A.\nHijoMasIzq (Nodo n, Árbol A) -> nodo\n\tEfecto: Devuelve el hijo más izquierdo del nodo n y si no tiene hijos devuelve nodoNulo.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo distinto a nodo nulo.\tModifica: N/A.\nHermanoDer (Nodo n, Árbol A) -> nodo\n\tEfecto: Devuelve el hermano derecho del nodo n y si no tiene hermano derecho devuelve nodoNulo.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo distinto a nodo nulo.\tModifica: N/A.\nEtiqueta (Nodo n, Árbol A) -> etiqueta\tEfecto: Devuelve la etiqueta en relación 1 a 1 con el nodo n.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo distinto a nodoNulo.\n\tModifica: N/A.\nNumNodos(Árbol A) -> int\n\tEfecto: Devuelve como un entero la cantidad de nodos que contiene el árbol A.\n\tRequiere: Un árbol A inicializado.\tModifica: N/A.\nNumHijos (Nodo n, Árbol A) -> int\n\tEfecto: Devuelve como un entero la cantidad de nodos hijos que tiene el nodo n.\n\tRequiere: Un árbol A inicializado, no vacío y un nodo distinto a nodo nulo.\n\tModifica: N/A.\n";

	std::cout << reglas;
	std::cin.get();
	system("clear");
}