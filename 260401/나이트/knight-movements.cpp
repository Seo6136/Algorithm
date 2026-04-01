#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

using namespace std;

static int n,r1,c1,r2,c2;
static int dy[8] = {-1,-2,-2,-1,1,2,2,1};
static int dx[8] = {-2,-1,1,2,-2,-1,1,2};

int main() {
    cin >> n >> r1 >> c1 >> r2 >> c2;
    r1 -= 1;
    c1 -= 1;
    r2 -= 1;
    c2 -= 1;

    vector<vector<int>> grid (n, vector<int> (n,INT_MAX));

    queue<pair<int,int>> q;

    q.push({r1,c1});
    grid[r1][c1] = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int nd = grid[y][x] + 1;
        q.pop();

        for (int i = 0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] <= nd) continue;
            q.push({ny,nx});
            grid[ny][nx] = nd;
        }
    }

    if (grid[r2][c2] == INT_MAX) cout << -1;
    else cout << grid[r2][c2];

    return 0;
}