#include <bits//stdc++.h>
using namespace std;

int main()
{
    int ans[10], b[10], g[10], c[10];
    while(scanf("%d %d %d %d %d %d %d %d %d",
                &b[1], &g[1], &c[1], &b[2], &g[2],
                &c[2], &b[3], &g[3], &c[3])==9){

        ans[1] = b[2]+b[3]+c[1]+c[3]+g[1]+g[2];
        ans[2] = b[2]+b[3]+g[1]+g[3]+c[1]+c[2];
        ans[3] = c[2]+c[3]+b[1]+b[3]+g[1]+g[2];
        ans[4] = c[2]+c[3]+g[1]+g[3]+b[1]+b[2];
        ans[5] = g[2]+g[3]+b[1]+b[3]+c[1]+c[2];
        ans[6] = g[2]+g[3]+c[1]+c[3]+b[1]+b[2];



        int mini = ans[1];
        for(int i=2; i<=6; i++){
            if(ans[i]<mini)
                mini = ans[i];
        }

        if(ans[1]==mini) printf("BCG");
        else if (ans[2]==mini) printf("BGC");
        else if (ans[3]==mini) printf("CBG");
        else if (ans[4]==mini) printf("CGB");
        else if (ans[5]==mini) printf("GBC");
        else if (ans[6]==mini) printf("GCB");


        printf(" %d\n", mini);
    }
    return 0;
}
