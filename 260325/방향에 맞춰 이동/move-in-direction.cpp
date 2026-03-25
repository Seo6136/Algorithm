#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int n,x,y;
    x = 0;
    y = 0;
    cin >> n;

    char dir;
    int dis;

    for (int i = 0; i<n; i++) {
        cin >> dir >> dis;

        if (dir == 'N') {
            y += dis;
        }
        else if (dir == 'S') y -= dis;
        else if (dir == 'E') x += dis;
        else x -= dis;
    }

    cout << x << " " << y;
    return 0;
}