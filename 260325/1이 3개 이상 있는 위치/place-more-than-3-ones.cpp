#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int grid[100][100];
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int ans = 0;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            //check
            int cnt = 0; 
            for (int d = 0; d<4; d++) {
                int y,x;
                y = i + dy[d];
                x = j + dx[d];

                if (y < 0 || y > n-1 || x < 0 || x > n-1) continue;
                if (grid[y][x] == 1) cnt++;
            }
            if (cnt >= 3) ans++;
        }
    }
    // Please write your code here.
    cout << ans;

    return 0;
}