#include <iostream>
#include <set>

using namespace std;

static int n,m,t,seq;
static int grid[20][20];
static char visited[20][20];
static int dy[4] = {-1,1,0,0};
static int dx[4] = {0,0,-1,1};

set<pair<int,int>> move (set<pair<int,int>> &coord) {
    set<pair<int,int>> tmp;
    set<pair<int,int>> to_del;
    
    for (auto c:coord) {
        int cy,cx;
        int y = c.first;
        int x = c.second;
        int mnum = 0;

        //cout << "at " << y << " " << x << '\n';

        for (int i = 0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1 || grid[ny][nx] <= mnum) continue;
            mnum = grid[ny][nx];
            cy = ny;
            cx = nx;
        }

        //cout << "to move " << cy << " " << cx << '\n';

        if (visited[cy][cx] == seq) {
            //cout << "already visited\n";
            to_del.insert({cy,cx});
        }
        else {
            //cout << "new visit\n";
            visited[cy][cx] = seq;
            tmp.insert({cy,cx});
        }
    }

    for (auto d:to_del) {
        tmp.erase(d);
    }

    seq++;
    return tmp;
}

int main() {
    
    cin >> n >> m >> t;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cin >> grid[i][j];
    }
    seq = 1;

    set<pair<int,int>> coord;

    for (int i = 0; i<m; i++) {
        int y,x;
        cin >> y >> x;
        y-=1;
        x-=1;
        coord.insert({y,x});
    }

    for (int i = 0; i<t; i++) {
        coord = move(coord);
    }
    cout << coord.size();
    return 0;
}