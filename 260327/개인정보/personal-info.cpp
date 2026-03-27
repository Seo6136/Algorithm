#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct inf {
    string name;
    int h;
    double w;
};

struct cmp1 {
    bool operator() (const inf &a, const inf &b) const {
        return a.h > b.h;
    }
};
struct cmp2 {
    bool operator() (const inf &a, const inf &b) const {
        return a.name < b.name;
    }
};

inf arr[5];

int main() {
    // Please write your code here.


    for (int i = 0; i<5; i++) {
        cin >> arr[i].name >> arr[i].h >> arr[i].w;
    }

    sort(arr, arr+5, cmp2());
    cout << fixed << setprecision(1);

    cout << "name" << '\n';
    for (int i = 0; i<5; i++) {
        cout << arr[i].name << " " << arr[i].h << " " << arr[i].w << '\n';
    }

    cout << '\n';
    sort(arr, arr+5, cmp1());

    cout << "height" << '\n';
    for (int i = 0; i<5; i++) {
        cout << arr[i].name << " " << arr[i].h << " " << arr[i].w << '\n';
    }
    return 0;
}