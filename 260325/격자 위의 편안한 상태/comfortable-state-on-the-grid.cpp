#include <iostream>
#include <string>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    int n,m;
    int grid[100][100];

    cin >> n >> m;

    for (int i = 0; i<m; i++) {
        int y,x;
        cin >> y >> x;
        y -= 1;
        x -= 1;
        grid[y][x] = 1;
        int cnt = 0;

        for (int j = 0; j<4; j++) {
            int ny = y + dy[j];
            int nx = x + dx[j];

            //cout << ny << " " << nx << '\n';

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] != 1) continue;
            cnt++;
        }

        /*for (int r = 0; r<n; r++) {
            for (int c = 0; c<n; c++) cout << grid[r][c] << " ";
            cout << '\n';
        }*/

        if (cnt == 3) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    // Please write your code here.

    return 0;
}