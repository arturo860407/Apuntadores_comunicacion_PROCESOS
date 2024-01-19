#include <stdio.h>
#include <stdlib.h>
#include "funcionesCadenas.h"

int main(int argc, char **argv)
{
   char *str;
   int i;

   /* Initial memory allocation */
   str = malloc(sizeof(char)*40);
   
   printf("Longitud de la cadenas = %d\n", cadlen(argv[1]));
   printf("Cadena copiar de la cadenas = %s:%s \n", cadcpy(str,argv[1]),str);	
   printf("Cadena concatenar de la cadenas = %s \n", cadcat(str,"Rendón"));
   printf("Cadena comparar %s con %s  de la cadenas = %d \n",argv[1],argv[2],cadcmp(argv[1],argv[2]));
   if(argc>2)
   {
   	printf("Cadena comparar %s con %s de la cadenas = %d \n", argv[1],argv[2],cadcompmayusculas(argv[1],argv[2]));
	
   }

   free(str);
   
   return 0;
}
