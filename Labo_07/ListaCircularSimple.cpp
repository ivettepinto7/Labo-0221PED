#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *sig;
};

class ListaCircSimple{
    private:
        nodo *pInicio;

    public:
        ListaCircSimple();
        void insertar(int numero);
        void imprimir();

        void eliminar(int buscar);
        void eliminar(int buscar, nodo *p);

        //Actualiza todas las ocurrencias en la lista
        void actualizar(int buscar, int nuevo);
};

ListaCircSimple::ListaCircSimple(){
    pInicio = NULL;
}

void ListaCircSimple::insertar(int numero){
     nodo *nuevo, *aux;

    nuevo = new nodo;
    nuevo->dato = numero;

    if (!pInicio){
        pInicio = nuevo;
        /*Por ser una lista circular, el siguiente ya no apunta
        a NULL sino que, apunta al primero*/
        pInicio->sig = pInicio;
    }
    else{
        nuevo->sig = pInicio;
        aux = pInicio;
        while (aux->sig != pInicio){
            aux = aux->sig;
        }
        aux->sig = nuevo;
    }
}

void ListaCircSimple::imprimir(){
    nodo* p;
    if(pInicio){
        /*Solo si hay elementos en la lista p = pInicio*/
        p = pInicio;
        do{
            cout << p->dato << endl;
            p = p->sig;
        }while(p != pInicio);
    }
}

void ListaCircSimple::eliminar(int buscar){
    nodo *p = pInicio;
    if (p == NULL){//Si la lista está vacia
        cout << "No hay elementos en esta lista" << endl;
        return;
    }else if (p->sig == pInicio){//Si el siguiente de p es pInicio, quiere decir que ya llegue al final de mi lista
            if (p->dato == buscar){//Si el dato a eliminar es el primero de la lista
            pInicio = NULL;//pInicio será NULL UNICAMENTE porque la lista solo tiene 1 elemento, y es el que quiero borrar
            delete p;
        }
        else{
            cout << "No hay " << buscar << " en esta lista" << endl;
        }
        return;
    }else{
        eliminar(buscar,p);
    }
}

void ListaCircSimple::eliminar(int buscar, nodo *p){
    //Si la lista tiene más de un elemento y, quiero borrar el primero de ella
    if(p == pInicio && p->dato == buscar){
        nodo *aux = p;
        while(aux->sig != pInicio){
            aux = aux->sig;
        }
        pInicio = p->sig;
        aux->sig = pInicio;
        delete p;
        return;
    }//Si quiero borrar un elemento de en medio de la lista
    else if (p->sig->dato == buscar){
        p->sig = p->sig->sig;
        return;
    }
    eliminar(buscar, p->sig);
}

void ListaCircSimple::actualizar(int buscar, int nuevo){
    nodo* p;
    if(pInicio){
        p = pInicio;
        do{
            if(p->dato == buscar)
                p->dato = nuevo;
            p = p->sig;
            /*Pongo nuevamente el if de arriba, porque por la condicion del while, no tomará en cuenta el
            último nodo
            Por ejemplo si tengo 1,2,3,4 el siguiente de 4 es 1
            Cuando llegue a 3 y hago p = p->sig si irá al 4 y por eso vuelvo a poner el if*/
             if(p->dato == buscar)
                p->dato = nuevo;
        }while(p->sig != pInicio);
    }
}

int main(){
    ListaCircSimple listaNumeros;
    bool continuar = true;
    int n = 0, op = 0, num = 0, act = 0, nuevo = 0;

    do{
        cout << "MENU" << endl;
        cout << "\t1) Agregar número" << endl;
        cout << "\t2) Imprimir lista" << endl;
        cout << "\t3) Actualizar" << endl;
        cout << "\t4) Eliminar número" << endl;
        cout << "\t5) Salir \tSu opcion: ";
        cin >> op;
        switch (op){
        case 1:
            cout << "Número: ";
            cin >> n;
            listaNumeros.insertar(n);
            break;
        case 2:
            listaNumeros.imprimir();
            break;
        case 3:
            cout << "Numero a actualizar: ";
            cin >> act;
            cout << "Actualizar por: ";
            cin >> nuevo;
            listaNumeros.actualizar(act, nuevo);
            break;
        case 4:
            cout << "Numero a eliminar: ";
            cin >> num;
            listaNumeros.eliminar(num);
            break;
        case 5:
            continuar = false;
            break;
        default:
            cout << "Opción invalida!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}