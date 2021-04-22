/* 
    Begin
        Get the array of Profit and Weight
        Calculate the Profit/Weight Ratio
        Sort the Array based on the Profit/Weight Ratio.        --> N logN
        for i = 1 to N:     --> N
            if capacity > 0 and weight[i] < capacity:       --> N logN
                capacity -= weight[i]
                Profit += Profit[i]
            else if capacity > 0:
                Profit += Fractional Profit
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

    // Declaring Profit and Weight array. Also we have declared Ration array, total profit and a temporary variable.
    float A[N], B[N], Ratio[N], P = 0, temp;

    // Getting the Profit and Weight Array.
    for (int i = 0; i < N; i++)
    {
        scanf("%f", &A[i]);
        scanf("%f", &B[i]);

        // Getting Ratio of Profit and Weight.
        Ratio[i] = A[i] / (float)B[i];
    }

    // Sorting the arrays according to the Ratio array.
    for (int i = 0; i < N; i++)
    {
        // Sorting in descending order.
        if (Ratio[i + 1] > Ratio[i])
        {
            temp = Ratio[i + 1];
            Ratio[i + 1] = Ratio[i];
            Ratio[i] = temp;

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
            printf("%d. Profit %d = %f\n", i + 1, i + 1, P);
        }
        // If we have some space but another items have larger weight than the available, then we do fraction of weight and profit and add them.
        else if (M > 0)
        {
            // Calculating the fractional profit.
            P = P + (M / B[i]) * A[i];

            // Printing the fractional profit.
            printf("%d. Profit %d = %f", i + 1, i + 1, ((M / B[i]) * A[i]));

            // We don't need to run our code if we enter into fractional part, so use break.
            break;
        }
    }

    // At last, we got total value.
    printf("\nMaximum Profit is: %f", P);

    return 0;
}