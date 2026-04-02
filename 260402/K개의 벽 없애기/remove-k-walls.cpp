#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

struct Status {
    int y, x, bw;
};

int n, k, r1, c1, r2, c2;
int grid[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    vector<vector<vector<int>>> dis(
        n, vector<vector<int>>(n, vector<int>(k + 1, INT_MAX))
    );

    queue<Status> q;
    q.push({r1, c1, 0});
    dis[r1][c1][0] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        int y = cur.y;
        int x = cur.x;
        int w = cur.bw;
        int d = dis[y][x][w];

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nd = d+1;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

            int nw = w;
            if (grid[ny][nx] == 1) nw++;

            if (nw > k) continue;
            if (dis[ny][nx][nw] <= nd) continue;

            dis[ny][nx][nw] = nd;
            q.push({ny, nx, nw});
        }
    }

    int ans = INT_MAX;
    for (int w = 0; w <= k; w++) {
        ans = min(ans, dis[r2][c2][w]);
    }

    cout << (ans == INT_MAX ? -1 : ans);
    return 0;
}