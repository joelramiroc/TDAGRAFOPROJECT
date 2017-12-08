//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_ARISTA_H
#define GRAFOPROYECTO_ARISTA_H

#include<iostream>
#include"vertice.h"

using namespace std;

class Vertice;

class Arista
{
public:
    Arista();
    Vertice* verticeInicial;
    Vertice* verticeFinal;
    int peso;
    string id;
    bool operator ==(Arista m) {
        return this->id == m.id;
    }
};

#endif //GRAFOPROYECTO_ARISTA_H
