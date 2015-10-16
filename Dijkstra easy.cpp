#include <bits//stdc++.h>

using namespace std;
#define mx 20010
vector<int> edge[mx], cost[mx];
const int infinity = 1000000000;

struct data {
    int city, dist;
    bool operator < ( const data& p ) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination) {
    int d[mx];
    for(int i=0; i<=mx; i++) d[i] = infinity;

    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push(u);
    d[source] = 0;

    while(!q.empty()) {
        u = q.top(); q.pop();
        int ucost = d[u.city];

        for(int i=0; i<edge[u.city].size(); i++) {
            v.city = edge[u.city][i], v.dist = cost[u.city][i] + ucost;
            // relaxing :)
            if(d[v.city] > v.dist) {
                d[v.city] = v.dist;
                q.push( v );
            }
        }
    }
    return d[destination];
}

int main()
{
    int n, e, src, dist;
    while(scanf("%d %d", &n, &e)==2) {
        while(e--) {
                int u, v, w;
            cin>>u>>v>>w;
            edge[u].push_back(v);
            edge[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>src>>dist;
        int ans = dijkstra(src, dist);
        cout<<ans<<endl;
    }
    return 0;
}
