#include <stdio.h> 
#include <time.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <pthread.h>

#define ITERACOES 2000000000

//pthread_mutex_t MeuSemaforo = PTHREAD_MUTEX_INITIALIZER;
//no fim usei só as variaveis globais de forma local
//se utiliza-se o Mutex rodaria uma thread de cada vez e nao
//iria acontecer a paralelizacao

/*	
    unsigned int ex;
    int i;
    int numero;
    int prox_numero;
    
    se as variaveis ficarem aqui globais as 4 threads irao comparilhar e corromper os calculos
*/  

void *criaArq1(void *param) {

//  pthread_mutex_lock(&MeuSemaforo);

    // =========================================================
    //   CRIACAO DO ARQUIVO 01
    // ========================================================= 

    unsigned int ex;
    int i;
    int numero;
    int prox_numero;

    printf("Gerando o Arquivo 01...\n");

    FILE *txt = fopen("Arquivo01.txt", "w");

    if (txt == NULL)
    {
        perror("Erro ao abrir Arquivo01.txt");
        //return 1;
        //Como as funções das threads foram declaradas com o tipo void * (ponteiro), elas não podem retornar o número inteiro 1 caso dê erro ao abrir o arquivo de texto
	return NULL;
    }

    ex = (unsigned int)time(NULL);
    i = 0;
    while (i < ITERACOES)
    {
       numero= rand_r(&ex) % ITERACOES;
   	   prox_numero= rand_r(&ex) % ITERACOES;
   		
        if ((numero - 1  == prox_numero + 1) &&
            (numero >= 1) && (numero <= 999))

        {
            fprintf(txt, "%d\n", numero);
        }

        ++i;
    }

    fclose(txt);


//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}

void *criaArq2(void *param) {

    unsigned int ex;
    int i;
    int numero;
    int prox_numero;

//  pthread_mutex_lock(&MeuSemaforo);

   // =========================================================
    //   CRIACAO DO ARQUIVO 02
    // ========================================================= 

    printf("Gerando o Arquivo 02...\n");

    FILE *txt2 = fopen("Arquivo02.txt", "w");

    if (txt2 == NULL)
    {
        perror("Erro ao abrir Arquivo02.txt");
       //return 1;
        //Como as funções das threads foram declaradas com o tipo void * (ponteiro), elas não podem retornar o número inteiro 1 caso dê erro ao abrir o arquivo de texto
	return NULL;
    }

    ex = (unsigned int)time(NULL) + 2;

    i = 0;

    while (i < ITERACOES)
    {
       numero= rand_r(&ex) % ITERACOES;
   	   prox_numero= rand_r(&ex) % ITERACOES;
   		
        if ((numero == prox_numero + 2) &&
           	(numero >= 1000) && (numero <= 1999))
        {
            fprintf(txt2, "%d\n", numero);
        }

        ++i;
    }

    fclose(txt2);

//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}

void *criaArq3(void *param) {
    unsigned int ex;
    int i;
    int numero;
    int prox_numero;
//  pthread_mutex_lock(&MeuSemaforo);

    // =========================================================
    //   CRIACAO DO ARQUIVO 03
    // ========================================================= 

    printf("Gerando o Arquivo 03...\n");

    FILE *txt3 = fopen("Arquivo03.txt", "w");

    if (txt3 == NULL)
    {
        perror("Erro ao abrir Arquivo03.txt");
       //return 1;
        //Como as funções das threads foram declaradas com o tipo void * (ponteiro), elas não podem retornar o número inteiro 1 caso dê erro ao abrir o arquivo de texto
	return NULL;
    }

    ex = (unsigned int)time(NULL) + 3;

    i = 0;

    while (i < ITERACOES)
    {
    	numero = rand_r(&ex) % ITERACOES;

       	prox_numero= rand_r(&ex) % ITERACOES;
   		
        if ((numero == prox_numero + 3) &&
        	(numero >= 3000) && (numero <= 3999))
        {
            fprintf(txt3, "%d\n", numero);
        }

        ++i;
    }

    fclose(txt3);

//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}

void *criaArq4(void *param) {
    unsigned int ex;
    int i;
    int numero;
    int prox_numero;

//  pthread_mutex_lock(&MeuSemaforo);

    // =========================================================
    //   CRIACAO DO ARQUIVO 04
    // ========================================================= 

    printf("Gerando o Arquivo 04...\n");

    FILE *txt4 = fopen("Arquivo04.txt", "w");

    if (txt4 == NULL)
    {
        perror("Erro ao abrir Arquivo04.txt");
       //return 1;
        //Como as funções das threads foram declaradas com o tipo void * (ponteiro), elas não podem retornar o número inteiro 1 caso dê erro ao abrir o arquivo de texto
	return NULL;
    }

    ex = (unsigned int)time(NULL) + 4;

    i = 0;

    while (i < ITERACOES)
    {
        numero = rand_r(&ex) % ITERACOES;
     	prox_numero= rand_r(&ex) % ITERACOES;
   		
        if ((numero - 4  == prox_numero) &&
           	(numero >= 4000) && (numero <= 4999))

        {
		    fprintf(txt4, "%d\n", numero);
        }

        ++i;
    }

    fclose(txt4);

//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}

int main(void)
{

  pthread_t tid1, tid2, tid3, tid4;
  pthread_create(&tid1, NULL, criaArq1, NULL);
  pthread_create(&tid2, NULL, criaArq2, NULL);
  pthread_create(&tid3, NULL, criaArq3, NULL);
  pthread_create(&tid4, NULL, criaArq4, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);
  pthread_join(tid4, NULL);
  
    printf("\n========================================\n");
    printf("Os 4 arquivos foram gerados.\n");
    printf("========================================\n");
    return 0;
}

