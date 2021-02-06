/* ------------------------- 19BCP101 -----------------------*/
/* ----------------------- Rajan Gautam ---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>          // For Time Calculation

// Function for Insertion Algorithm
void insertion_sort(int A[], int n)
{
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {

            A[j+1] = A[j];
            j = j -1;
        }
        A[j+1] = key;
    }
}

// Function for Bubble Sort Algorithm
void bubble_sort(int A[], int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (A[j] > A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}


int main()
{
    printf("<--------------- Sorting --------------->\n\n");

    int n = 1000, it = 0;
    double time1[20], time2[20];         // To store the time values

    printf(" Array    |  Bubble(s)   |  Insertion(s) \n\n");

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
        bubble_sort(a, n);
        end = clock();

        time1[it] = ((double)(end - start)/CLOCKS_PER_SEC);


        // For Insertion Algorithm
        start = clock();
        insertion_sort(b, n);
        end = clock();

        time2[it] = ((double)(end - start)/CLOCKS_PER_SEC);

        // Printing the table of array size, time taken by Bubble Sort and Insertion Algorithm
        printf(" %d     |   %f   |  %f\n", n, time1[it], time2[it]);


        // Incrementing the value of n by 1000
        n += 1000;
    }
    return 0;
}


