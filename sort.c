#include <stdlib.h>
#include <stdio.h>

#include "sort.h"
#include "intVector.h"

void merge(int *vetor, int began, int mid, int end)
{
    int i = 0, j = 0, k = 0;
    int n1 = mid - began + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = vetor[began + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[mid + 1 + j];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *vetor, int began, int end)
{
    if (began < end)
    {
        int m = began + (end - began) / 2;

        mergeSort(vetor, began, m);
        mergeSort(vetor, m + 1, end);

        merge(vetor, began, m, end);
    }
}

void quicksort(int *vetor, int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = vetor[(began + end) / 2];
	while(i <= j)
	{
		while(vetor[i] < pivo && i < end)
		{
			i++;
		}
		while(vetor[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quicksort(vetor, began, j+1);
	if(i < end)
		quicksort(vetor, i, end);
}

void swap(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble(int *vetor, int began, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                swap(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

void selection(int *vetor, int began, int end)
{
    int menor = 0;
    for (int i = 0; i < end; i++)
    {
        for (int j = i; j < end; j++)
        {
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }
        if (menor != i)
            swap(&vetor[i], &vetor[menor]);
    }
}
