#include <stdio.h>
#include <math.h>

//funcion de pruebas
void imprimirFila(float fila[],int tamanio){
	for(int i=0;i<tamanio;i++){
		printf(" %.2f",fila[i]);
	}
}

void imprimirSistema(float matriz[][20],int filas,int columnas){
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			printf("%2.f ",matriz[i][j]);
		}
		printf("\n");
	}
}



//funcion que hace 1 el pivote de una fila
void pivoteA1(float fila[],int pivote,int tamanio){
	float valDeDivision=fila[pivote];
	for(int i=0;i<tamanio;i++){
		fila[i]/=valDeDivision;
	}
}





void hacer0s(float fila1[],float fila2[],int pivote,int tamanio){
	float valorEliminar=fila2[pivote];
	
	float valRestar;
	for(int i=0;i<tamanio;i++){
		valRestar=valorEliminar*fila1[i];
		//printf("\n %2.f - %2.f = %2.f   \n",fila2[i],valRestar,(fila2[i]-valRestar));
		fila2[i] = fila2[i]-valRestar;
	}
}


void solucionar(float sistema[][20],int filas,int columnas){
	for(int i=0;i<filas;i++){
		pivoteA1(sistema[i],i,columnas);
		for(int j=i+1;j<filas;j++){
			hacer0s(sistema[i],sistema[j],i,columnas);
		}
		for(int h=0;h<i-1;h++){
			hacer0s(sistema[i],sistema[h],i,columnas);
		}
	}
}



int main(void){
	float matriz[3][20]={{1.0,3.0,4.0,2.0},
	                    {-2.0,4.0,7.0,1.0},
					    {4.0,2.0,4.0,1.0}};
	solucionar(matriz,3,4);
    imprimirSistema(matriz,3,4);
    
	
	return 0;
}
