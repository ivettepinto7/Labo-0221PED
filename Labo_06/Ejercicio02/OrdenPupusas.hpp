#include <iostream>
using namespace std;

//Registro para los campos de una orden
struct Orden{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;
};

//Funcion que devuelve una orden que se ingresa desde teclado
Orden solicitarOrden(){
    Orden o;
    cout << "Cantidad de revueltas: ";
    cin >> o.revueltas;
    while (o.revueltas < 0){//Si el numero ingresado es negativo
        cout << "Cantidad de revueltas: ";
        cin >> o.revueltas;
    }
    
    cout << "Cantidad de frijol con queso: ";
    cin >> o.frijolConQueso;
    while (o.frijolConQueso < 0){//Si la cantidad ingresada es negativa
        cout << "Cantidad de frijol con queso: ";
        cin >> o.frijolConQueso;
    }
    
    cout << "Cantidad de queso: ";
    cin >> o.queso;
    while (o.queso < 0){//Si la cantidad ingresada es negativa
         cout << "Cantidad de queso: ";
        cin >> o.queso;
    }
    
    cout << "1. Arroz \t0. Maiz ";//1 es true y 0 es false
    cin >> o.arroz;
    return o;
}

//Funcion que muestra una orden
void mostrarOrden(Orden o){
    cout << "Revueltas: " << o.revueltas << endl;
    cout << "Frijol con queso: " << o.frijolConQueso << endl;
    cout << "Queso: " << o.queso << endl;
    if (o.arroz){
        cout << "La orden es de arroz" << endl;
    }
    else{
        cout << "La orden es de maiz" << endl;
    }
    cout << endl;
}

struct nodo{
    Orden dato;//Parte de informacion del nodo que hace referenccia al registro Orden
    nodo *ant;//Puntero al anterior
    nodo *sig;//Puntero al siguiente
};

class ListaOrden{
    private:
        nodo *pInicio;
        nodo *pFinal;

    public:
        ListaOrden();//Constructor de clase
        void agregarOrden(Orden o);//Agrega ordenes a la lista dependiendo de la opcion inserta al inicio o al final
        void insInicio(Orden o);//Inserta al inicio de la lista
        void insFinal(Orden o);//Inserta al final de la lista
        void mostrarListaOrdenes();//Imprime la lista de forma normal
        void mostrarListaOrdenesInverso();//Imprime la lista de forma inversa
};

ListaOrden::ListaOrden(){
    pInicio = NULL;
    pFinal = NULL;
}

void ListaOrden::agregarOrden(Orden o){
    bool continuar = true;
    int opc = 0;

    do{
        cout << "\t1) Al principio" << endl;
        cout << "\t2) Al final \tOpcion: ";
        cin >> opc;
        switch (opc){
        case 1:
            insInicio(o);
            continuar = false;
            break;
        case 2:
            insFinal(o);
            continuar = false;
            break;
        default:
            cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar);
}

void ListaOrden::insInicio(Orden o){
    nodo *nuevo = new nodo;
    nuevo->dato = o;
    nuevo->sig = pInicio;
    if(pInicio)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}

void ListaOrden::insFinal(Orden o){
    nodo *nuevo = new nodo;
    nuevo->dato = o;
    if (!pInicio){
        pInicio = nuevo;
        pInicio->ant = pInicio->sig = NULL;
    }
    else{
        nodo *q = pInicio;
        while (q->sig)
            q = q->sig;
        q->sig = nuevo;
        nuevo->ant = q;
        nuevo->sig = NULL;
    }
}

void ListaOrden::mostrarListaOrdenes(){
    nodo *p = pInicio;
    cout << "\t\tMostrando lista normal" << endl;
    while (p != NULL){
        mostrarOrden(p->dato);
        p = p->sig;
    }
}

void ListaOrden::mostrarListaOrdenesInverso(){
    nodo *p = pInicio;
    nodo *q = NULL;
    if(!pInicio)
        return;
    while(p){
        q = p;
        p = p->sig;
    }
    cout << "\t\tMostrando lista en inverso" << endl;
    while(q){
        mostrarOrden(q->dato);//cout << q->dato << endl;
        q = q->ant;
    }
}
