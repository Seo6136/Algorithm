#include <iostream>

using namespace std;

int n, m;
int grid[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> m;
    int num = 1;
    int y = 0;
    int x = 0;
    int dir = 1;

    // Please write your code here.
    for (int i = 1; i<=n*m; i++) {
        grid[y][x] = i;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || grid[ny][nx] != 0) {
            dir += 1;
            if (dir > 3) dir -= 4;
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        y = ny;
        x = nx;

        /*for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cout << grid[i][j] << " ";
        cout << '\n';
        }*/

    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }

    return 0;
}