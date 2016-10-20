#include<bits//stdc++.h>
using namespace std;

static int dr[] = {-1, 0, 0, 1};
static int dc[] = {0, -1, 1, 0};
int m, n;
bool vis[51][51];
char M[51][51];

void DFS(int row, int col)
{
    vis[row][col] = true;
    cout << row <<"  "<<col << "\n";
    for(int i=0;i<4;i++)
    {
        int x = row + dr[i];
        int y = col + dc[i];
        if(x < 0 && x >= m && y < 0 &&y >= n) continue;
        if(M[x][y] == '.' && !vis[x][y])
        {
            DFS(x, y);
        }
    }
}


int main() {
    scanf("%d %d", &m, &n);
    char ch = getchar();
    for(int i=0; i<m; i++) {
        scanf("%s", M[i]);
    }

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(M[i][j] == '.' && !vis[i][j]) DFS(i, j), cout <<"\n";
        }
    }
    return 0;
}

//Input
//5 4
//#...
//#.#.
//.#..
//...#
//.#.#
