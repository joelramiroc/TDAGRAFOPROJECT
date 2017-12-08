//
// Created by DELL 5040 I7 on 12/7/2017.
//

#include "../hd/DragWidget.h"

DragWidget::DragWidget()
{
    this->grafoActual="Normal";
    this->listaCirculosGrafo = new Lista<circuloVertice*>();
    this->grafoPrincipal = new Grafo();
    this->imprimir = grafoPrincipal;
    this->peso = 0;
}

void DragWidget::grafoToWarshall()
{
    this->grafoWarshall = new Grafo();
    this->copyGraphto(grafoWarshall);
    Nodo<Vertice*>* pivote=this->grafoWarshall->listaVertices->getFirst(),*desde,*hasta;
    while(pivote!=nullptr)
    {
        desde=this->grafoWarshall->listaVertices->getFirst();
        while(desde!=nullptr)
        {
            hasta=this->grafoWarshall->listaVertices->getFirst();
            while(hasta!=nullptr)
            {
                if(this->grafoWarshall->existeArista(desde->valor,pivote->valor) && this->grafoWarshall->existeArista(pivote->valor,hasta->valor))
                {
                    int peso = this->grafoWarshall->pesoTotal(desde->valor,pivote->valor) + this->grafoWarshall->pesoTotal(pivote->valor,hasta->valor);
                    int pesoActual=this->grafoWarshall->pesoTotal(desde->valor,hasta->valor);
                    if(pesoActual==-1)
                    {
                        this->grafoWarshall->insertarArista(desde->valor,hasta->valor,peso);
                    }
                }
                hasta = hasta->siguiente;
            }
            desde = desde->siguiente;
        }
        pivote = pivote->siguiente;
    }
    this->grafoActual="Warshall";
    update();
}

void DragWidget::grafoToPrincipal()
{
    this->grafoActual="Normal";
    this->imprimir=this->grafoPrincipal;
    this->update();
}

void DragWidget::grafoToFloyd()
{
    this->grafoFloyd = new Grafo();
    this->copyGraphto(grafoFloyd);
    Arista* arista;
    Nodo<Vertice*>* pivote=this->grafoFloyd->listaVertices->getFirst(),*desde,*hasta;

    while(pivote!=nullptr)
    {
        desde=this->grafoFloyd->listaVertices->getFirst();
        while(desde!=nullptr)
        {
            hasta=this->grafoFloyd->listaVertices->getFirst();
            while(hasta!=nullptr)
            {
                if(this->grafoFloyd->existeArista(desde->valor,pivote->valor) && this->grafoFloyd->existeArista(pivote->valor,hasta->valor))
                {
                    arista = this->grafoFloyd->getArista(desde->valor,hasta->valor);
                    int peso = this->grafoFloyd->pesoTotal(desde->valor,pivote->valor) + this->grafoFloyd->pesoTotal(pivote->valor,hasta->valor);
                    int pesoActual=this->grafoFloyd->pesoTotal(desde->valor,hasta->valor);
                    if(arista==nullptr)
                    {
                        this->grafoFloyd->insertarArista(desde->valor,hasta->valor,peso);
                    }else
                    if(peso < pesoActual)
                    {
                        arista = this->grafoFloyd->getArista(desde->valor,hasta->valor);
                        arista->peso=peso;
                    }else if(pesoActual==-1)
                    {
                        this->grafoFloyd->insertarArista(desde->valor,hasta->valor,peso);
                    }
                }
                hasta = hasta->siguiente;
            }
            desde = desde->siguiente;
        }
        pivote = pivote->siguiente;
    }
    this->grafoActual="Floyd";
    update();
}

void DragWidget::grafoToDjikstra()
{
    this->grafoDijkstra = new Grafo();
    string nombrep;
    cout<<"Ingrese Nombre Vertice Inicial"<<endl;
    cin>>nombrep;
    if(this->grafoPrincipal->listaVertices->getSize()==0)
    {
        cout<<"Necesita tener por lo menos un vertice para poder ejecutar Dijkstra"<<endl;
        return;
    }else if(nombrep=="")
    {
        cout<<"Ingrese un vertice inicial para ejecutar Dijkstra"<<endl;
        return;
    }
    if(!this->grafoPrincipal->existeVertice(nombrep))
    {
        cout<<("Ingrese un nombre de vertice existente para poder ejecutar Dijkstra")<<endl;
        return;
    }
    arrayD= new ArrayListP<Vertice*>();
    if(this->grafoPrincipal->listaVertices->getSize()==0)
        return;
    bool visitado[this->grafoPrincipal->listaVertices->getSize()];
    int peso[this->grafoPrincipal->listaVertices->getSize()];
    Nodo<Vertice*>* temporal = this->grafoPrincipal->listaVertices->getFirst();
    Vertice*nuevo;
    while(temporal!=nullptr)
    {
        nuevo= new Vertice();
        nuevo->dibujado=temporal->valor->dibujado;
        nuevo->nombre=temporal->valor->nombre;
        arrayD->guardar(nuevo);
        temporal=temporal->siguiente;
    }
    int max = 2147483647;
    for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        visitado[i]=false;
        peso[i]=max;
        int a = peso[i];
        a=a;
    }
    Vertice* caminoInicio = new Vertice();
    caminoInicio = this->grafoPrincipal->getvertice(nombrep);
    int pos=arrayD->getPos(caminoInicio);
    visitado[pos]=true;
    Nodo<Arista*>* actualizando;
    Vertice*uGrafoPrincipalU;
    Vertice* uU = new Vertice();
    Vertice* buscar2 = new Vertice();
    int posFinal;
    actualizando=caminoInicio->aristas->getFirst();
    while(actualizando!=nullptr)
    {
        uU->nombre=actualizando->valor->verticeFinal->nombre;
        posFinal=this->arrayD->getPos(uU);
        peso[posFinal]=actualizando->valor->peso;
        actualizando=actualizando->siguiente;
    }

    int menor=pos,posicionfinal,pesoNuevo,peso1,peso2;
    Nodo<Arista*>* aristaRelajadora;
    for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        for(int j=0;j<this->grafoPrincipal->listaVertices->getSize();j++)
        {
            peso1=peso[j];
            for(int k=0;k<this->grafoPrincipal->listaVertices->getSize();k++)
            {
                peso2=peso[k];
                if(peso1<peso2 && !visitado[j])
                {
                    menor=j;
                }
            }
        }
        uU=arrayD->buscar(menor);
        visitado[menor]=true;

        uGrafoPrincipalU=this->grafoPrincipal->getvertice(uU->nombre);
        aristaRelajadora=uGrafoPrincipalU->aristas->getFirst();

        while(aristaRelajadora!=nullptr)
        {
            buscar2->nombre=aristaRelajadora->valor->verticeFinal->nombre;
            posicionfinal=arrayD->getPos(buscar2);
            pesoNuevo=peso[menor]+aristaRelajadora->valor->peso;

            if(peso[posicionfinal]>pesoNuevo)
            {
                peso[posicionfinal]=pesoNuevo;
            }
            aristaRelajadora= aristaRelajadora->siguiente;
        }
    }

    Vertice* paraCopiar,*finalCopiar,*devuelto;
    for(int i=0; i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        paraCopiar=arrayD->buscar(i);
        this->grafoDijkstra->insertarVertice(paraCopiar->nombre);
        devuelto=this->grafoDijkstra->getvertice(paraCopiar->nombre);
        devuelto->dibujado=paraCopiar->dibujado;
    }

    paraCopiar=this->grafoDijkstra->getvertice(nombrep);
    for(int i=0; i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        if(peso[i]!=max)
        {
            finalCopiar=arrayD->buscar(i);
            this->grafoDijkstra->insertarArista(paraCopiar->nombre,finalCopiar->nombre,peso[i]);
        }
    }
    this->grafoActual="Dijkstra";
    this->imprimir=grafoDijkstra;
    update();
}

void DragWidget::recorridoAnchura()
{
    string origenV;
    cout<<"Ingrese Nombre Vertice Inicial"<<endl;
    cin>>origenV;
    if(origenV=="")
    {
        cout<<("Necesita Ingresar un vertice de origen para el recorrido")<<endl;
        return;
    }
    Vertice* origen = this->grafoPrincipal->getvertice(origenV);
    if(origen==nullptr)
    {
        cout<<("No se encontro un vertice con ese nombre")<<endl;
        return;
    }

    Cola<Vertice*>* cola = new Cola<Vertice*>();
    ArrayListP<Vertice*>* listadoNuevo = new ArrayListP<Vertice*>();
    bool visitado[this->grafoPrincipal->listaVertices->getSize()];
    int saltos[this->grafoPrincipal->listaVertices->getSize()];
    Nodo<Vertice*>* recorrerr = this->grafoPrincipal->listaVertices->getFirst();
    Vertice*nuevo;

    while(recorrerr!=nullptr)
    {
        nuevo = new Vertice();
        nuevo->nombre=recorrerr->valor->nombre;
        listadoNuevo->guardar(nuevo);
        recorrerr = recorrerr->siguiente;
    }

    for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        visitado[i]=false;
        saltos[i]=-1;
    }

    int pos,peso=0,pos2;
    cola->push_back(origen);
    pos=listadoNuevo->getPos(origen);
    saltos[pos]=0;
    visitado[pos]=true;

    recorrerr = this->grafoPrincipal->listaVertices->getFirst();
    Nodo<Arista*>* recorrido;
    Vertice* obteniendo;
    while(!cola->empty())
    {
        obteniendo=cola->pop_front();
        recorrido=obteniendo->aristas->getFirst();
        while(recorrido!=nullptr)
        {
            pos=listadoNuevo->getPos(recorrido->valor->verticeFinal);

            if(!visitado[pos])
            {
                pos2=listadoNuevo->getPos(recorrido->valor->verticeInicial);
                peso=saltos[pos2];
                saltos[pos]=peso+1;
                visitado[pos]=true;
                cola->push_back(recorrido->valor->verticeFinal);
            }
            recorrido=recorrido->siguiente;
        }
    }

    Vertice* imprimir;
    string textos="";
    for(int i = 0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        imprimir=listadoNuevo->buscar(i);
        if(saltos[i]!=-1)
        {
            cout<<"Nombre: " + imprimir->nombre + ". Saltos:" + to_string( saltos[i])<<endl;
        }
    }
}

void DragWidget::copyGraphto(Grafo* nuevo)
{
    Nodo<Vertice*>* temporal = this->grafoPrincipal->listaVertices->getFirst();
    Nodo<Arista*>* temporalA;
    Vertice* circ;
    while(temporal!=nullptr)
    {
        nuevo->insertarVertice(temporal->valor->nombre);
        circ=nuevo->getvertice(temporal->valor->nombre);
        circ->dibujado=temporal->valor->dibujado;
        temporal=temporal->siguiente;
    }

    temporal = this->grafoPrincipal->listaVertices->getFirst();

    while(temporal!=nullptr)
    {
        temporalA =temporal->valor->aristas->getFirst();
        while(temporalA!=nullptr)
        {
            nuevo->insertarArista(temporalA->valor->verticeInicial->nombre,temporalA->valor->verticeFinal->nombre,temporalA->valor->peso);
            temporalA = temporalA->siguiente;
        }
        temporal=temporal->siguiente;
    }
    imprimir=nuevo;
}

void DragWidget::recorridoProfundidad()
{
    string origenV;
    cout<<"Ingrese vertice Inicial"<<endl;
    cin>>origenV;
    if(origenV=="")
    {
        cout<<("Necesita Ingresar un vertice de origen para el recorrido")<<endl;
        return;
    }
    Vertice* origen = this->grafoPrincipal->getvertice(origenV);
    if(origen==nullptr)
    {
        cout<<("No se encontro un vertice con ese nombre")<<endl;
        return;
    }

    Pila<Vertice*>* pila = new Pila<Vertice*>();
    ArrayListP<Vertice*>* listadoNuevo = new ArrayListP<Vertice*>();
    bool visitado[this->grafoPrincipal->listaVertices->getSize()];
    int padre[this->grafoPrincipal->listaVertices->getSize()];
    Nodo<Vertice*>* recorrerr = this->grafoPrincipal->listaVertices->getFirst();
    Vertice*nuevo;
    while(recorrerr!=nullptr)
    {
        nuevo = new Vertice();
        nuevo->nombre=recorrerr->valor->nombre;
        listadoNuevo->guardar(nuevo);
        recorrerr = recorrerr->siguiente;
    }

    for(int i=0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        visitado[i]=false;
        padre[i]=-1;
    }

    int pos,pos2;
    pila->push_back(origen);
    pos=listadoNuevo->getPos(origen);
    padre[pos]=0;
    visitado[pos]=true;
    recorrerr = this->grafoPrincipal->listaVertices->getFirst();
    Nodo<Arista*>* recorrido;
    Vertice* obteniendo;

    while(!pila->empty())
    {
        obteniendo=pila->pop_back();
        visitado[pos]=true;
        recorrido=obteniendo->aristas->getFirst();
        while(recorrido!=nullptr)
        {
            pos=listadoNuevo->getPos(recorrido->valor->verticeFinal);
            if(!visitado[pos])
            {
                pos2=listadoNuevo->getPos(recorrido->valor->verticeInicial);
                padre[pos]=pos2;
                pila->push_back(recorrido->valor->verticeFinal);
            }
            recorrido=recorrido->siguiente;
        }
    }

    Vertice* imprimir, *padreI;
    string textos="";
    for(int i = 0;i<this->grafoPrincipal->listaVertices->getSize();i++)
    {
        imprimir=listadoNuevo->buscar(i);
        if(padre[i]!=-1)
        {
            padreI=listadoNuevo->buscar(padre[i]);
            cout<<"Nombre:" + imprimir->nombre + ". Padre: " + padreI->nombre<<endl;
        }
    }
}

void DragWidget::grafoPrim()
{
    if(this->grafoPrincipal->listaVertices->getSize()==0)
    {
        cout<<("El Grafo esta vacio")<<endl;
        return;
    }
    Nodo<Vertice*>* Verticerecorrer = this->grafoPrincipal->listaVertices->getFirst();
    string origenV =(Verticerecorrer->valor->nombre);
    Vertice* origen = this->grafoPrincipal->getvertice(origenV);
    this->prim = new Grafo();
    Grafo* grafoNuevo = new Grafo();
    Vertice* temporal, *temporal2;
    while(Verticerecorrer!=nullptr)
    {
        temporal = new Vertice();
        temporal2 = new Vertice();
        temporal->nombre=Verticerecorrer->valor->nombre;
        temporal->dibujado=Verticerecorrer->valor->dibujado;
        temporal2->nombre=Verticerecorrer->valor->nombre;
        temporal2->dibujado=Verticerecorrer->valor->dibujado;
        prim->listaVertices->guardar(temporal);
        grafoNuevo->listaVertices->guardar(temporal2);
        Verticerecorrer = Verticerecorrer->siguiente;
    }

    Verticerecorrer = this->grafoPrincipal->listaVertices->getFirst();
    Nodo<Arista*>* Aristarecorrer;
    bool marcado[this->grafoPrincipal->listaVertices->getSize()];
    int posD=0;
    while(Verticerecorrer!=nullptr)
    {
        marcado[posD]=false;
        posD++;
        Aristarecorrer=Verticerecorrer->valor->aristas->getFirst();
        while(Aristarecorrer!=nullptr)
        {
            prim->insertarArista(Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->peso);
            prim->insertarArista(Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->peso);
            Aristarecorrer = Aristarecorrer->siguiente;
        }
        Verticerecorrer = Verticerecorrer->siguiente;
    }

    ArrayListP<Information*>* aristasComparar = new ArrayListP<Information*>();
    ArrayListP<Information*>* aristasFinales = new ArrayListP<Information*>();
    Information* guardar;

    Verticerecorrer=prim->listaVertices->buscar(origen);
    Aristarecorrer = Verticerecorrer->valor->aristas->getFirst();

    while(Aristarecorrer!=nullptr)
    {
        guardar = new Information(Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->peso);
        aristasComparar->guardar(guardar);
        Aristarecorrer = Aristarecorrer->siguiente;
    }
    posD=0;

    Nodo<Information*>*electo,*val;
    int mar,pos;
    mar=prim->listaVertices->getPos(origen);
    marcado[mar]=true;
    bool continuar=true;

    while(continuar)
    {

        continuar=false;
        electo=nullptr;
        pos=mar;
        for(int i=0;i<aristasComparar->getSize();i++)
        {
            val=aristasComparar->obtener(i);
            origen=prim->getvertice(val->valor->nombreFin);
            pos=prim->listaVertices->getPos(origen);
            if(!marcado[pos])
            {
                if(electo==nullptr)
                {
                    electo=val;
                }else if(val->valor->peso<electo->valor->peso){
                    electo=val;
                }
                continuar=true;
            }
        }

        if(continuar)
        {
            origen=prim->getvertice(electo->valor->nombreFin);
            pos=prim->listaVertices->getPos(origen);
            marcado[pos]=true;

            Aristarecorrer=origen->aristas->getFirst();
            while(Aristarecorrer !=nullptr)
            {
                guardar = new Information(Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->peso);
                aristasComparar->guardar(guardar);
                Aristarecorrer = Aristarecorrer->siguiente;
            }
            guardar = new Information(electo->valor->nombreInicio,electo->valor->nombreFin,electo->valor->peso);
            aristasFinales->guardar(guardar);
        }
    }



    for(int i=0;i<aristasFinales->getSize();i++)
    {
        guardar=aristasFinales->buscar(i);
        grafoNuevo->insertarArista(guardar->nombreInicio,guardar->nombreFin,guardar->peso);
        grafoNuevo->insertarArista(guardar->nombreFin,guardar->nombreInicio,guardar->peso);
    }

    imprimir=grafoNuevo;
    this->grafoActual="Prim";
    update();
}


void DragWidget::grafoKruskal()
{

    if(this->grafoPrincipal->listaVertices->getSize()==0)
    {
        cout<<("El Grafo esta vacio")<<endl;
        return;
    }
    Nodo<Vertice*>* Verticerecorrer = this->grafoPrincipal->listaVertices->getFirst();
    string origenV =(Verticerecorrer->valor->nombre);
    Vertice* origen = this->grafoPrincipal->getvertice(origenV);
    this->kruskal = new Grafo();
    Grafo* grafoNuevo = new Grafo();
    Vertice* temporal, *temporal2;
    while(Verticerecorrer!=nullptr)
    {
        temporal = new Vertice();
        temporal2 = new Vertice();
        temporal->nombre=Verticerecorrer->valor->nombre;
        temporal->dibujado=Verticerecorrer->valor->dibujado;
        temporal2->nombre=Verticerecorrer->valor->nombre;
        temporal2->dibujado=Verticerecorrer->valor->dibujado;
        kruskal->listaVertices->guardar(temporal);
        grafoNuevo->listaVertices->guardar(temporal2);
        Verticerecorrer = Verticerecorrer->siguiente;
    }

    Verticerecorrer = this->grafoPrincipal->listaVertices->getFirst();
    Nodo<Arista*>* Aristarecorrer;
    while(Verticerecorrer!=nullptr)
    {
        Aristarecorrer=Verticerecorrer->valor->aristas->getFirst();
        while(Aristarecorrer!=nullptr)
        {
            kruskal->insertarArista(Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->peso);
            kruskal->insertarArista(Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->peso);
            Aristarecorrer = Aristarecorrer->siguiente;
        }
        Verticerecorrer = Verticerecorrer->siguiente;
    }

    ArrayListP<Information*>* aristasComparar = new ArrayListP<Information*>();
    ArrayListP<Information*>* conjuntoSolucion = new ArrayListP<Information*>();
    Information* guardar;

    Verticerecorrer=kruskal->listaVertices->buscar(origen);

    while(Verticerecorrer!=nullptr)
    {
        Aristarecorrer = Verticerecorrer->valor->aristas->getFirst();
        while(Aristarecorrer!=nullptr)
        {
            guardar = new Information(Aristarecorrer->valor->verticeInicial->nombre,Aristarecorrer->valor->verticeFinal->nombre,Aristarecorrer->valor->peso);
            aristasComparar->guardar(guardar);
            Aristarecorrer = Aristarecorrer->siguiente;
        }
        Verticerecorrer=Verticerecorrer->siguiente;
    }

    int grupo[kruskal->listaVertices->getSize()];
    for(int i=0; i<kruskal->listaVertices->getSize();i++)
    {
        grupo[i]=i;
    }

    Nodo<Information*>*c1,*c2,*sus;

    for(int i=0;i<aristasComparar->getSize();i++)
    {
        for(int j=0;j<aristasComparar->getSize();j++)
        {
            c1=aristasComparar->obtener(i);
            c2=aristasComparar->obtener(j);

            if(c2->valor->peso < c1->valor->peso)
            {
                aristasComparar->change(i,j);
            }
        }
    }

    int pos1=0,pos2=0;
    Vertice* obtenido = new Vertice();
    for(int contara=aristasComparar->getSize()-1;contara!=-1;contara--)
    {
        c1=aristasComparar->obtener(contara);
        obtenido->nombre=c1->valor->nombreFin;
        string obs=obtenido->nombre;
        pos1=kruskal->listaVertices->getPos(obtenido);
        obtenido->nombre=c1->valor->nombreInicio;
        string ob=obtenido->nombre;
        pos2=kruskal->listaVertices->getPos(obtenido);
        if(grupo[pos1]!=grupo[pos2])
        {
            guardar = new Information(c1->valor->nombreInicio,c1->valor->nombreFin,c1->valor->peso);
            conjuntoSolucion->guardar(guardar);
            int comparar=grupo[pos1];
            int sustituir=grupo[pos2];
            for(int i=0;i<kruskal->listaVertices->getSize();i++)
            {
                int grupoI=grupo[i];
                if(grupo[i]==comparar)
                {
                    grupo[i]=sustituir;
                }
            }
        }
    }

    for(int i=0;i<conjuntoSolucion->getSize();i++)
    {
        sus=conjuntoSolucion->obtener(i);
        grafoNuevo->insertarArista(sus->valor->nombreInicio,sus->valor->nombreFin,sus->valor->peso);
        grafoNuevo->insertarArista(sus->valor->nombreFin,sus->valor->nombreInicio,sus->valor->peso);
    }
    this->imprimir=grafoNuevo;
    this->grafoActual="Kruskal";
    update();
}

void DragWidget::update() {
    this->imprimir->listarAdyacentes();
}
