
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>



/*
*     ordenamiento por merge Sort
*
*
*
*
*/
void mezcla(int vec[],int izq,int der,int med){
    int mez[der-izq];
    int i=izq,j=med,k=0;
    while(i<med&&j<der){
    	if(vec[i]<vec[j])
    	    mez[k++]=vec[i++];
    	else
    	    mez[k++]=vec[j++];
	}
	while(i<med)
	    mez[k++]=vec[i++];
	while(j<der)
	    mez[k++]=vec[j++];
	for(i=izq,j=0;j<k;i++,j++) 
	    vec[i]=mez[j];	
}



//solo funciona el 1
void mergeSort1(int vec[],int izq,int der){
	if(izq+1==der){
		if(vec[der]<vec[izq]){
			int aux=vec[der];
			vec[der]=vec[izq];
			vec[izq]=aux;
		}   
	}else{
		int med=(izq+der)/2;
		mergeSort1(vec,izq,med);
		mergeSort1(vec,med,der);
		mezcla(vec,izq,der,med);
	}
}
void mergeSort2(int vec[],int izq,int der){
	if(izq<der){
		int med=(izq+der)/2;
		mergeSort2(vec,izq,med);
		mergeSort2(vec,med+1,der);
		mezcla(vec,izq,der,med);
	}
}


/*
*
*    ordenamineto por borbuja
*
*/
void ordenamientoBorbuja(int vec[],int n){
	bool ordenado=false;
	int aux;
	while(!ordenado){
		ordenado=true;
	    for(int i=0;i<n-1;i++){
	    	if(vec[i]>vec[i+1]){
	    		ordenado=false;
	    		aux=vec[i];
	    		vec[i]=vec[i+1];
	    		vec[i+1]=aux;
			}
		}
	}
}


/*
*
*   ordenamineto por intercambio
*
*/
void ordenaminetoIntercambio(int vec[],int n){
	int aux;//for(int i=0;i<n;i++)
	for(int j=0;j<n-1;j++)
        for(int k=j+1;k<n;k++)
	    	if(vec[j]>vec[k]){
	       		aux=vec[j];
	       		vec[j]=vec[k];
	       		vec[k]=aux;
			}			
}




/*
*
*
*     ordenamineto por quiq Sort
*
*
*/
void intercambiar(int vec[],int i,int j){
	int aux=vec[i];
	vec[i]=vec[j];
	vec[j]=aux; 
}

int nIndice(int vec[],int izq,int der){
	if(izq==der)
	    return izq;
	int med=(izq+der)/2;
	if((vec[med]>vec[izq] && vec[med]<vec[der-1]) || (vec[med]>vec[der-1] && vec[med]<vec[izq]))
	    return med;
	else if((vec[izq]>vec[med] && vec[izq]<vec[der-1]) || (vec[izq]>vec[der-1] && vec[izq]<vec[med]))
	    return izq;
	else if((vec[der-1]>vec[med] && vec[der-1]<vec[izq]) || (vec[der-1]>vec[izq] && vec[der-1]<vec[med]))
	    return der-1;
	else{
		printf("returnando med XD\n");
	    return med;
    }
}


int pivote(int vec[],int izq,int der){
	printf("---------------------------------------------------------------------------------\n\n");
	int k=0,indice=nIndice(vec,izq,der);
	printf("pivote: %d\n",vec[indice]);
	for(int i=izq;i<der;i++)
	    if(vec[i]<=vec[indice])
	        k++;
	k=k+izq-1;
	intercambiar(vec,k,indice);
	int i=izq,j=der-1;
	while(i<k && j>k){
		if(vec[i]>vec[k] && vec[j]<=vec[k]){
			intercambiar(vec,i,j);
			j--;
			i++;
		}else if(vec[i]>vec[k] && vec[j]>vec[k])
		    j--;
		else if(vec[j]<vec[k] && vec[i]<=vec[k])
		    i++;
		else{
			i++;
			j--;
		}
	}
	for(int i=izq;i<der;i++)
	    printf("%d\t",vec[i]);
	printf("\n\n\n");
	getchar();
	return k;
}


void quiqSort(int vec[],int izq,int der){
	if(izq<der){
		int med=pivote(vec,izq,der);
		quiqSort(vec,izq,med);
		quiqSort(vec,med+1,der);
	}
}



/*
*
*   arbol Binario de busqueda
*    
*    implementacion con apuntadores
*
*/

typedef struct arbol{
	int valor;
	struct arbol *hizq,*hder;
}Arbol;

void crearArbol(Arbol **raiz){
	*raiz=NULL;
}

bool esHoja(Arbol *nodo){
	return (nodo->hder==NULL && nodo->hizq==NULL);
}

bool arbolVacio(Arbol **nodo){
	return *nodo==NULL;
}

int alturaArbol(Arbol *raiz){
	if(esHoja(raiz)){
		return 1;
	}else{
		int hder=alturaArbol(raiz->hder);
		int hizq=alturaArbol(raiz->hizq);
		if(hder>hizq)
		    return 1+hder;
		else
		    return 1+hizq;
	}
}

void insertarNodo(Arbol **raiz,int x){
	if(arbolVacio(raiz)){
		Arbol *p;
		p=(Arbol*)malloc(sizeof(Arbol));
		p->hder=NULL;
		p->hizq=NULL;
		p->valor=x;
		*raiz=p;
		
	}
}



int main(void){
	int vec[]={90,87,34,12,-98,43,65,89,12,65,89,23,6,34,-6,0,12,565,2,67,76,1,67,-8,34,78,9,45};
	int n=sizeof(vec)/sizeof(int);
/*	for(int i=0;i<n;i++)
	    printf("%d\t",vec[i]);
	printf("\n\nn:%d\n\n",n);
	printf("\n\ndespues de mergeSort\n\n");
	//int k=n;
	mergeSort1(vec,0,n);
//	printf("\nn:%d  k:%d\n",n,k);
	for(int i=0;i<n;i++)
	    printf("%d\t",vec[i]);  
	  printf("antes %d:\n\n",n);  
    quiqSort(vec,0,n);
    printf("\nfuera!!!!!!!!!!!\n\n");
    for(int i=0;i<n;i++)
	    printf("%d\t",vec[i]);  */

    
	
	return 0;  
}




