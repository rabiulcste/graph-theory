#include <bits//stdc++.h>
using namespace std;

int M[128][128]; // adjacency matrix
bool seen[128]; // which vertices have been visited by dfs()
int n; // number of vertices

void dfs(int u)
{
    seen[u] = true;
    printf("%d ", u);
    for(int v = 0; v < n; v++) if(!seen[v] && M[u][v]) dfs(v);
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        for(int j =0; j<n; j++) {
        scanf("%d", &M[i][j]);
        }
    }
    for(int i=0; i<n; i++) seen[i] = false;
    dfs(0);
    return 0;
}
