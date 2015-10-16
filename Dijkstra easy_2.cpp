#include <bits//stdc++.h>
#define mx 10001
#define INF 52312424

using namespace std;

int no, e, dist[mx], cost[mx][mx];
vector<int>G[mx];

struct node
{
   int x, c;
   node(int d, int f) {
       x = d;
       c = f;
   }
   bool operator < (const node &p) const
   {
       return c>p.c;
   }
};

void dijkstra(int s)
{
    for(int i=1; i<=no; i++)
    {
        dist[i] = INF;
    }

    priority_queue<node>Q;
    dist[s] = 0;
    Q.push(node(s, dist[s]));

    while(!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int ux = top.x;
        for(int i=0; i<G[ux].size(); i++) {
            int vx = G[ux][i];

            if(dist[vx]>dist[ux]+cost[ux][vx]){
                dist[vx] = dist[ux] + cost[ux][vx];
                Q.push(node(vx, dist[vx]));
            }
        }
    }
}

int main()
{
    cin>>no>>e;
    for(int i=0; i<e; i++) {
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back(v);
        G[v].push_back(u); // bidirectional
        cost[v][u] = w;
    }
    int src, end;
    cin>>src>>end;
    dijkstra(src);
    cout<<dist[end]<<endl;
    return 0;
}
