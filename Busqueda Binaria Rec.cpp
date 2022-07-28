#include <stdio.h>


int busqedaBinaria(int vec[],int izq,int der,int x){
	if(izq<der){
		int i=(izq+der)/2;
		if(vec[izq]==x)
		    return izq;
		else if(vec[der]==x)
		    return der;
		else if(vec[i]==x)
		    return i;
		else if(x>vec[i])
		    return  busqedaBinaria(vec,i+1,der-1,x);
		else
		    return  busqedaBinaria(vec,izq+1,i-1,x);	
	}
	return -1;
}

int main(void){
	int vector[]={0,1,2,2,3,4,5,5,6,7,8,9,10,11,13,14,18,23,45,56,78,79,80,91,94,95,97,100,106};
	int n=sizeof(vector)/sizeof(int);
	int x= busqedaBinaria(vector,0,n-1,80);
	if(x!=-1)
	    printf("esta en la posicion %d",x);
	else
	    printf("no esta en el vector");
	    
}
