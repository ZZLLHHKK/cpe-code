#include <bits/stdc++.h>
using namespace std;

bool solve(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[')
            st.push(c);
        else if (c == ')' || c == ']') {
            if (st.empty()) return false;
            char tt = st.top();
            st.pop();
            if ((tt != '(' && c == ')') || (tt != '[' && c == ']'))
                return false;
        }
    }
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string s;
        getline(cin, s);

        if (solve(s))
            cout << "Yes\n";
        else 
            cout << "No\n";
    }
}
