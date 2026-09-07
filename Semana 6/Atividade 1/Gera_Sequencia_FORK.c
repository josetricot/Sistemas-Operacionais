#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
#include <unistd.h> 
#include <pthread.h>
#include <sys/types.h>

#define ITERACOES 2000000000

int main(void)
{
    unsigned int ex;
    int i;
    int numero;
    int prox_numero;
    pid_t pid1, pid2, pid3;
    

    // =========================================================
    //   CRIACAO DO ARQUIVO 01
    // ========================================================= 

    if ((pid1 = fork()) < 0)
    {
        perror("Erro na Criação do fork1");
        exit(1);
    }

    if (pid1 == 0)
    {
        //O código no processo filho

    printf("Gerando o Arquivo 01...\n");

    FILE *txt = fopen("Arquivo01.txt", "w");

    if (txt == NULL)
    {
        perror("Erro ao abrir Arquivo01.txt");
        return 1;
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
    return 0;
    }

    // =========================================================
    //   CRIACAO DO ARQUIVO 02
    // ========================================================= 
if ((pid2 = fork()) < 0) {
        perror("Erro na Criacao do fork1");
        exit(1);
    }
	    if (pid2 == 0)
    {
        //O código no processo filho

    printf("Gerando o Arquivo 02...\n");

    FILE *txt2 = fopen("Arquivo02.txt", "w");

    if (txt2 == NULL)
    {
        perror("Erro ao abrir Arquivo02.txt");
        return 1;
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
    return 0;
    }

    // =========================================================
    //   CRIACAO DO ARQUIVO 03
    // ========================================================= 
if ((pid3 = fork()) < 0) {
        perror("Erro na Criacao do fork1");
        exit(1);
    }
    if (pid3 == 0)
    {
        //O código no processo filho

    printf("Gerando o Arquivo 03...\n");

    FILE *txt3 = fopen("Arquivo03.txt", "w");

    if (txt3 == NULL)
    {
        perror("Erro ao abrir Arquivo03.txt");
        return 1;
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
    return 0;
}
    // =========================================================
    //   CRIACAO DO ARQUIVO 04
    // ========================================================= 

    else
    {
        //O código no processo pai

    printf("Gerando o Arquivo 04...\n");

    FILE *txt4 = fopen("Arquivo04.txt", "w");

    if (txt4 == NULL)
    {
        perror("Erro ao abrir Arquivo04.txt");
        return 1;
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
    //return 0; nao pode existir para que apareça parte final
    
    }

    printf("\n========================================\n");
    printf("Os 4 arquivos foram gerados.\n");
    printf("========================================\n");
    return 0;
}

