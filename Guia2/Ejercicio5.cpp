#include <iostream>
using namespace std;

struct nodo{
	int dato;
	nodo *sig;
};

class ListaNumeros{
    private:
        nodo *pInicio;

    public:
        ListaNumeros();
        void insertarEnLista(void);
        void insInicio(int);
        void mostrarListaNumeros(void);
        //Sobrecarga de funciones
        void impresionRecursiva();
        void impresionRecursiva(nodo *,int, int);
};

ListaNumeros::ListaNumeros(){
    pInicio = NULL;
};

void ListaNumeros::insertarEnLista(void){
     int dato;

    cout << "Digite un numero o Ctrl-D para terminar: ";
    while(cin >> dato){
        insInicio(dato);
        cout << "Ingrese un numero o Ctrl-D para terminar: ";
    }
}

void ListaNumeros::insInicio(int dato){
    nodo *nuevo;

    
    nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;//4 3 2 1
    pInicio = nuevo;
}

void ListaNumeros::mostrarListaNumeros(void){
    nodo *p;
    cout << "Los elementos de la lista son:" << endl;
    p = pInicio;
    while(p){
        cout << p->dato << endl;
        p = p->sig;
    }
}

void ListaNumeros::impresionRecursiva(){
    nodo *p = pInicio;
    if(!p)
        return;
    else{
        if(((p->dato)%2)==0)
			impresionRecursiva(p->sig,p->dato, 0); //Si es par sumo el dato en los pares
		else
			impresionRecursiva(p->sig,0,p->dato); //Sumo el dato en los impares
    }
}

void ListaNumeros::impresionRecursiva(nodo *p,int sumaPares, int sumaImpares){
    if(!p){
	cout <<"La suma de pares es: "<< sumaPares <<endl;
	cout <<"La suma de impares es: "<< sumaImpares <<endl;
	return;	
}
	else{
        if(((p->dato)%2)==0)
			impresionRecursiva(p->sig,sumaPares + p->dato, sumaImpares);
		else
			impresionRecursiva(p->sig,sumaPares, sumaImpares + p->dato);
	}
}

int main(void){
    ListaNumeros objListaNumeros;

    cout << "Insertar elementos en la lista" << endl;
    objListaNumeros.insertarEnLista();
    cin.clear();

    objListaNumeros.mostrarListaNumeros();

    objListaNumeros.impresionRecursiva();

    return 0;
};