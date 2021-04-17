/*********************** Rajan Gautam ***********************/
/************************* 19BCP101 *************************/

#include <stdio.h>
#define INFINITY 999999;

int ss[6][6], mm[20][20], pp[20], i, j, n;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int mySolver(int *a, int s, int e)
{
    if (s == e)
    {
        return 0;
    }
    int mini = __INT_MAX__;

    for (int i = s; i < e; i++)
    {
        mini = min(mini, mySolver(a, s, i) + mySolver(a, i + 1, e) + a[s - 1] * a[i] * a[e]);
    }
    return mini;
}

void MatrixMultiply(void)
{
    long int q;
    int i, j, k;
    for (i = n; i > 0; i--)
    {
        for (j = i; j <= n; j++)
        {
            if (i == j)
                mm[i][j] = 0;
            else
            {
                for (k = i; k < j; k++)
                {
                    q = mm[i][k] + mm[k + 1][j] + pp[i - 1] * pp[k] * pp[j];
                    if (q < mm[i][j])
                    {
                        mm[i][j] = q;
                        ss[i][j] = k;
                    }
                }
            }
        }
    }
}

void print_optimal(int i, int j)
{
    if (i == j)
        printf("A%d ", i);
    else
    {
        printf("( ");
        print_optimal(i, ss[i][j]);
        print_optimal(ss[i][j] + 1, j);
        printf(" )");
    }
}

int main()
{
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            mm[i][i] = 0;
            mm[i][j] = INFINITY;
            ss[i][j] = 0;
        }
    }
    printf("Enter the dimensions: ");
    for (int i = 0; i <= n; i++)
    {
        scanf("%d", &pp[i]);
    }

    MatrixMultiply();

    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            printf("%d \t", mm[i][j]);
        }
        printf("\n");
    }

    i = 1;
    j = n;
    printf("Multiplication Sequence: \n");

    print_optimal(i, j);

    printf("\nMinimum Number of Multiplication: %d", mySolver(pp, 1, n));

    return 0;
}