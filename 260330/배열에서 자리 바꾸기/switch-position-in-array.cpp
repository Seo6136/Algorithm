#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* prev = nullptr;
    Node* nxt = nullptr;
};

const int MAXN = 250000;
Node* nodes[MAXN + 1];

bool is_before(Node* a, Node* b) {
    Node* cur = a;
    while (cur != nullptr) {
        if (cur == b) return true;
        cur = cur->nxt;
    }
    return false;
}

void swap_ranges(Node* fs, Node* fe, Node* ss, Node* se) {
    Node* A = fs->prev;
    Node* B = fe->nxt;
    Node* C = ss->prev;
    Node* D = se->nxt;

    if (B == ss) {
        A->nxt = ss;
        ss->prev = A;

        se->nxt = fs;
        fs->prev = se;

        fe->nxt = D;
        if (D != nullptr) D->prev = fe;
    }
    else {
        A->nxt = ss;
        ss->prev = A;

        se->nxt = B;
        if (B != nullptr) B->prev = se;

        C->nxt = fs;
        fs->prev = C;

        fe->nxt = D;
        if (D != nullptr) D->prev = fe;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* head = new Node;
    Node* cur = head;

    for (int i = 1; i <= n; i++) {
        Node* p = new Node;
        p->num = i;
        p->prev = cur;
        cur->nxt = p;
        cur = p;
        nodes[i] = p;
    }

    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        Node* fs = nodes[a];
        Node* fe = nodes[b];
        Node* ss = nodes[c];
        Node* se = nodes[d];

        if (!is_before(fs, ss)) {
            swap(fs, ss);
            swap(fe, se);
        }

        swap_ranges(fs, fe, ss, se);
    }

    Node* p = head->nxt;
    while (p != nullptr) {
        cout << p->num << ' ';
        p = p->nxt;
    }

    return 0;
}