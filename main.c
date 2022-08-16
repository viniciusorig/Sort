#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "intVector.h"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Voce precisa passar apenas 2 argumentos");
        exit(EXIT_FAILURE);
    }
    int tam = atoi(argv[1]);
    struct intVector *intVector = create(tam);

    append(intVector, tam);

    mergesort(intVector, 0, tam);

    print(intVector);

    destroy(intVector);
    return 0;
}