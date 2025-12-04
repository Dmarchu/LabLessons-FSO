#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <math.h>

#define REPETICIONES 20000000

long int V = 100;      // Valor inicial
//VALOR V FINAL 100 = INICIAL
//TReal = 0.002s
//TUser = 0.000s
//TSys  = 0.002s

int test_and_set(int *spinlock) {
  int ret;
  __asm__ __volatile__(
    "xchg %0, %1"
    : "=r"(ret), "=m"(*spinlock)
    : "0"(1), "m"(*spinlock)
    : "memory");
  return ret;
}

void SeccionRestante(int V) {
    int i;
    long tot;
    tot = 0;
    for (i = 0; i < 300; i++) {
       tot = tot+V;
    }
}

void *agrega (void *argumento) {
  long int cont;
  for (cont = 0; cont < REPETICIONES; cont = cont + 1) {
      V = V + 1;
      SeccionRestante(V);
  }
  printf("-------> Fin AGREGA (V = %ld)\n", V);
  pthread_exit(0);
}

void *resta (void *argumento) {
  long int cont;
  for (cont = 0; cont < REPETICIONES; cont = cont + 1) {
        V = V - 1;
        SeccionRestante(V);
  }
  printf("-------> Fin RESTA  (V = %ld)\n", V);
  pthread_exit(0);
}

void *inspecciona (void *argumento) {
  for (;;) {
    usleep(200000);
    fprintf(stderr, "Inspeccion: Valor actual de V = %ld\n", V);
  }
}

int main (int argc, char *argv[]) {
    pthread_t hiloSuma, hiloResta, hiloInspeccion;
    pthread_attr_t attr;

    pthread_attr_init(&attr);

    pthread_create(&hiloInspeccion, &attr, inspecciona, &V);
    pthread_create(&hiloSuma, &attr, agrega, &V);
    pthread_create(&hiloResta, &attr, resta, &V);

    //pthread_join(hiloInspeccion, NULL);
    //pthread_join(hiloSuma, NULL);
    //pthread_join(hiloResta, NULL);

    pthread_exit(0);

    fprintf(stderr, "-------> VALOR FINAL: V = %ld\n\n", V);
    exit(0);
}
