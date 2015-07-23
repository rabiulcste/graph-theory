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

    for(int i = 1; i <= node; i++) d[i] = 99999;
        d[src] = 0; // distance to source is 0
    for(int i = 1; i <= edge; i++)
    {
        cin>>edge_u[i]>>edge_v[i]>>edge_cost[i];
    }
    bool neg_cycle = false;
    for(int step = 1; step <= node; step++)
    {
        bool updated = false;
        for(int i = 1; i <= edge; i++)
        {
            int u = edge_u[i], v = edge_v[i], w = edge_cost[i];
           if(d[u] + edge_cost[i] < d[v])
           {
               updated = true;
               if(step==node) neg_cycle = true; //if we can update in n'th step, there is a negative cycle
              d[v] = d[u] + edge_cost[i];
           }
        }
        if(updated == false) break; // if we can't update in a or any step, no need to try anymore
    }

    if(neg_cycle == false)
    {
        printf("Distance to node: \n");
        for(int i = 1; i <= node; i++) cout<<i<<"  "<<d[i]<<endl;
    }
    else
        cout<<"Negative cycle detected\n";
    return 0;
}
