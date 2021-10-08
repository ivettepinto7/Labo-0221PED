#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *izq;//Anterior
    nodo *der;//Siguiente
};

class ListaDoble{
    private:
        nodo *pInicio;
    public:
        //Constructor de la clase
        ListaDoble();
        //Lee datos desde teclado
        void insertar();
        //Inserta al final de la lista
        void insFinal(int dato);
        void mostrarLista();
        //Sobrecarga de funcion
        void mostrarLista(nodo *p);
};

ListaDoble::ListaDoble(){
    pInicio = NULL;
}

void ListaDoble::insertar(){
    int num = 0, op = 1;
    do{
        cout << "Numero: ";
        cin >> num;
        insFinal(num);
        cout << "Ingresar otro numero? 1) Si 2) No ";
        cin >> op;
    }while(op == 1);
}

void ListaDoble::insFinal(int dato){
    nodo *nuevo = new nodo;

    nuevo->dato = dato;
    if(!pInicio){//Si la lista esta vacia
        pInicio = nuevo;
        pInicio->izq = pInicio->der = NULL;
    }else{//
        nodo *q = pInicio;
        //Buscar el ultimo de la lista
        while(q->der){
            q = q->der;//1 2 3 4
        }
        q->der = nuevo;
        nuevo->izq = q;
        nuevo->der = NULL;

    }
}

void ListaDoble::mostrarLista(){
    nodo *p = pInicio;
    cout << "Mostrando lista" << endl;
    mostrarLista(p);
}

void ListaDoble::mostrarLista(nodo *p){
   if(!p){//Caso base si la lista esta vacia
       return;
   }else{
       cout << p->dato << endl;
       mostrarLista(p->der);
   }
}

int main(){
    ListaDoble objListaDoble;
    int opc = 0;

    do{
        cout << "\t\tLISTA DOBLEMENTE ENLAZADA" << endl;
        cout << "\t1) Insertar al final" << endl;
        cout << "\t2) Imprimir lista" << endl;
        cout << "\t0) Salir ";
        cout << "\tSu opcion: ";
        cin >> opc;
        switch (opc){
            case 0:
            break;
            case 1:
                objListaDoble.insertar();
            break;
            case 2:
                objListaDoble.mostrarLista();
            break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (opc != 0);

    return 0;
}