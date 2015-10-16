#include <bits//stdc++.h>

using namespace std;
#define mx 1000
struct node {
    int r, c, cost;
    node() {
    }

    node(int _r, int _c, int _cost) {
        r = _r;
        c = _c;
        cost = _cost;
    }

    bool operator < (node X) const {
        return cost>X.cost;
    }
};

int g[mx][mx], dist[mx][mx];
bool visited[mx][mx];

int main()
{
    int test, R, C, r, c;
    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    scanf("%d", &test);

    for(int tc = 0; tc < test; tc++) {
        cin>>R>>C;

        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                scanf("%d", &g[i][j]);
        for(int i=0; i<R; i++) fill(dist[i], dist[i]+C, -1);
        for(int i=0; i<R; i++) fill(visited[i], visited[i]+C, false);
        priority_queue<node> Q;
        node aux;
        Q.push(node(0, 0, g[0][0]));
        dist[0][0] = g[0][0]; // 0

        while(1) {
            aux = Q.top();
            Q.pop();

            if(visited[aux.r][aux.c]) continue;
            visited[aux.r][aux.c] = true;

            if(aux.r==R-1 && aux.c==C-1) {
                printf("%d\n", aux.cost);
                break;
            }

            for(int i=0; i<4; i++) {
                r = aux.r + dr[i];
                c = aux.c + dc[i];

                if(r>=0 && r<R && c>=0 && c<C && (dist[r][c]==-1 || dist[r][c]>dist[aux.r][aux.c]+g[r][c])) {
                    dist[r][c] = dist[aux.r][aux.c] + g[r][c];
                    Q.push(node(r, c, dist[r][c]));
                }
            }
        }
    }
    return 0;
}
