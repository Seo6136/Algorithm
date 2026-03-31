#include <iostream>
#include <algorithm>
using namespace std;

int n,k;
long long mx,mn; 
long long bombs[50000];

bool check_bombs(long long mid) {
    int curidx = 0;
    long long sp,mp;

    for (int i = 0; i<k; i++) {
        //cout << curidx << '\n';
        sp = bombs[curidx];
        mp = sp + mid*2;

        while (mp >= bombs[curidx]) {
            curidx++;
            if (curidx >= n) return true;
        } 
    }

    return false;
}

int main() {
    // Please write your code here.
    cin >> n >> k;
    for (int i = 0; i<n; i++) {
        cin >> bombs[i];
    }

    sort(bombs, bombs+n);

    long long left = 0;
    long long right = bombs[n-1] - bombs[0];
    long long mid;

    long long ans;

    while(left <= right) {
        mid = (left+right) / 2;
        //cout << "mid " << mid << '\n';

        if (check_bombs(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else left = mid + 1;
    }

    cout << ans;

    return 0;
}