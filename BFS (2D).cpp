#define mx 1002

int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
int mat[mx][mx], dist[mx][mx], color[mx][mx];
int row, col, dr, dc;

void bfs(int sx, int sy)
{
    memset(color, 0, sizeof(color));
    memset(dist, 0, sizeof(dist));

    int ux, uy, vx, vy, flag = 0;

    queue<int>Q;

    Q.push(sx);
    Q.push(sy);

    color[sx][sy] = 1;
    dist[sx][sy] = 0;

    while(!Q.empty())
    {
        ux = Q.front();
        Q.pop();
        uy = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++)
        {
            vx = ux + fx[i];
            vy = uy + fy[i];
            if((vx>=0 && vx<row) && (vy>=0 && vy<col) && mat[vx][vy] != 1) {
                if(!color[vx][vy])
                {
                    color[vx][vy] = 1;
                    dist[vx][vy] = dist[ux][uy] + 1;
                    Q.push(vx);
                    Q.push(vy);
                }
            }
            if(vx == dr && vy == dc)
            {
                printf("%d\n", dist[dr][dc]);
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
}
