#define MAXN 100002
int dp[MAXN][5];
int par[MAXN];
vector<int>edges[MAXN];
int f(int u, int isGuard)
{
    if(edges[u].size()==0) return 0;
    if(dp[u][isGuard]!=-1) return dp[u][isGuard];
    int sum = 0;
    for(int i=0; i<(int)edges[u].size(); i++){
        int v = edges[u][i];

        if(v!=par[u]){
            par[v] = u;
            if(isGuard==0) sum += f(v, 1);
            else sum += min(f(v, 1), f(v,0));
        }
    }
    return dp[u][isGuard] = sum + isGuard;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int node, u, v;
    cin>>node;
    for(int i=1; i<node; i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int ans = 0;
    ans = min(f(1, 1), f(1, 0));
    cout<<ans<<endl;
    return 0;

}
