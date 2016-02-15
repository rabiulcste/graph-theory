#include <bits//stdc++.h>
using namespace std;

// MAXN = maximum points in the graph
#define MAXN 1000
vector<int> G[MAXN];
bool vis[MAXN];
int timer, dis[MAXN], low[MAXN];
vector<int>arti;
void dfs (int u, int p = -1) {
    vis[u] = true;
    dis[u] = low[u] = timer++;
    int children = 0;
    for (int i=0; i<G[u].size(); ++i) {
        int v = G[u][i];
        if (v == p)  continue;
        if (vis[v])
            low[u] = min (low[u], dis[v]);
        else {
            dfs (v, u);
            low[u] = min (low[u], low[v]);
            if (low[v] >= dis[u] && p != -1)
                //u is articulation point
                arti.push_back(u);
                ++children;
        }
    }
    if (p == -1 && children > 1)
        //u is articulation point
        arti.push_back(u);
        }

int main() {
    int n, m;
    // read nodes, edges
    scanf("%d %d", &n, &m);

    for(int p=0; p<m; p++)
    {
        int a, b;
        scanf("%d %d",&a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
    timer = 0;
    for (int i=0; i<n; ++i)
        vis[i] = false;
    dfs (0);
    for(int i=0; i<arti.size(); i++)
    {
        cout<<arti[i]<<endl;
    }
}
