#include<bits/stdc++.h>
using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))
#define MAX 1005

vector<int> G[MAX],R[MAX],SCC[MAX],myList,nodes;
bool visited[MAX];

void dfs1(int u)
{
    visited[u] = 1;
    int l = G[u].size();
    for(int i = 0; i < l; i++) {
        int v = G[u][i];
        if(!visited[v]) dfs1(v);
    }
    myList.push_back(u);
}

void dfs2(int u)
{
    visited[u] = 1;
    nodes.push_back(u);
    int l = R[u].size();
    for(int i = 0; i < l; i++) {
        int v = R[u][i];
        if(!visited[v]) dfs2(v);
    }
}

int main()
{
    int i, j, n, m, a, b, totalSCC;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        R[b].push_back(a);
    }

    CLR(visited); myList.clear();
    for(i = 1; i <= n; i++) {
        if(!visited[i]) dfs1(i);
    }

    CLR(visited); totalSCC = 0;
    for(i = n-1; i >= 0; i--) {
        if(!visited[myList[i]]) {
            nodes.clear();
            dfs2(myList[i]);
            SCC[totalSCC] = nodes;
            totalSCC++;
        }
    }

    printf("%d\n", totalSCC);
    for(i = 0; i < totalSCC; i++) {
        for(j = 0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }
    return 0;
}
