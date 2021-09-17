#include <iostream>
using namespace std;

struct libro{
	string titulo;
	int numPaginas;
	libro *sig;
};

class ListaLibros{
    private: 
        libro *pInicio;

    public:
        ListaLibros();
        void insertarEnLista();
        void insInicio(string titulo, int numPaginas);
        void mostrarLibros();
        //Funcion que va a ser llemada desde main
        void buscarLibro();
        //Funcion con sobrecarga
        void buscarLibro(libro *p, string buscar);
};

ListaLibros::ListaLibros(){
    pInicio = NULL;
}

void ListaLibros::insertarEnLista(){
    string titulo = "";
    int numPaginas = 0, op = 1;

    do{
        cout << "Titulo: ";
        cin.ignore();
        getline(cin, titulo);
        cout << "Numero de paginas: ";
        cin.clear();
        cin >> numPaginas;
        insInicio(titulo, numPaginas);
        cout << "Agregar libro? 1) Si 2) No ";
        cin >> op;
    }while(op == 1);
}

void ListaLibros::insInicio(string titulo, int numPaginas){
    libro *nuevo;

    //Insertar como en una pila porque el ejercicio dice que son una pila de libros
    nuevo = new libro;
    nuevo->titulo = titulo;
    nuevo->numPaginas = numPaginas;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ListaLibros::mostrarLibros(){
    libro *p;
    cout << "\tMOSTRANDO LIBROS..." << endl;
    p = pInicio;
    while(p){
        cout << "Titutlo: " << p->titulo << endl;
        cout << "Numero de paginas: " << p->numPaginas << endl;
        p = p->sig;
    }
}

void ListaLibros::buscarLibro(){
    libro *p = pInicio;
    string buscar = "";
    //Solicitar el nombre del libro a buscar
    cout << "Libro a buscar: ";
    cin.ignore();
    getline(cin, buscar);

    if (!p){
        cout << "El libro a buscar no existe" <<endl;
	    return;
	}
	else{//Si el nombre ingresado es igual al titulo en esa posicion de la lista
	    if(p->titulo == buscar){
		    cout<<"El libro tiene: "<<p->numPaginas<<" paginas"<<endl;
		    return;
        }
	    else
		    buscarLibro(p->sig,p->titulo);
	}
}

void ListaLibros::buscarLibro(libro *p, string buscar){
    if (!p){
        cout << "El libro a buscar no existe" <<endl;
	    return;
	}
	else{//Si el titulo recibido es igual al titulo del libro en esa posicion de la lista
	    if(p->titulo==buscar){
		    cout<<"El libro tiene: "<<p->numPaginas<<" paginas"<<endl;
		    return;
        }
	    else
		    buscarLibro(p->sig,buscar);
	}
}

int main(){
    ListaLibros objlibros;
    int op = 0;

    do{
        cout << "\tMENU" << endl;
        cout << "1) Ingresar libro" << endl;
        cout << "2) Mostrar libro" << endl;
        cout << "3) Buscar libro" << endl;
        cout << "0) Salir\t\tSu opcion: ";
        cin >> op;
        cin.clear();
        switch (op){
            case 0://Opcion de salir
                break;
            case 1://Insertar libros en la pila
                objlibros.insertarEnLista();
                cin.clear();
                break;
            case 2://Mostrar los libros de la pila
                objlibros.mostrarLibros();
                break;
            case 3://Buscar libro por su titulo
                objlibros.buscarLibro();
                cin.clear();
                break;
            default://Si no ingresa una opcion valida
                cout << "Opcion invalida" << endl;
                break;
        }
    }while(op != 0);

    return 0;
}




