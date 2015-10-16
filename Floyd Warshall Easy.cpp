#include <bits//stdc++.h>

using namespace std;
#define INF 999999
#define sz 105
int dist[sz][sz];
int n, e;

void ini() {
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            dist[i][j] = INF;
            if(i==j)
                dist[i][i] = 0;

    }
}

int main()
{
    cin>>n>>e;
    while(e--){
        int i , j, w;
        cin>>i>>j>>w;
        dist[i][j] = w;
    }
    int i, j, k;
    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return 0;
}
