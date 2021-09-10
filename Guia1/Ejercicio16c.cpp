#include <iostream>
using namespace std;

void movimientos(int d,char tA, char tB, char tC);

int main(){
	//Numero de discos
	int d = 0;
	
	cout << "Ingrese la cantidad de discos: ";
	cin >> d;

	while(d < 1){
		cout << "Ingrese una cantidad de discos valida: ";
		cin >> d;
	}
	movimientos(d,'A','B','C');

	return 0;
}
void movimientos(int d,char tA, char tB, char tC){
	//Si solo hay un disco en la torre A, se mueve directamente a la torre C
	if(d == 1){
		cout << "Se mueve el disco " << d << " de la torre " << tA << " a la torre " << tC << endl;
	}
	else{
		// Se disminuye la cantidad de discos en 1
		// Invertir el orden de las torres
		movimientos(d-1,tA,tC,tB);
		cout << "Se mueve el disco " << d << " de la torre " << tA << " a la torre " << tC <<endl;
		movimientos(d-1,tB,tA,tC);
	}
}
