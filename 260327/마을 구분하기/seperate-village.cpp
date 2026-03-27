#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, cnt;
int grid[25][25];
char visited[25][25];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int main() {
    cin >> n;
    cnt = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    memset(visited, sizeof(visited), 0);
    // Please write your code here.

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                //cout << "found people at " << i << " " << j << '\n';
                cnt++;
                int mem = 1;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = 1;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int k = 0; k<4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || visited[ny][nx] == 1 || grid[ny][nx] == 0) continue;
                        q.push({ny,nx});
                        mem++;
                        visited[ny][nx] = 1;
                        //cout << "viligers " << ny << " " << nx << '\n';
                    }
                }
                //cout << "members " << mem << '\n'; 
                pq.push(mem);
            }
        }
    }

    cout << cnt << '\n';
    while(!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }

    return 0;
}
