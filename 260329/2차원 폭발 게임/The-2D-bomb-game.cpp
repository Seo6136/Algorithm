#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int grid[100][100];

void do_it() {
    //delete bombs
    bool flag = true;
    while (flag) {
        /*for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
            cout << '\n';
        }*/
        //cout << '\n';
        flag = false;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
            int num = grid[y][x];
            if (num == 0) continue;

            int start = y;
            int end = y;

            for (int ny = y + 1; ny < n; ny++) {
                if (grid[ny][x] == num) end = ny;
                else break;
            }

            if (end - start + 1 >= m) {
                flag = true;
                for (int i = start; i <= end; i++) grid[i][x] = 0;
            }

            y = end;
            }
        }
        //apply gravity
        for (int x = 0; x<n; x++) {
            vector<int> tmp;
            int zero = 0;
            for (int y = n-1; y>=0; y--) {
                if (grid[y][x] != 0) tmp.push_back(grid[y][x]);
                else zero++;
            }
            for (int t = 0; t<tmp.size(); t++) {
                grid[n-1-t][x] = tmp[t];
            }
            for (int y = 0; y<zero; y++) grid[y][x] = 0;
        }
    }

    //turn right
    vector<vector<int>> tmp(n, vector<int> (n,0));
    int tc = 0;

    for (int y = n-1; y>=0; y--) {
        vector<int> tp;
        for (int x = n-1; x>=0; x--) {
            if (grid[y][x] != 0) tp.push_back(grid[y][x]);
        }
        for (int i = 0; i<tp.size(); i++) {
            tmp[n-1-i][tc] = tp[i];
        }
        tc++;
    }

    /*for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }*/

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            grid[i][j] = tmp[i][j];
        }
    }

}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        do_it();
    }

    int ans = 0;
    //delete bombs
    for (int x = 0; x<n; x++) {
        for (int y = 0; y<n; y++) {
            int num = grid[y][x];
            if (num == 0) continue;
            int cnt = 1;

            for (int ny = y+1; ny < n;  ny++) {
                if (num == grid[ny][x]) cnt++;
                else break;
            }

            if (cnt >= m) {
                for (int i = 0; i < cnt; i++) grid[y+i][x] = 0;
            }
        }
    }

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            //cout << grid[i][j] << " ";
            if (grid[i][j] != 0) ans++;
        }
        //cout << '\n';
    }

    cout << ans;

    // Please write your code here.

    return 0;
}
