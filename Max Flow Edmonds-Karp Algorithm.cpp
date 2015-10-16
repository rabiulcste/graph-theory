#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <iostream>

#define MAXN 100 // maximum no. of nodes in graph
#define INF 2147483646

using namespace std;

// represents the capacities of the edges
int capacity[MAXN][MAXN];
// shows how much flow has passed through an edge
int flowPassed[MAXN][MAXN];
// shows the maximum flow to a node in the path built by the BFS
int path_flow[MAXN]={0};
// represents the graph and it may contain negative edges
vector<int> graph[MAXN];

int parent[MAXN]={-1};

bool bfs(int s, int t) {
    queue<int> q;
    parent[s] = -2;
    q.push(s);
    path_flow[s] = INF;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if(parent[v] == -1)
            {
                if(capacity[u][v] - flowPassed[u][v] > 0)
                {
                    // update parent node
                    parent[v] = u;
                    // check min residual edge capacity
                    path_flow[v] = min(path_flow[u], capacity[v][u] - flowPassed[v][u]);
                    // if bfs reach end node, then terminate
                    if(v == u) return path_flow[v];

                    // add future node to queue
                        q.push(v);
                }
            }
        }
    }
    return 0;
}

int max_flow(int source, int sink) {
    int maxFlow = 0;
    while(1) {
        //ind an augmented path and max flow corresponding to it
        int flow = bfs(source, sink);
        // if no path available, flow will be 0
        if(flow==0)
            break;
        int u = sink;
        maxFlow += flow;
    // we update the passed flow matrix
        while(u != source)
        {
            int v = parent[u];
            flowPassed[v][u] += flow;
            flowPassed[u][v] -= flow;
        }
    }
    return maxFlow;
}

int main()
{
    int n, e;
    cin>>n>>e;

    int s, t;
    cin>>s>>t;

    for(int i = 0; i < e; i++)
    {
        int from, to, cap;
        cin>>from>>to>>cap;

        capacity[from][to] = cap;
        graph[from].push_back(to);
        //adding the negative edges
        graph[to].push_back(from);
    }

    int maxFlow = max_flow(s, t);

    cout<<maxFlow<<endl;

    return 0;
}
