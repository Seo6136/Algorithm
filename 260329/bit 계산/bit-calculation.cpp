#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n,num;
char setint [100001];
string inst;

int main() {
    // Please write your code here.
    cin >> n;
    memset(setint, 0, sizeof(setint));
    
    for (int i = 0; i<n; i++) {
        cin >> inst;
        if (inst == "add") {
            cin >> num;
            setint[num] = 1;
        }
        else if (inst == "delete") {
            cin >> num;
            setint[num] = 0;
        }
        else if (inst == "print") {
            cin >> num;
            if (setint[num]) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (inst == "toggle") {
            cin >> num;
            if (setint[num]) setint[num] = 0;
            else setint[num] = 1;
        }
        else memset(setint, 0, sizeof(setint));
    }
    return 0;
}