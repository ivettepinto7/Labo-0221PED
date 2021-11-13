#include <iostream>
using namespace std;

struct nodo
{
    int data;
    nodo *left;
    nodo *right;

    nodo()
    {
        left = right = NULL;
    }

    nodo(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class ABB
{
private:
    nodo *pABB;

public:
    ABB();
    void insertar(int d);
    nodo *insertar(nodo *t, int d);

    void inOrder();
    void inOrder(nodo *);

    nodo *min();
    nodo *min(nodo *t);

    nodo *max();
    nodo *max(nodo *t);
};

ABB::ABB()
{
    pABB = NULL;
};

void ABB::insertar(int d)
{
    nodo *t = pABB;//Nodo que apunta hacia la raiz
    if (!t)//Si no hay nada en la raiz, creo un nuevo nodo y lo coloco en ella
        pABB = new nodo(d);
    else
    {//Si ya hay algo en la raiz hago llamada hacia la sobrecarga para verificar si lo inserto a la izquierda o derecha
        insertar(t, d);
    }
}

nodo *ABB::insertar(nodo *t, int d)
{
    if (!t)//Si no hay nada en la raiz, creo un nuevo nodo y lo coloco en ella
        t = new nodo(d);
    else
    {
        if (d <= t->data)//Si el dato es menor o igual al nodo actual, lo coloco a su izquierda
            t->left = insertar(t->left, d);
        else//Sino, si el dato es mayor al nodo actual, lo coloco a su derecha
            t->right = insertar(t->right, d);
    }
    return t;
}

void ABB::inOrder()
{
    nodo *t = pABB;
    if (t != NULL)
    { //Is not empty
        inOrder(t);
    }
}

void ABB::inOrder(nodo *t)
{
    if (t != NULL)
    {                           //Is not empty
        inOrder(t->left);       //Left
        cout << t->data << " "; //Root
        inOrder(t->right);
    }
}

nodo *ABB::min()
{
    nodo *t = pABB;//Nodo que apunta hacia la raiz del arbol
    return min(t);
}

nodo *ABB::min(nodo *t)
{/*Esta funcion es de forma iterativa, como yo se que en un ABB el menor se encuentra en el nodo
    de hasta más a la izquierda y que su hijo izquierdo es nulo, lo recorro y guardo en t dicho nodo*/
    while (t->left != NULL)
        t = t->left;
    return t;
}

nodo *ABB::max()
{
    nodo *t = pABB;//Nodo que apunta a la raiz del arbol
    return max(t);
}

nodo *ABB::max(nodo *t)
{   /*Esta funcion es de forma recursiva. Similar al minimo, para el maximo, este va a estar hasta lo mas
    derecha del arbol y que su hijo derecho sea nulo*/
    if (!t->right)//Caso base: Si el hijo derecho es nulo, ahi se encuentra mi maximo
        return t;
    else
    {//Caso recursivo: Recorro el arbol derecho
        return max(t->right);
    }
}

int main()
{
    ABB objTree;
    nodo* min = NULL;
    nodo* max = NULL;
    int n = 0, option = 0;
    bool cont = true;

    do{
        cout << "\t\tMENU:" << endl;
        cout << "\t1) Agregar" << endl;
        cout << "\t2) Imprimir arbol" << endl;
        cout << "\t3) Minimo y maximo " << endl;
        cout << "\t4) Salir \tYour option: ";
        cin >> option;
        switch(option){
            case 1:
                cout << "Number: ";
                cin >> n;
                objTree.insertar(n);
            break;
            case 2: 
                cout << "InOrder: "; objTree.inOrder(); cout << endl;
            break;
            case 3:
                cout << "Minimo: ";
                min = objTree.min();
                cout << min->data << endl;
                cout << "Maximo: ";
                max = objTree.max();
                cout << max->data << endl;
            break;
            case 4:
                cont = false;
            break;
            default: 
                cout << "Invalid option!" << endl;
            break;
        }
    }while(cont);

    return 0;
}