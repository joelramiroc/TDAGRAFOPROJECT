//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_CIRCULOVERTICE_H
#define GRAFOPROYECTO_CIRCULOVERTICE_H
#include<iostream>
#include <cstring>
#include"grafo.h"
#include "Vertice.h"
#include <iostream>

using namespace std;

class Vertice;
class circuloVertice
{
    string ruta;
public:
    string name;
    int x,y;
    Vertice* representavertice;
    circuloVertice();
    bool createVertice(string name, int x, int y);

    bool operator ==(circuloVertice m) {
        return this->name == m.name;
    }
};


#endif //GRAFOPROYECTO_CIRCULOVERTICE_H
