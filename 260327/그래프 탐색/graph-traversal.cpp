#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m,cnt;
vector<vector<int>> edges;
vector<char> visited;
int main() {
    // Please write your code here.
    cin >> n >> m;
    edges = vector<vector<int>>(n+1);
    visited = vector<char>(n+1,0);

    for (int i = 0; i<m; i++) {
        int a,b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> q;

    q.push(1);
    visited[1] = 1;
    cnt = 0;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next:edges[now]) {
            if (visited[next] == 0) {
                q.push(next);
                cnt++;
                visited[next] = 1;
            }
        }
    }

    cout << cnt;

    return 0;
}