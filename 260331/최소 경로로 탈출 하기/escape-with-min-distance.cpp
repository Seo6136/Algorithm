#include <iostream>
#include <queue>

using namespace std;

int n, m;
int a[100][100];
int visited[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            visited[i][j] = 10000;
        }
    }


    queue<pair<int,int>> q;

    q.push({0,0});
    visited[0][0] = 0;

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int d = visited[y][x];
        q.pop();

        for (int i = 0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nd = d + 1;

            if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || visited[ny][nx] == 1 || a[ny][nx] == 0 || nd >= visited[ny][nx]) continue;
            
            visited[ny][nx] = nd;
            q.push({ny,nx});
        }
    }

    

    if (visited[n-1][m-1] == 10000) cout << -1;
    else cout << visited[n-1][m-1];

    return 0;
}
