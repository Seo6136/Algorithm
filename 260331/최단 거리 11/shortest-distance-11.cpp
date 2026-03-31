#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

int N, M;
int dist[1001];
int prv[1001];
vector<vector<pair<int,int>>> nodes;

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    cin >> N >> M;
    fill(dist, dist+N+1, INT_MAX);
    nodes = vector<vector<pair<int,int>>>(N+1);
    
    for (int i = 0; i<M; i++) {
        int a,b,dis;
        cin >> a >> b >> dis;

        nodes[a].push_back({b,dis});
        nodes[b].push_back({a,dis});
    }

    int start,end;
    cin >> end >> start;

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;

    dist[start] = 0;
    q.push({start, 0});

    while (!q.empty()) {
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();

        for (auto &nn:nodes[now]) {
            int nxt = nn.first;
            int nd = dis + nn.second;

            if (nd < dist[nxt]) {
                dist[nxt] = nd;
                prv[nxt] = now;
                q.push({nxt,nd});
            }
            else if (nd == dist[nxt] && prv[nxt] > now) prv[nxt] = now;
        }
    }
    // Please write your code here.
    vector<int> path;
    int pv = end;

    while (pv != 0) {
        path.push_back(pv);
        pv = prv[pv];
    }
    cout << dist[end] << '\n';
    for (int i = 0; i<path.size(); i++) cout << path[i] << " ";

    return 0;
}
