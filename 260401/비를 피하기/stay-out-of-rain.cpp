#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,h,m;
int grid[100][100];
int dis[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n >> h >> m;

    vector<pair<int,int>> coord;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) coord.push_back({i,j});
        }
    }

    for (auto &p:coord) {
        int y = p.first;
        int x = p.second;

        dis[y][x] = -1;

        vector<vector<int>> cnt (n, vector<int>(n,10001));
        queue<pair<int,int>> q;

        q.push({y,x});
        cnt[y][x] = 0;

        while(!q.empty()) {
            int cy = q.front().first;
            int cx = q.front().second;
            int nd = cnt[cy][cx] + 1;
            bool flag = false;
            //cout << cy << " " << cx << " " << nd << '\n';
            q.pop();

            for (int i = 0; i<4; i++) {
                int ny = cy + dy[i];
                int nx = cx + dx[i];

                if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] == 1 || cnt[ny][nx] <= nd) continue;
                if (grid[ny][nx] == 3) {
                    //cout << "min dis " << ny << " " << nx << " " << nd << '\n';
                    dis[y][x] = nd;
                    flag = true;
                    break;
                }
                cnt[ny][nx] = nd;
                q.push({ny,nx});
            }
            if (flag) break;
        }
        
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cout << dis[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
