#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m, k;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> m >> k;
    int sec = 0;

    int y = 0;
    int x = 0;
    vector<vector<int>> grid(n, vector<int>(n,0));
    grid[0][0] = 1;
    deque<pair<int,int>> worm;
    worm.push_front({0,0});

    //put apple
    for (int i = 0; i<m; i++) {
        int y,x;
        cin >> y >> x;
        y-=1;
        x-=1;

        grid[y][x] = 2;
    }

    for (int i = 0; i<k; i++) {
        char dir;
        int dis;
        int dn;
        cin >> dir >> dis;

        if (dir == 'U') dn = 0;
        else if (dir == 'R') dn = 1;
        else if (dir == 'D') dn = 2;
        else dn = 3;

        for (int j = 0; j<dis; j++) {
            /*for (int r = 0; r<n; r++) {
                for (int c = 0; c<n; c++) cout << grid[r][c] << " ";
                cout << '\n';
            }
            cout << '\n';*/
            sec++;
            grid[worm.back().first][worm.back().second] = 0;
            int ny = y + dy[dn];
            int nx = x + dx[dn];
            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] == 1) {
                cout << sec;
                return 0;
            }
            y = ny;
            x = nx;
            worm.push_front({y,x});

            if (grid[y][x] == 2) {
                grid[y][x] = 1;
                grid[worm.back().first][worm.back().second] = 1;
                continue;
            };
            worm.pop_back();
            grid[y][x] = 1;
        }
    }

    // Please write your code here.
    cout << sec;
    return 0;
}
