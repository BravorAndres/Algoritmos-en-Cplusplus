#include <stdio.h>

typedef int MATRIZ[50][50];

void sumaMat(MATRIZ matA,MATRIZ matB,MATRIZ matC,int n,int i,int j,int k,int h){
	if(i==k && j==h)
	    matC[i][j]=matA[i][j]+matB[i][j];
	else{
		int mi=(i+k)/2;
		int mj=(j+h)/2;
		sumaMat(matA,matB,matC,0,0,5,i,j);
		sumaMat(matA,matB,matC,i,j,0,5,0);
	}
	
	
}

int potencia(int base,int p){
	if(p==2)
	    return base*base;
	else if(p==3)
	    return base*base*base;
	else{
		if((p%2)==0){
			int aux=potencia(base,p/2);
			return aux*aux;
		}else
		    return base*potencia(base,p-1);
	}
}

int main(void){
	int a=25,b=4;
	
	printf("potencia %d^%d = %d",a,b,potencia(a,b));
	
	return 0;
}
