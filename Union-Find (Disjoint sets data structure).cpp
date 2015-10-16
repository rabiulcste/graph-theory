#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 10000
// union find array
int pr[MAXN];

int findset(int r) {
    if(pr[r] == r) return r; // x is the root
    return findset(pr[r]);
}

/* Find with path compression
int FIND(int x) {
    if(uf[x] !=uf[uf[x]]) uf[x] = FIND(uf[x]);
        return uf[x];
}
*/
void UNION(int x, int y) {
    pr[findset(x)] = findset(y);
}

// a structure to represent an edge
struct Edge {
    // the two endpoints and the weight
    int u, v;
};

vector <Edge> e;

int isCycle(int n)
{
    // initialize the union find array
    for(int i = 0; i < n; i++)pr[i] = i;
    for(int i =0; i < (int)e.size(); i++)
    {
        int u = findset(e[i].u);
        int v = findset(e[i].v);

        if(u == v)
            return 1;
        UNION(u, v);
    }
    return 0;
}

int main()
{
    int n, m;
    cin>>n>>m;
     for(int i = 0; i < m; i++) {
        cin>>e[i].u>>e[i].v;
    }

    if(isCycle(n))
        cout<<"Graph contains cycle."<<endl;
    else
        cout<<"No cycle detected"<<endl;
}
