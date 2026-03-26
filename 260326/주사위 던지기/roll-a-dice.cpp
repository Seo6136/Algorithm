#include <iostream>
#include <vector>

using namespace std;

int n,m;
int x, y;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int nd[4] = {5,3,2,4};


int main() {
    cin >> n >> m >> y >> x;
    y-=1;
    x-=1;
    int sum = 0;
    vector<vector<int>> grid(n,vector<int>(n,0));
    int now = 6;
    int r = 0;
    int c = 0;

    grid[y][x] = 6;
    int nowval = 6;

    for (int i = 0; i < m; i++) {
        char inst;
        cin >> inst;

        int dir;
        if (inst == 'U') dir = 0;
        else if (inst == 'R') dir = 1;
        else if (inst == 'D') dir = 2;
        else dir = 3;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;

        int nn;

        if (dir == 0) { // U
            nn = nd[0];
            nd[0] = 7 - nowval;
            nd[2] = nowval;
        }
        else if (dir == 2) { // D
            nn = nd[2];
            nd[0] = nowval;
            nd[2] = 7 - nowval;
        }
        else if (dir == 1) { // R
            nn = nd[1];
            nd[1] = 7 - nowval;
            nd[3] = nowval;
        }
        else { // L
            nn = nd[3];
            nd[1] = nowval;
            nd[3] = 7 - nowval;
        }

        y = ny;
        x = nx;
        nowval = nn;
        grid[y][x] = nn;
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) sum += grid[i][j];
    }

    cout << sum;

    // Please write your code here.

    return 0;
}
