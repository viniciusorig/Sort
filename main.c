#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intVector.h"
#include "sort.h"

typedef struct
{
    clock_t start_t;
    clock_t end_t;
} Time;

FILE *file;

int main(int argc, char *argv[])
{
    Time time;
    if (argc < 3)
    {
        printf("Digite todos os parametros <tam1> <tam2> <tam3> <tam4>");
        exit(EXIT_FAILURE);
    }

    if((file = fopen("result.txt", "a")) == NULL)
    {
        fprintf(stderr,"erro na abertura de arquivo");
        exit(EXIT_FAILURE);
    }

    int tamanhos[] = {atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])};

    void (*funcs[])(int *, int, int) =
        {
            mergeSort,
            quicksort,
            bubble,
            selection
        };

    for (int i = 0; i < 4; i++)
    {
        fprintf(file, "\nQuantidades de dados :: %d\n\n", tamanhos[i]);
        for (int j = 0; j < 4; j++)
        {
            int *vetor = (int *)malloc(tamanhos[i] * sizeof(int));
            time.start_t = clock();
            (funcs[j])(vetor, 0, tamanhos[i]);
            time.end_t = clock();
            fprintf(file, "função[%d] pronta em %lfs\n", j, getTime(time.start_t, time.end_t));
            destroy(vetor);
            time.start_t = 0, time.end_t = 0;
        }
    }

    return 0;
}