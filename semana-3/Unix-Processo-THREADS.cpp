#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

struct valor{
   int lacos;
   int id;
};

void *processa(void *argumento){
   struct valor *v = (struct valor *) argumento;
   int i = 0; 
   while (i < v->lacos)
   {
   	i++;
	sleep(1);
   }
   printf("  Eu sou a thread %d. Executei %d lacos antes de finalizar\n",v->id,v->lacos);
   pthread_exit(NULL);
}

int main(){

   pthread_t programas[10];
   int execute,i;
   struct valor *v;
   
   srand(time(NULL));
   
   for (i=0;i<2;i++){
      v = (struct valor *) malloc(sizeof(struct valor *));
      v->lacos = (200) ;
      v->id = i;
     
 	printf("Criando a thread <%d> com <%d> lacos\n",i,v->lacos);
      	execute = pthread_create(&programas[i],NULL,processa,(void *)v);
   }
   pthread_exit(NULL);
}
