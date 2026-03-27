#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
struct inf {
    string name;
    int korean, english, math; 
};
inf students[10];

struct cmp {
    bool operator() (const inf &a, const inf &b) const {
        if (a.korean != b. korean) return a.korean > b.korean;
        else if (a.english != b.english) return a.english > b.english;
        return a.math > b.math;
    }
};
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].korean >> students[i].english >> students[i].math;
    }

    // Please write your code here.
    sort(students, students+n, cmp());

    for (int i = 0; i<n; i++) cout << students[i].name << " " << students[i].korean << " " << students[i].english << " " << students[i].math << '\n';

    return 0;
}