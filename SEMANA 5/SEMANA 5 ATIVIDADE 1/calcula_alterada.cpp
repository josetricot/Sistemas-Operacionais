#include <stdio.h>
#include <math.h>
#include <pthread.h> //incluido

double resultado1 = 0;
double resultado2 = 0;


/*void  soma_massiva(long long limite) {
    double soma = 0.0;
    for (long long i = 1; i <= limite; i++) {
        soma += sqrt(i) / (i + 1.0); // operação mais pesada que apenas somar
    }
    resultado1 =  soma;
}
*/

/* exemplo codigos anteriores
void *soma_massica(void *argumento){
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
*/

void *soma_massiva(void *argumento){
   long long limite = (long long) argumento;
   
    double soma = 0.0;
    for (long long i = 1; i <= limite; i++) {
        soma += sqrt(i) / (i + 1.0); // operação mais pesada que apenas somar
    }
    resultado1 =  soma;
    pthread_exit(NULL); //incluida pois as funcoes agora sao void
}

/*void aproximar_pi(long long iteracoes) {
    double pi = 0.0;
    for (long long i = 0; i < iteracoes; i++) {
        double termo;
			if (i % 2 == 0) {
    				termo = 1.0 / (2.0 * i + 1.0);
				} else {
    				termo = -1.0 / (2.0 * i + 1.0);
				}
        pi += termo;
    }
    resultado2 =  pi * 4.0;
}
*/
void *aproximar_pi(void *argumento){
   long long iteracoes = (long long) argumento;
       double pi = 0.0;
    for (long long i = 0; i < iteracoes; i++) {
        double termo;
			if (i % 2 == 0) {
    				termo = 1.0 / (2.0 * i + 1.0);
				} else {
    				termo = -1.0 / (2.0 * i + 1.0);
				}
        pi += termo;
    }
    resultado2 =  pi * 4.0;
    pthread_exit(NULL); //incluida pois as funcoes agora sao void
}

int main() {

	long long n1 = 5000000000; 
	long long n2 = 10000000000; 

	pthread_t f1, f2;
	
    printf("Iniciando o Procesos de calculos massivos Sequencial...\n");

    printf("Calculos Soma massivos ...\n");
	
	//soma_massiva(n1);
	//pthread_create(&f1,NULL,soma_massiva, NULL);
	//pthread_create(&f1,NULL,soma_massiva, n1);
	//funcao espera receber o valor escondido
	pthread_create(&f1, NULL, soma_massiva, (void *)n1);
	//passa o n1 fazendo um cast direto para ponteiro genérico
	
	printf("Calculos aproximação do Pi ...\n");
	
	//aproximar_pi(n2);
	pthread_create(&f2, NULL, aproximar_pi, (void *)n2);
	
	pthread_join(f1, NULL);
	pthread_join(f2, NULL);
	
    printf("Resultado da soma massiva: %.6f\n", resultado1);

    printf("Aproximação de Pi: %.12f\n", resultado2);

    printf("Calculos finalizados.\n");

    return 0;
}
