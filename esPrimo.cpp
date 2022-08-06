#include <stdio.h>
#include <stdlib.h>

bool primo(float x){
	printf("aqui 1\n");
	int y=x;
	for(float i=0;i<(x/2)+1;i++){
		if(x%i==0)
		    return false;
    }
	return true;
}


int main(void){
    if(primo(11))
        printf("es primo");
	else 
	    printf("no es primo");  
	
	
	return 0;
}
