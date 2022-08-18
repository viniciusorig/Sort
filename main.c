#include <stdio.h>
#include <stdlib.h>
#include "intVector.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Voce precisa passar apenas 2 argumentos");
        exit(EXIT_FAILURE);
    }
    int tam = atoi(argv[1]);
    struct Vetor *vetor = create(tam);

    for (int i = 0; i < tam; i++)
        vetor->data[i] = rand() % tam;

   /*  printf("Vetor Original :: ");
    for (int i = 0; i < tam; i++)
        printf("%d ", vetor->data[i]); */
    merge(vetor, 0, tam - 1);   

    printf("\n\n\nVetor Ordenado :: ");
    /* for (int i = 0; i < tam; i++)
        printf("%d ", vetor->data[i]); */
    destroy(vetor);
    return 0;
}