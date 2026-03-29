#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n, m;
vector<vector<int>> grid;
int dy[5] = {0, -1, 0, 1, 0};
int dx[5] = {0, 0, 1, 0, -1};

void change_grid(int y, int x, vector<vector<int>>& board) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        board[ny][nx] ^= 1;
    }
}

int check_grid(vector<vector<int>> board, int click) {
    for (int y = 1; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (board[y - 1][x] == 0) {
                change_grid(y, x, board);
                click++;
            }
        }
    }

    for (int x = 0; x < m; x++) {
        if (board[n - 1][x] == 0) return INT_MAX;
    }

    return click;
}

int main() {
    cin >> n >> m;
    grid = vector<vector<int>>(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int minclick = INT_MAX;

    for (int mask = 0; mask < (1 << m); mask++) {
        auto board = grid;
        int click = 0;

        for (int x = 0; x < m; x++) {
            if (mask & (1 << x)) {
                change_grid(0, x, board);
                click++;
            }
        }

        minclick = min(minclick, check_grid(board, click));
    }

    if (minclick == INT_MAX) cout << -1;
    else cout << minclick;

    return 0;
}