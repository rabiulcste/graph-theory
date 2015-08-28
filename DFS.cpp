#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <list>

using namespace std;
vector<int> adj[100]; //adj[a].push_back(b); for add an edge from a to b
bool visited[100]; //False if not visited, true if visited

void addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}


void DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); ++i)
        if(!visited[*i])
        DFSUtil(*i, visited);
}


// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void DFS(int n, int s)
{
    // Mark all the vertices as not visited
    for(int i = 0; i < n; i++)
        visited[i] = false;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(s, visited);
}


int main()
{
    // Create a graph given in the above diagram
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);

    cout << "Following is Depth First Traversal ";
    cout << "(starting from vertex 2)\n";
    DFS(4, 2);
    return 0;
}
