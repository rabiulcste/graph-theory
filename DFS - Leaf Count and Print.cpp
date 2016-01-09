#include <cstdio>
#include <stack>
#include <list>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <cmath>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define Lowbit(x) ((x) & (-x))
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define pb push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define LC rt << 1, l, mid
#define RC rt << 1|1, mid + 1, r
#define LRT rt << 1
#define RRT rt << 1|1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int MAXN = 1000 + 10;
const int MOD = 1000007;
const int dir[][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
typedef pair<int, int> pii;
typedef vector<int>::iterator viti;
typedef vector<pii>::iterator vitii;

vector<int> edge[1000010];
vector<int> ans;

int dp[1000010];

void dfs(int u, int p)
{
    for(int i = 0; i < (int)edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(v == p) continue;
        dfs(v, u);
        dp[u] += dp[v];
        if(!dp[v]) {
            dp[u]++;
            ans.pb(v);
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
            int u, v;
        scanf("%d %d", &u, &v);
        edge[u].pb(v);
        edge[v].pb(u);
    }
    dfs(1, -1);

    printf("%d\n", dp[1]);
    sort(ans.begin(), ans.end());

    for(int i=0; i<(int)ans.size(); i++)
    {
        printf("%d", ans[i]);
        if(i == ans.size() - 1)
            printf("\n");
        else printf(" ");
    }
    return 0;
}
