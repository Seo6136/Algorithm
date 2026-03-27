#include <iostream>
using namespace std;

int n, m;
int maze[100][100];
int dp[100][100];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 0) continue;
            if (i > 0 && dp[i - 1][j]) dp[i][j] = 1;
            if (j > 0 && dp[i][j - 1]) dp[i][j] = 1;
        }
    }

    cout << dp[n - 1][m - 1];
    return 0;
}