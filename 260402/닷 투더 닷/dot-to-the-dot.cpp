#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
using ll = long long;

struct Edge {
    int to;
    ll l, c;
};

struct State {
    int node;
    ll a, b;
    double d;
};

struct Cmp {
    bool operator()(const State& x, const State& y) const {
        return x.d > y.d;
    }
};

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        ll l, c;
        cin >> u >> v >> l >> c;
        graph[u].push_back({v, l, c});
        graph[v].push_back({u, l, c});
    }

    vector<vector<pair<ll, ll>>> dist(n + 1);

    priority_queue<State, vector<State>, Cmp> pq;

    dist[1].push_back({LLONG_MAX, 0});
    pq.push({1, LLONG_MAX, 0, 0});

    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        int now = cur.node;
        ll a = cur.a;
        ll b = cur.b;

        for (auto& e : graph[now]) {
            int nxt = e.to;
            ll na = min(a, e.c);
            ll nb = b + e.l;

            bool skip = false;
            for (auto& p : dist[nxt]) {
                if (p.first >= na && p.second <= nb) {
                    skip = true;
                    break;
                }
            }
            if (skip) continue;

            vector<pair<ll, ll>> tmp;
            for (auto& p : dist[nxt]) {
                if (!(na >= p.first && nb <= p.second)) {
                    tmp.push_back(p);
                }
            }
            dist[nxt] = tmp;

            dist[nxt].push_back({na, nb});

            double nd = nb + (double)x / (double)na;
            pq.push({nxt, na, nb, nd});
        }
    }

    double ans = 1e18;
    for (auto& p : dist[n]) {
        ll a = p.first;
        ll b = p.second;
        ans = min(ans, b + (double)x / (double)a);
    }

    if (ans == 1e18) cout << -1;
    else cout << (int)ans;

    return 0;
}