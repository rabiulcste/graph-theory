#define M 55
vector<int> ans, depends[M];

// depends[i] contains all the items that item i is depending
// when taken[i] = 1, that means it's already taken

void take(int p)
{
    if(!taken[p]) {
        // i am taking all the items that i should take before p
        for(int i=0; i<depends[p].size(); i++)
            take(depends[p][i]);
        ans.push_back(p); // now i can take it
        taken[p] = 1;
    }
}

int main()
{
    // input routine

    for(int i=0; i<n; i++) take(i);
    for(int i=0; i<n; i++) printf("%d\n", ans[i]);

    return 0;
}
