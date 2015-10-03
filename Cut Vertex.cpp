/*
Let disc_time[u] be the time at which a vertex u was discovered/explored
during the dfs traversal. Let low[u] be the earliest discovery time of any vertex
in the subtree rooted at u or connected to a vertex in that subtree by a back edge.

1. Then If some child x of u has low[x] ≥ disc_time[u], then u is an articulation point.
2. low[u] = min( {low[v] | v is a child of u} ∪ {disc_time[x] | (u, x) is a back edge from u} )
*/

#include <bits//stdc++.h>

using namespace std;
#define MAX 1000
vector< int > G[MAX];
int low[MAX], dis[MAX], dfstime;

void dfs(int u, int par = -1) {
    dis[u] = low[u] = dfstime++;
    int child = 0;
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(v == par) continue;
        if(dis[v]!=-1) low[u] = min(low[u], dis[v]);
        else {
            dfs(v, u);
            if(u!=0 && low[v] >= dis[u]) child = 1;
            else if(u==0) child++;
            low[u] = min(low[u], low[v]);
        }
    }
    if(u!=0 && child)
        cout<<"Articulation Point "<<u<<endl;
    else if(u==0 && child>1)
        cout<<"Articulation Point "<<u<<endl;
}

int main()
{
    int a, b, n, m;
    // please note vetices are indexed from 0 as base
    // please provide number of vertices and edges?
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) G[i].clear();

    for(int p=0; p<m; p++)
    {
        scanf("%d %d",&a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<n;i++) dis[i] = -1;
    dfstime = 1;;
    dfs(0,-1);
}
