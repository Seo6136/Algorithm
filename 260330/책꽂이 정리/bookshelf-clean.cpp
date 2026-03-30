#include <iostream>
#include <deque>

using namespace std;

struct Node{
    int num;
    Node* prev = nullptr;
    Node* nxt = nullptr;
    Node* tail = nullptr;
    int cnt = 0;
};


int main() {
    // head of bookself
    Node *nodes[101];

    int n,k,q;

    cin >> n >> k >> q;
    nodes[1] = new Node;

    for (int i = 1; i<=k; i++) {
        Node* p = new Node;
        nodes[i] = p;
    }

    Node* cur = nodes[1];
    for (int i = 1; i<=n; i++) {
        Node* p = new Node;
        p->num = i;

        cur->nxt = p;
        p->prev = cur;

        cur = p;
        nodes[1]->tail = cur;
    }
    nodes[1]->cnt = n;

    /*for (int i = 1; i<=k; i++) {
        Node* cur = nodes[i];
        if (cur->cnt == 0) cout << 0 << '\n';
        else {
            cout << cur->cnt << " ";
            cur = cur->nxt;
            while(cur != nullptr) {
                cout << cur->num << " ";
                cur = cur->nxt;
            }
        }
        cout << '\n';
    }*/

    //cout << nodes[1]->nxt->num << " " << nodes[1]->tail->num << '\n';

    for (int x = 0; x<q; x++) {
        int inst, i, j;

        cin >> inst >> i >> j;

        if (inst == 1) {
            //cout << "at 1 " << '\n';
            if (nodes[i]->nxt == NULL) continue;
            Node *from = nodes[i]->nxt;
            Node *to = nodes[j]->tail;

            //cout << from->num << " " << to->num <<'\n';
            //cout << from->prev->num << " " << to->prev->num <<'\n';
            
            nodes[i]->nxt = from->nxt;
            from->nxt->prev = nodes[i];
            from->nxt = nullptr;

            if (nodes[j]->nxt == nullptr) {
                nodes[j]->nxt = from;
                from->prev = nodes[j];
            }
            
            else {
                from->prev = to;
                to->nxt = from;
            }

            nodes[j]->tail = from;
            nodes[i]->cnt--;
            nodes[j]->cnt++;

            
            /*for (int y = 1; y<=k; y++) {
                Node* cur = nodes[y];
                if (cur->cnt == 0) cout << 0;
                else {
                    cout << cur->cnt << " ";
                    cur = cur->nxt;
                    while(cur != nullptr) {
                        cout << cur->num << " ";
                        cur = cur->nxt;
                    }
                }
                cout << '\n';
            }*/
        }

        else if (inst == 2) {
            //cout << "at 2" << '\n';
            if (nodes[i]->nxt == NULL) continue;
            Node *from = nodes[i]->tail;
            Node *to = nodes[j]->nxt;
            nodes[i]->tail = from->prev;

            from->prev->nxt = nullptr;

            if (nodes[j]->nxt == nullptr) {
                nodes[j]->nxt = from;
            }
            
            else {
                from->prev = nodes[j];
                from->nxt = nodes[j]->nxt;
                nodes[j]->nxt = from;
            }
            nodes[j]->tail = from;
            nodes[i]->cnt--;
            nodes[j]->cnt++;
            
            /*for (int y = 1; y<=k; y++) {
                Node* cur = nodes[y];
                if (cur->cnt == 0) cout << 0;
                else {
                    cout << cur->cnt << " ";
                    cur = cur->nxt;
                    while(cur != nullptr) {
                        cout << cur->num << " ";
                        cur = cur->nxt;
                    }
                }
                cout << '\n';
            }*/
        }

        else if (inst == 3) {
            //cout << "at 3" << '\n';
            if (i == j) continue;
            if (nodes[i]->nxt == NULL) continue;
            Node *h = nodes[i]->nxt;
            Node *t = nodes[i]->tail;
            Node *oh = nodes[j]->nxt;
            int tmp = nodes[i]->cnt;

            //cout << h->num << " " << t->num << " " << oh->num << '\n';

            nodes[i]->nxt = nullptr;
            nodes[i]->tail = nullptr;
            nodes[i]->cnt = 0;
            
            h->prev = nodes[j];
            nodes[j]->nxt = h;
            
            if (nodes[j]->nxt != nullptr) {
                oh->prev = t;
                t->nxt = oh;
            }
            
            nodes[j]->cnt += tmp;
            nodes[j]->tail = t;

            /*for (int y = 1; y<=k; y++) {
                Node* cur = nodes[y];
                if (cur->cnt == 0) cout << 0;
                else {
                    cout << cur->cnt << " ";
                    cur = cur->nxt;
                    while(cur != nullptr) {
                        cout << cur->num << " ";
                        cur = cur->nxt;
                    }
                }
                cout << '\n';
            }*/
        }

        else {
            //cout << "at 4" << '\n';
            if (i == j) continue;
            if (nodes[i]->nxt == NULL) continue;
            Node *h = nodes[i]->nxt;
            Node *t = nodes[i]->tail;
            int tmp = nodes[i]->cnt;

            h->prev = nullptr;
            nodes[i]->nxt = nullptr;
            nodes[i]->tail = nullptr;
            nodes[i]->cnt = 0;

            if (nodes[j]->nxt == nullptr) {
                nodes[j]->nxt = h;
                h->prev = nodes[j];
            }
            else {
                h->prev = nodes[j]->nxt;
                nodes[j]->nxt->nxt = h;
            }

            nodes[j]->tail = t;
            nodes[j]->cnt += tmp;
            /*for (int y = 1; y<=k; y++) {
                Node* cur = nodes[y];
                if (cur->cnt == 0) cout << 0;
                else {
                    cout << cur->cnt << " ";
                    cur = cur->nxt;
                    while(cur != nullptr) {
                        cout << cur->num << " ";
                        cur = cur->nxt;
                    }
                }
                cout << '\n';
            }*/
        }
    }
    for (int y = 1; y<=k; y++) {
        Node* cur = nodes[y];
        if (cur->cnt == 0) cout << 0;
        else {
            cout << cur->cnt << " ";
            cur = cur->nxt;
            while(cur != nullptr) {
                cout << cur->num << " ";
                cur = cur->nxt;
            }
        }
        cout << '\n';
    }
    return 0;
}
