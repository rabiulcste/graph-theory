#include <stdio.h>
#include <queue>
using namespace std;

int nodes, edges, src, last;
int graph[100][100], color[100], dist[100];
const int WHITE = 0;
const int GRAY = 1;
const int BLACK = 2;

int main() {
    // printf("Nodes, edges, source? ");
    scanf("%d %d", &nodes, &edges);
    for (int i = 0; i < edges; i++) {
        // printf("Edge %d: ", i);
        int x, y;
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
    }
    scanf("%d %d", &src, &last);

    //run BFS
    queue<int> q; //create a queue
    q.push(src); //1. put root node on the queue
    dist[src] = 1;
    do {
        int u = q.front(); //2. pull a node from the beginning of the queue
        q.pop();
        // printf("%d ", u); //print the node
        for (int i = 0; i < nodes; i++) { //4. get all the adjacent nodes
            if ((graph[u][i] == 1) //if an edge exists between these two nodes,
                && (color[i] == WHITE)) { //and this adjacent node is still WHITE,
                q.push(i); //4. push this node into the queue
                color[i] = GRAY; //color this adjacent node with GRAY
                dist[i] = dist[u] + 1;
            }
        }
        color[u] = BLACK; //color the current node black to mark it as dequeued
    } while (!q.empty()); //5. if the queue is empty, then all the nodes have been visited
    // printf("%d\n", dist[last]);
    return 0;
}
