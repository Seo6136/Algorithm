#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<vector<int>> grid (n, vector<int>(n,0));

    int dir = 3;
    int y = n-1;
    int x = n-1;

    for (int i = n*n; i>=1; i--) {
        grid[y][x] = i;
        /*
        for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cout << grid[i][j] << " ";
        cout << '\n';
        }*/

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        //cout << ny << " " << nx << '\n';

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] != 0) {
            dir += 1;
            if (dir > 3) dir -= 4; 
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        
        y = ny;
        x = nx;
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }
    return 0;
}