#include <iostream>
#include <queue>
#include <limits.h>
#include <vector>
#include <cstring>

using namespace std;

int n,m;
int dis[101];
vector<vector<pair<int,int>>> graph;

struct cmp {
    bool operator() (const pair<int,int>& a, pair<int,int>& b) const {
        return a.second > b.second;
    }
};

void djk(int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;

    q.push({start,0});

    while (!q.empty()) {
        int node = q.top().first;
        int d = q.top().second;
        q.pop();
        //cout << node << " " << d << '\n';

        for (auto &k:graph[node]) {
            int to = k.first;
            int nd = d + k.second;
            //cout << to << " " << nd << '\n';
            if (nd < dis[to]) {
                dis[to] = nd;
                q.push({to,nd});
            }
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n >> m;

    graph = vector<vector<pair<int,int>>> (n+1);

    fill(dis, dis + n+1, INT_MAX);

    for (int i = 0; i<m; i++) {
        int from, to, dis;
        cin >> from >> to >> dis;

        graph[from].push_back({to,dis});
    }

    dis[1] = 0;
    djk(1);

    for (int i = 2; i<=n; i++) {
        if (dis[i] == INT_MAX) cout << -1 << '\n';
        else cout << dis[i] << '\n';
    }

    return 0;
}