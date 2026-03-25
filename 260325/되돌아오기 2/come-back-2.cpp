#include <iostream>

using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    string n;
    cin >> n;
    int dir = 0;
    int y = 0;
    int x = 0;
    int cnt = 0;
    bool moved = false;

    for (char c:n) {
        cnt++;

        if (c == 'F') {
            y += dy[dir];
            x += dx[dir];
            moved = true;
        }
        else if (c == 'R') {
            dir += 1;
            if (dir > 3) dir -= 4;
        }
        else {
            dir -= 1;
            if (dir < 0) dir += 4;
        }

        if (y == 0 & x == 0 && moved) {
            cout << cnt;
            return 0;
        }
    }

    cout << -1;
    // Please write your code here.

    return 0;
}