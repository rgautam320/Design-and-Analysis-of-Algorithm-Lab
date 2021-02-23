#include <stdio.h>
#define MAX 30

typedef struct edge
{
    int u, v, w;
}   edge;

typedef struct edge_list
{
    edge data[MAX];
    int n;
}   edge_list;

edge_list elist;

int Graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgo();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algo
void kruskalAlgo()
{
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
        {
            if (Graph[i][j] != 0)
            {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }

    sort();

    for (i = 0; i < n; i++)
        belongs[i] = i;

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++)
    {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v);

        if (cno1 != cno2)
        {
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;
            applyUnion(belongs, cno1, cno2);
        }
    }
}

int find(int belongs[], int vertexno)
{
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2)
{
    int i;

    for (i = 0; i < n; i++)
        if (belongs[i] == c2)
            belongs[i] = c1;
}

// Sorting algo
void sort()
{
    int i, j;
    edge temp;

    for (i = 1; i < elist.n; i++)
        for (j = 0; j < elist.n - 1; j++)
            if (elist.data[j].w > elist.data[j + 1].w)
            {
                temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
}

// Printing the result
void print()
{
    int i, cost = 0;
    printf("Minimum Spanning Tree's Edges are: \n\n");
    for (i = 0; i < spanlist.n; i++)
    {
        printf("%d. Edge (%d , %d) : %d\n", i+1, spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\n\nMinimum Spanning Tree Cost: %d\n\n", cost);
}

int main()
{
    n = 9;

    Graph[0][0] = 0;
    Graph[0][1] = 4;
    Graph[0][2] = 0;
    Graph[0][3] = 0;
    Graph[0][4] = 0;
    Graph[0][5] = 0;
    Graph[0][6] = 0;
    Graph[0][7] = 8;
    Graph[0][8] = 0;


    Graph[1][0] = 4;
    Graph[1][1] = 0;
    Graph[1][2] = 8;
    Graph[1][3] = 0;
    Graph[1][4] = 0;
    Graph[1][5] = 0;
    Graph[1][6] = 0;
    Graph[1][7] = 11;
    Graph[1][8] = 0;


    Graph[2][0] = 0;
    Graph[2][1] = 8;
    Graph[2][2] = 0;
    Graph[2][3] = 7;
    Graph[2][4] = 0;
    Graph[2][5] = 4;
    Graph[2][6] = 0;
    Graph[2][7] = 0;
    Graph[2][8] = 2;


    Graph[3][0] = 0;
    Graph[3][1] = 0;
    Graph[3][2] = 7;
    Graph[3][3] = 0;
    Graph[3][4] = 9;
    Graph[3][5] = 14;
    Graph[3][6] = 0;
    Graph[3][7] = 0;
    Graph[3][8] = 0;


    Graph[4][0] = 0;
    Graph[4][1] = 0;
    Graph[4][2] = 0;
    Graph[4][3] = 9;
    Graph[4][4] = 0;
    Graph[4][5] = 10;
    Graph[4][6] = 0;
    Graph[4][7] = 0;
    Graph[4][8] = 0;


    Graph[5][0] = 0;
    Graph[5][1] = 0;
    Graph[5][2] = 4;
    Graph[5][3] = 14;
    Graph[5][4] = 10;
    Graph[5][5] = 0;
    Graph[5][6] = 2;
    Graph[5][7] = 0;
    Graph[5][8] = 0;


    Graph[6][0] = 0;
    Graph[6][1] = 0;
    Graph[6][2] = 0;
    Graph[6][3] = 0;
    Graph[6][4] = 0;
    Graph[6][5] = 2;
    Graph[6][6] = 0;
    Graph[6][7] = 1;
    Graph[6][8] = 6;


    Graph[7][0] = 8;
    Graph[7][1] = 11;
    Graph[7][2] = 0;
    Graph[7][3] = 0;
    Graph[7][4] = 0;
    Graph[7][5] = 1;
    Graph[7][6] = 0;
    Graph[7][7] = 0;
    Graph[7][8] = 7;


    Graph[8][0] = 0;
    Graph[8][1] = 0;
    Graph[8][2] = 2;
    Graph[8][3] = 0;
    Graph[8][4] = 0;
    Graph[8][5] = 0;
    Graph[8][6] = 6;
    Graph[8][7] = 7;
    Graph[8][8] = 0;


    kruskalAlgo();
    print();
}
