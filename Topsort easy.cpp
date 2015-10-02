int taken[55] = {};
int n, take[55][55], list[55], indegree[55];
int i, j, k;

// when take[a][b] = 1, that means a must come before b
// indegree[i] = number of items that must come before i
// taken[i] = 1, means we already have taken ith item

int invalid = 0;
for(i = 0; i<n; i++)
{
    for(j=0; j<n; j++) if(!indegree[j] && !taken[j]) {
        taken[j] = 1;
        list[i] = j;
        // in this step we are taking item j
        // we'd update the indegree[k] of items that depend on j
        for(k=0; k<n; k++)
            if(!taken[k] && take[j][k]) --indegre[k];
        break;
    }
    if(j==n) {
        invalid  = 1;
        break;
    }
}
if(invalid) printf("There is no solution\n");
else for(i=0; i<n; i++) printf("%d\n", list[i]);

