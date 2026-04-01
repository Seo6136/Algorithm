#include <iostream>

using namespace std;

int n,m,ans;
int grid[100][100];

bool check_row(int row) {
    for (int i = 0; i<=n-m; i++) {
        int num = grid[row][i];
        int cnt = 1;

        for (int j = i+1; j<n; j++) {
            if (num == grid[row][j]) {
                cnt++;
                if (cnt >= m) return true;
            }
            else break;
        }
        if (cnt >= m) return true;
    }
    return false;
}
bool check_ver(int row) {
    for (int i = 0; i<=n-m; i++) {
        int num = grid[i][row];
        int cnt = 1;

        for (int j = i+1; j<n; j++) {
            if (num == grid[j][row]) {
                cnt++;
                if (cnt >= m) return true;
            }
            else break;
        }
        if (cnt >= m) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    ans = 0;

    for (int i = 0; i<n; i++) {
        if (check_row(i)) ans++;
        if (check_ver(i)) ans++;
    }

    cout << ans;
    return 0;
}
