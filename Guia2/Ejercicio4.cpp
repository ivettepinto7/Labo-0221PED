#include <iostream>
#include <string>
using namespace std;

//El struct para los nodos
struct nodo
{
	int carnet, edad;
	string nombre, apellido, telefono, correo;
	nodo *sig;
};

class Personas
{
	//atributo de la clase
private:
	nodo *pInicio;

public:
	//firmas de los métodos de la clase
	Personas();
	void insertarEnLista(void);
	void eliminarPersona(void);
	void actualizarPersona(void);
	void mostrarPersonas();
	void mostrarPersonas(nodo *p);
};

//constructor
Personas::Personas(void)
{
	pInicio = NULL;
}

void Personas::insertarEnLista(void)
{
	//declarar el nuevo nodo
	nodo *nuevo;
	nuevo = new nodo;
	cout << "Carnet: ";
	cin >> nuevo->carnet;
	cout << "Edad: ";
	cin >> nuevo->edad;
	cin.clear();
	cin.ignore(1000, '\n');
	cout << "Nombre: ";
	getline(cin, nuevo->nombre);
	cout << "Apellido: ";
	getline(cin, nuevo->apellido);
	cout << "Numero de telefono: ";
	getline(cin, nuevo->telefono);
	cout << "Correo electronico: ";
	getline(cin, nuevo->correo);
	nuevo->sig = NULL;
	//lista vacia (false)
	if (!pInicio)
	{
		pInicio = nuevo;
	}
	else
	{
		//un auxiliar
		nodo *aux = pInicio;
		//se mueve hasta el final de la lista
		while (aux->sig != NULL)
			aux = aux->sig;
		//se asigna al final de la lista
		aux->sig = nuevo;
	}
}

void Personas::eliminarPersona(void)
{

	int carnet = 0;
	nodo *p = pInicio;
	nodo *q = NULL;
	cout << "Ingrese el carnet de la persona a eliminar: ";
	cin >> carnet;

	//verificar si el primer nodo es el correcto
	if (pInicio->carnet == carnet)
	{
		//el nuevo inicio sera el siguiente
		pInicio = pInicio->sig;
		//eliminar el que se buscó
		delete (p);
		cout << "Persona eliminada!" << endl;
		return;
	}
	//verificar que el nodo contenga datos y no sea el carnet que se busca
	while (p != NULL && p->carnet != carnet)
	{
		//en 1,2,3,4
		//q y p son 1
		q = p;
		//p es 2
		p = p->sig;
	}
	//a este punto se llegó al ultimo nodo
	if (p == NULL)
	{
		cout << "Persona a borrar NO existe" << endl;
		return;
	}

	if (q == NULL)
		p = p->sig;
	else
		q->sig = p->sig;
	delete (p);
	cout << "Persona eliminada!" << endl;
}

void Personas::actualizarPersona()
{
	nodo *p = pInicio;
	int carnet = 0;
	nodo *q = NULL;

	cout << "Ingrese el carnet de la persona a actualizar: ";
	cin >> carnet;

	while (p != NULL && p->carnet != carnet)
	{
		q = p;
		p = p->sig;
	}

	if (p == NULL)
	{
		cout << "Persona a actualizar NO existe" << endl;
		return;
	}
	cout << "Que desea actualizar?\n\t1.Carnet\n\t2.Nombre\n\t3.Apellido\n\t4.Edad\n\t5.Telefono\n\t6.Correo";
	cin >> carnet;
	switch (carnet)
	{
	case 1:
		cout << "Ingrese el nuevo carnet: ";
		cin >> p->carnet;
		break;
	case 2:
		cout << "Ingrese el nuevo nombre: ";
		cin >> p->nombre;
		break;
	case 3:
		cout << "Ingrese el nuevo apellido: ";
		cin >> p->apellido;
		break;
	case 4:
		cout << "Ingrese la nueva edad: ";
		cin >> p->edad;
		break;
	case 5:
		cout << "Ingrese el nuevo telefono: ";
		cin >> p->telefono;
		break;
	case 6:
		cout << "Ingrese el nuevo correo: ";
		cin >> p->correo;
		break;
	default:
		cout << "Opcion invalida." << endl;
	}
}

void Personas::mostrarPersonas()
{
	//para no perder referencias cuando nos movamos
	nodo *p = pInicio;
	if (!p)
		return;
	else
	{
		cout << "Carnet: " << p->carnet << endl;
		cout << "Edad: " << p->edad << endl;
		cout << "Nombre: " << p->nombre << endl;
		cout << "Apellido: " << p->apellido << endl;
		cout << "Numero de telefono: " << p->telefono << endl;
		cout << "Correo electronico: " << p->correo << endl
			 << endl;
		mostrarPersonas(p->sig);
	}
}
void Personas::mostrarPersonas(nodo *p)
{
	if (!p)
		return;
	else
	{
		cout << "Carnet: " << p->carnet << endl;
		cout << "Edad: " << p->edad << endl;
		cout << "Nombre: " << p->nombre << endl;
		cout << "Apellido: " << p->apellido << endl;
		cout << "Numero de telefono: " << p->telefono << endl;
		cout << "Correo electronico: " << p->correo << endl
			 << endl;
		mostrarPersonas(p->sig);
	}
}

int main(void)
{
	//objeto persona
	Personas persona;

	int res = 0;
	do
	{
		cout << "MENU:\n\t1-Ingresar persona\n\t2-Eliminar persona\n\t3-Actualizar datos de una persona\n\t4-Mostrar personas\n\t0-Salir.\t\tSu opcion: ";
		cin >> res;
		switch (res)
		{
		case 1:
			cout << "Ingresando . . ." << endl;
			persona.insertarEnLista();
			break;
		case 2:
			cout << "Eliminar . . ." << endl;
			persona.eliminarPersona();
			break;
		case 3:
			cout << "Actualizar datos . . ." << endl;
			persona.actualizarPersona();
			break;
		case 4:
			cout << "Imprimiendo . . ." << endl;
			persona.mostrarPersonas();
			break;
		case 0:
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	} while (res != 0);

	return 0;
}
