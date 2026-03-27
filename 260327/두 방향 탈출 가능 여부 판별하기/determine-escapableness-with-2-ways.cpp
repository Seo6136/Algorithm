#include <iostream>
#include <vector>

using namespace std;

int n, m;
int maze [100][100];
bool flag;
int dy[2] = {1,0};
int dx[2] = {0,1};

void dfs(int y, int x) {
    if (y == n-1 && x == m-1) flag = true;
    if (flag) return;

    for (int i = 0; i<2; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        //cout << ny << " " << nx << '\n';

        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || maze[ny][nx] == 0) continue;
        dfs(ny,nx);
        if (flag) return;
    }
}

int main() {
    cin >> n >> m;
    flag = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j<m; j++) cin >> maze[i][j];
    }


    // Please write your code here.
    dfs(0,0);

    if (flag) cout << 1;
    else cout << 0;

    return 0;
}
