#include <stdio.h>

void ordena(int vetor[], int inicio, int meio, int fim)
{
	int tam1 = meio - inicio + 1, tam2 = fim - meio;
	int subvetA[tam1], subvetB[tam2];

	for (int i = 0; i < tam1; i++)
	{
		subvetA[i] = vetor[inicio + i];
	}

	for (int i = 0; i < tam2; i++)
	{
		subvetB[i] = vetor[1 + meio + i];
	}
	int i = 0, j = 0, k = inicio;
	while (i < tam1 && j < tam2)
	{
		if (subvetA[i] <= subvetB[j])
		{
			vetor[k] = subvetA[i];
			i++;
		}
		else
		{
			vetor[k] = subvetB[j];
			j++;
		}
		k++;
	}

	while (i < tam1)
	{

		vetor[k] = subvetA[i];
		i++;
		k++;
	}
	while (i < tam2)
	{
		vetor[k] = subvetB[j];
		j++;
		k++;
	}
}

void merge(int vetor[], int inicio, int fim)
{
	if (inicio < fim)
	{
		int meio = inicio + ((fim - inicio) / 2);
		merge(vetor, inicio, meio);
		merge(vetor, meio + 1, fim);
		ordena(vetor, inicio, meio, fim);
	}
}

int main()
{
	int tam = 8;
	int vetor[] = {8, 9, 4, 5, 3, 0, 1, 7};
	printf("Vetor Original :: ");
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
	merge(vetor, 0, tam - 1);

	printf("Vetor Ordenado :: ");
	for (int i = 0; i < tam; i++)
		printf("%d ", vetor[i]);
}