#include <iostream>
#include <unordered_map>

using namespace std;

struct knight{
    int num;
    knight* prev = nullptr;
    knight* nxt = nullptr;
};

int n,m;
unordered_map<int, knight*> ptr;

int main() {
    // Please write your code here.
    cin >> n >> m;

    knight *root = new knight;
    knight *cur = root;

    for (int i = 0; i<n; i++) {
        knight *p = new knight; 
        int num;
        cin >> num;

        p->num = num;
        p->prev = cur;
        cur->nxt = p;
        cur = p;
        ptr[num] = p;
    }

    root = root->nxt;
    root->prev = cur;
    cur->nxt = root;

    /*for (int i =0; i<n; i++) {
        cout << cur->num << " ";
        cur = cur->nxt;
    }*/

    for (int i = 0; i<m; i++) {
        int pos;
        cin >> pos;
        cur = ptr[pos];

        cout << cur->nxt->num << " " << cur->prev->num << '\n';

        knight *left = cur->prev;
        knight *right = cur->nxt;

        left->nxt = right;
        right->prev = left;

        cur->nxt = nullptr;
        cur->prev = nullptr;
    }
    
    return 0;
}