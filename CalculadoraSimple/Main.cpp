#include <iostream>
using namespace std;

int main() {
	
	int A = 0;
	int B = 0;
	cout << "Escriba el valor de A:" << endl;
	cin >> A;
	cout << "Escriba el valor de B:" << endl;
	cin >> B;
	cout << "Primer valor: " << A << "Segundo valor:" << B << endl;
	int resultado;
	char operacion;
	cout << "Que operacion desea hacer? (* o /)" << endl;
	cin >> operacion;
	if (operacion == '*') {
		resultado = A * B;
	}
	else {
		resultado = A / B;
	}
	cout << "El Resultado es: " << resultado << endl;
	int C = 0;
	int D = 0;
	cout << "Escribe el valor de C:" << endl;
	cin >> C;
	cout << "Escribe el valor de D:" << endl;
	cin >> D;
	cout << "Tercer valor: " << C << "Cuarto valor:" << D << endl;
	int resultado2;
	char operacion2; 
	cout << "Que operacion quieres hacer (+,-,* o /)" << endl;
	cin >> operacion2;
	if (operacion2 == '+') {
		resultado2 = C + D;
	}
	else if (operacion2 == '-') {
		resultado2 = C - D;
	}
	else if (operacion2 == '*') {
		resultado2 = C * D;
	}
	else {
		resultado2 = C / D;
	}
	cout << "El resultado de la segunda operacion es:" << resultado2 << endl;



}