#include <iostream>
using namespace std;

struct Node {
    int num = 0;
    Node* prev = nullptr;
    Node* nxt = nullptr;
    Node* tail = nullptr; 
    int cnt = 0;          
};

Node* pop_front(Node* head) {
    if (head->cnt == 0) return nullptr;

    Node* x = head->nxt;

    if (head->cnt == 1) {
        head->nxt = nullptr;
        head->tail = nullptr;
    } else {
        head->nxt = x->nxt;
        head->nxt->prev = head;
    }

    x->prev = nullptr;
    x->nxt = nullptr;
    head->cnt--;
    return x;
}

Node* pop_back(Node* head) {
    if (head->cnt == 0) return nullptr;

    Node* x = head->tail;

    if (head->cnt == 1) {
        head->nxt = nullptr;
        head->tail = nullptr;
    } else {
        head->tail = x->prev;
        head->tail->nxt = nullptr;
    }

    x->prev = nullptr;
    x->nxt = nullptr;
    head->cnt--;
    return x;
}

void push_front(Node* head, Node* first, Node* last, int add_cnt) {
    if (first == nullptr) return;

    if (head->cnt == 0) {
        head->nxt = first;
        head->tail = last;
        first->prev = head;
        last->nxt = nullptr;
    } else {
        Node* old_head = head->nxt;
        head->nxt = first;
        first->prev = head;
        last->nxt = old_head;
        old_head->prev = last;
    }
    head->cnt += add_cnt;
}

void push_back(Node* head, Node* first, Node* last, int add_cnt) {
    if (first == nullptr) return;

    if (head->cnt == 0) {
        head->nxt = first;
        head->tail = last;
        first->prev = head;
        last->nxt = nullptr;
    } else {
        head->tail->nxt = first;
        first->prev = head->tail;
        head->tail = last;
        last->nxt = nullptr;
    }
    head->cnt += add_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    Node* shelf[101];

    for (int i = 1; i <= k; i++) {
        shelf[i] = new Node; 
    }

    for (int i = 1; i <= n; i++) {
        Node* book = new Node;
        book->num = i;
        push_back(shelf[1], book, book, 1);
    }

    while (q--) {
        int inst, i, j;
        cin >> inst >> i >> j;

        if (inst == 1) {
            Node* x = pop_front(shelf[i]);
            if (x != nullptr) push_back(shelf[j], x, x, 1);
        }
        else if (inst == 2) {
            Node* x = pop_back(shelf[i]);
            if (x != nullptr) push_front(shelf[j], x, x, 1);
        }
        else if (inst == 3) {
            if (i == j || shelf[i]->cnt == 0) continue;

            Node* first = shelf[i]->nxt;
            Node* last = shelf[i]->tail;
            int moved = shelf[i]->cnt;

            shelf[i]->nxt = nullptr;
            shelf[i]->tail = nullptr;
            shelf[i]->cnt = 0;

            push_front(shelf[j], first, last, moved);
        }
        else if (inst == 4) {
            if (i == j || shelf[i]->cnt == 0) continue;

            Node* first = shelf[i]->nxt;
            Node* last = shelf[i]->tail;
            int moved = shelf[i]->cnt;

            shelf[i]->nxt = nullptr;
            shelf[i]->tail = nullptr;
            shelf[i]->cnt = 0;

            push_back(shelf[j], first, last, moved);
        }
    }

    for (int s = 1; s <= k; s++) {
        cout << shelf[s]->cnt;
        Node* cur = shelf[s]->nxt;
        while (cur != nullptr) {
            cout << ' ' << cur->num;
            cur = cur->nxt;
        }
        cout << '\n';
    }

    return 0;
}