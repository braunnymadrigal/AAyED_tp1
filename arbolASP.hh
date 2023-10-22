#pragma once

class Arbol {
public:
  struct Nodo {
    char etiqueta;
    int padre;
  };

  // Create a type alias for the Nodo structure using 'using'
  using Node = int;

public:
  Arbol() { this->Iniciar(); }

  ~Arbol() { this->Destruir(); }

  void Iniciar() {
    this->raiz = -1;
    this->ultimo = -1;
  }

  void Destruir() {}

  void Vaciar() {
    this->raiz = -1;
    this->ultimo = -1;
  }

  bool Vacio() { return raiz == -1; }

  void PonerRaiz(char etiqueta) {
    Nodo nuevoNodo;
    nuevoNodo.etiqueta = etiqueta;
    nuevoNodo.padre = -1;

    this->arbol[0] = nuevoNodo;
    this->raiz = 0;
    this->ultimo = 0;
  }

  Nodo AgregarHijo(int nodoPadre, char etiqueta, int lugarDelHijo) {
    int cantHijos = 0;
    int i = nodoPadre + 1;
    while ((cantHijos + 1) != lugarDelHijo && i <= this->tamArbol) {
      if (this->arbol[i].padre == nodoPadre) {
        ++cantHijos;
      }
      ++i;
    }
    this->abrirCampo(i);
    Nodo nuevoNodo;
    nuevoNodo.etiqueta = etiqueta;
    nuevoNodo.padre = nodoPadre;
    arbol[i] = nuevoNodo;
    ++this->ultimo;
    return nuevoNodo;
  }

  void BorrarHoja(int nodo) {
    this->cerrarCampo(nodo);
    --this->ultimo;
  }

  void ModificarEtiqueta(int nodo, char etiqNueva) {
    this->arbol[nodo].etiqueta = etiqNueva;
  }

  int Raiz() { return this->raiz; }

  char Etiqueta(int nodo) { return this->arbol[nodo].etiqueta; }

  int Padre(int nodo) { return this->arbol[nodo].padre; }

  int HijoMasIzq(int nodoPadre) {
    int hijoIzq = -1;

    int i = nodoPadre + 1;
    while (this->arbol[i].padre != nodoPadre && i <= this->ultimo) {
      ++i;
    }

    if (i < this->ultimo + 1) {
      hijoIzq = i;
    }

    return hijoIzq;
  }

  int HermanoDer(int nodo) {
    int hermDer = -1;

    int padre = this->arbol[nodo].padre;
    int i = nodo + 1;
    while (this->arbol[i].padre != padre && i <= this->ultimo) {
      ++i;
    }

    if (i != this->ultimo + 1) {
      hermDer = i;
    }

    return hermDer;
  }

  int NumNodos() { return this->ultimo + 1; }

  int NumHijos(int padre) {
    int hijos = 0;

    for (int i = padre + 1; i <= this->ultimo; ++i) {
      if (this->arbol[i].padre == padre) {
        ++hijos;
      }
    }

    return hijos;
  }

  int getNodo(char etiqueta) {
    int nodo = this->raiz;

    while (this->arbol[nodo].etiqueta != etiqueta && nodo <= this->tamArbol) {
      ++nodo;
    }

    return nodo;
  }

private:
  void abrirCampo(int i) {
    int nodoAux = this->ultimo + 1;
    while (nodoAux > i) {
      this->arbol[nodoAux] = this->arbol[nodoAux - 1];
      --nodoAux;
    }
  }

  void cerrarCampo(int i) {
    while (i < this->ultimo) {
      this->arbol[i] = this->arbol[i + 1];
      ++i;
    }
  }

private:
  Nodo arbol[20];
  int raiz;
  int ultimo;
  int tamArbol = 20;
};
