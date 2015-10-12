#include <bits//stdc++.h>

using namespace std;

int visited[1000];
vector<int>edge[1000];
vector<int>cost[1000];

struct data
{
    int v, w;
    bool operator < (data p) const {
        return w > p.w;
    }
};

int mstPrims(int src, int n)
{
    memset(visited, 0, sizeof(visited));
    priority_queue<data>pq;
    int u, v, p, sum = 0;

    for(int i = 0; i < n-1; i++)
    {
        u = src;
        visited[src] = 1;

        for(int j = 0; j < edge[u].size(); j++)
        {
            v = edge[u][j];
            if(visited[v] == 0)
            {
                data D;
                D.v = v;
                D.w = cost[u][j];
                pq.push(D);
            }
        }

        while(visited[src])
        {
            data T = pq.top(); pq.pop();
            src = T.v;
            p = T.w;
        }
    }
    sum += p;
    return sum;
}

int main()
{
    int n, e, u, v, w;
    scanf("%d %d", &n, &e);
    for(int i = 0; i < e; i++)
    {
        cin>>u>>v>>w;
        edge[u].push_back(v);
        edge[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }

    cout<<mstPrims(1, n);
    return  0;
}
