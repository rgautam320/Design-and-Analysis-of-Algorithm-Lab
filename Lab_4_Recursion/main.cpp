#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int recursive_fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }
}

int non_recursive_fibonacci(int n)
{
    int n1 = 0, n2 = 1, next;
    for(int i = 0; i < n - 1; i++)
    {
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
    return next;
}

int recursive_factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * recursive_factorial(n - 1);
    }
}

int non_recursive_factorial(int n)
{
    int factorial = 1;
    for(int i = 1; i <= n; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int m, n;
    cout<<"\t Enter the value of Factorial and Fibonacci: ";
    cin>>m;
    cin>>n;

    cout<<"\t Time Taken by the Recursive and Non-Recursive Factorial"<<endl;
    cout<<"\t Using Recursion: "<< m << "! = "<< recursive_factorial(m)<<endl;
    cout<<"\t Using Non-Recursion: "<< m << "! = "<< non_recursive_factorial(m)<<endl;
    cout<<"\tNumber \t Time Taken by Recursive \tTime Taken by Non-Recursive"<<endl;
    while(m > 0)
    {
        clock_t ft1 = clock();
        recursive_factorial(n);
        clock_t ft2 = clock() - ft1;

        clock_t nft1 = clock();
        non_recursive_factorial(n);
        clock_t nft2 = clock() - nft1;

        cout<<"\t"<<m<<" \t "<< fixed << setprecision(3)<< (float)ft2 / CLOCKS_PER_SEC * 1000 << " ms "<<"\t\t\t"<<(float)nft2 / CLOCKS_PER_SEC * 1000<< " ms\n";

        m = m - 1;
    }


    cout<<"\n\t Time Taken by the Recursive and Non-Recursive Fibonacci Series"<<endl;
    cout<<"\t nth Term Using Recursion: " <<recursive_fibonacci(n)<<endl;
    cout<<"\t nth Term Using Non-Recursion: " << non_recursive_fibonacci(n)<<endl;
    cout<<"\tNumber \t Time Taken by Recursive \tTime Taken by Non-Recursive"<<endl;
    while(n > 10)
    {
        clock_t ft1 = clock();
        recursive_fibonacci(n);
        clock_t ft2 = clock() - ft1;

        clock_t nft1 = clock();
        non_recursive_fibonacci(n);
        clock_t nft2 = clock() - nft1;

        cout<<"\t"<<n<<" \t "<< fixed << setprecision(3)<< (float)ft2 / CLOCKS_PER_SEC * 1000 << " ms "<<"\t\t\t"<<(float)nft2 / CLOCKS_PER_SEC * 1000<< " ms\n";

        n = n - 1;
    }

    return 0;
}
