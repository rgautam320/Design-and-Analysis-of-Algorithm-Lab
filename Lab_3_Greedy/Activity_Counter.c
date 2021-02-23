#include <stdio.h>
#include <stdlib.h>

// Algorithm to sort array
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

// Algorithm for Greedy
int GreedyAlgorithm(int S[], int F[], int n)
{
    int A = 1;
    int j = 1;
    for (int i = 2; i <= n; i++)
    {
        if(S[i] >= F[j])
        {
            A++;
            j = i;
        }
    }
    return A;
}

// Main Function
int main()
{
    // Scanning the total number of Activities
    int numActivity;
    printf("Enter total number of Activity: ");
    scanf("%d", &numActivity);

    // Declaring two arrays
    int start[numActivity];
    int finish[numActivity];

    // Getting the values of start Array
    printf("Enter starting time for %d Activities \n", numActivity);

    for (int i = 0; i < numActivity; i++)
    {
        scanf("%d", &start[i]);
    }

    // Getting the values for final Array
    printf("Enter finishing time for %d Activities \n", numActivity);

    for (int i = 0; i < numActivity; i++)
    {
        scanf("%d", &finish[i]);
    }

    // Sorting the finish array using Insertion Sort Algorithm
    insertion_sort(finish, numActivity);

    // Getting the maximum set of activities that can be done by a single person
    int maxNum = GreedyAlgorithm(start, finish, numActivity);

    // Printing maximum number returned by our GreedyAlgorithm Function
    printf("Maximum Set of Activities that can be done by a single person: %d\n", maxNum);

    return 0;
}
