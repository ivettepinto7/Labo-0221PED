#include <iostream>
using namespace std;

//una estructura con el numero y el nodo siguiente.
struct nodo
{
    int numero;
    nodo *sig;
};

//La clase de la que será nuestro objeto.
class Lista
{
    //atributos y metodos privados
private:
    nodo *pInicio;
    //atributos y metodos publicos
public:
    //constructor
    Lista();

    //insertar en lista
    void insertarEnLista(void);
    void insInicio(int);
    //imprimir la lista
    void impresionRecursiva();
    void impresionRecursiva(nodo *);
    
    //eliminar de lista
    void eliminarDeLista();
    nodo *eliminarDeLista(nodo *, int);
};

//el constructor inicializa nuestor atributo pInicio como nulo.
Lista::Lista()
{
    pInicio = NULL;
};

void Lista::eliminarDeLista()
{
    int numeroAEliminar = 0;
    cout << "Numero a eliminar de lista: ";
    cin >> numeroAEliminar;
    cin.clear();
    //Porque la indicacion pide una funcion que se encarga 
    pInicio = eliminarDeLista(pInicio, numeroAEliminar);
}

//yo necesito darle otro valor a pInicio, y para que manejen otros tipos de funciones más complejas
nodo *Lista::eliminarDeLista(nodo *p, int numAbuscar)
{
    //Primero yo declararia un auxiliar llamado q, para no perder referencias a otros numeros
    nodo *q = p;

    //¿Cómo verificarían un elemento?
    //Puesto que vamos a devolver un elemento que será el nuevo pInicio
    while (p->numero == numAbuscar)
    {
        //vamos a mover el p hasta que encontremos un numero que no sea el que estamos buscando
        //en caso de que toda la lista este llena del numero a buscar p será NULL
        p = p->sig;
        //Por que se muere el programa?Que podemos poner para que no se muera?

        //if (!p) //para evitar error, si la lista solo es de numeros
        //  p = new nodo;
    }

    //si yo quisiera eliminar un numero que este en medio de otros 
    //nos vamos a saltar un numero por ejemplo 1, 2, 3, y buscamos eliminar al 2
    //entonces 1 debería apuntar a 3
    //verificaremos que el siguiente de q no sea nulo, porque despues
    while (q->sig != NULL)
    {
        //verificamos que el numeor del siguiente sea el que vamos a buscar,
        //si es asi entonces saltamos el siguiente en el que estamos al siguiente del siguiente
        if (q->sig->numero == numAbuscar)
        {
            //copiamos el siguiente de q en otra variable para luego liberar espacio de memoria
            nodo *t = q->sig;
            //y hacemos el salto, de esta forma q apuntará al siguiente del siguiente de q
            q->sig = q->sig->sig;
            //liberamos el espacio de t
            delete (t);
        }
        //de lo contrario solo nos movemos al siguiente para verificar
        else
        {
            //para movernos de elemento
            q = q->sig;
        }
    }

    return p;
}

void Lista::insertarEnLista(void)
{
    //enviamos el dato
    int dato = 0;

    cout << "Digite un numero: ";
    cin >> dato;
    insInicio(dato);
}

//funcion exclusiva para insercion
void Lista::insInicio(int dato)
{
    nodo *nuevo;
    nuevo = new nodo;

    nuevo->numero = dato;
    nuevo->sig = pInicio;

    pInicio = nuevo;
}

//imprimimos con el head de la funcion y posteriormente hacemos llamada recursiva a la sobrecarga
void Lista::impresionRecursiva()
{
    nodo *p = pInicio;
    if (!p)
        return;
    else
    {
        cout << p->numero << endl;
        impresionRecursiva(p->sig);
    }
}

void Lista::impresionRecursiva(nodo *p)
{
    if (!p)
    {
        return;
    }
    else
    {
        cout << p->numero << endl;
        impresionRecursiva(p->sig);
    }
}

int main(void)
{
    //Para que tengamos nuestra lista necesitamos el puntero que apuntaría hacia el head de nuestra lista
    //¿Qué es lo que necesitamos?
    Lista objListaNumeros;

    int res = 0;
    do
    {
        cout << "MENU:\n\t1-Ingresar numero\n\t2-Eliminar numero\n\t3-Mostrar numeros\n\t0-Salir\t\tSu opcion: ";
        cin >> res;
        switch (res)
        {
        case 1:
            cout << "Ingresando . . ." << endl;
            objListaNumeros.insertarEnLista();
            break;
        case 2:
            cout << "Eliminar . . ." << endl;
            objListaNumeros.eliminarDeLista();
            break;
        case 3:
            cout << "Mostrar datos . . ." << endl;
            objListaNumeros.impresionRecursiva();
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (res != 0);

    return 0;
};