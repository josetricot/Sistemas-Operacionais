#include <stdio.h>  
#include <pthread.h>  
#include <unistd.h> 
#include <stdlib.h>
#include <time.h>

void *contar(void *th){
   	int b=0;	 
	printf("\n++ Executando o Thread Nro %d \n", th);

			//Pega o Id da Thread para o SRAND * 100
			int id = *((int*)(&th))*100;

			//Definindo a Semente Inicial do Gerador Aleatório
			srand(((unsigned) time(NULL)) + id) ; 
			  for (b=0; b< 20000000; b++)
			{
				//Geração de Numero aleatório entre 1 até 100.000
				float c = rand_r(&id) ;
				
				//Para mostrar os Valores Gerados (Pode misturar as Threads). 
				//printf ("\n Thread Nro %d gerou %.0f",th,  c); 	
			}
	printf("\n>>>>> Thread %d Finalizou agora 20.000.000 de operacoes\n", th);
   	pthread_exit(NULL);
}

int main ( ) 
{   
	int a=0, b=0;
	time_t now;
	const struct tm *tm;
	now = time ( NULL );
    tm = localtime ( &now );
	
	//Controlador das Threads
	pthread_t programas[10];
	
	printf("Inciando do programa com Threads. Contanto 10 x ate 20.000.000 \n");

	for (a = 0; a<10; a++)
		{
			printf("\n>> Criando a thread Nro: %d \n", a+1);
			pthread_create(&programas[a],NULL,contar,(void *)a);
		}
	pthread_exit(NULL);
	return 0;   
}
