#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, E;
vector<int>adj[100];

void addEdge(int v, int w)
{
    adj[v].push_back(w); // add w to v's list
}

void DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

bool isConnected()
{
    // Mark all the vertices as not visited
    bool visited[N];
    int i;
    for(i = 0; i < N; i++)
        visited[i] = false;

    // Find a vertex with non-zero degree
    for(i = 0; i<N; i++)
        if(adj[i].size()!=0)
            break;
    // If there are no edges in the graph, return true
    if(i == N)
        return true;

    // Start DFS traversal from a vertex with non-zero degree
    DFSUtil(i, visited);

    // Check if all non-zero degree vertices are visited
    for(i = 0; i < N; i++)
        if(visited[i] == false && adj[i].size() > 0)
            return false;
    return true;
}

   // The function returns one of the following values
   // 0 --> If graph is not Eulerian
   // 1 --> If graph has an Euler path (Semi-Eulerian)
   // 2 --> If graph has an Euler Circuit (Eulerian) 
int isEulerian()
{
    // Check is all non-zero degree vertices are connected
    if(isConnected() == false)
        return 0;
    // Count vertices with odd degree
    int odd = 0;
    for(int i = 0; i < N; i++)
        if(adj[i].size() & 1)
        odd++;
    // If count is more than 2, then graph is not Eulerian
    if(odd > 2)
        return 0;
    // If odd count is 2, then semi-eulerian
    // If odd count is 0, then eulerian
    // Note that odd count can never be 1 for undirected graph
    return (odd)? 1 : 2;
}


int main()
{
    int u, v;
    cin>>N>>E;
    int res = isEulerian();

    for(int i = 0; i < E; i++){
        cin>>u>>v;
        addEdge(u, v);
    }

    if(res == 0)
        cout << "Graph is not Eulerian" << endl;
    if(res == 1)
        cout << "Graph has an Euler path" << endl;
    else
        cout << "Graph has an Euler Cycle" << endl;
}
