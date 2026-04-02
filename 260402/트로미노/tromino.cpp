#include <iostream>
#include <algorithm>

using namespace std;
int n,m,mx;
int grid[200][200];

int main() {
    cin >> n >> m;

    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) cin >> grid[i][j];
    }

    mx = 0;

    //case ㄴ,r
    for (int i = 0; i<n-1; i++) {
        for (int j = 0; j<m-1; j++) {
            int num1 = grid[i][j] + grid[i+1][j] + grid[i+1][j+1];
            int num2 = grid[i][j] + grid[i+1][j] + grid[i][j+1];
            int cmp = max(num1,num2);
            mx = max(cmp,mx);
        }
    }

    //case ㄱ
    for (int i = 0; i<n-1; i++) {
        for (int j = 1; j<m; j++) {
            int num1 = grid[i][j-1] + grid[i][j] + grid[i+1][j];
            mx = max(num1,mx);
        }
    }

    //case ㅢ
    for (int i = 1; i<n; i++) {
        for (int j = 1; j<m; j++) {
            int num1 = grid[i][j-1] + grid[i][j] + grid[i-1][j];
            mx = max(num1,mx);
        }
    }

    //case ㅡ
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m-2; j++) {
            int num1 = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            mx = max(num1,mx);
        }
    }

    //case ㅣ
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n-2; j++){
            int num1 = grid[j][i] + grid[j+1][i] + grid[j+2][i];
            //cout << i << " " << j << " " << num1 << '\n';
            mx = max(num1,mx);
        }
    }

    cout << mx;

    return 0;
}