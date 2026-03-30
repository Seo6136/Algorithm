#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int grid[20][20];
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};
vector<pair<int,int>> coord;

void change() {
    /*for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }
    cout << '\n';*/

    for (int i = 1; i<=n*n; i++) {
        auto c = coord[i];
        int y  = c.first;
        int x = c.second;
        int num = grid[y][x];
        int cy,cx;

        int mnum = 0;
        for (int i = 0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny > n-1 || ny < 0 || nx > n-1 || nx < 0 || grid[ny][nx] < mnum) continue;
            mnum = grid[ny][nx];
            cy = ny;
            cx = nx;
        }

        swap(coord[num], coord[mnum]);
        grid[y][x] = mnum;
        grid[cy][cx] = num;
        /*for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
        }
        cout << '\n';*/
    }

}

int main() {
    cin >> n >> m;
    coord = vector<pair<int,int>> (n*n+1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            coord[grid[i][j]] = {i, j};
        }
    }

    //for (auto c:coord) cout << c.first << " " << c.second << '\n';

    for (int i = 0; i < m; i++) {
        change();
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }
    
    return 0;
}
