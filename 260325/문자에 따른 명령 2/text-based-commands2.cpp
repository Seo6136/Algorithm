#include <iostream>

using namespace std;

int main() {
    string n;
    cin >> n;
    int x,y;
    x = 0;
    y = 0;
    //0 up, 1 right, 2 down, 3 left 
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    int dir = 0;
    for (char c : n) {
        if (c == 'L') {
            dir -= 1;
            if (dir < 0) dir += 4;
        }
        else if (c == 'R') {
            dir += 1;
            if (dir > 3) dir -= 4;
        }

        else {
            y += dy[dir];
            x += dx[dir];
        }
    }

    // Please write your code here.
    cout << x << " " << y;

    return 0;
}