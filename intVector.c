// ARQUIVO DE IMPLEMANTAÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "intVector.h"

// minha tad

/**
 * @brief create(alocate) a vector of floats
 *
 * @param tam is the capacity of the vector
 * @return struct intVector* um vetor de floats alocado/criado
 */

int *create(size_t tam)
{
	int *vet = (int *)malloc(tam * sizeof(int));
	append(vet, tam);
	return vet;
}

/**
 * @brief destroi(libera) um vetor de float com uma dada capacidade
 */
void destroy(int *vet_ref)
{
	free(vet_ref);
}

void print(int *vector, size_t tam)
{
	for (int i = 0; i < tam; i++)
	{
		fprintf(stdout, "%d\t", vector[i]);
	}
}

void append(int *vector, int tam)
{
	for (int i = 0; i < tam; i++)
	{
		vector[i] = rand() % tam;
	}
}

double getTime(clock_t start_t, clock_t end_t)
{
	double total_t = (double)(end_t - start_t)/CLOCKS_PER_SEC;
	return total_t;
}
