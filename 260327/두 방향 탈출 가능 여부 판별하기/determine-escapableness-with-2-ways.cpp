#include <iostream>
#include <vector>

using namespace std;

int n, m;
int maze [100][100];
bool flag;
int dy[2] = {1,0};
int dx[2] = {0,1};

void dfs(int y, int x, vector<vector<char>> visited) {
    if (y == n-1 && x == n-1) flag = true;
    if (flag) return;

    for (int i = 0; i<2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        //cout << ny << " " << nx << '\n';

        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || maze[ny][nx] == 0 || visited[ny][nx] == 1) continue;
        visited[ny][nx] = 1;
        dfs(ny,nx,visited);
        visited[ny][nx] = 0;
        if (flag) return;
    }
}

int main() {
    cin >> n >> m;
    flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j<m; j++) cin >> maze[i][j];
    }

    vector<vector<char>> visited (n, vector<char>(m,0));

    // Please write your code here.
    visited[0][0] = 1;
    dfs(0,0,visited);

    if (flag) cout << 1;
    else cout << 0;

    return 0;
}
