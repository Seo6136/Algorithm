#include <iostream>

using namespace std;

int inst;
string word;
int n;

struct Node {
    string s;
    Node *previous = NULL;
    Node *next = NULL;
};

int main() {
    cin >> word;
    cin >> n;

    Node *init = new Node;
    init->s = word;
    Node *cur = init; 

    for (int i = 0; i < n; i++) {
        cin >> inst;
        if (inst == 1) {
            cin >> word;
            Node *node = new Node;
            if (cur->previous != NULL) {
                node->previous = cur->previous;
                cur->previous->next = node;    
            }
            cur->previous = node;
            node->next = cur;
            node->s = word;
        }
        else if (inst == 2) {
            cin >> word;
            Node *node = new Node;
            if (cur -> next != NULL) {
                node->next = cur->next;
                cur->next->previous = node;    
            }
            cur->next = node;
            node->previous = cur;
            node->s = word;
        }
        else if (inst == 3) {
            if (cur->previous != NULL) {
                cur = cur->previous;
            }
        }
        else {
            if (cur->next != NULL) {
                cur = cur->next;
            }
        }
        if (cur->previous == NULL) cout << "(Null) ";
        else cout << cur->previous->s << " ";
        cout << cur->s << " ";
        if (cur->next == NULL) cout << "(Null) ";
        else cout << cur->next->s;
        cout << '\n';
    }

    
    
    return 0;
}
