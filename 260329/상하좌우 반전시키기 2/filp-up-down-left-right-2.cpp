#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int n,m;
vector<vector<int>> grid;
int dy[5] = {0,-1,0,1,0};
int dx[5] = {0,0,1,0,-1};

void change_grid(int y, int x, vector<vector<int>> &grid) {
    for (int i = 0; i<5; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1) continue;
        if (grid[ny][nx] == 1) grid[ny][nx] = 0;
        else grid[ny][nx] = 1;
    }
}

int check_grid(vector<vector<int>> board, int click) {
    for (int y = 1; y<n; y++) {
        for (int x = 0; x<m; x++) {
            if (board[y-1][x] == 0) {
                change_grid(y,x,board);
                click++;
            }
        }
    }

    for (int y = 0; y<n; y++) {
        for (int x = 0; x<m; x++) {
            if (board[y][x] == 0) return INT_MAX;
        }
    }

    return click;
}

int main() {
    cin >> n >> m;
    grid = vector<vector<int>> (n, vector<int>(m));
    int minclick = INT_MAX;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> grid[i][j];
    }
    
    for (int i = 0; i<m; i++) {
        //non-click
        int click = check_grid(grid,0);
        minclick = min(click, minclick);
        //click
        change_grid(0,i,grid);
        click = check_grid(grid,1);
        minclick = min(click, minclick);
        change_grid(0,i,grid);
    }

    cout << minclick;
    return 0;
}