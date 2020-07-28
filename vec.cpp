// Ingresar cantidad de horas trabajadas de 5 empleados, solictar valor de hora de trabajo 
#include <iostream>

using namespace std;

int main(){
	
	float vec[5];
	float horas;
	float precio;
	cout << "Ingrese precio por hora: " <<endl;
	cin>> precio;
	for (int i=0;i<5;i++) {
		cout << "Ingrese cantidad de horas trabajadas del empleado "<< i+1 <<endl;
		cin>> horas;
		vec[i] = horas * precio;
	}
	
	cout<< "Pago total: "<<endl;
    for (int i=0; i<5;i++){
		cout <<endl<< "Empleado "<< i+1<< ": $" << vec[i]<<endl;
	}
	return 0;
}
