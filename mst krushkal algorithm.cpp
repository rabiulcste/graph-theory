#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100000

// union find array
int pr[MAXN];

int findset(int r) {
    if(pr[r] == r) return r; // x is the root
    return findset(pr[r]);
}

// প্রথমে প্রত্যেকটা নোডকে আলাদা আলাদা সেটে রাখবো
void makeset(int n)
{
    for(int i = 0; i < n; i++) pr[i] = i;
}
// a structure to represent an edge
struct Edge {
    // the two endpoints and the weight
    int u, v, w;
    // a comparator that stores by least wight
    bool operator<(const Edge &p) const
    {
        return w < p.w;
    }
};

vector<Edge> e;

int krushkal(int n)
{
    // sort the edges
    sort(e.begin(), e.end());

    makeset(n); // create set

    int count = 0, sum = 0;
    for(int i = 0; i < (int)e.size(); i++){
        int u = findset(e[i].u);
        int v = findset(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            count++;
            sum += e[i].w;
            if(count==n-1) break;
        }
    }
    return sum;
}
int main()
{
    int n, m;
    // the number of nodes and edges
    cin>>n>>m;

    for(int i = 0; i < m; i++) {
        cin>>e[i].u>>e[i].v>>e[i].w;
    }

    int res = krushkal(n);
    cout<<res<<endl;
    return 0;
}

