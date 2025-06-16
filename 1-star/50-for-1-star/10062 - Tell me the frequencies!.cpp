#include <iostream>
#include <algorithm>
using namespace std;

struct p {
    char c;
    int cnt = 0;
};

bool cmp(p a, p b) {
    if (a.cnt == b.cnt) return a.c > b.c;
    return a.cnt < b.cnt;
}

int main() {
    string s;
    bool first = true;

    while (getline(cin, s)) {
        if (!first) cout << '\n';
        first = false;

        p count[129] = {};
        for (int i = 0; i < s.size(); ++i) {
            count[(int)s[i]].cnt++;
            count[(int)s[i]].c = s[i];
        }
        sort(count, count + 129, cmp);
        for (int i = 0; i < 129; ++i) {
            if (count[i].cnt != 0) 
                cout << (int)count[i].c << " " << count[i].cnt << '\n';
        }
    }
}
