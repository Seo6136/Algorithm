#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

vector<pair<int,int>> coord;
vector<vector<vector<int>>> grid;
int n,m;
int dy[8] = {-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

int get_max(int y, int x) {
    if (grid[y][x].size() == 0) return 0;
    int mx = 0;
    for (int cn:grid[y][x]) {
        mx = max(mx,cn);
    }
    return mx;
}

int main() {

    cin >> n >> m;

    coord = vector<pair<int,int>>(n*n+1);
    grid = vector<vector<vector<int>>> (n, vector<vector<int>> (n));

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            int tmp;
            cin >> tmp;
            grid[i][j].push_back(tmp);
            coord[tmp] = {i,j};
        }
    }

    /*for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            for (int k:grid[i][j]) cout << k << " ";
        }
        cout << '\n';
    }*/

    /*for (auto k:coord) {
        cout << k.first << " " << k.second << '\n';
    }*/

    for (int i = 0; i<m; i++) {
        int to_move;
        cin >> to_move;
        int cy,cx;
        int y = coord[to_move].first;
        int x = coord[to_move].second;
        int mx = 0;

        //cout << "num " << to_move << " coord " << y << " " << x << '\n';

        for(int j = 0; j<8; j++) {  
            int ny = y + dy[j];
            int nx = x + dx[j];

            if (ny < 0 || ny > n-1 || nx < 0 || nx > n-1) continue;
            int num = get_max(ny, nx);

            if (num > mx) {
                cy = ny;
                cx = nx;
                mx = num;
            }
        }

        //cout << "max " << mx << " coord " << cy << " " << cx << '\n';

        if (mx != 0) {
            vector<int> tmp;
            vector<int> rmn;
            bool flag = 0;
            for (int pn:grid[y][x]) {
                if (!flag) {
                    tmp.push_back(pn);
                    coord[pn] = {cy,cx};
                    if (pn == to_move) flag = true;
                }
                else 
                rmn.push_back(pn);
                //grid[cy][cx].push_back(pn);
            }
            for (int nn:grid[cy][cx]) {
                tmp.push_back(nn);
            }
            grid[cy][cx] = tmp;
            grid[y][x] = rmn;
        }

        /*for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                for (int k:grid[i][j]) cout << k << " ";
                cout << '\n';
            }
            cout << '\n';
        }*/
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            if (grid[i][j].size() == 0) cout << "None" << '\n';
            else {
                for (int k:grid[i][j]) cout << k << " ";
                cout << '\n';
            }
        }
    }

    return 0;
}