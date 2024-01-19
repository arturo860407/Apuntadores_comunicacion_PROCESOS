#include <stdio.h>
#include <unistd.h>

int suma(int *v)
{
	int suma=0,i;
	for(i=0;i<5;i++)
		suma+= *(v+i);
	return suma;
}

int main(int argc, char *argv[])
{
	int vector[10]={10,20,30,40,50,60,70,80,90,100};
	int hijo,estado,fd[2];	
	int *punt=NULL,suma2=0,suma1=0,i;
	
	pipe(fd);
	hijo=fork();
	if (hijo==0){
		
		punt=&vector[0];
		suma2=suma(punt);
		
		 /* Cierra la lectura */
                close(fd[0]);

                /* Escribe el dato por la tuberia*/
                write(fd[1], &suma2, sizeof(suma2));
		printf("Hijo(%d) mandó el valor: %d\n", getpid(), suma2);
               
		
		
	}
	else{
		punt=&vector[5]; 
		suma2=suma(punt);
		wait(&estado);
		/* Cierro la escritura*/
                close(fd[1]);

                /* Lee el dato por la tuberia */

		read(fd[0], &suma1, sizeof(suma1));
        		printf("Papá(%d) recibio el valor: %d\n", getpid(), suma1);

       		printf ("Vector: ");
		for(i=0;i<10;i++)
			printf("%d ",*(vector+i));
                printf("\nLa suma es del hijo es %d y la del padre es %d, suma TOTAL: %d\n", suma1,suma2,suma1+suma2);
		
		
	}
	return 1;
}
