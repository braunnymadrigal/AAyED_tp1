#pragma once

class Arbol {
public:
  struct Nodo {
    char etiqueta;
    bool ultHijo;
    Nodo *hmi;
    Nodo *hd;
  };

  // Create a type alias for the Nodo structure using 'using'
  using Node = Nodo *;
  // Define NodoNulo as an specific value accordingly to the data structure
  Nodo* NodoNulo = nullptr;

public:
  Arbol() { this->Iniciar(); }

  ~Arbol() { this->Destruir(); }

  void Iniciar() { raiz = nullptr; }

  void Destruir() {
    this->Vaciar();
    delete this->raiz;
  }

  void Vaciar() {
    VaciarR(this->raiz, nullptr);
    this->raiz = nullptr;
  }

  bool Vacio() { return raiz == nullptr; }

  void PonerRaiz(char e) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->etiqueta = e;
    nuevoNodo->ultHijo = 1;
    nuevoNodo->hmi = nullptr;
    nuevoNodo->hd = nullptr;
    raiz = nuevoNodo;
  }

  Nodo *AgregarHijo(Nodo *n, char e, int i) {
    Nodo *nodoPadre = n;
    Nodo *nodoHijo = nodoPadre->hmi;
    int cantHijos = 0;

    while (cantHijos + 1 != i && nodoHijo != nullptr) {
      ++cantHijos;
      if (cantHijos + 1 != i && nodoHijo->hd != nullptr &&
          nodoHijo->hd != nodoPadre) {
        Nodo *nAux = nodoHijo->hd;
        if (nAux == nodoPadre) {
          nodoHijo = nullptr;
        } else {
          nodoHijo = nAux;
        }
      }
    }

    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->etiqueta = e;
    nuevoNodo->ultHijo = 0;
    nuevoNodo->hmi = nullptr;
    nuevoNodo->hd = nullptr;

    if (cantHijos == 0) {
      nodoPadre->hmi = nuevoNodo;
      nuevoNodo->hd = nodoHijo;
      if (nuevoNodo->hd == nullptr) {
        nuevoNodo->hd = n;
        nuevoNodo->ultHijo = 1;
      }
    } else {
      Nodo *aux = nodoHijo->hd;
      nodoHijo->hd = nuevoNodo;
      nuevoNodo->hd = aux;
      if (nuevoNodo->hd == nodoPadre) {
        nuevoNodo->ultHijo = 1;
        nodoHijo->ultHijo = 0;
      }
    }
    return nuevoNodo;
  }

  void BorrarHoja(Nodo *nodo) {
    Nodo *nodoPadre = this->Padre(nodo);

    if (nodoPadre != nullptr) {
      if (nodoPadre->hmi == nodo) {
        nodoPadre->hmi = nodo->hd;
        if (nodo->hd == nodoPadre) {
          nodoPadre->hmi = nullptr;
        } else {
          if (nodo->hd->hd == nodoPadre) {
            nodo->hd->ultHijo = 1;
          }
        }
      } else {
        Nodo *hermanoIzq = nodoPadre->hmi;
        while (hermanoIzq->hd != nodo) {
          hermanoIzq = hermanoIzq->hd;
        }
        hermanoIzq->hd = nodo->hd;
        if (hermanoIzq->hd == nodoPadre) {
          hermanoIzq->ultHijo = 1;
        }
      }
    } else {
      this->raiz = nullptr;
    }

    delete nodo;
  }

  void ModificarEtiqueta(Nodo *n, char e) { n->etiqueta = e; }

  Nodo *Raiz() { return raiz; }

  Nodo *Padre(Nodo *n) {
    Nodo *nPadre = nullptr;
    Nodo *nAct = n;
    while (nAct != nullptr && nAct->ultHijo == 0) {
      nAct = nAct->hd;
    }
    if (nAct != nullptr) {
      nPadre = nAct->hd;
    }
    return nPadre;
  }

  Nodo *HijoMasIzq(Nodo *n) { return n->hmi; }

  Nodo *HermanoDer(Nodo *n) { return n->hd; }

  char Etiqueta(Nodo *n) { return n->etiqueta; }

  int NumHijos(Nodo *n) {
    int hijos = 0;
    Nodo *nh = n->hmi;
    while (nh != nullptr && nh != n) {
      ++hijos;
      nh = nh->hd;
    }
    return hijos;
  }

  int NumNodos() {
    int nodos = 0;
    if (!this->Vacio()) {
      NumNodosR(this->Raiz(), nodos);
    }
    return nodos;
  }

  Nodo *getNodo(char etiqueta) {
    Nodo *nodo = nullptr;
    if (!this->Vacio()) {
      getNodoR(etiqueta, nodo, this->raiz);
    }

    return nodo;
  }

private:
  void VaciarR(Nodo *nodoA, Nodo *nodoP) {
    if (nodoA != nullptr) {
      VaciarR(nodoA->hmi, nodoA);
      if (nodoA->hd == nodoP) {
        VaciarR(nullptr, nodoP);
      } else {
        VaciarR(nodoA->hd, nodoP);
      }
    }
    delete nodoA;
  }

  void NumNodosR(Nodo *n, int &nodos) {
    ++nodos;
    Nodo *nAuxPadre = n;
    n = this->HijoMasIzq(n);
    while (n != nullptr) {
      NumNodosR(n, nodos);
      Nodo *nAux = this->HermanoDer(n);
      if (nAux == nAuxPadre) {
        n = nullptr;
      } else {
        n = nAux;
      }
    }
  }

  void getNodoR(char etiqueta, Nodo *&nodo, Nodo *nodoActual) {
    if (nodo == nullptr && nodoActual != nullptr &&
        nodoActual->etiqueta == etiqueta) {
      nodo = nodoActual;
    } else {
      Nodo *nAuxPadre = nodoActual;
      Nodo *nodoHijo = nodoActual->hmi;
      while (nodo == nullptr && nodoHijo != nullptr) {
        getNodoR(etiqueta, nodo, nodoHijo);
        Nodo *nAux = nodoHijo->hd;
        if (nAux == nAuxPadre) {
          nodoHijo = nullptr;
        } else {
          nodoHijo = nAux;
        }
      }
    }
  }

private:
  Nodo *raiz;
};
