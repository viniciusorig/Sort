#include <stdlib.h>
#include <stdio.h>

#include "sort.h"
#include "intVector.h"

void merge(struct Vetor *vetor, int l, int m, int r)
{
    int i = 0, j = 0, k = 0;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = vetor->data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor->data[m + 1 + j];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor->data[k] = L[i];
            i++;
        }
        else
        {
            vetor->data[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor->data[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vetor->data[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(struct Vetor *vetor, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(vetor, l, m);
        mergeSort(vetor, m + 1, r);

        merge(vetor, l, m, r);
    }
}