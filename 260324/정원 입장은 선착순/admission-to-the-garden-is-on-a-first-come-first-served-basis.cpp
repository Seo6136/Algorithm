#include <iostream>
#include <queue>

using namespace std;

struct people{
    int num,arrv,stay;
};

struct cmp {
    bool operator() (people a, people b) {
        if (a.arrv != b.arrv) return a.arrv > b.arrv;
        return a.num > b.num;
    }
};

struct lcmp {
    bool operator() (people a, people b) {
        return a.num > b.num;
    }
};

int n;

int main() {
    cin >> n;
    priority_queue<people, vector<people>, cmp> yet;
    priority_queue<people, vector<people>, lcmp> line;
    int time = 0;
    int mwait = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        people p;
        p.num = i;
        cin >> p.arrv >> p.stay;
        yet.push(p);
    }

    while (cnt != n) {
        while (!yet.empty() && yet.top().arrv <= time) {
            line.push(yet.top());
            //cout << "push " << yet.top().num << '\n';
            yet.pop();
        }
        if (line.empty()) {
            line.push(yet.top());
            time = yet.top().arrv;
            //cout << "push " << yet.top().num << '\n';
            yet.pop();
        }

        //cout << line.top().num << '\n';
        //cout << "at time " << time << " ";
        int wait = time - line.top().arrv;
        if (wait > mwait) mwait = wait;
        //cout << "he waited " << wait << " ";

        time = time + line.top().stay;
        //cout << "next time is " << time << '\n';
        line.pop();
        cnt++;
    }


    // Please write your code here.
    cout << mwait;
    return 0;
}
