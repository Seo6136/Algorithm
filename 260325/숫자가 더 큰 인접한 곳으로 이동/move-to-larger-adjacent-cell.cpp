#include <iostream>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int grid[100][100];

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    int y,x;
    cin >> y >> x;
    y -= 1;
    x -= 1;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> grid[i][j];
    }

    while (1) {
        int now = grid[y][x];
        bool flag = false;

        cout << now << " ";

        for (int i = 0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;
            if (grid[ny][nx] > now) {
                y = ny;
                x = nx;
                flag = true;
                break;
            }
        }

        if (!flag) break;

    }
    return 0;
}