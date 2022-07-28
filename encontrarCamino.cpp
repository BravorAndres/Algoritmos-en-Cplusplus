
#include <stdio.h>

bool avanzar(bool laberinto[][100],int camino[][2],int &nx,int &ny,int dnx,int dny,int &nc){
	if(!laberinto[dnx][dny]&& !(dnx==camino[nc][0] && dny==camino[nc][1])){
		nc++;
		camino[nc][0]=dnx;
		camino[nc][1]=dny;
		nx=dnx;
		ny=dny;
		return true;
	}else
	    return false;
}


void encontrarCamino(bool laberinto[][100],int camino[][2],int &fpx,int &fpy,int &x,int &y,int nx,int ny,int nc){
	if(fpx==x && fpy==y){
		bool avanzado;
		//caso mas general
		if(nx!=0 && ny!=0 && nx!=x-1 && ny!=y-1){
			if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
			    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
			else if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
			    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
			else if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
			    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
			else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
			    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
			else{
				printf("\n\nno hay camino");
				return;
			}
			//lateral derecho
		}else if(nx==0){
			//esquina superior
			if(ny==0){
				if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
		            encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
		        else if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
		            encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
		        else{
		        	printf("no hay camino\n\n");
		        	return;
				}
			//	esquina inferior
			}else if(ny==y-1){
				if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
			//centro del lateral
			}else{
				if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
			}
		// lateral izquierdo
		}else if(nx==x-1){
			//esquina superior
		    if(ny==0){
		    	if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
		    	    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
		    	else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
		    	    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
		    	else{
		    		printf("no hay camino\n\n");
		    		return;
				}
				//esquina inferior
			}else if(ny==y-1){
				if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
				//centro del lateral
			}else{
				if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
			}
		// centro del lateral alto	
		}else if(ny==0){
			if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx-1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
		//centro del latera bajo		
		}else if(ny==y-1){
			if(avanzar(laberinto,camino,nx,ny,nx+1,ny,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny+1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else if(avanzar(laberinto,camino,nx,ny,nx,ny-1,nc))
				    encontrarCamino(laberinto,camino,fpx,fpy,x,y,nx,ny,nc);
				else{
					printf("no hay camino\n\n");
					return;
				}
		}
	}
	printf("\n\ncamino encontrado");
}


void imprimirLaberinto(bool laberinto[][100],int x,int y){
	printf("[][][][][][][][]\n");
	for(int i=0;i<x;i++){
	    for(int j=0;j<y;j++){
	    	if(j==0 || j==y-2)
	    	    printf("[]");
	    	if(!laberinto[i][j])
	    		printf("  ");
	    	else
	    	    printf("[]");
		}
		printf("\n");
   }
   printf("[][][][][][][][]\n");
}



int main(void){
	bool mat[100][100]={{1,1,1,0,0,0},{
	                     1,0,0,0,1,0},{
						 0,0,1,1,1,0},{
						 0,0,0,0,1,0},{
						 1,1,1,1,0,0},{
						 1,1,1,0,0,1},{
						 0,0,0,0,1,1}};
	imprimirLaberinto(mat,6,8);					 

	
	return 0;
}
