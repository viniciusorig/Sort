// ARQUIVO DE ESPECIFICAÇÕES
#include <stdbool.h>
struct intVector
{
    int capacity; // numero maximo de elementos
    int size;     // qtd de elementos atuais
    int *data;    // vetor de floats
};

struct intVector *create(int tam);
void destroy(struct intVector **ref_vector);
int size(struct intVector *vector);
int capacity(struct intVector *vector);
int at(struct intVector *vector, int pos);
int get(struct intVector *vector);
void append(struct intVector *vector, int tam);
void print(struct intVector *vector);
bool isFull(struct intVector *vector);

/*--------------PODERIA EXISTIR-------------*/
// bool compare(floatVector*, floatVector*);
// void split(floatVector*, floatVector*);
// void join(floatVector*, floatVector*);