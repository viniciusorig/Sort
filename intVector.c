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

struct Vetor *create(int tam)
{
    struct Vetor *vet = (struct Vetor *)malloc(sizeof(struct Vetor));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (int *)malloc(tam * sizeof(int));

    return vet;
}

/**
 * @brief destroi(libera) um vetor de float com uma dada capacidade
 */
void destroy(struct Vetor *vet_ref)
{
    free(vet_ref->data);
    free(vet_ref);
}

/**
 * @brief  quantos dados do vetor atual
 * @return retorna quantos dados existe atualmente do vetor alocado dinamicamente
 */
int size(struct Vetor *vector)
{
    return vector->size;
}

/**
 *@brief tamanho total do vetor
 * @return retorna o tamanho maximo do vetor
 */
int capacity(struct Vetor *vector)
{
    return vector->capacity;
}

/**
 * @brief verifica a posição atual do ponteiro e se estiver em uma posição invada ele sai do programa principal
 * @param pos posição que deseja que o ponteiro se deslo
 */
int at(struct Vetor *vector, int pos)
{
    if (pos < 0 || pos >= vector->size)
    {
        fprintf(stderr, "ERROR: INVALID POSITION\n");
    }
    exit(EXIT_FAILURE);
}

void print(struct Vetor *vector)
{
    for (int i = 0; i < vector->capacity; i++)
    {
        fprintf(stdout, "%d\t", vector->data[i]);
    }
}

void append(struct Vetor *vector, int tam)
{
    tam = 5;
    for (int i = 0; i < tam; i++)
    {

        vector->data[i] = rand() % tam;
        printf("%d\t", vector->data[i]);
    }
}

bool isFull(struct Vetor *vector)
{
    if (vector->size == vector->capacity)
    {
        return true;
    }
    else
        return false;
}

void ordena(struct Vetor *vetor, int inicio, int meio, int fim)
{
	int tam1 = meio - inicio + 1, tam2 = fim - meio;
	int subvetA[tam1], subvetB[tam2];

	for (int i = 0; i < tam1; i++)
	{
		subvetA[i] = vetor->data[inicio + i];
	}

	for (int i = 0; i < tam2; i++)
	{
		subvetB[i] = vetor->data[1 + meio + i];
	}
	int i = 0, j = 0, k = inicio;
	while (i < tam1 && j < tam2)
	{
		if (subvetA[i] <= subvetB[j])
		{
			vetor->data[k] = subvetA[i];
			i++;
		}
		else
		{
			vetor->data[k] = subvetB[j];
			j++;
		}
		k++;
	}

	while (i < tam1)
	{

		vetor->data[k] = subvetA[i];
		i++;
		k++;
	}
	while (i < tam2)
	{
		vetor->data[k] = subvetB[j];
		j++;
		k++;
	}
}

void merge(struct Vetor *vetor, int inicio, int fim)
{
	if (inicio < fim)
	{
		int meio = inicio + ((fim - inicio) / 2);
		merge(vetor, inicio, meio);
		merge(vetor, meio + 1, fim);
		ordena(vetor, inicio, meio, fim);
	}
}