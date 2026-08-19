#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int i;
	pid_t pid;

	printf("\nArea Comun, antes do FORK. ");

	if ((pid = fork()) < 0)
	{
		perror("Erro na CriaC'C#o do fork");
		exit(1);
	}
	if (pid == 0)
	{
		//O codigo no processo filho
		printf("\nArea do Fork Filho - %d", getpid());

		int x = 0;
		while (x<3 )
		{
			printf("\n-PID do Filho: %d - ExecuC'C#o: %d\n", getpid(),x) ;
			x++;
			sleep(2);
		}
	}
	else
	{
		//O codigo no processo pai
		printf("\nArea Comun do FOR PAI - %d", getpid());
		int x = 0;
		while (x< 3)
		{
			printf("\n+PID do Pai: %d - Execucao: %d\n", getpid(),x);
			x++;
			sleep(2);
		}
	}
	printf("\n Processos Finalizados - Area comum aos processos. \n Pressione enter:");
	getchar();
	exit(0);
}

