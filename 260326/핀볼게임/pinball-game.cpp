#include <iostream>

using namespace std;

int n,dir;
int grid[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int out_time(int y, int x, int dir) {
    int sec = 0;
    while (1) {
        sec++;
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny > n-1 || ny < 0 || nx > n-1 || nx < 0) {
            return sec;
        }

        if (grid[ny][nx] == 1) {
            if (dir == 0 || dir == 2) {
                dir += 1;
                if (dir > 3) dir -= 4;
            }
            else {
                dir -= 1;
                if (dir < 0) dir += 4;
            }
        }
        else if (grid[ny][nx] == 2) {
            if (dir == 0 || dir == 2) {
                dir -= 1;
                if (dir < 0) dir += 4;
            }
            else {
                dir += 1;
                if (dir > 3) dir -= 4;
            }
        }
        y = ny;
        x = nx;
    }
}

int main() {
    cin >> n;
    int maxsec = 0;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    //up
    for (int i = 0; i<n; i++) {
        int dir = 2;
        int y = -1;
        int x = i;
        int sec = out_time(y,x,dir);
        if (sec > maxsec) maxsec = sec;
    }
    //left
    for (int i = 0; i<n; i++) {
        int dir = 1;
        int y = i;
        int x = -1;
        int sec = out_time(y,x,dir);
        if (sec > maxsec) maxsec = sec;
    }
    //down
    for (int i = 0; i<n; i++) {
        int dir = 0;
        int y = n-1;
        int x = i;
        int sec = out_time(y,x,dir);
        if (sec > maxsec) maxsec = sec;
    }
    //right 
    for (int i = 0; i<n; i++) {
        int dir = 3;
        int y = i;
        int x = n-1;
        int sec = out_time(y,x,dir);
        if (sec > maxsec) maxsec = sec;
    }

    cout << maxsec;
    return 0;
}
