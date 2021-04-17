/*********************** Rajan Gautam ***********************/
/************************* 19BCP101 *************************/

#include <stdio.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int mySolver(int STATION, int a[][STATION], int t[][STATION], int *e, int *x)
{
    int T1[STATION], T2[STATION], i, answer;

    T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

    for (i = 1; i < STATION; ++i)
    {
        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[1][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[0][i] + a[1][i]);
    }

    answer = min(T1[STATION - 1] + x[0], T2[STATION - 1] + x[1]);

    for (int i = 0; i < STATION; i++)
    {
        if (T1[i] > T2[i])
        {
            printf("STATION => %d  LINE => %d \n", i, 2);
        }
        else
        {
            printf("STATION => %d  LINE => %d \n", i, 1);
        }
    }
    return answer;
}

int main()
{
    int ans, No_of_Station;

    printf("Enter the Number of Station: ");
    scanf("%d", &No_of_Station);

    int a[2][No_of_Station], t[2][No_of_Station], e[2], x[2];

    for (int i = 0; i < No_of_Station; i++)
    {
        scanf("%d", &a[0][i]);
    }
    for (int i = 0; i < No_of_Station; i++)
    {
        scanf("%d", &a[1][i]);
    }
    for (int i = 0; i < No_of_Station; i++)
    {
        scanf("%d", &t[0][i]);
    }
    for (int i = 0; i < No_of_Station; i++)
    {
        scanf("%d", &t[1][i]);
    }
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &e[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        scanf("%d", &x[i]);
    }

    ans = mySolver(No_of_Station, a, t, e, x);

    printf("%d", ans);

    return 0;
}