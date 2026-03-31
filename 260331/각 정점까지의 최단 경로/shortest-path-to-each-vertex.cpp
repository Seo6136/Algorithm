#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;

int n,m,k;
vector<vector<pair<int,int>>> nodes;
int dis[20001];

struct cmp {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) const {
        return a.second < b.second;
    }
};
void djik(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
    dis[start] = 0;
    q.push({start, 0});

    while(!q.empty()) {
        int node = q.top().first;
        int d = q.top().second;
        q.pop();

        for (auto &to:nodes[node]) {
            int nxt = to.first;
            int nd = d + to.second;

            if (nd < dis[nxt]) {
                dis[nxt] = nd;
                q.push({nxt, nd});
            }
        }
    }
}

int main() {
    cin >> n >> m >> k;
    nodes = vector<vector<pair<int,int>>>(n+1);
    fill(dis, dis+n+1, INT_MAX);

    for (int i = 0; i < m; i++) {
        int a,b,dis;
        cin >> a >> b >> dis;

        nodes[a].push_back({b,dis});
        nodes[b].push_back({a,dis});
    }

    djik(k);
    for (int i = 1; i<=n; i++) {
        if (dis[i] == INT_MAX) cout << -1 << '\n';
        else cout << dis[i] << '\n';
    }

    return 0;
}
