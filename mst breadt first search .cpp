#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

vector<int> adj[100]; //adj[a].push_back(b); for add an edge from a to b
int visited[100]={0}; //O if not visited, 1 if visited
int level[100];

void addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void bfs(int s, int n)
{
    for(int i=0; i<n; i++)
        visited[i] = 0;

    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    level[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
            cout << u <<" ";
        for(int i=0; i<adj[u].size(); i++){
            if(visited[adj[u][i]]==0){
                int v = adj[u][i];
                level[v] = level[u]+1;
                visited[v] = 1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        printf("%d to %d distance = %d\n", s, i, level[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    bfs(2, 4);
    return 0;
}
