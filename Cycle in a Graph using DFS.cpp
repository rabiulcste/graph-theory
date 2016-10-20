#include <bits//stdc++.h>
using namespace std;

#define WHITE -1 //  color[u] = White - for the "undiscovered" state
#define BLACK 1 //  color[u] = Gray - for the "discovered but not finished" state
#define GRAY 2 //  color[u] = Black - for the "finished" state

vector<int> g[10000];
int color[1000];
int parent[1000];  // predecessor
int flag = 0;
void dfs(int u) {
    color[u] = GRAY;   // color this as DFS_GRAY (temp) instead of DFS_BLACK
    for (int j = 0; j < (int)g[u].size(); j++) {
        int v = g[u][j];
        if (color[v] == WHITE) {    // Tree Edge, DFS_GRAY to DFS_WHITE
            parent[v] = u;          // parent of this children is me
            dfs(v);
        }
        else if (color[v] == GRAY && v != parent[u]) {  // not bidirectional and cycle exists
//            printf(" Back Edge (%d, %d) (Cycle)\n", u, v);
            flag = 1;
        }
//        else if (color[v] == BLACK)             // DFS_GRAY to DFS_BLACK
//            printf(" Forward/Cross Edge (%d, %d)\n", u, v);
    }
    color[u] = BLACK;     // after recursion, color this as DFS_BLACK (DONE)
}



int main() {
    int n, e;
    cin >> n >> e;
    memset(color, WHITE, sizeof(color));
    for(int i=0; i<n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
    if(flag == 1) cout << "Cycle Exists\n";
    else cout << "No cycle\n";
    return 0;
}
