#include "interfaz.hh"

void Interfaz::pruebas() {
  // Estructuras
  Arbol *arbol = new Arbol;
  // Mensaje de Bienvenida
  this->bienvenida();

  int opcion = -1;
  while (opcion != 0) {
    std::cout << "MENU PRINCIPAL:\n\t0. Salir\n\t1. Usar operadores "
                 "basicos.\n\t2. Usar algoritmos.\n\t3. Ver manual.";
    opcion = this->getOpcion();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // limpiar buffer
    switch (opcion) {
    case 1:
      this->probarOps(arbol);
      break;
    case 2:
      // this->probarAlg(arbol);
      break;
    case 3:
      this->mostrarManual();
      break;
    }
    system("clear");
  }
  //delete arbol;
}

void Interfaz::probarOps(Arbol *&arbol) { 
  int opcion = -1;
  char etiqueta1 = ' ';
  char etiqueta2 = ' ';
  int enteroAux = 0;
  delete arbol;
  while (opcion != 0) {
    this->mostrarOperadoresArbol();
    opcion = this->getOpcion();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    switch (opcion) {
    case 1:
      //delete arbol;
      arbol = new Arbol;
      std::cout << "Arbol creado... :)" << std::endl
                << "Ya podemos empezar" << std::endl;

      break;

    case 2:
      delete arbol;
      std::cout << "Arbol eliminado... :(" << std::endl
                << "Recuerda que no puedes trabajar con un arbol destruido, te "
                   "recomendamos que crees uno :)"
                << std::endl;

      break;

    case 3:
      arbol->Vaciar();
      std::cout << "El arbol se vacio..." << std::endl;

      break;

    case 4:
      if (arbol->Vacio()) {
        std::cout << "El arbol SÍ está vacio." << std::endl;
      } else {
        std::cout << "El arbol NO está vacio." << std::endl;
      }

      break;

    case 5:
      std::cout << "*Recuerda que es un arbol de tipo de elemento char*"
                << std::endl
                << "¿Cúal quieres que sea la raiz?: ";
      std::cin >> etiqueta1;
      arbol->PonerRaiz(etiqueta1);
      std::cout << "La nueva raiz es:" << etiqueta1;

      break;

    case 6:
      std::cout
          << "*Recuerda que es un arbol de tipo de elemento char y que la "
             "posición del nodo va desde el 1 hasta la cantidad de hijos + 1*"
          << std::endl
          << "¿Cúal quieres que sea el padre?: ";
      std::cin >> etiqueta1;

      std::cout << "\n¿Cúal quieres que sea el nuevo nodo?: ";
      std::cin >> etiqueta2;

      std::cout << "\n¿En que posición quieres que este el nodo?: ";
      std::cin >> enteroAux;

      arbol->AgregarHijo(arbol->getNodo(etiqueta1), etiqueta2, enteroAux);

      std::cout << "Se agrego el nuevo nodo ";

      break;

    case 7:
      std::cout << "*Recuerda que el nodo debe ser una etiqueta*\n¿Cúal nodo "
                   "quieres borrar?: ";
      std::cin >> etiqueta1;
      arbol->BorrarHoja(arbol->getNodo(etiqueta1));

      std::cout << "Se borro el nodo." << etiqueta1;

      break;

    case 8:
      std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿Cúal nodo "
                   "quieres modificar?: ";
      std::cin >> etiqueta1;

      std::cout << "\n¿Cúal quieres que sea la nueva etiqueta?: ";
      std::cin >> etiqueta2;

      arbol->ModificarEtiqueta(arbol->getNodo(etiqueta1), etiqueta2);

      std::cout << "Se modifico el nodo.";

      break;

    case 9:
      if (arbol->Vacio()) {
        std::cout << "El árbol no tiene raíz, puedes agregarle una :)";
      } else {
        std::cout << "La raíz del arbol es: " << arbol->Etiqueta(arbol->Raiz());
      }

      break;

    case 10:
      std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el padre?: ";
      std::cin >> etiqueta1;

      std::cout << "El padre del nodo " << etiqueta1 << " es: ";

      if (arbol->Vacio() || etiqueta1 == arbol->Etiqueta(arbol->Raiz())) {
        std::cout << " ";
      } else {
        std::cout << arbol->Etiqueta(arbol->Padre(arbol->getNodo(etiqueta1)));
      }

      break;

    case 11:
      std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el hijo más izquierdo?: ";
      std::cin >> etiqueta1;

      std::cout << "El hijo más izquierdo del nodo " << etiqueta1 << " es: ";
      if (arbol->NumHijos(arbol->getNodo(etiqueta1)) < 1) {
        std::cout << " ";
      } else {
        std::cout << arbol->Etiqueta(
            arbol->HijoMasIzq(arbol->getNodo(etiqueta1)));
      }

      break;

    case 12:
      std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber el hermano derecho?: ";
      std::cin >> etiqueta1;
      try {
        std::cout << "El hermano derecho del nodo " << etiqueta1 << " es: "
                  << arbol->Etiqueta(
                         arbol->HermanoDer(arbol->getNodo(etiqueta1)));
      } catch (const std::invalid_argument &e) {

      } catch (const std::exception &e) {
      }

      break;

    case 13:
      enteroAux = arbol->NumNodos();
      std::cout << "El número de nodos del árbol es: " << enteroAux;

      break;

    case 14:
      std::cout << "*Recuerda que el nodo debe estar en el arbol*\n¿De cúal "
                   "nodo quieres saber la cantidad de hijos?: ";
      std::cin >> etiqueta1;
      enteroAux = arbol->NumHijos(arbol->getNodo(etiqueta1));
      std::cout << "El número de nodos hijos del nodo " << etiqueta1 << ": "
                << enteroAux;

      break;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
    system("clear");
  }
}

void Interfaz::mostrarOperadoresArbol() {
  std::cout << "OPERADORES BASICOS DEL ARBOL:\n"
            << "\t0. Salir.\n"
            << "\t1. Crear.\n"
            << "\t2. Destruir.\n"
            << "\t3. Vaciar.\n"
            << "\t4. Vacio.\n"
            << "\t5. Poner Raiz.\n"
            << "\t6. Agregar Hijo.\n"
            << "\t7. Borrar Hoja.\n"
            << "\t8. Modificar Etiqueta.\n"
            << "\t9. Raiz.\n"
            << "\t10. Padre.\n"
            << "\t11. Hijo mas Izquierdo.\n"
            << "\t12. Hermano Derecho.\n"
            << "\t13. Numero de Nodos.\n"
            << "\t14. Numero de Hijos.\n";
}

void Interfaz::bienvenida() {
  system("clear");
  std::cout
      << "BIENVENIDO.\nEste es programa que permite operar la estructura de "
         "datos Arbol n-ario tal que sí importa el orden entre los hijos con: "
         "\n\tOperadores basicos de dicha estructura. \n\tAlgoritmos que "
         "operan dicha estructura. \n\nPresione enter para continuar.";
  std::cin.get();
  system("clear");
}

int Interfaz::getOpcion() {
  int opcion = -1;
  std::cout << "\n¿Que deseas hacer?:";
  std::string entrada = "";
  std::cin >> entrada;
  std::cout << std::endl;
  try {
    opcion = std::stoi(entrada);
  } catch (const std::invalid_argument &e) {
    std::cerr << "Error: Entrada no válida. No es un número entero."
              << std::endl;
  }
  return opcion;
}

void Interfaz::mostrarManual() {
  system("clear");
  std::string reglas = "";
  std::cout << reglas;
  std::cin.get();
  system("clear");
}
