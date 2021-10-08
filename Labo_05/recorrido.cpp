#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *izq;
    nodo *der;
};

class numeros
{
private:
    nodo *pInicio;
    nodo *pFinal;

public:
    numeros();
    void insertar(int numero);
    void imprimir();
    void imprimir(nodo *p);

    void imprimirInverso();
    void imprimirInverso(nodo *p);
};

numeros::numeros()
{
    pInicio = NULL;
    pFinal = NULL;
}

void numeros::insertar(int numero)
{
    nodo *p = pInicio;
    nodo *nuevo = new nodo;
    nuevo->dato = numero;
    nuevo->der = NULL;
    nuevo->izq = NULL;
    if (!pInicio)
    {
        pInicio = nuevo;
        pFinal = nuevo;
    }
    else
    {
        while (p->der != NULL)
        { //1,2,3,4
            p = p->der;
        }
        p->der = nuevo;
        nuevo->izq = p;
        pFinal = nuevo;
    }
}

void numeros::imprimir()
{
    //
    nodo *p = pInicio;
    //
    cout << "Imprimiendo lista de forma normal" << endl;
    imprimir(p);
}

void numeros::imprimir(nodo *p)
{
    //caso base
    if (!p)
        return;
    //caso recursivo
    else
    {
        cout << p->dato << endl;
        //llamada recursiva
        imprimir(p->der);
    }
}

void numeros::imprimirInverso(){
    nodo *p=pFinal;
    cout<<"Imprimiendo lista de forma inversa"<<endl;
    imprimirInverso(p);
}

void numeros::imprimirInverso(nodo *p){
    //caso base
    if(!p)
    return;
    else{
        cout<<p->dato<<endl;
        //llamada recursiva
        imprimirInverso(p->izq);//1 2 3 4 5
    }
    //caso recursivo
}


int main()
{
    numeros listaNumeros;
    for (int i = 1; i < 6; i++)
    {
        listaNumeros.insertar(i);
    }
    listaNumeros.imprimir();
    cout<<endl;

    listaNumeros.imprimirInverso();

    return 0;
}