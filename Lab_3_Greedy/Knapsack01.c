/* 
    Begin
        Get the array of Profit and Weight
        Sort the Array based on the Profit                  --> N logN
        for i = 1 to N:                                     --> N
            If capacity > 0 and weight[i] < capacity:       --> N logN
                capacity -= weight[i]
                Profit += Profit[i]
            End If
        End For Loop
    End

    Time Complexity = O(N logN)
*/

#include <stdio.h>

int main()
{
    // Getting the size of Array and capacity of Knapsack.
    int N, M;
    printf("Enter size of Array: ");
    scanf("%d", &N);
    printf("Enter Capacity of Knapsack: ");
    scanf("%d", &M);

    // Declaring Profit and Weight array. Also we have declared total profit and a temporary variable.
    int A[N], B[N], Ratio[N], P = 0, temp;

    // Getting the Profit and Weight Array.
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i], &B[i]);
    }

    // Sorting the arrays according to the Profit.
    for (int i = 0; i < N; i++)
    {
        if (A[i + 1] > A[i])
        {
            temp = A[i + 1];
            A[i + 1] = A[i];
            A[i] = temp;

            temp = B[i + 1];
            B[i + 1] = B[i];
            B[i] = temp;
        }
    }

    // For each item.
    for (int i = 0; i < N; i++)
    {
        // If bag has some space.
        // And weight value is less than capacity.
        if (M > 0 && B[i] <= M)
        {
            // Decrementing space with added weight.
            M = M - B[i];

            // Adding profit of added item.
            P = P + A[i];

            // Printing the Profit value.
            printf("%d. Profit %d = %d\n", i + 1, i + 1, P);
        }
    }

    // At last, we got total value.
    printf("\nMaximum Profit is: %d", P);
    return 0;
}
