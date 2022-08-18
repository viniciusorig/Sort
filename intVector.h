// ARQUIVO DE ESPECIFICAÇÕES
#include <stdbool.h>
struct Vetor
{
    int capacity; // numero maximo de elementos
    int size;     // qtd de elementos atuais
    int *data;    // vetor de int
};

struct Vetor *create(int tam);
void destroy(struct Vetor *ref_vector);
int size(struct Vetor *vector);
int capacity(struct Vetor *vector);
int at(struct Vetor *vector, int pos);
int get(struct Vetor *vector);
void append(struct Vetor *vector, int tam);
void print(struct Vetor *vector);
bool isFull(struct Vetor *vector);
void ordena(struct Vetor *vetor, int inicio, int meio, int fim);
void merge(struct Vetor *vetor, int inicio, int fim);


/*--------------PODERIA EXISTIR-------------*/
// bool compare(floatVector*, floatVector*);
// void split(floatVector*, floatVector*);
// void join(floatVector*, floatVector*);