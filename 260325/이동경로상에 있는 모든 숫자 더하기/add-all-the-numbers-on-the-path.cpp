#include <iostream>

using namespace std;

int n,t;
int grid[99][99];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> t;
    string s;
    cin >> s;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> grid[i][j];
    }
    // Please write your code here.
    int dir = 0;
    int y = n/2;
    int x = n/2;
    int sum = grid[y][x];

    for (char c : s) {
        //cout << y << " " << x << " " << sum << '\n';
        if (c == 'L') {
            dir -= 1;
            if (dir < 0) dir += 4;
        }
        else if (c == 'R') {
            dir += 1;
            if (dir > 3) dir -= 4;
        }
        else {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;
            y = ny;
            x = nx;
            sum += grid[y][x];
        }
    }

    cout << sum;
    return 0;
}
