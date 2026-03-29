#include <iostream>
#include <algorithm>
using namespace std;

int n, maxnum;
int nums[500];

void find_sum(int cnt, int sum, int idx, int usedMask) {
    if (cnt == 3) {
        maxnum = max(maxnum, sum);
        return;
    }

    for (int i = idx; i < n; i++) {
        if ((usedMask & nums[i]) == 0) {
            find_sum(cnt + 1, sum + nums[i], i + 1, usedMask | nums[i]);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];

    maxnum = 0;
    find_sum(0, 0, 0, 0);

    cout << maxnum;
    return 0;
}