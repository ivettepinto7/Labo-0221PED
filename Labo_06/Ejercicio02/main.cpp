#include "OrdenPupusas.hpp";

int menu(){
    int opc = 0;
    cout << "---MENU---" << endl;
    cout << "\t1) Agregar Orden" << endl;
    cout << "\t2) Ver Orden" << endl;
    cout << "\t3) Salir \tOpcion: ";
    cin >> opc;
    return opc;    
}

int main(){
    ListaOrden objListaOrden;
    
    bool continuar = true;
    Orden o;
    do{
        switch(menu()){
            case 1: cout << "Agregando..." << endl;
                o = solicitarOrden();
                objListaOrden.agregarOrden(o);
            break;
            case 2: cout << "Listando..." << endl;
                objListaOrden.mostrarListaOrdenes();
                objListaOrden.mostrarListaOrdenesInverso();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}