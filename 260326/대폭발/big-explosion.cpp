#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m,r,c;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> m >> r >> c;
    r -= 1;
    c -= 1;

    vector<vector<int>> grid(n, vector<int>(n,0));
    vector<pair<int,int>> bombs;
    int bc = 1;
    bombs.push_back({r,c});
    grid[r][c] = 1;
    queue<pair<int,int>> q;
    int dis = 1;

    for (int i = 0; i<m; i++) {
        /*for (int rr = 0; rr<n; rr++) {
            for (int rc = 0; rc<n; rc++) cout << grid[rr][rc] << " ";
            cout << '\n';
        }
        cout << '\n';*/
        for (auto coord:bombs) {
            int y = coord.first;
            int x = coord.second;

            for (int j = 0; j<4; j++) {
                int ny = y + dy[j] * dis;
                int nx = x + dx[j] * dis;

                if (ny > n-1 || ny < 0 || nx > n-1 || nx < 0 || grid[ny][nx] != 0) continue;

                q.push({ny,nx});
                grid[ny][nx] = 1;
            }
        }
        while(!q.empty()) {
            bombs.push_back(q.front());
            q.pop();
            bc++;
        }
        dis *= 2;
    }    
    /*for (int rr = 0; rr<n; rr++) {
        for (int rc = 0; rc<n; rc++) cout << grid[rr][rc] << " ";
        cout << '\n';
    }
    cout << '\n';*/

    cout << bc;

    // Please write your code here.

    return 0;
}
