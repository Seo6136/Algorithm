#include <iostream>
#include <algorithm>

using namespace std;

int n;
struct point {
    int num, y, x;
};
struct cmp {
    bool operator() (const point &a, const point &b) const {
        if (abs(a.y) + abs(a.x) != abs(b.y) + abs(b.x)) return abs(a.y) + abs(a.x) < abs(b.y) + abs(b.x);
        return a.num < b.num;
    }
};
point points[1000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        points[i].num = i+1;
        cin >> points[i].y >> points[i].x;
    }

    sort(points, points+n, cmp());

    for (int i = 0; i<n; i++) cout << points[i].num << '\n';
    // Please write your code here.

    return 0;
}