#include <iostream>
#include <algorithm>

using namespace std;

int N;
struct numinf {
    int num, ogi;
};
struct cmp {
    bool operator() (const numinf &a, const numinf &b) const {
        if (a.num != b.num) return a.num < b.num;
        return a.ogi < b.ogi;
    }
};

numinf nums[1000];
int afternum[1000];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        nums[i].ogi = i + 1;
        cin >> nums[i].num;
    }

    sort(nums, nums+N, cmp());

    for (int i = 0; i<N; i++) {
        afternum[nums[i].ogi-1] = i+1;
    }

    for (int i = 0; i<N; i++) cout << afternum[i] << " ";

    // Please write your code here.

    return 0;
}
