#include <iostream>
#include <climits>
#include <queue>

using namespace std;

struct status{
    int y,x,bw;
};

int grid[100][100];
int dis[100][100];
int n,k,r1,c1,r2,c2;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> k;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> grid[i][j];
            dis[i][j] = INT_MAX;
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;

    r1-=1;
    c1-=1;
    r2-=1;
    c2-=1;

    queue<status> q;

    q.push({r1,c1,0});
    dis[r1][c1] = 0;

    while(!q.empty()) {
        auto s = q.front();
        int y = s.y;
        int x = s.x;
        int w = s.bw;
        int d = dis[y][x];
        q.pop();

        for (int i = 0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            int nd = d+1;
            int nw = w;

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || dis[ny][nx] <= nd) continue;

            if (grid[ny][nx] == 1) {
                nw += 1;
                if (nw > k) continue;
            }
            dis[ny][nx] = nd;
            q.push({ny,nx,nw});
        }
    }


    if (dis[r2][c2] == INT_MAX) cout << -1;
    else cout << dis[r2][c2];
    return 0;
}