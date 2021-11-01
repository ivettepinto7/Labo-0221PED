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

    void imprimirInversa();
    void imprimirInversa(nodo *p);

    void eliminar(int numero);
    void eliminar(int numero, nodo *p);

    void actualizar(int buscar, int nuevo);
    void actualizar(int buscar, int nuevo, nodo *p);
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
        nuevo->der = pInicio;
        nuevo->izq = pInicio;
    }
    else
    {
        while (p->der != pInicio)
            p = p->der;
        p->der = nuevo;

        nuevo->izq = p;
        nuevo->der = pInicio;
        pFinal = nuevo;

        pInicio->izq = pFinal;
    }
}
void numeros::imprimir()
{
    nodo *p = pInicio;

    cout << "El nodo anterior del inicial es: " << p->izq->dato << endl;
    cout << "El nodo siguiente del final es: " << pFinal->der->dato << endl;

    imprimir(p);
}
void numeros::imprimir(nodo *p)
{
    //caso base
    if (p == pFinal)
    {
        cout << p->dato << endl;
        return;
    }
    else
    { //caso recursivo
        cout << p->dato << endl;
        //llamada recursiva
        imprimir(p->der);
    }
}

void numeros::imprimirInversa()
{
    nodo *p = pFinal;
    imprimirInversa(p);
}
void numeros::imprimirInversa(nodo *p)
{
    //caso base
    if (p == pInicio)
    {
        cout << p->dato << endl;
        return;
    }
    else
    {
        cout << p->dato << endl;
        imprimirInversa(p->izq);
    }
    //caso recursivo
}

void numeros::eliminar(int buscar)
{
    nodo *p = pInicio;
    if (p == pFinal && p)
    {
        if (p->dato == buscar)
        {
            pInicio = NULL;
            pFinal = NULL;
            delete p;
        }
        else
        {
            cout << "No hay " << buscar << " en esta lista" << endl;
        }
        return;
    }
    else if (!p)
    {
        cout << "No hay elementos en esta lista " << endl;
        return;
    }
    else
    {
        eliminar(buscar, p);
    }
}
void numeros::eliminar(int buscar, nodo *p)
{
    if (p == pFinal)
    { //1,2,3
        if (p->dato == buscar)
        {
            //cout<<p->izq->dato<<endl;
            p->izq->der = p->der->der;
            pFinal = p->izq;
            pInicio->izq = pFinal;
            delete p;
        }
        else
        {
            cout << "No hay " << buscar << " en esta lista" << endl;
        }
        return;
    }
    else
    {
        nodo *q = p->der;
        if (p->dato == buscar)
        { //1,2,3
            p->izq->der = p->der;
            p->der->izq = p->izq;
            if (p == pInicio)
                pInicio = p->der;
            delete p;
        }
        eliminar(buscar, q);
    }
}
void numeros::actualizar(int buscar, int nuevo)
{
    nodo *p = pInicio;
    actualizar(buscar, nuevo, p);
}
void numeros::actualizar(int buscar, int nuevo, nodo *p)
{
    //caso base
    if (p == pFinal)
    {
        if (p->dato == buscar)
        {
            p->dato = nuevo;
        }
        return;
    }
    else
    {
        if (p->dato == buscar)
        {
            p->dato = nuevo;
            return;
        }
        actualizar(buscar, nuevo, p->der);
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
    cout << "Imprimiendo inversa: " << endl;
    listaNumeros.imprimirInversa();

    listaNumeros.eliminar(5);
    cout << "Imprimiendo inversa: " << endl;
    listaNumeros.imprimirInversa();

    listaNumeros.actualizar(4, 44);
    cout << "Imprimiendo inversa: " << endl;
    listaNumeros.imprimirInversa();

    return 0;
}