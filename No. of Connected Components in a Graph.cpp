#include <bits//stdc++.h>

using namespace std;
#define pb push_back
typedef long long i64;
vector<int>G[100];
int seen[100];

void dfs(int u)
{
    seen[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
        if(!seen[G[u][i]]) dfs(G[u][i]);
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(!seen[i]){
            dfs(i);
            cnt++;
        }
    }
    printf("No. of connected components %d\n", cnt);
}
