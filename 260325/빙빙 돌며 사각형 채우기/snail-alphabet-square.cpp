#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    // Please write your code here.
    int n,m;
    cin >> n >> m;

    vector<vector<char>> grid (n, vector<char>(m,0));

    int dir = 1;
    int y = 0;
    int x = 0;
    int nc = 0 + 'A';

    for (int i = 0; i<n*m; i++) {
        grid[y][x] = nc;
        /*
        for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cout << grid[i][j] << " ";
        cout << '\n';
        }*/

        int ny = y + dy[dir];
        int nx = x + dx[dir];
        //cout << ny << " " << nx << '\n';

        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || grid[ny][nx] != 0) {
            dir += 1;
            if (dir > 3) dir -= 4; 
            ny = y + dy[dir];
            nx = x + dx[dir];
        }
        
        y = ny;
        x = nx;
        nc += 1;
        if (nc > 0 + 'Z') nc = 'A';
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }
    return 0;
}