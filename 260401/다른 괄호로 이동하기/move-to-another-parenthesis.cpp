#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int n,a,b;
char grid[30][30];
vector<vector<pair<int,int>>> nodes;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

struct cmp {
    bool operator() (const pair<int,int> &a, const pair<int,int> &b) const {
        return a.second > b.second;
    }
};

int get_node(int d) {
    if (d == 0) return -n;
    if (d == 1) return 1;
    if (d == 2) return n;
    if (d == 3) return -1;
    return 0;
}

int get_mxdis (int start) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> q;
    vector<int> dist (n*n+1, INT_MAX);
    q.push({start, 0});
    dist[start] = 0;

    while(!q.empty()) {
        int now = q.top().first;
        int dis = q.top().second;
        q.pop();

        if (dis != dist[now]) continue;

        for (auto &nn:nodes[now]) {
            int nxt = nn.first;
            int nd = dis + nn.second;

            if (nd < dist[nxt]) {
                q.push({nxt, nd});
                dist[nxt] = nd;
            }
        } 
    }

    //for (int i = 1; i<dist.size(); i++) cout << dist[i] << '\n';
    
    auto max_it = max_element(dist.begin()+1, dist.end());
    //cout << *max_it << '\n';
    return *max_it;
}

int main() {
    cin >> n >> a >> b;

    nodes = vector<vector<pair<int,int>>>(n*n+1);

    for (int i = 0; i<n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j<n; j++) grid[i][j] = line[j];
    }
    /*
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }*/

    
    int now = 1;

    //make graph
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            //cout << "node " << now << '\n';
            char s = grid[i][j];

            for (int d = 0; d<4; d++) {
                int ny = i + dy[d];
                int nx = j + dx[d];

                if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;

                char ns = grid[ny][nx];
                int nn = now + get_node(d);
                //cout << "to " << nn << '\n';
                if (s == ns) nodes[now].push_back({nn, a});
                else nodes[now].push_back({nn, b});
            }
            now++;
        }
    }
    

    int ans = 0;

    for (int i = 1; i<=n*n; i++) {
        ans = max(ans, get_mxdis(i));
    }

    cout << ans;
    
    return 0;
}
