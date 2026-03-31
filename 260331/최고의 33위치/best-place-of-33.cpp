#include <iostream>

using namespace std;

int n, m,mx;
int grid[20][20];

int check_coin(int y, int x) {
    int coin = 0;
    for (int i = 0; i<3; i++) {
        for (int j = 0; j<3; j++) {
            //cout << y+i << " " << x+j << '\n';
            //cout << grid[y+i][x+j] << '\n';
            if (grid[y+i][x+j] == 1) coin++;
        }
    }
    return coin;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }*/

    // Please write your code here.
    int mx = 0;

    for (int i = 0; i<=n-3; i++) {
        for (int j = 0; j<=n-3; j++) {
            int coin = check_coin(i,j);
            if (coin > mx) mx = coin;
        }
    }

    cout << mx;

    return 0;
}
