#include <bits//stdc++.h>

using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))
int n, take[110][110], indegree[110], taken[110];



void topsort()
{
    vector<int> task;
    int i, j, k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(!indegree[j] && !taken[j]) {
                taken[j] = 1; // taken[j] = 1, means we already have taken i'th item
                task.push_back(j);
                for(k=1; k<=n; k++)
                    if(take[j][k])
                        --indegree[k];
                break;
            }
        }
        /*if( j == n ) {
                invalid = 1;
                break;
            }*/
    }
    // if(invalid) printf("There is no solution\n");
    // else for(i=0; i<n; i++) printf("%d\n", task[i]);
    cout<<task[0];
    for(int i=1; i<n; i++)
        cout<<" "<<task[i];
    cout<<endl;
    task.clear();
}

int main()
{
    int a, b, m;
    while(cin>>n>>m) // n = number of tasks and m = number of task order
    {
        if(n==0 && m==0) break;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            take[a][b] = 1; // that means a must come before b
            indegree[b]++;  // indegree[i] = number of items that must come before i
        }
        topsort();
        CLR(take);
        CLR(indegree);
        CLR(taken);
    }
    return 0;
}
