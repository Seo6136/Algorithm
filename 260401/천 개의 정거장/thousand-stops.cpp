#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int to;
    long long fee;
    int bus;
};

struct Info {
    long long cost;
    long long time;
};

struct State {
    int station;
    int bus;
    long long cost;
    long long time;
};

struct Cmp {
    bool operator()(const State& a, const State& b) const {
        if (a.cost != b.cost) return a.cost > b.cost;
        return a.time > b.time;
    }
};

bool better(long long c1, long long t1, long long c2, long long t2) {
    if (c1 != c2) return c1 < c2;
    return t1 < t2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, N;
    cin >> A >> B >> N;

    vector<vector<Edge>> stations(1001);

    for (int busNum = 1; busNum <= N; busNum++) {
        long long fee;
        int cnt;
        cin >> fee >> cnt;

        vector<int> route(cnt);
        for (int i = 0; i < cnt; i++) cin >> route[i];

        for (int i = 0; i < cnt; i++) {
            int cur = route[i];
            int nxt = route[(i + 1) % cnt]; // 마지막이면 처음으로 순환
            stations[cur].push_back({nxt, fee, busNum});
        }
    }

    vector<vector<Info>> dist(1001, vector<Info>(N + 1, {LLONG_MAX, LLONG_MAX}));
    priority_queue<State, vector<State>, Cmp> pq;

    dist[A][0] = {0, 0};
    pq.push({A, 0, 0, 0});

    while (!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        if (dist[cur.station][cur.bus].cost != cur.cost ||
            dist[cur.station][cur.bus].time != cur.time) {
            continue;
        }

        for (const auto& e : stations[cur.station]) {
            long long nextCost = cur.cost;
            if (cur.bus != e.bus) nextCost += e.fee;

            long long nextTime = cur.time + 1;
            int nextStation = e.to;
            int nextBus = e.bus;

            if (better(nextCost, nextTime,
                       dist[nextStation][nextBus].cost,
                       dist[nextStation][nextBus].time)) {
                dist[nextStation][nextBus] = {nextCost, nextTime};
                pq.push({nextStation, nextBus, nextCost, nextTime});
            }
        }
    }

    long long ansCost = LLONG_MAX;
    long long ansTime = LLONG_MAX;

    for (int bus = 0; bus <= N; bus++) {
        if (better(dist[B][bus].cost, dist[B][bus].time, ansCost, ansTime)) {
            ansCost = dist[B][bus].cost;
            ansTime = dist[B][bus].time;
        }
    }

    if (ansCost == LLONG_MAX) {
        cout << -1 << ' ' << -1;
    } else {
        cout << ansCost << ' ' << ansTime;
    }

    return 0;
}