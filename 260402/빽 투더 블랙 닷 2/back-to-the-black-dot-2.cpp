#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
using ll = long long;

int n, m, r1, r2;
vector<vector<pair<int,ll>>> g;
ll rdist1[100001];
ll rdist2[100001];

struct cmp {
    bool operator() (const pair<int,ll> &a, const pair<int,ll> &b) const {
        return a.second > b.second;
    }
};

int main() {
    cin >> n >> m;
    fill(rdist1, rdist1 + n + 1, LLONG_MAX);
    fill(rdist2, rdist2 + n + 1, LLONG_MAX);
    cin >> r1 >> r2;

    g = vector<vector<pair<int,ll>>>(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll d;
        cin >> a >> b >> d;
        g[a].push_back({b, d});
        g[b].push_back({a, d});
    }

    priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> q;
    q.push({r1, 0});
    rdist1[r1] = 0;

    while (!q.empty()) {
        int now = q.top().first;
        ll dis = q.top().second;
        q.pop();

        if (rdist1[now] != dis) continue;
        for (auto &nn : g[now]) {
            int nxt = nn.first;
            ll nd = nn.second + dis;
            if (nd < rdist1[nxt]) {
                rdist1[nxt] = nd;
                q.push({nxt, nd});
            }
        }
    }

    priority_queue<pair<int,ll>, vector<pair<int,ll>>, cmp> qq;
    qq.push({r2, 0});
    rdist2[r2] = 0;

    while (!qq.empty()) {
        int now = qq.top().first;
        ll dis = qq.top().second;
        qq.pop();

        if (rdist2[now] != dis) continue;
        for (auto &nn : g[now]) {
            int nxt = nn.first;
            ll nd = nn.second + dis;
            if (nd < rdist2[nxt]) {
                rdist2[nxt] = nd;
                qq.push({nxt, nd});
            }
        }
    }

    ll mn = LLONG_MAX;
    ll rtor = rdist1[r2];

    if (rtor == LLONG_MAX) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (i == r1 || i == r2) continue;
        ll r1toi = rdist1[i];
        ll r2toi = rdist2[i];

        if (r1toi == LLONG_MAX || r2toi == LLONG_MAX) continue;

        mn = min(mn, r1toi + r2toi + rtor);
    }

    if (mn == LLONG_MAX) cout << -1;
    else cout << mn;

    return 0;
}