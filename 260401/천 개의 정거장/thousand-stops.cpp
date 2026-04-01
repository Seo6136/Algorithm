#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

struct State {
    ll cost, time;
    int node;
    bool operator<(const State& other) const {
        if (cost != other.cost) return cost > other.cost; // min-heap
        if (time != other.time) return time > other.time;
        return node > other.node;
    }
};

struct Bus {
    ll fee;
    vector<int> stops;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, N;
    cin >> A >> B >> N;

    vector<Bus> buses(N);
    vector<vector<pair<int, int>>> appear(1001); 
    // appear[stop] = {(busIndex, positionInRoute)}

    for (int i = 0; i < N; ++i) {
        int m;
        cin >> buses[i].fee >> m;
        buses[i].stops.resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> buses[i].stops[j];
            appear[buses[i].stops[j]].push_back({i, j});
        }
    }

    vector<ll> distCost(1001, INF), distTime(1001, INF);
    priority_queue<State> pq;

    distCost[A] = 0;
    distTime[A] = 0;
    pq.push({0, 0, A});

    while (!pq.empty()) {
        auto [curCost, curTime, u] = pq.top();
        pq.pop();

        if (distCost[u] != curCost || distTime[u] != curTime) continue;
        if (u == B) break;

        for (auto [busIdx, pos] : appear[u]) {
            const auto& bus = buses[busIdx];
            ll nextCost = curCost + bus.fee;

            for (int j = pos + 1; j < (int)bus.stops.size(); ++j) {
                int v = bus.stops[j];
                ll nextTime = curTime + (j - pos);

                if (nextCost < distCost[v] ||
                    (nextCost == distCost[v] && nextTime < distTime[v])) {
                    distCost[v] = nextCost;
                    distTime[v] = nextTime;
                    pq.push({nextCost, nextTime, v});
                }
            }
        }
    }

    if (distCost[B] == INF) {
        cout << "-1 -1\n";
    } else {
        cout << distCost[B] << ' ' << distTime[B] << '\n';
    }

    return 0;
}