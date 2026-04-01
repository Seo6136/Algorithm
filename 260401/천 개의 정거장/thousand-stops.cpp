#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Edge {
    int to, fee, bus;
};

struct State {
    int station, bus;
    long long cost;
};

struct Cmp {
    bool operator()(const State& a, const State& b) const {
        return a.cost > b.cost;
    }
};

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<vector<Edge>> stations(101);

    for (int i = 1; i <= n; i++) {
        int fee, nums;
        cin >> fee >> nums;

        int start, to;
        cin >> start;
        for (int j = 1; j < nums; j++) {
            cin >> to;
            stations[start].push_back({to, fee, i});
            start = to;
        }
    }

    vector<vector<long long>> dist(101, vector<long long>(n + 1, LLONG_MAX));
    vector<vector<pair<int, int>>> pv(101, vector<pair<int, int>>(n + 1, {-1, -1}));

    priority_queue<State, vector<State>, Cmp> pq;

    dist[a][0] = 0;
    pq.push({a, 0, 0});  // 시작점, 아직 버스 안 탐

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        int now = cur.station;
        int bus = cur.bus;
        long long cost = cur.cost;

        if (cost > dist[now][bus]) continue;

        for (const auto& nb : stations[now]) {
            int nxt = nb.to;
            int nbus = nb.bus;
            long long ncost;

            if (bus == nbus) ncost = cost;
            else ncost = cost + nb.fee;

            if (dist[nxt][nbus] > ncost) {
                dist[nxt][nbus] = ncost;
                pv[nxt][nbus] = {now, bus};
                pq.push({nxt, nbus, ncost});
            }
        }
    }

    long long ans = LLONG_MAX;
    int lastBus = -1;

    for (int bus = 0; bus <= n; bus++) {
        if (dist[b][bus] < ans) {
            ans = dist[b][bus];
            lastBus = bus;
        }
    }

    if (ans == LLONG_MAX) {
        cout << -1 << " " << -1;
        return 0;
    }

    int cnt = 0;
    int curStation = b;
    int curBus = lastBus;

    while (!(curStation == a && curBus == 0)) {
        cnt++;
        auto prev = pv[curStation][curBus];
        curStation = prev.first;
        curBus = prev.second;
    }

    cout << ans << " " << cnt;
    return 0;
}