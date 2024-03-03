#include<iostream>
#include<cstdlib>
#include <chrono>
#include <thread>

#include <vector>
#include <algorithm> // Para std::sort
#include<limits>



using namespace std;

void mostrarBarraDeCarga(int progreso, int total, int longitud) {
    float porcentaje = static_cast<float>(progreso) / total;
    int caracteresCargados = static_cast<int>(porcentaje * longitud);

    cout << "[";
    for (int i = 0; i < caracteresCargados; ++i) {
        cout << '|';
    }
    for (int i = caracteresCargados; i < longitud; ++i) {
        cout << ' ';
    }
    cout << "] " << static_cast<int>(porcentaje * 100) << "%\r";
    cout.flush();
}


int main() {
	
	int tabla [10][10];
	int costo [10][10];
	int ofer_costo [10][10];
	int demanda [10][10];
	
	int valMin [10][10];
	int oferta [10][10];
	int filaz,columnaz;
	int filamin, columnamin, val_demanda, val_oferta;
	

	
	cout<<"Ingresa el numero de filas: "; cin>>filaz;
    cout<<"Ingresa el numero de columnas: "; cin>>columnaz;	
    const int filas = filaz; // Tamaño de filas de la matriz
    const int columnas = columnaz; // Tamaño de columnas de la matriz
	
	
	//GENERAMOS LA PRIMERA TABLA
	for (int i = 0; i < filas; i++ ){
		
		for(int j = 0; j < columnas; j++){
			
			//SELECCIONAMOS LAS CELDAS DE COSTO
			if(i<columnas -1 && j<filas-1){
				cout<<"[C]";
			}    
			
			//SELECCIONAMOS LAS CELDAS DE DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				cout<<"[D]";
			}    
			
			// SELECCIONAMOS LAS CELDAS DE OFERTA
			if(i<filas -1   && j==columnas -1){
				cout<<"[F]";
			}  
		}
		cout<<"\n";
	}
	
	//*****************RECOLEPCION DE DATOS**********************************
	
	//INGRESAMOS LOS DATOS EN LAS CELDAS 	
	for (int i = 0; i < filas; i++ ){
		
		for(int j = 0; j < columnas; j++){
	
			//INGRESAMOS DATOS A LAS CELDAS DE COSTO
			if(i<columnas -1 && j<filas-1){
				cout<<"Ingresa el valor del COSTO ["<<(i)<<"]["<<(j)<<"]:";cin>>costo[i][j];
			}   
	
			//INGRESAMOS DATOS A LAS CELDAS DE DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				system("cls");
				cout<<"Ingresa el valor de la DEMANDA ["<<(i)<<"]["<<(j)<<"]:";cin>>demanda[i][j];
			}  
			
			//INGRESAMOS DATOS A LAS CELDAS DE OFERTA
			if(i<filas -1   && j==columnas -1){
				cout<<"Ingresa el valor de la OFERTA ["<<(i)<<"]["<<(j)<<"]:";cin>>oferta[i][j];
			}  
		
	
		}

				cout<<"\n";
	}
	
	
	system("cls");
	
	
	/*****************POST LIMPIEZA DE PANTALLA */
	//GENERAMOS LA PRIMERA TABLA
	
	cout<<"TABLA 1"<<endl;
	for (int i = 0; i < filas; i++ ){
		
		for(int j = 0; j < columnas; j++){
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
			if(i<columnas -1 && j<filas-1){
				cout<<"["<<(costo[i][j])<<"]";
			}   
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				cout<<"["<<(demanda[i][j])<<"]";
			}   
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				cout<<"["<<(oferta[i][j])<<"]";
			}  
		
		}
		cout<<"\n";
	}
	
	
	int menor= std::numeric_limits<int>::max();
	int menor_aux;

    // Recorremos la matriz para encontrar el número más pequeño
 
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
        	
        	if(i<columnas -1 && j<filas-1){
        		
        		
        		int total = 100;
    			int longitud = 20;
    		
			    if(i == 0 && j == 0) {
			    	cout <<"Procesando..."<< endl; 
			    	for (int i = 0; i <= total; ++i) {
			        mostrarBarraDeCarga(i, total, longitud);
			        // Simular una pausa para mostrar la barra de carga
			        this_thread::sleep_for(chrono::milliseconds(30));
			    	}
			    	cout << endl << "Proceso completado!" << endl;
				}
			    
			    
				if (costo[i][j] < menor) {
                menor = costo[i][j];
                menor_aux = costo[i][j];
                filamin = i;
                columnamin = j;
            	}
            	
            	
			} 
            
        }
    }
    
    /******************************************************/
 
	/***************************************************************************/
		


	
	 std::cout << "El numero mas pequeno en la matriz es: " << menor << std::endl;
	 
	 
	 /*SE GENERA LA TABLA CON LOS VALORES PREVIAMENTE RECOLEPTADOS 
	 SELECCIONANDO EL VALOR MINIMO Y SUS REFERENCIAS
	 ********************************************************/
	 
	 
	 cout<<"\nTABLA 2"<<endl;
	 
	 for(int i = 0; i<filas; i++){
	 	
	 	for(int j = 0; j < columnas; j++){
	 		
	 		//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
			if(i<columnas -1 && j<filas-1){
				
				if(i == filamin && j == columnamin){
					
					cout<<"[*"<<(menor)<<"*]";
					
				}
				else{
					cout<<"[ "<<(costo[i][j])<<" ]";
				}
			}   
		
			//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				//OBTENEMOS EL VALOR DE LA DEMANDA LIGADA AL VALOR MINIMO
				
				if(i == filas -1 && j == columnamin){
					val_demanda = demanda[i][j];
					cout<<"[*"<<(demanda[i][j])<<"*]";
				}
				
				else{
					cout<<"[ "<<(demanda[i][j])<<" ]";
				}
				
			
			}   
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				//OBTENEMOS EL VALOR DE LA OFERTA LIGADA AL VALOR MINIMO
				
				if(i == filamin && j == columnas -1){
					val_oferta = oferta[i][j];
					cout<<"[*"<<(oferta[i][j])<<"*]";
				}
				
				else{
					cout<<"[ "<<(oferta[i][j])<<" ]";
				}
			}  	
		 }		 
		cout<<"\n";
	 }
	
	
	//PRIMERA ITERACION
		cout<<"\n";
		
		
	//EN CASO DE QUE LA OFERTA SEA MENOR A LA DEMANDA
	if(val_oferta < val_demanda){
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++ ){
				
				
				//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
				if(i<columnas -1 && j<filas-1){
				
					if(i == filamin){
						if(costo[i][j] == menor){
							cout<<"[ "<<(val_oferta)<<" ]";
						}
						else 
						{
							cout<<"[ X ]";}
					
					}	else{
					cout<<"[ "<<(costo[i][j])<<" ]";
					}
				
				}
				
				
					//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				//OBTENEMOS EL VALOR DE LA DEMANDA LIGADA AL VALOR MINIMO
				
				if(i == filas -1 && j == columnamin){
					
					val_demanda = val_demanda - val_oferta;
				
					cout<<"[ "<<(val_demanda)<<" ]";
				}
				
				else{
					cout<<"[ "<<(demanda[i][j])<<" ]";
				}
				
			
			}   
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				//OBTENEMOS EL VALOR DE LA OFERTA LIGADA AL VALOR MINIMO
				
				if(i == filamin && j == columnas -1){
					ofer_costo[i][j] = val_oferta;
					cout<<"["<<(ofer_costo[i][j])<<"/0]";
				}
				
				else{
					cout<<"[ "<<(oferta[i][j])<<" ]";
				}
			}
				
				
			}
			cout<<"\n";
		}
	}

	/***********************************************************/
	
	
	
	//EN CASO DE QUE LA OFERTA SEA MAYOR A LA DEMANDA
	if(val_oferta > val_demanda){
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++ ){
				
				
				//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
				if(i<columnas -1 && j<filas-1){
				
					if(j == columnamin){
						if(costo[i][j] == menor){
							cout<<"[ "<<(val_demanda)<<" ]";
						}
						else 
						{
							cout<<"[ X ]";
							costo[i][j] = 0;
							
						}
					
					}
					else{
					cout<<"[ "<<(costo[i][j])<<" ]";
					}
				}
				
				
				
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				//OBTENEMOS EL VALOR DE LA OFERTA LIGADA AL VALOR MINIMO
				
				if(i == filamin && j == columnas -1){
					ofer_costo[i][j] = val_oferta;
					val_oferta = val_oferta - val_demanda;
					cout<<"["<<(val_oferta)<<"]";
				}
				
				else{
					cout<<"[ "<<(oferta[i][j])<<" ]";
				}
			}	
				
			//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				//OBTENEMOS EL VALOR DE LA DEMANDA LIGADA AL VALOR MINIMO
				
				if(i == filas -1 && j == columnamin){
					cout<<"["<<(demanda[i][j])<<"/0]";
				}
				
				else{
					cout<<"[ "<<(demanda[i][j])<<" ]";
				}
				
			
			}   
			
			
				
				
			}
			cout<<"\n";
		}
	} 
		
  
	/*PRUEBAS*****************************************************************************/	
		
		menor= std::numeric_limits<int>::max();
	    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
        	
        	if(i<columnas -1 && j<filas-1){
        		
        		
        		int total = 100;
    			int longitud = 20;
    		
			    if(i == 0 && j == 0) {
			    	cout <<"Procesando..."<< endl; 
			    	for (int i = 0; i <= total; ++i) {
			        mostrarBarraDeCarga(i, total, longitud);
			        // Simular una pausa para mostrar la barra de carga
			        this_thread::sleep_for(chrono::milliseconds(30));
			    	}
			    	cout << endl << "Proceso completado!" << endl;
				}
			    
			    if (costo[i][j] < menor && costo[i][j] != menor_aux && costo[i][j] !=0) {
                menor = costo[i][j];
                filamin = i;
                columnamin = j;
            	}
			
            	
            	
			} 
            
        }
    }
	 
        	
        
     
	/**************************************************************************************************/
		 /*SE GENERA LA TABLA CON LOS VALORES PREVIAMENTE RECOLEPTADOS 
	 SELECCIONANDO EL VALOR MINIMO Y SUS REFERENCIAS
	 ********************************************************/
	 
	 
	 cout<<"\nTABLA 3"<<endl;
	 
	 for(int i = 0; i<filas; i++){
	 	
	 	for(int j = 0; j < columnas; j++){
	 		
	 		//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
			if(i<columnas -1 && j<filas-1){
				
				if(costo[i][j] == 0){
					cout<<"[ X ]";
				}
				
				if(i == filamin && j == columnamin){
					
					cout<<"[*"<<(menor)<<"*]";
					
				}
				else{
					cout<<"[ "<<(costo[i][j])<<" ]";
				}
			}   
		
			//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				//OBTENEMOS EL VALOR DE LA DEMANDA LIGADA AL VALOR MINIMO
				
				if(i == filas -1 && j == columnamin){
					val_demanda = demanda[i][j];
					cout<<"[*"<<(demanda[i][j])<<"*]";
				}
				
				else{
					cout<<"[ "<<(demanda[i][j])<<" ]";
				}
				
			
			}   
			
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				//OBTENEMOS EL VALOR DE LA OFERTA LIGADA AL VALOR MINIMO
				
				if(i == filamin && j == columnas -1){
					//val_oferta = oferta[i][j];
					cout<<"[-"<<(val_oferta)<<"-]";
				}
				
				else{
					cout<<"[ "<<(oferta[i][j])<<" ]";
				}
			}  	
		 }		 
		cout<<"\n";
	 }                             
	
	/***************************************************************************************/
	
	cout<<"\n";
	
	//SEGUNDA ITERACION "PRUEBA"
	
		//EN CASO DE QUE LA OFERTA SEA MAYOR A LA DEMANDA
	if(val_oferta >= val_demanda){
		for(int i = 0; i < filas; i++){
			for(int j = 0; j < columnas; j++ ){
	
				
				//IMPRIMIMOS LOS VALORES EN LA CELDAS COSTO
				if(i<columnas -1 && j<filas-1){
				
					if(j == columnamin){
						if(costo[i][j] == menor){
							cout<<"[ "<<(val_demanda)<<" ]";
						}
						else 
						{
							cout<<"[ X ]";
							costo[i][j] = 0;
							
						}
					
					}
					else{
					cout<<"[ "<<(costo[i][j])<<" ]";
					}
				}
				
				
				
			//IMPRIMIMOS LOS VALORES EN LA CELDAS OFERTA
			if(i<filas -1   && j==columnas -1){
				//OBTENEMOS EL VALOR DE LA OFERTA LIGADA AL VALOR MINIMO
				
				if(i == filamin && j == columnas -1){
					ofer_costo[i][j] = val_oferta;
					val_oferta = val_oferta - val_demanda;
					cout<<"[-"<<(val_oferta)<<"-]";
				}
				
				else{
					cout<<"[ "<<(oferta[i][j])<<" ]";
				}
			}	
				
			//IMPRIMIMOS LOS VALORES EN LA CELDAS DEMANDA
			
			if(i==filas -1   && j<columnas -1){
				//OBTENEMOS EL VALOR DE LA DEMANDA LIGADA AL VALOR MINIMO
				
				if(i == filas -1 && j == columnamin){
					cout<<"["<<(demanda[i][j])<<"/0]";
				}
				
				else{
					cout<<"[ "<<(demanda[i][j])<<" ]";
				}
				
			
			}   
			
			
				
				
			}
			cout<<"\n";
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	//LOS ORDENA DE MENOR A MAYOR
	
	/*
	 // Convertir la matriz a un vector unidimensional
    vector<int> elementos;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            elementos.push_back(costo[i][j]);
        }
    }

    // Ordenar el vector de menor a mayor
    sort(elementos.begin(), elementos.end());

    // Actualizar la matriz ordenada
    int indice = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            costo[i][j] = elementos[indice++];
        }
    }

    // Imprimir la matriz ordenada
    cout << "Matriz ordenada de menor a mayor:" << endl;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << costo[i][j] << " ";
        }
        cout << endl;
    }
*/

	
	
	return 0;
	
	
	
}

