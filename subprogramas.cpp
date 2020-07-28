//realice un programa que lea dos números enteros y muestre un menú con las opciones
//sumar los umeros, restarlos, multiplicarlos, dividorlos

//subprogramas

#include <iostream>
#include <conio.h> //getch
using namespace std;

 int suma (int n1, int n2){
 	return n1+n2;
 };
 int resta ( int n1, int n2){
 	return n1-n2;
 }
 int multiplicar (int n1, int n2){
 	return n1*n2;
 };
 void dividir (int n1, int n2, bool &error, float &resultado){
 	if (n2 != 0){
 		error = false;
 		resultado = n1/n2;
	 }
	 error = true;
	 resultado = 0;
	 cout <<"error"<<endl;
	return;
 };

int main(){
	int n1, n2;
	char letra;
	float resultado;
	bool error;
	cout << "Ingrese primer numero" <<endl; 
	cin >> n1;
	cout << "ingrese segundo numero"<<endl;
	cin >> n2;
	cout << "a - sumar"<<endl;
	cout << "b - restar"<<endl;
	cout << "c - mutiplicar"<<endl;
	cout << "d - dividir"<<endl;
	
	cin >> letra;
	
	switch (letra){
		case 'a': case 'A':
			resultado = suma(n1,n2);
			break;
		case 'b':
			resultado = resta(n1,n2);
			break;
		case 'c':
			resultado = multiplicar(n1,n2);
			break;
		case 'd':
			dividir(n1,n2, error, resultado);
			
			break;

	}
    
    cout << resultado<<endl;
	return 0;
}
