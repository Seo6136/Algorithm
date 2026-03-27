#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int n, m;
int grid[50][50];
char visited[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        if (a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

void check_area (int k) {
    int cnt = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            if (grid[i][j] > k && visited[i][j] != k) {
                //cout << "found safe area at " << i << " " << j << '\n';
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                visited[i][j] = k;

                while(!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    for (int s = 0; s<4; s++) {
                        int ny = y + dy[s];
                        int nx = x + dx[s];
                        //cout << "check " << ny << " " << nx << '\n';
                        if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1 || visited[ny][nx] == k || grid[ny][nx] <= k) continue;
                        q.push({ny,nx});
                        visited[ny][nx] = k;
                        //cout << "other area " << ny << " " << nx << '\n';
                    }
                }
                //cout << "members " << mem << '\n'; 
            }
        }
    }
    pq.push({k,cnt});
}

int main() {
    cin >> n >> m;
    int mnum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] > mnum) mnum = grid[i][j];
        }
    }
    memset(visited, sizeof(visited), 0);
    // Please write your code here.

    

    for (int i = 1; i<=mnum; i++) {
        check_area(i);
    }

    cout << pq.top().first << " " << pq.top().second;
    return 0;
}
