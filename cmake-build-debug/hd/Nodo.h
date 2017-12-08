//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_NODO_H
#define GRAFOPROYECTO_NODO_H

template <class T>

class Nodo {
public:
    Nodo(T valor)
    {
        this->valor = valor;
        this->anterior  = nullptr;
        this->siguiente = nullptr;
    }
    T valor;
    Nodo* siguiente;
    Nodo* anterior;
};


#endif //GRAFOPROYECTO_NODO_H
