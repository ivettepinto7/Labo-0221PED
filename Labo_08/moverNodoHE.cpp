#include <iostream>
//#include <stdlib.h>
using namespace std;

struct nodo{
    int nFil, nCol;
    nodo *sigCol, *sigFil;
    int dato;
};

class HojaCalc{
    private:
        int totFil; // Total de filas de la hoja electrónica.
        int totCol; // Total de columnas de la hoja electrónica.
        nodo *pBase; // Puntero base de la hoja electrónica.

    public:
        HojaCalc(int totCol, int totFil); // Constructor que arma la estructura básica (la escuadra).
        //void insNodo(int, int);
        void insNodo();
        void imprimirHojaElec(void);
        void moverNodo(int cActual, int fActual, int nCol, int nFila);
};

HojaCalc::HojaCalc(int totCol, int totFil){
    nodo *nuevo, *s;
    int i;

    // Creación e inicialización del nodo base:
    pBase = new nodo;

    this->totCol = totCol;
    this->totFil = totFil;
    pBase->nFil = 0;
    pBase->nCol = 0;
    pBase->sigCol = pBase;
    pBase->sigFil = pBase;
    pBase->dato = 0;

    // Creacion de la columna base (nodos base de filas):
    s = pBase;
    for(i = 1; i <= totFil; i++){
        nuevo = new nodo;
        s->sigFil = nuevo;
        nuevo->dato = 0;
        nuevo->nFil = i;
        nuevo->nCol = 0;
        nuevo->sigCol = nuevo;
        s = s->sigFil;
    }
    nuevo->sigFil = pBase;
    
    // Creacion de la fila base (nodos base de columnas):
    s = pBase;
    for(i = 1; i <= totCol; i++){
        nuevo = new nodo;
        s->sigCol = nuevo;
        nuevo->dato = 0;
        nuevo->nCol = i;
        nuevo->nFil = 0;
        nuevo->sigFil = nuevo;
        s = s->sigCol;
    };
    nuevo->sigCol = pBase;
}

void HojaCalc::insNodo(){
    int fila, columna;

    cout << "Inserción de nodos en la hoja electrónica." << endl;
    cout << "Finalice introduciendo ceros:" << endl << endl;
    do{
        cout << "Columna: ";
        cin >> columna;
        cout << "Fila: ";
        cin >> fila;
        if(fila >= 1 && fila <= totFil && columna >= 1 && columna <= totCol){
            // Creación de un nuevo nodo:
            nodo *nuevo = new nodo;

            cout << "Entero a almacenar: ";
            cin >> nuevo->dato;
            nuevo->nFil = fila;
            nuevo->nCol = columna;
            
            nodo *pFil = pBase;
            nodo *pCol = pBase;
            int i;
            
            // Localización de la posición sobre la fila. El puntero que salta sobre la fila
            // queda apuntando al nodo anterior.
            for(i = 1; i <= fila; i++) // Bajando sobre la columna base.
                pFil = pFil->sigFil;//nos movemos hasta la fila
            while((pFil->sigCol->nCol < columna) && (pFil->sigCol->nCol != 0)) // Avanzando sobre la fila.
                pFil = pFil->sigCol; //nos quedamos en el nodo previo existente (referente a columna)

            // Localización de la posición sobre la column. El puntero que salta sobre la columna
            // queda apuntando al nodo anterior.
            for(i = 1; i <= columna; i++) // Avanzando sobre la fila base.
                pCol = pCol->sigCol;
            while((pCol->sigFil->nFil < fila) && (pCol->sigFil->nFil != 0)) // Bajando sobre la columna.
                pCol = pCol->sigFil;
            
            // Enlazar el nuevo nodo a la estructura.
            // FALTA VERIFICAR SI EL NODO YA EXISTE.
            // SI ESTE FUERA EL CASO, SOLO HABRÍA QUE SUSTITUIR EL VALOR.
            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            cout << "El nodo se ha insertado" << endl << endl;
        }
        else
            cout << "Ubicación no válida para nuevo dato" << endl << endl;
    }while(fila  != 0 || columna != 0);
}

// Impresión para verificar ewl estado de
// la mariz. Se imprime por filas:
void HojaCalc::imprimirHojaElec(void){
    cout << "Para cada nodo se muestra:columna, fila, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    nodo *s = pBase;
    int i;

    do{
        do{
            cout <<'(' <<s->nCol <<',' << s->nFil << ")-> "<< s->dato << '\t';
            s = s->sigCol;
        }while(s->nCol != 0);
        cout << endl;
        s = s->sigFil;
    }while(s->nFil != 0);
}

void HojaCalc::moverNodo(int aCol, int aFila, int nCol, int nFila){
     if((aCol >= 1 && aCol <= totCol && aFila >= 1 && aFila <= totFil) &&
     (nCol >= 1 && nCol <= totCol && nFila >= 1 && nFila <= totFil)){
            nodo *pCol = pBase;
            nodo *pFil = pBase;
             nodo *pMover = NULL; //Puntero que apunta al nodo a mover
            nodo *nuevo = new nodo;
            int i;

            nuevo->nCol = nCol;
            nuevo->nFil = nFila;

            
            // Localización de la posición sobre la columna. El puntero que salta sobre la columna
            // queda apuntando al nodo anterior.
            for(i = 1; i <= aCol; i++) // Avanzando sobre fila base.
                pCol = pCol->sigCol;
            while((pCol->sigFil->nFil < aFila) && (pCol->sigFil->nFil != 0)) // Bajando sobre columna.
                pCol = pCol->sigFil;

            // Localización de la posición sobre la fila. El putero que salta sobre la fila
            // queda apuntando al nodo anterior.
            for(i = 1; i <= aFila; i++) // Bajando sobre columna base.
                pFil = pFil->sigFil;
            while((pFil->sigCol->nCol < aCol) && (pFil->sigCol->nCol != 0)) // Avanzando sobre fila.
                pFil = pFil->sigCol;
            //bajar hasta fila correcta, con un nodo existente en una columna previa
            
            //Desenlazar el nodo de la estructura y borrarlo.
            pMover = pFil->sigCol; // FALTA VERIFICAR SI EL NODO EN REALIDAD EXISTE.
            pFil->sigCol = pFil->sigCol->sigCol; //al nodo en la fila correcta pero columna previa, decimos que su siguiente seria el siguiente del siguiente
            pCol->sigFil = pCol->sigFil->sigFil;// al nodo en la columna correcta pero fila previa, le decimos que su siguiente va a ser el sigueinte del siguiente

            //Ponerlo en la nueva posicion
            pFil = pBase;
            pCol = pBase;
            for(i = 1; i <= nCol; i++) // Avanzando sobre fila base.
                pCol = pCol->sigCol;
            while((pCol->sigFil->nFil < nFila) && (pCol->sigFil->nFil != 0)) // Bajando sobre columna.
                pCol = pCol->sigFil;

            for(i = 1; i <= nFila; i++) // Bajando sobre columna base.
                pFil = pFil->sigFil;
            while((pFil->sigCol->nCol < nCol) && (pFil->sigCol->nCol != 0)) // Avanzando sobre fila.
                pFil = pFil->sigCol;

            nuevo->dato = pMover->dato;
            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            
            cout << "El nodo se ha movido" << endl << endl;
        }
        else
            cout << "Ubicación no válida" << endl << endl;
}

int main(void){
    nodo *s;
    int totFilas, totColumnas, fil, col, i, nfil, ncol;

    cout << endl;
    cout << "FUNCIONES IMPLEMENTADAS PARA ADMINISTRAR UNA HOJA DE CÁLCULO" << endl << endl;

    // Inicialización de la estructura base de una hoja de cálculo.
    cout << "Para inicializar la hoja de cálculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendrá:" << endl << endl;
    cout << "Total de columnas: ";
    cin >> totColumnas;
    cout << "Total de filas: ";
    cin >> totFilas;

    HojaCalc hojaCalculo(totColumnas, totFilas);

    // Impresión para verificar la estructura base
    // de la hoja electrónica:
    hojaCalculo.imprimirHojaElec();
    
    // Inserción de un nodo en la hoja de cálculo:
    hojaCalculo.insNodo();
    
    // Impresión para verificar la inserción de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();

    // Mover un nodo de la hoja de cálculo.
    cout << "Mover un nodo de la hoja de cálculo:" << endl << endl;
    cout << "Digite el número de columna y el número de fila" << endl;
    cout << "del nodo que desea mover:" << endl;
    cout << "Colmna: ";
    cin >> col;
    cout << "Fila: ";
    cin >> fil;

     cout << "Digite el número de columna y el número de fila de la nueva posicion" << endl;
    cout << "del nodo que será eliminado:" << endl;
    cout << "Colmna: ";
    cin >> ncol;
    cout << "Fila: ";
    cin >> nfil;

    hojaCalculo.moverNodo(col, fil, ncol, nfil);

    // Impresión para verificar la eliminación de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();

    cout << endl << endl;
    return 0;
}