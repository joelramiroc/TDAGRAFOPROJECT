//
// Created by DELL 5040 I7 on 12/7/2017.
//

#ifndef GRAFOPROYECTO_INFORMATION_H
#define GRAFOPROYECTO_INFORMATION_H

#include<iostream>
using namespace std;

class Information
{
public:
    Information(string inicio,string fin, int peso);
    string nombreInicio;
    string nombreFin;
    int peso;
    bool operator ==(Information m) {
        if(nombreInicio==m.nombreInicio && nombreFin== m.nombreFin)
            return true;
        return false;
    }
};

#endif //GRAFOPROYECTO_INFORMATION_H
