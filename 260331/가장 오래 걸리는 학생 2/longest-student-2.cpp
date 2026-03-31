#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

vector<vector<pair<int,int>>> nodes;
int n,m;
int dist[100001];

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    cin >> n >> m;
    nodes = vector<vector<pair<int,int>>>(n+1);

    fill(dist, dist+n+1, INT_MAX);

    for (int i = 0; i<m; i++) {
        int a,b,dis;
        cin >> a >> b >> dis;

        nodes[b].push_back({a,dis});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;

    q.push({n, 0});
    dist[n] = 0;

    while (!q.empty()) {
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();

        for (auto& nn:nodes[now]) {
            int nxt = nn.first;
            int nd = dis + nn.second;

            if (dist[nxt] > nd) {
                dist[nxt] = nd;
                q.push({nxt, nd});
            }
        }
    }

    int mx = 0;
    for (int i = 1; i<=n; i++) {
        if (dist[i] > mx) mx = dist[i];
    }

    cout << mx;

    // Please write your code here.
    return 0;
}