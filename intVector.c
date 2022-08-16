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

struct intVector *create(int tam)
{
    struct intVector *vet = (struct intVector *)calloc(1, sizeof(struct intVector));
    vet->capacity = tam;
    vet->size = 0;
    vet->data = (int *)calloc(vet->capacity, sizeof(int));

    return vet;
}

/**
 * @brief destroi(libera) um vetor de float com uma dada capacidade
 */
void destroy(struct intVector **vet_ref)
{
    struct intVector *vet = *vet_ref;
    free(vet->data);
    free(vet);
    *vet_ref = NULL;
}

/**
 * @brief  quantos dados do vetor atual
 * @return retorna quantos dados existe atualmente do vetor alocado dinamicamente
 */
int size(struct intVector *vector)
{
    return vector->size;
}

/**
 *@brief tamanho total do vetor
 * @return retorna o tamanho maximo do vetor
 */
int capacity(struct intVector *vector)
{
    return vector->capacity;
}

/**
 * @brief verifica a posição atual do ponteiro e se estiver em uma posição invada ele sai do programa principal
 * @param pos posição que deseja que o ponteiro se deslo
 */
int at(struct intVector *vector, int pos)
{
    if (pos < 0 || pos >= vector->size)
    {
        fprintf(stderr, "ERROR: INVALID POSITION\n");
    }
    exit(EXIT_FAILURE);
}

void print(struct intVector *vector)
{
    for (int i = 0; i < vector->size; i++)
    {
        fprintf(stdout, "%f", vector->data[i]);
    }
}

void append(struct intVector *vector, int tam)
{
    for (int i = 0; i < vector->size; i++)
    {
        if (isFull(vector) == true)
        {
            vector->data = (struct intVector *)realloc(vector, vector->capacity + 1 * sizeof(struct intVector));
        }
        vector->data[i] = rand() % tam;
    }
}

bool isFull(struct intVector *vector)
{
    if (vector->size == vector->capacity)
    {
        return true;
    }
    else
        return false;
}
