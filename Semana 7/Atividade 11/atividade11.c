#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *conta_thread1(void *arg) {
    for (int i = 1; i <= 10; i++) {
        //pthread_self() pega o ID real da thread no sistema
        printf("[ID: %lu] Thread 1 contando: %d\n", (unsigned long)pthread_self(), i);
        sleep(1);
    }
    return NULL;
}

void *conta_thread2(void *arg) {
    for (int i = 10; i <= 20; i++) {
        printf("[ID: %lu] Thread 2 contando: %d\n", (unsigned long)pthread_self(), i);
        sleep(1);
    }
    return NULL;
}

void *conta_thread3(void *arg) {
    for (int i = 20; i <= 30; i++) {
        printf("[ID: %lu] Thread 3 contando: %d\n", (unsigned long)pthread_self(), i);
        sleep(1);
    }
    return NULL;
}

void *conta_thread4(void *arg) {
    for (int i = 30; i <= 40; i++) {
        printf("[ID: %lu] Thread 4 contando: %d\n", (unsigned long)pthread_self(), i);
        sleep(1);
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2, t3, t4;

    //cria as quatro threads simultaneamente
    pthread_create(&t1, NULL, conta_thread1, NULL);
    pthread_create(&t2, NULL, conta_thread2, NULL);
    pthread_create(&t3, NULL, conta_thread3, NULL);
    pthread_create(&t4, NULL, conta_thread4, NULL);

    //obriga o programa principal a esperar as 4 terminarem
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    printf("Todas as contagens foram concluidas!\n");
    return 0;
}
