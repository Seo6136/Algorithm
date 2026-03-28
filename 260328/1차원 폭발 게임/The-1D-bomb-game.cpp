#include <iostream>
#include <vector>

using namespace std;

int n,m;
int bombs[100];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> bombs[i];
    }
    

    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = 0; i<n; i++) {
            if (bombs[i] == 0) continue;
            int curnum = bombs[i];
            int cnt = 1;
            vector<int> tmp;
            tmp.push_back(i);
            for (int j = i+1; j<n; j++) {
                if (bombs[j] == 0) continue;
                if (bombs[j] == curnum) {
                    cnt++;
                    tmp.push_back(j);
                }
                else break;
            }
            if (cnt >= m) {
                flag = true;
                for (int t:tmp) bombs[t] = 0;
            }
        }
        //for (int i = 0; i<n; i++) cout << bombs[i] << " ";
        //cout << '\n';
    }

    vector<int> leftbomb;
    for (int i = 0; i < n; i++) {
        if (bombs[i] != 0) leftbomb.push_back(bombs[i]);
    }
    if (leftbomb.size() == 0) cout << 0;
    else {
        cout << leftbomb.size() << '\n';
        for (int b:leftbomb) cout << b << '\n';
    }

    // Please write your code here.

    return 0;
}
