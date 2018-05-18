/**
---- thread_id.c ----
El programa crea varios hilos y cada uno de ellos ejecuta un hola n, 
donde n es el identificador del hilo. Se hace uso del archivo de cabecera
pthread y de la funcion pthread_self()
Autores: Mateo Gregory (1629431) - Sofía Navas (1629571) - Luis Restrepo (1427086)
Fecha: Mayo 17, 2018
**/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXTHREADS 1000

void *print_n(void *null) {
	printf("hola %ld\n", pthread_self());
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int cant_hilos;
	printf("Digite la cantidad de hilos con los que desea trabajar: ");
	scanf("%d", &cant_hilos);	

	pthread_t ptarray[cant_hilos];

	if (cant_hilos > MAXTHREADS || cant_hilos == 0) {
		printf("La cantidad de hilos que usted puede solicitar debe estar entre 0 y %d\n",MAXTHREADS);
		exit(-1);
	}

	for (int i = 0; i < cant_hilos; i++) {
		pthread_create(&ptarray[i], NULL, print_n, NULL);		
	}

	for (int i = 0; i < cant_hilos; i++) {
		pthread_join(ptarray[i], NULL);
	}
	
	return 0;
} 