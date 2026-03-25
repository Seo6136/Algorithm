#include <iostream>

using namespace std;

int n;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n;
    int y = 0;
    int x = 0;

    char d;
    int dis,dir;
    int cnt = 0;
    for (int i = 0; i<n; i++) { 
        cin >> d >> dis;
        if (d == 'N') dir = 0;
        else if (d == 'E') dir = 1;
        else if (d == 'S') dir = 2;
        else dir = 3;

        for (int j = 0; j<dis; j++) {
            cnt += 1;
            y += dy[dir];
            x += dx[dir];
            if (y == 0 && x == 0) {
                cout << cnt;
                return 0;
            }
        }
    }
    cout << - 1;
}