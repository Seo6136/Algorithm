#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* prev = nullptr;
    Node* nxt = nullptr;
};

const int MAXN = 250000;
Node* nodes[MAXN + 1];

void swap_ranges(Node* fs, Node* fe, Node* ss, Node* se) {
    Node* A = fs->prev;
    Node* B = fe->nxt;
    Node* C = ss->prev;
    Node* D = se->nxt;

    if (fe->nxt == ss) {
        A->nxt = ss;
        ss->prev = A;

        se->nxt = fs;
        fs->prev = se;

        fe->nxt = D;
        D->prev = fe;
    }
    else if (se->nxt == fs) {
        C->nxt = fs;
        fs->prev = C;

        fe->nxt = ss;
        ss->prev = fe;

        se->nxt = B;
        B->prev = se;
    }
    else {
        A->nxt = ss;
        ss->prev = A;

        se->nxt = B;
        B->prev = se;

        C->nxt = fs;
        fs->prev = C;

        fe->nxt = D;
        D->prev = fe;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    Node* head = new Node;
    Node* tail = new Node;

    head->nxt = tail;
    tail->prev = head;

    Node* cur = head;
    for (int i = 1; i <= N; i++) {
        Node* p = new Node;
        p->num = i;

        p->prev = cur;
        p->nxt = tail;
        cur->nxt = p;
        tail->prev = p;

        cur = p;
        nodes[i] = p;
    }

    for (int i = 0; i < Q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        Node* fs = nodes[a];
        Node* fe = nodes[b];
        Node* ss = nodes[c];
        Node* se = nodes[d];

        swap_ranges(fs, fe, ss, se);
    }

    Node* p = head->nxt;
    while (p != tail) {
        cout << p->num;
        if (p->nxt != tail) cout << ' ';
        p = p->nxt;
    }

    return 0;
}