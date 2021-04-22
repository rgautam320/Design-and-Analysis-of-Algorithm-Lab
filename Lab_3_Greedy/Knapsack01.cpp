#include <bits/stdc++.h>
using namespace std;
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int knapSack(int W, vector<int>wt, vector<int>val, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
}
// Driver code
int main()
{
    vector<int> profit= {280,100,120,120};
    vector<int> weight= {40,10,20,24};
    int W = 60;
    int n = profit.size();
    cout<<"Maximum Value of Knapsack is " << knapSack(W, weight, profit, n)<<endl;
    return 0;
}
