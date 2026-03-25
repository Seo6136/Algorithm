#include <iostream>

using namespace std;

int n,k;
char mirror [1000][1000];
int dy[4] = {1,0,-1,0};
int dx[4] = {0,-1,0,1};

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) cin >> mirror[i][j];
    }

    cin >> k;
    k -= 1;

    //0 down, 1 left, 2 up, 3 right
    int dir = k / n;

    int sy,sx;

    if (dir == 0) {
        sy = 0;
        sx = 0 + k % n;
    }
    else if (dir == 1) {
        sy = 0 + k % n;
        sx = n-1;
    }
    else if (dir == 2) {
        sy = n-1;
        sx = n-1 - k % n;
    }
    else {
        sy = n-1 - k % n ;
        sx = 0;
    }

    // Please write your code here.
    int cnt = 0;
    while (1) {
        cnt++;
        //cout << sy << " " << sx << '\n';

        if (mirror[sy][sx] == '/') {
            if (dir == 0) dir = 1;
            else if (dir == 1) dir = 0;
            else if (dir == 2) dir = 3;
            else dir = 2;
        }
        else {
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else dir = 0;
        }

        sy += dy[dir];
        sx += dx[dir];

        if (sy < 0 || sy > n-1 || sx < 0 || sx > n-1) break;
    }
    cout << cnt;
    return 0;
}