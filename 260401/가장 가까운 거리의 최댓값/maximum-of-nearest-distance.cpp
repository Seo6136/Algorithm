#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

static int n,m,a,b,c;
vector<vector<pair<int,int>>> nodes;
int dista[100001];
int distb[100001];
int distc[100001];

void djik (int start, int *dist) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        int now = q.top().first;
        int d = q.top().second;
        q.pop();
        
        for (auto &nn:nodes[now]) {
            int nxt = nn.first;
            int nd = nn.second + d;

            if (nd < dist[nxt])  {
                dist[nxt] = nd;
                q.push({nxt, nd});
            }
        }
    }
}

int main() {
    cin >> n >> m;

    fill(dista, dista+n+1, INT_MAX);
    fill(distb, distb+n+1, INT_MAX);
    fill(distc, distc+n+1, INT_MAX);
    nodes = vector<vector<pair<int,int>>>(n+1);

    cin >> a >> b >> c;

    for (int i = 0; i<m; i++) {
        int t,f,d;
        cin >> t >> f >> d;

        nodes[t].push_back({f,d});
        nodes[f].push_back({t,d});
    }

    djik(a, dista);
    djik(b, distb);
    djik(c, distc);    

    int mx = 0;

    for(int i = 1; i<=n; i++) {
        int mn = INT_MAX;

        mn = min(mn, dista[i]);
        mn = min(mn, distb[i]);
        mn = min(mn, distc[i]);

        mx = max(mx, mn);
    }

    cout << mx;
    
    return 0;
}
