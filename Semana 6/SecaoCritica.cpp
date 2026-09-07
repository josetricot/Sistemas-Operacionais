#include <stdio.h>
#include <pthread.h>

pthread_mutex_t MeuSemaforo = PTHREAD_MUTEX_INITIALIZER;

int soma = 0;

void *contapar(void *param) {
  int i;

//  pthread_mutex_lock(&MeuSemaforo);

  for (i = 0; i < 1000000; i++) {
    soma += 2;
  }
//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}


void *contaimpar(void *param) {
  int i;
  
//  pthread_mutex_lock(&MeuSemaforo);

  for (i = 0; i < 1000000; i++) {
    soma += 3;
  }
//  pthread_mutex_unlock(&MeuSemaforo);
  return NULL;
}


int main() {
  pthread_t tid1, tid2;
  pthread_create(&tid1, NULL, contapar, NULL);
  pthread_create(&tid2, NULL, contaimpar, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);

  printf("A Soma das Threads eh %d\n", soma);
  return 0;
}
