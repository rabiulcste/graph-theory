#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, E;
vector<int>adj[100];
vector<int>revadj[100];
int in[100];

void DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur all the nodes adjacent to this vertex
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

void revDFSUtil(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;

    // Recur all the nodes adjacent to this vertex
    vector<int>::iterator i;
    for(i = revadj[v].begin(); i != revadj[v].end(); ++i)
        if(!visited[*i])
            revDFSUtil(*i, visited);
}


bool isSC()
{
    // Mark all the nodes as not visited (for First DFS)
    bool visited[N];
    for(int i = 0; i < N; i++)
        visited[i]  = false;

    // Find the first node with non-zero degree
    int n;
    for(int n = 0; n < N; n++)
            if(adj[n].size() > 0)
                break;
    // Do DFS traversal starting from first non-zero degree node
    DFSUtil(n, visited);

    // If DFS traversal doesn't visit all nodes, then return false
    for(int i = 0; i < N; i++)
        if(adj[i].size() > 0 && visited[i] == false)
            return false;
    // Mark all the nodes as not visited (for Second DFS)
    for(int i = 0; i < N; i++)
        visited[i]  = false;

    // Do DFS for reversed graph starting from first node.
    // Starting vertex must be same as starting point of first DFS
    revDFSUtil(n, visited);

    // If all node are not visited in second DFS, then return false
    for(int i = 0; i < N; i++)
      if(adj[i].size() > 0 && visited[i] == false)
            return false;
    return true;
}

bool isEulerianCycle()
{
    // Check if all non-zero vertices are connected
    if(isSC() == false)
        return false;

    // Check if in degree and out degree of every vertex is same
    for(int i =0; i < N; i++)
        if(adj[i].size()!=in[i])
            return false;
    return true;
}


int main()
{
    int u, v;
    cin>>N>>E;

    // Initialize in degree array as 0
    for (int i = 0; i < N; i++)
       in[i] = 0;

    for(int i = 0; i < E; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
        in[u]++; // Count in degree
    }
    if(isEulerianCycle())
        cout << "Given graph is eulerian" << endl;
    else
        cout << "Given graph is not eulerian" << endl;
}
