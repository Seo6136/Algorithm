#include <iostream>

using namespace std;

int n,t,dir, y, x;
int grid[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> t;

    char d;
    cin >> y >> x >> d;

    y -= 1;
    x -= 1;

    if (d == 'U') dir = 0;
    else if (d == 'R') dir = 1;
    else if (d == 'D') dir = 2;
    else dir = 3;
    // Please write your code here.
    for (int i = 0; i<t; i++) {
        //cout << y << " " << x << '\n';
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
            dir += 2;
            if (dir > 3) dir -= 4;
            else if (dir < 0) dir += 4;
        }
        else {
            y = ny;
            x = nx;
        }
    }

    cout << y + 1 << " " << x + 1;

    return 0;
}