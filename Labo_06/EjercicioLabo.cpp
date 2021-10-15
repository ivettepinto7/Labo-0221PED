#include <iostream>
#include <string>
using namespace std;

enum generos
{
    ciencia_ficcion,
    aventura,
    policial,
    romance,
    misterio
};

struct TLibro
{
    int isbn;
    string titulo;
    string autor;
    generos genero;
    bool espanol;
};
typedef struct TLibro Libro;

struct TNodo
{
    TNodo *ant;
    TNodo *sig;
    Libro dato;
};
typedef struct TNodo Nodo;

class ListaLibro
{
private:
    Nodo *pInicio;
    Nodo *pFinal;

public:
    ListaLibro();
    void insertar(Libro p);
    void insertarInicio(Libro p);
    void insertarFinal(Libro p);
    void insertarDespuesDe(Libro p);
    void insertarAntesDe(Libro p);

    void mostrarLista();
    void imprimirInverso();
    void imprimirInverso(Nodo *p);

    void eliminarLibro();

    bool buscar(int valor);
};

Libro solicitarLibro();
void mostrarLibro(Libro p);

ListaLibro::ListaLibro()
{
    pInicio = NULL;
    pFinal = NULL;
};

void ListaLibro::insertar(Libro p)
{
    bool continuar = true;
    do
    {
        int opcion = 0;
        cout << "\t1)Al principio\n\t2)Al final\n\t3)Despues de\n\t4)Antes de\n\tOpcion Elegida: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            insertarInicio(p);
            continuar = false;
            break;
        case 2:
            insertarFinal(p);
            continuar = false;
            break;
        case 3:
            insertarDespuesDe(p);
            continuar = false;
            break;
        case 4:
            insertarAntesDe(p);
            continuar = false;
            break;
        default:
            cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar);
}

void ListaLibro::insertarInicio(Libro p)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    nuevo->ant = NULL;
    if (!pInicio)
    {
        pFinal = nuevo;
        pInicio = nuevo;
    }
    else
    {
        pInicio->ant = nuevo;
        pInicio = nuevo;
    }
}
void ListaLibro::insertarFinal(Libro p)
{
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    if (!pInicio)
    {
        pInicio = nuevo;
        pFinal = nuevo;
    }
    else
    {
        Nodo *aux = pInicio;
        while (aux->sig)
            aux = aux->sig;
        aux->sig = nuevo;
        pFinal = nuevo;
        nuevo->ant = aux;
    }
}

void ListaLibro::insertarDespuesDe(Libro p)
{
    int unISBN = 0;
    cout << "ISBN de libro de referencia: ";
    cin >> unISBN;
    cin.ignore();
    Nodo *s = pInicio;
    while (s != NULL && (s->dato).isbn != unISBN)
        s = s->sig;
    if (s == NULL)
    {
        cout << "Libro de ref no existe. " << endl;
        return;
    }
    else
    {
        Nodo *nuevo = new Nodo;
        nuevo->dato = p;
        if (s->sig)
        {
            s->sig->ant = nuevo;
        }
        else
        {
            pFinal = nuevo;
        }
        nuevo->sig = s->sig;
        s->sig = nuevo;
        nuevo->ant = s;
        cout << "Libro ingresado exitosamente " << endl;
    }
}

void ListaLibro::insertarAntesDe(Libro p)
{
    int unISBN = 0;
    cout << "ISBN de referencia: ";
    cin >> unISBN;
    cin.ignore();
    Nodo *s = pInicio, *q = NULL;
    while (s != NULL && (s->dato).isbn != unISBN)
    {
        q = s; //anterior a s
        s = s->sig;
    }

    if (s == NULL)
    {
        cout << "Libro de referencia no existe" << endl;
        return;
    }
    else
    {
        Nodo *nuevo = new Nodo;
        nuevo->dato = p;
        if (q == NULL)
        {
            pInicio = nuevo;
            nuevo->sig = s;
            s->ant = nuevo;
            nuevo->ant == NULL;
        }
        else
        {
            q->sig = nuevo;
            nuevo->ant = q;
            s->ant = nuevo;
            nuevo->sig = s;
        }
        cout << "Libro ingresado exitosamente " << endl;
    }
}

void ListaLibro::mostrarLista()
{
    Nodo *s = pInicio;
    while (s != NULL)
    {
        mostrarLibro(s->dato);
        s = s->sig;
    }
}

void ListaLibro::imprimirInverso()
{
    Nodo *p = pFinal;
    cout << "Imprimiendo de forma inversa" << endl;
    imprimirInverso(p);
}
void ListaLibro::imprimirInverso(Nodo *p)
{
    //caso base
    if (!p)
        return;
    else
    {
        mostrarLibro(p->dato);
        //llamada recursiva
        imprimirInverso(p->ant);
    }
    //caso recursivo
}
void ListaLibro::eliminarLibro()
{
    Nodo *p = pInicio, *q = NULL;
    while (p != NULL && (p->dato).genero != 4)
    {
        q = p;
        p = p->sig;
    }
    if (p == NULL)
    {
        cout << "No hay mas libros que borrar" << endl;
        return;
    }
    else if (q == NULL)
    {
        pInicio = p->sig;
        pInicio->ant = NULL;
        delete p;
    }
    else
    {
        q->sig = p->sig;
        p->sig->ant = q;
        if (pFinal == p)
        {
            pFinal = q;
        }
        delete p;
    }
    cout << "Libro eliminado" << endl;
    if (p != NULL)
    {
        eliminarLibro();
    }
}

bool ListaLibro::buscar(int valor)
{
    Nodo *s = pInicio;
    switch (valor)
    {
    case 1:
        //libros de ccff
        while (s != NULL && (s->dato).genero != 0)
            s = s->sig;
        break;
    case 2:
        while (s != NULL && (s->dato).espanol == false)
            s = s->sig;
        //libros en espa
        break;
    }
    return s != NULL;
}

int main()
{
    ListaLibro Lista;
    cout << "Iniciando . . ." << endl;
    bool continuar = true;
    int op = 0;
    do
    {
        cout << "1)Agregar Libro\n\t2)Ver Libros\n\t3)Ver libros inversos"
             << "\n\t4)Eliminar libro de misterio\n\t5)Buscar libros de ciencia ficcion"
             << "\n\t6)Buscar espanol\n\t7)Salir\n\tOpcion elegida: ";
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Agregando . . ." << endl;
            Lista.insertar(solicitarLibro());
            break;
        case 2:
            cout << "Ver libros . . ." << endl;
            Lista.mostrarLista();
            break;
        case 3:
            cout << "Libros inversos  . . . " << endl;
            Lista.imprimirInverso();
            break;
        case 4:
            Lista.eliminarLibro();
            break;
        case 5:
            cout << "Hay libros de Ciencia ficcion?" << endl;
            if (Lista.buscar(1))
                cout << "Si hay libros de ciencia ficcion" << endl;
            else
                cout << "No hay libros de ciencia ficcion" << endl;
            break;
        case 6:
            cout << "Hay libros en espanol?" << endl;
            if (Lista.buscar(2))
                cout << "Si hay libros en espanol" << endl;
            else
                cout << "No hay libros en espanol" << endl;
            break;
        case 7:
            continuar = false;
            break;
        default:
            cout << "Opcion erronea!" << endl;
            break;
        }
    } while (continuar == true);

    return 0;
}

void mostrarLibro(Libro p)
{
    cout << "ISBN: " << p.isbn << endl;
    cout << "Titulo: " << p.titulo << endl;
    cout << "autor: " << p.autor << endl;
    cout << "Genero: ";

    switch (p.genero)
    {
    case ciencia_ficcion:
        cout << "Ciencia Ficción" << endl;
        break;
    case policial:
        cout << "Policial" << endl;
        break;
    case romance:
        cout << "Romance" << endl;
        break;
    case aventura:
        cout << "aventura" << endl;
        break;
    case misterio:
        cout << "misterio" << endl;
        break;
    }
    cout << "Idioma: " << (p.espanol ? "Espanol" : "Otro") << endl;
}

Libro solicitarLibro()
{
    Libro p;
    /*******solicitar campos**/
    cout << "ISBN: ";
    cin >> p.isbn;
    cin.ignore();
    cout << "Titulo: ";
    cin >> p.titulo;
    cin.ignore();
    cout << "Autor: ";
    getline(cin, p.autor);

    bool continuar = true;
    do
    {
        char opcion = 0;
        cout << "Genero(c,a,p,r,m): ";
        cin >> opcion;
        switch (opcion)
        {
        case 'c':
            p.genero = ciencia_ficcion;
            continuar = false;
            break;
        case 'a':
            p.genero = aventura;
            continuar = false;
            break;
        case 'p':
            p.genero = policial;
            continuar = false;
            break;
        case 'r':
            p.genero = romance;
            continuar = false;
            break;
        case 'm':
            p.genero = misterio;
            continuar = false;
            break;
        default:
            cout << "Opcion erronea" << endl;
            continuar = true;
            break;
        }
    } while (continuar);

    continuar = true;
    do
    {
        char letra = 0;
        cout << "Espanol (s/n) ";
        cin >> letra;
        switch (letra)
        {
        case 's':
            p.espanol = true;
            continuar = false;
            break;
        case 'n':
            p.espanol = false;
            continuar = false;
            break;
        default:
            cout << "Opcion erronea" << endl;
        }
    } while (continuar);

    return p;
}