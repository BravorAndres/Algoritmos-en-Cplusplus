#include <stdio.h>
#define max 50


void imprimirConjunto(int conjunto[],int n){
	if(n>0){
		imprimirConjunto(conjunto,n-1);
		printf("%d\t",conjunto[n-1]);
	}
}


void adicionarConj(int conjunto[], int valor,int &n) {
	if (valor>0 && valor<max) {
		canjunto[n]=valor;
		n++;
	}
	else {
		printf("\nValor no valido para el Conjunto");
	}
}




int main(void){
	int vector[max]={0};
	adicionarConj(vector,34);
	for(char i=0;i<10;i++)
	    printf("%d\t",vector[i]);
}


