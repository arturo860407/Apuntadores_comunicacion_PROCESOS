#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 0



char * izquierda(char * cad1, char * cad2)
{
	int cad,i;
	do{
	printf("La cadena origen es: %s \n¿Cuánto caracteres quieres copiar a la cadena destino (izq a der): ",cad1);
	scanf("%d",&cad);
	}while(cad<=0 || cad > strlen(cad1));
	cad2= (char*) malloc(sizeof(char)*cad);
	if (cad2==NULL)
		printf("Error en el malloc\n");
	else
	{
		for (i=0;i<cad;i++)
			*(cad2+i)=*(cad1+i);
		*(cad2+i)='\0';
	}
	
	return cad2;
}
char * derecha(char * cad1, char * cad2)
{
	int cad,i,j;
	do{
	printf("La cadena origen es: %s \n¿Cuánto caracteres quieres copiar a la cadena destino(der a izq): ",cad1);
	scanf("%d",&cad);
	}while(cad<=0 || cad > strlen(cad1));
	cad2= (char*) malloc(sizeof(char)*cad);
	if (cad2==NULL)
		printf("Error en el malloc\n");
	else
	{
		j=strlen(cad1)-1;
		for (i=0;i<cad;i++,j--)
			*(cad2+i)=*(cad1+j);
		*(cad2+i)='\0';
	}
	
	return cad2;
}

void * menu(int opciones, char **arg)
{
	int i=0,opc;
	void *ptrFuncion = NULL;
	do{
		for (i=0;i<opciones;i++)
			printf("(%d).- %s\n", i+1,*(arg+i));
		printf("\n Escoge una opcion de 1 a %d: ",i); scanf("%d",&opc);
	}while(opc<0||opc>opciones);

	switch(opc) {

   		case 1  :
      			ptrFuncion = izquierda;
      		        break; 
	
   		case 2  :
      			ptrFuncion = derecha;
      			break; 
  
  			 
   			default : 
   			ptrFuncion = NULL;
	}
	return ptrFuncion;
}

void ambas(char* (*func)(char*,char*), char* (*func2)(char*,char*))
{
	char *str=NULL;
	printf("Resultado de izquierda: %s\n", func("CADENAIZQUIERDA",str));

	printf("Resultado de derecha: %s\n", func2("CADENADERECHA",str));
}

int main(int argv, char**arg) {
	char * (*ptrFuncion) (char *,char *);
  	char *opciones[]={"Funcion de Izquierda","Funcion de Derecha"};
	char *str=NULL;
	ptrFuncion=menu(2,opciones);
	
	if (ptrFuncion==NULL)
		printf("\n Error en la dirección");
	else
	{
		printf("Resultado: %s\n", ptrFuncion("Advanced programming",str));
	}
	if(true)
	{
		char* (* izq) (char*,char*);
		char* (* der) (char*,char*);
  		izq = izquierda; der= derecha;
		ambas(izq,der);
	}
  return(0);
}

