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

    void eliminacionDespuesDe(int buscar); // 1 2 3 4 5
    void eliminacionDespuesDe(int buscar, nodo *p);
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

void numeros::imprimirInverso()
{
    nodo *p = pFinal;
    cout << "Imprimiendo lista de forma inversa" << endl;
    imprimirInverso(p);
}

void numeros::imprimirInverso(nodo *p)
{
    //caso base
    if (!p)
        return;
    else
    {
        cout << p->dato << endl;
        //llamada recursiva
        imprimirInverso(p->izq); //1 2 3 4 5
    }
    //caso recursivo
}

void numeros::eliminacionDespuesDe(int buscar)
{
    nodo *p = pInicio;
    if (p == pFinal)
    {
        cout << "No hay elementos en una lista unica" << endl;
        return;
    }
    else
        eliminacionDespuesDe(buscar, p);
}

void numeros::eliminacionDespuesDe(int buscar, nodo *p)
{
    /**por el caso que vimos al final de 1 2 3 4 5 5 6
    al final se trataba de comparar un NULL con pFinal y esto provoca segmentation core
    es por esto que agregamos un caso extra, donde se verifica que
    el nodo que estamos recibiendo sea distinto de null**/
    if (!p)
        return;
    //en este caso verificamos que tampoco estemos en el nodo final, 
    //porque no se puede eliminar después de un nulo
    else if (p == pFinal)
    {
        return; // 1 2 3 4 5 5 6
    }
    else
    {
        /**
         * hacemos verificacion de que el nodo en el que estamos sea igual
         * al parametro recibido. Además verificamos que el siguiente (el que se quiere eliminar)
         * sea distinto al parametro de busqueda, porque queremos eliminar despues del parametro
         * pero no todas las instancias de ese numero.
         * **/
        if (p->dato == buscar && p->der->dato != buscar)
        {
            cout << "Eliminando " << p->der->dato << endl;
            nodo *aux = p->der;
            // 1 5 2 3 4 5 5 NULL
            //verificamos que el de la siguiente del siguiente sea distinto de nulo
            //en el caso 1 5 2 3 4 5 5 6, sería el primer 5.
            if (p->der->der != NULL)
            {
                //referencia a la derecha
                p->der = p->der->der; // también aux->der
                //referencia a la izquierda
                (p->der)->izq = p;
                pFinal=p;
            }
            else
            {
                //en la lista 1 5 2 3 4 5 5 6
                //seria el penultimo número, o sea el último 5.
                p->der = NULL;
                pFinal=p;
            }
            //se elimina el nodo 
            delete (aux);
        }
        //llamada recursiva
        eliminacionDespuesDe(buscar, p->der);
    }
}

int main()
{
    numeros listaNumeros;
    for (int i = 1; i < 6; i++)
    {
        listaNumeros.insertar(i);
    }
    listaNumeros.insertar(5);
    listaNumeros.insertar(6);
    listaNumeros.imprimir();
    cout << endl;

    listaNumeros.imprimirInverso();

    listaNumeros.eliminacionDespuesDe(5);

    listaNumeros.imprimir();
    listaNumeros.imprimirInverso();
    return 0;
}