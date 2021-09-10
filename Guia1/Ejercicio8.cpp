#include <iostream>
using namespace std;
void imprimirRecursivo(int n, int actual);
int main(void)
{
	int n = 0;

	cout << "Ingrese un numero: ";
	cin >> n;
	//validacion
	while (n < 1)
	{
		cout << "El numero debe ser mayor a 0" << endl;
		cout << "Ingrese un numero: ";
		cin >> n;
	}

	imprimirRecursivo(n, 1);
	return 0;
}

void imprimirRecursivo(int n, int actual)
{
	//caso base
	//Si el numero es igual al max se imprime y se regresa al hilo pendiente
	if (actual == n)
	{
		cout << actual << endl;
		return;
	}
	//caso recursivo

	else
	{
		//se imprime el  1, 2
		cout << actual << endl;
		//se crea nuevo hilo, se retoma la linea 39 cuando se de el caso base
		imprimirRecursivo(n, actual + 1); //pausa
		cout << actual << endl;
		return;
	}
}