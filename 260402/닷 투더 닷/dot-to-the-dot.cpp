#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;
using ll = long long;

struct inf {
    int to;
    ll l,c;
};
struct status {
    int now;
    ll a, b;
    double d;
};
struct cmp {
    bool operator()(const status &a, const status &b) const {
        return a.d > b.d;
    }
};
double dist[501];
int n,m,x;


int main() {
    cin >> n >> m >> x;

    vector<vector<inf>> nodes (n+1);
    fill(dist, dist+n+1, LLONG_MAX);

    for (int i = 0; i<m; i++) {
        int a,b;
        ll l,c;
        cin >> a >> b >> l >> c;
        nodes[a].push_back({b,l,c});
        nodes[b].push_back({a,l,c});
    }

    priority_queue<status, vector<status>, cmp> q;
    q.push({1,LLONG_MAX,0,0});
    dist[1] = 0;

    while(!q.empty()) {
        auto cur = q.top();
        int now = cur.now;
        ll a = cur.a;
        ll b = cur.b;
        double d = cur.d;
        q.pop();
        //cout << "at " << now << '\n';

        if (d != dist[now]) continue;

        for (auto &nn:nodes[now]) {
            int nxt = nn.to;
            ll na = min(a,nn.c);
            ll nb = b + nn.l;
            double nd = nb + double(x) / double(na);
            //cout << "to " << nxt << " ";
            //cout << nd << '\n';
            if (nd < dist[nxt]) {
                q.push({nxt,na,nb,nd});
                dist[nxt] = nd;
            }
        }
    }

    cout << int(dist[n]);

    return 0;
}