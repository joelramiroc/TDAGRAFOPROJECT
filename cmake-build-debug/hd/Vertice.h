//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_VERTICE_H
#define GRAFOPROYECTO_VERTICE_H

#include"arista.h"
#include"lista.h"
#include"circulovertice.h"
#include<iostream>
using namespace std;

class Arista;
class circuloVertice;
class Vertice
{
public:
    Vertice();
    string nombre;
    Lista<Arista*>* aristas;
    circuloVertice* dibujado;
    bool operator ==(Vertice m) {
        return this->nombre == m.nombre;
    }
};

#endif //GRAFOPROYECTO_VERTICE_H
