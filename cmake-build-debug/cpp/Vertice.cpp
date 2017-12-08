//
// Created by DELL 5040 I7 on 12/7/2017.
//

#include "../hd/Vertice.h"
Vertice::Vertice()
{
    this->aristas = new Lista<Arista*>();
    this->nombre="";
    this->dibujado=nullptr;
}