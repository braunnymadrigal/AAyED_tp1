#pragma once

class Arbol {
public:
  Arbol() { Iniciar(); }

  ~Arbol() { Destruir(); }

  void Iniciar() { raiz = nullptr; }

  void Destruir() {
    while (raiz != nullptr) {
      Nodo *raizAux = raiz;
      SubLista *subL = raizAux->sublista;
      while (subL != nullptr) {
        SubLista *subLAux = subL;
        subL = subL->siguiente;
        delete subLAux;
      }
      raiz = raiz->abajo;
      delete raizAux;
    }
  }

  void Vaciar() {
    Destruir();
    raiz = nullptr;
  }

  bool Vacio() { return raiz == nullptr; }

  void PonerRaiz(char e) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->etiqueta = e;
    nuevoNodo->abajo = nullptr;
    nuevoNodo->sublista = nullptr;
    raiz = nuevoNodo;
  }

  Nodo *AgregarHijo(Nodo *n, char e, int i) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->etiqueta = e;
    nuevoNodo->abajo = nullptr;
    nuevoNodo->sublista = nullptr;

    Nodo *nodoAct = n;
    while (nodoAct->abajo != nullptr) {
      nodoAct = nodoAct->abajo;
    }
    nodoAct->abajo = nuevoNodo;

    SubLista *nuevoSub = new SubLista;
    nuevoSub->siguiente = nullptr;
    nuevoSub->nodoOrg = nodoAct->abajo;

    if (i == 1) {
      nuevoSub->siguiente = n->sublista;
      n->sublista = nuevoSub;
    } else {
      SubLista *actual = n->sublista;
      int j = 1;

      while (j < i - 1) {
        actual = actual->siguiente;
        ++j;
      }

      nuevoSub->siguiente = actual->siguiente;
      actual->siguiente = nuevoSub;
    }

    return nuevoNodo;
  }

  void BorrarHoja(Nodo *n) {

    bool borrado = false;
    Nodo *nodoAct = raiz;
    while (!borrado && nodoAct != nullptr) {
      SubLista *subAnt = nullptr;
      SubLista *subAct = nodoAct->sublista;
      while (!borrado && subAct != nullptr) {
        if (subAct->nodoOrg == n) {
          if (subAnt == nullptr) {
            nodoAct->sublista = subAct->siguiente;
          } else {
            subAnt->siguiente = subAct->siguiente;
          }
          delete subAct;
          borrado = true;
        } else {
          subAnt = subAct;
          subAct = subAct->siguiente;
        }
      }
      nodoAct = nodoAct->abajo;
    }
    borrado = false;
    Nodo *nodoAnt = nullptr;
    nodoAct = raiz;
    while (!borrado && nodoAct != nullptr) {
      if (nodoAct == n) {
        if (nodoAnt == nullptr) {
          raiz = nodoAct->abajo;
        } else {
          nodoAnt->abajo = nodoAct->abajo;
        }
        delete nodoAct;
        borrado = true;
      } else {
        nodoAnt = nodoAct;
        nodoAct = nodoAct->abajo;
      }
    }
  }

  void ModificarEtiqueta(Nodo *n, char e) { n->etiqueta = e; }

  Nodo *Raiz() { return raiz; }

  Nodo *Padre(Nodo *n) {
    Nodo *padre = nullptr;
    Nodo *nAct = raiz;
    while (nAct != nullptr && padre == nullptr) {
      SubLista *subLAct = nAct->sublista;
      while (subLAct != nullptr && padre == nullptr) {
        if (subLAct->nodoOrg == n) {
          padre = nAct;
        } else {
          subLAct = subLAct->siguiente;
        }
      }
      nAct = nAct->abajo;
    }
    return padre;
  }

  Nodo *HijoMasIzq(Nodo *n) {
    Nodo *hmi = nullptr;
    if (n->sublista != nullptr) {
      hmi = n->sublista->nodoOrg;
    }
    return hmi;
  }

  Nodo *HermanoDer(Nodo *n) {
    Nodo *hd = nullptr;
    Nodo *nAct = raiz;
    bool encontrado = false;
    while (nAct != nullptr && !encontrado) {
      SubLista *subLAct = nAct->sublista;
      while (subLAct != nullptr && !encontrado) {
        if (subLAct->nodoOrg == n) {
          encontrado = true;
          if (subLAct->siguiente != nullptr) {
            hd = subLAct->siguiente->nodoOrg;
          }
        } else {
          subLAct = subLAct->siguiente;
        }
      }
      nAct = nAct->abajo;
    }
    return hd;
  }

  char Etiqueta(Nodo *n) { return n->etiqueta; }

  int NumNodos() {
    int numNodos = 0;
    Nodo *nAct = raiz;
    while (nAct != nullptr) {
      ++numNodos;
      nAct = nAct->abajo;
    }
    return numNodos;
  }

  int NumHijos(Nodo *n) {
    int numHijos = 0;
    SubLista *subLAct = n->sublista;
    while (subLAct != nullptr) {
      ++numHijos;
      subLAct = subLAct->siguiente;
    }
    return numHijos;
  }

  Nodo *getNodo(char e) {
    Nodo *nodoEquivalente = nullptr;
    Nodo *nAct = raiz;
    while (nAct != nullptr && nodoEquivalente == nullptr) {
      if (nAct->etiqueta == e) {
        nodoEquivalente = nAct;
      } else {
        nAct = nAct->abajo;
      }
    }
    return nodoEquivalente;
  }

private:
  struct SubLista;

  struct Nodo {
    char etiqueta;
    Nodo *abajo;
    SubLista *sublista;
  };

  struct SubLista {
    SubLista *siguiente;
    Nodo *nodoOrg;
  };

  Nodo *raiz;
};
