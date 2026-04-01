#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <set>

using namespace std;

int n,m;
vector<set<pair<int,int>>> nodes;
int dist[1001];

int main() {
    cin >> n >> m;
    nodes = vector<set<pair<int,int>>>(n+1);
    fill(dist, dist+n+1, INT_MAX);

    for (int i = 0; i<m; i++) {
        int a,b,d;

        cin >> a >> b >> d;

        nodes[a].insert({b,d});
        nodes[b].insert({a,d});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    int start, end;
    cin >> start >> end;

    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();

        for (auto &nn:nodes[now]) {
            int nxt = nn.first;
            int nd = nn.second + dis;

            if (nd < dist[nxt]) {
                q.push({nxt,nd});
                dist[nxt] = nd;
            }
        }
    }

    cout << dist[end];

    return 0;
}