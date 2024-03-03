#include <iostream>

using namespace std;

int main () {
	
	int opc ;
	const int width = 25; //Ancho de la pantalla
	const int heigth = 3; //Altura de la pantalla
	
	//Dibuja la parte superior de la pantalla
	
	for(int i = 0; i < width; ++i){
		cout<<"-";
	}
	cout<<endl;

	
	//Dibuja los lados de la pantalla
	
	for(int i = 0; i < heigth; ++i) {
		cout<<"|";
		for(int j = 0; j < width - 2; ++j) {
			cout<<"* ";
			if (j == 1 && i == 1){
				cout<<"BIENVENIDO AL MENU"<<endl;
			}
		}
		cout<<"|"<< endl;
	}
	
	
		
	//Dibuja la parte inferior de la pantalla
	
	for(int i = 0; i<width; ++i){
		cout<<"-";
	}
	cout<<endl;
	
	cout<<"\n";
	
	//¨*******************MENU********************
	
	cout<<"|COSTO MINIMO - 1:\n|ESQUINA NOROESTE - 2:\n|Salir - 3:\n|Ingrese la opcion a elegir:"; cin>>opc;
	
	
	switch(opc) {
		case 1:
				cout<<"Costo Minimo";
			break;
		
		case 2:
				cout<<"Esquina Noroeste";
			break;
			
		default:
			
			cout<<"Error!";
	}

	
	

	
	
	
	
	
	
	
	return 0;
	
}