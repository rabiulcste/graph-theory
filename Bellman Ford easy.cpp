#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define pi acos(-1)
using namespace std;

#define MAXE 10000
#define MAXN 100

int main()
{
    int node, edge, src;
    int d[MAXN], edge_u[MAXE], edge_v[MAXE], edge_cost[MAXE];
    cin>>node>>edge>>src;

    for(int i = 1; i < node; i++) d[i] = 99999;
        d[src] = 0; // distance to source is 0
    for(int i = 0; i < edge; i++)
    {
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    }
    bool neg_cycle = false;
    for(int step = 0; step < node-1; step++)
    {
        bool updated = false;
        for(int i = 0; i < edge; i++)
        {
            int u = edge_u[i], v = edge_v[i], w = edge_cost[i];
           if(d[u] + edge_cost[i] < d[v])
           {
              d[v] = d[u] + edge_cost[i];
           }
        }
    }

    for(int i = 0; i < edge; i++ ) {
            int u = edge_u[i], v = edge_v[i], w = edge_cost[i];
            if(d[u] + edge_cost[i] < d[v])
            {
               neg_cycle = true;
            }
        }

    if(!neg_cycle)
    {
        printf("Distance to node: \n");
        for(int i = 0; i < node; i++) cout<<i<<"  "<<d[i]<<endl;
    }
    else
        cout<<"not possible\n";
    return 0;
}
