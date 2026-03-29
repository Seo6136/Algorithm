#include <iostream>
#include <vector>

using namespace std;

int n,m;
int group[5000][30];

int main() {
    cin >> n;
    vector<vector<int>> group(n);

    for (int i = 0; i < n; i++) {
        cin >> m;
        for (int j = 0; j<m; j++) {
            int num;
            cin >> num;
            group[i].push_back(num);
        }
    }

    int cnt = 0;
    
    for (int i = 0; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            bool flag = true;
            for (int k:group[i]) {
                for (int x:group[j]) {
                    //cout << k << " " << x << '\n';
                    if (k==x) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag) {
                //cout << i << " " << j << '\n';
                cnt++;
            }
        }
    }

    // Please write your code here.
    cout << cnt;

    return 0;
}