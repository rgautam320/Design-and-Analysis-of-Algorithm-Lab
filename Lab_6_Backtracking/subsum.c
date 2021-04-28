/*
    if(subset is satisfying the constraint)
        print the subset
        exclude the current element and consider next element

    else
        generate the nodes of present level along breadth of tree and
        recur for next levels

    The Time Complexity of this problem is : O(2^N)
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

int totalNodes;

void PrintSolution(int A[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%*d", N, A[i]);
    }
    printf("\n");
}

/* 
    A -> Set Vector
    V -> Tuplet Vector
    ASize -> Set Size
    VSize -> Tuplet Size so Far
    Sum -> Sum so far
    Nodes -> Nodes Count
    m -> Sum to be found
*/

void subsetSum(int A[], int V[], int ASize, int VSize, int sum, int Nodes, int m)
{
    totalNodes++;
    if (m == sum)
    {
        // We found subset
        PrintSolution(V, VSize);

        // Consider next item to find another combination
        subsetSum(A, V, ASize, VSize - 1, sum - A[Nodes], Nodes + 1, m);
        return;
    }
    else
    {
        // Generate Nodes along the breadth
        for (int i = Nodes; i < ASize; i++)
        {
            V[VSize] = A[i];

            // Consider next level node along depth
            subsetSum(A, V, ASize, VSize + 1, sum + A[i], i + 1, m);
        }
    }
}

// A Function to generate subset
void SubsetGenerator(int A[], int size, int m)
{
    int *TupletVector = (int *)malloc(size * sizeof(int));

    subsetSum(A, TupletVector, size, 0, 0, 0, m);

    free(TupletVector);
}

int main()
{
    // Getting the input weights
    int Weight[] = {7, 3, 2, 5, 8};

    SubsetGenerator(Weight, N, 14);

    printf("Total Nodes Generated: %d", totalNodes);

    return 0;
}