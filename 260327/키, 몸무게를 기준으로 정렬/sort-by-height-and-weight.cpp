#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct inf {
    string name;
    int h;
    int w;
};

struct cmp {
    bool operator() (const inf &a, const inf &b) const {
        if (a.h != b.h) return a.h < b.h;
        return a.w > b.w;
    }
};
int n;
inf arr[10];

int main() {
    // Please write your code here.
    cin >> n;

    for (int i = 0; i<n; i++) {
        cin >> arr[i].name >> arr[i].h >> arr[i].w;
    }

    sort(arr, arr+n, cmp());

    for (int i = 0; i<n; i++) {
        cout << arr[i].name << " " << arr[i].h << " " << arr[i].w << '\n';
    }

    return 0;
}