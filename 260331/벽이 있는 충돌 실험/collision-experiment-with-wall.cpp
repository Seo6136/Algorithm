#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct marvel{
    int y,x,dir;
    bool alive = true;
};

int n,m,t,tt;
vector<marvel> marvels;
int cnt[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int to_dir(char d) {
    if (d == 'U') return 0;
    else if (d == 'R') return 1;
    else if (d == 'D') return 2;
    else return 3;
}

void moving() {
    //move marvels
    for (auto &it:marvels) {
        if (!it.alive) continue;
        int y = it.y;
        int x = it.x;
        int dir = it.dir;

        //cout << "at " << y << " " << x << " " << dir << '\n';
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
            ny = y;
            nx = x;
            dir += 2;
            dir = dir % 4;
        }
        it.y = ny;
        it.x = nx;
        it.dir = dir;
        cnt[ny][nx]++;
    }

    for (auto &it:marvels) {
        if (!it.alive) continue;
        int y = it.y;
        int x = it.x;

        if (cnt[y][x] >= 2) it.alive=false;
    }

}

int main() {
    cin >> t;

    for (int tc = 0; tc<t; tc++) {
        cin >> n >> m;
        marvels.clear();
        
        for (int i = 0; i<m; i++) {
            int y,x,dir;
            char d;

            cin >> y >> x >> d;
            y-=1;
            x-=1;
            dir = to_dir(d);
            
            marvels.push_back({y,x,dir,true});
        }

        tt = n * 2;
        
        for (int i = 0; i<tt; i++) {
            moving();
            memset(cnt, 0, sizeof(cnt));
        }
        int ans = 0;

        for (auto &it:marvels) {
            if (it.alive) ans++;
        }
        cout << ans << '\n';

    }
    // Please write your code here.
    return 0;
}