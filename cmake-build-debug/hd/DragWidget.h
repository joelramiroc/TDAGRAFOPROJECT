//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_DRAGWIDGET_H
#define GRAFOPROYECTO_DRAGWIDGET_H
#include <math.h>
#include<time.h>
#include <cString>
#include"grafo.h"
#include"arraylist.h"
#include "circulovertice.h"
#include"Information.h"
#include"circulovertice.h"
#include"pila.h"
#include"cola.h"
#include <iostream>
using namespace std;
class DragWidget {

public:

    DragWidget();
    string grafoActual;
    Lista<circuloVertice*>* listaCirculosGrafo;
    Grafo* grafoPrincipal;
    Grafo* imprimir;
    Grafo* grafoFloyd;
    Grafo* grafoWarshall;
    Grafo* grafoDijkstra;
    Grafo* prim;
    Grafo* kruskal;
    ArrayListP<Vertice*>* arrayD;
    bool relleno=true;
    int peso;
    int x1=0,x2=300,y1=3,y2=300;
    void grafoToWarshall();
    void grafoToPrincipal();
    void copyGraphto(Grafo* nuevo);
    void grafoToFloyd();
    void grafoToDjikstra();
    void recorridoAnchura();
    void recorridoProfundidad();
    void grafoPrim();
    void grafoKruskal();
    void update();

};


#endif //GRAFOPROYECTO_DRAGWIDGET_H
