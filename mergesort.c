#include <stdio.h>
#include <stdlib.h>

int a[] = {11, 22, 33, 44, 55};
int b[] = {5, 10, 15, 20, 25};
int c[200];
int size1 = sizeof(a) / sizeof(int);
int size2 = sizeof(b) / sizeof(int);
int size3 = 10;
int i = 0, j = 0, k = 0;

void main()
{
    while (i < size1 && j < size2)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
        }
        if (b[j] < a[i])
        {
            c[k++] = b[j++];
        }
    }

    while (i < size1)
    {
        c[k++] = a[i++];
    }
    while (j < size2)
    {
        c[k++] = b[j++];
    }
    for (i = 0; i < size3; i++)
    {
        printf("%d ", c[i]);
    }
}
