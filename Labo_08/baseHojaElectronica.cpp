#include <stdlib.h>
#include <iostream>

using namespace std;

template <class T>
struct nodo
{
    T dato; // PERO NUESTRA HOJA LA VAMOS A MANEJAR SOLO CON DATOS ENTEROS.
    int nFil, nCol;
    nodo<T> *sigCol, *sigFil;
    nodo()
    {
        sigCol = NULL;
        sigFil = NULL;
    }
    nodo(T dato)
    {
        this->dato = dato;
        sigCol = NULL;
        sigFil = NULL;
    }
};

template <class T>
class HojaCalc
{
private:
    int totFil;   // Total de filas de la hoja electrónica.
    int totCol;   // Total de columnas de la hoja electrónica.
    nodo<T> *pHE; // Puntero base de la hoja electrónica.

public:
    HojaCalc(int, int, T); // Constructor que arma la estructura básica (la escuadra).
    //void insNodo(int, int);
    void insNodo(void);
    void borraNodo(int, int);
    void imprimirHojaElec(void);
};
template <class T>
// Este constructor inicializa la estructura base de una hoja de cálculo.
HojaCalc<T>::HojaCalc(int totFil, int totCol, T init)
{
    nodo<T> *nuevo, *s;
    int i;

    // Creación e inicialización del nodo base:
    pHE = new nodo<T>;

    this->totFil = totFil; //total de filas
    this->totCol = totCol; //total de columnas
    pHE->nFil = 0;         // fila 0
    pHE->nCol = 0;         //columna 0
    pHE->sigCol = pHE;     //lista circular, su siguiente apunta al primer nodo al ser lista de un solo nodo
    pHE->sigFil = pHE;
    pHE->dato = init;

    // Creacion de la fila base (nodos base de columnas):
    s = pHE;
    for (i = 1; i <= totCol; i++)
    { //moviendonos a la derecha, como una lista normal, estas serian Columnas A, B, C
        nuevo = new nodo<T>;
        s->sigCol = nuevo;
        nuevo->dato = init; //basicamente no guardamos datos en estas dos listas iniciales, solo so estructurales
        nuevo->nCol = i;    //el numero de columna que estamos creando, A B C
        nuevo->nFil = 0;
        nuevo->sigFil = nuevo; //puntero horizontal hacia si mismo, indicando que es circular apunta a si mismo
        s = s->sigCol;         //me muevo a la derecha
    };
    nuevo->sigCol = pHE; //puntero horizontal del siguiente del ultimo creado apunta hacia el primero

    // Creacion de la columna base (nodos base de filas):
    s = pHE;
    for (i = 1; i <= totFil; i++)
    { //moviendonos hacia abajo, serian filas 1, 2, 3
        nuevo = new nodo<T>;
        s->sigFil = nuevo; //puntero vertical del s apunta hacia el nuevo
        nuevo->dato = init;
        nuevo->nFil = i; //llenado del nuevo, indicandole su numero de fila
        nuevo->nCol = 0;
        nuevo->sigCol = nuevo;
        s = s->sigFil;
    }
    nuevo->sigFil = pHE;
}

// Insertar un nodo en la hoja de cálculo:
//void HojaCalc::insNodo(int fil, int col)
template <class T>
void HojaCalc<T>::insNodo(void)
{
    int fila, columna;

    cout << "Inserción de nodos en la hoja electrónica." << endl;
    cout << "Finalice introduciendo ceros:" << endl
         << endl;
    do
    {
        cout << "Columna: ";
        cin >> columna;
        cout << "Fila: ";
        cin >> fila;
        //if(fil >= 1 && fil <= totFil && col >= 1 && col <= totCol){
        if (fila >= 1 && fila <= totFil && columna >= 1 && columna <= totCol)
        {
            // Creación de un nuevo nodo:
            nodo<T> *nuevo = new nodo<T>();

            cout << "Entero a almacenar: ";
            cin >> nuevo->dato;
            nuevo->nFil = fila;
            nuevo->nCol = columna;

            nodo<T> *pFil = pHE;
            nodo<T> *pCol = pHE;
            int i;

            // Localización de la posición sobre la fila. El putero que salta sobre la fila
            // queda apuntando al nodo anterior.
            for (i = 1; i <= fila; i++)                                         // Bajando sobe la columna base.
                pFil = pFil->sigFil;                                            //nos movemos hasta la fila
            while ((pFil->sigCol->nCol < columna) && (pFil->sigCol->nCol != 0)) // Avanzando sobre la fila.
                pFil = pFil->sigCol;                                            //nos quedamos en el nodo previo existente (referente a columna)

            // Localización de la posición sobre la column. El putero que salta sobre la columna
            // queda apuntando al nodo anterior.
            for (i = 1; i <= columna; i++) // Avanzando sobre la fila base.
                pCol = pCol->sigCol;
            while ((pCol->sigFil->nFil < fila) && (pCol->sigFil->nFil != 0)) // Bajando sobre la columna.
                pCol = pCol->sigFil;

            // Enlazar el nuevo nodo a la estructura.
            // FALTA VERIFICAR SI EL NODO YA EXISTE.
            // SI ESTE FUERA EL CASO, SOLO HABRÍA QUE SUSTITUIR EL VALOR.
            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            cout << "El nodo se ha insertado" << endl
                 << endl;
        }
        else
            cout << "Hubicación no válida para nuevo dato" << endl
                 << endl;
    } while (fila != 0 || columna != 0);
}

// Eliminar un nodo de la hoja de cálculo. Se asume que el
// nodo sí existe, la función solo hace el trabajo de borrarlo.
template <class T>
void HojaCalc<T>::borraNodo(int fil, int col)
{
    nodo<T> *pFil = pHE;
    nodo<T> *pCol = pHE;
    nodo<T> *pBorrar = NULL; // Puntero que apuntara al nodo a a eliminar.
    int i;

    // Localización de la posición sobre la fila. El putero que salta sobre la fila
    // queda apuntando al nodo anterior.
    for (i = 1; i <= fil; i++) // Bajando sobre columna base.
        pFil = pFil->sigFil;
    while ((pFil->sigCol->nCol < col) && (pFil->sigCol->nCol != 0)) // Avanzando sobre fila.
        pFil = pFil->sigCol;
    ///////bajar hasta fila correcta, con un nodo existente en una columna previa

    // Localización de la posición sobre la columna. El putero que salta sobre la columna
    // queda apuntando al nodo anterior.
    for (i = 1; i <= col; i++) // Avanzando sobre fila base.
        pCol = pCol->sigCol;
    while ((pCol->sigFil->nFil < fil) && (pCol->sigFil->nFil != 0)) // Bajando sobre columna.
        pCol = pCol->sigFil;

    /////mover a la derecha hasta la columna correcta y luego hacia abajo a un nodo existente en alguna fila previa

    // Desenlazar el nodo de la estructura y borrarlo.
    pBorrar = pFil->sigCol;                             // FALTA VERIFICAR SI EL NODO EN REALIDAD EXISTE.
    if (pBorrar->nCol == col)
    {
        pFil->sigCol = pFil->sigCol->sigCol;        //al nodo en la fila correcta pero columna previa, decimos que su siguiente seria el siguiente del siguiente
        pCol->sigFil = pCol->sigFil->sigFil;        // al nodo en la columna correcta pero fila previa, le decimos que su siguiente va a ser el sigueinte del siguiente
        delete pBorrar;

        cout << "El nodo ha sido borrado" << endl
             << endl;
    }else{
        cout<<"El nodo no existe"<<endl;
    } //solo fila porque columna ya esta correcta

    // Eliminar el nodo desenlazado.
}

// Impresión para verificar ewl estado de
// la mariz. Se imprime por filas:
template <class T>
void HojaCalc<T>::imprimirHojaElec(void)
{
    cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    nodo<T> *s = pHE;
    int i;

    do
    {
        do
        {
            cout << '(' << s->nCol << ',' << s->nFil << ")-> " << s->dato << '\t';
            s = s->sigCol;
        } while (s->nCol != 0);
        cout << endl;
        s = s->sigFil;
    } while (s->nFil != 0);
}

int main(void)
{
    //nodo<int> *s;
    int totFilas, totColumnas, fil, col, i;

    cout << endl;
    cout << "FUNCIONES IMPLEMENTADAS PARA ADMINISTRAR UNA HOJA DE CÁLCULO" << endl
         << endl;

    // Inicialización de la estructura base de una hoja de cálculo.
    cout << "Para inicializar la hoja de cálculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendrá:" << endl
         << endl;
    cout << "Total de filas: ";
    cin >> totFilas;
    cout << "Total de columnas: ";
    cin >> totColumnas;

    HojaCalc<int> hojaCalculo(totFilas, totColumnas, 0);

    // Impresión para verificar la estructura base
    // de la hoja electrónica:
    hojaCalculo.imprimirHojaElec();

    // Inserción de un nodo en la hoja de cálculo:
    hojaCalculo.insNodo();

    // Impresión para verificar la inserción de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();

    // Eliminación de un nodo de la hoja de cálculo.
    cout << "Eliminación de un nodo de la hoja de cálculo:" << endl
         << endl;
    cout << "Digite el número de fila y el número de columna" << endl;
    cout << "del nodo que será eliminado:" << endl;
    cout << "Columna: ";
    cin >> col;
    cout << "Fila: ";
    cin >> fil;

    hojaCalculo.borraNodo(fil, col);

    // Impresión para verificar la eliminación de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();

    cout << endl
         << endl;
    return 0;
}