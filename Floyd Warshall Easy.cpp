#include <bits//stdc++.h>

using namespace std;

#define pf printf
#define clr(arr,val) memset(arr,val,sizeof(arr))
#define mp make_pair
#define pb push_back
#define inf (1<<30)-2
#define sz  103

typedef long long int ll;

int dist[sz][sz];
int no, edge;

void ini()
{
    for(int i=1; i<=no; i++)
        for(int j=1; j<=no; j++)
        {
            dist[i][j]=inf;
            if(i==j)
                dist[i][j]=0;
        }
}

int main()
{
    int i, j, k;
    cin>>no>>edge;
    ini();

    for(i=1; i<=edge; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
    }
        for(k=1; k<=no; k++)
            for(i=1; i<=no; i++)
                for(j=1; j<=no; j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    return 0;
}
