//
// Created by DELL 5040 I7 on 12/7/2017.
//

#include "../hd/CirculoVertice.h"

circuloVertice::circuloVertice()
{
    this->representavertice=nullptr;
    this->name="";
    this->x=0;
    this->y=0;
    this->name="";
    this->ruta=("C:/Users/DELL 5040 I7/Documents/ProyectoGrafo/images/vertice.png");
}

bool circuloVertice::createVertice(string name,int x, int y)
{
    this->name=name;
    this->x=x;
    this->y=y;
    return true;
}