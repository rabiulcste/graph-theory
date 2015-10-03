int main()
{
    int n, e, u, v;
    //freopen("input.txt","r",stdin); //redirects standard input
    //freopen("output.txt","w",stdout); //redirects standard output
    while(scanf("%d", &n)==1){
            if(n==0)
            break;
            cin>>e;
        vector<int>adj[10000];

    for(int i=0; i<e; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    int colorArr[n];
    for(int i=0; i<n; i++)
        colorArr[i] = -1;
    colorArr[0] = 1;
    queue<int>Q;
    Q.push(0);
    int flag = 0;

    while(!Q.empty())
    {
        int u = Q.front();
            Q.pop();
        for(int i=0; i<adj[u].size(); i++) {
                int v = adj[u][i];
            if(colorArr[v] == -1) {
                if(colorArr[u] == 1)
                    colorArr[v] = 0;
                else
                    colorArr[v] = 1;
                    Q.push(v);
            }
            else {
                if(colorArr[v] == colorArr[u]) {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 1)
            break;
    }

    if(flag == 1)
        cout<<"NOT BICOLORABLE."<<endl;
    else
        cout<<"BICOLORABLE."<<endl;
    }
}
