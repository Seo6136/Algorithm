#include <iostream>
#include <vector>

using namespace std;

int grid[4][4];

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j<4; j++) cin >> grid[i][j];
    }

    char inst;
    cin >> inst;

    if (inst == 'D') {
        for (int x = 0; x<4; x++) {
            for (int y = 3; y > 0; y--) {
                if (grid[y][x] == 0) continue;
                int num = grid[y][x];
                for (int ny = y-1; ny >= 0; ny--) {
                    if (grid[ny][x] == 0) continue;
                    if (grid[ny][x] == num) {
                        grid[y][x] = num*2;
                        grid[ny][x] = 0;
                        break;
                    }
                    else break;
                }
            }
        }
        for (int x = 0; x<4; x++) {
            vector<int> tmp;
            int zero = 0;
            for (int y = 3; y>=0; y--) {
                if (grid[y][x] != 0) tmp.push_back(grid[y][x]);
                else zero++;
            }
            for (int n = 0; n<tmp.size(); n++) grid[3-n][x] = tmp[n];
            for (int n = 0; n<zero; n++) grid[n][x] = 0;
        }
        
    }
    if (inst == 'U') {
        for (int x = 0; x<4; x++) {
            for (int y = 0; y < 3; y++) {
                if (grid[y][x] == 0) continue;
                int num = grid[y][x];
                for (int ny = y+1; ny <= 3; ny++) {
                    if (grid[ny][x] == 0) continue;
                    if (grid[ny][x] == num) {
                        grid[y][x] = num*2;
                        grid[ny][x] = 0;
                        break;
                    }
                    else break;
                }
            }
        }
        for (int x = 0; x<4; x++) {
            vector<int> tmp;
            int zero = 0;
            for (int y = 0; y<4; y++) {
                if (grid[y][x] != 0) tmp.push_back(grid[y][x]);
                else zero++;
            }
            for (int n = 0; n<tmp.size(); n++) grid[n][x] = tmp[n];
            for (int n = 0; n<zero; n++) grid[3-n][x] = 0;
        }
        
    }
    if (inst == 'R') {
        for (int y = 0; y<4; y++) {
            for (int x = 3; x > 0; x--) {
                if (grid[y][x] == 0) continue;
                int num = grid[y][x];
                //cout << "at " << y << " " << x << " num is " << num << '\n';  
                for (int nx = x-1; nx >= 0; nx--) {
                    //cout << grid[y][nx] << '\n';
                    if (grid[y][nx] == 0) continue;
                    if (grid[y][nx] == num) {
                        grid[y][x] = num*2;
                        grid[y][nx] = 0;
                        break;
                    }
                    else break;
                }
            }
        }
        for (int y = 0; y<4; y++) {
            vector<int> tmp;
            int zero = 0;
            for (int x = 3; x>=0; x--) {
                //cout << grid[y][x] << " ";
                if (grid[y][x] != 0) tmp.push_back(grid[y][x]);
                else zero++;
            }
            //cout << '\n';
            for (int n = 0; n<tmp.size(); n++) grid[y][3-n] = tmp[n];
            for (int n = 0; n<zero; n++) grid[y][n] = 0;
        }
    }
    if (inst == 'L') {
        for (int y = 0; y<4; y++) {
            for (int x = 0; x < 3; x++) {
                if (grid[y][x] == 0) continue;
                int num = grid[y][x];
                for (int nx = x+1; nx <=3; nx++) {
                    if (grid[y][nx] == 0) continue;
                    if (grid[y][nx] == num) {
                        grid[y][x] = num*2;
                        grid[y][nx] = 0;
                        break;
                    }
                    else break;
                }
            }
        }
        for (int y = 0; y<4; y++) {
            vector<int> tmp;
            int zero = 0;
            for (int x = 0; x<4; x++) {
                if (grid[y][x] != 0) tmp.push_back(grid[y][x]);
                else zero++;
            }
            for (int n = 0; n<tmp.size(); n++) grid[y][n] = tmp[n];
            for (int n = 0; n<zero; n++) grid[y][3-n] = 0;
        }
        
    }

    // Please write your code here.
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<4; j++) cout << grid[i][j] << " ";
        cout << '\n';
    }

    return 0;
}
