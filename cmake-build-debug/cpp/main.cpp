#include <iostream>
#include "../hd/DragWidget.h"

using namespace std;
int main() {
    DragWidget* draw = new DragWidget();
    int opcion;
    bool continuar=true;
    cout<<"============================================================"<<endl;
    cout<<"======================GRAFO PROJECT========================="<<endl;
    cout<<"============================================================"<<endl;
    do{
        cout<<"=======================MAIN================================="<<endl;
        cout<<"Seleccione una opcion"<<endl;
        cout<<"1. Insertar Vertice"<<endl;
        cout<<"2. Eliminar Vertice"<<endl;
        cout<<"3. Insertar Arista"<<endl;
        cout<<"4. Eliminar Arista"<<endl;
        cout<<"5. Grafo Floyd"<<endl;
        cout<<"6. Grafo Dijkstra"<<endl;
        cout<<"7. Grafo Prim"<<endl;
        cout<<"8. Grafo Kruskal"<<endl;
        cout<<"9. Recorrido Anchura"<<endl;
        cout<<"10. Recorrido Profundidad"<<endl;
        cout<<"11. Mostrar Grafo"<<endl;
        cout<<"12. Salir"<<endl;
        cin>>opcion;

        switch (opcion)
        {
            case 1:
            {
                string name;
                cout<<"Ingrese nombre del vertice:"<<endl;
                cin>>name;
                draw->grafoPrincipal->insertarVertice(name);
                cout<<"==================================================="<<endl;
            }
                break;
            case 2:
            {
                string name;
                cout<<"Ingrese nombre del vertice:"<<endl;
                cin>>name;
                draw->grafoPrincipal->insertarVertice(name);
                cout<<"==================================================="<<endl;
            }
                break;
            case 3:
            {
                string inicial,final;
                int peso;
                cout<<"Ingrese nombre del vertice Inicial:"<<endl;
                cin>>inicial;
                cout<<"Ingrese nombre del vertice Final:"<<endl;
                cin>>final;
                cout<<"Ingrese peso de la Arista:"<<endl;
                cin>>peso;
                draw->grafoPrincipal->insertarArista(inicial,final,peso);
                cout<<"==================================================="<<endl;
            }
                break;
            case 4:
            {
                string inicial,final;
                cout<<"Ingrese nombre del vertice Inicial:"<<endl;
                cin>>inicial;
                cout<<"Ingrese nombre del vertice Final:"<<endl;
                cin>>final;
                draw->grafoPrincipal->eliminarArista(inicial,final);
                cout<<"==================================================="<<endl;
            }
                break;
            case 5:
            {
                draw->grafoToFloyd();
                cout<<"==================================================="<<endl;
            }
                break;
            case 6:
            {
                draw->grafoToDjikstra();
                cout<<"==================================================="<<endl;
            }
                break;
            case 7:
            {
                draw->grafoPrim();
                cout<<"==================================================="<<endl;
            }
                break;
            case 8:
            {
                draw->grafoKruskal();
                cout<<"==================================================="<<endl;
            }
                break;
            case 9:
            {
                draw->recorridoAnchura();
                cout<<"==================================================="<<endl;
            }
                break;
            case 10:
            {
                draw->recorridoProfundidad();
                cout<<"==================================================="<<endl;
            }
                break;
            case 11:
            {
                draw->grafoPrincipal->listarAdyacentes();
            }
                break;
            case 12:
            {
                continuar=false;
            }
                break;

        }
    }while(continuar);

    return 0;
}