#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
struct inf {
    int num, h, w; 
};
inf students[1000];

struct cmp {
    bool operator() (const inf &a, const inf &b) const {
        if (a.h != b. h) return a.h > b.h;
        else if (a.w != b.w) return a.w > b.w;
        return a.num < b.num;
    }
};
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        students[i].num = i+1;
        cin >> students[i].h >> students[i].w;
    }

    // Please write your code here.
    sort(students, students+n, cmp());

    for (int i = 0; i<n; i++) cout << students[i].h << " " << students[i].w << " " << students[i].num << '\n';

    return 0;
}