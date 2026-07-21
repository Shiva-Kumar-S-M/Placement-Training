// #include <stdio.h>

// #define V 5
// #define INF 9999

// int main(){
//     int graph[V][V] = {
//         {0, 2, 0, 6, 0},
//         {2, 0, 3, 8, 5},
//         {0, 3, 0, 0, 7},
//         {6, 8, 0, 0, 9},
//         {0, 5, 7, 9, 0}
//     };

//     int selected[V] = {0};
//     int no_edge = 0;
//     int x, y;

//     selected[0] = 1;   // Start from vertex 0

//     printf("Edge\tWeight\n");

//     while (no_edge < V - 1) {
//         int min = INF;
//         x = 0;
//         y = 0;

//         for (int i = 0; i < V; i++) {
//             if (selected[i]) {
//                 for (int j = 0; j < V; j++) {
//                     if (!selected[j] && graph[i][j]) {
//                         if (graph[i][j] < min) {
//                             min = graph[i][j];
//                             x = i;
//                             y = j;
//                         }
//                     }
//                 }
//             }
//         }

//         printf("%d - %d\t%d\n", x, y, graph[x][y]);

//         selected[y] = 1;
//         no_edge++;
//     }

//     return 0;
// }

//Krushkal's algorithm is a greedy algorithm that finds a minimum spanning tree for a connected weighted graph. It works by sorting all the edges in the graph by their weight and adding them one by one to the spanning tree, ensuring that no cycles are formed. The algorithm continues until there are (V-1) edges in the spanning tree, where V is the number of vertices in the graph.
#include <stdio.h>

#define MAX 20
#define INF 9999

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int unite(int i, int j)
{
    if(i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main()
{
    int cost[MAX][MAX];
    int n;
    int i, j;
    int min, a, b;
    int u, v;
    int edges = 0;
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    printf("\nEdges in MST:\n");

    while(edges < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(unite(u, v))
        {
            printf("%d - %d : %d\n", a, b, min);
            total += min;
            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("\nTotal Cost = %d\n", total);

    return 0;
}






