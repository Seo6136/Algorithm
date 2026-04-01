#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

struct way {
    long long to, fee, bus;
};
long long dist[101];
long long pv[101];

struct cmp {
    bool operator() (const way &a, const way &b) const {
        return a.fee > b.fee;
    }
};

int main() {
    long long a, b, n;

    cin >> a >> b >> n;

    vector<vector<way>> stations(101);

    fill (dist, dist+101, LONG_LONG_MAX);

    for (long long i = 1; i<=n; i++) {
        long long fee;
        long long nums;
        cin >> fee >> nums;

        long long start,to;
        cin >> start;
        for (long long w = 1; w<nums; w++) {
            cin >> to;
            stations[start].push_back({to,fee,i});
            start = to;
        }
    }

    /*for (int i = 1; i<=5; i++) {
        cout << "at station " << i << '\n';
        for (auto& k:stations[i]) cout << k.bus << " " << k.to << " " << k.fee << '\n';
    }*/

    priority_queue<way, vector<way>, cmp> q;
    q.push({a,0,0});
    dist[a] = 0;
    
    while (!q.empty()) {
        long long now = q.top().to;
        long long fee = q.top().fee;
        long long bus = q.top().bus;
        q.pop();

        //cout << "at station " << now << '\n';

        for (auto &nb:stations[now]) {
            long long nxt = nb.to;
            long long nbus = nb.bus;
            long long nfee;
            if(bus != nbus) nfee = fee + nb.fee;
            else nfee = fee;

            //cout << "to station " << nxt << " using bus " << nbus << " fee " << nfee << '\n';

            if (dist[nxt] > nfee) {
                //cout << "accept" << '\n';
                q.push({nxt, nfee, nbus});
                dist[nxt] = nfee;
                pv[nxt] = now;
            }
        }
    }

    if (dist[b] == LONG_LONG_MAX) cout << -1 << " " << -1;
    else {
        long long cnt = 0;
        long long now = b;

        while (now != a) {
            cnt++;
            now = pv[now];
        }

        cout << dist[b] << " " << cnt;
    }
    
    return 0;
}