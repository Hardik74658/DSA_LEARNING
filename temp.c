#include <stdio.h>

// merge -> combine 2 array into 3rd
//  we have 1 array
void merge(int a[], int left, int mid, int right)
{
    int i, j, k;
    const int size1 = mid - left + 1;
    const int size2 = right - mid;
    int l[10], r[10];

    for (i = 0; i < size1; i++)
    {
        l[i] = a[left + i];
    }
    for (j = 0; j < size2; j++)
    {
        r[j] = a[mid + j + 1];
    }

    // merge sort
    i = 0;
    j = 0;
    k = 0;

    while (i < size1 && j < size2)
    {
        if (l[i] < r[j])
        {
            a[k++] = l[i++];
        }
        else
        {
            a[k++] = r[j++];
        }
    }
    while (i < size1)
    {
        a[k++] = l[i++];
    }
    while (j < size2)
    {
        a[k++] = r[j++];
    }
}

// divide - merge
void mergeSort(int a[], int left, int right) // 0  8
{                                            // 0,8
    if (left < right)
    {
        int mid = (left + right) / 2; // 4  : 6
        mergeSort(a, left, mid);      // 0,4   0,2 0 1 2 3  4
        mergeSort(a, mid + 1, right); // 5,8 5 6 7 8
        merge(a, left, mid, right);
    }
}

int main()
{
    int a[] = {15, 21, 7, 45, 6, 78, 9, 25, 3, 10}; // 9*4

    // int a[] = {5,4,3,2,1};
    // int a[] = {24,25,19,71,65};
    // int a[] = {1,2,3,4,5};
    int i;
    int size = sizeof(a) / sizeof(int);
    printf("\ntotal elements in the array => %d", size);
    // 0 1 2 3 4 5 6 7 8 9

    printf("\nArray Before Sort\n");
    for (i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }

    mergeSort(a, 0, size - 1); // 0 size-1

    printf("\nArray After Sort\n");
    for (i = 0; i < size; i++)
    {
        printf(" %d", a[i]);
    }

    return 0;
}