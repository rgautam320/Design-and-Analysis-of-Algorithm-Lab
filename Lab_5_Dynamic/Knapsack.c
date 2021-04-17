/*********************** Rajan Gautam ***********************/
/************************* 19BCP101 *************************/

#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int myKnapsack(int w, int wt[], int val[], int n)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (wt[n - 1] > w)
    {
        return myKnapsack(w, wt, val, n - 1);
    }
    else
    {
        return max(val[n - 1] + myKnapsack(w - wt[n - 1], wt, val, n - 1), myKnapsack(w, wt, val, n - 1));
    }
}

void solve()
{
    int n, w, z;
    scanf("%d %d", &n, &w);
    int wt[n], val[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    z = myKnapsack(w, wt, val, n);
    printf("%d", z);
}

int main()
{
    solve();
    return 0;
}