#include <iostream>
#include <vector>

using namespace std;

int n;
int blocks[100][100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) cin >> blocks[i][j];
    }
    
    int y,x;
    cin >> y >> x;
    y-=1;
    x-=1;

    //bombs
    int num = blocks[y][x];
    blocks[y][x] = 0;

    //up
    for (int i = 1; i < num; i++) {
        int ny = y - i;
        if (ny < 0) break;
        blocks[ny][x] = 0;
    }
    //down
    for (int i = 1; i < num; i++) {
        int ny = y + i;
        if (ny > n-1) break;
        blocks[ny][x] = 0;
    }
    //left
    for (int i = 1; i < num; i++) {
        int nx = x - i;
        if (nx < 0) break;
        blocks[y][nx] = 0;
    }
    //right
    for (int i = 1; i < num; i++) {
        int nx = x + i;
        if (nx > n-1) break;
        blocks[y][nx] = 0;
    }

    for (int i = 0; i<n; i++) {
        int zcnt = 0;
        vector<int> tmp;

        for (int j = n-1; j>=0; j--) {
            if (blocks[j][i] != 0) tmp.push_back(blocks[j][i]);
            else zcnt++;
        }

        for (int j = 0; j<tmp.size(); j++) {
            blocks[n-1-j][i] = tmp[j];
        }

        for (int j = 0; j<zcnt; j++) blocks[j][i] = 0;

    }
    // Please write your code here.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j<n; j++) cout << blocks[i][j] << " ";
        cout << '\n';
    }
    return 0;
}
