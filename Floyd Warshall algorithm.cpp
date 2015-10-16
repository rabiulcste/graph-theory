#include <iostream>
#include <cstdio>
using namespace std;
#define V 4 //no of nodes
#define INF 99999

void printSolution(int dist[][V]);

void floydWarshall(int graph[][V])
{
    int dist[V][V], i, j, k;

    //Initialize the solution matrix as input matrix
    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
        dist[i][j] = graph[i][j];

    //Traverse each pair of nodes
    for(k = 0; k < V; k++) {
        for(i = 0; i< V; i++) {
            for(j = 0; j < V; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    //Print the solution
    printSolution(dist);
}

void printSolution(int dist[][V])
{
    printf("Shortest distance between every pair of vertices\n");
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            if(dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[V][V];
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshell(graph);
}
