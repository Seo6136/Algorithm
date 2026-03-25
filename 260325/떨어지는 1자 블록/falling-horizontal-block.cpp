#include <iostream>

using namespace std;

int n;
int m, k;
int a[100][100];

int main() {
    cin >> n >> m >> k;

    k -= 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int row = 0;
    bool flag = true;
    // Please write your code here.
    while (1) {
        //check
        for (int i = k; i<k+m; i++) {
            if (a[row][i] == 1) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            row--;
            break;
        }
        row++;
    }

    for (int i = k; i<k+m; i++) a[row][i] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
