#pragma once

class Arbol {
public:
    struct Nodo {
        char etiqueta;
        Nodo *hijoIzq;
        Nodo *hermanoDer;
    };

    // Create a type alias for the Nodo structure using 'using'
    using Node = Nodo *;
    // Define NodoNulo as an specific value accordingly to the data structure
    Nodo *NodoNulo = nullptr;

public:
    Arbol() { this->Crear(); }

    ~Arbol() { this->Destruir(); }

    void Crear() { this->raiz = nullptr; }

    void Destruir() {
        this->Vaciar();
        delete this->raiz;
    }

    void Vaciar() {
        VaciarPostOrden(this->raiz);
        this->raiz = nullptr;
    }

    bool Vacio() { return (this->raiz == nullptr); }

    void PonerRaiz(char etiqueta) {
        if (this->raiz == nullptr) {
            Nodo *nuevoNodo = new Nodo;
            nuevoNodo->etiqueta = etiqueta;
            this->raiz = nuevoNodo;
        }
    }

    Nodo *AgregarHijo(Nodo *nodoPadre, char etiqueta, int lugarDelHijo) {
        Nodo *nodoHijo = nodoPadre->hijoIzq;
        int cantHijos = 0;

        while (cantHijos + 1 != lugarDelHijo && nodoHijo != nullptr) {
            ++cantHijos;
            if (cantHijos + 1 != lugarDelHijo &&
                nodoHijo->hermanoDer != nullptr) {
                nodoHijo = nodoHijo->hermanoDer;
            }
        }
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->etiqueta = etiqueta;

        if (cantHijos == 0) {
            nodoPadre->hijoIzq = nuevoNodo;
            nuevoNodo->hermanoDer = nodoHijo;
        } else {
            Nodo *aux = nodoHijo->hermanoDer;
            nodoHijo->hermanoDer = nuevoNodo;
            nuevoNodo->hermanoDer = aux;
        }

        return nuevoNodo;
    }

    void BorrarHoja(Nodo *nodo) {
        Nodo *nodoPadre = this->Padre(nodo);

        if (nodoPadre != nullptr) {
            if (nodoPadre->hijoIzq == nodo) {
                nodoPadre->hijoIzq = nodo->hermanoDer;
            } else {
                Nodo *hermanoIzq = nodoPadre->hijoIzq;
                while (hermanoIzq->hermanoDer != nodo) {
                    hermanoIzq = hermanoIzq->hermanoDer;
                }
                hermanoIzq->hermanoDer = nodo->hermanoDer;
            }
        } else {
            this->raiz = nullptr;
        }

        delete nodo;
    }

    Nodo *Padre(Nodo *nodo) {
        Nodo *nodoPadre = nullptr;
        if (!this->Vacio()) {
            PadrePreOrdenR(nodo, nodoPadre, this->raiz);
        }

        return nodoPadre;
    }

    char Etiqueta(Nodo *nodo) { return nodo->etiqueta; }

    void ModificarEtiqueta(Nodo *nodo, char etiqNueva) {
        nodo->etiqueta = etiqNueva;
    }

    Nodo *Raiz() { return this->raiz; }

    Nodo *HijoMasIzq(Nodo *nodo) { return nodo->hijoIzq; }

    Nodo *HermanoDer(Nodo *nodo) { return nodo->hermanoDer; }

    int NumNodos() {
        int cantNodos = 0;
        if (!this->Vacio()) {
            ++cantNodos;
            numNodosPreOrdenR(this->raiz, cantNodos);
        }

        return cantNodos;
    }

    int NumHijos(Nodo *nodo) {
        int hijos = 0;
        Nodo *nh = nodo->hijoIzq;
        while (nh != nullptr) {
            ++hijos;
            nh = nh->hermanoDer;
        }
        return hijos;
    }

    Nodo *getNodo(char etiqueta) {
        Nodo *nodo = nullptr;
        if (!this->Vacio()) {
            getNodoPreOrdenR(etiqueta, nodo, this->raiz);
        }

        return nodo;
    }

private:
    void VaciarPostOrden(Nodo *nodo) {
        if (nodo != nullptr) {
            VaciarPostOrden(nodo->hijoIzq);
            VaciarPostOrden(nodo->hermanoDer);
        }
        delete nodo;
    }

    void PadrePreOrdenR(Nodo *nodo, Nodo *&nodoPadre, Nodo *nodoActual) {
        Nodo *nodoHijo = nodoActual->hijoIzq;

        while (nodoPadre == nullptr && nodoHijo != nullptr) {
            if (nodoHijo == nodo) {
                nodoPadre = nodoActual;
            } else {
                PadrePreOrdenR(nodo, nodoPadre, nodoHijo);
                nodoHijo = nodoHijo->hermanoDer;
            }
        }
    }

    void numNodosPreOrdenR(Nodo *nodo, int &cantNodos) {
        Nodo *nodoHijo = nodo->hijoIzq;

        while (nodoHijo != nullptr) {
            ++cantNodos;
            numNodosPreOrdenR(nodoHijo, cantNodos);
            nodoHijo = nodoHijo->hermanoDer;
        }
    }

    void getNodoPreOrdenR(char etiqueta, Nodo *&nodo, Nodo *nodoActual) {
        if (nodo == nullptr && nodoActual != nullptr &&
            nodoActual->etiqueta == etiqueta) {
            nodo = nodoActual;
        } else {
            Nodo *nodoHijo = nodoActual->hijoIzq;
            while (nodo == nullptr && nodoHijo != nullptr) {
                getNodoPreOrdenR(etiqueta, nodo, nodoHijo);
                nodoHijo = nodoHijo->hermanoDer;
            }
        }
    }

private:
    Nodo *raiz;
};
