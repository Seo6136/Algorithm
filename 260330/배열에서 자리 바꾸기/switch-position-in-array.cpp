#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* prev = nullptr;
    Node* nxt = nullptr;
};

void swap_ranges(Node* fs, Node* fe, Node* ss, Node* se) {
    Node* a = fs->prev;
    Node* b = fe->nxt;
    Node* c = ss->prev;
    Node* d = se->nxt;

    if (b == ss) {
        a->nxt = ss;
        ss->prev = a;

        se->nxt = fs;
        fs->prev = se;

        fe->nxt = d;
        if (d) d->prev = fe;
    } else {
        a->nxt = ss;
        ss->prev = a;

        se->nxt = b;
        if (b) b->prev = se;

        c->nxt = fs;
        fs->prev = c;

        fe->nxt = d;
        if (d) d->prev = fe;
    }
}

int main() {
    Node* nodes[250001];

    int n, q;
    cin >> n >> q;

    Node* root = new Node;
    nodes[0] = root;

    for (int i = 1; i <= n; i++) {
        Node* p = new Node;
        p->num = i;
        p->prev = nodes[i - 1];
        p->prev->nxt = p;
        nodes[i] = p;
    }

    for (int i = 0; i < q; i++) {
        int s1, e1, s2, e2;
        cin >> s1 >> e1 >> s2 >> e2;

        Node* fs = nodes[s1];
        Node* fe = nodes[e1];
        Node* ss = nodes[s2];
        Node* se = nodes[e2];

        swap_ranges(fs, fe, ss, se);

        // nodes 배열의 인덱스 의미가 "값별 노드 포인터"라면 갱신 불필요
        // 노드 자체는 그대로이고 위치만 바뀌기 때문
    }

    Node* cur = root->nxt;
    while (cur != nullptr) {
        cout << cur->num << " ";
        cur = cur->nxt;
    }

    return 0;
}