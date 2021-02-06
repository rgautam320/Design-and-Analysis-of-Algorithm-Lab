/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>          // For Time Calculation

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and h
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

/* FOR QUICK SORT */

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main()
{
    printf("<--------------- Sorting --------------->\n\n");

    int n = 1000, it = 0;
    double time1[20], time2[20];         // To store the time values

    printf(" Array \t Merge(s) \t Quick(s) \n\n");

    while(it++ < 10)
    {
        long int a[n], b[n];
        for (int i = 0; i < n ; i++)
        {
            // Generating Random Integer Array for each algorithm

            a[i] = (rand() % n);
            b[i] = (rand() % n);
        }


        // For time calculation
        clock_t start, end;


        // For Bubble Sort Algorithm
        start = clock();
        mergeSort(a, 0, n-1);
        end = clock();

        time1[it] = ((double)(end - start)/CLOCKS_PER_SEC);


        // For Insertion Algorithm
        start = clock();
        quickSort(b, 0, n-1);
        end = clock();

        time2[it] = ((double)(end - start)/CLOCKS_PER_SEC);

        // Printing the table of array size, time taken by Bubble Sort and Insertion Algorithm
        printf(" %d \t %f \t %f\n", n, time1[it], time2[it]);


        // Incrementing the value of n by 1000
        n += 1000;
    }
    return 0;
}


