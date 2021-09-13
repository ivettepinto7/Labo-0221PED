//MCD
//Incluir librerias
#include <iostream>
//Namespace a utilizar por defecto
using namespace std;
//prototipos de funciones, o escribir toda la función previa a su llamada
//int verificar(int, int);
int verificar(int mayor, int menor);

//Main
int main(void)
{
	int mayor = 0, menor = 0;
	cout << "Ingrese el numero menor: ";
	cin >> menor;
	cout << "Ingrese el numero mayor: ";
	cin >> mayor;
	cout << "MCD: " << verificar(mayor, menor) << endl;
	return 0;
}

//Funciones a llamar
int verificar(int mayor, int menor)
{
	//caso base
	//división entera de mayor entre menor,
	//residuo 0--> el mcd es menor.

	if ((mayor % menor) == 0 || menor == 0)
		return menor;
	//caso recursivo
	//valor de menor pasa a mayor
	// y el residuo mayor%menor a menor
	else
	{
		int aux = 0;
		aux = mayor % menor;
		mayor = menor;
		menor = aux;
		return verificar(mayor, menor); //pausa
	}
}