#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n,m,seq;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<vector<int>> grid;
vector<vector<int>> visited;
struct inf {
    int y,x,dis;
};

int bfs(int y, int x, int k) {
    //cout << "at " << y << " " << x << '\n';
    int cost = k*k + (k+1)*(k+1);
    int cnt = 0;

    queue<inf> q;
    q.push({y,x,0});
    visited[y][x] = seq;

    while(!q.empty()) {
        auto now = q.front();
        int y = now.y;
        int x = now.x;
        int dis = now.dis + 1;
        if (grid[y][x] == 1) cnt++;

        //cout << "visit " << y << " " << x << '\n';
        q.pop();
        if (dis > k) continue;

        for (int i = 0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || visited[ny][nx] == seq) continue;
            //cout << "push " << ny << " " << nx << '\n';
            q.push({ny,nx,dis});
            visited[ny][nx] = seq;
        }
    }
    //cout << "cnt " << cnt << '\n';
    seq++;
    int gain = cnt * m;

    //cout << "cost " << cost << " gain " << gain << '\n';

    if (gain >= cost) return cnt;
    else return 0;

}

int main() {
    cin >> n >> m;

    grid = vector<vector<int>> (n, vector<int>(n));
    visited = vector<vector<int>>(n, vector<int>(n,0));
    seq = 1;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> grid[i][j];
    }

    int mx = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<n; k++) {
                //cout << "dis " << k << '\n';
                int num = bfs(i,j,k);
                mx = max(mx,num);
            }
        }
    }

    cout << mx;
    // Please write your code here.
    return 0;
}