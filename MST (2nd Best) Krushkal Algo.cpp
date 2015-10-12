#include <bits//stdc++.h>
using namespace std;
#define MAXN 110
#define INF 999999

int pr[MAXN], edgetaken[MAXN], etl;

int findset(int r) {
    if(pr[r] == r) return r;
    return findset(pr[r]);
}

void makeset(int n)
{
    for(int i = 0; i <= n; i++) pr[i] = i;
}

struct Edge {

    int u, v, w;
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

    int sum = 0, ans = -1;
    etl = 0;
    for(int i = 0; i < (int)e.size(); i++){
        int u = findset(e[i].u);
        int v = findset(e[i].v);
        if(u!=v)
        {
            pr[u] = v;
            edgetaken[etl++] = i;
            sum += e[i].w;
            if(etl==n-1) break;
        }
    }
    if(etl==n-1) ans = sum;
    return ans;
}
int main()
{
    int n, m, u, v, w, miin, cnt, sum, test, kase;
    scanf("%d", &test); // number of test-cases
    for(kase=1; kase<=test; kase++){
            cin>>n>>m; // nodes and edges
            e.clear();
            memset(edgetaken, 0, sizeof(edgetaken));
            for(int i = 0; i < m; i++) {
                cin>>u>>v>>w;
                Edge data;
                data.u = u;
                data.v = v;
                data.w = w;
                e.push_back(data);
            }
        printf("Case #%d : ", kase);
        int res = krushkal(n);
        if(res == -1) cout<<"No way"<<endl; // No MST possible
        else
        {
            miin = INF;
            for(int j=0; j<etl; j++)
            {
                makeset(n);
                cnt=0;
                sum=0;

            for(int i = 0; i < (int)e.size(); i++) {
                if(edgetaken[j]!=i){
                int u = findset(e[i].u);
                int v = findset(e[i].v);

                if(u!=v)
                {
                    pr[u] = v;
                    cnt++;
                    sum += e[i].w;
                    if(cnt==n-1) break;
                }
                }
            }
            // cout<<sum<<endl;

            if(cnt==n-1 && miin>sum) miin = sum;

        }
            if(miin==INF)
                printf("No second way\n"); // There is no 2nd MST
            else printf("%d\n", miin); // Value of 2nd Best MST
        }
    }
    return 0;
}
