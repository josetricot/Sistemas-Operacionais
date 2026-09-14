#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid1, pid2, pid3;

    //PROCESSO 1 (Filho 1)
    if ((pid1 = fork()) < 0) { //aqui no (pid1 = fork()) a clonagem é feita, é como se o processo pai recebece pid1=5001 e o filho clonado pid1=0 
        perror("Erro no fork 1"); //como o pid1 = fork() está entre parênteses ele é executado, indepente desse if não se concretizar
        exit(1);
    }
    if (pid1 == 0) { //aqui o pai não entra mas o filho sim e começa a rodar seu laço
        for (int i = 1; i <= 10; i++) {
            printf("[PID: %d] Processo 1 contando: %d\n", getpid(), i);
            sleep(1);
        }
        return 0; //impede que o Filho 1 crie outros clones
    }

	//o filho 1 "morreu" mas o pai segue "vivo"
	
    //PROCESSO 2 (Filho 2)

    if ((pid2 = fork()) < 0) { //a clonagem é feita, é como se o processo pai recebece pid2=5002 e o filho clonado pid2=0 
        perror("Erro no fork 2");
        exit(1);
    }
    if (pid2 == 0) { //aqui o pai não entra mas o filho sim e começa a rodar seu laço
        for (int i = 10; i <= 20; i++) {
            printf("[PID: %d] Processo 2 contando: %d\n", getpid(), i);
            sleep(1);
        }
        return 0;//impede que o Filho 2 crie outros clones
    }

	//o filho 2 "morreu" mas o pai segue "vivo"

    //PROCESSO 3 (Filho 3)
    
    if ((pid3 = fork()) < 0) { //a clonagem é feita, é como se o processo pai recebece pid3=5003 e o filho clonado pid3=0 
        perror("Erro no fork 3");
        exit(1);
    }
    if (pid3 == 0) { //aqui o pai não entra mas o filho sim e começa a rodar seu laço
        for (int i = 20; i <= 30; i++) {
            printf("[PID: %d] Processo 3 contando: %d\n", getpid(), i);
            sleep(1);
        }
        return 0;//impede que o Filho 3 crie outros clones
    }

	//o filho 3 "morreu" mas o pai segue "vivo"

    //PROCESSO 4 (Pai)
    //pai escapa de todos os "if" e entra no laço
    for (int i = 30; i <= 40; i++) {
        printf("[PID: %d] Processo 4 (PAI) contando: %d\n", getpid(), i);
        sleep(1);
    }
	//note que não existem uma ordem, os processos rodam "juntos"
    return 0;
}
