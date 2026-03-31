#include <iostream>

using namespace std;


int n, q, inst, nc;
struct City{
    string name;
    City* prev = nullptr;
    City* nxt = nullptr;
};

void print_city(City* pin) {
    City* left = pin->prev;
    City* right = pin->nxt;

    if (left->name == right->name) cout << -1 << '\n';
    else cout << left->name << " " << right->name << '\n';
}

void del_city(City* pin) {
    City* right = pin->nxt;

    if (pin == right) return;

    pin->nxt = right->nxt;
    right->nxt->prev = pin;

    right->nxt = nullptr;
    right->prev = nullptr;
}

void make_city(City* pin) {
    City* right = pin->nxt;
    City* now = new City;
    cin >> now->name;
    
    if (pin == right) {
        pin->nxt = now;
        pin->prev = now;
        now->nxt = pin;
        now->prev = pin;
        return; 
    }

    right->prev = now;
    pin->nxt = now;
    now->nxt = right;
    now->prev = pin;

}

int main() {
    cin >> n >> q;

    City* head = new City;

    City* cur = head;

    for (int i = 0; i < n; i++) {
        City* now = new City;
        cin >> now->name;

        cur->nxt = now;
        now->prev = cur;

        cur = now;
    }

    City* pin = head->nxt;

    cur->nxt = pin;
    pin->prev = cur;

    /*for (int i = 0; i<n; i++) {
        cout << cur->name << " ";
        cur = cur->nxt;
    }*/

    for (int i = 0; i<q; i++) {
        cin >> inst;
        if (inst == 1) pin = pin->nxt;
        else if (inst == 2) pin = pin->prev;
        else if (inst == 3) del_city(pin);
        else make_city(pin);
        print_city(pin);
    }
    // Please write your code here.

    return 0;
}
