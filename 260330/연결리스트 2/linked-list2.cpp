#include <iostream>

using namespace std;

int nxt[100001];
int previous[100001];

int main() {
    
    int n,inst,num,q,j;
    cin >> n >> q;

    for (int i = 0; i<q; i++) {
        cin >> inst;
        if (inst == 1) {
            cin >> num;
            if (previous[num] != 0) nxt[previous[num]] = nxt[num];
            if (nxt[num] != 0) previous[nxt[num]] = previous[num];
            previous[num] = 0;
            nxt[num] = 0; 
        }
        else if (inst == 2) {
            cin >> num >> j;
            if (previous[num] != 0) {
                previous[j] = previous[num];
                nxt[previous[num]] = j;
            }
            nxt[j] = num;
            previous[num] = j;
            //cout << previous[j] << " " << nxt[j] << '\n';

        }
        else if (inst  == 3) {
            cin >> num >> j;
            if (nxt[num] != 0) {
                nxt[j] = nxt[num];
                previous[nxt[num]] = j;
            }
            previous[j] = num;
            nxt[num] = j;
           //cout << previous[j] << " " << nxt[j] << '\n';
        }
        else {
            cin >> num;
            cout << previous[num] << " " << nxt[num] << '\n';
        }

    }

    for (int i = 1; i<=n; i++) {
        cout << nxt[i] << " ";
    }

    return 0;
}
