#include <stdio.h>

#include <string.h>



int tam(char con[],int t){
	if (con[t]==NULL){
		return t-1;
	}else{
		t++;
		return tam(con,t);
	}
	
}

bool unCarecter(char con[],char x,int posicion){
	if(con[posicion]==x){
		return true;
	}else if(posicion==tam(con,0)){
		return false;
	}else{
		return unCarecter(con,x,posicion);
	}
}






int main(){
	char con1[]="qwertyuioplkjhgfdsamnbvcxz1234567890 ";
	char con2[]="mnbvcxzñlkjhgfdsapoiuytrewq0987654";
    con1[strlen(con1)+1]=NULL;
    con2[strlen(con2)+1]=NULL;	
	printf("%d",unCarecter(con1,'t',0));
}
