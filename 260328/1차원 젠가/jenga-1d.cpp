#include <iostream>
#include <vector>
using namespace std;

int blocks[100];

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    for (int i = 0; i<n; i++) cin >> blocks[i];

    vector<int> b1;
    vector<int> b2;

    int start,end;
    cin >> start >> end;
    start -=1 ;
    end -= 1;

    for (int i = start; i <= end; i++) blocks[i] = 0;

    

    for (int i = 0; i<n; i++) {
        if (blocks[i] != 0) b1.push_back(blocks[i]);
    }

    cin >> start >> end;
    start -=1 ;
    end -= 1;

    for (int i = start; i <= end; i++) b1[i] = 0;

    for (int i = 0; i<b1.size(); i++) {
        //cout << b1[i] << " ";
        if (b1[i] != 0) b2.push_back(b1[i]);
    }
    //cout << '\n';

    if (b2.empty()) cout << 0;
    else {
        cout << b2.size() << '\n';
        for (int i = 0; i < b2.size(); i++) {
            cout << b2[i] << '\n';
        }
    }
    

    return 0;
}