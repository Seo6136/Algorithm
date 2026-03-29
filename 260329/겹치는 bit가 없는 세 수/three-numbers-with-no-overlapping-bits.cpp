#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int n,maxnum;
int bits [500][30];
int nums [500];
vector<vector<int>> cn;

void find_sum(int cnt, int sum, int idx, unordered_set<int> tmp) {
    if (cnt == 3) {
        //cout << "sum is " << sum << '\n';
        if (sum > maxnum) maxnum = sum;
        return;
    }
    for (int i = idx; i<n; i++) {
        bool flag = true;
        for (int t:tmp) {
            if (bits[i][t] == 1) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int c:cn[i]) tmp.insert(c);
            //cout << "select " << nums[i] << '\n';
            find_sum(cnt+1, sum+nums[i], i+1, tmp);
            for (int c:cn[i]) tmp.erase(c);
        }
    }
}

int main() {
    cin >> n;

    cn = vector<vector<int>> (n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        int num = nums[i];
        //cout << "num " << num << '\n';

        int div = 1;
        int divcnt = 0;

        while (num > 0) {
            if (div * 2 <= num) {
                div *= 2;
                divcnt++;
            }
            else {
                //cout << div << " " << divcnt << '\n';
                num -= div;
                div = 1;
                cn[i].push_back(divcnt);
                bits[i][divcnt] = 1;
                divcnt = 0;
            }
        }
    }
    maxnum = 0;

    // Please write your code here.
    unordered_set<int> tmp;
    find_sum(0,0,0,tmp);
    cout << maxnum;

    return 0;
}