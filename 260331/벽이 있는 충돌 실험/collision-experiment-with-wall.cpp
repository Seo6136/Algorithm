#include <iostream>
#include <set>
#include <map>


using namespace std;

int n,m,t,seq,tt;
map<pair<int,int>, int> marvels;
int visited[50][50];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};

int to_dir(char d) {
    if (d == 'U') return 0;
    else if (d == 'R') return 1;
    else if (d == 'D') return 2;
    else return 3;
}

map<pair<int,int>, int> moving() {
    map<pair<int,int>,int> tmp;
    set<pair<int,int>> to_del;

    auto it = marvels.begin();

    //move marvels
    for (it; it != marvels.end(); it++) {
        int y = it->first.first;
        int x = it->first.second;
        int dir = it->second;

        //cout << "at " << y << " " << x << " " << dir << '\n';

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) {
            ny = y;
            nx = x;
            dir += 2;
            dir = dir % 4;
        }

        if (visited[ny][nx] == seq) {
            to_del.insert({ny,nx});
        }
        else {
            visited[ny][nx] = seq;
            tmp[{ny,nx}] = dir;
        }
    }

    //delete overlapped marvels
    for (auto coord:to_del) {
        tmp.erase(coord);
    }

    //it = tmp.begin();
    //for (it; it != tmp.end(); it++) cout << it->first.first << " " << it->first.second << " " << it->second << '\n';

    return tmp;

}

int main() {
    cin >> t;
    seq = 1;

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
            
            marvels[{y,x}] = dir;
        }

        tt = n * 2;
        
        for (int i = 0; i<tt; i++) {
            marvels = moving();
            seq++;
        }

        cout << marvels.size() << '\n';

    }
    // Please write your code here.
    return 0;
}