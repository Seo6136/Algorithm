#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n;
int grid[100][100];
char visited[100][100];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n;
    int mcnt = 0;
    int mnum = 0;

    memset(visited, sizeof(visited), 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j] == 0) {
                int num = grid[i][j];
                visited[i][j] = 1;
                int cnt = 1;

                queue<pair<int,int>> q;
                q.push({i,j});

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k<4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || ny > n-1|| nx < 0 || nx > n-1 || grid[ny][nx] != num || visited[ny][nx] != 0) continue;
                        q.push({ny,nx});
                        visited[ny][nx] = 1;
                        cnt++;
                    }
                }
                if (cnt >= 4) mnum++;
                if (cnt > mcnt) {
                    mcnt = cnt;
                }
            }
        }
    }

    cout << mnum << " " << mcnt;

    // Please write your code here.

    return 0;
}
