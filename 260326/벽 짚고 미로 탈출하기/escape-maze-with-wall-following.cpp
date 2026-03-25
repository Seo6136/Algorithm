#include <iostream>

using namespace std;

int n, y, x;
char grid[100][100];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
bool visited[100][100][4];

int main() {
    cin >> n >> y >> x;
    y -= 1;
    x -= 1;
    int oy = y;
    int ox = x;
    int dir = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    int sec = 0;

    // Please write your code here.
    while (1) {
        //cout << y << " " << x << " " << sec << " " << dir << '\n';
        if (visited[y][x][dir]) {
            cout << -1;
            return 0;
        }
        visited[y][x][dir] = true;
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
            cout << sec+1;
            return 0;
        }

        if (grid[ny][nx] == '#') {
            dir -= 1;
            if (dir < 0) dir += 4;
            continue;
        }
        else {
            int tdir = dir+1;
            if (tdir > 3) tdir -= 4;
            int nny = ny + dy[tdir];
            int nnx = nx + dx[tdir];
            if (grid[nny][nnx] == '.') {
                dir += 1;
                if (dir > 3) dir -= 4;
                y = nny;
                x = nnx;
                sec++;
            } 
            else {
                y = ny;
                x = nx;
            }
        }
        sec++;
    }


    return 0;
}
