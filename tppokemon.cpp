//Ingresar pokemons en la pokedex e informar tipo y nivel.
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include<conio.h>
#include <stdlib.h>

using namespace std;

struct Pokemon {

	char tipo;
	int nivel;
	char nombre [10];

};

void cnivel(int nivel,int & cnmay500,int & cnmen500,int & cnig500 ) {
 
 if(nivel>500){
    cnmay500++; 
	}
    else if(nivel<500){
        cnmen500++;  
		}
    else{
        cnig500++; 
		}
 };

void Mayor(int nivel,int & maynv,char nombre [],string & maynom){
  if(nivel>=maynv){
    maynv=nivel;
    maynom=nombre;
  }

};

void Menor(int nivel, int & mennv,char nombre[],string & mennom,bool & bandera){
if(bandera|| nivel <= mennv){
 	mennv = nivel;
 	mennom = nombre;
 	bandera = false;
 }
};

void Suma (float suma, float total, double &prom, string pokemon, string maynom,int maynv,string mennom,int mennv){

if(suma!=0){
     prom= suma/total;

    cout<<"---------------------------------------------------------------------"<<endl;
    cout <<"\nPOKEMONS TIPO " <<pokemon<<endl;
	cout <<"\n Total: " <<total<<"\n Promedio: " <<prom<<endl;
    cout <<" El Pokemon mas fuerte es "<<maynom<< " con nivel " << maynv << endl;
    cout <<" El Pokemon mas debil es "<<mennom<< " con nivel "<< mennv<< endl;

 }
 else{
    suma=1;
    prom= total/suma;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout <<"\nPOKEMONS TIPO " <<pokemon<<endl;
	cout <<"\n Total: " <<total<<"\n Promedio: " <<prom<<endl;
    cout <<" No existe pokemon tipo "<<pokemon<<endl; 
 }
};

int main() {
	int cant;
Pokemon reg;
	FILE* dat = fopen("PokemonGo.dat","wb+");
	printf("                             **********Creando el archivo**********\n\n");

cout<<"      -###########----########----###---####----#########----###-----###----########----###----- ##-------- "<<endl;
cout<<"     --###-----###----##----##----###--###------###----------##-#---#-##----##----##----##-#---- ##------"<<endl;
cout<<"    ---###-----###----##----##----###-###-------###----------##--#-#--##----##----##----##--#--- ##-----"<<endl;
cout<<"   ----###########----##----##----#####---------#########----##---#---##----##----##----##---#-- ##----"<<endl;
cout<<"  -----###------------##----##----###-###-------###----------##-------##----##----##----##----#- ##---"<<endl;
cout<<" ------###------------##----##----###--###------###----------##-------##----##----##----##------###--"<<endl;
cout<<"-------###------------########----###   ####----#########----##-------##----########----##------ ##-"<<endl;
cout<<""<<endl;
cout<<"                                         ###########      ########  ##                               "<<endl;
cout<<"                                         ###              ##    ##  ##                               "<<endl;
cout<<"                                         ###              ##    ##  ##                               "<<endl;
cout<<"                                         ###   #####      ##    ##  ##                               "<<endl;
cout<<"                                         ###   #####      ##    ##  ##                               "<<endl;
cout<<"                                         ###      ##      ##    ##                                   "<<endl;
cout<<"                                         ###########      ########  ##                               "<<endl;




	system("pause");
	system("cls");
	cout << "\nIngrese cantidad de pokemones a registrar:\n" << endl;
	cin >> cant;

	for(int i=1;i<=cant;i++){

		cout << "\nIngrese nombre del Pokemon:\n" << endl;
		cin>>reg.nombre;

		while (strlen (reg.nombre) > 10) {
				cout << "\nNombre incorrecto. Ingrese nuevamente:\n" <<endl;
				cin>>reg.nombre;
		}
		cout << "\nIngrese tipo de Pokemon: \n Si es de agua ingrese: A \n Si es de fuego ingrese: F \n Si es de Tierra ingrese: T \n Si es electrico ingrese: E \n" << endl;
		cin >> reg.tipo;

		while ( (reg.tipo)!= 'a'&& (reg.tipo)!='e'&&(reg.tipo)!='f'&& (reg.tipo)!='t' && (reg.tipo)!= 'A'&& (reg.tipo)!='E'&&(reg.tipo)!='F'&& (reg.tipo)!='T')
		{

			cout << "\nIngrese correctamente el tipo de pokemon:\n"<<endl;
			cin>>reg.tipo;
}


		cout << "\nIngrese nivel del Pokemon:\n" << endl;
		cin >> reg.nivel;
			while (reg.nivel > 1000 or reg.nivel <=0) {
				cout << "\nNivel incorrecto.Ingrese nuevamente:\n" <<endl;
				cin>>reg.nivel;
		}
		fwrite(&reg,sizeof(reg),1,dat);
};
fclose (dat);

    bool bandera=true; bool bandera1=true; bool bandera2=true; bool bandera3=true;
    int maynvA=0; int maynvF=0; int maynvE=0; int maynvT=0; int cnmay500=0; int cnmen500=0; int cnig500=0;
	int mennvA=0; int mennvF=0; int mennvT=0; int mennvE=0;

    float totalA=0; float sumaA=0; float totalT=0; float sumaT=0; float totalF=0; float sumaF=0;float totalE=0; float sumaE=0;
    double prom= sumaA/totalA; double prom1= sumaE/totalE; double prom2=sumaF/totalF; double prom3=sumaT/totalT;
    string mennomA; string maynomA; string mennomF; string maynomF; string mennomE; string maynomE; string mennomT; string maynomT;

	dat = fopen ("PokemonGo.dat", "rb");
	fread(&reg,sizeof(reg),1,dat);

	while(!feof(dat)){


    switch(reg.tipo){


	   case'a': case'A':

       	    totalA ++;
			sumaA += reg.nivel;
            Mayor (reg.nivel,maynvA,reg.nombre,maynomA);
			Menor (reg.nivel,mennvA,reg.nombre, mennomA,bandera3);
			break;

       case'f': case'F':

            totalF ++;
			sumaF = sumaF + reg.nivel;
            Menor(reg.nivel,mennvF,reg.nombre, mennomF,bandera1);
            Mayor(reg.nivel,maynvF,reg.nombre,maynomF);
            break;

       case't': case'T':

            totalT ++;
			sumaT = sumaT + reg.nivel;
		    Menor(reg.nivel,mennvT,reg.nombre, mennomT,bandera);
            Mayor(reg.nivel,maynvT,reg.nombre,maynomT);
			break;

        case'e': case'E':

			totalE ++;
			sumaE = sumaE + reg.nivel;
			Menor(reg.nivel,mennvE,reg.nombre, mennomE,bandera2);
            Mayor(reg.nivel,maynvE,reg.nombre,maynomE);
	        break;
   };

    cnivel (reg.nivel, cnmay500,cnmen500, cnig500 );
    fread(&reg,sizeof(reg),1,dat);
};
getch();
fclose (dat);
    
    string pokemon;
    Suma (sumaA, totalA, prom, "AGUA", maynomA, maynvA, mennomA, mennvA);
    Suma (sumaF, totalF, prom2, "FUEGO", maynomF, maynvF, mennomF, mennvF);
    Suma (sumaT, totalT, prom3, "TIERRA", maynomT, maynvT, mennomT, mennvT);
    Suma (sumaE, totalE, prom1, "ELECTRICO", maynomE, maynvE, mennomE, mennvE);
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"\n Total de Pokemons con nivel > 500: "<<cnmay500<<endl;
    cout<<"\n Total de Pokemons con nivel < 500: "<<cnmen500<<endl;
    cout<<"\n Total de Pokemons con nivel = 500: "<<cnig500<<endl;
    
return 0;
};
