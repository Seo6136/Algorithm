#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;
int n,m,r1,r2;
vector<vector<pair<int,int>>> g;
int rdist1[100001];
int rdist2[100001];

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return a.second > b.second;
    }
};

int main() {
    cin >> n >> m;
    fill(rdist1,rdist1+n+1,INT_MAX);
    fill(rdist2,rdist2+n+1,INT_MAX);
    cin >> r1 >> r2;

    g = vector<vector<pair<int,int>>>(n+1);

    for (int i = 0; i<m; i++) {
        int a,b,d;
        cin >> a >> b >> d;
        g[a].push_back({b,d});
        g[b].push_back({a,d});
    }

    int ans = INT_MAX;

    //finf red dist
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
    q.push({r1,0});
    rdist1[r1] = 0;

    while(!q.empty()) {
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();

        if (rdist1[now] != dis) continue;
        for (auto &nn:g[now]) {
            int nxt = nn.first;
            int nd = nn.second + dis;
            if (nd < rdist1[nxt]) {
                rdist1[nxt] = nd;
                q.push({nxt,nd}); 
            }
        }
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> qq;

    qq.push({r2,0});
    rdist2[r2] = 0; 


    while(!qq.empty()) {
        int now = qq.top().first;
        int dis = qq.top().second;
        qq.pop();

        if (rdist2[now] != dis) continue;
        for (auto &nn:g[now]) {
            int nxt = nn.first;
            int nd = nn.second + dis;
            if (nd < rdist2[nxt]) {
                rdist2[nxt] = nd;
                qq.push({nxt,nd}); 
            }
        }
    }

    int mn = INT_MAX;
    int rtor = rdist1[r2];

    if (rtor == INT_MAX) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i<=n; i++) {
        int r1toi = rdist1[i];
        int r2toi = rdist2[i];

        if (r1toi == INT_MAX || r2toi == INT_MAX) continue;

        mn = min(mn, r1toi+r2toi+rtor);
    }

    if (mn == INT_MAX) cout << -1;
    else cout << mn;
    // Please write your code here.
    return 0;
}