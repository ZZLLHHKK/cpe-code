#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    while (cin >> n) {
        pq.push(n);
        int s = pq.size();
        vector<int> tmp;
        if (s & 1) {
            for (int i = 0; i < (s / 2); ++i) {
                tmp.push_back(pq.top());
                pq.pop();
            }
            cout << pq.top() << '\n';
        }
        else {
            int fir, sec;
            for (int i = 0; i < (s / 2) - 1; ++i) {
                tmp.push_back(pq.top());
                pq.pop();
            }
            fir = pq.top(); pq.pop();
            sec = pq.top(); pq.pop();
            cout << (fir + sec) / 2 << '\n';
            tmp.push_back(fir);
            tmp.push_back(sec);
        }
        for (int j = 0; j < tmp.size(); ++j) 
            pq.push(tmp[j]);
    }
}
