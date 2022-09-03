// ARQUIVO DE ESPECIFICAÇÕES
#include <stdbool.h>
#include <time.h>

int *create(size_t tam);
void destroy(int *vet_ref);
void print(int *vector, size_t tam);
void append(int *vector, int tam);
double getTime(clock_t start_t, clock_t end_t);
