#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#define max 100


//-----------------------------------------------   funciones primera parte  --------------------------------------------------

//>>>>>>>>>>>>>>>>>>>> funcion para escribir una matriz
void escribirmatriz(int matriz[][max])
{
    int rep,rep2; //rep, rep2 hacen de i y j respectivamente, 
	for (rep=0;rep<4;rep++)
	{
	   for (rep2=0;rep2<4;rep2++)
	   {
	       printf(" %d",matriz[rep][rep2]);   	
	   }
	   printf("\n");
	}	
}

//>>>>>>>>>>>>>>>>>  funcion leer numero entre 1 y 4  <<<<<<<<<<<<<<<<<<<<<<<
int leerposicion()
{
    int x;
	scanf("%d",&x);
	while (x<0 || x>4)
	{
		printf("el numero debe ser entre 1 y 4\n");
		scanf("%d",&x);
	}
	return x;
}


//>>>>>>>>>>>>>>>>>>    funcion para no permitir leer misma posicion en un intento
int leernuevaposicion(int b)
{
	int x,y;
	y=b;
	y++;
	scanf("%d",&x);
	x--;
	while ((x<0)||(x>4)||(x==b))
	{
	printf("el numero debe estar entre 1 y 4, debe ser diferente de %d\n", y);
	scanf("%d",&x);
	x--;	
	}
	return x;
}


//>>>>>>>>>>>>>>>>> funcion crear matriz en ceros
void matrizceros(int matriz[][max])
{
	int rep,rep2;
	for (rep=0;rep<4;rep++)
	{
		for (rep2=0;rep2<4;rep2++)
		{
			matriz[rep][rep2]=0;
		}
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    funcion crear matriz 
void matrizaleatoria(int matriz[][max])
{
	int rep,rep2,a1,a2,a3,a4,a5,a6,a7,a8,x,z,band;
	//>>>>>>>>>>>>>>>>>>>>>>>>    a1,a2,a3...  representan los numeros que debe tener la matriz
	//>>>>>>>>>>>>>>>>>>>>>>>     x es variable logica
	x=0;
	z=0;
    band=0;
    while (band==0)
    {
        z=0;
        srand(time(NULL));//reinicia la semilla de aleatoriedad 
		x=0;       
    	while (x==0)
    	{	
    	    z++;
    	   //printf("%d \n",z);
    	    a1=0;
	        a2=0;
    	    a3=0;
    	    a4=0;
    	    a5=0;
	        a6=0;
	        a7=0;
	        a8=0;
    	    for (rep=0;rep<4;rep++)
         	    {
	        	for (rep2=0;rep2<4;rep2++)
		        {
	    		    matriz[rep][rep2]=1+(rand()%8);
		     	    if (matriz[rep][rep2]==1)
			        {
			        	a1++;
			    	}
			    	if (matriz[rep][rep2]==2)
		     	    {
			        	a2++;
			    	}
		  	    	if (matriz[rep][rep2]==3)
		    	    {
		    	    	a3++;
			    	}
		    		if (matriz[rep][rep2]==4)
			        {
			        	a4++;
			    	}
		    		if (matriz[rep][rep2]==5)
			        {
			        	a5++;
			    	}
	    			if (matriz[rep][rep2]==6)
		    	    {
			        	a6++;
	     			}
		    		if (matriz[rep][rep2]==7)
			        {
			        	a7++;
		    		}
			    	if (matriz[rep][rep2]==8)
			        {
		 	        	a8++;
		    		}
 	     	   }
        	}
            if (a1==2 && a2==2 && a3==2 && a4==2 && a5==2 && a6==2 && a7==2 && a8==2)
            {
            	x=1;
            	band=-1;
	    	}
	    	
	    	if (z>500000) //tope de intentos de aleatoriedad con pares de numeros de lo contrario se reinicia
	    	{
	    		x=-1;
			}
        }

	}
	
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   funcion tutorial 
void tutorial()
{
	int rep,rep2;
	printf("\n\n    TUTORIAL \n");
	printf("para jugar digita la posicion que deseas destapar, por ejemplo si digitas\n");
	printf("filas: 3\n");
	printf("columnas: 2\n");
	printf("entonces la fila 3 columna 2 mostrara su contenido asi\n\n ");
	for (rep=0;rep<4;rep++)
	{
		for (rep2=0;rep2<4;rep2++)
		{
			if (rep == 2 & rep2 == 1)
			{
				printf("4 ");
			}
			else
			{
			    printf("* ");	
			}
		}
		printf("\n ");
	}
	system("pause");
	system("cls");
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    funcion para imprimir avances del usuario
void avances(int matriz2[][max])
{
	int rep,rep2;
	printf("\n\n");
	for (rep=0;rep<4;rep++)
	{
	    for (rep2=0;rep2<4;rep2++)
	    {
	    	if (matriz2[rep][rep2]==0)
	    	{
	    		printf(" *");
			}
			else 
			{
				printf(" %d",matriz2[rep][rep2]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>   funcion para imprimir una posicon
void imprimirunaposicion(int a,int b,int matriz [][max],int matriz2[][max])
{
	int rep,rep2;
	printf("\n\n");
	for (rep=0;rep<4;rep++)
	{
		for (rep2=0;rep2<4;rep2++)
		{
			if (rep==a & rep2 == b)
			{
				printf(" %d!",matriz[rep][rep2]);
			}
			else
			{
			    if (matriz2[rep][rep2]==0 )
			    {
			    	printf(" *");
				}
				else 
				{
					printf(" %d",matriz2[rep][rep2]);
				}
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    funcion para escribir 2 posiciones
void imprimirdosposiciones(int a,int b,int c,int d,int matriz[][max],int matriz2[][max])
{
	int rep,rep2;
	printf("\n\n");
	for (rep=0;rep<4;rep++)
	{
		for (rep2=0;rep2<4;rep2++)
		{
			if ((rep==a & rep2 == b)||(rep==c & rep2==d))
			{
				printf(" %d!",matriz[rep][rep2]);
			}
			else
			{
				if (matriz2[rep][rep2]==0)
				{
					printf(" *");
				}
				else 
				{
					printf(" %d",matriz2[rep][rep2]);
				}
			}
		}
		printf("\n");
	}
	printf("\n\n\n");
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     funcion para saber si el usuario repitio posicion    
int posicionvalida(int a,int b,int matriz2[][max])
{
	int x; // x variable logica
	if (matriz2[a][b]==0)
	{
		x=1;// posicion valida
	}
	else
	{
	    x=0;//posicion no valida	
	}
	return x;
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>      funcion jugar concentrese         <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void jugarconcentrese(int matriz[][max])
{
	int matriz2[4][max];// esta matriz permite guardar los avances del ususario
	matrizceros(matriz2);
	int band,band2,cont,a,b,c,d,x; // a,b,c y d son variables de posicion     x variable logica
	band=5; // numero de oportunidades
	printf("\n\n");
	tutorial();
	//printf("entrando al while\n"); //----------------------------------   control
	cont=0;
	while (band > 0) // para controlar numero de oportunidades
	{
		
	//	printf("entrando segundo while");//------------------------------  control
		band2=1;
		while (band2>1); // para controlar errores del usuario
		{
		//	printf("dentro del segundo while");//--------------------------- control
			printf("debes encontrar todas las parejas\n\n");
	    	printf("en esta matriz que posicion deseas destapar");
	    	avances(matriz2);
	    	printf("filas: ");
	    	a=leerposicion();
     		printf("\ncolumnas: ");
    		b=leerposicion();
      		a--;
    		b--;
	    	//hay que evaluar si el usuario repitio posicion
		    x = posicionvalida(a,b,matriz2);
		    if (x==0)
		    {
		    	printf("\nesta posicion ya habia sido destapada\n\n");
		    	band--;
		    	system("pause");
		    	system("cls");
		    	band2=-1;	
			}
		    imprimirunaposicion(a,b,matriz,matriz2);
    		printf("\n\nbien, ahora encuentra su pareja\n\n");
    		printf("fila: ");
	    	c=leerposicion();
	    	c--;
	    	// si el usuario digita lamisma fila de la posicion anterior no se debe permitir digitar la misma columna
	    	printf("columna: ");
	    	if (a==c)
	    	{
		    	d=leernuevaposicion(b);
     		}
	    	else
    		{
	    		d=leerposicion();
	    		d--;
		    }
		    // hay que saber si el usuario digito una posicion valida
		    x=posicionvalida(c,d,matriz2);
		    if (x==0)
		    {
		       printf("\n\nla posicion no es valida\n\n\n");	
		       band--;
		       system ("pause");
		       system("cls");
		       band2=-1;
			}
			//imprimir segunda posicion
			imprimirdosposiciones(a,b,c,d,matriz,matriz2);
			// son iguales las posiciones
			if (matriz[a][b]==matriz[c][d])
			{
				printf("!!!!!!felicidades¡¡¡¡¡¡¡  encontraste una pareja \n\n");
				matriz2[a][b]=matriz[a][b];
				matriz2[c][d]=matriz[c][d];
				system("pause");
				cont++;
				system("cls");
				band2=-1;
			}
			else
			{
				printf("\nfallaste\n\n\n");
				band--;				
				system("pause");
				system("cls");
                band2=-1;
			}
		}
		if (cont==8)
		{
			printf("\n\n!!!!!!  felicidades ¡¡¡¡¡¡¡¡¡  has terminado todo el juego");
			band = -1;
			band2=-2;
		}
	}
	printf("\n\nel juego ha terminado\n");
	system("pause");
	system("cls");
}
//-------------------------------------------------------  funciones para la segunda parte -------------------------------------



// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>      funcion para sumar los vordes de una posicion  <<<<<<<<<<<<<<<<<<<<<<<<<
void sumarvordes(float m[][max],float m1[][max],int n,int n1) 
{
	int i,j; //se cambian por comodidad pero no se quiere arriesgar el codigo ya realizado, dentro de la funcion no afecta.
	for (i=0;i<=n-1;i++)
    {
	    for (j=0;j<=n1-1;j++)
	                {
	                    //condicion esquina superior izquierda
	                    if (i==0 && j==0)
	                    { 
	                        m1[i][j]=(m[i][j]+m[i][j+1]+m[i+1][j+1]+m[i+1][j])/5;
	                        if (m1[i][j]>10)
	                        {
	                        	m1[i][j]=1;
	                        }
                            else
	                        {
	                            m1[i][j]=0;
	                        }
	                    }
	                    else
	                    {
	                        //condicion  borde superior
	                        if (i==0 && j!=n1-1&& j!=0)
	                        {
	                            m1[i][j]=(m[i][j]+m[i][j-1]+m[i+1][j-1]+m[i+1][j]+m[i+1][j+1]+m[i][j+1])/5;
	                            if (m1[i][j]>10)
	                            {
	                               m1[i][j]=1;
	                            }
                                else
                                {
	                                m1[i][j]=0;
	                            }
	                        }
	                        else
	                        {
	                            //condicion esquina superior derecha 
	                            if (i==0 && j==n1-1)
	                            {
	                                m1[i][j]=(m[i][j]+m[i][j-1]+m[i+1][j-1]+m[i+1][j])/5;
	                                if (m1[i][j]>10)
	                                {
	                                    m1[i][j]=1;
	                                }
	                                else
	                                {
	                                    m1[i][j]=0;
	                                }
	                            }
	                            else
	                            {
                                    //condicion borde derecho
	                                if(j==n1-1 && i!=0 && i!=n-1)
	                                {
	                                    m1[i][j]=(m[i][j]+m[i-1][j]+m[i-1][j-1]+m[i][j-1]+m[i+1][j-1]+m[i+1][j])/5;
	                                    if (m1[i][j]>10)
	                                    {
	                                        m1[i][j]=1;
	                                    }
	                                    else
	                                    {
	                                        m1[i][j]=0;
	                                    }
	                                }
	                                else
                                    {
	                                    //condicion esquina inferior derecha 
	                                    if (i==n-1 && j==n1-1)
	                                    {
	                                        m1[i][j]=(m[i][j]+m[i-1][j]+m[i-1][j-1]+m[i][j-1])/5;
	                                        if (m1[i][j]>10)
	                                        {
	                                            m1[i][j]=1;
	                                        }
	                                        else
	                                        {
	                                            m1[i][j]=0;
	                                        }
	                                    }
	                                    else
	                                    {
	                                        //condicion borde inferior
	                                        if (i==n-1 && j!=0 && j!=n1-1)
		                                    {
	                                            m1[i][j]=(m[i][j]+m[i][j-1]+m[i-1][j-1]+m[i-1][j]+m[i-1][j+1]+m[i][j+1])/5;
		                                        if (m1[i][j]>10)
		                                        {
		                                            m1[i][j]=1;
		                                        }
			                                    else
	                                            {
	                                                m1[i][j]=0;
	                                            }
	                                        }
		                                    else
	                                        {
	                                            //condicion esquina inferior izquierda
                                                if (i==n-1 && j==0)
		                                        {
		                                            m1[i][j]=(m[i][j]+m[i][j+1]+m[i-1][j+1]+m[i-1][j])/5;
                                            		//printf("%i\n",m1[i][j]);
                                            		if (m1[i][j]>10)
                                               	    {   
                                                		m1[i][j]=1;
		                                            }
                                            		else
		                                            {
		                                                 m1[i][j]=0;
		                                            }
		                                        }
		                                        else
		                                        {         
											        if (j==0 && i!=0 && i!=n-1)
			                                        {
			                                            //CONDICION borde izquierdo
                                            			m1[i][j]=(m[i][j]+m[i-1][j]+m[i-1][j+1]+m[i][j+1]+m[i+1][j+1]+m[i+1][j])/5;
		                                                if (m1[i][j]>10)
		                                                {
		                                                    m1[i][j]=1;
			                                            }
		                                                else
		                                                {
		                                                    m1[i][j]=0;
		                                                }
		                                            }
		                                            else
		                                                //suma de todas las posiciones dentro de la matriz que no es borde ni esquina
		                                            {
			                                            m1[i][j]=(m[i][j]+m[i-1][j-1]+m[i-1][j]+m[i-1][j+1]+m[i][j-1]+m[i][j+1]+m[i+1][j-1]+m[i+1][j]+m[i+1][j+1])/5;
                                            			if (m1[i][j]>10)
				                                        {
			                                        		m1[i][j]=1;
			                                           }
		                                                else
			                                            {
		                                                    m1[i][j]=0;
			                                            }
		                                            }
	    	                                    }	
	 	                                   }
		                                }
	    	                        }
	                           } 
                        	}			
			            }
		            }		
		        }
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>    funcion para escribir el resultado de las estrellas
void escribircielo(float m[][max],float m1[][max],int n,int n1)
{
	int i,j;
	// imprimir arriba//
	for (i=1;i<=n1;i++)
      	if (i==1)
		{
			printf("   %i ",i);
		}
		else
		{
			 printf("%i ",i);
		}
		if (i==8)
		{
			printf("%i ",8);
		}
		//imprimir asteriscos y espacios 
		for (i=0;i<=n+1;i++)
		{
	     	printf("  \n%i ",i+1);
			for (j=0;j<=n1-1;j++)
			{	
			    if (j<n1-1)
				{
				   if (m1[i][j]==1)
					{
					    printf(" *");
				    }
				    else
				    {
					    printf("  ");
			        }
				}
				if (j==n1-1)
				{
					if (m1[i][j]==1)
					{
					    printf("*");
					    printf(" %i",i);
					}
					else
					{
						printf(" ");
						printf("   %i   ",i+1);					
					}
				}
			} 
		}
    //imprimir numeros de abajo 
	printf("\n");
	for (i=1;i<=n1;i++)
	if (i==1)
	{
		printf("   %i ",i);
	}
	else
	{
		printf("%i ",i);
	}		   	
}

//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><    funcion para leer un numero entre 1 y 10
int men10()
{
	int x;
	printf("Ingrese un numero menor que 10 :\n");
	scanf("%i",&x);
	while (x>10 || x<1)
	{
		printf("\nError -- el entero debe estar en el rango (1-10):");
		scanf("%i",&x);
	}
	return x;
}

// funcion validar dato entre 1 y 20
int num20()
{
	int x;
	scanf("%i",&x);
	while (x<0 || x>20)
	{
		printf("el numero debe estar entre 1 y 20\n");
		scanf("%i",&x);
	}
	return x;
}

// funcion llenar una matriz 
int llema(float m[][max],float m1[][max],int a, int b)
{
	int i,j,x;
	printf("Ingrese los elementos para la matriz\n");
	for (i=0;i<=a-1;i++)
	{
		for (j=0;j<=b-1;j++)
		{
			printf("Ingrese valor para la posicion [%i,%i]: ",i,j);
			x=num20();
			m[i][j]=x;
			m1[i][j]=m[i][j];
		}
	}
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>      proceso principal           <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
main()
{
    int band,band2,x,y,a,b;
    band = 1;
    int matriz[4][max];
    while (band == 1)
    {
        printf("\n\nselecciona el modo de jugo\n");
        printf("1: juego concentrese\n");
        printf("2: identificar estrellas \n");
        printf("3: salir\n");
        scanf("%d",&x);
        switch (x)
        {
    	case 1:
    		system("cls");
    		printf("\nbienvenido a concentrese \n");
    		printf("presiona 1 para iniciar a jugar.\n");
    		printf("\npresiona 2 para volver al menu principal\n");
    		band2=1;
    		while (band2==1)
    		{
    			scanf("%d",&y);
    			switch(y)
    		    {
    			    case 1:
    			    	system("cls");
    			    	matrizaleatoria(matriz);
    			    	printf("\n\n");
    			    	//escribirmatriz(matriz);
    			    	printf("\n\n");
    			        jugarconcentrese(matriz);
    				    band2=0;
    				    break;
    			    case 2:
				         band2=0;
					    break;
				    default:
				        printf("\n digitaste un numero diferenta a 1 o 2");
			    }
			}
			break;
    	case 2:// estrellas
    	{
            system("cls");
            int band2=1,n=6,n1=8,z; //z es para control en el segundo menu
	 		while(band2==1)
	 		{
	 	        printf("Mapa de Estrellas\n");
	 	    	printf("1. Cargar datos por defecto\n");
	     	   	printf("2. Ingresar datos por el usuario\n");
	     		printf("Ingrese una opcion:\n");
	 		    scanf("%i",&z);
				 switch(z)
				{
					case 1:
						{
                      	n=6;
                        n1=8;
	  	            	float m[6][max]={{0,3,4,20,15,0,6,8},{5,13,6,8,2,0,2,3},{2,6,2,2,3,0,10,0},{0,0,4,15,4,1,1,20},{0,0,7,2,6,9,10,4},{5,0,6,10,6,4,8,0}};
	                    float m1[6][max]={{0,3,4,20,15,0,6,8},{5,13,6,8,2,0,2,3},{2,6,2,2,3,0,10,0},{0,0,4,15,4,1,1,20},{0,0,7,2,6,9,10,4},{5,0,6,10,6,4,8,0}};
	            	    sumarvordes(m,m1,n,n1);
            			escribircielo(m,m1,n,n1);
            			printf("\n");
	            		system("pause");
	            		system("cls");
	            		band2=0;
						break;
						}
					case 2:
						{
						
					    printf("\ningrese el valor de las filas: ");
	            	    a=men10();
             			printf("\ningrese el numero de columnas: ");
            			b=men10();
                         float m2[50][max];
                        float m3[50][max];
            			llema(m2,m3,a,b); // funcion para leer la  matriz
	            		system("pause");
            			system("cls");
	            		sumarvordes(m2,m3,a,b);	
	            		escribircielo(m2,m3,a,b);
	            		printf("\n\n");
	            		system("pause");
	            		system("cls");
	             		band2 = -1;
		             	break;
		             	}
					default:
					printf("digitaste un numero diferente a 1 y 2");					   		 	
				}	
			}
			break;
		}	
		case 3:
			{
		    band =0;
		    break;
			}	
    	default:
            printf("\ndigitaste un  numero diferente de 1,2 o 3\n");
        }
	}

}
