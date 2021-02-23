#include<bits/stdc++.h>
using namespace std;
struct Item
{
    int profit;
    int weight;

};
bool comp(Item a,Item b)
{
    double i1 = (double)a.profit/double(a.weight);
    double i2 = (double)b.profit/double(b.weight);
    return i1>i2;
}
double fractionalKnapsack(int W,Item arr[],int n)
{

    sort(arr,arr+n,comp);


    int currentWeight=0;
    double finalProfit=0.0;

    for(int i=0; i<n; i++)
    {
        if(currentWeight+arr[i].weight<=W)
        {
            currentWeight+=arr[i].weight;
            finalProfit+=arr[i].profit;
        }
        else
        {
            int remaining=W-currentWeight;
            finalProfit+=(arr[i].profit*((double)remaining)/(double)arr[i].weight);

            break;
        }
    }

    return finalProfit;

}
int main()
{

    int W=60;
    int n=4;
    Item arr[4]= {{280,40},{100,10},{120,20},{120,24}};
    cout<< "Maximum Value of Knapsack is " <<fractionalKnapsack(W,arr,n) <<endl;
    return 0;

}
