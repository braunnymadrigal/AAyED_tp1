#include "tiempos.hh"

void Tiempos::Ejecutar() {
    Arbol *arbolB = new Arbol;
    std::vector<Arbol::Node> *nodosB = new std::vector<Arbol::Node>;
    Arbol *arbolA = new Arbol;
    std::vector<Arbol::Node> *nodosA = new std::vector<Arbol::Node>;
    Arbol *arbolP = new Arbol;
    std::vector<Arbol::Node> *nodosP = new std::vector<Arbol::Node>;

    CrearArbolSemiBalanceado(arbolB, nodosB, 100);
    CrearArbolUltraAncho(arbolA, nodosA, 100);
    CrearArbolUltraProfundo(arbolP, nodosP, 100);

    std::cout << "Balanceados:" << std::endl;
    std::cout << "\tEtiqRept:";
    TestAlgEtiqRepetidas(arbolB);
    std::cout << "\tListHijs:";
    TestAlgListarHijos(arbolB, nodosB);
    std::cout << "\tProfNodo:";
    TestAlgProfundidadNodo(arbolB, nodosB);
    std::cout << "\tBorrSubA:";
    TestAlgBorrarSubArbol(arbolB, nodosB);

    delete arbolB;
    delete nodosB;

    std::cout << "Anchos:" << std::endl;
    std::cout << "\tEtiqRept:";
    TestAlgEtiqRepetidas(arbolA);
    std::cout << "\tListHijs:";
    TestAlgListarHijos(arbolA, nodosA);
    std::cout << "\tProfNodo:";
    TestAlgProfundidadNodo(arbolA, nodosA);
    std::cout << "\tBorrSubA:";
    TestAlgBorrarSubArbol(arbolA, nodosA);

    delete arbolA;
    delete nodosA;

    std::cout << "Profundos:" << std::endl;
    std::cout << "\tEtiqRept:";
    TestAlgEtiqRepetidas(arbolP);
    std::cout << "\tListHijs:";
    TestAlgListarHijos(arbolP, nodosP);
    std::cout << "\tProfNodo:";
    TestAlgProfundidadNodo(arbolP, nodosP);
    std::cout << "\tBorrSubA:";
    TestAlgBorrarSubArbol(arbolP, nodosP);

    delete arbolP;
    delete nodosP;
}

void Tiempos::CrearArbolSemiBalanceado(
    Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(
        0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
    // generador de randoms listo
    A->PonerRaiz(randomChar);
    vecNodes->push_back(A->getNodo(randomChar));
    int posicion;
    int numHijos;
    int j = 0;
    // seteo inicial listo
    for (int i = 0; i < n - 1; ++i) {
        if (vecNodes->size() <= n) {
            randomChar = characterSet[distribution(rng)];
            posicion = 1;
            numHijos = A->NumHijos((*vecNodes)[j]);
            if (numHijos == 1) {
                ++posicion;
            } else if (numHijos == 2) {
                ++j;
            }
            vecNodes->push_back(
                A->AgregarHijo((*vecNodes)[j], randomChar, posicion));

        } else {
            i = n;
        }
    }
}

void Tiempos::CrearArbolUltraAncho(
    Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(
        0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
    // generador de randoms listo
    A->PonerRaiz(randomChar);
    Arbol::Node nodoRaiz = A->getNodo(randomChar);
    vecNodes->push_back(nodoRaiz);
    // seteo inicial listo
    for (int i = 1; i < n; ++i) {
        randomChar = characterSet[distribution(rng)];
        vecNodes->push_back(A->AgregarHijo(nodoRaiz, randomChar, i));
    }
}

void Tiempos::CrearArbolUltraProfundo(
    Arbol *&A, std::vector<Arbol::Node> *&vecNodes, int n) {
    std::mt19937 rng(std::time(0));
    const std::string characterSet =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    std::uniform_int_distribution<std::size_t> distribution(
        0, characterSet.size() - 1);
    char randomChar = characterSet[distribution(rng)];
    // generador de randoms listo
    A->PonerRaiz(randomChar);
    vecNodes->push_back(A->getNodo(randomChar));
    // seteo inicial listo
    for (int i = 0; i < n - 1; ++i) {
        randomChar = characterSet[distribution(rng)];
        vecNodes->push_back(A->AgregarHijo((*vecNodes)[i], randomChar, 1));
    }
}

/*
------------------------
TEST DE LOS ALGORITMOS
------------------------
*/

void Tiempos::TestAlgEtiqRepetidas(Arbol *A) {
    Algoritmos alg;

    auto start = std::chrono::high_resolution_clock::now();
    alg.EtiqRepetidas(A);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    int64_t durationInNanoseconds = duration.count();

    std::cout << "\tTIEM: " << std::left << std::setw(10)
              << durationInNanoseconds << std::endl;
}

void Tiempos::TestAlgListarHijos(Arbol *A, std::vector<Arbol::Node> *vecNodes) {
    Algoritmos alg;
    int64_t peorTiempo = 0;
    int64_t promTiempo = 0;
    int vecSize = vecNodes->size();
    freopen("salida.txt", "w", stdout);

    for (int i = 0; i < vecSize; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        alg.ListarHijos(A, (*vecNodes)[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        int64_t durationInNanoseconds = duration.count();
        promTiempo += durationInNanoseconds;
        if (durationInNanoseconds > peorTiempo) {
            peorTiempo = durationInNanoseconds;
        }
    }

    freopen("/dev/tty", "w", stdout); // Para Linux
    // freopen("CON", "w", stdout); Para windows

    promTiempo = promTiempo / vecSize;
    std::cout << "\tPEOR: " << std::left << std::setw(10) << peorTiempo
              << " PROM: " << std::left << std::setw(10) << promTiempo
              << std::endl;
}

void Tiempos::TestAlgProfundidadNodo(
    Arbol *A, std::vector<Arbol::Node> *vecNodes) {
    Algoritmos alg;
    int64_t peorTiempo = 0;
    int64_t promTiempo = 0;
    int vecSize = vecNodes->size();

    for (int i = 0; i < vecSize; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        alg.ProfundidadNodo(A, (*vecNodes)[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        int64_t durationInNanoseconds = duration.count();
        promTiempo += durationInNanoseconds;
        if (durationInNanoseconds > peorTiempo) {
            peorTiempo = durationInNanoseconds;
        }
    }

    promTiempo = promTiempo / vecSize;
    std::cout << "\tPEOR: " << std::left << std::setw(10) << peorTiempo
              << " PROM: " << std::left << std::setw(10) << promTiempo
              << std::endl;
}

void Tiempos::TestAlgBorrarSubArbol(
    Arbol *A, std::vector<Arbol::Node> *vecNodes) {
    Algoritmos alg;
    int64_t peorTiempo = 0;
    int64_t promTiempo = 0;
    int vecSize = vecNodes->size();

    for (int i = vecSize - 1; i >= 0; --i) {
        auto start = std::chrono::high_resolution_clock::now();
        alg.BorrarSubArbol(A, (*vecNodes)[i]);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration =
            std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
        int64_t durationInNanoseconds = duration.count();
        promTiempo += durationInNanoseconds;
        if (durationInNanoseconds > peorTiempo) {
            peorTiempo = durationInNanoseconds;
        }
    }

    promTiempo = promTiempo / vecSize;
    std::cout << "\tPEOR: " << std::left << std::setw(10) << peorTiempo
              << " PROM: " << std::left << std::setw(10) << promTiempo
              << std::endl;
}
