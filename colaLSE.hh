#pragma once

template <typename T> class Cola {
public:
    Cola() { Iniciar(); }

    ~Cola() { Destruir(); }

    void Iniciar() {
        primero = nullptr;
        ultimo = nullptr;
    }

    void Destruir() {
        while (primero != nullptr) {
            Caja *primeroAux = primero;
            primero = primero->siguiente;
            delete primeroAux;
        }
    }

    void Vaciar() {
        Destruir();
        primero = nullptr;
        ultimo = nullptr;
    }

    bool Vacio() { return primero == nullptr; }

    void Encolar(T e) {
        Caja *nuevaCaja = new Caja;
        nuevaCaja->elemento = e;
        nuevaCaja->siguiente = nullptr;
        if (primero == nullptr) {
            primero = nuevaCaja;
            ultimo = nuevaCaja;
        } else {
            ultimo->siguiente = nuevaCaja;
            ultimo = ultimo->siguiente;
        }
    }

    T Desencolar() {
        Caja *primeroAux = primero;
        primero = primero->siguiente;
        T e = primeroAux->elemento;
        if (primeroAux == ultimo) {
            ultimo = ultimo->siguiente;
        }
        delete primeroAux;
        return e;
    }

    T Frente() { return primero->elemento; }

private:
    struct Caja {
        T elemento;
        Caja *siguiente;
    };

    Caja *primero;
    Caja *ultimo;
};
