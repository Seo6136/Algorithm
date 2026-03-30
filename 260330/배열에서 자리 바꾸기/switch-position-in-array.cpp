#include <iostream>
using namespace std;

struct Node {
    int num;
    Node* prev = nullptr;
    Node* nxt = nullptr;
};

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
        if (D) D->prev = fe;
    } else {
        A->nxt = ss;
        ss->prev = A;

        se->nxt = B;
        if (B) B->prev = se;

        C->nxt = fs;
        fs->prev = C;

        fe->nxt = D;
        if (D) D->prev = fe;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    Node* nodes[250001];

    Node* head = new Node;   // 앞 센티넬
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

        // 첫 번째 구간이 실제로 더 뒤에 있다면 순서 교체가 필요할 수 있음
        // 문제 입력이 항상 앞 구간 먼저 준다면 생략 가능

        swap_ranges(fs, fe, ss, se);
    }

    Node* p = head->nxt;
    while (p != nullptr) {
        cout << p->num << ' ';
        p = p->nxt;
    }

    return 0;
}